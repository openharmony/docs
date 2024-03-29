# ArkUI子系统Changelog

## cl.arkui.1 Toggle组件Switch样式移除宽高比1.8倍限制

**访问级别**

公开接口

**变更原因**

a)当前Toggle组件Switch样式宽高比固定1.8倍，依照UX规范移除1.8倍限制。

**变更影响**

该变更为非兼容性变更。API version 11及以前，Toggle组件Switch样式宽高比固定1.8倍。API version 12及以后，Toggle组件Switch样式宽高比没有限制。

**API Level**

12 

**变更发生版本**

从OpenHarmony SDK 5.0.0.21 版本开始。

**变更的接口/组件**

Toggle组件

**适配指导**

请查阅[Toggle组件](../../../application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-toggle.md)文档进行适配。
