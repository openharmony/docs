# ArkWeb子系统Changelog

## cl.arkweb.1 overScrollMode接口行为变更

**访问级别**

公开接口

**变更原因**

ArkWeb组件过滚动模式默认值变更

**变更影响**

该变更为非兼容性变更，变更后对于不设置overScrollMode的Web组件，默认会开启过滚动模式，在Web滚动到边缘时，触发过界回弹效果。

**起始API Level**

起始版本API 11，变更版本为API 12。

**变更发生版本**

从OpenHarmony SDK 5.0.0.23 版本开始。

**变更的接口/组件**

变更前接口行为

| 名称             | 默认值               | 描述                   |
| -------------- | ---------------- | -------------------- |
| overScrollMode  | OverScrollMode.NEVER | 默认关闭过滚动效果 |

变更后接口行为

| 名称             | 默认值               | 描述                   |
| -------------- | ---------------- | -------------------- |
| overScrollMode  | OverScrollMode.ALWAYS | 默认开启过滚动效果 |

**适配指导**

会影响嵌套滚动等场景用户体验。这些场景下建议在API version 12后设置overScrollMode为OverScrollMode.NEVER。

请查阅[ArkWeb组件嵌套滚动](../../../application-dev/web/web-nested-scrolling.md)文档进行适配。