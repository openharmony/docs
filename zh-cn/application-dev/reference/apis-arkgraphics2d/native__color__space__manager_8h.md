# native_color_space_manager.h


## 概述

定义创建和使用色彩空间的相关函数。

**引用文件：**&lt;native_color_space_manager/native_color_space_manager.h&gt;

**库：** libnative_color_space_manager.so

**系统能力：** SystemCapability.Graphic.Graphic2D.ColorManager.Core

**起始版本：** 13

**相关模块：**[NativeColorSpaceManager](_native_color_space_manager.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct  [ColorSpacePrimaries](_color_space_primaries.md) | 提供色彩原色结构体声明。 | 
| struct  [WhitePointArray](_white_point_array.md) | 提供白点数组结构体，白点是指在当前色域中表示白色的坐标。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_NativeColorSpaceManager](_native_color_space_manager.md#oh_nativecolorspacemanager) [OH_NativeColorSpaceManager](_native_color_space_manager.md#oh_nativecolorspacemanager) | 提供OH_NativeColorSpaceManager结构体声明。 | 
| typedef enum [ColorSpaceName](_native_color_space_manager.md#colorspacename) [ColorSpaceName](_native_color_space_manager.md#colorspacename) | 色彩空间枚举。 | 
| typedef struct [ColorSpacePrimaries](_color_space_primaries.md) [ColorSpacePrimaries](_native_color_space_manager.md#colorspaceprimaries) | 提供色彩原色结构体声明。 | 
| typedef struct [WhitePointArray](_white_point_array.md) [WhitePointArray](_native_color_space_manager.md#whitepointarray) | 提供白点数组结构体，白点是指在当前色域中表示白色的坐标。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [ColorSpaceName](_native_color_space_manager.md#colorspacename) {<br/>NONE = 0, ADOBE_RGB = 1, DCI_P3 = 2, DISPLAY_P3 = 3,<br/>SRGB = 4, BT709 = 6, BT601_EBU = 7, BT601_SMPTE_C = 8,<br/>BT2020_HLG = 9, BT2020_PQ = 10, P3_HLG = 11, P3_PQ = 12,<br/>ADOBE_RGB_LIMIT = 13, DISPLAY_P3_LIMIT = 14, SRGB_LIMIT = 15, BT709_LIMIT = 16,<br/>BT601_EBU_LIMIT = 17, BT601_SMPTE_C_LIMIT = 18, BT2020_HLG_LIMIT = 19, BT2020_PQ_LIMIT = 20,<br/>P3_HLG_LIMIT = 21, P3_PQ_LIMIT = 22, LINEAR_P3 = 23, LINEAR_SRGB = 24,<br/>LINEAR_BT709 = LINEAR_SRGB, LINEAR_BT2020 = 25, DISPLAY_SRGB = SRGB, DISPLAY_P3_SRGB = DISPLAY_P3,<br/>DISPLAY_P3_HLG = P3_HLG, DISPLAY_P3_PQ = P3_PQ, CUSTOM = 5<br/>} | 色彩空间枚举。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_NativeColorSpaceManager](_native_color_space_manager.md#oh_nativecolorspacemanager) \* [OH_NativeColorSpaceManager_CreateFromName](_native_color_space_manager.md#oh_nativecolorspacemanager_createfromname) ([ColorSpaceName](_native_color_space_manager.md#colorspacename) colorSpaceName) | 通过colorSpaceName创建OH_NativeColorSpaceManager实例。 每次调用此函数时，都会创建一个新的OH_NativeColorSpaceManager实例。 | 
| [OH_NativeColorSpaceManager](_native_color_space_manager.md#oh_nativecolorspacemanager) \* [OH_NativeColorSpaceManager_CreateFromPrimariesAndGamma](_native_color_space_manager.md#oh_nativecolorspacemanager_createfromprimariesandgamma) ([ColorSpacePrimaries](_color_space_primaries.md) primaries, float gamma) | 通过原色和伽马值创建OH_NativeColorSpaceManager实例。 每次调用此函数时，都会创建一个新的OH_NativeColorSpaceManager实例。 | 
| void [OH_NativeColorSpaceManager_Destroy](_native_color_space_manager.md#oh_nativecolorspacemanager_destroy) ([OH_NativeColorSpaceManager](_native_color_space_manager.md#oh_nativecolorspacemanager) \*nativeColorSpaceManager) | 销毁OH_NativeColorSpaceManager实例。 | 
| int [OH_NativeColorSpaceManager_GetColorSpaceName](_native_color_space_manager.md#oh_nativecolorspacemanager_getcolorspacename) ([OH_NativeColorSpaceManager](_native_color_space_manager.md#oh_nativecolorspacemanager) \*nativeColorSpaceManager) | 获取色彩空间名称。 | 
| [WhitePointArray](_white_point_array.md)[OH_NativeColorSpaceManager_GetWhitePoint](_native_color_space_manager.md#oh_nativecolorspacemanager_getwhitepoint) ([OH_NativeColorSpaceManager](_native_color_space_manager.md#oh_nativecolorspacemanager) \*nativeColorSpaceManager) | 获取白点。 | 
| float [OH_NativeColorSpaceManager_GetGamma](_native_color_space_manager.md#oh_nativecolorspacemanager_getgamma) ([OH_NativeColorSpaceManager](_native_color_space_manager.md#oh_nativecolorspacemanager) \*nativeColorSpaceManager) | 获取伽马值。 | 
