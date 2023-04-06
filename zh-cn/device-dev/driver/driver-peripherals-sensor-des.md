# Sensor


## 概述

### 功能简介

Sensor驱动模型屏蔽硬件器件差异，为上层Sensor服务系统提供稳定的Sensor基础能力接口，包括Sensor列表查询、Sensor启停、Sensor订阅及取消订阅，Sensor参数配置等功能。Sensor设备驱动的开发是基于HDF驱动框架基础上，结合操作系统适配层（OSAL）和平台驱动接口（比如I2C/SPI/UART总线等平台资源）能力，屏蔽不同操作系统和平台总线资源差异，实现Sensor驱动“一次开发，多系统部署”的目标。Sensor驱动模型如图1所示。

**图 1**  Sensor驱动模型图

![Sensor驱动模型图](figures/Sensor驱动模型图.png)

### 基本概念

目前根据sensorId将Sensor分为医学类Sensor、传统类Sensor两种。

- 医学类Sensor：已订阅的sensorId枚举值在128-160范围的为医学类Sensor。

- 传统类Sensor：已订阅的sensorId枚举值不在128-160范围的为传统类Sensor。

### 运作机制

通过介绍Sensor驱动模型的加载以及运行流程，对模型内部关键组件以及关联组件之间的关系进行了划分，整体加载流程如图2所示：

**图 2** Sensor驱动运行图

![Sensor驱动运行图](figures/Sensor驱动运行图.png)

Sensor驱动模型以标准系统Hi3516DV300产品中的加速度传感器驱动为例，介绍整个驱动加载及运行流程：

1. 从device_info.hcs配置文件中的Sensor Host读取到Sensor设备管理配置信息。
2. HDF配置框架从HCB数据库中解析Sensor设备管理配置信息，并关联对应设备驱动。
3. 加载并初始化Sensor设备管理驱动。
4. Sensor设备管理驱动向HDI发布Sensor基础能力接口。
5. 从device_info.hcs配置文件中的Sensor Host读取到加速度传感器驱动配置信息。
6. 加载加速度传感器抽象驱动，调用初始化接口，完成Sensor器件的驱动资源分配和数据处理队列的创建。
7. 从accel_xxx_config.hcs配置文件中读取到加速度传感器差异化驱动配置和私有化配置信息。
8. 加速度传感器芯片差异化驱动，调用通用配置解析接口，完成器件属性信息解析，器件寄存器解析。
9. 加速度传感器芯片差异化驱动完成器件的探测，并分配加速度传感器配置资源和加速度传感器差异化接口注册。
10. 加速度传感器成功探测到器件之后，加速度传感器芯片差异化驱动通知加速度传感器抽象驱动，注册加速度传感器设备到Sensor设备管理中。

## 开发指导

### 场景介绍

- 通过重力和陀螺仪传感器数据，能感知设备倾斜和旋转量，提高用户在游戏场景中的体验。
- 通过接近光传感器数据，感知距离遮挡物的距离，使设备能够自动亮灭屏，达到防误触目的。例如，手机通话时，如屏幕距离人脸过近，则自动关闭屏幕，防止误触的同时降低功耗。
- 通过气压计传感器数据，可以准确的判断设备当前所处的海拔。
- 通过环境光传感器数据，设备能够实现背光自动调节。
- 通过霍尔传感器数据，设备可以实现皮套功能，皮套合上，手机上开一个小窗口，可降低功耗。

### 接口说明

Sensor驱动模型对外开放的API接口能力如下：

- 提供Sensor HDI（Hardware Device Interface）能力接口，简化服务开发。
- 提供Sensor驱动模型能力接口：
  - 依赖HDF驱动框架实现Sensor器件驱动的加载、器件探测、注册和去注册等能力。
  - 提供同一类型Sensor器件驱动归一接口、寄存器配置解析操作接口、总线访问抽象接口和平台抽象接口。
- 提供开发者实现的能力接口：依赖HDF驱动框架的HCS（HDF Configuration Source）配置管理，根据同类型Sensor差异化配置，实现Sensor器件参数序列化配置和器件部分操作接口，简化Sensor器件驱动开发。

Sensor驱动模型对外开放的API接口能力的具体实现请参考：

**表 1**  Sensor驱动模型对外API接口功能介绍

| 接口名 | 功能描述 |
| ----- | -------- |
| int32_t GetAllSensors(struct SensorInformation **sensorInfo, int32_t *count) | 获取系统中注册的所有传感器信息，一组完整传感器信息包括传感器名字、设备厂商、固件版本号、硬件版本号、传感器类型编号、传感器标识、最大量程、精度、功耗。 |
| int32_t Enable(int32_t sensorId) | 使能指定传感器设备，只有数据订阅者使能传感器后，才能获取订阅的传感器数据。 |
| int32_t Disable(int32_t sensorId) | 去使能指定传感器设备。 |
| int32_t SetBatch(int32_t sensorId, int64_t samplingInterval, int64_t reportInterval) | 设置指定传感器的数据采样间隔和数据上报间隔。 |
| int32_t SetMode(int32_t sensorId, int32_t mode) | 设置指定传感器的工作模式，不同的工作模式，上报数据方式不同。 |
| int32_t SetOption(int32_t sensorId, uint32_t option) | 设置指定传感器量程，精度等可选配置。 |
| int32_t Register(int32_t groupId, RecordDataCallback cb) | 订阅者根据不同groupId注册传感器数据回调函数，系统会将获取到的传感器数据上报给订阅者。 |
| int32_t Unregister(int32_t groupId, RecordDataCallback cb) | 订阅者根据groupId和回调函数注销对应订阅者的传感器数据回调函数。 |



Sensor驱动模型对驱动开发者开放的功能接口，驱动开发者无需实现，直接使用，请参考：

 **表2** Sensor驱动模型对驱动开发者开放的功能接口列表

| 接口名 | 功能描述 |
| ----- | -------- |
| int32_t AddSensorDevice(const struct SensorDeviceInfo *deviceInfo) | 添加当前类型的传感器设备到传感器设备管理。 |
| int32_t DeleteSensorDevice(const struct SensorBasicInfo *sensorBaseInfo) | 删除传感器设备管理里指定的传感器设备。 |
| int32_t ReportSensorEvent(const struct SensorReportEvent *events) | 上报指定类型传感器的数据到用户侧。 |
| int32_t ReadSensor(struct SensorBusCfg *busCfg, uint16_t regAddr, uint8_t *data, uint16_t dataLen) | 按照配置的总线方式，读取传感器寄存器配置数据。 |
| int32_t WriteSensor(struct SensorBusCfg *busCfg, uint8_t *writeData, uint16_t len) | 按照配置的总线方式，将传感器配置数据写入寄存器。 |
| int32_t SetSensorRegCfgArray(struct SensorBusCfg *busCfg, const struct SensorRegCfgGroupNode *group); | 根据传感器总线类型信息，下发寄存器分组配置。 |
| int32_t GetSensorBaseConfigData(const struct DeviceResourceNode *node, struct SensorCfgData *config) | 根据传感器设备HCS资源配置，获取传感器信息，总线配置信息，属性配置等基本配置信息，并初始化对应的基本配置数据结构体。 |
| int32_t ParseSensorRegConfig(struct SensorCfgData *config) | 根据传感器设备HCS资源配置，解析寄存器分组信息，并初始化配置数据结构体。 |
| void ReleaseSensorAllRegConfig(struct SensorCfgData *config) | 释放传感器配置数据结构体里分配的资源。 |
| int32_t GetSensorBusHandle(struct SensorBusCfg *busCfg) | 获取传感器总线句柄信息。 |
| int32_t ReleaseSensorBusHandle(struct SensorBusCfg *busCfg) | 释放传感器句柄信息。 |



Sensor驱动模型要求驱动开发者实现的接口功能，请参考：

**表 3**  Sensor驱动模型要求驱动开发者实现的接口列表

| 接口名 | 功能描述 |
| ----- | -------- |
| int32_t init(void) | 传感器设备探测成功后，需要对传感器设备初始化配置。 |
| int32_t Enable(void) | 根据当前传感器设备的HCS配置，下发传感器设备使能操作组的寄存器配置。 |
| int32_t Disable(void) | 根据当前传感器设备的HCS配置，下发传感器设备去使能操作组的寄存器配置。 |
| int32_t SetBatch(int64_t samplingInterval, int64_t reportInterval) | 根据数据采样率和数据上报间隔，配置当前传感器设备的数据上报线程处理时间。 |
| int32_t SetMode(int32_t mode) | 配置当前传感器设备数据上报方式。 |
| int32_t SetOption(uint32_t option) | 根据可选配置、下发量程和精度等寄存器配置。 |
| void ReadSensorData(void) | 实现传感器的数据读取函数。 |


接口实现参考[开发步骤](#开发步骤)章节。

### 开发步骤
1. 基于HDF驱动框架，按照驱动Driver Entry程序，完成加速度抽象驱动开发，主要由Bind、Init、Release、Dispatch函数接口实现。

   - 加速度传感器驱动入口函数实现

     ```c
     /* 注册加速度计传感器入口数据结构体对象 */
     struct HdfDriverEntry g_sensorAccelDevEntry = {
         .moduleVersion = 1,                // 加速度计传感器模块版本号
         .moduleName = "HDF_SENSOR_ACCEL",  // 加速度计传感器模块名，要与device_info.hcs文件里的加速度计moduleName字段值一样
         .Bind = BindAccelDriver,           // 加速度计传感器绑定函数
         .Init = InitAccelDriver,           // 加速度计传感器初始化函数
         .Release = ReleaseAccelDriver,     // 加速度计传感器资源释放函数
     };
     
     /* 调用HDF_INIT将驱动入口注册到HDF框架中。在加载驱动时HDF框架会先调用Bind函数，再调用Init函数加载该驱动。当Init调用异常时，HDF框架会调用Release释放驱动资源并退出 */
     HDF_INIT(g_sensorAccelDevEntry);
     ```

   - 加速度传感器驱动操作接口实现

     ```c
     /* 加速度计传感器驱动对外提供的服务绑定到HDF框架 */
     int32_t AccelBindDriver(struct HdfDeviceObject *device)
     {
         CHECK_NULL_PTR_RETURN_VALUE(device, HDF_ERR_INVALID_PARAM);
     
         struct AccelDrvData *drvData = (struct AccelDrvData *)OsalMemCalloc(sizeof(*drvData));
         if (drvData == NULL) {
             HDF_LOGE("%s: Malloc accel drv data fail!", __func__);
             return HDF_ERR_MALLOC_FAIL;
         }
     
         drvData->ioService.Dispatch = DispatchAccel;
         drvData->device = device;
         device->service = &drvData->ioService;
         g_accelDrvData = drvData;
         return HDF_SUCCESS;
     }
     
     /* 注册加速度计传感器驱动归一化的接口函数 */
     static int32_t InitAccelOps(struct SensorCfgData *config, struct SensorDeviceInfo *deviceInfo)
     {
         CHECK_NULL_PTR_RETURN_VALUE(config, HDF_ERR_INVALID_PARAM);
     
         deviceInfo->ops.Enable = SetAccelEnable;
         deviceInfo->ops.Disable = SetAccelDisable;
         deviceInfo->ops.SetBatch = SetAccelBatch;
         deviceInfo->ops.SetMode = SetAccelMode;
         deviceInfo->ops.SetOption = SetAccelOption;
     
         if (memcpy_s(&deviceInfo->sensorInfo, sizeof(deviceInfo->sensorInfo),
             &config->sensorInfo, sizeof(config->sensorInfo)) != EOK) {
             HDF_LOGE("%s: Copy sensor info failed", __func__);
             return HDF_FAILURE;
         }
     
         return HDF_SUCCESS;
     }
     /* 提供给差异化驱动的初始化接口，完成加速度器件基本配置信息解析（加速度信息、加速度总线配置、加速度器件探测寄存器配置）、器件探测、器件寄存器解析 */
     static int32_t InitAccelAfterDetected(struct SensorCfgData *config)
     {
         struct SensorDeviceInfo deviceInfo;
         CHECK_NULL_PTR_RETURN_VALUE(config, HDF_ERR_INVALID_PARAM);
         /* 初始化加速度计接口函数 */
         if (InitAccelOps(config, &deviceInfo) != HDF_SUCCESS) {
             HDF_LOGE("%s: Init accel ops failed", __func__);
             return HDF_FAILURE;
         }
         /* 注册加速度计设备到传感器管理模块 */
         if (AddSensorDevice(&deviceInfo) != HDF_SUCCESS) {
             HDF_LOGE("%s: Add accel device failed", __func__);
             return HDF_FAILURE;
         }
         /* 器件寄存器解析 */
         if (ParseSensorRegConfig(config) != HDF_SUCCESS) {
             HDF_LOGE("%s: Parse sensor register failed", __func__);
             (void)DeleteSensorDevice(&config->sensorInfo);
             ReleaseSensorAllRegConfig(config);
             return HDF_FAILURE;
         }
         return HDF_SUCCESS;
     }
     struct SensorCfgData *AccelCreateCfgData(const struct DeviceResourceNode *node)
     {
         ……
         /* 如果探测不到器件在位，返回进行下个器件探测 */
         if (drvData->detectFlag) {
             HDF_LOGE("%s: Accel sensor have detected", __func__);
             return NULL;
         }
         if (drvData->accelCfg == NULL) {
             HDF_LOGE("%s: Accel accelCfg pointer NULL", __func__);
             return NULL;
         }
         /* 设备基本配置信息解析 */
         if (GetSensorBaseConfigData(node, drvData->accelCfg) != HDF_SUCCESS) {
             HDF_LOGE("%s: Get sensor base config failed", __func__);
             goto BASE_CONFIG_EXIT;
         }
         /* 如果探测不到器件在位，返回进行下个器件探测 */
         if (DetectSensorDevice(drvData->accelCfg) != HDF_SUCCESS) {
             HDF_LOGI("%s: Accel sensor detect device no exist", __func__);
             drvData->detectFlag = false;
             goto BASE_CONFIG_EXIT;
         }
         drvData->detectFlag = true;
         /* 器件寄存器解析 */
         if (InitAccelAfterDetected(drvData->accelCfg) != HDF_SUCCESS) {
             HDF_LOGE("%s: Accel sensor detect device no exist", __func__);
             goto INIT_EXIT;
         }
         return drvData->accelCfg;
         ……
     }
     /* 加速度计传感器驱动初始化入口函数，主要功能为对传感器私有数据的结构体对象进行初始化，传感器HCS数据配置对象空间分配，传感器HCS数据配置初始化入口函数调用，传感器设备探测是否在位功能，传感器数据上报定时器创建，传感器归一化接口注册，传感器设备注册功能 */ 
     int32_t AccelInitDriver(struct HdfDeviceObject *device)
     {
         ……
         /* 工作队列资源初始化 */
         if (InitAccelData(drvData) != HDF_SUCCESS) {
             HDF_LOGE("%s: Init accel config failed", __func__);
             return HDF_FAILURE;
         }
         /* 分配加速度配置信息资源 */
         drvData->accelCfg = (struct SensorCfgData *)OsalMemCalloc(sizeof(*drvData->accelCfg));
         if (drvData->accelCfg == NULL) {
             HDF_LOGE("%s: Malloc accel config data failed", __func__);
             return HDF_FAILURE;
         }
         /* 注册寄存器分组信息 */
         drvData->accelCfg->regCfgGroup = &g_regCfgGroup[0];
         ……
         return HDF_SUCCESS;
     }
     /* 释放驱动初始化时分配的资源 */
     void AccelReleaseDriver(struct HdfDeviceObject *device)
     {
         CHECK_NULL_PTR_RETURN(device);
         struct AccelDrvData *drvData = (struct AccelDrvData *)device->service;
         CHECK_NULL_PTR_RETURN(drvData);
         /* 器件在位，释放已分配资源 */
         if (drvData->detectFlag) {
             AccelReleaseCfgData(drvData->accelCfg);
         }
         OsalMemFree(drvData->accelCfg);
         drvData->accelCfg = NULL;
         /* 器件在位，销毁工作队列资源 */
         HdfWorkDestroy(&drvData->accelWork);
         HdfWorkQueueDestroy(&drvData->accelWorkQueue);
         OsalMemFree(drvData);
     }
     ```

2. 完成加速度传感器驱动的设备信息配置。

   加速度传感器模型使用HCS作为配置描述源码，HCS配置字段请参考[配置管理](driver-hdf-manage.md)介绍。

   ```hcs
   /* 加速度计传感器设备HCS配置 */
   device_sensor_accel :: device {
       device0 :: deviceNode {
           policy = 1;                                  // 驱动服务发布的策略
           priority = 110;                              // 驱动启动优先级（0-200），值越大优先级越低，建议配置为100，优先级相同则不保证device的加载顺序
           preload = 0;                                 // 驱动按需加载字段，0表示加载，2表示不加载
           permission = 0664;                           // 驱动创建设备节点权限
           moduleName = "HDF_SENSOR_ACCEL";             // 驱动名称，该字段的值必须和驱动入口结构的moduleName值一致
           serviceName = "sensor_accel";                // 驱动对外发布服务的名称，必须唯一
           deviceMatchAttr = "hdf_sensor_accel_driver"; // 驱动私有数据匹配的关键字，必须和驱动私有数据配置表中的match_attr值相等
       }
   } 
   ```

3. 完成加速度传感器抽象驱动内部接口开发，包括Enable、Disable、SetBatch、SetMode、SetOption、AccelCreateCfgData、AccelReleaseCfgData、AccelRegisterChipOps接口实现。

   ```c
   /* 不使用函数暂时置空 */
   static int32_t SetAccelInfo(struct SensorBasicInfo *info)
   {
       (void)info;
   
       return HDF_ERR_NOT_SUPPORT;
   }
   /* 下发使能寄存器组的配置 */
   static int32_t SetAccelEnable(void)
   {
       int32_t ret;
       struct AccelDrvData *drvData = AccelGetDrvData();
   
       CHECK_NULL_PTR_RETURN_VALUE(drvData, HDF_ERR_INVALID_PARAM);
       CHECK_NULL_PTR_RETURN_VALUE(drvData->accelCfg, HDF_ERR_INVALID_PARAM);
   
       if (drvData->enable) {
           HDF_LOGE("%s: Accel sensor is enabled", __func__);
           return HDF_SUCCESS;
       }
   
       ret = SetSensorRegCfgArray(&drvData->accelCfg->busCfg, drvData->accelCfg->regCfgGroup[SENSOR_ENABLE_GROUP]);
       if (ret != HDF_SUCCESS) {
           HDF_LOGE("%s: Accel sensor enable config failed", __func__);
           return ret;
       }
   
       ret = OsalTimerCreate(&drvData->accelTimer, SENSOR_TIMER_MIN_TIME, AccelTimerEntry, (uintptr_t)drvData);
       if (ret != HDF_SUCCESS) {
           HDF_LOGE("%s: Accel create timer failed[%d]", __func__, ret);
           return ret;
       }
   
       ret = OsalTimerStartLoop(&drvData->accelTimer);
       if (ret != HDF_SUCCESS) {
           HDF_LOGE("%s: Accel start timer failed[%d]", __func__, ret);
           return ret;
       }
       drvData->enable = true;
   
       return HDF_SUCCESS;
   }
   /* 下发去使能寄存器组的配置 */
   static int32_t SetAccelDisable(void)
   {
       int32_t ret;
       struct AccelDrvData *drvData = AccelGetDrvData();
   
       CHECK_NULL_PTR_RETURN_VALUE(drvData, HDF_ERR_INVALID_PARAM);
       CHECK_NULL_PTR_RETURN_VALUE(drvData->accelCfg, HDF_ERR_INVALID_PARAM);
   
       if (!drvData->enable) {
           HDF_LOGE("%s: Accel sensor had disable", __func__);
           return HDF_SUCCESS;
       }
   
       ret = SetSensorRegCfgArray(&drvData->accelCfg->busCfg, drvData->accelCfg->regCfgGroup[SENSOR_DISABLE_GROUP]);
       if (ret != HDF_SUCCESS) {
           HDF_LOGE("%s: Accel sensor disable config failed", __func__);
           return ret;
       }
   
       ret = OsalTimerDelete(&drvData->accelTimer);
       if (ret != HDF_SUCCESS) {
           HDF_LOGE("%s: Accel delete timer failed", __func__);
           return ret;
       }
       drvData->enable = false;
   
       return HDF_SUCCESS;
   }
   /* 配置传感器采样率和数据上报间隔 */
   static int32_t SetAccelBatch(int64_t samplingInterval, int64_t interval)
   {
       (void)interval;
   
       struct AccelDrvData *drvData = NULL;
   
       drvData = AccelGetDrvData();
       CHECK_NULL_PTR_RETURN_VALUE(drvData, HDF_ERR_INVALID_PARAM);
   
       drvData->interval = samplingInterval;
   
       return HDF_SUCCESS;
   }
   /* 设置传感器工作模式，当前支持实时模式 */
   static int32_t SetAccelMode(int32_t mode)
   {
       return (mode == SENSOR_WORK_MODE_REALTIME) ? HDF_SUCCESS : HDF_FAILURE;
   }
   
   static int32_t SetAccelOption(uint32_t option)
   {
       (void)option;
       return HDF_SUCCESS;
   }
   /* 设置传感器可选配置 */
   static int32_t SetAccelOption(uint32_t option)
   {
       (void)option;
       return HDF_ERR_NOT_SUPPORT;
   }
   ```

4. 基于HDF驱动框架，按照驱动Driver Entry程序，完成加速度传感器差异化驱动开发，主要由Bind、Init、Release、Dispatch函数接口实现。

   ```c
   /* 加速度计传感器差异化驱动消息交互 */
   static int32_t DispatchBMI160(struct HdfDeviceIoClient *client,
       int cmd, struct HdfSBuf *data, struct HdfSBuf *reply)
   {
       (void)client;
       (void)cmd;
       (void)data;
       (void)reply;
   
       return HDF_SUCCESS;
   }
   /* 加速度计传感器差异化驱动对外提供的服务绑定到HDF框架 */
   int32_t Bmi160BindDriver(struct HdfDeviceObject *device)
   {
       CHECK_NULL_PTR_RETURN_VALUE(device, HDF_ERR_INVALID_PARAM);
   
       struct Bmi160DrvData *drvData = (struct Bmi160DrvData *)OsalMemCalloc(sizeof(*drvData));
       if (drvData == NULL) {
           HDF_LOGE("%s: Malloc Bmi160 drv data fail", __func__);
           return HDF_ERR_MALLOC_FAIL;
       }
   
       drvData->ioService.Dispatch = DispatchBMI160;
       drvData->device = device;
       device->service = &drvData->ioService;
       g_bmi160DrvData = drvData;
   
       return HDF_SUCCESS;
   }
   /* 加速度计传感器差异化驱动初始化 */
   int32_t Bmi160InitDriver(struct HdfDeviceObject *device)
   {
       int32_t ret;
       struct AccelOpsCall ops;
   
       CHECK_NULL_PTR_RETURN_VALUE(device, HDF_ERR_INVALID_PARAM);
       struct Bmi160DrvData *drvData = (struct Bmi160DrvData *)device->service;
       CHECK_NULL_PTR_RETURN_VALUE(drvData, HDF_ERR_INVALID_PARAM);
   
       ret = InitAccelPreConfig();
       if (ret != HDF_SUCCESS) {
           HDF_LOGE("%s: Init  BMI160 bus mux config", __func__);
           return HDF_FAILURE;
       }
   
       drvData->sensorCfg = AccelCreateCfgData(device->property);
       if (drvData->sensorCfg == NULL || drvData->sensorCfg->root == NULL) {
           HDF_LOGD("%s: Creating accelcfg failed because detection failed", __func__);
           return HDF_ERR_NOT_SUPPORT;
       }
   
       ops.Init = NULL;
       ops.ReadData = ReadBmi160Data;
       ret = AccelRegisterChipOps(&ops);
       if (ret != HDF_SUCCESS) {
           HDF_LOGE("%s: Register BMI160 accel failed", __func__);
           return HDF_FAILURE;
       }
   
       ret = InitBmi160(drvData->sensorCfg);
       if (ret != HDF_SUCCESS) {
           HDF_LOGE("%s: Init BMI160 accel failed", __func__);
           return HDF_FAILURE;
       }
   
       return HDF_SUCCESS;
   }
   /* 释放驱动初始化时分配的资源 */
   void Bmi160ReleaseDriver(struct HdfDeviceObject *device)
   {
   	......
       if (drvData->sensorCfg != NULL) {
           AccelReleaseCfgData(drvData->sensorCfg);
           drvData->sensorCfg = NULL;
       }
       OsalMemFree(drvData);
   }
   /* 加速度传感器差异化驱动对应的HdfDriverEntry对象 */
   struct HdfDriverEntry g_accelBmi160DevEntry = {
       .moduleVersion = 1,
       .moduleName = "HDF_SENSOR_ACCEL_BMI160",
       .Bind = Bmi160BindDriver,
       .Init = Bmi160InitDriver,
       .Release = Bmi160ReleaseDriver,
   };
   HDF_INIT(g_accelBmi160DevEntry);
   ```

5. 完成加速度传感器差异化驱动中差异化接口ReadData函数实现。

   ```c
   int32_t ReadBmi160Data(struct SensorCfgData *data)
   {
       int32_t ret;
       struct AccelData rawData = { 0, 0, 0 };
       int32_t tmp[ACCEL_AXIS_NUM];
       struct SensorReportEvent event;
       (void)memset_s(&event, sizeof(event), 0, sizeof(event));
       ret = ReadBmi160RawData(data, &rawData, &event.timestamp);
       if (ret != HDF_SUCCESS) {
           HDF_LOGE("%s: BMI160 read raw data failed", __func__);
           return HDF_FAILURE;
       }
       event.sensorId = SENSOR_TAG_ACCELEROMETER;
       event.option = 0;
       event.mode = SENSOR_WORK_MODE_REALTIME;
       ……
       ret = ReportSensorEvent(&event);
       if (ret != HDF_SUCCESS) {
           HDF_LOGE("%s: BMI160 report data failed", __func__);
       }
       return ret;
   }
   ```

### 调测验证

驱动开发完成后，在传感器单元测试里面开发自测试用例，验证驱动基本功能。测试环境采用开发者自测试平台。

```c++
static int32_t g_sensorDataFlag = 0;                        // 标识是否上报传感器数据
static const struct SensorInterface *g_sensorDev = nullptr; // 保持获取的传感器接口实例地址

/* 订阅者注册数据上报函数 */
static int SensorTestDataCallback(struct SensorEvents *event)
{
    if (event == nullptr) {
        return -1;
    }
    float *data = (float*)event->data;
    printf("time [%lld] sensor id [%d] x-[%f] y-[%f] z-[%f]\n\r", event->timestamp,
        event->sensorId, (*data), *(data + 1), *(data + g_axisZ));
    if (*data > 1e-5) {
        g_sensorDataFlag = 1;
    }
    return 0;
}
/* 用例执行前，初始化传感器接口实例 */
void HdfSensorTest::SetUpTestCase()
{
    g_sensorDev = NewSensorInterfaceInstance();
    if (g_sensorDev == nullptr) {
        printf("test sensor get module instance failed\n\r");
    }
}
/* 用例资源释放 */
void HdfSensorTest::TearDownTestCase()
{
    if (g_sensorDev != nullptr) {
        FreeSensorInterfaceInstance();
        g_sensorDev = nullptr;
    }
}
/* 传感器驱动测试验证 */
HWTEST_F(HdfSensorTest,TestAccelDriver_001, TestSize.Level0)
{
    int32_t sensorInterval = 1000000000;    // 数据采样率单位纳秒
    int32_t pollTime = 5;                   // 数据采样时间单位秒
    int32_t accelSensorId = 1;              // 加速度传感器类型标识为1
    int32_t count = 0;
    int ret;
    struct SensorInformation *sensorInfo = nullptr;

    ret = g_sensorDev->Register(0, TraditionSensorTestDataCallback)
    EXPECT_EQ(SENSOR_NULL_PTR, ret);

    ret = g_sensorDev->GetAllSensors(&sensorInfo, &count);
    EXPECT_EQ(0, ret);
    if (sensorInfo == nullptr) {
        EXPECT_NE(nullptr, sensorInfo);
        return;
    }
    /* 打印获取的传感器列表 */
    for (int i = 0; i < count; i++) {
        printf("get sensorId[%d], info name[%s]\n\r", sensorInfo[i]->sensorId, sensorInfo[i]->sensorName);
    }
    ret = g_sensorDev->Enable(accelSensorId);
    EXPECT_EQ(0, ret);
    g_sensorDataFlag = 0;

    ret = g_sensorDev->SetBatch(accelSensorId, sensorInterval, pollTime);
    EXPECT_EQ(0, ret);
    /* 在时间pollTime内，观察输出打印数据 */
    OsalSleep(pollTime);
    EXPECT_EQ(1, g_sensorDataFlag);

    ret = g_sensorDev->Disable(accelSensorId);
    g_sensorDataFlag = 0;
    EXPECT_EQ(0, ret);

    ret = g_sensorDev->Unregister(0, TraditionSensorTestDataCallback);
    EXPECT_EQ(0, ret);
}
```

