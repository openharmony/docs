# ArkUI子系统Changelog

## cl.arkui.1 TextPicker、Progress、QRCode、TextClock、TextTimer接口支持Resource类型

**访问级别**

公开接口

**变更原因**

基础能力增强，TextPicker、Progress、QRCode、TextClock、TextTimer接口支持Resource类型，可以使用资源对象设置默认选项的值。

**变更影响**

此变更不涉及应用适配。

- 变更前：TextPickerOptions、Progress、QRCode、TextClock、TextTimer中部分接口不支持Resource类型。

- 变更后：TextPickerOptions、Progress、QRCode、TextClock、TextTimer中部分接口支持Resource类型。


**起始API Level**

11

**变更发生版本**

从OpenHarmony SDK 6.0.0.32开始。

**变更的接口/组件**

TextPicker.TextPickerOptions.value、Progress.CapsuleStyleOptions.content、QRCode.value、TextClock.format、TextTimer.fontWeight

**适配指导**

默认行为变更，无需适配。