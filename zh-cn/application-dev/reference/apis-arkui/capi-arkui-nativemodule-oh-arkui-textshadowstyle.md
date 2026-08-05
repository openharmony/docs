# OH_ArkUI_TextShadowStyle
 <!--Kit: ArkUI-->
 <!--Subsystem: ArkUI-->
 <!--Owner: @carnivore233-->
 <!--Designer: @carnivore233-->
 <!--Tester: @mateng_Holtens-->
 <!--Adviser: @Brilliantry_Rui-->

```c
typedef struct OH_ArkUI_TextShadowStyle OH_ArkUI_TextShadowStyle
```

## 概述

定义文本阴影样式，文本阴影样式包含阴影偏移、模糊半径、颜色等属性，用于为文本添加阴影效果，如标题文字突出显示、深色背景下的文字增强等。<br>调用[OH_ArkUI_TextShadowStyle_Create](capi-styled-string-h.md#oh_arkui_textshadowstyle_create)接口创建文本阴影样式对象。<br>调用[OH_ArkUI_TextShadowStyle_Destroy](capi-styled-string-h.md#oh_arkui_textshadowstyle_destroy)接口销毁文本阴影样式对象。<br>创建文本阴影样式对象后，调用[OH_ArkUI_TextShadowStyle_SetTextShadow](capi-styled-string-h.md#oh_arkui_textshadowstyle_settextshadow)接口设置文本阴影的具体样式。<br>调用[OH_ArkUI_TextShadowStyle_GetTextShadow](capi-styled-string-h.md#oh_arkui_textshadowstyle_gettextshadow)接口获取已设置的文本阴影样式。

**起始版本：** 24

**相关模块：** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**所在头文件：** [styled_string.h](capi-styled-string-h.md)