# ScsiPeripheral_Response
<!--Kit: Driver Development Kit-->
<!--Subsystem: Driver-->
<!--Owner: @zgene94-->
<!--Designer: @w00373942-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @hu-zhiqiong-->

```c
typedef struct ScsiPeripheral_Response {...} ScsiPeripheral_Response
```

## 概述

SCSI响应参数结构体，包含状态、错误诊断数据、传输结果等，用于接收SCSI设备响应数据、判断命令是否成功。

**起始版本：** 18

**相关模块：** [ScsiPeripheralDDK](capi-scsiperipheralddk.md)

**所在头文件：** [scsi_peripheral_types.h](capi-scsi-peripheral-types-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| uint8_t senseData[[SCSIPERIPHERAL_MAX_SENSE_DATA_LEN](capi-scsi-peripheral-types-h.md#scsiperipheral_max_sense_data_len)] | Sense Data，SCSI设备返回给主机的状态、错误及诊断信息。 |
| [ScsiPeripheral_Status](capi-scsi-peripheral-types-h.md#scsiperipheral_status) status | 调用完成时的状态。可能的值包括：SCSIPERIPHERAL_STATUS_GOOD（正常状态）、SCSIPERIPHERAL_STATUS_BUSY（占用中）等。 |
| uint8_t maskedStatus | 在SCSI通用驱动中，该字段用于存储经过处理后的SCSI状态。 |
| uint8_t msgStatus | 消息状态，表示SCSI命令执行完成后的消息结果。 |
| uint8_t sbLenWr | 实际写入到Sense Buffer（感知缓冲区）的有效字节数，用于确定senseData数组中有效数据的长度，若为0表示无Sense Data。 |
| uint16_t hostStatus | 主机适配器状态。例如：成功（0x00）、无法连接（0x01）、总线忙（0x02）、超时（0x03）。 |
| uint16_t driverStatus | 驱动状态。例如：成功（0x00）、设备或资源忙（0x01）。 |
| int32_t resId | 实际传输的数据长度差值，即未传输的字节数。 |
| uint32_t duration | 执行SCSI命令消耗的时间（单位：毫秒）。 |


