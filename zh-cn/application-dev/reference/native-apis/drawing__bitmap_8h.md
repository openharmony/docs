# drawing_bitmap.h


## 概述

文件中定义了与位图相关的功能函数。

**起始版本：**

8

**相关模块：**

[Drawing](_drawing.md)


## 汇总


### 结构体

| 结构体名称 | 描述 |
| -------- | -------- |
| [OH_Drawing_BitmapFormat](_o_h___drawing___bitmap_format.md) | 结构体用于描述位图像素的格式，包括颜色类型和透明度类型 |


### 函数

| 函数名称 | 描述 |
| -------- | -------- |
| [OH_Drawing_BitmapCreate](_drawing.md#oh_drawing_bitmapcreate) (void) | 函数用于创建一个位图对象。 |
| [OH_Drawing_BitmapDestroy](_drawing.md#oh_drawing_bitmapdestroy) ([OH_Drawing_Bitmap](_drawing.md#oh_drawing_bitmap) \*) | 函数用于销毁位图对象并回收该对象占有内存。 |
| [OH_Drawing_BitmapBuild](_drawing.md#oh_drawing_bitmapbuild) ([OH_Drawing_Bitmap](_drawing.md#oh_drawing_bitmap) \*, const uint32_t width, const uint32_t height, const [OH_Drawing_BitmapFormat](_o_h___drawing___bitmap_format.md) \*) | 函数用于初始化位图对象的宽度和高度，并且为该位图设置像素格式 |
| [OH_Drawing_BitmapGetWidth](_drawing.md#oh_drawing_bitmapgetwidth) ([OH_Drawing_Bitmap](_drawing.md#oh_drawing_bitmap) \*) | 该函数用于获取指定位图的宽度 |
| [OH_Drawing_BitmapGetHeight](_drawing.md#oh_drawing_bitmapgetheight) ([OH_Drawing_Bitmap](_drawing.md#oh_drawing_bitmap) \*) | 函数用于获取指定位图的高度 |
| [OH_Drawing_BitmapGetPixels](_drawing.md#oh_drawing_bitmapgetpixels) ([OH_Drawing_Bitmap](_drawing.md#oh_drawing_bitmap) \*) | 函数用于获取指定位图的像素地址，可以通过像素地址获取到位图的像素数据 |
