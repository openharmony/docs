# 帐号子系统ChangeLog

## cl.account_os_account.1 帐号SystemAPI错误信息返回方式变更

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

## cl.account_os_account.2 应用帐号鉴权服务ACTION定义变更

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
        "srcEntrance": "./ets/ServiceAbility/ServiceAbility.ts",
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
