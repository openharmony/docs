# OH_ArkUI_LineSpacingStyle
 <!--Kit: ArkUI-->
 <!--Subsystem: ArkUI-->
 <!--Owner: @carnivore233-->
 <!--Designer: @carnivore233-->
 <!--Tester: @mateng_Holtens-->
 <!--Adviser: @Brilliantry_Rui-->

```c
typedef struct OH_ArkUI_LineSpacingStyle OH_ArkUI_LineSpacingStyle
```

## 概述

定义行间距样式，用于设置文本行之间的间距，可提升文本可读性和视觉效果。适用于电子书阅读器、新闻资讯类应用、长文档编辑等需要精细控制多行文本排版行间距的场景。<br>调用[OH_ArkUI_LineSpacingStyle_Create](capi-styled-string-h.md#oh_arkui_linespacingstyle_create)接口创建行间距样式对象，行间距默认值为0，行间距是否只在行间生效默认为false。<br>调用[OH_ArkUI_LineSpacingStyle_Destroy](capi-styled-string-h.md#oh_arkui_linespacingstyle_destroy)接口销毁行间距样式对象。<br>对象创建成功后，调用[OH_ArkUI_LineSpacingStyle_SetLineSpacing](capi-styled-string-h.md#oh_arkui_linespacingstyle_setlinespacing)接口设置行间距值（取值范围及约束详见该接口说明）。<br>调用[OH_ArkUI_LineSpacingStyle_SetOnlyBetweenLines](capi-styled-string-h.md#oh_arkui_linespacingstyle_setonlybetweenlines)接口设置行间距是否只在行间生效（取值规则详见该接口说明），若对象创建失败，则无法进行后续设置操作。

**起始版本：** 26.0.0

**相关模块：** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**所在头文件：** [styled_string.h](capi-styled-string-h.md)