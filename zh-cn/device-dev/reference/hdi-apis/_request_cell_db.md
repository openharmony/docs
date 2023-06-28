# RequestCellDb


## 概述

定义请求基站离线数据库数据的数据结构。

**Since:**

4.0

**相关模块:**

[HdiLpfenceGeofence](_hdi_lpfence_geofence.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [requestSize](#requestsize) | int<br/>请求基站离线数据库的大小。 | 
| [location](#location) | struct&nbsp;[GeoLocationInfo](_geo_location_info.md)<br/>设备最新的位置信息。详见[GeoLocationInfo](_geo_location_info.md)。 | 
| [cellInfo](#cellinfo) | struct&nbsp;[GeofenceCellInfo](_geofence_cell_info.md)[]<br/>设备最新的基站数据信息。详见[GeofenceCellInfo](_geofence_cell_info.md)。 | 


## 类成员变量说明


### cellInfo

  
```
struct GeofenceCellInfo [] RequestCellDb::cellInfo
```

**描述:**

设备最新的基站数据信息。详见[GeofenceCellInfo](_geofence_cell_info.md)。


### location

  
```
struct GeoLocationInfo RequestCellDb::location
```

**描述:**

设备最新的位置信息。详见[GeoLocationInfo](_geo_location_info.md)。


### requestSize

  
```
int RequestCellDb::requestSize
```

**描述:**

请求基站离线数据库的大小。
