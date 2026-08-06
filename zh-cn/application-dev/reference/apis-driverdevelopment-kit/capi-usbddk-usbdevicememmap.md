# UsbDeviceMemMap
<!--Kit: Driver Development Kit-->
<!--Subsystem: Driver-->
<!--Owner: @zgene94-->
<!--Designer: @w00373942-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @hu-zhiqiong-->

```c
typedef struct UsbDeviceMemMap {...} UsbDeviceMemMap
```

## 概述

设备内存映射，通过[OH_Usb_CreateDeviceMemMap](capi-usb-ddk-api-h.md#oh_usb_createdevicememmap)创建，使用映射后的缓冲区可提升数据传输性能。

**起始版本：** 10

**相关模块：** [UsbDdk](capi-usbddk.md)

**所在头文件：** [usb_ddk_types.h](capi-usb-ddk-types-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| uint8_t* const address | 映射后的缓冲区地址。 |
| const size_t size | 缓冲区大小（单位：字节），必须大于 0。 |
| uint32_t offset | 所使用的缓冲区的偏移量，默认为0，表示没有偏移。偏移从缓冲区地址address开始计算，offset和bufferLength之和必须小于等于缓冲区大小size。 |
| uint32_t bufferLength | 所使用的缓冲区的长度，默认等于缓冲区大小 size，表示使用全部的缓冲区。offset和bufferLength之和必须小于等于缓冲区大小size。 |
| uint32_t transferedLength | 实际传输的数据长度（单位：字节）。 |


