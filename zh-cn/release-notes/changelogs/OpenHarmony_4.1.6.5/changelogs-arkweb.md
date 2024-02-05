# ArkWeb子系统Changelog

## cl.arkweb.1 nestdScroll接口行为变更

**访问级别**

公开接口

**变更原因**

ArkWeb组件嵌套滚动设置嵌套滚动模式scrollForward和scrollBackward功能实现有误。

**变更影响**

该变更为非兼容性变更，变更后原本适配ArkWeb组件嵌套滚动熟悉接口，且设置前后模式不一致的应用，需修改前后模式。

**API Level**

11

**变更发生版本**

从OpenHarmony SDK 4.1.6.5 版本开始。

**变更的接口/组件**

变更前接口行为

| 名称             | 类型               | 描述                   |
| -------------- | ---------------- | -------------------- |
| scrollForward  | NestedScrollMode | 可滚动组件往起始端滚动时的嵌套滚动选项。 |
| scrollBackward | NestedScrollMode | 可滚动组件往末尾端滚动时的嵌套滚动选项。 |

变更后接口行为

| 名称             | 类型               | 描述                   |
| -------------- | ---------------- | -------------------- |
| scrollForward  | NestedScrollMode | 可滚动组件往末尾端滚动时的嵌套滚动选项。 |
| scrollBackward | NestedScrollMode | 可滚动组件往起始端滚动时的嵌套滚动选项。 |

**适配指导**

请查阅[ArkWeb组件嵌套滚动](../../../application-dev/web/web-nested-scrolling.md)文档进行适配。