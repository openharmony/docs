# GPIO

## 概述

### 功能简介

GPIO（General-purpose input/output）即通用型输入输出。通常，GPIO控制器通过分组的方式管理所有GPIO管脚，每组GPIO有一个或多个寄存器与之关联，通过读写寄存器完成对GPIO管脚的操作。

### 基本概念

GPIO又俗称为I/O口，I指的是输入(in），O指的是输出（out）。可以通过软件来控制其输入和输出，即I/O控制。

- GPIO输入

    输入是检测各个引脚上的电平状态，高电平或者低电平状态。常见的输入模式有：模拟输入、浮空输入、上拉输入、下拉输入。

- GPIO输出

    输出是当需要控制引脚电平的高低时需要用到输出功能。常见的输出模式有：开漏输出、推挽输出、复用开漏输出、复用推挽输出。

### 运作机制

在HDF框架中，同类型设备对象较多时（可能同时存在十几个同类型配置器），若采用独立服务模式，则需要配置更多的设备节点，且相关服务会占据更多的内存资源。相反，采用统一服务模式可以使用一个设备服务作为管理器，统一处理所有同类型对象的外部访问（这会在配置文件中有所体现），实现便捷管理和节约资源的目的。GPIO模块采用统一服务模式（如图1所示）。

在统一模式下，所有的控制器都被核心层统一管理，并由核心层统一发布一个服务供接口层，因此这种模式下驱动无需再为每个控制器发布服务。

GPIO模块各分层作用：

- 接口层：提供操作GPIO管脚的标准方法。

- 核心层：提供GPIO管脚资源匹配，GPIO管脚控制器的添加、移除以及管理的能力，通过钩子函数与适配层交互，供芯片厂家快速接入HDF框架。

- 适配层：由驱动适配者将钩子函数的功能实例化，实现与硬件相关的具体功能。

**图 1**  GPIO统一服务模式结构图

![GPIO统一服务模式结构图](figures/统一服务模式结构图.png)

## 开发指导

### 场景介绍

GPIO主要是对GPIO管脚资源进行管理。驱动开发者可以使用GPIO模块提供的操作接口，实现对管脚的具体控制。当驱动开发者需要将GPIO适配到OpenHarmony时，需要进行GPIO驱动适配。下文将介绍如何进行GPIO驱动适配。

### 接口说明

为了保证上层在调用GPIO接口时能够正确的操作GPIO管脚，核心层在//drivers/hdf_core/framework/support/platform/include/gpio/gpio_core.h中定义了以下钩子函数，驱动适配者需要在适配层实现这些函数的具体功能，并与钩子函数挂接，从而完成适配层与核心层的交互。

GpioMethod定义：

```c
struct GpioMethod {
    int32_t (*request)(struct GpioCntlr *cntlr, uint16_t local);                 // 【预留】
    int32_t (*release)(struct GpioCntlr *cntlr, uint16_t local);                 // 【预留】
    int32_t (*write)(struct GpioCntlr *cntlr, uint16_t local, uint16_t val);
    int32_t (*read)(struct GpioCntlr *cntlr, uint16_t local, uint16_t *val);
    int32_t (*setDir)(struct GpioCntlr *cntlr, uint16_t local, uint16_t dir);
    int32_t (*getDir)(struct GpioCntlr *cntlr, uint16_t local, uint16_t *dir);
    int32_t (*toIrq)(struct GpioCntlr *cntlr, uint16_t local, uint16_t *irq);    // 【预留】
    int32_t (*setIrq)(struct GpioCntlr *cntlr, uint16_t local, uint16_t mode);
    int32_t (*unsetIrq)(struct GpioCntlr *cntlr, uint16_t local);
    int32_t (*enableIrq)(struct GpioCntlr *cntlr, uint16_t local);
    int32_t (*disableIrq)(struct GpioCntlr *cntlr, uint16_t local);
}
```

**表 1** GpioMethod结构体成员的钩子函数功能说明

| 函数成员 | 入参 | 出参 | 返回值 | 功能 |
| -------- | -------- | -------- | -------- | -------- |
| write | cntlr：结构体指针，核心层GPIO控制器<br/>local：uint16_t类型，GPIO端口标识号<br/>val：uint16_t类型，电平传入值 | 无 | HDF_STATUS相关状态 | GPIO引脚写入电平值 |
| read | cntlr：结构体指针，核心层GPIO控制器<br/>local：uint16_t类型，GPIO端口标识号 | val：uint16_t类型指针，用于传出电平值。 | HDF_STATUS相关状态 | GPIO引脚读取电平值 |
| setDir | cntlr：结构体指针，核心层GPIO控制器<br/>local：uint16_t类型，GPIO端口标识号<br/>dir：uint16_t类型，管脚方向传入值 | 无 | HDF_STATUS相关状态 | 设置GPIO引脚输入/输出方向 |
| getDir | cntlr：结构体指针，核心层GPIO控制器<br/>local：uint16_t类型，GPIO端口标识号 | dir：uint16_t类型指针，用于传出管脚方向值。 | HDF_STATUS相关状态 | 读GPIO引脚输入/输出方向 |
| setIrq | cntlr：结构体指针，核心层GPIO控制器<br/>local：uint16_t类型，GPIO端口标识号<br/>mode：uint16_t类型，表示触发模式（边沿或电平） | 无 | HDF_STATUS相关状态 | 将GPIO引脚设置为中断模式 |
| unsetIrq | cntlr：结构体指针，核心层GPIO控制器<br/>local：uint16_t类型，GPIO端口标识号 | 无 | HDF_STATUS相关状态 | 取消GPIO中断设置 |
| enableIrq | cntlr：结构体指针，核心层GPIO控制器<br/>local：uint16_t类型，GPIO端口标识号 | 无 | HDF_STATUS相关状态 | 使能GPIO管脚中断 |
| disableIrq | cntlr：结构体指针，核心层GPIO控制器<br/>local：uint16_t类型，GPIO端口标识号 | 无 | HDF_STATUS相关状态 | 禁止GPIO管脚中断 |

### 开发步骤

GPIO模块适配包含以下四个步骤：

- 实例化驱动入口

- 配置属性文件

- 实例化GPIO控制器对象

- 驱动调试

### 开发实例

下方将基于Hi3516DV300开发板以//device/soc/hisilicon/common/platform/gpio/gpio_hi35xx.c驱动为示例，展示需要驱动适配者提供哪些内容来完整实现设备功能。

1. 实例化驱动入口

    驱动入口必须为HdfDriverEntry（在hdf_device_desc.h中定义）类型的全局变量，且moduleName要和device_info.hcs中保持一致。HDF框架会将所有加载的驱动的HdfDriverEntry对象首地址汇总，形成一个类似数组的段地址空间，方便上层调用。

    一般在加载驱动时HDF会先调用Bind函数，再调用Init函数加载该驱动。当Init调用异常时，HDF框架会调用Release释放驱动资源并退出。

    GPIO驱动入口开发参考：

    ```c
    struct HdfDriverEntry g_gpioDriverEntry = {
        .moduleVersion = 1,
        .Bind = Pl061GpioBind,                // GPIO不需要实现Bind，本例是一个空实现，驱动适配者可根据自身需要添加相关操作
        .Init = Pl061GpioInit,                // 挂接Gpio模块Init实例化
        .Release = Pl061GpioRelease,          // 挂接Gpio模块Release实例化
        .moduleName = "hisi_pl061_driver",    // 【必要且需要与HCS文件中里面的moduleName匹配】
    };
    HDF_INIT(g_gpioDriverEntry);              // 调用HDF_INIT将驱动入口注册到HDF框架中
    ```

2. 配置属性文件

    完成驱动入口注册之后，下一步请在device_info.hcs文件中添加deviceNode信息，deviceNode信息与驱动入口注册相关。本例以一个GPIO控制器为例，如有多个器件信息，则需要在device_info.hcs文件增加deviceNode信息，以及在gpio_config.hcs文件中增加对应的器件属性。器件属性值与核心层GpioCntlr成员的默认值或限制范围有密切关系，需要在gpio_config.hcs中配置器件属性。

    统一服务模式的特点是device_info.hcs文件中第一个设备节点必须为GPIO管理器，其各项参数如表2所示：

    **表 2** device_info.hcs节点参数说明

    | 成员名 | 值 |
    | -------- | -------- |
    | policy | 驱动服务发布的策略，GPIO管理器具体配置为2，表示驱动对内核态和用户态都发布服务 |
    | priority | 驱动启动优先级（0-200），值越大优先级越低。GPIO管理器具体配置为10 |
    | permission | 驱动创建设备节点权限，GPIO管理器具体配置为0664 |
    | moduleName | 驱动名称，GPIO管理器固定为HDF_PLATFORM_GPIO_MANAGER |
    | serviceName | 驱动对外发布服务的名称，GPIO管理器服务名设置为HDF_PLATFORM_GPIO_MANAGER |
    | deviceMatchAttr | 驱动私有数据匹配的关键字，GPIO管理器没有使用，可忽略 |

    - device_info.hcs 配置参考：

        在//vendor/hisilicon/hispark_taurus/hdf_config/device_info/device_info.hcs文件中添加deviceNode描述。

        ```c
        root {
            device_info {
                platform :: host {
                    hostName = "platform_host";
                    priority = 50;
                    device_gpio :: device {
                        device0 :: deviceNode {
                            policy = 2;
                            priority = 10;
                            permission = 0644;
                            moduleName = "HDF_PLATFORM_GPIO_MANAGER";
                            serviceName = "HDF_PLATFORM_GPIO_MANAGER";
                        }
                        device1 :: deviceNode {
                            policy = 0;                                    // 等于0，不需要发布服务
                            priority = 10;                                 // 驱动启动优先级
                            permission = 0644;                             // 驱动创建设备节点权限
                            moduleName = "hisi_pl061_driver";              // 【必要】用于指定驱动名称，需要与期望的驱动Entry中的moduleName一致
                            deviceMatchAttr = "hisilicon_hi35xx_pl061";    // 【必要】用于配置控制器私有数据，要与gpio_config.hcs中对应控制器保持一致，其他控制器信息也在文件中
                        }
                    }
                }
            }
        }
        ```

    - gpio_config.hcs配置参考：

        此处以Hi3516DV300为例，给出HCS配置参考。其中部分字段为Hi3516DV300特有功能，驱动适配者可根据需要进行删除或添加字段。

        ```c
        root {
            platform {
                gpio_config {
                    controller_0x120d0000 {
                        match_attr = "hisilicon_hi35xx_pl061";    // 【必要】必须和device_info.hcs中的deviceMatchAttr值一致
                        groupNum = 12;                            // 【必要】GPIO组索引，需要根据设备情况填写
                        bitNum = 8;                               // 【必要】每组GPIO管脚数
                        regBase = 0x120d0000;                     // 【必要】物理基地址
                        regStep = 0x1000;                         // 【必要】寄存器偏移步进
                        irqStart = 48;                            // 【必要】开启中断
                        irqShare = 0;                             // 【必要】共享中断
                    }
                    template gpio_info {                          // gpio_info模板
                        gpioCustomName = "";                      // gpio管脚默认名称
                    }
                    GPIO0 :: gpio_info {                          
                        gpioCustomName = "GPIO0_0";
                    }
                    ......
                }
            }
        }
        ```

        需要注意的是，新增gpio_config.hcs配置文件后，必须在产品对应的hdf.hcs文件中将其包含如下语句所示，否则配置文件无法生效。

        ```c
        #include "../../../../device/soc/hisilicon/hi3516dv300/sdk_liteos/hdf_config/gpio/gpio_config.hcs" // 配置文件相对路径
        ```

        本例基于Hi3516DV300开发板的小型系统LiteOS内核运行，对应的hdf.hcs文件路径为vendor/hisilicon/hispark_taurus/hdf_config/hdf.hcs以及//device/hisilicon/hispark_taurus/sdk_liteos/hdf_config/hdf.hcs。驱动适配者需根据实际情况选择对应路径下的文件进行修改。

3. 实例化GPIO控制器对象

    完成驱动入口注册之后，下一步就是以核心层GpioCntlr对象的初始化为核心，包括驱动适配者自定义结构体（传递参数和数据），实例化GpioCntlr成员GpioMethod（让用户可以通过接口来调用驱动底层函数），实现HdfDriverEntry成员函数（Bind，Init，Release）。

    - 驱动适配者自定义结构体参考。

        从驱动的角度看，自定义结构体是参数和数据的载体，而且gpio_config.hcs文件中的数值会被HDF读入并通过DeviceResourceIface来初始化结构体成员，其中一些重要数值也会传递给核心层GpioCntlr对象，例如索引、管脚数等。

        ```c
        //GPIO分组信息定义
        struct Pl061GpioGroup {
            struct GpioCntlr cntlr;             // 【必要】是核心层控制对象，其成员定义见下面。
            volatile unsigned char *regBase;    // 【必要】寄存器基地址。
            unsigned int index;
            unsigned int irq;
            OsalIRQHandle irqFunc;
            OsalSpinlock lock;
            uint32_t irqSave;
            bool irqShare;
            struct PlatformDumper *dumper;
            char *dumperName;
        };

        struct Pl061GpioData {
            volatile unsigned char *regBase;    // 【必要】寄存器基地址。
            uint32_t phyBase;                   // 【必要】物理基址。
            uint32_t regStep;                   // 【必要】寄存器偏移步进。
            uint32_t irqStart;                  // 【必要】中断开启。
            uint16_t groupNum;                  // 【必要】用于描述厂商的GPIO端口号的参数。
            uint16_t bitNum;                    // 【必要】用于描述厂商的GPIO端口号的参数。
            uint8_t irqShare;                   // 【必要】共享中断。
            struct Pl061GpioGroup *groups;      // 【可选】根据厂商需要设置。
            struct GpioInfo *gpioInfo;
            void *priv;
        };

        struct GpioInfo {
            struct GpioCntlr *cntlr;
            char name[GPIO_NAME_LEN];
            OsalSpinlock spin;
            uint32_t irqSave;
            struct GpioIrqRecord *irqRecord;
        };
        // GpioCntlr是核心层控制器结构体，其中的成员在Init函数中会被赋值。
        struct GpioCntlr {
            struct PlatformDevice device;
            struct GpioMethod *ops;
            uint16_t start;
            uint16_t count;
            struct GpioInfo *ginfos;
            bool isAutoAlloced;
            void *priv;
        };
        ```

    - GpioCntlr成员钩子函数结构体GpioMethod的实例化。

        ```c
        //GpioMethod结构体成员都是钩子函数，驱动适配者需要根据表1完成相应的函数功能。
        static struct GpioMethod g_method = {
            .request = NULL,
            .release = NULL,
            .write = Pl061GpioWrite,              // 写管脚
            .read = Pl061GpioRead,                // 读管脚
            .setDir = Pl061GpioSetDir,            // 设置管脚方向
            .getDir = Pl061GpioGetDir,            // 获取管脚方向
            .toIrq = NULL,                        
            .setIrq = Pl061GpioSetIrq,            // 设置管脚中断，如不具备此能力可忽略
            .unsetIrq = Pl061GpioUnsetIrq,        // 取消管脚中断设置，如不具备此能力可忽略
            .enableIrq = Pl061GpioEnableIrq,      // 使能管脚中断，如不具备此能力可忽略
            .disableIrq = Pl061GpioDisableIrq,    // 禁止管脚中断，如不具备此能力可忽略
        };
        ```

    - Init函数开发参考。

        入参：

        HdfDeviceObject：HDF框架给每一个驱动创建的设备对象，用来保存设备相关的私有数据和服务接口。

        返回值：

        HDF_STATUS相关状态（表3为部分展示，如需使用其他状态，可参考//drivers/hdf_core/interfaces/inner_api/utils/hdf_base.h中HDF_STATUS定义）。

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

        初始化自定义结构体对象，初始化GpioCntlr成员，调用核心层GpioCntlrAdd函数，接入VFS（可选）。

        ```c
        static struct Pl061GpioData g_pl061 = {
            .groups = NULL,
            .groupNum = PL061_GROUP_MAX,
            .bitNum = PL061_BIT_MAX,
        };

        static int32_t Pl061GpioInitGroups(struct Pl061GpioData *pl061)
        {
            int32_t ret;
            uint16_t i;
            struct Pl061GpioGroup *groups = NULL;

            if (pl061 == NULL) {
                return HDF_ERR_INVALID_PARAM;
            }

            groups = (struct Pl061GpioGroup *)OsalMemCalloc(sizeof(*groups) * pl061->groupNum);
            if (groups == NULL) {
                return HDF_ERR_MALLOC_FAIL;
            }
            pl061->groups = groups;

            for (i = 0; i < pl061->groupNum; i++) {
                // 相关信息初始化
                groups[i].index = i;
                groups[i].regBase = pl061->regBase + i * pl061->regStep;
                groups[i].irq = pl061->irqStart + i;
                groups[i].irqShare = pl061->irqShare;
                groups[i].cntlr.start = i * pl061->bitNum;
                groups[i].cntlr.count = pl061->bitNum;
                groups[i].cntlr.ops = &g_method;
                groups[i].cntlr.ginfos = &pl061->gpioInfo[i * pl061->bitNum];
        
                if ((ret = OsalSpinInit(&groups[i].lock)) != HDF_SUCCESS) {
                    goto ERR_EXIT;
                }

                ret =  GpioCntlrAdd(&groups[i].cntlr); // 向HDF core中添加相关信息
                if (ret != HDF_SUCCESS) {
                    HDF_LOGE("%s: err add controller(%hu:%hu):%d", __func__,
                        groups[i].cntlr.start, groups[i].cntlr.count, ret);
                    (void)OsalSpinDestroy(&groups[i].lock);
                    goto ERR_EXIT;
                }
                ret = GpioDumperCreate(&pl061->groups[i]);
                if (ret != HDF_SUCCESS) {
                    HDF_LOGE("%s: create dumper failed:%d", __func__, ret);
                    return ret;
                }
            }
            return HDF_SUCCESS;

        ERR_EXIT:
            while (i-- > 0) {
                GpioCntlrRemove(&groups[i].cntlr);
                (void)OsalSpinDestroy(&groups[i].lock);
            }
            pl061->groups = NULL;
            OsalMemFree(groups);
            return ret;
        }

        static int32_t Pl061GpioInit(struct HdfDeviceObject *device)
        {
            int32_t ret;
            struct Pl061GpioData *pl061 = &g_pl061;
        
            if (device == NULL || device->property == NULL) {
                HDF_LOGE("%s: device or property null!", __func__);
                return HDF_ERR_INVALID_OBJECT;
            }

            pl061->gpioInfo = OsalMemCalloc(sizeof(struct GpioInfo) * GPIO_MAX_INFO_NUM);
            if (pl061->gpioInfo == NULL) {
                HDF_LOGE("%s: failed to calloc gpioInfo!", __func__);
                return HDF_ERR_MALLOC_FAIL;
            }

            ret = Pl061GpioReadDrs(pl061, device->property);                                 // 利用从gpio_config.HCS文件读取的属性值来初始化自定义结构体对象成员
            if (ret != HDF_SUCCESS) {                                                        
                HDF_LOGE("%s: failed to read drs:%d", __func__, ret);                        
                return ret;                                                                  
            }                                                                                

            if (pl061->groupNum > PL061_GROUP_MAX || pl061->groupNum <= 0 ||                 
                pl061->bitNum > PL061_BIT_MAX || pl061->bitNum <= 0) {                       
                HDF_LOGE("%s: err groupNum:%hu, bitNum:%hu", __func__, pl061->groupNum, pl0  61->bitNum);
                return HDF_ERR_INVALID_PARAM;                                                
            }                                                                                

            pl061->regBase = OsalIoRemap(pl061->phyBase, pl061->groupNum * pl061->regStep);  // 地址映射
            if (pl061->regBase == NULL) {
                HDF_LOGE("%s: err remap phy:0x%x", __func__, pl061->phyBase);
                return HDF_ERR_IO;
            }

            ret = Pl061GpioInitGroups(pl061);                                                // group信息初始化，并添加到HDF核心层
            if (ret != HDF_SUCCESS) {
                HDF_LOGE("%s: err init groups:%d", __func__, ret);
                OsalIoUnmap((void *)pl061->regBase);
                pl061->regBase = NULL;
                return ret;
            }
            pl061->priv = (void *)device->property;
            device->priv = (void *)pl061;
            Pl061GpioDebug(pl061);

        #ifdef PL061_GPIO_USER_SUPPORT
            if (GpioAddVfs(pl061->bitNum) != HDF_SUCCESS) {
                HDF_LOGE("%s: add vfs fail!", __func__);
            }
        #endif
            HDF_LOGI("%s: dev service:%s init success!", __func__, HdfDeviceGetServiceName(device));
            return HDF_SUCCESS;
        }
        ```

    - Release函数开发参考

        入参：

        HdfDeviceObject：HDF框架给每一个驱动创建的设备对象，用来保存设备相关的私有数据和服务接口。

        返回值：

        无。

        函数说明：

        释放内存和删除控制器，该函数需要在驱动入口结构体中赋值给Release接口，当HDF框架调用Init函数初始化驱动失败时，可以调用Release释放驱动资源。

        > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**<br>
        > 所有强制转换获取相应对象的操作**前提**是在Init函数中具备对应赋值的操作。

        ```c
        static void Pl061GpioUninitGroups(struct Pl061GpioData *pl061)
        {
            uint16_t i;
            struct Pl061GpioGroup *group = NULL;
        
            for (i = 0; i < pl061->groupNum; i++) {
                group = &pl061->groups[i];
                GpioDumperDestroy(&pl061->groups[i]);
                GpioCntlrRemove(&group->cntlr);        // 从HDF核心层删除
            }
        
            OsalMemFree(pl061->groups);
            pl061->groups = NULL;
        }

        static void Pl061GpioRelease(struct HdfDeviceObject *device)
        {
            struct Pl061GpioData *pl061 = NULL;
        
            HDF_LOGI("%s: enter", __func__);
            if (device == NULL) {
                HDF_LOGE("%s: device is null!", __func__);
                return;
            }

        #ifdef PL061_GPIO_USER_SUPPORT
            GpioRemoveVfs();
        #endif
        
            pl061 = (struct Pl061GpioData *)device->priv;
            if (pl061 == NULL) {
                HDF_LOGE("%s: device priv is null", __func__);
                return;
            }

            Pl061GpioUninitGroups(pl061);
            OsalMemFree(pl061->gpioInfo);
            pl061->gpioInfo = NULL;
            OsalIoUnmap((void *)pl061->regBase);
            pl061->regBase = NULL;
        }
        ```

4. 驱动调试

    【可选】针对新增驱动程序，建议验证驱动基本功能，例如GPIO控制状态，中断响应情况等。
