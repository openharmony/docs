# Telephony Data


## 概述

为电话蜂窝数据模块提供C接口。

**起始版本：** 13


## 汇总


### 文件

| 名称 | 描述 |
| -------- | -------- |
| [telephony_data.h](telephony__data_8h.md) | 为电话蜂窝数据定义C接口。<br>**引用文件：** \<telephony\/cellular_data\/telephony_data.h\> |

### 函数

| 名称 | 描述 |
| -------- | -------- |
| int32_t [OH_Telephony_GetDefaultCellularDataSlotId](#oh_telephony_getdefaultcellulardataslotid)(void) | 获取默认移动数据的SIM卡接口。 |

## 函数说明


### OH_Telephony_GetDefaultCellularDataSlotId()

```
int32_t OH_Telephony_GetDefaultCellularDataSlotId(void)
```

**描述**

获取默认移动数据的SIM卡接口。

**系统能力：** SystemCapability.Telephony.CellularData

**起始版本：** 13

**返回：**

0 - 卡槽1.

1- 卡槽2.