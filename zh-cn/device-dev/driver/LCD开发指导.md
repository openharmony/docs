# LCD开发指导<a name="ZH-CN_TOPIC_0000001051616710"></a>

-   [开发步骤](#section3904154911218)

Display驱动模型基于HDF驱动框架、Platform接口及OSAL接口开发，可以做到不区分OS（LiteOS、Linux）和芯片平台（Hi35xx、Hi38xx、V3S等），为LCD器件提供统一的驱动模型。

## 开发步骤<a name="section3904154911218"></a>

1.  添加LCD驱动相关的设备描述配置。
2.  在SOC平台驱动适配层中适配对应的芯片平台驱动。
3.  添加器件驱动，并在驱动入口函数Init中注册Panel驱动数据，驱动数据接口主要包括如下接口：
    -   LCD上下电

        根据LCD硬件连接，使用Platform接口层提供的GPIO操作接口操作对应LCD管脚，例如复位管脚、IOVCC管脚，上电时序参考LCD供应商提供的SPEC。

    -   发送初始化序列

        根据LCD硬件接口，使用Platform接口层提供的I2C、SPI、MIPI等接口，下载LCD初始化序列，初始化参数序列可以参考LCD供应商提供的SPEC。


4.  根据需求实现HDF框架其他接口，比如Release接口。
5.  根据需求使用HDF框架可创建其他设备节点，用于业务逻辑或者调试功能。

