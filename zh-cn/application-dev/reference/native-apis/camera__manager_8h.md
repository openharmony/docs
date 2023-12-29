# camera_manager.h


## 概述

声明相机管理器的概念。

**库：** libohcamera.so

**系统能力：** SystemCapability.Multimedia.Camera.Core

**起始版本：** 11

**相关模块：**[OH_Camera](_o_h___camera.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| [CameraManager_Callbacks](_camera_manager___callbacks.md) | 相机设备状态的回调。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| (\*[OH_CameraManager_StatusCallback](_o_h___camera.md#oh_cameramanager_statuscallback)) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, [Camera_StatusInfo](_camera___status_info.md) \*status) | 在[CameraManager_Callbacks](_camera_manager___callbacks.md)中被调用的相机管理器状态回调。 | 
| [CameraManager_Callbacks](_o_h___camera.md#cameramanager_callbacks) | 相机设备状态的回调。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_CameraManager_RegisterCallback](_o_h___camera.md#oh_cameramanager_registercallback) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, [CameraManager_Callbacks](_camera_manager___callbacks.md) \*callback) | 注册相机状态更改事件回调。 | 
| [OH_CameraManager_UnregisterCallback](_o_h___camera.md#oh_cameramanager_unregistercallback) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, [CameraManager_Callbacks](_camera_manager___callbacks.md) \*callback) | 注销摄像机状态更改事件回调。 | 
| [OH_CameraManager_GetSupportedCameras](_o_h___camera.md#oh_cameramanager_getsupportedcameras) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, [Camera_Device](_camera___device.md) \*\*cameras, uint32_t \*size) | 获取支持相机的描述。 | 
| [OH_CameraManager_DeleteSupportedCameras](_o_h___camera.md#oh_cameramanager_deletesupportedcameras) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, [Camera_Device](_camera___device.md) \*cameras, uint32_t size) | 删除支持的相机。 | 
| [OH_CameraManager_GetSupportedCameraOutputCapability](_o_h___camera.md#oh_cameramanager_getsupportedcameraoutputcapability) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, const [Camera_Device](_camera___device.md) \*camera, [Camera_OutputCapability](_camera___output_capability.md) \*\*cameraOutputCapability) | 获取特定相机和特定模式支持的输出功能。 | 
| [OH_CameraManager_DeleteSupportedCameraOutputCapability](_o_h___camera.md#oh_cameramanager_deletesupportedcameraoutputcapability) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, [Camera_OutputCapability](_camera___output_capability.md) \*cameraOutputCapability) | 删除支持的输出功能。 | 
| [OH_CameraManager_IsCameraMuted](_o_h___camera.md#oh_cameramanager_iscameramuted) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, bool \*isCameraMuted) | 确定相机是否静音。 | 
| [OH_CameraManager_CreateCaptureSession](_o_h___camera.md#oh_cameramanager_createcapturesession) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, [Camera_CaptureSession](_o_h___camera.md#camera_capturesession) \*\*captureSession) | 创建捕获会话实例。 | 
| [OH_CameraManager_CreateCameraInput](_o_h___camera.md#oh_cameramanager_createcamerainput) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, const [Camera_Device](_camera___device.md) \*camera, [Camera_Input](_o_h___camera.md#camera_input) \*\*cameraInput) | 创建相机输入实例。 | 
| [OH_CameraManager_CreateCameraInput_WithPositionAndType](_o_h___camera.md#oh_cameramanager_createcamerainput_withpositionandtype) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, [Camera_Position](_o_h___camera.md#camera_position) position, [Camera_Type](_o_h___camera.md#camera_type) type, [Camera_Input](_o_h___camera.md#camera_input) \*\*cameraInput) | 创建具有位置和类型的相机输入实例 | 
| [OH_CameraManager_CreatePreviewOutput](_o_h___camera.md#oh_cameramanager_createpreviewoutput) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, const [Camera_Profile](_camera___profile.md) \*profile, const char \*surfaceId, [Camera_PreviewOutput](_o_h___camera.md#camera_previewoutput) \*\*previewOutput) | 创建预览输出实例。 | 
| [OH_CameraManager_CreatePhotoOutput](_o_h___camera.md#oh_cameramanager_createphotooutput) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, const [Camera_Profile](_camera___profile.md) \*profile, const char \*surfaceId, [Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*\*photoOutput) | 创建一个拍照输出实例。 | 
| [OH_CameraManager_CreateVideoOutput](_o_h___camera.md#oh_cameramanager_createvideooutput) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, const [Camera_VideoProfile](_camera___video_profile.md) \*profile, const char \*surfaceId, [Camera_VideoOutput](_o_h___camera.md#camera_videooutput) \*\*videoOutput) | 创建一个录像输出实例。 | 
| [OH_CameraManager_CreateMetadataOutput](_o_h___camera.md#oh_cameramanager_createmetadataoutput) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, const [Camera_MetadataObjectType](_o_h___camera.md#camera_metadataobjecttype) \*profile, [Camera_MetadataOutput](_o_h___camera.md#camera_metadataoutput) \*\*metadataOutput) | 创建元数据输出实例。 | 
