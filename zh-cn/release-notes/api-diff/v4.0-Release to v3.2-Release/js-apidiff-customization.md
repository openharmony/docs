| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|类名：accountManager;<br>方法or属性：function disallowAddLocalAccount(admin: Want, disallow: boolean, callback: AsyncCallback\<void>): void;|@ohos.enterprise.accountManager.d.ts|
|新增|NA|类名：accountManager;<br>方法or属性：function disallowAddLocalAccount(admin: Want, disallow: boolean): Promise\<void>;|@ohos.enterprise.accountManager.d.ts|
|新增|NA|类名：adminManager;<br>方法or属性：function authorizeAdmin(admin: Want, bundleName: string, callback: AsyncCallback\<void>): void;|@ohos.enterprise.adminManager.d.ts|
|新增|NA|类名：adminManager;<br>方法or属性：function authorizeAdmin(admin: Want, bundleName: string): Promise\<void>;|@ohos.enterprise.adminManager.d.ts|
|新增|NA|类名：ManagedEvent;<br>方法or属性：MANAGED_EVENT_APP_START = 2|@ohos.enterprise.adminManager.d.ts|
|新增|NA|类名：ManagedEvent;<br>方法or属性：MANAGED_EVENT_APP_STOP = 3|@ohos.enterprise.adminManager.d.ts|
|新增|NA|类名：applicationManager;<br>方法or属性：function addDisallowedRunningBundles(admin: Want, appIds: Array\<string>, callback: AsyncCallback\<void>): void;|@ohos.enterprise.applicationManager.d.ts|
|新增|NA|类名：applicationManager;<br>方法or属性：function addDisallowedRunningBundles(admin: Want, appIds: Array\<string>, userId: number, callback: AsyncCallback\<void>): void;|@ohos.enterprise.applicationManager.d.ts|
|新增|NA|类名：applicationManager;<br>方法or属性：function addDisallowedRunningBundles(admin: Want, appIds: Array\<string>, userId?: number): Promise\<void>;|@ohos.enterprise.applicationManager.d.ts|
|新增|NA|类名：applicationManager;<br>方法or属性：function removeDisallowedRunningBundles(admin: Want, appIds: Array\<string>, callback: AsyncCallback\<void>): void;|@ohos.enterprise.applicationManager.d.ts|
|新增|NA|类名：applicationManager;<br>方法or属性：function removeDisallowedRunningBundles(admin: Want, appIds: Array\<string>, userId: number, callback: AsyncCallback\<void>): void;|@ohos.enterprise.applicationManager.d.ts|
|新增|NA|类名：applicationManager;<br>方法or属性：function removeDisallowedRunningBundles(admin: Want, appIds: Array\<string>, userId?: number): Promise\<void>;|@ohos.enterprise.applicationManager.d.ts|
|新增|NA|类名：applicationManager;<br>方法or属性：function getDisallowedRunningBundles(admin: Want, callback: AsyncCallback\<Array\<string>>): void;|@ohos.enterprise.applicationManager.d.ts|
|新增|NA|类名：applicationManager;<br>方法or属性：function getDisallowedRunningBundles(admin: Want, userId: number, callback: AsyncCallback\<Array\<string>>): void;|@ohos.enterprise.applicationManager.d.ts|
|新增|NA|类名：applicationManager;<br>方法or属性：function getDisallowedRunningBundles(admin: Want, userId?: number): Promise\<Array\<string>>;|@ohos.enterprise.applicationManager.d.ts|
|新增|NA|类名：browser;<br>方法or属性：function setPolicies(admin: Want, appId: string, policies: string, callback: AsyncCallback\<void>): void;|@ohos.enterprise.browser.d.ts|
|新增|NA|类名：browser;<br>方法or属性：function setPolicies(admin: Want, appId: string, policies: string): Promise\<void>;|@ohos.enterprise.browser.d.ts|
|新增|NA|类名：browser;<br>方法or属性：function getPolicies(admin: Want, appId: string, callback: AsyncCallback\<string>): void;|@ohos.enterprise.browser.d.ts|
|新增|NA|类名：browser;<br>方法or属性：function getPolicies(admin: Want, appId: string): Promise\<string>;|@ohos.enterprise.browser.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function addAllowedInstallBundles(admin: Want, appIds: Array\<string>, callback: AsyncCallback\<void>): void;|@ohos.enterprise.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function addAllowedInstallBundles(admin: Want, appIds: Array\<string>, userId: number, callback: AsyncCallback\<void>): void;|@ohos.enterprise.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function addAllowedInstallBundles(admin: Want, appIds: Array\<string>, userId?: number): Promise\<void>;|@ohos.enterprise.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function removeAllowedInstallBundles(admin: Want, appIds: Array\<string>, callback: AsyncCallback\<void>): void;|@ohos.enterprise.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function removeAllowedInstallBundles(admin: Want, appIds: Array\<string>, userId: number, callback: AsyncCallback\<void>): void;|@ohos.enterprise.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function removeAllowedInstallBundles(admin: Want, appIds: Array\<string>, userId?: number): Promise\<void>;|@ohos.enterprise.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function getAllowedInstallBundles(admin: Want, callback: AsyncCallback\<Array\<string>>): void;|@ohos.enterprise.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function getAllowedInstallBundles(admin: Want, userId: number, callback: AsyncCallback\<Array\<string>>): void;|@ohos.enterprise.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function getAllowedInstallBundles(admin: Want, userId?: number): Promise\<Array\<string>>;|@ohos.enterprise.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function addDisallowedInstallBundles(admin: Want, appIds: Array\<string>, callback: AsyncCallback\<void>): void;|@ohos.enterprise.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function addDisallowedInstallBundles(admin: Want, appIds: Array\<string>, userId: number, callback: AsyncCallback\<void>): void;|@ohos.enterprise.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function addDisallowedInstallBundles(admin: Want, appIds: Array\<string>, userId?: number): Promise\<void>;|@ohos.enterprise.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function removeDisallowedInstallBundles(admin: Want, appIds: Array\<string>, callback: AsyncCallback\<void>): void;|@ohos.enterprise.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function removeDisallowedInstallBundles(admin: Want, appIds: Array\<string>, userId: number, callback: AsyncCallback\<void>): void;|@ohos.enterprise.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function removeDisallowedInstallBundles(admin: Want, appIds: Array\<string>, userId?: number): Promise\<void>;|@ohos.enterprise.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function getDisallowedInstallBundles(admin: Want, callback: AsyncCallback\<Array\<string>>): void;|@ohos.enterprise.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function getDisallowedInstallBundles(admin: Want, userId: number, callback: AsyncCallback\<Array\<string>>): void;|@ohos.enterprise.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function getDisallowedInstallBundles(admin: Want, userId?: number): Promise\<Array\<string>>;|@ohos.enterprise.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function addDisallowedUninstallBundles(admin: Want, appIds: Array\<string>, callback: AsyncCallback\<void>): void;|@ohos.enterprise.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function addDisallowedUninstallBundles(admin: Want, appIds: Array\<string>, userId: number, callback: AsyncCallback\<void>): void;|@ohos.enterprise.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function addDisallowedUninstallBundles(admin: Want, appIds: Array\<string>, userId?: number): Promise\<void>;|@ohos.enterprise.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function removeDisallowedUninstallBundles(admin: Want, appIds: Array\<string>, callback: AsyncCallback\<void>): void;|@ohos.enterprise.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function removeDisallowedUninstallBundles(admin: Want, appIds: Array\<string>, userId: number, callback: AsyncCallback\<void>): void;|@ohos.enterprise.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function removeDisallowedUninstallBundles(admin: Want, appIds: Array\<string>, userId?: number): Promise\<void>;|@ohos.enterprise.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function getDisallowedUninstallBundles(admin: Want, callback: AsyncCallback\<Array\<string>>): void;|@ohos.enterprise.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function getDisallowedUninstallBundles(admin: Want, userId: number, callback: AsyncCallback\<Array\<string>>): void;|@ohos.enterprise.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function getDisallowedUninstallBundles(admin: Want, userId?: number): Promise\<Array\<string>>;|@ohos.enterprise.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function uninstall(admin: Want, bundleName: string, callback: AsyncCallback\<void>): void;|@ohos.enterprise.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function uninstall(admin: Want, bundleName: string, userId: number, callback: AsyncCallback\<void>): void;|@ohos.enterprise.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function uninstall(admin: Want, bundleName: string, isKeepData: boolean, callback: AsyncCallback\<void>): void;|@ohos.enterprise.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function uninstall(admin: Want, bundleName: string, userId: number, isKeepData: boolean, callback: AsyncCallback\<void>): void;|@ohos.enterprise.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function uninstall(admin: Want, bundleName: string, userId?: number, isKeepData?: boolean): Promise\<void>;|@ohos.enterprise.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function install(admin: Want, hapFilePaths: Array\<string>, callback: AsyncCallback\<void>): void;|@ohos.enterprise.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function install(admin: Want, hapFilePaths: Array\<string>, installParam: InstallParam, callback: AsyncCallback\<void>): void;|@ohos.enterprise.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function install(admin: Want, hapFilePaths: Array\<string>, installParam?: InstallParam): Promise\<void>;|@ohos.enterprise.bundleManager.d.ts|
|新增|NA|类名：InstallParam;<br>方法or属性：userId?: number;|@ohos.enterprise.bundleManager.d.ts|
|新增|NA|类名：InstallParam;<br>方法or属性：installFlag?: number;|@ohos.enterprise.bundleManager.d.ts|
|新增|NA|类名：dateTimeManager;<br>方法or属性：function disallowModifyDateTime(admin: Want, disallow: boolean, callback: AsyncCallback\<void>): void;|@ohos.enterprise.dateTimeManager.d.ts|
|新增|NA|类名：dateTimeManager;<br>方法or属性：function disallowModifyDateTime(admin: Want, disallow: boolean): Promise\<void>;|@ohos.enterprise.dateTimeManager.d.ts|
|新增|NA|类名：dateTimeManager;<br>方法or属性：function isModifyDateTimeDisallowed(admin: Want, callback: AsyncCallback\<boolean>): void;|@ohos.enterprise.dateTimeManager.d.ts|
|新增|NA|类名：dateTimeManager;<br>方法or属性：function isModifyDateTimeDisallowed(admin: Want): Promise\<boolean>;|@ohos.enterprise.dateTimeManager.d.ts|
|新增|NA|类名：deviceControl;<br>方法or属性：function resetFactory(admin: Want, callback: AsyncCallback\<void>): void;|@ohos.enterprise.deviceControl.d.ts|
|新增|NA|类名：deviceControl;<br>方法or属性：function resetFactory(admin: Want): Promise\<void>;|@ohos.enterprise.deviceControl.d.ts|
|新增|NA|类名：deviceInfo;<br>方法or属性：function getDeviceSerial(admin: Want, callback: AsyncCallback\<string>): void;|@ohos.enterprise.deviceInfo.d.ts|
|新增|NA|类名：deviceInfo;<br>方法or属性：function getDeviceSerial(admin: Want): Promise\<string>;|@ohos.enterprise.deviceInfo.d.ts|
|新增|NA|类名：deviceInfo;<br>方法or属性：function getDisplayVersion(admin: Want, callback: AsyncCallback\<string>): void;|@ohos.enterprise.deviceInfo.d.ts|
|新增|NA|类名：deviceInfo;<br>方法or属性：function getDisplayVersion(admin: Want): Promise\<string>;|@ohos.enterprise.deviceInfo.d.ts|
|新增|NA|类名：deviceInfo;<br>方法or属性：function getDeviceName(admin: Want, callback: AsyncCallback\<string>): void;|@ohos.enterprise.deviceInfo.d.ts|
|新增|NA|类名：deviceInfo;<br>方法or属性：function getDeviceName(admin: Want): Promise\<string>;|@ohos.enterprise.deviceInfo.d.ts|
|新增|NA|类名：deviceSettings;<br>方法or属性：function getScreenOffTime(admin: Want, callback: AsyncCallback\<number>): void;|@ohos.enterprise.deviceSettings.d.ts|
|新增|NA|类名：deviceSettings;<br>方法or属性：function getScreenOffTime(admin: Want): Promise\<number>;|@ohos.enterprise.deviceSettings.d.ts|
|新增|NA|类名：deviceSettings;<br>方法or属性：function installUserCertificate(admin: Want, certificate: CertBlob, callback: AsyncCallback\<string>): void;|@ohos.enterprise.deviceSettings.d.ts|
|新增|NA|类名：deviceSettings;<br>方法or属性：function installUserCertificate(admin: Want, certificate: CertBlob): Promise\<string>;|@ohos.enterprise.deviceSettings.d.ts|
|新增|NA|类名：deviceSettings;<br>方法or属性：function uninstallUserCertificate(admin: Want, certUri: string, callback: AsyncCallback\<void>): void;|@ohos.enterprise.deviceSettings.d.ts|
|新增|NA|类名：deviceSettings;<br>方法or属性：function uninstallUserCertificate(admin: Want, certUri: string): Promise\<void>;|@ohos.enterprise.deviceSettings.d.ts|
|新增|NA|类名：CertBlob;<br>方法or属性：inData: Uint8Array;|@ohos.enterprise.deviceSettings.d.ts|
|新增|NA|类名：CertBlob;<br>方法or属性：alias: string;|@ohos.enterprise.deviceSettings.d.ts|
|新增|NA|类名：EnterpriseAdminExtensionAbility;<br>方法or属性：onAppStart(bundleName: string): void;|@ohos.enterprise.EnterpriseAdminExtensionAbility.d.ts|
|新增|NA|类名：EnterpriseAdminExtensionAbility;<br>方法or属性：onAppStop(bundleName: string): void;|@ohos.enterprise.EnterpriseAdminExtensionAbility.d.ts|
|新增|NA|类名：networkManager;<br>方法or属性：function getAllNetworkInterfaces(admin: Want, callback: AsyncCallback\<Array\<string>>): void;|@ohos.enterprise.networkManager.d.ts|
|新增|NA|类名：networkManager;<br>方法or属性：function getAllNetworkInterfaces(admin: Want): Promise\<Array\<string>>;|@ohos.enterprise.networkManager.d.ts|
|新增|NA|类名：networkManager;<br>方法or属性：function getIpAddress(admin: Want, networkInterface: string, callback: AsyncCallback\<string>): void;|@ohos.enterprise.networkManager.d.ts|
|新增|NA|类名：networkManager;<br>方法or属性：function getIpAddress(admin: Want, networkInterface: string): Promise\<string>;|@ohos.enterprise.networkManager.d.ts|
|新增|NA|类名：networkManager;<br>方法or属性：function getMac(admin: Want, networkInterface: string, callback: AsyncCallback\<string>): void;|@ohos.enterprise.networkManager.d.ts|
|新增|NA|类名：networkManager;<br>方法or属性：function getMac(admin: Want, networkInterface: string): Promise\<string>;|@ohos.enterprise.networkManager.d.ts|
|新增|NA|类名：networkManager;<br>方法or属性：function isNetworkInterfaceDisabled(admin: Want, networkInterface: string, callback: AsyncCallback\<boolean>): void;|@ohos.enterprise.networkManager.d.ts|
|新增|NA|类名：networkManager;<br>方法or属性：function isNetworkInterfaceDisabled(admin: Want, networkInterface: string): Promise\<boolean>;|@ohos.enterprise.networkManager.d.ts|
|新增|NA|类名：networkManager;<br>方法or属性：function setNetworkInterfaceDisabled(admin: Want, networkInterface: string, isDisabled: boolean, callback: AsyncCallback\<void>): void;|@ohos.enterprise.networkManager.d.ts|
|新增|NA|类名：networkManager;<br>方法or属性：function setNetworkInterfaceDisabled(admin: Want, networkInterface: string, isDisabled: boolean): Promise\<void>;|@ohos.enterprise.networkManager.d.ts|
|新增|NA|类名：networkManager;<br>方法or属性：function setGlobalProxy(admin: Want, httpProxy: connection.HttpProxy, callback: AsyncCallback\<void>): void;|@ohos.enterprise.networkManager.d.ts|
|新增|NA|类名：networkManager;<br>方法or属性：function setGlobalProxy(admin: Want, httpProxy: connection.HttpProxy): Promise\<void>;|@ohos.enterprise.networkManager.d.ts|
|新增|NA|类名：networkManager;<br>方法or属性：function getGlobalProxy(admin: Want, callback: AsyncCallback\<connection.HttpProxy>): void;|@ohos.enterprise.networkManager.d.ts|
|新增|NA|类名：networkManager;<br>方法or属性：function getGlobalProxy(admin: Want): Promise\<connection.HttpProxy>;|@ohos.enterprise.networkManager.d.ts|
|新增|NA|类名：networkManager;<br>方法or属性：function addIptablesFilterRule(admin: Want, filterRule: AddFilterRule, callback: AsyncCallback\<void>): void;|@ohos.enterprise.networkManager.d.ts|
|新增|NA|类名：networkManager;<br>方法or属性：function addIptablesFilterRule(admin: Want, filterRule: AddFilterRule): Promise\<void>;|@ohos.enterprise.networkManager.d.ts|
|新增|NA|类名：networkManager;<br>方法or属性：function removeIptablesFilterRule(admin: Want, filterRule: RemoveFilterRule, callback: AsyncCallback\<void>): void;|@ohos.enterprise.networkManager.d.ts|
|新增|NA|类名：networkManager;<br>方法or属性：function removeIptablesFilterRule(admin: Want, filterRule: RemoveFilterRule): Promise\<void>;|@ohos.enterprise.networkManager.d.ts|
|新增|NA|类名：networkManager;<br>方法or属性：function listIptablesFilterRules(admin: Want, callback: AsyncCallback\<string>): void;|@ohos.enterprise.networkManager.d.ts|
|新增|NA|类名：networkManager;<br>方法or属性：function listIptablesFilterRules(admin: Want): Promise\<string>;|@ohos.enterprise.networkManager.d.ts|
|新增|NA|类名：AddMethod;<br>方法or属性：APPEND = 0|@ohos.enterprise.networkManager.d.ts|
|新增|NA|类名：AddMethod;<br>方法or属性：INSERT = 1|@ohos.enterprise.networkManager.d.ts|
|新增|NA|类名：Direction;<br>方法or属性：INPUT = 0|@ohos.enterprise.networkManager.d.ts|
|新增|NA|类名：Direction;<br>方法or属性：OUTPUT = 1|@ohos.enterprise.networkManager.d.ts|
|新增|NA|类名：Action;<br>方法or属性：ALLOW = 0|@ohos.enterprise.networkManager.d.ts|
|新增|NA|类名：Action;<br>方法or属性：DENY = 1|@ohos.enterprise.networkManager.d.ts|
|新增|NA|类名：Protocol;<br>方法or属性：ALL = 0|@ohos.enterprise.networkManager.d.ts|
|新增|NA|类名：Protocol;<br>方法or属性：TCP = 1|@ohos.enterprise.networkManager.d.ts|
|新增|NA|类名：Protocol;<br>方法or属性：UDP = 2|@ohos.enterprise.networkManager.d.ts|
|新增|NA|类名：Protocol;<br>方法or属性：ICMP = 3|@ohos.enterprise.networkManager.d.ts|
|新增|NA|类名：AddFilterRule;<br>方法or属性：ruleNo?: number;|@ohos.enterprise.networkManager.d.ts|
|新增|NA|类名：AddFilterRule;<br>方法or属性：srcAddr?: string;|@ohos.enterprise.networkManager.d.ts|
|新增|NA|类名：RemoveFilterRule;<br>方法or属性：srcAddr?: string;|@ohos.enterprise.networkManager.d.ts|
|新增|NA|类名：AddFilterRule;<br>方法or属性：destAddr?: string;|@ohos.enterprise.networkManager.d.ts|
|新增|NA|类名：RemoveFilterRule;<br>方法or属性：destAddr?: string;|@ohos.enterprise.networkManager.d.ts|
|新增|NA|类名：AddFilterRule;<br>方法or属性：srcPort?: string;|@ohos.enterprise.networkManager.d.ts|
|新增|NA|类名：RemoveFilterRule;<br>方法or属性：srcPort?: string;|@ohos.enterprise.networkManager.d.ts|
|新增|NA|类名：AddFilterRule;<br>方法or属性：destPort?: string;|@ohos.enterprise.networkManager.d.ts|
|新增|NA|类名：RemoveFilterRule;<br>方法or属性：destPort?: string;|@ohos.enterprise.networkManager.d.ts|
|新增|NA|类名：AddFilterRule;<br>方法or属性：uid?: string;|@ohos.enterprise.networkManager.d.ts|
|新增|NA|类名：RemoveFilterRule;<br>方法or属性：uid?: string;|@ohos.enterprise.networkManager.d.ts|
|新增|NA|类名：AddFilterRule;<br>方法or属性：method: AddMethod;|@ohos.enterprise.networkManager.d.ts|
|新增|NA|类名：AddFilterRule;<br>方法or属性：direction: Direction;|@ohos.enterprise.networkManager.d.ts|
|新增|NA|类名：RemoveFilterRule;<br>方法or属性：direction: Direction;|@ohos.enterprise.networkManager.d.ts|
|新增|NA|类名：AddFilterRule;<br>方法or属性：action: Action;|@ohos.enterprise.networkManager.d.ts|
|新增|NA|类名：AddFilterRule;<br>方法or属性：protocol?: Protocol;|@ohos.enterprise.networkManager.d.ts|
|新增|NA|类名：RemoveFilterRule;<br>方法or属性：protocol?: Protocol;|@ohos.enterprise.networkManager.d.ts|
|新增|NA|类名：RemoveFilterRule;<br>方法or属性：action?: Action;|@ohos.enterprise.networkManager.d.ts|
|新增|NA|类名：restrictions;<br>方法or属性：function setPrinterDisabled(admin: Want, disabled: boolean, callback: AsyncCallback\<void>): void;|@ohos.enterprise.restrictions.d.ts|
|新增|NA|类名：restrictions;<br>方法or属性：function setPrinterDisabled(admin: Want, disabled: boolean): Promise\<void>;|@ohos.enterprise.restrictions.d.ts|
|新增|NA|类名：restrictions;<br>方法or属性：function isPrinterDisabled(admin: Want, callback: AsyncCallback\<boolean>): void;|@ohos.enterprise.restrictions.d.ts|
|新增|NA|类名：restrictions;<br>方法or属性：function isPrinterDisabled(admin: Want): Promise\<boolean>;|@ohos.enterprise.restrictions.d.ts|
|新增|NA|类名：restrictions;<br>方法or属性：function setHdcDisabled(admin: Want, disabled: boolean, callback: AsyncCallback\<void>): void;|@ohos.enterprise.restrictions.d.ts|
|新增|NA|类名：restrictions;<br>方法or属性：function setHdcDisabled(admin: Want, disabled: boolean): Promise\<void>;|@ohos.enterprise.restrictions.d.ts|
|新增|NA|类名：restrictions;<br>方法or属性：function isHdcDisabled(admin: Want, callback: AsyncCallback\<boolean>): void;|@ohos.enterprise.restrictions.d.ts|
|新增|NA|类名：restrictions;<br>方法or属性：function isHdcDisabled(admin: Want): Promise\<boolean>;|@ohos.enterprise.restrictions.d.ts|
|新增|NA|类名：usbManager;<br>方法or属性：function setUsbPolicy(admin: Want, usbPolicy: UsbPolicy, callback: AsyncCallback\<void>): void;|@ohos.enterprise.usbManager.d.ts|
|新增|NA|类名：usbManager;<br>方法or属性：function setUsbPolicy(admin: Want, usbPolicy: UsbPolicy): Promise\<void>;|@ohos.enterprise.usbManager.d.ts|
|新增|NA|类名：UsbPolicy;<br>方法or属性：READ_WRITE = 0|@ohos.enterprise.usbManager.d.ts|
|新增|NA|类名：UsbPolicy;<br>方法or属性：READ_ONLY = 1|@ohos.enterprise.usbManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function isWifiActive(admin: Want, callback: AsyncCallback\<boolean>): void;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function isWifiActive(admin: Want): Promise\<boolean>;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function setWifiProfile(admin: Want, profile: WifiProfile, callback: AsyncCallback\<void>): void;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function setWifiProfile(admin: Want, profile: WifiProfile): Promise\<void>;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|类名：WifiSecurityType;<br>方法or属性：WIFI_SEC_TYPE_INVALID = 0|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|类名：WifiSecurityType;<br>方法or属性：WIFI_SEC_TYPE_OPEN = 1|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|类名：WifiSecurityType;<br>方法or属性：WIFI_SEC_TYPE_WEP = 2|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|类名：WifiSecurityType;<br>方法or属性：WIFI_SEC_TYPE_PSK = 3|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|类名：WifiSecurityType;<br>方法or属性：WIFI_SEC_TYPE_SAE = 4|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|类名：WifiSecurityType;<br>方法or属性：WIFI_SEC_TYPE_EAP = 5|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|类名：WifiSecurityType;<br>方法or属性：WIFI_SEC_TYPE_EAP_SUITE_B = 6|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|类名：WifiSecurityType;<br>方法or属性：WIFI_SEC_TYPE_OWE = 7|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|类名：WifiSecurityType;<br>方法or属性：WIFI_SEC_TYPE_WAPI_CERT = 8|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|类名：WifiSecurityType;<br>方法or属性：WIFI_SEC_TYPE_WAPI_PSK = 9|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|类名：IpType;<br>方法or属性：STATIC|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|类名：IpType;<br>方法or属性：DHCP|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|类名：IpType;<br>方法or属性：UNKNOWN|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|类名：IpProfile;<br>方法or属性：ipAddress: number;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|类名：IpProfile;<br>方法or属性：gateway: number;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|类名：IpProfile;<br>方法or属性：prefixLength: number;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|类名：IpProfile;<br>方法or属性：dnsServers: number[];|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|类名：IpProfile;<br>方法or属性：domains: Array\<string>;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|类名：EapMethod;<br>方法or属性：EAP_NONE|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|类名：EapMethod;<br>方法or属性：EAP_PEAP|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|类名：EapMethod;<br>方法or属性：EAP_TLS|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|类名：EapMethod;<br>方法or属性：EAP_TTLS|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|类名：EapMethod;<br>方法or属性：EAP_PWD|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|类名：EapMethod;<br>方法or属性：EAP_SIM|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|类名：EapMethod;<br>方法or属性：EAP_AKA|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|类名：EapMethod;<br>方法or属性：EAP_AKA_PRIME|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|类名：EapMethod;<br>方法or属性：EAP_UNAUTH_TLS|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|类名：Phase2Method;<br>方法or属性：PHASE2_NONE|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|类名：Phase2Method;<br>方法or属性：PHASE2_PAP|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|类名：Phase2Method;<br>方法or属性：PHASE2_MSCHAP|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|类名：Phase2Method;<br>方法or属性：PHASE2_MSCHAPV2|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|类名：Phase2Method;<br>方法or属性：PHASE2_GTC|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|类名：Phase2Method;<br>方法or属性：PHASE2_SIM|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|类名：Phase2Method;<br>方法or属性：PHASE2_AKA|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|类名：Phase2Method;<br>方法or属性：PHASE2_AKA_PRIME|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|类名：WifiEapProfile;<br>方法or属性：eapMethod: EapMethod;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|类名：WifiEapProfile;<br>方法or属性：phase2Method: Phase2Method;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|类名：WifiEapProfile;<br>方法or属性：identity: string;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|类名：WifiEapProfile;<br>方法or属性：anonymousIdentity: string;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|类名：WifiEapProfile;<br>方法or属性：password: string;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|类名：WifiEapProfile;<br>方法or属性：caCertAliases: string;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|类名：WifiEapProfile;<br>方法or属性：caPath: string;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|类名：WifiEapProfile;<br>方法or属性：clientCertAliases: string;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|类名：WifiEapProfile;<br>方法or属性：certEntry: Uint8Array;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|类名：WifiEapProfile;<br>方法or属性：certPassword: string;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|类名：WifiEapProfile;<br>方法or属性：altSubjectMatch: string;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|类名：WifiEapProfile;<br>方法or属性：domainSuffixMatch: string;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|类名：WifiEapProfile;<br>方法or属性：realm: string;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|类名：WifiEapProfile;<br>方法or属性：plmn: string;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|类名：WifiEapProfile;<br>方法or属性：eapSubId: number;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|类名：WifiProfile;<br>方法or属性：ssid: string;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|类名：WifiProfile;<br>方法or属性：bssid?: string;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|类名：WifiProfile;<br>方法or属性：preSharedKey: string;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|类名：WifiProfile;<br>方法or属性：isHiddenSsid?: boolean;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|类名：WifiProfile;<br>方法or属性：securityType: WifiSecurityType;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|类名：WifiProfile;<br>方法or属性：creatorUid?: number;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|类名：WifiProfile;<br>方法or属性：disableReason?: number;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|类名：WifiProfile;<br>方法or属性：netId?: number;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|类名：WifiProfile;<br>方法or属性：randomMacType?: number;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|类名：WifiProfile;<br>方法or属性：randomMacAddr?: string;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|类名：WifiProfile;<br>方法or属性：ipType?: IpType;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|类名：WifiProfile;<br>方法or属性：staticIp?: IpProfile;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|类名：WifiProfile;<br>方法or属性：eapProfile?: WifiEapProfile;|@ohos.enterprise.wifiManager.d.ts|
|新增(错误码)|类名：configPolicy;<br>方法or属性：function getOneCfgFile(relPath: string): Promise\<string>;<br>旧版本信息：|类名：configPolicy;<br>方法or属性：function getOneCfgFile(relPath: string): Promise\<string>;<br>新版本信息：401|@ohos.configPolicy.d.ts|
|新增(错误码)|类名：configPolicy;<br>方法or属性：function getCfgFiles(relPath: string): Promise\<Array\<string>>;<br>旧版本信息：|类名：configPolicy;<br>方法or属性：function getCfgFiles(relPath: string): Promise\<Array\<string>>;<br>新版本信息：401|@ohos.configPolicy.d.ts|
|新增(错误码)|类名：configPolicy;<br>方法or属性：function getCfgDirList(): Promise\<Array\<string>>;<br>旧版本信息：|类名：configPolicy;<br>方法or属性：function getCfgDirList(): Promise\<Array\<string>>;<br>新版本信息：401|@ohos.configPolicy.d.ts|
|错误码有变化|类名：adminManager;<br>方法or属性：function enableAdmin(admin: Want, enterpriseInfo: EnterpriseInfo, type: AdminType, callback: AsyncCallback\<void>): void;<br>旧版本信息：9200003,9200004,9200007,201,401|类名：adminManager;<br>方法or属性：function enableAdmin(admin: Want, enterpriseInfo: EnterpriseInfo, type: AdminType, callback: AsyncCallback\<void>): void;<br>新版本信息：9200003,9200004,9200007,201,202,401|@ohos.enterprise.adminManager.d.ts|
|错误码有变化|类名：adminManager;<br>方法or属性：function enableAdmin(admin: Want, enterpriseInfo: EnterpriseInfo, type: AdminType, userId: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：9200003,9200004,9200007,201,401|类名：adminManager;<br>方法or属性：function enableAdmin(admin: Want, enterpriseInfo: EnterpriseInfo, type: AdminType, userId: number, callback: AsyncCallback\<void>): void;<br>新版本信息：9200003,9200004,9200007,201,202,401|@ohos.enterprise.adminManager.d.ts|
|错误码有变化|类名：adminManager;<br>方法or属性：function enableAdmin(admin: Want, enterpriseInfo: EnterpriseInfo, type: AdminType, userId?: number): Promise\<void>;<br>旧版本信息：9200003,9200004,9200007,201,401|类名：adminManager;<br>方法or属性：function enableAdmin(admin: Want, enterpriseInfo: EnterpriseInfo, type: AdminType, userId?: number): Promise\<void>;<br>新版本信息：9200003,9200004,9200007,201,202,401|@ohos.enterprise.adminManager.d.ts|
|错误码有变化|类名：adminManager;<br>方法or属性：function disableAdmin(admin: Want, callback: AsyncCallback\<void>): void;<br>旧版本信息：9200005,201,401|类名：adminManager;<br>方法or属性：function disableAdmin(admin: Want, callback: AsyncCallback\<void>): void;<br>新版本信息：9200005,201,202,401|@ohos.enterprise.adminManager.d.ts|
|错误码有变化|类名：adminManager;<br>方法or属性：function disableAdmin(admin: Want, userId: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：9200005,201,401|类名：adminManager;<br>方法or属性：function disableAdmin(admin: Want, userId: number, callback: AsyncCallback\<void>): void;<br>新版本信息：9200005,201,202,401|@ohos.enterprise.adminManager.d.ts|
|错误码有变化|类名：adminManager;<br>方法or属性：function disableAdmin(admin: Want, userId?: number): Promise\<void>;<br>旧版本信息：9200005,201,401|类名：adminManager;<br>方法or属性：function disableAdmin(admin: Want, userId?: number): Promise\<void>;<br>新版本信息：9200005,201,202,401|@ohos.enterprise.adminManager.d.ts|
|错误码有变化|类名：adminManager;<br>方法or属性：function disableSuperAdmin(bundleName: String, callback: AsyncCallback\<void>): void;<br>旧版本信息：9200005,201,401|类名：adminManager;<br>方法or属性：function disableSuperAdmin(bundleName: String, callback: AsyncCallback\<void>): void;<br>新版本信息：9200005,201,202,401|@ohos.enterprise.adminManager.d.ts|
|错误码有变化|类名：adminManager;<br>方法or属性：function disableSuperAdmin(bundleName: String): Promise\<void>;<br>旧版本信息：9200005,201,401|类名：adminManager;<br>方法or属性：function disableSuperAdmin(bundleName: String): Promise\<void>;<br>新版本信息：9200005,201,202,401|@ohos.enterprise.adminManager.d.ts|
|错误码有变化|类名：adminManager;<br>方法or属性：function isAdminEnabled(admin: Want, callback: AsyncCallback\<boolean>): void;<br>旧版本信息：401|类名：adminManager;<br>方法or属性：function isAdminEnabled(admin: Want, callback: AsyncCallback\<boolean>): void;<br>新版本信息：202,401|@ohos.enterprise.adminManager.d.ts|
|错误码有变化|类名：adminManager;<br>方法or属性：function isAdminEnabled(admin: Want, userId: number, callback: AsyncCallback\<boolean>): void;<br>旧版本信息：401|类名：adminManager;<br>方法or属性：function isAdminEnabled(admin: Want, userId: number, callback: AsyncCallback\<boolean>): void;<br>新版本信息：202,401|@ohos.enterprise.adminManager.d.ts|
|错误码有变化|类名：adminManager;<br>方法or属性：function isAdminEnabled(admin: Want, userId?: number): Promise\<boolean>;<br>旧版本信息：401|类名：adminManager;<br>方法or属性：function isAdminEnabled(admin: Want, userId?: number): Promise\<boolean>;<br>新版本信息：202,401|@ohos.enterprise.adminManager.d.ts|
|错误码有变化|类名：adminManager;<br>方法or属性：function getEnterpriseInfo(admin: Want, callback: AsyncCallback\<EnterpriseInfo>): void;<br>旧版本信息：9200001,401|类名：adminManager;<br>方法or属性：function getEnterpriseInfo(admin: Want, callback: AsyncCallback\<EnterpriseInfo>): void;<br>新版本信息：9200001,202,401|@ohos.enterprise.adminManager.d.ts|
|错误码有变化|类名：adminManager;<br>方法or属性：function getEnterpriseInfo(admin: Want): Promise\<EnterpriseInfo>;<br>旧版本信息：9200001,401|类名：adminManager;<br>方法or属性：function getEnterpriseInfo(admin: Want): Promise\<EnterpriseInfo>;<br>新版本信息：9200001,202,401|@ohos.enterprise.adminManager.d.ts|
|错误码有变化|类名：adminManager;<br>方法or属性：function setEnterpriseInfo(admin: Want, enterpriseInfo: EnterpriseInfo, callback: AsyncCallback\<void>): void;<br>旧版本信息：9200001,201,401|类名：adminManager;<br>方法or属性：function setEnterpriseInfo(admin: Want, enterpriseInfo: EnterpriseInfo, callback: AsyncCallback\<void>): void;<br>新版本信息：9200001,201,202,401|@ohos.enterprise.adminManager.d.ts|
|错误码有变化|类名：adminManager;<br>方法or属性：function setEnterpriseInfo(admin: Want, enterpriseInfo: EnterpriseInfo): Promise\<void>;<br>旧版本信息：9200001,201,401|类名：adminManager;<br>方法or属性：function setEnterpriseInfo(admin: Want, enterpriseInfo: EnterpriseInfo): Promise\<void>;<br>新版本信息：9200001,201,202,401|@ohos.enterprise.adminManager.d.ts|
|错误码有变化|类名：adminManager;<br>方法or属性：function isSuperAdmin(bundleName: String, callback: AsyncCallback\<boolean>): void;<br>旧版本信息：401|类名：adminManager;<br>方法or属性：function isSuperAdmin(bundleName: String, callback: AsyncCallback\<boolean>): void;<br>新版本信息：202,401|@ohos.enterprise.adminManager.d.ts|
|错误码有变化|类名：adminManager;<br>方法or属性：function isSuperAdmin(bundleName: String): Promise\<boolean>;<br>旧版本信息：401|类名：adminManager;<br>方法or属性：function isSuperAdmin(bundleName: String): Promise\<boolean>;<br>新版本信息：202,401|@ohos.enterprise.adminManager.d.ts|
|错误码有变化|类名：adminManager;<br>方法or属性：function subscribeManagedEvent(admin: Want, managedEvents: Array\<ManagedEvent>, callback: AsyncCallback\<void>): void;<br>旧版本信息：9200001,9200008,201,401|类名：adminManager;<br>方法or属性：function subscribeManagedEvent(admin: Want, managedEvents: Array\<ManagedEvent>, callback: AsyncCallback\<void>): void;<br>新版本信息：9200001,9200008,201,202,401|@ohos.enterprise.adminManager.d.ts|
|错误码有变化|类名：adminManager;<br>方法or属性：function subscribeManagedEvent(admin: Want, managedEvents: Array\<ManagedEvent>): Promise\<void>;<br>旧版本信息：9200001,9200008,201,401|类名：adminManager;<br>方法or属性：function subscribeManagedEvent(admin: Want, managedEvents: Array\<ManagedEvent>): Promise\<void>;<br>新版本信息：9200001,9200008,201,202,401|@ohos.enterprise.adminManager.d.ts|
|错误码有变化|类名：adminManager;<br>方法or属性：function unsubscribeManagedEvent(admin: Want, managedEvents: Array\<ManagedEvent>, callback: AsyncCallback\<void>): void;<br>旧版本信息：9200001,9200008,201,401|类名：adminManager;<br>方法or属性：function unsubscribeManagedEvent(admin: Want, managedEvents: Array\<ManagedEvent>, callback: AsyncCallback\<void>): void;<br>新版本信息：9200001,9200008,201,202,401|@ohos.enterprise.adminManager.d.ts|
|错误码有变化|类名：adminManager;<br>方法or属性：function unsubscribeManagedEvent(admin: Want, managedEvents: Array\<ManagedEvent>): Promise\<void>;<br>旧版本信息：9200001,9200008,201,401|类名：adminManager;<br>方法or属性：function unsubscribeManagedEvent(admin: Want, managedEvents: Array\<ManagedEvent>): Promise\<void>;<br>新版本信息：9200001,9200008,201,202,401|@ohos.enterprise.adminManager.d.ts|
|错误码有变化|类名：dateTimeManager;<br>方法or属性：function setDateTime(admin: Want, time: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：9200001,9200002,201,401|类名：dateTimeManager;<br>方法or属性：function setDateTime(admin: Want, time: number, callback: AsyncCallback\<void>): void;<br>新版本信息：9200001,9200002,201,202,401|@ohos.enterprise.dateTimeManager.d.ts|
|错误码有变化|类名：dateTimeManager;<br>方法or属性：function setDateTime(admin: Want, time: number): Promise\<void>;<br>旧版本信息：9200001,9200002,201,401|类名：dateTimeManager;<br>方法or属性：function setDateTime(admin: Want, time: number): Promise\<void>;<br>新版本信息：9200001,9200002,201,202,401|@ohos.enterprise.dateTimeManager.d.ts|
|访问级别有变化|类名：configPolicy;<br>方法or属性：function getOneCfgFile(relPath: string): Promise\<string>;<br>旧版本信息：|类名：configPolicy;<br>方法or属性：function getOneCfgFile(relPath: string): Promise\<string>;<br>新版本信息：systemapi|@ohos.configPolicy.d.ts|
|访问级别有变化|类名：configPolicy;<br>方法or属性：function getCfgFiles(relPath: string): Promise\<Array\<string>>;<br>旧版本信息：|类名：configPolicy;<br>方法or属性：function getCfgFiles(relPath: string): Promise\<Array\<string>>;<br>新版本信息：systemapi|@ohos.configPolicy.d.ts|
|访问级别有变化|类名：configPolicy;<br>方法or属性：function getCfgDirList(): Promise\<Array\<string>>;<br>旧版本信息：|类名：configPolicy;<br>方法or属性：function getCfgDirList(): Promise\<Array\<string>>;<br>新版本信息：systemapi|@ohos.configPolicy.d.ts|
|访问级别有变化|类名：EnterpriseInfo;<br>方法or属性：name: string;<br>旧版本信息：|类名：EnterpriseInfo;<br>方法or属性：name: string;<br>新版本信息：systemapi|@ohos.enterprise.adminManager.d.ts|
|访问级别有变化|类名：EnterpriseInfo;<br>方法or属性：description: string;<br>旧版本信息：|类名：EnterpriseInfo;<br>方法or属性：description: string;<br>新版本信息：systemapi|@ohos.enterprise.adminManager.d.ts|
|访问级别有变化|类名：AdminType;<br>方法or属性：ADMIN_TYPE_NORMAL = 0x00<br>旧版本信息：|类名：AdminType;<br>方法or属性：ADMIN_TYPE_NORMAL = 0x00<br>新版本信息：systemapi|@ohos.enterprise.adminManager.d.ts|
|访问级别有变化|类名：AdminType;<br>方法or属性：ADMIN_TYPE_SUPER = 0x01<br>旧版本信息：|类名：AdminType;<br>方法or属性：ADMIN_TYPE_SUPER = 0x01<br>新版本信息：systemapi|@ohos.enterprise.adminManager.d.ts|
|访问级别有变化|类名：ManagedEvent;<br>方法or属性：MANAGED_EVENT_BUNDLE_ADDED = 0<br>旧版本信息：|类名：ManagedEvent;<br>方法or属性：MANAGED_EVENT_BUNDLE_ADDED = 0<br>新版本信息：systemapi|@ohos.enterprise.adminManager.d.ts|
|访问级别有变化|类名：ManagedEvent;<br>方法or属性：MANAGED_EVENT_BUNDLE_REMOVED = 1<br>旧版本信息：|类名：ManagedEvent;<br>方法or属性：MANAGED_EVENT_BUNDLE_REMOVED = 1<br>新版本信息：systemapi|@ohos.enterprise.adminManager.d.ts|
