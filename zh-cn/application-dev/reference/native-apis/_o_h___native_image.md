# OH_NativeImage


## 概述

提供NativeImage功能，作为数据消费者，主要用来将数据和OpenGL纹理对接，需在OpenGL环境下使用

\@syscap SystemCapability.Graphic.Graphic2D.OH_NativeImage

**起始版本:**

9


## 汇总


### 文件

| 名称 | 描述 |
| -------- | -------- |
| [native_image.h](native__image_8h.md) | 定义获取和使用NativeImage的相关函数<br/>引用文件：&lt;native_image/native_image.h&gt; |


### 类型定义

| 名称 | 描述 |
| -------- | -------- |
| [OH_NativeImage](#oh_nativeimage) | 提供OH_NativeImage结构体声明 |
| [OHNativeWindow](#ohnativewindow) | 提供对NativeWindow的访问功能 |


### 函数

| 名称 | 描述 |
| -------- | -------- |
| [OH_NativeImage_Create](#oh_nativeimage_create) (uint32_t textureId, uint32_t textureTarget) | 创建一个**OH_NativeImage**实例，该实例与OpenGL ES的纹理ID和纹理目标相关联 |
| [OH_NativeImage_AcquireNativeWindow](#oh_nativeimage_acquirenativewindow) (OH_NativeImage \*image) | 获取与OH_NativeImage相关联的OHNativeWindow指针. 该OHNativeWindow后续不再需要时需要调用<br/>OH_NativeWindow_DestroyNativeWindow释放 |
| [OH_NativeImage_AttachContext](#oh_nativeimage_attachcontext) (OH_NativeImage \*image, uint32_t textureId) | 将OH_NativeImage实例附加到当前OpenGL ES上下文, 且该OpenGL ES纹理会绑定到<br/>GL_TEXTURE_EXTERNAL_OES, 并通过OH_NativeImage进行更新 |
| [OH_NativeImage_DetachContext](#oh_nativeimage_detachcontext) (OH_NativeImage \*image) | 将OH_NativeImage实例从当前OpenGL ES上下文分离 |
| [OH_NativeImage_UpdateSurfaceImage](#oh_nativeimage_updatesurfaceimage) (OH_NativeImage \*image) | 通过OH_NativeImage获取最新帧更新相关联的OpenGL ES纹理 |
| [OH_NativeImage_GetTimestamp](#oh_nativeimage_gettimestamp) (OH_NativeImage*image) | 获取最近调用OH_NativeImage_UpdateSurfaceImage的纹理图像的相关时间戳 |
| [OH_NativeImage_GetTransformMatrix](#oh_nativeimage_gettransformmatrix) (OH_NativeImage \*image, float matrix[16]) | 获取最近调用OH_NativeImage_UpdateSurfaceImage的纹理图像的变化矩阵 |
| [OH_NativeImage_Destroy](#oh_nativeimage_destroy) (OH_NativeImage \*\*image) | 销毁通过OH_NativeImage_Create创建的**OH_NativeImage**实例, 销毁后该<br/>**OH_NativeImage**指针会被赋值为空 |


## 类型定义说明


### OH_NativeImage


```
typedef struct OH_NativeImage OH_NativeImage
```

**描述:**

提供OH_NativeImage结构体声明


### OHNativeWindow


```
typedef struct NativeWindow OHNativeWindow
```

**描述:**

提供对NativeWindow的访问功能


## 函数说明


### OH_NativeImage_AcquireNativeWindow()


```
OHNativeWindow* OH_NativeImage_AcquireNativeWindow (OH_NativeImage * image)
```

**描述:**

获取与OH_NativeImage相关联的OHNativeWindow指针. 该OHNativeWindow后续不再需要时需要调用

OH_NativeWindow_DestroyNativeWindow释放

\@syscap SystemCapability.Graphic.Graphic2D.OH_NativeImage

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| image | 指向OH_NativeImage实例的指针。 |

**返回:**

成功则返回一个指向OHNativeWindow实例的指针，否则返回**NULL**


### OH_NativeImage_AttachContext()


```
int32_t OH_NativeImage_AttachContext (OH_NativeImage * image, uint32_t textureId )
```

**描述:**

将OH_NativeImage实例附加到当前OpenGL ES上下文, 且该OpenGL ES纹理会绑定到

GL_TEXTURE_EXTERNAL_OES, 并通过OH_NativeImage进行更新

\@syscap SystemCapability.Graphic.Graphic2D.OH_NativeImage

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| image | 指向OH_NativeImage实例的指针。 |
| textureId | OH_NativeImage要附加到的OpenGL ES纹理的id。 |

**返回:**

返回值为0表示执行成功


### OH_NativeImage_Create()


```
OH_NativeImage* OH_NativeImage_Create (uint32_t textureId, uint32_t textureTarget )
```

**描述:**

创建一个**OH_NativeImage**实例，该实例与OpenGL ES的纹理ID和纹理目标相关联

\@syscap SystemCapability.Graphic.Graphic2D.OH_NativeImage

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| textureId | OpenGL ES的纹理ID，OH_NativeImage实例会与之相关联 |
| textureTarget | OpenGL ES的纹理目标 |

**返回:**

返回一个指向**OH_NativeImage**实例的指针 returns **NULL** otherwise


### OH_NativeImage_Destroy()


```
void OH_NativeImage_Destroy (OH_NativeImage ** image)
```

**描述:**

销毁通过OH_NativeImage_Create创建的**OH_NativeImage**实例, 销毁后该

**OH_NativeImage**指针会被赋值为空

\@syscap SystemCapability.Graphic.Graphic2D.OH_NativeImage

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| image | 指向OH_NativeImage实例的指针。 |


### OH_NativeImage_DetachContext()


```
int32_t OH_NativeImage_DetachContext (OH_NativeImage * image)
```

**描述:**

将OH_NativeImage实例从当前OpenGL ES上下文分离

\@syscap SystemCapability.Graphic.Graphic2D.OH_NativeImage

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| image | 指向OH_NativeImage实例的指针。 |

**返回:**

返回值为0表示执行成功


### OH_NativeImage_GetTimestamp()


```
int64_t OH_NativeImage_GetTimestamp (OH_NativeImage * image)
```

**描述:**

获取最近调用OH_NativeImage_UpdateSurfaceImage的纹理图像的相关时间戳

\@syscap SystemCapability.Graphic.Graphic2D.OH_NativeImage

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| image | 指向OH_NativeImage实例的指针。 |

**返回:**

返回纹理图像的相关时间戳


### OH_NativeImage_GetTransformMatrix()


```
int32_t OH_NativeImage_GetTransformMatrix (OH_NativeImage * image, float matrix[16] )
```

**描述:**

获取最近调用OH_NativeImage_UpdateSurfaceImage的纹理图像的变化矩阵

\@syscap SystemCapability.Graphic.Graphic2D.OH_NativeImage

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| image | 指向OH_NativeImage实例的指针。 |
| matrix | 用来存储要获取的4\*4的变化矩阵。 |

**返回:**

返回值为0表示执行成功


### OH_NativeImage_UpdateSurfaceImage()


```
int32_t OH_NativeImage_UpdateSurfaceImage (OH_NativeImage * image)
```

**描述:**

通过OH_NativeImage获取最新帧更新相关联的OpenGL ES纹理

\@syscap SystemCapability.Graphic.Graphic2D.OH_NativeImage

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| image | 指向OH_NativeImage实例的指针。 |

**返回:**

返回值为0表示执行成功
