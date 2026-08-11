# ScsiPeripheral_DeviceMemMap
<!--Kit: Driver Development Kit-->
<!--Subsystem: Driver-->
<!--Owner: @zgene94-->
<!--Designer: @w00373942-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @hu-zhiqiong-->

```c
typedef struct ScsiPeripheral_DeviceMemMap {...} ScsiPeripheral_DeviceMemMap
```

## 概述

通过调用[OH_ScsiPeripheral_CreateDeviceMemMap](capi-scsi-peripheral-api-h.md#oh_scsiperipheral_createdevicememmap)创建的设备内存映射。使用该设备内存映射的缓冲区可以提供更好的性能。

**起始版本：** 18

**相关模块：** [ScsiPeripheralDDK](capi-scsiperipheralddk.md)

**所在头文件：** [scsi_peripheral_types.h](capi-scsi-peripheral-types-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| uint8_t* const address | 设备内存映射的缓冲区起始地址，指向映射的设备内存空间。该缓冲区用于存储SCSI设备数据，提供高性能的内存访问能力。 |
| const size_t size | 缓冲区大小，单位：字节。取值原则：必须大于0。 |
| uint32_t offset | 缓冲区读写起始偏移量，单位：字节。默认值为0，表示没有偏移，缓冲区从指定地址开始。取值范围为[0, size]，当需要从缓冲区特定位置开始读写时设置此参数，不同的offset值对应不同的起始读写位置。 |
| uint32_t bufferLength | 要使用的缓冲区长度，单位：字节。默认情况下，该值等于缓冲区的大小，表示整个缓冲区都被使用。当只使用缓冲区的一部分时设置此参数，bufferLength加offset的值应小于等于size。 |
| uint32_t transferredLength | 已传输数据的长度，单位：字节。初始值为0，表示尚未传输任何数据。该字段在SCSI数据传输完成后更新，表示实际传输的数据量，可用于监控传输进度。 |


