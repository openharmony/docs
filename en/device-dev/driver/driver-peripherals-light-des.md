# Light


## Overview

### Light

The light driver model provides APIs for the upper-layer light hardware service layer to control lights, including obtaining the light type, setting the lighting mode and blinking effect, and turning on or off a light. This model implements functionalities such as cross-OS migration and differentiated configurations based on the Hardware Driver Foundation (HDF) to achieve the goal of "one-time development for cross-system deployment" of the light driver. The figure below shows the light driver model.

**Figure 1** Light driver model

![Light driver model](figures/light_driver_model.png)

### Working Principles

The figure below shows how the light driver works.

**Figure 2** How light driver works

![How light driver works](figures/light_working.png)

The following uses the Hi3516D V300 development board powered by the standard system as an example to describe how the light driver works.

1. The light driver reads the light device management configuration from **Light Host** in the **device_info.hcs** file.
2. The light driver reads the light data configuration from the **light_config.hcs** file.
3. The light driver parses information about the light device management configuration and associates with the corresponding device driver.
4. The light proxy delivers an instruction to the light stub.
5. The light stub delivers an instruction to the light controller.
6. The light abstract driver interface is started.

## Development Guidelines

### When to Use

Light control is widely used in daily life. For example, a light is blinking when a mobile phone receives an SMS message or has low battery level, and a light changes its colors based on the device charging status. These actions are implemented by calling the APIs provided by the light driver model.

### Available APIs

The light driver model provides APIs to obtain information about all the lights in the system and dynamically set the blinking mode and duration. The light hardware service calls the **GetLightInfo** method to obtain basic information about the light and calls the **TurnOnLight** method to make the light blinking. The table below describes the APIs of the light driver model.

**Table 1** APIs of the light driver model

| API                                                      | Description                                                    |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| int32_t (*GetLightInfo)(struct LightInfo **lightInfo, uint32_t *count) | Obtains information about all lights in the system. **lightInfo** indicates the double pointer to the basic light information. **count** indicates the pointer to the number of lights.|
| int32_t (*TurnOnLight)(uint32_t type, struct LightEffect *effect) | Turns on available lights in the list based on the specified light type. **type** indicates the light type, and **effect** indicates the pointer to the blinking effect.|
| int32_t (*TurnOffLight)(uint32_t type)                       | Turns off available lights in the light list based on the specified light type. **type** indicates the light type.                      |

### How to Develop
1. Based on the HDF and the driver entry, complete the light abstract driver development (using the **Bind**, **Init**, **Release**, and **Dispatch** functions), resource configuration, and HCS parsing. Configure the light driver device information.

   - Call **HDF_INIT** to register the driver entry with the HDF. Generally, the HDF calls the **Bind** function and then the **Init** function to load the driver. If **Init** fails to be called, the HDF calls **Release** to release driver resources and exit.
     The light driver model uses HDF configuration source (HCS). For details about HCS fields, see [Configuration Management](https://gitee.com/openharmony/docs/blob/master/en/device-dev/driver/driver-hdf-manage.md).
     The light driver entry is defined as follows:

     ```c
     /* Register the light entry data structure object. */
     struct HdfDriverEntry g_lightDriverEntry = {
         .moduleVersion = 1, // Light module version.
         .moduleName = "HDF_LIGHT", // Light module name, which must be the same as the value of moduleName in the device_info.hcs file.
         .Bind = BindLightDriver, // BInd the light driver.
         .Init = InitLightDriver, // Initialize the light driver.
         .Release = ReleaseLightDriver, // Release the light resources.
     };
     /* Call HDF_INIT to register the driver entry with the HDF. The HDF calls the Bind function and then the Init function to load a driver. If Init fails to be called, the HDF calls Release to release driver resources and exit. */
     HDF_INIT(g_lightDriverEntry);
     ```

   - Develop the light abstract driver. Specifically, implement the **Bind**, **Init**, **Release**, and **Dispatch** functions.

     ```c
     /* Dispatch the light driver. */
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
         if (!HdfSbufReadInt32(data, &lightType)) {
             HDF_LOGE("%s: sbuf read lightType failed", __func__);
             (void)OsalMutexUnlock(&drvData->mutex);
             return HDF_ERR_INVALID_PARAM;
         }
         .....
         ret = DispatchCmdHandle(lightType, data, reply);
         (void)OsalMutexUnlock(&drvData->mutex);
         return ret;
     }
     
     /* Bind the external service provided by the light driver to the HDF. */
     int32_t BindLightDriver(struct HdfDeviceObject *device)
     {
         struct LightDriverData *drvData = NULL;
     
         CHECK_LIGHT_NULL_PTR_RETURN_VALUE(device, HDF_FAILURE);
         /* Allocate resources for private interfaces. */
         drvData = (struct LightDriverData *)OsalMemCalloc(sizeof(*drvData));
         CHECK_LIGHT_NULL_PTR_RETURN_VALUE(drvData, HDF_ERR_MALLOC_FAIL);
         /* Functions to be dispatched. */
         drvData->ioService.Dispatch = DispatchLight;
         drvData->device = device;
         device->service = &drvData->ioService;
         g_lightDrvData = drvData;
         return HDF_SUCCESS;
     }
     
     /* Initialize the light driver. */
     int32_t InitLightDriver(struct HdfDeviceObject *device)
     { 
     	.....
         /* Initialize the workqueue. */
         if (HdfWorkQueueInit(&drvData->workQueue, LIGHT_WORK_QUEUE_NAME) != HDF_SUCCESS) {
             HDF_LOGE("%s: init workQueue fail!", __func__);
             return HDF_FAILURE;
         }
         /* Initialize work items. */
         if (HdfWorkInit(&drvData->work, LightWorkEntry, (void*)drvData) != HDF_SUCCESS) {
             HDF_LOGE("%s: init workQueue fail!", __func__);
             return HDF_FAILURE;
         }
         /* Parse the HCS. */
         if (GetLightConfigData(device->property) != HDF_SUCCESS) {
             HDF_LOGE("%s: get light config fail!", __func__);
             return HDF_FAILURE;
         }
     
         return HDF_SUCCESS;
     }
     
     /* Release the resources allocated for driver initialization. */
     void ReleaseLightDriver(struct HdfDeviceObject *device)
     { 
         .....
         /* Release the allocated resources. */
         for (i = LIGHT_TYPE_NONE; i < LIGHT_TYPE_BUTT; ++i) {
     
             if (drvData->info[i] != NULL) {
                 OsalMemFree(drvData->info[i]);
                 drvData->info[i] = NULL;
             }
         }
         /* Destroy workqueue resources. */
         HdfWorkDestroy(&drvData->work);
         HdfWorkQueueDestroy(&drvData->workQueue);
         (void)OsalMutexDestroy(&drvData->mutex);
         OsalMemFree(drvData);
         g_lightDrvData = NULL;
     }
     ```

   - The light device management module dispatches light device APIs in the system. During the system startup process, the HDF loads the device management driver from the HCS of the light host.

     ```
     /* Light device HCS */
     device_light :: device {
         device0 :: deviceNode {
             policy = 2; // Driver service dispatch policy (0: no service is dispatched; 1: services are dispatched to the kernel mode; 2: services are dispatched to both the kernel mode and user mode)
             priority = 100; // Light driver startup priority. The value ranges from 0 to 200. A larger value indicates a lower priority. The value 100 is recommended. If the priorities are the same, the device loading sequence cannot be ensured.
             preload = 0; // Field for specifying whether to load the driver. The value 0 means to load the driver, and 2 means the opposite.
             permission = 0664; // Permission for the driver to create a device node.
             moduleName = "HDF_LIGHT"; // Light driver name. The value of this field must be the same as that of moduleName in the HdfDriverEntry structure.
             serviceName = "hdf_light"; // Service name of the driver, which must be unique.
             deviceMatchAttr = "hdf_light_driver"; // Keyword for matching the private data of the driver. The value must be the same as that of match_attr in the private data configuration table of the driver.
         }
     ```

2. Parse the device attribute information and registers, and register them with the light device management module.

   ```c
   /* Allocate resources and parse the HCS. */
   static int32_t ParseLightInfo(const struct DeviceResourceNode *node)
   {
       .....
       /* Obtain the number of supported light types from the HCS. */
       drvData->lightNum = parser->GetElemNum(light, "lightType");
       ....
       for (i = 0; i < drvData->lightNum; ++i) {
            /* Obtains the light type information. */
            ret = parser->GetUint32ArrayElem(light, "lightType", i, &temp, 0);
            CHECK_LIGHT_PARSER_RESULT_RETURN_VALUE(ret, "lightType");
       }
   
       for (i = 0; i < drvData->lightNum; ++i) {
       .....
       /* Types are used as subscripts to create space. */
       drvData->info[temp] = (struct LightDeviceInfo *)OsalMemCalloc(sizeof(struct LightDeviceInfo));
       .....
       /* Fill in the light device information. */
       ret = parser->GetUint32(light, "busRNum", &drvData->info[temp]->busRNum, 0);
       CHECK_LIGHT_PARSER_RESULT_RETURN_VALUE(ret, "busRNum");
       ret = parser->GetUint32(light, "busGNum", &drvData->info[temp]->busGNum, 0);
       CHECK_LIGHT_PARSER_RESULT_RETURN_VALUE(ret, "busGNum");
       ret = parser->GetUint32(light, "busBNum", &drvData->info[temp]->busBNum, 0);
       CHECK_LIGHT_PARSER_RESULT_RETURN_VALUE(ret, "busBNum");
       .....
       return HDF_SUCCESS;
   }
   ```

3. Call related APIs to obtain the light type, turn on and off lights, and create and delete the timer based on the blinking mode. 

   ```c
   /* Call GetAllLightInfo to obtain the light type. Call Enable to enable the blinking mode. 
      Call Disable to stop blinking. */
   static int32_t GetAllLightInfo(struct HdfSBuf *data, struct HdfSBuf *reply)
   {
       .....
       /* Obtain the number of light types. */
       if (!HdfSbufWriteUint32(reply, drvData->lightNum)) {
           HDF_LOGE("%s: write sbuf failed", __func__);
           return HDF_FAILURE;
       }
       for (i = 0; i < LIGHT_TYPE_BUTT; ++i) {
           if (drvData->info[i] == NULL) {
               continue;
           }
           lightInfo.lightType = i;
           lightInfo.reserved = NULL;
           /* Fill the light device information into the reply. */
           if (!HdfSbufWriteBuffer(reply, &lightInfo, sizeof(lightInfo))) {
               HDF_LOGE("%s: write sbuf failed", __func__);
               return HDF_FAILURE;
           }
       }
   
       return HDF_SUCCESS;
   }
   
   /* Enable lights based on the specified light type and input parameters. */
   static int32_t Enable(uint32_t lightType, struct HdfSBuf *data, struct HdfSBuf *reply)
   {
       .....
       /* Set the light color based on the brightness value passed in. Red: bits 16–31; Green: bits 8–15; Blue: bits 0–7 */
       if ((drvData->info[lightType]->lightBrightness & LIGHT_MAKE_R_BIT) != 0) {
           drvData->info[lightType]->busNum = drvData->info[lightType]->busRNum;
       } else if ((drvData->info[lightType]->lightBrightness & LIGHT_MAKE_G_BIT) != 0) {
           drvData->info[lightType]->busNum = drvData->info[lightType]->busGNum;
       } else if ((drvData->info[lightType]->lightBrightness & LIGHT_MAKE_B_BIT) != 0) {
           drvData->info[lightType]->busNum = drvData->info[lightType]->busBNum;
       }
       /* The light is steady on. */
       if (buf->flashEffect.flashMode == LIGHT_FLASH_NONE) {
   
           if (GpioWrite(drvData->info[lightType]->busNum, GPIO_VAL_HIGH) != HDF_SUCCESS) {
               return HDF_FAILURE;
           }
       }
       /* The light is blinking. */
       if (buf->flashEffect.flashMode == LIGHT_FLASH_TIMED) {
           drvData->info[lightType]->lightState = LIGHT_STATE_START;
           /* If the specified blinking duration is less than the minimum time period supported by the system, the time configured by the system (in HCS) is used. */
           drvData->info[lightType]->onTime = buf->flashEffect.onTime < drvData->info[lightType]->onTime ?
           drvData->info[lightType]->onTime : buf->flashEffect.onTime;
           drvData->info[lightType]->offTime = buf->flashEffect.offTime < drvData->info[lightType]->offTime ?
           drvData->info[lightType]->offTime : buf->flashEffect.offTime;
           /* Create a timer. */
           if (OsalTimerCreate(&drvData->timer, drvData->info[lightType]->onTime,
               LightTimerEntry, (uintptr_t)lightType) != HDF_SUCCESS) {
                HDF_LOGE("%s: create light timer fail!", __func__);
                return HDF_FAILURE;
           }
           /* Start the periodic timer. */
           if (OsalTimerStartLoop(&drvData->timer) != HDF_SUCCESS) {
                HDF_LOGE("%s: start light timer fail!", __func__);
                return HDF_FAILURE;
           }
       }
       return HDF_SUCCESS;
   }
   
   /* Turn off lights based on the specified light type. */
   static int32_t Disable(uint32_t lightType, struct HdfSBuf *data, struct HdfSBuf *reply)
   {
       /* Delete the timer. */
       if (drvData->timer.realTimer != NULL) {
   
           if (OsalTimerDelete(&drvData->timer) != HDF_SUCCESS) {
               HDF_LOGE("%s: delete haptic timer fail!", __func__);
           }
       }
       /* Power off the corresponding GPIO. */
       if (GpioWrite(drvData->info[lightType]->busRNum, GPIO_VAL_LOW) != HDF_SUCCESS){
           HDF_LOGE("%s: gpio write failed", __func__);
           return HDF_FAILURE;
       }
   
       return HDF_SUCCESS;
   }
   ```

### Verification

After the driver is developed, develop auto-test cases in the light unit test to verify the basic functionalities of the driver. Use the developer self-test platform as the test environment.

```c++
/* Initialize the light interface instance before executing the test case. */
void HdfLightTest::SetUpTestCase()
{
    g_lightDev = NewLightInterfaceInstance();
    if (g_lightDev == nullptr) {
        printf("test light get Module instance failed\n\r");
    }
    int32_t ret = g_lightDev->GetLightInfo(&g_lightInfo, &g_count);
    if (ret == -1) {
        printf("get light informations failed\n\r");
    }
}

/* After the test case is executed, release the resources used by the test case. */
void HdfLightTest::TearDownTestCase()
{
    if(g_lightDev != nullptr){
        FreeLightInterfaceInstance();
        g_lightDev = nullptr;
    }
}

/* Obtain the light type. */
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
        printf("get lightId[%d]\n\r", info->lightType);
        EXPECT_GE(info->lightType, g_minLightType);
        EXPECT_LE(info->lightType, g_maxLightType);
        info++;
    }
}

/* Verify the steady on state of the light. */
HWTEST_F(HdfLightTest, EnableLight001, TestSize.Level1)
{
    int32_t i;
    int32_t ret;
    struct LightEffect effect;
    effect->lightBrightness = 0x80000000;
    effect->flashEffect.flashMode = LIGHT_FLASH_NONE;
    effect->flashEffect.onTime = 0;
    effect->flashEffect.offTime = 0;

    for (i = 0; i < g_count; ++i) {

        ret = g_lightDev->TurnOnLight(g_lightInfo[i]->lightType, effect);
        EXPECT_EQ(0, ret);

        OsalSleep(LIGHT_WAIT_TIME);

        ret = g_lightDev->TurnOffLight(type);
        EXPECT_EQ(0, ret);
    }
}

/* Verify the blinking mode of the light. */
HWTEST_F(HdfLightTest, EnableLight002, TestSize.Level1)
{
    int32_t i;
    int32_t ret;
    struct LightEffect effect;
    effect->lightBrightness = 0x80000000;
    effect->flashEffect.flashMode = LIGHT_FLASH_TIMED;
    effect->flashEffect.onTime = g_onTime;
    effect->flashEffect.offTime = g_offTime;

    for (i = 0; i < g_count; ++i) {

        ret = g_lightDev->TurnOnLight(g_lightInfo[i]->lightType, effect);
        EXPECT_EQ(0, ret);

        OsalSleep(LIGHT_WAIT_TIME);

        ret = g_lightDev->TurnOffLight(type);
        EXPECT_EQ(0, ret);
    }
}
```
