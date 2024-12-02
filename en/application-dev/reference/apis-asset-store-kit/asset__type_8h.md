# asset_type.h


## Overview

Defines the enums, structs, and error codes used in the asset store service (ASSET).

**Library**: libasset_ndk.z.so

**System capability**: SystemCapability.Security.Asset

**Since**: 11

**Related module**: [AssetType](_asset_type.md)


## Summary


### Structs

| Name| Description|
| -------- | -------- |
| struct  [Asset_Blob](_asset___blob.md) | Defines a binary array, that is, an array of bytes with variable length.|
| union  [Asset_Value](union_asset___value.md) | Represents the value of an asset attribute.|
| struct  [Asset_Attr](_asset___attr.md) | Represents an asset attribute in the form of a key-value (KV) pair.|
| struct  [Asset_Result](_asset___result.md) | Represents the query result of an asset.|
| struct  [Asset_ResultSet](_asset___result_set.md) | Represents the query result of multiple assets.|


### Macros

| Name| Description|
| -------- | -------- |
| [ASSET_TAG_TYPE_MASK](_asset_type.md#asset_tag_type_mask)   (0xF &lt;&lt; 28) | Defines the mask used to obtain the key type of an asset attribute.|


### Enums

| Name| Description|
| -------- | -------- |
| [Asset_TagType](_asset_type.md#asset_tagtype) {<br>ASSET_TYPE_BOOL = 0x1 &lt;&lt; 28,<br>ASSET_TYPE_NUMBER = 0x2 &lt;&lt; 28,<br>ASSET_TYPE_BYTES = 0x3 &lt;&lt; 28 } | Enumerates the tag types of asset attributes. |
| [Asset_Tag](_asset_type.md#asset_tag) {<br/>ASSET_TAG_SECRET = ASSET_TYPE_BYTES \| 0x01,<br/>ASSET_TAG_ALIAS = ASSET_TYPE_BYTES \| 0x02,<br/>ASSET_TAG_ACCESSIBILITY = ASSET_TYPE_NUMBER \| 0x03,<br/>ASSET_TAG_REQUIRE_PASSWORD_SET = ASSET_TYPE_BOOL \| 0x04,<br/>ASSET_TAG_AUTH_TYPE = ASSET_TYPE_NUMBER \| 0x05,<br/>ASSET_TAG_AUTH_VALIDITY_PERIOD = ASSET_TYPE_NUMBER \| 0x06,<br/>ASSET_TAG_AUTH_CHALLENGE = ASSET_TYPE_BYTES \| 0x07,<br/>ASSET_TAG_AUTH_TOKEN = ASSET_TYPE_BYTES \| 0x08,<br/>ASSET_TAG_SYNC_TYPE = ASSET_TYPE_NUMBER \| 0x10,<br/>ASSET_TAG_IS_PERSISTENT = ASSET_TYPE_BOOL \| 0x11,<br/>ASSET_TAG_DATA_LABEL_CRITICAL_1 = ASSET_TYPE_BYTES \| 0x20,<br/>ASSET_TAG_DATA_LABEL_CRITICAL_2 = ASSET_TYPE_BYTES \| 0x21,<br/>ASSET_TAG_DATA_LABEL_CRITICAL_3 = ASSET_TYPE_BYTES \| 0x22,<br/>ASSET_TAG_DATA_LABEL_CRITICAL_4 = ASSET_TYPE_BYTES \| 0x23,<br/>ASSET_TAG_DATA_LABEL_NORMAL_1 = ASSET_TYPE_BYTES \| 0x30,<br/>ASSET_TAG_DATA_LABEL_NORMAL_2 = ASSET_TYPE_BYTES \| 0x31,<br/>ASSET_TAG_DATA_LABEL_NORMAL_3 = ASSET_TYPE_BYTES \| 0x32,<br/>ASSET_TAG_DATA_LABEL_NORMAL_4 = ASSET_TYPE_BYTES \| 0x33,<br/>ASSET_TAG_DATA_LABEL_NORMAL_LOCAL_1<sup>12+</sup> = ASSET_TYPE_BYTES \| 0x34,<br/>ASSET_TAG_DATA_LABEL_NORMAL_LOCAL_2<sup>12+</sup> = ASSET_TYPE_BYTES \| 0x35,<br/>ASSET_TAG_DATA_LABEL_NORMAL_LOCAL_3<sup>12+</sup> = ASSET_TYPE_BYTES \| 0x36,<br/>ASSET_TAG_DATA_LABEL_NORMAL_LOCAL_4<sup>12+</sup> = ASSET_TYPE_BYTES \| 0x37,<br/>ASSET_TAG_RETURN_TYPE = ASSET_TYPE_NUMBER \| 0x40,<br/>ASSET_TAG_RETURN_LIMIT = ASSET_TYPE_NUMBER \| 0x41,<br/>ASSET_TAG_RETURN_OFFSET = ASSET_TYPE_NUMBER \| 0x42,<br/>ASSET_TAG_RETURN_ORDERED_BY = ASSET_TYPE_NUMBER \| 0x43,<br/>ASSET_TAG_CONFLICT_RESOLUTION = ASSET_TYPE_NUMBER \| 0x44,<br/>ASSET_TAG_UPDATE_TIME<sup>12+</sup> = ASSET_TYPE_BYTES \| 0x45,<br/>ASSET_TAG_OPERATION_TYPE<sup>12+</sup> = ASSET_TYPE_NUMBER \| 0x46<br/>} | Enumerates the tags of asset attributes. | 
| [Asset_ResultCode](_asset_type.md#asset_resultcode) {<br>ASSET_SUCCESS = 0,<br>ASSET_PERMISSION_DENIED = 201,<br>ASSET_INVALID_ARGUMENT = 401,<br>ASSET_SERVICE_UNAVAILABLE = 24000001,<br>ASSET_NOT_FOUND = 24000002,<br>ASSET_DUPLICATED = 24000003,<br>ASSET_ACCESS_DENIED = 24000004,<br>ASSET_STATUS_MISMATCH = 24000005,<br>ASSET_OUT_OF_MEMORY = 24000006,<br>ASSET_DATA_CORRUPTED = 24000007,<br>ASSET_DATABASE_ERROR = 24000008,<br>ASSET_CRYPTO_ERROR = 24000009,<br>ASSET_IPC_ERROR = 24000010,<br>ASSET_BMS_ERROR = 24000011,<br>ASSET_ACCOUNT_ERROR = 24000012,<br>ASSET_ACCESS_TOKEN_ERROR = 24000013,<br>ASSET_FILE_OPERATION_ERROR = 24000014,<br>ASSET_GET_SYSTEM_TIME_ERROR = 24000015,<br>ASSET_LIMIT_EXCEEDED = 24000016,<br>ASSET_UNSUPPORTED = 24000017<br>} | Enumerates the result codes returned by ASSET functions.|
| [Asset_Accessibility](_asset_type.md#asset_accessibility) {<br>ASSET_ACCESSIBILITY_DEVICE_POWERED_ON = 0,<br>ASSET_ACCESSIBILITY_DEVICE_FIRST_UNLOCKED = 1,<br>ASSET_ACCESSIBILITY_DEVICE_UNLOCKED = 2<br>} | Enumerates the types of access control based on the lock screen status.|
| [Asset_AuthType](_asset_type.md#asset_authtype) { ASSET_AUTH_TYPE_NONE = 0x00,<br>ASSET_AUTH_TYPE_ANY = 0xFF } | Enumerates the user authentication types supported by assets. |
| [Asset_SyncType](_asset_type.md#asset_synctype) {<br>ASSET_SYNC_TYPE_NEVER = 0,<br>ASSET_SYNC_TYPE_THIS_DEVICE = 1 &lt;&lt; 0,<br>ASSET_SYNC_TYPE_TRUSTED_DEVICE = 1 &lt;&lt; 1,<br>ASSET_SYNC_TYPE_TRUSTED_ACCOUNT<sup>12+</sup> = 1 &lt;&lt; 2<br>} | Enumerates the sync types supported by assets.|
| [Asset_ConflictResolution](_asset_type.md#asset_conflictresolution) {<br>ASSET_CONFLICT_OVERWRITE = 0,<br>ASSET_CONFLICT_THROW_ERROR = 1<br>} | Enumerates the policies for resolving the conflict (for example, a duplicate alias).|
| [Asset_ReturnType](_asset_type.md#asset_returntype) {<br>ASSET_RETURN_ALL = 0,<br>ASSET_RETURN_ATTRIBUTES = 1<br>} | Enumerates the types of the asset query result to return.|
| [Asset_OperationType](_asset_type.md#asset_operationtype)<sup>12+</sup> {<br>ASSET_NEED_SYNC = 0,<br>ASSET_NEED_LOGOUT = 1<br>} | Enumerates the additional asset operation types.|
