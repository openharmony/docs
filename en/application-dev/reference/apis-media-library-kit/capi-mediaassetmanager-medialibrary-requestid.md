# MediaLibrary_RequestId

## Overview

The struct describes a request ID.

A value of this type is returned when a media asset is requested.

The request ID can be used to cancel a request.

If a request fails, an all-zero value, for example, **00000000-0000-0000-0000-000000000000** is returned.

**Since**: 12

**Related module**: [MediaAssetManager](capi-mediaassetmanager.md)

**Header file**: [media_asset_base_capi.h](capi-media-asset-base-capi-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| char requestId[UUID_STR_MAX_LENGTH] | Request ID.|
