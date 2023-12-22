# CLOCK

## 概述

### 功能简介<a name="section1"></a>

CLOCK，时钟是系统各个部件运行的基础，以CPU时钟举例，CPU 时钟是指 CPU 内部的时钟发生器，它以频率的形式工作，用来同步和控制 CPU 内部的各个操作。

### 基本概念<a name="section2"></a>

设备的时钟信号是指在电子设备中用于同步和控制各个模块或组件操作的信号。它是设备内部的一个基本信号源，用于确保设备的正常运行和数据传输的准确性。

### 运作机制

在HDF框架中，同类型设备对象较多时（可能同时存在十几个同类型配置器），若采用独立服务模式，则需要配置更多的设备节点，且相关服务会占据更多的内存资源。相反，采用统一服务模式可以使用一个设备服务作为管理器，统一处理所有同类型对象的外部访问（这会在配置文件中有所体现），实现便捷管理和节约资源的目的。CLOCK模块即采用统一服务模式（如图1所示）。

CLOCK模块各分层的作用为：

- 接口层：提供打开设备，写入数据，关闭设备的能力。

- 核心层：主要负责服务绑定、初始化以及释放管理器，并提供添加、删除以及获取控制器的能力。

- 适配层：由驱动适配者实现与硬件相关的具体功能，如控制器的初始化等。

在统一模式下，所有的控制器都被核心层统一管理，并由核心层统一发布一个服务供接口层，因此这种模式下驱动无需再为每个控制器发布服务。

**图 1** CLOCK统一服务模式结构图<a name="fig1"></a>  
![CLOCK统一服务模式结构图](figures/统一服务模式结构图.png)

## 使用指导

### 场景介绍

CLOCK提供芯片级别的时钟管理：时钟功能可用于控制芯片内部的时钟分频、时钟倍频、时钟源选择和时钟门控等操作。通过合理的时钟管理，可以提高芯片的能效，并确保各个功能部件的正确协调和协同工作。

### 接口说明

为了保证上层在调用CLOCK接口时能够正确的操作硬件，核心层在//drivers/hdf_core/framework/support/platform/include/clock/clock_core.h中定义了以下钩子函数。驱动适配者需要在适配层实现这些函数的具体功能，并与这些钩子函数挂接，从而完成接口层与核心层的交互。

ClockMethod和ClockLockMethod定义：

```c
struct ClockMethod {
    int32_t (*start)(struct ClockDevice *device);
    int32_t (*stop)(struct ClockDevice *device);
    int32_t (*setRate)(struct ClockDevice *device, uint32_t rate);
    int32_t (*getRate)(struct ClockDevice *device, uint32_t *rate);
    int32_t (*disable)(struct ClockDevice *device);
    int32_t (*enable)(struct ClockDevice *device);
    struct ClockDevice *(*getParent)(struct ClockDevice *device);
    int32_t (*setParent)(struct ClockDevice *device, struct ClockDevice *parent);
};

struct ClockLockMethod {
    int32_t (*lock)(struct ClockDevice *device);
    void (*unlock)(struct ClockDevice *device);
};

```

在适配层中，ClockMethod必须被实现，ClockLockMethod可根据实际情况考虑是否实现。核心层提供了默认的ClockLockMethod，其中使用Spinlock作为保护临界区的锁：

```c
static int32_t ClockDeviceLockDefault(struct ClockDevice *device)
{
    if (device == NULL) {
        HDF_LOGE("ClockDeviceLockDefault: device is null!");
        return HDF_ERR_INVALID_OBJECT;
    }
    return OsalSpinLock(&device->spin);
}

static void ClockDeviceUnlockDefault(struct ClockDevice *device)
{
    if (device == NULL) {
        HDF_LOGE("ClockDeviceUnlockDefault: device is null!");
        return;
    }
    (void)OsalSpinUnlock(&device->spin);
}

static const struct ClockLockMethod g_clockLockOpsDefault = {
    .lock = ClockDeviceLockDefault,
    .unlock = ClockDeviceUnlockDefault,
};

```

若实际情况不允许使用Spinlock，驱动适配者可以考虑使用其他类型的锁来实现一个自定义的ClockLockMethod。一旦实现了自定义的ClockLockMethod，默认的ClockLockMethod将被覆盖。

**表 1** ClockMethod结构体成员的钩子函数功能说明

| 函数成员 | 入参 | 出参 | 返回值 | 功能 | 
| -------- | -------- | -------- | -------- | -------- |
| start | device：结构体指针，核心层CLOCK控制器 | 无| HDF_STATUS相关状态 | 打开CLOCK设备 |
| stop | device：结构体指针，核心层CLOCK控制器 | 无 | HDF_STATUS相关状态 | 关闭CLOCK设备 |
| setRate | device：结构体指针，核心层CLOCK控制器 | 无 | HDF_STATUS相关状态 | 设置CLOCK设备的速率 |
| getRate | device：结构体指针，核心层CLOCK控制器 | 获取的速率 | HDF_STATUS相关状态 | 获取CLOCK设备的速率 |
| disable | device：结构体指针，核心层CLOCK控制器 | 无 | HDF_STATUS相关状态 | 使能CLOCK设备 |
| enable | device：结构体指针，核心层CLOCK控制器 | 无 | HDF_STATUS相关状态 | 去使能CLOCK设备 |
| getParent | device：结构体指针，核心层CLOCK控制器 | 获取的device：结构体指针，核心层CLOCK控制器 | HDF_STATUS相关状态 | 设置CLOCK设备的父设备 |
| setParent | device：结构体指针，核心层CLOCK控制器 | 无 | HDF_STATUS相关状态 | 设置CLOCK设备的父设备 |

**表 2** ClockLockMethod结构体成员函数功能说明

| 函数成员 | 入参 | 出参 | 返回值 | 功能 | 
| -------- | -------- | -------- | -------- | -------- |
| lock | device：结构体指针，核心层CLOCK设备对象。 | 无 | HDF_STATUS相关状态 | 获取临界区锁 | 
| unlock | device：结构体指针，核心层CLOCK设备对象。 | 无 | HDF_STATUS相关状态 | 释放临界区锁 | 

### 开发步骤

CLOCK模块适配包含以下四个步骤：

1. 实例化驱动入口

    - 实例化HdfDriverEntry结构体成员。

    - 调用HDF_INIT将HdfDriverEntry实例化对象注册到HDF框架中。

2. 配置属性文件

    - 在device_info.hcs文件中添加deviceNode描述。

    - 【可选】添加clock_config.hcs器件属性文件。

3. 实例化核心层接口函数

    - 初始化ClockDevice成员。

    - 实例化ClockDevice成员ClockMethod。

        > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**<br>
        > 实例化ClockDevice成员ClockMethod，其定义和成员说明见[接口说明](#接口说明)。

4. 驱动调试

    【可选】针对新增驱动程序，建议验证驱动基本功能，例如挂载后的测试用例是否成功等。

### 开发实例

下方将基于RK3568开发板以//drivers/hdf_core/adapter/khdf/linux/platform/clock/clock_adapter.c驱动为示例，展示需要驱动适配者提供哪些内容来完整实现设备功能。

1. 实例化驱动入口

    驱动入口必须为HdfDriverEntry（在//drivers/hdf_core/interfaces/inner_api/host/shared/hdf_device_desc.h中定义）类型的全局变量，且moduleName要和device_info.hcs中保持一致。HDF框架会将所有加载的驱动的HdfDriverEntry对象首地址汇总，形成一个类似数组的段地址空间，方便上层调用。

    一般在加载驱动时HDF会先调用Bind函数，再调用Init函数加载该驱动。当Init调用异常时，HDF框架会调用Release释放驱动资源并退出。

    CLOCK驱动入口参考：

    CLOCK控制器会出现多个设备挂接的情况，因而在HDF框架中首先会为此类型的设备创建一个管理器对象。这样，需要打开某个设备时，管理器对象会根据指定参数查找到指定设备。

    CLOCK管理器的驱动由核心层实现，驱动适配者不需要关注这部分内容的实现，但在实现Init函数的时候需要调用核心层的ClockDeviceAdd函数，它会实现相应功能。

    ```c
    struct HdfDriverEntry g_clockLinuxDriverEntry = {
        .moduleVersion = 1,
        .Bind = NULL,
        .Init = LinuxClockInit,
        .Release = LinuxClockRelease,
        .moduleName = "linux_clock_adapter",      // 【必要且与device_info.hcs文件内的模块名匹配】
    };
    HDF_INIT(g_clockLinuxDriverEntry);            // 调用HDF_INIT将驱动入口注册到HDF框架中

    // 核心层clock_core.c管理器服务的驱动入口
    struct HdfDriverEntry g_clockManagerEntry = {
        .moduleVersion = 1,
        .Bind = ClockManagerBind,                     // CLOCK不需要实现Bind，本例是一个空实现，驱动适配者可根据自身需要添加相关操作
        .Init = ClockManagerInit,                     // 见Init参考
        .Release = ClockManagerRelease,               // 见Release参考
        .moduleName = "HDF_PLATFORM_CLOCK_MANAGER",   // 这与device_info.hcs文件中device0对应
    };
    HDF_INIT(g_clockManagerEntry);                // 调用HDF_INIT将驱动入口注册到HDF框架中
    ```

2. 配置属性文件

    完成驱动入口注册之后，下一步请在//vendor/hihope/rk3568/hdf_config/khdf/device_info/device_info.hcs文件中添加deviceNode信息，并在clock_config.hcs中配置器件属性。

    deviceNode信息与驱动入口注册相关，器件属性值对于驱动适配者的驱动实现以及核心层ClockDevice相关成员的默认值或限制范围有密切关系。

    统一服务模式的特点是device_info.hcs文件中第一个设备节点必须为CLOCK管理器，其各项参数如表3所示：

    **表 3** device_info.hcs节点参数说明

    | 成员名 | 值 |
    | -------- | -------- |
    | policy | 驱动服务发布的策略，CLOCK管理器具体配置为2，表示驱动对内核态和用户态都发布服务 |
    | priority | 驱动启动优先级（0-200），值越大优先级越低。CLOCK管理器具体配置为59 |
    | permission | 驱动创建设备节点权限，CLOCK管理器具体配置为0664 |
    | moduleName | 驱动名称，CLOCK管理器固定为HDF_PLATFORM_CLOCK_MANAGER |
    | serviceName | 驱动对外发布服务的名称，CLOCK管理器服务名设置为HDF_PLATFORM_CLOCK_MANAGER |
    | deviceMatchAttr | 驱动私有数据匹配的关键字，CLOCK管理器没有使用，可忽略 |

    从第二个节点开始配置具体CLOCK控制器信息，第一个节点并不表示某一路CLOCK控制器，而是代表一个资源性质设备，用于描述一类CLOCK控制器的信息。本例只有一个CLOCK设备，如有多个设备，则需要在device_info.hcs文件增加deviceNode信息，以及在clock_config.hcs文件中增加对应的器件属性。

    - device_info.hcs配置参考
        ```
        root {
            device_info {
                platform :: host {
                    device_clock :: device {
                        device0 :: deviceNode {
                            policy = 2;
                            priority = 59;
                            permission = 0644;
                            moduleName = "HDF_PLATFORM_CLOCK_MANAGER";
                            serviceName = "HDF_PLATFORM_CLOCK_MANAGER";
                        }
                        device1 :: deviceNode {
                            policy = 0;                                 // 等于0，不需要发布服务。
                            priority = 65;                              // 驱动启动优先级。
                            permission = 0644;                          // 驱动创建设备节点权限。
                            moduleName = "linux_clock_adapter";         //【必要】用于指定驱动名称，需要与期望的驱动Entry中的moduleName一致。
                            deviceMatchAttr = "linux_clock_adapter_0";  //【必要】用于配置控制器私有数据，要与clock_config.hcs中对应控制器保持一致，具体的控制器信息在clock_config.hcs中。
                        }
                    }
                }
            }
        }
        ```

    - clock_config.hcs配置参考
    
        此处以RK3568为例，给出HCS配置参考。

        ```
        root {
            platform {
                clock_config {
                    match_attr = "linux_clock_adapter_0";
                    template clock_device {
                    }
                    device_clock_0x0000 :: clock_device {
                        deviceName = "/cpus/cpu@0";
                        deviceIndex = 1;
                    }
                }
            }
        }
        ```

        需要注意的是，新增clock_config.hcs配置文件后，必须在hdf.hcs文件中将其包含，否则配置文件无法生效。

        例如：本例中clock_config.hcs所在路径为//vendor/hihope/rk3568/hdf_config/ hdf_config/khdf/hdf.hcs，则必须在产品对应的hdf.hcs中添加如下语句：

        ```
        #include "platform/clock_config_linux.hcs" // 配置文件相对路径
        ```

        本例基于RK3568开发板的标准系统Linux内核运行，对应的hdf.hcs文件路径为//vendor/hihope/rk3568/hdf_config/ hdf_config/khdf/hdf.hcs驱动适配者需根据实际情况选择对应路径下的文件进行修改。

3. 实例化核心层函数

    完成驱动入口注册之后，下一步就是以核心层ClockDevice对象的初始化为核心，包括初始化驱动适配者自定义结构体（传递参数和数据），实例化ClockDevice成员ClockMethod（让用户可以通过接口来调用驱动底层函数），实现HdfDriverEntry成员函数（Bind，Init，Release）。

    - 自定义结构体参考。

        从驱动的角度看，自定义结构体是参数和数据的载体，而且clock_config.hcs文件中的数值会被HDF读入并通过DeviceResourceIface来初始化结构体成员，其中一些重要数值（例如设备号、总线号等）也会传递给核心层ClockDevice对象。
        ```c
        // ClockDevice是核心层控制器结构体，其中的成员在Init函数中会被赋值。
        struct ClockDevice {
            const struct ClockMethod *ops;
            OsalSpinlock spin;
            const char *deviceName;
            const char *clockName;
            uint32_t deviceIndex;
            const struct ClockLockMethod *lockOps;
            void *clk;
            void *priv;
            struct ClockDevice *parent;
        };
        ```
        - ClockDevice成员钩子函数结构体ClockMethod的实例化。

        ClockLockMethod钩子函数结构体本例未实现，若要实例化，可参考I2C驱动开发。

        ```c
        struct ClockMethod {
            int32_t (*start)(struct ClockDevice *device);
            int32_t (*stop)(struct ClockDevice *device);
            int32_t (*setRate)(struct ClockDevice *device, uint32_t rate);
            int32_t (*getRate)(struct ClockDevice *device, uint32_t *rate);
            int32_t (*disable)(struct ClockDevice *device);
            int32_t (*enable)(struct ClockDevice *device);
            struct ClockDevice *(*getParent)(struct ClockDevice *device);
            int32_t (*setParent)(struct ClockDevice *device, struct ClockDevice *parent);
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

        初始化自定义结构体对象，初始化ClockDevice成员，并调用核心层ClockDeviceAdd函数。

        ```c
        static int32_t LinuxClockInit(struct HdfDeviceObject *device)
        {
            int32_t ret = HDF_SUCCESS;
            struct DeviceResourceNode *childNode = NULL;

            if (device == NULL || device->property == NULL) {
                HDF_LOGE("LinuxClockInit: device or property is null");
                return HDF_ERR_INVALID_OBJECT;
            }

            DEV_RES_NODE_FOR_EACH_CHILD_NODE(device->property, childNode) {
                ret = ClockParseAndDeviceAdd(device, childNode);
                if (ret != HDF_SUCCESS) {
                    HDF_LOGE("LinuxClockInit: clock init fail!");
                    return ret;
                }
            }
            HDF_LOGE("LinuxClockInit: clock init success!");

            return HDF_SUCCESS;
        }

        static int32_t ClockParseAndDeviceAdd(struct HdfDeviceObject *device, struct DeviceResourceNode *node)
        {
            int32_t ret;
            struct ClockDevice *clockDevice = NULL;

            (void)device;
            clockDevice = (struct ClockDevice *)OsalMemCalloc(sizeof(*clockDevice));
            if (clockDevice == NULL) {
                HDF_LOGE("ClockParseAndDeviceAdd: alloc clockDevice fail!");
                return HDF_ERR_MALLOC_FAIL;
            }
            ret = ClockReadDrs(clockDevice, node);
            if (ret != HDF_SUCCESS) {
                HDF_LOGE("ClockParseAndDeviceAdd: read drs fail, ret: %d!", ret);
                OsalMemFree(clockDevice);
                return ret;
            }

            clockDevice->priv = (void *)node;
            clockDevice->ops = &g_method;

            ret = ClockDeviceAdd(clockDevice);
            if (ret != HDF_SUCCESS) {
                HDF_LOGE("ClockParseAndDeviceAdd: add clock device:%u fail!", clockDevice->deviceIndex);
                OsalMemFree(clockDevice);
                return ret;
            }

            return HDF_SUCCESS;
        }

        static int32_t ClockReadDrs(struct ClockDevice *clockDevice, const struct DeviceResourceNode *node)
        {
            int32_t ret;
            struct DeviceResourceIface *drsOps = NULL;

            drsOps = DeviceResourceGetIfaceInstance(HDF_CONFIG_SOURCE);
            if (drsOps == NULL || drsOps->GetUint32 == NULL || drsOps->GetString == NULL) {
                HDF_LOGE("ClockReadDrs: invalid drs ops!");
                return HDF_ERR_NOT_SUPPORT;
            }
            ret = drsOps->GetUint32(node, "deviceIndex", &clockDevice->deviceIndex, 0);
            if (ret != HDF_SUCCESS) {
                HDF_LOGE("ClockReadDrs: read deviceIndex fail, ret: %d!", ret);
                return ret;
            }

            drsOps->GetString(node, "clockName", &clockDevice->clockName, 0);

            ret = drsOps->GetString(node, "deviceName", &clockDevice->deviceName, 0);
            if (ret != HDF_SUCCESS) {
                HDF_LOGE("ClockReadDrs: read deviceName fail, ret: %d!", ret);
                return ret;
            }
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
        static void LinuxClockRelease(struct HdfDeviceObject *device)
        {
            const struct DeviceResourceNode *childNode = NULL;
            if (device == NULL || device->property == NULL) {
                HDF_LOGE("LinuxClockRelease: device or property is null!");
                return;
            }
            DEV_RES_NODE_FOR_EACH_CHILD_NODE(device->property, childNode) {
                ClockRemoveByNode(childNode);
            }
        }

        static void ClockRemoveByNode(const struct DeviceResourceNode *node)
        {
            int32_t ret;
            int32_t deviceIndex;
            struct ClockDevice *device = NULL;
            struct DeviceResourceIface *drsOps = NULL;

            drsOps = DeviceResourceGetIfaceInstance(HDF_CONFIG_SOURCE);
            if (drsOps == NULL || drsOps->GetUint32 == NULL) {
                HDF_LOGE("ClockRemoveByNode: invalid drs ops!");
                return;
            }

            ret = drsOps->GetUint32(node, "deviceIndex", (uint32_t *)&deviceIndex, 0);
            if (ret != HDF_SUCCESS) {
                HDF_LOGE("ClockRemoveByNode: read deviceIndex fail, ret: %d!", ret);
                return;
            }

            device = ClockDeviceGet(deviceIndex);
            if (device != NULL && device->priv == node) {
                ret = ClockStop(device);
                if (ret != HDF_SUCCESS) {
                    HDF_LOGE("ClockRemoveByNode: close fail, ret: %d!", ret);
                }
                if (device->parent  && device->parent->deviceName == NULL) {
                    ClockDeviceRemove(device->parent);
                    OsalMemFree(device->parent);
                }
                ClockDeviceRemove(device);
                OsalMemFree(device);
            }
        }
        ```

4. 驱动调试

    【可选】针对新增驱动程序，建议验证驱动基本功能，例如挂载后的测试用例是否成功等。
