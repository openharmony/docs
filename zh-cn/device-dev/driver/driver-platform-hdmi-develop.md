# HDMI

## 概述 

### 功能简介

HDMI（High Definition Multimedia Interface），即高清多媒体接口，是Hitachi、Panasonic、Philips、Silicon Image、Sony、Thomson、Toshiba共同发布的一款音视频传输协议，主要用于DVD、机顶盒等音视频Source设备到TV、显示器等Sink设备的传输。HDMI传输过程遵循TMDS（Transition Minimized Differential Signaling）协议。

### 基本概念

- TMDS（Transition Minimized Differential signal）：过渡调制差分信号，也被称为最小化传输差分信号，用于发送音频、视频及各种辅助数据。

- DDC（Display Data Channel）：显示数据通道，发送端与接收端可利用DDC通道得知彼此的发送与接收能力，但HDMI仅需单向获知接收端（显示器）的能力。

- CEC（Consumer Electronics Control）：消费电子控制，该功能应该能够在连接HDMI的发送设备与接收设备之间实现交互操作。

- FRL（Fixed Rate Link）：TMDS的架构进行讯号传输时，最高带宽可达18Gbps，而FRL模式的带宽则提升到48Gbps。

- HDCP（High-bandwidth Digital Content Protection）：即高带宽数字内容保护技术，当用户对高清晰信号进行非法复制时，该技术会进行干扰，降低复制出来的影像的质量，从而对内容进行保护。

### 运作机制

在HDF框架中，HDMI的接口适配模式拟采用独立服务模式（如图1）。在这种模式下，每一个设备对象会独立发布一个设备服务来处理外部访问，设备管理器收到API的访问请求之后，通过提取该请求的参数，达到调用实际设备对象的相应内部方法的目的。独立服务模式可以直接借助HDFDeviceManager的服务管理能力，但需要为每个设备单独配置设备节点，增加内存占用率。

HDMI模块各分层作用：

- 接口层提供打开HDMI设备、启动HDMI传输、停止HDMI传输、声音图像消隐设置、设置色彩深度、获取色彩深度、设置视频属性、获取视频属性、设置HDR属性、读取Sink端原始EDID数据、注册HDMI热插拔检测回调函数、注销HDMI热插拔检测回调函数、关闭HDMI设备的接口。

- 核心层主要提供HDMI控制器的打开、关闭及管理的能力，通过钩子函数与适配层交互。

- 适配层主要是将钩子函数的功能实例化，实现具体的功能。

**图 1** HDMI独立服务模式

![HDMI独立服务模式](figures/独立服务模式结构图.png)

### 约束与限制

HDMI模块当前仅支持轻量和小型系统内核（LiteOS），暂无实际适配驱动。

## 开发指导

### 场景介绍

HDMI具有体积小、传输速率高、传输带宽宽、兼容性好、能同时传输无压缩音视频信号等优点。与传统的全模拟接口相比，HDMI不但增加了设备间接线的便捷性，还提供了一些HDMI特有的智能化功能，可用于小体积设备进行高质量音视频传输的场景。

### 接口说明

HdmiCntlrOps定义：

```c
struct HdmiCntlrOps {
    void (*hardWareInit)(struct HdmiCntlr *cntlr);
    void (*hardWareStatusGet)(struct HdmiCntlr *cntlr, struct HdmiHardwareStatus *status);
    void (*controllerReset)(struct HdmiCntlr *cntlr);
    bool (*hotPlugStateGet)(struct HdmiCntlr *cntlr);
    bool (*hotPlugInterruptStateGet)(struct HdmiCntlr *cntlr);
    void (*lowPowerSet)(struct HdmiCntlr *cntlr, bool enable);
    void (*tmdsModeSet)(struct HdmiCntlr *cntlr, enum HdmiTmdsModeType mode);
    int32_t (*tmdsConfigSet)(struct HdmiCntlr *cntlr, struct HdmiTmdsConfig mode);
    void (*infoFrameEnable)(struct HdmiCntlr *cntlr, enum HdmiPacketType infoFrameType, bool enable);
    int32_t (*infoFrameSend)(struct HdmiCntlr *cntlr, enum HdmiPacketType infoFrameType, uint8_t *data, uint32_t len);
    int32_t (*infoFrameDataSet)(struct HdmiCntlr *cntlr, uint32_t type, uint8_t *data, uint32_t len);
    int32_t (*cecMsgSend)(struct HdmiCntlr *cntlr, struct HdmiCecMsg *msg);
    void (*audioPathEnable)(struct HdmiCntlr *cntlr, bool enable);
    void (*audioPathSet)(struct HdmiCntlr *cntlr, struct HdmiAudioConfigInfo *config);
    void (*phyOutputEnable)(struct HdmiCntlr *cntlr, bool enable);
    void (*phyOutputSet)(struct HdmiCntlr *cntlr, struct HdmiPhyCfg *cfg);
    void (*blackDataSet)(struct HdmiCntlr *cntlr, bool enable);
    void (*videoMuteEnable)(struct HdmiCntlr *cntlr, bool enable);
    void (*videoPathSet)(struct HdmiCntlr *cntlr, struct HdmiVideoAttr *attr);
    void (*audioMuteEnable)(struct HdmiCntlr *cntlr, bool enable);
    void (*avmuteSet)(struct HdmiCntlr *cntlr, bool enable);
    int32_t (*ddcTransfer)(struct HdmiCntlr *cntlr, struct HdmiDdcCfg *ddcCfg);
    bool (*scdcSourceScrambleGet)(struct HdmiCntlr *cntlr);
    int32_t (*scdcSourceScrambleSet)(struct HdmiCntlr *cntlr, bool enable);
    void (*frlSet)(struct HdmiCntlr *cntlr);
    int32_t (*frlEnable)(struct HdmiCntlr *cntlr, bool enable);
    int32_t (*audioNctsSet)(struct HdmiCntlr *cntlr, struct HdmiFrlAudioNctsConfig *cfg);
    void (*frlTrainingConfigSet)(struct HdmiCntlr *cntlr, struct HdmiFrlTrainConfig *cfg);
    void (*frlTrainingStart)(struct HdmiCntlr *cntlr);
    void (*frlGetTriningRslt)(struct HdmiCntlr *cntlr, struct HdmiFrlTrainRslt *rslt);
    void (*hdcpRegInit)(struct HdmiCntlr *cntlr);
    int32_t (*hdcpGenerateAksvAndAn)(struct HdmiCntlr *cntlr);
    int32_t (*hdcpOptReg)(struct HdmiCntlr *cntlr, enum HdmiHdcpRegOptType type, uint8_t *data, uint32_t len);
    void (*hdrTimerSet)(struct HdmiCntlr *cntlr, struct HdmiHdrTimerConfig *config);
};
```

**表 1** HdmiCntlrOps结构体成员的回调函数功能说明

| 函数成员 | 入参 | 出参 | 返回值 | 功能 |
| ------------------------ | ------------------------------------------------------------ | -------------------------------------- | ------------------ | -------------------------------------------------- |
| hardWareInit | **cntlr**：结构体指针，核心层HDMI控制器 | 无 | 无 | 初始化HDMI硬件 |
| hardWareStatusGet | **cntlr**：结构体指针，核心层HDMI控制器<br /> | **status**：HDMI硬件状态 ; | 无 | 获取HDMI当前硬件状态 |
| controllerReset | **cntlr**：结构体指针，核心层HDMI控制器 | 无 | 无 | 复位HDMI控制器 |
| hotPlugStateGet | **cntlr**：结构体指针，核心层HDMI控制器 | 无 | bool：HDMI热插拔状态 | 获取HDMI热插拔状态 |
| hotPlugInterruptStateGet | **cntlr**：结构体指针，核心层HDMI控制器 | 无 | bool：HDMI热插拔中断状态 | 获取HDMI热插拔中断状态 |
| lowPowerSet | **cntlr**：结构体指针，核心层HDMI控制器<br />**enable**：bool，使能/去使能 | 无 | 无 | 使能/去使能低功耗 |
| tmdsModeSet | **cntlr**：结构体指针，核心层HDMI控制器<br />**mode**：TMDS模式 | 无 | 无 | 设置TMDS模式 |
| tmdsConfigSet | **cntlr**：结构体指针，核心层HDMI控制器<br />**mode**：TMDS参数 | 无 | HDF_STATUS相关状态 | 配置TMDS参数 |
| infoFrameEnable | **cntlr**：结构体指针，核心层HDMI控制器<br />**infoFrameType**：packet类型<br />**enable**：bool，使能/去使能 | 无 | 无 | 使能/去使能infoFrame |
| infoFrameSend | **cntlr**：结构体指针，核心层HDMI控制器<br />**infoFrameType**：packet类型<br />**data**：infoFrame数据<br />**len**：数据长度 | 无 | HDF_STATUS相关状态 | 发送infoFrame |
| cecMsgSend | **cntlr**：结构体指针，核心层HDMI控制器<br />**msg**：CEC消息 | 无 | HDF_STATUS相关状态 | 发送CEC消息 |
| audioPathEnable | **cntlr**：结构体指针，核心层HDMI控制器<br />**enable**：bool，使能/去使能| 无 | 无 | 使能/去使能audio通路 |
| audioPathSet | **cntlr**：结构体指针，核心层HDMI控制器<br />**config**：配置信息 | 无 | 无 | 设置audio通路配置信息 |
| phyOutputEnable | **cntlr**：结构体指针，核心层HDMI控制器<br />**enable**：bool，使能/去使能 | 无 | 无 | 使能/去使能物理层输出状态 |
| phyOutputSet | **cntlr**：结构体指针，核心层HDMI控制器<br />**cfg**：配置信息 | 无 | 无 | 设置物理层配置信息 |
| blackDataSet | **cntlr**：结构体指针，核心层HDMI控制器<br />**enable**：bool，使能/去使能 | 无 | 无 | 设置黑屏 |
| videoMuteEnable | **cntlr**：结构体指针，核心层HDMI控制器<br />**enable**：bool，使能/去使能 | 无 | 无 | 使能/去使能video静音 |
| videoPathSet | **cntlr**：结构体指针，核心层HDMI控制器<br />**attr**：配置信息| 无 | 无 | 设置video通路配置信息 |
|audioMuteEnable | **cntlr**：结构体指针，核心层HDMI控制器<br />**enable**：bool，使能/去使能 | 无 | 无 | 使能/去使能audio静音 |
| avmuteSet | **cntlr**：结构体指针，核心层HDMI控制器<br />**enable**：bool，使能/去使能| 无 | 无 | 使能/去使能声音图像消隐 |
| ddcTransfer | **cntlr**：结构体指针，核心层HDMI控制器<br />**ddcCfg**：DDC配置参数 |**ddcCfg**：DDC配置参数 |HDF_STATUS相关状态 | 读写DDC数据 |
| scdcSourceScrambleGet | **cntlr**：结构体指针，核心层HDMI控制器 | 无 | bool，加扰状态 | 获取source端的加扰状态 |
| scdcSourceScrambleSet | **cntlr**：结构体指针，核心层HDMI控制器<br />**enable**：bool，使能/去使能 | 无 | HDF_STATUS相关状态 | 使能/去使能source端的加扰 |
| frlEnable | **cntlr**：结构体指针，核心层HDMI控制器<br />**enable**：bool，使能/去使能 | 无 | HDF_STATUS相关状态 | 使能/去使能FRL |
| audioNctsSet | **cntlr**：结构体指针，核心层HDMI控制器<br />**cfg**：N/CTS配置参数 | 无 | HDF_STATUS相关状态 | 设置audio的N/CTS信息 |
| frlTrainingConfigSet | **cntlr**：结构体指针，核心层HDMI控制器<br />**cfg**：FRL Training配置参数 | 无 | 无| 设置FRL Training配置信息 |
| frlTrainingStart | **cntlr**：结构体指针，核心层HDMI控制器 | 无 | 无 | 开始FRL Training流程 |
| frlGetTriningRslt | **cntlr**：结构体指针，核心层HDMI控制器 | **rslt**：FRL Training结果 | 无 | 获取FRL Training结果 |
| hdcpRegInit | **cntlr**：结构体指针，核心层HDMI控制器 | 无 | 无 | 初始化HDCP流程相关的寄存器 |
|hdcpGenerateAksvAndAn |**cntlr**：结构体指针，核心层HDMI控制器 | 无 | HDF_STATUS相关状态 | HDCP流程中生成aksv和an |
| hdcpOptReg | **cntlr**：结构体指针，核心层HDMI控制器<br />**type**：操作类型<br />**data**：寄存器数据<br />**len**：数据长度 | **data**：寄存器数据 | HDF_STATUS相关状态 | HDCP流程中读写相关寄存器 |
| hdrTimerSet | **cntlr**：结构体指针，核心层HDMI控制器<br />**config**：timer配置信息 | 无 | 无 | 设置HDR相关的timer配置信息 |


### 开发步骤

HDMI模块适配包含以下四个步骤：

- 实例化驱动入口

    - 实例化HdfDriverEntry结构体成员。

    - 调用HDF_INIT将HdfDriverEntry实例化对象注册到HDF框架中。

- 配置属性文件

    - 在device_info.hcs文件中添加deviceNode描述。

    - 【可选】添加hdmi_config.hcs器件属性文件。

- 实例化HDMI控制器对象

    - 初始化HdmiCntlr成员。

    - 实例化HdmiCntlr成员HdmiCntlrOps方法集合。

- 驱动调试

    【可选】针对新增驱动程序，建议验证驱动基本功能，例如挂载后的信息反馈，HDMI传输等。

1. 实例化驱动入口

    驱动入口必须为HdfDriverEntry（在hdf_device_desc.h中定义）类型的全局变量，且moduleName要和device_info.hcs中保持一致。HDF框架会将所有加载的驱动的HdfDriverEntry对象首地址汇总，形成一个类似数组的段地址空间，方便上层调用。

    一般在加载驱动时HDF会先调用Bind函数，再调用Init函数加载该驱动。当Init调用异常时，HDF框架会调用Release释放驱动资源并退出。

    HDMI驱动入口参考：

    ```c
    struct HdfDriverEntry g_hdmiDriverEntry = {
        .moduleVersion = 1,
        .Bind = HdmiAdapterBind,
        .Init = HdmiAdapterInit,
        .Release = HdmiAdapterRelease,
        .moduleName = "adapter_hdmi_driver", // 【必要且与HCS文件中里面的moduleName匹配】
    };
    HDF_INIT(g_hdmiDriverEntry);             // 调用HDF_INIT将驱动入口注册到HDF框架中
    ```

2. 配置属性文件

    完成驱动入口注册之后，下一步请在device_info.hcs文件中添加deviceNode信息，并在hdmi_config.hcs中配置器件属性。deviceNode信息与驱动入口注册相关，器件属性值对于厂商驱动的实现以及核心层HdmiCntlr相关成员的默认值或限制范围有密切关系。从第一个节点开始配置具体HDMI控制器信息，此节点并不表示某一路HDMI控制器，而是代表一个资源性质设备，用于描述一类HDMI控制器的信息。本例只有一个HDMI控制器，如有多个控制器，则需要在device_info文件增加deviceNode信息，以及在hdmi_config文件中增加对应的器件属性。

    - device_info.hcs配置参考

        ```c
        root {
            platform :: host {
                 device_hdmi :: device {
                    device0 :: deviceNode {
                        policy = 2;                                // 等于2，需要发布服务。
                        priority = 20;                             // 驱动启动优先级。
                        permission = 0644;                         // 驱动创建设备节点权限。
                        serviceName = "HDF_PLATFORM_HDMI_0";       //【必要】驱动对外发布服务的名称，必须唯一。
                        moduleName = "hdmi_driver";                //【必要】用于指定驱动名称，需要与期望的驱动Entry中的moduleName一致。
                        deviceMatchAttr = "adapter_hdmi_driver";   //【必要】用于配置控制器私有数据，要与hdmi_config.hcs中对应控制器保持一致。
                    }                                              // 具体的控制器信息在hdmi_config.hcs中。
                 }
            }
        }
        ```

    - hdmi_config.hcs 配置参考

        ```c
        root {
            platform {
                hdmi_config {
                    template hdmi_controller {     // 模板公共参数，继承该模板的节点如果使用模板中的默认值，则节点字段可以缺省。
                        match_attr = "";           //【必要】需要和device_info.hcs中的deviceMatchAttr值一致。
                        index = 0;                 //【必要】hdmi控制器编号
                        regBasePhy = 0x10100000;   //【必要】寄存器物理基地址
                        regSize = 0xd1;            //【必要】寄存器位宽
                        irqNum = 100;              //【必要】中断号
                        maxTmdsClock = 300;
                        videoTiming = 10;
                        quantization = 1;
                        colorSpace = 0;
                        colorimetry = 0;
                        audioIfType = 0;
                        audioBitDepth = 1;
                        audioSampleRate = 2;
                        audioChannels = 1;
                        hdrColorimetry = 4;
                        hdrUserMode = 1;
                        cap = 0xd001e045;
                    }
                    controller_0x10100000 :: hdmi_controller {
                        match_attr = "adapter_hdmi_driver";
                        index = 0;
                        regBasePhy = 0x10100000;
                        irqNum = 100;
                        maxTmdsClock = 400;
                        defTmdsClock = 300;
                        maxFrlRate = 600;
                        videoTiming = 10;
                        quantization = 1;
                        colorSpace = 0;
                        colorimetry = 0;
                        audioIfType = 0;
                        audioSampleRate = 2;
                        audioChannels = 1;
                        hdrColorimetry = 4;
                        hdrUserMode = 1;
                        cap = 0xd001e045;
                    }
                }
            }
        }
        ```

        需要注意的是，新增hdmi_config.hcs配置文件后，必须在对应的hdf.hcs文件中包含hdmi_config.hcs所在路径信息，否则配置文件无法生效。

3. 实例化HDMI控制器对象

    最后一步，完成驱动入口注册之后，要以核心层HdmiCntlr对象的初始化为核心，包括厂商自定义结构体（传递参数和数据），实例化HdmiCntlr成员HdmiCntlrOps（让用户可以通过接口来调用驱动底层函数），实现HdfDriverEntry成员函数（Bind，Init，Release）。

    - 自定义结构体参考

        > ![](../public_sys-resources/icon-note.gif) **说明：**<br> 
        > 从驱动角度看，自定义结构体是参数和数据的载体。HDF会读取hdmi_config.hcs文件中的数值并通过DeviceResourceIface来初始化结构体成员，且其中一些重要数值（例如设备号、总线号等）也会被传递给核心层HdmiCntlr对象。

        ```c
        struct HdmiAdapterHost {
            struct HdmiCntlr *cntlr;        //【必要】是核心层控制对象，具体描述如下。
            volatile unsigned char *regBase;//【必要】寄存器基地址
            uint32_t regBasePhy;            //【必要】寄存器物理基地址
            uint32_t regSize;               //【必要】寄存器位宽
            uint32_t irqNum;                //【必要】中断号
        };

        struct HdmiCntlr {
            struct IDeviceIoService service;
            struct HdfDeviceObject *hdfDevObj;
            struct PlatformDevice device;
            struct OsalMutex mutex;
            struct PlatformQueue *msgQueue;
            struct HdmiCntlrCap cap;
            struct HdmiAttr attr;
            struct HdmiCntlrOps *ops;
            uint32_t deviceIndex;
            uint32_t state;                 // 控制器状态
            enum HdmiTmdsModeType tmdsMode;
            struct HdmiDevice *hdmi;
            struct HdmiInfoframe infoframe;
            struct HdmiScdc *scdc;
            struct HdmiDdc ddc;
            struct HdmiFrl *frl;
            struct HdmiHdcp *hdcp;
            struct HdmiCec *cec;
            struct HdmiEvent event;
            struct HdmiHdr *hdr;
            void *priv;
        };
        ```

    -  HdmiCntlr成员回调函数结构体HdmiCntlrOps的实例化

        ```c 
        static struct HdmiCntlrOps g_hdmiAdapterHostOps = {
            .hardWareInit = HdmiAdapterHardWareInit,
            .hardWareStatusGet = HdmiAdapterHardWareStatusGet,
            .controllerReset = HdmiAdapterControllerReset,
            .hotPlugStateGet = HdmiAdapterHotPlugStateGet,
            .hotPlugInterruptStateGet = HdmiAdapterHotPlugInterruptStateGet,
            .lowPowerSet = HdmiAdapterLowPowerSet,
            .tmdsModeSet = HdmiAdapterTmdsModeSet,
            .tmdsConfigSet = HdmiAdapterTmdsConfigSet,
            .infoframeEnable = HdmiAdapterInfoframeEnable,
            .infoframeSend = HdmiAdapterInfoframeSend,
            .infoframeDataSet = HdmiAdapterInfoframeDataSet,
            .cecMsgSend = HdmiAdapterCecMsgSend,
            .audioPathEnable = HdmiAdapterAudioPathEnable,
            .audioPathSet = HdmiAdapterAudioPathSet,
            .phyOutputEnable = HdmiAdapterPhyOutputEnable,
            .phyOutputSet = HdmiAdapterPhyOutputSet,
            .blackDataSet = HdmiAdapterBlackDataSet,
            .videoMuteEnable = HdmiAdapterVideoMuteEnable,
            .videoPathSet = HdmiAdapterVideoPathSet,
            .audioMuteEnable = HdmiAdapterAudioMuteEnable,
            .avmuteSet = HdmiAdapterAvmuteSet,
            .ddcTransfer = HdmiAdapterDdcTransfer,
            .scdcSourceScrambleGet = HdmiAdapterScdcSourceScrambleGet,
            .scdcSourceScrambleSet = HdmiAdapterScdcSourceScrambleSet,
            .frlSet = HdmiAdapterFrlSet,
            .frlEnable = HdmiAdapterFrlEnable,
            .audioNctsSet = HdmiAdapterAudioNctsSet,
            .frlTrainingConfigSet = HdmiAdapterFrlTrainingConfigSet,
            .frlTrainingStart = HdmiAdapterFrlTrainingStart,
            .frlGetTriningRslt = HdmiAdapterFrlGetTriningRslt,
            .hdcpRegInit = HdmiAdapterHdcpRegInit,
            .hdcpGenerateAksvAndAn = HdmiAdapterHdcpGenerateAksvAndAn,
            .hdcpOptReg = HdmiAdapterHdcpOptReg,
            .hdrTimerSet = HdmiAdapterHdrTimerSet,
        };
        ```

    - Bind函数参考

        **入参：** 

        HdfDeviceObject是整个驱动对外呈现的接口参数，具备HCS配置文件的信息。
        
        **返回值：**

        HDF_STATUS相关状态 （表2为部分展示，如需使用其他状态，可参考//drivers/hdf_core/interfaces/inner_api/utils/hdf_base.h中HDF_STATUS的定义）。

        **表 2** HDF_STATUS相关状态说明

        | 状态(值) | 问题描述 |
        | -------- | -------- |
        | HDF_ERR_INVALID_OBJECT | 控制器对象非法 |
        | HDF_ERR_MALLOC_FAIL | 内存分配失败 |
        | HDF_ERR_IO | I/O&nbsp;错误 |
        | HDF_SUCCESS | 初始化成功 |
        | HDF_FAILURE | 初始化失败 |

        **函数说明：** 

        初始化自定义结构体对象HdmiAdapterHost，初始化HdmiCntlr成员，调用核心层HdmiCntlrAdd函数。
        
        HdmiCntlr，HdmiAdapterHost，HdfDeviceObject之间互相赋值，方便其他函数可以相互转化。

        ```c
        static int32_t HdmiAdapterBind(struct HdfDeviceObject *obj)
        {
            struct HdmiCntlr *cntlr = NULL;
            struct HimciAdapterHost *host = NULL;
            int32_t ret;
            cntlr = (struct HdmiCntlr *)OsalMemCalloc(sizeof(struct HdmiCntlr));
            if (cntlr == NULL) {
                HDF_LOGE("%s: malloc cntlr failed!", __func__);
                return HDF_ERR_MALLOC_FAIL;
            }
            host = (struct HimciAdapterHost *)OsalMemCalloc(sizeof(struct HimciAdapterHost));
            if (host == NULL) {
                HDF_LOGE("%s: malloc host failed!", __func__);
                return HDF_ERR_MALLOC_FAIL;
            }
            cntlr->priv = (void *)host;              //【必要】将host存放至cntlr的私有数据
            cntlr->ops = &g_hdmiHostOps;             //【必要】HdmiCntlrOps的实例化对象的挂载
            cntlr->hdfDevObj = obj;                  //【必要】使HdfDeviceObject与HdmiCntlr可以相互转化的前提
            obj->service = &cntlr->service;          //【必要】使HdfDeviceObject与HdmiCntlr可以相互转化的前提
            ret = HdmiAdapterCntlrParse(cntlr, obj); //【必要】初始化cntlr，失败则goto __ERR。
            ...... 
            ret = HdmiAdapterHostParse(host, obj);   //【必要】初始化host对象的相关属性，失败则goto __ERR。
            ......
            ret = HdmiAdapterHostInit(host, cntlr);  // 厂商自定义的初始化，失败则goto __ERR。
            ......
            ret = HdmiCntlrAdd(cntlr);               // 调用核心层函数，失败则goto __ERR。
            ......
            HDF_LOGD("HdmiAdapterBind: success.");
            return HDF_SUCCESS;
        __ERR:
            HdmiAdapterDeleteHost(host);
            HDF_LOGD("HdmiAdapterBind: fail, err = %d.", ret);
            return ret;
        }
        ```

    - Init函数参考

        **入参：** 

        HdfDeviceObject是整个驱动对外暴露的接口参数，具备HCS配置文件的信息。
        
        **返回值：**

        HDF_STATUS相关状态。
        
        **函数说明**：
        
        实现HdmiAdapterInit函数。

        ```c
        static int32_t HdmiAdapterInit(struct HdfDeviceObject *obj)
        {
            return HDF_SUCCESS;
        }
        ```

    - Release函数参考

        **入参：** 

        HdfDeviceObject是整个驱动对外暴露的接口参数，具备HCS配置文件的信息。
       
        **返回值：**

        无
        
        **函数说明：**

        释放内存和删除控制器，该函数需要在驱动入口结构体中赋值给Release接口，当HDF框架调用Init函数初始化驱动失败时，可以调用Release释放驱动资源。

        > ![](../public_sys-resources/icon-note.gif) **说明：**<br>
        > 所有强制转换获取相应对象的操作前提是在Init函数中具备对应赋值的操作。

        ```c
        static void HdmiAdapterRelease(struct HdfDeviceObject *obj)
        {
            struct HdmiCntlr *cntlr = NULL;
            ......
            cntlr = (struct HdmiCntlr *)obj->service;               // 这里有HdfDeviceObject到HdmiCntlr的强制转化，通过service成员，赋值见Bind函数。
            ......
            HimciDeleteHost((struct HimciAdapterHost *)cntlr->priv);// 厂商自定义的内存释放函数，这里有HdmiCntlr到HimciAdapterHost的强制转化。
        }
        ```

4. 驱动调试

    【可选】针对新增驱动程序，建议验证驱动基本功能，例如挂载后的信息反馈，HDMI传输等。
