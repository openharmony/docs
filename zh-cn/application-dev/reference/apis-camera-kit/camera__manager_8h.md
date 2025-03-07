# camera_manager.h


## 概述

声明相机管理器的概念。

**库：** libohcamera.so

**引用文件：**&lt;ohcamera/camera_manager.h&gt;

**系统能力：** SystemCapability.Multimedia.Camera.Core

**起始版本：** 11

**相关模块：**[OH_Camera](_o_h___camera.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct  [CameraManager_Callbacks](_camera_manager___callbacks.md) | 相机设备状态的回调。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef void(\* [OH_CameraManager_StatusCallback](_o_h___camera.md#oh_cameramanager_statuscallback)) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, [Camera_StatusInfo](_camera___status_info.md) \*status) | 在[CameraManager_Callbacks](_camera_manager___callbacks.md)中被调用的相机管理器状态回调。 | 
| typedef void(\* [OH_CameraManager_TorchStatusCallback](_o_h___camera.md#oh_cameramanager_torchstatuscallback)) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, [Camera_TorchStatusInfo](_camera___torch_status_info.md) \*status) | 手电筒状态变化回调。 | 
| typedef struct [CameraManager_Callbacks](_camera_manager___callbacks.md) [CameraManager_Callbacks](_o_h___camera.md#cameramanager_callbacks) | 相机设备状态的回调。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraManager_RegisterCallback](_o_h___camera.md#oh_cameramanager_registercallback) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, [CameraManager_Callbacks](_camera_manager___callbacks.md) \*callback) | 注册相机状态更改事件回调。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraManager_UnregisterCallback](_o_h___camera.md#oh_cameramanager_unregistercallback) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, [CameraManager_Callbacks](_camera_manager___callbacks.md) \*callback) | 注销摄像机状态更改事件回调。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraManager_RegisterTorchStatusCallback](_o_h___camera.md#oh_cameramanager_registertorchstatuscallback) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, [OH_CameraManager_TorchStatusCallback](_o_h___camera.md#oh_cameramanager_torchstatuscallback) torchStatusCallback) | 注册手电筒状态变更事件回调。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraManager_UnregisterTorchStatusCallback](_o_h___camera.md#oh_cameramanager_unregistertorchstatuscallback) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, [OH_CameraManager_TorchStatusCallback](_o_h___camera.md#oh_cameramanager_torchstatuscallback) torchStatusCallback) | 注销手电筒状态变更事件回调。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraManager_GetSupportedCameras](_o_h___camera.md#oh_cameramanager_getsupportedcameras) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, [Camera_Device](_camera___device.md) \*\*cameras, uint32_t \*size) | 获取支持相机的描述。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraManager_DeleteSupportedCameras](_o_h___camera.md#oh_cameramanager_deletesupportedcameras) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, [Camera_Device](_camera___device.md) \*cameras, uint32_t size) | 删除支持的相机。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraManager_GetSupportedCameraOutputCapability](_o_h___camera.md#oh_cameramanager_getsupportedcameraoutputcapability) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, const [Camera_Device](_camera___device.md) \*camera, [Camera_OutputCapability](_camera___output_capability.md) \*\*cameraOutputCapability) | 查询指定相机在指定模式下支持的输出能力。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraManager_GetSupportedCameraOutputCapabilityWithSceneMode](_o_h___camera.md#oh_cameramanager_getsupportedcameraoutputcapabilitywithscenemode) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, const [Camera_Device](_camera___device.md) \*camera, [Camera_SceneMode](_o_h___camera.md#camera_scenemode) sceneMode, [Camera_OutputCapability](_camera___output_capability.md) \*\*cameraOutputCapability) | 查询指定相机在指定模式下支持的输出能力。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraManager_DeleteSupportedCameraOutputCapability](_o_h___camera.md#oh_cameramanager_deletesupportedcameraoutputcapability) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, [Camera_OutputCapability](_camera___output_capability.md) \*cameraOutputCapability) | 删除支持的输出功能。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraManager_IsCameraMuted](_o_h___camera.md#oh_cameramanager_iscameramuted) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, bool \*isCameraMuted) | 确定相机是否静音。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraManager_CreateCaptureSession](_o_h___camera.md#oh_cameramanager_createcapturesession) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, [Camera_CaptureSession](_o_h___camera.md#camera_capturesession) \*\*captureSession) | 创建捕获会话实例。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraManager_CreateCameraInput](_o_h___camera.md#oh_cameramanager_createcamerainput) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, const [Camera_Device](_camera___device.md) \*camera, [Camera_Input](_o_h___camera.md#camera_input) \*\*cameraInput) | 创建相机输入实例。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraManager_CreateCameraInput_WithPositionAndType](_o_h___camera.md#oh_cameramanager_createcamerainput_withpositionandtype) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, [Camera_Position](_o_h___camera.md#camera_position) position, [Camera_Type](_o_h___camera.md#camera_type) type, [Camera_Input](_o_h___camera.md#camera_input) \*\*cameraInput) | 创建具有位置和类型的相机输入实例 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraManager_CreatePreviewOutput](_o_h___camera.md#oh_cameramanager_createpreviewoutput) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, const [Camera_Profile](_camera___profile.md) \*profile, const char \*surfaceId, [Camera_PreviewOutput](_o_h___camera.md#camera_previewoutput) \*\*previewOutput) | 创建预览输出实例。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraManager_CreatePreviewOutputUsedInPreconfig](_o_h___camera.md#oh_cameramanager_createpreviewoutputusedinpreconfig) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, const char \*surfaceId, [Camera_PreviewOutput](_o_h___camera.md#camera_previewoutput) \*\*previewOutput) | 创建在预配置流中使用的预览输出实例。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraManager_CreatePhotoOutput](_o_h___camera.md#oh_cameramanager_createphotooutput) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, const [Camera_Profile](_camera___profile.md) \*profile, const char \*surfaceId, [Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*\*photoOutput) | 创建一个拍照输出实例。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraManager_CreatePhotoOutputUsedInPreconfig](_o_h___camera.md#oh_cameramanager_createphotooutputusedinpreconfig) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, const char \*surfaceId, [Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*\*photoOutput) | 创建在预配置流中使用的照片输出实例。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraManager_CreatePhotoOutputWithoutSurface](_o_h___camera.md#oh_cameramanager_createphotooutputwithoutsurface) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, const [Camera_Profile](_camera___profile.md) \*profile, [Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*\*photoOutput) | 创建照片输出实例，调用此函数不需要surfaceId。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraManager_CreateVideoOutput](_o_h___camera.md#oh_cameramanager_createvideooutput) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, const [Camera_VideoProfile](_camera___video_profile.md) \*profile, const char \*surfaceId, [Camera_VideoOutput](_o_h___camera.md#camera_videooutput) \*\*videoOutput) | 创建一个录像输出实例。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraManager_CreateVideoOutputUsedInPreconfig](_o_h___camera.md#oh_cameramanager_createvideooutputusedinpreconfig) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, const char \*surfaceId, [Camera_VideoOutput](_o_h___camera.md#camera_videooutput) \*\*videoOutput) | 创建在预配置流中使用的视频输出实例。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraManager_CreateMetadataOutput](_o_h___camera.md#oh_cameramanager_createmetadataoutput) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, const [Camera_MetadataObjectType](_o_h___camera.md#camera_metadataobjecttype) \*profile, [Camera_MetadataOutput](_o_h___camera.md#camera_metadataoutput) \*\*metadataOutput) | 创建元数据输出实例。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraManager_GetSupportedSceneModes](_o_h___camera.md#oh_cameramanager_getsupportedscenemodes) ([Camera_Device](_camera___device.md) \*camera, [Camera_SceneMode](_o_h___camera.md#camera_scenemode) \*\*sceneModes, uint32_t \*size) | 获取特定摄影机支持的场景模式。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraManager_DeleteSceneModes](_o_h___camera.md#oh_cameramanager_deletescenemodes) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, [Camera_SceneMode](_o_h___camera.md#camera_scenemode) \*sceneModes) | 删除场景模式。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraManager_IsTorchSupported](_o_h___camera.md#oh_cameramanager_istorchsupported) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, bool \*isTorchSupported) | 检查设备是否支持手电筒。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraManager_IsTorchSupportedByTorchMode](_o_h___camera.md#oh_cameramanager_istorchsupportedbytorchmode) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, [Camera_TorchMode](_o_h___camera.md#camera_torchmode) torchMode, bool \*isTorchSupported) | 检查设备是否支持指定的手电筒模式。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraManager_SetTorchMode](_o_h___camera.md#oh_cameramanager_settorchmode) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, [Camera_TorchMode](_o_h___camera.md#camera_torchmode) torchMode) | 设置相机手电筒模式。 | 
