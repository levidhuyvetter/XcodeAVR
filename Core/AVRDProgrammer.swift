import Foundation

class AVRDProgrammer {
	private var pgm:PROGRAMMER
	private var prt:AVRPART? = nil
	var port:String
	private var open:Bool = false
	
	var id:String { String(cString: UnsafeMutablePointer<UInt8>(OpaquePointer(ldata(lfirst(self.pgm.id))))) }
	var desc:String { withUnsafePointer(to: self.pgm.desc) { $0.withMemoryRebound(to: UInt8.self, capacity: MemoryLayout.size(ofValue: $0)) { String(cString: $0) } } }
	var connected:Bool { return self.open && (self.prt != nil) }
	var baud:Int { get { Int(self.pgm.baudrate) } set { self.pgm.baudrate = Int32(newValue) } }
	var signature:(UInt8, UInt8, UInt8) = (0, 0, 0)
	
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
	
	func getSignature() throws -> (UInt8, UInt8, UInt8) {
		return try self.enable {
			var prt = $0
			guard avr_signature(&self.pgm, &prt) == 0 else { throw "Could not get signature." }
			guard let sig = avr_locate_mem(&prt, strdup("signature")) else { throw "Could not locate signature memory." }
			guard sig.pointee.size >= 3 else { throw "Signature is too short." }
			self.signature = (sig.pointee.buf[0], sig.pointee.buf[1], sig.pointee.buf[2])
			return self.signature
		}
	}
	
	func verifiySignature() throws -> Bool {
		let real = try self.getSignature()
		let expected = self.prt!.signature
		return real == expected
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
