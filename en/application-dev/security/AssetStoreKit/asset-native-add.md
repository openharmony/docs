# Adding an Asset (C/C++)

## Available APIs

For details about the API, see:

[int32_t OH_Asset_Add(const Asset_Attr *attributes, uint32_t attrCnt)](../../reference/apis-asset-store-kit/_asset_api.md#oh_asset_add)

The following table describes the parameters of **AssetMap**.

| Attribute Name (Asset_Tag)           | Attribute Content (Asset_Value)                                      | Mandatory| Description                                                        |
| ------------------------------- | ------------------------------------------------------------ | -------- | ------------------------------------------------------------ |
| ASSET_TAG_SECRET                | Type: uint8[]<br>Length: 1-1024 bytes                             | Yes    | Asset plaintext.                                                |
| ASSET_TAG_ALIAS                 | Type: uint8[]<br>Length: 1-256 bytes                              | Yes    | Asset alias, which uniquely identifies an asset.                        |
| ASSET_TAG_ACCESSIBILITY         | Type: uint32_t<br>Value range: see [Asset_Accessibility](../../reference/apis-asset-store-kit/_asset_type.md#asset_accessibility)| No    | Access control based on the lock screen status.                                                |
| ASSET_TAG_REQUIRE_PASSWORD_SET  | Type: bool                                                  | No    | Whether the asset is accessible only when a lock screen password is set.                |
| ASSET_TAG_AUTH_TYPE             | Type: uint32_t<br>Value range: see [Asset_AuthType](../../reference/apis-asset-store-kit/_asset_type.md#asset_authtype)| No    | Type of user authentication required for accessing the asset.                              |
| ASSET_TAG_SYNC_TYPE             | Type: uint32_t<br>Value range: see [Asset_SyncType](../../reference/apis-asset-store-kit/_asset_type.md#asset_synctype)| No    | Type of sync supported by the asset.                                      |
| ASSET_TAG_IS_PERSISTENT         | Type: bool                                                  | No    | Whether to retain the asset when the application is uninstalled.<br>**Required permissions**: ohos.permission.STORE_PERSISTENT_DATA|
| ASSET_TAG_DATA_LABEL_CRITICAL_1 | Type: uint8[]<br>Length: 1-512 bytes                              | No    | Additional asset data customized by the service with integrity protection.            |
| ASSET_TAG_DATA_LABEL_CRITICAL_2 | Type: uint8[]<br>Length: 1-512 bytes                              | No    | Additional asset data customized by the service with integrity protection.            |
| ASSET_TAG_DATA_LABEL_CRITICAL_3 | Type: uint8[]<br>Length: 1-512 bytes                              | No    | Additional asset data customized by the service with integrity protection.            |
| ASSET_TAG_DATA_LABEL_CRITICAL_4 | Type: uint8[]<br>Length: 1-512 bytes                              | No    | Additional asset data customized by the service with integrity protection.            |
| ASSET_TAG_DATA_LABEL_NORMAL_1   | Type: uint8[]<br>Length: 1-512 bytes                              | No    | Additional asset data customized by the service without integrity protection.            |
| ASSET_TAG_DATA_LABEL_NORMAL_2   | Type: uint8[]<br>Length: 1-512 bytes                              | No    | Additional asset data customized by the service without integrity protection.            |
| ASSET_TAG_DATA_LABEL_NORMAL_3   | Type: uint8[]<br>Length: 1-512 bytes                              | No    | Additional asset data customized by the service without integrity protection.            |
| ASSET_TAG_DATA_LABEL_NORMAL_4   | Type: uint8[]<br>Length: 1-512 bytes                              | No    | Additional asset data customized by the service without integrity protection.            |
| ASSET_TAG_CONFLICT_RESOLUTION   | Type: uint32_t<br>Value range: see [Asset_ConflictResolution](../../reference/apis-asset-store-kit/_asset_type.md#asset_conflictresolution)| No    | Policy for resolving the conflict (for example, a duplicate alias).                            |

## Example

Add an asset with password of **demo_pwd**, alias of **demo_alias**, and additional information of **demo_label** and allow the asset to be accessed after the device is unlocked for the first time.

1. Add the dynamic library in the CMake script.
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

## Constraints

* Alias-based access

  Assets are stored in the ASSET database in ciphertext and uniquely identified by the service identity and alias. The alias of each asset must be unique.

* Custom service data storage

  ASSET provides 8 custom asset attributes starting with **ASSET_TAG_DATA_LABEL** for services. If the 8 custom attributes are used, you can combine multiple data segments in a certain format (for example, JSON) into an ASSET attribute.

  ASSET protects the integrity of the attributes starting with **ASSET_TAG_DATA_LABEL_CRITICAL**. These attributes cannot be changed once written.