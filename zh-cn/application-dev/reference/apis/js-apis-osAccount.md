#    系统帐号管理

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```js
import account_osAccount from '@ohos.account.osAccount';
```

## account_osAccount.getAccountManager

getAccountManager(): AccountManager

获取系统帐号能力的实例。

**系统能力：** SystemCapability.Account.OsAccount

**返回值：**
| 类型                              | 说明                     |
| --------------------------------- | ------------------------ |
| [AccountManager](#accountmanager) | 获取系统帐号能力的实例。 |

**示例：**
  ```js
  const accountManager = account_osAccount.getAccountManager();
  ```

## OsAccountType

枚举，系统帐号类型。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Account.OsAccount。

| 参数   | 默认值 | 说明         |
| ------ | ------ | ------------ |
| ADMIN  | 0      | 管理员帐号。 |
| NORMAL | 1      | 普通帐号。   |
| GUEST  | 2      | 访客帐号。   |

## AccountManager

管理系统帐号能力的类。

### activateOsAccount

activateOsAccount(localId: number, callback: AsyncCallback&lt;void&gt;): void

激活指定系统帐号，使用callback回调异步返回结果。

此接口为系统接口，三方应用不支持调用。

**需要权限：** ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS_EXTENSION

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                      | 必填 | 说明                 |
| -------- | ------------------------- | ---- | -------------------- |
| localId  | number                    | 是   | 要激活的系统帐号ID。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调结果。           |

**示例：**激活ID为100的系统帐号
  ```js
  const accountManager = account_osAccount.getAccountManager();
  var localId = 100;
  accountManager.activateOsAccount(localId, (err)=>{
    console.log("activateOsAccount err:" + JSON.stringify(err));
  });
  ```

### activateOsAccount

activateOsAccount(localId: number): Promise&lt;void&gt;

激活指定系统帐号，使用Promise方式异步返回结果。

此接口为系统接口，三方应用不支持调用。

**需要权限：** ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS_EXTENSION

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名  | 类型   | 必填 | 说明                 |
| ------- | ------ | ---- | -------------------- |
| localId | number | 是   | 要激活的系统帐号ID。 |

**返回值：**

| 类型                | 说明                                |
| :------------------ | :---------------------------------- |
| Promise&lt;void&gt; | Promise实例，用于获取异步返回结果。 |

**示例：**激活ID为100的系统帐号
  ```js
  const accountManager = account_osAccount.getAccountManager();
  var localId = 100;
  accountManager.activateOsAccount(localId).then(() => {
    console.log("activateOsAccount success");
  }).catch((err) => {
    console.log("activateOsAccount err:" + JSON.stringify(err));
  });
  ```

### isMultiOsAccountEnable

isMultiOsAccountEnable(callback: AsyncCallback&lt;boolean&gt;): void

判断是否支持多系统帐号，使用callback回调异步返回结果。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                         | 必填 | 说明                                                |
| -------- | ---------------------------- | ---- | --------------------------------------------------- |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调结果，支持多系统帐号则返回true，否则返回false。 |

**示例：**

  ```js
  const accountManager = account_osAccount.getAccountManager();
  accountManager.isMultiOsAccountEnable((err, isEnabled) => {
    console.log("isMultiOsAccountEnable err: " + JSON.stringify(err));
    console.log('isMultiOsAccountEnable isEnabled: ' + isEnabled);
  });
  ```

### isMultiOsAccountEnable

isMultiOsAccountEnable(): Promise&lt;boolean&gt;

判断是否支持多系统帐号，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Account.OsAccount

**返回值：**

| 类型                   | 说明                                                         |
| :--------------------- | :----------------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise实例，用于获取异步返回结果，支持多系统帐号则返回true，否则返回false。 |

**示例：**

  ```js
  const accountManager = account_osAccount.getAccountManager();
  accountManager.isMultiOsAccountEnable().then((isEnabled) => {
    console.log('isMultiOsAccountEnable, isEnabled: ' + isEnabled);
  }).catch((err) => {
    console.log("isMultiOsAccountEnable err: "  + JSON.stringify(err));
  });
  ```

### isOsAccountActived

isOsAccountActived(localId: number, callback: AsyncCallback&lt;boolean&gt;): void

判断指定系统帐号是否处于激活状态，使用callback回调异步返回结果。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS 或 ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                         | 必填 | 说明                                              |
| -------- | ---------------------------- | ---- | ------------------------------------------------- |
| localId  | number                       | 是   | 系统帐号ID。                                      |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调结果，处于激活状态则返回true，否则返回false。 |

**示例：**判断ID为100的系统帐号是否处于激活状态

  ```js
  const accountManager = account_osAccount.getAccountManager();
  var osLocalId = 100;
  accountManager.isOsAccountActived(osLocalId, (err, isActive)=>{
    console.log("isOsAccountActived err:" + JSON.stringify(err));
    console.log("isOsAccountActived isActive:" + isActive);
  });
  ```

### isOsAccountActived

isOsAccountActived(localId: number): Promise&lt;boolean&gt;

判断指定系统帐号是否处于激活状态，使用Promise方式异步返回结果。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS 或 ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名  | 类型   | 必填 | 说明         |
| ------- | ------ | ---- | ------------ |
| localId | number | 是   | 系统帐号ID。 |

**返回值：**

| 类型                   | 说明                                                         |
| :--------------------- | :----------------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise实例，用于获取异步返回结果，处于激活状态则返回true，否则返回false。 |

**示例：**判断ID为100的系统帐号是否处于激活状态

  ```js
  const accountManager = account_osAccount.getAccountManager();
  var osLocalId = 100;
  accountManager.isOsAccountActived(osLocalId).then((isActive) => {
    console.log('isOsAccountActived, isActive: ' + isActive);
  }).catch((err) => {
    console.log("isOsAccountActived err: "  + JSON.stringify(err));
  });
  ```

### isOsAccountConstraintEnable

isOsAccountConstraintEnable(localId: number, constraint: string, callback: AsyncCallback&lt;boolean&gt;): void

判断指定系统帐号是否具有指定约束，使用callback回调异步返回结果。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名     | 类型                         | 必填 | 说明                                              |
| ---------- | ---------------------------- | ---- | ------------------------------------------------- |
| localId    | number                       | 是   | 指定的系统帐号ID。                                |
| constraint | string                       | 是   | 指定的[约束](#系统帐号约束列表)名称。             |
| callback   | AsyncCallback&lt;boolean&gt; | 是   | 回调结果，具有指定约束则返回true，否则返回false。 |

**示例：**判断ID为100的系统帐号是否有禁止使用wifi的约束

  ```js
  const accountManager = account_osAccount.getAccountManager();
  var localId = 100;
  accountManager.isOsAccountConstraintEnable(localId, "constraint.wifi", (err, isConstraintEnabled)=>{
    console.log("isOsAccountConstraintEnable err:" + JSON.stringify(err));
    console.log("isOsAccountConstraintEnable isConstraintEnabled:" + isConstraintEnabled);
  });
  ```

### isOsAccountConstraintEnable

isOsAccountConstraintEnable(localId: number, constraint: string): Promise&lt;boolean&gt;

判断指定系统帐号是否具有指定约束，使用Promise方式异步返回结果。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名     | 类型   | 必填 | 说明                                  |
| ---------- | ------ | ---- | ------------------------------------- |
| localId    | number | 是   | 指定的系统帐号ID。                    |
| constraint | string | 是   | 指定的[约束](#系统帐号约束列表)名称。 |

**返回值：**

| 类型                   | 说明                                                         |
| :--------------------- | :----------------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise实例，用于获取异步返回结果，具有指定约束则返回true，否则返回false。 |

**示例：**判断ID为100的系统帐号是否有禁止使用wifi的约束

  ```js
  const accountManager = account_osAccount.getAccountManager();
  var localId = 100;
  accountManager.isOsAccountConstraintEnable(localId, "constraint.wifi").then((isConstraintEnabled) => {
    console.log('isOsAccountConstraintEnable, isConstraintEnabled: ' + isConstraintEnabled);
  }).catch((err) => {
    console.log("isOsAccountConstraintEnable err: "  + JSON.stringify(err));
  });
  ```

### isTestOsAccount

isTestOsAccount(callback: AsyncCallback&lt;boolean&gt;): void

检查当前系统帐号是否为测试帐号，使用callback回调异步返回结果。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                         | 必填 | 说明                                            |
| -------- | ---------------------------- | ---- | ----------------------------------------------- |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调结果，是测试帐号则返回true，否则返回false。 |

**示例：**

  ```js
  const accountManager = account_osAccount.getAccountManager();
  accountManager.isTestOsAccount((err, isTest) => {
    console.log("isTestOsAccount err: " + JSON.stringify(err));
    console.log('isTestOsAccount isTest: ' + isTest);
  });
  ```

### isTestOsAccount

isTestOsAccount(): Promise&lt;boolean&gt;

检查当前系统帐号是否为测试帐号，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Account.OsAccount

**返回值：**

| 类型                   | 说明                                                         |
| :--------------------- | :----------------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise实例，用于获取异步返回结果，是测试帐号则返回true，否则返回false。 |

**示例：**

  ```js
  const accountManager = account_osAccount.getAccountManager();
  accountManager.isTestOsAccount().then((isTest) => {
    console.log('isTestOsAccount, isTest: ' + isTest);
  }).catch((err) => {
    console.log("isTestOsAccount err: "  + JSON.stringify(err));
  });
  ```

### isOsAccountVerified

isOsAccountVerified(callback: AsyncCallback&lt;boolean&gt;): void

检查当前系统帐号是否已验证，使用callback回调异步返回结果。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                         | 必填 | 说明                                        |
| -------- | ---------------------------- | ---- | ------------------------------------------- |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调结果，已验证则返回true，否则返回false。 |

**示例：**

  ```js
  const accountManager = account_osAccount.getAccountManager();
  accountManager.isOsAccountVerified((err, isVerified) => {
    console.log("isOsAccountVerified err: " + JSON.stringify(err));
    console.log('isOsAccountVerified isVerified: ' + isVerified);
  });
  ```

### isOsAccountVerified

isOsAccountVerified(localId: number, callback: AsyncCallback&lt;boolean&gt;): void

检查指定系统帐号是否已验证，使用callback回调异步返回结果。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS 或 ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                         | 必填 | 说明                                        |
| -------- | ---------------------------- | ---- | ------------------------------------------- |
| localId  | number                       | 否   | 指定的系统帐号ID。                          |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调结果，已验证则返回true，否则返回false。 |

**示例：**

  ```js
  const accountManager = account_osAccount.getAccountManager();
  accountManager.isOsAccountVerified((err, isVerified) => {
    console.log("isOsAccountVerified err: " + JSON.stringify(err));
    console.log('isOsAccountVerified isVerified: ' + isVerified);
  });
  ```

### isOsAccountVerified

isOsAccountVerified(localId?: number): Promise&lt;boolean&gt;

检查指定系统帐号是否已验证，使用Promise方式异步返回结果。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS 或 ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名  | 类型   | 必填 | 说明               |
| ------- | ------ | ---- | ------------------ |
| localId | number | 否   | 指定的系统帐号ID。 |

**返回值：**

| 类型                   | 说明                                                         |
| :--------------------- | :----------------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise实例，用于获取异步返回结果，已验证则返回true，否则返回false。 |

**示例：**

  ```js
  const accountManager = account_osAccount.getAccountManager();
  accountManager.isOsAccountVerified().then((isVerified) => {
    console.log('isOsAccountVerified, isVerified: ' + isVerified);
  }).catch((err) => {
    console.log("isOsAccountVerified err: "  + JSON.stringify(err));
  });
  ```

### removeOsAccount

removeOsAccount(localId: number, callback: AsyncCallback&lt;void&gt;): void

删除指定系统帐号，使用callback回调异步返回结果。

此接口为系统接口，三方应用不支持调用。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                      | 必填 | 说明                 |
| -------- | ------------------------- | ---- | -------------------- |
| localId  | number                    | 是   | 要删除的系统帐号ID。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调结果。           |

**示例：**

  ```js
  const accountManager = account_osAccount.getAccountManager();
  var createIocalId;
  osAccountManager.createOsAccount("testAccountName", osaccount.OsAccountType.NORMAL, (err, osAccountInfo)=>{
    createIocalId = osAccountInfo.localId;
  });
  accountManager.removeOsAccount(createIocalId, (err)=>{
    console.log("removeOsAccount err:" + JSON.stringify(err));
  });
  ```

### removeOsAccount

removeOsAccount(localId: number): Promise&lt;void&gt;

删除指定系统帐号，使用Promise方式异步返回结果。

此接口为系统接口，三方应用不支持调用。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名  | 类型   | 必填 | 说明                 |
| ------- | ------ | ---- | -------------------- |
| localId | number | 是   | 要删除的系统帐号ID。 |

**返回值：**

| 类型                | 说明                                |
| :------------------ | :---------------------------------- |
| Promise&lt;void&gt; | Promise实例，用于获取异步返回结果。 |

**示例：**

  ```js
  const accountManager = account_osAccount.getAccountManager();
  var createIocalId;
  osAccountManager.createOsAccount("testAccountName", osaccount.OsAccountType.NORMAL, (err, osAccountInfo)=>{
    createIocalId = osAccountInfo.localId;
  });
  createIocalId = osAccount.localId;
  accountManager.removeOsAccount(createIocalId).then(() => {
    console.log('removeOsAccount Success');
  }).catch(() => {
    console.log("removeOsAccount err: "  + JSON.stringify(err));
  });
  ```

### setOsAccountConstraints

setOsAccountConstraints(localId: number, constraints: Array&lt;string&gt;, enable: boolean,callback: AsyncCallback&lt;void&gt;): void

为指定系统帐号设置/删除约束，使用callback回调异步返回结果。

此接口为系统接口，三方应用不支持调用。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名      | 类型                      | 必填 | 说明                                         |
| ----------- | ------------------------- | ---- | -------------------------------------------- |
| localId     | number                    | 是   | 系统帐号ID。                                 |
| constraints | Array&lt;string&gt;       | 是   | 待设置/删除的[约束](#系统帐号约束列表)列表。 |
| enable      | boolean                   | 是   | 设置(true)/删除(false)                       |
| callback    | AsyncCallback&lt;void&gt; | 是   | 回调结果。                                   |

**示例：**给ID为100的系统帐号设置禁止使用wifi的约束

  ```js
  const accountManager = account_osAccount.getAccountManager();
  var localId = 100;
  accountManager.setOsAccountConstraints(localId, ["constraint.wifi"], true, (err)=>{
    console.log("setOsAccountConstraints err:" + JSON.stringify(err));
  });
  ```

### setOsAccountConstraints

setOsAccountConstraints(localId: number, constraints: Array&lt;string&gt;, enable: boolean): Promise&lt;void&gt;

为指定系统帐号设置/删除约束，使用Promise方式异步返回结果。

此接口为系统接口，三方应用不支持调用。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名      | 类型                | 必填 | 说明                                         |
| ----------- | ------------------- | ---- | -------------------------------------------- |
| localId     | number              | 是   | 系统帐号ID。                                 |
| constraints | Array&lt;string&gt; | 是   | 待设置/删除的[约束](#系统帐号约束列表)列表。 |
| enable      | boolean             | 是   | 设置(true)/删除(false)。                     |

**返回值：**

| 类型                | 说明                                |
| :------------------ | :---------------------------------- |
| Promise&lt;void&gt; | Promise实例，用于获取异步返回结果。 |

**示例：**删除ID为100的系统帐号的禁止使用wifi的约束

  ```js
  const accountManager = account_osAccount.getAccountManager();
  var localId = 100;
  accountManager.setOsAccountConstraints(localId, ["constraint.location.set"], false).then(() => {
    console.log('setOsAccountConstraints Success');
  }).catch((err) => {
    console.log("setOsAccountConstraints err: "  + JSON.stringify(err));
  });
  ```

### setOsAccountName

setOsAccountName(localId: number, localName: string, callback: AsyncCallback&lt;void&gt;): void

设置指定系统帐号的帐号名，使用callback回调异步返回结果。

此接口为系统接口，三方应用不支持调用。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名    | 类型                      | 必填 | 说明         |
| :-------- | ------------------------- | ---- | ------------ |
| localId   | number                    | 是   | 系统帐号ID。 |
| localName | string                    | 是   | 帐号名。     |
| callback  | AsyncCallback&lt;void&gt; | 是   | 回调结果。   |

**示例：**将ID为100的系统帐号的帐号名设置成demoName

  ```js
  const accountManager = account_osAccount.getAccountManager();
  var localId = 100;
  var newName = "demoName";
  accountManager.setOsAccountName(localId, newName, (err)=>{
    console.debug("setOsAccountName err:" + JSON.stringify(err));
  });
  ```

### setOsAccountName

setOsAccountName(localId: number, localName: string): Promise&lt;void&gt;

设置指定系统帐号的帐号名，使用Promise方式异步返回结果。 

此接口为系统接口，三方应用不支持调用。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名    | 类型   | 必填 | 说明         |
| --------- | ------ | ---- | ------------ |
| localId   | number | 是   | 系统帐号ID。 |
| localName | string | 是   | 帐号名。     |

**返回值：**

| 类型                | 说明                                |
| :------------------ | :---------------------------------- |
| Promise&lt;void&gt; | Promise实例，用于获取异步返回结果。 |

**示例：**将ID为100的系统帐号的帐号名设置成demoName

  ```js
  const accountManager = account_osAccount.getAccountManager();
  var localId = 100;
  var nameLimit = "demoName";
  accountManager.setOsAccountName(localId, nameLimit).then(() => {
    console.log('setOsAccountName Success');
  }).catch((err) => {
    console.log("setOsAccountName err: "  + JSON.stringify(err));
  });
  ```

### getCreatedOsAccountsCount

getCreatedOsAccountsCount(callback: AsyncCallback&lt;number&gt;): void

获取已创建的系统帐号数量，使用callback回调异步返回结果。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                       |
| -------- | --------------------------- | ---- | ------------------------------------------ |
| callback | AsyncCallback&lt;number&gt; | 是   | 回调结果，返回的是已创建的系统帐号的数量。 |

**示例：**

  ```js
  const accountManager = account_osAccount.getAccountManager();
  accountManager.getCreatedOsAccountsCount((err, accountCnt)=>{
    console.log("obtains the number of all os accounts created err:" + JSON.stringify(err));
    console.log("obtains the number of all os accounts created accountCnt:" + accountCnt);
  });
  ```

### getCreatedOsAccountsCount

getCreatedOsAccountsCount(): Promise&lt;number&gt;

获取已创建的系统帐号数量，使用Promise方式异步返回结果。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**返回值：**

| 类型                  | 说明                                                         |
| :-------------------- | :----------------------------------------------------------- |
| Promise&lt;number&gt; | Promise实例，用于获取异步返回结果，返回的是已创建的系统帐号的数量。 |

**示例：**

  ```js
  const accountManager = account_osAccount.getAccountManager();
  accountManager.getCreatedOsAccountsCount().then((accountCnt) => {
    console.log('getCreatedOsAccountsCount, accountCnt: ' + accountCnt);
  }).catch((err) => {
    console.log("getCreatedOsAccountsCount err: "  + JSON.stringify(err));
  });
  ```

### getOsAccountLocalIdFromProcess

getOsAccountLocalIdFromProcess(callback: AsyncCallback&lt;number&gt;): void

获取当前进程所属的系统帐号的帐号ID，使用callback回调异步返回结果。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                               |
| -------- | --------------------------- | ---- | -------------------------------------------------- |
| callback | AsyncCallback&lt;number&gt; | 是   | 回调结果，返回的是当前进程所属的系统帐号的帐号ID。 |

**示例：**

  ```js
  const accountManager = account_osAccount.getAccountManager();
  accountManager.getOsAccountLocalIdFromProcess((err, accountID) => {
    console.log("getOsAccountLocalIdFromProcess err: " + JSON.stringify(err));
    console.log('getOsAccountLocalIdFromProcess accountID: ' + accountID);
  });
  ```

### getOsAccountLocalIdFromProcess

getOsAccountLocalIdFromProcess(): Promise&lt;number&gt;

获取当前进程所属的系统帐号的帐号ID，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Account.OsAccount

**返回值：**

| 类型                  | 说明                                                         |
| :-------------------- | :----------------------------------------------------------- |
| Promise&lt;number&gt; | Promise实例，用于获取异步返回结果，返回的是当前进程所属的系统帐号的帐号ID。 |

**示例：**

  ```js
  const accountManager = account_osAccount.getAccountManager();
  accountManager.getOsAccountLocalIdFromProcess().then((accountID) => {
    console.log('getOsAccountLocalIdFromProcess, accountID: ' + accountID);
  }).catch((err) => {
    console.log("getOsAccountLocalIdFromProcess err: "  + JSON.stringify(err));
  });
  ```

### getOsAccountLocalIdFromUid

getOsAccountLocalIdFromUid(uid: number, callback: AsyncCallback&lt;number&gt;): void

从进程uid中获取该uid所属的系统帐号的帐号ID，使用callback回调异步返回结果。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                          |
| -------- | --------------------------- | ---- | --------------------------------------------- |
| uid      | number                      | 是   | 进程uid。                                     |
| callback | AsyncCallback&lt;number&gt; | 是   | 回调结果，返回的是uid所属的系统帐号的帐号ID。 |

**示例：**查询值为12345678的uid所属的系统帐号的帐号ID

  ```js
  const accountManager = account_osAccount.getAccountManager();
  let uid = 12345678;
  accountManager.getOsAccountLocalIdFromUid(uid, (err, accountID) => {
    console.log("getOsAccountLocalIdFromUid err: " + JSON.stringify(err));
    console.log('getOsAccountLocalIdFromUid: ' + accountID);
  });
  ```

### getOsAccountLocalIdFromUid

getOsAccountLocalIdFromUid(uid: number): Promise&lt;number&gt;

从进程uid中获取该uid所属的系统帐号的帐号ID，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名 | 类型   | 必填 | 说明      |
| ------ | ------ | ---- | --------- |
| uid    | number | 是   | 进程uid。 |

**返回值：**

| 类型                  | 说明                                                         |
| :-------------------- | :----------------------------------------------------------- |
| Promise&lt;number&gt; | Promise实例，用于获取异步返回结果，返回的是uid所属的系统帐号的帐号ID。 |

**示例：**查询值为12345678的uid所属的系统帐号的帐号ID

  ```js
  const accountManager = account_osAccount.getAccountManager();
  let uid = 12345678;
  accountManager.getOsAccountLocalIdFromUid(uid).then((accountID) => {
    console.log('getOsAccountLocalIdFromUid: ' + accountID);
  }).catch((err) => {
    console.log("getOsAccountLocalIdFromUid err: "  + JSON.stringify(err));
  });
  ```

### getOsAccountLocalIdFromDomain<sup>8+</sup>

getOsAccountLocalIdFromDomain(domainInfo: DomainAccountInfo, callback: AsyncCallback&lt;number&gt;): void

根据域帐号信息，获取与其关联的系统帐号的帐号ID。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名     | 类型                                    | 必填 | 说明                                         |
| ---------- | --------------------------------------- | ---- | -------------------------------------------- |
| domainInfo | [DomainAccountInfo](#domainaccountinfo) | 是   | 域帐号信息。                                 |
| callback   | AsyncCallback&lt;number&gt;             | 是   | 回调结果，返回的是和域帐号关联的系统帐号ID。 |

**示例：**

  ```js
  var domainInfo = {domain: "testDomain", accountName: "testAccountName"};
  const accountManager = account_osAccount.getAccountManager();
  accountManager.getOsAccountLocalIdFromDomain(domainInfo, (err, accountID) => {
    console.log("getOsAccountLocalIdFromDomain: " + JSON.stringify(err));
    console.log('getOsAccountLocalIdFromDomain: ' + accountID);
  });
  ```

### getOsAccountLocalIdFromDomain<sup>8+</sup>

getOsAccountLocalIdFromDomain(domainInfo: DomainAccountInfo): Promise&lt;number&gt;

根据域帐号信息，获取与其关联的系统帐号的帐号ID，使用Promise方式异步返回结果。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名     | 类型                                    | 必填 | 说明         |
| ---------- | --------------------------------------- | ---- | ------------ |
| domainInfo | [DomainAccountInfo](#domainaccountinfo) | 是   | 域帐号信息。 |

**返回值：**

| 类型                  | 说明                                                         |
| :-------------------- | :----------------------------------------------------------- |
| Promise&lt;number&gt; | Promise实例，用于获取异步返回结果，返回的是和域帐号关联的系统帐号ID。 |

**示例：**

  ```js
  const accountManager = account_osAccount.getAccountManager();
  var domainInfo = {domain: "testDomain", accountName: "testAccountName"};
  accountManager.getOsAccountLocalIdFromDomain(domainInfo).then((accountID) => {
    console.log('getOsAccountLocalIdFromDomain: ' + accountID);
  }).catch((err) => {
    console.log("getOsAccountLocalIdFromDomain err: "  + JSON.stringify(err));
  });
  ```

### queryMaxOsAccountNumber

queryMaxOsAccountNumber(callback: AsyncCallback&lt;number&gt;): void

查询允许创建的系统帐号的最大数量，使用callback回调异步返回结果。

此接口为系统接口，三方应用不支持调用。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                             |
| -------- | --------------------------- | ---- | ------------------------------------------------ |
| callback | AsyncCallback&lt;number&gt; | 是   | 回调结果，返回的是允许创建的系统帐号的最大数量。 |

**示例：**

  ```js
  const accountManager = account_osAccount.getAccountManager();
  accountManager.queryMaxOsAccountNumber((err, maxCnt)=>{
    console.log("queryMaxOsAccountNumber err:" + JSON.stringify(err));
    console.log("queryMaxOsAccountNumber maxCnt:" + maxCnt);
  });
  ```

### queryMaxOsAccountNumber

queryMaxOsAccountNumber(): Promise&lt;number&gt;

查询允许创建的系统帐号的最大数量，使用Promise方式异步返回结果。

此接口为系统接口，三方应用不支持调用。

**系统能力：** SystemCapability.Account.OsAccount

**返回值：**

| 类型                  | 说明                                                         |
| :-------------------- | :----------------------------------------------------------- |
| Promise&lt;number&gt; | Promise实例，用于获取异步返回结果，返回的是允许创建的系统帐号的最大数量。 |

**示例：**

  ```js
  const accountManager = account_osAccount.getAccountManager();
  accountManager.queryMaxOsAccountNumber().then((maxCnt) => {
    console.log('queryMaxOsAccountNumber, maxCnt: ' + maxCnt);
  }).catch((err) => {
    console.log("queryMaxOsAccountNumber err: "  + JSON.stringify(err));
  });
  ```

### getOsAccountAllConstraints

getOsAccountAllConstraints(localId: number, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

获取指定系统帐号的全部约束，使用callback回调异步返回结果。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                                     | 必填 | 说明                                                         |
| -------- | ---------------------------------------- | ---- | ------------------------------------------------------------ |
| localId  | number                                   | 是   | 系统帐号ID。                                                 |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt; | 是   | 回调结果，返回的是该系统帐号的全部[约束](#系统帐号约束列表)。 |

**示例：**获取ID为100的系统帐号的全部约束

  ```js
  const accountManager = account_osAccount.getAccountManager();
  var localId = 100;
  accountManager.getOsAccountAllConstraints(localId, (err, constraints)=>{
    console.log("getOsAccountAllConstraints err:" + JSON.stringify(err));
    console.log("getOsAccountAllConstraints:" + JSON.stringify(constraints));
  });
  ```

### getOsAccountAllConstraints

getOsAccountAllConstraints(localId: number): Promise&lt;Array&lt;string&gt;&gt;

获取指定系统帐号的全部约束，使用Promise方式异步返回结果。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名  | 类型   | 必填 | 说明         |
| ------- | ------ | ---- | ------------ |
| localId | number | 是   | 系统帐号ID。 |

**返回值：**

| 类型                               | 说明                                                         |
| :--------------------------------- | :----------------------------------------------------------- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise实例，用于获取异步返回结果，返回的是该系统帐号的全部[约束](#系统帐号约束列表)。 |

**示例：**获取ID为100的系统帐号的全部约束

  ```js
  const accountManager = account_osAccount.getAccountManager();
  var localId = 100;
  accountManager.getOsAccountAllConstraints(localId).then((constraints) => {
    console.log("getOsAccountAllConstraints, constraints: " + constraints);
  }).catch((err) => {
    console.log("getOsAccountAllConstraints err: "  + JSON.stringify(err));
  });
  ```

### queryAllCreatedOsAccounts

queryAllCreatedOsAccounts(callback: AsyncCallback&lt;Array&lt;OsAccountInfo&gt;&gt;): void

查询已创建的所有系统帐号的信息列表，使用callback回调异步返回结果。

此接口为系统接口，三方应用不支持调用。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                               |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------------------- |
| callback | AsyncCallback&lt;Array&lt;[OsAccountInfo](#osaccountinfo)&gt;&gt; | 是   | 回调结果，返回的是已创建的所有系统帐号的信息列表。 |

**示例：**

  ```js
  const accountManager = account_osAccount.getAccountManager();
  accountManager.queryAllCreatedOsAccounts((err, accountArr)=>{
    console.log("queryAllCreatedOsAccounts err:" + JSON.stringify(err));
    console.log("queryAllCreatedOsAccounts accountArr:" + JSON.stringify(accountArr));
  });
  ```

### queryAllCreatedOsAccounts

queryAllCreatedOsAccounts(): Promise&lt;Array&lt;OsAccountInfo&gt;&gt;

查询已创建的所有系统帐号的信息列表，使用Promise方式异步返回结果。

此接口为系统接口，三方应用不支持调用。

**系统能力：** SystemCapability.Account.OsAccount

**返回值：**

| 类型                                                        | 说明                                                         |
| :---------------------------------------------------------- | :----------------------------------------------------------- |
| Promise&lt;Array&lt;[OsAccountInfo](#osaccountinfo)&gt;&gt; | Promise实例，用于获取异步返回结果，返回的是已创建的所有系统帐号的信息列表。 |

**示例：**

  ```js
  const accountManager = account_osAccount.getAccountManager();
  accountManager.queryAllCreatedOsAccounts().then((accountArr) => {
    console.log('queryAllCreatedOsAccounts, accountArr: ' + JSON.stringify(accountArr));
  }).catch((err) => {
    console.log("queryAllCreatedOsAccounts err: "  + JSON.stringify(err));
  });
  ```

### queryActivatedOsAccountIds<sup>8+</sup>

queryActivatedOsAccountIds(callback: AsyncCallback&lt;Array&lt;number&gt;&gt;): void

查询当前处于激活状态的系统帐号的ID列表，使用callback回调异步返回结果。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                                     | 必填 | 说明                                                   |
| -------- | ---------------------------------------- | ---- | ------------------------------------------------------ |
| callback | AsyncCallback&lt;Array&lt;number&gt;&gt; | 是   | 回调结果，返回的是当前处于激活状态的系统帐号的ID列表。 |

**示例：**

  ```js
  const accountManager = account_osAccount.getAccountManager();
  accountManager.queryActivatedOsAccountIds((err, idArray)=>{
    console.log("queryActivatedOsAccountIds err:" + JSON.stringify(err));
    console.log("queryActivatedOsAccountIds idArray length:" + idArray.length);
    for(var i=0;i<idArray.length;i++) {
      console.info("activated os account id: " + idArray[i]);
    }
  });
  ```

### queryActivatedOsAccountIds<sup>8+</sup>

queryActivatedOsAccountIds(): Promise&lt;Array&lt;number&gt;&gt;

查询当前处于激活状态的系统帐号的ID列表，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Account.OsAccount

**返回值：**

| 类型                               | 说明                                                         |
| :--------------------------------- | :----------------------------------------------------------- |
| Promise&lt;Array&lt;number&gt;&gt; | Promise实例，用于获取异步返回结果，返回的是当前处于激活状态的系统帐号的ID列表。 |

**示例：**

  ```js
  const accountManager = account_osAccount.getAccountManager();
  accountManager.queryActivatedOsAccountIds().then((idArray) => {
    console.log('queryActivatedOsAccountIds, idArray: ' + idArray);
  }).catch((err) => {
    console.log("queryActivatedOsAccountIds err: "  + JSON.stringify(err));
  });
  ```

### createOsAccount

createOsAccount(localName: string, type: OsAccountType, callback: AsyncCallback&lt;OsAccountInfo&gt;): void

创建一个系统帐号，使用callback回调异步返回结果。

此接口为系统接口，三方应用不支持调用。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名    | 类型                                                 | 必填 | 说明                                       |
| :-------- | ---------------------------------------------------- | ---- | ------------------------------------------ |
| localName | string                                               | 是   | 创建的系统帐号的名称。                     |
| type      | [OsAccountType](#osaccounttype)                      | 是   | 创建的系统帐号的类型。                     |
| callback  | AsyncCallback&lt;[OsAccountInfo](#osaccountinfo)&gt; | 是   | 回调结果，返回的是新创建的系统帐号的信息。 |

**示例：**

  ```js
  const accountManager = account_osAccount.getAccountManager();
  accountManager.createOsAccount("testName", osaccount.OsAccountType.NORMAL, (err, osAccountInfo)=>{
    console.log("createOsAccount err:" + JSON.stringify(err));
    console.log("createOsAccount osAccountInfo:" + JSON.stringify(osAccountInfo));
  });
  ```

### createOsAccount

createOsAccount(localName: string, type: OsAccountType): Promise&lt;OsAccountInfo&gt;

创建一个系统帐号，使用Promise方式异步返回结果。 

此接口为系统接口，三方应用不支持调用。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名    | 类型                            | 必填 | 说明                   |
| --------- | ------------------------------- | ---- | ---------------------- |
| localName | string                          | 是   | 创建的系统帐号的名称。 |
| type      | [OsAccountType](#osaccounttype) | 是   | 创建的系统帐号的类型。 |

**返回值：**

| 类型                                           | 说明                                                         |
| :--------------------------------------------- | :----------------------------------------------------------- |
| Promise&lt;[OsAccountInfo](#osaccountinfo)&gt; | Promise实例，用于获取异步返回结果，返回的是新创建的系统帐号的信息。 |

**示例：**

  ```js
  const accountManager = account_osAccount.getAccountManager();
  accountManager.createOsAccount("testAccountName", osaccount.OsAccountType.NORMAL).then((accountInfo) => {
    console.log("createOsAccount, accountInfo: " + JSON.stringify(accountInfo));
  }).catch((err) => {
    console.log("createOsAccount err: "  + JSON.stringify(err));
  });
  ```

### createOsAccountForDomain<sup>8+</sup>

createOsAccountForDomain(type: OsAccountType, domainInfo: DomainAccountInfo, callback: AsyncCallback&lt;OsAccountInfo&gt;): void

根据域帐号信息，创建一个系统帐号并将其与域帐号关联，使用callback回调异步返回结果。

此接口为系统接口，三方应用不支持调用。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名     | 类型                                                 | 必填 | 说明                                       |
| :--------- | ---------------------------------------------------- | ---- | ------------------------------------------ |
| type       | [OsAccountType](#osaccounttype)                      | 是   | 创建的系统帐号的类型。                     |
| domainInfo | [DomainAccountInfo](#domainaccountinfo)              | 是   | 域帐号信息。                               |
| callback   | AsyncCallback&lt;[OsAccountInfo](#osaccountinfo)&gt; | 是   | 回调结果，返回的是新创建的系统帐号的信息。 |

**示例：**

  ```js
  const accountManager = account_osAccount.getAccountManager();
  var domainInfo = {domain: "testDomain", accountName: "testAccountName"};
  accountManager.createOsAccountForDomain(osaccount.OsAccountType.NORMAL, domainInfo, (err, osAccountInfo)=>{
    console.log("createOsAccountForDomain err:" + JSON.stringify(err));
    console.log("createOsAccountForDomain osAccountInfo:" + JSON.stringify(osAccountInfo));
  });
  ```

### createOsAccountForDomain<sup>8+</sup>

createOsAccountForDomain(type: OsAccountType, domainInfo: DomainAccountInfo): Promise&lt;OsAccountInfo&gt;

根据传入的域帐号信息，创建与其关联的系统帐号，使用Promise方式异步返回结果。 

此接口为系统接口，三方应用不支持调用。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名     | 类型                                    | 必填 | 说明                   |
| ---------- | --------------------------------------- | ---- | ---------------------- |
| type       | [OsAccountType](#osaccounttype)         | 是   | 创建的系统帐号的类型。 |
| domainInfo | [DomainAccountInfo](#domainaccountinfo) | 是   | 域帐号信息。           |

**返回值：**

| 类型                                           | 说明                                                         |
| :--------------------------------------------- | :----------------------------------------------------------- |
| Promise&lt;[OsAccountInfo](#osaccountinfo)&gt; | Promise实例，用于获取异步返回结果，返回的是新创建的系统帐号的信息。 |

**示例：**

  ```js
  const accountManager = account_osAccount.getAccountManager();
  var domainInfo = {domain: "testDomain", accountName: "testAccountName"};
  accountManager.createOsAccountForDomain(osaccount.OsAccountType.NORMAL, domainInfo).then((accountInfo) => {
    console.log("createOsAccountForDomain, account info: " + JSON.stringify(accountInfo));
  }).catch((err) => {
    console.log("createOsAccountForDomain err: "  + JSON.stringify(err));
  });
  ```

### queryCurrentOsAccount

queryCurrentOsAccount(callback: AsyncCallback&lt;OsAccountInfo&gt;): void

查询当前进程所属的系统帐号的信息，使用callback回调异步返回结果。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                                           |
| -------- | ---------------------------------------------------- | ---- | ---------------------------------------------- |
| callback | AsyncCallback&lt;[OsAccountInfo](#osaccountinfo)&gt; | 是   | 回调结果，返回的是当前进程所属的系统帐号信息。 |

**示例：**

  ```js
  const accountManager = account_osAccount.getAccountManager();
  accountManager.queryCurrentOsAccount((err, curAccountInfo)=>{
    console.log("queryCurrentOsAccount err:" + JSON.stringify(err));
    console.log("queryCurrentOsAccount curAccountInfo:" + JSON.stringify(curAccountInfo));
  });
  ```

### queryCurrentOsAccount

queryCurrentOsAccount(): Promise&lt;OsAccountInfo&gt;

查询当前进程所属的系统帐号的信息，使用Promise方式异步返回结果。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**返回值：**

| 类型                                           | 说明                                                         |
| :--------------------------------------------- | :----------------------------------------------------------- |
| Promise&lt;[OsAccountInfo](#osaccountinfo)&gt; | Promise实例，用于获取异步返回结果，返回的是当前进程所属的系统帐号信息。 |

**示例：**

  ```js
  const accountManager = account_osAccount.getAccountManager();
  accountManager.queryCurrentOsAccount().then((accountInfo) => {
    console.log("queryCurrentOsAccount, accountInfo: " + JSON.stringify(accountInfo));
  }).catch((err) => {
    console.log("queryCurrentOsAccount err: "  + JSON.stringify(err));
  });
  ```

### queryOsAccountById

queryOsAccountById(localId: number, callback: AsyncCallback&lt;OsAccountInfo&gt;): void

查询指定系统帐号的信息，使用callback回调异步返回结果。

此接口为系统接口，三方应用不支持调用。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS 或 ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS_EXTENSION

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                                     |
| -------- | ---------------------------------------------------- | ---- | ---------------------------------------- |
| localId  | number                                               | 是   | 要查询的系统帐号的ID                     |
| callback | AsyncCallback&lt;[OsAccountInfo](#osaccountinfo)&gt; | 是   | 回调结果，返回的是查到的系统帐号的信息。 |

**示例：**查询ID为100的系统帐号信息

  ```js
  const accountManager = account_osAccount.getAccountManager();
  var localId = 100;
  accountManager.queryOsAccountById(localId, (err, accountInfo)=>{
    console.log("queryOsAccountById err:" + JSON.stringify(err));
    console.log("queryOsAccountById accountInfo:" + JSON.stringify(accountInfo));
  });
  ```

### queryOsAccountById

queryOsAccountById(localId: number): Promise&lt;OsAccountInfo&gt;

查询指定系统帐号的信息，使用Promise方式异步返回结果。

此接口为系统接口，三方应用不支持调用。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS 或 ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS_EXTENSION

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名  | 类型   | 必填 | 说明                 |
| ------- | ------ | ---- | -------------------- |
| localId | number | 是   | 要查询的系统帐号的ID |

**返回值：**

| 类型                                           | 说明                                                         |
| :--------------------------------------------- | :----------------------------------------------------------- |
| Promise&lt;[OsAccountInfo](#osaccountinfo)&gt; | Promise实例，用于获取异步返回结果，返回的是查到的系统帐号的信息。 |

**示例：**查询ID为100的系统帐号信息

  ```js
  const accountManager = account_osAccount.getAccountManager();
  var localId = 100;
  accountManager.queryOsAccountById(localId).then((accountInfo) => {
    console.log("queryOsAccountById, accountInfo: " + JSON.stringify(accountInfo));
  }).catch((err) => {
    console.log("queryOsAccountById err: "  + JSON.stringify(err));
  });
  ```

### getOsAccountTypeFromProcess

getOsAccountTypeFromProcess(callback: AsyncCallback&lt;OsAccountType&gt;): void

查询当前进程所属的系统帐号的帐号类型，使用callback回调异步返回结果。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                                                 |
| -------- | ---------------------------------------------------- | ---- | ---------------------------------------------------- |
| callback | AsyncCallback&lt;[OsAccountType](#osaccounttype)&gt; | 是   | 回调结果，返回的是当前进程所属的系统帐号的帐号类型。 |

**示例：**

  ```js
  const accountManager = account_osAccount.getAccountManager();
  accountManager.getOsAccountTypeFromProcess((err, accountType) => {
    console.log("getOsAccountTypeFromProcess err: " + JSON.stringify(err));
    console.log('getOsAccountTypeFromProcess accountType: ' + accountType);
  });
  ```

### getOsAccountTypeFromProcess

getOsAccountTypeFromProcess(): Promise&lt;OsAccountType&gt;

查询当前进程所属的系统帐号的帐号类型，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Account.OsAccount

**返回值：**

| 类型                                           | 说明                                                         |
| :--------------------------------------------- | :----------------------------------------------------------- |
| Promise&lt;[OsAccountType](#osaccounttype)&gt; | Promise实例，用于获取异步返回结果，返回的是当前进程所属的系统帐号的帐号类型。 |

**示例：**

  ```js
  const accountManager = account_osAccount.getAccountManager();
  accountManager.getOsAccountTypeFromProcess().then((accountType) => {
    console.log('getOsAccountTypeFromProcess, accountType: ' + accountType);
  }).catch((err) => {
    console.log("getOsAccountTypeFromProcess err: "  + JSON.stringify(err));
  });
  ```

### getDistributedVirtualDeviceId

getDistributedVirtualDeviceId(callback: AsyncCallback&lt;string&gt;): void

获取分布式虚拟设备ID，使用callback回调异步返回结果。

**需要权限：** ohos.permission.DISTRIBUTED_DATASYNC 或 ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                 |
| -------- | --------------------------- | ---- | ------------------------------------ |
| callback | AsyncCallback&lt;string&gt; | 是   | 回调结果，返回的是分布式虚拟设备ID。 |

**示例：**

  ```js
  const accountManager = account_osAccount.getAccountManager();
  accountManager.getDistributedVirtualDeviceId((err, virtualID) => {
    console.log("getDistributedVirtualDeviceId err: " + JSON.stringify(err));
    console.log('getDistributedVirtualDeviceId virtualID: ' + virtualID);
  });
  ```

### getDistributedVirtualDeviceId

getDistributedVirtualDeviceId(): Promise&lt;string&gt;

获取分布式虚拟设备ID，使用Promise方式异步返回结果。

**需要权限：** ohos.permission.DISTRIBUTED_DATASYNC 或 ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**返回值：**

| 类型                  | 说明                                                         |
| :-------------------- | :----------------------------------------------------------- |
| Promise&lt;string&gt; | Promise实例，用于获取异步返回结果，返回的是分布式虚拟设备ID。 |

**示例：**

  ```js
  const accountManager = account_osAccount.getAccountManager();
  accountManager.getDistributedVirtualDeviceId().then((virtualID) => {
    console.log('getDistributedVirtualDeviceId, virtualID: ' + virtualID);
  }).catch((err) => {
    console.log("getDistributedVirtualDeviceId err: "  + JSON.stringify(err));
  });
  ```

### getOsAccountProfilePhoto

getOsAccountProfilePhoto(localId: number, callback: AsyncCallback&lt;string&gt;): void

获取指定系统帐号的头像信息，使用callback回调异步返回结果。

此接口为系统接口，三方应用不支持调用。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                     |
| -------- | --------------------------- | ---- | ---------------------------------------- |
| localId  | number                      | 是   | 系统帐号ID。                             |
| callback | AsyncCallback&lt;string&gt; | 是   | 回调结果，返回的是该系统帐号的头像信息。 |

**示例：**获取ID为100的系统帐号的头像

  ```js
  const accountManager = account_osAccount.getAccountManager();
  var localId = 100;
  accountManager.getOsAccountProfilePhoto(localId, (err, photo)=>{
    console.log("getOsAccountProfilePhoto err:" + JSON.stringify(err));
    console.log("get photo:" + photo + " by localId: " + localId);
  });
  ```

### getOsAccountProfilePhoto

getOsAccountProfilePhoto(localId: number): Promise&lt;string&gt;

获取指定系统帐号的头像信息，使用Promise方式异步返回结果。

此接口为系统接口，三方应用不支持调用。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名  | 类型   | 必填 | 说明         |
| ------- | ------ | ---- | ------------ |
| localId | number | 是   | 系统帐号ID。 |

**返回值：**

| 类型                  | 说明                                                         |
| :-------------------- | :----------------------------------------------------------- |
| Promise&lt;string&gt; | Promise实例，用于获取异步返回结果，返回的是该系统帐号的头像信息。 |

**示例：**获取ID为100的系统帐号的头像

  ```js
  const accountManager = account_osAccount.getAccountManager();
  var localId = 100;
  accountManager.getOsAccountProfilePhoto(localId).then((photo) => {
    console.log("getOsAccountProfilePhoto: " + photo);
  }).catch((err) => {
    console.log("getOsAccountProfilePhoto err: "  + JSON.stringify(err));
  });
  ```

### setOsAccountProfilePhoto

setOsAccountProfilePhoto(localId: number, photo: string, callback: AsyncCallback&lt;void&gt;): void

为指定系统帐号设置头像信息，使用callback回调异步返回结果。

此接口为系统接口，三方应用不支持调用。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                      | 必填 | 说明         |
| -------- | ------------------------- | ---- | ------------ |
| localId  | number                    | 是   | 系统帐号ID。 |
| photo    | string                    | 是   | 头像信息。   |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调结果。   |

**示例：**给ID为100的系统帐号设置头像

  ```js
  const accountManager = account_osAccount.getAccountManager();
  var localId = 100;
  var photo = "data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAA0AAAAPCAYAAAA/I0V3AAAAAXNSR0IArs4c6QAAAARnQU1BAA"+
  "Cxjwv8YQUAAAAJcEhZcwAADsMAAA7DAcdvqGQAAACwSURBVDhPvZLBDYMwDEV/ugsXRjAT0EHCOuFIBwkbdIRewi6unbiAyoGgSn1SFH85+Y"+
  "q/4ljARW62X+LHS8uIzjm4dXUYF+utzBikB52Jo5e5iEPKqpACk7R9NM2RvWm5tIkD2czLCUFNKLD6IjdMHFHDzws285MgGrT0xCtp3WOKHo"+
  "+7q0mP0DZW9pNmoEFUzrQjp5cCnaen2kSJXLFD8ghbXyZCMQf/8e8Ns1XVAG/XAgqKzVnJFAAAAABJRU5ErkJggg=="
  osAccountManager.setOsAccountProfilePhoto(localId, photo, (err)=>{
    console.log("setOsAccountProfilePhoto err:" + JSON.stringify(err));
  });
  ```

### setOsAccountProfilePhoto

setOsAccountProfilePhoto(localId: number, photo: string): Promise&lt;void&gt;

为指定系统帐号设置头像信息，使用Promise方式异步返回结果。

此接口为系统接口，三方应用不支持调用。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名  | 类型   | 必填 | 说明         |
| ------- | ------ | ---- | ------------ |
| localId | number | 是   | 系统帐号ID。 |
| photo   | string | 是   | 头像信息。   |

**返回值：**

| 类型                | 说明                                |
| :------------------ | :---------------------------------- |
| Promise&lt;void&gt; | Promise实例，用于获取异步返回结果。 |

**示例：**给ID为100的系统帐号设置头像

  ```js
  const accountManager = account_osAccount.getAccountManager();
  var localId = 100;
  var photo = "data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAA0AAAAPCAYAAAA/I0V3AAAAAXNSR0IArs4c6QAAAARnQU1BAA"+
  "Cxjwv8YQUAAAAJcEhZcwAADsMAAA7DAcdvqGQAAACwSURBVDhPvZLBDYMwDEV/ugsXRjAT0EHCOuFIBwkbdIRewi6unbiAyoGgSn1SFH85+Y"+
  "q/4ljARW62X+LHS8uIzjm4dXUYF+utzBikB52Jo5e5iEPKqpACk7R9NM2RvWm5tIkD2czLCUFNKLD6IjdMHFHDzws285MgGrT0xCtp3WOKHo"+
  "+7q0mP0DZW9pNmoEFUzrQjp5cCnaen2kSJXLFD8ghbXyZCMQf/8e8Ns1XVAG/XAgqKzVnJFAAAAABJRU5ErkJggg=="
  accountManager.setOsAccountProfilePhoto(localId, photo).then(() => {
    console.log("setOsAccountProfilePhoto success");
  }).catch((err) => {
    console.log("setOsAccountProfilePhoto err: "  + JSON.stringify(err));
  });
  ```

### getOsAccountLocalIdBySerialNumber<sup>8+</sup>

getOsAccountLocalIdBySerialNumber(serialNumber: number, callback: AsyncCallback&lt;number&gt;): void

通过SN码查询与其关联的系统帐号的帐号ID，使用callback回调异步返回结果。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名       | 类型                        | 必填 | 说明                                             |
| ------------ | --------------------------- | ---- | ------------------------------------------------ |
| serialNumber | number                      | 是   | 帐号SN码。                                       |
| callback     | AsyncCallback&lt;number&gt; | 是   | 回调结果，返回的是与SN码关联的系统帐号的帐号ID。 |

**示例：**查询与SN码12345关联的系统帐号的ID

  ```js
  const accountManager = account_osAccount.getAccountManager();
  var serialNumber = 12345;
  accountManager.getOsAccountLocalIdBySerialNumber(serialNumber, (err, localId)=>{
    console.log("ger localId err:" + JSON.stringify(err));
    console.log("get localId:" + localId + " by serialNumber: " + serialNumber);
  });
  ```

### getOsAccountLocalIdBySerialNumber<sup>8+</sup>

getOsAccountLocalIdBySerialNumber(serialNumber: number): Promise&lt;number&gt;

通过SN码查询与其关联的系统帐号的帐号ID，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名       | 类型   | 必填 | 说明       |
| ------------ | ------ | ---- | ---------- |
| serialNumber | number | 是   | 帐号SN码。 |

**返回值：**

| 类型                  | 说明                                                         |
| :-------------------- | :----------------------------------------------------------- |
| Promise&lt;number&gt; | Promise实例，用于获取异步返回结果，返回的是与SN码关联的系统帐号的帐号ID。 |

**示例：**查询与SN码12345关联的系统帐号的ID

  ```js
  const accountManager = account_osAccount.getAccountManager();
  var serialNumber = 12345;
  accountManager.getOsAccountLocalIdBySerialNumber(serialNumber).then((localId) => {
    console.log("getOsAccountLocalIdBySerialNumber localId: " + localId);
  }).catch((err) => {
    console.log("getOsAccountLocalIdBySerialNumber err: "  + JSON.stringify(err));
  });
  ```

### getSerialNumberByOsAccountLocalId<sup>8+</sup>

getSerialNumberByOsAccountLocalId(localId: number, callback: AsyncCallback&lt;number&gt;): void

通过系统帐号ID获取与该系统帐号关联的SN码，使用callback回调异步返回结果。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                       |
| -------- | --------------------------- | ---- | ------------------------------------------ |
| localId  | number                      | 是   | 系统帐号ID。                               |
| callback | AsyncCallback&lt;number&gt; | 是   | 回调结果，返回的是与该系统帐号关联的SN码。 |

**示例：**获取ID为100的系统帐号关联的SN码

  ```js
  const accountManager = account_osAccount.getAccountManager();
  var localId = 100;
  accountManager.getSerialNumberByOsAccountLocalId(localId, (err, serialNumber)=>{
    console.log("ger serialNumber err:" + JSON.stringify(err));
    console.log("get serialNumber:" + serialNumber + " by localId: " + localId);
  });
  ```

### getSerialNumberByOsAccountLocalId<sup>8+</sup>

getSerialNumberByOsAccountLocalId(localId: number): Promise&lt;number&gt;

通过系统帐号ID获取与该系统帐号关联的SN码，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名  | 类型   | 必填 | 说明         |
| ------- | ------ | ---- | ------------ |
| localId | number | 是   | 系统帐号ID。 |

**返回值：**

| 类型                  | 说明                                                         |
| :-------------------- | :----------------------------------------------------------- |
| Promise&lt;number&gt; | Promise实例，用于获取异步返回结果，返回的是与该系统帐号关联的SN码。 |

**示例：**获取ID为100的系统帐号关联的SN码

  ```js
  const accountManager = account_osAccount.getAccountManager();
  var localId = 100;
  accountManager.getSerialNumberByOsAccountLocalId(localId).then((serialNumber) => {
    console.log("getSerialNumberByOsAccountLocalId serialNumber: " + serialNumber);
  }).catch((err) => {
    console.log("getSerialNumberByOsAccountLocalId err: "  + JSON.stringify(err));
  });
  ```

### on

on(type: 'activate' | 'activating', name: string, callback: Callback&lt;number&gt;): void

订阅系统帐号的变动信息，使用callback回调异步返回结果。

此接口为系统接口，三方应用不支持调用。

**需要权限：** ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS_EXTENSION

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                       | 必填 | 说明                                                         |
| -------- | -------------------------- | ---- | ------------------------------------------------------------ |
| type     | 'activate' \| 'activating' | 是   | 订阅类型，activate表示订阅的是帐号已激活完成的事件，activating表示订阅的是帐号正在激活的事件。 |
| name     | string                     | 是   | 订阅名称，可自定义，要求非空且长度不超过1024字节。           |
| callback | Callback&lt;number&gt;     | 是   | 订阅系统帐号变动信息的回调，表示当前事件对应的系统帐号ID。   |

**示例：**

  ```js
  const accountManager = account_osAccount.getAccountManager();
  function onCallback(receiveLocalId){
    console.log("receive localId:" + receiveLocalId);
  }
  accountManager.on("activating", "osAccountOnOffNameA", onCallback);
  ```

### off

off(type: 'activate' | 'activating', name: string, callback?: Callback&lt;number&gt;): void

取消订阅系统帐号的变动信息，使用callback回调异步返回结果。

此接口为系统接口，三方应用不支持调用。

**需要权限：** ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS_EXTENSION

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                       | 必填 | 说明                                                         |
| -------- | -------------------------- | ---- | ------------------------------------------------------------ |
| type     | 'activate' \| 'activating' | 是   | 取消订阅类型，activate表示取消订阅帐号已激活完成的事件，activating取消订阅帐号正在激活的事件。 |
| name     | string                     | 是   | 订阅名称，可自定义，，要求非空且长度不超过1024字节，需要与订阅接口传入的值保持一致。 |
| callback | Callback&lt;number&gt;     | 否   | 取消订阅系统帐号变化的回调，默认返回0。                      |

**示例：**

  ```js
  const accountManager = account_osAccount.getAccountManager();
  function offCallback(){
    console.log("off enter")
  }
  accountManager.off("activating", "osAccountOnOffNameA", offCallback);
  ```

### getBundleIdFromUid<sup>9+</sup>

getBundleIdFromUid(uid: number, callback: AsyncCallback&lt;number&gt;): void;

通过uid查询对应的bundleId。

此接口为系统接口，三方应用不支持调用。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                       | 必填 | 说明                                                         |
| -------- | -------------------------- | ---- | ------------------------------------------------------------ |
| uid     | number | 是   |  进程uid。 |
| callback | AsyncCallback&lt;number&gt;     | 是   | 回调结果，返回的是与uid对应的bundleId。                      |

**示例：**

  ```js
  var testUid = 1000000;
  osAccountManager.getBundleIdFromUid(testUid,(err,bundleId)=>{
    console.info("getBundleIdFromUid errInfo:" + JSON.stringify(err));
    console.info("getBundleIdFromUid bundleId:" + JSON.stringify(bundleId));
  });
  ```
### getBundleIdFromUid<sup>9+</sup>

getBundleIdFromUid(uid: number): Promise&lt;number&gt;;

通过uid查询对应的bundleId。

此接口为系统接口，三方应用不支持调用。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名  | 类型   | 必填 | 说明         |
| ------- | ------ | ---- | ------------ |
| uid     | number | 是   |  进程uid。 |

**返回值：**

| 类型                  | 说明                                                         |
| :-------------------- | :----------------------------------------------------------- |
| Promise&lt;number&gt; | Promise实例，用于获取异步返回结果，返回的是与uid对应的bundleId。 |

**示例：**

  ```js
  var testUid = 1000000;
  var bundleIdInfo = await osAccountManager.getBundleIdFromUid(testUid).catch((err)=>{
    console.info("getBundleIdFromUid errInfo:" + JSON.stringify(err));})
  console.info("getBundleIdFromUid bundleId:" + JSON.stringify(bundleIdInfo));
  ```

### isMainOsAccount<sup>9+</sup>

isMainOsAccount(callback: AsyncCallback&lt;boolean&gt;): void;

查询当前进程是否处于主用户。

此接口为系统接口，三方应用不支持调用。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                       | 必填 | 说明                                                         |
| -------- | -------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;boolean&gt;     | 是   | 回调结果，返回的是当前进程是否处于主用户，是则返回true，否则返回false。                      |

**示例：**

  ```js
  osAccountManager.isMainOsAccount((err,result)=>{
    console.info("isMainOsAccount errInfo:" + JSON.stringify(err));
    console.info("isMainOsAccount result:" + JSON.stringify(result));
  });
  ```
### isMainOsAccount<sup>9+</sup>

isMainOsAccount(): Promise&lt;boolean&gt;;

查询当前进程是否处于主用户。

此接口为系统接口，三方应用不支持调用。

**系统能力：** SystemCapability.Account.OsAccount

**返回值：**

| 类型                  | 说明                                                         |
| :-------------------- | :----------------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise实例，用于获取异步返回结果，回调结果，返回的是当前进程是否处于主用户，是则返回true，否则返回false。 |

**示例：**

  ```js
  var result = await osAccountManager.isMainOsAccount().catch((err)=>{
    console.info("isMainOsAccount errInfo:" + JSON.stringify(err));
  });
  console.info("isMainOsAccount result:" + JSON.stringify(result));
  ```
### queryOsAccountConstraintSourceTypes<sup>9+</sup>

queryOsAccountConstraintSourceTypes(localId: number, constraint: string, callback: AsyncCallback&lt;Array&lt;ConstraintSourceTypeInfo&gt;&gt;): void;

查询指定系统帐号的指定约束来源信息。

此接口为系统接口，三方应用不支持调用。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                       | 必填 | 说明                                                         |
| -------- | -------------------------- | ---- | ------------------------------------------------------------ |
| localId     | number | 是   |  要查询的系统帐号ID |
| constraint     | string | 是   |  要查询的[约束](#系统帐号约束列表)名称 |
| callback | AsyncCallback&lt;Array&lt;[ConstraintSourceTypeInfo](#constraintsourcetypeinfo)&gt;&gt;     | 是   | 回调结果，返回的是指定系统帐号的指定[约束](#系统帐号约束列表)来源信息。                      |

**示例：**

  ```js
  osAccountManager.queryOsAccountConstraintSourceTypes(100, "constraint.wifi",(err,sourceTypeInfos)=>{
    console.info("queryOsAccountConstraintSourceType errInfo:" + JSON.stringify(err));
    console.info("queryOsAccountConstraintSourceType sourceTypeInfos:" + JSON.stringify(sourceTypeInfos));
  });
  ```

### queryOsAccountConstraintSourceTypes<sup>9+</sup>

queryOsAccountConstraintSourceTypes(localId: number, constraint: string): Promise&lt;Array&lt;ConstraintSourceTypeInfo&gt;&gt;;

查询指定系统帐号的指定约束来源信息。

此接口为系统接口，三方应用不支持调用。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名  | 类型   | 必填 | 说明         |
| ------- | ------ | ---- | ------------ |
| localId     | number | 是   |  要查询的系统帐号ID |
| constraint     | string | 是   |  要查询的[约束](#系统帐号约束列表)名称 |

**返回值：**

| 类型                  | 说明                                                         |
| :-------------------- | :----------------------------------------------------------- |
| Promise&lt;Array&lt;[ConstraintSourceTypeInfo](#constraintsourcetypeinfo)&gt;&gt; | Promise实例，用于获取异步返回结果，返回的是指定系统帐号的指定[约束](#系统帐号约束列表)来源信息。 |

**示例：**

  ```js
  var sourceTypeInfos = await osAccountManager.queryOsAccountConstraintSourceTypes(100, "constraint.wifi").catch((err)=>{
    console.info("queryOsAccountConstraintSourceType errInfo:" + JSON.stringify(err));})
  console.info("queryOsAccountConstraintSourceType sourceTypeInfos:" + JSON.stringify(sourceTypeInfos));
  ```

## OsAccountInfo

系统帐号信息。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Account.OsAccount。

| 参数名                         | 类型                                                         | 必填 | 说明                              |
| ------------------------------ | ------------------------------------------------------------ | ---- | --------------------------------- |
| localId                        | number                                                       | 是   | 系统帐号ID。                      |
| localName                      | string                                                       | 是   | 系统帐号名称。                    |
| type                           | [OsAccountType](#osaccounttype)                              | 是   | 系统帐号类型                      |
| constraints                    | Array&lt;string&gt;                                          | 否   | 系统帐号[约束](#系统帐号约束列表) |
| isVerified<sup>8+</sup>        | boolean                                                      | 是   | 帐号是否锁屏                      |
| photo<sup>8+</sup>             | string                                                       | 否   | 系统帐号头像                      |
| createTime<sup>8+</sup>        | number                                                       | 是   | 系统帐号创建时间                  |
| lastLoginTime<sup>8+</sup>     | number                                                       | 否   | 系统帐号最后一次登录时间          |
| serialNumber<sup>8+</sup>      | number                                                       | 是   | 系统帐号SN码                      |
| isActived<sup>8+</sup>         | boolean                                                      | 是   | 系统帐号激活状态                  |
| isCreateCompleted<sup>8+</sup> | boolean                                                      | 是   | 系统帐号创建是否完整              |
| distributedInfo                | [distributedAccount.DistributedInfo](js-apis-distributed-account.md) | 否   | 分布式帐号信息                    |
| domainInfo<sup>8+</sup>        | [DomainAccountInfo](#domainaccountinfo)                      | 否   | 域帐号信息                        |

## DomainAccountInfo<sup>8+</sup>

域帐号信息。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Account.OsAccount。

| 参数名      | 类型   | 必填 | 说明       |
| ----------- | ------ | ---- | ---------- |
| domain      | string | 是   | 域名。     |
| accountName | string | 是   | 域帐号名。 |

## 系统帐号约束列表

| 约束                                  | 说明                           |
| ------------------------------------- | ------------------------------ |
| constraint.wifi                       | 禁止使用wifi                   |
| constraint.wifi.set                   | 禁止配置wifi                   |
| constraint.locale.set                 | 禁止配置设备语言               |
| constraint.app.accounts               | 禁止添加和删除应用帐号         |
| constraint.apps.install               | 禁止安装应用                   |
| constraint.apps.uninstall             | 禁止卸载应用                   |
| constraint.location.shared            | 禁止打开位置共享               |
| constraint.unknown.sources.install    | 禁止安装未知来源的应用         |
| constraint.global.unknown.app.install | 禁止所有用户安装未知来源的应用 |
| constraint.bluetooth.set              | 禁止配置蓝牙                   |
| constraint.bluetooth | 禁止使用蓝牙 |
| constraint.bluetooth.share | 禁止共享使用蓝牙 |
| constraint.usb.file.transfer | 禁止通过USB传输文件 |
| constraint.credentials.set | 禁止配置用户凭据 |
| constraint.os.account.remove | 禁止删除用户 |
| constraint.managed.profile.remove | 禁止删除此用户的托管配置文件 |
| constraint.debug.features.use | J禁止启用或访问调试功能 |
| constraint.vpn.set | 禁止配置VPN |
| constraint.date.time.set | 禁止配置日期时间和时区 |
| constraint.tethering.config | 禁止配置Tethering |
| constraint.network.reset | 禁止重置网络设置 |
| constraint.factory.reset | 禁止出厂设置 |
| constraint.os.account.create | 禁止创建新用户 |
| constraint.add.managed.profile | 禁止添加托管配置文件 |
| constraint.apps.verify.disable | 强制应用程序验证 |
| constraint.cell.broadcasts.set | 禁止配置小区广播 |
| constraint.mobile.networks.set | 禁止配置移动网络 |
| constraint.control.apps | 禁止在设置或启动模块中修改应用程序 |
| constraint.physical.media | 禁止装载物理外部介质 |
| constraint.microphone | 禁止使用麦克风 |
| constraint.microphone.unmute | 禁止取消麦克风静音 |
| constraint.volume.adjust | 禁止调整音量 |
| constraint.calls.outgoing | 禁止拨打外呼电话 |
| constraint.sms.use | 禁止发送或接收短信 |
| constraint.fun | 禁止享受乐趣 |
| constraint.windows.create | 禁止创建应用程序窗口以外的窗口 |
| constraint.system.error.dialogs | 禁止显示崩溃或无响应应用程序的系统错误对话框 |
| constraint.cross.profile.copy.paste | 禁止通过将数据粘贴到其他用户或配置文件来导出剪贴板内容 |
| constraint.beam.outgoing | 禁止使用NFC从应用程序传送数据 |
| constraint.wallpaper | 禁止管理壁纸 |
| constraint.safe.boot | 禁止进入安全引导模式 |
| constraint.parent.profile.app.linking | 允许父配置文件中的应用程序处理来自托管配置文件的Web链接 |
| constraint.audio.record | 禁止录制音频 |
| constraint.camera.use | 禁止使用摄像机 |
| constraint.os.account.background.run | 禁止在后台运行 |
| constraint.data.roam | 禁止漫游通话时使用蜂窝数据 |
| constraint.os.account.set.icon | 禁止修改用户头像 |
| constraint.wallpaper.set | 禁止设置壁纸 |
| constraint.oem.unlock | 禁止启用oem解锁 |
| constraint.device.unmute | 禁止取消设备静音 |
| constraint.password.unified | 禁止托管配置文件与主用户进行统一锁屏质询 |
| constraint.autofill | 禁止使用自动填充服务 |
| constraint.content.capture | 禁止捕获用户屏幕 |
| constraint.content.suggestions | 禁止接收内容建议 |
| constraint.os.account.start | 禁止切换用户 |
| constraint.location.set | 禁止配置位置服务 |
| constraint.airplane.mode.set | 禁止飞行模式 |
| constraint.brightness.set | 禁止配置亮度 |
| constraint.share.into.profile | 禁止将主要用户的文件/图片/数据共享到托管配置文件中 |
| constraint.ambient.display | 禁止显示环境 |
| constraint.screen.timeout.set | 禁止配置屏幕关闭的超时 |
| constraint.print | 禁止打印 |
| constraint.private.dns.set | 禁止配置专用DNS |

## ConstraintSourceTypeInfo<sup>9+</sup>

约束来源类型信息。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Account.OsAccount。

| 参数名      | 类型   | 必填 | 说明       |
| ----------- | ------ | ---- | ---------- |
| localId      | number | 是   | 系统帐号ID     |
| type | [ConstraintSourceType](#constraintsourcetype) | 是   | 约束来源类型 |

## ConstraintSourceType<sup>9+</sup>

枚举，约束来源类型。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Account.OsAccount。

| 参数   | 默认值 | 说明         |
| ------ | ------ | ------------ |
| CONSTRAINT_NOT_EXIST  | 0      | 约束不存在 |
| CONSTRAINT_TYPE_BASE | 1      | 约束源自系统设置   |
| CONSTRAINT_TYPE_DEVICE_OWNER  | 2   | 约束源自设备所有者设置   |
| CONSTRAINT_TYPE_PROFILE_OWNER  | 3  | 约束源自资料所有者设置   |