# Light


## Overview

### Introduction

The light driver model provides APIs for the upper-layer light hardware service layer to control lights, including obtaining the light type, setting the lighting mode and blinking effect, and turning on or off a light. This model implements cross-OS porting and differentiated configurations based on the Hardware Driver Foundation (HDF) to achieve the goal of "one-time development for cross-system deployment" of the light driver. 

The figure below shows the light driver model.

**Figure 1** Light driver model

![Light driver model](figures/light_driver_model.png)

### Working Principles

The figure below shows how the light driver works.

**Figure 2** How light driver works

![How light driver works](figures/light_working.png)

The following describes how to start and run the light module driver on an RK3568 board that runs the standard system.

1. The Device Manager reads the Light device management configuration from the **device_info.hcs** file.
2. The Device Manager reads the light data configuration from the **light_config.hcs** file.
3. The HCS Parser parses the light device management configuration, loads the Light Host, and controls the Host to load the driver.
4. The Light Proxy obtains the light HDI service instance and calls the Light Stub over Inter-Process Communication (IPC).
5. The Light Stub processes IPC-related service logic and calls the Light Controller after parameter deserialization.
6. The Light Controller implements the HDI APIs and calls the Light Abstract Driver APIs to operate the light devices.

## Development Guidelines

### When to Use

Light control is widely used in daily life. For example, a light is blinking when a mobile device receives an SMS message or has low battery level, and a light changes its colors based on the device charging status. These actions are implemented by calling the APIs provided by the light driver model.

### Available APIs

The light driver model provides APIs for obtaining information about all the lights in the system and dynamically setting the blinking mode and duration. The light hardware service calls **GetLightInfo()** to obtain the basic light information, calls **TurnOnLight()** to set the blinking effect, and calls **TurnOffLight()** to turn off lights. The following table describes the APIs of the light driver model.

**Table 1** APIs of the light driver model

**NOTE**<br>The following APIs are C interfaces. For details about the interface declaration, see [/drivers/peripheral/light/interfaces/include](https://gitee.com/openharmony/drivers_peripheral/tree/master/light/interfaces/include).

| API                                                      | Description                                                    |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| int32_t (*GetLightInfo)(struct LightInfo **lightInfo, uint32_t *count) | Obtains information about all types of lights in the system. <br>**lightInfo** indicates the double pointer to the light information obtained. <br>**count** indicates the pointer to the number of lights.|
| int32_t (*TurnOnLight)(uint32_t lightId,  struct LightEffect *effect) | Turns on available lights in the list based on the specified light type. <br>**lightId** indicates the light type, and **effect** indicates the pointer to the light effect.|
| int32_t (*TurnOffLight)(uint32_t lightId)                    | Turns off available lights in the list based on the specified light type.                      |
| int32_t (*TurnOnMultiLights)(uint32_t lightId, const struct LightColor *colors, const uint32_t count); | Turns on multiple sub-lights of a light based on the specified light type ID.          |

### How to Develop
Develop the light driver based on the HDF and driver entry, configure resources, and parse the HCS configuration file.

1. Configure the light driver in the host.

   - Light HCS file path: **vendor\hihope\rk3568\hdf_config\khdf\device_info\device_info.hcs**.

   - The code is as follows:

     ```c
     /* HCS of the light device. */
     light :: host {
         hostName = "light_host";
         device_light :: device {
             device0 :: deviceNode {
                 policy = 2;                           // Policy for the driver to publish services. If the value is 0, the driver does not publish services. If the value is 1, the driver publishes services to the kernel space. If the value is 2, the driver publishes services to both the kernel space and user space.
                 priority = 100;                       // Priority (0–200) for starting the light driver. A larger value indicates a lower priority. The recommended value is 100. If the priorities are the same, the device loading sequence is not ensured.
                 preload = 0;                          // The value 0 means to load the driver by default during the startup of the system. The value 2 means the opposite.
                 permission = 0664;                    // Permission for the device node created.
                 moduleName = "HDF_LIGHT";             // Light driver name. The value must be the same as the value of moduleName in the driver entry structure.
                 serviceName = "hdf_light";            // Service published by the light driver. The service name must be unique.
                 deviceMatchAttr = "hdf_light_driver"; // Keyword matching the private data of the driver. The value must be the same as that of match_attr in the private data configuration table of the driver.
             }
         }
     }
     ```

2. Configure the private HCS of the light driver.

   - Code path: **vendor\hihope\rk3568\hdf_config\khdf\light\light_config.hcs**.

   - The code is as follows:

     ```c
     root {
         lightConfig {
             boardConfig {
                 match_attr = "hdf_light_driver";
                 lightAttr {
                     light01 {
                         lightId = [1];    // Lightid can contain multiple logical light IDs. For example, 1 indicates the power indicator.
                         lightName = "battery";
                         lightNumber = 1;
                         busRNum = 147;    // GPIO value corresponding to red (light effect color).
                         busGNum = 146;    // GPIO value corresponding to green (light effect color).
                         busBNum = 149;    // GPIO value corresponding to blue (light effect color).
                         defaultBrightness = 0X00FFFFFF; // Default luminance value of the system. B: bits 0 to 7; R: bits 8 to 15; G: bits 16 to 23; extended bits 24 to 31.
                         onTime = 50;      // Minimum duration (in milliseconds) supported by the system when the flash is on.
                         offTime = 50;     // Minimum duration (in milliseconds) supported by the system when the flash is off.
                     }
                 }
             }
         }
     }
     ```

3. Implement the light driver in **drivers\hdf_core\framework\model\misc\light\driver\src\light_driver.c**.

   - Define the **HdfDriverEntry** object of the light driver. The driver entry function is defined as follows:

     ```c
     /* Register the light entry data structure object. */
     struct HdfDriverEntry g_lightDriverEntry = {
         .moduleVersion = 1,            // Version of the light module.
         .moduleName = "HDF_LIGHT",     // Light module name, which must be the same as the value of moduleName in the device_info.hcs file.
         .Bind = BindLightDriver,       // Bind() of the light driver.
         .Init = InitLightDriver,       // Init() of the light driver.
         .Release = ReleaseLightDriver, // Release() of the light driver.
     };
     /* Call HDF_INIT to register the driver entry with the HDF. When loading the driver, the HDF calls Bind() and then Init() to load the driver. If Init() fails to be called, the HDF calls Release() to release resources and exit. */
     HDF_INIT(g_lightDriverEntry);
     ```

   - Implement **Bind()** of the light driver.

     ```c
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
     ```

   - Implement **Init()** of the light driver.

     ```c
     /* Initialize the light driver. */
     int32_t InitLightDriver(struct HdfDeviceObject *device)
     {
         struct LightDriverData *drvData = NULL;
     
         drvData = (struct LightDriverData *)device->service;
     
         if (OsalMutexInit(&drvData->mutex) != HDF_SUCCESS) {
             return HDF_FAILURE;
         }
     	/* Initialize the workqueue. */
         if (HdfWorkQueueInit(&drvData->workQueue, LIGHT_WORK_QUEUE_NAME) != HDF_SUCCESS) {
             return HDF_FAILURE;
         }
     	/* Initialize work items. */
         if (HdfWorkInit(&drvData->work, LightWorkEntry, (void*)drvData) != HDF_SUCCESS) {
             return HDF_FAILURE;
         }
     	/* Parse the HCS. */
         if (GetLightConfigData(device->property) != HDF_SUCCESS) {
             return HDF_FAILURE;
         }
     	/* Set the GPIO pin direction. */
         if (SetLightGpioDir(drvData) != HDF_SUCCESS) {
             return HDF_FAILURE;
         }
     
         return HDF_SUCCESS;
     }
     ```

   - Implement **Release()** of the light driver. When the driver is unloaded or **Init** fails to be executed, **Release()** can be used to release resources. The implementation is as follows:

     ```c
     /* Release the resources allocated for driver initialization. */
     void ReleaseLightDriver(struct HdfDeviceObject *device)
     {
         int32_t i;
         struct LightDriverData *drvData = NULL;
         /* Release the allocated resources. */
         for (i = LIGHT_ID_NONE; i < LIGHT_ID_BUTT; ++i) {
             if (drvData->info[i] != NULL) {
                 OsalMemFree(drvData->info[i]);
                 drvData->info[i] = NULL;
             }
         }
     	/* Destroy the work queue resource if the sensor is in position. */
         HdfWorkDestroy(&drvData->work);
         HdfWorkQueueDestroy(&drvData->workQueue);
         (void)OsalMutexDestroy(&drvData->mutex);
         OsalMemFree(drvData);
         g_lightDrvData = NULL;
     }
     ```

   - The light driver parses the light device management configuration information from the HCS file.

     ```c
     /* Obtain the Light basic configuration from the HCS file. */
     static int32_t GetLightBaseConfigData(const struct DeviceResourceNode *node, const struct DeviceResourceIface *parser,
         uint32_t lightId)
     {
         int32_t ret;
         uint32_t *defaultBrightness = NULL;
         struct LightDriverData *drvData = NULL;
         const char *name = NULL;
     
         drvData = GetLightDrvData();
         CHECK_LIGHT_NULL_PTR_RETURN_VALUE(drvData, HDF_ERR_INVALID_PARAM);
         CHECK_LIGHT_NULL_PTR_RETURN_VALUE(node, HDF_ERR_INVALID_PARAM);
         CHECK_LIGHT_NULL_PTR_RETURN_VALUE(parser, HDF_ERR_INVALID_PARAM);
     	/* Types are used as subscripts to create space. */
         drvData->info[lightId] = (struct LightDeviceInfo *)OsalMemCalloc(sizeof(struct LightDeviceInfo));
         if (drvData->info[lightId] == NULL) {
             HDF_LOGE("%s: malloc fail", __func__);
             return HDF_FAILURE;
         }
     	 /* Fill in the light device information. */
         ret = parser->GetUint32(node, "busRNum", (uint32_t *)&drvData->info[lightId]->busRNum, 0);
         if (ret != HDF_SUCCESS) {
             drvData->info[lightId]->busRNum = LIGHT_INVALID_GPIO;
         }
     
         ret = parser->GetUint32(node, "busGNum", (uint32_t *)&drvData->info[lightId]->busGNum, 0);
         if (ret != HDF_SUCCESS) {
             drvData->info[lightId]->busGNum = LIGHT_INVALID_GPIO;
         }
     
         ret = parser->GetUint32(node, "busBNum", (uint32_t *)&drvData->info[lightId]->busBNum, 0);
         if (ret != HDF_SUCCESS) {
             drvData->info[lightId]->busBNum = LIGHT_INVALID_GPIO;
         }
     
         ret = parser->GetString(node, "lightName", &name, NULL);
         if (ret != HDF_SUCCESS) {
             HDF_LOGE("%s:get lightName failed!", __func__);
             return HDF_FAILURE;
         }
     
         if (strcpy_s(drvData->info[lightId]->lightInfo.lightName, NAME_MAX_LEN, name) != EOK) {
             HDF_LOGE("%s:copy lightName failed!", __func__);
             return HDF_FAILURE;
         }
     
         ret = parser->GetUint32(node, "lightNumber", (uint32_t *)&drvData->info[lightId]->lightInfo.lightNumber, 0);
         if (ret != HDF_SUCCESS) {
             HDF_LOGE("%s:get lightNumber failed!", __func__);
             return HDF_FAILURE;
         }
     
         defaultBrightness = (uint32_t *)&drvData->info[lightId]->defaultBrightness;
         ret = parser->GetUint32(node, "defaultBrightness", defaultBrightness, 0);
         CHECK_LIGHT_PARSER_RESULT_RETURN_VALUE(ret, "defaultBrightness");
         ret = parser->GetUint32(node, "onTime", &drvData->info[lightId]->onTime, 0);
         CHECK_LIGHT_PARSER_RESULT_RETURN_VALUE(ret, "onTime");
         ret = parser->GetUint32(node, "offTime", &drvData->info[lightId]->offTime, 0);
         CHECK_LIGHT_PARSER_RESULT_RETURN_VALUE(ret, "offTime");
     
         drvData->info[lightId]->lightBrightness = 0;
         drvData->info[lightId]->lightState = LIGHT_STATE_STOP;
     
         return HDF_SUCCESS;
     }
     ```

   - Allocate resources and parse the HCS configuration information as follows:

     ```c
     /* Allocate resources and parse the HCS. */
     static int32_t ParseLightInfo(const struct DeviceResourceNode *node, const struct DeviceResourceIface *parser)
     {
         int32_t ret;
         uint32_t i;
         uint32_t temp;
         struct LightDriverData *drvData = NULL;
     
         drvData = GetLightDrvData();
         CHECK_LIGHT_NULL_PTR_RETURN_VALUE(drvData, HDF_ERR_INVALID_PARAM);
         CHECK_LIGHT_NULL_PTR_RETURN_VALUE(node, HDF_ERR_INVALID_PARAM);
         CHECK_LIGHT_NULL_PTR_RETURN_VALUE(parser, HDF_ERR_INVALID_PARAM);
     	 /* Obtain the number of supported light types from the HCS. */
         drvData->lightNum = (uint32_t)parser->GetElemNum(node, "lightId");
         if (drvData->lightNum > LIGHT_ID_NUM) {
             HDF_LOGE("%s: lightNum cross the border", __func__);
             return HDF_FAILURE;
         }
     
         ret = memset_s(drvData->info, sizeof(drvData->info[LIGHT_ID_NONE]) * LIGHT_ID_BUTT, 0,
             sizeof(drvData->info[LIGHT_ID_NONE]) * LIGHT_ID_BUTT);
         CHECK_LIGHT_PARSER_RESULT_RETURN_VALUE(ret, "memset_s");
     
         for (i = 0; i < drvData->lightNum; ++i) {
             /* Obtain the light type. */
             ret = parser->GetUint32ArrayElem(node, "lightId", i, &temp, 0);
             CHECK_LIGHT_PARSER_RESULT_RETURN_VALUE(ret, "lightId");
     
             if (temp >= LIGHT_ID_BUTT) {
                 HDF_LOGE("%s: light id invalid para", __func__);
                 return HDF_FAILURE;
             }
     
             ret = GetLightBaseConfigData(node, parser, temp);
             if (ret != HDF_SUCCESS) {
                 HDF_LOGE("%s: get light base config fail", __func__);
                 return HDF_FAILURE;
             }
         }
     
         return HDF_SUCCESS;
     }
     ```

   - Use the internal APIs of the light driver to obtain the light type information, set the blinking mode, turn on and trun off lights, and create and destroy timers based on the blinking mode.

     - The **GetAllLightInfo** interface is implemented as follows:

       ```c
       /* The light driver service calls GetAllLightInfo() to obtain the light type information. */
       static int32_t GetAllLightInfo(struct HdfSBuf *data, struct HdfSBuf *reply)
       {
           (void)data;
           uint32_t i;
           struct LightInfo lightInfo;
           struct LightDriverData *drvData = NULL;
       
           drvData = GetLightDrvData();
           CHECK_LIGHT_NULL_PTR_RETURN_VALUE(drvData, HDF_ERR_INVALID_PARAM);
           CHECK_LIGHT_NULL_PTR_RETURN_VALUE(reply, HDF_ERR_INVALID_PARAM);
       
           if (!HdfSbufWriteUint32(reply, drvData->lightNum)) {
               HDF_LOGE("%s: write sbuf failed", __func__);
               return HDF_FAILURE;
           }
       
           for (i = 0; i < LIGHT_ID_BUTT; ++i) {
               if (drvData->info[i] == NULL) {
                   continue;
               }
               lightInfo.lightId = i;
       
               if (!HdfSbufWriteUint32(reply, lightInfo.lightId)) {
                   HDF_LOGE("%s: write lightId failed", __func__);
                   return HDF_FAILURE;
               }
       
               if (strcpy_s(lightInfo.lightName, NAME_MAX_LEN, drvData->info[i]->lightInfo.lightName) != EOK) {
                   HDF_LOGE("%s:copy lightName failed!", __func__);
                   return HDF_FAILURE;
               }
       
               if (!HdfSbufWriteString(reply, (const char *)lightInfo.lightName)) {
                   HDF_LOGE("%s: write lightName failed", __func__);
                   return HDF_FAILURE;
               }
       
               lightInfo.lightNumber = drvData->info[i]->lightInfo.lightNumber;
               if (!HdfSbufWriteUint32(reply, lightInfo.lightNumber)) {
                   HDF_LOGE("%s: write lightNumber failed", __func__);
                   return HDF_FAILURE;
               }
       
               lightInfo.lightType = HDF_LIGHT_TYPE_RGB_COLOR;
               if (!HdfSbufWriteUint32(reply, lightInfo.lightType)) {
                   HDF_LOGE("%s: write lightType failed", __func__);
                   return HDF_FAILURE;
               }
           }
       
           return HDF_SUCCESS;
       }
       ```

     - The **TurnOnLight** interface is implemented as follows:

       ```c
       /* Enable lights based on the specified light type and input parameters. */
       static int32_t TurnOnLight(uint32_t lightId, struct HdfSBuf *data, struct HdfSBuf *reply)
       {
           (void)reply;
           uint32_t len;
           struct LightEffect *buf = NULL;
           struct LightDriverData *drvData = NULL;
       
           drvData = GetLightDrvData();
           CHECK_LIGHT_NULL_PTR_RETURN_VALUE(drvData, HDF_ERR_INVALID_PARAM);
       
           if (drvData->info[lightId] == NULL) {
               HDF_LOGE("%s: light id info is null", __func__);
               return HDF_FAILURE;
           }
       
           if (!HdfSbufReadBuffer(data, (const void **)&buf, &len)) {
               HDF_LOGE("%s: light read data failed", __func__);
               return HDF_FAILURE;
           }
       	/* Receive the lightBrightness value passed in. Bits 24 to 31 indicate extension bits, bits 16 to 23 indicate red, bits 8 to 15 indicate green, and bits 0 to 7 indicate blue. If lightBrightness is not 0, enable the light in the specified color.
              Set the light brightness to a value ranging from 0 to 255 if supported. */
           if (buf->lightColor.colorValue.rgbColor.r != 0) {
               drvData->info[lightId]->lightBrightness |= 0X00FF0000;
           }
       
           if (buf->lightColor.colorValue.rgbColor.g != 0) {
               drvData->info[lightId]->lightBrightness |= 0X0000FF00;
           }
       
           if (buf->lightColor.colorValue.rgbColor.b != 0) {
               drvData->info[lightId]->lightBrightness |= 0X000000FF;
           }
       	/* The light is steady on. */
           if (buf->flashEffect.flashMode == LIGHT_FLASH_NONE) {
               return UpdateLight(lightId, LIGHT_STATE_START);
           }
       	/* The light is blinking. */
           if (buf->flashEffect.flashMode == LIGHT_FLASH_BLINK) {
               drvData->info[lightId]->onTime = (buf->flashEffect.onTime < drvData->info[lightId]->onTime) ?
               drvData->info[lightId]->onTime : buf->flashEffect.onTime;
               drvData->info[lightId]->offTime = (buf->flashEffect.offTime < drvData->info[lightId]->offTime) ?
               drvData->info[lightId]->offTime : buf->flashEffect.offTime;
       		/* Create a timer. */
               if (OsalTimerCreate(&drvData->timer, LIGHT_WAIT_TIME, LightTimerEntry, (uintptr_t)lightId) != HDF_SUCCESS) {
                   HDF_LOGE("%s: create light timer fail!", __func__);
                   return HDF_FAILURE;
               }
       		/* Start the timer. */
               if (OsalTimerStartLoop(&drvData->timer) != HDF_SUCCESS) {
                   HDF_LOGE("%s: start light timer fail!", __func__);
                   return HDF_FAILURE;
               }
           }
       
           return HDF_SUCCESS;
       }
       ```

     - The **TurnOffLight** interface is implemented as follows:

       ```c
       /* Turn off lights based on the specified light type. */
       static int32_t TurnOffLight(uint32_t lightId, struct HdfSBuf *data, struct HdfSBuf *reply)
       {
           (void)data;
           (void)reply;
           struct LightDriverData *drvData = NULL;
       
           drvData = GetLightDrvData();
           CHECK_LIGHT_NULL_PTR_RETURN_VALUE(drvData, HDF_ERR_INVALID_PARAM);
       
           if (drvData->info[lightId] == NULL) {
               HDF_LOGE("%s: light id info is null", __func__);
               return HDF_FAILURE;
           }
       
           if (UpdateLight(lightId, LIGHT_STATE_STOP) != HDF_SUCCESS) {
               HDF_LOGE("%s: gpio write failed", __func__);
               return HDF_FAILURE;
           }
       
           drvData->info[lightId]->lightState = LIGHT_STATE_STOP;
           drvData->info[lightId]->lightBrightness = 0;
       	/* Destroy the timer. */
           if (drvData->timer.realTimer != NULL) {
               if (OsalTimerDelete(&drvData->timer) != HDF_SUCCESS) {
                   HDF_LOGE("%s: delete light timer fail!", __func__);
                   return HDF_FAILURE;
               }
           }
       
           return HDF_SUCCESS;
       }
       ```

5. Implement the HDIs of the light controller.

   - Code path: **drivers\peripheral\light\hal\src\light_controller.c**.

   - The **GetLightInfo** interface is implemented as follows:

     ```c
     /* Read the light type information from HdfSBuf in the light abstract driver to LightInfo. */
     static int32_t ReadLightInfo(struct HdfSBuf *reply, struct LightDevice *priv)
     {
         struct LightInfo *pos = NULL;
         const char *name = NULL;
     
         if (!HdfSbufReadUint32(reply, &priv->lightNum)) {
             HDF_LOGE("%s: sbuf read lightNum failed", __func__);
             return HDF_FAILURE;
         }
     
         if (priv->lightInfoEntry != NULL) {
             OsalMemFree(priv->lightInfoEntry);
             priv->lightInfoEntry = NULL;
         }
     
         priv->lightInfoEntry = (struct LightInfo *)OsalMemCalloc(sizeof(*priv->lightInfoEntry) * priv->lightNum);
         if (priv->lightInfoEntry == NULL) {
             HDF_LOGE("%s: malloc fail", __func__);
             return HDF_FAILURE;
         }
     
         pos = priv->lightInfoEntry;
     
         for (uint32_t i = 0; i < priv->lightNum; ++i) {
             if (!HdfSbufReadUint32(reply, &pos->lightId)) {
                 HDF_LOGE("%{public}s:read lightId failed!", __func__);
                 return HDF_FAILURE;
             }
     
             name = HdfSbufReadString(reply);
             if (strcpy_s(pos->lightName, NAME_MAX_LEN, name) != EOK) {
                 HDF_LOGE("%{public}s:copy lightName failed!", __func__);
                 return HDF_FAILURE;
             }
     
             if (!HdfSbufReadUint32(reply, &pos->lightNumber)) {
                 HDF_LOGE("%{public}s:read lightNumber failed!", __func__);
                 return HDF_FAILURE;
             }
     
             if (!HdfSbufReadInt32(reply, &pos->lightType)) {
                 HDF_LOGE("%{public}s:read lightType failed!", __func__);
                 return HDF_FAILURE;
             }
             pos++;
         }
     
         return HDF_SUCCESS;
     }
     /* GetLightInfo interface implementation. */
     static int32_t GetLightInfo(struct LightInfo **lightInfo, uint32_t *count)
     {
         if ((lightInfo == NULL) || (count == NULL)) {
             HDF_LOGE("%s:line:%{public}d pointer is null and return ret", __func__, __LINE__);
             return HDF_FAILURE;
         }
     
         struct LightDevice *priv = GetLightDevicePriv();
     
         if (priv->lightNum > 0) {
             *count = priv->lightNum;
             *lightInfo = priv->lightInfoEntry;
             return HDF_SUCCESS;
         }
     
         (void)OsalMutexLock(&priv->mutex);
         struct HdfSBuf *reply = HdfSbufObtainDefaultSize();
         if (reply == NULL) {
             HDF_LOGE("%s: get sbuf failed", __func__);
             (void)OsalMutexUnlock(&priv->mutex);
             return HDF_FAILURE;
         }
     
         int32_t ret = SendLightMsg(LIGHT_IO_CMD_GET_INFO_LIST, NULL, reply);
         if (ret != HDF_SUCCESS) {
             HDF_LOGE("%{public}s: Light send cmd failed, ret[%{public}d]", __func__, ret);
             HdfSbufRecycle(reply);
             (void)OsalMutexUnlock(&priv->mutex);
             return ret;
         }
     
         if (ReadLightInfo(reply, priv) != HDF_SUCCESS) {
             HdfSbufRecycle(reply);
             (void)OsalMutexUnlock(&priv->mutex);
             return HDF_FAILURE;
         }
     
         HdfSbufRecycle(reply);
         (void)OsalMutexUnlock(&priv->mutex);
     
         *count = priv->lightNum;
         *lightInfo = priv->lightInfoEntry;
     
         return HDF_SUCCESS;
     }
     ```

   - The **OnLight** interface is implemented as follows:

     ```c
     static int32_t OnLight(uint32_t lightId, struct LightEffect *effect)
     {
         int32_t ret;
     
         if (effect == NULL) {
             HDF_LOGE("%{public}s: effect is NULL", __func__);
             return HDF_FAILURE;
         }
     
         ret = OnLightValidityJudgment(lightId, effect);
         if (ret != HDF_SUCCESS) {
             HDF_LOGE("%{public}s: effect is false", __func__);
             return ret;
         }
     
         struct LightDevice *priv = GetLightDevicePriv();
         (void)OsalMutexLock(&priv->mutex);
     
         struct HdfSBuf *msg = HdfSbufObtainDefaultSize();
         if (msg == NULL) {
             HDF_LOGE("%{public}s: Failed to obtain sBuf size", __func__);
             (void)OsalMutexUnlock(&priv->mutex);
             return HDF_FAILURE;
         }
     
         if (!HdfSbufWriteInt32(msg, lightId)) {
             HDF_LOGE("%{public}s: Light write id failed", __func__);
             HdfSbufRecycle(msg);
             (void)OsalMutexUnlock(&priv->mutex);
             return HDF_FAILURE;
         }
     
         if (!HdfSbufWriteInt32(msg, LIGHT_OPS_IO_CMD_ENABLE)) {
             HDF_LOGE("%{public}s: Light write enable failed", __func__);
             HdfSbufRecycle(msg);
             (void)OsalMutexUnlock(&priv->mutex);
             return HDF_FAILURE;
         }
     
         if (!HdfSbufWriteBuffer(msg, effect, sizeof(*effect))) {
             HDF_LOGE("%{public}s: Light write enable failed", __func__);
             HdfSbufRecycle(msg);
             (void)OsalMutexUnlock(&priv->mutex);
             return HDF_FAILURE;
         }
     
         ret = SendLightMsg(LIGHT_IO_CMD_OPS, msg, NULL);
         if (ret != HDF_SUCCESS) {
             HDF_LOGE("%{public}s: Light enable failed, ret[%{public}d]", __func__, ret);
         }
         HdfSbufRecycle(msg);
         (void)OsalMutexUnlock(&priv->mutex);
     
         if (memcpy_s(&g_lightEffect, sizeof(g_lightEffect), effect, sizeof(*effect)) != EOK) {
             HDF_LOGE("%{public}s: Light effect cpy faild", __func__);
             return HDF_FAILURE;
         }
     
         g_lightState[lightId] = LIGHT_ON;
     
         return ret;
     }
     ```

   - The **OffLight** interface is implemented as follows:

     ```c
     static int32_t OffLight(uint32_t lightId)
     {
         if (lightId >= LIGHT_ID_BUTT) {
             HDF_LOGE("%{public}s: id not supported", __func__);
             return HDF_FAILURE;
         }
     
         struct LightDevice *priv = GetLightDevicePriv();
         (void)OsalMutexLock(&priv->mutex);
     
         struct HdfSBuf *msg = HdfSbufObtainDefaultSize();
         if (msg == NULL) {
             HDF_LOGE("%{public}s: Failed to obtain sBuf", __func__);
             (void)OsalMutexUnlock(&priv->mutex);
             return HDF_FAILURE;
         }
     
         if (!HdfSbufWriteInt32(msg, lightId)) {
             HDF_LOGE("%{public}s: Light write id failed", __func__);
             HdfSbufRecycle(msg);
             (void)OsalMutexUnlock(&priv->mutex);
             return HDF_FAILURE;
         }
     
         if (!HdfSbufWriteInt32(msg, LIGHT_OPS_IO_CMD_DISABLE)) {
             HDF_LOGE("%{public}s: Light write disable failed", __func__);
             HdfSbufRecycle(msg);
             (void)OsalMutexUnlock(&priv->mutex);
             return HDF_FAILURE;
         }
     
         int32_t ret = SendLightMsg(LIGHT_IO_CMD_OPS, msg, NULL);
         if (ret != HDF_SUCCESS) {
             HDF_LOGE("%{public}s: Light disable failed, ret[%{public}d]", __func__, ret);
         }
         HdfSbufRecycle(msg);
         (void)OsalMutexUnlock(&priv->mutex);
     
         g_lightState[lightId] = LIGHT_OFF;
     
         return ret;
     }
     ```

   - The **OnMultiLights** interface is implemented as follows:

     ```c
     static int32_t OnMultiLights(uint32_t lightId, const struct LightColor *colors, const uint32_t count)
     {
         int32_t ret;
         struct HdfSBuf *sbuf = NULL;
     
         ret = OnMultiLightsValidityJudgment(lightId, colors, count);
         if (ret != HDF_SUCCESS) {
             return ret;
         }
     
         struct LightDevice *priv = GetLightDevicePriv();
         (void)OsalMutexLock(&priv->mutex);
         sbuf = HdfSbufObtain(sizeof(struct LightColor) * count);
         if (sbuf == NULL) {
             return HDF_DEV_ERR_NO_MEMORY;
         }
     
         if (!HdfSbufWriteInt32(sbuf, lightId)) {
             ret = HDF_FAILURE;
             goto EXIT;
         }
     
         if (!HdfSbufWriteInt32(sbuf, LIGHT_OPS_IO_CMD_ENABLE_MULTI_LIGHTS)) {
             ret = HDF_FAILURE;
             goto EXIT;
         }
     
         if (!HdfSbufWriteBuffer(sbuf, colors, sizeof(*colors))) {
             ret = HDF_FAILURE;
             goto EXIT;
         }
     
         if (!HdfSbufWriteInt32(sbuf, count)) {
             ret = HDF_FAILURE;
             goto EXIT;
         }
     
         ret = SendLightMsg(LIGHT_IO_CMD_OPS, sbuf, NULL);
         if (ret != HDF_SUCCESS) {
         }
     	return ret;
     
     EXIT:
         HdfSbufRecycle(sbuf);
         (void)OsalMutexUnlock(&priv->mutex);
     }
     ```

### Verification

After the driver is developed, develop auto-test cases in the light unit test to verify the basic functionalities of the driver. Use the developer self-test platform as the test environment.

- The reference test code is as follows:

  ```c
  #include <cmath>
  #include <cstdio>
  #include <gtest/gtest.h>
  #include <securec.h>
  #include "hdf_base.h"
  #include "osal_time.h"
  #include "osal_mem.h"
  #include "light_if.h"
  #include "light_type.h"
  
  using namespace testing::ext;
  const struct LightInterface *g_lightDev = nullptr;
  static struct LightInfo *g_lightInfo = nullptr;
  static uint32_t g_count = 0;
  /* Initialize the LightInterfaceInstance before executing the test case. */
  class HdfLightTest : public testing::Test {
  public:
      static void SetUpTestCase();
      static void TearDownTestCase();
      void SetUp();
      void TearDown();
  };
  
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
  
  /* After the test case is executed, release the resources used by the test case. */
  void HdfLightTest::TearDownTestCase()
  {
      if(g_lightDev != nullptr){
          FreeLightInterfaceInstance();
          g_lightDev = nullptr;
      }
  }
  
  void HdfLightTest::SetUp()
  {
  }
  
  void HdfLightTest::TearDown()
  {
  }
  
  /* Obtain the test light type. */
  HWTEST_F(HdfLightTest, GetLightList001, TestSize.Level1)
  {
      struct LightInfo *info = nullptr;
  
      if (g_lightInfo == nullptr) {
          EXPECT_NE(nullptr, g_lightInfo);
          return;
      }
  
      printf("get light list num[%u]\n\r", g_count);
      info = g_lightInfo;
  
      for (uint32_t i = 0; i < g_count; ++i) {
          printf("get lightId[%u]\n\r", info->lightId);
          EXPECT_GE(info->lightId, 0);
          EXPECT_LE(info->lightId, 4);
          info++;
      }
  }
  
  /* Verify the steady on state of the light. */
  HWTEST_F(HdfLightTest, EnableLight001, TestSize.Level1)
  {
      uint32_t i;
      struct LightEffect effect;
      effect.flashEffect.flashMode = 0;
      effect.flashEffect.onTime = 0;
      effect.flashEffect.offTime = 0;
  
      for (i = 0; i < g_count; ++i) {
          effect.lightColor.colorValue.rgbColor.r = 255;
          effect.lightColor.colorValue.rgbColor.g = 0;
          effect.lightColor.colorValue.rgbColor.b = 0;
          int32_t ret = g_lightDev->TurnOnLight(g_lightInfo[i].lightId, &effect);
          EXPECT_EQ(0, ret);
  
     OsalSleep(2);
  
     ret = g_lightDev->TurnOffLight(g_lightInfo[i].lightId);
          EXPECT_EQ(0, ret);
  
          effect.lightColor.colorValue.rgbColor.r = 0;
          effect.lightColor.colorValue.rgbColor.g = 255;
          effect.lightColor.colorValue.rgbColor.b = 0;
          ret = g_lightDev->TurnOnLight(g_lightInfo[i].lightId, &effect);
          EXPECT_EQ(0, ret);
  
          OsalSleep(2);
  
          ret = g_lightDev->TurnOffLight(g_lightInfo[i].lightId);
          EXPECT_EQ(0, ret);
      }
  }
  ```

- The reference code of the **BUILD.gn** file is as follows:

  ```c
  import("//build/test.gni")
  import("//drivers/hdf_core/adapter/uhdf2/uhdf.gni")
  
  module_output_path = "drivers_peripheral_light/light"
  ohos_unittest("light_test") {
    module_out_path = module_output_path
    sources = [ "light_test.cpp" ]
    include_dirs = [
      "//drivers/peripheral/light/interfaces/include",
    ]
    deps = [ "//drivers/peripheral/light/hal:hdi_light" ]
  
    external_deps = [
      "c_utils:utils",
      "hdf_core:libhdf_utils",
   	"hiviewdfx_hilog_native:libhilog",
    ]
  
    cflags = [
      "-Wall",
      "-Wextra",
      "-Werror",
      "-Wno-format",
      "-Wno-format-extra-args",
    ]
  
    install_enable = true
    install_images = [ "vendor" ]
    module_install_dir = "bin"
    part_name = "unionman_products"
  }
  ```
