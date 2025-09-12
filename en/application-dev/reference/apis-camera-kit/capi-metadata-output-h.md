# metadata_output.h
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

## Overview

The file declares the metadata output concepts.

**File to include**: <ohcamera/metadata_output.h>

**Library**: libohcamera.so

**System capability**: SystemCapability.Multimedia.Camera.Core

**Since**: 11

**Related module**: [OH_Camera](capi-oh-camera.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [MetadataOutput_Callbacks](capi-oh-camera-metadataoutput-callbacks.md) | MetadataOutput_Callbacks | Describes the callbacks related to metadata output.|
| [Camera_MetadataOutput](capi-oh-camera-camera-metadataoutput.md) | Camera_MetadataOutput | Describes the metadata output object.<br> You can use [OH_CameraManager_CreateMetadataOutput](capi-camera-manager-h.md#oh_cameramanager_createmetadataoutput) to create such an object.|

### Functions

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [typedef void (\*OH_MetadataOutput_OnMetadataObjectAvailable)(Camera_MetadataOutput* metadataOutput,Camera_MetadataObject* metadataObject, uint32_t size)](#oh_metadataoutput_onmetadataobjectavailable) | OH_MetadataOutput_OnMetadataObjectAvailable | Defines the callback defined in the [MetadataOutput_Callbacks](capi-oh-camera-metadataoutput-callbacks.md) struct and used to report metadata output data.|
| [typedef void (\*OH_MetadataOutput_OnError)(Camera_MetadataOutput* metadataOutput, Camera_ErrorCode errorCode)](#oh_metadataoutput_onerror) | OH_MetadataOutput_OnError | Defines the callback defined in the [MetadataOutput_Callbacks](capi-oh-camera-metadataoutput-callbacks.md) struct and used to report metadata output errors.|
| [Camera_ErrorCode OH_MetadataOutput_RegisterCallback(Camera_MetadataOutput* metadataOutput, MetadataOutput_Callbacks* callback)](#oh_metadataoutput_registercallback) | - | Registers a callback to listen for metadata output events.|
| [Camera_ErrorCode OH_MetadataOutput_UnregisterCallback(Camera_MetadataOutput* metadataOutput, MetadataOutput_Callbacks* callback)](#oh_metadataoutput_unregistercallback) | - | Unregisters the callback used to listen for metadata output events.|
| [Camera_ErrorCode OH_MetadataOutput_Start(Camera_MetadataOutput* metadataOutput)](#oh_metadataoutput_start) | - | Starts metadata output.|
| [Camera_ErrorCode OH_MetadataOutput_Stop(Camera_MetadataOutput* metadataOutput)](#oh_metadataoutput_stop) | - | Stops metadata output.|
| [Camera_ErrorCode OH_MetadataOutput_Release(Camera_MetadataOutput* metadataOutput)](#oh_metadataoutput_release) | - | Releases a MetadataOutput instance.|

## Function Description

### OH_MetadataOutput_OnMetadataObjectAvailable()

```
typedef void (*OH_MetadataOutput_OnMetadataObjectAvailable)(Camera_MetadataOutput* metadataOutput,Camera_MetadataObject* metadataObject, uint32_t size)
```

**Description**

Defines the callback defined in the [MetadataOutput_Callbacks](capi-oh-camera-metadataoutput-callbacks.md) struct and used to report metadata output data.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [Camera_MetadataOutput](capi-oh-camera-camera-metadataoutput.md)* metadataOutput | Pointer to the MetadataOutput instance that transfers the callback.|
| [Camera_MetadataObject](capi-oh-camera-camera-metadataobject.md)* metadataObject | Pointer to the metadata output data.|
|  uint32_t size | Size of the metadata object.|

### OH_MetadataOutput_OnError()

```
typedef void (*OH_MetadataOutput_OnError)(Camera_MetadataOutput* metadataOutput, Camera_ErrorCode errorCode)
```

**Description**

Defines the callback defined in the [MetadataOutput_Callbacks](capi-oh-camera-metadataoutput-callbacks.md) struct and used to report metadata output errors.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [Camera_MetadataOutput](capi-oh-camera-camera-metadataoutput.md)* metadataOutput | Pointer to the MetadataOutput instance that transfers the callback.|
|  [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) errorCode | Error code reported during metadata output.|

**See also**

[CAMERA_SERVICE_FATAL_ERROR](capi-camera-h.md#camera_errorcode)

### OH_MetadataOutput_RegisterCallback()

```
Camera_ErrorCode OH_MetadataOutput_RegisterCallback(Camera_MetadataOutput* metadataOutput,MetadataOutput_Callbacks* callback)
```

**Description**

Registers a callback to listen for metadata output events.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [Camera_MetadataOutput](capi-oh-camera-camera-metadataoutput.md)* metadataOutput | Pointer to a MetadataOutput instance.|
| [MetadataOutput_Callbacks](capi-oh-camera-metadataoutput-callbacks.md)* callback | Pointer to the target callback.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_MetadataOutput_UnregisterCallback()

```
Camera_ErrorCode OH_MetadataOutput_UnregisterCallback(Camera_MetadataOutput* metadataOutput,MetadataOutput_Callbacks* callback)
```

**Description**

Unregisters the callback used to listen for metadata output events.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [Camera_MetadataOutput](capi-oh-camera-camera-metadataoutput.md)* metadataOutput | Pointer to a MetadataOutput instance.|
| [MetadataOutput_Callbacks](capi-oh-camera-metadataoutput-callbacks.md)* callback | Pointer to the target callback.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_MetadataOutput_Start()

```
Camera_ErrorCode OH_MetadataOutput_Start(Camera_MetadataOutput* metadataOutput)
```

**Description**

Starts metadata output.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [Camera_MetadataOutput](capi-oh-camera-camera-metadataoutput.md)* metadataOutput | Pointer to the MetadataOutput instance to start.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.<br>         **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.|

### OH_MetadataOutput_Stop()

```
Camera_ErrorCode OH_MetadataOutput_Stop(Camera_MetadataOutput* metadataOutput)
```

**Description**

Stops metadata output.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [Camera_MetadataOutput](capi-oh-camera-camera-metadataoutput.md)* metadataOutput | Pointer to the MetadataOutput instance to stop.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.|

### OH_MetadataOutput_Release()

```
Camera_ErrorCode OH_MetadataOutput_Release(Camera_MetadataOutput* metadataOutput)
```

**Description**

Releases a MetadataOutput instance.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [Camera_MetadataOutput](capi-oh-camera-camera-metadataoutput.md)* metadataOutput | Pointer to the MetadataOutput instance to release.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.|
