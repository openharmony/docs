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
| typedef struct NativeWindowBuffer [OHNativeWindowBuffer](#ohnativewindowbuffer) | Provides the declaration of a **NativeWindowBuffer** struct.| 
| typedef void(\* [OH_OnFrameAvailable](#oh_onframeavailable)) (void \*context) | Defines the callback function triggered when a frame is available. | 
| typedef struct [OH_OnFrameAvailableListener](_o_h___on_frame_available_listener.md)  [OH_OnFrameAvailableListener](#oh_onframeavailablelistener) | Defines an **OH_NativeImage** listener, which is registered through  **OH_NativeImage_SetOnFrameAvailableListener**. The listener triggers a callback when a frame is available. | 
| typedef enum [OHNativeErrorCode](#ohnativeerrorcode)  [OHNativeErrorCode](#ohnativeerrorcode) | Defines an enum for the error codes. | 

### Enums

| Name| Description| 
| -------- | -------- |
| [OHNativeErrorCode](#ohnativeerrorcode-1) {<br>NATIVE_ERROR_OK = 0, NATIVE_ERROR_INVALID_ARGUMENTS = 40001000, NATIVE_ERROR_NO_PERMISSION = 40301000, NATIVE_ERROR_NO_BUFFER = 40601000,<br>NATIVE_ERROR_NO_CONSUMER = 41202000, NATIVE_ERROR_NOT_INIT = 41203000, NATIVE_ERROR_CONSUMER_CONNECTED = 41206000, NATIVE_ERROR_BUFFER_STATE_INVALID = 41207000,<br>NATIVE_ERROR_BUFFER_IN_CACHE = 41208000, NATIVE_ERROR_BUFFER_QUEUE_FULL = 41209000, NATIVE_ERROR_BUFFER_NOT_IN_CACHE = 41210000, NATIVE_ERROR_CONSUMER_DISCONNECTED = 41211000,NATIVE_ERROR_CONSUMER_NO_LISTENER_REGISTERED = 41212000,NATIVE_ERROR_UNSUPPORTED = 50102000,<br>NATIVE_ERROR_UNKNOWN = 50002000, NATIVE_ERROR_HDI_ERROR = 50007000,NATIVE_ERROR_BINDER_ERROR = 50401000,NATIVE_ERROR_EGL_STATE_UNKNOWN = 60001000, NATIVE_ERROR_EGL_API_FAILED = 60002000<br>} | Enumerates the error codes. | 

### Functions

| Name| Description| 
| -------- | -------- |
| [OH_NativeImage](#oh_nativeimage) \* [OH_NativeImage_Create](#oh_nativeimage_create) (uint32_t textureId, uint32_t textureTarget) | Creates an **OH_NativeImage** instance to be associated with the OpenGL ES texture ID and target.<br>This function must be used in pair with [OH_NativeImage_Destroy](#oh_nativeimage_destroy). Otherwise, memory leak occurs.<br>This function is not thread-safe.| 
| [OHNativeWindow](_native_window.md#ohnativewindow) \* [OH_NativeImage_AcquireNativeWindow](#oh_nativeimage_acquirenativewindow) ([OH_NativeImage](#oh_nativeimage) \*image) | Obtains an **OHNativeWindow** instance associated with an **OH_NativeImage** instance.<br>This function is not thread-safe.<br>When **OH_NativeImage** is being destructed, the corresponding **OHNativeWindow** instance is released. If the **OHNativeWindow** pointer is obtained by using this function, set the pointer to null when releasing the **OH_NativeImage** instance, so as to prevent subsequent wild pointers.| 
| int32_t [OH_NativeImage_AttachContext](#oh_nativeimage_attachcontext) ([OH_NativeImage](#oh_nativeimage) \*image, uint32_t textureId) | Attaches an **OH_NativeImage** instance to the current OpenGL ES context. The OpenGL ES texture will be bound to an **GL_TEXTURE_EXTERNAL_OES** instance and updated through the **OH_NativeImage** instance.<br>This function is not thread-safe.| 
| int32_t [OH_NativeImage_DetachContext](#oh_nativeimage_detachcontext) ([OH_NativeImage](#oh_nativeimage) \*image) | Detaches an **OH_NativeImage** instance from the current OpenGL ES context.<br>This function is not thread-safe.| 
| int32_t [OH_NativeImage_UpdateSurfaceImage](#oh_nativeimage_updatesurfaceimage) ([OH_NativeImage](#oh_nativeimage) \*image) | Updates the OpenGL ES texture associated with the latest frame through an **OH_NativeImage** instance.<br>This function must be called in a thread of the OpenGL ES context.<br>This function must be called after the [OH_OnFrameAvailableListener](_o_h___on_frame_available_listener.md) callback is triggered.<br>This function is not thread-safe.| 
| int64_t [OH_NativeImage_GetTimestamp](#oh_nativeimage_gettimestamp) ([OH_NativeImage](#oh_nativeimage) \*image) | Obtains the timestamp of the texture image that recently called the **OH_NativeImage_UpdateSurfaceImage** function.<br>This function is not thread-safe.| 
| int32_t [OH_NativeImage_GetTransformMatrix](#oh_nativeimage_gettransformmatrix) ([OH_NativeImage](#oh_nativeimage) \*image, float matrix[16]) | Obtains the transformation matrix of the texture image that recently called the **OH_NativeImage_UpdateSurfaceImage** function.| 
| int32_t [OH_NativeImage_GetSurfaceId](#oh_nativeimage_getsurfaceid) ([OH_NativeImage](#oh_nativeimage) \*image, uint64_t \*surfaceId) | Obtains the surface ID of an **OH_NativeImage** instance.<br>This function is not thread-safe.| 
| int32_t [OH_NativeImage_SetOnFrameAvailableListener](#oh_nativeimage_setonframeavailablelistener) ([OH_NativeImage](#oh_nativeimage) \*image, [OH_OnFrameAvailableListener](_o_h___on_frame_available_listener.md) listener) | Registers a listener to listen for frame availability events.<br>Do not call other functions of this module in the callback.<br>This function is not thread-safe.| 
| int32_t [OH_NativeImage_UnsetOnFrameAvailableListener](#oh_nativeimage_unsetonframeavailablelistener) ([OH_NativeImage](#oh_nativeimage) \*image) | Deregisters the listener used to listen for frame availability events.<br>This function is not thread-safe.| 
| void [OH_NativeImage_Destroy](#oh_nativeimage_destroy) ([OH_NativeImage](#oh_nativeimage) \*\*image) | Destroys an **OH_NativeImage** instance created by calling **OH_NativeImage_Create**. After the instance is destroyed,<br>the pointer to the **OH_NativeImage** instance is assigned **NULL**.<br>This function is not thread-safe.| 
| int32_t [OH_NativeImage_GetTransformMatrixV2](#oh_nativeimage_gettransformmatrixv2) ([OH_NativeImage](#oh_nativeimage) \*image, float matrix[16]) | Obtains, based on the rotation angle set by the producer, the transform matrix of the texture image that recently called the **OH_NativeImage_UpdateSurfaceImage** function.<br>The matrix is updated only after [OH_NativeImage_UpdateSurfaceImage](#oh_nativeimage_updatesurfaceimage) is called.<br>This function is not thread-safe.| 
| int32_t [OH_NativeImage_AcquireNativeWindowBuffer](#oh_nativeimage_acquirenativewindowbuffer) ([OH_NativeImage](#oh_nativeimage) \*image, [OHNativeWindowBuffer](_native_window.md#ohnativewindowbuffer) \*\*nativeWindowBuffer, int \*fenceFd) | Obtains an **OHNativeWindowBuffer** instance through an **OH_NativeImage** instance on the consumer side.<br>This function cannot be used together with [OH_NativeImage_UpdateSurfaceImage](#oh_nativeimage_updatesurfaceimage).<br>This function creates an **OHNativeWindowBuffer**.<br>When using the **OHNativeWindowBuffer**, call [OH_NativeWindow_NativeObjectReference](_native_window.md#oh_nativewindow_nativeobjectreference) to increase its reference count by one.<br>When finishing using the **OHNativeWindowBuffer**, call [OH_NativeWindow_NativeObjectUnreference](_native_window.md#oh_nativewindow_nativeobjectunreference) to decrease the reference count by one.<br>This function must be used in pair with [OH_NativeImage_ReleaseNativeWindowBuffer](#oh_nativeimage_releasenativewindowbuffer). Otherwise, memory leak occurs.<br>When **fenceFd** is used up, you must close it.<br>This function is not thread-safe.| 
| int32_t [OH_NativeImage_ReleaseNativeWindowBuffer](#oh_nativeimage_releasenativewindowbuffer) ([OH_NativeImage](#oh_nativeimage) \*image, [OHNativeWindowBuffer](_native_window.md#ohnativewindowbuffer) \*nativeWindowBuffer, int fenceFd) | Releases an **OHNativeWindowBuffer** instance through an **OH_NativeImage** instance.<br>The system will close **fenFd**. You do not need to close it.<br>This function is not thread-safe.| 
| [OH_NativeImage](#oh_nativeimage) \* [OH_ConsumerSurface_Create](#oh_consumersurface_create) () | Creates an **OH_NativeImage** instance as the consumer of the surface.<br>This function is used only for memory cycling of the surface consumer. Memory rendering is not proactively performed in the created **OH_NativeImage** instance.<br>This function cannot be used together with [OH_NativeImage_UpdateSurfaceImage](#oh_nativeimage_updatesurfaceimage).<br>This function must be used in pair with **OH_NativeImage_AcquireNativeWindowBuffer** and **OH_NativeImage_ReleaseNativeWindowBuffer**.<br>This function must be used in pair with [OH_NativeImage_Destroy](#oh_nativeimage_destroy). Otherwise, memory leak occurs.<br>This function is not thread-safe.| 
| int32_t [OH_ConsumerSurface_SetDefaultUsage](#oh_consumersurface_setdefaultusage) ([OH_NativeImage](#oh_nativeimage) \*image, uint64_t usage) | Sets the default read/write mode. This function is not thread-safe.| 
| int32_t [OH_ConsumerSurface_SetDefaultSize](#oh_consumersurface_setdefaultsize) ([OH_NativeImage](#oh_nativeimage) \*image, int32_t width, int32_t height) | Sets the default size of a geometric shape. This function is not thread-safe.| 

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

### OHNativeWindowBuffer

```
typedef struct NativeWindowBuffer OHNativeWindowBuffer
```

**Description**

Provides the declaration of a **NativeWindowBuffer** struct.

**Since**: 12


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
| NATIVE_ERROR_CONSUMER_DISCONNECTED | The consumer is disconnected.|
| NATIVE_ERROR_CONSUMER_NO_LISTENER_REGISTERED | No listener is registered on the consumer side.|
| NATIVE_ERROR_UNSUPPORTED  | The device or platform does not support the operation.  | 
| NATIVE_ERROR_UNKNOWN  | Unknown error. Check the log.  | 
| NATIVE_ERROR_HDI_ERROR  | Failed to call the HDI.  | 
| NATIVE_ERROR_BINDER_ERROR  | Cross-process communication failed.  | 
| NATIVE_ERROR_EGL_STATE_UNKNOWN  | The EGL environment is abnormal.  | 
| NATIVE_ERROR_EGL_API_FAILED  | Failed to call the EGL APIs.  | 


## Function Description


### OH_ConsumerSurface_SetDefaultUsage()

```
int32_t OH_ConsumerSurface_SetDefaultUsage (OH_NativeImage* image, uint64_t usage )
```

**Description**

Sets the default read/write mode. This function is not thread-safe.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeImage

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| image | Pointer to an **OH_NativeImage** instance.| 
| usage | Read/write mode. For details about the available options, see **OH_NativeBuffer_Usage**.| 

**Returns**

Returns **NATIVE_ERROR_OK** if the operation is successful.

Returns **NATIVE_ERROR_INVALID_ARGUMENTS** if **image** is a null pointer.


### OH_ConsumerSurface_SetDefaultSize()

```
int32_t OH_ConsumerSurface_SetDefaultSize (OH_NativeImage* image, int32_t width, int32_t height )
```

**Description**

Sets the default size of a geometric shape. This function is not thread-safe.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeImage

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| image | Pointer to an **OH_NativeImage** instance.| 
| width | Width of the geometric shape. The value is greater than 0, in pixels.| 
| height | Height of the geometric shape. The value is greater than 0, in pixels.| 

**Returns**

Returns **NATIVE_ERROR_OK** if the operation is successful.

Returns **NATIVE_ERROR_INVALID_ARGUMENTS** if **image** is a null pointer or **width** or **height** is less than 0.

### OH_ConsumerSurface_Create()

```
OH_NativeImage* OH_ConsumerSurface_Create ()
```

**Description**

Creates an **OH_NativeImage** instance as the consumer of the surface.

This function is used only for memory cycling of the surface consumer. Memory rendering is not proactively performed in the created **OH_NativeImage** instance.

This function cannot be used together with [OH_NativeImage_UpdateSurfaceImage](#oh_nativeimage_updatesurfaceimage).

This function must be used in pair with **OH_NativeImage_AcquireNativeWindowBuffer** and **OH_NativeImage_ReleaseNativeWindowBuffer**.

This function must be used in pair with [OH_NativeImage_Destroy](#oh_nativeimage_destroy). Otherwise, memory leak occurs.

This function is not thread-safe.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeImage

**Since**: 12

**Returns**

Returns a pointer to the **OH_NativeImage** instance if the operation is successful; returns **NULL** otherwise.


### OH_NativeImage_AcquireNativeWindowBuffer()

```
int32_t OH_NativeImage_AcquireNativeWindowBuffer (OH_NativeImage* image, OHNativeWindowBuffer** nativeWindowBuffer, int* fenceFd )
```

**Description**

Obtains an **OHNativeWindowBuffer** instance through an **OH_NativeImage** instance on the consumer side.

This function cannot be used together with [OH_NativeImage_UpdateSurfaceImage](#oh_nativeimage_updatesurfaceimage).

This function creates an **OHNativeWindowBuffer**.

When using the **OHNativeWindowBuffer**, call **OH_NativeWindow_NativeObjectReference** to increase its reference count by one.

When finishing using the **OHNativeWindowBuffer**, call **OH_NativeWindow_NativeObjectUnreference** to decrease the reference count by one.

This function must be used in pair with [OH_NativeImage_ReleaseNativeWindowBuffer](#oh_nativeimage_releasenativewindowbuffer). Otherwise, memory leak occurs.

When **fenceFd** is used up, you must close it.

This function is not thread-safe.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeImage

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| image | Pointer to an **OH_NativeImage** instance.| 
| nativeWindowBuffer | Double pointer to the **OHNativeWindowBuffer** instance obtained.| 
| fenceFd | Pointer to the file descriptor handle.| 

**Returns**

Returns **NATIVE_ERROR_OK** if the operation is successful.

Returns **NATIVE_ERROR_INVALID_ARGUMENTS** if **image**, **nativeWindowBuffer**, or **fenceFd** is a null pointer.

Returns **NATIVE_ERROR_NO_BUFFER** if no buffer is available for consumption.


### OH_NativeImage_ReleaseNativeWindowBuffer()

```
int32_t OH_NativeImage_ReleaseNativeWindowBuffer (OH_NativeImage* image, OHNativeWindowBuffer* nativeWindowBuffer, int fenceFd )
```

**Description**

Releases an **OHNativeWindowBuffer** instance through an **OH_NativeImage** instance.

The system will close **fenFd**. You do not need to close it.

This function is not thread-safe.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeImage

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| image | Pointer to an **OH_NativeImage** instance.| 
| nativeWindowBuffer | Pointer to an **OHNativeWindowBuffer** instance.| 
| fenceFd | File descriptor handle, which is used for concurrent synchronization control.| 

**Returns**

Returns **NATIVE_ERROR_OK** if the operation is successful.

Returns **NATIVE_ERROR_INVALID_ARGUMENTS** if **image** or **nativeWindowBuffer** is a null pointer.

Returns **NATIVE_ERROR_BUFFER_STATE_INVALID** if the status of **nativeWindowBuffer** is invalid.

Returns **NATIVE_ERROR_BUFFER_NOT_IN_CACHE** if **nativeWindowBuffer** is not in the cache.



### OH_NativeImage_AcquireNativeWindow()

```
OHNativeWindow* OH_NativeImage_AcquireNativeWindow (OH_NativeImage * image)
```

**Description**

Obtains an **OHNativeWindow** instance associated with an **OH_NativeImage** instance.

This function is not thread-safe.

When **OH_NativeImage** is being destructed, the corresponding **OHNativeWindow** instance is released. If the **OHNativeWindow** pointer is obtained by using this function, set the pointer to null when releasing the **OH_NativeImage** instance, so as to prevent subsequent wild pointers.

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

This function is not thread-safe.

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

This function must be used in pair with **OH_NativeImage_Destroy**. Otherwise, memory leak occurs.

This function is not thread-safe.

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

This function is not thread-safe.

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

This function is not thread-safe.

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

This function is not thread-safe.

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

This function is not thread-safe.

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

**Deprecated from**: 12

**Substitute**: [OH_NativeImage_GetTransformMatrixV2](#oh_nativeimage_gettransformmatrixv2)

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

The matrix is updated only after **OH_NativeImage_UpdateSurfaceImage** is called.

This function is not thread-safe.

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

Do not call other functions of this module in the callback.

This function is not thread-safe.

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

This function is not thread-safe.

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

This function must be called in a thread of the OpenGL ES context.

This function must be called after the **OH_OnFrameAvailableListener** callback is triggered.

This function is not thread-safe.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeImage

**Since**: 9

**Parameters**

| Name| Description|
| -------- | -------- |
| image | Pointer to an **OH_NativeImage** instance.|

**Returns**

Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](#ohnativeerrorcode) otherwise.
