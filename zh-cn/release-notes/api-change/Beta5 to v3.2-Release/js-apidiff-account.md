| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|类名：Authenticator<br>方法or属性：checkAccountRemovable(name: string, callback: AuthCallback): void;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AccountManager<br>方法or属性：checkOsAccountConstraintEnabled(localId: number, constraint: string, callback: AsyncCallback\<boolean>): void;|@ohos.account.osAccount.d.ts|
|新增|NA|类名：AccountManager<br>方法or属性：checkOsAccountConstraintEnabled(localId: number, constraint: string): Promise\<boolean>;|@ohos.account.osAccount.d.ts|
|新增|NA|类名：AccountManager<br>方法or属性：getOsAccountLocalId(callback: AsyncCallback\<number>): void;|@ohos.account.osAccount.d.ts|
|新增|NA|类名：AccountManager<br>方法or属性：getOsAccountLocalId(): Promise\<number>;|@ohos.account.osAccount.d.ts|
|新增|NA|类名：AccountManager<br>方法or属性：getOsAccountLocalIdForUid(uid: number, callback: AsyncCallback\<number>): void;|@ohos.account.osAccount.d.ts|
|新增|NA|类名：AccountManager<br>方法or属性：getOsAccountLocalIdForUid(uid: number): Promise\<number>;|@ohos.account.osAccount.d.ts|
|新增|NA|类名：AccountManager<br>方法or属性：getOsAccountLocalIdForDomain(domainInfo: DomainAccountInfo, callback: AsyncCallback\<number>): void;|@ohos.account.osAccount.d.ts|
|新增|NA|类名：AccountManager<br>方法or属性：getOsAccountLocalIdForDomain(domainInfo: DomainAccountInfo): Promise\<number>;|@ohos.account.osAccount.d.ts|
|新增|NA|类名：AccountManager<br>方法or属性：getActivatedOsAccountLocalIds(callback: AsyncCallback\<Array\<number>>): void;|@ohos.account.osAccount.d.ts|
|新增|NA|类名：AccountManager<br>方法or属性：getActivatedOsAccountLocalIds(): Promise\<Array\<number>>;|@ohos.account.osAccount.d.ts|
|新增|NA|类名：AccountManager<br>方法or属性：getOsAccountLocalIdForSerialNumber(serialNumber: number, callback: AsyncCallback\<number>): void;|@ohos.account.osAccount.d.ts|
|新增|NA|类名：AccountManager<br>方法or属性：getOsAccountLocalIdForSerialNumber(serialNumber: number): Promise\<number>;|@ohos.account.osAccount.d.ts|
|新增|NA|类名：AccountManager<br>方法or属性：getSerialNumberForOsAccountLocalId(localId: number, callback: AsyncCallback\<number>): void;|@ohos.account.osAccount.d.ts|
|新增|NA|类名：AccountManager<br>方法or属性：getSerialNumberForOsAccountLocalId(localId: number): Promise\<number>;|@ohos.account.osAccount.d.ts|
|新增|NA|类名：AccountManager<br>方法or属性：getBundleIdForUid(uid: number, callback: AsyncCallback\<number>): void;|@ohos.account.osAccount.d.ts|
|新增|NA|类名：AccountManager<br>方法or属性：getBundleIdForUid(uid: number): Promise\<number>;|@ohos.account.osAccount.d.ts|
|新增|NA|类名：AccountManager<br>方法or属性：getOsAccountConstraintSourceTypes(localId: number, constraint: string, callback: AsyncCallback\<Array\<ConstraintSourceTypeInfo>>): void;|@ohos.account.osAccount.d.ts|
|新增|NA|类名：AccountManager<br>方法or属性：getOsAccountConstraintSourceTypes(localId: number, constraint: string): Promise\<Array\<ConstraintSourceTypeInfo>>;|@ohos.account.osAccount.d.ts|
|删除|模块名: ohos.account.appAccount<br>类名: OAuthTokenInfo<br>方法 or 属性：account?: AppAccountInfo;|NA|@ohos.account.appAccount.d.ts|
|删除|模块名: ohos.account.appAccount<br>类名: AuthenticatorCallback<br>方法 or 属性：onRequestContinued?: () => void;|NA|@ohos.account.appAccount.d.ts|
|删除|模块名：ohos.account.appAccount<br>类名:Authenticator<br>方法 or 属性:isAccountRemovable(name: string, callback: AuthCallback): void;|NA|@ohos.account.appAccount.d.ts|
|删除|模块名：ohos.account.osAccount<br>类名:AccountManager<br>方法 or 属性:checkConstraintEnabled(localId: number, constraint: string, callback: AsyncCallback\<boolean>): void;|NA|@ohos.account.osAccount.d.ts|
|删除|模块名：ohos.account.osAccount<br>类名:AccountManager<br>方法 or 属性:checkConstraintEnabled(localId: number, constraint: string): Promise\<boolean>;|NA|@ohos.account.osAccount.d.ts|
|删除|模块名：ohos.account.osAccount<br>类名:AccountManager<br>方法 or 属性:queryOsAccountLocalIdFromProcess(callback: AsyncCallback\<number>): void;|NA|@ohos.account.osAccount.d.ts|
|删除|模块名：ohos.account.osAccount<br>类名:AccountManager<br>方法 or 属性:queryOsAccountLocalIdFromProcess(): Promise\<number>;|NA|@ohos.account.osAccount.d.ts|
|删除|模块名：ohos.account.osAccount<br>类名:AccountManager<br>方法 or 属性:queryOsAccountLocalIdFromUid(uid: number, callback: AsyncCallback\<number>): void;|NA|@ohos.account.osAccount.d.ts|
|删除|模块名：ohos.account.osAccount<br>类名:AccountManager<br>方法 or 属性:queryOsAccountLocalIdFromUid(uid: number): Promise\<number>;|NA|@ohos.account.osAccount.d.ts|
|删除|模块名：ohos.account.osAccount<br>类名:AccountManager<br>方法 or 属性:queryOsAccountLocalIdFromDomain(domainInfo: DomainAccountInfo, callback: AsyncCallback\<number>): void;|NA|@ohos.account.osAccount.d.ts|
|删除|模块名：ohos.account.osAccount<br>类名:AccountManager<br>方法 or 属性:queryOsAccountLocalIdFromDomain(domainInfo: DomainAccountInfo): Promise\<number>;|NA|@ohos.account.osAccount.d.ts|
|删除|模块名：ohos.account.osAccount<br>类名:AccountManager<br>方法 or 属性:getActivatedOsAccountIds(callback: AsyncCallback\<Array\<number>>): void;|NA|@ohos.account.osAccount.d.ts|
|删除|模块名：ohos.account.osAccount<br>类名:AccountManager<br>方法 or 属性:getActivatedOsAccountIds(): Promise\<Array\<number>>;|NA|@ohos.account.osAccount.d.ts|
|删除|模块名：ohos.account.osAccount<br>类名:AccountManager<br>方法 or 属性:queryOsAccountLocalIdBySerialNumber(serialNumber: number, callback: AsyncCallback\<number>): void;|NA|@ohos.account.osAccount.d.ts|
|删除|模块名：ohos.account.osAccount<br>类名:AccountManager<br>方法 or 属性:queryOsAccountLocalIdBySerialNumber(serialNumber: number): Promise\<number>;|NA|@ohos.account.osAccount.d.ts|
|删除|模块名：ohos.account.osAccount<br>类名:AccountManager<br>方法 or 属性:querySerialNumberByOsAccountLocalId(localId: number, callback: AsyncCallback\<number>): void;|NA|@ohos.account.osAccount.d.ts|
|删除|模块名：ohos.account.osAccount<br>类名:AccountManager<br>方法 or 属性:querySerialNumberByOsAccountLocalId(localId: number): Promise\<number>;|NA|@ohos.account.osAccount.d.ts|
|删除|模块名：ohos.account.osAccount<br>类名:AccountManager<br>方法 or 属性:getBundleIdFromUid(uid: number, callback: AsyncCallback\<number>): void;|NA|@ohos.account.osAccount.d.ts|
|删除|模块名：ohos.account.osAccount<br>类名:AccountManager<br>方法 or 属性:getBundleIdFromUid(uid: number): Promise\<number>;|NA|@ohos.account.osAccount.d.ts|
|删除|模块名：ohos.account.osAccount<br>类名:AccountManager<br>方法 or 属性:queryOsAccountConstraintSourceTypes(localId: number, constraint: string, callback: AsyncCallback\<Array\<ConstraintSourceTypeInfo>>): void;|NA|@ohos.account.osAccount.d.ts|
|删除|模块名：ohos.account.osAccount<br>类名:AccountManager<br>方法 or 属性:queryOsAccountConstraintSourceTypes(localId: number, constraint: string): Promise\<Array\<ConstraintSourceTypeInfo>>;|NA|@ohos.account.osAccount.d.ts|
|起始版本有变化|类名：ConstraintSourceType<br>方法 or 属性：CONSTRAINT_NOT_EXIST = 0<br>起始版本：N/A|类名：ConstraintSourceType<br>方法 or 属性：CONSTRAINT_NOT_EXIST = 0<br>起始版本：9|@ohos.account.osAccount.d.ts|
|起始版本有变化|类名：ConstraintSourceType<br>方法 or 属性：CONSTRAINT_TYPE_BASE = 1<br>起始版本：N/A|类名：ConstraintSourceType<br>方法 or 属性：CONSTRAINT_TYPE_BASE = 1<br>起始版本：9|@ohos.account.osAccount.d.ts|
|起始版本有变化|类名：ConstraintSourceType<br>方法 or 属性：CONSTRAINT_TYPE_DEVICE_OWNER = 2<br>起始版本：N/A|类名：ConstraintSourceType<br>方法 or 属性：CONSTRAINT_TYPE_DEVICE_OWNER = 2<br>起始版本：9|@ohos.account.osAccount.d.ts|
|起始版本有变化|类名：ConstraintSourceType<br>方法 or 属性：CONSTRAINT_TYPE_PROFILE_OWNER = 3<br>起始版本：N/A|类名：ConstraintSourceType<br>方法 or 属性：CONSTRAINT_TYPE_PROFILE_OWNER = 3<br>起始版本：9|@ohos.account.osAccount.d.ts|
|起始版本有变化|类名：ConstraintSourceTypeInfo<br>方法 or 属性：localId: number;<br>起始版本：N/A|类名：ConstraintSourceTypeInfo<br>方法 or 属性：localId: number;<br>起始版本：9|@ohos.account.osAccount.d.ts|
|起始版本有变化|类名：ConstraintSourceTypeInfo<br>方法 or 属性：type: ConstraintSourceType;<br>起始版本：N/A|类名：ConstraintSourceTypeInfo<br>方法 or 属性：type: ConstraintSourceType;<br>起始版本：9|@ohos.account.osAccount.d.ts|
|删除(权限)|类名：AccountManager<br>方法 or 属性：checkOsAccountVerified(callback: AsyncCallback\<boolean>): void;<br>权限:ohos.permission.MANAGE_LOCAL_ACCOUNTS or ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS|类名：AccountManager<br>方法 or 属性：checkOsAccountVerified(callback: AsyncCallback\<boolean>): void;<br>权限:N/A|@ohos.account.osAccount.d.ts|
|新增(错误码)|NA|类名：PINAuth<br>方法 or 属性：unregisterInputer(): void;<br>错误码内容: 201|@ohos.account.osAccount.d.ts|
|新增(错误码)|NA|类名：UserIdentityManager<br>方法 or 属性：closeSession(): void;<br>错误码内容: 201|@ohos.account.osAccount.d.ts|
|函数有变化|类名：AccountManager<br>方法 or 属性：checkOsAccountVerified(localId?: number): Promise\<boolean>;<br>|类名：AccountManager<br>方法 or 属性：checkOsAccountVerified(): Promise\<boolean>;<br>|@ohos.account.osAccount.d.ts|
|函数有变化|类名：AccountManager<br>方法 or 属性：checkOsAccountVerified(localId?: number): Promise\<boolean>;<br>|类名：AccountManager<br>方法 or 属性：checkOsAccountVerified(localId: number): Promise\<boolean>;<br>|@ohos.account.osAccount.d.ts|
|函数有变化|类名：IInputData<br>方法 or 属性：onSetData: (pinSubType: AuthSubType, data: Uint8Array) => void;<br>|类名：IInputData<br>方法 or 属性：onSetData: (authSubType: AuthSubType, data: Uint8Array) => void;<br>|@ohos.account.osAccount.d.ts|
|函数有变化|类名：IInputer<br>方法 or 属性：onGetData: (pinSubType: AuthSubType, callback: IInputData) => void;<br>|类名：IInputer<br>方法 or 属性：onGetData: (authSubType: AuthSubType, callback: IInputData) => void;<br>|@ohos.account.osAccount.d.ts|
