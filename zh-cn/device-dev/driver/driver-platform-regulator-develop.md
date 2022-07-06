# Regulator


## 概述

### 功能简介

Regulator模块用于控制系统中某些设备的电压/电流供应。在嵌入式系统（尤其是手机）中，控制耗电量很重要，直接影响到电池的续航时间。所以，如果系统中某一个模块暂时不需要使用，就可以通过Regulator关闭其电源供应；或者降低提供给该模块的电压、电流大小。

### 运作机制

在HDF框架中，Regulator模块接口适配模式采用统一服务模式，这需要一个设备服务来作为Regulator模块的管理器，统一处理外部访问，这会在配置文件中有所体现。统一服务模式适合于同类型设备对象较多的情况，如Regulator可能同时具备十几个控制器，采用独立服务模式需要配置更多的设备节点，且服务会占据内存资源。

Regulator模块各分层的作用为：
- 接口层提供打开设备，写入数据，关闭设备接口的能力。
- 核心层主要提供绑定设备、初始化设备以及释放设备的能力。
- 适配层实现其他具体的功能。

![](../public_sys-resources/icon-note.gif) 说明：<br>核心层可以调用接口层的函数，也可以通过钩子函数调用适配层函数，从而使得适配层间接的可以调用接口层函数，但是不可逆转接口层调用适配层函数。

**图 1** 统一服务模式结构图

![image1](figures/统一服务模式结构图.png)



### 约束与限制

Regulator模块当前仅支持轻量和小型系统内核（LiteOS）。

## 开发指导

### 场景介绍

Regulator模块用于控制系统中某些设备的电压/电流供应。

### 接口说明

通过以下RegulatorMethod中的函数调用Regulator驱动对应的函数。

RegulatorMethod定义：

```
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

**表 1**  RegulatorMethod 结构体成员的回调函数功能说明


| 成员函数     | 入参                                                         | 返回值             | 功能             |
| ------------ | ----------------------------------------------------------- | ----------------- | ---------------- |
| open         | **node**：结构体指针，核心层Regulator节点                  | HDF_STATUS相关状态 | 打开设备         |
| close        | **node**：结构体指针，核心层Regulator节点                  | HDF_STATUS相关状态 | 关闭设备         |
| release      | **node**：结构体指针，核心层Regulator节点                  | HDF_STATUS相关状态 | 释放设备句柄     |
| enable       | **node**：结构体指针，核心层Regulator节点                  | HDF_STATUS相关状态 | 使能             |
| disable      | **node**：结构体指针，核心层Regulator节点                  | HDF_STATUS相关状态 | 禁用             |
| forceDisable | **node**：结构体指针，核心层Regulator节点                  | HDF_STATUS相关状态 | 强制禁用         |
| setVoltage   | **node**：结构体指针，核心层Regulator节点<br>**minUv**：uint32_t变量，最小电压<br>**maxUv**：uint32_t变量，最大电压 | HDF_STATUS相关状态 | 设置输出电压范围 |
| getVoltage   | **node**：结构体指针，核心层Regulator节点<br>**voltage**：uint32_t指针，传出电压值 | HDF_STATUS相关状态 | 获取电压         |
| setCurrent   | **node**：结构体指针，核心层Regulator节点<br>**minUa**：uint32_t变量，最小电流<br>**maxUa**：uint32_t变量，最大电流 | HDF_STATUS相关状态 | 设置输出电流范围 |
| getCurrent   | **node**：结构体指针，核心层Regulator节点<br>**regCurrent**：uint32_t指针，传出电流值 | HDF_STATUS相关状态 | 获取电流         |
| getStatus    | **node**：结构体指针，核心层Regulator节点<br>**status**：uint32_t指针，传出状态值 | HDF_STATUS相关状态 | 获取设备状态     |

### 开发步骤

Regulator模块适配包含以下四个步骤：

- 实例化驱动入口。
- 配置属性文件。
- 实例化核心层接口函数。
- 驱动调试。

1.  **实例化驱动入口：**

    驱动开发首先需要实例化驱动入口，驱动入口必须为HdfDriverEntry（在 hdf_device_desc.h 中定义）类型的全局变量，且moduleName要和device_info.hcs中保持一致。 HDF框架会汇总所有加载的驱动的HdfDriverEntry对象入口 ，形成一个类似数组的段地址空间，方便上层调用。
    
    一般在加载驱动时HDF会先调用Init函数加载该驱动。当Init调用异常时，HDF框架会调用Release释放驱动资源并退出。
    
    ```
    struct HdfDriverEntry g_regulatorDriverEntry = {
        .moduleVersion = 1,
        .moduleName = "virtual_regulator_driver",// 【必要且与HCS文件中里面的moduleName匹配】
        .Init = VirtualRegulatorInit,
        .Release = VirtualRegulatorRelease,
    };
    // 调用HDF_INIT将驱动入口注册到HDF框架中
    HDF_INIT(g_regulatorDriverEntry);
    ```
    
2. **配置属性文件：**

   - 在vendor/hisilicon/hispark_taurus/hdf_config/device_info/device_info.hcs文件中添加deviceNode描述。

     deviceNode信息与驱动入口注册相关，器件属性值与核心层RegulatorNode成员的默认值或限制范围有密切关系。

     由于采用了统一服务模式，device_info.hcs文件中第一个设备节点必须为Regulator管理器，其各项参数必须如下设置：

     | 成员名          | 值                                                           |
     | --------------- | ------------------------------------------------------------ |
     | policy          | 具体配置为0，不发布服务                                      |
     | priority        | 驱动启动优先级（0-200）。值越大优先级越低，优先级相同则不保证device的加载顺序 |
     | permission      | 驱动权限                                                     |
     | moduleName      | 固定为HDF_PLATFORM_REGULATOR_MANAGER                        |
     | serviceName     | 固定为HDF_PLATFORM_REGULATOR_MANAGER                         |
     | deviceMatchAttr | 没有使用，可忽略                                             |

     从第二个节点开始配置具体Regulator控制器信息，此节点并不表示某一路Regulator控制器，而是代表一个资源性质设备，用于描述一类Regulator控制器的信息。本例只有一个Regulator设备，如有多个设备，则需要在device_info文件增加deviceNode信息，以及在regulator\_config文件中增加对应的器件属性。

    - device_info.hcs 配置参考

       ```
       root {
       device_info { 
         platform :: host {
           hostName = "platform_host";
           priority = 50;
           device_regulator :: device {
               device0 :: deviceNode {	// 为每一个Regulator控制器配置一个HDF设备节点，存在多个时添加，否则不用
                   policy = 1;	        // 2：用户态可见；1：内核态可见；0：不需要发布服务
                   priority = 50;	    // 驱动启动优先级
                   permission = 0644;	// 驱动创建设备节点权限
                   /* 【必要】用于指定驱动名称，需要与期望的驱动Entry中的moduleName一致 */
                   moduleName = "HDF_PLATFORM_REGULATOR_MANAGER";		
                   serviceName = "HDF_PLATFORM_REGULATOR_MANAGER";		//【必要且唯一】驱动对外发布服务的名称
                   /* 【必要】用于配置控制器私有数据，要与regulator_config.hcs中对应控制器保持一致，具体的控制器信息在regulator_config.hcs中 */
                   deviceMatchAttr = "hdf_platform_regulator_manager";
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

    - regulator\_config.hcs配置参考

      ```
      root {
          platform {
              regulator_config {
              match_attr = "linux_regulator_adapter";
              template regulator_controller {    // 【必要】模板配置，继承该模板的节点如果使用模板中的默认值，则节点字段可以缺省
                  device_num = 1;
                  name = "";
                  devName = "regulator_adapter_consumer01";
                  supplyName = "";
                  mode = 1;
                  minUv = 0;
                  maxUv = 20000;
                  minUa = 0;
                  maxUa = 0;
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
              /* 每个Regulator控制器对应一个controller节点，如存在多个Regulator控制器，请依次添加对应的controller节点 */
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

3.  **实例化核心层接口函数：**
    
    - 完成驱动入口注册之后，最后一步就是对核心层RegulatorNode对象的初始化，包括厂商自定义结构体（传递参数和数据），实例化RegulatorNode成员RegulatorMethod（让用户可以通过接口来调用驱动底层函数），实现HdfDriverEntry成员函数（Bind，Init，Release）。
    
    - 自定义结构体参考。

        从驱动的角度看，RegulatorNode结构体是参数和数据的载体，HDF框架通过DeviceResourceIface将regulator\_config.hcs文件中的数值读入其中。
    
        ```
        // RegulatorNode是核心层控制器结构体，其中的成员在Init函数中会被赋值
        struct RegulatorNode {
            struct RegulatorDesc regulatorInfo;
            struct DListHead node;
            struct RegulatorMethod *ops;
            void *priv;
            struct OsalMutex lock;
        };
        
        struct RegulatorDesc {
            const char *name;                /* regulator名称 */
            const char *parentName;          /* regulator父节点名称 */
            struct RegulatorConstraints constraints;    /* regulator约束信息 */
            uint32_t minUv;                  /* 最小输出电压值 */
            uint32_t maxUv;                  /* 最大输出电压值 */
            uint32_t minUa;                  /* 最小输出电流值 */
            uint32_t maxUa;                  /* 最大输出电流值 */
            uint32_t status;                 /* regulator的状态，开或关 */
            int useCount;
            int consumerRegNums;             /* regulator用户数量 */
            RegulatorStatusChangecb cb;      /* 当regulator状态改变时，可通过此变量通知 */
        };
        
        struct RegulatorConstraints {
            uint8_t alwaysOn;     /* regulator是否常开 */
            uint8_t mode;         /* 模式：电压或者电流 */
            uint32_t minUv;       /* 最小可设置输出电压 */
            uint32_t maxUv;       /* 最大可设置输出电压 */
            uint32_t minUa;       /* 最小可设置输出电流 */
            uint32_t maxUa;       /* 最大可设置输出电流 */
        };
        ```
    
      
    
    - 实例化RegulatorNode成员RegulatorMethod，其他成员在Init函数中初始化。
    
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
      
    
    
    - Init函数参考
    
       入参：
    
       HdfDeviceObject 是整个驱动对外暴露的接口参数，具备hcs配置文件的信息。
        
       返回值：
        
       HDF\_STATUS相关状态（下表为部分展示，如需使用其他状态，可见//drivers/framework/include/utils/hdf\_base.h中HDF\_STATUS 定义）。
        
       **表 2**  HDF\_STATUS相关状态
    
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
           ret = VirtualRegulatorParseAndInit(device, childNode);// 【必要】实现见下
           ...
           }
           ...
       }
    
       static int32_t VirtualRegulatorParseAndInit(struct HdfDeviceObject *device, const struct DeviceResourceNode *node)
       {
           int32_t ret;
           struct RegulatorNode *regNode = NULL;
           (void)device;
    
           regNode = (struct RegulatorNode *)OsalMemCalloc(sizeof(*regNode));//加载HCS文件
           ...
           ret = VirtualRegulatorReadHcs(regNode, node);// 读取HCS文件信息
           ...
           regNode->priv = (void *)node;    // 实例化节点
           regNode->ops = &g_method;        // 实例化ops
    
           ret = RegulatorNodeAdd(regNode); // 挂载节点
           ...
       }
       ```
    
    -   Release 函数参考
        
         入参：
        
         HdfDeviceObject是整个驱动对外暴露的接口参数，其包含了hcs配置文件中的相关配置信息。
        
         返回值：
        
         无。
        
         函数说明:
        
         释放内存和删除控制器，该函数需要在驱动入口结构体中赋值给Release接口，当HDF框架调用Init函数初始化驱动失败时，可以调用Release释放驱动资源。
      
        ```c
        static void VirtualRegulatorRelease(struct HdfDeviceObject *device)
        {
            ...
            RegulatorNodeRemoveAll();// 【必要】调用核心层函数，释放RegulatorNode的设备和服务
        }
        ```
    
4. **驱动调试：**

   【可选】针对新增驱动程序，建议验证驱动基本功能，例如挂载后的测试用例是否成功等。

   
