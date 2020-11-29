//
//  IDERunAVRService.swift
//  IDEAVRPlatformSupportCore
//
//  Created by Levi Dhuyvetter on 25/11/2020.
//

import Cocoa

class IDERunAVRService: IDERunDeviceService {
	override func operationWorker(withLaunchSession v1: Any!, error v2: AutoreleasingUnsafeMutablePointer<AnyObject?>!) -> Any! {
		let worker = IDERunAVROperationWorker(extensionIdentifier: nil, launchSession: v1)
		return worker
	}
}
