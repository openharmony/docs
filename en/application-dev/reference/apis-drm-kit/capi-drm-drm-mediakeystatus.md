# DRM_MediaKeyStatus

## Overview

The struct describes the media key status.

**Since**: 11

**Related module**: [Drm](capi-drm.md)

**Header file**: [native_drm_common.h](capi-native-drm-common-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| uint32_t statusCount | Number of media key statuses.|
| char statusName[MAX_MEDIA_KEY_STATUS_COUNT][MAX_MEDIA_KEY_STATUS_NAME_LEN] | Array of status names.|
| char statusValue[MAX_MEDIA_KEY_STATUS_COUNT][MAX_MEDIA_KEY_STATUS_VALUE_LEN] | Array of status values.|
