# ScsiPeripheral_DeviceMemMap


## 概述

通过调用OH_ScsiPeripheral_CreateDeviceMemMap创建的设备内存映射。 使用该设备内存映射的缓冲区可以提供更好的性能。

**起始版本：** 18

**相关模块：**[SCSI Peripheral DDK](_s_c_s_i.md)

**所在头文件：** [scsi_peripheral_types.h](scsi__peripheral__types_8h.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| uint8_t \*const [address](#address) | 缓冲区地址。 | 
| const size_t [size](#size) | 缓冲区大小。 | 
| uint32_t [offset](#offset) | 已使用缓冲区的偏移量。默认值为0，表示没有偏移，缓冲区从指定地址开始。 | 
| uint32_t [bufferLength](#bufferlength) | 已使用缓冲区的长度。默认情况下，该值等于缓冲区的大小，表示整个缓冲区都被使用。 | 
| uint32_t [transferredLength](#transferredlength) | 传输数据的长度。 | 


## 结构体成员变量说明


### address

```
uint8_t* const ScsiPeripheral_DeviceMemMap::address
```

**描述**

缓冲区地址。


### bufferLength

```
uint32_t ScsiPeripheral_DeviceMemMap::bufferLength
```

**描述**

已使用缓冲区的长度。默认情况下，该值等于缓冲区的大小，表示整个缓冲区都被使用。


### offset

```
uint32_t ScsiPeripheral_DeviceMemMap::offset
```

**描述**

已使用缓冲区的偏移量。默认值为0，表示没有偏移，缓冲区从指定地址开始。


### size

```
const size_t ScsiPeripheral_DeviceMemMap::size
```

**描述**

缓冲区大小。


### transferredLength

```
uint32_t ScsiPeripheral_DeviceMemMap::transferredLength
```

**描述**

传输数据的长度。
