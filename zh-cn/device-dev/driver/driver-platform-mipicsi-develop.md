# MIPI CSI

## 概述 <a name="section1_MIPI_CSIDevelop"></a>

CSI（Camera Serial Interface）是由MIPI（Mobile Industry Processor Interface）联盟下Camera工作组指定的接口标准。在HDF框架中，MIPI CSI的接口适配模式采用无服务模式，用于不需要在用户态提供API的设备类型，或者没有用户态和内核区分的OS系统，MIPI CSI的接口关联方式是DevHandle直接指向设备对象内核态地址（DevHandle是一个void类型指针）。

图 1 无服务模式结构图

![image1](figures/无服务模式结构图.png)

## 接口说明 <a name="section2_MIPI_CSIDevelop"></a>

MipiCsiCntlrMethod定义

```c
struct MipiCsiCntlrMethod {
    int32_t (*setComboDevAttr)(struct MipiCsiCntlr *cntlr, ComboDevAttr *pAttr);
    int32_t (*setPhyCmvmode)(struct MipiCsiCntlr *cntlr, uint8_t devno, PhyCmvMode cmvMode);
    int32_t (*setExtDataType)(struct MipiCsiCntlr *cntlr, ExtDataType* dataType);
    int32_t (*setHsMode)(struct MipiCsiCntlr *cntlr, LaneDivideMode laneDivideMode);
    int32_t (*enableClock)(struct MipiCsiCntlr *cntlr, uint8_t comboDev);
    int32_t (*disableClock)(struct MipiCsiCntlr *cntlr, uint8_t comboDev);
    int32_t (*resetRx)(struct MipiCsiCntlr *cntlr, uint8_t comboDev);
    int32_t (*unresetRx)(struct MipiCsiCntlr *cntlr, uint8_t comboDev);
    int32_t (*enableSensorClock)(struct MipiCsiCntlr *cntlr, uint8_t snsClkSource);
    int32_t (*disableSensorClock)(struct MipiCsiCntlr *cntlr, uint8_t snsClkSource);
    int32_t (*resetSensor)(struct MipiCsiCntlr *cntlr, uint8_t snsResetSource);
    int32_t (*unresetSensor)(struct MipiCsiCntlr *cntlr, uint8_t snsResetSource);
};
```
表1 MipiCsiCntlrMethod成员的回调函数功能说明
| 成员函数           | 入参                                                         | 出参 | 返回状态           | 功能                       |
| ------------------ | ------------------------------------------------------------ | ---- | ------------------ | -------------------------- |
| setComboDevAttr    | **cntlr**：结构体指针，MipiCsi控制器 ;<br>**pAttr**：结构体指针，MIPI CSI相应配置结构体指针 | 无   | HDF_STATUS相关状态 | 写入MIPI CSI配置           |
| setPhyCmvmode      | **cntlr**：结构体指针，MipiCsi控制器 ;<br>**devno**：uint8_t，设备编号;<br>**cmvMode**：枚举类型，共模电压模式参数 | 无   | HDF_STATUS相关状态 | 设置共模电压模式           |
| setExtDataType     | **cntlr**：结构体指针，MipiCsi控制器 ;<br>**dataType**：结构体指针，定义YUV和原始数据格式以及位深度 | 无   | HDF_STATUS相关状态 | 设置YUV和RAW数据格式和位深 |
| setHsMode          | **cntlr**：结构体指针，MipiCsi控制器 ;<br>**laneDivideMode**：枚举类型，lane模式参数 | 无   | HDF_STATUS相关状态 | 设置MIPI RX的Lane分布     |
| enableClock        | **cntlr**：结构体指针，MipiCsi控制器 ;<br>**comboDev**：uint8_t，通路序号 | 无   | HDF_STATUS相关状态 | 使能MIPI的时钟             |
| disableClock       | **cntlr**：结构体指针，MipiCsi控制器 ;<br/>**comboDev**：uint8_t，通路序号 | 无   | HDF_STATUS相关状态 | 关闭MIPI的时钟             |
| resetRx            | **cntlr**：结构体指针，MipiCsi控制器 ;<br/>**comboDev**：uint8_t，通路序号 | 无   | HDF_STATUS相关状态 | 复位MIPI RX                |
| unresetRx          | **cntlr**：结构体指针，MipiCsi控制器 ;<br/>**comboDev**：uint8_t，通路序号 | 无   | HDF_STATUS相关状态 | 撤销复位MIPI RX            |
| enableSensorClock  | **cntlr**：结构体指针，MipiCsi控制器 ;<br/>**snsClkSource**：uint8_t，传感器的时钟信号线号 | 无   | HDF_STATUS相关状态 | 使能MIPI上的Sensor时钟     |
| disableSensorClock | **cntlr**：结构体指针，MipiCsi控制器 ;<br/>**snsClkSource**：uint8_t，传感器的时钟信号线号 | 无   | HDF_STATUS相关状态 | 关闭MIPI上的Sensor时钟     |
| resetSensor        | **cntlr**：结构体指针，MipiCsi控制器 ;<br/>**snsClkSource**：uint8_t，传感器的时钟信号线号 | 无   | HDF_STATUS相关状态 | 复位Sensor                 |
| unresetSensor      | **cntlr**：结构体指针，MipiCsi控制器 ;<br/>**snsClkSource**：uint8_t，传感器的时钟信号线号 | 无   | HDF_STATUS相关状态 | 撤销复位Sensor      |   

## 开发步骤 <a name="section3_MIPI_CSIDevelop"></a>

MIPI CSI模块适配的三个环节是配置属性文件、实例化驱动入、以及实例化核心层接口函数。

1. **实例化驱动入口：**   
   - 实例化HdfDriverEntry结构体成员。
   - 调用HDF_INIT将HdfDriverEntry实例化对象注册到HDF框架中。
   
2. **配置属性文件：**   

   - 在device_info.hcs文件中添加deviceNode描述。
   - 【可选】添加mipicsi_config.hcs器件属性文件。

3. **实例化MIPICSI控制器对象：**   
   - 初始化MipiCsiCntlr成员。
   - 实例化MipiCsiCntlr成员MipiCsiCntlrMethod。
     >![](../public_sys-resources/icon-note.gif) **说明：**<br>
     >实例化MipiCsiCntlr成员MipiCsiCntlrMethod，其定义和成员说明见[接口说明](#section2_MIPI_CSIDevelop)。
   
4. **驱动调试：**
   - 【可选】针对新增驱动程序，建议验证驱动基本功能，例如挂载后的信息反馈，数据传输的成功与否等。


## 开发实例 <a name="section4_MIPI_CSIDevelop"></a>

下方将以mipi_rx_hi35xx.c为示例，展示需要厂商提供哪些内容来完整实现设备功能。


1. 一般来说，驱动开发首先需要在 busxx_config.hcs 中配置器件属性，并在device_info.hcs文件中添加deviceNode描述。器件属性值与核心层MipiCsiCntlr 成员的默认值或限制范围有密切关系，deviceNode信息与驱动入口注册相关。

   **本例中MIPI控制器自身属性在源文件文件中，如有厂商需要，则在device_info文件的deviceNode增加deviceMatchAttr信息，相应增加mipicsi_config.hcs文件**。

- device_info.hcs 配置参考

  ```c
  root {
  device_info {
      match_attr = "hdf_manager";
      platform :: host {
      hostName = "platform_host";
      priority = 50;
      device_mipi_csi:: device {
      	device0 :: deviceNode {
              policy = 0;
              priority = 160;
              permission = 0644;
              moduleName = "HDF_MIPI_RX";    // 【必要】用于指定驱动名称，需要与期望的驱动Entry中的moduleName一致；
              serviceName = "HDF_MIPI_RX";   // 【必要且唯一】驱动对外发布服务的名称
          }
      }
      }
  }
  }
  ```

2. 完成器件属性文件的配置之后，下一步请实例化驱动入口，驱动入口必须为HdfDriverEntry（在 hdf_device_desc.h 中定义）类型的全局变量，且moduleName要和device_info.hcs中保持一致。HdfDriverEntry结构体的函数指针成员会被厂商操作函数填充，HDF框架会将所有加载的驱动的HdfDriverEntry对象首地址汇总，形成一个类似数组，方便调用。

   一般在加载驱动时HDF框架会先调用Bind函数，再调用Init函数加载该驱动。当Init调用异常时，HDF框架会调用Release释放驱动资源并退出。

- MIPI CSI驱动入口参考

  ```c 
  struct HdfDriverEntry g_mipiCsiDriverEntry = {
      .moduleVersion = 1,
      .Init = Hi35xxMipiCsiInit,          // 见Init参考
      .Release = Hi35xxMipiCsiRelease,    // 见Release参考
      .moduleName = "HDF_MIPI_RX",        // 【必要】需要与device_info.hcs 中保持一致。
  };
  HDF_INIT(g_mipiCsiDriverEntry);         // 调用HDF_INIT将驱动入口注册到HDF框架中
  ```

3.  完成驱动入口注册之后，最后一步就是以核心层MipiCsiCntlr对象的初始化为核心，实现HdfDriverEntry成员函数（Bind，Init，Release）。MipiCsiCntlr对象的初始化包括厂商自定义结构体（用于传递参数和数据）和实例化MipiCsiCntlr成员MipiCsiCntlrMethod（让用户可以通过接口来调用驱动底层函数）。

- 自定义结构体参考 

  从驱动的角度看，自定义结构体是参数和数据的载体，一般来说，config文件中的数值也会用来初始化结构体成员，本例的mipicsi器件属性在源文件中，故基本成员结构与MipiCsiCntlr无太大差异。

  ```c
  typedef struct {
      /** 数据类型：8/10/12/14/16位 */
      DataType inputDataType;
      /** MIPI波分复用模式 */
      MipiWdrMode wdrMode;
      /** laneId: -1 - 禁用 */
      short laneId[MIPI_LANE_NUM];
  
      union {
          /** 用于 HI_MIPI_WDR_MODE_DT */
          short dataType[WDR_VC_NUM];
      };
  } MipiDevAttr;
  
  typedef struct {
      /** 设备号 */
      uint8_t devno;
      /** 输入模式: MIPI/LVDS/SUBLVDS/HISPI/DC */
      InputMode inputMode;
      MipiDataRate dataRate;
      /** MIPI Rx设备裁剪区域（与原始传感器输入图像大小相对应） */
      ImgRect imgRect;
  
      union {
          MipiDevAttr mipiAttr;
          LvdsDevAttr lvdsAttr;
      };
  } ComboDevAttr;
  
  //MipiCsiCntlr是核心层控制器结构体，其中的成员在Init函数中会被赋值
  struct MipiCsiCntlr {
      /** 当驱动程序绑定到HDF框架时，将发送此控制器提供的服务 */
      struct IDeviceIoService service;
      /** 当驱动程序绑定到HDF框架时，将传入设备端指针 */
      struct HdfDeviceObject *device;
      /** 设备号 */
      unsigned int devNo;
      /** 控制器提供的所有接口 */
      struct MipiCsiCntlrMethod *ops;
      /** 对于控制器调试的所有接口，如果未实现驱动程序，则需要null */
      struct MipiCsiCntlrDebugMethod *debugs;
      /** 控制器上下文参数变量 */
      MipiDevCtx ctx;
      /** 访问控制器上下文参数变量时锁定 */
      OsalSpinlock ctxLock;
      /** 操作控制器时锁定方法 */
      struct OsalMutex lock;
      /** 匿名数据指针，用于存储csi设备结构 */
      void *priv;
  };
  ```

- **【重要】** MipiCsiCntlr成员回调函数结构体MipiCsiCntlrMethod的实例化，其他成员在Init函数中初始化。

  ```c 
  static struct MipiCsiCntlrMethod g_method = {
      .setComboDevAttr = Hi35xxSetComboDevAttr,
      .setPhyCmvmode = Hi35xxSetPhyCmvmode,
      .setExtDataType = Hi35xxSetExtDataType,
      .setHsMode = Hi35xxSetHsMode,
      .enableClock = Hi35xxEnableClock,
      .disableClock = Hi35xxDisableClock,
      .resetRx = Hi35xxResetRx,
      .unresetRx = Hi35xxUnresetRx,
      .enableSensorClock = Hi35xxEnableSensorClock,
      .disableSensorClock = Hi35xxDisableSensorClock,
      .resetSensor = Hi35xxResetSensor,
      .unresetSensor = Hi35xxUnresetSensor
  };
  ```

- **Init函数参考**

   **入参：** 
   HdfDeviceObject 是整个驱动对外暴露的接口参数，具备hcs配置文件的信息
  
   **返回值：**
   HDF_STATUS相关状态（下表为部分展示，如需使用其他状态，可见//drivers/framework/include/utils/hdf_base.h中HDF_STATUS 定义）

  
   | 状态(值)               |   问题描述   |
   | :--------------------- | :----------: |
   | HDF_ERR_INVALID_OBJECT |   无效对象   |
   | HDF_ERR_MALLOC_FAIL    | 内存分配失败 |
   | HDF_ERR_INVALID_PARAM  |   无效参数   |
   | HDF_ERR_IO             |   I/O 错误   |
   | HDF_SUCCESS            |   执行成功   |
   | HDF_FAILURE            |   执行失败   |
  
   **函数说明：**
   MipiCsiCntlrMethod的实例化对象的挂载，调用MipiCsiRegisterCntlr，以及其他厂商自定义初始化操作。


  ```c 
  static int32_t Hi35xxMipiCsiInit(struct HdfDeviceObject *device)
  {
      int32_t ret;
  
      HDF_LOGI("%s: enter!", __func__);
      g_mipiCsi.priv = NULL;		// g_mipiTx是定义的全局变量
      							// static struct MipiCsiCntlr g_mipiCsi = {
      							// .devNo = 0
  								//};
      g_mipiCsi.ops = &g_method;	//MipiCsiCntlrMethod的实例化对象的挂载
  #ifdef CONFIG_HI_PROC_SHOW_SUPPORT
      g_mipiCsi.debugs = &g_debugMethod;
  #endif
      ret = MipiCsiRegisterCntlr(&g_mipiCsi, device);	// 【必要】调用核心层函数和g_mipiTx初始化核心层全局变量
      if (ret != HDF_SUCCESS) {
          HDF_LOGE("%s: [MipiCsiRegisterCntlr] failed!", __func__);
          return ret;
      }
  
      ret = MipiRxDrvInit(); // 【必要】厂商对设备的初始化，形式不限
      if (ret != HDF_SUCCESS) {
          HDF_LOGE("%s: [MipiRxDrvInit] failed.", __func__);
          return ret;
      }
  #ifdef MIPICSI_VFS_SUPPORT
      ret = MipiCsiDevModuleInit(g_mipiCsi.devNo);
      if (ret != HDF_SUCCESS) {
          HDF_LOGE("%s: [MipiCsiDevModuleInit] failed!", __func__);
          return ret;
      }
  #endif
  
      OsalSpinInit(&g_mipiCsi.ctxLock);
      HDF_LOGI("%s: load mipi csi driver success!", __func__);
  
      return ret;
  }
  
  //mipi_dsi_core.c核心层
  int32_t MipiCsiRegisterCntlr(struct MipiCsiCntlr *cntlr, struct HdfDeviceObject *device)
  {
  ...
  //定义的全局变量:static struct MipiCsiHandle g_mipiCsihandle[MAX_CNTLR_CNT];
      if (g_mipiCsihandle[cntlr->devNo].cntlr == NULL) {
          (void)OsalMutexInit(&g_mipiCsihandle[cntlr->devNo].lock);
          (void)OsalMutexInit(&(cntlr->lock));
  
          g_mipiCsihandle[cntlr->devNo].cntlr = cntlr;	// 初始化MipiCsiHandle成员
          g_mipiCsihandle[cntlr->devNo].priv = NULL;
          cntlr->device = device;							// 使HdfDeviceObject与MipiCsiHandle可以相互转化的前提
          device->service = &(cntlr->service);			// 使HdfDeviceObject与MipiCsiHandle可以相互转化的前提
          cntlr->priv = NULL;
          HDF_LOGI("%s: success.", __func__);
  
          return HDF_SUCCESS;
      }
  
      HDF_LOGE("%s: cntlr already exists.", __func__);
      return HDF_FAILURE;
  }
  ```

- **Release函数参考**

   **入参：** 
   HdfDeviceObject 是整个驱动对外暴露的接口参数，具备 HCS 配置文件的信息。
  
   **返回值：**
   无
  
   **函数说明：**
   该函数需要在驱动入口结构体中赋值给Release接口，当HDF框架调用Init函数初始化驱动失败时，可以调用Release释放驱动资源，该函数中需包含释放内存和删除控制器等操作。所有强制转换获取相应对象的操作**前提**是在Init函数中具备对应赋值的操作。

  ```c
  static void Hi35xxMipiCsiRelease(struct HdfDeviceObject *device)
  {
      struct MipiCsiCntlr *cntlr = NULL;
  	...
      cntlr = MipiCsiCntlrFromDevice(device);	// 这里有HdfDeviceObject到MipiCsiCntlr的强制转化
                                          	// return (device == NULL) ? NULL : (struct MipiCsiCntlr *)device->service;
  	...
  
      OsalSpinDestroy(&cntlr->ctxLock);
  #ifdef MIPICSI_VFS_SUPPORT
      MipiCsiDevModuleExit(cntlr->devNo);
  #endif
      MipiRxDrvExit();						// 【必要】对厂商设备所占资源的释放
      MipiCsiUnregisterCntlr(&g_mipiCsi);		// 空函数
      g_mipiCsi.priv = NULL;
  
      HDF_LOGI("%s: unload mipi csi driver success!", __func__);
  }
  ```

