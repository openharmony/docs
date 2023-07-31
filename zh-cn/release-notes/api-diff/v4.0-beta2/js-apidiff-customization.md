| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|类名：browser;<br>方法or属性：function setPolicies(admin: Want, appId: string, policies: string, callback: AsyncCallback\<void>): void;|@ohos.enterprise.browser.d.ts|
|新增|NA|类名：browser;<br>方法or属性：function setPolicies(admin: Want, appId: string, policies: string): Promise\<void>;|@ohos.enterprise.browser.d.ts|
|新增|NA|类名：browser;<br>方法or属性：function getPolicies(admin: Want, appId: string, callback: AsyncCallback\<string>): void;|@ohos.enterprise.browser.d.ts|
|新增|NA|类名：browser;<br>方法or属性：function getPolicies(admin: Want, appId: string): Promise\<string>;|@ohos.enterprise.browser.d.ts|
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
|新增|NA|类名：deviceSettings;<br>方法or属性：function getScreenOffTime(admin: Want, callback: AsyncCallback\<number>): void;|@ohos.enterprise.deviceSettings.d.ts|
|新增|NA|类名：deviceSettings;<br>方法or属性：function getScreenOffTime(admin: Want): Promise\<number>;|@ohos.enterprise.deviceSettings.d.ts|
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
