# ScsiPeripheral_BasicSenseInfo
<!--Kit: Driver Development Kit-->
<!--Subsystem: Driver-->
<!--Owner: @lixinsheng2-->
<!--SE: @w00373942-->
<!--TSE: @dong-dongzhen-->

## 概述

sense data的基本信息。

**起始版本：** 18

**相关模块：** [SCSIPeripheralDDK](capi-scsiperipheralddk.md)

**所在头文件：** [scsi_peripheral_types.h](capi-scsi-peripheral-types-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| uint8_t responseCode | 响应码。 |
| bool valid | 信息有效标志位。 |
| uint64_t information | Information字段。 |
| uint64_t commandSpecific | Command-specific information字段。 |
| bool sksv | Sense key specific字段的标志位。 |
| uint32_t senseKeySpecific | Sense key specific字段。 |


