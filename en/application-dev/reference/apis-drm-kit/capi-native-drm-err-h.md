# native_drm_err.h

<!--Kit: Drm Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qin_wei_jie-->
<!--Designer: @chris2981-->
<!--Tester: @xdlinc-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=e85a6f3dbc9e10801a5d673c235723e814e8051f translatedAt=2026-07-31T02:12:58.536Z pushedAt=2026-07-31T03:52:43.310Z -->

## Overview

The file declares the DRM error codes.

**File to include**: <multimedia/drm_framework/native_drm_err.h>

**Library**: libnative_drm.so

**System capability**: SystemCapability.Multimedia.Drm.Core

**Since**: 11

**Related module**: [Drm](capi-drm.md)

## Summary

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [Drm_ErrCode](#drm_errcode) | Drm_ErrCode | Enumerates the DRM error codes.|

## Enum Description

### Drm_ErrCode

```c
enum Drm_ErrCode
```

**Description**

Enumerates the DRM error codes.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Since**: 11

| Enum Item| Description|
| -- | -- |
| DRM_ERR_OK = 0 | Operation successful.|
| DRM_CAPI_ERR_BASE = 24700500 | Base error code.|
| DRM_ERR_NO_MEMORY = DRM_CAPI_ERR_BASE + 1 | Insufficient memory.|
| DRM_ERR_OPERATION_NOT_PERMITTED = DRM_CAPI_ERR_BASE + 2 | Operation not permitted.|
| DRM_ERR_INVALID_VAL = DRM_CAPI_ERR_BASE + 3 | Invalid parameter.|
| DRM_ERR_IO = DRM_CAPI_ERR_BASE + 4 | I/O error.|
| DRM_ERR_TIMEOUT = DRM_CAPI_ERR_BASE + 5 | Network timeout.|
| DRM_ERR_UNKNOWN = DRM_CAPI_ERR_BASE + 6 | Unknown error.|
| DRM_ERR_SERVICE_DIED = DRM_CAPI_ERR_BASE + 7 | The DRM service died. |
| DRM_ERR_INVALID_STATE = DRM_CAPI_ERR_BASE + 8 | Invalid operation state.|
| DRM_ERR_UNSUPPORTED = DRM_CAPI_ERR_BASE + 9 | Unsupported operation.|
| DRM_ERR_MAX_SYSTEM_NUM_REACHED = DRM_CAPI_ERR_BASE + 10 | Too many MediaKeySystem instances.|
| DRM_ERR_MAX_SESSION_NUM_REACHED = DRM_CAPI_ERR_BASE + 11 | Too many MediaKeySession instances.|
| DRM_ERR_EXTEND_START  = DRM_CAPI_ERR_BASE + 100 | Extended error.|