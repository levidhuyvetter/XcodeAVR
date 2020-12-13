//
//  DVTAVRDevice.swift
//  IDEAVRPlatformSupportCore
//
//  Created by Levi Dhuyvetter on 25/11/2020.
//

import Cocoa

class DVTAVRDevice: DVTDevice {
	var pgm:AVRDProgrammer? = nil
	var paired = false
	var signature:(UInt8,UInt8,UInt8) { self.pgm?.signature ?? (0,0,0) }
	var locator:DVTAVRDeviceLocator? = nil
	
	init(id:String) {
		super.init()
		self.identifier = id
		self.platform = DVTPlatform.platform(forIdentifier: "com.atmel.platform.avr") as? DVTPlatform
		self.name = id.replacingOccurrences(of: "cu.", with: "", options: [], range: nil)
		self.modelName = "None"
		self.nativeArchitecture = "avr"
		self.supportedArchitectures = ["avr"]
		self.modelUTI = "com.apple.mac"
		self.deviceType = DVTDeviceType.deviceType(withIdentifier: "Xcode.DeviceType.AVR") as? DVTDeviceType
		self.operatingSystemVersionWithBuildNumber = "None"
		self.available = 0
	}

	override var deviceWindowCategory: Int32 { self.paired ? super.deviceWindowCategory : 5 } //0=connected,1=nowhere,2=paironly,3=ignored,4=disconnected,5=discovered,6=unknown
		
	override var deviceIsBusy: Bool { false }
	override var isPaired: Bool { self.paired }
	override var hasWiredConnection: Bool { self.pgm?.connected ?? false }
	
	
	override var allowsManagedStateControl: Int8 { 0 }
	override var canIgnore: Int8 { 1 } //Show as run destination checkbox enabled/disabled
	override var concreteDevice: Int8 { 1 }
	override var image: NSImage! {
		let big = Bundle(for: type(of: self)).image(forResource: "Chip")
		let small = Bundle(for: type(of: self)).image(forResource: "MiniChip")
		big?.addRepresentation(small!.representations.first!)
		return big
	}
	override var dvt_sourceListImage: NSImage! { Bundle(for: type(of: self)).image(forResource: "SidebarChip") }
	override var canRename: Int8 { 1 }
	override var deviceLocation: URL! { URL(fileURLWithPath: "/dev/\(self.identifier!)") }
//	override var canRunExecutables: Int8 { 1 }
	override var dvt_labeledSerialNumber: String! { return "Signature: \(String(format: "%02X %02X %02X", self.signature.0, self.signature.1, self.signature.2))" }
	
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
		self.paired = false
		self.pgm?.disconnect()
		self.pgm = nil
		self.locator?.delete(device: self.identifier)
	}
	
	override func shouldPresent(forBuildableContext v1: Any!, buildParameters v2: Any!, error v3: AutoreleasingUnsafeMutablePointer<AnyObject?>!) -> Int8 {
		return 0
	}
	
	func pair(name:String, programmer:AVRDProgrammer) -> Bool {
		self.name = name
		self.pgm = programmer
		self.locator?.save(device: self)
		
		//DispatchQueue.global(qos: .userInitiated).async {
			try! self.pgm!.connect()
			try! self.pgm!.verifiySignature()
		//}
				
		return true
	}
}
