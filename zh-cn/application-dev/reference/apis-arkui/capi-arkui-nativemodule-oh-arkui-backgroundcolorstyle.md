# OH_ArkUI_BackgroundColorStyle
 <!--Kit: ArkUI-->
 <!--Subsystem: ArkUI-->
 <!--Owner: @carnivore233-->
 <!--Designer: @carnivore233-->
 <!--Tester: @mateng_Holtens-->
 <!--Adviser: @Brilliantry_Rui-->

```c
typedef struct OH_ArkUI_BackgroundColorStyle OH_ArkUI_BackgroundColorStyle
```

## 概述

定义背景颜色样式，支持自定义背景颜色和圆角半径，适用于为属性字符串设置背景高亮效果，例如搜索结果高亮、重点文本标记、标签式文本展示等场景，可提升文本的视觉层次和可辨识度。<br>调用[OH_ArkUI_BackgroundColorStyle_Create](capi-styled-string-h.md#oh_arkui_backgroundcolorstyle_create)接口创建背景颜色样式对象。<br>调用[OH_ArkUI_BackgroundColorStyle_Destroy](capi-styled-string-h.md#oh_arkui_backgroundcolorstyle_destroy)接口销毁背景颜色样式对象。<br>对象创建后，调用[OH_ArkUI_BackgroundColorStyle_SetColor](capi-styled-string-h.md#oh_arkui_backgroundcolorstyle_setcolor)和[OH_ArkUI_BackgroundColorStyle_SetRadius](capi-styled-string-h.md#oh_arkui_backgroundcolorstyle_setradius)接口设置背景颜色和圆角。<br>调用[OH_ArkUI_BackgroundColorStyle_GetColor](capi-styled-string-h.md#oh_arkui_backgroundcolorstyle_getcolor)和[OH_ArkUI_BackgroundColorStyle_GetRadius](capi-styled-string-h.md#oh_arkui_backgroundcolorstyle_getradius)接口获取背景颜色和圆角。

**起始版本：** 24

**相关模块：** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**所在头文件：** [styled_string.h](capi-styled-string-h.md)