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

## cl.arkui.2 hideNonSecureWindows接口使用权限变更

**访问级别**

系统接口

**变更原因**

模态UIExtension默认隐藏不安全窗口且不允许取消隐藏，造成部分场景UX体验不佳。

**变更影响**

该变更为兼容性变更。

变更前：模态UIExtension默认隐藏不安全窗口且不允许取消隐藏。

变更后：模态UIExtension默认隐藏不安全窗口，申请ohos.permission.ALLOW_SHOW_NON_SECURE_WINDOWS权限后可取消隐藏。

**起始API Level**

API 12

**变更发生版本**

从OpenHarmony SDK 5.0.0.41开始。

**变更的接口/组件**

CreateModalUIExtension和hideNonSecureWindows接口。

**适配指导**

为避免不安全窗口先隐藏再显示导致闪烁，模态UIExtension在申请ohos.permission.ALLOW_SHOW_NON_SECURE_WINDOWS权限后，可以在``onSessionCreate``函数中调用``hideNonSecureWindows(false)``接口取消对不安全窗口的隐藏。此时应用需自行确保自身内容不会被遮挡，建议使用``createSubWindowWithOptions``接口创建模态置顶子窗，并将内容都加载在子窗中。

## cl.arkui.3 MenuItem组件在非2in1设备上超长文本布局由缩略显示变更为换行显示

**访问级别**

公开接口

**变更原因**

对于使用超长文本的MenuItem组件场景，默认布局效果优化，UX体验更佳。

**变更影响**

该变更为不兼容变更。

变更前：MenuItem组件含有超长文本时，文本缩略显示。

变更后：API13开始，MenuItem组件含有超长文本时，在2in1设备上不换行，其余设备无限换行。

| 变更前长文本缩略 | 变更后非2in1设备长文本换行 |
|---------|---------|
|  ![长文本缩略](figures/menu-item-long-text-before.png)       |  ![2in1设备长文本换行](figures/menu-item-long-text-after.png)       |

**起始API Level**

API 11

**变更发生版本**

从OpenHarmony SDK 5.0.0.41开始。

**变更的接口/组件**

MenuItem组件。

**适配指导**

MenuItem UX默认布局效果变更，应用无需适配。

## cl.arkui.2 Image组件的borderRadius接口支持动态修改

**访问级别**

公开接口

**变更原因**

为了增强功能的灵活性，Image组件的borderRadius接口现在支持动态修改。

**变更影响**

该变更为不兼容变更。

变更前：Image组件的borderRadius接口动态修改不生效。

变更后：Image组件的borderRadius接口动态修改生效。

**起始API Level**

7

**变更发生版本**

从OpenHarmony SDK 5.0.0.41 版本开始。

**变更的接口/组件**

Image组件的borderRadius接口。

**适配指导**

如果代码中依赖borderRadius动态修改不生效的行为（如避免在运行时改变圆角效果），建议传入不变的值，例如：borderRadius('5px')。

## cl.arkui.3 borderImage的outset属性按照实际的延伸距离来绘制边框向外扩展的效果

**访问级别**

公开接口

**变更原因**

borderImage中的边框外延距离（outset属性）在无需绘制的区域不会被绘制，这与预期行为不符。

**变更影响**

该变更为不兼容变更。

变更前：borderImage中的边框外延距离（outset属性）在无需绘制的区域不会被绘制。

变更后：borderImage中的边框外延距离（outset属性）按照实际延伸距离进行绘制。

**起始API Level**

9

**变更发生版本**

从OpenHarmony SDK 5.0.0.41 版本开始。

**变更的接口/组件**

通用接口。

**适配指导**

默认效果变更，无需适配，但应注意变更后的默认效果是否符合开发者预期，如不符合则应自定义修改效果控制变量以达到预期。