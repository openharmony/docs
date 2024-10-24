# HdfSensorEvents


## 概述

定义传感器上报的数据。

上报的传感器数据包括传感器ID、传感器算法版本号、数据生成时间、传感器类型ID、 数据选项（如测量范围和精度）、数据上报模式、数据地址、数据长度。

**起始版本：** 2.2

**相关模块：**[HdiSensor](_hdi_sensor_v20.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [sensorId](#sensorid) | 传感器ID。  | 
| int [version](#version) | 传感器算法版本号。  | 
| long [timestamp](#timestamp) | 传感器数据生成时间。  | 
| unsigned int [option](#option) | 传感器数据选项，包括测量范围和精度。  | 
| int [mode](#mode) | 传感器数据上报模式。  | 
| unsigned char[] [data](#data) | 传感器数据地址。  | 
| unsigned int [dataLen](#datalen) | 传感器数据长度。  | 


## 类成员变量说明


### data

```
unsigned char [] HdfSensorEvents::data
```
**描述**

传感器数据地址。


### dataLen

```
unsigned int HdfSensorEvents::dataLen
```
**描述**

传感器数据长度。


### mode

```
int HdfSensorEvents::mode
```
**描述**

传感器数据上报模式。


### option

```
unsigned int HdfSensorEvents::option
```
**描述**

传感器数据选项，包括测量范围和精度。


### sensorId

```
int HdfSensorEvents::sensorId
```
**描述**

传感器ID。


### timestamp

```
long HdfSensorEvents::timestamp
```
**描述**

传感器数据生成时间。


### version

```
int HdfSensorEvents::version
```
**描述**

传感器算法版本号。
