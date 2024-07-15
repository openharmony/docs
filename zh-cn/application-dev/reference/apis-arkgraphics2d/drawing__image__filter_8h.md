# drawing_image_filter.h


## 概述

声明与绘图模块中的图像滤波器对象相关的函数。

**引用文件：**&lt;native_drawing/drawing_image_filter.h&gt;

**库：** libnative_drawing.so

**起始版本：** 12

**相关模块：**[Drawing](_drawing.md)


## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Drawing_ImageFilter](_drawing.md#oh_drawing_imagefilter) \* [OH_Drawing_ImageFilterCreateBlur](_drawing.md#oh_drawing_imagefiltercreateblur) (float sigmaX, float sigmaY, [OH_Drawing_TileMode](_drawing.md#oh_drawing_tilemode), [OH_Drawing_ImageFilter](_drawing.md#oh_drawing_imagefilter) \*input) | 创建具有模糊效果的图像滤波器。 | 
| [OH_Drawing_ImageFilter](_drawing.md#oh_drawing_imagefilter) \* [OH_Drawing_ImageFilterCreateFromColorFilter](_drawing.md#oh_drawing_imagefiltercreatefromcolorfilter) ([OH_Drawing_ColorFilter](_drawing.md#oh_drawing_colorfilter) \*colorFilter, [OH_Drawing_ImageFilter](_drawing.md#oh_drawing_imagefilter) \*input) | 创建具有颜色变换效果的图像滤波器。 | 
| void [OH_Drawing_ImageFilterDestroy](_drawing.md#oh_drawing_imagefilterdestroy) ([OH_Drawing_ImageFilter](_drawing.md#oh_drawing_imagefilter) \*) | 销毁图像滤波器对象并回收该对象占有内存。 | 
