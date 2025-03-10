# ScsiPeripheral_TestUnitReadyRequest


## 概述

命令（test unit ready）的请求结构体。

**起始版本：** 18

**相关模块：**[SCSI Peripheral DDK](_s_c_s_i.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| uint8_t [control](#control) | Control字段，用于指定一些控制信息。 | 
| uint32_t [timeout](#timeout) | 超时时间（单位：毫秒）。 | 


## 结构体成员变量说明


### control

```
uint8_t ScsiPeripheral_TestUnitReadyRequest::control
```

**描述**

Control字段，用于指定一些控制信息。


### timeout

```
uint32_t ScsiPeripheral_TestUnitReadyRequest::timeout
```

**描述**

超时时间（单位：毫秒）。
