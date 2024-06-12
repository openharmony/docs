# OH_NativeImage


## 概述

提供NativeImage功能，作为数据消费者，主要用来将数据和OpenGL纹理对接，需在OpenGL环境下使用。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeImage

**起始版本：** 9


## 汇总


### 文件

| 名称 | 描述 |
| -------- | -------- |
| [native_image.h](native__image_8h.md) | 定义获取和使用NativeImage的相关函数。 |


### 结构体

| 名称 | 描述 |
| -------- | -------- |
| [OH_OnFrameAvailableListener](_o_h___on_frame_available_listener.md) | 一个OH_NativeImage的监听者，通过OH_NativeImage_SetOnFrameAvailableListener接口注册， 该监听结构体当有帧可用时，将触发回调。 |


### 类型定义

| 名称 | 描述 |
| -------- | -------- |
| typedef struct [OH_NativeImage](#oh_nativeimage)  [OH_NativeImage](#oh_nativeimage) | 提供OH_NativeImage结构体声明。  | 
| typedef struct NativeWindow [OHNativeWindow](#ohnativewindow) | 提供对NativeWindow的访问功能。  | 
| typedef void(\* [OH_OnFrameAvailable](#oh_onframeavailable)) (void \*context) | 有buffer可获取时触发的回调函数。  | 
| typedef struct [OH_OnFrameAvailableListener](_o_h___on_frame_available_listener.md)  [OH_OnFrameAvailableListener](#oh_onframeavailablelistener) | 一个OH_NativeImage的监听者，通过{\@Link OH_NativeImage_SetOnFrameAvailableListener}接口注册 该监听结构体，当有buffer可获取时，将触发回调给用户。  | 
| typedef enum [OHNativeErrorCode](#ohnativeerrorcode)  [OHNativeErrorCode](#ohnativeerrorcode) | 接口错误码说明（仅用于查询）。  | 

### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OHNativeErrorCode](#ohnativeerrorcode) {<br/>NATIVE_ERROR_OK = 0, NATIVE_ERROR_INVALID_ARGUMENTS = 40001000, NATIVE_ERROR_NO_PERMISSION = 40301000, NATIVE_ERROR_NO_BUFFER = 40601000,<br/>NATIVE_ERROR_NO_CONSUMER = 41202000, NATIVE_ERROR_NOT_INIT = 41203000, NATIVE_ERROR_CONSUMER_CONNECTED = 41206000, NATIVE_ERROR_BUFFER_STATE_INVALID = 41207000,<br/>NATIVE_ERROR_BUFFER_IN_CACHE = 41208000, NATIVE_ERROR_BUFFER_QUEUE_FULL = 41209000, NATIVE_ERROR_BUFFER_NOT_IN_CACHE = 41210000, NATIVE_ERROR_UNSUPPORT = 50102000,<br/>NATIVE_ERROR_UNKNOWN = 50002000, NATIVE_ERROR_EGL_STATE_UNKNOWN = 60001000, NATIVE_ERROR_EGL_API_FAILED = 60002000 | 接口错误码说明（仅用于查询）。  | 

### 函数

| 名称 | 描述 |
| -------- | -------- |
| [OH_NativeImage_Create](#oh_nativeimage_create) (uint32_t textureId, uint32_t textureTarget) | 创建一个**OH_NativeImage**实例，该实例与OpenGL ES的纹理ID和纹理目标相关联。 |
| [OH_NativeImage_AcquireNativeWindow](#oh_nativeimage_acquirenativewindow) ([OH_NativeImage](#oh_nativeimage) \*image) | 获取与OH_NativeImage相关联的OHNativeWindow指针。 该OHNativeWindow后续不再需要时需要调用<br/>OH_NativeWindow_DestroyNativeWindow释放。 |
| [OH_NativeImage_AttachContext](#oh_nativeimage_attachcontext) ([OH_NativeImage](#oh_nativeimage) \*image, uint32_t textureId) | 将OH_NativeImage实例附加到当前OpenGL ES上下文, 且该OpenGL ES纹理会绑定到<br/>GL_TEXTURE_EXTERNAL_OES, 并通过OH_NativeImage进行更新。 |
| [OH_NativeImage_DetachContext](#oh_nativeimage_detachcontext) ([OH_NativeImage](#oh_nativeimage) \*image) | 将OH_NativeImage实例从当前OpenGL ES上下文分离。 |
| [OH_NativeImage_UpdateSurfaceImage](#oh_nativeimage_updatesurfaceimage) ([OH_NativeImage](#oh_nativeimage) \*image) | 通过OH_NativeImage获取最新帧更新相关联的OpenGL ES纹理。 |
| [OH_NativeImage_GetTimestamp](#oh_nativeimage_gettimestamp) ([OH_NativeImage](#oh_nativeimage) \*image) | 获取最近调用OH_NativeImage_UpdateSurfaceImage的纹理图像的相关时间戳。 |
| [OH_NativeImage_GetTransformMatrix](#oh_nativeimage_gettransformmatrix) ([OH_NativeImage](#oh_nativeimage) \*image, float matrix[16]) | 获取最近调用OH_NativeImage_UpdateSurfaceImage的纹理图像的变化矩阵。 |
| [OH_NativeImage_GetSurfaceId](#oh_nativeimage_getsurfaceid) ([OH_NativeImage](#oh_nativeimage) \*image, uint64_t \*surfaceId) | 获取OH_NativeImage的surface编号。 |
| [OH_NativeImage_SetOnFrameAvailableListener](#oh_nativeimage_setonframeavailablelistener) ([OH_NativeImage](#oh_nativeimage) \*image, [OH_OnFrameAvailableListener](_o_h___on_frame_available_listener.md) listener) | 设置帧可用回调。 |
| [OH_NativeImage_UnsetOnFrameAvailableListener](#oh_nativeimage_unsetonframeavailablelistener) ([OH_NativeImage](#oh_nativeimage) \*image) | 取消设置帧可用回调。 |
| [OH_NativeImage_Destroy](#oh_nativeimage_destroy) ([OH_NativeImage](#oh_nativeimage) \*\*image) | 销毁通过OH_NativeImage_Create创建的**OH_NativeImage**实例, 销毁后该**OH_NativeImage**指针会被赋值为空。 |
| int32_t [OH_NativeImage_GetTransformMatrixV2](#oh_nativeimage_gettransformmatrixv2) ([OH_NativeImage](#oh_nativeimage) \*image, float matrix[16]) | 根据生产端设置的旋转角度，获取最近调用OH_NativeImage_UpdateSurfaceImage的纹理图像的变化矩阵。  |

## 类型定义说明


### OH_NativeImage

```
typedef struct OH_NativeImage OH_NativeImage
```

**描述**

提供OH_NativeImage结构体声明。

**起始版本：** 9


### OH_OnFrameAvailable

```
typedef void(* OH_OnFrameAvailable) (void *context)
```

**描述**

有buffer可获取时触发的回调函数。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeImage

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| context | 用户自定义的上下文信息，会在回调触发时返回给用户。 |


### OH_OnFrameAvailableListener

```
typedef struct OH_OnFrameAvailableListener OH_OnFrameAvailableListener
```

**描述**

一个OH_NativeImage的监听者，通过[OH_NativeImage_SetOnFrameAvailableListener](#oh_nativeimage_setonframeavailablelistener)接口注册， 该监听结构体，当有buffer可获取时，将触发回调给用户。

**起始版本：** 11


### OHNativeErrorCode

```
typedef enum OHNativeErrorCode OHNativeErrorCode
```
**描述**

接口错误码说明（仅用于查询）。

**起始版本：** 12


### OHNativeWindow

```
typedef struct NativeWindow OHNativeWindow
```

**描述**

提供对NativeWindow的访问功能。

**起始版本：** 9


## 枚举类型说明


### OHNativeErrorCode

```
enum OHNativeErrorCode
```
**描述**

接口错误码说明（仅用于查询）。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| NATIVE_ERROR_OK  | 成功   | 
| NATIVE_ERROR_INVALID_ARGUMENTS  | 入参无效   | 
| NATIVE_ERROR_NO_PERMISSION  | 无权限操作   | 
| NATIVE_ERROR_NO_BUFFER  | 无空闲可用的buffer   | 
| NATIVE_ERROR_NO_CONSUMER  | 消费端不存在   | 
| NATIVE_ERROR_NOT_INIT  | 未初始化   | 
| NATIVE_ERROR_CONSUMER_CONNECTED  | 消费端已经被连接   | 
| NATIVE_ERROR_BUFFER_STATE_INVALID  | buffer状态不符合预期   | 
| NATIVE_ERROR_BUFFER_IN_CACHE  | buffer已在缓存队列中   | 
| NATIVE_ERROR_BUFFER_QUEUE_FULL  | 队列已满   | 
| NATIVE_ERROR_BUFFER_NOT_IN_CACHE  | buffer不在缓存队列中   | 
| NATIVE_ERROR_UNSUPPORT  | 当前设备或平台不支持   | 
| NATIVE_ERROR_UNKNOWN  | 未知错误，请查看日志   | 
| NATIVE_ERROR_EGL_STATE_UNKNOWN  | egl环境状态异常   | 
| NATIVE_ERROR_EGL_API_FAILED  | egl接口调用失败   | 


## 函数说明


### OH_NativeImage_AcquireNativeWindow()

```
OHNativeWindow* OH_NativeImage_AcquireNativeWindow (OH_NativeImage * image)
```

**描述**

获取与OH_NativeImage相关联的OHNativeWindow指针. 该OHNativeWindow后续不再需要时需要调用

OH_NativeWindow_DestroyNativeWindow释放。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeImage

**起始版本：** 9

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| image | 是指向**OH_NativeImage**实例的指针。 |

**返回：**

成功则返回一个指向OHNativeWindow实例的指针，否则返回**NULL**。


### OH_NativeImage_AttachContext()

```
int32_t OH_NativeImage_AttachContext (OH_NativeImage * image, uint32_t textureId )
```

**描述**

将OH_NativeImage实例附加到当前OpenGL ES上下文, 且该OpenGL ES纹理会绑定到

GL_TEXTURE_EXTERNAL_OES, 并通过OH_NativeImage进行更新。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeImage

**起始版本：** 9

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| image | 是指向**OH_NativeImage**实例的指针。 |
| textureId | 是OH_NativeImage要附加到的OpenGL ES纹理的id。 |

**返回：**

返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](#ohnativeerrorcode)。


### OH_NativeImage_Create()

```
OH_NativeImage* OH_NativeImage_Create (uint32_t textureId, uint32_t textureTarget )
```

**描述**

创建一个**OH_NativeImage**实例，该实例与OpenGL ES的纹理ID和纹理目标相关联。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeImage

**起始版本：** 9

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| textureId | OpenGL ES的纹理ID，OH_NativeImage实例会与之相关联。 |
| textureTarget | OpenGL ES的纹理目标。 |

**返回：**

返回一个指向**OH_NativeImage**实例的指针 returns **NULL** otherwise。


### OH_NativeImage_Destroy()

```
void OH_NativeImage_Destroy (OH_NativeImage ** image)
```

**描述**

销毁通过OH_NativeImage_Create创建的**OH_NativeImage**实例, 销毁后该

**OH_NativeImage**指针会被赋值为空。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeImage

**起始版本：** 9

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| image | 是指向**OH_NativeImage**实例的指针。 |


### OH_NativeImage_DetachContext()

```
int32_t OH_NativeImage_DetachContext (OH_NativeImage * image)
```

**描述**

将OH_NativeImage实例从当前OpenGL ES上下文分离。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeImage

**起始版本：** 9

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| image | 是指向**OH_NativeImage**实例的指针。 |

**返回：**

返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](#ohnativeerrorcode)。


### OH_NativeImage_GetSurfaceId()

```
int32_t OH_NativeImage_GetSurfaceId (OH_NativeImage * image, uint64_t * surfaceId )
```

**描述**

获取OH_NativeImage的surface编号。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeImage

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| image | 是指向**OH_NativeImage**实例的指针。 |
| surfaceId | 是指向surface编号的指针。 |

**返回：**

返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](#ohnativeerrorcode)。


### OH_NativeImage_GetTimestamp()

```
int64_t OH_NativeImage_GetTimestamp (OH_NativeImage * image)
```

**描述**

获取最近调用OH_NativeImage_UpdateSurfaceImage的纹理图像的相关时间戳。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeImage

**起始版本：** 9

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| image | 是指向**OH_NativeImage**实例的指针。 |

**返回：**

返回纹理图像的相关时间戳。


### OH_NativeImage_GetTransformMatrix()

```
int32_t OH_NativeImage_GetTransformMatrix (OH_NativeImage * image, float matrix[16] )
```

**描述**

获取最近调用OH_NativeImage_UpdateSurfaceImage的纹理图像的变化矩阵。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeImage

**起始版本：** 9

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| image | 是指向**OH_NativeImage**实例的指针。 |
| matrix | 用来存储要获取的4\*4的变化矩阵。 |

**返回：**

返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](#ohnativeerrorcode)。

### OH_NativeImage_GetTransformMatrixV2()

```
int32_t OH_NativeImage_GetTransformMatrixV2 (OH_NativeImage* image, float matrix[16] )
```
**描述**
根据生产端设置的旋转角度，获取最近调用OH_NativeImage_UpdateSurfaceImage的纹理图像的变化矩阵。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeImage

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| image | 是指向**OH_NativeImage**实例的指针。  | 
| matrix | 用来存储要获取的4\*4的变化矩阵。  | 

**返回：**

返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](#ohnativeerrorcode)。

### OH_NativeImage_SetOnFrameAvailableListener()

```
int32_t OH_NativeImage_SetOnFrameAvailableListener (OH_NativeImage * image, OH_OnFrameAvailableListener listener )
```

**描述**

设置帧可用回调。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeImage

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| image | 是指向**OH_NativeImage**实例的指针。 |
| listener | 表示回调监听者。 |

**返回：**

返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](#ohnativeerrorcode)。


### OH_NativeImage_UnsetOnFrameAvailableListener()

```
int32_t OH_NativeImage_UnsetOnFrameAvailableListener (OH_NativeImage * image)
```

**描述**

取消设置帧可用回调。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeImage

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| image | 是指向**OH_NativeImage**实例的指针。 |

**返回：**

返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](#ohnativeerrorcode)。


### OH_NativeImage_UpdateSurfaceImage()

```
int32_t OH_NativeImage_UpdateSurfaceImage (OH_NativeImage * image)
```

**描述**

通过OH_NativeImage获取最新帧更新相关联的OpenGL ES纹理。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeImage

**起始版本：** 9

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| image | 是指向**OH_NativeImage**实例的指针。 |

**返回：**

返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](#ohnativeerrorcode)。
