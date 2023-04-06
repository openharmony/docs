# 泛Sensor子系统<a name="ZH-CN_TOPIC_0000001078062432"></a>

-   [简介](#section11660541593)
-   [目录](#section161941989596)
-   [说明](#section1312121216216)
-   [相关仓](#section1371113476307)

## 简介<a name="section11660541593"></a>

泛Sensor服务子系统提供了轻量级sensor服务基础框架，提供了如下功能：

-   Sensor列表查询
-   Sensor启停
-   Sensor订阅/去订阅
-   设置数据上报模式等

 **泛Sensor服务框架图如下所示：** 

![](figures/zh-cn_image_0000001106694563.png)

## 目录<a name="section161941989596"></a>

```
/base/sensors
├── sensor_lite          # Sensor组件目录
│   ├── frameworks       # 框架代码目录
│   ├── interfaces       # Native接口目录
│   └── services         # 服务代码目录
└── miscdevice_lite      # 小器件组件目录
```

## 说明<a name="section1312121216216"></a>

泛Sensor子系统中，主要包含三个模块：Sensor API、Sensor Framework和Sensor Service，详细结构见上述架构图：

-   Sensor API：提供传感器的基础API，主要包含Sensor列表查询、Sensor启停、Sensor订阅/去订阅等。
-   Sensor Framework：主要实现传感器的订阅管理，数据通道的创建、销毁、订阅与取消订阅，实现与SensorService的通信。
-   Sensor Service：主要实现HDF层数据接收、解析、分发，对Sensor服务的管理，数据上报管理以及Sensor权限管控等。

## 相关仓<a name="section1371113476307"></a>

**泛Sensor子系统**

[sensors_sensor_lite](https://gitee.com/openharmony/sensors_sensor_lite/blob/master/README_zh.md)

[sensors_miscdevice_lite](https://gitee.com/openharmony/sensors_miscdevice_lite/blob/master/README_zh.md)

