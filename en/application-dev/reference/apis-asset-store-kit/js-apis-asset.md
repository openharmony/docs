# @ohos.security.asset (Asset Store Service)

<!--Kit: Asset Store Kit-->
<!--Subsystem: Security-->
<!--Owner: @HarMonkey-->
<!--Designer: @wkr321_ent-->
<!--Tester: @nacyli-->
<!--Adviser: @zengyawen-->
<!-- md-trans-meta sourceCommit=8c92e73a9c5f77cd051558427dd3b1470296ac9f translatedAt=2026-08-18T15:28:13.026Z pushedAt=2026-08-19T01:52:36.003Z -->

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

Adds an asset. This API uses a promise to return the result.

To set the [Tag.IS_PERSISTENT](#tag) attribute, you need to request the ohos.permission.STORE_PERSISTENT_DATA permission. For details about how to request the permission, see [Declared Permission](../../security/AccessToken/declare-permissions.md).

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Asset Store Service Error Codes](errorcode-asset.md).

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

function stringToArray(str: string): Uint8Array {
  let textEncoder = new util.TextEncoder();
  return textEncoder.encodeInto(str);
}

let attr: asset.AssetMap = new Map();
attr.set(asset.Tag.SECRET, stringToArray('demo_pwd'));
attr.set(asset.Tag.ALIAS, stringToArray('demo_alias'));
attr.set(asset.Tag.ACCESSIBILITY, asset.Accessibility.DEVICE_FIRST_UNLOCKED);
attr.set(asset.Tag.DATA_LABEL_NORMAL_1, stringToArray('demo_label'));
asset.add(attr).then(() => {
  console.info(`Succeeded in adding Asset.`);
});
```

## asset.addSync<sup>12+</sup>

addSync(attributes: AssetMap): void

Add an asset. This API returns the result synchronously.

To set the [Tag.IS_PERSISTENT](#tag) attribute, you need to request the ohos.permission.STORE_PERSISTENT_DATA permission. For details about how to request the permission, see [Declared Permission](../../security/AccessToken/declare-permissions.md).

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Security.Asset

**Parameters**

| Name    | Type    | Mandatory| Description                                                        |
| ---------- | -------- | ---- | ------------------------------------------------------------ |
| attributes | [AssetMap](#assetmap) | Yes  | Attributes of the asset to add, including the asset plaintext, access control attributes, and custom data.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Asset Store Service Error Codes](errorcode-asset.md).

| ID | Error Message                                                    |
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

function stringToArray(str: string): Uint8Array {
  let textEncoder = new util.TextEncoder();
  return textEncoder.encodeInto(str);
}

let attr: asset.AssetMap = new Map();
attr.set(asset.Tag.SECRET, stringToArray('demo_pwd'));
attr.set(asset.Tag.ALIAS, stringToArray('demo_alias'));
attr.set(asset.Tag.ACCESSIBILITY, asset.Accessibility.DEVICE_FIRST_UNLOCKED);
attr.set(asset.Tag.DATA_LABEL_NORMAL_1, stringToArray('demo_label'));
asset.addSync(attr);
```

## asset.batchAdd

batchAdd(attributesArray: Array\<AssetMap>): Promise\<BatchResult>

Batch inserts assets. This API uses a promise to return the result.

To set the [Tag.IS_PERSISTENT](#tag) attribute, you need to request the ohos.permission.STORE_PERSISTENT_DATA permission. For details about how to request the permission, see [Declared Permission](../../security/AccessToken/declare-permissions.md).

The assets to be batch inserted must have the same [Tag.GROUP_ID](#tag) and [Tag.REQUIRE_ATTR_ENCRYPTED](#tag) attributes.

The maximum number of assets that can be batch inserted is 100.

**Since**: 26.0.0

**System capability:** SystemCapability.Security.Asset

**Parameters**

| Name     | Type     | Mandatory | Description                                                         |
| ---------- | -------- | ---- | ------------------------------------------------------------ |
| attributesArray | Array\<[AssetMap](#assetmap)> | Yes   | Array of attribute sets of the assets to be inserted, including the asset plaintext, access control attributes, custom data, and so on. The maximum length of the array is 100. |

**Return value**

| Type          | Description                    |
| ------------- | ----------------------- |
| Promise\<[BatchResult](#batchresult)> | Promise used to return the batch operation result, which contains the error information of the failed assets. |

**Error codes**

For details about the error codes, see [Asset Store Service Error Codes](errorcode-asset.md).

| ID| Error Message                                                  |
| -------- | ---------------------------------------------------------- |
| 24000001 | The ASSET service is unavailable.                          |
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
| 24000019 | Each value of [Tag.GROUP_ID](#tag) and [Tag.REQUIRE_ATTR_ENCRYPTED](#tag) in the array is not consistent. |

**Example**

```typescript
import { asset } from '@kit.AssetStoreKit';
import { util } from '@kit.ArkTS';

function stringToArray(str: string): Uint8Array {
  let textEncoder = new util.TextEncoder();
  return textEncoder.encodeInto(str);
}

let attributesArray: Array<asset.AssetMap> = [];
let attr1: asset.AssetMap = new Map();
attr1.set(asset.Tag.SECRET, stringToArray('demo_pwd1'));
attr1.set(asset.Tag.ALIAS, stringToArray('demo_alias1'));
attr1.set(asset.Tag.ACCESSIBILITY, asset.Accessibility.DEVICE_FIRST_UNLOCKED);
attributesArray.push(attr1);

let attr2: asset.AssetMap = new Map();
attr2.set(asset.Tag.SECRET, stringToArray('demo_pwd2'));
attr2.set(asset.Tag.ALIAS, stringToArray('demo_alias2'));
attr2.set(asset.Tag.ACCESSIBILITY, asset.Accessibility.DEVICE_FIRST_UNLOCKED);
attributesArray.push(attr2);

asset.batchAdd(attributesArray).then((res: asset.BatchResult) => {
  console.info(`Succeeded in batch adding Asset, failedCount: ${res.failedCount}`);
});
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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Asset Store Service Error Codes](errorcode-asset.md).

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

function stringToArray(str: string): Uint8Array {
  let textEncoder = new util.TextEncoder();
  return textEncoder.encodeInto(str);
}

let query: asset.AssetMap = new Map();
query.set(asset.Tag.ALIAS, stringToArray('demo_alias'));
asset.remove(query).then(() => {
  console.info(`Succeeded in removing Asset.`);
});
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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Asset Store Service Error Codes](errorcode-asset.md).

| ID | Error Message                                                    |
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

function stringToArray(str: string): Uint8Array {
  let textEncoder = new util.TextEncoder();
  return textEncoder.encodeInto(str);
}

let query: asset.AssetMap = new Map();
query.set(asset.Tag.ALIAS, stringToArray('demo_alias'));
asset.removeSync(query);
```

## asset.batchRemove

batchRemove(assetsToBeRemoved: Array\<AssetMap>): Promise\<void>

Batch deletes the assets that meet the conditions. This API uses a promise to return the result.

The assets to be batch deleted must have the same [Tag.GROUP_ID](#tag) and [Tag.REQUIRE_ATTR_ENCRYPTED](#tag) attributes.

The maximum number of assets that can be batch deleted is 100.

**Since**: 26.0.0

**System capability:** SystemCapability.Security.Asset

**Parameters**

| Name     | Type     | Mandatory | Description                                                         |
| ---------- | -------- | ---- | ------------------------------------------------------------ |
| assetsToBeRemoved | Array\<[AssetMap](#assetmap)> | Yes   | Array of search conditions of the assets to be deleted, such as the alias, access control attributes, custom data, and so on. The maximum length of the array is 100. |

**Return value**

| Type          | Description                    |
| ------------- | ----------------------- |
| Promise\<void> | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Asset Store Service Error Codes](errorcode-asset.md).

| ID| Error Message                                                  |
| -------- | ---------------------------------------------------------- |
| 24000001 | The ASSET service is unavailable.                          |
| 24000006 | Insufficient memory.                                       |
| 24000007 | The asset is corrupted.                                    |
| 24000008 | The database operation failed.                          |
| 24000010 | IPC failed.                                |
| 24000011 | Calling the Bundle Manager service failed. |
| 24000012 | Calling the OS Account service failed.     |
| 24000013 | Calling the Access Token service failed.   |
| 24000015 | Getting the system time failed.            |
| 24000019 | Each value of [Tag.GROUP_ID](#tag) and [Tag.REQUIRE_ATTR_ENCRYPTED](#tag) in the array is not consistent. |

**Example**

```typescript
import { asset } from '@kit.AssetStoreKit';
import { util } from '@kit.ArkTS';

function stringToArray(str: string): Uint8Array {
  let textEncoder = new util.TextEncoder();
  return textEncoder.encodeInto(str);
}

let assetsToBeRemoved: Array<asset.AssetMap> = [];
let query1: asset.AssetMap = new Map();
query1.set(asset.Tag.ALIAS, stringToArray('demo_alias1'));
assetsToBeRemoved.push(query1);

let query2: asset.AssetMap = new Map();
query2.set(asset.Tag.ALIAS, stringToArray('demo_alias2'));
assetsToBeRemoved.push(query2);

asset.batchRemove(assetsToBeRemoved).then(() => {
  console.info(`Succeeded in batch removing Asset.`);
});
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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Asset Store Service Error Codes](errorcode-asset.md).

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

function stringToArray(str: string): Uint8Array {
  let textEncoder = new util.TextEncoder();
  return textEncoder.encodeInto(str);
}

let query: asset.AssetMap = new Map();
query.set(asset.Tag.ALIAS, stringToArray('demo_alias'));
let attrsToUpdate: asset.AssetMap = new Map();
attrsToUpdate.set(asset.Tag.SECRET, stringToArray('demo_pwd_new'));
asset.update(query, attrsToUpdate).then(() => {
  console.info(`Succeeded in updating Asset.`);
});
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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Asset Store Service Error Codes](errorcode-asset.md).

| ID | Error Message                                                    |
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

function stringToArray(str: string): Uint8Array {
  let textEncoder = new util.TextEncoder();
  return textEncoder.encodeInto(str);
}

let query: asset.AssetMap = new Map();
query.set(asset.Tag.ALIAS, stringToArray('demo_alias'));
let attrsToUpdate: asset.AssetMap = new Map();
attrsToUpdate.set(asset.Tag.SECRET, stringToArray('demo_pwd_new'));
asset.updateSync(query, attrsToUpdate);
```

## asset.batchUpdate

batchUpdate(sourceAttributes: Array\<AssetMap>, destAttributes: Array\<AssetMap>): Promise\<BatchResult>

Batch updates the assets that meet the conditions. This API uses a promise to return the result.

The assets to be batch updated must have the same [Tag.GROUP_ID](#tag) and [Tag.REQUIRE_ATTR_ENCRYPTED](#tag) attributes.

The maximum number of assets that can be batch updated is 100.

**Since**: 26.0.0

**System capability:** SystemCapability.Security.Asset

**Parameters**

| Name             | Type     | Mandatory | Description                                                         |
| ------------------ | -------- | ---- | ------------------------------------------------------------ |
| sourceAttributes | Array\<[AssetMap](#assetmap)> | Yes   | Array of search conditions of the assets to be updated. The maximum length of the array is 100, and the values of the [Tag.GROUP_ID](#tag) and [Tag.REQUIRE_ATTR_ENCRYPTED](#tag) attributes of all elements in the array must be the same. |
| destAttributes | Array\<[AssetMap](#assetmap)> | Yes   | Array of attribute sets of the assets to be updated. The maximum length of the array is 100, and it must be the same as the length of sourceAttributes. The values of the [Tag.GROUP_ID](#tag) and [Tag.REQUIRE_ATTR_ENCRYPTED](#tag) attributes of all elements in the array must be the same. |

**Return value**

| Type          | Description                    |
| ------------- | ----------------------- |
| Promise\<[BatchResult](#batchresult)> | Promise used to return the batch operation result, which contains the error information of the failed assets. |

**Error codes**

For details about the error codes, see [Asset Store Service Error Codes](errorcode-asset.md).

| ID| Error Message                                                  |
| -------- | ---------------------------------------------------------- |
| 24000001 | The ASSET service is unavailable.                          |
| 24000006 | Insufficient memory.                                       |
| 24000007 | The asset is corrupted.                                    |
| 24000008 | The database operation failed.                          |
| 24000010 | IPC failed.                                |
| 24000011 | Calling the Bundle Manager service failed. |
| 24000012 | Calling the OS Account service failed.     |
| 24000013 | Calling the Access Token service failed.   |
| 24000015 | Getting the system time failed.            |
| 24000019 | Each value of [Tag.GROUP_ID](#tag) and [Tag.REQUIRE_ATTR_ENCRYPTED](#tag) in the array is not consistent. |

**Example**

```typescript
import { asset } from '@kit.AssetStoreKit';
import { util } from '@kit.ArkTS';

function stringToArray(str: string): Uint8Array {
  let textEncoder = new util.TextEncoder();
  return textEncoder.encodeInto(str);
}

let srcAttrs: Array<asset.AssetMap> = [];
let srcAttr1: asset.AssetMap = new Map();
srcAttr1.set(asset.Tag.ALIAS, stringToArray('demo_alias1'));
srcAttrs.push(srcAttr1);
let srcAttr2: asset.AssetMap = new Map();
srcAttr2.set(asset.Tag.ALIAS, stringToArray('demo_alias2'));
srcAttrs.push(srcAttr2);

let destAttrs: Array<asset.AssetMap> = [];
let destAttr1: asset.AssetMap = new Map();
destAttr1.set(asset.Tag.SECRET, stringToArray('demo_pwd_new1'));
destAttrs.push(destAttr1);
let destAttr2: asset.AssetMap = new Map();
destAttr2.set(asset.Tag.SECRET, stringToArray('demo_pwd_new2'));
destAttrs.push(destAttr2);

asset.batchUpdate(srcAttrs, destAttrs).then((res: asset.BatchResult) => {
  console.info(`Succeeded in batch updating Asset, failedCount: ${res.failedCount}`);
});
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
| Promise\<Uint8Array> | Promise used to return a challenge value.<br>**Note**: The challenge value is used for subsequent user authentication.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Asset Store Service Error Codes](errorcode-asset.md).

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

function stringToArray(str: string): Uint8Array {
  let textEncoder = new util.TextEncoder();
  return textEncoder.encodeInto(str);
}

let query: asset.AssetMap = new Map();
query.set(asset.Tag.ALIAS, stringToArray('demo_alias'));
asset.preQuery(query).then((challenge: Uint8Array) => {
  console.info(`Succeeded in pre-querying Asset, the challenge is: `, challenge);
});
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
| Uint8Array | Challenge value.<br>**Note**: The challenge value is used for subsequent user authentication.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Asset Store Service Error Codes](errorcode-asset.md).

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

function stringToArray(str: string): Uint8Array {
  let textEncoder = new util.TextEncoder();
  return textEncoder.encodeInto(str);
}

let query: asset.AssetMap = new Map();
query.set(asset.Tag.ALIAS, stringToArray('demo_alias'));
let challenge: Uint8Array = asset.preQuerySync(query);
console.info(`Succeeded in pre-querying with sync, the challenge is: `, challenge);
```

## asset.query

query(query: AssetMap): Promise\<Array\<AssetMap>>

Queries one or more assets. If user authentication is required for the access to the asset, call [asset.preQuery](#assetprequery) before this API and call [asset.postQuery](#assetpostquery) after this API. For details about the development procedure, see [Querying an Asset with User Authentication](../../security/AssetStoreKit/asset-js-query-auth.md). This API uses a promise to return the result.

If no asset is found, an exception indicating that no asset is found is thrown instead of an empty query result list.

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Asset Store Service Error Codes](errorcode-asset.md).

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

function stringToArray(str: string): Uint8Array {
  let textEncoder = new util.TextEncoder();
  return textEncoder.encodeInto(str);
}

let query: asset.AssetMap = new Map();
query.set(asset.Tag.ALIAS, stringToArray('demo_alias'));
// If only the asset attributes need to be returned, set RETURN_TYPE to ATTRIBUTES. The attributes do not need to be decrypted, so the query takes a short time.
query.set(asset.Tag.RETURN_TYPE, asset.ReturnType.ALL); // Return all asset information, including the attributes and asset plaintext. The plaintext needs to be decrypted, so the query takes a long time.
asset.query(query).then((res: Array<asset.AssetMap>) => {
  for (let i = 0; i < res.length; i++) {
    // Parse the attributes.
    let accessibility: number = res[i].get(asset.Tag.ACCESSIBILITY) as number;
    console.info(`Succeeded in getting accessibility, which is: ${accessibility}.`);
  }
  console.info(`Succeeded in querying Asset.`);
});
```

## asset.querySync<sup>12+</sup>

querySync(query: AssetMap): Array\<AssetMap>

Queries one or more assets. If user authentication is required for the access to the asset, call [asset.preQuerySync](#assetprequerysync12) before this API and call [asset.postQuerySync](#assetpostquerysync12) after this API. For details about the development procedure, see [Querying an Asset with User Authentication](../../security/AssetStoreKit/asset-js-query-auth.md). This API returns the result synchronously.

If no asset is found, an exception indicating that no asset is found is thrown instead of an empty query result list.

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Asset Store Service Error Codes](errorcode-asset.md).

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

function stringToArray(str: string): Uint8Array {
  let textEncoder = new util.TextEncoder();
  return textEncoder.encodeInto(str);
}

let query: asset.AssetMap = new Map();
query.set(asset.Tag.ALIAS, stringToArray('demo_alias'));
// If only the asset attributes need to be returned, set RETURN_TYPE to ATTRIBUTES. The attributes do not need to be decrypted, so the query takes a short time.
query.set(asset.Tag.RETURN_TYPE, asset.ReturnType.ALL); // Return all asset information, including the attributes and asset plaintext. The plaintext needs to be decrypted, so the query takes a long time.
let res: Array<asset.AssetMap> = asset.querySync(query);
for (let i = 0; i < res.length; i++) {
  // Parse the attributes.
  let accessibility: number = res[i].get(asset.Tag.ACCESSIBILITY) as number;
  console.info(`Succeeded in getting accessibility, which is: ${accessibility}.`);
}
console.info(`Succeeded in querying Asset.`);
```

## asset.postQuery

postQuery(handle: AssetMap): Promise\<void>

Performs postprocessing for the asset query. This API is used when user authentication is required for the access to an asset. It must be used with [asset.preQuery](#assetprequery). This API uses a promise to return the result.

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Asset Store Service Error Codes](errorcode-asset.md).

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

let handle: asset.AssetMap = new Map();
// The new Uint8Array(32) is only an example. Pass in the challenge value returned by asset.preQuery.
handle.set(asset.Tag.AUTH_CHALLENGE, new Uint8Array(32));
asset.postQuery(handle).then(() => {
  console.info(`Succeeded in post-querying Asset.`);
});
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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Asset Store Service Error Codes](errorcode-asset.md).

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

let handle: asset.AssetMap = new Map();
// The new Uint8Array(32) is only an example. Pass in the challenge value returned by asset.preQuerySync.
handle.set(asset.Tag.AUTH_CHALLENGE, new Uint8Array(32));
asset.postQuerySync(handle)
```

## asset.querySyncResult<sup>20+</sup>

querySyncResult(query: AssetMap): Promise\<SyncResult>

Queries the result of the sync operation. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.Asset

**Parameters**

| Name| Type    | Mandatory| Description                                                        |
| ------ | -------- | ---- | ------------------------------------------------------------ |
| query | [AssetMap](#assetmap) | Yes  | Attributes of the sync result to query, such as the group to which the asset belongs and whether the custom attribute information is encrypted.|

**Return value**

| Type         | Description                   |
| ------------- | ----------------------- |
| Promise\<[SyncResult](#syncresult20)> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Asset Store Service Error Codes](errorcode-asset.md).

| ID| Error Message                                                  |
| -------- | ---------------------------------------------------------- |
| 24000001 | The ASSET service is unavailable.                          |
| 24000006 | Insufficient memory.                                       |
| 24000010 | IPC failed.                                |
| 24000011 | Calling the Bundle Manager service failed. |
| 24000012 | Calling the OS Account service failed.     |
| 24000013 | Calling the Access Token service failed.   |
| 24000014 | The file operation failed.   |
| 24000018 | Parameter verification failed.   |

**Example**

```typescript
import { asset } from '@kit.AssetStoreKit';

let query: asset.AssetMap = new Map();
asset.querySyncResult(query).then((res: asset.SyncResult) => {
  console.info(`Succeeded in querying sync result: ${JSON.stringify(res)}`);
});
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
| REQUIRE_PASSWORD_SET      | TagType.BOOL &#124; 0x04                   | Whether the Critical Asset can be accessed only when a screen lock password is set. The value **true** indicates that the Critical Asset can be accessed only when a screen lock password is set, and **false** indicates that the Critical Asset is not restricted by the screen lock password.<br>**Atomic service API:** This API can be used in atomic services since API version 14.                 |
| AUTH_TYPE                 | TagType.NUMBER &#124; 0x05 | Type of user authentication required for accessing the asset.<br>**Atomic service API**: This API can be used in atomic services since API version 14.                              |
| AUTH_VALIDITY_PERIOD      | TagType.NUMBER &#124; 0x06 | Validity period of user authentication, in seconds.<br>**Atomic service API:** This API can be used in atomic services since API version 14.                                             |
| AUTH_CHALLENGE            | TagType.BYTES &#124; 0x07     | Challenge for the user authentication.<br>**Atomic service API**: This API can be used in atomic services since API version 14.                                        |
| AUTH_TOKEN                | TagType.BYTES &#124; 0x08    | Authorization token obtained after the user authentication is successful.<br>**Atomic service API**: This API can be used in atomic services since API version 14.                                          |
| SYNC_TYPE                 | TagType.NUMBER &#124; 0x10 | Asset sync type.<br>**Atomic service API**: This API can be used in atomic services since API version 14.                                      |
| IS_PERSISTENT             | TagType.BOOL &#124; 0x11                         | Whether to retain the Critical Asset when the app is uninstalled. The value **true** indicates that the Critical Asset is retained when the app is uninstalled, and **false** indicates that the Critical Asset is not retained. |
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
| RETURN_LIMIT              | TagType.NUMBER &#124; 0x41                      | Maximum number of results returned by a Critical Asset query.<br>**Atomic service API:** This API can be used in atomic services since API version 14.                                         |
| RETURN_OFFSET             | TagType.NUMBER &#124; 0x42   | Offset of the asset query result.<br>**Note**: This parameter specifies the starting asset record to return in batch asset query.<br>**Atomic service API**: This API can be used in atomic services since API version 14.                                |
| RETURN_ORDERED_BY         | TagType.NUMBER &#124; 0x43 | Sorting order of the query results. Currently, the results can be sorted only by **ASSET_TAG_DATA_LABEL**.<br>**Note**: By default, assets are returned in the order in which they are added.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
| CONFLICT_RESOLUTION       | TagType.NUMBER &#124; 0x44 | Policy for resolving the conflict (for example, a duplicate alias).<br>**Atomic service API**: This API can be used in atomic services since API version 14.                            |
| UPDATE_TIME<sup>12+</sup> | TagType.BYTES &#124; 0x45 | Data update time, in timestamp.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
| OPERATION_TYPE<sup>12+</sup> | TagType.NUMBER &#124; 0x46 | Additional operation type.|
| REQUIRE_ATTR_ENCRYPTED<sup>14+</sup> | TagType.BOOL &#124; 0x47 | Whether to encrypt the business custom additional information. The value **true** indicates that the business custom additional information is encrypted, and **false** indicates that it is not encrypted.<br>**Note:** When inserting, deleting, or updating Critical Assets in batches, each item in the array must have the same REQUIRE_ATTR_ENCRYPTED attribute value.<br>**Atomic service API:** This API can be used in atomic services since API version 14. |
| GROUP_ID<sup>18+</sup> | TagType.BYTES &#124; 0x48 | Group to which the Critical Asset belongs.<br>**Note:** When inserting, deleting, or updating Critical Assets in batches, each item in the array must have the same GROUP_ID attribute value. |
| WRAP_TYPE<sup>18+</sup> | TagType.NUMBER &#124; 0x49 | Encrypted import/export type supported by the asset.<br>|

## Value

type Value = boolean | number | Uint8Array

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
| DEVICE_FIRST_UNLOCKED | 1    | The asset can be accessed only after the device is unlocked for the first time.<br>**Note**: If no lock screen password is set, this option is equivalent to **DEVICE_POWERED_ON**.|
| DEVICE_UNLOCKED       | 2    | The asset can be accessed only when the device is unlocked.<br>**Note**: If no lock screen password is set, this option is equivalent to **DEVICE_POWERED_ON**.|

## AuthType

Enumerates the types of user authentication supported by an asset.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Security.Asset

| Name| Value  | Description                                                        |
| ---- | ---- | ------------------------------------------------------------ |
| NONE | 0x00 | No user authentication is required before the asset is accessed.                                |
| ANY  | 0xFF | The asset can be accessed if any user authentication (such as PIN, facial, or fingerprint authentication) is successful.|

## SyncType

Enumerates the sync types supported by an asset.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Security.Asset

| Name                         | Value    | Description                                            |
| ----------------------------- | ------ | ------------------------------------------------ |
| NEVER                         | 0      | Asset sync is not allowed.                            |
| THIS_DEVICE                   | 1 << 0 | Asset sync is allowed only on the local device, for example, in data restore on the local device.<br>**Note**: This field is reserved for future use and is not supported currently.|
| TRUSTED_DEVICE                | 1 << 1 | Asset sync is allowed only between trusted devices, for example, in the case of cloning.            |
| TRUSTED_ACCOUNT<sup>12+</sup> | 1 << 2 | Asset sync is allowed only between the devices that are logged in with trusted accounts, for example, in cloud sync scenarios.<br>**Note**: This field is reserved for future use and is not supported currently.|

## ReturnType

Enumerates the type of information returned by an asset query operation.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Security.Asset

| Name      | Value  | Description                                                        |
| ---------- | ---- | ------------------------------------------------------------ |
| ALL        | 0    | The query result contains the asset in plaintext and its attributes.<br>**Note**: Use this option when you need to query the plaintext of a single asset.|
| ATTRIBUTES | 1    | The query result contains only the asset attributes.<br>**Note**: Use this option when you need to query attributes of multiple assets.|

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

## WrapType<sup>18+</sup>

Enumerates the encrypted import/export types supported by the asset.

**System capability**: SystemCapability.Security.Asset

| Name       | Value  | Description              |
| ----------- | ---- | ------------------ |
| NEVER   | 0    | Encrypted import/export is not allowed for the asset.|
| TRUSTED_ACCOUNT | 1    | Encrypted import/export is allowed for the asset only on devices where a trusted account is logged in.|

## SyncResult<sup>20+</sup>

Represents the sync result of an asset.

**System capability**: SystemCapability.Security.Asset

| Name       | Type  | Read-Only| Optional|Description              |
| ----------- | ---- | ---- | ---- | ------------------ |
| resultCode   | number    | Yes| No| Sync result code of an asset. If the sync is successful, the result code is **0**. If the sync fails, see [ErrorCode](#errorcode) for the result code.|
| totalCount | number    | Yes| Yes|  Total number of assets to be synced.|
| failedCount | number    | Yes| Yes|  Number of assets that fail to be synced.|

## BatchErrInfo

Error information of a single asset in a batch operation.

**Since**: 26.0.0

**System capability:** SystemCapability.Security.Asset

| Name        | Type   | Read-Only | Optional | Description               |
| ----------- | ---- | ---- | ---- | ------------------ |
| index   | number    | No | No | Index of the asset. |
| errCode | number    | No | No | Error code of the batch operation. |
| message | string    | No | No | Error message of the batch operation. |

## BatchResult

Result of the [batchAdd](#assetbatchadd), [batchUpdate](#assetbatchupdate), and [batchRemove](#assetbatchremove) batch operations.

**Since**: 26.0.0

**System capability:** SystemCapability.Security.Asset

| Name        | Type   | Read-Only | Optional | Description               |
| ----------- | ---- | ---- | ---- | ------------------ |
| failedCount   | number    | No | No | Number of failed batch operations. The value 0 indicates that all operations are successful. |
| failedErrorInfos | Array\<[BatchErrInfo](#batcherrinfo)>    | No | No | Array of error information of the failed assets in the batch operation. It is an empty array when all operations are successful. |

## ErrorCode

Enumerates the error codes.

**System capability**: SystemCapability.Security.Asset

| Name                      | Value   | Description|
| -------------------------- | ----- | ---- |
| PERMISSION_DENIED | 201     |The caller does not have the permission.|
| NOT_SYSTEM_APPLICATION<sup>12+</sup> | 202     |The caller is not a system application.|
| INVALID_ARGUMENT | 401    |Incorrect parameters are detected.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
| SERVICE_UNAVAILABLE | 24000001    |The asset service is unavailable.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
| NOT_FOUND | 24000002    |Failed to find the asset.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
| DUPLICATED | 24000003    |The specified asset already exists.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
| ACCESS_DENIED | 24000004    |Access denied.<br>**Atomic service API:** This API can be used in atomic services since API version 14.|
| STATUS_MISMATCH | 24000005    |The screen lock status does not match.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
| OUT_OF_MEMORY | 24000006    |The system memory is insufficient.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
| DATA_CORRUPTED | 24000007    |The asset is corrupted.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
| DATABASE_ERROR | 24000008   |The database operation failed.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
| CRYPTO_ERROR | 24000009   |The crypto operation failed.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
| IPC_ERROR | 24000010   |IPC failed.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
| BMS_ERROR | 24000011   |The Bundle Manager service is abnormal.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
| ACCOUNT_ERROR | 24000012   |Account system service exception.<br>**Atomic service API:** This API can be used in atomic services since API version 14.|
| ACCESS_TOKEN_ERROR | 24000013   |The Access Token service is abnormal.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
| FILE_OPERATION_ERROR | 24000014   |The file operation failed.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
| GET_SYSTEM_TIME_ERROR | 24000015   |Failed to obtain the system time.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
| LIMIT_EXCEEDED | 24000016   |The number of cached records exceeds the upper limit.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
| UNSUPPORTED | 24000017   |The feature is not supported.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
| PARAM_VERIFICATION_FAILED<sup>20+</sup> | 24000018   |Parameter verification failed.<br>**Atomic service API**: This API can be used in atomic services since API version 20.|
| INCONSISTENT_ATTRIBUTE | 24000019   |Inconsistent attribute values.<br>**Since:** 26.0.0<br>**Atomic service API:** This API can be used in atomic services since API version 26.0.0.|