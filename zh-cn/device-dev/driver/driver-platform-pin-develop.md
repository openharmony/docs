# PIN

## 概述

### 功能简介

PIN即管脚控制器，用于统一管理各SoC的管脚资源，对外提供管脚复用功能。

### 基本概念

PIN是一个软件层面的概念，目的是为了统一对各SoC的PIN管脚进行管理，对外提供管脚复用功能，配置PIN管脚的电气特性。

- SoC（System on Chip）

    系统级芯片，又称作片上系统，通常是面向特定用途将微处理器、模拟IP核、数字IP核和存储器集成在单一芯片的标准产品。

- 管脚复用

    由于芯片自身的引脚数量有限，无法满足日益增多的外接需求。此时可以通过软件层面的寄存器设置，让引脚工作在不同的状态，从而实现相同引脚完成不同功能的目的。

### 运作机制

在HDF框架中，同类型设备对象较多时（可能同时存在十几个同类型配置器），若采用独立服务模式，则需要配置更多的设备节点，且相关服务会占据更多的内存资源。相反，采用统一服务模式可以使用一个设备服务作为管理器，统一处理所有同类型对象的外部访问（这会在配置文件中有所体现），实现便捷管理和节约资源的目的。PIN模块接口适配模式采用统一服务模式（如图1所示）。

在统一模式下，所有的控制器都被核心层统一管理，并由核心层统一发布一个服务供接口层，因此这种模式下驱动无需再为每个控制器发布服务。

PIN模块各分层作用：

- 接口层提供获取PIN管脚、设置PIN管脚推拉方式、获取PIN管脚推拉方式、设置PIN管脚推拉强度、获取PIN管脚推拉强度、设置PIN管脚功能、获取PIN管脚功能、释放PIN管脚的接口。

- 核心层主要提供PIN管脚资源匹配，PIN管脚控制器的添加、移除以及管理的能力，通过钩子函数与适配层交互。

- 适配层主要是将钩子函数的功能实例化，实现具体的功能。

**图 1**  统一服务模式结构图

![统一服务模式结构图](figures/统一服务模式结构图.png)

### 约束与限制

PIN模块目前只支持小型系统LiteOS-A内核。

## 开发指导

### 场景介绍

PIN模块主要用于管脚资源管理。在各SoC对接HDF框架时，需要来适配PIN驱动。下文将介绍如何进行PIN驱动适配。

### 接口说明

为了保证上层在调用PIN接口时能够正确的操作PIN管脚，核心层在//drivers/hdf_core/framework/support/platform/include/pin/pin_core.h中定义了以下钩子函数，驱动适配者需要在适配层实现这些函数的具体功能，并与钩子函数挂接，从而完成适配层与核心层的交互。

PinCntlrMethod定义：

```c
struct PinCntlrMethod {
    int32_t (*SetPinPull)(struct PinCntlr *cntlr, uint32_t index, enum PinPullType pullType);
    int32_t (*GetPinPull)(struct PinCntlr *cntlr, uint32_t index, enum PinPullType *pullType);
    int32_t (*SetPinStrength)(struct PinCntlr *cntlr, uint32_t index, uint32_t strength);
    int32_t (*GetPinStrength)(struct PinCntlr *cntlr, uint32_t index, uint32_t *strength);
    int32_t (*SetPinFunc)(struct PinCntlr *cntlr, uint32_t index, const char *funcName);
    int32_t (*GetPinFunc)(struct PinCntlr *cntlr, uint32_t index, const char **funcName);
};
```

**表 1**  PinCntlrMethod成员的钩子函数功能说明

| 成员函数 | 入参 | 出参 | 返回值 | 功能 |
| ------------ | ------------------------------------------- | ------ | ---- | ---- |
| SetPinPull | cntlr：结构体指针，核心层PIN控制器<br>index：uint32_t类型变量，管脚索引号<br/>pullType：枚举常量，PIN管脚推拉方式 | 无 |HDF_STATUS相关状态|PIN设置管脚推拉方式 |
| GetPinPull | cntlr：结构体指针，核心层PIN控制器<br/>index：uint32_t类型变量，管脚索引号 | pullType：枚举常量指针，传出获取的PIN管脚推拉方式 | HDF_STATUS相关状态 | PIN获取管脚推拉方式 |
| SetPinStrength | cntlr：结构体指针，核心层PIN控制器<br/>index：uint32_t类型变量，管脚索引号<br/>strength：uint32_t变量，PIN推拉强度 | 无 | HDF_STATUS相关状态 | PIN设置推拉强度 |
| GetPinStrength | cntlr：结构体指针，核心层PIN控制器<br/>index：uint32_t类型变量，管脚索引号 | strength：uint32_t变量指针，传出获取的PIN推拉强度 | HDF_STATUS相关状态 | PIN获取推拉强度 |
| SetPinFunc | cntlr：结构体指针，核心层PIN控制器<br/>index：uint32_t类型变量，管脚索引号<br/>funcName：char指针常量，传入PIN管脚功能 | 无 | HDF_STATUS相关状态 | PIN设置管脚功能 |
| GetPinFunc | cntlr：结构体指针，核心层PIN控制器<br/>index：uint32_t类型变量，管脚索引号 | funcName：char双重指针常量，传出获取的PIN管脚功能 | HDF_STATUS相关状态 | PIN获取管脚功能 |

### 开发步骤

PIN模块适配HDF框架包含以下四个步骤：

- 实例化驱动入口

- 配置属性文件

- 实例化PIN控制器对象

- 驱动调试

### 开发实例

下方将基于Hi3516DV300开发板以//device/soc/hisilicon/common/platform/pin/pin_hi35xx.c驱动为示例，展示需要驱动适配者提供哪些内容来完整实现设备功能。

1. 实例化驱动入口

    驱动入口必须为HdfDriverEntry（在hdf_device_desc.h中定义）类型的全局变量，且moduleName要和device_info.hcs中保持一致。HDF框架会将所有加载的驱动的HdfDriverEntry对象首地址汇总，形成一个类似数组的段地址空间，方便上层调用。

    一般在加载驱动时HDF会先调用Bind函数，再调用Init函数加载该驱动。当Init调用异常时，HDF框架会调用Release释放驱动资源并退出。

    PIN驱动入口开发参考：

    ```c
    static struct HdfDriverEntry g_hi35xxPinDriverEntry = {
        .moduleVersion = 1,
        .Bind = Hi35xxPinBind,                // PIN不需要实现Bind，本例是一个空实现，驱动适配者可根据自身需要添加相关操作
        .Init = Hi35xxPinInit,                // 挂接PIN模块Init实例化
        .Release = Hi35xxPinRelease,          // 挂接PIN模块Release实例化
        .moduleName = "hi35xx_pin_driver",    // 【必要且与HCS文件中里面的moduleName匹配】
    };
    HDF_INIT(g_hi35xxPinDriverEntry);         // 调用HDF_INIT将驱动入口注册到HDF框架中
   ```

2. 配置属性文件

    完成驱动入口注册之后，需要在device_info.hcs文件中添加deviceNode信息，deviceNode信息与驱动入口注册相关。本例以两个PIN控制器为例，如有多个器件信息，则需要在device_info.hcs文件增加对应的deviceNode信息，以及在gpio_config.hcs文件中增加对应的器件属性。器件属性值对于驱动适配者的驱动实现以及核心层PinCntlr相关成员的默认值或限制范围有密切关系，比如控制器号，控制器管脚数量、管脚等,需要在pin_config.hcs中配置器件属性。

    统一服务模式的特点是device_info.hcs文件中第一个设备节点必须为PIN管理器，其各项参数如表2所示：

    **表 2** device_info.hcs节点参数说明

    | 成员名 | 值 |
    | -------- | -------- |
    | policy | 驱动服务发布的策略，PIN管理器具体配置为2，表示驱动对内核态和用户态都发布服务 |
    | priority | 驱动启动优先级（0-200），值越大优先级越低。PIN管理器具体配置为8 |
    | permission | 驱动创建设备节点权限，PIN管理器具体配置为0664 |
    | moduleName | 驱动名称，PIN管理器固定为HDF_PLATFORM_PIN_MANAGER |
    | serviceName | 驱动对外发布服务的名称，PIN管理器服务名设置为HDF_PLATFORM_PIN_MANAGER |
    | deviceMatchAttr | 驱动私有数据匹配的关键字，PIN管理器没有使用，可忽略 |

    - device_info.hcs 配置参考：

        在//vendor/hisilicon/hispark_taurus/hdf_config/device_info/device_info.hcs文件中添加deviceNode描述。

        ```c
        root {
            device_info {
                platform :: host {
                    hostName = "platform_host";
                    priority = 50;
                    device_pin :: device {
                        device0 :: deviceNode {                              // 用于统一管理PIN并发布服务
                            policy = 2;                                      // 2：用户态可见；1：内核态可见；0：不需要发布服务。
                            priority = 8;                                    // 启动优先级
                            permission = 0644;                               // 创建设备节点权限
                            moduleName = "HDF_PLATFORM_PIN_MANAGER";
                            serviceName = "HDF_PLATFORM_PIN_MANAGER";
                        }
                        device1 :: deviceNode {                              // 为每一个PIN控制器配置一个HDF设备节点，存在多个时必须添加，否则不用。
                            policy = 0;
                            priority = 10;                                   // 驱动启动优先级
                            permission = 0644;                               // 驱动创建设备节点权限
                            moduleName = "hi35xx_pin_driver";                // 【必要】用于指定驱动名称，需要与期望的驱动Entry中的moduleName一致。
                            deviceMatchAttr = "hisilicon_hi35xx_pin_0";      // 【必要】用于配置控制器私有数据，要与pin_config.hcs中对应控制器保持一致，具体的控制器信息在pin_config.hcs中。
                        }
                        device2 :: deviceNode {
                            policy = 0;
                            priority = 10;
                            permission = 0644;
                            moduleName = "hi35xx_pin_driver";
                            deviceMatchAttr = "hisilicon_hi35xx_pin_1";
                        }
                        ......                                               // 如果存在多个PIN控制器时【必须】添加节点，否则不用                    
                    }
                }
            }
        }
        ```

    -  pin_config.hcs配置参考：

        在//device/soc/hisilicon/hi3516dv300/sdk_liteos/hdf_config/pin/pin_config.hcs文件配置器件属性，其中配置参数如下：

        ```c
        root {
            platform {
                pin_config_hi35xx {
                    template pin_controller {                   // 【必要】配置模板配，如果下面节点使用时继承该模板，则节点中未声明的字段会使用该模板中的默认值。
                        number = 0;                             // 【必要】PIN控制器号
                        regStartBasePhy = 0;                    // 【必要】寄存器物理基地址起始地址
                        regSize = 0;                            // 【必要】寄存器位宽
                        pinCount = 0;                           // 【必要】管脚数量
                        match_attr = "";
                        template pin_desc {
                            pinName = "";                       // 【必要】管脚名称
                                init = 0;                       // 【必要】寄存器默认值
                                F0 = "";                        // 【必要】功能0
                                F1 = "";                        // 功能1
                                F2 = "";                        // 功能2
                                F3 = "";                        // 功能3
                                F4 = "";                        // 功能4
                                F5 = "";                        // 功能5
                            }
                    }
                    controller_0 :: pin_controller {
                        number = 0;
                        regStartBasePhy = 0x10FF0000;
                        regSize = 0x48;
                        pinCount = 18;
                        match_attr = "hisilicon_hi35xx_pin_0";
                        T1 :: pin_desc {
                            pinName = "T1";
                            init = 0x0600;
                            F0 = "EMMC_CLK";
                            F1 = "SFC_CLK";
                            F2 = "SFC_BOOT_MODE";
                        }
                        ......                                  // 对应管脚控制器下的每个管脚，按实际添加。
                    }
                    ......                                      // 每个管脚控制器对应一个控制器节点，如存在多个PIN控制器，请依次添加对应的控制器节点。
                }
            }
        }
        ```

        需要注意的是，新增pin_config.hcs配置文件后，必须在产品对应的hdf.hcs文件中将其包含如下语句所示，否则配置文件无法生效。

        ```c
        #include "../../../../device/soc/hisilicon/hi3516dv300/sdk_liteos/hdf_config/pin/pin_config.hcs" // 配置文件相对路径
        ```

3. 实例化PIN控制器对象

    完成配置属性文件之后，下一步就是以核心层PinCntlr对象的初始化为核心，包括驱动适配者自定义结构体（传递参数和数据），实例化PinCntlr成员PinCntlrMethod（让用户可以通过接口来调用驱动底层函数），实现HdfDriverEntry成员函数（Bind、Init、Release）。

    - 驱动适配者自定义结构体参考。

        从驱动的角度看，自定义结构体是参数和数据的载体，而且pin_config.hcs文件中的数值会被HDF读入并通过DeviceResourceIface来初始化结构体成员，一些重要数值也会传递给核心层对象。

        在Hi35xxPinCntlrInit函数中对PinCntlr成员进行初始化操作。

        ```c
        // 驱动适配者自定义管脚描述结构体
        struct Hi35xxPinDesc {
            const char *pinName;                       // 管脚名
            uint32_t init;                             // 初始化值
            uint32_t index;                            // 管脚索引
            int32_t pullType;                          // 管脚推拉方式
            int32_t strength;                          // 管脚推拉强度
            const char *func[HI35XX_PIN_FUNC_MAX];     // 管脚功能名字符串数组
        };

        // 驱动适配者自定义结构体
        struct Hi35xxPinCntlr {
            struct PinCntlr cntlr;                     // 是核心层控制对象，具体描述见下面
            struct Hi35xxPinDesc *desc;                // 驱动适配者自定义管脚描述结构体指针
            volatile unsigned char *regBase;           // 寄存器映射地址
            uint16_t number;                           // 管脚控制器编号
            uint32_t regStartBasePhy;                  // 寄存器物理基地址起始地址
            uint32_t regSize;                          // 寄存器位宽
            uint32_t pinCount;                         // 管脚数量
        };

        // PinCntlr是核心层控制器结构体，其中的成员在Init函数中会被赋值。
        struct PinCntlr {
            struct IDeviceIoService service;           // 驱动服务
            struct HdfDeviceObject *device;            // 驱动设备对象
            struct PinCntlrMethod *method;             // 钩子函数
            struct DListHead node;                     // 链表节点
            OsalSpinlock spin;                         // 自旋锁
            uint16_t number;                           // 管脚控制器编号
            uint16_t pinCount;                         // 管脚数量
            struct PinDesc *pins;                      // 管脚资源
            void *priv;                                // 私有数据
        };

        // PIN管脚控制器初始化
        static int32_t Hi35xxPinCntlrInit(struct HdfDeviceObject *device, struct Hi35xxPinCntlr *hi35xx)
        {
            struct DeviceResourceIface *drsOps = NULL;
            int32_t ret;
            // 从hcs文件读取管脚控制器相关属性
            drsOps = DeviceResourceGetIfaceInstance(HDF_CONFIG_SOURCE);
            if (drsOps == NULL || drsOps->GetUint32 == NULL || drsOps->GetUint16 == NULL) {
                HDF_LOGE("%s: invalid drs ops fail!", __func__);
                return HDF_FAILURE;
            }
            ret = drsOps->GetUint16(device->property, "number", &hi35xx->number, 0);
            if (ret != HDF_SUCCESS) {
                HDF_LOGE("%s: read number failed", __func__);
                return ret;
            }
	    
            if (hi35xx->number > HI35XX_PIN_MAX_NUMBER) {
                HDF_LOGE("%s: invalid number:%u", __func__, hi35xx->number);
                return HDF_ERR_INVALID_PARAM;
            }
            ret = drsOps->GetUint32(device->property, "regStartBasePhy", &hi35xx->regStartBasePhy, 0);
            if (ret != HDF_SUCCESS) {
                HDF_LOGE("%s: read regStartBasePhy failed", __func__);
                return ret;
            }
            ret = drsOps->GetUint32(device->property, "regSize", &hi35xx->regSize, 0);
            if (ret != HDF_SUCCESS) {
                HDF_LOGE("%s: read regSize failed", __func__);
                return ret;
            }
            ret = drsOps->GetUint32(device->property, "pinCount", &hi35xx->pinCount, 0);
            if (ret != HDF_SUCCESS) {
                HDF_LOGE("%s: read pinCount failed", __func__);
                return ret;
            }
            if (hi35xx->pinCount > PIN_MAX_CNT_PER_CNTLR) {
                HDF_LOGE("%s: invalid number:%u", __func__, hi35xx->number);
                return HDF_ERR_INVALID_PARAM;
            }
            // 将读取的值赋值给管脚控制器的成员，完成管脚控制器初始化。
            hi35xx->cntlr.pinCount = hi35xx->pinCount;
            hi35xx->cntlr.number = hi35xx->number;
            hi35xx->regBase = OsalIoRemap(hi35xx->regStartBasePhy, hi35xx->regSize);  // 管脚控制器映射
            if (hi35xx->regBase == NULL) {
                HDF_LOGE("%s: remap Pin base failed", __func__);
                return HDF_ERR_IO;
            }
            hi35xx->desc = (struct Hi35xxPinDesc *)OsalMemCalloc(sizeof(struct Hi35xxPinDesc) * hi35xx->pinCount);
            if (hi35xx->desc == NULL) {
                HDF_LOGE("%s: memcalloc hi35xx desc failed", __func__);
                return HDF_ERR_MALLOC_FAIL;
            }
            hi35xx->cntlr.pins = (struct PinDesc *)OsalMemCalloc(sizeof(struct PinDesc) * hi35xx->pinCount);
                if (hi35xx->desc == NULL) {
                HDF_LOGE("%s: memcalloc hi35xx cntlr pins failed", __func__);
                return HDF_ERR_MALLOC_FAIL;
            }
            return HDF_SUCCESS;
        }
        ```

    - PinCntlr成员钩子函数结构体PinCntlrMethod的实例化。

        ```c
        static struct PinCntlrMethod g_method = {
            .SetPinPull = Hi35xxPinSetPull,              // 设置推拉方式
            .GetPinPull = Hi35xxPinGetPull,              // 获取推拉方式
            .SetPinStrength = Hi35xxPinSetStrength,      // 设置推拉强度
            .GetPinStrength = Hi35xxPinGetStrength,      // 获取推拉强度
            .SetPinFunc = Hi35xxPinSetFunc,              // 设置管脚功能
            .GetPinFunc = Hi35xxPinGetFunc,              // 获取管脚功能
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

        初始化自定义结构体对象和PinCntlr成员，并通过调用核心层PinCntlrAdd函数挂载PIN控制器。

        ```c
        static int32_t Hi35xxPinReadFunc(struct Hi35xxPinDesc *desc, const struct DeviceResourceNode *node, struct DeviceResourceIface *drsOps)
        {
            int32_t ret;
            uint32_t funcNum = 0;
            // 从hcs中读取管脚控制器子节点管脚功能名
            ret = drsOps->GetString(node, "F0", &desc->func[funcNum], "NULL");
            if (ret != HDF_SUCCESS) {
                HDF_LOGE("%s: read F0 failed", __func__);
                return ret;
            }

            funcNum++;
            ret = drsOps->GetString(node, "F1", &desc->func[funcNum], "NULL");
            if (ret != HDF_SUCCESS) {
                HDF_LOGE("%s: read F1 failed", __func__);
                return ret;
            }

            funcNum++;
            ......
            return HDF_SUCCESS;
        }

        static int32_t Hi35xxPinParsePinNode(const struct DeviceResourceNode *node, struct Hi35xxPinCntlr *hi35xx, int32_t index)
        {
            int32_t ret;
            struct DeviceResourceIface *drsOps = NULL;
            // 从hcs中读取管脚控制器子节点管脚相关属性
            drsOps = DeviceResourceGetIfaceInstance(HDF_CONFIG_SOURCE);
            if (drsOps == NULL || drsOps->GetUint32 == NULL || drsOps->GetString == NULL) {
                HDF_LOGE("%s: invalid drs ops fail!", __func__);
                return HDF_FAILURE;
            }
            ret = drsOps->GetString(node, "pinName", &hi35xx->desc[index].pinName, "NULL");
            if (ret != HDF_SUCCESS) {
                HDF_LOGE("%s: read pinName failed", __func__);
                return ret;
            }
            ...
            ret = Hi35xxPinReadFunc(&hi35xx->desc[index], node, drsOps);
            if (ret != HDF_SUCCESS) {
                HDF_LOGE("%s:Pin read Func failed", __func__);
                return ret;
            }
            hi35xx->cntlr.pins[index].pinName = hi35xx->desc[index].pinName;
            hi35xx->cntlr.pins[index].priv = (void *)node;
            ......
            return HDF_SUCCESS;
        }

        static int32_t Hi35xxPinInit(struct HdfDeviceObject *device)
        {
            ......
            struct Hi35xxPinCntlr *hi35xx = NULL;
            ......
            ret = Hi35xxPinCntlrInit(device, hi35xx);                         // 管脚控制器初始化
            ......
            DEV_RES_NODE_FOR_EACH_CHILD_NODE(device->property, childNode) {   // 遍历管脚控制器的每个子节点
                ret = Hi35xxPinParsePinNode(childNode, hi35xx, index);        // 解析子节点
                ......
            }

            hi35xx->cntlr.method = &g_method;                                 // PinCntlrMethod实例化实例化对象的挂载
            ret = PinCntlrAdd(&hi35xx->cntlr);                                // 添加控制器
            if (ret != HDF_SUCCESS) {
                HDF_LOGE("%s: add Pin cntlr: failed", __func__);
                ret = HDF_FAILURE;
            }
            return HDF_SUCCESS;
        }
        ```

    - Release函数开发参考。

        入参：

        HdfDeviceObject：HDF框架给每一个驱动创建的设备对象，用来保存设备相关的私有数据和服务接口。

        返回值：

        无。

        函数说明：

        释放内存和删除控制器，该函数需要在驱动入口结构体中赋值给Release接口。当HDF框架调用Init函数初始化驱动失败时，可以调用Release释放驱动资源。

        ```c
        static void Hi35xxPinRelease(struct HdfDeviceObject *device)
        {
            int32_t ret;
            uint16_t number;
            struct PinCntlr *cntlr = NULL;
            struct Hi35xxPinCntlr *hi35xx = NULL;
            struct DeviceResourceIface *drsOps = NULL;

            if (device == NULL || device->property == NULL) {
                HDF_LOGE("%s: device or property is null", __func__);
                return;
            }
            // 从hcs文件中读取管脚控制器编号
            drsOps = DeviceResourceGetIfaceInstance(HDF_CONFIG_SOURCE);
            if (drsOps == NULL || drsOps->GetUint32 == NULL || drsOps->GetString == NULL) {   
                HDF_LOGE("%s: invalid drs ops", __func__);
                return;
            }
            ret = drsOps->GetUint16(device->property, "number", &number, 0);
            if (ret != HDF_SUCCESS) {
                HDF_LOGE("%s: read cntlr number failed", __func__);
                return;
            }

            cntlr = PinCntlrGetByNumber(number);            // 通过管脚控制器编号获取管脚控制器
            PinCntlrRemove(cntlr);
            hi35xx = (struct Hi35xxPinCntlr *)cntlr;
            if (hi35xx != NULL) {
                if (hi35xx->regBase != NULL) {
                    OsalIoUnmap((void *)hi35xx->regBase);
                }
                OsalMemFree(hi35xx);
            }
        }
        ```

4. 驱动调试

   【可选】针对新增驱动程序，建议验证驱动基本功能，例如挂载后的信息反馈，PIN管脚设置推拉方式、推拉强度等。
