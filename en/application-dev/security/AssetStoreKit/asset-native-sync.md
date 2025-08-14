# Syncing Assets (Backup and Restore) (C/C++)


## Adding Dependencies

Link the dynamic libraries in the CMake script.
```txt
target_link_libraries(entry PUBLIC libasset_ndk.z.so)
```

## Adding Assets That Support Sync

Add an asset with the password **demo_pwd**, alias **demo_alias**, and additional information **demo_label**.

```c
#include <string.h>

#include "asset/asset_api.h"

void AddAsset() {
    static const char *SECRET = "demo_pwd";
    static const char *ALIAS = "demo_alias";
    static const char *LABEL = "demo_label";

    Asset_Blob secret = { (uint32_t)(strlen(SECRET)), (uint8_t *)SECRET };
    Asset_Blob alias = { (uint32_t)(strlen(ALIAS)), (uint8_t *)ALIAS };
    Asset_Blob label = { (uint32_t)(strlen(LABEL)), (uint8_t *)LABEL };
    Asset_Attr attr[] = {
        { .tag = ASSET_TAG_SECRET, .value.blob = secret },
        { .tag = ASSET_TAG_ALIAS, .value.blob = alias },
        { .tag = ASSET_TAG_DATA_LABEL_NORMAL_1, .value.blob = label },
        { .tag = ASSET_TAG_SYNC_TYPE, .value.u32 = ASSET_SYNC_TYPE_TRUSTED_DEVICE }, // You need to specify the sync type between trusted devices (for example, clone between old and new devices).
    };

    int32_t ret = OH_Asset_Add(attr, sizeof(attr) / sizeof(attr[0]));
    if (ret == ASSET_SUCCESS) {
        // The asset that supports sync is added successfully.
    } else {
        // The asset that supports sync failed to be added.
    }
}
```

## Accessing the Backup and Restore Extension Capability

To trigger the backup and restore of application data, see [Accessing Backup and Restore](../../file-management/app-file-backup-extension.md).

## Querying the Sync Result of Assets

### Available APIs

You can call **OH_Asset_QuerySyncResult** to query the sync result of assets. For more information, see the API reference.

The following table describes the attributes for querying an asset.

| Attribute Name (Asset_Tag)           | Attribute Content (Asset_Value)                                      | Mandatory or Not| Description                                                        |
| ------------------------------- | ------------------------------------------------------------ | -------- | ------------------------------------------------------------ |
| ASSET_TAG_REQUIRE_ATTR_ENCRYPTED<sup>14+</sup> | Type: bool| Yes| Whether to query the sync result of the asset whose custom additional information is encrypted. The value **true** means to query the sync result; the value **false** means the opposite. The default value is **false**.|
| ASSET_TAG_GROUP_ID<sup>18+</sup> | Type: Uint8[]<br>Length: 7-127 bytes| Yes| Group to which the asset to be queried belongs. By default, this parameter is not specified.|


### Sample Code

```c
#include <string.h>

#include "asset/asset_api.h"

void QuerySyncResults() {
    Asset_SyncResult syncResult = {0};
    int32_t ret = OH_Asset_QuerySyncResult(NULL, 0, &syncResult);
    if (ret == ASSET_SUCCESS) {
        // The asset sync result is successfully queried.
    } else {
        // The asset sync result failed to be queried.
    }
}
```

## Notes and Constraints

For a successful sync between trusted devices, the assets of both old and new devices must be accessible. Otherwise, the sync might fail.

* For assets that are accessible only when a password is set, the sync will fail if no lock screen password is set on either the old or new device.
  
* For assets that are accessible only when the screen is unlocked, the sync will fail if the screen of either the old or new device is locked.

* For assets that are accessible only after user authentication, the sync will fail if no lock screen password is set on the old device.
