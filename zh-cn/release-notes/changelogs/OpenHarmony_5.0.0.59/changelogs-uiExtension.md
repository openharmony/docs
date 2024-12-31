# ArkUI uiExtension hideNonSecureWindows接口PC规格变更

## cl.ArkUI.1 uiExtension hideNonSecureWindows在PC上不阻止全局悬浮窗创建和显示

**访问级别**

系统接口

**变更原因**

hideNonSecureWindows在PC上不允许全局悬浮窗创建和现实与业务诉求以及全局悬浮窗预期行为不符

**变更影响**

该变更为不兼容变更。


变更前：

hideNonSecureWindows在PC上不允许全局悬浮窗创建，且会隐藏已经创建的全局悬浮窗


变更后：

hideNonSecureWindows在PC上不阻止全局悬浮窗创建和显示


**起始API Level**

API 12

**变更发生版本**

从OpenHarmony SDK 5.0.0.59开始。

**变更的接口/组件**

hideNonSecureWindows

**适配指导**

默认行为变更，无需适配，但应注意变更后的行为是否对整体应用逻辑产生影响。
