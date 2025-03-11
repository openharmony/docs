# ArkUI子系统Changelog

## cl.arkui.1 半模态顶部高度位置优化

**访问级别**

公开接口

**变更原因**

半模态顶部高度位置优化。

**变更影响**

该变更为不兼容变更。

变更前：

1. 当使用Length设置的高度大于最大高度或者设置类型为SheetSize.LARGE、竖屏无状态栏时，最大高度为距离屏幕顶部8vp。
2. 当使用Length设置的高度大于最大高度或者设置类型为SheetSize.LARGE、竖屏有状态栏时，最大高度为距离信号栏8vp。
3. 当使用Length设置的高度大于最大高度或者设置类型为SheetSize.LARGE，横屏有无状态栏，最大高度都为距离屏幕顶部8vp。


变更后：

1. 当使用Length设置的高度大于最大高度或者设置类型为SheetSize.LARGE，竖屏有无状态栏，最大高度都为距离信号栏8vp。
2. 当使用Length设置的高度大于最大高度或者设置类型为SheetSize.LARGE、横屏无状态栏时，最大高度为距离屏幕顶部8vp。
3. 当使用Length设置的高度大于最大高度或者设置类型为SheetSize.LARGE、横屏有状态栏时，最大高度为距离信号栏8vp。

**起始API Level**

14

**变更发生版本**

从OpenHarmony 5.0.0.40 版本开始。

**变更的接口/组件**

bindSheet组件。

**适配指导**

默认行为变更，无需适配。

## cl.arkui.2  文本拖拽结束键盘行为变更

**访问级别**

公开接口

**变更原因**

优化系统易用性，提升用户体验

**变更影响**

该变更为兼容性变更。

变更前：从文本框A拖拽到文本框B，文本框B获焦拉起键盘，触发onEditChange回调。

变更后：从文本框A拖拽到文本框B，焦点转移到根节点。文本框B没有获焦，因此不触发onEditChange回调。

| 变更前 | 变更后 |
|---------|---------|
| ![](figures/keyboard_before.gif) | ![](figures/keyboard_after.gif) |

**起始API Level**

API 8

**变更发生版本**

从OpenHarmony 5.0.0.40 版本开始。

**变更的接口/组件**

textInput/textArea/search组件的onEditChange接口

**适配指导**

onEditChange接口的规格没有发生变化，系统默认行为变更，不需要适配。