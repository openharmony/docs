| Change Type | Old Version | New Version | d.ts File |
| ---- | ------ | ------ | -------- |
|Added|NA|Class name: browser;<br>Method or attribute name: function setPolicies(admin: Want, appId: string, policies: string, callback: AsyncCallback\<void>): void;|@ohos.enterprise.browser.d.ts|
|Added|NA|Class name: browser;<br>Method or attribute name: function setPolicies(admin: Want, appId: string, policies: string): Promise\<void>;|@ohos.enterprise.browser.d.ts|
|Added|NA|Class name: browser;<br>Method or attribute name: function getPolicies(admin: Want, appId: string, callback: AsyncCallback\<string>): void;|@ohos.enterprise.browser.d.ts|
|Added|NA|Class name: browser;<br>Method or attribute name: function getPolicies(admin: Want, appId: string): Promise\<string>;|@ohos.enterprise.browser.d.ts|
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
|Added|NA|Class name: deviceSettings;<br>Method or attribute name: function getScreenOffTime(admin: Want, callback: AsyncCallback\<number>): void;|@ohos.enterprise.deviceSettings.d.ts|
|Added|NA|Class name: deviceSettings;<br>Method or attribute name: function getScreenOffTime(admin: Want): Promise\<number>;|@ohos.enterprise.deviceSettings.d.ts|
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
