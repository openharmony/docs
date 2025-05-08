#  Web子系统变更说明

## cl.web.1 selectionMenuOptions接口废弃

**访问级别**

公开接口

**变更原因**

selectionMenuOptions接口功能已被editMenuOptions接口覆盖。

**变更影响**

此变更不涉及应用适配。

从API version 20开始，selectionMenuOptions接口不再维护，推荐使用editMenuOptions代替。

**起始API Level**

ArkWeb：12

**变更发生版本**

从OpenHarmony SDK 6.0开始。

**关键的接口/组件变更**

- 涉及接口

  @ohos.web.webview.d.ts中的selectionMenuOptions接口。

**适配指导**

不涉及