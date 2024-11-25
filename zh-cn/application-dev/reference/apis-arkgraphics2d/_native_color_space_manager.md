# NativeColorSpaceManager


## 概述

主要是提供创建色彩空间及获取色彩空间相关属性的能力。

**系统能力：** SystemCapability.Graphic.Graphic2D.ColorManager.Core

**起始版本：** 13


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [native_color_space_manager.h](native__color__space__manager_8h.md) | 定义创建和使用色彩空间的相关函数。 | 


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[ColorSpacePrimaries](_color_space_primaries.md) | 提供色彩原色结构体声明。 | 
| struct&nbsp;&nbsp;[WhitePointArray](_white_point_array.md) | 提供白点数组结构体，白点是指在当前色域中表示白色的坐标。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_NativeColorSpaceManager](#oh_nativecolorspacemanager) [OH_NativeColorSpaceManager](#oh_nativecolorspacemanager) | 提供OH_NativeColorSpaceManager结构体声明。 | 
| typedef enum [ColorSpaceName](#colorspacename) [ColorSpaceName](#colorspacename) | 色彩空间枚举。 | 
| typedef struct [ColorSpacePrimaries](_color_space_primaries.md) [ColorSpacePrimaries](#colorspaceprimaries) | 提供色彩原色结构体声明。 | 
| typedef struct [WhitePointArray](_white_point_array.md) [WhitePointArray](#whitepointarray) | 提供白点数组结构体，白点是指在当前色域中表示白色的坐标。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [ColorSpaceName](#colorspacename) {<br/>NONE = 0, ADOBE_RGB = 1, DCI_P3 = 2, DISPLAY_P3 = 3,<br/>SRGB = 4, BT709 = 6, BT601_EBU = 7, BT601_SMPTE_C = 8,<br/>BT2020_HLG = 9, BT2020_PQ = 10, P3_HLG = 11, P3_PQ = 12,<br/>ADOBE_RGB_LIMIT = 13, DISPLAY_P3_LIMIT = 14, SRGB_LIMIT = 15, BT709_LIMIT = 16,<br/>BT601_EBU_LIMIT = 17, BT601_SMPTE_C_LIMIT = 18, BT2020_HLG_LIMIT = 19, BT2020_PQ_LIMIT = 20,<br/>P3_HLG_LIMIT = 21, P3_PQ_LIMIT = 22, LINEAR_P3 = 23, LINEAR_SRGB = 24,<br/>LINEAR_BT709 = LINEAR_SRGB, LINEAR_BT2020 = 25, DISPLAY_SRGB = SRGB, DISPLAY_P3_SRGB = DISPLAY_P3,<br/>DISPLAY_P3_HLG = P3_HLG, DISPLAY_P3_PQ = P3_PQ, CUSTOM = 5<br/>} | 色彩空间枚举。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_NativeColorSpaceManager](#oh_nativecolorspacemanager) \* [OH_NativeColorSpaceManager_CreateFromName](#oh_nativecolorspacemanager_createfromname) ([ColorSpaceName](#colorspacename) colorSpaceName) | 通过colorSpaceName创建OH_NativeColorSpaceManager实例。 每次调用此函数时，都会创建一个新的OH_NativeColorSpaceManager实例。 | 
| [OH_NativeColorSpaceManager](#oh_nativecolorspacemanager) \* [OH_NativeColorSpaceManager_CreateFromPrimariesAndGamma](#oh_nativecolorspacemanager_createfromprimariesandgamma) ([ColorSpacePrimaries](_color_space_primaries.md) primaries, float gamma) | 通过原色和伽马值创建OH_NativeColorSpaceManager实例。 每次调用此函数时，都会创建一个新的OH_NativeColorSpaceManager实例。 | 
| void [OH_NativeColorSpaceManager_Destroy](#oh_nativecolorspacemanager_destroy) ([OH_NativeColorSpaceManager](#oh_nativecolorspacemanager) \*nativeColorSpaceManager) | 销毁OH_NativeColorSpaceManager实例。 | 
| int [OH_NativeColorSpaceManager_GetColorSpaceName](#oh_nativecolorspacemanager_getcolorspacename) ([OH_NativeColorSpaceManager](#oh_nativecolorspacemanager) \*nativeColorSpaceManager) | 获取色彩空间名称。 | 
| [WhitePointArray](_white_point_array.md)[OH_NativeColorSpaceManager_GetWhitePoint](#oh_nativecolorspacemanager_getwhitepoint) ([OH_NativeColorSpaceManager](#oh_nativecolorspacemanager) \*nativeColorSpaceManager) | 获取白点。 | 
| float [OH_NativeColorSpaceManager_GetGamma](#oh_nativecolorspacemanager_getgamma) ([OH_NativeColorSpaceManager](#oh_nativecolorspacemanager) \*nativeColorSpaceManager) | 获取伽马值。 | 


## 类型定义说明


### ColorSpaceName

```
typedef enum ColorSpaceName ColorSpaceName
```

**描述**

色彩空间枚举。

**起始版本：** 13


### ColorSpacePrimaries

```
typedef struct ColorSpacePrimaries ColorSpacePrimaries
```

**描述**

提供色彩原色结构体声明。

**起始版本：** 13


### OH_NativeColorSpaceManager

```
typedef struct OH_NativeColorSpaceManager OH_NativeColorSpaceManager
```

**描述**

提供OH_NativeColorSpaceManager结构体声明。

**起始版本：** 13


### WhitePointArray

```
typedef struct WhitePointArray WhitePointArray
```

**描述**

提供白点数组结构体，白点是指在当前色域中表示白色的坐标。

**起始版本：** 13


## 枚举类型说明


### ColorSpaceName

```
enum ColorSpaceName
```

**描述**

色彩空间枚举。

**起始版本：** 13

| 枚举值 | 描述 | 
| -------- | -------- |
| NONE | 表示未知的色彩空间。 | 
| ADOBE_RGB | 表示基于 Adobe RGB 的色彩空间。 | 
| DCI_P3 | 表示基于 SMPTE RP 431-2-2007 和 IEC 61966-2.1：1999 的色彩空间。 | 
| DISPLAY_P3 | 表示基于 SMPTE RP 431-2-2007 和 IEC 61966-2.1：1999 的色彩空间。 | 
| SRGB | 表示基于 IEC 61966-2.1：1999 的标准红绿蓝 （SRGB） 色彩空间。 | 
| BT709 | 表示基于 ITU-R BT.709 的色彩空间。 | 
| BT601_EBU | 表示基于 ITU-R BT.601 的色彩空间。 | 
| BT601_SMPTE_C | 表示基于 ITU-R BT.601 的色彩空间。 | 
| BT2020_HLG | 表示基于 ITU-R BT.2020 的色彩空间。 | 
| BT2020_PQ | 表示基于 ITU-R BT.2020 的色彩空间。 | 
| P3_HLG | 表示色彩原色为P3_D65，传输特性为HLG，色彩范围为FUll的色彩空间。 | 
| P3_PQ | 表示色彩原色为P3_D65，传输特性为PQ，色彩范围为FUll的色彩空间。 | 
| ADOBE_RGB_LIMIT | 表示色彩原色为ADOBE_RGB，传输特性为ADOBE_RGB，色彩范围为LIMIT的色彩空间。 | 
| DISPLAY_P3_LIMIT | 表示色彩原色为P3_D65，传输特性为SRGB，色彩范围为LIMIT的色彩空间。 | 
| SRGB_LIMIT | 表示色彩原色为SRGB，传输特性为SRGB，色彩范围为LIMIT的色彩空间。 | 
| BT709_LIMIT | 表示色彩原色为BT709，传输特性为BT709，色彩范围为LIMIT的色彩空间。 | 
| BT601_EBU_LIMIT | 表示色彩原色为BT601_P，传输特性为BT709，色彩范围为LIMIT的色彩空间。 | 
| BT601_SMPTE_C_LIMIT | 表示色彩原色为BT601_N，传输特性为BT709，色彩范围为LIMIT的色彩空间。 | 
| BT2020_HLG_LIMIT | 表示色彩原色为BT2020，传输特性为HLG，色彩范围为LIMIT的色彩空间。 | 
| BT2020_PQ_LIMIT | 表示色彩原色为BT2020，传输特性为PQ，色彩范围为LIMIT的色彩空间。 | 
| P3_HLG_LIMIT | 表示色彩原色为P3_D65，传输特性为HLG，色彩范围为LIMIT的色彩空间。 | 
| P3_PQ_LIMIT | 表示色彩原色为P3_D65，传输特性为PQ，色彩范围为LIMIT的色彩空间。 | 
| LINEAR_P3 | 表示色彩原色为P3_D65，传输特性为LINEAR的色彩空间。 | 
| LINEAR_SRGB | 表示色彩原色为SRGB，传输特性为LINEAR的色彩空间。 | 
| LINEAR_BT709 | 表示色彩原色为BT709，传输特性为LINEAR的色彩空间。 | 
| LINEAR_BT2020 | 表示色彩原色为BT2020，传输特性为LINEAR的色彩空间。 | 
| DISPLAY_SRGB | 表示色彩原色为SRGB，传输特性为SRGB，色彩范围为FUll的色彩空间。 | 
| DISPLAY_P3_SRGB | 表示色彩原色为P3_D65，传输特性为SRGB，色彩范围为FUll的色彩空间。 | 
| DISPLAY_P3_HLG | 表示色彩原色为P3_D65，传输特性为HLG，色彩范围为FUll的色彩空间。 | 
| DISPLAY_P3_PQ | 表示色彩原色为P3_D65，传输特性为PQ，色彩范围为FUll的色彩空间。 | 
| CUSTOM | 表示自定义色彩空间。 | 


## 函数说明


### OH_NativeColorSpaceManager_CreateFromName()

```
OH_NativeColorSpaceManager* OH_NativeColorSpaceManager_CreateFromName (ColorSpaceName colorSpaceName)
```

**描述**

通过colorSpaceName创建OH_NativeColorSpaceManager实例。 每次调用此函数时，都会创建一个新的OH_NativeColorSpaceManager实例。

**系统能力：** SystemCapability.Graphic.Graphic2D.ColorManager.Core

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| colorSpaceName | 表示创建OH_NativeColorSpaceManager的色彩空间名称。 | 

**返回：**

返回一个指向OH_NativeColorSpaceManager实例的指针。 内存不足时，会导致创建OH_NativeColorSpaceManager实例失败。


### OH_NativeColorSpaceManager_CreateFromPrimariesAndGamma()

```
OH_NativeColorSpaceManager* OH_NativeColorSpaceManager_CreateFromPrimariesAndGamma (ColorSpacePrimaries primaries, float gamma )
```

**描述**

通过原色和伽马值创建OH_NativeColorSpaceManager实例。 每次调用此函数时，都会创建一个新的OH_NativeColorSpaceManager实例。

**系统能力：** SystemCapability.Graphic.Graphic2D.ColorManager.Core

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| primaries | 表示创建OH_NativeColorSpaceManager的色彩原色。 | 
| gamma | 表示创建OH_NativeColorSpaceManager的伽马值，伽马值为一个浮点数，用于矫正亮度范围。 伽马值通常为正值，负值会使弱光区域更亮，强光区域变暗，伽马值为0表示线性色彩空间。 | 

**返回：**

返回一个指向OH_NativeColorSpaceManager实例的指针。 内存不足时，会导致创建OH_NativeColorSpaceManager实例失败。


### OH_NativeColorSpaceManager_Destroy()

```
void OH_NativeColorSpaceManager_Destroy (OH_NativeColorSpaceManager* nativeColorSpaceManager)
```

**描述**

销毁OH_NativeColorSpaceManager实例。

**系统能力：** SystemCapability.Graphic.Graphic2D.ColorManager.Core

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| nativeColorSpaceManager | 表示指向OH_NativeColorSpaceManager实例的指针。 | 


### OH_NativeColorSpaceManager_GetColorSpaceName()

```
int OH_NativeColorSpaceManager_GetColorSpaceName (OH_NativeColorSpaceManager* nativeColorSpaceManager)
```

**描述**

获取色彩空间名称。

**系统能力：** SystemCapability.Graphic.Graphic2D.ColorManager.Core

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| nativeColorSpaceManager | 表示指向OH_NativeColorSpaceManager实例的指针。 | 

**返回：**

返回色彩空间枚举[ColorSpaceName](#colorspacename)对应的值。其中，当返回值为0时，表示接口操作失败。


### OH_NativeColorSpaceManager_GetGamma()

```
float OH_NativeColorSpaceManager_GetGamma (OH_NativeColorSpaceManager* nativeColorSpaceManager)
```

**描述**

获取伽马值。

**系统能力：** SystemCapability.Graphic.Graphic2D.ColorManager.Core

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| nativeColorSpaceManager | 表示指向OH_NativeColorSpaceManager实例的指针。 | 

**返回：**

返回值为float类型，返回值为0.0表示接口操作失败，其余返回值表示操作成功。


### OH_NativeColorSpaceManager_GetWhitePoint()

```
WhitePointArray OH_NativeColorSpaceManager_GetWhitePoint (OH_NativeColorSpaceManager* nativeColorSpaceManager)
```

**描述**

获取白点。

**系统能力：** SystemCapability.Graphic.Graphic2D.ColorManager.Core

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| nativeColorSpaceManager | 表示指向OH_NativeColorSpaceManager实例的指针。 | 

**返回：**

返回值为float数组，返回值为&lt;0.0, 0.0&gt;表示接口操作失败，其余返回值表示操作成功。
