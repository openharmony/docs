# 帐号子系统JS API变更

OpenHarmony 3.2 Beta2版本相较于OpenHarmony 3.2 Beta1版本，帐号子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ohos.account.appAccount | Authenticator | getRemoteObject(): rpc.RemoteObject; | 新增 |
| ohos.account.appAccount | Authenticator | isAccountRemovable(name: string, callback: AuthenticatorCallback): void; | 新增 |
| ohos.account.appAccount | Authenticator | checkAccountLabels(name: string, labels: Array\<string>, callback: AuthenticatorCallback): void; | 新增 |
| ohos.account.appAccount | Authenticator | setProperties(options: SetPropertiesOptions, callback: AuthenticatorCallback): void; | 新增 |
| ohos.account.appAccount | Authenticator | verifyCredential(name: string, options: VerifyCredentialOptions, callback: AuthenticatorCallback): void; | 新增 |
| ohos.account.appAccount | AuthenticatorCallback | onRequestContinued?: () => void; | 新增 |
| ohos.account.appAccount | Constants | KEY_BOOLEAN_RESULT = "booleanResult" | 新增 |
| ohos.account.appAccount | Constants | KEY_REQUIRED_LABELS = "requiredLabels" | 新增 |
| ohos.account.appAccount | SetPropertiesOptions | parameters?: {[key: string]: Object} | 新增 |
| ohos.account.appAccount | SetPropertiesOptions | properties?: {[key: string]: Object}, | 新增 |
| ohos.account.appAccount | VerifyCredentialOptions | parameters?: {[key:string]: Object} | 新增 |
| ohos.account.appAccount | VerifyCredentialOptions | credential?: string, | 新增 |
| ohos.account.appAccount | VerifyCredentialOptions | credentialType?: string, | 新增 |
| ohos.account.appAccount | SelectAccountsOptions | requiredLabels?: Array\<string> | 新增 |
| ohos.account.appAccount | SelectAccountsOptions | allowedOwners?: Array\<string>, | 新增 |
| ohos.account.appAccount | SelectAccountsOptions | allowedAccounts?: Array\<AppAccountInfo>, | 新增 |
| ohos.account.appAccount | OAuthTokenInfo | account?: AppAccountInfo; | 新增 |
| ohos.account.appAccount | AppAccountManager | setAuthenticatorProperties(owner: string, callback: AuthenticatorCallback): void;<br>setAuthenticatorProperties(owner: string, options: SetPropertiesOptions, callback: AuthenticatorCallback): void; | 新增 |
| ohos.account.appAccount | AppAccountManager | verifyCredential(name: string, owner: string, callback: AuthenticatorCallback): void;<br>verifyCredential(name: string, owner: string, options: VerifyCredentialOptions, callback: AuthenticatorCallback): void; | 新增 |
| ohos.account.appAccount | AppAccountManager | selectAccountsByOptions(options: SelectAccountsOptions, callback: AsyncCallback\<Array\<AppAccountInfo>>);<br>selectAccountsByOptions(options: SelectAccountsOptions): Promise\<Array\<AppAccountInfo>>; | 新增 |
| ohos.account.appAccount | AppAccountManager | deleteAccountCredential(name: string, credentialType: string, callback: AsyncCallback\<void>): void;<br>deleteAccountCredential(name: string, credentialType: string): Promise\<void>; | 新增 |
| ohos.account.appAccount | AppAccountManager | checkAccountLabels(name: string, owner: string, labels: Array\<string>, callback: AsyncCallback\<boolean>): void;<br>checkAccountLabels(name: string, owner: string, labels: Array\<string>): Promise\<boolean>; | 新增 |
| ohos.account.appAccount | AppAccountManager | checkAppAccess(name: string, bundleName: string, callback: AsyncCallback\<boolean>): void;<br>checkAppAccess(name: string, bundleName: string): Promise\<boolean>; | 新增 |
| ohos.account.osAccount | ConstraintSourceTypeInfo | type: ConstraintSourceType; | 新增 |
| ohos.account.osAccount | ConstraintSourceTypeInfo | localId: number; | 新增 |
| ohos.account.osAccount | ConstraintSourceType | CONSTRAINT_TYPE_PROFILE_OWNER = 3 | 新增 |
| ohos.account.osAccount | ConstraintSourceType | CONSTRAINT_TYPE_DEVICE_OWNER = 2 | 新增 |
| ohos.account.osAccount | ConstraintSourceType | CONSTRAINT_TYPE_BASE = 1 | 新增 |
| ohos.account.osAccount | ConstraintSourceType | CONSTRAINT_NOT_EXIST = 0 | 新增 |
| ohos.account.osAccount | AccountManager | queryOsAccountConstraintSourceTypes(localId: number, constraint: string, callback: AsyncCallback\<Array\<ConstraintSourceTypeInfo>>): void;<br>queryOsAccountConstraintSourceTypes(localId: number, constraint: string): Promise\<Array\<ConstraintSourceTypeInfo>>; | 新增 |
| ohos.account.osAccount | AccountManager | isMainOsAccount(callback: AsyncCallback\<boolean>): void;<br>isMainOsAccount(): Promise\<boolean>; | 新增 |
| ohos.account.osAccount | AccountManager | getBundleIdFromUid(uid: number, callback: AsyncCallback\<number>): void;<br>getBundleIdFromUid(uid: number): Promise\<number>; | 新增 |