# ScsiPeripheral_CapacityInfo
<!--Kit: Driver Development Kit-->
<!--Subsystem: Driver-->
<!--Owner: @zgene94-->
<!--Designer: @w00373942-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @hu-zhiqiong-->

```c
typedef struct ScsiPeripheral_CapacityInfo {...} ScsiPeripheral_CapacityInfo
```

## 概述

SCSI READ CAPACITY结构体。用于在开发SCSI设备驱动时获取设备的存储容量信息，支持进行分区管理、可用空间检查和存储资源分配等操作。

**起始版本：** 18

**相关模块：** [ScsiPeripheralDDK](capi-scsiperipheralddk.md)

**所在头文件：** [scsi_peripheral_types.h](capi-scsi-peripheral-types-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| uint32_t lbAddress | 返回的逻辑块地址，表示可寻址的最后一块逻辑块的编号，逻辑块总数为该值加1。 |
| uint32_t lbLength | 单个逻辑块长度（单位：字节）。表示每个逻辑块的字节大小，通常为512、2048或4096等标准值，具体取决于设备类型和格式化方式。 |


