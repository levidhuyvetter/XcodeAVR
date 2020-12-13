//
//  DVTOnboardingTutorialController.swift
//  Core
//
//  Created by Levi Dhuyvetter on 10/12/2020.
//

import Foundation

extension DVTOnboardingTutorialController {
	class func avrSwizzle() {
		DVTOnboardingTutorialSuccess.avrSwizzle()
		let originalClass = DVTOnboardingTutorialController.self
		let originalMethod = class_getInstanceMethod(originalClass, #selector(DVTOnboardingTutorialController.pageController(_:viewControllerForIdentifier:)))
		let newMethod = class_getInstanceMethod(originalClass, #selector(DVTOnboardingTutorialController.avrPageController(_:viewControllerForIdentifier:)))
		method_exchangeImplementations(originalMethod!, newMethod!)
	}
	
	@objc dynamic func avrPageController(_ v1: DVTPageController!, viewControllerForIdentifier identifier: String!) -> DVTOnboardingPage! {
		if identifier == "setup-device", let _ = self.selectedDeviceForSetup as? DVTAVRDevice {
			let page = DVTOnboardingTutorialPairDevice()
			page.tutorialController = self
			
			return page
		} else {
			//Calling itself but is actually old implementation when methods are swizzled.
			return self.avrPageController(v1, viewControllerForIdentifier: identifier)
		}
	}
}

extension DVTOnboardingTutorialSuccess {
	class func avrSwizzle() {
		let originalClass = DVTOnboardingTutorialSuccess.self
		let originalMethod = class_getInstanceMethod(originalClass, #selector(DVTOnboardingTutorialSuccess.viewDidAppear))
		let newMethod = class_getInstanceMethod(originalClass, #selector(DVTOnboardingTutorialSuccess.avrViewDidAppear))
		method_exchangeImplementations(originalMethod!, newMethod!)
	}
	
	@objc dynamic func avrViewDidAppear() {
		(self.tutorialController.selectedDeviceForSetup as? DVTAVRDevice)?.paired = true
		
		//Calling itself but is actually old implementation when methods are swizzled.
		self.avrViewDidAppear()
	}
}
