# I2C

## 概述

### 功能简介<a name="section2"></a>

I2C（Inter Integrated Circuit）总线是由Philips公司开发的一种简单、双向二线制同步串行总线。由于其硬件连接简单、成本低廉，因此被广泛应用于各种短距离通信的场景。

### 运作机制

在HDF框架中，同类型设备对象较多时（可能同时存在十几个同类型控制器），若采用独立服务模式，则需要配置更多的设备节点，且相关服务会占据更多的内存资源。相反，采用统一服务模式可以使用一个设备服务作为管理器，统一处理所有同类型对象的外部访问（这会在配置文件中有所体现），实现便捷管理和节约资源的目的。I2C模块即采用统一服务模式（如图1）。

在统一模式下，所有的控制器都被核心层统一管理，并由核心层统一发布一个服务供接口层，因此这种模式下驱动无需再为每个控制器发布服务。

I2C模块各分层的作用为：

- 接口层：提供打开设备，数据传输以及关闭设备的能力。

- 核心层：主要负责服务绑定、初始化以及释放管理器，并提供添加、删除以及获取控制器的能力。

- 适配层：由驱动适配者实现与硬件相关的具体功能，如控制器的初始化等。

**图 1** I2C统一服务模式结构图<a name="fig1"></a>  

![I2C统一服务模式结构图](figures/统一服务模式结构图.png)

## 使用指导

### 场景介绍

I2C通常用于与各类支持I2C协议的传感器、执行器或输入输出设备进行通信。当驱动开发者需要将I2C设备适配到OpenHarmony时，需要进行I2C驱动适配，下文将介绍如何进行I2C驱动适配。

### 接口说明

为了保证上层在调用I2C接口时能够正确的操作硬件，核心层在//drivers/hdf_core/framework/support/platform/include/i2c/i2c_core.h中定义了以下钩子函数。驱动适配者需要在适配层实现这些函数的具体功能，并与这些钩子函数挂接，从而完成接口层与核心层的交互。

I2cMethod和I2cLockMethod定义：

```c
struct I2cMethod {
    int32_t (*transfer)(struct I2cCntlr *cntlr, struct I2cMsg *msgs, int16_t count);
};

struct I2cLockMethod { // 锁机制操作结构体
    int32_t (*lock)(struct I2cCntlr *cntlr);
    void (*unlock)(struct I2cCntlr *cntlr);
};
```

在适配层中，I2cMethod必须被实现，I2cLockMethod可根据实际情况考虑是否实现。核心层提供了默认的I2cLockMethod，其中使用mutex作为保护临界区的锁：

```c
static int32_t I2cCntlrLockDefault(struct I2cCntlr *cntlr)
{
    if (cntlr == NULL) {
        return HDF_ERR_INVALID_OBJECT;
    }
    return OsalMutexLock(&cntlr->lock);
}

static void I2cCntlrUnlockDefault(struct I2cCntlr *cntlr)
{
    if (cntlr == NULL) {
        return;
    }
    (void)OsalMutexUnlock(&cntlr->lock);
}

static const struct I2cLockMethod g_i2cLockOpsDefault = {
    .lock = I2cCntlrLockDefault,
    .unlock = I2cCntlrUnlockDefault,
};
```

若实际情况不允许使用mutex（例如使用者可能在中断上下文调用I2C接口，mutex可能导致休眠，而中断上下文不允许休眠）时，驱动适配者可以考虑使用其他类型的锁来实现一个自定义的I2cLockMethod。一旦实现了自定义的I2cLockMethod，默认的I2cLockMethod将被覆盖。

**表 1** I2cMethod结构体成员函数功能说明

| 函数成员 | 入参 | 出参 | 返回值 | 功能 | 
| -------- | -------- | -------- | -------- | -------- |
| transfer | cntlr：结构体指针，核心层I2C控制器。<br>msgs：结构体指针，用户消息。<br>count：uint16_t类型，消息数量。 | 无 | HDF_STATUS相关状态 | 传递用户消息 | 

**表 2** I2cLockMethod结构体成员函数功能说明

| 函数成员 | 入参 | 出参 | 返回值 | 功能 | 
| -------- | -------- | -------- | -------- | -------- |
| lock | cntlr：结构体指针，核心层I2C控制器。 | 无 | HDF_STATUS相关状态 | 获取临界区锁 | 
| unlock | cntlr：结构体指针，核心层I2C控制器。 | 无 | HDF_STATUS相关状态 | 释放临界区锁 | 

### 开发步骤

I2C模块适配包含以下四个步骤：

1. 实例化驱动入口

    - 实例化HdfDriverEntry结构体成员。

    - 调用HDF_INIT将HdfDriverEntry实例化对象注册到HDF框架中。

2. 配置属性文件

    - 在device_info.hcs文件中添加deviceNode描述。

    - 【可选】添加i2c_config.hcs器件属性文件。

3. 实例化I2C控制器对象

    - 初始化I2cCntlr成员。

    - 实例化I2cCntlr成员I2cMethod和I2cLockMethod。

        > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**<br>
        > 实例化I2cCntlr成员I2cMethod和I2cLockMethod，详见[接口说明](#接口说明)。

4. 驱动调试

    【可选】针对新增驱动程序，建议验证驱动基本功能，例如挂载后的信息反馈，消息传输的成功与否等。

### 开发实例

下方将以Hi3516DV300的驱动//device/soc/hisilicon/common/platform/i2c/i2c_hi35xx.c为示例，展示需要驱动适配者提供哪些内容来完整实现设备功能。

1. 实例化驱动入口

    驱动入口必须为HdfDriverEntry（在hdf_device_desc.h中定义）类型的全局变量，且moduleName要和device_info.hcs中保持一致。HDF框架会将所有加载的驱动的HdfDriverEntry对象首地址汇总，形成一个类似数组的段地址空间，方便上层调用。

    一般在加载驱动时HDF会先调用Bind函数，再调用Init函数加载该驱动。当Init调用异常时，HDF框架会调用Release释放驱动资源并退出。

    I2C驱动入口开发参考：

	I2C控制器会出现很多个设备挂接的情况，因而在HDF框架中首先会为此类型的设备创建一个管理器对象，并同时对外发布一个管理器服务来统一处理外部访问。这样，用户需要打开某个设备时，会先获取到管理器服务，然后管理器服务根据用户指定参数查找到指定设备。

    I2C管理器服务的驱动由核心层实现，驱动适配者不需要关注这部分内容的实现，但在实现Init函数的时候需要调用核心层的I2cCntlrAdd函数，它会实现相应功能。

    ```c
    struct HdfDriverEntry g_i2cDriverEntry = {
        .moduleVersion = 1,
        .Init = Hi35xxI2cInit,
        .Release = Hi35xxI2cRelease,
        .moduleName = "hi35xx_i2c_driver",        // 【必要且与config.hcs文件里面匹配】
    };
    HDF_INIT(g_i2cDriverEntry);                   // 调用HDF_INIT将驱动入口注册到HDF框架中

    // 核心层i2c_core.c管理器服务的驱动入口
    struct HdfDriverEntry g_i2cManagerEntry = {
       .moduleVersion = 1,
       .Bind = I2cManagerBind,
       .Init = I2cManagerInit,
       .Release = I2cManagerRelease,
       .moduleName = "HDF_PLATFORM_I2C_MANAGER",  // 这与device_info.hcs文件中device0对应
    };
    HDF_INIT(g_i2cManagerEntry);
    ```

2. 配置属性文件

    完成驱动入口注册之后，下一步请在//vendor/hisilicon/hispark_taurus/hdf_config/device_info/device_info.hcs文件中添加deviceNode信息，并在i2c_config.hcs中配置器件属性。

    deviceNode信息与驱动入口注册相关，器件属性值对于驱动适配者的驱动实现以及核心层I2cCntlr相关成员的默认值或限制范围有密切关系。

    统一服务模式的特点是device_info.hcs文件中第一个设备节点必须为I2C管理器，其各项参数必须如表3设置：

    **表 3** device_info.hcs节点参数说明
   
    | 成员名 | 值 |
    | -------- | -------- |
    | policy | 驱动服务发布的策略，I2C管理器具体配置为2，表示驱动对内核态和用户态都发布服务 |
    | priority | 驱动启动优先级（0-200），值越大优先级越低。I2C管理器具体配置为50 |
    | permission | 驱动创建设备节点权限，I2C管理器具体配置为0664 |
    | moduleName | 驱动名称，I2C管理器固定为HDF_PLATFORM_I2C_MANAGER |
    | serviceName | 驱动对外发布服务的名称，I2C管理器服务名设置为HDF_PLATFORM_I2C_MANAGER |
    | deviceMatchAttr | 驱动私有数据匹配的关键字，I2C管理器设置为hdf_platform_i2c_manager |

    从第二个节点开始配置具体I2C控制器信息，此节点并不表示某一路I2C控制器，而是代表一个资源性质设备，用于描述一类I2C控制器的信息。多个控制器之间相互区分的参数是busId和reg_pbase，这在i2c_config.hcs文件中有所体现。

    - device_info.hcs配置参考

        ```c
        root {
            device_info {
                match_attr = "hdf_manager";
                device_i2c :: device {
                    device0 :: deviceNode {
                        policy = 2;
                        priority = 50;
                        permission = 0644;
                        moduleName = "HDF_PLATFORM_I2C_MANAGER";
                        serviceName = "HDF_PLATFORM_I2C_MANAGER";
                        deviceMatchAttr = "hdf_platform_i2c_manager";
                    }
                    device1 :: deviceNode {
                        policy = 0;                               // 等于0，不需要发布服务。
                        priority = 55;                            // 驱动启动优先级。
                        permission = 0644;                        // 驱动创建设备节点权限。
                        moduleName = "hi35xx_i2c_driver";         //【必要】用于指定驱动名称，需要与期望的驱动Entry中的moduleName一致。
                        serviceName = "HI35XX_I2C_DRIVER";        //【必要】驱动对外发布服务的名称，必须唯一。
                        deviceMatchAttr = "hisilicon_hi35xx_i2c"; //【必要】用于配置控制器私有数据，要与i2c_config.hcs中对应控制器保持一致，
                                                                  // 具体的控制器信息在 i2c_config.hcs中。
                    }
                }
            }
        }
        ```

    - i2c_config.hcs配置参考

        ```c
        root {
            platform {
                i2c_config {
                    match_attr = "hisilicon_hi35xx_i2c";  // 【必要】需要和device_info.hcs中的deviceMatchAttr值一致
                    template i2c_controller {             // 模板公共参数，继承该模板的节点如果使用模板中的默认值，则节点字段可以缺省。
                        bus = 0;                          // 【必要】i2c识别号
                        reg_pbase = 0x120b0000;           // 【必要】物理基地址
                        reg_size = 0xd1;                  // 【必要】寄存器位宽
                        irq = 0;                          // 【可选】中断号，由控制器的中断特性决定是否需要
                        freq = 400000;                    // 【可选】频率，初始化硬件控制器的可选参数
                        clk = 50000000;                   // 【可选】控制器时钟，由控制器时钟的初始化流程决定是否需要
                    }
                    controller_0x120b0000 :: i2c_controller {
                        bus = 0;
                    }
                    controller_0x120b1000 :: i2c_controller {
                        bus = 1;
                        reg_pbase = 0x120b1000;
                    }
                    ...
                }
            }
        }
        ```

        需要注意的是，新增i2c_config.hcs配置文件后，必须在hdf.hcs文件中将其包含，否则配置文件无法生效。

        例如：本例中i2c_config.hcs所在路径为device/soc/hisilicon/hi3516dv300/sdk_liteos/hdf_config/i2c/i2c_config.hcs，则必须在产品对应的hdf.hcs中添加如下语句：

        ```c
        #include "../../../../device/soc/hisilicon/hi3516dv300/sdk_liteos/hdf_config/i2c/i2c_config.hcs" // 配置文件相对路径
        ```

3. 实例化I2C控制器对象

    完成驱动入口注册之后，下一步就是以核心层I2cCntlr对象的初始化为核心，包括驱动适配者自定义结构体（传递参数和数据），实例化I2cCntlr成员I2cMethod（让用户可以通过接口来调用驱动底层函数），实现HdfDriverEntry成员函数（Bind，Init，Release）。

    - 自定义结构体参考

        从驱动的角度看，自定义结构体是参数和数据的载体，而且i2c_config.hcs文件中的数值会被HDF读入通过DeviceResourceIface来初始化结构体成员，其中一些重要数值也会传递给核心层I2cCntlr对象，例如设备号、总线号等。

        ```c
        // 驱动适配者自定义结构体
        struct Hi35xxI2cCntlr {
            struct I2cCntlr cntlr;            // 【必要】是核心层控制对象，具体描述见下面。
            OsalSpinlock spin;                // 【必要】驱动适配者需要基于此锁变量对各个i2c操作函数实现对应的加锁解锁。
            volatile unsigned char  *regBase; // 【必要】寄存器基地址
            uint16_t regSize;                 // 【必要】寄存器位宽
            int16_t bus;                      // 【必要】i2c_config.hcs文件中可读取具体值
            uint32_t clk;                     // 【可选】驱动适配者自定义
            uint32_t freq;                    // 【可选】驱动适配者自定义
            uint32_t irq;                     // 【可选】驱动适配者自定义
            uint32_t regBasePhy;              // 【必要】寄存器物理基地址
        };
      
        // I2cCntlr是核心层控制器结构体，其中的成员在Init函数中会被赋值。
        struct I2cCntlr {
            struct OsalMutex lock;
            void *owner;
            int16_t busId;
            void *priv;
            const struct I2cMethod *ops;
            const struct I2cLockMethod *lockOps;
        };
        ```

    - I2cCntlr成员钩子函数结构体I2cMethod的实例化，和锁机制钩子函数结构体I2cLockMethod实例化，其他成员在Init函数中初始化。

        ```c
        // i2c_hi35xx.c中的示例
        static const struct I2cMethod g_method = {
            .transfer = Hi35xxI2cTransfer,
        };

        static const struct I2cLockMethod g_lockOps = {
            .lock = Hi35xxI2cLock,     // 加锁函数
            .unlock = Hi35xxI2cUnlock, // 解锁函数
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

        初始化自定义结构体对象，初始化I2cCntlr成员，调用核心层I2cCntlrAdd函数，接入VFS（可选）。

        ```c
        static int32_t Hi35xxI2cInit(struct HdfDeviceObject *device)
        {
            ......
            // 遍历、解析i2c_config.hcs中的所有配置节点，并分别进行初始化，需要调用Hi35xxI2cParseAndInit函数。
            DEV_RES_NODE_FOR_EACH_CHILD_NODE(device->property, childNode) {
                ret = Hi35xxI2cParseAndInit(device, childNode);//函数定义见下
            ......
            }
            ......
        }

        static int32_t Hi35xxI2cParseAndInit(struct HdfDeviceObject *device, const struct DeviceResourceNode *node)
        {
            struct Hi35xxI2cCntlr *hi35xx = NULL;
            ......                                                              // 入参判空
            hi35xx = (struct Hi35xxI2cCntlr *)OsalMemCalloc(sizeof(*hi35xx));   // 内存分配
            ......                                                              // 返回值校验
            hi35xx->regBase = OsalIoRemap(hi35xx->regBasePhy, hi35xx->regSize); // 地址映射
            ......                                                              // 返回值校验
            Hi35xxI2cCntlrInit(hi35xx);                                         // 【必要】i2c设备的初始化
												                                
            hi35xx->cntlr.priv = (void *)node;                                  // 【必要】存储设备属性
            hi35xx->cntlr.busId = hi35xx->bus;                                  // 【必要】初始化I2cCntlr成员busId
            hi35xx->cntlr.ops = &g_method;                                      // 【必要】I2cMethod的实例化对象的挂载
            hi35xx->cntlr.lockOps = &g_lockOps;                                 // 【必要】I2cLockMethod的实例化对象的挂载
            (void)OsalSpinInit(&hi35xx->spin);                                  // 【必要】锁的初始化
            ret = I2cCntlrAdd(&hi35xx->cntlr);                                  // 【必要】调用此函数将控制器对象添加至平台核心层，返回成功信号后驱动才完全接入平台核心层。
            ...... 
        #ifdef USER_VFS_SUPPORT
            (void)I2cAddVfsById(hi35xx->cntlr.busId);                           // 【可选】若支持用户级的虚拟文件系统，则接入。
        #endif
            return HDF_SUCCESS;
        __ERR__:                                                                // 若不成功，需要回滚函数内已执行的操作（如取消IO映射、释放内存等），并返回错误码
            if (hi35xx != NULL) {
                if (hi35xx->regBase != NULL) {
                    OsalIoUnmap((void *)hi35xx->regBase);
                    hi35xx->regBase = NULL;
                }
                OsalMemFree(hi35xx);
                hi35xx = NULL;
            }
            return ret;
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
        static void Hi35xxI2cRelease(struct HdfDeviceObject *device)
        {
            ...... 
            // 与Hi35xxI2cInit一样，需要将每个节点分别进行释放。
            DEV_RES_NODE_FOR_EACH_CHILD_NODE(device->property, childNode) {
                Hi35xxI2cRemoveByNode(childNode); // 函数定义如下
            }
        }

      static void Hi35xxI2cRemoveByNode(const struct DeviceResourceNode *node)
      {
          ...... 
          // 【必要】可以调用I2cCntlrGet函数通过设备的bus号获取I2cCntlr对象的指针，以及调用I2cCntlrRemove函数将I2cCntlr对象从平台核心层移除。
          cntlr = I2cCntlrGet(bus);
          if (cntlr != NULL && cntlr->priv == node) {
              ...... 
              I2cCntlrRemove(cntlr); 
              // 【必要】解除地址映射，释放锁和内存。
              hi35xx = (struct Hi35xxI2cCntlr *)cntlr; 
              OsalIoUnmap((void *)hi35xx->regBase);
              (void)OsalSpinDestroy(&hi35xx->spin);
              OsalMemFree(hi35xx);
          }
          return;
      }
      ```

4. 驱动调试

    【可选】针对新增驱动程序，建议验证驱动基本功能，例如挂载后的信息反馈，消息传输的成功与否等。
