# ArkUI子系统Changelog

## cl.arkui.1 Counter组件的focusType类型变更，使Counter的子组件获焦、失焦时，可触发其他组件的获焦、失焦。

**访问级别**

公开接口

**变更原因**

Counter组件的focusType类型为NODE，当Counter的子组件获焦、失焦时，未正确触发其他组件的获焦、失焦。

**变更影响**

该变更为不兼容变更。

变更前：Counter组件的focusType类型为NODE，子组件获焦时，页面上的其他组件没有失焦。Counter组件设置focusable属性为true，即可触发onFocus和onBlur事件。

变更后：Counter组件的focusType类型为SCOPE容器，子组件获焦时，页面上的其他组件失焦。Counter组件设置focusable属性为true，且拥有可获焦的子组件时，才能触发onFocus和onBlur事件。

**起始API Level**

API 9

**变更发生版本**

从OpenHarmony SDK 5.0.0.45开始

**变更的接口/组件**

Counter组件

**适配指导**

默认行为变更，无需适配，但应注意变更后的行为是否对整体应用逻辑产生影响。