# drawing_region.h


## 概述

定义了与区域相关的功能函数，包括区域的创建，边界设置和销毁等。

**引用文件：**&lt;native_drawing/drawing_region.h&gt;

**库：** libnative_drawing.so

**起始版本：** 12

**相关模块：**[Drawing](_drawing.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef enum [OH_Drawing_RegionOpMode](_drawing.md#oh_drawing_regionopmode)  [OH_Drawing_RegionOpMode](_drawing.md#oh_drawing_regionopmode) | 区域操作类型枚举。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Drawing_RegionOpMode](_drawing.md#oh_drawing_regionopmode) {<br/>REGION_OP_MODE_DIFFERENCE, REGION_OP_MODE_INTERSECT, REGION_OP_MODE_UNION, REGION_OP_MODE_XOR,<br/>REGION_OP_MODE_REVERSE_DIFFERENCE, REGION_OP_MODE_REPLACE<br/>} | 区域操作类型枚举。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Drawing_Region](_drawing.md#oh_drawing_region) \* [OH_Drawing_RegionCreate](_drawing.md#oh_drawing_regioncreate) (void) | 用于创建一个区域对象，实现更精确的图形控制。 | 
| bool [OH_Drawing_RegionContains](_drawing.md#oh_drawing_regioncontains) ([OH_Drawing_Region](_drawing.md#oh_drawing_region) \*region, int32_t x, int32_t y) | 判断区域是否包含指定坐标点。 |
| bool [OH_Drawing_RegionOp](_drawing.md#oh_drawing_regionop) ([OH_Drawing_Region](_drawing.md#oh_drawing_region) \*region, const [OH_Drawing_Region](_drawing.md#oh_drawing_region) \*other, [OH_Drawing_RegionOpMode](_drawing.md#oh_drawing_regionopmode) op) | 将两个区域按照指定的区域操作类型合并。 | 
| bool [OH_Drawing_RegionSetRect](_drawing.md#oh_drawing_regionsetrect) ([OH_Drawing_Region](_drawing.md#oh_drawing_region) \*region, const [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*rect) | 用于尝试给区域对象设置矩形边界。 | 
| bool [OH_Drawing_RegionSetPath](_drawing.md#oh_drawing_regionsetpath) ([OH_Drawing_Region](_drawing.md#oh_drawing_region) \*region, const [OH_Drawing_Path](_drawing.md#oh_drawing_path) \*path, const [OH_Drawing_Region](_drawing.md#oh_drawing_region) \*clip) | 给区域对象设置为指定区域内路径表示的范围。 | 
| void [OH_Drawing_RegionDestroy](_drawing.md#oh_drawing_regiondestroy) ([OH_Drawing_Region](_drawing.md#oh_drawing_region) \*) | 用于销毁区域对象并回收该对象占有的内存。 | 
