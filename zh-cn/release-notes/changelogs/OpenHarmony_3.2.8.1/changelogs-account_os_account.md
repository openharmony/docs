# 帐号子系统changeLog

## cl.account_os_account.1 变更错误码定义及其返回方式

针对帐号子系统API存在错误码定义不统一和抛出方式不符合OpenHarmony错误码规范的问题，从API9开始作以下变更：

- 新增统一的错误码定义：
  - [帐号公共错误码](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/errorcodes/errorcode-account.md)
  - [应用帐号错误码](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/errorcodes/errorcode-account.md)

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
