# data_asset.h

## 概述

提供资产类型数据结构。<br>资产是指可以一种可以在数据管理中使用的数据结构，可以存储及查询一个文件的名称、绝对路径、相对路径、创建时间、修改时间、状态、占用空间等属性。

**引用文件：** <database/rdb/data_asset.h>

**库：** libnative_rdb_ndk.z.so

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**起始版本：** 11

**相关模块：** [RDB](capi-rdb.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [Data_Asset](capi-data-asset.md) | Data_Asset | 表示资产附件类型的数据。<br>提供资产附件的信息。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [Data_AssetStatus](#data_assetstatus) | Data_AssetStatus | 资产状态值类型。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [int OH_Data_Asset_SetName(Data_Asset *asset, const char *name)](#oh_data_asset_setname) | 设置资产类型数据的名称。 |
| [int OH_Data_Asset_SetUri(Data_Asset *asset, const char *uri)](#oh_data_asset_seturi) | 设置资产类型数据在系统里的绝对路径，即URI。 |
| [int OH_Data_Asset_SetPath(Data_Asset *asset, const char *path)](#oh_data_asset_setpath) | 设置资产类型数据在应用沙箱里的相对路径。 |
| [int OH_Data_Asset_SetCreateTime(Data_Asset *asset, int64_t createTime)](#oh_data_asset_setcreatetime) | 设置资产类型数据创建的时间。 |
| [int OH_Data_Asset_SetModifyTime(Data_Asset *asset, int64_t modifyTime)](#oh_data_asset_setmodifytime) | 设置资产类型数据最后修改的时间。 |
| [int OH_Data_Asset_SetSize(Data_Asset *asset, size_t size)](#oh_data_asset_setsize) | 设置资产类型数据占用空间的大小。 |
| [int OH_Data_Asset_SetStatus(Data_Asset *asset, Data_AssetStatus status)](#oh_data_asset_setstatus) | 设置资产类型数据的状态码。 |
| [int OH_Data_Asset_GetName(Data_Asset *asset, char *name, size_t *length)](#oh_data_asset_getname) | 获取资产类型数据的名称。 |
| [int OH_Data_Asset_GetUri(Data_Asset *asset, char *uri, size_t *length)](#oh_data_asset_geturi) | 获取资产类型数据的绝对路径。 |
| [int OH_Data_Asset_GetPath(Data_Asset *asset, char *path, size_t *length)](#oh_data_asset_getpath) | 获取资产类型数据的相对路径。 |
| [int OH_Data_Asset_GetCreateTime(Data_Asset *asset, int64_t *createTime)](#oh_data_asset_getcreatetime) | 获取资产类型数据的创建时间。 |
| [int OH_Data_Asset_GetModifyTime(Data_Asset *asset, int64_t *modifyTime)](#oh_data_asset_getmodifytime) | 获取资产类型数据的最后修改的时间。 |
| [int OH_Data_Asset_GetSize(Data_Asset *asset, size_t *size)](#oh_data_asset_getsize) | 获取资产类型数据占用空间的大小。 |
| [int OH_Data_Asset_GetStatus(Data_Asset *asset, Data_AssetStatus *status)](#oh_data_asset_getstatus) | 获取资产类型数据的状态码。 |
| [Data_Asset *OH_Data_Asset_CreateOne(void)](#oh_data_asset_createone) | 创造一个[Data_Asset](capi-data-asset.md)类型实例。 |
| [int OH_Data_Asset_DestroyOne(Data_Asset *asset)](#oh_data_asset_destroyone) | 销毁[Data_Asset](capi-data-asset.md) 对象并回收该对象占用的内存。 |
| [Data_Asset **OH_Data_Asset_CreateMultiple(uint32_t count)](#oh_data_asset_createmultiple) | 创造指定数量的[Data_Asset](capi-data-asset.md)类型实例。 |
| [int OH_Data_Asset_DestroyMultiple(Data_Asset **assets, uint32_t count)](#oh_data_asset_destroymultiple) | 销毁多个[Data_Asset](capi-data-asset.md) 对象并回收该对象占用的内存。 |

## 枚举类型说明

### Data_AssetStatus

```
enum Data_AssetStatus
```

**描述**

资产状态值类型。

**起始版本：** 11

| 枚举项 | 描述 |
| -- | -- |
| ASSET_NULL = 0 | 表示资产为空。 |
| ASSET_NORMAL | 表示资产状态正常。 |
| ASSET_INSERT | 表示资产需要插入到云端。 |
| ASSET_UPDATE | 表示资产需要更新到云端。 |
| ASSET_DELETE | 表示资产需要在云端删除。 |
| ASSET_ABNORMAL | 表示资产状态异常。 |
| ASSET_DOWNLOADING | 表示资产正在下载到本地设备。 |


## 函数说明

### OH_Data_Asset_SetName()

```
int OH_Data_Asset_SetName(Data_Asset *asset, const char *name)
```

**描述**

设置资产类型数据的名称。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Data_Asset](capi-data-asset.md) *asset | 表示指向[Data_Asset](capi-data-asset.md)实例的指针。 |
| const char *name | 表示要设置的名称。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回特定的错误码值。详细信息可以查看[OH_Rdb_ErrCode](capi-relational-store-error-code-h.md#oh_rdb_errcode)。<br>返回RDB_OK表示成功。<br>返回RDB_E_INVALID_ARGS表示无效参数。 |

### OH_Data_Asset_SetUri()

```
int OH_Data_Asset_SetUri(Data_Asset *asset, const char *uri)
```

**描述**

设置资产类型数据在系统里的绝对路径，即URI。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Data_Asset](capi-data-asset.md) *asset | 表示指向[Data_Asset](capi-data-asset.md)实例的指针。 |
| name |  表示要设置的URI。 |

**返回：**

| 类型 | 说明                                                                                                                                          |
| -- |---------------------------------------------------------------------------------------------------------------------------------------------|
| int | 返回特定的错误码值。详细信息可以查看[OH_Rdb_ErrCode](capi-relational-store-error-code-h.md#oh_rdb_errcode)。<br>返回RDB_OK表示成功。<br>返回RDB_E_INVALID_ARGS表示无效参数。 |

### OH_Data_Asset_SetPath()

```
int OH_Data_Asset_SetPath(Data_Asset *asset, const char *path)
```

**描述**

设置资产类型数据在应用沙箱里的相对路径。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Data_Asset](capi-data-asset.md) *asset | 表示指向[Data_Asset](capi-data-asset.md)实例的指针。 |
| const char *path | 表示要设置的相对路径。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回特定的错误码值。详细信息可以查看[OH_Rdb_ErrCode](capi-relational-store-error-code-h.md#oh_rdb_errcode)。<br>返回RDB_OK表示成功。<br>返回RDB_E_INVALID_ARGS表示无效参数。 |

### OH_Data_Asset_SetCreateTime()

```
int OH_Data_Asset_SetCreateTime(Data_Asset *asset, int64_t createTime)
```

**描述**

设置资产类型数据创建的时间。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Data_Asset](capi-data-asset.md) *asset | 表示指向[Data_Asset](capi-data-asset.md)实例的指针。 |
| int64_t createTime | 表示要设置的创建时间。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回特定的错误码值。详细信息可以查看[OH_Rdb_ErrCode](capi-relational-store-error-code-h.md#oh_rdb_errcode)。<br>返回RDB_OK表示成功。<br>返回RDB_E_INVALID_ARGS表示无效参数。 |

### OH_Data_Asset_SetModifyTime()

```
int OH_Data_Asset_SetModifyTime(Data_Asset *asset, int64_t modifyTime)
```

**描述**

设置资产类型数据最后修改的时间。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Data_Asset](capi-data-asset.md) *asset | 表示指向[Data_Asset](capi-data-asset.md)实例的指针。 |
| int64_t modifyTime | 表示要设置的最后修改的时间。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回特定的错误码值。详细信息可以查看[OH_Rdb_ErrCode](capi-relational-store-error-code-h.md#oh_rdb_errcode)。<br>返回RDB_OK表示成功。<br>返回RDB_E_INVALID_ARGS表示无效参数。 |

### OH_Data_Asset_SetSize()

```
int OH_Data_Asset_SetSize(Data_Asset *asset, size_t size)
```

**描述**

设置资产类型数据占用空间的大小。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Data_Asset](capi-data-asset.md) *asset | 表示指向[Data_Asset](capi-data-asset.md)实例的指针。 |
| size_t size | 表示要设置的占用空间的大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回特定的错误码值。详细信息可以查看[OH_Rdb_ErrCode](capi-relational-store-error-code-h.md#oh_rdb_errcode)。<br>返回RDB_OK表示成功。<br>返回RDB_E_INVALID_ARGS表示无效参数。 |

### OH_Data_Asset_SetStatus()

```
int OH_Data_Asset_SetStatus(Data_Asset *asset, Data_AssetStatus status)
```

**描述**

设置资产类型数据的状态码。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Data_Asset](capi-data-asset.md) *asset | 表示指向[Data_Asset](capi-data-asset.md)实例的指针。 |
| [Data_AssetStatus](#data_assetstatus) status | 表示需要设置的状态码。详细信息可以查看[Data_AssetStatus](capi-data-asset-h.md#data_assetstatus)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回特定的错误码值。详细信息可以查看[OH_Rdb_ErrCode](capi-relational-store-error-code-h.md#oh_rdb_errcode)。<br>返回RDB_OK表示成功。<br>返回RDB_E_INVALID_ARGS表示无效参数。 |

### OH_Data_Asset_GetName()

```
int OH_Data_Asset_GetName(Data_Asset *asset, char *name, size_t *length)
```

**描述**

获取资产类型数据的名称。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Data_Asset](capi-data-asset.md) *asset | 表示指向[Data_Asset](capi-data-asset.md)实例的指针。 |
| char *name | 该参数是输出参数，资产类型数据的名称会以字符串形式写入该变量。 |
| size_t *length | 表示name的长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回特定的错误码值。详细信息可以查看[OH_Rdb_ErrCode](capi-relational-store-error-code-h.md#oh_rdb_errcode)。<br>返回RDB_ERR表示函数执行异常。<br>返回RDB_OK表示成功。<br>返回RDB_E_INVALID_ARGS表示无效参数。 |

### OH_Data_Asset_GetUri()

```
int OH_Data_Asset_GetUri(Data_Asset *asset, char *uri, size_t *length)
```

**描述**

获取资产类型数据的绝对路径。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Data_Asset](capi-data-asset.md) *asset | 表示指向[Data_Asset](capi-data-asset.md)实例的指针。 |
| char *uri | 参数是输出参数，资产类型数据的绝对路径会以字符串形式写入该变量。 |
| size_t *length | 表示uri的长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回特定的错误码值。详细信息可以查看[OH_Rdb_ErrCode](capi-relational-store-error-code-h.md#oh_rdb_errcode)。<br>返回RDB_ERR表示函数执行异常。<br>返回RDB_OK表示成功。<br>返回RDB_E_INVALID_ARGS表示无效参数。 |

### OH_Data_Asset_GetPath()

```
int OH_Data_Asset_GetPath(Data_Asset *asset, char *path, size_t *length)
```

**描述**

获取资产类型数据的相对路径。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Data_Asset](capi-data-asset.md) *asset | 表示指向[Data_Asset](capi-data-asset.md)实例的指针。 |
| char *path | 参数是输出参数，资产类型数据的相对路径会以字符串形式写入该变量。 |
| size_t *length | 表示path的长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回特定的错误码值。详细信息可以查看[OH_Rdb_ErrCode](capi-relational-store-error-code-h.md#oh_rdb_errcode)。<br>返回RDB_ERR表示函数执行异常。<br>返回RDB_OK表示成功。<br>返回RDB_E_INVALID_ARGS表示无效参数。 |

### OH_Data_Asset_GetCreateTime()

```
int OH_Data_Asset_GetCreateTime(Data_Asset *asset, int64_t *createTime)
```

**描述**

获取资产类型数据的创建时间。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Data_Asset](capi-data-asset.md) *asset | 表示指向[Data_Asset](capi-data-asset.md)实例的指针。 |
| int64_t *createTime | 参数是输出参数，资产类型数据的创建时间会以int64_t形式写入该变量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回特定的错误码值。详细信息可以查看[OH_Rdb_ErrCode](capi-relational-store-error-code-h.md#oh_rdb_errcode)。<br>返回RDB_ERR表示函数执行异常。<br>返回RDB_OK表示成功。<br>返回RDB_E_INVALID_ARGS表示无效参数。 |

**参考：**

Data_Asset

### OH_Data_Asset_GetModifyTime()

```
int OH_Data_Asset_GetModifyTime(Data_Asset *asset, int64_t *modifyTime)
```

**描述**

获取资产类型数据的最后修改的时间。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Data_Asset](capi-data-asset.md) *asset | 表示指向[Data_Asset](capi-data-asset.md)实例的指针。 |
| int64_t *modifyTime | 参数是输出参数，资产类型数据的最后修改时间会以int64_t形式写入该变量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回特定的错误码值。详细信息可以查看[OH_Rdb_ErrCode](capi-relational-store-error-code-h.md#oh_rdb_errcode)。<br>返回RDB_ERR表示函数执行异常。<br>返回RDB_OK表示成功。<br>返回RDB_E_INVALID_ARGS表示无效参数。 |

### OH_Data_Asset_GetSize()

```
int OH_Data_Asset_GetSize(Data_Asset *asset, size_t *size)
```

**描述**

获取资产类型数据占用空间的大小。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Data_Asset](capi-data-asset.md) *asset | 表示指向[Data_Asset](capi-data-asset.md)实例的指针。 |
| size_t *size | 参数是输出参数，资产类型数据的占用空间大小会以size_t形式写入该变量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回特定的错误码值。详细信息可以查看[OH_Rdb_ErrCode](capi-relational-store-error-code-h.md#oh_rdb_errcode)。<br>返回RDB_ERR表示函数执行异常。<br>返回RDB_OK表示成功。<br>返回RDB_E_INVALID_ARGS表示无效参数。 |

### OH_Data_Asset_GetStatus()

```
int OH_Data_Asset_GetStatus(Data_Asset *asset, Data_AssetStatus *status)
```

**描述**

获取资产类型数据的状态码。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Data_Asset](capi-data-asset.md) *asset | 表示指向[Data_Asset](capi-data-asset.md)实例的指针。 |
| [Data_AssetStatus](#data_assetstatus) *status | 参数是输出参数，资产类型数据的状态码会以[Data_AssetStatus](capi-data-asset-h.md#data_assetstatus)形式写入该变量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回特定的错误码值。详细信息可以查看[OH_Rdb_ErrCode](capi-relational-store-error-code-h.md#oh_rdb_errcode)。<br>返回RDB_OK表示成功。<br>返回RDB_E_INVALID_ARGS表示无效参数。 |

### OH_Data_Asset_CreateOne()

```
Data_Asset *OH_Data_Asset_CreateOne(void)
```

**描述**

创造一个[Data_Asset](capi-data-asset.md)类型实例。

**起始版本：** 11

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Data_Asset](capi-data-asset.md) | 创建成功则返回一个指向[Data_Asset](capi-data-asset.md)结构体实例的指针，否则返回NULL。 |

### OH_Data_Asset_DestroyOne()

```
int OH_Data_Asset_DestroyOne(Data_Asset *asset)
```

**描述**

销毁[Data_Asset](capi-data-asset.md) 对象并回收该对象占用的内存。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Data_Asset](capi-data-asset.md) *asset | 表示指向[Data_Asset](capi-data-asset.md)实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回操作是否成功，成功时返回RDB_OK，出错时返回对应的错误码。详细信息可以查看[OH_Rdb_ErrCode](capi-relational-store-error-code-h.md#oh_rdb_errcode)。 |

### OH_Data_Asset_CreateMultiple()

```
Data_Asset **OH_Data_Asset_CreateMultiple(uint32_t count)
```

**描述**

创造指定数量的[Data_Asset](capi-data-asset.md)类型实例。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| uint32_t count | 代表创建的资产类型数据的数量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Data_Asset](capi-data-asset.md) | 创建成功则返回一个指向[Data_Asset](capi-data-asset.md)结构体实例的指针，否则返回NULL。 |

### OH_Data_Asset_DestroyMultiple()

```
int OH_Data_Asset_DestroyMultiple(Data_Asset **assets, uint32_t count)
```

**描述**

销毁多个[Data_Asset](capi-data-asset.md) 对象并回收该对象占用的内存。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Data_Asset](capi-data-asset.md) **assets | 表示指向[Data_Asset](capi-data-asset.md)实例的指针。 |
| uint32_t count | 代表需要销毁的[Data_Asset](capi-data-asset.md)类型对象的数量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回操作是否成功，成功时返回RDB_OK，出错时返回对应的错误码。详细信息可以查看[OH_Rdb_ErrCode](capi-relational-store-error-code-h.md#oh_rdb_errcode)。 |



