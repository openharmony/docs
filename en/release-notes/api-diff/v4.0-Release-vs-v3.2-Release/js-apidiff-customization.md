| Change Type | Old Version | New Version | d.ts File |
| ---- | ------ | ------ | -------- |
|Added|NA|Class name: accountManager;<br>Method or attribute name: function disallowAddLocalAccount(admin: Want, disallow: boolean, callback: AsyncCallback\<void>): void;|@ohos.enterprise.accountManager.d.ts|
|Added|NA|Class name: accountManager;<br>Method or attribute name: function disallowAddLocalAccount(admin: Want, disallow: boolean): Promise\<void>;|@ohos.enterprise.accountManager.d.ts|
|Added|NA|Class name: adminManager;<br>Method or attribute name: function authorizeAdmin(admin: Want, bundleName: string, callback: AsyncCallback\<void>): void;|@ohos.enterprise.adminManager.d.ts|
|Added|NA|Class name: adminManager;<br>Method or attribute name: function authorizeAdmin(admin: Want, bundleName: string): Promise\<void>;|@ohos.enterprise.adminManager.d.ts|
|Added|NA|Class name: ManagedEvent;<br>Method or attribute name: MANAGED_EVENT_APP_START = 2|@ohos.enterprise.adminManager.d.ts|
|Added|NA|Class name: ManagedEvent;<br>Method or attribute name: MANAGED_EVENT_APP_STOP = 3|@ohos.enterprise.adminManager.d.ts|
|Added|NA|Class name: applicationManager;<br>Method or attribute name: function addDisallowedRunningBundles(admin: Want, appIds: Array\<string>, callback: AsyncCallback\<void>): void;|@ohos.enterprise.applicationManager.d.ts|
|Added|NA|Class name: applicationManager;<br>Method or attribute name: function addDisallowedRunningBundles(admin: Want, appIds: Array\<string>, userId: number, callback: AsyncCallback\<void>): void;|@ohos.enterprise.applicationManager.d.ts|
|Added|NA|Class name: applicationManager;<br>Method or attribute name: function addDisallowedRunningBundles(admin: Want, appIds: Array\<string>, userId?: number): Promise\<void>;|@ohos.enterprise.applicationManager.d.ts|
|Added|NA|Class name: applicationManager;<br>Method or attribute name: function removeDisallowedRunningBundles(admin: Want, appIds: Array\<string>, callback: AsyncCallback\<void>): void;|@ohos.enterprise.applicationManager.d.ts|
|Added|NA|Class name: applicationManager;<br>Method or attribute name: function removeDisallowedRunningBundles(admin: Want, appIds: Array\<string>, userId: number, callback: AsyncCallback\<void>): void;|@ohos.enterprise.applicationManager.d.ts|
|Added|NA|Class name: applicationManager;<br>Method or attribute name: function removeDisallowedRunningBundles(admin: Want, appIds: Array\<string>, userId?: number): Promise\<void>;|@ohos.enterprise.applicationManager.d.ts|
|Added|NA|Class name: applicationManager;<br>Method or attribute name: function getDisallowedRunningBundles(admin: Want, callback: AsyncCallback\<Array\<string>>): void;|@ohos.enterprise.applicationManager.d.ts|
|Added|NA|Class name: applicationManager;<br>Method or attribute name: function getDisallowedRunningBundles(admin: Want, userId: number, callback: AsyncCallback\<Array\<string>>): void;|@ohos.enterprise.applicationManager.d.ts|
|Added|NA|Class name: applicationManager;<br>Method or attribute name: function getDisallowedRunningBundles(admin: Want, userId?: number): Promise\<Array\<string>>;|@ohos.enterprise.applicationManager.d.ts|
|Added|NA|Class name: browser;<br>Method or attribute name: function setPolicies(admin: Want, appId: string, policies: string, callback: AsyncCallback\<void>): void;|@ohos.enterprise.browser.d.ts|
|Added|NA|Class name: browser;<br>Method or attribute name: function setPolicies(admin: Want, appId: string, policies: string): Promise\<void>;|@ohos.enterprise.browser.d.ts|
|Added|NA|Class name: browser;<br>Method or attribute name: function getPolicies(admin: Want, appId: string, callback: AsyncCallback\<string>): void;|@ohos.enterprise.browser.d.ts|
|Added|NA|Class name: browser;<br>Method or attribute name: function getPolicies(admin: Want, appId: string): Promise\<string>;|@ohos.enterprise.browser.d.ts|
|Added|NA|Class name: bundleManager;<br>Method or attribute name: function addAllowedInstallBundles(admin: Want, appIds: Array\<string>, callback: AsyncCallback\<void>): void;|@ohos.enterprise.bundleManager.d.ts|
|Added|NA|Class name: bundleManager;<br>Method or attribute name: function addAllowedInstallBundles(admin: Want, appIds: Array\<string>, userId: number, callback: AsyncCallback\<void>): void;|@ohos.enterprise.bundleManager.d.ts|
|Added|NA|Class name: bundleManager;<br>Method or attribute name: function addAllowedInstallBundles(admin: Want, appIds: Array\<string>, userId?: number): Promise\<void>;|@ohos.enterprise.bundleManager.d.ts|
|Added|NA|Class name: bundleManager;<br>Method or attribute name: function removeAllowedInstallBundles(admin: Want, appIds: Array\<string>, callback: AsyncCallback\<void>): void;|@ohos.enterprise.bundleManager.d.ts|
|Added|NA|Class name: bundleManager;<br>Method or attribute name: function removeAllowedInstallBundles(admin: Want, appIds: Array\<string>, userId: number, callback: AsyncCallback\<void>): void;|@ohos.enterprise.bundleManager.d.ts|
|Added|NA|Class name: bundleManager;<br>Method or attribute name: function removeAllowedInstallBundles(admin: Want, appIds: Array\<string>, userId?: number): Promise\<void>;|@ohos.enterprise.bundleManager.d.ts|
|Added|NA|Class name: bundleManager;<br>Method or attribute name: function getAllowedInstallBundles(admin: Want, callback: AsyncCallback\<Array\<string>>): void;|@ohos.enterprise.bundleManager.d.ts|
|Added|NA|Class name: bundleManager;<br>Method or attribute name: function getAllowedInstallBundles(admin: Want, userId: number, callback: AsyncCallback\<Array\<string>>): void;|@ohos.enterprise.bundleManager.d.ts|
|Added|NA|Class name: bundleManager;<br>Method or attribute name: function getAllowedInstallBundles(admin: Want, userId?: number): Promise\<Array\<string>>;|@ohos.enterprise.bundleManager.d.ts|
|Added|NA|Class name: bundleManager;<br>Method or attribute name: function addDisallowedInstallBundles(admin: Want, appIds: Array\<string>, callback: AsyncCallback\<void>): void;|@ohos.enterprise.bundleManager.d.ts|
|Added|NA|Class name: bundleManager;<br>Method or attribute name: function addDisallowedInstallBundles(admin: Want, appIds: Array\<string>, userId: number, callback: AsyncCallback\<void>): void;|@ohos.enterprise.bundleManager.d.ts|
|Added|NA|Class name: bundleManager;<br>Method or attribute name: function addDisallowedInstallBundles(admin: Want, appIds: Array\<string>, userId?: number): Promise\<void>;|@ohos.enterprise.bundleManager.d.ts|
|Added|NA|Class name: bundleManager;<br>Method or attribute name: function removeDisallowedInstallBundles(admin: Want, appIds: Array\<string>, callback: AsyncCallback\<void>): void;|@ohos.enterprise.bundleManager.d.ts|
|Added|NA|Class name: bundleManager;<br>Method or attribute name: function removeDisallowedInstallBundles(admin: Want, appIds: Array\<string>, userId: number, callback: AsyncCallback\<void>): void;|@ohos.enterprise.bundleManager.d.ts|
|Added|NA|Class name: bundleManager;<br>Method or attribute name: function removeDisallowedInstallBundles(admin: Want, appIds: Array\<string>, userId?: number): Promise\<void>;|@ohos.enterprise.bundleManager.d.ts|
|Added|NA|Class name: bundleManager;<br>Method or attribute name: function getDisallowedInstallBundles(admin: Want, callback: AsyncCallback\<Array\<string>>): void;|@ohos.enterprise.bundleManager.d.ts|
|Added|NA|Class name: bundleManager;<br>Method or attribute name: function getDisallowedInstallBundles(admin: Want, userId: number, callback: AsyncCallback\<Array\<string>>): void;|@ohos.enterprise.bundleManager.d.ts|
|Added|NA|Class name: bundleManager;<br>Method or attribute name: function getDisallowedInstallBundles(admin: Want, userId?: number): Promise\<Array\<string>>;|@ohos.enterprise.bundleManager.d.ts|
|Added|NA|Class name: bundleManager;<br>Method or attribute name: function addDisallowedUninstallBundles(admin: Want, appIds: Array\<string>, callback: AsyncCallback\<void>): void;|@ohos.enterprise.bundleManager.d.ts|
|Added|NA|Class name: bundleManager;<br>Method or attribute name: function addDisallowedUninstallBundles(admin: Want, appIds: Array\<string>, userId: number, callback: AsyncCallback\<void>): void;|@ohos.enterprise.bundleManager.d.ts|
|Added|NA|Class name: bundleManager;<br>Method or attribute name: function addDisallowedUninstallBundles(admin: Want, appIds: Array\<string>, userId?: number): Promise\<void>;|@ohos.enterprise.bundleManager.d.ts|
|Added|NA|Class name: bundleManager;<br>Method or attribute name: function removeDisallowedUninstallBundles(admin: Want, appIds: Array\<string>, callback: AsyncCallback\<void>): void;|@ohos.enterprise.bundleManager.d.ts|
|Added|NA|Class name: bundleManager;<br>Method or attribute name: function removeDisallowedUninstallBundles(admin: Want, appIds: Array\<string>, userId: number, callback: AsyncCallback\<void>): void;|@ohos.enterprise.bundleManager.d.ts|
|Added|NA|Class name: bundleManager;<br>Method or attribute name: function removeDisallowedUninstallBundles(admin: Want, appIds: Array\<string>, userId?: number): Promise\<void>;|@ohos.enterprise.bundleManager.d.ts|
|Added|NA|Class name: bundleManager;<br>Method or attribute name: function getDisallowedUninstallBundles(admin: Want, callback: AsyncCallback\<Array\<string>>): void;|@ohos.enterprise.bundleManager.d.ts|
|Added|NA|Class name: bundleManager;<br>Method or attribute name: function getDisallowedUninstallBundles(admin: Want, userId: number, callback: AsyncCallback\<Array\<string>>): void;|@ohos.enterprise.bundleManager.d.ts|
|Added|NA|Class name: bundleManager;<br>Method or attribute name: function getDisallowedUninstallBundles(admin: Want, userId?: number): Promise\<Array\<string>>;|@ohos.enterprise.bundleManager.d.ts|
|Added|NA|Class name: bundleManager;<br>Method or attribute name: function uninstall(admin: Want, bundleName: string, callback: AsyncCallback\<void>): void;|@ohos.enterprise.bundleManager.d.ts|
|Added|NA|Class name: bundleManager;<br>Method or attribute name: function uninstall(admin: Want, bundleName: string, userId: number, callback: AsyncCallback\<void>): void;|@ohos.enterprise.bundleManager.d.ts|
|Added|NA|Class name: bundleManager;<br>Method or attribute name: function uninstall(admin: Want, bundleName: string, isKeepData: boolean, callback: AsyncCallback\<void>): void;|@ohos.enterprise.bundleManager.d.ts|
|Added|NA|Class name: bundleManager;<br>Method or attribute name: function uninstall(admin: Want, bundleName: string, userId: number, isKeepData: boolean, callback: AsyncCallback\<void>): void;|@ohos.enterprise.bundleManager.d.ts|
|Added|NA|Class name: bundleManager;<br>Method or attribute name: function uninstall(admin: Want, bundleName: string, userId?: number, isKeepData?: boolean): Promise\<void>;|@ohos.enterprise.bundleManager.d.ts|
|Added|NA|Class name: bundleManager;<br>Method or attribute name: function install(admin: Want, hapFilePaths: Array\<string>, callback: AsyncCallback\<void>): void;|@ohos.enterprise.bundleManager.d.ts|
|Added|NA|Class name: bundleManager;<br>Method or attribute name: function install(admin: Want, hapFilePaths: Array\<string>, installParam: InstallParam, callback: AsyncCallback\<void>): void;|@ohos.enterprise.bundleManager.d.ts|
|Added|NA|Class name: bundleManager;<br>Method or attribute name: function install(admin: Want, hapFilePaths: Array\<string>, installParam?: InstallParam): Promise\<void>;|@ohos.enterprise.bundleManager.d.ts|
|Added|NA|Class name: InstallParam;<br>Method or attribute name: userId?: number;|@ohos.enterprise.bundleManager.d.ts|
|Added|NA|Class name: InstallParam;<br>Method or attribute name: installFlag?: number;|@ohos.enterprise.bundleManager.d.ts|
|Added|NA|Class name: dateTimeManager;<br>Method or attribute name: function disallowModifyDateTime(admin: Want, disallow: boolean, callback: AsyncCallback\<void>): void;|@ohos.enterprise.dateTimeManager.d.ts|
|Added|NA|Class name: dateTimeManager;<br>Method or attribute name: function disallowModifyDateTime(admin: Want, disallow: boolean): Promise\<void>;|@ohos.enterprise.dateTimeManager.d.ts|
|Added|NA|Class name: dateTimeManager;<br>Method or attribute name: function isModifyDateTimeDisallowed(admin: Want, callback: AsyncCallback\<boolean>): void;|@ohos.enterprise.dateTimeManager.d.ts|
|Added|NA|Class name: dateTimeManager;<br>Method or attribute name: function isModifyDateTimeDisallowed(admin: Want): Promise\<boolean>;|@ohos.enterprise.dateTimeManager.d.ts|
|Added|NA|Class name: deviceControl;<br>Method or attribute name: function resetFactory(admin: Want, callback: AsyncCallback\<void>): void;|@ohos.enterprise.deviceControl.d.ts|
|Added|NA|Class name: deviceControl;<br>Method or attribute name: function resetFactory(admin: Want): Promise\<void>;|@ohos.enterprise.deviceControl.d.ts|
|Added|NA|Class name: deviceInfo;<br>Method or attribute name: function getDeviceSerial(admin: Want, callback: AsyncCallback\<string>): void;|@ohos.enterprise.deviceInfo.d.ts|
|Added|NA|Class name: deviceInfo;<br>Method or attribute name: function getDeviceSerial(admin: Want): Promise\<string>;|@ohos.enterprise.deviceInfo.d.ts|
|Added|NA|Class name: deviceInfo;<br>Method or attribute name: function getDisplayVersion(admin: Want, callback: AsyncCallback\<string>): void;|@ohos.enterprise.deviceInfo.d.ts|
|Added|NA|Class name: deviceInfo;<br>Method or attribute name: function getDisplayVersion(admin: Want): Promise\<string>;|@ohos.enterprise.deviceInfo.d.ts|
|Added|NA|Class name: deviceInfo;<br>Method or attribute name: function getDeviceName(admin: Want, callback: AsyncCallback\<string>): void;|@ohos.enterprise.deviceInfo.d.ts|
|Added|NA|Class name: deviceInfo;<br>Method or attribute name: function getDeviceName(admin: Want): Promise\<string>;|@ohos.enterprise.deviceInfo.d.ts|
|Added|NA|Class name: deviceSettings;<br>Method or attribute name: function getScreenOffTime(admin: Want, callback: AsyncCallback\<number>): void;|@ohos.enterprise.deviceSettings.d.ts|
|Added|NA|Class name: deviceSettings;<br>Method or attribute name: function getScreenOffTime(admin: Want): Promise\<number>;|@ohos.enterprise.deviceSettings.d.ts|
|Added|NA|Class name: deviceSettings;<br>Method or attribute name: function installUserCertificate(admin: Want, certificate: CertBlob, callback: AsyncCallback\<string>): void;|@ohos.enterprise.deviceSettings.d.ts|
|Added|NA|Class name: deviceSettings;<br>Method or attribute name: function installUserCertificate(admin: Want, certificate: CertBlob): Promise\<string>;|@ohos.enterprise.deviceSettings.d.ts|
|Added|NA|Class name: deviceSettings;<br>Method or attribute name: function uninstallUserCertificate(admin: Want, certUri: string, callback: AsyncCallback\<void>): void;|@ohos.enterprise.deviceSettings.d.ts|
|Added|NA|Class name: deviceSettings;<br>Method or attribute name: function uninstallUserCertificate(admin: Want, certUri: string): Promise\<void>;|@ohos.enterprise.deviceSettings.d.ts|
|Added|NA|Class name: CertBlob;<br>Method or attribute name: inData: Uint8Array;|@ohos.enterprise.deviceSettings.d.ts|
|Added|NA|Class name: CertBlob;<br>Method or attribute name: alias: string;|@ohos.enterprise.deviceSettings.d.ts|
|Added|NA|Class name: EnterpriseAdminExtensionAbility;<br>Method or attribute name: onAppStart(bundleName: string): void;|@ohos.enterprise.EnterpriseAdminExtensionAbility.d.ts|
|Added|NA|Class name: EnterpriseAdminExtensionAbility;<br>Method or attribute name: onAppStop(bundleName: string): void;|@ohos.enterprise.EnterpriseAdminExtensionAbility.d.ts|
|Added|NA|Class name: networkManager;<br>Method or attribute name: function getAllNetworkInterfaces(admin: Want, callback: AsyncCallback\<Array\<string>>): void;|@ohos.enterprise.networkManager.d.ts|
|Added|NA|Class name: networkManager;<br>Method or attribute name: function getAllNetworkInterfaces(admin: Want): Promise\<Array\<string>>;|@ohos.enterprise.networkManager.d.ts|
|Added|NA|Class name: networkManager;<br>Method or attribute name: function getIpAddress(admin: Want, networkInterface: string, callback: AsyncCallback\<string>): void;|@ohos.enterprise.networkManager.d.ts|
|Added|NA|Class name: networkManager;<br>Method or attribute name: function getIpAddress(admin: Want, networkInterface: string): Promise\<string>;|@ohos.enterprise.networkManager.d.ts|
|Added|NA|Class name: networkManager;<br>Method or attribute name: function getMac(admin: Want, networkInterface: string, callback: AsyncCallback\<string>): void;|@ohos.enterprise.networkManager.d.ts|
|Added|NA|Class name: networkManager;<br>Method or attribute name: function getMac(admin: Want, networkInterface: string): Promise\<string>;|@ohos.enterprise.networkManager.d.ts|
|Added|NA|Class name: networkManager;<br>Method or attribute name: function isNetworkInterfaceDisabled(admin: Want, networkInterface: string, callback: AsyncCallback\<boolean>): void;|@ohos.enterprise.networkManager.d.ts|
|Added|NA|Class name: networkManager;<br>Method or attribute name: function isNetworkInterfaceDisabled(admin: Want, networkInterface: string): Promise\<boolean>;|@ohos.enterprise.networkManager.d.ts|
|Added|NA|Class name: networkManager;<br>Method or attribute name: function setNetworkInterfaceDisabled(admin: Want, networkInterface: string, isDisabled: boolean, callback: AsyncCallback\<void>): void;|@ohos.enterprise.networkManager.d.ts|
|Added|NA|Class name: networkManager;<br>Method or attribute name: function setNetworkInterfaceDisabled(admin: Want, networkInterface: string, isDisabled: boolean): Promise\<void>;|@ohos.enterprise.networkManager.d.ts|
|Added|NA|Class name: networkManager;<br>Method or attribute name: function setGlobalProxy(admin: Want, httpProxy: connection.HttpProxy, callback: AsyncCallback\<void>): void;|@ohos.enterprise.networkManager.d.ts|
|Added|NA|Class name: networkManager;<br>Method or attribute name: function setGlobalProxy(admin: Want, httpProxy: connection.HttpProxy): Promise\<void>;|@ohos.enterprise.networkManager.d.ts|
|Added|NA|Class name: networkManager;<br>Method or attribute name: function getGlobalProxy(admin: Want, callback: AsyncCallback\<connection.HttpProxy>): void;|@ohos.enterprise.networkManager.d.ts|
|Added|NA|Class name: networkManager;<br>Method or attribute name: function getGlobalProxy(admin: Want): Promise\<connection.HttpProxy>;|@ohos.enterprise.networkManager.d.ts|
|Added|NA|Class name: networkManager;<br>Method or attribute name: function addIptablesFilterRule(admin: Want, filterRule: AddFilterRule, callback: AsyncCallback\<void>): void;|@ohos.enterprise.networkManager.d.ts|
|Added|NA|Class name: networkManager;<br>Method or attribute name: function addIptablesFilterRule(admin: Want, filterRule: AddFilterRule): Promise\<void>;|@ohos.enterprise.networkManager.d.ts|
|Added|NA|Class name: networkManager;<br>Method or attribute name: function removeIptablesFilterRule(admin: Want, filterRule: RemoveFilterRule, callback: AsyncCallback\<void>): void;|@ohos.enterprise.networkManager.d.ts|
|Added|NA|Class name: networkManager;<br>Method or attribute name: function removeIptablesFilterRule(admin: Want, filterRule: RemoveFilterRule): Promise\<void>;|@ohos.enterprise.networkManager.d.ts|
|Added|NA|Class name: networkManager;<br>Method or attribute name: function listIptablesFilterRules(admin: Want, callback: AsyncCallback\<string>): void;|@ohos.enterprise.networkManager.d.ts|
|Added|NA|Class name: networkManager;<br>Method or attribute name: function listIptablesFilterRules(admin: Want): Promise\<string>;|@ohos.enterprise.networkManager.d.ts|
|Added|NA|Class name: AddMethod;<br>Method or attribute name: APPEND = 0|@ohos.enterprise.networkManager.d.ts|
|Added|NA|Class name: AddMethod;<br>Method or attribute name: INSERT = 1|@ohos.enterprise.networkManager.d.ts|
|Added|NA|Class name: Direction;<br>Method or attribute name: INPUT = 0|@ohos.enterprise.networkManager.d.ts|
|Added|NA|Class name: Direction;<br>Method or attribute name: OUTPUT = 1|@ohos.enterprise.networkManager.d.ts|
|Added|NA|Class name: Action;<br>Method or attribute name: ALLOW = 0|@ohos.enterprise.networkManager.d.ts|
|Added|NA|Class name: Action;<br>Method or attribute name: DENY = 1|@ohos.enterprise.networkManager.d.ts|
|Added|NA|Class name: Protocol;<br>Method or attribute name: ALL = 0|@ohos.enterprise.networkManager.d.ts|
|Added|NA|Class name: Protocol;<br>Method or attribute name: TCP = 1|@ohos.enterprise.networkManager.d.ts|
|Added|NA|Class name: Protocol;<br>Method or attribute name: UDP = 2|@ohos.enterprise.networkManager.d.ts|
|Added|NA|Class name: Protocol;<br>Method or attribute name: ICMP = 3|@ohos.enterprise.networkManager.d.ts|
|Added|NA|Class name: AddFilterRule;<br>Method or attribute name: ruleNo?: number;|@ohos.enterprise.networkManager.d.ts|
|Added|NA|Class name: AddFilterRule;<br>Method or attribute name: srcAddr?: string;|@ohos.enterprise.networkManager.d.ts|
|Added|NA|Class name: RemoveFilterRule;<br>Method or attribute name: srcAddr?: string;|@ohos.enterprise.networkManager.d.ts|
|Added|NA|Class name: AddFilterRule;<br>Method or attribute name: destAddr?: string;|@ohos.enterprise.networkManager.d.ts|
|Added|NA|Class name: RemoveFilterRule;<br>Method or attribute name: destAddr?: string;|@ohos.enterprise.networkManager.d.ts|
|Added|NA|Class name: AddFilterRule;<br>Method or attribute name: srcPort?: string;|@ohos.enterprise.networkManager.d.ts|
|Added|NA|Class name: RemoveFilterRule;<br>Method or attribute name: srcPort?: string;|@ohos.enterprise.networkManager.d.ts|
|Added|NA|Class name: AddFilterRule;<br>Method or attribute name: destPort?: string;|@ohos.enterprise.networkManager.d.ts|
|Added|NA|Class name: RemoveFilterRule;<br>Method or attribute name: destPort?: string;|@ohos.enterprise.networkManager.d.ts|
|Added|NA|Class name: AddFilterRule;<br>Method or attribute name: uid?: string;|@ohos.enterprise.networkManager.d.ts|
|Added|NA|Class name: RemoveFilterRule;<br>Method or attribute name: uid?: string;|@ohos.enterprise.networkManager.d.ts|
|Added|NA|Class name: AddFilterRule;<br>Method or attribute name: method: AddMethod;|@ohos.enterprise.networkManager.d.ts|
|Added|NA|Class name: AddFilterRule;<br>Method or attribute name: direction: Direction;|@ohos.enterprise.networkManager.d.ts|
|Added|NA|Class name: RemoveFilterRule;<br>Method or attribute name: direction: Direction;|@ohos.enterprise.networkManager.d.ts|
|Added|NA|Class name: AddFilterRule;<br>Method or attribute name: action: Action;|@ohos.enterprise.networkManager.d.ts|
|Added|NA|Class name: AddFilterRule;<br>Method or attribute name: protocol?: Protocol;|@ohos.enterprise.networkManager.d.ts|
|Added|NA|Class name: RemoveFilterRule;<br>Method or attribute name: protocol?: Protocol;|@ohos.enterprise.networkManager.d.ts|
|Added|NA|Class name: RemoveFilterRule;<br>Method or attribute name: action?: Action;|@ohos.enterprise.networkManager.d.ts|
|Added|NA|Class name: restrictions;<br>Method or attribute name: function setPrinterDisabled(admin: Want, disabled: boolean, callback: AsyncCallback\<void>): void;|@ohos.enterprise.restrictions.d.ts|
|Added|NA|Class name: restrictions;<br>Method or attribute name: function setPrinterDisabled(admin: Want, disabled: boolean): Promise\<void>;|@ohos.enterprise.restrictions.d.ts|
|Added|NA|Class name: restrictions;<br>Method or attribute name: function isPrinterDisabled(admin: Want, callback: AsyncCallback\<boolean>): void;|@ohos.enterprise.restrictions.d.ts|
|Added|NA|Class name: restrictions;<br>Method or attribute name: function isPrinterDisabled(admin: Want): Promise\<boolean>;|@ohos.enterprise.restrictions.d.ts|
|Added|NA|Class name: restrictions;<br>Method or attribute name: function setHdcDisabled(admin: Want, disabled: boolean, callback: AsyncCallback\<void>): void;|@ohos.enterprise.restrictions.d.ts|
|Added|NA|Class name: restrictions;<br>Method or attribute name: function setHdcDisabled(admin: Want, disabled: boolean): Promise\<void>;|@ohos.enterprise.restrictions.d.ts|
|Added|NA|Class name: restrictions;<br>Method or attribute name: function isHdcDisabled(admin: Want, callback: AsyncCallback\<boolean>): void;|@ohos.enterprise.restrictions.d.ts|
|Added|NA|Class name: restrictions;<br>Method or attribute name: function isHdcDisabled(admin: Want): Promise\<boolean>;|@ohos.enterprise.restrictions.d.ts|
|Added|NA|Class name: usbManager;<br>Method or attribute name: function setUsbPolicy(admin: Want, usbPolicy: UsbPolicy, callback: AsyncCallback\<void>): void;|@ohos.enterprise.usbManager.d.ts|
|Added|NA|Class name: usbManager;<br>Method or attribute name: function setUsbPolicy(admin: Want, usbPolicy: UsbPolicy): Promise\<void>;|@ohos.enterprise.usbManager.d.ts|
|Added|NA|Class name: UsbPolicy;<br>Method or attribute name: READ_WRITE = 0|@ohos.enterprise.usbManager.d.ts|
|Added|NA|Class name: UsbPolicy;<br>Method or attribute name: READ_ONLY = 1|@ohos.enterprise.usbManager.d.ts|
|Added|NA|Class name: wifiManager;<br>Method or attribute name: function isWifiActive(admin: Want, callback: AsyncCallback\<boolean>): void;|@ohos.enterprise.wifiManager.d.ts|
|Added|NA|Class name: wifiManager;<br>Method or attribute name: function isWifiActive(admin: Want): Promise\<boolean>;|@ohos.enterprise.wifiManager.d.ts|
|Added|NA|Class name: wifiManager;<br>Method or attribute name: function setWifiProfile(admin: Want, profile: WifiProfile, callback: AsyncCallback\<void>): void;|@ohos.enterprise.wifiManager.d.ts|
|Added|NA|Class name: wifiManager;<br>Method or attribute name: function setWifiProfile(admin: Want, profile: WifiProfile): Promise\<void>;|@ohos.enterprise.wifiManager.d.ts|
|Added|NA|Class name: WifiSecurityType;<br>Method or attribute name: WIFI_SEC_TYPE_INVALID = 0|@ohos.enterprise.wifiManager.d.ts|
|Added|NA|Class name: WifiSecurityType;<br>Method or attribute name: WIFI_SEC_TYPE_OPEN = 1|@ohos.enterprise.wifiManager.d.ts|
|Added|NA|Class name: WifiSecurityType;<br>Method or attribute name: WIFI_SEC_TYPE_WEP = 2|@ohos.enterprise.wifiManager.d.ts|
|Added|NA|Class name: WifiSecurityType;<br>Method or attribute name: WIFI_SEC_TYPE_PSK = 3|@ohos.enterprise.wifiManager.d.ts|
|Added|NA|Class name: WifiSecurityType;<br>Method or attribute name: WIFI_SEC_TYPE_SAE = 4|@ohos.enterprise.wifiManager.d.ts|
|Added|NA|Class name: WifiSecurityType;<br>Method or attribute name: WIFI_SEC_TYPE_EAP = 5|@ohos.enterprise.wifiManager.d.ts|
|Added|NA|Class name: WifiSecurityType;<br>Method or attribute name: WIFI_SEC_TYPE_EAP_SUITE_B = 6|@ohos.enterprise.wifiManager.d.ts|
|Added|NA|Class name: WifiSecurityType;<br>Method or attribute name: WIFI_SEC_TYPE_OWE = 7|@ohos.enterprise.wifiManager.d.ts|
|Added|NA|Class name: WifiSecurityType;<br>Method or attribute name: WIFI_SEC_TYPE_WAPI_CERT = 8|@ohos.enterprise.wifiManager.d.ts|
|Added|NA|Class name: WifiSecurityType;<br>Method or attribute name: WIFI_SEC_TYPE_WAPI_PSK = 9|@ohos.enterprise.wifiManager.d.ts|
|Added|NA|Class name: IpType;<br>Method or attribute name: STATIC|@ohos.enterprise.wifiManager.d.ts|
|Added|NA|Class name: IpType;<br>Method or attribute name: DHCP|@ohos.enterprise.wifiManager.d.ts|
|Added|NA|Class name: IpType;<br>Method or attribute name: UNKNOWN|@ohos.enterprise.wifiManager.d.ts|
|Added|NA|Class name: IpProfile;<br>Method or attribute name: ipAddress: number;|@ohos.enterprise.wifiManager.d.ts|
|Added|NA|Class name: IpProfile;<br>Method or attribute name: gateway: number;|@ohos.enterprise.wifiManager.d.ts|
|Added|NA|Class name: IpProfile;<br>Method or attribute name: prefixLength: number;|@ohos.enterprise.wifiManager.d.ts|
|Added|NA|Class name: IpProfile;<br>Method or attribute name: dnsServers: number[];|@ohos.enterprise.wifiManager.d.ts|
|Added|NA|Class name: IpProfile;<br>Method or attribute name: domains: Array\<string>;|@ohos.enterprise.wifiManager.d.ts|
|Added|NA|Class name: EapMethod;<br>Method or attribute name: EAP_NONE|@ohos.enterprise.wifiManager.d.ts|
|Added|NA|Class name: EapMethod;<br>Method or attribute name: EAP_PEAP|@ohos.enterprise.wifiManager.d.ts|
|Added|NA|Class name: EapMethod;<br>Method or attribute name: EAP_TLS|@ohos.enterprise.wifiManager.d.ts|
|Added|NA|Class name: EapMethod;<br>Method or attribute name: EAP_TTLS|@ohos.enterprise.wifiManager.d.ts|
|Added|NA|Class name: EapMethod;<br>Method or attribute name: EAP_PWD|@ohos.enterprise.wifiManager.d.ts|
|Added|NA|Class name: EapMethod;<br>Method or attribute name: EAP_SIM|@ohos.enterprise.wifiManager.d.ts|
|Added|NA|Class name: EapMethod;<br>Method or attribute name: EAP_AKA|@ohos.enterprise.wifiManager.d.ts|
|Added|NA|Class name: EapMethod;<br>Method or attribute name: EAP_AKA_PRIME|@ohos.enterprise.wifiManager.d.ts|
|Added|NA|Class name: EapMethod;<br>Method or attribute name: EAP_UNAUTH_TLS|@ohos.enterprise.wifiManager.d.ts|
|Added|NA|Class name: Phase2Method;<br>Method or attribute name: PHASE2_NONE|@ohos.enterprise.wifiManager.d.ts|
|Added|NA|Class name: Phase2Method;<br>Method or attribute name: PHASE2_PAP|@ohos.enterprise.wifiManager.d.ts|
|Added|NA|Class name: Phase2Method;<br>Method or attribute name: PHASE2_MSCHAP|@ohos.enterprise.wifiManager.d.ts|
|Added|NA|Class name: Phase2Method;<br>Method or attribute name: PHASE2_MSCHAPV2|@ohos.enterprise.wifiManager.d.ts|
|Added|NA|Class name: Phase2Method;<br>Method or attribute name: PHASE2_GTC|@ohos.enterprise.wifiManager.d.ts|
|Added|NA|Class name: Phase2Method;<br>Method or attribute name: PHASE2_SIM|@ohos.enterprise.wifiManager.d.ts|
|Added|NA|Class name: Phase2Method;<br>Method or attribute name: PHASE2_AKA|@ohos.enterprise.wifiManager.d.ts|
|Added|NA|Class name: Phase2Method;<br>Method or attribute name: PHASE2_AKA_PRIME|@ohos.enterprise.wifiManager.d.ts|
|Added|NA|Class name: WifiEapProfile;<br>Method or attribute name: eapMethod: EapMethod;|@ohos.enterprise.wifiManager.d.ts|
|Added|NA|Class name: WifiEapProfile;<br>Method or attribute name: phase2Method: Phase2Method;|@ohos.enterprise.wifiManager.d.ts|
|Added|NA|Class name: WifiEapProfile;<br>Method or attribute name: identity: string;|@ohos.enterprise.wifiManager.d.ts|
|Added|NA|Class name: WifiEapProfile;<br>Method or attribute name: anonymousIdentity: string;|@ohos.enterprise.wifiManager.d.ts|
|Added|NA|Class name: WifiEapProfile;<br>Method or attribute name: password: string;|@ohos.enterprise.wifiManager.d.ts|
|Added|NA|Class name: WifiEapProfile;<br>Method or attribute name: caCertAliases: string;|@ohos.enterprise.wifiManager.d.ts|
|Added|NA|Class name: WifiEapProfile;<br>Method or attribute name: caPath: string;|@ohos.enterprise.wifiManager.d.ts|
|Added|NA|Class name: WifiEapProfile;<br>Method or attribute name: clientCertAliases: string;|@ohos.enterprise.wifiManager.d.ts|
|Added|NA|Class name: WifiEapProfile;<br>Method or attribute name: certEntry: Uint8Array;|@ohos.enterprise.wifiManager.d.ts|
|Added|NA|Class name: WifiEapProfile;<br>Method or attribute name: certPassword: string;|@ohos.enterprise.wifiManager.d.ts|
|Added|NA|Class name: WifiEapProfile;<br>Method or attribute name: altSubjectMatch: string;|@ohos.enterprise.wifiManager.d.ts|
|Added|NA|Class name: WifiEapProfile;<br>Method or attribute name: domainSuffixMatch: string;|@ohos.enterprise.wifiManager.d.ts|
|Added|NA|Class name: WifiEapProfile;<br>Method or attribute name: realm: string;|@ohos.enterprise.wifiManager.d.ts|
|Added|NA|Class name: WifiEapProfile;<br>Method or attribute name: plmn: string;|@ohos.enterprise.wifiManager.d.ts|
|Added|NA|Class name: WifiEapProfile;<br>Method or attribute name: eapSubId: number;|@ohos.enterprise.wifiManager.d.ts|
|Added|NA|Class name: WifiProfile;<br>Method or attribute name: ssid: string;|@ohos.enterprise.wifiManager.d.ts|
|Added|NA|Class name: WifiProfile;<br>Method or attribute name: bssid?: string;|@ohos.enterprise.wifiManager.d.ts|
|Added|NA|Class name: WifiProfile;<br>Method or attribute name: preSharedKey: string;|@ohos.enterprise.wifiManager.d.ts|
|Added|NA|Class name: WifiProfile;<br>Method or attribute name: isHiddenSsid?: boolean;|@ohos.enterprise.wifiManager.d.ts|
|Added|NA|Class name: WifiProfile;<br>Method or attribute name: securityType: WifiSecurityType;|@ohos.enterprise.wifiManager.d.ts|
|Added|NA|Class name: WifiProfile;<br>Method or attribute name: creatorUid?: number;|@ohos.enterprise.wifiManager.d.ts|
|Added|NA|Class name: WifiProfile;<br>Method or attribute name: disableReason?: number;|@ohos.enterprise.wifiManager.d.ts|
|Added|NA|Class name: WifiProfile;<br>Method or attribute name: netId?: number;|@ohos.enterprise.wifiManager.d.ts|
|Added|NA|Class name: WifiProfile;<br>Method or attribute name: randomMacType?: number;|@ohos.enterprise.wifiManager.d.ts|
|Added|NA|Class name: WifiProfile;<br>Method or attribute name: randomMacAddr?: string;|@ohos.enterprise.wifiManager.d.ts|
|Added|NA|Class name: WifiProfile;<br>Method or attribute name: ipType?: IpType;|@ohos.enterprise.wifiManager.d.ts|
|Added|NA|Class name: WifiProfile;<br>Method or attribute name: staticIp?: IpProfile;|@ohos.enterprise.wifiManager.d.ts|
|Added|NA|Class name: WifiProfile;<br>Method or attribute name: eapProfile?: WifiEapProfile;|@ohos.enterprise.wifiManager.d.ts|
|Error code added|Class name: configPolicy;<br>Method or attribute name: function getOneCfgFile(relPath: string): Promise\<string>;<br>Old version information: |Class name: configPolicy;<br>Method or attribute name: function getOneCfgFile(relPath: string): Promise\<string>;<br>New version information: 401|@ohos.configPolicy.d.ts|
|Error code added|Class name: configPolicy;<br>Method or attribute name: function getCfgFiles(relPath: string): Promise\<Array\<string>>;<br>Old version information: |Class name: configPolicy;<br>Method or attribute name: function getCfgFiles(relPath: string): Promise\<Array\<string>>;<br>New version information: 401|@ohos.configPolicy.d.ts|
|Error code added|Class name: configPolicy;<br>Method or attribute name: function getCfgDirList(): Promise\<Array\<string>>;<br>Old version information: |Class name: configPolicy;<br>Method or attribute name: function getCfgDirList(): Promise\<Array\<string>>;<br>New version information: 401|@ohos.configPolicy.d.ts|
|Error code changed|Class name: adminManager;<br>Method or attribute name: function enableAdmin(admin: Want, enterpriseInfo: EnterpriseInfo, type: AdminType, callback: AsyncCallback\<void>): void;<br>Old version information: 9200003,9200004,9200007,201,401|Class name: adminManager;<br>Method or attribute name: function enableAdmin(admin: Want, enterpriseInfo: EnterpriseInfo, type: AdminType, callback: AsyncCallback\<void>): void;<br>New version information: 9200003,9200004,9200007,201,202,401|@ohos.enterprise.adminManager.d.ts|
|Error code changed|Class name: adminManager;<br>Method or attribute name: function enableAdmin(admin: Want, enterpriseInfo: EnterpriseInfo, type: AdminType, userId: number, callback: AsyncCallback\<void>): void;<br>Old version information: 9200003,9200004,9200007,201,401|Class name: adminManager;<br>Method or attribute name: function enableAdmin(admin: Want, enterpriseInfo: EnterpriseInfo, type: AdminType, userId: number, callback: AsyncCallback\<void>): void;<br>New version information: 9200003,9200004,9200007,201,202,401|@ohos.enterprise.adminManager.d.ts|
|Error code changed|Class name: adminManager;<br>Method or attribute name: function enableAdmin(admin: Want, enterpriseInfo: EnterpriseInfo, type: AdminType, userId?: number): Promise\<void>;<br>Old version information: 9200003,9200004,9200007,201,401|Class name: adminManager;<br>Method or attribute name: function enableAdmin(admin: Want, enterpriseInfo: EnterpriseInfo, type: AdminType, userId?: number): Promise\<void>;<br>New version information: 9200003,9200004,9200007,201,202,401|@ohos.enterprise.adminManager.d.ts|
|Error code changed|Class name: adminManager;<br>Method or attribute name: function disableAdmin(admin: Want, callback: AsyncCallback\<void>): void;<br>Old version information: 9200005,201,401|Class name: adminManager;<br>Method or attribute name: function disableAdmin(admin: Want, callback: AsyncCallback\<void>): void;<br>New version information: 9200005,201,202,401|@ohos.enterprise.adminManager.d.ts|
|Error code changed|Class name: adminManager;<br>Method or attribute name: function disableAdmin(admin: Want, userId: number, callback: AsyncCallback\<void>): void;<br>Old version information: 9200005,201,401|Class name: adminManager;<br>Method or attribute name: function disableAdmin(admin: Want, userId: number, callback: AsyncCallback\<void>): void;<br>New version information: 9200005,201,202,401|@ohos.enterprise.adminManager.d.ts|
|Error code changed|Class name: adminManager;<br>Method or attribute name: function disableAdmin(admin: Want, userId?: number): Promise\<void>;<br>Old version information: 9200005,201,401|Class name: adminManager;<br>Method or attribute name: function disableAdmin(admin: Want, userId?: number): Promise\<void>;<br>New version information: 9200005,201,202,401|@ohos.enterprise.adminManager.d.ts|
|Error code changed|Class name: adminManager;<br>Method or attribute name: function disableSuperAdmin(bundleName: String, callback: AsyncCallback\<void>): void;<br>Old version information: 9200005,201,401|Class name: adminManager;<br>Method or attribute name: function disableSuperAdmin(bundleName: String, callback: AsyncCallback\<void>): void;<br>New version information: 9200005,201,202,401|@ohos.enterprise.adminManager.d.ts|
|Error code changed|Class name: adminManager;<br>Method or attribute name: function disableSuperAdmin(bundleName: String): Promise\<void>;<br>Old version information: 9200005,201,401|Class name: adminManager;<br>Method or attribute name: function disableSuperAdmin(bundleName: String): Promise\<void>;<br>New version information: 9200005,201,202,401|@ohos.enterprise.adminManager.d.ts|
|Error code changed|Class name: adminManager;<br>Method or attribute name: function isAdminEnabled(admin: Want, callback: AsyncCallback\<boolean>): void;<br>Old version information: 401|Class name: adminManager;<br>Method or attribute name: function isAdminEnabled(admin: Want, callback: AsyncCallback\<boolean>): void;<br>New version information: 202,401|@ohos.enterprise.adminManager.d.ts|
|Error code changed|Class name: adminManager;<br>Method or attribute name: function isAdminEnabled(admin: Want, userId: number, callback: AsyncCallback\<boolean>): void;<br>Old version information: 401|Class name: adminManager;<br>Method or attribute name: function isAdminEnabled(admin: Want, userId: number, callback: AsyncCallback\<boolean>): void;<br>New version information: 202,401|@ohos.enterprise.adminManager.d.ts|
|Error code changed|Class name: adminManager;<br>Method or attribute name: function isAdminEnabled(admin: Want, userId?: number): Promise\<boolean>;<br>Old version information: 401|Class name: adminManager;<br>Method or attribute name: function isAdminEnabled(admin: Want, userId?: number): Promise\<boolean>;<br>New version information: 202,401|@ohos.enterprise.adminManager.d.ts|
|Error code changed|Class name: adminManager;<br>Method or attribute name: function getEnterpriseInfo(admin: Want, callback: AsyncCallback\<EnterpriseInfo>): void;<br>Old version information: 9200001,401|Class name: adminManager;<br>Method or attribute name: function getEnterpriseInfo(admin: Want, callback: AsyncCallback\<EnterpriseInfo>): void;<br>New version information: 9200001,202,401|@ohos.enterprise.adminManager.d.ts|
|Error code changed|Class name: adminManager;<br>Method or attribute name: function getEnterpriseInfo(admin: Want): Promise\<EnterpriseInfo>;<br>Old version information: 9200001,401|Class name: adminManager;<br>Method or attribute name: function getEnterpriseInfo(admin: Want): Promise\<EnterpriseInfo>;<br>New version information: 9200001,202,401|@ohos.enterprise.adminManager.d.ts|
|Error code changed|Class name: adminManager;<br>Method or attribute name: function setEnterpriseInfo(admin: Want, enterpriseInfo: EnterpriseInfo, callback: AsyncCallback\<void>): void;<br>Old version information: 9200001,201,401|Class name: adminManager;<br>Method or attribute name: function setEnterpriseInfo(admin: Want, enterpriseInfo: EnterpriseInfo, callback: AsyncCallback\<void>): void;<br>New version information: 9200001,201,202,401|@ohos.enterprise.adminManager.d.ts|
|Error code changed|Class name: adminManager;<br>Method or attribute name: function setEnterpriseInfo(admin: Want, enterpriseInfo: EnterpriseInfo): Promise\<void>;<br>Old version information: 9200001,201,401|Class name: adminManager;<br>Method or attribute name: function setEnterpriseInfo(admin: Want, enterpriseInfo: EnterpriseInfo): Promise\<void>;<br>New version information: 9200001,201,202,401|@ohos.enterprise.adminManager.d.ts|
|Error code changed|Class name: adminManager;<br>Method or attribute name: function isSuperAdmin(bundleName: String, callback: AsyncCallback\<boolean>): void;<br>Old version information: 401|Class name: adminManager;<br>Method or attribute name: function isSuperAdmin(bundleName: String, callback: AsyncCallback\<boolean>): void;<br>New version information: 202,401|@ohos.enterprise.adminManager.d.ts|
|Error code changed|Class name: adminManager;<br>Method or attribute name: function isSuperAdmin(bundleName: String): Promise\<boolean>;<br>Old version information: 401|Class name: adminManager;<br>Method or attribute name: function isSuperAdmin(bundleName: String): Promise\<boolean>;<br>New version information: 202,401|@ohos.enterprise.adminManager.d.ts|
|Error code changed|Class name: adminManager;<br>Method or attribute name: function subscribeManagedEvent(admin: Want, managedEvents: Array\<ManagedEvent>, callback: AsyncCallback\<void>): void;<br>Old version information: 9200001,9200008,201,401|Class name: adminManager;<br>Method or attribute name: function subscribeManagedEvent(admin: Want, managedEvents: Array\<ManagedEvent>, callback: AsyncCallback\<void>): void;<br>New version information: 9200001,9200008,201,202,401|@ohos.enterprise.adminManager.d.ts|
|Error code changed|Class name: adminManager;<br>Method or attribute name: function subscribeManagedEvent(admin: Want, managedEvents: Array\<ManagedEvent>): Promise\<void>;<br>Old version information: 9200001,9200008,201,401|Class name: adminManager;<br>Method or attribute name: function subscribeManagedEvent(admin: Want, managedEvents: Array\<ManagedEvent>): Promise\<void>;<br>New version information: 9200001,9200008,201,202,401|@ohos.enterprise.adminManager.d.ts|
|Error code changed|Class name: adminManager;<br>Method or attribute name: function unsubscribeManagedEvent(admin: Want, managedEvents: Array\<ManagedEvent>, callback: AsyncCallback\<void>): void;<br>Old version information: 9200001,9200008,201,401|Class name: adminManager;<br>Method or attribute name: function unsubscribeManagedEvent(admin: Want, managedEvents: Array\<ManagedEvent>, callback: AsyncCallback\<void>): void;<br>New version information: 9200001,9200008,201,202,401|@ohos.enterprise.adminManager.d.ts|
|Error code changed|Class name: adminManager;<br>Method or attribute name: function unsubscribeManagedEvent(admin: Want, managedEvents: Array\<ManagedEvent>): Promise\<void>;<br>Old version information: 9200001,9200008,201,401|Class name: adminManager;<br>Method or attribute name: function unsubscribeManagedEvent(admin: Want, managedEvents: Array\<ManagedEvent>): Promise\<void>;<br>New version information: 9200001,9200008,201,202,401|@ohos.enterprise.adminManager.d.ts|
|Error code changed|Class name: dateTimeManager;<br>Method or attribute name: function setDateTime(admin: Want, time: number, callback: AsyncCallback\<void>): void;<br>Old version information: 9200001,9200002,201,401|Class name: dateTimeManager;<br>Method or attribute name: function setDateTime(admin: Want, time: number, callback: AsyncCallback\<void>): void;<br>New version information: 9200001,9200002,201,202,401|@ohos.enterprise.dateTimeManager.d.ts|
|Error code changed|Class name: dateTimeManager;<br>Method or attribute name: function setDateTime(admin: Want, time: number): Promise\<void>;<br>Old version information: 9200001,9200002,201,401|Class name: dateTimeManager;<br>Method or attribute name: function setDateTime(admin: Want, time: number): Promise\<void>;<br>New version information: 9200001,9200002,201,202,401|@ohos.enterprise.dateTimeManager.d.ts|
|Access level changed|Class name: configPolicy;<br>Method or attribute name: function getOneCfgFile(relPath: string): Promise\<string>;<br>Old version information: |Class name: configPolicy;<br>Method or attribute name: function getOneCfgFile(relPath: string): Promise\<string>;<br>New version information: systemapi|@ohos.configPolicy.d.ts|
|Access level changed|Class name: configPolicy;<br>Method or attribute name: function getCfgFiles(relPath: string): Promise\<Array\<string>>;<br>Old version information: |Class name: configPolicy;<br>Method or attribute name: function getCfgFiles(relPath: string): Promise\<Array\<string>>;<br>New version information: systemapi|@ohos.configPolicy.d.ts|
|Access level changed|Class name: configPolicy;<br>Method or attribute name: function getCfgDirList(): Promise\<Array\<string>>;<br>Old version information: |Class name: configPolicy;<br>Method or attribute name: function getCfgDirList(): Promise\<Array\<string>>;<br>New version information: systemapi|@ohos.configPolicy.d.ts|
|Access level changed|Class name: EnterpriseInfo;<br>Method or attribute name: name: string;<br>Old version information: |Class name: EnterpriseInfo;<br>Method or attribute name: name: string;<br>New version information: systemapi|@ohos.enterprise.adminManager.d.ts|
|Access level changed|Class name: EnterpriseInfo;<br>Method or attribute name: description: string;<br>Old version information: |Class name: EnterpriseInfo;<br>Method or attribute name: description: string;<br>New version information: systemapi|@ohos.enterprise.adminManager.d.ts|
|Access level changed|Class name: AdminType;<br>Method or attribute name: ADMIN_TYPE_NORMAL = 0x00<br>Old version information: |Class name: AdminType;<br>Method or attribute name: ADMIN_TYPE_NORMAL = 0x00<br>New version information: systemapi|@ohos.enterprise.adminManager.d.ts|
|Access level changed|Class name: AdminType;<br>Method or attribute name: ADMIN_TYPE_SUPER = 0x01<br>Old version information: |Class name: AdminType;<br>Method or attribute name: ADMIN_TYPE_SUPER = 0x01<br>New version information: systemapi|@ohos.enterprise.adminManager.d.ts|
|Access level changed|Class name: ManagedEvent;<br>Method or attribute name: MANAGED_EVENT_BUNDLE_ADDED = 0<br>Old version information: |Class name: ManagedEvent;<br>Method or attribute name: MANAGED_EVENT_BUNDLE_ADDED = 0<br>New version information: systemapi|@ohos.enterprise.adminManager.d.ts|
|Access level changed|Class name: ManagedEvent;<br>Method or attribute name: MANAGED_EVENT_BUNDLE_REMOVED = 1<br>Old version information: |Class name: ManagedEvent;<br>Method or attribute name: MANAGED_EVENT_BUNDLE_REMOVED = 1<br>New version information: systemapi|@ohos.enterprise.adminManager.d.ts|
