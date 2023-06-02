# BatteryInfo


## 概述

电池相关信息。

**Since:**
3.1
**相关模块:**

[Battery](battery.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [capacity](#capacity) | int<br/>表示电池的电量百分比。&nbsp; | 
| [voltage](#voltage) | int<br/>表示电池的电压。&nbsp; | 
| [temperature](#temperature) | int<br/>表示电池的温度&nbsp; | 
| [healthState](#healthstate) | int<br/>表示电池的健康状态。&nbsp; | 
| [pluggedType](#pluggedtype) | int<br/>表示电池的充电设备类型。&nbsp; | 
| [pluggedMaxCurrent](#pluggedmaxcurrent) | int<br/>表示电池的最大充电电流。&nbsp; | 
| [pluggedMaxVoltage](#pluggedmaxvoltage) | int<br/>表示电池的最大充电电压。&nbsp; | 
| [chargeState](#chargestate) | int<br/>表示电池的充电状态。&nbsp; | 
| [chargeCounter](#chargecounter) | int<br/>表示电池的充电次数。&nbsp; | 
| [totalEnergy](#totalenergy) | int<br/>表示电池的总容量。&nbsp; | 
| [curAverage](#curaverage) | int<br/>表示电池的平均电流。&nbsp; | 
| [curNow](#curnow) | int<br/>表示电池的实时电流。&nbsp; | 
| [remainEnergy](#remainenergy) | int<br/>表示电池的剩余容量。&nbsp; | 
| [present](#present) | byte<br/>表示是否支持电池或者电池是否在位。&nbsp; | 
| [technology](#technology) | String<br/>表示电池的技术型号。&nbsp; | 


## 类成员变量说明


### capacity

  
```
int BatteryInfo::capacity
```
**描述:**
表示电池的电量百分比。


### chargeCounter

  
```
int BatteryInfo::chargeCounter
```
**描述:**
表示电池的充电次数。


### chargeState

  
```
int BatteryInfo::chargeState
```
**描述:**
表示电池的充电状态。


### curAverage

  
```
int BatteryInfo::curAverage
```
**描述:**
表示电池的平均电流。


### curNow

  
```
int BatteryInfo::curNow
```
**描述:**
表示电池的实时电流。


### healthState

  
```
int BatteryInfo::healthState
```
**描述:**
表示电池的健康状态。


### pluggedMaxCurrent

  
```
int BatteryInfo::pluggedMaxCurrent
```
**描述:**
表示电池的最大充电电流。


### pluggedMaxVoltage

  
```
int BatteryInfo::pluggedMaxVoltage
```
**描述:**
表示电池的最大充电电压。


### pluggedType

  
```
int BatteryInfo::pluggedType
```
**描述:**
表示电池的充电设备类型。


### present

  
```
byte BatteryInfo::present
```
**描述:**
表示是否支持电池或者电池是否在位。


### remainEnergy

  
```
int BatteryInfo::remainEnergy
```
**描述:**
表示电池的剩余容量。


### technology

  
```
String BatteryInfo::technology
```
**描述:**
表示电池的技术型号。


### temperature

  
```
int BatteryInfo::temperature
```
**描述:**
表示电池的温度


### totalEnergy

  
```
int BatteryInfo::totalEnergy
```
**描述:**
表示电池的总容量。


### voltage

  
```
int BatteryInfo::voltage
```
**描述:**
表示电池的电压。
