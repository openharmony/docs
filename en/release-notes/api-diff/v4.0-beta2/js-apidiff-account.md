| Change Type | Old Version | New Version | d.ts File |
| ---- | ------ | ------ | -------- |
|Added|NA|Class name: AuthorizationExtensionAbility;<br>Method or attribute name: onStartAuthorization(request: AuthorizationRequest, callback: AuthorizationCallback): void;|@ohos.account.appAccount.AuthorizationExtensionAbility.d.ts|
|Added|NA|Class name: AuthorizationRequest;<br>Method or attribute name: readonly callerUid: number;|@ohos.account.appAccount.AuthorizationExtensionAbility.d.ts|
|Added|NA|Class name: AuthorizationRequest;<br>Method or attribute name: readonly parameters: appAccount.AccountCapabilityRequest;|@ohos.account.appAccount.AuthorizationExtensionAbility.d.ts|
|Added|NA|Class name: AuthorizationCallback;<br>Method or attribute name: onResult: AsyncCallback\<appAccount.AccountCapabilityResponse, { [key: string]: object }>;|@ohos.account.appAccount.AuthorizationExtensionAbility.d.ts|
|Added|NA|Class name: AccountCapabilityType;<br>Method or attribute name: AUTHORIZATION = 1|@ohos.account.appAccount.d.ts|
|Added|NA|Class name: AccountCapabilityProvider;<br>Method or attribute name: readonly capabilityType: AccountCapabilityType;|@ohos.account.appAccount.d.ts|
|Added|NA|Class name: AccountCapabilityProvider;<br>Method or attribute name: constructor(capabilityType: AccountCapabilityType);|@ohos.account.appAccount.d.ts|
|Added|NA|Class name: AuthorizationProvider;<br>Method or attribute name: constructor(info: AuthorizationProviderInfo);|@ohos.account.appAccount.d.ts|
|Added|NA|Class name: AuthorizationProviderInfo;<br>Method or attribute name: readonly bundleName: string;|@ohos.account.appAccount.d.ts|
|Added|NA|Class name: AuthorizationProviderInfo;<br>Method or attribute name: readonly abilityName: string;|@ohos.account.appAccount.d.ts|
|Added|NA|Class name: AccountCapabilityRequest;<br>Method or attribute name: constructor(provider: AccountCapabilityProvider);|@ohos.account.appAccount.d.ts|
|Added|NA|Class name: AccountCapabilityResponse;<br>Method or attribute name: readonly request: AccountCapabilityRequest;|@ohos.account.appAccount.d.ts|
|Added|NA|Class name: AccountCapabilityResponse;<br>Method or attribute name: constructor(request: AccountCapabilityRequest);|@ohos.account.appAccount.d.ts|
|Added|NA|Class name: AccountCapabilityScheduler;<br>Method or attribute name: executeRequest(<br>      request: AccountCapabilityRequest,<br>      callback: AsyncCallback\<AccountCapabilityResponse, { [key: string]: object }><br>    ): void;|@ohos.account.appAccount.d.ts|
|Added|NA|Class name: AccountCapabilityScheduler;<br>Method or attribute name: executeRequest(request: AccountCapabilityRequest): Promise\<AccountCapabilityResponse>;|@ohos.account.appAccount.d.ts|
