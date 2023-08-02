# 帐号子系统changeLog

## cl.account_os_account.1 变更错误码定义及其返回方式

针对帐号子系统API存在错误码定义不统一和抛出方式不符合OpenHarmony错误码规范的问题，从API9开始作以下变更：

- 新增统一的错误码定义：
  [帐号公共错误码](../../../application-dev/reference/errorcodes/errorcode-account.md)

- 按以下方式返回错误码：
  - 异步接口：错误信息通过AsyncCallback或Promise的error对象返回。其中，参数类型和数量错误信息，通过抛出异常的方式返回。
  - 同步接口：错误信息通过抛出异常的方式返回。

**变更影响**

基于此前版本开发的应用，需适配变更后的新错误码和错误信息返回方式，否则会影响原有业务逻辑。

**关键接口/组件变更**

以下接口涉及新错误码和错误信息返回方式变更：
  - class AccountManager
    - activateOsAccount(localId: number, callback: AsyncCallback&lt;void&gt;): void;
    - removeOsAccount(localId: number, callback: AsyncCallback&lt;void&gt;): void;
    - setOsAccountConstraints(localId: number, constraints: Array&lt;string&gt;, enable: boolean, callback: AsyncCallback&lt;void&gt;): void;
    - setOsAccountName(localId: number, localName: string, callback: AsyncCallback&lt;void&gt;): void;
    - queryMaxOsAccountNumber(callback: AsyncCallback&lt;number&gt;): void;
    - queryAllCreatedOsAccounts(callback: AsyncCallback&lt;Array&lt;OsAccountInfo&gt;&gt;): void;
    - createOsAccount(localName: string, type: OsAccountType, callback: AsyncCallback&lt;OsAccountInfo&gt;): void;
    - createOsAccountForDomain(type: OsAccountType, domainInfo: DomainAccountInfo, callback: AsyncCallback&lt;OsAccountInfo&gt;): void;
    - queryOsAccountById(localId: number, callback: AsyncCallback&lt;OsAccountInfo&gt;): void;
    - getOsAccountProfilePhoto(localId: number, callback: AsyncCallback&lt;string&gt;): void;
    - setOsAccountProfilePhoto(localId: number, photo: string, callback: AsyncCallback&lt;void&gt;): void;
    - on(type: 'activate' | 'activating', name: string, callback: Callback&lt;number&gt;): void;
    - off(type: 'activate' | 'activating', name: string, callback?: Callback&lt;number&gt;): void;
    - isMainOsAccount(callback: AsyncCallback&lt;boolean&gt;): void;
    - queryOsAccountConstraintSourceTypes(localId: number, constraint: string, callback: AsyncCallback&lt;Array&lt;ConstraintSourceTypeInfo&gt;&gt;): void;
  - class UserAuth
    - constructor();
    - getVersion(): number;
    - getAvailableStatus(authType: AuthType, authTrustLevel: AuthTrustLevel): number;
    - getProperty(request: GetPropertyRequest, callback: AsyncCallback&lt;ExecutorProperty&gt;): void;
    - setProperty(request: SetPropertyRequest, callback: AsyncCallback&lt;number&gt;): void;
    - auth(challenge: Uint8Array, authType: AuthType, authTrustLevel: AuthTrustLevel, callback: IUserAuthCallback): Uint8Array;
    - authUser(userId: number, challenge: Uint8Array, authType: AuthType, authTrustLevel: AuthTrustLevel, callback: IUserAuthCallback): Uint8Array;
    - cancelAuth(contextID: Uint8Array): number;
  - class PINAuth
    - constructor();
    - registerInputer(inputer: IInputer): boolean;
    - unregisterInputer(authType: AuthType): void;
  - class UserIdentityManager
    - constructor();
    - openSession(callback: AsyncCallback&lt;Uint8Array&gt;): void;
    - addCredential(credentialInfo: CredentialInfo, callback: IIdmCallback): void;
    - updateCredential(credentialInfo: CredentialInfo, callback: IIdmCallback): void;
    - closeSession(): void;
    - cancel(challenge: Uint8Array): number;
    - delUser(token: Uint8Array, callback: IIdmCallback): void;
    - delCred(credentialId: Uint8Array, token: Uint8Array, callback: IIdmCallback): void;
    - getAuthInfo(callback: AsyncCallback&lt;Array&lt;EnrolledCredInfo&gt;&gt;): void;
  - interface IInputData
    - onSetData: (authSubType: AuthSubType, data: Uint8Array) =&gt; void;

**适配指导**

异步接口的错误信息处理逻辑以activateOsAccount为例，示例代码如下：

```ts
import account_osAccount from "@ohos.account.osAccount"
let accountMgr = account_osAccount.getAccountManager()
let callbackFunc = (err) => {
  if (err != null) {  // handle the bussiness error
    console.log("account_osAccount failed, error: " + JSON.stringify(err));
  } else {
    console.log("account_osAccount successfully");
  }
}
try {
  accountMgr.activateOsAccount("100", callbackFunc);
} catch (err) {  // handle the parameter type error
  console.log("account_osAccount failed for incorrect parameter type, error: " + JSON.stringify(err));
}
try {
  accountMgr.activateOsAccount();
} catch (err) {  // handle the parameter number error
  console.log("account_osAccount failed for incorrect parameter number, error: " + JSON.stringify(err));
}
```

同步接口的错误信息处理以registerInputer为例，示例代码如下：

```ts
import account_osAccount from "@ohos.account.osAccount"
let pinAuth = new account_osAccount.PINAuth()
try {
    pinAuth.registerInputer({})
} catch (err) {  // handle the parameter type error
  console.log("account_osAccount failed for incorrect parameter type, error: " + JSON.stringify(err));
}
try {
    pinAuth.registerInputer()
} catch (err) {  // handle the parameter number error
  console.log("account_osAccount failed for incorrect parameter number, error: " + JSON.stringify(err));
}
```

# 帐号子系统ChangeLog

## cl.account_os_account.2 帐号SystemAPI错误信息返回方式变更

已发布的部分帐号SystemAPI使用业务逻辑返回值表示错误信息，不符合OpenHarmony接口错误码规范。从API9开始作以下变更：

异步接口：通过AsyncCallback或Promise的error对象返回错误信息。

同步接口：通过抛出异常的方式返回错误信息。

**变更影响**

基于此前版本开发的应用，需适配变更接口的错误信息返回方式，否则会影响原有业务逻辑。

**关键接口/组件变更**

变更前：

  - class UserAuth
    - setProperty(request: SetPropertyRequest, callback: AsyncCallback&lt;number&gt;): void;
    - setProperty(request: SetPropertyRequest): Promise&lt;number&gt;;
    - cancelAuth(contextID: Uint8Array): number;
  - class PINAuth
    - registerInputer(inputer: Inputer): boolean;
  - UserIdentityManager
    - cancel(challenge: Uint8Array): number;

变更后：

  - class UserAuth
    - setProperty(request: SetPropertyRequest, callback: AsyncCallback&lt;void&gt;): void;
    - setProperty(request: SetPropertyRequest): Promise&lt;void&gt;;
    - cancelAuth(contextID: Uint8Array): void;
  - class PINAuth
    - registerInputer(inputer: Inputer): void;
  - UserIdentityManager
    - cancel(challenge: Uint8Array): void;

**适配指导**

异步接口以setProperty为例，示例代码如下：

```
import account_osAccount from "@ohos.account.osAccount"
userAuth.setProperty({
    authType: account_osAccount.AuthType.PIN,
    key: account_osAccount.SetPropertyType.INIT_ALGORITHM,
    setInfo: new Uint8Array([0])
}, (err) => {
    if (err) {
        console.log("setProperty failed, error: " + JSON.stringify(err));
    } else {
        console.log("setProperty successfully");
    }
});

userAuth.setProperty({
    authType: account_osAccount.AuthType.PIN,
    key: account_osAccount.SetPropertyType.INIT_ALGORITHM,
    setInfo: new Uint8Array([0])
}).catch((err) => {
    if (err) {
        console.log("setProperty failed, error: " + JSON.stringify(err));
    } else {
        console.log("setProperty successfully");
    }
});
```

同步接口以registerInputer为例，示例代码如下：

```
import account_osAccount from "@ohos.account.osAccount"
let pinAuth = new account_osAccount.PINAuth()
let inputer = {
    onGetData: (authType, passwordRecipient) => {
        let password = new Uint8Array([0]);
        passwordRecipient.onSetData(authType, password);
    }
}
try {
    pinAuth.registerInputer(inputer);
} catch (err) {
    console.log("registerInputer failed, error: " + JSON.stringify(err));
}
```

## cl.account_os_account.3 应用帐号鉴权服务ACTION定义变更

**变更影响**

基于此前版本开发的应用，需适配修改应用配置文件（FA模型为config.json或Stage模型为module.json5）中的ACTION才能正常对外提供应用鉴权服务。

**关键接口/组件变更**

涉及的常量：

@ohos.ability.wantConstant.ACTION_APP_ACCOUNT_AUTH

变更前：

ACTION_APP_ACCOUNT_AUTH = "account.appAccount.action.auth"

变更后：

ACTION_APP_ACCOUNT_AUTH = "ohos.appAccount.action.auth"

**适配指导**

提供应用帐号鉴权服务的三方应用，需要在相关ServiceAbility的配置文件（FA模型为config.json或Stage模型为module.json5）中适配变更后的应用帐号认证ACTION，示例如下：

```
"abilities": [
    {
        "name": "ServiceAbility",
        "srcEnty": "./ets/ServiceAbility/ServiceAbility.ts",
        ...
        "visible": true,
        "skills": {
            {
                "actions": [
                    "ohos.appAccount.action.auth"
                ]
            }
        }
    }]
}

```
