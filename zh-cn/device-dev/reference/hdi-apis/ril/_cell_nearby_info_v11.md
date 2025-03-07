# CellNearbyInfo


## 概述

相邻小区信息。

**起始版本：** 3.2

**相关模块：**[Ril](_ril_v11.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [ratType](#rattype) | 接入技术类型 | 
| union [ServiceCellParas](union_service_cell_paras_v11.md)[serviceCells](#servicecells) | 多种网络模式的小区信息  | 


## 类成员变量说明


### ratType

```
int CellNearbyInfo::ratType
```
**描述**

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
**描述**

多种网络模式的小区信息
