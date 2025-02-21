# 窗口子系统Changelog

## TYPE_FLOAT类型的窗口层级高于dock栏

**访问级别**

公开接口

**变更原因**

UX规范变更。

**变更影响**

此变更不涉及应用适配。

- 变更前：TYPE_FLOAT类型的悬浮窗层级在dock栏之下
  
- 变更后：TYPE_FLOAT类型的悬浮窗层级在dock栏之上

**起始API Level**

15

**变更发生版本**

从OpenHarmony SDK 5.1.0.52开始。

**适配指导**

默认行为变更，无需适配。