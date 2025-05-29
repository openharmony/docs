# ScsiPeripheral_IORequest


## 概述

读/写操作的请求参数。

**起始版本：** 18

**相关模块：**[SCSI Peripheral DDK](_s_c_s_i.md)

**所在头文件：** [scsi_peripheral_types.h](scsi__peripheral__types_8h.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| uint32_t [lbAddress](#lbaddress) | 逻辑块起始地址。 | 
| uint16_t [transferLength](#transferlength) | 需要操作的连续逻辑块的数量。 | 
| uint8_t [control](#control) | Control字段，用于指定一些控制信息。 | 
| uint8_t [byte1](#byte1) | CDB的第一个字节。 | 
| uint8_t [byte6](#byte6) | CDB的第六个字节。 | 
| [ScsiPeripheral_DeviceMemMap](_scsi_peripheral___device_mem_map.md) \* [data](#data) | 数据传输的缓冲区。 | 
| uint32_t [timeout](#timeout) | 超时时间（单位：毫秒）。 | 


## 结构体成员变量说明


### byte1

```
uint8_t ScsiPeripheral_IORequest::byte1
```

**描述**

CDB的第一个字节。


### byte6

```
uint8_t ScsiPeripheral_IORequest::byte6
```

**描述**

CDB的第六个字节。


### control

```
uint8_t ScsiPeripheral_IORequest::control
```

**描述**

Control字段，用于指定一些控制信息。


### data

```
ScsiPeripheral_DeviceMemMap* ScsiPeripheral_IORequest::data
```

**描述**

数据传输的缓冲区。


### lbAddress

```
uint32_t ScsiPeripheral_IORequest::lbAddress
```

**描述**

逻辑块起始地址。


### timeout

```
uint32_t ScsiPeripheral_IORequest::timeout
```

**描述**

超时时间（单位：毫秒）。


### transferLength

```
uint16_t ScsiPeripheral_IORequest::transferLength
```

**描述**

需要操作的连续逻辑块的数量。
