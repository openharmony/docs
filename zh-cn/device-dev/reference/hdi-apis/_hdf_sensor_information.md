# HdfSensorInformation


## **概述**

定义传感器的基本信息。

传感器的信息包括传感器名称、供应商、固件版本、硬件版本、传感器类型ID、传感器ID、最大测量范围、精度和功率。

**相关模块:**

[Sensor](sensor.md)


## **汇总**


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [sensorName](#sensorname) | 传感器名称。 | 
| [vendorName](#vendorname) | 传感器供应商。 | 
| [firmwareVersion](#firmwareversion) | 传感器固件版本。 | 
| [hardwareVersion](#hardwareversion) | 传感器硬件版本。 | 
| [sensorTypeId](#sensortypeid) | 传感器类型ID。 | 
| [sensorId](#sensorid) | 传感器ID，由传感器驱动程序开发人员定义。 | 
| [maxRange](#maxrange) | 传感器的最大测量范围。 | 
| [accuracy](#accuracy) | 传感器精度。 | 
| [power](#power) | 传感器功率。 | 


## **类成员变量说明**


### accuracy

  
```
float HdfSensorInformation::accuracy
```

**描述：**

传感器精度。


### firmwareVersion

  
```
String HdfSensorInformation::firmwareVersion
```

**描述：**

传感器固件版本。


### hardwareVersion

  
```
String HdfSensorInformation::hardwareVersion
```

**描述：**

传感器硬件版本。


### maxRange

  
```
float HdfSensorInformation::maxRange
```

**描述：**

传感器的最大测量范围。


### power

  
```
float HdfSensorInformation::power
```

**描述：**

传感器功率。


### sensorId

  
```
int HdfSensorInformation::sensorId
```

**描述：**

传感器ID，由传感器驱动程序开发人员定义。


### sensorName

  
```
String HdfSensorInformation::sensorName
```

**描述：**

传感器名称。


### sensorTypeId

  
```
int HdfSensorInformation::sensorTypeId
```

**描述：**

传感器类型ID（在[HdfSensorTypeTag](sensor.md#hdfsensortypetag)中描述）**。**


### vendorName

  
```
String HdfSensorInformation::vendorName
```

**描述：**

传感器供应商。
