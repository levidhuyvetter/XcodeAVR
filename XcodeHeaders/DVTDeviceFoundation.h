//struct _NSZone {
//};
//
//struct sockaddr {
//    unsigned char field_1;
//    unsigned char field_2;
//    char field_3[14];
//};
//
//
//
///*****************************************************************/
//
//@protocol NSObject
//@property (readonly) unsigned long long hash;
//@property (readonly) Class superclass;
//@property (readonly,copy) NSString * description;
//@property (readonly,copy) NSString * debugDescription;
//- (char)isEqual:(id)v1;
//- (Class)class;
//- (id)self;
//- (id)performSelector:(SEL)v1;
//- (id)performSelector:(SEL)v1 withObject:(id)v2;
//- (id)performSelector:(SEL)v1 withObject:(id)v2 withObject:(id)v3;
//- (char)isProxy;
//- (char)isKindOfClass:(Class)v1;
//- (char)isMemberOfClass:(Class)v1;
//- (char)conformsToProtocol:(id)v1;
//- (char)respondsToSelector:(SEL)v1;
//- (id)retain;
//- (oneway  void)release;
//- (id)autorelease;
//- (unsigned long long)retainCount;
//- (struct _NSZone *)zone;
//- (unsigned long long)hash;
//- (Class)superclass;
//- (id)description;
//
//@optional
//- (id)debugDescription;
//@end
//
//
///*****************************************************************/
//
//@protocol DVTNetworkDeviceServiceBrowserDelegate<NSObject>
//- (void)networkDeviceServiceBrowser:(id)v1 didFindServiceNamed:(id)v2 shouldResolve:(bool *)v3;
//- (void)networkDeviceServiceBrowser:(id)v1 didResolveIPAddress:(id)v2 deviceMACAddress:(id)v3 serviceName:(id)v4;
//- (void)networkDeviceServiceBrowser:(id)v1 didRemoveIPAddress:(id)v2 deviceMACAddress:(id)v3 serviceName:(id)v4;
//@end
//
//
///*****************************************************************/
//
//@protocol DVTDeviceToken<NSObject>
//@property (readonly,copy) NSString * deviceName;
//@property (readonly,copy) NSNumber * deviceECID;
//@property (readonly,copy) NSString * deviceIMEI;
//@property (readonly,copy) NSString * deviceClass;
//@property (readonly,copy) NSString * deviceActivationState;
//@property (readonly,copy) NSString * deviceType;
//@property (readonly,copy) NSString * deviceWiFiMAC;
//@property (readonly,copy) NSString * deviceBluetoothMAC;
//@property (readonly,copy) NSString * deviceCodename;
//@property (readonly,copy) NSString * productVersion;
//@property (readonly,copy) NSString * buildVersion;
//@property (readonly,copy) NSString * deviceSerialNumber;
//@property (readonly,copy) NSString * deviceDevelopmentStatus;
//@property (readonly,copy) NSString * deviceColorString;
//@property (readonly,copy) NSString * deviceEnclosureColorString;
//@property (readonly,copy) NSString * deviceArchitecture;
//@property (readonly,copy) NSNumber * deviceTotalCapacity;
//@property (readonly,copy) NSNumber * deviceAvailableCapacity;
//@property (readonly,copy) NSNumber * deviceBatteryCapacity;
//@property (readonly,copy) NSNumber * deviceChipID;
//@property (readonly,copy) NSString * deviceToolsType;
//@property (readonly,copy) NSNumber * deviceProductionSOC;
//@property (readonly) bool canBeWatchCompanion;
//@property (readonly) bool isPasscodeLocked;
//@property (readonly) bool deviceIsProduction;
//@property (readonly,copy) NSString * deviceIdentifier;
//@property (readonly,copy,nonatomic) NSString * bonjourServiceName;
//@property (readonly,copy,nonatomic) NSString * presumedRemoteAddress;
//- (id)hostPairingToken;
//- (bool)extendedPairWithError:(id *)v1 extendedInformationHandler:(void (^ /* unknown block signature */)(void))v2;
//- (id)deviceName;
//- (id)deviceECID;
//- (id)deviceIMEI;
//- (id)deviceClass;
//- (id)deviceActivationState;
//- (id)deviceType;
//- (id)deviceWiFiMAC;
//- (id)deviceBluetoothMAC;
//- (id)deviceCodename;
//- (id)productVersion;
//- (id)buildVersion;
//- (id)deviceSerialNumber;
//- (id)deviceDevelopmentStatus;
//- (id)deviceColorString;
//- (id)deviceEnclosureColorString;
//- (id)deviceArchitecture;
//- (id)deviceTotalCapacity;
//- (id)deviceAvailableCapacity;
//- (id)deviceBatteryCapacity;
//- (id)deviceChipID;
//- (id)deviceToolsType;
//- (id)deviceProductionSOC;
//- (bool)canBeWatchCompanion;
//- (bool)isPasscodeLocked;
//- (bool)deviceIsProduction;
//- (id)deviceIdentifier;
//- (id)bonjourServiceName;
//- (id)presumedRemoteAddress;
//@end
//
//
///*****************************************************************/
//
//@protocol DVTDeviceTokenAction<NSObject>
//@property (readonly,nonatomic) NSString * identifier;
//- (void)performForDeviceToken:(id)v1 completionHandler:(void (^ /* unknown block signature */)(void))v2;
//- (id)identifier;
//@end
//
//
///*****************************************************************/
//
//@protocol DVTDeviceActionProvider<NSObject>
//- (id)allDeviceActions;
//- (id)allDeviceTokenActions;
//@end
//
//
///*****************************************************************/
//
//@protocol DVTDeviceAction<NSObject>
//@property (readonly,nonatomic) NSString * identifier;
//- (id)confirmationMessageForDevice:(id)v1;
//- (id)titleForDevice:(id)v1;
//- (id)tooltipForDevice:(id)v1;
//- (bool)shouldShowActionForDevice:(id)v1;
//- (bool)shouldEnableActionForDevice:(id)v1;
//- (unsigned long long)currentStateForDevice:(id)v1;
//- (void)performForDevice:(id)v1 infoRequestHandler:(void (^ /* unknown block signature */)(void))v2 completionHandler:(void (^ /* unknown block signature */)(void))v3;
//- (void)cancelForDevice:(id)v1;
//- (id)identifier;
//@end
//
//
///*****************************************************************/
//
//@protocol NSCopying
//- (id)copyWithZone:(struct _NSZone *)v1;
//@end
//
//
///*****************************************************************/
//
//@protocol NSNetServiceBrowserDelegate<NSObject>
//
//@optional
//- (void)netServiceBrowserWillSearch:(id)v1;
//- (void)netServiceBrowserDidStopSearch:(id)v1;
//- (void)netServiceBrowser:(id)v1 didNotSearch:(id)v2;
//- (void)netServiceBrowser:(id)v1 didFindDomain:(id)v2 moreComing:(char)v3;
//- (void)netServiceBrowser:(id)v1 didFindService:(id)v2 moreComing:(char)v3;
//- (void)netServiceBrowser:(id)v1 didRemoveDomain:(id)v2 moreComing:(char)v3;
//- (void)netServiceBrowser:(id)v1 didRemoveService:(id)v2 moreComing:(char)v3;
//@end
//
//
///*****************************************************************/
//
//@protocol NSNetServiceDelegate<NSObject>
//
//@optional
//- (void)netServiceWillPublish:(id)v1;
//- (void)netServiceDidPublish:(id)v1;
//- (void)netService:(id)v1 didNotPublish:(id)v2;
//- (void)netServiceWillResolve:(id)v1;
//- (void)netServiceDidResolveAddress:(id)v1;
//- (void)netService:(id)v1 didNotResolve:(id)v2;
//- (void)netServiceDidStop:(id)v1;
//- (void)netService:(id)v1 didUpdateTXTRecordData:(id)v2;
//- (void)netService:(id)v1 didAcceptConnectionWithInputStream:(id)v2 outputStream:(id)v3;
//@end
//
//
///*****************************************************************/
//
//@protocol NSCoding
//- (void)encodeWithCoder:(id)v1;
//- (id)initWithCoder:(id)v1;
//@end
//
//
///*****************************************************************/
//
//@protocol NSSecureCoding<NSCoding>
//+ (char)supportsSecureCoding;
//@end
//
//
///*****************************************************************/
//
//@interface DVTNetworkDeviceMonitor : NSObject<DVTNetworkDeviceServiceBrowserDelegate> {
//    DVTObservingToken * _availableDevicesToken;
//    NSObject<OS_dispatch_queue> * _deviceObservingQueue;
//    NSMutableDictionary * _deviceObservingTokens;
//    NSMutableDictionary * _deviceScanTimerSources;
//    DVTDispatchLock * _deviceScanTimerSourcesLock;
//    DVTNetworkDeviceServiceBrowser * _networkDeviceServiceBrowser;
//    NSMutableDictionary * _deviceAddresses;
//    DVTDispatchLock * _deviceAddressesLock;
//    NSMutableDictionary * _activelyProxiedAddresses;
//    NSMutableDictionary * _activelyAdvertisedAddresses;
//    NSMutableDictionary * _activeDeviceBonjourProxies;
//    DVTDispatchLock * _activeDeviceBonjourLock;
//}
//@property (readonly) unsigned long long hash;
//@property (readonly) Class superclass;
//@property (readonly,copy) NSString * description;
//@property (readonly,copy) NSString * debugDescription;
//+ (void)initialize;
//+ (void)start;
//- (id)init;
//- (void)dealloc;
//- (void)networkDeviceServiceBrowser:(id)v1 didFindServiceNamed:(id)v2 shouldResolve:(bool *)v3;
//- (void)networkDeviceServiceBrowser:(id)v1 didResolveIPAddress:(id)v2 deviceMACAddress:(id)v3 serviceName:(id)v4;
//- (void)networkDeviceServiceBrowser:(id)v1 didRemoveIPAddress:(id)v2 deviceMACAddress:(id)v3 serviceName:(id)v4;
//- (void)_observeAvailableDevices;
//- (void)_observeDevice:(id)v1;
//- (void)_stopObservingDevice:(id)v1;
//- (void)_startMonitoringNetworkStatusOfDevice:(id)v1;
//- (bool)_deviceIsActivelyAdvertising:(id)v1;
//- (void)_scanForDevice:(id)v1 potentialAddresses:(id)v2;
//- (void)_attemptToConnectToDevice:(id)v1 promisingDeviceAddress:(id)v2;
//- (void)_stopMonitoringNetworkStatusOfDevice:(id)v1;
//- (void)_terminatePossiblyActiveProxyForDevice:(id)v1;
//- (id)_deviceForServiceName:(id)v1 type:(long long *)v2;
//- (id)_deviceForProxiedServiceName:(id)v1 devicesToSearch:(id)v2;
//- (id)_deviceForAdvertisedServiceName:(id)v1 devicesToSearch:(id)v2;
//- (id)_deviceForUnknownServiceName:(id)v1 devicesToSearch:(id)v2;
//- (void)_restoreSavedDeviceAddresses;
//- (void)_saveDeviceAddresses;
//- (void)_addPotentialDeviceAddress:(id)v1;
//- (id)_potentialDeviceAddressesForDevice:(id)v1;
//- (void).cxx_destruct;
//@end
//
//
///*****************************************************************/
//
//@interface DVTDNAEnableNetworkAccessAction : DVTAsyncDeviceAction {
//    DVTAsyncDeviceAction * _enableRemoteSSHAction;
//}
//- (id)init;
//- (id)_enableRemoteSSHAction;
//- (bool)_deviceVersionSupportsNBDD:(id)v1;
//- (bool)_deviceRequiresSRPForNetworkDevelopment:(id)v1;
//- (id)tooltipForDevice:(id)v1;
//- (id)confirmationMessageForDevice:(id)v1;
//- (bool)shouldShowActionForDevice:(id)v1;
//- (bool)shouldEnableActionForDevice:(id)v1;
//- (unsigned long long)currentStateForDevice:(id)v1;
//- (id)performForDevice:(id)v1 withArguments:(id)v2 infoRequestHandler:(void (^ /* unknown block signature */)(void))v3;
//- (void).cxx_destruct;
//@end
//
//
///*****************************************************************/
//
//@interface DVTDNAExtendedPairAction : DVTAsyncDeviceAction
//- (id)init;
//- (bool)shouldShowActionForDevice:(id)v1;
//- (id)performForDevice:(id)v1 withArguments:(id)v2 infoRequestHandler:(void (^ /* unknown block signature */)(void))v3;
//@end
//
//
///*****************************************************************/
//
//@interface DVTDNAConnectAction : DVTAsyncDeviceAction
//- (id)init;
//- (id)defaultValueForDevice:(id)v1 ofParameterWithKey:(id)v2;
//- (id)titleForDevice:(id)v1;
//- (bool)shouldShowActionForDevice:(id)v1;
//- (id)performForDevice:(id)v1 withArguments:(id)v2 infoRequestHandler:(void (^ /* unknown block signature */)(void))v3;
//@end
//
//
///*****************************************************************/
//
//@interface DVTDNAForgetAction : DVTAsyncDeviceAction
//- (id)init;
//- (bool)shouldShowActionForDevice:(id)v1;
//- (bool)shouldEnableActionForDevice:(id)v1;
//- (id)performForDevice:(id)v1 withArguments:(id)v2 infoRequestHandler:(void (^ /* unknown block signature */)(void))v3;
//@end
//
//
///*****************************************************************/
//
//@interface DVTDNATokenConnectAction : NSObject<DVTDeviceTokenAction> {
//    NSString * _identifier;
//    NSObject<OS_dispatch_queue> * _operationQueue;
//}
//@property (readonly,nonatomic) NSString * identifier;
//@property (readonly) unsigned long long hash;
//@property (readonly) Class superclass;
//@property (readonly,copy) NSString * description;
//@property (readonly,copy) NSString * debugDescription;
//- (id)init;
//- (void)performForDeviceToken:(id)v1 completionHandler:(void (^ /* unknown block signature */)(void))v2;
//- (void).cxx_destruct;
//@end
//
//
///*****************************************************************/
//
//@interface DVTDeviceNetworkActionProvider : NSObject<DVTDeviceActionProvider>
//@property (readonly) unsigned long long hash;
//@property (readonly) Class superclass;
//@property (readonly,copy) NSString * description;
//@property (readonly,copy) NSString * debugDescription;
//- (id)allDeviceActions;
//- (id)allDeviceTokenActions;
//@end
//
//
///*****************************************************************/
//
//@interface DVTNetworkDeviceARPTool : NSObject
//+ (void)arpLookupCallingCompletionHandlerOnQueue:(id)v1 completionHandler:(void (^ /* unknown block signature */)(void))v2;
//@end
//
//
///*****************************************************************/
//
//@interface DVTNetworkDeviceIfconfigTool : NSObject
//+ (void)enumerateActiveUsableInterfacesCallingCompletionHandlerOnQueue:(id)v1 completionHandler:(void (^ /* unknown block signature */)(void))v2;
//@end
//
//
///*****************************************************************/
//
//@interface DVTNetworkDevicePingTool : NSObject
//+ (void)populateARPCacheByScanningInterface:(id)v1 completionQueue:(id)v2 completionBlock:(void (^ /* unknown block signature */)(void))v3;
//@end
//
//
///*****************************************************************/
//
//@interface DVTAsyncDeviceAction : NSObject<DVTDeviceAction> {
//    NSString * _identifier;
//    NSString * _title;
//    NSMutableDictionary * _parameterMap;
//    NSMutableDictionary * _operationMap;
//    NSObject<OS_dispatch_queue> * _operationQueue;
//}
//@property (readonly,nonatomic) NSString * title;
//@property (readonly,nonatomic) NSString * identifier;
//@property (readonly) unsigned long long hash;
//@property (readonly) Class superclass;
//@property (readonly,copy) NSString * description;
//@property (readonly,copy) NSString * debugDescription;
//- (id)initWithIdentifier:(id)v1 title:(id)v2;
//- (void)addParameterWithKey:(id)v1 userPrompt:(id)v2 defaultValue:(id)v3;
//- (id)defaultValueForDevice:(id)v1 ofParameterWithKey:(id)v2;
//- (id)confirmationMessageForDevice:(id)v1;
//- (id)titleForDevice:(id)v1;
//- (id)tooltipForDevice:(id)v1;
//- (bool)shouldShowActionForDevice:(id)v1;
//- (bool)shouldEnableActionForDevice:(id)v1;
//- (unsigned long long)currentStateForDevice:(id)v1;
//- (void)performForDevice:(id)v1 infoRequestHandler:(void (^ /* unknown block signature */)(void))v2 completionHandler:(void (^ /* unknown block signature */)(void))v3;
//- (void)cancelForDevice:(id)v1;
//- (id)performForDevice:(id)v1 withArguments:(id)v2 infoRequestHandler:(void (^ /* unknown block signature */)(void))v3;
//- (void).cxx_destruct;
//@end
//
//
///*****************************************************************/
//
//@interface DVTAsyncDeviceActionParameter : NSObject {
//    NSString * _key;
//    NSString * _userPrompt;
//    NSString * _defaultValue;
//}
//@property (retain,nonatomic) NSString * key;
//@property (retain,nonatomic) NSString * userPrompt;
//@property (retain,nonatomic) NSString * defaultValue;
//- (void).cxx_destruct;
//@end
//
//
///*****************************************************************/
//
//@interface DVTNetworkDeviceReachability : NSObject
//+ (bool)deviceAddressIsReachable:(id)v1;
//+ (id)sharedReachability;
//- (id)trackReachabilityForDeviceAddresses:(id)v1 notificationBlock:(void (^ /* unknown block signature */)(void))v2;
//- (void)cancelTrackingReachabilityForToken:(id)v1;
//@end
//
//
///*****************************************************************/
//
//@interface DVTNetworkDeviceReachabilityToken : NSObject<NSCopying>
//- (id)copyWithZone:(struct _NSZone *)v1;
//@end
//
//
///*****************************************************************/
//
//@interface DVTBuildTargetDevice : DVTDevice {
//    NSOrderedSet * _supportedArchitectures;
//}
//+ (id)deviceExtension;
//- (id)initWithPlatform:(id)v1;
//- (id)name;
//- (id)displayOrder;
//- (char)isGenericDevice;
//- (char)isConcreteDevice;
//- (char)isProxiedDevice;
//- (id)modelCode;
//- (id)modelName;
//- (id)modelUTI;
//- (id)supportedArchitectures;
//- (id)nativeArchitecture;
//- (char)canSelectArchitectureToExecute;
//- (void)requestProcessInformationsOnPairedDevice:(char)v1 handler:(void (^ /* unknown block signature */)(void))v2;
//- (char)allowsManagedStateControl;
//- (char)supportsArchiving;
//- (char)supportsAttachByPIDOrName;
//- (char)supportsPGOReturningError:(id *)v1;
//- (char)supportsRecordedFrames;
//- (char)supportsMainThreadChecker;
//- (char)supportsDaemonDebugging;
//- (void)debugXPCServices:(id)v1 onPairedDevice:(char)v2 completionSemaphore:(id)v3;
//- (unsigned long long)supportsFetchEvents;
//- (id)deviceType;
//- (char)isAvailable;
//- (id)extraDebuggingRuntimeDylibPath;
//- (void).cxx_destruct;
//@end
//
//
///*****************************************************************/
//
//@interface DVTNetworkDeviceServiceBrowser : NSObject<NSNetServiceBrowserDelegate,NSNetServiceDelegate> {
//    NSObject<OS_dispatch_queue> * _browserQueue;
//    NSNetServiceBrowser * _browser;
//    NSMutableSet * _services;
//    NSMutableDictionary * _savedServiceAddresses;
//    NSObject<DVTNetworkDeviceServiceBrowserDelegate> * _delegate;
//}
//@property (readonly) unsigned long long hash;
//@property (readonly) Class superclass;
//@property (readonly,copy) NSString * description;
//@property (readonly,copy) NSString * debugDescription;
//+ (id)_deviceMACAddressFromServiceName:(id)v1;
//- (id)initWithDelegate:(id)v1;
//- (void)dealloc;
//- (void)restartBrowsing;
//- (void)netServiceBrowserWillSearch:(id)v1;
//- (void)netServiceBrowserDidStopSearch:(id)v1;
//- (void)netServiceBrowser:(id)v1 didNotSearch:(id)v2;
//- (void)netServiceBrowser:(id)v1 didFindDomain:(id)v2 moreComing:(char)v3;
//- (void)netServiceBrowser:(id)v1 didRemoveDomain:(id)v2 moreComing:(char)v3;
//- (void)netServiceBrowser:(id)v1 didFindService:(id)v2 moreComing:(char)v3;
//- (void)netServiceBrowser:(id)v1 didRemoveService:(id)v2 moreComing:(char)v3;
//- (void)netServiceDidResolveAddress:(id)v1;
//- (void)netService:(id)v1 didUpdateTXTRecordData:(id)v2;
//- (void).cxx_destruct;
//@end
//
//
///*****************************************************************/
//
//@interface DVTNetworkDeviceARPScanner : NSObject
//@end
//
//
///*****************************************************************/
//
//@interface DVTNetworkDeviceAddress : NSObject<NSSecureCoding,NSCopying> {
//    NSString * _deviceIdentifier;
//    NSString * _macAddress;
//    NSString * _ipAddress;
//    long long _type;
//}
//@property (readonly,copy,nonatomic) NSString * deviceIdentifier;
//@property (readonly,copy,nonatomic) NSString * macAddress;
//@property (readonly,copy,nonatomic) NSString * ipAddress;
//@property (readonly,nonatomic) long long type;
//+ (char)supportsSecureCoding;
//+ (id)ipAddressFromSockaddr:(struct sockaddr *)v1;
//+ (id)ipAddressFromAddressData:(id)v1;
//- (id)initWithDeviceIdentifier:(id)v1 macAddress:(id)v2 ipAddress:(id)v3 type:(long long)v4;
//- (id)initWithCoder:(id)v1;
//- (void)encodeWithCoder:(id)v1;
//- (unsigned long long)hash;
//- (char)isEqual:(id)v1;
//- (id)copyWithZone:(struct _NSZone *)v1;
//- (id)description;
//- (struct sockaddr *)sockaddrWithPort:(int)v1;
//- (id)addressDataWithPort:(int)v1;
//- (bool)attemptConnectionToAddressAtPort:(int)v1 timeout:(double)v2;
//- (void).cxx_destruct;
//@end
//
//
///*****************************************************************/
//
//@interface DVTDeviceBonjourProxy : NSObject {
//    NSString * _deviceIdentifier;
//    NSString * _hostPairingToken;
//    NSString * _primaryAddress;
//    NSString * _remoteAddress;
//    DVTTask * _dnssdTask;
//    NSNumber * _processIdentifier;
//}
//@property (readonly,copy,nonatomic) NSString * serviceName;
//@property (readonly,copy,nonatomic) NSString * hostname;
//+ (void)terminateExistingBonjourProxiesForDeviceWithPrimaryAddress:(id)v1;
//+ (id)_existingBonjourProxyProcessesMatchingPrimaryAddress:(id)v1;
//+ (void)_terminatePID:(int)v1;
//- (id)initWithDeviceIdentifier:(id)v1 hostPairingToken:(id)v2 primaryAddress:(id)v3 remoteAddress:(id)v4;
//- (void)dealloc;
//- (char)preflightWithError:(id *)v1;
//- (void)startProxyWithCompletionHandler:(void (^ /* unknown block signature */)(void))v1;
//- (void)connectToDeviceWithCompletionHandler:(void (^ /* unknown block signature */)(void))v1;
//- (void)terminate;
//- (void)_connectToDeviceWithTimeout:(unsigned long long)v1 completionHandler:(void (^ /* unknown block signature */)(void))v2;
//- (id)_bonjourProxyTaskWithError:(id *)v1;
//- (id)_unableToConnectErrorWithDeviceIdentifier:(id)v1;
//- (id)_deviceWithIdentifier:(id)v1;
//- (void).cxx_destruct;
//@end
