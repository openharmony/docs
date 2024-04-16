# native_avscreen_capture_errors.h


## Overview

The **native_avscreen_capture_errors.h** file declares the error codes generated during screen capture.

**Library**: libnative_avscreen_capture.so

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10

**Related module**: [AVScreenCapture](_a_v_screen_capture.md)


## Summary


### Types

| Name| Description| 
| -------- | -------- |
| typedef enum [OH_AVSCREEN_CAPTURE_ErrCode](_a_v_screen_capture.md#oh_avscreen_capture_errcode-1) [OH_AVSCREEN_CAPTURE_ErrCode](_a_v_screen_capture.md#oh_avscreen_capture_errcode) | Defines an enum for error codes generated during screen capture.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [OH_AVSCREEN_CAPTURE_ErrCode](_a_v_screen_capture.md#oh_avscreen_capture_errcode-1) {<br>AV_SCREEN_CAPTURE_ERR_BASE = 0,<br>AV_SCREEN_CAPTURE_ERR_OK = AV_SCREEN_CAPTURE_ERR_BASE,<br>AV_SCREEN_CAPTURE_ERR_NO_MEMORY = AV_SCREEN_CAPTURE_ERR_BASE + 1,<br>AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT = AV_SCREEN_CAPTURE_ERR_BASE + 2,<br>AV_SCREEN_CAPTURE_ERR_INVALID_VAL = AV_SCREEN_CAPTURE_ERR_BASE + 3,<br>AV_SCREEN_CAPTURE_ERR_IO = AV_SCREEN_CAPTURE_ERR_BASE + 4,<br>AV_SCREEN_CAPTURE_ERR_TIMEOUT = AV_SCREEN_CAPTURE_ERR_BASE + 5,<br>AV_SCREEN_CAPTURE_ERR_UNKNOWN = AV_SCREEN_CAPTURE_ERR_BASE + 6,<br>AV_SCREEN_CAPTURE_ERR_SERVICE_DIED = AV_SCREEN_CAPTURE_ERR_BASE + 7,<br>AV_SCREEN_CAPTURE_ERR_INVALID_STATE = AV_SCREEN_CAPTURE_ERR_BASE + 8,<br>AV_SCREEN_CAPTURE_ERR_UNSUPPORT = AV_SCREEN_CAPTURE_ERR_BASE + 9,<br>AV_SCREEN_CAPTURE_ERR_EXTEND_START = AV_SCREEN_CAPTURE_ERR_BASE + 100<br>} | Enumerates the error codes generated during screen capture.| 
