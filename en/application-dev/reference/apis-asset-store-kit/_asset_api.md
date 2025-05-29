# AssetApi


## Overview

Provides functions for adding, removing, updating, and querying sensitive data less than 1024 bytes in size,
including passwords, app tokens, and other critical data (such as bank card numbers).

**System capability**: SystemCapability.Security.Asset

**Since**: 11


## Summary


### Files

| Name| Description|
| -------- | -------- |
| [asset_api.h](asset__api_8h.md) | Defines the functions for accessing assets. |


### Functions

| Name| Description|
| -------- | -------- |
| int32_t [OH_Asset_Add](#oh_asset_add) (const [Asset_Attr](_asset___attr.md) \*attributes, uint32_t attrCnt) | Adds an asset.|
| int32_t [OH_Asset_Remove](#oh_asset_remove) (const [Asset_Attr](_asset___attr.md) \*query, uint32_t queryCnt) | Removes one or more assets. |
| int32_t [OH_Asset_Update](#oh_asset_update) (const [Asset_Attr](_asset___attr.md) \*query, uint32_t queryCnt, const [Asset_Attr](_asset___attr.md) \*attributesToUpdate, uint32_t updateCnt) | Updates an asset. |
| int32_t [OH_Asset_PreQuery](#oh_asset_prequery) (const [Asset_Attr](_asset___attr.md) \*query, uint32_t queryCnt, [Asset_Blob](_asset___blob.md) \*challenge) | Performs preprocessing for the asset query. This function is used when user authentication is required for the access to the asset. |
| int32_t [OH_Asset_Query](#oh_asset_query) (const [Asset_Attr](_asset___attr.md) \*query, uint32_t queryCnt, [Asset_ResultSet](_asset___result_set.md) \*resultSet) | Queries one or more assets. |
| int32_t [OH_Asset_PostQuery](#oh_asset_postquery) (const [Asset_Attr](_asset___attr.md) \*handle, uint32_t handleCnt) | Performs postprocessing for the asset query. This function is used when user authentication is required for the access to the asset. |
| [Asset_Attr](_asset___attr.md) \* [OH_Asset_ParseAttr](#oh_asset_parseattr) (const [Asset_Result](_asset___result.md) \*result, [Asset_Tag](_asset_type.md#asset_tag) tag) | Parses the query result and obtains the specified attribute. |
| void [OH_Asset_FreeBlob](#oh_asset_freeblob) ([Asset_Blob](_asset___blob.md) \*blob) | Releases the memory occupied by the challenge value. |
| void [OH_Asset_FreeResultSet](#oh_asset_freeresultset) ([Asset_ResultSet](_asset___result_set.md) \*resultSet) | Releases the memory occupied by the query result. |


## Function Description


### OH_Asset_Add()

```
int32_t OH_Asset_Add (const Asset_Attr * attributes, uint32_t attrCnt )
```
**Description**
Adds an asset.

To set [ASSET_TAG_IS_PERSISTENT](_asset_type.md#asset_tag), the application must have the ohos.permission.STORE_PERSISTENT_DATA permission.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| attributes | Attributes of the asset to add |
| attrCnt | Number of attributes of the asset to add. |

**Returns**

Returns [ASSET_SUCCESS](_asset_type.md#asset_resultcode) if the operation is successful; returns an error code otherwise.

0 - The operation is successful.

201 - The caller does not have the required permission.

401 - The parameter is invalid.

24000001 - The asset store service is unavailable.

24000003 - The asset already exists.

24000005 - The lock screen status does not match.

24000006 - The system memory is insufficient.

24000007 - The asset is corrupted.

24000008 - The database operation failed.

24000009 - The cryptographic operation failed.

24000010 - The IPC failed.

24000011 - The Bundle Manager service is abnormal.

24000012 - The Account service is abnormal.

24000013 - The Access Token service is abnormal.

24000014 - The file operation failed.

24000015 - Failed to obtain the system time.

### OH_Asset_FreeBlob()

```
void OH_Asset_FreeBlob (Asset_Blob * blob)
```
**Description**
Releases the memory occupied by the challenge value.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| blob | Challenge value returned by **OH_Asset_PreQuery**. |


### OH_Asset_FreeResultSet()

```
void OH_Asset_FreeResultSet (Asset_ResultSet * resultSet)
```
**Description**
Releases the memory occupied by the query result.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| resultSet | Query result returned by **OH_Asset_Query**. |


### OH_Asset_ParseAttr()

```
Asset_Attr* OH_Asset_ParseAttr (const Asset_Result * result, Asset_Tag tag )
```
**Description**
Parses the query result and obtains the specified attribute.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| result | Query result returned by **OH_Asset_Query**. |
| tag | Key of the attribute to obtain. |

**Returns**

Returns <b>Asset_Attr</b> obtained if the operation is successful; returns <b>NULL</b> otherwise. The attribute does not need to be released by the service.


### OH_Asset_PostQuery()

```
int32_t OH_Asset_PostQuery (const Asset_Attr * handle, uint32_t handleCnt )
```
**Description**
Performs postprocessing for the asset query. This API is used when user authentication is required for the access to the asset.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| handle | Handle of the query operation, including the challenge value returned by **OH_Asset_PreQuery**. |
| handleCnt | Number of elements in the handle attribute set. |

**Returns**

Returns [ASSET_SUCCESS](_asset_type.md#asset_resultcode) if the operation is successful; returns an error code otherwise.

0 - The operation is successful.

401 - The parameter is invalid.

24000001 - The asset store service is unavailable.

24000006 - The system memory is insufficient.

24000010 - The IPC failed.

24000011 - The Bundle Manager service is abnormal.

24000012 - The Account service is abnormal.

24000013 - The Access Token service is abnormal.

### OH_Asset_PreQuery()

```
int32_t OH_Asset_PreQuery (const Asset_Attr * query, uint32_t queryCnt, Asset_Blob * challenge )
```
**Description**
Performs preprocessing for the asset query. This API is used when user authentication is required for the access to the asset.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| query | Attributes of the asset to query. |
| queryCnt | Number of attributes. |
| challenge | Challenge value, which is used when **OH_Asset_Query** is called. |

**Returns**

Returns [ASSET_SUCCESS](_asset_type.md#asset_resultcode) if the operation is successful; returns an error code otherwise.

0 - The operation is successful.

401 - The parameter is invalid.

24000001 - The asset store service is unavailable.

24000002 - The asset is not found.

24000005 - The lock screen status does not match.

24000006 - The system memory is insufficient.

24000007 - The asset is corrupted.

24000008 - The database operation failed.

24000009 - The cryptographic operation failed.

24000010 - The IPC failed.

24000011 - The Bundle Manager service is abnormal.

24000012 - The Account service is abnormal.

24000013 - The Access Token service is abnormal.

24000016 - The number of cached assets exceeds the limit.

24000017 - The function is not supported.

### OH_Asset_Query()

```
int32_t OH_Asset_Query (const Asset_Attr * query, uint32_t queryCnt, Asset_ResultSet * resultSet )
```
**Description**
Queries one or more assets.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| query | Attributes of the asset to query. |
| queryCnt | Number of attributes. |
| resultSet | Array of query results. |

**Returns**

Returns [ASSET_SUCCESS](_asset_type.md#asset_resultcode) if the operation is successful; returns an error code otherwise.

0 - The operation is successful.

401 - The parameter is invalid.

24000001 - The asset store service is unavailable.

24000002 - The asset is not found.

24000004 - The access to the asset is denied.

24000005 - The lock screen status does not match.

24000006 - The system memory is insufficient.

24000007 - The asset is corrupted.

24000008 - The database operation failed.

24000009 - The cryptographic operation failed.

24000010 - The IPC failed.

24000011 - The Bundle Manager service is abnormal.

24000012 - The Account service is abnormal.

24000013 - The Access Token service is abnormal.

24000017 - The function is not supported.

### OH_Asset_Remove()

```
int32_t OH_Asset_Remove (const Asset_Attr * query, uint32_t queryCnt )
```
**Description**
Removes one or more assets.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| query | Attributes of the asset to remove. |
| queryCnt | Number of Attributes. |

**Returns**

Returns [ASSET_SUCCESS](_asset_type.md#asset_resultcode) if the operation is successful; returns an error code otherwise.

0 - The operation is successful.

401 - The parameter is invalid.

24000001 - The asset store service is unavailable.

24000002 - The asset is not found.

24000006 - The system memory is insufficient.

24000007 - The asset is corrupted.

24000008 - The database operation failed.

24000010 - The IPC failed.

24000011 - The Bundle Manager service is abnormal.

24000012 - The Account service is abnormal.

24000013 - The Access Token service is abnormal.

24000015 - Failed to obtain the system time.

### OH_Asset_Update()

```
int32_t OH_Asset_Update (const Asset_Attr * query, uint32_t queryCnt, const Asset_Attr * attributesToUpdate, uint32_t updateCnt )
```
**Description**
Updates an asset.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| query | Attributes of the asset to update. |
| queryCnt | Number of attributes to update. |
| attributesToUpdate | New attributes of the asset. |
| updateCnt | Number of new attributes. |

**Returns**

Returns [ASSET_SUCCESS](_asset_type.md#asset_resultcode) if the operation is successful; returns an error code otherwise.

0 - The operation is successful.

401 - The parameter is invalid.

24000001 - The asset store service is unavailable.

24000002 - The asset is not found.

24000005 - The lock screen status does not match.

24000006 - The system memory is insufficient.

24000007 - The asset is corrupted.

24000008 - The database operation failed.

24000009 - The cryptographic operation failed.

24000010 - The IPC failed.

24000011 - The Bundle Manager service is abnormal.

24000012 - The Account service is abnormal.

24000013 - The Access Token service is abnormal.

24000015 - Failed to obtain the system time.
