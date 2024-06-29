# photo_output.h


## 概述

声明拍照输出概念。

**库：** libohcamera.so

**引用文件：**&lt;ohcamera/photo_output.h&gt;

**系统能力：** SystemCapability.Multimedia.Camera.Core

**起始版本：** 11

**相关模块：**[OH_Camera](_o_h___camera.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[PhotoOutput_Callbacks](_photo_output___callbacks.md) | 拍照输出的回调。  | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) [Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) | 拍照输出对象  | 
| typedef void(\* [OH_PhotoOutput_OnFrameStart](_o_h___camera.md#oh_photooutput_onframestart)) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput) | 在[PhotoOutput_Callbacks](_photo_output___callbacks.md)中被调用的拍照输出帧启动回调。  | 
| typedef void(\* [OH_PhotoOutput_OnFrameShutter](_o_h___camera.md#oh_photooutput_onframeshutter)) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, [Camera_FrameShutterInfo](_camera___frame_shutter_info.md) \*info) | 在[PhotoOutput_Callbacks](_photo_output___callbacks.md)中被调用的拍照输出帧快门回调。  | 
| typedef void(\* [OH_PhotoOutput_OnFrameEnd](_o_h___camera.md#oh_photooutput_onframeend)) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, int32_t frameCount) | 在[PhotoOutput_Callbacks](_photo_output___callbacks.md)中被调用的拍照输出帧结束回调。  | 
| typedef void(\* [OH_PhotoOutput_OnError](_o_h___camera.md#oh_photooutput_onerror)) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) errorCode) | 在[PhotoOutput_Callbacks](_photo_output___callbacks.md)中被调用的拍照输出错误回调。  | 
| typedef struct [PhotoOutput_Callbacks](_photo_output___callbacks.md) [PhotoOutput_Callbacks](_o_h___camera.md#photooutput_callbacks) | 拍照输出的回调。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoOutput_RegisterCallback](_o_h___camera.md#oh_photooutput_registercallback) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, [PhotoOutput_Callbacks](_photo_output___callbacks.md) \*callback) | 注册拍照输出更改事件回调。  | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoOutput_UnregisterCallback](_o_h___camera.md#oh_photooutput_unregistercallback) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, [PhotoOutput_Callbacks](_photo_output___callbacks.md) \*callback) | 注销拍照输出更改事件回调。  | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoOutput_Capture](_o_h___camera.md#oh_photooutput_capture) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput) | 拍摄照片。  | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoOutput_Capture_WithCaptureSetting](_o_h___camera.md#oh_photooutput_capture_withcapturesetting) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, [Camera_PhotoCaptureSetting](_camera___photo_capture_setting.md) setting) | 使用捕获设置捕获拍照。  | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoOutput_Release](_o_h___camera.md#oh_photooutput_release) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput) | 释放拍照输出。  | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoOutput_IsMirrorSupported](_o_h___camera.md#oh_photooutput_ismirrorsupported) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, bool \*isSupported) | 检查是否支持镜像拍照。  | 
