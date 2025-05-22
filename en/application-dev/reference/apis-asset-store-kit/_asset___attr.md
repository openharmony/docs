# Asset_Attr


## Overview

Defines an asset attribute, which consists of a tag and a value in the form of a key-value (KV) pair.

**Since**: 11

**Related module**: [AssetType](_asset_type.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| uint32_t [tag](#tag) | Name of the asset attribute. The tag (the key in the KV pair) uniquely identifies an attribute. | 
| [Asset_Value](union_asset___value.md) [value](#value) | Value of the asset attribute. | 


## Member Variable Description


### tag

```
uint32_t Asset_Attr::tag
```
**Description**
Defines the name of the asset attribute.


### value

```
Asset_Value Asset_Attr::value
```
**Description**
Defines the value of the asset attribute
