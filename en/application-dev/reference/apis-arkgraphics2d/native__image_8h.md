# native_image.h


## Overview

The **native_image.h** file declares the functions for obtaining and using **NativeImage**.

**Library**: libnative_image.so

**Since**: 9

**Related module**: [OH_NativeImage](_o_h___native_image.md)


## Summary


### Structs

| Name| Description|
| -------- | -------- |
| [OH_OnFrameAvailableListener](_o_h___on_frame_available_listener.md) | Describes an **OH_NativeImage** listener, which is registered through **OH_NativeImage_SetOnFrameAvailableListener**. The listener triggers a callback when a frame is available.|


### Types

| Name| Description|
| -------- | -------- |
| typedef struct [OH_NativeImage](_o_h___native_image.md#oh_nativeimage)  [OH_NativeImage](_o_h___native_image.md#oh_nativeimage) | Provides the declaration of an **OH_NativeImage** struct. | 
| typedef struct NativeWindow [OHNativeWindow](_o_h___native_image.md#ohnativewindow) | Provides the capability of accessing the **NativeWindow**. | 
| typedef struct NativeWindowBuffer [OHNativeWindowBuffer](_o_h___native_image.md#ohnativewindowbuffer) | Provides the declaration of a **NativeWindowBuffer** struct.|
| typedef void(\* [OH_OnFrameAvailable](_o_h___native_image.md#oh_onframeavailable)) (void \*context) | Defines the callback function triggered when a frame is available. | 
| typedef struct [OH_OnFrameAvailableListener](_o_h___on_frame_available_listener.md)  [OH_OnFrameAvailableListener](_o_h___native_image.md#oh_onframeavailablelistener) | Defines an **OH_NativeImage** listener, which is registered through {\@link OH_NativeImage_SetOnFrameAvailableListener}. The listener triggers a callback when a frame is available. | 
| typedef enum [OHNativeErrorCode](_o_h___native_image.md#ohnativeerrorcode)  [OHNativeErrorCode](_o_h___native_image.md#ohnativeerrorcode) | Defines an enum for the error codes. | 

### Enums

| Name| Description| 
| -------- | -------- |
| [OHNativeErrorCode](_o_h___native_image.md#ohnativeerrorcode-1) {<br>NATIVE_ERROR_OK = 0, NATIVE_ERROR_MEM_OPERATION_ERROR = 30001000, NATIVE_ERROR_INVALID_ARGUMENTS = 40001000, NATIVE_ERROR_NO_PERMISSION = 40301000, NATIVE_ERROR_NO_BUFFER = 40601000,<br>NATIVE_ERROR_NO_CONSUMER = 41202000, NATIVE_ERROR_NOT_INIT = 41203000, NATIVE_ERROR_CONSUMER_CONNECTED = 41206000, NATIVE_ERROR_BUFFER_STATE_INVALID = 41207000,<br>NATIVE_ERROR_BUFFER_IN_CACHE = 41208000, NATIVE_ERROR_BUFFER_QUEUE_FULL = 41209000, NATIVE_ERROR_BUFFER_NOT_IN_CACHE = 41210000, NATIVE_ERROR_CONSUMER_DISCONNECTED = 41211000,NATIVE_ERROR_CONSUMER_NO_LISTENER_REGISTERED = 41212000,NATIVE_ERROR_UNSUPPORTED = 50102000,<br>NATIVE_ERROR_UNKNOWN = 50002000,NATIVE_ERROR_HDI_ERROR = 50007000,NATIVE_ERROR_BINDER_ERROR = 50401000, NATIVE_ERROR_EGL_STATE_UNKNOWN = 60001000, NATIVE_ERROR_EGL_API_FAILED = 60002000<br>} | Enumerates the error codes. | 


### Functions

| Name| Description| 
| -------- | -------- |
| int32_t [OH_NativeImage_SetDropBufferMode](_o_h___native_image.md#oh_nativeimage_setdropbuffermode) ([OH_NativeImage](_o_h___native_image.md#oh_nativeimage) \*image, bool isOpen) | Sets the frame-dropping mode for rendering of an **OH_NativeImage** instance.<br>In frame-dropping mode, most buffers produced by the producer are discarded, and only the latest buffer is rendered promptly.<br>This mode does not guarantee high frame rates.<br>It is recommended that you can call this function immediately after [OH_NativeImage_Create](_o_h___native_image.md#oh_nativeimage_create).<br>This function takes effect only when it is used together with [OH_NativeImage_UpdateSurfaceImage](_o_h___native_image.md#oh_nativeimage_updatesurfaceimage).<br>This function is not thread-safe.| 
| [OH_NativeImage](_o_h___native_image.md#oh_nativeimage) \* [OH_NativeImage_Create](_o_h___native_image.md#oh_nativeimage_create) (uint32_t textureId, uint32_t textureTarget) | Creates an **OH_NativeImage** instance to be associated with the OpenGL ES texture ID and target.<br>This function must be used in pair with [OH_NativeImage_Destroy](_o_h___native_image.md#oh_nativeimage_destroy). Otherwise, memory leak occurs.<br>This function is not thread-safe.| 
| [OHNativeWindow](_native_window.md#ohnativewindow) \* [OH_NativeImage_AcquireNativeWindow](_o_h___native_image.md#oh_nativeimage_acquirenativewindow) ([OH_NativeImage](_o_h___native_image.md#oh_nativeimage) \*image) | Obtains an **OHNativeWindow** instance associated with an **OH_NativeImage** instance.<br>This function is not thread-safe.<br>When **OH_NativeImage** is being destructed, the corresponding **OHNativeWindow** instance is released. If the **OHNativeWindow** pointer is obtained by using this function, set the pointer to null when releasing the **OH_NativeImage** instance, so as to prevent subsequent wild pointers.| 
| int32_t [OH_NativeImage_AttachContext](_o_h___native_image.md#oh_nativeimage_attachcontext) ([OH_NativeImage](_o_h___native_image.md#oh_nativeimage) \*image, uint32_t textureId) | Attaches an **OH_NativeImage** instance to the current OpenGL ES context. The OpenGL ES texture will be bound to an **GL_TEXTURE_EXTERNAL_OES** instance and updated through the **OH_NativeImage** instance.<br>This function is not thread-safe.| 
| int32_t [OH_NativeImage_DetachContext](_o_h___native_image.md#oh_nativeimage_detachcontext) ([OH_NativeImage](_o_h___native_image.md#oh_nativeimage) \*image) | Detaches an **OH_NativeImage** instance from the current OpenGL ES context.<br>This function is not thread-safe.| 
| int32_t [OH_NativeImage_UpdateSurfaceImage](_o_h___native_image.md#oh_nativeimage_updatesurfaceimage) ([OH_NativeImage](_o_h___native_image.md#oh_nativeimage) \*image) | Updates the OpenGL ES texture associated with the latest frame through an **OH_NativeImage** instance.<br>This function must be called in a thread of the OpenGL ES context.<br>This function must be called after the [OH_OnFrameAvailableListener](_o_h___on_frame_available_listener.md) callback is triggered.<br>This function is not thread-safe.| 
| int64_t [OH_NativeImage_GetTimestamp](_o_h___native_image.md#oh_nativeimage_gettimestamp) ([OH_NativeImage](_o_h___native_image.md#oh_nativeimage) \*image) | Obtains the timestamp of the texture image that recently called the **OH_NativeImage_UpdateSurfaceImage** function.<br>This function is not thread-safe.| 
| int32_t [OH_NativeImage_GetTransformMatrix](_o_h___native_image.md#oh_nativeimage_gettransformmatrix) ([OH_NativeImage](_o_h___native_image.md#oh_nativeimage) \*image, float matrix[16]) | Obtains the transformation matrix of the texture image that recently called the **OH_NativeImage_UpdateSurfaceImage** function.| 
| int32_t [OH_NativeImage_GetSurfaceId](_o_h___native_image.md#oh_nativeimage_getsurfaceid) ([OH_NativeImage](_o_h___native_image.md#oh_nativeimage) \*image, uint64_t \*surfaceId) | Obtains the surface ID of an **OH_NativeImage** instance.<br>This function is not thread-safe.| 
| int32_t [OH_NativeImage_SetOnFrameAvailableListener](_o_h___native_image.md#oh_nativeimage_setonframeavailablelistener) ([OH_NativeImage](_o_h___native_image.md#oh_nativeimage) \*image, [OH_OnFrameAvailableListener](_o_h___on_frame_available_listener.md) listener) | Registers a listener to listen for frame availability events.<br>Do not call other functions of this module in the callback.<br>This function is not thread-safe.| 
| int32_t [OH_NativeImage_UnsetOnFrameAvailableListener](_o_h___native_image.md#oh_nativeimage_unsetonframeavailablelistener) ([OH_NativeImage](_o_h___native_image.md#oh_nativeimage) \*image) | Deregisters the listener used to listen for frame availability events.<br>This function is not thread-safe.| 
| void [OH_NativeImage_Destroy](_o_h___native_image.md#oh_nativeimage_destroy) ([OH_NativeImage](_o_h___native_image.md#oh_nativeimage) \*\*image) | Destroys an **OH_NativeImage** instance created by calling **OH_NativeImage_Create**. After the instance is destroyed, the pointer to the **OH_NativeImage** instance is assigned **NULL**.<br>This function is not thread-safe.| 
| int32_t [OH_NativeImage_GetTransformMatrixV2](_o_h___native_image.md#oh_nativeimage_gettransformmatrixv2) ([OH_NativeImage](_o_h___native_image.md#oh_nativeimage) \*image, float matrix[16]) | Obtains, based on the rotation angle set by the producer, the transform matrix of the texture image that recently called the **OH_NativeImage_UpdateSurfaceImage** function.<br>The matrix is updated only after [OH_NativeImage_UpdateSurfaceImage](_o_h___native_image.md#oh_nativeimage_updatesurfaceimage) is called.<br>This function is not thread-safe.| 
| int32_t [OH_NativeImage_GetBufferMatrix](_o_h___native_image.md#oh_nativeimage_getbuffermatrix) ([OH_NativeImage](_o_h___native_image.md#oh_nativeimage) \*image, float matrix[16]) | Obtains the transformation matrix calculated based on the rotation angle set by the producer and the actual valid content area of the buffer.| 
| int32_t [OH_NativeImage_AcquireNativeWindowBuffer](_o_h___native_image.md#oh_nativeimage_acquirenativewindowbuffer) ([OH_NativeImage](_o_h___native_image.md#oh_nativeimage) \*image, [OHNativeWindowBuffer](_native_window.md#ohnativewindowbuffer) \*\*nativeWindowBuffer, int \*fenceFd) | Obtains an **OHNativeWindowBuffer** instance through an **OH_NativeImage** instance on the consumer side.<br>This function cannot be used together with [OH_NativeImage_UpdateSurfaceImage](_o_h___native_image.md#oh_nativeimage_updatesurfaceimage).<br>This function creates an **OHNativeWindowBuffer**.<br>When using the **OHNativeWindowBuffer**, call [OH_NativeWindow_NativeObjectReference](_native_window.md#oh_nativewindow_nativeobjectreference) to increase its reference count by one.<br>When finishing using the **OHNativeWindowBuffer**, call [OH_NativeWindow_NativeObjectUnreference](_native_window.md#oh_nativewindow_nativeobjectunreference) to decrease the reference count by one.<br>This function must be used in pair with [OH_NativeImage_ReleaseNativeWindowBuffer](_o_h___native_image.md#oh_nativeimage_releasenativewindowbuffer). Otherwise, memory leak occurs.<br>When **fenceFd** is used up, you must close it.<br>This function is not thread-safe.| 
| int32_t [OH_NativeImage_ReleaseNativeWindowBuffer](_o_h___native_image.md#oh_nativeimage_releasenativewindowbuffer) ([OH_NativeImage](_o_h___native_image.md#oh_nativeimage) \*image, [OHNativeWindowBuffer](_native_window.md#ohnativewindowbuffer) \*nativeWindowBuffer, int fenceFd) | Releases an **OHNativeWindowBuffer** instance through an **OH_NativeImage** instance.<br>The system will close **fenceFd**. You do not need to close it.<br>This function is not thread-safe.| 
| [OH_NativeImage](_o_h___native_image.md#oh_nativeimage) \* [OH_ConsumerSurface_Create](_o_h___native_image.md#oh_consumersurface_create) () | Creates an **OH_NativeImage** instance as the consumer of the surface.<br>This function is used only for memory cycling of the surface consumer. Memory rendering is not proactively performed in the created **OH_NativeImage** instance.<br>This function cannot be used together with [OH_NativeImage_UpdateSurfaceImage](_o_h___native_image.md#oh_nativeimage_updatesurfaceimage).<br>This function must be used in pair with **OH_NativeImage_AcquireNativeWindowBuffer** and **OH_NativeImage_ReleaseNativeWindowBuffer**.<br>This function must be used in pair with [OH_NativeImage_Destroy](_o_h___native_image.md#oh_nativeimage_destroy). Otherwise, memory leak occurs.<br>This function is not thread-safe.| 
| int32_t [OH_ConsumerSurface_SetDefaultUsage](_o_h___native_image.md#oh_consumersurface_setdefaultusage) ([OH_NativeImage](_o_h___native_image.md#oh_nativeimage) \*image, uint64_t usage) | Sets the default read/write mode. This function is not thread-safe.| 
| int32_t [OH_ConsumerSurface_SetDefaultSize](_o_h___native_image.md#oh_consumersurface_setdefaultsize) ([OH_NativeImage](_o_h___native_image.md#oh_nativeimage) \*image, int32_t width, int32_t height) | Sets the default size of a geometric shape. This function is not thread-safe.| 
