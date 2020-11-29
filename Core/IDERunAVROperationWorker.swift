//
//  IDERunAVROperation.swift
//  IDEAVRPlatformSupportCore
//
//  Created by Levi Dhuyvetter on 25/11/2020.
//

import Cocoa

class IDERunAVROperationWorker:IDERunOperationWorker {
	override func performAction() {
		super.performAction()
		
		
		
//		let elfpath:String = self.launchSession.launchParameters.runnableLocation.pathString
//		let hexpath:String = elfpath.replacingOccurrences(of: ".elf", with: ".hex")
//		let port:String = "/dev/" + self.launchSession.runDestination.targetDevice.identifier
//		let toolchain = DVTToolchainRegistry.default()?.toolchain(forIdentifier: "com.atmel.toolchain.avr")
//		let avrdude:String = toolchain!.path.pathString + "/usr/bin/avrdude"
//		let objcopy:String = toolchain!.path.pathString + "/usr/bin/avr-objcopy"
//
//		let task = Process()
//		task.launchPath = objcopy
//		task.arguments = ["-Oihex", elfpath, hexpath, "--set-start=0"]
//		let pipe = Pipe()
//		task.standardOutput = pipe
//		task.launch()
//		task.waitUntilExit()
//		let data = pipe.fileHandleForReading.readDataToEndOfFile()
//		let output = String(data: data, encoding: .utf8)
//		print(output ?? "No output")
//
//		let task2 = Process()
//		task2.launchPath = avrdude
//		task2.arguments = ["-v", "-pm328p", "-cstk500v1", "-P\(port)", "-b19200", "-Uflash:w:\(hexpath):i"]
//		let pipe2 = Pipe()
//		task2.standardOutput = pipe2
//		task2.launch()
//		task2.waitUntilExit()
//		let data2 = pipe2.fileHandleForReading.readDataToEndOfFile()
//		let output2 = String(data: data2, encoding: .utf8)
//		print(output2 ?? "No output")
	}
}
