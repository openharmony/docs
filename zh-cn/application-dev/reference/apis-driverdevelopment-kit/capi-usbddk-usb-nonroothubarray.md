# Usb_NonRootHubArray
<!--Kit: Driver Development Kit-->
<!--Subsystem: Driver-->
<!--Owner: @zgene94-->
<!--Designer: @w00373942-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @hu-zhiqiong-->

```c
typedef struct Usb_NonRootHubArray {...} Usb_NonRootHubArray
```

## 概述

非根集线器数组，用于存放[OH_Usb_GetNonRootHubs](capi-usb-ddk-api-h.md#oh_usb_getnonroothubs)接口获取到的非根集线器设备ID数组和数量。开发者申请非根集线器ID数组，使用完结构体后需释放申请的内存，否则会造成资源泄漏。

**起始版本：** 26.0.0

**相关模块：** [UsbDdk](capi-usbddk.md)

**所在头文件：** [usb_ddk_types.h](capi-usb-ddk-types-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| uint64_t* nonRootHubIds | 开发者申请好的非根集线器设备ID数组首地址，申请的数组大小建议不超过128，以避免过度占用内存。非根USB集线器设备ID由总线号左移32位加上设备地址构造而成。 |
| uint32_t num | 实际返回的非根集线器数量，根据数量遍历nonRootHubIds获得非根集线器设备ID。当该值为0时，表示不存在非根集线器设备。 |

