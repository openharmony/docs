# asset_api.h

<!--Kit: Asset Store Kit-->
<!--Subsystem: Security-->
<!--Owner: @JeremyXu-->
<!--Designer: @skye_you-->
<!--Tester: @nacyli-->
<!--Adviser: @zengyawen-->

## 概述

声明用于访问关键资产的接口。

**引用文件：** <asset/asset_api.h>

**库：** libasset_ndk.z.so

**系统能力：** SystemCapability.Security.Asset

**起始版本：** 11

**相关模块：** [AssetApi](capi-assetapi.md)

## 汇总

### 函数

| 名称 | 描述 |
| -- | -- |
| [int32_t OH_Asset_Add(const Asset_Attr *attributes, uint32_t attrCnt)](#oh_asset_add) | 新增一条关键资产。<br>如果要设置[Asset_Tag](capi-asset-type-h.md#asset_tag).ASSET_TAG_IS_PERSISTENT属性，需要申请ohos.permission.STORE_PERSISTENT_DATA权限。 |
| [int32_t OH_Asset_Remove(const Asset_Attr *query, uint32_t queryCnt)](#oh_asset_remove) | 删除符合条件的一条或多条关键资产。 |
| [int32_t OH_Asset_Update(const Asset_Attr *query, uint32_t queryCnt,const Asset_Attr *attributesToUpdate, uint32_t updateCnt)](#oh_asset_update) | 更新符合条件的一条关键资产。 |
| [int32_t OH_Asset_PreQuery(const Asset_Attr *query, uint32_t queryCnt, Asset_Blob *challenge)](#oh_asset_prequery) | 查询的预处理，用于需要用户认证的关键资产。 |
| [int32_t OH_Asset_Query(const Asset_Attr *query, uint32_t queryCnt, Asset_ResultSet *resultSet)](#oh_asset_query) | 查询一条或多条符合条件的关键资产。 |
| [int32_t OH_Asset_PostQuery(const Asset_Attr *handle, uint32_t handleCnt)](#oh_asset_postquery) | 查询的后置处理，用于需要用户认证的关键资产。 |
| [int32_t OH_Asset_QuerySyncResult(const Asset_Attr *query, uint32_t queryCnt, Asset_SyncResult *syncResult)](#oh_asset_querysyncresult) | 查询关键资产的同步结果。 |
| [Asset_Attr *OH_Asset_ParseAttr(const Asset_Result *result, Asset_Tag tag)](#oh_asset_parseattr) | 解析查询结果，并获取指定的属性值。 |
| [void OH_Asset_FreeBlob(Asset_Blob *blob)](#oh_asset_freeblob) | 释放挑战值所占用的内存。 |
| [void OH_Asset_FreeResultSet(Asset_ResultSet *resultSet)](#oh_asset_freeresultset) | 释放查询结果所占用的内存。 |

## 函数说明

### OH_Asset_Add()

```
int32_t OH_Asset_Add(const Asset_Attr *attributes, uint32_t attrCnt)
```

**描述**

新增一条关键资产。

如果要设置[Asset_Tag](capi-asset-type-h.md#asset_tag).ASSET_TAG_IS_PERSISTENT属性，需要申请ohos.permission.STORE_PERSISTENT_DATA权限。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [Asset_Attr](capi-assettype-asset-attr.md) *attributes | 待新增关键资产的属性集合。 |
| uint32_t attrCnt | 待新增关键资产的属性数量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [Asset_ResultCode](capi-asset-type-h.md#asset_resultcode):<br>     ASSET_SUCCESS = 0：操作成功。<br>     ASSET_PERMISSION_DENIED = 201：调用方不是一个系统应用。<br>     ASSET_INVALID_ARGUMENT = 401：参数错误。 可能原因:<br>         1. 必选参数未指定。<br>         2. 参数类型错误。<br>         3. 参数校验失败。<br>     ASSET_SERVICE_UNAVAILABLE = 24000001：关键资产服务不可用。<br>     ASSET_DUPLICATED = 24000003：关键资产已存在。<br>     ASSET_STATUS_MISMATCH = 24000005：锁屏状态不匹配。<br>     ASSET_OUT_OF_MEMORY = 24000006：系统内存不足。<br>     ASSET_DATA_CORRUPTED = 24000007：关键资产损坏。<br>     ASSET_DATABASE_ERROR = 24000008：数据库操作失败。<br>     ASSET_CRYPTO_ERROR = 24000009：算法库操作失败。<br>     ASSET_IPC_ERROR = 24000010：进程通信错误。<br>     ASSET_BMS_ERROR = 24000011：包管理服务异常。<br>     ASSET_ACCOUNT_ERROR = 24000012：账号系统异常。<br>     ASSET_ACCESS_TOKEN_ERROR = 24000013：访问控制服务异常。<br>     ASSET_FILE_OPERATION_ERROR = 24000014：文件操作失败。<br>     ASSET_GET_SYSTEM_TIME_ERROR = 24000015：获取系统时间失败。 |

### OH_Asset_Remove()

```
int32_t OH_Asset_Remove(const Asset_Attr *query, uint32_t queryCnt)
```

**描述**

删除符合条件的一条或多条关键资产。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [Asset_Attr](capi-assettype-asset-attr.md) *query | 待删除关键资产的搜索条件。 |
| uint32_t queryCnt | 待删除关键资产搜索条件的个数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [Asset_ResultCode](capi-asset-type-h.md#asset_resultcode):<br>     ASSET_SUCCESS = 0：操作成功。<br>     ASSET_INVALID_ARGUMENT = 401：参数错误。 可能原因:<br>         1. 参数类型错误。<br>         2. 参数校验失败。<br>     ASSET_SERVICE_UNAVAILABLE = 24000001：关键资产服务不可用。<br>     ASSET_NOT_FOUND = 24000002：未找到关键资产。<br>     ASSET_OUT_OF_MEMORY = 24000006：系统内存不足。<br>     ASSET_DATA_CORRUPTED = 24000007：关键资产损坏。<br>     ASSET_DATABASE_ERROR = 24000008：数据库操作失败。<br>     ASSET_IPC_ERROR = 24000010：进程通信错误。<br>     ASSET_BMS_ERROR = 24000011：包管理服务异常。<br>     ASSET_ACCOUNT_ERROR = 24000012：账号系统异常。<br>     ASSET_ACCESS_TOKEN_ERROR = 24000013：访问控制服务异常。<br>     ASSET_GET_SYSTEM_TIME_ERROR = 24000015：获取系统时间失败。 |

### OH_Asset_Update()

```
int32_t OH_Asset_Update(const Asset_Attr *query, uint32_t queryCnt,const Asset_Attr *attributesToUpdate, uint32_t updateCnt)
```

**描述**

更新符合条件的一条关键资产。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [Asset_Attr](capi-assettype-asset-attr.md) *query | 待更新关键资产的搜索条件。 |
| uint32_t queryCnt | 待更新关键资产搜索条件的个数。 |
| const [Asset_Attr](capi-assettype-asset-attr.md) *attributesToUpdate | 待更新关键资产的属性集合。 |
| uint32_t updateCnt | 待更新关键资产的属性数量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [Asset_ResultCode](capi-asset-type-h.md#asset_resultcode):<br>     ASSET_SUCCESS = 0：操作成功。<br>     ASSET_INVALID_ARGUMENT = 401：参数错误。 可能原因:<br>         1. 必选参数未指定。<br>         2. 参数类型错误。<br>         3. 参数校验失败。<br>     ASSET_SERVICE_UNAVAILABLE = 24000001：关键资产服务不可用。<br>     ASSET_NOT_FOUND = 24000002：未找到关键资产。<br>     ASSET_STATUS_MISMATCH = 24000005：锁屏状态不匹配。<br>     ASSET_OUT_OF_MEMORY = 24000006：系统内存不足。<br>     ASSET_DATA_CORRUPTED = 24000007：关键资产损坏。<br>     ASSET_DATABASE_ERROR = 24000008：数据库操作失败。<br>     ASSET_CRYPTO_ERROR = 24000009：算法库操作失败。<br>     ASSET_IPC_ERROR = 24000010：进程通信错误。<br>     ASSET_BMS_ERROR = 24000011：包管理服务异常。<br>     ASSET_ACCOUNT_ERROR = 24000012：账号系统异常。<br>     ASSET_ACCESS_TOKEN_ERROR = 24000013：访问控制服务异常。<br>     ASSET_GET_SYSTEM_TIME_ERROR = 24000015：获取系统时间失败。 |

### OH_Asset_PreQuery()

```
int32_t OH_Asset_PreQuery(const Asset_Attr *query, uint32_t queryCnt, Asset_Blob *challenge)
```

**描述**

查询的预处理，用于需要用户认证的关键资产。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [Asset_Attr](capi-assettype-asset-attr.md) *query | 关键资产的查询条件。 |
| uint32_t queryCnt | 关键资产查询条件的个数。 |
| [Asset_Blob](capi-assettype-asset-blob.md) *challenge | 挑战值，在后续调用[OH_Asset_Query](#oh_asset_query)时使用。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [Asset_ResultCode](capi-asset-type-h.md#asset_resultcode):<br>     ASSET_SUCCESS = 0：操作成功。<br>     ASSET_INVALID_ARGUMENT = 401：参数错误。 可能原因:<br>         1. 参数类型错误。<br>         2. 参数校验失败。<br>     ASSET_SERVICE_UNAVAILABLE = 24000001：关键资产服务不可用。<br>     ASSET_NOT_FOUND = 24000002：未找到关键资产。<br>     ASSET_STATUS_MISMATCH = 24000005：锁屏状态不匹配。<br>     ASSET_OUT_OF_MEMORY = 24000006：系统内存不足。<br>     ASSET_DATA_CORRUPTED = 24000007：关键资产损坏。<br>     ASSET_DATABASE_ERROR = 24000008：数据库操作失败。<br>     ASSET_CRYPTO_ERROR = 24000009：算法库操作失败。<br>     ASSET_IPC_ERROR = 24000010：进程通信错误。<br>     ASSET_BMS_ERROR = 24000011：包管理服务异常。<br>     ASSET_ACCOUNT_ERROR = 24000012：账号系统异常。<br>     ASSET_ACCESS_TOKEN_ERROR = 24000013：访问控制服务异常。<br>     ASSET_LIMIT_EXCEEDED = 24000016：缓存数量超限。<br>     ASSET_UNSUPPORTED = 24000017：该子功能不支持。 |

### OH_Asset_Query()

```
int32_t OH_Asset_Query(const Asset_Attr *query, uint32_t queryCnt, Asset_ResultSet *resultSet)
```

**描述**

查询一条或多条符合条件的关键资产。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [Asset_Attr](capi-assettype-asset-attr.md) *query | 关键资产的查询条件。 |
| uint32_t queryCnt | 关键资产查询条件的个数。 |
| [Asset_ResultSet](capi-assettype-asset-resultset.md) *resultSet | 查询结果列表。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [Asset_ResultCode](capi-asset-type-h.md#asset_resultcode):<br>     ASSET_SUCCESS = 0：操作成功。<br>     ASSET_INVALID_ARGUMENT = 401：参数错误。 可能原因:<br>         1. 参数类型错误。<br>         2. 参数校验失败。<br>     ASSET_SERVICE_UNAVAILABLE = 24000001：关键资产服务不可用。<br>     ASSET_NOT_FOUND = 24000002：未找到关键资产。<br>     ASSET_ACCESS_DENIED = 24000004：拒绝访问关键资产。<br>     ASSET_STATUS_MISMATCH = 24000005：锁屏状态不匹配。<br>     ASSET_OUT_OF_MEMORY = 24000006：系统内存不足。<br>     ASSET_DATA_CORRUPTED = 24000007：关键资产损坏。<br>     ASSET_DATABASE_ERROR = 24000008：数据库操作失败。<br>     ASSET_CRYPTO_ERROR = 24000009：算法库操作失败。<br>     ASSET_IPC_ERROR = 24000010：进程通信错误。<br>     ASSET_BMS_ERROR = 24000011：包管理服务异常。<br>     ASSET_ACCOUNT_ERROR = 24000012：账号系统异常。<br>     ASSET_ACCESS_TOKEN_ERROR = 24000013：访问控制服务异常。<br>     ASSET_UNSUPPORTED = 24000017：该子功能不支持。 |

### OH_Asset_PostQuery()

```
int32_t OH_Asset_PostQuery(const Asset_Attr *handle, uint32_t handleCnt)
```

**描述**

查询的后置处理，用于需要用户认证的关键资产。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [Asset_Attr](capi-assettype-asset-attr.md) *handle | 待处理的查询句柄，当前包含[OH_Asset_PreQuery](#oh_asset_prequery)执行成功返回的挑战值。 |
| uint32_t handleCnt | 句柄属性集合中元素的个数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [Asset_ResultCode](capi-asset-type-h.md#asset_resultcode):<br>     ASSET_SUCCESS = 0：操作成功。<br>     ASSET_INVALID_ARGUMENT = 401：参数错误。 可能原因:<br>         1. 必选参数未指定。<br>         2. 参数类型错误。<br>         3. 参数校验失败。<br>     ASSET_SERVICE_UNAVAILABLE = 24000001：关键资产服务不可用。<br>     ASSET_OUT_OF_MEMORY = 24000006：系统内存不足。<br>     ASSET_IPC_ERROR = 24000010：进程通信错误。<br>     ASSET_BMS_ERROR = 24000011：包管理服务异常。<br>     ASSET_ACCOUNT_ERROR = 24000012：账号系统异常。<br>     ASSET_ACCESS_TOKEN_ERROR = 24000013：访问控制服务异常。 |

### OH_Asset_QuerySyncResult()

```
int32_t OH_Asset_QuerySyncResult(const Asset_Attr *query, uint32_t queryCnt, Asset_SyncResult *syncResult)
```

**描述**

查询关键资产的同步结果。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [Asset_Attr](capi-assettype-asset-attr.md) *query | 关键资产同步结果的查询条件。 |
| uint32_t queryCnt | 关键资产同步结果的查询条件个数。 |
| [Asset_SyncResult](capi-assettype-asset-syncresult.md) *syncResult | 查询到的关键资产同步结果。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [Asset_ResultCode](capi-asset-type-h.md#asset_resultcode)：<br>     ASSET_SUCCESS = 0：操作成功。<br>     ASSET_SERVICE_UNAVAILABLE = 24000001：关键资产服务不可用。<br>     ASSET_OUT_OF_MEMORY = 24000006：系统内存不足。<br>     ASSET_IPC_ERROR = 24000010：进程通信错误。<br>     ASSET_BMS_ERROR = 24000011：包管理服务异常。<br>     ASSET_ACCOUNT_ERROR = 24000012：账号系统异常。<br>     ASSET_ACCESS_TOKEN_ERROR = 24000013：访问控制服务异常。<br>     ASSET_FILE_OPERATION_ERROR = 24000014：文件操作失败。<br>     ASSET_PARAM_VERIFICATION_FAILED = 24000018：参数校验失败。 |

### OH_Asset_ParseAttr()

```
Asset_Attr *OH_Asset_ParseAttr(const Asset_Result *result, Asset_Tag tag)
```

**描述**

解析查询结果，并获取指定的属性值。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [Asset_Result](capi-assettype-asset-result.md) *result | 从[OH_Asset_Query](#oh_asset_query)中获取的查询结果。 |
| [Asset_Tag](capi-asset-type-h.md#asset_tag) tag | 待获取的属性标签。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Asset_Attr](capi-assettype-asset-attr.md) | 如果操作成功，则以Asset_Attr的形式返回属性，该属性不需要业务进行释放；否则返回NULL。 |

### OH_Asset_FreeBlob()

```
void OH_Asset_FreeBlob(Asset_Blob *blob)
```

**描述**

释放挑战值所占用的内存。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Asset_Blob](capi-assettype-asset-blob.md) *blob | 从[OH_Asset_PreQuery](#oh_asset_prequery)获取的挑战值。 |

### OH_Asset_FreeResultSet()

```
void OH_Asset_FreeResultSet(Asset_ResultSet *resultSet)
```

**描述**

释放查询结果所占用的内存。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Asset_ResultSet](capi-assettype-asset-resultset.md) *resultSet | 从[OH_Asset_Query](#oh_asset_query)得到的查询结果列表。 |


