# IGeofenceCallback


## 概述

定义回调函数用于上报地理围栏服务是否可用、地理围栏事件、地理围栏操作结果等。

**起始版本：** 3.2

**相关模块：**[HdiGeofence](_hdi_geofence.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [ReportGeofenceAvailability](#reportgeofenceavailability) ([in] boolean isAvailable) | 上报地理围栏服务是否可用。 | 
| [ReportGeofenceEvent](#reportgeofenceevent) ([in] int fenceIndex, [in] struct [LocationInfo](_location_info.md) location, [in] enum GeofenceEvent event, [in] long timestamp) | 用于上报地理围栏事件。 | 
| [ReportGeofenceOperateResult](#reportgeofenceoperateresult) ([in] int fenceIndex, [in] enum GeofenceOperateType type, [in] enum GeofenceOperateResult result) | 上报围栏操作结果。 | 


## 成员函数说明


### ReportGeofenceAvailability()

```
IGeofenceCallback::ReportGeofenceAvailability ([in] boolean isAvailable)
```

**描述**


上报地理围栏服务是否可用。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| isAvailable | 表示地理围栏是否可用。 | 

**返回：**

返回0表示成功，返回负数表示失败。


### ReportGeofenceEvent()

```
IGeofenceCallback::ReportGeofenceEvent ([in] int fenceIndex, [in] struct LocationInfo location, [in] enum GeofenceEvent event, [in] long timestamp )
```

**描述**


用于上报地理围栏事件。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| fenceIndex | 表示地理围栏编号。 | 
| location | 表示当前的位置，详情参考[LocationInfo](_location_info.md)。 | 
| event | 表示当前发生的地理围栏事件，详情参考[GeofenceEvent](_hdi_geofence.md#geofenceevent)。 | 
| timestamp | 表示地理围栏事件发生的时刻。 | 

**返回：**

返回0表示成功，返回负数表示失败。


### ReportGeofenceOperateResult()

```
IGeofenceCallback::ReportGeofenceOperateResult ([in] int fenceIndex, [in] enum GeofenceOperateType type, [in] enum GeofenceOperateResult result )
```

**描述**


上报围栏操作结果。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| fenceIndex | 表示地理围栏编号。 | 
| type | 表示地理围栏操作类型，详情参考[GeofenceOperateType](_hdi_geofence.md#geofenceoperatetype)。 | 
| result | 表示地理围栏操作结果，详情参考[GeofenceOperateResult](_hdi_geofence.md#geofenceoperateresult)。 | 

**返回：**

返回0表示成功，返回负数表示失败。
