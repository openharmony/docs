# native_avscreen_capture_errors.h


## 概述

声明用于运行屏幕录制过程中接口调用的错误码说明。

**库：** libnative_avscreen_capture.so

**引用文件：** <multimedia/player_framework/native_avscreen_capture_errors.h>

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10

**相关模块：**[AVScreenCapture](_a_v_screen_capture.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef enum [OH_AVSCREEN_CAPTURE_ErrCode](_a_v_screen_capture.md#oh_avscreen_capture_errcode-1) [OH_AVSCREEN_CAPTURE_ErrCode](_a_v_screen_capture.md#oh_avscreen_capture_errcode) | 屏幕录制过程中产生的不同结果码。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AVSCREEN_CAPTURE_ErrCode](_a_v_screen_capture.md#oh_avscreen_capture_errcode-1) {<br/>AV_SCREEN_CAPTURE_ERR_BASE = 0,<br/>AV_SCREEN_CAPTURE_ERR_OK = AV_SCREEN_CAPTURE_ERR_BASE,<br/>AV_SCREEN_CAPTURE_ERR_NO_MEMORY = AV_SCREEN_CAPTURE_ERR_BASE + 1,<br/>AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT = AV_SCREEN_CAPTURE_ERR_BASE + 2,<br/>AV_SCREEN_CAPTURE_ERR_INVALID_VAL = AV_SCREEN_CAPTURE_ERR_BASE + 3,<br/>AV_SCREEN_CAPTURE_ERR_IO = AV_SCREEN_CAPTURE_ERR_BASE + 4,<br/>AV_SCREEN_CAPTURE_ERR_TIMEOUT = AV_SCREEN_CAPTURE_ERR_BASE + 5,<br/>AV_SCREEN_CAPTURE_ERR_UNKNOWN = AV_SCREEN_CAPTURE_ERR_BASE + 6,<br/>AV_SCREEN_CAPTURE_ERR_SERVICE_DIED = AV_SCREEN_CAPTURE_ERR_BASE + 7,<br/>AV_SCREEN_CAPTURE_ERR_INVALID_STATE = AV_SCREEN_CAPTURE_ERR_BASE + 8,<br/>AV_SCREEN_CAPTURE_ERR_UNSUPPORT = AV_SCREEN_CAPTURE_ERR_BASE + 9,<br/>AV_SCREEN_CAPTURE_ERR_EXTEND_START = AV_SCREEN_CAPTURE_ERR_BASE + 100<br/>} | 屏幕录制过程中产生的不同结果码。 | 
