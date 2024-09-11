# Location_BasicInfo


## 概述

定义位置基本信息的结构体。

**起始版本：** 13

**相关模块：**[Location](_location.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| double [latitude](#latitude) | 表示纬度信息，正值表示北纬，负值表示南纬。取值范围为-90到90。仅支持WGS84坐标系。  | 
| double [longitude](#longitude) | 表示经度信息，正值表示东经，负值表是西经。取值范围为-180到180。仅支持WGS84坐标系。  | 
| double [altitude](#altitude) | 表示高度信息，单位米。  | 
| double [accuracy](#accuracy) | 表示精度信息，单位米。  | 
| double [speed](#speed) | 表示速度信息，单位米每秒。  | 
| double [direction](#direction) | 表示航向信息。单位是“度”，取值范围为0到360。  | 
| int64_t [timeForFix](#timeforfix) | 表示位置时间戳，UTC格式。  | 
| int64_t [timeSinceBoot](#timesinceboot) | 表示位置时间戳，开机时间格式。  | 
| double [altitudeAccuracy](#altitudeaccuracy) | 表示高度信息的精度，单位米。  | 
| double [speedAccuracy](#speedaccuracy) | 表示速度信息的精度，单位米每秒。  | 
| double [directionAccuracy](#directionaccuracy) | 表示航向信息的精度。单位是“度”，取值范围为0到360。  | 
| int64_t [uncertaintyOfTimeSinceBoot](#uncertaintyoftimesinceboot) | 表示位置时间戳的不确定度。  | 
| [Location_SourceType](_location.md#location_sourcetype)[locationSourceType](#locationsourcetype) | 表示定位结果的来源。 详细定义请参考[Location_SourceType](_location.md#location_sourcetype). | 


## 结构体成员变量说明


### accuracy

```
double Location_BasicInfo::accuracy
```
**描述**
表示精度信息，单位米。


### altitude

```
double Location_BasicInfo::altitude
```
**描述**
表示高度信息，单位米。


### altitudeAccuracy

```
double Location_BasicInfo::altitudeAccuracy
```
**描述**
表示高度信息的精度，单位米。


### direction

```
double Location_BasicInfo::direction
```
**描述**
表示航向信息。单位是“度”，取值范围为0到360。


### directionAccuracy

```
double Location_BasicInfo::directionAccuracy
```
**描述**
表示航向信息的精度。单位是“度”，取值范围为0到360。


### latitude

```
double Location_BasicInfo::latitude
```
**描述**
表示纬度信息，正值表示北纬，负值表示南纬。取值范围为-90到90。仅支持WGS84坐标系。


### locationSourceType

```
Location_SourceType Location_BasicInfo::locationSourceType
```
**描述**
表示定位结果的来源。 详细定义请参考[Location_SourceType](_location.md#location_sourcetype).


### longitude

```
double Location_BasicInfo::longitude
```
**描述**
表示经度信息，正值表示东经，负值表是西经。取值范围为-180到180。仅支持WGS84坐标系。


### speed

```
double Location_BasicInfo::speed
```
**描述**
表示速度信息，单位米每秒。


### speedAccuracy

```
double Location_BasicInfo::speedAccuracy
```
**描述**
表示速度信息的精度，单位米每秒。


### timeForFix

```
int64_t Location_BasicInfo::timeForFix
```
**描述**
表示位置时间戳，UTC格式。


### timeSinceBoot

```
int64_t Location_BasicInfo::timeSinceBoot
```
**描述**
表示位置时间戳，开机时间格式。


### uncertaintyOfTimeSinceBoot

```
int64_t Location_BasicInfo::uncertaintyOfTimeSinceBoot
```
**描述**
表示位置时间戳的不确定度。
