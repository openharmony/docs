# ArkUI子系统ChangeLog

##  cl.arkui.1 工具链对Scroll的拦截规则变更

**访问级别**

公开接口

**变更原因**

[Scroll](application-dev/reference/arkui-ts/ts-container-scroll.md)组件仅支持设置单个子组件。为了避免开发者为Scroll组件添加多个子组件，编译器拦截，添加报错提示。

**变更影响**

该变更为非兼容性变更。添加了多个子组件的存量应用，会使其编译不过，但是并不会改变其应用布局和行为。

**变更发生版本**

从OpenHarmony SDK 4.1.3.5 开始。

**变更的接口/组件**

不涉及。

**适配指导**

删除Scroll组件下添加的多余子组件，即可正常编译。