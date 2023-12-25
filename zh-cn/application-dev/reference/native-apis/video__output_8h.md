# video_output.h


## 概述

声明录像输出概念。

**库：** libohcamera.so

**系统能力：** SystemCapability.Multimedia.Camera.Core

**起始版本：** 11

**相关模块：**[OH_Camera](_o_h___camera.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| [VideoOutput_Callbacks](_video_output___callbacks.md) | 用于录像输出的回调。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| [Camera_VideoOutput](_o_h___camera.md#camera_videooutput) | 录像输出对象。 | 
| (\*[OH_VideoOutput_OnFrameStart](_o_h___camera.md#oh_videooutput_onframestart)) ([Camera_VideoOutput](_o_h___camera.md#camera_videooutput) \*videoOutput) | 在[VideoOutput_Callbacks](_video_output___callbacks.md)中被调用的录像输出帧开始回调。 | 
| (\*[OH_VideoOutput_OnFrameEnd](_o_h___camera.md#oh_videooutput_onframeend)) ([Camera_VideoOutput](_o_h___camera.md#camera_videooutput) \*videoOutput, int32_t frameCount) | 在[VideoOutput_Callbacks](_video_output___callbacks.md)中被调用的录像输出帧结束回调。 | 
| (\*[OH_VideoOutput_OnError](_o_h___camera.md#oh_videooutput_onerror)) ([Camera_VideoOutput](_o_h___camera.md#camera_videooutput) \*videoOutput, [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) errorCode) | 在[VideoOutput_Callbacks](_video_output___callbacks.md)中被调用的录像输出错误回调。 | 
| [VideoOutput_Callbacks](_o_h___camera.md#videooutput_callbacks) | 用于录像输出的回调。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_VideoOutput_RegisterCallback](_o_h___camera.md#oh_videooutput_registercallback) ([Camera_VideoOutput](_o_h___camera.md#camera_videooutput) \*videoOutput, [VideoOutput_Callbacks](_video_output___callbacks.md) \*callback) | 注册录像输出更改事件回调。 | 
| [OH_VideoOutput_UnregisterCallback](_o_h___camera.md#oh_videooutput_unregistercallback) ([Camera_VideoOutput](_o_h___camera.md#camera_videooutput) \*videoOutput, [VideoOutput_Callbacks](_video_output___callbacks.md) \*callback) | 注销录像输出更改事件回调。 | 
| [OH_VideoOutput_Start](_o_h___camera.md#oh_videooutput_start) ([Camera_VideoOutput](_o_h___camera.md#camera_videooutput) \*videoOutput) | 开始录像输出。 | 
| [OH_VideoOutput_Stop](_o_h___camera.md#oh_videooutput_stop) ([Camera_VideoOutput](_o_h___camera.md#camera_videooutput) \*videoOutput) | 停止录像输出。 | 
| [OH_VideoOutput_Release](_o_h___camera.md#oh_videooutput_release) ([Camera_VideoOutput](_o_h___camera.md#camera_videooutput) \*videoOutput) | 释放录像输出。 | 
