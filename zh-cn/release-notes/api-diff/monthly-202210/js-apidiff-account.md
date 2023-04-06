| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|方法名 or 属性名：getAllAccounts<br>函数：getAllAccounts(callback: AsyncCallback<Array<AppAccountInfo>>): void;|@ohos.account.appAccount.d.ts|
|新增|NA|方法名 or 属性名：getAllAccounts<br>函数：getAllAccounts(): Promise<Array<AppAccountInfo>>;|@ohos.account.appAccount.d.ts|
|新增|NA|方法名 or 属性名：selectAccountsByOptions<br>函数：selectAccountsByOptions(options: SelectAccountsOptions, callback: AsyncCallback<Array<AppAccountInfo>>): void;|@ohos.account.appAccount.d.ts|
|新增|NA|方法名 or 属性名：verifyCredential<br>函数：verifyCredential(name: string, owner: string, callback: AuthCallback): void;|@ohos.account.appAccount.d.ts|
|新增|NA|方法名 or 属性名：verifyCredential<br>函数：verifyCredential(name: string, owner: string, options: VerifyCredentialOptions, callback: AuthCallback): void;|@ohos.account.appAccount.d.ts|
|新增|NA|方法名 or 属性名：setAuthenticatorProperties<br>函数：setAuthenticatorProperties(owner: string, callback: AuthCallback): void;|@ohos.account.appAccount.d.ts|
|新增|NA|方法名 or 属性名：setAuthenticatorProperties<br>函数：setAuthenticatorProperties(owner: string, options: SetPropertiesOptions, callback: AuthCallback): void;|@ohos.account.appAccount.d.ts|
|新增|NA|模块名: ohos.account.appAccount<br>类名: AuthTokenInfo|@ohos.account.appAccount.d.ts|
|新增|NA|模块名: ohos.account.appAccount<br>类名: AuthTokenInfo<br>方法名 or 属性名：authType|@ohos.account.appAccount.d.ts|
|新增|NA|模块名: ohos.account.appAccount<br>类名: AuthTokenInfo<br>方法名 or 属性名：token|@ohos.account.appAccount.d.ts|
|新增|NA|模块名: ohos.account.appAccount<br>类名: AuthTokenInfo<br>方法名 or 属性名：account|@ohos.account.appAccount.d.ts|
|新增|NA|模块名: ohos.account.appAccount<br>类名: AuthResult|@ohos.account.appAccount.d.ts|
|新增|NA|模块名: ohos.account.appAccount<br>类名: AuthResult<br>方法名 or 属性名：account|@ohos.account.appAccount.d.ts|
|新增|NA|模块名: ohos.account.appAccount<br>类名: AuthResult<br>方法名 or 属性名：tokenInfo|@ohos.account.appAccount.d.ts|
|新增|NA|模块名: ohos.account.appAccount<br>类名: CreateAccountOptions|@ohos.account.appAccount.d.ts|
|新增|NA|模块名: ohos.account.appAccount<br>类名: CreateAccountOptions<br>方法名 or 属性名：customData|@ohos.account.appAccount.d.ts|
|新增|NA|模块名: ohos.account.appAccount<br>类名: CreateAccountImplicitlyOptions|@ohos.account.appAccount.d.ts|
|新增|NA|模块名: ohos.account.appAccount<br>类名: CreateAccountImplicitlyOptions<br>方法名 or 属性名：requiredLabels|@ohos.account.appAccount.d.ts|
|新增|NA|模块名: ohos.account.appAccount<br>类名: CreateAccountImplicitlyOptions<br>方法名 or 属性名：authType|@ohos.account.appAccount.d.ts|
|新增|NA|模块名: ohos.account.appAccount<br>类名: CreateAccountImplicitlyOptions<br>方法名 or 属性名：parameters|@ohos.account.appAccount.d.ts|
|新增|NA|模块名: ohos.account.appAccount<br>类名: AuthCallback|@ohos.account.appAccount.d.ts|
|新增|NA|模块名: ohos.account.appAccount<br>类名: AuthCallback<br>方法名 or 属性名：onResult|@ohos.account.appAccount.d.ts|
|新增|NA|模块名: ohos.account.appAccount<br>类名: AuthCallback<br>方法名 or 属性名：onRequestRedirected|@ohos.account.appAccount.d.ts|
|新增|NA|模块名: ohos.account.appAccount<br>类名: AuthCallback<br>方法名 or 属性名：onRequestContinued|@ohos.account.appAccount.d.ts|
|新增|NA|方法名 or 属性名：verifyCredential<br>函数：verifyCredential(name: string, options: VerifyCredentialOptions, callback: AuthCallback): void;|@ohos.account.appAccount.d.ts|
|新增|NA|方法名 or 属性名：setProperties<br>函数：setProperties(options: SetPropertiesOptions, callback: AuthCallback): void;|@ohos.account.appAccount.d.ts|
|新增|NA|方法名 or 属性名：checkAccountLabels<br>函数：checkAccountLabels(name: string, labels: Array<string>, callback: AuthCallback): void;|@ohos.account.appAccount.d.ts|
|新增|NA|方法名 or 属性名：isAccountRemovable<br>函数：isAccountRemovable(name: string, callback: AuthCallback): void;|@ohos.account.appAccount.d.ts|
|新增|NA|模块名: ohos.account.distributedAccount<br>类名: DistributedInfo<br>方法名 or 属性名：nickname|@ohos.account.distributedAccount.d.ts|
|新增|NA|模块名: ohos.account.distributedAccount<br>类名: DistributedInfo<br>方法名 or 属性名：avatar|@ohos.account.distributedAccount.d.ts|
|新增|NA|方法名 or 属性名：cancelAuth<br>函数：cancelAuth(contextID: Uint8Array): void;|@ohos.account.osAccount.d.ts|
|新增|NA|方法名 or 属性名：registerInputer<br>函数：registerInputer(inputer: IInputer): void;|@ohos.account.osAccount.d.ts|
|新增|NA|方法名 or 属性名：cancel<br>函数：cancel(challenge: Uint8Array): void;|@ohos.account.osAccount.d.ts|
|删除|模块名：ohos.account.appAccount<br>类名:AppAccountManager<br>方法名 or 属性名:getAssociatedDataSync|NA|@ohos.account.appAccount.d.ts|
|删除|模块名：ohos.account.appAccount<br>类名:AppAccountManager<br>方法名 or 属性名:deleteAccountCredential|NA|@ohos.account.appAccount.d.ts|
|删除|模块名：ohos.account.appAccount<br>类名:AppAccountManager<br>方法名 or 属性名:deleteAccountCredential|NA|@ohos.account.appAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：addAccount<br>废弃版本：N/A|方法名 or 属性名：addAccount<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：addAccount<br>废弃版本：N/A|方法名 or 属性名：addAccount<br>废弃版本：9|@ohos.account.appAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：addAccount<br>废弃版本：N/A|方法名 or 属性名：addAccount<br>废弃版本：9|@ohos.account.appAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：addAccountImplicitly<br>废弃版本：N/A|方法名 or 属性名：addAccountImplicitly<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：deleteAccount<br>废弃版本：N/A|方法名 or 属性名：deleteAccount<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：deleteAccount<br>废弃版本：N/A|方法名 or 属性名：deleteAccount<br>废弃版本：9|@ohos.account.appAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：disableAppAccess<br>废弃版本：N/A|方法名 or 属性名：disableAppAccess<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：disableAppAccess<br>废弃版本：N/A|方法名 or 属性名：disableAppAccess<br>废弃版本：9|@ohos.account.appAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：enableAppAccess<br>废弃版本：N/A|方法名 or 属性名：enableAppAccess<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：enableAppAccess<br>废弃版本：N/A|方法名 or 属性名：enableAppAccess<br>废弃版本：9|@ohos.account.appAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：checkAppAccountSyncEnable<br>废弃版本：N/A|方法名 or 属性名：checkAppAccountSyncEnable<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：checkAppAccountSyncEnable<br>废弃版本：N/A|方法名 or 属性名：checkAppAccountSyncEnable<br>废弃版本：9|@ohos.account.appAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：setAccountCredential<br>废弃版本：N/A|方法名 or 属性名：setAccountCredential<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：setAccountCredential<br>废弃版本：N/A|方法名 or 属性名：setAccountCredential<br>废弃版本：9|@ohos.account.appAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：setAccountExtraInfo<br>废弃版本：N/A|方法名 or 属性名：setAccountExtraInfo<br>废弃版本：9|@ohos.account.appAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：setAccountExtraInfo<br>废弃版本：N/A|方法名 or 属性名：setAccountExtraInfo<br>废弃版本：9|@ohos.account.appAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：setAppAccountSyncEnable<br>废弃版本：N/A|方法名 or 属性名：setAppAccountSyncEnable<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：setAppAccountSyncEnable<br>废弃版本：N/A|方法名 or 属性名：setAppAccountSyncEnable<br>废弃版本：9|@ohos.account.appAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：setAssociatedData<br>废弃版本：N/A|方法名 or 属性名：setAssociatedData<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：setAssociatedData<br>废弃版本：N/A|方法名 or 属性名：setAssociatedData<br>废弃版本：9|@ohos.account.appAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：getAllAccessibleAccounts<br>废弃版本：N/A|方法名 or 属性名：getAllAccessibleAccounts<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：getAllAccessibleAccounts<br>废弃版本：N/A|方法名 or 属性名：getAllAccessibleAccounts<br>废弃版本：9|@ohos.account.appAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：getAllAccounts<br>废弃版本：N/A|方法名 or 属性名：getAllAccounts<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：getAllAccounts<br>废弃版本：N/A|方法名 or 属性名：getAllAccounts<br>废弃版本：9|@ohos.account.appAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：getAccountCredential<br>废弃版本：N/A|方法名 or 属性名：getAccountCredential<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：getAccountCredential<br>废弃版本：N/A|方法名 or 属性名：getAccountCredential<br>废弃版本：9|@ohos.account.appAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：getAccountExtraInfo<br>废弃版本：N/A|方法名 or 属性名：getAccountExtraInfo<br>废弃版本：9|@ohos.account.appAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：getAccountExtraInfo<br>废弃版本：N/A|方法名 or 属性名：getAccountExtraInfo<br>废弃版本：9|@ohos.account.appAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：getAssociatedData<br>废弃版本：N/A|方法名 or 属性名：getAssociatedData<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：getAssociatedData<br>废弃版本：N/A|方法名 or 属性名：getAssociatedData<br>废弃版本：9|@ohos.account.appAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：on_change<br>废弃版本：N/A|方法名 or 属性名：on_change<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：off_change<br>废弃版本：N/A|方法名 or 属性名：off_change<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：authenticate<br>废弃版本：N/A|方法名 or 属性名：authenticate<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：getOAuthToken<br>废弃版本：N/A|方法名 or 属性名：getOAuthToken<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：getOAuthToken<br>废弃版本：N/A|方法名 or 属性名：getOAuthToken<br>废弃版本：9|@ohos.account.appAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：setOAuthToken<br>废弃版本：N/A|方法名 or 属性名：setOAuthToken<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：setOAuthToken<br>废弃版本：N/A|方法名 or 属性名：setOAuthToken<br>废弃版本：9|@ohos.account.appAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：deleteOAuthToken<br>废弃版本：N/A|方法名 or 属性名：deleteOAuthToken<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：deleteOAuthToken<br>废弃版本：N/A|方法名 or 属性名：deleteOAuthToken<br>废弃版本：9|@ohos.account.appAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：setOAuthTokenVisibility<br>废弃版本：N/A|方法名 or 属性名：setOAuthTokenVisibility<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：setOAuthTokenVisibility<br>废弃版本：N/A|方法名 or 属性名：setOAuthTokenVisibility<br>废弃版本：9|@ohos.account.appAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：checkOAuthTokenVisibility<br>废弃版本：N/A|方法名 or 属性名：checkOAuthTokenVisibility<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：checkOAuthTokenVisibility<br>废弃版本：N/A|方法名 or 属性名：checkOAuthTokenVisibility<br>废弃版本：9|@ohos.account.appAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：getAllOAuthTokens<br>废弃版本：N/A|方法名 or 属性名：getAllOAuthTokens<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：getAllOAuthTokens<br>废弃版本：N/A|方法名 or 属性名：getAllOAuthTokens<br>废弃版本：9|@ohos.account.appAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：getOAuthList<br>废弃版本：N/A|方法名 or 属性名：getOAuthList<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：getOAuthList<br>废弃版本：N/A|方法名 or 属性名：getOAuthList<br>废弃版本：9|@ohos.account.appAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：getAuthenticatorCallback<br>废弃版本：N/A|方法名 or 属性名：getAuthenticatorCallback<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：getAuthenticatorCallback<br>废弃版本：N/A|方法名 or 属性名：getAuthenticatorCallback<br>废弃版本：9|@ohos.account.appAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：getAuthenticatorInfo<br>废弃版本：N/A|方法名 or 属性名：getAuthenticatorInfo<br>废弃版本：9<br>代替接口：appAccount.AppAccountManager|@ohos.account.appAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：getAuthenticatorInfo<br>废弃版本：N/A|方法名 or 属性名：getAuthenticatorInfo<br>废弃版本：9|@ohos.account.appAccount.d.ts|
|废弃版本有变化|类名：OAuthTokenInfo<br>废弃版本：N/A|类名：OAuthTokenInfo<br>废弃版本：9<br>代替接口：appAccount.AuthTokenInfo     |@ohos.account.appAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：ACTION_ADD_ACCOUNT_IMPLICITLY<br>废弃版本：N/A|方法名 or 属性名：ACTION_ADD_ACCOUNT_IMPLICITLY<br>废弃版本：9<br>代替接口：appAccount.Constants|@ohos.account.appAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：ACTION_AUTHENTICATE<br>废弃版本：N/A|方法名 or 属性名：ACTION_AUTHENTICATE<br>废弃版本：9<br>代替接口：appAccount.Constants|@ohos.account.appAccount.d.ts|
|废弃版本有变化|类名：ResultCode<br>废弃版本：N/A|类名：ResultCode<br>废弃版本：9|@ohos.account.appAccount.d.ts|
|废弃版本有变化|类名：AuthenticatorCallback<br>废弃版本：N/A|类名：AuthenticatorCallback<br>废弃版本：9<br>代替接口：AppAccount.AuthCallback     |@ohos.account.appAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：addAccountImplicitly<br>废弃版本：N/A|方法名 or 属性名：addAccountImplicitly<br>废弃版本：9<br>代替接口：appAccount.Authenticator|@ohos.account.appAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：authenticate<br>废弃版本：N/A|方法名 or 属性名：authenticate<br>废弃版本：9<br>代替接口：appAccount.Authenticator|@ohos.account.appAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：queryOsAccountDistributedInfo<br>废弃版本：N/A|方法名 or 属性名：queryOsAccountDistributedInfo<br>废弃版本：9<br>代替接口：distributedAccount.DistributedAccountAbility|@ohos.account.distributedAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：queryOsAccountDistributedInfo<br>废弃版本：N/A|方法名 or 属性名：queryOsAccountDistributedInfo<br>废弃版本：9|@ohos.account.distributedAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：updateOsAccountDistributedInfo<br>废弃版本：N/A|方法名 or 属性名：updateOsAccountDistributedInfo<br>废弃版本：9<br>代替接口：distributedAccount.DistributedAccountAbility|@ohos.account.distributedAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：updateOsAccountDistributedInfo<br>废弃版本：N/A|方法名 or 属性名：updateOsAccountDistributedInfo<br>废弃版本：9|@ohos.account.distributedAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：isMultiOsAccountEnable<br>废弃版本：N/A|方法名 or 属性名：isMultiOsAccountEnable<br>废弃版本：9<br>代替接口：osAccount.AccountManager|@ohos.account.osAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：isMultiOsAccountEnable<br>废弃版本：N/A|方法名 or 属性名：isMultiOsAccountEnable<br>废弃版本：9|@ohos.account.osAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：isOsAccountActived<br>废弃版本：N/A|方法名 or 属性名：isOsAccountActived<br>废弃版本：9<br>代替接口：osAccount.AccountManager|@ohos.account.osAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：isOsAccountActived<br>废弃版本：N/A|方法名 or 属性名：isOsAccountActived<br>废弃版本：9|@ohos.account.osAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：isOsAccountConstraintEnable<br>废弃版本：N/A|方法名 or 属性名：isOsAccountConstraintEnable<br>废弃版本：9<br>代替接口：osAccount.AccountManager|@ohos.account.osAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：isOsAccountConstraintEnable<br>废弃版本：N/A|方法名 or 属性名：isOsAccountConstraintEnable<br>废弃版本：9|@ohos.account.osAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：isTestOsAccount<br>废弃版本：N/A|方法名 or 属性名：isTestOsAccount<br>废弃版本：9<br>代替接口：osAccount.AccountManager|@ohos.account.osAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：isTestOsAccount<br>废弃版本：N/A|方法名 or 属性名：isTestOsAccount<br>废弃版本：9|@ohos.account.osAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：isOsAccountVerified<br>废弃版本：N/A|方法名 or 属性名：isOsAccountVerified<br>废弃版本：9<br>代替接口：osAccount.AccountManager|@ohos.account.osAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：isOsAccountVerified<br>废弃版本：N/A|方法名 or 属性名：isOsAccountVerified<br>废弃版本：9|@ohos.account.osAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：isOsAccountVerified<br>废弃版本：N/A|方法名 or 属性名：isOsAccountVerified<br>废弃版本：9|@ohos.account.osAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：getCreatedOsAccountsCount<br>废弃版本：N/A|方法名 or 属性名：getCreatedOsAccountsCount<br>废弃版本：9<br>代替接口：osAccount.AccountManager|@ohos.account.osAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：getCreatedOsAccountsCount<br>废弃版本：N/A|方法名 or 属性名：getCreatedOsAccountsCount<br>废弃版本：9|@ohos.account.osAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：getOsAccountLocalIdFromProcess<br>废弃版本：N/A|方法名 or 属性名：getOsAccountLocalIdFromProcess<br>废弃版本：9<br>代替接口：osAccount.AccountManager|@ohos.account.osAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：getOsAccountLocalIdFromProcess<br>废弃版本：N/A|方法名 or 属性名：getOsAccountLocalIdFromProcess<br>废弃版本：9|@ohos.account.osAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：getOsAccountLocalIdFromUid<br>废弃版本：N/A|方法名 or 属性名：getOsAccountLocalIdFromUid<br>废弃版本：9<br>代替接口：osAccount.AccountManager|@ohos.account.osAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：getOsAccountLocalIdFromUid<br>废弃版本：N/A|方法名 or 属性名：getOsAccountLocalIdFromUid<br>废弃版本：9|@ohos.account.osAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：getOsAccountLocalIdFromDomain<br>废弃版本：N/A|方法名 or 属性名：getOsAccountLocalIdFromDomain<br>废弃版本：9<br>代替接口：osAccount.AccountManager|@ohos.account.osAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：getOsAccountLocalIdFromDomain<br>废弃版本：N/A|方法名 or 属性名：getOsAccountLocalIdFromDomain<br>废弃版本：9|@ohos.account.osAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：getOsAccountAllConstraints<br>废弃版本：N/A|方法名 or 属性名：getOsAccountAllConstraints<br>废弃版本：9<br>代替接口：osAccount.AccountManager|@ohos.account.osAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：getOsAccountAllConstraints<br>废弃版本：N/A|方法名 or 属性名：getOsAccountAllConstraints<br>废弃版本：9|@ohos.account.osAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：queryActivatedOsAccountIds<br>废弃版本：N/A|方法名 or 属性名：queryActivatedOsAccountIds<br>废弃版本：9<br>代替接口：osAccount.AccountManager|@ohos.account.osAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：queryActivatedOsAccountIds<br>废弃版本：N/A|方法名 or 属性名：queryActivatedOsAccountIds<br>废弃版本：9|@ohos.account.osAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：queryCurrentOsAccount<br>废弃版本：N/A|方法名 or 属性名：queryCurrentOsAccount<br>废弃版本：9<br>代替接口：osAccount.AccountManager|@ohos.account.osAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：queryCurrentOsAccount<br>废弃版本：N/A|方法名 or 属性名：queryCurrentOsAccount<br>废弃版本：9|@ohos.account.osAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：getOsAccountTypeFromProcess<br>废弃版本：N/A|方法名 or 属性名：getOsAccountTypeFromProcess<br>废弃版本：9<br>代替接口：osAccount.AccountManager|@ohos.account.osAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：getOsAccountTypeFromProcess<br>废弃版本：N/A|方法名 or 属性名：getOsAccountTypeFromProcess<br>废弃版本：9|@ohos.account.osAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：getDistributedVirtualDeviceId<br>废弃版本：N/A|方法名 or 属性名：getDistributedVirtualDeviceId<br>废弃版本：9<br>代替接口：osAccount.AccountManager|@ohos.account.osAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：getDistributedVirtualDeviceId<br>废弃版本：N/A|方法名 or 属性名：getDistributedVirtualDeviceId<br>废弃版本：9|@ohos.account.osAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：getOsAccountLocalIdBySerialNumber<br>废弃版本：N/A|方法名 or 属性名：getOsAccountLocalIdBySerialNumber<br>废弃版本：9<br>代替接口：osAccount.AccountManager|@ohos.account.osAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：getOsAccountLocalIdBySerialNumber<br>废弃版本：N/A|方法名 or 属性名：getOsAccountLocalIdBySerialNumber<br>废弃版本：9|@ohos.account.osAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：getSerialNumberByOsAccountLocalId<br>废弃版本：N/A|方法名 or 属性名：getSerialNumberByOsAccountLocalId<br>废弃版本：9<br>代替接口：osAccount.AccountManager|@ohos.account.osAccount.d.ts|
|废弃版本有变化|方法名 or 属性名：getSerialNumberByOsAccountLocalId<br>废弃版本：N/A|方法名 or 属性名：getSerialNumberByOsAccountLocalId<br>废弃版本：9|@ohos.account.osAccount.d.ts|
|权限有变化|方法名 or 属性名：getAuthInfo<br>权限:ohos.permission.ACCESS_USER_IDM|方法名 or 属性名：getAuthInfo<br>权限:ohos.permission.USE_USER_IDM|@ohos.account.osAccount.d.ts|
|权限有变化|方法名 or 属性名：getAuthInfo<br>权限:ohos.permission.ACCESS_USER_IDM|方法名 or 属性名：getAuthInfo<br>权限:ohos.permission.USE_USER_IDM|@ohos.account.osAccount.d.ts|
|权限有变化|方法名 or 属性名：getAuthInfo<br>权限:ohos.permission.ACCESS_USER_IDM|方法名 or 属性名：getAuthInfo<br>权限:ohos.permission.USE_USER_IDM|@ohos.account.osAccount.d.ts|
|新增(权限)|方法名 or 属性名：isOsAccountVerified<br>权限:N/A|方法名 or 属性名：isOsAccountVerified<br>权限:ohos.permission.MANAGE_LOCAL_ACCOUNTS or ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS.|@ohos.account.osAccount.d.ts|
|新增(权限)|方法名 or 属性名：isMainOsAccount<br>权限:N/A|方法名 or 属性名：isMainOsAccount<br>权限:ohos.permission.MANAGE_LOCAL_ACCOUNTS.|@ohos.account.osAccount.d.ts|
|新增(权限)|方法名 or 属性名：isMainOsAccount<br>权限:N/A|方法名 or 属性名：isMainOsAccount<br>权限:ohos.permission.MANAGE_LOCAL_ACCOUNTS.|@ohos.account.osAccount.d.ts|
