# CellNearbyInfo


## 概述

相邻小区信息。

**相关模块:**

[Ril](_ril.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [ratType](#rattype) | int<br/>接入技术类型 | 
| [serviceCells](#servicecells) | union&nbsp;[ServiceCellParas](union_service_cell_paras.md)<br/>多种网络模式的小区信息&nbsp; | 


## 类成员变量说明


### ratType

  
```
int CellNearbyInfo::ratType
```
**描述:**
接入技术类型

- 0：未知

- 1：GSM

- 2：CDMA

- 3：WCDMA

- 4：TDSCDMA

- 5：LTE

- 6：NR 


### serviceCells

  
```
union ServiceCellParas CellNearbyInfo::serviceCells
```
**描述:**
多种网络模式的小区信息
