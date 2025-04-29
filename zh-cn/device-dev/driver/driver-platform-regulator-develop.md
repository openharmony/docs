# Regulator

## 概述

### 功能简介

Regulator模块用于控制系统中各类设备的电压/电流供应。在嵌入式系统（尤其是手机）中，控制耗电量很重要，直接影响到电池的续航时间。所以，如果系统中某一个模块暂时不需要使用，就可以通过Regulator关闭其电源供应；或者降低提供给该模块的电压、电流大小。

### 运作机制

在HDF框架中，Regulator模块接口适配模式采用统一服务模式（如图1所示），这需要一个设备服务来作为Regulator模块的管理器，统一处理外部访问，这会在配置文件中有所体现。统一服务模式适合于同类型设备对象较多的情况，如Regulator可能同时具备十几个控制器，采用独立服务模式需要配置更多的设备节点，且服务会占据内存资源。

Regulator模块各分层的作用为：

- 接口层：提供打开设备，操作Regulator，关闭设备的能力。

- 核心层：主要负责服务绑定、初始化以及释放管理器，并提供添加、删除以及获取Regulator设备的能力。

- 适配层：由驱动适配者实现与硬件相关的具体功能，如设备的初始化等。

在统一模式下，所有的控制器都被核心层统一管理，并由核心层统一发布一个服务供接口层，因此这种模式下驱动无需再为每个控制器发布服务。

**图 1** Regulator统一服务模式结构图<a name="fig1"></a>  

![Regulator统一服务模式结构图](figures/统一服务模式结构图.png)

### 约束与限制

Regulator模块当前仅支持小型系统。

## 开发指导

### 场景介绍

Regulator模块用于控制系统中某些设备的电压/电流供应。当驱动开发者需要将Regulator设备适配到OpenHarmony时，需要进行Regulator驱动适配，下文将介绍如何进行Regulator驱动适配。

### 接口说明

为了保证上层在调用Regulator接口时能够正确的操作硬件，核心层在//drivers/hdf_core/framework/support/platform/include/regulator/regulator_core.h中定义了以下钩子函数。驱动适配者需要在适配层实现这些函数的具体功能，并与这些钩子函数挂接，从而完成接口层与核心层的交互。

RegulatorMethod定义：

```c
struct RegulatorMethod {
    int32_t (*open)(struct RegulatorNode *node);
    int32_t (*close)(struct RegulatorNode *node);
    int32_t (*release)(struct RegulatorNode *node);
    int32_t (*enable)(struct RegulatorNode *node);
    int32_t (*disable)(struct RegulatorNode *node);
    int32_t (*forceDisable)(struct RegulatorNode *node);
    int32_t (*setVoltage)(struct RegulatorNode *node, uint32_t minUv, uint32_t maxUv);
    int32_t (*getVoltage)(struct RegulatorNode *node, uint32_t *voltage);
    int32_t (*setCurrent)(struct RegulatorNode *node, uint32_t minUa, uint32_t maxUa);
    int32_t (*getCurrent)(struct RegulatorNode *node, uint32_t *regCurrent);
    int32_t (*getStatus)(struct RegulatorNode *node, uint32_t *status);
};
```

**表 1**  RegulatorMethod 结构体成员的钩子函数功能说明

| 成员函数 | 入参 | 返回值 | 功能 |
| ------------ | ----------------------------------------------------------- | ----------------- | ---------------- |
| open | node：结构体指针，核心层Regulator节点 | HDF_STATUS相关状态 | 打开设备 |
| close | node：结构体指针，核心层Regulator节点 | HDF_STATUS相关状态 | 关闭设备 |
| release | node：结构体指针，核心层Regulator节点 | HDF_STATUS相关状态 | 释放设备句柄 |
| enable | node：结构体指针，核心层Regulator节点 | HDF_STATUS相关状态 | 使能 |
| disable | node：结构体指针，核心层Regulator节点 | HDF_STATUS相关状态 | 禁用 |
| forceDisable | node：结构体指针，核心层Regulator节点 | HDF_STATUS相关状态 | 强制禁用 |
| setVoltage | node：结构体指针，核心层Regulator节点<br>minUv：uint32_t类型，最小电压<br>maxUv：uint32_t类型，最大电压 | HDF_STATUS相关状态 | 设置输出电压范围 |
| getVoltage | node：结构体指针，核心层Regulator节点<br>voltage：uint32_t类型指针，传出电压值 | HDF_STATUS相关状态 | 获取电压 |
| setCurrent | node：结构体指针，核心层Regulator节点<br>minUa：uint32_t类型，最小电流<br>maxUa：uint32_t类型，最大电流 | HDF_STATUS相关状态 | 设置输出电流范围 |
| getCurrent | node：结构体指针，核心层Regulator节点<br>regCurrent：uint32_t类型指针，传出电流值 | HDF_STATUS相关状态 | 获取电流 |
| getStatus | node：结构体指针，核心层Regulator节点<br>status：uint32_t类型指针，传出状态值 | HDF_STATUS相关状态 | 获取设备状态 |

### 开发步骤

Regulator模块适配包含以下四个步骤：

- 实例化驱动入口

- 配置属性文件

- 实例化核心层接口函数

- 驱动调试

1.  实例化驱动入口

    驱动开发首先需要实例化驱动入口，驱动入口必须为HdfDriverEntry（在hdf_device_desc.h中定义）类型的全局变量，且moduleName要和device_info.hcs中保持一致。 

    HDF框架会汇总所有加载的驱动的HdfDriverEntry对象入口，形成一个类似数组的段地址空间，方便上层调用。

    一般在加载驱动时HDF会先调用Init函数加载该驱动。当Init调用异常时，HDF框架会调用Release释放驱动资源并退出。

    ```c
    struct HdfDriverEntry g_regulatorDriverEntry = {
        .moduleVersion = 1,
        .moduleName = "virtual_regulator_driver",       // 【必要且与HCS文件中里面的moduleName匹配】
        .Init = VirtualRegulatorInit,                   // 见Init参考
        .Release = VirtualRegulatorRelease,             // 见Release参考
    };
    HDF_INIT(g_regulatorDriverEntry);                   // 调用HDF_INIT将驱动入口注册到HDF框架中
    ```

2. 配置属性文件

    以Hi3516DV300开发板为例，在//vendor/hisilicon/hispark_taurus/hdf_config/device_info/device_info.hcs文件中添加deviceNode描述。

    deviceNode信息与驱动入口注册相关，器件属性值与核心层RegulatorNode成员的默认值或限制范围有密切关系。

    由于采用了统一服务模式，device_info.hcs文件中第一个设备节点必须为Regulator管理器，其各项参数必须如如表2所示：

    **表 2** device_info.hcs节点参数说明

    | 成员名 | 值 |
    | --------------- | ------------------------------------------------------------ |
    | policy | 驱动服务发布的策略，Regulator管理器具体配置为1，表示驱动对内核态发布服务 |
    | priority | 驱动启动优先级（0-200）。值越大优先级越低，优先级相同则不保证device的加载顺序，regulator管理器具体配置为50 |
    | permission | 驱动创建设备节点权限，Regulator管理器具体配置为0664 |
    | moduleName | 驱动名称，Regulator管理器固定为HDF_PLATFORM_REGULATOR_MANAGER |
    | serviceName | 驱动对外发布服务的名称，Regulator管理器固定为HDF_PLATFORM_REGULATOR_MANAGER |
    | deviceMatchAttr | 驱动私有数据匹配的关键字，Regulator管理器设置为hdf_platform_regulator_manager |

    从第二个节点开始配置具体Regulator控制器信息，此节点并不表示某一路Regulator控制器，而是代表一个资源性质设备，用于描述一类Regulator控制器的信息。本例只有一个Regulator设备，如有多个设备，则需要在device_info.hcs文件增加deviceNode信息，以及在regulator_config_linux.hcs文件中增加对应的器件属性。

    - device_info.hcs 配置参考

        ```c
        root {
            device_info {
                platform :: host {
                    hostName = "platform_host";
                    priority = 50;
                    device_regulator :: device {
                        device0 :: deviceNode {	                                 // 为每一个Regulator控制器配置一个HDF设备节点，存在多个时添加，否则不用。
                            policy = 1;	                                         // 2：用户态、内核态均可见；1：内核态可见；0：不需要发布服务。
                            priority = 50;	                                     // 驱动启动优先级
                            permission = 0644;	                                 // 驱动创建设备节点权限
                            moduleName = "HDF_PLATFORM_REGULATOR_MANAGER";                                                //【必要】用于指定驱动名称，需要与期望的驱动Entry中的moduleName一致。
                            serviceName = "HDF_PLATFORM_REGULATOR_MANAGER";		 // 【必要且唯一】驱动对外发布服务的名称
                            deviceMatchAttr = "hdf_platform_regulator_manager";  // 【必要】用于配置控制器私有数据，要与regulator_config.hcs中对应控制器保持一致，具体的控制器信息在regulator_config.hcs中。
                        }
                        device1 :: deviceNode {
                            policy = 0;
                            priority = 55;
                            permission = 0644;
                            moduleName = "linux_regulator_adapter";
                            deviceMatchAttr = "linux_regulator_adapter";
                        }
                    }
                }
            }
        }
        ```

    - regulator_config_linux.hcs配置参考

        ```c
        root {
            platform {
                regulator_config {
                match_attr = "linux_regulator_adapter";
                template regulator_controller {   // 【必要】模板配置，继承该模板的节点如果使用模板中的默认值，则节点字段可以缺省。
                    device_num = 1;
                    name = "";
                    devName = "regulator_adapter_consumer01";
                    supplyName = "";
                    mode = 1;
                    minUv = 0;                    // 最小电压
                    maxUv = 20000;                // 最大电压
                    minUa = 0;                    // 最小电流
                    maxUa = 0;                    // 最大电流
                    }
                controller_0x130d0000 :: regulator_controller {
                    device_num = 1;
                    name = "regulator_adapter_1";
                    devName = "regulator_adapter_consumer01";
                    supplyName = "virtual-regulator-hdf-adapter";
                    mode = 1;
                    minUv = 1000;
                    maxUv = 50000;
                    minUa = 0;
                    maxUa = 0;
                    }
                // 每个Regulator控制器对应一个controller节点，如存在多个Regulator控制器，请依次添加对应的controller节点。
                controller_0x130d0001 :: regulator_controller {
                    device_num = 1;
                    name = "regulator_adapter_2";
                    devName = "regulator_adapter_consumer01";
                    supplyName = "virtual2-regulator-hdf-adapter";
                    mode = 2;
                    minUv = 0;
                    maxUv = 0;
                    minUa = 1000;
                    maxUa = 50000;
                    }
                }
            }
        }
        ```

        需要注意的是，新增regulator_config.hcs配置文件后，必须在hdf.hcs文件中将其包含，否则配置文件无法生效。

        例如：本例中regulator_config.hcs所在路径为//vendor/hisilicon/hispark_taurus_linux/hdf_config/device/regulator/regulator_config_linux.hcs，则必须在产品对应的hdf.hcs中添加如下语句：

        ```c
        #include "device/regulator/regulator_config_linux.hcs"
        ```

3. 实例化核心层接口函数
    
    完成驱动入口注册之后，下一步就是对核心层RegulatorNode对象的初始化，包括驱动适配者自定义结构体（传递参数和数据），实例化RegulatorNode成员RegulatorMethod（让用户可以通过接口来调用驱动底层函数），实现HdfDriverEntry成员函数（Bind、Init、Release）。
    
    - 自定义结构体参考。

        从驱动的角度看，RegulatorNode结构体是参数和数据的载体，HDF框架通过DeviceResourceIface将regulator_config.hcs文件中的数值读入其中。
    
        ```c
        // RegulatorNode是核心层控制器结构体，其中的成员在Init函数中会被赋值。
        struct RegulatorNode {
            struct RegulatorDesc regulatorInfo;
            struct DListHead node;
            struct RegulatorMethod *ops;
            void *priv;
            struct OsalMutex lock;
        };
        
        struct RegulatorDesc {
            const char *name;                           // regulator名称
            const char *parentName;                     // regulator父节点名称
            struct RegulatorConstraints constraints;    // regulator约束信息
            uint32_t minUv;                             // 最小输出电压值
            uint32_t maxUv;                             // 最大输出电压值
            uint32_t minUa;                             // 最小输出电流值
            uint32_t maxUa;                             // 最大输出电流值
            uint32_t status;                            // regulator的状态，开或关。
            int useCount;
            int consumerRegNums;                        // regulator用户数量
            RegulatorStatusChangecb cb;                 // 当regulator状态改变时，可通过此变量通知。
        };
        
        struct RegulatorConstraints {
            uint8_t alwaysOn;     // regulator是否常开
            uint8_t mode;         // 模式：电压或者电流
            uint32_t minUv;       // 最小可设置输出电压
            uint32_t maxUv;       // 最大可设置输出电压
            uint32_t minUa;       // 最小可设置输出电流
            uint32_t maxUa;       // 最大可设置输出电流
        };
        ```

    - 实例化RegulatorNode成员RegulatorMethod。
    
        ```c
        // regulator_virtual.c中的示例：钩子函数的填充
        static struct RegulatorMethod g_method = {
            .enable = VirtualRegulatorEnable,
            .disable = VirtualRegulatorDisable,
            .setVoltage = VirtualRegulatorSetVoltage,
            .getVoltage = VirtualRegulatorGetVoltage,
            .setCurrent = VirtualRegulatorSetCurrent,
            .getCurrent = VirtualRegulatorGetCurrent,
            .getStatus = VirtualRegulatorGetStatus,
        };
        ```

    - Init函数开发参考。
    
        入参：
    
        HdfDeviceObject是整个驱动对外提供的接口参数，具备HCS配置文件的信息。
        
        返回值：
        
        HDF_STATUS相关状态（表4为部分展示，如需使用其他状态，可参考//drivers/hdf_core/interfaces/inner_api/utils/hdf_base.h中HDF_STATUS定义）。
        
        **表 3** HDF_STATUS相关状态说明
  
        | 状态(值)               | 描述          |
        | ---------------------- | -------------- |
        | HDF_ERR_INVALID_OBJECT | 控制器对象非法 |
        | HDF_ERR_MALLOC_FAIL    | 内存分配失败   |
        | HDF_ERR_INVALID_PARAM  | 参数非法       |
        | HDF_ERR_IO             | I/O 错误       |
        | HDF_SUCCESS            | 初始化成功     |
        | HDF_FAILURE            | 初始化失败     |
    
        函数说明：
    
        初始化自定义结构体和RegulatorNode成员，并通过调用核心层RegulatorNodeAdd函数挂载Regulator控制器。

        ```c
        static int32_t VirtualRegulatorInit(struct HdfDeviceObject *device)
        {
            int32_t ret;
            const struct DeviceResourceNode *childNode = NULL;
            ...
            DEV_RES_NODE_FOR_EACH_CHILD_NODE(device->property, childNode) {
                ret = VirtualRegulatorParseAndInit(device, childNode);         // 【必要】实现见下
            ......
            }
            ......
        }
        
        static int32_t VirtualRegulatorParseAndInit(struct HdfDeviceObject *device, const struct DeviceResourceNode *node)
        {
            int32_t ret;
            struct RegulatorNode *regNode = NULL;
            (void)device;
        
            regNode = (struct RegulatorNode *)OsalMemCalloc(sizeof(*regNode)); //加载HCS文件
            ......
            ret = VirtualRegulatorReadHcs(regNode, node);                      // 读取HCS文件信息
            ......
            regNode->priv = (void *)node;                                      // 实例化节点
            regNode->ops = &g_method;                                          // 实例化ops
        
            ret = RegulatorNodeAdd(regNode);                                   // 挂载节点
            ......
        }
        ```

    - Release函数开发参考。
        
        入参：
        
        HdfDeviceObject是整个驱动对外提供的接口参数，其包含了HCS配置文件中的相关配置信息。
        
        返回值：
        
        无。
        
        函数说明:
        
        释放内存和删除控制器，该函数需要在驱动入口结构体中赋值给Release接口，当HDF框架调用Init函数初始化驱动失败时，可以调用Release释放驱动资源。
      
        ```c
        static void VirtualRegulatorRelease(struct HdfDeviceObject *device)
        {
            ......
            RegulatorNodeRemoveAll(); // 【必要】调用核心层函数，释放RegulatorNode的设备和服务
        }
        ```

4. 驱动调试

   【可选】针对新增驱动程序，建议验证驱动基本功能，例如挂载后的测试用例是否成功等。
