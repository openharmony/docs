# 驱动子系统 USB设备HDI接口 Changelog

## IUsbdSubscriber.idl行为变更

**访问级别**

公开接口

**变更原因**

USB子系统进行Feature化改造，将原有HDI接口拆分为HOST、Device、Port三种Feature。

**变更影响**

该变更为不兼容变更。

变更前：在v1_0版本中，DeviceEvent接口和PortChangedEvent接口做统一的设备事件处理。

变更后：在v2_0版本中，DeviceEvent接口按HOST Feature和Device Feature两种不同的场景进行设备事件处理，PortChangedEvent接口按Port Feature的场景进行事件处理。

**起始API Level**

API 18

**变更发生版本**

从OpenHarmony 5.1.0.48 版本开始。

**变更的接口/组件**

DeviceEvent、PortChangedEvent

**适配指导**

默认行为变更，无需适配，但应注意变更后的行为是否对整体应用逻辑产生影响。
