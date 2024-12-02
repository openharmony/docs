# oh_sensor_type.h


## 概述

定义常用传感器属性。

**库**：libohsensor.so

**系统能力**：SystemCapability.Sensors.Sensor

**起始版本**：11

**相关模块**：[Sensor](_sensor.md)


## 汇总


### 类型定义

| 名称 | 描述 |
| -------- | -------- |
| [Sensor_Type](_sensor.md#sensor_type) | 枚举传感器类型。  |
| [Sensor_Result](_sensor.md#sensor_result)                    | 定义传感器错误码。                 |
| [Sensor_Accuracy](_sensor.md#sensor_accuracy) | 枚举传感器上报数据的精度级别。  |
| [Sensor_Info](_sensor.md#sensor_info) | 定义传感器信息。  |
| [Sensor_Event](_sensor.md#sensor_event) | 定义传感器数据信息。  |
| [Sensor_SubscriptionId](_sensor.md#sensor_subscriptionid) | 定义传感器订阅ID，唯一标识传感器。  |
| [Sensor_SubscriptionAttribute](_sensor.md#sensor_subscriptionattribute) | 定义传感器订阅属性。  |
| void ([Sensor_EventCallback](_sensor.md#sensor_eventcallback)) ([Sensor_Event](_sensor.md#sensor_event) *event) | 定义用于上报传感器数据的回调函数。  |
| [Sensor_Subscriber](_sensor.md#sensor_subscriber) | 定义传感器订阅者信息。  |


### 枚举

| 名称 | 描述 |
| -------- | -------- |
| [Sensor_Type](_sensor.md#sensor_type) {<br/>SENSOR_TYPE_ACCELEROMETER = 1,<br/>SENSOR_TYPE_GYROSCOPE = 2, <br/>SENSOR_TYPE_AMBIENT_LIGHT = 5,<br/>SENSOR_TYPE_MAGNETIC_FIELD = 6,<br/>SENSOR_TYPE_BAROMETER = 8, <br/>SENSOR_TYPE_HALL = 10,<br/>SENSOR_TYPE_PROXIMITY = 12,<br/>SENSOR_TYPE_ORIENTATION = 256,<br/>SENSOR_TYPE_GRAVITY = 257, <br/>SENSOR_TYPE_ROTATION_VECTOR = 259,<br/>SENSOR_TYPE_PEDOMETER_DETECTION = 265, <br/>SENSOR_TYPE_PEDOMETER = 266,<br/>SENSOR_TYPE_HEART_RATE = 278<br/>} | 枚举传感器类型。  |
| [Sensor_Result](_sensor.md#sensor_result) {<br/>SENSOR_SUCCESS = 0, <br/>SENSOR_PERMISSION_DENIED = 201, <br/>SENSOR_PARAMETER_ERROR = 401, <br/>SENSOR_SERVICE_EXCEPTION = 14500101<br/>} | 定义传感器错误码。  |
| [Sensor_Accuracy](_sensor.md#sensor_accuracy) { <br/>SENSOR_ACCURACY_UNRELIABLE = 0,<br/>SENSOR_ACCURACY_LOW = 1, <br/>SENSOR_ACCURACY_MEDIUM = 2,<br/>SENSOR_ACCURACY_HIGH = 3<br/>} | 枚举传感器上报数据的精度级别。  |


### 函数

| 名称 | 描述 |
| -------- | -------- |
| [OH_Sensor_CreateInfos](_sensor.md#oh_sensor_createinfos)(uint32_t count) | 用给定的数字创建一个实例数组，请参考[Sensor_Info](_sensor.md#sensor_info)。 |
| [OH_Sensor_DestroyInfos](_sensor.md#oh_sensor_destroyinfos)([Sensor_Info](_sensor.md#sensor_info) **sensors, uint32_t count) | 销毁实例数组并回收内存，请参考[Sensor_Info](_sensor.md#sensor_info)。 |
| [OH_SensorInfo_GetName](_sensor.md#oh_sensorinfo_getname)([Sensor_Info](_sensor.md#sensor_info) *sensor, char *sensorName, uint32_t *length) | 获取传感器名称。                                             |
| [OH_SensorInfo_GetVendorName](_sensor.md#oh_sensorinfo_getvendorname)([Sensor_Info](_sensor.md#sensor_info) *sensor, char *vendorName, uint32_t *length) | 获取传感器的厂商名称。  |
| [OH_SensorInfo_GetType](_sensor.md#oh_sensorinfo_gettype)([Sensor_Info](_sensor.md#sensor_info) *sensor, | 获取传感器类型。                                             |
| [OH_SensorInfo_GetResolution](_sensor.md#oh_sensorinfo_getresolution) ([Sensor_Info](_sensor.md#sensor_info) *sensor, float *resolution) | 获取传感器分辨率。  |
| [OH_SensorInfo_GetMinSamplingInterval](_sensor.md#oh_sensorinfo_getminsamplinginterval) ([Sensor_Info](_sensor.md#sensor_info) *sensor, int64_t *minSamplingInterval) | 获取传感器的最小数据上报间隔。  |
| [OH_SensorInfo_GetMaxSamplingInterval](_sensor.md#oh_sensorinfo_getmaxsamplinginterval) ([Sensor_Info](_sensor.md#sensor_info) *sensor, int64_t *maxSamplingInterval) | 获取传感器的最大数据上报间隔时间。  |
| [OH_SensorEvent_GetType](_sensor.md#oh_sensorevent_gettype) ([Sensor_Event](_sensor.md#sensor_event) *sensorEvent, [Sensor_Type](_sensor.md#sensor_type) *sensorType) | 获取传感器类型。                                             |
| [OH_SensorEvent_GetTimestamp](_sensor.md#oh_sensorevent_gettimestamp) ([Sensor_Event](_sensor.md#sensor_event) *sensorEvent, int64_t *timestamp) | 获取传感器数据的时间戳。  |
| [OH_SensorEvent_GetAccuracy](_sensor.md#oh_sensorevent_getaccuracy) ([Sensor_Event](_sensor.md#sensor_event) *sensorEvent, [Sensor_Accuracy](_sensor.md#sensor_accuracy) *accuracy) | 获取传感器数据的精度。                                       |
| [OH_SensorEvent_GetData](_sensor.md#oh_sensorevent_getdata) ([Sensor_Event](_sensor.md#sensor_event) *sensorEvent, float **data, uint32_t *length) | 获取传感器数据。数据的长度和内容依赖于监听的传感器类型，传感器上报的数据格式如下： 1.SENSOR_TYPE_ACCELEROMETER:data[0]、data[1]、data[2]分别表示设备x、y、z轴的加速度分量，单位m/s²；<br/>2.SENSOR_TYPE_GYROSCOPE:data[0]、data[1]、data[2]分别表示设备x、y、z轴的旋转角速度，单位弧度/s；<br/>3.SENSOR_TYPE_AMBIENT_LIGHT:data[0]表示环境光强度，单位lux；从API Version 12开始，将返回两个额外的数据，其中data[1]表示色温，单位kelvin；data[2]表示红外亮度，单位cd/m²；<br/>4.SENSOR_TYPE_MAGNETIC_FIELD:data[0]、data[1]、data[2]分别表示设备x、y、z轴的地磁分量，单位微特斯拉；<br/>5.SENSOR_TYPE_BAROMETER:data[0]表示气压值，单位hPa；<br/>6.SENSOR_TYPE_HALL: data[0]表示皮套吸合状态，0表示打开，大于0表示吸附；<br/>7.SENSOR_TYPE_PROXIMITY:data[0]表示接近状态，0表示接近，大于0表示远离； 8.SENSOR_TYPE_ORIENTATION:data[0]、data[1]、data[2]分别表示设备绕z、x、y轴的角度，单位度；<br/>9.SENSOR_TYPE_GRAVITY:data[0]、data[1]、data[2]分别表示设备x、y、z轴的重力加速度分量，单位m/s²；<br/>10.SENSOR_TYPE_ROTATION_VECTOR:data[0]、data[1]、data[2]分别表示设备x、y、z轴的旋转角度，单位度，data[3]表示旋转向量元素；<br/>11.SENSOR_TYPE_PEDOMETER_DETECTION:data[0]表示几步检测状态，1表示检测到了步数变化；<br/>12.SENSOR_TYPE_PEDOMETER:data[0]表示步数；<br/>13.SENSOR_TYPE_HEART_RATE:data[0]表示心率数值。 |
| [OH_Sensor_CreateSubscriptionId](_sensor.md#oh_sensor_createsubscriptionid) (void) | 创建一个[Sensor_SubscriptionId](_sensor.md#sensor_subscriptionid)实例。  |
| [OH_Sensor_DestroySubscriptionId](_sensor.md#oh_sensor_destroysubscriptionid) ([Sensor_SubscriptionId](_sensor.md#sensor_subscriptionid) *id) | 销毁[Sensor_SubscriptionId](_sensor.md#sensor_subscriptionid)实例并回收内存。  |
| [OH_SensorSubscriptionId_GetType](_sensor.md#oh_sensorsubscriptionid_gettype) ([Sensor_SubscriptionId](_sensor.md#sensor_subscriptionid) *id, [Sensor_Type](_sensor.md#sensor_type) *sensorType) | 获取传感器类型。                                             |
| [OH_SensorSubscriptionId_SetType](_sensor.md#oh_sensorsubscriptionid_settype) ([Sensor_SubscriptionId](_sensor.md#sensor_subscriptionid) *id, const [Sensor_Type](_sensor.md#sensor_type) sensorType) | 设置传感器类型。  |
| [OH_Sensor_CreateSubscriptionAttribute](_sensor.md#oh_sensor_createsubscriptionattribute) (void) | 创建[Sensor_SubscriptionAttribute](_sensor.md#sensor_subscriptionattribute)实例。  |
| [OH_Sensor_DestroySubscriptionAttribute](_sensor.md#oh_sensor_destroysubscriptionattribute) ([Sensor_SubscriptionAttribute](_sensor.md#sensor_subscriptionattribute) *attribute) | 销毁[Sensor_SubscriptionAttribute](_sensor.md#sensor_subscriptionattribute)实例并回收内存。  |
| [OH_SensorSubscriptionAttribute_SetSamplingInterval](_sensor.md#oh_sensorsubscriptionattribute_setsamplinginterval) ([Sensor_SubscriptionAttribute](_sensor.md#sensor_subscriptionattribute) *attribute, const int64_t samplingInterval) | 设置传感器数据上报间隔。  |
| [OH_SensorSubscriptionAttribute_GetSamplingInterval](_sensor.md#oh_sensorsubscriptionattribute_getsamplinginterval) ([Sensor_SubscriptionAttribute](_sensor.md#sensor_subscriptionattribute) *attribute, int64_t *samplingInterval) | 获取传感器数据上报间隔。  |
| [OH_Sensor_CreateSubscriber](_sensor.md#oh_sensor_createsubscriber) (void) | 创建一个[Sensor_Subscriber](_sensor.md#sensor_subscriber)实例。 |
| [OH_Sensor_DestroySubscriber](_sensor.md#oh_sensor_destroysubscriber) ([Sensor_Subscriber](_sensor.md#sensor_subscriber) *subscriber) | 销毁[Sensor_Subscriber](_sensor.md#sensor_subscriber)实例并回收内存。  |
| [OH_SensorSubscriber_SetCallback](_sensor.md#oh_sensorsubscriber_setcallback) ([Sensor_Subscriber](_sensor.md#sensor_subscriber) *subscriber, const [Sensor_EventCallback](_sensor.md#sensor_eventcallback) callback) | 设置一个回调函数来上报传感器数据。  |
| [OH_SensorSubscriber_GetCallback](_sensor.md#oh_sensorsubscriber_getcallback) ([Sensor_Subscriber](_sensor.md#sensor_subscriber) *subscriber, [Sensor_EventCallback](_sensor.md#sensor_eventcallback) *callback) | 获取用于上报传感器数据的回调函数。                           |
