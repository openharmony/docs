# @ohos.account.osAccount (系统账号管理)

本模块提供管理系统账号的基础能力，包括系统账号的添加、删除、查询、设置、订阅、启动等功能。

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { osAccount } from '@kit.BasicServicesKit';
```

## osAccount.getAccountManager

getAccountManager(): AccountManager

获取系统账号管理对象。

**系统能力：** SystemCapability.Account.OsAccount

**返回值：**

| 类型                              | 说明              |
| --------------------------------- | ---------------- |
| [AccountManager](#accountmanager) | 系统账号管理对象。 |

**示例：**

  ```ts
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  ```

## OsAccountType

表示系统账号类型的枚举。

**系统能力：** SystemCapability.Account.OsAccount。

| 名称   | 值 | 说明         |
| ------ | ------ | ----------- |
| ADMIN  | 0      | 管理员账号。 |
| NORMAL | 1      | 普通账号。   |
| GUEST  | 2      | 访客账号。   |

## AccountManager

系统账号管理类。

### checkMultiOsAccountEnabled<sup>9+</sup>

checkMultiOsAccountEnabled(callback: AsyncCallback&lt;boolean&gt;): void

判断是否支持多系统账号。使用callback异步回调。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                         | 必填 | 说明                                                     |
| -------- | ---------------------------- | ---- | ------------------------------------------------------ |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调函数。返回true表示支持多系统账号；返回false表示不支持。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  try {
    accountManager.checkMultiOsAccountEnabled((err: BusinessError, isEnabled: boolean) => {
      if (err) {
        console.error(`checkMultiOsAccountEnabled failed, code is ${err.code}, message is ${err.message}`);
      } else {
      console.log('checkMultiOsAccountEnabled successfully, isEnabled: ' + isEnabled);
      }
    });
  } catch (err) {
    console.log('checkMultiOsAccountEnabled failed, error:' + JSON.stringify(err));
  }
  ```

### checkMultiOsAccountEnabled<sup>9+</sup>

checkMultiOsAccountEnabled(): Promise&lt;boolean&gt;

判断是否支持多系统账号。使用Promise异步回调。

**系统能力：** SystemCapability.Account.OsAccount

**返回值：**

| 类型                   | 说明                                                        |
| :--------------------- | :--------------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise对象。返回true表示支持多系统账号；返回false表示不支持。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 12300001 | The system service works abnormally. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  try {
    let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
    accountManager.checkMultiOsAccountEnabled().then((isEnabled: boolean) => {
      console.log('checkMultiOsAccountEnabled successfully, isEnabled: ' + isEnabled);
    }).catch((err: BusinessError) => {
      console.error(`checkMultiOsAccountEnabled failed, code is ${err.code}, message is ${err.message}`);
    });
  } catch (err) {
    console.log('checkMultiOsAccountEnabled failed, error:' + JSON.stringify(err));
  }
  ```

### checkOsAccountActivated<sup>(deprecated)</sup>

checkOsAccountActivated(localId: number, callback: AsyncCallback&lt;boolean&gt;): void

判断指定系统账号是否处于激活状态。使用callback异步回调。

> **说明：**
>
> 从 API version 9开始支持，从API version 11开始废弃。替代方法仅向系统应用开放。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS 或 ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS，以上权限仅系统应用可申请。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                         | 必填 | 说明                                                     |
| -------- | ---------------------------- | ---- | ------------------------------------------------------ |
| localId  | number                       | 是   | 系统账号ID。                                             |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调函数。返回true表示账号已激活；返回false表示账号未激活。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 201 | Permission denied.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid localId.    |
| 12300003 | Account not found. |

**示例：** 判断ID为100的系统账号是否处于激活状态

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let localId: number = 100;
  try {
    accountManager.checkOsAccountActivated(localId, (err: BusinessError, isActivated: boolean) => {
      if (err) {
        console.log('checkOsAccountActivated failed, error:' + JSON.stringify(err));
      } else {
        console.log('checkOsAccountActivated successfully, isActivated:' + isActivated);
      }
    });
  } catch (err) {
    console.log('checkOsAccountActivated exception: ' + JSON.stringify(err));
  }
  ```

### checkOsAccountActivated<sup>(deprecated)</sup>

checkOsAccountActivated(localId: number): Promise&lt;boolean&gt;

判断指定系统账号是否处于激活状态。使用Promise异步回调。

> **说明：**
>
> 从 API version 9开始支持，从API version 11开始废弃。替代方法仅向系统应用开放。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS 或 ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS，以上权限仅系统应用可申请。

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
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid localId.    |
| 12300003 | Account not found. |

**示例：** 判断ID为100的系统账号是否处于激活状态

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let localId: number = 100;
  try {
    accountManager.checkOsAccountActivated(localId).then((isActivated: boolean) => {
      console.log('checkOsAccountActivated successfully, isActivated: ' + isActivated);
    }).catch((err: BusinessError) => {
      console.log('checkOsAccountActivated failed, error: ' + JSON.stringify(err));
    });
  } catch (err) {
    console.log('checkOsAccountActivated exception: ' + JSON.stringify(err));
  }
  ```

### isOsAccountConstraintEnabled<sup>11+</sup>

isOsAccountConstraintEnabled(constraint: string): Promise&lt;boolean&gt;

判断当前系统账号是否使能指定约束。使用Promise异步回调。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名     | 类型   | 必填 | 说明                                |
| ---------- | ------ | ---- | ---------------------------------- |
| constraint | string | 是   | 指定的[约束](#系统账号约束列表)名称。 |

**返回值：**

| 类型                   | 说明                                                                  |
| --------------------- | --------------------------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise对象。返回true表示已使能指定的约束；返回false表示未使能指定的约束。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 12300001 | The system service works abnormally. |

**示例：** 判断ID为100的系统账号是否有禁止使用Wi-Fi的约束

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let constraint: string = 'constraint.wifi';
  try {
    accountManager.isOsAccountConstraintEnabled(constraint).then((isEnabled: boolean) => {
      console.log('isOsAccountConstraintEnabled successfully, isEnabled: ' + isEnabled);
    }).catch((err: BusinessError) => {
      console.log('isOsAccountConstraintEnabled failed, error: ' + JSON.stringify(err));
    });
  } catch (err) {
    console.log('isOsAccountConstraintEnabled exception: ' + JSON.stringify(err));
  }
  ```

### checkOsAccountConstraintEnabled<sup>(deprecated)</sup>

checkOsAccountConstraintEnabled(localId: number, constraint: string, callback: AsyncCallback&lt;boolean&gt;): void

判断指定系统账号是否具有指定约束。使用callback异步回调。

> **说明：**
>
> 从 API version 9开始支持，从API version 11开始废弃。替代方法仅向系统应用开放。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS 或 ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS，以上权限仅系统应用可申请。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名     | 类型                         | 必填 | 说明                                                               |
| ---------- | ---------------------------- | ---- | ----------------------------------------------------------------- |
| localId    | number                       | 是   | 系统账号ID。                                 |
| constraint | string                       | 是   | 指定的[约束](#系统账号约束列表)名称。                                |
| callback   | AsyncCallback&lt;boolean&gt; | 是   | 回调函数。返回true表示已使能指定的约束；返回false表示未使能指定的约束。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 201 | Permission denied.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid localId or constraint.    |
| 12300003 | Account not found. |

**示例：** 判断ID为100的系统账号是否有禁止使用Wi-Fi的约束

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let localId: number = 100;
  let constraint: string = 'constraint.wifi';
  try {
    accountManager.checkOsAccountConstraintEnabled(localId, constraint, (err: BusinessError, isEnabled: boolean)=>{
      if (err) {
        console.log('checkOsAccountConstraintEnabled failed, error: ' + JSON.stringify(err));
      } else {
        console.log('checkOsAccountConstraintEnabled successfully, isEnabled: ' + isEnabled);
      }
    });
  } catch (err) {
    console.log('checkOsAccountConstraintEnabled exception: ' + JSON.stringify(err));
  }
  ```

### checkOsAccountConstraintEnabled<sup>(deprecated)</sup>

checkOsAccountConstraintEnabled(localId: number, constraint: string): Promise&lt;boolean&gt;

判断指定系统账号是否具有指定约束。使用Promise异步回调。

> **说明：**
>
> 从 API version 9开始支持，从API version 11开始废弃。替代方法仅向系统应用开放。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS 或 ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS，以上权限仅系统应用可申请。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名     | 类型   | 必填 | 说明                                |
| ---------- | ------ | ---- | ---------------------------------- |
| localId    | number | 是   | 系统账号ID。  |
| constraint | string | 是   | 指定的[约束](#系统账号约束列表)名称。 |

**返回值：**

| 类型                   | 说明                                                                  |
| --------------------- | --------------------------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise对象。返回true表示已使能指定的约束；返回false表示未使能指定的约束。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 201 | Permission denied.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid localId or constraint.    |
| 12300003 | Account not found. |

**示例：** 判断ID为100的系统账号是否有禁止使用Wi-Fi的约束

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let localId: number = 100;
  let constraint: string = 'constraint.wifi';
  try {
    accountManager.checkOsAccountConstraintEnabled(localId, constraint).then((isEnabled: boolean) => {
      console.log('checkOsAccountConstraintEnabled successfully, isEnabled: ' + isEnabled);
    }).catch((err: BusinessError) => {
      console.log('checkOsAccountConstraintEnabled failed, error: ' + JSON.stringify(err));
    });
  } catch (err) {
    console.log('checkOsAccountConstraintEnabled exception: ' + JSON.stringify(err));
  }
  ```

### checkOsAccountTestable<sup>9+</sup>

checkOsAccountTestable(callback: AsyncCallback&lt;boolean&gt;): void

检查当前系统账号是否为测试账号。使用callback异步回调。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                         | 必填 | 说明                                                                   |
| -------- | ---------------------------- | ---- | --------------------------------------------------------------------- |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调函数。返回true表示当前账号为测试账号；返回false表示当前账号非测试账号。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  try {
    accountManager.checkOsAccountTestable((err: BusinessError, isTestable: boolean) => {
      if (err) {
        console.log('checkOsAccountTestable failed, error: ' + JSON.stringify(err));
      } else {
        console.log('checkOsAccountTestable successfully, isTestable: ' + isTestable);
      }
    });
  } catch (err) {
    console.log('checkOsAccountTestable error: ' + JSON.stringify(err));
  }
  ```

### checkOsAccountTestable<sup>9+</sup>

checkOsAccountTestable(): Promise&lt;boolean&gt;

检查当前系统账号是否为测试账号。使用Promise异步回调。

**系统能力：** SystemCapability.Account.OsAccount

**返回值：**

| 类型                   | 说明                                                                      |
| ---------------------- | ------------------------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise对象。返回true表示当前账号为测试账号；返回false表示当前账号非测试账号。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 12300001 | The system service works abnormally. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  try {
    accountManager.checkOsAccountTestable().then((isTestable: boolean) => {
      console.log('checkOsAccountTestable successfully, isTestable: ' + isTestable);
    }).catch((err: BusinessError) => {
      console.log('checkOsAccountTestable failed, error: ' + JSON.stringify(err));
    });
  } catch (err) {
    console.log('checkOsAccountTestable exception: ' + JSON.stringify(err));
  }
  ```
  
### isOsAccountUnlocked<sup>11+</sup>

isOsAccountUnlocked(): Promise&lt;boolean&gt;

检查当前系统账号是否已认证解锁。使用Promise异步回调。

**系统能力：** SystemCapability.Account.OsAccount

**返回值：**

| 类型                   | 说明                                                                      |
| ---------------------- | ------------------------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise对象。返回true表示当前账号已认证解锁；返回false表示当前账号未认证解锁。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 12300001 | The system service works abnormally. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  try {
    accountManager.isOsAccountUnlocked().then((isVerified: boolean) => {
      console.log('isOsAccountUnlocked successfully, isVerified: ' + isVerified);
    }).catch((err: BusinessError) => {
      console.log('isOsAccountUnlocked failed, error: ' + JSON.stringify(err));
    });
  } catch (err) {
    console.log('isOsAccountUnlocked exception: ' + JSON.stringify(err));
  }
  ```

### checkOsAccountVerified<sup>(deprecated)</sup>

checkOsAccountVerified(callback: AsyncCallback&lt;boolean&gt;): void

检查当前系统账号是否已认证解锁。使用callback异步回调。

> **说明：**
>
> 从 API version 9开始支持，从API version 11开始废弃。建议使用[isOsAccountUnlocked](#isosaccountunlocked11)替代。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                         | 必填 | 说明                                                            |
| -------- | ---------------------------- | ---- | ------------------------------------------------------------- |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调函数。返回true表示当前账号已认证解锁；返回false表示当前账号未认证解锁。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 12300001 | The system service works abnormally. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  try {
    accountManager.checkOsAccountVerified((err: BusinessError, isVerified: boolean) => {
      if (err) {
        console.log('checkOsAccountVerified failed, error: ' + JSON.stringify(err));
      } else {
        console.log('checkOsAccountVerified successfully, isVerified: ' + isVerified);
      }
    });
  } catch (err) {
    console.log('checkOsAccountVerified exception: ' + JSON.stringify(err));
  }
  ```

### checkOsAccountVerified<sup>(deprecated)</sup>

checkOsAccountVerified(): Promise&lt;boolean&gt;

检查当前系统账号是否已认证解锁。使用Promise异步回调。

> **说明：**
>
> 从 API version 9开始支持，从API version 11开始废弃。建议使用[isOsAccountUnlocked](#isosaccountunlocked11)替代。

**系统能力：** SystemCapability.Account.OsAccount

**返回值：**

| 类型                   | 说明                                                                      |
| ---------------------- | ------------------------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise对象。返回true表示当前账号已认证解锁；返回false表示当前账号未认证解锁。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 12300001 | The system service works abnormally. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  try {
    accountManager.checkOsAccountVerified().then((isVerified: boolean) => {
      console.log('checkOsAccountVerified successfully, isVerified: ' + isVerified);
    }).catch((err: BusinessError) => {
      console.log('checkOsAccountVerified failed, error: ' + JSON.stringify(err));
    });
  } catch (err) {
    console.log('checkOsAccountVerified exception: ' + JSON.stringify(err));
  }
  ```

### checkOsAccountVerified<sup>(deprecated)</sup>

checkOsAccountVerified(localId: number, callback: AsyncCallback&lt;boolean&gt;): void

检查指定系统账号是否已验证。使用callback异步回调。

> **说明：**
>
> 从 API version 9开始支持，从API version 11开始废弃。替代方法仅向系统应用开放。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS 或 ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS，以上权限仅系统应用可申请。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                         | 必填 | 说明                                                            |
| -------- | ---------------------------- | ---- | ------------------------------------------------------------- |
| localId  | number                       | 是   | 系统账号ID。                              |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调函数。返回true表示当前账号已认证解锁；返回false表示当前账号未认证解锁。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 201 | Permission denied.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid localId.    |
| 12300003 | Account not found. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let localId: number = 100;
  try {
    accountManager.checkOsAccountVerified(localId, (err: BusinessError, isVerified: boolean) => {
      if (err) {
        console.log('checkOsAccountVerified failed, error: ' + JSON.stringify(err));
      } else {
        console.log('checkOsAccountVerified successfully, isVerified: ' + isVerified);
      }
    });
  } catch (err) {
    console.log('checkOsAccountVerified exception: ' + err);
  }
  ```

### checkOsAccountVerified<sup>(deprecated)</sup>

checkOsAccountVerified(localId: number): Promise&lt;boolean&gt;

检查指定系统账号是否已验证。使用Promise异步回调。

> **说明：**
>
> 从 API version 9开始支持，从API version 11开始废弃。替代方法仅向系统应用开放。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS 或 ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS，以上权限仅系统应用可申请。

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
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid localId.    |
| 12300003 | Account not found. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let localId: number = 100;
  try {
    accountManager.checkOsAccountVerified(localId).then((isVerified: boolean) => {
      console.log('checkOsAccountVerified successfully, isVerified: ' + isVerified);
    }).catch((err: BusinessError) => {
      console.log('checkOsAccountVerified failed, error: ' + JSON.stringify(err));
    });
  } catch (err) {
    console.log('checkOsAccountVerified exception: ' + JSON.stringify(err));
  }
  ```

### getOsAccountCount<sup>9+</sup>

getOsAccountCount(callback: AsyncCallback&lt;number&gt;): void

获取已创建的系统账号数量。使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS，以上权限仅系统应用可申请。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                                                         |
| -------- | --------------------------- | ---- | -------------------------------------------------------------------------- |
| callback | AsyncCallback&lt;number&gt; | 是   | 回调函数。当获取成功时，err为null，data为已创建的系统账号的数量；否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 201 | Permission denied.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 12300001 | The system service works abnormally. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  try {
    accountManager.getOsAccountCount((err: BusinessError, count: number) => {
      if (err) {
        console.log('getOsAccountCount failed, error: ' + JSON.stringify(err));
      } else {
        console.log('getOsAccountCount successfully, count: ' + count);
      }
    });
  } catch (err) {
    console.log('getOsAccountCount exception: ' + JSON.stringify(err));
  }
  ```

### getOsAccountCount<sup>9+</sup>

getOsAccountCount(): Promise&lt;number&gt;

获取已创建的系统账号数量。使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS，以上权限仅系统应用可申请。

**系统能力：** SystemCapability.Account.OsAccount

**返回值：**

| 类型                  | 说明                                    |
| --------------------- | -------------------------------------- |
| Promise&lt;number&gt; | Promise对象，返回已创建的系统账号的数量。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 201 | Permission denied.|
| 12300001 | The system service works abnormally. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  try {
    accountManager.getOsAccountCount().then((count: number) => {
      console.log('getOsAccountCount successfully, count: ' + count);
    }).catch((err: BusinessError) => {
      console.log('getOsAccountCount failed, error: ' + JSON.stringify(err));
    });
  } catch(err) {
    console.log('getOsAccountCount exception: ' + JSON.stringify(err));
  }
  ```

### getOsAccountLocalId<sup>9+</sup>

getOsAccountLocalId(callback: AsyncCallback&lt;number&gt;): void

获取当前进程所属的系统账号ID，使用callback异步回调。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                                                           |
| -------- | --------------------------- | ---- | ---------------------------------------------------------------------------- |
| callback | AsyncCallback&lt;number&gt; | 是   | 回调函数。当获取成功时，err为null，data为当前进程所属的系统账号ID；否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 12300001 | The system service works abnormally. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  try {
    accountManager.getOsAccountLocalId((err: BusinessError, localId: number) => {
      if (err) {
        console.log('getOsAccountLocalId failed, error: ' + JSON.stringify(err));
      } else {
        console.log('getOsAccountLocalId successfully, localId: ' + localId);
      }
    });
  } catch (err) {
    console.log('getOsAccountLocalId exception: ' + JSON.stringify(err));
  }
  ```

### getOsAccountLocalId<sup>9+</sup>

getOsAccountLocalId(): Promise&lt;number&gt;

获取当前进程所属的系统账号ID，使用Promise异步回调。

**系统能力：** SystemCapability.Account.OsAccount

**返回值：**

| 类型                  | 说明                                      |
| --------------------- | ---------------------------------------- |
| Promise&lt;number&gt; | Promise对象，返回当前进程所属的系统账号ID。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 12300001 | The system service works abnormally. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  try {
    accountManager.getOsAccountLocalId().then((localId: number) => {
      console.log('getOsAccountLocalId successfully, localId: ' + localId);
    }).catch((err: BusinessError) => {
      console.log('getOsAccountLocalId failed, error: ' + JSON.stringify(err));
    });
  } catch (err) {
    console.log('getOsAccountLocalId exception: ' + JSON.stringify(err));
  }
  ```

### getOsAccountLocalIdForUid<sup>9+</sup>

getOsAccountLocalIdForUid(uid: number, callback: AsyncCallback&lt;number&gt;): void

根据uid查询对应的系统账号ID，使用callback异步回调。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                                                    |
| -------- | --------------------------- | ---- | --------------------------------------------------------------------- |
| uid      | number                      | 是   | 进程uid。                                                              |
| callback | AsyncCallback&lt;number&gt; | 是   | 回调函数。如果查询成功，err为null，data为对应的系统账号ID；否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息         |
| -------- | --------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid uid.    |

**示例：** 查询值为12345678的uid所属的系统账号的账号ID

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let uid: number = 12345678;
  try {
    accountManager.getOsAccountLocalIdForUid(uid, (err: BusinessError, localId: number) => {
      if (err) {
        console.log('getOsAccountLocalIdForUid failed, error: ' + JSON.stringify(err));
      }
      console.log('getOsAccountLocalIdForUid successfully, localId: ' + localId);
    });
  } catch (err) {
    console.log('getOsAccountLocalIdForUid exception: ' + JSON.stringify(err));
  }
  ```

### getOsAccountLocalIdForUid<sup>9+</sup>

getOsAccountLocalIdForUid(uid: number): Promise&lt;number&gt;

根据uid查询对应的系统账号ID，使用Promise异步回调。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名 | 类型   | 必填 | 说明      |
| ------ | ------ | ---- | --------- |
| uid    | number | 是   | 进程uid。 |

**返回值：**

| 类型                  | 说明                                     |
| --------------------- | --------------------------------------- |
| Promise&lt;number&gt; | Promise对象，返回指定uid对应的系统账号ID。 |

**错误码：**

| 错误码ID | 错误信息       |
| -------- | ------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid uid. |

**示例：** 查询值为12345678的uid所属的系统账号ID

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let uid: number = 12345678;
  try {
    accountManager.getOsAccountLocalIdForUid(uid).then((localId: number) => {
      console.log('getOsAccountLocalIdForUid successfully, localId: ' + localId);
    }).catch((err: BusinessError) => {
      console.log('getOsAccountLocalIdForUid failed, error: ' + JSON.stringify(err));
    });
  } catch (err) {
    console.log('getOsAccountLocalIdForUid exception: ' + JSON.stringify(err));
  }
  ```

### getOsAccountLocalIdForUidSync<sup>10+</sup>

getOsAccountLocalIdForUidSync(uid: number): number

根据uid查询对应的系统账号ID。使用同步方式返回结果。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名 | 类型   | 必填 | 说明      |
| ------ | ------ | ---- | --------- |
| uid    | number | 是   | 进程uid。 |

**返回值：**

| 类型                  | 说明                                     |
| --------------------- | --------------------------------------- |
| number | 返回指定uid对应的系统账号ID。 |

**错误码：**

| 错误码ID | 错误信息       |
| -------- | ------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 12300002 | Invalid uid. |

**示例：** 查询值为12345678的uid所属的系统账号ID

  ```ts
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let uid: number = 12345678;
  try {
    let localId : number = accountManager.getOsAccountLocalIdForUidSync(uid);
    console.log('getOsAccountLocalIdForUidSync successfully, localId: ' + localId);
  } catch (err) {
    console.log('getOsAccountLocalIdForUidSync exception: ' + JSON.stringify(err));
  }
  ```

### getOsAccountLocalIdForDomain<sup>9+</sup>

getOsAccountLocalIdForDomain(domainInfo: DomainAccountInfo, callback: AsyncCallback&lt;number&gt;): void

根据域账号信息，获取与其关联的系统账号ID。使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS，以上权限仅系统应用可申请。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名     | 类型                                    | 必填 | 说明                                                                         |
| ---------- | --------------------------------------- | ---- | -------------------------------------------------------------------------- |
| domainInfo | [DomainAccountInfo](#domainaccountinfo8) | 是   | 域账号信息。                                                                |
| callback   | AsyncCallback&lt;number&gt;             | 是   | 回调函数。如果查询成功，err为null，data为域账号关联的系统账号ID；否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息       |
| -------- | ------------- |
| 201 | Permission denied.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid domainInfo. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let domainInfo: osAccount.DomainAccountInfo = {domain: 'testDomain', accountName: 'testAccountName'};
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  try {
    accountManager.getOsAccountLocalIdForDomain(domainInfo, (err: BusinessError, localId: number) => {
      if (err) {
        console.log('getOsAccountLocalIdForDomain failed, error: ' + JSON.stringify(err));
      } else {
        console.log('getOsAccountLocalIdForDomain successfully, localId: ' + localId);
      }
    });
  } catch (err) {
    console.log('getOsAccountLocalIdForDomain exception: ' + JSON.stringify(err));
  }
  ```

### getOsAccountLocalIdForDomain<sup>9+</sup>

getOsAccountLocalIdForDomain(domainInfo: DomainAccountInfo): Promise&lt;number&gt;

根据域账号信息，获取与其关联的系统账号的账号ID。使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS，以上权限仅系统应用可申请。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名     | 类型                                    | 必填 | 说明         |
| ---------- | --------------------------------------- | ---- | ------------ |
| domainInfo | [DomainAccountInfo](#domainaccountinfo8) | 是   | 域账号信息。 |

**返回值：**

| 类型                  | 说明                                    |
| :-------------------- | :------------------------------------- |
| Promise&lt;number&gt; | Promise对象，返回域账号关联的系统账号ID。 |

**错误码：**

| 错误码ID | 错误信息       |
| -------- | ------------- |
| 201 | Permission denied.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid domainInfo. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let domainInfo: osAccount.DomainAccountInfo = {domain: 'testDomain', accountName: 'testAccountName'};
  try {
    accountManager.getOsAccountLocalIdForDomain(domainInfo).then((localId: number) => {
      console.log('getOsAccountLocalIdForDomain successfully, localId: ' + localId);
    }).catch((err: BusinessError) => {
      console.log('getOsAccountLocalIdForDomain failed, error: ' + JSON.stringify(err));
    });
  } catch (err) {
    console.log('getOsAccountLocalIdForDomain exception: ' + JSON.stringify(err));
  }
  ```

### getOsAccountConstraints<sup>(deprecated)</sup>

getOsAccountConstraints(localId: number, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

获取指定系统账号的全部约束。使用callback异步回调。

> **说明：**
>
> 从 API version 9开始支持，从API version 11开始废弃。替代方法仅向系统应用开放。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS，以上权限仅系统应用可申请。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                                     | 必填 | 说明                                                                                           |
| -------- | ---------------------------------------- | ---- | -------------------------------------------------------------------------------------------- |
| localId  | number                                   | 是   | 系统账号ID。                                                                                  |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt; | 是   | 回调函数，如果获取成功，err为null，data为该系统账号的全部[约束](#系统账号约束列表)；否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 201 | Permission denied.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid localId.    |
| 12300003 | Account not found. |

**示例：** 获取ID为100的系统账号的全部约束

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let localId: number = 100;
  try {
    accountManager.getOsAccountConstraints(localId, (err: BusinessError, constraints: string[]) => {
      if (err) {
        console.log('getOsAccountConstraints failed, err: ' + JSON.stringify(err));
      } else {
        console.log('getOsAccountConstraints successfully, constraints: ' + JSON.stringify(constraints));
      }
    });
  } catch (err) {
    console.log('getOsAccountConstraints exception: ' + JSON.stringify(err));
  }
  ```

### getOsAccountConstraints<sup>(deprecated)</sup>

getOsAccountConstraints(localId: number): Promise&lt;Array&lt;string&gt;&gt;

获取指定系统账号的全部约束。使用Promise异步回调。

> **说明：**
>
> 从 API version 9开始支持，从API version 11开始废弃。替代方法仅向系统应用开放。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS，以上权限仅系统应用可申请。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名  | 类型   | 必填 | 说明         |
| ------- | ------ | ---- | ------------ |
| localId | number | 是   | 系统账号ID。 |

**返回值：**

| 类型                               | 说明                                                       |
| ---------------------------------- | ---------------------------------------------------------- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise对象，返回指定系统账号的全部[约束](#系统账号约束列表)。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 201 | Permission denied.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid localId.    |
| 12300003 | Account not found. |

**示例：** 获取ID为100的系统账号的全部约束

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let localId: number = 100;
  try {
    accountManager.getOsAccountConstraints(localId).then((constraints: string[]) => {
      console.log('getOsAccountConstraints, constraints: ' + constraints);
    }).catch((err: BusinessError) => {
      console.log('getOsAccountConstraints err: ' + JSON.stringify(err));
    });
  } catch (e) {
    console.log('getOsAccountConstraints exception: ' + JSON.stringify(e));
  }
  ```

### getActivatedOsAccountLocalIds<sup>9+</sup>

getActivatedOsAccountLocalIds(callback: AsyncCallback&lt;Array&lt;number&gt;&gt;): void

查询当前处于激活状态的系统账号的ID列表。使用callback异步回调。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                                     | 必填 | 说明                                                   |
| -------- | ---------------------------------------- | ---- | ------------------------------------------------------ |
| callback | AsyncCallback&lt;Array&lt;number&gt;&gt; | 是   | 回调函数。如果查询成功，err为null，data为当前处于激活状态的系统账号的ID列表；否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息       |
| -------- | ------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 12300001 | The system service works abnormally. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  try {
    accountManager.getActivatedOsAccountLocalIds((err: BusinessError, idArray: number[])=>{
      console.log('getActivatedOsAccountLocalIds err:' + JSON.stringify(err));
      console.log('getActivatedOsAccountLocalIds idArray length:' + idArray.length);
      for(let i=0;i<idArray.length;i++) {
        console.info('activated os account id: ' + idArray[i]);
      }
    });
  } catch (e) {
    console.log('getActivatedOsAccountLocalIds exception: ' + JSON.stringify(e));
  }
  ```

### getActivatedOsAccountLocalIds<sup>9+</sup>

getActivatedOsAccountLocalIds(): Promise&lt;Array&lt;number&gt;&gt;

查询当前处于激活状态的系统账号的ID列表。使用Promise异步回调。

**系统能力：** SystemCapability.Account.OsAccount

**返回值：**

| 类型                               | 说明                                               |
| :--------------------------------- | :------------------------------------------------ |
| Promise&lt;Array&lt;number&gt;&gt; | Promise对象，返回当前处于激活状态的系统账号的ID列表。 |

**错误码：**

| 错误码ID | 错误信息       |
| -------- | ------------- |
| 12300001 | The system service works abnormally. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  try {
    accountManager.getActivatedOsAccountLocalIds().then((idArray: number[]) => {
      console.log('getActivatedOsAccountLocalIds, idArray: ' + idArray);
    }).catch((err: BusinessError) => {
      console.log('getActivatedOsAccountLocalIds err: ' + JSON.stringify(err));
    });
  } catch (e) {
    console.log('getActivatedOsAccountLocalIds exception: ' + JSON.stringify(e));
  }
  ```

### getCurrentOsAccount<sup>(deprecated)</sup>

getCurrentOsAccount(callback: AsyncCallback&lt;OsAccountInfo&gt;): void

查询当前进程所属的系统账号的信息。使用callback异步回调。

> **说明：**
>
> 从 API version 9开始支持，从API version 11开始废弃。替代方法仅向系统应用开放。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS 或 ohos.permission.GET_LOCAL_ACCOUNTS<sup>10+</sup>，以上权限仅系统应用可申请。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                                           |
| -------- | ---------------------------------------------------- | ---- | ---------------------------------------------- |
| callback | AsyncCallback&lt;[OsAccountInfo](#osaccountinfo)&gt; | 是   | 回调函数。如果查询成功，err为null，data为当前进程所属的系统账号信息；否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 201 | Permission denied.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  try {
    accountManager.getCurrentOsAccount((err: BusinessError, curAccountInfo: osAccount.OsAccountInfo)=>{
      console.log('getCurrentOsAccount err:' + JSON.stringify(err));
      console.log('getCurrentOsAccount curAccountInfo:' + JSON.stringify(curAccountInfo));
    });
  } catch (e) {
    console.log('getCurrentOsAccount exception: ' + JSON.stringify(e));
  }
  ```

### getCurrentOsAccount<sup>(deprecated)</sup>

getCurrentOsAccount(): Promise&lt;OsAccountInfo&gt;

查询当前进程所属的系统账号的信息。使用Promise异步回调。

> **说明：**
>
> 从 API version 9开始支持，从API version 11开始废弃。替代方法仅向系统应用开放。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS 或 ohos.permission.GET_LOCAL_ACCOUNTS<sup>10+</sup>，以上权限仅系统应用可申请。

**系统能力：** SystemCapability.Account.OsAccount

**返回值：**

| 类型                                           | 说明                                       |
| ---------------------------------------------- | ----------------------------------------- |
| Promise&lt;[OsAccountInfo](#osaccountinfo)&gt; | Promise对象，返回当前进程所属的系统账号信息。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 201 | Permission denied.|
| 12300001 | The system service works abnormally. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  try {
    accountManager.getCurrentOsAccount().then((accountInfo: osAccount.OsAccountInfo) => {
      console.log('getCurrentOsAccount, accountInfo: ' + JSON.stringify(accountInfo));
    }).catch((err: BusinessError) => {
      console.log('getCurrentOsAccount err: ' + JSON.stringify(err));
    });
  } catch (e) {
    console.log('getCurrentOsAccount exception: ' + JSON.stringify(e));
  }
  ```

### getOsAccountType<sup>9+</sup>

getOsAccountType(callback: AsyncCallback&lt;OsAccountType&gt;): void

查询当前进程所属的系统账号的账号类型。使用callback异步回调。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                                                 |
| -------- | ---------------------------------------------------- | ---- | ---------------------------------------------------- |
| callback | AsyncCallback&lt;[OsAccountType](#osaccounttype)&gt; | 是   | 回调函数。如果查询成功，err为null，data为当前进程所属的系统账号的账号类型；否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  try {
    accountManager.getOsAccountType((err: BusinessError, accountType: osAccount.OsAccountType) => {
      console.log('getOsAccountType err: ' + JSON.stringify(err));
      console.log('getOsAccountType accountType: ' + accountType);
    });
  } catch (e) {
    console.log('getOsAccountType exception: ' + JSON.stringify(e));
  }
  ```

### getOsAccountType<sup>9+</sup>

getOsAccountType(): Promise&lt;OsAccountType&gt;

查询当前进程所属的系统账号的账号类型。使用Promise异步回调。

**系统能力：** SystemCapability.Account.OsAccount

**返回值：**

| 类型                                           | 说明                                             |
| ---------------------------------------------- | ----------------------------------------------- |
| Promise&lt;[OsAccountType](#osaccounttype)&gt; | Promise对象，返回当前进程所属的系统账号的账号类型。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 12300001 | The system service works abnormally. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  try {
    accountManager.getOsAccountType().then((accountType: osAccount.OsAccountType) => {
      console.log('getOsAccountType, accountType: ' + accountType);
    }).catch((err: BusinessError) => {
      console.log('getOsAccountType err: ' + JSON.stringify(err));
    });
  } catch (e) {
    console.log('getOsAccountType exception: ' + JSON.stringify(e));
  }
  ```

### queryDistributedVirtualDeviceId<sup>9+</sup>

queryDistributedVirtualDeviceId(callback: AsyncCallback&lt;string&gt;): void

获取分布式虚拟设备ID。使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS（仅系统应用可申请）或 ohos.permission.DISTRIBUTED_DATASYNC

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                                                   |
| -------- | --------------------------- | ---- | --------------------------------------------------------------------- |
| callback | AsyncCallback&lt;string&gt; | 是   | 回调函数。如果获取成功，err为null，data为分布式虚拟设备ID；否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 201 | Permission denied.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  try {
    accountManager.queryDistributedVirtualDeviceId((err: BusinessError, virtualID: string) => {
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

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS（仅系统应用可申请）或 ohos.permission.DISTRIBUTED_DATASYNC

**系统能力：** SystemCapability.Account.OsAccount

**返回值：**

| 类型                  | 说明                              |
| --------------------- | --------------------------------- |
| Promise&lt;string&gt; | Promise对象，返回分布式虚拟设备ID。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 201 | Permission denied.|
| 12300001 | The system service works abnormally. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  try {
    accountManager.queryDistributedVirtualDeviceId().then((virtualID: string) => {
      console.log('queryDistributedVirtualDeviceId, virtualID: ' + virtualID);
    }).catch((err: BusinessError) => {
      console.log('queryDistributedVirtualDeviceId err: ' + JSON.stringify(err));
    });
  } catch (e) {
    console.log('queryDistributedVirtualDeviceId exception: ' + JSON.stringify(e));
  }
  ```

### getOsAccountLocalIdForSerialNumber<sup>9+</sup>

getOsAccountLocalIdForSerialNumber(serialNumber: number, callback: AsyncCallback&lt;number&gt;): void

通过SN码查询与其关联的系统账号的账号ID。使用callback异步回调。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名       | 类型                        | 必填 | 说明                                                                           |
| ------------ | --------------------------- | ---- | ---------------------------------------------------------------------------- |
| serialNumber | number                      | 是   | 账号SN码。                                                                    |
| callback     | AsyncCallback&lt;number&gt; | 是   | 回调函数。如果成功，err为null，data为与SN码关联的系统账号的账号ID；否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息               |
| -------- | ------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid serialNumber. |
| 12300003 | The account indicated by serialNumber dose not exist. |

**示例：** 查询与SN码12345关联的系统账号的ID

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let serialNumber: number = 12345;
  try {
    accountManager.getOsAccountLocalIdForSerialNumber(serialNumber, (err: BusinessError, localId: number)=>{
      console.log('ger localId err:' + JSON.stringify(err));
      console.log('get localId:' + localId + ' by serialNumber: ' + serialNumber);
    });
  } catch (e) {
    console.log('ger localId exception: ' + JSON.stringify(e));
  }
  ```

### getOsAccountLocalIdForSerialNumber<sup>9+</sup>

getOsAccountLocalIdForSerialNumber(serialNumber: number): Promise&lt;number&gt;

通过SN码查询与其关联的系统账号的账号ID。使用Promise异步回调。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名       | 类型   | 必填 | 说明       |
| ------------ | ------ | ---- | ---------- |
| serialNumber | number | 是   | 账号SN码。 |

**返回值：**

| 类型                  | 说明                                         |
| --------------------- | -------------------------------------------- |
| Promise&lt;number&gt; | Promise对象，返回与SN码关联的系统账号的账号ID。 |

**错误码：**

| 错误码ID | 错误信息               |
| -------- | ------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid serialNumber. |
| 12300003 | The account indicated by serialNumber dose not exist. |

**示例：** 查询与SN码12345关联的系统账号的ID

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let serialNumber: number = 12345;
  try {
    accountManager.getOsAccountLocalIdForSerialNumber(serialNumber).then((localId: number) => {
      console.log('getOsAccountLocalIdForSerialNumber localId: ' + localId);
    }).catch((err: BusinessError) => {
      console.log('getOsAccountLocalIdForSerialNumber err: ' + JSON.stringify(err));
    });
  } catch (e) {
    console.log('getOsAccountLocalIdForSerialNumber exception: ' + JSON.stringify(e));
  }
  ```

### getSerialNumberForOsAccountLocalId<sup>9+</sup>

getSerialNumberForOsAccountLocalId(localId: number, callback: AsyncCallback&lt;number&gt;): void

通过系统账号ID获取与该系统账号关联的SN码。使用callback异步回调。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                                                         |
| -------- | --------------------------- | ---- | -------------------------------------------------------------------------- |
| localId  | number                      | 是   | 系统账号ID。                                                                 |
| callback | AsyncCallback&lt;number&gt; | 是   | 回调函数。如果获取成功，err为null，data为与该系统账号关联的SN码；否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid localId.    |
| 12300003 | Account not found. |

**示例：** 获取ID为100的系统账号关联的SN码

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let localId: number = 100;
  try {
    accountManager.getSerialNumberForOsAccountLocalId(localId, (err: BusinessError, serialNumber: number)=>{
      console.log('ger serialNumber err:' + JSON.stringify(err));
      console.log('get serialNumber:' + serialNumber + ' by localId: ' + localId);
    });
  } catch (e) {
    console.log('ger serialNumber exception: ' + JSON.stringify(e));
  }
  ```

### getSerialNumberForOsAccountLocalId<sup>9+</sup>

getSerialNumberForOsAccountLocalId(localId: number): Promise&lt;number&gt;

通过系统账号ID获取与该系统账号关联的SN码。使用Promise异步回调。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名  | 类型   | 必填 | 说明          |
| ------- | ------ | ---- | ----------- |
| localId | number | 是   | 系统账号ID。 |

**返回值：**

| 类型                  | 说明                                    |
| :-------------------- | :------------------------------------- |
| Promise&lt;number&gt; | Promise对象，返回与该系统账号关联的SN码。 |

**错误码：**

| 错误码ID | 错误信息             |
| -------- | ------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid localId.    |
| 12300003 | Account not found. |

**示例：** 获取ID为100的系统账号关联的SN码

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let localId: number = 100;
  try {
    accountManager.getSerialNumberForOsAccountLocalId(localId).then((serialNumber: number) => {
      console.log('getSerialNumberForOsAccountLocalId serialNumber: ' + serialNumber);
    }).catch((err: BusinessError) => {
      console.log('getSerialNumberForOsAccountLocalId err: ' + JSON.stringify(err));
    });
  } catch (e) {
    console.log('getSerialNumberForOsAccountLocalId exception: ' + JSON.stringify(e));
  }
  ```

### isMultiOsAccountEnable<sup>(deprecated)</sup>

isMultiOsAccountEnable(callback: AsyncCallback&lt;boolean&gt;): void

判断是否支持多系统账号。使用callback异步回调。

> **说明：**
>
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[checkMultiOsAccountEnabled](#checkmultiosaccountenabled9)。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                         | 必填 | 说明                                                     |
| -------- | ---------------------------- | ---- | ------------------------------------------------------ |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调函数。返回true表示支持多系统账号；返回false表示不支持。 |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  accountManager.isMultiOsAccountEnable((err: BusinessError, isEnabled: boolean) => {
    if (err) {
      console.log('isMultiOsAccountEnable failed, error: ' + JSON.stringify(err));
    } else {
    console.log('isMultiOsAccountEnable successfully, isEnabled: ' + isEnabled);
    }
  });
  ```

### isMultiOsAccountEnable<sup>(deprecated)</sup>

isMultiOsAccountEnable(): Promise&lt;boolean&gt;

判断是否支持多系统账号。使用Promise异步回调。

> **说明：**
>
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[checkMultiOsAccountEnabled](#checkmultiosaccountenabled9-1)。

**系统能力：** SystemCapability.Account.OsAccount

**返回值：**

| 类型                   | 说明                                                       |
| :--------------------- | :--------------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise对象。返回true表示支持多系统账号；返回false表示不支持。 |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  accountManager.isMultiOsAccountEnable().then((isEnabled: boolean) => {
    console.log('isMultiOsAccountEnable successfully, isEnabled: ' + isEnabled);
  }).catch((err: BusinessError) => {
    console.log('isMultiOsAccountEnable failed, error: ' + JSON.stringify(err));
  });
  ```

### isOsAccountActived<sup>(deprecated)</sup>

isOsAccountActived(localId: number, callback: AsyncCallback&lt;boolean&gt;): void

判断指定系统账号是否处于激活状态。使用callback异步回调。

> **说明：**
>
> 从 API version 7开始支持从API version 9开始废弃。替代方法仅向系统应用开放。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS 或 ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS，以上权限仅系统应用可申请。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                         | 必填 | 说明                                                     |
| -------- | ---------------------------- | ---- | ------------------------------------------------------ |
| localId  | number                       | 是   | 系统账号ID。                                            |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调函数。返回true表示账号已激活；返回false表示账号未激活。 |

**示例：** 判断ID为100的系统账号是否处于激活状态

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let localId: number = 100;
  accountManager.isOsAccountActived(localId, (err: BusinessError, isActived: boolean) => {
    if (err) {
      console.log('isOsAccountActived failed, err:' + JSON.stringify(err));
    } else {
      console.log('isOsAccountActived successfully, isActived:' + isActived);
    }
  });
  ```

### isOsAccountActived<sup>(deprecated)</sup>

isOsAccountActived(localId: number): Promise&lt;boolean&gt;

判断指定系统账号是否处于激活状态。使用Promise异步回调。

> **说明：**
>
> 从 API version 7开始支持从API version 9开始废弃。替代方法仅向系统应用开放。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS 或 ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS，以上权限仅系统应用可申请。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名  | 类型   | 必填 | 说明                               |
| ------- | ------ | ---- | --------------------------------- |
| localId | number | 是   | 系统账号ID。 |

**返回值：**

| 类型                   | 说明                                                        |
| --------------------- | ----------------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise对象。返回true表示账号已激活；返回false表示账号未激活。 |

**示例：** 判断ID为100的系统账号是否处于激活状态

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let localId: number = 100;
  accountManager.isOsAccountActived(localId).then((isActived: boolean) => {
    console.log('isOsAccountActived successfully, isActived: ' + isActived);
  }).catch((err: BusinessError) => {
    console.log('isOsAccountActived failed, error: ' + JSON.stringify(err));
  });
  ```

### isOsAccountConstraintEnable<sup>(deprecated)</sup>

isOsAccountConstraintEnable(localId: number, constraint: string, callback: AsyncCallback&lt;boolean&gt;): void

判断指定系统账号是否具有指定约束。使用callback异步回调。

> **说明：**
>
> 从 API version 7开始支持，从API version 9开始废弃。替代方法仅向系统应用开放。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS，该权限仅系统应用可申请。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名     | 类型                         | 必填 | 说明                                                                |
| ---------- | ---------------------------- | ---- | ----------------------------------------------------------------- |
| localId    | number                       | 是   | 系统账号ID。                                 |
| constraint | string                       | 是   | 指定的[约束](#系统账号约束列表)名称。                                |
| callback   | AsyncCallback&lt;boolean&gt; | 是   | 回调函数。返回true表示已使能指定的约束；返回false表示未使能指定的约束。 |

**示例：** 判断ID为100的系统账号是否有禁止使用Wi-Fi的约束

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let localId: number = 100;
  let constraint: string = 'constraint.wifi';
  accountManager.isOsAccountConstraintEnable(localId, constraint, (err: BusinessError, isEnabled: boolean) => {
    if (err) {
      console.log('isOsAccountConstraintEnable failed, error: ' + JSON.stringify(err));
    } else {
      console.log('isOsAccountConstraintEnable successfully, isEnabled: ' + isEnabled);
    }
  });
  ```

### isOsAccountConstraintEnable<sup>(deprecated)</sup>

isOsAccountConstraintEnable(localId: number, constraint: string): Promise&lt;boolean&gt;

判断指定系统账号是否具有指定约束。使用Promise异步回调。

> **说明：**
>
> 从 API version 7开始支持，从API version 9开始废弃。替代方法仅向系统应用开放。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS，该权限仅系统应用可申请。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名     | 类型   | 必填 | 说明                                 |
| ---------- | ------ | ---- | ---------------------------------- |
| localId    | number | 是   | 系统账号ID。  |
| constraint | string | 是   | 指定的[约束](#系统账号约束列表)名称。 |

**返回值：**

| 类型                   | 说明                                                                   |
| ---------------------- | --------------------------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise对象。返回true表示已使能指定的约束；返回false表示未使能指定的约束。 |

**示例：** 判断ID为100的系统账号是否有禁止使用Wi-Fi的约束

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let localId: number = 100;
  let constraint: string = 'constraint.wifi';
  accountManager.isOsAccountConstraintEnable(localId, constraint).then((isEnabled: boolean) => {
    console.log('isOsAccountConstraintEnable successfully, isEnabled: ' + isEnabled);
  }).catch((err: BusinessError) => {
    console.log('isOsAccountConstraintEnable err: ' + JSON.stringify(err));
  });
  ```

### isTestOsAccount<sup>(deprecated)</sup>

isTestOsAccount(callback: AsyncCallback&lt;boolean&gt;): void

检查当前系统账号是否为测试账号。使用callback异步回调。

> **说明：**
>
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[checkOsAccountTestable](#checkosaccounttestable9)。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                         | 必填 | 说明                                                                   |
| -------- | ---------------------------- | ---- | --------------------------------------------------------------------- |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调函数。返回true表示当前账号为测试账号；返回false表示当前账号非测试账号。 |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  accountManager.isTestOsAccount((err: BusinessError, isTestable: boolean) => {
    if (err) {
      console.log('isTestOsAccount failed, error: ' + JSON.stringify(err));
    } else {
      console.log('isTestOsAccount successfully, isTestable: ' + isTestable);
    }
  });
  ```

### isTestOsAccount<sup>(deprecated)</sup>

isTestOsAccount(): Promise&lt;boolean&gt;

检查当前系统账号是否为测试账号。使用Promise异步回调。

> **说明：**
>
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[checkOsAccountTestable](#checkosaccounttestable9-1)。

**系统能力：** SystemCapability.Account.OsAccount

**返回值：**

| 类型                   | 说明                                                                      |
| ---------------------- | ------------------------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise对象。返回true表示当前账号为测试账号；返回false表示当前账号非测试账号。 |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
    accountManager.isTestOsAccount().then((isTestable: boolean) => {
      console.log('isTestOsAccount successfully, isTestable: ' + isTestable);
    }).catch((err: BusinessError) => {
      console.log('isTestOsAccount failed, error: ' + JSON.stringify(err));
  });
  ```

### isOsAccountVerified<sup>(deprecated)</sup>

isOsAccountVerified(callback: AsyncCallback&lt;boolean&gt;): void

检查当前系统账号是否已验证。使用callback异步回调。

> **说明：**
>
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[checkOsAccountVerified](#checkosaccountverifieddeprecated)。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS 或 ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS，以上权限仅系统应用可申请。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                         | 必填 | 说明                                                            |
| -------- | ---------------------------- | ---- | ------------------------------------------------------------- |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调函数。返回true表示指定账号已验证；返回false表示指定账号未验证。 |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  accountManager.isOsAccountVerified((err: BusinessError, isVerified: boolean) => {
    if (err) {
      console.log('isOsAccountVerified failed, error: ' + JSON.stringify(err));
    } else {
      console.log('isOsAccountVerified successfully, isVerified: ' + isVerified);
    }
  });
  ```

### isOsAccountVerified<sup>(deprecated)</sup>

isOsAccountVerified(localId: number, callback: AsyncCallback&lt;boolean&gt;): void

检查指定系统账号是否已验证。使用callback异步回调。

> **说明：**
>
> 从 API version 7开始支持，从API version 9开始废弃。替代方法仅向系统应用开放。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS 或 ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS，以上权限仅系统应用可申请。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                         | 必填 | 说明                                                            |
| -------- | ---------------------------- | ---- | ------------------------------------------------------------- |
| localId  | number                       | 是   | 系统账号ID。                             |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调函数。返回true表示指定账号已验证；返回false表示指定账号未验证。 |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let localId: number = 100;
  accountManager.isOsAccountVerified(localId, (err: BusinessError, isVerified: boolean) => {
    if (err) {
      console.log('isOsAccountVerified failed, error: ' + JSON.stringify(err));
    } else {
      console.log('isOsAccountVerified successfully, isVerified: ' + isVerified);
    }
  });
  ```

### isOsAccountVerified<sup>(deprecated)</sup>

isOsAccountVerified(localId?: number): Promise&lt;boolean&gt;

检查指定系统账号是否已验证。使用Promise异步回调。

> **说明：**
>
> 从 API version 7开始支持，从API version 9开始废弃。替代方法仅向系统应用开放。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS 或 ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS，以上权限仅系统应用可申请。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名  | 类型   | 必填 | 说明                                                              |
| ------- | ------ | ---- | ---------------------------------------------------------------- |
| localId | number | 否   | 系统账号ID。不填则检查当前系统账号是否已验证。 |

**返回值：**

| 类型                   | 说明                                                               |
| ---------------------- | ----------------------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise对象。返回true表示指定账号已验证；返回false表示指定账号未验证。 |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  accountManager.isOsAccountVerified().then((isVerified: boolean) => {
    console.log('isOsAccountVerified successfully, isVerified: ' + isVerified);
  }).catch((err: BusinessError) => {
    console.log('isOsAccountVerified failed, error: ' + JSON.stringify(err));
  });
  ```

### getCreatedOsAccountsCount<sup>(deprecated)</sup>

getCreatedOsAccountsCount(callback: AsyncCallback&lt;number&gt;): void

获取已创建的系统账号数量。使用callback异步回调。

> **说明：**
>
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[getOsAccountCount](#getosaccountcount9)。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS，该权限仅系统应用可申请。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                                                         |
| -------- | --------------------------- | ---- | -------------------------------------------------------------------------- |
| callback | AsyncCallback&lt;number&gt; | 是   | 回调函数。当获取成功时，err为null，data为已创建的系统账号的数量；否则为错误对象。 |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  accountManager.getCreatedOsAccountsCount((err: BusinessError, count: number)=>{
    if (err) {
      console.log('getCreatedOsAccountsCount failed, error: ' + JSON.stringify(err));
    } else {
      console.log('getCreatedOsAccountsCount successfully, count: ' + count);
    }
  });
  ```

### getCreatedOsAccountsCount<sup>(deprecated)</sup>

getCreatedOsAccountsCount(): Promise&lt;number&gt;

获取已创建的系统账号数量，使用Promise异步回调。

> **说明：**
>
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[getOsAccountCount](#getosaccountcount9-1)。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS，该权限仅系统应用可申请。

**系统能力：** SystemCapability.Account.OsAccount

**返回值：**

| 类型                  | 说明                                    |
| --------------------- | -------------------------------------- |
| Promise&lt;number&gt; | Promise对象，返回已创建的系统账号的数量。 |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  accountManager.getCreatedOsAccountsCount().then((count: number) => {
    console.log('getCreatedOsAccountsCount successfully, count: ' + count);
  }).catch((err: BusinessError) => {
    console.log('getCreatedOsAccountsCount failed, error: ' + JSON.stringify(err));
  });
  ```

### getOsAccountLocalIdFromProcess<sup>(deprecated)</sup>

getOsAccountLocalIdFromProcess(callback: AsyncCallback&lt;number&gt;): void

获取当前进程所属的系统账号ID，使用callback异步回调。

> **说明：**
>
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[getOsAccountLocalId](#getosaccountlocalid9)。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                                                           |
| -------- | --------------------------- | ---- | ---------------------------------------------------------------------------- |
| callback | AsyncCallback&lt;number&gt; | 是   | 回调函数。当获取成功时，err为null，data为当前进程所属的系统账号ID；否则为错误对象。 |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  accountManager.getOsAccountLocalIdFromProcess((err: BusinessError, localId: number) => {
    if (err) {
      console.log('getOsAccountLocalIdFromProcess failed, error: ' + JSON.stringify(err));
    } else {
      console.log('getOsAccountLocalIdFromProcess failed, error: ' + localId);
    }
  });
  ```

### getOsAccountLocalIdFromProcess<sup>(deprecated)</sup>

getOsAccountLocalIdFromProcess(): Promise&lt;number&gt;

获取当前进程所属的系统账号ID，使用Promise异步回调。

> **说明：**
>
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[getOsAccountLocalId](#getosaccountlocalid9-1)。

**系统能力：** SystemCapability.Account.OsAccount

**返回值：**

| 类型                  | 说明                                      |
| :-------------------- | :--------------------------------------- |
| Promise&lt;number&gt; | Promise对象，返回当前进程所属的系统账号ID。 |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  accountManager.getOsAccountLocalIdFromProcess().then((localId: number) => {
    console.log('getOsAccountLocalIdFromProcess successfully, localId: ' + localId);
  }).catch((err: BusinessError) => {
    console.log('getOsAccountLocalIdFromProcess failed, error: ' + JSON.stringify(err));
  });
  ```

### getOsAccountLocalIdFromUid<sup>(deprecated)</sup>

getOsAccountLocalIdFromUid(uid: number, callback: AsyncCallback&lt;number&gt;): void

根据uid查询对应的系统账号ID。使用callback异步回调。

> **说明：**
>
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[getOsAccountLocalIdForUid](#getosaccountlocalidforuid9)。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                                                    |
| -------- | --------------------------- | ---- | --------------------------------------------------------------------- |
| uid      | number                      | 是   | 进程uid。                                                              |
| callback | AsyncCallback&lt;number&gt; | 是   | 回调函数。如果查询成功，err为null，data为对应的系统账号ID；否则为错误对象。 |

**示例：** 查询值为12345678的uid所属的系统账号ID

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let uid: number = 12345678;
  accountManager.getOsAccountLocalIdFromUid(uid, (err: BusinessError, localId: number) => {
    if (err) {
      console.log('getOsAccountLocalIdFromUid failed, error: ' + JSON.stringify(err));
    } else {
      console.log('getOsAccountLocalIdFromUid successfully, localId: ' + localId);
    }
  });
  ```

### getOsAccountLocalIdFromUid<sup>(deprecated)</sup>

getOsAccountLocalIdFromUid(uid: number): Promise&lt;number&gt;

根据uid查询对应的系统账号ID，使用Promise异步回调。

> **说明：**
>
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[getOsAccountLocalIdForUid](#getosaccountlocalidforuid9-1)。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名 | 类型   | 必填 | 说明      |
| ------ | ------ | ---- | --------- |
| uid    | number | 是   | 进程uid。 |

**返回值：**

| 类型                  | 说明                                  |
| :-------------------- | :----------------------------------- |
| Promise&lt;number&gt; | Promise对象，返回uid对应的系统账号ID。 |

**示例：** 查询值为12345678的uid所属的系统账号ID

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let uid: number = 12345678;
  accountManager.getOsAccountLocalIdFromUid(uid).then((localId: number) => {
    console.log('getOsAccountLocalIdFromUid successfully, localId: ' + localId);
  }).catch((err: BusinessError) => {
    console.log('getOsAccountLocalIdFromUid failed, error: ' + JSON.stringify(err));
  });
  ```

### getOsAccountLocalIdFromDomain<sup>(deprecated)</sup>

getOsAccountLocalIdFromDomain(domainInfo: DomainAccountInfo, callback: AsyncCallback&lt;number&gt;): void

根据域账号信息，获取与其关联的系统账号的账号ID。使用callback异步回调。

> **说明：**
>
> 从 API version 8开始支持，从API version 9开始废弃。建议使用[getOsAccountLocalIdForDomain](#getosaccountlocalidfordomain9)。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS，该权限仅系统应用可申请。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名     | 类型                                    | 必填 | 说明                                                                         |
| ---------- | --------------------------------------- | ---- | --------------------------------------------------------------------------- |
| domainInfo | [DomainAccountInfo](#domainaccountinfo8) | 是   | 域账号信息。                                                                |
| callback   | AsyncCallback&lt;number&gt;             | 是   | 回调函数，如果获取成功，err为null，data为域账号关联的系统账号ID；否则为错误对象。 |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let domainInfo: osAccount.DomainAccountInfo = {domain: 'testDomain', accountName: 'testAccountName'};
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  accountManager.getOsAccountLocalIdFromDomain(domainInfo, (err: BusinessError, localId: number) => {
    if (err) {
      console.log('getOsAccountLocalIdFromDomain failed, error: ' + JSON.stringify(err));
    } else {
      console.log('getOsAccountLocalIdFromDomain successfully, localId: ' + localId);
    }
  });
  ```

### getOsAccountLocalIdFromDomain<sup>(deprecated)</sup>

getOsAccountLocalIdFromDomain(domainInfo: DomainAccountInfo): Promise&lt;number&gt;

根据域账号信息，获取与其关联的系统账号的账号ID。使用Promise异步回调。

> **说明：**
>
> 从 API version 8开始支持，从API version 9开始废弃。建议使用[getOsAccountLocalIdForDomain](#getosaccountlocalidfordomain9-1)。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS，该权限仅系统应用可申请。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名     | 类型                                    | 必填 | 说明         |
| ---------- | --------------------------------------- | ---- | ------------ |
| domainInfo | [DomainAccountInfo](#domainaccountinfo8) | 是   | 域账号信息。 |

**返回值：**

| 类型                  | 说明                                    |
| :-------------------- | :------------------------------------- |
| Promise&lt;number&gt; | Promise对象，返回域账号关联的系统账号ID。 |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let domainInfo: osAccount.DomainAccountInfo = {domain: 'testDomain', accountName: 'testAccountName'};
  accountManager.getOsAccountLocalIdFromDomain(domainInfo).then((localId: number) => {
    console.log('getOsAccountLocalIdFromDomain successfully, localId: ' + localId);
  }).catch((err: BusinessError) => {
    console.log('getOsAccountLocalIdFromDomain failed, error: ' + JSON.stringify(err));
  });
  ```

### getOsAccountAllConstraints<sup>(deprecated)</sup>

getOsAccountAllConstraints(localId: number, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

获取指定系统账号的全部约束。使用callback异步回调。

> **说明：**
>
> 从 API version 7开始支持，从API version 9开始废弃。替代方法仅向系统应用开放。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS，该权限仅系统应用可申请。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                                     | 必填 | 说明                                                                                             |
| -------- | ---------------------------------------- | ---- | ---------------------------------------------------------------------------------------------- |
| localId  | number                                   | 是   | 系统账号ID。                                                                                    |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt; | 是   | 回调函数。如果获取成功，err为null，data为指定系统账号的全部[约束](#系统账号约束列表)；否则为错误对象。 |

**示例：** 获取ID为100的系统账号的全部约束

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let localId: number = 100;
  accountManager.getOsAccountAllConstraints(localId, (err: BusinessError, constraints: string[])=>{
    console.log('getOsAccountAllConstraints err:' + JSON.stringify(err));
    console.log('getOsAccountAllConstraints:' + JSON.stringify(constraints));
  });
  ```

### getOsAccountAllConstraints<sup>(deprecated)</sup>

getOsAccountAllConstraints(localId: number): Promise&lt;Array&lt;string&gt;&gt;

获取指定系统账号的全部约束。使用Promise异步回调。

> **说明：**
>
> 从 API version 7开始支持，从API version 9开始废弃。替代方法仅向系统应用开放。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS，该权限仅系统应用可申请。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名  | 类型   | 必填 | 说明         |
| ------- | ------ | ---- | ------------ |
| localId | number | 是   | 系统账号ID。 |

**返回值：**

| 类型                               | 说明                                                         |
| :--------------------------------- | :----------------------------------------------------------- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise对象，返回指定系统账号的全部[约束](#系统账号约束列表)。 |

**示例：** 获取ID为100的系统账号的全部约束

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let localId: number = 100;
  accountManager.getOsAccountAllConstraints(localId).then((constraints: string[]) => {
    console.log('getOsAccountAllConstraints, constraints: ' + constraints);
  }).catch((err: BusinessError) => {
    console.log('getOsAccountAllConstraints err: ' + JSON.stringify(err));
  });
  ```

### queryActivatedOsAccountIds<sup>(deprecated)</sup>

queryActivatedOsAccountIds(callback: AsyncCallback&lt;Array&lt;number&gt;&gt;): void

查询当前处于激活状态的系统账号的ID列表。使用callback异步回调。

> **说明：**
>
> 从 API version 8开始支持，从API version 9开始废弃。建议使用[getActivatedOsAccountLocalIds](#getactivatedosaccountlocalids9)。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                                     | 必填 | 说明                                                   |
| -------- | ---------------------------------------- | ---- | ------------------------------------------------------ |
| callback | AsyncCallback&lt;Array&lt;number&gt;&gt; | 是   | 回调函数。如果查询成功，err为null，data为当前处于激活状态的系统账号的ID列表；否则为错误对象。 |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  accountManager.queryActivatedOsAccountIds((err: BusinessError, idArray: number[])=>{
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
> 从 API version 8开始支持，从API version 9开始废弃。建议使用[getActivatedOsAccountLocalIds](#getactivatedosaccountlocalids9-1)。

查询当前处于激活状态的系统账号的ID列表。使用Promise异步回调。

**系统能力：** SystemCapability.Account.OsAccount

**返回值：**

| 类型                               | 说明                                               |
| ---------------------------------- | ------------------------------------------------- |
| Promise&lt;Array&lt;number&gt;&gt; | Promise对象，返回当前处于激活状态的系统账号的ID列表。 |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  accountManager.queryActivatedOsAccountIds().then((idArray: number[]) => {
    console.log('queryActivatedOsAccountIds, idArray: ' + idArray);
  }).catch((err: BusinessError) => {
    console.log('queryActivatedOsAccountIds err: ' + JSON.stringify(err));
  });
  ```

### queryCurrentOsAccount<sup>(deprecated)</sup>

queryCurrentOsAccount(callback: AsyncCallback&lt;OsAccountInfo&gt;): void

查询当前进程所属的系统账号的信息。使用callback异步回调。

> **说明：**
>
> 从 API version 7开始支持，从API version 9开始废弃。替代方法仅向系统应用开放。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS，该权限仅系统应用可申请。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                                           |
| -------- | ---------------------------------------------------- | ---- | ---------------------------------------------- |
| callback | AsyncCallback&lt;[OsAccountInfo](#osaccountinfo)&gt; | 是   | 回调函数。如果查询成功，err为null，data为当前进程所属的系统账号信息；否则为错误对象。 |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  accountManager.queryCurrentOsAccount((err: BusinessError, curAccountInfo: osAccount.OsAccountInfo)=>{
    console.log('queryCurrentOsAccount err:' + JSON.stringify(err));
    console.log('queryCurrentOsAccount curAccountInfo:' + JSON.stringify(curAccountInfo));
  });
  ```

### queryCurrentOsAccount<sup>(deprecated)</sup>

queryCurrentOsAccount(): Promise&lt;OsAccountInfo&gt;

查询当前进程所属的系统账号的信息。使用Promise异步回调。

> **说明：**
>
> 从 API version 7开始支持，从API version 9开始废弃。替代方法仅向系统应用开放。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS，该权限仅系统应用可申请。

**系统能力：** SystemCapability.Account.OsAccount

**返回值：**

| 类型                                           | 说明                                       |
| ---------------------------------------------- | ------------------------------------------ |
| Promise&lt;[OsAccountInfo](#osaccountinfo)&gt; | Promise对象，返回当前进程所属的系统账号信息。 |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  accountManager.queryCurrentOsAccount().then((accountInfo: osAccount.OsAccountInfo) => {
    console.log('queryCurrentOsAccount, accountInfo: ' + JSON.stringify(accountInfo));
  }).catch((err: BusinessError) => {
    console.log('queryCurrentOsAccount err: ' + JSON.stringify(err));
  });
  ```

### getOsAccountTypeFromProcess<sup>(deprecated)</sup>

getOsAccountTypeFromProcess(callback: AsyncCallback&lt;OsAccountType&gt;): void

查询当前进程所属的系统账号的账号类型。使用callback异步回调。

> **说明：**
>
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[getOsAccountType](#getosaccounttype9)。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                                                 |
| -------- | ---------------------------------------------------- | ---- | ---------------------------------------------------- |
| callback | AsyncCallback&lt;[OsAccountType](#osaccounttype)&gt; | 是   | 回调函数。如果查询成功，err为null，data为当前进程所属的系统账号的账号类型；否则为错误对象。 |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  accountManager.getOsAccountTypeFromProcess((err: BusinessError, accountType: osAccount.OsAccountType) => {
    console.log('getOsAccountTypeFromProcess err: ' + JSON.stringify(err));
    console.log('getOsAccountTypeFromProcess accountType: ' + accountType);
  });
  ```

### getOsAccountTypeFromProcess<sup>(deprecated)</sup>

getOsAccountTypeFromProcess(): Promise&lt;OsAccountType&gt;

查询当前进程所属的系统账号的账号类型。使用Promise异步回调。

> **说明：**
>
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[getOsAccountType](#getosaccounttype9-1)。

**系统能力：** SystemCapability.Account.OsAccount

**返回值：**

| 类型                                           | 说明                                            |
| ---------------------------------------------- | ----------------------------------------------- |
| Promise&lt;[OsAccountType](#osaccounttype)&gt; | Promise对象，返回当前进程所属的系统账号的账号类型。 |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  accountManager.getOsAccountTypeFromProcess().then((accountType: osAccount.OsAccountType) => {
    console.log('getOsAccountTypeFromProcess, accountType: ' + accountType);
  }).catch((err: BusinessError) => {
    console.log('getOsAccountTypeFromProcess err: ' + JSON.stringify(err));
  });
  ```

### getDistributedVirtualDeviceId<sup>(deprecated)</sup>

getDistributedVirtualDeviceId(callback: AsyncCallback&lt;string&gt;): void

获取分布式虚拟设备ID。使用callback异步回调。

> **说明：**
>
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[queryDistributedVirtualDeviceId](#querydistributedvirtualdeviceid9)。

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS（仅系统应用可申请）或 ohos.permission.DISTRIBUTED_DATASYNC

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                                                    |
| -------- | --------------------------- | ---- | --------------------------------------------------------------------- |
| callback | AsyncCallback&lt;string&gt; | 是   | 回调函数。如果获取成功，err为null，data为分布式虚拟设备ID；否则为错误对象。 |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  accountManager.getDistributedVirtualDeviceId((err: BusinessError, virtualID: string) => {
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

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS（仅系统应用可申请）或 ohos.permission.DISTRIBUTED_DATASYNC

**系统能力：** SystemCapability.Account.OsAccount

**返回值：**

| 类型                  | 说明                              |
| --------------------- | --------------------------------- |
| Promise&lt;string&gt; | Promise对象，返回分布式虚拟设备ID。 |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  accountManager.getDistributedVirtualDeviceId().then((virtualID: string) => {
    console.log('getDistributedVirtualDeviceId, virtualID: ' + virtualID);
  }).catch((err: BusinessError) => {
    console.log('getDistributedVirtualDeviceId err: ' + JSON.stringify(err));
  });
  ```

### getOsAccountLocalIdBySerialNumber<sup>(deprecated)</sup>

getOsAccountLocalIdBySerialNumber(serialNumber: number, callback: AsyncCallback&lt;number&gt;): void

通过SN码查询与其关联的系统账号的账号ID。使用callback异步回调。

> **说明：**
>
> 从 API version 8开始支持，从API version 9开始废弃。建议使用[getOsAccountLocalIdForSerialNumber](#getosaccountlocalidforserialnumber9)。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名       | 类型                        | 必填 | 说明                                                                               |
| ------------ | --------------------------- | ---- | -------------------------------------------------------------------------------- |
| serialNumber | number                      | 是   | 账号SN码。                                                                        |
| callback     | AsyncCallback&lt;number&gt; | 是   | 回调函数。如果查询成功，err为null，data为与SN码关联的系统账号的账号ID；否则为错误对象。 |

**示例：** 查询与SN码12345关联的系统账号的ID

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let serialNumber: number = 12345;
  accountManager.getOsAccountLocalIdBySerialNumber(serialNumber, (err: BusinessError, localId: number)=>{
    console.log('ger localId err:' + JSON.stringify(err));
    console.log('get localId:' + localId + ' by serialNumber: ' + serialNumber);
  });
  ```

### getOsAccountLocalIdBySerialNumber<sup>(deprecated)</sup>

getOsAccountLocalIdBySerialNumber(serialNumber: number): Promise&lt;number&gt;

通过SN码查询与其关联的系统账号的账号ID。使用Promise异步回调。

> **说明：**
>
> 从 API version 8开始支持，从API version 9开始废弃。建议使用[getOsAccountLocalIdForSerialNumber](#getosaccountlocalidforserialnumber9-1)。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名       | 类型   | 必填 | 说明       |
| ------------ | ------ | ---- | ---------- |
| serialNumber | number | 是   | 账号SN码。 |

**返回值：**

| 类型                  | 说明                                                         |
| --------------------- | -------------------------------------------- |
| Promise&lt;number&gt; | Promise对象，返回与SN码关联的系统账号的账号ID。 |

**示例：** 查询与SN码12345关联的系统账号的ID

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let serialNumber: number = 12345;
  accountManager.getOsAccountLocalIdBySerialNumber(serialNumber).then((localId: number) => {
    console.log('getOsAccountLocalIdBySerialNumber localId: ' + localId);
  }).catch((err: BusinessError) => {
    console.log('getOsAccountLocalIdBySerialNumber err: ' + JSON.stringify(err));
  });
  ```

### getSerialNumberByOsAccountLocalId<sup>(deprecated)</sup>

getSerialNumberByOsAccountLocalId(localId: number, callback: AsyncCallback&lt;number&gt;): void

通过系统账号ID获取与该系统账号关联的SN码。使用callback异步回调。

> **说明：**
>
> 从 API version 8开始支持，从API version 9开始废弃。建议使用[getSerialNumberForOsAccountLocalId](#getserialnumberforosaccountlocalid9)。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                                                         |
| -------- | --------------------------- | ---- | --------------------------------------------------------------------------- |
| localId  | number                      | 是   | 系统账号ID。                                                                 |
| callback | AsyncCallback&lt;number&gt; | 是   | 回调函数。如果获取成功，err为null，data为与该系统账号关联的SN码；否则为错误对象。 |

**示例：** 获取ID为100的系统账号关联的SN码

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let localId: number = 100;
  accountManager.getSerialNumberByOsAccountLocalId(localId, (err: BusinessError, serialNumber: number)=>{
    console.log('ger serialNumber err:' + JSON.stringify(err));
    console.log('get serialNumber:' + serialNumber + ' by localId: ' + localId);
  });
  ```

### getSerialNumberByOsAccountLocalId<sup>(deprecated)</sup>

getSerialNumberByOsAccountLocalId(localId: number): Promise&lt;number&gt;

通过系统账号ID获取与该系统账号关联的SN码。使用Promise异步回调。

> **说明：**
>
> 从 API version 8开始支持，从API version 9开始废弃。建议使用[getSerialNumberForOsAccountLocalId](#getserialnumberforosaccountlocalid9-1)。

**系统能力：** SystemCapability.Account.OsAccount

**参数：**

| 参数名  | 类型   | 必填 | 说明          |
| ------- | ------ | ---- | ----------- |
| localId | number | 是   | 系统账号ID。 |

**返回值：**

| 类型                  | 说明                                    |
| --------------------- | -------------------------------------- |
| Promise&lt;number&gt; | Promise对象，返回与该系统账号关联的SN码。 |

**示例：** 获取ID为100的系统账号关联的SN码

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let localId: number = 100;
  accountManager.getSerialNumberByOsAccountLocalId(localId).then((serialNumber: number) => {
    console.log('getSerialNumberByOsAccountLocalId serialNumber: ' + serialNumber);
  }).catch((err: BusinessError) => {
    console.log('getSerialNumberByOsAccountLocalId err: ' + JSON.stringify(err));
  });
  ```

### getOsAccountName<sup>12+</sup>

getOsAccountName(): Promise&lt;string&gt;

查询调用方所属系统账号的名称。使用Promise异步回调。

**系统能力：** SystemCapability.Account.OsAccount

**返回值：**

| 类型                      | 说明                     |
| :------------------------ | ----------------------- |
| Promise&lt;string&gt; | Promise对象，返回调用方所属系统账号的名称。 |

**错误码：**

| 错误码ID | 错误信息                     |
| -------- | --------------------------- |
| 12300001 | The system service works abnormally. |

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  try {
    accountManager.getOsAccountName().then((name: string) => {
      console.log('getOsAccountName, name: ' + name);
    }).catch((err: BusinessError) => {
      console.log('getOsAccountName err: ' + err);
    });
  } catch (e) {
    console.log('getOsAccountName exception: ' + e);
  }
  ```

### getForegroundOsAccountLocalId<sup>15+</sup>

getForegroundOsAccountLocalId(): Promise&lt;number&gt;;

获取前台系统账号的ID。

**系统能力：** SystemCapability.Account.OsAccount

**返回值：**

| 类型                   | 说明                                                               |
| ---------------------- | ----------------------------------------------------------------- |
| Promise&lt;number&gt; | Promise对象。返回前台系统账号的ID。 |

**错误码：**

| 错误码ID | 错误信息       |
| -------- | ------------- |
| 12300001 | The system service works abnormally. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  try {
    accountManager.getForegroundOsAccountLocalId().then((localId: number) => {
      console.log('getForegroundOsAccountLocalId, localId: ' + localId);
    }).catch((err: BusinessError) => {
      console.log('getForegroundOsAccountLocalId err: ' + JSON.stringify(err));
    });
  } catch (e) {
    console.log('getForegroundOsAccountLocalId exception: ' + JSON.stringify(e));
  }
  ```

### getOsAccountDomainInfo<sup>15+</sup>

getOsAccountDomainInfo(localId: number): Promise&lt;DomainAccountInfo&gt;;

获取指定系统账号关联的域账号信息。

**需要权限：** ohos.permission.GET_DOMAIN_ACCOUNTS 和 ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS，以上权限允许系统应用和企业应用进行申请。

**系统能力：** SystemCapability.Account.OsAccount

**返回值：**

| 类型                   | 说明                                                               |
| ---------------------- | ----------------------------------------------------------------- |
| Promise&lt;[DomainAccountInfo](#domainaccountinfo8)&gt; | Promise对象。返回与指定系统账号关联的域账号信息。 |

**错误码：**

| 错误码ID | 错误信息       |
| -------- | ------------- |
| 201 | Permission denied. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300003 | OS account not found. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let localId: number = 100;
  accountManager.getOsAccountDomainInfo(localId).then((domainAccountInfo: osAccount.DomainAccountInfo) => {
    if (domainAccountInfo === null) {
      console.log('The target OS account is not a domain account.')
    } else {
      console.log('getOsAccountDomainInfo domain: ' + domainAccountInfo.domain);
      console.log('getOsAccountDomainInfo accountName: ' + domainAccountInfo.accountName);
    }
  }).catch((err: BusinessError) => {
    console.log('getOsAccountDomainInfo err: ' + JSON.stringify(err));
  })
  ```

## OsAccountInfo

表示系统账号信息。

**系统能力：** SystemCapability.Account.OsAccount

| 名称                         | 类型                                                         | 必填 | 说明                              |
| ------------------------------ | ------------------------------------------------------------ | ---- | --------------------------------- |
| localId                        | number                                                       | 是   | 系统账号ID。                      |
| localName                      | string                                                       | 是   | 系统账号名称。                    |
| type                           | [OsAccountType](#osaccounttype)                              | 是   | 系统账号类型。                      |
| constraints                    | Array&lt;string&gt;                                          | 是   | 系统账号[约束](#系统账号约束列表)，默认为空。|
| isVerified<sup>(deprecated)</sup> | boolean                                                   | 是   | 账号是否验证。<br>**说明**: 从API version 7开始支持，从API version 11开始废弃。                     |
| isUnlocked<sup>11+</sup>      | boolean                                                       | 是   | 账号是否已解锁（EL2级别目录是否解密）。                      |
| photo<sup>8+</sup>             | string                                                       | 是   | 系统账号头像，默认为空。                      |
| createTime<sup>8+</sup>        | number                                                       | 是   | 系统账号创建时间。                  |
| lastLoginTime<sup>8+</sup>     | number                                                       | 是   | 系统账号最后一次登录时间，默认为空。          |
| serialNumber<sup>8+</sup>      | number                                                       | 是   | 系统账号SN码。                      |
| isActived<sup>(deprecated)</sup>         | boolean                                            | 是   | 系统账号激活状态。<br>**说明**: 从API version 7开始支持，从API version 11开始废弃。                  |
| isActivated<sup>11+</sup>         | boolean                                                   | 是   | 系统账号激是否激活。                  |
| isCreateCompleted<sup>8+</sup> | boolean                                                      | 是   | 系统账号创建是否完整。              |
| distributedInfo                | [distributedAccount.DistributedInfo](js-apis-distributed-account.md#distributedinfo) | 是   | 分布式账号信息，默认为空。                    |
| domainInfo<sup>8+</sup>        | [DomainAccountInfo](#domainaccountinfo8)                      | 是   | 域账号信息，默认为空。                        |

## DomainAccountInfo<sup>8+</sup>

表示域账号信息。

**系统能力：** SystemCapability.Account.OsAccount

| 名称      | 类型   | 必填 | 说明       |
| ----------- | ------ | ---- | ---------- |
| domain      | string | 是   | 域名。     |
| accountName | string | 是   | 域账号名。 |

## 系统账号约束列表

| 约束                                  | 说明                           |
| ------------------------------------- | ------------------------------ |
| constraint.wifi                       | 禁止使用Wi-Fi                  |
| constraint.wifi.set                   | 禁止配置Wi-Fi                  |
| constraint.locale.set                 | 禁止配置设备语言               |
| constraint.app.accounts               | 禁止添加和删除应用账号         |
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
| constraint.debug.features.use | 禁止启用或访问调试功能 |
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
| constraint.parent.profile.app.linking | 禁止父配置文件中的应用程序处理来自托管配置文件的Web链接 |
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
| constraint.os.account.activate | 禁止前台启动用户 |
| constraint.location.set | 禁止配置位置服务 |
| constraint.airplane.mode.set | 禁止飞行模式 |
| constraint.brightness.set | 禁止配置亮度 |
| constraint.share.into.profile | 禁止将主要用户的文件/图片/数据共享到托管配置文件中 |
| constraint.ambient.display | 禁止显示环境 |
| constraint.screen.timeout.set | 禁止配置屏幕关闭的超时 |
| constraint.print | 禁止打印 |
| constraint.private.dns.set | 禁止配置专用DNS |
