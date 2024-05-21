# ArkUI子系统Changelog

## cl.arkui.1 Progress组件线性样式默认宽度变更

**访问级别**

公开接口

**变更原因**

Progress组件线性样式默认宽度为300vp，不符合UX规范，依照UX规范进行修改。

**变更影响**

该变更为非兼容性变更，变更后Progress组件线性样式默认宽度跟随父组件宽度进行自适应变化，更加灵活。

**API Level**

8 

**变更发生版本**

从OpenHarmony SDK 4.1.6.6 版本开始。

**变更的接口/组件**

OpenHarmony SDK 4.1.6.6之前，Progress组件线性样式默认宽度为300vp。

![progress](figures/oldProgress.png)

OpenHarmony SDK 4.1.6.6及之后，Progress组件线性样式默认宽度跟随父组件宽度进行自适应变化。

![progress](figures/newProgress.png)

**适配指导**

变更前后Progress组件线性样式默认宽度会发生变化，若变更后组件宽度不符合预期，可通过设置通用属性[width](../../../application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-size.md#width)进行适配。
