# UsbDdkConfigDescriptor
<!--Kit: Driver Development Kit-->
<!--Subsystem: Driver-->
<!--Owner: @zgene94-->
<!--Designer: @w00373942-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @hu-zhiqiong-->

```c
typedef struct UsbDdkConfigDescriptor {...} UsbDdkConfigDescriptor
```

## 概述

配置描述符，包含标准配置描述符和接口描述符等信息。

**起始版本：** 10

**相关模块：** [UsbDdk](capi-usbddk.md)

**所在头文件：** [usb_ddk_types.h](capi-usb-ddk-types-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| [struct UsbConfigDescriptor](capi-usbddk-usbconfigdescriptor.md) configDescriptor | 标准配置描述符。 |
| [struct UsbDdkInterface](capi-usbddk-usbddkinterface.md)* interface | 该配置所包含的接口。 |
| const uint8_t* extra | 未做解析的描述符指针，包含特定于类或供应商的描述符。 |
| uint32_t extraLength | 未做解析的描述符长度。 |


