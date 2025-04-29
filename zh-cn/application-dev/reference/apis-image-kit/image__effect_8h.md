# image_effect.h


## 概述

声明效果器相关接口。

效果器提供了滤镜的添加、删除、查询等功能。开发者可以通过效果器提供的接口将多个滤镜组合串联，从而实现较为复杂的效果调节功能。

同时，效果器支持多种输入类型，如Pixelmap、URI、Surface、Picture。不同的输入类型在效果器内部都会转换为内存对象，通过滤镜的效果处理， 获得处理结果。

**库：** libimage_effect.so

**引用文件**：&lt;multimedia/image_effect/image_effect.h&gt;

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

**相关模块：**[ImageEffect](_image_effect.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_ImageEffect](_image_effect.md#oh_imageeffect) [OH_ImageEffect](_image_effect.md#oh_imageeffect) | 定义效果器结构类型。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_ImageEffect](_image_effect.md#oh_imageeffect) \* [OH_ImageEffect_Create](_image_effect.md#oh_imageeffect_create) (const char \*name) | 创建OH_ImageEffect实例，调用[OH_ImageEffect_Release](_image_effect.md#oh_imageeffect_release)进行资源释放。  | 
| [OH_EffectFilter](_image_effect.md#oh_effectfilter) \* [OH_ImageEffect_AddFilter](_image_effect.md#oh_imageeffect_addfilter) ([OH_ImageEffect](_image_effect.md#oh_imageeffect) \*imageEffect, const char \*filterName) | 添加滤镜。  | 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_ImageEffect_AddFilterByFilter](_image_effect.md#oh_imageeffect_addfilterbyfilter) ([OH_ImageEffect](_image_effect.md#oh_imageeffect) \*imageEffect, [OH_EffectFilter](_image_effect.md#oh_effectfilter) \*filter) | 添加指定滤镜。  | 
| [OH_EffectFilter](_image_effect.md#oh_effectfilter) \* [OH_ImageEffect_InsertFilter](_image_effect.md#oh_imageeffect_insertfilter) ([OH_ImageEffect](_image_effect.md#oh_imageeffect) \*imageEffect, uint32_t index, const char \*filterName) | 插入滤镜。  | 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_ImageEffect_InsertFilterByFilter](_image_effect.md#oh_imageeffect_insertfilterbyfilter) ([OH_ImageEffect](_image_effect.md#oh_imageeffect) \*imageEffect, uint32_t index, [OH_EffectFilter](_image_effect.md#oh_effectfilter) \*filter) | 按指定位置插入滤镜。  | 
| int32_t [OH_ImageEffect_RemoveFilter](_image_effect.md#oh_imageeffect_removefilter) ([OH_ImageEffect](_image_effect.md#oh_imageeffect) \*imageEffect, const char \*filterName) | 移除滤镜。  | 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_ImageEffect_RemoveFilterByIndex](_image_effect.md#oh_imageeffect_removefilterbyindex) ([OH_ImageEffect](_image_effect.md#oh_imageeffect) \*imageEffect, uint32_t index) | 移除指定位置滤镜。  | 
| [OH_EffectFilter](_image_effect.md#oh_effectfilter) \* [OH_ImageEffect_ReplaceFilter](_image_effect.md#oh_imageeffect_replacefilter) ([OH_ImageEffect](_image_effect.md#oh_imageeffect) \*imageEffect, uint32_t index, const char \*filterName) | 替换滤镜。  | 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_ImageEffect_ReplaceFilterByFilter](_image_effect.md#oh_imageeffect_replacefilterbyfilter) ([OH_ImageEffect](_image_effect.md#oh_imageeffect) \*imageEffect, uint32_t index, const char \*filterName) | 替换指定位置滤镜。  | 
| int32_t [OH_ImageEffect_GetFilterCount](_image_effect.md#oh_imageeffect_getfiltercount) ([OH_ImageEffect](_image_effect.md#oh_imageeffect) \*imageEffect) | 查询已添加滤镜个数。  | 
| [OH_EffectFilter](_image_effect.md#oh_effectfilter) \* [OH_ImageEffect_GetFilter](_image_effect.md#oh_imageeffect_getfilter) ([OH_ImageEffect](_image_effect.md#oh_imageeffect) \*imageEffect, uint32_t index) | 查询已添加滤镜。  | 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_ImageEffect_Configure](_image_effect.md#oh_imageeffect_configure) ([OH_ImageEffect](_image_effect.md#oh_imageeffect) \*imageEffect, const char \*key, const [ImageEffect_Any](_image_effect___any.md) \*value) | 设置配置信息。  | 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_ImageEffect_SetOutputSurface](_image_effect.md#oh_imageeffect_setoutputsurface) ([OH_ImageEffect](_image_effect.md#oh_imageeffect) \*imageEffect, OHNativeWindow \*nativeWindow) | 设置输出Surface。  | 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_ImageEffect_GetInputSurface](_image_effect.md#oh_imageeffect_getinputsurface) ([OH_ImageEffect](_image_effect.md#oh_imageeffect) \*imageEffect, OHNativeWindow \*\*nativeWindow) | 获取输入Surface。  | 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_ImageEffect_SetInputPixelmap](_image_effect.md#oh_imageeffect_setinputpixelmap) ([OH_ImageEffect](_image_effect.md#oh_imageeffect) \*imageEffect, OH_PixelmapNative \*pixelmap) | 设置输入的Pixelmap。  | 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_ImageEffect_SetOutputPixelmap](_image_effect.md#oh_imageeffect_setoutputpixelmap) ([OH_ImageEffect](_image_effect.md#oh_imageeffect) \*imageEffect, OH_PixelmapNative \*pixelmap) | 设置输出的Pixelmap。  | 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_ImageEffect_SetInputNativeBuffer](_image_effect.md#oh_imageeffect_setinputnativebuffer) ([OH_ImageEffect](_image_effect.md#oh_imageeffect) \*imageEffect, OH_NativeBuffer \*nativeBuffer) | 设置输入的NativeBuffer。  | 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_ImageEffect_SetOutputNativeBuffer](_image_effect.md#oh_imageeffect_setoutputnativebuffer) ([OH_ImageEffect](_image_effect.md#oh_imageeffect) \*imageEffect, OH_NativeBuffer \*nativeBuffer) | 设置输出的NativeBuffer。  | 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_ImageEffect_SetInputUri](_image_effect.md#oh_imageeffect_setinputuri) ([OH_ImageEffect](_image_effect.md#oh_imageeffect) \*imageEffect, const char \*uri) | 设置输入的URI。  | 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_ImageEffect_SetOutputUri](_image_effect.md#oh_imageeffect_setoutputuri) ([OH_ImageEffect](_image_effect.md#oh_imageeffect) \*imageEffect, const char \*uri) | 设置输出的URI。  | 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_ImageEffect_SetInputPicture](_image_effect.md#oh_imageeffect_setinputpicture) ([OH_ImageEffect](_image_effect.md#oh_imageeffect) \*imageEffect, OH_PictureNative \*picture) | 设置输入的Picture。  | 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_ImageEffect_SetOutputPicture](_image_effect.md#oh_imageeffect_setoutputpicture) ([OH_ImageEffect](_image_effect.md#oh_imageeffect) \*imageEffect, OH_PictureNative \*picture) | 设置输出的Picture。  | 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_ImageEffect_Start](_image_effect.md#oh_imageeffect_start) ([OH_ImageEffect](_image_effect.md#oh_imageeffect) \*imageEffect) | 启动效果器。  | 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_ImageEffect_Stop](_image_effect.md#oh_imageeffect_stop) ([OH_ImageEffect](_image_effect.md#oh_imageeffect) \*imageEffect) | 停止生效效果。  | 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_ImageEffect_Release](_image_effect.md#oh_imageeffect_release) ([OH_ImageEffect](_image_effect.md#oh_imageeffect) \*imageEffect) | 释放OH_ImageEffect实例资源。  | 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_ImageEffect_Save](_image_effect.md#oh_imageeffect_save) ([OH_ImageEffect](_image_effect.md#oh_imageeffect) \*imageEffect, char \*\*info) | 序列化效果器。  | 
| [OH_ImageEffect](_image_effect.md#oh_imageeffect) \* [OH_ImageEffect_Restore](_image_effect.md#oh_imageeffect_restore) (const char \*info) | 反序列化效果器。  | 
