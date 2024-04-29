# asset_api.h


## Overview

Defines the functions for accessing assets.

**Library**: libasset_ndk.z.so

**System capability**: SystemCapability.Security.Asset

**Since**: 11

**Related module**: [AssetApi](_asset_api.md)


## Summary


### Functions

| Name| Description|
| -------- | -------- |
| int32_t [OH_Asset_Add](_asset_api.md#oh_asset_add) (const [Asset_Attr](_asset___attr.md) \*attributes, uint32_t attrCnt) | Adds an asset.|
| int32_t [OH_Asset_Remove](_asset_api.md#oh_asset_remove) (const [Asset_Attr](_asset___attr.md) \*query, uint32_t queryCnt) | Removes one or more assets.|
| int32_t [OH_Asset_Update](_asset_api.md#oh_asset_update) (const [Asset_Attr](_asset___attr.md) \*query, uint32_t queryCnt, const [Asset_Attr](_asset___attr.md) \*attributesToUpdate, uint32_t updateCnt) | Updates an asset.|
| int32_t [OH_Asset_PreQuery](_asset_api.md#oh_asset_prequery) (const [Asset_Attr](_asset___attr.md) \*query, uint32_t queryCnt, [Asset_Blob](_asset___blob.md) \*challenge) | Performs preprocessing for the asset query. This function is used when user authentication is required for the access to the asset.|
| int32_t [OH_Asset_Query](_asset_api.md#oh_asset_query) (const [Asset_Attr](_asset___attr.md) \*query, uint32_t queryCnt, [Asset_ResultSet](_asset___result_set.md) \*resultSet) | Queries one or more assets.|
| int32_t [OH_Asset_PostQuery](_asset_api.md#oh_asset_postquery) (const [Asset_Attr](_asset___attr.md) \*handle, uint32_t handleCnt) | Performs postprocessing for the asset query. This function is used when user authentication is required for the access to the asset.|
| [Asset_Attr](_asset___attr.md) \* [OH_Asset_ParseAttr](_asset_api.md#oh_asset_parseattr) (const [Asset_Result](_asset___result.md) \*result, [Asset_Tag](_asset_type.md#asset_tag) tag) | Parses the query result and obtains the specified attribute. |
| void [OH_Asset_FreeBlob](_asset_api.md#oh_asset_freeblob) ([Asset_Blob](_asset___blob.md) \*blob) | Releases the memory occupied by the challenge value.|
| void [OH_Asset_FreeResultSet](_asset_api.md#oh_asset_freeresultset) ([Asset_ResultSet](_asset___result_set.md) \*resultSet) | Releases the memory occupied by the query result.|
