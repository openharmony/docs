# native_image.h


## 概述

定义获取和使用NativeImage的相关函数

**库：** libnative_image.so

**起始版本：** 9

**相关模块：**[OH_NativeImage](_o_h___native_image.md)


## 汇总


### 结构体

| 名称 | 描述 |
| -------- | -------- |
| [OH_OnFrameAvailableListener](_o_h___on_frame_available_listener.md) | 一个OH_NativeImage的监听者，通过OH_NativeImage_SetOnFrameAvailableListener接口注册， 该监听结构体当有帧可用时，将触发回调 |


### 类型定义

| 名称 | 描述 |
| -------- | -------- |
| typedef struct [OH_NativeImage](_o_h___native_image.md#oh_nativeimage)  [OH_NativeImage](_o_h___native_image.md#oh_nativeimage) | 提供OH_NativeImage结构体声明。  | 
| typedef struct NativeWindow [OHNativeWindow](_o_h___native_image.md#ohnativewindow) | 提供对NativeWindow的访问功能。  | 
| typedef struct NativeWindowBuffer [OHNativeWindowBuffer](_o_h___native_image.md#ohnativewindowbuffer) | 提供NativeWindowBuffer结构体声明。 |
| typedef void(\* [OH_OnFrameAvailable](_o_h___native_image.md#oh_onframeavailable)) (void \*context) | 有buffer可获取时触发的回调函数。  | 
| typedef struct [OH_OnFrameAvailableListener](_o_h___on_frame_available_listener.md)  [OH_OnFrameAvailableListener](_o_h___native_image.md#oh_onframeavailablelistener) | 一个OH_NativeImage的监听者，通过{\@Link OH_NativeImage_SetOnFrameAvailableListener}接口注册 该监听结构体，当有buffer可获取时，将触发回调给用户。  | 
| typedef enum [OHNativeErrorCode](_o_h___native_image.md#ohnativeerrorcode)  [OHNativeErrorCode](_o_h___native_image.md#ohnativeerrorcode) | 接口错误码说明（仅用于查询）。  | 

### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OHNativeErrorCode](_o_h___native_image.md#ohnativeerrorcode-1) {<br/>NATIVE_ERROR_OK = 0, NATIVE_ERROR_MEM_OPERATION_ERROR = 30001000, NATIVE_ERROR_INVALID_ARGUMENTS = 40001000, NATIVE_ERROR_NO_PERMISSION = 40301000, NATIVE_ERROR_NO_BUFFER = 40601000,<br/>NATIVE_ERROR_NO_CONSUMER = 41202000, NATIVE_ERROR_NOT_INIT = 41203000, NATIVE_ERROR_CONSUMER_CONNECTED = 41206000, NATIVE_ERROR_BUFFER_STATE_INVALID = 41207000,<br/>NATIVE_ERROR_BUFFER_IN_CACHE = 41208000, NATIVE_ERROR_BUFFER_QUEUE_FULL = 41209000, NATIVE_ERROR_BUFFER_NOT_IN_CACHE = 41210000, NATIVE_ERROR_CONSUMER_DISCONNECTED = 41211000,NATIVE_ERROR_CONSUMER_NO_LISTENER_REGISTERED = 41212000,NATIVE_ERROR_UNSUPPORTED = 50102000,<br/>NATIVE_ERROR_UNKNOWN = 50002000,NATIVE_ERROR_HDI_ERROR = 50007000,NATIVE_ERROR_BINDER_ERROR = 50401000, NATIVE_ERROR_EGL_STATE_UNKNOWN = 60001000, NATIVE_ERROR_EGL_API_FAILED = 60002000<br/>} | 接口错误码说明（仅用于查询）。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_NativeImage](_o_h___native_image.md#oh_nativeimage) \* [OH_NativeImage_Create](_o_h___native_image.md#oh_nativeimage_create) (uint32_t textureId, uint32_t textureTarget) | 创建一个**OH_NativeImage**实例，该实例与OpenGL ES的纹理ID和纹理目标相关联。<br/>本接口需要与[OH_NativeImage_Destroy](_o_h___native_image.md#oh_nativeimage_destroy)接口配合使用，否则会存在内存泄露。<br/>本接口为非线程安全类型接口。 | 
| [OHNativeWindow](_native_window.md#ohnativewindow) \* [OH_NativeImage_AcquireNativeWindow](_o_h___native_image.md#oh_nativeimage_acquirenativewindow) ([OH_NativeImage](_o_h___native_image.md#oh_nativeimage) \*image) | 获取与OH_NativeImage相关联的OHNativeWindow指针。<br/>本接口为非线程安全类型接口。<br/>OH_NativeImage析构时会将对应的OHNativeWindow实例释放。若从本接口获取OHNativeWindow指针， 当OH_NativeImage实例释放时，请将获取到的OHNativeWindow指针置空，防止后续产生野指针。 | 
| int32_t [OH_NativeImage_AttachContext](_o_h___native_image.md#oh_nativeimage_attachcontext) ([OH_NativeImage](_o_h___native_image.md#oh_nativeimage) \*image, uint32_t textureId) | 将OH_NativeImage实例附加到当前OpenGL ES上下文, 且该OpenGL ES纹理会绑定到 GL_TEXTURE_EXTERNAL_OES, 并通过OH_NativeImage进行更新。<br/>本接口为非线程安全类型接口。 | 
| int32_t [OH_NativeImage_DetachContext](_o_h___native_image.md#oh_nativeimage_detachcontext) ([OH_NativeImage](_o_h___native_image.md#oh_nativeimage) \*image) | 将OH_NativeImage实例从当前OpenGL ES上下文分离。<br/>本接口为非线程安全类型接口。 | 
| int32_t [OH_NativeImage_UpdateSurfaceImage](_o_h___native_image.md#oh_nativeimage_updatesurfaceimage) ([OH_NativeImage](_o_h___native_image.md#oh_nativeimage) \*image) | 通过OH_NativeImage获取最新帧更新相关联的OpenGL ES纹理。<br/>本接口需要在Opengl ES环境上下文的线程中调用。<br/>本接口需要在接收到[OH_OnFrameAvailableListener](_o_h___on_frame_available_listener.md)回调后调用。<br/>本接口为非线程安全类型接口。 | 
| int64_t [OH_NativeImage_GetTimestamp](_o_h___native_image.md#oh_nativeimage_gettimestamp) ([OH_NativeImage](_o_h___native_image.md#oh_nativeimage) \*image) | 获取最近调用OH_NativeImage_UpdateSurfaceImage的纹理图像的相关时间戳。<br/>本接口为非线程安全类型接口。 | 
| int32_t [OH_NativeImage_GetTransformMatrix](_o_h___native_image.md#oh_nativeimage_gettransformmatrix) ([OH_NativeImage](_o_h___native_image.md#oh_nativeimage) \*image, float matrix[16]) | 获取最近调用OH_NativeImage_UpdateSurfaceImage的纹理图像的变化矩阵。 | 
| int32_t [OH_NativeImage_GetSurfaceId](_o_h___native_image.md#oh_nativeimage_getsurfaceid) ([OH_NativeImage](_o_h___native_image.md#oh_nativeimage) \*image, uint64_t \*surfaceId) | 获取OH_NativeImage的surface编号。<br/>本接口为非线程安全类型接口。 | 
| int32_t [OH_NativeImage_SetOnFrameAvailableListener](_o_h___native_image.md#oh_nativeimage_setonframeavailablelistener) ([OH_NativeImage](_o_h___native_image.md#oh_nativeimage) \*image, [OH_OnFrameAvailableListener](_o_h___on_frame_available_listener.md) listener) | 设置帧可用回调。<br/>不允许在回调函数中调用本模块的其他接口。<br/>本接口为非线程安全类型接口。 | 
| int32_t [OH_NativeImage_UnsetOnFrameAvailableListener](_o_h___native_image.md#oh_nativeimage_unsetonframeavailablelistener) ([OH_NativeImage](_o_h___native_image.md#oh_nativeimage) \*image) | 取消设置帧可用回调。<br/>本接口为非线程安全类型接口。 | 
| void [OH_NativeImage_Destroy](_o_h___native_image.md#oh_nativeimage_destroy) ([OH_NativeImage](_o_h___native_image.md#oh_nativeimage) \*\*image) | 销毁通过OH_NativeImage_Create创建的**OH_NativeImage**实例, 销毁后该<br/>**OH_NativeImage**指针会被赋值为空。<br/>本接口为非线程安全类型接口。 | 
| int32_t [OH_NativeImage_GetTransformMatrixV2](_o_h___native_image.md#oh_nativeimage_gettransformmatrixv2) ([OH_NativeImage](_o_h___native_image.md#oh_nativeimage) \*image, float matrix[16]) | 根据生产端设置的旋转角度，获取最近调用OH_NativeImage_UpdateSurfaceImage的纹理图像的变化矩阵。<br/>matrix在[OH_NativeImage_UpdateSurfaceImage](_o_h___native_image.md#oh_nativeimage_updatesurfaceimage)接口调用后，才会更新。<br/>本接口为非线程安全类型接口。 | 
| int32_t [OH_NativeImage_GetBufferMatrix](_o_h___native_image.md#oh_nativeimage_getbuffermatrix) ([OH_NativeImage](_o_h___native_image.md#oh_nativeimage) \*image, float matrix[16]) | 获取根据生产端设置的旋转角度和buffer实际有效内容区域计算出的变换矩阵。 | 
| int32_t [OH_NativeImage_AcquireNativeWindowBuffer](_o_h___native_image.md#oh_nativeimage_acquirenativewindowbuffer) ([OH_NativeImage](_o_h___native_image.md#oh_nativeimage) \*image, [OHNativeWindowBuffer](_native_window.md#ohnativewindowbuffer) \*\*nativeWindowBuffer, int \*fenceFd) | 通过消费端的**OH_NativeImage**获取一个**OHNativeWindowBuffer**。<br/>本接口不能与[OH_NativeImage_UpdateSurfaceImage](_o_h___native_image.md#oh_nativeimage_updatesurfaceimage)接口同时使用。<br/>本接口将会创建一个**OHNativeWindowBuffer**。<br/>当使用**OHNativeWindowBuffer**时，用户需要通过[OH_NativeWindow_NativeObjectReference](_native_window.md#oh_nativewindow_nativeobjectreference)接口将其引用计数加一。<br/>当**OHNativeWindowBuffer**使用完，用户需要通过[OH_NativeWindow_NativeObjectUnreference](_native_window.md#oh_nativewindow_nativeobjectunreference)接口将其引用计数减一。<br/>本接口需要和[OH_NativeImage_ReleaseNativeWindowBuffer](_o_h___native_image.md#oh_nativeimage_releasenativewindowbuffer)接口配合使用，否则会存在内存泄露。<br/>当fenceFd使用完，用户需要将其close。<br/>本接口为非线程安全类型接口。 | 
| int32_t [OH_NativeImage_ReleaseNativeWindowBuffer](_o_h___native_image.md#oh_nativeimage_releasenativewindowbuffer) ([OH_NativeImage](_o_h___native_image.md#oh_nativeimage) \*image, [OHNativeWindowBuffer](_native_window.md#ohnativewindowbuffer) \*nativeWindowBuffer, int fenceFd) | 通过**OH_NativeImage**实例将**OHNativeWindowBuffer**归还到buffer队列中。<br/>系统会将fenFd关闭，无需用户close。<br/>本接口为非线程安全类型接口。 | 
| [OH_NativeImage](_o_h___native_image.md#oh_nativeimage) \* [OH_ConsumerSurface_Create](_o_h___native_image.md#oh_consumersurface_create) () | 创建一个**OH_NativeImage**实例，作为surface的消费端。<br/>本接口仅用于surface消费端的内存轮转，创建的OH_NativeImage内部不会主动进行内存渲染处理。<br/>本接口不能与[OH_NativeImage_UpdateSurfaceImage](_o_h___native_image.md#oh_nativeimage_updatesurfaceimage)接口同时使用。<br/>本接口与OH_NativeImage_AcquireNativeWindowBuffer和OH_NativeImage_ReleaseNativeWindowBuffer配合使用。<br/>本接口需要和[OH_NativeImage_Destroy](_o_h___native_image.md#oh_nativeimage_destroy)接口配合使用，否则会存在内存泄露。<br/>本接口为非线程安全类型接口。 | 
| int32_t [OH_ConsumerSurface_SetDefaultUsage](_o_h___native_image.md#oh_consumersurface_setdefaultusage) ([OH_NativeImage](_o_h___native_image.md#oh_nativeimage) \*image, uint64_t usage) | 设置默认读写方式。 本接口为非线程安全类型接口。 | 
| int32_t [OH_ConsumerSurface_SetDefaultSize](_o_h___native_image.md#oh_consumersurface_setdefaultsize) ([OH_NativeImage](_o_h___native_image.md#oh_nativeimage) \*image, int32_t width, int32_t height) | 设置几何图形默认尺寸。 本接口为非线程安全类型接口。 | 
