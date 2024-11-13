# LocationInfo


## 概述

定义GNSS定位结果结构体。

**起始版本：** 3.2

**相关模块：**[HdiGnss](_hdi_gnss.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| double [latitude](#latitude) | 纬度  | 
| double [longitude](#longitude) | 经度  | 
| double [altitude](#altitude) | 海拔  | 
| float [accuracy](#accuracy) | 精确度  | 
| float [speed](#speed) | 速度  | 
| double [direction](#direction) | 方向  | 
| long [timeStamp](#timestamp) | UTC时间戳  | 
| long [timeSinceBoot](#timesinceboot) | 自系统启动后经过的时间  | 


## 类成员变量说明


### accuracy

```
float LocationInfo::accuracy
```
**描述**

精确度


### altitude

```
double LocationInfo::altitude
```
**描述**

海拔


### direction

```
double LocationInfo::direction
```
**描述**

方向


### latitude

```
double LocationInfo::latitude
```
**描述**

纬度


### longitude

```
double LocationInfo::longitude
```
**描述**

经度


### speed

```
float LocationInfo::speed
```
**描述**

速度


### timeSinceBoot

```
long LocationInfo::timeSinceBoot
```
**描述**

自系统启动后经过的时间


### timeStamp

```
long LocationInfo::timeStamp
```
**描述**

UTC时间戳
