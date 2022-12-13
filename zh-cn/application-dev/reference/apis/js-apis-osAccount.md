# @ohos.account.osAccount (系统帐号管理)

本模块提供管理系统帐号的基础能力，包括系统帐号的添加、删除、查询、设置、订阅、启动等功能。

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```js
import account_osAccount from '@ohos.account.osAccount';
```

## account_osAccount.getAccountManager

getAccountManager(): AccountManager

获取系统帐号管理对象。

**系统能力：** SystemCapability.Account.OsAccount

**返回值：**

| 类型                              | 说明              |
| --------------------------------- | ---------------- |
| [AccountManager](#accountmanager) | 系统帐号管理对象。 |

**示例：**
  ```js
  let accountManager = account_osAccount.getAccountManager();
  ```

## OsAccountType

表示系统帐号类型的枚举。

**系统能力：** SystemCapability.Account.OsAccount。

| 名称   | 值 | 说明         |
| ------ | ------ | ----------- |
| ADMIN  | 0      | 管理员帐号。 |
| NORMAL | 1      | 普通帐号。   |
| GUEST  | 2      | 访客帐号。   |

## AccountManager

系统帐号管理类。

### activateOsAccount

activateOsAccount(localId: number, callback: AsyncCallback&lt;void&gt;): void

激活指定系统帐号。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS_EXTENSION

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                       | 必填 | 说明                                                |
| -------- | ------------------------- | ---- | -------------------------------------------------- |
| localId  | number                    | 是   | 系统帐号ID。                  |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。当帐号激活成功时，err为null，否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid localId.    |
| 12300003 | Account not found. |
| 12300008 | Restricted Account. |
| 12300009 | Account has been activated. |

**示例：** 激活ID为100的系统帐号
  ```js
  let accountManager = account_osAccount.getAccountManager();
  let localId = 100;
  try {
    accountManager.activateOsAccount(localId, (err)=>{
      if (err) {
        console.log("activateOsAccount failed, error:" + JSON.stringify(err));
      } else {
        console.log("activateOsAccount successfully");
      }
    });
  } catch (err) {
    console.log("activateOsAccount exception:" + JSON.stringify(err));
  }
  ```

### activateOsAccount

activateOsAccount(localId: number): Promise&lt;void&gt;

激活指定系统帐号。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS_EXTENSION

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名  | 类型   | 必填 | 说明                 |
| ------- | ------ | ---- | -------------------- |
| localId | number | 是   | 系统帐号ID。 |

**返回值：**

| 类型                | 说明                                  |
| ------------------- | ------------------------------------ |
| Promise&lt;void&gt; | Promise对象，无返回结果的Promise对象。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid localId.    |
| 12300003 | Account not found. |
| 12300008 | Restricted Account. |
| 12300009 | Account has been activated. |

**示例：** 激活ID为100的系统帐号
  ```js
  let accountManager = account_osAccount.getAccountManager();
  let localId = 100;
  try {
    accountManager.activateOsAccount(localId).then(() => {
      console.log('activateOsAccount successfully');
    }).catch((err) => {
      console.log('activateOsAccount failed, err:' + JSON.stringify(err));
    });
  } catch (e) {
    console.log('activateOsAccount exception:' + JSON.stringify(e));
  }
  ```

### checkMultiOsAccountEnabled<sup>9+</sup>

checkMultiOsAccountEnabled(callback: AsyncCallback&lt;boolean&gt;): void

判断是否支持多系统帐号。使用callback异步回调。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                         | 必填 | 说明                                                     |
| -------- | ---------------------------- | ---- | ------------------------------------------------------ |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调函数。返回true表示支持多系统帐号；返回false表示不支持。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 12300001 | System service exception. |

**示例：**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  try {
    accountManager.checkMultiOsAccountEnabled((err, isEnabled) => {
      if (err) {
        console.log("checkMultiOsAccountEnabled failed, error: " + JSON.stringify(err));
      } else {
      console.log("checkMultiOsAccountEnabled successfully, isEnabled: " + isEnabled);
      }
    });
  } catch (err) {
    console.log("checkMultiOsAccountEnabled exception: " + JSON.stringify(err));
  }
  ```

### checkMultiOsAccountEnabled<sup>9+</sup>

checkMultiOsAccountEnabled(): Promise&lt;boolean&gt;

判断是否支持多系统帐号。使用Promise异步回调。

**系统能力：** SystemCapability.Account.OsAccount

**返回值：**

| 类型                   | 说明                                                        |
| :--------------------- | :--------------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise对象。返回true表示支持多系统帐号；返回false表示不支持。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 12300001 | System service exception. |

**示例：**

  ```js
  try {
    let accountManager = account_osAccount.getAccountManager();
    accountManager.checkMultiOsAccountEnabled().then((isEnabled) => {
      console.log('checkMultiOsAccountEnabled successfully, isEnabled: ' + isEnabled);
    }).catch((err) => {
      console.log('checkMultiOsAccountEnabled failed, error: '  + JSON.stringify(err));
    });
  } catch (err) {
    console.log('checkMultiOsAccountEnabled exception: ' + JSON.stringify(err));
  }
  ```

### checkOsAccountActivated<sup>9+</sup>

checkOsAccountActivated(localId: number, callback: AsyncCallback&lt;boolean&gt;): void

判断指定系统帐号是否处于激活状态。使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS 或 ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                         | 必填 | 说明                                                     |
| -------- | ---------------------------- | ---- | ------------------------------------------------------ |
| localId  | number                       | 是   | 系统帐号ID。                                             |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调函数。返回true表示帐号已激活；返回false表示帐号未激活。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid localId.    |
| 12300003 | Account not found. |

**示例：** 判断ID为100的系统帐号是否处于激活状态

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let localId = 100;
  try {
    accountManager.checkOsAccountActivated(localId, (err, isActivated) => {
      if (err) {
        console.log('checkOsAccountActivated failed, error:' + JSON.stringify(err));
      } else {
        console.log('checkOsAccountActivated successfully, isActivated:' + isActivated);
      }
    });
  } catch (err) {
    console.log('checkOsAccountActivated exception:' + JSON.stringify(err));
  }
  ```

### checkOsAccountActivated<sup>9+</sup>

checkOsAccountActivated(localId: number): Promise&lt;boolean&gt;

判断指定系统帐号是否处于激活状态。使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS 或 ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名  | 类型   | 必填 | 说明                               |
| ------- | ------ | ---- | --------------------------------- |
| localId | number | 是   | 系统帐号ID。 |

**返回值：**

| 类型                   | 说明                                                       |
| ---------------------- | ---------------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise对象。返回true表示帐号已激活；返回false表示帐号未激活。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid localId.    |
| 12300003 | Account not found. |

**示例：** 判断ID为100的系统帐号是否处于激活状态

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let localId = 100;
  try {
    accountManager.checkOsAccountActivated(localId).then((isActivated) => {
      console.log('checkOsAccountActivated successfully, isActivated: ' + isActivated);
    }).catch((err) => {
      console.log('checkOsAccountActivated failed, error: '  + JSON.stringify(err));
    });
  } catch (err) {
    console.log('checkOsAccountActivated exception:' + JSON.stringify(err));
  }
  ```

### checkConstraintEnabled<sup>9+</sup>

checkConstraintEnabled(localId: number, constraint: string, callback: AsyncCallback&lt;boolean&gt;): void

判断指定系统帐号是否具有指定约束。使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名     | 类型                         | 必填 | 说明                                                               |
| ---------- | ---------------------------- | ---- | ----------------------------------------------------------------- |
| localId    | number                       | 是   | 系统帐号ID。                                 |
| constraint | string                       | 是   | 指定的[约束](#系统帐号约束列表)名称。                                |
| callback   | AsyncCallback&lt;boolean&gt; | 是   | 回调函数。返回true表示已使能指定的约束；返回false表示未使能指定的约束。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid localId.    |
| 12300003 | Account not found. |

**示例：** 判断ID为100的系统帐号是否有禁止使用Wi-Fi的约束

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let localId = 100;
  let constraint = "constraint.wifi";
  try {
    accountManager.checkConstraintEnabled(localId, constraint, (err, isEnabled)=>{
      if (err) {
        console.log("checkConstraintEnabled failed, error: " + JSON.stringify(err));
      } else {
        console.log("checkConstraintEnabled successfully, isEnabled: " + isEnabled);
      }
    });
  } catch (err) {
    console.log("checkConstraintEnabled exception: " + JSON.stringify(err));
  }
  ```

### checkConstraintEnabled<sup>9+</sup>

checkConstraintEnabled(localId: number, constraint: string): Promise&lt;boolean&gt;

判断指定系统帐号是否具有指定约束。使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名     | 类型   | 必填 | 说明                                |
| ---------- | ------ | ---- | ---------------------------------- |
| localId    | number | 是   | 系统帐号ID。  |
| constraint | string | 是   | 指定的[约束](#系统帐号约束列表)名称。 |

**返回值：**

| 类型                   | 说明                                                                  |
| --------------------- | --------------------------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise对象。返回true表示已使能指定的约束；返回false表示未使能指定的约束。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid localId.    |
| 12300003 | Account not found. |

**示例：** 判断ID为100的系统帐号是否有禁止使用Wi-Fi的约束

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let localId = 100;
  let constraint = "constraint.wifi";
  try {
    accountManager.checkConstraintEnabled(localId, constraint).then((isEnabled) => {
      console.log("checkConstraintEnabled successfully, isEnabled: " + isEnabled);
    }).catch((err) => {
      console.log("checkConstraintEnabled failed, error: "  + JSON.stringify(err));
    });
  } catch (err) {
    console.log("checkConstraintEnabled exception: " + JSON.stringify(err));
  }
  ```

### checkOsAccountTestable<sup>9+</sup>

checkOsAccountTestable(callback: AsyncCallback&lt;boolean&gt;): void

检查当前系统帐号是否为测试帐号。使用callback异步回调。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                         | 必填 | 说明                                                                   |
| -------- | ---------------------------- | ---- | --------------------------------------------------------------------- |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调函数。返回true表示当前帐号为测试帐号；返回false表示当前帐号非测试帐号。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 12300001 | System service exception. |

**示例：**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  try {
    accountManager.checkOsAccountTestable((err, isTestable) => {
      if (err) {
        console.log("checkOsAccountTestable failed, error: " + JSON.stringify(err));
      } else {
        console.log("checkOsAccountTestable successfully, isTestable: " + isTestable);
      }
    });
  } catch (err) {
    console.log("checkOsAccountTestable error: " + JSON.stringify(err));
  }
  ```

### checkOsAccountTestable<sup>9+</sup>

checkOsAccountTestable(): Promise&lt;boolean&gt;

检查当前系统帐号是否为测试帐号。使用Promise异步回调。

**系统能力：** SystemCapability.Account.OsAccount

**返回值：**

| 类型                   | 说明                                                                      |
| ---------------------- | ------------------------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise对象。返回true表示当前帐号为测试帐号；返回false表示当前帐号非测试帐号。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 12300001 | System service exception. |

**示例：**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  try {
    accountManager.checkOsAccountTestable().then((isTestable) => {
      console.log("checkOsAccountTestable successfully, isTestable: " + isTestable);
    }).catch((err) => {
      console.log("checkOsAccountTestable failed, error: "  + JSON.stringify(err));
    });
  } catch (err) {
    console.log('checkOsAccountTestable exception: ' + JSON.stringify(err));
  }
  ```

### checkOsAccountVerified<sup>9+</sup>

checkOsAccountVerified(callback: AsyncCallback&lt;boolean&gt;): void

检查当前系统帐号是否已验证。使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS 或 ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                         | 必填 | 说明                                                            |
| -------- | ---------------------------- | ---- | ------------------------------------------------------------- |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调函数。返回true表示当前帐号已验证；返回false表示当前帐号未验证。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid localId.    |
| 12300003 | Account not found. |

**示例：**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  try {
    accountManager.checkOsAccountVerified((err, isVerified) => {
      if (err) {
        console.log("checkOsAccountVerified failed, error: " + JSON.stringify(err));
      } else {
        console.log("checkOsAccountVerified successfully, isVerified: " + isVerified);
      }
    });
  } catch (err) {
    console.log("checkOsAccountVerified exception: " + JSON.stringify(err));
  }
  ```

### checkOsAccountVerified<sup>9+</sup>

checkOsAccountVerified(localId: number, callback: AsyncCallback&lt;boolean&gt;): void

检查指定系统帐号是否已验证。使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS 或 ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                         | 必填 | 说明                                                            |
| -------- | ---------------------------- | ---- | ------------------------------------------------------------- |
| localId  | number                       | 是   | 系统帐号ID。                              |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调函数。返回true表示指定帐号已验证；返回false表示指定帐号未验证。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid localId.    |
| 12300003 | Account not found. |

**示例：**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let localId = 100;
  try {
    accountManager.checkOsAccountVerified(localId, (err, isVerified) => {
      if (err) {
        console.log("checkOsAccountVerified failed, error: " + JSON.stringify(err));
      } else {
        console.log("checkOsAccountVerified successfully, isVerified: " + isVerified);
      }
    });
  } catch (err) {
    console.log("checkOsAccountVerified exception: " + err);
  }
  ```

### checkOsAccountVerified<sup>9+</sup>

checkOsAccountVerified(localId?: number): Promise&lt;boolean&gt;

检查指定系统帐号是否已验证。使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS 或 ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名  | 类型   | 必填 | 说明                                                              |
| ------- | ------ | ---- | --------------------------------------------------------------- |
| localId | number | 否   | 系统帐号ID。不填则检查当前系统帐号是否已验证。 |

**返回值：**

| 类型                   | 说明                                                               |
| ---------------------- | ----------------------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise对象。返回true表示指定帐号已验证；返回false表示指定帐号未验证。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid localId.    |
| 12300003 | Account not found. |

**示例：**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let localId = 100;
  try {
    accountManager.checkOsAccountVerified(localId).then((isVerified) => {
      console.log("checkOsAccountVerified successfully, isVerified: " + isVerified);
    }).catch((err) => {
      console.log("checkOsAccountVerified failed, error: " + JSON.stringify(err));
    });
  } catch (err) {
    console.log('checkOsAccountVerified exception: ' + JSON.stringify(err));
  }
  ```

### removeOsAccount

removeOsAccount(localId: number, callback: AsyncCallback&lt;void&gt;): void

删除指定系统帐号。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                                 |
| -------- | ------------------------- | ---- | -------------------------------------------------- |
| localId  | number                    | 是   | 系统帐号ID。                  |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。如果删除帐号成功，err为null，否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid localId.    |
| 12300003 | Account not found. |
| 12300008 | Restricted Account. |

**示例：**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let accountName = "testAccountName";
  try {
    accountManager.createOsAccount(accountName, account_osAccount.OsAccountType.NORMAL, (err, osAccountInfo) => {
      accountManager.removeOsAccount(osAccountInfo.localId, (err)=>{
        if (err) {
          console.log("removeOsAccount failed, error: " + JSON.stringify(err));
        } else {
          console.log("removeOsAccount successfully");
        }
      });
    });
  } catch (err) {
    console.log('removeOsAccount exception:' + JSON.stringify(err));
  }
  ```

### removeOsAccount

removeOsAccount(localId: number): Promise&lt;void&gt;

删除指定系统帐号。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名  | 类型   | 必填 | 说明                               |
| ------- | ------ | ---- | --------------------------------- |
| localId | number | 是   | 系统帐号ID。 |

**返回值：**

| 类型                | 说明                                  |
| ------------------- | ------------------------------------ |
| Promise&lt;void&gt; | Promise对象，无返回结果的Promise对象。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid localId.    |
| 12300003 | Account not found. |
| 12300008 | Restricted Account. |

**示例：**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let accountName = "testAccountName";
  try {
    accountManager.createOsAccount(accountName, account_osAccount.OsAccountType.NORMAL, (err, osAccountInfo)=>{
      accountManager.removeOsAccount(osAccountInfo.localId).then(() => {
        console.log("removeOsAccount successfully");
      }).catch((err) => {
          console.log("removeOsAccount failed, error: " + JSON.stringify(err));
      });
    });
  } catch (err) {
    console.log("removeOsAccount exception: " + JSON.stringify(err));
  }
  ```

### setOsAccountConstraints

setOsAccountConstraints(localId: number, constraints: Array&lt;string&gt;, enable: boolean,callback: AsyncCallback&lt;void&gt;): void

为指定系统帐号设置/删除约束。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名      | 类型                      | 必填 | 说明                                             |
| ----------- | ------------------------- | ---- | ----------------------------------------------- |
| localId     | number                    | 是   | 系统帐号ID。               |
| constraints | Array&lt;string&gt;       | 是   | 待设置/删除的[约束](#系统帐号约束列表)列表。        |
| enable      | boolean                   | 是   | 设置(true)/删除(false)                           |
| callback    | AsyncCallback&lt;void&gt; | 是   | 回调函数。如果设置成功，err为null，否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid localId.    |
| 12300003 | Account not found. |
| 12300008 | Restricted Account. |

**示例：** 给ID为100的系统帐号设置禁止使用Wi-Fi的约束

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let localId = 100;
  let constraint = "constraint.wifi";
  try {
    accountManager.setOsAccountConstraints(localId, [constraint], true, (err) => {
      if (err) {
        console.log("setOsAccountConstraints failed, error:" + JSON.stringify(err));
      } else {
        console.log("setOsAccountConstraints successfully");
      }
    });
  } catch (err) {
    console.log("setOsAccountConstraints exception: " + JSON.stringify(err));
  }
  ```

### setOsAccountConstraints

setOsAccountConstraints(localId: number, constraints: Array&lt;string&gt;, enable: boolean): Promise&lt;void&gt;

为指定系统帐号设置/删除约束。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名      | 类型                | 必填 | 说明                                         |
| ----------- | ------------------- | ---- | -------------------------------------------- |
| localId     | number              | 是   | 系统帐号ID。           |
| constraints | Array&lt;string&gt; | 是   | 待设置/删除的[约束](#系统帐号约束列表)列表。    |
| enable      | boolean             | 是   | 设置(true)/删除(false)。                     |

**返回值：**

| 类型                | 说明                                 |
| :------------------ | :----------------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果的Promise对象。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid localId.    |
| 12300003 | Account not found. |
| 12300008 | Restricted Account. |

**示例：** 删除ID为100的系统帐号的禁止使用Wi-Fi的约束

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let localId = 100;
  try {
    accountManager.setOsAccountConstraints(localId, ['constraint.location.set'], false).then(() => {
      console.log('setOsAccountConstraints succsuccessfully');
    }).catch((err) => {
      console.log('setOsAccountConstraints failed, error: '  + JSON.stringify(err));
    });
  } catch (err) {
    console.log('setOsAccountConstraints exception:' + JSON.stringify(err));
  }
  ```

### setOsAccountName

setOsAccountName(localId: number, localName: string, callback: AsyncCallback&lt;void&gt;): void

设置指定系统帐号的帐号名。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名    | 类型                      | 必填 | 说明                                             |
| :-------- | ------------------------- | ---- | ----------------------------------------------- |
| localId   | number                    | 是   | 系统帐号ID。               |
| localName | string                    | 是   | 帐号名，最大长度为1024个字符。                          |
| callback  | AsyncCallback&lt;void&gt; | 是   | 回调函数。如果设置成功，err为null，否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid localId or localName. |
| 12300003 | Account not found. |
| 12300008 | Restricted Account. |

**示例：** 将ID为100的系统帐号的帐号名设置成demoName

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let localId = 100;
  let name = "demoName";
  try {
    accountManager.setOsAccountName(localId, name, (err) => {
      if (err) {
        console.log("setOsAccountName failed, error: " + JSON.stringify(err));
      } else {
        console.log("setOsAccountName successfully");
      }
    });
  } catch (err) {
    console.log('setOsAccountName exception:' + JSON.stringify(err));
  }
  ```

### setOsAccountName

setOsAccountName(localId: number, localName: string): Promise&lt;void&gt;

设置指定系统帐号的帐号名。使用Promise异步调用。 

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名    | 类型   | 必填 | 说明                                |
| --------- | ------ | ---- | --------------------------------- |
| localId   | number | 是   | 系统帐号ID。 |
| localName | string | 是   | 帐号名，最大长度为1024。            |

**返回值：**

| 类型                | 说明                                  |
| ------------------- | ------------------------------------ |
| Promise&lt;void&gt; | Promise对象，无返回结果的Promise对象。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid localId or localName.    |
| 12300003 | Account not found. |
| 12300008 | Restricted Account. |

**示例：** 将ID为100的系统帐号的帐号名设置成demoName

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let localId = 100;
  let name = 'testName';
  try {
    accountManager.setOsAccountName(localId, name).then(() => {
      console.log('setOsAccountName successfully');
    }).catch((err) => {
      console.log('setOsAccountName failed, error: '  + JSON.stringify(err));
    });
  } catch (err) {
    console.log('setOsAccountName exception:' + JSON.stringify(err));
  }
  ```

### getOsAccountCount<sup>9+</sup>

getOsAccountCount(callback: AsyncCallback&lt;number&gt;): void

获取已创建的系统帐号数量。使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                                                         |
| -------- | --------------------------- | ---- | -------------------------------------------------------------------------- |
| callback | AsyncCallback&lt;number&gt; | 是   | 回调函数。当获取成功时，err为null，data为已创建的系统帐号的数量；否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 12300001 | System service exception. |

**示例：**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  try {
    accountManager.getOsAccountCount((err, count) => {
      if (err) {
        console.log("getOsAccountCount failed, error: " + JSON.stringify(err));
      } else {
        console.log("getOsAccountCount successfully, count: " + count);
      }
    });
  } catch (err) {
    console.log("getOsAccountCount exception: " + JSON.stringify(err));
  }
  ```

### getOsAccountCount<sup>9+</sup>

getOsAccountCount(): Promise&lt;number&gt;

获取已创建的系统帐号数量。使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**返回值：**

| 类型                  | 说明                                    |
| --------------------- | -------------------------------------- |
| Promise&lt;number&gt; | Promise对象，返回已创建的系统帐号的数量。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 12300001 | System service exception. |

**示例：**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  try {
    accountManager.getOsAccountCount().then((count) => {
      console.log("getOsAccountCount successfully, count: " + count);
    }).catch((err) => {
      console.log("getOsAccountCount failed, error: " + JSON.stringify(err));
    });
  } catch(err) {
    console.log('getOsAccountCount exception:' + JSON.stringify(err));
  }
  ```

### queryOsAccountLocalIdFromProcess<sup>9+</sup>

queryOsAccountLocalIdFromProcess(callback: AsyncCallback&lt;number&gt;): void

获取当前进程所属的系统帐号ID，使用callback异步回调。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                                                           |
| -------- | --------------------------- | ---- | ---------------------------------------------------------------------------- |
| callback | AsyncCallback&lt;number&gt; | 是   | 回调函数。当获取成功时，err为null，data为当前进程所属的系统帐号ID；否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 12300001 | System service exception. |

**示例：**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  try {
    accountManager.queryOsAccountLocalIdFromProcess((err, localId) => {
      if (err) {
        console.log("queryOsAccountLocalIdFromProcess failed, error: " + JSON.stringify(err));
      } else {
        console.log("queryOsAccountLocalIdFromProcess successfully, localId: " + localId);
      }
    });
  } catch (err) {
    console.log("queryOsAccountLocalIdFromProcess exception: " + JSON.stringify(err));
  }
  ```

### queryOsAccountLocalIdFromProcess<sup>9+</sup>

queryOsAccountLocalIdFromProcess(): Promise&lt;number&gt;

获取当前进程所属的系统帐号ID，使用Promise异步回调。

**系统能力：** SystemCapability.Account.OsAccount

**返回值：**

| 类型                  | 说明                                      |
| --------------------- | ---------------------------------------- |
| Promise&lt;number&gt; | Promise对象，返回当前进程所属的系统帐号ID。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 12300001 | System service exception. |

**示例：**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  try {
    accountManager.queryOsAccountLocalIdFromProcess().then((localId) => {
      console.log("queryOsAccountLocalIdFromProcess successfully, localId: " + localId);
    }).catch((err) => {
      console.log("queryOsAccountLocalIdFromProcess failed, error: "  + JSON.stringify(err));
    });
  } catch (err) {
    console.log('queryOsAccountLocalIdFromProcess exception: ' + JSON.stringify(err));
  }
  ```

### queryOsAccountLocalIdFromUid<sup>9+</sup>

queryOsAccountLocalIdFromUid(uid: number, callback: AsyncCallback&lt;number&gt;): void

根据uid查询对应的系统帐号ID，使用callback异步回调。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                                                    |
| -------- | --------------------------- | ---- | --------------------------------------------------------------------- |
| uid      | number                      | 是   | 进程uid。                                                              |
| callback | AsyncCallback&lt;number&gt; | 是   | 回调函数。如果查询成功，err为null，data为对应的系统帐号ID；否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息         |
| -------- | --------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid uid.    |

**示例：** 查询值为12345678的uid所属的系统帐号的帐号ID

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let uid = 12345678;
  try {
    accountManager.queryOsAccountLocalIdFromUid(uid, (err, localId) => {
      if (err) {
        console.log("queryOsAccountLocalIdFromUid failed, error: " + JSON.stringify(err));
      }
      console.log("queryOsAccountLocalIdFromUid successfully, localId: " + localId);
    });
  } catch (err) {
    console.log("queryOsAccountLocalIdFromUid exception: " + JSON.stringify(err));
  }
  ```

### queryOsAccountLocalIdFromUid<sup>9+</sup>

queryOsAccountLocalIdFromUid(uid: number): Promise&lt;number&gt;

根据uid查询对应的系统帐号ID，使用Promise异步回调。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名 | 类型   | 必填 | 说明      |
| ------ | ------ | ---- | --------- |
| uid    | number | 是   | 进程uid。 |

**返回值：**

| 类型                  | 说明                                     |
| --------------------- | --------------------------------------- |
| Promise&lt;number&gt; | Promise对象，返回指定uid对应的系统帐号ID。 |

**错误码：**

| 错误码ID | 错误信息       |
| -------- | ------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid uid. |

**示例：** 查询值为12345678的uid所属的系统帐号ID

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let uid = 12345678;
  try {
    accountManager.queryOsAccountLocalIdFromUid(uid).then((localId) => {
      console.log("queryOsAccountLocalIdFromUid successfully, localId: " + localId);
    }).catch((err) => {
      console.log("queryOsAccountLocalIdFromUid failed, error: " + JSON.stringify(err));
    });
  } catch (err) {
    console.log('queryOsAccountLocalIdFromUid exception: ' + JSON.stringify(err));
  }
  ```

### queryOsAccountLocalIdFromDomain<sup>9+</sup>

queryOsAccountLocalIdFromDomain(domainInfo: DomainAccountInfo, callback: AsyncCallback&lt;number&gt;): void

根据域帐号信息，获取与其关联的系统帐号ID。使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名     | 类型                                    | 必填 | 说明                                                                         |
| ---------- | --------------------------------------- | ---- | -------------------------------------------------------------------------- |
| domainInfo | [DomainAccountInfo](#domainaccountinfo8) | 是   | 域帐号信息。                                                                |
| callback   | AsyncCallback&lt;number&gt;             | 是   | 回调函数。如果查询成功，err为null，data为域帐号关联的系统帐号ID；否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息       |
| -------- | ------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid domainInfo. |

**示例：**

  ```js
  let domainInfo = {domain: 'testDomain', accountName: 'testAccountName'};
  let accountManager = account_osAccount.getAccountManager();
  try {
    accountManager.queryOsAccountLocalIdFromDomain(domainInfo, (err, localId) => {
      if (err) {
        console.log("queryOsAccountLocalIdFromDomain failed, error: " + JSON.stringify(err));
      } else {
        console.log("queryOsAccountLocalIdFromDomain successfully, localId: " + localId);
      }
    });
  } catch (err) {
    console.log('queryOsAccountLocalIdFromDomain exception: ' + JSON.stringify(err));
  }
  ```

### queryOsAccountLocalIdFromDomain<sup>9+</sup>

queryOsAccountLocalIdFromDomain(domainInfo: DomainAccountInfo): Promise&lt;number&gt;

根据域帐号信息，获取与其关联的系统帐号的帐号ID。使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名     | 类型                                    | 必填 | 说明         |
| ---------- | --------------------------------------- | ---- | ------------ |
| domainInfo | [DomainAccountInfo](#domainaccountinfo8) | 是   | 域帐号信息。 |

**返回值：**

| 类型                  | 说明                                    |
| :-------------------- | :------------------------------------- |
| Promise&lt;number&gt; | Promise对象，返回域帐号关联的系统帐号ID。 |

**错误码：**

| 错误码ID | 错误信息       |
| -------- | ------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid domainInfo. |

**示例：**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let domainInfo = {domain: 'testDomain', accountName: 'testAccountName'};
  try {
    accountManager.queryOsAccountLocalIdFromDomain(domainInfo).then((localId) => {
      console.log("queryOsAccountLocalIdFromDomain successfully, localId: " + localId);
    }).catch((err) => {
      console.log("queryOsAccountLocalIdFromDomain failed, error: "  + JSON.stringify(err));
    });
  } catch (err) {
    console.log("queryOsAccountLocalIdFromDomain exception: " + JSON.stringify(err));
  }
  ```

### queryMaxOsAccountNumber

queryMaxOsAccountNumber(callback: AsyncCallback&lt;number&gt;): void

查询允许创建的系统帐号的最大数量。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                                                              |
| -------- | --------------------------- | ---- | -------------------------------------------------------------------------------- |
| callback | AsyncCallback&lt;number&gt; | 是   | 回调函数，如果查询成功，err为null，data为允许创建的系统帐号的最大数量；否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息       |
| -------- | ------------- |
| 12300001 | System service exception. |

**示例：**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  try {
    accountManager.queryMaxOsAccountNumber((err, maxCnt) => {
      if (err) {
        console.log('queryMaxOsAccountNumber failed, error:' + JSON.stringify(err));
      } else {
        console.log('queryMaxOsAccountNumber successfully, maxCnt:' + maxCnt);
      }
    });
  } catch (err) {
    console.log('queryMaxOsAccountNumber exception:' + JSON.stringify(err));
  }
  ```

### queryMaxOsAccountNumber

queryMaxOsAccountNumber(): Promise&lt;number&gt;

查询允许创建的系统帐号的最大数量。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**返回值：**

| 类型                  | 说明                                         |
| --------------------- | ------------------------------------------- |
| Promise&lt;number&gt; | Promise对象，返回允许创建的系统帐号的最大数量。 |

**错误码：**

| 错误码ID | 错误信息       |
| -------- | ------------- |
| 12300001 | System service exception. |

**示例：**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  try {
    accountManager.queryMaxOsAccountNumber().then((maxCnt) => {
      console.log('queryMaxOsAccountNumber successfully, maxCnt: ' + maxCnt);
    }).catch((err) => {
      console.log('queryMaxOsAccountNumber failed, error: '  + JSON.stringify(err));
    });
  } catch (err) {
    console.log('queryMaxOsAccountNumber exception:' + JSON.stringify(err));
  }
  ```

### getOsAccountConstraints<sup>9+</sup>

getOsAccountConstraints(localId: number, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

获取指定系统帐号的全部约束。使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                                     | 必填 | 说明                                                                                           |
| -------- | ---------------------------------------- | ---- | -------------------------------------------------------------------------------------------- |
| localId  | number                                   | 是   | 系统帐号ID。                                                                                  |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt; | 是   | 回调函数，如果获取成功，err为null，data为该系统帐号的全部[约束](#系统帐号约束列表)；否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid localId.    |
| 12300003 | Account not found. |

**示例：** 获取ID为100的系统帐号的全部约束

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let localId = 100;
  try {
    accountManager.getOsAccountConstraints(localId, (err, constraints) => {
      if (err) {
        console.log("getOsAccountConstraints failed, err: " + JSON.stringify(err));
      } else {
        console.log("getOsAccountConstraints successfully, constraints: " + JSON.stringify(constraints));
      }
    });
  } catch (err) {
    console.log('getOsAccountConstraints exception:' + JSON.stringify(err));
  }
  ```

### getOsAccountConstraints<sup>9+</sup>

getOsAccountConstraints(localId: number): Promise&lt;Array&lt;string&gt;&gt;

获取指定系统帐号的全部约束。使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名  | 类型   | 必填 | 说明         |
| ------- | ------ | ---- | ------------ |
| localId | number | 是   | 系统帐号ID。 |

**返回值：**

| 类型                               | 说明                                                       |
| ---------------------------------- | ---------------------------------------------------------- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise对象，返回指定系统帐号的全部[约束](#系统帐号约束列表)。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid localId.    |
| 12300003 | Account not found. |

**示例：** 获取ID为100的系统帐号的全部约束

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let localId = 100;
  try {
    accountManager.getOsAccountConstraints(localId).then((constraints) => {
      console.log('getOsAccountConstraints, constraints: ' + constraints);
    }).catch((err) => {
      console.log('getOsAccountConstraints err: '  + JSON.stringify(err));
    });
  } catch (e) {
    console.log('getOsAccountConstraints exception:' + JSON.stringify(e));
  }
  ```

### queryAllCreatedOsAccounts

queryAllCreatedOsAccounts(callback: AsyncCallback&lt;Array&lt;OsAccountInfo&gt;&gt;): void

查询已创建的所有系统帐号的信息列表。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                               |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------------------- |
| callback | AsyncCallback&lt;Array&lt;[OsAccountInfo](#osaccountinfo)&gt;&gt; | 是   | 回调函数。如果查询成功，err为null，data为已创建的所有系统帐号的信息列表；否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息       |
| -------- | ------------- |
| 12300001 | System service exception. |

**示例：**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  try {
    accountManager.queryAllCreatedOsAccounts((err, accountArr)=>{
      console.log('queryAllCreatedOsAccounts err:' + JSON.stringify(err));
      console.log('queryAllCreatedOsAccounts accountArr:' + JSON.stringify(accountArr));
    });
  } catch (e) {
    console.log('queryAllCreatedOsAccounts exception:' + JSON.stringify(e));
  }
  ```

### queryAllCreatedOsAccounts

queryAllCreatedOsAccounts(): Promise&lt;Array&lt;OsAccountInfo&gt;&gt;

查询已创建的所有系统帐号的信息列表。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**返回值：**

| 类型                                                        | 说明                                           |
| ----------------------------------------------------------- | --------------------------------------------- |
| Promise&lt;Array&lt;[OsAccountInfo](#osaccountinfo)&gt;&gt; | Promise对象，返回已创建的所有系统帐号的信息列表。 |

**错误码：**

| 错误码ID | 错误信息       |
| -------- | ------------- |
| 12300001 | System service exception. |

**示例：**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  try {
    accountManager.queryAllCreatedOsAccounts().then((accountArr) => {
      console.log('queryAllCreatedOsAccounts, accountArr: ' + JSON.stringify(accountArr));
    }).catch((err) => {
      console.log('queryAllCreatedOsAccounts err: '  + JSON.stringify(err));
    });
  } catch (e) {
    console.log('queryAllCreatedOsAccounts exception:' + JSON.stringify(e));
  }
  ```

### getActivatedOsAccountIds<sup>9+</sup>

getActivatedOsAccountIds(callback: AsyncCallback&lt;Array&lt;number&gt;&gt;): void

查询当前处于激活状态的系统帐号的ID列表。使用callback异步回调。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                                     | 必填 | 说明                                                   |
| -------- | ---------------------------------------- | ---- | ------------------------------------------------------ |
| callback | AsyncCallback&lt;Array&lt;number&gt;&gt; | 是   | 回调函数。如果查询成功，err为null，data为当前处于激活状态的系统帐号的ID列表；否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息       |
| -------- | ------------- |
| 12300001 | System service exception. |

**示例：**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  try {
    accountManager.getActivatedOsAccountIds((err, idArray)=>{
      console.log('getActivatedOsAccountIds err:' + JSON.stringify(err));
      console.log('getActivatedOsAccountIds idArray length:' + idArray.length);
      for(let i=0;i<idArray.length;i++) {
        console.info('activated os account id: ' + idArray[i]);
      }
    });
  } catch (e) {
    console.log('getActivatedOsAccountIds exception:' + JSON.stringify(e));
  }
  ```

### getActivatedOsAccountIds<sup>9+</sup>

getActivatedOsAccountIds(): Promise&lt;Array&lt;number&gt;&gt;

查询当前处于激活状态的系统帐号的ID列表。使用Promise异步回调。

**系统能力：** SystemCapability.Account.OsAccount

**返回值：**

| 类型                               | 说明                                               |
| :--------------------------------- | :------------------------------------------------ |
| Promise&lt;Array&lt;number&gt;&gt; | Promise对象，返回当前处于激活状态的系统帐号的ID列表。 |

**错误码：**

| 错误码ID | 错误信息       |
| -------- | ------------- |
| 12300001 | System service exception. |

**示例：**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  try {
    accountManager.getActivatedOsAccountIds().then((idArray) => {
      console.log('getActivatedOsAccountIds, idArray: ' + idArray);
    }).catch((err) => {
      console.log('getActivatedOsAccountIds err: '  + JSON.stringify(err));
    });
  } catch (e) {
    console.log('getActivatedOsAccountIds exception:' + JSON.stringify(e));
  }
  ```

### createOsAccount

createOsAccount(localName: string, type: OsAccountType, callback: AsyncCallback&lt;OsAccountInfo&gt;): void

创建一个系统帐号。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名    | 类型                                                 | 必填 | 说明                                                                         |
| :-------- | ---------------------------------------------------- | ---- | --------------------------------------------------------------------------- |
| localName | string                                               | 是   | 创建的系统帐号的名称。                                                        |
| type      | [OsAccountType](#osaccounttype)                      | 是   | 创建的系统帐号的类型。                                                        |
| callback  | AsyncCallback&lt;[OsAccountInfo](#osaccountinfo)&gt; | 是   | 回调函数。如果创建成功，err为null，data为新创建的系统帐号的信息；否则为错误对象。 |

**错误码：**

| 错误码ID  | 错误信息                   |
| -------- | ------------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid localName or type. |
| 12300005 | Multi-user not supported. |
| 12300006 | Unsupported account type. |
| 12300007 | The number of account reaches the upper limit. |

**示例：**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  try {
    accountManager.createOsAccount('testName', account_osAccount.OsAccountType.NORMAL, (err, osAccountInfo)=>{
      console.log('createOsAccount err:' + JSON.stringify(err));
      console.log('createOsAccount osAccountInfo:' + JSON.stringify(osAccountInfo));
    });
  } catch (e) {
    console.log('createOsAccount exception:' + JSON.stringify(e));
  }
  ```

### createOsAccount

createOsAccount(localName: string, type: OsAccountType): Promise&lt;OsAccountInfo&gt;

创建一个系统帐号。使用Promise异步回调。 

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名    | 类型                            | 必填 | 说明                   |
| --------- | ------------------------------- | ---- | ---------------------- |
| localName | string                          | 是   | 创建的系统帐号的名称。 |
| type      | [OsAccountType](#osaccounttype) | 是   | 创建的系统帐号的类型。 |

**返回值：**

| 类型                                           | 说明                                  |
| ---------------------------------------------- | ------------------------------------- |
| Promise&lt;[OsAccountInfo](#osaccountinfo)&gt; | Promise对象，返回新创建的系统帐号的信息。 |

**错误码：**

| 错误码ID  | 错误信息                   |
| -------- | ------------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid localName or type. |
| 12300005 | Multi-user not supported. |
| 12300006 | Unsupported account type. |
| 12300007 | The number of account reaches the upper limit. |

**示例：**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  try {
    accountManager.createOsAccount('testAccountName', account_osAccount.OsAccountType.NORMAL).then((accountInfo) => {
      console.log('createOsAccount, accountInfo: ' + JSON.stringify(accountInfo));
    }).catch((err) => {
      console.log('createOsAccount err: '  + JSON.stringify(err));
    });
  } catch (e) {
    console.log('createOsAccount exception:' + JSON.stringify(e));
  }
  ```

### createOsAccountForDomain<sup>8+</sup>

createOsAccountForDomain(type: OsAccountType, domainInfo: DomainAccountInfo, callback: AsyncCallback&lt;OsAccountInfo&gt;): void

根据域帐号信息，创建一个系统帐号并将其与域帐号关联。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名     | 类型                                                 | 必填 | 说明                                                                         |
| ---------- | ---------------------------------------------------- | ---- | -------------------------------------------------------------------------- |
| type       | [OsAccountType](#osaccounttype)                      | 是   | 创建的系统帐号的类型。                                                       |
| domainInfo | [DomainAccountInfo](#domainaccountinfo8)              | 是   | 域帐号信息。                                                               |
| callback   | AsyncCallback&lt;[OsAccountInfo](#osaccountinfo)&gt; | 是   | 回调函数。如果创建成功，err为null，data为新创建的系统帐号的信息；否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息                     |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid type or domainInfo. |
| 12300005 | Multi-user not supported. |
| 12300006 | Unsupported account type. |
| 12300007 | The number of account reaches the upper limit. |

**示例：**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let domainInfo = {domain: 'testDomain', accountName: 'testAccountName'};
  try {
    accountManager.createOsAccountForDomain(account_osAccount.OsAccountType.NORMAL, domainInfo, (err, osAccountInfo)=>{
      console.log('createOsAccountForDomain err:' + JSON.stringify(err));
      console.log('createOsAccountForDomain osAccountInfo:' + JSON.stringify(osAccountInfo));
    });
  } catch (e) {
    console.log('createOsAccountForDomain exception:' + JSON.stringify(e));
  }
  ```

### createOsAccountForDomain<sup>8+</sup>

createOsAccountForDomain(type: OsAccountType, domainInfo: DomainAccountInfo): Promise&lt;OsAccountInfo&gt;

根据传入的域帐号信息，创建与其关联的系统帐号。使用Promise异步回调。 

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名     | 类型                                      | 必填 | 说明                 |
| ---------- | ---------------------------------------- | ---- | -------------------- |
| type       | [OsAccountType](#osaccounttype)          | 是   | 创建的系统帐号的类型。 |
| domainInfo | [DomainAccountInfo](#domainaccountinfo8) | 是   | 域帐号信息。          |

**返回值：**

| 类型                                           | 说明                                    |
| ---------------------------------------------- | -------------------------------------- |
| Promise&lt;[OsAccountInfo](#osaccountinfo)&gt; | Promise对象，返回新创建的系统帐号的信息。 |

**错误码：**

| 错误码ID | 错误信息                     |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid type or domainInfo. |
| 12300005 | Multi-user not supported. |
| 12300006 | Unsupported account type. |
| 12300007 | The number of account reaches the upper limit. |

**示例：**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let domainInfo = {domain: 'testDomain', accountName: 'testAccountName'};
  try {
    accountManager.createOsAccountForDomain(account_osAccount.OsAccountType.NORMAL, domainInfo).then((accountInfo) => {
      console.log('createOsAccountForDomain, account info: ' + JSON.stringify(accountInfo));
    }).catch((err) => {
      console.log('createOsAccountForDomain err: '  + JSON.stringify(err));
    });
  } catch (e) {
    console.log('createOsAccountForDomain exception:' + JSON.stringify(e));
  }
  ```

### getCurrentOsAccount<sup>9+</sup>

getCurrentOsAccount(callback: AsyncCallback&lt;OsAccountInfo&gt;): void

查询当前进程所属的系统帐号的信息。使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                                           |
| -------- | ---------------------------------------------------- | ---- | ---------------------------------------------- |
| callback | AsyncCallback&lt;[OsAccountInfo](#osaccountinfo)&gt; | 是   | 回调函数。如果查询成功，err为null，data为当前进程所属的系统帐号信息；否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 12300001 | System service exception. |

**示例：**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  try {
    accountManager.getCurrentOsAccount((err, curAccountInfo)=>{
      console.log('getCurrentOsAccount err:' + JSON.stringify(err));
      console.log('getCurrentOsAccount curAccountInfo:' + JSON.stringify(curAccountInfo));
    });
  } catch (e) {
    console.log('getCurrentOsAccount exception:' + JSON.stringify(e));
  }
  ```

### getCurrentOsAccount<sup>9+</sup>

getCurrentOsAccount(): Promise&lt;OsAccountInfo&gt;

查询当前进程所属的系统帐号的信息。使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**返回值：**

| 类型                                           | 说明                                       |
| ---------------------------------------------- | ----------------------------------------- |
| Promise&lt;[OsAccountInfo](#osaccountinfo)&gt; | Promise对象，返回当前进程所属的系统帐号信息。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 12300001 | System service exception. |

**示例：**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  try {
    accountManager.getCurrentOsAccount().then((accountInfo) => {
      console.log('getCurrentOsAccount, accountInfo: ' + JSON.stringify(accountInfo));
    }).catch((err) => {
      console.log('getCurrentOsAccount err: '  + JSON.stringify(err));
    });
  } catch (e) {
    console.log('getCurrentOsAccount exception:' + JSON.stringify(e));
  }
  ```

### queryOsAccountById

queryOsAccountById(localId: number, callback: AsyncCallback&lt;OsAccountInfo&gt;): void

查询指定系统帐号的信息。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS 或 ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS_EXTENSION

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                                                                       |
| -------- | ---------------------------------------------------- | ---- | ------------------------------------------------------------------------ |
| localId  | number                                               | 是   | 要查询的系统帐号的ID。                                                      |
| callback | AsyncCallback&lt;[OsAccountInfo](#osaccountinfo)&gt; | 是   | 回调函数。如果查询成功，err为null，data为查到的系统帐号的信息；否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid localId.    |
| 12300003 | Account not found. |

**示例：** 查询ID为100的系统帐号信息

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let localId = 100;
  try {
    accountManager.queryOsAccountById(localId, (err, accountInfo)=>{
      console.log('queryOsAccountById err:' + JSON.stringify(err));
      console.log('queryOsAccountById accountInfo:' + JSON.stringify(accountInfo));
    });
  } catch (e) {
    console.log('queryOsAccountById exception:' + JSON.stringify(e));
  }
  ```

### queryOsAccountById

queryOsAccountById(localId: number): Promise&lt;OsAccountInfo&gt;

查询指定系统帐号的信息。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS 或 ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS_EXTENSION

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名  | 类型   | 必填 | 说明                 |
| ------- | ------ | ---- | -------------------- |
| localId | number | 是   | 要查询的系统帐号的ID |

**返回值：**

| 类型                                           | 说明                                 |
| ---------------------------------------------- | ------------------------------------ |
| Promise&lt;[OsAccountInfo](#osaccountinfo)&gt; | Promise对象，返回查到的系统帐号的信息。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid localId.    |
| 12300003 | Account not found. |

**示例：** 查询ID为100的系统帐号信息

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let localId = 100;
  try {
    accountManager.queryOsAccountById(localId).then((accountInfo) => {
      console.log('queryOsAccountById, accountInfo: ' + JSON.stringify(accountInfo));
    }).catch((err) => {
      console.log('queryOsAccountById err: '  + JSON.stringify(err));
    });
  } catch (e) {
    console.log('queryOsAccountById exception:' + JSON.stringify(e));
  }
  ```

### getOsAccountType<sup>9+</sup>

getOsAccountType(callback: AsyncCallback&lt;OsAccountType&gt;): void

查询当前进程所属的系统帐号的帐号类型。使用callback异步回调。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                                                 |
| -------- | ---------------------------------------------------- | ---- | ---------------------------------------------------- |
| callback | AsyncCallback&lt;[OsAccountType](#osaccounttype)&gt; | 是   | 回调函数。如果查询成功，err为null，data为当前进程所属的系统帐号的帐号类型；否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 12300001 | System service exception. |

**示例：**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  try {
    accountManager.getOsAccountType((err, accountType) => {
      console.log('getOsAccountType err: ' + JSON.stringify(err));
      console.log('getOsAccountType accountType: ' + accountType);
    });
  } catch (e) {
    console.log('getOsAccountType exception: ' + JSON.stringify(e));
  }
  ```

### getOsAccountType<sup>9+</sup>

getOsAccountType(): Promise&lt;OsAccountType&gt;

查询当前进程所属的系统帐号的帐号类型。使用Promise异步回调。

**系统能力：** SystemCapability.Account.OsAccount

**返回值：**

| 类型                                           | 说明                                             |
| ---------------------------------------------- | ----------------------------------------------- |
| Promise&lt;[OsAccountType](#osaccounttype)&gt; | Promise对象，返回当前进程所属的系统帐号的帐号类型。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 12300001 | System service exception. |

**示例：**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  try {
    accountManager.getOsAccountType().then((accountType) => {
      console.log('getOsAccountType, accountType: ' + accountType);
    }).catch((err) => {
      console.log('getOsAccountType err: '  + JSON.stringify(err));
    });
  } catch (e) {
    console.log('getOsAccountType exception: ' + JSON.stringify(e));
  }
  ```

### queryDistributedVirtualDeviceId<sup>9+</sup>

queryDistributedVirtualDeviceId(callback: AsyncCallback&lt;string&gt;): void

获取分布式虚拟设备ID。使用callback异步回调。

**需要权限：** ohos.permission.DISTRIBUTED_DATASYNC or ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                                                   |
| -------- | --------------------------- | ---- | --------------------------------------------------------------------- |
| callback | AsyncCallback&lt;string&gt; | 是   | 回调函数。如果获取成功，err为null，data为分布式虚拟设备ID；否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 12300001 | System service exception. |

**示例：**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  try {
    accountManager.queryDistributedVirtualDeviceId((err, virtualID) => {
      console.log('queryDistributedVirtualDeviceId err: ' + JSON.stringify(err));
      console.log('queryDistributedVirtualDeviceId virtualID: ' + virtualID);
    });
  } catch (e) {
    console.log('queryDistributedVirtualDeviceId exception: ' + JSON.stringify(e));
  }
  ```

### queryDistributedVirtualDeviceId<sup>9+</sup>

queryDistributedVirtualDeviceId(): Promise&lt;string&gt;

获取分布式虚拟设备ID。使用Promise异步回调。

**需要权限：** ohos.permission.DISTRIBUTED_DATASYNC or ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**返回值：**

| 类型                  | 说明                              |
| --------------------- | --------------------------------- |
| Promise&lt;string&gt; | Promise对象，返回分布式虚拟设备ID。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 12300001 | System service exception. |

**示例：**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  try {
    accountManager.queryDistributedVirtualDeviceId().then((virtualID) => {
      console.log('queryDistributedVirtualDeviceId, virtualID: ' + virtualID);
    }).catch((err) => {
      console.log('queryDistributedVirtualDeviceId err: '  + JSON.stringify(err));
    });
  } catch (e) {
    console.log('queryDistributedVirtualDeviceId exception: ' + JSON.stringify(e));
  }
  ```

### getOsAccountProfilePhoto

getOsAccountProfilePhoto(localId: number, callback: AsyncCallback&lt;string&gt;): void

获取指定系统帐号的头像信息。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                                                         |
| -------- | --------------------------- | ---- | -------------------------------------------------------------------------- |
| localId  | number                      | 是   | 系统帐号ID。                                                                |
| callback | AsyncCallback&lt;string&gt; | 是   | 回调函数。如果获取成功，err为null，data为指定系统帐号的头像信息；否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid localId.    |
| 12300003 | Account not found. |

**示例：** 获取ID为100的系统帐号的头像

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let localId = 100;
  try {
    accountManager.getOsAccountProfilePhoto(localId, (err, photo)=>{
      console.log('getOsAccountProfilePhoto err:' + JSON.stringify(err));
      console.log('get photo:' + photo + ' by localId: ' + localId);
    });
  } catch (e) {
    console.log('getOsAccountProfilePhoto exception:' + JSON.stringify(e));
  }
  ```

### getOsAccountProfilePhoto

getOsAccountProfilePhoto(localId: number): Promise&lt;string&gt;

获取指定系统帐号的头像信息。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名  | 类型   | 必填 | 说明         |
| ------- | ------ | ---- | ------------ |
| localId | number | 是   | 系统帐号ID。 |

**返回值：**

| 类型                  | 说明                                    |
| --------------------- | -------------------------------------- |
| Promise&lt;string&gt; | Promise对象，返回指定系统帐号的头像信息。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid localId.    |
| 12300003 | Account not found. |

**示例：** 获取ID为100的系统帐号的头像

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let localId = 100;
  try {
    accountManager.getOsAccountProfilePhoto(localId).then((photo) => {
      console.log('getOsAccountProfilePhoto: ' + photo);
    }).catch((err) => {
      console.log('getOsAccountProfilePhoto err: '  + JSON.stringify(err));
    });
  } catch (e) {
    console.log('getOsAccountProfilePhoto exception:' + JSON.stringify(e));
  }
  ```

### setOsAccountProfilePhoto

setOsAccountProfilePhoto(localId: number, photo: string, callback: AsyncCallback&lt;void&gt;): void

为指定系统帐号设置头像信息。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                      | 必填 | 说明         |
| -------- | ------------------------- | ---- | ------------ |
| localId  | number                    | 是   | 系统帐号ID。 |
| photo    | string                    | 是   | 头像信息。   |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。如果设置成功，err为null，否则为错误对象。  |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid localId or photo.    |
| 12300003 | Account not found. |
| 12300008 | Restricted Account. |

**示例：** 给ID为100的系统帐号设置头像

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let localId = 100;
  let photo = 'data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAA0AAAAPCAYAAAA/I0V3AAAAAXNSR0IArs4c6QAAAARnQU1BAA'+
  'Cxjwv8YQUAAAAJcEhZcwAADsMAAA7DAcdvqGQAAACwSURBVDhPvZLBDYMwDEV/ugsXRjAT0EHCOuFIBwkbdIRewi6unbiAyoGgSn1SFH85+Y'+
  'q/4ljARW62X+LHS8uIzjm4dXUYF+utzBikB52Jo5e5iEPKqpACk7R9NM2RvWm5tIkD2czLCUFNKLD6IjdMHFHDzws285MgGrT0xCtp3WOKHo'+
  '+7q0mP0DZW9pNmoEFUzrQjp5cCnaen2kSJXLFD8ghbXyZCMQf/8e8Ns1XVAG/XAgqKzVnJFAAAAABJRU5ErkJggg=='
  try {
    accountManager.setOsAccountProfilePhoto(localId, photo, (err)=>{
      console.log('setOsAccountProfilePhoto err:' + JSON.stringify(err));
    });
  } catch (e) {
    console.log('setOsAccountProfilePhoto exception:' + JSON.stringify(e));
  }
  ```

### setOsAccountProfilePhoto

setOsAccountProfilePhoto(localId: number, photo: string): Promise&lt;void&gt;

为指定系统帐号设置头像信息。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名  | 类型   | 必填 | 说明         |
| ------- | ------ | ---- | ------------ |
| localId | number | 是   | 系统帐号ID。 |
| photo   | string | 是   | 头像信息。   |

**返回值：**

| 类型                | 说明                                 |
| ------------------- | ------------------------------------ |
| Promise&lt;void&gt; | Promise对象，无返回结果的Promise对象。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid localId or photo.    |
| 12300003 | Account not found. |
| 12300008 | Restricted Account. |

**示例：** 给ID为100的系统帐号设置头像

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let localId = 100;
  let photo = 'data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAA0AAAAPCAYAAAA/I0V3AAAAAXNSR0IArs4c6QAAAARnQU1BAA'+
  'Cxjwv8YQUAAAAJcEhZcwAADsMAAA7DAcdvqGQAAACwSURBVDhPvZLBDYMwDEV/ugsXRjAT0EHCOuFIBwkbdIRewi6unbiAyoGgSn1SFH85+Y'+
  'q/4ljARW62X+LHS8uIzjm4dXUYF+utzBikB52Jo5e5iEPKqpACk7R9NM2RvWm5tIkD2czLCUFNKLD6IjdMHFHDzws285MgGrT0xCtp3WOKHo'+
  '+7q0mP0DZW9pNmoEFUzrQjp5cCnaen2kSJXLFD8ghbXyZCMQf/8e8Ns1XVAG/XAgqKzVnJFAAAAABJRU5ErkJggg=='
  try {
    accountManager.setOsAccountProfilePhoto(localId, photo).then(() => {
      console.log('setOsAccountProfilePhoto success');
    }).catch((err) => {
      console.log('setOsAccountProfilePhoto err: '  + JSON.stringify(err));
    });
  } catch (e) {
    console.log('setOsAccountProfilePhoto exception:' + JSON.stringify(e));
  }
  ```

### queryOsAccountLocalIdBySerialNumber<sup>9+</sup>

queryOsAccountLocalIdBySerialNumber(serialNumber: number, callback: AsyncCallback&lt;number&gt;): void

通过SN码查询与其关联的系统帐号的帐号ID。使用callback异步回调。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名       | 类型                        | 必填 | 说明                                                                           |
| ------------ | --------------------------- | ---- | ---------------------------------------------------------------------------- |
| serialNumber | number                      | 是   | 帐号SN码。                                                                    |
| callback     | AsyncCallback&lt;number&gt; | 是   | 回调函数。如果成功，err为null，data为与SN码关联的系统帐号的帐号ID；否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息               |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid serialNumber. |
| 12300003 | Account not found. |

**示例：** 查询与SN码12345关联的系统帐号的ID

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let serialNumber = 12345;
  try {
    accountManager.queryOsAccountLocalIdBySerialNumber(serialNumber, (err, localId)=>{
      console.log('ger localId err:' + JSON.stringify(err));
      console.log('get localId:' + localId + ' by serialNumber: ' + serialNumber);
    });
  } catch (e) {
    console.log('ger localId exception:' + JSON.stringify(e));
  }
  ```

### queryOsAccountLocalIdBySerialNumber<sup>9+</sup>

queryOsAccountLocalIdBySerialNumber(serialNumber: number): Promise&lt;number&gt;

通过SN码查询与其关联的系统帐号的帐号ID。使用Promise异步回调。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名       | 类型   | 必填 | 说明       |
| ------------ | ------ | ---- | ---------- |
| serialNumber | number | 是   | 帐号SN码。 |

**返回值：**

| 类型                  | 说明                                         |
| --------------------- | -------------------------------------------- |
| Promise&lt;number&gt; | Promise对象，返回与SN码关联的系统帐号的帐号ID。 |

**错误码：**

| 错误码ID | 错误信息               |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid serialNumber. |
| 12300003 | Account not found. |

**示例：** 查询与SN码12345关联的系统帐号的ID

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let serialNumber = 12345;
  try {
    accountManager.queryOsAccountLocalIdBySerialNumber(serialNumber).then((localId) => {
      console.log('queryOsAccountLocalIdBySerialNumber localId: ' + localId);
    }).catch((err) => {
      console.log('queryOsAccountLocalIdBySerialNumber err: '  + JSON.stringify(err));
    });
  } catch (e) {
    console.log('queryOsAccountLocalIdBySerialNumber exception: '  + JSON.stringify(e));
  }
  ```

### querySerialNumberByOsAccountLocalId<sup>9+</sup>

querySerialNumberByOsAccountLocalId(localId: number, callback: AsyncCallback&lt;number&gt;): void

通过系统帐号ID获取与该系统帐号关联的SN码。使用callback异步回调。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                                                         |
| -------- | --------------------------- | ---- | -------------------------------------------------------------------------- |
| localId  | number                      | 是   | 系统帐号ID。                                                                 |
| callback | AsyncCallback&lt;number&gt; | 是   | 回调函数。如果获取成功，err为null，data为与该系统帐号关联的SN码；否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid localId.    |
| 12300003 | Account not found. |

**示例：** 获取ID为100的系统帐号关联的SN码

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let localId = 100;
  try {
    accountManager.querySerialNumberByOsAccountLocalId(localId, (err, serialNumber)=>{
      console.log('ger serialNumber err:' + JSON.stringify(err));
      console.log('get serialNumber:' + serialNumber + ' by localId: ' + localId);
    });
  } catch (e) {
    console.log('ger serialNumber exception:' + JSON.stringify(e));
  }
  ```

### querySerialNumberByOsAccountLocalId<sup>9+</sup>

querySerialNumberByOsAccountLocalId(localId: number): Promise&lt;number&gt;

通过系统帐号ID获取与该系统帐号关联的SN码。使用Promise异步回调。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名  | 类型   | 必填 | 说明          |
| ------- | ------ | ---- | ----------- |
| localId | number | 是   | 系统帐号ID。 |

**返回值：**

| 类型                  | 说明                                    |
| :-------------------- | :------------------------------------- |
| Promise&lt;number&gt; | Promise对象，返回与该系统帐号关联的SN码。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid localId.    |
| 12300003 | Account not found. |

**示例：** 获取ID为100的系统帐号关联的SN码

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let localId = 100;
  try {
    accountManager.querySerialNumberByOsAccountLocalId(localId).then((serialNumber) => {
      console.log('querySerialNumberByOsAccountLocalId serialNumber: ' + serialNumber);
    }).catch((err) => {
      console.log('querySerialNumberByOsAccountLocalId err: '  + JSON.stringify(err));
    });
  } catch (e) {
    console.log('querySerialNumberByOsAccountLocalId exception:' + JSON.stringify(e));
  }
  ```

### on

on(type: 'activate' | 'activating', name: string, callback: Callback&lt;number&gt;): void

订阅系统帐号的激活完成与激活中的事件。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS_EXTENSION

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                       | 必填 | 说明                                                         |
| -------- | -------------------------- | ---- | ------------------------------------------------------------ |
| type     | 'activate' \| 'activating' | 是   | 订阅类型，activate表示订阅的是帐号已激活完成的事件，activating表示订阅的是帐号正在激活的事件。 |
| name     | string                     | 是   | 订阅名称，可自定义，要求非空且长度不超过1024字节。           |
| callback | Callback&lt;number&gt;     | 是   | 订阅系统帐号激活完成与激活中的事件回调，表示激活完成后或正在激活中的系统帐号ID。    |

**错误码：**

| 错误码ID | 错误信息       |
| -------- | ------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid type or name. |
| 12300011 | Callback has been registered. |

**示例：**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  function onCallback(receiveLocalId){
    console.log('receive localId:' + receiveLocalId);
  }
  try {
    accountManager.on('activating', 'osAccountOnOffNameA', onCallback);
  } catch (e) {
    console.log('receive localId exception:' + JSON.stringify(e));
  }
  ```

### off

off(type: 'activate' | 'activating', name: string, callback?: Callback&lt;number&gt;): void

取消订阅系统帐号的激活完成与激活中的事件。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS_EXTENSION

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                       | 必填 | 说明                                                         |
| -------- | -------------------------- | ---- | ------------------------------------------------------------ |
| type     | 'activate' \| 'activating' | 是   | 取消订阅类型，activate表示取消订阅帐号已激活完成的事件，activating取消订阅帐号正在激活的事件。 |
| name     | string                     | 是   | 订阅名称，可自定义，，要求非空且长度不超过1024字节，需要与订阅接口传入的值保持一致。 |
| callback | Callback&lt;number&gt;     | 否   | 取消订阅系统帐号激活完成与激活中的事件回调，默认返回0。                      |

**错误码：**

| 错误码ID | 错误信息       |
| -------- | ------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid type or name. |
| 12300012 | Callback has not been registered. |

**示例：**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  function offCallback(){
    console.log('off enter')
  }
  try {
    accountManager.off('activating', 'osAccountOnOffNameA', offCallback);
  } catch (e) {
    console.log('off exception:' + JSON.stringify(e));
  }
  ```

### getBundleIdFromUid<sup>9+</sup>

getBundleIdFromUid(uid: number, callback: AsyncCallback&lt;number&gt;): void;

通过uid查询对应的bundleId，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                       | 必填 | 说明                                                                        |
| -------- | --------------------------- | ---- | ------------------------------------------------------------------------ |
| uid      | number                      | 是   | 进程uid。                                                                 |
| callback | AsyncCallback&lt;number&gt; | 是   | 回调函数。如果查询成功，err为null，data为与uid对应的bundleId；否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息       |
| -------- | ------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid uid. |

**示例：**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let testUid = 1000000;
  try {
    accountManager.getBundleIdFromUid(testUid, (err, bundleId) => {
      console.info('getBundleIdFromUid errInfo:' + JSON.stringify(err));
      console.info('getBundleIdFromUid bundleId:' + JSON.stringify(bundleId));
    });
  } catch (e) {
    console.info('getBundleIdFromUid exception:' + JSON.stringify(e));
  }
  ```
### getBundleIdFromUid<sup>9+</sup>

getBundleIdFromUid(uid: number): Promise&lt;number&gt;;

通过uid查询对应的bundleId，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名  | 类型   | 必填 | 说明         |
| ------- | ------ | ---- | ------------ |
| uid     | number | 是   |  进程uid。 |

**返回值：**

| 类型                  | 说明                                  |
| --------------------- | ------------------------------------ |
| Promise&lt;number&gt; | Promise对象，返回与uid对应的bundleId。 |

**错误码：**

| 错误码ID | 错误信息       |
| -------- | ------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid uid. |

**示例：**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let testUid = 1000000;
  try {
    accountManager.getBundleIdFromUid(testUid).then((result) => {
      console.info('getBundleIdFromUid bundleId:' + JSON.stringify(result));
    }).catch((err)=>{
      console.info('getBundleIdFromUid errInfo:' + JSON.stringify(err));
    });
  } catch (e) {
    console.info('getBundleIdFromUid exception:' + JSON.stringify(e));
  }
  ```

### isMainOsAccount<sup>9+</sup>

isMainOsAccount(callback: AsyncCallback&lt;boolean&gt;): void;

查询当前进程是否处于主用户，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                          | 必填 | 说明                                                               |
| -------- | ---------------------------- | ---- | ----------------------------------------------------------------- |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调函数，返回true表示当前帐号为主帐号，返回false表示当前帐号非主帐号。 |

**错误码：**

| 错误码ID | 错误信息       |
| -------- | ------------- |
| 12300001 | System service exception. |

**示例：**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  try {
    accountManager.isMainOsAccount((err,result)=>{
      console.info('isMainOsAccount errInfo:' + JSON.stringify(err));
      console.info('isMainOsAccount result:' + JSON.stringify(result));
    });
  } catch (e) {
    console.info('isMainOsAccount exception:' + JSON.stringify(e));
  }
  ```
### isMainOsAccount<sup>9+</sup>

isMainOsAccount(): Promise&lt;boolean&gt;;

查询当前进程是否处于主用户，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**返回值：**

| 类型                   | 说明                                                                  |
| ---------------------- | --------------------------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise对象，返回true表示当前帐号为主帐号，返回false表示当前帐号非主帐号。 |

**错误码：**

| 错误码ID | 错误信息       |
| -------- | ------------- |
| 12300001 | System service exception. |

**示例：**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  try {
    accountManager.isMainOsAccount().then((result) => {
      console.info('isMainOsAccount result:' + JSON.stringify(result));
    }).catch((err)=>{
      console.info('isMainOsAccount errInfo:' + JSON.stringify(err));
    });
  } catch (e) {
    console.info('isMainOsAccount exception:' + JSON.stringify(e));
  }
  ```
### queryOsAccountConstraintSourceTypes<sup>9+</sup>

queryOsAccountConstraintSourceTypes(localId: number, constraint: string, callback: AsyncCallback&lt;Array&lt;ConstraintSourceTypeInfo&gt;&gt;): void;

查询指定系统帐号的指定约束来源信息，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                       | 必填 | 说明                                                         |
| -------- | -------------------------- | ---- | ------------------------------------------------------------ |
| localId     | number | 是   |  要查询的系统帐号ID |
| constraint     | string | 是   |  要查询的[约束](#系统帐号约束列表)名称 |
| callback | AsyncCallback&lt;Array&lt;[ConstraintSourceTypeInfo](#constraintsourcetypeinfo)&gt;&gt;     | 是   | 回调函数。如果成功，err为null，data为指定系统帐号的指定[约束](#系统帐号约束列表)来源信息；否则为错误对象。                      |

**错误码：**

| 错误码ID | 错误信息       |
| -------- | ------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid localId or constraint. |
| 12300003 | Account not found. |

**示例：**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  try {
    accountManager.queryOsAccountConstraintSourceTypes(100, 'constraint.wifi',(err,sourceTypeInfos)=>{
      console.info('queryOsAccountConstraintSourceType errInfo:' + JSON.stringify(err));
      console.info('queryOsAccountConstraintSourceType sourceTypeInfos:' + JSON.stringify(sourceTypeInfos));
    });
  } catch (e) {
    console.info('queryOsAccountConstraintSourceType exception:' + JSON.stringify(e));
  }
  ```

### queryOsAccountConstraintSourceTypes<sup>9+</sup>

queryOsAccountConstraintSourceTypes(localId: number, constraint: string): Promise&lt;Array&lt;ConstraintSourceTypeInfo&gt;&gt;;

查询指定系统帐号的指定约束来源信息，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名  | 类型   | 必填 | 说明         |
| ------- | ------ | ---- | ------------ |
| localId     | number | 是   |  要查询的系统帐号ID |
| constraint     | string | 是   |  要查询的[约束](#系统帐号约束列表)名称 |

**返回值：**

| 类型                  | 说明                                                         |
| --------------------- | ------------------------------------------------------------ |
| Promise&lt;Array&lt;[ConstraintSourceTypeInfo](#constraintsourcetypeinfo)&gt;&gt; | Promise对象，返回指定系统帐号的指定[约束](#系统帐号约束列表)来源信息。 |

**错误码：**

| 错误码ID | 错误信息       |
| -------- | ------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid localId or constraint. |
| 12300003 | Account not found. |

**示例：**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  try {
    accountManager.queryOsAccountConstraintSourceTypes(100, 'constraint.wifi').then((result) => {
      console.info('queryOsAccountConstraintSourceType sourceTypeInfos:' + JSON.stringify(result));
    }).catch((err)=>{
      console.info('queryOsAccountConstraintSourceType errInfo:' + JSON.stringify(err));
    });
  } catch (e) {
    console.info('queryOsAccountConstraintSourceType exception:' + JSON.stringify(e));
  }
  ```

### isMultiOsAccountEnable<sup>(deprecated)</sup>

isMultiOsAccountEnable(callback: AsyncCallback&lt;boolean&gt;): void

判断是否支持多系统帐号。使用callback异步回调。

> **说明：** 
>
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[checkMultiOsAccountEnabled](#checkmultiosaccountenabled9)。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                         | 必填 | 说明                                                     |
| -------- | ---------------------------- | ---- | ------------------------------------------------------ |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调函数。返回true表示支持多系统帐号；返回false表示不支持。 |

**示例：**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  accountManager.isMultiOsAccountEnable((err, isEnabled) => {
    if (err) {
      console.log("isMultiOsAccountEnable failed, error: " + JSON.stringify(err));
    } else {
    console.log("isMultiOsAccountEnable successfully, isEnabled: " + isEnabled);
    }
  });
  ```

### isMultiOsAccountEnable<sup>(deprecated)</sup>

isMultiOsAccountEnable(): Promise&lt;boolean&gt;

判断是否支持多系统帐号。使用Promise异步回调。

> **说明：** 
>
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[checkMultiOsAccountEnabled](#checkmultiosaccountenabled9-1)。

**系统能力：** SystemCapability.Account.OsAccount

**返回值：**

| 类型                   | 说明                                                       |
| :--------------------- | :--------------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise对象。返回true表示支持多系统帐号；返回false表示不支持。 |

**示例：**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  accountManager.isMultiOsAccountEnable().then((isEnabled) => {
    console.log('isMultiOsAccountEnable successfully, isEnabled: ' + isEnabled);
  }).catch((err) => {
    console.log('isMultiOsAccountEnable failed, error: '  + JSON.stringify(err));
  });
  ```


### isOsAccountActived<sup>(deprecated)</sup>

isOsAccountActived(localId: number, callback: AsyncCallback&lt;boolean&gt;): void

判断指定系统帐号是否处于激活状态。使用callback异步回调。

> **说明：** 
>
> 从 API version 7开始支持从API version 9开始废弃, 建议使用[checkOsAccountActivated](#checkosaccountactivated9)。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS 或 ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                         | 必填 | 说明                                                     |
| -------- | ---------------------------- | ---- | ------------------------------------------------------ |
| localId  | number                       | 是   | 系统帐号ID。                                            |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调函数。返回true表示帐号已激活；返回false表示帐号未激活。 |

**示例：** 判断ID为100的系统帐号是否处于激活状态

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let localId = 100;
  accountManager.isOsAccountActived(localId, (err, isActived) => {
    if (err) {
      console.log('isOsAccountActived failed, err:' + JSON.stringify(err));
    } else {
      console.log('isOsAccountActived successfully, isActived:' + isActived);
    }
  });
  ```

### isOsAccountActived<sup>(deprecated)</sup>

isOsAccountActived(localId: number): Promise&lt;boolean&gt;

判断指定系统帐号是否处于激活状态。使用Promise异步回调。

> **说明：** 
>
> 从 API version 7开始支持从API version 9开始废弃, 建议使用[checkOsAccountActivated](#checkosaccountactivated9-1)。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS 或 ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名  | 类型   | 必填 | 说明                               |
| ------- | ------ | ---- | --------------------------------- |
| localId | number | 是   | 系统帐号ID。 |

**返回值：**

| 类型                   | 说明                                                        |
| --------------------- | ----------------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise对象。返回true表示帐号已激活；返回false表示帐号未激活。 |

**示例：** 判断ID为100的系统帐号是否处于激活状态

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let localId = 100;
  accountManager.isOsAccountActived(localId).then((isActived) => {
    console.log('isOsAccountActived successfully, isActived: ' + isActived);
  }).catch((err) => {
    console.log('isOsAccountActived failed, error: '  + JSON.stringify(err));
  });
  ```

### isOsAccountConstraintEnable<sup>(deprecated)</sup>

isOsAccountConstraintEnable(localId: number, constraint: string, callback: AsyncCallback&lt;boolean&gt;): void

判断指定系统帐号是否具有指定约束。使用callback异步回调。

> **说明：** 
>
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[checkConstraintEnabled](#checkconstraintenabled9)。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名     | 类型                         | 必填 | 说明                                                                |
| ---------- | ---------------------------- | ---- | ----------------------------------------------------------------- |
| localId    | number                       | 是   | 系统帐号ID。                                 |
| constraint | string                       | 是   | 指定的[约束](#系统帐号约束列表)名称。                                |
| callback   | AsyncCallback&lt;boolean&gt; | 是   | 回调函数。返回true表示已使能指定的约束；返回false表示未使能指定的约束。 |

**示例：** 判断ID为100的系统帐号是否有禁止使用Wi-Fi的约束

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let localId = 100;
  let constraint = "constraint.wifi";
  accountManager.isOsAccountConstraintEnable(localId, constraint, (err, isEnabled) => {
    if (err) {
      console.log("isOsAccountConstraintEnable failed, error:" + JSON.stringify(err));
    } else {
      console.log("isOsAccountConstraintEnable successfully, isEnabled:" + isEnabled);
    }
  });
  ```

### isOsAccountConstraintEnable<sup>(deprecated)</sup>

isOsAccountConstraintEnable(localId: number, constraint: string): Promise&lt;boolean&gt;

判断指定系统帐号是否具有指定约束。使用Promise异步回调。

> **说明：** 
>
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[checkConstraintEnabled](#checkconstraintenabled9-1)。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名     | 类型   | 必填 | 说明                                 |
| ---------- | ------ | ---- | ---------------------------------- |
| localId    | number | 是   | 系统帐号ID。  |
| constraint | string | 是   | 指定的[约束](#系统帐号约束列表)名称。 |

**返回值：**

| 类型                   | 说明                                                                   |
| ---------------------- | --------------------------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise对象。返回true表示已使能指定的约束；返回false表示未使能指定的约束。 |

**示例：** 判断ID为100的系统帐号是否有禁止使用Wi-Fi的约束

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let localId = 100;
  let constraint = "constraint.wifi";
  accountManager.isOsAccountConstraintEnable(localId, constraint).then((isEnabled) => {
    console.log("isOsAccountConstraintEnable successfully, isEnabled: " + isEnabled);
  }).catch((err) => {
    console.log("isOsAccountConstraintEnable err: "  + JSON.stringify(err));
  });
  ```

### isTestOsAccount<sup>(deprecated)</sup>

isTestOsAccount(callback: AsyncCallback&lt;boolean&gt;): void

检查当前系统帐号是否为测试帐号。使用callback异步回调。

> **说明：** 
>
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[checkOsAccountTestable](#checkosaccounttestable9)。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                         | 必填 | 说明                                                                   |
| -------- | ---------------------------- | ---- | --------------------------------------------------------------------- |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调函数。返回true表示当前帐号为测试帐号；返回false表示当前帐号非测试帐号。 |

**示例：**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  accountManager.isTestOsAccount((err, isTestable) => {
    if (err) {
      console.log("isTestOsAccount failed, error: " + JSON.stringify(err));
    } else {
      console.log("isTestOsAccount successfully, isTestable: " + isTestable);
    }
  });
  ```

### isTestOsAccount<sup>(deprecated)</sup>

isTestOsAccount(): Promise&lt;boolean&gt;

检查当前系统帐号是否为测试帐号。使用Promise异步回调。

> **说明：** 
>
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[checkOsAccountTestable](#checkosaccounttestable9-1)。

**系统能力：** SystemCapability.Account.OsAccount

**返回值：**

| 类型                   | 说明                                                                      |
| ---------------------- | ------------------------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise对象。返回true表示当前帐号为测试帐号；返回false表示当前帐号非测试帐号。 |

**示例：**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  accountManager.isTestOsAccount().then((isTestable) => {
      console.log("isTestOsAccount successfully, isTestable: " + isTestable);
  }).catch((err) => {
      console.log("isTestOsAccount failed, error: " + JSON.stringify(err));
  });
  ```

### isOsAccountVerified<sup>(deprecated)</sup>

isOsAccountVerified(callback: AsyncCallback&lt;boolean&gt;): void

检查当前系统帐号是否已验证。使用callback异步回调。

> **说明：** 
>
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[checkOsAccountVerified](#checkosaccountverified9)。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS 或 ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                         | 必填 | 说明                                                            |
| -------- | ---------------------------- | ---- | ------------------------------------------------------------- |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调函数。返回true表示指定帐号已验证；返回false表示指定帐号未验证。 |

**示例：**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  accountManager.isOsAccountVerified((err, isVerified) => {
    if (err) {
      console.log("isOsAccountVerified failed, error: " + JSON.stringify(err));
    } else {
      console.log("isOsAccountVerified successfully, isVerified: " + isVerified);
    }
  });
  ```

### isOsAccountVerified<sup>(deprecated)</sup>

isOsAccountVerified(localId: number, callback: AsyncCallback&lt;boolean&gt;): void

检查指定系统帐号是否已验证。使用callback异步回调。

> **说明：** 
>
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[checkOsAccountVerified](#checkosaccountverified9-1)。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS 或 ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                         | 必填 | 说明                                                            |
| -------- | ---------------------------- | ---- | ------------------------------------------------------------- |
| localId  | number                       | 是   | 系统帐号ID。                             |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调函数。返回true表示指定帐号已验证；返回false表示指定帐号未验证。 |

**示例：**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let localId = 100;
  accountManager.isOsAccountVerified(localId, (err, isVerified) => {
    if (err) {
      console.log("isOsAccountVerified failed, error: " + JSON.stringify(err));
    } else {
      console.log("isOsAccountVerified successfully, isVerified: " + isVerified);
    }
  });
  ```

### isOsAccountVerified<sup>(deprecated)</sup>

isOsAccountVerified(localId?: number): Promise&lt;boolean&gt;

检查指定系统帐号是否已验证。使用Promise异步回调。

> **说明：** 
>
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[checkOsAccountVerified](#checkosaccountverified9-2)。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS 或 ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名  | 类型   | 必填 | 说明                                                              |
| ------- | ------ | ---- | ---------------------------------------------------------------- |
| localId | number | 否   | 系统帐号ID。不填则检查当前系统帐号是否已验证。 |

**返回值：**

| 类型                   | 说明                                                               |
| ---------------------- | ----------------------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise对象。返回true表示指定帐号已验证；返回false表示指定帐号未验证。 |

**示例：**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  accountManager.isOsAccountVerified(localId).then((isVerified) => {
    console.log("isOsAccountVerified successfully, isVerified: " + isVerified);
  }).catch((err) => {
    console.log("isOsAccountVerified failed, error: " + JSON.stringify(err));
  });
  ```

### getCreatedOsAccountsCount<sup>(deprecated)</sup>

getCreatedOsAccountsCount(callback: AsyncCallback&lt;number&gt;): void

获取已创建的系统帐号数量。使用callback异步回调。

> **说明：** 
>
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[getOsAccountCount](#getosaccountcount9)。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                                                         |
| -------- | --------------------------- | ---- | -------------------------------------------------------------------------- |
| callback | AsyncCallback&lt;number&gt; | 是   | 回调函数。当获取成功时，err为null，data为已创建的系统帐号的数量；否则为错误对象。 |

**示例：**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  accountManager.getCreatedOsAccountsCount((err, count)=>{
    if (err) {
      console.log("getCreatedOsAccountsCount failed, error: " + JSON.stringify(err));
    } else {
      console.log("getCreatedOsAccountsCount successfully, count: " + count);
    }
  });
  ```

### getCreatedOsAccountsCount<sup>(deprecated)</sup>

getCreatedOsAccountsCount(): Promise&lt;number&gt;

获取已创建的系统帐号数量，使用Promise异步回调。

> **说明：** 
>
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[getOsAccountCount](#getosaccountcount9-1)。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**返回值：**

| 类型                  | 说明                                    |
| --------------------- | -------------------------------------- |
| Promise&lt;number&gt; | Promise对象，返回已创建的系统帐号的数量。 |

**示例：**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  accountManager.getCreatedOsAccountsCount().then((count) => {
    console.log("getCreatedOsAccountsCount successfully, count: " + count);
  }).catch((err) => {
    console.log("getCreatedOsAccountsCount failed, error: "  + JSON.stringify(err));
  });
  ```

### getOsAccountLocalIdFromProcess<sup>(deprecated)</sup>

getOsAccountLocalIdFromProcess(callback: AsyncCallback&lt;number&gt;): void

获取当前进程所属的系统帐号ID，使用callback异步回调。

> **说明：** 
>
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[queryOsAccountLocalIdFromProcess](#queryosaccountlocalidfromprocess9)。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                                                           |
| -------- | --------------------------- | ---- | ---------------------------------------------------------------------------- |
| callback | AsyncCallback&lt;number&gt; | 是   | 回调函数。当获取成功时，err为null，data为当前进程所属的系统帐号ID；否则为错误对象。 |

**示例：**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  accountManager.getOsAccountLocalIdFromProcess((err, localId) => {
    if (err) {
      console.log("getOsAccountLocalIdFromProcess failed, error: " + JSON.stringify(err));
    } else {
      console.log("getOsAccountLocalIdFromProcess successfully, localId: " + localId);
    }
  });
  ```

### getOsAccountLocalIdFromProcess<sup>(deprecated)</sup>

getOsAccountLocalIdFromProcess(): Promise&lt;number&gt;

获取当前进程所属的系统帐号ID，使用Promise异步回调。

> **说明：**
>
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[queryOsAccountLocalIdFromProcess](#queryosaccountlocalidfromprocess9-1)。

**系统能力：** SystemCapability.Account.OsAccount

**返回值：**

| 类型                  | 说明                                      |
| :-------------------- | :--------------------------------------- |
| Promise&lt;number&gt; | Promise对象，返回当前进程所属的系统帐号ID。 |

**示例：**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  accountManager.getOsAccountLocalIdFromProcess().then((localId) => {
    console.log('getOsAccountLocalIdFromProcess successfully, localId: ' + localId);
  }).catch((err) => {
    console.log('getOsAccountLocalIdFromProcess failed, error: '  + JSON.stringify(err));
  });
  ```

### getOsAccountLocalIdFromUid<sup>(deprecated)</sup>

getOsAccountLocalIdFromUid(uid: number, callback: AsyncCallback&lt;number&gt;): void

根据uid查询对应的系统帐号ID。使用callback异步回调。

> **说明：** 
>
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[queryOsAccountLocalIdFromUid](#queryosaccountlocalidfromuid9)。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                                                    |
| -------- | --------------------------- | ---- | --------------------------------------------------------------------- |
| uid      | number                      | 是   | 进程uid。                                                              |
| callback | AsyncCallback&lt;number&gt; | 是   | 回调函数。如果查询成功，err为null，data为对应的系统帐号ID；否则为错误对象。 |

**示例：** 查询值为12345678的uid所属的系统帐号ID

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let uid = 12345678;
  accountManager.getOsAccountLocalIdFromUid(uid, (err, localId) => {
    if (err) {
      console.log("getOsAccountLocalIdFromUid failed, error: " + JSON.stringify(err));
    } else {
      console.log("getOsAccountLocalIdFromUid successfully, localId: " + localId);
    }
  });
  ```

### getOsAccountLocalIdFromUid<sup>(deprecated)</sup>

getOsAccountLocalIdFromUid(uid: number): Promise&lt;number&gt;

根据uid查询对应的系统帐号ID，使用Promise异步回调。

> **说明：** 
>
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[queryOsAccountLocalIdFromUid](#queryosaccountlocalidfromuid9-1)。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名 | 类型   | 必填 | 说明      |
| ------ | ------ | ---- | --------- |
| uid    | number | 是   | 进程uid。 |

**返回值：**

| 类型                  | 说明                                  |
| :-------------------- | :----------------------------------- |
| Promise&lt;number&gt; | Promise对象，返回uid对应的系统帐号ID。 |

**示例：** 查询值为12345678的uid所属的系统帐号ID

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let uid = 12345678;
  accountManager.getOsAccountLocalIdFromUid(uid).then((localId) => {
    console.log("getOsAccountLocalIdFromUid successfully, localId: " + localId);
  }).catch((err) => {
    console.log("getOsAccountLocalIdFromUid failed, error: "  + JSON.stringify(err));
  });
  ```

### getOsAccountLocalIdFromDomain<sup>(deprecated)</sup>

getOsAccountLocalIdFromDomain(domainInfo: DomainAccountInfo, callback: AsyncCallback&lt;number&gt;): void

根据域帐号信息，获取与其关联的系统帐号的帐号ID。使用callback异步回调。

> **说明：** 
>
> 从 API version 8开始支持，从API version 9开始废弃。建议使用[queryOsAccountLocalIdFromDomain](#queryosaccountlocalidfromdomain9)。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名     | 类型                                    | 必填 | 说明                                                                         |
| ---------- | --------------------------------------- | ---- | --------------------------------------------------------------------------- |
| domainInfo | [DomainAccountInfo](#domainaccountinfo8) | 是   | 域帐号信息。                                                                |
| callback   | AsyncCallback&lt;number&gt;             | 是   | 回调函数，如果获取成功，err为null，data为域帐号关联的系统帐号ID；否则为错误对象。 |

**示例：**

  ```js
  let domainInfo = {domain: 'testDomain', accountName: 'testAccountName'};
  let accountManager = account_osAccount.getAccountManager();
  accountManager.getOsAccountLocalIdFromDomain(domainInfo, (err, localId) => {
    if (err) {
      console.log("getOsAccountLocalIdFromDomain failed, error: " + JSON.stringify(err));
    } else {
      console.log("getOsAccountLocalIdFromDomain successfully, localId: " + localId);
    }
  });
  ```

### getOsAccountLocalIdFromDomain<sup>(deprecated)</sup>

getOsAccountLocalIdFromDomain(domainInfo: DomainAccountInfo): Promise&lt;number&gt;

根据域帐号信息，获取与其关联的系统帐号的帐号ID。使用Promise异步回调。

> **说明：** 
>
> 从 API version 8开始支持，从API version 9开始废弃。建议使用[queryOsAccountLocalIdFromDomain](#queryosaccountlocalidfromdomain9-1)。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名     | 类型                                    | 必填 | 说明         |
| ---------- | --------------------------------------- | ---- | ------------ |
| domainInfo | [DomainAccountInfo](#domainaccountinfo8) | 是   | 域帐号信息。 |

**返回值：**

| 类型                  | 说明                                    |
| :-------------------- | :------------------------------------- |
| Promise&lt;number&gt; | Promise对象，返回域帐号关联的系统帐号ID。 |

**示例：**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let domainInfo = {domain: 'testDomain', accountName: 'testAccountName'};
  accountManager.getOsAccountLocalIdFromDomain(domainInfo).then((localId) => {
    console.log('getOsAccountLocalIdFromDomain successfully, localId: ' + localId);
  }).catch((err) => {
    console.log('getOsAccountLocalIdFromDomain failed, error: '  + JSON.stringify(err));
  });
  ```

### getOsAccountAllConstraints<sup>(deprecated)</sup>

getOsAccountAllConstraints(localId: number, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

获取指定系统帐号的全部约束。使用callback异步回调。

> **说明：** 
>
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[getOsAccountConstraints](#getosaccountconstraints9)。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                                     | 必填 | 说明                                                                                             |
| -------- | ---------------------------------------- | ---- | ---------------------------------------------------------------------------------------------- |
| localId  | number                                   | 是   | 系统帐号ID。                                                                                    |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt; | 是   | 回调函数。如果获取成功，err为null，data为指定系统帐号的全部[约束](#系统帐号约束列表)；否则为错误对象。 |

**示例：** 获取ID为100的系统帐号的全部约束

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let localId = 100;
  accountManager.getOsAccountAllConstraints(localId, (err, constraints)=>{
    console.log('getOsAccountAllConstraints err:' + JSON.stringify(err));
    console.log('getOsAccountAllConstraints:' + JSON.stringify(constraints));
  });
  ```

### getOsAccountAllConstraints<sup>(deprecated)</sup>

getOsAccountAllConstraints(localId: number): Promise&lt;Array&lt;string&gt;&gt;

> **说明：** 
>
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[getOsAccountConstraints](#getosaccountconstraints9-1)。

获取指定系统帐号的全部约束。使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名  | 类型   | 必填 | 说明         |
| ------- | ------ | ---- | ------------ |
| localId | number | 是   | 系统帐号ID。 |

**返回值：**

| 类型                               | 说明                                                         |
| :--------------------------------- | :----------------------------------------------------------- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise对象，返回指定系统帐号的全部[约束](#系统帐号约束列表)。 |

**示例：** 获取ID为100的系统帐号的全部约束

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let localId = 100;
  accountManager.getOsAccountAllConstraints(localId).then((constraints) => {
    console.log('getOsAccountAllConstraints, constraints: ' + constraints);
  }).catch((err) => {
    console.log('getOsAccountAllConstraints err: '  + JSON.stringify(err));
  });
  ```

### queryActivatedOsAccountIds<sup>(deprecated)</sup>

queryActivatedOsAccountIds(callback: AsyncCallback&lt;Array&lt;number&gt;&gt;): void

查询当前处于激活状态的系统帐号的ID列表。使用callback异步回调。

> **说明：** 
>
> 从 API version 8开始支持，从API version 9开始废弃。建议使用[getActivatedOsAccountIds](#getactivatedosaccountids9)。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                                     | 必填 | 说明                                                   |
| -------- | ---------------------------------------- | ---- | ------------------------------------------------------ |
| callback | AsyncCallback&lt;Array&lt;number&gt;&gt; | 是   | 回调函数。如果查询成功，err为null，data为当前处于激活状态的系统帐号的ID列表；否则为错误对象。 |

**示例：**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  accountManager.queryActivatedOsAccountIds((err, idArray)=>{
    console.log('queryActivatedOsAccountIds err:' + JSON.stringify(err));
    console.log('queryActivatedOsAccountIds idArray length:' + idArray.length);
    for(let i=0;i<idArray.length;i++) {
      console.info('activated os account id: ' + idArray[i]);
    }
  });
  ```

### queryActivatedOsAccountIds<sup>(deprecated)</sup>

queryActivatedOsAccountIds(): Promise&lt;Array&lt;number&gt;&gt;

> **说明：** 
>
> 从 API version 8开始支持，从API version 9开始废弃。建议使用[getActivatedOsAccountIds](#getactivatedosaccountids9-1)。

查询当前处于激活状态的系统帐号的ID列表。使用Promise异步回调。

**系统能力：** SystemCapability.Account.OsAccount

**返回值：**

| 类型                               | 说明                                               |
| ---------------------------------- | ------------------------------------------------- |
| Promise&lt;Array&lt;number&gt;&gt; | Promise对象，返回当前处于激活状态的系统帐号的ID列表。 |

**示例：**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  accountManager.queryActivatedOsAccountIds().then((idArray) => {
    console.log('queryActivatedOsAccountIds, idArray: ' + idArray);
  }).catch((err) => {
    console.log('queryActivatedOsAccountIds err: '  + JSON.stringify(err));
  });
  ```

### queryCurrentOsAccount<sup>(deprecated)</sup>

queryCurrentOsAccount(callback: AsyncCallback&lt;OsAccountInfo&gt;): void

查询当前进程所属的系统帐号的信息。使用callback异步回调。

> **说明：** 
>
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[getCurrentOsAccount](#getcurrentosaccount9)。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                                           |
| -------- | ---------------------------------------------------- | ---- | ---------------------------------------------- |
| callback | AsyncCallback&lt;[OsAccountInfo](#osaccountinfo)&gt; | 是   | 回调函数。如果查询成功，err为null，data为当前进程所属的系统帐号信息；否则为错误对象。 |

**示例：**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  accountManager.queryCurrentOsAccount((err, curAccountInfo)=>{
    console.log('queryCurrentOsAccount err:' + JSON.stringify(err));
    console.log('queryCurrentOsAccount curAccountInfo:' + JSON.stringify(curAccountInfo));
  });
  ```

### queryCurrentOsAccount<sup>(deprecated)</sup>

queryCurrentOsAccount(): Promise&lt;OsAccountInfo&gt;

查询当前进程所属的系统帐号的信息。使用Promise异步回调。

> **说明：** 
>
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[getCurrentOsAccount](#getcurrentosaccount9-1)。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**返回值：**

| 类型                                           | 说明                                       |
| ---------------------------------------------- | ------------------------------------------ |
| Promise&lt;[OsAccountInfo](#osaccountinfo)&gt; | Promise对象，返回当前进程所属的系统帐号信息。 |

**示例：**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  accountManager.queryCurrentOsAccount().then((accountInfo) => {
    console.log('queryCurrentOsAccount, accountInfo: ' + JSON.stringify(accountInfo));
  }).catch((err) => {
    console.log('queryCurrentOsAccount err: '  + JSON.stringify(err));
  });
  ```

### getOsAccountTypeFromProcess<sup>(deprecated)</sup>

getOsAccountTypeFromProcess(callback: AsyncCallback&lt;OsAccountType&gt;): void

查询当前进程所属的系统帐号的帐号类型。使用callback异步回调。

> **说明：** 
>
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[getOsAccountType](#getosaccounttype9)。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                                                 |
| -------- | ---------------------------------------------------- | ---- | ---------------------------------------------------- |
| callback | AsyncCallback&lt;[OsAccountType](#osaccounttype)&gt; | 是   | 回调函数。如果查询成功，err为null，data为当前进程所属的系统帐号的帐号类型；否则为错误对象。 |

**示例：**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  accountManager.getOsAccountTypeFromProcess((err, accountType) => {
    console.log('getOsAccountTypeFromProcess err: ' + JSON.stringify(err));
    console.log('getOsAccountTypeFromProcess accountType: ' + accountType);
  });
  ```

### getOsAccountTypeFromProcess<sup>(deprecated)</sup>

getOsAccountTypeFromProcess(): Promise&lt;OsAccountType&gt;

查询当前进程所属的系统帐号的帐号类型。使用Promise异步回调。

> **说明：**
>
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[getOsAccountType](#getosaccounttype9-1)。

**系统能力：** SystemCapability.Account.OsAccount

**返回值：**

| 类型                                           | 说明                                            |
| ---------------------------------------------- | ----------------------------------------------- |
| Promise&lt;[OsAccountType](#osaccounttype)&gt; | Promise对象，返回当前进程所属的系统帐号的帐号类型。 |

**示例：**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  accountManager.getOsAccountTypeFromProcess().then((accountType) => {
    console.log('getOsAccountTypeFromProcess, accountType: ' + accountType);
  }).catch((err) => {
    console.log('getOsAccountTypeFromProcess err: '  + JSON.stringify(err));
  });
  ```

### getDistributedVirtualDeviceId<sup>(deprecated)</sup>

getDistributedVirtualDeviceId(callback: AsyncCallback&lt;string&gt;): void

获取分布式虚拟设备ID。使用callback异步回调。

> **说明：** 
>
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[queryDistributedVirtualDeviceId](#querydistributedvirtualdeviceid9)。

**需要权限：** ohos.permission.DISTRIBUTED_DATASYNC 或 ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                                                    |
| -------- | --------------------------- | ---- | --------------------------------------------------------------------- |
| callback | AsyncCallback&lt;string&gt; | 是   | 回调函数。如果获取成功，err为null，data为分布式虚拟设备ID；否则为错误对象。 |

**示例：**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  accountManager.getDistributedVirtualDeviceId((err, virtualID) => {
    console.log('getDistributedVirtualDeviceId err: ' + JSON.stringify(err));
    console.log('getDistributedVirtualDeviceId virtualID: ' + virtualID);
  });
  ```

### getDistributedVirtualDeviceId<sup>(deprecated)</sup>

getDistributedVirtualDeviceId(): Promise&lt;string&gt;

获取分布式虚拟设备ID。使用Promise异步回调。

> **说明：** 
>
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[queryDistributedVirtualDeviceId](#querydistributedvirtualdeviceid9-1)。

**需要权限：** ohos.permission.DISTRIBUTED_DATASYNC 或 ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**返回值：**

| 类型                  | 说明                              |
| --------------------- | --------------------------------- |
| Promise&lt;string&gt; | Promise对象，返回分布式虚拟设备ID。 |

**示例：**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  accountManager.getDistributedVirtualDeviceId().then((virtualID) => {
    console.log('getDistributedVirtualDeviceId, virtualID: ' + virtualID);
  }).catch((err) => {
    console.log('getDistributedVirtualDeviceId err: '  + JSON.stringify(err));
  });
  ```

### getOsAccountLocalIdBySerialNumber<sup>(deprecated)</sup>

getOsAccountLocalIdBySerialNumber(serialNumber: number, callback: AsyncCallback&lt;number&gt;): void

通过SN码查询与其关联的系统帐号的帐号ID。使用callback异步回调。

> **说明：** 
>
> 从 API version 8开始支持，从API version 9开始废弃。建议使用[queryOsAccountLocalIdBySerialNumber](#queryosaccountlocalidbyserialnumber9)。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名       | 类型                        | 必填 | 说明                                                                               |
| ------------ | --------------------------- | ---- | -------------------------------------------------------------------------------- |
| serialNumber | number                      | 是   | 帐号SN码。                                                                        |
| callback     | AsyncCallback&lt;number&gt; | 是   | 回调函数。如果查询成功，err为null，data为与SN码关联的系统帐号的帐号ID；否则为错误对象。 |

**示例：** 查询与SN码12345关联的系统帐号的ID

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let serialNumber = 12345;
  accountManager.getOsAccountLocalIdBySerialNumber(serialNumber, (err, localId)=>{
    console.log('ger localId err:' + JSON.stringify(err));
    console.log('get localId:' + localId + ' by serialNumber: ' + serialNumber);
  });
  ```

### getOsAccountLocalIdBySerialNumber<sup>(deprecated)</sup>

getOsAccountLocalIdBySerialNumber(serialNumber: number): Promise&lt;number&gt;

通过SN码查询与其关联的系统帐号的帐号ID。使用Promise异步回调。

> **说明：** 
>
> 从 API version 8开始支持，从API version 9开始废弃。建议使用[queryOsAccountLocalIdBySerialNumber](#queryosaccountlocalidbyserialnumber9-1)。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名       | 类型   | 必填 | 说明       |
| ------------ | ------ | ---- | ---------- |
| serialNumber | number | 是   | 帐号SN码。 |

**返回值：**

| 类型                  | 说明                                                         |
| --------------------- | -------------------------------------------- |
| Promise&lt;number&gt; | Promise对象，返回与SN码关联的系统帐号的帐号ID。 |

**示例：** 查询与SN码12345关联的系统帐号的ID

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let serialNumber = 12345;
  accountManager.getOsAccountLocalIdBySerialNumber(serialNumber).then((localId) => {
    console.log('getOsAccountLocalIdBySerialNumber localId: ' + localId);
  }).catch((err) => {
    console.log('getOsAccountLocalIdBySerialNumber err: '  + JSON.stringify(err));
  });
  ```

### getSerialNumberByOsAccountLocalId<sup>(deprecated)</sup>

getSerialNumberByOsAccountLocalId(localId: number, callback: AsyncCallback&lt;number&gt;): void

通过系统帐号ID获取与该系统帐号关联的SN码。使用callback异步回调。

> **说明：** 
>
> 从 API version 8开始支持，从API version 9开始废弃。建议使用[querySerialNumberByOsAccountLocalId](#queryserialnumberbyosaccountlocalid9)。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                                                         |
| -------- | --------------------------- | ---- | --------------------------------------------------------------------------- |
| localId  | number                      | 是   | 系统帐号ID。                                                                 |
| callback | AsyncCallback&lt;number&gt; | 是   | 回调函数。如果获取成功，err为null，data为与该系统帐号关联的SN码；否则为错误对象。 |

**示例：** 获取ID为100的系统帐号关联的SN码

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let localId = 100;
  accountManager.getSerialNumberByOsAccountLocalId(localId, (err, serialNumber)=>{
    console.log('ger serialNumber err:' + JSON.stringify(err));
    console.log('get serialNumber:' + serialNumber + ' by localId: ' + localId);
  });
  ```

### getSerialNumberByOsAccountLocalId<sup>(deprecated)</sup>

getSerialNumberByOsAccountLocalId(localId: number): Promise&lt;number&gt;

通过系统帐号ID获取与该系统帐号关联的SN码。使用Promise异步回调。

> **说明：** 
>
> 从 API version 8开始支持，从API version 9开始废弃。建议使用[querySerialNumberByOsAccountLocalId](#queryserialnumberbyosaccountlocalid9-1)。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名  | 类型   | 必填 | 说明          |
| ------- | ------ | ---- | ----------- |
| localId | number | 是   | 系统帐号ID。 |

**返回值：**

| 类型                  | 说明                                    |
| --------------------- | -------------------------------------- |
| Promise&lt;number&gt; | Promise对象，返回与该系统帐号关联的SN码。 |

**示例：** 获取ID为100的系统帐号关联的SN码

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let localId = 100;
  accountManager.getSerialNumberByOsAccountLocalId(localId).then((serialNumber) => {
    console.log('getSerialNumberByOsAccountLocalId serialNumber: ' + serialNumber);
  }).catch((err) => {
    console.log('getSerialNumberByOsAccountLocalId err: '  + JSON.stringify(err));
  });
  ```

## UserAuth<sup>8+</sup>

用户认证类。

**系统接口：** 此接口为系统接口。

### constructor<sup>8+</sup>

constructor()

创建用户认证的实例。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Account.OsAccount

**示例：**  
  ```js
  let userAuth = new account_osAccount.UserAuth();
  ```

### getVersion<sup>8+</sup>

getVersion(): number;

返回版本信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**返回值：**

| 类型   | 说明         |
| :----- | :----------- |
| number | 返回版本信息。|

**示例：**  
  ```js
  let userAuth = new account_osAccount.UserAuth();
  let version = userAuth.getVersion();
  console.log('getVersion version = ' + version);
  ```

### getAvailableStatus<sup>8+</sup>

getAvailableStatus(authType: AuthType, authTrustLevel: AuthTrustLevel): number;

获取指定认证类型和认证可信等级的认证能力的可用状态。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**需要权限：** ohos.permission.ACCESS_USER_AUTH_INTERNAL

**参数：**

| 参数名           | 类型                               | 必填 | 说明                       |
| --------------- | -----------------------------------| ---- | ------------------------- |
| authType        | [AuthType](#authtype8)             | 是   | 认证类型。     |
| authTrustLevel  | [AuthTrustLevel](#authtrustlevel8) | 是   | 认证的可信等级。 |

**返回值：**

| 类型   | 说明                           |
| ------ | ----------------------------- |
| number | 返回认证能力的可用状态。 |

**错误码：**

| 错误码ID | 错误信息                     |
| -------- | --------------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid authType or authTrustLevel. |

**示例：**  
  ```js
  let userAuth = new account_osAccount.UserAuth();
  let authType = account_osAccount.AuthType.PIN;
  let authTrustLevel = account_osAccount.AuthTrustLevel.ATL1;
  try {
    let status = userAuth.getAvailableStatus(authType, authTrustLevel);
    console.log('getAvailableStatus status = ' + status);
  } catch (e) {
    console.log('getAvailableStatus exception = ' + JSON.stringify(e));
  }
  ```

### getProperty<sup>8+</sup>

getProperty(request: GetPropertyRequest, callback: AsyncCallback&lt;ExecutorProperty&gt;): void;

基于指定的请求信息获取属性。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**需要权限：** ohos.permission.ACCESS_USER_AUTH_INTERNAL

**参数：**

| 参数名    | 类型                                                                    | 必填 | 说明                                |
| -------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------ |
| request  | [GetPropertyRequest](#getpropertyrequest8)                  | 是   | 请求信息，包括认证类型和属性类型列表。 |
| callback | AsyncCallback&lt;[ExecutorProperty](#executorproperty8)&gt; | 是   | 回调函数。如果获取成功，err为null，data为执行器属性信息；否则为错误对象。|

**错误码：**

| 错误码ID | 错误信息                     |
| -------- | --------------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid request. |

**示例：**
  ```js
  let userAuth = new account_osAccount.UserAuth();
  let keys = [
    account_osAccount.GetPropertyType.AUTH_SUB_TYPE, 
    account_osAccount.GetPropertyType.REMAIN_TIMES,
    account_osAccount.GetPropertyType.FREEZING_TIME
  ];
  let request = {
    authType: account_osAccount.AuthType.PIN,
    keys: keys
  };
  try {
    userAuth.getProperty(request, (err, result) => {
      console.log('getProperty err = ' + JSON.stringify(err));
      console.log('getProperty result = ' + JSON.stringify(result));
    });
  } catch (e) {
    console.log('getProperty exception = ' + JSON.stringify(e));
  }
  ```

### getProperty<sup>8+</sup>

getProperty(request: GetPropertyRequest): Promise&lt;ExecutorProperty&gt;;

基于指定的请求信息获取属性。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**需要权限：** ohos.permission.ACCESS_USER_AUTH_INTERNAL

**参数：**

| 参数名    | 类型                                                   | 必填 | 说明                                |
| -------- | ------------------------------------------------------ | ---- | ---------------------------------- |
| request  | [GetPropertyRequest](#getpropertyrequest8) | 是   | 请求信息，包括认证类型和属性类型列表。 |

**返回值：**

| 类型                                                              | 说明                                                 |
| :---------------------------------------------------------------- | :-------------------------------------------------- |
| Promise&lt;[ExecutorProperty](#executorproperty8)&gt; | Promise对象，返回执行者属性信息。 |

**错误码：**

| 错误码ID | 错误信息                     |
| -------- | --------------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid request. |

**示例：**
  ```js
  let userAuth = new account_osAccount.UserAuth();
  let keys = [
    account_osAccount.GetPropertyType.AUTH_SUB_TYPE, 
    account_osAccount.GetPropertyType.REMAIN_TIMES,
    account_osAccount.GetPropertyType.FREEZING_TIME
  ];
  let request = {
    authType: account_osAccount.AuthType.PIN,
    keys: keys
  };
  try {
    userAuth.getProperty(request).then((result) => {
      console.log('getProperty result = ' + JSON.stringify(result));
    }).catch((err) => {
      console.log('getProperty error = ' + JSON.stringify(err));
    });
  } catch (e) {
    console.log('getProperty exception = ' + JSON.stringify(e));
  }
  ```

### setProperty<sup>8+</sup>

setProperty(request: SetPropertyRequest, callback: AsyncCallback&lt;void&gt;): void;

设置可用于初始化算法的属性。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**需要权限：** ohos.permission.ACCESS_USER_AUTH_INTERNAL

**参数：**

| 参数名    | 类型                                                  | 必填 | 说明                                                                    |
| -------- | ----------------------------------------------------- | ---- | ---------------------------------------------------------------------- |
| request  | [SetPropertyRequest](#setpropertyrequest8)| 是   | 请求信息，包括认证类型和要设置的密钥值。                                   |
| callback | AsyncCallback&lt;void&gt;                           | 是   | 回调函数。如果设置成功，err为null，否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息                     |
| -------- | --------------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid request. |

**示例：**
  ```js
  let userAuth = new account_osAccount.UserAuth();
  let request = {
    authType: account_osAccount.AuthType.PIN,
    key: account_osAccount.SetPropertyType.INIT_ALGORITHM,
    setInfo: new Uint8Array([0])
  };
  try {
    userAuth.setProperty(request, (err) => {
      if (err) {
        console.log('setProperty failed, error = ' + JSON.stringify(err));
      } else {
        console.log('setProperty successfully');
      }
    });
  } catch (e) {
    console.log('setProperty exception = ' + JSON.stringify(e));
  }
  ```

### setProperty<sup>8+</sup>

setProperty(request: SetPropertyRequest): Promise&lt;void&gt;;

设置可用于初始化算法的属性。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**需要权限：** ohos.permission.ACCESS_USER_AUTH_INTERNAL

**参数：**

| 参数名    | 类型                                       | 必填 | 说明                                      |
| -------- | ------------------------------------------ | ---- | ---------------------------------------- |
| request  | [SetPropertyRequest](#setpropertyrequest8) | 是   | 请求信息，包括身份验证类型和要设置的密钥值。 |

**返回值：**

| 类型                  | 说明                                                           |
| :-------------------- | :------------------------------------------------------------ |
| Promise&lt;void&gt; | Promise对象，无返回结果的Promise对象。 |

**错误码：**

| 错误码ID | 错误信息                     |
| -------- | --------------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid request. |

**示例：**
  ```js
  let userAuth = new account_osAccount.UserAuth();
  let request = {
    authType: account_osAccount.AuthType.PIN,
    key: account_osAccount.SetPropertyType.INIT_ALGORITHM,
    setInfo: new Uint8Array([0])
  };
  try {
    userAuth.setProperty(request).then(() => {
      console.log('setProperty successfully');
    }).catch((err) => {
      console.log('setProperty failed, error = ' + JSON.stringify(err));
    });
  } catch (e) {
    console.log('setProperty exception = ' + JSON.stringify(e));
  }
  ```

### auth<sup>8+</sup>

auth(challenge: Uint8Array, authType: AuthType, authTrustLevel: AuthTrustLevel, callback: IUserAuthCallback): Uint8Array;

认证当前用户。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**需要权限：** ohos.permission.ACCESS_USER_AUTH_INTERNAL

**参数：**

| 参数名           | 类型                                     | 必填 | 说明                                |
| --------------- | ---------------------------------------- | --- | ------------------------------------ |
| challenge       | Uint8Array                               | 是  | 指示挑战值，挑战值为一个随机数，用于提升安全性。|
| authType        | [AuthType](#authtype8)                   | 是  | 指示认证类型。                        |
| authTrustLevel  | [AuthTrustLevel](#authtrustlevel8)       | 是  | 指示认证结果的信任级别。               |
| callback        | [IUserAuthCallback](#iuserauthcallback8) | 是  | 回调对象，返回认证结果。  |

**返回值：**

| 类型        | 说明               |
| ---------- | ------------------ |
| Uint8Array | 返回取消的上下文ID。 |

**错误码：**

| 错误码ID | 错误信息          |
| -------- | --------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid challenge or authType or authTrustLevel. |
| 12300101 | Credential is incorrect. |
| 12300105 | Unsupported authTrustLevel. |
| 12300106 | Unsupported authType. |
| 12300110 | Authentication locked. |
| 12300111 | Authentication timeout. |
| 12300112 | Authentication service busy. |

**示例：**
  ```js
  let userAuth = new account_osAccount.UserAuth();
  let challenge = new Uint8Array([0]);
  let authType = account_osAccount.AuthType.PIN;
  let authTrustLevel = account_osAccount.AuthTrustLevel.ATL1;
  try {
    userAuth.auth(challenge, authType, authTrustLevel, {
      onResult: function(result,extraInfo){
          console.log('auth result = ' + result);
          console.log('auth extraInfo = ' + JSON.stringify(extraInfo));
      }
    });
  } catch (e) {
    console.log('auth exception = ' + JSON.stringify(e));
  }
  ```

### authUser<sup>8+</sup>

authUser(userId: number, challenge: Uint8Array, authType: AuthType, authTrustLevel: AuthTrustLevel, callback: IUserAuthCallback): Uint8Array;

认证指定用户。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**需要权限：** ohos.permission.ACCESS_USER_AUTH_INTERNAL

**参数：**

| 参数名           | 类型                                                 | 必填 | 说明                                |
| --------------- | ---------------------------------------------------- | --- | ------------------------------------ |
| userId          | number                                               | 是  | 指示用户身份。                        |
| challenge       | Uint8Array                                           | 是  | 指示挑战值，挑战值为一个随机数，用于提升安全性。                          |
| authType        | [AuthType](#authtype8)                   | 是  | 指示认证类型。                        |
| authTrustLevel  | [AuthTrustLevel](#authtrustlevel8)       | 是  | 指示认证结果的信任级别。               |
| callback        | [IUserAuthCallback](#iuserauthcallback8) | 是  | 回调对象，返回认证结果。  |

**返回值：**

| 类型        | 说明               |
| ---------- | ------------------ |
| Uint8Array | 返回取消的上下文ID。 |

**错误码：**

| 错误码ID | 错误信息          |
| -------- | --------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid userId or challenge or authType or authTrustLevel. |
| 12300101 | Credential is incorrect. |
| 12300105 | Unsupported authTrustLevel. |
| 12300106 | Unsupported authType. |
| 12300110 | Authentication locked. |
| 12300111 | Authentication timeout. |
| 12300112 | Authentication service busy. |

**示例：**
  ```js
  let userAuth = new account_osAccount.UserAuth();
  let userID = 100;
  let challenge = new Uint8Array([0]);
  let authType = account_osAccount.AuthType.PIN;
  let authTrustLevel = account_osAccount.AuthTrustLevel.ATL1;
  try {
    userAuth.authUser(userID, challenge, authType, authTrustLevel, {
      onResult: function(result,extraInfo){
        console.log('authUser result = ' + result);
        console.log('authUser extraInfo = ' + JSON.stringify(extraInfo));
      }
    });
  } catch (e) {
    console.log('authUser exception = ' + JSON.stringify(e));
  }
  ```

### cancelAuth<sup>8+</sup>

cancelAuth(contextID: Uint8Array): void;

取消指定的认证操作。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**需要权限：** ohos.permission.ACCESS_USER_AUTH_INTERNAL

**参数：**

| 参数名    | 类型       | 必填  | 说明                                        |
| ----------| ---------- | ---- | ------------------------------------------ |
| contextId | Uint8Array | 是   | 指示身份验证上下文ID，此ID动态生成没有具体值。 |

**错误码：**

| 错误码ID | 错误信息            |
| -------- | ------------------ |
| 12300001 | System service exception. |
| 12300002 | Invalid contextId. |

**示例：**
  ```js
  let userAuth = new account_osAccount.UserAuth();
  let pinAuth = new account_osAccount.PINAuth();
  let challenge = new Uint8Array([0]);
  let contextId = userAuth.auth(challenge, account_osAccount.AuthType.PIN, account_osAccount.AuthTrustLevel.ATL1, {
    onResult: (result, extraInfo) => {
      console.log('auth result = ' + result);
      console.log('auth extraInfo = ' + JSON.stringify(extraInfo));
    }
  });
  try {
    userAuth.cancelAuth(contextId);
  } catch (e) {
    console.log('cancelAuth exception = ' + JSON.stringify(e));
  }
  ```

## PINAuth<sup>8+</sup>

Pin码认证功能基类。

**系统接口：** 此接口为系统接口。

### constructor<sup>8+</sup>

constructor()

创建Pin码认证的实例。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Account.OsAccount

**示例：**  
  ```js
  let pinAuth = new account_osAccount.PINAuth();
  ```

### registerInputer<sup>8+</sup>

registerInputer(inputer: IInputer): void;

注册PIN码输入器。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**需要权限：** ohos.permission.ACCESS_PIN_AUTH

**参数：**

| 参数名    | 类型                     | 必填 | 说明                      |
| ----------| ----------------------- | --- | -------------------------- |
| inputer   | [IInputer](#iinputer8)  | 是  | PIN码输入器，用于获取PIN码。 |

**返回值：**

| 类型    | 说明                                           |
| :------ | :-------------------------------------------- |
| boolean | 返回布尔值，true表示注册成功，false表示注册失败。 |

**错误码：**

| 错误码ID | 错误信息                     |
| -------- | --------------------------- |
| 12300001 | System service exception. |
| 12300103 | Inputer already registered. |

**示例：**
  ```js
  let pinAuth = new account_osAccount.PINAuth();
  let password = new Uint8Array([0, 0, 0, 0, 0]);
  try {
    let result = pinAuth.registerInputer({
        onGetData: (pinSubType, callback) => {
          callback.onSetData(pinSubType, password);
        }
    });
    console.log('registerInputer result = ' + result);
  } catch (e) {
    console.log('registerInputer exception = ' + JSON.stringify(e));
  }
  ```

### unregisterInputer<sup>8+</sup>

unregisterInputer(): void;

解注册PIN码输入器。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**需要权限：** ohos.permission.ACCESS_PIN_AUTH

**示例：**
  ```js
  let pinAuth = new account_osAccount.PINAuth();
  pinAuth.unregisterInputer();
  ```

## UserIdentityManager<sup>8+</sup>

获取用户身份管理类。

**系统接口：** 此接口为系统接口。

### constructor<sup>8+</sup>

constructor()

用户身份管理类的默认构造函数。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Account.OsAccount

**示例：**  
  ```js
  let userIDM = new account_osAccount.UserIdentityManager();
  ```

### openSession<sup>8+</sup>

openSession(callback: AsyncCallback&lt;Uint8Array&gt;): void;

打开会话，获取挑战值。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**需要权限：** ohos.permission.MANAGE_USER_IDM

**参数：**

| 参数名    | 类型                             | 必填 | 说明                                                            |
| -------- | -------------------------------- | ---- | -------------------------------------------------------------- |
| callback | AsyncCallback&lt;Uint8Array&gt;  | 是   | 回调函数。如果打开会话成功，err为null，data为挑战值；否则为错误对象。|

**错误码：**

| 错误码ID | 错误信息                     |
| -------- | --------------------------- |
| 12300001 | System service exception. |

**示例：**
  ```js
  let userIDM = new account_osAccount.UserIdentityManager();
  try {
    userIDM.openSession((err, challenge) => {
        console.log('openSession error = ' + JSON.stringify(err));
        console.log('openSession challenge = ' + JSON.stringify(challenge));
    });
  } catch (e) {
    console.log('openSession exception = ' + JSON.stringify(e));
  }
  ```

### openSession<sup>8+</sup>

openSession(): Promise&lt;Uint8Array&gt;;

打开会话，获取挑战值。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**需要权限：** ohos.permission.MANAGE_USER_IDM

**返回值：**

| 类型                      | 说明                     |
| :------------------------ | ----------------------- |
| Promise&lt;Uint8Array&gt; | Promise对象，返回挑战值。 |

**错误码：**

| 错误码ID | 错误信息                     |
| -------- | --------------------------- |
| 12300001 | System service exception. |

**示例：**
  ```js
  let userIDM = new account_osAccount.UserIdentityManager();
  try {
    userIDM.openSession().then((challenge) => {
        console.info('openSession challenge = ' + JSON.stringify(challenge));
    }).catch((err) => {
        console.info('openSession error = ' + JSON.stringify(err));
    });
  } catch (e) {
    console.log('openSession exception = ' + JSON.stringify(e));
  }
  ```

### addCredential<sup>8+</sup>

addCredential(credentialInfo: CredentialInfo, callback: IIdmCallback): void;

添加凭据，添加用户凭据信息，传入凭据添加方法和凭据信息（凭据类型，子类，如果添加用户的非密码凭据，则传入密码身份验证令牌），并获取结果/获取信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**需要权限：** ohos.permission.MANAGE_USER_IDM

**参数：**

| 参数名           | 类型                                 | 必填 | 说明                        |
| --------------- | ------------------------------------ | --- | ---------------------------- |
| credentialInfo  | [CredentialInfo](#credentialinfo8)   | 是  | 指示凭据信息。                |
| callback        | [IIdmCallback](#iidmcallback8)       | 是  | 回调对象，返回添加凭据的结果。  |

**错误码：**

| 错误码ID | 错误信息                     |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid credentialInfo, i.e. authType or authSubType. |
| 12300101 | Token is invalid. |
| 12300106 | Unsupported authType. |

**示例：**
  ```js
  let password = new Uint8Array([0, 0, 0, 0, 0, 0]);
  let pinAuth = new account_osAccount.PINAuth();
  pinAuth.registerInputer({
    onGetData: (pinSubType, callback) => {
      callback.onSetData(pinSubType, password);
    }
  });
  let credentialInfo = {
    credType: account_osAccount.AuthType.PIN,
    credSubType: account_osAccount.AuthSubType.PIN_SIX,
    token: null
  };
  let userIDM = new account_osAccount.UserIdentityManager();
  userIDM.openSession((err, challenge) => {
    try {
    userIDM.addCredential(credentialInfo, {
      onResult: (result, extraInfo) => {
        console.log('updateCredential result = ' + result);
        console.log('updateCredential extraInfo = ' + extraInfo);
      }
    });
    } catch (e) {
      console.log('updateCredential exception = ' + JSON.stringify(e));
    }
  });
  ```

### updateCredential<sup>8+</sup>

updateCredential(credentialInfo: CredentialInfo, callback: IIdmCallback): void;

更新凭据。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**需要权限：** ohos.permission.MANAGE_USER_IDM

**参数：**

| 参数名           | 类型                                  | 必填 | 说明                     |
| --------------- | ------------------------------------- | --- | ------------------------- |
| credentialInfo  | [CredentialInfo](#credentialinfo8)    | 是  | 指示凭据信息。             |
| callback        | [IIdmCallback](#iidmcallback8)        | 是  | 回调对象，返回更新凭据的结果。 |

**错误码：**

| 错误码ID | 错误信息                     |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid credentialInfo, i.e. authType or authSubType or token. |
| 12300101 | Token is invalid. |
| 12300106 | Unsupported authType. |

**示例：**
  ```js
  let userIDM = new account_osAccount.UserIdentityManager();
  let userAuth = new account_osAccount.UserAuth();
  let pinAuth = new account_osAccount.PINAuth();
  let password = new Uint8Array([0, 0, 0, 0, 0, 0]);
  let credentialInfo = {
    credType: account_osAccount.AuthType.PIN,
    credSubType: account_osAccount.AuthSubType.PIN_SIX,
    token: null
  };
  pinAuth.registerInputer({
    onGetData: (pinSubType, callback) => {
      callback.onSetData(pinSubType, password);
    }
  });
  userIDM.openSession((err, challenge) => {
    userAuth.auth(challenge, credentialInfo.credType, account_osAccount.AuthTrustLevel.ATL1, {
      onResult: (result, extraInfo) => {
        if (result != account_osAccount.ResultCode.SUCCESS) {
          return;
        }
        credentialInfo.token = extraInfo.token;
        try {
          userIDM.updateCredential(credentialInfo, {
            onResult: (result, extraInfo) => {
                console.log('updateCredential result = ' + result);
                console.log('updateCredential extraInfo = ' + extraInfo);
            }
          });
        } catch (e) {
          console.log('updateCredential exception = ' + JSON.stringify(e));
        }
      }
    });
  });
  ```

### closeSession<sup>8+</sup>

closeSession(): void;

关闭会话，结束IDM操作。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**需要权限：** ohos.permission.MANAGE_USER_IDM

**示例：**
  ```js
  let userIDM = new account_osAccount.UserIdentityManager();
  userIDM.closeSession();
  ```

### cancel<sup>8+</sup>

cancel(challenge: Uint8Array): void;

根据挑战值取消条目。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**需要权限：** ohos.permission.MANAGE_USER_IDM

**参数：**

| 参数名    | 类型        | 必填 | 说明   |
| -------- | ----------- | ---- | ----- |
| challenge | Uint8Array | 是   | 挑战值。 |

**错误码：**

| 错误码ID | 错误信息            |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid challenge. |

**示例：**
  ```js
  let userIDM = new account_osAccount.UserIdentityManager();
  let challenge = new Uint8Array([0]);
  try {
    userIDM.cancel(challenge);
  } catch(err) {
    console.log("cancel err:" + JSON.stringify(err));
  }
  ```

### delUser<sup>8+</sup>

delUser(token: Uint8Array, callback: IIdmCallback): void;

删除具有身份验证令牌的用户，使用callback方式异步返回结果。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**需要权限：** ohos.permission.MANAGE_USER_IDM

**参数：**

| 参数名    | 类型                           | 必填 | 说明                      |
| -------- | ------------------------------ | --- | ------------------------- |
| token    | Uint8Array                     | 是  | 身份验证令牌。             |
| callback | [IIdmCallback](#iidmcallback8) | 是  | 回调对象，返回删除用户的结果。|

**错误码：**

| 错误码ID | 错误信息        |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300101 | Token is invalid. |

**示例：**
  ```js
  let userIDM = new account_osAccount.UserIdentityManager();
  let token = new Uint8Array([0]);
  try {
    userIDM.delUser(token, {
      onResult: (result, extraInfo) => {
        console.log('delUser result = ' + result);
        console.log('delUser extraInfo = ' + JSON.stringify(extraInfo));
      }
    });
  } catch (e) {
    console.log('delUser exception = ' + JSON.stringify(e));
  }
  ```

### delCred<sup>8+</sup>

delCred(credentialId: Uint8Array, token: Uint8Array, callback: IIdmCallback): void;

删除用户凭据信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**需要权限：** ohos.permission.MANAGE_USER_IDM

**参数：**

| 参数名           | 类型                                            | 必填 | 说明                      |
| --------------- | ----------------------------------- | --- | ---------------------------|
| credentialId    | Uint8Array                          | 是  | 凭证索引。                  |
| token           | Uint8Array                          | 是  | 身份验证令牌。               |
| callback        | [IIdmCallback](#iidmcallback8)      | 是  | 回调对象，返回删除凭据的结果。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid credentialId. |
| 12300101 | Token is invalid. |
| 12300102 | Credential not found. |

**示例：**
  ```js
  let userIDM = new account_osAccount.UserIdentityManager();
  let credentialId = new Uint8Array([0]);
  let token = new Uint8Array([0]);
  try {
    userIDM.delCred(credentialId, token, {
      onResult: (result, extraInfo) => {
          console.log('delCred result = ' + result);
          console.log('delCred extraInfo = ' + JSON.stringify(extraInfo));
      }
    });
  } catch (e) {
    console.log('delCred exception = ' + JSON.stringify(e));
  }
  ```

### getAuthInfo<sup>8+</sup>

getAuthInfo(callback: AsyncCallback&lt;Array&lt;EnrolledCredInfo&gt;&gt;): void;

获取认证信息。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**需要权限：** ohos.permission.USE_USER_IDM

**参数：**

| 参数名    | 类型                                                                     | 必填 | 说明                                                 |
| -------- | ------------------------------------------------------------------------ | ---- | --------------------------------------------- |
| callback | AsyncCallback&lt;Array&lt;[EnrolledCredInfo](#enrolledcredinfo8)&gt;&gt; | 是   | 回调函数。如果成功，err为null，data为当前用户的所有已注册凭据信息；否则为错误对象。|

**错误码：**

| 错误码ID | 错误信息               |
| -------- | --------------------- |
| 12300001 | System service exception. |
| 12300102 | Credential not found. |

**示例：**
  ```js
  let userIDM = new account_osAccount.UserIdentityManager();
  try {
    userIDM.getAuthInfo((err, result) => {
      console.log('getAuthInfo err = ' + JSON.stringify(err));
      console.log('getAuthInfo result = ' + JSON.stringify(result));
    });
  } catch (e) {
    console.log('getAuthInfo exception = ' + JSON.stringify(e));
  }
  ```

### getAuthInfo<sup>8+</sup>

getAuthInfo(authType: AuthType, callback: AsyncCallback&lt;Array&lt;EnrolledCredInfo&gt;&gt;): void;

获取指定类型的认证信息。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**需要权限：** ohos.permission.USE_USER_IDM

**参数：**

| 参数名    | 类型                                               | 必填 | 说明                                                |
| -------- | -------------------------------------------------- | ---- | -------------------------------------------------- |
| authType | [AuthType](#authtype8) | 是   | 认证类型。                                          |
| callback | AsyncCallback&lt;Array&lt;[EnrolledCredInfo](#enrolledcredinfo8)&gt;&gt; | 是   | 回调函数，如果获取成功，err为null，data为当前用户指定类型的所有已注册凭据信息；否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息               |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid authType. |
| 12300102 | Credential not found. |

**示例：**
  ```js
  let userIDM = new account_osAccount.UserIdentityManager();
  try {
    userIDM.getAuthInfo(account_osAccount.AuthType.PIN, (err, result) => {
      console.log('getAuthInfo err = ' + JSON.stringify(err));
      console.log('getAuthInfo result = ' + JSON.stringify(result));
    });
  } catch (e) {
    console.log('getAuthInfo exception = ' + JSON.stringify(e));
  }
  ```

### getAuthInfo<sup>8+</sup>

getAuthInfo(authType?: AuthType): Promise&lt;Array&lt;EnrolledCredInfo&gt;&gt;;

获取认证信息。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**需要权限：** ohos.permission.USE_USER_IDM

**参数：**

| 参数名    | 类型                                | 必填 | 说明      |
| -------- | ----------------------------------- | ---- | -------- |
| authType | [AuthType](#authtype8)              | 否   | 认证类型。|

**返回值：**

| 类型                                         | 说明                                                                     |
| :------------------------------------------- | :----------------------------------------------------------------------- |
| Promise&lt;Array&lt;[EnrolledCredInfo](#enrolledcredinfo8)&gt;&gt; | Promise对象，返回当前用户指定类型的所有已注册凭据信息。|

**错误码：**

| 错误码ID | 错误信息               |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid authType. |
| 12300102 | Credential not found. |

**示例：**
  ```js
  let userIDM = new account_osAccount.UserIdentityManager();
  try {
    userIDM.getAuthInfo(account_osAccount.AuthType.PIN).then((result) => {
      console.log('getAuthInfo result = ' + JSON.stringify(result))
    }).catch((err) => {
      console.log('getAuthInfo error = ' + JSON.stringify(err));
    });
  } catch (e) {
    console.log('getAuthInfo exception = ' + JSON.stringify(e));
  }
  ```

## IInputData<sup>8+</sup>

密码数据回调。

**系统接口：** 此接口为系统接口。

### onSetData<sup>8+</sup>

onSetData: (pinSubType: AuthSubType, data: Uint8Array) => void;

**系统接口：** 此接口为系统接口。

通知设置数据。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名      | 类型                                     | 必填 | 说明                                            |
| ---------- | ---------------------------------------- | ---- | ----------------------------------------------- |
| pinSubType | [AuthSubType](#authsubtype8)             | 是   | 用于认证的凭据子类型。                            |
| data       | Uint8Array                               | 是   | 要设置的数据是凭据，用来在认证、添加、修改凭据操作。 |

**示例：**
  ```js
  let password = new Uint8Array([0, 0, 0, 0, 0, 0]);
  let passwordNumber = new Uint8Array([1, 2, 3, 4]);
  let inputer = {
    onGetData: (pinSubType, callback) => {
        if (pinSubType == account_osAccount.AuthSubType.PIN_NUMBER) {
          callback.onSetData(pinSubType, passwordNumber);
        } else {
          callback.onSetData(pinSubType, password);
        }
    }
  };
  ```

## IInputer<sup>8+</sup>

密码输入框回调。

**系统接口：** 此接口为系统接口。

### onGetData<sup>8+</sup>

onGetData: (pinSubType: AuthSubType, callback: IInputData) => void;

通知获取数据。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名      | 类型                                    | 必填 | 说明             |
| ---------- | --------------------------------------- | ---- | --------------- |
| callback   | [IInputData](#iinputdata8)  | 是   | 指示密码数据回调。|

**示例：**
  ```js
  let password = new Uint8Array([0, 0, 0, 0, 0, 0]);
  let passwordNumber = new Uint8Array([1, 2, 3, 4]);
  let inputer = {
    onGetData: (pinSubType, callback) => {
        if (pinSubType == account_osAccount.AuthSubType.PIN_NUMBER) {
          callback.onSetData(pinSubType, passwordNumber);
        } else {
          callback.onSetData(pinSubType, password);
        }
    }
  };
  let pinAuth = new account_osAccount.PINAuth();
  let result = pinAuth.registerInputer(inputer);
  console.log('registerInputer result: ' + result);
  ```

## IUserAuthCallback<sup>8+</sup>

表示用户认证回调类。

**系统接口：** 此接口为系统接口。

### onResult<sup>8+</sup>

onResult: (result: number, extraInfo: AuthResult) => void;

身份认证结果回调函数，返回结果码和认证结果信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名     | 类型                                    | 必填 | 说明                 |
| --------- | --------------------------------------- | ---- | ------------------- |
| result    | number                                   | 是   | 表示身份认证结果代码。|
| extraInfo | [AuthResult](#authresult8)  | 是   | 表示不同情况下的具体信息，如果认证通过，则在extrainfo中返回认证令牌，如果身份验证失败，则在extrainfo中返回剩余的身份验证时间，如果身份验证执行器被锁定，冻结时间将在extrainfo中返回。|

**示例：**
  ```js
  let authCallback = {
    onResult: (result, extraInfo) => {
      console.log('auth result = ' + result);
      console.log('auth extraInfo = ' + JSON.stringify(extraInfo));
    }
  };
  ```

### onAcquireInfo?<sup>8+</sup>

onAcquireInfo?: (module: number, acquire: number, extraInfo: any) => void;

身份认证信息获取回调函数。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名    | 类型     | 必填 | 说明                           |
| --------- | ------- | ---- | ----------------------------- |
| module    | number  | 是   | 指示用于身份验证的执行器类型。   |
| acquire   | number  | 是   | 指示不同身份验证执行器的tip代码。|
| extraInfo | any     | 是   | 保留参数。                     |

**示例：**
  ```js
  let authCallback = {
    onResult: (result, extraInfo) => {
      console.log('auth result = ' + result)
      console.log('auth extraInfo = ' + JSON.stringify(extraInfo));
    },
    onAcquireInfo: (module, acquire, extraInfo) => {
      console.log('auth module = ' + module);
      console.log('auth acquire = ' + acquire);
      console.info('auth extraInfo = ' + JSON.stringify(extraInfo));
    }
  };
  ```

## IIdmCallback<sup>8+</sup>

表示身份管理回调类。

**系统接口：** 此接口为系统接口。

### onResult<sup>8+</sup>

onResult: (result: number, extraInfo: RequestResult) => void;

身份管理操作结果回调函数，返回结果码和请求结果信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名     | 类型                                    | 必填 | 说明                     |
| --------- | --------------------------------------- | ---- | ----------------------- |
| result    | number                                  | 是   | 表示身份认证结果代码。    |
| extraInfo | [RequestResult](#requestresult8)  | 是   | 针对不同情况传递具体信息。|

**示例：**
  ```js
  let idmCallback = {
    onResult: (result, extraInfo) => {
      console.log('callback result = ' + result)
      console.info('callback extraInfo = ' + JSON.stringify(extraInfo));
    }
  };
  ```

### onAcquireInfo?<sup>8+</sup>

onAcquireInfo?: (module: number, acquire: number, extraInfo: any) => void;

身份管理信息获取回调函数。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名    | 类型     | 必填 | 说明                           |
| --------- | ------- | ---- | ----------------------------- |
| module    | number  | 是   | 指示用于身份验证的执行器类型。   |
| acquire   | number  | 是   | 指示不同身份验证执行器的tip代码。|
| extraInfo | any     | 是   | 保留参数。                     |

**示例：**
  ```js
  let idmCallback = {
    onResult: (result, extraInfo) => {
      console.log('callback result = ' + result)
      console.log('callback onResult = ' + JSON.stringify(extraInfo));
    },
    onAcquireInfo: (module, acquire, extraInfo) => {
      console.log('callback module = ' + module);
      console.log('callback acquire = ' + acquire);
      console.log('callback onacquireinfo = ' + JSON.stringify(extraInfo));
    }
  };
  ```

## GetPropertyRequest<sup>8+</sup>

提供获取属性请求的信息。

**系统接口：** 此接口为系统接口。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Account.OsAccount

| 名称    | 类型                                                          | 必填   | 说明                   |
| -------- | ------------------------------------------------------------- | ----- | ----------------------- |
| authType | [AuthType](#authtype8)                            | 是    | 身份验证凭据类型。        |
| keys     | Array&lt;[GetPropertyType](#getpropertytype8)&gt; | 是    | 指示要获取的属性类型数组。 |

## SetPropertyRequest<sup>8+</sup>

提供设置属性请求的信息。

**系统接口：** 此接口为系统接口。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Account.OsAccount

| 名称    | 类型                                             | 必填   | 说明                 |
| -------- | ------------------------------------------------ | ----- | -------------------- |
| authType | [AuthType](#authtype8)               | 是    | 身份验证凭据类型。     |
| key     | [SetPropertyType](#setpropertytype8) | 是    | 指示要设置的属性类型。 |
| setInfo  | Uint8Array                                       | 是    | 指示要设置的信息。     |

## ExecutorProperty<sup>8+</sup>

提供执行器的属性。

**系统接口：** 此接口为系统接口。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Account.OsAccount

| 名称        | 类型                                     | 必填   | 说明              |
| ------------ | ---------------------------------------- | ----- | ----------------- |
| result       | number                                   | 是    | 指示结果。         |
| authSubType  | [AuthSubType](#authsubtype8) | 是    | 指示认证凭据子类型。|
| remainTimes  | number                                   | 否    | 指示剩余时间。     |
| freezingTime | number                                   | 否    | 指示冻结时间。     |

## AuthResult<sup>8+</sup>

表示认证结果的信息。

**系统接口：** 此接口为系统接口。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Account.OsAccount

| 名称        | 类型        | 必填   | 说明              |
| ------------ | ----------- | ----- | ----------------- |
| token        | Uint8Array  | 否    | 指示认证令牌。     |
| remainTimes  | number      | 否    | 指示剩余时间。     |
| freezingTime | number      | 否    | 指示冻结时间。     |

## CredentialInfo<sup>8+</sup>

表示凭证信息。

**系统接口：** 此接口为系统接口。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Account.OsAccount

| 名称        | 类型                                     | 必填   | 说明              |
| ------------ | ---------------------------------------- | ----- | ----------------- |
| credType     | [AuthType](#authtype8)       | 是    | 指示凭据类型。     |
| credSubType  | [AuthSubType](#authsubtype8) | 是    | 指示凭据子类型。   |
| token        | Uint8Array                           | 是    | 指示认证令牌。     |

## RequestResult<sup>8+</sup>

表示请求结果的信息。

**系统接口：** 此接口为系统接口。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Account.OsAccount

| 名称        | 类型        | 必填   | 说明              |
| ------------ | ----------- | ----- | ----------------- |
| credentialId | Uint8Array  | 否    | 指示凭据索引。     |

## EnrolledCredInfo<sup>8+</sup>

表示已注册凭据的信息。

**系统接口：** 此接口为系统接口。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Account.OsAccount

| 名称        | 类型                                     | 必填   | 说明              |
| ------------ | ---------------------------------------- | ----- | ------------------- |
| credentialId | Uint8Array                               | 是    | 指示凭据索引。       |
| authType     | [AuthType](#authtype8)       | 是    | 指示认证凭据类型。   |
| authSubType  | [AuthSubType](#authsubtype8) | 是    | 指示认证凭据子类型。 |
| templateId   | Uint8Array                               | 是    | 指示凭据模板ID。     |

## GetPropertyType<sup>8+</sup>

表示要获取的属性类型的枚举。

**系统接口：** 此接口为系统接口。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Account.OsAccount

| 名称           | 值 | 说明      |
| ------------- | ------ | --------- |
| AUTH_SUB_TYPE | 1      | 认证子类型。 |
| REMAIN_TIMES  | 2      | 剩余时间。   |
| FREEZING_TIME | 3      | 冻结时间。   |

## SetPropertyType<sup>8+</sup>

表示要设置的属性类型的枚举。

**系统接口：** 此接口为系统接口。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Account.OsAccount

| 名称           | 值 | 说明        |
| -------------- | ----- | ----------- |
| INIT_ALGORITHM | 1     | 初始化算法。 |

## AuthType<sup>8+</sup>

表示身份验证的凭据类型的枚举。

**系统接口：** 此接口为系统接口。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Account.OsAccount

| 名称  | 值 | 说明             |
| ----- | ----- | ---------------- |
| PIN   | 1     | 指示PIN认证类型。 |
| FACE  | 2     | 指示脸部认证类型。|

## AuthSubType<sup>8+</sup>

表示用于认证的凭据子类型的枚举。

**系统接口：** 此接口为系统接口。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Account.OsAccount

| 名称       | 值 | 说明               |
| ---------- | ----- | ------------------ |
| PIN_SIX    | 10000 | 表示6位凭证。       |
| PIN_NUMBER | 10001 | 表示自定义数字凭证。 |
| PIN_MIXED  | 10002 | 表示自定义混合凭据。 |
| FACE_2D    | 20000 | 指示2D 人脸凭证。   |
| FACE_3D    | 20001 | 指示3D 人脸凭证。   |

## AuthTrustLevel<sup>8+</sup>

表示认证结果的受信任级别的枚举。

**系统接口：** 此接口为系统接口。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Account.OsAccount

| 名称  | 值 | 说明        |
| ---- | ------ | ----------- |
| ATL1 | 10000  | 信任级别 1。 |
| ATL2 | 20000  | 信任级别 2。 |
| ATL3 | 30000  | 信任级别 3。 |
| ATL4 | 40000  | 信任级别 4。 |

## Module<sup>8+</sup>

表示获取信息的模块的枚举。

**系统接口：** 此接口为系统接口。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Account.OsAccount

| 名称       | 值 | 说明                     |
| --------- | ------ | ------------------------ |
| FACE_AUTH | 1      | 表示从人脸认证获取的信息。 |

## ResultCode<sup>8+</sup>

表示身份验证结果码。

**系统接口：** 此接口为系统接口。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Account.OsAccount

| 名称                    | 值 | 说明                                     |
| ----------------------- | ----- | ---------------------------------------- |
| SUCCESS                 | 0     | 表示身份验证成功或支持此功能。             |
| FAIL                    | 1     | 表示验证器无法识别用户。                   |
| GENERAL_ERROR           | 2     | 表示其他错误。                            |
| CANCELED                | 3     | 表示身份验证已取消。                       |
| TIMEOUT                 | 4     | 表示身份验证已超时。                       |
| TYPE_NOT_SUPPORT        | 5     | 表示不支持此身份验证类型。                 |
| TRUST_LEVEL_NOT_SUPPORT | 6     | 表示不支持身份验证信任级别。               |
| BUSY                    | 7     | 表示身份验证任务正忙。等待几秒钟，然后重试。 |
| INVALID_PARAMETERS      | 8     | 表示参数不正确。                          |
| LOCKED                  | 9     | 指示身份验证器已锁定。                     |
| NOT_ENROLLED            | 10    | 表示用户尚未注册验证器。                   |

## FaceTipsCode<sup>8+</sup>

表示人脸验证过程中提示的枚举。

**系统接口：** 此接口为系统接口。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Account.OsAccount

| 名称                          | 值 | 说明                                     |
| ----------------------------- | ----- | ---------------------------------------- |
| FACE_AUTH_TIP_TOO_BRIGHT      | 1     | 表示由于高照明，获得的面部图像太亮。         |
| FACE_AUTH_TIP_TOO_DARK        | 2     | 表示由于照明度低，获得的面部图像太暗。       |
| FACE_AUTH_TIP_TOO_CLOSE       | 3     | 表示面部离设备太近。                       |
| FACE_AUTH_TIP_TOO_FAR         | 4     | 表示面部离设备太远。                       |
| FACE_AUTH_TIP_TOO_HIGH        | 5     | 表示设备太高，仅捕捉面部上部。              |
| FACE_AUTH_TIP_TOO_LOW         | 6     | 表示设备太低，仅捕捉面部下部。              |
| FACE_AUTH_TIP_TOO_RIGHT       | 7     | 指示设备向右偏移，并且仅捕捉面部的右侧部分。 |
| FACE_AUTH_TIP_TOO_LEFT        | 8     | 指示设备向左偏移，并且仅捕捉面部的左侧部分。 |
| FACE_AUTH_TIP_TOO_MUCH_MOTION | 9     | 表示面部信息收集过程中面部移动过快。         |
| FACE_AUTH_TIP_POOR_GAZE       | 10    | 表示面未朝向设备。                         |
| FACE_AUTH_TIP_NOT_DETECTED    | 11    | 表示未检测到人脸。                         |

## FingerprintTips<sup>8+</sup>

表示指纹身份验证过程中提示的枚举。

**系统接口：** 此接口为系统接口。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Account.OsAccount

| 名称                          | 值 | 说明                                            |
| ----------------------------- | ----- | ----------------------------------------------- |
| FINGERPRINT_TIP_GOOD          | 0     | 表明采集的图像良好。                              |
| FINGERPRINT_TIP_IMAGER_DIRTY  | 1     | 表示由于传感器上可疑或检测到污垢，指纹图像噪声过大。 |
| FINGERPRINT_TIP_INSUFFICIENT  | 2     | 表示由于检测到的情况，指纹图像噪声太大，无法处理。   |
| FINGERPRINT_TIP_PARTIAL       | 3     | 指示仅检测到部分指纹图像。                         |
| FINGERPRINT_TIP_TOO_FAST      | 4     | 表示指纹图像由于快速运动而不完整。                  |
| FINGERPRINT_TIP_TOO_SLOW      | 5     | 表示由于缺少运动，指纹图像无法读取。                |

## OsAccountInfo

表示系统帐号信息。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Account.OsAccount。

| 名称                         | 类型                                                         | 必填 | 说明                              |
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
| domainInfo<sup>8+</sup>        | [DomainAccountInfo](#domainaccountinfo8)                      | 否   | 域帐号信息                        |

## DomainAccountInfo<sup>8+</sup>

表示域帐号信息。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Account.OsAccount。

| 名称      | 类型   | 必填 | 说明       |
| ----------- | ------ | ---- | ---------- |
| domain      | string | 是   | 域名。     |
| accountName | string | 是   | 域帐号名。 |

## 系统帐号约束列表

| 约束                                  | 说明                           |
| ------------------------------------- | ------------------------------ |
| constraint.wifi                       | 禁止使用Wi-Fi                  |
| constraint.wifi.set                   | 禁止配置Wi-Fi                  |
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

表示约束来源类型信息。

**系统接口：** 此接口为系统接口。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Account.OsAccount。

| 名称      | 类型   | 必填 | 说明       |
| ----------- | ------ | ---- | ---------- |
| localId      | number | 是   | 系统帐号ID     |
| type | [ConstraintSourceType](#constraintsourcetype) | 是   | 约束来源类型 |

## ConstraintSourceType<sup>9+</sup>

表示约束来源类型的枚举。

**系统接口：** 此接口为系统接口。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Account.OsAccount。

| 名称   | 值 | 说明         |
| ------ | ------ | ------------ |
| CONSTRAINT_NOT_EXIST  | 0      | 约束不存在 |
| CONSTRAINT_TYPE_BASE | 1      | 约束源自系统设置   |
| CONSTRAINT_TYPE_DEVICE_OWNER  | 2   | 约束源自设备所有者设置   |
| CONSTRAINT_TYPE_PROFILE_OWNER  | 3  | 约束源自资料所有者设置   |