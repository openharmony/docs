# Vibrator

## Overview

### Introduction

Developed on the Hardware Driver Foundation (HDF), the vibrator driver model makes vibrator driver development easier. This model masks the interaction between the device driver and system, provides unified and stable driver interfaces for the hardware service layer, and offers open interfaces and interface parsing capabilities for driver developers. This document provides guidance for developing vibrator drivers and deploying vibrators in different OSs. The figure below shows the vibrator driver model.

**Figure 1** Vibrator driver model

![Vibrator driver model](figures/vibrator_driver_model.png)

### Basic Concepts

The system controls device vibration by invoking the vibrator. There are two vibration modes:

- One-shot vibration

  The vibrator vibrates for a specified duration.

- Periodic vibration

  The vibrator vibrates with a preset effect. For example, if the preset effect is "haptic.clock.timer" = [600, 600, 200, 600], the vibrator waits for 600 ms, vibrates for 600 ms, waits for 200 ms, and vibrates for 600 ms.

### Working Principles

Based on the loading and running process (shown below) of the vibrator driver model, the relationships between key modules in the model and associated modules are clearly defined.

**Figure 2** How vibrator driver works

![How vibrator driver works](figures/vibrator_working.png)

The following uses the vibrator driver on the Hi3516D V300 development board of the standard system as an example to describe the driver loading and running process.

1. The vibrator host reads the vibrator management configuration from the Vibrator Host node of the device_info HCS (vibrator device information HCS).
2. The vibrator host parses the vibrator management configuration and associates it with the corresponding vibrator abstract driver.
3. The vibrator host reads the vibrator data configuration from the linear_vibrator_config HCS (vibrator private configuration HCS).
4. The vibrator host parses the vibrator data configuration and associates it with the corresponding vibrator haptic driver.
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

The vibrator driver model supports static HDF Configuration Source (HCS) configurations and dynamic parameter configurations. The vibrator hardware service calls the **StartOnce** interface to trigger continuous vibration and calls the **Start** interface to trigger vibration with a specified effect. The table below lists the APIs provided by the vibrator driver model for the hardware service layer.

**Table 1** External APIs of the vibrator driver model

| API                                | Description                                                |
| -------------------------------------- | -------------------------------------------------------- |
| int32_t  StartOnce(uint32_t duration)  | Triggers vibration with a given **duration**.  |
| int32_t  Start(const char *effectType) | Triggers vibration with a given effect, which is specified by **effectType**.|
| int32_t  Stop(enum VibratorMode mode)  | Stops vibration.                        |

### How to Develop

The vibrator driver model provides stable interfaces for the upper-layer hardware service to trigger a one-shot vibration with a given duration, trigger vibration with a given effect, and stop vibration. The model implements functionalities such as cross-OS migration and differentiated configurations. To develop a vibrator, perform the following steps:

1. Develop the vibrator abstract driver based on the driver entry. Specifically, implement the **Bind**, **Init**, **Release**, and **Dispatch** functions, configure resources, and parse HCS configurations.

   - Call **HDF_INIT** to register the driver entry with the HDF. During driver loading, the HDF calls the **Bind** function and then the **Init** function to load the driver. If the **Init** function fails to be called, the HDF calls **Release** to release the driver resources and exit the vibrator driver model. The vibrator driver model uses the HCS as the configuration source code. For details about HCS fields, see [Driver Configuration Management](https://gitee.com/openharmony/docs/blob/master/en/device-dev/driver/driver-hdf-manage.md). The driver entry function is defined as follows:

     ```c
     /* Register the entry structure object of the vibrator abstract driver. */
     struct HdfDriverEntry g_vibratorDriverEntry = {
         .moduleVersion = 1, // Version of the vibrator module.
         .moduleName = "HDF_VIBRATOR", // Vibrator module name. The value must be the same as the value of moduleName in the device_info.hcs file.
         .Bind = BindVibratorDriver, // Function for binding a vibrator.
         .Init = InitVibratorDriver, // Function for initializing a vibrator.
        .Release = ReleaseVibratorDriver, // Function for releasing vibrator resources.
     };
     
     HDF_INIT(g_vibratorDriverEntry);
     ```

   - Develop the vibrator abstract driver. Specifically, implement the **Bind**, **Init**, **Release**, and **Dispatch** functions.

     ```c
     /* External service published by the vibrator driver. */
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
             HDF_LOGE("%s: init workQueue fail!", __func__);
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
                         preload = 0; // Field for specifying whether to load the driver. The value 0 means to load the driver, and 2 means the opposite.
                         permission = 0664; // Permission for the driver to create a device node.
                         moduleName = "HDF_VIBRATOR"; // Driver name. The value must be the same as that of moduleName in the driver entry structure.
                         serviceName = "hdf_misc_vibrator"; // Name of the service provided by the driver. The name must be unique.
                         deviceMatchAttr = "hdf_vibrator_driver"; // Keyword matching the private data of the driver. The value must be the same as that of match_attr in the private data configuration table of the driver.
                     }
                 }
     ```

2. Create a vibrator haptic model and parse the haptic HCS configuration.

   - Create a vibrator haptic model.

     ```hcs
     /* Create a vibrator haptic model, allocate resources, and parse the haptic HCS configuration. */
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
     
         /* Parse the haptic HCS configuration. */
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

   - The vibrator effect model uses the HCS. For details about HCS fields, see [Driver Configuration Management](https://gitee.com/openharmony/docs/blob/master/en/device-dev/driver/driver-hdf-manage.md).

     ```
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
           HDF_LOGE("%s: start haptic fail!", __func__);
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
           HDF_LOGE("%s: start haptic fail!", __func__);
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
           HDF_LOGE("%s: stop haptic fail!", __func__);
           return ret;
       }
   
       (void)OsalMutexLock(&drvData->mutex);
       drvData->mode = VIBRATOR_MODE_BUTT;
       (void)OsalMutexUnlock(&drvData->mutex);
   
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
         (void)OsalMutexUnlock(&drvData->mutex);
     
         return HDF_SUCCESS;
     }
     ```

   - The vibrator driver model provides vibrator chipset driver interfaces. Implement these interfaces as follows:

     ```c
     /* Start a linear vibrator to vibrate with a given duration. */
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
     
     /* Start a linear vibration to vibrate with a given effect. */
     static int32_t StartEffectLinearVibrator(uint32_t effectType)
     {
         (void)effectType;
          HDF_LOGE("%s: vibrator set build-in effect no support!", __func__);
         return HDF_SUCCESS;
     }
     
     /* Stop a linear vibration based on the specified vibration mode. */
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
