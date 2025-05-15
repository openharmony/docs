# @ohos.security.asset (关键资产存储服务)(系统接口)

关键资产存储服务提供了用户短敏感数据的安全存储及管理能力。其中，短敏感数据可以是密码类（账号/密码）、Token类（应用凭据）、其他关键明文（如银行卡号）等长度较短的用户敏感数据。

> **说明：**
>
> - 本模块首批接口从API version 12 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 当前页面仅包含本模块的系统接口，其他公开接口参见[ohos.security.asset (关键资产存储服务)](js-apis-asset.md)。

## 导入模块

```typescript
import { asset } from '@kit.AssetStoreKit';
```

## asset.addAsUser

addAsUser(userId: number, attributes: AssetMap): Promise\<void>

在指定用户空间中新增一条关键资产，使用Promise方式异步返回结果。

设置[IS_PERSISTENT](js-apis-asset.md#tag)属性，需申请ohos.permission.STORE_PERSISTENT_DATA权限。

**需要权限：** ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Security.Asset

**参数：**

| 参数名     | 类型     | 必填 | 说明                                                         |
| ---------- | -------- | ---- | ------------------------------------------------------------ |
| userId     | number                                | 是   | 用户ID。取值范围大于等于100。                           |
| attributes | [AssetMap](js-apis-asset.md#assetmap) | 是   | 待新增关键资产的属性集合，包括关键资产明文、访问控制属性、自定义数据等。 |

**返回值：**

| 类型          | 说明                    |
| ------------- | ----------------------- |
| Promise\<void> | Promise对象，无返回值。 |

**错误码：**

以下错误码的详细介绍请参见[关键资产存储服务错误码](errorcode-asset.md)

| 错误码ID | 错误信息                                                   |
| -------- | ---------------------------------------------------------- |
| 201      | The caller doesn't have the permission.                    |
| 202      | Non-system applications use system APIs.                   |
| 401      | Parameter error. Possible causes: <br> 1. Mandatory parameters are left unspecified. <br> 2. Incorrect parameter types. <br> 3. Parameter verification failed.           |
| 24000001 | The ASSET service is unavailable.                          |
| 24000003 | The asset already exists.                                  |
| 24000005 | The screen lock status does not match.                         |
| 24000006 | Insufficient memory.                                       |
| 24000007 | The asset is corrupted.                                    |
| 24000008 | The database operation failed.                          |
| 24000009 | The cryptography operation failed.                      |
| 24000010 | IPC failed.                                |
| 24000011 | Calling the Bundle Manager service failed. |
| 24000012 | Calling the OS Account service failed.     |
| 24000013 | Calling the Access Token service failed.   |
| 24000014 | The file operation failed.                           |
| 24000015 | Getting the system time failed.            |

**示例：**

```typescript
import { asset } from '@kit.AssetStoreKit';
import { util } from '@kit.ArkTS';
import { BusinessError } from '@kit.BasicServicesKit';

function stringToArray(str: string): Uint8Array {
  let textEncoder = new util.TextEncoder();
  return textEncoder.encodeInto(str);
}

let userId: number = 100;
let attr: asset.AssetMap = new Map();
attr.set(asset.Tag.SECRET, stringToArray('demo_pwd'));
attr.set(asset.Tag.ALIAS, stringToArray('demo_alias'));
attr.set(asset.Tag.ACCESSIBILITY, asset.Accessibility.DEVICE_FIRST_UNLOCKED);
attr.set(asset.Tag.DATA_LABEL_NORMAL_1, stringToArray('demo_label'));
try {
  asset.addAsUser(userId, attr).then(() => {
    console.info(`Asset added to user space successfully.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to add Asset to user space. Code is ${err.code}, message is ${err.message}`);
  })
} catch (error) {
  let err = error as BusinessError;
  console.error(`Failed to add Asset to user space. Code is ${err.code}, message is ${err.message}`);
}
```

## asset.removeAsUser

removeAsUser(userId: number, query: AssetMap): Promise\<void>

从指定用户空间中删除符合条件的一条或多条关键资产，使用Promise方式异步返回结果。

**需要权限：** ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Security.Asset

**参数：**

| 参数名 | 类型     | 必填 | 说明                                                   |
| ------ | -------- | ---- | ------------------------------------------------------ |
| userId | number                                | 是   | 用户ID。取值范围大于等于100。                         |
| query  | [AssetMap](js-apis-asset.md#assetmap) | 是   | 待删除关键资产的搜索条件，如别名、访问控制属性、自定义数据等。 |

**返回值：**

| 类型          | 说明                    |
| ------------- | ----------------------- |
| Promise\<void> | Promise对象，无返回值。 |

**错误码：**

以下错误码的详细介绍请参见[关键资产存储服务错误码](errorcode-asset.md)

| 错误码ID | 错误信息                                                   |
| -------- | ---------------------------------------------------------- |
| 201      | The caller doesn't have the permission.                    |
| 202      | Non-system applications use system APIs.                   |
| 401      | Parameter error. Possible causes: <br> 1. Incorrect parameter types.  <br> 2. Parameter verification failed. |
| 24000001 | The ASSET service is unavailable.                          |
| 24000002 | The asset is not found.                        |
| 24000006 | Insufficient memory.                                       |
| 24000007 | The asset is corrupted.                                    |
| 24000008 | The database operation failed.                          |
| 24000010 | IPC failed.                                |
| 24000011 | Calling the Bundle Manager service failed. |
| 24000012 | Calling the OS Account service failed.     |
| 24000013 | Calling the Access Token service failed.   |
| 24000015 | Getting the system time failed.            |

**示例：**

```typescript
import { asset } from '@kit.AssetStoreKit';
import { util } from '@kit.ArkTS';
import { BusinessError } from '@kit.BasicServicesKit';

function stringToArray(str: string): Uint8Array {
  let textEncoder = new util.TextEncoder();
  return textEncoder.encodeInto(str);
}

let userId: number = 100;
let query: asset.AssetMap = new Map();
query.set(asset.Tag.ALIAS, stringToArray('demo_alias'));
try {
  asset.removeAsUser(userId, query).then(() => {
    console.info(`Asset removed from user space successfully.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to remove Asset from user space. Code is ${err.code}, message is ${err.message}`);
  });
} catch (error) {
  let err = error as BusinessError;
  console.error(`Failed to remove Asset from user space. Code is ${err.code}, message is ${err.message}`);
}
```

## asset.updateAsUser

updateAsUser(userId: number, query: AssetMap, attributesToUpdate: AssetMap): Promise\<void>

在指定用户空间中更新符合条件的一条关键资产，使用Promise方式异步返回结果。

**需要权限：** ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Security.Asset

**参数：**

| 参数名             | 类型     | 必填 | 说明                                                         |
| ------------------ | -------- | ---- | ------------------------------------------------------------ |
| userId             | number                                | 是   | 用户ID。取值范围大于等于100。                              |
| query              | [AssetMap](js-apis-asset.md#assetmap) | 是   | 待更新关键资产的搜索条件，如关键资产别名、访问控制属性、自定义数据等。 |
| attributesToUpdate | [AssetMap](js-apis-asset.md#assetmap) | 是   | 待更新关键资产的属性集合，如关键资产明文和自定义数据等。              |

**返回值：**

| 类型          | 说明                    |
| ------------- | ----------------------- |
| Promise\<void> | Promise对象，无返回值。 |

**错误码：**

以下错误码的详细介绍请参见[关键资产存储服务错误码](errorcode-asset.md)

| 错误码ID | 错误信息                                                   |
| -------- | ---------------------------------------------------------- |
| 201      | The caller doesn't have the permission.                    |
| 202      | Non-system applications use system APIs.                   |
| 401      | Parameter error. Possible causes: <br> 1. Mandatory parameters are left unspecified. <br> 2. Incorrect parameter types. <br> 3. Parameter verification failed.           |
| 24000001 | The ASSET service is unavailable.                          |
| 24000002 | The asset is not found.                        |
| 24000005 | The screen lock status does not match.                         |
| 24000006 | Insufficient memory.                                       |
| 24000007 | The asset is corrupted.                                    |
| 24000008 | The database operation failed.                          |
| 24000009 | The cryptography operation failed.                      |
| 24000010 | IPC failed.                                |
| 24000011 | Calling the Bundle Manager service failed. |
| 24000012 | Calling the OS Account service failed.     |
| 24000013 | Calling the Access Token service failed.   |
| 24000015 | Getting the system time failed.            |

**示例：**

```typescript
import { asset } from '@kit.AssetStoreKit';
import { util } from '@kit.ArkTS';
import { BusinessError } from '@kit.BasicServicesKit';

function stringToArray(str: string): Uint8Array {
  let textEncoder = new util.TextEncoder();
  return textEncoder.encodeInto(str);
}

let userId: number = 100;
let query: asset.AssetMap = new Map();
query.set(asset.Tag.ALIAS, stringToArray('demo_alias'));
let attrsToUpdate: asset.AssetMap = new Map();
attrsToUpdate.set(asset.Tag.SECRET, stringToArray('demo_pwd_new'));
try {
  asset.updateAsUser(userId, query, attrsToUpdate).then(() => {
    console.info(`Asset updated in user space successfully.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to update Asset in user space. Code is ${err.code}, message is ${err.message}`);
  });
} catch (error) {
  let err = error as BusinessError;
  console.error(`Failed to update Asset in user space. Code is ${err.code}, message is ${err.message}`);
}
```

## asset.preQueryAsUser

preQueryAsUser(userId: number, query: AssetMap): Promise\<Uint8Array>

在指定用户空间中查询的预处理，用于需要用户认证的关键资产。在用户认证成功后，应当随后调用[asset.queryAsUser](#assetqueryasuser)、[asset.postQueryAsUser](#assetpostqueryasuser)。使用Promise方式异步返回结果。

**需要权限：** ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Security.Asset

**参数：**

| 参数名 | 类型     | 必填 | 说明                                                   |
| ------ | -------- | ---- | ------------------------------------------------------ |
| userId | number                                | 是   | 用户ID。取值范围大于等于100。                        |
| query  | [AssetMap](js-apis-asset.md#assetmap) | 是   | 关键资产的查询条件，如别名、访问控制属性、自定义数据等。 |

**返回值：**

| 类型                | 说明                                                  |
| ------------------- | ----------------------------------------------------- |
| Promise\<Uint8Array> | Promise对象，返回挑战值。<br>**说明：** 挑战值用于后续用户认证。 |

**错误码：**

以下错误码的详细介绍请参见[关键资产存储服务错误码](errorcode-asset.md)

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | The caller doesn't have the permission.                      |
| 202      | Non-system applications use system APIs.                     |
| 401      | Parameter error. Possible causes: <br> 1. Incorrect parameter types.  <br> 2. Parameter verification failed. |
| 24000001 | The ASSET service is unavailable.                            |
| 24000002 | The asset is not found.                          |
| 24000005 | The screen lock status does not match.                           |
| 24000006 | Insufficient memory.                                         |
| 24000007 | The asset is corrupted.                                      |
| 24000008 | The database operation failed.                            |
| 24000009 | The cryptography operation failed.                        |
| 24000010 | IPC failed.                                  |
| 24000011 | Calling the Bundle Manager service failed.   |
| 24000012 | Calling the OS Account service failed.       |
| 24000013 | Calling the Access Token service failed.     |
| 24000016 | The cache exceeds the limit.                                 |
| 24000017 | The capability is not supported.                             |

**示例：**

```typescript
import { asset } from '@kit.AssetStoreKit';
import { util } from '@kit.ArkTS';
import { BusinessError } from '@kit.BasicServicesKit';

function stringToArray(str: string): Uint8Array {
  let textEncoder = new util.TextEncoder();
  return textEncoder.encodeInto(str);
}

let userId: number = 100;
let query: asset.AssetMap = new Map();
query.set(asset.Tag.ALIAS, stringToArray('demo_alias'));
try {
  asset.preQueryAsUser(userId, query).then((challenge: Uint8Array) => {
    console.info(`Succeeded in pre-querying Asset from user space.`);
  }).catch ((err: BusinessError) => {
    console.error(`Failed to pre-query Asset from user space. Code is ${err.code}, message is ${err.message}`);
  });
} catch (error) {
  let err = error as BusinessError;
  console.error(`Failed to pre-query Asset from user space. Code is ${err.code}, message is ${err.message}`);
}
```

## asset.queryAsUser

queryAsUser(userId: number, query: AssetMap): Promise\<Array\<AssetMap>>

在指定用户空间中查询一条或多条符合条件的关键资产。若查询需要用户认证的关键资产，则需要在本函数前调用[asset.preQueryAsUser](#assetprequeryasuser)，在本函数后调用[asset.postQueryAsUser](#assetpostqueryasuser)，开发步骤请参考[开发指导](../../security/AssetStoreKit/asset-js-query-auth.md)。使用Promise回调异步返回结果。

**需要权限：** ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Security.Asset

**参数：**

| 参数名   | 类型                            | 必填 | 说明                                                         |
| -------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| userId   | number                                          | 是   | 用户ID。取值范围大于等于100。                          |
| query    | [AssetMap](js-apis-asset.md#assetmap)           | 是   | 关键资产的查询条件，如别名、访问控制属性、自定义数据等。       |

**返回值：**

| 类型                     | 说明                                  |
| ------------------------ | ------------------------------------- |
| Promise\<Array\<AssetMap>> | Promise对象，返回查询结果列表。 |

**错误码：**

以下错误码的详细介绍请参见[关键资产存储服务错误码](errorcode-asset.md)

| 错误码ID | 错误信息                                                   |
| -------- | ---------------------------------------------------------- |
| 201      | The caller doesn't have the permission.                    |
| 202      | Non-system applications use system APIs.                   |
| 401      | Parameter error. Possible causes: <br> 1. Incorrect parameter types.  <br> 2. Parameter verification failed. |
| 24000001 | The ASSET service is unavailable.                          |
| 24000002 | The asset is not found.                        |
| 24000004 | Access denied.                             |
| 24000005 | The screen lock status does not match.                         |
| 24000006 | Insufficient memory.                                       |
| 24000007 | The asset is corrupted.                                    |
| 24000008 | The database operation failed.                          |
| 24000009 | The cryptography operation failed.                      |
| 24000010 | IPC failed.                                |
| 24000011 | Calling the Bundle Manager service failed. |
| 24000012 | Calling the OS Account service failed.     |
| 24000013 | Calling the Access Token service failed.   |
| 24000017 | The capability is not supported.                           |

**示例：**

```typescript
import { asset } from '@kit.AssetStoreKit';
import { util } from '@kit.ArkTS';
import { BusinessError } from '@kit.BasicServicesKit';

function stringToArray(str: string): Uint8Array {
  let textEncoder = new util.TextEncoder();
  return textEncoder.encodeInto(str);
}

let userId: number = 100;
let query: asset.AssetMap = new Map();
query.set(asset.Tag.ALIAS, stringToArray('demo_alias'));
try {
  asset.queryAsUser(userId, query).then((res: Array<asset.AssetMap>) => {
    for (let i = 0; i < res.length; i++) {
      // parse the attribute.
      let accessibility: number = res[i].get(asset.Tag.ACCESSIBILITY) as number;
    }
    console.info(`Succeeded in querying Asset from user space.`);
  }).catch ((err: BusinessError) => {
    console.error(`Failed to query Asset from user space. Code is ${err.code}, message is ${err.message}`);
  });
} catch (error) {
  let err = error as BusinessError;
  console.error(`Failed to query Asset from user space. Code is ${err.code}, message is ${err.message}`);
}
```

## asset.postQueryAsUser

postQueryAsUser(userId: number, handle: AssetMap): Promise\<void>

在指定用户空间中查询的后置处理，用于需要用户认证的关键资产。需与[asset.preQueryAsUser](#assetprequeryasuser)函数成对出现。使用Promise方式异步返回结果。

**需要权限：** ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Security.Asset

**参数：**

| 参数名 | 类型     | 必填 | 说明                                                         |
| ------ | -------- | ---- | ------------------------------------------------------------ |
| userId | number                                | 是   | 用户ID。取值范围大于等于100。                                      |
| handle | [AssetMap](js-apis-asset.md#assetmap) | 是   | 待处理的查询句柄，当前包含[asset.preQueryAsUser](#assetprequeryasuser)执行成功返回的挑战值。 |

**返回值：**

| 类型          | 说明                    |
| ------------- | ----------------------- |
| Promise\<void> | Promise对象，无返回值。 |

**错误码：**

以下错误码的详细介绍请参见[关键资产存储服务错误码](errorcode-asset.md)

| 错误码ID | 错误信息                                                   |
| -------- | ---------------------------------------------------------- |
| 201      | The caller doesn't have the permission.                    |
| 202      | Non-system applications use system APIs.                   |
| 401      | Parameter error. Possible causes: <br> 1. Mandatory parameters are left unspecified. <br> 2. Incorrect parameter types. <br> 3. Parameter verification failed.           |
| 24000001 | The ASSET service is unavailable.                          |
| 24000006 | Insufficient memory.                                       |
| 24000010 | IPC failed.                                |
| 24000011 | Calling the Bundle Manager service failed. |
| 24000012 | Calling the OS Account service failed.     |
| 24000013 | Calling the Access Token service failed.   |

**示例：**

```typescript
import { asset } from '@kit.AssetStoreKit';
import { BusinessError } from '@kit.BasicServicesKit';

let userId: number = 100;
let handle: asset.AssetMap = new Map();
// 此处传入的new Uint8Array(32)仅作为示例，实际应传入asset.preQueryAsUser执行成功返回的挑战值
handle.set(asset.Tag.AUTH_CHALLENGE, new Uint8Array(32));
try {
  asset.postQueryAsUser(userId, handle).then(() => {
    console.info(`Succeeded in post-querying Asset from user space.`);
  }).catch ((err: BusinessError) => {
    console.error(`Failed to post-query Asset from user space. Code is ${err.code}, message is ${err.message}`);
  });
} catch (error) {
  let err = error as BusinessError;
  console.error(`Failed to post-query Asset from user space. Code is ${err.code}, message is ${err.message}`);
}
```