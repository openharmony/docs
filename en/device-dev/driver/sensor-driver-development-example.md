# Sensor Driver Development Example<a name="EN-US_TOPIC_0000001097057435"></a>

This section provides a code example of how to load and start the acceleration sensor driver based on the HDF driver model. For details about the mechanism, see  [HDF Driver Development](driver-development.md). This example uses the Bosch BMI160 acceleration sensor that communicates over I2C.

1.  Register the driver entry of the acceleration sensor.

-   Implementation of the entry function

```
/* Register the entry structure object of the acceleration sensor. */
struct HdfDriverEntry g_sensorAccelDevEntry = {
    .moduleVersion = 1, /* Version number of the acceleration sensor module */
    .moduleName = "HDF_SENSOR_ACCEL", /* Name of the acceleration sensor module. The value must be the same as that of moduleName in the device_info.hcs file. */
    .Bind = BindAccelDriver, /* Binding function of the acceleration sensor */
    .Init = InitAccelDriver, /* Initialization function of the acceleration sensor */
    .Release = ReleaseAccelDriver, /* Resource release function of the acceleration sensor */
};

/* Call HDF_INIT to register the driver entry with the HDF. When loading the driver, the HDF calls the Bind function first and then the Init function. If the Init function fails to be called, the HDF will call Release to release the driver resource and exit.
HDF_INIT(g_sensorAccelDevEntry);
```

-   Acceleration sensor configuration

The acceleration sensor model uses the HCS as the configuration source code. For details about the HCS configuration fields, see  [Driver Configuration Management](driver-configuration-management.md).

```
/* HCS configuration of the acceleration sensor device */
device_sensor_accel :: device {
    device0 :: deviceNode {
        policy = 1; /* Policy for providing the driver service */
        priority = 105; /* Driver startup priority (0–200). A larger value indicates a lower priority. The default value 100 is recommended. The sequence for loading devices with the same priority is random. */
        preload = 2; /* Field for specifying whether to load the driver. Value 0 means to load the driver, and 2 means the opposite. */
        permission = 0664; /* Permission for the driver to create device nodes */
        moduleName = "HDF_SENSOR_ACCEL"; /* Driver name. The value must be the same as that of moduleName in the driver entry structure. */
        serviceName = "sensor_accel"; /* Name of the service provided by the driver. The name must be unique. */
        deviceMatchAttr = "hdf_sensor_accel_driver"; /* Keyword matching the private data of the driver. The value must be the same as that of match_attr in the private data configuration table of the driver. */
    }
} 
```

1.  Initialize and deinitialize the acceleration sensor driver.

-   Initialization entry function  **init**

```
/* Bind the service provided by the acceleration sensor driver to the HDF. */
int32_t BindAccelDriver(struct HdfDeviceObject *device)
{
    CHECK_NULL_PTR_RETURN_VALUE(device, HDF_ERR_INVALID_PARAM);

    static struct IDeviceIoService service = {
        .object = {0},
        .Dispatch = DispatchAccel,
    };
    device->service = &service;

    return HDF_SUCCESS;
}
/* After detecting that the device is in position, call RegisterAccelChipOps to register the differentiation adaptation function. */
int32_t RegisterAccelChipOps(struct AccelOpsCall *ops)
{
    struct AccelDrvData *drvData = NULL;

    CHECK_NULL_PTR_RETURN_VALUE(ops, HDF_ERR_INVALID_PARAM);

    drvData = AccelGetDrvData();
    drvData->ops.Init = ops->Init;
    drvData->ops.ReadData = ops->ReadData;
    return HDF_SUCCESS;
}
/* Hook the acceleration sensor driver normalization function. */
static int32_t InitAccelOps(struct SensorDeviceInfo *deviceInfo)
{
    struct AccelDrvData *drvData = AccelGetDrvData();

    (void)memset_s((void *)deviceInfo, sizeof(*deviceInfo), 0, sizeof(*deviceInfo));
    deviceInfo->ops.GetInfo = SetAccelInfo;
    deviceInfo->ops.Enable = SetAccelEnable;
    deviceInfo->ops.Disable = SetAccelDisable;
    deviceInfo->ops.SetBatch = SetAccelBatch;
    deviceInfo->ops.SetMode = SetAccelMode;
    deviceInfo->ops.SetOption = SetAccelOption;

    if (memcpy_s(&deviceInfo->sensorInfo, sizeof(deviceInfo->sensorInfo),
        &drvData->accelCfg->sensorInfo, sizeof(drvData->accelCfg->sensorInfo)) != EOK) {
        HDF_LOGE("%s: copy sensor info failed", __func__);
        return HDF_FAILURE;
    }
    /* The sensor type ID can be configured in the HCS configuration file or here. */
    drvData->accelCfg->sensorInfo.sensorTypeId = SENSOR_TAG_ACCELEROMETER;
    drvData->accelCfg->sensorInfo.sensorId = SENSOR_TAG_ACCELEROMETER;

    return HDF_SUCCESS;
}
/* Initialize the sensor register. */
static int32_t InitAccelAfterConfig(void)
{
    struct SensorDeviceInfo deviceInfo;

    if (InitAccelConfig() != HDF_SUCCESS) {
        HDF_LOGE("%s: init accel config failed", __func__);
        return HDF_FAILURE;
    }

    if (InitAccelOps(&deviceInfo) != HDF_SUCCESS) {
        HDF_LOGE("%s: init accel ops failed", __func__);
        return HDF_FAILURE;
    }

    if (AddSensorDevice(&deviceInfo) != HDF_SUCCESS) {
        HDF_LOGE("%s: add accel device failed", __func__);
        return HDF_FAILURE;
    }

    return HDF_SUCCESS;
}
/* Call the device detection function to hook the differentiated device function. */
static int32_t DetectAccelChip(void)
{
    int32_t num;
    int32_t ret;
    int32_t loop;
    struct AccelDrvData *drvData = AccelGetDrvData();
    CHECK_NULL_PTR_RETURN_VALUE(drvData->accelCfg, HDF_ERR_INVALID_PARAM);

    num = sizeof(g_accelDetectIfList) / sizeof(g_accelDetectIfList[0]);
    for (loop = 0; loop < num; ++loop) {
        if (g_accelDetectIfList[loop].DetectChip != NULL) {
            ret = g_accelDetectIfList[loop].DetectChip(drvData->accelCfg);
            if (ret == HDF_SUCCESS) {
                drvData->detectFlag = true;
                break;
            }
        }
    }

    if (loop == num) {
        HDF_LOGE("%s: detect accel device failed", __func__);
        drvData->detectFlag = false;
        return HDF_FAILURE;
    }
    return HDF_SUCCESS;
}
/* The entry function of the acceleration sensor driver is used to initialize the structure object of the sensor private data, allocate space for the HCS data configuration object of the sensor, invoke the entry function for initializing the sensor HCS data configuration, detect whether the sensor device is in position, create the sensor data reporting timer, implement the sensor normalization API, and register the sensor device. */
int32_t InitAccelDriver(struct HdfDeviceObject *device)
{
    /* Obtain the private data structure object of the sensor. */
    struct AccelDrvData *drvData = AccelGetDrvData();

   /* When detecting sensors of the same type from different vendors, the function checks whether this type of sensors is in position. If yes, it no longer detects the other sensors of this type and directly returns the result. */
    if (drvData->detectFlag) {
        HDF_LOGE("%s: accel sensor have detected", __func__);
        return HDF_SUCCESS;
    }

    CHECK_NULL_PTR_RETURN_VALUE(device, HDF_ERR_INVALID_PARAM);
    /* Allocate space for the private data structure objects for storing sensor data configurations. The allocated space needs to be released when the driver is released. */
        drvData->accelCfg = (struct SensorCfgData *)OsalMemCalloc(sizeof(*cfg));
        if (drvData->accelCfg == NULL) {
            HDF_LOGE("%s: malloc sensor config data failed", __func__);
            return HDF_FAILURE;
        }
  
    drvData->accelCfg->regCfgGroup = &g_regCfgGroup[0];
    /* Initializing the sensor configuration data aims to parse the configuration information of the sensor communication bus, basic sensor information, sensor attributes, whether the sensor is in position, and register group information. */
    if (GetSensorBaseConfigData(device->property, drvData->accelCfg) != HDF_SUCCESS) {
        HDF_LOGE("%s: get sensor base config failed", __func__);
        goto Base_CONFIG_EXIT;
    }

    if (DetectAccelChip() != HDF_SUCCESS) {
        HDF_LOGE("%s: accel sensor detect device no exist", __func__);
        goto DETECT_CHIP_EXIT;
    }
    drvData->detectFlag = true;
    if (ParseSensorRegConfig(drvData->accelCfg) != HDF_SUCCESS) {
        HDF_LOGE("%s: detect sensor device failed", __func__);
        goto REG_CONFIG_EXIT;
    }

    if (InitAccelAfterConfig() != HDF_SUCCESS) {
        HDF_LOGE("%s: init accel after config failed", __func__);
        goto INIT_EXIT;
    }

    HDF_LOGI("%s: init accel driver success", __func__);
    return HDF_SUCCESS;

INIT_EXIT:
    DestroySensorThread(&drvData->thread, &drvData->threadStatus);
    (void)DeleteSensorDevice(SENSOR_TAG_ACCELEROMETER);
REG_CONFIG_EXIT:
    ReleaseSensorAllRegConfig(drvData->accelCfg);
    (void)ReleaseSensorBusHandle(&drvData->accelCfg->busCfg);
DETECT_CHIP_EXIT:
    drvData->detectFlag = false;
BASE_CONFIG_EXIT:
    drvData->accelCfg->root = NULL;
    drvData->accelCfg->regCfgGroup = NULL;
    OsalMemFree(drvData->accelCfg);
    drvData->accelCfg = NULL;
    return HDF_FAILURE;
}

/* Release the resources allocated during driver initialization. */
void ReleaseAccelDriver(struct HdfDeviceObject *device)
{
    (void)device;
    struct AccelDrvData *drvData = NULL;

    drvData = AccelGetDrvData();
    (void)DestroySensorThread(&drvData->thread, &drvData->threadStatus);
    (void)DeleteSensorDevice(SENSOR_TAG_ACCELEROMETER);
    drvData->detectFlag = false;

    if (drvData->accelCfg != NULL) {
        drvData->accelCfg->root = NULL;
        drvData->accelCfg->regCfgGroup = NULL;
        ReleaseSensorAllRegConfig(drvData->accelCfg);
        (void)ReleaseSensorBusHandle(&drvData->accelCfg->busCfg);
        OsalMemFree(drvData->accelCfg);
        drvData->accelCfg = NULL;
    }

    drvData->initStatus = false;
}
```

1.  Configure the acceleration sensor register group.

You only need to configure the acceleration sensor data according to the template. Template configuration parsing has been implemented via the  **InitSensorConfigData**  function and only needs to be called during initialization. If new configuration items are added, you need to modify this function accordingly.

```
Acceleration sensor data configuration template (accel_config.hcs)
root {
    sensorAccelConfig {
        accelChipConfig {
            /* Sensor information template */
            template sensorInfo {
                sensorName = "accelerometer"; /* Acceleration sensor name. The value contains a maximum of 16 bytes. */
                vendorName = "borsh_bmi160"; /* Sensor vendor name. The value contains a maximum of 16 bytes. */
                firmwareVersion = "1.0"; /* Sensor firmware version number. The default value is 1.0. The value contains a maximum of 16 bytes. */
                hardwareVersion = "1.0"; /* Sensor hardware version number. The default value is 1.0. The value contains a maximum of 16 bytes. */
                sensorTypeId = 1; /* Sensor type ID. For details, see SensorTypeTag. */
                sensorId = 1; /* Sensor ID, which is defined by the sensor driver developer. The SensorTypeTag enums are recommended. */
                maxRange = 8; /* Maximum measurement range of the sensor. Set this parameter based on your business requirements. */
                precision = 0; /* Sensor accuracy, which is used together with sensor data reporting. For details, see SensorEvents. */
                power = 230; /* Power consumption of the sensor */
            }
            /* Template of the bus type and configuration information used by the sensor */
            template sensorBusConfig {
                busType = 0; /* 0 for the I2C bus and 1 for the SPI bus */ 
                busNum = 6; /* Device ID allocated to the sensor on the chip */
                busAddr = 0; /* Address allocated to the sensor on the chip */
                regWidth = 1; /* Width of the sensor register address */
                regBigEndian = 0; /* Endian mode of the sensor register */
            }
            /* Sensor attribute template */
            template sensorAttr {
                chipName = ""; /* Sensor chip name */
                chipIdRegister = 0xf; /* Address of the register detecting whether the sensor is in position */
                chipIdValue = 0xd1; /* Value of the register detecting whether the sensor is in position */
            }
        }
    }
}

/* You can modify the template configuration based on the differences of sensor devices. If no modification is made, the default template configuration is used. */
root {
    sensorAccelConfig {
        accel_bmi160_chip_config : accelChipConfig {
            match_attr = "hdf_sensor_accel_driver"; /* The value must be the same as the match_attr field configured for the acceleration sensor. */
            accelInfo :: sensorInfo {
                vendorName = "borsh_bmi160";
                sensorTypeId = 1;
                sensorId = 1;
            }
            accelBusConfig :: sensorBusConfig {
                busType = 0; /* I2C communication mode */
                busNum = 6;
                busAddr = 0x68;
                regWidth = 1; /* 1-byte bit width */
            }
            accelAttr :: sensorAttr {
                chipName = "bmi160";
                chipIdRegister = 0x00;
                chipIdValue = 0xd1;
            }
            accelRegConfig {
                /*  regAddr: Register address
                    value: Register value
                    mask: Mask of the register value
                    len: Length (in bytes) of the register value
                    delay: Register delay (in milliseconds)
                    opsType: Operation type. The options can be 0 (no operation), 1 (read), 2 (write), 3 (read and check), and 4 (bit update).
                    calType: Calculation type. The options can be 0 (none), 1 (write), 2 (negate), 3 (XOR) 4, (left shift), and 5 (right shift).
                    shiftNum: Number of shifts
                    debug: Debugging switch. The value can be 0 (disabled) or 1 (enabled).
                    save: Data saving switch. The value can be 0 (not save data) or 1 (save data).
                */
                /* Groups of sensor register operations. Registers can be configured in sequence based on the groups. */
                /* Register address, register value, mask of the register value, data length of the register value, register delay, operation type, calculation type, number of shifts, debugging switch, data saving switch */
                /* Initialize the register groups. */
                initSeqConfig = [
                    0x7e,    0xb6, 0xff,   1,     5,       2,       0,        0,     0,    0,
                    0x7e,    0x10, 0xff,   1,     5,       2,       0,        0,     0,    0
                ];
                /* Enable the register groups. */
                enableSeqConfig = [
                    0x7e,    0x11, 0xff,   1,     5,       2,       0,        0,     0,    0,
                    0x41,    0x03, 0xff,   1,     0,       2,       0,        0,     0,    0,
                    0x40,    0x08, 0xff,   1,     0,       2,       0,        0,     0,    0
                ];
                /* Disable the register groups. */
                disableSeqConfig = [
                    0x7e,    0x10, 0xff,   1,     5,       2,       0,        0,     0,    0
                ];
            }
        }
    }
}
```

1.  Implement APIs for acceleration sensor driver operations.

You need to implement normalized APIs based on sensor types.

```
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

    CHECK_NULL_PTR_RETURN_VALUE(drvData->accelCfg, HDF_ERR_INVALID_PARAM);
    ret = SetSensorRegCfgArray(&drvData->accelCfg->busCfg, drvData->accelCfg->regCfgGroup[SENSOR_ENABLE_GROUP]);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%s: accel sensor disable config failed", __func__);
        return HDF_FAILURE;
    }

    drvData->threadStatus = SENSOR_THREAD_RUNNING;

    return HDF_SUCCESS;
}
/* Deliver the configuration of disabling the register groups. */
static int32_t SetAccelDisable(void)
{
    int32_t ret;
    struct AccelDrvData *drvData = AccelGetDrvData();

    CHECK_NULL_PTR_RETURN_VALUE(drvData->accelCfg, HDF_ERR_INVALID_PARAM);

    ret = SetSensorRegCfgArray(&drvData->accelCfg->busCfg, drvData->accelCfg->regCfgGroup[SENSOR_DISABLE_GROUP]);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%s: accel sensor disable config failed", __func__);
        return HDF_FAILURE;
        }

    drvData->threadStatus = SENSOR_THREAD_STOPPED;

    return HDF_SUCCESS;
}
/* Set the sampling interval and data reporting interval of the sensor. */
static int32_t SetAccelBatch(int64_t samplingInterval, int64_t interval)
{
    (void)interval;

    struct AccelDrvData *drvData = AccelGetDrvData();
    drvData->interval = samplingInterval;

    return HDF_SUCCESS;
}
/* Set the data reporting mode of the sensor. Currently, the real-time mode is supported. */
static int32_t SetAccelMode(int32_t mode)
{
    return (mode == SENSOR_WORK_MODE_REALTIME) ? HDF_SUCCESS : HDF_FAILURE;
}
/* Set the sensor options. */
static int32_t SetAccelOption(uint32_t option)
{
    (void)option;
    return HDF_ERR_NOT_SUPPORT;
}
```

-   Differentiated processing APIs 

    ```
    /* If a device is successfully detected, register the differentiated processing function to the accel driver model. */
    int32_t DetectAccelBim160Chip(struct SensorCfgData *data)
    {
        int32_t ret;
        struct AccelOpsCall ops;
        CHECK_NULL_PTR_RETURN_VALUE(data, HDF_ERR_INVALID_PARAM);
    
        if (strcmp(ACCEL_CHIP_NAME_BMI160, data->sensorAttr.chipName) != 0) {
            return HDF_SUCCESS;
        }
        ret = InitAccelPreConfig();
        if (ret != HDF_SUCCESS) {
            HDF_LOGE("%s: init  BMI160 bus mux config", __func__);
            return HDF_FAILURE;
        }
        if (DetectSensorDevice(data) != HDF_SUCCESS) {
            return HDF_FAILURE;
        }
    
       /* Differentiated processing function */
        ops.Init = InitBmi160;
        ops.ReadData = ReadBmi160Data;
        ret = RegisterAccelChipOps(&ops);
        if (ret != HDF_SUCCESS) {
            HDF_LOGE("%s: register BMI160 accel failed", __func__);
            (void)ReleaseSensorBusHandle(&data->busCfg);
            return HDF_FAILURE;
        }
        return HDF_SUCCESS;
    }
    /* Initialization processing function */
    static int32_t InitBmi160(struct SensorCfgData *data)
    {
        int32_t ret;
    
        CHECK_NULL_PTR_RETURN_VALUE(data, HDF_ERR_INVALID_PARAM);
        ret = SetSensorRegCfgArray(&data->busCfg, data->regCfgGroup[SENSOR_INIT_GROUP]);
        if (ret != HDF_SUCCESS) {
            HDF_LOGE("%s: bmi160 sensor init config failed", __func__);
            return HDF_FAILURE;
        }
        return HDF_SUCCESS;
    }
    /* Data processing function */
    int32_t ReadBmi160Data(struct SensorCfgData *data)
    {
        int32_t ret;
        struct AccelData  rawData = { 0, 0, 0 };
        int32_t tmp[ACCEL_AXIS_NUM];
        struct SensorReportEvent event;
    
        (void)memset_s(&event, sizeof(event), 0, sizeof(event));
    
        ret = ReadBmi160RawData(data, &rawData, &event.timestamp);
        if (ret != HDF_SUCCESS) {
            return HDF_FAILURE;
        }
    
        event.sensorId = SENSOR_TAG_ACCELEROMETER;
        event.option = 0;
        event.mode = SENSOR_WORK_MODE_REALTIME;
    
        rawData.x = rawData.x * BMI160_ACC_SENSITIVITY_2G;
        rawData.y = rawData.y * BMI160_ACC_SENSITIVITY_2G;
        rawData.z = rawData.z * BMI160_ACC_SENSITIVITY_2G;
    
        tmp[ACCEL_X_AXIS] = (rawData.x * SENSOR_1K_UNIT) / SENSOR_CONVERT_UNIT;
        tmp[ACCEL_Y_AXIS] = (rawData.y * SENSOR_1K_UNIT) / SENSOR_CONVERT_UNIT;
        tmp[ACCEL_Z_AXIS] = (rawData.z * SENSOR_1K_UNIT) / SENSOR_CONVERT_UNIT;
    
        event.dataLen = sizeof(tmp);
        event.data = (uint8_t *)&tmp;
        ret = ReportSensorEvent(&event);
        return ret;
    }
    ```

-   Data processing function

Create a sensor timer to periodically sample data based on the configured sampling interval and report the data to the data subscriber.

```
/* Scheduled working thread of the sensor */
static int32_t ReadAccelDataThreadWorker(void *arg)
{
    (void)arg;
    int64_t interval;
    struct AccelDrvData *drvData = AccelGetDrvData();

    drvData->threadStatus = SENSOR_THREAD_START;
    while (true) {
        if (drvData->threadStatus == SENSOR_THREAD_RUNNING) {
            if (drvData->ops.ReadData != NULL) {
                (void)drvData->ops.ReadData(drvData->accelCfg);
            }
            interval = OsalDivS64(drvData->interval, (SENSOR_CONVERT_UNIT * SENSOR_CONVERT_UNIT));
            OsalMSleep(interval);
        } else if (drvData->threadStatus == SENSOR_THREAD_DESTROY) {
            break;
        } else {
            OsalMSleep(ACC_DEFAULT_SAMPLING_200_MS / SENSOR_CONVERT_UNIT / SENSOR_CONVERT_UNIT);
        }

        if ((!drvData->initStatus) || (drvData->interval < 0) || drvData->threadStatus != SENSOR_THREAD_RUNNING) {
            continue;
        }
    }

    return HDF_SUCCESS;
}
/* Create a sensor timer and initialize the sensor device. */
static int32_t InitAccelConfig(void)
{
    int32_t ret;
    struct AccelDrvData *drvData = AccelGetDrvData();

    if (drvData->threadStatus != SENSOR_THREAD_NONE && drvData->threadStatus != SENSOR_THREAD_DESTROY) {
        HDF_LOGE("%s: accel thread have created", __func__);
        return HDF_SUCCESS;
    }

    ret = CreateSensorThread(&drvData->thread, ReadAccelDataThreadWorker, "hdf_sensor_accel", drvData);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%s: accel create thread failed", __func__);
        drvData->threadStatus = SENSOR_THREAD_NONE;
        return HDF_FAILURE;
    }

    CHECK_NULL_PTR_RETURN_VALUE(drvData->ops.Init, HDF_ERR_INVALID_PARAM);

    ret = drvData->ops.Init(drvData->accelCfg);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%s: accel create thread failed", __func__);
        drvData->threadStatus = SENSOR_THREAD_NONE;
        return HDF_FAILURE;
    }
    drvData->initStatus = true;
    return HDF_SUCCESS;
}
```

-   Major data structures

```
/* Sensor conversion units */
#define SENSOR_CONVERT_UNIT             1000
#define SENSOR_1K_UNIT                  1024
/* Sensitivity conversion value of the sensor with a 2g measurement range */
#define BMI160_ACC_SENSITIVITY_2G       61
/* Address of the sensor data sampling register */
#define BMI160_ACCEL_X_LSB_ADDR              0X12
#define BMI160_ACCEL_X_MSB_ADDR              0X13
#define BMI160_ACCEL_Y_LSB_ADDR              0X14
#define BMI160_ACCEL_Y_MSB_ADDR              0X15
#define BMI160_ACCEL_Z_LSB_ADDR              0X16
#define BMI160_ACCEL_Z_MSB_ADDR              0X17
/* Data dimension of the sensor */
enum AccelAxisNum {
    ACCEL_X_AXIS   = 0,
    ACCEL_Y_AXIS   = 1,
    ACCEL_Z_AXIS   = 2,
    ACCEL_AXIS_NUM = 3,
};
/* Each dimension of the sensor */
struct AccelData {
    int32_t x;
    int32_t y;
    int32_t z;
};
/* Private data structure of the sensor */
struct AccelDrvData {
    bool detectFlag;
    uint8_t threadStatus;
    uint8_t initStatus;
    int64_t interval;
    struct SensorCfgData *accelCfg;
    struct OsalThread thread;
    struct AccelOpsCall ops;
};
/* Differentiation adaptation function */
struct AccelOpsCall {
    int32_t (*Init)(struct SensorCfgData *data);
    int32_t (*ReadData)(struct SensorCfgData *data);
};
```

