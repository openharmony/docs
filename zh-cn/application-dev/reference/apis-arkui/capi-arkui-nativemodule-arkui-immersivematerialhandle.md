# ArkUI_ImmersiveMaterial\*
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @hehongyang3-->
<!--Designer: @zhanghaibo0-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->

```c
typedef struct ArkUI_ImmersiveMaterial* ArkUI_ImmersiveMaterialHandle
```

## 概述

定义指向沉浸式材质对象的指针，沉浸式材质用于实现沉浸式视觉效果对象。

可以通过[OH_ArkUI_NativeModule_ImmersiveMaterial_Create](./capi-native-material-h.md#oh_arkui_nativemodule_immersivematerial_create)创建沉浸式材质对象，创建后必须在使用完毕时调用[OH_ArkUI_NativeModule_ImmersiveMaterial_Destroy](./capi-native-material-h.md#oh_arkui_nativemodule_immersivematerial_destroy)销毁沉浸式材质对象以释放资源，避免内存泄漏。

**起始版本：** 26.0.0

**相关模块：** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**所在头文件：** [native_material.h](capi-native-material-h.md)
