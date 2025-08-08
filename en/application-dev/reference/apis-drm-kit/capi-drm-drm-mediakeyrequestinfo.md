# DRM_MediaKeyRequestInfo

## Overview

The struct describes the information about a media key request.

**Since**: 11

**Related module**: [Drm](capi-drm.md)

**Header file**: [native_drm_common.h](capi-native-drm-common-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| [DRM_MediaKeyType](capi-native-drm-common-h.md#drm_mediakeytype) type | Key type.|
| int32_t initDataLen | Initial data length.|
| uint8_t initData[MAX_INIT_DATA_LEN] | Initial data in PSSH format after Base64 decoding.|
| char mimeType[MAX_MIMETYPE_LEN] | MIME type of the media context.|
| uint32_t optionsCount | Number of options.|
| char optionName[MAX_MEDIA_KEY_REQUEST_OPTION_COUNT][MAX_MEDIA_KEY_REQUEST_OPTION_NAME_LEN] | Option name set.|
| char optionData[MAX_MEDIA_KEY_REQUEST_OPTION_COUNT][MAX_MEDIA_KEY_REQUEST_OPTION_DATA_LEN] | Option data set.|
