# ArkWeb子系统Changelog

## cl.arkweb.1 onBeforeUnload接口行为变更

**访问级别**

公开接口

**变更原因**

API version 11及之前，刷新或关闭场景下，在即将离开当前页面时触发onBeforeUnload回调，默认情况下会触发系统弹窗能力，弹窗提示语(回调内参数OnBeforeUnloadEvent对应的message内容)为固定英文"Is it OK to leave/reload this page?"，中文环境出现英文提示信息，影响体验。

**变更影响**

该变更为不兼容性变更。

从API version 12开始，onBeforeUnload回调内参数OnBeforeUnloadEvent对应的message内容发生变化，中文环境为"系统可能不会保存您所做的更改。"，且该字串内容支持国际化。

**起始API Level**

起始版本API 8。

**变更发生版本**

从OpenHarmony SDK 5.0.0.36 版本开始。

**变更的接口/组件**

Web#onBeforeUnload(callback: Callback<OnBeforeUnloadEvent, boolean>)中的参数OnBeforeUnloadEvent对应的弹窗中显示的信息message。

**适配指导**

默认行为变更，无需适配，但应注意变更后的行为是否对整体应用显示产生影响。
