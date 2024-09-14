# ThermalZoneInfo


## 概述

设备发热的信息。

**起始版本：** 3.1

**相关模块：**[Thermal](thermal_v11.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| String [type](#type) | 发热器件的类型，不同设备支持的类型不同，可参考厂商提供的详细说明。  | 
| int [temp](#temp) | 器件的温度值。  | 


## 类成员变量说明


### temp

```
int ThermalZoneInfo::temp
```
**描述**
器件的温度值。


### type

```
String ThermalZoneInfo::type
```
**描述**
发热器件的类型，不同设备支持的类型不同，可参考厂商提供的详细说明。
