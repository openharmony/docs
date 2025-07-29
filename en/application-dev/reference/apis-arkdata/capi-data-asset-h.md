# data_asset.h

## Overview

Defines data asset structs.<br>Asset is a data struct used in data management. You can use it to set and obtain file attributes, including the name, absolute path, relative path, creation time, modification time, status, and size of a file.

**File to include**: <database/rdb/data_asset.h>

**Library**: libnative_rdb_ndk.z.so

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Since**: 11

**Related module**: [RDB](capi-rdb.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [Data_Asset](capi-rdb-data-asset.md) | Data_Asset | Defines a struct for a data asset, which provides information about a data asset. |

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [Data_AssetStatus](#data_assetstatus) | Data_AssetStatus | Enumerates the data asset statuses.|

### Functions

| Name| Description|
| -- | -- |
| [int OH_Data_Asset_SetName(Data_Asset *asset, const char *name)](#oh_data_asset_setname) | Sets the name of an asset.|
| [int OH_Data_Asset_SetUri(Data_Asset *asset, const char *uri)](#oh_data_asset_seturi) | Sets the absolute path (URI) of an asset in the system.|
| [int OH_Data_Asset_SetPath(Data_Asset *asset, const char *path)](#oh_data_asset_setpath) | Sets the relative path of an asset in the application sandbox directory.|
| [int OH_Data_Asset_SetCreateTime(Data_Asset *asset, int64_t createTime)](#oh_data_asset_setcreatetime) | Sets the creation time for an asset.|
| [int OH_Data_Asset_SetModifyTime(Data_Asset *asset, int64_t modifyTime)](#oh_data_asset_setmodifytime) | Sets the last modification time for an asset.|
| [int OH_Data_Asset_SetSize(Data_Asset *asset, size_t size)](#oh_data_asset_setsize) | Sets the size of an asset.|
| [int OH_Data_Asset_SetStatus(Data_Asset *asset, Data_AssetStatus status)](#oh_data_asset_setstatus) | Sets the status of an asset.|
| [int OH_Data_Asset_GetName(Data_Asset *asset, char *name, size_t *length)](#oh_data_asset_getname) | Obtains the name of a data asset.|
| [int OH_Data_Asset_GetUri(Data_Asset *asset, char *uri, size_t *length)](#oh_data_asset_geturi) | Obtains the absolute path of a data asset.|
| [int OH_Data_Asset_GetPath(Data_Asset *asset, char *path, size_t *length)](#oh_data_asset_getpath) | Obtains the relative path of an asset.|
| [int OH_Data_Asset_GetCreateTime(Data_Asset *asset, int64_t *createTime)](#oh_data_asset_getcreatetime) | Obtains the creation time of a data asset.|
| [int OH_Data_Asset_GetModifyTime(Data_Asset *asset, int64_t *modifyTime)](#oh_data_asset_getmodifytime) | Obtains the last modification time of an asset.|
| [int OH_Data_Asset_GetSize(Data_Asset *asset, size_t *size)](#oh_data_asset_getsize) | Obtains the space occupied by an asset.|
| [int OH_Data_Asset_GetStatus(Data_Asset *asset, Data_AssetStatus *status)](#oh_data_asset_getstatus) | Obtains the status of a data asset.|
| [Data_Asset *OH_Data_Asset_CreateOne(void)](#oh_data_asset_createone) | Creates a [Data_Asset](capi-rdb-data-asset.md) instance.|
| [int OH_Data_Asset_DestroyOne(Data_Asset *asset)](#oh_data_asset_destroyone) | Destroys an [Data_Asset](capi-rdb-data-asset.md) object and reclaims the memory occupied by the object.|
| [Data_Asset **OH_Data_Asset_CreateMultiple(uint32_t count)](#oh_data_asset_createmultiple) | Creates a specified number of [Data_Asset](capi-rdb-data-asset.md) instances.|
| [int OH_Data_Asset_DestroyMultiple(Data_Asset **assets, uint32_t count)](#oh_data_asset_destroymultiple) | Destroys multiple [Data_Asset](capi-rdb-data-asset.md) objects and reclaims the memory occupied by the objects.|

## Enum Description

### Data_AssetStatus

```
enum Data_AssetStatus
```

**Description**

Enumerates the data asset statuses.

**Since**: 11

| Enum Item| Description|
| -- | -- |
| ASSET_NULL = 0 | The data asset is null.|
| ASSET_NORMAL | The asset is in normal status.|
| ASSET_INSERT | The asset is to be inserted to the cloud.|
| ASSET_UPDATE | The asset is to be updated to the cloud.|
| ASSET_DELETE | The asset is to be deleted from the cloud.|
| ASSET_ABNORMAL | The asset is in abnormal status.|
| ASSET_DOWNLOADING | The asset is being downloaded to a local device.|


## Function Description

### OH_Data_Asset_SetName()

```
int OH_Data_Asset_SetName(Data_Asset *asset, const char *name)
```

**Description**

Sets the name of a data asset.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [Data_Asset](capi-rdb-data-asset.md) *asset | Pointer to the [Data_Asset](capi-rdb-data-asset.md) instance.|
| const char *name | Pointer to the name to set.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns an error code. For details, see [OH_Rdb_ErrCode](capi-relational-store-error-code-h.md#oh_rdb_errcode).<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Data_Asset_SetUri()

```
int OH_Data_Asset_SetUri(Data_Asset *asset, const char *uri)
```

**Description**

Sets the absolute path (URI) of an asset in the system.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [Data_Asset](capi-rdb-data-asset.md) *asset | Pointer to the [Data_Asset](capi-rdb-data-asset.md) instance.|
| uri |  Pointer to the URI to set.|

**Returns**

| Type| Description                                                                                                                                         |
| -- |---------------------------------------------------------------------------------------------------------------------------------------------|
| int | Returns an error code. For details, see [OH_Rdb_ErrCode](capi-relational-store-error-code-h.md#oh_rdb_errcode).<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Data_Asset_SetPath()

```
int OH_Data_Asset_SetPath(Data_Asset *asset, const char *path)
```

**Description**

Sets the relative path of an asset in the application sandbox directory.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [Data_Asset](capi-rdb-data-asset.md) *asset | Pointer to the [Data_Asset](capi-rdb-data-asset.md) instance.|
| const char *path | Pointer to the relative path to set.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns an error code. For details, see [OH_Rdb_ErrCode](capi-relational-store-error-code-h.md#oh_rdb_errcode).<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Data_Asset_SetCreateTime()

```
int OH_Data_Asset_SetCreateTime(Data_Asset *asset, int64_t createTime)
```

**Description**

Sets the creation time for an asset.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [Data_Asset](capi-rdb-data-asset.md) *asset | Pointer to the [Data_Asset](capi-rdb-data-asset.md) instance.|
| int64_t createTime | Creation time to set.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns an error code. For details, see [OH_Rdb_ErrCode](capi-relational-store-error-code-h.md#oh_rdb_errcode).<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Data_Asset_SetModifyTime()

```
int OH_Data_Asset_SetModifyTime(Data_Asset *asset, int64_t modifyTime)
```

**Description**

Sets the last modification time for a data asset.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [Data_Asset](capi-rdb-data-asset.md) *asset | Pointer to the [Data_Asset](capi-rdb-data-asset.md) instance.|
| int64_t modifyTime | Last modification time to set.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns an error code. For details, see [OH_Rdb_ErrCode](capi-relational-store-error-code-h.md#oh_rdb_errcode).<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Data_Asset_SetSize()

```
int OH_Data_Asset_SetSize(Data_Asset *asset, size_t size)
```

**Description**

Sets the size of an asset.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [Data_Asset](capi-rdb-data-asset.md) *asset | Pointer to the [Data_Asset](capi-rdb-data-asset.md) instance.|
| size_t size | Size of the data asset to set.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns an error code. For details, see [OH_Rdb_ErrCode](capi-relational-store-error-code-h.md#oh_rdb_errcode).<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Data_Asset_SetStatus()

```
int OH_Data_Asset_SetStatus(Data_Asset *asset, Data_AssetStatus status)
```

**Description**

Sets the status of an asset.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [Data_Asset](capi-rdb-data-asset.md) *asset | Pointer to the [Data_Asset](capi-rdb-data-asset.md) instance.|
| [Data_AssetStatus](#data_assetstatus) status | Status to set. For details, see [Data_AssetStatus](capi-data-asset-h.md#data_assetstatus).|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns an error code. For details, see [OH_Rdb_ErrCode](capi-relational-store-error-code-h.md#oh_rdb_errcode).<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Data_Asset_GetName()

```
int OH_Data_Asset_GetName(Data_Asset *asset, char *name, size_t *length)
```

**Description**

Obtains the name of a data asset.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [Data_Asset](capi-rdb-data-asset.md) *asset | Pointer to the [Data_Asset](capi-rdb-data-asset.md) instance.|
| char *name | Pointer to the data asset name obtained, in the form of a string.|
| size_t *length | Pointer to the length of the name.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns an error code. For details, see [OH_Rdb_ErrCode](capi-relational-store-error-code-h.md#oh_rdb_errcode).<br>**RDB_ERR** indicates that the execute function is abnormal.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Data_Asset_GetUri()

```
int OH_Data_Asset_GetUri(Data_Asset *asset, char *uri, size_t *length)
```

**Description**

Obtains the absolute path (URI) of a data asset.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [Data_Asset](capi-rdb-data-asset.md) *asset | Pointer to the [Data_Asset](capi-rdb-data-asset.md) instance.|
| char *uri | Pointer to the absolute path of the data asset obtained, in the form of a string.|
| size_t *length | Pointer to the length of the URI.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns an error code. For details, see [OH_Rdb_ErrCode](capi-relational-store-error-code-h.md#oh_rdb_errcode).<br>**RDB_ERR** indicates that the execute function is abnormal.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Data_Asset_GetPath()

```
int OH_Data_Asset_GetPath(Data_Asset *asset, char *path, size_t *length)
```

**Description**

Obtains the relative path of a data asset.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [Data_Asset](capi-rdb-data-asset.md) *asset | Pointer to the [Data_Asset](capi-rdb-data-asset.md) instance.|
| char *path | Pointer to the relative path of the data asset obtained, in the form of a string.|
| size_t *length | Pointer to the length of the relative path.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns an error code. For details, see [OH_Rdb_ErrCode](capi-relational-store-error-code-h.md#oh_rdb_errcode).<br>**RDB_ERR** indicates that the execute function is abnormal.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Data_Asset_GetCreateTime()

```
int OH_Data_Asset_GetCreateTime(Data_Asset *asset, int64_t *createTime)
```

**Description**

Obtains the creation time of a data asset.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [Data_Asset](capi-rdb-data-asset.md) *asset | Pointer to the [Data_Asset](capi-rdb-data-asset.md) instance.|
| int64_t *createTime | Ponter to the creation time obtained, in int64_t format.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns an error code. For details, see [OH_Rdb_ErrCode](capi-relational-store-error-code-h.md#oh_rdb_errcode).<br>**RDB_ERR** indicates that the execute function is abnormal.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

**See**

Data_Asset

### OH_Data_Asset_GetModifyTime()

```
int OH_Data_Asset_GetModifyTime(Data_Asset *asset, int64_t *modifyTime)
```

**Description**

Obtains the last modification time of an asset.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [Data_Asset](capi-rdb-data-asset.md) *asset | Pointer to the [Data_Asset](capi-rdb-data-asset.md) instance.|
| int64_t *modifyTime | Pointer to the last modification time obtained, in int64_t format.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns an error code. For details, see [OH_Rdb_ErrCode](capi-relational-store-error-code-h.md#oh_rdb_errcode).<br>**RDB_ERR** indicates that the execute function is abnormal.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Data_Asset_GetSize()

```
int OH_Data_Asset_GetSize(Data_Asset *asset, size_t *size)
```

**Description**

Obtains the space occupied by an asset.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [Data_Asset](capi-rdb-data-asset.md) *asset | Pointer to the [Data_Asset](capi-rdb-data-asset.md) instance.|
| size_t *size | Pointer to the data asset size obtained, in the format of size_t.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns an error code. For details, see [OH_Rdb_ErrCode](capi-relational-store-error-code-h.md#oh_rdb_errcode).<br>**RDB_ERR** indicates that the execute function is abnormal.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Data_Asset_GetStatus()

```
int OH_Data_Asset_GetStatus(Data_Asset *asset, Data_AssetStatus *status)
```

**Description**

Obtains the status of a data asset.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [Data_Asset](capi-rdb-data-asset.md) *asset | Pointer to the [Data_Asset](capi-rdb-data-asset.md) instance.|
| [Data_AssetStatus](#data_assetstatus) *status | Pointer to the [Data_AssetStatus](capi-data-asset-h.md#data_assetstatus) obtained.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns an error code. For details, see [OH_Rdb_ErrCode](capi-relational-store-error-code-h.md#oh_rdb_errcode).<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Data_Asset_CreateOne()

```
Data_Asset *OH_Data_Asset_CreateOne(void)
```

**Description**

Creates a [Data_Asset](capi-rdb-data-asset.md) instance.

**Since**: 11

**Returns**

| Type| Description|
| -- | -- |
| [Data_Asset](capi-rdb-data-asset.md) | Returns the pointer to the [Data_Asset](capi-rdb-data-asset.md) instance created if the operation is successful; returns null otherwise.|

### OH_Data_Asset_DestroyOne()

```
int OH_Data_Asset_DestroyOne(Data_Asset *asset)
```

**Description**

Destroys an [Data_Asset](capi-rdb-data-asset.md) object and reclaims the memory occupied by the object.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [Data_Asset](capi-rdb-data-asset.md) *asset | Pointer to the [Data_Asset](capi-rdb-data-asset.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns **RDB_OK** if the operation is successful; returns an error code otherwise. For details, see [OH_Rdb_ErrCode](capi-relational-store-error-code-h.md#oh_rdb_errcode).|

### OH_Data_Asset_CreateMultiple()

```
Data_Asset **OH_Data_Asset_CreateMultiple(uint32_t count)
```

**Description**

Creates a specified number of [Data_Asset](capi-rdb-data-asset.md) instances.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| uint32_t count | Number of data assets to create.|

**Returns**

| Type| Description|
| -- | -- |
| [Data_Asset](capi-rdb-data-asset.md) | Returns the pointer to the [Data_Asset](capi-rdb-data-asset.md) instance created if the operation is successful; returns null otherwise.|

### OH_Data_Asset_DestroyMultiple()

```
int OH_Data_Asset_DestroyMultiple(Data_Asset **assets, uint32_t count)
```

**Description**

Destroys multiple [Data_Asset](capi-rdb-data-asset.md) objects and reclaims the memory occupied by the objects.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [Data_Asset](capi-rdb-data-asset.md) **assets | Double pointer to the [Data_Asset](capi-rdb-data-asset.md) instance.|
| uint32_t count | Number of [Data_Asset](capi-rdb-data-asset.md) objects to be destroyed.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns **RDB_OK** if the operation is successful; returns an error code otherwise. For details, see [OH_Rdb_ErrCode](capi-relational-store-error-code-h.md#oh_rdb_errcode).|
