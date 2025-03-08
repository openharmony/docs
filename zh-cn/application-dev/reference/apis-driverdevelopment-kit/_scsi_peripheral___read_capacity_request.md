# ScsiPeripheral_ReadCapacityRequest


## 概述

SCSI命令（read capacity）的请求结构体。

**起始版本：** 18

**相关模块：**[SCSI Peripheral DDK](_s_c_s_i.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| uint32_t [lbAddress](#lbaddress) | 逻辑单元地址。 | 
| uint8_t [control](#control) | Control字段，用于指定一些控制信息。 | 
| uint8_t [byte8](#byte8) | CDB的第八个字节。 | 
| uint32_t [timeout](#timeout) | 超时时间（单位：毫秒）。 | 


## 结构体成员变量说明


### byte8

```
uint8_t ScsiPeripheral_ReadCapacityRequest::byte8
```

**描述**

CDB的第八个字节。


### control

```
uint8_t ScsiPeripheral_ReadCapacityRequest::control
```

**描述**

Control字段，用于指定一些控制信息。


### lbAddress

```
uint32_t ScsiPeripheral_ReadCapacityRequest::lbAddress
```

**描述**

逻辑单元地址。


### timeout

```
uint32_t ScsiPeripheral_ReadCapacityRequest::timeout
```

**描述**

超时时间（单位：毫秒）。
