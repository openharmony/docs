# OH_NativeXComponent
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @pengzhiwen3-->
<!--Designer: @dutie123-->
<!--Tester: @liuli0427-->
<!--Adviser: @Brilliantry_Rui-->

```c
typedef struct OH_NativeXComponent OH_NativeXComponent
```

## 概述

OH_NativeXComponent是ArkUI提供的XComponent在Native侧的实例封装。用于在ArkUI页面中嵌入自绘制渲染内容（如EGL/OpenGL ES/Vulkan渲染表面），并支持Native层与ArkUI层之间的触摸事件、尺寸变化等事件交互。适用于游戏、地图、视频渲染等需要在应用内集成高性能自绘制内容的场景。

**起始版本：** 8

**相关模块：** [OH_NativeXComponent Native XComponent](capi-oh-nativexcomponent-native-xcomponent.md)

**所在头文件：** [native_interface_xcomponent.h](capi-native-interface-xcomponent-h.md)

