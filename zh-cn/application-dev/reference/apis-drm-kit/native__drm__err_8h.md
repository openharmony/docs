# native_drm_err.h


## 概述

定义DRM错误码。

**库：** libnative_drm.so

**引用文件：** &lt;multimedia/drm_framework/native_drm_err.h&gt;

**系统能力：** SystemCapability.Multimedia.Drm.Core

**起始版本：** 11

**相关模块：**[Drm](_drm.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef enum [Drm_ErrCode](_drm.md#drm_errcode) [Drm_ErrCode](_drm.md#drm_errcode) | DRM错误码。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [Drm_ErrCode](_drm.md#drm_errcode-1) {<br/>DRM_ERR_OK = 0, <br/>DRM_CAPI_ERR_BASE = 24700500, <br/>DRM_ERR_NO_MEMORY = DRM_CAPI_ERR_BASE + 1, <br/>DRM_ERR_OPERATION_NOT_PERMITTED = DRM_CAPI_ERR_BASE + 2,<br/>DRM_ERR_INVALID_VAL = DRM_CAPI_ERR_BASE + 3, <br/>DRM_ERR_IO = DRM_CAPI_ERR_BASE + 4, <br/>DRM_ERR_TIMEOUT = DRM_CAPI_ERR_BASE + 5, <br/>DRM_ERR_UNKNOWN = DRM_CAPI_ERR_BASE + 6,<br/>DRM_ERR_SERVICE_DIED = DRM_CAPI_ERR_BASE + 7, <br/>DRM_ERR_INVALID_STATE = DRM_CAPI_ERR_BASE + 8, <br/>DRM_ERR_UNSUPPORTED = DRM_CAPI_ERR_BASE + 9, <br/>DRM_ERR_MAX_SYSTEM_NUM_REACHED = DRM_CAPI_ERR_BASE + 10,<br/>DRM_ERR_MAX_SESSION_NUM_REACHED = DRM_CAPI_ERR_BASE + 11, <br/>DRM_ERR_EXTEND_START = DRM_CAPI_ERR_BASE + 100<br/>} | DRM错误码。 | 
