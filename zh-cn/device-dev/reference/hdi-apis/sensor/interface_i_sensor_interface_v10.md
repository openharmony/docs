# ISensorInterface


## 概述

提供Sensor设备基本控制操作接口。

操作包括获取传感器设备信息、订阅/取消订阅传感器数据、使能/去使能传感器、设置传感器模式、设置传感器精度、量程等可选配置接口定义。

**起始版本：** 2.2

**相关模块：**[Sensor](_hdi_sensor_v10.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [GetAllSensorInfo](#getallsensorinfo) ([out] struct [HdfSensorInformation](_hdf_sensor_information_v10.md)[] info) | 获取当前系统中所有类型的传感器信息。  | 
| [Enable](#enable) ([in] int sensorId) | 根据传感器设备类型标识使能传感器信息列表里存在的设备，只有数据订阅者使能传感器后，才能获取订阅的传感器数据。  | 
| [Disable](#disable) ([in] int sensorId) | 根据传感器设备类型标识去使能传感器信息列表里存在的设备。  | 
| [SetBatch](#setbatch) ([in] int sensorId,[in] long samplingInterval, [in] long reportInterval) | 设置指定传感器的数据上报模式，不同的工作模式，上报数据的方式不同。  | 
| [SetMode](#setmode) ([in] int sensorId, [in] int mode) | 设置指定传感器数据上报模式。  | 
| [SetOption](#setoption) ([in] int sensorId, [in] unsigned int option) | 设置指定传感器量程、精度等可选配置。  | 
| [Register](#register) ([in] int groupId, [in] [ISensorCallback](interface_i_sensor_callback_v10.md) callbackObj) | 订阅者注册传感器数据回调函数，系统会将获取到的传感器数据上报给订阅者。  | 
| [Unregister](#unregister) ([in] int groupId, [in] [ISensorCallback](interface_i_sensor_callback_v10.md) callbackObj) | 订阅者取消注册传感器数据回调函数。  | 


## 成员函数说明


### Disable()

```
ISensorInterface::Disable ([in] int sensorId)
```
**描述**

根据传感器设备类型标识去使能传感器信息列表里存在的设备。

**起始版本：** 2.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| sensorId | 唯一标识一个传感器设备类型，详见[HdfSensorTypeTag](_hdi_sensor_v10.md#hdfsensortypetag)。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### Enable()

```
ISensorInterface::Enable ([in] int sensorId)
```
**描述**

根据传感器设备类型标识使能传感器信息列表里存在的设备，只有数据订阅者使能传感器后，才能获取订阅的传感器数据。

**起始版本：** 2.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| sensorId | 唯一标识一个传感器设备类型，详见[HdfSensorTypeTag](_hdi_sensor_v10.md#hdfsensortypetag)。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### GetAllSensorInfo()

```
ISensorInterface::GetAllSensorInfo ([out] struct HdfSensorInformation[] info)
```
**描述**

获取当前系统中所有类型的传感器信息。

**起始版本：** 2.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| 输出系统中注册的所有传感器信息，一种类型传感器信息包括传感器名字、设备厂商、 | 固件版本号、硬件版本号、传感器类型编号、传感器标识、最大量程、精度、功耗，详见[HdfSensorInformation](_hdf_sensor_information_v10.md)。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### Register()

```
ISensorInterface::Register ([in] int groupId, [in] ISensorCallback callbackObj )
```
**描述**

订阅者注册传感器数据回调函数，系统会将获取到的传感器数据上报给订阅者。

**起始版本：** 2.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| groupId | 传感器组ID。 groupId枚举值范围为128-160，表示已订阅医疗传感器服务，只需成功订阅一次，无需重复订阅。 groupId枚举值范围不在128-160之间，这意味着传统传感器已订阅，只需成功订阅一次，无需重复订阅。  | 
| callbackObj | 要注册的回调函数，详见[ISensorCallback](interface_i_sensor_callback_v10.md)。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负数。


### SetBatch()

```
ISensorInterface::SetBatch ([in] int sensorId, [in] long samplingInterval, [in] long reportInterval )
```
**描述**

设置指定传感器的数据上报模式，不同的工作模式，上报数据的方式不同。

**起始版本：** 2.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| sensorId | 唯一标识一个传感器设备类型，详见[HdfSensorTypeTag](_hdi_sensor_v10.md#hdfsensortypetag)。  | 
| samplingInterval | 设置指定传感器的数据采样间隔，单位纳秒。  | 
| reportInterval | 表示传感器数据上报间隔，单位纳秒。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### SetMode()

```
ISensorInterface::SetMode ([in] int sensorId, [in] int mode )
```
**描述**

设置指定传感器数据上报模式。

**起始版本：** 2.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| sensorId | 唯一标识一个传感器设备类型，详见[HdfSensorTypeTag](_hdi_sensor_v10.md#hdfsensortypetag)。  | 
| mode | 传感器的数据上报模式，详见[HdfSensorModeType](_hdi_sensor_v10.md#hdfsensormodetype)。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负数。


### SetOption()

```
ISensorInterface::SetOption ([in] int sensorId, [in] unsigned int option )
```
**描述**

设置指定传感器量程、精度等可选配置。

**起始版本：** 2.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| sensorId | 唯一标识一个传感器设备类型，详见[HdfSensorTypeTag](_hdi_sensor_v10.md#hdfsensortypetag)。  | 
| option | 表示要设置的选项，如测量范围和精度。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负数。


### Unregister()

```
ISensorInterface::Unregister ([in] int groupId, [in] ISensorCallback callbackObj )
```
**描述**

订阅者取消注册传感器数据回调函数。

**起始版本：** 2.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| groupId | 传感器组ID。 groupId枚举值范围为128-160，表示已订阅医疗传感器服务。只需成功取消订阅一次，无需重复取消订阅。 groupId枚举值范围不在128-160之间，这意味着传统传感器已订阅。并且成功取消订阅。  | 
| callbackObj | 要取消注册的回调函数，详见[ISensorCallback](interface_i_sensor_callback_v10.md)。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负数。
