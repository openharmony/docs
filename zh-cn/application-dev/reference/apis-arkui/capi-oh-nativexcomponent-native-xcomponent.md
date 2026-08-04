# OH_NativeXComponent Native XComponent
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @pengzhiwen3-->
<!--Designer: @dutie123-->
<!--Tester: @liuli0427-->
<!--Adviser: @Brilliantry_Rui-->

## 概述

OH_NativeXComponent提供ArkUI XComponent持有的Surface和触摸事件能力。支持将EGL/OpenGLES渲染输出、媒体数据等自绘内容上屏显示，并实现Native层与ArkUI之间的触摸等事件交互。适用于游戏/图形渲染、视频播放、相机预览等需要在Native侧进行高性能绘制并与ArkUI联动交互的场景，具体使用请参考[Native XComponent](../../ui/napi-xcomponent-guidelines.md)。

**起始版本：** 8

## 文件汇总

| 名称 | 描述 |
| -- | -- |
| [native_interface_xcomponent.h](capi-native-interface-xcomponent-h.md) | 声明用于访问Native XComponent的API。 |
| [native_xcomponent_key_event.h](capi-native-xcomponent-key-event-h.md) | 声明用于访问Native XComponent键盘事件的枚举类型。 |
