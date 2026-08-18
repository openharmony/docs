# oh_sensor_type.h
<!--Kit: Sensor Service Kit-->
<!--Subsystem: Sensors-->
<!--Owner: @dilligencer-->
<!--Designer: @andeszhang-->
<!--Tester: @zhaofangyuan-->
<!--Adviser: @hu-zhiqiong-->

## 概述

定义常用传感器属性。

**引用文件：** <sensors/oh_sensor_type.h>

**库：** libohsensor.so

**系统能力：** SystemCapability.Sensors.Sensor

**起始版本：** 11

**相关模块：** [Sensor](capi-sensor.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [Sensor_Info](capi-sensor-sensor-info.md) | Sensor_Info | 定义传感器信息。 |
| [Sensor_Event](capi-sensor-sensor-event.md) | Sensor_Event | 定义传感器数据信息。 |
| [Sensor_SubscriptionId](capi-sensor-sensor-subscriptionid.md) | Sensor_SubscriptionId | 定义传感器订阅ID，唯一标识传感器。 |
| [Sensor_SubscriptionAttribute](capi-sensor-sensor-subscriptionattribute.md) | Sensor_SubscriptionAttribute | 定义传感器订阅属性。 |
| [Sensor_Subscriber](capi-sensor-sensor-subscriber.md) | Sensor_Subscriber | 定义传感器订阅者信息。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [Sensor_Type](#sensor_type) | Sensor_Type | 枚举传感器类型。 |
| [Sensor_Result](#sensor_result) | Sensor_Result | 定义传感器错误码。 |
| [Sensor_Accuracy](#sensor_accuracy) | Sensor_Accuracy | 枚举传感器报告的数据的精度级别。 |

### 函数

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [Sensor_Info **OH_Sensor_CreateInfos(uint32_t count)](#oh_sensor_createinfos) | - | 用给定的数字创建一个实例数组，请参考[Sensor_Info](capi-sensor-sensor-info.md)。创建成功后，返回指向count个Sensor_Info实例的指针数组。 |
| [int32_t OH_Sensor_DestroyInfos(Sensor_Info **sensors, uint32_t count)](#oh_sensor_destroyinfos) | - | 销毁实例数组并回收内存，请参考[Sensor_Info](capi-sensor-sensor-info.md)。调用成功后，实例数组占用的内存被释放，sensors指针及其指向的所有Sensor_Info实例不能再使用。 |
| [int32_t OH_SensorInfo_GetName(Sensor_Info* sensor, char *sensorName, uint32_t *length)](#oh_sensorinfo_getname) | - | 获取传感器名称。获取成功后，sensorName参数中会填充传感器名称的字符串，length参数中会返回字符串的长度（包含结束符）。 |
| [int32_t OH_SensorInfo_GetVendorName(Sensor_Info* sensor, char *vendorName, uint32_t *length)](#oh_sensorinfo_getvendorname) | - | 获取传感器的厂商名称。获取成功后，vendorName参数中会填充传感器厂商名称的字符串，length参数中会返回字符串的长度（包含结束符）。 |
| [int32_t OH_SensorInfo_GetType(Sensor_Info* sensor, Sensor_Type *sensorType)](#oh_sensorinfo_gettype) | - | 获取[Sensor_Type](capi-oh-sensor-type-h.md#sensor_type)。获取成功后，sensorType参数中会填充传感器的类型值。 |
| [int32_t OH_SensorInfo_GetResolution(Sensor_Info* sensor, float *resolution)](#oh_sensorinfo_getresolution) | - | 获取传感器分辨率。获取成功后，resolution参数中会填充传感器的分辨率值。 |
| [int32_t OH_SensorInfo_GetMinSamplingInterval(Sensor_Info* sensor, int64_t *minSamplingInterval)](#oh_sensorinfo_getminsamplinginterval) | - | 获取传感器的最小数据上报间隔。获取成功后，minSamplingInterval参数中会填充传感器的最小数据上报间隔值，单位：ns（纳秒）。 |
| [int32_t OH_SensorInfo_GetMaxSamplingInterval(Sensor_Info* sensor, int64_t *maxSamplingInterval)](#oh_sensorinfo_getmaxsamplinginterval) | - | 获取传感器的最大数据上报间隔。获取成功后，maxSamplingInterval参数中会填充传感器的最大数据上报间隔值，单位：ns（纳秒）。 |
| [int32_t OH_SensorEvent_GetType(Sensor_Event* sensorEvent, Sensor_Type *sensorType)](#oh_sensorevent_gettype) | - | 获取传感器类型。 |
| [int32_t OH_SensorEvent_GetTimestamp(Sensor_Event* sensorEvent, int64_t *timestamp)](#oh_sensorevent_gettimestamp) | - | 获取传感器数据的时间戳。 |
| [int32_t OH_SensorEvent_GetAccuracy(Sensor_Event* sensorEvent, Sensor_Accuracy *accuracy)](#oh_sensorevent_getaccuracy) | - | 获取传感器数据的精度。 |
| [int32_t OH_SensorEvent_GetData(Sensor_Event* sensorEvent, float **data, uint32_t *length)](#oh_sensorevent_getdata) | - | 数据的长度和内容依赖于监听的传感器类型，传感器上报的数据格式如下所示：SENSOR_TYPE_ACCELEROMETER:  data[0]、data[1]、data[2]分别表示设备x、y、z轴的加速度分量，单位：m/s²。SENSOR_TYPE_GYROSCOPE: data[0]、data[1]、data[2]分别表示设备x、y、z轴的旋转角速度，单位：rad/s（弧度/秒）。SENSOR_TYPE_AMBIENT_LIGHT: data[0]表示环境光强度，单位：lux（勒克斯）；从API version 12开始，data[1]表示色温，单位：K（开尔文）；data[2]表示红外亮度，单位：cd/m²（坎德拉每平方米）。SENSOR_TYPE_MAGNETIC_FIELD: data[0]、data[1]、data[2]分别表示设备x、y、z轴的地磁分量，单位：μT（微特斯拉）。SENSOR_TYPE_BAROMETER：data[0]表示气压值，单位：hPa（百帕）。SENSOR_TYPE_HALL: data[0]表示皮套吸合状态，0表示打开，大于0表示吸附。SENSOR_TYPE_PROXIMITY：data[0]表示接近状态，0表示接近，大于0表示远离。SENSOR_TYPE_ORIENTATION:data[0]、data[1]、data[2]分别表示设备绕z、x、y轴的角度，单位：°（度）。SENSOR_TYPE_GRAVITY：data[0]、data[1]、data[2]分别表示设备x、y、z轴的重力加速度分量，单位：m/s²。SENSOR_TYPE_ROTATION_VECTOR:data[0]、data[1]、data[2]分别表示设备x、y、z轴的旋转角度，单位：°（度）；data[3]表示旋转向量元素。SENSOR_TYPE_PEDOMETER_DETECTION:data[0]表示步数检测状态，1表示检测到了步数变化。SENSOR_TYPE_PEDOMETER:data[0]表示步数。SENSOR_TYPE_HEART_RATE：data[0]表示心率数值。SENSOR_TYPE_LINEAR_ACCELERATION：从API version 13开始支持。data[0]、data[1]、data[2]分别表示设备x、y、z轴的线性加速度，单位：m/s²。SENSOR_TYPE_GAME_ROTATION_VECTOR：从API version 13开始支持。data[0]、data[1]、data[2]分别表示设备x、y、z轴的旋转角度，单位：°（度）；data[3]表示旋转向量。 |
| [Sensor_SubscriptionId *OH_Sensor_CreateSubscriptionId(void)](#oh_sensor_createsubscriptionid) | - | 创建一个[Sensor_SubscriptionId](capi-sensor-sensor-subscriptionid.md)实例。 |
| [int32_t OH_Sensor_DestroySubscriptionId(Sensor_SubscriptionId *id)](#oh_sensor_destroysubscriptionid) | - | 销毁[Sensor_SubscriptionId](capi-sensor-sensor-subscriptionid.md)实例并回收内存。 |
| [int32_t OH_SensorSubscriptionId_GetType(Sensor_SubscriptionId* id, Sensor_Type *sensorType)](#oh_sensorsubscriptionid_gettype) | - | 获取传感器类型。 |
| [int32_t OH_SensorSubscriptionId_SetType(Sensor_SubscriptionId* id, const Sensor_Type sensorType)](#oh_sensorsubscriptionid_settype) | - | 设置传感器类型。调用成功后，订阅ID的类型被设置为指定的sensorType值。 |
| [Sensor_SubscriptionAttribute *OH_Sensor_CreateSubscriptionAttribute(void)](#oh_sensor_createsubscriptionattribute) | - | 创建[Sensor_SubscriptionAttribute](capi-sensor-sensor-subscriptionattribute.md)实例。 |
| [int32_t OH_Sensor_DestroySubscriptionAttribute(Sensor_SubscriptionAttribute *attribute)](#oh_sensor_destroysubscriptionattribute) | - | 销毁[Sensor_SubscriptionAttribute](capi-sensor-sensor-subscriptionattribute.md)实例并回收内存。 |
| [int32_t OH_SensorSubscriptionAttribute_SetSamplingInterval(Sensor_SubscriptionAttribute* attribute, const int64_t samplingInterval)](#oh_sensorsubscriptionattribute_setsamplinginterval) | - | 设置传感器数据报告间隔。调用成功后，订阅属性的采样间隔被设置为指定的samplingInterval值，后续传感器数据上报将按照此间隔进行。 |
| [int32_t OH_SensorSubscriptionAttribute_GetSamplingInterval(Sensor_SubscriptionAttribute* attribute, int64_t *samplingInterval)](#oh_sensorsubscriptionattribute_getsamplinginterval) | - | 获取传感器数据报告间隔。 |
| [typedef void (\*Sensor_EventCallback)(Sensor_Event *event)](#sensor_eventcallback) | Sensor_EventCallback | 定义用于报告传感器数据的回调函数。 |
| [Sensor_Subscriber *OH_Sensor_CreateSubscriber(void)](#oh_sensor_createsubscriber) | - | 创建一个[Sensor_Subscriber](capi-sensor-sensor-subscriber.md)实例。 |
| [int32_t OH_Sensor_DestroySubscriber(Sensor_Subscriber *subscriber)](#oh_sensor_destroysubscriber) | - | 销毁[Sensor_Subscriber](capi-sensor-sensor-subscriber.md)实例并回收内存。 |
| [int32_t OH_SensorSubscriber_SetCallback(Sensor_Subscriber* subscriber, const Sensor_EventCallback callback)](#oh_sensorsubscriber_setcallback) | - | 设置一个回调函数来报告传感器数据。调用成功后，订阅者将使用指定的回调函数来报告传感器数据。 |
| [int32_t OH_SensorSubscriber_GetCallback(Sensor_Subscriber* subscriber, Sensor_EventCallback *callback)](#oh_sensorsubscriber_getcallback) | - | 获取用于报告传感器数据的回调函数。 |

## 枚举类型说明

### Sensor_Type

```c
enum Sensor_Type
```

**描述**

枚举传感器类型。

**起始版本：** 11

| 枚举项 | 描述 |
| -- | -- |
| SENSOR_TYPE_ACCELEROMETER = 1 | 加速度传感器。<br>**起始版本：** 11 |
| SENSOR_TYPE_GYROSCOPE = 2 | 陀螺仪传感器。<br>**起始版本：** 11 |
| SENSOR_TYPE_AMBIENT_LIGHT = 5 | 环境光传感器。<br>**起始版本：** 11 |
| SENSOR_TYPE_MAGNETIC_FIELD = 6 | 地磁传感器。<br>**起始版本：** 11 |
| SENSOR_TYPE_BAROMETER = 8 | 气压传感器。<br>**起始版本：** 11 |
| SENSOR_TYPE_HALL = 10 | 霍尔传感器。<br>**起始版本：** 11 |
| SENSOR_TYPE_PROXIMITY = 12 | 接近光传感器。<br>**起始版本：** 11 |
| SENSOR_TYPE_ORIENTATION = 256 | 方向传感器。<br>**起始版本：** 11 |
| SENSOR_TYPE_GRAVITY = 257 | 重力传感器。<br>**起始版本：** 11 |
| SENSOR_TYPE_LINEAR_ACCELERATION = 258 | 线性加速度传感器。<br>**起始版本：** 13 |
| SENSOR_TYPE_ROTATION_VECTOR = 259 | 旋转矢量传感器。<br>**起始版本：** 11 |
| SENSOR_TYPE_GAME_ROTATION_VECTOR = 262 | 游戏旋转矢量传感器。<br>**起始版本：** 13 |
| SENSOR_TYPE_PEDOMETER_DETECTION = 265 | 计步器检测传感器。<br>**起始版本：** 11 |
| SENSOR_TYPE_PEDOMETER = 266 | 计步器传感器。<br>**起始版本：** 11 |
| SENSOR_TYPE_HEART_RATE = 278 | 心率传感器。<br>**起始版本：** 11 |

### Sensor_Result

```c
enum Sensor_Result
```

**描述**

定义传感器错误码。

**起始版本：** 11

| 枚举项 | 描述 |
| -- | -- |
| SENSOR_SUCCESS = 0 | 操作成功。<br>**起始版本：** 11 |
| SENSOR_PERMISSION_DENIED = 201 | 权限验证失败。可能原因：应用缺少必要的传感器权限、权限申请被拒绝、权限级别不足等。解决措施：请检查应用配置文件中是否已申请所需的传感器权限，确保在运行时正确请求和获取权限。<br>**起始版本：** 11 |
| SENSOR_PARAMETER_ERROR = 401 | 参数检查失败。可能原因：参数为空、参数超出有效范围、参数类型不匹配、缺少必填参数等。解决措施：请根据具体函数的参数说明，检查传入的参数是否完整、符合类型要求、在有效范围内，并修正参数值。<br>**起始版本：** 11 |
| SENSOR_SERVICE_EXCEPTION = 14500101 | 传感器服务异常。可能原因：传感器服务未启动、传感器服务崩溃、设备不支持指定传感器、系统资源不足等。解决措施：请检查设备是否支持所需传感器，确保系统资源充足，必要时重启设备或重新初始化传感器服务。<br>**起始版本：** 11 |

### Sensor_Accuracy

```c
enum Sensor_Accuracy
```

**描述**

枚举传感器报告的数据的精度级别。

**起始版本：** 11

| 枚举项 | 描述 |
| -- | -- |
| SENSOR_ACCURACY_UNRELIABLE = 0 | 传感器数据不可靠。有可能传感器不与设备接触而进行测量。<br>**起始版本：** 11 |
| SENSOR_ACCURACY_LOW = 1 | 传感器数据精度较低。数据在使用前必须根据环境进行校准。<br>**起始版本：** 11 |
| SENSOR_ACCURACY_MEDIUM = 2 | 传感器数据处于中等精度水平。建议用户在使用前根据实际环境进行数据校准。<br>**起始版本：** 11 |
| SENSOR_ACCURACY_HIGH = 3 | 传感器数据具有很高的精度。数据可以直接使用。<br>**起始版本：** 11 |


## 函数说明

### OH_Sensor_CreateInfos()

```c
Sensor_Info **OH_Sensor_CreateInfos(uint32_t count)
```

**描述**

用给定的数字创建一个实例数组，请参考[Sensor_Info](capi-sensor-sensor-info.md)。创建成功后，返回指向count个Sensor_Info实例的指针数组。

调用此函数创建的实例数组，在使用完毕后必须调用OH_Sensor_DestroyInfos()销毁并回收内存，否则会导致资源泄漏。

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| uint32_t count | 要创建的实例的数量，请参考 [Sensor_Info](capi-sensor-sensor-info.md)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Sensor_Info **](capi-sensor-sensor-info.md) | 如果操作成功，返回指向[Sensor_Info](capi-sensor-sensor-info.md)实例数组的双指针，数组中包含count个Sensor_Info实例，用于存储传感器信息；否则返回<b>NULL</b>。 |

### OH_Sensor_DestroyInfos()

```c
int32_t OH_Sensor_DestroyInfos(Sensor_Info **sensors, uint32_t count)
```

**描述**

销毁实例数组并回收内存，请参考[Sensor_Info](capi-sensor-sensor-info.md)。调用成功后，实例数组占用的内存被释放，sensors指针及其指向的所有Sensor_Info实例不能再使用。

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Sensor_Info](capi-sensor-sensor-info.md) **sensors | 指向[Sensor_Info](capi-sensor-sensor-info.md)实例数组的双指针。 |
| uint32_t count | 要销毁的[Sensor_Info](capi-sensor-sensor-info.md)实例的数量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回操作结果，如果成功返回<b>SENSOR_SUCCESS</b>，表示所有实例已成功销毁；否则返回[Sensor_Result](capi-oh-sensor-type-h.md#sensor_result)中定义的错误代码。 |

### OH_SensorInfo_GetName()

```c
int32_t OH_SensorInfo_GetName(Sensor_Info* sensor, char *sensorName, uint32_t *length)
```

**描述**

获取传感器名称。获取成功后，sensorName参数中会填充传感器名称的字符串，length参数中会返回字符串的长度（包含结束符）。

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Sensor_Info](capi-sensor-sensor-info.md)* sensor | 指向传感器信息的指针。 |
| char *sensorName | 指向传感器名称的指针。 |
| uint32_t *length | 指向长度的指针，单位：B（字节）。调用前应设置为缓冲区大小，调用后返回实际名称长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回操作结果，如果成功返回<b>SENSOR_SUCCESS</b>，表示传感器名称已成功获取；否则返回[Sensor_Result](capi-oh-sensor-type-h.md#sensor_result)中定义的错误代码。 |


### OH_SensorInfo_GetVendorName()
```c
int32_t OH_SensorInfo_GetVendorName(Sensor_Info* sensor, char *vendorName, uint32_t *length)
```

**描述**

获取传感器的厂商名称。获取成功后，vendorName参数中会填充传感器厂商名称的字符串，length参数中会返回字符串的长度（包含结束符）。

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Sensor_Info](capi-sensor-sensor-info.md)* sensor | 指向传感器信息的指针。 |
| char *vendorName | 指向厂商名称的指针。 |
| uint32_t *length | 指向长度的指针，单位：B（字节）。调用前应设置为缓冲区大小，调用后返回实际厂商名称长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回操作结果，如果成功返回<b>SENSOR_SUCCESS</b>，表示传感器厂商名称已成功获取；否则返回[Sensor_Result](capi-oh-sensor-type-h.md#sensor_result)中定义的错误代码。 |

### OH_SensorInfo_GetType()

```c
int32_t OH_SensorInfo_GetType(Sensor_Info* sensor, Sensor_Type *sensorType)
```

**描述**

获取[Sensor_Type](capi-oh-sensor-type-h.md#sensor_type)。获取成功后，sensorType参数中会填充传感器的类型值。

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Sensor_Info](capi-sensor-sensor-info.md)* sensor | 指向传感器信息的指针。 |
| [Sensor_Type](capi-oh-sensor-type-h.md#sensor_type) *sensorType | 指向传感器类型的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回操作结果，如果成功返回<b>SENSOR_SUCCESS</b>，表示传感器类型已成功获取；否则返回[Sensor_Result](capi-oh-sensor-type-h.md#sensor_result)中定义的错误代码。 |

### OH_SensorInfo_GetResolution()

```c
int32_t OH_SensorInfo_GetResolution(Sensor_Info* sensor, float *resolution)
```

**描述**

获取传感器分辨率。获取成功后，resolution参数中会填充传感器的分辨率值。

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Sensor_Info](capi-sensor-sensor-info.md)* sensor | 指向传感器信息的指针。 |
| float *resolution | 指向传感器分辨率的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回操作结果，如果成功返回<b>SENSOR_SUCCESS</b>，表示传感器分辨率已成功获取；否则返回[Sensor_Result](capi-oh-sensor-type-h.md#sensor_result)中定义的错误代码。 |

### OH_SensorInfo_GetMinSamplingInterval()

```c
int32_t OH_SensorInfo_GetMinSamplingInterval(Sensor_Info* sensor, int64_t *minSamplingInterval)
```

**描述**

获取传感器的最小数据上报间隔。获取成功后，minSamplingInterval参数中会填充传感器的最小数据上报间隔值，单位：ns（纳秒）。

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Sensor_Info](capi-sensor-sensor-info.md)* sensor | 指向传感器信息的指针。 |
| int64_t *minSamplingInterval | 指向最小数据报告间隔的指针，单位：ns（纳秒）。该值表示传感器支持的最快数据上报间隔，小于该值的设置可能导致数据丢失或性能下降。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回操作结果，如果成功返回<b>SENSOR_SUCCESS</b>，表示最小数据上报间隔已成功获取；否则返回[Sensor_Result](capi-oh-sensor-type-h.md#sensor_result)中定义的错误代码。 |

### OH_SensorInfo_GetMaxSamplingInterval()

```c
int32_t OH_SensorInfo_GetMaxSamplingInterval(Sensor_Info* sensor, int64_t *maxSamplingInterval)
```

**描述**

获取传感器的最大数据上报间隔。获取成功后，maxSamplingInterval参数中会填充传感器的最大数据上报间隔值，单位：ns（纳秒）。

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Sensor_Info](capi-sensor-sensor-info.md)* sensor | 指向传感器信息的指针。 |
| int64_t *maxSamplingInterval | 指向最大数据报告间隔的指针，单位：ns（纳秒）。该值表示传感器支持的最慢数据上报间隔，大于该值的设置可能导致数据更新不及时。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回操作结果，如果成功返回<b>SENSOR_SUCCESS</b>，表示最大数据上报间隔已成功获取；否则返回[Sensor_Result](capi-oh-sensor-type-h.md#sensor_result)中定义的错误代码。 |

### OH_SensorEvent_GetType()

```c
int32_t OH_SensorEvent_GetType(Sensor_Event* sensorEvent, Sensor_Type *sensorType)
```

**描述**

获取传感器类型。

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Sensor_Event](capi-sensor-sensor-event.md)* sensorEvent | 指向传感器数据信息的指针。 |
| [Sensor_Type](capi-oh-sensor-type-h.md#sensor_type) *sensorType | 指向传感器类型的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回操作结果，如果成功返回<b>SENSOR_SUCCESS</b>，表示传感器事件类型已成功获取；否则返回[Sensor_Result](capi-oh-sensor-type-h.md#sensor_result)中定义的错误代码。 |

### OH_SensorEvent_GetTimestamp()

```c
int32_t OH_SensorEvent_GetTimestamp(Sensor_Event* sensorEvent, int64_t *timestamp)
```

**描述**

获取传感器数据的时间戳。

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Sensor_Event](capi-sensor-sensor-event.md)* sensorEvent | 指向传感器数据信息的指针。 |
| int64_t *timestamp | 指向时间戳的指针，单位：ns（纳秒），表示传感器数据采集的时间，表示系统启动运行至今的纳秒数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回操作结果，如果成功返回<b>SENSOR_SUCCESS</b>，表示时间戳已成功获取；否则返回[Sensor_Result](capi-oh-sensor-type-h.md#sensor_result)中定义的错误代码。 |

### OH_SensorEvent_GetAccuracy()

```c
int32_t OH_SensorEvent_GetAccuracy(Sensor_Event* sensorEvent, Sensor_Accuracy *accuracy)
```

**描述**

获取传感器数据的精度。

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Sensor_Event](capi-sensor-sensor-event.md)* sensorEvent | 指向传感器数据信息的指针。 |
| [Sensor_Accuracy](capi-oh-sensor-type-h.md#sensor_accuracy) *accuracy | 指向传感器数据精度级别的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回操作结果，如果成功返回<b>SENSOR_SUCCESS</b>，表示传感器数据精度已成功获取；否则返回[Sensor_Result](capi-oh-sensor-type-h.md#sensor_result)中定义的错误代码。 |

### OH_SensorEvent_GetData()

```c
int32_t OH_SensorEvent_GetData(Sensor_Event* sensorEvent, float **data, uint32_t *length)
```

**描述**

获取传感器数据。数据的长度和内容依赖于监听的传感器类型，传感器上报的数据格式如下表所示：

| 传感器类型 | 数据元素及描述 |
| --- | --- |
| SENSOR_TYPE_ACCELEROMETER | data[0]、data[1]、data[2]分别表示设备x、y、z轴的加速度分量，单位：m/s² |
| SENSOR_TYPE_GYROSCOPE | data[0]、data[1]、data[2]分别表示设备x、y、z轴的旋转角速度，单位：rad/s（弧度/秒） |
| SENSOR_TYPE_AMBIENT_LIGHT | data[0]表示环境光强度，单位：lux（勒克斯）；从API version 12开始，data[1]表示色温，单位：K（开尔文）；data[2]表示红外亮度，单位：cd/m²（坎德拉每平方米） |
| SENSOR_TYPE_MAGNETIC_FIELD | data[0]、data[1]、data[2]分别表示设备x、y、z轴的地磁分量，单位：μT（微特斯拉） |
| SENSOR_TYPE_BAROMETER | data[0]表示气压值，单位：hPa（百帕） |
| SENSOR_TYPE_HALL | data[0]表示皮套吸合状态，0表示打开，大于0表示吸附 |
| SENSOR_TYPE_PROXIMITY | data[0]表示接近状态，0表示接近，大于0表示远离 |
| SENSOR_TYPE_ORIENTATION | data[0]、data[1]、data[2]分别表示设备绕z、x、y轴的角度，单位：°（度） |
| SENSOR_TYPE_GRAVITY | data[0]、data[1]、data[2]分别表示设备x、y、z轴的重力加速度分量，单位：m/s² |
| SENSOR_TYPE_ROTATION_VECTOR | data[0]、data[1]、data[2]分别表示设备x、y、z轴的旋转角度，单位：°（度）；data[3]表示旋转向量元素 |
| SENSOR_TYPE_PEDOMETER_DETECTION | data[0]表示步数检测状态，1表示检测到了步数变化 |
| SENSOR_TYPE_PEDOMETER | data[0]表示步数 |
| SENSOR_TYPE_HEART_RATE | data[0]表示心率数值 |
| SENSOR_TYPE_LINEAR_ACCELERATION | 从API version 13开始支持。data[0]、data[1]、data[2]分别表示设备x、y、z轴的线性加速度，单位：m/s² |
| SENSOR_TYPE_GAME_ROTATION_VECTOR | 从API version 13开始支持。data[0]、data[1]、data[2]分别表示设备x、y、z轴的旋转角度，单位：°（度）；data[3]表示旋转向量 |

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Sensor_Event](capi-sensor-sensor-event.md)* sensorEvent | 指向传感器数据信息的指针。 |
| float **data | 出参，传感器数据数组指针。数据格式依赖传感器类型，具体格式参考函数描述。 |
| uint32_t *length | 出参，数据数组的长度，表示data数组中有效数据的个数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回操作结果，如果成功返回<b>SENSOR_SUCCESS</b>，表示传感器数据已成功获取；否则返回[Sensor_Result](capi-oh-sensor-type-h.md#sensor_result)中定义的错误代码。 |

### OH_Sensor_CreateSubscriptionId()

```c
Sensor_SubscriptionId *OH_Sensor_CreateSubscriptionId(void)
```

**描述**

创建一个[Sensor_SubscriptionId](capi-sensor-sensor-subscriptionid.md)实例。

调用此函数创建的实例，在使用完毕后必须调用OH_Sensor_DestroySubscriptionId()销毁并回收内存，否则会导致资源泄漏。

**起始版本：** 11

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Sensor_SubscriptionId *](capi-sensor-sensor-subscriptionid.md) | 如果操作成功，返回指向[Sensor_SubscriptionId](capi-sensor-sensor-subscriptionid.md)实例的指针，该实例可用于标识传感器订阅；否则返回<b>NULL</b>。 |

### OH_Sensor_DestroySubscriptionId()

```c
int32_t OH_Sensor_DestroySubscriptionId(Sensor_SubscriptionId *id)
```

**描述**

销毁[Sensor_SubscriptionId](capi-sensor-sensor-subscriptionid.md)实例并回收内存。

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Sensor_SubscriptionId](capi-sensor-sensor-subscriptionid.md) *id | 指向[Sensor_SubscriptionId](capi-sensor-sensor-subscriptionid.md)实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回操作结果，如果成功返回<b>SENSOR_SUCCESS</b>，表示订阅ID实例已成功销毁；否则返回[Sensor_Result](capi-oh-sensor-type-h.md#sensor_result)中定义的错误代码。 |

### OH_SensorSubscriptionId_GetType()

```c
int32_t OH_SensorSubscriptionId_GetType(Sensor_SubscriptionId* id, Sensor_Type *sensorType)
```

**描述**

获取传感器类型。

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Sensor_SubscriptionId](capi-sensor-sensor-subscriptionid.md)* id | 指向传感器订阅ID的指针。 |
| [Sensor_Type](capi-oh-sensor-type-h.md#sensor_type) *sensorType | 指向传感器类型的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回操作结果，如果成功返回<b>SENSOR_SUCCESS</b>，表示传感器订阅类型已成功获取；否则返回[Sensor_Result](capi-oh-sensor-type-h.md#sensor_result)中定义的错误代码。 |

### OH_SensorSubscriptionId_SetType()

```c
int32_t OH_SensorSubscriptionId_SetType(Sensor_SubscriptionId* id, const Sensor_Type sensorType)
```

**描述**

设置传感器类型。调用成功后，订阅ID的类型被设置为指定的sensorType值。

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Sensor_SubscriptionId](capi-sensor-sensor-subscriptionid.md)* id | 指向传感器订阅ID的指针。 |
| const [Sensor_Type](capi-oh-sensor-type-h.md#sensor_type) sensorType | 要设置的传感器类型，用于指定订阅的传感器类型。取值范围为[Sensor_Type](#sensor_type)枚举中定义的传感器类型，如SENSOR_TYPE_ACCELEROMETER(加速度传感器)等。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回操作结果，如果成功返回<b>SENSOR_SUCCESS</b>，表示传感器订阅类型已成功设置；否则返回[Sensor_Result](capi-oh-sensor-type-h.md#sensor_result)中定义的错误代码。 |

### OH_Sensor_CreateSubscriptionAttribute()

```c
Sensor_SubscriptionAttribute *OH_Sensor_CreateSubscriptionAttribute(void)
```

**描述**

创建[Sensor_SubscriptionAttribute](capi-sensor-sensor-subscriptionattribute.md)实例。

调用此函数创建的实例，在使用完毕后必须调用OH_Sensor_DestroySubscriptionAttribute()销毁并回收内存，否则会导致资源泄漏。

**起始版本：** 11

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Sensor_SubscriptionAttribute *](capi-sensor-sensor-subscriptionattribute.md) | 如果操作成功，返回指向[Sensor_SubscriptionAttribute](capi-sensor-sensor-subscriptionattribute.md)实例的指针，该实例可用于配置传感器订阅属性；否则返回<b>NULL</b>。 |

### OH_Sensor_DestroySubscriptionAttribute()

```c
int32_t OH_Sensor_DestroySubscriptionAttribute(Sensor_SubscriptionAttribute *attribute)
```

**描述**

销毁[Sensor_SubscriptionAttribute](capi-sensor-sensor-subscriptionattribute.md)实例并回收内存。

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Sensor_SubscriptionAttribute](capi-sensor-sensor-subscriptionattribute.md) *attribute | 指向[Sensor_SubscriptionAttribute](capi-sensor-sensor-subscriptionattribute.md)实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回操作结果，如果成功返回<b>SENSOR_SUCCESS</b>，表示订阅属性实例已成功销毁；否则返回[Sensor_Result](capi-oh-sensor-type-h.md#sensor_result)中定义的错误代码。 |

### OH_SensorSubscriptionAttribute_SetSamplingInterval()

```c
int32_t OH_SensorSubscriptionAttribute_SetSamplingInterval(Sensor_SubscriptionAttribute* attribute, const int64_t samplingInterval)
```

**描述**

设置传感器数据报告间隔。调用成功后，订阅属性的采样间隔被设置为指定的samplingInterval值，后续传感器数据上报将按照此间隔进行。

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Sensor_SubscriptionAttribute](capi-sensor-sensor-subscriptionattribute.md)* attribute | 指向传感器订阅属性的指针。 |
| const int64_t samplingInterval | 要设置的数据报告间隔，单位：ns（纳秒）。该值决定了传感器数据上报的频率，值越小上报频率越高，过小可能导致系统性能压力，需根据传感器类型选择合适范围。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回操作结果，如果成功返回<b>SENSOR_SUCCESS</b>，表示传感器数据报告间隔已成功设置；否则返回[Sensor_Result](capi-oh-sensor-type-h.md#sensor_result)中定义的错误代码。 |

### OH_SensorSubscriptionAttribute_GetSamplingInterval()

```c
int32_t OH_SensorSubscriptionAttribute_GetSamplingInterval(Sensor_SubscriptionAttribute* attribute, int64_t *samplingInterval)
```

**描述**

获取传感器数据报告间隔。

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Sensor_SubscriptionAttribute](capi-sensor-sensor-subscriptionattribute.md)* attribute | 指向传感器订阅属性的指针。 |
| int64_t *samplingInterval | 指向数据报告间隔的指针，单位：ns（纳秒）。该值为当前设置的传感器数据上报间隔，可用于判断数据上报的频率，一般范围需参考传感器具体要求。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回操作结果，如果成功返回<b>SENSOR_SUCCESS</b>，表示传感器数据报告间隔已成功获取；否则返回[Sensor_Result](capi-oh-sensor-type-h.md#sensor_result)中定义的错误代码。 |

### Sensor_EventCallback()

```c
typedef void (*Sensor_EventCallback)(Sensor_Event *event)
```

**描述**

定义用于报告传感器数据的回调函数。

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Sensor_Event](capi-sensor-sensor-event.md)* event | 指向传感器数据信息的指针。 |

### OH_Sensor_CreateSubscriber()

```c
Sensor_Subscriber *OH_Sensor_CreateSubscriber(void)
```

**描述**

创建一个[Sensor_Subscriber](capi-sensor-sensor-subscriber.md)实例。

调用此函数创建的实例，在使用完毕后必须调用OH_Sensor_DestroySubscriber()销毁并回收内存，否则会导致资源泄漏。

**起始版本：** 11

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Sensor_Subscriber *](capi-sensor-sensor-subscriber.md) | 如果操作成功，返回指向[Sensor_Subscriber](capi-sensor-sensor-subscriber.md)实例的指针，该实例可用于订阅传感器数据；否则返回<b>NULL</b>。 |

### OH_Sensor_DestroySubscriber()

```c
int32_t OH_Sensor_DestroySubscriber(Sensor_Subscriber *subscriber)
```

**描述**

销毁[Sensor_Subscriber](capi-sensor-sensor-subscriber.md)实例并回收内存。

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Sensor_Subscriber](capi-sensor-sensor-subscriber.md) *subscriber | 指向[Sensor_Subscriber](capi-sensor-sensor-subscriber.md)实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回操作结果，如果成功返回<b>SENSOR_SUCCESS</b>，表示订阅者实例已成功销毁；否则返回[Sensor_Result](capi-oh-sensor-type-h.md#sensor_result)中定义的错误代码。 |

### OH_SensorSubscriber_SetCallback()

```c
int32_t OH_SensorSubscriber_SetCallback(Sensor_Subscriber* subscriber, const Sensor_EventCallback callback)
```

**描述**

设置一个回调函数来报告传感器数据。调用成功后，订阅者将使用指定的回调函数来报告传感器数据。

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Sensor_Subscriber](capi-sensor-sensor-subscriber.md)* subscriber | 指向传感器订阅者信息的指针。 |
| const [Sensor_EventCallback](capi-oh-sensor-type-h.md#sensor_eventcallback) callback | 要设置的回调函数，用于接收传感器数据上报。回调函数签名为void (*Sensor_EventCallback)(Sensor_Event *event)，其中event参数包含传感器数据的详细信息，如数据类型、时间戳、精度和传感器数据值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回操作结果，如果成功返回<b>SENSOR_SUCCESS</b>，表示回调函数已成功设置；否则返回[Sensor_Result](capi-oh-sensor-type-h.md#sensor_result)中定义的错误代码。 |

### OH_SensorSubscriber_GetCallback()

```c
int32_t OH_SensorSubscriber_GetCallback(Sensor_Subscriber* subscriber, Sensor_EventCallback *callback)
```

**描述**

获取用于报告传感器数据的回调函数。

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Sensor_Subscriber](capi-sensor-sensor-subscriber.md)* subscriber | 指向传感器订阅者信息的指针。 |
| [Sensor_EventCallback](capi-oh-sensor-type-h.md#sensor_eventcallback) *callback | 指向回调函数的指针。该值为当前设置的回调函数指针，若未设置则为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回操作结果，如果成功返回<b>SENSOR_SUCCESS</b>，表示回调函数已成功获取；否则返回[Sensor_Result](capi-oh-sensor-type-h.md#sensor_result)中定义的错误代码。 |


