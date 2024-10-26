# HdiLpfenceGeofence


## 概述

为低功耗围栏服务提供地理围栏的API。

本模块接口提供添加圆形和多边形地理围栏，删除地理围栏，获取地理围栏状态信息，获取设备地理位置等功能。本模块可在AP休眠状态下持续工作。 应用场景：判断用户设备是否达到某个精确地理位置区域，从而进行一些后续服务，如门禁卡的切换、定制消息的提醒等。

**起始版本：** 4.0


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [GeofenceTypes.idl](lpfence_geofence_types_8idl.md) | 定义地理围栏使用的数据类型。 | 
| [IGeofenceCallback.idl](lpfence_i_geofence_callback_8idl.md) | 定义地理围栏模块回调接口。 | 
| [IGeofenceIntf.idl](lpfence_i_geofence_intf_8idl.md) | 声明基站围栏模块提供的API，用于添加多种地理围栏，删除地理围栏，获取地理围栏状态信息，获取设备地理位置，下发基站离线数据库。 | 


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
| interface&nbsp;&nbsp;[IGeofenceCallback](lpfence_interface_i_geofence_callback.md) | 定义地理围栏模块的回调函数 | 
| interface&nbsp;&nbsp;[IGeofenceInterface](lpfence_interface_i_geofence_interface.md) | 定义对地理围栏模块进行基本操作的接口。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [GeofenceTransition](#geofencetransition) {<br/>GEOFENCE_TRANSITION_ENTERED = (1 &lt;&lt; 0) , GEOFENCE_TRANSITION_EXITED = (1 &lt;&lt; 1) , GEOFENCE_TRANSITION_UNCERTAIN = (1 &lt;&lt; 2) , GEOFENCE_TRANSITION_DWELL = (1 &lt;&lt; 3) , GEOFENCE_TRANSITION_INDOOR = (1 &lt;&lt; 4) , GEOFENCE_TRANSITION_OUTDOOR = (1 &lt;&lt; 5)<br/>} | 枚举可关注的地理围栏状态事件。 | 
| [GeofenceAttribute](#geofenceattribute) { GEOFENCE_ATTRI_COORDINATE_WGS84 = 16 } | 枚举地理围栏支持的设置项。 | 
| [GeofenceAccuracy](#geofenceaccuracy) { ACCURACY_FINE = 1 , ACCURACY_BALANCE = 2 , ACCURACY_COARSE = 3 } | 枚举地理围栏支持的精度模式。 | 
| [GeofenceCellType](#geofencecelltype) { GEOFENCE_CELL_G4 = 0 , GEOFENCE_CELL_NR = 1 } | 枚举移动通信技术代。 | 
| [GeofenceLocSource](#geofencelocsource) {<br/>GEOFENCE_GNSS = 1 , GEOFENCE_WIFI = 2 , GEOFENCE_SENSOR = 4 , GEOFENCE_CELL = 8 , GEOFENCE_BT = 16<br/>} | 枚举位置信息来源。 | 


## 枚举类型说明


### GeofenceAccuracy

```
enum GeofenceAccuracy
```

**描述**


枚举地理围栏支持的精度模式。

**起始版本：** 4.0

| 枚举值 | 描述 | 
| -------- | -------- |
| ACCURACY_FINE | 高精度模式，GNSS模块接收GPS定位信号频率为1秒1次，功耗较高。 | 
| ACCURACY_BALANCE | 中精度模式，GNSS模块接收GPS定位信号频率为60秒1次，功耗较低。 | 
| ACCURACY_COARSE | 低精度模式，只使用基站定位，不依赖GNSS模块。 | 


### GeofenceAttribute

```
enum GeofenceAttribute
```

**描述**


枚举地理围栏支持的设置项。

**起始版本：** 4.0

| 枚举值 | 描述 | 
| -------- | -------- |
| GEOFENCE_ATTRI_COORDINATE_WGS84 | 地理位置使用WGS-84地心坐标系。 | 


### GeofenceCellType

```
enum GeofenceCellType
```

**描述**


枚举移动通信技术代。

**起始版本：** 4.0

| 枚举值 | 描述 | 
| -------- | -------- |
| GEOFENCE_CELL_G4 | 第2、3、4代移动通信技术 | 
| GEOFENCE_CELL_NR | 第5代移动通信技术 | 


### GeofenceLocSource

```
enum GeofenceLocSource
```

**描述**


枚举位置信息来源。

**起始版本：** 4.0

| 枚举值 | 描述 | 
| -------- | -------- |
| GEOFENCE_GNSS | 位置信息来源于GNSS模块 | 
| GEOFENCE_WIFI | 位置信息来源于Wi-Fi模块 | 
| GEOFENCE_SENSOR | 位置信息来源于Sensor模块 | 
| GEOFENCE_CELL | 位置信息来源于基站模块 | 
| GEOFENCE_BT | 位置信息来源于蓝牙模块 | 


### GeofenceTransition

```
enum GeofenceTransition
```

**描述**


枚举可关注的地理围栏状态事件。

**起始版本：** 4.0

| 枚举值 | 描述 | 
| -------- | -------- |
| GEOFENCE_TRANSITION_ENTERED | 设备在地理围栏范围内。 | 
| GEOFENCE_TRANSITION_EXITED | 设备在地理围栏范围外。 | 
| GEOFENCE_TRANSITION_UNCERTAIN | 无法确定设备与地理围栏位置关系。 | 
| GEOFENCE_TRANSITION_DWELL | 设备在地理围栏内，且持续徘徊一段时间。 | 
| GEOFENCE_TRANSITION_INDOOR | 设备在地理围栏内，且在室内。 | 
| GEOFENCE_TRANSITION_OUTDOOR | 设备在地理围栏内，且在室外。 | 
