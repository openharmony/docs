# 元能力子系统Changelog

## cl.formkit.1 卡片创建前不允许触发刷新变更

**访问级别**

公开接口

**变更原因**

卡片框架在重启场景会触发onAddForm以及收到requestForm，二者是异步并行的，所以会出现先调用onUpdateForm，后调用onAddForm的情况。对于应用，没有走onAddForm，先走onUpdateForm，会导致卡片异常。

**变更影响**

此变更不涉及应用适配。


变更前：requestForm允许在onAddForm之前执行。


变更后：requestForm不允许在onAddForm之前执行。

**起始 API Level**

API 9

**变更发生版本**

从OpenHarmony SDK 5.0.0.45开始。

**变更的接口/组件**

requestForm

**适配指导**

默认行为变更，无需适配。
