# ArkUI子系统Changelog

## cl.arkui.1 TextClock组件构造参数timeZoneOffset支持设置特定浮点数

**访问级别**

公开接口

**变更原因**

某些国家和地区时区偏移量为浮点数，因此需要支持设置浮点数。

**变更影响**

该变更为兼容性变更，变更后timeZoneOffset支持设置特定浮点数。

**API Level**

8 

**变更发生版本**

从OpenHarmony SDK 4.1.6.5 版本开始。

**变更的接口/组件**

API 11之前，TextClock组件构造参数timeZoneOffset设置浮点数会取对应的整数值。

API 11及之后，TextClock组件构造参数timeZoneOffset设置{ 9.5, 3.5, -3.5, -4.5, -5.5, -5.75, -6.5, -9.5, -10.5, -12.75 }里的值会取对应的浮点数。

**适配指导**

请查阅[TextClock组件](../../../application-dev/reference/arkui-ts/ts-basic-components-textclock.md)文档进行适配。