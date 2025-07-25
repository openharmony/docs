# Data


## Overview

Data (distributed data manager) supports persistence of various structured data on a single device, and data sync and sharing between a device and the cloud. It defines a series of data types for operations, such as data addition, deletion, modification, and query.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Since**: 11


## Summary


### Files

| Name| Description|
| -------- | -------- |
| [data_asset.h](data__asset_8h.md) | Defines data asset structures.<br>File to include: <database/data/data_asset.h><br>Library: libnative_rdb_ndk.z.so<br>|


### Types

| Name| Description|
| -------- | -------- |
| [Data_AssetStatus](#data_assetstatus) | Defines an enum for data asset statuses.|
| [Data_Asset](#data_asset) | Defines a struct for a data asset.|


### Enums

| Name| Description|
| -------- | -------- |
| [Data_AssetStatus](#data_assetstatus) {<br>ASSET_NULL = 0, ASSET_NORMAL, ASSET_INSERT, ASSET_UPDATE,<br>ASSET_DELETE, ASSET_ABNORMAL, ASSET_DOWNLOADING<br>} | Enumerates the data asset statuses.|


### Functions

| Name| Description|
| -------- | -------- |
| [OH_Data_Asset_SetName](#oh_data_asset_setname) ([Data_Asset](#data_asset) \*asset, const char \*name) | Sets the name of a data asset.|
| [OH_Data_Asset_SetUri](#oh_data_asset_seturi) ([Data_Asset](#data_asset) \*asset, const char \*uri) | Sets the absolute path (URI) of a data asset in the system.|
| [OH_Data_Asset_SetPath](#oh_data_asset_setpath) ([Data_Asset](#data_asset) \*asset, const char \*path) | Sets the relative path of a data asset in the application sandbox directory.|
| [OH_Data_Asset_SetCreateTime](#oh_data_asset_setcreatetime) ([Data_Asset](#data_asset) \*asset, int64_t createTime) | Sets the creation time for a data asset.|
| [OH_Data_Asset_SetModifyTime](#oh_data_asset_setmodifytime) ([Data_Asset](#data_asset) \*asset, int64_t modifyTime) | Sets the last modification time for a data asset.|
| [OH_Data_Asset_SetSize](#oh_data_asset_setsize) ([Data_Asset](#data_asset) \*asset, size_t size) | Sets the size of a data asset.|
| [OH_Data_Asset_SetStatus](#oh_data_asset_setstatus) ([Data_Asset](#data_asset) \*asset, [Data_AssetStatus](#data_assetstatus) status) | Sets the status of a data asset.|
| [OH_Data_Asset_GetName](#oh_data_asset_getname) ([Data_Asset](#data_asset) \*asset, char \*name, size_t \*length) | Obtains the name of a data asset.|
| [OH_Data_Asset_GetUri](#oh_data_asset_geturi) ([Data_Asset](#data_asset) \*asset, char \*uri, size_t \*length) | Obtains the absolute path of a data asset.|
| [OH_Data_Asset_GetPath](#oh_data_asset_getpath) ([Data_Asset](#data_asset) \*asset, char \*path, size_t \*length) | Obtains the relative path of a data asset.|
| [OH_Data_Asset_GetCreateTime](#oh_data_asset_getcreatetime) ([Data_Asset](#data_asset) \*asset, int64_t \*createTime) | Obtains the creation time of a data asset.|
| [OH_Data_Asset_GetModifyTime](#oh_data_asset_getmodifytime) ([Data_Asset](#data_asset) \*asset, int64_t \*modifyTime) | Obtains the last modification time of a data asset.|
| [OH_Data_Asset_GetSize](#oh_data_asset_getsize) ([Data_Asset](#data_asset) \*asset, size_t \*size) | Obtains the space occupied by a data asset.|
| [OH_Data_Asset_GetStatus](#oh_data_asset_getstatus) ([Data_Asset](#data_asset) \*asset, [Data_AssetStatus](#data_assetstatus) \*status) | Obtains the status of a data asset.|
| [OH_Data_Asset_CreateOne](#oh_data_asset_createone) () | Creates a [Data_Asset](#data_asset) instance.|
| [OH_Data_Asset_DestroyOne](#oh_data_asset_destroyone) ([Data_Asset](#data_asset) \*asset) | Destroys a [Data_Asset](#data_asset) instance.|
| [OH_Data_Asset_CreateMultiple](#oh_data_asset_createmultiple) (uint32_t count) | Creates multiple [Data_Asset](#data_asset) instances.|
| [OH_Data_Asset_DestroyMultiple](#oh_data_asset_destroymultiple) ([Data_Asset](#data_asset) \*\*assets, uint32_t count) | Destroys multiple [Data_Asset](#data_asset) instances.|


## Type Description


### Data_Asset

```
typedef struct Data_Asset Data_Asset
```

**Description**

Defines a struct for a data asset.

It provides information about a data asset.

**Since**: 11


## Enum Description


### Data_AssetStatus

```
enum Data_AssetStatus
```

**Description**

Enumerates the data asset statuses.

| Value| Description|
| -------- | -------- |
| ASSET_NULL | The data asset is null.|
| ASSET_NORMAL | The data asset is in normal status.|
| ASSET_INSERT | The data asset is to be inserted to the cloud.|
| ASSET_UPDATE | The data asset is to be updated to the cloud.|
| ASSET_DELETE | The data asset is to be deleted from the cloud.|
| ASSET_ABNORMAL | The data asset is in abnormal status.|
| ASSET_DOWNLOADING | The data asset is being downloaded to a local device.|


## Function Description


### OH_Data_Asset_CreateMultiple()

```
Data_Asset** OH_Data_Asset_CreateMultiple (uint32_t count)
```

**Description**

Creates multiple [Data_Asset](#data_asset) instances.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| count | Number of data assets to create.|

**Returns**

Returns the pointer to the [Data_Asset](#data_asset) instance created if the operation is successful; returns null otherwise.

**See**

[Data_Asset](#data_asset).


### OH_Data_Asset_CreateOne()

```
Data_Asset* OH_Data_Asset_CreateOne ()
```

**Description**

Creates a [Data_Asset](#data_asset) instance.

**Since**: 11

**Returns**

Returns the pointer to the [Data_Asset](#data_asset) instance created if the operation is successful; returns null otherwise.

**See**

[Data_Asset](#data_asset).


### OH_Data_Asset_DestroyMultiple()

```
int OH_Data_Asset_DestroyMultiple (Data_Asset ** assets, uint32_t count )
```

**Description**

Destroys multiple [Data_Asset](#data_asset) instances.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| assets | Pointer to the [Data_Asset](#data_asset) instances to destroy.|
| count | Number of the [Data_Asset](#data_asset) instances to destroy.|

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise. For details about the error codes, see [OH_Rdb_ErrCode](_r_d_b.md#oh_rdb_errcode-1).

**See**

[Data_Asset](#data_asset), [OH_Rdb_ErrCode](_r_d_b.md#oh_rdb_errcode-1).


### OH_Data_Asset_DestroyOne()

```
int OH_Data_Asset_DestroyOne (Data_Asset * asset)
```

**Description**

Destroys a [Data_Asset](#data_asset) instance.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| asset | Pointer to the [Data_Asset](#data_asset) instance to destroy.|

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise. For details about the error codes, see [OH_Rdb_ErrCode](_r_d_b.md#oh_rdb_errcode-1).

**See**

[Data_Asset](#data_asset), [OH_Rdb_ErrCode](_r_d_b.md#oh_rdb_errcode-1).


### OH_Data_Asset_GetCreateTime()

```
int OH_Data_Asset_GetCreateTime (Data_Asset * asset, int64_t * createTime )
```

**Description**

Obtains the creation time of a data asset.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| asset | Pointer to the target [Data_Asset](#data_asset) instance.|
| createTime | Ponter to the creation time obtained, in int64_t format.|

**Returns**

Returns an error code. For details about the error codes, see [OH_Rdb_ErrCode](_r_d_b.md#oh_rdb_errcode-1).

**See**

[Data_Asset](#data_asset)


### OH_Data_Asset_GetModifyTime()

```
int OH_Data_Asset_GetModifyTime (Data_Asset * asset, int64_t * modifyTime )
```

**Description**

Obtains the last modification time of a data asset.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| asset | Pointer to the target [Data_Asset](#data_asset) instance.|
| modifyTime | Pointer to the last modification time obtained, in int64_t format.|

**Returns**

Returns an error code. For details about the error codes, see [OH_Rdb_ErrCode](_r_d_b.md#oh_rdb_errcode-1).

**See**

[Data_Asset](#data_asset)


### OH_Data_Asset_GetName()

```
int OH_Data_Asset_GetName (Data_Asset * asset, char * name, size_t * length )
```

**Description**

Obtains the name of a data asset.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| asset | Pointer to the target [Data_Asset](#data_asset) instance.|
| name | Pointer to the data asset name obtained, in the form of a string.|
| length | Pointer to the length of the name.|

**Returns**

Returns an error code. For details about the error codes, see [OH_Rdb_ErrCode](_r_d_b.md#oh_rdb_errcode-1).

**See**

[Data_Asset](#data_asset)


### OH_Data_Asset_GetPath()

```
int OH_Data_Asset_GetPath (Data_Asset * asset, char * path, size_t * length )
```

**Description**

Obtains the relative path of a data asset.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| asset | Pointer to the target [Data_Asset](#data_asset) instance.|
| path | Pointer to the relative path of the data asset obtained, in the form of a string.|
| length | Pointer to the length of the relative path.|

**Returns**

Returns an error code. For details about the error codes, see [OH_Rdb_ErrCode](_r_d_b.md#oh_rdb_errcode-1).

**See**

[Data_Asset](#data_asset)


### OH_Data_Asset_GetSize()

```
int OH_Data_Asset_GetSize (Data_Asset * asset, size_t * size )
```

**Description**

Obtains the space occupied by a data asset.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| asset | Pointer to the target [Data_Asset](#data_asset) instance.|
| size | Pointer to the data asset size obtained, in the format of size_t.|

**Returns**

Returns an error code. For details about the error codes, see [OH_Rdb_ErrCode](_r_d_b.md#oh_rdb_errcode-1).

**See**

[Data_Asset](#data_asset)


### OH_Data_Asset_GetStatus()

```
int OH_Data_Asset_GetStatus (Data_Asset * asset, Data_AssetStatus * status )
```

**Description**

Obtains the status of a data asset.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| asset | Pointer to the target [Data_Asset](#data_asset) instance.|
| status | Pointer to the [Data_AssetStatus](#data_assetstatus) obtained.|

**Returns**

Returns an error code. For details about the error codes, see [OH_Rdb_ErrCode](_r_d_b.md#oh_rdb_errcode-1).

**See**

[Data_Asset](#data_asset)


### OH_Data_Asset_GetUri()

```
int OH_Data_Asset_GetUri (Data_Asset * asset, char * uri, size_t * length )
```

**Description**

Obtains the absolute path (URI) of a data asset.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| asset | Pointer to the target [Data_Asset](#data_asset) instance.|
| uri | Pointer to the absolute path of the data asset obtained, in the form of a string.|
| length | Pointer to the length of the URI.|

**Returns**

Returns an error code. For details about the error codes, see [OH_Rdb_ErrCode](_r_d_b.md#oh_rdb_errcode-1).

**See**

[Data_Asset](#data_asset)


### OH_Data_Asset_SetCreateTime()

```
int OH_Data_Asset_SetCreateTime (Data_Asset * asset, int64_t createTime )
```

**Description**

Sets the creation time for a data asset.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| asset | Pointer to the target [Data_Asset](#data_asset) instance.|
| createTime | Creation time to set.|

**Returns**

Returns an error code. For details about the error codes, see [OH_Rdb_ErrCode](_r_d_b.md#oh_rdb_errcode-1).

**See**

[Data_Asset](#data_asset)


### OH_Data_Asset_SetModifyTime()

```
int OH_Data_Asset_SetModifyTime (Data_Asset * asset, int64_t modifyTime )
```

**Description**

Sets the last modification time for a data asset.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| asset | Pointer to the target [Data_Asset](#data_asset) instance.|
| modifyTime | Last modification time to set.|

**Returns**

Returns an error code. For details about the error codes, see [OH_Rdb_ErrCode](_r_d_b.md#oh_rdb_errcode-1).

**See**

[Data_Asset](#data_asset)


### OH_Data_Asset_SetName()

```
int OH_Data_Asset_SetName (Data_Asset * asset, const char * name )
```

**Description**

Sets the name of a data asset.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| asset | Pointer to the target [Data_Asset](#data_asset) instance.|
| name | Pointer to the name to set.|

**Returns**

Returns an error code. For details about the error codes, see [OH_Rdb_ErrCode](_r_d_b.md#oh_rdb_errcode-1).

**See**

[Data_Asset](#data_asset)


### OH_Data_Asset_SetPath()

```
int OH_Data_Asset_SetPath (Data_Asset * asset, const char * path )
```

**Description**

Sets the relative path of a data asset in the application sandbox directory.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| asset | Pointer to the target [Data_Asset](#data_asset) instance.|
| path | Pointer to the relative path to set.|

**Returns**

Returns an error code. For details about the error codes, see [OH_Rdb_ErrCode](_r_d_b.md#oh_rdb_errcode-1).

**See**

[Data_Asset](#data_asset)


### OH_Data_Asset_SetSize()

```
int OH_Data_Asset_SetSize (Data_Asset * asset, size_t size )
```

**Description**

Sets the size of a data asset.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| asset | Pointer to the target [Data_Asset](#data_asset) instance.|
| size | Size of the data asset to set.|

**Returns**

Returns an error code. For details about the error codes, see [OH_Rdb_ErrCode](_r_d_b.md#oh_rdb_errcode-1).

**See**

[Data_Asset](#data_asset)


### OH_Data_Asset_SetStatus()

```
int OH_Data_Asset_SetStatus (Data_Asset * asset, Data_AssetStatus status )
```

**Description**

Sets the status of a data asset.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| asset | Pointer to the target [Data_Asset](#data_asset) instance.|
| status | Status to set. For details, see [Data_AssetStatus](#data_assetstatus).|

**Returns**

Returns an error code. For details about the error codes, see [OH_Rdb_ErrCode](_r_d_b.md#oh_rdb_errcode-1).

**See**

[Data_Asset](#data_asset), [Data_AssetStatus](#data_assetstatus)


### OH_Data_Asset_SetUri()

```
int OH_Data_Asset_SetUri (Data_Asset * asset, const char * uri )
```

**Description**

Sets the absolute path (URI) of a data asset in the system.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| asset | Pointer to the target [Data_Asset](#data_asset) instance.|
| name | Pointer to the URI to set.|

**Returns**

Returns an error code. For details about the error codes, see [OH_Rdb_ErrCode](_r_d_b.md#oh_rdb_errcode-1).

**See**

[Data_Asset](#data_asset)
