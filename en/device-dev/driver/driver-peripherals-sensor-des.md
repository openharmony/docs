# Sensor


## Overview

### Function

The sensor driver model shields the hardware difference and provides interfaces for the upper-layer sensor service to implement basic sensor capabilities, including querying the sensor list, enabling or disabling a sensor, subscribing to or unsubscribing from sensor data changes, and setting sensor attributes. Developed based on the Hardware Driver Foundation (HDF), the sensor driver model leverages the capabilities of the OS adaptation layer (OSAL) and platform driver interfaces (such as I2C, SPI, and UART buses) to shield the difference between OSs and platform bus resources, achieving "one-time development and multi-system deployment" of the sensor driver. The figure below shows the architecture of the sensor driver model.

**Figure 1** Sensor driver model

![Sensor driver model](figures/sensor_driver_model.png)

### Basic Concepts

Sensors are classified into the following types by sensor ID:

- Medical sensors: The sensor IDs range from 128 to 160.

- Traditional sensors: The sensor IDs are out of the range of 128 to 160.

### Working Principles

The following figure shows how a sensor driver works.

**Figure 2** How a sensor driver works

![How sensor driver works](figures/sensor_working.png)

The following uses the acceleration sensor driver on the Hi3516D V300 development board of the standard system as an example to describe the driver loading and running process.

1. The sensor host reads the sensor device management configuration from **Sensor Host** in the **device_info.hcs** file.
2. The sensor host parses the sensor management configuration from the HCB database and associates the configuration with the sensor driver.
3. The sensor host loads and initializes the sensor manager driver.
4. The sensor manager driver publishes the sensor APIs for the hardware driver interface (HDI).
5. The sensor host reads the acceleration sensor driver configuration information from **Sensor Host** in the **device_info.hcs** configuration file.
6. The sensor host loads the acceleration sensor abstract driver and calls the initialization interface to allocate the sensor driver resources and create the data processing queue.
7. The sensor host reads the chipset driver configuration and private configuration of the acceleration sensor from the **accel_xxx_config.hcs** file.
8. The acceleration sensor chipset driver calls the common configuration parsing interface to parse the sensor attributes and registers.
9. The chipset driver detects sensors, allocates configuration resources to the acceleration sensor, and registers the acceleration sensor chipset interfaces.
10. Upon successful sensor detection, the chipset driver instructs the abstract driver to register the acceleration sensor to the sensor manager driver.

## Development Guidelines

### When to Use

- Data provided by the gravity and gyroscope sensors denotes the tilt and rotation of the device, which helps your application improve user experience in games.
- Data provided by the proximity sensor denotes the distance between the device and a visible object, which enables the device to automatically turn on or off its screen accordingly to prevent accidental touch on the screen. For example, when the proximity sensor detects the user face approaches the earpiece during a call, it triggers backlight of the screen to be turned off. This prevents the screen from being accidentally touched and further reduces power consumption.
- Data provided by the barometric pressure sensor helps your application accurately determine the altitude of the device.
- Data provided by the ambient light sensor helps your device automatically adjust its backlight.
- Data provided by the Hall effect sensor implements the smart cover mode of your device. When the smart cover is closed, a small window is opened on the phone to reduce power consumption. 

### Available APIs

The sensor driver model offers the following APIs:

- Sensor HDI APIs, for easier sensor service development

- APIs for implementing sensor driver model capabilities
  - APIs for loading, registering, and deregitering sensor drivers, and detecting sensors based on the HDF
  - Unified driver API, register configuration parsing API, bus access abstract API, and platform abstract API for the same type of sensors

- APIs to be implemented by developers

  Based on the HDF Configuration Source (HCS) and differentiated configuration for sensors of the same type, you need to implement serialized configuration of sensor device parameters and some sensor device operation interfaces to simplify sensor driver development.

The sensor driver model provides APIs for the hardware service to make sensor service development easier. See the table below.

**Table 1** APIs of the sensor driver model

| API| Description|
| ----- | -------- |
| int32_t GetAllSensors(struct SensorInformation **sensorInfo, int32_t *count) | Obtains information about all registered sensors in the system. The sensor information includes the sensor name, sensor vendor, firmware version, hardware version, sensor type ID, sensor ID, maximum range, accuracy, and power consumption.|
| int32_t Enable(int32_t sensorId) | Enables a sensor. The subscriber can obtain sensor data only after the sensor is enabled.|
| int32_t Disable(int32_t sensorId) | Disables a sensor.|
| int32_t SetBatch(int32_t sensorId, int64_t samplingInterval, int64_t reportInterval) | Sets the sampling interval and data reporting interval for a sensor.|
| int32_t SetMode(int32_t sensorId, int32_t mode) | Sets the data reporting mode for a sensor.|
| int32_t SetOption(int32_t sensorId, uint32_t option) | Sets options for a sensor, including its range and accuracy.|
| int32_t Register(int32_t groupId, RecordDataCallback cb) | Registers a sensor data callback based on the group ID.|
| int32_t Unregister(int32_t groupId, RecordDataCallback cb) | Deregisters a sensor data callback based on the group ID.|



The sensor driver model provides driver development APIs that do not require further implementation. See the table below.

 **Table 2** Sensor driver development APIs

| API| Description|
| ----- | -------- |
| int32_t AddSensorDevice(const struct SensorDeviceInfo *deviceInfo) | Adds a sensor of the current type to the sensor management module.|
| int32_t DeleteSensorDevice(const struct SensorBasicInfo *sensorBaseInfo) | Deletes a sensor from the sensor management module.|
| int32_t ReportSensorEvent(const struct SensorReportEvent *events) | Reports data of a specified sensor type.|
| int32_t ReadSensor(struct SensorBusCfg *busCfg, uint16_t regAddr, uint8_t *data, uint16_t dataLen) | Reads sensor configuration data from the sensor register based on the bus configuration.|
| int32_t WriteSensor(struct SensorBusCfg *busCfg, uint8_t *writeData, uint16_t len) | Writes sensor configuration data to the sensor register based on the bus configuration.|
| int32_t SetSensorRegCfgArray(struct SensorBusCfg *busCfg, const struct SensorRegCfgGroupNode *group); | Sets the sensor register group configuration based on the sensor bus type.|
| int32_t GetSensorBaseConfigData(const struct DeviceResourceNode *node, struct SensorCfgData *config) | Obtains basic configuration information such as sensor, bus, and attribute configurations based on the device information HCS configuration, and initializes the basic configuration data structure.|
| int32_t ParseSensorRegConfig(struct SensorCfgData *config) | Parses the register group information based on the device information HCS configuration and initializes the configuration data structure.|
| void ReleaseSensorAllRegConfig(struct SensorCfgData *config) | Releases the resources allocated to the sensor configuration data structure.|
| int32_t GetSensorBusHandle(struct SensorBusCfg *busCfg) | Obtains the sensor bus handle information.|
| int32_t ReleaseSensorBusHandle(struct SensorBusCfg *busCfg) | Releases the sensor bus handle information.|



The sensor driver model also provides certain driver development APIs that need to be implemented by driver developers. See the table below.

**Table 3** APIs to be implemented by driver developers

| API| Description|
| ----- | -------- |
| int32_t init(void) | Initializes the sensor device configuration after a sensor is detected.|
| int32_t Enable(void) | Enables the current sensor by delivering the register configuration in the enabling operation group based on the device information HCS configuration.|
| int32_t Disable(void) | Disables the current sensor by delivering the register configuration in the disabling operation group based on the device information HCS configuration.|
| int32_t SetBatch(int64_t samplingInterval, int64_t reportInterval) | Sets the processing time of the data reporting thread for the current sensor based on the sampling interval and data reporting interval.|
| int32_t SetMode(int32_t mode) | Sets the data reporting mode of the current sensor device.|
| int32_t SetOption(uint32_t option) | Sets the register configuration such as the range and accuracy based on sensor options.|
| void ReadSensorData(void) | Reads sensor data.|


### How to Develop
1. Develop the acceleration sensor abstract driver. Specifically, implement the **Bind**, **Init**, **Release**, and **Dispatch** functions.

   - Implement the entry function for the acceleration sensor.

     ```c
     /* Register the entry structure object of the acceleration sensor. */
     struct HdfDriverEntry g_sensorAccelDevEntry = {
         .moduleVersion = 1,                // Version of the acceleration sensor module.
         .moduleName = "HDF_SENSOR_ACCEL",  // Name of the acceleration sensor module. The value must be the same as that of moduleName in the device_info.hcs file.
         .Bind = BindAccelDriver,           // Function for binding an acceleration sensor.
         .Init = InitAccelDriver,           // Function for initializing an acceleration sensor.
         .Release = ReleaseAccelDriver      // Function for releasing acceleration sensor resources.
     };
     
     /* Call HDF_INIT to register the driver entry with the HDF. When loading the driver, the HDF calls Bind() and then Init() to load the driver. If Init() fails to be called, the HDF calls Release() to release resources and exit. */
     HDF_INIT(g_sensorAccelDevEntry);
     ```

   - Implement interfaces for acceleration sensor driver operations.

     ```c
     /* Bind the service provided by the acceleration sensor driver to the HDF. */
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
     
     /* Register the normalization functions of the acceleration sensor driver. */
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
     /* Provide the initialization interface for the chipset driver to parse the basic acceleration sensor configuration (acceleration information, bus configuration, and sensor detection register configuration), detect sensors, and parse sensor registers. */
     static int32_t InitAccelAfterDetected(struct SensorCfgData *config)
     {
         struct SensorDeviceInfo deviceInfo;
         CHECK_NULL_PTR_RETURN_VALUE(config, HDF_ERR_INVALID_PARAM);
         /* Initialize the acceleration sensor function. */
         if (InitAccelOps(config, &deviceInfo) != HDF_SUCCESS) {
             HDF_LOGE("%s: Init accel ops failed", __func__);
             return HDF_FAILURE;
         }
         /* Register the acceleration sensor with the sensor management module. */
         if (AddSensorDevice(&deviceInfo) != HDF_SUCCESS) {
             HDF_LOGE("%s: Add accel device failed", __func__);
             return HDF_FAILURE;
         }
         /* Parse the sensor register. */
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
         ...
         /* Continue the next detection if the sensor is not detected. */
         if (drvData->detectFlag) {
             HDF_LOGE("%s: Accel sensor have detected", __func__);
             return NULL;
         }
         if (drvData->accelCfg == NULL) {
             HDF_LOGE("%s: Accel accelCfg pointer NULL", __func__);
             return NULL;
         }
         /* Parse the basic sensor configuration. */
         if (GetSensorBaseConfigData(node, drvData->accelCfg) != HDF_SUCCESS) {
             HDF_LOGE("%s: Get sensor base config failed", __func__);
             goto BASE_CONFIG_EXIT;
         }
         /* Continue the next detection if the sensor is not detected. */
         if (DetectSensorDevice(drvData->accelCfg) != HDF_SUCCESS) {
             HDF_LOGI("%s: Accel sensor detect device no exist", __func__);
             drvData->detectFlag = false;
             goto BASE_CONFIG_EXIT;
         }
         drvData->detectFlag = true;
         /* Parse the sensor register. */
         if (InitAccelAfterDetected(drvData->accelCfg) != HDF_SUCCESS) {
             HDF_LOGE("%s: Accel sensor detect device no exist", __func__);
             goto INIT_EXIT;
         }
         return drvData->accelCfg;
         ...
     }
     /* The entry function of the acceleration sensor driver is used to initialize the sensor private data structure object, allocate space for the sensor HCS data configuration object, call the entry function for initializing the sensor HCS data configuration, detect whether the sensor device is in position, create a timer for sensor data reporting, register the sensor normalization APIs, and register the sensor device. */
     int32_t AccelInitDriver(struct HdfDeviceObject *device)
     {
         ...
         /* Initialize work queue resources. */
         if (InitAccelData(drvData) != HDF_SUCCESS) {
             HDF_LOGE("%s: Init accel config failed", __func__);
             return HDF_FAILURE;
         }
         /* Allocate acceleration configuration resources. */
         drvData->accelCfg = (struct SensorCfgData *)OsalMemCalloc(sizeof(*drvData->accelCfg));
         if (drvData->accelCfg == NULL) {
             HDF_LOGE("%s: Malloc accel config data failed", __func__);
             return HDF_FAILURE;
         }
         /* Register the register group information. */
         drvData->accelCfg->regCfgGroup = &g_regCfgGroup[0];
         ...
         return HDF_SUCCESS;
     }
     /* Release the resources allocated during driver initialization. */
     void AccelReleaseDriver(struct HdfDeviceObject *device)
     {
         CHECK_NULL_PTR_RETURN(device);
         struct AccelDrvData *drvData = (struct AccelDrvData *)device->service;
         CHECK_NULL_PTR_RETURN(drvData);
         /* Release the resources if the sensor is in position. */
         if (drvData->detectFlag) {
             AccelReleaseCfgData(drvData->accelCfg);
         }
         OsalMemFree(drvData->accelCfg);
         drvData->accelCfg = NULL;
         /* Destroy the work queue resource if the sensor is in position. */
         HdfWorkDestroy(&drvData->accelWork);
         HdfWorkQueueDestroy(&drvData->accelWorkQueue);
         OsalMemFree(drvData);
     }
     ```

2. Configure the device information about the acceleration sensor driver.

   The acceleration sensor model uses the HCS as the configuration source code. For details about the HCS configuration fields, see [Driver Configuration Management](driver-hdf-manage.md).

   ```hcs
   /* Device information HCS configuration of the acceleration sensor. */
   device_sensor_accel :: device {
       device0 :: deviceNode {
           policy = 1;                                  // Policy for the driver to publish services.
           priority = 100;                              // Priority (0–200) for starting the driver. A larger value indicates a lower priority. The recommended value is 100. If the priorities are the same, the device loading sequence is not ensured.
           preload = 0;                                 // The value 0 means to load the driver by default during the startup of the system. The value 2 means the opposite.
           permission = 0664;                           // Permission for the device node created.
           moduleName = "HDF_SENSOR_ACCEL";             // Driver name. It must be the same as moduleName in the driver entry structure.
           serviceName = "sensor_accel";                // Name of the service published by the driver. The name must be unique.
           deviceMatchAttr = "hdf_sensor_accel_driver"; // Keyword matching the private data of the driver. The value must be the same as that of match_attr in the private data configuration table of the driver.
       }
   } 
   ```

3. Develop the internal interfaces of the acceleration sensor abstract driver. Specifically, implement the **Enable**, **Disable**, **SetBatch**, **SetMode**, **SetOption**, **AccelCreateCfgData**, **AccelReleaseCfgData**, and **AccelRegisterChipOps** functions.

   ```c
   /* Leave a function empty if it is not used. */
   static int32_t SetAccelInfo(struct SensorBasicInfo *info)
   {
       (void)info;
   
       return HDF_ERR_NOT_SUPPORT;
   }
   /* Deliver the configuration of enabling the register groups. */
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
   /* Deliver the configuration of disabling the register groups. */
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
   /* Set the sampling interval and data reporting interval of the sensor. */
   static int32_t SetAccelBatch(int64_t samplingInterval, int64_t interval)
   {
       (void)interval;
   
       struct AccelDrvData *drvData = NULL;
   
       drvData = AccelGetDrvData();
       CHECK_NULL_PTR_RETURN_VALUE(drvData, HDF_ERR_INVALID_PARAM);
   
       drvData->interval = samplingInterval;
   
       return HDF_SUCCESS;
   }
   /* Set the data reporting mode of the sensor. Currently, the real-time mode is supported. */
   static int32_t SetAccelMode(int32_t mode)
   {
       return (mode == SENSOR_WORK_MODE_REALTIME) ? HDF_SUCCESS : HDF_FAILURE;
   }
   
   static int32_t SetAccelOption(uint32_t option)
   {
       (void)option;
       return HDF_SUCCESS;
   }
   /* Set the sensor options. */
   static int32_t SetAccelOption(uint32_t option)
   {
       (void)option;
       return HDF_ERR_NOT_SUPPORT;
   }
   ```

4. Develop the acceleration sensor chipset driver. Specifically, implement the **Bind**, **Init**, **Release**, and **Dispatch** functions.

   ```c
   /* Message interaction of the acceleration sensor chipset driver */
   static int32_t DispatchBMI160(struct HdfDeviceIoClient *client,
       int cmd, struct HdfSBuf *data, struct HdfSBuf *reply)
   {
       (void)client;
       (void)cmd;
       (void)data;
       (void)reply;
   
       return HDF_SUCCESS;
   }
   /* Bind the service provided by the acceleration sensor chipset driver to the HDF. */
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
   /* Initialize the acceleration sensor chipset driver. */
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
   /* Release the resources allocated during driver initialization. */
   void Bmi160ReleaseDriver(struct HdfDeviceObject *device)
   {
   	...
       if (drvData->sensorCfg != NULL) {
           AccelReleaseCfgData(drvData->sensorCfg);
           drvData->sensorCfg = NULL;
       }
       OsalMemFree(drvData);
   }
   /*HdfDriverEntry object corresponding to the acceleration sensor chipset driver */
   struct HdfDriverEntry g_accelBmi160DevEntry = {
       .moduleVersion = 1,
       .moduleName = "HDF_SENSOR_ACCEL_BMI160",
       .Bind = Bmi160BindDriver,
       .Init = Bmi160InitDriver,
       .Release = Bmi160ReleaseDriver,
   };
   HDF_INIT(g_accelBmi160DevEntry);
   ```

5. Implement the **ReadData** function of the acceleration sensor chipset driver.

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
       ...
       ret = ReportSensorEvent(&event);
       if (ret != HDF_SUCCESS) {
           HDF_LOGE("%s: BMI160 report data failed", __func__);
       }
       return ret;
   }
   ```

### Verification

After the driver is developed, develop test cases in the sensor unit test to verify the basic functions of the driver. Use your test platform to set up the test environment.

```c++
static int32_t g_sensorDataFlag = 0;                        // Whether to report sensor data.
static const struct SensorInterface *g_sensorDev = nullptr; // Retain the obtained sensor interface instance address.

/* Register the data reporting function. */
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
/* Initialize the sensor interface instance before executing the test cases. */
void HdfSensorTest::SetUpTestCase()
{
    g_sensorDev = NewSensorInterfaceInstance();
    if (g_sensorDev == nullptr) {
        printf("test sensor get module instance failed\n\r");
    }
}
/* Release case resources. */
void HdfSensorTest::TearDownTestCase()
{
    if (g_sensorDev != nullptr) {
        FreeSensorInterfaceInstance();
        g_sensorDev = nullptr;
    }
}
/* Verify the sensor driver. */
HWTEST_F(HdfSensorTest,TestAccelDriver_001, TestSize.Level0)
{
    int32_t sensorInterval = 1000000000;    // Data sampling interval, in nanoseconds.
    int32_t pollTime = 5;                   // Data sampling time, in seconds.
    int32_t accelSensorId = 1;              // Acceleration sensor ID, which specifies the sensor type.
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
    /* Print the obtained sensor list. */
    for (int i = 0; i < count; i++) {
        printf("get sensorId[%d], info name[%s]\n\r", sensorInfo[i]->sensorId, sensorInfo[i]->sensorName);
    }
    ret = g_sensorDev->Enable(accelSensorId);
    EXPECT_EQ(0, ret);
    g_sensorDataFlag = 0;

    ret = g_sensorDev->SetBatch(accelSensorId, sensorInterval, pollTime);
    EXPECT_EQ(0, ret);
    /* Observe the printed data within the period specified by pollTime. */
    OsalSleep(pollTime);
    EXPECT_EQ(1, g_sensorDataFlag);

    ret = g_sensorDev->Disable(accelSensorId);
    g_sensorDataFlag = 0;
    EXPECT_EQ(0, ret);

    ret = g_sensorDev->Unregister(0, TraditionSensorTestDataCallback);
    EXPECT_EQ(0, ret);
}
```
