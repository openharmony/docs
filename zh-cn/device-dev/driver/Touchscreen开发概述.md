# Touchscreen开发概述<a name="ZH-CN_TOPIC_0000001052857350"></a>

-   [简介](#section124332411260)
-   [接口说明](#section10542625172618)

## 简介<a name="section124332411260"></a>

-   **Touchscreen驱动主要任务**

    Touchscreen驱动用于驱动触摸屏使其正常工作，该驱动主要完成如下工作：对触摸屏驱动IC进行上电、配置硬件管脚并初始化其状态、注册中断、配置通信接口（I2C或SPI）、设定input相关配置、下载及更新固件等操作。


-   **Touchscreen驱动层次说明**

    本节主要介绍基于input驱动模型开发touchscreen器件驱动，其整体的框架模型如[图1](#fig6251184817261)。

    Input驱动模型基于HDF驱动框架、PLATFORM接口、OSAL接口进行开发，向上对接规范化的驱动接口HDI（Hardware Driver Interface）层，通过Input-HDI层对外提供硬件能力，即上层input service可以通过HDI接口层获取相应的驱动能力，进而操控touchscreen等输入设备。


**图 1**  基于HDF驱动框架的input驱动模型<a name="fig6251184817261"></a>  
![](figures/基于HDF驱动框架的input驱动模型.png "基于HDF驱动框架的input驱动模型")

-   **Input驱动模型介绍**

    Input驱动模型核心部分由设备管理层、公共驱动层、器件驱动层组成。器件产生的数据借助平台数据通道能力从内核传递到用户态，驱动模型通过配置文件适配不同器件及硬件平台，提高开发者的器件驱动开发效率。如下部分为模型各部分的说明：

    （1）input设备管理：为各类输入设备驱动提供input设备的注册、注销接口，同时统一管理input设备列表；

    （2）input平台驱动：指各类input设备的公共抽象驱动（例如触摸屏的公共驱动），负责对板级硬件进行初始化、硬件中断处理、向manager注册input设备等；

    （3）input器件驱动：指各器件厂家的差异化驱动，通过适配平台驱动预留的差异化接口，实现器件驱动开发量最小化；

    （4）input数据通道：提供一套通用的数据上报通道，各类别的input设备驱动均可用此通道上报input事件；

    （5）input配置解析：负责对input设备的板级配置及器件私有配置进行解析及管理。


-   **基于HDF驱动框架开发器件驱动的优势**

    在HDF（Hardware Driver Foundation）[驱动管理框架](驱动开发.md)的基础上，input驱动模型调用OSAL接口层和Platfom接口层提供的基础接口进行开发，包括bus通信接口、操作系统原生接口（memory、lock、thread、timer等）。由于OSAL接口和Platform接口屏蔽了芯片平台差异，所以基于input驱动模型实现的touchscreen驱动可以进行跨平台、跨OS迁移，以便逐步实现驱动的一次开发，多端部署。


## 接口说明<a name="section10542625172618"></a>

Touchscreen器件的硬件接口相对简单，根据PIN脚的属性，可以简单分为如下三类:

-   电源接口
-   IO控制接口
-   通信接口

**图 2**  Touchscreen器件常用管脚<a name="fig1290384314416"></a>  
![](figures/Touchscreen器件常用管脚.png "Touchscreen器件常用管脚")

如上图所示的三类接口，分别做简要说明如下：

1.  **电源接口**
    -   LDO\_1P8：1.8v数字电路
    -   LDO\_3P3：3.3v模拟电路

        通常情况下，touchscreen驱动IC和LCD驱动IC是相互分离的，这种情况下，touchscreen驱动IC一般同时需要1.8v和3.3v两路供电。随着芯片演进，业内已有touchscreen驱动IC和LCD驱动IC集成在一颗IC中的芯片案例，对touchscreen而言，只需要关注1.8v供电即可，其内部需要的3.3v电源，会在驱动IC内部从LCD的VSP电源（典型值5.5V）中分出来。


2.  **IO控制接口**
    -   Reset：reset管脚，用于在系统休眠、唤醒时，由主机侧对驱动IC进行复位操作。
    -   INT：中断管脚，需要在驱动初始化时，配置为输入上拉状态。在驱动IC检测到外部触摸信号后，通过操作中断管脚来触发中断，器件驱动则会在中断处理函数中进行报点数据读取等操作。

3.  **通信接口**
    -   I2C：由于touchscreen的报点数据量相对较少，所以一般选用I2C方式传输数据。I2C的具体协议及对应操作接口，可以参考Platform接口层中的[“I2C”使用指南](I2C使用指导.md)。
    -   SPI：部分厂商，由于需要传递的数据不止报点坐标，而是需要获取基础容值，数据量较大，所以会选用SPI通信方式。SPI的具体协议及对应操作接口，可以参考Platform接口层中的[“SPI” 使用指南](SPI使用指导.md)。


