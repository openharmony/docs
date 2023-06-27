# GeofenceCircleRequest


## 概述

定义添加圆形地理围栏的数据结构。

**Since:**

4.0

**相关模块:**

[HdiLpfenceGeofence](_hdi_lpfence_geofence.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [geofenceId](#geofenceid) | int<br/>地理围栏的ID号，用于标识某个地理围栏，不可重复添加相同ID号的围栏。 | 
| [point](#point) | struct&nbsp;[Point](_point.md)<br/>圆形地理围栏的中心点坐标。详见[Point](_point.md)。 | 
| [radius](#radius) | double<br/>圆形地理围栏的半径，单位为米。 | 
| [accuracy](#accuracy) | unsigned&nbsp;short<br/>圆形地理围栏的精度。详见[GeofenceAccuracy](_hdi_lpfence_geofence.md#geofenceaccuracy)。 | 
| [loiterTimeMs](#loitertimems) | unsigned&nbsp;int<br/>徘徊时间，单位为毫秒，需关注[GEOFENCE_TRANSITION_DWELL](_hdi_lpfence_geofence.md#geofencetransition)事件。若设备在圆形围栏内徘徊时间达到该值，则上报[GEOFENCE_TRANSITION_DWELL](_hdi_lpfence_geofence.md#geofencetransition)事件。 | 
| [monitorTransitions](#monitortransitions) | unsigned&nbsp;char<br/>关注的圆形围栏事件，若设备满足关注的事件则会进行上报。详见[GeofenceTransition](_hdi_lpfence_geofence.md#geofencetransition)。 | 
| [attribute](#attribute) | unsigned&nbsp;int<br/>设置圆形地理围栏。详见[GeofenceAttribute](_hdi_lpfence_geofence.md#geofenceattribute)。 | 


## 类成员变量说明


### accuracy

  
```
unsigned short GeofenceCircleRequest::accuracy
```

**描述:**

圆形地理围栏的精度。详见[GeofenceAccuracy](_hdi_lpfence_geofence.md#geofenceaccuracy)。


### attribute

  
```
unsigned int GeofenceCircleRequest::attribute
```

**描述:**

设置圆形地理围栏。详见[GeofenceAttribute](_hdi_lpfence_geofence.md#geofenceattribute)。


### geofenceId

  
```
int GeofenceCircleRequest::geofenceId
```

**描述:**

地理围栏的ID号，用于标识某个地理围栏，不可重复添加相同ID号的围栏。


### loiterTimeMs

  
```
unsigned int GeofenceCircleRequest::loiterTimeMs
```

**描述:**

徘徊时间，单位为毫秒，需关注[GEOFENCE_TRANSITION_DWELL](_hdi_lpfence_geofence.md#geofencetransition)事件。若设备在圆形围栏内徘徊时间达到该值，则上报[GEOFENCE_TRANSITION_DWELL](_hdi_lpfence_geofence.md#geofencetransition)事件。


### monitorTransitions

  
```
unsigned char GeofenceCircleRequest::monitorTransitions
```

**描述:**

关注的圆形围栏事件，若设备满足关注的事件则会进行上报。详见[GeofenceTransition](_hdi_lpfence_geofence.md#geofencetransition)。


### point

  
```
struct Point GeofenceCircleRequest::point
```

**描述:**

圆形地理围栏的中心点坐标。详见[Point](_point.md)。


### radius

  
```
double GeofenceCircleRequest::radius
```

**描述:**

圆形地理围栏的半径，单位为米。
