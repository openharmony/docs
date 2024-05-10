# Updating an Asset (ArkTS)

## Available APIs

For details about the API, see:

[update(query: AssetMap, attributesToUpdate: AssetMap): Promise\<void>](../../reference/apis-asset-store-kit/js-apis-asset.md#assetupdate)

Attributes in **query**:

| Attribute Name (Tag)       | Attribute Content (Value)                                            | Mandatory | Description                                            |
| --------------------- | ------------------------------------------------------------ | -------- | ------------------------------------------------ |
| ALIAS                 | Type: Uint8Array<br>Length: 1-256 bytes                           | Yes    | Asset alias, which uniquely identifies an asset.           |
| ACCESSIBILITY         | Type: number<br>Value range: see [Accessibility](../../reference/apis-asset-store-kit/js-apis-asset.md#accessibility)| No    | Access control based on the lock screen status.                                    |
| REQUIRE_PASSWORD_SET  | Type: bool                                                  | No    | Whether the asset is accessible only when a lock screen password is set.    |
| AUTH_TYPE             | Type: number<br>Value range: see [AuthType](../../reference/apis-asset-store-kit/js-apis-asset.md#authtype)| No    | Type of user authentication required for accessing the asset.                  |
| SYNC_TYPE             | Type: number<br>Value range: see [SyncType](../../reference/apis-asset-store-kit/js-apis-asset.md#synctype)| No    | Type of sync supported by the asset.                          |
| IS_PERSISTENT         | Type: bool                                                  | No    | Whether to retain the asset when the application is uninstalled.                |
| DATA_LABEL_CRITICAL_1 | Type: Uint8Array<br>Length: 1-512 bytes                           | No    | Additional asset data customized by the service with integrity protection.|
| DATA_LABEL_CRITICAL_2 | Type: Uint8Array<br>Length: 1-512 bytes                           | No    | Additional asset data customized by the service with integrity protection.|
| DATA_LABEL_CRITICAL_3 | Type: Uint8Array<br>Length: 1-512 bytes                           | No    | Additional asset data customized by the service with integrity protection.|
| DATA_LABEL_CRITICAL_4 | Type: Uint8Array<br>Length: 1-512 bytes                           | No    | Additional asset data customized by the service with integrity protection.|
| DATA_LABEL_NORMAL_1   | Type: Uint8Array<br>Length: 1-512 bytes                           | No    | Additional asset data customized by the service without integrity protection.|
| DATA_LABEL_NORMAL_2   | Type: Uint8Array<br>Length: 1-512 bytes                           | No    | Additional asset data customized by the service without integrity protection.|
| DATA_LABEL_NORMAL_3   | Type: Uint8Array<br>Length: 1-512 bytes                           | No    | Additional asset data customized by the service without integrity protection.|
| DATA_LABEL_NORMAL_4   | Type: Uint8Array<br>Length: 1-512 bytes                           | No    | Additional asset data customized by the service without integrity protection.|


Attributes in **attributesToUpdate**:


| Attribute Name (Tag)       | Attribute Content (Value)                   | Mandatory | Description                                                        |
| --------------------- | ------------------------------------------------------------ | -------- | ------------------------------------------------------------ |
| SECRET                | Type: Uint8Array<br>Length: 1-1024 bytes                          | No    | New asset plaintext.                                                |
| DATA_LABEL_NORMAL_1   | Type: Uint8Array<br>Length: 1-512 bytes                           | No    | Additional data of the new asset customized by the service without integrity protection.            |
| DATA_LABEL_NORMAL_2   | Type: Uint8Array<br>Length: 1-512 bytes                           | No    | Additional data of the new asset customized by the service without integrity protection.            |
| DATA_LABEL_NORMAL_3   | Type: Uint8Array<br>Length: 1-512 bytes                           | No    | Additional data of the new asset customized by the service without integrity protection.            |
| DATA_LABEL_NORMAL_4   | Type: Uint8Array<br>Length: 1-512 bytes                           | No    | Additional data of the new asset customized by the service without integrity protection.            |

## Example

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

## Constraints

N/A.
