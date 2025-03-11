# ScsiPeripheral_RequestSenseRequest


## 概述

SCSI命令（request sense）的请求结构体。

**起始版本：** 18

**相关模块：**[SCSI Peripheral DDK](_s_c_s_i.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| uint8_t [allocationLength](#allocationlength) | Allocation length字段，指定了请求方向发起者（通常是主机）为响应数据准备的缓冲区大小。 | 
| uint8_t [control](#control) | Control字段，用于指定一些控制信息。 | 
| uint8_t [byte1](#byte1) | CDB的第一个字节。 | 
| uint32_t [timeout](#timeout) | 超时时间（单位：毫秒）。 | 


## 结构体成员变量说明


### allocationLength

```
uint8_t ScsiPeripheral_RequestSenseRequest::allocationLength
```

**描述**

Allocation length字段，指定了请求方向发起者（通常是主机）为响应数据准备的缓冲区大小。


### byte1

```
uint8_t ScsiPeripheral_RequestSenseRequest::byte1
```

**描述**

CDB的第一个字节。


### control

```
uint8_t ScsiPeripheral_RequestSenseRequest::control
```

**描述**

Control字段，用于指定一些控制信息。


### timeout

```
uint32_t ScsiPeripheral_RequestSenseRequest::timeout
```

**描述**

超时时间（单位：毫秒）。
