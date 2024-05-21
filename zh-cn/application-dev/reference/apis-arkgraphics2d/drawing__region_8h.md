# drawing_region.h


## 概述

定义了与区域相关的功能函数，包括区域的创建，边界设置和销毁等。

**引用文件：**&lt;native_drawing/drawing_region.h&gt;

**库：** libnative_drawing.so

**起始版本：** 12

**相关模块：**[Drawing](_drawing.md)


## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Drawing_Region](_drawing.md#oh_drawing_region) \* [OH_Drawing_RegionCreate](_drawing.md#oh_drawing_regioncreate) (void) | 用于创建一个区域对象，实现更精确的图形控制。 | 
| bool [OH_Drawing_RegionSetRect](_drawing.md#oh_drawing_regionsetrect) ([OH_Drawing_Region](_drawing.md#oh_drawing_region) \*region, const [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*rect) | 用于尝试给区域对象设置矩形边界。 | 
| void [OH_Drawing_RegionDestroy](_drawing.md#oh_drawing_regiondestroy) ([OH_Drawing_Region](_drawing.md#oh_drawing_region) \*) | 用于销毁区域对象并回收该对象占有的内存。 | 
