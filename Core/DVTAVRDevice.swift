//
//  DVTAVRDevice.swift
//  IDEAVRPlatformSupportCore
//
//  Created by Levi Dhuyvetter on 25/11/2020.
//

import Cocoa

class DVTAVRDevice: DVTDevice {
	var pgm:AVRDProgrammer? = nil
	@objc dynamic var paired = false
	@objc dynamic var connected = false
	var locator:DVTAVRDeviceLocator? = nil
	
	@objc dynamic var signature:Signature? = nil
	@objc dynamic var size:Int = 0
	
	init(id:String) {
		super.init()
		self.identifier = id
		self.platform = DVTPlatform.platform(forIdentifier: "com.atmel.platform.avr") as? DVTPlatform
		self.name = id.replacingOccurrences(of: "cu.", with: "", options: [], range: nil)
		self.modelName = "-"
		self.nativeArchitecture = "avr"
		self.supportedArchitectures = ["avr"]
		self.modelUTI = "com.apple.mac"
		self.deviceType = DVTDeviceType.deviceType(withIdentifier: "Xcode.DeviceType.AVR") as? DVTDeviceType
		self.operatingSystemVersionWithBuildNumber = "None"
		self.available = 1
	}

	override var deviceWindowCategory: Int32 { self.paired ? super.deviceWindowCategory : 5 } //0=connected,1=nowhere,2=paironly,3=ignored,4=disconnected,5=discovered,6=unknown
		
	override var deviceIsBusy: CBool { false }
	override var isPaired: CBool { self.paired }
	override var hasWiredConnection: CBool { self.pgm?.connected ?? false }
	
	
	override var allowsManagedStateControl: CBool { false }
	override var canIgnore: CBool { true } //Show as run destination checkbox enabled/disabled
	override var concreteDevice: CBool { true }
	override var image: NSImage! {
		let big = Bundle(for: type(of: self)).image(forResource: "Chip")
		let small = Bundle(for: type(of: self)).image(forResource: "MiniChip")
		big?.addRepresentation(small!.representations.first!)
		return big
	}
	override var dvt_sourceListImage: NSImage! { Bundle(for: type(of: self)).image(forResource: "SidebarChip") }
	override var canRename: CBool { true }
	override var deviceLocation: URL! { URL(fileURLWithPath: "/dev/\(self.identifier!)") }
//	override var canRunExecutables: Int8 { 1 }
	override var dvt_labeledSerialNumber: String! { return "Signature: \(self.signature?.string ?? "-")" }
	override var dvt_labeledCapacity: String! { return "Flash: \((self.size > 0 ? "\(self.size)" : "-")) bytes" }
	
	//override var runsRemoteFromHostLauncher: Int8 { 1 }
	//override var canRunMultipleInstancesPerApp: Int8 { 1 }

	override func renameDevice(_ v1: Any!) {
		if let new = v1 as? String {
			self.name = new
		}
	}
	
	override func extendedPairWithError(_ v1: AutoreleasingUnsafeMutablePointer<AnyObject?>!, extendedInformationHandler v2: (() -> Void)!) -> Bool {
		guard let wc = DVTDevicesWindowController.shared() else { return false }
		DispatchQueue.main.async {
			wc.beginOnboardingTutorialSheet()
		}
		return true
	}
	
	override func services(matching v1: DVTDeviceCapability!) -> Set<AnyHashable>! {
		return [IDERunAVRService(forDevice: self, extension: nil, capability: v1)]
		//return [IDELaunchDaemonService(forDevice: self, extension: nil, capability: v1)]
	}
	
	override func wantsDeviceOperationActivityReporting() -> Int8 {
		return 0
	}
	
	override var recordedFramesLibdispatchIntrospectionDylibPath: String! {
		return ""
	}

	override var extraDebuggingRuntimeDylibPath: String! {
		return ""
	}

	override func supportedArchitectures(forBuildableContext v1: Any!, buildParameters v2: Any!, error v3: AutoreleasingUnsafeMutablePointer<AnyObject?>!) -> Any! {
		return self.supportedArchitectures
	}
	
	override func supportedSDKs(forBuildableContext v1: Any!, buildParameters v2: Any!, error v3: AutoreleasingUnsafeMutablePointer<AnyObject?>!) -> Any! {
		let sdk = DVTSDK.sdk(forCanonicalName: "avr")!
		return NSSet(object: sdk)
	}
	
	override func forget() {
		self.pgm?.disconnect()
		self.pgm = nil
		self.locator?.delete(device: self.identifier)
		DispatchQueue.main.async {
			self.paired = false
		}
	}
	
	override func shouldPresent(forBuildableContext v1: Any!, buildParameters v2: Any!, error v3: AutoreleasingUnsafeMutablePointer<AnyObject?>!) -> Int8 {
		return 0
	}
	
	func pair(name:String, programmer:AVRDProgrammer) -> Bool {
		self.name = name
		self.pgm = programmer
		self.locator?.save(device: self)
		
		DispatchQueue.global(qos: .background).async {
			let con = (try? self.connect()) ?? false
			DispatchQueue.main.async {
				self.connected = con
			}
		}
				
		return true
	}
	
	func connect() throws -> Bool {
		guard let pgm = self.pgm else { throw "Programmer not set up. Maybe device is not paired." }
		
		try pgm.connect()
		let sig = try pgm.getSignature()
		self.signature = sig
		let _ = pgm.verifiySignature(sig)
		self.size = try pgm.getMemorySize()
		self.modelName = pgm.part
		
		return true
	}
	
	override class func keyPathsForValuesAffectingDeviceWindowCategory() -> Set<AnyHashable>! {
		return ["ignored","paired","connected"]
	}
	
	override class func keyPathsForValuesAffectingHasConnection() -> Set<AnyHashable>! {
		return ["connected"]
	}
	
	override class func keyPathsForValuesAffectingDvt_labeledSerialNumber() -> Set<AnyHashable>! {
		return ["signature"]
	}
	
	override class func keyPathsForValuesAffectingDvt_labeledCapacity() -> Set<AnyHashable>! {
		return ["size"]
	}
	
	
}
