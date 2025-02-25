# ArkUI子系统Changelog

## cl.arkui.1 selectDialog未选中radio样式变更

**访问级别**

公开接口

**变更原因**

弹窗内容风格优化，增强用户体验。

**变更影响**

此变更不涉及应用适配。

变更点1：selectDialog未选中radio样式变更。

| 变更前                                                                                       | 变更后                                                                        |
|-------------------------------------------------------------------------------------------|----------------------------------------------------------------------------|
| selectDialog未选中时的radio为显示非高亮状态。<br>  ![变更前](figures/selectDialog/selectDialog_before.png) | selectDialog未选中时的radio不显示。<br>![变更后](figures/selectDialog/selectDialog_after.png) |


**起始API Level**

API 9

**变更发生版本**

从OpenHarmony SDK 5.1.0.55开始。

**变更的接口/组件**

advancedDialog.selectDialog

**适配指导**

默认行为变更，无需适配。系统弹窗默认规格优化演进，若开发者有其他布局、样式诉求，建议使用CustomDialog自定义实现。