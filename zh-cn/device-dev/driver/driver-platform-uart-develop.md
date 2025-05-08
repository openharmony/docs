# UART

## 概述

### 功能简介

UART指异步收发传输器（Universal Asynchronous Receiver/Transmitter），是通用串行数据总线，用于异步通信。该总线双向通信，可以实现全双工传输。

两个UART设备的连接示意图如下，UART与其他模块一般用2线（图1）或4线（图2）相连，它们分别是：

- TX：发送数据端，和对端的RX相连。

- RX：接收数据端，和对端的TX相连。

- RTS：发送请求信号，用于指示本设备是否准备好，可接受数据，和对端CTS相连。

- CTS：允许发送信号，用于判断是否可以向对端发送数据，和对端RTS相连。

**图 1** 2线UART设备连接示意图

![2线UART设备连接示意图](figures/2线UART设备连接示意图.png)

**图 2** 4线UART设备连接示意图

![4线UART设备连接示意图](figures/4线UART设备连接示意图.png)

UART通信之前，收发双方需要约定好一些参数：波特率、数据格式（起始位、数据位、校验位、停止位）等。通信过程中，UART通过TX发送给对端数据，通过RX接收对端发送的数据。当UART接收缓存达到预定的门限值时，RTS变为不可发送数据，对端的CTS检测到不可发送数据，则停止发送数据。

### 基本概念

- 异步通信

    异步通信中，数据通常以字符或者字节为单位组成字符帧传送。字符帧由发送端逐帧发送，通过传输线被接收设备逐帧接收。发送端和接收端可以由各自的时钟来控制数据的发送和接收，这两个时钟源彼此独立，互不同步。异步通信以一个字符为传输单位，通信中两个字符间的时间间隔是不固定的，然而在同一个字符中的两个相邻位代码间的时间间隔是固定的。

- 全双工传输（Full Duplex）

    此通信模式允许数据在两个方向上同时传输，它在能力上相当于两个单工通信方式的结合。全双工可以同时进行信号的双向传输。

### 运作机制

在HDF框架中，UART接口适配模式采用独立服务模式（如图3所示）。在这种模式下，每一个设备对象会独立发布一个设备服务来处理外部访问，设备管理器收到API的访问请求之后，通过提取该请求的参数，达到调用实际设备对象的相应内部方法的目的。独立服务模式可以直接借助HDF设备管理器的服务管理能力，但需要为每个设备单独配置设备节点，增加内存占用。

独立服务模式下，核心层不会统一发布一个服务供上层使用，因此这种模式下驱动要为每个控制器发布一个服务，具体表现为：

- 驱动适配者需要实现HdfDriverEntry的Bind钩子函数以绑定服务。

- device_info.hcs文件中deviceNode的policy字段为1或2，不能为0。

UART模块各分层作用：

- 接口层提供打开UART设备、UART设备读取指定长度数据、UART设备写入指定长度数据、设置UART设备波特率、获取设UART设备波特率、设置UART设备属性、获取UART设备波特率、设置UART设备传输模式、关闭UART设备的接口。

- 核心层主要提供UART控制器的创建、移除以及管理的能力，通过钩子函数与适配层交互。

- 适配层主要是将钩子函数的功能实例化，实现具体的功能。

**图 3** UART独立服务模式结构图

![UART独立服务模式结构图](figures/独立服务模式结构图.png)

## 开发指导

### 场景介绍

UART模块应用比较广泛，主要用于实现设备之间的低速串行通信，例如输出打印信息，当然也可以外接各种模块，如GPS、蓝牙等。当驱动开发者需要将UART设备适配到OpenHarmony时，需要进行UART驱动适配。下文将介绍如何进行UART驱动适配。

### 接口说明

为了保证上层在调用UART接口时能够正确的操作UART控制器，核心层在//drivers/hdf_core/framework/support/platform/include/uart/uart_core.h中定义了以下钩子函数，驱动适配者需要在适配层实现这些函数的具体功能，并与钩子函数挂接，从而完成适配层与核心层的交互。

UartHostMethod定义：

```c
struct UartHostMethod {
    int32_t (*Init)(struct UartHost *host);
    int32_t (*Deinit)(struct UartHost *host);
    int32_t (*Read)(struct UartHost *host, uint8_t *data, uint32_t size);
    int32_t (*Write)(struct UartHost *host, uint8_t *data, uint32_t size);
    int32_t (*GetBaud)(struct UartHost *host, uint32_t *baudRate);
    int32_t (*SetBaud)(struct UartHost *host, uint32_t baudRate);
    int32_t (*GetAttribute)(struct UartHost *host, struct UartAttribute *attribute);
    int32_t (*SetAttribute)(struct UartHost *host, struct UartAttribute *attribute);
    int32_t (*SetTransMode)(struct UartHost *host, enum UartTransMode mode);
    int32_t (*pollEvent)(struct UartHost *host, void *filep, void *table);
};
```

**表 1** UartHostMethod结构体成员的回调函数功能说明

| 函数 | 入参 | 出参 | 返回值 | 功能 |
| -------- | -------- | -------- | -------- | -------- |
| Init | host：结构体指针，核心层UART控制器 | 无 | HDF_STATUS相关状态 | 初始化Uart设备 |
| Deinit | host：结构体指针，核心层UART控制器 | 无 | HDF_STATUS相关状态 | 去初始化Uart设备 |
| Read | host：结构体指针，核心层UART控制器<br>size：uint32_t类型，接收数据大小 | data：uint8_t类型指针，接收的数据 | HDF_STATUS相关状态 | 接收数据RX |
| Write | host：结构体指针，核心层UART控制器<br>data：uint8_t类型指针，传入数据<br>size：uint32_t类型，发送数据大小 | 无 | HDF_STATUS相关状态 | 发送数据TX |
| SetBaud | host：结构体指针，核心层UART控制器<br>baudRate：uint32_t类型，波特率传入值 | 无 | HDF_STATUS相关状态 | 设置波特率 |
| GetBaud | host：结构体指针，核心层UART控制器 | baudRate：uint32_t类型指针，传出的波特率 | HDF_STATUS相关状态 | 获取当前设置的波特率 |
| GetAttribute | host：结构体指针，核心层UART控制器 | attribute：结构体指针，传出的属性值（见uart_if.h中UartAttribute定义） | HDF_STATUS相关状态 | 获取设备uart相关属性 |
| SetAttribute | host：结构体指针，核心层UART控制器<br>attribute：结构体指针，属性传入值 | 无 | HDF_STATUS相关状态 | 设置设备UART相关属性 |
| SetTransMode | host：结构体指针，核心层UART控制器<br>mode：枚举值（见uart_if.h中UartTransMode定义），传输模式 | 无 | HDF_STATUS相关状态 | 设置传输模式 |
| PollEvent | host：结构体指针，核心层UART控制器<br>filep：void类型指针filep<br>table：void类型指针table | 无 | HDF_STATUS相关状态 | poll轮询机制 |

### 开发步骤

UART模块适配HDF框架包含以下四个步骤：

- 实例化驱动入口

- 配置属性文件

- 实例化UART控制器对象

- 驱动调试

### 开发实例

下方将基于Hi3516DV300开发板以//device/soc/hisilicon/common/platform/uart/uart_hi35xx.c驱动为示例，展示需要驱动适配者提供哪些内容来完整实现设备功能。

1. 实例化驱动入口

    驱动入口必须为HdfDriverEntry（在hdf_device_desc.h中定义）类型的全局变量，且moduleName要和device_info.hcs中保持一致。HDF框架会将所有加载的驱动的HdfDriverEntry对象首地址汇总，形成一个类似数组的段地址空间，方便上层调用。

    一般在加载驱动时HDF会先调用Bind函数，再调用Init函数加载该驱动。当Init调用异常时，HDF框架会调用Release释放驱动资源并退出。

    UART驱动入口开发参考：

    ```c
    struct HdfDriverEntry g_hdfUartDevice = {
        .moduleVersion = 1,
        .moduleName = "HDF_PLATFORM_UART",    // 【必要且与HCS文件中里面的moduleName匹配】
        .Bind = HdfUartDeviceBind,            // 挂接UART模块Bind实例化
        .Init = HdfUartDeviceInit,            // 挂接UART模块Init实例化
        .Release = HdfUartDeviceRelease,      // 挂接UART模块Release实例化
    };
    HDF_INIT(g_hdfUartDevice);                // 调用HDF_INIT将驱动入口注册到HDF框架中
    ```

2. 配置属性文件

    完成驱动入口注册之后，需要在device_info.hcs文件中添加deviceNode信息，deviceNode信息与驱动入口注册相关。本例以两个UART控制器为例，如有多个器件信息，则需要在device_info.hcs文件增加对应的deviceNode信息，以及在uart_config.hcs文件中增加对应的器件属性。器件属性值与核心层UartHost成员的默认值或限制范围有密切关系，比如UART设备端口号，需要在uart_config.hcs文件中增加对应的器件属性。

    独立服务模式的特点是device_info.hcs文件中设备节点代表着一个设备对象，如果存在多个设备对象，则按需添加，注意服务名与驱动私有数据匹配的关键字名称必须唯一。其中各项参数如表2所示：

    **表 2** device_info.hcs节点参数说明

    | 成员名 | 值 |
    | -------- | -------- |
    | policy | 驱动服务发布的策略，UART控制器具体配置为2，表示驱动对内核态和用户态都发布服务 |
    | priority | 驱动启动优先级（0-200），值越大优先级越低。UART控制器具体配置为40 |
    | permission | 驱动创建设备节点权限，UART控制器具体配置为0664 |
    | moduleName | 驱动名称，UART控制器固定为HDF_PLATFORM_UART |
    | serviceName | 驱动对外发布服务的名称，UART控制器服务名设置为HDF_PLATFORM_UART_X，X代表UART控制器编号 |
    | deviceMatchAttr | 驱动私有数据匹配的关键字，UART控制器设置为hisilicon_hi35xx_uart_X ，X代表UART控制器编号 |

    - device_info.hcs 配置参考：

        在//vendor/hisilicon/hispark_taurus/hdf_config/device_info/device_info.hcs文件中添加deviceNode描述。

        ```c
        root {
            device_info {
                match_attr = "hdf_manager";
                platform :: host {
                    hostName = "platform_host";
                    priority = 50;
                    device_uart :: device {
                        device0 :: deviceNode {
                            policy = 1;                                   // 驱动服务发布的策略，policy大于等于1（用户态可见为2，仅内核态可见为1）。
                            priority = 40;                                // 驱动启动优先级
                            permission = 0644;                            // 驱动创建设备节点权限
                            moduleName = "HDF_PLATFORM_UART";             // 驱动名称，该字段的值必须和驱动入口结构的moduleName值一致。
                            serviceName = "HDF_PLATFORM_UART_0";          // 驱动对外发布服务的名称，必须唯一，必须要按照HDF_PLATFORM_UART_X的格式，X为UART控制器编号。
                            deviceMatchAttr = "hisilicon_hi35xx_uart_0";  // 驱动私有数据匹配的关键字，必须和驱动私有数据配置表中的match_attr值一致。
                        }
                        device1 :: deviceNode {
                          policy = 2;
                          permission = 0644;
                          priority = 40;
                          moduleName = "HDF_PLATFORM_UART"; 
                          serviceName = "HDF_PLATFORM_UART_1";
                          deviceMatchAttr = "hisilicon_hi35xx_uart_1";
                        }
                        ......                                            // 如果存在多个UART设备时【必须】添加节点，否则不用
                    }
                }
            }
        }
        ```

    - uart_config.hcs 配置参考：

        在//device/soc/hisilicon/hi3516dv300/sdk_liteos/hdf_config/uart/uart_config.hcs文件配置器件属性，其中配置参数如下：

        ```c
        root {
            platform {
                template uart_controller {                   // 配置模板，如果下面节点使用时继承该模板，则节点中未声明的字段会使用该模板中的默认值
                    match_attr = "";
                    num = 0;                                 // 【必要】端口号
                    baudrate = 115200;                       // 【必要】波特率，数值可按需填写
                    fifoRxEn = 1;                            // 【必要】使能接收FIFO
                    fifoTxEn = 1;                            // 【必要】使能发送FIFO
                    flags = 4;                               // 【必要】标志信号
                    regPbase = 0x120a0000;                   // 【必要】地址映射需要
                    interrupt = 38;                          // 【必要】中断号
                    iomemCount = 0x48;                       // 【必要】地址映射需要
                }
                controller_0x120a0000 :: uart_controller {
                    match_attr = "hisilicon_hi35xx_uart_0";  // 【必要】必须和device_info.hcs中对应的设备的deviceMatchAttr值一致
                }
                controller_0x120a1000 :: uart_controller {
                    num = 1;
                    baudrate = 9600;
                    regPbase = 0x120a1000;
                    interrupt = 39;
                    match_attr = "hisilicon_hi35xx_uart_1";
                }
                ......                                       // 如果存在多个UART设备时【必须】添加节点，否则不用
            }
        }
        ```

        需要注意的是，新增uart_config.hcs配置文件后，必须在产品对应的hdf.hcs文件中将其包含如下语句所示，否则配置文件无法生效。

        例如：本例中uart_config.hcs所在路径为device/soc/hisilicon/hi3516dv300/sdk_liteos/hdf_config/uart/uart_config.hcs，则必须在产品对应的hdf.hcs中添加如下语句：

        ```c
        #include "../../../../device/soc/hisilicon/hi3516dv300/sdk_liteos/hdf_config/uart/uart_config.hcs" // 配置文件相对路径
        ```

3. 实例化UART控制器对象

    完成属性文件配置之后，下一步就是以核心层UartHost对象的初始化为核心，包括驱动适配者自定义结构体（传递参数和数据），实例化UartHost成员UartHostMethod（让用户可以通过接口来调用驱动底层函数），实现HdfDriverEntry成员函数（Bind、Init、Release）。

    - 驱动适配者自定义结构体参考。

        从驱动的角度看，驱动适配者自定义结构体是参数和数据的载体，而且uart_config.hcs文件中的数值会被HDF读入并通过DeviceResourceIface来初始化结构体成员，一些重要数值也会传递给核心层对象，例如端口号。

        ```c
        struct UartPl011Port {                       // 驱动适配者自定义管脚描述结构体
            int32_t enable;
            unsigned long physBase;                  // 物理地址
            uint32_t irqNum;                         // 中断号
            uint32_t defaultBaudrate;                // 默认波特率
            uint32_t flags;                          // 标志信号，下面三个宏与之相关
        #define PL011_FLG_IRQ_REQUESTED    (1 << 0)
        #define PL011_FLG_DMA_RX_REQUESTED (1 << 1)
        #define PL011_FLG_DMA_TX_REQUESTED (1 << 2)
            struct UartDmaTransfer *rxUdt;           // DMA传输相关
            struct UartDriverData *udd;
        };
        struct UartDriverData {                      // 数据传输相关的结构体
            uint32_t num;                            // 端口号
            uint32_t baudrate;                       // 波特率（可设置）
            struct UartAttribute attr;               // 数据位、停止位等传输属性相关
            struct UartTransfer *rxTransfer;         // 缓冲区相关，可理解为FIFO结构
            wait_queue_head_t wait;                  // 条件变量相关的排队等待信号
            int32_t count;                           // 数据数量
            int32_t state;                           // UART控制器状态
        #define UART_STATE_NOT_OPENED 0
        #define UART_STATE_OPENING    1
        #define UART_STATE_USEABLE    2
        #define UART_STATE_SUSPENDED  3
            uint32_t flags;                          // 状态标志
        #define UART_FLG_DMA_RX       (1 << 0)
        #define UART_FLG_DMA_TX       (1 << 1)
        #define UART_FLG_RD_BLOCK     (1 << 2)
            RecvNotify recv;                         // 函数指针类型，指向串口数据接收函数
            struct UartOps *ops;                     // 自定义函数指针结构体
            void *private;                           // 私有数据
        };
        
        // UartHost是核心层控制器结构体，其中的成员在Init函数中会被赋值。
        struct UartHost {
            struct IDeviceIoService service;         // 驱动服务
            struct HdfDeviceObject *device;          // 驱动设备对象
            uint32_t num;                            // 端口号
            OsalAtomic atom;                         // 原子量
            void *priv;                              // 私有数据
            struct UartHostMethod *method;           // 回调函数
        };
        ```

    - UartHost成员回调函数结构体UartHostMethod的实例化。

        ```c
        // uart_hi35xx.c 中的示例：钩子函数的实例化
        struct UartHostMethod g_uartHostMethod = {
            .Init = Hi35xxInit,                     // 初始化
            .Deinit = Hi35xxDeinit,                 // 去初始化
            .Read = Hi35xxRead,                     // 接收数据
            .Write = Hi35xxWrite,                   // 发送数据
            .SetBaud = Hi35xxSetBaud,               // 设置波特率
            .GetBaud = Hi35xxGetBaud,               // 获取波特率
            .SetAttribute = Hi35xxSetAttribute,     // 设置设备属性
            .GetAttribute = Hi35xxGetAttribute,     // 获取设备属性
            .SetTransMode = Hi35xxSetTransMode,     // 设置传输模式
            .pollEvent = Hi35xxPollEvent,           // 轮询
        };
        ```

    - Bind函数开发参考。

        入参：

        HdfDeviceObject：HDF框架给每一个驱动创建的设备对象，用来保存设备相关的私有数据和服务接口。

        返回值：

        HDF_STATUS相关状态（表3为部分展示，如需使用其他状态，可参考//drivers/hdf_core/interfaces/inner_api/utils/hdf_base.h中HDF_STATUS中HDF_STATUS定义）。

        **表 3** HDF_STATUS相关状态说明

        | 状态(值) | 问题描述 |
        | -------- | -------- |
        | HDF_ERR_INVALID_OBJECT | 控制器对象非法 |
        | HDF_ERR_MALLOC_FAIL | 内存分配失败 |
        | HDF_ERR_INVALID_PARAM | 参数非法 |
        | HDF_ERR_IO | I/O&nbsp;错误 |
        | HDF_SUCCESS | 初始化成功 |
        | HDF_FAILURE | 初始化失败 |

        函数说明：

        初始化自定义结构体对象，初始化UartHost成员。

        ```c
        //uart_hi35xx.c
        static int32_t HdfUartDeviceBind(struct HdfDeviceObject *device)
        {
            ......
            return (UartHostCreate(device) == NULL) ? HDF_FAILURE : HDF_SUCCESS; // 【必须】调用核心层函数UartHostCreate
        }

        // uart_core.c核心层UartHostCreate函数说明
        struct UartHost *UartHostCreate(struct HdfDeviceObject *device)
        {
            struct UartHost *host = NULL;                                        // 新建UartHost
            ......                                                                  
            host = (struct UartHost *)OsalMemCalloc(sizeof(*host));              // 分配内存
            ......
            host->device = device;                                               // 【必要】使HdfDeviceObject与UartHost可以相互转化的前提
            device->service = &(host->service);                                  // 【必要】使HdfDeviceObject与UartHost可以相互转化的前提
            host->device->service->Dispatch = UartIoDispatch;                    // 为service成员的Dispatch方法赋值
            OsalAtomicSet(&host->atom, 0);                                       // 原子量初始化或者原子量设置
            host->priv = NULL;
            host->method = NULL;
            return host;
        }
        ```

    - Init函数开发参考。

        入参：

        HdfDeviceObject：HDF框架给每一个驱动创建的设备对象，用来保存设备相关的私有数据和服务接口。

        返回值：

        HDF_STATUS相关状态。

        函数说明：

        初始化自定义结构体对象，初始化UartHost成员，调用核心层UartAddDev函数，完成UART控制器的添加，接入VFS。
 
        ```c
        int32_t HdfUartDeviceInit(struct HdfDeviceObject *device)
        {
            int32_t ret;
            struct UartHost *host = NULL;
            HDF_LOGI("%s: entry", __func__);
            ......
            host = UartHostFromDevice(device);                                           // 通过service成员后强制转为UartHost，赋值是在Bind函数中
            ......                                    
            ret = Hi35xxAttach(host, device);                                            // 完成UartHost对象的初始化，见下
            ......                                   
            host->method = &g_uartHostMethod;                                            // UartHostMethod的实例化对象的挂载
            return ret;
        }
        // 完成UartHost对象的初始化。
        static int32_t Hi35xxAttach(struct UartHost *host, struct HdfDeviceObject *device)
        {
            int32_t ret;
            struct UartDriverData *udd = NULL;                                           // udd和port对象是驱动适配者自定义的结构体对象，可根据需要实现相关功能
            struct UartPl011Port *port = NULL;
            ......
            // 【必要】步骤【1】~【7】主要实现对udd对象的实例化赋值，然后赋值给核心层UartHost对象。
            udd = (struct UartDriverData *)OsalMemCalloc(sizeof(*udd));                  // 【1】
            ......
            port = (struct UartPl011Port *)OsalMemCalloc(sizeof(struct UartPl011Port));  // 【2】
            ......
            udd->ops = Pl011GetOps();                                                    // 【3】设备开启、关闭、属性设置、发送操作等函数挂载。
            udd->recv = PL011UartRecvNotify;                                             // 【4】数据接收通知函数（条件锁机制）挂载
            udd->count = 0;                                                              // 【5】
            port->udd = udd;                                                             // 【6】使UartPl011Port与UartDriverData可以相互转化的前提
            ret = UartGetConfigFromHcs(port, device->property);                          // 将HdfDeviceObject的属性传递给驱动适配者自定义结构体，用于相关操作，示例代码见下
            ......
            udd->private = port;                                                         // 【7】
            host->priv = udd;                                                            // 【必要】使UartHost与UartDriverData可以相互转化的前提
            host->num = udd->num;                                                        // 【必要】UART设备号
            UartAddDev(host);                                                            // 【必要】核心层uart_dev.c中的函数，作用：注册一个字符设备节点到vfs，这样从用户态可以通过这个虚拟文件节点访问UART  
            return HDF_SUCCESS;
        }

        static int32_t UartGetConfigFromHcs(struct UartPl011Port *port, const struct DeviceResourceNode *node)
        {
            uint32_t tmp, regPbase, iomemCount;
            struct UartDriverData *udd = port->udd;
            struct DeviceResourceIface *iface = DeviceResourceGetIfaceInstance(HDF_CONFIG_SOURCE); 
            ......
            // 通过请求参数提取相应的值，并赋值给驱动适配者自定义的结构体。
            if (iface->GetUint32(node, "num", &udd->num, 0) != HDF_SUCCESS) {
                HDF_LOGE("%s: read busNum fail", __func__);
                return HDF_FAILURE;
            }
            ......
            return 0;
        }
        ```

    - Release函数开发参考。

        入参：

        HdfDeviceObject：HDF框架给每一个驱动创建的设备对象，用来保存设备相关的私有数据和服务接口。

        返回值：

        无。

        函数说明：

        该函数需要在驱动入口结构体中赋值给Release接口，当HDF框架调用Init函数初始化驱动失败时，可以调用Release释放驱动资源，该函数中需包含释放内存和删除控制器等操作。

        > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**<br>
        > 所有强制转换获取相应对象的操作前提是在Init函数中具备对应赋值的操作。

        ```c
        void HdfUartDeviceRelease(struct HdfDeviceObject *device)
        {
            struct UartHost *host = NULL;
            ...
            host = UartHostFromDevice(device);           // 这里有HdfDeviceObject到UartHost的强制转化，通过service成员，赋值见Bind函数。
            ...                                          
            if (host->priv != NULL) {                    
                Hi35xxDetach(host);                      // 驱动适配自定义的内存释放函数，见下。
            }                                            
            UartHostDestroy(host);                       // 调用核心层函数释放host
        }

        static void Hi35xxDetach(struct UartHost *host)
        {
            struct UartDriverData *udd = NULL;
            struct UartPl011Port *port = NULL;
            ...
            udd = host->priv;                            // 这里有UartHost到UartDriverData的转化
            ...                                          
            UartRemoveDev(host);                         // VFS注销
            port = udd->private;                         // 这里有UartDriverData到UartPl011Port的转化
            if (port != NULL) {                          
                if (port->physBase != 0) {               
                    OsalIoUnmap((void *)port->physBase); // 地址反映射
                }
                OsalMemFree(port);
                udd->private = NULL;
            }
            OsalMemFree(udd);                            // 释放UartDriverData
            host->priv = NULL;
        }
        ```

4. 驱动调试

   【可选】针对新增驱动程序，建议验证驱动基本功能，例如挂载后的信息反馈，数据传输的成功与否等。
