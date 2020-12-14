#import <objc/runtime.h>
#import "DVTDeviceKit.h"
#import "IDEAVRPlatformSupportCore-Swift.h"

@implementation DVTOnboardingTutorialController (Hooks)

+ (void)load {
	static dispatch_once_t onceToken;
	dispatch_once(&onceToken, ^{
		Method originalMethod = class_getInstanceMethod([self class], @selector(pageController:viewControllerForIdentifier:));
		Method swizzledMethod = class_getInstanceMethod([self class], @selector(_pageController:viewControllerForIdentifier:));
		method_exchangeImplementations(originalMethod, swizzledMethod);
	});
}

- (DVTOnboardingPage*)_pageController:(DVTPageController*)v1 viewControllerForIdentifier:(NSString*)v2 {
	if ([v2 isEqualToString:@"setup-device"] && [[self selectedDeviceForSetup] isKindOfClass:[DVTAVRDevice class]]) {
		DVTOnboardingPage* page = [[DVTOnboardingTutorialPairDevice alloc] init];
		[page setTutorialController:self];
		return page;
	} else {
		return [self _pageController:v1 viewControllerForIdentifier:v2];
	}
}

@end
