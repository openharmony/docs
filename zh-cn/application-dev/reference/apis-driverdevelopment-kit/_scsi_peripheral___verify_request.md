# ScsiPeripheral_VerifyRequest


## 概述

SCSI命令（verify）的请求结构体。

**起始版本：** 18

**相关模块：**[SCSI Peripheral DDK](_s_c_s_i.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| uint32_t [lbAddress](#lbaddress) | 起始逻辑块地址。 | 
| uint16_t [verificationLength](#verificationlength) | 连续校验逻辑块的个数。 | 
| uint8_t [control](#control) | Control字段，用于指定一些控制信息。 | 
| uint8_t [byte1](#byte1) | CDB的第一个字节。 | 
| uint8_t [byte6](#byte6) | CDB的第六个字节。 | 
| uint32_t [timeout](#timeout) | 超时时间（单位：毫秒）。 | 


## 结构体成员变量说明


### byte1

```
uint8_t ScsiPeripheral_VerifyRequest::byte1
```

**描述**

CDB的第一个字节。


### byte6

```
uint8_t ScsiPeripheral_VerifyRequest::byte6
```

**描述**

CDB的第六个字节。


### control

```
uint8_t ScsiPeripheral_VerifyRequest::control
```

**描述**

Control字段，用于指定一些控制信息。


### lbAddress

```
uint32_t ScsiPeripheral_VerifyRequest::lbAddress
```

**描述**

起始逻辑块地址。


### timeout

```
uint32_t ScsiPeripheral_VerifyRequest::timeout
```

**描述**

超时时间（单位：毫秒）。


### verificationLength

```
uint16_t ScsiPeripheral_VerifyRequest::verificationLength
```

**描述**

连续校验逻辑块的个数。
