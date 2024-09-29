# IGeofenceInterface


## 概述

定义接口用于添加围栏，删除围栏，设置围栏回调函数等。

**起始版本：** 3.2

**相关模块：**[HdiGeofence](_hdi_geofence.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [SetGeofenceCallback](#setgeofencecallback) ([in] [IGeofenceCallback](interface_i_geofence_callback.md) callbackObj) | 设置地理围栏回调函数。 | 
| [AddGnssGeofence](#addgnssgeofence) ([in] struct [GeofenceInfo](_geofence_info.md) fence, [in] enum GeofenceEvent monitorEvent) | 添加一个地理围栏。 | 
| [DeleteGnssGeofence](#deletegnssgeofence) ([in] int fenceIndex) | 删除一个地理围栏。 | 


## 成员函数说明


### AddGnssGeofence()

```
IGeofenceInterface::AddGnssGeofence ([in] struct GeofenceInfo fence, [in] enum GeofenceEvent monitorEvent )
```

**描述**


添加一个地理围栏。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| fence | 表示地理围栏的参数。详情参考[GeofenceInfo](_geofence_info.md)。 | 
| monitorEvent | 表示APP想要监控的地理围栏事件。详情参考[GeofenceEvent](_hdi_geofence.md#geofenceevent)。 | 

**返回：**

返回0表示成功，返回负数表示失败。


### DeleteGnssGeofence()

```
IGeofenceInterface::DeleteGnssGeofence ([in] int fenceIndex)
```

**描述**


删除一个地理围栏。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| fenceIndex | 表示地理围栏的编号。 | 

**返回：**

返回0表示成功，返回负数表示失败。


### SetGeofenceCallback()

```
IGeofenceInterface::SetGeofenceCallback ([in] IGeofenceCallback callbackObj)
```

**描述**


设置地理围栏回调函数。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| callback | 表示地理围栏的回调函数，GNSS驱动使用此回调上报地理围栏服务可用性， 上报地理围栏事件，上报地理围栏操作结果。详情参考[IGeofenceCallback](interface_i_geofence_callback.md)。 | 

**返回：**

返回0表示成功，返回负数表示失败。
