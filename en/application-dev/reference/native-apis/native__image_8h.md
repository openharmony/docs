# native_image.h


## Overview

The **native_image.h** file declares the functions for obtaining and using **NativeImage**.

**Since**

9

**Related Modules**

[OH_NativeImage](_o_h___native_image.md)


## Summary


### Types

| Name| Description|
| -------- | -------- |
| [OH_NativeImage](_o_h___native_image.md#oh_nativeimage) | Provides the declaration of an **OH_NativeImage** struct.|
| [OHNativeWindow](_o_h___native_image.md#ohnativewindow) | Provides the capability of accessing the **NativeWindow**.|


### Functions

| Name| Description|
| -------- | -------- |
| [OH_NativeImage_Create](_o_h___native_image.md#oh_nativeimage_create) (uint32_t textureId, uint32_t textureTarget) | Creates an **OH_NativeImage** instance to be associated with the OpenGL ES texture ID and target.|
| [OH_NativeImage_AcquireNativeWindow](_o_h___native_image.md#oh_nativeimage_acquirenativewindow) (OH_NativeImage \*image) | Obtains an **OHNativeWindow** instance associated with an **OH_NativeImage** instance. You need to call **OH_NativeWindow_DestroyNativeWindow** to release the **OHNativeWindow** instance when it is no longer required. |
| [OH_NativeImage_AttachContext](_o_h___native_image.md#oh_nativeimage_attachcontext) (OH_NativeImage \*image, uint32_t textureId) | Attaches an **OH_NativeImage** instance to the current OpenGL ES context.<br>The OpenGL ES texture will be bound to an **GL_TEXTURE_EXTERNAL_OES** instance and updated through the **OH_NativeImage** instance.|
| [OH_NativeImage_DetachContext](_o_h___native_image.md#oh_nativeimage_detachcontext) (OH_NativeImage \*image) | Detaches an **OH_NativeImage** instance from the current OpenGL ES context.|
| [OH_NativeImage_UpdateSurfaceImage](_o_h___native_image.md#oh_nativeimage_updatesurfaceimage) (OH_NativeImage \*image) | Updates the OpenGL ES texture associated with the latest frame through an **OH_NativeImage** instance.|
| [OH_NativeImage_GetTimestamp](_o_h___native_image.md#oh_nativeimage_gettimestamp) (OH_NativeImage \*image) | Obtains the timestamp of the texture image that recently called the **OH_NativeImage_UpdateSurfaceImage** function.|
| [OH_NativeImage_GetTransformMatrix](_o_h___native_image.md#oh_nativeimage_gettransformmatrix) (OH_NativeImage \*image, float matrix[16]) | Obtains the transform matrix of the texture image that recently called the **OH_NativeImage_UpdateSurfaceImage** function.|
| [OH_NativeImage_Destroy](_o_h___native_image.md#oh_nativeimage_destroy) (OH_NativeImage \*\*image) | Destroys an **OH_NativeImage** instance created by calling **OH_NativeImage_Create**. After the instance is destroyed, the pointer to the **OH_NativeImage** instance is assigned **NULL**. |
