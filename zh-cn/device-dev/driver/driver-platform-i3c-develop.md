# I3C 

## 概述 <a name="1"></a>

### 功能简介<a name="2"></a>

I3C（Improved Inter Integrated Circuit）总线是由MIPI Alliance开发的一种简单、低成本的双向二线制同步串行总线。

I3C是两线双向串行总线，针对多个传感器从设备进行了优化，并且一次只能由一个I3C主设备控制。相比于I2C，I3C总线拥有更高的速度、更低的功耗，支持带内中断、从设备热接入以及切换当前主设备，同时向后兼容I2C从设备。I3C增加了带内中断（In-Bind Interrupt）功能，支持I3C设备进行热接入操作，弥补了I2C总线需要额外增加中断线来完成中断的不足。I3C总线上允许同时存在I2C设备、I3C从设备和I3C次级主设备。

### 基本概念<a name="3"></a>

- IBI（In-Band Interrupt）：带内中断。

    在SCL线没有启动信号时，I3C从设备可以通过拉低SDA线使主设备发出SCL启动信号，从而发出带内中断请求。若有多个从设备同时发出中断请求，I3C主设备则通过从设备地址进行仲裁，低地址优先相应。

- DAA（Dynamic Address Assignment）：动态地址分配。

    I3C支持对从设备地址进行动态分配从而避免地址冲突。在分配动态地址之前，连接到I3C总线上的每个I3C/I2C设备都应以两种方式之一来唯一标识：
 
    - 设备可能有一个符合I2C规范的静态地址，主机可以使用此静态地址。

    - 在任何情况下，I3C设备均应具有48位的临时ID。除非设备具有静态地址且主机使用静态地址，否则主机应使用此48位临时ID。

- CCC（Common Command Code）：通用命令代码。

    所有I3C设备均支持CCC，可以直接将其传输到特定的I3C从设备，也可以同时传输到所有I3C从设备。

- BCR（Bus Characteristic Register）：总线特性寄存器。

    每个连接到I3C总线的I3C设备都应具有相关的只读总线特性寄存器（BCR），该寄存器描述了I3C兼容设备在动态地址分配和通用命令代码中的作用和功能。

- DCR（Device Characteristic Register）：设备特性寄存器。
  
    连接到I3C总线的每个I3C设备都应具有相关的只读设备特性寄存器（DCR），该寄存器描述了用于动态地址分配和通用命令代码的I3C兼容设备类型（例如加速度计、陀螺仪等）。


### 运作机制<a name="4"></a>

在HDF框架中，同类型控制器对象较多时（可能同时存在十几个同类型控制器），如果采用独立服务模式则需要配置更多的设备节点，且相关服务会占据更多的内存资源。相反，采用统一服务模式可以使用一个设备服务作为管理器，统一处理所有同类型对象的外部访问（这会在配置文件中有所体现），实现便捷管理和节约资源的目的。I3C模块采用统一服务模式（如图1）。

I3C模块各分层的作用为：

- 接口层：提供打开设备，写入数据，关闭设备的能力。

- 核心层：主要负责服务绑定、初始化以及释放管理器，并提供添加、删除以及获取控制器的能力。由于框架需要统一管理I3C总线上挂载的所有设备，因此还提供了添加、删除以及获取设备的能力，以及中断回调函数。

- 适配层：由驱动适配者实现与硬件相关的具体功能，如控制器的初始化等。

在统一模式下，所有的控制器都被核心层统一管理，并由核心层统一发布一个服务供接口层，因此这种模式下驱动无需再为每个控制器发布服务。

**图 1** I3C统一服务模式结构图<a name="fig1"></a>  

![I3C统一服务模式结构图](figures/统一服务模式结构图.png)

### 约束与限制<a name="5"></a>

I3C模块当前仅支持轻量和小型系统内核（LiteOS-A） 。

## 开发指导 <a name="6"></a>

### 场景介绍 <a name="7"></a>

I3C可连接单个或多个I3C、I2C从器件，它主要用于：

- 与传感器通信，如陀螺仪、气压计或支持I3C协议的图像传感器等。

- 通过软件或硬件协议转换，与其他通信接口（如UART串口等）的设备进行通信。

当驱动开发者需要将I3C设备适配到OpenHarmony时，需要进行I3C驱动适配，下文将介绍如何进行I3C驱动适配。

### 接口说明 <a name="8"></a>

为了保证上层在调用I3C接口时能够正确的操作硬件，核心层在//drivers/hdf_core/framework/support/platform/include/i3c/i3c_core.h中定义了以下钩子函数。驱动适配者需要在适配层实现这些函数的具体功能，并与这些钩子函数挂接，从而完成接口层与核心层的交互。

I3cMethod定义：

```c
struct I3cMethod {
    int32_t (*sendCccCmd)(struct I3cCntlr *cntlr, struct I3cCccCmd *ccc);
    int32_t (*transfer)(struct I3cCntlr *cntlr, struct I3cMsg *msgs, int16_t count);
    int32_t (*i2cTransfer)(struct I3cCntlr *cntlr, struct I3cMsg *msgs, int16_t count);
    int32_t (*setConfig)(struct I3cCntlr *cntlr, struct I3cConfig *config);
    int32_t (*getConfig)(struct I3cCntlr *cntlr, struct I3cConfig *config);
    int32_t (*requestIbi)(struct I3cDevice *dev);
    void (*freeIbi)(struct I3cDevice *dev);
};
```

**表 1** I3cMethod结构体成员的钩子函数功能说明
| 函数成员 | 入参 | 出参 | 返回值 | 功能 |
| - | - | - | - | - |
| sendCccCmd | **cntlr**：结构体指针，核心层I3C控制器<br />**ccc**：传入的通用命令代码结构体指针 | **ccc**：传出的通用命令代码结构体指针 | HDF_STATUS相关状态|发送CCC（Common command Code，即通用命令代码）|
| Transfer | **cntlr**：结构体指针，核心层I3C控制器<br />**msgs**：结构体指针，用户消息<br />**count**：int16_t，消息数量 | **msgs**：结构体指针，用户消息 | HDF_STATUS相关状态 | 使用I3C模式传递用户消息 |
|i2cTransfer | **cntlr**：结构体指针，核心层I3C控制器<br />**msgs**：结构体指针，用户消息<br />**count**：int16_t，消息数量 | **msgs**：结构体指针，用户消息 | HDF_STATUS相关状态 | 使用I2C模式传递用户消息 |
| setConfig | **cntlr**：结构体指针，核心层I3C控制器<br />**config**：控制器配置参数| 无 | HDF_STATUS相关状态 | 设置I3C控制器配置参数 |
| getConfig | **cntlr**：结构体指针，核心层I3C控制器 | **config**：控制器配置参数 | HDF_STATUS相关状态 | 获取I3C控制器配置参数 |
| requestIbi | **device**：结构体指针，核心层I3C设备 | 无 | HDF_STATUS相关状态 | 为I3C设备请求IBI（In-Band Interrupt，即带内中断） |
| freeIbi | **device**：结构体指针，核心层I3C设备 | 无 | HDF_STATUS相关状态 | 释放IBI |

### 开发步骤 <a name="9"></a>

I3C模块适配包含以下五个步骤：

- 实例化驱动入口

    - 实例化HdfDriverEntry结构体成员。

    - 调用HDF_INIT将HdfDriverEntry实例化对象注册到HDF框架中。

- 配置属性文件

    - 在device_info.hcs文件中添加deviceNode描述。

    - 【可选】添加i3c_config.hcs器件属性文件。

- 实例化I3C控制器对象

    - 初始化I3cCntlr成员。

    - 实例化I3cCntlr成员I3cMethod方法集合，其定义和成员函数说明见下文。

- 注册中断处理子程序

    为控制器注册中断处理程序，实现设备热接入和IBI（带内中断）功能。

- 驱动调试

    【可选】针对新增驱动程序，建议验证驱动基本功能，例如挂载后的测试用例是否成功，数据能否传输等。

### 开发实例

下方将以Hi3516DV300的虚拟驱动//drivers/hdf_core/framework/test/unittest/platform/virtual/i3c_virtual.c为示例，展示需要驱动适配者提供哪些内容来完整实现设备功能。

1. 实例化驱动入口
    驱动入口必须为HdfDriverEntry（在//drivers/hdf_core/framework/include/core/hdf_device_desc.h中定义）类型的全局变量，且moduleName要和device_info.hcs中保持一致。HDF框架会将所有加载的驱动的HdfDriverEntry对象首地址汇总，形成一个类似数组的段地址空间，方便上层调用。

    一般在加载驱动时HDF会先调用Bind函数，再调用Init函数加载该驱动。当Init调用异常时，HDF框架会调用Release释放驱动资源并退出。

    I3C驱动入口参考：

    > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**<br>    
    > I3C控制器会出现很多个控制器挂接的情况，因而在HDF框架中首先会为此类型的控制器创建一个管理器对象，并同时对外发布一个管理器服务来统一处理外部访问。这样，用户需要打开某个控制器时，会先获取到管理器服务，然后管理器服务根据用户指定参数查找到指定控制器。
    > 
    > I3C管理器服务的驱动由核心层实现，驱动适配者不需要关注这部分内容的实现，但在实现Init函数的时候需要调用核心层的I3cCntlrAdd函数，它会实现相应功能。
    
    ```c
    static struct HdfDriverEntry g_virtualI3cDriverEntry = {
        .moduleVersion = 1,
        .Init = VirtualI3cInit,
        .Release = VirtualI3cRelease,
        .moduleName = "virtual_i3c_driver",        // 【必要且与hcs文件中的名字匹配】
    };
    HDF_INIT(g_virtualI3cDriverEntry);             // 调用HDF_INIT将驱动入口注册到HDF框架中
    
    // 核心层i3c_core.c管理器服务的驱动入口
    struct HdfDriverEntry g_i3cManagerEntry = {
        .moduleVersion = 1,
        .Init     = I3cManagerInit,
        .Release  = I3cManagerRelease,
        .moduleName = "HDF_PLATFORM_I3C_MANAGER",  // 这与device_info.hcs文件中device0对应
    };
    HDF_INIT(g_i3cManagerEntry);
    ```

2. 配置属性文件
    完成驱动入口注册之后，下一步请在//vendor/hisilicon/hispark_taurus/hdf_config/device_info/device_info.hcs文件中添加deviceNode信息，并在i3c_config.hcs中配置器件属性。deviceNode信息与驱动入口注册相关，器件属性值对于驱动适配者的驱动实现以及核心层I3cCntlr相关成员的默认值或限制范围有密切关系。

    统一服务模式的特点是device_info.hcs文件中第一个设备节点必须为I3C管理器，其各项参数必须如表2设置：

    **表 2** device_info.hcs节点参数说明
   
    | 成员名 | 值 |
    | -------- | -------- |
    | policy | 驱动服务发布的策略，I3C管理器具体配置为0，表示驱动不需要发布服务 |
    | priority | 驱动启动优先级（0-200），值越大优先级越低。I3C管理器具体配置为52 |
    | permission | 驱动创建设备节点权限，I3C管理器具体配置为0664 |
    | moduleName | 驱动名称，I3C管理器固定为HDF_PLATFORM_I3C_MANAGER |
    | serviceName | 驱动对外发布服务的名称，I3C管理器服务名设置为HDF_PLATFORM_I3C_MANAGER |
    | deviceMatchAttr | 驱动私有数据匹配的关键字，I3C管理器没有使用，可忽略 |

    从第二个节点开始配置具体I3C控制器信息，此节点并不表示某一路I3C控制器，而是代表一个资源性质设备，用于描述一类I3C控制器的信息。本例只有一个I3C控制器，如有多个控制器，则需要在device_info.hcs文件增加deviceNode信息，以及在i3c_config文件中增加对应的器件属性。

    - device_info.hcs配置参考

        ```c
        root {
            device_i3c :: device {
                device0 :: deviceNode {
                    policy = 0;
                    priority = 52;
                    permission = 0644;
                    serviceName = "HDF_PLATFORM_I3C_MANAGER";
                    moduleName = "HDF_PLATFORM_I3C_MANAGER";
                }
            }
            i3c_virtual :: deviceNode {
                policy = 0;                               // 等于0，不需要发布服务。
                priority = 56;                            // 驱动启动优先级。
                permission = 0644;                        // 驱动创建设备节点权限。
                moduleName = "virtual_i3c_driver";        // 【必要】用于指定驱动名称，需要与期望的驱动Entry中的moduleName一致。
                serviceName = "VIRTUAL_I3C_DRIVER";       // 【必要】驱动对外发布服务的名称，必须唯一。
                deviceMatchAttr = "virtual_i3c";          // 【必要】用于配置控制器私有数据，要与i3c_config.hcs中对应控制器保持一致。
            }                                             // 具体的控制器信息在i3c_config.hcs中。
        }
        ```

    - i3c_config.hcs 配置参考

        ```c
        root {
            platform {
                i3c_config {
                    match_attr = "virtual_i3c";  // 【必要】需要和device_info.hcs中的deviceMatchAttr值一致
                    template i3c_controller {    // 模板公共参数，继承该模板的节点如果使用模板中的默认值，则节点字段可以缺省。
                        busId = 0;               // 【必要】i3c总线号
                        busMode = 0x0;           // 总线模式，0x0：纯净；0x1：混合高速；0x2：混合受限；0x3：混合低速。
                        regBasePhy = 0x120b0000; // 【必要】物理基地址
                        regSize = 0xd1;          // 【必要】寄存器位宽
                        IrqNum = 20;             // 【必要】中断号
                        i3cMaxRate = 12900000;   // 【可选】i3c模式最大时钟速率
                        i3cRate = 12500000;      // 【可选】i3c模式时钟速率
                        i2cFmRate = 1000000;     // 【可选】i2c FM模式时钟速率
                        i2cFmPlusRate = 400000;  // 【可选】i2c FM+模式时钟速率
                    }
                    controller_0 :: i3c_controller {
                        busId = 18;
                        IrqNum = 20;
                    }
                }
            }
        }
        ```

        需要注意的是，新增i3c_config.hcs配置文件后，必须在对应的hdf.hcs文件中包含i3c_config.hcs所在路径信息，否则配置文件无法生效。

3. 实例化I3C控制器对象

    配置属性文件完成后，要以核心层I3cCntlr对象的初始化为核心，包括驱动适配者自定义结构体（传递参数和数据），实例化I3cCntlr成员I3cMethod（让用户可以通过接口来调用驱动底层函数）。

    此步骤需要通过实现HdfDriverEntry成员函数（Bind，Init，Release）来完成。

    I3cCntlr成员钩子函数结构体I3cMethod的实例化，I3cLockMethod钩子函数结构体本例未实现，若要实例化，可参考I2C驱动开发。

    - 自定义结构体参考

        > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**<br>          
        > 从驱动的角度看，自定义结构体是参数和数据的载体，而且i3c_config.hcs文件中的数值会被HDF读入并通过DeviceResourceIface来初始化结构体成员，其中一些重要数值也会传递给核心层I3cCntlr对象，例如设备号、总线号等。

        ```c
        struct VirtualI3cCntlr {
            struct I3cCntlr cntlr;           // 【必要】是核心层控制对象，具体描述见下面。
            volatile unsigned char *regBase; // 【必要】寄存器基地址
            uint32_t regBasePhy;             // 【必要】寄存器物理基地址
            uint32_t regSize;                // 【必要】寄存器位宽
            uint16_t busId;                  // 【必要】设备号
            uint16_t busMode;
            uint16_t IrqNum;
            uint32_t i3cMaxRate;
            uint32_t i3cRate;
            uint32_t i2cFmRate;
            uint32_t i2cFmPlusRate;
        };
        
        // I3cCntlr是核心层控制器结构体，其中的成员在Init函数中被赋值。
        struct I3cCntlr {
            OsalSpinlock lock;
            void *owner;
            int16_t busId;
            struct I3cConfig config;
            uint16_t addrSlot[(I3C_ADDR_MAX + 1) / ADDRS_PER_UINT16];
            struct I3cIbiInfo *ibiSlot[I3C_IBI_MAX];
            const struct I3cMethod *ops;
            const struct I3cLockMethod *lockOps;
            void *priv;
        };
        ```

    - Init函数开发参考

        **入参：** 

        HdfDeviceObject是整个驱动对外提供的接口参数，具备HCS配置文件的信息。

        **返回值：**

        HDF_STATUS相关状态（表3为部分展示，如需使用其他状态，可参考//drivers/hdf_core/interfaces/inner_api/utils/hdf_base.h中HDF_STATUS定义）。

        **表 3** HDF_STATUS相关状态说明

        | 状态(值) | 问题描述 |
        | -------- | -------- |
        | HDF_ERR_INVALID_OBJECT | 控制器对象非法 |
        | HDF_ERR_INVALID_PARAM | 参数非法 |
        | HDF_ERR_MALLOC_FAIL | 内存分配失败 |
        | HDF_ERR_IO | I/O错误 |
        | HDF_SUCCESS | 传输成功 |
        | HDF_FAILURE | 传输失败 |

        **函数说明：**

        初始化自定义结构体对象，初始化I3cCntlr成员，调用核心层I3cCntlrAdd函数。

        ```c
        static int32_t VirtualI3cParseAndInit(struct HdfDeviceObject *device, const struct DeviceResourceNode *node)
        {
            int32_t ret;
            struct VirtualI3cCntlr *virtual = NULL;                                // 【必要】自定义结构体对象
            (void)device;

            virtual = (struct VirtualI3cCntlr *)OsalMemCalloc(sizeof(*virtual));   // 【必要】内存分配
            if (virtual == NULL) {
                HDF_LOGE("%s: Malloc virtual fail!", __func__);
                return HDF_ERR_MALLOC_FAIL;
            }

            ret = VirtualI3cReadDrs(virtual, node);                                // 【必要】将i3c_config文件的默认值填充到结构体中，函数定义见下方
            if (ret != HDF_SUCCESS) {
                HDF_LOGE("%s: Read drs fail! ret:%d", __func__, ret);
                goto __ERR__;
            }
            ......
            virtual->regBase = OsalIoRemap(virtual->regBasePhy, virtual->regSize); // 【必要】地址映射
            ret = OsalRegisterIrq(hi35xx->softIrqNum, OSAL_IRQF_TRIGGER_NONE, I3cIbiHandle, "I3C", virtual); //【必要】注册中断程序
            if (ret != HDF_SUCCESS) {
                HDF_LOGE("%s: register irq failed!", __func__);
                return ret;
            }
            ......
            VirtualI3cCntlrInit(virtual);              // 【必要】I3C设备的初始化
            virtual->cntlr.priv = (void *)node;        // 【必要】存储设备属性
            virtual->cntlr.busId = virtual->busId;     // 【必要】初始化I3cCntlr成员
            virtual->cntlr.ops = &g_method;            // 【必要】I3cMethod的实例化对象的挂载
            (void)OsalSpinInit(&virtual->spin);
            ret = I3cCntlrAdd(&virtual->cntlr);        // 【必要且重要】调用此函数将控制器添加至核心，返回成功信号后驱动才完全接入平台核心层。
            if (ret != HDF_SUCCESS) {
                HDF_LOGE("%s: add i3c controller failed! ret = %d", __func__, ret);
                (void)OsalSpinDestroy(&virtual->spin);
                goto __ERR__;
            }

            return HDF_SUCCESS;
        __ERR__:                                       // 若控制器添加失败，需要执行去初始化相关函数。
            if (virtual != NULL) {
                OsalMemFree(virtual);
                virtual = NULL;
            }

            return ret;
        }

        static int32_t VirtualI3cInit(struct HdfDeviceObject *device)
        {
            int32_t ret;
            const struct DeviceResourceNode *childNode = NULL;

            if (device == NULL || device->property == NULL) {
                HDF_LOGE("%s: device or property is NULL", __func__);
                return HDF_ERR_INVALID_OBJECT;
            }

            DEV_RES_NODE_FOR_EACH_CHILD_NODE(device->property, childNode) {
                ret = VirtualI3cParseAndInit(device, childNode);
                if (ret != HDF_SUCCESS) {
                    break;
                }
            }

            return ret;
        }

        static int32_t VirtualI3cReadDrs(struct VirtualI3cCntlr *virtual, const struct DeviceResourceNode *node)
        {
            struct DeviceResourceIface *drsOps = NULL;

            // 获取drsOps方法
            drsOps = DeviceResourceGetIfaceInstance(HDF_CONFIG_SOURCE);
            if (drsOps == NULL || drsOps->GetUint32 == NULL || drsOps->GetUint16 == NULL) {
                HDF_LOGE("%s: Invalid drs ops fail!", __func__);
                return HDF_FAILURE;
            }
            // 将配置参数依次读出，并填充至结构体中
            if (drsOps->GetUint16(node, "busId", &virtual->busId, 0) != HDF_SUCCESS) {
                HDF_LOGE("%s: Read busId fail!", __func__);
                return HDF_ERR_IO;
            }
            if (drsOps->GetUint16(node, "busMode", &virtual->busMode, 0) != HDF_SUCCESS) {
                HDF_LOGE("%s: Read busMode fail!", __func__);
                return HDF_ERR_IO;
            }
            if (drsOps->GetUint16(node, "IrqNum", &virtual->IrqNum, 0) != HDF_SUCCESS) {
                HDF_LOGE("%s: Read IrqNum fail!", __func__);
                return HDF_ERR_IO;
            }
            ......
            return HDF_SUCCESS;
        }
        ```

    - Release函数开发参考

        **入参：** 

        HdfDeviceObject是整个驱动对外提供的接口参数，具备HCS配置文件的信息。
        
        **返回值：**

        无。
        
        **函数说明：**

        释放内存和删除控制器，该函数需要在驱动入口结构体中赋值给Release接口，当HDF框架调用Init函数初始化驱动失败时，可以调用Release释放驱动资源。

        > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**<br>          
        > 所有强制转换获取相应对象的操作**前提**是在Init函数中具备对应赋值的操作。

        ```c
        static void VirtualI3cRemoveByNode(const struct DeviceResourceNode *node)
        {
            int32_t ret;
            int16_t busId;
            struct I3cCntlr *cntlr = NULL;
            struct VirtualI3cCntlr *virtual = NULL;
            struct DeviceResourceIface *drsOps = NULL;

            drsOps = DeviceResourceGetIfaceInstance(HDF_CONFIG_SOURCE);
            if (drsOps == NULL || drsOps->GetUint32 == NULL) {
                HDF_LOGE("%s: invalid drs ops fail!", __func__);
                return;
            }

            ret = drsOps->GetUint16(node, "busId", (uint16_t *)&busId, 0);
            if (ret != HDF_SUCCESS) {
                HDF_LOGE("%s: read busId fail!", __func__);
                return;
            }
            ......
            // 可以调用I3cCntlrGet函数通过设备的cntlrNum获取I3cCntlr对象，以及调用I3cCntlrRemove函数来释放I3cCntlr对象的内容。
            cntlr = I3cCntlrGet(busId);
            if (cntlr != NULL && cntlr->priv == node) {
                I3cCntlrPut(cntlr);
                I3cCntlrRemove(cntlr);                     // 【必要】主要是从管理器驱动那边移除I3cCntlr对象
                virtual = (struct VirtualI3cCntlr *)cntlr; // 【必要】通过强制转换获取自定义的对象并进行release操作
                (void)OsalSpinDestroy(&virtual->spin);
                OsalMemFree(virtual);
            }
            return;
        }

        static void VirtualI3cRelease(struct HdfDeviceObject *device)
        {
            const struct DeviceResourceNode *childNode = NULL;
        
            HDF_LOGI("%s: enter", __func__);
        
            if (device == NULL || device->property == NULL) {
                HDF_LOGE("%s: device or property is NULL", __func__);
                return;
            }
            ......
            // 遍历、解析i3c_config.hcs中的所有配置节点，并分别进行release操作
            DEV_RES_NODE_FOR_EACH_CHILD_NODE(device->property, childNode) {
                VirtualI3cRemoveByNode(childNode); //函数定义如上
            }
        }
        ```

4. 注册中断处理子程序

    在中断处理程序中通过判断中断产生的地址，实现热接入、IBI等操作。

    ```c
    static int32_t VirtualI3cReservedAddrWorker(struct VirtualI3cCntlr *virtual, uint16_t addr)
    {
        (void)virtual;
        switch (addr) {
            case I3C_HOT_JOIN_ADDR:
                 VirtualI3cHotJoin(virtual);
                break;
            case I3C_RESERVED_ADDR_7H3E:
            case I3C_RESERVED_ADDR_7H5E:
            case I3C_RESERVED_ADDR_7H6E:
            case I3C_RESERVED_ADDR_7H76:
            case I3C_RESERVED_ADDR_7H7A:
            case I3C_RESERVED_ADDR_7H7C:
            case I3C_RESERVED_ADDR_7H7F:
            // 广播地址单比特错误的所有情形
            HDF_LOGW("%s: broadcast Address single bit error!", __func__);
                break;
            default:
                HDF_LOGD("%s: Reserved address which is not supported!", __func__);
                break;
        }

        return HDF_SUCCESS;
    }

    static int32_t I3cIbiHandle(uint32_t irq, void *data)
    {
        struct VirtualI3cCntlr *virtual = NULL;
        struct I3cDevice *device = NULL;
        uint16_t ibiAddr;
        char *testStr = "Hello I3C!";

        (void)irq;
        if (data == NULL) {
            HDF_LOGW("%s: data is NULL!", __func__);
            return HDF_ERR_INVALID_PARAM;
        }
        virtual = (struct VirtualI3cCntlr *)data;
        // 【必要】获取产生中断的地址，使用CHECK_RESERVED_ADDR宏判断该地址是否为I3C保留地址。
        ibiAddr = VirtualI3cGetIbiAddr();
        if (CHECK_RESERVED_ADDR(ibiAddr) == I3C_ADDR_RESERVED) {
            HDF_LOGD("%s: Calling VirtualI3cResAddrWorker...", __func__);
            return VirtualI3cReservedAddrWorker(virtual, ibiAddr);
        } else {
            HDF_LOGD("%s: Calling I3cCntlrIbiCallback...", __func__);
            device = GetDeviceByAddr(&virtual->cntlr, ibiAddr);
            if (device == NULL) {
                HDF_LOGE("func:%s device is NULL!",__func__);
                return HDF_ERR_MALLOC_FAIL;
            }
            if (device->ibi->payload > VIRTUAL_I3C_TEST_STR_LEN) {
                // 将字符串"Hello I3C!"放入IBI缓冲区内
                *device->ibi->data = *testStr;
            }
            // 根据产生IBI的I3C设备调用IBI回调函数
            return I3cCntlrIbiCallback(device);
        }

        return HDF_SUCCESS;
    }
    ```

5. 驱动调试

    【可选】针对新增驱动程序，建议验证驱动基本功能，例如挂载后的测试用例是否成功，数据能否传输等。
