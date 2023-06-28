# GeoLocationInfo


## 概述

定义设备具体位置信息的数据结构。

**Since:**
4.0
**相关模块:**

[HdiLpfenceGeofence](_hdi_lpfence_geofence.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [flags](#flags) | unsigned&nbsp;short<br/>bit0表示经纬度是否有效，bit5表示精度是否有效。0表示无效，1表示有效。&nbsp; | 
| [latitude](#latitude) | double<br/>纬度&nbsp; | 
| [longitude](#longitude) | double<br/>经度&nbsp; | 
| [altitude](#altitude) | double<br/>海拔高度，单位米&nbsp; | 
| [accuracy](#accuracy) | float<br/>精度，单位米&nbsp; | 
| [speed](#speed) | float<br/>移动速度，单位米/秒&nbsp; | 
| [bearing](#bearing) | float<br/>导向&nbsp; | 
| [timeStamp](#timestamp) | long<br/>时间戳，单位纳秒&nbsp; | 


## 类成员变量说明


### accuracy

  
```
float GeoLocationInfo::accuracy
```
**描述:**
精度，单位米


### altitude

  
```
double GeoLocationInfo::altitude
```
**描述:**
海拔高度，单位米


### bearing

  
```
float GeoLocationInfo::bearing
```
**描述:**
导向


### flags

  
```
unsigned short GeoLocationInfo::flags
```
**描述:**
bit0表示经纬度是否有效，bit5表示精度是否有效。0表示无效，1表示有效。


### latitude

  
```
double GeoLocationInfo::latitude
```
**描述:**
纬度


### longitude

  
```
double GeoLocationInfo::longitude
```
**描述:**
经度


### speed

  
```
float GeoLocationInfo::speed
```
**描述:**
移动速度，单位米/秒


### timeStamp

  
```
long GeoLocationInfo::timeStamp
```
**描述:**
时间戳，单位纳秒
