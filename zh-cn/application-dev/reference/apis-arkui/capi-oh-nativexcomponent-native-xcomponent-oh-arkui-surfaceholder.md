# OH_ArkUI_SurfaceHolder
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @pengzhiwen3-->
<!--Designer: @dutie123-->
<!--Tester: @liuli0427-->
<!--Adviser: @Brilliantry_Rui-->

```c
typedef struct OH_ArkUI_SurfaceHolder OH_ArkUI_SurfaceHolder
```

## 概述

OH_ArkUI_SurfaceHolder用于封装和管理Native XComponent的Surface，提供对底层渲染表面的访问与操作能力。可通过[OH_ArkUI_SurfaceHolder_Create](capi-native-interface-xcomponent-h.md#oh_arkui_surfaceholder_create)接口创建实例，适用于在Native侧需要进行自定义渲染或与图形/媒体组件对接的场景。

**起始版本：** 19

**相关模块：** [OH_NativeXComponent Native XComponent](capi-oh-nativexcomponent-native-xcomponent.md)

**所在头文件：** [native_interface_xcomponent.h](capi-native-interface-xcomponent-h.md)

