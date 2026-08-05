# OH_ArkUI_GestureStyle
 <!--Kit: ArkUI-->
 <!--Subsystem: ArkUI-->
 <!--Owner: @carnivore233-->
 <!--Designer: @carnivore233-->
 <!--Tester: @mateng_Holtens-->
 <!--Adviser: @Brilliantry_Rui-->

```c
typedef struct OH_ArkUI_GestureStyle OH_ArkUI_GestureStyle
```

## 概述

定义手势样式，适用于需要配置手势样式并接收相关事件回调的场景，便于应用统一管理手势样式及事件回调。 <br/>        可以通过[OH_ArkUI_GestureStyle_Create](capi-styled-string-h.md#oh_arkui_gesturestyle_create)接口创建对应的手势样式对象。 <br/>        可以通过[OH_ArkUI_GestureStyle_Destroy](capi-styled-string-h.md#oh_arkui_gesturestyle_destroy)接口销毁手势样式对象。 <br/>        对象创建后通过OH_ArkUI_GestureStyle_RegisterOnXXXCallback系列接口注册具体的事件回调，例如通过[OH_ArkUI_GestureStyle_RegisterOnClickCallback](capi-styled-string-h.md#oh_arkui_gesturestyle_registeronclickcallback)注册点击事件回调。

**起始版本：** 24

**相关模块：** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**所在头文件：** [styled_string.h](capi-styled-string-h.md)
