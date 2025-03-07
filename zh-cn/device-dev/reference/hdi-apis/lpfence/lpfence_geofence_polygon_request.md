# GeofencePolygonRequest


## 概述

定义添加多边形地理围栏的数据结构。

**起始版本：** 4.0

**相关模块：**[HdiLpfenceGeofence](_hdi_lpfence_geofence.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [geofenceId](#geofenceid) | 地理围栏的ID号，用于标识某个地理围栏，不可重复添加相同ID号的围栏。 | 
| struct [Point](lpfence_point.md)[] [points](#points) | 多边形地理围栏的边界坐标，仅支持凸多边形。详见[Point](lpfence_point.md)。 | 
| unsigned short [accuracy](#accuracy) | 多边形地理围栏的精度。详见[GeofenceAccuracy](_hdi_lpfence_geofence.md#geofenceaccuracy)。 | 
| unsigned int [loiterTimeMs](#loitertimems) | 徘徊时间，单位为毫秒，需关注[GEOFENCE_TRANSITION_DWELL](_hdi_lpfence_geofence.md)事件。若设备在多边形围栏内徘徊时间达到该值，则上报[GEOFENCE_TRANSITION_DWELL](_hdi_lpfence_geofence.md)事件。 | 
| unsigned char [monitorTransitions](#monitortransitions) | 关注的多边形围栏事件，若设备满足关注的事件则会进行上报。详见[GeofenceTransition](_hdi_lpfence_geofence.md#geofencetransition)。 | 
| unsigned int [attribute](#attribute) | 设置多边形地理围栏。详见[GeofenceAttribute](_hdi_lpfence_geofence.md#geofenceattribute)。 | 


## 类成员变量说明


### accuracy

```
unsigned short GeofencePolygonRequest::accuracy
```

**描述**


多边形地理围栏的精度。详见[GeofenceAccuracy](_hdi_lpfence_geofence.md#geofenceaccuracy)。


### attribute

```
unsigned int GeofencePolygonRequest::attribute
```

**描述**


设置多边形地理围栏。详见[GeofenceAttribute](_hdi_lpfence_geofence.md#geofenceattribute)。


### geofenceId

```
int GeofencePolygonRequest::geofenceId
```

**描述**


地理围栏的ID号，用于标识某个地理围栏，不可重复添加相同ID号的围栏。


### loiterTimeMs

```
unsigned int GeofencePolygonRequest::loiterTimeMs
```

**描述**


徘徊时间，单位为毫秒，需关注[GEOFENCE_TRANSITION_DWELL](_hdi_lpfence_geofence.md)事件。若设备在多边形围栏内徘徊时间达到该值，则上报[GEOFENCE_TRANSITION_DWELL](_hdi_lpfence_geofence.md)事件。


### monitorTransitions

```
unsigned char GeofencePolygonRequest::monitorTransitions
```

**描述**


关注的多边形围栏事件，若设备满足关注的事件则会进行上报。详见[GeofenceTransition](_hdi_lpfence_geofence.md#geofencetransition)。


### points

```
struct Point [] GeofencePolygonRequest::points
```

**描述**


多边形地理围栏的边界坐标，仅支持凸多边形。详见[Point](lpfence_point.md)。
