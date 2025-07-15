# Adding an Asset (C/C++)

## Available APIs

You can use [OH_Asset_Add](../../reference/apis-asset-store-kit/capi-asset-api-h.md#oh_asset_add) to add an asset.

The following table describes the attributes for adding an asset.

>**NOTE**
>
>In the following table, the attributes starting with **DATA_LABEL** are custom asset attributes reserved for services. These attributes are not encrypted. Therefore, do not put personal data in these attributes.

| Attribute Name (Asset_Tag)           | Attribute Content (Asset_Value)                                      | Mandatory| Description                                                        |
| ------------------------------- | ------------------------------------------------------------ | -------- | ------------------------------------------------------------ |
| ASSET_TAG_SECRET                | Type: uint8[]<br>Length: 1-1024 bytes                             | Yes    | Asset in plaintext.                                                |
| ASSET_TAG_ALIAS                 | Type: uint8[]<br>Length: 1-256 bytes                              | Yes    | Asset alias, which uniquely identifies an asset.                        |
| ASSET_TAG_ACCESSIBILITY         | Type: uint32_t<br>Value range: see [Asset_Accessibility](../../reference/apis-asset-store-kit/capi-asset-type-h.md#asset_accessibility).| No    | Access control based on whether the screen is locked. The default value is **ASSET_ACCESSIBILITY_DEVICE_FIRST_UNLOCKED**, indicating that the asset can be accessed after the device is unlocked for the first time.                      |
| ASSET_TAG_REQUIRE_PASSWORD_SET  | Type: bool                                                  | No    | Whether the asset is accessible only when a lock screen password is set. The value **true** means that the asset can be accessed only when the user sets a screen lock password. The value **false** means that the asset can be accessed regardless of whether the user sets a screen lock password. The default value is **false**.                |
| ASSET_TAG_AUTH_TYPE             | Type: uint32_t<br>Value range: see [Asset_AuthType](../../reference/apis-asset-store-kit/capi-asset-type-h.md#asset_authtype).| No    | User authentication type required for accessing an asset. The default value is **ASSET_AUTH_TYPE_NONE**, indicating that user authentication is not required before the user accesses an asset.  |
| ASSET_TAG_SYNC_TYPE             | Type: uint32_t<br>Value range: see [Asset_SyncType](../../reference/apis-asset-store-kit/capi-asset-type-h.md#asset_synctype).| No    | Sync type supported by the asset. The default value is **ASSET_SYNC_TYPE_NEVER**, indicating that the asset cannot be synced.           |
| ASSET_TAG_IS_PERSISTENT         | Type: bool                                                  | No    | Whether to retain the asset when the application is uninstalled. The value **true** means to retain the asset when the application is uninstalled; the value **false** means the opposite. Default value: **false**.<br>**NOTE**: If this parameter is set, the application must [apply for](../AccessToken/declare-permissions.md) the ohos.permission.STORE_PERSISTENT_DATA permission.|
| ASSET_TAG_DATA_LABEL_CRITICAL_1 | Type: uint8[]<br>Length: 1-2048 bytes                          | No    | Asset attribute information customized by the service with integrity protection.<br>**NOTE**: The data length is 1 to 512 bytes before API version 12.|
| ASSET_TAG_DATA_LABEL_CRITICAL_2 | Type: uint8[]<br>Length: 1-2048 bytes                          | No    | Asset attribute information customized by the service with integrity protection.<br>**NOTE**: The data length is 1 to 512 bytes before API version 12.|
| ASSET_TAG_DATA_LABEL_CRITICAL_3 | Type: uint8[]<br>Length: 1-2048 bytes                          | No    | Asset attribute information customized by the service with integrity protection.<br>**NOTE**: The data length is 1 to 512 bytes before API version 12.|
| ASSET_TAG_DATA_LABEL_CRITICAL_4 | Type: uint8[]<br>Length: 1-2048 bytes                          | No    | Asset attribute information customized by the service with integrity protection.<br>**NOTE**: The data length is 1 to 512 bytes before API version 12.|
| ASSET_TAG_DATA_LABEL_NORMAL_1   | Type: uint8[]<br>Length: 1-2048 bytes                          | No    | Asset attribute information customized by the service without integrity protection.<br>**NOTE**: The data length is 1 to 512 bytes before API version 12.|
| ASSET_TAG_DATA_LABEL_NORMAL_2   | Type: uint8[]<br>Length: 1-2048 bytes                          | No    | Asset attribute information customized by the service without integrity protection.<br>**NOTE**: The data length is 1 to 512 bytes before API version 12.|
| ASSET_TAG_DATA_LABEL_NORMAL_3   | Type: uint8[]<br>Length: 1-2048 bytes                          | No    | Asset attribute information customized by the service without integrity protection.<br>**NOTE**: The data length is 1 to 512 bytes before API version 12.|
| ASSET_TAG_DATA_LABEL_NORMAL_4   | Type: uint8[]<br>Length: 1-2048 bytes                          | No    | Asset attribute information customized by the service without integrity protection.<br>**NOTE**: The data length is 1 to 512 bytes before API version 12.|
| ASSET_TAG_DATA_LABEL_NORMAL_LOCAL_1<sup>12+</sup> | Type: uint8[]<br>Length: 1-2048 bytes| No| Local attribute information about the asset. The value is assigned by the service without integrity protection and will not be synced.|
| ASSET_TAG_DATA_LABEL_NORMAL_LOCAL_2<sup>12+</sup> | Type: uint8[]<br>Length: 1-2048 bytes| No| Local attribute information about the asset. The value is assigned by the service without integrity protection and will not be synced.|
| ASSET_TAG_DATA_LABEL_NORMAL_LOCAL_3<sup>12+</sup> | Type: uint8[]<br>Length: 1-2048 bytes| No| Local attribute information about the asset. The value is assigned by the service without integrity protection and will not be synced.|
| ASSET_TAG_DATA_LABEL_NORMAL_LOCAL_4<sup>12+</sup> | Type: uint8[]<br>Length: 1-2048 bytes| No| Local attribute information about the asset. The value is assigned by the service without integrity protection and will not be synced.|
| ASSET_TAG_CONFLICT_RESOLUTION   | Type: uint32_t<br>Value range: see [Asset_ConflictResolution](../../reference/apis-asset-store-kit/capi-asset-type-h.md#asset_conflictresolution).| No    | Conflict (for example, duplicate aliases) resolution when an asset is added. The default value is **ASSET_CONFLICT_THROW_ERROR**, indicating that an exception is thrown for subsequent processing by the service.            |
| ASSET_TAG_REQUIRE_ATTR_ENCRYPTED<sup>14+</sup> | Type: bool| No| Whether to encrypt the additional asset information customized by the service. The value **true** means to encrypt the additional asset information customized by the service; the value **false** means the opposite. Default value: **false**.|
| ASSET_TAG_GROUP_ID<sup>18+</sup> | Type: Uint8[]<br>Length: 7-127 bytes| No| Group to which the asset to be added belongs. By default, this parameter is not specified.|
| ASSET_TAG_WRAP_TYPE<sup>18+</sup> |Type: uint32_t<br>Value range: see [Asset_WrapType](../../reference/apis-asset-store-kit/capi-asset-type-h.md#asset_wraptype).| No| Encrypted import/export type supported by the asset. The default value is **ASSET_WRAP_TYPE_NEVER**, indicating that encrypted import/export is not supported.|

## Constraints

* Alias-based access

  Assets are stored in the ASSET database in ciphertext. The service identity and alias are used as the unique index. The alias of each asset must be unique.

* Custom service data storage

  ASSET provides 12 custom asset attributes starting with **ASSET_TAG_DATA_LABEL** for services. If the 12 custom attributes are used, you can combine multiple data segments in a certain format (for example, JSON) into an ASSET attribute.

  ASSET protects the integrity of the attributes starting with **ASSET_TAG_DATA_LABEL_CRITICAL**. These attributes cannot be changed once written.

## Example

Add an asset with the password **demo_pwd**, alias **demo_alias**, and additional attribute **demo_label**. The asset can be accessed after the device is unlocked for the first time.

For details about how to add an asset to a group, see [Adding an Asset to a Group](asset-native-group-access-control.md#adding-an-asset-to-a-group).

1. Link the dynamic libraries in the CMake script.
   ```txt
   target_link_libraries(entry PUBLIC libasset_ndk.z.so)
   ```

2. Add an asset.
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
         { .tag = ASSET_TAG_ACCESSIBILITY, .value.u32 = ASSET_ACCESSIBILITY_DEVICE_FIRST_UNLOCKED },
         { .tag = ASSET_TAG_SECRET, .value.blob = secret },
         { .tag = ASSET_TAG_ALIAS, .value.blob = alias },
         { .tag = ASSET_TAG_DATA_LABEL_NORMAL_1, .value.blob = label },
      };

      int32_t ret = OH_Asset_Add(attr, sizeof(attr) / sizeof(attr[0]));
      if (ret == ASSET_SUCCESS) {
         // Asset added successfully.
      } else {
         // Failed to add Asset.
      }
   }
   ```
