# ScsiPeripheral_Request
<!--Kit: Driver Development Kit-->
<!--Subsystem: Driver-->
<!--Owner: @zgene94-->
<!--Designer: @w00373942-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @hu-zhiqiong-->

```c
typedef struct ScsiPeripheral_Request {...} ScsiPeripheral_Request
```

## 概述

SCSI请求参数结构体，用于构造与SCSI设备交互的请求参数，支持配置命令描述符块、数据缓冲区、超时时间等。

**起始版本：** 18

**相关模块：** [ScsiPeripheralDDK](capi-scsiperipheralddk.md)

**所在头文件：** [scsi_peripheral_types.h](capi-scsi-peripheral-types-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| uint8_t commandDescriptorBlock[[SCSIPERIPHERAL_MAX_CMD_DESC_BLOCK_LEN](capi-scsi-peripheral-types-h.md#scsiperipheral_max_cmd_desc_block_len)] | 命令描述符块，应遵循SCSI命令规范，填充对应命令的标准描述符格式。 |
| uint8_t cdbLength | 命令描述符块的长度，应确保长度和实际命令匹配，最大不超过[SCSIPERIPHERAL_MAX_CMD_DESC_BLOCK_LEN](capi-scsi-peripheral-types-h.md#scsiperipheral_max_cmd_desc_block_len)。 |
| int8_t dataTransferDirection | 数据传输方向：-1为无数据传输的命令，-2为从主机到设备的数据传输（写），-3为从设备到主机的数据传输（读），-4为双向数据传输。 |
| [ScsiPeripheral_DeviceMemMap](capi-scsiperipheralddk-scsiperipheral-devicememmap.md)* data | 数据传输缓冲区的指针。 |
| uint32_t timeout | 超时时间（单位：毫秒）。 |


