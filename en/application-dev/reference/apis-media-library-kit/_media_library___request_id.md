# MediaLibrary_RequestId


## Overview

Defines a request ID.

A value of this type is returned when a media asset is requested. The request ID can be used to cancel a request. If a request fails, an all-zero value, for example, **00000000-0000-0000-0000-000000000000** is returned.

**Since**: 12

**Related module**: [MediaAssetManager](_media_asset_manager.md)


## Summary


### Member Variables

| Name| **Describe**:|
| -------- | -------- |
| char [requestId](_media_asset_manager.md#requestid) [UUID_STR_MAX_LENGTH] | Maximum length of a UUID.|
