# camera_input.h


## 概述

声明相机输入概念。

**库：** libohcamera.so

**引用文件：**&lt;ohcamera/camera_input.h&gt;

**系统能力：** SystemCapability.Multimedia.Camera.Core

**起始版本：** 11

**相关模块：**[OH_Camera](_o_h___camera.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct  [CameraInput_Callbacks](_camera_input___callbacks.md) | 相机输入错误事件的回调。  | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [Camera_Input](_o_h___camera.md#camera_input) [Camera_Input](_o_h___camera.md#camera_input) | 相机输入对象。  | 
| typedef void(\* [OH_CameraInput_OnError](_o_h___camera.md#oh_camerainput_onerror)) (const [Camera_Input](_o_h___camera.md#camera_input) \*cameraInput, [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) errorCode) | 在[CameraInput_Callbacks](_camera_input___callbacks.md)中被调用的相机输入错误回调。  | 
| typedef struct [CameraInput_Callbacks](_camera_input___callbacks.md) [CameraInput_Callbacks](_o_h___camera.md#camerainput_callbacks) | 相机输入错误事件的回调。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraInput_RegisterCallback](_o_h___camera.md#oh_camerainput_registercallback) ([Camera_Input](_o_h___camera.md#camera_input) \*cameraInput, [CameraInput_Callbacks](_camera_input___callbacks.md) \*callback) | 注册相机输入更改事件回调。  | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraInput_UnregisterCallback](_o_h___camera.md#oh_camerainput_unregistercallback) ([Camera_Input](_o_h___camera.md#camera_input) \*cameraInput, [CameraInput_Callbacks](_camera_input___callbacks.md) \*callback) | 注销相机输入更改事件回调。  | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraInput_Open](_o_h___camera.md#oh_camerainput_open) ([Camera_Input](_o_h___camera.md#camera_input) \*cameraInput) | 打开相机。  | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraInput_OpenSecureCamera](_o_h___camera.md#oh_camerainput_opensecurecamera) ([Camera_Input](_o_h___camera.md#camera_input) \*cameraInput, uint64_t \*secureSeqId) | 打开安全相机。  | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraInput_OpenConcurrentCameras](_o_h___camera.md#oh_camerainput_openconcurrentcameras) ([Camera_Input](_o_h___camera.md#camera_input) \*cameraInput, [Camera_ConcurrentType](_o_h___camera.md#camera_concurrenttype) type) | 根据指定并发类型打开相机。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraInput_Close](_o_h___camera.md#oh_camerainput_close) ([Camera_Input](_o_h___camera.md#camera_input) \*cameraInput) | 关闭相机。  | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraInput_Release](_o_h___camera.md#oh_camerainput_release) ([Camera_Input](_o_h___camera.md#camera_input) \*cameraInput) | 释放当前的相机输入实例。与[OH_CameraInput_Close](_o_h___camera.md#oh_camerainput_close)在功能上有相同的部分，在调用此函数之后无须再调用[OH_CameraInput_Close](_o_h___camera.md#oh_camerainput_close)。  | 
