#import <objc/runtime.h>
#import "DVTDeviceKit.h"
#import "IDEAVRPlatformSupportCore-Swift.h"

@implementation DVTOnboardingTutorialSuccess (Hooks)

+ (void)load {
	static dispatch_once_t onceToken;
	dispatch_once(&onceToken, ^{
		Method originalMethod = class_getInstanceMethod([self class], @selector(viewDidAppear));
		Method swizzledMethod = class_getInstanceMethod([self class], @selector(_viewDidAppear));
		method_exchangeImplementations(originalMethod, swizzledMethod);
	});
}

- (void)_viewDidAppear {
	[(DVTAVRDevice*)[[self tutorialController] selectedDeviceForSetup] setPaired:true];
	[self _viewDidAppear];
}

@end
