#  Web子系统变更说明

## cl.web.1 getHitTest、getHitTestValue接口废弃

**访问级别**

公开接口

**变更原因**

提供实现逻辑优化的新接口getLastHitTest代替getHitTest和getHitTestValue。

**变更影响**

此变更不涉及应用适配。

从API version 16开始，getHitTest、getHitTestValue接口不再维护，推荐使用getLastHitTest代替。

**起始API Level**

ArkWeb：11

**变更发生版本**

从OpenHarmony SDK 5.1.0.52开始。

**关键的接口/组件变更**

- 涉及接口

  @ohos.web.webview.d.ts中的getHitTest接口、getHitTestValue接口。

**适配指导**

不涉及