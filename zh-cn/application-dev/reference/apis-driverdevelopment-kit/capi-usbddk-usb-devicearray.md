# Usb_DeviceArray
<!--Kit: Driver Development Kit-->
<!--Subsystem: Driver-->
<!--Owner: @zgene94-->
<!--Designer: @w00373942-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @hu-zhiqiong-->

```c
typedef struct Usb_DeviceArray {...} Usb_DeviceArray
```

## 概述

设备ID数组，用于存放[OH_Usb_GetDevices](capi-usb-ddk-api-h.md#oh_usb_getdevices)接口获取到的设备ID列表和设备数量。开发者申请设备ID数组，使用完结构体后需释放申请的内存，否则会造成资源泄漏。

**起始版本：** 18

**相关模块：** [UsbDdk](capi-usbddk.md)

**所在头文件：** [usb_ddk_types.h](capi-usb-ddk-types-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| uint64_t* deviceIds | 开发者申请好的设备ID数组首地址，申请的数组大小建议不超过128，以避免过度占用内存。 |
| uint32_t num | 实际返回的设备数量，根据数量遍历deviceIds获得设备ID。当该值为0时，表示不存在USB设备。 |


