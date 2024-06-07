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
| typedef void(\* [OH_OnFrameAvailable](_o_h___native_image.md#oh_onframeavailable)) (void \*context) | 有buffer可获取时触发的回调函数。  | 
| typedef struct [OH_OnFrameAvailableListener](_o_h___on_frame_available_listener.md)  [OH_OnFrameAvailableListener](_o_h___native_image.md#oh_onframeavailablelistener) | 一个OH_NativeImage的监听者，通过{\@Link OH_NativeImage_SetOnFrameAvailableListener}接口注册 该监听结构体，当有buffer可获取时，将触发回调给用户。  | 
| typedef enum [OHNativeErrorCode](_o_h___native_image.md#ohnativeerrorcode)  [OHNativeErrorCode](_o_h___native_image.md#ohnativeerrorcode) | 接口错误码说明（仅用于查询）。  | 

### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OHNativeErrorCode](_o_h___native_image.md#ohnativeerrorcode) {<br/>NATIVE_ERROR_OK = 0, NATIVE_ERROR_INVALID_ARGUMENTS = 40001000, NATIVE_ERROR_NO_PERMISSION = 40301000, NATIVE_ERROR_NO_BUFFER = 40601000,<br/>NATIVE_ERROR_NO_CONSUMER = 41202000, NATIVE_ERROR_NOT_INIT = 41203000, NATIVE_ERROR_CONSUMER_CONNECTED = 41206000, NATIVE_ERROR_BUFFER_STATE_INVALID = 41207000,<br/>NATIVE_ERROR_BUFFER_IN_CACHE = 41208000, NATIVE_ERROR_BUFFER_QUEUE_FULL = 41209000, NATIVE_ERROR_BUFFER_NOT_IN_CACHE = 41210000, NATIVE_ERROR_UNSUPPORT = 50102000,<br/>NATIVE_ERROR_UNKNOWN = 50002000, NATIVE_ERROR_EGL_STATE_UNKNOWN = 60001000, NATIVE_ERROR_EGL_API_FAILED = 60002000 | 接口错误码说明（仅用于查询）。  | 


### 函数

| 名称 | 描述 |
| -------- | -------- |
| [OH_NativeImage_Create](_o_h___native_image.md#oh_nativeimage_create) (uint32_t textureId, uint32_t textureTarget) | 创建一个**OH_NativeImage**实例，该实例与OpenGL ES的纹理ID和纹理目标相关联 |
| [OH_NativeImage_AcquireNativeWindow](_o_h___native_image.md#oh_nativeimage_acquirenativewindow) ([OH_NativeImage](_o_h___native_image.md#oh_nativeimage) \*image) | 获取与OH_NativeImage相关联的OHNativeWindow指针。该OHNativeWindow后续不再需要时需要调用<br/>OH_NativeWindow_DestroyNativeWindow释放 |
| [OH_NativeImage_AttachContext](_o_h___native_image.md#oh_nativeimage_attachcontext) ([OH_NativeImage](_o_h___native_image.md#oh_nativeimage) \*image, uint32_t textureId) | 将OH_NativeImage实例附加到当前OpenGL ES上下文, 且该OpenGL ES纹理会绑定到<br/>GL_TEXTURE_EXTERNAL_OES, 并通过OH_NativeImage进行更新 |
| [OH_NativeImage_DetachContext](_o_h___native_image.md#oh_nativeimage_detachcontext) ([OH_NativeImage](_o_h___native_image.md#oh_nativeimage) \*image) | 将OH_NativeImage实例从当前OpenGL ES上下文分离 |
| [OH_NativeImage_UpdateSurfaceImage](_o_h___native_image.md#oh_nativeimage_updatesurfaceimage) ([OH_NativeImage](_o_h___native_image.md#oh_nativeimage) \*image) | 通过OH_NativeImage获取最新帧更新相关联的OpenGL ES纹理 |
| [OH_NativeImage_GetTimestamp](_o_h___native_image.md#oh_nativeimage_gettimestamp) ([OH_NativeImage](_o_h___native_image.md#oh_nativeimage) \*image) | 获取最近调用OH_NativeImage_UpdateSurfaceImage的纹理图像的相关时间戳 |
| [OH_NativeImage_GetTransformMatrix](_o_h___native_image.md#oh_nativeimage_gettransformmatrix) ([OH_NativeImage](_o_h___native_image.md#oh_nativeimage) \*image, float matrix[16]) | 获取最近调用OH_NativeImage_UpdateSurfaceImage的纹理图像的变化矩阵 |
| [OH_NativeImage_GetSurfaceId](_o_h___native_image.md#oh_nativeimage_getsurfaceid) ([OH_NativeImage](_o_h___native_image.md#oh_nativeimage) \*image, uint64_t \*surfaceId) | 获取OH_NativeImage的surface编号 |
| [OH_NativeImage_SetOnFrameAvailableListener](_o_h___native_image.md#oh_nativeimage_setonframeavailablelistener) ([OH_NativeImage](_o_h___native_image.md#oh_nativeimage) \*image, [OH_OnFrameAvailableListener](_o_h___on_frame_available_listener.md) listener) | 设置帧可用回调 |
| [OH_NativeImage_UnsetOnFrameAvailableListener](_o_h___native_image.md#oh_nativeimage_unsetonframeavailablelistener) ([OH_NativeImage](_o_h___native_image.md#oh_nativeimage) \*image) | 取消设置帧可用回调 |
| [OH_NativeImage_Destroy](_o_h___native_image.md#oh_nativeimage_destroy) ([OH_NativeImage](_o_h___native_image.md#oh_nativeimage) \*\*image) | 销毁通过OH_NativeImage_Create创建的**OH_NativeImage**实例, 销毁后该**OH_NativeImage**指针会被赋值为空 |
| int32_t [OH_NativeImage_GetTransformMatrixV2](_o_h___native_image.md#oh_nativeimage_gettransformmatrixv2) ([OH_NativeImage](_o_h___native_image.md#oh_nativeimage) \*image, float matrix[16]) | 根据生产端设置的旋转角度，获取最近调用OH_NativeImage_UpdateSurfaceImage的纹理图像的变化矩阵。  | 