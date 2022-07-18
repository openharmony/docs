# sensor_type.h


## **概述**

**所属模块:**

[Sensor](_sensor.md)


## **汇总**


### 类

  | 类 | 描述 | 
| -------- | -------- |
| [SensorInformation](_sensor_information.md) | 定义传感器基本信息。&nbsp;[更多...](_sensor_information.md) | 
| [SensorEvents](_sensor_events.md) | 上报传感器数据结构。&nbsp;[更多...](_sensor_events.md) | 


### 宏定义

  | 宏定义 | 描述 | 
| -------- | -------- |
| [SENSOR_NAME_MAX_LEN](_sensor.md#sensornamemaxlen)&nbsp;&nbsp;&nbsp;32 | Sensor名称的最大长度 | 
| [SENSOR_VERSION_MAX_LEN](_sensor.md#sensorversionmaxlen)&nbsp;&nbsp;&nbsp;16 | Sensor版本号的最大长度 | 


### 类型定义

  | 类型定义 | 描述 | 
| -------- | -------- |
| ([RecordDataCallback](_sensor.md#recorddatacallback))&nbsp;(const&nbsp;struct&nbsp;[SensorEvents](_sensor_events.md)&nbsp;\*) | 传感器上报数据回调函数的定义，传感器服务用户在订阅传感器时，&nbsp;需要注册上报数据回调函数，传感器使能后，传感器服务用户可以接受到传感器数据，详见[SensorInterface](_sensor_interface.md)。&nbsp;[更多...](_sensor.md#recorddatacallback) | 


### 枚举

  | 枚举名称 | 描述 | 
| -------- | -------- |
| [SensorStatus](_sensor.md#sensorstatus)&nbsp;{&nbsp;SENSOR_SUCCESS&nbsp;=&nbsp;0,&nbsp;SENSOR_FAILURE&nbsp;=&nbsp;-1,&nbsp;SENSOR_NOT_SUPPORT&nbsp;=&nbsp;-2,&nbsp;SENSOR_INVALID_PARAM&nbsp;=&nbsp;-3,&nbsp;&nbsp;&nbsp;SENSOR_INVALID_SERVICE&nbsp;=&nbsp;-4,&nbsp;SENSOR_NULL_PTR&nbsp;=&nbsp;-5&nbsp;} | 定义传感器模块返回值类型。&nbsp;[更多...](_sensor.md#sensorstatus) | 
| [SensorTypeTag](_sensor.md#sensortypetag)&nbsp;{&nbsp;SENSOR_TYPE_NONE&nbsp;=&nbsp;0,&nbsp;SENSOR_TYPE_ACCELEROMETER&nbsp;=&nbsp;1,&nbsp;SENSOR_TYPE_GYROSCOPE&nbsp;=&nbsp;2,&nbsp;SENSOR_TYPE_PHOTOPLETHYSMOGRAPH&nbsp;=&nbsp;3,&nbsp;&nbsp;&nbsp;SENSOR_TYPE_ELECTROCARDIOGRAPH&nbsp;=&nbsp;4,&nbsp;SENSOR_TYPE_AMBIENT_LIGHT&nbsp;=&nbsp;5,&nbsp;SENSOR_TYPE_MAGNETIC_FIELD&nbsp;=&nbsp;6,&nbsp;SENSOR_TYPE_CAPACITIVE&nbsp;=&nbsp;7,&nbsp;&nbsp;&nbsp;SENSOR_TYPE_BAROMETER&nbsp;=&nbsp;8,&nbsp;SENSOR_TYPE_TEMPERATURE&nbsp;=&nbsp;9,&nbsp;SENSOR_TYPE_HALL&nbsp;=&nbsp;10,&nbsp;SENSOR_TYPE_GESTURE&nbsp;=&nbsp;11,&nbsp;&nbsp;&nbsp;SENSOR_TYPE_PROXIMITY&nbsp;=&nbsp;12,&nbsp;SENSOR_TYPE_HUMIDITY&nbsp;=&nbsp;13,&nbsp;SENSOR_TYPE_MEDICAL_BEGIN&nbsp;=&nbsp;128,&nbsp;SENSOR_TYPE_MEDICAL_END&nbsp;=&nbsp;160,&nbsp;&nbsp;&nbsp;SENSOR_TYPE_PHYSICAL_MAX&nbsp;=&nbsp;255,&nbsp;SENSOR_TYPE_ORIENTATION&nbsp;=&nbsp;256,&nbsp;SENSOR_TYPE_GRAVITY&nbsp;=&nbsp;257,&nbsp;SENSOR_TYPE_LINEAR_ACCELERATION&nbsp;=&nbsp;258,&nbsp;&nbsp;&nbsp;SENSOR_TYPE_ROTATION_VECTOR&nbsp;=&nbsp;259,&nbsp;SENSOR_TYPE_AMBIENT_TEMPERATURE&nbsp;=&nbsp;260,&nbsp;SENSOR_TYPE_MAGNETIC_FIELD_UNCALIBRATED&nbsp;=&nbsp;261,&nbsp;SENSOR_TYPE_GAME_ROTATION_VECTOR&nbsp;=&nbsp;262,&nbsp;&nbsp;&nbsp;SENSOR_TYPE_GYROSCOPE_UNCALIBRATED&nbsp;=&nbsp;263,&nbsp;SENSOR_TYPE_SIGNIFICANT_MOTION&nbsp;=&nbsp;264,&nbsp;SENSOR_TYPE_PEDOMETER_DETECTION&nbsp;=&nbsp;265,&nbsp;SENSOR_TYPE_PEDOMETER&nbsp;=&nbsp;266,&nbsp;&nbsp;&nbsp;SENSOR_TYPE_GEOMAGNETIC_ROTATION_VECTOR&nbsp;=&nbsp;277,&nbsp;SENSOR_TYPE_HEART_RATE&nbsp;=&nbsp;278,&nbsp;SENSOR_TYPE_DEVICE_ORIENTATION&nbsp;=&nbsp;279,&nbsp;SENSOR_TYPE_WEAR_DETECTION&nbsp;=&nbsp;280,&nbsp;&nbsp;&nbsp;SENSOR_TYPE_ACCELEROMETER_UNCALIBRATED&nbsp;=&nbsp;281,&nbsp;SENSOR_TYPE_MAX&nbsp;} | 定义传感器类型标识。&nbsp;[更多...](_sensor.md#sensortypetag) | 
| [SensorAccuracyType](_sensor.md#sensoraccuracytype)&nbsp;{&nbsp;SENSOR_NO_ACCURACY&nbsp;=&nbsp;0,&nbsp;SENSOR_LOW_ACCURACY&nbsp;=&nbsp;1,&nbsp;SENSOR_MEDIUM_ACCURACY&nbsp;=&nbsp;2,&nbsp;SENSOR_HIGH_ACCURACY&nbsp;=&nbsp;3,&nbsp;&nbsp;&nbsp;SENSOR_MAX_ACCURACY&nbsp;} | 传感器的精度类型。&nbsp;[更多...](_sensor.md#sensoraccuracytype) | 
| [SensorRangeType](_sensor.md#sensorrangetype)&nbsp;{&nbsp;SENSOR_RANGE_LEVEL1&nbsp;=&nbsp;0,&nbsp;SENSOR_RANGE_LEVEL2&nbsp;=&nbsp;1,&nbsp;SENSOR_RANGE_LEVEL3&nbsp;=&nbsp;2,&nbsp;SENSOR_RANGE_LEVEL_MAX&nbsp;} | 传感器的量程级别。&nbsp;[更多...](_sensor.md#sensorrangetype) | 
| [SensorModeType](_sensor.md#sensormodetype)&nbsp;{&nbsp;SENSOR_MODE_DEFAULT&nbsp;=&nbsp;0,&nbsp;SENSOR_MODE_REALTIME&nbsp;=&nbsp;1,&nbsp;SENSOR_MODE_ON_CHANGE&nbsp;=&nbsp;2,&nbsp;SENSOR_MODE_ONE_SHOT&nbsp;=&nbsp;3,&nbsp;&nbsp;&nbsp;SENSOR_MODE_FIFO_MODE&nbsp;=&nbsp;4,&nbsp;SENSOR_MODE_MAX&nbsp;} | 传感器的工作模式。&nbsp;[更多...](_sensor.md#sensormodetype) | 
| [SensorGroupType](_sensor.md#sensorgrouptype)&nbsp;{&nbsp;TRADITIONAL_SENSOR_TYPE&nbsp;=&nbsp;0,&nbsp;MEDICAL_SENSOR_TYPE&nbsp;=&nbsp;1,&nbsp;SENSOR_GROUP_TYPE_MAX&nbsp;} | 枚举传感器的硬件服务组。&nbsp;[更多...](_sensor.md#sensorgrouptype) | 


## **详细描述**

定义传感器模块所使用的传感器类型，传感器信息，传感器数据结构等数据类型。

**Since：**

2.2

**Version：**

1.0
