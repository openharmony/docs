| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|模块名: ohos.account.osAccount<br>类名: InputerManager|@ohos.account.osAccount.d.ts|
|新增|NA|模块名: ohos.account.osAccount<br>类名: InputerManager<br>方法 or 属性: static registerInputer(authType: AuthType, inputer: IInputer): void;|@ohos.account.osAccount.d.ts|
|新增|NA|模块名: ohos.account.osAccount<br>类名: InputerManager<br>方法 or 属性: static unregisterInputer(authType: AuthType): void;|@ohos.account.osAccount.d.ts|
|新增|NA|模块名: ohos.account.osAccount<br>类名: DomainPlugin|@ohos.account.osAccount.d.ts|
|新增|NA|模块名: ohos.account.osAccount<br>类名: DomainPlugin<br>方法 or 属性: auth(domainAccountInfo: DomainAccountInfo, credential: Uint8Array, callback: IUserAuthCallback): void;|@ohos.account.osAccount.d.ts|
|新增|NA|模块名: ohos.account.osAccount<br>类名: DomainAccountManager|@ohos.account.osAccount.d.ts|
|新增|NA|模块名: ohos.account.osAccount<br>类名: DomainAccountManager<br>方法 or 属性: static registerPlugin(plugin: DomainPlugin): void;|@ohos.account.osAccount.d.ts|
|新增|NA|模块名: ohos.account.osAccount<br>类名: DomainAccountManager<br>方法 or 属性: static unregisterPlugin(): void;|@ohos.account.osAccount.d.ts|
|新增|NA|模块名: ohos.account.osAccount<br>类名: AuthType<br>方法 or 属性: DOMAIN = 1024|@ohos.account.osAccount.d.ts|
|新增|NA|模块名: ohos.account.osAccount<br>类名: AuthSubType<br>方法 or 属性: DOMAIN_MIXED = 10240001|@ohos.account.osAccount.d.ts|
|删除(权限)|类名：AppAccountManager<br>方法 or 属性：getAllAccounts(callback: AsyncCallback<Array<AppAccountInfo>>): void;<br>权限:ohos.permission.GET_ALL_APP_ACCOUNTS|类名：AppAccountManager<br>方法 or 属性：getAllAccounts(callback: AsyncCallback<Array<AppAccountInfo>>): void;<br>权限:N/A|@ohos.account.appAccount.d.ts|
|删除(权限)|类名：AppAccountManager<br>方法 or 属性：getAllAccounts(): Promise<Array<AppAccountInfo>>;<br>权限:ohos.permission.GET_ALL_APP_ACCOUNTS|类名：AppAccountManager<br>方法 or 属性：getAllAccounts(): Promise<Array<AppAccountInfo>>;<br>权限:N/A|@ohos.account.appAccount.d.ts|
|删除(权限)|类名：AppAccountManager<br>方法 or 属性：getAccountsByOwner(owner: string, callback: AsyncCallback<Array<AppAccountInfo>>): void;<br>权限:ohos.permission.GET_ALL_APP_ACCOUNTS|类名：AppAccountManager<br>方法 or 属性：getAccountsByOwner(owner: string, callback: AsyncCallback<Array<AppAccountInfo>>): void;<br>权限:N/A|@ohos.account.appAccount.d.ts|
|删除(权限)|类名：AppAccountManager<br>方法 or 属性：getAccountsByOwner(owner: string): Promise<Array<AppAccountInfo>>;<br>权限:ohos.permission.GET_ALL_APP_ACCOUNTS|类名：AppAccountManager<br>方法 or 属性：getAccountsByOwner(owner: string): Promise<Array<AppAccountInfo>>;<br>权限:N/A|@ohos.account.appAccount.d.ts|
