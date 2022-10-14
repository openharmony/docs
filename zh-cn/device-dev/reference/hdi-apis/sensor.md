# Sensor


## **概述**

传感器设备驱动对传感器服务提供通用的接口能力。

模块提供传感器服务对传感器驱动访问统一接口，服务获取驱动对象或者代理后，通过其提供的各类方法，以传感器ID区分访问不同类型传感器设备，实现获取传感器设备信息、订阅/取消订阅传感器数据、 使能/去使能传感器、设置传感器模式、设置传感器精度、量程等可选配置等。

**Since**:

2.2

**Version**:

1.0


## **汇总**


### 文件

  | 名称 | 描述 | 
| -------- | -------- |
| [ISensorCallback.idl](_i_sensor_callback_8idl.md) | Sensor模块为Sensor服务提供数据上报的回调函数。 | 
| [ISensorInterface.idl](_i_sensor_interface_8idl.md) | Sensor模块对外通用的接口声明文件，提供获取传感器设备信息、订阅/取消订阅传感器数据、使能/去使能传感器、设置传感器模式、设置传感器精度，量程等可选配置接口定义。 | 
| [SensorTypes.idl](_sensor_types_8idl.md) | 定义传感器模块所使用的传感器类型，传感器信息，传感器数据结构等数据类型。 | 


### 类

  | 名称 | 描述 | 
| -------- | -------- |
| [ISensorCallback](interface_i_sensor_callback.md) | 定义用于上报传感器数据的回调函数。 | 
| [ISensorInterface](interface_i_sensor_interface.md) | 提供Sensor设备基本控制操作接口。 | 
| [HdfSensorInformation](_hdf_sensor_information.md) | 定义传感器的基本信息。 | 
| [HdfSensorEvents](_hdf_sensor_events.md) | 定义传感器上报的数据。 | 


### 枚举

  | 名称 | 描述 | 
| -------- | -------- |
| [HdfSensorTypeTag](#hdfsensortypetag)&nbsp;{&nbsp;&nbsp;&nbsp;HDF_SENSOR_TYPE_NONE&nbsp;=&nbsp;0,&nbsp;HDF_SENSOR_TYPE_ACCELEROMETER&nbsp;=&nbsp;1,&nbsp;HDF_SENSOR_TYPE_GYROSCOPE&nbsp;=&nbsp;2,&nbsp;HDF_SENSOR_TYPE_PHOTOPLETHYSMOGRAPH&nbsp;=&nbsp;3,&nbsp;&nbsp;&nbsp;HDF_SENSOR_TYPE_ELECTROCARDIOGRAPH&nbsp;=&nbsp;4,&nbsp;HDF_SENSOR_TYPE_AMBIENT_LIGHT&nbsp;=&nbsp;5,&nbsp;HDF_SENSOR_TYPE_MAGNETIC_FIELD&nbsp;=&nbsp;6,&nbsp;HDF_SENSOR_TYPE_CAPACITIVE&nbsp;=&nbsp;7,&nbsp;&nbsp;&nbsp;HDF_SENSOR_TYPE_BAROMETER&nbsp;=&nbsp;8,&nbsp;HDF_SENSOR_TYPE_TEMPERATURE&nbsp;=&nbsp;9,&nbsp;HDF_SENSOR_TYPE_HALL&nbsp;=&nbsp;10,&nbsp;HDF_SENSOR_TYPE_GESTURE&nbsp;=&nbsp;11,&nbsp;&nbsp;&nbsp;HDF_SENSOR_TYPE_PROXIMITY&nbsp;=&nbsp;12,&nbsp;HDF_SENSOR_TYPE_HUMIDITY&nbsp;=&nbsp;13,&nbsp;HDF_SENSOR_TYPE_MEDICAL_BEGIN&nbsp;=&nbsp;128,&nbsp;HDF_SENSOR_TYPE_MEDICAL_END&nbsp;=&nbsp;160,&nbsp;&nbsp;&nbsp;HDF_SENSOR_TYPE_PHYSICAL_MAX&nbsp;=&nbsp;255,&nbsp;HDF_SENSOR_TYPE_ORIENTATION&nbsp;=&nbsp;256,&nbsp;HDF_SENSOR_TYPE_GRAVITY&nbsp;=&nbsp;257,&nbsp;HDF_SENSOR_TYPE_LINEAR_ACCELERATION&nbsp;=&nbsp;258,&nbsp;&nbsp;&nbsp;HDF_SENSOR_TYPE_ROTATION_VECTOR&nbsp;=&nbsp;259,&nbsp;HDF_SENSOR_TYPE_AMBIENT_TEMPERATURE&nbsp;=&nbsp;260,&nbsp;HDF_SENSOR_TYPE_MAGNETIC_FIELD_UNCALIBRATED&nbsp;=&nbsp;261,&nbsp;HDF_SENSOR_TYPE_GAME_ROTATION_VECTOR&nbsp;=&nbsp;262,&nbsp;&nbsp;&nbsp;HDF_SENSOR_TYPE_GYROSCOPE_UNCALIBRATED&nbsp;=&nbsp;263,&nbsp;HDF_SENSOR_TYPE_SIGNIFICANT_MOTION&nbsp;=&nbsp;264,&nbsp;HDF_SENSOR_TYPE_PEDOMETER_DETECTION&nbsp;=&nbsp;265,&nbsp;HDF_SENSOR_TYPE_PEDOMETER&nbsp;=&nbsp;266,&nbsp;&nbsp;&nbsp;HDF_SENSOR_TYPE_GEOMAGNETIC_ROTATION_VECTOR&nbsp;=&nbsp;277,&nbsp;HDF_SENSOR_TYPE_HEART_RATE&nbsp;=&nbsp;278,&nbsp;HDF_SENSOR_TYPE_DEVICE_ORIENTATION&nbsp;=&nbsp;279,&nbsp;HDF_SENSOR_TYPE_WEAR_DETECTION&nbsp;=&nbsp;280,&nbsp;&nbsp;&nbsp;HDF_SENSOR_TYPE_ACCELEROMETER_UNCALIBRATED&nbsp;=&nbsp;281,&nbsp;HDF_SENSOR_TYPE_MAX&nbsp;} | 定义传感器类型标识。 | 
| [HdfSensorGroupType](#hdfsensorgrouptype)&nbsp;{&nbsp;HDF_TRADITIONAL_SENSOR_TYPE&nbsp;=&nbsp;0,&nbsp;HDF_MEDICAL_SENSOR_TYPE&nbsp;=&nbsp;1,&nbsp;HDF_SENSOR_GROUP_TYPE_MAX&nbsp;} | 枚举传感器的硬件服务组。 | 
| [HdfSensorModeType](#hdfsensormodetype)&nbsp;{&nbsp;&nbsp;&nbsp;SENSOR_MODE_DEFAULT&nbsp;=&nbsp;0,&nbsp;SENSOR_MODE_REALTIME&nbsp;=&nbsp;1,&nbsp;SENSOR_MODE_ON_CHANGE&nbsp;=&nbsp;2,&nbsp;SENSOR_MODE_ONE_SHOT&nbsp;=&nbsp;3,&nbsp;&nbsp;&nbsp;SENSOR_MODE_FIFO_MODE&nbsp;=&nbsp;4,&nbsp;SENSOR_MODE_MAX&nbsp;} | 传感器的工作模式。 | 


### 关键字

  | 名称 | 描述 | 
| -------- | -------- |
| package&nbsp;ohos.hdi.sensor.v1_0 | Sensor模块接口的包路径。 | 


## **枚举类型说明**


### HdfSensorGroupType

  
```
enum HdfSensorGroupType
```

**描述：**

枚举传感器的硬件服务组。

  | 枚举值 | 描述 | 
| -------- | -------- |
| HDF_TRADITIONAL_SENSOR_TYPE | 传统传感器类型，传感器ID枚举值范围不在128-160之间。 | 
| HDF_MEDICAL_SENSOR_TYPE | 医疗传感器类型，传感器ID枚举值范围在128-160之间。 | 
| HDF_SENSOR_GROUP_TYPE_MAX | 最大传感器类型。 | 


### HdfSensorModeType

  
```
enum HdfSensorModeType
```

**描述：**

传感器的工作模式。

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

**描述：**

定义传感器类型标识。

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
