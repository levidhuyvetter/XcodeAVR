#import <Cocoa/Cocoa.h>
#import "DVTFoundation.h"
#import "IDEFoundation.h"

@class DVTOnboardingTutorialController;
@class DVTPageController;

//
//
///*****************************************************************/
//
@protocol DVTDevicesListViewControllerDelegate<NSObject>
- (void)didFinishLoadingDevices:(id)v1;
@end
//
//
///*****************************************************************/
//

//
//
///*****************************************************************/
//

//
//
///*****************************************************************/
//
//@protocol DVTTabChooserViewDelegate<NSObject>
//- (void)tabChooserView:(id)v1 userDidChooseChoice:(id)v2;
//@end
//
//
///*****************************************************************/
//
//@protocol DVTInvalidation<NSObject>
//@property (readonly,nonatomic,getter=isValid) char valid;
//@property (readonly) DVTStackBacktrace * invalidationBacktrace;
//@property (retain) DVTStackBacktrace * creationBacktrace;
//- (void)primitiveInvalidate;
//
//@optional
//+ (unsigned long long)assertionBehaviorAfterEndOfEventForSelector:(SEL)v1;
//+ (unsigned long long)assertionBehaviorForKeyValueObservationsAtEndOfEvent;
//+ (char)supportsInvalidationPrevention;
//- (void)invalidate;
//- (void)addAutoInvalidatedObject:(id)v1;
//- (char)isValid;
//- (id)invalidationBacktrace;
//- (id)creationBacktrace;
//- (void)setCreationBacktrace:(id)v1;
//@end
//
//
///*****************************************************************/
//
//@protocol DVTDevicesWindowDetailViewController<DVTInvalidation>
//@property (retain,nonatomic) DVTDevice * device;
//- (id)device;
//- (void)setDevice:(id)v1;
//
//@optional
//- (void)detailViewDidAppear;
//- (void)detailViewDidDisappear;
//@end
//
//
///*****************************************************************/
//
//@protocol AKPinFieldViewDelegate<NSObject>
//
//@optional
//- (void)pinFieldViewTextDidChange:(id)v1;
//- (void)pinFieldViewTextDidComplete:(id)v1;
//@end
//
//
///*****************************************************************/
//
//@protocol DVTMenuBuilder<NSObject>
//+ (id)contextHelpMenuItemForHelpID:(id)v1 andTitle:(id)v2;
//
//@optional
//+ (id)contextHelpMenuItemForHelpID:(id)v1;
//@end
//
//
///*****************************************************************/
//

//
//
///*****************************************************************/
//

//
//
///*****************************************************************/
//
//@protocol DVTDevicesListItem<NSObject>
//@property (retain) NSString * name;
//@property (readonly,getter=isEditable) char editable;
//@property (readonly,getter=isGroupItem) char groupItem;
//@property (retain) DVTDevice * device;
//@property (readonly,getter=isLeaf) char leaf;
//@property (readonly) NSMutableArray * children;
//- (id)name;
//- (void)setName:(id)v1;
//- (char)isEditable;
//- (char)isGroupItem;
//- (id)device;
//- (void)setDevice:(id)v1;
//- (char)isLeaf;
//- (id)children;
//@end
//
//
///*****************************************************************/
//
@protocol AKAppleIDAuthenticationDelegate<NSObject>

@optional
- (char)authenticationController:(id)v1 shouldContinueWithAuthenticationResults:(id)v2 error:(id)v3 forContext:(id)v4;
- (void)authenticationController:(id)v1 shouldContinueWithAuthenticationResults:(id)v2 error:(id)v3 forContext:(id)v4 completion:(void (^ /* unknown block signature */)(void))v5;
@end
//
//
///*****************************************************************/
//

//
//
///*****************************************************************/
//

//
//
///*****************************************************************/
//
//@protocol DVTTableViewDelegate<NSTableViewDelegate>
//
//@optional
//- (char)tableView:(id)v1 doCommandBySelector:(SEL)v2;
//- (unsigned long long)tableView:(id)v1 draggingSourceOperationMaskForLocal:(char)v2;
//- (void)tableView:(id)v1 draggingDidEnter:(id)v2;
//- (void)tableView:(id)v1 draggingDidUpdate:(id)v2;
//- (void)tableView:(id)v1 draggingDidEnd:(id)v2;
//- (void)tableView:(id)v1 concludeDragOperation:(id)v2;
//@end
//
//
///*****************************************************************/
//

//
//
///*****************************************************************/
//
//@protocol DVTCodesignableDevice<NSObject>
//@property (readonly,copy,nonatomic) NSString * name;
//@property (readonly,copy) NSString * nameForDeveloperPortal;
//@property (readonly,copy,nonatomic) NSString * identifier;
//@property (readonly,copy) NSString * platformIdentifier;
//@property (readonly) DVTPlatform * platform;
//@property (readonly) char supportsProvisioning;
//@property (readonly,copy) NSSet * proxiedDevices;
//- (id)name;
//- (id)nameForDeveloperPortal;
//- (id)identifier;
//- (id)platformIdentifier;
//- (id)platform;
//- (char)supportsProvisioning;
//- (id)proxiedDevices;
//@end
//
//
///*****************************************************************/
//
//@protocol DVTBasicDevice<DVTCodesignableDevice>
//@property (readonly,copy,nonatomic) NSString * modelName;
//@property (readonly,copy,nonatomic) NSString * modelCodename;
//@property (readonly,copy,nonatomic) NSString * modelCode;
//@property (readonly,copy,nonatomic) NSString * modelUTI;
//@property (readonly,copy) NSString * processorDescription;
//@property (readonly,copy) NSString * operatingSystemVersion;
//@property (readonly,copy) NSString * iOSSupportVersion;
//@property (readonly,copy) NSString * operatingSystemBuild;
//@property (readonly,copy,nonatomic) NSString * operatingSystemVersionWithBuildNumber;
//@property (readonly) DVTPlatform * platform;
//@property (readonly,copy) NSString * nativeArchitecture;
//@property (readonly) char isProxiedDevice;
//@property (readonly,getter=isAvailable) char available;
//@property (readonly) NSError * unavailabilityError;
//@property (readonly) bool deviceIsBusy;
//- (char)isAvailableWithError:(id *)v1;
//- (id)modelName;
//- (id)modelCodename;
//- (id)modelCode;
//- (id)modelUTI;
//- (id)processorDescription;
//- (id)operatingSystemVersion;
//- (id)iOSSupportVersion;
//- (id)operatingSystemBuild;
//- (id)operatingSystemVersionWithBuildNumber;
//- (id)platform;
//- (id)nativeArchitecture;
//- (char)isProxiedDevice;
//- (char)isAvailable;
//- (id)unavailabilityError;
//- (bool)deviceIsBusy;
//
//@optional
//- (id)primaryInstrumentsServer;
//- (void)cancelPrimaryInstrumentsServer;
//@end
//
//
///*****************************************************************/
//
@protocol DVTBasicDeviceUI<DVTBasicDevice>
@property (readonly) NSArray * deviceSummaryPropertyDictionaries;
@property (readonly) NSImage * image;
@property (readonly) NSImage * proxyDeviceImage;
@property (readonly) char showCompanionUI;
@property (readonly) int deviceWindowCategory;
- (id)deviceSummaryPropertyDictionaries;
- (id)image;
- (id)proxyDeviceImage;
- (char)showCompanionUI;
- (int)deviceWindowCategory;
@end
//
//
///*****************************************************************/
//
//@protocol DVTDeviceApplicationProvider<NSObject>
//@property (readonly) NSSet * applications;
//@property (readonly) NSSet * systemApplications;
//- (id)applications;
//
//@optional
//- (id)systemApplications;
//@end
//
//
///*****************************************************************/
//
//@protocol DVTDeviceApplicationInstaller<DVTDeviceApplicationProvider>
//- (id)uninstallApplicationWithBundleIdentifierSync:(id)v1;
//- (char)downloadApplicationDataToPath:(id)v1 forInstalledApplicationWithBundleIdentifier:(id)v2 error:(id *)v3;
//- (char)uploadApplicationDataWithPath:(id)v1 forInstalledApplicationWithBundleIdentifier:(id)v2 error:(id *)v3;
//@end
//
//
///*****************************************************************/
//
//@protocol DVTPreparableDevice
//@property (readonly) NSArray * developerPrepErrors;
//@property (readonly) NSArray * developerPrepWarnings;
//- (void)addPrepError:(id)v1;
//- (void)addPrepWarning:(id)v1;
//- (unsigned long long)prepErrorsAndWarningsCount;
//- (id)developerPrepErrors;
//- (id)developerPrepWarnings;
//@end
//
//
///*****************************************************************/
//

//
//
///*****************************************************************/
//

//
//
///*****************************************************************/
//
//@protocol DVTFilterExpressionPresentationDelegate<NSObject>
//@property (nonatomic,readonly) NSString * filterFieldToolTip;
//@property (nonatomic,readonly) NSString * filterFieldAccessibilityDescription;
//- (id)filterFieldToolTip;
//- (id)filterFieldAccessibilityDescription;
//- (id)titleForFilterIdentifier:(id)v1;
//- (id)titleForFilterIdentifier:(id)v1;
//- (id)filterExpressionForText:(id)v1 isComplete:(char)v2 currentFilterExpression:(id)v3;
//- (id)filterExpressionForText:(id)v1 isComplete:(char)v2 currentFilterExpression:(id)v3;
//- (id)validFilterExpressionsForExpressions:(id)v1 currentFilterExpression:(id)v2;
//- (id)validFilterExpressionsForExpressions:(id)v1 currentFilterExpression:(id)v2;
//- (id)fieldDisplayStringForFilterExpression:(id)v1;
//- (id)fieldDisplayStringForFilterExpression:(id)v1;
//- (id)menuDisplayStringForFilterExpression:(id)v1;
//- (id)menuDisplayStringForFilterExpression:(id)v1;
//- (id)editingStringForFilterExpression:(id)v1;
//- (id)editingStringForFilterExpression:(id)v1;
//
//@optional
//- (id)prefixFieldDisplayStringForFilterExpression:(id)v1;
//- (id)prefixFieldDisplayStringForFilterExpression:(id)v1;
//- (id)suffixFieldDisplayStringForFilterExpression:(id)v1;
//- (id)suffixFieldDisplayStringForFilterExpression:(id)v1;
//- (id)buttonsForCustomFilterExpressions;
//- (id)filterExpressionsForAdditionalFilteringOptionsMenu;
//- (id)filterExpressionsForSampleFiltersMenu;
//- (id)relatedFilterExpressionsIncludingExpression:(id)v1;
//- (id)relatedFilterExpressionsIncludingExpression:(id)v1;
//- (id)relatedFilterExpressionsAffectingTypeIncludingExpression:(id)v1;
//- (id)relatedFilterExpressionsAffectingTypeIncludingExpression:(id)v1;
//- (id)textFragmentsForFilterExpression:(id)v1;
//- (id)textFragmentsForFilterExpression:(id)v1;
//- (id)filterExpressionCompletionsForText:(id)v1 currentFilterExpression:(id)v2;
//- (id)filterExpressionCompletionsForText:(id)v1 currentFilterExpression:(id)v2;
//@end
//
//
///*****************************************************************/
//
//@protocol DVTFilteredDataViewingContext<NSObject>
//@property (nonatomic,readonly) long long filterProgress;
//@property (nonatomic,copy) NSArray * highlightFragments;
//- (long long)filterProgress;
//- (void)showMatches:(id)v1 added:(id)v2 removed:(id)v3;
//
//@optional
//- (id)highlightFragments;
//- (void)setHighlightFragments:(id)v1;
//@end
//
//
///*****************************************************************/
//
//@protocol DVTFilteredDataSource<NSObject>
//@property (nonatomic,readonly) OS_dispatch_queue * filteringQueue;
//- (id)filteringQueue;
//- (void)filterWithFilterSession:(id)v1;
//- (void)filterWithFilterSession:(id)v1;
//
//@optional
//- (void)filterSessionWillBegin:(id)v1;
//- (void)filterSessionDidEnd:(id)v1;
//@end
//
//
///*****************************************************************/
//

//
//
///*****************************************************************/
//
@interface DVTDevice (KitAdditions)<DVTBasicDeviceUI>
@property (readonly) NSImage * dvt_statusImage;
@property (readonly) NSImage * dvt_proxiedDeviceImage;
@property (readonly) bool dvt_deviceIsSimulator;
@property (readonly) bool dvt_deviceIsConnectedAndNotIgnored;
@property (readonly) bool dvt_hideStatusImage;
@property (readonly) bool dvt_hideBusyIndicator;
@property (readonly) NSString * dvt_deviceWindowCategoryDescription;
@property (readonly) NSString * dvt_osVersion;
@property (readonly) NSString * dvt_labeledModelName;
@property (readonly) NSString * dvt_labeledCapacity;
@property (readonly) NSString * dvt_labeledSerialNumber;
@property (readonly) NSString * dvt_platformUserDescription;
@property (readonly) NSImage * dvt_sourceListImage;
@property (readonly) NSArray * deviceSummaryPropertyDictionaries;
@property (readonly) NSImage * image;
@property (readonly) NSImage * proxyDeviceImage;
@property (readonly) char showCompanionUI;
@property (readonly) int deviceWindowCategory;
@property (readonly,copy,nonatomic) NSString * modelName;
@property (readonly,copy,nonatomic) NSString * modelCodename;
@property (readonly,copy,nonatomic) NSString * modelCode;
@property (readonly,copy,nonatomic) NSString * modelUTI;
@property (readonly,copy) NSString * processorDescription;
@property (readonly,copy) NSString * operatingSystemVersion;
@property (readonly,copy) NSString * iOSSupportVersion;
@property (readonly,copy) NSString * operatingSystemBuild;
@property (readonly,copy,nonatomic) NSString * operatingSystemVersionWithBuildNumber;
@property (readonly) DVTPlatform * platform;
@property (readonly,copy) NSString * nativeArchitecture;
@property (readonly) char isProxiedDevice;
@property (readonly,getter=isAvailable) char available;
@property (readonly) NSError * unavailabilityError;
@property (readonly) bool deviceIsBusy;
@property (readonly,copy,nonatomic) NSString * name;
@property (readonly,copy) NSString * nameForDeveloperPortal;
@property (readonly,copy,nonatomic) NSString * identifier;
@property (readonly,copy) NSString * platformIdentifier;
@property (readonly) char supportsProvisioning;
@property (readonly,copy) NSSet * proxiedDevices;
//@property (readonly) unsigned long long hash;
@property (readonly) Class superclass;
@property (readonly,copy) NSString * description;
@property (readonly,copy) NSString * debugDescription;
+ (NSSet*)keyPathsForValuesAffectingDeviceWindowCategory;
+ (NSSet*)keyPathsForValuesAffectingDvt_statusImage;
+ (NSSet*)keyPathsForValuesAffectingDvt_hideStatusImage;
+ (NSSet*)keyPathsForValuesAffectingDvt_hideBusyIndicator;
+ (NSSet*)keyPathsForValuesAffectingDvt_deviceIsConnectedAndNotIgnored;
+ (NSSet*)keyPathsForValuesAffectingDvt_osVersion;
+ (NSSet*)keyPathsForValuesAffectingDvt_labeledModelName;
+ (NSSet*)keyPathsForValuesAffectingDvt_labeledCapacity;
+ (NSSet*)keyPathsForValuesAffectingDvt_labeledSerialNumber;
+ (NSSet*)keyPathsForValuesAffectingDvt_platformUserDescription;
- (int)deviceWindowCategory;
- (id)dvt_deviceWindowCategoryDescription;
- (char)showCompanionUI;
- (id)image;
- (id)proxyDeviceImage;
- (id)dvt_sourceListImage;
- (id)deviceSummaryPropertyDictionaries;
- (id)dvt_statusImage;
- (id)dvt_proxiedDeviceImage;
- (bool)dvt_hideStatusImage;
- (bool)dvt_hideBusyIndicator;
- (bool)dvt_deviceIsSimulator;
- (bool)dvt_deviceIsConnectedAndNotIgnored;
- (id)dvt_osVersion;
- (id)dvt_labeledModelName;
- (id)dvt_labeledCapacity;
- (id)dvt_labeledSerialNumber;
- (id)_labeledPropertyValue:(id)v1;
- (id)_deviceSummaryValueForProperty:(id)v1;
- (id)dvt_platformUserDescription;
@end
//
//
///*****************************************************************/
//
//@interface DVTLocalComputer (KitAdditions)
//- (int)deviceWindowCategory;
//- (id)image;
//- (id)deviceSummaryPropertyDictionaries;
//- (void)showTodayViewForExtensions:(id)v1 pid:(int)v2;
//- (void)showSiriForExtensions:(id)v1 queryText:(id)v2 pid:(int)v3 onProxy:(char)v4 completed:(void (^ /* unknown block signature */)(void))v5;
//- (void)showQuicklookPreviewForExtension:(id)v1;
//@end
//
//
///*****************************************************************/
//
@interface DVTDeviceLocator (KitAdditions)
@property (readonly) char canCreateDevices;
- (char)canCreateDevices;
- (void)beginDeviceCreationAssistantWithWindow:(id)v1 completionHandler:(void (^ /* unknown block signature */)(void))v2;
- (void)beginPairingAssistantForDevice:(id)v1 withWindow:(id)v2 completionHandler:(void (^ /* unknown block signature */)(void))v3;
@end
//
//
///*****************************************************************/
//
@interface DVTDevicesWindowController : NSWindowController<DVTDevicesListViewControllerDelegate,NSMenuDelegate,NSWindowDelegate> {
    //DVTDeviceProvisioningProfilesSheetController * _provisioningProfilesSheet;
    //void (^ /* unknown block signature */)(void) _devicesWindowCompletionHandler;
    //NSWindow * _tutorialWindow;
    //DVTOnboardingTutorialController * _tutorialController;
    //DVTDevicesListViewController * _devicesListViewController;
    NSMutableSet * _loadedModes;
}
//@property (copy) void (^ /* unknown block signature */)(void) devicesWindowCompletionHandler;
//@property (retain) NSWindow * tutorialWindow;
//@property (retain) DVTOnboardingTutorialController * tutorialController;
//@property DVTDevicesListViewController * devicesListViewController;
@property (retain) NSMutableSet * loadedModes;
//@property (readonly) unsigned long long hash;
@property (readonly) Class superclass;
@property (readonly,copy) NSString * description;
@property (readonly,copy) NSString * debugDescription;
+ (void)initialize;
+ (id)logAspect;
+ (DVTDevicesWindowController*)sharedDevicesWindowController;
+ (char)shouldShowDeviceConsole;
+ (id)_provisioningProfileTypeIdentifers;
+ (id)supportedFileDataTypeIdentifiers;
- (void)showWindowWithCompletionHandler:(void (^ /* unknown block signature */)(void))v1;
- (void)showWindow:(id)v1;
- (void)windowWillClose:(id)v1;
- (char)openFileURL:(id)v1 withFileType:(id)v2 error:(id *)v3;
- (void)beginOnboardingTutorialSheet;
- (void)didFinishLoadingDevices:(id)v1;
- (void)showProvisioningProfiles:(id)v1;
- (void)selectTabForMode:(long long)v1 completionHandler:(void (^ /* unknown block signature */)(void))v2;
- (void)selectDevice:(id)v1;
@end
//
//
///*****************************************************************/
//
//@interface DVTDevicesWindow : NSWindow
//- (void)setContentView:(id)v1;
//@end
//
//
///*****************************************************************/
//
//@interface DVTDeviceConsoleViewController : DVTViewController<DVTTabChooserViewDelegate,DVTDevicesWindowDetailViewController> {
//    DVTObservingToken * _proxiedDeviceObserver;
//    DVTObservingToken * _installedViewControllerObserver;
//    DVTObservingToken * _deviceWindowCategoryObserer;
//    char _animating;
//    char _consoleVisible;
//    DVTDevice * _device;
//    DVTReplacementView * _replacementView;
//    DVTDeviceContentSplitViewController * _splitViewController;
//    DVTBorderedView * _footerView;
//    DVTGradientImageButton * _consoleButton;
//    DVTTabChooserView * _consoleChooserView;
//    NSLayoutConstraint * _consoleChooserWidthConstraint;
//    NSButton * _consoleClearButton;
//    NSButton * _consoleSaveButton;
//    NSArray * _savedConsoleChoices;
//    NSString * _savedConsoleSelectedChoiceTitle;
//}
//@property (retain) DVTBorderedView * footerView;
//@property (retain) DVTGradientImageButton * consoleButton;
//@property (retain) DVTTabChooserView * consoleChooserView;
//@property (retain) NSLayoutConstraint * consoleChooserWidthConstraint;
//@property (retain) NSButton * consoleClearButton;
//@property (retain) NSButton * consoleSaveButton;
//@property (nonatomic,getter=isConsoleVisible) char consoleVisible;
//@property (readonly) DVTViewController<DVTDevicesWindowConsoleViewController> * consoleViewController;
//@property (retain) NSArray * savedConsoleChoices;
//@property (retain) NSString * savedConsoleSelectedChoiceTitle;
//@property (retain) DVTReplacementView * replacementView;
//@property DVTDeviceContentSplitViewController * splitViewController;
//@property (readonly) double footerViewHeight;
//@property char animating;
//@property (readonly) unsigned long long hash;
//@property (readonly) Class superclass;
//@property (readonly,copy) NSString * description;
//@property (readonly,copy) NSString * debugDescription;
//@property (retain,nonatomic) DVTDevice * device;
//@property (readonly,nonatomic,getter=isValid) char valid;
//@property (readonly) DVTStackBacktrace * invalidationBacktrace;
//@property (retain) DVTStackBacktrace * creationBacktrace;
//+ (void)initialze;
//- (id)initWithNibName:(id)v1 bundle:(id)v2;
//- (id)initWithCoder:(id)v1;
//- (void)primitiveInvalidate;
//- (void)viewDidLoad;
//- (void)viewDidAppear;
//- (void)viewDidDisappear;
//- (void)_adjustButtonStyling:(id)v1;
//- (void)viewDidLayout;
//- (void)toggleConsole:(id)v1;
//- (void)clearConsole:(id)v1;
//- (void)saveConsole:(id)v1;
//- (void)tabChooserView:(id)v1 userDidChooseChoice:(id)v2;
//- (void)_saveConsoleVisibleState;
//- (void)_saveConsoleDividerPositionState;
//- (void)_restoreConsoleVisibleState;
//- (void)_restoreConsoleDividerPositionState;
//- (void)_restoreConsoleState;
//- (void)_syncConsoleTabChoices;
//- (void)_syncConsoleTabSelectedChoice;
//- (void).cxx_destruct;
//@end
//
//
///*****************************************************************/
//
//@interface DVTDevicesWindowSplitViewController : NSSplitViewController {
//    DVTObservingToken * _selectionObserver;
//}
//@property (retain) DVTObservingToken * selectionObserver;
//@property long long mode;
//- (void)viewWillAppear;
//- (void)viewWillDisappear;
//- (char)splitView:(id)v1 canCollapseSubview:(id)v2;
//- (char)includesDevice:(id)v1;
//- (void)selectDevice:(id)v1;
//- (void)_updateDetailsWithDevice:(id)v1;
//- (void).cxx_destruct;
//@end
//
//
///*****************************************************************/
//
//@interface DVTDevicePairViewController : DVTViewController<AKPinFieldViewDelegate,DVTDevicesWindowDetailViewController> {
//    char _pinEntryComplete;
//    char _hasSetupConstraints;
//    DVTDevice * _device;
//    NSView * _waitToStartCenteringView;
//    NSImageView * _waitingToStartDeviceImageView;
//    NSButton * _startPairingButton;
//    NSView * _pinCenteringView;
//    NSImageView * _deviceImageView;
//    NSTextField * _enterPINLabel;
//    NSView * _pinContainerView;
//    NSLayoutConstraint * _widthOfPinViewConstraint;
//    NSButton * _connectButton;
//    NSView * _busyCenteringView;
//    NSTextField * _settingUpLabel;
//    NSProgressIndicator * _busyProgressIndicator;
//    NSView * _errorCenteringView;
//    NSTextField * _errorLabel;
//    NSButton * _retryButton;
//    AKPinFieldView * _pinView;
//    long long _state;
//    NSObject<DVTDeviceAction> * _pairAction;
//    void (^ /* unknown block signature */)(void) _infoRequestCallback;
//    DVTObservingToken * _nameObservingToken;
//}
//@property (retain) NSView * waitToStartCenteringView;
//@property (retain) NSImageView * waitingToStartDeviceImageView;
//@property (retain) NSButton * startPairingButton;
//@property (retain) NSView * pinCenteringView;
//@property (retain) NSImageView * deviceImageView;
//@property (retain) NSTextField * enterPINLabel;
//@property (retain) NSView * pinContainerView;
//@property (retain) NSLayoutConstraint * widthOfPinViewConstraint;
//@property (retain) NSButton * connectButton;
//@property (retain) NSView * busyCenteringView;
//@property (retain) NSTextField * settingUpLabel;
//@property (retain) NSProgressIndicator * busyProgressIndicator;
//@property (retain) NSView * errorCenteringView;
//@property (retain) NSTextField * errorLabel;
//@property (retain) NSButton * retryButton;
//@property (retain) AKPinFieldView * pinView;
//@property char pinEntryComplete;
//@property (nonatomic) long long state;
//@property (retain) NSObject<DVTDeviceAction> * pairAction;
//@property (copy) void (^ /* unknown block signature */)(void) infoRequestCallback;
//@property char hasSetupConstraints;
//@property (retain) DVTObservingToken * nameObservingToken;
//@property (readonly) unsigned long long hash;
//@property (readonly) Class superclass;
//@property (readonly,copy) NSString * description;
//@property (readonly,copy) NSString * debugDescription;
//@property (retain,nonatomic) DVTDevice * device;
//@property (readonly,nonatomic,getter=isValid) char valid;
//@property (readonly) DVTStackBacktrace * invalidationBacktrace;
//@property (retain) DVTStackBacktrace * creationBacktrace;
//- (void)awakeFromNib;
//- (void)viewDidLoad;
//- (void)viewDidLayout;
//- (void)viewWillDisappear;
//- (void)primitiveInvalidate;
//- (void)startPairing:(id)v1;
//- (void)connect:(id)v1;
//- (void)retry:(id)v1;
//- (void)_setupDeviceObservers;
//- (void)_removeDeviceObservers;
//- (void)pinFieldViewTextDidChange:(id)v1;
//- (void)pinFieldViewTextDidComplete:(id)v1;
//- (void)_beginPairing;
//- (void)_resetPinView;
//- (void)_transitionToState:(long long)v1;
//- (void).cxx_destruct;
//@end
//
//
///*****************************************************************/
//
//@interface DVTDevicesDebugInfoFixupCenter : NSObject {
//    NSMetadataQuery * _dsymQuery;
//    DVTNotificationToken * _dsymFinishedInitialGatheringToken;
//    DVTNotificationToken * _dsymUpdateToken;
//}
//+ (id)logAspect;
//+ (id)sharedCenter;
//+ (id)_dSYMFixupUuidImporterPath;
//+ (void)_dSYMFixupFixItem:(id)v1;
//- (id)init;
//- (void)dealloc;
//- (void)startFixup;
//- (void)stopFixup;
//- (char)_isEnabled;
//- (void)_dSYMFixupQueryDidFinishInitialGathering:(id)v1;
//- (void)_dSYMFixupQueryDidUpdate:(id)v1;
//- (void).cxx_destruct;
//@end
//
//
///*****************************************************************/
//
//@interface DVTDevicesListViewController : DVTViewController<NSOutlineViewDelegate,NSMenuDelegate> {
//    DVTObservingToken * _devicesObserver;
//    NSMutableDictionary * _deviceObservationTokens;
//    DVTDelayedInvocation * _delayedDevicesDisplayUpdateInvocation;
//    NSObject<DVTInvalidation> * _sidebarLayoutObserverToken;
//    char _updatingDevicesForDisplay;
//    char _helpMenuItemAdded;
//    char _promptingForDelete;
//    char _restoringExpansionState;
//    long long _mode;
//    NSObject<DVTDevicesListViewControllerDelegate> * _delegate;
//    NSTreeController * _devicesTreeController;
//    NSView * _contentView;
//    NSOutlineView * _devicesOutline;
//    DVTGradientImageButton * _addDevice;
//    DVTSearchField * _searchField;
//    DVTScopeBarButton * _devicesScopeButton;
//    DVTScopeBarButton * _simulatorsScopeButton;
//    NSMenu * _devicesMenu;
//    NSMenuItem * _deleteSimMenuItem;
//    NSMenuItem * _connectViaAddressMenuItem;
//    NSMenuItem * _forgetDeviceSeparatorMenuItem;
//    NSMenuItem * _forgetDeviceMenuItem;
//    NSMenu * _addDeviceMenu;
//    NSMutableSet * _devices;
//    NSArray * _devicesOutlineSelectionIndexPaths;
//    NSString * _filterString;
//    NSMutableDictionary * _wirelessEnablingFutures;
//    NSMutableDictionary * _headerItems;
//    NSMutableDictionary * _deviceItems;
//    NSMutableDictionary * _indexPathForDeviceIdentifier;
//    NSObject<DVTDeviceAction> * _forgetDeviceAction;
//}
//@property (retain) NSTreeController * devicesTreeController;
//@property (retain) NSView * contentView;
//@property (retain) NSOutlineView * devicesOutline;
//@property (retain) DVTGradientImageButton * addDevice;
//@property (retain) DVTSearchField * searchField;
//@property (retain) DVTScopeBarButton * devicesScopeButton;
//@property (retain) DVTScopeBarButton * simulatorsScopeButton;
//@property (retain) NSMenu * devicesMenu;
//@property (retain) NSMenuItem * deleteSimMenuItem;
//@property (retain) NSMenuItem * connectViaAddressMenuItem;
//@property (retain) NSMenuItem * forgetDeviceSeparatorMenuItem;
//@property (retain) NSMenuItem * forgetDeviceMenuItem;
//@property (retain) NSMenu * addDeviceMenu;
//@property (retain) NSMutableSet * devices;
//@property (retain,nonatomic) NSArray * devicesOutlineSelectionIndexPaths;
//@property (copy,nonatomic) NSString * filterString;
//@property (retain) NSMutableDictionary * wirelessEnablingFutures;
//@property char promptingForDelete;
//@property char restoringExpansionState;
//@property (readonly) NSMutableDictionary * headerItems;
//@property (readonly) NSMutableDictionary * deviceItems;
//@property (readonly) NSMutableDictionary * indexPathForDeviceIdentifier;
//@property (retain) NSObject<DVTDeviceAction> * forgetDeviceAction;
//@property (nonatomic) long long mode;
//@property NSObject<DVTDevicesListViewControllerDelegate> * delegate;
//@property (copy) NSString * selectedDeviceIdentifier;
//@property (readonly) DVTDevice * selectedDevice;
//@property (readonly) unsigned long long hash;
//@property (readonly) Class superclass;
//@property (readonly,copy) NSString * description;
//@property (readonly,copy) NSString * debugDescription;
//+ (id)_deviceActionsToSkip;
//- (id)initWithNibName:(id)v1 bundle:(id)v2;
//- (id)initWithCoder:(id)v1;
//- (void)primitiveInvalidate;
//- (void)viewDidLoad;
//- (void)viewWillAppear;
//- (void)viewDidAppear;
//- (void)viewWillDisappear;
//- (void)_installContentViewYConstraints;
//- (void)scopeButtonClicked:(id)v1;
//- (id)_selectedDeviceDefaultsKey;
//- (void)addDeviceButtonClicked:(id)v1;
//- (void)addSimulator:(id)v1;
//- (void)addDevice:(id)v1;
//- (void)copyDeviceName:(id)v1;
//- (void)copyDeviceIdentifier:(id)v1;
//- (void)renameDevice:(id)v1;
//- (void)connectViaAddress:(id)v1;
//- (void)showProvisioningProfiles:(id)v1;
//- (char)validateMenuItem:(id)v1;
//- (void)deleteSimulator:(id)v1;
//- (void)_deleteSimulator:(id)v1;
//- (void)_deleteSimulators:(id)v1;
//- (void)_deleteSimulator:(id)v1 prompt:(char)v2;
//- (id)_selectedDevicesFromMenuItem:(id)v1;
//- (void)performDeviceAction:(id)v1;
//- (void)keyDown:(id)v1;
//- (void)deleteBackward:(id)v1;
//- (void)noAction:(id)v1;
//- (void)outlineViewItemDidCollapse:(id)v1;
//- (void)outlineViewItemDidExpand:(id)v1;
//- (char)outlineView:(id)v1 shouldSelectItem:(id)v2;
//- (char)outlineView:(id)v1 isGroupItem:(id)v2;
//- (id)outlineView:(id)v1 viewForTableColumn:(id)v2 item:(id)v3;
//- (id)outlineView:(id)v1 tintColorForItem:(id)v2;
//- (id)_purportedSelectedDeviceWithSelectionIndexPaths:(id)v1;
//- (id)tableView:(id)v1 rowActionsForRow:(long long)v2 edge:(long long)v3;
//- (void)_selectDeviceWithIdentifier:(id)v1;
//- (id)_keyForCollapsedStatePersistence;
//- (void)_persistOutlineViewExpansionState;
//- (void)_restoreOutlineViewExpansionState;
//- (void)menuWillOpen:(id)v1;
//- (char)includesDevice:(id)v1;
//- (void)selectDevice:(id)v1;
//- (id)_contextuallySelectedDevices;
//- (id)_contextuallySelectedDevice;
//- (id)_simulatorLocator;
//- (void)_startObservingDeviceAvailabilty;
//- (void)_stopObservingDeviceAvailabilty;
//- (void)_updateDevices;
//- (id)_headerItemForName:(id)v1;
//- (id)_deviceItemForDevice:(id)v1;
//- (id)_deviceListSortDescriptors;
//- (void)_updateDeviceDisplayWithDelay:(char)v1;
//- (id)_categoryDescriptionForDevice:(id)v1;
//- (void)_restoreDeviceSelection;
//- (void)_addDevices:(id)v1;
//- (void)_removeDevices:(id)v1;
//- (id)_deviceWithIdentifier:(id)v1;
//- (void).cxx_destruct;
//@end
//
//
///*****************************************************************/
//
//@interface DVTTutorialNavigationController : NSViewController {
//    char _isOnLastPage;
//    NSString * _nextButtonTitle;
//    void (^ /* unknown block signature */)(void) _additionalAction;
//    NSButton * _nextButton;
//    NSButton * _previousButton;
//    NSButton * _cancelButton;
//    NSView * _navigationContainerView;
//    DVTTutorialController * _tutorialController;
//    NSButton * _currentPageNavigationButton;
//}
//@property NSButton * nextButton;
//@property NSButton * previousButton;
//@property NSButton * cancelButton;
//@property NSView * navigationContainerView;
//@property DVTTutorialController * tutorialController;
//@property (retain,nonatomic) NSButton * currentPageNavigationButton;
//- (void)nextAction:(id)v1;
//- (void)previousAction:(id)v1;
//- (void)cancelAction:(id)v1;
//- (void)setPageControllerIsOnLastPage:(char)v1;
//- (void)setPageControllerIsOnFirstPage:(char)v1;
//- (void)setNextButtonEnabled:(char)v1;
//- (void)setNextButton:(id)v1 additionalAction:(void (^ /* unknown block signature */)(void))v2;
//- (void).cxx_destruct;
//@end
//
//
///*****************************************************************/
//
//@interface DVTDeviceAddressSheetController : DVTViewController {
//    char _cancelled;
//    NSString * _prompt;
//    DVTDevice * _device;
//    NSTextField * _promptLabel;
//    NSProgressIndicator * _addressProgressIndicator;
//    NSTextField * _addressTextField;
//    NSButton * _connectButton;
//    NSTextField * _errorLabel;
//    NSObject<DVTDeviceAction> * _connectAction;
//}
//@property (retain) NSTextField * promptLabel;
//@property (retain) NSProgressIndicator * addressProgressIndicator;
//@property (retain) NSTextField * addressTextField;
//@property (retain) NSButton * connectButton;
//@property (retain) NSTextField * errorLabel;
//@property (retain) NSObject<DVTDeviceAction> * connectAction;
//@property char cancelled;
//@property (retain) NSString * prompt;
//@property (retain) DVTDevice * device;
//- (void)viewWillAppear;
//- (void)cancel:(id)v1;
//- (void)connect:(id)v1;
//- (void).cxx_destruct;
//@end
//
//
///*****************************************************************/
//
//
//
///*****************************************************************/
//
@interface DVTOnboardingPage : NSViewController {
    NSSegmentedControl * deviceSourceSegmentedControl;
    NSLayoutConstraint * topConstraint;
    DVTOnboardingTutorialController * _tutorialController;
}
@property (retain) DVTOnboardingTutorialController * tutorialController;
- (void)viewWillAppear;
- (char)readyForNextPage;
- (char)willNavigateToNextPage;
- (void)selectConnectedVsRemote:(id)v1;
@end

@interface DVTOnboardingTutorialSetupDevice : DVTOnboardingPage
- (void)viewDidAppear;
- (char)readyForNextPage;
- (char)willNavigateToNextPage;
@end
//
//
///*****************************************************************/
//
//@interface DVTDevicesListHeaderItem : NSObject<DVTDevicesListItem> {
//    NSString * _name;
//    NSMutableArray * _children;
//    DVTDevice * _device;
//}
//@property (retain) NSString * name;
//@property (readonly,getter=isEditable) char editable;
//@property (readonly,getter=isGroupItem) char groupItem;
//@property (retain) DVTDevice * device;
//@property (readonly,getter=isLeaf) char leaf;
//@property (readonly) NSMutableArray * children;
//@property (readonly) unsigned long long hash;
//@property (readonly) Class superclass;
//@property (readonly,copy) NSString * description;
//@property (readonly,copy) NSString * debugDescription;
//+ (id)headerItemWithName:(id)v1;
//- (id)initWithName:(id)v1;
//- (void).cxx_destruct;
//@end
//
//
///*****************************************************************/
//
//@interface DVTDevicesListDeviceItem : NSObject<DVTDevicesListItem> {
//    DVTDevice * _device;
//}
//@property (retain) NSString * name;
//@property (readonly,getter=isEditable) char editable;
//@property (readonly,getter=isGroupItem) char groupItem;
//@property (retain) DVTDevice * device;
//@property (readonly,getter=isLeaf) char leaf;
//@property (readonly) NSMutableArray * children;
//@property (readonly) unsigned long long hash;
//@property (readonly) Class superclass;
//@property (readonly,copy) NSString * description;
//@property (readonly,copy) NSString * debugDescription;
//+ (id)deviceItemWithDevice:(id)v1;
//+ (id)keyPathsForValuesAffectingName;
//+ (id)keyPathsForValuesAffectingEditable;
//- (id)initWithDevice:(id)v1;
//- (void)setChildren:(id)v1;
//- (void).cxx_destruct;
//@end
//
//
///*****************************************************************/
//
//@interface DVTDevicesWindowSplitView : NSSplitView
//@end
//
//
///*****************************************************************/
//
//@interface DVTOnboardingTutorialNoDevices : DVTOnboardingPage
//- (char)readyForNextPage;
//@end
//
//
///*****************************************************************/
//
//@interface DVTDeviceCategoryToTextColorValueTransformer : NSValueTransformer
//+ (Class)transformedValueClass;
//+ (char)allowsReverseTransformation;
//- (id)transformedValue:(id)v1;
//@end
//
//
///*****************************************************************/
//
//@interface DVTDeviceLogsSheetController : DVTPagingSheetWindowController {
//    Class _deviceLogsViewControllerClass;
//    DVTDevice * _device;
//    DVTReplacementView * _replacementView;
//}
//@property (retain) DVTReplacementView * replacementView;
//- (id)initWithDevice:(id)v1 deviceLogsViewControllerClass:(Class)v2;
//- (void)windowDidLoad;
//- (void)endSheet;
//- (void)done:(id)v1;
//- (void)primitiveInvalidate;
//- (void).cxx_destruct;
//@end
//
//
///*****************************************************************/
//
//@interface DVTDevicesListOutlineView : NSOutlineView
//- (char)validateProposedFirstResponder:(id)v1 forEvent:(id)v2;
//@end
//
//
///*****************************************************************/
//
@interface DVTOnboardingTutorialSuccess : DVTOnboardingPage
- (void)setupAnotherAction:(id)v1;
- (void)viewDidAppear;
@end
//
//
///*****************************************************************/
//
//@interface DVTDevicesListTableCellView : NSTableCellView {
//    NSProgressIndicator * _busyIndicator;
//}
//@property (retain) NSProgressIndicator * busyIndicator;
//- (void)setBackgroundStyle:(long long)v1;
//- (void)viewDidChangeEffectiveAppearance;
//- (void)_updateBusyIndicator;
//- (void).cxx_destruct;
//@end
//
//
///*****************************************************************/
//
//@interface DVTDevicesWindowContentAreaViewController : DVTViewController {
//    DVTReplacementView * _replacementView;
//    DVTBorderedView * _borderedView;
//}
//@property (retain) DVTReplacementView * replacementView;
//@property (retain) DVTBorderedView * borderedView;
//- (void)viewDidLoad;
//- (void)primitiveInvalidate;
//- (void).cxx_destruct;
//@end
//
//
///*****************************************************************/
//
//@interface DVTDeviceContentSplitViewController : NSSplitViewController {
//    DVTObservingToken * _deviceWindowCategoryObserer;
//    DVTDeviceConsoleViewController * _consoleViewController;
//    NSSplitViewItem * _consoleSplitViewItem;
//    DVTDevice * _device;
//    DVTEmptyContentPlaceholder * _emptyContentView;
//}
//@property (retain) DVTEmptyContentPlaceholder * emptyContentView;
//@property (readonly) DVTDevicesWindowContentAreaViewController * contentAreaViewController;
//@property (readonly,nonatomic) DVTDeviceConsoleViewController * consoleViewController;
//@property (readonly,getter=isConsoleViewControllerLoaded) char consoleViewControllerLoaded;
//@property (readonly,nonatomic) NSSplitViewItem * consoleSplitViewItem;
//@property (retain,nonatomic) DVTDevice * device;
//- (void)dealloc;
//- (char)splitView:(id)v1 shouldHideDividerAtIndex:(long long)v2;
//- (struct CGRect)splitView:(id)v1 effectiveRect:(struct CGRect)v2 forDrawnRect:(struct CGRect)v3 ofDividerAtIndex:(long long)v4;
//- (void)_animateDividerToPosition:(double)v1 consoleViewController:(id)v2 completionHandler:(void (^ /* unknown block signature */)(void))v3;
//- (void)collapseConsole:(id)v1;
//- (void)setConsoleHeight:(double)v1 sender:(id)v2;
//- (void)_addConsoleSplitViewItemWithClass:(Class)v1 device:(id)v2;
//- (void)_removeConsoleSplitViewItem;
//- (char)_shouldShowConsoleForWindowCategory:(int)v1;
//- (void)_updateDetailsWithDevice:(id)v1;
//- (void)_showEmptySelectionView;
//- (void)_hideEmptySelectionView;
//- (id)_detailViewControllerInfoDictionaryForDevice:(id)v1;
//- (void).cxx_destruct;
//@end
//
//
///*****************************************************************/
//
//@interface DVTOnboardingDeviceTableCellView : NSTableCellView {
//    NSTextField * _reasonTextField;
//    NSImageView * _deviceIsSetupImage;
//}
//@property NSTextField * reasonTextField;
//@property NSImageView * deviceIsSetupImage;
//- (void).cxx_destruct;
//@end
//
//
///*****************************************************************/
//
@interface DVTOnboardingTutorialChooseDevice : DVTOnboardingPage<AKAppleIDAuthenticationDelegate,NSTableViewDataSource> {
    NSPredicate * _predicate;
    NSTableView * _tableView;
    //AKAppleIDAuthenticationController * _appleIDController;
}
@property NSTableView * tableView;
//@property (retain) AKAppleIDAuthenticationController * appleIDController;
//@property (readonly) unsigned long long hash;
@property (readonly) Class superclass;
@property (readonly,copy) NSString * description;
@property (readonly,copy) NSString * debugDescription;
- (void)viewDidAppear;
- (void)setTutorialController:(id)v1;
- (char)readyForNextPage;
- (char)willNavigateToNextPage;
- (void)viewWillDisappear;
- (id)_orderedDevices;
- (id)whyIsDeviceNotAvailable:(id)v1;
- (id)accountCredentialsForResults:(id)v1;
- (void)_addAccountWithResults:(id)v1;
- (long long)numberOfRowsInTableView:(id)v1;
- (id)tableView:(id)v1 viewForTableColumn:(id)v2 row:(long long)v3;
- (void)tableViewSelectionDidChange:(id)v1;
- (char)authenticationController:(id)v1 shouldContinueWithAuthenticationResults:(id)v2 error:(id)v3 forContext:(id)v4;
@end
//
//
///*****************************************************************/

@interface DVTTutorialController : NSObject<DVTInvalidation,NSPageControllerDelegate> {
	//void (^ /* unknown block signature */)(void) _cancelHandler;
	DVTPageController * _pageController;
	NSButton * _currentPageNavigationButton;
	NSStoryboard * _storyboard;
	//DVTTutorialNavigationController * _navigationController;
}
@property (retain) NSStoryboard * storyboard;
//@property (retain) DVTTutorialNavigationController * navigationController;
//@property (copy,nonatomic) void (^ /* unknown block signature */)(void) cancelHandler;
@property (readonly) NSView * tutorialView;
@property (retain) DVTPageController * pageController;
@property (retain,nonatomic) NSButton * currentPageNavigationButton;
//@property (readonly,nonatomic,getter=isValid) char valid;
//@property (readonly) DVTStackBacktrace * invalidationBacktrace;
//@property (retain) DVTStackBacktrace * creationBacktrace;
//@property (readonly) unsigned long long hash;
@property (readonly) Class superclass;
@property (readonly,copy) NSString * description;
@property (readonly,copy) NSString * debugDescription;
+ (void)initialize;
+ (id)linkColor;
- (void)nextPage;
- (void)previousPage;
- (void)showViewControllerWithIdentifier:(id)v1;
- (void)cancel;
- (id)identifiersForPagesInStoryboard;
- (id)identifierForPageController;
- (void)reloadIdentifiers:(char)v1;
- (void)validateCurrentPage;
- (char)currentPageShouldEnableNextButton;
- (id)init;
- (id)pageController:(id)v1 identifierForObject:(id)v2;
- (id)pageController:(id)v1 viewControllerForIdentifier:(id)v2;
- (void)_ensureNavigationIsOnTop;
- (void)pageControllerDidEndLiveTransition:(id)v1;
- (void)_updateNavigationButtons;
- (void)pageController:(id)v1 didTransitionToObject:(id)v2;
- (void)pageController:(id)v1 prepareViewController:(id)v2 withObject:(id)v3;
- (void)setNextButton:(id)v1 additionalAction:(void (^ /* unknown block signature */)(void))v2;
- (void)primitiveInvalidate;
@end

//
@interface DVTOnboardingTutorialController : DVTTutorialController {
    NSArray * _developerTeams;
    unsigned long long _startKey;
    DVTDevice * _selectedDeviceForSetup;
    //DVTDeveloperAccount * _accountForSetup;
}
@property (retain,nonatomic) DVTDevice * selectedDeviceForSetup;
//@property (retain,nonatomic) DVTDeveloperAccount * accountForSetup;
@property (readonly,nonatomic) char focusOnConnected;
- (id)init;
- (id)devices;
- (id)_identifiersForConnectedPages;
- (id)_identifiersForRemotePages;
- (id)identifiersForPagesInStoryboard;
- (char)currentPageShouldEnableNextButton;
- (void)nextPage;
- (void)restartTutorial:(unsigned long long)v1;
- (id)identifierForPageController;
- (DVTOnboardingPage*)pageController:(DVTPageController*)v1 viewControllerForIdentifier:(NSString*)v2;
- (id)_devicesForPlatforms:(id)v1;
- (id)developerTeamsForAccount;
@end
//
//
///*****************************************************************/
//
//@interface DVTClassForFindingDVTDeviceKit : NSObject
//@end
//
//
///*****************************************************************/
//
//@interface DVTDeviceSummaryRootsViewController : DVTViewController<DVTTableViewDelegate,NSTableViewDataSource,NSOpenSavePanelDelegate> {
//    NSArray * _installedRoots;
//    DVTObservingToken * _rootsObservingToken;
//    char _disableDeviceTriggeredUpdates;
//    DVTDevice * _device;
//    DVTTableView * _rootsTableView;
//    DVTBorderedView * _rootsTableFooterView;
//    DVTGradientImagePopUpButton * _gearRootButton;
//    DVTGradientImageButton * _installRootButton;
//    DVTGradientImageButton * _uninstallRootButton;
//}
//@property (retain) DVTTableView * rootsTableView;
//@property (retain) DVTBorderedView * rootsTableFooterView;
//@property (retain) DVTGradientImagePopUpButton * gearRootButton;
//@property (retain) DVTGradientImageButton * installRootButton;
//@property (retain) DVTGradientImageButton * uninstallRootButton;
//@property (readonly,nonatomic) DVTDevice * device;
//@property (readonly) unsigned long long hash;
//@property (readonly) Class superclass;
//@property (readonly,copy) NSString * description;
//@property (readonly,copy) NSString * debugDescription;
//- (id)initWithDevice:(id)v1;
//- (void)primitiveInvalidate;
//- (void)loadView;
//- (void)tableViewSelectionDidChange:(id)v1;
//- (long long)numberOfRowsInTableView:(id)v1;
//- (id)tableView:(id)v1 objectValueForTableColumn:(id)v2 row:(long long)v3;
//- (id)tableView:(id)v1 viewForTableColumn:(id)v2 row:(long long)v3;
//- (id)supportedRootArchiveUTIs;
//- (unsigned long long)tableView:(id)v1 validateDrop:(id)v2 proposedRow:(long long)v3 proposedDropOperation:(unsigned long long)v4;
//- (char)tableView:(id)v1 acceptDrop:(id)v2 row:(long long)v3 dropOperation:(unsigned long long)v4;
//- (void)installRoot:(id)v1;
//- (void)installRootsAtPaths:(id)v1;
//- (void)uninstallRoots:(id)v1;
//- (void)copyRootUUID:(id)v1;
//- (void)_updateRootsTableAsynchronouslyFromDevice;
//- (void)_refreshRootsTable:(id)v1;
//- (void).cxx_destruct;
//@end
//
//
///*****************************************************************/
//
//@interface DVTDeviceProvisioningProfilesSheetController : DVTPagingSheetWindowController {
//    DVTDevice * _device;
//    DVTTableView * _profileTable;
//    DVTGradientImageButton * _addButton;
//    DVTGradientImageButton * _removeButton;
//    DVTBorderedView * _tableBorder;
//    DVTBorderedView * _buttonBorder;
//    NSArrayController * _profilesArrayController;
//    NSArray * _provisioningProfiles;
//}
//@property (readonly) DVTDevice * device;
//@property (retain) DVTTableView * profileTable;
//@property (retain) DVTGradientImageButton * addButton;
//@property (retain) DVTGradientImageButton * removeButton;
//@property (retain) DVTBorderedView * tableBorder;
//@property (retain) DVTBorderedView * buttonBorder;
//@property (retain) NSArrayController * profilesArrayController;
//@property (retain) NSArray * provisioningProfiles;
//- (id)initWithDevice:(id)v1;
//- (void)windowDidLoad;
//- (char)validateMenuItem:(id)v1;
//- (void)done:(id)v1;
//- (void)selectAll:(id)v1;
//- (void)addProfile:(id)v1;
//- (void)delete:(id)v1;
//- (void)removeProfiles:(id)v1;
//- (void)exportProfiles:(id)v1;
//- (void).cxx_destruct;
//@end
//
//
///*****************************************************************/
//
//@interface DVTDeviceSummaryClipView : NSClipView
//- (char)isFlipped;
//@end
//
//
///*****************************************************************/
//
//@interface DVTDeviceSummaryViewController : DVTViewController<DVTDevicesWindowDetailViewController,NSTableViewDataSource,DVTTableViewDelegate> {
//    NSArray * _additionalSliceControllers;
//    NSMutableArray * _deviceObservationTokens;
//    NSMutableArray * _proxiedDevicesObservingTokens;
//    NSObject<NSObject> * _devicePrepErrorsObserver;
//    char _showViolator;
//    char _updateViolatorPending;
//    char _rebuildStackViewPending;
//    char _addedConstraints;
//    DVTDevice * _device;
//    NSArray * _additionalSliceViewControllerClasses;
//    Class _deviceLogsViewControllerClass;
//    DVTDeviceSummaryAboutViewController * _aboutViewController;
//    NSTextField * _violatorTitleLabel;
//    NSTextField * _violatorDetailLabel;
//    NSTextField * _proxiedDeviceLabel;
//    DVTTableView * _proxiedDeviceTableView;
//    NSScrollView * _proxiedDeviceScrollView;
//    DVTBorderedView * _proxiedDeviceScrollViewSeparator;
//    DVTBorderedView * _proxiedDevicesFooter;
//    NSTextField * _proxiedDevicesNotSupportedLabel;
//    NSStackView * _stackView;
//    DVTBorderedView * _violatorSlice;
//    NSView * _proxiedDeviceSlice;
//    NSImageView * _violatorImageView;
//    DVTBorderedView * _tableHeaderLine;
//    NSButton * _takeScreenshotButton;
//    DVTGradientImageButton * _addPairedDeviceButton;
//    DVTGradientImageButton * _deletePairedDeviceButton;
//    DVTDeviceErrorsAndWarningsController * _errorsController;
//    DVTDeviceSummaryAppsViewController * _appsViewController;
//    DVTDeviceSummaryRootsViewController * _rootsViewController;
//    NSString * _violatorMessage;
//    NSString * _violatorDescription;
//    NSArray * _deviceInfo;
//    NSMutableDictionary * _proxyInfo;
//}
//@property (retain) DVTDeviceSummaryAboutViewController * aboutViewController;
//@property (retain) NSTextField * violatorTitleLabel;
//@property (retain) NSTextField * violatorDetailLabel;
//@property (retain) NSTextField * proxiedDeviceLabel;
//@property (retain) DVTTableView * proxiedDeviceTableView;
//@property (retain) NSScrollView * proxiedDeviceScrollView;
//@property (retain) DVTBorderedView * proxiedDeviceScrollViewSeparator;
//@property (retain) DVTBorderedView * proxiedDevicesFooter;
//@property (retain) NSTextField * proxiedDevicesNotSupportedLabel;
//@property (retain) NSStackView * stackView;
//@property (retain) DVTBorderedView * violatorSlice;
//@property (retain) NSView * proxiedDeviceSlice;
//@property (retain) NSImageView * violatorImageView;
//@property (retain) DVTBorderedView * tableHeaderLine;
//@property (retain) NSButton * takeScreenshotButton;
//@property (retain) DVTGradientImageButton * addPairedDeviceButton;
//@property (retain) DVTGradientImageButton * deletePairedDeviceButton;
//@property (retain) DVTDeviceErrorsAndWarningsController * errorsController;
//@property (retain) DVTDeviceSummaryAppsViewController * appsViewController;
//@property (retain) DVTDeviceSummaryRootsViewController * rootsViewController;
//@property char showViolator;
//@property char updateViolatorPending;
//@property (retain) NSString * violatorMessage;
//@property (retain) NSString * violatorDescription;
//@property char rebuildStackViewPending;
//@property (readonly) NSSet * proxiedDevices;
//@property (copy) NSArray * deviceInfo;
//@property (retain) NSMutableDictionary * proxyInfo;
//@property char addedConstraints;
//@property (readonly) char showApplicationList;
//@property (readonly) char showInstalledRootList;
//@property (readonly) char showProxiedDeviceSlice;
//@property (readonly) NSArray * additionalSliceViewControllerClasses;
//@property (readonly) Class deviceLogsViewControllerClass;
//@property (retain,nonatomic) DVTDevice * device;
//@property (readonly,nonatomic,getter=isValid) char valid;
//@property (readonly) DVTStackBacktrace * invalidationBacktrace;
//@property (retain) DVTStackBacktrace * creationBacktrace;
//@property (readonly) unsigned long long hash;
//@property (readonly) Class superclass;
//@property (readonly,copy) NSString * description;
//@property (readonly,copy) NSString * debugDescription;
//+ (id)defaultViewNibName;
//+ (id)defaultViewNibBundle;
//+ (id)keyPathsForValuesAffectingShowProxiedDeviceSlice;
//+ (id)keyPathsForValuesAffectingProxiedDevices;
//+ (id)keyPathsForValuesAffectingActiveProxiedDevice;
//- (void)primitiveInvalidate;
//- (void)loadView;
//- (void)viewDidInstall;
//- (void)viewWillAppear;
//- (void)updateViewConstraints;
//- (void)_setPreferredMaxLayoutWidthForTextField:(id)v1;
//- (void)viewDidLayout;
//- (char)_disableProxiedDeviceSlice;
//- (id)activeProxiedDevice;
//- (long long)numberOfRowsInTableView:(id)v1;
//- (id)tableView:(id)v1 objectValueForTableColumn:(id)v2 row:(long long)v3;
//- (id)tableView:(id)v1 viewForTableColumn:(id)v2 row:(long long)v3;
//- (char)tableView:(id)v1 shouldSelectRow:(long long)v2;
//- (void)tableViewSelectionDidChange:(id)v1;
//- (void)selectActivePairedDevice:(id)v1;
//- (void)addPairedDevice:(id)v1;
//- (void)deletePairedDevice:(id)v1;
//- (void)openConsole:(id)v1;
//- (char)panel:(id)v1 shouldEnableURL:(id)v2;
//- (void)stackViewNeedsUpdate;
//- (void)_rebuildStackView;
//- (id)_regenerateAdditionalSliceViews;
//- (void)violatorNeedsUpdate;
//- (void)_updateViolator;
//- (id)_proxiedDeviceSummaryForDeviceSummary:(id)v1;
//- (id)_proxiedDeviceIdentifierForRow:(long long)v1;
//- (id)_proxiedDeviceForIdentifier:(id)v1;
//- (void)_reloadProxiedDevices;
//- (id)_simulatorLocator;
//- (void).cxx_destruct;
//@end
//
//
///*****************************************************************/
//
//@interface DVTDeviceSummarySliceViewController : DVTViewController {
//    DVTDevice * _device;
//}
//@property (readonly) DVTDevice * device;
//- (id)initWithDevice:(id)v1;
//- (void).cxx_destruct;
//@end
//
//
///*****************************************************************/
//
//@interface DVTDeviceSummaryTableCellView : NSTableCellView {
//    NSButton * _radioButton;
//    NSLayoutConstraint * _radioButtonWidthConstraint;
//}
//@property (retain) NSButton * radioButton;
//@property (retain) NSLayoutConstraint * radioButtonWidthConstraint;
//- (void).cxx_destruct;
//@end
//
//
///*****************************************************************/
//
@interface DVTPageController : NSPageController {
    char _disableSwipeWithScrollWheel;
}
@property char disableSwipeWithScrollWheel;
- (void)scrollWheel:(id)v1;
@end
//
//
///*****************************************************************/
//

//
//
///*****************************************************************/
//
//@interface DVTDeviceSummaryAppsViewController : DVTViewController<DVTTableViewDelegate,NSTableViewDataSource,NSOpenSavePanelDelegate> {
//    NSArray * _appInfo;
//    DVTObservingToken * _appsObservingToken;
//    DVTDeviceSummaryAppContainerSheetController * _appContainerWindowController;
//    char _disableDeviceTriggeredUpdates;
//    DVTDevice<DVTDeviceApplicationInstaller> * _device;
//    DVTTableView * _appsTableView;
//    DVTBorderedView * _appsTableFooterView;
//    DVTGradientImageButton * _addAppButton;
//    DVTGradientImageButton * _deleteAppButton;
//    DVTGradientImagePopUpButton * _gearAppButton;
//    NSBox * _appsSectionSeparator;
//}
//@property (retain) DVTTableView * appsTableView;
//@property (retain) DVTBorderedView * appsTableFooterView;
//@property (retain) DVTGradientImageButton * addAppButton;
//@property (retain) DVTGradientImageButton * deleteAppButton;
//@property (retain) DVTGradientImagePopUpButton * gearAppButton;
//@property (retain) NSBox * appsSectionSeparator;
//@property (readonly,nonatomic) DVTDevice<DVTDeviceApplicationInstaller> * device;
//@property (readonly) unsigned long long hash;
//@property (readonly) Class superclass;
//@property (readonly,copy) NSString * description;
//@property (readonly,copy) NSString * debugDescription;
//- (id)initWithDevice:(id)v1;
//- (void)primitiveInvalidate;
//- (void)loadView;
//- (void)tableViewSelectionDidChange:(id)v1;
//- (long long)numberOfRowsInTableView:(id)v1;
//- (id)tableView:(id)v1 objectValueForTableColumn:(id)v2 row:(long long)v3;
//- (id)tableView:(id)v1 viewForTableColumn:(id)v2 row:(long long)v3;
//- (unsigned long long)tableView:(id)v1 validateDrop:(id)v2 proposedRow:(long long)v3 proposedDropOperation:(unsigned long long)v4;
//- (char)tableView:(id)v1 acceptDrop:(id)v2 row:(long long)v3 dropOperation:(unsigned long long)v4;
//- (void)addApplication:(id)v1;
//- (void)installApplications:(id)v1;
//- (void)deleteApplications:(id)v1;
//- (void)showContainer:(id)v1;
//- (void)downloadContainer:(id)v1;
//- (void)replaceContainer:(id)v1;
//- (void)_updateAppsTableFromDevice;
//- (void)_refreshAppsTable;
//- (void).cxx_destruct;
//@end
//
//
///*****************************************************************/
//
//@interface DVTDeviceErrorsAndWarningsController : DVTViewController<DVTTableViewDelegate,NSTableViewDataSource> {
//    NSMutableArray * _content;
//    NSSet * _errorSet;
//    NSSet * _warningSet;
//    NSObject<NSObject> * _deviceObserver;
//    DVTTableView * _tableView;
//    NSObject<DVTPreparableDevice> * _device;
//}
//@property (retain,nonatomic) NSObject<DVTPreparableDevice> * device;
//@property DVTTableView * tableView;
//@property (readonly) unsigned long long hash;
//@property (readonly) Class superclass;
//@property (readonly,copy) NSString * description;
//@property (readonly,copy) NSString * debugDescription;
//- (id)initWithDevice:(id)v1;
//- (void)primitiveInvalidate;
//- (void)loadView;
//- (void)showError:(id)v1;
//- (void)buildErrorList;
//- (void)copy:(id)v1;
//- (long long)numberOfRowsInTableView:(id)v1;
//- (id)tableView:(id)v1 viewForTableColumn:(id)v2 row:(long long)v3;
//- (void).cxx_destruct;
//@end
//
//
///*****************************************************************/
//
//@interface DVTErrorsAndWarningsTableCellView : NSTableCellView {
//    NSTextField * _detailTextField;
//}
//@property NSTextField * detailTextField;
//@end
//
//
///*****************************************************************/
//
//@interface DVTDeviceSummaryAboutViewController : DVTViewController {
//    char _stackViewsComplete;
//    DVTDevice * _device;
//    Class _deviceLogsViewControllerClass;
//    NSView * _gridViewPlaceholder;
//    NSTextField * _osVersionTextField;
//    NSTextField * _modelTextField;
//    NSButton * _showAsDestinationsButton;
//    NSTextField * _capacityTextField;
//    NSButton * _openSimulatorButton;
//    NSTextField * _serialNumberTextField;
//    NSButton * _connectWiFiButton;
//    NSButton * _openConsoleButton;
//    NSImageView * _image;
//    NSView * _identifierContainerView;
//    NSView * _buttonContainerView;
//    NSButton * _takeScreenshotButton;
//    NSButton * _viewLogsButton;
//    NSView * _widthAdjustmentView1;
//    NSView * _widthAdjustmentView2;
//    NSStackView * _leftStackView;
//    NSStackView * _rightStackView;
//    NSObject<DVTDeviceAction> * _networkAccessAction;
//    NSAppleScript * _openConsoleScript;
//}
//@property (retain) NSView * gridViewPlaceholder;
//@property (retain) NSTextField * osVersionTextField;
//@property (retain) NSTextField * modelTextField;
//@property (retain) NSButton * showAsDestinationsButton;
//@property (retain) NSTextField * capacityTextField;
//@property (retain) NSButton * openSimulatorButton;
//@property (retain) NSTextField * serialNumberTextField;
//@property (retain) NSButton * connectWiFiButton;
//@property (retain) NSButton * openConsoleButton;
//@property (retain) NSImageView * image;
//@property (retain) NSView * identifierContainerView;
//@property (retain) NSView * buttonContainerView;
//@property (retain) NSButton * takeScreenshotButton;
//@property (retain) NSButton * viewLogsButton;
//@property (retain) NSView * widthAdjustmentView1;
//@property (retain) NSView * widthAdjustmentView2;
//@property (retain) NSStackView * leftStackView;
//@property (retain) NSStackView * rightStackView;
//@property char stackViewsComplete;
//@property (retain) NSObject<DVTDeviceAction> * networkAccessAction;
//@property (readonly) char hideConnectWiFiButton;
//@property (readonly) char enableConnectWiFiButton;
//@property (nonatomic) long long wifiConnectionEnabled;
//@property (readonly) NSString * connectWiFiButtonTooltip;
//@property (readonly) char enableScreenshots;
//@property (readonly) char enableOpenConsole;
//@property (retain,nonatomic) NSAppleScript * openConsoleScript;
//@property (retain,nonatomic) DVTDevice * device;
//@property (retain) Class deviceLogsViewControllerClass;
//+ (id)keyPathsForValuesAffectingHideConnectWiFiButton;
//+ (id)keyPathsForValuesAffectingEnableConnectWiFiButton;
//+ (id)keyPathsForValuesAffectingConnectWiFiButtonTooltip;
//+ (id)keyPathsForValuesAffectingEnableScreenshots;
//+ (id)keyPathsForValuesAffectingEnableOpenConsole;
//+ (id)keyPathsForValuesAffectingWifiConnectionEnabled;
//- (id)initWithCoder:(id)v1;
//- (id)initWithNibName:(id)v1 bundle:(id)v2;
//- (void)viewDidLoad;
//- (char)enableViewDeviceLogs;
//- (void)_performAction:(id)v1 onDevice:(id)v2 completionHandler:(void (^ /* unknown block signature */)(void))v3;
//- (void)viewLogs:(id)v1;
//- (void)launchSimulator:(id)v1;
//- (void)takeScreenshot:(id)v1;
//- (void)openConsole:(id)v1;
//- (void)_buildStackViews;
//- (void)_completeStackViews:(id)v1;
//- (void).cxx_destruct;
//@end
//
//
///*****************************************************************/
//
//@interface DVTDeviceSummaryAppContainerSheetController : DVTPagingSheetWindowController<NSOutlineViewDataSource,NSOutlineViewDelegate> {
//    NSArray * _containerItemDictionaries;
//    NSObject<DVTDeviceApplication_KitSupport> * _application;
//    DVTOutlineView * _containerOutline;
//}
//@property (retain) DVTOutlineView * containerOutline;
//@property (readonly) NSObject<DVTDeviceApplication_KitSupport> * application;
//@property (readonly) unsigned long long hash;
//@property (readonly) Class superclass;
//@property (readonly,copy) NSString * description;
//@property (readonly,copy) NSString * debugDescription;
//+ (unsigned long long)assertionBehaviorForKeyValueObservationsAtEndOfEvent;
//- (id)initWithApplication:(id)v1;
//- (void)primitiveInvalidate;
//- (void)done:(id)v1;
//- (id)outlineView:(id)v1 child:(long long)v2 ofItem:(id)v3;
//- (char)outlineView:(id)v1 isItemExpandable:(id)v2;
//- (char)outlineView:(id)v1 shouldEditTableColumn:(id)v2 item:(id)v3;
//- (char)outlineView:(id)v1 shouldSelectItem:(id)v2;
//- (long long)outlineView:(id)v1 numberOfChildrenOfItem:(id)v2;
//- (id)outlineView:(id)v1 objectValueForTableColumn:(id)v2 byItem:(id)v3;
//- (void)outlineView:(id)v1 willDisplayCell:(id)v2 forTableColumn:(id)v3 item:(id)v4;
//- (id)_recursiveContainerItemDictionariesForItems:(id)v1;
//- (void)_updateContainerItemDictionaries;
//- (void).cxx_destruct;
//@end
//
//
///*****************************************************************/
//
//@interface _TtC12DVTDeviceKit33DVTOnboardingTutorialChooseRemote : DVTOnboardingPage<NSTableViewDataSource,NSTableViewDelegate,DVTFilterExpressionPresentationDelegate,DVTFilteredDataViewingContext,DVTFilteredDataSource> {
//    id tableView;
//    id loadingIndicator;
//    id filterField;
//    id providerName;
//    id defaultOSTrain;
//    id ColumnViewIdentifierDeviceType;
//    id ColumnViewIdentifierModel;
//    id ColumnViewIdentifierBuild;
//    id ColumnViewIdentifierTrain;
//    id ColumnViewIdentifierAvailability;
//    id ColumnViewIdentifierMatch;
//    id coreDeviceQueue;
//    id searchParameters;
//    id devices;
//    id selectedRemoteDevice;
//    id defaultFilterCompletionIdentifiers;
//    id usedFilterCompletionIdentifiers;
//    id availableFilterCompletionIdentifiers;
//    id filterFieldController;
//    id filteringQueue;
//    id filterProgress;
//    id filterFieldToolTip;
//    id filterFieldAccessibilityDescription;
//}
//@property (nonatomic,retain) NSTableView * tableView;
//@property (nonatomic,retain) NSProgressIndicator * loadingIndicator;
//@property (nonatomic,retain) DVTFilterTokenField * filterField;
//@property (nonatomic,retain) DVTOnboardingTutorialController * tutorialController;
//@property (nonatomic,retain) OS_dispatch_queue * filteringQueue;
//@property (nonatomic) long long filterProgress;
//@property (nonatomic,copy) NSString * filterFieldToolTip;
//@property (nonatomic,copy) NSString * filterFieldAccessibilityDescription;
//- (void)viewDidAppear;
//- (void)tableViewDoubleClicked:(id)v1;
//- (char)readyForNextPage;
//- (long long)numberOfRowsInTableView:(id)v1;
//- (id)tableView:(id)v1 viewForTableColumn:(id)v2 row:(long long)v3;
//- (void)tableView:(id)v1 sortDescriptorsDidChange:(id)v2;
//- (void)tableViewSelectionDidChange:(id)v1;
//- (void)filterSessionDidEnd:(id)v1;
//- (void)filterWithFilterSession:(id)v1;
//- (void)showMatches:(id)v1 added:(id)v2 removed:(id)v3;
//- (id)titleForFilterIdentifier:(id)v1;
//- (id)filterExpressionCompletionsForText:(id)v1 currentFilterExpression:(id)v2;
//- (id)relatedFilterExpressionsAffectingTypeIncludingExpression:(id)v1;
//- (id)filterExpressionForText:(id)v1 isComplete:(char)v2 currentFilterExpression:(id)v3;
//- (id)validFilterExpressionsForExpressions:(id)v1 currentFilterExpression:(id)v2;
//- (id)fieldDisplayStringForFilterExpression:(id)v1;
//- (id)menuDisplayStringForFilterExpression:(id)v1;
//- (id)editingStringForFilterExpression:(id)v1;
//- (id)initWithNibName:(id)v1 bundle:(id)v2;
//- (id)initWithCoder:(id)v1;
//- (void).cxx_destruct;
//@end
//
//
///*****************************************************************/
//
//@interface _TtC12DVTDeviceKit12SearchResult : NSObject {
//    id name;
//    id productType;
//    id deviceType;
//    id model;
//    id build;
//    id train;
//    id availability;
//    id match;
//}
//@property (nonatomic,readonly) NSString * name;
//@property (nonatomic,readonly) NSString * deviceType;
//@property (nonatomic,readonly) NSString * model;
//@property (nonatomic,readonly) NSString * build;
//@property (nonatomic,readonly) NSString * train;
//@property (nonatomic,readonly) long long availability;
//@property (nonatomic,readonly) NSString * match;
//- (id)init;
//- (void).cxx_destruct;
//@end
