# Sensor_Subscriber
<!--Kit: Sensor Service Kit-->
<!--Subsystem: Sensors-->
<!--Owner: @dilligencer-->
<!--Designer: @andeszhang-->
<!--Tester: @zhaofangyuan-->
<!--Adviser: @hu-zhiqiong-->

```c
typedef struct Sensor_Subscriber Sensor_Subscriber
```

## 概述

用于注册传感器数据订阅的订阅者信息结构体，包含订阅回调函数和用户数据。使用该结构体可以指定传感器订阅者的参数，订阅成功后，将接收传感器的数据更新。

**起始版本：** 11

**相关模块：** [Sensor](capi-sensor.md)

**所在头文件：** [oh_sensor_type.h](capi-oh-sensor-type-h.md)

