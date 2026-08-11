# OH_ArkUI_DecorationStyle
 <!--Kit: ArkUI-->
 <!--Subsystem: ArkUI-->
 <!--Owner: @carnivore233-->
 <!--Designer: @carnivore233-->
 <!--Tester: @mateng_Holtens-->
 <!--Adviser: @Brilliantry_Rui-->

```c
typedef struct OH_ArkUI_DecorationStyle OH_ArkUI_DecorationStyle
```

## 概述

定义文本装饰线样式，支持对文本添加下划线、删除线等装饰线效果，适用于需要自定义文本装饰线外观的场景，可帮助开发者灵活控制文本装饰线的类型、颜色与样式。<br>调用[OH_ArkUI_DecorationStyle_Create](capi-styled-string-h.md#oh_arkui_decorationstyle_create)接口创建文本装饰线样式对象。<br>对象创建后，调用OH_ArkUI_DecorationStyle_SetXXX系列接口设置具体样式。例如，调用[OH_ArkUI_DecorationStyle_SetTextDecorationType](capi-styled-string-h.md#oh_arkui_decorationstyle_settextdecorationtype)接口设置装饰线类型。<br>使用完毕后，调用[OH_ArkUI_DecorationStyle_Destroy](capi-styled-string-h.md#oh_arkui_decorationstyle_destroy)接口销毁文本装饰线样式对象。

**起始版本：** 24

**相关模块：** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**所在头文件：** [styled_string.h](capi-styled-string-h.md)