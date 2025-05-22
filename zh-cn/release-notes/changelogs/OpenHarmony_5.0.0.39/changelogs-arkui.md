# ArkUI子系统Changelog

## cl.arkui.1 修复C-API场景下NODE_TIME_PICKER_DISAPPEAR_TEXT_STYLE的get接口的错误行为

**访问级别**

公开接口

**变更原因**

该接口用于C-API中TimePicker组件用于设置或者获取待消失字体样式。

该变更修复了此处返回值的实现错误。

**变更影响**

该变更为不兼容变更。

变更前：通过该接口返回的值指向的是组件的普通字体样式。

变更后：通过该接口返回的值指向的是组件正确的待消失行字体的样式。

**起始API Level**

12

**变更发生版本**

从OpenHarmony 5.0.0.39 版本开始。

**变更的接口/组件**

C-API NODE_TIME_PICKER_DISAPPEAR_TEXT_STYLE的get接口。

**适配指导**

原先使用该接口的场景，如要保持原效果不变，换用NODE_TIME_PICKER_TEXT_STYLE接口即可。

即将原先使用 nodeApi->getAttribute(node, NODE_TIME_PICKER_DISAPPEAR_TEXT_STYLE) 变更为

nodeApi->getAttribute(node, NODE_TIME_PICKER_TEXT_STYLE)