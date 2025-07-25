# Asset_ResultSet


## Overview

Defines the query result of multiple assets.

**Since**: 11

**Related module**: [AssetType](_asset_type.md)

**Header file**: [asset_type.h](asset__type_8h.md)

## Summary


### Member Variables

| Name| Description|
| -------- | -------- |
| uint32_t [count](#count) | Number of assets in the query result. |
| [Asset_Result](_asset___result.md) \* [results](#results) | Pointer to the array of assets. |


## Member Variable Description


### count

```
uint32_t Asset_ResultSet::count
```
**Description**
Indicates the number of assets in the query result.


### results

```
Asset_Result* Asset_ResultSet::results
```
**Description**
Indicates the pointer to the array of assets.
