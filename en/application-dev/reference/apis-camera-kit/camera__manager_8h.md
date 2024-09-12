# camera_manager.h


## Overview

The **camera_manager.h** file declares the camera manager concepts.

**Library**: libohcamera.so

**File to include**: &lt;ohcamera/camera_manager.h&gt; 

**System capability**: SystemCapability.Multimedia.Camera.Core

**Since**: 11

**Related module**: [OH_Camera](_o_h___camera.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| struct  [CameraManager_Callbacks](_camera_manager___callbacks.md) | Describes the callbacks used to listen for camera status changes.| 


### Types

| Name| Description| 
| -------- | -------- |
| typedef void(\* [OH_CameraManager_StatusCallback](_o_h___camera.md#oh_cameramanager_statuscallback)) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, [Camera_StatusInfo](_camera___status_info.md) \*status) | Defines the callback defined in the [CameraManager_Callbacks](_camera_manager___callbacks.md) struct and used to report the camera manager status.| 
| typedef void(\* [OH_CameraManager_TorchStatusCallback](_o_h___camera.md#oh_cameramanager_torchstatuscallback)) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, [Camera_TorchStatusInfo](_camera___torch_status_info.md) \*status) | Defines the callback invoked when the flashlight status changes.| 
| typedef struct [CameraManager_Callbacks](_camera_manager___callbacks.md) [CameraManager_Callbacks](_o_h___camera.md#cameramanager_callbacks) | Defines a struct for the callbacks used to listen for camera status changes.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraManager_RegisterCallback](_o_h___camera.md#oh_cameramanager_registercallback) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, [CameraManager_Callbacks](_camera_manager___callbacks.md) \*callback) | Registers a callback to listen for camera status changes.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraManager_UnregisterCallback](_o_h___camera.md#oh_cameramanager_unregistercallback) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, [CameraManager_Callbacks](_camera_manager___callbacks.md) \*callback) | Unregisters the callback used to listen for camera status changes.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraManager_RegisterTorchStatusCallback](_o_h___camera.md#oh_cameramanager_registertorchstatuscallback) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, [OH_CameraManager_TorchStatusCallback](_o_h___camera.md#oh_cameramanager_torchstatuscallback) torchStatusCallback) | Registers a callback to listen for flashlight status changes.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraManager_UnregisterTorchStatusCallback](_o_h___camera.md#oh_cameramanager_unregistertorchstatuscallback) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, [OH_CameraManager_TorchStatusCallback](_o_h___camera.md#oh_cameramanager_torchstatuscallback) torchStatusCallback) | Unregisters the callback used to listen for flashlight status changes.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraManager_GetSupportedCameras](_o_h___camera.md#oh_cameramanager_getsupportedcameras) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, [Camera_Device](_camera___device.md) \*\*cameras, uint32_t \*size) | Obtains supported cameras.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraManager_DeleteSupportedCameras](_o_h___camera.md#oh_cameramanager_deletesupportedcameras) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, [Camera_Device](_camera___device.md) \*cameras, uint32_t size) | Deletes supported cameras.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraManager_GetSupportedCameraOutputCapability](_o_h___camera.md#oh_cameramanager_getsupportedcameraoutputcapability) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, const [Camera_Device](_camera___device.md) \*camera, [Camera_OutputCapability](_camera___output_capability.md) \*\*cameraOutputCapability) | Obtains the output capability supported by a camera.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraManager_GetSupportedCameraOutputCapabilityWithSceneMode](_o_h___camera.md#oh_cameramanager_getsupportedcameraoutputcapabilitywithscenemode) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, const [Camera_Device](_camera___device.md) \*camera, [Camera_SceneMode](_o_h___camera.md#camera_scenemode) sceneMode, [Camera_OutputCapability](_camera___output_capability.md) \*\*cameraOutputCapability) | Obtains the output capability supported by a camera in a given scene mode.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraManager_DeleteSupportedCameraOutputCapability](_o_h___camera.md#oh_cameramanager_deletesupportedcameraoutputcapability) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, [Camera_OutputCapability](_camera___output_capability.md) \*cameraOutputCapability) | Deletes the output capability supported by a camera.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraManager_IsCameraMuted](_o_h___camera.md#oh_cameramanager_iscameramuted) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, bool \*isCameraMuted) | Checks whether a camera is muted.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraManager_CreateCaptureSession](_o_h___camera.md#oh_cameramanager_createcapturesession) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, [Camera_CaptureSession](_o_h___camera.md#camera_capturesession) \*\*captureSession) | Creates a **CaptureSession** instance.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraManager_CreateCameraInput](_o_h___camera.md#oh_cameramanager_createcamerainput) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, const [Camera_Device](_camera___device.md) \*camera, [Camera_Input](_o_h___camera.md#camera_input) \*\*cameraInput) | Creates a **CameraInput** instance.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraManager_CreateCameraInput_WithPositionAndType](_o_h___camera.md#oh_cameramanager_createcamerainput_withpositionandtype) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, [Camera_Position](_o_h___camera.md#camera_position) position, [Camera_Type](_o_h___camera.md#camera_type) type, [Camera_Input](_o_h___camera.md#camera_input) \*\*cameraInput) | Creates a **CameraInput** instance with the specified location and type.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraManager_CreatePreviewOutput](_o_h___camera.md#oh_cameramanager_createpreviewoutput) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, const [Camera_Profile](_camera___profile.md) \*profile, const char \*surfaceId, [Camera_PreviewOutput](_o_h___camera.md#camera_previewoutput) \*\*previewOutput) | Creates a **PreviewOutput** instance.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraManager_CreatePreviewOutputUsedInPreconfig](_o_h___camera.md#oh_cameramanager_createpreviewoutputusedinpreconfig) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, const char \*surfaceId, [Camera_PreviewOutput](_o_h___camera.md#camera_previewoutput) \*\*previewOutput) | Creates a **PreviewOutput** instance to be used in a preconfiguration stream.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraManager_CreatePhotoOutput](_o_h___camera.md#oh_cameramanager_createphotooutput) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, const [Camera_Profile](_camera___profile.md) \*profile, const char \*surfaceId, [Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*\*photoOutput) | Creates a **PhotoOutput** instance.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraManager_CreatePhotoOutputUsedInPreconfig](_o_h___camera.md#oh_cameramanager_createphotooutputusedinpreconfig) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, const char \*surfaceId, [Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*\*photoOutput) | Creates a **PhotoOutput** instance to be used in a preconfiguration stream.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraManager_CreatePhotoOutputWithoutSurface](_o_h___camera.md#oh_cameramanager_createphotooutputwithoutsurface) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, const [Camera_Profile](_camera___profile.md) \*profile, [Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*\*photoOutput) | Creates a **PhotoOutput** instance. **surfaceId** is not required in this function.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraManager_CreateVideoOutput](_o_h___camera.md#oh_cameramanager_createvideooutput) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, const [Camera_VideoProfile](_camera___video_profile.md) \*profile, const char \*surfaceId, [Camera_VideoOutput](_o_h___camera.md#camera_videooutput) \*\*videoOutput) | Creates a **VideoOutput** instance.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraManager_CreateVideoOutputUsedInPreconfig](_o_h___camera.md#oh_cameramanager_createvideooutputusedinpreconfig) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, const char \*surfaceId, [Camera_VideoOutput](_o_h___camera.md#camera_videooutput) \*\*videoOutput) | Creates a **VideoOutput** instance to be used in a preconfiguration stream.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraManager_CreateMetadataOutput](_o_h___camera.md#oh_cameramanager_createmetadataoutput) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, const [Camera_MetadataObjectType](_o_h___camera.md#camera_metadataobjecttype) \*profile, [Camera_MetadataOutput](_o_h___camera.md#camera_metadataoutput) \*\*metadataOutput) | Creates a **MetadataOutput** instance.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraManager_GetSupportedSceneModes](_o_h___camera.md#oh_cameramanager_getsupportedscenemodes) ([Camera_Device](_camera___device.md) \*camera, [Camera_SceneMode](_o_h___camera.md#camera_scenemode) \*\*sceneModes, uint32_t \*size) | Obtains the scene modes supported by a camera.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraManager_DeleteSceneModes](_o_h___camera.md#oh_cameramanager_deletescenemodes) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, [Camera_SceneMode](_o_h___camera.md#camera_scenemode) \*sceneModes) | Deletes scene modes.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraManager_IsTorchSupported](_o_h___camera.md#oh_cameramanager_istorchsupported) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, bool \*isTorchSupported) | Checks whether the device supports the flashlight.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraManager_IsTorchSupportedByTorchMode](_o_h___camera.md#oh_cameramanager_istorchsupportedbytorchmode) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, [Camera_TorchMode](_o_h___camera.md#camera_torchmode) torchMode, bool \*isTorchSupported) | Checks whether the device supports the specified flashlight mode.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraManager_SetTorchMode](_o_h___camera.md#oh_cameramanager_settorchmode) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, [Camera_TorchMode](_o_h___camera.md#camera_torchmode) torchMode) | Sets a flashlight mode.| 
