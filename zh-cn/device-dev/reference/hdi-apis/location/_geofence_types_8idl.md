# GeofenceTypes.idl


## 概述

定义地理围栏模块接口使用到的数据结构。

模块包路径：ohos.hdi.location.geofence.v1_0

**起始版本：** 3.2

**相关模块：**[HdiGeofence](_hdi_geofence.md)


## 汇总


### 类

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[GeofenceInfo](_geofence_info.md) | 定义地理围栏的参数。 | 
| struct&nbsp;&nbsp;[LocationInfo](_location_info.md) | 定义位置信息结构体。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [GeofenceEvent](_hdi_geofence.md#geofenceevent) { GEOFENCE_EVENT_UNCERTAIN = 1 , GEOFENCE_EVENT_ENTERED = 2 , GEOFENCE_EVENT_EXITED = 4 } | 定义监控的地理围栏事件类型。 | 
| [GeofenceOperateResult](_hdi_geofence.md#geofenceoperateresult) {<br/>OPERATION_SUCCESS = 0 , OPERATION_ERROR_UNKNOWN = -100 , OPERATION_ERROR_TOO_MANY_GEOFENCES = -101 , OPERATION_ERROR_GEOFENCE_INDEX_EXISTS = -102 , OPERATION_ERROR_PARAMS_INVALID = -103<br/>} | 定义地理围栏操作的错误码。 | 
| [GeofenceOperateType](_hdi_geofence.md#geofenceoperatetype) { TYPE_ADD = 1 , TYPE_DELETE = 2 } | 定义地理围栏的操作类型。 | 
