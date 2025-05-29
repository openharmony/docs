# PWM

## 概述

### 功能简介

PWM（Pulse Width Modulation）即脉冲宽度调制，是一种对模拟信号电平进行数字编码并将其转换为脉冲的技术，广泛应用在从测量、通信到功率控制与变换的许多领域中。通常情况下，在使用马达控制、背光亮度调节时会用到PWM模块。

### 基本概念

脉冲是“电脉冲”的简称，指电路中电流或电压短暂起伏的现象，其特点是突变和不连续性。脉冲的种类很多，常见的脉冲波形有：三角脉冲、尖脉冲、矩形脉冲、方形脉冲、梯形脉冲及阶梯脉冲等。脉冲的主要参数包括重复周期T（T=1/F，F为重复频率）、脉冲幅度U、脉冲前沿上升时间ts、后沿下降时间t、脉冲宽度tk等。

### 运作机制

在HDF框架中，PWM接口适配模式采用独立服务模式（如图1所示）。在这种模式下，每一个设备对象会独立发布一个设备服务来处理外部访问，设备管理器收到API的访问请求之后，通过提取该请求的参数，达到调用实际设备对象的相应内部方法的目的。独立服务模式可以直接借助HDF设备管理器的服务管理能力，但需要为每个设备单独配置设备节点，增加内存占用。

独立服务模式下，核心层不会统一发布一个服务供上层使用，因此这种模式下驱动要为每个控制器发布一个服务，具体表现为：

- 驱动适配者需要实现HdfDriverEntry的Bind钩子函数以绑定服务。

- device_info.hcs文件中deviceNode的policy字段为1或2，不能为0。

PWM模块各分层作用：

- 接口层提供打开PWM设备、设置PWM设备周期、设置PWM设备占空时间、设置PWM设备极性、设置PWM设备参数、获取PWM设备参数、使能PWM设备、禁止PWM设备、关闭PWM设备的接口。

- 核心层主要提供PWM控制器的添加、移除以及管理的能力，通过钩子函数与适配层交互。

- 适配层主要是将钩子函数的功能实例化，实现具体的功能。

**图 1** PWM独立服务模式结构图

![PWM独立服务模式结构图](figures/独立服务模式结构图.png)

## 开发指导

### 场景介绍

PWM用于脉冲宽度调制，当驱动开发者需要将PWM设备适配到OpenHarmony时，需要进行PWM驱动适配。下文将介绍如何进行PWM驱动适配。

### 接口说明

为了保证上层在调用PWM接口时能够正确的操作PWM控制器，核心层在//drivers/hdf_core/framework/support/platform/include/pwm/pwm_core.h中定义了以下钩子函数，驱动适配者需要在适配层实现这些函数的具体功能，并与钩子函数挂接，从而完成适配层与核心层的交互。

PwmMethod定义：

```c
struct PwmMethod {
    int32_t (*setConfig)(struct PwmDev *pwm, struct PwmConfig *config);
    int32_t (*open)(struct PwmDev *pwm);
    int32_t (*close)(struct PwmDev *pwm);
};
```

**表 1** PwmMethod结构体成员的钩子函数功能说明

| 成员函数 | 入参 | 返回值 | 功能 | 
| -------- | -------- | -------- | -------- |
| setConfig | pwm：结构体指针，核心层PWM控制器<br/>config：结构体指针，传入设置得设备属性 | HDF_STATUS相关状态 | 配置属性 | 
| open | pwm：结构体指针，核心层PWM控制器 | HDF_STATUS相关状态 | 打开PWM设备 | 
| close | pwm：结构体指针，核心层PWM控制器 | HDF_STATUS相关状态 | 关闭PWM设备 | 

### 开发步骤

PWM模块适配包含以下四个步骤：

- 驱实例化驱动入口

- 配置属性文件

- 实例化PWM控制器对象

- 驱动调试

### 开发实例

下方将基于Hi3516DV300开发板以//device/soc/hisilicon/common/platform/pwm/pwm_hi35xx.c驱动为示例，展示需要驱动适配者提供哪些内容来完整实现设备功能。

1. 驱实例化驱动入口

    驱动入口必须为HdfDriverEntry（在hdf_device_desc.h中定义）类型的全局变量，且moduleName要和device_info.hcs中保持一致。HDF框架会将所有加载的驱动的HdfDriverEntry对象首地址汇总，形成一个类似数组的段地址空间，方便上层调用。

    一般在加载驱动时HDF会先调用Bind函数，再调用Init函数加载该驱动。当Init调用异常时，HDF框架会调用Release释放驱动资源并退出。

    PWM驱动入口开发参考：

    ```c
    struct HdfDriverEntry g_hdfPwm = {
        .moduleVersion = 1,
        .moduleName = "HDF_PLATFORM_PWM",    // 【必要且与HCS文件中里面的moduleName匹配】
        .Bind = HdfPwmBind,                  // 挂接PWM模块Bind实例化
        .Init = HdfPwmInit,                  // 挂接PWM模块Init实例化
        .Release = HdfPwmRelease,            // 挂接PWM模块Release实例化
    };
    HDF_INIT(g_hdfPwm);                      // 调用HDF_INIT将驱动入口注册到HDF框架中
    ```

2. 配置属性文件

    完成驱动入口注册之后，需要在device_info.hcs文件中添加deviceNode信息，deviceNode信息与驱动入口注册相关。本例以两个PWM控制器为例，如有多个器件信息，则需要在device_info.hcs文件增加对应的deviceNode信息，以及在pwm_config.hcs文件中增加对应的器件属性。器件属性值与核心层PwmDev成员的默认值或限制范围有密切关系，比如PWM设备号，需要在pwm_config.hcs文件中增加对应的器件属性。

    独立服务模式的特点是device_info.hcs文件中设备节点代表着一个设备对象，如果存在多个设备对象，则按需添加，注意服务名与驱动私有数据匹配的关键字名称必须唯一。其中各项参数如表2所示：

    **表 2** device_info.hcs节点参数说明

    | 成员名 | 值 |
    | -------- | -------- |
    | policy | 驱动服务发布的策略，PWM控制器具体配置为2，表示驱动对内核态和用户态都发布服务 |
    | priority | 驱动启动优先级（0-200），值越大优先级越低。PWM控制器具体配置为80 |
    | permission | 驱动创建设备节点权限，PWM控制器具体配置为0664 |
    | moduleName | 驱动名称，PWM控制器固定为HDF_PLATFORM_PWM |
    | serviceName | 驱动对外发布服务的名称，PWM控制器服务名设置为HDF_PLATFORM_PWM_X，X代表PWM控制器编号 |
    | deviceMatchAttr | 驱动私有数据匹配的关键字，PWM控制器设置为hisilicon_hi35xx_pwm_X，X代表PWM控制器编号 |


    - device_info.hcs 配置参考：

        在//vendor/hisilicon/hispark_taurus/hdf_config/device_info/device_info.hcs文件中添加deviceNode描述。

        ```c
        root {
            device_info { 
                platform :: host {
                    hostName = "platform_host";
                    priority = 50;
                    device_pwm :: device {                                 // 为每一个PWM控制器配置一个HDF设备节点
                        device0 :: deviceNode {
                            policy = 2;                                    // policy字段是驱动服务发布的策略,如果需要面向用户态，则为2
                            priority = 80;                                 // 驱动启动优先级
                            permission = 0644;                             // 驱动创建设备节点权限
                            moduleName = "HDF_PLATFORM_PWM";               // 【必要】用于指定驱动名称，需要与期望的驱动Entry中的moduleName一致
                            serviceName = "HDF_PLATFORM_PWM_0";            // 【必要且唯一】驱动对外发布服务的名称
                            deviceMatchAttr = "hisilicon_hi35xx_pwm_0";    // 【必要】用于配置控制器私有数据，要与pwm_config.hcs中对应控制器保持一致，具体的控制器信息在pwm_config.hcs中
                        }
                        device1 :: deviceNode {
                            policy = 2;
                            priority = 80;
                            permission = 0644;
                            moduleName = "HDF_PLATFORM_PWM";
                            serviceName = "HDF_PLATFORM_PWM_1";
                            deviceMatchAttr = "hisilicon_hi35xx_pwm_1";
                        }
                    ......                                                 // 如果存在多个PWM设备时【必须】添加节点，否则不用
                    }
                }
            }
        }
        ```

    - pwm_config.hcs 配置参考：

        在//device/soc/hisilicon/hi3516dv300/sdk_liteos/hdf_config/pwm/pwm_config.hcs文件配置器件属性，其中配置参数如下：

        ```c
        root {
            platform {
                pwm_config {
                    template pwm_device {                       // 【必要】配置模板，如果下面节点使用时继承该模板，则节点中未声明的字段会使用该模板中的默认值
                        serviceName = "";
                        match_attr = "";
                        num = 0;                                // 【必要】设备号
                        base = 0x12070000;                      // 【必要】地址映射需要
                    }
                    device_0x12070000 :: pwm_device {           // 存在多个设备时，请逐一添加相关HDF节点和设备节点信息。
                        match_attr = "hisilicon_hi35xx_pwm_0";  // 【必要】需要和device_info.hcs中的deviceMatchAttr值一致
                    }
                    device_0x12070020 :: pwm_device {
                        match_attr = "hisilicon_hi35xx_pwm_1";
                        num = 1;
                        base = 0x12070020;                      // 【必要】地址映射需要
                    }
                    ......                                      // 如果存在多个PWM设备时【必须】添加节点，否则不用
                }
            }
        }
        ```

        需要注意的是，新增pwm_config.hcs配置文件后，必须在产品对应的hdf.hcs文件中将其包含如下语句所示，否则配置文件无法生效。

        ```c
        #include "../../../../device/soc/hisilicon/hi3516dv300/sdk_liteos/hdf_config/pwm/pwm_config.hcs" // 配置文件相对路径
        ```

3. 实例化PWM控制器对象

    完成驱动入口注册之后，下一步就是以核心层PwmDev对象的初始化为核心，包括驱动适配者自定义结构体（传递参数和数据），实例化PwmDev成员PwmMethod（让用户可以通过接口来调用驱动底层函数），实现HdfDriverEntry成员函数（Bind、Init、Release）。

    - 驱动适配者自定义结构体参考。

        从驱动的角度看，驱动适配者自定义结构体是参数和数据的载体，而且pwm_config.hcs文件中的数值会被HDF读入并通过DeviceResourceIface来初始化结构体成员，一些重要数值也会传递给核心层对象，例如PWM设备号。

        ```c
        struct HiPwm {
            struct PwmDev dev;                // 【必要】 核是核心层控制对象
            volatile unsigned char *base;     // 【必要】地址映射需要，寄存器基地址
            struct HiPwmRegs *reg;            // 设备属性结构体，可自定义。
            bool supportPolarity;             // 是否支持极性
        };

        struct PwmDev {                       // PwmDev是核心层控制器结构体，其中的成员在Init函数中会被赋值。
            struct IDeviceIoService service;  // 驱动服务
            struct HdfDeviceObject *device;   // 驱动设备对象
            struct PwmConfig cfg;             // 设备属性结构体，相关定义见下。
            struct PwmMethod *method;         // 钩子函数
            bool busy;                        // 是否繁忙
            uint32_t num;                     // 设备号
            OsalSpinlock lock;                // 自旋锁
            void *priv;                       // 私有数据
        };

        struct PwmConfig {                    // PWM设备属性
            uint32_t duty;                    // 占空时间 nanoseconds
            uint32_t period;                  // pwm 周期 nanoseconds
            uint32_t number;                  // pwm 连续个数
            uint8_t polarity;                 // Polarity
                                              // ------------------- | --------------
                                              // PWM_NORMAL_POLARITY | Normal polarity
                                              // PWM_INVERTED_POLARITY | Inverted polarity
                                              //
            uint8_t status;                   // 运行状态
                                              // ------------------ | -----------------
                                              // PWM_DISABLE_STATUS | Disabled
                                              // PWM_ENABLE_STATUS  | Enabled
        };
        ```

    - PwmDev成员钩子函数结构体PwmMethod的实例化，其他成员在Init函数中初始化。
 
        ```c
        struct PwmMethod g_pwmOps = {         // pwm_hi35xx.c中的示例：钩子函数实例化
            .setConfig = HiPwmSetConfig,      // 配置属性
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

        初始化自定义结构体对象，初始化PwmDev成员，调用核心层PwmDeviceAdd函数，完成PWM控制器的添加。

        ```c
        // 此处Bind函数为空函数，可与Init函数结合，也可根据驱动适配者需要实现相关操作。
        static int32_t HdfPwmBind(struct HdfDeviceObject *obj)
        {
            (void)obj;
            return HDF_SUCCESS;
        }

        static int32_t HdfPwmInit(struct HdfDeviceObject *obj)
        {
            int ret;
            struct HiPwm *hp = NULL;
            ......
            hp = (struct HiPwm *)OsalMemCalloc(sizeof(*hp));
            ......
            ret = HiPwmProbe(hp, obj);                                 // 【必要】实现见下
            ......
            return ret;

        static int32_t HiPwmProbe(struct HiPwm *hp, struct HdfDeviceObject *obj)
        {
            uint32_t tmp;
            struct DeviceResourceIface *iface = NULL;

            iface = DeviceResourceGetIfaceInstance(HDF_CONFIG_SOURCE); // 初始化自定义结构体HiPwm
            ......
            
            hp->reg = (struct HiPwmRegs *)hp->base;                    // 初始化自定义结构体HiPwm
            hp->supportPolarity = false;                               // 初始化自定义结构体HiPwm
            hp->dev.method = &g_pwmOps;                                // PwmMethod的实例化对象的挂载
            hp->dev.cfg.duty = PWM_DEFAULT_DUTY_CYCLE;                 // 初始化PwmDev
            hp->dev.cfg.period = PWM_DEFAULT_PERIOD;                   // 初始化PwmDev
            hp->dev.cfg.polarity = PWM_DEFAULT_POLARITY;               // 初始化PwmDev
            hp->dev.cfg.status = PWM_DISABLE_STATUS;                   // 初始化PwmDev
            hp->dev.cfg.number = 0;                                    // 初始化PwmDev
            hp->dev.busy = false;                                      // 初始化PwmDev
            if (PwmDeviceAdd(obj, &(hp->dev)) != HDF_SUCCESS) {        // 【重要】调用核心层函数，初始化hp->dev的设备和服务。
                OsalIoUnmap((void *)hp->base);
                return HDF_FAILURE;
            }
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

        ```c
        static void HdfPwmRelease(struct HdfDeviceObject *obj)
        {
            struct HiPwm *hp = NULL;
            ......
            hp = (struct HiPwm *)obj->service;        // 这里有HdfDeviceObject到HiPwm的强制转化
            ......                                       
            PwmDeviceRemove(obj, &(hp->dev));         // 【必要】调用核心层函数，释放PwmDev的设备和服务，这里有HiPwm到PwmDev的强制转化。
            HiPwmRemove(hp);                          // 释放HiPwm
        }
        ```

4. 驱动调试

    【可选】针对新增驱动程序，建议验证驱动基本功能，例如PWM控制状态等。
