# GeofenceCellInfo


## 概述

定义设备驻留的基站小区信息的数据结构。

**起始版本：** 4.0

**相关模块：**[HdiLpfenceGeofence](_hdi_lpfence_geofence.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| struct [CurrentCell](lpfence_current_cell.md)[cell](#cell) | 设备驻留的基站主区信息。详见[CurrentCell](lpfence_current_cell.md)。 | 
| struct [NeighborCell](lpfence_neighbor_cell.md)[] [neighborCells](#neighborcells) | 设备驻留的基站邻区信息。详见[NeighborCell](lpfence_neighbor_cell.md)。 | 


## 类成员变量说明


### cell

```
struct CurrentCell GeofenceCellInfo::cell
```

**描述**


设备驻留的基站主区信息。详见[CurrentCell](lpfence_current_cell.md)。


### neighborCells

```
struct NeighborCell [] GeofenceCellInfo::neighborCells
```

**描述**


设备驻留的基站邻区信息。详见[NeighborCell](lpfence_neighbor_cell.md)。
