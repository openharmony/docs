# drawing_pixel_map.h


## 概述

声明与绘图模块中的像素图对象相关的函数。

**引用文件：**&lt;native_drawing/drawing_pixel_map.h&gt;

**库：** libnative_drawing.so

**起始版本：** 12

**相关模块：**[Drawing](_drawing.md)


## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Drawing_PixelMap](_drawing.md#oh_drawing_pixelmap) \* [OH_Drawing_PixelMapGetFromNativePixelMap](_drawing.md#oh_drawing_pixelmapgetfromnativepixelmap) (NativePixelMap_ \*) | 从图像框架定义的像素图对象中获取本模块定义的像素图对象。 | 
| [OH_Drawing_PixelMap](_drawing.md#oh_drawing_pixelmap) \* [OH_Drawing_PixelMapGetFromOhPixelMapNative](_drawing.md#oh_drawing_pixelmapgetfromohpixelmapnative) (OH_PixelmapNative \*) | 从图像框架定义的像素图对象中获取本模块定义的像素图对象。 | 
| void [OH_Drawing_PixelMapDissolve](_drawing.md#oh_drawing_pixelmapdissolve) ([OH_Drawing_PixelMap](_drawing.md#oh_drawing_pixelmap) \*) | 解除本模块定义的像素图对象和图像框架定义的像素图对象之间的关系，该关系通过调用 [OH_Drawing_PixelMapGetFromNativePixelMap](_drawing.md#oh_drawing_pixelmapgetfromnativepixelmap)或[OH_Drawing_PixelMapGetFromOhPixelMapNative](_drawing.md#oh_drawing_pixelmapgetfromohpixelmapnative)建立。 | 
