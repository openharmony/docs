# oh_sensor.h
<!--Kit: Sensor Service Kit-->
<!--Subsystem: Sensors-->
<!--Owner: @dilligencer-->
<!--SE: @butterls-->
<!--TSE: @murphy84-->

## 概述

声明操作传感器的API，包括获取传感器信息和订阅取消订阅传感器数据。

**库**：libohsensor.so

**系统能力**：SystemCapability.Sensors.Sensor

**起始版本**：11

**相关模块**：[Sensor](_sensor.md)


## 汇总


### 函数

| 名称 | 描述 |
| -------- | -------- |
| [OH_Sensor_GetInfos](_sensor.md#oh_sensor_getinfos)([Sensor_Info](_sensor.md#sensor_info) \*\*infos, uint32_t \*count) | 获取设备上所有传感器的信息。  |
| [OH_Sensor_Subscribe](_sensor.md#oh_sensor_subscribe)(const [Sensor_SubscriptionId](_sensor.md#sensor_subscriptionid) \*id, const [Sensor_SubscriptionAttribute](_sensor.md#sensor_subscriptionattribute) \*attribute, const [Sensor_Subscriber](_sensor.md#sensor_subscriber) \*subscriber) | 订阅传感器数据。系统将以指定的频率向用户报告传感器数据。<br/>订阅加速度传感器，需要申请ohos.permission.ACCELEROMETER权限；<br/>订阅陀螺仪传感器，需要申请ohos.permission.GYROSCOPE权限；<br/>订阅计步器相关传感器时，需要申请ohos.permission.ACTIVITY_MOTION权限；<br/>订阅与健康相关的传感器时，比如心率传感器，需要申请ohos.permission.READ_HEALTH_DATA权限，否则订阅失败。订阅其余传感器不需要申请权限。 |
| [OH_Sensor_Unsubscribe](_sensor.md#oh_sensor_unsubscribe)(const [Sensor_SubscriptionId](_sensor.md#sensor_subscriptionid) \*id, const [Sensor_Subscriber](_sensor.md#sensor_subscriber) \*subscriber) | 取消订阅传感器数据。<br/>取消订阅加速度计传感器，需要申请ohos.permission.ACCELEROMETER权限；<br/>取消订阅陀螺仪传感器，需要申请ohos.permission.GYROSCOPE权限；<br/>取消订阅计步器相关传感器时，需要申请ohos.permission.ACTIVITY_MOTION权限；<br/>取消订阅与健康相关的传感器时，需要申请ohos.permission.READ_HEALTH_DATA权限，否则取消订阅失败。取消订阅其余传感器不需要申请权限。 |
