//
//  DVTAVRDevice.swift
//  IDEAVRPlatformSupportCore
//
//  Created by Levi Dhuyvetter on 25/11/2020.
//

import Cocoa

class DVTAVRDevice: DVTDevice {
	override init() {
		super.init()
		self.identifier = "/dev/cu.SLAB_USBtoUART"
		self.platform = DVTPlatform.platform(forIdentifier: "com.atmel.platform.avr") as? DVTPlatform
		self.name = "Atmega328P"
		self.modelName = "Microchip Atmega328P"
		self.available = 1
		self.nativeArchitecture = "avr"
		self.supportedArchitectures = ["avr"]
		self.ignored = 0
		self.modelUTI = "com.apple.mac"
		self.usedForDevelopment = 1
		self.deviceType = DVTDeviceType.deviceType(withIdentifier: "Xcode.DeviceType.AVR") as? DVTDeviceType
		self.isCloudDevice = 0
		self.operatingSystemVersionWithBuildNumber = "None"
		
//		let programmer = strdup("stk500v1")
//		let port = strdup(self.identifier)
//		let partdesc = strdup("m328p")
//
//		let pgm = locate_programmer(programmers, programmer)
//		pgm?.pointee.initpgm(pgm)
//		pgm?.pointee.setup(pgm)
//
//		let prt = locate_part(part_list, partdesc)
//		avr_initmem(prt)
//
//		pgm?.pointee.baudrate = 19200
//		let _ = pgm?.pointee.open(pgm, port)
//		pgm?.pointee.enable(pgm)
//		let _ = pgm?.pointee.rdy_led(pgm, OFF)
//		let _ = pgm?.pointee.err_led(pgm, OFF)
//		let _ = pgm?.pointee.pgm_led(pgm, OFF)
//		let _ = pgm?.pointee.vfy_led(pgm, OFF)
//
//		let _ = pgm?.pointee.initialize(pgm, prt)
//
//		let _ = pgm?.pointee.rdy_led(pgm, ON)
//
//		let _ = avr_signature(pgm, prt)
//		let sig = avr_locate_mem(prt, strdup("signature"))
	}

	override var hasConnection: Bool { true }
	override var hasWiredConnection: Bool { true }
	override var hasWirelessConnection: Bool { false }
	override var allowsManagedStateControl: Int8 { 0 }
	override var canIgnore: Int8 { 1 } //Show as run destination checkbox enabled/disabled
	override var concreteDevice: Int8 { 1 }
	override var nameForDeveloperPortal: String! { self.name }
	override var image: NSImage! {
		let big = Bundle(for: type(of: self)).image(forResource: "Chip")
		let small = Bundle(for: type(of: self)).image(forResource: "MiniChip")
		big?.addRepresentation(small!.representations.first!)
		return big
	}
	override var dvt_sourceListImage: NSImage! { Bundle(for: type(of: self)).image(forResource: "SidebarChip") }
	override var isRunningSupportedOS: Int8 { 1 }
	override var isPaired: Bool { true }
	override var canRename: Int8 { 1 }
	override var deviceLocation: URL! { URL(fileURLWithPath: "/") }
	override var canRunExecutables: Int8 { 1 }
	
	override var runsRemoteFromHostLauncher: Int8 { 1 }
	override var canRunMultipleInstancesPerApp: Int8 { 1 }

	override func renameDevice(_ v1: Any!) {
		if let new = v1 as? String {
			self.name = new
		}
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
	
	override func startOperation() -> Any! {
		return super.startOperation()
	}
	
	override func runExecutable(atPath v1: Any!, withArguments v2: Any!, environment v3: Any!, options v4: Any!, terminationHandler v5: (() -> Void)!) -> Any! {
		return super.runExecutable(atPath: v1, withArguments: v2, environment: v3, options: v4, terminationHandler: v5)
	}
	
	override func endOperation(_ v1: Any!) {
		super.endOperation(v1)
	}
}
