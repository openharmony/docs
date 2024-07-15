# drawing_round_rect.h


## 概述

文件中定义了与圆角矩形相关的功能函数。

**引用文件：** <native_drawing/drawing_round_rect.h>

**库：** libnative_drawing.so

**起始版本：** 11

**相关模块：**[Drawing](_drawing.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef enum [OH_Drawing_CornerPos](_drawing.md#oh_drawing_cornerpos)  [OH_Drawing_CornerPos](_drawing.md#oh_drawing_cornerpos) | 用于描述圆角位置的枚举。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Drawing_CornerPos](_drawing.md#oh_drawing_cornerpos) { CORNER_POS_TOP_LEFT, CORNER_POS_TOP_RIGHT, CORNER_POS_BOTTOM_RIGHT, CORNER_POS_BOTTOM_LEFT } | 用于描述圆角位置的枚举。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Drawing_RoundRect](_drawing.md#oh_drawing_roundrect) \* [OH_Drawing_RoundRectCreate](_drawing.md#oh_drawing_roundrectcreate) (const [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*, float xRad, float yRad) | 用于创建一个圆角矩形对象。 | 
| void [OH_Drawing_RoundRectSetCorner](_drawing.md#oh_drawing_roundrectsetcorner) ([OH_Drawing_RoundRect](_drawing.md#oh_drawing_roundrect) \*, [OH_Drawing_CornerPos](_drawing.md#oh_drawing_cornerpos) pos, [OH_Drawing_Corner_Radii](_drawing.md#oh_drawing_corner_radii)) | 用于设置圆角矩形中指定圆角位置的圆角半径。 | 
| [OH_Drawing_Corner_Radii](_drawing.md#oh_drawing_corner_radii) [OH_Drawing_RoundRectGetCorner](_drawing.md#oh_drawing_roundrectgetcorner) ([OH_Drawing_RoundRect](_drawing.md#oh_drawing_roundrect) \*, [OH_Drawing_CornerPos](_drawing.md#oh_drawing_cornerpos) pos) | 用于获取圆角矩形中指定圆角位置的圆角半径。 | 
| void [OH_Drawing_RoundRectDestroy](_drawing.md#oh_drawing_roundrectdestroy) ([OH_Drawing_RoundRect](_drawing.md#oh_drawing_roundrect) \*) | 用于销毁圆角矩形对象并回收该对象占有的内存。 | 
| [OH_Drawing_ErrorCode](_drawing.md#oh_drawing_errorcode) [OH_Drawing_RoundRectOffset](_drawing.md#oh_drawing_roundrectoffset) ([OH_Drawing_RoundRect](_drawing.md#oh_drawing_roundrect) \*roundRect, float dx, float dy) | 用于将圆角矩形沿x轴方向和y轴方向平移指定距离。 | 
