# DRM_OfflineMediakeyIdArray

## Overview

The struct describes an array holding the IDs of offline media keys.

**Since**: 11

**Related module**: [Drm](capi-drm.md)

**Header file**: [native_drm_common.h](capi-native-drm-common-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| uint32_t idsCount | Number of IDs.|
| int32_t idsLen[MAX_OFFLINE_MEDIA_KEY_ID_COUNT] | ID length set.|
| uint8_t ids[MAX_OFFLINE_MEDIA_KEY_ID_COUNT][MAX_OFFLINE_MEDIA_KEY_ID_LEN] | ID data set.|
