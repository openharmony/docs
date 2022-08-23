# Vibrator

## Overview

### Introduction

Developed on the Hardware Driver Foundation (HDF), the vibrator driver model makes vibrator driver development easier. The motor driver model shields the interaction between the device driver and the system and provides unified and stable driver interface capabilities for the hardware service layer. It also provides open interfaces and interface parsing capabilities for developers to develop vibrator drivers and deploy vibrators in different OSs.<br> The figure below shows the vibrator driver model.

**Figure 1** Vibrator driver model

![Vibrator driver model](figures/vibrator_driver_model.png)

### Basic Concepts

The system controls device vibration by invoking the vibrator. There are two vibration modes:

- One-shot vibration

  The vibrator vibrates for a specified duration.

- Periodic vibration

  The vibrator vibrates with a preset effect. For example, if **haptic.clock.timer** is set to **[600, 600, 200, 600]**, the vibrator waits for 600 ms, vibrates for 600 ms, waits for 200 ms, and vibrates for 600 ms.

### Working Principles

The figure below shows how a vibrator driver is loaded.

**Figure 2** How a vibrator driver works

![How vibrator driver works](figures/vibrator_working.png)

The following uses the vibrator driver on the Hi3516D V300 development board of the standard system as an example to describe the driver loading and running process.

1. The vibrator driver reads the vibrator management configuration information from **Vibrator Host** in the **device_info.hcs** file.
2. The HCS parser parses the vibrator management configuration and associates it with the vibrator abstract driver.
3. The vibrator chipset driver reads the vibrator data configuration from the **linear_vibrator_config.hcs** file.
4. The HCS parser parses the vibrator data configuration and associates it with the vibrator haptic driver.
5. The vibrator proxy delivers an instruction to the vibrator stub.
6. The vibrator stub calls the vibrator controller.
7. The vibrator host initializes the vibrator abstract driver interfaces.
8. The vibrator haptic driver starts a thread to parse the vibrator haptic module.
9. The vibrator haptic driver calls the **Start** interface in the vibrator abstract driver.
10. The vibrator abstract driver calls the **Start** interface in the vibrator chipset driver.

## Development Guidelines

### When to Use

You can set different vibration effects as needed, for example, customizing vibration effects with different intensities and durations for buttons on the device, and customizing one-shot or periodic vibration effects with different intensities and durations for alarm clocks and incoming calls.

### Available APIs

The vibrator driver model supports static HDF Configuration Source (HCS) configuration and dynamic parameter configuration. The vibrator hardware service calls **StartOnce()** to trigger continuous vibration and calls **Start()** to trigger vibration with a specified effect. The table below lists the APIs provided by the vibrator driver model for the hardware service layer.

**Table 1** APIs of the vibrator driver model

| API                                 | Description                                          |
| -------------------------------------- | ------------------------------------------------ |
| int32_t  StartOnce(uint32_t duration)                        | Triggers vibration with a given **duration**.      |
| int32_t  Start(const char *effectType)                       | Triggers vibration with a given effect, which is specified by **effectType**.    |
| int32_t  Stop(enum VibratorMode mode)                        | Stops vibration.                            |
| int32_t EnableVibratorModulation(uint32_t duration, int32_t intensity, int32_t frequency) | Triggers vibration with the given **duration**, **frequency**, and **intensity**.|
| int32_t GetVibratorInfo(struct VibratorInfo **vibratorInfo); | Obtains vibrator information, including whether the intensity and frequency can be set and the intensity and frequency range.|

### How to Develop

The vibrator driver model provides APIs for the upper-layer hardware service to trigger a one-shot vibration with a given duration, trigger vibration with a given effect, and stop vibration. This model implements functionalities such as cross-OS porting and device-specific configurations. The development procedure is as follows:

1. Develop the vibrator abstract driver based on the driver entry. Specifically, implement the **Bind**, **Init**, **Release**, and **Dispatch** functions, configure resources, and parse the HCS.

   - Call **HDF_INIT** to register the driver entry with the HDF. During driver loading, the HDF calls the **Bind** function and then the **Init** function to load the driver. If the **Init** function fails to be called, the HDF calls **Release** to release the driver resources and exit the vibrator driver model. The vibrator driver model uses the HCS as the configuration source code. For details about HCS configuration fields, see [Configuration Management](driver-hdf-manage.md). The driver entry function is defined as follows:

     ```c
     /* Register the entry structure object of the vibrator abstract driver. */
     struct HdfDriverEntry g_vibratorDriverEntry = {
         .moduleVersion = 1, // Version of the vibrator module.
         .moduleName = "HDF_VIBRATOR", // Vibrator module name, which must be the same as moduleName in the device_info.hcs file.
         .Bind = BindVibratorDriver, // Function for binding a vibrator.
         .Init = InitVibratorDriver, // Function for initializing a vibrator.
         .Release = ReleaseVibratorDriver, // Function for releasing vibrator resources.
     };
     
     HDF_INIT(g_vibratorDriverEntry);
     ```

   - Develop the vibrator abstract driver. Specifically, implement the **Bind**, **Init**, **Release**, and **Dispatch** functions.

     ```c
     /* Message exchange capability of the vibrator driver. */
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
     
     /* Bind the external service provided by the vibrator driver to the HDF. */
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

     /* Entry function for vibrator driver initialization. */
     int32_t InitVibratorDriver(struct HdfDeviceObject *device)
     {
         struct VibratorDriverData *drvData = NULL;

         drvData->mode = VIBRATOR_MODE_BUTT;
         drvData->state = VIBRATOR_STATE_IDLE;
         ......
         if (CreateVibratorHaptic(device) != HDF_SUCCESS) {
             HDF_LOGE("%s: init workQueue failed!", __func__);
             return HDF_FAILURE;
         }

         return HDF_SUCCESS;
     }

     /* Release the resources allocated during vibrator driver initialization. */
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

   - During system startup, the HDF configuration management loads the vibrator abstract driver based on the device information HCS and publishes the vibrator driver interfaces.

     ```c
     /* Device information HCS. */
     vibrator :: host {
                 hostName = "vibrator_host";
                 device_vibrator :: device {
                     device0 :: deviceNode {
                         policy = 2; // Policy for publishing the driver service.
                         priority = 100; // Driver startup priority (0–200). A larger value indicates a lower priority. The default value 100 is recommended. The sequence for loading devices with the same priority is random.
                         preload = 0; // Whether to load the driver on demand. The value 0 means to load the driver on demand, and 2 means the opposite.
                         permission = 0664; // Permission for the driver to create a device node.
                         moduleName = "HDF_VIBRATOR"; // Driver name, which must be the same as moduleName in the driver entry structure.
                         serviceName = "hdf_misc_vibrator"; // Name of the service provided by the driver. The name must be unique.
                         deviceMatchAttr = "hdf_vibrator_driver"; // Keyword matching the private data of the driver. The value must be the same as that of match_attr in the private data configuration table of the driver.
                     }
                 }
     ```

2. Create a vibrator haptic model and parse the haptic HCS.

   - Create a vibrator haptic model.

     ```c
     /* Create a vibrator haptic model, allocate resources, and parse the haptic HCS. */
     int32_t CreateVibratorHaptic(struct HdfDeviceObject *device)
     {
         struct VibratorHapticData *hapticData = NULL;
         CHECK_VIBRATOR_NULL_PTR_RETURN_VALUE(device, HDF_FAILURE);
     
         hapticData = (struct VibratorHapticData *)OsalMemCalloc(sizeof(*hapticData));
         CHECK_VIBRATOR_NULL_PTR_RETURN_VALUE(hapticData, HDF_ERR_MALLOC_FAIL);
         g_vibratorHapticData = hapticData;
         hapticData->supportHaptic = false;
     
         if (OsalMutexInit(&hapticData->mutex) != HDF_SUCCESS) {
             HDF_LOGE("%s: failed to init mutex", __func__);
             goto EXIT;
         }
     
         DListHeadInit(&hapticData->effectSeqHead);
     
         /* Parse the haptic HCS. */
         if (ParserVibratorHapticConfig(device->property) != HDF_SUCCESS) {
             HDF_LOGE("%s: parser haptic config failed!", __func__);
             goto EXIT;
         }
     
         return HDF_SUCCESS;
     EXIT:
         OsalMemFree(hapticData);
         return HDF_FAILURE;
     }
     ```

   - The vibrator haptic model uses the HCS. For details about the HCS fields, see [Configuration Management](driver-hdf-manage.md).

     ```hcs
     /* Vibrator data configuration template (vibrator_config.hcs). */
     root {
         vibratorConfig {
             boardConfig {
                 match_attr = "hdf_vibrator_driver"; // The value must be the same as that of the match_attr field configured for the vibrator.
                 vibratorAttr {
                     /* The value 0 means a rotor vibrator, and 1 means a linear vibrator. */
                     deviceType = 1; // Device type.
                     supportPreset = 1; // Supported preset type.
                 }
                 vibratorHapticConfig {
                     haptic_clock_timer {
                         effectName = "haptic.clock.timer";
                         type = 1; // The value 0 means the built-in mode, and 1 means the time sequence.
                         seq = [600, 600, 200, 600]; // Time sequence.
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

3. Develop the interfaces for starting and stopping vibration. A timer will be created and destroyed based on the vibration effect.

   The vibrator hardware service calls **StartOnce** to start one-shot vibration with a given duration and calls **StartEffect** to start vibration with a specified effect.

   ```c
   /* Trigger vibration with a given duration. */
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
       /* Create a timer based on the vibration effect. */
       ret = StartHaptic(&config);
       if (ret != HDF_SUCCESS) {
           HDF_LOGE("%s: start haptic failed!", __func__);
           return ret;
       }
   
       return HDF_SUCCESS;
   }
   
   /* Trigger vibration with a given effect. */
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
           HDF_LOGE("%s: start haptic failed!", __func__);
           return ret;
       }
   
       return HDF_SUCCESS;
   }
   
   /* Stop vibration based on the specified vibration mode. */
   static int32_t Stop(struct HdfSBuf *data, struct HdfSBuf *reply)
   {
       int32_t ret;
       int32_t mode;
       struct VibratorDriverData *drvData = GetVibratorDrvData();
       (void)reply;
       ......
       /* Stop vibration and destroy the timer. */
       ret = StopHaptic();
       if (ret != HDF_SUCCESS) {
           HDF_LOGE("%s: stop haptic failed!", __func__);
           return ret;
       }
   
       (void)OsalMutexLock(&drvData->mutex);
       drvData->mode = VIBRATOR_MODE_BUTT;
       (void)OsalMutexUnlock(&drvData->mutex);
   
       return HDF_SUCCESS;
   }
   
   /* Trigger vibration with the given duration, frequency, and intensity. */
   static int32_t EnableModulationParameter(struct HdfSBuf *data, struct HdfSBuf *reply)
   {
       (void)reply;
       struct VibratorEffectCfg config;
       struct VibratorDriverData *drvData;
       uint32_t duration;
       int32_t intensity;
       int32_t frequency;
       int32_t ret;
    .....
       (void)OsalMutexLock(&drvData->mutex);
       drvData->mode = VIBRATOR_MODE_ONCE;
       (void)OsalMutexUnlock(&drvData->mutex);
    /* Set the vibration intensity and frequency. */
       ret = drvData->ops.SetParameter(intensity, frequency);
       if (ret != HDF_SUCCESS) {
           HDF_LOGE("%s: set parameter failed", __func__);
           return HDF_FAILURE;
       }
   
       config.cfgMode = VIBRATOR_MODE_ONCE;
       config.duration = duration;
       config.effect = NULL;
   
       ret = StartHaptic(&config);
       if (ret != HDF_SUCCESS) {
           HDF_LOGE("%s: start haptic failed", __func__);
           return HDF_FAILURE;
       }
   
       return HDF_SUCCESS;
   }
   
   /* Obtain vibrator information, including whether the intensity and frequency can be set and the intensity and frequency range. */
   static int32_t GetVibratorInfo(struct HdfSBuf *data, struct HdfSBuf *reply)
   {
       (void)data;
       struct VibratorDriverData *drvData;
   
       drvData = GetVibratorDrvData();
       CHECK_VIBRATOR_NULL_PTR_RETURN_VALUE(drvData, HDF_ERR_INVALID_PARAM);
       CHECK_VIBRATOR_NULL_PTR_RETURN_VALUE(reply, HDF_ERR_INVALID_PARAM);
   
       if (!HdfSbufWriteBuffer(reply, &drvData->vibratorInfo, sizeof(drvData->vibratorInfo))) {
           HDF_LOGE("%s: write sbuf failed", __func__);
           return HDF_FAILURE;
       }
   
       return HDF_SUCCESS;
   }
   ```

4. Implement the interfaces for the vibrator chipset driver.

   - Register the vibrator chipset driver interfaces when the vibrator chipset driver is initialized successfully.

     ```c
     /* Register the vibrator chipset driver interfaces. */
     int32_t RegisterVibrator(struct VibratorOps *ops)
     {
         struct VibratorDriverData *drvData = GetVibratorDrvData();
     
         CHECK_VIBRATOR_NULL_PTR_RETURN_VALUE(ops, HDF_FAILURE);
         CHECK_VIBRATOR_NULL_PTR_RETURN_VALUE(drvData, HDF_FAILURE);
     
         (void)OsalMutexLock(&drvData->mutex);
         drvData->ops.Start = ops->Start;
         drvData->ops.StartEffect = ops->StartEffect;
         drvData->ops.Stop = ops->Stop;
         drvData->ops.SetParameter = ops->SetParameter;
         (void)OsalMutexUnlock(&drvData->mutex);
     
         return HDF_SUCCESS;
     }
     
     /* Register vibrator information. */
      int32_t RegisterVibratorInfo(struct VibratorInfo *vibratorInfo)
     {
         struct VibratorDriverData *drvData = GetVibratorDrvData();
     
         CHECK_VIBRATOR_NULL_PTR_RETURN_VALUE(vibratorInfo, HDF_FAILURE);
         CHECK_VIBRATOR_NULL_PTR_RETURN_VALUE(drvData, HDF_FAILURE);
     
         (void)OsalMutexLock(&drvData->mutex);
         if (memcpy_s(&drvData->vibratorInfo, sizeof(drvData->vibratorInfo), vibratorInfo, sizeof(*vibratorInfo)) != EOK) {
             HDF_LOGE("%s: Memcpy vibrator config failed", __func__);
             return HDF_FAILURE;
         }
         (void)OsalMutexUnlock(&drvData->mutex);
     
         return HDF_SUCCESS;
     }
     ```

     

   - The vibrator driver model provides vibrator chipset driver interfaces. Implement these interfaces as follows:

     ```c
     /* Stop vibration based on the specified vibration mode. */
     static int32_t StopModulationParameter()
     {
         uint8_t value[DRV2605L_VALUE_BUTT];
      struct Drv2605lDriverData *drvData = NULL;
         drvData = GetDrv2605lDrvData();
     
      CHECK_VIBRATOR_NULL_PTR_RETURN_VALUE(drvData, HDF_FAILURE);
         CHECK_VIBRATOR_NULL_PTR_RETURN_VALUE(drvData->drv2605lCfgData, HDF_FAILURE);
     
         value[DRV2605L_ADDR_INDEX] = (uint8_t)DRV2605_REG_MODE;
         value[DRV2605L_VALUE_INDEX] = (uint8_t)DRV2605_MODE_STANDBY;
         if (WriteDrv2605l(&drvData->drv2605lCfgData->vibratorBus.i2cCfg, value, sizeof(value)) != HDF_SUCCESS) {
             HDF_LOGE("%s: i2c addr [%0X] write failed", __func__, value[DRV2605L_ADDR_INDEX]);
          return HDF_FAILURE;
         }
     
         value[DRV2605L_ADDR_INDEX] = (uint8_t)DRV2605_REG_RTPIN;
         value[DRV2605L_VALUE_INDEX] = (uint8_t)&drvData->drv2605lCfgData->vibratorAttr.defaultIntensity;
         if (WriteDrv2605l(&drvData->drv2605lCfgData->vibratorBus.i2cCfg, value, sizeof(value)) != HDF_SUCCESS) {
          HDF_LOGE("%s: i2c addr [%0X] write failed", __func__, value[DRV2605L_ADDR_INDEX]);
         }
     
         value[DRV2605L_ADDR_INDEX] = (uint8_t)DRV2605_REG_LRARESON;
         value[DRV2605L_VALUE_INDEX] = (uint8_t)&drvData->drv2605lCfgData->vibratorAttr.defaultFrequency;
         if (WriteDrv2605l(&drvData->drv2605lCfgData->vibratorBus.i2cCfg, value, sizeof(value)) != HDF_SUCCESS) {
          HDF_LOGE("%s: i2c addr [%0X] write failed", __func__, value[DRV2605L_ADDR_INDEX]);
         }
     
         return HDF_SUCCESS;
     }
     
     /* Set the vibration intensity and frequency. */
     static void SetModulationParameter(int32_t intensity, int32_t frequency)
     {
         uint8_t value[DRV2605L_VALUE_BUTT];
      struct Drv2605lDriverData *drvData = NULL;
         drvData = GetDrv2605lDrvData();
     
         CHECK_VIBRATOR_NULL_PTR_RETURN_VALUE(drvData, HDF_FAILURE);
     
         if (intensity != 0) {
             value[DRV2605L_ADDR_INDEX] = (uint8_t)DRV2605_REG_RTPIN;
             value[DRV2605L_VALUE_INDEX] = (uint8_t)INTENSITY_MAPPING_VALUE(intensity);
             if (WriteDrv2605l(&drvData->drv2605lCfgData->vibratorBus.i2cCfg, value, sizeof(value)) != HDF_SUCCESS) {
                 HDF_LOGE("%s: i2c addr [%0X] write failed", __func__, value[DRV2605L_ADDR_INDEX]);
                 return;
             }
         } else {
             HDF_LOGD("%s: the setting of intensity 0 is not supported and \
              will be set as the system default intensity", __func__);
         }
     
         if (frequency != 0) {
             value[DRV2605L_ADDR_INDEX] = (uint8_t)DRV2605_REG_LRARESON;
             value[DRV2605L_VALUE_INDEX] = (uint8_t)FREQUENCY_MAPPING_VALUE(frequency);
             if (WriteDrv2605l(&drvData->drv2605lCfgData->vibratorBus.i2cCfg, value, sizeof(value)) != HDF_SUCCESS) {
                 HDF_LOGE("%s: i2c addr [%0X] write failed", __func__, value[DRV2605L_ADDR_INDEX]);
                 return;
             }
         } else {
             HDF_LOGD("%s: the setting of frequency 0 is not supported and \
                 will be set as the system default frequency", __func__);
         }
     }
     ```

### Verification

After the driver is developed, develop test cases in the sensor unit test to verify the basic functions of the driver. Use the developer self-test platform as the test environment.

```
/* Initialize the vibrator interface instance before executing test cases. */
void HdfVibratorTest::SetUpTestCase()
{
    g_vibratorDev = NewVibratorInterfaceInstance();
}
/* Release test case resources. */
void HdfVibratorTest::TearDownTestCase()
{
    if(g_vibratorDev != nullptr){
        FreeVibratorInterfaceInstance();
        g_vibratorDev = nullptr;
    }
}

/* Verify one-short vibration. */
HWTEST_F(HdfVibratorTest, PerformOneShotVibratorDuration_001, TestSize.Level1)
{
    ASSERT_NE(nullptr, g_vibratorDev);

    int32_t startRet = g_vibratorDev->StartOnce(g_duration);
    EXPECT_EQ(startRet, HDF_SUCCESS);

    OsalMSleep(g_sleepTime1);

    int32_t endRet = g_vibratorDev->Stop(VIBRATOR_MODE_ONCE);
    EXPECT_EQ(endRet, HDF_SUCCESS);
}
/* Verify vibration with the preset effect. */
HWTEST_F(HdfVibratorTest, ExecuteVibratorEffect_002, TestSize.Level1)
{
    ASSERT_NE(nullptr, g_vibratorDev);

    int32_t startRet = g_vibratorDev->Start(g_builtIn);
    EXPECT_EQ(startRet, HDF_SUCCESS);

    OsalMSleep(g_sleepTime1);

    int32_t endRet = g_vibratorDev->Stop(VIBRATOR_MODE_PRESET);
    EXPECT_EQ(endRet, HDF_SUCCESS);
}
/* Obtain vibrator information, including whether the intensity and frequency can be set and the intensity and frequency range. */
HWTEST_F(HdfVibratorTest, GetVibratorInfo_001, TestSize.Level1)
{
    ASSERT_NE(nullptr, g_vibratorDev);

    int32_t startRet = g_vibratorDev->GetVibratorInfo(&g_vibratorInfo);
    EXPECT_EQ(startRet, HDF_SUCCESS);
    EXPECT_NE(g_vibratorInfo, nullptr);

    printf("intensity = %d, intensityMaxValue = %d, intensityMinValue = %d\n\t",
    g_vibratorInfo->isSupportIntensity, g_vibratorInfo->intensityMaxValue, g_vibratorInfo->intensityMinValue);
    printf("frequency = %d, frequencyMaxValue = %d, frequencyMinValue = %d\n\t",
    g_vibratorInfo->isSupportFrequency, g_vibratorInfo->frequencyMaxValue, g_vibratorInfo->frequencyMinValue);
}
/* Trigger vibration with the given duration, frequency, and intensity. */
HWTEST_F(HdfVibratorTest, EnableVibratorModulation_001, TestSize.Level1)
{
    int32_t startRet;
    ASSERT_NE(nullptr, g_vibratorDev);
    EXPECT_GT(g_duration, 0);

    if ((g_vibratorInfo->isSupportIntensity == 1) || (g_vibratorInfo->isSupportFrequency == 1)) {
        EXPECT_GE(g_intensity1, g_vibratorInfo->intensityMinValue);
        EXPECT_LE(g_intensity1, g_vibratorInfo->intensityMaxValue);
        EXPECT_GE(g_frequency1, g_vibratorInfo->frequencyMinValue);
        EXPECT_LE(g_frequency1, g_vibratorInfo->frequencyMaxValue);

        startRet = g_vibratorDev->EnableVibratorModulation(g_duration, g_intensity1, g_frequency1);
        EXPECT_EQ(startRet, HDF_SUCCESS);
        OsalMSleep(g_sleepTime1);
        startRet = g_vibratorDev->Stop(VIBRATOR_MODE_ONCE);
        EXPECT_EQ(startRet, HDF_SUCCESS);
    }
}
```
