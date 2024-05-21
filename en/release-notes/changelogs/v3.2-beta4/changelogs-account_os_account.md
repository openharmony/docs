# Account Subsystem ChangeLog

## cl.account_os_account.1 Change of Definition and Return Mode of Error Codes

To solve the issues that error code definitions of the account subsystem APIs were inconsistent and that the return mode of the error codes did not comply with relevant specifications of OpenHarmony, the following changes are made and take effect in API version 9 and later:

- Added the following unified error code definitions:
  - [Account Error Codes](https://gitee.com/openharmony/docs/tree/OpenHarmony-3.2-Beta4/en/application-dev/reference/errorcodes/errorcode-account.md)

- Returned an error code in either of the following ways, according to the API type:
  - Asynchronous API: An error message is returned via **AsyncCallback** or the **error** object of **Promise**. An error message related to the parameter type or quantity is returned via an exception.
  - Synchronous API: An error message is returned via an exception.

**Change Impacts**

The application developed based on earlier versions needs to adapt the method for returning API error information. Otherwise, the original service logic will be affected.

**Key API/Component Changes**

The mentioned changes involve the following APIs:
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

**Adaptation Guide**

The following uses **activateOsAccount** as an example to illustrate the error information processing logic of an asynchronous API:

```ts
import account_osAccount from "@ohos.account.osAccount"
let accountMgr = account_osAccount.getAccountManager()
let callbackFunc = (err) => {
  if (err != null) {  // Handle the business error.
    console.log("account_osAccount failed, error: " + JSON.stringify(err));
  } else {
    console.log("account_osAccount successfully");
  }
}
try {
  accountMgr.activateOsAccount("100", callbackFunc);
} catch (err) {  // Process the error that is related to the parameter type.
  console.log("account_osAccount failed for incorrect parameter type, error: " + JSON.stringify(err));
}
try {
  accountMgr.activateOsAccount();
} catch (err) {  // Process the error that is related to the parameter quantity.
  console.log("account_osAccount failed for incorrect parameter number, error: " + JSON.stringify(err));
}
```

The following uses **registerInputer** as an example to illustrate the error information processing logic of a synchronous API:

```ts
import account_osAccount from "@ohos.account.osAccount"
let pinAuth = new account_osAccount.PINAuth()
try {
    pinAuth.registerInputer({})
} catch (err) {  // Process the error that is related to the parameter type.
  console.log("account_osAccount failed for incorrect parameter type, error: " + JSON.stringify(err));
}
try {
    pinAuth.registerInputer()
} catch (err) {  // Process the error that is related to the parameter quantity.
  console.log("account_osAccount failed for incorrect parameter number, error: " + JSON.stringify(err));
}
```


## cl.account_os_account.2 Change in Error Information Return Method of Account System APIs

Certain system APIs of the account subsystem use service logic return values to indicate error information, which does not comply with the API error code specifications of OpenHarmony. The following changes are made in API version 9 and later:

Asynchronous API: An error message is returned via **AsyncCallback** or the **error** object of **Promise**.

Synchronous API: An error message is returned via an exception.

**Change Impacts**

The application developed based on earlier versions needs to adapt the new APIs and their method for returning API error information. Otherwise, the original service logic will be affected.

**Key API/Component Changes**

Before change:
  - class UserAuth
    - setProperty(request: SetPropertyRequest, callback: AsyncCallback&lt;number&gt;): void;
    - setProperty(request: SetPropertyRequest): Promise&lt;number&gt;;
    - cancelAuth(contextID: Uint8Array): number;
  - class PINAuth
    - registerInputer(inputer: Inputer): boolean;
  - UserIdentityManager
    - cancel(challenge: Uint8Array): number;

After change:
  - class UserAuth
    - setProperty(request: SetPropertyRequest, callback: AsyncCallback&lt;void&gt;): void;
    - setProperty(request: SetPropertyRequest): Promise&lt;void&gt;;
    - cancelAuth(contextID: Uint8Array): void;
  - class PINAuth
    - registerInputer(inputer: Inputer): void;
  - UserIdentityManager
    - cancel(challenge: Uint8Array): void;

**Adaptation Guide**

The following uses **setProperty** as an example for asynchronous APIs:

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

The following uses **registerInputer** as an example for synchronous APIs:

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

## cl.account_os_account.3 ACTION Definition Change for the Application Account Authentication Service

**Change Impacts**

For the application developed based on an earlier version, you need to modify **ACTION** in the application configuration file (**config.json** for the FA model and **module.json5** for the Stage model) to normally provide the application authentication service.

**Key API/Component Changes**

Involved constant:

@ohos.ability.wantConstant.ACTION_APP_ACCOUNT_AUTH

Before change:

ACTION_APP_ACCOUNT_AUTH = "account.appAccount.action.auth"

After change:

ACTION_APP_ACCOUNT_AUTH = "ohos.appAccount.action.auth"

**Adaptation Guide**

For a third-party application providing the account authentication service, adapt the changed application account authentication **ACTION** in the **ServiceAbility** configuration file (**config.json** for the FA module or **module.json5** for the Stage module). 
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
