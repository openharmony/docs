# ScsiPeripheral_RequestSenseRequest
<!--Kit: Driver Development Kit-->
<!--Subsystem: Driver-->
<!--Owner: @zgene94-->
<!--Designer: @w00373942-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @hu-zhiqiong-->

```c
typedef struct ScsiPeripheral_RequestSenseRequest {...} ScsiPeripheral_RequestSenseRequest
```

## 概述

SCSI命令（REQUEST SENSE）的请求结构体，该命令通常用于获取设备的错误信息。

**起始版本：** 18

**相关模块：** [ScsiPeripheralDDK](capi-scsiperipheralddk.md)

**所在头文件：** [scsi_peripheral_types.h](capi-scsi-peripheral-types-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| uint8_t allocationLength | Allocation length字段，指定了请求发起者（通常是主机）为响应数据准备的缓冲区大小，单位：字节。 |
| uint8_t control | Control字段，用于指定SCSI命令的控制信息。 |
| uint8_t byte1 | CDB（Command Descriptor Block，命令描述符块）的第一个字节。 |
| uint32_t timeout | 超时时间（单位：毫秒）。 |


