# ScsiPeripheral_CapacityInfo


## 概述

SCSI read capacity 数据。

**起始版本：** 18

**相关模块：**[SCSI Peripheral DDK](_s_c_s_i.md)

**所在头文件：** [scsi_peripheral_types.h](scsi__peripheral__types_8h.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| uint32_t [lbAddress](#lbaddress) | 返回的逻辑单元地址。 | 
| uint32_t [lbLength](#lblength) | 单个逻辑单元长度，单位：字节。 | 


## 结构体成员变量说明


### lbAddress

```
uint32_t ScsiPeripheral_CapacityInfo::lbAddress
```

**描述**

返回的逻辑单元地址。


### lbLength

```
uint32_t ScsiPeripheral_CapacityInfo::lbLength
```

**描述**

单个逻辑单元长度，单位：字节。
