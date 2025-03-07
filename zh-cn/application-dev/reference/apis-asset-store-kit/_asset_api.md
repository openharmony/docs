# AssetApi


## 概述

提供用户短敏感数据的安全存储及管理能力，包括新增、删除、更新、查询等。
其中，短敏感数据可以是密码类（账号/密码）、Token类（应用凭据）、其他关键明文（如银行卡号）等长度较短的用户敏感数据。

**系统能力：** SystemCapability.Security.Asset

**起始版本：** 11


## 汇总


### 文件

| 名称 | 描述 |
| -------- | -------- |
| [asset_api.h](asset__api_8h.md) | 声明用于访问关键资产的接口。  |


### 函数

| 名称 | 描述 |
| -------- | -------- |
| int32_t [OH_Asset_Add](#oh_asset_add) (const [Asset_Attr](_asset___attr.md) \*attributes, uint32_t attrCnt) | 新增一条关键资产。 |
| int32_t [OH_Asset_Remove](#oh_asset_remove) (const [Asset_Attr](_asset___attr.md) \*query, uint32_t queryCnt) | 删除符合条件的一条或多条关键资产。  |
| int32_t [OH_Asset_Update](#oh_asset_update) (const [Asset_Attr](_asset___attr.md) \*query, uint32_t queryCnt, const [Asset_Attr](_asset___attr.md) \*attributesToUpdate, uint32_t updateCnt) | 更新符合条件的一条关键资产。  |
| int32_t [OH_Asset_PreQuery](#oh_asset_prequery) (const [Asset_Attr](_asset___attr.md) \*query, uint32_t queryCnt, [Asset_Blob](_asset___blob.md) \*challenge) | 查询的预处理，用于需要用户认证的关键资产。  |
| int32_t [OH_Asset_Query](#oh_asset_query) (const [Asset_Attr](_asset___attr.md) \*query, uint32_t queryCnt, [Asset_ResultSet](_asset___result_set.md) \*resultSet) | 查询一条或多条符合条件的关键资产。  |
| int32_t [OH_Asset_PostQuery](#oh_asset_postquery) (const [Asset_Attr](_asset___attr.md) \*handle, uint32_t handleCnt) | 查询的后置处理，用于需要用户认证的关键资产。  |
| [Asset_Attr](_asset___attr.md) \* [OH_Asset_ParseAttr](#oh_asset_parseattr) (const [Asset_Result](_asset___result.md) \*result, [Asset_Tag](_asset_type.md#asset_tag) tag) | 解析查询结果，并获取指定的属性值。  |
| void [OH_Asset_FreeBlob](#oh_asset_freeblob) ([Asset_Blob](_asset___blob.md) \*blob) | 释放挑战值所占用的内存。  |
| void [OH_Asset_FreeResultSet](#oh_asset_freeresultset) ([Asset_ResultSet](_asset___result_set.md) \*resultSet) | 释放查询结果所占用的内存。  |


## 函数说明


### OH_Asset_Add()

```
int32_t OH_Asset_Add (const Asset_Attr * attributes, uint32_t attrCnt )
```
**描述**
新增一条关键资产。

如果要设置[ASSET_TAG_IS_PERSISTENT](_asset_type.md#asset_tag)属性，需要申请ohos.permission.STORE_PERSISTENT_DATA权限。

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| attributes | 待新增关键资产的属性集合。  |
| attrCnt | 待新增关键资产的属性数量。  |

**返回：**

如果操作成功，则返回[ASSET_SUCCESS](_asset_type.md#asset_resultcode)；否则返回错误码。

0 - 表示操作成功。

201 - 表示调用者没有权限。

401 - 表示参数错误。

24000001 - 表示关键资产服务不可用。

24000003 - 表示关键资产已存在。

24000005 - 表示锁屏状态不匹配。

24000006 - 表示系统内存不足。

24000007 - 表示关键资产损坏。

24000008 - 表示数据库操作失败。

24000009 - 表示算法库操作失败。

24000010 - 表示进程通信错误。

24000011 - 表示包管理服务异常。

24000012 - 表示账号系统异常。

24000013 - 表示访问控制服务异常。

24000014 - 表示文件操作失败。

24000015 - 表示获取系统时间失败。


### OH_Asset_FreeBlob()

```
void OH_Asset_FreeBlob (Asset_Blob * blob)
```
**描述**
释放挑战值所占用的内存。

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| blob | 从OH_Asset_PreQuery获取的挑战值。  |


### OH_Asset_FreeResultSet()

```
void OH_Asset_FreeResultSet (Asset_ResultSet * resultSet)
```
**描述**
释放查询结果所占用的内存。

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| resultSet | 从OH_Asset_Query得到的查询结果列表。  |


### OH_Asset_ParseAttr()

```
Asset_Attr* OH_Asset_ParseAttr (const Asset_Result * result, Asset_Tag tag )
```
**描述**
解析查询结果，并获取指定的属性值。

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| result | 从OH_Asset_Query中获取的查询结果。  |
| tag | 待获取的属性标签。  |

**返回：**

如果操作成功，则以Asset_Attr的形式返回属性，该属性不需要业务进行释放；否则返回NULL。


### OH_Asset_PostQuery()

```
int32_t OH_Asset_PostQuery (const Asset_Attr * handle, uint32_t handleCnt )
```
**描述**
查询的后置处理，用于需要用户认证的关键资产。

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| handle | 待处理的查询句柄，当前包含OH_Asset_PreQuery执行成功返回的挑战值。  |
| handleCnt | 句柄属性集合中元素的个数。  |

**返回：**

如果操作成功，则返回[ASSET_SUCCESS](_asset_type.md#asset_resultcode)；否则返回错误码。

0 - 表示操作成功。

401 - 表示参数错误。

24000001 - 表示关键资产服务不可用。

24000006 - 表示系统内存不足。

24000010 - 表示进程通信错误。

24000011 - 表示包管理服务异常。

24000012 - 表示账号系统异常。

24000013 - 表示访问控制服务异常。

### OH_Asset_PreQuery()

```
int32_t OH_Asset_PreQuery (const Asset_Attr * query, uint32_t queryCnt, Asset_Blob * challenge )
```
**描述**
查询的预处理，用于需要用户认证的关键资产。

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| query | 关键资产的查询条件。  |
| queryCnt | 关键资产查询条件的个数。  |
| challenge | 挑战值，在后续调用OH_Asset_Query时使用。  |

**返回：**

如果操作成功，则返回[ASSET_SUCCESS](_asset_type.md#asset_resultcode)；否则返回错误码。

0 - 表示操作成功。

401 - 表示参数错误。

24000001 - 表示关键资产服务不可用。

24000002 - 表示未找到关键资产。

24000005 - 表示锁屏状态不匹配。

24000006 - 表示系统内存不足。

24000007 - 表示关键资产损坏。

24000008 - 表示数据库操作失败。

24000009 - 表示算法库操作失败。

24000010 - 表示进程通信错误。

24000011 - 表示包管理服务异常。

24000012 - 表示账号系统异常。

24000013 - 表示访问控制服务异常。

24000016 - 表示缓存数量超限。

24000017 - 表示该子功能不支持。

### OH_Asset_Query()

```
int32_t OH_Asset_Query (const Asset_Attr * query, uint32_t queryCnt, Asset_ResultSet * resultSet )
```
**描述**
查询一条或多条符合条件的关键资产。

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| query | 关键资产的查询条件。  |
| queryCnt | 关键资产查询条件的个数。  |
| resultSet | 查询结果列表。  |

**返回：**

如果操作成功，则返回[ASSET_SUCCESS](_asset_type.md#asset_resultcode)；否则返回错误码。

0 - 表示操作成功。

401 - 表示参数错误。

24000001 - 表示关键资产服务不可用。

24000002 - 表示未找到关键资产。

24000004 - 表示拒绝访问关键资产。

24000005 - 表示锁屏状态不匹配。

24000006 - 表示系统内存不足。

24000007 - 表示关键资产损坏。

24000008 - 表示数据库操作失败。

24000009 - 表示算法库操作失败。

24000010 - 表示进程通信错误。

24000011 - 表示包管理服务异常。

24000012 - 表示账号系统异常。

24000013 - 表示访问控制服务异常。

24000017 - 表示该子功能不支持。

### OH_Asset_Remove()

```
int32_t OH_Asset_Remove (const Asset_Attr * query, uint32_t queryCnt )
```
**描述**
删除符合条件的一条或多条关键资产。

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| query | 待删除关键资产的搜索条件。  |
| queryCnt | 待删除关键资产搜索条件的个数。  |

**返回：**

如果操作成功，则返回[ASSET_SUCCESS](_asset_type.md#asset_resultcode)；否则返回错误码。

0 - 表示操作成功。

401 - 表示参数错误。

24000001 - 表示关键资产服务不可用。

24000002 - 表示未找到关键资产。

24000006 - 表示系统内存不足。

24000007 - 表示关键资产损坏。

24000008 - 表示数据库操作失败。

24000010 - 表示进程通信错误。

24000011 - 表示包管理服务异常。

24000012 - 表示账号系统异常。

24000013 - 表示访问控制服务异常。

24000015 - 表示获取系统时间失败。

### OH_Asset_Update()

```
int32_t OH_Asset_Update (const Asset_Attr * query, uint32_t queryCnt, const Asset_Attr * attributesToUpdate, uint32_t updateCnt )
```
**描述**
更新符合条件的一条关键资产。

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| query | 待更新关键资产的搜索条件。  |
| queryCnt | 待更新关键资产搜索条件的个数。  |
| attributesToUpdate | 待更新关键资产的属性集合。  |
| updateCnt | 待更新关键资产的属性数量。  |

**返回：**

如果操作成功，则返回[ASSET_SUCCESS](_asset_type.md#asset_resultcode)；否则返回错误码。

0 - 表示操作成功。

401 - 表示参数错误。

24000001 - 表示关键资产服务不可用。

24000002 - 表示未找到关键资产。

24000005 - 表示锁屏状态不匹配。

24000006 - 表示系统内存不足。

24000007 - 表示关键资产损坏。

24000008 - 表示数据库操作失败。

24000009 - 表示算法库操作失败。

24000010 - 表示进程通信错误。

24000011 - 表示包管理服务异常。

24000012 - 表示账号系统异常。

24000013 - 表示访问控制服务异常。

24000015 - 表示获取系统时间失败。
