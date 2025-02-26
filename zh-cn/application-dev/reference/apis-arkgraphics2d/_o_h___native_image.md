# OH_NativeImage


## 概述

提供NativeImage功能，作为数据消费者，其中一种用法是将数据和OpenGL纹理对接，需在OpenGL环境下使用，另外一种用法是开发者自行获取buffer进行渲染处理。

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
| typedef struct [OH_NativeImage](#oh_nativeimage-1)  [OH_NativeImage](#oh_nativeimage-1) | 提供OH_NativeImage结构体声明。  | 
| typedef struct NativeWindow [OHNativeWindow](#ohnativewindow) | 提供对NativeWindow的访问功能。  | 
| typedef struct NativeWindowBuffer [OHNativeWindowBuffer](#ohnativewindowbuffer) | 提供NativeWindowBuffer结构体声明。 | 
| typedef void(\* [OH_OnFrameAvailable](#oh_onframeavailable)) (void \*context) | 有buffer可获取时触发的回调函数。  | 
| typedef struct [OH_OnFrameAvailableListener](_o_h___on_frame_available_listener.md)  [OH_OnFrameAvailableListener](#oh_onframeavailablelistener) | 一个OH_NativeImage的监听者，通过[OH_NativeImage_SetOnFrameAvailableListener](#oh_nativeimage_setonframeavailablelistener)接口注册 该监听结构体，当有buffer可获取时，将触发回调给用户。 |
| typedef enum [OHNativeErrorCode](#ohnativeerrorcode)  [OHNativeErrorCode](#ohnativeerrorcode) | 接口错误码说明（仅用于查询）。  | 

### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OHNativeErrorCode](#ohnativeerrorcode-1) {<br/>NATIVE_ERROR_OK = 0, NATIVE_ERROR_MEM_OPERATION_ERROR = 30001000, NATIVE_ERROR_INVALID_ARGUMENTS = 40001000, NATIVE_ERROR_NO_PERMISSION = 40301000, NATIVE_ERROR_NO_BUFFER = 40601000,<br/>NATIVE_ERROR_NO_CONSUMER = 41202000, NATIVE_ERROR_NOT_INIT = 41203000, NATIVE_ERROR_CONSUMER_CONNECTED = 41206000, NATIVE_ERROR_BUFFER_STATE_INVALID = 41207000,<br/>NATIVE_ERROR_BUFFER_IN_CACHE = 41208000, NATIVE_ERROR_BUFFER_QUEUE_FULL = 41209000, NATIVE_ERROR_BUFFER_NOT_IN_CACHE = 41210000, NATIVE_ERROR_CONSUMER_DISCONNECTED = 41211000,NATIVE_ERROR_CONSUMER_NO_LISTENER_REGISTERED = 41212000,NATIVE_ERROR_UNSUPPORTED = 50102000,<br/>NATIVE_ERROR_UNKNOWN = 50002000, NATIVE_ERROR_HDI_ERROR = 50007000,NATIVE_ERROR_BINDER_ERROR = 50401000,NATIVE_ERROR_EGL_STATE_UNKNOWN = 60001000, NATIVE_ERROR_EGL_API_FAILED = 60002000<br/>} | 接口错误码说明（仅用于查询）。  | 

### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_NativeImage](#oh_nativeimage-1) \* [OH_NativeImage_Create](#oh_nativeimage_create) (uint32_t textureId, uint32_t textureTarget) | 创建一个**OH_NativeImage**实例，该实例与OpenGL ES的纹理ID和纹理目标相关联。<br/>本接口需要与[OH_NativeImage_Destroy](#oh_nativeimage_destroy)接口配合使用，否则会存在内存泄露。<br/>本接口为非线程安全类型接口。 | 
| [OHNativeWindow](_native_window.md#ohnativewindow) \* [OH_NativeImage_AcquireNativeWindow](#oh_nativeimage_acquirenativewindow) ([OH_NativeImage](#oh_nativeimage-1) \*image) | 获取与OH_NativeImage相关联的OHNativeWindow指针。<br/>本接口为非线程安全类型接口。<br/>OH_NativeImage析构时会将对应的OHNativeWindow实例释放。若从本接口获取OHNativeWindow指针， 当OH_NativeImage实例释放时，请将获取到的OHNativeWindow指针置空，防止后续产生野指针。 | 
| int32_t [OH_NativeImage_AttachContext](#oh_nativeimage_attachcontext) ([OH_NativeImage](#oh_nativeimage-1) \*image, uint32_t textureId) | 将OH_NativeImage实例附加到当前OpenGL ES上下文, 且该OpenGL ES纹理会绑定到 GL_TEXTURE_EXTERNAL_OES, 并通过OH_NativeImage进行更新。<br/>本接口为非线程安全类型接口。 | 
| int32_t [OH_NativeImage_DetachContext](#oh_nativeimage_detachcontext) ([OH_NativeImage](#oh_nativeimage-1) \*image) | 将OH_NativeImage实例从当前OpenGL ES上下文分离。<br/>本接口为非线程安全类型接口。 | 
| int32_t [OH_NativeImage_UpdateSurfaceImage](#oh_nativeimage_updatesurfaceimage) ([OH_NativeImage](#oh_nativeimage-1) \*image) | 通过OH_NativeImage获取最新帧更新相关联的OpenGL ES纹理。<br/>本接口需要在Opengl ES环境上下文的线程中调用。<br/>本接口需要在接收到[OH_OnFrameAvailableListener](_o_h___on_frame_available_listener.md)回调后调用。<br/>本接口为非线程安全类型接口。 | 
| int64_t [OH_NativeImage_GetTimestamp](#oh_nativeimage_gettimestamp) ([OH_NativeImage](#oh_nativeimage-1) \*image) | 获取最近调用OH_NativeImage_UpdateSurfaceImage的纹理图像的相关时间戳。<br/>本接口为非线程安全类型接口。 | 
| int32_t [OH_NativeImage_GetTransformMatrix](#oh_nativeimage_gettransformmatrix) ([OH_NativeImage](#oh_nativeimage-1) \*image, float matrix[16]) | 获取最近调用OH_NativeImage_UpdateSurfaceImage的纹理图像的变化矩阵。 | 
| int32_t [OH_NativeImage_GetSurfaceId](#oh_nativeimage_getsurfaceid) ([OH_NativeImage](#oh_nativeimage-1) \*image, uint64_t \*surfaceId) | 获取OH_NativeImage的surface编号。<br/>本接口为非线程安全类型接口。 | 
| int32_t [OH_NativeImage_SetOnFrameAvailableListener](#oh_nativeimage_setonframeavailablelistener) ([OH_NativeImage](#oh_nativeimage-1) \*image, [OH_OnFrameAvailableListener](_o_h___on_frame_available_listener.md) listener) | 设置帧可用回调。<br/>不允许在回调函数中调用本模块的其他接口。<br/>本接口为非线程安全类型接口。 | 
| int32_t [OH_NativeImage_UnsetOnFrameAvailableListener](#oh_nativeimage_unsetonframeavailablelistener) ([OH_NativeImage](#oh_nativeimage-1) \*image) | 取消设置帧可用回调。<br/>本接口为非线程安全类型接口。 | 
| void [OH_NativeImage_Destroy](#oh_nativeimage_destroy) ([OH_NativeImage](#oh_nativeimage-1) \*\*image) | 销毁通过OH_NativeImage_Create创建的**OH_NativeImage**实例, 销毁后该<br/>**OH_NativeImage**指针会被赋值为空。<br/>本接口为非线程安全类型接口。 | 
| int32_t [OH_NativeImage_GetTransformMatrixV2](#oh_nativeimage_gettransformmatrixv2) ([OH_NativeImage](#oh_nativeimage-1) \*image, float matrix[16]) | 根据生产端设置的旋转角度，获取最近调用OH_NativeImage_UpdateSurfaceImage的纹理图像的变化矩阵。<br/>matrix在[OH_NativeImage_UpdateSurfaceImage](#oh_nativeimage_updatesurfaceimage)接口调用后，才会更新。<br/>本接口为非线程安全类型接口。 | 
| int32_t [OH_NativeImage_GetBufferMatrix](#oh_nativeimage_getbuffermatrix) ([OH_NativeImage](#oh_nativeimage-1) \*image, float matrix[16]) | 获取根据生产端设置的旋转角度和buffer实际有效内容区域计算出的变换矩阵。 | 
| int32_t [OH_NativeImage_AcquireNativeWindowBuffer](#oh_nativeimage_acquirenativewindowbuffer) ([OH_NativeImage](#oh_nativeimage-1) \*image, [OHNativeWindowBuffer](_native_window.md#ohnativewindowbuffer) \*\*nativeWindowBuffer, int \*fenceFd) | 通过消费端的**OH_NativeImage**获取一个**OHNativeWindowBuffer**。<br/>本接口不能与[OH_NativeImage_UpdateSurfaceImage](#oh_nativeimage_updatesurfaceimage)接口同时使用。<br/>本接口将会创建一个**OHNativeWindowBuffer**。<br/>当使用**OHNativeWindowBuffer**时，用户需要通过[OH_NativeWindow_NativeObjectReference](_native_window.md#oh_nativewindow_nativeobjectreference)接口将其引用计数加一。<br/>当**OHNativeWindowBuffer**使用完，用户需要通过[OH_NativeWindow_NativeObjectUnreference](_native_window.md#oh_nativewindow_nativeobjectunreference)接口将其引用计数减一。<br/>本接口需要和[OH_NativeImage_ReleaseNativeWindowBuffer](#oh_nativeimage_releasenativewindowbuffer)接口配合使用，否则会存在内存泄露。<br/>当fenceFd使用完，用户需要将其close。<br/>本接口为非线程安全类型接口。 | 
| int32_t [OH_NativeImage_ReleaseNativeWindowBuffer](#oh_nativeimage_releasenativewindowbuffer) ([OH_NativeImage](#oh_nativeimage-1) \*image, [OHNativeWindowBuffer](_native_window.md#ohnativewindowbuffer) \*nativeWindowBuffer, int fenceFd) | 通过**OH_NativeImage**实例将**OHNativeWindowBuffer**归还到buffer队列中。<br/>系统会将fenFd关闭，无需用户close。<br/>本接口为非线程安全类型接口。 | 
| [OH_NativeImage](#oh_nativeimage-1) \* [OH_ConsumerSurface_Create](#oh_consumersurface_create) () | 创建一个**OH_NativeImage**实例，作为surface的消费端。<br/>本接口仅用于surface消费端的内存轮转，创建的OH_NativeImage内部不会主动进行内存渲染处理。<br/>本接口不能与[OH_NativeImage_UpdateSurfaceImage](#oh_nativeimage_updatesurfaceimage)接口同时使用。<br/>本接口与 OH_NativeImage_AcquireNativeWindowBuffer和OH_NativeImage_ReleaseNativeWindowBuffer配合使用。<br/>本接口需要和[OH_NativeImage_Destroy](#oh_nativeimage_destroy)接口配合使用，否则会存在内存泄露。<br/>本接口为非线程安全类型接口。 | 
| int32_t [OH_ConsumerSurface_SetDefaultUsage](#oh_consumersurface_setdefaultusage) ([OH_NativeImage](#oh_nativeimage-1) \*image, uint64_t usage) | 设置默认读写方式。 本接口为非线程安全类型接口。 | 
| int32_t [OH_ConsumerSurface_SetDefaultSize](#oh_consumersurface_setdefaultsize) ([OH_NativeImage](#oh_nativeimage-1) \*image, int32_t width, int32_t height) | 设置几何图形默认尺寸。 本接口为非线程安全类型接口。 | 

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

### OHNativeWindowBuffer

```
typedef struct NativeWindowBuffer OHNativeWindowBuffer
```

**描述**

提供NativeWindowBuffer结构体声明。

**起始版本：** 12


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
| NATIVE_ERROR_OK  | 成功。   | 
| NATIVE_ERROR_MEM_OPERATION_ERROR<sup>15+</sup> | 内存操作错误。 | 
| NATIVE_ERROR_INVALID_ARGUMENTS  | 入参无效。   | 
| NATIVE_ERROR_NO_PERMISSION  | 无权限操作。   | 
| NATIVE_ERROR_NO_BUFFER  | 无空闲可用的buffer。   | 
| NATIVE_ERROR_NO_CONSUMER  | 消费端不存在。   | 
| NATIVE_ERROR_NOT_INIT  | 未初始化。   | 
| NATIVE_ERROR_CONSUMER_CONNECTED  | 消费端已经被连接。   | 
| NATIVE_ERROR_BUFFER_STATE_INVALID  | buffer状态不符合预期。   | 
| NATIVE_ERROR_BUFFER_IN_CACHE  | buffer已在缓存队列中。   | 
| NATIVE_ERROR_BUFFER_QUEUE_FULL  | 队列已满。   | 
| NATIVE_ERROR_BUFFER_NOT_IN_CACHE  | buffer不在缓存队列中。   | 
| NATIVE_ERROR_CONSUMER_DISCONNECTED | 消费端已经被断开连接。 |
| NATIVE_ERROR_CONSUMER_NO_LISTENER_REGISTERED | 消费端未注册listener回调函数。 |
| NATIVE_ERROR_UNSUPPORTED  | 当前设备或平台不支持。   | 
| NATIVE_ERROR_UNKNOWN  | 未知错误，请查看日志。   | 
| NATIVE_ERROR_HDI_ERROR  | HDI接口调用失败。   | 
| NATIVE_ERROR_BINDER_ERROR  | 跨进程通信失败。   | 
| NATIVE_ERROR_EGL_STATE_UNKNOWN  | egl环境状态异常。   | 
| NATIVE_ERROR_EGL_API_FAILED  | egl接口调用失败。   | 


## 函数说明

### OH_NativeImage_GetBufferMatrix()

```
int32_t OH_NativeImage_GetBufferMatrix (OH_NativeImage* image, float matrix[16] )
```

**描述**

获取根据生产端设置的旋转角度和buffer实际有效内容区域计算出的变换矩阵。

本接口返回一个变换矩阵，该矩阵是[OH_NativeImage](#oh_nativeimage-1)在消费buffer，即调用[OH_NativeImage_UpdateSurfaceImage](#oh_nativeimage_updatesurfaceimage) 或者[OH_NativeImage_AcquireNativeWindowBuffer](#oh_nativeimage_acquirenativewindowbuffer)时，根据buffer的旋转角度和实际有效内容区域计算所得。

本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeImage

**起始版本：** 15

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| image | 指向[OH_NativeImage](#oh_nativeimage-1)实例的指针。 | 
| matrix | 用于存储获取的4\*4变换矩阵。 | 

**返回：**

返回接口执行结果。NATIVE_ERROR_OK，表示接口执行成功。

返回NATIVE_ERROR_INVALID_ARGUMENTS，对应错误码为40001000，表示image参数为空。

返回NATIVE_ERROR_MEM_OPERATION_ERROR，对应错误码为30001000，表示内存操作错误，获取变换矩阵失败。

### OH_ConsumerSurface_SetDefaultUsage()

```
int32_t OH_ConsumerSurface_SetDefaultUsage (OH_NativeImage* image, uint64_t usage )
```

**描述**

设置默认读写方式。 本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeImage

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| image | 指向**OH_NativeImage**实例的指针。 | 
| usage | 表示读写方式。枚举值参考**OH_NativeBuffer_Usage**。 | 

**返回：**

执行成功时返回NATIVE_ERROR_OK。

image是空指针时返回NATIVE_ERROR_INVALID_ARGUMENTS。


### OH_ConsumerSurface_SetDefaultSize()

```
int32_t OH_ConsumerSurface_SetDefaultSize (OH_NativeImage* image, int32_t width, int32_t height )
```

**描述**

设置几何图形默认尺寸。 本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeImage

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| image | 指向**OH_NativeImage**实例的指针。 | 
| width | 表示几何图形宽度，取值范围大于0，单位为像素。 | 
| height | 表示几何图形高度，取值范围大于0，单位为像素。 | 

**返回：**

执行成功时返回NATIVE_ERROR_OK。

image是空指针时，或width、height小于等于0时返回NATIVE_ERROR_INVALID_ARGUMENTS。



### OH_ConsumerSurface_Create()

```
OH_NativeImage* OH_ConsumerSurface_Create ()
```

**描述**

创建一个**OH_NativeImage**实例，作为surface的消费端。

本接口仅用于surface消费端的内存轮转，创建的OH_NativeImage内部不会主动进行内存渲染处理。

本接口不能与[OH_NativeImage_UpdateSurfaceImage](#oh_nativeimage_updatesurfaceimage)接口同时使用。

本接口与 OH_NativeImage_AcquireNativeWindowBuffer和OH_NativeImage_ReleaseNativeWindowBuffer配合使用。

本接口需要和[OH_NativeImage_Destroy](#oh_nativeimage_destroy)接口配合使用，否则会存在内存泄露。

本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeImage

**起始版本：** 12

**返回：**

成功则返回一个指向**OH_NativeImage**实例的指针，否则返回**NULL**。


### OH_NativeImage_AcquireNativeWindowBuffer()

```
int32_t OH_NativeImage_AcquireNativeWindowBuffer (OH_NativeImage* image, OHNativeWindowBuffer** nativeWindowBuffer, int* fenceFd )
```

**描述**

通过消费端的**OH_NativeImage**获取一个**OHNativeWindowBuffer**。

本接口不能与[OH_NativeImage_UpdateSurfaceImage](#oh_nativeimage_updatesurfaceimage)接口同时使用。

本接口将会创建一个**OHNativeWindowBuffer**。

当使用**OHNativeWindowBuffer**时，用户需要通过**OH_NativeWindow_NativeObjectReference**接口将其引用计数加一。

当**OHNativeWindowBuffer**使用完，用户需要通过**OH_NativeWindow_NativeObjectUnreference**接口将其引用计数减一。

本接口需要和[OH_NativeImage_ReleaseNativeWindowBuffer](#oh_nativeimage_releasenativewindowbuffer)接口配合使用，否则会存在内存泄露。

当fenceFd使用完，用户需要将其close。
本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeImage

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| image | 指向**OH_NativeImage**实例的指针。 | 
| nativeWindowBuffer | 指向**OHNativeWindowBuffer**指针的指针。 | 
| fenceFd | 指向文件描述符句柄的指针。 | 

**返回：**

执行成功时返回NATIVE_ERROR_OK。

image, nativeWindowBuffer, fenceFd是空指针时返回NATIVE_ERROR_INVALID_ARGUMENTS。

没有buffer可以消费时返回NATIVE_ERROR_NO_BUFFER。


### OH_NativeImage_ReleaseNativeWindowBuffer()

```
int32_t OH_NativeImage_ReleaseNativeWindowBuffer (OH_NativeImage* image, OHNativeWindowBuffer* nativeWindowBuffer, int fenceFd )
```

**描述**

通过**OH_NativeImage**实例将**OHNativeWindowBuffer**归还到buffer队列中。

系统会将fenFd关闭，无需用户close。
本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeImage

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| image | 指向**OH_NativeImage**实例的指针。 | 
| nativeWindowBuffer | 指向**OHNativeWindowBuffer**实例的指针。 | 
| fenceFd | 指向文件描述符句柄, 用于并发同步控制。 | 

**返回：**

执行成功时返回NATIVE_ERROR_OK。

image或nativeWindowBuffer是空指针时返回NATIVE_ERROR_INVALID_ARGUMENTS。

nativeWindowBuffer为状态非法时返回NATIVE_ERROR_BUFFER_STATE_INVALID。

nativeWindowBuffer不在缓存中返回NATIVE_ERROR_BUFFER_NOT_IN_CACHE。



### OH_NativeImage_AcquireNativeWindow()

```
OHNativeWindow* OH_NativeImage_AcquireNativeWindow (OH_NativeImage * image)
```

**描述**

获取与OH_NativeImage相关联的OHNativeWindow指针。

本接口为非线程安全类型接口。

OH_NativeImage析构时会将对应的OHNativeWindow实例释放。若从本接口获取OHNativeWindow指针，当OH_NativeImage实例释放时，请将获取到的OHNativeWindow指针置空，防止后续产生野指针。


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
本接口为非线程安全类型接口。

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
本接口需要与OH_NativeImage_Destroy接口配合使用，否则会存在内存泄露。
本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeImage

**起始版本：** 9

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| textureId | OpenGL ES的纹理ID，OH_NativeImage实例会与之相关联。 |
| textureTarget | OpenGL ES的纹理目标。 |

**返回：**

创建成功则返回一个指向**OH_NativeImage**实例的指针实例的指针，否则返回**NULL**。


### OH_NativeImage_Destroy()

```
void OH_NativeImage_Destroy (OH_NativeImage ** image)
```

**描述**

销毁通过OH_NativeImage_Create创建的**OH_NativeImage**实例, 销毁后该

**OH_NativeImage**指针会被赋值为空。
本接口为非线程安全类型接口。

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
本接口为非线程安全类型接口。

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
本接口为非线程安全类型接口。

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
本接口为非线程安全类型接口。

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

**废弃版本：** 12

**替代接口：** [OH_NativeImage_GetTransformMatrixV2](#oh_nativeimage_gettransformmatrixv2)

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
matrix在OH_NativeImage_UpdateSurfaceImage接口调用后，才会更新。
本接口为非线程安全类型接口。

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
不允许在回调函数中调用本模块的其他接口。
本接口为非线程安全类型接口。

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
本接口为非线程安全类型接口。

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
本接口需要在Opengl ES环境上下文的线程中调用。
本接口需要在接收到OH_OnFrameAvailableListener回调后调用。
本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeImage

**起始版本：** 9

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| image | 是指向**OH_NativeImage**实例的指针。 |

**返回：**

返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](#ohnativeerrorcode)。
