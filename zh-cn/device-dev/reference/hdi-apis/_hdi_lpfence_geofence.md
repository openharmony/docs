# HdiLpfenceGeofence


## 概述

为低功耗围栏服务提供地理围栏的API。

本模块接口提供添加圆形和多边形地理围栏，删除地理围栏，获取地理围栏状态信息，获取设备地理位置等功能。本模块可在AP休眠状态下持续工作。

应用场景：判断用户设备是否达到某个精确地理位置区域，从而进行一些后续服务，如门禁卡的切换、定制消息的提醒等。

**Since:**

4.0

**Version:**

1.0


## 汇总


### 文件

  | 名称 | 描述 | 
| -------- | -------- |
| [GeofenceTypes.idl](_geofence_types_8idl.md) | 定义地理围栏使用的数据类型。 | 
| [IGeofenceCallback.idl](_i_geofence_callback_8idl.md) | 定义地理围栏模块回调接口。 | 
| [IGeofenceIntf.idl](_i_geofence_intf_8idl.md) | 声明基站围栏模块提供的API，用于添加多种地理围栏，删除地理围栏，获取地理围栏状态信息，获取设备地理位置，下发基站离线数据库。 | 


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
| [IGeofenceCallback](interface_i_geofence_callback.md) | interface<br/>导入地理围栏模块的数据类型。 | 
| [IGeofenceInterface](interface_i_geofence_interface.md) | interface<br/>导入地理围栏模块的数据类型。 | 


### 枚举

  | 名称 | 描述 | 
| -------- | -------- |
| [GeofenceTransition](#geofencetransition)&nbsp;{<br/>GEOFENCE_TRANSITION_ENTERED&nbsp;=&nbsp;(1&nbsp;&lt;&lt;&nbsp;0)&nbsp;,&nbsp;GEOFENCE_TRANSITION_EXITED&nbsp;=&nbsp;(1&nbsp;&lt;&lt;&nbsp;1)&nbsp;,&nbsp;GEOFENCE_TRANSITION_UNCERTAIN&nbsp;=&nbsp;(1&nbsp;&lt;&lt;&nbsp;2)&nbsp;,&nbsp;GEOFENCE_TRANSITION_DWELL&nbsp;=&nbsp;(1&nbsp;&lt;&lt;&nbsp;3)&nbsp;,<br/>GEOFENCE_TRANSITION_INDOOR&nbsp;=&nbsp;(1&nbsp;&lt;&lt;&nbsp;4)&nbsp;,&nbsp;GEOFENCE_TRANSITION_OUTDOOR&nbsp;=&nbsp;(1&nbsp;&lt;&lt;&nbsp;5)<br/>} | 枚举可关注的地理围栏状态事件。 | 
| [GeofenceAttribute](#geofenceattribute)&nbsp;{&nbsp;GEOFENCE_ATTRI_COORDINATE_WGS84&nbsp;=&nbsp;16&nbsp;} | 枚举地理围栏支持的设置项。 | 
| [GeofenceAccuracy](#geofenceaccuracy)&nbsp;{&nbsp;ACCURACY_FINE&nbsp;=&nbsp;1&nbsp;,&nbsp;ACCURACY_BALANCE&nbsp;=&nbsp;2&nbsp;,&nbsp;ACCURACY_COARSE&nbsp;=&nbsp;3&nbsp;} | 枚举地理围栏支持的精度模式。 | 
| [GeofenceCellType](#geofencecelltype)&nbsp;{&nbsp;GEOFENCE_CELL_G4&nbsp;=&nbsp;0&nbsp;,&nbsp;GEOFENCE_CELL_NR&nbsp;=&nbsp;1&nbsp;} | 枚举移动通信技术代。 | 
| [GeofenceLocSource](#geofencelocsource)&nbsp;{<br/>GEOFENCE_GNSS&nbsp;=&nbsp;1&nbsp;,&nbsp;GEOFENCE_WIFI&nbsp;=&nbsp;2&nbsp;,&nbsp;GEOFENCE_SENSOR&nbsp;=&nbsp;4&nbsp;,&nbsp;GEOFENCE_CELL&nbsp;=&nbsp;8&nbsp;,<br/>GEOFENCE_BT&nbsp;=&nbsp;16<br/>} | 枚举位置信息来源。 | 


### 关键字

  | 名称 | 描述 | 
| -------- | -------- |
| package&nbsp;ohos.hdi.location.lpfence.geofence.v1_0 | 地理围栏模块接口的包路径。 | 


## 枚举类型说明


### GeofenceAccuracy

  
```
enum GeofenceAccuracy
```

**描述:**

枚举地理围栏支持的精度模式。

  | 枚举值 | 描述 | 
| -------- | -------- |
| ACCURACY_FINE | 高精度模式，GNSS模块接收GPS定位信号频率为1秒1次，功耗较高。 | 
| ACCURACY_BALANCE | 中精度模式，GNSS模块接收GPS定位信号频率为60秒1次，功耗较低。 | 
| ACCURACY_COARSE | 低精度模式，只使用基站定位，不依赖GNSS模块。 | 


### GeofenceAttribute

  
```
enum GeofenceAttribute
```

**描述:**

枚举地理围栏支持的设置项。

  | 枚举值 | 描述 | 
| -------- | -------- |
| GEOFENCE_ATTRI_COORDINATE_WGS84 | 地理位置使用WGS-84地心坐标系。 | 


### GeofenceCellType

  
```
enum GeofenceCellType
```

**描述:**

枚举移动通信技术代。

  | 枚举值 | 描述 | 
| -------- | -------- |
| GEOFENCE_CELL_G4 | 第2、3、4代移动通信技术 | 
| GEOFENCE_CELL_NR | 第5代移动通信技术 | 


### GeofenceLocSource

  
```
enum GeofenceLocSource
```

**描述:**

枚举位置信息来源。

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

**描述:**

枚举可关注的地理围栏状态事件。

  | 枚举值 | 描述 | 
| -------- | -------- |
| GEOFENCE_TRANSITION_ENTERED | 设备在地理围栏范围内。 | 
| GEOFENCE_TRANSITION_EXITED | 设备在地理围栏范围外。 | 
| GEOFENCE_TRANSITION_UNCERTAIN | 无法确定设备与地理围栏位置关系。 | 
| GEOFENCE_TRANSITION_DWELL | 设备在地理围栏内，且持续徘徊一段时间。 | 
| GEOFENCE_TRANSITION_INDOOR | 设备在地理围栏内，且在室内。 | 
| GEOFENCE_TRANSITION_OUTDOOR | 设备在地理围栏内，且在室外。 | 
