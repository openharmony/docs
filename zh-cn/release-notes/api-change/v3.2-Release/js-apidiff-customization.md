| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|模块名: ohos.enterprise.adminManager<br>类名: adminManager|@ohos.enterprise.adminManager.d.ts|
|新增|NA|模块名: ohos.enterprise.adminManager<br>类名: EnterpriseInfo|@ohos.enterprise.adminManager.d.ts|
|新增|NA|模块名: ohos.enterprise.adminManager<br>类名: EnterpriseInfo<br>方法 or 属性: name: string;|@ohos.enterprise.adminManager.d.ts|
|新增|NA|模块名: ohos.enterprise.adminManager<br>类名: EnterpriseInfo<br>方法 or 属性: description: string;|@ohos.enterprise.adminManager.d.ts|
|新增|NA|模块名: ohos.enterprise.adminManager<br>类名: AdminType|@ohos.enterprise.adminManager.d.ts|
|新增|NA|模块名: ohos.enterprise.adminManager<br>类名: AdminType<br>方法 or 属性: ADMIN_TYPE_NORMAL = 0x00|@ohos.enterprise.adminManager.d.ts|
|新增|NA|模块名: ohos.enterprise.adminManager<br>类名: AdminType<br>方法 or 属性: ADMIN_TYPE_SUPER = 0x01|@ohos.enterprise.adminManager.d.ts|
|新增|NA|模块名: ohos.enterprise.adminManager<br>类名: ManagedEvent|@ohos.enterprise.adminManager.d.ts|
|新增|NA|模块名: ohos.enterprise.adminManager<br>类名: ManagedEvent<br>方法 or 属性: MANAGED_EVENT_BUNDLE_ADDED = 0|@ohos.enterprise.adminManager.d.ts|
|新增|NA|模块名: ohos.enterprise.adminManager<br>类名: ManagedEvent<br>方法 or 属性: MANAGED_EVENT_BUNDLE_REMOVED = 1|@ohos.enterprise.adminManager.d.ts|
|新增|NA|模块名: ohos.enterprise.adminManager<br>类名: adminManager<br>方法 or 属性: function enableAdmin(admin: Want, enterpriseInfo: EnterpriseInfo, type: AdminType, callback: AsyncCallback\<void>): void;|@ohos.enterprise.adminManager.d.ts|
|新增|NA|模块名: ohos.enterprise.adminManager<br>类名: adminManager<br>方法 or 属性: function enableAdmin(admin: Want, enterpriseInfo: EnterpriseInfo, type: AdminType, userId: number, callback: AsyncCallback\<void>): void;|@ohos.enterprise.adminManager.d.ts|
|新增|NA|模块名: ohos.enterprise.adminManager<br>类名: adminManager<br>方法 or 属性: function enableAdmin(admin: Want, enterpriseInfo: EnterpriseInfo, type: AdminType, userId?: number): Promise\<void>;|@ohos.enterprise.adminManager.d.ts|
|新增|NA|模块名: ohos.enterprise.adminManager<br>类名: adminManager<br>方法 or 属性: function disableAdmin(admin: Want, callback: AsyncCallback\<void>): void;|@ohos.enterprise.adminManager.d.ts|
|新增|NA|模块名: ohos.enterprise.adminManager<br>类名: adminManager<br>方法 or 属性: function disableAdmin(admin: Want, userId: number, callback: AsyncCallback\<void>): void;|@ohos.enterprise.adminManager.d.ts|
|新增|NA|模块名: ohos.enterprise.adminManager<br>类名: adminManager<br>方法 or 属性: function disableAdmin(admin: Want, userId?: number): Promise\<void>;|@ohos.enterprise.adminManager.d.ts|
|新增|NA|模块名: ohos.enterprise.adminManager<br>类名: adminManager<br>方法 or 属性: function disableSuperAdmin(bundleName: String, callback: AsyncCallback\<void>): void;|@ohos.enterprise.adminManager.d.ts|
|新增|NA|模块名: ohos.enterprise.adminManager<br>类名: adminManager<br>方法 or 属性: function disableSuperAdmin(bundleName: String): Promise\<void>;|@ohos.enterprise.adminManager.d.ts|
|新增|NA|模块名: ohos.enterprise.adminManager<br>类名: adminManager<br>方法 or 属性: function isAdminEnabled(admin: Want, callback: AsyncCallback\<boolean>): void;|@ohos.enterprise.adminManager.d.ts|
|新增|NA|模块名: ohos.enterprise.adminManager<br>类名: adminManager<br>方法 or 属性: function isAdminEnabled(admin: Want, userId: number, callback: AsyncCallback\<boolean>): void;|@ohos.enterprise.adminManager.d.ts|
|新增|NA|模块名: ohos.enterprise.adminManager<br>类名: adminManager<br>方法 or 属性: function isAdminEnabled(admin: Want, userId?: number): Promise\<boolean>;|@ohos.enterprise.adminManager.d.ts|
|新增|NA|模块名: ohos.enterprise.adminManager<br>类名: adminManager<br>方法 or 属性: function getEnterpriseInfo(admin: Want, callback: AsyncCallback\<EnterpriseInfo>): void;|@ohos.enterprise.adminManager.d.ts|
|新增|NA|模块名: ohos.enterprise.adminManager<br>类名: adminManager<br>方法 or 属性: function getEnterpriseInfo(admin: Want): Promise\<EnterpriseInfo>;|@ohos.enterprise.adminManager.d.ts|
|新增|NA|模块名: ohos.enterprise.adminManager<br>类名: adminManager<br>方法 or 属性: function setEnterpriseInfo(admin: Want, enterpriseInfo: EnterpriseInfo, callback: AsyncCallback\<void>): void;|@ohos.enterprise.adminManager.d.ts|
|新增|NA|模块名: ohos.enterprise.adminManager<br>类名: adminManager<br>方法 or 属性: function setEnterpriseInfo(admin: Want, enterpriseInfo: EnterpriseInfo): Promise\<void>;|@ohos.enterprise.adminManager.d.ts|
|新增|NA|模块名: ohos.enterprise.adminManager<br>类名: adminManager<br>方法 or 属性: function isSuperAdmin(bundleName: String, callback: AsyncCallback\<boolean>): void;|@ohos.enterprise.adminManager.d.ts|
|新增|NA|模块名: ohos.enterprise.adminManager<br>类名: adminManager<br>方法 or 属性: function isSuperAdmin(bundleName: String): Promise\<boolean>;|@ohos.enterprise.adminManager.d.ts|
|新增|NA|模块名: ohos.enterprise.adminManager<br>类名: adminManager<br>方法 or 属性: function subscribeManagedEvent(admin: Want, managedEvents: Array\<ManagedEvent>, callback: AsyncCallback\<void>): void;|@ohos.enterprise.adminManager.d.ts|
|新增|NA|模块名: ohos.enterprise.adminManager<br>类名: adminManager<br>方法 or 属性: function subscribeManagedEvent(admin: Want, managedEvents: Array\<ManagedEvent>): Promise\<void>;|@ohos.enterprise.adminManager.d.ts|
|新增|NA|模块名: ohos.enterprise.adminManager<br>类名: adminManager<br>方法 or 属性: function unsubscribeManagedEvent(admin: Want, managedEvents: Array\<ManagedEvent>, callback: AsyncCallback\<void>): void;|@ohos.enterprise.adminManager.d.ts|
|新增|NA|模块名: ohos.enterprise.adminManager<br>类名: adminManager<br>方法 or 属性: function unsubscribeManagedEvent(admin: Want, managedEvents: Array\<ManagedEvent>): Promise\<void>;|@ohos.enterprise.adminManager.d.ts|
|新增|NA|模块名: ohos.enterprise.dateTimeManager<br>类名: dateTimeManager|@ohos.enterprise.dateTimeManager.d.ts|
|新增|NA|模块名: ohos.enterprise.dateTimeManager<br>类名: dateTimeManager<br>方法 or 属性: function setDateTime(admin: Want, time: number, callback: AsyncCallback\<void>): void;|@ohos.enterprise.dateTimeManager.d.ts|
|新增|NA|模块名: ohos.enterprise.dateTimeManager<br>类名: dateTimeManager<br>方法 or 属性: function setDateTime(admin: Want, time: number): Promise\<void>;|@ohos.enterprise.dateTimeManager.d.ts|
|新增|NA|模块名: ohos.enterprise.EnterpriseAdminExtensionAbility<br>类名: EnterpriseAdminExtensionAbility|@ohos.enterprise.EnterpriseAdminExtensionAbility.d.ts|
|新增|NA|模块名: ohos.enterprise.EnterpriseAdminExtensionAbility<br>类名: EnterpriseAdminExtensionAbility<br>方法 or 属性: onAdminEnabled(): void;|@ohos.enterprise.EnterpriseAdminExtensionAbility.d.ts|
|新增|NA|模块名: ohos.enterprise.EnterpriseAdminExtensionAbility<br>类名: EnterpriseAdminExtensionAbility<br>方法 or 属性: onAdminDisabled(): void;|@ohos.enterprise.EnterpriseAdminExtensionAbility.d.ts|
|新增|NA|模块名: ohos.enterprise.EnterpriseAdminExtensionAbility<br>类名: EnterpriseAdminExtensionAbility<br>方法 or 属性: onBundleAdded(bundleName: string): void;|@ohos.enterprise.EnterpriseAdminExtensionAbility.d.ts|
|新增|NA|模块名: ohos.enterprise.EnterpriseAdminExtensionAbility<br>类名: EnterpriseAdminExtensionAbility<br>方法 or 属性: onBundleRemoved(bundleName: string): void;|@ohos.enterprise.EnterpriseAdminExtensionAbility.d.ts|
|访问级别有变化|类名：configPolicy<br>访问级别：公开API|类名：configPolicy<br>访问级别：系统API|@ohos.configPolicy.d.ts|
|新增(错误码)|NA|类名：configPolicy<br>方法 or 属性：function getOneCfgFile(relPath: string, callback: AsyncCallback\<string>);<br>错误码内容: 401|@ohos.configPolicy.d.ts|
|新增(错误码)|NA|类名：configPolicy<br>方法 or 属性：function getOneCfgFile(relPath: string): Promise\<string>;<br>错误码内容: 401|@ohos.configPolicy.d.ts|
|新增(错误码)|NA|类名：configPolicy<br>方法 or 属性：function getCfgFiles(relPath: string, callback: AsyncCallback\<Array\<string>>);<br>错误码内容: 401|@ohos.configPolicy.d.ts|
|新增(错误码)|NA|类名：configPolicy<br>方法 or 属性：function getCfgFiles(relPath: string): Promise\<Array\<string>>;<br>错误码内容: 401|@ohos.configPolicy.d.ts|
|新增(错误码)|NA|类名：configPolicy<br>方法 or 属性：function getCfgDirList(callback: AsyncCallback\<Array\<string>>);<br>错误码内容: 401|@ohos.configPolicy.d.ts|
|新增(错误码)|NA|类名：configPolicy<br>方法 or 属性：function getCfgDirList(): Promise\<Array\<string>>;<br>错误码内容: 401|@ohos.configPolicy.d.ts|
