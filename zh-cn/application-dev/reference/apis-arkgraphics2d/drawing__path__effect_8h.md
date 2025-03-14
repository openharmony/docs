# drawing_path_effect.h


## 概述

文件中定义了与路径效果相关的功能函数。

**引用文件：**&lt;native_drawing/drawing_path_effect.h&gt;

**库：** libnative_drawing.so

**起始版本：** 12

**相关模块：**[Drawing](_drawing.md)


## 汇总

### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef enum [OH_Drawing_PathDashStyle](_drawing.md#oh_drawing_pathdashstyle)  [OH_Drawing_PathDashStyle](_drawing.md#oh_drawing_pathdashstyle) | 路径效果的绘制样式枚举。  | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Drawing_PathDashStyle](_drawing.md#oh_drawing_pathdashstyle-1) { DRAWING_PATH_DASH_STYLE_TRANSLATE, DRAWING_PATH_DASH_STYLE_ROTATE, DRAWING_PATH_DASH_STYLE_MORPH } | 路径效果的绘制样式枚举。  | 

### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Drawing_PathEffect](_drawing.md#oh_drawing_patheffect) \* [OH_Drawing_CreateComposePathEffect](_drawing.md#oh_drawing_createcomposepatheffect) ([OH_Drawing_PathEffect](_drawing.md#oh_drawing_patheffect) \*outer, [OH_Drawing_PathEffect](_drawing.md#oh_drawing_patheffect) \*inner) | 创建路径组合的路径效果对象。首先应用内部路径效果，然后应用外部路径效果。  | 
| [OH_Drawing_PathEffect](_drawing.md#oh_drawing_patheffect) \* [OH_Drawing_CreateCornerPathEffect](_drawing.md#oh_drawing_createcornerpatheffect) (float radius) | 创建一个将路径的夹角变成指定半径的圆角的路径效果对象。  | 
| [OH_Drawing_PathEffect](_drawing.md#oh_drawing_patheffect) \* [OH_Drawing_CreateDashPathEffect](_drawing.md#oh_drawing_createdashpatheffect) (float \*intervals, int count, float phase) | 创建一个虚线效果的路径效果对象。虚线效果由一组虚线开的间隔、虚线关的间隔数据决定。  | 
| [OH_Drawing_PathEffect](_drawing.md#oh_drawing_patheffect) \* [OH_Drawing_CreateDiscretePathEffect](_drawing.md#oh_drawing_creatediscretepatheffect) (float segLength, float deviation) | 创建一种将路径打散并且在路径上产生不规则分布的路径效果对象。  | 
| [OH_Drawing_PathEffect](_drawing.md#oh_drawing_patheffect) \* [OH_Drawing_CreatePathDashEffect](_drawing.md#oh_drawing_createpathdasheffect) (const [OH_Drawing_Path](_drawing.md#oh_drawing_path) \*path, float advance, float phase, [OH_Drawing_PathDashStyle](_drawing.md#oh_drawing_pathdashstyle) type) | 创建一个虚线效果的路径效果对象。  | 
| [OH_Drawing_PathEffect](_drawing.md#oh_drawing_patheffect) \* [OH_Drawing_CreateSumPathEffect](_drawing.md#oh_drawing_createsumpatheffect) ([OH_Drawing_PathEffect](_drawing.md#oh_drawing_patheffect) \*firstPathEffect, [OH_Drawing_PathEffect](_drawing.md#oh_drawing_patheffect) \*secondPathEffect) | 创建一个使用两种路径效果分别生效后叠加的路径效果对象。  | 
| void [OH_Drawing_PathEffectDestroy](_drawing.md#oh_drawing_patheffectdestroy) ([OH_Drawing_PathEffect](_drawing.md#oh_drawing_patheffect) \*) | 销毁路径效果对象并回收该对象占有内存。  | 
