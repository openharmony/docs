# ArkUI_XComponentSurfaceConfig
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @pengzhiwen3-->
<!--Designer: @dutie123-->
<!--Tester: @liuli0427-->
<!--Adviser: @Brilliantry_Rui-->

```c
typedef struct ArkUI_XComponentSurfaceConfig ArkUI_XComponentSurfaceConfig
```

## 概述

定义该Surface配置，用于设置XComponent组件持有的Surface在渲染时是否被视为不透明。适用于对XComponent渲染性能有要求的场景，将Surface设置为不透明可以减少渲染合成开销，提升渲染性能。需要注意的是，仅当Surface实际渲染的内容全部为不透明时才应设置为不透明，否则可能导致渲染异常。

**起始版本：** 22

**相关模块：** [OH_NativeXComponent Native XComponent](capi-oh-nativexcomponent-native-xcomponent.md)

**所在头文件：** [native_interface_xcomponent.h](capi-native-interface-xcomponent-h.md)

