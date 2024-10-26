# Adding an Asset (ArkTS)

## Available APIs

You can use [add(attributes: AssetMap)](../../reference/apis-asset-store-kit/js-apis-asset.md#assetadd), an asynchronous API, or [addSync(attributes: AssetMap)](../../reference/apis-asset-store-kit/js-apis-asset.md#assetaddsync12), a synchronous API, to add an asset.

The following table describes the attributes of **AssetMap** for adding an asset.

>**NOTE**
>
>In the following table, the attributes starting with **DATA_LABEL** are custom asset attributes reserved for services. These attributes are not encrypted. Therefore, do not put personal data in these attributes.

| Attribute Name (Tag)       | Value                                            | Mandatory | Description                                                        |
| --------------------- | ------------------------------------------------------------ | -------- | ------------------------------------------------------------ |
| SECRET                | Type: Uint8Array<br>Length: 1-1024 bytes                          | Yes    | Asset in plaintext.                                             |
| ALIAS                 | Type: Uint8Array<br>Length: 1-256 bytes                           | Yes    | Asset alias, which uniquely identifies an asset.                       |
| ACCESSIBILITY         | Type: number<br>Value range: see [Accessibility](../../reference/apis-asset-store-kit/js-apis-asset.md#accessibility)| No    | Access control based on the lock screen status.     |
| REQUIRE_PASSWORD_SET  | Type: bool                                                  | No    | Whether the asset is accessible only when a lock screen password is set.             |
| AUTH_TYPE             | Type: number<br>Value range: see [AuthType](../../reference/apis-asset-store-kit/js-apis-asset.md#authtype)| No    | Type of user authentication required for accessing the asset.        |
| SYNC_TYPE             | Type: number<br>Value range: see [SyncType](../../reference/apis-asset-store-kit/js-apis-asset.md#synctype)| No    | Type of sync supported by the asset.               |
| IS_PERSISTENT         | Type: bool                                                  | No    | Whether to retain the asset when the application is uninstalled.<br>**NOTE**: If this parameter is set, the application must [apply for](../AccessToken/declare-permissions.md) the ohos.permission.STORE_PERSISTENT_DATA permission.|
| DATA_LABEL_CRITICAL_1 | Type: Uint8Array<br>Length: 1-2048 bytes                        | No    | Asset attribute information customized by the service with integrity protection.<br>**NOTE**: The data length is 1 to 512 bytes before API version 12.|
| DATA_LABEL_CRITICAL_2 | Type: Uint8Array<br>Length: 1-2048 bytes                      | No    | Asset attribute information customized by the service with integrity protection.<br>**NOTE**: The data length is 1 to 512 bytes before API version 12.|
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
| CONFLICT_RESOLUTION   | Type: number<br>Value range: see [ConflictResolution](../../reference/apis-asset-store-kit/js-apis-asset.md#conflictresolution)| No    | Policy for resolving the conflict (for example, duplicate alias). |
| REQUIRE_ATTR_ENCRYPTED<sup>13+</sup> | Type: bool| No| Whether to encrypt the customized asset attribute information. By default, the information does not need to be encrypted.|

## Constraints

* Alias-based access

  Assets are stored in the ASSET database in ciphertext and uniquely identified by the service identity and alias. The alias of each asset must be unique.

* Custom service data storage

  ASSET provides 12 custom asset attributes starting with **DATA_LABEL** for services. If the 12 custom attributes are used, you can combine multiple data segments in a certain format (for example, JSON) into an ASSET attribute.

  ASSET protects the integrity of the attributes starting with **DATA_LABEL_CRITICAL**. These attributes cannot be changed once written.


## Example

> **NOTE**
>
> The **asset** module provides an asynchronous API and a synchronous API for adding an asset. The following uses the asynchronous API as an example. For more information about the APIs, see [Asset Store Service](../../reference/apis-asset-store-kit/js-apis-asset.md).

Add an asset with password of **demo_pwd**, alias of **demo_alias**, and additional information of **demo_label** and allow the asset to be accessed after the device is unlocked for the first time.

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
