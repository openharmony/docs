# JS API Changes of the Account Subsystem

The table below lists the APIs changes of the account subsystem in OpenHarmony 3.1 Release over OpenHarmony 3.0 LTS.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| ohos.account.osAccount | OsAccountType | GUEST | Added|
| ohos.account.osAccount | OsAccountType | NORMAL | Added|
| ohos.account.osAccount | OsAccountType | ADMIN = 0 | Added|
| ohos.account.osAccount | DomainAccountInfo | accountName: string; | Added|
| ohos.account.osAccount | DomainAccountInfo | domain: string; | Added|
| ohos.account.osAccount | OsAccountInfo | domainInfo: DomainAccountInfo; | Added|
| ohos.account.osAccount | OsAccountInfo | distributedInfo: distributedAccount.DistributedInfo; | Added|
| ohos.account.osAccount | OsAccountInfo | isCreateCompleted: boolean; | Added|
| ohos.account.osAccount | OsAccountInfo | isActived: boolean; | Added|
| ohos.account.osAccount | OsAccountInfo | serialNumber: number; | Added|
| ohos.account.osAccount | OsAccountInfo | lastLoginTime: number; | Added|
| ohos.account.osAccount | OsAccountInfo | createTime: number; | Added|
| ohos.account.osAccount | OsAccountInfo | photo: string; | Added|
| ohos.account.osAccount | OsAccountInfo | isVerified: boolean; | Added|
| ohos.account.osAccount | OsAccountInfo | constraints: Array\<string>; | Added|
| ohos.account.osAccount | OsAccountInfo | type: OsAccountType; | Added|
| ohos.account.osAccount | OsAccountInfo | localName: string; | Added|
| ohos.account.osAccount | OsAccountInfo | localId: number; | Added|
| ohos.account.osAccount | AccountManager | getSerialNumberByOsAccountLocalId(localId: number, callback: AsyncCallback\<number>): void;<br>getSerialNumberByOsAccountLocalId(localId: number): Promise\<number>; | Added|
| ohos.account.osAccount | AccountManager | getOsAccountLocalIdBySerialNumber(serialNumber: number, callback: AsyncCallback\<number>): void;<br>getOsAccountLocalIdBySerialNumber(serialNumber: number): Promise\<number>; | Added|
| ohos.account.osAccount | AccountManager | getDistributedVirtualDeviceId(callback: AsyncCallback\<string>): void;<br>getDistributedVirtualDeviceId(): Promise\<string>; | Added|
| ohos.account.osAccount | AccountManager | getOsAccountTypeFromProcess(callback: AsyncCallback\<OsAccountType>): void;<br>getOsAccountTypeFromProcess(): Promise\<OsAccountType>; | Added|
| ohos.account.osAccount | AccountManager | queryCurrentOsAccount(callback: AsyncCallback\<OsAccountInfo>): void;<br>queryCurrentOsAccount(): Promise\<OsAccountInfo>; | Added|
| ohos.account.osAccount | AccountManager | queryActivatedOsAccountIds(callback: AsyncCallback\<Array\<number>>): void;<br>queryActivatedOsAccountIds(): Promise\<Array\<number>>; | Added|
| ohos.account.osAccount | AccountManager | getOsAccountAllConstraints(localId: number, callback: AsyncCallback\<Array\<string>>): void;<br>getOsAccountAllConstraints(localId: number): Promise\<Array\<string>>; | Added|
| ohos.account.osAccount | AccountManager | getOsAccountLocalIdFromDomain(domainInfo: DomainAccountInfo, callback: AsyncCallback\<number>): void;<br>getOsAccountLocalIdFromDomain(domainInfo: DomainAccountInfo): Promise\<number>; | Added|
| ohos.account.osAccount | AccountManager | getOsAccountLocalIdFromUid(uid: number, callback: AsyncCallback\<number>): void;<br>getOsAccountLocalIdFromUid(uid: number): Promise\<number>; | Added|
| ohos.account.osAccount | AccountManager | getOsAccountLocalIdFromProcess(callback: AsyncCallback\<number>): void;<br>getOsAccountLocalIdFromProcess(): Promise\<number>; | Added|
| ohos.account.osAccount | AccountManager | getCreatedOsAccountsCount(callback: AsyncCallback\<number>): void;<br>getCreatedOsAccountsCount(): Promise\<number>; | Added|
| ohos.account.osAccount | AccountManager | isOsAccountVerified(callback: AsyncCallback\<boolean>): void;<br>isOsAccountVerified(localId: number, callback: AsyncCallback\<boolean>): void;<br>isOsAccountVerified(localId?: number): Promise\<boolean>; | Added|
| ohos.account.osAccount | AccountManager | isTestOsAccount(callback: AsyncCallback\<boolean>): void;<br>isTestOsAccount(): Promise\<boolean>; | Added|
| ohos.account.osAccount | AccountManager | isOsAccountConstraintEnable(localId: number, constraint: string, callback: AsyncCallback\<boolean>): void;<br>isOsAccountConstraintEnable(localId: number, constraint: string): Promise\<boolean>; | Added|
| ohos.account.osAccount | AccountManager | isOsAccountActived(localId: number, callback: AsyncCallback\<boolean>): void;<br>isOsAccountActived(localId: number): Promise\<boolean>; | Added|
| ohos.account.osAccount | AccountManager | isMultiOsAccountEnable(callback: AsyncCallback\<boolean>): void;<br>isMultiOsAccountEnable(): Promise\<boolean>; | Added|
| ohos.account.osAccount | osAccount | getAccountManager(): AccountManager; | Added|
| ohos.account.appAccount | Authenticator | authenticate(name: string, authType: string, callerBundleName: string, options: {[key: string]: any}, callback: AuthenticatorCallback): void; | Added|
| ohos.account.appAccount | Authenticator | addAccountImplicitly(authType: string, callerBundleName: string, options: {[key: string]: any}, callback: AuthenticatorCallback): void; | Added|
| ohos.account.appAccount | AuthenticatorCallback | onRequestRedirected: (request: Want) => void; | Added|
| ohos.account.appAccount | AuthenticatorCallback | onResult: (code: number, result: {[key: string]: any}) => void; | Added|
| ohos.account.appAccount | ResultCode | ERROR_PERMISSION_DENIED = 10018 | Added|
| ohos.account.appAccount | ResultCode | ERROR_OAUTH_UNSUPPORT_AUTH_TYPE = 10017 | Added|
| ohos.account.appAccount | ResultCode | ERROR_OAUTH_UNSUPPORT_ACTION = 10016 | Added|
| ohos.account.appAccount | ResultCode | ERROR_OAUTH_TOKEN_TOO_MANY = 10015 | Added|
| ohos.account.appAccount | ResultCode | ERROR_OAUTH_TOKEN_NOT_EXIST = 10014 | Added|
| ohos.account.appAccount | ResultCode | ERROR_OAUTH_TIMEOUT = 10013 | Added|
| ohos.account.appAccount | ResultCode | ERROR_OAUTH_SESSION_NOT_EXIST = 10012 | Added|
| ohos.account.appAccount | ResultCode | ERROR_OAUTH_SERVICE_EXCEPTION = 10011 | Added|
| ohos.account.appAccount | ResultCode | ERROR_OAUTH_SERVICE_BUSY = 10010 | Added|
| ohos.account.appAccount | ResultCode | ERROR_OAUTH_LIST_TOO_LARGE = 10009 | Added|
| ohos.account.appAccount | ResultCode | ERROR_OAUTH_CANCELED = 10008 | Added|
| ohos.account.appAccount | ResultCode | ERROR_OAUTH_AUTHENTICATOR_NOT_EXIST = 10007 | Added|
| ohos.account.appAccount | ResultCode | ERROR_NETWORK_EXCEPTION = 10006 | Added|
| ohos.account.appAccount | ResultCode | ERROR_INVALID_RESPONSE = 10005 | Added|
| ohos.account.appAccount | ResultCode | ERROR_INVALID_REQUEST = 10004 | Added|
| ohos.account.appAccount | ResultCode | ERROR_INVALID_PASSWORD = 10003 | Added|
| ohos.account.appAccount | ResultCode | ERROR_APP_ACCOUNT_SERVICE_EXCEPTION = 10002 | Added|
| ohos.account.appAccount | ResultCode | ERROR_ACCOUNT_NOT_EXIST = 10001 | Added|
| ohos.account.appAccount | ResultCode | SUCCESS = 0 | Added|
| ohos.account.appAccount | Constants | KEY_CALLER_BUNDLE_NAME = "callerBundleName" | Added|
| ohos.account.appAccount | Constants | KEY_CALLER_UID = "callerUid" | Added|
| ohos.account.appAccount | Constants | KEY_CALLER_PID = "callerPid" | Added|
| ohos.account.appAccount | Constants | KEY_SESSION_ID = "sessionId" | Added|
| ohos.account.appAccount | Constants | KEY_AUTH_TYPE = "authType" | Added|
| ohos.account.appAccount | Constants | KEY_ACTION = "action" | Added|
| ohos.account.appAccount | Constants | KEY_TOKEN = "token" | Added|
| ohos.account.appAccount | Constants | KEY_OWNER = "owner" | Added|
| ohos.account.appAccount | Constants | KEY_NAME = "name" | Added|
| ohos.account.appAccount | Constants | ACTION_AUTHENTICATE = "authenticate" | Added|
| ohos.account.appAccount | Constants | ACTION_ADD_ACCOUNT_IMPLICITLY = "addAccountImplicitly" | Added|
| ohos.account.appAccount | AuthenticatorInfo | labelId: number; | Added|
| ohos.account.appAccount | AuthenticatorInfo | iconId: number; | Added|
| ohos.account.appAccount | AuthenticatorInfo | owner: string; | Added|
| ohos.account.appAccount | OAuthTokenInfo | token: string; | Added|
| ohos.account.appAccount | OAuthTokenInfo | authType: string; | Added|
| ohos.account.appAccount | AppAccountInfo | name: string; | Added|
| ohos.account.appAccount | AppAccountInfo | owner: string; | Added|
| ohos.account.appAccount | AppAccountManager | getAuthenticatorInfo(owner: string, callback: AsyncCallback\<AuthenticatorInfo>): void;<br>getAuthenticatorInfo(owner: string): Promise\<AuthenticatorInfo>; | Added|
| ohos.account.appAccount | AppAccountManager | getAuthenticatorCallback(sessionId: string, callback: AsyncCallback\<AuthenticatorCallback>): void;<br>getAuthenticatorCallback(sessionId: string): Promise\<AuthenticatorCallback>; | Added|
| ohos.account.appAccount | AppAccountManager | getOAuthList(name: string, authType: string, callback: AsyncCallback\<Array\<string>>): void;<br>getOAuthList(name: string, authType: string): Promise\<Array\<string>>; | Added|
| ohos.account.appAccount | AppAccountManager | getAllOAuthTokens(name: string, owner: string, callback: AsyncCallback\<Array\<OAuthTokenInfo>>): void;<br>getAllOAuthTokens(name: string, owner: string): Promise\<Array\<OAuthTokenInfo>>; | Added|
| ohos.account.appAccount | AppAccountManager | checkOAuthTokenVisibility(name: string, authType: string, bundleName: string, callback: AsyncCallback\<boolean>): void;<br>checkOAuthTokenVisibility(name: string, authType: string, bundleName: string): Promise\<boolean>; | Added|
| ohos.account.appAccount | AppAccountManager | setOAuthTokenVisibility(name: string, authType: string, bundleName: string, isVisible: boolean, callback: AsyncCallback\<void>): void;<br>setOAuthTokenVisibility(name: string, authType: string, bundleName: string, isVisible: boolean): Promise\<void>; | Added|
| ohos.account.appAccount | AppAccountManager | deleteOAuthToken(name: string, owner: string, authType: string, token: string, callback: AsyncCallback\<void>): void;<br>deleteOAuthToken(name: string, owner: string, authType: string, token: string): Promise\<void>; | Added|
| ohos.account.appAccount | AppAccountManager | setOAuthToken(name: string, authType: string, token: string, callback: AsyncCallback\<void>): void;<br>setOAuthToken(name: string, authType: string, token: string): Promise\<void>; | Added|
| ohos.account.appAccount | AppAccountManager | getOAuthToken(name: string, owner: string, authType: string, callback: AsyncCallback\<string>): void;<br>getOAuthToken(name: string, owner: string, authType: string): Promise\<string>; | Added|
| ohos.account.appAccount | AppAccountManager | authenticate(name: string, owner: string, authType: string, options: {[key: string]: any}, callback: AuthenticatorCallback): void; | Added|
| ohos.account.appAccount | AppAccountManager | off(type: 'change', callback?: Callback\<Array\<AppAccountInfo>>): void; | Added|
| ohos.account.appAccount | AppAccountManager | on(type: 'change', owners: Array\<string>, callback: Callback\<Array\<AppAccountInfo>>): void; | Added|
| ohos.account.appAccount | AppAccountManager | getAssociatedData(name: string, key: string, callback: AsyncCallback\<string>): void;<br>getAssociatedData(name: string, key: string): Promise\<string>; | Added|
| ohos.account.appAccount | AppAccountManager | getAccountExtraInfo(name: string, callback: AsyncCallback\<string>): void;<br>getAccountExtraInfo(name: string): Promise\<string>; | Added|
| ohos.account.appAccount | AppAccountManager | getAccountCredential(name: string, credentialType: string, callback: AsyncCallback\<string>): void;<br>getAccountCredential(name: string, credentialType: string): Promise\<string>; | Added|
| ohos.account.appAccount | AppAccountManager | getAllAccounts(owner: string, callback: AsyncCallback\<Array\<AppAccountInfo>>): void;<br>getAllAccounts(owner: string): Promise\<Array\<AppAccountInfo>>; | Added|
| ohos.account.appAccount | AppAccountManager | getAllAccessibleAccounts(callback: AsyncCallback\<Array\<AppAccountInfo>>): void;<br>getAllAccessibleAccounts(): Promise\<Array\<AppAccountInfo>>; | Added|
| ohos.account.appAccount | AppAccountManager | setAssociatedData(name: string, key: string, value: string, callback: AsyncCallback\<void>): void;<br>setAssociatedData(name: string, key: string, value: string): Promise\<void>; | Added|
| ohos.account.appAccount | AppAccountManager | setAppAccountSyncEnable(name: string, isEnable: boolean, callback: AsyncCallback\<void>): void;<br>setAppAccountSyncEnable(name: string, isEnable: boolean): Promise\<void>; | Added|
| ohos.account.appAccount | AppAccountManager | setAccountExtraInfo(name: string, extraInfo: string, callback: AsyncCallback\<void>): void;<br>setAccountExtraInfo(name: string, extraInfo: string): Promise\<void>; | Added|
| ohos.account.appAccount | AppAccountManager | setAccountCredential(name: string, credentialType: string, credential: string, callback: AsyncCallback\<void>): void;<br>setAccountCredential(name: string, credentialType: string, credential: string): Promise\<void>; | Added|
| ohos.account.appAccount | AppAccountManager | checkAppAccountSyncEnable(name: string, callback: AsyncCallback\<boolean>): void;<br>checkAppAccountSyncEnable(name: string): Promise\<boolean>; | Added|
| ohos.account.appAccount | AppAccountManager | enableAppAccess(name: string, bundleName: string, callback: AsyncCallback\<void>): void;<br>enableAppAccess(name: string, bundleName: string): Promise\<void>; | Added|
| ohos.account.appAccount | AppAccountManager | disableAppAccess(name: string, bundleName: string, callback: AsyncCallback\<void>): void;<br>disableAppAccess(name: string, bundleName: string): Promise\<void>; | Added|
| ohos.account.appAccount | AppAccountManager | deleteAccount(name: string, callback: AsyncCallback\<void>): void;<br>deleteAccount(name: string): Promise\<void>; | Added|
| ohos.account.appAccount | AppAccountManager | addAccountImplicitly(owner: string, authType: string, options: {[key: string]: any}, callback: AuthenticatorCallback): void; | Added|
| ohos.account.appAccount | AppAccountManager | addAccount(name: string, callback: AsyncCallback\<void>): void;<br>addAccount(name: string, extraInfo: string, callback: AsyncCallback\<void>): void;<br>addAccount(name: string, extraInfo?: string): Promise\<void>; | Added|
| ohos.account.appAccount | appAccount | createAppAccountManager(): AppAccountManager; | Added|
