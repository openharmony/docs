# OH_ArkUI_CustomSpan
 <!--Kit: ArkUI-->
 <!--Subsystem: ArkUI-->
 <!--Owner: @carnivore233-->
 <!--Designer: @carnivore233-->
 <!--Tester: @mateng_Holtens-->
 <!--Adviser: @Brilliantry_Rui-->

```c
typedef struct OH_ArkUI_CustomSpan OH_ArkUI_CustomSpan
```

## 概述

定义自定义绘制Span，用于在属性字符串中实现自定义测量和绘制能力。自定义绘制Span通过测量回调确定其占位大小，通过绘制回调在对应区域内绘制自定义内容，从而将自定义图形元素嵌入到富文本中。<br>调用[OH_ArkUI_CustomSpan_Create](capi-styled-string-h.md#oh_arkui_customspan_create)接口创建自定义绘制Span对象。<br>对象创建后，调用[OH_ArkUI_CustomSpan_RegisterOnMeasureCallback](capi-styled-string-h.md#oh_arkui_customspan_registeronmeasurecallback)接口注册测量回调函数。<br>调用[OH_ArkUI_CustomSpan_RegisterOnDrawCallback](capi-styled-string-h.md#oh_arkui_customspan_registerondrawcallback)接口注册绘制回调函数。<br>调用[OH_ArkUI_CustomSpan_Destroy](capi-styled-string-h.md#oh_arkui_customspan_destroy)接口销毁自定义绘制Span对象。

**起始版本：** 24

**相关模块：** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**所在头文件：** [styled_string.h](capi-styled-string-h.md)