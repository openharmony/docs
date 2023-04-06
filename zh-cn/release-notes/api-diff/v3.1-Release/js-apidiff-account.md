# 帐号子系统JS API变更

OpenHarmony 3.1 Release版本相较于OpenHarmony 3.0 LTS版本，帐号子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ohos.account.osAccount | OsAccountType | GUEST | 新增 |
| ohos.account.osAccount | OsAccountType | NORMAL | 新增 |
| ohos.account.osAccount | OsAccountType | ADMIN = 0 | 新增 |
| ohos.account.osAccount | DomainAccountInfo | accountName: string; | 新增 |
| ohos.account.osAccount | DomainAccountInfo | domain: string; | 新增 |
| ohos.account.osAccount | OsAccountInfo | domainInfo: DomainAccountInfo; | 新增 |
| ohos.account.osAccount | OsAccountInfo | distributedInfo: distributedAccount.DistributedInfo; | 新增 |
| ohos.account.osAccount | OsAccountInfo | isCreateCompleted: boolean; | 新增 |
| ohos.account.osAccount | OsAccountInfo | isActived: boolean; | 新增 |
| ohos.account.osAccount | OsAccountInfo | serialNumber: number; | 新增 |
| ohos.account.osAccount | OsAccountInfo | lastLoginTime: number; | 新增 |
| ohos.account.osAccount | OsAccountInfo | createTime: number; | 新增 |
| ohos.account.osAccount | OsAccountInfo | photo: string; | 新增 |
| ohos.account.osAccount | OsAccountInfo | isVerified: boolean; | 新增 |
| ohos.account.osAccount | OsAccountInfo | constraints: Array\<string>; | 新增 |
| ohos.account.osAccount | OsAccountInfo | type: OsAccountType; | 新增 |
| ohos.account.osAccount | OsAccountInfo | localName: string; | 新增 |
| ohos.account.osAccount | OsAccountInfo | localId: number; | 新增 |
| ohos.account.osAccount | AccountManager | getSerialNumberByOsAccountLocalId(localId: number, callback: AsyncCallback\<number>): void;<br>getSerialNumberByOsAccountLocalId(localId: number): Promise\<number>; | 新增 |
| ohos.account.osAccount | AccountManager | getOsAccountLocalIdBySerialNumber(serialNumber: number, callback: AsyncCallback\<number>): void;<br>getOsAccountLocalIdBySerialNumber(serialNumber: number): Promise\<number>; | 新增 |
| ohos.account.osAccount | AccountManager | getDistributedVirtualDeviceId(callback: AsyncCallback\<string>): void;<br>getDistributedVirtualDeviceId(): Promise\<string>; | 新增 |
| ohos.account.osAccount | AccountManager | getOsAccountTypeFromProcess(callback: AsyncCallback\<OsAccountType>): void;<br>getOsAccountTypeFromProcess(): Promise\<OsAccountType>; | 新增 |
| ohos.account.osAccount | AccountManager | queryCurrentOsAccount(callback: AsyncCallback\<OsAccountInfo>): void;<br>queryCurrentOsAccount(): Promise\<OsAccountInfo>; | 新增 |
| ohos.account.osAccount | AccountManager | queryActivatedOsAccountIds(callback: AsyncCallback\<Array\<number>>): void;<br>queryActivatedOsAccountIds(): Promise\<Array\<number>>; | 新增 |
| ohos.account.osAccount | AccountManager | getOsAccountAllConstraints(localId: number, callback: AsyncCallback\<Array\<string>>): void;<br>getOsAccountAllConstraints(localId: number): Promise\<Array\<string>>; | 新增 |
| ohos.account.osAccount | AccountManager | getOsAccountLocalIdFromDomain(domainInfo: DomainAccountInfo, callback: AsyncCallback\<number>): void;<br>getOsAccountLocalIdFromDomain(domainInfo: DomainAccountInfo): Promise\<number>; | 新增 |
| ohos.account.osAccount | AccountManager | getOsAccountLocalIdFromUid(uid: number, callback: AsyncCallback\<number>): void;<br>getOsAccountLocalIdFromUid(uid: number): Promise\<number>; | 新增 |
| ohos.account.osAccount | AccountManager | getOsAccountLocalIdFromProcess(callback: AsyncCallback\<number>): void;<br>getOsAccountLocalIdFromProcess(): Promise\<number>; | 新增 |
| ohos.account.osAccount | AccountManager | getCreatedOsAccountsCount(callback: AsyncCallback\<number>): void;<br>getCreatedOsAccountsCount(): Promise\<number>; | 新增 |
| ohos.account.osAccount | AccountManager | isOsAccountVerified(callback: AsyncCallback\<boolean>): void;<br>isOsAccountVerified(localId: number, callback: AsyncCallback\<boolean>): void;<br>isOsAccountVerified(localId?: number): Promise\<boolean>; | 新增 |
| ohos.account.osAccount | AccountManager | isTestOsAccount(callback: AsyncCallback\<boolean>): void;<br>isTestOsAccount(): Promise\<boolean>; | 新增 |
| ohos.account.osAccount | AccountManager | isOsAccountConstraintEnable(localId: number, constraint: string, callback: AsyncCallback\<boolean>): void;<br>isOsAccountConstraintEnable(localId: number, constraint: string): Promise\<boolean>; | 新增 |
| ohos.account.osAccount | AccountManager | isOsAccountActived(localId: number, callback: AsyncCallback\<boolean>): void;<br>isOsAccountActived(localId: number): Promise\<boolean>; | 新增 |
| ohos.account.osAccount | AccountManager | isMultiOsAccountEnable(callback: AsyncCallback\<boolean>): void;<br>isMultiOsAccountEnable(): Promise\<boolean>; | 新增 |
| ohos.account.osAccount | osAccount | getAccountManager(): AccountManager; | 新增 |
| ohos.account.appAccount | Authenticator | authenticate(name: string, authType: string, callerBundleName: string, options: {[key: string]: any}, callback: AuthenticatorCallback): void; | 新增 |
| ohos.account.appAccount | Authenticator | addAccountImplicitly(authType: string, callerBundleName: string, options: {[key: string]: any}, callback: AuthenticatorCallback): void; | 新增 |
| ohos.account.appAccount | AuthenticatorCallback | onRequestRedirected: (request: Want) => void; | 新增 |
| ohos.account.appAccount | AuthenticatorCallback | onResult: (code: number, result: {[key: string]: any}) => void; | 新增 |
| ohos.account.appAccount | ResultCode | ERROR_PERMISSION_DENIED = 10018 | 新增 |
| ohos.account.appAccount | ResultCode | ERROR_OAUTH_UNSUPPORT_AUTH_TYPE = 10017 | 新增 |
| ohos.account.appAccount | ResultCode | ERROR_OAUTH_UNSUPPORT_ACTION = 10016 | 新增 |
| ohos.account.appAccount | ResultCode | ERROR_OAUTH_TOKEN_TOO_MANY = 10015 | 新增 |
| ohos.account.appAccount | ResultCode | ERROR_OAUTH_TOKEN_NOT_EXIST = 10014 | 新增 |
| ohos.account.appAccount | ResultCode | ERROR_OAUTH_TIMEOUT = 10013 | 新增 |
| ohos.account.appAccount | ResultCode | ERROR_OAUTH_SESSION_NOT_EXIST = 10012 | 新增 |
| ohos.account.appAccount | ResultCode | ERROR_OAUTH_SERVICE_EXCEPTION = 10011 | 新增 |
| ohos.account.appAccount | ResultCode | ERROR_OAUTH_SERVICE_BUSY = 10010 | 新增 |
| ohos.account.appAccount | ResultCode | ERROR_OAUTH_LIST_TOO_LARGE = 10009 | 新增 |
| ohos.account.appAccount | ResultCode | ERROR_OAUTH_CANCELED = 10008 | 新增 |
| ohos.account.appAccount | ResultCode | ERROR_OAUTH_AUTHENTICATOR_NOT_EXIST = 10007 | 新增 |
| ohos.account.appAccount | ResultCode | ERROR_NETWORK_EXCEPTION = 10006 | 新增 |
| ohos.account.appAccount | ResultCode | ERROR_INVALID_RESPONSE = 10005 | 新增 |
| ohos.account.appAccount | ResultCode | ERROR_INVALID_REQUEST = 10004 | 新增 |
| ohos.account.appAccount | ResultCode | ERROR_INVALID_PASSWORD = 10003 | 新增 |
| ohos.account.appAccount | ResultCode | ERROR_APP_ACCOUNT_SERVICE_EXCEPTION = 10002 | 新增 |
| ohos.account.appAccount | ResultCode | ERROR_ACCOUNT_NOT_EXIST = 10001 | 新增 |
| ohos.account.appAccount | ResultCode | SUCCESS = 0 | 新增 |
| ohos.account.appAccount | Constants | KEY_CALLER_BUNDLE_NAME = "callerBundleName" | 新增 |
| ohos.account.appAccount | Constants | KEY_CALLER_UID = "callerUid" | 新增 |
| ohos.account.appAccount | Constants | KEY_CALLER_PID = "callerPid" | 新增 |
| ohos.account.appAccount | Constants | KEY_SESSION_ID = "sessionId" | 新增 |
| ohos.account.appAccount | Constants | KEY_AUTH_TYPE = "authType" | 新增 |
| ohos.account.appAccount | Constants | KEY_ACTION = "action" | 新增 |
| ohos.account.appAccount | Constants | KEY_TOKEN = "token" | 新增 |
| ohos.account.appAccount | Constants | KEY_OWNER = "owner" | 新增 |
| ohos.account.appAccount | Constants | KEY_NAME = "name" | 新增 |
| ohos.account.appAccount | Constants | ACTION_AUTHENTICATE = "authenticate" | 新增 |
| ohos.account.appAccount | Constants | ACTION_ADD_ACCOUNT_IMPLICITLY = "addAccountImplicitly" | 新增 |
| ohos.account.appAccount | AuthenticatorInfo | labelId: number; | 新增 |
| ohos.account.appAccount | AuthenticatorInfo | iconId: number; | 新增 |
| ohos.account.appAccount | AuthenticatorInfo | owner: string; | 新增 |
| ohos.account.appAccount | OAuthTokenInfo | token: string; | 新增 |
| ohos.account.appAccount | OAuthTokenInfo | authType: string; | 新增 |
| ohos.account.appAccount | AppAccountInfo | name: string; | 新增 |
| ohos.account.appAccount | AppAccountInfo | owner: string; | 新增 |
| ohos.account.appAccount | AppAccountManager | getAuthenticatorInfo(owner: string, callback: AsyncCallback\<AuthenticatorInfo>): void;<br>getAuthenticatorInfo(owner: string): Promise\<AuthenticatorInfo>; | 新增 |
| ohos.account.appAccount | AppAccountManager | getAuthenticatorCallback(sessionId: string, callback: AsyncCallback\<AuthenticatorCallback>): void;<br>getAuthenticatorCallback(sessionId: string): Promise\<AuthenticatorCallback>; | 新增 |
| ohos.account.appAccount | AppAccountManager | getOAuthList(name: string, authType: string, callback: AsyncCallback\<Array\<string>>): void;<br>getOAuthList(name: string, authType: string): Promise\<Array\<string>>; | 新增 |
| ohos.account.appAccount | AppAccountManager | getAllOAuthTokens(name: string, owner: string, callback: AsyncCallback\<Array\<OAuthTokenInfo>>): void;<br>getAllOAuthTokens(name: string, owner: string): Promise\<Array\<OAuthTokenInfo>>; | 新增 |
| ohos.account.appAccount | AppAccountManager | checkOAuthTokenVisibility(name: string, authType: string, bundleName: string, callback: AsyncCallback\<boolean>): void;<br>checkOAuthTokenVisibility(name: string, authType: string, bundleName: string): Promise\<boolean>; | 新增 |
| ohos.account.appAccount | AppAccountManager | setOAuthTokenVisibility(name: string, authType: string, bundleName: string, isVisible: boolean, callback: AsyncCallback\<void>): void;<br>setOAuthTokenVisibility(name: string, authType: string, bundleName: string, isVisible: boolean): Promise\<void>; | 新增 |
| ohos.account.appAccount | AppAccountManager | deleteOAuthToken(name: string, owner: string, authType: string, token: string, callback: AsyncCallback\<void>): void;<br>deleteOAuthToken(name: string, owner: string, authType: string, token: string): Promise\<void>; | 新增 |
| ohos.account.appAccount | AppAccountManager | setOAuthToken(name: string, authType: string, token: string, callback: AsyncCallback\<void>): void;<br>setOAuthToken(name: string, authType: string, token: string): Promise\<void>; | 新增 |
| ohos.account.appAccount | AppAccountManager | getOAuthToken(name: string, owner: string, authType: string, callback: AsyncCallback\<string>): void;<br>getOAuthToken(name: string, owner: string, authType: string): Promise\<string>; | 新增 |
| ohos.account.appAccount | AppAccountManager | authenticate(name: string, owner: string, authType: string, options: {[key: string]: any}, callback: AuthenticatorCallback): void; | 新增 |
| ohos.account.appAccount | AppAccountManager | off(type: 'change', callback?: Callback\<Array\<AppAccountInfo>>): void; | 新增 |
| ohos.account.appAccount | AppAccountManager | on(type: 'change', owners: Array\<string>, callback: Callback\<Array\<AppAccountInfo>>): void; | 新增 |
| ohos.account.appAccount | AppAccountManager | getAssociatedData(name: string, key: string, callback: AsyncCallback\<string>): void;<br>getAssociatedData(name: string, key: string): Promise\<string>; | 新增 |
| ohos.account.appAccount | AppAccountManager | getAccountExtraInfo(name: string, callback: AsyncCallback\<string>): void;<br>getAccountExtraInfo(name: string): Promise\<string>; | 新增 |
| ohos.account.appAccount | AppAccountManager | getAccountCredential(name: string, credentialType: string, callback: AsyncCallback\<string>): void;<br>getAccountCredential(name: string, credentialType: string): Promise\<string>; | 新增 |
| ohos.account.appAccount | AppAccountManager | getAllAccounts(owner: string, callback: AsyncCallback\<Array\<AppAccountInfo>>): void;<br>getAllAccounts(owner: string): Promise\<Array\<AppAccountInfo>>; | 新增 |
| ohos.account.appAccount | AppAccountManager | getAllAccessibleAccounts(callback: AsyncCallback\<Array\<AppAccountInfo>>): void;<br>getAllAccessibleAccounts(): Promise\<Array\<AppAccountInfo>>; | 新增 |
| ohos.account.appAccount | AppAccountManager | setAssociatedData(name: string, key: string, value: string, callback: AsyncCallback\<void>): void;<br>setAssociatedData(name: string, key: string, value: string): Promise\<void>; | 新增 |
| ohos.account.appAccount | AppAccountManager | setAppAccountSyncEnable(name: string, isEnable: boolean, callback: AsyncCallback\<void>): void;<br>setAppAccountSyncEnable(name: string, isEnable: boolean): Promise\<void>; | 新增 |
| ohos.account.appAccount | AppAccountManager | setAccountExtraInfo(name: string, extraInfo: string, callback: AsyncCallback\<void>): void;<br>setAccountExtraInfo(name: string, extraInfo: string): Promise\<void>; | 新增 |
| ohos.account.appAccount | AppAccountManager | setAccountCredential(name: string, credentialType: string, credential: string, callback: AsyncCallback\<void>): void;<br>setAccountCredential(name: string, credentialType: string, credential: string): Promise\<void>; | 新增 |
| ohos.account.appAccount | AppAccountManager | checkAppAccountSyncEnable(name: string, callback: AsyncCallback\<boolean>): void;<br>checkAppAccountSyncEnable(name: string): Promise\<boolean>; | 新增 |
| ohos.account.appAccount | AppAccountManager | enableAppAccess(name: string, bundleName: string, callback: AsyncCallback\<void>): void;<br>enableAppAccess(name: string, bundleName: string): Promise\<void>; | 新增 |
| ohos.account.appAccount | AppAccountManager | disableAppAccess(name: string, bundleName: string, callback: AsyncCallback\<void>): void;<br>disableAppAccess(name: string, bundleName: string): Promise\<void>; | 新增 |
| ohos.account.appAccount | AppAccountManager | deleteAccount(name: string, callback: AsyncCallback\<void>): void;<br>deleteAccount(name: string): Promise\<void>; | 新增 |
| ohos.account.appAccount | AppAccountManager | addAccountImplicitly(owner: string, authType: string, options: {[key: string]: any}, callback: AuthenticatorCallback): void; | 新增 |
| ohos.account.appAccount | AppAccountManager | addAccount(name: string, callback: AsyncCallback\<void>): void;<br>addAccount(name: string, extraInfo: string, callback: AsyncCallback\<void>): void;<br>addAccount(name: string, extraInfo?: string): Promise\<void>; | 新增 |
| ohos.account.appAccount | appAccount | createAppAccountManager(): AppAccountManager; | 新增 |
