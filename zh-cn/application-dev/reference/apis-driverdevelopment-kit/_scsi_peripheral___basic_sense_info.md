# ScsiPeripheral_BasicSenseInfo


## 概述

sense data的基本信息。

**起始版本：** 18

**相关模块：**[SCSI Peripheral DDK](_s_c_s_i.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| uint8_t [responseCode](#responsecode) | 响应码。 | 
| bool [valid](#valid) | 信息有效标志位。 | 
| uint64_t [information](#information) | Information字段。 | 
| uint64_t [commandSpecific](#commandspecific) | Command-specific information字段。 | 
| bool [sksv](#sksv) | Sense key specific字段的标志位。 | 
| uint32_t [senseKeySpecific](#sensekeyspecific) | Sense key specific字段。 | 


## 结构体成员变量说明


### commandSpecific

```
uint64_t ScsiPeripheral_BasicSenseInfo::commandSpecific
```

**描述**

Command-specific information字段。


### information

```
uint64_t ScsiPeripheral_BasicSenseInfo::information
```

**描述**

Information字段。


### responseCode

```
uint8_t ScsiPeripheral_BasicSenseInfo::responseCode
```

**描述**

响应码。


### senseKeySpecific

```
uint32_t ScsiPeripheral_BasicSenseInfo::senseKeySpecific
```

**描述**

Sense key specific字段。


### sksv

```
bool ScsiPeripheral_BasicSenseInfo::sksv
```

**描述**

Sense key specific字段的标志位。


### valid

```
bool ScsiPeripheral_BasicSenseInfo::valid
```

**描述**

信息有效标志位。
