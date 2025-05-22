# GnssBasicConfig


## 概述

定义基础的GNSS配置参数。

**起始版本：** 3.2

**相关模块：**[HdiGnss](_hdi_gnss.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| unsigned int [minInterval](#mininterval) | 位置上报间隔  | 
| unsigned int [accuracy](#accuracy) | 期望的定位精度  | 
| unsigned int [firstFixTime](#firstfixtime) | 期望的首定位耗时  | 
| boolean [isPeriodicPositioning](#isperiodicpositioning) | 是否周期性定位  | 
| enum [GnssWorkingMode](_hdi_gnss.md#gnssworkingmode)[gnssMode](#gnssmode) | GNSS工作模式  | 


## 类成员变量说明


### accuracy

```
unsigned int GnssBasicConfig::accuracy
```
**描述**

期望的定位精度


### firstFixTime

```
unsigned int GnssBasicConfig::firstFixTime
```
**描述**

期望的首定位耗时


### gnssMode

```
enum GnssWorkingMode GnssBasicConfig::gnssMode
```
**描述**

GNSS工作模式


### isPeriodicPositioning

```
boolean GnssBasicConfig::isPeriodicPositioning
```
**描述**

是否周期性定位


### minInterval

```
unsigned int GnssBasicConfig::minInterval
```
**描述**

位置上报间隔
