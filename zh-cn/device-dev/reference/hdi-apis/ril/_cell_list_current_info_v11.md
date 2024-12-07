# CellListCurrentInfo


## 概述

当前小区信息列表。

**起始版本：** 3.2

**相关模块：**[Ril](_ril_v11.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [itemNum](#itemnum) | 小区信息数量  | 
| List&lt; struct [CurrentCellInfo](_current_cell_info_v11.md) &gt; [cellCurrentInfo](#cellcurrentinfo) | 当前小区信息  | 


## 类成员变量说明


### cellCurrentInfo

```
List<struct CurrentCellInfo> CellListCurrentInfo::cellCurrentInfo
```
**描述**

当前小区信息


### itemNum

```
int CellListCurrentInfo::itemNum
```
**描述**

小区信息数量
