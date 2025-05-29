# RTC

## 概述

### 功能简介

RTC（real-time clock）为操作系统中的实时时钟设备，为操作系统提供精准的实时时间和定时报警功能。当设备下电后，通过外置电池供电，RTC继续记录操作系统时间；设备上电后，RTC提供实时时钟给操作系统，确保断电后系统时间的连续性。

### 运作机制

在HDF框架中，RTC的接口适配模式采用独立服务模式，在这种模式下，每一个设备对象会独立发布一个设备服务来处理外部访问，设备管理器收到API的访问请求之后，通过提取该请求的参数，达到调用实际设备对象的相应内部方法的目的。独立服务模式可以直接借助HDFDeviceManager的服务管理能力，但需要为每个设备单独配置设备节点，增加内存占用。

独立服务模式下，核心层不会统一发布一个服务供上层使用，因此这种模式下驱动要为每个控制器发布一个服务，具体表现为：

- 驱动适配者需要实现HdfDriverEntry的Bind钩子函数以绑定服务。

- device_info.hcs文件中deviceNode的policy字段为1或2，不能为0。

**图 1** RTC独立服务模式结构图<a name="fig1"></a>  

![RTC独立服务模式结构图](figures/独立服务模式结构图.png)

RTC模块各分层作用：

- 接口层提供打开RTC设备、RTC设备读取时间、RTC设备设置时间、RTC设备读取警报时间、RTC设备设置警报时间、RTC设备定时报警回调函数、RTC设备设置定时报警中断使能去使能、RTC设备设置RTC外频、RTC设备读取RTC外频、复位RTC、设置RTC自定义寄存器配置，读取RTC自定义寄存器配置以及关闭RTC设备的接口。

- 核心层主要提供RTC控制器的创建、销毁，通过钩子函数与适配层交互。

- 适配层主要是将钩子函数的功能实例化，实现具体的功能。

## 开发指导

### 场景介绍

RTC主要用于提供实时时间和定时报警功能。当驱动开发者需要将RTC设备适配到OpenHarmony时，需要进行RTC驱动适配，下文将介绍如何进行RTC驱动适配。

### 接口说明

为了保证上层在调用RTC接口时能够正确的操作硬件，核心层在//drivers/hdf_core/framework/support/platform/include/rtc/rtc_core.h中定义了以下钩子函数。驱动适配者需要在适配层实现这些函数的具体功能，并与这些钩子函数挂接，从而完成接口层与核心层的交互。

RtcMethod定义：

```c
struct RtcMethod {
    int32_t (*ReadTime)(struct RtcHost *host, struct RtcTime *time);
    int32_t (*WriteTime)(struct RtcHost *host, const struct RtcTime *time);
    int32_t (*ReadAlarm)(struct RtcHost *host, enum RtcAlarmIndex alarmIndex, struct RtcTime *time);
    int32_t (*WriteAlarm)(struct RtcHost *host, enum RtcAlarmIndex alarmIndex, const struct RtcTime *time);
    int32_t (*RegisterAlarmCallback)(struct RtcHost *host, enum RtcAlarmIndex alarmIndex, RtcAlarmCallback cb);
    int32_t (*AlarmInterruptEnable)(struct RtcHost *host, enum RtcAlarmIndex alarmIndex, uint8_t enable);
    int32_t (*GetFreq)(struct RtcHost *host, uint32_t *freq);
    int32_t (*SetFreq)(struct RtcHost *host, uint32_t freq);
    int32_t (*Reset)(struct RtcHost *host);
    int32_t (*ReadReg)(struct RtcHost *host, uint8_t usrDefIndex, uint8_t *value);
    int32_t (*WriteReg)(struct RtcHost *host, uint8_t usrDefIndex, uint8_t value);
};
```

**表 1** RtcMethod结构体成员的钩子函数功能说明

| 函数 | 入参 | 出参 | 返回值 | 功能 | 
| -------- | -------- | -------- | -------- | -------- |
| ReadTime | host：结构体指针，核心层RTC控制器 | time：结构体指针，传出的时间值 | HDF_STATUS相关状态 | 读RTC时间信息 | 
| WriteTime | host：结构体指针，核心层RTC控制器<br>time：结构体指针，时间传入值 | 无 | HDF_STATUS相关状态 | 写RTC时间信息（包括毫秒~年） | 
| ReadAlarm | host：结构体指针，核心层RTC控制器<br>alarmIndex：枚举值，闹钟报警索引 | time：结构体指针，传出的时间值 | HDF_STATUS相关状态 | 读RTC报警时间信息 | 
| WriteAlarm | host：结构体指针，核心层RTC控制器<br>alarmIndex：枚举值，闹钟报警索引<br>time：结构体指针，时间传入值 | 无 | HDF_STATUS相关状态 | 写RTC报警时间信息 | 
| RegisterAlarmCallback | host：结构体指针，核心层RTC控制器<br>alarmIndex：枚举值，闹钟报警索引<br>cb：函数指针，回调函数 | 无 | HDF_STATUS相关状态 | 注册报警超时回调函数 | 
| AlarmInterruptEnable | host：结构体指针，核心层RTC控制器<br>alarmIndex：枚举值，闹钟报警索引<br>enable：布尔值，控制报警 | 无 | HDF_STATUS相关状态 | 使能/去使能RTC报警中断 | 
| GetFreq | host：结构体指针，核心层RTC控制器 | freq：uint32_t类型指针，传出的频率值 | HDF_STATUS相关状态 | 读RTC外接晶振频率 | 
| SetFreq | host：结构体指针，核心层RTC控制器<br>freq：uint32_t类型，频率传入值 | 无 | HDF_STATUS相关状态 | 配置RTC外接晶振频率 | 
| Reset | host：结构体指针，核心层RTC控制器 | 无 | HDF_STATUS相关状态 | RTC复位 | 
| ReadReg | host：结构体指针，核心层RTC控制器<br>usrDefIndex：结构体，用户自定义寄存器索引 | value：uint8_t类型指针，传出的寄存器值 | HDF_STATUS相关状态 | 按照用户定义的寄存器索引，读取对应的寄存器配置，一个索引对应一字节的配置值 | 
| WriteReg | host：结构体指针，核心层RTC控制器<br>usrDefIndex：结构体，用户自定义寄存器索引<br>value：uint8_t类型，寄存器传入值 | 无 | HDF_STATUS相关状态 | 按照用户定义的寄存器索引，设置对应的寄存器配置，一个索引对应一字节的配置值 | 


### 开发步骤

RTC模块适配HDF框架包含以下四个步骤：

1. 实例化驱动入口

    - 实例化HdfDriverEntry结构体成员。

    - 调用HDF_INIT将HdfDriverEntry实例化对象注册到HDF框架中。

2. 配置属性文件

    - 在device_info.hcs文件中添加deviceNode描述。

    - 【可选】添加rtc_config.hcs器件属性文件。

3. 实例化RTC控制器对象

    - 初始化RtcHost成员。

    - 实例化RtcHost成员RtcMethod。

        > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**<br>
        > 实例化RtcHost成员RtcMethod，其定义和成员说明见[接口说明](#接口说明)。

4. 驱动调试

   【可选】针对新增驱动程序，建议验证驱动基本功能，例如RTC控制状态，中断响应情况等。


### 开发实例

下方将以Hi3516DV300的驱动//device/soc/hisilicon/common/platform/rtc/rtc_hi35xx.c为示例，展示驱动适配者需要提供哪些内容来完整实现设备功能。

1. 实例化驱动入口

    驱动入口必须为HdfDriverEntry（在hdf_device_desc.h中定义）类型的全局变量，且moduleName要和device_info.hcs中保持一致。HDF框架会将所有加载的驱动的HdfDriverEntry对象首地址汇总，形成一个类似数组的段地址空间，方便上层调用。

    一般在加载驱动时HDF会先调用Bind函数，再调用Init函数加载该驱动。当Init调用异常时，HDF框架会调用Release释放驱动资源并退出。

    RTC驱动入口参考：
     
    ```c
    struct HdfDriverEntry g_rtcDriverEntry = {
      .moduleVersion = 1,
      .Bind = HiRtcBind,                   // 挂接RTC模块Bind实例化
      .Init = HiRtcInit,                   // 挂接RTC模块Init实例化
      .Release = HiRtcRelease,             // 挂接RTC模块Release实例化
      .moduleName = "HDF_PLATFORM_RTC",    // 【必要且与HCS文件中里面的moduleName匹配】
    };
    HDF_INIT(g_rtcDriverEntry);            // 调用HDF_INIT将驱动入口注册到HDF框架中
    ```

2. 配置属性文件

    完成驱动入口注册之后，需要在device_info.hcs文件中添加deviceNode描述。deviceNode信息与驱动入口注册相关。本例只有一个RTC控制器，如有多个器件信息，则需要在device_info.hcs文件增加deviceNode信息，以及在rtc_config.hcs文件中增加对应的器件属性。器件属性值与核心层RtcHost成员的默认值或限制范围有密切关系，比如RTC中断号，需要在rtc_config.hcs文件中增加对应的器件属性。

    独立服务模式的特点是device_info.hcs文件中设备节点代表着一个设备对象，如果存在多个设备对象，则按需添加，注意服务名与驱动私有数据匹配的关键字名称必须唯一。其中各项参数如表2所示：

    **表 2** device_info.hcs节点参数说明

    | 成员名 | 值 |
    | -------- | -------- |
    | policy | 驱动服务发布的策略，RTC控制器具体配置为2，表示驱动对内核态和用户态都发布服务 |
    | priority | 驱动启动优先级（0-200），值越大优先级越低。RTC控制器具体配置为30 |
    | permission | 驱动创建设备节点权限，RTC控制器具体配置为0664 |
    | moduleName | 驱动名称，RTC控制器固定为HDF_PLATFORM_RTC |
    | serviceName | 驱动对外发布服务的名称，RTC控制器服务名设置为HDF_PLATFORM_RTC |
    | deviceMatchAttr | 驱动私有数据匹配的关键字，RTC控制器设置为hisilicon_hi35xx_rtc |

    - device_info.hcs配置参考
   
        在//vendor/hisilicon/hispark_taurus/hdf_config/device_info/device_info.hcs文件中添加deviceNode描述。

        ```c
        root {
            device_info {
                platform :: host {
                    device_rtc :: device {
                        device0 :: deviceNode {                        // 驱动的DeviceNode节点
                          policy = 1;                                  // policy字段是驱动服务发布的策略,如果需要面向用户态，则为2
                          priority = 30;                               // 驱动启动优先级
                          permission = 0644;                           // 驱动创建设备节点权限
                          moduleName = "HDF_PLATFORM_RTC";             // 【必要】用于指定驱动名称，需要与驱动Entry中的moduleName一致。
                          serviceName = "HDF_PLATFORM_RTC";            // 【必要】驱动对外发布服务的名称，必须唯一。
                          deviceMatchAttr = "hisilicon_hi35xx_rtc";    // 【必要】用于配置控制器私有数据，必须和驱动私有数据配置表rtc_config.hcs中的match_attr值保持一致。
                        }
                    }
                }
            }
        }
        ```
   
    - rtc_config.hcs配置参考
   
        在//device/soc/hisilicon/hi3516dv300/sdk_liteos/hdf_config/rtc/rtc_config.hcs文件配置器件属性，其中配置参数如下：

        ```c
        root {
            platform {
                rtc_config {
                    controller_0x12080000 {
                        match_attr = "hisilicon_hi35xx_rtc"; // 【必要】需要和device_info.hcs中的deviceMatchAttr值一致
                        rtcSpiBaseAddr = 0x12080000;         // 地址映射相关
                        regAddrLength = 0x100;               // 地址映射相关
                        irq = 37;                            // 中断号
                        supportAnaCtrl = false;
                        supportLock = false;
                        anaCtrlAddr = 0xff;
                        lock0Addr = 0xff;
                        lock1Addr = 0xff;
                        lock2Addr = 0xff;
                        lock3Addr = 0xff;
                    }
                }
            }
        }
        ```

        需要注意的是，新增rtc_config.hcs配置文件后，必须在hdf.hcs文件中将其包含，否则配置文件无法生效。

        例如：本例中rtc_config.hcs所在路径为device/soc/hisilicon/hi3516dv300/sdk_liteos/hdf_config/rtc/rtc_config.hcs，则必须在产品对应的hdf.hcs中添加如下语句：

        ```c
        #include "../../../../device/soc/hisilicon/hi3516dv300/sdk_liteos/hdf_config/rtc/rtc_config.hcs" // 配置文件相对路径
        ```

3. 实例化RTC控制器对象

    完成属性文件配置之后，下一步就是以核心层RtcHost对象的初始化为核心，包括驱动适配者自定义结构体（传递参数和数据），实例化RtcHost成员RtcMethod（让用户可以通过接口来调用驱动底层函数），实现HdfDriverEntry成员函数（Bind、Init、Release）。

    - 自定义结构体参考。

        从驱动的角度看，自定义结构体是参数和数据的载体，而且rtc_config.hcs文件中的数值会被HDF读入并通过DeviceResourceIface来初始化结构体成员。

        ```c
        struct RtcConfigInfo {
            uint32_t spiBaseAddr;         // 地址映射相关
            volatile void *remapBaseAddr; // 地址映射相关
            uint16_t regAddrLength;       // 地址映射相关
            uint8_t supportAnaCtrl;       // 是否支持anactrl
            uint8_t supportLock;          // 是否支持锁
            uint8_t irq;                  // 中断号
            uint8_t alarmIndex;           // 闹钟索引
            uint8_t anaCtrlAddr;          // anactrl地址
            struct RtcLockAddr lockAddr;  // 锁地址
            RtcAlarmCallback cb;          // 回调函数
            struct OsalMutex mutex;       // 互斥锁
        };
      
        // RtcHost是核心层控制器结构体，其中的成员在Init函数中会被赋值。
        struct RtcHost {
            struct IDeviceIoService service;
            struct HdfDeviceObject *device;
            struct RtcMethod *method;
            void *data;
        };
        ```

    - RtcHost成员钩子函数结构体RtcMethod的实例化。

        ```c
        // rtc_hi35xx.c中的示例：钩子函数的填充
        static struct RtcMethod g_method = {
            .ReadTime = HiRtcReadTime,
            .WriteTime = HiRtcWriteTime,
            .ReadAlarm = HiReadAlarm,
            .WriteAlarm = HiWriteAlarm,
            .RegisterAlarmCallback = HiRegisterAlarmCallback,
            .AlarmInterruptEnable = HiAlarmInterruptEnable,
            .GetFreq = HiGetFreq,
            .SetFreq = HiSetFreq,
            .Reset = HiReset,
            .ReadReg = HiReadReg,
            .WriteReg = HiWriteReg,
        };
        ```

    - Bind函数开发参考。

        入参：

        HdfDeviceObject是整个驱动对外提供的接口参数，具备HCS配置文件的信息。

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

        关联HdfDeviceObject对象和RtcHost。

        ```c
        static int32_t HiRtcBind(struct HdfDeviceObject *device)
        {
            struct RtcHost *host = NULL;
            host = RtcHostCreate(device);     // 实际是申请内存并挂接device: host->device = device
                                              // 使HdfDeviceObject与RtcHost可以相互转化的前提
            ......
            device->service = &host->service; // 使HdfDeviceObject与RtcHost可以相互转化的前提
                                              // 方便后续通过调用RtcHostFromDevice实现全局性质的host
            return HDF_SUCCESS;
        }
        ```

    - Init函数开发参考。

        入参：

        HdfDeviceObject是整个驱动对外提供的接口参数，具备HCS配置文件的信息。

        返回值：

        HDF_STATUS相关状态。

        函数说明：

        初始化自定义结构体对象，初始化RtcHost成员。

        ```c
        static int32_t HiRtcInit(struct HdfDeviceObject *device)
        {
            struct RtcHost *host = NULL;
            struct RtcConfigInfo *rtcInfo = NULL;
            ......
            host = RtcHostFromDevice(device);  // 这里是HdfDeviceObject到RtcHost的强制转换
            rtcInfo = OsalMemCalloc(sizeof(*rtcInfo));
            ......
            /* HiRtcConfigData会从设备配置树中读取属性填充rtcInfo的supportAnaCtrl、supportLock、spiBaseAddr、regAddrLength、irq，
             * 为HiRtcSwInit和HiRtcSwInit提供参数，当函数HiRtcSwInit和HiRtcSwInit内部执行失败后进行内存释放等操作。
             */
            if (HiRtcConfigData(rtcInfo, device->property) != 0) {
                ......
            }
            if (HiRtcSwInit(rtcInfo) != 0) {   // 地址映射以及中断注册相关
                ......
            }
            if (HiRtcHwInit(rtcInfo) != 0) {   // 初始化anaCtrl和lockAddr相关内容
                ......
            }
        
            host->method = &g_method;          // RtcMethod的实例化对象的挂载
            host->data = rtcInfo;              // 使RtcConfigInfo与RtcHost可以相互转化的前提
            HDF_LOGI("Hdf dev service:%s init success!", HdfDeviceGetServiceName(device));
            return HDF_SUCCESS;
        }
        ```
    - Release函数开发参考。

        入参：

        HdfDeviceObject是整个驱动对外提供的接口参数，具备HCS配置文件的信息。

        返回值：

        无。

        函数说明：

        释放内存和删除控制器，该函数需要在驱动入口结构体中赋值给Release接口，当HDF框架调用Init函数初始化驱动失败时，可以调用Release释放驱动资源。

        > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**<br>
        > 所有强制转换获取相应对象的操作前提是在Init或Bind函数中具备对应赋值的操作。

        
        ```c
        static void HiRtcRelease(struct HdfDeviceObject *device)
        {
            struct RtcHost *host = NULL;
            struct RtcConfigInfo *rtcInfo = NULL;
            ...
            host = RtcHostFromDevice(device);             // 这里是HdfDeviceObject到RtcHost的强制转换
            rtcInfo = (struct RtcConfigInfo *)host->data; // 这里是RtcHost到RtcConfigInfo的强制转换
            if (rtcInfo != NULL) {
                HiRtcSwExit(rtcInfo);
                OsalMemFree(rtcInfo);                     // 释放RtcConfigInfo
                host->data = NULL;
            }
            RtcHostDestroy(host);                         // 释放RtcHost
        }
        ```

4. 驱动调试

    【可选】针对新增驱动程序，建议验证驱动基本功能，例如挂载后的信息反馈，读取RTC时间、设置RTC时间等。
