# MMC


## 概述

MMC（MultiMedia Card）即多媒体卡。在HDF框架中，MMC的接口适配模式采用独立服务模式。在这种模式下，每一个设备对象会独立发布一个设备服务来处理外部访问，设备管理器收到API的访问请求之后，通过提取该请求的参数，达到调用实际设备对象的相应内部方法的目的。独立服务模式可以直接借助HDFDeviceManager的服务管理能力，但需要为每个设备单独配置设备节点，增加内存占用。

  **图1** MMC独立服务模式结构图

  ![zh-cn_image_0000001176603968](figures/独立服务模式结构图.png "MMC独立服务模式结构图")


## 接口说明

MmcCntlrOps定义：

  
```
struct MmcCntlrOps {
  int32_t (*request)(struct MmcCntlr *cntlr, struct MmcCmd *cmd);
  int32_t (*setClock)(struct MmcCntlr *cntlr, uint32_t clock);
  int32_t (*setPowerMode)(struct MmcCntlr *cntlr, enum MmcPowerMode mode);
  int32_t (*setBusWidth)(struct MmcCntlr *cntlr, enum MmcBusWidth width);
  int32_t (*setBusTiming)(struct MmcCntlr *cntlr, enum MmcBusTiming timing);
  int32_t (*setSdioIrq)(struct MmcCntlr *cntlr, bool enable);
  int32_t (*hardwareReset)(struct MmcCntlr *cntlr);
  int32_t (*systemInit)(struct MmcCntlr *cntlr);
  int32_t (*setEnhanceSrobe)(struct MmcCntlr *cntlr, bool enable);
  int32_t (*switchVoltage)(struct MmcCntlr *cntlr, enum MmcVolt volt);
  bool (*devReadOnly)(struct MmcCntlr *cntlr);
  bool (*devPluged)(struct MmcCntlr *cntlr);
  bool (*devBusy)(struct MmcCntlr *cntlr);
  int32_t  (*tune)(struct MmcCntlr *cntlr, uint32_t cmdCode);
  int32_t (*rescanSdioDev)(struct MmcCntlr *cntlr);
};
```

  **表1** MmcCntlrOps结构体成员的回调函数功能说明

| 成员函数 | 入参 | 返回值 | 功能 | 
| -------- | -------- | -------- | -------- |
| doRequest | cntlr：核心层结构体指针，MMC控制器<br>cmd：结构体指针,传入命令值 | HDF_STATUS相关状态 | request相应处理 | 
| setClock | cntlr：核心层结构体指针，MMC控制器<br>clock：时钟传入值 | HDF_STATUS相关状态 | 设置时钟频率 | 
| setPowerMode | cntlr：核心层结构体指针，MMC控制器<br>mode：枚举值（见MmcPowerMode定义），功耗模式 | HDF_STATUS相关状态 | 设置功耗模式 | 
| setBusWidth | cntlr：核心层结构体指针，MMC控制器<br>width：枚举值（见MmcBusWidth定义），总线带宽 | HDF_STATUS相关状态 | 设置总线带宽 | 
| setBusTiming | cntlr：核心层结构体指针，MMC控制器<br>timing：枚举值（见MmcBusTiming定义），总线时序 | HDF_STATUS相关状态 | 设置总线时序 | 
| setSdioIrq | cntlr：核心层结构体指针，MMC控制器<br>enable：布尔值，控制中断 | HDF_STATUS相关状态 | 使能/去使能SDIO中断 | 
| hardwareReset | cntlr：核心层结构体指针，MMC控制器 | HDF_STATUS相关状态 | 复位硬件 | 
| systemInit | cntlr：核心层结构体指针，MMC控制器 | HDF_STATUS相关状态 | 系统初始化 | 
| setEnhanceSrobe | cntlr：核心层结构体指针，MMC控制器<br>enable：布尔值，设置功能 | HDF_STATUS相关状态 | 设置增强选通 | 
| switchVoltage | cntlr：核心层结构体指针，MMC控制器<br>volt：枚举值，电压值（3.3,1.8,1.2V） | HDF_STATUS相关状态 | 设置电压值 | 
| devReadOnly | cntlr：核心层结构体指针，MMC控制器 | 布尔值 | 检验设备是否只读 | 
| cardPluged | cntlr：核心层结构体指针，MMC控制器 | 布尔值 | 检验设备是否拔出 | 
| devBusy | cntlr：核心层结构体指针，MMC控制器 | 布尔值 | 检验设备是否忙碌 | 
| tune | cntlr：核心层结构体指针，MMC控制器<br>cmdCode：uint32_t，命令代码 | HDF_STATUS相关状态 | 调谐 | 
| rescanSdioDev | cntlr：核心层结构体指针，MMC控制器 | HDF_STATUS相关状态 | 扫描并添加SDIO设备 | 


## 开发步骤

MMC模块适配的三个环节是配置属性文件，实例化驱动入口，以及实例化核心层接口函数。

1. **实例化驱动入口：**
   - 实例化HdfDriverEntry结构体成员。
   - 调用HDF_INIT将HdfDriverEntry实例化对象注册到HDF框架中。

2. **配置属性文件：**
   - 在device_info.hcs文件中添加deviceNode描述。
   - 【可选】添加mmc_config.hcs器件属性文件。

3. **实例化MMC控制器对象：**
   - 初始化MmcCntlr成员。
   - 实例化MmcCntlr成员MmcCntlrOps。
      > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**<br>
      > 实例化MmcCntlr成员MmcCntlrOps，其定义和成员说明见[接口说明](#接口说明)。

4. **驱动调试：**
   【可选】针对新增驱动程序，建议验证驱动基本功能，例如挂载后的信息反馈，设备启动是否成功等。


## 开发实例

下方将以himci.c为示例，展示需要厂商提供哪些内容来完整实现设备功能。

1. 驱动开发首先需要实例化驱动入口，驱动入口必须为HdfDriverEntry（在 hdf_device_desc.h 中定义）类型的全局变量，且moduleName要和device_info.hcs中保持一致。HDF框架会将所有加载的驱动的HdfDriverEntry对象首地址汇总，形成一个类似数组的段地址空间，方便上层调用。

   一般在加载驱动时HDF会先调用Bind函数，再调用Init函数加载该驱动。当Init调用异常时，HDF框架会调用Release释放驱动资源并退出。

     MMC驱动入口参考：
     
   ```
   struct HdfDriverEntry g_mmcDriverEntry = {
       .moduleVersion = 1,
       .Bind = HimciMmcBind,             // 见Bind参考
       .Init = HimciMmcInit,             // 见Init参考
       .Release = HimciMmcRelease,       // 见Release参考
       .moduleName = "hi3516_mmc_driver",// 【必要且与HCS文件中里面的moduleName匹配】
   };
   HDF_INIT(g_mmcDriverEntry);           // 调用HDF_INIT将驱动入口注册到HDF框架中
   ```

2. 完成驱动入口注册之后，下一步请在device_info.hcs文件中添加deviceNode信息，并在mmc_config.hcs中配置器件属性。deviceNode信息与驱动入口注册相关，器件属性值与核心层MmcCntlr成员的默认值或限制范围有密切关系。
     如有多个器件信息，则需要在device_info文件增加deviceNode信息，以及在mmc_config文件中增加对应的器件属性**。**
   - device_info.hcs 配置参考
   
       
     ```
     root {
       device_info {
         match_attr = "hdf_manager";
         platform :: host {
           hostName = "platform_host";
           priority = 50;
           device_mmc:: device {
             device0 :: deviceNode {
               policy = 2;
               priority = 10;
               permission = 0644;
               moduleName = "hi3516_mmc_driver";   // 【必要】用于指定驱动名称，需要与驱动Entry中的moduleName一致；
               serviceName = "HDF_PLATFORM_MMC_0"; // 【必要】驱动对外发布服务的名称，必须唯一
               deviceMatchAttr = "hi3516_mmc_emmc";// 【必要】用于配置控制器私有数据，要与 mmc_config.hcs 中对应控制器保持一致
             }
             device1 :: deviceNode {
               policy = 1;
               priority = 20;
               permission = 0644;
               moduleName = "hi3516_mmc_driver";
               serviceName = "HDF_PLATFORM_MMC_1";
               deviceMatchAttr = "hi3516_mmc_sd"; // SD类型
             }
             device2 :: deviceNode {
               policy = 1;
               priority = 30;
               permission = 0644;
               moduleName = "hi3516_mmc_driver";
               serviceName = "HDF_PLATFORM_MMC_2";
               deviceMatchAttr = "hi3516_mmc_sdio";// SDIO类型
             }
           }
         }
       }
     }
     ```
   
   - mmc_config.hcs配置参考
   
       
     ```
     root {
       platform {
         mmc_config {
           template mmc_controller {// 模板公共参数，继承该模板的节点如果使用模板中的默认值，则节点字段可以缺省
             match_attr = "";
             voltDef = 0;            // 3.3V
             freqMin = 50000;        // 【必要】最小频率值
             freqMax = 100000000;    // 【必要】最大频率值
             freqDef = 400000;       // 【必要】默认频率值
             maxBlkNum = 2048;       // 【必要】最大的block号
             maxBlkSize = 512;       // 【必要】最大的block个数
             ocrDef = 0x300000;      // 【必要】工作电压设置相关
             caps2 = 0;              // 【必要】属性寄存器相关，见mmc_caps.h中MmcCaps2定义
             regSize = 0x118;        // 【必要】寄存器位宽
             hostId = 0;             // 【必要】主机号
             regBasePhy = 0x10020000;// 【必要】寄存器物理基地址
             irqNum = 63;            // 【必要】中断号
             devType = 2;            // 【必要】模式选择：emmc, SD, SDIO ,COMBO
             caps = 0x0001e045;      // 【必要】属性寄存器相关，见mmc_caps.h 中 MmcCaps 定义
           }
           controller_0x10100000 :: mmc_controller {
             match_attr = "hi3516_mmc_emmc";// 【必要】需要和device_info.hcs中的deviceMatchAttr值一致
             hostId = 0;
             regBasePhy = 0x10100000;
             irqNum = 96;
             devType = 0;            // emmc类型
             caps = 0xd001e045;
             caps2 = 0x60;
           }
           controller_0x100f0000 :: mmc_controller {
             match_attr = "hi3516_mmc_sd";
             hostId = 1;
             regBasePhy = 0x100f0000;
             irqNum = 62;
             devType = 1;            // SD类型
             caps = 0xd001e005;
           }
           controller_0x10020000 :: mmc_controller {
             match_attr = "hi3516_mmc_sdio";
             hostId = 2;
             regBasePhy = 0x10020000;
             irqNum = 63;
             devType = 2;            // SDIO类型
             caps = 0x0001e04d;
           }
         }
       }
     }
     ```

3. 完成驱动入口注册之后，最后一步就是以核心层MmcCntlr对象的初始化为核心，包括厂商自定义结构体（传递参数和数据），实例化MmcCntlr成员MmcCntlrOps（让用户可以通过接口来调用驱动底层函数），实现HdfDriverEntry成员函数（Bind，Init，Release）。
   - 自定义结构体参考

      从驱动的角度看，自定义结构体是参数和数据的载体，而且mmc_config.hcs文件中的数值会被HDF读入通过DeviceResourceIface来初始化结构体成员 ，一些重要数值也会传递给核心层对象。

        
      ```
      struct HimciHost {
          struct MmcCntlr *mmc;// 【必要】核心层结构体
          struct MmcCmd *cmd;  // 【必要】核心层结构体，传递命令的，相关命令见枚举量 MmcCmdCode
          // 【可选】根据厂商驱动需要添加
          void *base;
          enum HimciPowerStatus powerStatus;
          uint8_t *alignedBuff;
          uint32_t buffLen;
          struct scatterlist dmaSg;
          struct scatterlist *sg;
          uint32_t dmaSgNum;
          DMA_ADDR_T dmaPaddr;
          uint32_t *dmaVaddr;
          uint32_t irqNum;
          bool isTuning;
          uint32_t id;
          struct OsalMutex mutex;
          bool waitForEvent;
          HIMCI_EVENT himciEvent;
      };
      // MmcCntlr是核心层控制器结构体，其中的成员在bind函数中会被赋值
      struct MmcCntlr {
          struct IDeviceIoService service;
          struct HdfDeviceObject *hdfDevObj;
          struct PlatformDevice device;
          struct OsalMutex mutex;
          struct OsalSem released;
          uint32_t devType;
          struct MmcDevice *curDev;
          struct MmcCntlrOps *ops;
          struct PlatformQueue *msgQueue;
          uint16_t index;
          uint16_t voltDef;
          uint32_t vddBit;
          uint32_t freqMin;
          uint32_t freqMax;
          uint32_t freqDef;
          union MmcOcr ocrDef;
          union MmcCaps caps;
          union MmcCaps2 caps2;
          uint32_t maxBlkNum;
          uint32_t maxBlkSize;
          uint32_t maxReqSize;
          bool devPluged;
          bool detecting;
          void *priv;
      };
      ```

   - MmcCntlr成员回调函数结构体MmcCntlrOps的实例化，其他成员在Bind函数中初始化。

        
      ```
      static struct MmcCntlrOps g_himciHostOps = {
          .request        = HimciDoRequest,
          .setClock       = HimciSetClock,
          .setPowerMode   = HimciSetPowerMode,
          .setBusWidth    = HimciSetBusWidth,
          .setBusTiming   = HimciSetBusTiming,
          .setSdioIrq     = HimciSetSdioIrq,
          .hardwareReset  = HimciHardwareReset,
          .systemInit     = HimciSystemInit,
          .setEnhanceSrobe= HimciSetEnhanceSrobe,
          .switchVoltage  = HimciSwitchVoltage,
          .devReadOnly    = HimciDevReadOnly,
          .devPluged      = HimciCardPluged,
          .devBusy        = HimciDevBusy,
          .tune           = HimciTune,
          .rescanSdioDev  = HimciRescanSdioDev,
      };
      ```
   - Bind函数参考

      入参**：**

      HdfDeviceObject是整个驱动对外暴露的接口参数，具备hcs配置文件的信息。

      返回值：

      HDF_STATUS相关状态（下表为部分展示，如需使用其他状态，可见//drivers/framework/include/utils/hdf_base.h中HDF_STATUS 定义）。

        | 状态(值) | 问题描述 | 
      | -------- | -------- |
      | HDF_ERR_INVALID_OBJECT | 控制器对象非法 | 
      | HDF_ERR_MALLOC_FAIL | 内存分配失败 | 
      | HDF_ERR_INVALID_PARAM | 参数非法 | 
      | HDF_ERR_IO | I/O&nbsp;错误 | 
      | HDF_SUCCESS | 初始化成功 | 
      | HDF_FAILURE | 初始化失败 | 

      函数说明：

      MmcCntlr，HimciHost，HdfDeviceObject之间互相赋值，方便其他函数可以相互转化，初始化自定义结构体HimciHost对象，初始化MmcCntlr成员，调用核心层MmcCntlrAdd函数。

        
      ```
      static int32_t HimciMmcBind(struct HdfDeviceObject *obj)
      {
          struct MmcCntlr *cntlr = NULL;
          struct HimciHost *host = NULL;
          int32_t ret;
          cntlr = (struct MmcCntlr *)OsalMemCalloc(sizeof(struct MmcCntlr));
          host = (struct HimciHost *)OsalMemCalloc(sizeof(struct HimciHost));
          
          host->mmc = cntlr;               // 【必要】使HimciHost与MmcCntlr可以相互转化的前提
          cntlr->priv = (void *)host;      // 【必要】使HimciHost与MmcCntlr可以相互转化的前提
          cntlr->ops = &g_himciHostOps;    // 【必要】MmcCntlrOps的实例化对象的挂载
          cntlr->hdfDevObj = obj;          // 【必要】使HdfDeviceObject与MmcCntlr可以相互转化的前提
          obj->service = &cntlr->service;  // 【必要】使HdfDeviceObject与MmcCntlr可以相互转化的前提
          ret = MmcCntlrParse(cntlr, obj); // 【必要】 初始化 cntlr，失败就goto _ERR;
          ... 
          ret = HimciHostParse(host, obj); // 【必要】 初始化host对象的相关属性，失败就goto _ERR;
          ...
          ret = HimciHostInit(host, cntlr);// 厂商自定义的初始化，失败就 goto _ERR;
          ...
          ret = MmcCntlrAdd(cntlr);        // 调用核心层函数 失败就goto _ERR;
          ...
          (void)MmcCntlrAddDetectMsgToQueue(cntlr);// 将卡检测消息添加到队列中。
          HDF_LOGD("HimciMmcBind: success.");
          return HDF_SUCCESS;
      _ERR:
          HimciDeleteHost(host);
          HDF_LOGD("HimciMmcBind: fail, err = %d.", ret);
          return ret;
      }
      ```

   - Init函数参考

      入参：

      HdfDeviceObject是整个驱动对外暴露的接口参数，具备hcs配置文件的信息。

      返回值：

      HDF_STATUS相关状态。

      函数说明：

      实现ProcMciInit。

        
      ```
      static int32_t HimciMmcInit(struct HdfDeviceObject *obj)
      {
          static bool procInit = false;
          (void)obj;
          if (procInit == false) {
              if (ProcMciInit() == HDF_SUCCESS) {
                  procInit = true;
                  HDF_LOGD("HimciMmcInit: proc init success.");
              }
          }
          HDF_LOGD("HimciMmcInit: success.");
          return HDF_SUCCESS;
      }
      ```
   - Release函数参考

      入参：

      HdfDeviceObject 是整个驱动对外暴露的接口参数，具备hcs配置文件的信息。

      返回值：

      无。

      函数说明：

      释放内存和删除控制器等操作，该函数需要在驱动入口结构体中赋值给Release接口，当HDF框架调用Init函数初始化驱动失败时，可以调用 Release释放驱动资源。所有强制转换获取相应对象的操作**前提**是在Init函数中具备对应赋值的操作。

        
      ```
      static void HimciMmcRelease(struct HdfDeviceObject *obj)
      {
          struct MmcCntlr *cntlr = NULL;
          ...
          cntlr = (struct MmcCntlr *)obj->service;// 这里有HdfDeviceObject到MmcCntlr的强制转化，通过service成员，赋值见Bind函数
          ...
          HimciDeleteHost((struct HimciHost *)cntlr->priv);// 厂商自定义的内存释放函数，这里有MmcCntlr到HimciHost的强制转化
      }
      ```
