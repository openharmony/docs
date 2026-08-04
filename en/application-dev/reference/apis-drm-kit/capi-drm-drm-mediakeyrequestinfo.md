# DRM_MediaKeyRequestInfo

<!--Kit: Drm Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qin_wei_jie-->
<!--Designer: @chris2981-->
<!--Tester: @xdlinc-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=e85a6f3dbc9e10801a5d673c235723e814e8051f translatedAt=2026-07-31T02:12:14.339Z pushedAt=2026-07-31T03:50:34.435Z -->

```c
typedef struct DRM_MediaKeyRequestInfo {...} DRM_MediaKeyRequestInfo
```

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
| int32_t initDataLen | Length of the initialization data.|
| uint8_t initData[MAX_INIT_DATA_LEN] | Initialization data in PSSH format (Base64-decoded).|
| char mimeType[MAX_MIMETYPE_LEN] | MIME type of the media context. |
| uint32_t optionsCount | Number of options.|
| char optionName[MAX_MEDIA_KEY_REQUEST_OPTION_COUNT][MAX_MEDIA_KEY_REQUEST_OPTION_NAME_LEN] | Array of option names.|
| char optionData[MAX_MEDIA_KEY_REQUEST_OPTION_COUNT][MAX_MEDIA_KEY_REQUEST_OPTION_DATA_LEN] | Array of option values.|