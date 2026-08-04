# Sensor
<!--Kit: Sensor Service Kit-->
<!--Subsystem: Sensors-->
<!--Owner: @dilligencer-->
<!--Designer: @andeszhang-->
<!--Tester: @zhaofangyuan-->
<!--Adviser: @hu-zhiqiong-->

## 概述

提供API来使用常见的传感器特性，支持加速度计、陀螺仪、光传感器等多种传感器。通过统一的接口获取传感器信息、订阅或取消订阅传感器数据，简化应用开发流程，降低开发成本。**使用场景**：计步器、运动追踪、屏幕自动亮度调节、游戏控制等。

**起始版本：** 11

## 文件汇总

| 名称 | 描述 |
| -- | -- |
| [oh_sensor.h](capi-oh-sensor-h.md) | 声明操作传感器的API，包括获取传感器信息，以及订阅或取消订阅传感器数据。 |
| [oh_sensor_type.h](capi-oh-sensor-type-h.md) | 定义常用传感器属性。 |