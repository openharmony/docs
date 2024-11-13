# IGeofenceInterface


## 概述

定义对地理围栏模块进行基本操作的接口。

接口包含注册回调函数，取消注册回调函数，添加圆形和多边形地理围栏，删除地理围栏，获取地理围栏状态信息，获取设备地理位置，下发基站离线数据库。

**起始版本：** 4.0

**相关模块：**[HdiLpfenceGeofence](_hdi_lpfence_geofence.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [RegisterGeofenceCallback](#registergeofencecallback) ([in] [IGeofenceCallback](lpfence_interface_i_geofence_callback.md) callbackObj) | 注册回调函数。 | 
| [UnregisterGeofenceCallback](#unregistergeofencecallback) ([in] [IGeofenceCallback](lpfence_interface_i_geofence_callback.md) callbackObj) | 取消注册回调函数。 | 
| [AddCircleGeofences](#addcirclegeofences) ([in] struct [GeofenceCircleRequest](lpfence_geofence_circle_request.md)[] circleGeofences) | 添加圆形地理围栏。 | 
| [AddPolygonGeofences](#addpolygongeofences) ([in] struct [GeofencePolygonRequest](lpfence_geofence_polygon_request.md)[] polygonGeofences) | 添加多边形地理围栏。 | 
| [RemoveGeofences](#removegeofences) ([in] int[] geofenceId) | 删除地理围栏。 | 
| [GetGeofenceStatus](#getgeofencestatus) ([in] int geofenceId) | 获取当前设备与一个地理围栏的状态关系。 | 
| [GetGeofenceLocation](#getgeofencelocation) () | 获取最新的位置信息。 | 
| [GetGeofenceSize](#getgeofencesize) () | 获取地理围栏使用信息。 | 
| [SendCellOfflineDb](#sendcellofflinedb) ([in] struct [OfflineDb](lpfence_offline_db.md) dbData, [in] int cellType) | 下发基站离线数据库数据。 | 


## 成员函数说明


### AddCircleGeofences()

```
IGeofenceInterface::AddCircleGeofences ([in] struct GeofenceCircleRequest[] circleGeofences)
```

**描述**


添加圆形地理围栏。

支持一次添加多个圆形地理围栏

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| circleGeofences | 添加圆形围栏信息。详见[GeofenceCircleRequest](lpfence_geofence_circle_request.md)。 | 

**返回：**

如果添加成功，则返回0。

如果添加失败，则返回负值。


### AddPolygonGeofences()

```
IGeofenceInterface::AddPolygonGeofences ([in] struct GeofencePolygonRequest[] polygonGeofences)
```

**描述**


添加多边形地理围栏。

支持一次添加多个多边形地理围栏

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| polygonGeofences | 添加多边形围栏信息。详见[GeofencePolygonRequest](lpfence_geofence_polygon_request.md)。 | 

**返回：**

如果添加成功，则返回0。

如果添加失败，则返回负值。


### GetGeofenceLocation()

```
IGeofenceInterface::GetGeofenceLocation ()
```

**描述**


获取最新的位置信息。

位置信息通过回调函数上报。详见[OnGetCurrentLocation](lpfence_interface_i_geofence_callback.md#ongetcurrentlocation)定义。

**起始版本：** 4.0

**返回：**

如果调用成功，则返回0。

如果调用失败，则返回负值。


### GetGeofenceSize()

```
IGeofenceInterface::GetGeofenceSize ()
```

**描述**


获取地理围栏使用信息。

查看当前设备支持添加的地理围栏最大个数和已添加的地理围栏个数。通过回调函数上报通知，详见[OnGetGeofenceSizeCb](lpfence_interface_i_geofence_callback.md#ongetgeofencesizecb)。

**起始版本：** 4.0

**返回：**

如果调用成功，则返回0。

如果调用失败，则返回负值。


### GetGeofenceStatus()

```
IGeofenceInterface::GetGeofenceStatus ([in] int geofenceId)
```

**描述**


获取当前设备与一个地理围栏的状态关系。

设备与地理围栏的状态关系详见[GeofenceTransition](_hdi_lpfence_geofence.md#geofencetransition)定义。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| geofenceId | 地理围栏id号。 | 

**返回：**

返回位置关系。详见[GeofenceTransition](_hdi_lpfence_geofence.md#geofencetransition)定义。

如果调用失败，则返回负值。


### RegisterGeofenceCallback()

```
IGeofenceInterface::RegisterGeofenceCallback ([in] IGeofenceCallback callbackObj)
```

**描述**


注册回调函数。

用户在开启地理围栏功能前，需要先注册该回调函数。当地理围栏状态发生变化时，会通过回调函数进行上报。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| callbackObj | 要注册的回调函数，只需成功订阅一次，无需重复订阅。详见[IGeofenceCallback](lpfence_interface_i_geofence_callback.md)。 | 

**返回：**

如果注册回调函数成功，则返回0。

如果注册回调函数失败，则返回负值。


### RemoveGeofences()

```
IGeofenceInterface::RemoveGeofences ([in] int[] geofenceId)
```

**描述**


删除地理围栏。

支持一次删除多个地理围栏。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| geofenceId | 地理围栏id号。详见[GeofenceCircleRequest](lpfence_geofence_circle_request.md)和[GeofencePolygonRequest](lpfence_geofence_polygon_request.md)。 | 

**返回：**

如果删除成功，则返回0。

如果删除失败，则返回负值。


### SendCellOfflineDb()

```
IGeofenceInterface::SendCellOfflineDb ([in] struct OfflineDb dbData, [in] int cellType )
```

**描述**


下发基站离线数据库数据。

若请求离线数据库数据成功，则上层服务通过该接口将数据下发。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dbData | 基站离线数据库数据。详见[OfflineDb](lpfence_offline_db.md)定义。 | 
| cellType | 基站主区的移动通信技术代。详见[GeofenceCellType](_hdi_lpfence_geofence.md#geofencecelltype)定义。 | 

**返回：**

如果调用成功，则返回0。

如果调用失败，则返回负值。


### UnregisterGeofenceCallback()

```
IGeofenceInterface::UnregisterGeofenceCallback ([in] IGeofenceCallback callbackObj)
```

**描述**


取消注册回调函数。

取消之前注册的回调函数。当不需要使用地理围栏功能，或需要更换回调函数时，需要取消注册回调函数。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| callbackObj | 要取消注册的回调函数，只需成功取消订阅一次，无需重复取消订阅。详见[IGeofenceCallback](lpfence_interface_i_geofence_callback.md)。 | 

**返回：**

如果取消注册回调函数成功，则返回0。

如果取消注册回调函数失败，则返回负值。
