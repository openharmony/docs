# UsbDdkEndpointDescriptor
<!--Kit: Driver Development Kit-->
<!--Subsystem: Driver-->
<!--Owner: @zgene94-->
<!--Designer: @w00373942-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @hu-zhiqiong-->

```c
typedef struct UsbDdkEndpointDescriptor {...} UsbDdkEndpointDescriptor
```

## 概述

端点描述符，包含标准端点描述符和未做解析的描述符信息。

**起始版本：** 10

**相关模块：** [UsbDdk](capi-usbddk.md)

**所在头文件：** [usb_ddk_types.h](capi-usb-ddk-types-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| [struct UsbEndpointDescriptor](capi-usbddk-usbendpointdescriptor.md) endpointDescriptor | 标准端点描述符。 |
| const uint8_t* extra | 未做解析的描述符指针，包含特定于类或供应商的描述符。 |
| uint32_t extraLength | 未做解析的描述符长度。 |


