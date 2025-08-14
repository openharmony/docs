# Asset_Attr

## Overview

Defines an asset attribute, which consists of a tag and a value in the form of a key-value (KV) pair.

**Since**: 11

**Related module**: [AssetType](capi-assettype.md)

**Header file:** [asset_type.h](capi-asset-type-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| uint32_t tag | Name of the asset attribute. The tag (the key in the KV pair) uniquely identifies an attribute.|
| [Asset_Value](capi-assettype-asset-value.md) value | Defines the value of the asset attribute.|
