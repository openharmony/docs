# ArkUI子系统Changelog


## cl.arkui.1 滚动组件通用接口backToTop属性默认值变更

**访问级别**

公开接口

**变更原因**

[List](../../../application-dev/reference/apis-arkui/arkui-ts/ts-container-list.md)、[Grid](../../../application-dev/reference/apis-arkui/arkui-ts/ts-container-grid.md)、[Scroll](../../../application-dev/reference/apis-arkui/arkui-ts/ts-container-scroll.md)和[WaterFlow](../../../application-dev/reference/apis-arkui/arkui-ts/ts-container-waterflow.md)组件默认不支持点击状态栏回到顶部，用户体验较差。

**变更影响**

- 变更前：[List](../../../application-dev/reference/apis-arkui/arkui-ts/ts-container-list.md)、[Grid](../../../application-dev/reference/apis-arkui/arkui-ts/ts-container-grid.md)、[Scroll](../../../application-dev/reference/apis-arkui/arkui-ts/ts-container-scroll.md)和[WaterFlow](../../../application-dev/reference/apis-arkui/arkui-ts/ts-container-waterflow.md)组件[backToTop](../../../application-dev/reference/apis-arkui/arkui-ts/ts-container-scrollable-common.md#backtotop15)属性默认值为false，默认不支持点击状态栏回到顶部。
  
- 变更后：API 18及以后版本，[List](../../../application-dev/reference/apis-arkui/arkui-ts/ts-container-list.md)、[Grid](../../../application-dev/reference/apis-arkui/arkui-ts/ts-container-grid.md)、[Scroll](../../../application-dev/reference/apis-arkui/arkui-ts/ts-container-scroll.md)和[WaterFlow](../../../application-dev/reference/apis-arkui/arkui-ts/ts-container-waterflow.md)组件滚动方向为垂直方向时，[backToTop](../../../application-dev/reference/apis-arkui/arkui-ts/ts-container-scrollable-common.md#backtotop15)属性默认值为true，默认支持点击状态栏回到顶部。

**起始API Level**

API 15

**变更发生版本**

从OpenHarmony SDK 5.1.0.57开始。

**变更的接口/组件**

涉及接口：[backToTop](../../../application-dev/reference/apis-arkui/arkui-ts/ts-container-scrollable-common.md#backtotop15)属性。

涉及组件：[List](../../../application-dev/reference/apis-arkui/arkui-ts/ts-container-list.md)、[Grid](../../../application-dev/reference/apis-arkui/arkui-ts/ts-container-grid.md)、[Scroll](../../../application-dev/reference/apis-arkui/arkui-ts/ts-container-scroll.md)和[WaterFlow](../../../application-dev/reference/apis-arkui/arkui-ts/ts-container-waterflow.md)组件。

**适配指导**

默认行为变更，原则上无需适配，若应用期望点击状态栏不回到顶部，则需要设置[backToTop](../../../application-dev/reference/apis-arkui/arkui-ts/ts-container-scrollable-common.md#backtotop15)属性为false。