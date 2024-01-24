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

## cl.arkui.2 Gauge组件的默认阴影模糊半径变更

**访问级别**

公开接口

**变更原因**

当前Gauge组件的默认阴影模糊半径为5vp、UX检视时发现模糊半径过小，因此依照UX规范增加阴影模糊半径到20vp。

**变更影响**

该变更为兼容性变更，改变了组件默认情况下的阴影模糊半径，提升了组件的默认显示效果。

**API Level**

11

**变更发生版本**

从OpenHarmony SDK 4.1.6.5开始。

**变更的接口/组件**

OpenHarmony SDK 4.1.6.5前，Gauge组件的默认阴影模糊半径为5vp。

![gauge](figures/oldGauge.png)

OpenHarmony SDK 4.1.6.5及以后，Gauge组件的默认阴影模糊半径为20vp。

![gauge](figures/newGauge.png)

**适配指导**

默认阴影效果变更，不涉及适配。
