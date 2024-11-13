# data_asset.h


## Overview

Defines data asset structs.

Asset is a data struct used in data management. You can use it to set and obtain file properties, including the name, absolute path, relative path, creation time, modification time, status, and size of a file.

**File to include**: <database/data/data_asset.h>

**Library**: libnative_rdb_ndk.z.so

**Since**: 11

Related module: [Data](_data.md)


## Summary


### Types

| Name| Description|
| -------- | -------- |
| [Data_AssetStatus](_data.md#data_assetstatus) | Defines an enum for data asset statuses.|
| [Data_Asset](_data.md#data_asset) | Defines a struct for an asset.|


### Enums

| Name| Description|
| -------- | -------- |
| [Data_AssetStatus](_data.md#data_assetstatus) {<br>ASSET_NULL = 0, ASSET_NORMAL, ASSET_INSERT, ASSET_UPDATE,<br>ASSET_DELETE, ASSET_ABNORMAL, ASSET_DOWNLOADING<br>} | Enumerates data asset statuses.|


### Functions

| Name| Description|
| -------- | -------- |
| [OH_Data_Asset_SetName](_data.md#oh_data_asset_setname) ([Data_Asset](_data.md#data_asset) \*asset, const char \*name) | Sets the name of an asset.|
| [OH_Data_Asset_SetUri](_data.md#oh_data_asset_seturi) ([Data_Asset](_data.md#data_asset) \*asset, const char \*uri) | Sets the absolute path (URI) of an asset in the system.|
| [OH_Data_Asset_SetPath](_data.md#oh_data_asset_setpath) ([Data_Asset](_data.md#data_asset) \*asset, const char \*path) | Sets the relative path of an asset in the application sandbox directory.|
| [OH_Data_Asset_SetCreateTime](_data.md#oh_data_asset_setcreatetime) ([Data_Asset](_data.md#data_asset) \*asset, int64_t createTime) | Sets the creation time for an asset.|
| [OH_Data_Asset_SetModifyTime](_data.md#oh_data_asset_setmodifytime) ([Data_Asset](_data.md#data_asset) \*asset, int64_t modifyTime) | Sets the last modification time for an asset.|
| [OH_Data_Asset_SetSize](_data.md#oh_data_asset_setsize) ([Data_Asset](_data.md#data_asset) \*asset, size_t size) | Sets the size of an asset.|
| [OH_Data_Asset_SetStatus](_data.md#oh_data_asset_setstatus) ([Data_Asset](_data.md#data_asset) \*asset, [Data_AssetStatus](_data.md#data_assetstatus) status) | Sets the status of an asset.|
| [OH_Data_Asset_GetName](_data.md#oh_data_asset_getname) ([Data_Asset](_data.md#data_asset) \*asset, char \*name, size_t \*length) | Obtains the name of an asset.|
| [OH_Data_Asset_GetUri](_data.md#oh_data_asset_geturi) ([Data_Asset](_data.md#data_asset) \*asset, char \*uri, size_t \*length) | Obtains the absolute path of an asset.|
| [OH_Data_Asset_GetPath](_data.md#oh_data_asset_getpath) ([Data_Asset](_data.md#data_asset) \*asset, char \*path, size_t \*length) | Obtains the relative path of an asset.|
| [OH_Data_Asset_GetCreateTime](_data.md#oh_data_asset_getcreatetime) ([Data_Asset](_data.md#data_asset) \*asset, int64_t \*createTime) | Obtains the creation time of an asset.|
| [OH_Data_Asset_GetModifyTime](_data.md#oh_data_asset_getmodifytime) ([Data_Asset](_data.md#data_asset) \*asset, int64_t \*modifyTime) | Obtains the last modification time of an asset.|
| [OH_Data_Asset_GetSize](_data.md#oh_data_asset_getsize) ([Data_Asset](_data.md#data_asset) \*asset, size_t \*size) | Obtains the space occupied by an asset.|
| [OH_Data_Asset_GetStatus](_data.md#oh_data_asset_getstatus) ([Data_Asset](_data.md#data_asset) \*asset, [Data_AssetStatus](_data.md#data_assetstatus) \*status) | Obtains the status of an asset.|
| [OH_Data_Asset_CreateOne](_data.md#oh_data_asset_createone) () | Creates a [Data_Asset](_data.md#data_asset) instance.|
| [OH_Data_Asset_DestroyOne](_data.md#oh_data_asset_destroyone) ([Data_Asset](_data.md#data_asset) \*asset) | Destroys a [Data_Asset](_data.md#data_asset) instance.|
| [OH_Data_Asset_CreateMultiple](_data.md#oh_data_asset_createmultiple) (uint32_t count) | Creates multiple [Data_Asset](_data.md#data_asset) instances.|
| [OH_Data_Asset_DestroyMultiple](_data.md#oh_data_asset_destroymultiple) ([Data_Asset](_data.md#data_asset) \*\*assets, uint32_t count) | Destroys multiple [Data_Asset](_data.md#data_asset) instances.|
