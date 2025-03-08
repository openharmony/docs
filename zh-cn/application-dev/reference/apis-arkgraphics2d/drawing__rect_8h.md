# drawing_rect.h


## 概述

文件中定义了与矩形相关的功能函数。

**引用文件：** <native_drawing/drawing_rect.h>

**库：** libnative_drawing.so

**起始版本：** 11

**相关模块：**[Drawing](_drawing.md)


## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \* [OH_Drawing_RectCreate](_drawing.md#oh_drawing_rectcreate) (float left, float top, float right, float bottom) | 用于创建一个矩形对象，不会对设置的坐标排序，即允许矩形设置的左上角坐标大于对应的矩形右下角坐标。  | 
| float [OH_Drawing_RectGetHeight](_drawing.md#oh_drawing_rectgetheight) ([OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*) | 用于获取矩形对象高度，计算方式为设置的矩形的右下角纵坐标减去左上角纵坐标。  | 
| float [OH_Drawing_RectGetWidth](_drawing.md#oh_drawing_rectgetwidth) ([OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*) | 用于获取矩形对象的宽度，计算方式为设置的矩形的右下角横坐标减去左上角横坐标。  | 
| float [OH_Drawing_RectGetLeft](_drawing.md#oh_drawing_rectgetleft) ([OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*) | 用于获取给矩形设置的左上角的横坐标。  | 
| float [OH_Drawing_RectGetTop](_drawing.md#oh_drawing_rectgettop) ([OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*) | 用于获取给矩形设置的左上角的纵坐标。  | 
| float [OH_Drawing_RectGetRight](_drawing.md#oh_drawing_rectgetright) ([OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*) | 用于获取给矩形设置的右下角的横坐标。  | 
| float [OH_Drawing_RectGetBottom](_drawing.md#oh_drawing_rectgetbottom) ([OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*) | 用于获取给矩形设置的右下角的纵坐标。  | 
| bool [OH_Drawing_RectIntersect](_drawing.md#oh_drawing_rectintersect) ([OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*rect, const [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*other) | 用于判断两个矩形是否相交，若相交，将rect设置为两个矩形的交集。  | 
| bool [OH_Drawing_RectJoin](_drawing.md#oh_drawing_rectjoin) ([OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*rect, const [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*other) | 将两个矩形取并集。 | 
| void [OH_Drawing_RectSetLeft](_drawing.md#oh_drawing_rectsetleft) ([OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*rect, float left) | 用于设置矩形左上角的横坐标。  | 
| void [OH_Drawing_RectSetTop](_drawing.md#oh_drawing_rectsettop) ([OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*rect, float top) | 用于设置矩形左上角的纵坐标。  | 
| void [OH_Drawing_RectSetRight](_drawing.md#oh_drawing_rectsetright) ([OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*rect, float right) | 用于设置矩形右下角的横坐标。  | 
| void [OH_Drawing_RectSetBottom](_drawing.md#oh_drawing_rectsetbottom) ([OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*rect, float bottom) | 用于设置矩形右下角的纵坐标。  | 
| void [OH_Drawing_RectCopy](_drawing.md#oh_drawing_rectcopy) ([OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*sRect, [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*dRect) | 用于将源矩形对象复制到目标矩形对象。  | 
| void [OH_Drawing_RectDestroy](_drawing.md#oh_drawing_rectdestroy) ([OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*) | 用于销毁矩形对象并回收该对象占有的内存。  | 
| [OH_Drawing_Array](_drawing.md#oh_drawing_array) \* [OH_Drawing_RectCreateArray](_drawing.md#oh_drawing_rectcreatearray) (size_t size) | 用于创建一个矩形数组对象, 用来存储多个矩形对象。不再需要[OH_Drawing_Array](_drawing.md#oh_drawing_array)时，请使用[OH_Drawing_RectDestroyArray](_drawing.md#oh_drawing_rectdestroyarray)接口释放该对象的指针。  | 
| [OH_Drawing_ErrorCode](_drawing.md#oh_drawing_errorcode) [OH_Drawing_RectGetArraySize](_drawing.md#oh_drawing_rectgetarraysize) ([OH_Drawing_Array](_drawing.md#oh_drawing_array) \*rectArray, size_t \*pSize) | 用于获取矩形数组对象[OH_Drawing_Array](_drawing.md#oh_drawing_array)的大小。  | 
| [OH_Drawing_ErrorCode](_drawing.md#oh_drawing_errorcode) [OH_Drawing_RectGetArrayElement](_drawing.md#oh_drawing_rectgetarrayelement) ([OH_Drawing_Array](_drawing.md#oh_drawing_array) \*rectArray, size_t index, [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*\*rect) | 用于获取矩形数组对象中指定索引的矩形对象。  | 
| [OH_Drawing_ErrorCode](_drawing.md#oh_drawing_errorcode) [OH_Drawing_RectDestroyArray](_drawing.md#oh_drawing_rectdestroyarray) ([OH_Drawing_Array](_drawing.md#oh_drawing_array) \*rectArray) | 用于销毁矩形数组对象并回收该对象占有的内存。  | 
