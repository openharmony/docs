# SPI

## 概述

### 功能简介

SPI即串行外设接口（Serial Peripheral Interface），是一种高速的，全双工，同步的通信总线。SPI是由Motorola公司开发，用于在主设备和从设备之间进行通信。

### 运作机制

在HDF框架中，SPI的接口适配模式采用独立服务模式（如图1所示），在这种模式下，每一个设备对象会独立发布一个设备服务来处理外部访问，设备管理器收到API的访问请求之后，通过提取该请求的参数，达到调用实际设备对象的相应内部方法的目的。独立服务模式可以直接借助HDFDeviceManager的服务管理能力，但需要为每个设备单独配置设备节点，若设备过多可能增加内存占用。

独立服务模式下，核心层不会统一发布一个服务供上层使用，因此这种模式下驱动要为每个控制器发布一个服务，具体表现为：

- 驱动适配者需要实现HdfDriverEntry的Bind钩子函数以绑定服务。

- device_info.hcs文件中deviceNode的policy字段为1或2，不能为0。

**图 1** SPI独立服务模式结构图<a name="fig1"></a>  

![SPI独立服务模式结构图](figures/独立服务模式结构图.png)

SPI模块各分层作用：

- 接口层提供打开SPI设备、SPI写数据、SPI读数据、SPI传输、配置SPI设备属性、获取SPI设备属性、关闭SPI设备的接口。

- 核心层主要提供SPI控制器的添加、移除以及管理的能力，通过钩子函数与适配层交互。

- 适配层主要是将钩子函数的功能实例化，实现具体的功能。

SPI以主从方式工作，通常有一个主设备和一个或者多个从设备。主设备和从设备之间一般用4根线相连，它们分别是：

- SCLK：时钟信号，由主设备产生；

- MOSI：主设备数据输出，从设备数据输入；
  
- MISO：主设备数据输入，从设备数据输出；
  
- CS：片选，从设备使能信号，由主设备控制。

一个主设备和两个从设备的连接示意图如图2所示，Device A和Device B共享主设备的SCLK、MISO和MOSI三根引脚，Device A的片选CS0连接主设备的CS0，Device B的片选CS1连接主设备的CS1。

**图 2** SPI主从设备连接示意图<a name="fig2"></a>  

![SPI主从设备连接示意图](figures/SPI主从设备连接示意图.png)

- SPI通信通常由主设备发起，通过以下步骤完成一次通信：

    1. 通过CS选中要通信的从设备，在任意时刻，一个主设备上最多只能有一个从设备被选中。

    2. 通过SCLK给选中的从设备提供时钟信号。

    3. 基于SCLK时钟信号，主设备数据通过MOSI发送给从设备，同时通过MISO接收从设备发送的数据，完成通信。

- 根据SCLK时钟信号的CPOL（Clock Polarity，时钟极性）和CPHA（Clock Phase，时钟相位）的不同组合，SPI有以下四种工作模式：

    - CPOL=0，CPHA=0 时钟信号idle状态为低电平，第一个时钟边沿采样数据。

    - CPOL=0，CPHA=1 时钟信号idle状态为低电平，第二个时钟边沿采样数据。

    - CPOL=1，CPHA=0 时钟信号idle状态为高电平，第一个时钟边沿采样数据。

    - CPOL=1，CPHA=1 时钟信号idle状态为高电平，第二个时钟边沿采样数据。

## 开发指导

### 场景介绍

SPI通常用于与闪存、实时时钟、传感器以及模数/数模转换器等支持SPI协议的设备进行通信。当驱动开发者需要将SPI设备适配到OpenHarmony时，需要进行SPI驱动适配，下文将介绍如何进行SPI驱动适配。

### 接口说明

为了保证上层在调用SPI接口时能够正确的操作硬件，核心层在//drivers/hdf_core/framework/support/platform/include/spi/spi_core.h中定义了以下钩子函数。驱动适配者需要在适配层实现这些函数的具体功能，并与这些钩子函数挂接，从而完成接口层与核心层的交互。

SpiCntlrMethod定义：

```c
struct SpiCntlrMethod {
    int32_t (*GetCfg)(struct SpiCntlr *cntlr, struct SpiCfg *cfg);
    int32_t (*SetCfg)(struct SpiCntlr *cntlr, struct SpiCfg *cfg);
    int32_t (*Transfer)(struct SpiCntlr *cntlr, struct SpiMsg *msg, uint32_t count);
    int32_t (*Open)(struct SpiCntlr *cntlr);
    int32_t (*Close)(struct SpiCntlr *cntlr);
};
```

**表 1** SpiCntlrMethod结构体成员的钩子函数功能说明

| 成员函数 | 入参 | 返回值 | 功能 | 
| -------- | -------- | -------- | -------- |
| Transfer | cntlr：结构体指针，核心层SPI控制器。<br/>msg：结构体指针，Spi消息。<br/>count：uint32_t类型，消息个数。 | HDF_STATUS相关状态 | 传输消息 | 
| SetCfg | cntlr：结构体指针，核心层SPI控制器。<br/>cfg：结构体指针，Spi属性。 | HDF_STATUS相关状态 | 设置控制器属性 | 
| GetCfg | cntlr：结构体指针，核心层SPI控制器。<br/>cfg：结构体指针，Spi属性。 | HDF_STATUS相关状态 | 获取控制器属性 | 
| Open | cntlr：结构体指针，核心层SPI控制器。 | HDF_STATUS相关状态 | 打开SPI | 
| Close | cntlr：结构体指针，核心层SPI控制器。 | HDF_STATUS相关状态 | 关闭SPI | 


### 开发步骤

SPI模块适配包含以下四个步骤：

1. 实例化驱动入口

    - 实例化HdfDriverEntry结构体成员。

    - 调用HDF_INIT将HdfDriverEntry实例化对象注册到HDF框架中。

2. 配置属性文件

    - 在device_info.hcs文件中添加deviceNode描述。

    - 【可选】添加spi_config.hcs器件属性文件。

3. 实例化SPI控制器对象

    - 初始化SpiCntlr成员。

    - 实例化SpiCntlr成员SpiCntlrMethod。

        > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**<br>
        > 实例化SpiCntlr成员SpiCntlrMethod，其定义和成员说明见[接口说明](#接口说明)。

4. 驱动调试

   【可选】针对新增驱动程序，建议验证驱动基本功能，例如SPI控制状态，中断响应情况等。

### 开发实例

下方将以//device/soc/hisilicon/common/platform/spi/spi_hi35xx.c为示例，展示需要驱动适配者提供哪些内容来完整实现设备功能。

1. 实例化驱动入口

    驱动入口必须为HdfDriverEntry（在hdf_device_desc.h中定义）类型的全局变量，且moduleName要和device_info.hcs中保持一致。HDF框架会将所有加载的驱动的HdfDriverEntry对象首地址汇总，形成一个类似数组的段地址空间，方便上层调用。

    一般在加载驱动时HDF会先调用Bind函数，再调用Init函数加载该驱动。当Init调用异常时，HDF框架会调用Release释放驱动资源并退出。

    SPI驱动入口参考：

    ```c
    struct HdfDriverEntry g_hdfSpiDevice = {
        .moduleVersion = 1,
        .moduleName = "HDF_PLATFORM_SPI", //【必要且与HCS文件中里面的moduleName匹配】
        .Bind = HdfSpiDeviceBind,         // 挂接SPI模块Bind实例化
        .Init = HdfSpiDeviceInit,         // 挂接SPI模块Init实例化
        .Release = HdfSpiDeviceRelease,   // 挂接SPI模块Release实例化
    };
    HDF_INIT(g_hdfSpiDevice);             // 调用HDF_INIT将驱动入口注册到HDF框架中
    ```

2. 配置属性文件

    完成驱动入口注册之后，需要在device_info.hcs文件中添加deviceNode描述。deviceNode信息与驱动入口注册相关。 本例只有一个SPI控制器，如有多个器件信息，则需要在device_info.hcs文件增加deviceNode信息,以及在spi_config.hcs文件中增加对应的器件属性。器件属性值与核心层WatchdogCntlr成员的默认值或限制范围有密切关系，比如busNum设备号，需要在watchdog_config.hcs文件中增加对应的器件属性。

    独立服务模式的特点是device_info.hcs文件中设备节点代表着一个设备对象，如果存在多个设备对象，则按需添加，注意服务名与驱动私有数据匹配的关键字名称必须唯一。其中各项参数如表2所示：

    **表 2** device_info.hcs节点参数说明

    | 成员名 | 值 |
    | -------- | -------- |
    | policy | 驱动服务发布的策略，SPI控制器具体配置为2，表示驱动对内核态和用户态都发布服务 |
    | priority | 驱动启动优先级（0-200），值越大优先级越低。SPI控制器具体配置为60 |
    | permission | 驱动创建设备节点权限，SPI控制器具体配置为0664 |
    | moduleName | 驱动名称，SPI控制器固定为HDF_PLATFORM_SPI |
    | serviceName | 驱动对外发布服务的名称，SPI控制器服务名设置为HDF_PLATFORM_SPI_X，X代表SPI控制器编号|
    | deviceMatchAttr | 驱动私有数据匹配的关键字，SPI控制器设置为hisilicon_hi35xx_spi_X，X代表SPI控制器编号 |

    - device_info.hcs配置参考

        ```c
        root {
            device_info {
                match_attr = "hdf_manager";
                platform :: host {
                    hostName = "platform_host";
                    priority = 50;
                    device_spi :: device {                             // 为每一个SPI控制器配置一个HDF设备节点
                        device0 :: deviceNode {
                          policy = 2;
                          priority = 60;
                          permission = 0644;
                          moduleName = "HDF_PLATFORM_SPI";
                          serviceName = "HDF_PLATFORM_SPI_0";
                          deviceMatchAttr = "hisilicon_hi35xx_spi_0";
                        }
                        device1 :: deviceNode {
                          policy = 2;                                  // 驱动服务发布的策略，policy大于等于1（用户态可见为2，仅内核态可见为1）。
                          priority = 60;                               // 驱动启动优先级
                          permission = 0644;                           // 驱动创建设备节点权限
                          moduleName = "HDF_PLATFORM_SPI";             // 驱动名称，该字段的值必须和驱动入口结构的moduleName值一致。
                          serviceName = "HDF_PLATFORM_SPI_1";          // 驱动对外发布服务的名称，必须唯一，必须要按照HDF_PLATFORM_SPI_1的格式，X为SPI控制器编号。
                          deviceMatchAttr = "hisilicon_hi35xx_spi_1";  // 驱动私有数据匹配的关键字，必须和驱动私有数据配置表中的match_attr值一致。
                        }
                        ......                                         // 如果存在多个SPI设备时【必须】添加节点，否则不用
                    }
                }
            }
        }
        ```
   
    - spi_config.hcs配置参考
   
       
        ```c
        root {
            platform {
                spi_config {                                   // 每一个SPI控制器配置私有数据
                    template spi_controller {                  // 模板公共参数，继承该模板的节点如果使用模板中的默认值，则节点字段可以缺省。
                        serviceName = "";
                        match_attr = "";
                        transferMode = 0;                      // 数据传输模式：中断传输(0)、流控传输(1)、DMA传输(2)
                        busNum = 0;                            // 总线号
                        clkRate = 100000000;
                        bitsPerWord = 8;                       // 传输位宽
                        mode = 19;                             // SPI 数据的输入输出模式
                        maxSpeedHz = 0;                        // 最大时钟频率
                        minSpeedHz = 0;                        // 最小时钟频率
                        speed = 2000000;                       // 当前消息传输速度
                        fifoSize = 256;                        // FIFO大小
                        numCs = 1;                             // 片选号
                        regBase = 0x120c0000;                  // 地址映射需要
                        irqNum = 100;                          // 中断号
                        REG_CRG_SPI = 0x120100e4;              // CRG_REG_BASE(0x12010000) + 0x0e4
                        CRG_SPI_CKEN = 0;
                        CRG_SPI_RST = 0;
                        REG_MISC_CTRL_SPI = 0x12030024;        // MISC_REG_BASE(0x12030000) + 0x24
                        MISC_CTRL_SPI_CS = 0;
                        MISC_CTRL_SPI_CS_SHIFT = 0;
                    }
                    controller_0x120c0000 :: spi_controller {
                        busNum = 0;                            // 【必要】总线号
                        CRG_SPI_CKEN = 0x10000;                // (0x1 << 16) 0:close clk, 1:open clk
                        CRG_SPI_RST = 0x1;                     // (0x1 << 0) 0:cancel reset, 1:reset
                        match_attr = "hisilicon_hi35xx_spi_0"; // 【必要】需要和device_info.hcs中的deviceMatchAttr值一致
                    }
                    controller_0x120c1000 :: spi_controller {
                        busNum = 1;
                        CRG_SPI_CKEN = 0x20000;                // (0x1 << 17) 0:close clk, 1:open clk
                        CRG_SPI_RST = 0x2;                     // (0x1 << 1) 0:cancel reset, 1:reset
                        match_attr = "hisilicon_hi35xx_spi_1";
                        regBase = 0x120c1000;                  // 【必要】地址映射需要
                        irqNum = 101;                          // 【必要】中断号
                    }
                    ......                                     // 如果存在多个SPI设备时【必须】添加节点，否则不用
                }
            }
        }
        ```

        需要注意的是，新增spi_config.hcs配置文件后，必须在hdf.hcs文件中将其包含，否则配置文件无法生效。

        例如：本例中spi_config.hcs所在路径为device/soc/hisilicon/hi3516dv300/sdk_liteos/hdf_config/spi/spi_config.hcs，则必须在产品对应的hdf.hcs中添加如下语句：

        ```c
        #include "../../../../device/soc/hisilicon/hi3516dv300/sdk_liteos/hdf_config/spi/spi_config.hcs" // 配置文件相对路径
        ```

3. 实例化SPI控制器对象 

    完成属性文件配置之后，下一步就是以核心层SpiCntlr对象的初始化为核心，包括驱动适配者自定义结构体（传递参数和数据），实例化SpiCntlr成员SpiCntlrMethod（让用户可以通过接口来调用驱动底层函数），实现HdfDriverEntry成员函数（Bind、Init、Release）。

    - 自定义结构体参考。

        从驱动的角度看，自定义结构体是参数和数据的载体，而且spi_config.hcs文件中的数值会被HDF读入并通过DeviceResourceIface来初始化结构体成员，一些重要数值也会传递给核心层对象，例如设备号、总线号等。

        
        ```c
		// 对应于spi_config.hcs中的参数
        struct Pl022 {
            struct SpiCntlr *cntlr;
            struct DListHead deviceList;
            struct OsalSem sem;
            volatile unsigned char *phyBase;
            volatile unsigned char *regBase;
            uint32_t irqNum;
            uint32_t busNum;
            uint32_t numCs;
            uint32_t curCs;
            uint32_t speed;
            uint32_t fifoSize;
            uint32_t clkRate;
            uint32_t maxSpeedHz;
            uint32_t minSpeedHz;
            uint32_t regCrg;
            uint32_t clkEnBit;
            uint32_t clkRstBit;
            uint32_t regMiscCtrl;
            uint32_t miscCtrlCsShift;
            uint32_t miscCtrlCs;
            uint16_t mode;
            uint8_t bitsPerWord;
            uint8_t transferMode;
        };
     
        // SpiCntlr是核心层控制器结构体，其中的成员在Init函数中会被赋值。
        struct SpiCntlr {
            struct IDeviceIoService service;
            struct HdfDeviceObject *device;
            uint32_t busNum;
            uint32_t numCs;
            uint32_t curCs;
            struct OsalMutex lock;
            struct SpiCntlrMethod *method;
            struct DListHead list;
            void *priv;
        };
        ```

    - SpiCntlr成员钩子函数结构体SpiCntlrMethod的实例化。

        ```c
        // spi_hi35xx.c中的示例：钩子函数的实例化
        struct SpiCntlrMethod g_method = {
            .Transfer = Pl022Transfer,
            .SetCfg = Pl022SetCfg,
            .GetCfg = Pl022GetCfg,
            .Open = Pl022Open,
            .Close = Pl022Close,
        };
        ```

    - Bind函数参考。

        入参：

        HdfDeviceObject是整个驱动对外提供的接口参数，具备HCS配置文件的信息。

        返回值：

        HDF_STATUS相关状态。

        函数说明：

        将SpiCntlr对象同HdfDeviceObject进行了关联。
 
        ```c
        static int32_t HdfSpiDeviceBind(struct HdfDeviceObject *device)
        {
            ......
            return (SpiCntlrCreate(device) == NULL) ? HDF_FAILURE : HDF_SUCCESS;
        }

        struct SpiCntlr *SpiCntlrCreate(struct HdfDeviceObject *device)
        {
            struct SpiCntlr *cntlr = NULL;                            // 创建核心层SpiCntlr对象
            ......
            cntlr = (struct SpiCntlr *)OsalMemCalloc(sizeof(*cntlr)); // 分配内存
            ......
            cntlr->device = device;                                   // 使HdfDeviceObject与SpiCntlr可以相互转化的前提
            device->service = &(cntlr->service);                      // 使HdfDeviceObject与SpiCntlr可以相互转化的前提
            (void)OsalMutexInit(&cntlr->lock);                        // 锁初始化
            DListHeadInit(&cntlr->list);                              // 添加对应的节点
            cntlr->priv = NULL;
            return cntlr;
        }
        ```

    - Init函数开发参考。

        入参：

        HdfDeviceObject是整个驱动对外提供的接口参数，具备HCS配置文件的信息。

        返回值：

        HDF_STATUS相关状态（表3为部分展示，如需使用其他状态，可参考//drivers/hdf_core/interfaces/inner_api/utils/hdf_base.h中HDF_STATUS定义）。

        **表 3** HDF_STATUS相关状态说明

        | 状态(值) | 描述 | 
        | -------- | -------- |
        | HDF_ERR_INVALID_OBJECT | 控制器对象非法 | 
        | HDF_ERR_MALLOC_FAIL | 内存分配失败 | 
        | HDF_ERR_INVALID_PARAM | 参数非法 | 
        | HDF_ERR_IO | I/O&nbsp;错误 | 
        | HDF_SUCCESS | 初始化成功 | 
        | HDF_FAILURE | 初始化失败 | 

        函数说明：

        初始化自定义结构体对象，初始化SpiCntlr成员。

        ```c
        static int32_t HdfSpiDeviceInit(struct HdfDeviceObject *device)
        {
            int32_t ret;
            struct SpiCntlr *cntlr = NULL;
            ......
            cntlr = SpiCntlrFromDevice(device); // 这里有HdfDeviceObject到SpiCntlr的强制转换，通过service成员，赋值见Bind函数。
                                                // return (device == NULL) ? NULL : (struct SpiCntlr *)device->service;
            ......
            ret = Pl022Init(cntlr, device);     // 【必要】实例化驱动适配者自定义操作对象，示例见下。
            ......
            ret = Pl022Probe(cntlr->priv);
            ......
            return ret;
        }

        static int32_t Pl022Init(struct SpiCntlr *cntlr, const struct HdfDeviceObject *device)
        {
            int32_t ret;
            struct Pl022 *pl022 = NULL;
            ......
            pl022 = (struct Pl022 *)OsalMemCalloc(sizeof(*pl022)); // 申请内存
            ......
            ret = SpiGetBaseCfgFromHcs(pl022, device->property);   // 初始化busNum、numCs、speed、fifoSize、clkRate、mode、bitsPerWord、transferMode参数值。
            ......
            ret = SpiGetRegCfgFromHcs(pl022, device->property);    // 初始化regBase、phyBase、irqNum、regCrg、clkEnBit、clkRstBit、regMiscCtrl、regMiscCtrl、 miscCtrlCs、miscCtrlCsShift参数值。
            ......
            // 计算最大、最小速度对应的频率。
            pl022->maxSpeedHz = (pl022->clkRate) / ((SCR_MIN + 1) * CPSDVSR_MIN);
            pl022->minSpeedHz = (pl022->clkRate) / ((SCR_MAX + 1) * CPSDVSR_MAX);
            DListHeadInit(&pl022->deviceList); // 初始化DList链表
            pl022->cntlr = cntlr;              // 使Pl022与SpiCntlr可以相互转化的前提
            cntlr->priv = pl022;               // 使Pl022与SpiCntlr可以相互转化的前提
            cntlr->busNum = pl022->busNum;     // 给SpiCntlr的busNum赋值
            cntlr->method = &g_method;         // SpiCntlrMethod的实例化对象的挂载
            ......
            ret = Pl022CreatAndInitDevice(pl022);
            if (ret != 0) {
                Pl022Release(pl022);           // 初始化失败则释放Pl022对象
                return ret;
            }
            return 0;
        }
        ```

    - Release函数开发参考

        入参：

        HdfDeviceObject是整个驱动对外提供的接口参数，具备HCS配置文件的信息。

        返回值：

        无。

        函数说明：

        释放内存和删除控制器，该函数需要在驱动入口结构体中赋值给Release接口，当HDF框架调用Init函数初始化驱动失败时，可以调用Release释放驱动资源。

        > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**<br>
        > 所有强制转换获取相应对象的操作前提是在Init函数中具备对应赋值的操作。

        ```c
        static void HdfSpiDeviceRelease(struct HdfDeviceObject *device)
        {
            struct SpiCntlr *cntlr = NULL;
            ......
            cntlr = SpiCntlrFromDevice(device);             // 这里有HdfDeviceObject到SpiCntlr的强制转换，通过service成员，赋值见Bind函数
                                                            // return (device==NULL) ?NULL:(struct SpiCntlr *)device->service;
            ......
            if (cntlr->priv != NULL) {
                Pl022Remove((struct Pl022 *)cntlr->priv);   // 这里有SpiCntlr到Pl022的强制转换
            }
            SpiCntlrDestroy(cntlr);                         // 释放Pl022对象
        }
        ```

4. 驱动调试

    【可选】针对新增驱动程序，建议验证驱动基本功能，例如挂载后的信息反馈，SPI获取设备属性、SPI设置设备属性、SPI传输等。
