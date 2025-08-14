# ScsiPeripheral_CapacityInfo
<!--Kit: Driver Development Kit-->
<!--Subsystem: Driver-->
<!--Owner: @lixinsheng2-->
<!--SE: @w00373942-->
<!--TSE: @dong-dongzhen-->

## 概述

SCSI read capacity 数据。

**起始版本：** 18

**相关模块：** [SCSIPeripheralDDK](capi-scsiperipheralddk.md)

**所在头文件：** [scsi_peripheral_types.h](capi-scsi-peripheral-types-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| uint32_t lbAddress | 返回的逻辑单元地址。 |
| uint32_t lbLength | 单个逻辑单元长度，单位：字节。 |


