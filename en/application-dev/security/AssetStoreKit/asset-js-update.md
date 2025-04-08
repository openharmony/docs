# Updating an Asset (ArkTS)

## Available APIs

You can use [update(query: AssetMap, attributesToUpdate: AssetMap)](../../reference/apis-asset-store-kit/js-apis-asset.md#assetupdate), an asynchronous API, or [updateSync(query: AssetMap, attributesToUpdate: AssetMap)](../../reference/apis-asset-store-kit/js-apis-asset.md#assetupdatesync12), a synchronous API, to update an asset.

The following table describes the attributes of **AssetMap** for updating an asset.

>**NOTE**
>
>In the following table, the attributes starting with **DATA_LABEL** are custom asset attributes reserved for services. These attributes are not encrypted. Therefore, do not put personal data in these attributes.

- Attributes of **AssetMap** in **query**:

  | Attribute Name (Tag)       | Attribute Content (Value)                   | Mandatory | Description                                            |
  | --------------------- | ------------------------------------------------------------ | -------- | ------------------------------------------------ |
  | ALIAS                 | Type: Uint8Array<br>Length: 1-256 bytes                           | Yes    | Asset alias, which uniquely identifies an asset.          |
  | ACCESSIBILITY         | Type: number<br>Value range: see [Accessibility](../../reference/apis-asset-store-kit/js-apis-asset.md#accessibility)| No    | Access control based on the lock screen status.                                    |
  | REQUIRE_PASSWORD_SET  | Type: boolean                                                  | No    | Whether the asset is accessible only when a lock screen password is set.    |
  | AUTH_TYPE             | Type: number<br>Value range: see [AuthType](../../reference/apis-asset-store-kit/js-apis-asset.md#authtype)| No    | Type of user authentication required for accessing the asset.                  |
  | SYNC_TYPE             | Type: number<br>Value range: see [SyncType](../../reference/apis-asset-store-kit/js-apis-asset.md#synctype)| No    | Asset sync type.                          |
  | IS_PERSISTENT         | Type: boolean                                                  | No    | Whether to retain the asset when the application is uninstalled.                |
  | DATA_LABEL_CRITICAL_1 | Type: Uint8Array<br>Length: 1-2048 bytes                       | No    | Asset attribute information customized by the service with integrity protection.<br>**NOTE**: The data length is 1 to 512 bytes before API version 12.|
  | DATA_LABEL_CRITICAL_2 | Type: Uint8Array<br>Length: 1-2048 bytes                       | No    | Asset attribute information customized by the service with integrity protection.<br>**NOTE**: The data length is 1 to 512 bytes before API version 12.|
  | DATA_LABEL_CRITICAL_3 | Type: Uint8Array<br>Length: 1-2048 bytes                      | No    | Asset attribute information customized by the service with integrity protection.<br>**NOTE**: The data length is 1 to 512 bytes before API version 12.|
  | DATA_LABEL_CRITICAL_4 | Type: Uint8Array<br>Length: 1-2048 bytes                       | No    | Asset attribute information customized by the service with integrity protection.<br>**NOTE**: The data length is 1 to 512 bytes before API version 12.|
  | DATA_LABEL_NORMAL_1   | Type: Uint8Array<br>Length: 1-2048 bytes                       | No    | Asset attribute information customized by the service without integrity protection.<br>**NOTE**: The data length is 1 to 512 bytes before API version 12.|
  | DATA_LABEL_NORMAL_2   | Type: Uint8Array<br>Length: 1-2048 bytes                       | No    | Asset attribute information customized by the service without integrity protection.<br>**NOTE**: The data length is 1 to 512 bytes before API version 12.|
  | DATA_LABEL_NORMAL_3   | Type: Uint8Array<br>Length: 1-2048 bytes                       | No    | Asset attribute information customized by the service without integrity protection.<br>**NOTE**: The data length is 1 to 512 bytes before API version 12.|
  | DATA_LABEL_NORMAL_4   | Type: Uint8Array<br>Length: 1-2048 bytes                       | No    | Asset attribute information customized by the service without integrity protection.<br>**NOTE**: The data length is 1 to 512 bytes before API version 12.|
  | DATA_LABEL_NORMAL_LOCAL_1<sup>12+</sup> | Type: Uint8Array<br>Length: 1-2048 bytes| No| Local attribute information about the asset. The value is assigned by the service without integrity protection and will not be synced.|
  | DATA_LABEL_NORMAL_LOCAL_2<sup>12+</sup> | Type: Uint8Array<br>Length: 1-2048 bytes| No| Local attribute information about the asset. The value is assigned by the service without integrity protection and will not be synced.|
  | DATA_LABEL_NORMAL_LOCAL_3<sup>12+</sup> | Type: Uint8Array<br>Length: 1-2048 bytes| No| Local attribute information about the asset. The value is assigned by the service without integrity protection and will not be synced.|
  | DATA_LABEL_NORMAL_LOCAL_4<sup>12+</sup> | Type: Uint8Array<br>Length: 1-2048 bytes| No| Local attribute information about the asset. The value is assigned by the service without integrity protection and will not be synced.|
  | REQUIRE_ATTR_ENCRYPTED<sup>14+</sup> | Type: boolean| No| Whether to update the customized asset attribute information that is encrypted. By default, the unencrypted customized asset attribute information is updated.|
  | GROUP_ID<sup>18+</sup> | Type: Uint8Array<br>Length: 7-127 bytes| No| Group to which the asset to be updated belongs. By default, this parameter is not specified.|

- Attributes of **AssetMap** in **attributesToUpdate**:

  | Attribute Name (Tag)       | Attribute Content (Value) | Mandatory | Description                                                        |
  | --------------------- | -------------------------------| -------- | ------------------------------- |
  | SECRET                | Type: Uint8Array<br>Length: 1-1024 bytes                          | No    | New asset in plaintext.                                                |
  | DATA_LABEL_NORMAL_1   | Type: Uint8Array<br>Length: 1-2048 bytes                       | No    | New asset attribute information customized by the service without integrity protection.<br>**NOTE**: The data length is 1 to 512 bytes before API version 12.|
  | DATA_LABEL_NORMAL_2   | Type: Uint8Array<br>Length: 1-2048 bytes                       | No    | New asset attribute information customized by the service without integrity protection.<br>**NOTE**: The data length is 1 to 512 bytes before API version 12.|
  | DATA_LABEL_NORMAL_3   | Type: Uint8Array<br>Length: 1-2048 bytes                       | No    | New asset attribute information customized by the service without integrity protection.<br>**NOTE**: The data length is 1 to 512 bytes before API version 12.|
  | DATA_LABEL_NORMAL_4   | Type: Uint8Array<br>Length: 1-2048 bytes                       | No    | New asset attribute information customized by the service without integrity protection.<br>**NOTE**: The data length is 1 to 512 bytes before API version 12.|
  | DATA_LABEL_NORMAL_LOCAL_1<sup>12+</sup> | Type: Uint8Array<br>Length: 1-2048 bytes| No| Local attribute information about the new asset. The value is assigned by the service without integrity protection and will not be synced.|
  | DATA_LABEL_NORMAL_LOCAL_2<sup>12+</sup> | Type: Uint8Array<br>Length: 1-2048 bytes| No| Local attribute information about the new asset. The value is assigned by the service without integrity protection and will not be synced.|
  | DATA_LABEL_NORMAL_LOCAL_3<sup>12+</sup> | Type: Uint8Array<br>Length: 1-2048 bytes| No| Local attribute information about the new asset. The value is assigned by the service without integrity protection and will not be synced.|
  | DATA_LABEL_NORMAL_LOCAL_4<sup>12+</sup> | Type: Uint8Array<br>Length: 1-2048 bytes| No| Local information about the new asset. The value is assigned by the service without integrity protection and will not be synced.|

## Example

> **NOTE**
>
> The **asset** module provides an asynchronous API and a synchronous API for updating an asset. The following uses the asynchronous API as an example. For more information about the APIs, see [Asset Store Service](../../reference/apis-asset-store-kit/js-apis-asset.md).
>
> For details about how to update an asset in a group, see [Updating an asset in a Group](asset-js-group-access-control.md#updating-an-asset-in-a-group).

Update asset **demo_alias** as follows: change the asset plaintext to **demo_pwd_new** and additional attribute to **demo_label_new**.

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
attrsToUpdate.set(asset.Tag.DATA_LABEL_NORMAL_1, stringToArray('demo_label_new'));
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
