# SensorInformation


## **概述**

**所属模块:**

[Sensor](_sensor.md)


## **汇总**


### Public 属性

| Public&nbsp;属性 | 描述 |
| -------- | -------- |
| [sensorName](#sensorname)&nbsp;[[SENSOR_NAME_MAX_LEN](_sensor.md#sensornamemaxlen)] | 传感器名称。 |
| [vendorName](#vendorname)&nbsp;[[SENSOR_NAME_MAX_LEN](_sensor.md#sensornamemaxlen)] | 传感器设备厂商。 |
| [firmwareVersion](#firmwareversion)&nbsp;[[SENSOR_VERSION_MAX_LEN](_sensor.md#sensorversionmaxlen)] | 传感器固件版本号。 |
| [hardwareVersion](#hardwareversion)<br/>[[SENSOR_VERSION_MAX_LEN](_sensor.md#sensorversionmaxlen)] | 传感器硬件版本号。 |
| [sensorTypeId](#sensortypeid) | 传感器类型编号。 |
| [sensorId](#sensorid) | 传感器的标识号，由传感器驱动开发者定义。 |
| [maxRange](#maxrange) | 传感器的最大量程。 |
| [accuracy](#accuracy) | 传感器的精度。 |
| [power](#power) | 传感器的功耗。 |


## **详细描述**

定义传感器基本信息。

一个传感器设备信息包括传感器名字、设备厂商、固件版本号、硬件版本号、传感器类型编号、传感器标识、最大量程、精度、功耗。

**Since：**

2.2


## **类成员变量说明**


### accuracy


```
float SensorInformation::accuracy
```

**描述：**

传感器的精度。


### firmwareVersion


```
char SensorInformation::firmwareVersion[SENSOR_VERSION_MAX_LEN]
```

**描述：**

传感器固件版本号。


### hardwareVersion


```
char SensorInformation::hardwareVersion[SENSOR_VERSION_MAX_LEN]
```

**描述：**

传感器硬件版本号。


### maxRange


```
float SensorInformation::maxRange
```

**描述：**

传感器的最大量程。


### sensorId


```
int32_t SensorInformation::sensorId
```

**描述：**

传感器的标识号，由传感器驱动开发者定义。


### sensorName


```
char SensorInformation::sensorName[SENSOR_NAME_MAX_LEN]
```

**描述：**

传感器名称。


### sensorTypeId


```
int32_t SensorInformation::sensorTypeId
```

**描述：**

传感器类型编号，唯一标识一个传感器设备类型，详见[SensorTypeTag](_sensor.md#sensortypetag)。


### vendorName


```
char SensorInformation::vendorName[SENSOR_NAME_MAX_LEN]
```

**描述：**

传感器设备厂商。


### power


```
char SensorInformation::power
```

**描述：**

传感器的功耗。
