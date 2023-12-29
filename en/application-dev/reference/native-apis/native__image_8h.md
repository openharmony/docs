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
| [OH_OnFrameAvailableListener](_o_h___on_frame_available_listener.md) | Defines an **OH_NativeImage** listener, which is registered through **OH_NativeImage_SetOnFrameAvailableListener**. The listener triggers a callback when a frame is available.|


### Types

| Name| Description|
| -------- | -------- |
| [OH_NativeImage](_o_h___native_image.md#oh_nativeimage) | Provides the declaration of an **OH_NativeImage** struct.|
| [OHNativeWindow](_o_h___native_image.md#ohnativewindow) | Provides the capability of accessing the **NativeWindow**.|
| [OH_OnFrameAvailable](_o_h___native_image.md#oh_onframeavailable) | Defines the callback function triggered when a frame is available.|
| [OH_OnFrameAvailableListener](_o_h___native_image.md#oh_onframeavailablelistener) | Defines an **OH_NativeImage** listener, which is registered through **OH_NativeImage_SetOnFrameAvailableListener**. The listener triggers a callback when a frame is available.|


### Functions

| Name| Description|
| -------- | -------- |
| [OH_NativeImage_Create](_o_h___native_image.md#oh_nativeimage_create) (uint32_t textureId, uint32_t textureTarget) | Creates an **OH_NativeImage** instance to be associated with the OpenGL ES texture ID and target.|
| [OH_NativeImage_AcquireNativeWindow](_o_h___native_image.md#oh_nativeimage_acquirenativewindow) ([OH_NativeImage](_o_h___native_image.md#oh_nativeimage) \*image) | Obtains an **OHNativeWindow** instance associated with an **OH_NativeImage** instance. You need to call **OH_NativeWindow_DestroyNativeWindow** to release the **OHNativeWindow** instance when it is no longer required. |
| [OH_NativeImage_AttachContext](_o_h___native_image.md#oh_nativeimage_attachcontext) ([OH_NativeImage](_o_h___native_image.md#oh_nativeimage) \*image, uint32_t textureId) | Attaches an **OH_NativeImage** instance to the current OpenGL ES context.<br>The OpenGL ES texture will be bound to an **GL_TEXTURE_EXTERNAL_OES** instance and updated through the **OH_NativeImage** instance.|
| [OH_NativeImage_DetachContext](_o_h___native_image.md#oh_nativeimage_detachcontext) ([OH_NativeImage](_o_h___native_image.md#oh_nativeimage) \*image) | Detaches an **OH_NativeImage** instance from the current OpenGL ES context.|
| [OH_NativeImage_UpdateSurfaceImage](_o_h___native_image.md#oh_nativeimage_updatesurfaceimage) ([OH_NativeImage](_o_h___native_image.md#oh_nativeimage) \*image) | Updates the OpenGL ES texture associated with the latest frame through an **OH_NativeImage** instance.|
| [OH_NativeImage_GetTimestamp](_o_h___native_image.md#oh_nativeimage_gettimestamp) ([OH_NativeImage](_o_h___native_image.md#oh_nativeimage) \*image) | Obtains the timestamp of the texture image that recently called the **OH_NativeImage_UpdateSurfaceImage** function.|
| [OH_NativeImage_GetTransformMatrix](_o_h___native_image.md#oh_nativeimage_gettransformmatrix) ([OH_NativeImage](_o_h___native_image.md#oh_nativeimage) \*image, float matrix[16]) | Obtains the transform matrix of the texture image that recently called the **OH_NativeImage_UpdateSurfaceImage** function.|
| [OH_NativeImage_GetSurfaceId](_o_h___native_image.md#oh_nativeimage_getsurfaceid) ([OH_NativeImage](_o_h___native_image.md#oh_nativeimage) \*image, uint64_t \*surfaceId) | Obtains the surface ID of an **OH_NativeImage** instance.|
| [OH_NativeImage_SetOnFrameAvailableListener](_o_h___native_image.md#oh_nativeimage_setonframeavailablelistener) ([OH_NativeImage](_o_h___native_image.md#oh_nativeimage) \*image, [OH_OnFrameAvailableListener](_o_h___on_frame_available_listener.md) listener) | Registers a listener to listen for frame availability events.|
| [OH_NativeImage_UnsetOnFrameAvailableListener](_o_h___native_image.md#oh_nativeimage_unsetonframeavailablelistener) ([OH_NativeImage](_o_h___native_image.md#oh_nativeimage) \*image) | Deregisters the listener used to listen for frame availability events.|
| [OH_NativeImage_Destroy](_o_h___native_image.md#oh_nativeimage_destroy) ([OH_NativeImage](_o_h___native_image.md#oh_nativeimage) \*\*image) | Destroys an **OH_NativeImage** instance created by calling **OH_NativeImage_Create**. After the instance is destroyed, the pointer to the **OH_NativeImage** instance is assigned **NULL**.|
