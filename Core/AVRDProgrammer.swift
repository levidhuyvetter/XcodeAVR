import Foundation

class AVRDProgrammer {
	private var pgm:PROGRAMMER
	private var prt:AVRPART? = nil
	var port:String
	private var open:Bool = false
	
	var id:String { String(cString: UnsafeMutablePointer<UInt8>(OpaquePointer(ldata(lfirst(self.pgm.id))))) }
	var desc:String { withUnsafePointer(to: self.pgm.desc) { $0.withMemoryRebound(to: UInt8.self, capacity: MemoryLayout.size(ofValue: $0)) { String(cString: $0) } } }
	var part:String { withUnsafePointer(to: self.prt?.desc) { $0.withMemoryRebound(to: UInt8.self, capacity: MemoryLayout.size(ofValue: $0)) { String(cString: $0) } } }
	var connected:Bool { return self.open && (self.prt != nil) }
	var baud:Int { get { Int(self.pgm.baudrate) } set { self.pgm.baudrate = Int32(newValue) } }
	
	init(_ pgm:PROGRAMMER, port:String) {
		self.port = port
		self.pgm = pgm
	}
	
	init(_ id:String, port:String, baud:Int? = nil) {
		self.port = port
		
		let cId = strdup(id)
		self.pgm = locate_programmer(programmers, cId).pointee
				
		guard let b = baud, b > 0 else { return }
		self.baud = b
	}
	
	func connect(_ part:String? = nil) throws {
		if !self.open {
			self.pgm.initpgm(&self.pgm)
			self.pgm.setup?(&self.pgm)
			
			let cPort = strdup(self.port)
			guard self.pgm.open(&self.pgm, cPort) >= 0 else {
				self.pgm.ppidata = 0
				self.disconnect()
				throw "Could not open programmer."
			}
			
			self.open = true
		}
		
		self.pgm.enable(&self.pgm)
		let _ = self.pgm.rdy_led(&self.pgm, OFF)
		let _ = self.pgm.err_led(&self.pgm, OFF)
		let _ = self.pgm.pgm_led(&self.pgm, OFF)
		let _ = self.pgm.vfy_led(&self.pgm, OFF)
		
		if self.prt == nil {
			let cPrt = part == nil ? strdup("m328p") : strdup(part!)
			var prt = locate_part(part_list, cPrt).pointee
			avr_initmem(&prt)
			guard self.pgm.initialize(&self.pgm, &prt) >= 0 else { throw "Could not initialize programmer with part." }
			
			if self.prt == nil {
				guard avr_signature(&self.pgm, &prt) == 0 else { throw "Could not get signature for part." }
				guard let sig = avr_locate_mem(&prt, strdup("signature")) else { throw "Could not get signature memory for part." }
				prt = locate_part_by_signature(part_list, sig.pointee.buf, sig.pointee.size).pointee
				avr_initmem(&prt)
				guard self.pgm.initialize(&self.pgm, &prt) >= 0 else { throw "Could not initialize programmer with part." }
			}
			
			self.prt = prt
			
			let _ = self.pgm.rdy_led(&self.pgm, ON)
		}
		
		self.pgm.disable(&self.pgm)
	}
	
	@discardableResult
	func enable<T>(_ cb:(AVRPART)throws->(T)) throws -> T {
		guard var prt = self.prt, self.open else { throw "Programmer is not connected." }
		self.pgm.enable(&self.pgm)
		guard self.pgm.initialize(&self.pgm, &prt) >= 0 else { throw "Could not initialize programmer with part." }
		
		let rv = try cb(prt)
		
		self.pgm.disable(&self.pgm)
		
		return rv
	}
	
	func getSignature() throws -> Signature {
		return try self.enable {
			var prt = $0
			guard avr_signature(&self.pgm, &prt) == 0 else { throw "Could not get signature." }
			guard let sig = avr_locate_mem(&prt, strdup("signature")) else { throw "Could not locate signature memory." }
			guard let signature = Signature(sig.pointee) else { throw "Could not create signature object." }
			return signature
		}
	}
	
	func verifiySignature(_ sig:Signature) -> Bool {
		let expected = self.prt!.signature
		return sig.tuple == expected
	}
	
	func getMemorySize() throws -> Int {
		return try self.enable {
			var prt = $0
			guard let fls = avr_locate_mem(&prt, strdup("flash")) else { throw "Could not locate flash memory." }
			return Int(fls.pointee.size)
		}
	}
		
	func disconnect() {
		if self.open {
			self.pgm.powerdown(&self.pgm)
			self.pgm.disable(&self.pgm)
			let _ = self.pgm.rdy_led(&self.pgm, OFF)
		}
		
		self.pgm.close(&self.pgm)
		
		self.open = false
	}
	
	class func all() -> [AVRDProgrammer] {
		var rv:[AVRDProgrammer] = []
		var ln = lfirst(programmers)
		
		while ln != nil {
			let p = ldata(ln).load(as: PROGRAMMER.self)
			rv.append(AVRDProgrammer(p, port:""))
			ln = lnext(ln)
		}
		
		return rv
	}
}

extension String:Error {}

class Signature:NSObject {
	let a:UInt8
	let b:UInt8
	let c:UInt8
	
	var tuple:(UInt8,UInt8,UInt8) { (self.a,self.b,self.c) }
	var string:String { String(format: "%02X %02X %02X", self.a, self.b, self.c) }
	
	init(_ a:UInt8, _ b:UInt8, _ c:UInt8) {
		self.a = a
		self.b = b
		self.c = c
		super.init()
	}
	
	init?(_ sig:AVRMEM) {
		guard sig.size >= 3 else { return nil }
		self.a = sig.buf[0]
		self.b = sig.buf[1]
		self.c = sig.buf[2]
		super.init()
	}
}
