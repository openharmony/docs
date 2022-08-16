# JS API Changes of the Account Subsystem

The table below lists the APIs changes of the account subsystem in OpenHarmony 3.2 Beta2 over OpenHarmony 3.2 Beta1.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| ohos.account.appAccount | Authenticator | getRemoteObject(): rpc.RemoteObject; | Added|
| ohos.account.appAccount | Authenticator | isAccountRemovable(name: string, callback: AuthenticatorCallback): void; | Added|
| ohos.account.appAccount | Authenticator | checkAccountLabels(name: string, labels: Array\<string>, callback: AuthenticatorCallback): void; | Added|
| ohos.account.appAccount | Authenticator | setProperties(options: SetPropertiesOptions, callback: AuthenticatorCallback): void; | Added|
| ohos.account.appAccount | Authenticator | verifyCredential(name: string, options: VerifyCredentialOptions, callback: AuthenticatorCallback): void; | Added|
| ohos.account.appAccount | AuthenticatorCallback | onRequestContinued?: () => void; | Added|
| ohos.account.appAccount | Constants | KEY_BOOLEAN_RESULT = "booleanResult" | Added|
| ohos.account.appAccount | Constants | KEY_REQUIRED_LABELS = "requiredLabels" | Added|
| ohos.account.appAccount | SetPropertiesOptions | parameters?: {[key: string]: Object} | Added|
| ohos.account.appAccount | SetPropertiesOptions | properties?: {[key: string]: Object}, | Added|
| ohos.account.appAccount | VerifyCredentialOptions | parameters?: {[key:string]: Object} | Added|
| ohos.account.appAccount | VerifyCredentialOptions | credential?: string, | Added|
| ohos.account.appAccount | VerifyCredentialOptions | credentialType?: string, | Added|
| ohos.account.appAccount | SelectAccountsOptions | requiredLabels?: Array\<string> | Added|
| ohos.account.appAccount | SelectAccountsOptions | allowedOwners?: Array\<string>, | Added|
| ohos.account.appAccount | SelectAccountsOptions | allowedAccounts?: Array\<AppAccountInfo>, | Added|
| ohos.account.appAccount | OAuthTokenInfo | account?: AppAccountInfo; | Added|
| ohos.account.appAccount | AppAccountManager | setAuthenticatorProperties(owner: string, callback: AuthenticatorCallback): void;<br>setAuthenticatorProperties(owner: string, options: SetPropertiesOptions, callback: AuthenticatorCallback): void; | Added|
| ohos.account.appAccount | AppAccountManager | verifyCredential(name: string, owner: string, callback: AuthenticatorCallback): void;<br>verifyCredential(name: string, owner: string, options: VerifyCredentialOptions, callback: AuthenticatorCallback): void; | Added|
| ohos.account.appAccount | AppAccountManager | selectAccountsByOptions(options: SelectAccountsOptions, callback: AsyncCallback\<Array\<AppAccountInfo>>);<br>selectAccountsByOptions(options: SelectAccountsOptions): Promise\<Array\<AppAccountInfo>>; | Added|
| ohos.account.appAccount | AppAccountManager | deleteAccountCredential(name: string, credentialType: string, callback: AsyncCallback\<void>): void;<br>deleteAccountCredential(name: string, credentialType: string): Promise\<void>; | Added|
| ohos.account.appAccount | AppAccountManager | checkAccountLabels(name: string, owner: string, labels: Array\<string>, callback: AsyncCallback\<boolean>): void;<br>checkAccountLabels(name: string, owner: string, labels: Array\<string>): Promise\<boolean>; | Added|
| ohos.account.appAccount | AppAccountManager | checkAppAccess(name: string, bundleName: string, callback: AsyncCallback\<boolean>): void;<br>checkAppAccess(name: string, bundleName: string): Promise\<boolean>; | Added|
| ohos.account.osAccount | ConstraintSourceTypeInfo | type: ConstraintSourceType; | Added|
| ohos.account.osAccount | ConstraintSourceTypeInfo | localId: number; | Added|
| ohos.account.osAccount | ConstraintSourceType | CONSTRAINT_TYPE_PROFILE_OWNER = 3 | Added|
| ohos.account.osAccount | ConstraintSourceType | CONSTRAINT_TYPE_DEVICE_OWNER = 2 | Added|
| ohos.account.osAccount | ConstraintSourceType | CONSTRAINT_TYPE_BASE = 1 | Added|
| ohos.account.osAccount | ConstraintSourceType | CONSTRAINT_NOT_EXIST = 0 | Added|
| ohos.account.osAccount | AccountManager | queryOsAccountConstraintSourceTypes(localId: number, constraint: string, callback: AsyncCallback\<Array\<ConstraintSourceTypeInfo>>): void;<br>queryOsAccountConstraintSourceTypes(localId: number, constraint: string): Promise\<Array\<ConstraintSourceTypeInfo>>; | Added|
| ohos.account.osAccount | AccountManager | isMainOsAccount(callback: AsyncCallback\<boolean>): void;<br>isMainOsAccount(): Promise\<boolean>; | Added|
| ohos.account.osAccount | AccountManager | getBundleIdFromUid(uid: number, callback: AsyncCallback\<number>): void;<br>getBundleIdFromUid(uid: number): Promise\<number>; | Added|
