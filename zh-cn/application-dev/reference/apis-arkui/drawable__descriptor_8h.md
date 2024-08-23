# drawable_descriptor.h


## 概述

提供NativeDrawableDescriptor接口的类型定义。

**库：** libace_ndk.z.so

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**起始版本：** 12

**相关模块：**[ArkUI_NativeModule](_ark_u_i___native_module.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [ArkUI_DrawableDescriptor](_ark_u_i___native_module.md#arkui_drawabledescriptor) [ArkUI_DrawableDescriptor](_ark_u_i___native_module.md#arkui_drawabledescriptor) | 定义 DrawableDescriptor 对象。  | 
| typedef struct [OH_PixelmapNative](_ark_u_i___native_module.md#oh_pixelmapnative) \* [OH_PixelmapNativeHandle](_ark_u_i___native_module.md#oh_pixelmapnativehandle) | 定义OH_PixelmapNative对象指针类型。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [ArkUI_DrawableDescriptor](_ark_u_i___native_module.md#arkui_drawabledescriptor) \* [OH_ArkUI_DrawableDescriptor_CreateFromPixelMap](_ark_u_i___native_module.md#oh_arkui_drawabledescriptor_createfrompixelmap) ([OH_PixelmapNativeHandle](_ark_u_i___native_module.md#oh_pixelmapnativehandle) pixelMap) | 使用 PixelMap 创建 DrawableDescriptor 对象。  | 
| [ArkUI_DrawableDescriptor](_ark_u_i___native_module.md#arkui_drawabledescriptor) \* [OH_ArkUI_DrawableDescriptor_CreateFromAnimatedPixelMap](_ark_u_i___native_module.md#oh_arkui_drawabledescriptor_createfromanimatedpixelmap) ([OH_PixelmapNativeHandle](_ark_u_i___native_module.md#oh_pixelmapnativehandle) \*array, int32_t size) | 使用 PixelMap 图片数组创建DrawableDescriptor 对象。  | 
| void [OH_ArkUI_DrawableDescriptor_Dispose](_ark_u_i___native_module.md#oh_arkui_drawabledescriptor_dispose) ([ArkUI_DrawableDescriptor](_ark_u_i___native_module.md#arkui_drawabledescriptor) \*drawableDescriptor) | 销毁 DrawableDescriptor 对象指针。  | 
| [OH_PixelmapNativeHandle](_ark_u_i___native_module.md#oh_pixelmapnativehandle) [OH_ArkUI_DrawableDescriptor_GetStaticPixelMap](_ark_u_i___native_module.md#oh_arkui_drawabledescriptor_getstaticpixelmap) ([ArkUI_DrawableDescriptor](_ark_u_i___native_module.md#arkui_drawabledescriptor) \*drawableDescriptor) | 获取 PixelMap 图片对象指针。  | 
| [OH_PixelmapNativeHandle](_ark_u_i___native_module.md#oh_pixelmapnativehandle) \* [OH_ArkUI_DrawableDescriptor_GetAnimatedPixelMapArray](_ark_u_i___native_module.md#oh_arkui_drawabledescriptor_getanimatedpixelmaparray) ([ArkUI_DrawableDescriptor](_ark_u_i___native_module.md#arkui_drawabledescriptor) \*drawableDescriptor) | 获取用于播放动画的 PixelMap 图片数组数据。  | 
| int32_t [OH_ArkUI_DrawableDescriptor_GetAnimatedPixelMapArraySize](_ark_u_i___native_module.md#oh_arkui_drawabledescriptor_getanimatedpixelmaparraysize) ([ArkUI_DrawableDescriptor](_ark_u_i___native_module.md#arkui_drawabledescriptor) \*drawableDescriptor) | 获取用于播放动画的 PixelMap 图片数组数据。  | 
| void [OH_ArkUI_DrawableDescriptor_SetAnimationDuration](_ark_u_i___native_module.md#oh_arkui_drawabledescriptor_setanimationduration) ([ArkUI_DrawableDescriptor](_ark_u_i___native_module.md#arkui_drawabledescriptor) \*drawableDescriptor, int32_t duration) | 设置 PixelMap 图片数组播放总时长。  | 
| int32_t [OH_ArkUI_DrawableDescriptor_GetAnimationDuration](_ark_u_i___native_module.md#oh_arkui_drawabledescriptor_getanimationduration) ([ArkUI_DrawableDescriptor](_ark_u_i___native_module.md#arkui_drawabledescriptor) \*drawableDescriptor) | 获取 PixelMap 图片数组播放总时长。  | 
| void [OH_ArkUI_DrawableDescriptor_SetAnimationIteration](_ark_u_i___native_module.md#oh_arkui_drawabledescriptor_setanimationiteration) ([ArkUI_DrawableDescriptor](_ark_u_i___native_module.md#arkui_drawabledescriptor) \*drawableDescriptor, int32_t iteration) | 设置 PixelMap 图片数组播放次数。  | 
| int32_t [OH_ArkUI_DrawableDescriptor_GetAnimationIteration](_ark_u_i___native_module.md#oh_arkui_drawabledescriptor_getanimationiteration) ([ArkUI_DrawableDescriptor](_ark_u_i___native_module.md#arkui_drawabledescriptor) \*drawableDescriptor) | 获取 PixelMap 图片数组播放次数。  | 
