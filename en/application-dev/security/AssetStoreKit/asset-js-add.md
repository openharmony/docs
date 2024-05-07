# Adding an Asset (ArkTS)

## Available APIs

For details about the API, see:

[add(attributes: AssetMap): Promise\<void>](../../reference/apis-asset-store-kit/js-apis-asset.md#assetadd)

The following table describes the parameters of **AssetMap**.

| Attribute Name (Tag)       | Attribute Content (Value)                     | Mandatory | Description                                                        |
| --------------------- | ------------------------------------------------------------ | -------- | ------------------------------------------------------------ |
| SECRET                | Type: Uint8Array<br>Length: 1-1024 bytes                          | Yes    | Asset plaintext.                                             |
| ALIAS                 | Type: Uint8Array<br>Length: 1-256 bytes                           | Yes    | Asset alias, which uniquely identifies an asset.                       |
| ACCESSIBILITY         | Type: number<br>Value range: see [Accessibility](../../reference/apis-asset-store-kit/js-apis-asset.md#accessibility)| No    | Access control based on the lock screen status.     |
| REQUIRE_PASSWORD_SET  | Type: bool                                                  | No    | Whether the asset is accessible only when a lock screen password is set.             |
| AUTH_TYPE             | Type: number<br>Value range: see [AuthType](../../reference/apis-asset-store-kit/js-apis-asset.md#authtype)| No    | Type of user authentication required for accessing the asset.        |
| SYNC_TYPE             | Type: number<br>Value range: see [SyncType](../../reference/apis-asset-store-kit/js-apis-asset.md#synctype)| No    | Type of sync supported by the asset.               |
| IS_PERSISTENT         | Type: bool                                                  | No    | Whether to retain the asset when the application is uninstalled.<br>**Required permissions**: ohos.permission.STORE_PERSISTENT_DATA|
| DATA_LABEL_CRITICAL_1 | Type: Uint8Array<br>Length: 1-512 bytes                           | No    | Additional asset data customized by the service with integrity protection.            |
| DATA_LABEL_CRITICAL_2 | Type: Uint8Array<br>Length: 1-512 bytes                           | No    | Additional asset data customized by the service with integrity protection.            |
| DATA_LABEL_CRITICAL_3 | Type: Uint8Array<br>Length: 1-512 bytes                           | No    | Additional asset data customized by the service with integrity protection.            |
| DATA_LABEL_CRITICAL_4 | Type: Uint8Array<br>Length: 1-512 bytes                           | No    | Additional asset data customized by the service with integrity protection.            |
| DATA_LABEL_NORMAL_1   | Type: Uint8Array<br>Length: 1-512 bytes                           | No    | Additional asset data customized by the service without integrity protection.            |
| DATA_LABEL_NORMAL_2   | Type: Uint8Array<br>Length: 1-512 bytes                           | No    | Additional asset data customized by the service without integrity protection.            |
| DATA_LABEL_NORMAL_3   | Type: Uint8Array<br>Length: 1-512 bytes                           | No    | Additional asset data customized by the service without integrity protection.            |
| DATA_LABEL_NORMAL_4   | Type: Uint8Array<br>Length: 1-512 bytes                           | No    | Additional asset data customized by the service without integrity protection.            |
| CONFLICT_RESOLUTION   | Type: number<br>Value range: see [ConflictResolution](../../reference/apis-asset-store-kit/js-apis-asset.md#conflictresolution)| No    | Policy for resolving the conflict (for example, a duplicate alias).                            |

## Example

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

## Constraints

* Alias-based access

  Assets are stored in the ASSET database in ciphertext and uniquely identified by the service identity and alias. The alias of each asset must be unique.

* Custom service data storage

  ASSET provides 8 custom asset attributes starting with **DATA_LABEL** for services. If the 8 custom attributes are used, you can combine multiple data segments in a certain format (for example, JSON) into an ASSET attribute.

  ASSET protects the integrity of the attributes starting with **DATA_LABEL_CRITICAL**. These attributes cannot be changed once written.