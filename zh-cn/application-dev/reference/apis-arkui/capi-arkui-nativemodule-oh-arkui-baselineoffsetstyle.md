# OH_ArkUI_BaselineOffsetStyle
 <!--Kit: ArkUI-->
 <!--Subsystem: ArkUI-->
 <!--Owner: @carnivore233-->
 <!--Designer: @carnivore233-->
 <!--Tester: @mateng_Holtens-->
 <!--Adviser: @Brilliantry_Rui-->

```c
typedef struct OH_ArkUI_BaselineOffsetStyle OH_ArkUI_BaselineOffsetStyle
```

## 概述

定义基线偏移量样式，用于在属性字符串中设置文本的基线偏移量，使文本在垂直方向上相对于基线进行上移或下移，从而实现上下标等特殊排版效果。基线偏移量样式需通过创建样式对象、设置偏移值后应用到属性字符串中生效。<br>调用[OH_ArkUI_BaselineOffsetStyle_Create](capi-styled-string-h.md#oh_arkui_baselineoffsetstyle_create)接口创建基线偏移量样式对象。<br>对象创建后，调用[OH_ArkUI_BaselineOffsetStyle_SetBaselineOffset](capi-styled-string-h.md#oh_arkui_baselineoffsetstyle_setbaselineoffset)接口设置基线偏移量值。<br>调用[OH_ArkUI_BaselineOffsetStyle_GetBaselineOffset](capi-styled-string-h.md#oh_arkui_baselineoffsetstyle_getbaselineoffset)接口获取基线偏移量值。<br>使用完毕后，调用[OH_ArkUI_BaselineOffsetStyle_Destroy](capi-styled-string-h.md#oh_arkui_baselineoffsetstyle_destroy)接口销毁基线偏移量样式对象。

**起始版本：** 24

**相关模块：** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**所在头文件：** [styled_string.h](capi-styled-string-h.md)