# OH_ArkUI_ShadowOptions
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @carnivore233-->
<!--Designer: @carnivore233-->
<!--Tester: @mateng_Holtens-->
<!--Adviser: @Brilliantry_Rui-->

```c
typedef struct OH_ArkUI_ShadowOptions OH_ArkUI_ShadowOptions
```

## 概述

定义阴影选项，用于设置组件的阴影效果，包括阴影颜色、偏移量、模糊半径、阴影类型、是否填充等属性。<br>调用[OH_ArkUI_ShadowOptions_Create](capi-native-type-visual-h.md#oh_arkui_shadowoptions_create)接口创建对应的阴影选项对象。<br>调用[OH_ArkUI_ShadowOptions_Destroy](capi-native-type-visual-h.md#oh_arkui_shadowoptions_destroy)接口销毁阴影选项对象。<br>对象创建后，调用OH_ArkUI_ShadowOptions_SetXXX系列接口设置生效的具体样式。例如调用[OH_ArkUI_ShadowOptions_SetRadius](capi-native-type-visual-h.md#oh_arkui_shadowoptions_setradius)设置阴影模糊半径。若创建对象失败（返回空指针），调用SetXXX系列接口将不会生效。

**起始版本：** 24

**相关模块：** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**所在头文件：** [native_type_visual.h](capi-native-type-visual-h.md)
