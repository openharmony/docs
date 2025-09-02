# ScsiPeripheral_ReadCapacityRequest
<!--Kit: Driver Development Kit-->
<!--Subsystem: Driver-->
<!--Owner: @lixinsheng2-->
<!--Designer: @w00373942-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @w_Machine_cc-->

## 概述

SCSI命令（read capacity）的请求结构体。

**起始版本：** 18

**相关模块：** [SCSIPeripheralDDK](capi-scsiperipheralddk.md)

**所在头文件：** [scsi_peripheral_types.h](capi-scsi-peripheral-types-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| uint32_t lbAddress | 逻辑单元地址。 |
| uint8_t control | Control字段，用于指定一些控制信息。 |
| uint8_t byte8 | CDB的第八个字节。 |
| uint32_t timeout | 超时时间(单位: 毫秒)。 |


