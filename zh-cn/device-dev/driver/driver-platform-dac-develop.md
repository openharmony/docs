# DAC 

## 概述

### 功能简介

DAC（Digital to Analog Converter）是一种通过电流、电压或电荷的形式将数字信号转换为模拟信号的设备。

DAC模块支持数模转换的开发。它主要用于：

1. 作为过程控制计算机系统的输出通道，与执行器相连，实现对生产过程的自动控制。
2. 在利用反馈技术的魔术转换器设计中，作为重要的功能模块呈现。

### 基本概念

- 分辨率

  分辨率指的是D/A转换器能够转换的二进制位数，位数越多分辨率越高。

- 转换精度

  精度是指输入端加有最大数值时，DAC的实际输出值和理论计算值之差，DAC转换器的转换精度与DAC转换器的集成芯片结构和接口电路配置有关。理想情况下，DAC的转换精度越小越好，因此为了获得更高精度的DAC转换结果，首先要保证选择的DAC转换器具备足够高的分辨率。其次，要保证接口电路的器件或电源误差最小或者不存在误差，否则会造成DAC转换的误差，若这些误差超过一定程度，就会导致DAC转换错误。

- 转换速度

  转换速度一般由建立时间决定。从输入由全0突变为全1时开始，到输出电压稳定在FSR±½LSB范围（或以FSR±x%FSR指明范围）内为止，这段时间称为建立时间，它是DAC的最大响应时间，所以用它衡量转换速度的快慢。

  满量程范围FSR（ Full Scale Range ），是指DAC输出信号幅度的最大范围，不同的DAC有不同的满量程范围， 该范围可以用正、负电流或者正、负电压来限制 。

  最低有效位LSB（Least Significant Byte），指的是一个二进制数字中的第0位（即最低位）。

### 运作机制

在HDF框架中，同类型设备对象较多时（可能同时存在十几个同类型配置器），若采用独立服务模式，则需要配置更多的设备节点，且相关服务会占据更多的内存资源。相反，采用统一服务模式可以使用一个设备服务作为管理器，统一处理所有同类型对象的外部访问（这会在配置文件中有所体现）,实现便捷管理和节约资源的目的。DAC模块接口适配模式采用统一服务模式（如图1所示）。 

DAC模块各分层的作用为：接口层提供打开设备、写入数据和关闭设备接口的能力。核心层主要提供绑定设备、初始化设备以及释放设备的能力。适配层实现其他具体的功能。

![](../public_sys-resources/icon-note.gif) 说明：<br>核心层可以调用接口层的函数，也可以通过钩子函数调用适配层函数，从而使得适配层间接的可以调用接口层函数，但是不可逆转接口层调用适配层函数。

**图 1**  统一服务模式 

![](figures/统一服务模式结构图.png "DAC统一服务模式")

### 约束与限制

DAC模块当前仅支持轻量和小型系统内核（LiteOS）。

## 开发指导

### 场景介绍

DAC模块主要在设备中数模转换、音频输出和电机控制等设备使用，设置将DAC模块传入的数字信号转换为输出模拟信号时需要用到DAC数模转换驱动。

### 接口说明

通过以下DacMethod中的函数调用DAC驱动对应的函数。

DacMethod定义：

```c++
struct DacMethod {
    // 写入数据的钩子函数
    int32_t (*write)(struct DacDevice *device, uint32_t channel, uint32_t val);
    // 启动DAC设备的钩子函数
    int32_t (*start)(struct DacDevice *device);
    // 停止DAC设备的钩子函数
    int32_t (*stop)(struct DacDevice *device);
};
```

**表 1**  DacMethod结构体成员的回调函数功能说明

| 函数成员 | 入参                                                         | 出参 | 返回值             | 功能           |
| -------- | ------------------------------------------------------------ | ---- | ------------------ | -------------- |
| write    | device：结构体指针，核心层DAC控制器<br>channel：uint32_t，传入的通道号<br>val：uint32_t，要传入的数据 | 无   | HDF_STATUS相关状态 | 写入DA的目标值 |
| start    | device：结构体指针，核心层DAC控制器                        | 无   | HDF_STATUS相关状态 | 开启DAC设备    |
| stop     | device：结构体指针，核心层DAC控制器                        | 无   | HDF_STATUS相关状态 | 关闭DAC设备    |

### 开发步骤

DAC模块适配包含以下四个步骤：

1. 实例化驱动入口。
2. 配置属性文件。
3. 实例化核心层接口函数。
4. 驱动调试。

### 开发实例

下方将展示厂商需要提供哪些内容来完整实现设备功能。

1.  实例化驱动入口：

    驱动开发首先需要实例化驱动入口，驱动入口必须为HdfDriverEntry（在hdf_device_desc.h中定义）类型的全局变量，且moduleName要和device_info.hcs中保持一致。HDF框架会汇总所有加载的驱动的HdfDriverEntry对象入口，形成一个类似数组的段地址空间，方便上层调用。
    
    一般在加载驱动时HDF会先调用Init函数加载该驱动。当Init调用异常时，HDF框架会调用Release释放驱动资源并退出。
    
    ```c++
    static struct HdfDriverEntry g_dacDriverEntry = {
        .moduleVersion = 1,
        .Init = VirtualDacInit,
        .Release = VirtualDacRelease,
        .moduleName = "virtual_dac_driver", //【必要且与 HCS 里面的名字匹配】
        };
        HDF_INIT(g_dacDriverEntry); // 调用HDF_INIT将驱动入口注册到HDF框架中
    ```
    
2. 配置属性文件：

   - 在vendor/hisilicon/hispark_taurus/hdf_config/device_info/device_info.hcs文件中添加deviceNode描述。

     器件属性值对于厂商驱动的实现以及核心层DacDevice相关成员的默认值或限制范围有密切关系，比如设备通道的个数以及传输速率的最大值，会影响DacDevice相关成员的默认值。

     由于采用了统一服务模式，device_info.hcs文件中第一个设备节点必须为DAC管理器，其各项参数必须如下设置：

     | 成员名           | 值                                                                  |
     | --------------- | ------------------------------------------------------------------- |
     | policy          | 具体配置为0，不发布服务                                                |
     | priority        | 驱动启动优先级（0-200），值越大优先级越低，优先级相同则不保证device的加载顺序。|
     | permission      | 驱动权限                                                             |
     | moduleName      | 固定为HDF_PLATFORM_DAC_MANAGER                                       |
     | serviceName     | 固定为HDF_PLATFORM_DAC_MANAGER                                       |
     | deviceMatchAttr | 没有使用，可忽略                                                       |

     从第二个节点开始配置具体DAC控制器信息，此节点并不表示某一路DAC控制器，而是代表一个资源性质设备，用于描述一类DAC控制器的信息。本例只有一个DAC设备，如有多个设备，则需要在device_info文件增加deviceNode信息，以及在dac_config文件中增加对应的器件属性。

        device_info.hcs配置参考。

        ```hcs
        root {
            device_dac :: device {
                // device0是DAC管理器
                device0 :: deviceNode {
                    policy = 0;
                    priority = 52;
                    permission = 0644;
                    serviceName = "HDF_PLATFORM_DAC_MANAGER";
                    moduleName = "HDF_PLATFORM_DAC_MANAGER";
                }
            }
            // dac_virtual是DAC控制器
            dac_virtual :: deviceNode {
                policy = 0;
                priority = 56;
                permission = 0644;
                moduleName = "virtual_dac_driver";        //【必要】用于指定驱动名称，需要与期望的驱动Entry中的moduleName一致
                serviceName = "VIRTUAL_DAC_DRIVER";       //【必要】驱动对外发布服务的名称，必须唯一
                deviceMatchAttr = "virtual_dac";          //【必要】用于配置控制器私有数据，要与dac_config.hcs中对应控制器保持一致
                }                                          
        }
        ```

    - 添加dac_test_config.hcs器件属性文件 
    在vendor/vendor_hisilicon/hispark_taurus/hdf_config/hdf_test/xxx_test_config.hcs目录下新增文件用于驱动配置参数，（例如：vendor/vendor_hisilicon/hispark_taurus/hdf_config/hdf_test/dac_test_config.hcs）其中配置参数如下：

        ```hcs
        root {
            platform {
            dac_config {
                    match_attr = "virtual_dac"; //【必要】需要和device_info.hcs中的deviceMatchAttr值一致    
                    template dac_device {
                        deviceNum = 0; // 设备号     
                        validChannel = 0x1; // 有效通道1
                        rate = 20000; // 速率
                    }
                    device_0 :: dac_device {
                        deviceNum = 0; // 设备号
                        validChannel = 0x2; // 有效通道2
                    }
                }
            }
        }
        ```

3.  实例化核心层接口函数：
    
    - 初始化DacDevice成员。
    
        在VirtualDacParseAndInit函数中对DacDevice成员进行初始化操作。

        ```c++
        // 虚拟驱动自定义结构体
        struct VirtualDacDevice {
        // DAC设备结构体
            struct DacDevice device;
            // DAC设备号
            uint32_t deviceNum;
            // 有效通道
            uint32_t validChannel;
            // DAC速率
            uint32_t rate;
        };
        // 解析并且初始化核心层DacDevice对象
        static int32_t VirtualDacParseAndInit(struct HdfDeviceObject *device, const struct DeviceResourceNode *node)
        {
            // 定义返回值
            int32_t ret;
            // DAC设备虚拟指针
            struct VirtualDacDevice *virtual = NULL;
            (void)device;
            // 给virtual指针开辟空间
            virtual = (struct VirtualDacDevice *)OsalMemCalloc(sizeof(*virtual));
        if (virtual == NULL) {
            // 为空则返回错误参数
            HDF_LOGE("%s: Malloc virtual fail!", __func__);
            return HDF_ERR_MALLOC_FAIL;
        }
        // 读取属性文件配置参数
        ret = VirtualDacReadDrs(virtual, node);
        if (ret != HDF_SUCCESS) {
            // 读取失败
            HDF_LOGE("%s: Read drs fail! ret:%d", __func__, ret);
            // 释放virtual空间
            OsalMemFree(virtual);
            // 指针置为0
            virtual = NULL;
            return ret;
        }
        // 初始化虚拟指针
        VirtualDacDeviceInit(virtual);
        // 对DacDevice中priv对象初始化
        virtual->device.priv = (void *)node;
        // 对DacDevice中devNum对象初始化
        virtual->device.devNum = virtual->deviceNum;
        // 对DacDevice中ops对象初始化
        virtual->device.ops = &g_method;
        // 添加DAC设备
        ret = DacDeviceAdd(&virtual->device);
        if (ret != HDF_SUCCESS) {
            // 添加设备失败
            HDF_LOGE("%s: add Dac controller failed! ret = %d", __func__, ret);
            // 释放virtual空间
            OsalMemFree(virtual);
            // 虚拟指针置空
            virtual = NULL;
            return ret;
        }
        
        return HDF_SUCCESS;
       }
       ```
    
    - 自定义结构体参考。
    
      通过自定义结构体定义DAC数模转换必要的参数，在定义结构体时需要根据设备的功能参数来实现自定义结构体，从驱动的角度看，自定义结构体是参数和数据的载体，dac_config.hcs文件中传递的参数和数据会被HDF驱动模块的DacTestReadConfig函数读入，通过DeviceResourceIface来初始化结构体成员，其中一些重要数值也会传递给核心层DacDevice对象，例如设备号、总线号等。
    
      ```c++
      struct VirtualDacDevice {
          struct DacDevice device; //【必要】是核心层控制对象，具体描述见下面
          uint32_t deviceNum;      //【必要】设备号
          uint32_t validChannel;   //【必要】有效通道
          uint32_t rate;           //【必要】采样率
      };
      
      // DacDevice是核心层控制器结构体，其中的成员在Init函数中会被赋值
      struct DacDevice {
          const struct DacMethod *ops;
          OsalSpinlock spin; // 自旋锁
          uint32_t devNum; // 设备号
          uint32_t chanNum; // 设备通道号
          const struct DacLockMethod *lockOps;
          void *priv;
      };
      ```
    
    - 实例化DacDevice成员DacMethod。
    
        VirtualDacWrite、VirtualDacStop、VirtualDacStart函数会在dac_virtual.c文件中进行模块功能的实例化。
        
        ```c++
        static const struct DacMethod g_method = {
            .write = VirtualDacWrite, // DAC设备写入值
            .stop = VirtualDacStop, // 停止DAC设备
            .start = VirtualDacStart, // 开始启动DAC设备
        };
        ```
        
        ![](../public_sys-resources/icon-note.gif) **说明：**<br>
         DacDevice成员DacMethod的定义和成员说明见[接口说明](#接口说明)。
    
    - Init函数参考
    
        入参：
    
        HdfDeviceObject这个是整个驱动对外暴露的接口参数，具备hcs配置文件的信息。
    
        返回值：
    
        HDF_STATUS相关状态（下表为部分展示，如需使用其他状态，可见//drivers/framework/include/utils/hdf_base.h中HDF_STATUS定义）。
    
        | 状态(值)                | 问题描述       |
        | ---------------------- | ------------- |
        | HDF_ERR_INVALID_OBJECT | 控制器对象非法。 |
        | HDF_ERR_INVALID_PARAM  | 参数非法。      |
        | HDF_ERR_MALLOC_FAIL    | 内存分配失败。   |
        | HDF_ERR_IO             | I/O 错误。     |
        | HDF_SUCCESS            | 传输成功。      |
        | HDF_FAILURE            | 传输失败。      |
    
        函数说明：
    
      初始化自定义结构体对象，初始化DacDevice成员，并调用核心层DacDeviceAdd函数。
    
      ```c++
      static int32_t VirtualDacParseAndInit(struct HdfDeviceObject *device, const struct DeviceResourceNode *node)
      {
          // 定义返回值参数
          int32_t ret;
          // DAC设备的结构体指针
          struct VirtualDacDevice *virtual = NULL;
          (void)device;
          // 分配指定大小的内存
          virtual = (struct VirtualDacDevice *)OsalMemCalloc(sizeof(*virtual));
          if (virtual == NULL) {
              // 分配内存失败
              HDF_LOGE("%s: Malloc virtual fail!", __func__);
              return HDF_ERR_MALLOC_FAIL;
          }
          // 读取hcs中的node节点参数
          ret = VirtualDacReadDrs(virtual, node);
          if (ret != HDF_SUCCESS) {
              // 读取节点失败 
              HDF_LOGE("%s: Read drs fail! ret:%d", __func__, ret);
              goto __ERR__;
          }
          // 初始化DAC设备指针
          VirtualDacDeviceInit(virtual);
          // 节点数据传入私有数据
          virtual->device.priv = (void *)node;
          // 传入设备号
          virtual->device.devNum = virtual->deviceNum;
          // 传入方法
          virtual->device.ops = &g_method;
          // 添加DAC设备
          ret = DacDeviceAdd(&virtual->device);
          if (ret != HDF_SUCCESS) {
              // 添加DAC设备失败
              HDF_LOGE("%s: add Dac controller failed! ret = %d", __func__, ret);
              goto __ERR__;
          }
          // 成功添加DAC设备
          return HDF_SUCCESS;
      __ERR__:
          // 如果指针为空
          if (virtual != NULL) {
              // 释放内存
              OsalMemFree(virtual);
              // 指针置空
              virtual = NULL;
          }
      
          return ret;
      }
      
      static int32_t VirtualDacInit(struct HdfDeviceObject *device)
      {
          // 定义返回值参数
          int32_t ret;
          // 设备结构体子节点
          const struct DeviceResourceNode *childNode = NULL;
          // 入参指针进行判断
          if (device == NULL || device->property == NULL) {
              // 入参指针为空
              HDF_LOGE("%s: device or property is NULL", __func__);
              return HDF_ERR_INVALID_OBJECT;
          }
          // 入参指针不为空
          ret = HDF_SUCCESS;
          DEV_RES_NODE_FOR_EACH_CHILD_NODE(device->property, childNode) {
              // 解析子节点
              ret = VirtualDacParseAndInit(device, childNode);
              if (ret != HDF_SUCCESS) {
                  // 解析失败
                  break;
              }
          }
          // 解析成功
          return ret;
      }
      ```
    
    -   Release函数参考
        
          入参：
        
          HdfDeviceObject是整个驱动对外暴露的接口参数，具备hcs配置文件的信息。
        
          返回值：
        
          无。
        
          函数说明：
        
          释放内存和删除控制器，该函数需要在驱动入口结构体中赋值给Release接口，当HDF框架调用Init函数初始化驱动失败时，可以调用Release释放驱动资源。所有强制转换获取相应对象的操作前提是在Init函数中具备对应赋值的操作。
      
        ```c++
        static void VirtualDacRemoveByNode(const struct DeviceResourceNode *node)
        {
            // 定义返回值参数
            int32_t ret;
            // 定义DAC设备号
            int16_t devNum;
            // DAC设备结构体指针
            struct DacDevice *device = NULL;
            // DAC虚拟结构体指针
            struct VirtualDacDevice *virtual = NULL;
            // 设备资源接口结构体指针
            struct DeviceResourceIface *drsOps = NULL;
            // 通过实例入口获取设备资源
            drsOps = DeviceResourceGetIfaceInstance(HDF_CONFIG_SOURCE);
            // 入参指判空
            if (drsOps == NULL || drsOps->GetUint32 == NULL) {
                // 指针为空
                HDF_LOGE("%s: invalid drs ops fail!", __func__);
                return;
        }
        // 获取devNum节点的数据
        ret = drsOps->GetUint16(node, "devNum", (uint16_t *)&devNum, 0);
        if (ret != HDF_SUCCESS) {
            //获取失败
            HDF_LOGE("%s: read devNum fail!", __func__);
            return;
        }
        // 获取DAC设备号
        device = DacDeviceGet(devNum);
        // 判断DAC设备号以及数据是否为空
        if (device != NULL && device->priv == node) {
            // 为空释放DAC设备号
            DacDevicePut(device);
            // 移除DAC设备号
            DacDeviceRemove(device);
            virtual = (struct VirtualDacDevice *)device;
            // 释放虚拟指针
            OsalMemFree(virtual);
            }
            return;
        }
    
        static void VirtualDacRelease(struct HdfDeviceObject *device)
        {
            // 定义设备资源子节点结构体指针
            const struct DeviceResourceNode *childNode = NULL;
            // 入参指针判空
            if (device == NULL || device->property == NULL) {
            // 入参指针为空
            HDF_LOGE("%s: device or property is NULL", __func__);
            return;
            }
            
            DEV_RES_NODE_FOR_EACH_CHILD_NODE(device->property, childNode) {
                // 通过节点移除DAC
                VirtualDacRemoveByNode(childNode);
                }
        }
        ```

4. 驱动调试：

   【可选】针对新增驱动程序，建议验证驱动基本功能，例如挂载后的测试用例是否成功等。