# 驱动子系统 USB设备HDI接口 Changelog

## IUsbdBulkCallback.idl接口行为变更

**访问级别**

公开接口

**变更原因**

USB子系统进行Feature化改造，将原有HDI接口拆分为HOST、Device、Port三种Feature。

**变更影响**

该变更为不兼容变更。

变更前：该回调接口在UsbService中返回数据。

变更后：该回调接口在UsbHostManager、UsbDeviceManager和UsbPortManager中返回数据。

**起始API Level**

API 18

**变更发生版本**

从OpenHarmony 5.1.0.48 版本开始。

**变更的接口/组件**

无变更接口

**适配指导**

默认行为变更，无需适配。
