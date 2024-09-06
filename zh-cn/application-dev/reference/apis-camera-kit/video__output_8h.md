# video_output.h


## 概述

声明录像输出概念。

**库：** libohcamera.so

**引用文件：**&lt;ohcamera/video_output.h&gt;

**系统能力：** SystemCapability.Multimedia.Camera.Core

**起始版本：** 11

**相关模块：**[OH_Camera](_o_h___camera.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct  [VideoOutput_Callbacks](_video_output___callbacks.md) | 用于录像输出的回调。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [Camera_VideoOutput](_o_h___camera.md#camera_videooutput) [Camera_VideoOutput](_o_h___camera.md#camera_videooutput) | 录像输出对象。 | 
| typedef void(\* [OH_VideoOutput_OnFrameStart](_o_h___camera.md#oh_videooutput_onframestart)) ([Camera_VideoOutput](_o_h___camera.md#camera_videooutput) \*videoOutput) | 在[VideoOutput_Callbacks](_video_output___callbacks.md)中被调用的录像输出帧开始回调。 | 
| typedef void(\* [OH_VideoOutput_OnFrameEnd](_o_h___camera.md#oh_videooutput_onframeend)) ([Camera_VideoOutput](_o_h___camera.md#camera_videooutput) \*videoOutput, int32_t frameCount) | 在[VideoOutput_Callbacks](_video_output___callbacks.md)中被调用的录像输出帧结束回调。 | 
| typedef void(\* [OH_VideoOutput_OnError](_o_h___camera.md#oh_videooutput_onerror)) ([Camera_VideoOutput](_o_h___camera.md#camera_videooutput) \*videoOutput, [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) errorCode) | 在[VideoOutput_Callbacks](_video_output___callbacks.md)中被调用的录像输出错误回调。 | 
| typedef struct [VideoOutput_Callbacks](_video_output___callbacks.md) [VideoOutput_Callbacks](_o_h___camera.md#videooutput_callbacks) | 用于录像输出的回调。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_VideoOutput_RegisterCallback](_o_h___camera.md#oh_videooutput_registercallback) ([Camera_VideoOutput](_o_h___camera.md#camera_videooutput) \*videoOutput, [VideoOutput_Callbacks](_video_output___callbacks.md) \*callback) | 注册录像输出更改事件回调。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_VideoOutput_UnregisterCallback](_o_h___camera.md#oh_videooutput_unregistercallback) ([Camera_VideoOutput](_o_h___camera.md#camera_videooutput) \*videoOutput, [VideoOutput_Callbacks](_video_output___callbacks.md) \*callback) | 注销录像输出更改事件回调。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_VideoOutput_Start](_o_h___camera.md#oh_videooutput_start) ([Camera_VideoOutput](_o_h___camera.md#camera_videooutput) \*videoOutput) | 开始录像输出。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_VideoOutput_Stop](_o_h___camera.md#oh_videooutput_stop) ([Camera_VideoOutput](_o_h___camera.md#camera_videooutput) \*videoOutput) | 停止录像输出。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_VideoOutput_Release](_o_h___camera.md#oh_videooutput_release) ([Camera_VideoOutput](_o_h___camera.md#camera_videooutput) \*videoOutput) | 释放录像输出。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_VideoOutput_GetActiveProfile](_o_h___camera.md#oh_videooutput_getactiveprofile) ([Camera_VideoOutput](_o_h___camera.md#camera_videooutput) \*videoOutput, [Camera_VideoProfile](_camera___video_profile.md) \*\*profile) | 获取当前视频输出配置文件。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_VideoOutput_DeleteProfile](_o_h___camera.md#oh_videooutput_deleteprofile) ([Camera_VideoProfile](_camera___video_profile.md) \*profile) | 删除视频配置文件实例。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_VideoOutput_GetSupportedFrameRates](_o_h___camera.md#oh_videooutput_getsupportedframerates) ([Camera_VideoOutput](_o_h___camera.md#camera_videooutput) \*videoOutput, [Camera_FrameRateRange](_camera___frame_rate_range.md) \*\*frameRateRange, uint32_t \*size) | 获取支持的视频输出帧率列表。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_VideoOutput_DeleteFrameRates](_o_h___camera.md#oh_videooutput_deleteframerates) ([Camera_VideoOutput](_o_h___camera.md#camera_videooutput) \*videoOutput, [Camera_FrameRateRange](_camera___frame_rate_range.md) \*frameRateRange) | 删除帧率列表。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_VideoOutput_SetFrameRate](_o_h___camera.md#oh_videooutput_setframerate) ([Camera_VideoOutput](_o_h___camera.md#camera_videooutput) \*videoOutput, int32_t minFps, int32_t maxFps) | 设置视频输出帧率。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_VideoOutput_GetActiveFrameRate](_o_h___camera.md#oh_videooutput_getactiveframerate) ([Camera_VideoOutput](_o_h___camera.md#camera_videooutput) \*videoOutput, [Camera_FrameRateRange](_camera___frame_rate_range.md) \*frameRateRange) | 获取当前视频输出帧率。 | 
