# UART


## 概述

UART指通用异步收发传输器（Universal Asynchronous Receiver/Transmitter）。在HDF框架中，UART的接口适配模式采用独立服务模式。在这种模式下，每一个设备对象会独立发布一个设备服务来处理外部访问，设备管理器收到API的访问请求之后，通过提取该请求的参数，达到调用实际设备对象的相应内部方法的目的。独立服务模式可以直接借助HDFDeviceManager的服务管理能力，但需要为每个设备单独配置设备节点，增加内存占用。

  **图1** UART独立服务模式结构图

  ![image](figures/独立服务模式结构图.png "UART独立服务模式结构图")


## 接口说明

UartHostMethod定义：

  
```
struct UartHostMethod {
  int32_t (*Init)(struct UartHost *host);
  int32_t (*Deinit)(struct UartHost *host);
  int32_t (*Read)(struct UartHost *host, uint8_t *data, uint32_t size);
  int32_t (*Write)(struct UartHost *host, uint8_t *data, uint32_t size);
  int32_t (*GetBaud)(struct UartHost *host, uint32_t *baudRate);
  int32_t (*SetBaud)(struct UartHost *host, uint32_t baudRate);
  int32_t (*GetAttribute)(struct UartHost *host, struct UartAttribute *attribute);
  int32_t (*SetAttribute)(struct UartHost *host, struct UartAttribute *attribute);
  int32_t (*SetTransMode)(struct UartHost *host, enum UartTransMode mode);
  int32_t (*pollEvent)(struct UartHost *host, void *filep, void *table);
};
```

  **表1** UartHostMethod结构体成员的回调函数功能说明

| 函数 | 入参 | 出参 | 返回值 | 功能 | 
| -------- | -------- | -------- | -------- | -------- |
| Init | host：&nbsp;结构体指针，核心层UART控制器 | 无 | HDF_STATUS相关状态 | 初始化Uart设备 | 
| Deinit | host：&nbsp;结构体指针，核心层UART控制器 | 无 | HDF_STATUS相关状态 | 去初始化Uart设备 | 
| Read | host：&nbsp;结构体指针，核心层UART控制器<br>size：uint32_t，数据大小 | data：&nbsp;uint8_t指针，传出的数据 | HDF_STATUS相关状态 | 接收数据RX | 
| Write | host：&nbsp;结构体指针，核心层UART控制器<br>data：uint8_t指针，传入数据<br>size：uint32_t，数据大小 | 无 | HDF_STATUS相关状态 | 发送数据TX | 
| SetBaud | host：&nbsp;结构体指针，核心层UART控制器<br>baudRate：&nbsp;uint32_t指针，波特率传入值 | 无 | HDF_STATUS相关状态 | 设置波特率 | 
| GetBaud | host：&nbsp;结构体指针，核心层UART控制器 | baudRate：&nbsp;uint32_t指针，传出的波特率 | HDF_STATUS相关状态 | 获取当前设置的波特率 | 
| GetAttribute | host：&nbsp;结构体指针，核心层UART控制器 | attribute：&nbsp;结构体指针，传出的属性值（见uart_if.h中UartAttribute定义） | HDF_STATUS相关状态 | 获取设备uart相关属性 | 
| SetAttribute | host：&nbsp;结构体指针，核心层UART控制器<br>attribute：&nbsp;结构体指针，属性传入值 | 无 | HDF_STATUS相关状态 | 设置设备UART相关属性 | 
| SetTransMode | host：&nbsp;结构体指针，核心层UART控制器<br>mode：&nbsp;枚举值（见uart_if.h中UartTransMode定义），传输模式 | 无 | HDF_STATUS相关状态 | 设置传输模式 | 
| PollEvent | host：&nbsp;结构体指针，核心层UART控制器<br>filep：&nbsp;void&nbsp;指针file<br>table：&nbsp;void&nbsp;指针poll_table | 无 | HDF_STATUS相关状态 | poll机制 | 


## 开发步骤

UART模块适配HDF框架的三个环节是配置属性文件，实例化驱动入口，以及实例化核心层接口函数。

1. **实例化驱动入口：**
   - 实例化HdfDriverEntry结构体成员。
   - 调用HDF_INIT将HdfDriverEntry实例化对象注册到HDF框架中。

2. **配置属性文件：**
   - 在device_info.hcs文件中添加deviceNode描述。
   - 【可选】添加uart_config.hcs器件属性文件。

3. **实例化UART控制器对象：**
   - 初始化UartHost成员。
   - 实例化UartHost成员UartHostMethod。
      > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**<br>
      > 实例化UartHost成员UartHostMethod，其定义和成员说明见[接口说明](#接口说明)。

4. **驱动调试：**
   【可选】针对新增驱动程序，建议验证驱动基本功能，例如UART控制状态，中断响应情况等。


## 开发实例

下方将以uart_hi35xx.c为示例，展示需要厂商提供哪些内容来完整实现设备功能。

1. 驱动开发首先需要实例化驱动入口，驱动入口必须为HdfDriverEntry（在 hdf_device_desc.h 中定义）类型的全局变量，且moduleName要和device_info.hcs中保持一致。HDF框架会将所有加载的驱动的HdfDriverEntry对象首地址汇总，形成一个类似数组的段地址空间，方便上层调用。
   一般在加载驱动时HDF会先调用Bind函数，再调用Init函数加载该驱动。当Init调用异常时，HDF框架会调用Release释放驱动资源并退出。

     UART驱动入口参考：
     
   ```
   struct HdfDriverEntry g_hdfUartDevice = {
       .moduleVersion = 1,
       .moduleName = "HDF_PLATFORM_UART",// 【必要且与HCS里面的名字匹配】
       .Bind = HdfUartDeviceBind,        // 见Bind参考
       .Init = HdfUartDeviceInit,        // 见Init参考
       .Release = HdfUartDeviceRelease,  // 见Release参考
   };
   //调用HDF_INIT将驱动入口注册到HDF框架中
   HDF_INIT(g_hdfUartDevice);
   ```

2. 完成驱动入口注册之后，下一步请在device_info.hcs文件中添加deviceNode信息，并在 uart_config.hcs 中配置器件属性。deviceNode信息与驱动入口注册相关，器件属性值与核心层UartHost成员的默认值或限制范围有密切关系。
     本例只有一个UART控制器，如有多个器件信息，则需要在device_info文件增加deviceNode信息，以及在uart_config文件中增加对应的器件属性。
   - device_info.hcs 配置参考：
   
       
     ```
     root {
       device_info {
         match_attr = "hdf_manager";
         platform :: host {
           hostName = "platform_host";
           priority = 50;
           device_uart :: device {
             device0 :: deviceNode {
               policy = 1;                         // 驱动服务发布的策略，policy大于等于1（用户态可见为2，仅内核态可见为1）；
               priority = 40;                      // 驱动启动优先级
               permission = 0644;                  // 驱动创建设备节点权限
               moduleName = "HDF_PLATFORM_UART";   // 驱动名称，该字段的值必须和驱动入口结构的moduleName值一致
               serviceName = "HDF_PLATFORM_UART_0";// 驱动对外发布服务的名称，必须唯一，必须要按照HDF_PLATFORM_UART_X的格式，X为UART控制器编号
               deviceMatchAttr = "hisilicon_hi35xx_uart_0";// 驱动私有数据匹配的关键字，必须和驱动私有数据配置表中的match_attr值一致
             }
             device1 :: deviceNode {
               policy = 2;
               permission = 0644;
               priority = 40;
               moduleName = "HDF_PLATFORM_UART"; 
               serviceName = "HDF_PLATFORM_UART_1";
               deviceMatchAttr = "hisilicon_hi35xx_uart_1";
             }
             ...
           }
         }
       }
     }
     ```
   
   - uart_config.hcs 配置参考：
   
       
     ```
     root {
       platform {
         template uart_controller {// 模板公共参数，继承该模板的节点如果使用模板中的默认值，则节点字段可以缺省
           match_attr = "";
           num = 0;                // 【必要】设备号
           baudrate = 115200;      // 【必要】波特率，数值可按需填写
           fifoRxEn = 1;           // 【必要】使能接收FIFO
           fifoTxEn = 1;           // 【必要】使能发送FIFO
           flags = 4;              // 【必要】标志信号
           regPbase = 0x120a0000;  // 【必要】地址映射需要
           interrupt = 38;         // 【必要】中断号
           iomemCount = 0x48;      // 【必要】地址映射需要
         }
         controller_0x120a0000 :: uart_controller {
           match_attr = "hisilicon_hi35xx_uart_0";// 【必要】必须和device_info.hcs中对应的设备的deviceMatchAttr值一致
         }
         controller_0x120a1000 :: uart_controller {
           num = 1;
           baudrate = 9600;
           regPbase = 0x120a1000;
           interrupt = 39;
           match_attr = "hisilicon_hi35xx_uart_1";
         }
         ...
         // 【可选】可新增，但需要在 device_info.hcs 添加对应的节点
       }
     }
     ```

3. 完成驱动入口注册之后，最后一步就是以核心层UartHost对象的初始化为核心，包括厂商自定义结构体（传递参数和数据），实例化UartHost成员UartHostMethod（让用户可以通过接口来调用驱动底层函数），实现HdfDriverEntry成员函数（Bind，Init，Release）。
   - 自定义结构体参考

      从驱动的角度看，自定义结构体是参数和数据的载体，而且uart_config.hcs文件中的数值会被HDF读入通过DeviceResourceIface来初始化结构体成员，一些重要数值也会传递给核心层对象，例如设备号等。

        
      ```
      struct UartPl011Port {                  // 接口相关的结构体
          int32_t             enable;
          unsigned long       physBase;       // 物理地址
          uint32_t            irqNum;         // 中断号
          uint32_t            defaultBaudrate;// 默认波特率
          uint32_t            flags;          // 标志信号，下面三个宏与之相关
      #define PL011_FLG_IRQ_REQUESTED    (1 << 0)
      #define PL011_FLG_DMA_RX_REQUESTED (1 << 1)
      #define PL011_FLG_DMA_TX_REQUESTED (1 << 2)
          struct UartDmaTransfer  *rxUdt;     // DMA传输相关
          struct UartDriverData   *udd;       // 见下
      };
      struct UartDriverData {                 // 数据传输相关的结构体
          uint32_t num;
          uint32_t baudrate;                  // 波特率（可设置）
          struct UartAttribute attr;          // 数据位、停止位等传输属性相关
          struct UartTransfer *rxTransfer;    // 缓冲区相关，可理解为FIFO结构
          wait_queue_head_t wait;             // 条件变量相关的排队等待信号
          int32_t count;                      // 数据数量
          int32_t state;                      // UART控制器状态
      #define UART_STATE_NOT_OPENED 0
      #define UART_STATE_OPENING    1
      #define UART_STATE_USEABLE    2
      #define UART_STATE_SUSPENED   3
          uint32_t flags;                     // 状态标志
      #define UART_FLG_DMA_RX       (1 << 0)
      #define UART_FLG_DMA_TX       (1 << 1)
      #define UART_FLG_RD_BLOCK     (1 << 2)
          RecvNotify recv;                    // 函数指针类型，指向串口数据接收函数
          struct UartOps *ops;                // 自定义函数指针结构体，详情见device/hisilicon/drivers/uart/uart_pl011.c
          void *private;                      // 一般用来存储UartPl011Port首地址，方便调用
      };
      
      // UartHost是核心层控制器结构体，其中的成员在Init函数中会被赋值
      struct UartHost {
          struct IDeviceIoService service;
          struct HdfDeviceObject *device;
          uint32_t num;
          OsalAtomic atom;
          void *priv;                         // 一般存储厂商自定义结构体首地址，方便后者被调用
          struct UartHostMethod *method;      // 核心层钩子函数，厂商需要实现其成员函数功能并实例化
      };
      ```
   - UartHost成员回调函数结构体UartHostMethod的实例化，其他成员在Bind函数中初始化。

        
      ```
      // uart_hi35xx.c 中的示例：钩子函数的实例化
      struct UartHostMethod g_uartHostMethod = {
        .Init = Hi35xxInit,
        .Deinit = Hi35xxDeinit,
        .Read = Hi35xxRead,
        .Write = Hi35xxWrite,
        .SetBaud = Hi35xxSetBaud,
        .GetBaud = Hi35xxGetBaud,
        .SetAttribute = Hi35xxSetAttribute,
        .GetAttribute = Hi35xxGetAttribute,
        .SetTransMode = Hi35xxSetTransMode,
        .pollEvent = Hi35xxPollEvent,
      };
      ```

   - Bind函数参考

      入参：

      HdfDeviceObject是整个驱动对外暴露的接口参数，具备HCS配置文件的信息。

      返回值：

      HDF_STATUS相关状态（下表为部分展示，如需使用其他状态，可参见//drivers/framework/include/utils/hdf_base.h中HDF_STATUS定义）。

        **表2** HDF_STATUS返回值说明
      
      | 状态(值) | 问题描述 | 
      | -------- | -------- |
      | HDF_ERR_INVALID_OBJECT | 控制器对象非法 | 
      | HDF_ERR_MALLOC_FAIL | 内存分配失败 | 
      | HDF_ERR_INVALID_PARAM | 参数非法 | 
      | HDF_ERR_IO | I/O&nbsp;错误 | 
      | HDF_SUCCESS | 初始化成功 | 
      | HDF_FAILURE | 初始化失败 | 

      函数说明：

      初始化自定义结构体对象，初始化UartHost成员。

        
      ```
      //uart_hi35xx.c
      static int32_t HdfUartDeviceBind(struct HdfDeviceObject *device)
      {
          ...
          return (UartHostCreate(device) == NULL) ? HDF_FAILURE : HDF_SUCCESS;// 【必须做】调用核心层函数UartHostCreate
      }
      // uart_core.c核心层UartHostCreate函数说明
      struct UartHost *UartHostCreate(struct HdfDeviceObject *device)
      {
          struct UartHost *host = NULL;                          // 新建UartHost
          ...
          host = (struct UartHost *)OsalMemCalloc(sizeof(*host));//分配内存
          ...
          host->device = device;                           // 【必要】使HdfDeviceObject与UartHost可以相互转化的前提
          device->service = &(host->service);              // 【必要】使HdfDeviceObject与UartHost可以相互转化的前提
          host->device->service->Dispatch = UartIoDispatch;// 为service成员的Dispatch方法赋值    
          OsalAtomicSet(&host->atom, 0);                   // 原子量初始化或者原子量设置
          host->priv = NULL;
          host->method = NULL;
          return host;
      }
      ```

   - Init函数参考

      入参：

      HdfDeviceObject是整个驱动对外暴露的接口参数，具备HCS配置文件的信息。

      返回值：

      HDF_STATUS相关状态。

      函数说明：

      初始化自定义结构体对象，初始化UartHost成员，调用核心层UartAddDev函数，接入VFS。

        
      ```
      int32_t HdfUartDeviceInit(struct HdfDeviceObject *device)
      {
          int32_t ret;
          struct UartHost *host = NULL;
          HDF_LOGI("%s: entry", __func__);
          ...
          host = UartHostFromDevice(device);// 通过service成员后强制转为UartHost，赋值是在Bind函数中
          ...
          ret = Hi35xxAttach(host, device); // 完成UartHost对象的初始化，见下
          ...
          host->method = &g_uartHostMethod; // UartHostMethod的实例化对象的挂载
          return ret;
      }
      // 完成 UartHost 对象的初始化
      static int32_t Hi35xxAttach(struct UartHost *host, struct HdfDeviceObject *device)
      {
          int32_t ret;
          // udd和port对象是厂商自定义的结构体对象，可根据需要实现相关功能
          struct UartDriverData *udd = NULL;
          struct UartPl011Port *port = NULL;
          ...
          // 【必要】步骤【1】~【7】主要实现对 udd 对象的实例化赋值，然后赋值给核心层UartHost对象
          udd = (struct UartDriverData *)OsalMemCalloc(sizeof(*udd));//【1】
          ...
          port = (struct UartPl011Port *)OsalMemCalloc(sizeof(struct UartPl011Port));//【2】
          ...
          udd->ops = Pl011GetOps();       // 【3】设备开启、关闭、属性设置、发送操作等函数挂载
          udd->recv = PL011UartRecvNotify;// 【4】数据接收通知函数（条件锁机制）挂载
          udd->count = 0;          // 【5】
          port->udd = udd;         // 【6】使UartPl011Port与UartDriverData可以相互转化的前提
          ret = UartGetConfigFromHcs(port, device->property);// 将HdfDeviceObject的属性传递给厂商自定义结构体
                                                             // 用于相关操作，示例代码见下
          ...
          udd->private = port;     //【7】
          
          host->priv = udd;        // 【必要】使UartHost与UartDriverData可以相互转化的前提
          host->num = udd->num;    // 【必要】UART设备号
          UartAddDev(host);        // 【必要】核心层uart_dev.c 中的函数，作用：注册一个字符设备节点到vfs，这样从用户态可以通过这个虚拟文件节点访问UART    
          return HDF_SUCCESS;
      }
      
      static int32_t UartGetConfigFromHcs(struct UartPl011Port *port, const struct DeviceResourceNode *node)
      {
          uint32_t tmp, regPbase, iomemCount;
          struct UartDriverData *udd = port->udd;
          struct DeviceResourceIface *iface = DeviceResourceGetIfaceInstance(HDF_CONFIG_SOURCE); 
          ...
          // 通过请求参数提取相应的值，并赋值给厂商自定义的结构体
          if (iface->GetUint32(node, "num", &udd->num, 0) != HDF_SUCCESS) {
              HDF_LOGE("%s: read busNum fail", __func__);
              return HDF_FAILURE;
          }
          ...
          return 0;
          }
      ```
   - Release函数参考

      入参：

      HdfDeviceObject是整个驱动对外暴露的接口参数，具备HCS配置文件的信息。

      返回值：

      无。

      函数说明：

      该函数需要在驱动入口结构体中赋值给Release接口，当HDF框架调用Init函数初始化驱动失败时，可以调用Release释放驱动资源，该函数中需包含释放内存和删除控制器等操作。所有强制转换获取相应对象的操作前提是在Init函数中具备对应赋值的操作。

        
      ```
      void HdfUartDeviceRelease(struct HdfDeviceObject *device)
      {
          struct UartHost *host = NULL;
          ...
          host = UartHostFromDevice(device);// 这里有HdfDeviceObject到UartHost的强制转化，通过service成员，赋值见Bind函数
          ...
          if (host->priv != NULL) {
              Hi35xxDetach(host);           // 厂商自定义的内存释放函数，见下
          }
          UartHostDestroy(host);            // 调用核心层函数释放host
      }
      
      static void Hi35xxDetach(struct UartHost *host)
      {
          struct UartDriverData *udd = NULL;
          struct UartPl011Port *port = NULL;
          ...
          udd = host->priv;   // 这里有UartHost到UartDriverData的转化
          ...
          UartRemoveDev(host);// VFS注销
          port = udd->private;// 这里有UartDriverData到UartPl011Port的转化
          if (port != NULL) {
              if (port->physBase != 0) {
                  OsalIoUnmap((void *)port->physBase);// 地址反映射
              }
              OsalMemFree(port);
              udd->private = NULL;
          }
          OsalMemFree(udd);// 释放UartDriverData
          host->priv = NULL;
      }
      ```
