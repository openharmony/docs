# native_drm_err.h

## Overview

The file declares the DRM error codes.

**File to include**: <multimedia/drm_framework/native_drm_err.h>

**Library**: libnative_drm.z.so

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

```
enum Drm_ErrCode
```

**Description**

Enumerates the DRM error codes.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Since**: 11

| Enum Item| Description|
| -- | -- |
| DRM_ERR_OK = 0 | Operation successful.|
| DRM_CAPI_ERR_BASE = 24700500 | Basic error.|
| DRM_ERR_NO_MEMORY = DRM_CAPI_ERR_BASE + 1 | Insufficient memory.|
| DRM_ERR_OPERATION_NOT_PERMITTED = DRM_CAPI_ERR_BASE + 2 | Unsupported operation.|
| DRM_ERR_INVALID_VAL = DRM_CAPI_ERR_BASE + 3 | Invalid parameter.|
| DRM_ERR_IO = DRM_CAPI_ERR_BASE + 4 | I/O error.|
| DRM_ERR_TIMEOUT = DRM_CAPI_ERR_BASE + 5 | Network timeout.|
| DRM_ERR_UNKNOWN = DRM_CAPI_ERR_BASE + 6 | Unknown error.|
| DRM_ERR_SERVICE_DIED = DRM_CAPI_ERR_BASE + 7 | DRM service error.|
| DRM_ERR_INVALID_STATE = DRM_CAPI_ERR_BASE + 8 | Invalid operation status.|
| DRM_ERR_UNSUPPORTED = DRM_CAPI_ERR_BASE + 9 | Unsupported operation.|
| DRM_ERR_MAX_SYSTEM_NUM_REACHED = DRM_CAPI_ERR_BASE + 10 | Too many MediaKeySystem instances.|
| DRM_ERR_MAX_SESSION_NUM_REACHED = DRM_CAPI_ERR_BASE + 11 | Too many MediaKeySession instances.|
| DRM_ERR_EXTEND_START  = DRM_CAPI_ERR_BASE + 100 | Extended error.|
