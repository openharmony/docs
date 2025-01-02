# drawing_bitmap.h


## 概述

文件中定义了与位图相关的功能函数

**引用文件：**&lt;native_drawing/drawing_bitmap.h&gt;

**库：** libnative_drawing.so

**起始版本：** 8

**相关模块：**[Drawing](_drawing.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct  [OH_Drawing_BitmapFormat](_o_h___drawing___bitmap_format.md) | 结构体用于描述位图像素的格式，包括颜色类型和透明度类型 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_Drawing_BitmapFormat](_o_h___drawing___bitmap_format.md)  [OH_Drawing_BitmapFormat](_drawing.md#oh_drawing_bitmapformat) | 结构体用于描述位图像素的格式，包括颜色类型和透明度类型 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Drawing_Bitmap](_drawing.md#oh_drawing_bitmap) \* [OH_Drawing_BitmapCreate](_drawing.md#oh_drawing_bitmapcreate) (void) | 用于创建一个位图对象。 | 
| void [OH_Drawing_BitmapDestroy](_drawing.md#oh_drawing_bitmapdestroy) ([OH_Drawing_Bitmap](_drawing.md#oh_drawing_bitmap) \*) | 用于销毁位图对象并回收该对象占有内存。 | 
| [OH_Drawing_Bitmap](_drawing.md#oh_drawing_bitmap) \* [OH_Drawing_BitmapCreateFromPixels](_drawing.md#oh_drawing_bitmapcreatefrompixels) ([OH_Drawing_Image_Info](_o_h___drawing___image___info.md) \*, void \*pixels, uint32_t rowBytes) | 用于创建一个位图对象，并将位图像素存储内存地址设置为开发者申请内存的地址。 | 
| void [OH_Drawing_BitmapBuild](_drawing.md#oh_drawing_bitmapbuild) ([OH_Drawing_Bitmap](_drawing.md#oh_drawing_bitmap) \*, const uint32_t width, const uint32_t height, const [OH_Drawing_BitmapFormat](_o_h___drawing___bitmap_format.md) \*) | 用于初始化位图对象的宽度和高度，并且为该位图设置像素格式。 | 
| uint32_t [OH_Drawing_BitmapGetWidth](_drawing.md#oh_drawing_bitmapgetwidth) ([OH_Drawing_Bitmap](_drawing.md#oh_drawing_bitmap) \*) | 用于获取指定位图的宽度。 | 
| uint32_t [OH_Drawing_BitmapGetHeight](_drawing.md#oh_drawing_bitmapgetheight) ([OH_Drawing_Bitmap](_drawing.md#oh_drawing_bitmap) \*) | 用于获取指定位图的高度。 | 
| [OH_Drawing_ColorFormat](_drawing.md#oh_drawing_colorformat) [OH_Drawing_BitmapGetColorFormat](_drawing.md#oh_drawing_bitmapgetcolorformat) ([OH_Drawing_Bitmap](_drawing.md#oh_drawing_bitmap) \*) | 用于获取指定位图的像素存储格式。 | 
| [OH_Drawing_AlphaFormat](_drawing.md#oh_drawing_alphaformat) [OH_Drawing_BitmapGetAlphaFormat](_drawing.md#oh_drawing_bitmapgetalphaformat) ([OH_Drawing_Bitmap](_drawing.md#oh_drawing_bitmap) \*) | 用于获取指定位图的像素透明度分量。 | 
| void \* [OH_Drawing_BitmapGetPixels](_drawing.md#oh_drawing_bitmapgetpixels) ([OH_Drawing_Bitmap](_drawing.md#oh_drawing_bitmap) \*) | 用于获取指定位图的像素地址，可以通过像素地址获取到位图的像素数据。 | 
| void [OH_Drawing_BitmapGetImageInfo](_drawing.md#oh_drawing_bitmapgetimageinfo) ([OH_Drawing_Bitmap](_drawing.md#oh_drawing_bitmap) \*, [OH_Drawing_Image_Info](_o_h___drawing___image___info.md) \*) | 用于获取指定位图的信息。 | 
| bool [OH_Drawing_BitmapReadPixels](_drawing.md#oh_drawing_bitmapreadpixels) ([OH_Drawing_Bitmap](_drawing.md#oh_drawing_bitmap) \*, const [OH_Drawing_Image_Info](_o_h___drawing___image___info.md) \*dstInfo, void \*dstPixels, size_t dstRowBytes, int32_t srcX, int32_t srcY) | 将位图中的矩形区域像素数据读取到指定的内存缓冲区中。 | 
