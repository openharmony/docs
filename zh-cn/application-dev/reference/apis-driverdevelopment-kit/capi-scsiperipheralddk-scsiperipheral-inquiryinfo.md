# ScsiPeripheral_InquiryInfo

## 概述

SCSI inquiry 数据。

**起始版本：** 18

**相关模块：** [SCSIPeripheralDDK](capi-scsiperipheralddk.md)

**所在头文件：** [scsi_peripheral_types.h](capi-scsi-peripheral-types-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| uint8_t deviceType | 设备类型。 |
| char idVendor | 制造商 id。 |
| char idProduct | 生产商 id。 |
| char revProduct | 产品版本。 |
| ScsiPeripheral_DeviceMemMap* data | 所有的查询数据。 |


