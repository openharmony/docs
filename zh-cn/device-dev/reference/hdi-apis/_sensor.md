# Sensor


## **汇总**


### 文件

| 文件 | 描述 |
| -------- | -------- |
| [sensor_if.h](sensor__if_8h.md) | Sensor模块对外通用的接口声明文件，提供获取传感器设备信息、订阅/取消订阅传感器数据、&nbsp;使能/去使能传感器、设置传感器模式、设置传感器精度，量程等可选配置接口定义。 |
| [sensor_type.h](sensor__type_8h.md) | 定义传感器模块所使用的传感器类型，传感器信息，传感器数据结构等数据类型。 |


### 类

| 类 | 描述 |
| -------- | -------- |
| [SensorInterface](_sensor_interface.md) | 提供sensor设备基本控制操作接口。&nbsp;[更多...](_sensor_interface.md) |
| [SensorInformation](_sensor_information.md) | 定义传感器基本信息。&nbsp;[更多...](_sensor_information.md) |
| [SensorEvents](_sensor_events.md) | 上报传感器数据结构。&nbsp;[更多...](_sensor_events.md) |


### 宏定义

| 宏定义 | 描述 |
| -------- | -------- |
| [SENSOR_NAME_MAX_LEN](#sensor_name_max_len)&nbsp;&nbsp;&nbsp;32 | Sensor名称的最大长度。 |
| [SENSOR_VERSION_MAX_LEN](#sensor_version_max_len)&nbsp;&nbsp;&nbsp;16 | Sensor版本号的最大长度。 |


### 类型定义

| 类型定义 | 描述 |
| -------- | -------- |
| ([RecordDataCallback](#recorddatacallback))&nbsp;(const&nbsp;struct&nbsp;[SensorEvents](_sensor_events.md)&nbsp;\*) | 传感器上报数据回调函数的定义，传感器服务用户在订阅传感器时，&nbsp;需要注册上报数据回调函数，传感器使能后，传感器服务用户可以接受到传感器数据，详见[SensorInterface](_sensor_interface.md)。&nbsp;[更多...](#recorddatacallback) |


### 枚举

| 枚举 | 描述 |
| -------- | -------- |
| [SensorStatus](#sensorstatus)&nbsp;{&nbsp;SENSOR_SUCCESS&nbsp;=&nbsp;0,&nbsp;SENSOR_FAILURE&nbsp;=&nbsp;-1,&nbsp;SENSOR_NOT_SUPPORT&nbsp;=&nbsp;-2,&nbsp;SENSOR_INVALID_PARAM&nbsp;=&nbsp;-3,&nbsp;&nbsp;&nbsp;SENSOR_INVALID_SERVICE&nbsp;=&nbsp;-4,&nbsp;SENSOR_NULL_PTR&nbsp;=&nbsp;-5&nbsp;} | 定义传感器模块返回值类型。&nbsp;[更多...](#sensorstatus) |
| [SensorTypeTag](#sensortypetag)&nbsp;{&nbsp;SENSOR_TYPE_NONE&nbsp;=&nbsp;0,&nbsp;SENSOR_TYPE_ACCELEROMETER&nbsp;=&nbsp;1,&nbsp;SENSOR_TYPE_GYROSCOPE&nbsp;=&nbsp;2,&nbsp;SENSOR_TYPE_PHOTOPLETHYSMOGRAPH&nbsp;=&nbsp;3,&nbsp;&nbsp;&nbsp;SENSOR_TYPE_ELECTROCARDIOGRAPH&nbsp;=&nbsp;4,&nbsp;SENSOR_TYPE_AMBIENT_LIGHT&nbsp;=&nbsp;5,&nbsp;SENSOR_TYPE_MAGNETIC_FIELD&nbsp;=&nbsp;6,&nbsp;SENSOR_TYPE_CAPACITIVE&nbsp;=&nbsp;7,&nbsp;&nbsp;&nbsp;SENSOR_TYPE_BAROMETER&nbsp;=&nbsp;8,&nbsp;SENSOR_TYPE_TEMPERATURE&nbsp;=&nbsp;9,&nbsp;SENSOR_TYPE_HALL&nbsp;=&nbsp;10,&nbsp;SENSOR_TYPE_GESTURE&nbsp;=&nbsp;11,&nbsp;&nbsp;&nbsp;SENSOR_TYPE_PROXIMITY&nbsp;=&nbsp;12,&nbsp;SENSOR_TYPE_HUMIDITY&nbsp;=&nbsp;13,&nbsp;SENSOR_TYPE_MEDICAL_BEGIN&nbsp;=&nbsp;128,&nbsp;SENSOR_TYPE_MEDICAL_END&nbsp;=&nbsp;160,&nbsp;&nbsp;&nbsp;SENSOR_TYPE_PHYSICAL_MAX&nbsp;=&nbsp;255,&nbsp;SENSOR_TYPE_ORIENTATION&nbsp;=&nbsp;256,&nbsp;SENSOR_TYPE_GRAVITY&nbsp;=&nbsp;257,&nbsp;SENSOR_TYPE_LINEAR_ACCELERATION&nbsp;=&nbsp;258,&nbsp;&nbsp;&nbsp;SENSOR_TYPE_ROTATION_VECTOR&nbsp;=&nbsp;259,&nbsp;SENSOR_TYPE_AMBIENT_TEMPERATURE&nbsp;=&nbsp;260,&nbsp;SENSOR_TYPE_MAGNETIC_FIELD_UNCALIBRATED&nbsp;=&nbsp;261,&nbsp;SENSOR_TYPE_GAME_ROTATION_VECTOR&nbsp;=&nbsp;262,&nbsp;&nbsp;&nbsp;SENSOR_TYPE_GYROSCOPE_UNCALIBRATED&nbsp;=&nbsp;263,&nbsp;SENSOR_TYPE_SIGNIFICANT_MOTION&nbsp;=&nbsp;264,&nbsp;SENSOR_TYPE_PEDOMETER_DETECTION&nbsp;=&nbsp;265,&nbsp;SENSOR_TYPE_PEDOMETER&nbsp;=&nbsp;266,&nbsp;&nbsp;&nbsp;SENSOR_TYPE_GEOMAGNETIC_ROTATION_VECTOR&nbsp;=&nbsp;277,&nbsp;SENSOR_TYPE_HEART_RATE&nbsp;=&nbsp;278,&nbsp;SENSOR_TYPE_DEVICE_ORIENTATION&nbsp;=&nbsp;279,&nbsp;SENSOR_TYPE_WEAR_DETECTION&nbsp;=&nbsp;280,&nbsp;&nbsp;&nbsp;SENSOR_TYPE_ACCELEROMETER_UNCALIBRATED&nbsp;=&nbsp;281,&nbsp;SENSOR_TYPE_MAX&nbsp;} | 定义传感器类型标识。&nbsp;[更多...](#sensortypetag) |
| [SensorAccuracyType](#sensoraccuracytype)&nbsp;{&nbsp;SENSOR_NO_ACCURACY&nbsp;=&nbsp;0,&nbsp;SENSOR_LOW_ACCURACY&nbsp;=&nbsp;1,&nbsp;SENSOR_MEDIUM_ACCURACY&nbsp;=&nbsp;2,&nbsp;SENSOR_HIGH_ACCURACY&nbsp;=&nbsp;3,&nbsp;&nbsp;&nbsp;SENSOR_MAX_ACCURACY&nbsp;} | 传感器的精度类型。&nbsp;[更多...](#sensoraccuracytype) |
| [SensorRangeType](#sensorrangetype)&nbsp;{&nbsp;SENSOR_RANGE_LEVEL1&nbsp;=&nbsp;0,&nbsp;SENSOR_RANGE_LEVEL2&nbsp;=&nbsp;1,&nbsp;SENSOR_RANGE_LEVEL3&nbsp;=&nbsp;2,&nbsp;SENSOR_RANGE_LEVEL_MAX&nbsp;} | 传感器的量程级别。&nbsp;[更多...](#sensorrangetype) |
| [SensorModeType](#sensormodetype)&nbsp;{&nbsp;SENSOR_MODE_DEFAULT&nbsp;=&nbsp;0,&nbsp;SENSOR_MODE_REALTIME&nbsp;=&nbsp;1,&nbsp;SENSOR_MODE_ON_CHANGE&nbsp;=&nbsp;2,&nbsp;SENSOR_MODE_ONE_SHOT&nbsp;=&nbsp;3,&nbsp;&nbsp;&nbsp;SENSOR_MODE_FIFO_MODE&nbsp;=&nbsp;4,&nbsp;SENSOR_MODE_MAX&nbsp;} | 传感器的工作模式。&nbsp;[更多...](#sensormodetype) |
| [SensorGroupType](#sensorgrouptype)&nbsp;{&nbsp;TRADITIONAL_SENSOR_TYPE&nbsp;=&nbsp;0,&nbsp;MEDICAL_SENSOR_TYPE&nbsp;=&nbsp;1,&nbsp;SENSOR_GROUP_TYPE_MAX&nbsp;} | 枚举传感器的硬件服务组。&nbsp;[更多...](#sensorgrouptype) |


### 函数

| 函数 | 描述 |
| -------- | -------- |
| [NewSensorInterfaceInstance](#newsensorinterfaceinstance)&nbsp;(void) | 创建传感器接口实例。&nbsp;[更多...](#newsensorinterfaceinstance) |
| [FreeSensorInterfaceInstance](#freesensorinterfaceinstance)&nbsp;(void) | 释放传感器接口实例。&nbsp;[更多...](#freesensorinterfaceinstance) |


## **详细描述**

传感器设备驱动对传感器服务提供通用的接口能力。

模块提供传感器服务对传感器驱动访问统一接口，服务获取驱动对象或者代理后， 通过其提供的各类方法，以传感器id区分访问不同类型传感器设备，实现获取传感器设备信息、订阅/取消订阅传感器数据、 使能/去使能传感器、设置传感器模式、设置传感器精度、量程等可选配置等。

**Since：**

2.2

**Version：**

1.0


## **宏定义说明**


### SENSOR_NAME_MAX_LEN


```
#define SENSOR_NAME_MAX_LEN   32
```

**描述：**

Sensor名称的最大长度。


### SENSOR_VERSION_MAX_LEN


```
#define SENSOR_VERSION_MAX_LEN  16
```

**描述：**

Sensor版本号的最大长度。


## **类型定义说明**


### RecordDataCallback


```
typedef int32_t(* RecordDataCallback) (const struct SensorEvents *)
```

**描述：**

传感器上报数据回调函数的定义，传感器服务用户在订阅传感器时， 需要注册上报数据回调函数，传感器使能后，传感器服务用户可以接受到传感器数据，详见[SensorInterface](_sensor_interface.md)。


## **枚举类型说明**


### SensorAccuracyType


```
enum SensorAccuracyType
```

**描述：**

传感器的精度类型。

| 枚举值 | 描述 |
| -------- | -------- |
| SENSOR_NO_ACCURACY | 无精度类型。 |
| SENSOR_LOW_ACCURACY | 低精度类型。 |
| SENSOR_MEDIUM_ACCURACY | 中等精度类型。 |
| SENSOR_HIGH_ACCURACY | 高精度类型。 |
| SENSOR_MAX_ACCURACY | 最大精度类型。 |


### SensorGroupType


```
enum SensorGroupType
```

**描述：**

枚举传感器的硬件服务组。

| 枚举值 | 描述 |
| -------- | -------- |
| TRADITIONAL_SENSOR_TYPE | 传统传感器类型，传感器ID枚举值范围为128-160。 |
| MEDICAL_SENSOR_TYPE | 医疗传感器类型，传感器ID枚举值范围不在128-160之间。 |
| SENSOR_GROUP_TYPE_MAX | 最大传感器类型。 |


### SensorModeType


```
enum SensorModeType
```

**描述：**

传感器的工作模式。

| 枚举值 | 描述 |
| -------- | -------- |
| SENSOR_MODE_DEFAULT | 传感器默认工作模式状态。 |
| SENSOR_MODE_REALTIME | 传感器实时工作模式状态，一组数据上报一次。 |
| SENSOR_MODE_ON_CHANGE | 传感器实时工作模式状态，状态变更上报一次。 |
| SENSOR_MODE_ONE_SHOT | 传感器实时工作模式状态，只上报一次。 |
| SENSOR_MODE_FIFO_MODE | 传感器缓存工作模式状态，根据配置的缓存大小上报。 |
| SENSOR_MODE_MAX | 传感器最大类型标识。 |


### SensorRangeType


```
enum SensorRangeType
```

**描述：**

传感器的量程级别。

| 枚举值 | 描述 |
| -------- | -------- |
| SENSOR_RANGE_LEVEL1 | 量程级别1。 |
| SENSOR_RANGE_LEVEL2 | 量程级别2。 |
| SENSOR_RANGE_LEVEL3 | 量程级别3。 |
| SENSOR_RANGE_LEVEL_MAX | 量程最大级别。 |


### SensorStatus


```
enum SensorStatus
```

**描述：**

定义传感器模块返回值类型。

| 枚举值 | 描述 |
| -------- | -------- |
| SENSOR_SUCCESS | 传感器执行成功。 |
| SENSOR_FAILURE | 传感器执行失败。 |
| SENSOR_NOT_SUPPORT | 传感器不支持。 |
| SENSOR_INVALID_PARAM | 传感器无效参数。 |
| SENSOR_INVALID_SERVICE | 传感器无效服务。 |
| SENSOR_NULL_PTR | 传感器空指针。 |


### SensorTypeTag


```
enum SensorTypeTag
```

**描述：**

定义传感器类型标识。

| 枚举值 | 描述 |
| -------- | -------- |
| SENSOR_TYPE_NONE | 空传感器类型，用于测试。 |
| SENSOR_TYPE_ACCELEROMETER | 加速度传感器。 |
| SENSOR_TYPE_GYROSCOPE | 陀螺仪传感器。 |
| SENSOR_TYPE_PHOTOPLETHYSMOGRAPH | 心率传感器。 |
| SENSOR_TYPE_ELECTROCARDIOGRAPH | 心电传感器。 |
| SENSOR_TYPE_AMBIENT_LIGHT | 环境光传感器。 |
| SENSOR_TYPE_MAGNETIC_FIELD | 地磁传感器。 |
| SENSOR_TYPE_CAPACITIVE | 电容传感器。 |
| SENSOR_TYPE_BAROMETER | 气压计传感器。 |
| SENSOR_TYPE_TEMPERATURE | 温度传感器。 |
| SENSOR_TYPE_HALL | 霍尔传感器。 |
| SENSOR_TYPE_GESTURE | 手势传感器。 |
| SENSOR_TYPE_PROXIMITY | 接近光传感器。 |
| SENSOR_TYPE_HUMIDITY | 湿度传感器。 |
| SENSOR_TYPE_MEDICAL_BEGIN | 医疗传感器ID枚举值范围的开始。 |
| SENSOR_TYPE_MEDICAL_END | 医疗传感器ID枚举值范围的结束。 |
| SENSOR_TYPE_PHYSICAL_MAX | 物理传感器最大类型。 |
| SENSOR_TYPE_ORIENTATION | 方向传感器。 |
| SENSOR_TYPE_GRAVITY | 重力传感器。 |
| SENSOR_TYPE_LINEAR_ACCELERATION | 线性加速度传感器。 |
| SENSOR_TYPE_ROTATION_VECTOR | 旋转矢量传感器。 |
| SENSOR_TYPE_AMBIENT_TEMPERATURE | 环境温度传感器 |
| SENSOR_TYPE_MAGNETIC_FIELD_UNCALIBRATED | 未校准磁场传感器。 |
| SENSOR_TYPE_GAME_ROTATION_VECTOR | 游戏旋转矢量传感器。 |
| SENSOR_TYPE_GYROSCOPE_UNCALIBRATED | 未校准陀螺仪传感器。 |
| SENSOR_TYPE_SIGNIFICANT_MOTION | 大幅度动作传感器。 |
| SENSOR_TYPE_PEDOMETER_DETECTION | 计步器检测传感器。 |
| SENSOR_TYPE_PEDOMETER | 计步器传感器。 |
| SENSOR_TYPE_GEOMAGNETIC_ROTATION_VECTOR | 地磁旋转矢量传感器。 |
| SENSOR_TYPE_HEART_RATE | 心率传感器。 |
| SENSOR_TYPE_DEVICE_ORIENTATION | 设备方向传感器。 |
| SENSOR_TYPE_WEAR_DETECTION | 佩戴检测传感器。 |
| SENSOR_TYPE_ACCELEROMETER_UNCALIBRATED | 未校准加速度传感器。 |
| SENSOR_TYPE_MAX | 传感器类型最大个数标识。 |


## **函数说明**


### FreeSensorInterfaceInstance()


```
int32_t FreeSensorInterfaceInstance (void )
```

**描述：**

释放传感器接口实例。

**返回：**

如果释放实例成功，则返回0。

如果释放实例失败，则返回负值。

**Since：**

2.2

**Version：**

1.0


### NewSensorInterfaceInstance()


```
const struct SensorInterface* NewSensorInterfaceInstance (void )
```

**描述：**

创建传感器接口实例。

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| sensorId | 表示传感器ID。有关详细信息，详见[SensorTypeTag](#sensortypetag)。 |
| cb | 表示要注册的回调函数。有关详细信息，详见[RecordDataCallback](#recorddatacallback)。 |

**返回：**

如果创建实例成功，则返回非零值。

如果创建实例失败，则返回负值。

**Since：**

2.2

**Version：**

1.0
