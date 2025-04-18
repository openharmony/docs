# Data


## 概述

分布式数据管理（Distributed data manager，data）支持单设备的各种结构化数据的持久化，以及端云间的同步、共享功能。分布式数据管理定义了一系列数据类型，可以对数据进行增删改查。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**起始版本：** 11


## 汇总


### 文件

| 名称 | 描述 |
| -------- | -------- |
| [data_asset.h](data__asset_8h.md) | 提供资产类型数据结构。<br/>引用文件: <database/data/data_asset.h><br/>库: libnative_rdb_ndk.z.so<br/> |


### 类型定义

| 名称 | 描述 |
| -------- | -------- |
| [Data_AssetStatus](#data_assetstatus) | 资产状态值类型。 |
| [Data_Asset](#data_asset) | 表示资产附件类型的数据。 |


### 枚举

| 名称 | 描述 |
| -------- | -------- |
| [Data_AssetStatus](#data_assetstatus) {<br/>ASSET_NULL = 0, ASSET_NORMAL, ASSET_INSERT, ASSET_UPDATE,<br/>ASSET_DELETE, ASSET_ABNORMAL, ASSET_DOWNLOADING<br/>} | 资产状态值类型。 |


### 函数

| 名称 | 描述 |
| -------- | -------- |
| [OH_Data_Asset_SetName](#oh_data_asset_setname) ([Data_Asset](#data_asset) \*asset, const char \*name) | 设置资产类型数据的名称。 |
| [OH_Data_Asset_SetUri](#oh_data_asset_seturi) ([Data_Asset](#data_asset) \*asset, const char \*uri) | 设置资产类型数据在系统里的绝对路径，即URI。 |
| [OH_Data_Asset_SetPath](#oh_data_asset_setpath) ([Data_Asset](#data_asset) \*asset, const char \*path) | 设置资产类型数据在应用沙箱里的相对路径。 |
| [OH_Data_Asset_SetCreateTime](#oh_data_asset_setcreatetime) ([Data_Asset](#data_asset) \*asset, int64_t createTime) | 设置资产类型数据创建的时间。 |
| [OH_Data_Asset_SetModifyTime](#oh_data_asset_setmodifytime) ([Data_Asset](#data_asset) \*asset, int64_t modifyTime) | 设置资产类型数据最后修改的时间。 |
| [OH_Data_Asset_SetSize](#oh_data_asset_setsize) ([Data_Asset](#data_asset) \*asset, size_t size) | 设置资产类型数据占用空间的大小。 |
| [OH_Data_Asset_SetStatus](#oh_data_asset_setstatus) ([Data_Asset](#data_asset) \*asset, [Data_AssetStatus](#data_assetstatus) status) | 设置资产类型数据的状态码。 |
| [OH_Data_Asset_GetName](#oh_data_asset_getname) ([Data_Asset](#data_asset) \*asset, char \*name, size_t \*length) | 获取资产类型数据的名称。 |
| [OH_Data_Asset_GetUri](#oh_data_asset_geturi) ([Data_Asset](#data_asset) \*asset, char \*uri, size_t \*length) | 获取资产类型数据的绝对路径。 |
| [OH_Data_Asset_GetPath](#oh_data_asset_getpath) ([Data_Asset](#data_asset) \*asset, char \*path, size_t \*length) | 获取资产类型数据的相对路径。 |
| [OH_Data_Asset_GetCreateTime](#oh_data_asset_getcreatetime) ([Data_Asset](#data_asset) \*asset, int64_t \*createTime) | 获取资产类型数据的创建时间。 |
| [OH_Data_Asset_GetModifyTime](#oh_data_asset_getmodifytime) ([Data_Asset](#data_asset) \*asset, int64_t \*modifyTime) | 获取资产类型数据的最后修改的时间。 |
| [OH_Data_Asset_GetSize](#oh_data_asset_getsize) ([Data_Asset](#data_asset) \*asset, size_t \*size) | 获取资产类型数据占用空间的大小。 |
| [OH_Data_Asset_GetStatus](#oh_data_asset_getstatus) ([Data_Asset](#data_asset) \*asset, [Data_AssetStatus](#data_assetstatus) \*status) | 获取资产类型数据的状态码。 |
| [OH_Data_Asset_CreateOne](#oh_data_asset_createone) () | 创造一个[Data_Asset](#data_asset)类型实例。 |
| [OH_Data_Asset_DestroyOne](#oh_data_asset_destroyone) ([Data_Asset](#data_asset) \*asset) | 销毁[Data_Asset](#data_asset) 对象并回收该对象占用的内存。 |
| [OH_Data_Asset_CreateMultiple](#oh_data_asset_createmultiple) (uint32_t count) | 创造指定数量的[Data_Asset](#data_asset)类型实例。 |
| [OH_Data_Asset_DestroyMultiple](#oh_data_asset_destroymultiple) ([Data_Asset](#data_asset) \*\*assets, uint32_t count) | 销毁多个[Data_Asset](#data_asset) 对象并回收该对象占用的内存。 |


## 类型定义说明


### Data_Asset

```
typedef struct Data_Asset Data_Asset
```

**描述**

表示资产附件类型的数据。

提供资产附件的信息。

**起始版本：** 11


## 枚举类型说明


### Data_AssetStatus

```
enum Data_AssetStatus
```

**描述：**

资产状态值类型。

| 枚举值 | 描述 |
| -------- | -------- |
| ASSET_NULL | 表示资产为空。 |
| ASSET_NORMAL | 表示资产状态正常。 |
| ASSET_INSERT | 表示资产需要插入到云端。 |
| ASSET_UPDATE | 表示资产需要更新到云端。 |
| ASSET_DELETE | 表示资产需要在云端删除。 |
| ASSET_ABNORMAL | 表示资产状态异常。 |
| ASSET_DOWNLOADING | 表示资产正在下载到本地设备。 |


## 函数说明


### OH_Data_Asset_CreateMultiple()

```
Data_Asset** OH_Data_Asset_CreateMultiple (uint32_t count)
```

**描述**

创造指定数量的[Data_Asset](#data_asset) 类型实例。

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| count | 代表创建的资产类型数据的数量。 |

**返回：**

创建成功则返回一个指向[Data_Asset](#data_asset)结构体实例的指针，否则返回NULL。

**参见：**

[Data_Asset](#data_asset).


### OH_Data_Asset_CreateOne()

```
Data_Asset* OH_Data_Asset_CreateOne ()
```

**描述**

创造一个[Data_Asset](#data_asset) 类型实例。

**起始版本：** 11

**返回：**

创建成功则返回一个指向[Data_Asset](#data_asset)结构体实例的指针，否则返回NULL。

**参见：**

[Data_Asset](#data_asset).


### OH_Data_Asset_DestroyMultiple()

```
int OH_Data_Asset_DestroyMultiple (Data_Asset ** assets, uint32_t count )
```

**描述**

销毁多个[Data_Asset](#data_asset) 对象并回收该对象占用的内存。

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| assets | 表示指向[Data_Asset](#data_asset)实例的指针。 |
| count | 代表需要销毁的[Data_Asset](#data_asset)类型对象的数量。 |

**返回：**

返回操作是否成功，成功时返回RDB_OK，出错时返回对应的错误码。详细信息可以查看[OH_Rdb_ErrCode](_r_d_b.md#oh_rdb_errcode-1)。

**参见：**

[Data_Asset](#data_asset), [OH_Rdb_ErrCode](_r_d_b.md#oh_rdb_errcode-1).


### OH_Data_Asset_DestroyOne()

```
int OH_Data_Asset_DestroyOne (Data_Asset * asset)
```

**描述**

销毁[Data_Asset](#data_asset) 对象并回收该对象占用的内存。

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| asset | 表示指向[Data_Asset](#data_asset)实例的指针。 |

**返回：**

返回操作是否成功，成功时返回RDB_OK，出错时返回对应的错误码。详细信息可以查看[OH_Rdb_ErrCode](_r_d_b.md#oh_rdb_errcode-1)。

**参见：**

[Data_Asset](#data_asset), [OH_Rdb_ErrCode](_r_d_b.md#oh_rdb_errcode-1).


### OH_Data_Asset_GetCreateTime()

```
int OH_Data_Asset_GetCreateTime (Data_Asset * asset, int64_t * createTime )
```

**描述**

获取资产类型数据的创建时间。

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| asset | 表示指向[Data_Asset](#data_asset)实例的指针。 |
| createTime | 参数是输出参数，资产类型数据的创建时间会以int64_t形式写入该变量。 |

**返回：**

返回特定的错误码值。详细信息可以查看[OH_Rdb_ErrCode](_r_d_b.md#oh_rdb_errcode-1)。

**参见：**

[Data_Asset](#data_asset)


### OH_Data_Asset_GetModifyTime()

```
int OH_Data_Asset_GetModifyTime (Data_Asset * asset, int64_t * modifyTime )
```

**描述**

获取资产类型数据的最后修改的时间。

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| asset | 表示指向[Data_Asset](#data_asset)实例的指针。 |
| modifyTime | 参数是输出参数，资产类型数据的最后修改时间会以int64_t形式写入该变量。 |

**返回：**

返回特定的错误码值。详细信息可以查看[OH_Rdb_ErrCode](_r_d_b.md#oh_rdb_errcode-1)。

**参见：**

[Data_Asset](#data_asset)


### OH_Data_Asset_GetName()

```
int OH_Data_Asset_GetName (Data_Asset * asset, char * name, size_t * length )
```

**描述**

获取资产类型数据的名称。

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| asset | 表示指向[Data_Asset](#data_asset)实例的指针。 |
| name | 该参数是输出参数，资产类型数据的名称会以字符串形式写入该变量。 |
| length | 表示name的长度。 |

**返回：**

返回特定的错误码值。详细信息可以查看[OH_Rdb_ErrCode](_r_d_b.md#oh_rdb_errcode-1)。

**参见：**

[Data_Asset](#data_asset)


### OH_Data_Asset_GetPath()

```
int OH_Data_Asset_GetPath (Data_Asset * asset, char * path, size_t * length )
```

**描述**

获取资产类型数据的相对路径。

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| asset | 表示指向[Data_Asset](#data_asset)实例的指针。 |
| path | 参数是输出参数，资产类型数据的相对路径会以字符串形式写入该变量。 |
| length | 表示path的长度。 |

**返回：**

返回特定的错误码值。详细信息可以查看[OH_Rdb_ErrCode](_r_d_b.md#oh_rdb_errcode-1)。

**参见：**

[Data_Asset](#data_asset)


### OH_Data_Asset_GetSize()

```
int OH_Data_Asset_GetSize (Data_Asset * asset, size_t * size )
```

**描述**

获取资产类型数据占用空间的大小。

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| asset | 表示指向[Data_Asset](#data_asset)实例的指针。 |
| size | 参数是输出参数，资产类型数据的占用空间大小会以size_t形式写入该变量。 |

**返回：**

返回特定的错误码值。详细信息可以查看[OH_Rdb_ErrCode](_r_d_b.md#oh_rdb_errcode-1)。

**参见：**

[Data_Asset](#data_asset)


### OH_Data_Asset_GetStatus()

```
int OH_Data_Asset_GetStatus (Data_Asset * asset, Data_AssetStatus * status )
```

**描述**

获取资产类型数据的状态码。

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| asset | 表示指向[Data_Asset](#data_asset)实例的指针。 |
| status | 参数是输出参数，资产类型数据的状态码会以[Data_AssetStatus](#data_assetstatus)形式写入该变量。 |

**返回：**

返回特定的错误码值。详细信息可以查看[OH_Rdb_ErrCode](_r_d_b.md#oh_rdb_errcode-1)。

**参见：**

[Data_Asset](#data_asset)


### OH_Data_Asset_GetUri()

```
int OH_Data_Asset_GetUri (Data_Asset * asset, char * uri, size_t * length )
```

**描述**

获取资产类型数据的绝对路径。

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| asset | 表示指向[Data_Asset](#data_asset)实例的指针。 |
| uri | 参数是输出参数，资产类型数据的绝对路径会以字符串形式写入该变量。 |
| length | 表示uri的长度。 |

**返回：**

返回特定的错误码值。详细信息可以查看[OH_Rdb_ErrCode](_r_d_b.md#oh_rdb_errcode-1)。

**参见：**

[Data_Asset](#data_asset)


### OH_Data_Asset_SetCreateTime()

```
int OH_Data_Asset_SetCreateTime (Data_Asset * asset, int64_t createTime )
```

**描述**

设置资产类型数据创建的时间。

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| asset | 表示指向[Data_Asset](#data_asset)实例的指针。 |
| createTime | 表示要设置的创建时间。 |

**返回：**

返回特定的错误码值。详细信息可以查看[OH_Rdb_ErrCode](_r_d_b.md#oh_rdb_errcode-1)。

**参见：**

[Data_Asset](#data_asset)


### OH_Data_Asset_SetModifyTime()

```
int OH_Data_Asset_SetModifyTime (Data_Asset * asset, int64_t modifyTime )
```

**描述**

设置资产类型数据最后修改的时间。

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| asset | 表示指向[Data_Asset](#data_asset)实例的指针。 |
| modifyTime | 表示要设置的最后修改的时间。 |

**返回：**

返回特定的错误码值。详细信息可以查看[OH_Rdb_ErrCode](_r_d_b.md#oh_rdb_errcode-1)。

**参见：**

[Data_Asset](#data_asset)


### OH_Data_Asset_SetName()

```
int OH_Data_Asset_SetName (Data_Asset * asset, const char * name )
```

**描述**

设置资产类型数据的名称。

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| asset | 表示指向[Data_Asset](#data_asset)实例的指针。 |
| name | 表示要设置的名称。 |

**返回：**

返回特定的错误码值。详细信息可以查看[OH_Rdb_ErrCode](_r_d_b.md#oh_rdb_errcode-1)。

**参见：**

[Data_Asset](#data_asset)


### OH_Data_Asset_SetPath()

```
int OH_Data_Asset_SetPath (Data_Asset * asset, const char * path )
```

**描述**

设置资产类型数据在应用沙箱里的相对路径。

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| asset | 表示指向[Data_Asset](#data_asset)实例的指针。 |
| path | 表示要设置的相对路径。 |

**返回：**

返回特定的错误码值。详细信息可以查看[OH_Rdb_ErrCode](_r_d_b.md#oh_rdb_errcode-1)。

**参见：**

[Data_Asset](#data_asset)


### OH_Data_Asset_SetSize()

```
int OH_Data_Asset_SetSize (Data_Asset * asset, size_t size )
```

**描述**

设置资产类型数据占用空间的大小。

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| asset | 表示指向[Data_Asset](#data_asset)实例的指针。 |
| size | 表示要设置的占用空间的大小。 |

**返回：**

返回特定的错误码值。详细信息可以查看[OH_Rdb_ErrCode](_r_d_b.md#oh_rdb_errcode-1)。

**参见：**

[Data_Asset](#data_asset)


### OH_Data_Asset_SetStatus()

```
int OH_Data_Asset_SetStatus (Data_Asset * asset, Data_AssetStatus status )
```

**描述**

设置资产类型数据的状态码。

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| asset | 表示指向[Data_Asset](#data_asset)实例的指针。 |
| status | 表示需要设置的状态码。详细信息可以查看[Data_AssetStatus](#data_assetstatus)。 |

**返回：**

返回特定的错误码值。详细信息可以查看[OH_Rdb_ErrCode](_r_d_b.md#oh_rdb_errcode-1)。

**参见：**

[Data_Asset](#data_asset), [Data_AssetStatus](#data_assetstatus)


### OH_Data_Asset_SetUri()

```
int OH_Data_Asset_SetUri (Data_Asset * asset, const char * uri )
```

**描述**

设置资产类型数据在系统里的绝对路径，即URI。

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| asset | 表示指向[Data_Asset](#data_asset)实例的指针。 |
| name | 表示要设置的URI。 |

**返回：**

返回特定的错误码值。详细信息可以查看[OH_Rdb_ErrCode](_r_d_b.md#oh_rdb_errcode-1)。

**参见：**

[Data_Asset](#data_asset)
