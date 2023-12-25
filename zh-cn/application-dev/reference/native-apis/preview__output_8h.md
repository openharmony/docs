# preview_output.h


## 概述

声明预览输出概念。

**库：** libohcamera.so

**系统能力：** SystemCapability.Multimedia.Camera.Core

**起始版本：** 11

**相关模块：**[OH_Camera](_o_h___camera.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| [PreviewOutput_Callbacks](_preview_output___callbacks.md) | 用于预览输出的回调。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| [Camera_PreviewOutput](_o_h___camera.md#camera_previewoutput) | 预览输出对象。 | 
| (\*[OH_PreviewOutput_OnFrameStart](_o_h___camera.md#oh_previewoutput_onframestart)) ([Camera_PreviewOutput](_o_h___camera.md#camera_previewoutput) \*previewOutput) | 在[PreviewOutput_Callbacks](_preview_output___callbacks.md)中被调用的预览输出帧开始回调。 | 
| (\*[OH_PreviewOutput_OnFrameEnd](_o_h___camera.md#oh_previewoutput_onframeend)) ([Camera_PreviewOutput](_o_h___camera.md#camera_previewoutput) \*previewOutput, int32_t frameCount) | 在[PreviewOutput_Callbacks](_preview_output___callbacks.md)中被调用的预览输出帧结束回调。 | 
| (\*[OH_PreviewOutput_OnError](_o_h___camera.md#oh_previewoutput_onerror)) ([Camera_PreviewOutput](_o_h___camera.md#camera_previewoutput) \*previewOutput, [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) errorCode) | 在[PreviewOutput_Callbacks](_preview_output___callbacks.md)中被调用的预览输出帧错误回调。 | 
| [PreviewOutput_Callbacks](_o_h___camera.md#previewoutput_callbacks) | 用于预览输出的回调。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_PreviewOutput_RegisterCallback](_o_h___camera.md#oh_previewoutput_registercallback) ([Camera_PreviewOutput](_o_h___camera.md#camera_previewoutput) \*previewOutput, [PreviewOutput_Callbacks](_preview_output___callbacks.md) \*callback) | 注册预览输出更改事件回调。 | 
| [OH_PreviewOutput_UnregisterCallback](_o_h___camera.md#oh_previewoutput_unregistercallback) ([Camera_PreviewOutput](_o_h___camera.md#camera_previewoutput) \*previewOutput, [PreviewOutput_Callbacks](_preview_output___callbacks.md) \*callback) | 注销预览输出更改事件回调。 | 
| [OH_PreviewOutput_Start](_o_h___camera.md#oh_previewoutput_start) ([Camera_PreviewOutput](_o_h___camera.md#camera_previewoutput) \*previewOutput) | 开始预览输出。 | 
| [OH_PreviewOutput_Stop](_o_h___camera.md#oh_previewoutput_stop) ([Camera_PreviewOutput](_o_h___camera.md#camera_previewoutput) \*previewOutput) | 停止预览输出。 | 
| [OH_PreviewOutput_Release](_o_h___camera.md#oh_previewoutput_release) ([Camera_PreviewOutput](_o_h___camera.md#camera_previewoutput) \*previewOutput) | 释放预览输出。 | 
