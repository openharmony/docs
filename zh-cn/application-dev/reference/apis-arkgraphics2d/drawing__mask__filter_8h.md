# drawing_mask_filter.h


## 概述

声明与绘图模块中的对象相关的函数。

**引用文件：**&lt;native_drawing/drawing_mask_filter.h&gt;

**库：** libnative_drawing.so

**起始版本：** 11

**相关模块：**[Drawing](_drawing.md)


## 汇总


### 类型定义

| 名称 | 描述 |
| -------- | -------- |
| typedef enum [OH_Drawing_BlurType](_drawing.md#oh_drawing_blurtype)  [OH_Drawing_BlurType](_drawing.md#oh_drawing_blurtype) | 蒙版滤波器模糊操作类型的枚举。 |


### 枚举

| 名称 | 描述 |
| -------- | -------- |
| [OH_Drawing_BlurType](_drawing.md#oh_drawing_blurtype) { NORMAL, SOLID, OUTER, INNER } | 蒙版滤波器模糊操作类型的枚举。 |


### 函数

| 名称 | 描述 |
| -------- | -------- |
| [OH_Drawing_MaskFilter](_drawing.md#oh_drawing_maskfilter) \* [OH_Drawing_MaskFilterCreateBlur](_drawing.md#oh_drawing_maskfiltercreateblur) ([OH_Drawing_BlurType](_drawing.md#oh_drawing_blurtype) blurType, float sigma, bool respectCTM) | 创建具有模糊效果的蒙版滤波器。 |
| void [OH_Drawing_MaskFilterDestroy](_drawing.md#oh_drawing_maskfilterdestroy) ([OH_Drawing_MaskFilter](_drawing.md#oh_drawing_maskfilter) \*) | 销毁蒙版滤波器对象，并收回该对象占用的内存。 |
