# SensorInterface


## **概述**

**所属模块:**

[Sensor](_sensor.md)


## **汇总**


### Public 属性

  | Public&nbsp;属性 | 描述 | 
| -------- | -------- |
| (&nbsp;[GetAllSensors](#getallsensors)&nbsp;)([out]&nbsp;struct&nbsp;[SensorInformation](_sensor_information.md)&nbsp;\*\*sensorInfo,&nbsp;[out]&nbsp;int32_t&nbsp;\*count) | 获取当前系统中所有类型的传感器信息。&nbsp;[更多...](#getallsensors) | 
| (&nbsp;[Enable](#enable)&nbsp;)([in]&nbsp;int32_t&nbsp;sensorId) | 根据传感器设备类型标识使能传感器信息列表里存在的设备，只有数据订阅者使能传感器后，才能获取订阅的传感器数据。&nbsp;[更多...](#enable) | 
| (&nbsp;[Disable](#disable)&nbsp;)([in]&nbsp;int32_t&nbsp;sensorId) | 根据传感器设备类型标识去使能传感器信息列表里存在的设备。&nbsp;[更多...](#disable) | 
| (&nbsp;[SetBatch](#setbatch)&nbsp;)([in]&nbsp;int32_t&nbsp;sensorId,&nbsp;[in]&nbsp;int64_t&nbsp;samplingInterval,&nbsp;[in]&nbsp;int64_t&nbsp;reportInterval) | 设置指定传感器的数据采样间隔和数据上报间隔。&nbsp;[更多...](#setbatch) | 
| (&nbsp;[SetMode](#setmode)&nbsp;)([in]&nbsp;int32_t&nbsp;sensorId,&nbsp;[in]&nbsp;int32_t&nbsp;mode) | 设置指定传感器的数据上报模式，不同的工作模式，上报数据的方式不同。&nbsp;[更多...](#setmode) | 
| (&nbsp;[SetOption](#setoption)&nbsp;)([in]&nbsp;int32_t&nbsp;sensorId,&nbsp;[in]&nbsp;uint32_t&nbsp;option) | 设置指定传感器量程、精度等可选配置。&nbsp;[更多...](#setoption) | 
| (&nbsp;[Register](#register)&nbsp;)([in]&nbsp;int32_t&nbsp;groupId,&nbsp;[in]&nbsp;[RecordDataCallback](_sensor.md#recorddatacallback)&nbsp;cb) | 订阅者注册传感器数据回调函数，系统会将获取到的传感器数据上报给订阅者。&nbsp;[更多...](#register) | 
| (&nbsp;[Unregister](#unregister)&nbsp;)([in]&nbsp;int32_t&nbsp;groupId,&nbsp;[in]&nbsp;[RecordDataCallback](_sensor.md#recorddatacallback)&nbsp;cb) | 订阅者去注册传感器数据回调函数。&nbsp;[更多...](#unregister) | 


## **详细描述**

提供sensor设备基本控制操作接口。

结构体提供获取传感器设备信息、订阅/去订阅传感器数据、使能/去使能传感器、设置传感器模式、设置传感器精度、量程等可选配置接口定义。


## **类成员变量说明**


### Disable

  
```
int32_t(* SensorInterface::Disable) ([in] int32_t sensorId)
```

**描述：**

根据传感器设备类型标识去使能传感器信息列表里存在的设备。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| sensorId | 唯一标识一个传感器设备类型，详见[SensorTypeTag](_sensor.md#sensortypetag)。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### Enable

  
```
int32_t(* SensorInterface::Enable) ([in] int32_t sensorId)
```

**描述：**

根据传感器设备类型标识使能传感器信息列表里存在的设备，只有数据订阅者使能传感器后，才能获取订阅的传感器数据。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| sensorId | 唯一标识一个传感器设备类型，详见[SensorTypeTag](_sensor.md#sensortypetag)。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### GetAllSensors

  
```
int32_t(* SensorInterface::GetAllSensors) ([out] struct SensorInformation **sensorInfo,[out] int32_t *count)
```

**描述：**

获取当前系统中所有类型的传感器信息。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| sensorInfo | 输出系统中注册的所有传感器信息，一种类型传感器信息包括传感器名字、设备厂商、&nbsp;固件版本号、硬件版本号、传感器类型编号、传感器标识、最大量程、精度、功耗，详见[SensorInformation](_sensor_information.md)。 | 
| count | 输出系统中注册的传感器数量。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### Register

  
```
int32_t(* SensorInterface::Register) ([in] int32_t groupId,[in] RecordDataCallback cb)
```

**描述：**

订阅者注册传感器数据回调函数，系统会将获取到的传感器数据上报给订阅者。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| groupId | 传感器组ID。&nbsp;sensorId枚举值范围为128-160，表示已订阅医疗传感器服务，只需成功订阅一次，无需重复订阅。&nbsp;sensorId枚举值范围不在128-160之间，这意味着传统传感器已订阅，只需成功订阅一次，无需重复订阅。 | 
| cb | 要注册的回调函数，详见[RecordDataCallback](_sensor.md#recorddatacallback)。 | 

**返回：**

如果注册回调函数成功，则返回0。

如果注册回调函数失败，则返回负数。


### SetBatch

  
```
int32_t(* SensorInterface::SetBatch) ([in] int32_t sensorId,[in] int64_t samplingInterval,[in] int64_t reportInterval)
```

**描述：**

设置指定传感器的数据采样间隔和数据上报间隔。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| sensorId | 唯一标识一个传感器设备类型，详见[SensorTypeTag](_sensor.md#sensortypetag)。 | 
| samplingInterval | 设置指定传感器的数据采样间隔，单位纳秒。 | 
| reportInterval | 表示传感器数据上报间隔，单位纳秒。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### SetMode

  
```
int32_t(* SensorInterface::SetMode) ([in] int32_t sensorId,[in] int32_t mode)
```

**描述：**

设置指定传感器的数据上报模式，不同的工作模式，上报数据的方式不同。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| sensorId | 唯一标识一个传感器设备类型，详见[SensorTypeTag](_sensor.md#sensortypetag)。 | 
| mode | 传感器的数据上报模式，详见[SensorModeType](_sensor.md#sensormodetype)。 | 

**返回：**

如果设置传感器数据报告模式成功，则返回0。

如果设置传感器数据报告模式失败，则返回负数。


### SetOption

  
```
int32_t(* SensorInterface::SetOption) ([in] int32_t sensorId,[in] uint32_t option)
```

**描述：**

设置指定传感器量程、精度等可选配置。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| sensorId | 唯一标识一个传感器设备类型，详见[SensorTypeTag](_sensor.md#sensortypetag)。 | 
| option | 传感器的量程、精度等配置。 | 

**返回：**

如果设置参数成功，则返回0。

如果设置参数失败，则返回负数。


### Unregister

  
```
int32_t(* SensorInterface::Unregister) ([in] int32_t groupId,[in] RecordDataCallback cb)
```

**描述：**

订阅者去注册传感器数据回调函数。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| groupId | 传感器组ID。&nbsp;sensorId枚举值范围为128-160，表示已订阅医疗传感器服务。只需成功取消订阅一次，无需重复取消订阅。&nbsp;sensorId枚举值范围不在128-160之间，这意味着传统传感器已订阅。并且成功取消订阅。 | 
| cb | 要注册的回调函数，详见[RecordDataCallback](_sensor.md#recorddatacallback)。 | 

**返回：**

如果取消注册回调函数成功，则返回0。

如果取消注册回调函数失败，则返回负数。
