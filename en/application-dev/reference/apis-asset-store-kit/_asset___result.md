# Asset_Result


## Overview

Defines the query result of an asset.

**Since**: 11

**Related module**: [AssetType](_asset_type.md)


## Summary


### Member Variables

| Name| Description|
| -------- | -------- |
| uint32_t [count](#count) | Number of asset attributes in the query result. |
| [Asset_Attr](_asset___attr.md) \* [attrs](#attrs) | Pointer to the array of the asset attributes. |


## Member Variable Description


### attrs

```
Asset_Attr* Asset_Result::attrs
```
**Description**
Indicates the pointer to the array of the asset attributes.


### count

```
uint32_t Asset_Result::count
```
**Description**
Indicates the number of asset attributes in the query result.
