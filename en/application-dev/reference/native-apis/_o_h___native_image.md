# OH_NativeImage


## Overview

The **OH_NativeImage** module provides the capabilities of **NativeImage**. Functioning as a data consumer, it is used to associate data with the OpenGL texture. It is used in the OpenGL environment.

\@syscap SystemCapability.Graphic.Graphic2D.OH_NativeImage

**Since**

9


## Summary


### Files

| Name| Description|
| -------- | -------- |
| [native_image.h](native__image_8h.md) | Defines the functions for obtaining and using **NativeImage**.<br>File to include: &lt;native_image/native_image.h&gt; |


### Types

| Name| Description|
| -------- | -------- |
| [OH_NativeImage](#oh_nativeimage) | Provides the declaration of an **OH_NativeImage** struct.|
| [OHNativeWindow](#ohnativewindow) | Provides the capability of accessing the **NativeWindow**.|


### Functions

| Name| Description|
| -------- | -------- |
| [OH_NativeImage_Create](#oh_nativeimage_create) (uint32_t textureId, uint32_t textureTarget) | Creates an **OH_NativeImage** instance to be associated with the OpenGL ES texture ID and target.|
| [OH_NativeImage_AcquireNativeWindow](#oh_nativeimage_acquirenativewindow) (OH_NativeImage \*image) | Obtains an **OHNativeWindow** instance associated with an **OH_NativeImage** instance. You need to call **OH_NativeWindow_DestroyNativeWindow** to release the **OHNativeWindow** instance when it is no longer required. |
| [OH_NativeImage_AttachContext](#oh_nativeimage_attachcontext) (OH_NativeImage \*image, uint32_t textureId) | Attaches an **OH_NativeImage** instance to the current OpenGL ES context.<br>The OpenGL ES texture will be bound to an **GL_TEXTURE_EXTERNAL_OES** instance and updated through the **OH_NativeImage** instance.|
| [OH_NativeImage_DetachContext](#oh_nativeimage_detachcontext) (OH_NativeImage \*image) | Detaches an **OH_NativeImage** instance from the current OpenGL ES context.|
| [OH_NativeImage_UpdateSurfaceImage](#oh_nativeimage_updatesurfaceimage) (OH_NativeImage \*image) | Updates the OpenGL ES texture associated with the latest frame through an **OH_NativeImage** instance.|
| [OH_NativeImage_GetTimestamp](#oh_nativeimage_gettimestamp) (OH_NativeImage*image) | Obtains the timestamp of the texture image that recently called the **OH_NativeImage_UpdateSurfaceImage** function.|
| [OH_NativeImage_GetTransformMatrix](#oh_nativeimage_gettransformmatrix) (OH_NativeImage \*image, float matrix[16]) | Obtains the transform matrix of the texture image that recently called the **OH_NativeImage_UpdateSurfaceImage** function.|
| [OH_NativeImage_Destroy](#oh_nativeimage_destroy) (OH_NativeImage \*\*image) | Destroys an **OH_NativeImage** instance created by calling **OH_NativeImage_Create**. After the instance is destroyed, the pointer to the **OH_NativeImage** instance is assigned **NULL**. |


## Type Description


### OH_NativeImage


```
typedef struct OH_NativeImage OH_NativeImage
```

**Description**

Provides the declaration of an **OH_NativeImage** struct.


### OHNativeWindow


```
typedef struct NativeWindow OHNativeWindow
```

**Description**

Provides the capability of accessing the **NativeWindow**.


## Function Description


### OH_NativeImage_AcquireNativeWindow()


```
OHNativeWindow* OH_NativeImage_AcquireNativeWindow (OH_NativeImage * image)
```

**Description**

Obtains an **OHNativeWindow** instance associated with an **OH_NativeImage** instance. You need to call **OH_NativeWindow_DestroyNativeWindow** to release the **OHNativeWindow** instance when it is no longer required. 

\@syscap SystemCapability.Graphic.Graphic2D.OH_NativeImage

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

\@syscap SystemCapability.Graphic.Graphic2D.OH_NativeImage

**Parameters**

| Name| Description|
| -------- | -------- |
| image | Pointer to an **OH_NativeImage** instance.|
| textureId | ID of the OpenGL ES texture to which the **OH_NativeImage** instance is to be attached.|

**Returns**

Returns **0** if the operation is successful.


### OH_NativeImage_Create()


```
OH_NativeImage* OH_NativeImage_Create (uint32_t textureId, uint32_t textureTarget )
```

**Description**

Creates an **OH_NativeImage** instance to be associated with the OpenGL ES texture ID and target.

\@syscap SystemCapability.Graphic.Graphic2D.OH_NativeImage

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

Destroys an **OH_NativeImage** instance created by calling **OH_NativeImage_Create**. After the instance is destroyed, the pointer to the **OH_NativeImage** instance is assigned **NULL**.

\@syscap SystemCapability.Graphic.Graphic2D.OH_NativeImage

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

\@syscap SystemCapability.Graphic.Graphic2D.OH_NativeImage

**Parameters**

| Name| Description|
| -------- | -------- |
| image | Pointer to an **OH_NativeImage** instance.|

**Returns**

Returns **0** if the operation is successful.


### OH_NativeImage_GetTimestamp()


```
int64_t OH_NativeImage_GetTimestamp (OH_NativeImage * image)
```

**Description**

Obtains the timestamp of the texture image that recently called the **OH_NativeImage_UpdateSurfaceImage** function.

\@syscap SystemCapability.Graphic.Graphic2D.OH_NativeImage

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

Obtains the transform matrix of the texture image that recently called the **OH_NativeImage_UpdateSurfaceImage** function.

\@syscap SystemCapability.Graphic.Graphic2D.OH_NativeImage

**Parameters**

| Name| Description|
| -------- | -------- |
| image | Pointer to an **OH_NativeImage** instance.|
| matrix | Buffer used to store the 4 \* 4 transform matrix obtained.|

**Returns**

Returns **0** if the operation is successful.


### OH_NativeImage_UpdateSurfaceImage()


```
int32_t OH_NativeImage_UpdateSurfaceImage (OH_NativeImage * image)
```

**Description**

Updates the OpenGL ES texture associated with the latest frame through an **OH_NativeImage** instance.

\@syscap SystemCapability.Graphic.Graphic2D.OH_NativeImage

**Parameters**

| Name| Description|
| -------- | -------- |
| image | Pointer to an **OH_NativeImage** instance.|

**Returns**

Returns **0** if the operation is successful.
