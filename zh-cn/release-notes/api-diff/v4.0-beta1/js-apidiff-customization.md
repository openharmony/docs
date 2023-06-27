| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|模块名: ohos.enterprise.accountManager<br>类名: accountManager|@ohos.enterprise.accountManager.d.ts|
|新增|NA|模块名: ohos.enterprise.accountManager<br>类名: accountManager<br>方法 or 属性: function disallowAddLocalAccount(admin: Want, disallow: boolean, callback: AsyncCallback\<void>): void;|@ohos.enterprise.accountManager.d.ts|
|新增|NA|模块名: ohos.enterprise.accountManager<br>类名: accountManager<br>方法 or 属性: function disallowAddLocalAccount(admin: Want, disallow: boolean): Promise\<void>;|@ohos.enterprise.accountManager.d.ts|
|新增|NA|类名：ManagedEvent<br>方法or属性：MANAGED_EVENT_APP_START = 2|@ohos.enterprise.adminManager.d.ts|
|新增|NA|类名：ManagedEvent<br>方法or属性：MANAGED_EVENT_APP_STOP = 3|@ohos.enterprise.adminManager.d.ts|
|新增|NA|模块名: ohos.enterprise.applicationManager<br>类名: applicationManager|@ohos.enterprise.applicationManager.d.ts|
|新增|NA|模块名: ohos.enterprise.applicationManager<br>类名: applicationManager<br>方法 or 属性: function addDisallowedRunningBundles(admin: Want, appIds: Array\<string>, callback: AsyncCallback\<void>): void;|@ohos.enterprise.applicationManager.d.ts|
|新增|NA|模块名: ohos.enterprise.applicationManager<br>类名: applicationManager<br>方法 or 属性: function addDisallowedRunningBundles(admin: Want, appIds: Array\<string>, userId: number, callback: AsyncCallback\<void>): void;|@ohos.enterprise.applicationManager.d.ts|
|新增|NA|模块名: ohos.enterprise.applicationManager<br>类名: applicationManager<br>方法 or 属性: function addDisallowedRunningBundles(admin: Want, appIds: Array\<string>, userId?: number): Promise\<void>;|@ohos.enterprise.applicationManager.d.ts|
|新增|NA|模块名: ohos.enterprise.applicationManager<br>类名: applicationManager<br>方法 or 属性: function removeDisallowedRunningBundles(admin: Want, appIds: Array\<string>, callback: AsyncCallback\<void>): void;|@ohos.enterprise.applicationManager.d.ts|
|新增|NA|模块名: ohos.enterprise.applicationManager<br>类名: applicationManager<br>方法 or 属性: function removeDisallowedRunningBundles(admin: Want, appIds: Array\<string>, userId: number, callback: AsyncCallback\<void>): void;|@ohos.enterprise.applicationManager.d.ts|
|新增|NA|模块名: ohos.enterprise.applicationManager<br>类名: applicationManager<br>方法 or 属性: function removeDisallowedRunningBundles(admin: Want, appIds: Array\<string>, userId?: number): Promise\<void>;|@ohos.enterprise.applicationManager.d.ts|
|新增|NA|模块名: ohos.enterprise.applicationManager<br>类名: applicationManager<br>方法 or 属性: function getDisallowedRunningBundles(admin: Want, callback: AsyncCallback\<Array\<string>>): void;|@ohos.enterprise.applicationManager.d.ts|
|新增|NA|模块名: ohos.enterprise.applicationManager<br>类名: applicationManager<br>方法 or 属性: function getDisallowedRunningBundles(admin: Want, userId: number, callback: AsyncCallback\<Array\<string>>): void;|@ohos.enterprise.applicationManager.d.ts|
|新增|NA|模块名: ohos.enterprise.applicationManager<br>类名: applicationManager<br>方法 or 属性: function getDisallowedRunningBundles(admin: Want, userId?: number): Promise\<Array\<string>>;|@ohos.enterprise.applicationManager.d.ts|
|新增|NA|模块名: ohos.enterprise.bundleManager<br>类名: bundleManager|@ohos.enterprise.bundleManager.d.ts|
|新增|NA|模块名: ohos.enterprise.bundleManager<br>类名: bundleManager<br>方法 or 属性: function addAllowedInstallBundles(admin: Want, appIds: Array\<string>, callback: AsyncCallback\<void>): void;|@ohos.enterprise.bundleManager.d.ts|
|新增|NA|模块名: ohos.enterprise.bundleManager<br>类名: bundleManager<br>方法 or 属性: function addAllowedInstallBundles(admin: Want, appIds: Array\<string>, userId: number, callback: AsyncCallback\<void>): void;|@ohos.enterprise.bundleManager.d.ts|
|新增|NA|模块名: ohos.enterprise.bundleManager<br>类名: bundleManager<br>方法 or 属性: function addAllowedInstallBundles(admin: Want, appIds: Array\<string>, userId?: number): Promise\<void>;|@ohos.enterprise.bundleManager.d.ts|
|新增|NA|模块名: ohos.enterprise.bundleManager<br>类名: bundleManager<br>方法 or 属性: function removeAllowedInstallBundles(admin: Want, appIds: Array\<string>, callback: AsyncCallback\<void>): void;|@ohos.enterprise.bundleManager.d.ts|
|新增|NA|模块名: ohos.enterprise.bundleManager<br>类名: bundleManager<br>方法 or 属性: function removeAllowedInstallBundles(admin: Want, appIds: Array\<string>, userId: number, callback: AsyncCallback\<void>): void;|@ohos.enterprise.bundleManager.d.ts|
|新增|NA|模块名: ohos.enterprise.bundleManager<br>类名: bundleManager<br>方法 or 属性: function removeAllowedInstallBundles(admin: Want, appIds: Array\<string>, userId?: number): Promise\<void>;|@ohos.enterprise.bundleManager.d.ts|
|新增|NA|模块名: ohos.enterprise.bundleManager<br>类名: bundleManager<br>方法 or 属性: function getAllowedInstallBundles(admin: Want, callback: AsyncCallback\<Array\<string>>): void;|@ohos.enterprise.bundleManager.d.ts|
|新增|NA|模块名: ohos.enterprise.bundleManager<br>类名: bundleManager<br>方法 or 属性: function getAllowedInstallBundles(admin: Want, userId: number, callback: AsyncCallback\<Array\<string>>): void;|@ohos.enterprise.bundleManager.d.ts|
|新增|NA|模块名: ohos.enterprise.bundleManager<br>类名: bundleManager<br>方法 or 属性: function getAllowedInstallBundles(admin: Want, userId?: number): Promise\<Array\<string>>;|@ohos.enterprise.bundleManager.d.ts|
|新增|NA|模块名: ohos.enterprise.bundleManager<br>类名: bundleManager<br>方法 or 属性: function addDisallowedInstallBundles(admin: Want, appIds: Array\<string>, callback: AsyncCallback\<void>): void;|@ohos.enterprise.bundleManager.d.ts|
|新增|NA|模块名: ohos.enterprise.bundleManager<br>类名: bundleManager<br>方法 or 属性: function addDisallowedInstallBundles(admin: Want, appIds: Array\<string>, userId: number, callback: AsyncCallback\<void>): void;|@ohos.enterprise.bundleManager.d.ts|
|新增|NA|模块名: ohos.enterprise.bundleManager<br>类名: bundleManager<br>方法 or 属性: function addDisallowedInstallBundles(admin: Want, appIds: Array\<string>, userId?: number): Promise\<void>;|@ohos.enterprise.bundleManager.d.ts|
|新增|NA|模块名: ohos.enterprise.bundleManager<br>类名: bundleManager<br>方法 or 属性: function removeDisallowedInstallBundles(admin: Want, appIds: Array\<string>, callback: AsyncCallback\<void>): void;|@ohos.enterprise.bundleManager.d.ts|
|新增|NA|模块名: ohos.enterprise.bundleManager<br>类名: bundleManager<br>方法 or 属性: function removeDisallowedInstallBundles(admin: Want, appIds: Array\<string>, userId: number, callback: AsyncCallback\<void>): void;|@ohos.enterprise.bundleManager.d.ts|
|新增|NA|模块名: ohos.enterprise.bundleManager<br>类名: bundleManager<br>方法 or 属性: function removeDisallowedInstallBundles(admin: Want, appIds: Array\<string>, userId?: number): Promise\<void>;|@ohos.enterprise.bundleManager.d.ts|
|新增|NA|模块名: ohos.enterprise.bundleManager<br>类名: bundleManager<br>方法 or 属性: function getDisallowedInstallBundles(admin: Want, callback: AsyncCallback\<Array\<string>>): void;|@ohos.enterprise.bundleManager.d.ts|
|新增|NA|模块名: ohos.enterprise.bundleManager<br>类名: bundleManager<br>方法 or 属性: function getDisallowedInstallBundles(admin: Want, userId: number, callback: AsyncCallback\<Array\<string>>): void;|@ohos.enterprise.bundleManager.d.ts|
|新增|NA|模块名: ohos.enterprise.bundleManager<br>类名: bundleManager<br>方法 or 属性: function getDisallowedInstallBundles(admin: Want, userId?: number): Promise\<Array\<string>>;|@ohos.enterprise.bundleManager.d.ts|
|新增|NA|类名：dateTimeManager<br>方法or属性：function disallowModifyDateTime(admin: Want, disallow: boolean, callback: AsyncCallback\<void>): void;|@ohos.enterprise.dateTimeManager.d.ts|
|新增|NA|类名：dateTimeManager<br>方法or属性：function disallowModifyDateTime(admin: Want, disallow: boolean): Promise\<void>;|@ohos.enterprise.dateTimeManager.d.ts|
|新增|NA|类名：dateTimeManager<br>方法or属性：function isModifyDateTimeDisallowed(admin: Want, callback: AsyncCallback\<boolean>): void;|@ohos.enterprise.dateTimeManager.d.ts|
|新增|NA|类名：dateTimeManager<br>方法or属性：function isModifyDateTimeDisallowed(admin: Want): Promise\<boolean>;|@ohos.enterprise.dateTimeManager.d.ts|
|新增|NA|模块名: ohos.enterprise.deviceControl<br>类名: deviceControl|@ohos.enterprise.deviceControl.d.ts|
|新增|NA|模块名: ohos.enterprise.deviceControl<br>类名: deviceControl<br>方法 or 属性: function resetFactory(admin: Want, callback: AsyncCallback\<void>): void;|@ohos.enterprise.deviceControl.d.ts|
|新增|NA|模块名: ohos.enterprise.deviceControl<br>类名: deviceControl<br>方法 or 属性: function resetFactory(admin: Want): Promise\<void>;|@ohos.enterprise.deviceControl.d.ts|
|新增|NA|模块名: ohos.enterprise.deviceInfo<br>类名: deviceInfo|@ohos.enterprise.deviceInfo.d.ts|
|新增|NA|模块名: ohos.enterprise.deviceInfo<br>类名: deviceInfo<br>方法 or 属性: function getDeviceSerial(admin: Want, callback: AsyncCallback\<string>): void;|@ohos.enterprise.deviceInfo.d.ts|
|新增|NA|模块名: ohos.enterprise.deviceInfo<br>类名: deviceInfo<br>方法 or 属性: function getDeviceSerial(admin: Want): Promise\<string>;|@ohos.enterprise.deviceInfo.d.ts|
|新增|NA|模块名: ohos.enterprise.deviceInfo<br>类名: deviceInfo<br>方法 or 属性: function getDisplayVersion(admin: Want, callback: AsyncCallback\<string>): void;|@ohos.enterprise.deviceInfo.d.ts|
|新增|NA|模块名: ohos.enterprise.deviceInfo<br>类名: deviceInfo<br>方法 or 属性: function getDisplayVersion(admin: Want): Promise\<string>;|@ohos.enterprise.deviceInfo.d.ts|
|新增|NA|模块名: ohos.enterprise.deviceInfo<br>类名: deviceInfo<br>方法 or 属性: function getDeviceName(admin: Want, callback: AsyncCallback\<string>): void;|@ohos.enterprise.deviceInfo.d.ts|
|新增|NA|模块名: ohos.enterprise.deviceInfo<br>类名: deviceInfo<br>方法 or 属性: function getDeviceName(admin: Want): Promise\<string>;|@ohos.enterprise.deviceInfo.d.ts|
|新增|NA|模块名: ohos.enterprise.EnterpriseAdminExtensionAbility<br>类名: EnterpriseAdminExtensionAbility<br>方法 or 属性: onAppStart(bundleName: string): void;|@ohos.enterprise.EnterpriseAdminExtensionAbility.d.ts|
|新增|NA|模块名: ohos.enterprise.EnterpriseAdminExtensionAbility<br>类名: EnterpriseAdminExtensionAbility<br>方法 or 属性: onAppStop(bundleName: string): void;|@ohos.enterprise.EnterpriseAdminExtensionAbility.d.ts|
|新增|NA|模块名: ohos.enterprise.networkManager<br>类名: networkManager|@ohos.enterprise.networkManager.d.ts|
|新增|NA|模块名: ohos.enterprise.networkManager<br>类名: networkManager<br>方法 or 属性: function getAllNetworkInterfaces(admin: Want, callback: AsyncCallback\<Array\<string>>): void;|@ohos.enterprise.networkManager.d.ts|
|新增|NA|模块名: ohos.enterprise.networkManager<br>类名: networkManager<br>方法 or 属性: function getAllNetworkInterfaces(admin: Want): Promise\<Array\<string>>;|@ohos.enterprise.networkManager.d.ts|
|新增|NA|模块名: ohos.enterprise.networkManager<br>类名: networkManager<br>方法 or 属性: function getIpAddress(admin: Want, networkInterface: string, callback: AsyncCallback\<string>): void;|@ohos.enterprise.networkManager.d.ts|
|新增|NA|模块名: ohos.enterprise.networkManager<br>类名: networkManager<br>方法 or 属性: function getIpAddress(admin: Want, networkInterface: string): Promise\<string>;|@ohos.enterprise.networkManager.d.ts|
|新增|NA|模块名: ohos.enterprise.networkManager<br>类名: networkManager<br>方法 or 属性: function getMac(admin: Want, networkInterface: string, callback: AsyncCallback\<string>): void;|@ohos.enterprise.networkManager.d.ts|
|新增|NA|模块名: ohos.enterprise.networkManager<br>类名: networkManager<br>方法 or 属性: function getMac(admin: Want, networkInterface: string): Promise\<string>;|@ohos.enterprise.networkManager.d.ts|
|新增|NA|模块名: ohos.enterprise.networkManager<br>类名: networkManager<br>方法 or 属性: function isNetworkInterfaceDisabled(admin: Want, networkInterface: string, callback: AsyncCallback\<boolean>): void;|@ohos.enterprise.networkManager.d.ts|
|新增|NA|模块名: ohos.enterprise.networkManager<br>类名: networkManager<br>方法 or 属性: function isNetworkInterfaceDisabled(admin: Want, networkInterface: string): Promise\<boolean>;|@ohos.enterprise.networkManager.d.ts|
|新增|NA|模块名: ohos.enterprise.networkManager<br>类名: networkManager<br>方法 or 属性: function setNetworkInterfaceDisabled(admin: Want, networkInterface: string, isDisabled: boolean, callback: AsyncCallback\<void>): void;|@ohos.enterprise.networkManager.d.ts|
|新增|NA|模块名: ohos.enterprise.networkManager<br>类名: networkManager<br>方法 or 属性: function setNetworkInterfaceDisabled(admin: Want, networkInterface: string, isDisabled: boolean): Promise\<void>;|@ohos.enterprise.networkManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: wifiManager|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: WifiSecurityType|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: WifiSecurityType<br>方法 or 属性: WIFI_SEC_TYPE_INVALID = 0|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: WifiSecurityType<br>方法 or 属性: WIFI_SEC_TYPE_OPEN = 1|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: WifiSecurityType<br>方法 or 属性: WIFI_SEC_TYPE_WEP = 2|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: WifiSecurityType<br>方法 or 属性: WIFI_SEC_TYPE_PSK = 3|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: WifiSecurityType<br>方法 or 属性: WIFI_SEC_TYPE_SAE = 4|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: WifiSecurityType<br>方法 or 属性: WIFI_SEC_TYPE_EAP = 5|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: WifiSecurityType<br>方法 or 属性: WIFI_SEC_TYPE_EAP_SUITE_B = 6|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: WifiSecurityType<br>方法 or 属性: WIFI_SEC_TYPE_OWE = 7|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: WifiSecurityType<br>方法 or 属性: WIFI_SEC_TYPE_WAPI_CERT = 8|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: WifiSecurityType<br>方法 or 属性: WIFI_SEC_TYPE_WAPI_PSK = 9|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: IpType|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: IpType<br>方法 or 属性: STATIC|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: IpType<br>方法 or 属性: DHCP|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: IpType<br>方法 or 属性: UNKNOWN|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: IpProfile|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: IpProfile<br>方法 or 属性: ipAddress: number;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: IpProfile<br>方法 or 属性: gateway: number;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: IpProfile<br>方法 or 属性: prefixLength: number;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: IpProfile<br>方法 or 属性: dnsServers: number[];|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: IpProfile<br>方法 or 属性: domains: Array\<string>;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: EapMethod|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: EapMethod<br>方法 or 属性: EAP_NONE|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: EapMethod<br>方法 or 属性: EAP_PEAP|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: EapMethod<br>方法 or 属性: EAP_TLS|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: EapMethod<br>方法 or 属性: EAP_TTLS|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: EapMethod<br>方法 or 属性: EAP_PWD|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: EapMethod<br>方法 or 属性: EAP_SIM|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: EapMethod<br>方法 or 属性: EAP_AKA|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: EapMethod<br>方法 or 属性: EAP_AKA_PRIME|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: EapMethod<br>方法 or 属性: EAP_UNAUTH_TLS|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: Phase2Method|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: Phase2Method<br>方法 or 属性: PHASE2_NONE|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: Phase2Method<br>方法 or 属性: PHASE2_PAP|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: Phase2Method<br>方法 or 属性: PHASE2_MSCHAP|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: Phase2Method<br>方法 or 属性: PHASE2_MSCHAPV2|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: Phase2Method<br>方法 or 属性: PHASE2_GTC|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: Phase2Method<br>方法 or 属性: PHASE2_SIM|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: Phase2Method<br>方法 or 属性: PHASE2_AKA|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: Phase2Method<br>方法 or 属性: PHASE2_AKA_PRIME|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: WifiEapProfile|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: WifiEapProfile<br>方法 or 属性: eapMethod: EapMethod;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: WifiEapProfile<br>方法 or 属性: phase2Method: Phase2Method;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: WifiEapProfile<br>方法 or 属性: identity: string;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: WifiEapProfile<br>方法 or 属性: anonymousIdentity: string;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: WifiEapProfile<br>方法 or 属性: password: string;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: WifiEapProfile<br>方法 or 属性: caCertAliases: string;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: WifiEapProfile<br>方法 or 属性: caPath: string;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: WifiEapProfile<br>方法 or 属性: clientCertAliases: string;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: WifiEapProfile<br>方法 or 属性: certEntry: Uint8Array;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: WifiEapProfile<br>方法 or 属性: certPassword: string;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: WifiEapProfile<br>方法 or 属性: altSubjectMatch: string;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: WifiEapProfile<br>方法 or 属性: domainSuffixMatch: string;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: WifiEapProfile<br>方法 or 属性: realm: string;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: WifiEapProfile<br>方法 or 属性: plmn: string;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: WifiEapProfile<br>方法 or 属性: eapSubId: number;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: WifiProfile|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: WifiProfile<br>方法 or 属性: ssid: string;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: WifiProfile<br>方法 or 属性: bssid?: string;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: WifiProfile<br>方法 or 属性: preSharedKey: string;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: WifiProfile<br>方法 or 属性: isHiddenSsid?: boolean;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: WifiProfile<br>方法 or 属性: securityType: WifiSecurityType;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: WifiProfile<br>方法 or 属性: creatorUid?: number;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: WifiProfile<br>方法 or 属性: disableReason?: number;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: WifiProfile<br>方法 or 属性: netId?: number;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: WifiProfile<br>方法 or 属性: randomMacType?: number;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: WifiProfile<br>方法 or 属性: randomMacAddr?: string;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: WifiProfile<br>方法 or 属性: ipType?: IpType;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: WifiProfile<br>方法 or 属性: staticIp?: IpProfile;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: WifiProfile<br>方法 or 属性: eapProfile?: WifiEapProfile;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: wifiManager<br>方法 or 属性: function isWifiActive(admin: Want, callback: AsyncCallback\<boolean>): void;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: wifiManager<br>方法 or 属性: function isWifiActive(admin: Want): Promise\<boolean>;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: wifiManager<br>方法 or 属性: function setWifiProfile(admin: Want, profile: WifiProfile, callback: AsyncCallback\<void>): void;|@ohos.enterprise.wifiManager.d.ts|
|新增|NA|模块名: ohos.enterprise.wifiManager<br>类名: wifiManager<br>方法 or 属性: function setWifiProfile(admin: Want, profile: WifiProfile): Promise\<void>;|@ohos.enterprise.wifiManager.d.ts|
