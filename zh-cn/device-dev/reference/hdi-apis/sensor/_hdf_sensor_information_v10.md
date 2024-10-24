# HdfSensorInformation


## 概述

定义传感器的基本信息。

传感器的信息包括传感器名称、供应商、固件版本、硬件版本、传感器类型ID、传感器ID、最大测量范围、精度和功率。

**起始版本：** 2.2

**相关模块：**[Sensor](_hdi_sensor_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| String [sensorName](#sensorname) | 传感器名称。 | 
| String [vendorName](#vendorname) | 传感器供应商。 | 
| String [firmwareVersion](#firmwareversion) | 传感器固件版本。 | 
| String [hardwareVersion](#hardwareversion) | 传感器硬件版本。 | 
| int [sensorTypeId](#sensortypeid) | 传感器类型ID（在[HdfSensorTypeTag](_hdi_sensor_v10.md#hdfsensortypetag)中描述）**。** | 
| int [sensorId](#sensorid) | 传感器ID，由传感器驱动程序开发人员定义。 | 
| float [maxRange](#maxrange) | 传感器的最大测量范围。 | 
| float [accuracy](#accuracy) | 传感器精度。 | 
| float [power](#power) | 传感器功率。 | 


## 类成员变量说明


### accuracy

```
float HdfSensorInformation::accuracy
```

**描述**


传感器精度。


### firmwareVersion

```
String HdfSensorInformation::firmwareVersion
```

**描述**


传感器固件版本。


### hardwareVersion

```
String HdfSensorInformation::hardwareVersion
```

**描述**


传感器硬件版本。


### maxRange

```
float HdfSensorInformation::maxRange
```

**描述**


传感器的最大测量范围。


### power

```
float HdfSensorInformation::power
```

**描述**


传感器功率。


### sensorId

```
int HdfSensorInformation::sensorId
```

**描述**


传感器ID，由传感器驱动程序开发人员定义。


### sensorName

```
String HdfSensorInformation::sensorName
```

**描述**


传感器名称。


### sensorTypeId

```
int HdfSensorInformation::sensorTypeId
```

**描述**


传感器类型ID（在[HdfSensorTypeTag](_hdi_sensor_v10.md#hdfsensortypetag)中描述）**。**


### vendorName

```
String HdfSensorInformation::vendorName
```

**描述**


传感器供应商。
