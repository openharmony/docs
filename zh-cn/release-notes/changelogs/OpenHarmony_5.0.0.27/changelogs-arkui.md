# ArkUI子系统Changelog

## cl.arkui.1 onTextSelectionChange触发回调不需要获焦变更

**访问级别**
 
公开接口

**变更原因**

onTextSelectionChange回调触发与控件获焦解除绑定

**变更影响**

该变更为非兼容性变更。

变更前：控件没有获焦时，不允许触发onTextSelectionChange。

变更后：控件没有获焦时，允许触发onTextSelectionChange。

**起始API Level**

10

**变更发生版本**

从OpenHarmony SDK 5.0.0.27开始。

**变更的接口/组件**

Text、TextInput、TextArea、Search。

**适配指导**

如果onTextSelectionChange绑定了事件，需要适配未获焦时的触发回调的行为。