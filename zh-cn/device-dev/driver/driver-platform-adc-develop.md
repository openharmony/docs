# ADC

## 概述

### 功能简介<a name="section2"></a>

ADC（Analog to Digital Converter），即模拟-数字转换器，可将模拟信号转换成对应的数字信号，便于存储与计算等操作。除电源线和地线之外，ADC只需要1根线与被测量的设备进行连接，其物理连线如图1所示：

**图 1** ADC物理连线示意图<a name="fig1"></a>  
![ADC物理连线示意图](figures/ADC物理连线示意图.png)

### 基本概念<a name="section3"></a>

- 分辨率

    分辨率指的是ADC模块能够转换的二进制位数，位数越多分辨率越高。

- 转换误差

    转换误差通常是以输出误差的最大值形式给出。它表示A/D转换器实际输出的数字量和理论上的输出数字量之间的差别。常用最低有效位的倍数表示。

- 转换时间

    转换时间是指A/D转换器从转换控制信号到来开始，到输出端得到稳定的数字信号所经过的时间。


### 运作机制

在HDF框架中，同类型设备对象较多时（可能同时存在十几个同类型配置器），若采用独立服务模式，则需要配置更多的设备节点，且相关服务会占据更多的内存资源。相反，采用统一服务模式可以使用一个设备服务作为管理器，统一处理所有同类型对象的外部访问（这会在配置文件中有所体现），实现便捷管理和节约资源的目的。ADC模块即采用统一服务模式（如图2所示）。

ADC模块各分层的作用为：

- 接口层：提供打开设备，写入数据，关闭设备的能力。

- 核心层：主要负责服务绑定、初始化以及释放管理器，并提供添加、删除以及获取控制器的能力。

- 适配层：由驱动适配者实现与硬件相关的具体功能，如控制器的初始化等。

在统一模式下，所有的控制器都被核心层统一管理，并由核心层统一发布一个服务供接口层，因此这种模式下驱动无需再为每个控制器发布服务。

**图 2** ADC统一服务模式结构图<a name="fig2"></a>  
![ADC统一服务模式结构图](figures/统一服务模式结构图.png)

## 使用指导

### 场景介绍

ADC设备通常用于将模拟电压转换为数字量，例如与NTC电阻搭配进行温度测量，或者将其他模拟传感器的输出量转换为数字量的场景。当驱动开发者需要将ADC设备适配到OpenHarmony时，需要进行ADC驱动适配，下文将介绍如何进行ADC驱动适配。

### 接口说明

为了保证上层在调用ADC接口时能够正确的操作硬件，核心层在//drivers/hdf_core/framework/support/platform/include/adc/adc_core.h中定义了以下钩子函数。驱动适配者需要在适配层实现这些函数的具体功能，并与这些钩子函数挂接，从而完成接口层与核心层的交互。

AdcMethod和AdcLockMethod定义：

```c
struct AdcMethod {
    int32_t (*read)(struct AdcDevice *device, uint32_t channel, uint32_t *val);
    int32_t (*start)(struct AdcDevice *device);
    int32_t (*stop)(struct AdcDevice *device);
};

struct AdcLockMethod {
    int32_t (*lock)(struct AdcDevice *device);
    void (*unlock)(struct AdcDevice *device);
};

```

在适配层中，AdcMethod必须被实现，AdcLockMethod可根据实际情况考虑是否实现。核心层提供了默认的AdcLockMethod，其中使用Spinlock作为保护临界区的锁：

```c
static int32_t AdcDeviceLockDefault(struct AdcDevice *device)
{
    if (device == NULL) {
        return HDF_ERR_INVALID_OBJECT;
    }
    return OsalSpinLock(&device->spin);
}

static void AdcDeviceUnlockDefault(struct AdcDevice *device)
{
    if (device == NULL) {
        return;
    }
    (void)OsalSpinUnlock(&device->spin);
}

static const struct AdcLockMethod g_adcLockOpsDefault = {
    .lock = AdcDeviceLockDefault,
    .unlock = AdcDeviceUnlockDefault,
};

```

若实际情况不允许使用Spinlock，驱动适配者可以考虑使用其他类型的锁来实现一个自定义的AdcLockMethod。一旦实现了自定义的AdcLockMethod，默认的AdcLockMethod将被覆盖。

**表 1** AdcMethod结构体成员的钩子函数功能说明

| 函数成员 | 入参 | 出参 | 返回值 | 功能 | 
| -------- | -------- | -------- | -------- | -------- |
| read | device：结构体指针，核心层ADC控制器<br/>channel：uint32_t类型，传入的通道号 | val：uint32_t类型指针，要传出的信号数据 | HDF_STATUS相关状态 | 读取ADC采样的信号数据 |
| stop | device：结构体指针，核心层ADC控制器 | 无 | HDF_STATUS相关状态 | 关闭ADC设备 |
| start | device：结构体指针，核心层ADC控制器 | 无 | HDF_STATUS相关状态 | 开启ADC设备 |

**表 2** AdcLockMethod结构体成员函数功能说明

| 函数成员 | 入参 | 出参 | 返回值 | 功能 | 
| -------- | -------- | -------- | -------- | -------- |
| lock | device：结构体指针，核心层ADC设备对象。 | 无 | HDF_STATUS相关状态 | 获取临界区锁 | 
| unlock | device：结构体指针，核心层ADC设备对象。 | 无 | HDF_STATUS相关状态 | 释放临界区锁 | 

### 开发步骤

ADC模块适配包含以下四个步骤：

1. 实例化驱动入口

    - 实例化HdfDriverEntry结构体成员。

    - 调用HDF_INIT将HdfDriverEntry实例化对象注册到HDF框架中。

2. 配置属性文件

    - 在device_info.hcs文件中添加deviceNode描述。

    - 【可选】添加adc_config.hcs器件属性文件。

3. 实例化核心层接口函数

    - 初始化AdcDevice成员。

    - 实例化AdcDevice成员AdcMethod。

        > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**<br>
        > 实例化AdcDevice成员AdcMethod，其定义和成员说明见[接口说明](#接口说明)。

4. 驱动调试

    【可选】针对新增驱动程序，建议验证驱动基本功能，例如挂载后的测试用例是否成功等。

### 开发实例

下方将基于Hi3516DV300开发板以//device/soc/hisilicon/common/platform/adc/adc_hi35xx.c驱动为示例，展示需要驱动适配者提供哪些内容来完整实现设备功能。

1. 实例化驱动入口

    驱动入口必须为HdfDriverEntry（在//drivers/hdf_core/interfaces/inner_api/host/shared/hdf_device_desc.h中定义）类型的全局变量，且moduleName要和device_info.hcs中保持一致。HDF框架会将所有加载的驱动的HdfDriverEntry对象首地址汇总，形成一个类似数组的段地址空间，方便上层调用。

    一般在加载驱动时HDF会先调用Bind函数，再调用Init函数加载该驱动。当Init调用异常时，HDF框架会调用Release释放驱动资源并退出。

    ADC驱动入口参考：

    ADC控制器会出现多个设备挂接的情况，因而在HDF框架中首先会为此类型的设备创建一个管理器对象。这样，需要打开某个设备时，管理器对象会根据指定参数查找到指定设备。

    ADC管理器的驱动由核心层实现，驱动适配者不需要关注这部分内容的实现，但在实现Init函数的时候需要调用核心层的AdcDeviceAdd函数，它会实现相应功能。

    ```c
    static struct HdfDriverEntry g_hi35xxAdcDriverEntry = {
        .moduleVersion = 1,
        .Init = Hi35xxAdcInit,
        .Release = Hi35xxAdcRelease,
        .moduleName = "hi35xx_adc_driver",        // 【必要且与device_info.hcs文件内的模块名匹配】
    };
    HDF_INIT(g_hi35xxAdcDriverEntry);             // 调用HDF_INIT将驱动入口注册到HDF框架中

    // 核心层adc_core.c管理器服务的驱动入口
    struct HdfDriverEntry g_adcManagerEntry = {
        .moduleVersion = 1,
        .Bind = AdcManagerBind,                   // ADC不需要实现Bind，本例是一个空实现，驱动适配者可根据自身需要添加相关操作
        .Init = AdcManagerInit,                   // 见Init参考
        .Release = AdcManagerRelease,             // 见Release参考
        .moduleName = "HDF_PLATFORM_ADC_MANAGER", // 这与device_info.hcs文件中device0对应
    };
    HDF_INIT(g_adcManagerEntry);                  // 调用HDF_INIT将驱动入口注册到HDF框架中
    ```

2. 配置属性文件

    完成驱动入口注册之后，下一步请在//vendor/hisilicon/hispark_taurus/hdf_config/device_info/device_info.hcs文件中添加deviceNode信息，并在adc_config.hcs中配置器件属性。

    deviceNode信息与驱动入口注册相关，器件属性值对于驱动适配者的驱动实现以及核心层AdcDevice相关成员的默认值或限制范围有密切关系。

    统一服务模式的特点是device_info.hcs文件中第一个设备节点必须为ADC管理器，其各项参数如表3所示：

    **表 3** device_info.hcs节点参数说明

    | 成员名 | 值 |
    | -------- | -------- |
    | policy | 驱动服务发布的策略，ADC管理器具体配置为2，表示驱动对内核态和用户态都发布服务 |
    | priority | 驱动启动优先级（0-200），值越大优先级越低。ADC管理器具体配置为50 |
    | permission | 驱动创建设备节点权限，ADC管理器具体配置为0664 |
    | moduleName | 驱动名称，ADC管理器固定为HDF_PLATFORM_ADC_MANAGER |
    | serviceName | 驱动对外发布服务的名称，ADC管理器服务名设置为HDF_PLATFORM_ADC_MANAGER |
    | deviceMatchAttr | 驱动私有数据匹配的关键字，ADC管理器没有使用，可忽略 |

    从第二个节点开始配置具体ADC控制器信息，第一个节点并不表示某一路ADC控制器，而是代表一个资源性质设备，用于描述一类ADC控制器的信息。本例只有一个ADC设备，如有多个设备，则需要在device_info.hcs文件增加deviceNode信息，以及在adc_config.hcs文件中增加对应的器件属性。

    - device_info.hcs配置参考

        ```c
        root {
            device_info {
                platform :: host {
                    device_adc :: device {
                        device0 :: deviceNode {
                            policy = 2;
                            priority = 50;
                            permission = 0644;
                            moduleName = "HDF_PLATFORM_ADC_MANAGER";
                            serviceName = "HDF_PLATFORM_ADC_MANAGER";
                        }
                        device1 :: deviceNode {
                            policy = 0;                               // 等于0，不需要发布服务。
                            priority = 55;                            // 驱动启动优先级。
                            permission = 0644;                        // 驱动创建设备节点权限。
                            moduleName = "hi35xx_adc_driver";         //【必要】用于指定驱动名称，需要与期望的驱动Entry中的moduleName一致。
                            serviceName = "HI35XX_ADC_DRIVER";        //【必要】驱动对外发布服务的名称，必须唯一。
                            deviceMatchAttr = "hisilicon_hi35xx_adc"; //【必要】用于配置控制器私有数据，要与adc_config.hcs中对应控制器保持一致，具体的控制器信息在adc_config.hcs中。
                        }
                    }
                }
            }
        }
        ```

    - adc_config.hcs配置参考

        此处以Hi3516DV300为例，给出HCS配置参考。其中部分字段为Hi3516DV300特有功能，驱动适配者可根据需要进行删除或添加字段。

        ```c
        root {
            platform {
                adc_config_hi35xx {
                    match_attr = "hisilicon_hi35xx_adc";
                    template adc_device {
                        regBasePhy = 0x120e0000; // 寄存器物理基地址
                        regSize = 0x34;          // 寄存器位宽
                        deviceNum = 0;           // 设备号
                        validChannel = 0x1;      // 有效通道
                        dataWidth = 10;          // AD转换后的数据位宽，即分辨率
                        scanMode = 1;            // 扫描模式
                        delta = 0;               // 转换结果误差范围
                        deglitch = 0;            // 滤毛刺开关
                        glitchSample = 5000;     // 滤毛刺时间窗口
                        rate = 20000;            // 转换速率
                    }
                    device_0 :: adc_device {
                        deviceNum = 0;
                        validChannel = 0x2;
                    }
                }
            }
        }
        ```

        需要注意的是，新增adc_config.hcs配置文件后，必须在hdf.hcs文件中将其包含，否则配置文件无法生效。

        例如：本例中adc_config.hcs所在路径为//device/soc/hisilicon/hi3516dv300/sdk_liteos/hdf_config/adc/adc_config.hcs，则必须在产品对应的hdf.hcs中添加如下语句：

        ```c
        #include "../../../../device/soc/hisilicon/hi3516dv300/sdk_liteos/hdf_config/adc/adc_config.hcs" // 配置文件相对路径
        ```

        本例基于Hi3516DV300开发板的小型系统LiteOS内核运行，对应的hdf.hcs文件路径为vendor/hisilicon/hispark_taurus/hdf_config/hdf.hcs以及//device/hisilicon/hispark_taurus/sdk_liteos/hdf_config/hdf.hcs。驱动适配者需根据实际情况选择对应路径下的文件进行修改。

3. 实例化核心层函数

    完成驱动入口注册之后，下一步就是以核心层AdcDevice对象的初始化为核心，包括初始化驱动适配者自定义结构体（传递参数和数据），实例化AdcDevice成员AdcMethod（让用户可以通过接口来调用驱动底层函数），实现HdfDriverEntry成员函数（Bind，Init，Release）。

    - 自定义结构体参考。

        从驱动的角度看，自定义结构体是参数和数据的载体，而且adc_config.hcs文件中的数值会被HDF读入并通过DeviceResourceIface来初始化结构体成员，其中一些重要数值（例如设备号、总线号等）也会传递给核心层AdcDevice对象。

        ```c
        struct Hi35xxAdcDevice {
            struct AdcDevice device;         // 【必要】是核心层控制对象，必须作为自定义结构体的首个成员，其具体描述见下方。
            volatile unsigned char *regBase; // 【必要】寄存器基地址
            volatile unsigned char *pinCtrlBase;
            uint32_t regBasePhy;             // 【必要】寄存器物理基地址
            uint32_t regSize;                // 【必要】寄存器位宽
            uint32_t deviceNum;              // 【必要】设备号
            uint32_t dataWidth;              // 【必要】信号接收的数据位宽
            uint32_t validChannel;           // 【必要】有效通道
            uint32_t scanMode;               // 【必要】扫描模式
            uint32_t delta;
            uint32_t deglitch;
            uint32_t glitchSample;
            uint32_t rate;                   // 【必要】采样率
        };

        // AdcDevice是核心层控制器结构体，其中的成员在Init函数中会被赋值。
        struct AdcDevice {
            const struct AdcMethod *ops;
            OsalSpinlock spin;
            uint32_t devNum;
            uint32_t chanNum;
            const struct AdcLockMethod *lockOps;
            void *priv;
        };
        ```

    - AdcDevice成员钩子函数结构体AdcMethod的实例化。

        AdcLockMethod钩子函数结构体本例未实现，若要实例化，可参考I2C驱动开发。

        ```c
        static const struct AdcMethod g_method = {
            .read = Hi35xxAdcRead,
            .stop = Hi35xxAdcStop,
            .start = Hi35xxAdcStart,
        };
        ```

    - Init函数开发参考

        入参：

        HdfDeviceObject是整个驱动对外提供的接口参数，具备HCS配置文件的信息。

        返回值：

        HDF_STATUS相关状态（表4为部分展示，如需使用其他状态，可参考//drivers/hdf_core/interfaces/inner_api/utils/hdf_base.h中HDF_STATUS定义）。

        **表 4** HDF_STATUS相关状态说明

        | 状态(值) | 问题描述 |
        | -------- | -------- |
        | HDF_ERR_INVALID_OBJECT | 控制器对象非法 |
        | HDF_ERR_INVALID_PARAM | 参数非法 |
        | HDF_ERR_MALLOC_FAIL | 内存分配失败 |
        | HDF_ERR_IO | I/O错误 |
        | HDF_SUCCESS | 传输成功 |
        | HDF_FAILURE | 传输失败 |

        函数说明：

        初始化自定义结构体对象，初始化AdcDevice成员，并调用核心层AdcDeviceAdd函数。
      
        ```c
        static int32_t Hi35xxAdcInit(struct HdfDeviceObject *device)
        {
            int32_t ret;
            struct DeviceResourceNode *childNode = NULL;
            ......
            // 遍历、解析adc_config.hcs中的所有配置节点，并分别调用Hi35xxAdcParseInit函数来初始化device。
            DEV_RES_NODE_FOR_EACH_CHILD_NODE(device->property, childNode) {
                ret = Hi35xxAdcParseInit(device, childNode); // 函数定义见下方
                ......
            }
            HDF_LOGI("%s: adc init success.", __func__);
            return ret;
        }

        static int32_t Hi35xxAdcParseInit(struct HdfDeviceObject *device, struct DeviceResourceNode *node)
        {
            int32_t ret;
            struct Hi35xxAdcDevice *hi35xx = NULL;     //【必要】自定义结构体对象

            (void)device;
            hi35xx = (struct Hi35xxAdcDevice *)OsalMemCalloc(sizeof(*hi35xx));  //【必要】内存分配
            ......
            ret = Hi35xxAdcReadDrs(hi35xx, node);      //【必要】将adc_config文件的默认值填充到结构体中，函数定义见下方
            ......
            hi35xx->regBase = OsalIoRemap(hi35xx->regBasePhy, hi35xx->regSize); //【必要】地址映射
            ......
            hi35xx->pinCtrlBase = OsalIoRemap(HI35XX_ADC_IO_CONFIG_BASE, HI35XX_ADC_IO_CONFIG_SIZE);
            ......
            Hi35xxAdcDeviceInit(hi35xx);               // 【必要】ADC设备的初始化
            hi35xx->device.priv = (void *)node;        // 【必要】存储设备属性
            hi35xx->device.devNum = hi35xx->deviceNum; // 【必要】初始化AdcDevice成员
            hi35xx->device.ops = &g_method;            // 【必要】AdcMethod的实例化对象的挂载
            ret = AdcDeviceAdd(&hi35xx->device);       // 【必要且重要】调用此函数填充核心层结构体，返回成功信号后驱动才完全接入平台核心层。
            ......
            return HDF_SUCCESS;

        __ERR__:
            if (hi35xx != NULL) {                      // 若不成功，需要执行去初始化相关函数。
                if (hi35xx->regBase != NULL) {
                    OsalIoUnmap((void *)hi35xx->regBase);
                    hi35xx->regBase = NULL;
                }
                AdcDeviceRemove(&hi35xx->device);
                OsalMemFree(hi35xx);
            }
            return ret;
        }

        static int32_t Hi35xxAdcReadDrs(struct Hi35xxAdcDevice *hi35xx, const struct DeviceResourceNode *node)
        {
            int32_t ret;
            struct DeviceResourceIface *drsOps = NULL;

            // 获取drsOps方法
            drsOps = DeviceResourceGetIfaceInstance(HDF_CONFIG_SOURCE);
            if (drsOps == NULL || drsOps->GetUint32 == NULL) {
                HDF_LOGE("%s: invalid drs ops", __func__);
                return HDF_ERR_NOT_SUPPORT;
            }
            // 将配置参数依次读出，并填充至结构体中
            ret = drsOps->GetUint32(node, "regBasePhy", &hi35xx->regBasePhy, 0);
            if (ret != HDF_SUCCESS) {
                HDF_LOGE("%s: read regBasePhy failed", __func__);
                return ret;
            }
            ret = drsOps->GetUint32(node, "regSize", &hi35xx->regSize, 0);
            if (ret != HDF_SUCCESS) {
                HDF_LOGE("%s: read regSize failed", __func__);
                return ret;
            }
            ......
            return HDF_SUCCESS;
        }
        ```

    - Release函数开发参考

        入参：

        HdfDeviceObject是整个驱动对外提供的接口参数，具备HCS配置文件的信息。

        返回值：

        无。

        函数说明：

        释放内存和删除控制器，该函数需要在驱动入口结构体中赋值给Release接口，当HDF框架调用Init函数初始化驱动失败时，可以调用Release释放驱动资源。

        ```c
        static void Hi35xxAdcRelease(struct HdfDeviceObject *device)
        {
            const struct DeviceResourceNode *childNode = NULL;
            ......
            // 遍历、解析adc_config.hcs中的所有配置节点，并分别进行Release操作。
            DEV_RES_NODE_FOR_EACH_CHILD_NODE(device->property, childNode) {
                Hi35xxAdcRemoveByNode(childNode);// 函数定义见下
            }
        }
      
        static void Hi35xxAdcRemoveByNode(const struct DeviceResourceNode *node)
        {
            int32_t ret;
            int32_t deviceNum;
            struct AdcDevice *device = NULL;
            struct Hi35xxAdcDevice *hi35xx = NULL;
            struct DeviceResourceIface *drsOps = NULL;

            drsOps = DeviceResourceGetIfaceInstance(HDF_CONFIG_SOURCE);
            ......
            ret = drsOps->GetUint32(node, "deviceNum", (uint32_t *)&deviceNum, 0);
            ......
            // 可以调用AdcDeviceGet函数通过设备的deviceNum获取AdcDevice对象，以及调用AdcDeviceRemove函数来释放AdcDevice对象的内容。
            device = AdcDeviceGet(deviceNum);
            if (device != NULL && device->priv == node) {
                AdcDevicePut(device);   
                AdcDeviceRemove(device);                   //【必要】主要是从管理器驱动那边移除AdcDevice对象。
                hi35xx = (struct Hi35xxAdcDevice *)device; //【必要】通过强制转换获取自定义的对象并进行Release操作。这一步的前提是device必须作为自定义结构体的首个成员。
                OsalIoUnmap((void *)hi35xx->regBase);
                OsalMemFree(hi35xx);
            }
            return;
        }
        ```

4. 驱动调试

    【可选】针对新增驱动程序，建议验证驱动基本功能，例如挂载后的测试用例是否成功等。
