# Removing Assets (ArkTS)

## Available APIs

You can use [remove(query: AssetMap)](../../reference/apis-asset-store-kit/js-apis-asset.md#assetremove), an asynchronous API, or [removeSync(query: AssetMap)](../../reference/apis-asset-store-kit/js-apis-asset.md#assetremovesync12), a synchronous API, to remove assets. If the asset alias is specified, the specified asset will be removed. If no asset alias is specified, all assets will be removed.

The following table describes the attributes of **AssetMap** for removing an asset.

>**NOTE**
>
>In the following table, the attributes starting with **DATA_LABEL** are custom asset attributes reserved for services. These attributes are not encrypted. Therefore, do not put personal data in these attributes.

| Attribute Name (Tag)       | Value                                            | Mandatory | Description                                            |
| --------------------- | ------------------------------------------------------------ | -------- | ------------------------------------------------ |
| ALIAS                 | Type: Uint8Array<br>Length: 1-256 bytes                           | No    | Asset alias, which uniquely identifies an asset.           |
| ACCESSIBILITY         | Type: number<br>Value range: see [Accessibility](../../reference/apis-asset-store-kit/js-apis-asset.md#accessibility)| No    | Access control based on the lock screen status.                                    |
| REQUIRE_PASSWORD_SET  | Type: bool                                                  | No    | Whether the asset is accessible only when a lock screen password is set.    |
| AUTH_TYPE             | Type: number<br>Value range: see [AuthType](../../reference/apis-asset-store-kit/js-apis-asset.md#authtype)| No    | Type of user authentication required for accessing the asset.                  |
| SYNC_TYPE             | Type: number<br>Value range: see [SyncType](../../reference/apis-asset-store-kit/js-apis-asset.md#synctype)| No    | Type of sync supported by the asset.                          |
| IS_PERSISTENT         | Type: bool                                                  | No    | Whether to retain the asset when the application is uninstalled.                |
| DATA_LABEL_CRITICAL_1 | Type: Uint8Array<br>Length: 1-2048 bytes                       | No    | Asset attribute information customized by the service with integrity protection.<br>**NOTE**: The data length is 1 to 512 bytes before API version 12.|
| DATA_LABEL_CRITICAL_2 | Type: Uint8Array<br>Length: 1-2048 bytes                       | No    | Asset attribute information customized by the service with integrity protection.<br>**NOTE**: The data length is 1 to 512 bytes before API version 12.|
| DATA_LABEL_CRITICAL_3 | Type: Uint8Array<br>Length: 1-2048 bytes                       | No    | Asset attribute information customized by the service with integrity protection.<br>**NOTE**: The data length is 1 to 512 bytes before API version 12.|
| DATA_LABEL_CRITICAL_4 | Type: Uint8Array<br>Length: 1-2048 bytes                       | No    | Asset attribute information customized by the service with integrity protection.<br>**NOTE**: The data length is 1 to 512 bytes before API version 12.|
| DATA_LABEL_NORMAL_1   | Type: Uint8Array<br>Length: 1-2048 bytes                       | No    | Asset attribute information customized by the service without integrity protection.<br>**NOTE**: The data length is 1 to 512 bytes before API version 12.|
| DATA_LABEL_NORMAL_2   | Type: Uint8Array<br>Length: 1-2048 bytes                       | No    | Asset attribute information customized by the service without integrity protection.<br>**NOTE**: The data length is 1 to 512 bytes before API version 12.|
| DATA_LABEL_NORMAL_3   | Type: Uint8Array<br>Length: 1-2048 bytes                       | No    | Asset attribute information customized by the service without integrity protection.<br>**NOTE**: The data length is 1 to 512 bytes before API version 12.|
| DATA_LABEL_NORMAL_4   | Type: Uint8Array<br>Length: 1-2048 bytes                       | No    | Asset attribute information customized by the service without integrity protection.<br>**NOTE**: The data length is 1 to 512 bytes before API version 12.|
| DATA_LABEL_NORMAL_LOCAL_1<sup>12+</sup> | Type: Uint8Array<br>Length: 1-2048 bytes| No| Local attribute information about the asset. The value is assigned by the service without integrity protection and will not be synced.|
| DATA_LABEL_NORMAL_LOCAL_2<sup>12+</sup> | Type: Uint8Array<br>Length: 1-2048 bytes| No| Local attribute information about the asset. The value is assigned by the service without integrity protection and will not be synced.|
| DATA_LABEL_NORMAL_LOCAL_3<sup>12+</sup> | Type: Uint8Array<br>Length: 1-2048 bytes| No| Local attribute information about the asset. The value is assigned by the service without integrity protection and will not be synced.|
| DATA_LABEL_NORMAL_LOCAL_4<sup>12+</sup> | Type: Uint8Array<br>Length: 1-2048 bytes| No| Local attribute information about the asset. The value is assigned by the service without integrity protection and will not be synced.|
| REQUIRE_ATTR_ENCRYPTED<sup>14+</sup> | Type: bool| No| Whether to remove the customized asset attribute information that is encrypted. By default, the unencrypted, customized asset attribute information is removed.|
| GROUP_ID<sup>18+</sup> | Type: Uint8Array<br>Length: 7-127 bytes| No| Group to which the asset to be removed belongs. By default, this parameter is not specified.|

## Example

> **NOTE**
>
> The **asset** module provides an asynchronous API and a synchronous API for removing an asset. The following uses the asynchronous API as an example. For more information about the APIs, see [Asset Store Service](../../reference/apis-asset-store-kit/js-apis-asset.md).
>
> For details about how to remove an asset from a group, see [Removing an Asset from a Group](asset-js-group-access-control.md#removing-an-asset-from-a-group).

Remove asset **demo_alias**.

```typescript
import { asset } from '@kit.AssetStoreKit';
import { util } from '@kit.ArkTS';
import { BusinessError } from '@kit.BasicServicesKit';

function stringToArray(str: string): Uint8Array {
  let textEncoder = new util.TextEncoder();
  return textEncoder.encodeInto(str);
}

let query: asset.AssetMap = new Map();
query.set(asset.Tag.ALIAS, stringToArray('demo_alias')); // Specify the asset alias to remove a single asset. To remove all assets, leave the alias unspecified.
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
