# OH_ArkUI_TextEditorChangeEvent
 <!--Kit: ArkUI-->
 <!--Subsystem: ArkUI-->
 <!--Owner: @carnivore233-->
 <!--Designer: @carnivore233-->
 <!--Tester: @mateng_Holtens-->
 <!--Adviser: @Brilliantry_Rui-->

```c
typedef struct OH_ArkUI_TextEditorChangeEvent OH_ArkUI_TextEditorChangeEvent
```

## 概述

定义TextEditor组件文本内容变化事件的结构体，用于在文本内容变化时通知用户，支持获取变化前后的内容等信息，适用于需要在文本内容变化前进行拦截或校验的场景，例如输入拦截、内容过滤、变更确认等。

**起始版本：** 24

**相关模块：** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**所在头文件：** [native_node.h](capi-native-node-h.md)

