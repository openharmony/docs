# ArkUI_LightEffectOptions
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @hehongyang3-->
<!--Designer: @zhanghaibo0-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->

```c
typedef struct ArkUI_LightEffectOptions ArkUI_LightEffectOptions
```

## 概述

定义沉浸式材质的光感交互效果配置对象，用于配置沉浸式材质在用户交互时产生的光感响应效果。详细设计逻辑请参见[native_material.h](capi-native-material-h.md)。沉浸式材质是一种具有深度感和层次感的视觉材质风格，光感交互效果指用户与组件交互时产生的光影视觉反馈。创建后需通过[OH_ArkUI_NativeModule_ImmersiveMaterial_SetLightEffect](capi-native-material-h.md#oh_arkui_nativemodule_immersivematerial_setlighteffect)将配置对象设置到沉浸式材质对象上才能生效。

未指定光感交互颜色时，默认光感交互颜色为白色（0xffffffff）。

**起始版本：** 26.0.0

**相关模块：** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**所在头文件：** [native_material.h](capi-native-material-h.md)
