# OH_ArkUI_SurfaceCallback
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @pengzhiwen3-->
<!--Designer: @dutie123-->
<!--Tester: @liuli0427-->
<!--Adviser: @Brilliantry_Rui-->

```c
typedef struct OH_ArkUI_SurfaceCallback OH_ArkUI_SurfaceCallback
```

## 概述

定义Surface生命周期回调结构体。当XComponent的Surface创建、销毁或尺寸发生变化时，会触发对应的回调。开发者可在回调中获取Surface指针并执行自定义渲染（如OpenGL ES渲染、Vulkan渲染或视频解码渲染等场景）。

**起始版本：** 19

**相关模块：** [OH_NativeXComponent Native XComponent](capi-oh-nativexcomponent-native-xcomponent.md)

**所在头文件：** [native_interface_xcomponent.h](capi-native-interface-xcomponent-h.md)

