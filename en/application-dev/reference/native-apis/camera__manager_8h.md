# camera_manager.h


## Overview

The **camera_manager.h** file declares the camera manager concepts.

**Library**: libohcamera.so

**System capability**: SystemCapability.Multimedia.Camera.Core

**Since**: 11

**Related module**: [OH_Camera](_o_h___camera.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| [CameraManager_Callbacks](_camera_manager___callbacks.md) | Defines the callbacks used to listen for camera status changes.| 


### Types

| Name| Description| 
| -------- | -------- |
| (\*[OH_CameraManager_StatusCallback](_o_h___camera.md#oh_cameramanager_statuscallback)) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, [Camera_StatusInfo](_camera___status_info.md) \*status) | Defines the pointer to the callback defined in the [CameraManager_Callbacks](_camera_manager___callbacks.md) struct and used to report the camera manager status.| 
| [CameraManager_Callbacks](_o_h___camera.md#cameramanager_callbacks) | Defines the callbacks used to listen for camera status changes.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_CameraManager_RegisterCallback](_o_h___camera.md#oh_cameramanager_registercallback) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, [CameraManager_Callbacks](_camera_manager___callbacks.md) \*callback) | Registers a callback to listen for camera status changes.| 
| [OH_CameraManager_UnregisterCallback](_o_h___camera.md#oh_cameramanager_unregistercallback) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, [CameraManager_Callbacks](_camera_manager___callbacks.md) \*callback) | Unregisters the callback used to listen for camera status changes.| 
| [OH_CameraManager_GetSupportedCameras](_o_h___camera.md#oh_cameramanager_getsupportedcameras) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, [Camera_Device](_camera___device.md) \*\*cameras, uint32_t \*size) | Obtains supported cameras.| 
| [OH_CameraManager_DeleteSupportedCameras](_o_h___camera.md#oh_cameramanager_deletesupportedcameras) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, [Camera_Device](_camera___device.md) \*cameras, uint32_t size) | Deletes supported cameras.| 
| [OH_CameraManager_GetSupportedCameraOutputCapability](_o_h___camera.md#oh_cameramanager_getsupportedcameraoutputcapability) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, const [Camera_Device](_camera___device.md) \*camera, [Camera_OutputCapability](_camera___output_capability.md) \*\*cameraOutputCapability) | Obtains the output capability supported by a camera in the specified mode.| 
| [OH_CameraManager_DeleteSupportedCameraOutputCapability](_o_h___camera.md#oh_cameramanager_deletesupportedcameraoutputcapability) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, [Camera_OutputCapability](_camera___output_capability.md) \*cameraOutputCapability) | Deletes the output capability supported by a camera.| 
| [OH_CameraManager_IsCameraMuted](_o_h___camera.md#oh_cameramanager_iscameramuted) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, bool \*isCameraMuted) | Checks whether a camera is muted.| 
| [OH_CameraManager_CreateCaptureSession](_o_h___camera.md#oh_cameramanager_createcapturesession) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, [Camera_CaptureSession](_o_h___camera.md#camera_capturesession) \*\*captureSession) | Creates a **CaptureSession** instance.| 
| [OH_CameraManager_CreateCameraInput](_o_h___camera.md#oh_cameramanager_createcamerainput) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, const [Camera_Device](_camera___device.md) \*camera, [Camera_Input](_o_h___camera.md#camera_input) \*\*cameraInput) | Creates a **CameraInput** instance.| 
| [OH_CameraManager_CreateCameraInput_WithPositionAndType](_o_h___camera.md#oh_cameramanager_createcamerainput_withpositionandtype) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, [Camera_Position](_o_h___camera.md#camera_position) position, [Camera_Type](_o_h___camera.md#camera_type) type, [Camera_Input](_o_h___camera.md#camera_input) \*\*cameraInput) | Creates a **CameraInput** instance with the specified location and type.| 
| [OH_CameraManager_CreatePreviewOutput](_o_h___camera.md#oh_cameramanager_createpreviewoutput) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, const [Camera_Profile](_camera___profile.md) \*profile, const char \*surfaceId, [Camera_PreviewOutput](_o_h___camera.md#camera_previewoutput) \*\*previewOutput) | Creates a **PreviewOutput** instance.| 
| [OH_CameraManager_CreatePhotoOutput](_o_h___camera.md#oh_cameramanager_createphotooutput) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, const [Camera_Profile](_camera___profile.md) \*profile, const char \*surfaceId, [Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*\*photoOutput) | Creates a **PhotoOutput** instance.| 
| [OH_CameraManager_CreateVideoOutput](_o_h___camera.md#oh_cameramanager_createvideooutput) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, const [Camera_VideoProfile](_camera___video_profile.md) \*profile, const char \*surfaceId, [Camera_VideoOutput](_o_h___camera.md#camera_videooutput) \*\*videoOutput) | Creates a **VideoOutput** instance.| 
| [OH_CameraManager_CreateMetadataOutput](_o_h___camera.md#oh_cameramanager_createmetadataoutput) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager, const [Camera_MetadataObjectType](_o_h___camera.md#camera_metadataobjecttype) \*profile, [Camera_MetadataOutput](_o_h___camera.md#camera_metadataoutput) \*\*metadataOutput) | Creates a **MetadataOutput** instance.| 
