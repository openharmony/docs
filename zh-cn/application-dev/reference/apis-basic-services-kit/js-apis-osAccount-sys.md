# @ohos.account.osAccount (系统账号管理)(系统接口)

本模块提供管理系统账号的基础能力，包括系统账号的添加、删除、查询、设置、订阅、启动等功能。

> **说明：**
>
> - 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 当前页面仅包含本模块的系统接口，其他公开接口参见[ohos.account.osAccount (系统账号管理)](js-apis-osAccount.md)。

## 导入模块

```ts
import { osAccount } from '@kit.BasicServicesKit';
```

## AccountManager

系统账号管理类。

### activateOsAccount

activateOsAccount(localId: number, callback: AsyncCallback&lt;void&gt;): void

激活指定系统账号。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS_EXTENSION

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                       | 必填 | 说明                                                |
| -------- | ------------------------- | ---- | -------------------------------------------------- |
| localId  | number                    | 是   | 系统账号ID。                  |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。当账号激活成功时，err为null，否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid localId.    |
| 12300003 | Account not found. |
| 12300008 | Restricted Account. |
| 12300010 | Service busy. Possible causes: The target account is being operated. |
| 12300016 | The number of logged in accounts reaches the upper limit. |

**示例：** 激活ID为100的系统账号
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let localId: number = 100;
  try {
    accountManager.activateOsAccount(localId, (err: BusinessError)=>{
      if (err) {
        console.error(`activateOsAccount failed, code is ${err.code}, message is ${err.message}`);
      } else {
        console.log('activateOsAccount successfully');
      }
    });
  } catch (err) {
    console.error('activateOsAccount failed, error:' + JSON.stringify(err));
  }
  ```

### activateOsAccount

activateOsAccount(localId: number): Promise&lt;void&gt;

激活指定系统账号。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS_EXTENSION

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名  | 类型   | 必填 | 说明                 |
| ------- | ------ | ---- | -------------------- |
| localId | number | 是   | 系统账号ID。 |

**返回值：**

| 类型                | 说明                                  |
| ------------------- | ------------------------------------ |
| Promise&lt;void&gt; | Promise对象，无返回结果的Promise对象。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid localId.    |
| 12300003 | Account not found. |
| 12300008 | Restricted Account. |
| 12300010 | Service busy. Possible causes: The target account is being operated. |
| 12300016 | The number of logged in accounts reaches the upper limit. |

**示例：** 激活ID为100的系统账号
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let localId: number = 100;
  try {
    accountManager.activateOsAccount(localId).then(() => {
      console.log('activateOsAccount successfully');
    }).catch((err: BusinessError) => {
      console.error('activateOsAccount failed, err:' + JSON.stringify(err));
    });
  } catch (e) {
    console.error('activateOsAccount exception: ' + JSON.stringify(e));
  }
  ```

### deactivateOsAccount<sup>12+</sup>

deactivateOsAccount(localId: number): Promise&lt;void&gt;

注销（退出登录）指定系统账号。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS_EXTENSION

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名  | 类型   | 必填 | 说明                 |
| ------- | ------ | ---- | -------------------- |
| localId | number | 是   | 系统账号ID。 |

**返回值：**

| 类型                | 说明                                  |
| ------------------- | ------------------------------------ |
| Promise&lt;void&gt; | Promise对象，无返回结果的Promise对象。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300003 | Account not found. |
| 12300008 | Restricted Account. |
| 12300010 | Service busy. Possible causes: The target account is being operated. |

**示例：** 注销ID为100的系统账号
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let localId: number = 100;
  try {
    accountManager.deactivateOsAccount(localId).then(() => {
      console.log('deactivateOsAccount successfully');
    }).catch((err: BusinessError) => {
      console.error('deactivateOsAccount failed, err:' + JSON.stringify(err));
    });
  } catch (e) {
    console.error('deactivateOsAccount exception: ' + JSON.stringify(e));
  }
  ```

### isOsAccountActivated<sup>11+</sup>

isOsAccountActivated(localId: number): Promise&lt;boolean&gt;

判断指定系统账号是否处于激活状态。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS 或 ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名  | 类型   | 必填 | 说明                               |
| ------- | ------ | ---- | --------------------------------- |
| localId | number | 是   | 系统账号ID。 |

**返回值：**

| 类型                   | 说明                                                       |
| ---------------------- | ---------------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise对象。返回true表示账号已激活；返回false表示账号未激活。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300003 | Account not found. |

**示例：** 判断ID为100的系统账号是否处于激活状态

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let localId: number = 100;
  try {
    accountManager.isOsAccountActivated(localId).then((isActivated: boolean) => {
      console.log('isOsAccountActivated successfully, isActivated: ' + isActivated);
    }).catch((err: BusinessError) => {
      console.error('isOsAccountActivated failed, error: ' + JSON.stringify(err));
    });
  } catch (err) {
    console.error('isOsAccountActivated exception: ' + JSON.stringify(err));
  }
  ```

### isOsAccountConstraintEnabled<sup>11+</sup>

isOsAccountConstraintEnabled(localId: number, constraint: string): Promise&lt;boolean&gt;

判断指定系统账号是否使能指定约束。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS 或 ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名     | 类型   | 必填 | 说明                                |
| ---------- | ------ | ---- | ---------------------------------- |
| localId    | number | 是   | 系统账号ID。  |
| constraint | string | 是   | 指定的[约束](js-apis-osAccount.md#系统账号约束列表)名称。 |

**返回值：**

| 类型                   | 说明                                                                  |
| --------------------- | --------------------------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise对象。返回true表示已使能指定的约束；返回false表示未使能指定的约束。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300003 | Account not found. |

**示例：** 判断ID为100的系统账号是否有禁止使用Wi-Fi的约束

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let localId: number = 100;
  let constraint: string = 'constraint.wifi';
  try {
    accountManager.isOsAccountConstraintEnabled(localId, constraint).then((isEnabled: boolean) => {
      console.log('isOsAccountConstraintEnabled successfully, isEnabled: ' + isEnabled);
    }).catch((err: BusinessError) => {
      console.error('isOsAccountConstraintEnabled failed, error: ' + JSON.stringify(err));
    });
  } catch (err) {
    console.error('isOsAccountConstraintEnabled exception: ' + JSON.stringify(err));
  }
  ```

### isOsAccountUnlocked<sup>11+</sup>

isOsAccountUnlocked(localId: number): Promise&lt;boolean&gt;

检查指定系统账号是否已验证。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS 或 ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名  | 类型   | 必填 | 说明                                                              |
| ------- | ------ | ---- | --------------------------------------------------------------- |
| localId | number | 是   | 系统账号ID。不填则检查当前系统账号是否已验证。 |

**返回值：**

| 类型                   | 说明                                                               |
| ---------------------- | ----------------------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise对象。返回true表示当前账号已认证解锁；返回false表示当前账号未认证解锁。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300003 | Account not found. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let localId: number = 100;
  try {
    accountManager.isOsAccountUnlocked(localId).then((isVerified: boolean) => {
      console.log('isOsAccountUnlocked successfully, isVerified: ' + isVerified);
    }).catch((err: BusinessError) => {
      console.error('isOsAccountUnlocked failed, error: ' + JSON.stringify(err));
    });
  } catch (err) {
    console.error('isOsAccountUnlocked exception: ' + JSON.stringify(err));
  }
  ```

### removeOsAccount

removeOsAccount(localId: number, callback: AsyncCallback&lt;void&gt;): void

删除指定系统账号。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                                 |
| -------- | ------------------------- | ---- | -------------------------------------------------- |
| localId  | number                    | 是   | 系统账号ID。                  |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。如果删除账号成功，err为null，否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid localId.    |
| 12300003 | Account not found. |
| 12300008 | Restricted Account. |
| 12300010 | Service busy. Possible causes: The target account is being operated. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let accountName: string = 'testAccountName';
  try {
    accountManager.createOsAccount(accountName, osAccount.OsAccountType.NORMAL,
      (err: BusinessError, osAccountInfo: osAccount.OsAccountInfo) => {
        accountManager.removeOsAccount(osAccountInfo.localId, (err: BusinessError)=>{
          if (err) {
            console.error('removeOsAccount failed, error: ' + JSON.stringify(err));
          } else {
            console.log('removeOsAccount successfully');
          }
      });
    });
  } catch (err) {
    console.error('removeOsAccount exception: ' + JSON.stringify(err));
  }
  ```

### removeOsAccount

removeOsAccount(localId: number): Promise&lt;void&gt;

删除指定系统账号。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名  | 类型   | 必填 | 说明                               |
| ------- | ------ | ---- | --------------------------------- |
| localId | number | 是   | 系统账号ID。 |

**返回值：**

| 类型                | 说明                                  |
| ------------------- | ------------------------------------ |
| Promise&lt;void&gt; | Promise对象，无返回结果的Promise对象。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid localId.    |
| 12300003 | Account not found. |
| 12300008 | Restricted Account. |
| 12300010 | Service busy. Possible causes: The target account is being operated. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let accountName: string = 'testAccountName';
  try {
    accountManager.createOsAccount(accountName, osAccount.OsAccountType.NORMAL,
      (err: BusinessError, osAccountInfo: osAccount.OsAccountInfo)=>{
        accountManager.removeOsAccount(osAccountInfo.localId).then(() => {
          console.log('removeOsAccount successfully');
        }).catch((err: BusinessError) => {
            console.error('removeOsAccount failed, error: ' + JSON.stringify(err));
        });
    });
  } catch (err) {
    console.error('removeOsAccount exception: ' + JSON.stringify(err));
  }
  ```

### setOsAccountConstraints

setOsAccountConstraints(localId: number, constraints: Array&lt;string&gt;, enable: boolean,callback: AsyncCallback&lt;void&gt;): void

为指定系统账号设置/删除约束。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名      | 类型                      | 必填 | 说明                                             |
| ----------- | ------------------------- | ---- | ----------------------------------------------- |
| localId     | number                    | 是   | 系统账号ID。               |
| constraints | Array&lt;string&gt;       | 是   | 待设置/删除的[约束](js-apis-osAccount.md#系统账号约束列表)列表。        |
| enable      | boolean                   | 是   | 设置(true)/删除(false) 。                          |
| callback    | AsyncCallback&lt;void&gt; | 是   | 回调函数。如果设置成功，err为null，否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid localId or constraints.    |
| 12300003 | Account not found. |
| 12300008 | Restricted Account. |

**示例：** 给ID为100的系统账号设置禁止使用Wi-Fi的约束

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let localId: number = 100;
  let constraint: string = 'constraint.wifi';
  try {
    accountManager.setOsAccountConstraints(localId, [constraint], true, (err: BusinessError) => {
      if (err) {
        console.error('setOsAccountConstraints failed, error: ' + JSON.stringify(err));
      } else {
        console.log('setOsAccountConstraints successfully');
      }
    });
  } catch (err) {
    console.error('setOsAccountConstraints exception: ' + JSON.stringify(err));
  }
  ```

### setOsAccountConstraints

setOsAccountConstraints(localId: number, constraints: Array&lt;string&gt;, enable: boolean): Promise&lt;void&gt;

为指定系统账号设置/删除约束。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名      | 类型                | 必填 | 说明                                         |
| ----------- | ------------------- | ---- | -------------------------------------------- |
| localId     | number              | 是   | 系统账号ID。           |
| constraints | Array&lt;string&gt; | 是   | 待设置/删除的[约束](js-apis-osAccount.md#系统账号约束列表)列表。    |
| enable      | boolean             | 是   | 设置(true)/删除(false)。                     |

**返回值：**

| 类型                | 说明                                 |
| :------------------ | :----------------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果的Promise对象。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid localId or constraints.    |
| 12300003 | Account not found. |
| 12300008 | Restricted Account. |

**示例：** 删除ID为100的系统账号的禁止使用Wi-Fi的约束

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let localId: number = 100;
  try {
    accountManager.setOsAccountConstraints(localId, ['constraint.location.set'], false).then(() => {
      console.log('setOsAccountConstraints succsuccessfully');
    }).catch((err: BusinessError) => {
      console.error('setOsAccountConstraints failed, error: ' + JSON.stringify(err));
    });
  } catch (err) {
    console.error('setOsAccountConstraints exception: ' + JSON.stringify(err));
  }
  ```

### setOsAccountName

setOsAccountName(localId: number, localName: string, callback: AsyncCallback&lt;void&gt;): void

设置指定系统账号的账号名。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名    | 类型                      | 必填 | 说明                                             |
| :-------- | ------------------------- | ---- | ----------------------------------------------- |
| localId   | number                    | 是   | 系统账号ID。               |
| localName | string                    | 是   | 账号名，最大长度为1024个字符。                          |
| callback  | AsyncCallback&lt;void&gt; | 是   | 回调函数。如果设置成功，err为null，否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid localId or localName. |
| 12300003 | Account not found. |
| 12300008 | Restricted Account. |

**示例：** 将ID为100的系统账号的账号名设置成demoName

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let localId: number = 100;
  let name: string = 'demoName';
  try {
    accountManager.setOsAccountName(localId, name, (err: BusinessError) => {
      if (err) {
        console.error('setOsAccountName failed, error: ' + JSON.stringify(err));
      } else {
        console.log('setOsAccountName successfully');
      }
    });
  } catch (err) {
    console.error('setOsAccountName exception: ' + JSON.stringify(err));
  }
  ```

### setOsAccountName

setOsAccountName(localId: number, localName: string): Promise&lt;void&gt;

设置指定系统账号的账号名。使用Promise异步调用。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名    | 类型   | 必填 | 说明                                |
| --------- | ------ | ---- | --------------------------------- |
| localId   | number | 是   | 系统账号ID。 |
| localName | string | 是   | 账号名，最大长度为1024。            |

**返回值：**

| 类型                | 说明                                  |
| ------------------- | ------------------------------------ |
| Promise&lt;void&gt; | Promise对象，无返回结果的Promise对象。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid localId or localName.    |
| 12300003 | Account not found. |
| 12300008 | Restricted Account. |

**示例：** 将ID为100的系统账号的账号名设置成demoName

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let localId: number = 100;
  let name: string = 'testName';
  try {
    accountManager.setOsAccountName(localId, name).then(() => {
      console.log('setOsAccountName successfully');
    }).catch((err: BusinessError) => {
      console.error('setOsAccountName failed, error: ' + JSON.stringify(err));
    });
  } catch (err) {
    console.error('setOsAccountName exception: ' + JSON.stringify(err));
  }
  ```

### queryMaxOsAccountNumber

queryMaxOsAccountNumber(callback: AsyncCallback&lt;number&gt;): void

查询允许创建的系统账号的最大数量。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                                                              |
| -------- | --------------------------- | ---- | -------------------------------------------------------------------------------- |
| callback | AsyncCallback&lt;number&gt; | 是   | 回调函数，如果查询成功，err为null，data为允许创建的系统账号的最大数量；否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息       |
| -------- | ------------- |
| 202 | Not system application.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 12300001 | The system service works abnormally. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  try {
    accountManager.queryMaxOsAccountNumber((err: BusinessError, maxCnt: number) => {
      if (err) {
        console.error('queryMaxOsAccountNumber failed, error:' + JSON.stringify(err));
      } else {
        console.log('queryMaxOsAccountNumber successfully, maxCnt:' + maxCnt);
      }
    });
  } catch (err) {
    console.error('queryMaxOsAccountNumber exception: ' + JSON.stringify(err));
  }
  ```

### queryMaxOsAccountNumber

queryMaxOsAccountNumber(): Promise&lt;number&gt;

查询允许创建的系统账号的最大数量。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**返回值：**

| 类型                  | 说明                                         |
| --------------------- | ------------------------------------------- |
| Promise&lt;number&gt; | Promise对象，返回允许创建的系统账号的最大数量。 |

**错误码：**

| 错误码ID | 错误信息       |
| -------- | ------------- |
| 202 | Not system application.|
| 12300001 | The system service works abnormally. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  try {
    accountManager.queryMaxOsAccountNumber().then((maxCnt: number) => {
      console.log('queryMaxOsAccountNumber successfully, maxCnt: ' + maxCnt);
    }).catch((err: BusinessError) => {
      console.error('queryMaxOsAccountNumber failed, error: ' + JSON.stringify(err));
    });
  } catch (err) {
    console.error('queryMaxOsAccountNumber exception: ' + JSON.stringify(err));
  }
  ```

### queryMaxLoggedInOsAccountNumber<sup>12+</sup>

queryMaxLoggedInOsAccountNumber(): Promise&lt;number&gt;

查询允许同时登录的系统账号的最大数量。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**返回值：**

| 类型                  | 说明                                         |
| --------------------- | ------------------------------------------- |
| Promise&lt;number&gt; | Promise对象，返回允许登录的系统账号的最大数量。 |

**错误码：**

| 错误码ID | 错误信息       |
| -------- | ------------- |
| 202 | Not system application.|
| 12300001 | The system service works abnormally. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  try {
    accountManager.queryMaxLoggedInOsAccountNumber().then((maxNum: number) => {
      console.log('queryMaxLoggedInOsAccountNumber successfully, maxNum: ' + maxNum);
    }).catch((err: BusinessError) => {
      console.error('queryMaxLoggedInOsAccountNumber failed, error: ' + JSON.stringify(err));
    });
  } catch (err) {
    console.error('queryMaxLoggedInOsAccountNumber exception: ' + JSON.stringify(err));
  }
  ```

### getEnabledOsAccountConstraints<sup>11+</sup>

getEnabledOsAccountConstraints(localId: number): Promise&lt;Array&lt;string&gt;&gt;

获取指定系统账号已使能的的全部约束。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS 或 ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名  | 类型   | 必填 | 说明         |
| ------- | ------ | ---- | ------------ |
| localId | number | 是   | 系统账号ID。 |

**返回值：**

| 类型                               | 说明                                                       |
| ---------------------------------- | ---------------------------------------------------------- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise对象，返回指定系统账号已使能的的全部[约束](js-apis-osAccount.md#系统账号约束列表)。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 12300001 | The system service works abnormally. |
| 12300003 | Account not found. |

**示例：** 获取ID为100的系统账号的全部约束

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let localId: number = 100;
  try {
    accountManager.getEnabledOsAccountConstraints(localId).then((constraints: string[]) => {
      console.log('getEnabledOsAccountConstraints, constraints: ' + constraints);
    }).catch((err: BusinessError) => {
      console.error('getEnabledOsAccountConstraints err: ' + JSON.stringify(err));
    });
  } catch (e) {
    console.error('getEnabledOsAccountConstraints exception: ' + JSON.stringify(e));
  }
  ```

### queryAllCreatedOsAccounts

queryAllCreatedOsAccounts(callback: AsyncCallback&lt;Array&lt;OsAccountInfo&gt;&gt;): void

查询已创建的所有系统账号的信息列表。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                               |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------------------- |
| callback | AsyncCallback&lt;Array&lt;[OsAccountInfo](js-apis-osAccount.md#osaccountinfo)&gt;&gt; | 是   | 回调函数。如果查询成功，err为null，data为已创建的所有系统账号的信息列表；否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息       |
| -------- | ------------- |
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 12300001 | The system service works abnormally. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  try {
    accountManager.queryAllCreatedOsAccounts((err: BusinessError, accountArr: osAccount.OsAccountInfo[])=>{
      if (err) {
        console.error('queryAllCreatedOsAccounts exception:' + JSON.stringify(err));
      } else {
        console.log('queryAllCreatedOsAccounts accountArr:' + JSON.stringify(accountArr));
      }
    });
  } catch (e) {
    console.error('queryAllCreatedOsAccounts exception: ' + JSON.stringify(e));
  }
  ```

### queryAllCreatedOsAccounts

queryAllCreatedOsAccounts(): Promise&lt;Array&lt;OsAccountInfo&gt;&gt;

查询已创建的所有系统账号的信息列表。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**返回值：**

| 类型                                                        | 说明                                           |
| ----------------------------------------------------------- | --------------------------------------------- |
| Promise&lt;Array&lt;[OsAccountInfo](js-apis-osAccount.md#osaccountinfo)&gt;&gt; | Promise对象，返回已创建的所有系统账号的信息列表。 |

**错误码：**

| 错误码ID | 错误信息       |
| -------- | ------------- |
| 201 | Permission denied.|
| 202 | Not system application.|
| 12300001 | The system service works abnormally. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  try {
    accountManager.queryAllCreatedOsAccounts().then((accountArr: osAccount.OsAccountInfo[]) => {
      console.log('queryAllCreatedOsAccounts, accountArr: ' + JSON.stringify(accountArr));
    }).catch((err: BusinessError) => {
      console.error('queryAllCreatedOsAccounts err: ' + JSON.stringify(err));
    });
  } catch (e) {
    console.error('queryAllCreatedOsAccounts exception: ' + JSON.stringify(e));
  }
  ```

### createOsAccount

createOsAccount(localName: string, type: OsAccountType, callback: AsyncCallback&lt;OsAccountInfo&gt;): void

创建一个系统账号。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名    | 类型                                                 | 必填 | 说明                                                                         |
| :-------- | ---------------------------------------------------- | ---- | --------------------------------------------------------------------------- |
| localName | string                                               | 是   | 创建的系统账号的名称。                                                        |
| type      | [OsAccountType](js-apis-osAccount.md#osaccounttype)                      | 是   | 创建的系统账号的类型。                                                        |
| callback  | AsyncCallback&lt;[OsAccountInfo](js-apis-osAccount.md#osaccountinfo)&gt; | 是   | 回调函数。如果创建成功，err为null，data为新创建的系统账号的信息；否则为错误对象。 |

**错误码：**

| 错误码ID  | 错误信息                   |
| -------- | ------------------------- |
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid localName or type. |
| 12300004 | Local name already exists. |
| 12300005 | Multi-user not supported. |
| 12300006 | Unsupported account type. |
| 12300007 | The number of accounts has reached the upper limit. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  try {
    accountManager.createOsAccount('testName', osAccount.OsAccountType.NORMAL,
      (err: BusinessError, osAccountInfo: osAccount.OsAccountInfo)=>{
      if (err) {
        console.error('createOsAccount exception:' + JSON.stringify(err));
      } else {
        console.log('createOsAccount osAccountInfo:' + JSON.stringify(osAccountInfo));
      }
    });
  } catch (e) {
    console.error('createOsAccount exception: ' + JSON.stringify(e));
  }
  ```

### createOsAccount

createOsAccount(localName: string, type: OsAccountType, options?: CreateOsAccountOptions): Promise&lt;OsAccountInfo&gt;

创建一个系统账号。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名    | 类型                            | 必填 | 说明                   |
| --------- | ------------------------------- | ---- | ---------------------- |
| localName | string                          | 是   | 创建的系统账号的名称。 |
| type      | [OsAccountType](js-apis-osAccount.md#osaccounttype) | 是   | 创建的系统账号的类型。 |
| options      | [CreateOsAccountOptions](js-apis-osAccount-sys.md#createosaccountoptions12) | 否   | 创建系统账号的选项，默认为空。 <br/>从API version 12开始支持该可选参数。|

**返回值：**

| 类型                                           | 说明                                  |
| ---------------------------------------------- | ------------------------------------- |
| Promise&lt;[OsAccountInfo](js-apis-osAccount.md#osaccountinfo)&gt; | Promise对象，返回新创建的系统账号的信息。 |

**错误码：**

| 错误码ID  | 错误信息                   |
| -------- | ------------------------- |
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid localName, type or options. |
| 12300004 | Local name already exists. |
| 12300005 | Multi-user not supported. |
| 12300006 | Unsupported account type. |
| 12300007 | The number of accounts has reached the upper limit. |
| 12300015 | The short name already exists. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let options: osAccount.CreateOsAccountOptions = {
    shortName: 'myShortName',
    disallowedPreinstalledBundles: [],
    allowedPreinstalledBundles: [],
  }
  try {
    accountManager.createOsAccount('testAccountName', osAccount.OsAccountType.NORMAL, options).then(
      (accountInfo: osAccount.OsAccountInfo) => {
      console.log('createOsAccount, accountInfo: ' + JSON.stringify(accountInfo));
    }).catch((err: BusinessError) => {
      console.error('createOsAccount err: ' + JSON.stringify(err));
    });
  } catch (e) {
    console.error('createOsAccount exception: ' + JSON.stringify(e));
  }
  ```

### createOsAccountForDomain<sup>8+</sup>

createOsAccountForDomain(type: OsAccountType, domainInfo: DomainAccountInfo, callback: AsyncCallback&lt;OsAccountInfo&gt;): void

根据域账号信息，创建一个系统账号并将其与域账号关联。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名     | 类型                                                 | 必填 | 说明                                                                         |
| ---------- | ---------------------------------------------------- | ---- | -------------------------------------------------------------------------- |
| type       | [OsAccountType](js-apis-osAccount.md#osaccounttype)                      | 是   | 创建的系统账号的类型。                                                       |
| domainInfo | [DomainAccountInfo](#domainaccountinfo8)              | 是   | 域账号信息。                                                               |
| callback   | AsyncCallback&lt;[OsAccountInfo](js-apis-osAccount.md#osaccountinfo)&gt; | 是   | 回调函数。如果创建成功，err为null，data为新创建的系统账号的信息；否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息                     |
| -------- | ------------------- |
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.|
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid type or domainInfo. |
| 12300004 | Account already exists. |
| 12300005 | Multi-user not supported. |
| 12300006 | Unsupported account type. |
| 12300007 | The number of accounts has reached the upper limit. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let domainInfo: osAccount.DomainAccountInfo =
    {domain: 'testDomain', accountName: 'testAccountName'};
  try {
    accountManager.createOsAccountForDomain(osAccount.OsAccountType.NORMAL, domainInfo,
      (err: BusinessError, osAccountInfo: osAccount.OsAccountInfo)=>{
      if (err) {
        console.error('createOsAccountForDomain exception:' + JSON.stringify(err));
      } else {
        console.log('createOsAccountForDomain osAccountInfo:' + JSON.stringify(osAccountInfo));
      }
    });
  } catch (e) {
    console.error('createOsAccountForDomain exception: ' + JSON.stringify(e));
  }
  ```

### createOsAccountForDomain<sup>8+</sup>

createOsAccountForDomain(type: OsAccountType, domainInfo: DomainAccountInfo, options?: CreateOsAccountForDomainOptions): Promise&lt;OsAccountInfo&gt;

根据传入的域账号信息，创建与其关联的系统账号。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名     | 类型                                      | 必填 | 说明                 |
| ---------- | ---------------------------------------- | ---- | -------------------- |
| type       | [OsAccountType](js-apis-osAccount.md#osaccounttype)          | 是   | 创建的系统账号的类型。 |
| domainInfo | [DomainAccountInfo](#domainaccountinfo8) | 是   | 域账号信息。          |
| options      | [CreateOsAccountForDomainOptions](#createosaccountfordomainoptions12) | 否   | 创建账号的可选参数，默认为空。 <br/>从API version 12开始支持该可选参数。|

**返回值：**

| 类型                                           | 说明                                    |
| ---------------------------------------------- | -------------------------------------- |
| Promise&lt;[OsAccountInfo](js-apis-osAccount.md#osaccountinfo)&gt; | Promise对象，返回新创建的系统账号的信息。 |

**错误码：**

| 错误码ID | 错误信息                     |
| -------- | ------------------- |
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.|
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid type, domainInfo or options. |
| 12300004 | Account already exists. |
| 12300005 | Multi-user not supported. |
| 12300006 | Unsupported account type. |
| 12300007 | The number of accounts has reached the upper limit. |
| 12300015 | The short name already exists. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let domainInfo: osAccount.DomainAccountInfo =
    {domain: 'testDomain', accountName: 'testAccountName'};
  let options: osAccount.CreateOsAccountForDomainOptions = {
    shortName: 'myShortName'
  }
  try {
    accountManager.createOsAccountForDomain(osAccount.OsAccountType.NORMAL, domainInfo, options).then(
      (accountInfo: osAccount.OsAccountInfo) => {
      console.log('createOsAccountForDomain, account info: ' + JSON.stringify(accountInfo));
    }).catch((err: BusinessError) => {
      console.error('createOsAccountForDomain err: ' + JSON.stringify(err));
    });
  } catch (e) {
    console.error('createOsAccountForDomain exception: ' + JSON.stringify(e));
  }
  ```

### queryOsAccount<sup>11+</sup>

queryOsAccount(): Promise&lt;OsAccountInfo&gt;

查询当前进程所属的系统账号的信息。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS 或 ohos.permission.GET_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**返回值：**

| 类型                                           | 说明                                       |
| ---------------------------------------------- | ----------------------------------------- |
| Promise&lt;[OsAccountInfo](js-apis-osAccount.md#osaccountinfo)&gt; | Promise对象，返回当前进程所属的系统账号信息。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 201 | Permission denied.|
| 202 | Not system application.|
| 12300001 | The system service works abnormally. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  try {
    accountManager.queryOsAccount().then((accountInfo: osAccount.OsAccountInfo) => {
      console.log('queryOsAccount, accountInfo: ' + JSON.stringify(accountInfo));
    }).catch((err: BusinessError) => {
      console.error('queryOsAccount err: ' + JSON.stringify(err));
    });
  } catch (e) {
    console.error('queryOsAccount exception: ' + JSON.stringify(e));
  }
  ```

### queryOsAccountById

queryOsAccountById(localId: number, callback: AsyncCallback&lt;OsAccountInfo&gt;): void

查询指定系统账号的信息。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS 或 ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS_EXTENSION

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                                                                       |
| -------- | ---------------------------------------------------- | ---- | ------------------------------------------------------------------------ |
| localId  | number                                               | 是   | 要查询的系统账号的ID。                                                      |
| callback | AsyncCallback&lt;[OsAccountInfo](js-apis-osAccount.md#osaccountinfo)&gt; | 是   | 回调函数。如果查询成功，err为null，data为查到的系统账号的信息；否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid localId.    |
| 12300003 | Account not found. |

**示例：** 查询ID为100的系统账号信息

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let localId: number = 100;
  try {
    accountManager.queryOsAccountById(localId, (err: BusinessError, accountInfo: osAccount.OsAccountInfo)=>{
      if (err) {
        console.error('queryOsAccountById exception:' + JSON.stringify(err));
      } else {
        console.log('queryOsAccountById accountInfo:' + JSON.stringify(accountInfo));
      }
    });
  } catch (e) {
    console.error('queryOsAccountById exception: ' + JSON.stringify(e));
  }
  ```

### queryOsAccountById

queryOsAccountById(localId: number): Promise&lt;OsAccountInfo&gt;

查询指定系统账号的信息。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS 或 ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS_EXTENSION

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名  | 类型   | 必填 | 说明                 |
| ------- | ------ | ---- | -------------------- |
| localId | number | 是   | 要查询的系统账号的ID。 |

**返回值：**

| 类型                                           | 说明                                 |
| ---------------------------------------------- | ------------------------------------ |
| Promise&lt;[OsAccountInfo](js-apis-osAccount.md#osaccountinfo)&gt; | Promise对象，返回查到的系统账号的信息。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid localId. |
| 12300003 | Account not found. |

**示例：** 查询ID为100的系统账号信息

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let localId: number = 100;
  try {
    accountManager.queryOsAccountById(localId).then((accountInfo: osAccount.OsAccountInfo) => {
      console.log('queryOsAccountById, accountInfo: ' + JSON.stringify(accountInfo));
    }).catch((err: BusinessError) => {
      console.error('queryOsAccountById err: ' + JSON.stringify(err));
    });
  } catch (e) {
    console.error('queryOsAccountById exception: ' + JSON.stringify(e));
  }
  ```

### getOsAccountProfilePhoto

getOsAccountProfilePhoto(localId: number, callback: AsyncCallback&lt;string&gt;): void

获取指定系统账号的头像信息。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                                                         |
| -------- | --------------------------- | ---- | -------------------------------------------------------------------------- |
| localId  | number                      | 是   | 系统账号ID。                                                                |
| callback | AsyncCallback&lt;string&gt; | 是   | 回调函数。如果获取成功，err为null，data为指定系统账号的头像信息；否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid localId.    |
| 12300003 | Account not found. |

**示例：** 获取ID为100的系统账号的头像

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let localId: number = 100;
  try {
    accountManager.getOsAccountProfilePhoto(localId, (err: BusinessError, photo: string)=>{
      if (err) {
        console.error('getOsAccountProfilePhoto exception:' + JSON.stringify(err));
      } else {
        console.log('get photo:' + photo + ' by localId: ' + localId);
      }
    });
  } catch (e) {
    console.error('getOsAccountProfilePhoto exception: ' + JSON.stringify(e));
  }
  ```

### getOsAccountProfilePhoto

getOsAccountProfilePhoto(localId: number): Promise&lt;string&gt;

获取指定系统账号的头像信息。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名  | 类型   | 必填 | 说明         |
| ------- | ------ | ---- | ------------ |
| localId | number | 是   | 系统账号ID。 |

**返回值：**

| 类型                  | 说明                                    |
| --------------------- | -------------------------------------- |
| Promise&lt;string&gt; | Promise对象，返回指定系统账号的头像信息。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid localId.    |
| 12300003 | Account not found. |

**示例：** 获取ID为100的系统账号的头像

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let localId: number = 100;
  try {
    accountManager.getOsAccountProfilePhoto(localId).then((photo: string) => {
      console.log('getOsAccountProfilePhoto: ' + photo);
    }).catch((err: BusinessError) => {
      console.error('getOsAccountProfilePhoto err: ' + JSON.stringify(err));
    });
  } catch (e) {
    console.error('getOsAccountProfilePhoto exception: ' + JSON.stringify(e));
  }
  ```

### setOsAccountProfilePhoto

setOsAccountProfilePhoto(localId: number, photo: string, callback: AsyncCallback&lt;void&gt;): void

为指定系统账号设置头像信息。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                      | 必填 | 说明         |
| -------- | ------------------------- | ---- | ------------ |
| localId  | number                    | 是   | 系统账号ID。 |
| photo    | string                    | 是   | 头像信息。   |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。如果设置成功，err为null，否则为错误对象。  |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid localId or photo.    |
| 12300003 | Account not found. |
| 12300008 | Restricted Account. |

**示例：** 给ID为100的系统账号设置头像

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let localId: number = 100;
  let photo: string = 'data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAA0AAAAPCAYAAAA/I0V3AAAAAXNSR0IArs4c6QAAAARnQU1BAA'+
  'Cxjwv8YQUAAAAJcEhZcwAADsMAAA7DAcdvqGQAAACwSURBVDhPvZLBDYMwDEV/ugsXRjAT0EHCOuFIBwkbdIRewi6unbiAyoGgSn1SFH85+Y'+
  'q/4ljARW62X+LHS8uIzjm4dXUYF+utzBikB52Jo5e5iEPKqpACk7R9NM2RvWm5tIkD2czLCUFNKLD6IjdMHFHDzws285MgGrT0xCtp3WOKHo'+
  '+7q0mP0DZW9pNmoEFUzrQjp5cCnaen2kSJXLFD8ghbXyZCMQf/8e8Ns1XVAG/XAgqKzVnJFAAAAABJRU5ErkJggg=='
  try {
    accountManager.setOsAccountProfilePhoto(localId, photo, (err: BusinessError)=>{
      if (err) {
        console.error('setOsAccountProfilePhoto exception:' + JSON.stringify(err));
      } else {
        console.log('setOsAccountProfilePhoto successful.');
      }
    });
  } catch (e) {
    console.error('setOsAccountProfilePhoto exception: ' + JSON.stringify(e));
  }
  ```

### setOsAccountProfilePhoto

setOsAccountProfilePhoto(localId: number, photo: string): Promise&lt;void&gt;

为指定系统账号设置头像信息。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名  | 类型   | 必填 | 说明         |
| ------- | ------ | ---- | ------------ |
| localId | number | 是   | 系统账号ID。 |
| photo   | string | 是   | 头像信息。   |

**返回值：**

| 类型                | 说明                                 |
| ------------------- | ------------------------------------ |
| Promise&lt;void&gt; | Promise对象，无返回结果的Promise对象。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid localId or photo.    |
| 12300003 | Account not found. |
| 12300008 | Restricted Account. |

**示例：** 给ID为100的系统账号设置头像

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let localId: number = 100;
  let photo: string = 'data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAA0AAAAPCAYAAAA/I0V3AAAAAXNSR0IArs4c6QAAAARnQU1BAA'+
  'Cxjwv8YQUAAAAJcEhZcwAADsMAAA7DAcdvqGQAAACwSURBVDhPvZLBDYMwDEV/ugsXRjAT0EHCOuFIBwkbdIRewi6unbiAyoGgSn1SFH85+Y'+
  'q/4ljARW62X+LHS8uIzjm4dXUYF+utzBikB52Jo5e5iEPKqpACk7R9NM2RvWm5tIkD2czLCUFNKLD6IjdMHFHDzws285MgGrT0xCtp3WOKHo'+
  '+7q0mP0DZW9pNmoEFUzrQjp5cCnaen2kSJXLFD8ghbXyZCMQf/8e8Ns1XVAG/XAgqKzVnJFAAAAABJRU5ErkJggg=='
  try {
    accountManager.setOsAccountProfilePhoto(localId, photo).then(() => {
      console.log('setOsAccountProfilePhoto success');
    }).catch((err: BusinessError) => {
      console.error('setOsAccountProfilePhoto err: ' + JSON.stringify(err));
    });
  } catch (e) {
    console.error('setOsAccountProfilePhoto exception: ' + JSON.stringify(e));
  }
  ```

### on

on(type: 'activate' | 'activating', name: string, callback: Callback&lt;number&gt;): void

订阅系统账号的激活完成与激活中的事件。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS_EXTENSION

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                       | 必填 | 说明                                                         |
| -------- | -------------------------- | ---- | ------------------------------------------------------------ |
| type     | 'activate' \| 'activating' | 是   | 订阅类型，activate表示订阅的是账号已激活完成的事件，activating表示订阅的是账号正在激活的事件。 |
| name     | string                     | 是   | 订阅名称，可自定义，要求非空且长度不超过1024字节。           |
| callback | Callback&lt;number&gt;     | 是   | 订阅系统账号激活完成与激活中的事件回调，表示激活完成后或正在激活中的系统账号ID。    |

**错误码：**

| 错误码ID | 错误信息       |
| -------- | ------------- |
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid type or name. |

**示例：**

  ```ts
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  function onCallback(receiveLocalId: number){
    console.log('receive localId:' + receiveLocalId);
  }
  try {
    accountManager.on('activating', 'osAccountOnOffNameA', onCallback);
  } catch (e) {
    console.error('receive localId exception: ' + JSON.stringify(e));
  }
  ```

### off

off(type: 'activate' | 'activating', name: string, callback?: Callback&lt;number&gt;): void

取消订阅系统账号的激活完成与激活中的事件。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS_EXTENSION

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                       | 必填 | 说明                                                         |
| -------- | -------------------------- | ---- | ------------------------------------------------------------ |
| type     | 'activate' \| 'activating' | 是   | 取消订阅类型，activate表示取消订阅账号已激活完成的事件，activating取消订阅账号正在激活的事件。 |
| name     | string                     | 是   | 订阅名称，可自定义，要求非空且长度不超过1024字节，需要与订阅接口传入的值保持一致。 |
| callback | Callback&lt;number&gt;     | 否   | 取消订阅系统账号激活完成与激活中的事件回调，默认为空，表示取消该类型事件的所有回调。                      |

**错误码：**

| 错误码ID | 错误信息       |
| -------- | ------------- |
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid type or name. |

**示例：**

  ```ts
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  function offCallback(){
    console.log('off enter')
  }
  try {
    accountManager.off('activating', 'osAccountOnOffNameA', offCallback);
  } catch (e) {
    console.error('off exception: ' + JSON.stringify(e));
  }
  ```

### on<sup>12+</sup>

on(type: 'switching', callback: Callback&lt;OsAccountSwitchEventData&gt;): void

订阅系统账号的前后台正在切换事件。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                       | 必填 | 说明                                                         |
| -------- | -------------------------- | ---- | ------------------------------------------------------------ |
| type     | 'switching'                 | 是   | 订阅类型，switching表示订阅的是系统账号的前后台正在切换事件。 |
| callback | Callback&lt;[OsAccountSwitchEventData](#osaccountswitcheventdata12)&gt;     | 是   | 订阅系统账号的前后台正在切换事件回调，表示切换前和切换后的系统账号ID。    |

**错误码：**

| 错误码ID | 错误信息       |
| -------- | ------------- |
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 |Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid type. |

**示例：**

  ```ts
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  function onSwitchingCallback(eventData: osAccount.OsAccountSwitchEventData){
    console.log('receive eventData:' + JSON.stringify(eventData));
  }
  try {
    accountManager.on('switching', onSwitchingCallback);
  } catch (e) {
    console.error('receive eventData exception: ' + JSON.stringify(e));
  }
  ```

### off<sup>12+</sup>

off(type: 'switching', callback?: Callback&lt;OsAccountSwitchEventData&gt;): void

取消订阅系统账号的前后台正在切换事件。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                       | 必填 | 说明                                                         |
| -------- | -------------------------- | ---- | ------------------------------------------------------------ |
| type     | 'switching'                 | 是   | 取消订阅类型，switching表示取消订阅的是系统账号的前后台正在切换事件。 |
| callback | Callback&lt;[OsAccountSwitchEventData](#osaccountswitcheventdata12)&gt;     | 否   | 取消订阅系统账号的前后台正在切换事件回调，默认为空，表示取消该类型事件的所有回调。                      |

**错误码：**

| 错误码ID | 错误信息       |
| -------- | ------------- |
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 |Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid type. |

**示例：**

  ```ts
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  try {
    accountManager.off('switching');
  } catch (e) {
    console.error('off exception: ' + JSON.stringify(e));
  }
  ```

### on<sup>12+</sup>

on(type: 'switched', callback: Callback&lt;OsAccountSwitchEventData&gt;): void

订阅系统账号的前后台切换结束事件。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                       | 必填 | 说明                                                         |
| -------- | -------------------------- | ---- | ------------------------------------------------------------ |
| type     | 'switched'                 | 是   | 订阅类型，switched表示订阅的是系统账号的前后台切换结束事件。 |
| callback | Callback&lt;[OsAccountSwitchEventData](#osaccountswitcheventdata12)&gt;     | 是   | 订阅系统账号的前后台切换结束事件回调，表示切换前和切换后的系统账号ID。    |

**错误码：**

| 错误码ID | 错误信息       |
| -------- | ------------- |
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 |Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid type. |

**示例：**

  ```ts
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  function onSwitchedCallback(eventData: osAccount.OsAccountSwitchEventData){
    console.log('receive eventData:' + JSON.stringify(eventData));
  }
  try {
    accountManager.on('switched', onSwitchedCallback);
  } catch (e) {
    console.error('receive eventData exception: ' + JSON.stringify(e));
  }
  ```

### off<sup>12+</sup>

off(type: 'switched', callback?: Callback&lt;OsAccountSwitchEventData&gt;): void

取消订阅系统账号的前后台切换结束事件。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                       | 必填 | 说明                                                         |
| -------- | -------------------------- | ---- | ------------------------------------------------------------ |
| type     | 'switched'                 | 是   | 取消订阅类型，switched表示取消订阅的是系统账号的前后台切换结束事件。 |
| callback | Callback&lt;[OsAccountSwitchEventData](#osaccountswitcheventdata12)&gt;     | 否   | 取消订阅系统账号的前后台切换结束事件回调，默认为空，表示取消该类型事件的所有回调。                      |

**错误码：**

| 错误码ID | 错误信息       |
| -------- | ------------- |
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 |Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid type. |

**示例：**

  ```ts
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  try {
    accountManager.off('switched');
  } catch (e) {
    console.error('off exception: ' + JSON.stringify(e));
  }
  ```

### getBundleIdForUid<sup>9+</sup>

getBundleIdForUid(uid: number, callback: AsyncCallback&lt;number&gt;): void

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
| 202 | Not system application.|
| 401 |Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid uid. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let testUid: number = 1000000;
  try {
    accountManager.getBundleIdForUid(testUid, (err: BusinessError, bundleId: number) => {
      if (err) {
        console.error('getBundleIdForUid errInfo:' + JSON.stringify(err));
      } else {
        console.info('getBundleIdForUid bundleId:' + JSON.stringify(bundleId));
      }
    });
  } catch (e) {
    console.error('getBundleIdForUid exception: ' + JSON.stringify(e));
  }
  ```

### getBundleIdForUid<sup>9+</sup>

getBundleIdForUid(uid: number): Promise&lt;number&gt;

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
| 202 | Not system application.|
| 401 |Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid uid. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let testUid: number = 1000000;
  try {
    accountManager.getBundleIdForUid(testUid).then((result: number) => {
      console.info('getBundleIdForUid bundleId:' + JSON.stringify(result));
    }).catch((err: BusinessError) => {
      console.error('getBundleIdForUid errInfo:' + JSON.stringify(err));
    });
  } catch (e) {
    console.error('getBundleIdForUid exception: ' + JSON.stringify(e));
  }
  ```

### getBundleIdForUidSync<sup>10+</sup>

getBundleIdForUidSync(uid: number): number

通过uid查询对应的bundleId。使用同步方式返回结果。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名  | 类型   | 必填 | 说明         |
| ------- | ------ | ---- | ------------ |
| uid     | number | 是   |  进程uid。 |

**返回值：**

| 类型   | 说明                     |
| ------ | ------------------------ |
| number | 表示与进程uid对应的bundleId。 |

**错误码：**

| 错误码ID | 错误信息       |
| -------- | ------------- |
| 202 | Not system application.|
| 401 |Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300002 | Invalid uid. |

**示例：**

  ```ts
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let testUid: number = 1000000;
  try {
    let bundleId : number = accountManager.getBundleIdForUidSync(testUid);
    console.info('getBundleIdForUidSync bundleId:' + bundleId);
  } catch (e) {
    console.error('getBundleIdForUidSync exception: ' + JSON.stringify(e));
  }
  ```

### isMainOsAccount<sup>9+</sup>

isMainOsAccount(callback: AsyncCallback&lt;boolean&gt;): void

查询当前进程是否处于主用户，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                          | 必填 | 说明                                                               |
| -------- | ---------------------------- | ---- | ----------------------------------------------------------------- |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调函数，返回true表示当前账号为主账号，返回false表示当前账号非主账号。 |

**错误码：**

| 错误码ID | 错误信息       |
| -------- | ------------- |
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 |Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  try {
    accountManager.isMainOsAccount((err: BusinessError,result: boolean)=>{
      if (err) {
        console.error('isMainOsAccount errInfo:' + JSON.stringify(err));
      } else {
        console.info('isMainOsAccount result:' + JSON.stringify(result));
      }
    });
  } catch (e) {
    console.error('isMainOsAccount exception: ' + JSON.stringify(e));
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
| Promise&lt;boolean&gt; | Promise对象，返回true表示当前账号为主账号，返回false表示当前账号非主账号。 |

**错误码：**

| 错误码ID | 错误信息       |
| -------- | ------------- |
| 201 | Permission denied.|
| 202 | Not system application.|
| 12300001 | The system service works abnormally. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  try {
    accountManager.isMainOsAccount().then((result: boolean) => {
      console.info('isMainOsAccount result:' + JSON.stringify(result));
    }).catch((err: BusinessError) => {
      console.error('isMainOsAccount errInfo:' + JSON.stringify(err));
    });
  } catch (e) {
    console.error('isMainOsAccount exception: ' + JSON.stringify(e));
  }
  ```

### getOsAccountConstraintSourceTypes<sup>9+</sup>

getOsAccountConstraintSourceTypes(localId: number, constraint: string, callback: AsyncCallback&lt;Array&lt;ConstraintSourceTypeInfo&gt;&gt;): void

查询指定系统账号的指定约束来源信息，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                       | 必填 | 说明                                                         |
| -------- | -------------------------- | ---- | ------------------------------------------------------------ |
| localId     | number | 是   |  要查询的系统账号ID。 |
| constraint     | string | 是   |  要查询的[约束](js-apis-osAccount.md#系统账号约束列表)名称。 |
| callback | AsyncCallback&lt;Array&lt;[ConstraintSourceTypeInfo](#constraintsourcetypeinfo9)&gt;&gt;     | 是   | 回调函数。如果成功，err为null，data为指定系统账号的指定[约束](js-apis-osAccount.md#系统账号约束列表)来源信息；否则为错误对象。                      |

**错误码：**

| 错误码ID | 错误信息       |
| -------- | ------------- |
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 |Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid name or constraint. |
| 12300003 | Account not found. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  try {
    accountManager.getOsAccountConstraintSourceTypes(100, 'constraint.wifi',
      (err: BusinessError,sourceTypeInfos: osAccount.ConstraintSourceTypeInfo[])=>{
      if (err) {
        console.error('getOsAccountConstraintSourceTypes errInfo:' + JSON.stringify(err));
      } else {
        console.info('getOsAccountConstraintSourceTypes sourceTypeInfos:' + JSON.stringify(sourceTypeInfos));
      }
    });
  } catch (e) {
    console.error('getOsAccountConstraintSourceTypes exception: ' + JSON.stringify(e));
  }
  ```

### getOsAccountConstraintSourceTypes<sup>9+</sup>

getOsAccountConstraintSourceTypes(localId: number, constraint: string): Promise&lt;Array&lt;ConstraintSourceTypeInfo&gt;&gt;;

查询指定系统账号的指定约束来源信息，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名  | 类型   | 必填 | 说明         |
| ------- | ------ | ---- | ------------ |
| localId     | number | 是   |  要查询的系统账号ID。 |
| constraint     | string | 是   |  要查询的[约束](js-apis-osAccount.md#系统账号约束列表)名称。 |

**返回值：**

| 类型                  | 说明                                                         |
| --------------------- | ------------------------------------------------------------ |
| Promise&lt;Array&lt;[ConstraintSourceTypeInfo](#constraintsourcetypeinfo9)&gt;&gt; | Promise对象，返回指定系统账号的指定[约束](js-apis-osAccount.md#系统账号约束列表)来源信息。 |

**错误码：**

| 错误码ID | 错误信息       |
| -------- | ------------- |
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 |Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid name or constraint. |
| 12300003 | Account not found. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  try {
    accountManager.getOsAccountConstraintSourceTypes(100, 'constraint.wifi').then(
      (result: osAccount.ConstraintSourceTypeInfo[]) => {
      console.info('getOsAccountConstraintSourceTypes sourceTypeInfos:' + JSON.stringify(result));
    }).catch((err: BusinessError) => {
      console.error('getOsAccountConstraintSourceTypes errInfo:' + JSON.stringify(err));
    });
  } catch (e) {
    console.error('getOsAccountConstraintSourceTypes exception: ' + JSON.stringify(e));
  }
  ```

### getOsAccountType<sup>12+</sup>

getOsAccountType(localId: number): Promise&lt;OsAccountType&gt;;

查询指定系统账号的类型，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS 或 ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名  | 类型   | 必填 | 说明         |
| ------- | ------ | ---- | ------------ |
| localId     | number | 是   |  要查询的系统账号ID。 |

**返回值：**

| 类型                  | 说明                                                         |
| --------------------- | ------------------------------------------------------------ |
| Promise&lt;[OsAccountType](js-apis-osAccount.md#osaccounttype)&gt; | Promise对象，返回指定系统账号的类型。 |

**错误码：**

| 错误码ID | 错误信息       |
| -------- | ------------- |
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300003 | Account not found. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  try {
    let localId: number = 100;
    accountManager.getOsAccountType(localId).then((type: osAccount.OsAccountType) => {
      console.info('getOsAccountType Type:' + type);
    }).catch((err: BusinessError) => {
      console.error('getOsAccountType errInfo:' + JSON.stringify(err));
    });
  } catch (e) {
    console.error('getOsAccountType exception: ' + JSON.stringify(e));
  }
  ```

## UserAuth<sup>8+</sup>

用户认证类。

**系统接口：** 此接口为系统接口。

### constructor<sup>8+</sup>

constructor()

创建用户认证的实例。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Account.OsAccount

**错误码：**

| 错误码ID | 错误信息       |
| -------- | ------------- |
| 202 | Not system application.|

**示例：**
  ```ts
  let userAuth = new osAccount.UserAuth();
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

**错误码：**

| 错误码ID | 错误信息       |
| -------- | ------------- |
| 202 | Not system application.|

**示例：**
  ```ts
  let userAuth = new osAccount.UserAuth();
  let version: number = userAuth.getVersion();
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
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 |Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid authType or authTrustLevel. |

**示例：**
  ```ts
  let userAuth = new osAccount.UserAuth();
  let authType: osAccount.AuthType = osAccount.AuthType.PIN;
  let authTrustLevel: osAccount.AuthTrustLevel = osAccount.AuthTrustLevel.ATL1;
  try {
    let status: number = userAuth.getAvailableStatus(authType, authTrustLevel);
    console.log('getAvailableStatus status = ' + status);
  } catch (e) {
    console.error('getAvailableStatus exception = ' + JSON.stringify(e));
  }
  ```

### getProperty<sup>8+</sup>

getProperty(request: GetPropertyRequest, callback: AsyncCallback&lt;ExecutorProperty&gt;): void

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
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 |Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid request. |
| 12300003 | Account not found. |

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let userAuth = new osAccount.UserAuth();
  let keys: Array<osAccount.GetPropertyType>  = [
    osAccount.GetPropertyType.AUTH_SUB_TYPE,
    osAccount.GetPropertyType.REMAIN_TIMES,
    osAccount.GetPropertyType.FREEZING_TIME
  ];
  let request: osAccount.GetPropertyRequest = {
    authType: osAccount.AuthType.PIN,
    keys: keys
  };
  try {
    userAuth.getProperty(request, (err: BusinessError, result: osAccount.ExecutorProperty) => {
      if (err) {
        console.error('getProperty exception = ' + JSON.stringify(err));
      } else {
        console.log('getProperty result = ' + JSON.stringify(result));
      }
    });
  } catch (e) {
    console.error('getProperty exception = ' + JSON.stringify(e));
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
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 |Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid request. |
| 12300003 | Account not found. |

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let userAuth = new osAccount.UserAuth();
  let keys: Array<osAccount.GetPropertyType> = [
    osAccount.GetPropertyType.AUTH_SUB_TYPE,
    osAccount.GetPropertyType.REMAIN_TIMES,
    osAccount.GetPropertyType.FREEZING_TIME
  ];
  let request: osAccount.GetPropertyRequest = {
    authType: osAccount.AuthType.PIN,
    keys: keys
  };
  try {
    userAuth.getProperty(request).then((result: osAccount.ExecutorProperty) => {
      console.log('getProperty result = ' + JSON.stringify(result));
    }).catch((err: BusinessError) => {
      console.error('getProperty error = ' + JSON.stringify(err));
    });
  } catch (e) {
    console.error('getProperty exception = ' + JSON.stringify(e));
  }
  ```

### getPropertyByCredentialId<sup>14+</sup>

getPropertyByCredentialId(credentialId: Uint8Array, keys: Array&lt;GetPropertyType&gt;): Promise&lt;ExecutorProperty&gt;;

基于凭据id获取关联执行器的指定属性信息。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**需要权限：** ohos.permission.ACCESS_USER_AUTH_INTERNAL

**参数：**

| 参数名    | 类型                                                   | 必填 | 说明                                |
| -------- | ------------------------------------------------------ | ---- | ---------------------------------- |
| credentialId  | Uint8Array | 是   | 指示凭据索引。 |
| keys     | Array&lt;[GetPropertyType](#getpropertytype8)&gt; | 是    | 指示要查询的属性类型数组。 |

**返回值：**

| 类型                                                              | 说明                                                 |
| :---------------------------------------------------------------- | :-------------------------------------------------- |
| Promise&lt;[ExecutorProperty](#executorproperty8)&gt; | Promise对象，返回执行器的属性信息。 |

**错误码：**

| 错误码ID | 错误信息                     |
| -------- | --------------------------- |
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 |Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid keys. |
| 12300102 | The credential does not exist. |

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let userIDM = new osAccount.UserIdentityManager();
  let credInfo: osAccount.EnrolledCredInfo[] = [];
  async function getProperty() {
    try {
      credInfo = await userIDM.getAuthInfo(osAccount.AuthType.PRIVATE_PIN);
    } catch (e) {
      console.error('getAuthInfo exception = ' + JSON.stringify(e));
      return;
    }
    if (credInfo.length == 0) {
      console.log('no credential infos');
      return;
    }
    let testCredentialId: Uint8Array = credInfo[0].credentialId;
    let keys: Array<osAccount.GetPropertyType> = [
      osAccount.GetPropertyType.AUTH_SUB_TYPE,
      osAccount.GetPropertyType.REMAIN_TIMES,
      osAccount.GetPropertyType.FREEZING_TIME
    ];
    try {
      let userAuth = new osAccount.UserAuth();
      userAuth.getPropertyByCredentialId(testCredentialId, keys).then((result: osAccount.ExecutorProperty) => {
        console.log('getPropertyByCredentialId result = ' + JSON.stringify(result));
      }).catch((err: BusinessError) => {
        console.error('getPropertyByCredentialId error = ' + JSON.stringify(err));
      });
    } catch (e) {
      console.error('getPropertyByCredentialId exception = ' + JSON.stringify(e));
    }
  }
  ```

### setProperty<sup>8+</sup>

setProperty(request: SetPropertyRequest, callback: AsyncCallback&lt;void&gt;): void

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
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 |Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid request. |

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let userAuth = new osAccount.UserAuth();
  let request: osAccount.SetPropertyRequest = {
    authType: osAccount.AuthType.PIN,
    key: osAccount.SetPropertyType.INIT_ALGORITHM,
    setInfo: new Uint8Array([0])
  };
  try {
    userAuth.setProperty(request, (err: BusinessError) => {
      if (err) {
        console.error('setProperty failed, error = ' + JSON.stringify(err));
      } else {
        console.log('setProperty successfully');
      }
    });
  } catch (e) {
    console.error('setProperty exception = ' + JSON.stringify(e));
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
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 |Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid request. |

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let userAuth = new osAccount.UserAuth();
  let request: osAccount.SetPropertyRequest = {
    authType: osAccount.AuthType.PIN,
    key: osAccount.SetPropertyType.INIT_ALGORITHM,
    setInfo: new Uint8Array([0])
  };
  try {
    userAuth.setProperty(request).then(() => {
      console.log('setProperty successfully');
    }).catch((err: BusinessError) => {
      console.error('setProperty failed, error = ' + JSON.stringify(err));
    });
  } catch (e) {
    console.error('setProperty exception = ' + JSON.stringify(e));
  }
  ```

### prepareRemoteAuth<sup>12+</sup>

prepareRemoteAuth(remoteNetworkId: string): Promise&lt;void&gt;;

准备远端认证。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**需要权限：** ohos.permission.ACCESS_USER_AUTH_INTERNAL

**参数：**

| 参数名            | 类型   | 必填 | 说明             |
| --------         | ------ | ---- | --------------- |
| remoteNetworkId  | string | 是   | 远端网络Id。  |

**返回值：**

| 类型                  | 说明                                                           |
| :-------------------- | :------------------------------------------------------------ |
| Promise&lt;void&gt; | Promise对象，无返回结果的Promise对象。 |

**错误码：**

| 错误码ID | 错误信息                     |
| -------- | --------------------------- |
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 |Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | System service exception. |
| 12300002 | Invalid remoteNetworkId. |

**示例：**
  ```ts
  import { distributedDeviceManager } from '@kit.DistributedServiceKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let userAuth = new osAccount.UserAuth();
  let distributedDeviceMgr = distributedDeviceManager.createDeviceManager("com.example.bundleName");
  distributedDeviceMgr.getAvailableDeviceList().then((data: Array<distributedDeviceManager.DeviceBasicInfo>) => {
      try {
        if (data.length > 0 && data[0].networkId != null) {
          userAuth.prepareRemoteAuth(data[0].networkId).then(() => {
            console.log('prepareRemoteAuth successfully');
          }).catch((err: BusinessError) => {
            console.error('prepareRemoteAuth failed, error = ' + JSON.stringify(err));
          });
        }
      } catch (e) {
        console.error('prepareRemoteAuth exception = ' + JSON.stringify(e));
      }
    }
  )
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
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 |Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid challenge, authType or authTrustLevel. |
| 12300013 | Network exception. |
| 12300101 | The credential is incorrect. |
| 12300102 | The credential does not exist. |
| 12300105 | The trust level is not supported. |
| 12300106 | The authentication type is not supported. |
| 12300109 | The authentication, enrollment, or update operation is canceled. |
| 12300110 | The authentication is locked. |
| 12300111 | The authentication time out. |
| 12300112 | The authentication service is busy. |
| 12300113 | The authentication service does not exist. |
| 12300114 | The authentication service works abnormally. |
| 12300117 | PIN is expired. |
| 12300211 | Server unreachable. |

**示例：**
  ```ts
  let userAuth = new osAccount.UserAuth();
  let challenge: Uint8Array = new Uint8Array([0]);
  let authType: osAccount.AuthType = osAccount.AuthType.PIN;
  let authTrustLevel: osAccount.AuthTrustLevel = osAccount.AuthTrustLevel.ATL1;
  try {
    userAuth.auth(challenge, authType, authTrustLevel, {
      onResult: (result: number, extraInfo: osAccount.AuthResult) => {
          console.log('auth result = ' + result);
          console.log('auth extraInfo = ' + JSON.stringify(extraInfo));
      }
    });
  } catch (e) {
    console.error('auth exception = ' + JSON.stringify(e));
  }
  ```

### auth<sup>12+</sup>

auth(challenge: Uint8Array, authType: AuthType, authTrustLevel: AuthTrustLevel, options: AuthOptions, callback: IUserAuthCallback): Uint8Array

基于指定的挑战值、认证类型（如口令、人脸、指纹等）、认证可信等级以及可选参数（如账号标识、认证意图等）进行身份认证。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**需要权限：** ohos.permission.ACCESS_USER_AUTH_INTERNAL

**参数：**

| 参数名           | 类型                                     | 必填 | 说明                                |
| --------------- | ---------------------------------------- | --- | ------------------------------------ |
| challenge       | Uint8Array                               | 是  | 指示挑战值，挑战值为一个随机数，用于防止重放攻击，提升安全性。|
| authType        | [AuthType](#authtype8)                   | 是  | 指示认证类型。                        |
| authTrustLevel  | [AuthTrustLevel](#authtrustlevel8)       | 是  | 指示认证结果的信任级别。               |
| options         | [AuthOptions](#authoptions12) | 是 | 指示认证用户的可选参数集合。 |
| callback        | [IUserAuthCallback](#iuserauthcallback8) | 是  | 回调对象，返回认证结果。  |

**返回值：**

| 类型        | 说明               |
| ---------- | ------------------ |
| Uint8Array | 返回取消的上下文ID。 |

**错误码：**

| 错误码ID | 错误信息          |
| -------- | --------------------- |
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 |Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid challenge, authType, authTrustLevel or options. |
| 12300003 | Account not found. |
| 12300013 | Network exception. |
| 12300101 | The credential is incorrect. |
| 12300102 | The credential does not exist. |
| 12300105 | The trust level is not supported. |
| 12300106 | The authentication type is not supported. |
| 12300109 | The authentication, enrollment, or update operation is canceled. |
| 12300110 | The authentication is locked. |
| 12300111 | The authentication time out. |
| 12300112 | The authentication service is busy. |
| 12300113 | The authentication service does not exist. |
| 12300114 | The authentication service works abnormally. |
| 12300117 | PIN is expired. |
| 12300211 | Server unreachable. |

**示例：**
  ```ts
  let userAuth = new osAccount.UserAuth();
  let challenge: Uint8Array = new Uint8Array([0]);
  let authType: osAccount.AuthType = osAccount.AuthType.PIN;
  let authTrustLevel: osAccount.AuthTrustLevel = osAccount.AuthTrustLevel.ATL1;
  let options: osAccount.AuthOptions = {
    accountId: 100
  };
  try {
    userAuth.auth(challenge, authType, authTrustLevel, options, {
      onResult: (result: number, extraInfo: osAccount.AuthResult) => {
          console.log('auth result = ' + result);
          console.log('auth extraInfo = ' + JSON.stringify(extraInfo));
      }
    });
  } catch (e) {
    console.error('auth exception = ' + JSON.stringify(e));
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
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 |Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid challenge, authType or authTrustLevel. |
| 12300003 | Account not found. |
| 12300013 | Network exception. |
| 12300101 | The credential is incorrect. |
| 12300102 | The credential does not exist. |
| 12300105 | The trust level is not supported. |
| 12300106 | The authentication type is not supported. |
| 12300109 | The authentication, enrollment, or update operation is canceled. |
| 12300110 | The authentication is locked. |
| 12300111 | The authentication time out. |
| 12300112 | The authentication service is busy. |
| 12300113 | The authentication service does not exist. |
| 12300114 | The authentication service works abnormally. |
| 12300117 | PIN is expired. |
| 12300211 | Server unreachable. |

**示例：**
  ```ts
  let userAuth = new osAccount.UserAuth();
  let userID: number = 100;
  let challenge: Uint8Array = new Uint8Array([0]);
  let authType: osAccount.AuthType = osAccount.AuthType.PIN;
  let authTrustLevel: osAccount.AuthTrustLevel = osAccount.AuthTrustLevel.ATL1;
  try {
    userAuth.authUser(userID, challenge, authType, authTrustLevel, {
      onResult: (result,extraInfo) => {
        console.log('authUser result = ' + result);
        console.log('authUser extraInfo = ' + JSON.stringify(extraInfo));
      }
    });
  } catch (e) {
    console.error('authUser exception = ' + JSON.stringify(e));
  }
  ```

### cancelAuth<sup>8+</sup>

cancelAuth(contextID: Uint8Array): void

取消指定的认证操作。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**需要权限：** ohos.permission.ACCESS_USER_AUTH_INTERNAL

**参数：**

| 参数名    | 类型       | 必填  | 说明                                        |
| ----------| ---------- | ---- | ------------------------------------------ |
| contextID | Uint8Array | 是   | 指示身份验证上下文ID，此ID动态生成没有具体值。 |

**错误码：**

| 错误码ID | 错误信息            |
| -------- | ------------------ |
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 |Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid contextId. |

**示例：**
  ```ts
  let userAuth = new osAccount.UserAuth();
  let pinAuth: osAccount.PINAuth = new osAccount.PINAuth();
  let challenge = new Uint8Array([0]);
  let contextId: Uint8Array = userAuth.auth(challenge, osAccount.AuthType.PIN, osAccount.AuthTrustLevel.ATL1, {
    onResult: (result: number, extraInfo: osAccount.AuthResult) => {
      console.log('auth result = ' + result);
      console.log('auth extraInfo = ' + JSON.stringify(extraInfo));
    }
  });
  try {
    userAuth.cancelAuth(contextId);
  } catch (e) {
    console.error('cancelAuth exception = ' + JSON.stringify(e));
  }
  ```

## PINAuth<sup>8+</sup>

PIN码认证基类。

**系统接口：** 此接口为系统接口。

### constructor<sup>8+</sup>

constructor()

创建PIN码认证的实例。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Account.OsAccount

**错误码：**

| 错误码ID | 错误信息       |
| -------- | ------------- |
| 202 | Not system application.|

**示例：**
  ```ts
  let pinAuth: osAccount.PINAuth = new osAccount.PINAuth();
  ```

### registerInputer<sup>8+</sup>

registerInputer(inputer: IInputer): void

注册PIN码输入器。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**需要权限：** ohos.permission.ACCESS_PIN_AUTH

**参数：**

| 参数名    | 类型                     | 必填 | 说明                      |
| ----------| ----------------------- | --- | -------------------------- |
| inputer   | [IInputer](#iinputer8)  | 是  | PIN码输入器，用于获取PIN码。 |

**错误码：**

| 错误码ID | 错误信息                     |
| -------- | --------------------------- |
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 |Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid inputer. |
| 12300103 | The credential inputer already exists. |

**示例：**
  ```ts
  let pinAuth: osAccount.PINAuth = new osAccount.PINAuth();
  let password = new Uint8Array([0, 0, 0, 0, 0]);
  try {
    pinAuth.registerInputer({
        onGetData: (authSubType: osAccount.AuthSubType, callback: osAccount.IInputData) => {
          callback.onSetData(authSubType, password);
        }
    });
    console.log('registerInputer success.');
  } catch (e) {
    console.error('registerInputer exception = ' + JSON.stringify(e));
  }
  ```

### unregisterInputer<sup>8+</sup>

unregisterInputer(): void

解注册PIN码输入器。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**需要权限：** ohos.permission.ACCESS_PIN_AUTH

**错误码：**

| 错误码ID | 错误信息                     |
| -------- | --------------------------- |
| 201 | Permission denied.|
| 202 | Not system application.|

**示例：**
  ```ts
  let pinAuth: osAccount.PINAuth = new osAccount.PINAuth();
  pinAuth.unregisterInputer();
  ```

## InputerManager <sup>9+</sup>

凭据输入管理器。

### registerInputer<sup>9+</sup>

static registerInputer(authType: AuthType, inputer: IInputer): void

注册凭据输入器。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**需要权限：** ohos.permission.ACCESS_USER_AUTH_INTERNAL 或 ohos.permission.MANAGE_USER_IDM

**参数：**

| 参数名    | 类型                     | 必填 | 说明                      |
| ----------| ----------------------- | --- | -------------------------- |
| authType   | [AuthType](#authtype8)  | 是  | 认证类型。 |
| inputer   | [IInputer](#iinputer8)  | 是  | 凭据输入器，用于获取凭据。 |

**错误码：**

| 错误码ID | 错误信息                     |
| -------- | --------------------------- |
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 |Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid authType or inputer. |
| 12300103 | The credential inputer already exists. |
| 12300106 | The authentication type is not supported. |

**示例：**
  ```ts
  let authType: osAccount.AuthType = osAccount.AuthType.DOMAIN;
  let password: Uint8Array = new Uint8Array([0, 0, 0, 0, 0]);
  try {
    osAccount.InputerManager.registerInputer(authType, {
        onGetData: (authSubType: osAccount.AuthSubType, callback: osAccount.IInputData) => {
          callback.onSetData(authSubType, password);
        }
    });
    console.log('registerInputer success.');
  } catch (e) {
    console.error('registerInputer exception = ' + JSON.stringify(e));
  }
  ```

### unregisterInputer<sup>9+</sup>

static unregisterInputer(authType: AuthType): void

解注册凭据输入器。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**需要权限：** ohos.permission.ACCESS_USER_AUTH_INTERNAL 或 ohos.permission.MANAGE_USER_IDM

**参数：**

| 参数名    | 类型                     | 必填 | 说明                      |
| ----------| ----------------------- | --- | -------------------------- |
| authType   | [AuthType](#authtype8)  | 是  | 认证类型。 |

**错误码：**

| 错误码ID | 错误信息                     |
| -------- | --------------------------- |
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 |Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300002  | Invalid authType. |

**示例：**
  ```ts
  let authType: osAccount.AuthType = osAccount.AuthType.DOMAIN;
  try {
    osAccount.InputerManager.unregisterInputer(authType);
    console.log('unregisterInputer success.');
  } catch(err) {
    console.error('unregisterInputer err:' + JSON.stringify(err));
  }
  ```

## DomainPlugin<sup>9+</sup>

域插件，提供域账号认证功能。

**系统接口：** 此接口为系统接口。

### auth<sup>9+</sup>

auth(domainAccountInfo: DomainAccountInfo, credential: Uint8Array, callback: IUserAuthCallback): void

认证指定的域账号。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名      | 类型                                    | 必填 | 说明             |
| ---------- | --------------------------------------- | ---- | --------------- |
| domainAccountInfo   | [DomainAccountInfo](#domainaccountinfo8)  | 是   | 指示域账号信息。|
| credential   | Uint8Array  | 是   | 指示域账号的凭据。|
| callback   | [IUserAuthCallback](#iuserauthcallback8)  | 是   | 指示认证结果回调。|

**示例：**
  ```ts
  import { AsyncCallback } from '@kit.BasicServicesKit';
  let plugin: osAccount.DomainPlugin = {
    auth: (domainAccountInfo: osAccount.DomainAccountInfo, credential: Uint8Array,
          callback: osAccount.IUserAuthCallback) => {
      // mock authentication
      // notify authentication result
      let result: osAccount.AuthResult = {
        token: new Uint8Array([0]),
        remainTimes: 5,
        freezingTime: 0
      };
      callback.onResult(0, result);
    },
    authWithPopup: (domainAccountInfo: osAccount.DomainAccountInfo,
                    callback: osAccount.IUserAuthCallback) => {},
    authWithToken: (domainAccountInfo: osAccount.DomainAccountInfo, token: Uint8Array,
                    callback: osAccount.IUserAuthCallback) => {},
    getAccountInfo: (options: osAccount.GetDomainAccountInfoPluginOptions,
                    callback: AsyncCallback<osAccount.DomainAccountInfo>) => {},
    getAuthStatusInfo: (domainAccountInfo: osAccount.DomainAccountInfo,
                      callback: AsyncCallback<osAccount.AuthStatusInfo>) => {},
    bindAccount: (domainAccountInfo: osAccount.DomainAccountInfo, localId: number,
                  callback: AsyncCallback<void>) => {},
    unbindAccount: (domainAccountInfo: osAccount.DomainAccountInfo, callback: AsyncCallback<void>) => {},
    isAccountTokenValid: (domainAccountInfo: osAccount.DomainAccountInfo, token: Uint8Array,
                          callback: AsyncCallback<boolean>) => {},
    getAccessToken: (options: osAccount.GetDomainAccessTokenOptions, callback: AsyncCallback<Uint8Array>) => {}
  }
  osAccount.DomainAccountManager.registerPlugin(plugin);
  let userAuth = new osAccount.UserAuth();
  let challenge: Uint8Array = new Uint8Array([0]);
  let authType: osAccount.AuthType = osAccount.AuthType.DOMAIN;
  let authTrustLevel: osAccount.AuthTrustLevel = osAccount.AuthTrustLevel.ATL1;
  try {
    userAuth.auth(challenge, authType, authTrustLevel, {
      onResult: (resultCode: number, authResult: osAccount.AuthResult) => {
          console.log('auth resultCode = ' + resultCode);
          console.log('auth authResult = ' + JSON.stringify(authResult));
      }
    });
  } catch (err) {
    console.error('auth exception = ' + JSON.stringify(err));
  }
  ```

### authWithPopup<sup>10+</sup>

authWithPopup(domainAccountInfo: DomainAccountInfo, callback: IUserAuthCallback): void

弹窗认证指定的域账号。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名      | 类型                                    | 必填 | 说明             |
| ---------- | --------------------------------------- | ---- | --------------- |
| domainAccountInfo   | [DomainAccountInfo](#domainaccountinfo8)  | 是   | 指示域账号信息。|
| callback   | [IUserAuthCallback](#iuserauthcallback8)  | 是   | 指示认证结果回调。|

**示例：**
  ```ts
  import { AsyncCallback } from '@kit.BasicServicesKit';
  let plugin: osAccount.DomainPlugin = {
    auth: (domainAccountInfo: osAccount.DomainAccountInfo, credential: Uint8Array,
          callback: osAccount.IUserAuthCallback) => {},
    authWithPopup: (domainAccountInfo: osAccount.DomainAccountInfo,
                    callback: osAccount.IUserAuthCallback) => {
      // mock authentication
      // notify authentication result
      let result: osAccount.AuthResult = {
        token: new Uint8Array([0]),
        remainTimes: 5,
        freezingTime: 0
      };
      callback.onResult(0, result);
    },
    authWithToken: (domainAccountInfo: osAccount.DomainAccountInfo, token: Uint8Array,
                    callback: osAccount.IUserAuthCallback) => {},
    getAccountInfo: (options: osAccount.GetDomainAccountInfoPluginOptions,
                    callback: AsyncCallback<osAccount.DomainAccountInfo>) => {},
    getAuthStatusInfo: (domainAccountInfo: osAccount.DomainAccountInfo,
                        callback: AsyncCallback<osAccount.AuthStatusInfo>) => {},
    bindAccount: (domainAccountInfo: osAccount.DomainAccountInfo, localId: number,
                  callback: AsyncCallback<void>) => {},
    unbindAccount: (domainAccountInfo: osAccount.DomainAccountInfo, callback: AsyncCallback<void>) => {},
    isAccountTokenValid: (domainAccountInfo: osAccount.DomainAccountInfo, token: Uint8Array,
                          callback: AsyncCallback<boolean>) => {},
    getAccessToken: (options: osAccount.GetDomainAccessTokenOptions, callback: AsyncCallback<Uint8Array>) => {}
  }
  osAccount.DomainAccountManager.registerPlugin(plugin)
  ```

### authWithToken<sup>10+</sup>

authWithToken(domainAccountInfo: DomainAccountInfo, token: Uint8Array, callback: IUserAuthCallback): void

使用授权令牌认证指定的域账号。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名      | 类型                                    | 必填 | 说明             |
| ---------- | --------------------------------------- | ---- | --------------- |
| domainAccountInfo   | [DomainAccountInfo](#domainaccountinfo8)  | 是   | 指示域账号信息。|
| token   | Uint8Array  | 是   | 指示PIN码或生物识别认证成功时生成的授权令牌。|
| callback   | [IUserAuthCallback](#iuserauthcallback8)  | 是   | 指示认证结果回调。|

**示例：**
  ```ts
  import { AsyncCallback } from '@kit.BasicServicesKit';
  let plugin: osAccount.DomainPlugin = {
    auth: (domainAccountInfo: osAccount.DomainAccountInfo, credential: Uint8Array,
          callback: osAccount.IUserAuthCallback) => {},
    authWithPopup: (domainAccountInfo: osAccount.DomainAccountInfo,
                    callback: osAccount.IUserAuthCallback) => {},
    authWithToken: (domainAccountInfo: osAccount.DomainAccountInfo, token: Uint8Array,
                    callback: osAccount.IUserAuthCallback) => {
      // mock authentication
      // notify authentication result
      let result: osAccount.AuthResult = {
        token: new Uint8Array([0]),
        remainTimes: 5,
        freezingTime: 0
      };
      callback.onResult(0, result);
    },
    getAccountInfo: (options: osAccount.GetDomainAccountInfoPluginOptions,
                    callback: AsyncCallback<osAccount.DomainAccountInfo>) => {},
    getAuthStatusInfo: (domainAccountInfo: osAccount.DomainAccountInfo,
                        callback: AsyncCallback<osAccount.AuthStatusInfo>) => {},
    bindAccount: (domainAccountInfo: osAccount.DomainAccountInfo, localId: number,
                  callback: AsyncCallback<void>) => {},
    unbindAccount: (domainAccountInfo: osAccount.DomainAccountInfo, callback: AsyncCallback<void>) => {},
    isAccountTokenValid: (domainAccountInfo: osAccount.DomainAccountInfo, token: Uint8Array,
                          callback: AsyncCallback<boolean>) => {},
    getAccessToken: (options: osAccount.GetDomainAccessTokenOptions, callback: AsyncCallback<Uint8Array>) => {}
  }
  osAccount.DomainAccountManager.registerPlugin(plugin)
  ```

### getAccountInfo<sup>10+</sup>

getAccountInfo(options: GetDomainAccountInfoPluginOptions, callback: AsyncCallback&lt;DomainAccountInfo&gt;): void

查询指定域账号的信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名      | 类型                                    | 必填 | 说明             |
| ---------- | --------------------------------------- | ---- | --------------- |
| options   | [GetDomainAccountInfoPluginOptions](#getdomainaccountinfopluginoptions10)  | 是   | 指示域账号信息。|
| callback   | AsyncCallback&lt;[DomainAccountInfo](#domainaccountinfo8)&gt; | 是   | 指示查询结果回调。|

**示例：**
  ```ts
  import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
  let plugin: osAccount.DomainPlugin = {
    auth: (domainAccountInfo: osAccount.DomainAccountInfo, credential: Uint8Array,
          callback: osAccount.IUserAuthCallback) => {},
    authWithPopup: (domainAccountInfo: osAccount.DomainAccountInfo,
                    callback: osAccount.IUserAuthCallback) => {},
    authWithToken: (domainAccountInfo: osAccount.DomainAccountInfo, token: Uint8Array,
                    callback: osAccount.IUserAuthCallback) => {},
    getAccountInfo: (options: osAccount.GetDomainAccountInfoPluginOptions,
                    callback: AsyncCallback<osAccount.DomainAccountInfo>) => {
      // mock getting account information
      // notify result
      let code: BusinessError = {
        code: 0,
        name: "",
        message: ""
      };
      let accountInfo: osAccount.DomainAccountInfo = {
        domain: options.domain ? options.domain : "",
        accountName: options.accountName,
        accountId: 'xxxx'
      };
      callback(code, accountInfo);
    },
    getAuthStatusInfo: (domainAccountInfo: osAccount.DomainAccountInfo,
                        callback: AsyncCallback<osAccount.AuthStatusInfo>) => {},
    bindAccount: (domainAccountInfo: osAccount.DomainAccountInfo, localId: number,
                  callback: AsyncCallback<void>) => {},
    unbindAccount: (domainAccountInfo: osAccount.DomainAccountInfo, callback: AsyncCallback<void>) => {},
    isAccountTokenValid: (domainAccountInfo: osAccount.DomainAccountInfo, token: Uint8Array,
                          callback: AsyncCallback<boolean>) => {},
    getAccessToken: (options: osAccount.GetDomainAccessTokenOptions, callback: AsyncCallback<Uint8Array>) => {}
  }
  osAccount.DomainAccountManager.registerPlugin(plugin)
  ```

### getAuthStatusInfo<sup>10+</sup>

getAuthStatusInfo(domainAccountInfo: DomainAccountInfo, callback: AsyncCallback&lt;AuthStatusInfo&gt;): void

查询指定域账号的认证状态信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名      | 类型                                    | 必填 | 说明             |
| ---------- | --------------------------------------- | ---- | --------------- |
| domainAccountInfo   | [DomainAccountInfo](#domainaccountinfo8)  | 是   | 指示域账号信息。|
| callback   | AsyncCallback&lt;[AuthStatusInfo](#authstatusinfo10)&gt; | 是   | 指示查询结果回调。|

**示例：**
  ```ts
  import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
  let plugin: osAccount.DomainPlugin = {
    auth: (domainAccountInfo: osAccount.DomainAccountInfo, credential: Uint8Array,
          callback: osAccount.IUserAuthCallback) => {},
    authWithPopup: (domainAccountInfo: osAccount.DomainAccountInfo,
                    callback: osAccount.IUserAuthCallback) => {},
    authWithToken: (domainAccountInfo: osAccount.DomainAccountInfo, token: Uint8Array,
                    callback: osAccount.IUserAuthCallback) => {},
    getAccountInfo: (options: osAccount.GetDomainAccountInfoPluginOptions,
                    callback: AsyncCallback<osAccount.DomainAccountInfo>) => {},
    getAuthStatusInfo: (domainAccountInfo: osAccount.DomainAccountInfo,
                        callback: AsyncCallback<osAccount.AuthStatusInfo>) => {
      let code: BusinessError = {
        code: 0,
        name: "",
        message: ""
      };
      let statusInfo: osAccount.AuthStatusInfo = {
        remainTimes: 5,
        freezingTime: 0
      };
      callback(code, statusInfo);
    },
    bindAccount: (domainAccountInfo: osAccount.DomainAccountInfo, localId: number,
                  callback: AsyncCallback<void>) => {},
    unbindAccount: (domainAccountInfo: osAccount.DomainAccountInfo, callback: AsyncCallback<void>) => {},
    isAccountTokenValid: (domainAccountInfo: osAccount.DomainAccountInfo, token: Uint8Array,
                          callback: AsyncCallback<boolean>) => {},
    getAccessToken: (options: osAccount.GetDomainAccessTokenOptions, callback: AsyncCallback<Uint8Array>) => {}
  }
  osAccount.DomainAccountManager.registerPlugin(plugin)
  ```

### bindAccount<sup>10+</sup>

bindAccount(domainAccountInfo: DomainAccountInfo, localId: number, callback: AsyncCallback&lt;void&gt;): void

绑定指定的域账号。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名      | 类型                                    | 必填 | 说明             |
| ---------- | --------------------------------------- | ---- | --------------- |
| domainAccountInfo   | [DomainAccountInfo](#domainaccountinfo8)  | 是   | 指示域账号信息。|
| localId             | number  | 是   | 系统账号ID。 |
| callback   | AsyncCallback&lt;void&gt; | 是   | 指示绑定结果回调。|

**示例：**
  ```ts
  import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
  let plugin: osAccount.DomainPlugin = {
    auth: (domainAccountInfo: osAccount.DomainAccountInfo, credential: Uint8Array,
          callback: osAccount.IUserAuthCallback) => {},
    authWithPopup: (domainAccountInfo: osAccount.DomainAccountInfo,
                    callback: osAccount.IUserAuthCallback) => {},
    authWithToken: (domainAccountInfo: osAccount.DomainAccountInfo, token: Uint8Array,
                    callback: osAccount.IUserAuthCallback) => {},
    getAccountInfo: (options: osAccount.GetDomainAccountInfoPluginOptions,
                    callback: AsyncCallback<osAccount.DomainAccountInfo>) => {},
    getAuthStatusInfo: (domainAccountInfo: osAccount.DomainAccountInfo,
                        callback: AsyncCallback<osAccount.AuthStatusInfo>) => {},
    bindAccount: (domainAccountInfo: osAccount.DomainAccountInfo, localId: number,
                  callback: AsyncCallback<void>) => {
      // mock unbinding operation
      // notify binding result
      let code: BusinessError = {
        code: 0,
        name: "",
        message: ""
      };
      callback(code);
    },
    unbindAccount: (domainAccountInfo: osAccount.DomainAccountInfo, callback: AsyncCallback<void>) => {},
    isAccountTokenValid: (domainAccountInfo: osAccount.DomainAccountInfo, token: Uint8Array,
                          callback: AsyncCallback<boolean>) => {},
    getAccessToken: (options: osAccount.GetDomainAccessTokenOptions, callback: AsyncCallback<Uint8Array>) => {}
  }
  osAccount.DomainAccountManager.registerPlugin(plugin)
  ```

### unbindAccount<sup>10+</sup>

unbindAccount(domainAccountInfo: DomainAccountInfo, callback: AsyncCallback&lt;void&gt;): void

解绑指定的域账号。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名      | 类型                                    | 必填 | 说明             |
| ---------- | --------------------------------------- | ---- | --------------- |
| domainAccountInfo   | [DomainAccountInfo](#domainaccountinfo8)  | 是   | 指示域账号信息。|
| callback   | AsyncCallback&lt;void&gt; | 是   | 指示绑定结果回调。|

**示例：**
  ```ts
  import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
  let plugin: osAccount.DomainPlugin = {
    auth: (domainAccountInfo: osAccount.DomainAccountInfo, credential: Uint8Array,
          callback: osAccount.IUserAuthCallback) => {},
    authWithPopup: (domainAccountInfo: osAccount.DomainAccountInfo,
                    callback: osAccount.IUserAuthCallback) => {},
    authWithToken: (domainAccountInfo: osAccount.DomainAccountInfo, token: Uint8Array,
                    callback: osAccount.IUserAuthCallback) => {},
    getAccountInfo: (options: osAccount.GetDomainAccountInfoPluginOptions,
                    callback: AsyncCallback<osAccount.DomainAccountInfo>) => {},
    getAuthStatusInfo: (domainAccountInfo: osAccount.DomainAccountInfo,
                        callback: AsyncCallback<osAccount.AuthStatusInfo>) => {},
    bindAccount: (domainAccountInfo: osAccount.DomainAccountInfo, localId: number,
                  callback: AsyncCallback<void>) => {},
    unbindAccount: (domainAccountInfo: osAccount.DomainAccountInfo, callback: AsyncCallback<void>) => {
      // mock unbinding operation
      // notify unbinding result
      let code: BusinessError = {
        code: 0,
        name: "",
        message: ""
      };
      callback(code);
    },
    isAccountTokenValid: (domainAccountInfo: osAccount.DomainAccountInfo, token: Uint8Array,
                          callback: AsyncCallback<boolean>) => {},
    getAccessToken: (options: osAccount.GetDomainAccessTokenOptions, callback: AsyncCallback<Uint8Array>) => {}
  }
  osAccount.DomainAccountManager.registerPlugin(plugin)
  ```

### isAccountTokenValid<sup>10+</sup>

isAccountTokenValid(domainAccountInfo: DomainAccountInfo, token: Uint8Array, callback: AsyncCallback&lt;boolean&gt;): void

检查指定的域账号令牌是否有效。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名      | 类型                                    | 必填 | 说明             |
| ---------- | --------------------------------------- | ---- | --------------- |
| domainAccountInfo   | [DomainAccountInfo](#domainaccountinfo8)  | 是   | 指示域账号信息。|
| token | Uint8Array | 是 | 指示域账号令牌。 |
| callback   | AsyncCallback&lt;boolean&gt; | 是   | 指示检查结果回调。true表示指定的域账号令牌是有效的；false表示指定的域账号令牌是无效的。|

**示例：**
  ```ts
  import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
  let plugin: osAccount.DomainPlugin = {
    auth: (domainAccountInfo: osAccount.DomainAccountInfo, credential: Uint8Array,
          callback: osAccount.IUserAuthCallback) => {},
    authWithPopup: (domainAccountInfo: osAccount.DomainAccountInfo,
                    callback: osAccount.IUserAuthCallback) => {},
    authWithToken: (domainAccountInfo: osAccount.DomainAccountInfo, token: Uint8Array,
                    callback: osAccount.IUserAuthCallback) => {},
    getAccountInfo: (options: osAccount.GetDomainAccountInfoPluginOptions,
                    callback: AsyncCallback<osAccount.DomainAccountInfo>) => {},
    getAuthStatusInfo: (domainAccountInfo: osAccount.DomainAccountInfo,
                        callback: AsyncCallback<osAccount.AuthStatusInfo>) => {},
    bindAccount: (domainAccountInfo: osAccount.DomainAccountInfo, localId: number,
                  callback: AsyncCallback<void>) => {},
    unbindAccount: (domainAccountInfo: osAccount.DomainAccountInfo, callback: AsyncCallback<void>) => {},
    isAccountTokenValid: (domainAccountInfo: osAccount.DomainAccountInfo, token: Uint8Array,
                          callback: AsyncCallback<boolean>) => {
      // mock checking operation
      // notify checking result
      let code: BusinessError = {
        code: 0,
        name: "",
        message: ""
      };
      callback(code, true);
    },
    getAccessToken: (options: osAccount.GetDomainAccessTokenOptions, callback: AsyncCallback<Uint8Array>) => {}
  }
  osAccount.DomainAccountManager.registerPlugin(plugin)
  ```

### getAccessToken<sup>10+</sup>

getAccessToken(options: GetDomainAccessTokenOptions, callback: AsyncCallback&lt;Uint8Array&gt;): void

根据指定的选项获取域访问令牌。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名      | 类型                                    | 必填 | 说明             |
| ---------- | --------------------------------------- | ---- | --------------- |
| options | [GetDomainAccessTokenOptions](#getdomainaccesstokenoptions10)  | 是   | 指示获取域访问令牌的选项。|
| callback   | AsyncCallback&lt;Uint8Array&gt; | 是   | 指示结果回调。|

**示例：**
  ```ts
  import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
  let plugin: osAccount.DomainPlugin = {
    auth: (domainAccountInfo: osAccount.DomainAccountInfo, credential: Uint8Array,
          callback: osAccount.IUserAuthCallback) => {},
    authWithPopup: (domainAccountInfo: osAccount.DomainAccountInfo,
                    callback: osAccount.IUserAuthCallback) => {},
    authWithToken: (domainAccountInfo: osAccount.DomainAccountInfo, token: Uint8Array,
                    callback: osAccount.IUserAuthCallback) => {},
    getAccountInfo: (options: osAccount.GetDomainAccountInfoPluginOptions,
                    callback: AsyncCallback<osAccount.DomainAccountInfo>) => {},
    getAuthStatusInfo: (domainAccountInfo: osAccount.DomainAccountInfo,
                        callback: AsyncCallback<osAccount.AuthStatusInfo>) => {},
    bindAccount: (domainAccountInfo: osAccount.DomainAccountInfo, localId: number,
                  callback: AsyncCallback<void>) => {},
    unbindAccount: (domainAccountInfo: osAccount.DomainAccountInfo, callback: AsyncCallback<void>) => {},
    isAccountTokenValid: (domainAccountInfo: osAccount.DomainAccountInfo, token: Uint8Array,
                          callback: AsyncCallback<boolean>) => {},
    getAccessToken: (options: osAccount.GetDomainAccessTokenOptions, callback: AsyncCallback<Uint8Array>) => {
      // mock getting operation
      // notify result
      let code: BusinessError = {
        code: 0,
        name: "",
        message: ""
      };
      let token: Uint8Array = new Uint8Array([0]);
      callback(code, token);
    }
  }
  osAccount.DomainAccountManager.registerPlugin(plugin)
  ```

## DomainAccountManager <sup>9+</sup>
域账号管理器类。

### registerPlugin<sup>9+</sup>

static registerPlugin(plugin: DomainPlugin): void

注册域插件。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**参数：**

| 参数名    | 类型                     | 必填 | 说明                      |
| ----------| ----------------------- | --- | -------------------------- |
| plugin   | [DomainPlugin](#domainplugin9)  | 是  | 指示域插件。 |

**错误码：**

| 错误码ID | 错误信息                     |
| -------- | --------------------------- |
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.|
| 12300201 | The domain plugin has been registered. |

**示例：**
  ```ts
  import { AsyncCallback } from '@kit.BasicServicesKit';
  let plugin: osAccount.DomainPlugin = {
    auth: (domainAccountInfo: osAccount.DomainAccountInfo, credential: Uint8Array,
         callback: osAccount.IUserAuthCallback) => {},
    authWithPopup: (domainAccountInfo: osAccount.DomainAccountInfo,
                  callback: osAccount.IUserAuthCallback) => {},
    authWithToken: (domainAccountInfo: osAccount.DomainAccountInfo, token: Uint8Array,
                  callback: osAccount.IUserAuthCallback) => {},
    getAccountInfo: (options: osAccount.GetDomainAccountInfoPluginOptions,
                   callback: AsyncCallback<osAccount.DomainAccountInfo>) => {},
    getAuthStatusInfo: (domainAccountInfo: osAccount.DomainAccountInfo,
                        callback: AsyncCallback<osAccount.AuthStatusInfo>) => {},
    bindAccount: (domainAccountInfo: osAccount.DomainAccountInfo, localId: number,
                  callback: AsyncCallback<void>) => {},
    unbindAccount: (domainAccountInfo: osAccount.DomainAccountInfo, callback: AsyncCallback<void>) => {},
    isAccountTokenValid: (domainAccountInfo: osAccount.DomainAccountInfo, token: Uint8Array,
                        callback: AsyncCallback<boolean>) => {},
    getAccessToken: (options: osAccount.GetDomainAccessTokenOptions, callback: AsyncCallback<Uint8Array>) => {}
  }
  try {
    osAccount.DomainAccountManager.registerPlugin(plugin);
    console.log('registerPlugin success.');
  } catch(err) {
    console.error('registerPlugin err:' + JSON.stringify(err));
  }
  ```

### unregisterPlugin<sup>9+</sup>

static unregisterPlugin(): void

注销域插件。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**错误码：**

| 错误码ID | 错误信息                     |
| -------- | --------------------------- |
| 201 | Permission denied.|
| 202 | Not system application.|
| 801 | Capability not supported.|

**示例：**
  ```ts
  try {
    osAccount.DomainAccountManager.unregisterPlugin();
    console.log('unregisterPlugin success.');
  } catch(err) {
    console.error('unregisterPlugin err:' + JSON.stringify(err));
  }
  ```

### auth<sup>10+</sup>

auth(domainAccountInfo: DomainAccountInfo, credential: Uint8Array, callback: IUserAuthCallback): void

认证指定的域账号。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**需要权限：** ohos.permission.ACCESS_USER_AUTH_INTERNAL

**参数：**

| 参数名      | 类型                                    | 必填 | 说明             |
| ---------- | --------------------------------------- | ---- | --------------- |
| domainAccountInfo   | [DomainAccountInfo](#domainaccountinfo8)  | 是   | 指示域账号信息。|
| credential   | Uint8Array  | 是   | 指示域账号的凭据。|
| callback   | [IUserAuthCallback](#iuserauthcallback8)  | 是   | 指示认证结果回调。|

**错误码：**

| 错误码ID | 错误信息                     |
| -------- | --------------------------- |
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 |Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.|
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid domainAccountInfo or credential. |
| 12300003 | Domain account does not exist. |
| 12300013 | Network exception. |
| 12300101 | Authentication failed. |
| 12300109 | The authentication, enrollment, or update operation is canceled. |
| 12300110 | The authentication is locked. |
| 12300111 | The authentication time out. |
| 12300112 | The authentication service is busy. |
| 12300113 | The account authentication service does not exist. |
| 12300114 | The account authentication service works abnormally. |
| 12300211 | Server unreachable. |

**示例：**
  ```ts
  let domainAccountInfo: osAccount.DomainAccountInfo = {
    domain: 'CHINA',
    accountName: 'zhangsan'
  }
  let credential = new Uint8Array([0])
  try {
    osAccount.DomainAccountManager.auth(domainAccountInfo, credential, {
      onResult: (resultCode: number, authResult: osAccount.AuthResult) => {
        console.log('auth resultCode = ' + resultCode);
        console.log('auth authResult = ' + JSON.stringify(authResult));
      }
    });
  } catch (err) {
    console.error('auth exception = ' + JSON.stringify(err));
  }
  ```

### authWithPopup<sup>10+</sup>

authWithPopup(callback: IUserAuthCallback): void

弹框认证指定的域账号。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**需要权限：** ohos.permission.ACCESS_USER_AUTH_INTERNAL

从API version 11开始无需申请权限，建议升级SDK版本。

**参数：**

| 参数名      | 类型                                    | 必填 | 说明             |
| ---------- | --------------------------------------- | ---- | --------------- |
| callback   | [IUserAuthCallback](#iuserauthcallback8)  | 是   | 指示认证结果回调。|

**错误码：**

| 错误码ID | 错误信息                     |
| -------- | --------------------------- |
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.|
| 12300001 | The system service works abnormally. |
| 12300003 | No domain account is bound. |
| 12300013 | Network exception. |
| 12300101 | Authentication failed. |
| 12300109 | The authentication, enrollment, or update operation is canceled. |
| 12300110 | The authentication is locked. |
| 12300111 | The authentication time out. |
| 12300112 | The authentication service is busy. |
| 12300113 | The account authentication service does not exist. |
| 12300114 | The account authentication service works abnormally. |
| 12300211 | Server unreachable. |

**示例：**
  ```ts
  try {
    osAccount.DomainAccountManager.authWithPopup({
      onResult: (resultCode: number, authResult: osAccount.AuthResult) => {
        console.log('auth resultCode = ' + resultCode);
        console.log('auth authResult = ' + JSON.stringify(authResult));
      }
    })
  } catch (err) {
    console.error('auth exception = ' + JSON.stringify(err));
  }
  ```

### authWithPopup<sup>10+</sup>

authWithPopup(localId: number, callback: IUserAuthCallback): void

弹框认证指定的域账号。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**需要权限：** ohos.permission.ACCESS_USER_AUTH_INTERNAL

从API version 11开始无需申请权限，建议升级SDK版本。

**参数：**

| 参数名      | 类型                                    | 必填 | 说明             |
| ---------- | --------------------------------------- | ---- | --------------- |
| localId   | number  | 是   | 指示绑定域账号的系统账号的本地标识。|
| callback   | [IUserAuthCallback](#iuserauthcallback8)  | 是   | 指示认证结果回调。|

**错误码：**

| 错误码ID | 错误信息                     |
| -------- | --------------------------- |
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.|
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid localId. |
| 12300003 | No domain account is bound. |
| 12300013 | Network exception. |
| 12300101 | Authentication failed. |
| 12300109 | The authentication, enrollment, or update operation is canceled. |
| 12300110 | The authentication is locked. |
| 12300111 | The authentication time out. |
| 12300112 | The authentication service is busy. |
| 12300113 | The account authentication service does not exist. |
| 12300114 | The account authentication service works abnormally. |
| 12300211 | Server unreachable. |

**示例：**
  ```ts
  try {
    osAccount.DomainAccountManager.authWithPopup(100, {
      onResult: (resultCode: number, authResult: osAccount.AuthResult) => {
        console.log('authWithPopup resultCode = ' + resultCode);
        console.log('authWithPopup authResult = ' + JSON.stringify(authResult));
      }
    })
  } catch (err) {
    console.error('authWithPopup exception = ' + JSON.stringify(err));
  }
  ```

### hasAccount<sup>10+</sup>

hasAccount(domainAccountInfo: DomainAccountInfo, callback: AsyncCallback&lt;boolean&gt;): void

检查是否存在指定的域账号。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**参数：**

| 参数名      | 类型                                    | 必填 | 说明             |
| ---------- | --------------------------------------- | ---- | --------------- |
| domainAccountInfo   | [DomainAccountInfo](#domainaccountinfo8)  | 是   | 指示域账号信息。|
| callback   | AsyncCallback&lt;boolean&gt;  | 是   | 指示检查结果回调。true表示指定的域账号已存在；false表示指定的域账号不存在。|

**错误码：**

| 错误码ID | 错误信息                     |
| -------- | --------------------------- |
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.|
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid domainAccountInfo. |
| 12300013 | Network exception. |
| 12300014 | Not authenticated. |
| 12300111 | The operation time out. |
| 12300114 | The authentication service works abnormally. |
| 12300211 | Server unreachable. |

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let domainAccountInfo: osAccount.DomainAccountInfo = {
    domain: 'CHINA',
    accountName: 'zhangsan'
  }
  try {
    osAccount.DomainAccountManager.hasAccount(domainAccountInfo, (err: BusinessError, result: boolean) => {
      if (err) {
        console.error('call hasAccount failed, error: ' + JSON.stringify(err));
      } else {
        console.log('hasAccount result: ' + result);
      }
    });
  } catch (err) {
    console.error('hasAccount exception = ' + JSON.stringify(err));
  }
  ```

### hasAccount<sup>10+</sup>

hasAccount(domainAccountInfo: DomainAccountInfo): Promise&lt;boolean&gt;

检查是否存在指定的域账号。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**参数：**

| 参数名      | 类型                                    | 必填 | 说明             |
| ---------- | --------------------------------------- | ---- | --------------- |
| domainAccountInfo   | [DomainAccountInfo](#domainaccountinfo8)  | 是   | 指示域账号信息。|

**返回值：**

| 类型                      | 说明                     |
| :------------------------ | ----------------------- |
| Promise&lt;boolean&gt; | Promise对象。返回true表示指定的域账号已存在；返回false表示指定的域账号不存在。 |

**错误码：**

| 错误码ID | 错误信息                     |
| -------- | --------------------------- |
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.|
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid domainAccountInfo. |
| 12300013 | Network exception. |
| 12300014 | Not authenticated. |
| 12300111 | The operation time out. |
| 12300114 | The authentication service works abnormally. |
| 12300211 | Server unreachable. |

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let domainAccountInfo: osAccount.DomainAccountInfo = {
    domain: 'CHINA',
    accountName: 'zhangsan'
  }
  try {
    osAccount.DomainAccountManager.hasAccount(domainAccountInfo).then((result: boolean) => {
      console.log('hasAccount result: ' + result);
    }).catch((err: BusinessError) => {
        console.error('call hasAccount failed, error: ' + JSON.stringify(err));
    });
  } catch (err) {
    console.error('hasAccount exception = ' + JSON.stringify(err));
  }
  ```

### updateAccountToken<sup>10+</sup>

updateAccountToken(domainAccountInfo: DomainAccountInfo, token: Uint8Array, callback: AsyncCallback&lt;void&gt;): void

更新指定域账号的令牌，空令牌表示目标域账号的令牌失效。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**参数：**

| 参数名      | 类型                                    | 必填 | 说明             |
| ---------- | --------------------------------------- | ---- | --------------- |
| domainAccountInfo | [DomainAccountInfo](#domainaccountinfo8)  | 是   | 指示域账号信息。|
| token | Uint8Array  | 是   | 指示域账号的令牌。|
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。如果更新成功，err为null，否则为错误对象。|

**错误码：**

| 错误码ID | 错误信息                     |
| -------- | --------------------------- |
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid token. |
| 12300003 | Account not found. |

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let domainAccountInfo: osAccount.DomainAccountInfo = {
    domain: 'CHINA',
    accountName: 'zhangsan',
    accountId: '123456'
  }
  let token = new Uint8Array([0])
  try {
    osAccount.DomainAccountManager.updateAccountToken(domainAccountInfo, token, (err: BusinessError) => {
      if (err != null) {
        console.error('updateAccountToken failed, error: ' + JSON.stringify(err));
      } else {
        console.log('updateAccountToken successfully');
      }
    })
  } catch (err) {
    console.error('updateAccountToken exception = ' + JSON.stringify(err));
  }
  ```

### updateAccountToken<sup>10+</sup>

updateAccountToken(domainAccountInfo: DomainAccountInfo, token: Uint8Array): Promise&lt;void&gt;

更新指定域账号的令牌，空令牌表示目标域账号的令牌失效。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS

**参数：**

| 参数名      | 类型                                    | 必填 | 说明             |
| ---------- | --------------------------------------- | ---- | --------------- |
| domainAccountInfo | [DomainAccountInfo](#domainaccountinfo8)  | 是   | 指示域账号信息。|
| token | Uint8Array  | 是   | 指示域账号的令牌。|

**返回值：**

| 类型                      | 说明                     |
| :------------------------ | ----------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果的Promise对象。 |

**错误码：**

| 错误码ID | 错误信息                     |
| -------- | --------------------------- |
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid token. |
| 12300003 | Account not found. |

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let domainAccountInfo: osAccount.DomainAccountInfo = {
    domain: 'CHINA',
    accountName: 'zhangsan',
    accountId: '123456'
  }
  let token = new Uint8Array([0])
  try {
    osAccount.DomainAccountManager.updateAccountToken(domainAccountInfo, token).then(() => {
      console.log('updateAccountToken successfully');
    }).catch((err: BusinessError) => {
        console.error('updateAccountToken failed, error: ' + JSON.stringify(err));
    });
  } catch (err) {
    console.error('updateAccountToken exception = ' + JSON.stringify(err));
  }
  ```

### getAccountInfo<sup>10+</sup>

getAccountInfo(options: GetDomainAccountInfoOptions, callback: AsyncCallback&lt;DomainAccountInfo&gt;): void

查询指定的域账号信息，callback方式。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**需要权限：** ohos.permission.GET_DOMAIN_ACCOUNTS

**参数：**

| 参数名      | 类型                                    | 必填 | 说明             |
| ---------- | --------------------------------------- | ---- | --------------- |
| options   | [GetDomainAccountInfoOptions](#getdomainaccountinfooptions10)  | 是   | 指示域账号信息。|
| callback   | AsyncCallback&lt;DomainAccountInfo&gt;  | 是   | 指示查询结果回调。|

**错误码：**

| 错误码ID | 错误信息                     |
| -------- | --------------------------- |
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.|
| 12300001 | The system service works abnormally. |
| 12300003 | Account not found. |
| 12300013 | Network exception. |
| 12300014 | Not authenticated. |
| 12300111 | The operation time out. |
| 12300114 | The authentication service works abnormally. |
| 12300211 | Server unreachable. |

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let domainAccountInfo: osAccount.GetDomainAccountInfoOptions = {
    domain: 'CHINA',
    accountName: 'zhangsan'
  }
  try {
    osAccount.DomainAccountManager.getAccountInfo(domainAccountInfo,
      (err: BusinessError, result: osAccount.DomainAccountInfo) => {
      if (err) {
        console.error('call getAccountInfo failed, error: ' + JSON.stringify(err));
      } else {
        console.log('getAccountInfo result: ' + result);
      }
    });
  } catch (err) {
    console.error('getAccountInfo exception = ' + JSON.stringify(err));
  }
  ```

### getAccountInfo<sup>10+</sup>

getAccountInfo(options: GetDomainAccountInfoOptions): Promise&lt;DomainAccountInfo&gt;

查询指定的域账号信息，promise方式。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**需要权限：** ohos.permission.GET_DOMAIN_ACCOUNTS

**参数：**

| 参数名      | 类型                                    | 必填 | 说明             |
| ---------- | --------------------------------------- | ---- | --------------- |
| options   | [GetDomainAccountInfoOptions](#getdomainaccountinfooptions10)  | 是   | 指示域账号信息。|

**返回值：**

| 类型                      | 说明                     |
| :------------------------ | ----------------------- |
| Promise&lt;DomainAccountInfo&gt; | Promise对象，返回指定的域账号信息。 |

**错误码：**

| 错误码ID | 错误信息                     |
| -------- | --------------------------- |
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.|
| 12300001 | The system service works abnormally. |
| 12300003 | Account not found. |
| 12300013 | Network exception. |
| 12300014 | Not authenticated. |
| 12300111 | The operation time out. |
| 12300114 | The authentication service works abnormally. |
| 12300211 | Server unreachable. |

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let domainAccountInfo: osAccount.GetDomainAccountInfoOptions = {
    domain: 'CHINA',
    accountName: 'zhangsan'
  }
  try {
    osAccount.DomainAccountManager.getAccountInfo(domainAccountInfo)
      .then((result: osAccount.DomainAccountInfo) => {
      console.log('getAccountInfo result: ' + result);
    }).catch((err: BusinessError) => {
      console.error('call getAccountInfo failed, error: ' + JSON.stringify(err));
    });
  } catch (err) {
    console.error('getAccountInfo exception = ' + JSON.stringify(err));
  }
  ```

### getAccessToken<sup>11+</sup>

getAccessToken(businessParams: Record<string, Object>, callback: AsyncCallback&lt;Uint8Array&gt;): void

获取当前域账号的业务访问令牌，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名      | 类型                                    | 必填 | 说明             |
| ---------- | --------------------------------------- | ---- | --------------- |
| businessParams | Record<string, Object>  | 是   | 指示业务参数，具体格式取决于域插件的实现要求。|
| callback | AsyncCallback&lt;Uint8Array&gt;  | 是   | 指示结果回调。如果获取成功，err返回null，否则为错误对象。|

**错误码：**

| 错误码ID | 错误信息                     |
| -------- | --------------------------- |
| 202 | Not system application.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.|
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid business parameters. |
| 12300003 | Domain account not found. |
| 12300013 | Network exception. |
| 12300014 | The domain account is not authenticated. |
| 12300111 | The operation time out. |
| 12300114 | The authentication service works abnormally. |
| 12300211 | Server unreachable. |

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let businessParams: Record<string, Object> = {
    'clientId': 'xxx',
    'secretId': 'yyy'
  };  // depends on the implementation of the domain plugin
  try {
    osAccount.DomainAccountManager.getAccessToken(businessParams,
      (err: BusinessError, result: Uint8Array) => {
      if (err) {
        console.error('getAccessToken failed, error: ' + JSON.stringify(err));
      } else {
        console.log('getAccessToken result: ' + result);
      }
    });
  } catch (err) {
    console.error('getAccessToken exception = ' + JSON.stringify(err));
  }
  ```

### getAccessToken<sup>11+</sup>

getAccessToken(businessParams: Record<string, Object>): Promise&lt;Uint8Array&gt;

查询当前域账号的业务访问令牌，使用promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名      | 类型                                    | 必填 | 说明             |
| ---------- | --------------------------------------- | ---- | --------------- |
| businessParams | Record<string, Object> | 是   | 指示业务参数，具体格式取决于域插件的实现要求。|

**返回值：**

| 类型                      | 说明                     |
| :------------------------ | ----------------------- |
| Promise&lt;Uint8Array&gt; | Promise对象，返回业务访问令牌。 |

**错误码：**

| 错误码ID | 错误信息                     |
| -------- | --------------------------- |
| 202 | Not system application.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.|
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid business parameters. |
| 12300003 | Domain account not found. |
| 12300013 | Network exception. |
| 12300014 | The domain account is not authenticated. |
| 12300111 | The operation time out. |
| 12300114 | The authentication service works abnormally. |
| 12300211 | Server unreachable. |

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let businessParams: Record<string, Object> = {
    'clientId': 'xxx',
    'secretId': 'yyy'
  };  // depends on the implementation of the domain plugin
  try {
    osAccount.DomainAccountManager.getAccessToken(businessParams)
      .then((result: Uint8Array) => {
      console.log('getAccessToken result: ' + result);
    }).catch((err: BusinessError) => {
      console.error('getAccessToken failed, error: ' + JSON.stringify(err));
    });
  } catch (err) {
    console.error('getAccessToken exception = ' + JSON.stringify(err));
  }
  ```

### isAuthenticationExpired<sup>12+</sup>

isAuthenticationExpired(domainAccountInfo: DomainAccountInfo): Promise&lt;boolean&gt;;

判断指定域账号是否登录超期。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS 或 ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名      | 类型                                    | 必填 | 说明             |
| ---------- | --------------------------------------- | ---- | --------------- |
| domainAccountInfo   | [DomainAccountInfo](#domainaccountinfo8)  | 是   | 指示域账号信息。|

**返回值：**

| 类型                      | 说明                     |
| :------------------------ | ----------------------- |
| Promise&lt;boolean&gt; | Promise对象。返回true表示指定的域账号已登录超期；返回false表示指定的域账号未登录超期。 |

**错误码：**

| 错误码ID | 错误信息                     |
| -------- | --------------------------- |
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.|
| 12300001 | The system service works abnormally. |
| 12300003 | Domain account not found. |

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let domainInfo: osAccount.DomainAccountInfo =
    {domain: 'testDomain', accountName: 'testAccountName'};
  try {
    osAccount.DomainAccountManager.isAuthenticationExpired(domainInfo).then((result: boolean) => {
      console.log('isAuthenticationExpired, result: ' + result);
    }).catch((err: BusinessError) => {
      console.error('isAuthenticationExpired err: ' + err);
    });
  } catch (e) {
    console.error('isAuthenticationExpired exception: ' + e);
  }
  ```

## UserIdentityManager<sup>8+</sup>

获取用户身份管理类。

**系统接口：** 此接口为系统接口。

### constructor<sup>8+</sup>

constructor()

用户身份管理类的默认构造函数。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Account.OsAccount

**错误码：**

| 错误码ID | 错误信息                     |
| -------- | --------------------------- |
| 202 | Not system application.|

**示例：**
  ```ts
  let userIDM = new osAccount.UserIdentityManager();
  ```

### openSession<sup>8+</sup>

openSession(callback: AsyncCallback&lt;Uint8Array&gt;): void

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
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let userIDM = new osAccount.UserIdentityManager();
  try {
    userIDM.openSession((err: BusinessError, challenge: Uint8Array) => {
      if (err) {
        console.error('openSession exception = ' + JSON.stringify(err));
      } else {
        console.log('openSession challenge = ' + JSON.stringify(challenge));
      }
    });
  } catch (e) {
    console.error('openSession exception = ' + JSON.stringify(e));
  }
  ```

### openSession<sup>8+</sup>

openSession(accountId?: number): Promise&lt;Uint8Array&gt;

打开会话，获取挑战值（用于判断后续的身份认证场景是否处于该会话下，防止重放攻击）。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**需要权限：** ohos.permission.MANAGE_USER_IDM

**参数：**

| 参数名     | 类型    | 必填 | 说明        |
| --------- | ------- | ---- | ----------- |
| accountId<sup>12+</sup> | number  | 否   | 系统账号标识，默认为空。 |

**返回值：**

| 类型                      | 说明                     |
| :------------------------ | ----------------------- |
| Promise&lt;Uint8Array&gt; | Promise对象，返回挑战值。 |

**错误码：**

| 错误码ID | 错误信息                     |
| -------- | --------------------------- |
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 | Parameter error. Possible causes: Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300003 | Account not found. |
| 12300008 | Restricted account. |

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let userIDM = new osAccount.UserIdentityManager();
  let accountId = 100;
  try {
    userIDM.openSession(accountId).then((challenge: Uint8Array) => {
        console.info('openSession challenge = ' + JSON.stringify(challenge));
    }).catch((err: BusinessError) => {
        console.error('openSession error = ' + JSON.stringify(err));
    });
  } catch (e) {
    console.error('openSession exception = ' + JSON.stringify(e));
  }
  ```

### addCredential<sup>8+</sup>

addCredential(credentialInfo: CredentialInfo, callback: IIdmCallback): void

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
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid credentialInfo, i.e. authType or authSubType. |
| 12300003 | Account not found. |
| 12300008 | Restricted account. |
| 12300101 | The token is invalid. |
| 12300106 | The authentication type is not supported. |
| 12300109 | The authentication, enrollment, or update operation is canceled. |
| 12300111 | The operation time out. |
| 12300115 | The number of credentials reaches the upper limit. |
| 12300116 | Credential complexity verification failed. |

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let password: Uint8Array = new Uint8Array([0, 0, 0, 0, 0, 0]);
  let pinAuth: osAccount.PINAuth = new osAccount.PINAuth();
  pinAuth.registerInputer({
    onGetData: (authSubType: osAccount.AuthSubType, callback: osAccount.IInputData) => {
      callback.onSetData(authSubType, password);
    }
  });
  let credentialInfo: osAccount.CredentialInfo = {
    credType: osAccount.AuthType.PIN,
    credSubType: osAccount.AuthSubType.PIN_SIX,
    token: new Uint8Array([]),
  };
  let userIDM = new osAccount.UserIdentityManager();
  userIDM.openSession((err: BusinessError, challenge: Uint8Array) => {
    try {
    userIDM.addCredential(credentialInfo, {
      onResult: (result: number, extraInfo: osAccount.RequestResult) => {
        console.log('addCredential result = ' + result);
        console.log('addCredential extraInfo = ' + extraInfo);
      }
    });
    } catch (e) {
      console.error('addCredential exception = ' + JSON.stringify(e));
    }
  });
  ```

### updateCredential<sup>8+</sup>

updateCredential(credentialInfo: CredentialInfo, callback: IIdmCallback): void

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
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid credentialInfo, i.e. authType or authSubType. |
| 12300003 | Account not found. |
| 12300101 | The token is invalid. |
| 12300102 | The credential does not exist. |
| 12300106 | The authentication type is not supported. |
| 12300109 | The authentication, enrollment, or update operation is canceled. |
| 12300111 | The operation time out. |
| 12300116 | Credential complexity verification failed. |

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let userIDM = new osAccount.UserIdentityManager();
  let userAuth: osAccount.UserAuth = new osAccount.UserAuth();
  let pinAuth: osAccount.PINAuth = new osAccount.PINAuth();
  let password: Uint8Array = new Uint8Array([0, 0, 0, 0, 0, 0]);
  let credentialInfo: osAccount.CredentialInfo = {
    credType: osAccount.AuthType.PIN,
    credSubType: osAccount.AuthSubType.PIN_SIX,
    token: new Uint8Array([]),
  };
  pinAuth.registerInputer({
    onGetData: (authSubType: osAccount.AuthSubType, callback: osAccount.IInputData) => {
      callback.onSetData(authSubType, password);
    }
  });
  userIDM.openSession((err: BusinessError, challenge: Uint8Array) => {
    userAuth.auth(challenge, credentialInfo.credType, osAccount.AuthTrustLevel.ATL1, {
      onResult: (result: number, extraInfo: osAccount.AuthResult) => {
        if (result != osAccount.ResultCode.SUCCESS) {
          return;
        }
        if (extraInfo.token != null) {
          credentialInfo.token = extraInfo.token;
        }
        try {
          userIDM.updateCredential(credentialInfo, {
            onResult: (result: number, extraInfo: osAccount.RequestResult) => {
                console.log('updateCredential result = ' + result);
                console.log('updateCredential extraInfo = ' + extraInfo);
            }
          });
        } catch (e) {
          console.error('updateCredential exception = ' + JSON.stringify(e));
        }
      }
    });
  });
  ```

### closeSession<sup>8+</sup>

closeSession(accountId?: number): void

关闭会话，结束IDM操作。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**需要权限：** ohos.permission.MANAGE_USER_IDM

**参数：**

| 参数名     | 类型    | 必填 | 说明        |
| --------- | ------- | ---- | ----------- |
| accountId<sup>12+</sup> | number  | 否   | 系统账号标识，默认为空。 |

**错误码：**

| 错误码ID | 错误信息                     |
| -------- | --------------------------- |
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 | Parameter error. Possible causes: Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300003 | Account not found. |
| 12300008 | Restricted account. |

**示例：**
  ```ts
  let userIDM = new osAccount.UserIdentityManager();
  let accountId = 100;
  userIDM.closeSession(accountId);
  ```

### cancel<sup>8+</sup>

cancel(challenge: Uint8Array): void

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
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid challenge. |

**示例：**
  ```ts
  let userIDM = new osAccount.UserIdentityManager();
  let challenge: Uint8Array = new Uint8Array([0]);
  try {
    userIDM.cancel(challenge);
  } catch(err) {
    console.error('cancel err:' + JSON.stringify(err));
  }
  ```

### delUser<sup>8+</sup>

delUser(token: Uint8Array, callback: IIdmCallback): void

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
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300101 | The token is invalid. |

**示例：**
  ```ts
  let userIDM = new osAccount.UserIdentityManager();
  let token: Uint8Array = new Uint8Array([0]);
  try {
    userIDM.delUser(token, {
      onResult: (result: number, extraInfo: osAccount.RequestResult) => {
        console.log('delUser result = ' + result);
        console.log('delUser extraInfo = ' + JSON.stringify(extraInfo));
      }
    });
  } catch (e) {
    console.error('delUser exception = ' + JSON.stringify(e));
  }
  ```

### delCred<sup>8+</sup>

delCred(credentialId: Uint8Array, token: Uint8Array, callback: IIdmCallback): void

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
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid credentialId. |
| 12300101 | The token is invalid. |
| 12300102 | The credential does not exist. |

**示例：**
  ```ts
  let userIDM = new osAccount.UserIdentityManager();
  let credentialId: Uint8Array = new Uint8Array([0, 0, 0, 0, 0, 0, 0, 0]);
  let token: Uint8Array = new Uint8Array([0]);
  try {
    userIDM.delCred(credentialId, token, {
      onResult: (result: number, extraInfo: osAccount.RequestResult) => {
          console.log('delCred result = ' + result);
          console.log('delCred extraInfo = ' + JSON.stringify(extraInfo));
      }
    });
  } catch (e) {
    console.error('delCred exception = ' + JSON.stringify(e));
  }
  ```

### getAuthInfo<sup>8+</sup>

getAuthInfo(callback: AsyncCallback&lt;Array&lt;EnrolledCredInfo&gt;&gt;): void

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
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let userIDM = new osAccount.UserIdentityManager();
  try {
    userIDM.getAuthInfo((err: BusinessError, result: osAccount.EnrolledCredInfo[]) => {
      if (err) {
        console.error('getAuthInfo exception = ' + JSON.stringify(err));
      } else {
        console.log('getAuthInfo result = ' + JSON.stringify(result));
      }
    });
  } catch (e) {
    console.error('getAuthInfo exception = ' + JSON.stringify(e));
  }
  ```

### getAuthInfo<sup>8+</sup>

getAuthInfo(authType: AuthType, callback: AsyncCallback&lt;Array&lt;EnrolledCredInfo&gt;&gt;): void

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
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid authType. |

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let userIDM = new osAccount.UserIdentityManager();
  try {
    userIDM.getAuthInfo(osAccount.AuthType.PIN,
      (err: BusinessError, result: osAccount.EnrolledCredInfo[]) => {
      if (err) {
        console.error('getAuthInfo exception = ' + JSON.stringify(err));
      } else {
        console.log('getAuthInfo result = ' + JSON.stringify(result));
      }
    });
  } catch (e) {
    console.error('getAuthInfo exception = ' + JSON.stringify(e));
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
| authType | [AuthType](#authtype8)              | 否   | 认证类型，默认为空，表示查询所有认证类型的信息。|

**返回值：**

| 类型                                         | 说明                                                                     |
| :------------------------------------------- | :----------------------------------------------------------------------- |
| Promise&lt;Array&lt;[EnrolledCredInfo](#enrolledcredinfo8)&gt;&gt; | Promise对象，返回当前用户指定类型的所有已注册凭据信息。|

**错误码：**

| 错误码ID | 错误信息               |
| -------- | ------------------- |
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 | Parameter error. Possible causes: Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid authType. |

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let userIDM = new osAccount.UserIdentityManager();
  try {
    userIDM.getAuthInfo(osAccount.AuthType.PIN).then((result: osAccount.EnrolledCredInfo[]) => {
      console.log('getAuthInfo result = ' + JSON.stringify(result))
    }).catch((err: BusinessError) => {
      console.error('getAuthInfo error = ' + JSON.stringify(err));
    });
  } catch (e) {
    console.error('getAuthInfo exception = ' + JSON.stringify(e));
  }
  ```

### getAuthInfo<sup>12+</sup>

getAuthInfo(options?: GetAuthInfoOptions): Promise&lt;Array&lt;EnrolledCredInfo&gt;&gt;

依据提供的可选参数，获取认证信息。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**需要权限：** ohos.permission.USE_USER_IDM

**参数：**

| 参数名    | 类型                                | 必填 | 说明      |
| -------- | ----------------------------------- | ---- | -------- |
| options | [GetAuthInfoOptions](#getauthinfooptions12)          | 否   | 获取认证信息的可选参数集合。默认为空，表示查询当前用户所有已注册凭据信息。 |

**返回值：**

| 类型                                         | 说明                                                                     |
| :------------------------------------------- | :----------------------------------------------------------------------- |
| Promise&lt;Array&lt;[EnrolledCredInfo](#enrolledcredinfo8)&gt;&gt; | Promise对象，返回当前用户指定类型的所有已注册凭据信息。|

**错误码：**

| 错误码ID | 错误信息               |
| -------- | ------------------- |
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 | Parameter error. Possible causes: Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid options. |
| 12300003 | Account not found. |

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let userIDM = new osAccount.UserIdentityManager();
  let options: osAccount.GetAuthInfoOptions = {
    authType: osAccount.AuthType.PIN,
    accountId: 100,
  };
  try {
    userIDM.getAuthInfo(options).then((result: osAccount.EnrolledCredInfo[]) => {
      console.log('getAuthInfo result = ' + JSON.stringify(result))
    }).catch((err: BusinessError) => {
      console.error('getAuthInfo error = ' + JSON.stringify(err));
    });
  } catch (e) {
    console.error('getAuthInfo exception = ' + JSON.stringify(e));
  }
  ```

### getEnrolledId<sup>12+</sup>

getEnrolledId(authType: AuthType, accountId?: number): Promise&lt;Uint8Array&gt;

基于凭据类型，以及可选的账号标识，获取已注册的凭据ID。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**需要权限：** ohos.permission.USE_USER_IDM

**参数：**

| 参数名     | 类型                   | 必填 | 说明      |
| --------  | ---------------------- | ---- | -------- |
| authType  | [AuthType](#authtype8) | 是   | 认证凭据类型 |
| accountId | number                 | 否   | 系统账号标识，默认为空。 |

**返回值：**

| 类型                       | 说明                                                                     |
| :------------------------ | :----------------------------------------------------------------------- |
| Promise&lt;Uint8Array&gt; | Promise对象，返回已注册的凭据ID。|

**错误码：**

| 错误码ID | 错误信息               |
| -------- | ------------------- |
| 201 | Permission denied.|
| 202 | Not system application.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid authType. |
| 12300003 | Account not found. |
| 12300102 | The credential does not exist. |
| 12300106 | The authentication type is not supported. |

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let userIDM = new osAccount.UserIdentityManager();
  let authType: osAccount.AuthType = osAccount.AuthType.PIN;
  let accountId = 100;
  try {
    userIDM.getEnrolledId(authType, accountId).then((enrolledId: Uint8Array) => {
        console.info('getEnrolledId enrolledId = ' + JSON.stringify(enrolledId));
    }).catch((err: BusinessError) => {
        console.error('getEnrolledId error = ' + JSON.stringify(err));
    });
  } catch (e) {
    console.error('getEnrolledId exception = ' + JSON.stringify(e));
  }
  ```

## IInputData<sup>8+</sup>

密码数据回调。

**系统接口：** 此接口为系统接口。

### onSetData<sup>8+</sup>

onSetData: (authSubType: AuthSubType, data: Uint8Array) => void;

**系统接口：** 此接口为系统接口。

通知设置数据。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名      | 类型                                     | 必填 | 说明                                            |
| ---------- | ---------------------------------------- | ---- | ----------------------------------------------- |
| authSubType | [AuthSubType](#authsubtype8)             | 是   | 用于认证的凭据子类型。                            |
| data       | Uint8Array                               | 是   | 要设置的数据是凭据，用来在认证、添加、修改凭据操作。 |

**错误码：**

| 错误码ID | 错误信息               |
| -------- | ------------------- |
| 202 | Not system application.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300002 | Invalid pinSubType. |

**示例：**
  ```ts
  let password: Uint8Array = new Uint8Array([0, 0, 0, 0, 0, 0]);
  let passwordNumber: Uint8Array = new Uint8Array([1, 2, 3, 4]);
  let inputer: osAccount.IInputer = {
    onGetData: (authSubType: osAccount.AuthSubType, callback: osAccount.IInputData) => {
        if (authSubType == osAccount.AuthSubType.PIN_NUMBER) {
          callback.onSetData(authSubType, passwordNumber);
        } else {
          callback.onSetData(authSubType, password);
        }
    }
  };
  ```

## IInputer<sup>8+</sup>

凭据输入器回调。

**系统接口：** 此接口为系统接口。

### onGetData<sup>8+</sup>

onGetData: (authSubType: AuthSubType, callback: IInputData, options: GetInputDataOptions) => void;

通知调用者获取数据的回调函数。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名      | 类型                                    | 必填 | 说明             |
| ---------- | --------------------------------------- | ---- | --------------- |
| authSubType | [AuthSubType](#authsubtype8) | 是 | 认证凭据子类型。 |
| callback   | [IInputData](#iinputdata8)  | 是   | 指示密码数据回调。|
| options | [GetInputDataOptions](#getinputdataoptions-12) | 是 | 回调函数的可选参数集合。 |

**示例：**
  ```ts
  let password: Uint8Array = new Uint8Array([0, 0, 0, 0, 0, 0]);
  let passwordNumber: Uint8Array = new Uint8Array([1, 2, 3, 4]);
  let inputer: osAccount.IInputer = {
    onGetData: (authSubType: osAccount.AuthSubType,
      callback: osAccount.IInputData, options: osAccount.GetInputDataOptions) => {
        if (authSubType == osAccount.AuthSubType.PIN_NUMBER) {
          callback.onSetData(authSubType, passwordNumber);
        } else {
          callback.onSetData(authSubType, password);
        }
    }
  };
  let pinAuth: osAccount.PINAuth = new osAccount.PINAuth();
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
  ```ts
  let authCallback: osAccount.IUserAuthCallback = {
    onResult: (result: number, extraInfo: osAccount.AuthResult) => {
      console.log('auth result = ' + result);
      console.log('auth extraInfo = ' + JSON.stringify(extraInfo));
    }
  };
  ```

### onAcquireInfo?<sup>8+</sup>

onAcquireInfo?: (module: number, acquire: number, extraInfo: Uint8Array) => void;

身份认证信息获取回调函数。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名    | 类型     | 必填 | 说明                           |
| --------- | ------- | ---- | ----------------------------- |
| module    | number  | 是   | 指示用于身份验证的执行器类型。   |
| acquire   | number  | 是   | 指示不同身份验证执行器的tip代码。|
| extraInfo | Uint8Array     | 是   | 保留参数。                     |

**示例：**
  ```ts
  let authCallback: osAccount.IUserAuthCallback = {
    onResult: (result: number, extraInfo: osAccount.AuthResult) => {
      console.log('auth result = ' + result)
      console.log('auth extraInfo = ' + JSON.stringify(extraInfo));
    },
    onAcquireInfo: (module: number, acquire: number, extraInfo: Uint8Array) => {
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
  ```ts
  let idmCallback: osAccount.IIdmCallback = {
    onResult: (result: number, extraInfo: osAccount.RequestResult) => {
      console.log('callback result = ' + result)
      console.info('callback extraInfo = ' + JSON.stringify(extraInfo));
    }
  };
  ```

### onAcquireInfo?<sup>8+</sup>

onAcquireInfo?: (module: number, acquire: number, extraInfo: Uint8Array) => void;

身份管理信息获取回调函数。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名    | 类型     | 必填 | 说明                           |
| --------- | ------- | ---- | ----------------------------- |
| module    | number  | 是   | 指示用于身份验证的执行器类型。   |
| acquire   | number  | 是   | 指示不同身份验证执行器的tip代码。|
| extraInfo | Uint8Array | 是   | 保留参数。                     |

**示例：**
  ```ts
  let idmCallback: osAccount.IIdmCallback = {
    onResult: (result: number, extraInfo: Object) => {
      console.log('callback result = ' + result)
      console.log('callback onResult = ' + JSON.stringify(extraInfo));
    },
    onAcquireInfo: (module: number, acquire: number, extraInfo: Uint8Array) => {
      console.log('callback module = ' + module);
      console.log('callback acquire = ' + acquire);
      console.log('callback onacquireinfo = ' + JSON.stringify(extraInfo));
    }
  };
  ```

## GetPropertyRequest<sup>8+</sup>

提供获取属性请求的信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

| 名称    | 类型                                                          | 必填   | 说明                   |
| -------- | ------------------------------------------------------------- | ----- | ----------------------- |
| authType | [AuthType](#authtype8)                            | 是    | 身份验证凭据类型。        |
| keys     | Array&lt;[GetPropertyType](#getpropertytype8)&gt; | 是    | 指示要获取的属性类型数组。 |
| accountId<sup>12+</sup> | number | 否 | 系统账号标识，默认为undefined。 |

## SetPropertyRequest<sup>8+</sup>

提供设置属性请求的信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

| 名称    | 类型                                             | 必填   | 说明                 |
| -------- | ------------------------------------------------ | ----- | -------------------- |
| authType | [AuthType](#authtype8)               | 是    | 身份验证凭据类型。     |
| key     | [SetPropertyType](#setpropertytype8) | 是    | 指示要设置的属性类型。 |
| setInfo  | Uint8Array                                       | 是    | 指示要设置的信息。     |

## ExecutorProperty<sup>8+</sup>

提供执行器的属性。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

| 名称         | 类型                         |  可读 | 可写 | 说明              |
| ------------ | ---------------------------- | ----- | -----|----------------- |
| result       | number                       | 是    | 是   | 指示结果。         |
| authSubType  | [AuthSubType](#authsubtype8) | 是    | 是   | 指示认证凭据子类型。|
| remainTimes  | number                       | 是    | 是   | 指示剩余次数。     |
| freezingTime | number                       | 是    | 是   | 指示冻结时间。     |
| enrollmentProgress<sup>10+</sup> | string   | 是    | 是   | 指示录入进度，默认为空。 |
| sensorInfo<sup>10+</sup> | string           | 是    | 是   | 指示传感器信息，默认为空。 |
| nextPhaseFreezingTime<sup>12+</sup> | number | 是    | 是   | 指示下次冻结时间，默认为undefined。 |
| credentialLength<sup>20+</sup> | number | 是    | 是   | 指示凭据长度，默认为undefined。查询生物信息等无定长属性的凭据时返回undefined。 |

## AuthResult<sup>8+</sup>

表示认证结果的信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

| 名称        | 类型        | 必填   | 说明              |
| ------------ | ----------- | ----- | ----------------- |
| token        | Uint8Array  | 否    | 指示认证令牌，默认为空。      |
| remainTimes  | number      | 否    | 指示剩余次数，默认为空。      |
| freezingTime | number      | 否    | 指示冻结时间，默认为空。      |
| nextPhaseFreezingTime<sup>12+</sup> | number | 否    | 指示下次冻结时间，默认为undefined。 |
| credentialId<sup>12+</sup> | Uint8Array  | 否    | 指示凭据ID，默认为空。 |
| accountId<sup>12+</sup>         | number | 否    | 指示系统账号标识，默认为undefined。 |
| pinValidityPeriod<sup>12+</sup> | number | 否    | 指示认证有效期，默认为undefined。 |

## CredentialInfo<sup>8+</sup>

表示凭证信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

| 名称        | 类型                                     | 必填   | 说明              |
| ------------ | ---------------------------------------- | ----- | ----------------- |
| credType     | [AuthType](#authtype8)       | 是    | 指示凭据类型。     |
| credSubType  | [AuthSubType](#authsubtype8) | 是    | 指示凭据子类型。   |
| token        | Uint8Array                           | 是    | 指示认证令牌。     |
| accountId<sup>12+</sup>    | number | 否    | 系统账号标识，默认为undefined。 |

## RequestResult<sup>8+</sup>

表示请求结果的信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

| 名称        | 类型        | 必填   | 说明              |
| ------------ | ----------- | ----- | ----------------- |
| credentialId | Uint8Array  | 否    | 指示凭据索引，默认为空。      |

## EnrolledCredInfo<sup>8+</sup>

表示已注册凭据的信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

| 名称        | 类型                                     | 必填   | 说明              |
| ------------ | ---------------------------------------- | ----- | ------------------- |
| credentialId | Uint8Array                               | 是    | 指示凭据索引。       |
| authType     | [AuthType](#authtype8)       | 是    | 指示认证凭据类型。   |
| authSubType  | [AuthSubType](#authsubtype8) | 是    | 指示认证凭据子类型。 |
| templateId   | Uint8Array                               | 是    | 指示凭据模板ID。     |
| isAbandoned<sup>20+</sup>   | boolean                      | 否    | 指示凭据是否废弃。废弃后的凭据可能作为备份凭据保存一段时间。默认为undefined，表示是否废弃未定义。   |
| validityPeriod<sup>20+</sup>   | number                    | 否    | 指示凭据有效期。默认为undefined，表示有效期未定义。     |

## GetPropertyType<sup>8+</sup>

表示要获取的属性类型的枚举。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

| 名称           | 值 | 说明      |
| ------------- | ------ | --------- |
| AUTH_SUB_TYPE | 1      | 认证子类型。 |
| REMAIN_TIMES  | 2      | 剩余次数。   |
| FREEZING_TIME | 3      | 冻结时间。   |
| ENROLLMENT_PROGRESS<sup>10+</sup> | 4      | 录入进度。   |
| SENSOR_INFO<sup>10+</sup> | 5      | 传感器信息。   |
| NEXT_PHASE_FREEZING_TIME<sup>12+</sup> | 6 | 下次冻结时间。 |
| CREDENTIAL_LENGTH<sup>20+</sup> | 7 | 凭据长度。 |

## SetPropertyType<sup>8+</sup>

表示要设置的属性类型的枚举。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

| 名称           | 值 | 说明        |
| -------------- | ----- | ----------- |
| INIT_ALGORITHM | 1     | 初始化算法。 |

## AuthType<sup>8+</sup>

表示身份验证的凭据类型的枚举。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

| 名称  | 值 | 说明             |
| ----- | ----- | ---------------- |
| PIN   | 1     | 表示PIN认证类型。 |
| FACE  | 2     | 表示脸部认证类型。|
| FINGERPRINT<sup>10+</sup>   | 4     | 表示指纹认证类型。 |
| RECOVERY_KEY<sup>12+</sup> | 8 | 表示键恢复类型。 |
| PRIVATE_PIN<sup>14+</sup> | 16 | 表示隐私PIN类型。 |
| DOMAIN<sup>9+</sup>  | 1024     | 表示域认证类型。|

## AuthSubType<sup>8+</sup>

表示用于认证的凭据子类型的枚举。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

| 名称       | 值 | 说明               |
| ---------- | ----- | ------------------ |
| PIN_SIX    | 10000 | 表示6位凭证。       |
| PIN_NUMBER | 10001 | 表示自定义数字凭证。 |
| PIN_MIXED  | 10002 | 表示自定义混合凭据。 |
| PIN_FOUR<sup>12+</sup>   | 10003 | 表示4位凭证。 |
| PIN_PATTERN<sup>12+</sup>  | 10004 | 表示图案凭据。 |
| PIN_QUESTION<sup>14+</sup>  | 10005 | 表示密保问题凭据。 |
| FACE_2D    | 20000 | 表示2D 人脸凭证。   |
| FACE_3D    | 20001 | 表示3D 人脸凭证。   |
| FINGERPRINT_CAPACITIVE<sup>10+</sup>    | 30000 | 表示电容式指纹。   |
| FINGERPRINT_OPTICAL<sup>10+</sup>    | 30001 | 表示光学指纹。   |
| FINGERPRINT_ULTRASONIC<sup>10+</sup>    | 30002 | 表示超声波指纹。   |
| DOMAIN_MIXED<sup>9+</sup>    | 10240001 | 表示域认证混合凭证。   |

## AuthTrustLevel<sup>8+</sup>

表示认证结果的受信任级别的枚举。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

| 名称  | 值 | 说明        |
| ---- | ------ | ----------- |
| ATL1 | 10000  | 信任级别 1。 |
| ATL2 | 20000  | 信任级别 2。 |
| ATL3 | 30000  | 信任级别 3。 |
| ATL4 | 40000  | 信任级别 4。 |

## Module<sup>8+</sup>

表示获取信息的模块的枚举。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

| 名称       | 值 | 说明                     |
| --------- | ------ | ------------------------ |
| FACE_AUTH | 1      | 表示从人脸认证获取的信息。 |

## ResultCode<sup>8+</sup>

表示身份验证结果码。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

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

**系统能力：** SystemCapability.Account.OsAccount

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

**系统能力：** SystemCapability.Account.OsAccount

| 名称                          | 值 | 说明                                            |
| ----------------------------- | ----- | ----------------------------------------------- |
| FINGERPRINT_TIP_GOOD          | 0     | 表示采集的图像良好。                              |
| FINGERPRINT_TIP_IMAGER_DIRTY  | 1     | 表示由于传感器上可疑或检测到污垢，指纹图像噪声过大。 |
| FINGERPRINT_TIP_INSUFFICIENT  | 2     | 表示由于检测到的情况，指纹图像噪声太大，无法处理。   |
| FINGERPRINT_TIP_PARTIAL       | 3     | 表示仅检测到部分指纹图像。                         |
| FINGERPRINT_TIP_TOO_FAST      | 4     | 表示指纹图像由于快速运动而不完整。                  |
| FINGERPRINT_TIP_TOO_SLOW      | 5     | 表示由于缺少运动，指纹图像无法读取。                |
| FINGERPRINT_TIP_FINGER_DOWN<sup>10+</sup>   | 6     | 表示手指落下。                  |
| FINGERPRINT_TIP_FINGER_UP<sup>10+</sup>     | 7     | 表示手指抬起。                |

## OsAccountInfo

表示系统账号信息。

**系统能力：** SystemCapability.Account.OsAccount

| 名称      | 类型   | 必填 | 说明       |
| ----------- | ------ | ---- | ---------- |
| shortName<sup>12+</sup> | string | 否   | 系统账号的短名称。<br>**系统接口：** 此接口为系统接口，默认为空。 |
| isLoggedIn<sup>12+</sup> | boolean | 否   | 是否登录。true表示已登录；false表示未登录。<br>**系统接口：** 此接口为系统接口，默认为false。 |

## OsAccountType

表示系统账号类型的枚举。

**系统能力：** SystemCapability.Account.OsAccount。

| 名称   | 值 | 说明         |
| ------ | ------ | ----------- |
| PRIVATE<sup>12+</sup> | 1024  | 隐私账号。隐私账号只能有一个。<br>**系统接口：** 此接口为系统接口。   |

## DomainAccountInfo<sup>8+</sup>

表示域账号信息。

**系统能力：** SystemCapability.Account.OsAccount

| 名称      | 类型   | 必填 | 说明       |
| ----------- | ------ | ---- | ---------- |
| accountId<sup>10+</sup> | string | 否   | 域账号标识。<br>**系统接口：** 此接口为系统接口，默认为undefined。 |
| isAuthenticated<sup>11+</sup>| boolean | 否 | 指示域账号是否已认证。true表示指定的域账号已认证；false表示指定的域账号未认证。<br>**系统接口：** 此接口为系统接口，默认为false。|

## ConstraintSourceTypeInfo<sup>9+</sup>

表示约束来源类型信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

| 名称      | 类型   | 必填 | 说明       |
| ----------- | ------ | ---- | ---------- |
| localId      | number | 是   | 系统账号ID     |
| type | [ConstraintSourceType](#constraintsourcetype9) | 是   | 约束来源类型。 |

## ConstraintSourceType<sup>9+</sup>

表示约束来源类型的枚举。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

| 名称   | 值 | 说明         |
| ------ | ------ | ------------ |
| CONSTRAINT_NOT_EXIST  | 0      | 约束不存在。 |
| CONSTRAINT_TYPE_BASE | 1      | 约束源自系统设置。   |
| CONSTRAINT_TYPE_DEVICE_OWNER  | 2   | 约束源自设备所有者设置。   |
| CONSTRAINT_TYPE_PROFILE_OWNER  | 3  | 约束源自资料所有者设置。   |

## AuthStatusInfo<sup>10+</sup>

表示认证状态信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

| 名称      | 类型   | 必填 | 说明       |
| ----------- | ------ | ---- | ---------- |
| remainTimes  | number | 是   | 剩余次数。   |
| freezingTime | number | 是   | 冻结时间。 |

## GetDomainAccessTokenOptions<sup>10+</sup>

表示获取域访问令牌的选项。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

| 名称      | 类型   | 必填 | 说明       |
| ----------- | ------ | ---- | ---------- |
| domainAccountInfo  | [DomainAccountInfo](#domainaccountinfo8) | 是   | 域账号的信息。   |
| domainAccountToken | Uint8Array | 是   | 域账号的令牌。 |
| businessParams | Record<string, Object> | 是   | 业务参数，由业务方根据请求协议自定义。 |
| callerUid | number | 是   | 调用方唯一标识符。 |

## GetDomainAccountInfoOptions<sup>10+</sup>

表示查询域账号信息的选项。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

| 名称      | 类型   | 必填 | 说明       |
| ----------- | ------ | ---- | ---------- |
| accountName | string | 是   | 域账号名。 |
| domain      | string | 否   | 域名。默认为undefined。|
| serverConfigId<sup>12+</sup>| string | 否 | 域账号所属服务器标识。默认为undefined。|

## GetDomainAccountInfoPluginOptions<sup>10+</sup>

表示插件查询域账号信息的选项。GetDomainAccountInfoPluginOptions类继承[GetDomainAccountInfoOptions](#getdomainaccountinfooptions10)

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

| 名称      | 类型   | 必填 | 说明       |
| ----------- | ------ | ---- | ---------- |
| callerUid | number | 是   | 调用方唯一标识符。 |

## OsAccountSwitchEventData<sup>12+</sup>

表示系统账号前后台开始切换和结束切换事件的数据结构。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

| 名称      | 类型   | 必填 | 说明       |
| ----------- | ------ | ---- | ---------- |
| fromAccountId | number | 是   | 切换前系统账号ID。 |
| toAccountId | number | 是   | 切换后系统账号ID。 |

## CreateOsAccountOptions<sup>12+</sup>

表示用于创建系统账号的可选参数。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

| 名称      | 类型   | 必填 | 说明       |
| ----------- | ------ | ---- | ---------- |
| shortName | string | 是   | 表示账号短名称（用作个人文件夹目录）。 <br/>**约束：** <br>1）不允许出现的字符：\< \> \| : " * ? / \\<br>2）不允许独立出现的字符串：.或..<br>3）长度不超过255个字符。|
| disallowedPreinstalledBundles<sup>19+</sup> | Array&lt;string&gt; | 否   | 表示预置应用禁止名单，名单中的应用不可被安装在设备上。|
| allowedPreinstalledBundles<sup>19+</sup> | Array&lt;string&gt; | 否   | 表示预置应用允许名单，仅名单中的应用可以被安装在设备上。|

## CreateOsAccountForDomainOptions<sup>12+</sup>

表示用于创建与指定域账号绑定的系统账号的可选参数。继承自[CreateOsAccountOptions](#createosaccountoptions12)。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

| 名称      | 类型   | 必填 | 说明       |
| ----------- | ------ | ---- | ---------- |
| shortName | string | 是   | 表示账号短名称（用作个人文件夹目录）。 <br/>**约束：** <br>1）不允许出现的字符：\< \> \| : " * ? / \\<br>2）不允许独立出现的字符串：.或..<br>3）长度不超过255个字符。|

## GetAuthInfoOptions<sup>12+</sup>

表示[查询认证凭据信息](#getauthinfo12)的可选参数集合。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

| 名称      | 类型                    | 必填 | 说明       |
| --------- | ---------------------- | ---- | ---------- |
| authType  | [AuthType](#authtype8) | 否   | 认证类型，默认为undefined。 |
| accountId | number                 | 否   | 系统账号标识，默认为undefined。 |

## AuthIntent<sup>12+</sup>

表示认证意图的枚举。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

| 名称     | 值   | 说明       |
| -------- | --- | ---------- |
| UNLOCK   | 1   | 解锁意图。 |
| SILENT_AUTH<sup>14+</sup>  | 2   | 静默认证意图。 |
| QUESTION_AUTH<sup>14+</sup>   | 3   | 密保问题认证意图。 |
| ABANDONED_PIN_AUTH<sup>20+</sup>   | 4   | 废弃PIN码认证意图。用户修改锁屏密码后，旧的PIN码被废弃。废弃PIN存在期间，用户如果忘记密码可以通过废弃PIN认证通过后重置锁屏密码。 |

## RemoteAuthOptions<sup>12+</sup>

表示远程认证的可选参数集合。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

| 名称               | 类型    | 必填 | 说明       |
| ------------------ | ------ | ---- | ---------- |
| verifierNetworkId  | string | 否   | 凭据验证者的网络标识，默认为空。 |
| collectorNetworkId | string | 否   | 凭据收集者的网络标识，默认为空。 |
| collectorTokenId   | number | 否   | 凭据收集者的令牌标识，默认为undefined。 |

## AuthOptions<sup>12+</sup>

表示[认证用户](#auth12)的可选参数集合。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

| 名称               | 类型    | 必填 | 说明       |
| ------------------ | ------ | ---- | ---------- |
| accountId          | number | 否   | 系统账号标识，默认为undefined。 |
| authIntent         | [AuthIntent](#authintent12) | 否   | 认证意图，默认为undefined。 |
| remoteAuthOptions  | [RemoteAuthOptions](#remoteauthoptions12) | 否   | 远程认证选项，默认为undefined。 |

## GetInputDataOptions <sup>12+</sup>

表示[通知调用者获取数据](#ongetdata8)的可选参数集合。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.OsAccount

| 名称               | 类型    | 必填 | 说明       |
| ------------------ | ------ | ---- | ---------- |
| challenge          | Uint8Array | 否   | 挑战值，默认为undefined。 |
