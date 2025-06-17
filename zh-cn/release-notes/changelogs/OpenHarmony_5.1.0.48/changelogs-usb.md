# 驱动子系统 Changelog

## cl.usb.1 USB设备HDI接口变更

**访问级别**

公开接口

**变更原因**

USB子系统进行Feature化改造，将原有HDI接口拆分为Host、Device、Port三种Feature。

**变更影响**

该变更为不兼容变更。

| 接口能力     | 变更前     | 变更后                                      |
|-----------------|-------------------------|---------------------------|
| USB Device管理(Device查询、Open/Close、Device配置管理)、USB数据传输、USB Device访问授权等HOST模式下相关功能 | 在v1_0、v1_1和v1_2版本中，相关接口包含在IUsbInterface.idl中，通过UsbService调用。 | 在v2_0版本中，相关接口包含在IUsbHostInterface.idl中，通过UsbHostManager调用。 |
| USB Port配置管理（查询Ports清单，查询/设置Port Roles）  | 同上 | 在v2_0版本中，相关接口包含在IUsbHostInterface.idl中，通过UsbPortManager调用。 |
| USB Function管理（支持查询/设置）  | 同上 | 在v2_0版本中，相关接口包含在IUsbHostInterface.idl中，通过UsbDeviceManager调用。 |
| HDI接口使用的所有数据类型  | 定义在v1_0、v1_1和v1_2版本的UsbTypes.idl文件中，在UsbService中使用类型。 | 定义在v2_0版本的UsbTypes.idl文件中，在UsbHostManager、UsbPortManager和UsbDeviceManager中使用类型。 |
| 异步传输回调接口  | 在v1_0和v1_2版本中，在UsbService中返回数据。 | 在v2_0版本中，在UsbHostManager、UsbDeviceManager和UsbPortManager中返回数据。 |
| 批量传输回调接口  | 同上 | 同上 |
| 设备事件和Port变更事件处理接口  | 在v1_0版本中，DeviceEvent接口和PortChangedEvent接口做统一的设备事件处理。 | 在v2_0版本中，DeviceEvent接口按HOST Feature和Device Feature两种不同的场景进行设备事件处理，PortChangedEvent接口按Port Feature的场景进行事件处理。 |

**起始API Level**

API 9

**变更发生版本**

从OpenHarmony 5.1.0.48 版本开始。

**变更的接口/组件**

DeviceEvent、PortChangedEvent

**适配指导**

默认行为变更，无需适配，不支持USB Host模式或USB Device模式的设备可不配置相应的Feature。
