# Querying Assets (C/C++)

## Available APIs

You can use [OH_Asset_Query](../../reference/apis-asset-store-kit/_asset_api.md#oh_asset_query) to query asset
information.

The following table describes the attributes for querying an asset.

>**NOTE**
>
>In the following table, the attributes starting with **ASSET_TAG_DATA_LABEL** are custom asset attributes reserved. These attributes are not encrypted. Therefore, do not put personal data in these attributes.

| Attribute Name (Asset_Tag)           | Attribute Content (Asset_Value)                                      | Mandatory| Description                                                        |
| ------------------------------- | ------------------------------------------------------------ | -------- | ------------------------------------------------------------ |
| ASSET_TAG_ALIAS                 | Type: uint8[]<br>Length: 1-256 bytes                              | No    | Asset alias, which uniquely identifies an asset.                      |
| ASSET_TAG_ACCESSIBILITY         | Type: uint32_t<br>Value range: see [Asset_Accessibility](../../reference/apis-asset-store-kit/_asset_type.md#asset_accessibility)| No    | Access control based on the lock screen status.                                                |
| ASSET_TAG_REQUIRE_PASSWORD_SET  | Type: bool                                                  | No    | Whether the asset is accessible only when a lock screen password is set.                |
| ASSET_TAG_AUTH_TYPE             | Type: uint32_t<br>Value range: see [Asset_AuthType](../../reference/apis-asset-store-kit/_asset_type.md#asset_authtype)| No    | Type of user authentication required for accessing the asset.                              |
| ASSET_TAG_SYNC_TYPE             | Type: uint32_t<br>Value range: see [Asset_SyncType](../../reference/apis-asset-store-kit/_asset_type.md#asset_synctype)| No    | Type of sync supported by the asset.                                      |
| ASSET_TAG_IS_PERSISTENT         | Type: bool                                                  | No    | Whether to retain the asset when the application is uninstalled.                            |
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
| ASSET_TAG_RETURN_TYPE           | Type: uint32_t<br>Value range: see [Asset_ReturnType](../../reference/apis-asset-store-kit/_asset_type.md#asset_returntype)| No    | Type of the asset query result to return.                                        |
| ASSET_TAG_RETURN_LIMIT          | Type: uint32_t                                              | No    | Maximum number of asset records to return.                                        |
| ASSET_TAG_RETURN_OFFSET         | Type: uint32_t<br>Value range: 1-65536                           | No    | Offset of the asset query result.<br>**NOTE**: This parameter specifies the starting asset record to return in batch asset query.                 |
| ASSET_TAG_RETURN_ORDERED_BY     | Type: uint32_t<br>Value: ASSET_TAG_DATA_LABEL_xxx          | No    | How the query results are sorted. Currently, the results can be sorted only by **ASSET_TAG_DATA_LABEL**.<br>**NOTE**: By default, assets are returned in the order in which they are added.|
| ASSET_TAG_REQUIRE_ATTR_ENCRYPTED<sup>14+</sup> | Type: bool| No| Whether to query the customized asset attribute information that is encrypted. By default, the unencrypted, customized asset attribute information is queried.|
| ASSET_TAG_GROUP_ID<sup>18+</sup> | Type: Uint8[]<br>Length: 7-127 bytes| No| Group to which the asset to be queried belongs. By default, this parameter is not specified.|

## Constraints

The assets queried are transmitted to the service through an IPC channel. Due to the limitation of the IPC buffer size, the maximum number of assets to be queried at a time cannot exceed 40.

## Example

### Querying the Plaintext of an Asset

Query the plaintext of asset **demo_alias**.

For details about how to query the plaintext of an asset in a group, see [Querying the Plaintext of an Asset in a Group](asset-native-group-access-control.md#querying-the-plaintext-of-an-asset-in-a-group).

1. Add the dynamic library in the CMake script.
   ```txt
   target_link_libraries(entry PUBLIC libasset_ndk.z.so)
   ```

2. Add an asset.
   ```c
   #include <string.h>

   #include "asset/asset_api.h"

   void QueryAsset() {
      static const char *ALIAS = "demo_alias";
      Asset_Blob alias = { (uint32_t)(strlen(ALIAS)), (uint8_t *)ALIAS };
      Asset_Attr attr[] = {
         { .tag = ASSET_TAG_ALIAS, .value.blob = alias },  // Specify the alias of the asset to query.
         { .tag = ASSET_TAG_RETURN_TYPE, .value.u32 = ASSET_RETURN_ALL }, // Return all asset information, including the attributes and asset plaintext.
      };

      Asset_ResultSet resultSet = {0};
      int32_t ret = OH_Asset_Query(attr, sizeof(attr) / sizeof(attr[0]), &resultSet);
      if (ret == ASSET_SUCCESS) {
         // Parse the resultSet.
         for (uint32_t i = 0; i < resultSet.count; i++) {
               // Parse the secret: the data is secret->blob.data, the size is secret->blob.size.
               Asset_Attr *secret = OH_Asset_ParseAttr(resultSet.results + i, ASSET_TAG_SECRET);
         }
      }
      OH_Asset_FreeResultSet(&resultSet);
   }
   ```

### Querying Attributes of an Asset

Query attributes of asset **demo_alias**.

For details about how to query the attributes of an asset in a group, see [Querying the Attributes of an Asset in a Group](asset-native-group-access-control.md#querying-the-attributes-of-an-asset-in-a-group).

1. Add the dynamic library in the CMake script.
   ```txt
   target_link_libraries(entry PUBLIC libasset_ndk.z.so)
   ```

2. Add an asset.
   ```c
   #include <string.h>

   #include "asset/asset_api.h"

   void QueryAttributes() {
      static const char *ALIAS = "demo_alias";
      Asset_Blob alias = { (uint32_t)(strlen(ALIAS)), (uint8_t *)ALIAS };
      Asset_Attr attr[] = {
         { .tag = ASSET_TAG_ALIAS, .value.blob = alias },  // Specify the alias of the asset to query.
         { .tag = ASSET_TAG_RETURN_TYPE, .value.u32 = ASSET_RETURN_ATTRIBUTES }, // Return only the asset attributes, that is, the result does not include the asset plaintext.
      };

      Asset_ResultSet resultSet = {0};
      int32_t ret = OH_Asset_Query(attr, sizeof(attr) / sizeof(attr[0]), &resultSet);
      if (ret == ASSET_SUCCESS) {
         // Parse the result.
         for (uint32_t i = 0; i < resultSet.count; i++) {
         // Parse the data label: the data is label->blob.data, the size is label->blob.size.
               Asset_Attr *label = OH_Asset_ParseAttr(resultSet.results + i, ASSET_TAG_DATA_LABEL_NORMAL_1);
         }
      }
      OH_Asset_FreeResultSet(&resultSet);
   }
   ```

### Querying Attributes of Assets

Query attributes of assets with the tag of **demo_label** and return a total of 10 records sorted by **DATA_LABEL_NORMAL_1** starting from the fifth record that matches the search criteria.

1. Add the dynamic library in the CMake script.
   ```txt
   target_link_libraries(entry PUBLIC libasset_ndk.z.so)
   ```

2. Add an asset.
   ```c
   #include <string.h>

   #include "asset/asset_api.h"

   void BatchQuery() {
      static const char *LABEL = "demo_label";
      Asset_Blob label = { (uint32_t)(strlen(LABEL)), (uint8_t *)LABEL };

      Asset_Attr attr[] = {
         { .tag = ASSET_TAG_RETURN_TYPE, .value.u32 = ASSET_RETURN_ATTRIBUTES },
         { .tag = ASSET_TAG_DATA_LABEL_NORMAL_1, .value.blob = label },
         { .tag = ASSET_TAG_RETURN_OFFSET, .value.u32 = 5 },
         { .tag = ASSET_TAG_RETURN_LIMIT, .value.u32 = 10 },
         { .tag = ASSET_TAG_RETURN_ORDERED_BY, .value.u32 = ASSET_TAG_DATA_LABEL_NORMAL_1 },
      };

      Asset_ResultSet resultSet = { 0 };
      int32_t ret = OH_Asset_Query(attr, sizeof(attr) / sizeof(attr[0]), &resultSet);
      if (ret == ASSET_SUCCESS) {
         // Parse the result.
         for (uint32_t i = 0; i < resultSet.count; i++) {
               // Parse the data alias: the data is alias->blob.data, the size is alias->blob.size.
               Asset_Attr *alias = OH_Asset_ParseAttr(resultSet.results + i, ASSET_TAG_ALIAS);
         }
      }
      OH_Asset_FreeResultSet(&resultSet);
   }
   ```
