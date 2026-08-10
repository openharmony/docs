# ScsiPeripheral_VerifyRequest
<!--Kit: Driver Development Kit-->
<!--Subsystem: Driver-->
<!--Owner: @zgene94-->
<!--Designer: @w00373942-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @hu-zhiqiong-->

```c
typedef struct ScsiPeripheral_VerifyRequest {...} ScsiPeripheral_VerifyRequest
```

## 概述

SCSI命令（VERIFY）的请求结构体，该命令通常用于校验逻辑块的数据完整性。

**起始版本：** 18

**相关模块：** [ScsiPeripheralDDK](capi-scsiperipheralddk.md)

**所在头文件：** [scsi_peripheral_types.h](capi-scsi-peripheral-types-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| uint32_t lbAddress | 起始逻辑块地址。 |
| uint16_t verificationLength | 要校验的连续逻辑块的数量。 |
| uint8_t control | Control字段，用于指定SCSI命令的控制信息。 |
| uint8_t byte1 | CDB（Command Descriptor Block，命令描述符块）的第一个字节。 |
| uint8_t byte6 | CDB（Command Descriptor Block，命令描述符块）的第六个字节。 |
| uint32_t timeout | 超时时间（单位：毫秒）。 |


