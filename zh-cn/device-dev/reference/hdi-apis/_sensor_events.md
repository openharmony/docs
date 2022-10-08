# SensorEvents


## **概述**

**所属模块:**

[Sensor](_sensor.md)


## **汇总**


### Public 属性

  | Public&nbsp;属性 | 描述 | 
| -------- | -------- |
| [sensorId](#sensorid) | 传感器的标识号。 | 
| [version](#version) | 传感器算法版本号。 | 
| [timestamp](#timestamp) | 传感器数据生成时间。 | 
| [option](#option) | 传感器量程精度可选配置。 | 
| [mode](#mode) | 传感器工作模式。 | 
| [data](#data) | 传感器数据地址。 | 
| [dataLen](#datalen) | 传感器数据长度。 | 


## **详细描述**

上报传感器数据结构。

上报传感器设备数据事件信息包括传感器的标识号、传感器算法版本号、传感器数据生成时间、传感器量程精度可选配置、传感器工作模式、传感器数据地址、传感器数据长度。

**Since：**

2.2


## **类成员变量说明**


### data

  
```
uint8_t* SensorEvents::data
```

**描述：**

传感器数据地址。


### mode

  
```
int32_t SensorEvents::mode
```

**描述：**

传感器工作模式。


### option

  
```
uint32_t SensorEvents::option
```

**描述：**

传感器量程精度可选配置。


### sensorId

  
```
int32_t SensorEvents::sensorId
```

**描述：**

传感器的标识号。


### timestamp

  
```
int64_t SensorEvents::timestamp
```

**描述：**

传感器数据生成时间。


### version

  
```
int32_t SensorEvents::version
```

**描述：**

传感器算法版本号。


### dataLen

  
```
int32_t SensorEvents::dataLen
```

**描述：**

传感器算法版本号。
