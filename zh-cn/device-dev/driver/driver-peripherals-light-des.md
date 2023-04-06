# Light


## 概述

### 功能简介

Light驱动模型为上层Light硬件服务层提供稳定的灯控制能力接口，包括获取灯类型、配置点灯模式、配置灯闪烁效果、点灯、熄灯等。基于HDF（Hardware Driver Foundation）驱动框架开发的Light驱动模型，实现跨操作系统迁移，器件差异配置等功能。实现Light驱动“一次开发，多系统部署”的目标。Light驱动模型如图1示：

**图 1**  Light驱动模型图

![Light驱动模型图](figures/Light驱动模型图.png)

### 运作机制

通过介绍Light驱动模型的加载以及运行流程，对模型内部关键组件以及关联组件之间的关系进行了划分，整体加载流程如图2所示：

**图 2**  Light驱动运行图

![Light驱动运行图](figures/Light驱动运行图.png)

以标准系统Hi3516DV300为例，介绍Light模块驱动加载及运行流程：

1. Device Manager从device_info.hcs配置文件中读取Light设备管理配置信息。
2. Device Manager从light_config.hcs配置文件中读取Light数据配置信息。
3. HCS Parser解析Light设备管理配置信息，加载对应的Light Host，并控制Host完成驱动的加载。
4. Light Proxy获取到Light HDI接口服务实例后，通过IPC（Inter-Process Communication）调用到Light Stub。
5. Light Stub主要处理与IPC相关的业务逻辑，完成参数反序列化后调用Light Controller。
6. Light Controller中是HDI接口的真正实现，通过IPC调用Light抽象驱动接口，进一步操作Light硬件设备。

## 开发指导

### 场景介绍

灯设备的控制，在实际生活中比比皆是，例如短信通知时闪灯、手机电量不足时预警、充电时根据充电进度变换灯的颜色等等。这些动作的实现，都需要使用Light驱动模型提供的接口，动态配置点灯模式、配置灯闪烁效果、点灯、熄灯等。

### 接口说明

Light驱动模型支持获取系统中所有灯的信息、动态配置闪烁模式和闪烁时间的能力。Light硬件服务调用GetLightInfo获取Light设备的基本信息，调用TurnOnLight接口启动配置的闪烁效果，调用TurnOffLight接口关闭Light设备。Light驱动模型对外开放的API接口能力，参考表1。

**表1**  Light驱动模型对外API接口能力介绍

| 接口名                                                       | 功能描述                                                     |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| int32_t (*GetLightInfo)([out] struct LightInfo **lightInfo, [out] uint32_t *count)  | 获取当前系统中所有类型的灯信息，lightInfo表示指向灯信息的二级指针，count表示指向灯数量的指针。 |
| int32_t (*TurnOnLight)([in] uint32_t lightId, [in] struct LightEffect *effect)  | 根据指定的灯类型ID打开列表中的可用灯，lightId表示灯类型ID，effect表示指向灯效果的指针。 |
| int32_t (*TurnOffLight)([in] uint32_t lightId)                 | 根据指定的灯类型ID关闭列表中的可用灯。                     |

### 开发步骤
1. 基于HDF驱动框架，按照驱动Driver Entry程序，完成Light抽象驱动开发（主要由Bind、Init、Release、Dispatch函数接口实现），资源配置及HCS配置文件解析。

   - 调用HDF_INIT将驱动入口注册到HDF框架中。在加载驱动时HDF框架会先调用Bind函数，再调用Init函数加载该驱动。当Init调用异常时，HDF框架会调用Release释放驱动资源并退出。
   - Light驱动模型使用HCS配置文件作为配置描述源码。HCS配置字段详细介绍请参考[配置管理](driver-hdf-manage.md)。其Driver Entry入口函数定义如下:

     ```c
     /* 注册灯入口数据结构体对象 */
     struct HdfDriverEntry g_lightDriverEntry = {
         .moduleVersion = 1,            // 灯模块版本号
         .moduleName = "HDF_LIGHT",     // 灯模块名，要与device_info.hcs文件里灯moduleName字段值一样
         .Bind = BindLightDriver,       // 灯绑定函数
         .Init = InitLightDriver,       // 灯初始化函数
         .Release = ReleaseLightDriver, // 灯资源释放函数
     };
     /* 调用HDF_INIT将驱动入口注册到HDF框架中 */
     HDF_INIT(g_lightDriverEntry);
     ```

   - 基于HDF驱动框架，按照驱动Driver Entry程序，完成Light抽象驱动开发，主要由Bind、Init、Release、Dispatch函数接口实现。

     ```c
     /* Light驱动对外发布的能力 */
     static int32_t DispatchLight(struct HdfDeviceIoClient *client,
         int32_t cmd, struct HdfSBuf *data, struct HdfSBuf *reply)
     {
         .....
         if (cmd == LIGHT_IO_CMD_GET_INFO_LIST) {
             CHECK_LIGHT_NULL_PTR_RETURN_VALUE(reply, HDF_ERR_INVALID_PARAM);
             return GetAllLightInfo(data, reply);
         }
     
         CHECK_LIGHT_NULL_PTR_RETURN_VALUE(data, HDF_ERR_INVALID_PARAM);
         (void)OsalMutexLock(&drvData->mutex);
         if (!HdfSbufReadInt32(data, &lightId)) {
             HDF_LOGE("%s: sbuf read lightId fail", __func__);
             (void)OsalMutexUnlock(&drvData->mutex);
             return HDF_ERR_INVALID_PARAM;
         }
         .....
         ret = DispatchCmdHandle(lightId, data, reply);
         (void)OsalMutexUnlock(&drvData->mutex);
         return ret;
     }
     
     /* Light驱动对外提供的服务绑定到HDF框架 */
     int32_t BindLightDriver(struct HdfDeviceObject *device)
     {
         struct LightDriverData *drvData = NULL;
     
         CHECK_LIGHT_NULL_PTR_RETURN_VALUE(device, HDF_FAILURE);
         /* 私有接口分配资源 */
         drvData = (struct LightDriverData *)OsalMemCalloc(sizeof(*drvData));
         CHECK_LIGHT_NULL_PTR_RETURN_VALUE(drvData, HDF_ERR_MALLOC_FAIL);
         /* 需要发布的接口函数 */
         drvData->ioService.Dispatch = DispatchLight;
         drvData->device = device;
         device->service = &drvData->ioService;
         g_lightDrvData = drvData;
         return HDF_SUCCESS;
     }
     
     /* Light驱动初始化入口函数*/
     int32_t InitLightDriver(struct HdfDeviceObject *device)
     { 
     	.....
         /* 工作队列初始化 */
         if (HdfWorkQueueInit(&drvData->workQueue, LIGHT_WORK_QUEUE_NAME) != HDF_SUCCESS) {
             HDF_LOGE("%s: init workQueue fail!", __func__);
             return HDF_FAILURE;
         }
         /* 工作项初始化 */
         if (HdfWorkInit(&drvData->work, LightWorkEntry, (void*)drvData) != HDF_SUCCESS) {
             HDF_LOGE("%s: init work fail!", __func__);
             return HDF_FAILURE;
         }
         /* 解析HCS配置文件 */
         if (GetLightConfigData(device->property) != HDF_SUCCESS) {
             HDF_LOGE("%s: get light config fail!", __func__);
             return HDF_FAILURE;
         }
         /* 设置GPIO引脚方向 */
         if (SetLightGpioDir(drvData) != HDF_SUCCESS) {
             HDF_LOGE("%s: set light gpio dir fail!", __func__);
             return HDF_FAILURE;
         }
     
         return HDF_SUCCESS;
     }
     
     /* 释放Light驱动初始化时分配的资源 */
     void ReleaseLightDriver(struct HdfDeviceObject *device)
     { 
         .....
         /* 释放已分配资源 */
         for (i = LIGHT_TYPE_NONE; i < LIGHT_TYPE_BUTT; ++i) {
     
             if (drvData->info[i] != NULL) {
                 OsalMemFree(drvData->info[i]);
                 drvData->info[i] = NULL;
             }
         }
         /* 销毁工作队列资源 */
         HdfWorkDestroy(&drvData->work);
         HdfWorkQueueDestroy(&drvData->workQueue);
         (void)OsalMutexDestroy(&drvData->mutex);
         OsalMemFree(drvData);
         g_lightDrvData = NULL;
     }
     ```

   - Light设备管理模块负责系统中Light器件接口发布。在系统启动过程中，HDF框架机制通过Light Host里的设备HCS配置信息，加载设备管理驱动。

     ```c
     /* Light设备HCS配置 */
     light :: host {
         hostName = "light_host";
         device_light :: device {
             device0 :: deviceNode {
                 policy = 2;                           // 驱动服务发布的策略（0：不提供服务，1：对内核态发布服务；2：对内核态和用户态都发布服务）
                 priority = 100;                       // Light驱动启动优先级（0-200），值越大优先级越低，建议配置为100，优先级相同则不保证device的加载顺序
                 preload = 0;                          // 驱动按需加载字段，0：加载；2：不加载
                 permission = 0664;                    // 驱动创建设备节点权限
                 moduleName = "HDF_LIGHT";             // Light驱动名称，该字段的值必须和驱动入口结构的moduleName值一致
                 serviceName = "hdf_light";            // Light驱动对外发布服务的名称，必须唯一
                 deviceMatchAttr = "hdf_light_driver"; // 驱动私有数据匹配的关键字，必须和驱动私有数据配置表中的match_attr值相等
             }
         }
     }
     ```

2. 调用配置解析接口，完成器件属性信息解析、器件寄存器解析，并注册到Light设备管理中。

   ```c
   /* 分配资源，解析灯HCS配置。 */
   static int32_t ParseLightInfo(const struct DeviceResourceNode *node, const struct DeviceResourceIface *parser)
   {
       .....
       /* 从HCS配置获取支持的灯类型个数 */
       drvData->lightNum = parser->GetElemNum(light, "lightId");
       ....
       for (i = 0; i < drvData->lightNum; ++i) {
           /* 获取灯的类型 */
           ret = parser->GetUint32ArrayElem(light, "lightId", i, &temp, 0);
           CHECK_LIGHT_PARSER_RESULT_RETURN_VALUE(ret, "lightId");
       }
   
       for (i = 0; i < drvData->lightNum; ++i) {
           .....
           /* 类型作为下标开辟空间 */
           drvData->info[temp] = (struct LightDeviceInfo *)OsalMemCalloc(sizeof(struct LightDeviceInfo));
           .....
           /* 将Light设备信息进行填充 */
           ret = parser->GetUint32(node, "busRNum", (uint32_t *)&drvData->info[temp]->busRNum, 0);
           if (ret != HDF_SUCCESS) {
               /* 如果没有成功获取busNum，代表不支持设置busNum对应颜色的灯。 */
               drvData->info[temp]->busRNum = LIGHT_INVALID_GPIO;
           }
           ret = parser->GetUint32(node, "busGNum", (uint32_t *)&drvData->info[temp]->busGNum, 0);
           if (ret != HDF_SUCCESS) {
               drvData->info[temp]->busGNum = LIGHT_INVALID_GPIO;
           }
           ret = parser->GetUint32(node, "busBNum", (uint32_t *)&drvData->info[temp]->busBNum, 0);
           if (ret != HDF_SUCCESS) {
               drvData->info[temp]->busBNum = LIGHT_INVALID_GPIO;
           }
       }
       .....
       return HDF_SUCCESS;
   }
   ```

3. 完成Light类型获取、闪烁模式设置和停止的接口开发，并实现根据闪烁模式创建和销毁定时器。

   ```c
   /* Light驱动服务调用GetAllLightInfo接口获取灯类型，调用TurnOnLight接口启动闪烁模式，
      调用TurnOffLight接口停止闪烁。 */
   static int32_t GetAllLightInfo(struct HdfSBuf *data, struct HdfSBuf *reply)
   {
       .....
       /* 获取灯类型的个数 */
       if (!HdfSbufWriteUint32(reply, drvData->lightNum)) {
           HDF_LOGE("%s: write sbuf fail", __func__);
           return HDF_FAILURE;
       }
       for (i = 0; i < LIGHT_TYPE_BUTT; ++i) {
           if (drvData->info[i] == NULL) {
               continue;
           }
           lightInfo.lightId = i;
           lightInfo.reserved = NULL;
           /* 将Light设备信息填充进reply */
           if (!HdfSbufWriteBuffer(reply, &lightInfo, sizeof(lightInfo))) {
               HDF_LOGE("%s: write sbuf fail", __func__);
               return HDF_FAILURE;
           }
       }
   
       return HDF_SUCCESS;
   }
   
   /* 更新指定类型灯的状态 */
   static int32_t UpdateLight(uint32_t lightId, uint32_t lightOn)
   {
       .....
       /* 如果用户传入的亮度值无效，则使用系统默认的亮度值。 */
       if (drvData->info[lightId]->lightBrightness == 0) {
           lightBrightness = drvData->info[lightId]->defaultBrightness;
       } else {
           lightBrightness = drvData->info[lightId]->lightBrightness;
       }
       /* 如果0-7bit不等于0，根据lightOn的状态，输出蓝色对应的GPIO引脚。 */
       if ((lightBrightness & LIGHT_MAKE_B_BIT) != 0) {
           ret = WriteGpio(drvData->info[lightId]->busBNum, lightOn);
           if (ret != HDF_SUCCESS) {
               HDF_LOGE("%s: write blue gpio fail", __func__);
               return HDF_FAILURE;
           }
       }
       /* 如果8-15bit不等于0，根据lightOn的状态，输出绿色对应的GPIO引脚。 */
       if ((lightBrightness & LIGHT_MAKE_G_BIT) != 0) {
           ret = WriteGpio(drvData->info[lightId]->busGNum, lightOn);
           if (ret != HDF_SUCCESS) {
               HDF_LOGE("%s: write green gpio fail", __func__);
               return HDF_FAILURE;
           }
       }
       /* 如果16-23bit不等于0，根据lightOn的状态，输出红色对应的GPIO引脚。 */
       if ((lightBrightness & LIGHT_MAKE_R_BIT) != 0) {
           ret = WriteGpio(drvData->info[lightId]->busRNum, lightOn);
           if (ret != HDF_SUCCESS) {
               HDF_LOGE("%s: write red gpio fail", __func__);
               return HDF_FAILURE;
           }
       }
       .....
   }

   /* 按照指定的类型和用户传入的参数使能灯 */
   static int32_t TurnOnLight(uint32_t lightId, struct HdfSBuf *data, struct HdfSBuf *reply)
   {
       .....
       /* 接收用户传入的亮度值。24-31bit表示扩展位，16-23bit表示红色，8-15bit表示绿色，0-7bit表示蓝色。如果字段不等于0，表示使能相应颜色的灯。
          如果支持亮度设置，则通过0-255设置不同的亮度。 */
       drvData->info[lightId]->lightBrightness = buf->lightBrightness;
       /* 常亮模式 */
       if (buf->flashEffect.flashMode == LIGHT_FLASH_NONE) {
           return UpdateLight(lightId, LIGHT_STATE_START);
       }
       /* 闪烁模式 */
       if (buf->flashEffect.flashMode == LIGHT_FLASH_TIMED) {
           drvData->info[lightId]->lightState = LIGHT_STATE_START;
           /* 用户设置的闪烁时间小于系统支持的最短时间，采用系统配置的时间(HCS配置)。 */
           drvData->info[lightId]->onTime = buf->flashEffect.onTime < drvData->info[lightId]->onTime ?
           drvData->info[lightId]->onTime : buf->flashEffect.onTime;
           drvData->info[lightId]->offTime = buf->flashEffect.offTime < drvData->info[lightId]->offTime ?
           drvData->info[lightId]->offTime : buf->flashEffect.offTime;
           /* 创建定时器 */
           if (OsalTimerCreate(&drvData->timer, drvData->info[lightId]->onTime,
               LightTimerEntry, (uintptr_t)lightId) != HDF_SUCCESS) {
               HDF_LOGE("%s: create light timer fail!", __func__);
               return HDF_FAILURE;
           }
           /* 启动周期定时器 */
           if (OsalTimerStartLoop(&drvData->timer) != HDF_SUCCESS) {
               HDF_LOGE("%s: start light timer fail!", __func__);
               return HDF_FAILURE;
           }
       }
       return HDF_SUCCESS;
   }
   
   /* 按照指定的类型关闭灯 */
   static int32_t TurnOffLight(uint32_t lightId, struct HdfSBuf *data, struct HdfSBuf *reply)
   {
       /* 删除定时器 */
       if (drvData->timer.realTimer != NULL) {
   
           if (OsalTimerDelete(&drvData->timer) != HDF_SUCCESS) {
               HDF_LOGE("%s: delete haptic timer fail!", __func__);
           }
       }
       if (UpdateLight(lightId, LIGHT_STATE_STOP) != HDF_SUCCESS) {
           HDF_LOGE("%s: gpio write fail", __func__);
           return HDF_FAILURE;
       }
   
       return HDF_SUCCESS;
   }
   ```

### 调测验证

驱动开发完成后，在灯单元测试里面开发自测试用例，验证驱动基本功能。测试环境采用开发者自测试平台。

```c++
/* 用例执行前，初始化Light接口实例。 */
void HdfLightTest::SetUpTestCase()
{
    g_lightDev = NewLightInterfaceInstance();
    if (g_lightDev == nullptr) {
        printf("test light get Module instance fail\n\r");
    }
    int32_t ret = g_lightDev->GetLightInfo(&g_lightInfo, &g_count);
    if (ret == -1) {
        printf("get light informations fail\n\r");
    }
}

/* 用例执行后，释放用例资源。 */
void HdfLightTest::TearDownTestCase()
{
    if(g_lightDev != nullptr){
        FreeLightInterfaceInstance();
        g_lightDev = nullptr;
    }
}

/* 获取测试灯类型 */
HWTEST_F(HdfLightTest, GetLightList001, TestSize.Level1)
{
    struct LightInfo *info = nullptr;

    if (g_lightInfo == nullptr) {
        EXPECT_NE(nullptr, g_lightInfo);
        return;
    }

    printf("get light list num[%d]\n\r", g_count);
    info = g_lightInfo;

    for (int i = 0; i < g_count; ++i) {
        printf("get lightId[%d]\n\r", info->lightId);
        EXPECT_GE(info->lightId, g_minLightId);
        EXPECT_LE(info->lightId, g_maxLightId);
        info++;
    }
}

/* 测试灯常亮模式 */
HWTEST_F(HdfLightTest, EnableLight001, TestSize.Level1)
{
    int32_t i;
    int32_t ret;
    struct LightEffect effect;
    effect->lightBrightness = 0x00800000;
    effect->flashEffect.flashMode = LIGHT_FLASH_NONE;
    effect->flashEffect.onTime = 0;
    effect->flashEffect.offTime = 0;

    for (i = 0; i < g_count; ++i) {

        ret = g_lightDev->TurnOnLight(g_lightInfo[i]->lightId, effect);
        EXPECT_EQ(0, ret);

        OsalSleep(LIGHT_WAIT_TIME);

        ret = g_lightDev->TurnOffLight(type);
        EXPECT_EQ(0, ret);
    }
}

/* 测试灯闪烁模式 */
HWTEST_F(HdfLightTest, EnableLight002, TestSize.Level1)
{
    int32_t i;
    int32_t ret;
    struct LightEffect effect;
    effect->lightBrightness = 0x00800000;
    effect->flashEffect.flashMode = LIGHT_FLASH_TIMED;
    effect->flashEffect.onTime = g_onTime;
    effect->flashEffect.offTime = g_offTime;

    for (i = 0; i < g_count; ++i) {

        ret = g_lightDev->TurnOnLight(g_lightInfo[i]->lightId, effect);
        EXPECT_EQ(0, ret);

        OsalSleep(LIGHT_WAIT_TIME);

        ret = g_lightDev->TurnOffLight(type);
        EXPECT_EQ(0, ret);
    }
}
```
