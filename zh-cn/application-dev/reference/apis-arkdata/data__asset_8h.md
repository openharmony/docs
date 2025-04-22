# data_asset.h


## 概述

提供资产类型数据结构。

资产是指一种可以在数据管理中使用的数据结构，可以存储及查询一个文件的名称、绝对路径、相对路径、创建时间、修改时间、 状态、 占用空间等属性。

**引用文件：** <database/data/data_asset.h>

**库：** libnative_rdb_ndk.z.so

**起始版本：** 11

**相关模块：**[Data](_data.md)


## 汇总


### 类型定义

| 名称 | 描述 |
| -------- | -------- |
| [Data_AssetStatus](_data.md#data_assetstatus) | 资产状态值类型。 |
| [Data_Asset](_data.md#data_asset) | 表示资产附件类型的数据。 |


### 枚举

| 名称 | 描述 |
| -------- | -------- |
| [Data_AssetStatus](_data.md#data_assetstatus) {<br/>ASSET_NULL = 0, ASSET_NORMAL, ASSET_INSERT, ASSET_UPDATE,<br/>ASSET_DELETE, ASSET_ABNORMAL, ASSET_DOWNLOADING<br/>} | 资产状态值类型。 |


### 函数

| 名称 | 描述 |
| -------- | -------- |
| [OH_Data_Asset_SetName](_data.md#oh_data_asset_setname) ([Data_Asset](_data.md#data_asset) \*asset, const char \*name) | 设置资产类型数据的名称。 |
| [OH_Data_Asset_SetUri](_data.md#oh_data_asset_seturi) ([Data_Asset](_data.md#data_asset) \*asset, const char \*uri) | 设置资产类型数据在系统里的绝对路径，即URI。 |
| [OH_Data_Asset_SetPath](_data.md#oh_data_asset_setpath) ([Data_Asset](_data.md#data_asset) \*asset, const char \*path) | 设置资产类型数据在应用沙箱里的相对路径。 |
| [OH_Data_Asset_SetCreateTime](_data.md#oh_data_asset_setcreatetime) ([Data_Asset](_data.md#data_asset) \*asset, int64_t createTime) | 设置资产类型数据创建的时间。 |
| [OH_Data_Asset_SetModifyTime](_data.md#oh_data_asset_setmodifytime) ([Data_Asset](_data.md#data_asset) \*asset, int64_t modifyTime) | 设置资产类型数据最后修改的时间。 |
| [OH_Data_Asset_SetSize](_data.md#oh_data_asset_setsize) ([Data_Asset](_data.md#data_asset) \*asset, size_t size) | 设置资产类型数据占用空间的大小。 |
| [OH_Data_Asset_SetStatus](_data.md#oh_data_asset_setstatus) ([Data_Asset](_data.md#data_asset) \*asset, [Data_AssetStatus](_data.md#data_assetstatus) status) | 设置资产类型数据的状态码。 |
| [OH_Data_Asset_GetName](_data.md#oh_data_asset_getname) ([Data_Asset](_data.md#data_asset) \*asset, char \*name, size_t \*length) | 获取资产类型数据的名称。 |
| [OH_Data_Asset_GetUri](_data.md#oh_data_asset_geturi) ([Data_Asset](_data.md#data_asset) \*asset, char \*uri, size_t \*length) | 获取资产类型数据的绝对路径。 |
| [OH_Data_Asset_GetPath](_data.md#oh_data_asset_getpath) ([Data_Asset](_data.md#data_asset) \*asset, char \*path, size_t \*length) | 获取资产类型数据的相对路径。 |
| [OH_Data_Asset_GetCreateTime](_data.md#oh_data_asset_getcreatetime) ([Data_Asset](_data.md#data_asset) \*asset, int64_t \*createTime) | 获取资产类型数据的创建时间。 |
| [OH_Data_Asset_GetModifyTime](_data.md#oh_data_asset_getmodifytime) ([Data_Asset](_data.md#data_asset) \*asset, int64_t \*modifyTime) | 获取资产类型数据的最后修改的时间。 |
| [OH_Data_Asset_GetSize](_data.md#oh_data_asset_getsize) ([Data_Asset](_data.md#data_asset) \*asset, size_t \*size) | 获取资产类型数据占用空间的大小。 |
| [OH_Data_Asset_GetStatus](_data.md#oh_data_asset_getstatus) ([Data_Asset](_data.md#data_asset) \*asset, [Data_AssetStatus](_data.md#data_assetstatus) \*status) | i获取资产类型数据的状态码。 |
| [OH_Data_Asset_CreateOne](_data.md#oh_data_asset_createone) () | 创造一个[Data_Asset](_data.md#data_asset)类型实例。 |
| [OH_Data_Asset_DestroyOne](_data.md#oh_data_asset_destroyone) ([Data_Asset](_data.md#data_asset) \*asset) | 销毁[Data_Asset](_data.md#data_asset)对象并回收该对象占用的内存。 |
| [OH_Data_Asset_CreateMultiple](_data.md#oh_data_asset_createmultiple) (uint32_t count) | 创造指定数量的[Data_Asset](_data.md#data_asset)类型实例。 |
| [OH_Data_Asset_DestroyMultiple](_data.md#oh_data_asset_destroymultiple) ([Data_Asset](_data.md#data_asset) \*\*assets, uint32_t count) | 销毁多个[Data_Asset](_data.md#data_asset)对象并回收该对象占用的内存。 |
