# Sensor


## 概述

提供API来使用常见的传感器特性。例如，调用API来获取传感器和订阅或取消订阅传感器数据。

提供标准的开放api，定义常用传感器属性。

**起始版本**：11


## 汇总


### 文件

| 名称 | 描述 |
| -------- | -------- |
| [oh_sensor.h](oh_sensor_8h.md) | 声明操作传感器的API，包括获取传感器信息和订阅取消订阅传感器数据。  |
| [oh_sensor_type.h](oh_sensor_type_8h.md) | 定义常用传感器属性。  |


### 类型定义

| 名称 | 描述 |
| -------- | -------- |
| [Sensor_Type](#sensor_type) | 枚举传感器类型。  |
| [Sensor_Result](#sensor_result) | 定义传感器错误码。  |
| [Sensor_Accuracy](#sensor_accuracy) | 枚举传感器上报的数据的精度级别。 |
| [Sensor_Info](#sensor_info) | 定义传感器信息。  |
| [Sensor_Event](#sensor_event) | 定义传感器数据信息。  |
| [Sensor_SubscriptionId](#sensor_subscriptionid) | 定义传感器订阅ID，唯一标识传感器。  |
| [Sensor_SubscriptionAttribute](#sensor_subscriptionattribute) | 定义传感器订阅属性。 |
| void ([*Sensor_EventCallback](#sensor_eventcallback)) ([Sensor_Event](#sensor_event) \*event) | 定义用于传感器数据的回调函数。 |
| [Sensor_Subscriber](#sensor_subscriber) | 定义传感器订阅者信息。  |


### 枚举

| 名称 | 描述 |
| -------- | -------- |
| [Sensor_Type](#sensor_type) {<br/>SENSOR_TYPE_ACCELEROMETER = 1, <br/>SENSOR_TYPE_GYROSCOPE = 2,<br/> SENSOR_TYPE_AMBIENT_LIGHT = 5, <br/>SENSOR_TYPE_MAGNETIC_FIELD = 6,<br/>SENSOR_TYPE_BAROMETER = 8,<br/> SENSOR_TYPE_HALL = 10, <br/>SENSOR_TYPE_PROXIMITY = 12,<br/> SENSOR_TYPE_ORIENTATION = 256,<br/>SENSOR_TYPE_GRAVITY = 257, <br/>SENSOR_TYPE_LINEAR_ACCELERATION = 258,<br/>SENSOR_TYPE_ROTATION_VECTOR = 259,<br/>SENSOR_TYPE_GAME_ROTATION_VECTOR = 262,<br/>SENSOR_TYPE_PEDOMETER_DETECTION = 265,<br/> SENSOR_TYPE_PEDOMETER = 266,<br/>SENSOR_TYPE_HEART_RATE = 278<br/>} | 枚举传感器类型。  |
| [Sensor_Result](#sensor_result) { <br/>SENSOR_SUCCESS = 0,<br/> SENSOR_PERMISSION_DENIED = 201, <br/>SENSOR_PARAMETER_ERROR = 401,<br/> SENSOR_SERVICE_EXCEPTION = 14500101<br/> } | 定义传感器错误码。  |
| [Sensor_Accuracy](#sensor_accuracy) { <br/>SENSOR_ACCURACY_UNRELIABLE = 0, <br/>SENSOR_ACCURACY_LOW = 1,<br/> SENSOR_ACCURACY_MEDIUM = 2, <br/>SENSOR_ACCURACY_HIGH = 3 <br/>} | 枚举传感器上报数据的精度级别。 |


### 函数

| 名称 | 描述 |
| -------- | -------- |
| [OH_Sensor_GetInfos](#oh_sensor_getinfos)([Sensor_Info](#sensor_info) **infos, uint32_t *count) | 获取设备上所有传感器的信息。                                 |
| [OH_Sensor_Subscribe](#oh_sensor_subscribe)(const [Sensor_SubscriptionId](#sensor_subscriptionid) *id, const [Sensor_SubscriptionAttribute](#sensor_subscriptionattribute) *attribute, const [Sensor_Subscriber](#sensor_subscriber) *subscriber) | 订阅传感器数据。系统将以指定的频率向用户上报传感器数据。<br/>订阅加速度传感器，需要申请ohos.permission.ACCELEROMETER权限；<br/>订阅陀螺仪传感器，需要申请ohos.permission.GYROSCOPE权限；<br/>订阅计步器相关传感器时，需要申请ohos.permission.ACTIVITY_MOTION权限；<br/>订阅与健康相关的传感器时，比如心率传感器需要申请ohos.permission.READ_HEALTH_DATA权限，否则订阅失败;<br/>订阅其余传感器不需要申请权限。 |
| [OH_Sensor_Unsubscribe](#oh_sensor_unsubscribe)(const [Sensor_SubscriptionId](#sensor_subscriptionid) *id, const [Sensor_Subscriber](#sensor_subscriber) *subscriber) | 取消订阅传感器数据。<br/>取消订阅加速度计传感器，需要申请ohos.permission.ACCELEROMETER权限； <br/>取消订阅陀螺仪传感器，需要申请ohos.permission.GYROSCOPE权限； <br/>取消订阅计步器相关传感器时，需要申请ohos.permission.ACTIVITY_MOTION权限；<br/>取消订阅与健康相关的传感器时，需要申请ohos.permission.READ_HEALTH_DATA权限，否则取消订阅失败。 <br/>取消订阅其余传感器不需要申请权限。 |
| [OH_Sensor_CreateInfos](#oh_sensor_createinfos)(uint32_t count) | 用给定的数字创建一个实例数组，请参考Sensor_Info](#sensor_info)。 |
| [OH_Sensor_DestroyInfos](#oh_sensor_destroyinfos)([Sensor_Info](#sensor_info) **sensors, uint32_t count) | 销毁实例数组并回收内存，请参考[Sensor_Info](#sensor_info)。 |
| [OH_SensorInfo_GetName](#oh_sensorinfo_getname)([Sensor_Info](#sensor_info) *sensor, char *sensorName, uint32_t *length) | 获取传感器名称。  |
| [OH_SensorInfo_GetVendorName](#oh_sensorinfo_getvendorname)([Sensor_Info](#sensor_info)* sensor, char *vendorName, uint32_t *length) | 获取传感器的厂商名称。  |
| [OH_SensorInfo_GetType](#oh_sensorinfo_gettype)([Sensor_Info](#sensor_info)* sensor, [Sensor_Type](#sensor_type) *sensorType) | 获取传感器类型。  |
| [OH_SensorInfo_GetResolution](#oh_sensorinfo_getresolution)([Sensor_Info](#sensor_info)* sensor, float *resolution) | 获取传感器分辨率。                                           |
| [OH_SensorInfo_GetMinSamplingInterval](#oh_sensorinfo_getminsamplinginterval)([Sensor_Info](#sensor_info)* sensor, int64_t *minSamplingInterval) | 获取传感器的最小数据上报间隔。  |
| [OH_SensorInfo_GetMaxSamplingInterval](#oh_sensorinfo_getmaxsamplinginterval)([Sensor_Info](#sensor_info)* sensor, int64_t *maxSamplingInterval) | 获取传感器的最大数据上报间隔时间。  |
| [OH_SensorEvent_GetType](#oh_sensorevent_gettype)([Sensor_Event](#sensor_event)* sensorEvent, [Sensor_Type](#sensor_type) *sensorType) | 获取传感器类型。  |
| [OH_SensorEvent_GetTimestamp](#oh_sensorevent_gettimestamp)([Sensor_Event](#sensor_event)* sensorEvent, int64_t *timestamp) | 获取传感器数据的时间戳。                                     |
| [OH_SensorEvent_GetAccuracy](#oh_sensorevent_getaccuracy)([Sensor_Event](#sensor_event)* sensorEvent, Sensor_Accuracy *accuracy) | 获取传感器数据的精度。                                       |
| [OH_SensorEvent_GetData](#oh_sensorevent_getdata)([Sensor_Event](#sensor_event)* sensorEvent, float **data, uint32_t *length) | 获取传感器数据。<br/>数据的长度和内容依赖于监听的传感器类型，传感器上报的数据格式如下：<br/>1.SENSOR_TYPE_ACCELEROMETER:data[0]、data[1]、data[2]分别表示设备x、y、z轴的加速度分量，单位m/s²；<br/>2.SENSOR_TYPE_GYROSCOPE:data[0]、data[1]、data[2]分别表示设备x、y、z轴的旋转角速度，单位弧度/s；<br/>3.SENSOR_TYPE_AMBIENT_LIGHT:data[0]表示环境光强度，单位lux；从API Version 12开始，将返回两个额外的数据，其中data[1]表示色温，单位kelvin；data[2]表示红外亮度，单位cd/m²；<br/>4. SENSOR_TYPE_MAGNETIC_FIELD:data[0]、data[1]、data[2]分别表示设备x、y、z轴的地磁分量，单位微特斯拉； <br/>5.SENSOR_TYPE_BAROMETER:data[0]表示气压值，单位hPa；<br/>6.SENSOR_TYPE_HALL:data[0]表示皮套吸合状态，0表示打开，大于0表示吸附；<br/>7.SENSOR_TYPE_PROXIMITY:data[0]表示接近状态，0表示接近，大于0表示远离；<br/>8.SENSOR_TYPE_ORIENTATION:data[0]、data[1]、data[2]分别表示设备绕z、x、y轴的角度，单位度；<br/>9.SENSOR_TYPE_GRAVITY:data[0]、data[1]、data[2]分别表示设备x、y、z轴的重力加速度分量，单位m/s²；<br/>10.SENSOR_TYPE_ROTATION_VECTOR:data[0]、data[1]、data[2]分别表示设备x、y、z轴的旋转角度，单位度，data[3]表示旋转向量元素；<br/>11.SENSOR_TYPE_PEDOMETER_DETECTION:data[0]表示计步检测状态，1表示检测到了步数变化；<br/>12.SENSOR_TYPE_PEDOMETER:data[0]表示步数；<br/>13.SENSOR_TYPE_HEART_RATE:data[0]表示心率数值；<br/>14.SENSOR_TYPE_LINEAR_ACCELERATION:从API Version 13开始支持，data[0]、data[1]、data[2]分别表示绕设备的x、y、z的线性加速度，单位m/s²；<br/>15.SENSOR_TYPE_GAME_ROTATION_VECTOR:从API Version 13开始支持，data[0]、data[1]、data[2]分别表示设备分别围绕x、y、z的旋转角度，单位为度，data[3]表示旋转向量。 |
| [OH_Sensor_CreateSubscriptionId](#oh_sensor_createsubscriptionid)(void) | 创建一个[Sensor_SubscriptionId](#sensor_subscriptionid)实例。 |
| [OH_Sensor_DestroySubscriptionId](#oh_sensor_destroysubscriptionid)([Sensor_SubscriptionId](#sensor_subscriptionid) *id) | 销毁[Sensor_SubscriptionId](#sensor_subscriptionid)实例并回收内存。 |
| [OH_SensorSubscriptionId_GetType](#oh_sensorsubscriptionid_gettype)([Sensor_SubscriptionId](#sensor_subscriptionid) *id, [Sensor_Type](#sensor_type) *sensorType) | 获取传感器类型。  |
| [OH_SensorSubscriptionId_SetType](#oh_sensorsubscriptionid_settype)([Sensor_SubscriptionId](#sensor_subscriptionid)* id, const [Sensor_Type](#sensor_type) sensorType) | 设置传感器类型。  |
| [OH_Sensor_CreateSubscriptionAttribute](#oh_sensor_createsubscriptionattribute)(void) | 创建[Sensor_SubscriptionAttribute](#sensor_subscriptionattribute)实例。 |
| [OH_Sensor_DestroySubscriptionAttribute](#oh_sensor_destroysubscriptionattribute)([Sensor_SubscriptionAttribute](#sensor_subscriptionattribute) *attribute) | 销毁[Sensor_SubscriptionAttribute](#sensor_subscriptionattribute)实例并回收内存。 |
| [OH_SensorSubscriptionAttribute_SetSamplingInterval](#oh_sensorsubscriptionattribute_setsamplinginterval)([Sensor_SubscriptionAttribute](#sensor_subscriptionattribute)* attribute, const int64_t samplingInterval) | 设置传感器数据上报间隔。                                  |
| [OH_SensorSubscriptionAttribute_GetSamplingInterval](#oh_sensorsubscriptionattribute_getsamplinginterval) ([Sensor_SubscriptionAttribute](#sensor_subscriptionattribute)* attribute, int64_t *samplingInterval) | 获取传感器数据上报间隔。                                   |
| [OH_Sensor_CreateSubscriber](#oh_sensor_createsubscriber)(void) | 创建一个[Sensor_Subscriber](#sensor_subscriber)实例。      |
| [OH_Sensor_DestroySubscriber](#oh_sensor_destroysubscriber)([Sensor_Subscriber](#sensor_subscriber) *subscriber) | 销毁[Sensor_Subscriber](#sensor_subscriber)实例并回收内存。 |
| [OH_SensorSubscriber_SetCallback](#oh_sensorsubscriber_setcallback)([Sensor_Subscriber](#sensor_subscriber)* subscriber, const [Sensor_EventCallback](#sensor_eventcallback) callback) | 设置一个回调函数来上报传感器数据。 |
| [OH_SensorSubscriber_GetCallback](#oh_sensorsubscriber_getcallback)([Sensor_Subscriber](#sensor_subscriber)* subscriber, [Sensor_EventCallback](#sensor_eventcallback) *callback) | 获取用于上报传感器数据的回调函数。 |


## 类型定义说明


### Sensor_Accuracy

```
typedef enum Sensor_Accuracy Sensor_Accuracy
```
**描述**：

枚举传感器上报的数据的精度级别。

**起始版本**：11


### Sensor_Event

```
typedef struct Sensor_Event Sensor_Event
```
**描述**：

定义传感器数据信息。

**起始版本**：11


### Sensor_EventCallback

```
typedef void(*Sensor_EventCallback)(Sensor_Event *event)
```
**描述**：

定义用于上报传感器数据的回调函数。

**起始版本**：11


### Sensor_Info

```
typedef struct Sensor_Info Sensor_Info
```
**描述**：

定义传感器信息。

**起始版本**：11


### Sensor_Result

```
typedef enum Sensor_Result Sensor_Result
```
**描述**：

定义传感器错误码。

**起始版本**：11


### Sensor_Subscriber

```
typedef struct Sensor_Subscriber Sensor_Subscriber
```
**描述**：

定义传感器订阅者信息。

**起始版本**：11


### Sensor_SubscriptionAttribute

```
typedef struct Sensor_SubscriptionAttribute Sensor_SubscriptionAttribute
```
**描述**：

定义传感器订阅属性。

**起始版本**：11


### Sensor_SubscriptionId

```
typedef struct Sensor_SubscriptionId Sensor_SubscriptionId
```
**描述**：

定义传感器订阅ID，唯一标识传感器。

**起始版本**：11


### Sensor_Type

```
typedef enum Sensor_Type Sensor_Type
```
**描述**：

枚举传感器类型。

**起始版本**：11


## 枚举类型说明


### Sensor_Accuracy

```
enum Sensor_Accuracy
```
**描述**：

枚举传感器上报的数据的精度级别。

**起始版本**：11

| 枚举值 | 描述 |
| -------- | -------- |
| SENSOR_ACCURACY_UNRELIABLE  | 传感器数据不可靠。有可能传感器不与设备接触而进行测量。 |
| SENSOR_ACCURACY_LOW  | 传感器数据精度较低。数据在使用前必须根据环境进行校准。 |
| SENSOR_ACCURACY_MEDIUM  | 传感器数据处于中等精度水平。建议用户在使用前根据实际环境进行数据校准。 |
| SENSOR_ACCURACY_HIGH  | 传感器数据具有很高的精度。数据可以直接使用。 |


### Sensor_Result

```
enum Sensor_Result
```
**描述**：

定义传感器错误码。

**起始版本**：11

| 枚举值 | 描述 |
| -------- | -------- |
| SENSOR_SUCCESS  | 操作成功。 |
| SENSOR_PERMISSION_DENIED  | 权限验证失败。 |
| SENSOR_PARAMETER_ERROR  | 参数检查失败。例如，没有传入强制参数，或者传入的参数类型不正确。 |
| SENSOR_SERVICE_EXCEPTION  | 传感器服务异常。 |


### Sensor_Type

```
enum Sensor_Type
```
**描述**：

枚举传感器类型。

**起始版本**：11

| 枚举值 | 描述 |
| -------- | -------- |
| SENSOR_TYPE_ACCELEROMETER  | 加速度传感器。 |
| SENSOR_TYPE_GYROSCOPE  | 陀螺仪传感器。 |
| SENSOR_TYPE_AMBIENT_LIGHT  | 环境光传感器。 |
| SENSOR_TYPE_MAGNETIC_FIELD  | 地磁传感器。 |
| SENSOR_TYPE_BAROMETER  | 气压传感器。 |
| SENSOR_TYPE_HALL  | 霍尔传感器。 |
| SENSOR_TYPE_PROXIMITY  | 接近光传感器。 |
| SENSOR_TYPE_ORIENTATION  | 方向传感器。 |
| SENSOR_TYPE_GRAVITY  | 重力传感器。 |
| SENSOR_TYPE_ROTATION_VECTOR  | 旋转矢量传感器。 |
| SENSOR_TYPE_PEDOMETER_DETECTION  | 计步器检测传感器。 |
| SENSOR_TYPE_PEDOMETER  | 计步器传感器。 |
| SENSOR_TYPE_HEART_RATE  | 心率传感器。 |


## 函数说明


### OH_Sensor_CreateInfos()

```
Sensor_Info **OH_Sensor_CreateInfos(uint32_t count)
```
**描述**：

用给定的数字创建一个实例数组，请参考 [Sensor_Info](#sensor_info)。

**起始版本**：11

**参数**：

| 名称 | 描述 |
| -------- | -------- |
| count | 要创建的实例的数量，请参考 [Sensor_Info](#sensor_info)。 |

**返回**：

如果操作成功，返回指向 [Sensor_Info](#sensor_info) 实例数组的双指针；否则返回**NULL**。


### OH_Sensor_CreateSubscriber()

```
Sensor_Subscriber *OH_Sensor_CreateSubscriber(void)
```
**描述**：

创建一个 [Sensor_Subscriber ](#sensor_subscriber)实例。

**起始版本**：11

**返回**：

如果操作成功，返回指向 [Sensor_Subscriber](#sensor_subscriber) 实例的指针；否则返回**NULL**。


### OH_Sensor_CreateSubscriptionAttribute()

```
Sensor_SubscriptionAttribute *OH_Sensor_CreateSubscriptionAttribute(void)
```
**描述**：

创建 [Sensor_SubscriptionAttribute ](#sensor_subscriptionattribute)实例。

**起始版本**：11

**返回**：

如果操作成功，返回指向 [Sensor_SubscriptionAttribute](#sensor_subscriptionattribute) 实例的指针；否则返回**NULL**。


### OH_Sensor_CreateSubscriptionId()

```
Sensor_SubscriptionId *OH_Sensor_CreateSubscriptionId(void)
```
**描述**：

创建一个 [Sensor_SubscriptionId](#sensor_subscriptionid) 实例。

**起始版本**：11

**返回**：

如果操作成功，返回指向 [Sensor_SubscriptionId](#sensor_subscriptionid) 实例的指针；否则返回**NULL**。


### OH_Sensor_DestroyInfos()

```
int32_t OH_Sensor_DestroyInfos(Sensor_Info **sensors, uint32_t count)
```
**描述**：

销毁实例数组并回收内存，请参考 [Sensor_Info](#sensor_info)。

**起始版本**：11

**参数**：

| 名称 | 描述 |
| -------- | -------- |
| sensors | 指向 [Sensor_Info](#sensor_info) 实例数组的双指针。 |
| count | 要销毁的 [Sensor_Info](#sensor_info) 实例的数量。 |

**返回**：

如果操作成功返回**SENSOR_SUCCESS**；否则返回 [Sensor_Result](#sensor_result) 中定义的错误代码。


### OH_Sensor_DestroySubscriber()

```
int32_t OH_Sensor_DestroySubscriber(Sensor_Subscriber *subscriber)
```
**描述**：

销毁 [Sensor_Subscriber ](#sensor_subscriber)实例并回收内存。

**起始版本**：11

**参数**：

| 名称 | 描述 |
| -------- | -------- |
| subscriber | 指向 [Sensor_Subscriber](#sensor_subscriber) 实例的指针。 |

**返回**：

如果操作成功返回**SENSOR_SUCCESS**；否则返回 [Sensor_Result](#sensor_result) 中定义的错误代码。


### OH_Sensor_DestroySubscriptionAttribute()

```
int32_t OH_Sensor_DestroySubscriptionAttribute(Sensor_SubscriptionAttribute *attribute)
```
**描述**：

销毁 [Sensor_SubscriptionAttribute](#sensor_subscriptionattribute) 实例并回收内存。

**起始版本**：11

**参数**：

| 名称 | 描述 |
| -------- | -------- |
| attribute | 指向 [Sensor_SubscriptionAttribute](#sensor_subscriptionattribute) 实例的指针。 |

**返回**：

如果操作成功返回**SENSOR_SUCCESS**；否则返回 [Sensor_Result](#sensor_result) 中定义的错误代码。


### OH_Sensor_DestroySubscriptionId()

```
int32_t OH_Sensor_DestroySubscriptionId(Sensor_SubscriptionId *id)
```
**描述**：

销毁 [Sensor_SubscriptionId](#sensor_subscriptionid) 实例并回收内存。

**起始版本**：11

**参数**：

| 名称 | 描述 |
| -------- | -------- |
| id | 指向 [Sensor_SubscriptionId](#sensor_subscriptionid) 实例的指针。 |

**返回**：

如果操作成功返回**SENSOR_SUCCESS**；否则返回 [Sensor_Result](#sensor_result) 中定义的错误代码。


### OH_Sensor_GetInfos()

```
Sensor_Result OH_Sensor_GetInfos(Sensor_Info **infos, uint32_t *count)
```
**描述**：

获取设备上所有传感器的信息。

**起始版本**：11

**参数**：

| 名称 | 描述 |
| -------- | -------- |
| infos | 双指针指向设备上所有传感器的信息。请参考 [Sensor_Info](#sensor_info)。 |
| count | 指向设备上传感器数量的指针。  |

**返回**：

如果操作成功返回**SENSOR_SUCCESS**；否则返回 [Sensor_Result](#sensor_result) 中定义的错误代码。


### OH_Sensor_Subscribe()

```
Sensor_Result OH_Sensor_Subscribe(const Sensor_SubscriptionId *id, const Sensor_SubscriptionAttribute *attribute, const Sensor_Subscriber *subscriber)
```
**描述**：

订阅传感器数据。系统将以指定的频率向用户上报传感器数据。 订阅加速度传感器，需要申请ohos.permission.ACCELEROMETER权限； 订阅陀螺仪传感器，需要申请ohos.permission.GYROSCOPE权限； 订阅计步器相关传感器时，需要申请ohos.permission.ACTIVITY_MOTION权限； 订阅与健康相关的传感器时，比如心率传感器，需要申请ohos.permission.READ_HEALTH_DATA权限，否则订阅失败。 订阅其余传感器不需要申请权限。

**起始版本**：11

**参数**：

| 名称 | 描述 |
| -------- | -------- |
| id | 指向传感器订阅ID的指针。请参考 [Sensor_SubscriptionId](#sensor_subscriptionid)。 |
| attribute | 指向订阅属性的指针，该属性用于指定数据报告频率。请参考 [Sensor_SubscriptionAttribute](#sensor_subscriptionattribute)。 |
| subscriber | 指向订阅者信息的指针，该信息用于指定的回调函数报告传感器数据。请参考 [Sensor_Subscriber](#sensor_subscriber)。 |

**返回**：

如果操作成功返回**SENSOR_SUCCESS**；否则返回 [Sensor_Result](#sensor_result) 中定义的错误代码。

**Permission**:

ohos.permission.ACCELEROMETER or ohos.permission.GYROSCOPE or ohos.permission.ACTIVITY_MOTION or ohos.permission.READ_HEALTH_DATA


### OH_Sensor_Unsubscribe()

```
Sensor_Result OH_Sensor_Unsubscribe(const Sensor_SubscriptionId *id, const Sensor_Subscriber *subscriber)
```
**描述**：

取消订阅传感器数据。 取消订阅加速度计传感器，需要申请ohos.permission.ACCELEROMETER权限； 取消订阅陀螺仪传感器，需要申请ohos.permission.GYROSCOPE权限； 取消订阅计步器相关传感器时，需要申请ohos.permission.ACTIVITY_MOTION权限； 取消订阅与健康相关的传感器时，需要申请ohos.permission.READ_HEALTH_DATA权限，否则取消订阅失败。 取消订阅其余传感器不需要申请权限。

**起始版本**：11

**参数**：

| 名称 | 描述 |
| -------- | -------- |
| id | 指向传感器订阅ID的指针。请参考 [Sensor_SubscriptionId](#sensor_subscriptionid)。 |
| subscriber | 指向订阅者信息的指针，该信息用于指定的回调函数报告传感器数据。请参考 [Sensor_Subscriber](#sensor_subscriber)。 |

**返回**：

如果操作成功返回**SENSOR_SUCCESS**；否则返回 [Sensor_Result](#sensor_result) 中定义的错误代码。

**Permission**:

ohos.permission.ACCELEROMETER or ohos.permission.GYROSCOPE or ohos.permission.ACTIVITY_MOTION or ohos.permission.READ_HEALTH_DATA


### OH_SensorEvent_GetAccuracy()

```
int32_t OH_SensorEvent_GetAccuracy(Sensor_Event* sensorEvent, Sensor_Accuracy *accuracy)
```
**描述**：

获取传感器数据的精度。

**起始版本**：11

**参数**：

| 名称 | 描述 |
| -------- | -------- |
| sensorEvent | 指向传感器数据信息的指针。  |
| accuracy | 指向精度的指针。  |

**返回**：

如果操作成功返回**SENSOR_SUCCESS**；否则返回 [Sensor_Result](#sensor_result) 中定义的错误代码。


### OH_SensorEvent_GetData()

```
int32_t OH_SensorEvent_GetData(Sensor_Event* sensorEvent, float **data, uint32_t *length)
```
**描述**：

获取传感器数据。数据的长度和内容依赖于监听的传感器类型，传感器上报的数据格式如下：

SENSOR_TYPE_ACCELEROMETER:data[0]、data[1]、data[2]分别表示设备x、y、z轴的加速度分量，单位m/s²；

SENSOR_TYPE_GYROSCOPE:data[0]、data[1]、data[2]分别表示设备x、y、z轴的旋转角速度，单位弧度/s；

SENSOR_TYPE_AMBIENT_LIGHT:data[0]表示环境光强度，in lux；

SENSOR_TYPE_MAGNETIC_FIELD:data[0]、data[1]、data[2]分别表示设备x、y、z轴的地磁分量，单位微特斯拉； 

SENSOR_TYPE_BAROMETER:data[0]表示气压值，单位hPa；

SENSOR_TYPE_HALL:data[0]表示皮套吸合状态，0表示打开，大于0表示吸附；

SENSOR_TYPE_PROXIMITY:data[0]表示接近状态，0表示接近，大于0表示远离；

SENSOR_TYPE_ORIENTATION:data[0]、data[1]、data[2]分别表示设备绕z、x、y轴的角度，单位度；

SENSOR_TYPE_GRAVITY:data[0]、data[1]、data[2]分别表示设备x、y、z轴的重力加速度分量，单位m/s²；

SENSOR_TYPE_ROTATION_VECTOR:data[0]、data[1]、data[2]分别表示设备x、y、z轴的旋转角度，单位度，data[3]表示旋转向量元素；

SENSOR_TYPE_PEDOMETER_DETECTION:data[0]表示计步检测状态，1表示检测到了步数变化；

SENSOR_TYPE_PEDOMETER:data[0]表示步数；

SENSOR_TYPE_HEART_RATE:data[0]表示心率数值；

SENSOR_TYPE_LINEAR_ACCELERATION:从API Version 13开始支持，data[0]、data[1]、data[2]分别表示绕设备的x、y、z的线性加速度，单位m/s²；

SENSOR_TYPE_GAME_ROTATION_VECTOR:从API Version 13开始支持，data[0]、data[1]、data[2]分别表示设备分别围绕x、y、z的旋转角度，单位为度，data[3]表示旋转向量。

**起始版本**：11

**参数**：

| 名称 | 描述 |
| -------- | -------- |
| sensorEvent | 传感器数据信息。  |
| data | 出参，传感器数据。  |
| length | 出参，数组长度。  |

**返回**：

如果操作成功返回**SENSOR_SUCCESS**；否则返回 [Sensor_Result](#sensor_result) 中定义的错误代码。


### OH_SensorEvent_GetTimestamp()

```
int32_t OH_SensorEvent_GetTimestamp(Sensor_Event* sensorEvent, int64_t *timestamp)
```
**描述**：

获取传感器数据的时间戳。

**起始版本**：11

**参数**：

| 名称 | 描述 |
| -------- | -------- |
| sensorEvent | 指向传感器数据信息的指针。  |
| timestamp | 时间戳指针。  |

**返回**：

如果操作成功返回**SENSOR_SUCCESS**；否则返回 [Sensor_Result](#sensor_result) 中定义的错误代码。


### OH_SensorEvent_GetType()

```
int32_t OH_SensorEvent_GetType(Sensor_Event* sensorEvent, Sensor_Type *sensorType)
```
**描述**：

获取传感器类型。

**起始版本**：11

**参数**：

| 名称 | 描述 |
| -------- | -------- |
| sensorEvent | 指向传感器数据信息的指针。  |
| sensorType | 指向传感器类型的指针。  |

**返回**：

如果操作成功返回**SENSOR_SUCCESS**；否则返回 [Sensor_Result](#sensor_result) 中定义的错误代码。


### OH_SensorInfo_GetMaxSamplingInterval()

```
int32_t OH_SensorInfo_GetMaxSamplingInterval(Sensor_Info* sensor, int64_t *maxSamplingInterval)
```
**描述**：

获取传感器的最大数据上报间隔时间。

**起始版本**：11

**参数**：

| 名称 | 描述 |
| -------- | -------- |
| sensor | 指向传感器信息的指针。  |
| maxSamplingInterval | 指向最大数据报告间隔的指针，单位为纳秒。  |

**返回**：

如果操作成功返回**SENSOR_SUCCESS**；否则返回 [Sensor_Result](#sensor_result) 中定义的错误代码。


### OH_SensorInfo_GetMinSamplingInterval()

```
int32_t OH_SensorInfo_GetMinSamplingInterval(Sensor_Info* sensor, int64_t *minSamplingInterval)
```
**描述**：

获取传感器的最小数据上报间隔。

**起始版本**：11

**参数**：

| 名称 | 描述 |
| -------- | -------- |
| sensor | 指向传感器信息的指针。  |
| minSamplingInterval | 指向最小数据报告间隔的指针，以纳秒为单位。  |

**返回**：

如果操作成功返回**SENSOR_SUCCESS**；否则返回 [Sensor_Result](#sensor_result) 中定义的错误代码。


### OH_SensorInfo_GetName()

```
int32_t OH_SensorInfo_GetName (Sensor_Info* sensor, char *sensorName, uint32_t *length)
```
**描述**：

获取传感器名称。

**起始版本**：11

**参数**：

| 名称 | 描述 |
| -------- | -------- |
| sensor | 指向传感器信息的指针。  |
| sensorName | 指向传感器名称的指针。  |
| length | 指向长度的指针，以字节为单位。  |

**返回**：

如果操作成功返回**SENSOR_SUCCESS**；否则返回 [Sensor_Result](#sensor_result) 中定义的错误代码。


### OH_SensorInfo_GetResolution()

```
int32_t OH_SensorInfo_GetResolution(Sensor_Info* sensor, float *resolution)
```
**描述**：

获取传感器分辨率。

**起始版本**：11

**参数**：

| 名称 | 描述 |
| -------- | -------- |
| sensor | 指向传感器信息的指针。  |
| resolution | 指向传感器分辨率的指针。  |

**返回**：

如果操作成功返回**SENSOR_SUCCESS**；否则返回 [Sensor_Result](#sensor_result) 中定义的错误代码。


### OH_SensorInfo_GetType()

```
int32_t OH_SensorInfo_GetType(Sensor_Info* sensor, Sensor_Type *sensorType)
```
**描述**：

获取传感器类型。

**起始版本**： 11

**参数**：

| 名称 | 描述 |
| -------- | -------- |
| sensor | 指向传感器信息的指针。  |
| sensorType | 指向传感器类型的指针。  |

**返回**：

如果操作成功返回**SENSOR_SUCCESS**；否则返回 [Sensor_Result](#sensor_result) 中定义的错误代码。


### OH_SensorInfo_GetVendorName()

```
int32_t OH_SensorInfo_GetVendorName(Sensor_Info* sensor, char *vendorName, uint32_t *length)
```
**描述**：

获取传感器的厂商名称。

**起始版本**：11

**参数**：

| 名称 | 描述 |
| -------- | -------- |
| sensor | 指向传感器信息的指针。  |
| vendorName | 指向供应商名称的指针。  |
| length | 指向长度的指针，以字节为单位。  |

**返回**：

如果操作成功返回**SENSOR_SUCCESS**；否则返回 [Sensor_Result](#sensor_result) 中定义的错误代码。


### OH_SensorSubscriber_GetCallback()

```
int32_t OH_SensorSubscriber_GetCallback(Sensor_Subscriber* subscriber, Sensor_EventCallback *callback)
```
**描述**：

获取用于上报传感器数据的回调函数。

**起始版本**：11

**参数**：

| 名称 | 描述 |
| -------- | -------- |
| subscriber | 指向传感器订阅者信息的指针。  |
| callback | 指向回调函数的指针。  |

**返回**：

如果操作成功返回**SENSOR_SUCCESS**；否则返回 [Sensor_Result](#sensor_result) 中定义的错误代码。


### OH_SensorSubscriber_SetCallback()

```
int32_t OH_SensorSubscriber_SetCallback (Sensor_Subscriber* subscriber, const Sensor_EventCallback callback )
```
**描述**：

设置一个回调函数来上报传感器数据。

**起始版本**：11

**参数**：

| 名称 | 描述 |
| -------- | -------- |
| subscriber | 指向传感器订阅者信息的指针。  |
| callback | 设置回调函数。  |

**返回**：

如果操作成功返回**SENSOR_SUCCESS**；否则返回 [Sensor_Result](#sensor_result) 中定义的错误代码。


### OH_SensorSubscriptionAttribute_GetSamplingInterval()

```
int32_t OH_SensorSubscriptionAttribute_GetSamplingInterval (Sensor_SubscriptionAttribute * attribute, int64_t * samplingInterval )
```
**描述**：

获取传感器数据上报间隔。

**起始版本**：11

**参数**：

| 名称 | 描述 |
| -------- | -------- |
| attribute | 指向传感器订阅属性的指针。  |
| samplingInterval | 指向数据报告间隔的指针，以纳秒为单位。  |

**返回**：

如果操作成功返回**SENSOR_SUCCESS**；否则返回 [Sensor_Result](#sensor_result) 中定义的错误代码。


### OH_SensorSubscriptionAttribute_SetSamplingInterval()

```
int32_t OH_SensorSubscriptionAttribute_SetSamplingInterval(Sensor_SubscriptionAttribute* attribute, const int64_t samplingInterval)
```
**描述**：

设置传感器数据上报间隔。

**起始版本**：11

**参数**：

| 名称 | 描述 |
| -------- | -------- |
| attribute | 指向传感器订阅属性的指针。  |
| samplingInterval | 要设置的数据报告间隔，以纳秒为单位。  |

**返回**：

如果操作成功返回**SENSOR_SUCCESS**；否则返回 [Sensor_Result](#sensor_result) 中定义的错误代码。


### OH_SensorSubscriptionId_GetType()

```
int32_t OH_SensorSubscriptionId_GetType(Sensor_SubscriptionId* id, Sensor_Type *sensorType)
```
**描述**：

获取传感器类型。

**起始版本**：11

**参数**：

| 名称 | 描述 |
| -------- | -------- |
| id | 指向传感器订阅ID的指针。  |
| sensorType | 指向传感器类型的指针。  |

**返回**：

如果操作成功返回**SENSOR_SUCCESS**；否则返回 [Sensor_Result](#sensor_result) 中定义的错误代码。


### OH_SensorSubscriptionId_SetType()

```
int32_t OH_SensorSubscriptionId_SetType(Sensor_SubscriptionId* id, const Sensor_Type sensorType)
```
**描述**：

设置传感器类型。

**起始版本**：11

**参数**：

| 名称 | 描述 |
| -------- | -------- |
| id | 指向传感器订阅ID的指针。  |
| sensorType | 要设置的传感器类型。  |

**返回**：

如果操作成功返回**SENSOR_SUCCESS**；否则返回 [Sensor_Result](#sensor_result) 中定义的错误代码。
