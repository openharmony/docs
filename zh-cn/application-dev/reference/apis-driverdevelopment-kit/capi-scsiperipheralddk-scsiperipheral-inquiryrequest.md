# ScsiPeripheral_InquiryRequest
<!--Kit: Driver Development Kit-->
<!--Subsystem: Driver-->
<!--Owner: @zgene94-->
<!--Designer: @w00373942-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @hu-zhiqiong-->

```c
typedef struct ScsiPeripheral_InquiryRequest {...} ScsiPeripheral_InquiryRequest
```

## 概述

SCSI命令（INQUIRY）的请求结构体，通常用于查询设备的基本信息。

**起始版本：** 18

**相关模块：** [ScsiPeripheralDDK](capi-scsiperipheralddk.md)

**所在头文件：** [scsi_peripheral_types.h](capi-scsi-peripheral-types-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| uint8_t pageCode | Page code字段。获取设备的某些特定类型的信息时使用。当发出带有特定页面代码的 Inquiry 命令时，设备会返回与该页面代码相关的详细信息。如果 page code 设置为 0x00，则表示请求的是标准的 Inquiry 数据，而非特定页面的数据。 |
| uint16_t allocationLength | Allocation length字段，用于指定请求发起者（通常是主机）为响应数据准备的缓冲区大小。单位：字节。 |
| uint8_t control | Control字段，用于指定SCSI命令的控制信息。 |
| uint8_t byte1 | CDB（Command Descriptor Block，命令描述符块）的第一个字节。 |
| uint32_t timeout | 超时时间（单位：毫秒）。 |


