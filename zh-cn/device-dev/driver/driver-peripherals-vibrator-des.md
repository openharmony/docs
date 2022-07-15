# Vibrator

## 概述

### 功能简介

为了快速开发传感器驱动，基于HDF（Hardware Driver Foundation）驱动框架开发了马达（Vibrator）驱动模型。马达驱动模型，屏蔽设备驱动与系统交互的实现，为硬件服务层提供统一稳定的驱动接口能力，为驱动开发者提供开放的接口和解析接口的能力，用于不同操作系统马达设备部件的部署指导和马达设备部件驱动的开发。马达驱动模型如图1所示：

**图 1** 马达驱动模型图

![Vibrator驱动模型图](figures/Vibrator驱动模型图.png)

### 基本概念

系统通过调用马达实现对设备的振动控制。目前，马达只有两种振动方式：

- 单次振动

  单次振动是指按照指定的时间控制振动时长。

- 周期振动

  周期振动是指按照预置的效果模式控制振动。例如：预置效果为“haptic.clock.timer” = [600, 600, 200, 600]，等待600ms，振动600ms，等待200ms，振动600ms。

### 运作机制

通过介绍马达驱动模型的加载以及运行流程，对模型内部关键组件以及关联组件之间的关系进行了划分，整体加载流程如图2所示：

**图2** 马达驱动运行图

![Vibrator驱动运行图](figures/Vibrator驱动运行图.png)

马达驱动模型以标准系统Hi3516DV300产品为例，介绍整个驱动加载及运行流程：

1. 从device_info.hcs配置文件中的Vibrator Host读取Vibrator管理配置信息。
2. 解析Vibrator管理配置信息，并关联对应马达抽象驱动。
3. 从linear_vibrator_config.hcs配置文件中读取Vibrator数据配置信息。
4. 解析Vibrator数据配置信息，并关联对应Haptic驱动。
5. 客户端下发Vibrator Stub控制到服务端。
6. Vibrator Stub控制调用马达服务。
7. 初始化马达抽象驱动接口。
8. Haptic中起线程，解析效果模块。
9. Haptic调用马达抽象驱动中的Start接口。
10. 马达抽象驱动调用马达差异化驱动中的Start接口。

## 开发指导

### 场景介绍

当设备需要设置不同的振动效果时，可以调用Vibrator模块，例如，设备的按键可以设置不同强度和时长的振动，闹钟和来电可以设置不同强度和时长的单次或周期性振动。

### 接口说明

马达驱动模型支持静态HCS配置和动态参数两种振动效果配置能力。马达硬件服务调用StartOnce接口动态配置持续振动；调用Start接口启动静态配置的振动效果。马达驱动模型对HDI开放的API接口能力，如下表所示。

**表 1** 马达驱动模型对外API接口能力介绍

| 接口名                                  | 功能描述                                           |
| -------------------------------------- | ------------------------------------------------ |
| int32_t  StartOnce(uint32_t duration)  | 按照指定持续时间触发振动马达，duration为振动持续时长。   |
| int32_t  Start(const char *effectType) | 按照指定预置效果启动马达，effectType表示预置的预置效果。 |
| int32_t  Stop(enum VibratorMode mode)  | 按照指定的振动模式停止马达振动。                       |

### 开发步骤

Vibrator驱动模型为上层马达硬件服务层提供稳定的马达控制能力接口，包括马达一次振动、马达效果配置震动、马达停止。基于HDF驱动框架开发的马达驱动模型，实现跨操作系统迁移、器件差异配置等功能。具体的开发步骤如下：

1. 基于HDF驱动框架，按照驱动Driver Entry程序，完成马达抽象驱动开发，主要由Bind、Init、Release、Dispatch函数接口实现，配置资源和HCS解析。

   - 调用HDF_INIT将驱动入口注册到HDF框架中，在加载驱动时HDF框架会先调用Bind函数，再调用Init函数加载该驱动。当Init调用异常时，HDF框架会调用Release释放驱动资源并退出马达驱动模型，使用HCS作为配置描述源码。HCS配置字段详细介绍参考[配置管理](driver-hdf-manage.md)。其中Driver Entry入口函数定义如下：

     ```c
     /* 注册马达抽象驱动入口数据结构体对象 */
     struct HdfDriverEntry g_vibratorDriverEntry = {
         .moduleVersion = 1, // 马达模块版本号
         .moduleName = "HDF_VIBRATOR", // 马达模块名，要与device_info.hcs文件里的马达moduleName字段值一样
         .Bind = BindVibratorDriver, // 马达绑定函数
         .Init = InitVibratorDriver, // 马达初始化函数
         .Release = ReleaseVibratorDriver, // 马达资源释放函数
     };
     
     HDF_INIT(g_vibratorDriverEntry);
     ```

   - 基于HDF驱动框架，按照驱动Driver Entry程序，完成马达抽象驱动开发，主要由Bind、Init、Release、Dispatch函数接口实现。

     ```c
     /* 马达驱动对外发布的能力 */
     static int32_t DispatchVibrator(struct HdfDeviceIoClient *client,
         int32_t cmd, struct HdfSBuf *data, struct HdfSBuf *reply)
     {
         int32_t loop;
     
         for (loop = 0; loop < sizeof(g_vibratorCmdHandle) / sizeof(g_vibratorCmdHandle[0]); ++loop) {
             if ((cmd == g_vibratorCmdHandle[loop].cmd) && (g_vibratorCmdHandle[loop].func != NULL)) {
                 return g_vibratorCmdHandle[loop].func(data, reply);
             }
         }
     
         return HDF_SUCCESS;
     }
     
     /* 马达驱动对外提供的服务绑定到HDF框架 */
     int32_t BindVibratorDriver(struct HdfDeviceObject *device)
     {
         struct VibratorDriverData *drvData = NULL;
         CHECK_VIBRATOR_NULL_PTR_RETURN_VALUE(device, HDF_FAILURE);
     
         drvData = (struct VibratorDriverData *)OsalMemCalloc(sizeof(*drvData));
         CHECK_VIBRATOR_NULL_PTR_RETURN_VALUE(drvData, HDF_ERR_MALLOC_FAIL);
     
         drvData->ioService.Dispatch = DispatchVibrator;
         drvData->device = device;
         device->service = &drvData->ioService;
         g_vibratorDrvData = drvData;
     
         return HDF_SUCCESS;
     }
     
     /* 马达驱动初始化入口函数*/
     int32_t InitVibratorDriver(struct HdfDeviceObject *device)
     {
         struct VibratorDriverData *drvData = NULL;
     
         drvData->mode = VIBRATOR_MODE_BUTT;
         drvData->state = VIBRATOR_STATE_IDLE;
         ......
         if (CreateVibratorHaptic(device) != HDF_SUCCESS) {
             HDF_LOGE("%s: init workQueue fail!", __func__);
             return HDF_FAILURE;
         }
     
         return HDF_SUCCESS;
     }
     
     /* 释放马达驱动初始化时分配的资源 */
     void ReleaseVibratorDriver(struct HdfDeviceObject *device)
     {
         struct VibratorDriverData *drvData = NULL;
         ......
         (void)DestroyVibratorHaptic();
         (void)OsalMutexDestroy(&drvData->mutex);
         (void)OsalMemFree(drvData);
         g_vibratorDrvData = NULL;
     }
     ```

   - 在系统启动过程中，HDF设备管理模块通过设备HCS配置信息，加载马达抽象驱动，并对外发布马达驱动接口。

     ```c
     /* 马达设备HCS配置 */
     vibrator :: host {
                 hostName = "vibrator_host";
                 device_vibrator :: device {
                     device0 :: deviceNode {
                         policy = 2; // 驱动服务发布的策略
                         priority = 100; // 驱动启动优先级（0-200），值越大优先级越低，建议配置100，优先级相同则不保证device的加载顺序
                         preload = 0; // 驱动按需加载字段，0表示加载，2表示不加载
                         permission = 0664; // 驱动创建设备节点权限
                         moduleName = "HDF_VIBRATOR"; // 驱动名称，该字段的值必须和驱动入口结构的moduleName值一致
                         serviceName = "hdf_misc_vibrator"; // 驱动对外发布服务的名称，必须唯一 
                         deviceMatchAttr = "hdf_vibrator_driver"; // 驱动私有数据匹配的关键字，必须和驱动私有数据配置表中的match_attr值相等
                     }
                 }
     ```

2. 创建马达效果模型，解析马达效果HCS配置。

   - 创建马达效果模型。

     ```hcs
     /* 创建马达效果模型，分配资源，解析马达效果HCS配置 */
     int32_t CreateVibratorHaptic(struct HdfDeviceObject *device)
     {
         struct VibratorHapticData *hapticData = NULL;
         CHECK_VIBRATOR_NULL_PTR_RETURN_VALUE(device, HDF_FAILURE);
     
         hapticData = (struct VibratorHapticData *)OsalMemCalloc(sizeof(*hapticData));
         CHECK_VIBRATOR_NULL_PTR_RETURN_VALUE(hapticData, HDF_ERR_MALLOC_FAIL);
         g_vibratorHapticData = hapticData;
         hapticData->supportHaptic = false;
     
         if (OsalMutexInit(&hapticData->mutex) != HDF_SUCCESS) {
             HDF_LOGE("%s: fail to init mutex", __func__);
             goto EXIT;
         }
     
         DListHeadInit(&hapticData->effectSeqHead);
     
         /* 解析马达效果HCS配置 */
         if (ParserVibratorHapticConfig(device->property) != HDF_SUCCESS) {
             HDF_LOGE("%s: parser haptic config fail!", __func__);
             goto EXIT;
         }
     
         return HDF_SUCCESS;
     EXIT:
         OsalMemFree(hapticData);
         return HDF_FAILURE;
     }
     ```

   - 马达效果模型使用HCS作为配置描述源码，hcs配置文件字段详细介绍参考[配置管理](driver-hdf-manage.md)。

     ```hcs
     /* 马达数据配置模板（vibrator_config.hcs） */
     root {
         vibratorConfig {
             boardConfig {
                 match_attr = "hdf_vibrator_driver"; // 需要和马达设备配置match_attr字段保持一致
                 vibratorAttr {
                     /* 0：转子；1：线性 */
                     deviceType = 1; // 设备类型
                     supportPreset = 1; // 支持的预设类型
                 }
                 vibratorHapticConfig {
                     haptic_clock_timer {
                         effectName = "haptic.clock.timer";
                         type = 1; // 0：内置模式；1：时间序列
                         seq = [600, 600, 200, 600]; // 时间序列
                     }
                     haptic_default_effect {
                         effectName = "haptic.default.effect";
                         type = 0;
                         seq = [0, 3, 800, 1];
                     }
                 }
             }
         }
     }
     ```

3. 完成马达振动和停止接口开发，会根据振动效果的模式创建和销毁定时器。

   马达硬件服务调用StartOnce接口动态配置持续振动时间；调用StartEffect接口启动静态配置的振动效果，为驱动开发者提供抽象的配置接口能力。

   ```c
   /* 按照指定持续时间触发振动马达，duration为振动持续时长 */
   static int32_t StartOnce(struct HdfSBuf *data, struct HdfSBuf *reply)
   {
       uint32_t duration;
       int32_t ret;
       struct VibratorEffectCfg config;
       struct VibratorDriverData *drvData = GetVibratorDrvData();
       (void)reply;
       ...... 
       config.cfgMode = VIBRATOR_MODE_ONCE;
       config.duration = duration;
       config.effect = NULL;
       /* 根据振动效果的模式创建定时器 */
       ret = StartHaptic(&config);
       if (ret != HDF_SUCCESS) {
           HDF_LOGE("%s: start haptic fail!", __func__);
           return ret;
       }
   
       return HDF_SUCCESS;
   }
   
   /* 按照预置效果启动马达，effectType表示预置的预置效果 */
   static int32_t StartEffect(struct HdfSBuf *data, struct HdfSBuf *reply)
   {
       int32_t ret;
       const char *effect = NULL;
       struct VibratorEffectCfg config;
       struct VibratorDriverData *drvData = GetVibratorDrvData();
       (void)reply;
       ......
       config.cfgMode = VIBRATOR_MODE_PRESET;
       config.duration = 0;
       config.effect = effect;
   
       ret = StartHaptic(&config);
       if (ret != HDF_SUCCESS) {
           HDF_LOGE("%s: start haptic fail!", __func__);
           return ret;
       }
   
       return HDF_SUCCESS;
   }
   
   /* 按照指定的振动模式停止马达振动 */
   static int32_t Stop(struct HdfSBuf *data, struct HdfSBuf *reply)
   {
       int32_t ret;
       int32_t mode;
       struct VibratorDriverData *drvData = GetVibratorDrvData();
       (void)reply;
       ......
       /* 停止马达效果振动，销毁马达定时器 */
       ret = StopHaptic();
       if (ret != HDF_SUCCESS) {
           HDF_LOGE("%s: stop haptic fail!", __func__);
           return ret;
       }
   
       (void)OsalMutexLock(&drvData->mutex);
       drvData->mode = VIBRATOR_MODE_BUTT;
       (void)OsalMutexUnlock(&drvData->mutex);
   
       return HDF_SUCCESS;
   }
   ```

4. 马达驱动模型提供给开发者马达驱动差异化接口，开发者实现差异化接口。

   - 在差异化器件驱动初始化成功时，注册差异实现接口，方便实现器件差异的驱动接口。

     ```c
     /* 注册马达差异化实现接口 */
     int32_t RegisterVibrator(struct VibratorOps *ops)
     {
         struct VibratorDriverData *drvData = GetVibratorDrvData();
     
         CHECK_VIBRATOR_NULL_PTR_RETURN_VALUE(ops, HDF_FAILURE);
         CHECK_VIBRATOR_NULL_PTR_RETURN_VALUE(drvData, HDF_FAILURE);
     
         (void)OsalMutexLock(&drvData->mutex);
         drvData->ops.Start = ops->Start;
         drvData->ops.StartEffect = ops->StartEffect;
         drvData->ops.Stop = ops->Stop;
         (void)OsalMutexUnlock(&drvData->mutex);
     
         return HDF_SUCCESS;
     }
     ```

   - 马达驱动模型提供给开发者马达驱动差异化接口，具体实现如下：

     ```c
     /* 按照指定持续时间触发线性马达的振动 */
     static int32_t StartLinearVibrator()
     {
         int32_t ret;
         struct VibratorLinearDriverData *drvData = GetLinearVibratorData();
         CHECK_VIBRATOR_NULL_PTR_RETURN_VALUE(drvData, HDF_FAILURE);
         ......
         ret = GpioWrite(drvData->gpioNum, GPIO_VAL_LOW);
         if (ret != HDF_SUCCESS) {
             HDF_LOGE("%s: pull gpio%d to %d level failed", __func__, drvData->gpioNum, GPIO_VAL_LOW);
             return ret;
         }
         return HDF_SUCCESS;
     }
     
     /* 按照预置振动效果触发线性马达的振动 */
     static int32_t StartEffectLinearVibrator(uint32_t effectType)
     {
         (void)effectType;
          HDF_LOGE("%s: vibrator set build-in effect no support!", __func__);
         return HDF_SUCCESS;
     }
     
     /* 按照指定的振动模式停止线性马达的振动 */
     static int32_t StopLinearVibrator()
     {
         int32_t ret;
         struct VibratorLinearDriverData *drvData = GetLinearVibratorData();
         CHECK_VIBRATOR_NULL_PTR_RETURN_VALUE(drvData, HDF_FAILURE);
         ......
         ret = GpioWrite(drvData->gpioNum, GPIO_VAL_HIGH);
         if (ret != HDF_SUCCESS) {
             HDF_LOGE("%s: pull gpio%d to %d level failed", __func__, drvData->gpioNum, GPIO_VAL_HIGH);
             return ret;
         }
         return HDF_SUCCESS;
     }
     ```