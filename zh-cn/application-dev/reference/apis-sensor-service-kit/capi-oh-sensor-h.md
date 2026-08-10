# oh_sensor.h
<!--Kit: Sensor Service Kit-->
<!--Subsystem: Sensors-->
<!--Owner: @dilligencer-->
<!--Designer: @andeszhang-->
<!--Tester: @liuhaonan2-->
<!--Adviser: @hu-zhiqiong-->

## 概述

声明传感器服务的API，包括获取传感器信息和订阅/取消订阅传感器数据。

**引用文件：** <sensors/oh_sensor.h>

**库：** libohsensor.so

**系统能力：** SystemCapability.Sensors.Sensor

**起始版本：** 11

**相关模块：** [Sensor](capi-sensor.md)

## 汇总

### 函数

| 名称 | 描述 |
| -- | -- |
| [Sensor_Result OH_Sensor_GetInfos(Sensor_Info \*\*infos, uint32_t \*count)](#oh_sensor_getinfos) | 获取设备上所有传感器的信息。使用场景：应用启动时查询设备支持的传感器列表，根据传感器能力展示或隐藏相关功能；选择合适的传感器进行订阅。调用成功后，通过指针infos返回传感器信息数组，通过指针count返回传感器数量。 |
| [Sensor_Result OH_Sensor_Subscribe(const Sensor_SubscriptionId \*id, const Sensor_SubscriptionAttribute \*attribute, const Sensor_Subscriber \*subscriber)](#oh_sensor_subscribe) | 订阅传感器数据。系统将以指定的频率向用户报告传感器数据。该订阅通过事件回调机制实现。使用场景：运动健康应用实时监测用户步数、心率等数据；游戏应用使用加速度传感器实现重力感应；导航应用使用陀螺仪传感器辅助定位。权限说明：订阅加速度传感器，需要申请ohos.permission.ACCELEROMETER权限；订阅陀螺仪传感器，需要申请ohos.permission.GYROSCOPE权限；订阅计步器相关传感器时，需要申请ohos.permission.ACTIVITY_MOTION权限；订阅与健康相关的传感器时，例如心率传感器，需要申请ohos.permission.READ_HEALTH_DATA权限，否则订阅失败。订阅其余传感器不需要申请权限。 |
| [Sensor_Result OH_Sensor_Unsubscribe(const Sensor_SubscriptionId \*id, const Sensor_Subscriber \*subscriber)](#oh_sensor_unsubscribe) | 取消订阅传感器数据。该操作会停止传感器数据上报。取消订阅加速度传感器，需要申请ohos.permission.ACCELEROMETER权限；取消订阅陀螺仪传感器，需要申请ohos.permission.GYROSCOPE权限；取消订阅计步器相关传感器时，需要申请ohos.permission.ACTIVITY_MOTION权限；取消订阅与健康相关的传感器时，例如心率传感器，需要申请ohos.permission.READ_HEALTH_DATA权限，否则取消订阅失败。取消订阅其余传感器不需要申请权限。 |

## 函数说明

### OH_Sensor_GetInfos()

```c
Sensor_Result OH_Sensor_GetInfos(Sensor_Info **infos, uint32_t *count)
```

**描述**

获取设备上所有传感器的信息。使用场景：应用启动时查询设备支持的传感器列表，根据传感器能力展示或隐藏相关功能；选择合适的传感器进行订阅。调用成功后，通过指针infos返回传感器信息数组，通过指针count返回传感器数量。

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| Sensor_Info \*\*infos | 输出参数，双指针指向设备上所有传感器的信息。调用者不需要预先分配内存，函数内部会分配内存，调用者需要在使用完毕后调用相应的释放函数释放内存。调用后，\*infos指向传感器信息数组，请参考[Sensor_Info](capi-sensor-sensor-info.md)。该参数不应为NULL。 |
| uint32_t \*count | 输出参数，指向设备上传感器数量的指针。调用者传入指向uint32_t变量的指针即可，调用后count指向的变量会被设置为传感器的数量。该参数不应为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Sensor_Result](capi-oh-sensor-type-h.md#sensor_result) | 返回[Sensor_Result](capi-oh-sensor-type-h.md#sensor_result)枚举值。主要枚举值如下：<br> SENSOR_SUCCESS：操作成功，表示成功获取传感器信息。<br> [SENSOR_PARAMETER_ERROR](capi-oh-sensor-type-h.md#sensor_result)：参数检查失败。例如，传入的infos或count参数为NULL指针。<br> [SENSOR_SERVICE_EXCEPTION](capi-oh-sensor-type-h.md#sensor_result)：传感器服务异常。例如，传感器服务未启动或发生内部错误。<br>其他可能的错误代码请参考[Sensor_Result](capi-oh-sensor-type-h.md#sensor_result)。 |

### OH_Sensor_Subscribe()

```c
Sensor_Result OH_Sensor_Subscribe(const Sensor_SubscriptionId *id, const Sensor_SubscriptionAttribute *attribute, const Sensor_Subscriber *subscriber)
```

**描述**

订阅传感器数据。系统将以指定的频率向用户报告传感器数据。该订阅通过事件回调机制实现。使用场景：运动健康应用实时监测用户步数、心率等数据；游戏应用使用加速度传感器实现重力感应；导航应用使用陀螺仪传感器辅助定位。

权限说明：订阅加速度传感器，需要申请ohos.permission.ACCELEROMETER权限；订阅陀螺仪传感器，需要申请ohos.permission.GYROSCOPE权限；订阅计步器相关传感器时，需要申请ohos.permission.ACTIVITY_MOTION权限；订阅与健康相关的传感器时，例如心率传感器，需要申请ohos.permission.READ_HEALTH_DATA权限，否则订阅失败。订阅其余传感器不需要申请权限。

**需要权限：** ohos.permission.ACCELEROMETER or ohos.permission.GYROSCOPE or ohos.permission.ACTIVITY_MOTION or ohos.permission.READ_HEALTH_DATA

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [Sensor_SubscriptionId](capi-sensor-sensor-subscriptionid.md) \*id | 输入参数，指向传感器订阅ID的指针。这是要订阅的传感器类型标识，不同的传感器类型对应不同的id值，如加速度传感器、陀螺仪传感器、心率传感器等，具体取值请参考[Sensor_SubscriptionId](capi-sensor-sensor-subscriptionid.md)。调用者需要确保id指向的数据有效。该参数不应为NULL。 |
| const [Sensor_SubscriptionAttribute](capi-sensor-sensor-subscriptionattribute.md) \*attribute | 输入参数，指向订阅属性的指针，该属性用于指定数据报告频率（单位：Hz）。调用者需先创建Sensor_SubscriptionAttribute对象并设置所需的数据报告频率，然后将该对象传入本函数。频率值需在传感器支持的频率范围内，具体范围因传感器类型而异；高频（如100Hz以上）适合需要实时监测数据的场景（如游戏），低频（如1-10Hz）适合省电且不需要高频数据的场景（如后台监测）。请根据实际需求选择合适的数据报告频率，如未设置数据报告频率，将使用系统默认值。请参考[Sensor_SubscriptionAttribute](capi-sensor-sensor-subscriptionattribute.md)。该参数不应为NULL。 |
| const [Sensor_Subscriber](capi-sensor-sensor-subscriber.md) \*subscriber | 输入参数，指向订阅者信息的指针，该信息包含回调函数，用于报告传感器数据。调用者在调用本函数前必须先设置好回调函数，系统会按照订阅属性中指定的频率调用该回调函数。在取消订阅前，回调函数应保持有效，不应被修改或释放。请参考[Sensor_Subscriber](capi-sensor-sensor-subscriber.md)。该参数不应为NULL。注意：回调函数在传感器服务线程中执行，不应在回调中进行耗时操作或阻塞调用，否则可能影响传感器数据报告的实时性。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Sensor_Result](capi-oh-sensor-type-h.md#sensor_result) | 返回[Sensor_Result](capi-oh-sensor-type-h.md#sensor_result)枚举值。主要枚举值如下：<br> SENSOR_SUCCESS：操作成功，表示成功订阅传感器数据。<br> [SENSOR_PERMISSION_DENIED](capi-oh-sensor-type-h.md#sensor_result)：权限验证失败。缺少订阅传感器所需权限时返回此错误，请参考函数描述部分了解不同传感器所需的权限，并按照要求申请相应权限后再试。<br> [SENSOR_PARAMETER_ERROR](capi-oh-sensor-type-h.md#sensor_result)：参数检查失败。例如，传入的id、attribute或subscriber参数为NULL指针。<br> [SENSOR_SERVICE_EXCEPTION](capi-oh-sensor-type-h.md#sensor_result)：传感器服务异常。例如，传感器服务未启动或发生内部错误。<br>其他可能的错误代码请参考[Sensor_Result](capi-oh-sensor-type-h.md#sensor_result)。 |

### OH_Sensor_Unsubscribe()

```c
Sensor_Result OH_Sensor_Unsubscribe(const Sensor_SubscriptionId *id, const Sensor_Subscriber *subscriber)
```

**描述**

取消订阅传感器数据。该操作会停止传感器数据上报。

取消订阅加速度传感器，需要申请ohos.permission.ACCELEROMETER权限；取消订阅陀螺仪传感器，需要申请ohos.permission.GYROSCOPE权限；取消订阅计步器相关传感器时，需要申请ohos.permission.ACTIVITY_MOTION权限；取消订阅与健康相关的传感器时，例如心率传感器，需要申请ohos.permission.READ_HEALTH_DATA权限，否则取消订阅失败。取消订阅其余传感器不需要申请权限。

**需要权限：** ohos.permission.ACCELEROMETER or ohos.permission.GYROSCOPE or ohos.permission.ACTIVITY_MOTION or ohos.permission.READ_HEALTH_DATA

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [Sensor_SubscriptionId](capi-sensor-sensor-subscriptionid.md) \*id | 输入参数，指向传感器订阅ID的指针。这是要取消的订阅ID，必须与之前调用OH_Sensor_Subscribe时使用的订阅ID一致，否则可能返回SENSOR_PARAMETER_ERROR。不同的传感器类型对应不同的id值，如加速度传感器、陀螺仪传感器、心率传感器等，具体取值请参考[Sensor_SubscriptionId](capi-sensor-sensor-subscriptionid.md)。该参数不应为NULL。 |
| const [Sensor_Subscriber](capi-sensor-sensor-subscriber.md) \*subscriber | 输入参数，指向订阅者信息的指针，该信息包含回调函数，用于报告传感器数据。这个subscriber必须与之前调用OH_Sensor_Subscribe时使用的subscriber一致，用于唯一标识订阅者，否则可能返回SENSOR_PARAMETER_ERROR。取消订阅成功后，回调函数将不再被调用。请参考[Sensor_Subscriber](capi-sensor-sensor-subscriber.md)。该参数不应为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Sensor_Result](capi-oh-sensor-type-h.md#sensor_result) | 返回[Sensor_Result](capi-oh-sensor-type-h.md#sensor_result)枚举值。主要枚举值如下：<br> SENSOR_SUCCESS：操作成功，表示成功取消订阅传感器数据。<br> [SENSOR_PERMISSION_DENIED](capi-oh-sensor-type-h.md#sensor_result)：权限验证失败。缺少取消订阅传感器所需权限时返回此错误，请参考函数描述部分了解不同传感器所需的权限，并按照要求申请相应权限后再试。<br> [SENSOR_PARAMETER_ERROR](capi-oh-sensor-type-h.md#sensor_result)：参数检查失败。例如，传入的id或subscriber参数为NULL指针。<br> [SENSOR_SERVICE_EXCEPTION](capi-oh-sensor-type-h.md#sensor_result)：传感器服务异常。例如，传感器服务未启动或发生内部错误。<br>其他可能的错误代码请参考[Sensor_Result](capi-oh-sensor-type-h.md#sensor_result)。 |
