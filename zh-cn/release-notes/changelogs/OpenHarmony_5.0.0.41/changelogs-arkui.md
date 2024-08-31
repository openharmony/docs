# ArkUI 子系统变更说明


## cl.arkui.1 keyboardShortcut快捷键功能增强

**访问级别**

公开接口

**变更原因**

应用快捷键功能增强。

**变更影响**

该变更为兼容性变更。

API version 13及以后，不再禁止注册以下列表中的快捷键。

- `Ctrl` + `C`
- `Ctrl` + `A`
- `Ctrl` + `V`
- `Ctrl` + `X`
- `Ctrl` + `Shift` + `Z`
- `Ctrl` + `Z`
- `Ctrl` + `Y`

变更前：应用不可以使用keyboardShortcut注册上述列表中的快捷键。

变更后：应用可以使用keyboardShortcut注册上述列表中的快捷键。

**起始API Level**

10

**变更发生版本**

从OpenHarmony SDK 5.0.0.41 版本开始。

**变更的接口/组件**

通用接口。

**适配指导**

不涉及适配，API使用参考[keyboardShortcut](../../../application-dev/reference/apis-arkui/arkui-ts/ts-universal-events-keyboardshortcut.md)。
