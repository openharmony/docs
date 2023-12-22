# oh_sensor_type.h


## 概述

定义常用传感器属性。

**库：** libohsensor.so

**系统能力：** SystemCapability.Sensors.Sensor

**起始版本：** 11

**相关模块：**[Sensor](_sensor.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| [Sensor_Type](_sensor.md#sensor_type) | typedef enum [Sensor_Type](_sensor.md#sensor_type)<br/>枚举传感器类型。  | 
| [Sensor_Result](_sensor.md#sensor_result) | typedef enum [Sensor_Result](_sensor.md#sensor_result)<br/>定义传感器错误码。  | 
| [Sensor_Accuracy](_sensor.md#sensor_accuracy) | typedef enum [Sensor_Accuracy](_sensor.md#sensor_accuracy)<br/>枚举传感器报告的数据的精度级别。  | 
| [Sensor_Info](_sensor.md#sensor_info) | typedef struct [Sensor_Info](_sensor.md#sensor_info)<br/>定义传感器信息。  | 
| [Sensor_Event](_sensor.md#sensor_event) | typedef struct [Sensor_Event](_sensor.md#sensor_event)<br/>定义传感器数据信息。  | 
| [Sensor_SubscriptionId](_sensor.md#sensor_subscriptionid) | typedef struct [Sensor_SubscriptionId](_sensor.md#sensor_subscriptionid)<br/>定义传感器订阅ID，唯一标识传感器。  | 
| [Sensor_SubscriptionAttribute](_sensor.md#sensor_subscriptionattribute) | typedef struct [Sensor_SubscriptionAttribute](_sensor.md#sensor_subscriptionattribute)<br/>定义传感器订阅属性。  | 
| [Sensor_EventCallback](_sensor.md#sensor_eventcallback)) ([Sensor_Event](_sensor.md#sensor_event) \*event) | typedef void(\*<br/>定义用于报告传感器数据的回调函数。  | 
| [Sensor_Subscriber](_sensor.md#sensor_subscriber) | typedef struct [Sensor_Subscriber](_sensor.md#sensor_subscriber)<br/>定义传感器订阅者信息。  | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [Sensor_Type](_sensor.md#sensor_type) {<br/>[SENSOR_TYPE_ACCELEROMETER](_sensor.md) = 1, [SENSOR_TYPE_GYROSCOPE](_sensor.md) = 2, [SENSOR_TYPE_AMBIENT_LIGHT](_sensor.md) = 5, [SENSOR_TYPE_MAGNETIC_FIELD](_sensor.md) = 6,<br/>[SENSOR_TYPE_BAROMETER](_sensor.md) = 8, [SENSOR_TYPE_HALL](_sensor.md) = 10, [SENSOR_TYPE_PROXIMITY](_sensor.md) = 12, [SENSOR_TYPE_ORIENTATION](_sensor.md) = 256,<br/>[SENSOR_TYPE_GRAVITY](_sensor.md) = 257, [SENSOR_TYPE_ROTATION_VECTOR](_sensor.md) = 259, [SENSOR_TYPE_PEDOMETER_DETECTION](_sensor.md) = 265, [SENSOR_TYPE_PEDOMETER](_sensor.md) = 266,<br/>[SENSOR_TYPE_HEART_RATE](_sensor.md) = 278<br/>} | 枚举传感器类型。  | 
| [Sensor_Result](_sensor.md#sensor_result) { [SENSOR_SUCCESS](_sensor.md) = 0, [SENSOR_PERMISSION_DENIED](_sensor.md) = 201, [SENSOR_PARAMETER_ERROR](_sensor.md) = 401, [SENSOR_SERVICE_EXCEPTION](_sensor.md) = 14500101 } | 定义传感器错误码。  | 
| [Sensor_Accuracy](_sensor.md#sensor_accuracy) { [SENSOR_ACCURACY_UNRELIABLE](_sensor.md) = 0, [SENSOR_ACCURACY_LOW](_sensor.md) = 1, [SENSOR_ACCURACY_MEDIUM](_sensor.md) = 2, [SENSOR_ACCURACY_HIGH](_sensor.md) = 3 } | 枚举传感器报告的数据的精度级别。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Sensor_CreateInfos](_sensor.md#oh_sensor_createinfos) (uint32_t count) | [Sensor_Info](_sensor.md#sensor_info) \*\*<br/>用给定的数字创建一个实例数组，请参考[Sensor_Info](_sensor.md#sensor_info)。  | 
| [OH_Sensor_DestroyInfos](_sensor.md#oh_sensor_destroyinfos) ([Sensor_Info](_sensor.md#sensor_info) \*\*sensors, uint32_t count) | int32_t<br/>销毁实例数组并回收内存，请参考[Sensor_Info](_sensor.md#sensor_info)。  | 
| [OH_SensorInfo_GetName](_sensor.md#oh_sensorinfo_getname) ([Sensor_Info](_sensor.md#sensor_info) \*sensor, char \*sensorName, uint32_t \*length) | int32_t<br/>获取传感器名称。  | 
| [OH_SensorInfo_GetVendorName](_sensor.md#oh_sensorinfo_getvendorname) ([Sensor_Info](_sensor.md#sensor_info) \*sensor, char \*vendorName, uint32_t \*length) | int32_t<br/>获取传感器的厂商名称。  | 
| [OH_SensorInfo_GetType](_sensor.md#oh_sensorinfo_gettype) ([Sensor_Info](_sensor.md#sensor_info) \*sensor, [Sensor_Type](_sensor.md#sensor_type) \*sensorType) | int32_t<br/>获取传感器类型。  | 
| [OH_SensorInfo_GetResolution](_sensor.md#oh_sensorinfo_getresolution) ([Sensor_Info](_sensor.md#sensor_info) \*sensor, float \*resolution) | int32_t<br/>获取传感器分辨率。  | 
| [OH_SensorInfo_GetMinSamplingInterval](_sensor.md#oh_sensorinfo_getminsamplinginterval) ([Sensor_Info](_sensor.md#sensor_info) \*sensor, int64_t \*minSamplingInterval) | int32_t<br/>获取传感器的最小数据上报间隔。  | 
| [OH_SensorInfo_GetMaxSamplingInterval](_sensor.md#oh_sensorinfo_getmaxsamplinginterval) ([Sensor_Info](_sensor.md#sensor_info) \*sensor, int64_t \*maxSamplingInterval) | int32_t<br/>获取传感器的最大数据上报间隔时间。  | 
| [OH_SensorEvent_GetType](_sensor.md#oh_sensorevent_gettype) ([Sensor_Event](_sensor.md#sensor_event) \*sensorEvent, [Sensor_Type](_sensor.md#sensor_type) \*sensorType) | int32_t<br/>获取传感器类型。  | 
| [OH_SensorEvent_GetTimestamp](_sensor.md#oh_sensorevent_gettimestamp) ([Sensor_Event](_sensor.md#sensor_event) \*sensorEvent, int64_t \*timestamp) | int32_t<br/>获取传感器数据的时间戳。  | 
| [OH_SensorEvent_GetAccuracy](_sensor.md#oh_sensorevent_getaccuracy) ([Sensor_Event](_sensor.md#sensor_event) \*sensorEvent, [Sensor_Accuracy](_sensor.md#sensor_accuracy) \*accuracy) | int32_t<br/>获取传感器数据的精度。  | 
| [OH_SensorEvent_GetData](_sensor.md#oh_sensorevent_getdata) ([Sensor_Event](_sensor.md#sensor_event) \*sensorEvent, float \*\*data, uint32_t \*length) | int32_t<br/>获取传感器数据。数据的长度和内容依赖于监听的传感器类型，传感器上报的数据格式如下： SENSOR_TYPE_ACCELEROMETER: data[0]、data[1]、data[2]分别表示设备x、y、z轴的加速度分量，单位m/s2； SENSOR_TYPE_GYROSCOPE: data[0]、data[1]、data[2]分别表示设备x、y、z轴的旋转角速度，单位弧度/s； SENSOR_TYPE_AMBIENT_LIGHT: data[0]表示环境光强度，in lux； SENSOR_TYPE_MAGNETIC_FIELD: data[0]、data[1]、data[2]分别表示设备x、y、z轴的地磁分量，单位微特斯拉； SENSOR_TYPE_BAROMETER：data[0]表示气压值，单位hPa； SENSOR_TYPE_HALL: data[0]表示皮套吸合状态，0表示打开，大于0表示吸附； SENSOR_TYPE_PROXIMITY：data[0]表示接近状态，0表示接近，大于0表示远离； SENSOR_TYPE_ORIENTATION:data[0]、data[1]、data[2]分别表示设备绕z、x、y轴的角度，单位度； SENSOR_TYPE_GRAVITY：data[0]、data[1]、data[2]分别表示设备x、y、z轴的重力加速度分量，单位m/s2； SENSOR_TYPE_ROTATION_VECTOR:data[0]、data[1]、data[2]分别表示设备x、y、z轴的旋转角度，单位度，data[3]表示旋转向量元素； SENSOR_TYPE_PEDOMETER_DETECTION:data[0]表示几步检测状态，1表示检测到了步数变化； SENSOR_TYPE_PEDOMETER:data[0]表示步数； SENSOR_TYPE_HEART_RATE：data[0]表示心率数值；  | 
| [OH_Sensor_CreateSubscriptionId](_sensor.md#oh_sensor_createsubscriptionid) (void) | [Sensor_SubscriptionId](_sensor.md#sensor_subscriptionid) \*<br/>创建一个[Sensor_SubscriptionId](_sensor.md#sensor_subscriptionid)实例。  | 
| [OH_Sensor_DestroySubscriptionId](_sensor.md#oh_sensor_destroysubscriptionid) ([Sensor_SubscriptionId](_sensor.md#sensor_subscriptionid) \*id) | int32_t<br/>销毁[Sensor_SubscriptionId](_sensor.md#sensor_subscriptionid)实例并回收内存。  | 
| [OH_SensorSubscriptionId_GetType](_sensor.md#oh_sensorsubscriptionid_gettype) ([Sensor_SubscriptionId](_sensor.md#sensor_subscriptionid) \*id, [Sensor_Type](_sensor.md#sensor_type) \*sensorType) | int32_t<br/>获取传感器类型。  | 
| [OH_SensorSubscriptionId_SetType](_sensor.md#oh_sensorsubscriptionid_settype) ([Sensor_SubscriptionId](_sensor.md#sensor_subscriptionid) \*id, const [Sensor_Type](_sensor.md#sensor_type) sensorType) | int32_t<br/>设置传感器类型。  | 
| [OH_Sensor_CreateSubscriptionAttribute](_sensor.md#oh_sensor_createsubscriptionattribute) (void) | [Sensor_SubscriptionAttribute](_sensor.md#sensor_subscriptionattribute) \*<br/>创建[Sensor_SubscriptionAttribute](_sensor.md#sensor_subscriptionattribute)实例。  | 
| [OH_Sensor_DestroySubscriptionAttribute](_sensor.md#oh_sensor_destroysubscriptionattribute) ([Sensor_SubscriptionAttribute](_sensor.md#sensor_subscriptionattribute) \*attribute) | int32_t<br/>销毁[Sensor_SubscriptionAttribute](_sensor.md#sensor_subscriptionattribute)实例并回收内存。  | 
| [OH_SensorSubscriptionAttribute_SetSamplingInterval](_sensor.md#oh_sensorsubscriptionattribute_setsamplinginterval) ([Sensor_SubscriptionAttribute](_sensor.md#sensor_subscriptionattribute) \*attribute, const int64_t samplingInterval) | int32_t<br/>设置传感器数据报告间隔。  | 
| [OH_SensorSubscriptionAttribute_GetSamplingInterval](_sensor.md#oh_sensorsubscriptionattribute_getsamplinginterval) ([Sensor_SubscriptionAttribute](_sensor.md#sensor_subscriptionattribute) \*attribute, int64_t \*samplingInterval) | int32_t<br/>获取传感器数据报告间隔。  | 
| [OH_Sensor_CreateSubscriber](_sensor.md#oh_sensor_createsubscriber) (void) | [Sensor_Subscriber](_sensor.md#sensor_subscriber) \*<br/>创建一个[Sensor_Subscriber](_sensor.md#sensor_subscriber)实例。  | 
| [OH_Sensor_DestroySubscriber](_sensor.md#oh_sensor_destroysubscriber) ([Sensor_Subscriber](_sensor.md#sensor_subscriber) \*subscriber) | int32_t<br/>销毁[Sensor_Subscriber](_sensor.md#sensor_subscriber)实例并回收内存。  | 
| [OH_SensorSubscriber_SetCallback](_sensor.md#oh_sensorsubscriber_setcallback) ([Sensor_Subscriber](_sensor.md#sensor_subscriber) \*subscriber, const [Sensor_EventCallback](_sensor.md#sensor_eventcallback) callback) | int32_t<br/>设置一个回调函数来报告传感器数据。  | 
| [OH_SensorSubscriber_GetCallback](_sensor.md#oh_sensorsubscriber_getcallback) ([Sensor_Subscriber](_sensor.md#sensor_subscriber) \*subscriber, [Sensor_EventCallback](_sensor.md#sensor_eventcallback) \*callback) | int32_t<br/>获取用于报告传感器数据的回调函数。  | 
