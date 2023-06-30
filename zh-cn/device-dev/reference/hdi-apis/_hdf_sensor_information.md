# HdfSensorInformation


## 概述

定义传感器的基本信息。

传感器的信息包括传感器名称、供应商、固件版本、硬件版本、传感器类型ID、传感器ID、最大测量范围、精度和功率。

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
| [sensorName](#sensorname) | String<br/>传感器名称。 | 
| [vendorName](#vendorname) | String<br/>传感器供应商。 | 
| [firmwareVersion](#firmwareversion) | String<br/>传感器固件版本。 | 
| [hardwareVersion](#hardwareversion) | String<br/>传感器硬件版本。 | 
| [sensorTypeId](#sensortypeid) | int<br/>传感器类型ID（在[HdfSensorTypeTag](_sensor.md#hdfsensortypetag)中描述）**。** | 
| [sensorId](#sensorid) | int<br/>传感器ID，由传感器驱动程序开发人员定义。 | 
| [maxRange](#maxrange) | float<br/>传感器的最大测量范围。 | 
| [accuracy](#accuracy) | float<br/>传感器精度。 | 
| [power](#power) | float<br/>传感器功率。 | 


## 类成员变量说明


### accuracy

  
```
float HdfSensorInformation::accuracy
```

**描述:**

传感器精度。


### firmwareVersion

  
```
String HdfSensorInformation::firmwareVersion
```

**描述:**

传感器固件版本。


### hardwareVersion

  
```
String HdfSensorInformation::hardwareVersion
```

**描述:**

传感器硬件版本。


### maxRange

  
```
float HdfSensorInformation::maxRange
```

**描述:**

传感器的最大测量范围。


### power

  
```
float HdfSensorInformation::power
```

**描述:**

传感器功率。


### sensorId

  
```
int HdfSensorInformation::sensorId
```

**描述:**

传感器ID，由传感器驱动程序开发人员定义。


### sensorName

  
```
String HdfSensorInformation::sensorName
```

**描述:**

传感器名称。


### sensorTypeId

  
```
int HdfSensorInformation::sensorTypeId
```

**描述:**

传感器类型ID（在[HdfSensorTypeTag](_sensor.md#hdfsensortypetag)中描述）。


### vendorName

  
```
String HdfSensorInformation::vendorName
```

**描述:**

传感器供应商。
