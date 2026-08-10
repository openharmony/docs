# ScsiPeripheral_IORequest
<!--Kit: Driver Development Kit-->
<!--Subsystem: Driver-->
<!--Owner: @zgene94-->
<!--Designer: @w00373942-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @hu-zhiqiong-->

```c
typedef struct ScsiPeripheral_IORequest {...} ScsiPeripheral_IORequest
```

## 概述

读/写操作的请求参数。该结构体定义了SCSI外设进行读/写操作时所需的请求参数，包括逻辑块起始地址、传输长度、控制信息等。

**起始版本：** 18

**相关模块：** [ScsiPeripheralDDK](capi-scsiperipheralddk.md)

**所在头文件：** [scsi_peripheral_types.h](capi-scsi-peripheral-types-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| uint32_t lbAddress | 逻辑块起始地址，用于指定SCSI外设读/写操作的起始逻辑块位置。 |
| uint16_t transferLength | 需要操作的连续逻辑块的数量，必须是正整数且不超过设备单次传输的最大逻辑块数限制。 |
| uint8_t control | Control字段，用于指定SCSI命令的控制标志，如优先级、链接命令等控制选项。 |
| uint8_t byte1 | SCSI命令描述符块（CDB）的第一个字节，通常包含操作码和操作组信息。 |
| uint8_t byte6 | SCSI命令描述符块（CDB）的第六个字节，根据命令类型包含不同的参数或标志信息。 |
| [ScsiPeripheral_DeviceMemMap](capi-scsiperipheralddk-scsiperipheral-devicememmap.md)* data | 数据传输的缓冲区。 |
| uint32_t timeout | 超时时间（单位：毫秒）。 |


