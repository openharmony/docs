# native_drm_err.h


## Overview

The **native_drm_err.h** file declares the DRM error codes.

**Library**: libnative_drm.so

**File to include**: &lt;multimedia/drm_framework/native_drm_err.h&gt;

**System capability**: SystemCapability.Multimedia.Drm.Core

**Since**: 11

**Related module**: [Drm](_drm.md)


## Summary


### Types

| Name| Description| 
| -------- | -------- |
| typedef enum [Drm_ErrCode](_drm.md#drm_errcode) [Drm_ErrCode](_drm.md#drm_errcode) | Defines an enum for the DRM error codes.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [Drm_ErrCode](_drm.md#drm_errcode-1) {<br>DRM_ERR_OK = 0, <br>DRM_CAPI_ERR_BASE = 24700500, <br>DRM_ERR_NO_MEMORY = DRM_CAPI_ERR_BASE + 1, <br>DRM_ERR_OPERATION_NOT_PERMITTED = DRM_CAPI_ERR_BASE + 2,<br>DRM_ERR_INVALID_VAL = DRM_CAPI_ERR_BASE + 3, <br>DRM_ERR_IO = DRM_CAPI_ERR_BASE + 4, <br>DRM_ERR_TIMEOUT = DRM_CAPI_ERR_BASE + 5, <br>DRM_ERR_UNKNOWN = DRM_CAPI_ERR_BASE + 6,<br>DRM_ERR_SERVICE_DIED = DRM_CAPI_ERR_BASE + 7, <br>DRM_ERR_INVALID_STATE = DRM_CAPI_ERR_BASE + 8, <br>DRM_ERR_UNSUPPORTED = DRM_CAPI_ERR_BASE + 9, <br>DRM_ERR_MAX_SYSTEM_NUM_REACHED = DRM_CAPI_ERR_BASE + 10,<br>DRM_ERR_MAX_SESSION_NUM_REACHED = DRM_CAPI_ERR_BASE + 11, <br>DRM_ERR_EXTEND_START = DRM_CAPI_ERR_BASE + 100<br>} | Enumerates the DRM error codes.| 
