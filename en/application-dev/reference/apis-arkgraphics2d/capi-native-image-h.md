# native_image.h
<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @Flix-fangyang; @li_hui180; @ding-panyun-->
<!--Designer: @conan13234-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->
## Overview

This file declares the functions for obtaining and using **NativeImage**.

<!--RP1-->
**Sample**: [NDKNativeImage](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Native/NdkNativeImage)<!--RP1End-->

**File to include**: <native_image/native_image.h>

**Library**: libnative_image.so

**Since**: 9

**Related module**: [OH_NativeImage](capi-oh-nativeimage.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_OnFrameAvailableListener](capi-oh-nativeimage-oh-onframeavailablelistener.md) | OH_OnFrameAvailableListener | Defines an **OH_NativeImage** listener, which is registered through [OH_NativeImage_SetOnFrameAvailableListener](capi-native-image-h.md#oh_nativeimage_setonframeavailablelistener). The listener triggers a callback when a frame is available.|
| [OH_NativeImage](capi-oh-nativeimage-oh-nativeimage.md) | OH_NativeImage | Provides the declaration of an **OH_NativeImage** struct.|
| [NativeWindow](capi-nativewindow-nativewindow.md) | OHNativeWindow | Provides the capability of accessing the **NativeWindow**.|
| [NativeWindowBuffer](capi-nativewindow-nativewindowbuffer.md) | OHNativeWindowBuffer | Provides the declaration of a **NativeWindowBuffer** struct.|

### Functions

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [typedef void (\*OH_OnFrameAvailable)(void *context)](#oh_onframeavailable) | OH_OnFrameAvailable | Callback function triggered when a frame is available.|
| [OH_NativeImage* OH_NativeImage_Create(uint32_t textureId, uint32_t textureTarget)](#oh_nativeimage_create) | - | Creates an **OH_NativeImage** instance to be associated with the specified OpenGL ES texture ID and target.<br>This function must be used in pair with [OH_NativeImage_Destroy](capi-native-image-h.md#oh_nativeimage_destroy). Otherwise, memory leak occurs.<br>This function is not thread-safe.|
| [OHNativeWindow* OH_NativeImage_AcquireNativeWindow(OH_NativeImage* image)](#oh_nativeimage_acquirenativewindow) | - | Obtains an **OHNativeWindow** instance associated with an **OH_NativeImage** instance.<br>This function is not thread-safe.<br>When **OH_NativeImage** is being destructed, the corresponding **OHNativeWindow** instance is released. If the **OHNativeWindow** pointer is obtained by using this function, set the pointer to null when releasing the **OH_NativeImage** instance, so as to prevent subsequent wild pointers.|
| [int32_t OH_NativeImage_AttachContext(OH_NativeImage* image, uint32_t textureId)](#oh_nativeimage_attachcontext) | - | Attaches an **OH_NativeImage** instance to the current OpenGL ES context. The OpenGL ES texture will be bound to an **GL_TEXTURE_EXTERNAL_OES** instance and updated through the **OH_NativeImage** instance.<br>This function is not thread-safe.|
| [int32_t OH_NativeImage_DetachContext(OH_NativeImage* image)](#oh_nativeimage_detachcontext) | - | Detaches an **OH_NativeImage** instance from the current OpenGL ES context.<br>This function is not thread-safe.|
| [int32_t OH_NativeImage_UpdateSurfaceImage(OH_NativeImage* image)](#oh_nativeimage_updatesurfaceimage) | - | Updates the OpenGL ES texture associated with the latest frame through an **OH_NativeImage** instance.<br>This function must be called in a thread of the OpenGL ES context.<br>This function must be called after the [OH_OnFrameAvailableListener](capi-oh-nativeimage-oh-onframeavailablelistener.md) callback is received.<br>This function is not thread-safe.|
| [int64_t OH_NativeImage_GetTimestamp(OH_NativeImage* image)](#oh_nativeimage_gettimestamp) | - | Obtains the timestamp of the texture image that recently called the **OH_NativeImage_UpdateSurfaceImage** function.<br>This function is not thread-safe.|
| [int32_t OH_NativeImage_GetTransformMatrix(OH_NativeImage* image, float matrix[16])](#oh_nativeimage_gettransformmatrix) | - | Obtains the transformation matrix of the texture image that recently called the **OH_NativeImage_UpdateSurfaceImage** function.|
| [int32_t OH_NativeImage_GetSurfaceId(OH_NativeImage* image, uint64_t* surfaceId)](#oh_nativeimage_getsurfaceid) | - | Obtains the surface ID of an **OH_NativeImage** instance.<br>This function is not thread-safe.|
| [int32_t OH_NativeImage_SetOnFrameAvailableListener(OH_NativeImage* image, OH_OnFrameAvailableListener listener)](#oh_nativeimage_setonframeavailablelistener) | - | Registers a listener to listen for frame availability events.<br>Do not call other functions of this module in the callback.<br>This function is not thread-safe.|
| [int32_t OH_NativeImage_UnsetOnFrameAvailableListener(OH_NativeImage* image)](#oh_nativeimage_unsetonframeavailablelistener) | - | Deregisters the listener used to listen for frame availability events.<br>This function is not thread-safe.|
| [void OH_NativeImage_Destroy(OH_NativeImage** image)](#oh_nativeimage_destroy) | - | Destroys an **OH_NativeImage** instance created by calling **OH_NativeImage_Create**. After the instance is destroyed,<br>the pointer to the **OH_NativeImage** instance is assigned **NULL**.<br>This function is not thread-safe.|
| [int32_t OH_NativeImage_GetTransformMatrixV2(OH_NativeImage* image, float matrix[16])](#oh_nativeimage_gettransformmatrixv2) | - | Obtains, based on the rotation angle set by the producer, the transform matrix of the texture image that recently called the **OH_NativeImage_UpdateSurfaceImage** function.<br>The matrix is updated only after [OH_NativeImage_UpdateSurfaceImage](capi-native-image-h.md#oh_nativeimage_updatesurfaceimage) is called.<br>This function is not thread-safe.|
| [int32_t OH_NativeImage_GetBufferMatrix(OH_NativeImage* image, float matrix[16])](#oh_nativeimage_getbuffermatrix) | - | Obtains the transformation matrix calculated based on the rotation angle set by the producer and the actual valid content area of the buffer.<br>This function returns a transformation matrix that is determined by the buffer's rotation angle and actual valid content area during the consumption of the buffer by [OH_NativeImage](capi-oh-nativeimage-oh-nativeimage.md), specifically when calling [OH_NativeImage_UpdateSurfaceImage](capi-native-image-h.md#oh_nativeimage_updatesurfaceimage) or [OH_NativeImage_AcquireNativeWindowBuffer](capi-native-image-h.md#oh_nativeimage_acquirenativewindowbuffer).<br>This function is not thread-safe.|
| [int32_t OH_NativeImage_AcquireNativeWindowBuffer(OH_NativeImage* image,OHNativeWindowBuffer** nativeWindowBuffer, int* fenceFd)](#oh_nativeimage_acquirenativewindowbuffer) | - | Obtain an **OHNativeWindowBuffer** instance through the **OH_NativeImage** instance on the consumer side.<br>This function cannot be used in together with [OH_NativeImage_UpdateSurfaceImage](capi-native-image-h.md#oh_nativeimage_updatesurfaceimage).<br>This function creates an **OHNativeWindowBuffer**.<br>When using the **OHNativeWindowBuffer**, call [OH_NativeWindow_NativeObjectReference](capi-external-window-h.md#oh_nativewindow_nativeobjectreference) to increase its reference count by one.<br>When finishing using the **OHNativeWindowBuffer**, call [OH_NativeWindow_NativeObjectUnreference](capi-external-window-h.md#oh_nativewindow_nativeobjectunreference) to decrease the reference count by one.<br>This function must be used in pair with [OH_NativeImage_ReleaseNativeWindowBuffer](capi-native-image-h.md#oh_nativeimage_releasenativewindowbuffer). Otherwise, memory leak occurs.<br>When **fenceFd** is used up, you must close it.<br>This function is not thread-safe.|
| [int32_t OH_NativeImage_ReleaseNativeWindowBuffer(OH_NativeImage* image,OHNativeWindowBuffer* nativeWindowBuffer, int fenceFd)](#oh_nativeimage_releasenativewindowbuffer) | - | Release the **OHNativeWindowBuffer** instance through the **OH_NativeImage** instance.<br>The system will close **fenceFd**. You do not need to close it.<br>This function is not thread-safe.|
| [OH_NativeImage* OH_ConsumerSurface_Create(void)](#oh_consumersurface_create) | - | Creates an **OH_NativeImage** instance as the consumer of the surface.<br>This function is used only for memory cycling of the surface consumer. Memory rendering is not proactively performed in the created **OH_NativeImage** instance.<br>This function cannot be used in together with [OH_NativeImage_UpdateSurfaceImage](capi-native-image-h.md#oh_nativeimage_updatesurfaceimage).<br>This function must be used in together with [OH_NativeImage_AcquireNativeWindowBuffer](capi-native-image-h.md#oh_nativeimage_acquirenativewindowbuffer) and [OH_NativeImage_ReleaseNativeWindowBuffer](capi-native-image-h.md#oh_nativeimage_releasenativewindowbuffer).<br>This function must be used in pair with [OH_NativeImage_Destroy](capi-native-image-h.md#oh_nativeimage_destroy). Otherwise, memory leak occurs.<br>This function is not thread-safe.|
| [int32_t OH_ConsumerSurface_SetDefaultUsage(OH_NativeImage* image, uint64_t usage)](#oh_consumersurface_setdefaultusage) | - | Sets the default read/write mode.<br>This function is not thread-safe.|
| [int32_t OH_ConsumerSurface_SetDefaultSize(OH_NativeImage* image, int32_t width, int32_t height)](#oh_consumersurface_setdefaultsize) | - | Sets the default size of a geometric shape.<br>This function is not thread-safe.|
| [int32_t OH_NativeImage_SetDropBufferMode(OH_NativeImage* image, bool isOpen)](#oh_nativeimage_setdropbuffermode) | - | Sets the frame-dropping mode for rendering of an **OH_NativeImage** instance.<br>In frame-dropping mode, most buffers produced by the producer are discarded, and only the latest buffer is rendered promptly.<br>This mode does not guarantee high frame rates.<br>It is recommended that you can call this function immediately after [OH_NativeImage_Create](capi-native-image-h.md#oh_nativeimage_create).<br>This function takes effect only when it is used together with [OH_NativeImage_UpdateSurfaceImage](capi-native-image-h.md#oh_nativeimage_updatesurfaceimage).<br>This function is not thread-safe.<br>|

## Function Description

### OH_OnFrameAvailable()

```
typedef void (*OH_OnFrameAvailable)(void *context)
```

**Description**

Callback function triggered when a frame is available.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeImage

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| void *context | User-defined context information, which is returned when the callback is triggered.|

### OH_NativeImage_Create()

```
OH_NativeImage* OH_NativeImage_Create(uint32_t textureId, uint32_t textureTarget)
```

**Description**

Creates an **OH_NativeImage** instance to be associated with the specified OpenGL ES texture ID and target.<br>This function must be used in pair with [OH_NativeImage_Destroy](capi-native-image-h.md#oh_nativeimage_destroy). Otherwise, memory leak occurs.<br>This function is not thread-safe.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeImage

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| uint32_t textureId | OpenGL ES texture ID.|
| uint32_t textureTarget | OpenGL ES texture target.|

**Returns**

| Type| Description|
| -- | -- |
| OH_NativeImage* | Returns a pointer to the **OH_NativeImage** instance if the creation is successful; returns **NULL** otherwise.|

### OH_NativeImage_AcquireNativeWindow()

```
OHNativeWindow* OH_NativeImage_AcquireNativeWindow(OH_NativeImage* image)
```

**Description**

Obtains an **OHNativeWindow** instance associated with an **OH_NativeImage** instance.<br>This function is not thread-safe.<br>When **OH_NativeImage** is being destructed, the corresponding **OHNativeWindow** instance is released. If the **OHNativeWindow** pointer is obtained by using this function, set the pointer to null when releasing the **OH_NativeImage** instance, so as to prevent subsequent wild pointers.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeImage

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeImage](capi-oh-nativeimage-oh-nativeimage.md)* image | Pointer to an **OH_NativeImage** instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OHNativeWindow](capi-nativewindow-nativewindow.md)* | Returns a pointer to the **OHNativeWindow** instance if the operation is successful; returns **NULL** otherwise.|

### OH_NativeImage_AttachContext()

```
int32_t OH_NativeImage_AttachContext(OH_NativeImage* image, uint32_t textureId)
```

**Description**

Attaches an **OH_NativeImage** instance to the current OpenGL ES context. The OpenGL ES texture will be bound to an **GL_TEXTURE_EXTERNAL_OES** instance and updated through the **OH_NativeImage** instance.<br>This function is not thread-safe.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeImage

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeImage](capi-oh-nativeimage-oh-nativeimage.md)* image | Pointer to an **OH_NativeImage** instance.|
| uint32_t textureId | ID of the OpenGL ES texture to which the **OH_NativeImage** instance is to be attached.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](capi-graphic-error-code-h.md#ohnativeerrorcode) otherwise.|

### OH_NativeImage_DetachContext()

```
int32_t OH_NativeImage_DetachContext(OH_NativeImage* image)
```

**Description**

Detaches an **OH_NativeImage** instance from the current OpenGL ES context.<br>This function is not thread-safe.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeImage

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeImage](capi-oh-nativeimage-oh-nativeimage.md)* image | Pointer to an **OH_NativeImage** instance.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](capi-graphic-error-code-h.md#ohnativeerrorcode) otherwise.|

### OH_NativeImage_UpdateSurfaceImage()

```
int32_t OH_NativeImage_UpdateSurfaceImage(OH_NativeImage* image)
```

**Description**

Updates the OpenGL ES texture associated with the latest frame through an **OH_NativeImage** instance.<br>This function must be called in a thread of the OpenGL ES context.<br>This function must be called after the [OH_OnFrameAvailableListener](capi-oh-nativeimage-oh-onframeavailablelistener.md) callback is received.<br>This function is not thread-safe.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeImage

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeImage](capi-oh-nativeimage-oh-nativeimage.md)* image | Pointer to an **OH_NativeImage** instance.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](capi-graphic-error-code-h.md#ohnativeerrorcode) otherwise.|

### OH_NativeImage_GetTimestamp()

```
int64_t OH_NativeImage_GetTimestamp(OH_NativeImage* image)
```

**Description**

Obtains the timestamp of the texture image that recently called the **OH_NativeImage_UpdateSurfaceImage** function.<br>This function is not thread-safe.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeImage

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeImage](capi-oh-nativeimage-oh-nativeimage.md)* image | Pointer to an **OH_NativeImage** instance.|

**Returns**

| Type| Description|
| -- | -- |
| int64_t | Returns the timestamp of the texture image.|

### OH_NativeImage_GetTransformMatrix()

```
int32_t OH_NativeImage_GetTransformMatrix(OH_NativeImage* image, float matrix[16])
```

**Description**

Obtains the transformation matrix of the texture image that recently called the **OH_NativeImage_UpdateSurfaceImage** function.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeImage

**Since**: 9

**Deprecated from**: 12

**Substitute**: [OH_NativeImage_GetTransformMatrixV2](capi-native-image-h.md#oh_nativeimage_gettransformmatrixv2)


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeImage](capi-oh-nativeimage-oh-nativeimage.md)* image | Pointer to an **OH_NativeImage** instance.|
| matrix |  Buffer used to store the 4 * 4 transform matrix obtained.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](capi-graphic-error-code-h.md#ohnativeerrorcode) otherwise.|

### OH_NativeImage_GetSurfaceId()

```
int32_t OH_NativeImage_GetSurfaceId(OH_NativeImage* image, uint64_t* surfaceId)
```

**Description**

Obtains the surface ID of an **OH_NativeImage** instance.<br>This function is not thread-safe.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeImage

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeImage](capi-oh-nativeimage-oh-nativeimage.md)* image | Pointer to an **OH_NativeImage** instance.|
| uint64_t* surfaceId | Pointer to the surface ID.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](capi-graphic-error-code-h.md#ohnativeerrorcode) otherwise.|

### OH_NativeImage_SetOnFrameAvailableListener()

```
int32_t OH_NativeImage_SetOnFrameAvailableListener(OH_NativeImage* image, OH_OnFrameAvailableListener listener)
```

**Description**

Registers a listener to listen for frame availability events.<br>Do not call other functions of this module in the callback.<br>This function is not thread-safe.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeImage

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeImage](capi-oh-nativeimage-oh-nativeimage.md)* image | Pointer to an **OH_NativeImage** instance.|
| [OH_OnFrameAvailableListener](capi-oh-nativeimage-oh-onframeavailablelistener.md) listener | Listener to register.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](capi-graphic-error-code-h.md#ohnativeerrorcode) otherwise.|

### OH_NativeImage_UnsetOnFrameAvailableListener()

```
int32_t OH_NativeImage_UnsetOnFrameAvailableListener(OH_NativeImage* image)
```

**Description**

Deregisters the listener used to listen for frame availability events.<br>This function is not thread-safe.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeImage

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeImage](capi-oh-nativeimage-oh-nativeimage.md)* image | Pointer to an **OH_NativeImage** instance.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](capi-graphic-error-code-h.md#ohnativeerrorcode) otherwise.|

### OH_NativeImage_Destroy()

```
void OH_NativeImage_Destroy(OH_NativeImage** image)
```

**Description**

Destroys an **OH_NativeImage** instance created by calling **OH_NativeImage_Create**. After the instance is destroyed,<br>the pointer to the **OH_NativeImage** instance is assigned **NULL**.<br>This function is not thread-safe.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeImage

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeImage](capi-oh-nativeimage-oh-nativeimage.md)** image | Pointer to an **OH_NativeImage** instance.|

### OH_NativeImage_GetTransformMatrixV2()

```
int32_t OH_NativeImage_GetTransformMatrixV2(OH_NativeImage* image, float matrix[16])
```

**Description**

Obtains, based on the rotation angle set by the producer, the transform matrix of the texture image that recently called the **OH_NativeImage_UpdateSurfaceImage** function.<br>The matrix is updated only after [OH_NativeImage_UpdateSurfaceImage](capi-native-image-h.md#oh_nativeimage_updatesurfaceimage) is called.<br>This function is not thread-safe.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeImage

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeImage](capi-oh-nativeimage-oh-nativeimage.md)* image | Pointer to an **OH_NativeImage** instance.|
| matrix |  Buffer used to store the 4 * 4 transform matrix obtained.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](capi-graphic-error-code-h.md#ohnativeerrorcode) otherwise.|

### OH_NativeImage_GetBufferMatrix()

```
int32_t OH_NativeImage_GetBufferMatrix(OH_NativeImage* image, float matrix[16])
```

**Description**

Obtains the transformation matrix calculated based on the rotation angle set by the producer and the actual valid content area of the buffer.<br>This function returns a transformation matrix that is determined by the buffer's rotation angle and actual valid content area during the consumption of the buffer by [OH_NativeImage](capi-oh-nativeimage-oh-nativeimage.md), specifically when calling [OH_NativeImage_UpdateSurfaceImage](capi-native-image-h.md#oh_nativeimage_updatesurfaceimage) or [OH_NativeImage_AcquireNativeWindowBuffer](capi-native-image-h.md#oh_nativeimage_acquirenativewindowbuffer).<br>This function is not thread-safe.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeImage

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeImage](capi-oh-nativeimage-oh-nativeimage.md)* image | Pointer to an [OH_NativeImage](capi-oh-nativeimage-oh-nativeimage.md) instance.|
| matrix |  Buffer used to store the 4 x 4 transformation matrix obtained.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns **NATIVE_ERROR_OK** if the operation is successful.<br> Returns **NATIVE_ERROR_INVALID_ARGUMENTS** (error code: 40001000) if **image** is a null pointer.<br> Returns **NATIVE_ERROR_MEM_OPERATION_ERROR** (error code: 30001000) if the transformation matrix fails to be obtained due to a memory manipulation error.|

### OH_NativeImage_AcquireNativeWindowBuffer()

```
int32_t OH_NativeImage_AcquireNativeWindowBuffer(OH_NativeImage* image,OHNativeWindowBuffer** nativeWindowBuffer, int* fenceFd)
```

**Description**

Obtain an **OHNativeWindowBuffer** instance through the **OH_NativeImage** instance on the consumer side. This function cannot be used in together with [OH_NativeImage_UpdateSurfaceImage](capi-native-image-h.md#oh_nativeimage_updatesurfaceimage).<br>This function creates an **OHNativeWindowBuffer**. When using the **OHNativeWindowBuffer**, call [OH_NativeWindow_NativeObjectReference](capi-external-window-h.md#oh_nativewindow_nativeobjectreference) to increase its reference count by one. When finishing using the **OHNativeWindowBuffer**, call [OH_NativeWindow_NativeObjectUnreference](capi-external-window-h.md#oh_nativewindow_nativeobjectunreference) to decrease the reference count by one.<br>This function must be used in pair with [OH_NativeImage_ReleaseNativeWindowBuffer](capi-native-image-h.md#oh_nativeimage_releasenativewindowbuffer). Otherwise, memory leak occurs.<br>When **fenceFd** is used up, you must close it.<br>This function is not thread-safe.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeImage

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeImage](capi-oh-nativeimage-oh-nativeimage.md)* image | Pointer to an **OH_NativeImage** instance.|
| [OHNativeWindowBuffer](capi-nativewindow-nativewindowbuffer.md)** nativeWindowBuffer | Double pointer to the **OHNativeWindowBuffer** instance obtained.|
| int* fenceFd | Pointer to the file descriptor handle.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns **NATIVE_ERROR_OK** if the operation is successful.<br> Returns **NATIVE_ERROR_INVALID_ARGUMENTS** if **image**, **nativeWindowBuffer**, or **fenceFd** is a null pointer.<br> Returns **NATIVE_ERROR_NO_BUFFER** if no buffer is available for consumption.|

### OH_NativeImage_ReleaseNativeWindowBuffer()

```
int32_t OH_NativeImage_ReleaseNativeWindowBuffer(OH_NativeImage* image,OHNativeWindowBuffer* nativeWindowBuffer, int fenceFd)
```

**Description**

Release the **OHNativeWindowBuffer** instance through the **OH_NativeImage** instance.<br>The system will close **fenceFd**. You do not need to close it.<br>This function is not thread-safe.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeImage

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeImage](capi-oh-nativeimage-oh-nativeimage.md)* image | Pointer to an **OH_NativeImage** instance.|
| [OHNativeWindowBuffer](capi-nativewindow-nativewindowbuffer.md)* nativeWindowBuffer | Pointer to an **OHNativeWindowBuffer** instance.|
| int fenceFd | File descriptor handle, which is used for concurrent synchronization control.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns **NATIVE_ERROR_OK** if the operation is successful.<br> Returns **NATIVE_ERROR_INVALID_ARGUMENTS** if **image** or **nativeWindowBuffer** is a null pointer.<br> Returns **NATIVE_ERROR_BUFFER_STATE_INVALID** if the status of **nativeWindowBuffer** is invalid.<br> Returns **NATIVE_ERROR_BUFFER_NOT_IN_CACHE** if **nativeWindowBuffer** is not in the cache.|

### OH_ConsumerSurface_Create()

```
OH_NativeImage* OH_ConsumerSurface_Create(void)
```

**Description**

Creates an **OH_NativeImage** instance as the consumer of the surface.<br>This function is used only for memory cycling of the surface consumer. Memory rendering is not proactively performed in the created **OH_NativeImage** instance.<br>This function cannot be used in together with [OH_NativeImage_UpdateSurfaceImage](capi-native-image-h.md#oh_nativeimage_updatesurfaceimage).<br>This function must be used in together with [OH_NativeImage_AcquireNativeWindowBuffer](capi-native-image-h.md#oh_nativeimage_acquirenativewindowbuffer) and [OH_NativeImage_ReleaseNativeWindowBuffer](capi-native-image-h.md#oh_nativeimage_releasenativewindowbuffer).<br>This function must be used in pair with [OH_NativeImage_Destroy](capi-native-image-h.md#oh_nativeimage_destroy). Otherwise, memory leak occurs.<br>This function is not thread-safe.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeImage

**Since**: 12

**Returns**

| Type| Description|
| -- | -- |
| [OH_NativeImage](capi-oh-nativeimage-oh-nativeimage.md)* | Returns a pointer to the **OH_NativeImage** instance if the operation is successful; returns **NULL** otherwise.|

### OH_ConsumerSurface_SetDefaultUsage()

```
int32_t OH_ConsumerSurface_SetDefaultUsage(OH_NativeImage* image, uint64_t usage)
```

**Description**

Sets the default read/write mode.<br>This function is not thread-safe.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeImage

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeImage](capi-oh-nativeimage-oh-nativeimage.md)* image | Pointer to an **OH_NativeImage** instance.|
| uint64_t usage | Read/write mode. For details about the enumerated values, see [OH_NativeBuffer_Usage](capi-native-buffer-h.md#oh_nativebuffer_usage).|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns **NATIVE_ERROR_OK** if the operation is successful.<br> Returns **NATIVE_ERROR_INVALID_ARGUMENTS** if **image** is a null pointer.|

### OH_ConsumerSurface_SetDefaultSize()

```
int32_t OH_ConsumerSurface_SetDefaultSize(OH_NativeImage* image, int32_t width, int32_t height)
```

**Description**

Sets the default size of a geometric shape.<br>This function is not thread-safe.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeImage

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeImage](capi-oh-nativeimage-oh-nativeimage.md)* image | Pointer to an **OH_NativeImage** instance.|
| int32_t width | Width of the geometric shape. The value is greater than 0, in pixels.|
| int32_t height | Height of the geometric shape. The value is greater than 0, in pixels.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns **NATIVE_ERROR_OK** if the operation is successful.<br> Returns **NATIVE_ERROR_INVALID_ARGUMENTS** if **image** is a null pointer or **width** or **height** is less than 0.|

### OH_NativeImage_SetDropBufferMode()

```
int32_t OH_NativeImage_SetDropBufferMode(OH_NativeImage* image, bool isOpen)
```

**Description**

Sets the frame-dropping mode for rendering of an **OH_NativeImage** instance.<br>In frame-dropping mode, most buffers produced by the producer are discarded, and only the latest buffer is rendered promptly.<br>This mode does not guarantee high frame rates.<br>It is recommended that you can call this function immediately after [OH_NativeImage_Create](capi-native-image-h.md#oh_nativeimage_create).<br>This function takes effect only when it is used together with [OH_NativeImage_UpdateSurfaceImage](capi-native-image-h.md#oh_nativeimage_updatesurfaceimage).<br>This function is not thread-safe.<br>The number of listener callbacks set by [OH_NativeImage_SetOnFrameAvailableListener](capi-native-image-h.md#oh_nativeimage_setonframeavailablelistener) does not decrease because the frame loss mode is set.<br>

**System capability**: SystemCapability.Graphic.Graphic2D.NativeImage

**Since**: 17


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeImage](capi-oh-nativeimage-oh-nativeimage.md)* image | Pointer to an **OH_NativeImage** instance.|
| bool isOpen | Whether to set the frame-dropping mode. The value **true** means to set the frame-dropping mode, and **false** means the opposite.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns **NATIVE_ERROR_OK** if the operation is successful.<br> Returns **NATIVE_ERROR_INVALID_ARGUMENTS** if **image** is a null pointer.|
