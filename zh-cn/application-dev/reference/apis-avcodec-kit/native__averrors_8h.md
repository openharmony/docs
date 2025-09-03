# native_averrors.h
<!--Kit: AVCodec Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @xushubo; @chennotfound-->
<!--Designer: @dongyu_dy-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->


## 概述

媒体系统错误码。

**库：** libnative_media_core.so

**引用文件：** <multimedia/player_framework/native_averrors.h>

**系统能力：** SystemCapability.Multimedia.Media.Core

**起始版本：** 9

**相关模块：**[Core](_core.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef enum [OH_AVErrCode](_core.md#oh_averrcode-1) [OH_AVErrCode](_core.md#oh_averrcode) | 媒体系统错误码。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AVErrCode](_core.md#oh_averrcode-1) {<br/>AV_ERR_OK = 0,<br/>AV_ERR_NO_MEMORY = 1,<br/>AV_ERR_OPERATE_NOT_PERMIT = 2,<br/>AV_ERR_INVALID_VAL = 3,<br/>AV_ERR_IO = 4,<br/>AV_ERR_TIMEOUT = 5,<br/>AV_ERR_UNKNOWN = 6,<br/>AV_ERR_SERVICE_DIED = 7,<br/>AV_ERR_INVALID_STATE = 8,<br/>AV_ERR_UNSUPPORT = 9, <br/>AV_ERR_UNSUPPORTED_FORMAT = 11,<br/>AV_ERR_EXTEND_START = 100,<br/>AV_ERR_DRM_BASE = 200,<br/>AV_ERR_DRM_DECRYPT_FAILED = 201,<br/>AV_ERR_VIDEO_BASE = 300,<br/>AV_ERR_VIDEO_UNSUPPORTED_COLOR_SPACE_CONVERSION = 301,<br/>AV_ERR_IO_CANNOT_FIND_HOST = 5411001,<br/>AV_ERR_IO_CONNECTION_TIMEOUT = 5411002,<br/>AV_ERR_IO_NETWORK_ABNORMAL = 5411003,<br/>AV_ERR_IO_NETWORK_UNAVAILABLE = 5411004,<br/>AV_ERR_IO_NO_PERMISSION = 5411005,<br/>AV_ERR_IO_NETWORK_ACCESS_DENIED = 5411006,<br/>AV_ERR_IO_RESOURCE_NOT_FOUND = 5411007,<br/>AV_ERR_IO_SSL_CLIENT_CERT_NEEDED = 5411008,<br/>AV_ERR_IO_SSL_CONNECT_FAIL = 5411009,<br/>AV_ERR_IO_SSL_SERVER_CERT_UNTRUSTED = 5411010,<br/>AV_ERR_IO_UNSUPPORTED_REQUEST = 5411011,<br/>AV_ERR_STREAM_CHANGED = 5410005,<br/>AV_ERR_TRY_AGAIN_LATER  = 5410006<br/>} | 媒体系统错误码。  |