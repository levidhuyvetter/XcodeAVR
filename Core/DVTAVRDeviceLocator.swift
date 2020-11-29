class DVTAVRDeviceLocator: DVTDeviceLocator {
	override var deviceLocationScheme: String! { "" }
	override var deviceType: DVTDeviceType! { DVTDeviceType.deviceType(withIdentifier: "Xcode.DeviceType.AVR") as? DVTDeviceType }
	override var platform: DVTPlatform! { DVTPlatform.platform(forIdentifier: "com.atmel.platform.avr") as? DVTPlatform }

	override func startLocating() {
		DispatchQueue.global(qos: .background).async {
			while true {
				if let paths = try? FileManager.default.contentsOfDirectory(atPath: "/dev/") {
					for path in paths where path.hasPrefix("cu.") {
						if !self.locatedDevices.contains(where: { ($0 as! DVTDevice).identifier == path }) {
							let device = DVTAVRDevice()
							device.identifier = path
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
}
