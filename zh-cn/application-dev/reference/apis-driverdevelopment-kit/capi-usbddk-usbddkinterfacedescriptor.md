# UsbDdkInterfaceDescriptor
<!--Kit: Driver Development Kit-->
<!--Subsystem: Driver-->
<!--Owner: @lixinsheng2-->
<!--SE: @w00373942-->
<!--TSE: @dong-dongzhen-->

## 概述

接口描述符。

**起始版本：** 10

**相关模块：** [UsbDDK](capi-usbddk.md)

**所在头文件：** [usb_ddk_types.h](capi-usb-ddk-types-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| struct UsbInterfaceDescriptor interfaceDescriptor | 标准接口描述符。 |
| struct UsbDdkEndpointDescriptor* endPoint | 该接口所包含的端点描述符。 |
| uint8_t* extra | 未做解析的描述符，包含特定于类或供应商的描述符。 |
| uint32_t extraLength | 未做解析的描述符长度。 |


