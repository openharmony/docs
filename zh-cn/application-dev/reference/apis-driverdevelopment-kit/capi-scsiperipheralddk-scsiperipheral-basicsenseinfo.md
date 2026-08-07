# ScsiPeripheral_BasicSenseInfo
<!--Kit: Driver Development Kit-->
<!--Subsystem: Driver-->
<!--Owner: @zgene94-->
<!--Designer: @w00373942-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @hu-zhiqiong-->

```c
typedef struct ScsiPeripheral_BasicSenseInfo {...} ScsiPeripheral_BasicSenseInfo
```

## 概述

SCSI Sense Data的基本信息结构体，用于封装SCSI命令执行后返回的sense数据。该结构体包含响应码、状态标志位以及各类信息字段，用于驱动程序获取和分析SCSI设备的错误状态和命令执行结果。

**起始版本：** 18

**相关模块：** [ScsiPeripheralDDK](capi-scsiperipheralddk.md)

**所在头文件：** [scsi_peripheral_types.h](capi-scsi-peripheral-types-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| uint8_t responseCode | 响应码。由驱动层在收到Sense Data时自动设置。 |
| bool valid | 信息有效标志位。为true时表示information和commandSpecific字段有效，为false时这些字段应被忽略。使用前应先检查此标志位以避免读取无效数据。 |
| uint64_t information | Information字段，取值遵循SCSI标准协议。 |
| uint64_t commandSpecific | Command-specific information字段，取值遵循SCSI标准协议。 |
| bool sksv | Sense key specific字段的标志位。当为true时，表示senseKeySpecific字段有效，包含sense key specific data；为false时应忽略senseKeySpecific字段。使用前应先检查此标志位以避免读取无效数据。 |
| uint32_t senseKeySpecific | Sense key specific字段，取值遵循SCSI标准协议。 |


