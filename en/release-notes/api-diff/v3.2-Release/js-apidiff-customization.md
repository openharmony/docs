| Change Type | Old Version | New Version | d.ts File |
| ---- | ------ | ------ | -------- |
|Added|NA|Class name: adminManager;<br>Method or attribute name: function enableAdmin(admin: Want, enterpriseInfo: EnterpriseInfo, type: AdminType, callback: AsyncCallback\<void>): void;|@ohos.enterprise.adminManager.d.ts|
|Added|NA|Class name: adminManager;<br>Method or attribute name: function enableAdmin(admin: Want, enterpriseInfo: EnterpriseInfo, type: AdminType, userId: number, callback: AsyncCallback\<void>): void;|@ohos.enterprise.adminManager.d.ts|
|Added|NA|Class name: adminManager;<br>Method or attribute name: function enableAdmin(admin: Want, enterpriseInfo: EnterpriseInfo, type: AdminType, userId?: number): Promise\<void>;|@ohos.enterprise.adminManager.d.ts|
|Added|NA|Class name: adminManager;<br>Method or attribute name: function disableAdmin(admin: Want, callback: AsyncCallback\<void>): void;|@ohos.enterprise.adminManager.d.ts|
|Added|NA|Class name: adminManager;<br>Method or attribute name: function disableAdmin(admin: Want, userId: number, callback: AsyncCallback\<void>): void;|@ohos.enterprise.adminManager.d.ts|
|Added|NA|Class name: adminManager;<br>Method or attribute name: function disableAdmin(admin: Want, userId?: number): Promise\<void>;|@ohos.enterprise.adminManager.d.ts|
|Added|NA|Class name: adminManager;<br>Method or attribute name: function disableSuperAdmin(bundleName: String, callback: AsyncCallback\<void>): void;|@ohos.enterprise.adminManager.d.ts|
|Added|NA|Class name: adminManager;<br>Method or attribute name: function disableSuperAdmin(bundleName: String): Promise\<void>;|@ohos.enterprise.adminManager.d.ts|
|Added|NA|Class name: adminManager;<br>Method or attribute name: function isAdminEnabled(admin: Want, callback: AsyncCallback\<boolean>): void;|@ohos.enterprise.adminManager.d.ts|
|Added|NA|Class name: adminManager;<br>Method or attribute name: function isAdminEnabled(admin: Want, userId: number, callback: AsyncCallback\<boolean>): void;|@ohos.enterprise.adminManager.d.ts|
|Added|NA|Class name: adminManager;<br>Method or attribute name: function isAdminEnabled(admin: Want, userId?: number): Promise\<boolean>;|@ohos.enterprise.adminManager.d.ts|
|Added|NA|Class name: adminManager;<br>Method or attribute name: function getEnterpriseInfo(admin: Want, callback: AsyncCallback\<EnterpriseInfo>): void;|@ohos.enterprise.adminManager.d.ts|
|Added|NA|Class name: adminManager;<br>Method or attribute name: function getEnterpriseInfo(admin: Want): Promise\<EnterpriseInfo>;|@ohos.enterprise.adminManager.d.ts|
|Added|NA|Class name: adminManager;<br>Method or attribute name: function setEnterpriseInfo(admin: Want, enterpriseInfo: EnterpriseInfo, callback: AsyncCallback\<void>): void;|@ohos.enterprise.adminManager.d.ts|
|Added|NA|Class name: adminManager;<br>Method or attribute name: function setEnterpriseInfo(admin: Want, enterpriseInfo: EnterpriseInfo): Promise\<void>;|@ohos.enterprise.adminManager.d.ts|
|Added|NA|Class name: adminManager;<br>Method or attribute name: function isSuperAdmin(bundleName: String, callback: AsyncCallback\<boolean>): void;|@ohos.enterprise.adminManager.d.ts|
|Added|NA|Class name: adminManager;<br>Method or attribute name: function isSuperAdmin(bundleName: String): Promise\<boolean>;|@ohos.enterprise.adminManager.d.ts|
|Added|NA|Class name: adminManager;<br>Method or attribute name: function subscribeManagedEvent(admin: Want, managedEvents: Array\<ManagedEvent>, callback: AsyncCallback\<void>): void;|@ohos.enterprise.adminManager.d.ts|
|Added|NA|Class name: adminManager;<br>Method or attribute name: function subscribeManagedEvent(admin: Want, managedEvents: Array\<ManagedEvent>): Promise\<void>;|@ohos.enterprise.adminManager.d.ts|
|Added|NA|Class name: adminManager;<br>Method or attribute name: function unsubscribeManagedEvent(admin: Want, managedEvents: Array\<ManagedEvent>, callback: AsyncCallback\<void>): void;|@ohos.enterprise.adminManager.d.ts|
|Added|NA|Class name: adminManager;<br>Method or attribute name: function unsubscribeManagedEvent(admin: Want, managedEvents: Array\<ManagedEvent>): Promise\<void>;|@ohos.enterprise.adminManager.d.ts|
|Added|NA|Class name: EnterpriseInfo;<br>Method or attribute name: name: string;|@ohos.enterprise.adminManager.d.ts|
|Added|NA|Class name: EnterpriseInfo;<br>Method or attribute name: description: string;|@ohos.enterprise.adminManager.d.ts|
|Added|NA|Class name: AdminType;<br>Method or attribute name: ADMIN_TYPE_NORMAL = 0x00|@ohos.enterprise.adminManager.d.ts|
|Added|NA|Class name: AdminType;<br>Method or attribute name: ADMIN_TYPE_SUPER = 0x01|@ohos.enterprise.adminManager.d.ts|
|Added|NA|Class name: ManagedEvent;<br>Method or attribute name: MANAGED_EVENT_BUNDLE_ADDED = 0|@ohos.enterprise.adminManager.d.ts|
|Added|NA|Class name: ManagedEvent;<br>Method or attribute name: MANAGED_EVENT_BUNDLE_REMOVED = 1|@ohos.enterprise.adminManager.d.ts|
|Added|NA|Class name: dateTimeManager;<br>Method or attribute name: function setDateTime(admin: Want, time: number, callback: AsyncCallback\<void>): void;|@ohos.enterprise.dateTimeManager.d.ts|
|Added|NA|Class name: dateTimeManager;<br>Method or attribute name: function setDateTime(admin: Want, time: number): Promise\<void>;|@ohos.enterprise.dateTimeManager.d.ts|
|Added|NA|Class name: EnterpriseAdminExtensionAbility;<br>Method or attribute name: onAdminEnabled(): void;|@ohos.enterprise.EnterpriseAdminExtensionAbility.d.ts|
|Added|NA|Class name: EnterpriseAdminExtensionAbility;<br>Method or attribute name: onAdminDisabled(): void;|@ohos.enterprise.EnterpriseAdminExtensionAbility.d.ts|
|Added|NA|Class name: EnterpriseAdminExtensionAbility;<br>Method or attribute name: onBundleAdded(bundleName: string): void;|@ohos.enterprise.EnterpriseAdminExtensionAbility.d.ts|
|Added|NA|Class name: EnterpriseAdminExtensionAbility;<br>Method or attribute name: onBundleRemoved(bundleName: string): void;|@ohos.enterprise.EnterpriseAdminExtensionAbility.d.ts|
|Error code added|Class name: configPolicy;<br>Method or attribute name: function getOneCfgFile(relPath: string, callback: AsyncCallback\<string>);<br>Old version: |Class name: configPolicy;<br>Method or attribute name: function getOneCfgFile(relPath: string, callback: AsyncCallback\<string>);<br>New version: 401|@ohos.configPolicy.d.ts|
|Error code added|Class name: configPolicy;<br>Method or attribute name: function getOneCfgFile(relPath: string): Promise\<string>;<br>Old version: |Class name: configPolicy;<br>Method or attribute name: function getOneCfgFile(relPath: string): Promise\<string>;<br>New version: 401|@ohos.configPolicy.d.ts|
|Error code added|Class name: configPolicy;<br>Method or attribute name: function getCfgFiles(relPath: string, callback: AsyncCallback\<Array\<string>>);<br>Old version: |Class name: configPolicy;<br>Method or attribute name: function getCfgFiles(relPath: string, callback: AsyncCallback\<Array\<string>>);<br>New version: 401|@ohos.configPolicy.d.ts|
|Error code added|Class name: configPolicy;<br>Method or attribute name: function getCfgFiles(relPath: string): Promise\<Array\<string>>;<br>Old version: |Class name: configPolicy;<br>Method or attribute name: function getCfgFiles(relPath: string): Promise\<Array\<string>>;<br>New version: 401|@ohos.configPolicy.d.ts|
|Error code added|Class name: configPolicy;<br>Method or attribute name: function getCfgDirList(callback: AsyncCallback\<Array\<string>>);<br>Old version: |Class name: configPolicy;<br>Method or attribute name: function getCfgDirList(callback: AsyncCallback\<Array\<string>>);<br>New version: 401|@ohos.configPolicy.d.ts|
|Error code added|Class name: configPolicy;<br>Method or attribute name: function getCfgDirList(): Promise\<Array\<string>>;<br>Old version: |Class name: configPolicy;<br>Method or attribute name: function getCfgDirList(): Promise\<Array\<string>>;<br>New version: 401|@ohos.configPolicy.d.ts|
|Access level changed|Class name: configPolicy;<br>Method or attribute name: declare configPolicy<br>Old version: |Class name: configPolicy;<br>Method or attribute name: declare configPolicy<br>New version: systemapi|@ohos.configPolicy.d.ts|
