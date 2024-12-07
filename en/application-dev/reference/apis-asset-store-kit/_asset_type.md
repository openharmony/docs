# AssetType


## Overview

Defines the enums, structs, and error codes used in the asset store service (ASSET).

**System capability**: SystemCapability.Security.Asset

**Since**: 11


## Summary


### Files

| Name| Description|
| -------- | -------- |
| [asset_type.h](asset__type_8h.md) | Defines the enums, structs, and error codes used in the ASSET. |


### Structs

| Name| Description|
| -------- | -------- |
| struct  [Asset_Blob](_asset___blob.md) | Defines a binary array, that is, an array of bytes with variable length.|
| union  [Asset_Value](union_asset___value.md) | Defines the value of an asset attribute. |
| struct  [Asset_Attr](_asset___attr.md) | Defines an asset attribute in the form of a key-value (KV) pair. |
| struct  [Asset_Result](_asset___result.md) | Defines the query result of an asset. |
| struct  [Asset_ResultSet](_asset___result_set.md) | Defines the query result of multiple assets. |


### Macros

| Name| Description|
| -------- | -------- |
| [ASSET_TAG_TYPE_MASK](#asset_tag_type_mask)   (0xF &lt;&lt; 28) | Defines the mask used to obtain the tag type of an asset attribute. |


### Enums

| Name| Description|
| -------- | -------- |
| [Asset_TagType](#asset_tagtype) {<br>ASSET_TYPE_BOOL = 0x1 &lt;&lt; 28,<br>ASSET_TYPE_NUMBER = 0x2 &lt;&lt; 28,<br>ASSET_TYPE_BYTES = 0x3 &lt;&lt; 28 } | Enumerates the tag types of the asset attributes. |
| [Asset_Tag](#asset_tag) {<br>ASSET_TAG_SECRET = ASSET_TYPE_BYTES \| 0x01,<br>ASSET_TAG_ALIAS = ASSET_TYPE_BYTES \| 0x02,<br>ASSET_TAG_ACCESSIBILITY = ASSET_TYPE_NUMBER \| 0x03,<br>ASSET_TAG_REQUIRE_PASSWORD_SET = ASSET_TYPE_BOOL \| 0x04,<br>ASSET_TAG_AUTH_TYPE = ASSET_TYPE_NUMBER \| 0x05,<br>ASSET_TAG_AUTH_VALIDITY_PERIOD = ASSET_TYPE_NUMBER \| 0x06,<br>ASSET_TAG_AUTH_CHALLENGE = ASSET_TYPE_BYTES \| 0x07,<br>ASSET_TAG_AUTH_TOKEN = ASSET_TYPE_BYTES \| 0x08,<br>ASSET_TAG_SYNC_TYPE = ASSET_TYPE_NUMBER \| 0x10,<br>ASSET_TAG_IS_PERSISTENT = ASSET_TYPE_BOOL \| 0x11,<br>ASSET_TAG_DATA_LABEL_CRITICAL_1 = ASSET_TYPE_BYTES \| 0x20,<br>ASSET_TAG_DATA_LABEL_CRITICAL_2 = ASSET_TYPE_BYTES \| 0x21,<br>ASSET_TAG_DATA_LABEL_CRITICAL_3 = ASSET_TYPE_BYTES \| 0x22,<br>ASSET_TAG_DATA_LABEL_CRITICAL_4 = ASSET_TYPE_BYTES \| 0x23,<br>ASSET_TAG_DATA_LABEL_NORMAL_1 = ASSET_TYPE_BYTES \| 0x30,<br>ASSET_TAG_DATA_LABEL_NORMAL_2 = ASSET_TYPE_BYTES \| 0x31,<br>ASSET_TAG_DATA_LABEL_NORMAL_3 = ASSET_TYPE_BYTES \| 0x32,<br>ASSET_TAG_DATA_LABEL_NORMAL_4 = ASSET_TYPE_BYTES \| 0x33,<br>ASSET_TAG_DATA_LABEL_NORMAL_LOCAL_1<sup>12+</sup> = ASSET_TYPE_BYTES \| 0x34,<br>ASSET_TAG_DATA_LABEL_NORMAL_LOCAL_2<sup>12+</sup> = ASSET_TYPE_BYTES \| 0x35,<br>ASSET_TAG_DATA_LABEL_NORMAL_LOCAL_3<sup>12+</sup> = ASSET_TYPE_BYTES \| 0x36,<br>ASSET_TAG_DATA_LABEL_NORMAL_LOCAL_4<sup>12+</sup> = ASSET_TYPE_BYTES \| 0x37,<br>ASSET_TAG_RETURN_TYPE = ASSET_TYPE_NUMBER \| 0x40,<br>ASSET_TAG_RETURN_LIMIT = ASSET_TYPE_NUMBER \| 0x41,<br>ASSET_TAG_RETURN_OFFSET = ASSET_TYPE_NUMBER \| 0x42,<br>ASSET_TAG_RETURN_ORDERED_BY = ASSET_TYPE_NUMBER \| 0x43,<br>ASSET_TAG_CONFLICT_RESOLUTION = ASSET_TYPE_NUMBER \| 0x44,<br>ASSET_TAG_UPDATE_TIME<sup>12+</sup> = ASSET_TYPE_BYTES \| 0x45,<br>ASSET_TAG_OPERATION_TYPE<sup>12+</sup> = ASSET_TYPE_NUMBER \| 0x46,<br>} | Enumerates the tags of asset attributes. | 
| [Asset_ResultCode](#asset_resultcode) {<br>ASSET_SUCCESS = 0,<br>ASSET_PERMISSION_DENIED = 201,<br>ASSET_INVALID_ARGUMENT = 401,<br>ASSET_SERVICE_UNAVAILABLE = 24000001,<br>ASSET_NOT_FOUND = 24000002,<br>ASSET_DUPLICATED = 24000003,<br>ASSET_ACCESS_DENIED = 24000004,<br>ASSET_STATUS_MISMATCH = 24000005,<br>ASSET_OUT_OF_MEMORY = 24000006,<br>ASSET_DATA_CORRUPTED = 24000007,<br>ASSET_DATABASE_ERROR = 24000008,<br>ASSET_CRYPTO_ERROR = 24000009,<br>ASSET_IPC_ERROR = 24000010,<br>ASSET_BMS_ERROR = 24000011,<br>ASSET_ACCOUNT_ERROR = 24000012,<br>ASSET_ACCESS_TOKEN_ERROR = 24000013,<br>ASSET_FILE_OPERATION_ERROR = 24000014,<br>ASSET_GET_SYSTEM_TIME_ERROR = 24000015,<br>ASSET_LIMIT_EXCEEDED = 24000016,<br>ASSET_UNSUPPORTED = 24000017<br>} | Enumerates the result codes returned by ASSET functions.|
| [Asset_Accessibility](#asset_accessibility) {<br>ASSET_ACCESSIBILITY_DEVICE_POWERED_ON = 0,<br>ASSET_ACCESSIBILITY_DEVICE_FIRST_UNLOCKED = 1,<br>ASSET_ACCESSIBILITY_DEVICE_UNLOCKED = 2<br>} | Enumerates the types of access control based on the lock screen status.|
| [Asset_AuthType](#asset_authtype) { ASSET_AUTH_TYPE_NONE = 0x00,<br>ASSET_AUTH_TYPE_ANY = 0xFF } | Enumerates the user authentication types supported by assets. | 
| [Asset_SyncType](#asset_synctype) {<br>ASSET_SYNC_TYPE_NEVER = 0,<br>ASSET_SYNC_TYPE_THIS_DEVICE = 1 &lt;&lt; 0,<br>ASSET_SYNC_TYPE_TRUSTED_DEVICE = 1 &lt;&lt; 1,<br>ASSET_SYNC_TYPE_TRUSTED_ACCOUNT<sup>12+</sup> = 1 &lt;&lt; 2<br>} | Enumerates the types of sync supported by assets.|
| [Asset_ConflictResolution](#asset_conflictresolution) {<br>ASSET_CONFLICT_OVERWRITE = 0,<br>ASSET_CONFLICT_THROW_ERROR = 1<br>} | Enumerates the policies for resolving the conflict (for example, a duplicate alias).|
| [Asset_ReturnType](#asset_returntype) {<br>ASSET_RETURN_ALL = 0,<br>ASSET_RETURN_ATTRIBUTES = 1<br>} | Enumerates the types of the asset query result to return.|
| [Asset_OperationType](#asset_operationtype) {<br>ASSET_NEED_SYNC = 0,<br>ASSET_NEED_LOGOUT = 1<br>} | Enumerates the additional asset operation types.|


## Macro Description


### ASSET_TAG_TYPE_MASK

```
#define ASSET_TAG_TYPE_MASK   (0xF << 28)
```

**Description**

Defines the mask used to obtain the tag type of an asset attribute.

**Since**: 11


## Enum Description


### Asset_Accessibility

```
enum Asset_Accessibility
```

**Description**

Enumerates the types of access control based on the lock screen status.

**Since**: 11

| Value| Description|
| -------- | -------- |
| ASSET_ACCESSIBILITY_DEVICE_POWERED_ON | The asset can be accessed after the device is powered on.|
| ASSET_ACCESSIBILITY_DEVICE_FIRST_UNLOCKED | The asset can be accessed only after the device is unlocked for the first time.|
| ASSET_ACCESSIBILITY_DEVICE_UNLOCKED | The asset can be accessed only after the device is unlocked.|


### Asset_AuthType

```
enum Asset_AuthType
```

**Description**

Enumerates the user authentication types supported by assets.

**Since**: 11

| Value| Description|
| -------- | -------- |
| ASSET_AUTH_TYPE_NONE | No user authentication is required before the asset is accessed.|
| ASSET_AUTH_TYPE_ANY | The asset can be accessed if any user authentication (such as PIN, facial, or fingerprint authentication) is successful.|


### Asset_ConflictResolution

```
enum Asset_ConflictResolution
```

**Description**

Enumerates the policies for resolving the conflict (for example, a duplicate alias).

**Since**: 11

| Value| Description|
| -------- | -------- |
| ASSET_CONFLICT_OVERWRITE | Overwrite the original asset.|
| ASSET_CONFLICT_THROW_ERROR | Throw an exception for the service to perform subsequent processing.|


### Asset_ResultCode

```
enum Asset_ResultCode
```

**Description**

Enumerates the result codes returned by ASSET functions.

**Since**: 11

| Value| Description|
| -------- | -------- |
| ASSET_SUCCESS | The operation is successful.|
| ASSET_PERMISSION_DENIED | The caller does not have the required permission.|
| ASSET_INVALID_ARGUMENT | The parameter is invalid.|
| ASSET_SERVICE_UNAVAILABLE | The asset store service is unavailable.|
| ASSET_NOT_FOUND | The asset is not found.|
| ASSET_DUPLICATED | The asset already exists.|
| ASSET_ACCESS_DENIED | The access to the asset is denied.|
| ASSET_STATUS_MISMATCH | The lock screen status does not match.|
| ASSET_OUT_OF_MEMORY | The system memory is insufficient.|
| ASSET_DATA_CORRUPTED | The asset is corrupted.|
| ASSET_DATABASE_ERROR | The database operation failed.|
| ASSET_CRYPTO_ERROR | The cryptographic operation failed.|
| ASSET_IPC_ERROR | The IPC failed.|
| ASSET_BMS_ERROR | The Bundle Manager service is abnormal.|
| ASSET_ACCOUNT_ERROR | The Account service is abnormal.|
| ASSET_ACCESS_TOKEN_ERROR | The Access Token service is abnormal.|
| ASSET_FILE_OPERATION_ERROR | The file operation failed.|
| ASSET_GET_SYSTEM_TIME_ERROR | Failed to obtain the system time.|
| ASSET_LIMIT_EXCEEDED | The number of cached assets exceeds the limit.|
| ASSET_UNSUPPORTED | The function is not supported.|


### Asset_ReturnType

```
enum Asset_ReturnType
```

**Description**

Enumerates the types of the asset query result to return.

**Since**: 11

| Value| Description|
| -------- | -------- |
| ASSET_RETURN_ALL | The query result contains the asset plaintext and its attributes.|
| ASSET_RETURN_ATTRIBUTES | The query result contains only the asset attributes.|


### Asset_SyncType

```
enum Asset_SyncType
```

**Description**

Enumerates the types of sync supported by assets.

**Since**: 11

| Value| Description|
| -------- | -------- |
| ASSET_SYNC_TYPE_NEVER | Asset sync is not allowed.|
| ASSET_SYNC_TYPE_THIS_DEVICE | Asset sync is allowed only on the local device, for example, in data restore on the local device.|
| ASSET_SYNC_TYPE_TRUSTED_DEVICE | Asset sync is allowed only between trusted devices, for example, in the case of cloning.|
| ASSET_SYNC_TYPE_TRUSTED_ACCOUNT | Asset sync is allowed only between the devices that are logged in with trusted accounts, for example, in cloud sync scenarios.<br>**Since**: 12|


### Asset_Tag

```
enum Asset_Tag
```

**Description**

Enumerates the tags of asset attributes.

**Since**: 11

| Value| Description|
| -------- | -------- |
| ASSET_TAG_SECRET | Sensitive user data in the form of bytes, such as passwords and tokens.|
| ASSET_TAG_ALIAS | Asset alias (identifier) in the form of bytes.|
| ASSET_TAG_ACCESSIBILITY | Access control based on the lock screen status. The value is of the uint32 type, which is a 32-bit unsigned integer.|
| ASSET_TAG_REQUIRE_PASSWORD_SET | Whether the asset is available only after a lock screen password is set.|
| ASSET_TAG_AUTH_TYPE | User authentication type for the asset. The value is of the uint32 type.|
| ASSET_TAG_AUTH_VALIDITY_PERIOD | Validity period of the user authentication, in seconds. The value is of the uint32 type, in seconds.|
| ASSET_TAG_AUTH_CHALLENGE | Challenge value, in the form of bytes, used for anti-replay during the authentication.|
| ASSET_TAG_AUTH_TOKEN | Authentication token, in the form of bytes, obtained after a successful user authentication.|
| ASSET_TAG_SYNC_TYPE | Asset sync type. The value is of the uint32 type.|
| ASSET_TAG_IS_PERSISTENT | Whether the asset needs to be stored persistently.|
| ASSET_TAG_DATA_LABEL_CRITICAL_1 | Custom data, which is of the bytes type and cannot be changed.|
| ASSET_TAG_DATA_LABEL_CRITICAL_2 | Custom data, which is of the bytes type and cannot be changed.|
| ASSET_TAG_DATA_LABEL_CRITICAL_3 | Custom data, which is of the bytes type and cannot be changed.|
| ASSET_TAG_DATA_LABEL_CRITICAL_4 | Custom data, which is of the bytes type and cannot be changed.|
| ASSET_TAG_DATA_LABEL_NORMAL_1 | Custom data, which is of the bytes type and can be changed.|
| ASSET_TAG_DATA_LABEL_NORMAL_2 | Custom data, which is of the bytes type and can be changed.|
| ASSET_TAG_DATA_LABEL_NORMAL_3 | Custom data, which is of the bytes type and can be changed.|
| ASSET_TAG_DATA_LABEL_NORMAL_4 | Custom data, which is of the bytes type and can be changed.|
| ASSET_TAG_DATA_LABEL_NORMAL_LOCAL_1 | Custom data, which is of the bytes type, can be changed, but cannot be synced.<br>**Since**: 12|
| ASSET_TAG_DATA_LABEL_NORMAL_LOCAL_2 | Custom data, which is of the bytes type, can be changed, but cannot be synced.<br>**Since**: 12|
| ASSET_TAG_DATA_LABEL_NORMAL_LOCAL_3 | Custom data, which is of the bytes type, can be changed, but cannot be synced.<br>**Since**: 12|
| ASSET_TAG_DATA_LABEL_NORMAL_LOCAL_4 | Custom data, which is of the bytes type, can be changed, but cannot be synced.<br>**Since**: 12|
| ASSET_TAG_RETURN_TYPE | Type of asset information to return. The value is of the uint32 type.|
| ASSET_TAG_RETURN_LIMIT | Maximum number of assets that can be returned in a query operation. The value is of the uint32 type.|
| ASSET_TAG_RETURN_OFFSET | Offset of the returned assets in a batch query. The value is of the uint32 type.|
| ASSET_TAG_RETURN_ORDERED_BY | Sorting order of the assets in the query result. The value is of the uint32 type.|
| ASSET_TAG_CONFLICT_RESOLUTION | Policy for resolving the conflict when an asset is added. The value is of the uint32_t type.|
| ASSET_TAG_UPDATE_TIME | Asset update time, in timestamp format. The value is of the bytes type.<br>**Since**: 12|
| ASSET_TAG_OPERATION_TYPE | Additional operation type. The value is of the uint32_t type.<br>**Since**: 12|
| ASSET_TAG_REQUIRE_ATTR_ENCRYPTED | Whether to encrypt the additional information customized by the service. The value is of the Boolean type.<br>**Since**: 13|


### Asset_TagType

```
enum Asset_TagType
```

**Description**

Enumerates the tag types of asset attributes.

**Since**: 11

| Value| Description|
| -------- | -------- |
| ASSET_TYPE_BOOL | Boolean. |
| ASSET_TYPE_NUMBER | uint32_t. |
| ASSET_TYPE_BYTES | Bytes. |


### Asset_OperationType

```
enum Asset_OperationType
```

**Description**

Enumerates the additional asset operation types.

**Since**: 12

| Value| Description|
| -------- | -------- |
| ASSET_NEED_SYNC | Sync.|
| ASSET_NEED_LOGOUT | Log out.|
