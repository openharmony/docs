# camera_manager.h

<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=24fda3c85dbda24aa54f2b583638cbacb52c758e translatedAt=2026-08-11T02:01:53.733Z pushedAt=2026-08-12T02:25:16.827Z -->

## Overview

The file declares the camera manager concepts.

**File to include**: <ohcamera/camera_manager.h>

**Library**: libohcamera.so

**System capability**: SystemCapability.Multimedia.Camera.Core

**Since**: 11

**Related module**: [OH_Camera](capi-oh-camera.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [CameraManager_Callbacks](capi-oh-camera-cameramanager-callbacks.md) | CameraManager_Callbacks | Describes the callbacks used to listen for camera status changes.|

### Functions

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [typedef void (\*OH_CameraManager_StatusCallback)(Camera_Manager* cameraManager, Camera_StatusInfo* status)](#oh_cameramanager_statuscallback) | OH_CameraManager_StatusCallback | Defines the callback defined in the [CameraManager_Callbacks](capi-oh-camera-cameramanager-callbacks.md) struct and used to report the camera manager status.|
| [typedef void (\*OH_CameraManager_TorchStatusCallback)(Camera_Manager* cameraManager, Camera_TorchStatusInfo* status)](#oh_cameramanager_torchstatuscallback) | OH_CameraManager_TorchStatusCallback | Defines the callback to listen for flashlight status changes.|
| [typedef void (\*OH_CameraManager_OnFoldStatusInfoChange)(Camera_Manager* cameraManager, Camera_FoldStatusInfo* foldStatusInfo)](#oh_cameramanager_onfoldstatusinfochange) | OH_CameraManager_OnFoldStatusInfoChange | Defines the callback to listen for fold status changes of the camera manager.|
| [Camera_ErrorCode OH_CameraManager_RegisterCallback(Camera_Manager* cameraManager, CameraManager_Callbacks* callback)](#oh_cameramanager_registercallback) | - | Registers a callback to listen for camera status changes.|
| [Camera_ErrorCode OH_CameraManager_UnregisterCallback(Camera_Manager* cameraManager, CameraManager_Callbacks* callback)](#oh_cameramanager_unregistercallback) | - | Unregisters the callback used to listen for camera status changes.|
| [Camera_ErrorCode OH_CameraManager_RegisterTorchStatusCallback(Camera_Manager* cameraManager, OH_CameraManager_TorchStatusCallback torchStatusCallback)](#oh_cameramanager_registertorchstatuscallback) | - | Registers a callback to listen for flashlight status changes.|
| [Camera_ErrorCode OH_CameraManager_UnregisterTorchStatusCallback(Camera_Manager* cameraManager, OH_CameraManager_TorchStatusCallback torchStatusCallback)](#oh_cameramanager_unregistertorchstatuscallback) | - | Unregisters the callback used to listen for flashlight status changes.|
| [Camera_ErrorCode OH_CameraManager_RegisterFoldStatusInfoCallback(Camera_Manager* cameraManager, OH_CameraManager_OnFoldStatusInfoChange foldStatusInfoCallback)](#oh_cameramanager_registerfoldstatusinfocallback) | - | Registers a callback to listen for fold status changes.|
| [Camera_ErrorCode OH_CameraManager_UnregisterFoldStatusInfoCallback(Camera_Manager* cameraManager, OH_CameraManager_OnFoldStatusInfoChange foldStatusInfoCallback)](#oh_cameramanager_unregisterfoldstatusinfocallback) | - | Unregisters the callback used to listen for fold status changes.|
| [Camera_ErrorCode OH_CameraManager_GetSupportedCameras(Camera_Manager* cameraManager, Camera_Device** cameras, uint32_t* size)](#oh_cameramanager_getsupportedcameras) | - | Obtains the supported cameras.|
| [Camera_ErrorCode OH_CameraManager_DeleteSupportedCameras(Camera_Manager* cameraManager, Camera_Device* cameras, uint32_t size)](#oh_cameramanager_deletesupportedcameras) | - | Deletes supported cameras.|
| [Camera_ErrorCode OH_CameraManager_GetSupportedCameraOutputCapability(Camera_Manager* cameraManager, const Camera_Device* camera, Camera_OutputCapability** cameraOutputCapability)](#oh_cameramanager_getsupportedcameraoutputcapability) | - | Obtains the output capability supported by a camera.|
| [Camera_ErrorCode OH_CameraManager_GetSupportedCameraOutputCapabilityWithSceneMode(Camera_Manager* cameraManager, const Camera_Device* camera, Camera_SceneMode sceneMode, Camera_OutputCapability** cameraOutputCapability)](#oh_cameramanager_getsupportedcameraoutputcapabilitywithscenemode) | - | Obtains the output capability supported by a camera in the specified mode.|
| [Camera_ErrorCode OH_CameraManager_GetSupportedFullCameraOutputCapabilityWithSceneMode(Camera_Manager* cameraManager, const Camera_Device* camera, Camera_SceneMode sceneMode, Camera_OutputCapability** cameraOutputCapability)](#oh_cameramanager_getsupportedfullcameraoutputcapabilitywithscenemode) | - | Obtains the complete output capabilities supported by a specified camera in a specified mode, including YUV, HEIF, and HDR. Before using YUV, HEIF, or HDR, you need to explicitly call this method to ensure that the complete output capabilities are obtained.|
| [Camera_ErrorCode OH_CameraManager_DeleteSupportedCameraOutputCapability(Camera_Manager* cameraManager, Camera_OutputCapability* cameraOutputCapability)](#oh_cameramanager_deletesupportedcameraoutputcapability) | - | Deletes the output capability supported by a camera.|
| [Camera_ErrorCode OH_CameraManager_IsCameraMuted(Camera_Manager* cameraManager, bool* isCameraMuted)](#oh_cameramanager_iscameramuted) | - | Checks whether a camera is muted.|
| [Camera_ErrorCode OH_CameraManager_CreateCaptureSession(Camera_Manager* cameraManager, Camera_CaptureSession** captureSession)](#oh_cameramanager_createcapturesession) | - | Creates a **CaptureSession** instance.|
| [Camera_ErrorCode OH_CameraManager_CreateCameraInput(Camera_Manager* cameraManager, const Camera_Device* camera, Camera_Input** cameraInput)](#oh_cameramanager_createcamerainput) | - | Creates a **Camera_Input** instance.|
| [Camera_ErrorCode OH_CameraManager_CreateCameraInput_WithPositionAndType(Camera_Manager* cameraManager, Camera_Position position, Camera_Type type, Camera_Input** cameraInput)](#oh_cameramanager_createcamerainput_withpositionandtype) | - | Creates a **Camera_Input** instance with the specified camera position and type.|
| [Camera_ErrorCode OH_CameraManager_CreatePreviewOutput(Camera_Manager* cameraManager, const Camera_Profile* profile, const char* surfaceId, Camera_PreviewOutput** previewOutput)](#oh_cameramanager_createpreviewoutput) | - | Creates a **PreviewOutput** instance.|
| [Camera_ErrorCode OH_CameraManager_CreateDeferredPreviewOutput(const Camera_Manager* cameraManager, const Camera_Profile* profile, Camera_PreviewOutput** previewOutput)](#oh_cameramanager_createdeferredpreviewoutput) | - | Creates a deferred **PreviewOutput** instance. After using the instance, call [OH_PreviewOutput_Release](capi-preview-output-h.md#oh_previewoutput_release) to release it.|
| [Camera_ErrorCode OH_CameraManager_CreatePreviewOutputUsedInPreconfig(Camera_Manager* cameraManager, const char* surfaceId, Camera_PreviewOutput** previewOutput)](#oh_cameramanager_createpreviewoutputusedinpreconfig) | - | Creates a **PreviewOutput** instance to be used in a preconfiguration stream.|
| [Camera_ErrorCode OH_CameraManager_CreatePhotoOutput(Camera_Manager* cameraManager, const Camera_Profile* profile, const char* surfaceId, Camera_PhotoOutput** photoOutput)](#oh_cameramanager_createphotooutput) | - | Creates a **PhotoOutput** instance. This API can only be used to create a **PhotoOutput** object in JPEG format.|
| [Camera_ErrorCode OH_CameraManager_CreatePhotoOutputUsedInPreconfig(Camera_Manager* cameraManager, const char* surfaceId, Camera_PhotoOutput** photoOutput)](#oh_cameramanager_createphotooutputusedinpreconfig) | - | Creates a **PhotoOutput** instance to be used in a preconfiguration stream.|
| [Camera_ErrorCode OH_CameraManager_CreatePhotoOutputWithoutSurface(Camera_Manager *cameraManager, const Camera_Profile *profile, Camera_PhotoOutput **photoOutput)](#oh_cameramanager_createphotooutputwithoutsurface) | - | Creates a **PhotoOutput** instance. **surfaceId** is not required in this function.|
| [Camera_ErrorCode OH_CameraManager_CreateVideoOutput(Camera_Manager* cameraManager, const Camera_VideoProfile* profile, const char* surfaceId, Camera_VideoOutput** videoOutput)](#oh_cameramanager_createvideooutput) | - | Creates a **VideoOutput** instance.|
| [Camera_ErrorCode OH_CameraManager_CreateVideoOutputUsedInPreconfig(Camera_Manager* cameraManager, const char* surfaceId, Camera_VideoOutput** videoOutput)](#oh_cameramanager_createvideooutputusedinpreconfig) | - | Creates a **VideoOutput** instance to be used in a preconfiguration stream.|
| [Camera_ErrorCode OH_CameraManager_CreateMetadataOutput(Camera_Manager* cameraManager, const Camera_MetadataObjectType* profile, Camera_MetadataOutput** metadataOutput)](#oh_cameramanager_createmetadataoutput) | - | Creates a **MetadataOutput** instance.|
| [Camera_ErrorCode OH_CameraManager_CreateMetadataOutputWithObjectTypes(Camera_Manager* cameraManager, const Camera_MetadataObjectType* metadataObjectTypes, uint32_t size, Camera_MetadataOutput** metadataOutput)](#oh_cameramanager_createmetadataoutputwithobjecttypes) | - | Creates a **metadataOutput** instance using an array of metadata object types.|
| [Camera_ErrorCode OH_CameraManager_GetSupportedSceneModes(Camera_Device* camera, Camera_SceneMode** sceneModes, uint32_t* size)](#oh_cameramanager_getsupportedscenemodes) | - | Obtains the scene modes supported by a camera.|
| [Camera_ErrorCode OH_CameraManager_DeleteSceneModes(Camera_Manager* cameraManager, Camera_SceneMode* sceneModes)](#oh_cameramanager_deletescenemodes) | - | Deletes scene modes.|
| [Camera_ErrorCode OH_CameraManager_IsTorchSupported(Camera_Manager* cameraManager, bool* isTorchSupported)](#oh_cameramanager_istorchsupported) | - | Checks whether the device supports the flashlight.|
| [Camera_ErrorCode OH_CameraManager_IsTorchSupportedByTorchMode(Camera_Manager* cameraManager, Camera_TorchMode torchMode, bool* isTorchSupported)](#oh_cameramanager_istorchsupportedbytorchmode) | - | Checks whether the device supports the specified flashlight mode.|
| [Camera_ErrorCode OH_CameraManager_SetTorchMode(Camera_Manager* cameraManager, Camera_TorchMode torchMode)](#oh_cameramanager_settorchmode) | - | Sets a flashlight mode.|
| [Camera_ErrorCode OH_CameraManager_IsTorchLevelControlSupported(const Camera_Manager* cameraManager, bool* isTorchLevelControlSupported)](#oh_cameramanager_istorchlevelcontrolsupported) | - | Checks whether the device supports flashlight brightness control.|
| [Camera_ErrorCode OH_CameraManager_SetTorchModeOnWithLevel(Camera_Manager* cameraManager, double torchLevel)](#oh_cameramanager_settorchmodeonwithlevel) | - | Turns on the flashlight and sets the brightness level. |
| [Camera_ErrorCode OH_CameraManager_GetCameraDevice(Camera_Manager* cameraManager, Camera_Position position, Camera_Type type, Camera_Device* camera)](#oh_cameramanager_getcameradevice) | - | Obtains the specified camera based on the camera position and type.|
| [Camera_ErrorCode OH_CameraManager_GetCameraDevices(Camera_Manager* cameraManager, Camera_DeviceQueryInfo* deviceQueryInfo, uint32_t* cameraSize, Camera_Device** cameras)](#oh_cameramanager_getcameradevices) | - | Obtains the list of cameras that meet the search criteria based on the camera position, camera types, and connection type.|
| [Camera_ErrorCode OH_CameraManager_DeleteCameraDevices(Camera_Manager* cameraManager, Camera_Device* cameras)](#oh_cameramanager_deletecameradevices) | - | Deletes the specified camera.|
| [Camera_ErrorCode OH_CameraManager_GetCameraConcurrentInfos(Camera_Manager* cameraManager, const Camera_Device* camera, uint32_t deviceSize, Camera_ConcurrentInfo** cameraConcurrentInfo, uint32_t* infoSize)](#oh_cameramanager_getcameraconcurrentinfos) | - | Obtains the concurrency information of the specified cameras.|

## Function Description

### OH_CameraManager_StatusCallback()

```c
typedef void (*OH_CameraManager_StatusCallback)(Camera_Manager* cameraManager, Camera_StatusInfo* status)
```

**Description**

Defines the callback defined in the [CameraManager_Callbacks](capi-oh-camera-cameramanager-callbacks.md) struct and used to report the camera manager status.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_Manager](capi-oh-camera-camera-manager.md)* cameraManager | Pointer to the **Camera_Manager** instance that transfers the callback.|
| [Camera_StatusInfo](capi-oh-camera-camera-statusinfo.md)* status | Pointer to the status information of each camera.|

### OH_CameraManager_TorchStatusCallback()

```c
typedef void (*OH_CameraManager_TorchStatusCallback)(Camera_Manager* cameraManager, Camera_TorchStatusInfo* status)
```

**Description**

Defines the callback to listen for flashlight status changes.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_Manager](capi-oh-camera-camera-manager.md)* cameraManager | Pointer to the **Camera_Manager** instance that transfers the callback.|
| [Camera_TorchStatusInfo](capi-oh-camera-camera-torchstatusinfo.md)* status | Pointer to the flashlight status information.|

### OH_CameraManager_OnFoldStatusInfoChange()

```c
typedef void (*OH_CameraManager_OnFoldStatusInfoChange)(Camera_Manager* cameraManager, Camera_FoldStatusInfo* foldStatusInfo)
```

**Description**

Defines the callback to listen for fold status changes of the camera manager.

**Since**: 13

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_Manager](capi-oh-camera-camera-manager.md)* cameraManager | Pointer to the **Camera_Manager** instance that transfers the callback.|
| [Camera_FoldStatusInfo](capi-oh-camera-camera-foldstatusinfo.md)* foldStatusInfo | Pointer to the fold status information of the device.|

### OH_CameraManager_RegisterCallback()

```c
Camera_ErrorCode OH_CameraManager_RegisterCallback(Camera_Manager* cameraManager, CameraManager_Callbacks* callback)
```

**Description**

Registers a callback to listen for camera status changes.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_Manager](capi-oh-camera-camera-manager.md)* cameraManager | Pointer to the **Camera_Manager** instance.|
| [CameraManager_Callbacks](capi-oh-camera-cameramanager-callbacks.md)* callback | Pointer to the target callback.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_CameraManager_UnregisterCallback()

```c
Camera_ErrorCode OH_CameraManager_UnregisterCallback(Camera_Manager* cameraManager, CameraManager_Callbacks* callback)
```

**Description**

Unregisters the callback used to listen for camera status changes.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_Manager](capi-oh-camera-camera-manager.md)* cameraManager | Pointer to the **Camera_Manager** instance.|
| [CameraManager_Callbacks](capi-oh-camera-cameramanager-callbacks.md)* callback | Pointer to the target callback.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_CameraManager_RegisterTorchStatusCallback()

```c
Camera_ErrorCode OH_CameraManager_RegisterTorchStatusCallback(Camera_Manager* cameraManager, OH_CameraManager_TorchStatusCallback torchStatusCallback)
```

**Description**

Registers a callback to listen for flashlight status changes.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_Manager](capi-oh-camera-camera-manager.md)* cameraManager | Pointer to the **Camera_Manager** instance.|
| [OH_CameraManager_TorchStatusCallback](capi-camera-manager-h.md#oh_cameramanager_torchstatuscallback) torchStatusCallback | Target callback.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_CameraManager_UnregisterTorchStatusCallback()

```c
Camera_ErrorCode OH_CameraManager_UnregisterTorchStatusCallback(Camera_Manager* cameraManager, OH_CameraManager_TorchStatusCallback torchStatusCallback)
```

**Description**

Unregisters the callback used to listen for flashlight status changes.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_Manager](capi-oh-camera-camera-manager.md)* cameraManager | Pointer to the **Camera_Manager** instance.|
| [OH_CameraManager_TorchStatusCallback](capi-camera-manager-h.md#oh_cameramanager_torchstatuscallback) torchStatusCallback | Target callback.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_CameraManager_RegisterFoldStatusInfoCallback()

```c
Camera_ErrorCode OH_CameraManager_RegisterFoldStatusInfoCallback(Camera_Manager* cameraManager, OH_CameraManager_OnFoldStatusInfoChange foldStatusInfoCallback)
```

**Description**

Registers a callback to listen for fold status changes.

**Since**: 13

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_Manager](capi-oh-camera-camera-manager.md)* cameraManager | Pointer to the **Camera_Manager** instance.|
| [OH_CameraManager_OnFoldStatusInfoChange](capi-camera-manager-h.md#oh_cameramanager_onfoldstatusinfochange) foldStatusInfoCallback | Target callback.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_CameraManager_UnregisterFoldStatusInfoCallback()

```c
Camera_ErrorCode OH_CameraManager_UnregisterFoldStatusInfoCallback(Camera_Manager* cameraManager, OH_CameraManager_OnFoldStatusInfoChange foldStatusInfoCallback)
```

**Description**

Unregisters the callback used to listen for fold status changes.

**Since**: 13

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_Manager](capi-oh-camera-camera-manager.md)* cameraManager | Pointer to the **Camera_Manager** instance.|
| [OH_CameraManager_OnFoldStatusInfoChange](capi-camera-manager-h.md#oh_cameramanager_onfoldstatusinfochange) foldStatusInfoCallback | Target callback.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_CameraManager_GetSupportedCameras()

```c
Camera_ErrorCode OH_CameraManager_GetSupportedCameras(Camera_Manager* cameraManager, Camera_Device** cameras, uint32_t* size)
```

**Description**

Obtains the supported cameras.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_Manager](capi-oh-camera-camera-manager.md)* cameraManager | Pointer to the **Camera_Manager** instance.|
| [Camera_Device](capi-oh-camera-camera-device.md)** cameras | Double pointer to the list of cameras, which are defined in the Camera_Device struct, if the function is successfully called.|
| uint32_t* size | Pointer to the size of the list of cameras.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_CameraManager_DeleteSupportedCameras()

```c
Camera_ErrorCode OH_CameraManager_DeleteSupportedCameras(Camera_Manager* cameraManager, Camera_Device* cameras, uint32_t size)
```

**Description**

Deletes supported cameras.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_Manager](capi-oh-camera-camera-manager.md)* cameraManager | Pointer to the **Camera_Manager** instance.|
| [Camera_Device](capi-oh-camera-camera-device.md)* cameras | Pointer to a list of cameras, which are defined in the Camera_Device struct.|
| uint32_t size | Number of cameras to delete.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_CameraManager_GetSupportedCameraOutputCapability()

```c
Camera_ErrorCode OH_CameraManager_GetSupportedCameraOutputCapability(Camera_Manager* cameraManager, const Camera_Device* camera, Camera_OutputCapability** cameraOutputCapability)
```

**Description**

Obtains the output capability supported by a camera.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_Manager](capi-oh-camera-camera-manager.md)* cameraManager | Pointer to the **Camera_Manager** instance.|
| [const Camera_Device](capi-oh-camera-camera-device.md)* camera | Pointer to the **Camera_Device** instance.|
| [Camera_OutputCapability](capi-oh-camera-camera-outputcapability.md)** cameraOutputCapability | Double pointer to the output capability, which is defined in the Camera_OutputCapability struct, if the function is successfully called.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_CameraManager_GetSupportedCameraOutputCapabilityWithSceneMode()

```c
Camera_ErrorCode OH_CameraManager_GetSupportedCameraOutputCapabilityWithSceneMode(Camera_Manager* cameraManager, const Camera_Device* camera, Camera_SceneMode sceneMode, Camera_OutputCapability** cameraOutputCapability)
```

**Description**

Obtains the output capability supported by a camera in the specified mode.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_Manager](capi-oh-camera-camera-manager.md)* cameraManager | Pointer to the **Camera_Manager** instance.|
| [const Camera_Device](capi-oh-camera-camera-device.md)* camera | Pointer to the **Camera_Device** instance.|
| [Camera_SceneMode](capi-camera-h.md#camera_scenemode) sceneMode | Scene mode.|
| [Camera_OutputCapability](capi-oh-camera-camera-outputcapability.md)** cameraOutputCapability | Double pointer to output capability, which is defined in the **Camera_OutputCapability** struct, if the function is successfully called.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal.|

### OH_CameraManager_GetSupportedFullCameraOutputCapabilityWithSceneMode()

```c
Camera_ErrorCode OH_CameraManager_GetSupportedFullCameraOutputCapabilityWithSceneMode(Camera_Manager* cameraManager, const Camera_Device* camera, Camera_SceneMode sceneMode, Camera_OutputCapability** cameraOutputCapability)
```

**Description**

Obtains the complete output capabilities supported by a specified camera in a specified mode, including YUV, HEIF, and HDR. Before using YUV, HEIF, or HDR, you need to explicitly call this method to ensure that the complete output capabilities are obtained.

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_Manager](capi-oh-camera-camera-manager.md)* cameraManager | Pointer to the **Camera_Manager** instance.|
| [const Camera_Device](capi-oh-camera-camera-device.md)* camera | Pointer to the **Camera_Device** instance.|
| [Camera_SceneMode](capi-camera-h.md#camera_scenemode) sceneMode | Scene mode.|
| [Camera_OutputCapability](capi-oh-camera-camera-outputcapability.md)** cameraOutputCapability | Double pointer to output capability, which is defined in the **Camera_OutputCapability** struct, if the function is successfully called.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal.|

### OH_CameraManager_DeleteSupportedCameraOutputCapability()

```c
Camera_ErrorCode OH_CameraManager_DeleteSupportedCameraOutputCapability(Camera_Manager* cameraManager, Camera_OutputCapability* cameraOutputCapability)
```

**Description**

Deletes the output capability supported by a camera.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_Manager](capi-oh-camera-camera-manager.md)* cameraManager | Pointer to the **Camera_Manager** instance.|
| [Camera_OutputCapability](capi-oh-camera-camera-outputcapability.md)* cameraOutputCapability | Pointer to the output capability, which is defined in the **Camera_OutputCapability** struct.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_CameraManager_IsCameraMuted()

```c
Camera_ErrorCode OH_CameraManager_IsCameraMuted(Camera_Manager* cameraManager, bool* isCameraMuted)
```

**Description**

Checks whether a camera is muted.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_Manager](capi-oh-camera-camera-manager.md)* cameraManager | Pointer to the **Camera_Manager** instance.|
| bool* isCameraMuted | Pointer to the check result for whether the camera is muted, if the function is successfully called. **true** if muted, **false** otherwise.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_CameraManager_CreateCaptureSession()

```c
Camera_ErrorCode OH_CameraManager_CreateCaptureSession(Camera_Manager* cameraManager, Camera_CaptureSession** captureSession)
```

**Description**

Creates a **CaptureSession** instance.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_Manager](capi-oh-camera-camera-manager.md)* cameraManager | Pointer to the **Camera_Manager** instance.|
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)** captureSession | Double pointer to the **Camera_CaptureSession** instance created, if the function is successfully called.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal.|

### OH_CameraManager_CreateCameraInput()

```c
Camera_ErrorCode OH_CameraManager_CreateCameraInput(Camera_Manager* cameraManager, const Camera_Device* camera, Camera_Input** cameraInput)
```

**Description**

Creates a **Camera_Input** instance.

**Required permissions**: ohos.permission.CAMERA

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_Manager](capi-oh-camera-camera-manager.md)* cameraManager | Pointer to the **Camera_Manager** instance.|
| [const Camera_Device](capi-oh-camera-camera-device.md)* camera | Pointer to the **Camera_Device** instance.|
| [Camera_Input](capi-oh-camera-camera-input.md)** cameraInput | Double pointer to the **Camera_Input** instance created, if the function is successfully called.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal.|

### OH_CameraManager_CreateCameraInput_WithPositionAndType()

```c
Camera_ErrorCode OH_CameraManager_CreateCameraInput_WithPositionAndType(Camera_Manager* cameraManager, Camera_Position position, Camera_Type type, Camera_Input** cameraInput)
```

**Description**

Creates a **Camera_Input** instance with the specified camera position and type.

**Required permissions**: ohos.permission.CAMERA

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_Manager](capi-oh-camera-camera-manager.md)* cameraManager | Pointer to the **Camera_Manager** instance.|
| [Camera_Position](capi-camera-h.md#camera_position) position | Camera position.|
| [Camera_Type](capi-camera-h.md#camera_type) type | Camera type.|
| [Camera_Input](capi-oh-camera-camera-input.md)** cameraInput | Double pointer to the **Camera_Input** instance created, if the function is successfully called.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal.|

### OH_CameraManager_CreatePreviewOutput()

```c
Camera_ErrorCode OH_CameraManager_CreatePreviewOutput(Camera_Manager* cameraManager, const Camera_Profile* profile, const char* surfaceId, Camera_PreviewOutput** previewOutput)
```

**Description**

Creates a **PreviewOutput** instance.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_Manager](capi-oh-camera-camera-manager.md)* cameraManager | Pointer to the **Camera_Manager** instance.|
| [const Camera_Profile](capi-oh-camera-camera-profile.md)* profile | Pointer to the profile used for creating the **Camera_PreviewOutput** instance.|
| const char* surfaceId | Pointer to the surface ID used for creating the **Camera_PreviewOutput** instance.|
| [Camera_PreviewOutput](capi-oh-camera-camera-previewoutput.md)** previewOutput | Double pointer to the **Camera_PreviewOutput** instance created, if the function is successfully called.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal.|

### OH_CameraManager_CreateDeferredPreviewOutput()

```c
Camera_ErrorCode OH_CameraManager_CreateDeferredPreviewOutput(const Camera_Manager* cameraManager, const Camera_Profile* profile, Camera_PreviewOutput** previewOutput)
```

**Description**

Creates a deferred **PreviewOutput** instance. After using the instance, call [OH_PreviewOutput_Release](capi-preview-output-h.md#oh_previewoutput_release) to release it.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [const Camera_Manager](capi-oh-camera-camera-manager.md)* cameraManager | Pointer to the **Camera_Manager** instance.|
| [const Camera_Profile](capi-oh-camera-camera-profile.md)* profile | Pointer to the profile used for creating the **Camera_PreviewOutput** instance.|
| [Camera_PreviewOutput](capi-oh-camera-camera-previewoutput.md)** previewOutput | Double pointer to the **Camera_PreviewOutput** instance created, if the function is successfully called.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal.|

### OH_CameraManager_CreatePreviewOutputUsedInPreconfig()

```c
Camera_ErrorCode OH_CameraManager_CreatePreviewOutputUsedInPreconfig(Camera_Manager* cameraManager, const char* surfaceId, Camera_PreviewOutput** previewOutput)
```

**Description**

Creates a **PreviewOutput** instance to be used in a preconfiguration stream.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_Manager](capi-oh-camera-camera-manager.md)* cameraManager | Pointer to the **Camera_Manager** instance.|
| const char* surfaceId | Pointer to the surface ID used for creating the **Camera_PreviewOutput** instance.|
| [Camera_PreviewOutput](capi-oh-camera-camera-previewoutput.md)** previewOutput | Double pointer to the **Camera_PreviewOutput** instance created, if the function is successfully called.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal.|

### OH_CameraManager_CreatePhotoOutput()

```c
Camera_ErrorCode OH_CameraManager_CreatePhotoOutput(Camera_Manager* cameraManager, const Camera_Profile* profile, const char* surfaceId, Camera_PhotoOutput** photoOutput)
```

**Description**

Creates a **PhotoOutput** instance. This API can only be used to create a **PhotoOutput** object in JPEG format.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_Manager](capi-oh-camera-camera-manager.md)* cameraManager | Pointer to the **Camera_Manager** instance.|
| [const Camera_Profile](capi-oh-camera-camera-profile.md)* profile | Pointer to the profile used for creating the **Camera_PhotoOutput** instance.|
| const char* surfaceId | Pointer to the surface ID used for creating the **Camera_PhotoOutput** instance.|
| [Camera_PhotoOutput](capi-oh-camera-camera-photooutput.md)** photoOutput | Double pointer to the **Camera_PhotoOutput** instance created, if the function is successfully called.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal.|

### OH_CameraManager_CreatePhotoOutputUsedInPreconfig()

```c
Camera_ErrorCode OH_CameraManager_CreatePhotoOutputUsedInPreconfig(Camera_Manager* cameraManager, const char* surfaceId, Camera_PhotoOutput** photoOutput)
```

**Description**

Creates a **PhotoOutput** instance to be used in a preconfiguration stream.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_Manager](capi-oh-camera-camera-manager.md)* cameraManager | Pointer to the **Camera_Manager** instance.|
| const char* surfaceId | Pointer to the surface ID used for creating the **Camera_PhotoOutput** instance.|
| [Camera_PhotoOutput](capi-oh-camera-camera-photooutput.md)** photoOutput | Double pointer to the **Camera_PhotoOutput** instance created, if the function is successfully called.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal.|

### OH_CameraManager_CreatePhotoOutputWithoutSurface()

```c
Camera_ErrorCode OH_CameraManager_CreatePhotoOutputWithoutSurface(Camera_Manager *cameraManager, const Camera_Profile *profile, Camera_PhotoOutput **photoOutput)
```

**Description**

Creates a **PhotoOutput** instance. **surfaceId** is not required in this function.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_Manager](capi-oh-camera-camera-manager.md) *cameraManager | Pointer to the **Camera_Manager** instance.|
| [const Camera_Profile](capi-oh-camera-camera-profile.md) *profile | Pointer to the profile used for creating the **Camera_PhotoOutput** instance.|
| [Camera_PhotoOutput](capi-oh-camera-camera-photooutput.md) **photoOutput | Double pointer to the **Camera_PhotoOutput** instance created, if the function is successfully called.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal.|

### OH_CameraManager_CreateVideoOutput()

```c
Camera_ErrorCode OH_CameraManager_CreateVideoOutput(Camera_Manager* cameraManager, const Camera_VideoProfile* profile, const char* surfaceId, Camera_VideoOutput** videoOutput)
```

**Description**

Creates a **VideoOutput** instance.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_Manager](capi-oh-camera-camera-manager.md)* cameraManager | Pointer to the **Camera_Manager** instance.|
| [const Camera_VideoProfile](capi-oh-camera-camera-videoprofile.md)* profile | Pointer to the profile for creating the **Camera_VideoOutput** instance.|
| const char* surfaceId | Pointer to the surface ID used for creating the **Camera_VideoOutput** instance.|
| [Camera_VideoOutput](capi-oh-camera-camera-videooutput.md)** videoOutput | Double pointer to the **Camera_VideoOutput** instance created, if the function is successfully called.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal.|

### OH_CameraManager_CreateVideoOutputUsedInPreconfig()

```c
Camera_ErrorCode OH_CameraManager_CreateVideoOutputUsedInPreconfig(Camera_Manager* cameraManager, const char* surfaceId, Camera_VideoOutput** videoOutput)
```

**Description**

Creates a **VideoOutput** instance to be used in a preconfiguration stream.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_Manager](capi-oh-camera-camera-manager.md)* cameraManager | Pointer to the **Camera_Manager** instance.|
| const char* surfaceId | Pointer to the surface ID used for creating the **Camera_VideoOutput** instance.|
| [Camera_VideoOutput](capi-oh-camera-camera-videooutput.md)** videoOutput | Double pointer to the **Camera_VideoOutput** instance created, if the function is successfully called.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal.|

### OH_CameraManager_CreateMetadataOutput()

```c
Camera_ErrorCode OH_CameraManager_CreateMetadataOutput(Camera_Manager* cameraManager, const Camera_MetadataObjectType* profile, Camera_MetadataOutput** metadataOutput)
```

**Description**

Creates a **MetadataOutput** instance.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_Manager](capi-oh-camera-camera-manager.md)* cameraManager | Pointer to the **Camera_Manager** instance.|
| [const Camera_MetadataObjectType](capi-camera-h.md#camera_metadataobjecttype)* profile | Pointer to the metadata object type used for creating the **Camera_MetadataOutput** instance.|
| [Camera_MetadataOutput](capi-oh-camera-camera-metadataoutput.md)** metadataOutput | Double pointer to the **Camera_MetadataOutput** instance created, if the function is successfully called.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal.|

### OH_CameraManager_CreateMetadataOutputWithObjectTypes()

```c
Camera_ErrorCode OH_CameraManager_CreateMetadataOutputWithObjectTypes(Camera_Manager* cameraManager, const Camera_MetadataObjectType* metadataObjectTypes, uint32_t size, Camera_MetadataOutput** metadataOutput)
```

**Description**

Creates a **metadataOutput** instance using an array of metadata object types.

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_Manager](capi-oh-camera-camera-manager.md)* cameraManager | Pointer to the **Camera_Manager** instance.|
| [const Camera_MetadataObjectType](capi-camera-h.md#camera_metadataobjecttype)* metadataObjectTypes | Pointer to the metadata object types used for creating the **Camera_MetadataOutput** instance.|
| uint32_t size | Length of the metadata object type array.|
| [Camera_MetadataOutput](capi-oh-camera-camera-metadataoutput.md)** metadataOutput | Double pointer to the **Camera_MetadataOutput** instance created, if the function is successfully called.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal.|

### OH_CameraManager_GetSupportedSceneModes()

```c
Camera_ErrorCode OH_CameraManager_GetSupportedSceneModes(Camera_Device* camera, Camera_SceneMode** sceneModes, uint32_t* size)
```

**Description**

Obtains the scene modes supported by a camera.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_Device](capi-oh-camera-camera-device.md)* camera | Pointer to the **Camera_Device** instance.|
| [Camera_SceneMode](capi-camera-h.md#camera_scenemode)** sceneModes | Double pointer to the list of scene modes, which are defined in the Camera_SceneMode struct, if the function is successfully called.|
| uint32_t* size | Pointer to the size of the list of scene modes.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal.|

### OH_CameraManager_DeleteSceneModes()

```c
Camera_ErrorCode OH_CameraManager_DeleteSceneModes(Camera_Manager* cameraManager, Camera_SceneMode* sceneModes)
```

**Description**

Deletes scene modes.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_Manager](capi-oh-camera-camera-manager.md)* cameraManager | Pointer to the **Camera_Manager** instance.|
| [Camera_SceneMode](capi-camera-h.md#camera_scenemode)* sceneModes | Pointer to the list of scene modes to delete.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_CameraManager_IsTorchSupported()

```c
Camera_ErrorCode OH_CameraManager_IsTorchSupported(Camera_Manager* cameraManager, bool* isTorchSupported)
```

**Description**

Checks whether the device supports the flashlight.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_Manager](capi-oh-camera-camera-manager.md)* cameraManager | Pointer to the **Camera_Manager** instance.|
| bool* isTorchSupported | Pointer to the check result for the support of the flashlight. **true** if supported, **false** otherwise.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_CameraManager_IsTorchSupportedByTorchMode()

```c
Camera_ErrorCode OH_CameraManager_IsTorchSupportedByTorchMode(Camera_Manager* cameraManager, Camera_TorchMode torchMode, bool* isTorchSupported)
```

**Description**

Checks whether the device supports the specified flashlight mode.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_Manager](capi-oh-camera-camera-manager.md)* cameraManager | Pointer to the **Camera_Manager** instance.|
| [Camera_TorchMode](capi-camera-h.md#camera_torchmode) torchMode | Flashlight mode to check.|
| bool* isTorchSupported | Pointer to the check result for the support of the flashlight mode. **true** if supported, **false** otherwise.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal.|

### OH_CameraManager_SetTorchMode()

```c
Camera_ErrorCode OH_CameraManager_SetTorchMode(Camera_Manager* cameraManager, Camera_TorchMode torchMode)
```

**Description**

Sets a flashlight mode.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_Manager](capi-oh-camera-camera-manager.md)* cameraManager | Pointer to the **Camera_Manager** instance.|
| [Camera_TorchMode](capi-camera-h.md#camera_torchmode) torchMode | Flashlight mode to set.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal.|

### OH_CameraManager_IsTorchLevelControlSupported()

```c
Camera_ErrorCode OH_CameraManager_IsTorchLevelControlSupported(const Camera_Manager* cameraManager, bool* isTorchLevelControlSupported)
```

**Description**

Checks whether the device supports flashlight brightness control.

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [const Camera_Manager](capi-oh-camera-camera-manager.md)* cameraManager | Pointer to the **Camera_Manager** instance.|
| bool* isTorchLevelControlSupported | Whether the device supports flashlight brightness control.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal.|

### OH_CameraManager_SetTorchModeOnWithLevel()

```c
Camera_ErrorCode OH_CameraManager_SetTorchModeOnWithLevel(Camera_Manager* cameraManager, double torchLevel)
```

**Description**

Turns on the flashlight and sets the brightness level.

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [const Camera_Manager](capi-oh-camera-camera-manager.md)* cameraManager | Pointer to the **Camera_Manager** instance.|
| double torchLevel | Target brightness level. The value range is [0.0, 1.0].|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal.|

### OH_CameraManager_GetCameraDevice()

```c
Camera_ErrorCode OH_CameraManager_GetCameraDevice(Camera_Manager* cameraManager, Camera_Position position, Camera_Type type, Camera_Device* camera)
```

**Description**

Obtains the specified camera based on the camera position and type.

Obtains the camera lens of the specified [Camera_Position](capi-camera-h.md#camera_position) and [Camera_Type](capi-camera-h.md#camera_type). If the returned result is **CAMERA_SERVICE_FATAL_ERROR**, the camera lens is not found on the current device.

**Since**: 18

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_Manager](capi-oh-camera-camera-manager.md)* cameraManager | Pointer to the **Camera_Manager** instance.|
| [Camera_Position](capi-camera-h.md#camera_position) position | Camera position.|
| [Camera_Type](capi-camera-h.md#camera_type) type | Camera type.|
| [Camera_Device](capi-oh-camera-camera-device.md)* camera | Pointer to the **Camera_Device** instance.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal.|

### OH_CameraManager_GetCameraDevices()

```c
Camera_ErrorCode OH_CameraManager_GetCameraDevices(Camera_Manager* cameraManager, Camera_DeviceQueryInfo* deviceQueryInfo, uint32_t* cameraSize, Camera_Device** cameras)
```

**Description**

Obtains the list of cameras that meet the search criteria based on the camera position, camera types, and connection type.

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_Manager](capi-oh-camera-camera-manager.md)* cameraManager | Pointer to the **Camera_Manager** instance.|
| [Camera_DeviceQueryInfo](capi-oh-camera-camera-devicequeryinfo.md)* deviceQueryInfo | Camera device query information instance.|
| uint32_t* cameraSize | Size of the list of supported cameras.|
| [Camera_Device](capi-oh-camera-camera-device.md)** cameras | List of supported cameras.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal.|

### OH_CameraManager_DeleteCameraDevices()

```c
Camera_ErrorCode OH_CameraManager_DeleteCameraDevices(Camera_Manager* cameraManager, Camera_Device* cameras)
```

**Description**

Deletes the specified camera.

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_Manager](capi-oh-camera-camera-manager.md)* cameraManager | Pointer to the **Camera_Manager** instance.|
| [Camera_Device](capi-oh-camera-camera-device.md)* cameras | List of cameras to be deleted.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_CameraManager_GetCameraConcurrentInfos()

```c
Camera_ErrorCode OH_CameraManager_GetCameraConcurrentInfos(Camera_Manager* cameraManager, const Camera_Device* camera, uint32_t deviceSize, Camera_ConcurrentInfo** cameraConcurrentInfo, uint32_t* infoSize)
```

**Description**

Obtains the concurrency information of the specified cameras.

**Since**: 18

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_Manager](capi-oh-camera-camera-manager.md)* cameraManager | Pointer to the **Camera_Manager** instance.|
| [const Camera_Device](capi-oh-camera-camera-device.md)* camera | List of cameras used for query. You are advised to set this parameter to the camera list that contains the front and rear cameras obtained using [OH_CameraManager_GetCameraDevice](capi-camera-manager-h.md#oh_cameramanager_getcameradevice).|
| uint32_t deviceSize | Length of the camera device list. The value must be set to 2 (indicating that both the front and rear cameras are used for concurrency information query).|
| [Camera_ConcurrentInfo](capi-oh-camera-camera-concurrentinfo.md)** cameraConcurrentInfo | Double pointer to an array of **Camera_ConcurrentInfo** objects representing the concurrency information of the cameras. This parameter must be set to NULL by default when being passed in.<br> If the camera supports concurrency, it is assigned the **Camera_ConcurrentInfo** array obtained.<br> If the camera does not support concurrency, the passed-in value is retained and the error code [Camera_ErrorCode](capi-camera-h.md#camera_errorcode).CAMERA_SERVICE_FATAL_ERROR is returned.|
| uint32_t* infoSize | Pointer to the length of the array. This parameter must be set to **0** by default when being passed in.<br> If the camera supports concurrency, it is assigned the length of the **Camera_ConcurrentInfo** array obtained.<br> If the camera does not support concurrency, the passed-in value is retained and the error code [Camera_ErrorCode](capi-camera-h.md#camera_errorcode).CAMERA_SERVICE_FATAL_ERROR is returned.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal, or the camera does not support concurrency.|