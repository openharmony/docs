# HdfSensorEvents


## 概述

定义传感器上报的数据。

上报的传感器数据包括传感器ID、传感器算法版本号、数据生成时间、传感器类型ID、 数据选项（如测量范围和精度）、数据上报模式、数据地址、数据长度。

**Since:**
2.2
**Version:**
1.0
**相关模块:**

[Sensor](_sensor.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [sensorId](#sensorid) | int<br/>传感器ID。&nbsp; | 
| [version](#version) | int<br/>传感器算法版本号。&nbsp; | 
| [timestamp](#timestamp) | long<br/>传感器数据生成时间。&nbsp; | 
| [option](#option) | unsigned&nbsp;int<br/>传感器数据选项，包括测量范围和精度。&nbsp; | 
| [mode](#mode) | int<br/>传感器数据上报模式。&nbsp; | 
| [data](#data) | unsigned&nbsp;char[]<br/>传感器数据地址。&nbsp; | 
| [dataLen](#datalen) | unsigned&nbsp;int<br/>传感器数据长度。&nbsp; | 


## 类成员变量说明


### data

  
```
unsigned char [] HdfSensorEvents::data
```
**描述:**
传感器数据地址。


### dataLen

  
```
unsigned int HdfSensorEvents::dataLen
```
**描述:**
传感器数据长度。


### mode

  
```
int HdfSensorEvents::mode
```
**描述:**
传感器数据上报模式。


### option

  
```
unsigned int HdfSensorEvents::option
```
**描述:**
传感器数据选项，包括测量范围和精度。


### sensorId

  
```
int HdfSensorEvents::sensorId
```
**描述:**
传感器ID。


### timestamp

  
```
long HdfSensorEvents::timestamp
```
**描述:**
传感器数据生成时间。


### version

  
```
int HdfSensorEvents::version
```
**描述:**
传感器算法版本号。
