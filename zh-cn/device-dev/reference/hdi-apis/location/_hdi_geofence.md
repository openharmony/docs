# HdiGeofence


## 概述

定义GNSS地理围栏接口。

上层GNSS服务模块可以使用这个模块的接口来添加地理围栏，删除地理围栏，以及监视地理围栏状态的变化。

**起始版本：** 3.2


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [GeofenceTypes.idl](_geofence_types_8idl.md) | 定义地理围栏模块接口使用到的数据结构。 | 
| [IGeofenceCallback.idl](_i_geofence_callback_8idl.md) | 定义回调函数用于上报地理围栏服务是否可用、地理围栏事件、地理围栏操作结果等。 | 
| [IGeofenceInterface.idl](_i_geofence_interface_8idl.md) | 定义接口用于添加围栏，删除围栏，设置围栏回调函数等。 | 


### 类

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[GeofenceInfo](_geofence_info.md) | 定义地理围栏的参数。 | 
| struct&nbsp;&nbsp;[LocationInfo](_location_info.md) | 定义位置信息结构体。 | 
| interface&nbsp;&nbsp;[IGeofenceCallback](interface_i_geofence_callback.md) | 定义回调函数用于上报地理围栏服务是否可用、地理围栏事件、地理围栏操作结果等。 | 
| interface&nbsp;&nbsp;[IGeofenceInterface](interface_i_geofence_interface.md) | 定义接口用于添加围栏，删除围栏，设置围栏回调函数等。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [GeofenceEvent](#geofenceevent) { GEOFENCE_EVENT_UNCERTAIN = 1 , GEOFENCE_EVENT_ENTERED = 2 , GEOFENCE_EVENT_EXITED = 4 } | 定义监控的地理围栏事件类型。 | 
| [GeofenceOperateResult](#geofenceoperateresult) {<br/>OPERATION_SUCCESS = 0 , OPERATION_ERROR_UNKNOWN = -100 , OPERATION_ERROR_TOO_MANY_GEOFENCES = -101 , OPERATION_ERROR_GEOFENCE_INDEX_EXISTS = -102 , OPERATION_ERROR_PARAMS_INVALID = -103<br/>} | 定义地理围栏操作的错误码。 | 
| [GeofenceOperateType](#geofenceoperatetype) { TYPE_ADD = 1 , TYPE_DELETE = 2 } | 定义地理围栏的操作类型。 | 


## 枚举类型说明


### GeofenceEvent

```
enum GeofenceEvent
```

**描述**


定义监控的地理围栏事件类型。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| GEOFENCE_EVENT_UNCERTAIN | 状态不确定。 | 
| GEOFENCE_EVENT_ENTERED | 进入围栏。 | 
| GEOFENCE_EVENT_EXITED | 退出围栏。 | 


### GeofenceOperateResult

```
enum GeofenceOperateResult
```

**描述**


定义地理围栏操作的错误码。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| OPERATION_SUCCESS | 操作成功。 | 
| OPERATION_ERROR_UNKNOWN | 未知错误。 | 
| OPERATION_ERROR_TOO_MANY_GEOFENCES | 围栏个数超过限制。 | 
| OPERATION_ERROR_GEOFENCE_INDEX_EXISTS | 围栏ID重复。 | 
| OPERATION_ERROR_PARAMS_INVALID | 入参错误。 | 


### GeofenceOperateType

```
enum GeofenceOperateType
```

**描述**


定义地理围栏的操作类型。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| TYPE_ADD | 添加围栏。 | 
| TYPE_DELETE | 删除围栏。 | 
