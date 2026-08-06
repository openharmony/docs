# DRM_KeysInfo

<!--Kit: Drm Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qin_wei_jie-->
<!--Designer: @chris2981-->
<!--Tester: @xdlinc-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=ecefca9013cc090f0688005ae538b04dd2dd930a translatedAt=2026-07-31T02:12:05.157Z pushedAt=2026-07-31T03:50:36.363Z -->

```c
typedef struct DRM_KeysInfo {...} DRM_KeysInfo
```

## Overview

The struct describes the information about media keys.

**Since**: 11

**Related module**: [Drm](capi-drm.md)

**Header file**: [native_drm_common.h](capi-native-drm-common-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| uint32_t keysInfoCount | Number of keys. |
| uint8_t keyId[MAX_KEY_INFO_COUNT][MAX_KEY_ID_LEN] | Array of key IDs.|
| char statusValue[MAX_KEY_INFO_COUNT][MAX_KEY_STATUS_VALUE_LEN] | Value of the key status attribute.|