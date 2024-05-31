# ArkUI子系统Changelog

## cl.arkui.1 自定义弹窗避让软键盘行为优化

**访问级别**

公开接口

**变更原因**

从API version 12开始，将自定义弹窗避让软键盘行为优化为弹窗到达极限位置之后进行高度压缩与内容滚动。

**变更影响**

该变更为非兼容性变更。

API version 11及以前，自定义弹窗避让软键盘时仅抬起软键盘对应高度，横屏等高度不足场景或自定义弹窗高度较大场景下，会出现弹窗超出屏幕显示的情况。

API version 12及以后，将自定义弹窗避让软键盘行为优化为弹窗到达极限位置之后进行高度压缩，同时内容可滚动显示。

**起始API Level**

CustomDialogController: API7
openCustomDialog(options: CustomDialogOptions): API11
openCustomDialog<T extends Object>(dialogContent: ComponentContent<T>, options?: promptAction.BaseDialogOptions): API12

**变更发生版本**

从OpenHarmony SDK 5.0.0.29 版本开始。

**变更的接口/组件**

自定义弹窗

**适配指导**

默认行为变更，无需适配，但应注意变更后的行为是否对整体应用逻辑产生影响。

## cl.arkui.2 Badge组件显隐时增加缩放动效

**访问级别**

公开接口

**变更原因**

给Badge组件显隐时增加缩放动画，代替简单的出现与消失

**变更影响**

该变更为非兼容性变更。

API version 11及以前：Badge组件显隐时没有缩放动效。

API version 12及以后：Badge组件前后状态相同时不缩放，显隐时增加缩放动效。

**起始 API Level**

7

**变更发生版本**

从OpenHarmony SDK 5.0.0.29开始。

**适配指导**

默认样式变更调整，无需适配。
