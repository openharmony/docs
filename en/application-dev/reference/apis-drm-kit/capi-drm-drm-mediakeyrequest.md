# DRM_MediaKeyRequest

## Overview

The struct describes a media key request.

**Since**: 11

**Related module**: [Drm](capi-drm.md)

**Header file**: [native_drm_common.h](capi-native-drm-common-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| [DRM_MediaKeyRequestType](capi-native-drm-common-h.md#drm_mediakeyrequesttype) type | Type of a media key request.|
| int32_t dataLen | Length of data in a media key request.|
| uint8_t data[MAX_MEDIA_KEY_REQUEST_DATA_LEN] | Data in a media key request sent to the media key server.|
| char defaultUrl[MAX_DEFAULT_URL_LEN] | URL of a media key server.|
