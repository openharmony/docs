# ArkUI子系统ChangeLog

##  cl.arkui.1 工具链对Scroll的拦截规则变更

**访问级别**

公开接口

**变更原因**

[Scroll](../../../application-dev/reference/arkui-ts/ts-container-scroll.md)组件仅支持设置单个子组件。为了避免开发者为Scroll组件添加多个子组件，编译器添加报错提示。

**变更影响**

该变更为非兼容性变更。编译器对添加了多个子组件的Scroll组件添加报错提示，不会改变其布局和行为。

**API Level**

11

**变更发生版本**

从OpenHarmony SDK 4.1.3.5 开始。

**变更的接口/组件**

Scroll

**适配指导**

删除Scroll组件下添加的多余子组件。

##  cl.arkui.2 Flex容器子组件交叉轴尺寸设置和交叉轴stretch对齐方式明确优先级

**访问级别**

公开接口

**变更原因**

确定规格：Flex容器中，子组件的尺寸设置优先级高于交叉轴stretch对齐方式，同时设置，仅子组件的交叉轴尺寸设置生效。

**变更影响**

该变更为兼容性变更。

API Version 9以及之前版本：同时设置子组件的尺寸和交叉轴stretch对齐方式，子组件交叉轴尺寸设置不生效。

API Version 10变更后：同时设置子组件的尺寸和交叉轴stretch对齐方式，stretch对齐方式不生效。

**变更发生版本**

从OpenHarmony SDK 4.1.3.5 开始。

**变更的组件**

受影响的组件有：Flex。

**适配指导**

若需要交叉轴stretch对齐方式生效，删去对子组件的交叉轴上的尺寸设置。