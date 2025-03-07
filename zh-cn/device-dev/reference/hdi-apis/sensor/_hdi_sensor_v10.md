# HdiSensor (V1_0)


## 概述

传感器设备驱动对传感器服务提供通用的接口能力。

模块提供传感器服务对传感器驱动访问统一接口，服务获取驱动对象或者代理后，通过其提供的各类方法，实现获取传感器设备信息、订阅/取消订阅传感器数据、 使能/去使能传感器、设置传感器模式、设置传感器精度、量程等可选配置等。

**起始版本：** 2.2


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [ISensorCallback.idl](_i_sensor_callback_8idl_v10.md) | Sensor模块为Sensor服务提供数据上报的回调函数。 | 
| [ISensorInterface.idl](_i_sensor_interface_8idl_v10.md) | Sensor模块对外通用的接口声明文件，提供获取传感器设备信息、订阅/取消订阅传感器数据、 使能/去使能传感器、设置传感器模式、设置传感器精度，量程等可选配置接口定义。 | 
| [SensorTypes.idl](_sensor_types_8idl_v10.md) | 定义传感器模块所使用的传感器类型，传感器信息，传感器数据结构等数据类型。 | 


### 类

| 名称 | 描述 | 
| -------- | -------- |
| interface&nbsp;&nbsp;[ISensorCallback](interface_i_sensor_callback_v10.md) | 定义用于上报传感器数据的回调函数。 | 
| interface&nbsp;&nbsp;[ISensorInterface](interface_i_sensor_interface_v10.md) | 提供Sensor设备基本控制操作接口。 | 
| struct&nbsp;&nbsp;[HdfSensorInformation](_hdf_sensor_information_v10.md) | 定义传感器的基本信息。 | 
| struct&nbsp;&nbsp;[HdfSensorEvents](_hdf_sensor_events_v10.md) | 定义传感器上报的数据。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [HdfSensorTypeTag](#hdfsensortypetag) {<br/>HDF_SENSOR_TYPE_NONE = 0, HDF_SENSOR_TYPE_ACCELEROMETER = 1, HDF_SENSOR_TYPE_GYROSCOPE = 2, HDF_SENSOR_TYPE_PHOTOPLETHYSMOGRAPH = 3,&nbsp;&nbsp;&nbsp;HDF_SENSOR_TYPE_ELECTROCARDIOGRAPH = 4, HDF_SENSOR_TYPE_AMBIENT_LIGHT = 5, HDF_SENSOR_TYPE_MAGNETIC_FIELD = 6, HDF_SENSOR_TYPE_CAPACITIVE = 7,&nbsp;&nbsp;&nbsp;HDF_SENSOR_TYPE_BAROMETER = 8, HDF_SENSOR_TYPE_TEMPERATURE = 9, HDF_SENSOR_TYPE_HALL = 10, HDF_SENSOR_TYPE_GESTURE = 11,&nbsp;&nbsp;&nbsp;HDF_SENSOR_TYPE_PROXIMITY = 12, HDF_SENSOR_TYPE_HUMIDITY = 13, HDF_SENSOR_TYPE_MEDICAL_BEGIN = 128, HDF_SENSOR_TYPE_MEDICAL_END = 160,&nbsp;&nbsp;&nbsp;HDF_SENSOR_TYPE_PHYSICAL_MAX = 255, HDF_SENSOR_TYPE_ORIENTATION = 256, HDF_SENSOR_TYPE_GRAVITY = 257, HDF_SENSOR_TYPE_LINEAR_ACCELERATION = 258,&nbsp;&nbsp;&nbsp;HDF_SENSOR_TYPE_ROTATION_VECTOR = 259, HDF_SENSOR_TYPE_AMBIENT_TEMPERATURE = 260, HDF_SENSOR_TYPE_MAGNETIC_FIELD_UNCALIBRATED = 261, HDF_SENSOR_TYPE_GAME_ROTATION_VECTOR = 262,&nbsp;&nbsp;&nbsp;HDF_SENSOR_TYPE_GYROSCOPE_UNCALIBRATED = 263, HDF_SENSOR_TYPE_SIGNIFICANT_MOTION = 264, HDF_SENSOR_TYPE_PEDOMETER_DETECTION = 265, HDF_SENSOR_TYPE_PEDOMETER = 266,&nbsp;&nbsp;&nbsp;HDF_SENSOR_TYPE_GEOMAGNETIC_ROTATION_VECTOR = 277, HDF_SENSOR_TYPE_HEART_RATE = 278, HDF_SENSOR_TYPE_DEVICE_ORIENTATION = 279, HDF_SENSOR_TYPE_WEAR_DETECTION = 280,&nbsp;&nbsp;&nbsp;HDF_SENSOR_TYPE_ACCELEROMETER_UNCALIBRATED = 281, HDF_SENSOR_TYPE_MAX<br/>} | 定义传感器类型标识。 | 
| [HdfSensorGroupType](#hdfsensorgrouptype) { HDF_TRADITIONAL_SENSOR_TYPE = 0, HDF_MEDICAL_SENSOR_TYPE = 1, HDF_SENSOR_GROUP_TYPE_MAX } | 枚举传感器的硬件服务组。 | 
| [HdfSensorModeType](#hdfsensormodetype) { SENSOR_MODE_DEFAULT = 0, SENSOR_MODE_REALTIME = 1, SENSOR_MODE_ON_CHANGE = 2, SENSOR_MODE_ONE_SHOT = 3,&nbsp;&nbsp;&nbsp;SENSOR_MODE_FIFO_MODE = 4, SENSOR_MODE_MAX } | 传感器的工作模式。 | 


## 枚举类型说明


### HdfSensorGroupType

```
enum HdfSensorGroupType
```

**描述**


枚举传感器的硬件服务组。

**起始版本：** 2.2

| 枚举值 | 描述 | 
| -------- | -------- |
| HDF_TRADITIONAL_SENSOR_TYPE | 传统传感器类型，传感器ID枚举值范围不在128-160之间。 | 
| HDF_MEDICAL_SENSOR_TYPE | 医疗传感器类型，传感器ID枚举值范围在128-160之间。 | 
| HDF_SENSOR_GROUP_TYPE_MAX | 最大传感器类型。 | 


### HdfSensorModeType

```
enum HdfSensorModeType
```

**描述**


传感器的工作模式。

**起始版本：** 2.2

| 枚举值 | 描述 | 
| -------- | -------- |
| SENSOR_MODE_DEFAULT | 传感器数据默认上报模式。 | 
| SENSOR_MODE_REALTIME | 传感器数据持续上报模式。 | 
| SENSOR_MODE_ON_CHANGE | 传感器数据变更时上报模式。 | 
| SENSOR_MODE_ONE_SHOT | 传感器一次数据上报模式。 | 
| SENSOR_MODE_FIFO_MODE | 传感器数据缓存模式。 | 
| SENSOR_MODE_MAX | 传感器最大类型标识。 | 


### HdfSensorTypeTag

```
enum HdfSensorTypeTag
```

**描述**


定义传感器类型标识。

**起始版本：** 2.2

| 枚举值 | 描述 | 
| -------- | -------- |
| HDF_SENSOR_TYPE_NONE | 空传感器类型，用于测试。 | 
| HDF_SENSOR_TYPE_ACCELEROMETER | 加速度传感器。 | 
| HDF_SENSOR_TYPE_GYROSCOPE | 陀螺仪传感器。 | 
| HDF_SENSOR_TYPE_PHOTOPLETHYSMOGRAPH | 心率传感器。 | 
| HDF_SENSOR_TYPE_ELECTROCARDIOGRAPH | 心电传感器。 | 
| HDF_SENSOR_TYPE_AMBIENT_LIGHT | 环境光传感器。 | 
| HDF_SENSOR_TYPE_MAGNETIC_FIELD | 地磁传感器。 | 
| HDF_SENSOR_TYPE_CAPACITIVE | 电容传感器。 | 
| HDF_SENSOR_TYPE_BAROMETER | 气压计传感器。 | 
| HDF_SENSOR_TYPE_TEMPERATURE | 温度传感器。 | 
| HDF_SENSOR_TYPE_HALL | 霍尔传感器。 | 
| HDF_SENSOR_TYPE_GESTURE | 手势传感器。 | 
| HDF_SENSOR_TYPE_PROXIMITY | 接近光传感器。 | 
| HDF_SENSOR_TYPE_HUMIDITY | 湿度传感器。 | 
| HDF_SENSOR_TYPE_MEDICAL_BEGIN | 医疗传感器ID枚举值范围的开始。 | 
| HDF_SENSOR_TYPE_MEDICAL_END | 医疗传感器ID枚举值范围的结束。 | 
| HDF_SENSOR_TYPE_PHYSICAL_MAX | 物理传感器最大类型。 | 
| HDF_SENSOR_TYPE_ORIENTATION | 方向传感器。 | 
| HDF_SENSOR_TYPE_GRAVITY | 重力传感器。 | 
| HDF_SENSOR_TYPE_LINEAR_ACCELERATION | 线性加速度传感器。 | 
| HDF_SENSOR_TYPE_ROTATION_VECTOR | 旋转矢量传感器。 | 
| HDF_SENSOR_TYPE_AMBIENT_TEMPERATURE | 环境温度传感器。 | 
| HDF_SENSOR_TYPE_MAGNETIC_FIELD_UNCALIBRATED | 未校准磁场传感器。 | 
| HDF_SENSOR_TYPE_GAME_ROTATION_VECTOR | 游戏旋转矢量传感器。 | 
| HDF_SENSOR_TYPE_GYROSCOPE_UNCALIBRATED | 未校准陀螺仪传感器。 | 
| HDF_SENSOR_TYPE_SIGNIFICANT_MOTION | 大幅度动作传感器。 | 
| HDF_SENSOR_TYPE_PEDOMETER_DETECTION | 计步器检测传感器。 | 
| HDF_SENSOR_TYPE_PEDOMETER | 计步器传感器。 | 
| HDF_SENSOR_TYPE_GEOMAGNETIC_ROTATION_VECTOR | 地磁旋转矢量传感器。 | 
| HDF_SENSOR_TYPE_HEART_RATE | 心率传感器。 | 
| HDF_SENSOR_TYPE_DEVICE_ORIENTATION | 设备方向传感器。 | 
| HDF_SENSOR_TYPE_WEAR_DETECTION | 佩戴检测传感器。 | 
| HDF_SENSOR_TYPE_ACCELEROMETER_UNCALIBRATED | 未校准加速度传感器。 | 
| HDF_SENSOR_TYPE_MAX | 传感器类型最大个数标识。 | 
