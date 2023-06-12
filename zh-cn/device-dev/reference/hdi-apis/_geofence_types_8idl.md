# GeofenceTypes.idl


## 概述

定义地理围栏使用的数据类型。

**Since:**

4.0

**Version:**

1.0

**相关模块:**

[HdiLpfenceGeofence](_hdi_lpfence_geofence.md)


## 汇总


### 类

  | 名称 | 描述 | 
| -------- | -------- |
| [Point](_point.md) | struct<br/>定义位置坐标的数据结构。 | 
| [GeofenceCircleRequest](_geofence_circle_request.md) | struct<br/>定义添加圆形地理围栏的数据结构。 | 
| [GeofencePolygonRequest](_geofence_polygon_request.md) | struct<br/>定义添加多边形地理围栏的数据结构。 | 
| [GeofenceResult](_geofence_result.md) | struct<br/>定义添加或删除地理围栏执行结果的数据结构。 | 
| [OfflineDb](_offline_db.md) | struct<br/>定义下发基站离线数据库的数据结构。 | 
| [GeoLocationInfo](_geo_location_info.md) | struct<br/>定义设备具体位置信息的数据结构。 | 
| [GeofenceSize](_geofence_size.md) | struct<br/>定义地理围栏使用信息的数据结构。 | 
| [CurrentCell](_current_cell.md) | struct<br/>定义设备驻留的基站主区信息的数据结构。 | 
| [NeighborCell](_neighbor_cell.md) | struct<br/>定义设备驻留的基站邻区信息的数据结构。 | 
| [GeofenceCellInfo](_geofence_cell_info.md) | struct<br/>定义设备驻留的基站小区信息的数据结构。 | 
| [RequestCellDb](_request_cell_db.md) | struct<br/>定义请求基站离线数据库数据的数据结构。 | 


### 枚举

  | 名称 | 描述 | 
| -------- | -------- |
| [GeofenceTransition](_hdi_lpfence_geofence.md#geofencetransition)&nbsp;{<br/>GEOFENCE_TRANSITION_ENTERED&nbsp;=&nbsp;(1&nbsp;&lt;&lt;&nbsp;0)&nbsp;,&nbsp;GEOFENCE_TRANSITION_EXITED&nbsp;=&nbsp;(1&nbsp;&lt;&lt;&nbsp;1)&nbsp;,&nbsp;GEOFENCE_TRANSITION_UNCERTAIN&nbsp;=&nbsp;(1&nbsp;&lt;&lt;&nbsp;2)&nbsp;,&nbsp;GEOFENCE_TRANSITION_DWELL&nbsp;=&nbsp;(1&nbsp;&lt;&lt;&nbsp;3)&nbsp;,<br/>GEOFENCE_TRANSITION_INDOOR&nbsp;=&nbsp;(1&nbsp;&lt;&lt;&nbsp;4)&nbsp;,&nbsp;GEOFENCE_TRANSITION_OUTDOOR&nbsp;=&nbsp;(1&nbsp;&lt;&lt;&nbsp;5)<br/>} | 枚举可关注的地理围栏状态事件。 | 
| [GeofenceAttribute](_hdi_lpfence_geofence.md#geofenceattribute)&nbsp;{&nbsp;GEOFENCE_ATTRI_COORDINATE_WGS84&nbsp;=&nbsp;16&nbsp;} | 枚举地理围栏支持的设置项。 | 
| [GeofenceAccuracy](_hdi_lpfence_geofence.md#geofenceaccuracy)&nbsp;{&nbsp;ACCURACY_FINE&nbsp;=&nbsp;1&nbsp;,&nbsp;ACCURACY_BALANCE&nbsp;=&nbsp;2&nbsp;,&nbsp;ACCURACY_COARSE&nbsp;=&nbsp;3&nbsp;} | 枚举地理围栏支持的精度模式。 | 
| [GeofenceCellType](_hdi_lpfence_geofence.md#geofencecelltype)&nbsp;{&nbsp;GEOFENCE_CELL_G4&nbsp;=&nbsp;0&nbsp;,&nbsp;GEOFENCE_CELL_NR&nbsp;=&nbsp;1&nbsp;} | 枚举移动通信技术代。 | 
| [GeofenceLocSource](_hdi_lpfence_geofence.md#geofencelocsource)&nbsp;{<br/>GEOFENCE_GNSS&nbsp;=&nbsp;1&nbsp;,&nbsp;GEOFENCE_WIFI&nbsp;=&nbsp;2&nbsp;,&nbsp;GEOFENCE_SENSOR&nbsp;=&nbsp;4&nbsp;,&nbsp;GEOFENCE_CELL&nbsp;=&nbsp;8&nbsp;,<br/>GEOFENCE_BT&nbsp;=&nbsp;16<br/>} | 枚举位置信息来源。 | 


### 关键字

  | 名称 | 描述 | 
| -------- | -------- |
| package&nbsp;ohos.hdi.location.lpfence.geofence.v1_0 | 地理围栏模块接口的包路径。 | 
