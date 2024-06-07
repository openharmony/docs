# drawing_shadow_layer.h


## 概述

声明与绘图模块中的阴影层对象相关的函数。

**引用文件：**&lt;native_drawing/drawing_shadow_layer.h&gt;

**库：** libnative_drawing.so

**起始版本：** 12

**相关模块：**[Drawing](_drawing.md)


## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Drawing_ShadowLayer](_drawing.md#oh_drawing_shadowlayer) \* [OH_Drawing_ShadowLayerCreate](_drawing.md#oh_drawing_shadowlayercreate) (float blurRadius, float x, float y, uint32_t color) | 创建一个阴影层对象。 | 
| void [OH_Drawing_ShadowLayerDestroy](_drawing.md#oh_drawing_shadowlayerdestroy) ([OH_Drawing_ShadowLayer](_drawing.md#oh_drawing_shadowlayer) \*) | 销毁阴影层对象，并收回该对象占用的内存。 | 
