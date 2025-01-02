# IGeofenceCallback


## 概述

定义地理围栏模块的回调函数

用户在开启地理围栏功能前，需要先注册该回调函数。当地理围栏状态发生变化时，会通过回调函数进行上报。 详情可参考**ICellfenceInterface**。

**起始版本：** 4.0

**相关模块：**[HdiLpfenceGeofence](_hdi_lpfence_geofence.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [OnGeofenceAddResultCb](#ongeofenceaddresultcb) ([in] struct [GeofenceResult](lpfence_geofence_result.md)[] res) | 定义添加地理围栏结果的回调函数。 | 
| [OnGeofenceRemoveResultCb](#ongeofenceremoveresultcb) ([in] struct [GeofenceResult](lpfence_geofence_result.md)[] res) | 定义删除地理围栏结果的回调函数。 | 
| [OnGeofenceTransitionCb](#ongeofencetransitioncb) ([in] int geofenceId, [in] struct [GeoLocationInfo](lpfence_geo_location_info.md) location, [in] unsigned char transition, [in] long timeStamp) | 定义地理围栏状态变化的回调函数。 | 
| [OnGetGeofenceSizeCb](#ongetgeofencesizecb) ([in] struct [GeofenceSize](lpfence_geofence_size.md) size) | 定义地理围栏使用信息的回调函数。 | 
| [OnGeofenceRequestCellDb](#ongeofencerequestcelldb) ([in] struct [RequestCellDb](lpfence_request_cell_db.md) req) | 定义请求基站离线数据库的回调函数。 | 
| [OnGetCurrentLocation](#ongetcurrentlocation) ([in] int locSource, [in] struct [GeoLocationInfo](lpfence_geo_location_info.md) location) | 定义获取设备最新位置信息的回调函数。 | 
| [OnGeofenceReset](#ongeofencereset) () | 定义低功耗围栏服务复位事件通知的回调函数。 | 


## 成员函数说明


### OnGeofenceAddResultCb()

```
IGeofenceCallback::OnGeofenceAddResultCb ([in] struct GeofenceResult[] res)
```

**描述**


定义添加地理围栏结果的回调函数。

对每个地理围栏的添加结果，通过该回调函数进行上报。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| res | 上报地理围栏添加结果。详见[GeofenceResult](lpfence_geofence_result.md)定义。 | 

**返回：**

如果调用成功，则返回0。

如果调用失败，则返回负值。


### OnGeofenceRemoveResultCb()

```
IGeofenceCallback::OnGeofenceRemoveResultCb ([in] struct GeofenceResult[] res)
```

**描述**


定义删除地理围栏结果的回调函数。

对每个地理围栏的删除结果，通过该回调函数进行上报。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| res | 上报地理围栏删除结果。详见[GeofenceResult](lpfence_geofence_result.md)定义。 | 

**返回：**

如果调用成功，则返回0。

如果调用失败，则返回负值。


### OnGeofenceRequestCellDb()

```
IGeofenceCallback::OnGeofenceRequestCellDb ([in] struct RequestCellDb req)
```

**描述**


定义请求基站离线数据库的回调函数。

设备请求基站离线数据库时，会通过该回调函数进行上报。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| req | 请求基站离线数据库数据结构。详见[RequestCellDb](lpfence_request_cell_db.md)定义。 | 

**返回：**

如果调用成功，则返回0。

如果调用失败，则返回负值。


### OnGeofenceReset()

```
IGeofenceCallback::OnGeofenceReset ()
```

**描述**


定义低功耗围栏服务复位事件通知的回调函数。

低功耗围栏服务发生复位时会通过该回调函数进行事件上报。

**起始版本：** 4.0

**返回：**

如果回调函数调用成功，则返回0。

如果回调函数调用失败，则返回负值。


### OnGeofenceTransitionCb()

```
IGeofenceCallback::OnGeofenceTransitionCb ([in] int geofenceId, [in] struct GeoLocationInfo location, [in] unsigned char transition, [in] long timeStamp )
```

**描述**


定义地理围栏状态变化的回调函数。

设备与地理围栏的状态关系发生变化时，会通过该回调函数进行上报。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| geofenceId | 地理围栏id号。 | 
| location | 最新的位置坐标。详见[GeoLocationInfo](lpfence_geo_location_info.md)定义。 | 
| transition | 地理围栏变化的状态。详见[GeofenceTransition](_hdi_lpfence_geofence.md#geofencetransition)定义。 | 
| timeStamp | 时间戳。 | 

**返回：**

如果调用成功，则返回0。

如果调用失败，则返回负值。


### OnGetCurrentLocation()

```
IGeofenceCallback::OnGetCurrentLocation ([in] int locSource, [in] struct GeoLocationInfo location )
```

**描述**


定义获取设备最新位置信息的回调函数。

请求获取设备最新位置信息时，会通过该回调函数进行上报。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| locSource | 位置信息来源。详见[GeofenceLocSource](_hdi_lpfence_geofence.md#geofencelocsource)定义。 | 
| location | 最新位置信息。详见[GeoLocationInfo](lpfence_geo_location_info.md)定义。 | 

**返回：**

如果调用成功，则返回0。

如果调用失败，则返回负值。


### OnGetGeofenceSizeCb()

```
IGeofenceCallback::OnGetGeofenceSizeCb ([in] struct GeofenceSize size)
```

**描述**


定义地理围栏使用信息的回调函数。

获取地理围栏使用信息时，会通过该回调函数进行上报。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| size | 地理围栏使用信息。详见[GeofenceSize](lpfence_geofence_size.md)定义。 | 

**返回：**

如果调用成功，则返回0。

如果调用失败，则返回负值。
