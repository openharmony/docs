# @ohos.account.distributedAccount (分布式账号管理)

<!--Kit: Basic Services Kit-->
<!--Subsystem: Account-->
<!--Owner: @steven-q-->
<!--Designer: @JiDong-CS1-->
<!--Tester: @zhaimengchao-->
<!--Adviser: @zengyawen-->

本模块提供管理分布式账号的一些基础功能，主要包括查询和更新账号登录状态。

> **说明：**
> 
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { distributedAccount } from '@kit.BasicServicesKit';
```

## distributedAccount.getDistributedAccountAbility

getDistributedAccountAbility(): DistributedAccountAbility

获取分布式账号单实例对象。

**系统能力：** SystemCapability.Account.OsAccount

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | [DistributedAccountAbility](#distributedaccountability) | 返回一个实例，实例提供查询和更新分布式账号登录状态方法。 |

**示例：**
  ```ts
  const accountAbility: distributedAccount.DistributedAccountAbility = distributedAccount.getDistributedAccountAbility();
  ```

## DistributedAccountAbility

提供查询和更新分布式账号登录状态方法(需要先获取分布式账号的单实例对象)。

### getOsAccountDistributedInfo<sup>9+</sup>

getOsAccountDistributedInfo(callback: AsyncCallback&lt;DistributedInfo&gt;): void

获取分布式账号信息，使用callback异步回调。

**系统能力：** SystemCapability.Account.OsAccount

**需要权限：** ohos.permission.MANAGE_DISTRIBUTED_ACCOUNTS（仅系统应用可申请）或ohos.permission.GET_DISTRIBUTED_ACCOUNTS（仅系统应用可申请）或ohos.permission.DISTRIBUTED_DATASYNC

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;[DistributedInfo](#distributedinfo)&gt; | 是 | 回调参数。当获取分布式账号信息成功，err为undefined，data为获取到的分布式账号信息对象；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[账号管理错误码](errorcode-account.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息|
| -------- | ------------------- |
| 201 | Permission denied.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | System service exception. |

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  const accountAbility: distributedAccount.DistributedAccountAbility = distributedAccount.getDistributedAccountAbility();
  try {
    accountAbility.getOsAccountDistributedInfo(
      (err: BusinessError, data: distributedAccount.DistributedInfo) => {
        if (err) {
          console.error(`getOsAccountDistributedInfo exception: code is ${err.code}, message is ${err.message}`);
        } else {
          console.info('distributed information: ' + JSON.stringify(data));
        }
      });
  } catch (err) {
    console.error(`getOsAccountDistributedInfo exception: code is ${err.code}, message is ${err.message}`);
  }
  ```

### getOsAccountDistributedInfo<sup>9+</sup>

getOsAccountDistributedInfo(): Promise&lt;DistributedInfo&gt;

获取分布式账号信息。使用Promise异步回调。

**系统能力：** SystemCapability.Account.OsAccount

**需要权限：** ohos.permission.MANAGE_DISTRIBUTED_ACCOUNTS（仅系统应用可申请）或ohos.permission.GET_DISTRIBUTED_ACCOUNTS（仅系统应用可申请）或ohos.permission.DISTRIBUTED_DATASYNC

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;[DistributedInfo](#distributedinfo)&gt; | Promise对象，返回分布式账号信息对象。 |

**错误码：**

以下错误码的详细介绍请参见[账号管理错误码](errorcode-account.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息|
| -------- | ------------------- |
| 201 | Permission denied.|
| 12300001 | System service exception. |

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  const accountAbility: distributedAccount.DistributedAccountAbility = distributedAccount.getDistributedAccountAbility();
  try {
    accountAbility.getOsAccountDistributedInfo().then((data: distributedAccount.DistributedInfo) => {
        console.info('distributed information: ' + JSON.stringify(data));
    }).catch((err: BusinessError) => {
        console.error(`getOsAccountDistributedInfo exception: code is ${err.code}, message is ${err.message}`);
    });
  } catch (err) {
    console.error(`getOsAccountDistributedInfo exception: code is ${err.code}, message is ${err.message}`);
  }
  ```

### queryOsAccountDistributedInfo<sup>(deprecated)</sup>

queryOsAccountDistributedInfo(callback: AsyncCallback&lt;DistributedInfo&gt;): void

获取分布式账号信息。使用callback异步回调。
> **说明：** 
>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[getOsAccountDistributedInfo](#getosaccountdistributedinfo9)。

**系统能力：** SystemCapability.Account.OsAccount

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS（仅系统应用可申请）或ohos.permission.DISTRIBUTED_DATASYNC

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;[DistributedInfo](#distributedinfo)&gt; | 是 | 回调函数。当获取分布式账号信息成功，err为undefined，data为获取到的分布式账号信息对象；否则为错误对象。 |

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  
  const accountAbility: distributedAccount.DistributedAccountAbility = distributedAccount.getDistributedAccountAbility();
  accountAbility.queryOsAccountDistributedInfo(
    (err: BusinessError, data: distributedAccount.DistributedInfo) => {
      if (err) {
        console.error(`queryOsAccountDistributedInfo exception: code is ${err.code}, message is ${err.message}`);
      } else {
        console.info('distributed information: ' + JSON.stringify(data));
      }
    });
  ```

### queryOsAccountDistributedInfo<sup>(deprecated)</sup>

queryOsAccountDistributedInfo(): Promise&lt;DistributedInfo&gt;

获取分布式账号信息。使用Promise异步回调。

> **说明：** 
>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[getOsAccountDistributedInfo](#getosaccountdistributedinfo9-1)。

**系统能力：** SystemCapability.Account.OsAccount

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS（仅系统应用可申请）或ohos.permission.DISTRIBUTED_DATASYNC

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;[DistributedInfo](#distributedinfo)&gt; | Promise对象，返回分布式账号信息对象。 |

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  
  const accountAbility: distributedAccount.DistributedAccountAbility = distributedAccount.getDistributedAccountAbility();
  accountAbility.queryOsAccountDistributedInfo().then((data: distributedAccount.DistributedInfo) => {
      console.info('distributed information: ' + JSON.stringify(data));
  }).catch((err: BusinessError) => {
      console.error(`queryOsAccountDistributedInfo exception: code is ${err.code}, message is ${err.message}`);
  });
  ```

### setOsAccountDistributedInfo<sup>9+</sup>

setOsAccountDistributedInfo(accountInfo: DistributedInfo, callback: AsyncCallback&lt;void&gt;): void

更新分布式账号信息。使用callback异步回调。

**系统能力：** SystemCapability.Account.OsAccount

**需要权限：** ohos.permission.MANAGE_DISTRIBUTED_ACCOUNTS，该权限仅系统应用可申请。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | accountInfo | [DistributedInfo](#distributedinfo) | 是 | 分布式账号信息。 |
  | callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当更新分布式账号信息成功时，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[账号管理错误码](errorcode-account.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息|
| -------- | ------------------- |
| 201 | Permission denied.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | System service exception. |
| 12300002 | Invalid accountInfo. |
| 12300003 | Account not found. |

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  
  const accountAbility: distributedAccount.DistributedAccountAbility = distributedAccount.getDistributedAccountAbility();
  let accountInfo: distributedAccount.DistributedInfo =
    {id: '12345', name: 'ZhangSan', event: 'Ohos.account.event.LOGIN'};
  try {
    accountAbility.setOsAccountDistributedInfo(accountInfo, (err: BusinessError) => {
      if (err) {
        console.error(`setOsAccountDistributedInfo exception: code is ${err.code}, message is ${err.message}`);
      } else {
        console.info('setOsAccountDistributedInfo successfully');
      }
    });
  } catch (err) {
      console.error(`setOsAccountDistributedInfo exception: code is ${err.code}, message is ${err.message}`);
  }
  ```

### setOsAccountDistributedInfo<sup>9+</sup>

setOsAccountDistributedInfo(accountInfo: DistributedInfo): Promise&lt;void&gt;

更新分布式账号信息。使用Promise异步回调。

**系统能力：** SystemCapability.Account.OsAccount

**需要权限：** ohos.permission.MANAGE_DISTRIBUTED_ACCOUNTS，该权限仅系统应用可申请。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | accountInfo | [DistributedInfo](#distributedinfo) | 是 | 分布式账号信息。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise对象，无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[账号管理错误码](errorcode-account.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息|
| -------- | ------------------- |
| 201 | Permission denied.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | System service exception. |
| 12300002 | Invalid accountInfo. |
| 12300003 | Account not found. |

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  
  const accountAbility: distributedAccount.DistributedAccountAbility = distributedAccount.getDistributedAccountAbility();
  let accountInfo: distributedAccount.DistributedInfo =
    {id: '12345', name: 'ZhangSan', event: 'Ohos.account.event.LOGIN'};
  try {
    accountAbility.setOsAccountDistributedInfo(accountInfo).then(() => {
        console.info('setOsAccountDistributedInfo successfully');
    }).catch((err: BusinessError) => {
        console.error(`setOsAccountDistributedInfo exception: code is ${err.code}, message is ${err.message}`);
    });
  } catch (err) {
      console.error(`setOsAccountDistributedInfo exception: code is ${err.code}, message is ${err.message}`);
  }
  ```

### updateOsAccountDistributedInfo<sup>(deprecated)</sup>

updateOsAccountDistributedInfo(accountInfo: DistributedInfo, callback: AsyncCallback&lt;void&gt;): void

更新分布式账号信息。使用callback异步回调。

> **说明：** 
>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[setOsAccountDistributedInfo](#setosaccountdistributedinfo9)。

**系统能力：** SystemCapability.Account.OsAccount

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS，该权限仅系统应用可申请。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | accountInfo | [DistributedInfo](#distributedinfo) | 是 | 分布式账号信息。 |
  | callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当更新分布式账号信息成功时，err为undefined，否则为错误对象。 |

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  
  const accountAbility: distributedAccount.DistributedAccountAbility = distributedAccount.getDistributedAccountAbility();
  let accountInfo: distributedAccount.DistributedInfo =
    {id: '12345', name: 'ZhangSan', event: 'Ohos.account.event.LOGIN'};
  accountAbility.updateOsAccountDistributedInfo(accountInfo, (err: BusinessError) => {
    if (err) {
      console.error(`updateOsAccountDistributedInfo exception: code is ${err.code}, message is ${err.message}`);
    } else {
      console.info('updateOsAccountDistributedInfo successfully');
    }
  });
  ```

### updateOsAccountDistributedInfo<sup>(deprecated)</sup>

updateOsAccountDistributedInfo(accountInfo: DistributedInfo): Promise&lt;void&gt;

更新分布式账号信息。使用Promise异步回调。
> **说明：** 
>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[setOsAccountDistributedInfo](#setosaccountdistributedinfo9-1)。

**系统能力：** SystemCapability.Account.OsAccount

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS，该权限仅系统应用可申请。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | accountInfo | [DistributedInfo](#distributedinfo) | 是 | 分布式账号信息。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise对象，无返回结果的Promise对象。 |

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  
  const accountAbility: distributedAccount.DistributedAccountAbility = distributedAccount.getDistributedAccountAbility();
  let accountInfo: distributedAccount.DistributedInfo =
    {id: '12345', name: 'ZhangSan', event: 'Ohos.account.event.LOGIN'};
  accountAbility.updateOsAccountDistributedInfo(accountInfo).then(() => {
      console.info('updateOsAccountDistributedInfo successfully');
   }).catch((err: BusinessError) => {
      console.error(`updateOsAccountDistributedInfo exception: code is ${err.code}, message is ${err.message}`);
  });
  ```

## DistributedInfo

提供操作系统账号的分布式信息。

**系统能力：** SystemCapability.Account.OsAccount

| 名称 | 类型 | 只读  | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| name | string | 否 | 否  | 分布式账号名称，非空字符串。 |
| id | string | 否 | 否  | 分布式账号UID，非空字符串。 |
| event | string | 否 | 否  | 分布式账号登录状态，包括登录、登出、Token失效和注销，分别对应以下字符串：<br/>-&nbsp;Ohos.account.event.LOGIN<br/>-&nbsp;Ohos.account.event.LOGOUT<br/>-&nbsp;Ohos.account.event.TOKEN_INVALID<br/>-&nbsp;Ohos.account.event.LOGOFF |
| nickname<sup>9+</sup> | string | 否 | 是  | 分布式账号的昵称，默认为空。 |
| avatar<sup>9+</sup> | string | 否 | 是  | 分布式账号的头像，默认为空。 |
| status<sup>10+</sup> | [DistributedAccountStatus](#distributedaccountstatus10) | 是 | 是  | 分布式账号的状态，枚举类型，默认为未登录状态。 |
| scalableData<sup>8+</sup> | object | 否 | 是  | 分布式账号扩展信息，根据业务所需，以k-v形式传递定制化信息，默认为空。|

## DistributedAccountStatus<sup>10+</sup>

表示分布式账号状态枚举。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Account.OsAccount

| 名称  | 值 | 说明        |
| ---- | ------ | ----------- |
| NOT_LOGGED_IN   | 0  | 未登录状态。 |
| LOGGED_IN  | 1  | 已登录状态。 |
