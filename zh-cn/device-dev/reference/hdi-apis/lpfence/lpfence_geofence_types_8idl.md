# GeofenceTypes.idl


## 概述

定义地理围栏使用的数据类型。

模块包路径：ohos.hdi.location.lpfence.geofence.v1_0

**起始版本：** 4.0

**相关模块：**[HdiLpfenceGeofence](_hdi_lpfence_geofence.md)


## 汇总


### 类

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[Point](lpfence_point.md) | 定义位置坐标的数据结构。 | 
| struct&nbsp;&nbsp;[GeofenceCircleRequest](lpfence_geofence_circle_request.md) | 定义添加圆形地理围栏的数据结构。 | 
| struct&nbsp;&nbsp;[GeofencePolygonRequest](lpfence_geofence_polygon_request.md) | 定义添加多边形地理围栏的数据结构。 | 
| struct&nbsp;&nbsp;[GeofenceResult](lpfence_geofence_result.md) | 定义添加或删除地理围栏执行结果的数据结构。 | 
| struct&nbsp;&nbsp;[OfflineDb](lpfence_offline_db.md) | 定义下发基站离线数据库的数据结构。 | 
| struct&nbsp;&nbsp;[GeoLocationInfo](lpfence_geo_location_info.md) | 定义设备具体位置信息的数据结构。 | 
| struct&nbsp;&nbsp;[GeofenceSize](lpfence_geofence_size.md) | 定义地理围栏使用信息的数据结构。 | 
| struct&nbsp;&nbsp;[CurrentCell](lpfence_current_cell.md) | 定义设备驻留的基站主区信息的数据结构。 | 
| struct&nbsp;&nbsp;[NeighborCell](lpfence_neighbor_cell.md) | 定义设备驻留的基站邻区信息的数据结构。 | 
| struct&nbsp;&nbsp;[GeofenceCellInfo](lpfence_geofence_cell_info.md) | 定义设备驻留的基站小区信息的数据结构。 | 
| struct&nbsp;&nbsp;[RequestCellDb](lpfence_request_cell_db.md) | 定义请求基站离线数据库数据的数据结构。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [GeofenceTransition](_hdi_lpfence_geofence.md#geofencetransition) {<br/>GEOFENCE_TRANSITION_ENTERED = (1 &lt;&lt; 0) , GEOFENCE_TRANSITION_EXITED = (1 &lt;&lt; 1) , GEOFENCE_TRANSITION_UNCERTAIN = (1 &lt;&lt; 2) , GEOFENCE_TRANSITION_DWELL = (1 &lt;&lt; 3) , GEOFENCE_TRANSITION_INDOOR = (1 &lt;&lt; 4) , GEOFENCE_TRANSITION_OUTDOOR = (1 &lt;&lt; 5)<br/>} | 枚举可关注的地理围栏状态事件。 | 
| [GeofenceAttribute](_hdi_lpfence_geofence.md#geofenceattribute) { GEOFENCE_ATTRI_COORDINATE_WGS84 = 16 } | 枚举地理围栏支持的设置项。 | 
| [GeofenceAccuracy](_hdi_lpfence_geofence.md#geofenceaccuracy) { ACCURACY_FINE = 1 , ACCURACY_BALANCE = 2 , ACCURACY_COARSE = 3 } | 枚举地理围栏支持的精度模式。 | 
| [GeofenceCellType](_hdi_lpfence_geofence.md#geofencecelltype) { GEOFENCE_CELL_G4 = 0 , GEOFENCE_CELL_NR = 1 } | 枚举移动通信技术代。 | 
| [GeofenceLocSource](_hdi_lpfence_geofence.md#geofencelocsource) {<br/>GEOFENCE_GNSS = 1 , GEOFENCE_WIFI = 2 , GEOFENCE_SENSOR = 4 , GEOFENCE_CELL = 8 , GEOFENCE_BT = 16<br/>} | 枚举位置信息来源。 | 
