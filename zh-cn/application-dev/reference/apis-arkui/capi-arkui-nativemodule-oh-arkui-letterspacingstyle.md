# OH_ArkUI_LetterSpacingStyle
 <!--Kit: ArkUI-->
 <!--Subsystem: ArkUI-->
 <!--Owner: @carnivore233-->
 <!--Designer: @carnivore233-->
 <!--Tester: @mateng_Holtens-->
 <!--Adviser: @Brilliantry_Rui-->

```c
typedef struct OH_ArkUI_LetterSpacingStyle OH_ArkUI_LetterSpacingStyle
```

## 概述

定义字符间距样式，用于对文本设置字符间距以优化排版效果。适用于文本排列过密导致阅读困难等需要调整字符间距的场景，可提升文本可读性和排版美观度。<br>调用[OH_ArkUI_LetterSpacingStyle_Create](capi-styled-string-h.md#oh_arkui_letterspacingstyle_create)接口创建对应的字符间距样式对象。<br>创建对象成功后，调用[OH_ArkUI_LetterSpacingStyle_SetLetterSpacing](capi-styled-string-h.md#oh_arkui_letterspacingstyle_setletterspacing)接口设置具体的字符间距值，取值原则详见该接口说明。<br>调用[OH_ArkUI_LetterSpacingStyle_GetLetterSpacing](capi-styled-string-h.md#oh_arkui_letterspacingstyle_getletterspacing)接口获取字符间距值。<br>对象不再使用时，调用[OH_ArkUI_LetterSpacingStyle_Destroy](capi-styled-string-h.md#oh_arkui_letterspacingstyle_destroy)接口销毁字符间距样式对象。若创建失败，则不得调用上述接口。

**起始版本：** 24

**相关模块：** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**所在头文件：** [styled_string.h](capi-styled-string-h.md)