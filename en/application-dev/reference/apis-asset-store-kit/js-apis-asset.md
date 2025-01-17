# @ohos.security.asset (Asset Store Service)

The asset store service (ASSET) provides secure storage and management of sensitive data less than 1024 bytes in size, including passwords, app tokens, and other critical data (such as bank card numbers).

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```typescript
import { asset } from '@kit.AssetStoreKit';
```

## asset.add

add(attributes: AssetMap): Promise\<void>

Add an asset. This API uses a promise to return the result.

To set [IS_PERSISTENT](#tag), the application must have the ohos.permission.STORE_PERSISTENT_DATA permission.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Security.Asset

**Parameters**

| Name    | Type    | Mandatory| Description                                                        |
| ---------- | -------- | ---- | ------------------------------------------------------------ |
| attributes | [AssetMap](#assetmap) | Yes  | Attributes of the asset to add, including the asset plaintext, access control attributes, and custom data.|

**Return value**

| Type         | Description                   |
| ------------- | ----------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Asset Store Service Error Codes](errorcode-asset.md).

| ID| Error Message                                                  |
| -------- | ---------------------------------------------------------- |
| 201      | The caller doesn't have the permission.                    |
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

let attr: asset.AssetMap = new Map();
attr.set(asset.Tag.SECRET, stringToArray('demo_pwd'));
attr.set(asset.Tag.ALIAS, stringToArray('demo_alias'));
attr.set(asset.Tag.ACCESSIBILITY, asset.Accessibility.DEVICE_FIRST_UNLOCKED);
attr.set(asset.Tag.DATA_LABEL_NORMAL_1, stringToArray('demo_label'));
try {
  asset.add(attr).then(() => {
    console.info(`Asset added successfully.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to add Asset. Code is ${err.code}, message is ${err.message}`);
  })
} catch (error) {
  let err = error as BusinessError;
  console.error(`Failed to add Asset. Code is ${err.code}, message is ${err.message}`);
}
```

## asset.addSync<sup>12+</sup>

addSync(attributes: AssetMap): void

Add an asset. This API returns the result synchronously.

To set [IS_PERSISTENT](#tag), the application must have the ohos.permission.STORE_PERSISTENT_DATA permission.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Security.Asset

**Parameters**

| Name    | Type    | Mandatory| Description                                                        |
| ---------- | -------- | ---- | ------------------------------------------------------------ |
| attributes | [AssetMap](#assetmap) | Yes  | Attributes of the asset to add, including the asset plaintext, access control attributes, and custom data.|

**Error codes**

For details about the error codes, see [Asset Store Service Error Codes](errorcode-asset.md).

| ID| Error Message                                                  |
| -------- | ---------------------------------------------------------- |
| 201      | The caller doesn't have the permission.                    |
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

let attr: asset.AssetMap = new Map();
attr.set(asset.Tag.SECRET, stringToArray('demo_pwd'));
attr.set(asset.Tag.ALIAS, stringToArray('demo_alias'));
attr.set(asset.Tag.ACCESSIBILITY, asset.Accessibility.DEVICE_FIRST_UNLOCKED);
attr.set(asset.Tag.DATA_LABEL_NORMAL_1, stringToArray('demo_label'));
try {
  asset.addSync(attr);
} catch (error) {
  let err = error as BusinessError;
  console.error(`Failed to add Asset. Code is ${err.code}, message is ${err.message}`);
}
```

## asset.remove

remove(query: AssetMap): Promise\<void>

Removes one or more assets. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Security.Asset

**Parameters**

| Name| Type    | Mandatory| Description                                                  |
| ------ | -------- | ---- | ------------------------------------------------------ |
| query  | [AssetMap](#assetmap) | Yes  | Attributes of the asset to remove, such as the asset alias, access control attributes, and custom data.|

**Return value**

| Type         | Description                   |
| ------------- | ----------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Asset Store Service Error Codes](errorcode-asset.md).

| ID| Error Message                                                  |
| -------- | ---------------------------------------------------------- |
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

let query: asset.AssetMap = new Map();
query.set(asset.Tag.ALIAS, stringToArray('demo_alias'));
try {
  asset.remove(query).then(() => {
    console.info(`Asset removed successfully.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to remove Asset. Code is ${err.code}, message is ${err.message}`);
  });
} catch (error) {
  let err = error as BusinessError;
  console.error(`Failed to remove Asset. Code is ${err.code}, message is ${err.message}`);
}
```

## asset.removeSync<sup>12+</sup>

removeSync(query: AssetMap): void

Removes one or more assets. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Security.Asset

**Parameters**

| Name| Type    | Mandatory| Description                                                  |
| ------ | -------- | ---- | ------------------------------------------------------ |
| query  | [AssetMap](#assetmap) | Yes  | Attributes of the asset to remove, such as the asset alias, access control attributes, and custom data.|

**Error codes**

For details about the error codes, see [Asset Store Service Error Codes](errorcode-asset.md).

| ID| Error Message                                                  |
| -------- | ---------------------------------------------------------- |
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

let query: asset.AssetMap = new Map();
query.set(asset.Tag.ALIAS, stringToArray('demo_alias'));
try {
  asset.removeSync(query);
} catch (error) {
  let err = error as BusinessError;
  console.error(`Failed to remove Asset. Code is ${err.code}, message is ${err.message}`);
}
```

## asset.update

update(query: AssetMap, attributesToUpdate: AssetMap): Promise\<void>

Updates an asset. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Security.Asset

**Parameters**

| Name            | Type    | Mandatory| Description                                                        |
| ------------------ | -------- | ---- | ------------------------------------------------------------ |
| query              | [AssetMap](#assetmap) | Yes  | Attributes of the asset to update, such as the asset alias, access control attributes, and custom data.|
| attributesToUpdate | [AssetMap](#assetmap) | Yes  | New attributes of the asset, such as the asset plaintext and custom data.      |

**Return value**

| Type         | Description                   |
| ------------- | ----------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Asset Store Service Error Codes](errorcode-asset.md).

| ID| Error Message                                                  |
| -------- | ---------------------------------------------------------- |
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

let query: asset.AssetMap = new Map();
query.set(asset.Tag.ALIAS, stringToArray('demo_alias'));
let attrsToUpdate: asset.AssetMap = new Map();
attrsToUpdate.set(asset.Tag.SECRET, stringToArray('demo_pwd_new'));
try {
  asset.update(query, attrsToUpdate).then(() => {
    console.info(`Asset updated successfully.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to update Asset. Code is ${err.code}, message is ${err.message}`);
  });
} catch (error) {
  let err = error as BusinessError;
  console.error(`Failed to update Asset. Code is ${err.code}, message is ${err.message}`);
}
```

## asset.updateSync<sup>12+</sup>

updateSync(query: AssetMap, attributesToUpdate: AssetMap): void

Updates an asset. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Security.Asset

**Parameters**

| Name            | Type    | Mandatory| Description                                                        |
| ------------------ | -------- | ---- | ------------------------------------------------------------ |
| query              | [AssetMap](#assetmap) | Yes  | Attributes of the asset to update, such as the asset alias, access control attributes, and custom data.|
| attributesToUpdate | [AssetMap](#assetmap) | Yes  | New attributes of the asset, such as the asset plaintext and custom data.      |

**Error codes**

For details about the error codes, see [Asset Store Service Error Codes](errorcode-asset.md).

| ID| Error Message                                                  |
| -------- | ---------------------------------------------------------- |
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

let query: asset.AssetMap = new Map();
query.set(asset.Tag.ALIAS, stringToArray('demo_alias'));
let attrsToUpdate: asset.AssetMap = new Map();
attrsToUpdate.set(asset.Tag.SECRET, stringToArray('demo_pwd_new'));
try {
  asset.updateSync(query, attrsToUpdate);
} catch (error) {
  let err = error as BusinessError;
  console.error(`Failed to update Asset. Code is ${err.code}, message is ${err.message}`);
}
```

## asset.preQuery

preQuery(query: AssetMap): Promise\<Uint8Array>

Performs preprocessing for the asset query. This API is used when user authentication is required for the access to the asset. After the user authentication is successful, call [asset.query](#assetquery) and [asset.postQuery](#assetpostquery). This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Security.Asset

**Parameters**

| Name| Type    | Mandatory| Description                                                  |
| ------ | -------- | ---- | ------------------------------------------------------ |
| query  | [AssetMap](#assetmap) | Yes  | Attributes of the asset to query, such as the asset alias, access control attributes, and custom data.|

**Return value**

| Type               | Description                                                 |
| ------------------- | ----------------------------------------------------- |
| Promise\<Uint8Array> | Promise used to return a challenge value.<br>**NOTE**: The challenge value is used for subsequent user authentication.|

**Error codes**

For details about the error codes, see [Asset Store Service Error Codes](errorcode-asset.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
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

let query: asset.AssetMap = new Map();
query.set(asset.Tag.ALIAS, stringToArray('demo_alias'));
try {
  asset.preQuery(query).then((challenge: Uint8Array) => {
    console.info(`Succeeded in pre-querying Asset.`);
  }).catch ((err: BusinessError) => {
    console.error(`Failed to pre-query Asset. Code is ${err.code}, message is ${err.message}`);
  });
} catch (error) {
  let err = error as BusinessError;
  console.error(`Failed to pre-query Asset. Code is ${err.code}, message is ${err.message}`);
}
```

## asset.preQuerySync<sup>12+</sup>

preQuerySync(query: AssetMap): Uint8Array

Performs preprocessing for the asset query. This API is used when user authentication is required for the access to the asset. After the user authentication is successful, call [asset.querySync](#assetquerysync12) and [asset.postQuerySync](#assetpostquerysync12). This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Security.Asset

**Parameters**

| Name| Type    | Mandatory| Description                                                  |
| ------ | -------- | ---- | ------------------------------------------------------ |
| query  | [AssetMap](#assetmap) | Yes  | Attributes of the asset to query, such as the asset alias, access control attributes, and custom data.|

**Return value**

| Type               | Description                                                 |
| ------------------- | ----------------------------------------------------- |
| Uint8Array | Challenge value.<br>**NOTE**: The challenge value is used for subsequent user authentication.|

**Error codes**

For details about the error codes, see [Asset Store Service Error Codes](errorcode-asset.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
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

let query: asset.AssetMap = new Map();
query.set(asset.Tag.ALIAS, stringToArray('demo_alias'));
try {
  let challenge: Uint8Array = asset.preQuerySync(query);
} catch (error) {
  let err = error as BusinessError;
  console.error(`Failed to pre-query Asset. Code is ${err.code}, message is ${err.message}`);
}
```

## asset.query

query(query: AssetMap): Promise\<Array\<AssetMap>>

Queries one or more assets. If user authentication is required for the access to the asset, call [asset.preQuery](#assetprequery) before this API and call [asset.postQuery](#assetpostquery) after this API. For details about the development procedure, see [Querying an Asset with User Authentication](../../security/AssetStoreKit/asset-js-query-auth.md). This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Security.Asset

**Parameters**

| Name  | Type                           | Mandatory| Description                                                        |
| -------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| query    | [AssetMap](#assetmap)           | Yes  | Attributes of the asset to query, such as the asset alias, access control attributes, and custom data.      |

**Return value**

| Type                    | Description                                 |
| ------------------------ | ------------------------------------- |
| Promise\<Array\<AssetMap>> | Promise used to return the result obtained.|

**Error codes**

For details about the error codes, see [Asset Store Service Error Codes](errorcode-asset.md).

| ID| Error Message                                                  |
| -------- | ---------------------------------------------------------- |
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

let query: asset.AssetMap = new Map();
query.set(asset.Tag.ALIAS, stringToArray('demo_alias'));
try {
  asset.query(query).then((res: Array<asset.AssetMap>) => {
    for (let i = 0; i < res.length; i++) {
      // parse the attribute.
      let accessibility: number = res[i].get(asset.Tag.ACCESSIBILITY) as number;
    }
    console.info(`Asset query succeeded.`);
  }).catch ((err: BusinessError) => {
    console.error(`Failed to query Asset. Code is ${err.code}, message is ${err.message}`);
  });
} catch (error) {
  let err = error as BusinessError;
  console.error(`Failed to query Asset. Code is ${err.code}, message is ${err.message}`);
}
```

## asset.querySync<sup>12+</sup>

querySync(query: AssetMap): Array\<AssetMap>

Queries one or more assets. If user authentication is required for the access to the asset, call [asset.preQuerySync](#assetprequerysync12) before this API and call [asset.postQuerySync](#assetpostquerysync12) after this API. For details about the development procedure, see [Querying an Asset with User Authentication](../../security/AssetStoreKit/asset-js-query-auth.md). This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Security.Asset

**Parameters**

| Name  | Type                           | Mandatory| Description                                                        |
| -------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| query    | [AssetMap](#assetmap)           | Yes  | Attributes of the asset to query, such as the asset alias, access control attributes, and custom data.      |

**Return value**

| Type                    | Description                                 |
| ------------------------ | ------------------------------------- |
| Array\<AssetMap> | Array of query results.|

**Error codes**

For details about the error codes, see [Asset Store Service Error Codes](errorcode-asset.md).

| ID| Error Message                                                  |
| -------- | ---------------------------------------------------------- |
| 401      | Parameter error. Possible causes: <br> 1. Incorrect parameter types.  <br> 2. Parameter verification failed. |
| 24000001 | The ASSET service is unavailable.                          |
| 24000002 | The asset is not found.                        |
| 24000004 | Access denied.                            |
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

let query: asset.AssetMap = new Map();
query.set(asset.Tag.ALIAS, stringToArray('demo_alias'));
try {
  let res: Array<asset.AssetMap> = asset.querySync(query);
  let accessibility: number;
  for (let i = 0; i < res.length; i++) {
    // parse the attribute.
    if (res[i] != null) {
      accessibility = res[i].get(asset.Tag.ACCESSIBILITY) as number;
    }
  }
} catch (error) {
  let err = error as BusinessError;
  console.error(`Failed to query Asset. Code is ${err.code}, message is ${err.message}`);
}
```

## asset.postQuery

postQuery(handle: AssetMap): Promise\<void>

Performs postprocessing for the asset query. This API is used when user authentication is required for the access to the asset. This API must be used with [asset.preQuery](#assetprequery) together. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Security.Asset

**Parameters**

| Name| Type    | Mandatory| Description                                                        |
| ------ | -------- | ---- | ------------------------------------------------------------ |
| handle | [AssetMap](#assetmap) | Yes  | Handle of the query operation, including the challenge value returned by [asset.preQuery](#assetprequery).|

**Return value**

| Type         | Description                   |
| ------------- | ----------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Asset Store Service Error Codes](errorcode-asset.md).

| ID| Error Message                                                  |
| -------- | ---------------------------------------------------------- |
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

let handle: asset.AssetMap = new Map();
// The new Uint8Array(32) is only an example. Pass in the challenge value returned by asset.preQuery.
handle.set(asset.Tag.AUTH_CHALLENGE, new Uint8Array(32));
try {
  asset.postQuery(handle).then(() => {
    console.info(`Succeeded in post-querying Asset.`);
  }).catch ((err: BusinessError) => {
    console.error(`Failed to post-query Asset. Code is ${err.code}, message is ${err.message}`);
  });
} catch (error) {
  let err = error as BusinessError;
  console.error(`Failed to post-query Asset. Code is ${err.code}, message is ${err.message}`);
}
```

## asset.postQuerySync<sup>12+</sup>

postQuerySync(handle: AssetMap): void

Performs postprocessing for the asset query. This API is used when user authentication is required for the access to the asset. This API must be used with [asset.preQuerySync](#assetprequerysync12) together. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Security.Asset

**Parameters**

| Name| Type    | Mandatory| Description                                                        |
| ------ | -------- | ---- | ------------------------------------------------------------ |
| handle | [AssetMap](#assetmap) | Yes  | Handle of the query operation, including the challenge value returned by [asset.preQuerySync](#assetprequerysync12).|

**Error codes**

For details about the error codes, see [Asset Store Service Error Codes](errorcode-asset.md).

| ID| Error Message                                                  |
| -------- | ---------------------------------------------------------- |
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

let handle: asset.AssetMap = new Map();
// The new Uint8Array(32) is only an example. Pass in the challenge value returned by asset.preQuerySync.
handle.set(asset.Tag.AUTH_CHALLENGE, new Uint8Array(32));
try {
  asset.postQuerySync(handle)
} catch (error) {
  let err = error as BusinessError;
  console.error(`Failed to post-query Asset. Code is ${err.code}, message is ${err.message}`);
}
```

## TagType

Enumerates the asset attribute types.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Security.Asset

| Name  | Value        | Description                                    |
| ------ | ---------- | ---------------------------------------- |
| BOOL   | 0x01 << 28 | Boolean.    |
| NUMBER | 0x02 << 28 | Number.    |
| BYTES  | 0x03 << 28 | Byte array.|

## Tag

Enumerate the keys of asset attributes ([AssetMap](#assetmap)), which are in key-value (KV) pairs.

**System capability**: SystemCapability.Security.Asset

> **NOTE**
>
> The following table lists all enums of **Tag**. The specific tags and the value range of tag values vary with the API you use. For details, see [Introduction to Asset Store Kit](../../security/AssetStoreKit/asset-store-kit-overview.md).

| Name| Value                                 | Description                                                        |
| ------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| SECRET                    | TagType.BYTES &#124; 0x01  | Asset plaintext.<br>**Atomic service API**: This API can be used in atomic services since API version 14.                                                |
| ALIAS                     | TagType.BYTES &#124; 0x02 | Asset alias, which uniquely identifies an asset.<br>**Atomic service API**: This API can be used in atomic services since API version 14.                        |
| ACCESSIBILITY             | TagType.NUMBER &#124; 0x03 | Access control based on the lock screen status.<br>**Atomic service API**: This API can be used in atomic services since API version 14.                                      |
| REQUIRE_PASSWORD_SET      | TagType.BOOL &#124 0x04                   | Whether the asset is accessible only when a lock screen password is set.<br>**Atomic service API**: This API can be used in atomic services since API version 14.                |
| AUTH_TYPE                 | TagType.NUMBER &#124; 0x05 | Type of user authentication required for accessing the asset.<br>**Atomic service API**: This API can be used in atomic services since API version 14.                              |
| AUTH_VALIDITY_PERIOD      | TagType.NUMBER &#124; 0x06 | Validity period of the user authentication.<br>**Atomic service API**: This API can be used in atomic services since API version 14.                                            |
| AUTH_CHALLENGE            | TagType.BYTES &#124; 0x07     | Challenge for the user authentication.<br>**Atomic service API**: This API can be used in atomic services since API version 14.                                        |
| AUTH_TOKEN                | TagType.BYTES &#124; 0x08    | Authorization token obtained after the user authentication is successful.<br>**Atomic service API**: This API can be used in atomic services since API version 14.                                          |
| SYNC_TYPE                 | TagType.NUMBER &#124; 0x10 | Asset sync type.<br>**Atomic service API**: This API can be used in atomic services since API version 14.                                      |
| IS_PERSISTENT             | TagType.BOOL &#124; 0x11                         | Whether to retain the asset when the application is uninstalled.|
| DATA_LABEL_CRITICAL_1     | TagType.BYTES &#124; 0x20 | Additional asset data customized by the service with integrity protection.<br>**Atomic service API**: This API can be used in atomic services since API version 14.            |
| DATA_LABEL_CRITICAL_2 | TagType.BYTES &#124; 0x21 | Additional asset data customized by the service with integrity protection.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
| DATA_LABEL_CRITICAL_3 | TagType.BYTES &#124; 0x22 | Additional asset data customized by the service with integrity protection.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
| DATA_LABEL_CRITICAL_4 | TagType.BYTES &#124; 0x23  | Additional asset data customized by the service with integrity protection.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
| DATA_LABEL_NORMAL_1       | TagType.BYTES &#124; 0x30 | Additional asset data customized by the service without integrity protection.<br>**Atomic service API**: This API can be used in atomic services since API version 14.            |
| DATA_LABEL_NORMAL_2 | TagType.BYTES &#124; 0x31 | Additional asset data customized by the service without integrity protection.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
| DATA_LABEL_NORMAL_3 | TagType.BYTES &#124; 0x32 | Additional asset data customized by the service without integrity protection.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
| DATA_LABEL_NORMAL_4 | TagType.BYTES &#124; 0x33  | Additional asset data customized by the service without integrity protection.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
| DATA_LABEL_NORMAL_LOCAL_1<sup>12+</sup> | TagType.BYTES &#124; 0x34 | Local information about the asset. The value is assigned by the service without integrity protection and will not be synced.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
| DATA_LABEL_NORMAL_LOCAL_2<sup>12+</sup> | TagType.BYTES &#124; 0x35 | Local information about the asset. The value is assigned by the service without integrity protection and will not be synced.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
| DATA_LABEL_NORMAL_LOCAL_3<sup>12+</sup> | TagType.BYTES &#124; 0x36 | Local information about the asset. The value is assigned by the service without integrity protection and will not be synced.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
| DATA_LABEL_NORMAL_LOCAL_4<sup>12+</sup> | TagType.BYTES &#124; 0x37 | Local information about the asset. The value is assigned by the service without integrity protection and will not be synced.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
| RETURN_TYPE               | TagType.NUMBER &#124; 0x40 | Type of the asset query result to return.<br>**Atomic service API**: This API can be used in atomic services since API version 14.                                        |
| RETURN_LIMIT              | TagType.NUMBER &#124; 0x41                      | Maximum number of asset records to return.<br>**Atomic service API**: This API can be used in atomic services since API version 14.                                        |
| RETURN_OFFSET             | TagType.NUMBER &#124; 0x42   | Offset of the asset query result.<br>**NOTE**: This parameter specifies the starting asset record to return in batch asset query.<br>**Atomic service API**: This API can be used in atomic services since API version 14.                                |
| RETURN_ORDERED_BY         | TagType.NUMBER &#124; 0x43 | Sorting order of the query results. Currently, the results can be sorted only by **ASSET_TAG_DATA_LABEL**.<br>**NOTE**: By default, assets are returned in the order in which they are added.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
| CONFLICT_RESOLUTION       | TagType.NUMBER &#124; 0x44 | Policy for resolving the conflict (for example, a duplicate alias).<br>**Atomic service API**: This API can be used in atomic services since API version 14.                            |
| UPDATE_TIME<sup>12+</sup> | TagType.BYTES &#124; 0x45 | Data update time, in timestamp.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
| OPERATION_TYPE<sup>12+</sup> | TagType.NUMBER &#124; 0x46 | Additional operation type.|
| REQUIRE_ATTR_ENCRYPTED<sup>14+</sup> | TagType.BOOL &#124; 0x47 | Whether to encrypt the additional asset information customized by the service.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
| GROUP_ID<sup>16+</sup> | TagType.BYTES &#124; 0x48 | Group to which the asset belongs.|

## Value

type Value = boolean | number | Uint8Array;

Represents the value of each attribute in [AssetMap](#assetmap).

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Security.Asset

| Type   | Description                                            |
| ------- | ------------------------------------------------|
| boolean | The value is a Boolean value, that is, **true** or **false**.     |
| number  | The value is a number. It can be an enumerated value or a numeric value.|
| Uint8Array | The value is a byte array, and the content is defined by the service.       |

## AssetMap

type AssetMap = Map\<Tag, Value>

Represents a set of asset attributes in the form of KV pairs.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Security.Asset

| Type            | Description                                                             |
| ---------------- | ------------------------------------------------------------------|
| Map\<Tag, Value> | The value type is Map. For details about the range of the KV pair, see [Tag](#tag) and [Value](#value).|

## Accessibility

Enumerates the types of access control based on the lock screen status.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Security.Asset

| Name                 | Value  | Description                                                        |
| --------------------- | ---- | ------------------------------------------------------------ |
| DEVICE_POWERED_ON     | 0    | The asset can be accessed after the device is powered on.                                  |
| DEVICE_FIRST_UNLOCKED | 1    | The asset can be accessed only after the device is unlocked for the first time.<br>**NOTE**: If no lock screen password is set, this option is equivalent to **DEVICE_POWERED_ON**.|
| DEVICE_UNLOCKED       | 2    | The asset can be accessed only when the device is unlocked.<br>**NOTE**: If no lock screen password is set, this option is equivalent to **DEVICE_POWERED_ON**.|

## AuthType

Enumerates the types of user authentication supported by an asset.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Security.Asset

| Name| Value  | Description                                                        |
| ---- | ---- | ------------------------------------------------------------ |
| NONE | 0    | No user authentication is required before the asset is accessed.                                |
| ANY  | 255  | The asset can be accessed if any user authentication (such as PIN, facial, or fingerprint authentication) is successful.|

## SyncType

Enumerates the sync types supported by an asset.

> **NOTE**
>
> This field is an embedded parameter. Currently, asset sync is not supported.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Security.Asset

| Name                         | Value    | Description                                            |
| ----------------------------- | ------ | ------------------------------------------------ |
| NEVER                         | 0      | Asset sync is not allowed.                            |
| THIS_DEVICE                   | 1 << 0 | Asset sync is allowed only on the local device, for example, in data restore on the local device.|
| TRUSTED_DEVICE                | 1 << 1 | Asset sync is allowed only between trusted devices, for example, in the case of cloning.            |
| TRUSTED_ACCOUNT<sup>12+</sup> | 1 << 2 | Asset sync is allowed only between the devices that are logged in with trusted accounts, for example, in cloud sync scenarios.|

## ReturnType

Enumerates the type of information returned by an asset query operation.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Security.Asset

| Name      | Value  | Description                                                        |
| ---------- | ---- | ------------------------------------------------------------ |
| ALL        | 0    | The query result contains the asset plaintext and its attributes.<br>**NOTE**: Use this option when you need to query the plaintext of a single asset.|
| ATTRIBUTES | 1    | The query result contains only the asset attributes.<br>**NOTE**: Use this option when you need to query attributes of multiple assets.|

## ConflictResolution

Enumerates the policies for resolving conflicts (for example, a duplicate alias) when an asset is added.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Security.Asset

| Name       | Value  | Description                        |
| ----------- | ---- | ---------------------------- |
| OVERWRITE   | 0    | Overwrite the original asset.   |
| THROW_ERROR | 1    | Throw an exception for the service to perform subsequent processing.|

## OperationType<sup>12+</sup>

Enumerates the types of additional operation to perform.

**System capability**: SystemCapability.Security.Asset

| Name       | Value  | Description              |
| ----------- | ---- | ------------------ |
| NEED_SYNC   | 0    | Sync.|
| NEED_LOGOUT | 1    | Logout.|

## ErrorCode

Enumerates the error codes.

**System capability**: SystemCapability.Security.Asset

| Name                      | Value   | Description|
| -------------------------- | ----- | ---- |
| PERMISSION_DENIED | 201     |The caller does not have the permission.|
| NOT_SYSTEM_APPLICATION<sup>12+</sup> | 202     |The caller is not a system application.|
| INVALID_ARGUMENT | 401    |Incorrect parameters are detected.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
| SERVICE_UNAVAILABLE | 24000001    |The asset store service is unavailable.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
| NOT_FOUND | 24000002    |Failed to find the asset.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
| DUPLICATED | 24000003    |The specified asset already exists.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
| ACCESS_DENIED | 24000004    |The access to the asset is denied.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
| STATUS_MISMATCH | 24000005    |The screen lock status does not match.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
| OUT_OF_MEMORY | 24000006    |The system memory is insufficient.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
| DATA_CORRUPTED | 24000007    |The asset is corrupted.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
| DATABASE_ERROR | 24000008   |The database operation failed.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
| CRYPTO_ERROR | 24000009   |The crypto operation failed.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
| IPC_ERROR | 24000010   |IPC failed.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
| BMS_ERROR | 24000011   |The Bundle Manager service is abnormal.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
| ACCOUNT_ERROR | 24000012   |The account service is abnormal.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
| ACCESS_TOKEN_ERROR | 24000013   |The Access Token service is abnormal.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
| FILE_OPERATION_ERROR | 24000014   |The file operation failed.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
| GET_SYSTEM_TIME_ERROR | 24000015   |Failed to obtain the system time.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
| LIMIT_EXCEEDED | 24000016   |The number of cached records exceeds the upper limit.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
| UNSUPPORTED | 24000017   |The feature is not supported.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
