# Sensor_SubscriptionId
<!--Kit: Sensor Service Kit-->
<!--Subsystem: Sensors-->
<!--Owner: @dilligencer-->
<!--Designer: @andeszhang-->
<!--Tester: @zhaofangyuan-->
<!--Adviser: @hu-zhiqiong-->

```c
typedef struct Sensor_SubscriptionId Sensor_SubscriptionId
```

## 概述

定义传感器订阅ID结构体，用于唯一标识传感器订阅请求。该结构体用于标识一个传感器订阅操作，包含传感器类型、订阅的具体订阅条件等信息。开发者可以通过传感器订阅ID来管理传感器的订阅生命周期，包括激活、去激活和查询订阅状态等操作。

在订阅传感器数据时，作为订阅请求的参数，用于标识订阅关系，在查询已订阅的传感器信息时，用于获取对应的订阅状态和数据，在取消传感器订阅时，用于指定需要取消的订阅。

**起始版本：** 11

**相关模块：** [Sensor](capi-sensor.md)

**所在头文件：** [oh_sensor_type.h](capi-oh-sensor-type-h.md)

