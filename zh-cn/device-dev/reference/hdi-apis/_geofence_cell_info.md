# GeofenceCellInfo


## 概述

定义设备驻留的基站小区信息的数据结构。

**Since:**

4.0

**相关模块:**

[HdiLpfenceGeofence](_hdi_lpfence_geofence.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [cell](#cell) | struct&nbsp;[CurrentCell](_current_cell.md)<br/>设备驻留的基站主区信息。详见[CurrentCell](_current_cell.md)。 | 
| [neighborCells](#neighborcells) | struct&nbsp;[NeighborCell](_neighbor_cell.md)[]<br/>设备驻留的基站邻区信息。详见[NeighborCell](_neighbor_cell.md)。 | 


## 类成员变量说明


### cell

  
```
struct CurrentCell GeofenceCellInfo::cell
```

**描述:**

设备驻留的基站主区信息。详见[CurrentCell](_current_cell.md)。


### neighborCells

  
```
struct NeighborCell [] GeofenceCellInfo::neighborCells
```

**描述:**

设备驻留的基站邻区信息。详见[NeighborCell](_neighbor_cell.md)。
