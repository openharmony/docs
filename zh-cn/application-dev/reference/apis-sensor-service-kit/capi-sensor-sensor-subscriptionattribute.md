# Sensor_SubscriptionAttribute
<!--Kit: Sensor Service Kit-->
<!--Subsystem: Sensors-->
<!--Owner: @dilligencer-->
<!--Designer: @andeszhang-->
<!--Tester: @zhaofangyuan-->
<!--Adviser: @hu-zhiqiong-->

```c
typedef struct Sensor_SubscriptionAttribute Sensor_SubscriptionAttribute
```

## 概述

定义传感器订阅属性结构体，用于指定传感器订阅的相关参数，包括订阅的传感器类型、采样间隔等。该属性适用于传感器数据订阅场景，帮助开发者根据业务需求配置订阅方式，提供灵活的传感器数据获取能力。该属性用于指定传感器订阅的具体参数，如采样率、数据上报间隔等，用于配置传感器的数据采集和上报行为。用于运动健康应用中的步数和心率数据订阅，环境监测应用中的温湿度数据实时采集，设备控制应用中的状态变化监听等。

**起始版本：** 11

**相关模块：** [Sensor](capi-sensor.md)

**所在头文件：** [oh_sensor_type.h](capi-oh-sensor-type-h.md)

