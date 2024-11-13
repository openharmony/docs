# GeofenceSize


## 概述

定义地理围栏使用信息的数据结构。

**起始版本：** 4.0

**相关模块：**[HdiLpfenceGeofence](_hdi_lpfence_geofence.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| unsigned int [circleMaxNum](#circlemaxnum) | 设备支持添加圆形围栏的最大个数。 | 
| unsigned int [polygonMaxNum](#polygonmaxnum) | 设备支持添加多边形围栏的最大个数。 | 
| unsigned int [circleUsedNum](#circleusednum) | 设备当前已添加的圆形围栏个数。 | 
| unsigned int [polygonUsedNum](#polygonusednum) | 设备当前已添加的多边形围栏个数。 | 


## 类成员变量说明


### circleMaxNum

```
unsigned int GeofenceSize::circleMaxNum
```

**描述**


设备支持添加圆形围栏的最大个数。


### circleUsedNum

```
unsigned int GeofenceSize::circleUsedNum
```

**描述**


设备当前已添加的圆形围栏个数。


### polygonMaxNum

```
unsigned int GeofenceSize::polygonMaxNum
```

**描述**


设备支持添加多边形围栏的最大个数。


### polygonUsedNum

```
unsigned int GeofenceSize::polygonUsedNum
```

**描述**


设备当前已添加的多边形围栏个数。
