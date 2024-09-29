# GeofenceResult


## 概述

定义添加或删除地理围栏执行结果的数据结构。

**起始版本：** 4.0

**相关模块：**[HdiLpfenceGeofence](_hdi_lpfence_geofence.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [geofenceId](#geofenceid) | 地理围栏的ID号。 | 
| int [result](#result) | 返回值。0表示操作成功，负数表示操作失败。 | 


## 类成员变量说明


### geofenceId

```
int GeofenceResult::geofenceId
```

**描述**


地理围栏的ID号。


### result

```
int GeofenceResult::result
```

**描述**


返回值。0表示操作成功，负数表示操作失败。
