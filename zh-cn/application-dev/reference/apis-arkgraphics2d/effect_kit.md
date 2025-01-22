# EffectKit


## 概述

提供处理图像的一些基础能力，包括对当前图像的亮度调节、模糊化、灰度调节等。

**系统能力：** SystemCapability.Multimedia.Image.Core

**起始版本：** 12


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [effect_filter.h](effect__filter_8h.md) | 声明滤镜效果的接口。 | 
| [effect_types.h](effect__types_8h.md) | 声明滤镜效果的数据类型。 | 


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct  [OH_Filter_ColorMatrix](_o_h___filter___color_matrix.md) | 定义一个用来创建滤镜效果的矩阵。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_Filter](#oh_filter) [OH_Filter](#oh_filter) | 滤镜结构体，用来生成滤镜位图。 | 
| typedef struct [OH_PixelmapNative](#oh_pixelmapnative) [OH_PixelmapNative](#oh_pixelmapnative) | 定义一个位图。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [EffectErrorCode](#effecterrorcode) { EFFECT_SUCCESS = 0, EFFECT_BAD_PARAMETER = 401, EFFECT_UNSUPPORTED_OPERATION = 7600201, EFFECT_UNKNOWN_ERROR = 7600901 } | 定义滤镜效果的状态码。 | 
| [EffectTileMode](#effecttilemode) { CLAMP = 0, REPEAT, MIRROR, DECAL } | 定义着色器效果平铺模式的枚举。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [EffectErrorCode](#effecterrorcode) [OH_Filter_CreateEffect](#oh_filter_createeffect) ([OH_PixelmapNative](#oh_pixelmapnative) \*pixelmap, [OH_Filter](#oh_filter) \*\*filter) | 创建一个OH_Filter对象。 | 
| [EffectErrorCode](#effecterrorcode) [OH_Filter_Release](#oh_filter_release) ([OH_Filter](#oh_filter) \*filter) | 释放OH_Filter对象。 | 
| [EffectErrorCode](#effecterrorcode) [OH_Filter_Blur](#oh_filter_blur) ([OH_Filter](#oh_filter) \*filter, float radius) | 创建一个毛玻璃滤镜效果，然后添加到滤镜里面。 | 
| [EffectErrorCode](#effecterrorcode) [OH_Filter_BlurWithTileMode](#oh_filter_blurwithtilemode) ([OH_Filter](#oh_filter) \*filter, float radius, [EffectTileMode](#effecttilemode) tileMode) | 创建一个毛玻璃滤镜效果，然后添加到滤镜里面。 | 
| [EffectErrorCode](#effecterrorcode) [OH_Filter_Brighten](#oh_filter_brighten) ([OH_Filter](#oh_filter) \*filter, float brightness) | 创建一个提亮效果并且添加到滤镜中。 | 
| [EffectErrorCode](#effecterrorcode) [OH_Filter_GrayScale](#oh_filter_grayscale) ([OH_Filter](#oh_filter) \*filter) | 创建一个灰度效果并且添加到滤镜中。 | 
| [EffectErrorCode](#effecterrorcode) [OH_Filter_Invert](#oh_filter_invert) ([OH_Filter](#oh_filter) \*filter) | 创建一个反色效果并且添加到滤镜中。 | 
| [EffectErrorCode](#effecterrorcode) [OH_Filter_SetColorMatrix](#oh_filter_setcolormatrix) ([OH_Filter](#oh_filter) \*filter, [OH_Filter_ColorMatrix](_o_h___filter___color_matrix.md) \*matrix) | 通过矩阵创建一个自定义的效果并且添加到滤镜中。 | 
| [EffectErrorCode](#effecterrorcode) [OH_Filter_GetEffectPixelMap](#oh_filter_geteffectpixelmap) ([OH_Filter](#oh_filter) \*filter, [OH_PixelmapNative](#oh_pixelmapnative) \*\*pixelmap) | 获取滤镜生成的位图。 | 


## 类型定义说明


### OH_Filter

```
typedef struct OH_Filter OH_Filter
```

**描述**

滤镜结构体，用来生成滤镜位图。

**起始版本：** 12


### OH_PixelmapNative

```
typedef struct OH_PixelmapNative OH_PixelmapNative
```

**描述**

定义一个位图。

**起始版本：** 12


## 枚举类型说明


### EffectErrorCode

```
enum EffectErrorCode
```

**描述**

定义滤镜效果的状态码。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| EFFECT_SUCCESS | 成功 | 
| EFFECT_BAD_PARAMETER | 无效的参数 | 
| EFFECT_UNSUPPORTED_OPERATION | 不支持的操作 | 
| EFFECT_UNKNOWN_ERROR | 未知错误 | 


### EffectTileMode

```
enum EffectTileMode
```

**描述**

定义着色器效果平铺模式的枚举。

**起始版本：** 14

| 枚举值 | 描述 | 
| -------- | -------- |
| CLAMP | 如果着色器效果超出其原始边界，剩余区域使用着色器的边缘颜色填充。 | 
| REPEAT | 在水平和垂直方向上重复着色器效果。 | 
| MIRROR | 在水平和垂直方向上重复着色器效果，交替镜像图像，以便相邻图像始终接合。 | 
| DECAL | 仅在其原始边界内渲染着色器效果。 | 


## 函数说明


### OH_Filter_Blur()

```
EffectErrorCode OH_Filter_Blur (OH_Filter* filter, float radius )
```

**描述**

创建一个毛玻璃滤镜效果，然后添加到滤镜里面。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| filter | 滤镜指针。 | 
| radius | 毛玻璃效果的模糊半径，单位为像素。 | 

**返回：**

返回结果参见状态码[EffectErrorCode](#effecterrorcode)。


### OH_Filter_BlurWithTileMode()

```
EffectErrorCode OH_Filter_BlurWithTileMode (OH_Filter* filter, float radius, EffectTileMode tileMode )
```

**描述**

创建一个毛玻璃滤镜效果，然后添加到滤镜里面。

**起始版本：** 14

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| filter | 滤镜指针。 | 
| radius | 毛玻璃效果的模糊半径，单位为像素。 | 
| tileMode | 着色器效果平铺模式，支持可选的具体模式可见[EffectTileMode](#effecttilemode)枚举。 | 

**返回：**

返回结果参见状态码[EffectErrorCode](#effecterrorcode)。

操作成功则返回EFFECT_SUCCESS。

无效参数则返回EFFECT_BAD_PARAMETER。


### OH_Filter_Brighten()

```
EffectErrorCode OH_Filter_Brighten (OH_Filter* filter, float brightness )
```

**描述**

创建一个提亮效果并且添加到滤镜中。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| filter | 滤镜指针。 | 
| brightness | 提亮效果的亮度值, 取值范围在0-1之间，取值为0时图像保持不变。 | 

**返回：**

返回结果参见状态码[EffectErrorCode](#effecterrorcode)。


### OH_Filter_CreateEffect()

```
EffectErrorCode OH_Filter_CreateEffect (OH_PixelmapNative* pixelmap, OH_Filter** filter )
```

**描述**

创建一个OH_Filter对象。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pixelmap | 创建滤镜的位图。 | 
| filter | 用来接收滤镜的二级指针。 | 

**返回：**

返回结果参见状态码[EffectErrorCode](#effecterrorcode)。


### OH_Filter_GetEffectPixelMap()

```
EffectErrorCode OH_Filter_GetEffectPixelMap (OH_Filter* filter, OH_PixelmapNative** pixelmap )
```

**描述**

获取滤镜生成的位图。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| filter | 用来创建位图的滤镜指针。 | 
| pixelmap | 用来接收位图的二级指针。 | 

**返回：**

返回结果参见状态码[EffectErrorCode](#effecterrorcode)。


### OH_Filter_GrayScale()

```
EffectErrorCode OH_Filter_GrayScale (OH_Filter* filter)
```

**描述**

创建一个灰度效果并且添加到滤镜中。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| filter | 滤镜指针。 | 

**返回：**

返回结果参见状态码[EffectErrorCode](#effecterrorcode)。


### OH_Filter_Invert()

```
EffectErrorCode OH_Filter_Invert (OH_Filter* filter)
```

**描述**

创建一个反色效果并且添加到滤镜中。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| filter | 滤镜指针。 | 

**返回：**

返回结果参见状态码[EffectErrorCode](#effecterrorcode)。


### OH_Filter_Release()

```
EffectErrorCode OH_Filter_Release (OH_Filter* filter)
```

**描述**

释放OH_Filter对象。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| filter | 被释放的对象指针。 | 

**返回：**

返回结果参见状态码[EffectErrorCode](#effecterrorcode)。


### OH_Filter_SetColorMatrix()

```
EffectErrorCode OH_Filter_SetColorMatrix (OH_Filter* filter, OH_Filter_ColorMatrix* matrix )
```

**描述**

通过矩阵创建一个自定义的效果并且添加到滤镜中。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| filter | 滤镜指针。 | 
| matrix | 用来创建滤镜的自定义矩阵 [OH_Filter_ColorMatrix](_o_h___filter___color_matrix.md)。 | 

**返回：**

返回结果参见状态码[EffectErrorCode](#effecterrorcode)。
