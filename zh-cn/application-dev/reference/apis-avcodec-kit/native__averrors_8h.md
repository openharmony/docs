# native_averrors.h


## 概述

媒体框架错误码。

**库：** libnative_media_core.so

**系统能力：** SystemCapability.Multimedia.Media.Core

**起始版本：** 9

**相关模块：**[Core](_core.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef enum [OH_AVErrCode](_core.md#oh_averrcode-1) [OH_AVErrCode](_core.md#oh_averrcode) | 媒体框架错误码。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AVErrCode](_core.md#oh_averrcode-1) {<br/>AV_ERR_OK = 0,<br/>AV_ERR_NO_MEMORY = 1,<br/>AV_ERR_OPERATE_NOT_PERMIT = 2,<br/>AV_ERR_INVALID_VAL = 3,<br/>AV_ERR_IO = 4,<br/>AV_ERR_TIMEOUT = 5,<br/>AV_ERR_UNKNOWN = 6,<br/>AV_ERR_SERVICE_DIED = 7,<br/>AV_ERR_INVALID_STATE = 8,<br/>AV_ERR_UNSUPPORT = 9,<br/>AV_ERR_EXTEND_START = 100,<br/> AV_ERR_DRM_BASE = 200,<br/>AV_ERR_DRM_DECRYPT_FAILED = 201,<br/>AV_ERR_VIDEO_BASE = 300,<br/>AV_ERR_VIDEO_UNSUPPORTED_COLOR_SPACE_CONVERSION = 301<br/>} | 媒体框架错误码。  |
