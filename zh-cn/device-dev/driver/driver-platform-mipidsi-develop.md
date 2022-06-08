# MIPI DSI


## 概述

DSI（Display Serial Interface）是由移动行业处理器接口联盟（Mobile Industry Processor Interface (MIPI) Alliance）制定的规范。在HDF框架中，MIPI DSI的接口适配模式采用无服务模式，用于不需要在用户态提供API的设备类型，或者没有用户态和内核区分的OS系统，其关联方式是DevHandle直接指向设备对象内核态地址（DevHandle是一个void类型指针）。

  **图1** DSI无服务模式结构图

  ![image](figures/无服务模式结构图.png "DSI无服务模式结构图")


## 接口说明

MipiDsiCntlrMethod定义：

  
```
struct MipiDsiCntlrMethod { // 核心层结构体的成员函数
    int32_t (*setCntlrCfg)(struct MipiDsiCntlr *cntlr);
    int32_t (*setCmd)(struct MipiDsiCntlr *cntlr, struct DsiCmdDesc *cmd);
    int32_t (*getCmd)(struct MipiDsiCntlr *cntlr, struct DsiCmdDesc *cmd, uint32_t readLen, uint8_t *out);
    void (*toHs)(struct MipiDsiCntlr *cntlr);
    void (*toLp)(struct MipiDsiCntlr *cntlr);
    void (*enterUlps)(struct MipiDsiCntlr *cntlr);// 【可选】进入超低功耗模式
    void (*exitUlps)(struct MipiDsiCntlr *cntlr); // 【可选】退出超低功耗模式
    int32_t (*powerControl)(struct MipiDsiCntlr *cntlr, uint8_t enable);//【可选】使能/去使能功耗控制
    int32_t (*attach)(struct MipiDsiCntlr *cntlr);// 【可选】将一个DSI设备连接上host
};
```

  **表1** MipiDsiCntlrMethod成员的回调函数功能说明

| 成员函数 | 入参 | 出参 | 返回状态 | 功能 | 
| -------- | -------- | -------- | -------- | -------- |
| setCntlrCfg | cntlr：结构体指针，MipiDsi控制器 | 无 | HDF_STATUS相关状态 | 设置控制器参数 | 
| setCmd | cntlr：结构体指针，MipiDsi控制器<br>cmd：结构体指针，指令传入值 | 无 | HDF_STATUS相关状态 | 向显示设备发送指令 | 
| getCmd | cntlr：结构体指针，MipiDsi控制器<br>cmd：传入的命令描述结构体指针<br>readLen：读取的数据大小 | out：结构体指针，用于存储读取的数据 | HDF_STATUS相关状态 | 通过发送指令读取数据 | 
| toHs | cntlr：结构体指针，MipiDsi控制器 | 无 | HDF_STATUS相关状态 | 设置为高速模式 | 
| toLp | cntlr：结构体指针，MipiDsi控制器 | 无 | HDF_STATUS相关状态 | 设置为低电模式 | 


## 开发步骤

MIPI DSI模块适配的三个环节是配置属性文件，实例化驱动入口，以及实例化核心层接口函数。

1. **实例化驱动入口：**
   - 实例化HdfDriverEntry结构体成员。
   - 调用HDF_INIT将HdfDriverEntry实例化对象注册到HDF框架中。

2. **配置属性文件：**
   - 在device_info.hcs文件中添加deviceNode描述。
   - 【可选】添加mipidsi_config.hcs器件属性文件。

3. **实例化MIPIDSI控制器对象：**
   - 初始化MipiDsiCntlr成员。
   - 实例化MipiDsiCntlr成员MipiDsiCntlrMethod。
      > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**<br>
      > 实例化MipiDsiCntlr成员MipiDsiCntlrMethod，其定义和成员说明见[接口说明](#接口说明)。

4. **驱动调试：**
   【可选】针对新增驱动程序，建议验证驱动基本功能，例如挂载后的信息反馈，数据传输的成功与否等。


## 开发实例

下方将以mipi_tx_hi35xx.c为示例，展示需要厂商提供哪些内容来完整实现设备功能。

1. 一般来说，驱动开发首先需要在xx_config.hcs中配置器件属性，并在device_info.hcs文件中添加deviceNode描述。器件属性值与核心层MipiDsiCntlr成员的默认值或限制范围有密切关系，deviceNode信息与驱动入口注册相关。

   但本例中MIPI控制器无需配置额外属性，如有厂商需要，则需要在device_info文件的deviceNode增加deviceMatchAttr信息，以及增加mipidsi_config文件。

     device_info.hcs 配置参考：
     
   ```
   root {
   device_info {
       match_attr = "hdf_manager";
       platform :: host {
       hostName = "platform_host";
       priority = 50;
       device_mipi_dsi:: device {
           device0 :: deviceNode {
           policy = 0;
           priority = 150;
           permission = 0644;
           moduleName = "HDF_MIPI_TX";   // 【必要】用于指定驱动名称，需要与期望的驱动Entry中的moduleName一致
           serviceName = "HDF_MIPI_TX";  // 【必要且唯一】驱动对外发布服务的名称
           }
       }
       }
   }
   }
   ```

2. 完成器件属性文件的配置之后，下一步请实例化驱动入口，驱动入口必须为HdfDriverEntry（在 hdf_device_desc.h 中定义）类型的全局变量，且moduleName要和device_info.hcs中保持一致。HdfDriverEntry结构体的函数指针成员会被厂商操作函数填充，HDF框架会将所有加载的驱动的HdfDriverEntry对象首地址汇总，形成一个类似数组，方便调用。
   一般在加载驱动时HDF框架会先调用Bind函数，再调用Init函数加载该驱动。当Init调用异常时，HDF框架会调用Release释放驱动资源并退出。

   - MIPI DSI驱动入口参考
        
      ```
      struct HdfDriverEntry g_mipiTxDriverEntry = {
          .moduleVersion = 1,             
          .Init = Hi35xxMipiTxInit,      // 见Init参考
          .Release = Hi35xxMipiTxRelease,// 见Release参考
          .moduleName = "HDF_MIPI_TX",   // 【必要】需要与device_info.hcs 中保持一致。
      };
      HDF_INIT(g_mipiTxDriverEntry);     // 调用HDF_INIT将驱动入口注册到HDF框架中
      ```

3. 完成驱动入口注册之后，最后一步就是以核心层MipiDsiCntlr对象的初始化为核心，包括厂商自定义结构体（传递参数和数据），实例化MipiDsiCntlr成员MipiDsiCntlrMethod（让用户可以通过接口来调用驱动底层函数），实现HdfDriverEntry成员函数（Bind，Init，Release）。
   - 自定义结构体参考

      从驱动的角度看，自定义结构体是参数和数据的载体，一般来说，config文件中的数值也会用来初始化结构体成员，但本例的mipidsi无器件属性文件，故基本成员结构与MipiDsiCntlr无太大差异。

        
      ```
      typedef struct {
        unsigned int    devno;                // 设备号
        short           laneId[LANE_MAX_NUM]; // lane号
        OutPutModeTag   outputMode;           // 输出模式选择:刷新模式，命令行模式和视频流模式 
        VideoModeTag    videoMode;            // 显示设备的同步模式
        OutputFormatTag outputFormat;         // 输出DSI图像数据格式：RGB或YUV
        SyncInfoTag     syncInfo;             // 时序相关的设置
        unsigned int    phyDataRate;          // 数率：mbps 
        unsigned int    pixelClk;             // 时钟：KHz
      } ComboDevCfgTag;
      
      // MipiDsiCntlr是核心层控制器结构体，其中的成员在Init函数中会被赋值
      struct MipiDsiCntlr {
        struct IDeviceIoService service;
        struct HdfDeviceObject *device;
        unsigned int devNo;          // 设备号
        struct MipiCfg cfg;
        struct MipiDsiCntlrMethod *ops;
        struct OsalMutex  lock;
        void *priv;
      };
      ```
   - MipiDsiCntlr成员回调函数结构体MipiDsiCntlrMethod的实例化，其他成员在Init函数中初始化。

        
      ```
      static struct MipiDsiCntlrMethod g_method = {
          .setCntlrCfg = Hi35xxSetCntlrCfg,
          .setCmd = Hi35xxSetCmd,
          .getCmd = Hi35xxGetCmd,
          .toHs = Hi35xxToHs,
          .toLp = Hi35xxToLp,
      };
      ```
   - Init函数参考

      入参：

      HdfDeviceObject是整个驱动对外暴露的接口参数，具备hcs配置文件的信息。

      返回值：

      HDF_STATUS相关状态 （下表为部分展示，如需使用其他状态，可见//drivers/framework/include/utils/hdf_base.h中HDF_STATUS 定义）。

      
      | 状态(值) | 问题描述 | 
      | -------- | -------- |
      | HDF_ERR_INVALID_OBJECT | 无效对象 | 
      | HDF_ERR_MALLOC_FAIL | 内存分配失败 | 
      | HDF_ERR_INVALID_PARAM | 无效参数 | 
      | HDF_ERR_IO | I/O&nbsp;错误 | 
      | HDF_SUCCESS | 执行成功 | 
      | HDF_FAILURE | 执行失败 | 

      函数说明：

      MipiDsiCntlrMethod的实例化对象的挂载，调用MipiDsiRegisterCntlr，以及其他厂商自定义初始化操作。

        
      ```
      static int32_t Hi35xxMipiTxInit(struct HdfDeviceObject *device)
      {
      int32_t ret;
      g_mipiTx.priv = NULL;    // g_mipiTx是定义的全局变量
                              // static struct MipiDsiCntlr g_mipiTx { 
                              //     .devNo=0
                              //};
      g_mipiTx.ops = &g_method;// MipiDsiCntlrMethod的实例化对象的挂载
      ret = MipiDsiRegisterCntlr(&g_mipiTx, device);// 【必要】调用核心层函数和g_mipiTx初始化核心层全局变量
      ...
      return MipiTxDrvInit(0); // 【必要】厂商对设备的初始化，形式不限
      }
      
      // mipi_dsi_core.c核心层
      int32_t MipiDsiRegisterCntlr(struct MipiDsiCntlr *cntlr, struct HdfDeviceObject *device)
      {
      ...
      // 定义的全局变量:static struct MipiDsiHandle g_mipiDsihandle[MAX_CNTLR_CNT];
      if (g_mipiDsihandle[cntlr->devNo].cntlr == NULL) {
          (void)OsalMutexInit(&g_mipiDsihandle[cntlr->devNo].lock);
          (void)OsalMutexInit(&(cntlr->lock));
      
          g_mipiDsihandle[cntlr->devNo].cntlr = cntlr;// 初始化MipiDsiHandle成员
          g_mipiDsihandle[cntlr->devNo].priv = NULL;  
          cntlr->device = device;                     // 使HdfDeviceObject与MipiDsiHandle可以相互转化的前提
          device->service = &(cntlr->service);        // 使HdfDeviceObject与MipiDsiHandle可以相互转化的前提
          cntlr->priv = NULL;    
          ...
          return HDF_SUCCESS;
      }
      ...
      return HDF_FAILURE;
      }
      ```
   - Release函数参考

      入参：

      HdfDeviceObject是整个驱动对外暴露的接口参数，具备hcs配置文件的信息。

      返回值：

      无。

      函数说明：

      该函数需要在驱动入口结构体中赋值给Release接口，当HDF框架调用Init函数初始化驱动失败时，可以调用Release释放驱动资源，该函数中需包含释放内存和删除控制器等操作。所有强制转换获取相应对象的操作前提是在Init函数中具备对应赋值的操作。

        
      ```
      static void Hi35xxMipiTxRelease(struct HdfDeviceObject *device)
      {
      struct MipiDsiCntlr *cntlr = NULL;
      ...
      cntlr = MipiDsiCntlrFromDevice(device);// 这里有HdfDeviceObject到MipiDsiCntlr的强制转化
                                              // return (device == NULL) ? NULL : (struct MipiDsiCntlr *)device->service;
      ...
      MipiTxDrvExit();                       // 【必要】对厂商设备所占资源的释放
      MipiDsiUnregisterCntlr(&g_mipiTx);     // 空函数
      g_mipiTx.priv = NULL;
      HDF_LOGI("%s: unload mipi_tx driver 1212!", __func__);
      } 
      ```
