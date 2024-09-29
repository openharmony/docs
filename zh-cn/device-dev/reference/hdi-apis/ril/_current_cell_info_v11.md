# CurrentCellInfo


## 概述

当前小区信息。

**起始版本：** 3.2

**相关模块：**[Ril](_ril_v11.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [ratType](#rattype) | 语音接入技术类型，具体查看[RilRadioTech](_ril_v11.md#rilradiotech) | 
| int [mcc](#mcc) | 移动国家码  | 
| int [mnc](#mnc) | 移动网络码  | 
| union [CurrentServiceCellParas](union_current_service_cell_paras_v11.md)[serviceCells](#servicecells) | 小区信息参数，具体查看[CurrentServiceCellParas](union_current_service_cell_paras_v11.md) | 


## 类成员变量说明


### mcc

```
int CurrentCellInfo::mcc
```
**描述**

移动国家码


### mnc

```
int CurrentCellInfo::mnc
```
**描述**

移动网络码


### ratType

```
int CurrentCellInfo::ratType
```
**描述**

语音接入技术类型，具体查看[RilRadioTech](_ril_v11.md#rilradiotech)


### serviceCells

```
union CurrentServiceCellParas CurrentCellInfo::serviceCells
```
**描述**

小区信息参数，具体查看[CurrentServiceCellParas](union_current_service_cell_paras_v11.md)
