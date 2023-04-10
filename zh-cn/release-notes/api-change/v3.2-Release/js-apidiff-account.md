| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|类名：AppAccountManager<br>方法or属性：createAccount(name: string, callback: AsyncCallback\<void>): void;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AppAccountManager<br>方法or属性：createAccount(name: string, options: CreateAccountOptions, callback: AsyncCallback\<void>): void;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AppAccountManager<br>方法or属性：createAccount(name: string, options?: CreateAccountOptions): Promise\<void>;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AppAccountManager<br>方法or属性：createAccountImplicitly(owner: string, callback: AuthCallback): void;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AppAccountManager<br>方法or属性：createAccountImplicitly(owner: string, options: CreateAccountImplicitlyOptions, callback: AuthCallback): void;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AppAccountManager<br>方法or属性：removeAccount(name: string, callback: AsyncCallback\<void>): void;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AppAccountManager<br>方法or属性：removeAccount(name: string): Promise\<void>;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AppAccountManager<br>方法or属性：setAppAccess(name: string, bundleName: string, isAccessible: boolean, callback: AsyncCallback\<void>): void;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AppAccountManager<br>方法or属性：setAppAccess(name: string, bundleName: string, isAccessible: boolean): Promise\<void>;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AppAccountManager<br>方法or属性：checkAppAccess(name: string, bundleName: string, callback: AsyncCallback\<boolean>): void;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AppAccountManager<br>方法or属性：checkAppAccess(name: string, bundleName: string): Promise\<boolean>;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AppAccountManager<br>方法or属性：checkDataSyncEnabled(name: string, callback: AsyncCallback\<boolean>): void;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AppAccountManager<br>方法or属性：checkDataSyncEnabled(name: string): Promise\<boolean>;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AppAccountManager<br>方法or属性：setCredential(name: string, credentialType: string, credential: string,<br>                             callback: AsyncCallback\<void>): void;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AppAccountManager<br>方法or属性：setCredential(name: string, credentialType: string, credential: string): Promise\<void>;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AppAccountManager<br>方法or属性：setDataSyncEnabled(name: string, isEnabled: boolean, callback: AsyncCallback\<void>): void;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AppAccountManager<br>方法or属性：setDataSyncEnabled(name: string, isEnabled: boolean): Promise\<void>;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AppAccountManager<br>方法or属性：setCustomData(name: string, key: string, value: string, callback: AsyncCallback\<void>): void;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AppAccountManager<br>方法or属性：setCustomData(name: string, key: string, value: string): Promise\<void>;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AppAccountManager<br>方法or属性：getAccountsByOwner(owner: string, callback: AsyncCallback\<Array\<AppAccountInfo>>): void;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AppAccountManager<br>方法or属性：getAccountsByOwner(owner: string): Promise\<Array\<AppAccountInfo>>;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AppAccountManager<br>方法or属性：getCredential(name: string, credentialType: string, callback: AsyncCallback\<string>): void;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AppAccountManager<br>方法or属性：getCredential(name: string, credentialType: string): Promise\<string>;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AppAccountManager<br>方法or属性：getCustomData(name: string, key: string, callback: AsyncCallback\<string>): void;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AppAccountManager<br>方法or属性：getCustomData(name: string, key: string): Promise\<string>;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AppAccountManager<br>方法or属性：getCustomDataSync(name: string, key: string): string;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AppAccountManager<br>方法or属性：on(type: 'accountChange', owners: Array\<string>, callback: Callback\<Array\<AppAccountInfo>>): void;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AppAccountManager<br>方法or属性：off(type: 'accountChange', callback?: Callback\<Array\<AppAccountInfo>>): void;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AppAccountManager<br>方法or属性：auth(name: string, owner: string, authType: string, callback: AuthCallback): void;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AppAccountManager<br>方法or属性：auth(name: string, owner: string, authType: string, options: {[key:string]: Object}, callback: AuthCallback): void;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AppAccountManager<br>方法or属性：getAuthToken(name: string, owner: string, authType: string, callback: AsyncCallback\<string>): void;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AppAccountManager<br>方法or属性：getAuthToken(name: string, owner: string, authType: string): Promise\<string>;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AppAccountManager<br>方法or属性：setAuthToken(name: string, authType: string, token: string, callback: AsyncCallback\<void>): void;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AppAccountManager<br>方法or属性：setAuthToken(name: string, authType: string, token: string): Promise\<void>;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AppAccountManager<br>方法or属性：deleteAuthToken(name: string, owner: string, authType: string, token: string, callback: AsyncCallback\<void>): void;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AppAccountManager<br>方法or属性：deleteAuthToken(name: string, owner: string, authType: string, token: string): Promise\<void>;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AppAccountManager<br>方法or属性：setAuthTokenVisibility(name: string, authType: string, bundleName: string, isVisible: boolean, callback: AsyncCallback\<void>): void;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AppAccountManager<br>方法or属性：setAuthTokenVisibility(name: string, authType: string, bundleName: string, isVisible: boolean): Promise\<void>;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AppAccountManager<br>方法or属性：checkAuthTokenVisibility(name: string, authType: string, bundleName: string, callback: AsyncCallback\<boolean>): void;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AppAccountManager<br>方法or属性：checkAuthTokenVisibility(name: string, authType: string, bundleName: string): Promise\<boolean>;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AppAccountManager<br>方法or属性：getAllAuthTokens(name: string, owner: string, callback: AsyncCallback\<Array\<AuthTokenInfo>>): void;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AppAccountManager<br>方法or属性：getAllAuthTokens(name: string, owner: string): Promise\<Array\<AuthTokenInfo>>;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AppAccountManager<br>方法or属性：getAuthList(name: string, authType: string, callback: AsyncCallback\<Array\<string>>): void;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AppAccountManager<br>方法or属性：getAuthList(name: string, authType: string): Promise\<Array\<string>>;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AppAccountManager<br>方法or属性：getAuthCallback(sessionId: string, callback: AsyncCallback\<AuthCallback>): void;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AppAccountManager<br>方法or属性：getAuthCallback(sessionId: string): Promise\<AuthCallback>;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AppAccountManager<br>方法or属性：queryAuthenticatorInfo(owner: string, callback: AsyncCallback\<AuthenticatorInfo>): void;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AppAccountManager<br>方法or属性：queryAuthenticatorInfo(owner: string): Promise\<AuthenticatorInfo>;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AppAccountManager<br>方法or属性：checkAccountLabels(name: string, owner: string, labels: Array\<string>, callback: AsyncCallback\<boolean>): void;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AppAccountManager<br>方法or属性：checkAccountLabels(name: string, owner: string, labels: Array\<string>): Promise\<boolean>;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AppAccountManager<br>方法or属性：deleteCredential(name: string, credentialType: string, callback: AsyncCallback\<void>): void;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AppAccountManager<br>方法or属性：deleteCredential(name: string, credentialType: string): Promise\<void>;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AppAccountManager<br>方法or属性：selectAccountsByOptions(options: SelectAccountsOptions, callback: AsyncCallback\<Array\<AppAccountInfo>>): void;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AppAccountManager<br>方法or属性：selectAccountsByOptions(options: SelectAccountsOptions): Promise\<Array\<AppAccountInfo>>;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AppAccountManager<br>方法or属性：verifyCredential(name: string, owner: string, callback: AuthCallback): void;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AppAccountManager<br>方法or属性：verifyCredential(name: string, owner: string, options: VerifyCredentialOptions, callback: AuthCallback): void;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AppAccountManager<br>方法or属性：setAuthenticatorProperties(owner: string, callback: AuthCallback): void;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AppAccountManager<br>方法or属性：setAuthenticatorProperties(owner: string, options: SetPropertiesOptions, callback: AuthCallback): void;|@ohos.account.appAccount.d.ts|
|新增|NA|模块名: ohos.account.appAccount<br>类名: AuthTokenInfo|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AuthTokenInfo<br>方法or属性：|@ohos.account.appAccount.d.ts|
|新增|NA|模块名: ohos.account.appAccount<br>类名: AuthTokenInfo<br>方法 or 属性：authType: string;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AuthTokenInfo<br>方法or属性：authType: string;|@ohos.account.appAccount.d.ts|
|新增|NA|模块名: ohos.account.appAccount<br>类名: AuthTokenInfo<br>方法 or 属性：token: string;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AuthTokenInfo<br>方法or属性：token: string;|@ohos.account.appAccount.d.ts|
|新增|NA|模块名: ohos.account.appAccount<br>类名: AuthTokenInfo<br>方法 or 属性：account?: AppAccountInfo;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AuthTokenInfo<br>方法or属性：account?: AppAccountInfo;|@ohos.account.appAccount.d.ts|
|新增|NA|模块名: ohos.account.appAccount<br>类名: AuthResult|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AuthResult<br>方法or属性：|@ohos.account.appAccount.d.ts|
|新增|NA|模块名: ohos.account.appAccount<br>类名: AuthResult<br>方法 or 属性：account?: AppAccountInfo;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AuthResult<br>方法or属性：account?: AppAccountInfo;|@ohos.account.appAccount.d.ts|
|新增|NA|模块名: ohos.account.appAccount<br>类名: AuthResult<br>方法 or 属性：tokenInfo?: AuthTokenInfo;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AuthResult<br>方法or属性：tokenInfo?: AuthTokenInfo;|@ohos.account.appAccount.d.ts|
|新增|NA|模块名: ohos.account.appAccount<br>类名: CreateAccountOptions|@ohos.account.appAccount.d.ts|
|新增|NA|类名：CreateAccountOptions<br>方法or属性：|@ohos.account.appAccount.d.ts|
|新增|NA|模块名: ohos.account.appAccount<br>类名: CreateAccountOptions<br>方法 or 属性：customData?: {[key: string]: string};|@ohos.account.appAccount.d.ts|
|新增|NA|类名：CreateAccountOptions<br>方法or属性：customData?: {[key: string]: string};|@ohos.account.appAccount.d.ts|
|新增|NA|模块名: ohos.account.appAccount<br>类名: CreateAccountImplicitlyOptions|@ohos.account.appAccount.d.ts|
|新增|NA|类名：CreateAccountImplicitlyOptions<br>方法or属性：|@ohos.account.appAccount.d.ts|
|新增|NA|模块名: ohos.account.appAccount<br>类名: CreateAccountImplicitlyOptions<br>方法 or 属性：requiredLabels?: Array\<string>;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：CreateAccountImplicitlyOptions<br>方法or属性：requiredLabels?: Array\<string>;|@ohos.account.appAccount.d.ts|
|新增|NA|模块名: ohos.account.appAccount<br>类名: CreateAccountImplicitlyOptions<br>方法 or 属性：authType?: string;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：CreateAccountImplicitlyOptions<br>方法or属性：authType?: string;|@ohos.account.appAccount.d.ts|
|新增|NA|模块名: ohos.account.appAccount<br>类名: CreateAccountImplicitlyOptions<br>方法 or 属性：parameters?: {[key:string]: Object};|@ohos.account.appAccount.d.ts|
|新增|NA|类名：CreateAccountImplicitlyOptions<br>方法or属性：parameters?: {[key:string]: Object};|@ohos.account.appAccount.d.ts|
|新增|NA|模块名: ohos.account.appAccount<br>类名: SelectAccountsOptions|@ohos.account.appAccount.d.ts|
|新增|NA|类名：SelectAccountsOptions<br>方法or属性：|@ohos.account.appAccount.d.ts|
|新增|NA|模块名: ohos.account.appAccount<br>类名: SelectAccountsOptions<br>方法 or 属性：allowedAccounts?: Array\<AppAccountInfo>;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：SelectAccountsOptions<br>方法or属性：allowedAccounts?: Array\<AppAccountInfo>;|@ohos.account.appAccount.d.ts|
|新增|NA|模块名: ohos.account.appAccount<br>类名: SelectAccountsOptions<br>方法 or 属性：allowedOwners?: Array\<string>;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：SelectAccountsOptions<br>方法or属性：allowedOwners?: Array\<string>;|@ohos.account.appAccount.d.ts|
|新增|NA|模块名: ohos.account.appAccount<br>类名: SelectAccountsOptions<br>方法 or 属性：requiredLabels?: Array\<string>;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：SelectAccountsOptions<br>方法or属性：requiredLabels?: Array\<string>;|@ohos.account.appAccount.d.ts|
|新增|NA|模块名: ohos.account.appAccount<br>类名: VerifyCredentialOptions|@ohos.account.appAccount.d.ts|
|新增|NA|类名：VerifyCredentialOptions<br>方法or属性：|@ohos.account.appAccount.d.ts|
|新增|NA|模块名: ohos.account.appAccount<br>类名: VerifyCredentialOptions<br>方法 or 属性：credentialType?: string;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：VerifyCredentialOptions<br>方法or属性：credentialType?: string;|@ohos.account.appAccount.d.ts|
|新增|NA|模块名: ohos.account.appAccount<br>类名: VerifyCredentialOptions<br>方法 or 属性：credential?: string;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：VerifyCredentialOptions<br>方法or属性：credential?: string;|@ohos.account.appAccount.d.ts|
|新增|NA|模块名: ohos.account.appAccount<br>类名: VerifyCredentialOptions<br>方法 or 属性：parameters?: {[key:string]: Object};|@ohos.account.appAccount.d.ts|
|新增|NA|类名：VerifyCredentialOptions<br>方法or属性：parameters?: {[key:string]: Object};|@ohos.account.appAccount.d.ts|
|新增|NA|模块名: ohos.account.appAccount<br>类名: SetPropertiesOptions|@ohos.account.appAccount.d.ts|
|新增|NA|类名：SetPropertiesOptions<br>方法or属性：|@ohos.account.appAccount.d.ts|
|新增|NA|模块名: ohos.account.appAccount<br>类名: SetPropertiesOptions<br>方法 or 属性：properties?: {[key: string]: Object};|@ohos.account.appAccount.d.ts|
|新增|NA|类名：SetPropertiesOptions<br>方法or属性：properties?: {[key: string]: Object};|@ohos.account.appAccount.d.ts|
|新增|NA|模块名: ohos.account.appAccount<br>类名: SetPropertiesOptions<br>方法 or 属性：parameters?: {[key: string]: Object};|@ohos.account.appAccount.d.ts|
|新增|NA|类名：SetPropertiesOptions<br>方法or属性：parameters?: {[key: string]: Object};|@ohos.account.appAccount.d.ts|
|新增|NA|类名：Constants<br>方法or属性：ACTION_CREATE_ACCOUNT_IMPLICITLY = "createAccountImplicitly"|@ohos.account.appAccount.d.ts|
|新增|NA|类名：Constants<br>方法or属性：ACTION_AUTH = "auth"|@ohos.account.appAccount.d.ts|
|新增|NA|类名：Constants<br>方法or属性：ACTION_VERIFY_CREDENTIAL = "verifyCredential"|@ohos.account.appAccount.d.ts|
|新增|NA|类名：Constants<br>方法or属性：ACTION_SET_AUTHENTICATOR_PROPERTIES = "setAuthenticatorProperties"|@ohos.account.appAccount.d.ts|
|新增|NA|类名：Constants<br>方法or属性：KEY_REQUIRED_LABELS = "requiredLabels"|@ohos.account.appAccount.d.ts|
|新增|NA|类名：Constants<br>方法or属性：KEY_BOOLEAN_RESULT = "booleanResult"|@ohos.account.appAccount.d.ts|
|新增|NA|模块名: ohos.account.appAccount<br>类名: AuthCallback|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AuthCallback<br>方法or属性：|@ohos.account.appAccount.d.ts|
|新增|NA|模块名: ohos.account.appAccount<br>类名: AuthCallback<br>方法 or 属性：onResult: (code: number, result?: AuthResult) => void;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AuthCallback<br>方法or属性：onResult: (code: number, result?: AuthResult) => void;|@ohos.account.appAccount.d.ts|
|新增|NA|模块名: ohos.account.appAccount<br>类名: AuthCallback<br>方法 or 属性：onRequestRedirected: (request: Want) => void;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AuthCallback<br>方法or属性：onRequestRedirected: (request: Want) => void;|@ohos.account.appAccount.d.ts|
|新增|NA|模块名: ohos.account.appAccount<br>类名: AuthCallback<br>方法 or 属性：onRequestContinued?: () => void;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AuthCallback<br>方法or属性：onRequestContinued?: () => void;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：Authenticator<br>方法or属性：createAccountImplicitly(options: CreateAccountImplicitlyOptions, callback: AuthCallback): void;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：Authenticator<br>方法or属性：auth(name: string, authType: string, options: {[key:string]: Object}, callback: AuthCallback): void;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：Authenticator<br>方法or属性：verifyCredential(name: string, options: VerifyCredentialOptions, callback: AuthCallback): void;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：Authenticator<br>方法or属性：setProperties(options: SetPropertiesOptions, callback: AuthCallback): void;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：Authenticator<br>方法or属性：checkAccountLabels(name: string, labels: Array\<string>, callback: AuthCallback): void;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：Authenticator<br>方法or属性：checkAccountRemovable(name: string, callback: AuthCallback): void;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：Authenticator<br>方法or属性：getRemoteObject(): rpc.RemoteObject;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：DistributedAccountAbility<br>方法or属性：getOsAccountDistributedInfo(callback: AsyncCallback\<DistributedInfo>): void;|@ohos.account.distributedAccount.d.ts|
|新增|NA|类名：DistributedAccountAbility<br>方法or属性：getOsAccountDistributedInfo(): Promise\<DistributedInfo>;|@ohos.account.distributedAccount.d.ts|
|新增|NA|类名：DistributedAccountAbility<br>方法or属性：setOsAccountDistributedInfo(accountInfo: DistributedInfo, callback: AsyncCallback\<void>): void;|@ohos.account.distributedAccount.d.ts|
|新增|NA|类名：DistributedAccountAbility<br>方法or属性：setOsAccountDistributedInfo(accountInfo: DistributedInfo): Promise\<void>;|@ohos.account.distributedAccount.d.ts|
|新增|NA|类名：DistributedInfo<br>方法or属性：nickname?: string;|@ohos.account.distributedAccount.d.ts|
|新增|NA|类名：DistributedInfo<br>方法or属性：avatar?: string;|@ohos.account.distributedAccount.d.ts|
|新增|NA|类名：AccountManager<br>方法or属性：checkMultiOsAccountEnabled(callback: AsyncCallback\<boolean>): void;|@ohos.account.osAccount.d.ts|
|新增|NA|类名：AccountManager<br>方法or属性：checkMultiOsAccountEnabled(): Promise\<boolean>;|@ohos.account.osAccount.d.ts|
|新增|NA|类名：AccountManager<br>方法or属性：checkOsAccountActivated(localId: number, callback: AsyncCallback\<boolean>): void;|@ohos.account.osAccount.d.ts|
|新增|NA|类名：AccountManager<br>方法or属性：checkOsAccountActivated(localId: number): Promise\<boolean>;|@ohos.account.osAccount.d.ts|
|新增|NA|类名：AccountManager<br>方法or属性：checkOsAccountConstraintEnabled(localId: number, constraint: string, callback: AsyncCallback\<boolean>): void;|@ohos.account.osAccount.d.ts|
|新增|NA|类名：AccountManager<br>方法or属性：checkOsAccountConstraintEnabled(localId: number, constraint: string): Promise\<boolean>;|@ohos.account.osAccount.d.ts|
|新增|NA|类名：AccountManager<br>方法or属性：checkOsAccountTestable(callback: AsyncCallback\<boolean>): void;|@ohos.account.osAccount.d.ts|
|新增|NA|类名：AccountManager<br>方法or属性：checkOsAccountTestable(): Promise\<boolean>;|@ohos.account.osAccount.d.ts|
|新增|NA|类名：AccountManager<br>方法or属性：checkOsAccountVerified(callback: AsyncCallback\<boolean>): void;|@ohos.account.osAccount.d.ts|
|新增|NA|类名：AccountManager<br>方法or属性：checkOsAccountVerified(): Promise\<boolean>;|@ohos.account.osAccount.d.ts|
|新增|NA|类名：AccountManager<br>方法or属性：checkOsAccountVerified(localId: number, callback: AsyncCallback\<boolean>): void;|@ohos.account.osAccount.d.ts|
|新增|NA|类名：AccountManager<br>方法or属性：checkOsAccountVerified(localId: number): Promise\<boolean>;|@ohos.account.osAccount.d.ts|
|新增|NA|类名：AccountManager<br>方法or属性：getOsAccountCount(callback: AsyncCallback\<number>): void;|@ohos.account.osAccount.d.ts|
|新增|NA|类名：AccountManager<br>方法or属性：getOsAccountCount(): Promise\<number>;|@ohos.account.osAccount.d.ts|
|新增|NA|类名：AccountManager<br>方法or属性：getOsAccountLocalId(callback: AsyncCallback\<number>): void;|@ohos.account.osAccount.d.ts|
|新增|NA|类名：AccountManager<br>方法or属性：getOsAccountLocalId(): Promise\<number>;|@ohos.account.osAccount.d.ts|
|新增|NA|类名：AccountManager<br>方法or属性：getOsAccountLocalIdForUid(uid: number, callback: AsyncCallback\<number>): void;|@ohos.account.osAccount.d.ts|
|新增|NA|类名：AccountManager<br>方法or属性：getOsAccountLocalIdForUid(uid: number): Promise\<number>;|@ohos.account.osAccount.d.ts|
|新增|NA|类名：AccountManager<br>方法or属性：getOsAccountLocalIdForDomain(domainInfo: DomainAccountInfo, callback: AsyncCallback\<number>): void;|@ohos.account.osAccount.d.ts|
|新增|NA|类名：AccountManager<br>方法or属性：getOsAccountLocalIdForDomain(domainInfo: DomainAccountInfo): Promise\<number>;|@ohos.account.osAccount.d.ts|
|新增|NA|类名：AccountManager<br>方法or属性：getOsAccountConstraints(localId: number, callback: AsyncCallback\<Array\<string>>): void;|@ohos.account.osAccount.d.ts|
|新增|NA|类名：AccountManager<br>方法or属性：getOsAccountConstraints(localId: number): Promise\<Array\<string>>;|@ohos.account.osAccount.d.ts|
|新增|NA|类名：AccountManager<br>方法or属性：getActivatedOsAccountLocalIds(callback: AsyncCallback\<Array\<number>>): void;|@ohos.account.osAccount.d.ts|
|新增|NA|类名：AccountManager<br>方法or属性：getActivatedOsAccountLocalIds(): Promise\<Array\<number>>;|@ohos.account.osAccount.d.ts|
|新增|NA|类名：AccountManager<br>方法or属性：getCurrentOsAccount(callback: AsyncCallback\<OsAccountInfo>): void;|@ohos.account.osAccount.d.ts|
|新增|NA|类名：AccountManager<br>方法or属性：getCurrentOsAccount(): Promise\<OsAccountInfo>;|@ohos.account.osAccount.d.ts|
|新增|NA|类名：AccountManager<br>方法or属性：getOsAccountType(callback: AsyncCallback\<OsAccountType>): void;|@ohos.account.osAccount.d.ts|
|新增|NA|类名：AccountManager<br>方法or属性：getOsAccountType(): Promise\<OsAccountType>;|@ohos.account.osAccount.d.ts|
|新增|NA|类名：AccountManager<br>方法or属性：queryDistributedVirtualDeviceId(callback: AsyncCallback\<string>): void;|@ohos.account.osAccount.d.ts|
|新增|NA|类名：AccountManager<br>方法or属性：queryDistributedVirtualDeviceId(): Promise\<string>;|@ohos.account.osAccount.d.ts|
|新增|NA|类名：AccountManager<br>方法or属性：getOsAccountLocalIdForSerialNumber(serialNumber: number, callback: AsyncCallback\<number>): void;|@ohos.account.osAccount.d.ts|
|新增|NA|类名：AccountManager<br>方法or属性：getOsAccountLocalIdForSerialNumber(serialNumber: number): Promise\<number>;|@ohos.account.osAccount.d.ts|
|新增|NA|类名：AccountManager<br>方法or属性：getSerialNumberForOsAccountLocalId(localId: number, callback: AsyncCallback\<number>): void;|@ohos.account.osAccount.d.ts|
|新增|NA|类名：AccountManager<br>方法or属性：getSerialNumberForOsAccountLocalId(localId: number): Promise\<number>;|@ohos.account.osAccount.d.ts|
|新增|NA|类名：AccountManager<br>方法or属性：getBundleIdForUid(uid: number, callback: AsyncCallback\<number>): void;|@ohos.account.osAccount.d.ts|
|新增|NA|类名：AccountManager<br>方法or属性：getBundleIdForUid(uid: number): Promise\<number>;|@ohos.account.osAccount.d.ts|
|新增|NA|类名：AccountManager<br>方法or属性：isMainOsAccount(callback: AsyncCallback\<boolean>): void;|@ohos.account.osAccount.d.ts|
|新增|NA|类名：AccountManager<br>方法or属性：isMainOsAccount(): Promise\<boolean>;|@ohos.account.osAccount.d.ts|
|新增|NA|类名：AccountManager<br>方法or属性：getOsAccountConstraintSourceTypes(localId: number, constraint: string, callback: AsyncCallback\<Array\<ConstraintSourceTypeInfo>>): void;|@ohos.account.osAccount.d.ts|
|新增|NA|类名：AccountManager<br>方法or属性：getOsAccountConstraintSourceTypes(localId: number, constraint: string): Promise\<Array\<ConstraintSourceTypeInfo>>;|@ohos.account.osAccount.d.ts|
|新增|NA|模块名: ohos.account.osAccount<br>类名: InputerManager|@ohos.account.osAccount.d.ts|
|新增|NA|类名：InputerManager<br>方法or属性：|@ohos.account.osAccount.d.ts|
|新增|NA|模块名: ohos.account.osAccount<br>类名: InputerManager<br>方法 or 属性：static registerInputer(authType: AuthType, inputer: IInputer): void;|@ohos.account.osAccount.d.ts|
|新增|NA|类名：InputerManager<br>方法or属性：static registerInputer(authType: AuthType, inputer: IInputer): void;|@ohos.account.osAccount.d.ts|
|新增|NA|模块名: ohos.account.osAccount<br>类名: InputerManager<br>方法 or 属性：static unregisterInputer(authType: AuthType): void;|@ohos.account.osAccount.d.ts|
|新增|NA|类名：InputerManager<br>方法or属性：static unregisterInputer(authType: AuthType): void;|@ohos.account.osAccount.d.ts|
|新增|NA|模块名: ohos.account.osAccount<br>类名: DomainPlugin|@ohos.account.osAccount.d.ts|
|新增|NA|类名：DomainPlugin<br>方法or属性：|@ohos.account.osAccount.d.ts|
|新增|NA|模块名: ohos.account.osAccount<br>类名: DomainPlugin<br>方法 or 属性：auth(domainAccountInfo: DomainAccountInfo, credential: Uint8Array, callback: IUserAuthCallback): void;|@ohos.account.osAccount.d.ts|
|新增|NA|类名：DomainPlugin<br>方法or属性：auth(domainAccountInfo: DomainAccountInfo, credential: Uint8Array, callback: IUserAuthCallback): void;|@ohos.account.osAccount.d.ts|
|新增|NA|模块名: ohos.account.osAccount<br>类名: DomainAccountManager|@ohos.account.osAccount.d.ts|
|新增|NA|类名：DomainAccountManager<br>方法or属性：|@ohos.account.osAccount.d.ts|
|新增|NA|模块名: ohos.account.osAccount<br>类名: DomainAccountManager<br>方法 or 属性：static registerPlugin(plugin: DomainPlugin): void;|@ohos.account.osAccount.d.ts|
|新增|NA|类名：DomainAccountManager<br>方法or属性：static registerPlugin(plugin: DomainPlugin): void;|@ohos.account.osAccount.d.ts|
|新增|NA|模块名: ohos.account.osAccount<br>类名: DomainAccountManager<br>方法 or 属性：static unregisterPlugin(): void;|@ohos.account.osAccount.d.ts|
|新增|NA|类名：DomainAccountManager<br>方法or属性：static unregisterPlugin(): void;|@ohos.account.osAccount.d.ts|
|新增|NA|类名：UserIdentityManager<br>方法or属性：getAuthInfo(callback: AsyncCallback\<Array\<EnrolledCredInfo>>): void;|@ohos.account.osAccount.d.ts|
|新增|NA|类名：UserIdentityManager<br>方法or属性：getAuthInfo(authType: AuthType, callback: AsyncCallback\<Array\<EnrolledCredInfo>>): void;|@ohos.account.osAccount.d.ts|
|新增|NA|模块名: ohos.account.osAccount<br>类名: AuthType<br>方法 or 属性：DOMAIN = 1024|@ohos.account.osAccount.d.ts|
|新增|NA|类名：AuthType<br>方法or属性：DOMAIN = 1024|@ohos.account.osAccount.d.ts|
|新增|NA|模块名: ohos.account.osAccount<br>类名: AuthSubType<br>方法 or 属性：DOMAIN_MIXED = 10240001|@ohos.account.osAccount.d.ts|
|新增|NA|类名：AuthSubType<br>方法or属性：DOMAIN_MIXED = 10240001|@ohos.account.osAccount.d.ts|
|新增|NA|模块名: ohos.account.osAccount<br>类名: ConstraintSourceType|@ohos.account.osAccount.d.ts|
|新增|NA|类名：ConstraintSourceType<br>方法or属性：|@ohos.account.osAccount.d.ts|
|新增|NA|模块名: ohos.account.osAccount<br>类名: ConstraintSourceType<br>方法 or 属性：CONSTRAINT_NOT_EXIST = 0|@ohos.account.osAccount.d.ts|
|新增|NA|类名：ConstraintSourceType<br>方法or属性：CONSTRAINT_NOT_EXIST = 0|@ohos.account.osAccount.d.ts|
|新增|NA|模块名: ohos.account.osAccount<br>类名: ConstraintSourceType<br>方法 or 属性：CONSTRAINT_TYPE_BASE = 1|@ohos.account.osAccount.d.ts|
|新增|NA|类名：ConstraintSourceType<br>方法or属性：CONSTRAINT_TYPE_BASE = 1|@ohos.account.osAccount.d.ts|
|新增|NA|模块名: ohos.account.osAccount<br>类名: ConstraintSourceType<br>方法 or 属性：CONSTRAINT_TYPE_DEVICE_OWNER = 2|@ohos.account.osAccount.d.ts|
|新增|NA|类名：ConstraintSourceType<br>方法or属性：CONSTRAINT_TYPE_DEVICE_OWNER = 2|@ohos.account.osAccount.d.ts|
|新增|NA|模块名: ohos.account.osAccount<br>类名: ConstraintSourceType<br>方法 or 属性：CONSTRAINT_TYPE_PROFILE_OWNER = 3|@ohos.account.osAccount.d.ts|
|新增|NA|类名：ConstraintSourceType<br>方法or属性：CONSTRAINT_TYPE_PROFILE_OWNER = 3|@ohos.account.osAccount.d.ts|
|新增|NA|模块名: ohos.account.osAccount<br>类名: ConstraintSourceTypeInfo|@ohos.account.osAccount.d.ts|
|新增|NA|类名：ConstraintSourceTypeInfo<br>方法or属性：|@ohos.account.osAccount.d.ts|
|新增|NA|模块名: ohos.account.osAccount<br>类名: ConstraintSourceTypeInfo<br>方法 or 属性：localId: number;|@ohos.account.osAccount.d.ts|
|新增|NA|类名：ConstraintSourceTypeInfo<br>方法or属性：localId: number;|@ohos.account.osAccount.d.ts|
|新增|NA|模块名: ohos.account.osAccount<br>类名: ConstraintSourceTypeInfo<br>方法 or 属性：type: ConstraintSourceType;|@ohos.account.osAccount.d.ts|
|新增|NA|类名：ConstraintSourceTypeInfo<br>方法or属性：type: ConstraintSourceType;|@ohos.account.osAccount.d.ts|
|废弃版本有变化|类名：AppAccountManager<br>方法 or 属性：addAccount(name: string, callback: AsyncCallback\<void>): void;<br>废弃版本：N/A|类名：AppAccountManager<br>方法 or 属性：addAccount(name: string, callback: AsyncCallback\<void>): void;<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|类名：AppAccountManager<br>方法 or 属性：addAccount(name: string, extraInfo: string, callback: AsyncCallback\<void>): void;<br>废弃版本：N/A|类名：AppAccountManager<br>方法 or 属性：addAccount(name: string, extraInfo: string, callback: AsyncCallback\<void>): void;<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|类名：AppAccountManager<br>方法 or 属性：addAccount(name: string, extraInfo?: string): Promise\<void>;<br>废弃版本：N/A|类名：AppAccountManager<br>方法 or 属性：addAccount(name: string, extraInfo?: string): Promise\<void>;<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|类名：AppAccountManager<br>方法 or 属性：addAccountImplicitly(owner: string, authType: string, options: {[key: string]: any}, callback: AuthenticatorCallback): void;<br>废弃版本：N/A|类名：AppAccountManager<br>方法 or 属性：addAccountImplicitly(owner: string, authType: string, options: {[key: string]: any}, callback: AuthenticatorCallback): void;<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|类名：AppAccountManager<br>方法 or 属性：deleteAccount(name: string, callback: AsyncCallback\<void>): void;<br>废弃版本：N/A|类名：AppAccountManager<br>方法 or 属性：deleteAccount(name: string, callback: AsyncCallback\<void>): void;<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|类名：AppAccountManager<br>方法 or 属性：deleteAccount(name: string): Promise\<void>;<br>废弃版本：N/A|类名：AppAccountManager<br>方法 or 属性：deleteAccount(name: string): Promise\<void>;<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|类名：AppAccountManager<br>方法 or 属性：disableAppAccess(name: string, bundleName: string, callback: AsyncCallback\<void>): void;<br>废弃版本：N/A|类名：AppAccountManager<br>方法 or 属性：disableAppAccess(name: string, bundleName: string, callback: AsyncCallback\<void>): void;<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|类名：AppAccountManager<br>方法 or 属性：disableAppAccess(name: string, bundleName: string): Promise\<void>;<br>废弃版本：N/A|类名：AppAccountManager<br>方法 or 属性：disableAppAccess(name: string, bundleName: string): Promise\<void>;<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|类名：AppAccountManager<br>方法 or 属性：enableAppAccess(name: string, bundleName: string, callback: AsyncCallback\<void>): void;<br>废弃版本：N/A|类名：AppAccountManager<br>方法 or 属性：enableAppAccess(name: string, bundleName: string, callback: AsyncCallback\<void>): void;<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|类名：AppAccountManager<br>方法 or 属性：enableAppAccess(name: string, bundleName: string): Promise\<void>;<br>废弃版本：N/A|类名：AppAccountManager<br>方法 or 属性：enableAppAccess(name: string, bundleName: string): Promise\<void>;<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|类名：AppAccountManager<br>方法 or 属性：checkAppAccountSyncEnable(name: string, callback: AsyncCallback\<boolean>): void;<br>废弃版本：N/A|类名：AppAccountManager<br>方法 or 属性：checkAppAccountSyncEnable(name: string, callback: AsyncCallback\<boolean>): void;<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|类名：AppAccountManager<br>方法 or 属性：checkAppAccountSyncEnable(name: string): Promise\<boolean>;<br>废弃版本：N/A|类名：AppAccountManager<br>方法 or 属性：checkAppAccountSyncEnable(name: string): Promise\<boolean>;<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|类名：AppAccountManager<br>方法 or 属性：setAccountCredential(name: string, credentialType: string, credential: string,<br>                             callback: AsyncCallback\<void>): void;<br>废弃版本：N/A|类名：AppAccountManager<br>方法 or 属性：setAccountCredential(name: string, credentialType: string, credential: string,<br>                             callback: AsyncCallback\<void>): void;<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|类名：AppAccountManager<br>方法 or 属性：setAccountCredential(name: string, credentialType: string, credential: string): Promise\<void>;<br>废弃版本：N/A|类名：AppAccountManager<br>方法 or 属性：setAccountCredential(name: string, credentialType: string, credential: string): Promise\<void>;<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|类名：AppAccountManager<br>方法 or 属性：setAccountExtraInfo(name: string, extraInfo: string, callback: AsyncCallback\<void>): void;<br>废弃版本：N/A|类名：AppAccountManager<br>方法 or 属性：setAccountExtraInfo(name: string, extraInfo: string, callback: AsyncCallback\<void>): void;<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|类名：AppAccountManager<br>方法 or 属性：setAccountExtraInfo(name: string, extraInfo: string): Promise\<void>;<br>废弃版本：N/A|类名：AppAccountManager<br>方法 or 属性：setAccountExtraInfo(name: string, extraInfo: string): Promise\<void>;<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|类名：AppAccountManager<br>方法 or 属性：setAppAccountSyncEnable(name: string, isEnable: boolean, callback: AsyncCallback\<void>): void;<br>废弃版本：N/A|类名：AppAccountManager<br>方法 or 属性：setAppAccountSyncEnable(name: string, isEnable: boolean, callback: AsyncCallback\<void>): void;<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|类名：AppAccountManager<br>方法 or 属性：setAppAccountSyncEnable(name: string, isEnable: boolean): Promise\<void>;<br>废弃版本：N/A|类名：AppAccountManager<br>方法 or 属性：setAppAccountSyncEnable(name: string, isEnable: boolean): Promise\<void>;<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|类名：AppAccountManager<br>方法 or 属性：setAssociatedData(name: string, key: string, value: string, callback: AsyncCallback\<void>): void;<br>废弃版本：N/A|类名：AppAccountManager<br>方法 or 属性：setAssociatedData(name: string, key: string, value: string, callback: AsyncCallback\<void>): void;<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|类名：AppAccountManager<br>方法 or 属性：setAssociatedData(name: string, key: string, value: string): Promise\<void>;<br>废弃版本：N/A|类名：AppAccountManager<br>方法 or 属性：setAssociatedData(name: string, key: string, value: string): Promise\<void>;<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|类名：AppAccountManager<br>方法 or 属性：getAllAccessibleAccounts(callback: AsyncCallback\<Array\<AppAccountInfo>>): void;<br>废弃版本：N/A|类名：AppAccountManager<br>方法 or 属性：getAllAccessibleAccounts(callback: AsyncCallback\<Array\<AppAccountInfo>>): void;<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|类名：AppAccountManager<br>方法 or 属性：getAllAccessibleAccounts(): Promise\<Array\<AppAccountInfo>>;<br>废弃版本：N/A|类名：AppAccountManager<br>方法 or 属性：getAllAccessibleAccounts(): Promise\<Array\<AppAccountInfo>>;<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|类名：AppAccountManager<br>方法 or 属性：getAllAccounts(owner: string, callback: AsyncCallback\<Array\<AppAccountInfo>>): void;<br>废弃版本：N/A|类名：AppAccountManager<br>方法 or 属性：getAllAccounts(owner: string, callback: AsyncCallback\<Array\<AppAccountInfo>>): void;<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|类名：AppAccountManager<br>方法 or 属性：getAllAccounts(owner: string): Promise\<Array\<AppAccountInfo>>;<br>废弃版本：N/A|类名：AppAccountManager<br>方法 or 属性：getAllAccounts(owner: string): Promise\<Array\<AppAccountInfo>>;<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|类名：AppAccountManager<br>方法 or 属性：getAccountCredential(name: string, credentialType: string, callback: AsyncCallback\<string>): void;<br>废弃版本：N/A|类名：AppAccountManager<br>方法 or 属性：getAccountCredential(name: string, credentialType: string, callback: AsyncCallback\<string>): void;<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|类名：AppAccountManager<br>方法 or 属性：getAccountCredential(name: string, credentialType: string): Promise\<string>;<br>废弃版本：N/A|类名：AppAccountManager<br>方法 or 属性：getAccountCredential(name: string, credentialType: string): Promise\<string>;<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|类名：AppAccountManager<br>方法 or 属性：getAccountExtraInfo(name: string, callback: AsyncCallback\<string>): void;<br>废弃版本：N/A|类名：AppAccountManager<br>方法 or 属性：getAccountExtraInfo(name: string, callback: AsyncCallback\<string>): void;<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|类名：AppAccountManager<br>方法 or 属性：getAccountExtraInfo(name: string): Promise\<string>;<br>废弃版本：N/A|类名：AppAccountManager<br>方法 or 属性：getAccountExtraInfo(name: string): Promise\<string>;<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|类名：AppAccountManager<br>方法 or 属性：getAssociatedData(name: string, key: string, callback: AsyncCallback\<string>): void;<br>废弃版本：N/A|类名：AppAccountManager<br>方法 or 属性：getAssociatedData(name: string, key: string, callback: AsyncCallback\<string>): void;<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|类名：AppAccountManager<br>方法 or 属性：getAssociatedData(name: string, key: string): Promise\<string>;<br>废弃版本：N/A|类名：AppAccountManager<br>方法 or 属性：getAssociatedData(name: string, key: string): Promise\<string>;<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|类名：AppAccountManager<br>方法 or 属性：on(type: 'change', owners: Array\<string>, callback: Callback\<Array\<AppAccountInfo>>): void;<br>废弃版本：N/A|类名：AppAccountManager<br>方法 or 属性：on(type: 'change', owners: Array\<string>, callback: Callback\<Array\<AppAccountInfo>>): void;<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|类名：AppAccountManager<br>方法 or 属性：off(type: 'change', callback?: Callback\<Array\<AppAccountInfo>>): void;<br>废弃版本：N/A|类名：AppAccountManager<br>方法 or 属性：off(type: 'change', callback?: Callback\<Array\<AppAccountInfo>>): void;<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|类名：AppAccountManager<br>方法 or 属性：authenticate(name: string, owner: string, authType: string, options: {[key: string]: any}, callback: AuthenticatorCallback): void;<br>废弃版本：N/A|类名：AppAccountManager<br>方法 or 属性：authenticate(name: string, owner: string, authType: string, options: {[key: string]: any}, callback: AuthenticatorCallback): void;<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|类名：AppAccountManager<br>方法 or 属性：getOAuthToken(name: string, owner: string, authType: string, callback: AsyncCallback\<string>): void;<br>废弃版本：N/A|类名：AppAccountManager<br>方法 or 属性：getOAuthToken(name: string, owner: string, authType: string, callback: AsyncCallback\<string>): void;<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|类名：AppAccountManager<br>方法 or 属性：getOAuthToken(name: string, owner: string, authType: string): Promise\<string>;<br>废弃版本：N/A|类名：AppAccountManager<br>方法 or 属性：getOAuthToken(name: string, owner: string, authType: string): Promise\<string>;<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|类名：AppAccountManager<br>方法 or 属性：setOAuthToken(name: string, authType: string, token: string, callback: AsyncCallback\<void>): void;<br>废弃版本：N/A|类名：AppAccountManager<br>方法 or 属性：setOAuthToken(name: string, authType: string, token: string, callback: AsyncCallback\<void>): void;<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|类名：AppAccountManager<br>方法 or 属性：setOAuthToken(name: string, authType: string, token: string): Promise\<void>;<br>废弃版本：N/A|类名：AppAccountManager<br>方法 or 属性：setOAuthToken(name: string, authType: string, token: string): Promise\<void>;<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|类名：AppAccountManager<br>方法 or 属性：deleteOAuthToken(name: string, owner: string, authType: string, token: string, callback: AsyncCallback\<void>): void;<br>废弃版本：N/A|类名：AppAccountManager<br>方法 or 属性：deleteOAuthToken(name: string, owner: string, authType: string, token: string, callback: AsyncCallback\<void>): void;<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|类名：AppAccountManager<br>方法 or 属性：deleteOAuthToken(name: string, owner: string, authType: string, token: string): Promise\<void>;<br>废弃版本：N/A|类名：AppAccountManager<br>方法 or 属性：deleteOAuthToken(name: string, owner: string, authType: string, token: string): Promise\<void>;<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|类名：AppAccountManager<br>方法 or 属性：setOAuthTokenVisibility(name: string, authType: string, bundleName: string, isVisible: boolean, callback: AsyncCallback\<void>): void;<br>废弃版本：N/A|类名：AppAccountManager<br>方法 or 属性：setOAuthTokenVisibility(name: string, authType: string, bundleName: string, isVisible: boolean, callback: AsyncCallback\<void>): void;<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|类名：AppAccountManager<br>方法 or 属性：setOAuthTokenVisibility(name: string, authType: string, bundleName: string, isVisible: boolean): Promise\<void>;<br>废弃版本：N/A|类名：AppAccountManager<br>方法 or 属性：setOAuthTokenVisibility(name: string, authType: string, bundleName: string, isVisible: boolean): Promise\<void>;<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|类名：AppAccountManager<br>方法 or 属性：checkOAuthTokenVisibility(name: string, authType: string, bundleName: string, callback: AsyncCallback\<boolean>): void;<br>废弃版本：N/A|类名：AppAccountManager<br>方法 or 属性：checkOAuthTokenVisibility(name: string, authType: string, bundleName: string, callback: AsyncCallback\<boolean>): void;<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|类名：AppAccountManager<br>方法 or 属性：checkOAuthTokenVisibility(name: string, authType: string, bundleName: string): Promise\<boolean>;<br>废弃版本：N/A|类名：AppAccountManager<br>方法 or 属性：checkOAuthTokenVisibility(name: string, authType: string, bundleName: string): Promise\<boolean>;<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|类名：AppAccountManager<br>方法 or 属性：getAllOAuthTokens(name: string, owner: string, callback: AsyncCallback\<Array\<OAuthTokenInfo>>): void;<br>废弃版本：N/A|类名：AppAccountManager<br>方法 or 属性：getAllOAuthTokens(name: string, owner: string, callback: AsyncCallback\<Array\<OAuthTokenInfo>>): void;<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|类名：AppAccountManager<br>方法 or 属性：getAllOAuthTokens(name: string, owner: string): Promise\<Array\<OAuthTokenInfo>>;<br>废弃版本：N/A|类名：AppAccountManager<br>方法 or 属性：getAllOAuthTokens(name: string, owner: string): Promise\<Array\<OAuthTokenInfo>>;<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|类名：AppAccountManager<br>方法 or 属性：getOAuthList(name: string, authType: string, callback: AsyncCallback\<Array\<string>>): void;<br>废弃版本：N/A|类名：AppAccountManager<br>方法 or 属性：getOAuthList(name: string, authType: string, callback: AsyncCallback\<Array\<string>>): void;<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|类名：AppAccountManager<br>方法 or 属性：getOAuthList(name: string, authType: string): Promise\<Array\<string>>;<br>废弃版本：N/A|类名：AppAccountManager<br>方法 or 属性：getOAuthList(name: string, authType: string): Promise\<Array\<string>>;<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|类名：AppAccountManager<br>方法 or 属性：getAuthenticatorCallback(sessionId: string, callback: AsyncCallback\<AuthenticatorCallback>): void;<br>废弃版本：N/A|类名：AppAccountManager<br>方法 or 属性：getAuthenticatorCallback(sessionId: string, callback: AsyncCallback\<AuthenticatorCallback>): void;<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|类名：AppAccountManager<br>方法 or 属性：getAuthenticatorCallback(sessionId: string): Promise\<AuthenticatorCallback>;<br>废弃版本：N/A|类名：AppAccountManager<br>方法 or 属性：getAuthenticatorCallback(sessionId: string): Promise\<AuthenticatorCallback>;<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|类名：AppAccountManager<br>方法 or 属性：getAuthenticatorInfo(owner: string, callback: AsyncCallback\<AuthenticatorInfo>): void;<br>废弃版本：N/A|类名：AppAccountManager<br>方法 or 属性：getAuthenticatorInfo(owner: string, callback: AsyncCallback\<AuthenticatorInfo>): void;<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|类名：AppAccountManager<br>方法 or 属性：getAuthenticatorInfo(owner: string): Promise\<AuthenticatorInfo>;<br>废弃版本：N/A|类名：AppAccountManager<br>方法 or 属性：getAuthenticatorInfo(owner: string): Promise\<AuthenticatorInfo>;<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|类名：OAuthTokenInfo<br>废弃版本：N/A|类名：OAuthTokenInfo<br>废弃版本：9<br>代替接口：appAccount.AuthTokenInfo     |@ohos.account.appAccount.d.ts|
|废弃版本有变化|类名：Constants<br>方法 or 属性：ACTION_ADD_ACCOUNT_IMPLICITLY = "addAccountImplicitly"<br>废弃版本：N/A|类名：Constants<br>方法 or 属性：ACTION_ADD_ACCOUNT_IMPLICITLY = "addAccountImplicitly"<br>废弃版本：9<br>代替接口：appAccount.Constants|@ohos.account.appAccount.d.ts|
|废弃版本有变化|类名：Constants<br>方法 or 属性：ACTION_AUTHENTICATE = "authenticate"<br>废弃版本：N/A|类名：Constants<br>方法 or 属性：ACTION_AUTHENTICATE = "authenticate"<br>废弃版本：9<br>代替接口：appAccount.Constants|@ohos.account.appAccount.d.ts|
|废弃版本有变化|类名：ResultCode<br>废弃版本：N/A|类名：ResultCode<br>废弃版本：9<br>代替接口：N/A|@ohos.account.appAccount.d.ts|
|废弃版本有变化|类名：AuthenticatorCallback<br>废弃版本：N/A|类名：AuthenticatorCallback<br>废弃版本：9<br>代替接口：AppAccount.AuthCallback     |@ohos.account.appAccount.d.ts|
|废弃版本有变化|类名：Authenticator<br>方法 or 属性：addAccountImplicitly(authType: string, callerBundleName: string, options: {[key: string]: any}, callback: AuthenticatorCallback): void;<br>废弃版本：N/A|类名：Authenticator<br>方法 or 属性：addAccountImplicitly(authType: string, callerBundleName: string, options: {[key: string]: any}, callback: AuthenticatorCallback): void;<br>废弃版本：9<br>代替接口：appAccount.Authenticator|@ohos.account.appAccount.d.ts|
|废弃版本有变化|类名：Authenticator<br>方法 or 属性：authenticate(name: string, authType: string, callerBundleName: string, options: {[key: string]: any}, callback: AuthenticatorCallback): void;<br>废弃版本：N/A|类名：Authenticator<br>方法 or 属性：authenticate(name: string, authType: string, callerBundleName: string, options: {[key: string]: any}, callback: AuthenticatorCallback): void;<br>废弃版本：9<br>代替接口：appAccount.Authenticator|@ohos.account.appAccount.d.ts|
|废弃版本有变化|类名：DistributedAccountAbility<br>方法 or 属性：queryOsAccountDistributedInfo(callback: AsyncCallback\<DistributedInfo>): void;<br>废弃版本：N/A|类名：DistributedAccountAbility<br>方法 or 属性：queryOsAccountDistributedInfo(callback: AsyncCallback\<DistributedInfo>): void;<br>废弃版本：9<br>代替接口：distributedAccount.DistributedAccountAbility|@ohos.account.distributedAccount.d.ts|
|废弃版本有变化|类名：DistributedAccountAbility<br>方法 or 属性：queryOsAccountDistributedInfo(): Promise\<DistributedInfo>;<br>废弃版本：N/A|类名：DistributedAccountAbility<br>方法 or 属性：queryOsAccountDistributedInfo(): Promise\<DistributedInfo>;<br>废弃版本：9<br>代替接口：distributedAccount.DistributedAccountAbility|@ohos.account.distributedAccount.d.ts|
|废弃版本有变化|类名：DistributedAccountAbility<br>方法 or 属性：updateOsAccountDistributedInfo(accountInfo: DistributedInfo, callback: AsyncCallback\<void>): void;<br>废弃版本：N/A|类名：DistributedAccountAbility<br>方法 or 属性：updateOsAccountDistributedInfo(accountInfo: DistributedInfo, callback: AsyncCallback\<void>): void;<br>废弃版本：9<br>代替接口：distributedAccount.DistributedAccountAbility|@ohos.account.distributedAccount.d.ts|
|废弃版本有变化|类名：DistributedAccountAbility<br>方法 or 属性：updateOsAccountDistributedInfo(accountInfo: DistributedInfo): Promise\<void>;<br>废弃版本：N/A|类名：DistributedAccountAbility<br>方法 or 属性：updateOsAccountDistributedInfo(accountInfo: DistributedInfo): Promise\<void>;<br>废弃版本：9<br>代替接口：distributedAccount.DistributedAccountAbility|@ohos.account.distributedAccount.d.ts|
|废弃版本有变化|类名：AccountManager<br>方法 or 属性：isMultiOsAccountEnable(callback: AsyncCallback\<boolean>): void;<br>废弃版本：N/A|类名：AccountManager<br>方法 or 属性：isMultiOsAccountEnable(callback: AsyncCallback\<boolean>): void;<br>废弃版本：9<br>代替接口：osAccount.AccountManager|@ohos.account.osAccount.d.ts|
|废弃版本有变化|类名：AccountManager<br>方法 or 属性：isMultiOsAccountEnable(): Promise\<boolean>;<br>废弃版本：N/A|类名：AccountManager<br>方法 or 属性：isMultiOsAccountEnable(): Promise\<boolean>;<br>废弃版本：9<br>代替接口：osAccount.AccountManager|@ohos.account.osAccount.d.ts|
|废弃版本有变化|类名：AccountManager<br>方法 or 属性：isOsAccountActived(localId: number, callback: AsyncCallback\<boolean>): void;<br>废弃版本：N/A|类名：AccountManager<br>方法 or 属性：isOsAccountActived(localId: number, callback: AsyncCallback\<boolean>): void;<br>废弃版本：9<br>代替接口：osAccount.AccountManager|@ohos.account.osAccount.d.ts|
|废弃版本有变化|类名：AccountManager<br>方法 or 属性：isOsAccountActived(localId: number): Promise\<boolean>;<br>废弃版本：N/A|类名：AccountManager<br>方法 or 属性：isOsAccountActived(localId: number): Promise\<boolean>;<br>废弃版本：9<br>代替接口：osAccount.AccountManager|@ohos.account.osAccount.d.ts|
|废弃版本有变化|类名：AccountManager<br>方法 or 属性：isOsAccountConstraintEnable(localId: number, constraint: string, callback: AsyncCallback\<boolean>): void;<br>废弃版本：N/A|类名：AccountManager<br>方法 or 属性：isOsAccountConstraintEnable(localId: number, constraint: string, callback: AsyncCallback\<boolean>): void;<br>废弃版本：9<br>代替接口：osAccount.AccountManager|@ohos.account.osAccount.d.ts|
|废弃版本有变化|类名：AccountManager<br>方法 or 属性：isOsAccountConstraintEnable(localId: number, constraint: string): Promise\<boolean>;<br>废弃版本：N/A|类名：AccountManager<br>方法 or 属性：isOsAccountConstraintEnable(localId: number, constraint: string): Promise\<boolean>;<br>废弃版本：9<br>代替接口：osAccount.AccountManager|@ohos.account.osAccount.d.ts|
|废弃版本有变化|类名：AccountManager<br>方法 or 属性：isTestOsAccount(callback: AsyncCallback\<boolean>): void;<br>废弃版本：N/A|类名：AccountManager<br>方法 or 属性：isTestOsAccount(callback: AsyncCallback\<boolean>): void;<br>废弃版本：9<br>代替接口：osAccount.AccountManager|@ohos.account.osAccount.d.ts|
|废弃版本有变化|类名：AccountManager<br>方法 or 属性：isTestOsAccount(): Promise\<boolean>;<br>废弃版本：N/A|类名：AccountManager<br>方法 or 属性：isTestOsAccount(): Promise\<boolean>;<br>废弃版本：9<br>代替接口：osAccount.AccountManager|@ohos.account.osAccount.d.ts|
|废弃版本有变化|类名：AccountManager<br>方法 or 属性：isOsAccountVerified(callback: AsyncCallback\<boolean>): void;<br>废弃版本：N/A|类名：AccountManager<br>方法 or 属性：isOsAccountVerified(callback: AsyncCallback\<boolean>): void;<br>废弃版本：9<br>代替接口：osAccount.AccountManager|@ohos.account.osAccount.d.ts|
|废弃版本有变化|类名：AccountManager<br>方法 or 属性：isOsAccountVerified(localId: number, callback: AsyncCallback\<boolean>): void;<br>废弃版本：N/A|类名：AccountManager<br>方法 or 属性：isOsAccountVerified(localId: number, callback: AsyncCallback\<boolean>): void;<br>废弃版本：9<br>代替接口：osAccount.AccountManager|@ohos.account.osAccount.d.ts|
|废弃版本有变化|类名：AccountManager<br>方法 or 属性：isOsAccountVerified(localId?: number): Promise\<boolean>;<br>废弃版本：N/A|类名：AccountManager<br>方法 or 属性：isOsAccountVerified(localId?: number): Promise\<boolean>;<br>废弃版本：9<br>代替接口：osAccount.AccountManager|@ohos.account.osAccount.d.ts|
|废弃版本有变化|类名：AccountManager<br>方法 or 属性：getCreatedOsAccountsCount(callback: AsyncCallback\<number>): void;<br>废弃版本：N/A|类名：AccountManager<br>方法 or 属性：getCreatedOsAccountsCount(callback: AsyncCallback\<number>): void;<br>废弃版本：9<br>代替接口：osAccount.AccountManager|@ohos.account.osAccount.d.ts|
|废弃版本有变化|类名：AccountManager<br>方法 or 属性：getCreatedOsAccountsCount(): Promise\<number>;<br>废弃版本：N/A|类名：AccountManager<br>方法 or 属性：getCreatedOsAccountsCount(): Promise\<number>;<br>废弃版本：9<br>代替接口：osAccount.AccountManager|@ohos.account.osAccount.d.ts|
|废弃版本有变化|类名：AccountManager<br>方法 or 属性：getOsAccountLocalIdFromProcess(callback: AsyncCallback\<number>): void;<br>废弃版本：N/A|类名：AccountManager<br>方法 or 属性：getOsAccountLocalIdFromProcess(callback: AsyncCallback\<number>): void;<br>废弃版本：9<br>代替接口：osAccount.AccountManager|@ohos.account.osAccount.d.ts|
|废弃版本有变化|类名：AccountManager<br>方法 or 属性：getOsAccountLocalIdFromProcess(): Promise\<number>;<br>废弃版本：N/A|类名：AccountManager<br>方法 or 属性：getOsAccountLocalIdFromProcess(): Promise\<number>;<br>废弃版本：9<br>代替接口：osAccount.AccountManager|@ohos.account.osAccount.d.ts|
|废弃版本有变化|类名：AccountManager<br>方法 or 属性：getOsAccountLocalIdFromUid(uid: number, callback: AsyncCallback\<number>): void;<br>废弃版本：N/A|类名：AccountManager<br>方法 or 属性：getOsAccountLocalIdFromUid(uid: number, callback: AsyncCallback\<number>): void;<br>废弃版本：9<br>代替接口：osAccount.AccountManager|@ohos.account.osAccount.d.ts|
|废弃版本有变化|类名：AccountManager<br>方法 or 属性：getOsAccountLocalIdFromUid(uid: number): Promise\<number>;<br>废弃版本：N/A|类名：AccountManager<br>方法 or 属性：getOsAccountLocalIdFromUid(uid: number): Promise\<number>;<br>废弃版本：9<br>代替接口：osAccount.AccountManager|@ohos.account.osAccount.d.ts|
|废弃版本有变化|类名：AccountManager<br>方法 or 属性：getOsAccountLocalIdFromDomain(domainInfo: DomainAccountInfo, callback: AsyncCallback\<number>): void;<br>废弃版本：N/A|类名：AccountManager<br>方法 or 属性：getOsAccountLocalIdFromDomain(domainInfo: DomainAccountInfo, callback: AsyncCallback\<number>): void;<br>废弃版本：9<br>代替接口：osAccount.AccountManager|@ohos.account.osAccount.d.ts|
|废弃版本有变化|类名：AccountManager<br>方法 or 属性：getOsAccountLocalIdFromDomain(domainInfo: DomainAccountInfo): Promise\<number>;<br>废弃版本：N/A|类名：AccountManager<br>方法 or 属性：getOsAccountLocalIdFromDomain(domainInfo: DomainAccountInfo): Promise\<number>;<br>废弃版本：9<br>代替接口：osAccount.AccountManager|@ohos.account.osAccount.d.ts|
|废弃版本有变化|类名：AccountManager<br>方法 or 属性：getOsAccountAllConstraints(localId: number, callback: AsyncCallback\<Array\<string>>): void;<br>废弃版本：N/A|类名：AccountManager<br>方法 or 属性：getOsAccountAllConstraints(localId: number, callback: AsyncCallback\<Array\<string>>): void;<br>废弃版本：9<br>代替接口：osAccount.AccountManager|@ohos.account.osAccount.d.ts|
|废弃版本有变化|类名：AccountManager<br>方法 or 属性：getOsAccountAllConstraints(localId: number): Promise\<Array\<string>>;<br>废弃版本：N/A|类名：AccountManager<br>方法 or 属性：getOsAccountAllConstraints(localId: number): Promise\<Array\<string>>;<br>废弃版本：9<br>代替接口：osAccount.AccountManager|@ohos.account.osAccount.d.ts|
|废弃版本有变化|类名：AccountManager<br>方法 or 属性：queryActivatedOsAccountIds(callback: AsyncCallback\<Array\<number>>): void;<br>废弃版本：N/A|类名：AccountManager<br>方法 or 属性：queryActivatedOsAccountIds(callback: AsyncCallback\<Array\<number>>): void;<br>废弃版本：9<br>代替接口：osAccount.AccountManager|@ohos.account.osAccount.d.ts|
|废弃版本有变化|类名：AccountManager<br>方法 or 属性：queryActivatedOsAccountIds(): Promise\<Array\<number>>;<br>废弃版本：N/A|类名：AccountManager<br>方法 or 属性：queryActivatedOsAccountIds(): Promise\<Array\<number>>;<br>废弃版本：9<br>代替接口：osAccount.AccountManager|@ohos.account.osAccount.d.ts|
|废弃版本有变化|类名：AccountManager<br>方法 or 属性：queryCurrentOsAccount(callback: AsyncCallback\<OsAccountInfo>): void;<br>废弃版本：N/A|类名：AccountManager<br>方法 or 属性：queryCurrentOsAccount(callback: AsyncCallback\<OsAccountInfo>): void;<br>废弃版本：9<br>代替接口：osAccount.AccountManager|@ohos.account.osAccount.d.ts|
|废弃版本有变化|类名：AccountManager<br>方法 or 属性：queryCurrentOsAccount(): Promise\<OsAccountInfo>;<br>废弃版本：N/A|类名：AccountManager<br>方法 or 属性：queryCurrentOsAccount(): Promise\<OsAccountInfo>;<br>废弃版本：9<br>代替接口：osAccount.AccountManager|@ohos.account.osAccount.d.ts|
|废弃版本有变化|类名：AccountManager<br>方法 or 属性：getOsAccountTypeFromProcess(callback: AsyncCallback\<OsAccountType>): void;<br>废弃版本：N/A|类名：AccountManager<br>方法 or 属性：getOsAccountTypeFromProcess(callback: AsyncCallback\<OsAccountType>): void;<br>废弃版本：9<br>代替接口：osAccount.AccountManager|@ohos.account.osAccount.d.ts|
|废弃版本有变化|类名：AccountManager<br>方法 or 属性：getOsAccountTypeFromProcess(): Promise\<OsAccountType>;<br>废弃版本：N/A|类名：AccountManager<br>方法 or 属性：getOsAccountTypeFromProcess(): Promise\<OsAccountType>;<br>废弃版本：9<br>代替接口：osAccount.AccountManager|@ohos.account.osAccount.d.ts|
|废弃版本有变化|类名：AccountManager<br>方法 or 属性：getDistributedVirtualDeviceId(callback: AsyncCallback\<string>): void;<br>废弃版本：N/A|类名：AccountManager<br>方法 or 属性：getDistributedVirtualDeviceId(callback: AsyncCallback\<string>): void;<br>废弃版本：9<br>代替接口：osAccount.AccountManager|@ohos.account.osAccount.d.ts|
|废弃版本有变化|类名：AccountManager<br>方法 or 属性：getDistributedVirtualDeviceId(): Promise\<string>;<br>废弃版本：N/A|类名：AccountManager<br>方法 or 属性：getDistributedVirtualDeviceId(): Promise\<string>;<br>废弃版本：9<br>代替接口：osAccount.AccountManager|@ohos.account.osAccount.d.ts|
|废弃版本有变化|类名：AccountManager<br>方法 or 属性：getOsAccountLocalIdBySerialNumber(serialNumber: number, callback: AsyncCallback\<number>): void;<br>废弃版本：N/A|类名：AccountManager<br>方法 or 属性：getOsAccountLocalIdBySerialNumber(serialNumber: number, callback: AsyncCallback\<number>): void;<br>废弃版本：9<br>代替接口：osAccount.AccountManager|@ohos.account.osAccount.d.ts|
|废弃版本有变化|类名：AccountManager<br>方法 or 属性：getOsAccountLocalIdBySerialNumber(serialNumber: number): Promise\<number>;<br>废弃版本：N/A|类名：AccountManager<br>方法 or 属性：getOsAccountLocalIdBySerialNumber(serialNumber: number): Promise\<number>;<br>废弃版本：9<br>代替接口：osAccount.AccountManager|@ohos.account.osAccount.d.ts|
|废弃版本有变化|类名：AccountManager<br>方法 or 属性：getSerialNumberByOsAccountLocalId(localId: number, callback: AsyncCallback\<number>): void;<br>废弃版本：N/A|类名：AccountManager<br>方法 or 属性：getSerialNumberByOsAccountLocalId(localId: number, callback: AsyncCallback\<number>): void;<br>废弃版本：9<br>代替接口：osAccount.AccountManager|@ohos.account.osAccount.d.ts|
|废弃版本有变化|类名：AccountManager<br>方法 or 属性：getSerialNumberByOsAccountLocalId(localId: number): Promise\<number>;<br>废弃版本：N/A|类名：AccountManager<br>方法 or 属性：getSerialNumberByOsAccountLocalId(localId: number): Promise\<number>;<br>废弃版本：9<br>代替接口：osAccount.AccountManager|@ohos.account.osAccount.d.ts|
|起始版本有变化|类名：OAuthTokenInfo<br>方法 or 属性：authType: string;<br>起始版本：N/A|类名：OAuthTokenInfo<br>方法 or 属性：authType: string;<br>起始版本：8|@ohos.account.appAccount.d.ts|
|起始版本有变化|类名：OAuthTokenInfo<br>方法 or 属性：token: string;<br>起始版本：N/A|类名：OAuthTokenInfo<br>方法 or 属性：token: string;<br>起始版本：8|@ohos.account.appAccount.d.ts|
|起始版本有变化|类名：Constants<br>方法 or 属性：ACTION_ADD_ACCOUNT_IMPLICITLY = "addAccountImplicitly"<br>起始版本：N/A|类名：Constants<br>方法 or 属性：ACTION_ADD_ACCOUNT_IMPLICITLY = "addAccountImplicitly"<br>起始版本：8|@ohos.account.appAccount.d.ts|
|起始版本有变化|类名：Constants<br>方法 or 属性：ACTION_AUTHENTICATE = "authenticate"<br>起始版本：N/A|类名：Constants<br>方法 or 属性：ACTION_AUTHENTICATE = "authenticate"<br>起始版本：8|@ohos.account.appAccount.d.ts|
|起始版本有变化|类名：Constants<br>方法 or 属性：KEY_NAME = "name"<br>起始版本：N/A|类名：Constants<br>方法 or 属性：KEY_NAME = "name"<br>起始版本：8|@ohos.account.appAccount.d.ts|
|起始版本有变化|类名：Constants<br>方法 or 属性：KEY_OWNER = "owner"<br>起始版本：N/A|类名：Constants<br>方法 or 属性：KEY_OWNER = "owner"<br>起始版本：8|@ohos.account.appAccount.d.ts|
|起始版本有变化|类名：Constants<br>方法 or 属性：KEY_TOKEN = "token"<br>起始版本：N/A|类名：Constants<br>方法 or 属性：KEY_TOKEN = "token"<br>起始版本：8|@ohos.account.appAccount.d.ts|
|起始版本有变化|类名：Constants<br>方法 or 属性：KEY_ACTION = "action"<br>起始版本：N/A|类名：Constants<br>方法 or 属性：KEY_ACTION = "action"<br>起始版本：8|@ohos.account.appAccount.d.ts|
|起始版本有变化|类名：Constants<br>方法 or 属性：KEY_AUTH_TYPE = "authType"<br>起始版本：N/A|类名：Constants<br>方法 or 属性：KEY_AUTH_TYPE = "authType"<br>起始版本：8|@ohos.account.appAccount.d.ts|
|起始版本有变化|类名：Constants<br>方法 or 属性：KEY_SESSION_ID = "sessionId"<br>起始版本：N/A|类名：Constants<br>方法 or 属性：KEY_SESSION_ID = "sessionId"<br>起始版本：8|@ohos.account.appAccount.d.ts|
|起始版本有变化|类名：Constants<br>方法 or 属性：KEY_CALLER_PID = "callerPid"<br>起始版本：N/A|类名：Constants<br>方法 or 属性：KEY_CALLER_PID = "callerPid"<br>起始版本：8|@ohos.account.appAccount.d.ts|
|起始版本有变化|类名：Constants<br>方法 or 属性：KEY_CALLER_UID = "callerUid"<br>起始版本：N/A|类名：Constants<br>方法 or 属性：KEY_CALLER_UID = "callerUid"<br>起始版本：8|@ohos.account.appAccount.d.ts|
|起始版本有变化|类名：Constants<br>方法 or 属性：KEY_CALLER_BUNDLE_NAME = "callerBundleName"<br>起始版本：N/A|类名：Constants<br>方法 or 属性：KEY_CALLER_BUNDLE_NAME = "callerBundleName"<br>起始版本：8|@ohos.account.appAccount.d.ts|
|起始版本有变化|类名：DistributedInfo<br>方法 or 属性：name: string;<br>起始版本：N/A|类名：DistributedInfo<br>方法 or 属性：name: string;<br>起始版本：7|@ohos.account.distributedAccount.d.ts|
|起始版本有变化|类名：DistributedInfo<br>方法 or 属性：id: string;<br>起始版本：N/A|类名：DistributedInfo<br>方法 or 属性：id: string;<br>起始版本：7|@ohos.account.distributedAccount.d.ts|
|起始版本有变化|类名：DistributedInfo<br>方法 or 属性：event: string;<br>起始版本：N/A|类名：DistributedInfo<br>方法 or 属性：event: string;<br>起始版本：7|@ohos.account.distributedAccount.d.ts|
|起始版本有变化|类名：PINAuth<br>方法 or 属性：unregisterInputer(): void;<br>起始版本：N/A|类名：PINAuth<br>方法 or 属性：unregisterInputer(): void;<br>起始版本：8|@ohos.account.osAccount.d.ts|
|权限有变化|类名：UserIdentityManager<br>方法 or 属性：getAuthInfo(authType?: AuthType): Promise\<Array\<EnrolledCredInfo>>;<br>权限:ohos.permission.ACCESS_USER_IDM|类名：UserIdentityManager<br>方法 or 属性：getAuthInfo(authType?: AuthType): Promise\<Array\<EnrolledCredInfo>>;<br>权限:ohos.permission.USE_USER_IDM|@ohos.account.osAccount.d.ts|
|新增(错误码)|NA|类名：AccountManager<br>方法 or 属性：activateOsAccount(localId: number, callback: AsyncCallback\<void>): void;<br>错误码内容: 201, 401, 12300001, 12300002, 12300003, 12300008, 12300009|@ohos.account.osAccount.d.ts|
|新增(错误码)|NA|类名：AccountManager<br>方法 or 属性：activateOsAccount(localId: number): Promise\<void>;<br>错误码内容: 201, 401, 12300001, 12300002, 12300003, 12300008, 12300009|@ohos.account.osAccount.d.ts|
|新增(错误码)|NA|类名：AccountManager<br>方法 or 属性：removeOsAccount(localId: number, callback: AsyncCallback\<void>): void;<br>错误码内容: 201, 401, 12300001, 12300002, 12300003, 12300008|@ohos.account.osAccount.d.ts|
|新增(错误码)|NA|类名：AccountManager<br>方法 or 属性：removeOsAccount(localId: number): Promise\<void>;<br>错误码内容: 201, 401, 12300001, 12300002, 12300003, 12300008|@ohos.account.osAccount.d.ts|
|新增(错误码)|NA|类名：AccountManager<br>方法 or 属性：setOsAccountConstraints(localId: number, constraints: Array\<string>, enable: boolean,<br>                                callback: AsyncCallback\<void>): void;<br>错误码内容: 201, 401, 12300001, 12300002, 12300003, 12300008|@ohos.account.osAccount.d.ts|
|新增(错误码)|NA|类名：AccountManager<br>方法 or 属性：setOsAccountConstraints(localId: number, constraints: Array\<string>, enable: boolean): Promise\<void>;<br>错误码内容: 201, 401, 12300001, 12300002, 12300003, 12300008|@ohos.account.osAccount.d.ts|
|新增(错误码)|NA|类名：AccountManager<br>方法 or 属性：setOsAccountName(localId: number, localName: string, callback: AsyncCallback\<void>): void;<br>错误码内容: 201, 401, 12300001, 12300002, 12300003, 12300008|@ohos.account.osAccount.d.ts|
|新增(错误码)|NA|类名：AccountManager<br>方法 or 属性：setOsAccountName(localId: number, localName: string): Promise\<void>;<br>错误码内容: 201, 401, 12300001, 12300002, 12300003, 12300008|@ohos.account.osAccount.d.ts|
|新增(错误码)|NA|类名：AccountManager<br>方法 or 属性：queryMaxOsAccountNumber(callback: AsyncCallback\<number>): void;<br>错误码内容: 401, 12300001|@ohos.account.osAccount.d.ts|
|新增(错误码)|NA|类名：AccountManager<br>方法 or 属性：queryMaxOsAccountNumber(): Promise\<number>;<br>错误码内容: 401, 12300001|@ohos.account.osAccount.d.ts|
|新增(错误码)|NA|类名：AccountManager<br>方法 or 属性：queryAllCreatedOsAccounts(callback: AsyncCallback\<Array\<OsAccountInfo>>): void;<br>错误码内容: 201, 401, 12300001|@ohos.account.osAccount.d.ts|
|新增(错误码)|NA|类名：AccountManager<br>方法 or 属性：queryAllCreatedOsAccounts(): Promise\<Array\<OsAccountInfo>>;<br>错误码内容: 201, 401, 12300001|@ohos.account.osAccount.d.ts|
|新增(错误码)|NA|类名：AccountManager<br>方法 or 属性：createOsAccount(localName: string, type: OsAccountType, callback: AsyncCallback\<OsAccountInfo>): void;<br>错误码内容: 201, 401, 12300001, 12300002, 12300005, 12300006, 12300007|@ohos.account.osAccount.d.ts|
|新增(错误码)|NA|类名：AccountManager<br>方法 or 属性：createOsAccount(localName: string, type: OsAccountType): Promise\<OsAccountInfo>;<br>错误码内容: 201, 401, 12300001, 12300002, 12300005, 12300006, 12300007|@ohos.account.osAccount.d.ts|
|新增(错误码)|NA|类名：AccountManager<br>方法 or 属性：createOsAccountForDomain(type: OsAccountType, domainInfo: DomainAccountInfo, callback: AsyncCallback\<OsAccountInfo>): void;<br>错误码内容: 201, 401, 12300001, 12300002, 12300005, 12300006, 12300007|@ohos.account.osAccount.d.ts|
|新增(错误码)|NA|类名：AccountManager<br>方法 or 属性：createOsAccountForDomain(type: OsAccountType, domainInfo: DomainAccountInfo): Promise\<OsAccountInfo>;<br>错误码内容: 201, 401, 12300001, 12300002, 12300005, 12300006, 12300007|@ohos.account.osAccount.d.ts|
|新增(错误码)|NA|类名：AccountManager<br>方法 or 属性：queryOsAccountById(localId: number, callback: AsyncCallback\<OsAccountInfo>): void;<br>错误码内容: 201, 401, 12300001, 12300002, 12300003|@ohos.account.osAccount.d.ts|
|新增(错误码)|NA|类名：AccountManager<br>方法 or 属性：queryOsAccountById(localId: number): Promise\<OsAccountInfo>;<br>错误码内容: 201, 401, 12300001, 12300002, 12300003|@ohos.account.osAccount.d.ts|
|新增(错误码)|NA|类名：AccountManager<br>方法 or 属性：getOsAccountProfilePhoto(localId: number, callback: AsyncCallback\<string>): void;<br>错误码内容: 201, 401, 12300001, 12300002, 12300003|@ohos.account.osAccount.d.ts|
|新增(错误码)|NA|类名：AccountManager<br>方法 or 属性：getOsAccountProfilePhoto(localId: number): Promise\<string>;<br>错误码内容: 201, 401, 12300001, 12300002, 12300003|@ohos.account.osAccount.d.ts|
|新增(错误码)|NA|类名：AccountManager<br>方法 or 属性：setOsAccountProfilePhoto(localId: number, photo: string, callback: AsyncCallback\<void>): void;<br>错误码内容: 201, 401, 12300001, 12300002, 12300003, 12300008|@ohos.account.osAccount.d.ts|
|新增(错误码)|NA|类名：AccountManager<br>方法 or 属性：setOsAccountProfilePhoto(localId: number, photo: string): Promise\<void>;<br>错误码内容: 201, 401, 12300001, 12300002, 12300003, 12300008|@ohos.account.osAccount.d.ts|
|新增(错误码)|NA|类名：AccountManager<br>方法 or 属性：on(type: 'activate' \| 'activating', name: string, callback: Callback\<number>): void;<br>错误码内容: 201, 401, 12300001, 12300002, 12300011|@ohos.account.osAccount.d.ts|
|新增(错误码)|NA|类名：AccountManager<br>方法 or 属性：on(type: 'activate' \| 'activating', name: string, callback: Callback\<number>): void;<br>错误码内容: 201, 401, 12300001, 12300002, 12300011|@ohos.account.osAccount.d.ts|
|新增(错误码)|NA|类名：AccountManager<br>方法 or 属性：off(type: 'activate' \| 'activating', name: string, callback?: Callback\<number>): void;<br>错误码内容: 201, 401, 12300001, 12300002, 12300012|@ohos.account.osAccount.d.ts|
|新增(错误码)|NA|类名：AccountManager<br>方法 or 属性：off(type: 'activate' \| 'activating', name: string, callback?: Callback\<number>): void;<br>错误码内容: 201, 401, 12300001, 12300002, 12300012|@ohos.account.osAccount.d.ts|
|新增(错误码)|NA|类名：UserAuth<br>方法 or 属性：getAvailableStatus(authType: AuthType, authTrustLevel: AuthTrustLevel): number;<br>错误码内容: 201, 401, 12300001, 12300002|@ohos.account.osAccount.d.ts|
|新增(错误码)|NA|类名：UserAuth<br>方法 or 属性：getProperty(request: GetPropertyRequest, callback: AsyncCallback\<ExecutorProperty>): void;<br>错误码内容: 201, 401, 12300001, 12300002|@ohos.account.osAccount.d.ts|
|新增(错误码)|NA|类名：UserAuth<br>方法 or 属性：getProperty(request: GetPropertyRequest): Promise\<ExecutorProperty>;<br>错误码内容: 201, 401, 12300001, 12300002|@ohos.account.osAccount.d.ts|
|新增(错误码)|NA|类名：UserAuth<br>方法 or 属性：auth(challenge: Uint8Array, authType: AuthType, authTrustLevel: AuthTrustLevel, callback: IUserAuthCallback): Uint8Array;<br>错误码内容: 201, 401, 12300001, 12300002, 12300101, 12300105, 12300106, 12300110, 12300111, 12300112|@ohos.account.osAccount.d.ts|
|新增(错误码)|NA|类名：UserAuth<br>方法 or 属性：authUser(userId: number, challenge: Uint8Array, authType: AuthType, authTrustLevel: AuthTrustLevel, callback: IUserAuthCallback): Uint8Array;<br>错误码内容: 201, 401, 12300001, 12300002, 12300101, 12300105, 12300106, 12300110, 12300111, 12300112|@ohos.account.osAccount.d.ts|
|新增(错误码)|NA|类名：PINAuth<br>方法 or 属性：unregisterInputer(): void;<br>错误码内容: 201|@ohos.account.osAccount.d.ts|
|新增(错误码)|NA|类名：UserIdentityManager<br>方法 or 属性：openSession(callback: AsyncCallback\<Uint8Array>): void;<br>错误码内容: 201, 401, 12300001|@ohos.account.osAccount.d.ts|
|新增(错误码)|NA|类名：UserIdentityManager<br>方法 or 属性：openSession(): Promise\<Uint8Array>;<br>错误码内容: 201, 401, 12300001|@ohos.account.osAccount.d.ts|
|新增(错误码)|NA|类名：UserIdentityManager<br>方法 or 属性：addCredential(credentialInfo: CredentialInfo, callback: IIdmCallback): void;<br>错误码内容: 201, 401, 12300001, 12300002, 12300101, 12300106|@ohos.account.osAccount.d.ts|
|新增(错误码)|NA|类名：UserIdentityManager<br>方法 or 属性：updateCredential(credentialInfo: CredentialInfo, callback: IIdmCallback): void;<br>错误码内容: 201, 401, 12300001, 12300002, 12300101, 12300106|@ohos.account.osAccount.d.ts|
|新增(错误码)|NA|类名：UserIdentityManager<br>方法 or 属性：closeSession(): void;<br>错误码内容: 201|@ohos.account.osAccount.d.ts|
|新增(错误码)|NA|类名：UserIdentityManager<br>方法 or 属性：delUser(token: Uint8Array, callback: IIdmCallback): void;<br>错误码内容: 201, 401, 12300001, 12300101|@ohos.account.osAccount.d.ts|
|新增(错误码)|NA|类名：UserIdentityManager<br>方法 or 属性：delCred(credentialId: Uint8Array, token: Uint8Array, callback: IIdmCallback): void;<br>错误码内容: 201, 401, 12300001, 12300002, 12300101, 12300102|@ohos.account.osAccount.d.ts|
|新增(错误码)|NA|类名：UserIdentityManager<br>方法 or 属性：getAuthInfo(authType?: AuthType): Promise\<Array\<EnrolledCredInfo>>;<br>错误码内容: 201, 401, 12300001, 12300002, 12300102|@ohos.account.osAccount.d.ts|
|新增(权限)|类名：AccountManager<br>方法 or 属性：isOsAccountVerified(callback: AsyncCallback\<boolean>): void;<br>权限:N/A|类名：AccountManager<br>方法 or 属性：isOsAccountVerified(callback: AsyncCallback\<boolean>): void;<br>权限:ohos.permission.MANAGE_LOCAL_ACCOUNTS or ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS|@ohos.account.osAccount.d.ts|
|函数有变化|类名：AppAccountManager<br>方法 or 属性：getAllAccounts(owner: string, callback: AsyncCallback\<Array\<AppAccountInfo>>): void;<br>|类名：AppAccountManager<br>方法 or 属性：getAllAccounts(callback: AsyncCallback\<Array\<AppAccountInfo>>): void;<br>|@ohos.account.appAccount.d.ts|
|函数有变化|类名：AppAccountManager<br>方法 or 属性：getAllAccounts(owner: string): Promise\<Array\<AppAccountInfo>>;<br>|类名：AppAccountManager<br>方法 or 属性：getAllAccounts(): Promise\<Array\<AppAccountInfo>>;<br>|@ohos.account.appAccount.d.ts|
|函数有变化|类名：AppAccountManager<br>方法 or 属性：getAllAccounts(owner: string, callback: AsyncCallback\<Array\<AppAccountInfo>>): void;<br>|类名：AppAccountManager<br>方法 or 属性：getAllAccounts(owner: string, callback: AsyncCallback\<Array\<AppAccountInfo>>): void;<br>|@ohos.account.appAccount.d.ts|
|函数有变化|类名：AppAccountManager<br>方法 or 属性：getAllAccounts(owner: string): Promise\<Array\<AppAccountInfo>>;<br>|类名：AppAccountManager<br>方法 or 属性：getAllAccounts(owner: string): Promise\<Array\<AppAccountInfo>>;<br>|@ohos.account.appAccount.d.ts|
|函数有变化|类名：UserAuth<br>方法 or 属性：setProperty(request: SetPropertyRequest, callback: AsyncCallback\<number>): void;<br>|类名：UserAuth<br>方法 or 属性：setProperty(request: SetPropertyRequest, callback: AsyncCallback\<void>): void;<br>|@ohos.account.osAccount.d.ts|
|函数有变化|类名：UserAuth<br>方法 or 属性：setProperty(request: SetPropertyRequest): Promise\<number>;<br>|类名：UserAuth<br>方法 or 属性：setProperty(request: SetPropertyRequest): Promise\<void>;<br>|@ohos.account.osAccount.d.ts|
|函数有变化|类名：UserAuth<br>方法 or 属性：cancelAuth(contextID: Uint8Array): number;<br>|类名：UserAuth<br>方法 or 属性：cancelAuth(contextID: Uint8Array): void;<br>|@ohos.account.osAccount.d.ts|
|函数有变化|类名：PINAuth<br>方法 or 属性：registerInputer(inputer: IInputer): boolean;<br>|类名：PINAuth<br>方法 or 属性：registerInputer(inputer: IInputer): void;<br>|@ohos.account.osAccount.d.ts|
|函数有变化|类名：UserIdentityManager<br>方法 or 属性：cancel(challenge: Uint8Array): number;<br>|类名：UserIdentityManager<br>方法 or 属性：cancel(challenge: Uint8Array): void;<br>|@ohos.account.osAccount.d.ts|
|函数有变化|类名：IInputData<br>方法 or 属性：onSetData: (pinSubType: AuthSubType, data: Uint8Array) => void;<br>|类名：IInputData<br>方法 or 属性：onSetData: (authSubType: AuthSubType, data: Uint8Array) => void;<br>|@ohos.account.osAccount.d.ts|
|函数有变化|类名：IInputer<br>方法 or 属性：onGetData: (callback: IInputData) => void;<br>|类名：IInputer<br>方法 or 属性：onGetData: (authSubType: AuthSubType, callback: IInputData) => void;<br>|@ohos.account.osAccount.d.ts|
