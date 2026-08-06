# ArkUI_LightEffectOptions*
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @hehongyang3-->
<!--Designer: @zhanghaibo0-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->

```c
typedef ArkUI_LightEffectOptions* ArkUI_LightEffectOptionsHandle
```

## 概述

定义指向光感交互效果配置对象的指针，开发者通过该指针可配置和管理沉浸式材质的光感交互效果参数。

必须通过[OH_ArkUI_NativeModule_LightEffectOptions_Create](./capi-native-material-h.md#oh_arkui_nativemodule_lighteffectoptions_create)创建光感交互效果配置对象，使用完毕后必须调用[OH_ArkUI_NativeModule_LightEffectOptions_Destroy](./capi-native-material-h.md#oh_arkui_nativemodule_lighteffectoptions_destroy)接口销毁配置对象以释放资源，销毁后继续使用该指针会导致未定义行为。两者必须配对使用。未调用Destroy销毁对象会导致资源泄漏。

**起始版本：** 26.0.0

**相关模块：** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**所在头文件：** [native_material.h](capi-native-material-h.md)
