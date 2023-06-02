# CurrentCellInfo


## 概述

当前小区信息。

**相关模块:**

[Ril](_ril.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [ratType](#rattype) | int<br/>语音接入技术类型，具体查看[RilRadioTech](_ril.md#rilradiotech) | 
| [mcc](#mcc) | int<br/>移动国家码&nbsp; | 
| [mnc](#mnc) | int<br/>移动网络码&nbsp; | 
| [serviceCells](#servicecells) | union&nbsp;[CurrentServiceCellParas](union_current_service_cell_paras.md)<br/>小区信息参数，具体查看[CurrentServiceCellParas](union_current_service_cell_paras.md) | 


## 类成员变量说明


### mcc

  
```
int CurrentCellInfo::mcc
```
**描述:**
移动国家码


### mnc

  
```
int CurrentCellInfo::mnc
```
**描述:**
移动网络码


### ratType

  
```
int CurrentCellInfo::ratType
```
**描述:**
语音接入技术类型，具体查看[RilRadioTech](_ril.md#rilradiotech)


### serviceCells

  
```
union CurrentServiceCellParas CurrentCellInfo::serviceCells
```
**描述:**
小区信息参数，具体查看[CurrentServiceCellParas](union_current_service_cell_paras.md)
