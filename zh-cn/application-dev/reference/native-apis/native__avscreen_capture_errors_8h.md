# native_avscreen_capture_errors.h

## 概述

声明运行屏幕录制过程中调用接口发生的错误码。

\@syscap SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：**

10

**相关模块：**

[AVScreenCapture](_a_v_screen_capture.md)

## 汇总

### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode) | 屏幕录制错误码。 | 

### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode) {<br/>**AV_SCREEN_CAPTURE_ERR_BASE** = 0, **AV_SCREEN_CAPTURE_ERR_OK** = **AV_SCREEN_CAPTURE_ERR_BASE**, **AV_SCREEN_CAPTURE_ERR_NO_MEMORY** = **AV_SCREEN_CAPTURE_ERR_BASE** + 1, **AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT** = **AV_SCREEN_CAPTURE_ERR_BASE** + 2, **AV_SCREEN_CAPTURE_ERR_INVALID_VAL** = **AV_SCREEN_CAPTURE_ERR_BASE** + 3, **AV_SCREEN_CAPTURE_ERR_IO** = **AV_SCREEN_CAPTURE_ERR_BASE** + 4, **AV_SCREEN_CAPTURE_ERR_TIMEOUT** = **AV_SCREEN_CAPTURE_ERR_BASE** + 5， **AV_SCREEN_CAPTURE_ERR_UNKNOWN** = **AV_SCREEN_CAPTURE_ERR_BASE** + 6, **AV_SCREEN_CAPTURE_ERR_SERVICE_DIED** = **AV_SCREEN_CAPTURE_ERR_BASE** + 7, **AV_SCREEN_CAPTURE_ERR_INVALID_STATE** = **AV_SCREEN_CAPTURE_ERR_BASE** + 8, **AV_SCREEN_CAPTURE_ERR_UNSUPPORT** = **AV_SCREEN_CAPTURE_ERR_BASE** + 9, **AV_SCREEN_CAPTURE_ERR_EXTEND_START** = **AV_SCREEN_CAPTURE_ERR_BASE** + 100<br/>} | 屏幕录制进行过程中产生的不同错误码类型。 |


## 类型定义说明


### OH_AVSCREEN_CAPTURE_ErrCode

  
```
typedef enum OH_AVSCREEN_CAPTURE_ErrCode OH_AVSCREEN_CAPTURE_ErrCode
```

**描述：**

屏幕录制错误码。

\@syscap SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：**

10


## 枚举类型说明

### OH_AVSCREEN_CAPTURE_ErrCode

```
enum OH_AVSCREEN_CAPTURE_ErrCode
```

**描述：**

屏幕录制操作错误码

\@syscap SystemCapability.Multimedia.Media.Core

**起始版本：**

10

| 枚举值 | 描述 |
| -------- | -------- |
| AV_SCREEN_CAPTURE_ERR_BASE | basic error mask for screen recording. |
| AV_SCREEN_CAPTURE_ERR_OK | the operation completed successfully. |
| AV_SCREEN_CAPTURE_ERR_NO_MEMORY | no memory. |
| AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT | opertation not be permitted. |
| AV_SCREEN_CAPTURE_ERR_INVALID_VAL | invalid argument. |
| AV_SCREEN_CAPTURE_ERR_IO | IO error. |
| AV_SCREEN_CAPTURE_ERR_TIMEOUT | network timeout. |
| AV_SCREEN_CAPTURE_ERR_UNKNOWN | unknown error. |
| AV_SCREEN_CAPTURE_ERR_SERVICE_DIED | media service died. |
| AV_SCREEN_CAPTURE_ERR_INVALID_STATE | the state is not support this operation. |
| AV_SCREEN_CAPTURE_ERR_UNSUPPORT | unsupport interface. |
| AV_SCREEN_CAPTURE_ERR_EXTEND_START | extend err start. |