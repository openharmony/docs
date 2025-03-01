# ScsiPeripheral_InquiryRequest


## 概述

SCSI命令（inquiry）的请求结构体。

**起始版本：** 16

**相关模块：**[SCSI Peripheral DDK](_s_c_s_i.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| uint8_t [pageCode](#pagecode) | Page code字段。获取设备的某些特定类型的信息时使用。 当发出带有特定页面代码的 Inquiry 命令时，设备会返回与该页面代码相关的详细信息。 如果 page code 设置为 0x00，则表示请求的是标准的 Inquiry 数据，而非特定页面的数据。 | 
| uint16_t [allocationLength](#allocationlength) | Allocation length字段，指定了请求方向发起者（通常是主机）为响应数据准备的缓冲区大小。 | 
| uint8_t [control](#control) | Control字段，用于指定一些控制信息。 | 
| uint8_t [byte1](#byte1) | CDB的第一个字节。 | 
| uint32_t [timeout](#timeout) | 超时时间（单位：毫秒）。 | 


## 结构体成员变量说明


### allocationLength

```
uint16_t ScsiPeripheral_InquiryRequest::allocationLength
```

**描述**

Allocation length字段，指定了请求方向发起者（通常是主机）为响应数据准备的缓冲区大小。


### byte1

```
uint8_t ScsiPeripheral_InquiryRequest::byte1
```

**描述**

CDB的第一个字节。


### control

```
uint8_t ScsiPeripheral_InquiryRequest::control
```

**描述**

Control字段，用于指定一些控制信息。


### pageCode

```
uint8_t ScsiPeripheral_InquiryRequest::pageCode
```

**描述**

Page code字段。获取设备的某些特定类型的信息时使用。 当发出带有特定页面代码的 Inquiry 命令时，设备会返回与该页面代码相关的详细信息。 如果 page code 设置为 0x00，则表示请求的是标准的 Inquiry 数据，而非特定页面的数据。


### timeout

```
uint32_t ScsiPeripheral_InquiryRequest::timeout
```

**描述**

超时时间（单位：毫秒）。
