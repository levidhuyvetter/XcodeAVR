class DVTAVRDeviceLocator: DVTDeviceLocator {
	let pairedDevicesURL = FileManager.default.urls(for: .applicationSupportDirectory, in: .userDomainMask).first!
	
	override var deviceLocationScheme: String! { "" }
	override var deviceType: DVTDeviceType! { DVTDeviceType.deviceType(withIdentifier: "Xcode.DeviceType.AVR") as? DVTDeviceType }
	override var platform: DVTPlatform! { DVTPlatform.platform(forIdentifier: "com.atmel.platform.avr") as? DVTPlatform }
	
	override init!() {
		super.init()
		
		DVTOnboardingTutorialController.avrSwizzle()
		
		let sys_config = strdup("/Library/Developer/Toolchains/AVR.xctoolchain/usr/etc/avrdude.conf")
		let _ = init_config()
		let _ = read_config(sys_config)
	}
	
	

	override func startLocating() {
		DispatchQueue.global(qos: .background).async {
			while true {
				if let paths = try? FileManager.default.contentsOfDirectory(atPath: "/dev/") {
					for path in paths where path.hasPrefix("cu.") {
						if !self.locatedDevices.contains(where: { ($0 as! DVTDevice).identifier == path }) {
							let device = self.open(device: path) ?? DVTAVRDevice(id: path)
							device.locator = self
							DispatchQueue.main.async {
								if !self.locatedDevices.contains(where: { ($0 as! DVTDevice).identifier == path }) {
									self.mutableLocatedDevices.add(device)
								}
							}
						}
					}
					
					for device in (self.locatedDevices as! Set<DVTDevice>) {
						if !paths.contains(device.identifier) {
							DispatchQueue.main.async {
								self.mutableLocatedDevices.remove(device)
							}
						}
					}
				}
				
				Thread.sleep(forTimeInterval: 5)
			}
		}
	}
	
	override func stopLocating() {
		//
	}
	
	func save(device:DVTAVRDevice) {
		let dic:[String:String] = [
			"name":device.name,
			"id":device.identifier,
			"programmer":device.pgm!.id,
			"baud":"\(device.pgm!.baud)"
		]
		let data = try! PropertyListEncoder().encode(dic)
		try! data.write(to: pairedDevicesURL.appendingPathComponent("/\(device.identifier!).plist"))
	}
	
	func open(device:String) -> DVTAVRDevice? {
		guard let data = try? Data(contentsOf: pairedDevicesURL.appendingPathComponent("/\(device).plist")) else { return nil }
		guard let dic = try? PropertyListDecoder().decode([String:String].self, from: data) else { return nil }
		guard let name = dic["name"] else { return nil }
		guard let id = dic["id"] else { return nil }
		guard let prgName = dic["programmer"] else { return nil }
		guard let baudStr = dic["baud"] else { return nil }
		guard let baud = Int(baudStr) else { return nil }
		
		let programmer = AVRDProgrammer(prgName, port: "/dev/\(id)")
		programmer.baud = baud
		let device = DVTAVRDevice(id: id)
		device.name = name
		device.pgm = programmer
		device.paired = true
		
		DispatchQueue.global(qos: .background).async {
			let con = (try? device.connect()) ?? false
			DispatchQueue.main.async {
				device.connected = con
			}
		}
		
		return device
	}
	
	func delete(device:String) {
		guard FileManager.default.fileExists(atPath: pairedDevicesURL.appendingPathComponent("/\(device).plist").path) else { return }
		try? FileManager.default.removeItem(atPath: pairedDevicesURL.appendingPathComponent("/\(device).plist").path)
	}
}
