# 驱动子系统 USB设备HDI接口 Changelog

## IUsbHostInterface.idl行为变更

**访问级别**

公开接口

**变更原因**

USB子系统进行Feature化改造，将原有HDI接口拆分为HOST、Device、Port三种Feature。

**变更影响**

该变更为不兼容变更。

变更前：原有HDI接口在v1_2版本的IUsbInterface.idl中，在UsbService中调用HDI层接口。

变更后：将v1_2版本的IUsbInterface.idl中支持HOST Feature的接口移到v2_0版本的IUsbHostInterface.idl中，在UsbHostManager中调用HDI层接口，包括USB Device管理(Device查询、Open/Close、Device配置管理)、USB数据传输、USB Device访问授权等HOST模式下相关功能。

**起始API Level**

API 18

**变更发生版本**

从OpenHarmony 5.1.0.48 版本开始。

**变更的接口/组件**

无变更接口

**适配指导**

默认行为变更，无需适配，不支持USB HOST模式的设备可不配置该Feature。
