# UsbDdkInterfaceDescriptor
<!--Kit: Driver Development Kit-->
<!--Subsystem: Driver-->
<!--Owner: @zgene94-->
<!--Designer: @w00373942-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @hu-zhiqiong-->

```c
typedef struct UsbDdkInterfaceDescriptor {...} UsbDdkInterfaceDescriptor
```

## 概述

接口描述符，包含标准接口描述符和端点描述符等信息。

**起始版本：** 10

**相关模块：** [UsbDdk](capi-usbddk.md)

**所在头文件：** [usb_ddk_types.h](capi-usb-ddk-types-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| [struct UsbInterfaceDescriptor](capi-usbddk-usbinterfacedescriptor.md) interfaceDescriptor | 标准接口描述符。 |
| [struct UsbDdkEndpointDescriptor](capi-usbddk-usbddkendpointdescriptor.md)* endPoint | 该接口所包含的端点描述符，可为空指针表示无端点（不包含控制端点0）。 |
| const uint8_t* extra | 未做解析的描述符指针，包含特定于类或供应商的描述符。 |
| uint32_t extraLength | 未做解析的描述符长度。 |


