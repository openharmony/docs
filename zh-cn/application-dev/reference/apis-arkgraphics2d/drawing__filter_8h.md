# drawing_filter.h


## 概述

声明与绘图模块中的滤波器对象相关的函数。

**引用文件：**&lt;native_drawing/drawing_filter.h&gt;

**库：** libnative_drawing.so

**起始版本：** 11

**相关模块：**[Drawing](_drawing.md)


## 汇总


### 函数

| 名称 | 描述 |
| -------- | -------- |
| [OH_Drawing_Filter](_drawing.md#oh_drawing_filter) \* [OH_Drawing_FilterCreate](_drawing.md#oh_drawing_filtercreate) (void) | 创建一个滤波器对象。 |
| void [OH_Drawing_FilterSetImageFilter](_drawing.md#oh_drawing_filtersetimagefilter) ([OH_Drawing_Filter](_drawing.md#oh_drawing_filter) \*, [OH_Drawing_ImageFilter](_drawing.md#oh_drawing_imagefilter) \*) | 为滤波器对象设置图像滤波器对象。 | 
| void [OH_Drawing_FilterSetMaskFilter](_drawing.md#oh_drawing_filtersetmaskfilter) ([OH_Drawing_Filter](_drawing.md#oh_drawing_filter) \*, [OH_Drawing_MaskFilter](_drawing.md#oh_drawing_maskfilter) \*) | 为滤波器对象设置蒙版滤波器对象。 |
| void [OH_Drawing_FilterSetColorFilter](_drawing.md#oh_drawing_filtersetcolorfilter) ([OH_Drawing_Filter](_drawing.md#oh_drawing_filter) \*, [OH_Drawing_ColorFilter](_drawing.md#oh_drawing_colorfilter) \*) | 为滤波器对象设置颜色滤波器对象。 |
| void [OH_Drawing_FilterDestroy](_drawing.md#oh_drawing_filterdestroy) ([OH_Drawing_Filter](_drawing.md#oh_drawing_filter) \*) | 销毁滤波器对象，并收回该对象占用的内存。 |
