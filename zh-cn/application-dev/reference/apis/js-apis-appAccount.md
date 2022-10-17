# 应用帐号管理

本模块不仅用于对应用帐号的添加、删除、查询、修改和授权，且提供帐号将数据写入磁盘和数据同步的能力。

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```js
import account_appAccount from '@ohos.account.appAccount';
```


## account_appAccount.createAppAccountManager

createAppAccountManager(): AppAccountManager

获取应用帐号模块的对象。

**系统能力：** SystemCapability.Account.AppAccount

**返回值：**

| 类型                | 说明           |
| ----------------- | ------------ |
| AppAccountManager | 获取应用帐号模块的实例。 |

**示例：**
  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  ```

## AppAccountManager

管理应用帐号模块的实例。

### createAccount<sup>9+</sup>

createAccount(name: string, callback: AsyncCallback&lt;void&gt;): void;

将此应用的帐号名添加到帐号管理服务中，使用callback回调异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名      | 类型                        | 必填   | 说明                   |
| -------- | ------------------------- | ---- | -------------------- |
| name     | string                    | 是    | 要添加的应用帐号名称。          |
| callback | AsyncCallback&lt;void&gt; | 是    | 将此应用的帐号名添加到帐号管理服务回调。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  try {
      appAccountManager.createAccount("WangWu", (err) => { 
          console.log("createAccount err: " + JSON.stringify(err));
  });
  } catch (err) {
      console.log("createAccount err: " + JSON.stringify(err));
  }
  ```

### createAccount<sup>9+</sup>

createAccount(name: string, extraInfo: string, callback: AsyncCallback&lt;void&gt;): void

将此应用程序的帐号名和额外信息（能转换string类型的其它信息，如token）添加到帐号管理服务中，使用callback回调异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名       | 类型                        | 必填   | 说明                                       |
| --------- | ------------------------- | ---- | ---------------------------------------- |
| name      | string                    | 是    | 要添加的应用帐号名称。                              |
| extraInfo | string                    | 是    | 要添加的应用帐号的额外信息(能转换string类型的其它信息，如token等)，额外信息不能是应用帐号的敏感信息（如应用账号密码）。 |
| callback  | AsyncCallback&lt;void&gt; | 是    | 将此应用程序的帐号名和额外信息添加到帐号管理服务中回调。             |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  try {
      appAccountManager.createAccount("LiSi", "token101", (err) => { 
          console.log("createAccount err: " + JSON.stringify(err));
  });
  } catch (err) {
      console.log("createAccount err: " + JSON.stringify(err));
  }
  ```

### createAccount<sup>9+</sup>

createAccount(name: string, extraInfo?: string): Promise&lt;void&gt;

将此应用的帐号名或额外信息（能转换成string类型的其它信息）添加到帐号管理服务中，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名       | 类型     | 必填   | 说明                                       |
| --------- | ------ | ---- | ---------------------------------------- |
| name      | string | 是    | 要添加的应用帐号名称。                              |
| extraInfo | string | 否    | 要添加的应用帐号的额外信息（能转换成string类型的其它信息），额外信息不能是应用帐号的敏感信息（如应用账号密码）。 |

**返回值：**

| 类型                  | 说明                    |
| ------------------- | --------------------- |
| Promise&lt;void&gt; | Promise实例，用于获取异步返回结果。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  try {
      appAccountManager.createAccount("LiSi", "token101").then(()=> { 
          console.log('createAccount Success');
  }).catch((err) => {
          console.log("createAccount err: "  + JSON.stringify(err));
  });
  } catch (err) {
      console.log("createAccount err: "  + JSON.stringify(err));
  }
  ```

### addAccount<sup>(deprecated)</sup>

addAccount(name: string, callback: AsyncCallback&lt;void&gt;): void

将此应用的帐号名添加到帐号管理服务中，使用callback回调异步返回结果。

> **说明：** 
> 从API version 9开始废弃, 建议使用[createAccount](#createaccount9)替代
>
> 从 API version 7开始支持。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名      | 类型                        | 必填   | 说明                   |
| -------- | ------------------------- | ---- | -------------------- |
| name     | string                    | 是    | 要添加的应用帐号名称。          |
| callback | AsyncCallback&lt;void&gt; | 是    | 将此应用的帐号名添加到帐号管理服务回调。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.addAccount("WangWu", (err) => { 
      console.log("addAccount err: " + JSON.stringify(err));
  });
  ```

### addAccount<sup>(deprecated)</sup>

addAccount(name: string, extraInfo: string, callback: AsyncCallback&lt;void&gt;): void

将此应用程序的帐号名和额外信息（能转换string类型的其它信息，如token）添加到帐号管理服务中，使用callback回调异步返回结果。

> **说明：** > 从API version 9开始废弃, 建议使用[createAccount](#createaccount9-1)替代
> 从 API version 7开始支持。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名       | 类型                        | 必填   | 说明                                       |
| --------- | ------------------------- | ---- | ---------------------------------------- |
| name      | string                    | 是    | 要添加的应用帐号名称。                              |
| extraInfo | string                    | 是    | 要添加的应用帐号的额外信息(能转换string类型的其它信息，如token等)，额外信息不能是应用帐号的敏感信息（如应用账号密码）。 |
| callback  | AsyncCallback&lt;void&gt; | 是    | 将此应用程序的帐号名和额外信息添加到帐号管理服务中回调。             |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.addAccount("LiSi", "token101", (err) => { 
      console.log("addAccount err: " + JSON.stringify(err));
  });
  ```

### addAccount<sup>(deprecated)</sup>

addAccount(name: string, extraInfo?: string): Promise&lt;void&gt;

将此应用的帐号名或额外信息（能转换成string类型的其它信息）添加到帐号管理服务中，使用Promise方式异步返回结果。

> **说明：** > 从API version 9开始废弃, 建议使用[createAccount](#createaccount9-2)替代
> 从 API version 7开始支持。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名       | 类型     | 必填   | 说明                                       |
| --------- | ------ | ---- | ---------------------------------------- |
| name      | string | 是    | 要添加的应用帐号名称。                              |
| extraInfo | string | 否    | 要添加的应用帐号的额外信息（能转换成string类型的其它信息），额外信息不能是应用帐号的敏感信息（如应用账号密码）。 |

**返回值：**

| 类型                  | 说明                    |
| ------------------- | --------------------- |
| Promise&lt;void&gt; | Promise实例，用于获取异步返回结果。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.addAccount("LiSi", "token101").then(()=> { 
      console.log('addAccount Success');
  }).catch((err) => {
      console.log("addAccount err: "  + JSON.stringify(err));
  });
  ```

### createAccountImplicitly<sup>9+</sup>

createAccountImplicitly(owner: string, callback: AuthCallback): void

根据指定的帐号所有者隐式地添加应用帐号，并使用callback回调异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名      | 类型                    | 必填   | 说明                      |
| -------- | --------------------- | ---- | ----------------------- |
| owner    | string                | 是    | 要添加的应用帐号所有者包名。          |
| callback | [AuthCallback](#authcallback9) | 是    | 认证回调，用于返回鉴权结果。         |

**示例：**

  ```js
  import featureAbility from '@ohos.ability.featureAbility';

  function onResultCallback(code, result) {
      console.log("resultCode: "  + code);
      console.log("result: "  + JSON.stringify(result));
  }

  function onRequestRedirectedCallback(request) {
      let abilityStartSetting = {want: request};
      featureAbility.startAbility(abilityStartSetting, (err)=>{
          console.log("startAbility err: " + JSON.stringify(err));
      });
  }

  const appAccountManager = account_appAccount.createAppAccountManager();
  try {  
      appAccountManager.createAccountImplicitly("com.example.ohos.accountjsdemo", {
          onResult: onResultCallback,
          onRequestRedirected: onRequestRedirectedCallback
  });
  } catch (err) {
      console.log("createAccountImplicitly err: " + JSON.stringify(err));
  }
  ```

### createAccountImplicitly<sup>9+</sup>

createAccountImplicitly(owner: string, options: CreateAccountImplicitlyOptions, callback: AuthCallback): void

根据指定的帐号所有者和可选项隐式地添加应用帐号，并使用callback回调异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名      | 类型                    | 必填   | 说明                      |
| -------- | --------------------- | ---- | ----------------------- |
| owner    | string                | 是    | 要添加的应用帐号所有者包名。          |
| options    | [CreateAccountImplicitlyOptions](#createaccountimplicitlyoptions9)                | 是    | 隐式创建账号的选项。          |
| callback | [AuthCallback](#authcallback9) | 是    | 认证回调，用于返回鉴权结果。         |

**示例：**

  ```js
  import featureAbility from '@ohos.ability.featureAbility';

  function onResultCallback(code, result) {
      console.log("resultCode: "  + code);
      console.log("result: "  + JSON.stringify(result));
  }

  function onRequestRedirectedCallback(request) {
      let abilityStartSetting = {want: request};
      featureAbility.startAbility(abilityStartSetting, (err)=>{
          console.log("startAbility err: " + JSON.stringify(err));
      });
  }

  const appAccountManager = account_appAccount.createAppAccountManager();
  try {
      appAccountManager.createAccountImplicitly("com.example.ohos.accountjsdemo", {
          requiredLabels: ["student"], authType: "getSocialData"}, {
          onResult: onResultCallback,
          onRequestRedirected: onRequestRedirectedCallback
    });
  } catch (err) {
      console.log("createAccountImplicitly err: " + JSON.stringify(err));
  }

  ```

### addAccountImplicitly<sup>(deprecated)</sup>

addAccountImplicitly(owner: string, authType: string, options: {[key: string]: any}, callback: AuthenticatorCallback): void

根据指定的帐号所有者、鉴权类型和可选项隐式地添加应用帐号，并使用callback回调异步返回结果。

> **说明：**  从API version 9开始废弃, 建议使用[createAccountImplicitly](#createaccountimplicitly9)替代。
>
> 从 API version 8开始支持。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名      | 类型                    | 必填   | 说明                      |
| -------- | --------------------- | ---- | ----------------------- |
| owner    | string                | 是    | 要添加的应用帐号所有者包名。          |
| authType | string                | 是    | 要添加的应用帐号鉴权类型。鉴权类型为自定义。  |
| options  | {[key: string]: any}  | 是    | 鉴权所需要的可选项。可选项可根据自己需要设置。 |
| callback | [AuthenticatorCallback](#authenticatorcallbackdeprecated) | 是    | 认证器回调，用于返回鉴权结果。         |

**示例：**

  ```js
  import featureAbility from '@ohos.ability.featureAbility';

  function onResultCallback(code, result) {
      console.log("resultCode: "  + code);
      console.log("result: "  + JSON.stringify(result));
  }

  function onRequestRedirectedCallback(request) {
      let abilityStartSetting = {want: request};
      featureAbility.startAbility(abilityStartSetting, (err)=>{
          console.log("startAbility err: " + JSON.stringify(err));
      });
  }

  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.addAccountImplicitly("com.example.ohos.accountjsdemo", "getSocialData", {}, {
      onResult: onResultCallback,
      onRequestRedirected: onRequestRedirectedCallback
  });
  ```

### removeAccount<sup>9+</sup>

removeAccount(name: string, callback: AsyncCallback&lt;void&gt;): void

从帐号管理服务中移除应用帐号，使用callback回调异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名      | 类型                        | 必填   | 说明               |
| -------- | ------------------------- | ---- | ---------------- |
| name     | string                    | 是    | 要删除的应用帐号名称。      |
| callback | AsyncCallback&lt;void&gt; | 是    | 帐号管理服务中移除应用帐号的回调。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  try {
      appAccountManager.removeAccount("ZhaoLiu", (err) => { 
          console.log("removeAccount err: " + JSON.stringify(err));
   });
  } catch (err) {
      console.log("removeAccount err: " + JSON.stringify(err));
  }

  ```

### removeAccount<sup>9+</sup>

deleteAccount(name: string): Promise&lt;void&gt;

从帐号管理服务中移除应用帐号，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名  | 类型     | 必填   | 说明          |
| ---- | ------ | ---- | ----------- |
| name | string | 是    | 要移除的应用帐号名称。 |

**返回值：**

| 类型                  | 说明                    |
| :------------------ | :-------------------- |
| Promise&lt;void&gt; | Promise实例，用于获取异步返回结果。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  try {
      appAccountManager.deleteAccount("ZhaoLiu").then(() => { 
          console.log('removeAccount Success');
      }).catch((err) => {
          console.log("removeAccount err: "  + JSON.stringify(err));
      });
  } catch (err) {
      console.log("removeAccount err: "  + JSON.stringify(err));
  }

  ```

### deleteAccount<sup>(deprecated)</sup>

deleteAccount(name: string, callback: AsyncCallback&lt;void&gt;): void

从帐号管理服务中删除应用帐号，使用callback回调异步返回结果。

> **说明：** 从API version 9开始废弃, 建议使用[removeAccount](#removeaccount9)替代。
>
> 从 API version 7开始支持。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名      | 类型                        | 必填   | 说明               |
| -------- | ------------------------- | ---- | ---------------- |
| name     | string                    | 是    | 要删除的应用帐号名称。      |
| callback | AsyncCallback&lt;void&gt; | 是    | 帐号管理服务中删除应用帐号回调。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.deleteAccount("ZhaoLiu", (err) => { 
      console.log("deleteAccount err: " + JSON.stringify(err));
   });
  ```

### deleteAccount<sup>(deprecated)</sup>

deleteAccount(name: string): Promise&lt;void&gt;

从帐号管理服务中删除应用帐号，使用Promise方式异步返回结果。

> **说明：** 从API version 9开始废弃, 建议使用[removeAccount](#removeaccount9)替代。
>
> 从 API version 7开始支持。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名  | 类型     | 必填   | 说明          |
| ---- | ------ | ---- | ----------- |
| name | string | 是    | 要删除的应用帐号名称。 |

**返回值：**

| 类型                  | 说明                    |
| :------------------ | :-------------------- |
| Promise&lt;void&gt; | Promise实例，用于获取异步返回结果。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.deleteAccount("ZhaoLiu").then(() => { 
        console.log('deleteAccount Success');
   }).catch((err) => {
      console.log("deleteAccount err: "  + JSON.stringify(err));
  });
  ```

### setAppAccess<sup>9+</sup>

setAppAccess(name: string, bundleName: string, isAccessible: boolean, callback: AsyncCallback&lt;void&gt;): void

设置指定第三方应用帐号名称对指定包名称的第三方应用的访问权限，由isAccessible指明是允许访问还是禁止访问，callback回调异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名        | 类型                        | 必填   | 说明                                |
| ---------- | ------------------------- | ---- | --------------------------------- |
| name       | string                    | 是    | 应用帐号名称。                           |
| bundleName | string                    | 是    | 第三方应用的包名。                         |
| isAccessible | boolean                    | 是    | 访问控制，允许访问或禁止访问。                         |
| callback   | AsyncCallback&lt;void&gt; | 是    | 访问权限设置的回调。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  try {
      appAccountManager.setAppAccess("ZhangSan", "com.example.ohos.accountjsdemo", true, (err) => { 
          console.log("enableAppAccess: " + JSON.stringify(err));
      });
  } catch (err) {
      console.log("enableAppAccess: " + JSON.stringify(err));
  }

  ```

### setAppAccess<sup>9+</sup>

setAppAccess(name: string, bundleName: string, isAccessible: boolean): Promise&lt;void&gt;

设置指定第三方应用帐号名称对指定包名称的第三方应用的访问权限，由isAccessible指明是允许访问还是禁止访问，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名        | 类型     | 必填   | 说明        |
| ---------- | ------ | ---- | --------- |
| name       | string | 是    | 应用帐号名称。   |
| bundleName | string | 是    | 第三方应用的包名。 |
| isAccessible | boolean                    | 是    | 访问控制，允许访问或禁止访问。                         |

**返回值：**

| 类型                  | 说明                    |
| :------------------ | :-------------------- |
| Promise&lt;void&gt; | Promise实例，用于获取异步返回结果。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  try {
      appAccountManager.setAppAccess("ZhangSan", "com.example.ohos.accountjsdemo", true).then(() => { 
          console.log('setAppAccess Success');
      }).catch((err) => {
          console.log("setAppAccess err: "  + JSON.stringify(err));
      });    
  } catch (err) {
      console.log("setAppAccess err: "  + JSON.stringify(err));    
  }
  ```

### disableAppAccess<sup>(deprecated)</sup>

disableAppAccess(name: string, bundleName: string, callback: AsyncCallback&lt;void&gt;): void

禁止指定第三方应用帐号名称对指定的第三方应用进行访问，使用callback回调异步返回结果。

> **说明：** 从API version 9开始废弃。建议使用[setAppAccess](#setappaccess9)替代。
>
> 从 API version 7开始支持。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名        | 类型                        | 必填   | 说明                                |
| ---------- | ------------------------- | ---- | --------------------------------- |
| name       | string                    | 是    | 要禁用访问的第三方应用帐号名称。                  |
| bundleName | string                    | 是    | 第三方应用的包名。                         |
| callback   | AsyncCallback&lt;void&gt; | 是    | 禁止指定第三方应用帐号名称对指定包名称的第三方应用进行访问的回调。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.disableAppAccess("ZhangSan", "com.example.ohos.accountjsdemo", (err) => { 
      console.log("disableAppAccess err: " + JSON.stringify(err));
  });
  ```

### disableAppAccess<sup>(deprecated)</sup>

disableAppAccess(name: string, bundleName: string): Promise&lt;void&gt;

禁止指定第三方应用帐号名称对指定包名称的第三方应用进行访问，使用Promise方式异步返回结果。

> **说明：** 从API version 9开始废弃。建议使用[setAppAccess](#setappaccess9-1)替代。
>
> 从 API version 7开始支持。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名        | 类型     | 必填   | 说明               |
| ---------- | ------ | ---- | ---------------- |
| name       | string | 是    | 要禁用访问的第三方应用帐号名称。 |
| bundleName | string | 是    | 第三方应用的包名。        |

**返回值：**

| 类型                  | 说明                    |
| :------------------ | :-------------------- |
| Promise&lt;void&gt; | Promise实例，用于获取异步返回结果。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.disableAppAccess("ZhangSan", "com.example.ohos.accountjsdemo").then(() => { 
      console.log('disableAppAccess Success');
  }).catch((err) => {
      console.log("disableAppAccess err: "  + JSON.stringify(err));
  });
  ```

### enableAppAccess<sup>(deprecated)</sup>

enableAppAccess(name: string, bundleName: string, callback: AsyncCallback&lt;void&gt;): void

允许指定第三方应用帐号名称对指定包名称的第三方应用进行访问，使用callback回调异步返回结果。

> **说明：** 从API version 9开始废弃。建议使用[setAppAccess](#setappaccess9)替代。
>
> 从 API version 7开始支持。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名        | 类型                        | 必填   | 说明                                |
| ---------- | ------------------------- | ---- | --------------------------------- |
| name       | string                    | 是    | 应用帐号名称。                           |
| bundleName | string                    | 是    | 第三方应用的包名。                         |
| callback   | AsyncCallback&lt;void&gt; | 是    | 允许指定第三方应用帐号名称对指定包名称的第三方应用进行访问的回调。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.enableAppAccess("ZhangSan", "com.example.ohos.accountjsdemo", (err) => { 
      console.log("enableAppAccess: " + JSON.stringify(err));
   });
  ```

### enableAppAccess<sup>(deprecated)</sup>

enableAppAccess(name: string, bundleName: string): Promise&lt;void&gt;

允许指定第三方应用帐号的名称对指定包名称的第三方应用进行访问，使用Promise方式异步返回结果。

> **说明：** 从API version 9开始废弃。建议使用[setAppAccess](#setappaccess9-1)替代。
>
> 从 API version 7开始支持。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名        | 类型     | 必填   | 说明        |
| ---------- | ------ | ---- | --------- |
| name       | string | 是    | 应用帐号名称。   |
| bundleName | string | 是    | 第三方应用的包名。 |

**返回值：**

| 类型                  | 说明                    |
| :------------------ | :-------------------- |
| Promise&lt;void&gt; | Promise实例，用于获取异步返回结果。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.enableAppAccess("ZhangSan", "com.example.ohos.accountjsdemo").then(() => { 
       console.log('enableAppAccess Success');
  }).catch((err) => {
      console.log("enableAppAccess err: "  + JSON.stringify(err));
  });
  ```

### checkAppAccess<sup>9+</sup>

checkAppAccess(name: string, bundleName: string, callback: AsyncCallback&lt;boolean&gt;): void

查看指定第三方应用帐号名称对指定包名称的第三方应用的访问权限，callback回调异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名        | 类型                        | 必填   | 说明                                |
| ---------- | ------------------------- | ---- | --------------------------------- |
| name       | string                    | 是    | 应用帐号名称。                           |
| bundleName | string                    | 是    | 第三方应用的包名。                         |
| callback   | AsyncCallback&lt;void&gt; | 是    | 查看访问权限的回调。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  try {
      appAccountManager.checkAppAccess("ZhangSan", "com.example.ohos.accountjsdemo", (err) => { 
          console.log("checkAppAccess: " + JSON.stringify(err));
      });
  } catch (err) {
      console.log("checkAppAccess: " + JSON.stringify(err));
  }

  ```

### checkAppAccess<sup>9+</sup>

checkAppAccess(name: string, bundleName: string): Promise&lt;void&gt;

查看指定第三方应用帐号名称对指定包名称的第三方应用的访问权限，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名        | 类型     | 必填   | 说明        |
| ---------- | ------ | ---- | --------- |
| name       | string | 是    | 应用帐号名称。   |
| bundleName | string | 是    | 第三方应用的包名。 |

**返回值：**

| 类型                  | 说明                    |
| :------------------ | :-------------------- |
| Promise&lt;void&gt; | Promise实例，用于获取异步返回结果。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  try {
      appAccountManager.checkAppAccess("ZhangSan", "com.example.ohos.accountjsdemo").then(() => { 
          console.log('checkAppAccess Success');
      }).catch((err) => {
          console.log("checkAppAccess err: "  + JSON.stringify(err));
      });
  } catch (err) {
      console.log("checkAppAccess err: "  + JSON.stringify(err));
  }

  ```

### checkDataSyncEnabled<sup>9+</sup>

checkDataSyncEnabled(name: string, callback: AsyncCallback&lt;boolean&gt;): void

检查指定应用帐号是否允许应用数据同步，使用callback回调异步返回结果。

**需要权限：** ohos.permission.DISTRIBUTED_DATASYNC

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名      | 类型                           | 必填   | 说明                    |
| -------- | ---------------------------- | ---- | --------------------- |
| name     | string                       | 是    | 应用帐号名称。               |
| callback | AsyncCallback&lt;boolean&gt; | 是    | 检查指定应用帐号是否允许应用数据同步回调。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  try {
      appAccountManager.checkDataSyncEnabled("ZhangSan", (err, result) => {
          console.log("checkDataSyncEnabled err: " + JSON.stringify(err));
          console.log('checkDataSyncEnabled result: ' + result);
      });
  } catch (err) {
      console.log("checkDataSyncEnabled err: " + JSON.stringify(err));
  }

  ```

### checkDataSyncEnabled<sup>9+</sup>

checkDataSyncEnabled(name: string): Promise&lt;boolean&gt;

检查指定应用帐号是否允许应用数据同步，使用Promise方式异步返回结果。

**需要权限：** ohos.permission.DISTRIBUTED_DATASYNC

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名  | 类型     | 必填   | 说明      |
| ---- | ------ | ---- | ------- |
| name | string | 是    | 应用帐号名称。 |

**返回值：**

| 类型                     | 说明                    |
| :--------------------- | :-------------------- |
| Promise&lt;boolean&gt; | Promise实例，用于获取异步返回结果。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  try {
      appAccountManager.checkDataSyncEnabled("ZhangSan").then((data) => { 
          console.log('checkDataSyncEnabled, result: ' + data);
      }).catch((err) => {
          console.log("checkDataSyncEnabled err: "  + JSON.stringify(err));
      });
  } catch (err) {
      console.log("checkDataSyncEnabled err: "  + JSON.stringify(err));
  }

  ```

### checkAppAccountSyncEnable<sup>(deprecated)</sup>

checkAppAccountSyncEnable(name: string, callback: AsyncCallback&lt;boolean&gt;): void

检查指定应用帐号是否允许应用数据同步，使用callback回调异步返回结果。

> **说明：** 从API version 9开始废弃。建议使用[checkDataSyncEnabled](#checkdatasyncenabled9)替代。
>
> 从 API version 7开始支持。

**需要权限：** ohos.permission.DISTRIBUTED_DATASYNC

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名      | 类型                           | 必填   | 说明                    |
| -------- | ---------------------------- | ---- | --------------------- |
| name     | string                       | 是    | 应用帐号名称。               |
| callback | AsyncCallback&lt;boolean&gt; | 是    | 检查指定应用帐号是否允许应用数据同步回调。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.checkAppAccountSyncEnable("ZhangSan", (err, result) => { 
      console.log("checkAppAccountSyncEnable err: " + JSON.stringify(err));
      console.log('checkAppAccountSyncEnable result: ' + result);
  });
  ```

### checkAppAccountSyncEnable<sup>(deprecated)</sup>

checkAppAccountSyncEnable(name: string): Promise&lt;boolean&gt;

检查指定应用帐号是否允许应用数据同步，使用Promise方式异步返回结果。

> **说明：** 从API version 9开始废弃。建议使用[checkDataSyncEnabled](#checkdatasyncenabled9-1)替代。
>
> 从 API version 7开始支持。

**需要权限：** ohos.permission.DISTRIBUTED_DATASYNC

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名  | 类型     | 必填   | 说明      |
| ---- | ------ | ---- | ------- |
| name | string | 是    | 应用帐号名称。 |

**返回值：**

| 类型                     | 说明                    |
| :--------------------- | :-------------------- |
| Promise&lt;boolean&gt; | Promise实例，用于获取异步返回结果。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.checkAppAccountSyncEnable("ZhangSan").then((data) => { 
      console.log('checkAppAccountSyncEnable, result: ' + data);
  }).catch((err) => {
      console.log("checkAppAccountSyncEnable err: "  + JSON.stringify(err));
  });
  ```

### setCredential<sup>9+</sup>

setCredential(name: string, credentialType: string, credential: string,callback: AsyncCallback&lt;void&gt;): void

设置此应用程序帐号的凭据，使用callback回调异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名            | 类型                        | 必填   | 说明            |
| -------------- | ------------------------- | ---- | ------------- |
| name           | string                    | 是    | 应用程序帐号名称。     |
| credentialType | string                    | 是    | 要设置的凭据类型。     |
| credential     | string                    | 是    | 要设置的凭据。       |
| callback       | AsyncCallback&lt;void&gt; | 是    | 设置此应用帐号的凭据回调。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  try {
      appAccountManager.setCredential("ZhangSan", "credentialType001", "credential001", (err) => { 
          console.log("setCredential err: " + JSON.stringify(err));
      });
  } catch (err) {
    console.log("setCredential err: " + JSON.stringify(err));
  }
  ```

### setCredential<sup>9+</sup>

setCredential(name: string, credentialType: string, credential: string): Promise&lt;void&gt;

设置此应用程序帐号的凭据，使用Promise方式异步返回结果。

> **说明：** 从API version 9开始废弃。
>
> 从 API version 7开始支持。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名            | 类型     | 必填   | 说明         |
| -------------- | ------ | ---- | ---------- |
| name           | string | 是    | 应用帐号的名称。   |
| credentialType | string | 是    | 要设置的凭据的类型。 |
| credential     | string | 是    | 要设置的凭据。    |

**返回值：**

| 类型                  | 说明                    |
| :------------------ | :-------------------- |
| Promise&lt;void&gt; | Promise实例，用于获取异步返回结果。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  try {
      appAccountManager.setCredential("ZhangSan", "credentialType001", "credential001").then(() => { 
          console.log('setCredential Success');
      }).catch((err) => {
          console.log("setCredential err: "  + JSON.stringify(err));
      });
  } catch (err) {
      console.log("setCredential err: "  + JSON.stringify(err));
  }

  ```

### setAccountCredential<sup>(deprecated)</sup>

setAccountCredential(name: string, credentialType: string, credential: string,callback: AsyncCallback&lt;void&gt;): void

设置此应用程序帐号的凭据，使用callback回调异步返回结果。

> **说明：** 从API version 9开始废弃，建议使用[setCredential](#setcredential9)替代。
>
> 从 API version 7开始支持。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名            | 类型                        | 必填   | 说明            |
| -------------- | ------------------------- | ---- | ------------- |
| name           | string                    | 是    | 应用程序帐号名称。     |
| credentialType | string                    | 是    | 要设置的凭据类型。     |
| credential     | string                    | 是    | 要设置的凭据。       |
| callback       | AsyncCallback&lt;void&gt; | 是    | 设置此应用帐号的凭据回调。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.setAccountCredential("ZhangSan", "credentialType001", "credential001", (err) => { 
      console.log("setAccountCredential err: " + JSON.stringify(err));
  });
  ```

### setAccountCredential<sup>(deprecated)</sup>

setAccountCredential(name: string, credentialType: string, credential: string): Promise&lt;void&gt;

设置此应用程序帐号的凭据，使用Promise方式异步返回结果。

> **说明：** 从API version 9开始废弃，建议使用[setCredential](#setcredential9-1)替代。
>
> 从 API version 7开始支持。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名            | 类型     | 必填   | 说明         |
| -------------- | ------ | ---- | ---------- |
| name           | string | 是    | 应用帐号的名称。   |
| credentialType | string | 是    | 要设置的凭据的类型。 |
| credential     | string | 是    | 要设置的凭据。    |

**返回值：**

| 类型                  | 说明                    |
| :------------------ | :-------------------- |
| Promise&lt;void&gt; | Promise实例，用于获取异步返回结果。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.setAccountCredential("ZhangSan", "credentialType001", "credential001").then(() => { 
      console.log('setAccountCredential Success');
  }).catch((err) => {
      console.log("setAccountCredential err: "  + JSON.stringify(err));
  });
  ```

### setAccountExtraInfo<sup>(deprecated)</sup>

setAccountExtraInfo(name: string, extraInfo: string, callback: AsyncCallback&lt;void&gt;): void

设置此应用程序帐号的额外信息，使用callback回调异步返回结果。

> **说明：** 从API version 9开始废弃。
>
> 从 API version 7开始支持。


**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名       | 类型                        | 必填   | 说明              |
| --------- | ------------------------- | ---- | --------------- |
| name      | string                    | 是    | 应用帐号名称。         |
| extraInfo | string                    | 是    | 要设置的额外信息。       |
| callback  | AsyncCallback&lt;void&gt; | 是    | 设置此应用帐号的额外信息回调。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.setAccountExtraInfo("ZhangSan", "Tk002", (err) => { 
      console.log("setAccountExtraInfo err: " + JSON.stringify(err));
  });
  ```

### setAccountExtraInfo<sup>(deprecated)</sup>

setAccountExtraInfo(name: string, extraInfo: string): Promise&lt;void&gt;

设置此应用程序帐号的额外信息，使用Promise方式异步返回结果。

> **说明：** 从API version 9开始废弃。
>
> 从 API version 7开始支持。


**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名       | 类型     | 必填   | 说明        |
| --------- | ------ | ---- | --------- |
| name      | string | 是    | 应用帐号名称。   |
| extraInfo | string | 是    | 要设置的额外信息。 |

**返回值：**

| 类型                  | 说明                    |
| :------------------ | :-------------------- |
| Promise&lt;void&gt; | Promise实例，用于获取异步返回结果。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.setAccountExtraInfo("ZhangSan", "Tk002").then(() => { 
      console.log('setAccountExtraInfo Success');
  }).catch((err) => {
      console.log("setAccountExtraInfo err: "  + JSON.stringify(err));
  });
  ```
  
### setDataSyncEnabled<sup>9+</sup>

setDataSyncEnabled(name: string, isEnable: boolean, callback: AsyncCallback&lt;void&gt;): void

设置指定的应用程序帐号是否允许应用程序数据同步，使用callback回调异步返回结果。

**需要权限：** ohos.permission.DISTRIBUTED_DATASYNC

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名      | 类型                        | 必填   | 说明                        |
| -------- | ------------------------- | ---- | ------------------------- |
| name     | string                    | 是    | 应用帐号名称。                   |
| isEnable | boolean                   | 是    | 是否允许应用数据同步。               |
| callback | AsyncCallback&lt;void&gt; | 是    | 设置指定的应用帐号是否允许应用程序数据同步的回调。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  try {
      appAccountManager.setDataSyncEnabled("ZhangSan", true, (err) => { 
          console.log("setDataSyncEnabled err: " + JSON.stringify(err));
      });
  } catch (err) {
      console.log("setDataSyncEnabled err: " + JSON.stringify(err));
  }
  ```

### setDataSyncEnabled<sup>9+</sup>

setDataSyncEnabled(name: string, isEnable: boolean): Promise&lt;void&gt;

设置指定的应用程序帐号是否允许应用程序数据同步，使用Promise方式异步返回结果。

**需要权限：** ohos.permission.DISTRIBUTED_DATASYNC

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名      | 类型      | 必填   | 说明          |
| -------- | ------- | ---- | ----------- |
| name     | string  | 是    | 应用帐号名称。     |
| isEnable | boolean | 是    | 是否允许应用数据同步。 |

**返回值：**

| 类型                  | 说明                    |
| :------------------ | :-------------------- |
| Promise&lt;void&gt; | Promise实例，用于获取异步返回结果。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  try {
      appAccountManager .setDataSyncEnabled("ZhangSan", true).then(() => { 
          console.log('setDataSyncEnabled Success');
      }).catch((err) => {
          console.log("setDataSyncEnabled err: "  + JSON.stringify(err));
      });
  } catch (err) {
      console.log("setDataSyncEnabled err: "  + JSON.stringify(err));
  }
  ```

### setAppAccountSyncEnable<sup>(deprecated)</sup>

setAppAccountSyncEnable(name: string, isEnable: boolean, callback: AsyncCallback&lt;void&gt;): void

设置指定的应用程序帐号是否允许应用程序数据同步，使用callback回调异步返回结果。

> **说明：** 从API version 9开始废弃, 建议使用[setDataSyncEnabled](#setdatasyncenabled9)替代。
>
> 从 API version 7开始支持。

**需要权限：** ohos.permission.DISTRIBUTED_DATASYNC

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名      | 类型                        | 必填   | 说明                        |
| -------- | ------------------------- | ---- | ------------------------- |
| name     | string                    | 是    | 应用帐号名称。                   |
| isEnable | boolean                   | 是    | 是否允许应用数据同步。               |
| callback | AsyncCallback&lt;void&gt; | 是    | 设置指定的应用帐号是否允许应用程序数据同步的回调。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.setAppAccountSyncEnable("ZhangSan", true, (err) => { 
      console.log("setAppAccountSyncEnable err: " + JSON.stringify(err));
  });
  ```

### setAppAccountSyncEnable<sup>(deprecated)</sup>

setAppAccountSyncEnable(name: string, isEnable: boolean): Promise&lt;void&gt;

设置指定的应用程序帐号是否允许应用程序数据同步，使用Promise方式异步返回结果。

> **说明：** 从API version 9开始废弃, 建议使用[setDataSyncEnabled](#setdatasyncenabled9-1)替代。
>
> 从 API version 7开始支持。

**需要权限：** ohos.permission.DISTRIBUTED_DATASYNC

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名      | 类型      | 必填   | 说明          |
| -------- | ------- | ---- | ----------- |
| name     | string  | 是    | 应用帐号名称。     |
| isEnable | boolean | 是    | 是否允许应用数据同步。 |

**返回值：**

| 类型                  | 说明                    |
| :------------------ | :-------------------- |
| Promise&lt;void&gt; | Promise实例，用于获取异步返回结果。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager .setAppAccountSyncEnable("ZhangSan", true).then(() => { 
      console.log('setAppAccountSyncEnable Success');
  }).catch((err) => {
      console.log("setAppAccountSyncEnable err: "  + JSON.stringify(err));
  });
  ```

### setCustomData<sup>9+</sup>

setAssociatedData(name: string, key: string, value: string, callback: AsyncCallback&lt;void&gt;): void

设置与此应用程序帐号关联的数据，使用callback回调异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名      | 类型                        | 必填   | 说明                |
| -------- | ------------------------- | ---- | ----------------- |
| name     | string                    | 是    | 应用帐号名称。           |
| key      | string                    | 是    | 要设置的数据的键，密钥可以自定义。 |
| value    | string                    | 是    | 要设置的数据的值。         |
| callback | AsyncCallback&lt;void&gt; | 是    | 设置与此应用帐号关联的数据的回调。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  try {
      appAccountManager.setCustomData("ZhangSan", "k001", "v001", (err) => { 
          console.log("setCustomData err: " + JSON.stringify(err));
      });    
  } catch (err) {
      console.log("setCustomData err: " + JSON.stringify(err));
  }
  ```

### setCustomData<sup>9+</sup>

setAssociatedData(name: string, key: string, value: string): Promise&lt;void&gt;

设置与此应用程序帐号关联的数据，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名   | 类型     | 必填   | 说明                |
| ----- | ------ | ---- | ----------------- |
| name  | string | 是    | 应用帐号名称。           |
| key   | string | 是    | 要设置的数据的键，密钥可以自定义。 |
| value | string | 是    | 要设置的数据的值。         |

**返回值：**

| 类型                  | 说明                    |
| :------------------ | :-------------------- |
| Promise&lt;void&gt; | Promise实例，用于获取异步返回结果。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  try {
      appAccountManager.setCustomData("ZhangSan", "k001", "v001").then(() => { 
          console.log('setCustomData Success');
      }).catch((err) => {
          console.log("setCustomData err: "  + JSON.stringify(err));
      });
  } catch (err) {
      console.log("setCustomData err: "  + JSON.stringify(err));
  }
  ```

### setAssociatedData<sup>(deprecated)</sup>

setAssociatedData(name: string, key: string, value: string, callback: AsyncCallback&lt;void&gt;): void

设置与此应用程序帐号关联的数据，使用callback回调异步返回结果。

> **说明：** 从API version 9开始废弃, 建议使用[setCustomData](#setcustomdata9)替代。
>
> 从 API version 7开始支持。


**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名      | 类型                        | 必填   | 说明                |
| -------- | ------------------------- | ---- | ----------------- |
| name     | string                    | 是    | 应用帐号名称。           |
| key      | string                    | 是    | 要设置的数据的键，密钥可以自定义。 |
| value    | string                    | 是    | 要设置的数据的值。         |
| callback | AsyncCallback&lt;void&gt; | 是    | 设置与此应用帐号关联的数据的回调。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.setAssociatedData("ZhangSan", "k001", "v001", (err) => { 
      console.log("setAssociatedData err: " + JSON.stringify(err));
  });
  ```

### setAssociatedData<sup>(deprecated)</sup>

setAssociatedData(name: string, key: string, value: string): Promise&lt;void&gt;

设置与此应用程序帐号关联的数据，使用Promise方式异步返回结果。

> **说明：** 从API version 9开始废弃, 建议使用[setCustomData](#setcustomdata9-1)替代。
>
> 从 API version 7开始支持。


**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名   | 类型     | 必填   | 说明                |
| ----- | ------ | ---- | ----------------- |
| name  | string | 是    | 应用帐号名称。           |
| key   | string | 是    | 要设置的数据的键，密钥可以自定义。 |
| value | string | 是    | 要设置的数据的值。         |

**返回值：**

| 类型                  | 说明                    |
| :------------------ | :-------------------- |
| Promise&lt;void&gt; | Promise实例，用于获取异步返回结果。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.setAssociatedData("ZhangSan", "k001", "v001").then(() => { 
      console.log('setAssociatedData Success');
  }).catch((err) => {
      console.log("setAssociatedData err: "  + JSON.stringify(err));
  });
  ```

### getAllAccounts<sup>9+</sup>

getAllAccounts(callback: AsyncCallback&lt;Array&lt;AppAccountInfo&gt;&gt;): void

获取全部应用已授权帐号信息。

**需要权限：** ohos.permission.GET_ALL_APP_ACCOUNTS，仅系统应用可用。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名      | 类型                                       | 必填   | 说明        |
| -------- | ---------------------------------------- | ---- | --------- |
| callback | AsyncCallback&lt;Array&lt;[AppAccountInfo](#appaccountinfo)&gt;&gt; | 是    | 应用帐号信息列表。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  try {
      appAccountManager.getAllAccounts((err, data)=>{
          console.debug("getAllAccounts err:" + JSON.stringify(err));
          console.debug("getAllAccounts data:" + JSON.stringify(data));
      });
  } catch (err) {
      console.debug("getAllAccounts err:" + JSON.stringify(err));
  }
  ```

### getAllAccounts<sup>9+</sup>

getAllAccounts(): Promise&lt;Array&lt;AppAccountInfo&gt;&gt;

获取全部应用已授权帐号信息。

**需要权限：** ohos.permission.GET_ALL_APP_ACCOUNTS，仅系统应用可用。

**系统能力：** SystemCapability.Account.AppAccount

**返回值：**

| 类型                                       | 说明                    |
| ---------------------------------------- | --------------------- |
| Promise&lt;Array&lt;[AppAccountInfo](#appaccountinfo)&gt;&gt; | Promise实例，用于获取异步返回结果。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  try {
      appAccountManager.getAllAccounts().then((data) => { 
          console.log('getAllAccounts: ' + data);
      }).catch((err) => {
          console.log("getAllAccounts err: "  + JSON.stringify(err));
      });
  } catch (err) {
      console.log("getAllAccounts err: "  + JSON.stringify(err));
  }
  ```

### getAllAccessibleAccounts<sup>(deprecated)</sup>

getAllAccessibleAccounts(callback: AsyncCallback&lt;Array&lt;AppAccountInfo&gt;&gt;): void

获取全部应用已授权帐号信息。

> **说明：** 从API version 9开始废弃, 建议使用[getAllAccounts](#getallaccounts9)替代。
>
> 从 API version 7开始支持。

**需要权限：** ohos.permission.GET_ALL_APP_ACCOUNTS，仅系统应用可用。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名      | 类型                                       | 必填   | 说明        |
| -------- | ---------------------------------------- | ---- | --------- |
| callback | AsyncCallback&lt;Array&lt;[AppAccountInfo](#appaccountinfo)&gt;&gt; | 是    | 应用帐号信息列表。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getAllAccessibleAccounts((err, data)=>{
  	console.debug("getAllAccessibleAccounts err:" + JSON.stringify(err));
  	console.debug("getAllAccessibleAccounts data:" + JSON.stringify(data));
  });
  ```

### getAllAccessibleAccounts<sup>(deprecated)</sup>

getAllAccessibleAccounts(): Promise&lt;Array&lt;AppAccountInfo&gt;&gt;

获取全部应用已授权帐号信息。

> **说明：** 从API version 9开始废弃, 建议使用[getAllAccounts](#getallaccounts9-1)替代。
>
> 从 API version 7开始支持。

**需要权限：** ohos.permission.GET_ALL_APP_ACCOUNTS，仅系统应用可用。

**系统能力：** SystemCapability.Account.AppAccount

**返回值：**

| 类型                                       | 说明                    |
| ---------------------------------------- | --------------------- |
| Promise&lt;Array&lt;[AppAccountInfo](#appaccountinfo)&gt;&gt; | Promise实例，用于获取异步返回结果。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getAllAccessibleAccounts().then((data) => { 
       console.log('getAllAccessibleAccounts: ' + data);
  }).catch((err) => {
      console.log("getAllAccessibleAccounts err: "  + JSON.stringify(err));
  });
  ```

### getAccountsByOwner<sup>9+</sup>

getAccountsByOwner(owner: string, callback: AsyncCallback&lt;Array&lt;AppAccountInfo&gt;&gt;): void

获取指定应用全部帐号信息。

**需要权限：** ohos.permission.GET_ALL_APP_ACCOUNTS，仅系统应用可用。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名      | 类型                                       | 必填   | 说明        |
| -------- | ---------------------------------------- | ---- | --------- |
| owner    | string                                   | 是    | 应用包名称。    |
| callback | AsyncCallback&lt;Array&lt;[AppAccountInfo](#appaccountinfo)&gt;&gt; | 是    | 应用帐号信息列表。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  const selfBundle = "com.example.actsgetallaaccounts";
  try {
      appAccountManager.getAccountsByOwner(selfBundle, (err, data)=>{
          console.debug("getAccountsByOwner err:" + JSON.stringify(err));
          console.debug("getAccountsByOwner data:" + JSON.stringify(data));
      });
  } catch (err) {
      console.debug("getAccountsByOwner err:" + JSON.stringify(err));
  }
  ```

### getAccountsByOwner<sup>9+</sup>

getAccountsByOwner(owner: string): Promise&lt;Array&lt;AppAccountInfo&gt;&gt;

获取指定应用全部帐号信息。

**需要权限：** ohos.permission.GET_ALL_APP_ACCOUNTS，仅系统应用可用。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名   | 类型     | 必填   | 说明     |
| ----- | ------ | ---- | ------ |
| owner | string | 是    | 应用包名称。 |

**返回值：**

| 类型                                       | 说明                    |
| ---------------------------------------- | --------------------- |
| Promise&lt;Array&lt;[AppAccountInfo](#appaccountinfo)&gt;&gt; | Promise实例，用于获取异步返回结果。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  const selfBundle = "com.example.actsgetallaaccounts";
  try {
      appAccountManager.getAccountsByOwner(selfBundle).then((data) => { 
          console.log('getAccountsByOwner: ' + data);
      }).catch((err) => {
          console.log("getAccountsByOwner err: "  + JSON.stringify(err));
      });
  } catch (err) {
      console.log("getAccountsByOwner err: "  + JSON.stringify(err));
  }
  ```

### getAllAccounts<sup>(deprecated)</sup>

getAllAccounts(owner: string, callback: AsyncCallback&lt;Array&lt;AppAccountInfo&gt;&gt;): void

获取指定应用全部帐号信息。

> **说明：** 从API version 9开始废弃, 建议使用[getAccountsByOwner]替代。
>
> 从 API version 7开始支持。

**需要权限：** ohos.permission.GET_ALL_APP_ACCOUNTS，仅系统应用可用。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名      | 类型                                       | 必填   | 说明        |
| -------- | ---------------------------------------- | ---- | --------- |
| owner    | string                                   | 是    | 应用包名称。    |
| callback | AsyncCallback&lt;Array&lt;[AppAccountInfo](#appaccountinfo)&gt;&gt; | 是    | 应用帐号信息列表。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  const selfBundle = "com.example.actsgetallaaccounts";
  appAccountManager.getAllAccounts(selfBundle, (err, data)=>{
  	console.debug("getAllAccounts err:" + JSON.stringify(err));
  	console.debug("getAllAccounts data:" + JSON.stringify(data));
  });
  ```

### getAllAccounts<sup>(deprecated)</sup>

getAllAccounts(owner: string): Promise&lt;Array&lt;AppAccountInfo&gt;&gt;

获取指定应用全部帐号信息。

> **说明：** 从API version 9开始废弃, 建议使用[getAccountsByOwner](#getaccountsbyowner9-1)替代。
>
> 从 API version 7开始支持。

**需要权限：** ohos.permission.GET_ALL_APP_ACCOUNTS，仅系统应用可用。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名   | 类型     | 必填   | 说明     |
| ----- | ------ | ---- | ------ |
| owner | string | 是    | 应用包名称。 |

**返回值：**

| 类型                                       | 说明                    |
| ---------------------------------------- | --------------------- |
| Promise&lt;Array&lt;[AppAccountInfo](#appaccountinfo)&gt;&gt; | Promise实例，用于获取异步返回结果。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  const selfBundle = "com.example.actsgetallaaccounts";
  appAccountManager.getAllAccounts(selfBundle).then((data) => { 
       console.log('getAllAccounts: ' + data);
  }).catch((err) => {
      console.log("getAllAccounts err: "  + JSON.stringify(err));
  });
  ```

### getCredential<sup>9+</sup>

getCredential(name: string, credentialType: string, callback: AsyncCallback&lt;string&gt;): void

获取此应用帐号的凭据（如数字密码、人脸和PIN码等），使用callback回调异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名            | 类型                          | 必填   | 说明             |
| -------------- | --------------------------- | ---- | -------------- |
| name           | string                      | 是    | 应用帐号名称。        |
| credentialType | string                      | 是    | 获取此应用帐号的凭据的类型。 |
| callback       | AsyncCallback&lt;string&gt; | 是    | 获取此应用帐号的凭据的回调。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  try {
      appAccountManager.getCredential("ZhangSan", "credentialType001", (err, result) => { 
          console.log("getCredential err: " + JSON.stringify(err));
          console.log('getCredential result: ' + result);
      });
  } catch (err) {
      console.log("getCredential err: " + JSON.stringify(err));
  }
  ```

### getCredential<sup>9+</sup>

getCredential(name: string, credentialType: string): Promise&lt;string&gt;

获取此应用程序帐号的凭据，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名            | 类型     | 必填   | 说明         |
| -------------- | ------ | ---- | ---------- |
| name           | string | 是    | 应用帐号名称。    |
| credentialType | string | 是    | 要获取的凭据的类型。 |

**返回值：**

| 类型                    | 说明                    |
| :-------------------- | :-------------------- |
| Promise&lt;string&gt; | Promise实例，用于获取异步返回结果。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  try {
      appAccountManager.getCredential("ZhangSan", "credentialType001").then((data) => { 
          console.log('getCredential, result: ' + data);
      }).catch((err) => {
          console.log("getCredential err: "  + JSON.stringify(err));
      });
  } catch (err) {
      console.log("getCredential err: "  + JSON.stringify(err));
  }
  ```

### getAccountCredential<sup>(deprecated)</sup>

getAccountCredential(name: string, credentialType: string, callback: AsyncCallback&lt;string&gt;): void

获取此应用帐号的凭据（如数字密码、人脸和PIN码等），使用callback回调异步返回结果。

> **说明：** 从API version 9开始废弃, 建议使用[getCredential](#getcredential9)替代。
>
> 从 API version 7开始支持。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名            | 类型                          | 必填   | 说明             |
| -------------- | --------------------------- | ---- | -------------- |
| name           | string                      | 是    | 应用帐号名称。        |
| credentialType | string                      | 是    | 获取此应用帐号的凭据的类型。 |
| callback       | AsyncCallback&lt;string&gt; | 是    | 获取此应用帐号的凭据的回调。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getAccountCredential("ZhangSan", "credentialType001", (err, result) => { 
      console.log("getAccountCredential err: " + JSON.stringify(err));
      console.log('getAccountCredential result: ' + result);
  });
  ```

### getAccountCredential<sup>(deprecated)</sup>

getAccountCredential(name: string, credentialType: string): Promise&lt;string&gt;

获取此应用程序帐号的凭据，使用Promise方式异步返回结果。

> **说明：** 从API version 9开始废弃, 建议使用[getCredential](#getcredential9-1)替代。
>
> 从 API version 7开始支持。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名            | 类型     | 必填   | 说明         |
| -------------- | ------ | ---- | ---------- |
| name           | string | 是    | 应用帐号名称。    |
| credentialType | string | 是    | 要获取的凭据的类型。 |

**返回值：**

| 类型                    | 说明                    |
| :-------------------- | :-------------------- |
| Promise&lt;string&gt; | Promise实例，用于获取异步返回结果。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getAccountCredential("ZhangSan", "credentialType001").then((data) => { 
      console.log('getAccountCredential, result: ' + data);
  }).catch((err) => {
      console.log("getAccountCredential err: "  + JSON.stringify(err));
  });
  ```

### getAccountExtraInfo<sup>(deprecated)</sup>

getAccountExtraInfo(name: string, callback: AsyncCallback&lt;string&gt;): void

获取此应用帐号的额外信息（能转换成string类型的其它信息），使用callback回调异步返回结果。

> **说明：** 从API version 9开始废弃。
>
> 从 API version 7开始支持。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名      | 类型                          | 必填   | 说明              |
| -------- | --------------------------- | ---- | --------------- |
| name     | string                      | 是    | 应用帐号名称。         |
| callback | AsyncCallback&lt;string&gt; | 是    | 获取此应用帐号的额外信息回调。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getAccountExtraInfo("ZhangSan", (err, result) => { 
      console.log("getAccountExtraInfo err: " + JSON.stringify(err));
      console.log('getAccountExtraInfo result: ' + result);
  });
  ```

### getAccountExtraInfo<sup>(deprecated)</sup>

getAccountExtraInfo(name: string): Promise&lt;string&gt;

获取此应用程序帐号的额外信息，使用Promise方式异步返回结果。

> **说明：** 从API version 9开始废弃。
>
> 从 API version 7开始支持。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名  | 类型     | 必填   | 说明      |
| ---- | ------ | ---- | ------- |
| name | string | 是    | 应用帐号名称。 |

**返回值：**

| 类型                    | 说明                    |
| :-------------------- | :-------------------- |
| Promise&lt;string&gt; | Promise实例，用于获取异步返回结果。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getAccountExtraInfo("ZhangSan").then((data) => { 
      console.log('getAccountExtraInfo, result: ' + data);
  }).catch((err) => {
      console.log("getAccountExtraInfo err: "  + JSON.stringify(err));
  });
  ```

### getCustomData<sup>9+</sup>

getCustomData(name: string, key: string, callback: AsyncCallback&lt;string&gt;): void

获取与此应用程序帐号关联的数据，使用callback回调异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名      | 类型                          | 必填   | 说明                |
| -------- | --------------------------- | ---- | ----------------- |
| name     | string                      | 是    | 应用帐号名称。           |
| key      | string                      | 是    | 要获取的数据的键。         |
| callback | AsyncCallback&lt;string&gt; | 是    | 获取与此应用帐号关联的数据的回调。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  try {
      appAccountManager.getCustomData("ZhangSan", "k001", (err, result) => { 
          console.log("getCustomData err: " + JSON.stringify(err));
          console.log('getCustomData result: ' + result);
      });
  } catch (err) {
      console.log("getCustomData err: " + JSON.stringify(err));
  }
  ```

### getCustomData<sup>9+</sup>

getCustomData(name: string, key: string): Promise&lt;string&gt;

获取与此应用程序帐号关联的数据，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名  | 类型     | 必填   | 说明        |
| ---- | ------ | ---- | --------- |
| name | string | 是    | 应用帐号名称。   |
| key  | string | 是    | 要获取的数据的键。 |

**返回值：**

| 类型                    | 说明                    |
| :-------------------- | :-------------------- |
| Promise&lt;string&gt; | Promise实例，用于获取异步返回结果。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  try {
      appAccountManager.getCustomData("ZhangSan", "k001").then((data) => { 
          console.log('getCustomData: ' + data);
      }).catch((err) => {
          console.log("getCustomData err: "  + JSON.stringify(err));
      });
  } catch (err) {
      console.log("getCustomData err: "  + JSON.stringify(err));
  }
  ```

### getAssociatedData<sup>(deprecated)</sup>

getAssociatedData(name: string, key: string, callback: AsyncCallback&lt;string&gt;): void

获取与此应用程序帐号关联的数据，使用callback回调异步返回结果。

> **说明：** 从API version 9开始废弃, 建议使用[getCustomData](#getcustomdata9)替代。
>
> 从 API version 7开始支持。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名      | 类型                          | 必填   | 说明                |
| -------- | --------------------------- | ---- | ----------------- |
| name     | string                      | 是    | 应用帐号名称。           |
| key      | string                      | 是    | 要获取的数据的键。         |
| callback | AsyncCallback&lt;string&gt; | 是    | 获取与此应用帐号关联的数据的回调。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getAssociatedData("ZhangSan", "k001", (err, result) => { 
      console.log("getAssociatedData err: " + JSON.stringify(err));
      console.log('getAssociatedData result: ' + result);
  });
  ```

### getAssociatedData<sup>(deprecated)</sup>

getAssociatedData(name: string, key: string): Promise&lt;string&gt;

获取与此应用程序帐号关联的数据，使用Promise方式异步返回结果。

> **说明：** 从API version 9开始废弃, 建议使用[getCustomData](#getcustomdata9-1)替代。
>
> 从 API version 7开始支持。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名  | 类型     | 必填   | 说明        |
| ---- | ------ | ---- | --------- |
| name | string | 是    | 应用帐号名称。   |
| key  | string | 是    | 要获取的数据的键。 |

**返回值：**

| 类型                    | 说明                    |
| :-------------------- | :-------------------- |
| Promise&lt;string&gt; | Promise实例，用于获取异步返回结果。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getAssociatedData("ZhangSan", "k001").then((data) => { 
       console.log('getAssociatedData: ' + data);
  }).catch((err) => {
      console.log("getAssociatedData err: "  + JSON.stringify(err));
  });
  ```

### getAssociatedDataSync<sup>9+</sup>

getAssociatedDataSync(name: string, key: string): string;

获取与此应用程序帐号关联的数据，使用同步方式返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名  | 类型     | 必填   | 说明        |
| ---- | ------ | ---- | --------- |
| name | string | 是    | 应用帐号名称。   |
| key  | string | 是    | 要获取的数据的键。 |

**返回值：**

| 类型                    | 说明                    |
| :-------------------- | :-------------------- |
| string | 目标关联数据的取值。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  try {
      var backData = appAccountManager.getAssociatedDataSync("ZhangSan", "k001");
      console.info("getAssociatedDataSync backData:" + JSON.stringify(backData));
  } catch (err) {
    console.error(`getAssociatedDataSync err, code is ${e.code}, message is ${e.message}`);
  }
  ```

### on('accountChange')<sup>9+</sup>

on(type: 'accountChange', owners: Array&lt;string&gt;, callback: Callback&lt;Array&lt;AppAccountInfo&gt;&gt;): void

订阅指定帐号所有者的帐户变更事件，使用callback回调异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                             |
| -------- | ---------------------------------------- | ---- | ------------------------------ |
| type     | 'accountChange'                                 | 是    | 关于帐号更改事件，当帐号所有者更新帐号时，订阅者将收到通知。 |
| owners   | Array&lt;string&gt;                      | 是    | 指示帐号的所有者。                      |
| callback | Callback&lt;Array&lt;[AppAccountInfo](#appaccountinfo)&gt;&gt; | 是    | 订阅指定帐号所有者的帐号变更事件的回调。           |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  function changeOnCallback(data){
  	console.debug("receive change data:" + JSON.stringify(data));
  }
  try{
  	appAccountManager.on('accountChange', ["com.example.actsaccounttest"], changeOnCallback);
  }
  catch(err){
  	console.error("on accountOnOffDemo err:" + JSON.stringify(err));
  }
  ```

### on('change')<sup>(deprecated)</sup>

on(type: 'change', owners: Array&lt;string&gt;, callback: Callback&lt;Array&lt;AppAccountInfo&gt;&gt;): void

订阅指定帐号所有者的帐户变更事件，使用callback回调异步返回结果。

> **说明：** 从API version 9开始废弃, 建议使用[on('accountChange')](#onaccountchange9)替代。
>
> 从 API version 7开始支持。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                             |
| -------- | ---------------------------------------- | ---- | ------------------------------ |
| type     | 'change'                                 | 是    | 关于帐号更改事件，当帐号所有者更新帐号时，订阅者将收到通知。 |
| owners   | Array&lt;string&gt;                      | 是    | 指示帐号的所有者。                      |
| callback | Callback&lt;Array&lt;[AppAccountInfo](#appaccountinfo)&gt;&gt; | 是    | 订阅指定帐号所有者的帐号变更事件的回调。           |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  function changeOnCallback(data){
  	console.debug("receive change data:" + JSON.stringify(data));
  }
  try{
  	appAccountManager.on('change', ["com.example.actsaccounttest"], changeOnCallback);
  }
  catch(err){
  	console.error("on accountOnOffDemo err:" + JSON.stringify(err));
  }
  ```

### off('accountChange')<sup>9+</sup>

off(type: 'accountChange', callback?: Callback<Array\<AppAccountInfo>>): void

取消订阅帐号事件，使用callback回调异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名      | 类型                               | 必填   | 说明           |
| -------- | -------------------------------- | ---- | ------------ |
| type     | 'accountChange'                         | 是    | 关于帐号更改事件。    |
| callback | Callback<Array\<[AppAccountInfo](#appaccountinfo)>> | 否    | 取消订阅帐号事件的回调。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  function changeOnCallback(data){
  	console.debug("receive change data:" + JSON.stringify(data));
  	appAccountManager.off('accountChange', function(){
  		console.debug("off finish");
  	})
  }
  try{
  	appAccountManager.on('accountChange', ["com.example.actsaccounttest"], changeOnCallback);
  }
  catch(err){
  	console.error("on accountOnOffDemo err:" + JSON.stringify(err));
  }
  ```

### off('change')<sup>(deprecated)</sup>

off(type: 'change', callback?: Callback<Array\<AppAccountInfo>>): void

取消订阅帐号事件，使用callback回调异步返回结果。

> **说明：** 从API version 9开始废弃, 建议使用[off('accountChange')](#offaccountchange9)替代。
>
> 从 API version 7开始支持。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名      | 类型                               | 必填   | 说明           |
| -------- | -------------------------------- | ---- | ------------ |
| type     | 'change'                         | 是    | 关于帐号更改事件。    |
| callback | Callback<Array\<[AppAccountInfo](#appaccountinfo)>> | 否    | 取消订阅帐号事件的回调。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  function changeOnCallback(data){
  	console.debug("receive change data:" + JSON.stringify(data));
  	appAccountManager.off('change', function(){
  		console.debug("off finish");
  	})
  }
  try{
  	appAccountManager.on('change', ["com.example.actsaccounttest"], changeOnCallback);
  }
  catch(err){
  	console.error("on accountOnOffDemo err:" + JSON.stringify(err));
  }
  ```

### auth<sup>9+</sup>

auth(name: string, owner: string, authType: string, callback: AuthCallback): void

对应用帐户进行鉴权以获取Auth令牌，使用callback回调异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名      | 类型                    | 必填   | 说明              |
| -------- | --------------------- | ---- | --------------- |
| name     | string                | 是    | 要鉴权的应用帐号名称。     |
| owner    | string                | 是    | 要鉴权的应用帐号所有者包名。  |
| authType | string                | 是    | 鉴权类型。           |
| callback | [AuthCallback](#authcallback9) | 是    | 认证器回调，用于返回鉴权结果。 |

**示例：**

  ```js
  import featureAbility from '@ohos.ability.featureAbility';

  function onResultCallback(code, result) {
      console.log("resultCode: "  + code);
      console.log("result: "  + JSON.stringify(result));
  }

  function onRequestRedirectedCallback(request) {
      let abilityStartSetting = {want: request};
      featureAbility.startAbility(abilityStartSetting, (err)=>{
          console.log("startAbility err: " + JSON.stringify(err));
      });
  }

  const appAccountManager = account_appAccount.createAppAccountManager();
  try {
      appAccountManager.auth("LiSi", "com.example.ohos.accountjsdemo", "getSocialData", {
          onResult: onResultCallback,
          onRequestRedirected: onRequestRedirectedCallback
      });
  } catch (err) {
      console.log("auth err: "  + JSON.stringify(err));
  }
  ```

### auth<sup>9+</sup>

auth(name: string, owner: string, authType: string, options: {[key: string]: Object}, callback: AuthCallback): void

对应用帐户进行鉴权以获取OAuth令牌，使用callback回调异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名      | 类型                    | 必填   | 说明              |
| -------- | --------------------- | ---- | --------------- |
| name     | string                | 是    | 要鉴权的应用帐号名称。     |
| owner    | string                | 是    | 要鉴权的应用帐号所有者包名。  |
| authType | string                | 是    | 鉴权类型。           |
| options  | {[key: string]: Object}  | 是    | 鉴权所需的可选项。       |
| callback | [AuthCallback](#authcallback9) | 是    | 认证器回调，用于返回鉴权结果。 |

**示例：**

  ```js
  import featureAbility from '@ohos.ability.featureAbility';

  function onResultCallback(code, result) {
      console.log("resultCode: "  + code);
      console.log("result: "  + JSON.stringify(result));
  }

  function onRequestRedirectedCallback(request) {
      let abilityStartSetting = {want: request};
      featureAbility.startAbility(abilityStartSetting, (err)=>{
          console.log("startAbility err: " + JSON.stringify(err));
      });
  }

  const appAccountManager = account_appAccount.createAppAccountManager();
  try {
      appAccountManager.auth("LiSi", "com.example.ohos.accountjsdemo", "getSocialData", {}, {
          onResult: onResultCallback,
          onRequestRedirected: onRequestRedirectedCallback
      });
  } catch (err) {
      console.log("auth err: "  + JSON.stringify(err));
  }
  ```

### authenticate<sup>(deprecated)</sup>

authenticate(name: string, owner: string, authType: string, options: {[key: string]: any}, callback: AuthenticatorCallback): void

对应用帐户进行鉴权以获取OAuth令牌，使用callback回调异步返回结果。

> **说明：** 从API version 9开始废弃, 建议使用[auth](#auth9)替代。
>
> 从 API version 8开始支持。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名      | 类型                    | 必填   | 说明              |
| -------- | --------------------- | ---- | --------------- |
| name     | string                | 是    | 要鉴权的应用帐号名称。     |
| owner    | string                | 是    | 要鉴权的应用帐号所有者包名。  |
| authType | string                | 是    | 鉴权类型。           |
| options  | {[key: string]: any}  | 是    | 鉴权所需的可选项。       |
| callback | [AuthenticatorCallback](#authenticatorcallbackdeprecated) | 是    | 认证器回调，用于返回鉴权结果。 |

**示例：**

  ```js
  import featureAbility from '@ohos.ability.featureAbility';

  function onResultCallback(code, result) {
      console.log("resultCode: "  + code);
      console.log("result: "  + JSON.stringify(result));
  }

  function onRequestRedirectedCallback(request) {
      let abilityStartSetting = {want: request};
      featureAbility.startAbility(abilityStartSetting, (err)=>{
          console.log("startAbility err: " + JSON.stringify(err));
      });
  }

  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.authenticate("LiSi", "com.example.ohos.accountjsdemo", "getSocialData", {}, {
    onResult: onResultCallback,
    onRequestRedirected: onRequestRedirectedCallback
  });
  ```

### getAuthToken<sup>9+</sup>

getAuthToken(name: string, owner: string, authType: string, callback: AsyncCallback&lt;string&gt;): void

获取指定应用帐号和鉴权类型的Auth令牌，使用callback回调异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名      | 类型                          | 必填   | 说明          |
| -------- | --------------------------- | ---- | ----------- |
| name     | string                      | 是    | 应用帐号的名称。    |
| owner    | string                      | 是    | 应用帐号的所有者包名。 |
| authType | string                      | 是    | 鉴权类型。       |
| callback | AsyncCallback&lt;string&gt; | 是    | 查询结果的回调。    |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  try {
      appAccountManager.getAuthToken("LiSi", "com.example.ohos.accountjsdemo", "getSocialData", (err, data) => {
          console.log('getAuthToken err: ' + JSON.stringify(err));
          console.log('getAuthToken token: ' + data);
      });
  } catch (err) {
      console.log('getAuthToken err: ' + JSON.stringify(err));
  }
  ```

### getAuthToken<sup>9+</sup>

getAuthToken(name: string, owner: string, authType: string): Promise&lt;string&gt;

获取指定应用帐户和鉴权类型的Auth令牌，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名      | 类型     | 必填   | 说明          |
| -------- | ------ | ---- | ----------- |
| name     | string | 是    | 应用帐号的名称。    |
| owner    | string | 是    | 应用帐号的所有者包名。 |
| authType | string | 是    | 鉴权类型。       |

**返回值：**

| 类型                    | 说明                    |
| --------------------- | --------------------- |
| Promise&lt;string&gt; | Promise实例，用于获取异步返回结果。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  try {
      appAccountManager.getAuthToken("LiSi", "com.example.ohos.accountjsdemo", "getSocialData").then((data) => {
          console.log('getAuthToken token: ' + data);
      }).catch((err) => {
          console.log("getAuthToken err: "  + JSON.stringify(err));
      });
  } catch (err) {
      console.log("getAuthToken err: "  + JSON.stringify(err));
  }
  ```

### getOAuthToken<sup>(deprecated)</sup>

getOAuthToken(name: string, owner: string, authType: string, callback: AsyncCallback&lt;string&gt;): void

获取指定应用帐号和鉴权类型的OAuth令牌，使用callback回调异步返回结果。

> **说明：** 从API version 9开始废弃, 建议使用[getAuthToken](#getauthtoken9)替代。
>
> 从 API version 8开始支持。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名      | 类型                          | 必填   | 说明          |
| -------- | --------------------------- | ---- | ----------- |
| name     | string                      | 是    | 应用帐号的名称。    |
| owner    | string                      | 是    | 应用帐号的所有者包名。 |
| authType | string                      | 是    | 鉴权类型。       |
| callback | AsyncCallback&lt;string&gt; | 是    | 查询结果的回调。    |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getOAuthToken("LiSi", "com.example.ohos.accountjsdemo", "getSocialData", (err, data) => {
       console.log('getOAuthToken err: ' + JSON.stringify(err));
       console.log('getOAuthToken token: ' + data);
  });
  ```

### getOAuthToken<sup>(deprecated)</sup>

getOAuthToken(name: string, owner: string, authType: string): Promise&lt;string&gt;

获取指定应用帐户和鉴权类型的OAuth令牌，使用Promise方式异步返回结果。

> **说明：** 从API version 9开始废弃, 建议使用[getAuthToken](#getauthtoken9-1)替代。
>
> 从 API version 8开始支持。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名      | 类型     | 必填   | 说明          |
| -------- | ------ | ---- | ----------- |
| name     | string | 是    | 应用帐号的名称。    |
| owner    | string | 是    | 应用帐号的所有者包名。 |
| authType | string | 是    | 鉴权类型。       |

**返回值：**

| 类型                    | 说明                    |
| --------------------- | --------------------- |
| Promise&lt;string&gt; | Promise实例，用于获取异步返回结果。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getOAuthToken("LiSi", "com.example.ohos.accountjsdemo", "getSocialData").then((data) => {
       console.log('getOAuthToken token: ' + data);
  }).catch((err) => {
      console.log("getOAuthToken err: "  + JSON.stringify(err));
  });
  ```

### setAuthToken<sup>9+</sup>

setAuthToken(name: string, authType: string, token: string, callback: AsyncCallback&lt;void&gt;): void

设置指定应用帐号和鉴权类型的Auth令牌，使用callback回调异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名      | 类型                        | 必填   | 说明       |
| -------- | ------------------------- | ---- | -------- |
| name     | string                    | 是    | 应用帐号的名称。 |
| authType | string                    | 是    | 鉴权类型。    |
| token    | string                    | 是    | Auth令牌。 |
| callback | AsyncCallback&lt;void&gt; | 是    | 设置结果的回调。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  try {
      appAccountManager.setAuthToken("LiSi", "getSocialData", "xxxx", (err) => {
          console.log('setAuthToken err: ' + JSON.stringify(err));
      });
  } catch (err) {
      console.log('setAuthToken err: ' + JSON.stringify(err));
  }
  ```

### setAuthToken<sup>9+</sup>

setAuthToken(name: string, authType: string, token: string): Promise&lt;void&gt;

设置指定应用帐户和鉴权类型的Auth令牌，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名      | 类型     | 必填   | 说明       |
| -------- | ------ | ---- | -------- |
| name     | string | 是    | 应用帐号的名称。 |
| authType | string | 是    | 鉴权类型。    |
| token    | string | 是    | Auth令牌。 |

**返回值：**

| 类型                  | 说明                    |
| ------------------- | --------------------- |
| Promise&lt;void&gt; | Promise实例，用于获取异步返回结果。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  try {
      appAccountManager.setAuthToken("LiSi", "getSocialData", "xxxx").then(() => {
          console.log('setAuthToken successfully');
      }).catch((err) => {
          console.log('setAuthToken err: ' + JSON.stringify(err));
      });
  } catch (err) {
      console.log('setAuthToken err: ' + JSON.stringify(err));
  }
  ```

### setOAuthToken<sup>(deprecated)</sup>

setOAuthToken(name: string, authType: string, token: string, callback: AsyncCallback&lt;void&gt;): void

设置指定应用帐号和鉴权类型的OAuth令牌，使用callback回调异步返回结果。

> **说明：** 从API version 9开始废弃, 建议使用[setAuthToken](#setauthtoken9)替代。
>
> 从 API version 8开始支持。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名      | 类型                        | 必填   | 说明       |
| -------- | ------------------------- | ---- | -------- |
| name     | string                    | 是    | 应用帐号的名称。 |
| authType | string                    | 是    | 鉴权类型。    |
| token    | string                    | 是    | OAuth令牌。 |
| callback | AsyncCallback&lt;void&gt; | 是    | 设置结果的回调。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.setOAuthToken("LiSi", "getSocialData", "xxxx", (err) => {
      console.log('setOAuthToken err: ' + JSON.stringify(err));
  });
  ```

### setOAuthToken<sup>(deprecated)</sup>

setOAuthToken(name: string, authType: string, token: string): Promise&lt;void&gt;

设置指定应用帐户和鉴权类型的OAuth令牌，使用Promise方式异步返回结果。

> **说明：** 从API version 9开始废弃, 建议使用[setAuthToken](#setauthtoken9-1)替代。
>
> 从 API version 8开始支持。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名      | 类型     | 必填   | 说明       |
| -------- | ------ | ---- | -------- |
| name     | string | 是    | 应用帐号的名称。 |
| authType | string | 是    | 鉴权类型。    |
| token    | string | 是    | OAuth令牌。 |

**返回值：**

| 类型                  | 说明                    |
| ------------------- | --------------------- |
| Promise&lt;void&gt; | Promise实例，用于获取异步返回结果。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.setOAuthToken("LiSi", "getSocialData", "xxxx").then(() => {
      console.log('setOAuthToken successfully');
  }).catch((err) => {
      console.log('setOAuthToken err: ' + JSON.stringify(err));
  });
  ```

### deleteAuthToken<sup>9+</sup>

deleteAuthToken(name: string, owner: string, authType: string, token: string, callback: AsyncCallback&lt;void&gt;): void

删除指定应用帐户和鉴权类型的Auth令牌，使用callback回调异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名      | 类型                        | 必填   | 说明           |
| -------- | ------------------------- | ---- | ------------ |
| name     | string                    | 是    | 应用帐号的名称。     |
| owner    | string                    | 是    | 应用帐号的所有者包名。  |
| authType | string                    | 是    | 鉴权类型。        |
| token    | string                    | 是    | 要删除的Auth令牌。 |
| callback | AsyncCallback&lt;void&gt; | 是    | 删除结果的回调。     |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  try {
      appAccountManager.deleteAuthToken("LiSi", "com.example.ohos.accountjsdemo", "getSocialData", "xxxxx", (err) => {
          console.log('deleteAuthToken err: ' + JSON.stringify(err));
      });
  } catch (err) {
      console.log('deleteAuthToken err: ' + JSON.stringify(err));
  }
  ```

### deleteAuthToken<sup>9+</sup>

deleteAuthToken(name: string, owner: string, authType: string, token: string): Promise&lt;void&gt;

删除指定应用帐户和鉴权类型的Auth令牌，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名      | 类型     | 必填   | 说明           |
| -------- | ------ | ---- | ------------ |
| name     | string | 是    | 应用帐号的名称。     |
| owner    | string | 是    | 应用帐号的所有者包名。  |
| authType | string | 是    | 鉴权类型。        |
| token    | string | 是    | 要删除的Auth令牌。 |

**返回值：**

| 类型                  | 说明                    |
| ------------------- | --------------------- |
| Promise&lt;void&gt; | Promise实例，用于获取异步返回结果。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  try {
      appAccountManager.deleteAuthToken("LiSi", "com.example.ohos.accountjsdemo", "getSocialData", "xxxxx").then(() => {
          console.log('deleteAuthToken successfully');
      }).catch((err) => {
          console.log("deleteAuthToken err: "  + JSON.stringify(err));
      });
  } catch (err) {
      console.log("deleteAuthToken err: "  + JSON.stringify(err));
  }
  ```

### deleteOAuthToken<sup>(deprecated)</sup>

deleteOAuthToken(name: string, owner: string, authType: string, token: string, callback: AsyncCallback&lt;void&gt;): void

删除指定应用帐户和鉴权类型的OAuth令牌，使用callback回调异步返回结果。

> **说明：** 从API version 9开始废弃, 建议使用[deleteAuthToken](#deleteauthtoken9)替代。
>
> 从 API version 8开始支持。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名      | 类型                        | 必填   | 说明           |
| -------- | ------------------------- | ---- | ------------ |
| name     | string                    | 是    | 应用帐号的名称。     |
| owner    | string                    | 是    | 应用帐号的所有者包名。  |
| authType | string                    | 是    | 鉴权类型。        |
| token    | string                    | 是    | 要删除的OAuth令牌。 |
| callback | AsyncCallback&lt;void&gt; | 是    | 删除结果的回调。     |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.deleteOAuthToken("LiSi", "com.example.ohos.accountjsdemo", "getSocialData", "xxxxx", (err) => {
       console.log('deleteOAuthToken err: ' + JSON.stringify(err));
  });
  ```

### deleteOAuthToken<sup>(deprecated)</sup>

deleteOAuthToken(name: string, owner: string, authType: string, token: string): Promise&lt;void&gt;

删除指定应用帐户和鉴权类型的OAuth令牌，使用Promise方式异步返回结果。

> **说明：** 从API version 9开始废弃, 建议使用[setAuthToken](#setauthtoken9-1)替代。
>
> 从 API version 8开始支持。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名      | 类型     | 必填   | 说明           |
| -------- | ------ | ---- | ------------ |
| name     | string | 是    | 应用帐号的名称。     |
| owner    | string | 是    | 应用帐号的所有者包名。  |
| authType | string | 是    | 鉴权类型。        |
| token    | string | 是    | 要删除的OAuth令牌。 |

**返回值：**

| 类型                  | 说明                    |
| ------------------- | --------------------- |
| Promise&lt;void&gt; | Promise实例，用于获取异步返回结果。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.deleteOAuthToken("LiSi", "com.example.ohos.accountjsdemo", "getSocialData", "xxxxx").then(() => {
       console.log('deleteOAuthToken successfully');
  }).catch((err) => {
      console.log("deleteOAuthToken err: "  + JSON.stringify(err));
  });
  ```

### setAuthTokenVisibility<sup>9+</sup>

setAuthTokenVisibility(name: string, authType: string, bundleName: string, isVisible: boolean, callback: AsyncCallback&lt;void&gt;): void

设置指定鉴权类型的Auth令牌对特定应用的可见性，使用callback回调异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名        | 类型                        | 必填   | 说明                        |
| ---------- | ------------------------- | ---- | ------------------------- |
| name       | string                    | 是    | 应用帐号的名称。                  |
| authType   | string                    | 是    | 鉴权类型。                     |
| bundleName | string                    | 是    | 被设置可见性的应用包名。              |
| isVisible  | boolean                   | 是    | 是否可见。当设置成true可见，false不可见。 |
| callback   | AsyncCallback&lt;void&gt; | 是    | 设置结果的回调。                  |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  try {
      appAccountManager.setAuthTokenVisibility("LiSi", "getSocialData", "com.example.ohos.accountjsdemo", true, (err) => {
          console.log('setAuthTokenVisibility err: ' + JSON.stringify(err));
      });
  } catch (err) {
      console.log('setAuthTokenVisibility err: ' + JSON.stringify(err));
  }
  ```

### setAuthTokenVisibility<sup>9+</sup>

setAuthTokenVisibility(name: string, authType: string, bundleName: string, isVisible: boolean): Promise&lt;void&gt;

设置指定鉴权类型的OAuth令牌对特定应用的可见性，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名        | 类型      | 必填   | 说明           |
| ---------- | ------- | ---- | ------------ |
| name       | string  | 是    | 应用帐号的名称。     |
| authType   | string  | 是    | 鉴权类型。        |
| bundleName | string  | 是    | 被设置可见性的应用包名。 |
| isVisible  | boolean | 是    | 是否可见。        |

**返回值：**

| 类型                  | 说明                    |
| ------------------- | --------------------- |
| Promise&lt;void&gt; | Promise实例，用于获取异步返回结果。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  try {
      appAccountManager.setAuthTokenVisibility("LiSi", "getSocialData", "com.example.ohos.accountjsdemo", true).then(() => {
          console.log('setAuthTokenVisibility successfully');
      }).catch((err) => {
          console.log('setAuthTokenVisibility err: ' + JSON.stringify(err));
      });
  } catch (err) {
      console.log('setAuthTokenVisibility err: ' + JSON.stringify(err));
  }
  ```

### setOAuthTokenVisibility<sup>(deprecated)</sup>

setOAuthTokenVisibility(name: string, authType: string, bundleName: string, isVisible: boolean, callback: AsyncCallback&lt;void&gt;): void

设置指定鉴权类型的Auth令牌对特定应用的可见性，使用callback回调异步返回结果。

> **说明：** 从API version 9开始废弃, 建议使用[setAuthTokenVisibility](#setauthtokenvisibility9)替代。
>
> 从 API version 8开始支持。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名        | 类型                        | 必填   | 说明                        |
| ---------- | ------------------------- | ---- | ------------------------- |
| name       | string                    | 是    | 应用帐号的名称。                  |
| authType   | string                    | 是    | 鉴权类型。                     |
| bundleName | string                    | 是    | 被设置可见性的应用包名。              |
| isVisible  | boolean                   | 是    | 是否可见。当设置成true可见，false不可见。 |
| callback   | AsyncCallback&lt;void&gt; | 是    | 设置结果的回调。                  |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.setOAuthTokenVisibility("LiSi", "getSocialData", "com.example.ohos.accountjsdemo", true, (err) => {
       console.log('setOAuthTokenVisibility err: ' + JSON.stringify(err));
  });
  ```

### setOAuthTokenVisibility<sup>(deprecated)</sup>

setOAuthTokenVisibility(name: string, authType: string, bundleName: string, isVisible: boolean): Promise&lt;void&gt;

设置指定鉴权类型的OAuth令牌对特定应用的可见性，使用Promise方式异步返回结果。

> **说明：** 从API version 9开始废弃, 建议使用[setAuthTokenVisibility](#setauthtokenvisibility9-1)替代。
>
> 从 API version 8开始支持。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名        | 类型      | 必填   | 说明           |
| ---------- | ------- | ---- | ------------ |
| name       | string  | 是    | 应用帐号的名称。     |
| authType   | string  | 是    | 鉴权类型。        |
| bundleName | string  | 是    | 被设置可见性的应用包名。 |
| isVisible  | boolean | 是    | 是否可见。        |

**返回值：**

| 类型                  | 说明                    |
| ------------------- | --------------------- |
| Promise&lt;void&gt; | Promise实例，用于获取异步返回结果。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.setOAuthTokenVisibility("LiSi", "getSocialData", "com.example.ohos.accountjsdemo", true).then(() => {
      console.log('setOAuthTokenVisibility successfully');
  }).catch((err) => {
      console.log('setOAuthTokenVisibility err: ' + JSON.stringify(err));
  });
  ```

### checkAuthTokenVisibility<sup>9+</sup>

checkAuthTokenVisibility(name: string, authType: string, bundleName: string, callback: AsyncCallback&lt;boolean&gt;): void

检查指定鉴权类型的Auth令牌对特定应用的可见性，使用callback回调异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名        | 类型                           | 必填   | 说明          |
| ---------- | ---------------------------- | ---- | ----------- |
| name       | string                       | 是    | 应用帐号的名称。    |
| authType   | string                       | 是    | 鉴权类型。       |
| bundleName | string                       | 是    | 检查可见性的应用包名。 |
| callback   | AsyncCallback&lt;boolean&gt; | 是    | 检查结果的回调。    |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  try {
      appAccountManager.checkAuthTokenVisibility("LiSi", "getSocialData", "com.example.ohos.accountjsdemo", (err, data) => {
          console.log('checkAuthTokenVisibility err: ' + JSON.stringify(err));
          console.log('checkAuthTokenVisibility isVisible: ' + data);
      });
  } catch (err) {
      console.log('checkAuthTokenVisibility err: ' + JSON.stringify(err));
  }
  ```

### checkAuthTokenVisibility<sup>9+</sup>

checkAuthTokenVisibility(name: string, authType: string, bundleName: string): Promise&lt;boolean&gt;

检查指定鉴权类型的Auth令牌对特定应用的可见性，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名        | 类型     | 必填   | 说明            |
| ---------- | ------ | ---- | ------------- |
| name       | string | 是    | 应用帐号的名称。      |
| authType   | string | 是    | 鉴权类型。         |
| bundleName | string | 是    | 用于检查可见性的应用包名。 |

**返回值：**

| 类型                     | 说明                    |
| ---------------------- | --------------------- |
| Promise&lt;boolean&gt; | Promise实例，用于获取异步返回结果。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  try {
      appAccountManager.checkAuthTokenVisibility("LiSi", "getSocialData", "com.example.ohos.accountjsdemo").then((data) => {
          console.log('checkAuthTokenVisibility isVisible: ' + data);
      }).catch((err) => {
          console.log('checkAuthTokenVisibility err: ' + JSON.stringify(err));
      });
  } catch (err) {
      console.log('checkAuthTokenVisibility err: ' + JSON.stringify(err));
  }
  ```

### checkOAuthTokenVisibility<sup>(deprecated)</sup>

checkOAuthTokenVisibility(name: string, authType: string, bundleName: string, callback: AsyncCallback&lt;boolean&gt;): void

检查指定鉴权类型的OAuth令牌对特定应用的可见性，使用callback回调异步返回结果。

> **说明：** 从API version 9开始废弃, 建议使用[checkAuthTokenVisibility](#checkauthtokenvisibility9)替代。
>
> 从 API version 8开始支持。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名        | 类型                           | 必填   | 说明          |
| ---------- | ---------------------------- | ---- | ----------- |
| name       | string                       | 是    | 应用帐号的名称。    |
| authType   | string                       | 是    | 鉴权类型。       |
| bundleName | string                       | 是    | 检查可见性的应用包名。 |
| callback   | AsyncCallback&lt;boolean&gt; | 是    | 检查结果的回调。    |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.checkOAuthTokenVisibility("LiSi", "getSocialData", "com.example.ohos.accountjsdemo", (err, data) => {
      console.log('checkOAuthTokenVisibility err: ' + JSON.stringify(err));
      console.log('checkOAuthTokenVisibility isVisible: ' + data);
  });
  ```


### checkOAuthTokenVisibility<sup>(deprecated)</sup>

checkOAuthTokenVisibility(name: string, authType: string, bundleName: string): Promise&lt;boolean&gt;

检查指定鉴权类型的OAuth令牌对特定应用的可见性，使用Promise方式异步返回结果。

> **说明：** 从API version 9开始废弃, 建议使用[checkAuthTokenVisibility](#checkauthtokenvisibility9-1)替代。
>
> 从 API version 8开始支持。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名        | 类型     | 必填   | 说明            |
| ---------- | ------ | ---- | ------------- |
| name       | string | 是    | 应用帐号的名称。      |
| authType   | string | 是    | 鉴权类型。         |
| bundleName | string | 是    | 用于检查可见性的应用包名。 |

**返回值：**

| 类型                     | 说明                    |
| ---------------------- | --------------------- |
| Promise&lt;boolean&gt; | Promise实例，用于获取异步返回结果。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.checkOAuthTokenVisibility("LiSi", "getSocialData", "com.example.ohos.accountjsdemo").then((data) => {
      console.log('checkOAuthTokenVisibility isVisible: ' + data);
  }).catch((err) => {
      console.log('checkOAuthTokenVisibility err: ' + JSON.stringify(err));
  });
  ```

### getAllAuthTokens<sup>9+</sup>

getAllAuthTokens(name: string, owner: string, callback: AsyncCallback&lt;Array&lt;OAuthTokenInfo&gt;&gt;): void

获取指定应用对调用方全部可见的Auth令牌，使用callback回调异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名      | 类型                                       | 必填   | 说明          |
| -------- | ---------------------------------------- | ---- | ----------- |
| name     | string                                   | 是    | 应用帐号的名称。    |
| owner    | string                                   | 是    | 应用帐号的所有者包名。 |
| callback | AsyncCallback&lt;Array&lt; [AuthTokenInfo](#authtokeninfo9)&gt;&gt; | 是    | 查询结果的回调。    |

**示例：** 

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  try {
      appAccountManager.getAllAuthTokens("LiSi", "com.example.ohos.accountjsdemo", (err, data) => {
          console.log("getAllAuthTokens err: "  + JSON.stringify(err));
          console.log('getAllAuthTokens data: ' + JSON.stringify(data));
      });
  } catch (err) {
      console.log("getAllAuthTokens err: "  + JSON.stringify(err));
  }
  ```

### getAllAuthTokens<sup>9+</sup>

getAllAuthTokens(name: string, owner: string): Promise&lt;Array&lt;AuthTokenInfo&gt;&gt;

获取指定应用帐户对调用方可见的全部Auth令牌，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名   | 类型     | 必填   | 说明          |
| ----- | ------ | ---- | ----------- |
| name  | string | 是    | 应用帐号的名称。    |
| owner | string | 是    | 应用帐号的所有者包名。 |

**返回值：**

| 类型                                       | 说明                    |
| ---------------------------------------- | --------------------- |
| Promise&lt;Array&lt; [AuthTokenInfo](#authtokeninfo9)&gt;&gt; | Promise实例，用于获取异步返回结果。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  try {
      appAccountManager.getAllAuthTokens("LiSi", "com.example.ohos.accountjsdemo").then((data) => {
          console.log('getAllAuthTokens data: ' + JSON.stringify(data));
      }).catch((err) => {
          console.log("getAllAuthTokens err: "  + JSON.stringify(err));
      });
  } catch (err) {
      console.log("getAllAuthTokens err: "  + JSON.stringify(err));
  }
  ```

### getAllOAuthTokens<sup>(deprecated)</sup>

getAllOAuthTokens(name: string, owner: string, callback: AsyncCallback&lt;Array&lt;OAuthTokenInfo&gt;&gt;): void

获取指定应用对调用方全部可见的OAuth令牌，使用callback回调异步返回结果。

> **说明：** 从API version 9开始废弃, 建议使用[getAllAuthTokens](#getallauthtokens9)替代。
>
> 从 API version 8开始支持。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名      | 类型                                       | 必填   | 说明          |
| -------- | ---------------------------------------- | ---- | ----------- |
| name     | string                                   | 是    | 应用帐号的名称。    |
| owner    | string                                   | 是    | 应用帐号的所有者包名。 |
| callback | AsyncCallback&lt;Array&lt; [OAuthTokenInfo](#oauthtokeninfodeprecated)&gt;&gt; | 是    | 查询结果的回调。    |

**示例：** 

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getAllOAuthTokens("LiSi", "com.example.ohos.accountjsdemo", (err, data) => {
      console.log("getAllOAuthTokens err: "  + JSON.stringify(err));
      console.log('getAllOAuthTokens data: ' + JSON.stringify(data));
  });
  ```

### getAllOAuthTokens<sup>(deprecated)</sup>

getAllOAuthTokens(name: string, owner: string): Promise&lt;Array&lt;OAuthTokenInfo&gt;&gt;

获取指定应用帐户对调用方可见的全部OAuth令牌，使用Promise方式异步返回结果。

> **说明：** 从API version 9开始废弃, 建议使用[getAllAuthTokens](#getallauthtokens9-1)替代。
>
> 从 API version 8开始支持。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名   | 类型     | 必填   | 说明          |
| ----- | ------ | ---- | ----------- |
| name  | string | 是    | 应用帐号的名称。    |
| owner | string | 是    | 应用帐号的所有者包名。 |

**返回值：**

| 类型                                       | 说明                    |
| ---------------------------------------- | --------------------- |
| Promise&lt;Array&lt; [OAuthTokenInfo](#oauthtokeninfodeprecated)&gt;&gt; | Promise实例，用于获取异步返回结果。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getAllOAuthTokens("LiSi", "com.example.ohos.accountjsdemo").then((data) => {
      console.log('getAllOAuthTokens data: ' + JSON.stringify(data));
  }).catch((err) => {
      console.log("getAllOAuthTokens err: "  + JSON.stringify(err));
  });
  ```

### getAuthList<sup>9+</sup>

getAuthList(name: string, authType: string, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

获取指定应用帐户和鉴权类型的Auth令牌的授权列表，使用callback回调异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                      |
| -------- | ---------------------------------------- | ---- | ----------------------- |
| name     | string                                   | 是    | 应用帐号的名称。                |
| authType | string                                   | 是    | 应用帐号的鉴权类型的Auth令牌的授权列表。 |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt; | 是    | 查询结果的回调。                |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  try {
      appAccountManager.getAuthList("com.example.ohos.accountjsdemo", "getSocialData", (err, data) => {
          console.log('getAuthList err: ' + JSON.stringify(err));
          console.log('getAuthList data: ' + JSON.stringify(data));
      });
  } catch (err) {
      console.log('getAuthList err: ' + JSON.stringify(err));
  }
  ```

### getAuthList<sup>9+</sup>

getAuthList(name: string, authType: string): Promise&lt;Array&lt;string&gt;&gt;

获取指定应用帐户和鉴权类型的Auth令牌的授权列表，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名      | 类型     | 必填   | 说明                      |
| -------- | ------ | ---- | ----------------------- |
| name     | string | 是    | 应用帐号的名称。                |
| authType | string | 是    | 应用帐号的鉴权类型的Auth令牌的授权列表。 |

**返回值：**

| 类型                                 | 说明                    |
| ---------------------------------- | --------------------- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise实例，用于获取异步返回结果。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  try {
      appAccountManager.getAuthList("com.example.ohos.accountjsdemo", "getSocialData").then((data) => {
          console.log('getAuthList data: ' + JSON.stringify(data));
      }).catch((err) => {
          console.log("getAuthList err: "  + JSON.stringify(err));
      });
  } catch (err) {
    console.log("getAuthList err: "  + JSON.stringify(err));
  }
  ```

### getOAuthList<sup>(deprecated)</sup>

getOAuthList(name: string, authType: string, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

获取指定应用帐户和鉴权类型的OAuth令牌的授权列表，使用callback回调异步返回结果。

> **说明：** 从API version 9开始废弃, 建议使用[getAuthList](#getauthlist9)替代。
>
> 从 API version 8开始支持。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                      |
| -------- | ---------------------------------------- | ---- | ----------------------- |
| name     | string                                   | 是    | 应用帐号的名称。                |
| authType | string                                   | 是    | 应用帐号的鉴权类型的OAuth令牌的授权列表。 |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt; | 是    | 查询结果的回调。                |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getOAuthList("com.example.ohos.accountjsdemo", "getSocialData", (err, data) => {
       console.log('getOAuthList err: ' + JSON.stringify(err));
       console.log('getOAuthList data: ' + JSON.stringify(data));
  });
  ```

### getOAuthList<sup>(deprecated)</sup>

getOAuthList(name: string, authType: string): Promise&lt;Array&lt;string&gt;&gt;

获取指定应用帐户和鉴权类型的OAuth令牌的授权列表，使用Promise方式异步返回结果。

> **说明：** 从API version 9开始废弃, 建议使用[getAuthList](#getauthlist9-1)替代。
>
> 从 API version 8开始支持。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名      | 类型     | 必填   | 说明                      |
| -------- | ------ | ---- | ----------------------- |
| name     | string | 是    | 应用帐号的名称。                |
| authType | string | 是    | 应用帐号的鉴权类型的OAuth令牌的授权列表。 |

**返回值：**

| 类型                                 | 说明                    |
| ---------------------------------- | --------------------- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise实例，用于获取异步返回结果。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getOAuthList("com.example.ohos.accountjsdemo", "getSocialData").then((data) => {
       console.log('getOAuthList data: ' + JSON.stringify(data));
  }).catch((err) => {
      console.log("getOAuthList err: "  + JSON.stringify(err));
  });
  ```

### getAuthCallback<sup>9+</sup>

getAuthCallback(sessionId: string, callback: AsyncCallback&lt;AuthCallback&gt;): void

获取鉴权会话的认证器回调，使用callback回调异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名       | 类型                                       | 必填   | 说明       |
| --------- | ---------------------------------------- | ---- | -------- |
| sessionId | string                                   | 是    | 鉴权会话的标识。 |
| callback  | AsyncCallback&lt;[AuthCallback](#authcallback9)&gt; | 是    | 查询结果的回调。 |

**示例：**

  ```js
  import featureAbility from '@ohos.ability.featureAbility';
  const appAccountManager = account_appAccount.createAppAccountManager();
  featureAbility.getWant((err, want) => {
      var sessionId = want.parameters[account_appAccount.Constants.KEY_SESSION_ID];
      try {
          appAccountManager.getAuthCallback(sessionId, (err, callback) => {
              if (err.code != account_appAccount.ResultCode.SUCCESS) {
                  console.log("getAuthCallback err: "  + JSON.stringify(err));
                  return;
              }
              var result = {[account_appAccount.Constants.KEY_NAME]: "LiSi",
                            [account_appAccount.Constants.KEY_OWNER]: "com.example.ohos.accountjsdemo",
                            [account_appAccount.Constants.KEY_AUTH_TYPE]: "getSocialData",
                            [account_appAccount.Constants.KEY_TOKEN]: "xxxxxx"};
              callback.onResult(account_appAccount.ResultCode.SUCCESS, result);
          });
      } catch (err) {
          console.log("getAuthCallback err: "  + JSON.stringify(err));
      }
  });
  ```

### getAuthCallback<sup>9+</sup>

getAuthCallback(sessionId: string): Promise&lt;AuthCallback&gt;

获取鉴权会话的认证器回调，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名       | 类型     | 必填   | 说明       |
| --------- | ------ | ---- | -------- |
| sessionId | string | 是    | 鉴权会话的标识。 |

**返回值：**

| 类型                                   | 说明                    |
| ------------------------------------ | --------------------- |
| Promise&lt;[AuthCallback](#authcallback9)&gt; | Promise实例，用于获取异步返回结果。 |

**示例：**

  ```js
  import featureAbility from '@ohos.ability.featureAbility';

  const appAccountManager = account_appAccount.createAppAccountManager();
  featureAbility.getWant().then((want) => {
      var sessionId = want.parameters[account_appAccount.Constants.KEY_SESSION_ID];
      try {
          appAccountManager.getAuthCallback(sessionId).then((callback) => {
          var result = {[account_appAccount.Constants.KEY_NAME]: "LiSi",
                        [account_appAccount.Constants.KEY_OWNER]: "com.example.ohos.accountjsdemo",
                        [account_appAccount.Constants.KEY_AUTH_TYPE]: "getSocialData",
                        [account_appAccount.Constants.KEY_TOKEN]: "xxxxxx"};
          callback.onResult(account_appAccount.ResultCode.SUCCESS, result);
          }).catch((err) => {
              console.log("getAuthCallback err: "  + JSON.stringify(err));
          });
      }
  }).catch((err) => {
      console.log("getWant err: "  + JSON.stringify(err));
  });
  ```

### getAuthenticatorCallback<sup>(deprecated)</sup>

getAuthenticatorCallback(sessionId: string, callback: AsyncCallback&lt;AuthenticatorCallback&gt;): void

获取鉴权会话的认证器回调，使用callback回调异步返回结果。

> **说明：** 从API version 9开始废弃, 建议使用[getAuthCallback](#getauthcallback9)替代。
>
> 从 API version 8开始支持。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名       | 类型                                       | 必填   | 说明       |
| --------- | ---------------------------------------- | ---- | -------- |
| sessionId | string                                   | 是    | 鉴权会话的标识。 |
| callback  | AsyncCallback&lt;[AuthenticatorCallback](#authenticatorcallbackdeprecated)&gt; | 是    | 查询结果的回调。 |

**示例：**

  ```js
  import featureAbility from '@ohos.ability.featureAbility';
  const appAccountManager = account_appAccount.createAppAccountManager();
  featureAbility.getWant((err, want) => {
    var sessionId = want.parameters[account_appAccount.Constants.KEY_SESSION_ID];
    appAccountManager.getAuthenticatorCallback(sessionId, (err, callback) => {
        if (err.code != account_appAccount.ResultCode.SUCCESS) {
            console.log("getAuthenticatorCallback err: "  + JSON.stringify(err));
            return;
        }
        var result = {[account_appAccount.Constants.KEY_NAME]: "LiSi",
                      [account_appAccount.Constants.KEY_OWNER]: "com.example.ohos.accountjsdemo",
                      [account_appAccount.Constants.KEY_AUTH_TYPE]: "getSocialData",
                      [account_appAccount.Constants.KEY_TOKEN]: "xxxxxx"};
        callback.onResult(account_appAccount.ResultCode.SUCCESS, result);
    });
  });
  ```

### getAuthenticatorCallback<sup>(deprecated)</sup>

getAuthenticatorCallback(sessionId: string): Promise&lt;AuthenticatorCallback&gt;

获取鉴权会话的认证器回调，使用Promise方式异步返回结果。

> **说明：** 从API version 9开始废弃, 建议使用[getAuthCallback](#getauthcallback9-1)替代。
>
> 从 API version 8开始支持。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名       | 类型     | 必填   | 说明       |
| --------- | ------ | ---- | -------- |
| sessionId | string | 是    | 鉴权会话的标识。 |

**返回值：**

| 类型                                   | 说明                    |
| ------------------------------------ | --------------------- |
| Promise&lt;[AuthenticatorCallback](#authenticatorcallbackdeprecated)&gt; | Promise实例，用于获取异步返回结果。 |

**示例：**

  ```js
  import featureAbility from '@ohos.ability.featureAbility';

  const appAccountManager = account_appAccount.createAppAccountManager();
  featureAbility.getWant().then((want) => {
      var sessionId = want.parameters[account_appAccount.Constants.KEY_SESSION_ID];
      appAccountManager.getAuthenticatorCallback(sessionId).then((callback) => {
          var result = {[account_appAccount.Constants.KEY_NAME]: "LiSi",
                        [account_appAccount.Constants.KEY_OWNER]: "com.example.ohos.accountjsdemo",
                        [account_appAccount.Constants.KEY_AUTH_TYPE]: "getSocialData",
                        [account_appAccount.Constants.KEY_TOKEN]: "xxxxxx"};
          callback.onResult(account_appAccount.ResultCode.SUCCESS, result);
      }).catch((err) => {
          console.log("getAuthenticatorCallback err: "  + JSON.stringify(err));
      });
  }).catch((err) => {
      console.log("getWant err: "  + JSON.stringify(err));
  });
  ```

### queryAuthenticatorInfo<sup>9+</sup>

queryAuthenticatorInfo(owner: string, callback: AsyncCallback&lt;AuthenticatorInfo&gt;): void

获取指定应用帐号的认证器信息，使用callback回调异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名      | 类型                                     | 必填   | 说明          |
| -------- | -------------------------------------- | ---- | ----------- |
| owner    | string                                 | 是    | 应用帐号的所有者包名。 |
| callback | AsyncCallback&lt;[AuthenticatorInfo](#authenticatorinfo8)&gt; | 是    | 查询结果的回调。    |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  try {
      appAccountManager.queryAuthenticatorInfo("com.example.ohos.accountjsdemo", (err, data) => {
          console.log("queryAuthenticatorInfo err: "  + JSON.stringify(err));
          console.log('queryAuthenticatorInfo data: ' + JSON.stringify(data));
      });
  } catch (err) {
      console.log("queryAuthenticatorInfo err: "  + JSON.stringify(err));
  }
  ```

### queryAuthenticatorInfo<sup>9+</sup>

queryAuthenticatorInfo(owner: string): Promise&lt;AuthenticatorInfo&gt;

获取指定应用帐户的认证器信息，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名   | 类型     | 必填   | 说明          |
| ----- | ------ | ---- | ----------- |
| owner | string | 是    | 应用帐号的所有者包名。 |

**返回值：**

| 类型                               | 说明                    |
| -------------------------------- | --------------------- |
| Promise&lt;[AuthenticatorInfo](#authenticatorinfo8)&gt; | Promise实例，用于获取异步返回结果。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  try {
      appAccountManager.queryAuthenticatorInfo("com.example.ohos.accountjsdemo").then((data) => { 
          console.log('queryAuthenticatorInfo: ' + JSON.stringify(data));
      }).catch((err) => {
          console.log("queryAuthenticatorInfo err: "  + JSON.stringify(err));
      });
  } catch (err) {
      console.log("queryAuthenticatorInfo err: "  + JSON.stringify(err));
  }
  ```

### getAuthenticatorInfo<sup>(deprecated)</sup>

getAuthenticatorInfo(owner: string, callback: AsyncCallback&lt;AuthenticatorInfo&gt;): void

获取指定应用帐号的认证器信息，使用callback回调异步返回结果。

> **说明：** 从API version 9开始废弃, 建议使用[queryAuthenticatorInfo](#queryauthenticatorinfo9)替代。
>
> 从 API version 8开始支持。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名      | 类型                                     | 必填   | 说明          |
| -------- | -------------------------------------- | ---- | ----------- |
| owner    | string                                 | 是    | 应用帐号的所有者包名。 |
| callback | AsyncCallback&lt;[AuthenticatorInfo](#authenticatorinfo8)&gt; | 是    | 查询结果的回调。    |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getAuthenticatorInfo("com.example.ohos.accountjsdemo", (err, data) => {
      console.log("getAuthenticatorInfo err: "  + JSON.stringify(err));
      console.log('getAuthenticatorInfo data: ' + JSON.stringify(data));
  });
  ```

### getAuthenticatorInfo<sup>(deprecated)</sup>

getAuthenticatorInfo(owner: string): Promise&lt;AuthenticatorInfo&gt;

获取指定应用帐户的认证器信息，使用Promise方式异步返回结果。

> **说明：** 从API version 9开始废弃, 建议使用[queryAuthenticatorInfo](#queryauthenticatorinfo9-1)替代。
>
> 从 API version 8开始支持。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名   | 类型     | 必填   | 说明          |
| ----- | ------ | ---- | ----------- |
| owner | string | 是    | 应用帐号的所有者包名。 |

**返回值：**

| 类型                               | 说明                    |
| -------------------------------- | --------------------- |
| Promise&lt;[AuthenticatorInfo](#authenticatorinfo8)&gt; | Promise实例，用于获取异步返回结果。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getAuthenticatorInfo("com.example.ohos.accountjsdemo").then((data) => { 
       console.log('getAuthenticatorInfo: ' + JSON.stringify(data));
  }).catch((err) => {
      console.log("getAuthenticatorInfo err: "  + JSON.stringify(err));
  });
  ```

### checkAccountLabels<sup>9+</sup>

checkAccountLabels(name: string, owner: string, labels: Array&lt;string&gt;, callback: AsyncCallback&lt;boolean&gt;): void;

检查指定帐户是否具有特定的标签集合，使用callback回调异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名         | 类型                       | 必填  | 说明             |
| -------------- | ------------------------- | ----- | --------------- |
| name           | string                    | 是    | 应用帐户的名称。  |
| owner          | string                    | 是    | 应用帐户的所有者。|
| labels         | Array&lt;string&gt;       | 是    | 标签数组。       |
| callback       | AsyncCallback&lt;boolean&gt; | 是    | 检查结果的回调。  |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  var labels = ["student"];
  try {
      appAccountManager.checkAccountLabels("zhangsan", "com.example.ohos.accountjsdemo", labels, (err, data) => {
          console.log('checkAccountLabels: ' + JSON.stringify(data));
          console.log("checkAccountLabels err: "  + JSON.stringify(err));
      });
  } catch (err) {
      console.log("checkAccountLabels err: "  + JSON.stringify(err));
  }
  ```

### checkAccountLabels<sup>9+</sup>

checkAccountLabels(name: string, owner: string, labels: Array&lt;string&gt;): Promise&lt;boolean&gt;

检查指定帐户是否具有特定的标签集合，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名         | 类型                       | 必填  | 说明             |
| -------------- | ------------------------- | ----- | --------------- |
| name           | string                    | 是    | 应用帐户的名称。  |
| owner          | string                    | 是    | 应用帐户的所有者。|
| labels         | Array&lt;string&gt;       | 是    | 标签数组。       |

**返回值：**

| 类型                | 说明                              |
| ------------------- | -------------------------------- |
| Promise&lt;boolean&gt; | Promise实例，用于获取异步返回结果。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  var labels = ["student"];
  try {
      appAccountManager.checkAccountLabels("zhangsan", "com.example.ohos.accountjsdemo", labels).then((data) => {
          console.log('checkAccountLabels: ' + JSON.stringify(data));
      }).catch((err) => {
          console.log("checkAccountLabels err: "  + JSON.stringify(err));
      });
  } catch (err) {
      console.log("checkAccountLabels err: "  + JSON.stringify(err));
  }
  ```

### deleteAccountCredential<sup>9+</sup>

deleteAccountCredential(name: string, credentialType: string, callback: AsyncCallback&lt;void&gt;): void

删除指定应用帐户的指定类型的凭据信息，使用callback回调异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名         | 类型                       | 必填  | 说明            |
| -------------- | ------------------------- | ----- | -------------- |
| name           | string                    | 是    | 应用帐户的名称。 |
| credentialType | string                    | 是    | 凭据类型。      |
| callback       | AsyncCallback&lt;void&gt; | 是    | 删除结果的回调。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  try {
      appAccountManager.deleteAccountCredential("zhangsan", "pin", (err, data) => {
          console.log('deleteAccountCredential: ' + JSON.stringify(data));
          console.log("deleteAccountCredential err: "  + JSON.stringify(err));
      });
  } catch (err) {
      console.log("deleteAccountCredential err: "  + JSON.stringify(err));
  }
  ```

### deleteAccountCredential<sup>9+</sup>

deleteAccountCredential(name: string, credentialType: string): Promise&lt;void&gt;

删除指定应用帐户的指定类型的凭据信息，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名         | 类型   | 必填   | 说明            |
| -------------- | ------ | ----- | --------------- |
| name           | string | 是    | 应用帐户的名称。 |
| credentialType | string | 是    | 凭据类型。       |

**返回值：**

| 类型                | 说明                              |
| ------------------- | -------------------------------- |
| Promise&lt;void&gt; | Promise实例，用于获取异步返回结果。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  try {
      appAccountManager.deleteAccountCredential("zhangsan", "pin").then((data) => {
          console.log('deleteAccountCredential: ' + JSON.stringify(data));
      }).catch((err) => {
          console.log("deleteAccountCredential err: "  + JSON.stringify(err));
      });
  } catch (err) {
      console.log("deleteAccountCredential err: "  + JSON.stringify(err));
  }
  ```

### selectAccountsByOptions<sup>9+</sup>

selectAccountsByOptions(options: SelectAccountsOptions, callback: AsyncCallback&lt;Array&lt;AppAccountInfo&gt;&gt;);

根据选项选择请求方可访问的帐号列表，使用callback回调异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名         | 类型                                 | 必填  | 说明             |
| -------------- | ----------------------------------- | ----- | --------------- |
| options        | SelectAccountsOptions               | 是    | 选择帐户的选项。  |
| callback       | AsyncCallback&lt;[AppAccountInfo](#appaccountinfo)&gt; | 是    | 选择结果的回调。  |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  var options = {
    allowedOwners: ["com.example.ohos.accountjsdemo"]
  };
  try {
      appAccountManager.selectAccountsByOptions(options, (err, data) => {
          console.log('selectAccountsByOptions: ' + JSON.stringify(data));
          console.log("selectAccountsByOptions err: "  + JSON.stringify(err));
      });
  } catch (err) {
      console.log("selectAccountsByOptions err: "  + JSON.stringify(err));
  }
  ```

### selectAccountsByOptions<sup>9+</sup>

selectAccountsByOptions(options: SelectAccountsOptions): Promise&lt;Array&lt;AppAccountInfo&gt;&gt;

根据选项选择请求方可访问的帐户列表，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名         | 类型                       | 必填  | 说明             |
| -------------- | ------------------------- | ----- | --------------- |
| options        | [SelectAccountsOptions](#selectaccountsoptions9)     | 是    | 选择帐户的选项。  |

**返回值：**

| 类型                | 说明                              |
| ------------------- | -------------------------------- |
| Promise&lt;[AppAccountInfo](#appaccountinfo)&gt; | Promise实例，用于获取异步返回结果。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  var options = {
    allowedOwners: ["com.example.ohos.accountjsdemo"]
  };
  try {
      appAccountManager.selectAccountsByOptions(options).then((data) => {
          console.log('selectAccountsByOptions: ' + JSON.stringify(data));
      }).catch((err) => {
          console.log("selectAccountsByOptions err: "  + JSON.stringify(err));
      });
  } catch (err) {
      console.log("selectAccountsByOptions err: "  + JSON.stringify(err));
  }
  ```

### verifyCredential<sup>9+</sup>

verifyCredential(name: string, owner: string, callback: AuthenticatorCallback): void;

验证用户凭据，使用callback回调异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名    | 类型                  | 必填  | 说明                     |
| -------- | --------------------- | ----- | ----------------------- |
| name     | string                | 是    | 应用帐户的名称。          |
| owner    | string                | 是    | 应用帐户的所有者。        |
| callback | [AuthenticatorCallback](#authenticatorcallbackdeprecated) | 是    | 认证器回调，返回验证结果。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  try {
      appAccountManager.verifyCredential("zhangsan", "com.example.ohos.accountjsdemo", {
          onResult: (resultCode, result) => {
              console.log("verifyCredential onResult, resultCode:" + JSON.stringify(resultCode));
              console.log("verifyCredential onResult, result:" + JSON.stringify(result));
          },
          onRequestRedirected: (request) => {
              console.log("verifyCredential onRequestRedirected, request:" + JSON.stringify(request));
          }
      });
  } catch (err) {
      console.log("verifyCredential err: "  + JSON.stringify(err));
  }
  ```

### verifyCredential<sup>9+</sup>

verifyCredential(name: string, owner: string, options: VerifyCredentialOptions, callback: AuthenticatorCallback): void;

验证用户凭据，使用callback回调异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名    | 类型                    | 必填  | 说明                     |
| -------- | ----------------------- | ----- | ----------------------- |
| name     | string                  | 是    | 应用帐户的名称。          |
| owner    | string                  | 是    | 应用帐户的所有者。        |
| options  | [VerifyCredentialOptions](#verifycredentialoptions9) | 是    | 验证凭据的选项。          |
| callback | [AuthenticatorCallback](#authenticatorcallbackdeprecated)   | 是    | 认证器回调，返回验证结果。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  var options = {
    credentialType: "pin",
    credential: "123456"
  };
  try {
      appAccountManager.verifyCredential("zhangsan", "com.example.ohos.accountjsdemo", options, {
          onResult: (resultCode, result) => {
              console.log("verifyCredential onResult, resultCode:" + JSON.stringify(resultCode));
              console.log("verifyCredential onResult, result:" + JSON.stringify(result));
          },
          onRequestRedirected: (request) => {
              console.log("verifyCredential onRequestRedirected, request:" + JSON.stringify(request));
        }
      });
  } catch (err) {
    console.log("verifyCredential err: "  + JSON.stringify(err));
  }
  ```

### setAuthenticatorProperties<sup>9+</sup>

setAuthenticatorProperties(owner: string, callback: AuthCallback): void;

设置认证器属性，使用callback回调异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名    | 类型                  | 必填  | 说明                     |
| -------- | --------------------- | ----- | ----------------------- |
| owner    | string                | 是    | 认证器的所有者。          |
| callback | [AuthCallback](#authcallback9) | 是    | 认证器回调，返回设置结果。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  try {
      appAccountManager.setAuthenticatorProperties("com.example.ohos.accountjsdemo", {
          onResult: (resultCode, result) => {
              console.log("setAuthenticatorProperties onResult, resultCode:" + JSON.stringify(resultCode));
              console.log("setAuthenticatorProperties onResult, result:" + JSON.stringify(result));
          },
          onRequestRedirected: (request) => {
              console.log("setAuthenticatorProperties onRequestRedirected, request:" + JSON.stringify(request));
          }
      });
  } catch (err) {
      console.log("setAuthenticatorProperties err: "  + JSON.stringify(err));
  }
  ```

### setAuthenticatorProperties<sup>9+</sup>

setAuthenticatorProperties(owner: string, options: SetPropertiesOptions, callback: AuthCallback): void;

设置认证器属性，使用callback回调异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名    | 类型                  | 必填  | 说明                     |
| -------- | --------------------- | ----- | ----------------------- |
| owner    | string                | 是    | 认证器的所有者。          |
| options  | [SetPropertiesOptions](#setpropertiesoptions9)  | 是    | 设置属性的选项。          |
| callback | [AuthCallback](#authcallback9) | 是    | 认证器回调，返回设置结果。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  var options = {
    properties: {"prop1": "value1"}
  };
  try {
          appAccountManager.setAuthenticatorProperties("com.example.ohos.accountjsdemo", options, {
              onResult: (resultCode, result) => {
                  console.log("setAuthenticatorProperties onResult, resultCode:" + JSON.stringify(resultCode));
                  console.log("setAuthenticatorProperties onResult, result:" + JSON.stringify(result));
              },
              onRequestRedirected: (request) => {
                  console.log("setAuthenticatorProperties onRequestRedirected, request:" + JSON.stringify(request));
              }
          });
  } catch (err) {
      console.log("setAuthenticatorProperties err: "  + JSON.stringify(err));
  } 

  ```

## AppAccountInfo

表示应用帐号信息。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Account.AppAccount。

| 参数名   | 类型     | 必填   | 说明          |
| ----- | ------ | ---- | ----------- |
| owner | string | 是    | 应用帐号的所有者包名。 |
| name  | string | 是    | 应用帐号的名称。    |

## AuthTokenInfo<sup>9+</sup>

表示Auth令牌信息。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Account.AppAccount。

| 参数名               | 类型            | 必填  | 说明              |
| -------------------- | -------------- | ----- | ---------------- |
| authType<sup>9+</sup>             | string         | 是    | 令牌的鉴权类型。   |
| token<sup>9+</sup>                | string         | 是    | 令牌的取值。       |
| account<sup>9+</sup> | [AppAccountInfo](#appaccountinfo) | 否    | 令牌所属的帐号信息。|

## OAuthTokenInfo<sup>(deprecated)</sup>

表示OAuth令牌信息。

> **说明：** 从API version 9开始废弃, 建议使用[AuthTokenInfo](#authtokeninfo9)替代。
>
> 从 API version 8开始支持。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Account.AppAccount。

| 参数名               | 类型            | 必填  | 说明              |
| -------------------- | -------------- | ----- | ---------------- |
| authType             | string         | 是    | 令牌的鉴权类型。   |
| token                | string         | 是    | 令牌的取值。       |
| account<sup>9+</sup> | [AppAccountInfo](#appaccountinfo) | 否    | 令牌所属的帐号信息。|

## AuthenticatorInfo<sup>8+</sup>

表示OAuth认证器信息。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Account.AppAccount。

| 参数名     | 类型     | 必填   | 说明         |
| ------- | ------ | ---- | ---------- |
| owner   | string | 是    | 认证器的所有者包名。 |
| iconId  | number | 是    | 认证器的图标标识。  |
| labelId | number | 是    | 认证器的标签标识。  |

## AuthResult<sup>9+</sup>

表示认证结果信息。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Account.AppAccount。

| 参数名     | 类型     | 必填   | 说明         |
| ------- | ------ | ---- | ---------- |
| account   | [AppAccountInfo](#appaccountinfo) | 否    | 令牌所属的帐号信息。 |
| tokenInfo  | [AuthTokenInfo](#authtokeninfo9) | 否    | 令牌信息。  |

## AuthOptions<sup>9+</sup>

表示认证的选项。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Account.AppAccount。

| 参数名     | 类型     | 必填   | 说明         |
| ------- | ------ | ---- | ---------- |
| parameters   | {[key:string]: Object} | 否    | 自定义参数对象。 |

## CreateAccountOptions<sup>9+</sup>

表示创建账号的选项。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Account.AppAccount。

| 参数名     | 类型     | 必填   | 说明         |
| ------- | ------ | ---- | ---------- |
| customData   | {[key:string]: Object} | 否    | 自定义数据。 |

## CreateAccountImplicitlyOptions<sup>9+</sup>

表示隐式创建账号的选项。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Account.AppAccount。

| 参数名     | 类型     | 必填   | 说明         |
| ------- | ------ | ---- | ---------- |
| requiredLabels   | {[key:string]: Object} | 否    | 必须的标签。 |
| authType   | string | 否    | 鉴权类型。 |
| parameters   | {[key:string]: Object} | 否    | 自定义参数对象。 |
## SelectAccountsOptions<sup>9+</sup>

表示用于选择帐号的选项。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Account.AppAccount。

| 参数名          | 类型                         | 必填  | 说明                |
| --------------- | --------------------------- | ----- | ------------------- |
| allowedAccounts | Array&lt;[AppAccountInfo](#appaccountinfo)&gt; | 否    | 允许的帐号数组。      |
| allowedOwners   | Array&lt;string&gt;         | 否    | 允许的帐号所有者数组。 |
| requiredLabels  | Array&lt;string&gt;         | 否    | 认证器的标签标识。    |

## VerifyCredentialOptions<sup>9+</sup>

表示用于验证凭据的选项。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Account.AppAccount。

| 参数名          | 类型                   | 必填  | 说明           |
| -------------- | ---------------------- | ----- | -------------- |
| credentialType | string                 | 否    | 凭据类型。      |
| credential     | string                 | 否    | 凭据取值。      |
| parameters     | {[key:string]: Object} | 否    | 自定义参数对象。 |


## SetPropertiesOptions<sup>9+</sup>

表示用于设置属性的选项。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Account.AppAccount。

| 参数名     | 类型                    | 必填  | 说明           |
| ---------- | ---------------------- | ----- | -------------- |
| properties | {[key:string]: Object} | 否    | 属性对象。      |
| parameters | {[key:string]: Object} | 否    | 自定义参数对象。 |

## Constants<sup>8+</sup>

表示常量的枚举。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Account.AppAccount。

| 名称                            | 默认值                    | 说明                   |
| -------------------------------- | ---------------------- | ----------------------- |
| ACTION_ADD_ACCOUNT_IMPLICITLY<sup>(deprecated)</sup>    | "addAccountImplicitly" | 表示操作，隐式添加帐号。  |
| ACTION_AUTHENTICATE<sup>(deprecated)</sup>              | "authenticate"         | 表示操作，鉴权。         |
| ACTION_CREATE_ACCOUNT_IMPLICITLY<sup>9+</sup>    | "createAccountImplicitly" | 表示操作，隐式创建帐号。  |
| ACTION_AUTH<sup>9+</sup>              | "auth"         | 表示操作，鉴权。         |
| KEY_NAME                         | "name"                 | 表示键名，应用帐号名称。  |
| KEY_OWNER                        | "owner"                | 表示键名，应用帐号所有者。|
| KEY_TOKEN                        | "token"                | 表示键名，令牌。         |
| KEY_ACTION                       | "action"               | 表示键名，操作。         |
| KEY_AUTH_TYPE                    | "authType"             | 表示键名，鉴权类型。     |
| KEY_SESSION_ID                   | "sessionId"            | 表示键名，会话标识。     |
| KEY_CALLER_PID                   | "callerPid"            | 表示键名，调用方PID。    |
| KEY_CALLER_UID                   | "callerUid"            | 表示键名，调用方UID。    |
| KEY_CALLER_BUNDLE_NAME           | "callerBundleName"     | 表示键名，调用方包名。    |
| KEY_REQUIRED_LABELS<sup>9+</sup> | "requiredLabels"       | 表示键名，必需的标签。    |
| KEY_BOOLEAN_RESULT<sup>9+</sup>  | "booleanResult"        | 表示键名，布尔返回值。    |

## ResultCode<sup>8+</sup>

表示返回码的枚举。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Account.AppAccount。

| 名称                                  | 默认值   | 说明           |
| ----------------------------------- | ----- | ------------ |
| SUCCESS                             | 0     | 表示操作成功。      |
| ERROR_ACCOUNT_NOT_EXIST             | 10001 | 表示应用帐号不存在。   |
| ERROR_APP_ACCOUNT_SERVICE_EXCEPTION | 10002 | 表示应用帐号服务异常。  |
| ERROR_INVALID_PASSWORD              | 10003 | 表示密码无效。      |
| ERROR_INVALID_REQUEST               | 10004 | 表示请求无效。      |
| ERROR_INVALID_RESPONSE              | 10005 | 表示响应无效。      |
| ERROR_NETWORK_EXCEPTION             | 10006 | 表示网络异常。      |
| ERROR_OAUTH_AUTHENTICATOR_NOT_EXIST | 10007 | 表示认证器不存在。    |
| ERROR_OAUTH_CANCELED                | 10008 | 表示鉴权取消。      |
| ERROR_OAUTH_LIST_TOO_LARGE          | 10009 | 表示开放授权列表过大。  |
| ERROR_OAUTH_SERVICE_BUSY            | 10010 | 表示开放授权服务忙碌。  |
| ERROR_OAUTH_SERVICE_EXCEPTION       | 10011 | 表示开放授权服务异常。  |
| ERROR_OAUTH_SESSION_NOT_EXIST       | 10012 | 表示鉴权会话不存在。   |
| ERROR_OAUTH_TIMEOUT                 | 10013 | 表示鉴权超时。      |
| ERROR_OAUTH_TOKEN_NOT_EXIST         | 10014 | 表示开放授权令牌不存在。 |
| ERROR_OAUTH_TOKEN_TOO_MANY          | 10015 | 表示开放授权令牌过多。  |
| ERROR_OAUTH_UNSUPPORT_ACTION        | 10016 | 表示不支持的鉴权操作。  |
| ERROR_OAUTH_UNSUPPORT_AUTH_TYPE     | 10017 | 表示不支持的鉴权类型。  |
| ERROR_PERMISSION_DENIED             | 10018 | 表示权限不足。      |

## AuthCallback<sup>9+</sup>

认证回调接口。

### onResult<sup>9+</sup>

onResult: (code: number, result: {[key: string]: any}) =&gt; void

通知请求结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名    | 类型                   | 必填   | 说明     |
| ------ | -------------------- | ---- | ------ |
| code   | number               | 是    | 鉴权结果码。 |
| result | {[key: string]: any} | 否    | 鉴权结果。  |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  var sessionId = "1234";
  appAccountManager.getAuthCallback(sessionId).then((callback) => {
      var result = {[account_appAccount.Constants.KEY_NAME]: "LiSi",
                    [account_appAccount.Constants.KEY_OWNER]: "com.example.ohos.accountjsdemo",
                    [account_appAccount.Constants.KEY_AUTH_TYPE]: "getSocialData",
                    [account_appAccount.Constants.KEY_TOKEN]: "xxxxxx"};
      callback.onResult(account_appAccount.ResultCode.SUCCESS, result);
  }).catch((err) => {
      console.log("getAuthCallback err: "  + JSON.stringify(err));
  });
  ```

### onRequestRedirected<sup>9+</sup>

onRequestRedirected: (request: Want) =&gt; void

通知请求被跳转。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名     | 类型   | 必填   | 说明         |
| ------- | ---- | ---- | ---------- |
| request | Want | 是    | 用于跳转的请求信息。 |

**示例：**

  ```js
  class MyAuthenticator extends account_appAccount.Authenticator {
      createAccountImplicitly(options, callback) {
          callback.onRequestRedirected({
              bundleName: "com.example.ohos.accountjsdemo",
              abilityName: "com.example.ohos.accountjsdemo.LoginAbility",
          });
      }

      auth(name, authType, options, callback) {
          var result = {[account_appAccount.Constants.KEY_NAME]: name,
                        [account_appAccount.Constants.KEY_AUTH_TYPE]: authType,
                        [account_appAccount.Constants.KEY_TOKEN]: "xxxxxx"};
          callback.onResult(account_appAccount.ResultCode.SUCCESS, result);
      }
  }
  ```

### onRequestContinued<sup>9+</sup>

onRequestContinued?: () =&gt; void

通知请求被继续处理。

**系统能力：** SystemCapability.Account.AppAccount

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  var sessionId = "1234";
  appAccountManager.getAuthCallback(sessionId).then((callback) => {
      callback.onRequestContinued();
  }).catch((err) => {
      console.log("getAuthCallback err: "  + JSON.stringify(err));
  });
  ```

## AuthenticatorCallback<sup>(deprecated)</sup>

OAuth认证器回调接口。

> **说明：** 从API version 9开始废弃。
>
> 从 API version 8开始支持, 建议使用[AuthCallback](#authcallback9)替代。

### onResult<sup>8+</sup>

onResult: (code: number, result: {[key: string]: any}) =&gt; void

通知请求结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名    | 类型                   | 必填   | 说明     |
| ------ | -------------------- | ---- | ------ |
| code   | number               | 是    | 鉴权结果码。 |
| result | {[key: string]: any} | 是    | 鉴权结果。  |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  var sessionId = "1234";
  appAccountManager.getAuthenticatorCallback(sessionId).then((callback) => {
      var result = {[account_appAccount.Constants.KEY_NAME]: "LiSi",
                    [account_appAccount.Constants.KEY_OWNER]: "com.example.ohos.accountjsdemo",
                    [account_appAccount.Constants.KEY_AUTH_TYPE]: "getSocialData",
                    [account_appAccount.Constants.KEY_TOKEN]: "xxxxxx"};
      callback.onResult(account_appAccount.ResultCode.SUCCESS, result);
  }).catch((err) => {
      console.log("getAuthenticatorCallback err: "  + JSON.stringify(err));
  });
  ```

### onRequestRedirected<sup>8+</sup>

onRequestRedirected: (request: Want) =&gt; void

通知请求被跳转。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名     | 类型   | 必填   | 说明         |
| ------- | ---- | ---- | ---------- |
| request | Want | 是    | 用于跳转的请求信息。 |

**示例：**

  ```js
  class MyAuthenticator extends account_appAccount.Authenticator {
      addAccountImplicitly(authType, callerBundleName, options, callback) {
          callback.onRequestRedirected({
              bundleName: "com.example.ohos.accountjsdemo",
              abilityName: "com.example.ohos.accountjsdemo.LoginAbility",
          });
      }

      authenticate(name, authType, callerBundleName, options, callback) {
          var result = {[account_appAccount.Constants.KEY_NAME]: name,
                        [account_appAccount.Constants.KEY_AUTH_TYPE]: authType,
                        [account_appAccount.Constants.KEY_TOKEN]: "xxxxxx"};
          callback.onResult(account_appAccount.ResultCode.SUCCESS, result);
      }
  }
  ```

### onRequestContinued<sup>9+</sup>

onRequestContinued?: () =&gt; void

通知请求被继续处理。

**系统能力：** SystemCapability.Account.AppAccount

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  var sessionId = "1234";
  appAccountManager.getAuthenticatorCallback(sessionId).then((callback) => {
      callback.onRequestContinued();
  }).catch((err) => {
      console.log("getAuthenticatorCallback err: "  + JSON.stringify(err));
  });
  ```

## Authenticator<sup>8+</sup>

认证器基类。

### addAccountImplicitly<sup>8+</sup>

addAccountImplicitly(authType: string, callerBundleName: string, options: {[key: string]: any}, callback: AuthenticatorCallback): void

根据指定的鉴权类型和可选项，隐式地添加应用帐户，并使用callback回调异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名              | 类型                    | 必填   | 说明              |
| ---------------- | --------------------- | ---- | --------------- |
| authType         | string                | 是    | 应用帐号的鉴权类型。      |
| callerBundleName | string                | 是    | 鉴权请求方的包名。       |
| options          | {[key: string]: any}  | 是    | 鉴权所需要的可选项。      |
| callback         | [AuthenticatorCallback](#authenticatorcallbackdeprecated) | 是    | 认证器回调，用于返回鉴权结果。 |

### authenticate<sup>8+</sup>

authenticate(name: string, authType: string, callerBundleName: string, options: {[key: string]: any}, callback: AuthenticatorCallback): void

对应用帐户进行鉴权，获取OAuth令牌，并使用callback回调异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 接口名              | 类型                    | 必填   | 说明              |
| ---------------- | --------------------- | ---- | --------------- |
| name             | string                | 是    | 应用帐号的名称。        |
| authType         | string                | 是    | 应用帐号的鉴权类型。      |
| callerBundleName | string                | 是    | 鉴权请求方的包名。       |
| options          | {[key: string]: any}  | 是    | 鉴权所需要的可选项。      |
| callback         | [AuthenticatorCallback](#authenticatorcallbackdeprecated) | 是    | 认证器回调，用于返回鉴权结果。 |

### verifyCredential<sup>9+</sup>

verifyCredential(name: string, options: VerifyCredentialOptions, callback: AuthenticatorCallback): void;

验证应用帐户的凭据，并使用callback回调异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 接口名              | 类型                    | 必填   | 说明              |
| ---------------- | --------------------- | ---- | --------------- |
| name      | string                   | 是    | 应用帐号的名称。              |
| options   | [VerifyCredentialOptions](#verifycredentialoptions9)  | 是    | 验证凭据的可选项。            |
| callback  | [AuthenticatorCallback](#authenticatorcallbackdeprecated)    | 是    | 认证器回调，用于返回验证结果。 |

### setProperties<sup>9+</sup>

setProperties(options: SetPropertiesOptions, callback: AuthenticatorCallback): void;

设置认证器属性，并使用callback回调异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 接口名              | 类型                    | 必填   | 说明              |
| ---------------- | --------------------- | ---- | --------------- |
| options   | [SetPropertiesOptions](#setpropertiesoptions9)  | 是    | 设置属性的可选项。            |
| callback  | [AuthenticatorCallback](#authenticatorcallbackdeprecated) | 是    | 认证器回调，用于返回设置结果。 |

### checkAccountLabels<sup>9+</sup>

checkAccountLabels(name: string, labels: Array&lt;string&gt;, callback: AuthenticatorCallback): void;

检查帐号标签，并使用callback回调异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 接口名              | 类型                    | 必填   | 说明              |
| ---------------- | --------------------- | ---- | --------------- |
| name      | string                | 是    | 应用帐号的名称。              |
| labels    | Array&lt;string&gt;          | 是    | 标签数组。                   |
| callback  | [AuthenticatorCallback](#authenticatorcallbackdeprecated) | 是    | 认证器回调，用于返回检查结果。 |

### isAccountRemovable<sup>9+</sup>

isAccountRemovable(name: string, callback: AuthenticatorCallback): void;

判断帐号是否可以删除，并使用callback回调异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 接口名              | 类型                    | 必填   | 说明              |
| ---------------- | --------------------- | ---- | --------------- |
| name      | string                | 是    | 应用帐号的名称。              |
| callback  | [AuthenticatorCallback](#authenticatorcallbackdeprecated) | 是    | 认证器回调，用于返回判断结果。 |

### getRemoteObject<sup>9+</sup>

getRemoteObject(): rpc.RemoteObject;

获取认证器的远程对象，不可以重载实现。

**系统能力：** SystemCapability.Account.AppAccount

**示例：**

  ```js
  class MyAuthenticator extends account_appAccount.Authenticator {
      addAccountImplicitly(authType, callerBundleName, options, callback) {
          callback.onRequestRedirected({
              bundleName: "com.example.ohos.accountjsdemo",
              abilityName: "com.example.ohos.accountjsdemo.LoginAbility",
          });
      }

      authenticate(name, authType, callerBundleName, options, callback) {
          var result = {[account_appAccount.Constants.KEY_NAME]: name,
                        [account_appAccount.Constants.KEY_AUTH_TYPE]: authType,
                        [account_appAccount.Constants.KEY_TOKEN]: "xxxxxx"};
          callback.onResult(account_appAccount.ResultCode.SUCCESS, result);
      }

      verifyCredential(name, options, callback) {
          callback.onRequestRedirected({
              bundleName: "com.example.ohos.accountjsdemo",
              abilityName: "com.example.ohos.accountjsdemo.VerifyAbility",
              parameters: {
                name: name
              }
          });
      }

      setProperties(options, callback) {
          callback.onResult(account_appAccount.ResultCode.SUCCESS, {});
      }

      checkAccountLabels(name, labels, callback) {
          var result = {[account_appAccount.Constants.KEY_BOOLEAN_RESULT]: false};
          callback.onResult(account_appAccount.ResultCode.SUCCESS, result);
      }
    
      isAccountRemovable(name, callback) {
          var result = {[account_appAccount.Constants.KEY_BOOLEAN_RESULT]: true};
          callback.onResult(account_appAccount.ResultCode.SUCCESS, result);
      }
  }
  var authenticator = null;
  export default {
      onConnect(want) {
          authenticator = new MyAuthenticator();
          return authenticator.getRemoteObject();
      }
  }
  ```