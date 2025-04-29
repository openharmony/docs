# BatteryInfo


## 概述

电池相关信息。

**起始版本：** 3.1

**相关模块：**[Battery](battery_v20.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [capacity](#capacity) | 表示电池的电量百分比。  | 
| int [voltage](#voltage) | 表示电池的电压。  | 
| int [temperature](#temperature) | 表示电池的温度。  | 
| int [healthState](#healthstate) | 表示电池的健康状态，详情可参考[BatteryHealthState](battery_v20.md#batteryhealthstate)。  | 
| int [pluggedType](#pluggedtype) | 表示电池的充电设备类型，详情可参考[BatteryPluggedType](battery_v20.md#batterypluggedtype)。  | 
| int [pluggedMaxCurrent](#pluggedmaxcurrent) | 表示电池的最大充电电流。  | 
| int [pluggedMaxVoltage](#pluggedmaxvoltage) | 表示电池的最大充电电压。  | 
| int [chargeState](#chargestate) | 表示电池的充电状态，详情可参考[BatteryChargeState](battery_v20.md#batterychargestate)。  | 
| int [chargeCounter](#chargecounter) | 表示电池的充电次数。  | 
| int [totalEnergy](#totalenergy) | 表示电池的总容量。  | 
| int [curAverage](#curaverage) | 表示电池的平均电流。  | 
| int [curNow](#curnow) | 表示电池的实时电流。  | 
| int [remainEnergy](#remainenergy) | 表示电池的剩余容量。  | 
| byte [present](#present) | 表示是否支持电池或者电池是否在位。  | 
| String [technology](#technology) | 表示电池的技术型号。  | 
| String [uevent](#uevent) | 事件名。  | 


## 类成员变量说明


### capacity

```
int BatteryInfo::capacity
```
**描述**

表示电池的电量百分比。


### chargeCounter

```
int BatteryInfo::chargeCounter
```
**描述**

表示电池的充电次数。


### chargeState

```
int BatteryInfo::chargeState
```
**描述**

表示电池的充电状态，详情可参考[BatteryChargeState](battery_v20.md#batterychargestate)。


### curAverage

```
int BatteryInfo::curAverage
```
**描述**

表示电池的平均电流。


### curNow

```
int BatteryInfo::curNow
```
**描述**

表示电池的实时电流。


### healthState

```
int BatteryInfo::healthState
```
**描述**

表示电池的健康状态，详情可参考[BatteryHealthState](battery_v20.md#batteryhealthstate)。


### pluggedMaxCurrent

```
int BatteryInfo::pluggedMaxCurrent
```
**描述**

表示电池的最大充电电流。


### pluggedMaxVoltage

```
int BatteryInfo::pluggedMaxVoltage
```
**描述**

表示电池的最大充电电压。


### pluggedType

```
int BatteryInfo::pluggedType
```
**描述**

表示电池的充电设备类型，详情可参考[BatteryPluggedType](battery_v20.md#batterypluggedtype)。


### present

```
byte BatteryInfo::present
```
**描述**

表示是否支持电池或者电池是否在位。


### remainEnergy

```
int BatteryInfo::remainEnergy
```
**描述**

表示电池的剩余容量。


### technology

```
String BatteryInfo::technology
```
**描述**

表示电池的技术型号。


### temperature

```
int BatteryInfo::temperature
```
**描述**

表示电池的温度。


### totalEnergy

```
int BatteryInfo::totalEnergy
```
**描述**

表示电池的总容量。


### uevent

```
String BatteryInfo::uevent
```
**描述**

事件名。


### voltage

```
int BatteryInfo::voltage
```
**描述**

表示电池的电压。
