# SensorTypes.idl


## **概述**

定义传感器模块所使用的传感器类型，传感器信息，传感器数据结构等数据类型。

**Since:**

2.2

**Version:**

1.0

**相关模块:**

[Sensor](sensor.md)


## **汇总**


### 类

  | 名称 | 描述 | 
| -------- | -------- |
| [HdfSensorInformation](_hdf_sensor_information.md) | 定义传感器的基本信息。 | 
| [HdfSensorEvents](_hdf_sensor_events.md) | 定义传感器上报的数据。 | 


### 枚举

  | 名称 | 描述 | 
| -------- | -------- |
| [HdfSensorTypeTag](sensor.md#hdfsensortypetag)&nbsp;{&nbsp;&nbsp;&nbsp;HDF_SENSOR_TYPE_NONE&nbsp;=&nbsp;0,&nbsp;HDF_SENSOR_TYPE_ACCELEROMETER&nbsp;=&nbsp;1,&nbsp;HDF_SENSOR_TYPE_GYROSCOPE&nbsp;=&nbsp;2,&nbsp;HDF_SENSOR_TYPE_PHOTOPLETHYSMOGRAPH&nbsp;=&nbsp;3,&nbsp;&nbsp;&nbsp;HDF_SENSOR_TYPE_ELECTROCARDIOGRAPH&nbsp;=&nbsp;4,&nbsp;HDF_SENSOR_TYPE_AMBIENT_LIGHT&nbsp;=&nbsp;5,&nbsp;HDF_SENSOR_TYPE_MAGNETIC_FIELD&nbsp;=&nbsp;6,&nbsp;HDF_SENSOR_TYPE_CAPACITIVE&nbsp;=&nbsp;7,&nbsp;&nbsp;&nbsp;HDF_SENSOR_TYPE_BAROMETER&nbsp;=&nbsp;8,&nbsp;HDF_SENSOR_TYPE_TEMPERATURE&nbsp;=&nbsp;9,&nbsp;HDF_SENSOR_TYPE_HALL&nbsp;=&nbsp;10,&nbsp;HDF_SENSOR_TYPE_GESTURE&nbsp;=&nbsp;11,&nbsp;&nbsp;&nbsp;HDF_SENSOR_TYPE_PROXIMITY&nbsp;=&nbsp;12,&nbsp;HDF_SENSOR_TYPE_HUMIDITY&nbsp;=&nbsp;13,&nbsp;HDF_SENSOR_TYPE_MEDICAL_BEGIN&nbsp;=&nbsp;128,&nbsp;HDF_SENSOR_TYPE_MEDICAL_END&nbsp;=&nbsp;160,&nbsp;&nbsp;&nbsp;HDF_SENSOR_TYPE_PHYSICAL_MAX&nbsp;=&nbsp;255,&nbsp;HDF_SENSOR_TYPE_ORIENTATION&nbsp;=&nbsp;256,&nbsp;HDF_SENSOR_TYPE_GRAVITY&nbsp;=&nbsp;257,&nbsp;HDF_SENSOR_TYPE_LINEAR_ACCELERATION&nbsp;=&nbsp;258,&nbsp;&nbsp;&nbsp;HDF_SENSOR_TYPE_ROTATION_VECTOR&nbsp;=&nbsp;259,&nbsp;HDF_SENSOR_TYPE_AMBIENT_TEMPERATURE&nbsp;=&nbsp;260,&nbsp;HDF_SENSOR_TYPE_MAGNETIC_FIELD_UNCALIBRATED&nbsp;=&nbsp;261,&nbsp;HDF_SENSOR_TYPE_GAME_ROTATION_VECTOR&nbsp;=&nbsp;262,&nbsp;&nbsp;&nbsp;HDF_SENSOR_TYPE_GYROSCOPE_UNCALIBRATED&nbsp;=&nbsp;263,&nbsp;HDF_SENSOR_TYPE_SIGNIFICANT_MOTION&nbsp;=&nbsp;264,&nbsp;HDF_SENSOR_TYPE_PEDOMETER_DETECTION&nbsp;=&nbsp;265,&nbsp;HDF_SENSOR_TYPE_PEDOMETER&nbsp;=&nbsp;266,&nbsp;&nbsp;&nbsp;HDF_SENSOR_TYPE_GEOMAGNETIC_ROTATION_VECTOR&nbsp;=&nbsp;277,&nbsp;HDF_SENSOR_TYPE_HEART_RATE&nbsp;=&nbsp;278,&nbsp;HDF_SENSOR_TYPE_DEVICE_ORIENTATION&nbsp;=&nbsp;279,&nbsp;HDF_SENSOR_TYPE_WEAR_DETECTION&nbsp;=&nbsp;280,&nbsp;&nbsp;&nbsp;HDF_SENSOR_TYPE_ACCELEROMETER_UNCALIBRATED&nbsp;=&nbsp;281,&nbsp;HDF_SENSOR_TYPE_MAX&nbsp;} | 定义传感器类型标识。 | 
| [HdfSensorGroupType](sensor.md#hdfsensorgrouptype)&nbsp;{&nbsp;HDF_TRADITIONAL_SENSOR_TYPE&nbsp;=&nbsp;0,&nbsp;HDF_MEDICAL_SENSOR_TYPE&nbsp;=&nbsp;1,&nbsp;HDF_SENSOR_GROUP_TYPE_MAX&nbsp;} | 枚举传感器的硬件服务组。 | 
| [HdfSensorModeType](sensor.md#hdfsensormodetype)&nbsp;{&nbsp;&nbsp;&nbsp;SENSOR_MODE_DEFAULT&nbsp;=&nbsp;0,&nbsp;SENSOR_MODE_REALTIME&nbsp;=&nbsp;1,&nbsp;SENSOR_MODE_ON_CHANGE&nbsp;=&nbsp;2,&nbsp;SENSOR_MODE_ONE_SHOT&nbsp;=&nbsp;3,&nbsp;&nbsp;&nbsp;SENSOR_MODE_FIFO_MODE&nbsp;=&nbsp;4,&nbsp;SENSOR_MODE_MAX&nbsp;} | 传感器的工作模式。 | 


### 关键字

  | 名称 | 描述 | 
| -------- | -------- |
| package&nbsp;ohos.hdi.sensor.v1_0 | Sensor模块接口的包路径。 | 
