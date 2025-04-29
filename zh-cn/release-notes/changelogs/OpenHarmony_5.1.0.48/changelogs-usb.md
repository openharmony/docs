# 驱动子系统 Changelog

## cl.usb.1 USB设备HDI接口变更

**访问级别**

公开接口

**变更原因**

USB子系统进行Feature化改造，将原有HDI接口拆分为HOST、Device、Port三种Feature。

**变更影响**

该变更为不兼容变更。

| idl接口文件     | 变更前     | 变更后 | 说明                                  |
|---------|--------|----|-------------------------------------|
| IUsbHostInterface.idl | 在v1_0、v1_1和v1_2版本的IUsbInterface.idl中，在UsbService中调用HDI层接口 | 移到v2_0版本的IUsbHostInterface.idl中，在UsbHostManager中调用HDI层接口 | 包括USB Device管理(Device查询、Open/Close、Device配置管理)、USB数据传输、USB Device访问授权等HOST模式下相关功能 |
| IUsbPortInterface.idl  | 同上 | 移到v2_0版本的IUsbPortInterface.idl中，在UsbManager中调用HDI层接口 | 包括USB Port配置管理（查询Ports清单，查询/设置Port Roles） |
| IUsbDeviceInterface.idl  | 同上 | 移到v2_0版本的IUsbDeviceInterface.idl中，在UsbDeviceManager中调用HDI层接口 | 包括USB Function管理，支持查询/设置USB功能Functions |
| UsbTypes.idl  | 在v1_0、v1_1和v1_2版本中 | 在UsbService中使用类型 |  |
| IUsbdTransferCallback.idl  | 在v1_0和v1_2版本中，在UsbService中返回数据 | v2_0版本的回调接口在UsbHostManager、UsbDeviceManager和UsbPortManager中返回数据 |  |
| IUsbdBulkCallback.idl  | 同上 | 同上 |  |
| IUsbdSubscriber.idl  | 原有事件处理在v1_0中，DeviceEvent接口和PortChangedEvent接口做统一的设备事件处理 | 在v2_0版本的事件处理，DeviceEvent接口按HOST Feature和Device Feature两种不同的场景进行设备事件处理，PortChangedEvent接口按Port Feature的场景进行事件处理 |  |

**起始API Level**

API 9

**变更发生版本**

从OpenHarmony 5.1.0.48 版本开始。

**变更的接口/组件**

DeviceEvent、PortChangedEvent

**适配指导**

默认行为变更，无需适配，不支持USB HOST模式或USB DEVICE模式的设备可不配置相应的Feature。
