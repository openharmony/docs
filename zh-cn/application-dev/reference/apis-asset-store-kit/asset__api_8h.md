# asset_api.h


## 概述

声明用于访问关键资产的接口。

**库：** libasset_ndk.z.so

**系统能力：** SystemCapability.Security.Asset

**起始版本：** 11

**相关模块：**[AssetApi](_asset_api.md)


## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| int32_t [OH_Asset_Add](_asset_api.md#oh_asset_add) (const [Asset_Attr](_asset___attr.md) \*attributes, uint32_t attrCnt) | 新增一条关键资产。 | 
| int32_t [OH_Asset_Remove](_asset_api.md#oh_asset_remove) (const [Asset_Attr](_asset___attr.md) \*query, uint32_t queryCnt) | 删除符合条件的一条或多条关键资产。 | 
| int32_t [OH_Asset_Update](_asset_api.md#oh_asset_update) (const [Asset_Attr](_asset___attr.md) \*query, uint32_t queryCnt, const [Asset_Attr](_asset___attr.md) \*attributesToUpdate, uint32_t updateCnt) | 更新符合条件的一条关键资产。 | 
| int32_t [OH_Asset_PreQuery](_asset_api.md#oh_asset_prequery) (const [Asset_Attr](_asset___attr.md) \*query, uint32_t queryCnt, [Asset_Blob](_asset___blob.md) \*challenge) | 查询的预处理，用于需要用户认证的关键资产。 | 
| int32_t [OH_Asset_Query](_asset_api.md#oh_asset_query) (const [Asset_Attr](_asset___attr.md) \*query, uint32_t queryCnt, [Asset_ResultSet](_asset___result_set.md) \*resultSet) | 查询一条或多条符合条件的关键资产。 | 
| int32_t [OH_Asset_PostQuery](_asset_api.md#oh_asset_postquery) (const [Asset_Attr](_asset___attr.md) \*handle, uint32_t handleCnt) | 查询的后置处理，用于需要用户认证的关键资产。 | 
| [Asset_Attr](_asset___attr.md) \* [OH_Asset_ParseAttr](_asset_api.md#oh_asset_parseattr) (const [Asset_Result](_asset___result.md) \*result, [Asset_Tag](_asset_type.md#asset_tag) tag) | 解析查询结果，并获取指定的属性值。 | 
| void [OH_Asset_FreeBlob](_asset_api.md#oh_asset_freeblob) ([Asset_Blob](_asset___blob.md) \*blob) | 释放挑战值所占用的内存。 | 
| void [OH_Asset_FreeResultSet](_asset_api.md#oh_asset_freeresultset) ([Asset_ResultSet](_asset___result_set.md) \*resultSet) | 释放查询结果所占用的内存。 | 
