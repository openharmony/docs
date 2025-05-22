# ArkUI子系统Changelog

## cl.arkui.1 BadgeStyle和BadgeParamWithString接口支持Resource类型

**访问级别**

公开接口

**变更原因**

可以使用资源文件控制Badge组件的样式。

**变更影响**

此变更不涉及应用适配。

- 变更前：BadgeStyle和BadgeParamWithString接口部分支持Resource类型参数。
  
- 变更后：BadgeStyle和BadgeParamWithString接口均支持Resource类型参数。

**起始API Level**

10

**变更发生版本**

从OpenHarmony SDK 6.0.0.28开始。

**变更的接口/组件**

BadgeStyle.fontSize，BadgeStyle.badgeSize，BadgeStyle.fontWeight，BadgeParamWithString.value

**适配指导**

默认行为变更，无需适配。

