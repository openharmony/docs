# Asset_Value


## Overview

Defines the value of an asset attribute, which is in the form of a key-value (KV) pair.

**Since**: 11

**Related module**: [AssetType](_asset_type.md)


## Summary


### Member Variables

| Name| Description|
| -------- | -------- |
| bool [boolean](#boolean) | Asset attribute value of the Boolean type. |
| uint32_t [u32](#u32) | Asset attribute value of the uint32_t type. |
| [Asset_Blob](_asset___blob.md) [blob](#blob) | Asset attribute value in an array of bytes. |


## Member Variable Description


### blob

```
Asset_Blob Asset_Value::blob
```
**Description**
Represents an asset attribute value in an array of bytes.


### boolean

```
bool Asset_Value::boolean
```
**Description**
Represents an asset attribute value of the Boolean type.


### u32

```
uint32_t Asset_Value::u32
```
**Description**
Represents an asset attribute value of the uint32_t type.
