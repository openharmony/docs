| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|类名：AuthorizationExtensionAbility;<br>方法or属性：onStartAuthorization(request: AuthorizationRequest, callback: AuthorizationCallback): void;|@ohos.account.appAccount.AuthorizationExtensionAbility.d.ts|
|新增|NA|类名：AuthorizationRequest;<br>方法or属性：readonly callerUid: number;|@ohos.account.appAccount.AuthorizationExtensionAbility.d.ts|
|新增|NA|类名：AuthorizationRequest;<br>方法or属性：readonly parameters: appAccount.AccountCapabilityRequest;|@ohos.account.appAccount.AuthorizationExtensionAbility.d.ts|
|新增|NA|类名：AuthorizationCallback;<br>方法or属性：onResult: AsyncCallback\<appAccount.AccountCapabilityResponse, { [key: string]: object }>;|@ohos.account.appAccount.AuthorizationExtensionAbility.d.ts|
|新增|NA|类名：AccountCapabilityType;<br>方法or属性：AUTHORIZATION = 1|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AccountCapabilityProvider;<br>方法or属性：readonly capabilityType: AccountCapabilityType;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AccountCapabilityProvider;<br>方法or属性：constructor(capabilityType: AccountCapabilityType);|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AuthorizationProvider;<br>方法or属性：constructor(info: AuthorizationProviderInfo);|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AuthorizationProviderInfo;<br>方法or属性：readonly bundleName: string;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AuthorizationProviderInfo;<br>方法or属性：readonly abilityName: string;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AccountCapabilityRequest;<br>方法or属性：constructor(provider: AccountCapabilityProvider);|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AccountCapabilityResponse;<br>方法or属性：readonly request: AccountCapabilityRequest;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AccountCapabilityResponse;<br>方法or属性：constructor(request: AccountCapabilityRequest);|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AccountCapabilityScheduler;<br>方法or属性：executeRequest(<br>      request: AccountCapabilityRequest,<br>      callback: AsyncCallback\<AccountCapabilityResponse, { [key: string]: object }><br>    ): void;|@ohos.account.appAccount.d.ts|
|新增|NA|类名：AccountCapabilityScheduler;<br>方法or属性：executeRequest(request: AccountCapabilityRequest): Promise\<AccountCapabilityResponse>;|@ohos.account.appAccount.d.ts|
