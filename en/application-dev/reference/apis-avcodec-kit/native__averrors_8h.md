# native_averrors.h


## Overview

The **native_averrors.h** file declares the error codes used by the media system.

**Library**: libnative_media_core.so

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 9

**Related module**: [Core](_core.md)


## Summary


### Types

| Name| Description| 
| -------- | -------- |
| typedef enum [OH_AVErrCode](_core.md#oh_averrcode-1) [OH_AVErrCode](_core.md#oh_averrcode) | Defines an enum for the error codes used by the media system.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [OH_AVErrCode](_core.md#oh_averrcode-1) {<br>AV_ERR_OK = 0,<br>AV_ERR_NO_MEMORY = 1,<br>AV_ERR_OPERATE_NOT_PERMIT = 2,<br>AV_ERR_INVALID_VAL = 3,<br>AV_ERR_IO = 4,<br>AV_ERR_TIMEOUT = 5,<br>AV_ERR_UNKNOWN = 6,<br>AV_ERR_SERVICE_DIED = 7,<br>AV_ERR_INVALID_STATE = 8,<br>AV_ERR_UNSUPPORT = 9, <br>AV_ERR_UNSUPPORTED_FORMAT = 11,<br>AV_ERR_EXTEND_START = 100,<br>AV_ERR_DRM_BASE = 200,<br>AV_ERR_DRM_DECRYPT_FAILED = 201,<br>AV_ERR_VIDEO_BASE = 300,<br>AV_ERR_VIDEO_UNSUPPORTED_COLOR_SPACE_CONVERSION = 301<br>} | Enumerates the error codes used by the media system. |
