# drawing_path_effect.h


## 概述

文件中定义了与路径效果相关的功能函数。

**引用文件：**&lt;native_drawing/drawing_path_effect.h&gt;

**库：** libnative_drawing.so

**起始版本：** 12

**相关模块：**[Drawing](_drawing.md)


## 汇总


### 函数

| 名称 | 描述 |
| -------- | -------- |
| [OH_Drawing_PathEffect](_drawing.md#oh_drawing_patheffect) \* [OH_Drawing_CreateDashPathEffect](_drawing.md#oh_drawing_createdashpatheffect) (float \*intervals, int count, float phase) | 创建一个虚线效果的路径效果对象。虚线效果由一组虚线开的间隔、虚线关的间隔数据决定。 |
| void [OH_Drawing_PathEffectDestroy](_drawing.md#oh_drawing_patheffectdestroy) ([OH_Drawing_PathEffect](_drawing.md#oh_drawing_patheffect) \*) | 销毁路径效果对象并回收该对象占有内存。 |
