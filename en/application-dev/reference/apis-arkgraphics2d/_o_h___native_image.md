# OH_NativeImage


## Overview

The **OH_NativeImage** module provides the capabilities of **NativeImage**. Functioning as a data consumer, it is used to associate data with the OpenGL texture. It is used in the OpenGL environment.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeImage

**Since**: 9


## Summary


### Files

| Name| Description|
| -------- | -------- |
| [native_image.h](native__image_8h.md) | Defines the functions for obtaining and using **NativeImage**.|


### Structs

| Name| Description|
| -------- | -------- |
| [OH_OnFrameAvailableListener](_o_h___on_frame_available_listener.md) | Defines an **OH_NativeImage** listener, which is registered through **OH_NativeImage_SetOnFrameAvailableListener**. The listener triggers a callback when a frame is available.|


### Types

| Name| Description|
| -------- | -------- |
| typedef struct [OH_NativeImage](#oh_nativeimage)  [OH_NativeImage](#oh_nativeimage) | Provides the declaration of an **OH_NativeImage** struct. | 
| typedef struct NativeWindow [OHNativeWindow](#ohnativewindow) | Provides the capability of accessing the **NativeWindow**. | 
| typedef void(\* [OH_OnFrameAvailable](#oh_onframeavailable)) (void \*context) | Defines the callback function triggered when a frame is available. | 
| typedef struct [OH_OnFrameAvailableListener](_o_h___on_frame_available_listener.md)  [OH_OnFrameAvailableListener](#oh_onframeavailablelistener) | Defines an **OH_NativeImage** listener, which is registered through **OH_NativeImage_SetOnFrameAvailableListener**. The listener triggers a callback when a frame is available. | 
| typedef enum [OHNativeErrorCode](#ohnativeerrorcode)  [OHNativeErrorCode](#ohnativeerrorcode) | Defines an enum for the error codes. | 

### Enums

| Name| Description| 
| -------- | -------- |
| [OHNativeErrorCode](#ohnativeerrorcode-1) {<br>NATIVE_ERROR_OK = 0, NATIVE_ERROR_INVALID_ARGUMENTS = 40001000, NATIVE_ERROR_NO_PERMISSION = 40301000, NATIVE_ERROR_NO_BUFFER = 40601000,<br>NATIVE_ERROR_NO_CONSUMER = 41202000, NATIVE_ERROR_NOT_INIT = 41203000, NATIVE_ERROR_CONSUMER_CONNECTED = 41206000, NATIVE_ERROR_BUFFER_STATE_INVALID = 41207000,<br>NATIVE_ERROR_BUFFER_IN_CACHE = 41208000, NATIVE_ERROR_BUFFER_QUEUE_FULL = 41209000, NATIVE_ERROR_BUFFER_NOT_IN_CACHE = 41210000, NATIVE_ERROR_UNSUPPORT = 50102000,<br>NATIVE_ERROR_UNKNOWN = 50002000, NATIVE_ERROR_EGL_STATE_UNKNOWN = 60001000, NATIVE_ERROR_EGL_API_FAILED = 60002000<br>} | Enumerates the error codes. | 

### Functions

| Name| Description|
| -------- | -------- |
| [OH_NativeImage_Create](#oh_nativeimage_create) (uint32_t textureId, uint32_t textureTarget) | Creates an **OH_NativeImage** instance to be associated with the OpenGL ES texture ID and target.|
| [OH_NativeImage_AcquireNativeWindow](#oh_nativeimage_acquirenativewindow) ([OH_NativeImage](#oh_nativeimage) \*image) | Obtains an **OHNativeWindow** instance associated with an **OH_NativeImage** instance. You need to call **OH_NativeWindow_DestroyNativeWindow** to release the **OHNativeWindow** instance when it is no longer required.<br>* |
| [OH_NativeImage_AttachContext](#oh_nativeimage_attachcontext) ([OH_NativeImage](#oh_nativeimage) \*image, uint32_t textureId) | Attaches an **OH_NativeImage** instance to the current OpenGL ES context.<br>The OpenGL ES texture will be bound to an **GL_TEXTURE_EXTERNAL_OES** instance and updated through the **OH_NativeImage** instance.|
| [OH_NativeImage_DetachContext](#oh_nativeimage_detachcontext) ([OH_NativeImage](#oh_nativeimage) \*image) | Detaches an **OH_NativeImage** instance from the current OpenGL ES context.|
| [OH_NativeImage_UpdateSurfaceImage](#oh_nativeimage_updatesurfaceimage) ([OH_NativeImage](#oh_nativeimage) \*image) | Updates the OpenGL ES texture associated with the latest frame through an **OH_NativeImage** instance.|
| [OH_NativeImage_GetTimestamp](#oh_nativeimage_gettimestamp) ([OH_NativeImage](#oh_nativeimage) \*image) | Obtains the timestamp of the texture image that recently called the **OH_NativeImage_UpdateSurfaceImage** function.|
| [OH_NativeImage_GetTransformMatrix](#oh_nativeimage_gettransformmatrix) ([OH_NativeImage](#oh_nativeimage) \*image, float matrix[16]) | Obtains the transformation matrix of the texture image that recently called the **OH_NativeImage_UpdateSurfaceImage** function.|
| [OH_NativeImage_GetSurfaceId](#oh_nativeimage_getsurfaceid) ([OH_NativeImage](#oh_nativeimage) \*image, uint64_t \*surfaceId) | Obtains the surface ID of an **OH_NativeImage** instance.|
| [OH_NativeImage_SetOnFrameAvailableListener](#oh_nativeimage_setonframeavailablelistener) ([OH_NativeImage](#oh_nativeimage) \*image, [OH_OnFrameAvailableListener](_o_h___on_frame_available_listener.md) listener) | Registers a listener to listen for frame availability events.|
| [OH_NativeImage_UnsetOnFrameAvailableListener](#oh_nativeimage_unsetonframeavailablelistener) ([OH_NativeImage](#oh_nativeimage) \*image) | Deregisters the listener used to listen for frame availability events.|
| [OH_NativeImage_Destroy](#oh_nativeimage_destroy) ([OH_NativeImage](#oh_nativeimage) \*\*image) | Destroys an **OH_NativeImage** instance created by calling **OH_NativeImage_Create**. After the instance is destroyed, the pointer to the **OH_NativeImage** instance is assigned **NULL**.|
| int32_t [OH_NativeImage_GetTransformMatrixV2](#oh_nativeimage_gettransformmatrixv2) ([OH_NativeImage](#oh_nativeimage) \*image, float matrix[16]) | Obtains, based on the rotation angle set by the producer, the transform matrix of the texture image that recently called the **OH_NativeImage_UpdateSurfaceImage** function. |

## Type Description


### OH_NativeImage

```
typedef struct OH_NativeImage OH_NativeImage
```

**Description**

Provides the declaration of an **OH_NativeImage** struct.

**Since**: 9


### OH_OnFrameAvailable

```
typedef void(* OH_OnFrameAvailable) (void *context)
```

**Description**

Defines the callback function triggered when a frame is available.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeImage

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| context | User-defined context information, which is returned when the callback is triggered.|


### OH_OnFrameAvailableListener

```
typedef struct OH_OnFrameAvailableListener OH_OnFrameAvailableListener
```

**Description**

Defines an **OH_NativeImage** listener, which is registered through [OH_NativeImage_SetOnFrameAvailableListener](#oh_nativeimage_setonframeavailablelistener). The listener triggers a callback when a frame is available.

**Since**: 11


### OHNativeErrorCode

```
typedef enum OHNativeErrorCode OHNativeErrorCode
```
**Description**

Defines an enum for the error codes.

**Since**: 12


### OHNativeWindow

```
typedef struct NativeWindow OHNativeWindow
```

**Description**

Provides the capability of accessing the **NativeWindow**.

**Since**: 9


## Enum Description


### OHNativeErrorCode

```
enum OHNativeErrorCode
```
**Description**

Enumerates the error codes.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| NATIVE_ERROR_OK  | The operation is successful.  | 
| NATIVE_ERROR_INVALID_ARGUMENTS  | An input parameter is invalid.  | 
| NATIVE_ERROR_NO_PERMISSION  | You do not have the permission to perform the operation.  | 
| NATIVE_ERROR_NO_BUFFER  | No buffer is available.  | 
| NATIVE_ERROR_NO_CONSUMER  | The consumer does not exist.  | 
| NATIVE_ERROR_NOT_INIT  | Not initialized.  | 
| NATIVE_ERROR_CONSUMER_CONNECTED  | The consumer is connected.  | 
| NATIVE_ERROR_BUFFER_STATE_INVALID  | The buffer status does not meet the expectation.  | 
| NATIVE_ERROR_BUFFER_IN_CACHE  | The buffer is already in the buffer queue.  | 
| NATIVE_ERROR_BUFFER_QUEUE_FULL  | The queue is full.  | 
| NATIVE_ERROR_BUFFER_NOT_IN_CACHE  | The buffer is not in the buffer queue.  | 
| NATIVE_ERROR_UNSUPPORT  | The device or platform does not support the operation.  | 
| NATIVE_ERROR_UNKNOWN  | Unknown error. Check the log.  | 
| NATIVE_ERROR_EGL_STATE_UNKNOWN  | The EGL environment is abnormal.  | 
| NATIVE_ERROR_EGL_API_FAILED  | Failed to call the EGL APIs.  | 


## Function Description


### OH_NativeImage_AcquireNativeWindow()

```
OHNativeWindow* OH_NativeImage_AcquireNativeWindow (OH_NativeImage * image)
```

**Description**

Obtains an **OHNativeWindow** instance associated with an **OH_NativeImage** instance. You need to call **OH_NativeWindow_DestroyNativeWindow** to release the **OHNativeWindow** instance when it is no longer required.

* 

**System capability**: SystemCapability.Graphic.Graphic2D.NativeImage

**Since**: 9

**Parameters**

| Name| Description|
| -------- | -------- |
| image | Pointer to an **OH_NativeImage** instance.|

**Returns**

Returns a pointer to the **OHNativeWindow** instance if the operation is successful; returns **NULL** otherwise.


### OH_NativeImage_AttachContext()

```
int32_t OH_NativeImage_AttachContext (OH_NativeImage * image, uint32_t textureId )
```

**Description**

Attaches an **OH_NativeImage** instance to the current OpenGL ES context.

The OpenGL ES texture will be bound to an **GL_TEXTURE_EXTERNAL_OES** instance and updated through the **OH_NativeImage** instance.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeImage

**Since**: 9

**Parameters**

| Name| Description|
| -------- | -------- |
| image | Pointer to an **OH_NativeImage** instance.|
| textureId | ID of the OpenGL ES texture to which the **OH_NativeImage** instance is to be attached.|

**Returns**

Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](#ohnativeerrorcode) otherwise.


### OH_NativeImage_Create()

```
OH_NativeImage* OH_NativeImage_Create (uint32_t textureId, uint32_t textureTarget )
```

**Description**

Creates an **OH_NativeImage** instance to be associated with the OpenGL ES texture ID and target.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeImage

**Since**: 9

**Parameters**

| Name| Description|
| -------- | -------- |
| textureId | OpenGL ES texture ID.|
| textureTarget | OpenGL ES texture target.|

**Returns**

Returns a pointer to the **OH_NativeImage** instance if the operation is successful; returns **NULL** otherwise.


### OH_NativeImage_Destroy()

```
void OH_NativeImage_Destroy (OH_NativeImage ** image)
```

**Description**

Destroys an **OH_NativeImage** instance created by calling **OH_NativeImage_Create**. After the instance is destroyed,

the pointer to the **OH_NativeImage** instance is assigned **NULL**.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeImage

**Since**: 9

**Parameters**

| Name| Description|
| -------- | -------- |
| image | Pointer to an **OH_NativeImage** instance.|


### OH_NativeImage_DetachContext()

```
int32_t OH_NativeImage_DetachContext (OH_NativeImage * image)
```

**Description**

Detaches an **OH_NativeImage** instance from the current OpenGL ES context.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeImage

**Since**: 9

**Parameters**

| Name| Description|
| -------- | -------- |
| image | Pointer to an **OH_NativeImage** instance.|

**Returns**

Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](#ohnativeerrorcode) otherwise.


### OH_NativeImage_GetSurfaceId()

```
int32_t OH_NativeImage_GetSurfaceId (OH_NativeImage * image, uint64_t * surfaceId )
```

**Description**

Obtains the surface ID of an **OH_NativeImage** instance.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeImage

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| image | Pointer to an **OH_NativeImage** instance.|
| surfaceId | Pointer to the surface ID.|

**Returns**

Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](#ohnativeerrorcode) otherwise.


### OH_NativeImage_GetTimestamp()

```
int64_t OH_NativeImage_GetTimestamp (OH_NativeImage * image)
```

**Description**

Obtains the timestamp of the texture image that recently called the **OH_NativeImage_UpdateSurfaceImage** function.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeImage

**Since**: 9

**Parameters**

| Name| Description|
| -------- | -------- |
| image | Pointer to an **OH_NativeImage** instance.|

**Returns**

Returns the timestamp of the texture image.


### OH_NativeImage_GetTransformMatrix()

```
int32_t OH_NativeImage_GetTransformMatrix (OH_NativeImage * image, float matrix[16] )
```

**Description**

Obtains the transformation matrix of the texture image that recently called the **OH_NativeImage_UpdateSurfaceImage** function.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeImage

**Since**: 9

**Parameters**

| Name| Description|
| -------- | -------- |
| image | Pointer to an **OH_NativeImage** instance.|
| matrix | Buffer used to store the 4 \* 4 transform matrix obtained.|

**Returns**

Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](#ohnativeerrorcode) otherwise.

### OH_NativeImage_GetTransformMatrixV2()

```
int32_t OH_NativeImage_GetTransformMatrixV2 (OH_NativeImage* image, float matrix[16] )
```
**Description**

Obtains, based on the rotation angle set by the producer, the transform matrix of the texture image that recently called the **OH_NativeImage_UpdateSurfaceImage** function.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeImage

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| image | Pointer to an **OH_NativeImage** instance. | 
| matrix | Buffer used to store the 4 \* 4 transform matrix obtained. | 

**Returns**

Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](#ohnativeerrorcode) otherwise.

### OH_NativeImage_SetOnFrameAvailableListener()

```
int32_t OH_NativeImage_SetOnFrameAvailableListener (OH_NativeImage * image, OH_OnFrameAvailableListener listener )
```

**Description**

Registers a listener to listen for frame availability events.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeImage

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| image | Pointer to an **OH_NativeImage** instance.|
| listener | Listener to register.|

**Returns**

Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](#ohnativeerrorcode) otherwise.


### OH_NativeImage_UnsetOnFrameAvailableListener()

```
int32_t OH_NativeImage_UnsetOnFrameAvailableListener (OH_NativeImage * image)
```

**Description**

Deregisters the listener used to listen for frame availability events.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeImage

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| image | Pointer to an **OH_NativeImage** instance.|

**Returns**

Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](#ohnativeerrorcode) otherwise.


### OH_NativeImage_UpdateSurfaceImage()

```
int32_t OH_NativeImage_UpdateSurfaceImage (OH_NativeImage * image)
```

**Description**

Updates the OpenGL ES texture associated with the latest frame through an **OH_NativeImage** instance.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeImage

**Since**: 9

**Parameters**

| Name| Description|
| -------- | -------- |
| image | Pointer to an **OH_NativeImage** instance.|

**Returns**

Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](#ohnativeerrorcode) otherwise.
