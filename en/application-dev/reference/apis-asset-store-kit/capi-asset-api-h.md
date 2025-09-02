# asset_api.h

## Overview

Defines the functions for accessing assets.

**File to include**: <asset/asset_api.h>

**Library**: libasset_ndk.z.so

**System capability**: SystemCapability.Security.Asset

**Since**: 11

**Related module**: [AssetApi](capi-assetapi.md)

## Summary

### Functions

| Name| Description|
| -- | -- |
| [int32_t OH_Asset_Add(const Asset_Attr *attributes, uint32_t attrCnt)](#oh_asset_add) | Adds an asset.<br>To set the [Asset_Tag](capi-asset-type-h.md#asset_tag).**ASSET_TAG_IS_PERSISTENT** attribute, request the **ohos.permission.STORE_PERSISTENT_DATA** permission.|
| [int32_t OH_Asset_Remove(const Asset_Attr *query, uint32_t queryCnt)](#oh_asset_remove) | Removes one or more assets.|
| [int32_t OH_Asset_Update(const Asset_Attr *query, uint32_t queryCnt,const Asset_Attr *attributesToUpdate, uint32_t updateCnt)](#oh_asset_update) | Updates an asset.|
| [int32_t OH_Asset_PreQuery(const Asset_Attr *query, uint32_t queryCnt, Asset_Blob *challenge)](#oh_asset_prequery) | Performs preprocessing for the asset query. This function is used when user authentication is required for the access to the asset.|
| [int32_t OH_Asset_Query(const Asset_Attr *query, uint32_t queryCnt, Asset_ResultSet *resultSet)](#oh_asset_query) | Queries one or more assets.|
| [int32_t OH_Asset_PostQuery(const Asset_Attr *handle, uint32_t handleCnt)](#oh_asset_postquery) | Performs postprocessing for the asset query. This function is used when user authentication is required for the access to the asset.|
| [int32_t OH_Asset_QuerySyncResult(const Asset_Attr *query, uint32_t queryCnt, Asset_SyncResult *syncResult)](#oh_asset_querysyncresult) | Queries the sync result of an asset.|
| [Asset_Attr *OH_Asset_ParseAttr(const Asset_Result *result, Asset_Tag tag)](#oh_asset_parseattr) | Parses the query result and obtains the specified attribute.|
| [void OH_Asset_FreeBlob(Asset_Blob *blob)](#oh_asset_freeblob) | Releases the memory occupied by the challenge value.|
| [void OH_Asset_FreeResultSet(Asset_ResultSet *resultSet)](#oh_asset_freeresultset) | Releases the memory occupied by the query result.|

## Function Description

### OH_Asset_Add()

```
int32_t OH_Asset_Add(const Asset_Attr *attributes, uint32_t attrCnt)
```

**Description**

Adds an asset.

To set the [Asset_Tag](capi-asset-type-h.md#asset_tag).**ASSET_TAG_IS_PERSISTENT** attribute, request the **ohos.permission.STORE_PERSISTENT_DATA** permission.

**Since**: 11


**Parameters**

| Parameter| Description|
| -- | -- |
| const [Asset_Attr](capi-assettype-asset-attr.md) *attributes | Attributes of the asset to add.|
| uint32_t attrCnt | Number of attributes of the asset to add.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | [Asset_ResultCode](capi-asset-type-h.md#asset_resultcode):<br>     ASSET_SUCCESS = 0: Operation succeeded.<br>     ASSET_PERMISSION_DENIED = 201: The caller is not a system application.<br>     ASSET_INVALID_ARGUMENT = 401: invalid parameter. Possible causes:<br>         1. Mandatory parameters are left unspecified.<br>         2. The parameter type is incorrect.<br>         3. Parameter verification failed.<br>     ASSET_SERVICE_UNAVAILABLE = 24000001: The asset service is unavailable.<br>     ASSET_DUPLICATED = 24000003: The asset already exists.<br>     ASSET_STATUS_MISMATCH = 24000005: The screen lock status is incorrect.<br>     ASSET_OUT_OF_MEMORY = 24000006: The system memory is insufficient.<br>     ASSET_DATA_CORRUPTED = 24000007: The asset is corrupted.<br>     ASSET_DATABASE_ERROR = 24000008: The database operation failed.<br>     ASSET_CRYPTO_ERROR = 24000009: The cryptographic operation failed.<br>     ASSET_IPC_ERROR = 24000010: The IPC failed.<br>     ASSET_BMS_ERROR = 24000011: The bundle manager service is abnormal.<br>     ASSET_ACCOUNT_ERROR = 24000012: The account service is abnormal.<br>     ASSET_ACCESS_TOKEN_ERROR = 24000013: The access token service is abnormal.<br>     ASSET_FILE_OPERATION_ERROR = 24000014: The file operation failed.<br>     ASSET_GET_SYSTEM_TIME_ERROR = 24000015: Failed to obtain the system time.|

### OH_Asset_Remove()

```
int32_t OH_Asset_Remove(const Asset_Attr *query, uint32_t queryCnt)
```

**Description**

Removes one or more assets.

**Since**: 11


**Parameters**

| Parameter| Description|
| -- | -- |
| const [Asset_Attr](capi-assettype-asset-attr.md) *query | Attributes of the asset to remove.|
| uint32_t queryCnt | Number of attributes.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | [Asset_ResultCode](capi-asset-type-h.md#asset_resultcode):<br>     ASSET_SUCCESS = 0: Operation succeeded.<br>     ASSET_INVALID_ARGUMENT = 401: invalid parameter. Possible causes:<br>         1. The parameter type is incorrect.<br>         2. Parameter verification failed.<br>     ASSET_SERVICE_UNAVAILABLE = 24000001: The asset service is unavailable.<br>     ASSET_NOT_FOUND = 24000002: The asset is not found.<br>     ASSET_OUT_OF_MEMORY = 24000006: The system memory is insufficient.<br>     ASSET_DATA_CORRUPTED = 24000007: The asset is corrupted.<br>     ASSET_DATABASE_ERROR = 24000008: The database operation failed.<br>     ASSET_IPC_ERROR = 24000010: The IPC failed.<br>     ASSET_BMS_ERROR = 24000011: The bundle manager service is abnormal.<br>     ASSET_ACCOUNT_ERROR = 24000012: The account service is abnormal.<br>     ASSET_ACCESS_TOKEN_ERROR = 24000013: The access token service is abnormal.<br>     ASSET_GET_SYSTEM_TIME_ERROR = 24000015: Failed to obtain the system time.|

### OH_Asset_Update()

```
int32_t OH_Asset_Update(const Asset_Attr *query, uint32_t queryCnt,const Asset_Attr *attributesToUpdate, uint32_t updateCnt)
```

**Description**

Updates an asset.

**Since**: 11


**Parameters**

| Parameter| Description|
| -- | -- |
| const [Asset_Attr](capi-assettype-asset-attr.md) *query | Attributes of the asset to update.|
| uint32_t queryCnt | Number of attributes to update.|
| const [Asset_Attr](capi-assettype-asset-attr.md) *attributesToUpdate | New attributes of the asset.|
| uint32_t updateCnt | Number of new attributes.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | [Asset_ResultCode](capi-asset-type-h.md#asset_resultcode):<br>     ASSET_SUCCESS = 0: Operation succeeded.<br>     ASSET_INVALID_ARGUMENT = 401: invalid parameter. Possible causes:<br>         1. Mandatory parameters are left unspecified.<br>         2. The parameter type is incorrect.<br>         3. Parameter verification failed.<br>     ASSET_SERVICE_UNAVAILABLE = 24000001: The asset service is unavailable.<br>     ASSET_NOT_FOUND = 24000002: The asset is not found.<br>     ASSET_STATUS_MISMATCH = 24000005: The screen lock status is incorrect.<br>     ASSET_OUT_OF_MEMORY = 24000006: The system memory is insufficient.<br>     ASSET_DATA_CORRUPTED = 24000007: The asset is corrupted.<br>     ASSET_DATABASE_ERROR = 24000008: The database operation failed.<br>     ASSET_CRYPTO_ERROR = 24000009: The cryptographic operation failed.<br>     ASSET_IPC_ERROR = 24000010: The IPC failed.<br>     ASSET_BMS_ERROR = 24000011: The bundle manager service is abnormal.<br>     ASSET_ACCOUNT_ERROR = 24000012: The account service is abnormal.<br>     ASSET_ACCESS_TOKEN_ERROR = 24000013: The access token service is abnormal.<br>     ASSET_GET_SYSTEM_TIME_ERROR = 24000015: Failed to obtain the system time.|

### OH_Asset_PreQuery()

```
int32_t OH_Asset_PreQuery(const Asset_Attr *query, uint32_t queryCnt, Asset_Blob *challenge)
```

**Description**

Performs preprocessing for the asset query. This API is used when user authentication is required for the access to the asset.

**Since**: 11


**Parameters**

| Parameter| Description|
| -- | -- |
| const [Asset_Attr](capi-assettype-asset-attr.md) *query | Attributes of the asset to query.|
| uint32_t queryCnt | Number of attributes.|
| [Asset_Blob](capi-assettype-asset-blob.md) *challenge | Challenge value, which is used when **OH_Asset_Query** is called.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | [Asset_ResultCode](capi-asset-type-h.md#asset_resultcode):<br>     ASSET_SUCCESS = 0: Operation succeeded.<br>     ASSET_INVALID_ARGUMENT = 401: invalid parameter. Possible causes:<br>         1. The parameter type is incorrect.<br>         2. Parameter verification failed.<br>     ASSET_SERVICE_UNAVAILABLE = 24000001: The asset service is unavailable.<br>     ASSET_NOT_FOUND = 24000002: The asset is not found.<br>     ASSET_STATUS_MISMATCH = 24000005: The screen lock status is incorrect.<br>     ASSET_OUT_OF_MEMORY = 24000006: The system memory is insufficient.<br>     ASSET_DATA_CORRUPTED = 24000007: The asset is corrupted.<br>     ASSET_DATABASE_ERROR = 24000008: The database operation failed.<br>     ASSET_CRYPTO_ERROR = 24000009: The cryptographic operation failed.<br>     ASSET_IPC_ERROR = 24000010: The IPC failed.<br>     ASSET_BMS_ERROR = 24000011: The bundle manager service is abnormal.<br>     ASSET_ACCOUNT_ERROR = 24000012: The account service is abnormal.<br>     ASSET_ACCESS_TOKEN_ERROR = 24000013: The access token service is abnormal.<br>     ASSET_LIMIT_EXCEEDED = 24000016: The number of cached assets reaches the limit.<br>     ASSET_UNSUPPORTED = 24000017: This function is not supported.|

### OH_Asset_Query()

```
int32_t OH_Asset_Query(const Asset_Attr *query, uint32_t queryCnt, Asset_ResultSet *resultSet)
```

**Description**

Queries one or more assets.

**Since**: 11


**Parameters**

| Parameter| Description|
| -- | -- |
| const [Asset_Attr](capi-assettype-asset-attr.md) *query | Attributes of the asset to query.|
| uint32_t queryCnt | Number of attributes.|
| [Asset_ResultSet](capi-assettype-asset-resultset.md) *resultSet | Array of query results.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | [Asset_ResultCode](capi-asset-type-h.md#asset_resultcode):<br>     ASSET_SUCCESS = 0: Operation succeeded.<br>     ASSET_INVALID_ARGUMENT = 401: invalid parameter. Possible causes:<br>         1. The parameter type is incorrect.<br>         2. Parameter verification failed.<br>     ASSET_SERVICE_UNAVAILABLE = 24000001: The asset service is unavailable.<br>     ASSET_NOT_FOUND = 24000002: The asset is not found.<br>     ASSET_ACCESS_DENIED = 24000004: Access to the asset is denied.<br>     ASSET_STATUS_MISMATCH = 24000005: The screen lock status is incorrect.<br>     ASSET_OUT_OF_MEMORY = 24000006: The system memory is insufficient.<br>     ASSET_DATA_CORRUPTED = 24000007: The asset is corrupted.<br>     ASSET_DATABASE_ERROR = 24000008: The database operation failed.<br>     ASSET_CRYPTO_ERROR = 24000009: The cryptographic operation failed.<br>     ASSET_IPC_ERROR = 24000010: The IPC failed.<br>     ASSET_BMS_ERROR = 24000011: The bundle manager service is abnormal.<br>     ASSET_ACCOUNT_ERROR = 24000012: The account service is abnormal.<br>     ASSET_ACCESS_TOKEN_ERROR = 24000013: The access token service is abnormal.<br>     ASSET_UNSUPPORTED = 24000017: This function is not supported.|

### OH_Asset_PostQuery()

```
int32_t OH_Asset_PostQuery(const Asset_Attr *handle, uint32_t handleCnt)
```

**Description**

Performs postprocessing for the asset query. This API is used when user authentication is required for the access to the asset.

**Since**: 11


**Parameters**

| Parameter| Description|
| -- | -- |
| const [Asset_Attr](capi-assettype-asset-attr.md) *handle | Handle of the query operation, including the challenge value returned by **OH_Asset_PreQuery**.|
| uint32_t handleCnt | Number of elements in the handle attribute set.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | [Asset_ResultCode](capi-asset-type-h.md#asset_resultcode):<br>     ASSET_SUCCESS = 0: Operation succeeded.<br>     ASSET_INVALID_ARGUMENT = 401: invalid parameter. Possible causes:<br>         1. Mandatory parameters are left unspecified.<br>         2. The parameter type is incorrect.<br>         3. Parameter verification failed.<br>     ASSET_SERVICE_UNAVAILABLE = 24000001: The asset service is unavailable.<br>     ASSET_OUT_OF_MEMORY = 24000006: The system memory is insufficient.<br>     ASSET_IPC_ERROR = 24000010: The IPC failed.<br>     ASSET_BMS_ERROR = 24000011: The bundle manager service is abnormal.<br>     ASSET_ACCOUNT_ERROR = 24000012: The account service is abnormal.<br>     ASSET_ACCESS_TOKEN_ERROR = 24000013: The access token service is abnormal.|

### OH_Asset_QuerySyncResult()

```
int32_t OH_Asset_QuerySyncResult(const Asset_Attr *query, uint32_t queryCnt, Asset_SyncResult *syncResult)
```

**Description**

Queries the sync result of an asset.

**Since**: 20


**Parameters**

| Parameter| Description|
| -- | -- |
| const [Asset_Attr](capi-assettype-asset-attr.md) *query | Attributes of the asset to query the sync result.|
| uint32_t queryCnt | Number of attributes.|
| [Asset_SyncResult](capi-assettype-asset-syncresult.md) *syncResult | Sync result of the queried asset.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | [Asset_ResultCode](capi-asset-type-h.md#asset_resultcode):<br>     ASSET_SUCCESS = 0: Operation succeeded.<br>     ASSET_SERVICE_UNAVAILABLE = 24000001: The asset service is unavailable.<br>     ASSET_OUT_OF_MEMORY = 24000006: The system memory is insufficient.<br>     ASSET_IPC_ERROR = 24000010: The IPC failed.<br>     ASSET_BMS_ERROR = 24000011: The bundle manager service is abnormal.<br>     ASSET_ACCOUNT_ERROR = 24000012: The account service is abnormal.<br>     ASSET_ACCESS_TOKEN_ERROR = 24000013: The access token service is abnormal.<br>     ASSET_FILE_OPERATION_ERROR = 24000014: The file operation failed.<br>     ASSET_PARAM_VERIFICATION_FAILED = 24000018: Parameter verification failed.|

### OH_Asset_ParseAttr()

```
Asset_Attr *OH_Asset_ParseAttr(const Asset_Result *result, Asset_Tag tag)
```

**Description**

Parses the query result and obtains the specified attribute.

**Since**: 11


**Parameters**

| Parameter| Description|
| -- | -- |
| const [Asset_Result](capi-assettype-asset-result.md) *result | Query result returned by **OH_Asset_Query**.|
| [Asset_Tag](capi-asset-type-h.md#asset_tag) tag | Key of the attribute to obtain.|

**Return value**

| Type| Description|
| -- | -- |
| [Asset_Attr](capi-assettype-asset-attr.md) | Returns **Asset_Attr** obtained if the operation is successful; returns **NULL** otherwise. The attribute does not need to be released by the service.|

### OH_Asset_FreeBlob()

```
void OH_Asset_FreeBlob(Asset_Blob *blob)
```

**Description**

Releases the memory occupied by the challenge value.

**Since**: 11


**Parameters**

| Parameter| Description|
| -- | -- |
| [Asset_Blob](capi-assettype-asset-blob.md) *blob | Challenge value returned by **OH_Asset_PreQuery**.|

### OH_Asset_FreeResultSet()

```
void OH_Asset_FreeResultSet(Asset_ResultSet *resultSet)
```

**Description**

Releases the memory occupied by the query result.

**Since**: 11


**Parameters**

| Parameter| Description|
| -- | -- |
| [Asset_ResultSet](capi-assettype-asset-resultset.md) *resultSet | Query result returned by **OH_Asset_Query**.|
