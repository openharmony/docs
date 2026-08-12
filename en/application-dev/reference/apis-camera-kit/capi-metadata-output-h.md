# metadata_output.h

<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=56cdd06d96371b9d5dfb0c72df61265d9cc8c54d translatedAt=2026-08-11T02:01:55.104Z pushedAt=2026-08-12T03:29:13.544Z -->

## Overview

Declares the metadata output concepts.

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
| [typedef void (\*OH_MetadataOutput_OnMetadataObjectAvailable)(Camera_MetadataOutput* metadataOutput, Camera_MetadataObject* metadataObject, uint32_t size)](#oh_metadataoutput_onmetadataobjectavailable) | OH_MetadataOutput_OnMetadataObjectAvailable | Defines the callback defined in the [MetadataOutput_Callbacks](capi-oh-camera-metadataoutput-callbacks.md) struct and used to report metadata output data.|
| [typedef void (\*OH_MetadataOutput_OnError)(Camera_MetadataOutput* metadataOutput, Camera_ErrorCode errorCode)](#oh_metadataoutput_onerror) | OH_MetadataOutput_OnError | Defines the callback defined in the [MetadataOutput_Callbacks](capi-oh-camera-metadataoutput-callbacks.md) struct and used to report metadata output errors.|
| [Camera_ErrorCode OH_MetadataOutput_RegisterCallback(Camera_MetadataOutput* metadataOutput, MetadataOutput_Callbacks* callback)](#oh_metadataoutput_registercallback) | - | Registers a callback to listen for metadata output events.|
| [Camera_ErrorCode OH_MetadataOutput_UnregisterCallback(Camera_MetadataOutput* metadataOutput, MetadataOutput_Callbacks* callback)](#oh_metadataoutput_unregistercallback) | - | Unregisters the callback used to listen for metadata output events.|
| [Camera_ErrorCode OH_MetadataOutput_Start(Camera_MetadataOutput* metadataOutput)](#oh_metadataoutput_start) | - | Starts metadata output.|
| [Camera_ErrorCode OH_MetadataOutput_Stop(Camera_MetadataOutput* metadataOutput)](#oh_metadataoutput_stop) | - | Stops metadata output.|
| [Camera_ErrorCode OH_MetadataOutput_Release(Camera_MetadataOutput* metadataOutput)](#oh_metadataoutput_release) | - | Releases a MetadataOutput instance.|
| [Camera_ErrorCode OH_MetadataOutput_AddMetadataObjectTypes(Camera_MetadataOutput* metadataOutput, Camera_MetadataObjectType* types, uint32_t size)](#oh_metadataoutput_addmetadataobjecttypes) | - | Adds the metadata object types.|
| [Camera_ErrorCode OH_MetadataOutput_RemoveMetadataObjectTypes(Camera_MetadataOutput* metadataOutput, Camera_MetadataObjectType* types, uint32_t size)](#oh_metadataoutput_removemetadataobjecttypes) | - | Removes the metadata object types.|
| [typedef void (\*OH_MetadataOutput_OnMetadataObjectExtAvailable)(void* context, OH_Camera_MetadataObjectExt** metadataObjectExt, uint32_t size)](#oh_metadataoutput_onmetadataobjectextavailable) | OH_MetadataOutput_OnMetadataObjectExtAvailable | Defines a callback to listen for metadata object reporting events. The callback can be registered by calling [OH_MetadataOutput_RegisterMetadataObjectExtAvailableCallback](capi-metadata-output-h.md#oh_metadataoutput_registermetadataobjectextavailablecallback).|
| [typedef void (\*OH_MetadataOutput_OnErrorExt)(void* context, Camera_ErrorCode errorCode)](#oh_metadataoutput_onerrorext) | OH_MetadataOutput_OnErrorExt | Defines a callback to listen for error events during metadata output.|
| [Camera_ErrorCode OH_MetadataOutput_RegisterMetadataObjectExtAvailableCallback(Camera_MetadataOutput* metadataOutput, void* context, OH_MetadataOutput_OnMetadataObjectExtAvailable callback)](#oh_metadataoutput_registermetadataobjectextavailablecallback) | - | Registers a callback to listen for metadata object report events. This callback can be unregistered using [OH_MetadataOutput_UnregisterMetadataObjectExtAvailableCallback](capi-metadata-output-h.md#oh_metadataoutput_unregistermetadataobjectextavailablecallback). |
| [Camera_ErrorCode OH_MetadataOutput_UnregisterMetadataObjectExtAvailableCallback(Camera_MetadataOutput* metadataOutput, void* context, OH_MetadataOutput_OnMetadataObjectExtAvailable callback)](#oh_metadataoutput_unregistermetadataobjectextavailablecallback) | - | Unregisters the callback used to listen for metadata object reporting events. |
| [Camera_ErrorCode OH_MetadataOutput_RegisterErrorExtCallback(Camera_MetadataOutput* metadataOutput, void* context, OH_MetadataOutput_OnErrorExt callback)](#oh_metadataoutput_registererrorextcallback) | - | Registers a callback to listen for error events. This callback can be unregistered using [OH_MetadataOutput_UnregisterErrorExtCallback](capi-metadata-output-h.md#oh_metadataoutput_unregistererrorextcallback). |
| [Camera_ErrorCode OH_MetadataOutput_UnregisterErrorExtCallback(Camera_MetadataOutput* metadataOutput, void* context, OH_MetadataOutput_OnErrorExt callback)](#oh_metadataoutput_unregistererrorextcallback) | - | Unregisters the callback used to listen for error events. |
| [bool OH_MetadataOutput_IsLockMetadataObjectTrackingSupported(const Camera_MetadataOutput* metadataOutput)](#oh_metadataoutput_islockmetadataobjecttrackingsupported) | - | Checks whether the device supports the function of locking a metadata object (such as a cat or dog face) for tracking.|
| [Camera_ErrorCode OH_MetadataOutput_LockMetadataObjectTracking(Camera_MetadataOutput* metadataOutput, Camera_Point* pointOfInterest)](#oh_metadataoutput_lockmetadataobjecttracking) | - | Locks a metadata object (such as a cat or dog face) for tracking.<br> This function tracks the object pointed to by **pointOfInterest**. If such object does not exist, this function does not take effect.<br> Locking for tracking is automatically canceled when the tracked object has left the viewfinder range for more than three seconds or the object is unlocked.|
| [Camera_ErrorCode OH_MetadataOutput_UnlockMetadataObjectTracking(Camera_MetadataOutput* metadataOutput)](#oh_metadataoutput_unlockmetadataobjecttracking) | - | Unlocks the metadata object (such as a cat or dog face) for tracking.|

## Function Description

### OH_MetadataOutput_OnMetadataObjectAvailable()

```c
typedef void (*OH_MetadataOutput_OnMetadataObjectAvailable)(Camera_MetadataOutput* metadataOutput, Camera_MetadataObject* metadataObject, uint32_t size)
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

```c
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

```c
Camera_ErrorCode OH_MetadataOutput_RegisterCallback(Camera_MetadataOutput* metadataOutput, MetadataOutput_Callbacks* callback)
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

```c
Camera_ErrorCode OH_MetadataOutput_UnregisterCallback(Camera_MetadataOutput* metadataOutput, MetadataOutput_Callbacks* callback)
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

```c
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
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.<br>         **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal.|

### OH_MetadataOutput_Stop()

```c
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
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal.|

### OH_MetadataOutput_Release()

```c
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
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal.|

### OH_MetadataOutput_AddMetadataObjectTypes()

```c
Camera_ErrorCode OH_MetadataOutput_AddMetadataObjectTypes(Camera_MetadataOutput* metadataOutput, Camera_MetadataObjectType* types, uint32_t size)
```

**Description**

Adds the metadata object types.

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_MetadataOutput](capi-oh-camera-camera-metadataoutput.md)* metadataOutput | Pointer to a MetadataOutput instance.|
| [Camera_MetadataObjectType](capi-camera-h.md#camera_metadataobjecttype)* types | Array of metadata object types to be added to the **Camera_MetadataOutput** instance.|
| uint32_t size | Length of the metadata object type array.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal.|

### OH_MetadataOutput_RemoveMetadataObjectTypes()

```c
Camera_ErrorCode OH_MetadataOutput_RemoveMetadataObjectTypes(Camera_MetadataOutput* metadataOutput, Camera_MetadataObjectType* types, uint32_t size)
```

**Description**

Removes the metadata object types.

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_MetadataOutput](capi-oh-camera-camera-metadataoutput.md)* metadataOutput | Pointer to a MetadataOutput instance.|
| [Camera_MetadataObjectType](capi-camera-h.md#camera_metadataobjecttype)* types | Array of metadata object types removed from the **Camera_MetadataOutput** instance.|
| uint32_t size | Length of the metadata object type array.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal.|

### OH_MetadataOutput_OnMetadataObjectExtAvailable()

```c
typedef void (*OH_MetadataOutput_OnMetadataObjectExtAvailable)(void* context, OH_Camera_MetadataObjectExt** metadataObjectExt, uint32_t size)
```

**Description**

Defines a callback to listen for metadata object reporting events. The callback can be registered by calling [OH_MetadataOutput_RegisterMetadataObjectExtAvailableCallback](capi-metadata-output-h.md#oh_metadataoutput_registermetadataobjectextavailablecallback).

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| void* context | Context pointer provided by the user.|
| [OH_Camera_MetadataObjectExt](capi-oh-camera-oh-camera-metadataobjectext.md)\*\* metadataObjectExt | Double pointer to a **MetadataObjectExt** instance.|
| uint32_t size | Number of metadata objects|

### OH_MetadataOutput_OnErrorExt()

```c
typedef void (*OH_MetadataOutput_OnErrorExt)(void* context, Camera_ErrorCode errorCode)
```

**Description**

Defines a callback to listen for error events during metadata output.

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| void\* context | Context pointer provided by the user.|
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) errorCode | Error code reported during metadata output.|

### OH_MetadataOutput_RegisterMetadataObjectExtAvailableCallback()

```c
Camera_ErrorCode OH_MetadataOutput_RegisterMetadataObjectExtAvailableCallback(Camera_MetadataOutput* metadataOutput, void* context, OH_MetadataOutput_OnMetadataObjectExtAvailable callback)
```

**Description**

Registers a callback to listen for metadata object reporting events. This callback can be unregistered using [OH_MetadataOutput_UnregisterMetadataObjectExtAvailableCallback](capi-metadata-output-h.md#oh_metadataoutput_unregistermetadataobjectextavailablecallback).

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_MetadataOutput](capi-oh-camera-camera-metadataoutput.md)* metadataOutput | Pointer to a **MetadataOutput** instance.|
| void* context | Context pointer provided by the user.|
| [OH_MetadataOutput_OnMetadataObjectExtAvailable](capi-metadata-output-h.md#oh_metadataoutput_onmetadataobjectextavailable)* callback | Pointer to the callback used to listen for metadata object reporting events.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_MetadataOutput_UnregisterMetadataObjectExtAvailableCallback()

```c
Camera_ErrorCode OH_MetadataOutput_UnregisterMetadataObjectExtAvailableCallback(Camera_MetadataOutput* metadataOutput, void* context, OH_MetadataOutput_OnMetadataObjectExtAvailable callback)
```

**Description**

Unregisters the callback used to listen for metadata object reporting events.

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_MetadataOutput](capi-oh-camera-camera-metadataoutput.md)* metadataOutput | Pointer to a **MetadataOutput** instance.|
| void* context | Context pointer provided by the user.|
| [OH_MetadataOutput_OnMetadataObjectExtAvailable](capi-metadata-output-h.md#oh_metadataoutput_onmetadataobjectextavailable)* callback | Pointer to the callback used to listen for metadata object reporting events.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_MetadataOutput_RegisterErrorExtCallback()

```c
Camera_ErrorCode OH_MetadataOutput_RegisterErrorExtCallback(Camera_MetadataOutput* metadataOutput, void* context, OH_MetadataOutput_OnErrorExt callback)
```

**Description**

Registers a callback to listen for error events. This callback can be unregistered using [OH_MetadataOutput_UnregisterErrorExtCallback](capi-metadata-output-h.md#oh_metadataoutput_unregistererrorextcallback).

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_MetadataOutput](capi-oh-camera-camera-metadataoutput.md)* metadataOutput | Pointer to a **MetadataOutput** instance.|
| void* context | Context pointer provided by the user.|
| [OH_MetadataOutput_OnErrorExt](capi-metadata-output-h.md#oh_metadataoutput_onerrorext)* callback | Pointer to the callback used to listen for error events.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_MetadataOutput_UnregisterErrorExtCallback()

```c
Camera_ErrorCode OH_MetadataOutput_UnregisterErrorExtCallback(Camera_MetadataOutput* metadataOutput, void* context, OH_MetadataOutput_OnErrorExt callback)
```

**Description**

Unregisters the callback used to listen for error events.

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_MetadataOutput](capi-oh-camera-camera-metadataoutput.md)* metadataOutput | Pointer to a **MetadataOutput** instance.|
| void* context | Context pointer provided by the user.|
| [OH_MetadataOutput_OnErrorExt](capi-metadata-output-h.md#oh_metadataoutput_onerrorext)* callback | Pointer to the callback used to listen for error events.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_MetadataOutput_IsLockMetadataObjectTrackingSupported()

```c
bool OH_MetadataOutput_IsLockMetadataObjectTrackingSupported(const Camera_MetadataOutput* metadataOutput)
```

**Description**

Checks whether the device supports the function of locking a metadata object (such as a cat or dog face) for tracking.

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_MetadataOutput](capi-oh-camera-camera-metadataoutput.md)* metadataOutput | Pointer to a **MetadataOutput** instance.|

**Returns**

| Type| Description|
| -- | -- |
| bool | **true**: The function is supported.<br>         **false**: The function is not supported.|

### OH_MetadataOutput_LockMetadataObjectTracking()

```c
Camera_ErrorCode OH_MetadataOutput_LockMetadataObjectTracking(Camera_MetadataOutput* metadataOutput, Camera_Point* pointOfInterest)
```

**Description**

Locks a metadata object (such as a cat or dog face) for tracking.<br> This function tracks the object pointed to by **pointOfInterest**. If such object does not exist, this function does not take effect.<br> Locking for tracking is automatically canceled when the tracked object has left the viewfinder range for more than three seconds or the object is unlocked.

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_MetadataOutput](capi-oh-camera-camera-metadataoutput.md)* metadataOutput | Pointer to a **MetadataOutput** instance.|
| [Camera_Point](capi-oh-camera-camera-point.md)* pointOfInterest | Pointer to the point of the object to be tracked.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.<br>         **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal.|

### OH_MetadataOutput_UnlockMetadataObjectTracking()

```c
Camera_ErrorCode OH_MetadataOutput_UnlockMetadataObjectTracking(Camera_MetadataOutput* metadataOutput)
```

**Description**

Unlocks the metadata object (such as a cat or dog face) for tracking.

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_MetadataOutput](capi-oh-camera-camera-metadataoutput.md)* metadataOutput | Pointer to a **MetadataOutput** instance.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.<br>         **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal.|