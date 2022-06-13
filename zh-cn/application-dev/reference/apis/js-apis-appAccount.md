#  	应用帐号管理

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

### addAccount

addAccount(name: string, callback: AsyncCallback&lt;void&gt;): void

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
  appAccountManager.addAccount("WangWu", (err) => { 
      console.log("addAccount err: " + JSON.stringify(err));
  });
  ```

### addAccount

addAccount(name: string, extraInfo: string, callback: AsyncCallback&lt;void&gt;): void

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
  appAccountManager.addAccount("LiSi", "token101", (err) => { 
      console.log("addAccount err: " + JSON.stringify(err));
  });
  ```



### addAccount

addAccount(name: string, extraInfo: string): Promise&lt;void&gt;

将此应用的帐号名或额外信息（能转换成string类型的其它信息）添加到帐号管理服务中，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名       | 类型     | 必填   | 说明                                       |
| --------- | ------ | ---- | ---------------------------------------- |
| name      | string | 是    | 要添加的应用帐号名称。                              |
| extraInfo | string | 是    | 要添加的应用帐号的额外信息（能转换成string类型的其它信息），额外信息不能是应用帐号的敏感信息（如应用账号密码）。 |

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

### addAccountImplicitly<sup>8+</sup>

addAccountImplicitly(owner: string, authType: string, options: {[key: string]: any}, callback: AuthenticatorCallback): void

根据指定的帐号所有者、鉴权类型和可选项隐式地添加应用帐号，并使用callback回调异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名      | 类型                    | 必填   | 说明                      |
| -------- | --------------------- | ---- | ----------------------- |
| owner    | string                | 是    | 要添加的应用帐号所有者包名。          |
| authType | string                | 是    | 要添加的应用帐号鉴权类型。鉴权类型为自定义。  |
| options  | {[key: string]: any}  | 是    | 鉴权所需要的可选项。可选项可根据自己需要设置。 |
| callback | AuthenticatorCallback | 是    | 认证器回调，用于返回鉴权结果。         |

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
  appAccountManager.addAccountImplicitly("LiSi", "readAge", {}, {
      onResult: onResultCallback,
      onRequestRedirected: onRequestRedirectedCallback
  });
  ```

### deleteAccount

deleteAccount(name: string, callback: AsyncCallback&lt;void&gt;): void

从帐号管理服务中删除应用帐号，使用callback回调异步返回结果。

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

### deleteAccount

deleteAccount(name: string): Promise&lt;void&gt;

从帐号管理服务中删除应用帐号，使用Promise方式异步返回结果。

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

### disableAppAccess

disableAppAccess(name: string, bundleName: string, callback: AsyncCallback&lt;void&gt;): void

禁止指定第三方应用帐号名称对指定的第三方应用进行访问，使用callback回调异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名        | 类型                        | 必填   | 说明                                |
| ---------- | ------------------------- | ---- | --------------------------------- |
| name       | string                    | 是    | 要禁用访问的第三方应用帐号名称。                  |
| bundleName | string                    | 是    | 第三方应用的包名。                         |
| callback   | AsyncCallback&lt;void&gt; | 是    | 禁止指定第三方应用帐号名称对指定包名称的第三方应用的回调进行访问。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.disableAppAccess("ZhangSan", "com.example.ohos.accountjsdemo", (err) => { 
      console.log("disableAppAccess err: " + JSON.stringify(err));
  });
  ```

### disableAppAccess

disableAppAccess(name: string, bundleName: string): Promise&lt;void&gt;

禁止指定第三方应用帐号名称对指定包名称的第三方应用进行访问，使用Promise方式异步返回结果。

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

### enableAppAccess

enableAppAccess(name: string, bundleName: string, callback: AsyncCallback&lt;void&gt;): void

允许指定第三方应用帐号名称对指定包名称的第三方应用进行访问，使用callback回调异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名        | 类型                        | 必填   | 说明                                |
| ---------- | ------------------------- | ---- | --------------------------------- |
| name       | string                    | 是    | 应用帐号名称。                           |
| bundleName | string                    | 是    | 第三方应用的包名。                         |
| callback   | AsyncCallback&lt;void&gt; | 是    | 允许指定第三方应用帐号名称对指定包名称的第三方应用的回调进行访问。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.enableAppAccess("ZhangSan", "com.example.ohos.accountjsdemo", (err) => { 
      console.log("enableAppAccess: " + JSON.stringify(err));
   });
  ```

### enableAppAccess

enableAppAccess(name: string, bundleName: string): Promise&lt;void&gt;

允许指定第三方应用帐号的名称对指定包名称的第三方应用进行访问，使用Promise方式异步返回结果。

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
  app_account_instance.enableAppAccess("ZhangSan", "com.example.ohos.accountjsdemo").then(() => { 
       console.log('enableAppAccess Success');
  }).catch((err) => {
      console.log("enableAppAccess err: "  + JSON.stringify(err));
  });
  ```

### checkAppAccountSyncEnable

checkAppAccountSyncEnable(name: string, callback: AsyncCallback&lt;boolean&gt;): void

检查指定应用帐号是否允许应用数据同步，使用callback回调异步返回结果。

**需要权限：** ohos.permission.DISTRIBUTED_DATASYNC，仅系统应用可用。

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

### checkAppAccountSyncEnable

checkAppAccountSyncEnable(name: string): Promise&lt;boolean&gt;

检查指定应用帐号是否允许应用数据同步，使用Promise方式异步返回结果。

**需要权限：** ohos.permission.DISTRIBUTED_DATASYNC，仅系统应用可用。

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

### setAccountCredential

setAccountCredential(name: string, credentialType: string, credential: string,callback: AsyncCallback&lt;void&gt;): void

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
  appAccountManager.setAccountCredential("ZhangSan", "credentialType001", "credential001", (err) => { 
      console.log("setAccountCredential err: " + JSON.stringify(err));
  });
  ```

### setAccountCredential

setAccountCredential(name: string, credentialType: string, credential: string): Promise&lt;void&gt;

设置此应用程序帐号的凭据，使用Promise方式异步返回结果。

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

### setAccountExtraInfo

setAccountExtraInfo(name: string, extraInfo: string, callback: AsyncCallback&lt;void&gt;): void

设置此应用程序帐号的额外信息，使用callback回调异步返回结果。

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

### setAccountExtraInfo

setAccountExtraInfo(name: string, extraInfo: string): Promise&lt;void&gt;

设置此应用程序帐号的额外信息，使用Promise方式异步返回结果。

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

### setAppAccountSyncEnable

setAppAccountSyncEnable(name: string, isEnable: boolean, callback: AsyncCallback&lt;void&gt;): void

设置指定的应用程序帐号是否允许应用程序数据同步，使用callback回调异步返回结果。

**需要权限：** ohos.permission.DISTRIBUTED_DATASYNC，仅系统应用可用。

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

### setAppAccountSyncEnable

setAppAccountSyncEnable(name: string, isEnable: boolean): Promise&lt;void&gt;

设置指定的应用程序帐号是否允许应用程序数据同步，使用Promise方式异步返回结果。

**需要权限：** ohos.permission.DISTRIBUTED_DATASYNC，仅系统应用可用。

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

### setAssociatedData

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
  app_account_instance.setAssociatedData("ZhangSan", "k001", "v001", (err) => { 
      console.log("setAssociatedData err: " + JSON.stringify(err));
  });
  ```

### setAssociatedData

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
  appAccountManager.setAssociatedData("ZhangSan", "k001", "v001").then(() => { 
      console.log('setAssociatedData Success');
  }).catch((err) => {
      console.log("setAssociatedData err: "  + JSON.stringify(err));
  });
  ```

### getAccountCredential

getAccountCredential(name: string, credentialType: string, callback: AsyncCallback&lt;string&gt;): void

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
  appAccountManager.getAccountCredential("ZhangSan", "credentialType001", (err, result) => { 
      console.log("getAccountCredential err: " + JSON.stringify(err));
      console.log('getAccountCredential result: ' + result);
  });
  ```

### getAccountCredential

getAccountCredential(name: string, credentialType: string): Promise&lt;string&gt;

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
  appAccountManager.getAccountCredential("ZhangSan", "credentialType001").then((data) => { 
      console.log('getAccountCredential, result: ' + data);
  }).catch((err) => {
      console.log("getAccountCredential err: "  + JSON.stringify(err));
  });
  ```

### getAccountExtraInfo

getAccountExtraInfo(name: string, callback: AsyncCallback&lt;string&gt;): void

获取此应用帐号的额外信息（能转换成string类型的其它信息），使用callback回调异步返回结果。

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

### getAccountExtraInfo

getAccountExtraInfo(name: string): Promise&lt;string&gt;

获取此应用程序帐号的额外信息，使用Promise方式异步返回结果。

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

### getAssociatedData

getAssociatedData(name: string, key: string, callback: AsyncCallback&lt;string&gt;): void

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
  appAccountManager.getAssociatedData("ZhangSan", "k001", (err, result) => { 
      console.log("getAssociatedData err: " + JSON.stringify(err));
      console.log('getAssociatedData result: ' + result);
  });
  ```

### getAssociatedData

getAssociatedData(name: string, key: string): Promise&lt;string&gt;

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
  appAccountManager.getAssociatedData("ZhangSan", "k001").then((data) => { 
       console.log('getAssociatedData: ' + data);
  }).catch((err) => {
      console.log("getAssociatedData err: "  + JSON.stringify(err));
  });
  ```

### getAllAccessibleAccounts

getAllAccessibleAccounts(callback: AsyncCallback&lt;Array&lt;AppAccountInfo&gt;&gt;): void

获取全部应用已授权帐号信息。

**需要权限：** ohos.permission.GET_ALL_APP_ACCOUNTS，仅系统应用可用。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名      | 类型                                       | 必填   | 说明        |
| -------- | ---------------------------------------- | ---- | --------- |
| callback | AsyncCallback&lt;Array&lt;AppAccountInfo&gt;&gt; | 是    | 应用帐号信息列表。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getAllAccessibleAccounts((err, data)=>{
  	console.debug("getAllAccessibleAccounts err:" + JSON.stringify(err));
  	console.debug("getAllAccessibleAccounts data:" + JSON.stringify(data));
  });
  ```

### getAllAccessibleAccounts

getAllAccessibleAccounts(): Promise&lt;Array&lt;AppAccountInfo&gt;&gt;

获取全部应用已授权帐号信息。

**需要权限：** ohos.permission.GET_ALL_APP_ACCOUNTS，仅系统应用可用。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 类型                                       | 说明                    |
| ---------------------------------------- | --------------------- |
| Promise&lt;Array&lt;AppAccountInfo&gt;&gt; | Promise实例，用于获取异步返回结果。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getAllAccessibleAccounts().then((data) => { 
       console.log('getAllAccessibleAccounts: ' + data);
  }).catch((err) => {
      console.log("getAllAccessibleAccounts err: "  + JSON.stringify(err));
  });
  ```

### getAllAccounts

getAllAccounts(owner: string, callback: AsyncCallback&lt;Array&lt;AppAccountInfo&gt;&gt;): void

获取指定应用全部帐号信息。

**需要权限：** ohos.permission.GET_ALL_APP_ACCOUNTS，仅系统应用可用。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名      | 类型                                       | 必填   | 说明        |
| -------- | ---------------------------------------- | ---- | --------- |
| owner    | string                                   | 是    | 应用包名称。    |
| callback | AsyncCallback&lt;Array&lt;AppAccountInfo&gt;&gt; | 是    | 应用帐号信息列表。 |

**示例：**

  ```js
  const appAccountManager = account.createAppAccountManager();
  const selfBundle = "com.example.actsgetallaaccounts";
  appAccountManager.getAllAccounts(selfBundle, (err, data)=>{
  	console.debug("getAllAccounts err:" + JSON.stringify(err));
  	console.debug("getAllAccounts data:" + JSON.stringify(data));
  });
  ```

### getAllAccounts

getAllAccounts(owner: string): Promise&lt;Array&lt;AppAccountInfo&gt;&gt;

获取指定应用全部帐号信息。

**需要权限：** ohos.permission.GET_ALL_APP_ACCOUNTS，仅系统应用可用。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名   | 类型     | 必填   | 说明     |
| ----- | ------ | ---- | ------ |
| owner | string | 是    | 应用包名称。 |

**参数：**

| 类型                                       | 说明                    |
| ---------------------------------------- | --------------------- |
| Promise&lt;Array&lt;AppAccountInfo&gt;&gt; | Promise实例，用于获取异步返回结果。 |

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

### on('change')

on(type: 'change', owners: Array&lt;string&gt;, callback: Callback&lt;Array&lt;AppAccountInfo&gt;&gt;): void

订阅指定帐号所有者的帐户变更事件，使用callback回调异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                             |
| -------- | ---------------------------------------- | ---- | ------------------------------ |
| type     | 'change'                                 | 是    | 关于帐号更改事件，当帐号所有者更新帐号时，订阅者将收到通知。 |
| owners   | Array&lt;string&gt;                      | 是    | 指示帐号的所有者。                      |
| callback | Callback&lt;Array&lt;AppAccountInfo&gt;&gt; | 是    | 订阅指定帐号所有者的帐号变更事件的回调。           |

**示例：**

  ```js
  const appAccountManager = account.createAppAccountManager();
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

### off('change')

off(type: 'change', callback?: Callback<Array\<AppAccountInfo>>): void

取消订阅帐号事件，使用callback回调异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名      | 类型                               | 必填   | 说明           |
| -------- | -------------------------------- | ---- | ------------ |
| type     | 'change'                         | 是    | 关于帐号更改事件。    |
| callback | Callback<Array\<AppAccountInfo>> | 否    | 取消订阅帐号事件的回调。 |

**示例：**

  ```js
  const appAccountManager = account.createAppAccountManager();
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

### authenticate<sup>8+</sup>

authenticate(name: string, owner: string, authType: string, options: {[key: string]: any}, callback: AuthenticatorCallback): void

对应用帐户进行鉴权以获取OAuth令牌，使用callback回调异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名      | 类型                    | 必填   | 说明              |
| -------- | --------------------- | ---- | --------------- |
| name     | string                | 是    | 要鉴权的应用帐号名称。     |
| owner    | string                | 是    | 要鉴权的应用帐号所有者包名。  |
| authType | string                | 是    | 鉴权类型。           |
| options  | {[key: string]: any}  | 是    | 鉴权所需的可选项。       |
| callback | AuthenticatorCallback | 是    | 认证器回调，用于返回鉴权结果。 |

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
  appAccountManager.authenticate("LiSi", "com.example.ohos.accountjsdemo", "readAge", {}, {
    onResult: onResultCallback,
    onRequestRedirected: onRequestRedirectedCallback
  });
  ```

### getOAuthToken<sup>8+</sup>

getOAuthToken(name: string, owner: string, authType: string, callback: AsyncCallback&lt;string&gt;): void

获取指定应用帐号和鉴权类型的OAuth令牌，使用callback回调异步返回结果。

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
  appAccountManager.getOAuthToken("LiSi", "com.example.ohos.accountjsdemo", "readAge", (err, data) => {
       console.log('getOAuthToken err: ' + JSON.stringify(err));
       console.log('getOAuthToken token: ' + data);
  });
  ```

### getOAuthToken<sup>8+</sup>

getOAuthToken(name: string, owner: string, authType: string): Promise&lt;string&gt;

获取指定应用帐户和鉴权类型的OAuth令牌，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名      | 类型     | 必填   | 说明          |
| -------- | ------ | ---- | ----------- |
| name     | string | 是    | 应用帐号的名称。    |
| owner    | string | 是    | 应用帐号的所有者包名。 |
| authType | string | 是    | 鉴权类型。       |

**参数：**

| 类型                    | 说明                    |
| --------------------- | --------------------- |
| Promise&lt;string&gt; | Promise实例，用于获取异步返回结果。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getOAuthToken("LiSi", "com.example.ohos.accountjsdemo", "readAge").then((data) => {
       console.log('getOAuthToken token: ' + data);
  }).catch((err) => {
      console.log("getOAuthToken err: "  + JSON.stringify(err));
  });
  ```

### setOAuthToken<sup>8+</sup>

setOAuthToken(name: string, authType: string, token: string, callback: AsyncCallback&lt;void&gt;): void

设置指定应用帐号和鉴权类型的OAuth令牌，使用callback回调异步返回结果。

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
  appAccountManager.setOAuthToken("LiSi", "readAge", "xxxx", (err) => {
      console.log('setOAuthToken err: ' + JSON.stringify(err));
  });
  ```

### setOAuthToken<sup>8+</sup>

setOAuthToken(name: string, authType: string, token: string): Promise&lt;void&gt;

设置指定应用帐户和鉴权类型的OAuth令牌，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名      | 类型     | 必填   | 说明       |
| -------- | ------ | ---- | -------- |
| name     | string | 是    | 应用帐号的名称。 |
| authType | string | 是    | 鉴权类型。    |
| token    | string | 是    | OAuth令牌。 |

**参数：**

| 类型                  | 说明                    |
| ------------------- | --------------------- |
| Promise&lt;void&gt; | Promise实例，用于获取异步返回结果。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.setOAuthToken("LiSi", "readAge", "xxxx").then(() => {
      console.log('setOAuthToken successfully');
  }).catch((err) => {
      console.log('setOAuthToken err: ' + JSON.stringify(err));
  });
  ```

### deleteOAuthToken<sup>8+</sup>

deleteOAuthToken(name: string, owner: string, authType: string, token: string, callback: AsyncCallback&lt;void&gt;): void

删除指定应用帐户和鉴权类型的OAuth令牌，使用callback回调异步返回结果。

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
  appAccountManager.deleteOAuthToken("LiSi", "com.example.ohos.accountjsdemo", "readAge", "xxxxx", (err) => {
       console.log('deleteOAuthToken err: ' + JSON.stringify(err));
  });
  ```

### deleteOAuthToken<sup>8+</sup>

deleteOAuthToken(name: string, owner: string, authType: string, token: string): Promise&lt;void&gt;

删除指定应用帐户和鉴权类型的OAuth令牌，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名      | 类型     | 必填   | 说明           |
| -------- | ------ | ---- | ------------ |
| name     | string | 是    | 应用帐号的名称。     |
| owner    | string | 是    | 应用帐号的所有者包名。  |
| authType | string | 是    | 鉴权类型。        |
| token    | string | 是    | 要删除的OAuth令牌。 |

**参数：**

| 类型                  | 说明                    |
| ------------------- | --------------------- |
| Promise&lt;void&gt; | Promise实例，用于获取异步返回结果。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.deleteOAuthToken("LiSi", "com.example.ohos.accountjsdemo", "readAge", "xxxxx").then(() => {
       console.log('deleteOAuthToken successfully');
  }).catch((err) => {
      console.log("deleteOAuthToken err: "  + JSON.stringify(err));
  });
  ```

### setOAuthTokenVisibility<sup>8+</sup>

setOAuthTokenVisibility(name: string, authType: string, bundleName: string, isVisible: boolean, callback: AsyncCallback&lt;void&gt;): void

设置指定鉴权类型的OAuth令牌对特定应用的可见性，使用callback回调异步返回结果。

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
  appAccountManager.setOAuthTokenVisibility("LiSi", "readAge", "com.example.ohos.accountjsdemo", true, (err) => {
       console.log('setOAuthTokenVisibility err: ' + JSON.stringify(err));
  });
  ```

### setOAuthTokenVisibility<sup>8+</sup>

setOAuthTokenVisibility(name: string, authType: string, bundleName: string, isVisible: boolean): Promise&lt;void&gt;

设置指定鉴权类型的OAuth令牌对特定应用的可见性，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名        | 类型      | 必填   | 说明           |
| ---------- | ------- | ---- | ------------ |
| name       | string  | 是    | 应用帐号的名称。     |
| authType   | string  | 是    | 鉴权类型。        |
| bundleName | string  | 是    | 被设置可见性的应用包名。 |
| isVisible  | boolean | 是    | 是否可见。        |

**参数：**

| 类型                  | 说明                    |
| ------------------- | --------------------- |
| Promise&lt;void&gt; | Promise实例，用于获取异步返回结果。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.setOAuthTokenVisibility("LiSi", "readAge", "com.example.ohos.accountjsdemo", true).then(() => {
      console.log('setOAuthTokenVisibility successfully');
  }).catch((err) => {
      console.log('setOAuthTokenVisibility err: ' + JSON.stringify(err));
  });
  ```

### checkOAuthTokenVisibility<sup>8+</sup>

checkOAuthTokenVisibility(name: string, authType: string, bundleName: string, callback: AsyncCallback&lt;boolean&gt;): void

检查指定鉴权类型的OAuth令牌对特定应用的可见性，使用callback回调异步返回结果。

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
  appAccountManager.checkOAuthTokenVisibility("LiSi", "readAge", "com.example.ohos.accountjsdemo", true, (err, data) => {
      console.log('checkOAuthTokenVisibility err: ' + JSON.stringify(err));
      console.log('checkOAuthTokenVisibility isVisible: ' + data);
  });
  ```

### checkOAuthTokenVisibility<sup>8+</sup>

checkOAuthTokenVisibility(name: string, authType: string, bundleName: string): Promise&lt;boolean&gt;

检查指定鉴权类型的OAuth令牌对特定应用的可见性，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名        | 类型     | 必填   | 说明            |
| ---------- | ------ | ---- | ------------- |
| name       | string | 是    | 应用帐号的名称。      |
| authType   | string | 是    | 鉴权类型。         |
| bundleName | string | 是    | 用于检查可见性的应用包名。 |

**参数：**

| 类型                     | 说明                    |
| ---------------------- | --------------------- |
| Promise&lt;boolean&gt; | Promise实例，用于获取异步返回结果。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.checkOAuthTokenVisibility("LiSi", "readAge", "com.example.ohos.accountjsdemo", true).then((data) => {
      console.log('checkOAuthTokenVisibility isVisible: ' + data);
  }).catch((err) => {
      console.log('checkOAuthTokenVisibility err: ' + JSON.stringify(err));
  });
  ```

### getAllOAuthTokens<sup>8+</sup>

getAllOAuthTokens(name: string, owner: string, callback: AsyncCallback&lt;Array&lt;OAuthTokenInfo&gt;&gt;): void

获取指定应用对调用方全部可见的OAuth令牌，使用callback回调异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名      | 类型                                       | 必填   | 说明          |
| -------- | ---------------------------------------- | ---- | ----------- |
| name     | string                                   | 是    | 应用帐号的名称。    |
| owner    | string                                   | 是    | 应用帐号的所有者包名。 |
| callback | AsyncCallback&lt;Array&lt; [OAuthTokenInfo](#oauthtokeninfo8)&gt;&gt; | 是    | 查询结果的回调。    |

**示例：** 

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getAllOAuthTokens("LiSi", "com.example.ohos.accountjsdemo", (err, data) => {
      console.log("getAllOAuthTokens err: "  + JSON.stringify(err));
      console.log('getAllOAuthTokens data: ' + JSON.stringify(data));
  });
  ```

### getAllOAuthTokens<sup>8+</sup>

getAllOAuthTokens(name: string, owner: string): Promise&lt;Array&lt;OAuthTokenInfo&gt;&gt;

获取指定应用帐户对调用方可见的全部OAuth令牌，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名   | 类型     | 必填   | 说明          |
| ----- | ------ | ---- | ----------- |
| name  | string | 是    | 应用帐号的名称。    |
| owner | string | 是    | 应用帐号的所有者包名。 |

**参数：**

| 类型                                       | 说明                    |
| ---------------------------------------- | --------------------- |
| Promise&lt;Array&lt; [OAuthTokenInfo](#oauthtokeninfo8)&gt;&gt; | Promise实例，用于获取异步返回结果。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getAllOAuthTokens("LiSi", "com.example.ohos.accountjsdemo").then((data) => {
       console.log('getAllOAuthTokens data: ' + JSON.stringify(data));
  }).catch((err) => {
      console.log("getAllOAuthTokens err: "  + JSON.stringify(err));
  });
  ```

### getOAuthList<sup>8+</sup>

getOAuthList(name: string, authType: string, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

获取指定应用帐户和鉴权类型的OAuth令牌的授权列表，使用callback回调异步返回结果。

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
  appAccountManager.getOAuthList("com.example.ohos.accountjsdemo", "readAge", (err, data) => {
       console.log('getOAuthList err: ' + JSON.stringify(err));
       console.log('getOAuthList data: ' + JSON.stringify(data));
  });
  ```

### getOAuthList<sup>8+</sup>

getOAuthList(name: string, authType: string): Promise&lt;Array&lt;string&gt;&gt;

获取指定应用帐户和鉴权类型的OAuth令牌的授权列表，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名      | 类型     | 必填   | 说明                      |
| -------- | ------ | ---- | ----------------------- |
| name     | string | 是    | 应用帐号的名称。                |
| authType | string | 是    | 应用帐号的鉴权类型的OAuth令牌的授权列表。 |

**参数：**

| 类型                                 | 说明                    |
| ---------------------------------- | --------------------- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise实例，用于获取异步返回结果。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getOAuthList("com.example.ohos.accountjsdemo", "readAge").then((data) => {
       console.log('getOAuthList data: ' + JSON.stringify(data));
  }).catch((err) => {
      console.log("getOAuthList err: "  + JSON.stringify(err));
  });
  ```

### getAuthenticatorCallback<sup>8+</sup>

getAuthenticatorCallback(sessionId: string, callback: AsyncCallback&lt;AuthenticatorCallback&gt;): void

获取鉴权会话的认证器回调，使用callback回调异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名       | 类型                                       | 必填   | 说明       |
| --------- | ---------------------------------------- | ---- | -------- |
| sessionId | string                                   | 是    | 鉴权会话的标识。 |
| callback  | AsyncCallback&lt;AuthenticatorCallback&gt; | 是    | 查询结果的回调。 |

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
                      [account_appAccount.Constants.KEY_AUTH_TYPE]: "readAge",
                      [account_appAccount.Constants.KEY_TOKEN]: "xxxxxx"};
        callback.OnResult(account_appAccount.ResultCode.SUCCESS, result);
    });
  });
  ```

### getAuthenticatorCallback<sup>8+</sup>

getAuthenticatorCallback(sessionId: string): Promise&lt;AuthenticatorCallback&gt;

获取鉴权会话的认证器回调，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名       | 类型     | 必填   | 说明       |
| --------- | ------ | ---- | -------- |
| sessionId | string | 是    | 鉴权会话的标识。 |

**参数：**

| 类型                                   | 说明                    |
| ------------------------------------ | --------------------- |
| Promise&lt;AuthenticatorCallback&gt; | Promise实例，用于获取异步返回结果。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  featureAbility.getWant().then((want) => {
      var sessionId = want.parameters[account_appAccount.Constants.KEY_SESSION_ID];
      appAccountManager.getAuthenticatorCallback(sessionId).then((callback) => {
          var result = {[account_appAccount.Constants.KEY_NAME]: "LiSi",
                        [account_appAccount.Constants.KEY_OWNER]: "com.example.ohos.accountjsdemo",
                        [account_appAccount.Constants.KEY_AUTH_TYPE]: "readAge",
                        [account_appAccount.Constants.KEY_TOKEN]: "xxxxxx"};
          callback.OnResult(account_appAccount.ResultCode.SUCCESS, result);
      }).catch((err) => {
          console.log("getAuthenticatorCallback err: "  + JSON.stringify(err));
      });
  }).catch((err) => {
      console.log("getWant err: "  + JSON.stringify(err));
  });
  ```

### getAuthenticatorInfo<sup>8+</sup>

getAuthenticatorInfo(owner: string, callback: AsyncCallback&lt;AuthenticatorInfo&gt;): void

获取指定应用帐号的认证器信息，使用callback回调异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名      | 类型                                     | 必填   | 说明          |
| -------- | -------------------------------------- | ---- | ----------- |
| owner    | string                                 | 是    | 应用帐号的所有者包名。 |
| callback | AsyncCallback&lt;AuthenticatorInfo&gt; | 是    | 查询结果的回调。    |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getAuthenticatorInfo("com.example.ohos.accountjsdemo", (err, data) => {
      console.log("getAuthenticatorInfo err: "  + JSON.stringify(err));
      console.log('getAuthenticatorInfo data: ' + JSON.stringify(data));
  });
  ```

### getAuthenticatorInfo<sup>8+</sup>

getAuthenticatorInfo(owner: string): Promise&lt;AuthenticatorInfo&gt;

获取指定应用帐户的认证器信息，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名   | 类型     | 必填   | 说明          |
| ----- | ------ | ---- | ----------- |
| owner | string | 是    | 应用帐号的所有者包名。 |

**参数：**

| 类型                               | 说明                    |
| -------------------------------- | --------------------- |
| Promise&lt;AuthenticatorInfo&gt; | Promise实例，用于获取异步返回结果。 |

**示例：**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getAuthenticatorInfo("com.example.ohos.accountjsdemo").then((data) => { 
       console.log('getAuthenticatorInfo: ' + JSON.stringify(data));
  }).catch((err) => {
      console.log("getAuthenticatorInfo err: "  + JSON.stringify(err));
  });
  ```

## AppAccountInfo

表示应用帐号信息。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Account.AppAccount。

| 参数名   | 类型     | 必填   | 说明          |
| ----- | ------ | ---- | ----------- |
| owner | string | 是    | 应用帐号的所有者包名。 |
| name  | string | 是    | 应用帐号的名称。    |

## OAuthTokenInfo<sup>8+</sup>

表示OAuth令牌信息。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Account.AppAccount。

| 参数名      | 类型     | 必填   | 说明       |
| -------- | ------ | ---- | -------- |
| authType | string | 是    | 令牌的鉴权类型。 |
| token    | string | 是    | 令牌的取值。   |

## AuthenticatorInfo<sup>8+</sup>

表示OAuth认证器信息。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Account.AppAccount。

| 参数名     | 类型     | 必填   | 说明         |
| ------- | ------ | ---- | ---------- |
| owner   | string | 是    | 认证器的所有者包名。 |
| iconId  | string | 是    | 认证器的图标标识。  |
| labelId | string | 是    | 认证器的标签标识。  |

## Constants<sup>8+</sup>

表示常量的枚举。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Account.AppAccount。

| 名称                            | 默认值                    | 说明            |
| ----------------------------- | ---------------------- | ------------- |
| ACTION_ADD_ACCOUNT_IMPLICITLY | "addAccountImplicitly" | 表示操作，隐式添加帐号。  |
| ACTION_AUTHENTICATE           | "authenticate"         | 表示操作，鉴权。      |
| KEY_NAME                      | "name"                 | 表示键名，应用帐号名称。  |
| KEY_OWNER                     | "owner"                | 表示键名，应用帐号所有者。 |
| KEY_TOKEN                     | "token"                | 表示键名，令牌。      |
| KEY_ACTION                    | "action"               | 表示键名，操作。      |
| KEY_AUTH_TYPE                 | "authType"             | 表示键名，鉴权类型。    |
| KEY_SESSION_ID                | "sessionId"            | 表示键名，会话标识。    |
| KEY_CALLER_PID                | "callerPid"            | 表示键名，调用方PID。  |
| KEY_CALLER_UID                | "callerUid"            | 表示键名，调用方UID。  |
| KEY_CALLER_BUNDLE_NAME        | "callerBundleName"     | 表示键名，调用方包名。   |

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

## AuthenticatorCallback<sup>8+</sup>

OAuth认证器回调接口。

### onResult<sup>8+</sup>

onResult: (code: number, result: {[key: string]: any}) =&gt; void

通知鉴权结果。

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
                    [account_appAccount.Constants.KEY_AUTH_TYPE]: "readAge",
                    [account_appAccount.Constants.KEY_TOKEN]: "xxxxxx"};
      callback.OnResult(account_appAccount.ResultCode.SUCCESS, result);
  }).catch((err) => {
      console.log("getAuthenticatorCallback err: "  + JSON.stringify(err));
  });
  ```

### onRequestRedirected<sup>8+</sup>

onRequestRedirected: (request: Want) =&gt; void

通知鉴权请求被跳转。

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

## Authenticator<sup>8+</sup>

OAuth认证器基类。

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
| callback         | AuthenticatorCallback | 是    | 认证器回调，用于返回鉴权结果。 |

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
| callback         | AuthenticatorCallback | 是    | 认证器回调，用于返回鉴权结果。 |

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

  export default {
      onConnect(want) {
          return new MyAuthenticator();
      }
  }
  ```