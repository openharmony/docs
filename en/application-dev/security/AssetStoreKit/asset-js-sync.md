# Syncing Assets (Backup and Restore) (ArkTS)

## Adding Assets That Support Sync

Add an asset with the password **demo_pwd**, alias **demo_alias**, and additional information **demo_label**.

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
attr.set(asset.Tag.DATA_LABEL_NORMAL_1, stringToArray('demo_label'));
attr.set(asset.Tag.SYNC_TYPE, asset.SyncType.TRUSTED_DEVICE); // You need to specify the sync type between trusted devices (for example, clone between old and new devices).
try {
  asset.add(attr).then(() => {
    console.info(`Asset added with sync successfully.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to add Asset with sync. Code is ${err.code}, message is ${err.message}`);
  })
} catch (error) {
  let err = error as BusinessError;
  console.error(`Failed to add Asset with sync. Code is ${err.code}, message is ${err.message}`);
}
```

## Accessing the Backup and Restore Extension Capability

To trigger the backup and restore of application data, see [Accessing Backup and Restore](../../file-management/app-file-backup-extension.md).

## Querying the Sync Result of Assets

### Available APIs

You can call [asset.querySyncResult](../../reference/apis-asset-store-kit/js-apis-asset.md#assetquerysyncresult20) to query the sync result of assets. For more information, see the API reference.

The following table describes the attributes of **AssetMap** for querying the sync result of assets.

| Attribute Name (Tag)       | Attribute Content (Asset_Value)                                            | Mandatory/Optional  | Description                                                        |
| --------------------- | ------------------------------------------------------------ | -------- | ------------------------------------------------------------ |
| REQUIRE_ATTR_ENCRYPTED<sup>14+</sup> | Type: Boolean| Yes| Whether to query the sync result of the asset whose custom additional information is encrypted. The value **true** means to query the sync result; the value **false** means the opposite. The default value is **false**.|
| GROUP_ID<sup>18+</sup> | Type: Uint8Array<br>Length: 7-127 bytes| Yes| Group to which the asset to be queried belongs. By default, this parameter is not specified.|

### Sample Code

```typescript
import { asset } from '@kit.AssetStoreKit';
import { BusinessError } from '@kit.BasicServicesKit';

let query: asset.AssetMap = new Map();
asset.querySyncResult(query).then((res: asset.SyncResult) => {
  console.info(`sync result: ${JSON.stringify(res)}`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to query sync result of Asset. Code is ${err.code}, message is ${err.message}`);
});
```

## Notes and Constraints

For a successful sync between trusted devices, the assets of both old and new devices must be accessible. Otherwise, the sync might fail.

* For assets that are accessible only when a password is set, the sync will fail if no lock screen password is set on either the old or new device.
  
* For assets that are accessible only when the screen is unlocked, the sync will fail if the screen of either the old or new device is locked.

* For assets that are accessible only after user authentication, the sync will fail if no lock screen password is set on the old device.
