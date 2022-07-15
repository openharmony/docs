# I2C


## 概述

I2C（Inter Integrated Circuit）总线是由Philips公司开发的一种简单、双向二线制同步串行总线,在HDF框架中，I2C模块接口适配模式采用统一服务模式，这需要一个设备服务来作为I2C模块的管理器，统一处理外部访问，这会在配置文件中有所体现。统一服务模式适合于同类型设备对象较多的情况，如I2C可能同时具备十几个控制器，采用独立服务模式需要配置更多的设备节点，且服务会占据内存资源。

  **图1** I2C统一服务模式结构图

  ![image](figures/统一服务模式结构图.png "I2C统一服务模式结构图")


## 接口说明

I2cMethod和I2cLockMethod定义：

  
```
struct I2cMethod {
int32_t (*transfer)(struct I2cCntlr *cntlr, struct I2cMsg *msgs, int16_t count);
};
struct I2cLockMethod {// 锁机制操作结构体
    int32_t (*lock)(struct I2cCntlr *cntlr);// 加锁
    void (*unlock)(struct I2cCntlr *cntlr); // 解锁
};
```

  **表1** I2cMethod结构体成员的回调函数功能说明

| 函数成员 | 入参 | 出参 | 返回值 | 功能 | 
| -------- | -------- | -------- | -------- | -------- |
| transfer | cntlr：结构体指针，核心层I2C控制器。<br>msgs：结构体指针，用户消息。<br>count：uint16_t，消息数量。 | 无 | HDF_STATUS相关状态 | 传递用户消息 | 


## 开发步骤

I2C模块适配的三个环节是配置属性文件，实例化驱动入口，以及实例化核心层接口函数。

1. 实例化驱动入口：
   - 实例化HdfDriverEntry结构体成员。
   - 调用HDF_INIT将HdfDriverEntry实例化对象注册到HDF框架中。

2. 配置属性文件：
   - 在device_info.hcs文件中添加deviceNode描述。
   - 【可选】添加i2c_config.hcs器件属性文件。

3. 实例化I2C控制器对象：
   - 初始化I2cCntlr成员。
   - 实例化I2cCntlr成员I2cMethod和I2cLockMethod。
      > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**<br>
      > 实例化I2cCntlr成员I2cMethod和I2cLockMethod，详见[接口说明](#接口说明)。

4. 驱动调试：
   【可选】针对新增驱动程序，建议验证驱动基本功能，例如挂载后的信息反馈，消息传输的成功与否等。


## 开发实例

下方将以i2c_hi35xx.c为示例，展示需要厂商提供哪些内容来完整实现设备功能。

1. 驱动开发首先需要实例化驱动入口，驱动入口必须为HdfDriverEntry（在 hdf_device_desc.h 中定义）类型的全局变量，且moduleName要和device_info.hcs中保持一致。HDF框架会将所有加载的驱动的HdfDriverEntry对象首地址汇总，形成一个类似数组的段地址空间，方便上层调用。
   一般在加载驱动时HDF会先调用Bind函数，再调用Init函数加载该驱动。当Init调用异常时，HDF框架会调用Release释放驱动资源并退出。

   I2C驱动入口参考：

   I2C模块这种类型的控制器会出现很多个设备挂接的情况，因而在HDF框架中首先会为这类型的设备创建一个管理器对象，并同时对外发布一个管理器服务来统一处理外部访问。这样，用户需要打开某个设备时，会先获取到管理器服务，然后管理器服务根据用户指定参数查找到指定设备。

   I2C管理器服务的驱动由核心层实现，厂商不需要关注这部分内容的实现，这个但在实现Init函数的时候需要调用核心层的I2cCntlrAdd函数，它会实现相应功能。

     
   ```
   struct HdfDriverEntry g_i2cDriverEntry = {
       .moduleVersion = 1,
       .Init = Hi35xxI2cInit,
       .Release = Hi35xxI2cRelease,
       .moduleName = "hi35xx_i2c_driver",// 【必要且与config.hcs文件里面匹配】
   };
   HDF_INIT(g_i2cDriverEntry);           // 调用HDF_INIT将驱动入口注册到HDF框架中
   
   // 核心层i2c_core.c管理器服务的驱动入口
   struct HdfDriverEntry g_i2cManagerEntry = {
       .moduleVersion = 1,
       .Bind = I2cManagerBind,
       .Init = I2cManagerInit,
       .Release = I2cManagerRelease,
       .moduleName = "HDF_PLATFORM_I2C_MANAGER",// 这与device_info文件中device0对应
   };
   HDF_INIT(g_i2cManagerEntry);
   ```

2. 完成驱动入口注册之后，下一步请在device_info.hcs文件中添加deviceNode信息，并在i2c_config.hcs中配置器件属性。deviceNode信息与驱动入口注册相关，器件属性值对于厂商驱动的实现以及核心层I2cCntlr相关成员的默认值或限制范围有密切关系。
   统一服务模式的特点是device_info文件中第一个设备节点必须为I2C管理器，其各项参数必须如表2设置：

     **表2** 统一服务模式的特点
   
   | 成员名 | 值 | 
   | -------- | -------- |
   | moduleName | 固定为HDF_PLATFORM_I2C_MANAGER | 
   | serviceName | 固定为HDF_PLATFORM_I2C_MANAGER | 
   | policy | 具体配置为1或2取决于是否对用户态可见 | 
   | deviceMatchAttr | 没有使用，可忽略 | 

     从第二个节点开始配置具体I2C控制器信息，此节点并不表示某一路I2C控制器，而是代表一个资源性质设备，用于描述一类I2C控制器的信息。多个控制器之间相互区分的参数是busID和reg_pbase，这在i2c_config文件中有所体现。
   - device_info.hcs配置参考
   
       
     ```
     root {
     device_info {
     match_attr = "hdf_manager";
         device_i2c :: device {
         device0 :: deviceNode {
             policy = 2;
             priority = 50;
             permission = 0644;
             moduleName = "HDF_PLATFORM_I2C_MANAGER";
             serviceName = "HDF_PLATFORM_I2C_MANAGER";
             deviceMatchAttr = "hdf_platform_i2c_manager";
         }
         device1 :: deviceNode {
             policy = 0;                               // 等于0，不需要发布服务
             priority = 55;                            // 驱动启动优先级
             permission = 0644;                        // 驱动创建设备节点权限
             moduleName = "hi35xx_i2c_driver";         //【必要】用于指定驱动名称，需要与期望的驱动Entry中的moduleName一致；
             serviceName = "HI35XX_I2C_DRIVER";        //【必要】驱动对外发布服务的名称，必须唯一
             deviceMatchAttr = "hisilicon_hi35xx_i2c"; //【必要】用于配置控制器私有数据，要与i2c_config.hcs中对应控制器保持一致
                                                       // 具体的控制器信息在 i2c_config.hcs中
         }
         }
     }
     }
     ```
   
   - i2c_config.hcs 配置参考
   
       
     ```
     root {
     platform {
         i2c_config {
         match_attr = "hisilicon_hi35xx_i2c";  //【必要】需要和device_info.hcs中的deviceMatchAttr值一致
         template i2c_controller {             //模板公共参数，继承该模板的节点如果使用模板中的默认值，则节点字段可以缺省
             bus = 0;                          // 【必要】i2c 识别号
             reg_pbase = 0x120b0000;           // 【必要】物理基地址
             reg_size = 0xd1;                  // 【必要】寄存器位宽
             irq = 0;                          // 【可选】根据厂商需要来使用
             freq = 400000;                    // 【可选】根据厂商需要来使用
             clk = 50000000;                   // 【可选】根据厂商需要来使用
         }
         controller_0x120b0000 :: i2c_controller {
             bus = 0;
         }
         controller_0x120b1000 :: i2c_controller {
             bus = 1;
             reg_pbase = 0x120b1000;
         }
         ...
         }
     }
     }
     ```

3. 完成驱动入口注册之后，最后一步就是以核心层I2cCntlr对象的初始化为核心，包括厂商自定义结构体（传递参数和数据），实例化I2cCntlr成员I2cMethod（让用户可以通过接口来调用驱动底层函数），实现HdfDriverEntry成员函数（Bind，Init，Release）。
   - 自定义结构体参考

      从驱动的角度看，自定义结构体是参数和数据的载体，而且i2c_config.hcs文件中的数值会被HDF读入通过DeviceResourceIface来初始化结构体成员，其中一些重要数值也会传递给核心层I2cCntlr对象，例如设备号、总线号等。

        
      ```
      // 厂商自定义功能结构体
      struct Hi35xxI2cCntlr {
          struct I2cCntlr cntlr;            // 【必要】是核心层控制对象，具体描述见下面
          OsalSpinlock spin;                // 【必要】厂商需要基于此锁变量对各个 i2c 操作函数实现对应的加锁解锁
          volatile unsigned char  *regBase; // 【必要】寄存器基地址
          uint16_t regSize;                 // 【必要】寄存器位宽
          int16_t bus;                      // 【必要】i2c_config.hcs文件中可读取具体值
          uint32_t clk;                     // 【可选】厂商自定义
          uint32_t freq;                    // 【可选】厂商自定义
          uint32_t irq;                     // 【可选】厂商自定义
          uint32_t regBasePhy;              // 【必要】寄存器物理基地址
      };
      
      // I2cCntlr是核心层控制器结构体，其中的成员在Init函数中会被赋值
      struct I2cCntlr {
          struct OsalMutex lock;
          void *owner;
          int16_t busId;
          void *priv;
          const struct I2cMethod *ops;
          const struct I2cLockMethod *lockOps;
      };
      ```
   - I2cCntlr成员回调函数结构体I2cMethod的实例化，和锁机制回调函数结构体I2cLockMethod实例化，其他成员在Init函数中初始化。

        
      ```
      // i2c_hi35xx.c中的示例
      static const struct I2cMethod g_method = {
          .transfer = Hi35xxI2cTransfer,
      };
      
      static const struct I2cLockMethod g_lockOps = {
          .lock = Hi35xxI2cLock,    // 加锁函数
          .unlock = Hi35xxI2cUnlock,// 解锁函数
      };
      ```
   - Init函数参考

      入参：

      HdfDeviceObject是整个驱动对外暴露的接口参数，具备hcs配置文件的信息。

      返回值：

      HDF_STATUS相关状态（下表为部分展示，如需使用其他状态，可见//drivers/framework/include/utils/hdf_base.h中HDF_STATUS定义）。

        **表3** Init函数入参及返回值参考
      
      | 状态(值) | 问题描述 | 
      | -------- | -------- |
      | HDF_ERR_INVALID_OBJECT | 控制器对象非法 | 
      | HDF_ERR_INVALID_PARAM | 参数非法 | 
      | HDF_ERR_MALLOC_FAIL | 内存分配失败 | 
      | HDF_ERR_IO | I/O&nbsp;错误 | 
      | HDF_SUCCESS | 传输成功 | 
      | HDF_FAILURE | 传输失败 | 

      函数说明：

      初始化自定义结构体对象，初始化I2cCntlr成员，调用核心层I2cCntlrAdd函数，【可选】接入VFS。

        
      ```
      static int32_t Hi35xxI2cInit(struct HdfDeviceObject *device)
      {
          ...
          // 遍历、解析 i2c_config.hcs中的所有配置节点，并分别进行初始化，需要调用Hi35xxI2cParseAndInit函数
          DEV_RES_NODE_FOR_EACH_CHILD_NODE(device->property, childNode) {
              ret = Hi35xxI2cParseAndInit(device, childNode);//函数定义见下
          ...
          }
          ...
      }
      
      static int32_t Hi35xxI2cParseAndInit(struct HdfDeviceObject *device, const struct DeviceResourceNode *node)
      {
          struct Hi35xxI2cCntlr *hi35xx = NULL;
          ... 
          hi35xx = (struct Hi35xxI2cCntlr *)OsalMemCalloc(sizeof(*hi35xx));   // 内存分配
          ... 
          hi35xx->regBase = OsalIoRemap(hi35xx->regBasePhy, hi35xx->regSize); // 地址映射
          ... 
          Hi35xxI2cCntlrInit(hi35xx);         // 【必要】i2c设备的初始化
          
          hi35xx->cntlr.priv = (void *)node;  // 【必要】存储设备属性
          hi35xx->cntlr.busId = hi35xx->bus;  // 【必要】初始化I2cCntlr成员busId
          hi35xx->cntlr.ops = &g_method;      // 【必要】I2cMethod的实例化对象的挂载
          hi35xx->cntlr.lockOps = &g_lockOps; // 【必要】I2cLockMethod的实例化对象的挂载
          (void)OsalSpinInit(&hi35xx->spin);  // 【必要】锁的初始化
          ret = I2cCntlrAdd(&hi35xx->cntlr);  // 【必要】调用此函数填充核心层结构体，返回成功信号后驱动才完全接入平台核心层
          ...
      #ifdef USER_VFS_SUPPORT
          (void)I2cAddVfsById(hi35xx->cntlr.busId);// 【可选】若支持用户级的虚拟文件系统，则接入
      #endif
          return HDF_SUCCESS;
      __ERR__:                                // 不成功的话，需要反向执行初始化相关函数
          if (hi35xx != NULL) {
              if (hi35xx->regBase != NULL) {
                  OsalIoUnmap((void *)hi35xx->regBase);
                  hi35xx->regBase = NULL;
              }
              OsalMemFree(hi35xx);
              hi35xx = NULL;
          }
          return ret;
      }
      ```
   - Release函数参考

      入参：

      HdfDeviceObject是整个驱动对外暴露的接口参数，具备hcs配置文件的信息。

      返回值：

      无。

      函数说明：

      释放内存和删除控制器，该函数需要在驱动入口结构体中赋值给Release接口，当HDF框架调用Init函数初始化驱动失败时，可以调用Release释放驱动资源。

        
      ```
      static void Hi35xxI2cRelease(struct HdfDeviceObject *device)
      {
          ...
          // 与Hi35xxI2cInit一样，需要将对每个节点分别进行释放
          DEV_RES_NODE_FOR_EACH_CHILD_NODE(device->property, childNode) {
              Hi35xxI2cRemoveByNode(childNode);// 函数定义见下
          }
      }
      
      static void Hi35xxI2cRemoveByNode(const struct DeviceResourceNode *node)
      {
          ... 
          // 【必要】可以调用 I2cCntlrGet函数通过设备的busid获取I2cCntlr对象， 以及调用I2cCntlrRemove函数来释放I2cCntlr对象的内容
          cntlr = I2cCntlrGet(bus);
          if (cntlr != NULL && cntlr->priv == node) {
              ...
              I2cCntlrRemove(cntlr); 
              // 【必要】解除地址映射，锁和内存的释放
              hi35xx = (struct Hi35xxI2cCntlr *)cntlr; 
              OsalIoUnmap((void *)hi35xx->regBase);
              (void)OsalSpinDestroy(&hi35xx->spin);
              OsalMemFree(hi35xx);
          }
          return;
      }
      ```
