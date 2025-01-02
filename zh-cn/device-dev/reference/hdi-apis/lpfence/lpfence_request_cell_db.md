# RequestCellDb


## 概述

定义请求基站离线数据库数据的数据结构。

**起始版本：** 4.0

**相关模块：**[HdiLpfenceGeofence](_hdi_lpfence_geofence.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [requestSize](#requestsize) | 请求基站离线数据库的大小。 | 
| struct [GeoLocationInfo](lpfence_geo_location_info.md)[location](#location) | 设备最新的位置信息。详见[GeoLocationInfo](lpfence_geo_location_info.md)。 | 
| struct [GeofenceCellInfo](lpfence_geofence_cell_info.md)[] [cellInfo](#cellinfo) | 设备最新的基站数据信息。详见[GeofenceCellInfo](lpfence_geofence_cell_info.md)。 | 


## 类成员变量说明


### cellInfo

```
struct GeofenceCellInfo [] RequestCellDb::cellInfo
```

**描述**


设备最新的基站数据信息。详见[GeofenceCellInfo](lpfence_geofence_cell_info.md)。


### location

```
struct GeoLocationInfo RequestCellDb::location
```

**描述**


设备最新的位置信息。详见[GeoLocationInfo](lpfence_geo_location_info.md)。


### requestSize

```
int RequestCellDb::requestSize
```

**描述**


请求基站离线数据库的大小。
