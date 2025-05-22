# @ohos.security.asset (Asset Store Service) (System API)

The asset store service (ASSET) provides secure storage and management of sensitive data less than 1024 bytes in size, including passwords, app tokens, and other critical data (such as bank card numbers).

> **NOTE**
>
> - The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - This topic describes only the system APIs provided by the module. For details about its public APIs, see [ohos.security.asset (Asset Store Service)](js-apis-asset.md).

## Modules to Import

```typescript
import { asset } from '@kit.AssetStoreKit';
```

## asset.addAsUser

addAsUser(userId: number, attributes: AssetMap): Promise\<void>

Adds an asset to the specified user space. This API uses a promise to return the result.

To set [IS_PERSISTENT](js-apis-asset.md#tag), the application must have the ohos.permission.STORE_PERSISTENT_DATA permission.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Security.Asset

**Parameters**

| Name    | Type    | Mandatory| Description                                                        |
| ---------- | -------- | ---- | ------------------------------------------------------------ |
| userId     | number                                | Yes  | User ID.                                                          |
| attributes | [AssetMap](js-apis-asset.md#assetmap) | Yes  | Attributes of the asset to add, including the asset plaintext, access control attributes, and custom data.|

**Return value**

| Type         | Description                   |
| ------------- | ----------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Asset Store Service Error Codes](errorcode-asset.md).

| ID| Error Message                                                  |
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

**Example**

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

Removes one or more assets from the specified user space. This API uses a promise to return the result.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Security.Asset

**Parameters**

| Name| Type    | Mandatory| Description                                                  |
| ------ | -------- | ---- | ------------------------------------------------------ |
| userId | number                                | Yes  | User ID.                                                 |
| query  | [AssetMap](js-apis-asset.md#assetmap) | Yes  | Attributes of the asset to remove, such as the asset alias, access control attributes, and custom data.|

**Return value**

| Type         | Description                   |
| ------------- | ----------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Asset Store Service Error Codes](errorcode-asset.md).

| ID| Error Message                                                  |
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

**Example**

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

Updates an asset in the specified user space. This API uses a promise to return the result.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Security.Asset

**Parameters**

| Name            | Type    | Mandatory| Description                                                        |
| ------------------ | -------- | ---- | ------------------------------------------------------------ |
| userId             | number                                | Yes  | User ID.                                                        |
| query              | [AssetMap](js-apis-asset.md#assetmap) | Yes  | Attributes of the asset to update, such as the asset alias, access control attributes, and custom data.|
| attributesToUpdate | [AssetMap](js-apis-asset.md#assetmap) | Yes  | New attributes of the asset, such as the asset plaintext and custom data.             |

**Return value**

| Type         | Description                   |
| ------------- | ----------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Asset Store Service Error Codes](errorcode-asset.md).

| ID| Error Message                                                  |
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

**Example**

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

Performs preprocessing for the asset query in the specified user space. This API is used when user authentication is required for the access to an asset. After the user authentication is successful, call [asset.queryAsUser](#assetqueryasuser) and [asset.postQueryAsUser](#assetpostqueryasuser). This API uses a promise to return the result.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Security.Asset

**Parameters**

| Name| Type    | Mandatory| Description                                                  |
| ------ | -------- | ---- | ------------------------------------------------------ |
| userId | number                                | Yes  | User ID.                                           |
| query  | [AssetMap](js-apis-asset.md#assetmap) | Yes  | Conditions for querying the asset, such as the asset aliases, access control attributes, and custom data.|

**Return value**

| Type               | Description                                                 |
| ------------------- | ----------------------------------------------------- |
| Promise\<Uint8Array> | Promise used to return a challenge value.<br>**NOTE**: The challenge value is used for subsequent user authentication.|

**Error codes**

For details about the error codes, see [Asset Store Service Error Codes](errorcode-asset.md).

| ID| Error Message                                                    |
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

**Example**

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

Queries one or more assets in the specified user space. If user authentication is required for the access to the asset, call [asset.preQueryAsUser](#assetprequeryasuser) before this API and call [asset.postQueryAsUser](#assetpostqueryasuser) after this API. For details about the development procedure, see [Querying an Asset with User Authentication](../../security/AssetStoreKit/asset-js-query-auth.md). This API uses a promise to return the result.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Security.Asset

**Parameters**

| Name  | Type                           | Mandatory| Description                                                        |
| -------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| userId   | number                                          | Yes  | User ID.                                                 |
| query    | [AssetMap](js-apis-asset.md#assetmap)           | Yes  | Conditions for querying the asset, such as the asset aliases, access control attributes, and custom data.      |

**Return value**

| Type                    | Description                                 |
| ------------------------ | ------------------------------------- |
| Promise\<Array\<AssetMap>> | Promise used to return the result obtained.|

**Error codes**

For details about the error codes, see [Asset Store Service Error Codes](errorcode-asset.md).

| ID| Error Message                                                  |
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

**Example**

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

Performs postprocessing for the asset query in the specified user space. This API is used when user authentication is required for the access to the asset. This API must be used with [asset.preQueryAsUser](#assetprequeryasuser) together. This API uses a promise to return the result.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Security.Asset

**Parameters**

| Name| Type    | Mandatory| Description                                                        |
| ------ | -------- | ---- | ------------------------------------------------------------ |
| userId | number                                | Yes  | User ID.                                                                    |
| handle | [AssetMap](js-apis-asset.md#assetmap) | Yes  | Handle of the query operation, including the challenge value returned by [asset.preQueryAsUser](#assetprequeryasuser).|

**Return value**

| Type         | Description                   |
| ------------- | ----------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Asset Store Service Error Codes](errorcode-asset.md).

| ID| Error Message                                                  |
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

**Example**

```typescript
import { asset } from '@kit.AssetStoreKit';
import { BusinessError } from '@kit.BasicServicesKit';

let userId: number = 100;
let handle: asset.AssetMap = new Map();
// The new Uint8Array(32) is only an example. Pass in the challenge value returned by asset.preQueryAsUser.
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
