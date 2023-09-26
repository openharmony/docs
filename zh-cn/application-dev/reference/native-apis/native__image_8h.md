# native_image.h


## 概述

定义获取和使用NativeImage的相关函数

**起始版本:**

9

**相关模块:**

[OH_NativeImage](_o_h___native_image.md)


## 汇总


### 类型定义

| 类型名称 | 描述 |
| -------- | -------- |
| [OH_NativeImage](_o_h___native_image.md#oh_nativeimage) | 提供OH_NativeImage结构体声明 |
| [OHNativeWindow](_o_h___native_image.md#ohnativewindow) | 提供对NativeWindow的访问功能 |


### 函数

| 函数名称 | 描述 |
| -------- | -------- |
| [OH_NativeImage_Create](_o_h___native_image.md#oh_nativeimage_create) (uint32_t textureId, uint32_t textureTarget) | 创建一个**OH_NativeImage**实例，该实例与OpenGL ES的纹理ID和纹理目标相关联 |
| [OH_NativeImage_AcquireNativeWindow](_o_h___native_image.md#oh_nativeimage_acquirenativewindow) (OH_NativeImage \*image) | 获取与OH_NativeImage相关联的OHNativeWindow指针. 该OHNativeWindow后续不再需要时需要调用<br/>OH_NativeWindow_DestroyNativeWindow释放 |
| [OH_NativeImage_AttachContext](_o_h___native_image.md#oh_nativeimage_attachcontext) (OH_NativeImage \*image, uint32_t textureId) | 将OH_NativeImage实例附加到当前OpenGL ES上下文, 且该OpenGL ES纹理会绑定到<br/>GL_TEXTURE_EXTERNAL_OES, 并通过OH_NativeImage进行更新 |
| [OH_NativeImage_DetachContext](_o_h___native_image.md#oh_nativeimage_detachcontext) (OH_NativeImage \*image) | 将OH_NativeImage实例从当前OpenGL ES上下文分离 |
| [OH_NativeImage_UpdateSurfaceImage](_o_h___native_image.md#oh_nativeimage_updatesurfaceimage) (OH_NativeImage \*image) | 通过OH_NativeImage获取最新帧更新相关联的OpenGL ES纹理 |
| [OH_NativeImage_GetTimestamp](_o_h___native_image.md#oh_nativeimage_gettimestamp) (OH_NativeImage \*image) | 获取最近调用OH_NativeImage_UpdateSurfaceImage的纹理图像的相关时间戳 |
| [OH_NativeImage_GetTransformMatrix](_o_h___native_image.md#oh_nativeimage_gettransformmatrix) (OH_NativeImage \*image, float matrix[16]) | 获取最近调用OH_NativeImage_UpdateSurfaceImage的纹理图像的变化矩阵 |
| [OH_NativeImage_Destroy](_o_h___native_image.md#oh_nativeimage_destroy) (OH_NativeImage \*\*image) | 销毁通过OH_NativeImage_Create创建的**OH_NativeImage**实例, 销毁后该<br/>**OH_NativeImage**指针会被赋值为空 |
