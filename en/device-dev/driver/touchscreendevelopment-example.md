# Touchscreen Development Example<a name="EN-US_TOPIC_0000001052576212"></a>

-   [Device Description Configuration](#section85281142102317)
-   [Board-level Hardware Configuration and Private Data Configuration](#section189081946192410)
-   [Adding the Touchscreen Driver](#section19856687253)

This example describes how to develop the touchscreen driver.

## Device Description Configuration<a name="section85281142102317"></a>

The information about modules of the input driver model is shown as follows and enables the HDF to load the modules in sequence. For details, see  [Driver Development](driver-development.md).

```
input :: host {
            hostName = "input_host";
            priority = 100;
            device_input_manager :: device {
                device0 :: deviceNode {
                    policy = 2;        // Publish services externally.
                    priority = 100;    // Loading priority. The input device manager in the input driver has the highest priority.
                    preload = 0;       // Value 0 indicates that the driver is to be loaded, and value 1 indicates the opposite.
                    permission = 0660;
                    moduleName = "HDF_INPUT_MANAGER";
                    serviceName = "input_dev_manager";
                    deviceMatchAttr = "";
                }
            }
            device_hdf_touch :: device {
                device0 :: deviceNode {
                    policy = 2;
                    priority = 120;
                    preload = 0;
                    permission = 0660;
                    moduleName = "HDF_TOUCH";
                    serviceName = "event1";
                    deviceMatchAttr = "touch_device1";
                }
            }

            device_touch_chip :: device {
                device0 :: deviceNode {
                    policy = 0;
                    priority = 130;
                    preload = 0;
                    permission = 0660;
                    moduleName = "HDF_TOUCH_SAMPLE";
                    serviceName = "hdf_touch_sample_service";
                    deviceMatchAttr = "zsj_sample_5p5";
                }
            }
}
```

## Board-level Hardware Configuration and Private Data Configuration<a name="section189081946192410"></a>

The following describes the configuration of the board-level hardware and private data of the touchscreen. You can modify the configuration based on the service requirements.

```
root {
    input_config {
        touchConfig {
            touch0 {
                boardConfig {
                    match_attr = "touch_device1";
                    inputAttr {
                        inputType = 0;           // Value 0 indicates that the input device is a touchscreen.
                        solutionX = 480; 
                        solutionY = 960;
                        devName = "main_touch"; // Device name
                    }
                    busConfig {
                        busType = 0;             // Value 0 indicates the I2C bus.
                        busNum = 6;
                        clkGpio = 86;
                        dataGpio = 87;
                        i2cClkIomux = [0x114f0048, 0x403];  // Register configuration of the i2c_clk pin
                        i2cDataIomux = [0x114f004c, 0x403]; // Register configuration of the i2c_data pin
                    }
                    pinConfig {
                        rstGpio = 3;
                        intGpio = 4;
                        rstRegCfg = [0x112f0094, 0x400];  // Register configuration of the reset pin
                        intRegCfg = [0x112f0098, 0x400];  // Register configuration of the interrupt pin
                    }
                    powerConfig {
                        vccType = 2;       // Values 1, 2, and 3 indicate the low-dropout regulator (LDO), GPIO, and PMIC, respectively.
                        vccNum = 20;       // The GPIO number is 20.
                        vccValue = 1800;   // The voltage amplitude is 1800 mV.
                        vciType = 1;
                        vciNum = 12;
                        vciValue = 3300;
                    }
                    featureConfig {
                        capacitanceTest = 0;
                        gestureMode = 0;
                        gloverMOde = 0;
                        coverMode = 0;
                        chargerMode = 0;
                        knuckleMode = 0;
                    }
                }
                chipConfig {
                    template touchChip {
                        match_attr = "";
                        chipName = "sample";
                        vendorName = "zsj";
                        chipInfo = "AAAA11222";  // The first four characters indicate the product name. The fifth and sixth characters indicate the IC model. The last three characters indicate the chip model.
                        busType = 0;
                        deviceAddr = 0x5D;
                        irqFlag = 2;             // Values 1 and 2 indicate that the interrupt is triggered on the rising and falling edges, respectively. Values 4 and 8 indicate that the interrupt is triggered by the high and low levels, respectively.
                        maxSpeed = 400;
                        chipVersion = 0;
                        powerSequence {
                            /* Power-on sequence is described as follows:
                               [Type, status, direction, delay]
                               <type> Value 0 indicates the power or pin is empty. Values 1 and 2 indicate the VCC (1.8 V) and VCI (3.3 V) power, respectively. Values 3 and 4 indicate the reset and interrupt pins, respectively.
                               <status> Values 0 and 1 indicate the power-off or pull-down, and the power-on or pull-up, respectively. Value 2 indicates that no operation is performed.
                               <dir> Values 0 and 1 indicate the input and output directions, respectively. Value 2 indicates that no operation is performed.
                               <delay> Delay time, in milliseconds.
                             */
                            powerOnSeq = [4, 0, 1, 0,
                                         3, 0, 1, 10,
                                         3, 1, 2, 60,
                                         4, 2, 0, 0];
                            suspendSeq = [3, 0, 2, 10];
                            resumeSeq = [3, 1, 2, 10];
                            powerOffSeq = [3, 0, 2, 10,
                                           1, 0, 2, 20];
                        }
                    }
                    chip0 :: touchChip {
                        match_attr = "zsj_sample_5p5";
                        chipInfo = "ZIDN45100";
                        chipVersion = 0;
                    }
                }
            }
        }
    }
}
```

## Adding the Touchscreen Driver<a name="section19856687253"></a>

The following example shows how to implement the differentiated APIs provided by the platform driver to obtain and parse the touchscreen data. You can adjust the development process based on the board and touchscreen in use.

```
/* Parse the touch reporting data read from the touchscreen into coordinates. */
static void ParsePointData(ChipDevice *device, FrameData *frame, uint8_t *buf, uint8_t pointNum)
{
    int32_t resX = device->driver->boardCfg->attr.resolutionX;
    int32_t resY = device->driver->boardCfg->attr.resolutionY;

    for (int32_t i = 0; i < pointNum; i++) {
        frame->fingers[i].y = (buf[GT_POINT_SIZE * i + GT_X_LOW] & ONE_BYTE_MASK) |
                              ((buf[GT_POINT_SIZE * i + GT_X_HIGH] & ONE_BYTE_MASK) << ONE_BYTE_OFFSET);
        frame->fingers[i].x = (buf[GT_POINT_SIZE * i + GT_Y_LOW] & ONE_BYTE_MASK) |
                              ((buf[GT_POINT_SIZE * i + GT_Y_HIGH] & ONE_BYTE_MASK) << ONE_BYTE_OFFSET);
        frame->fingers[i].valid = true;
    }
}
/* Obtain the touch reporting data from the chip. */
static int32_t ChipDataHandle(ChipDevice *device)
{
    int32_t ret;
    uint8_t touchStatus = 0;
    uint8_t pointNum;
    uint8_t buf[GT_POINT_SIZE * MAX_SUPPORT_POINT] = {0};
    InputI2cClient *i2cClient = &device->driver->i2cClient;
    uint8_t reg[GT_ADDR_LEN] = {0};
    FrameData *frame = &device->driver->frameData;
    reg[0] = (GT_BUF_STATE_ADDR >> ONE_BYTE_OFFSET) & ONE_BYTE_MASK;
    reg[1] = GT_BUF_STATE_ADDR & ONE_BYTE_MASK;
    ret = InputI2cRead(i2cClient, reg, GT_ADDR_LEN, &touchStatus, 1);
    if (ret < 0 || touchStatus == GT_EVENT_INVALID) {
        return HDF_FAILURE;
    }
    OsalMutexLock(&device->driver->mutex);
    (void)memset_s(frame, sizeof(FrameData), 0, sizeof(FrameData));
    if (touchStatus == GT_EVENT_UP) {
        frame->realPointNum = 0;
        frame->definedEvent = TOUCH_UP;
        goto exit;
    }
    reg[0] = (GT_X_LOW_BYTE_BASE >> ONE_BYTE_OFFSET) & ONE_BYTE_MASK;
    reg[1] = GT_X_LOW_BYTE_BASE & ONE_BYTE_MASK;
    pointNum = touchStatus & GT_FINGER_NUM_MASK;
    if (pointNum <= 0 || pointNum > MAX_SUPPORT_POINT) {
        HDF_LOGE("%s: pointNum is invalid, %d", __func__, pointNum);
        (void)ChipCleanBuffer(i2cClient);
        OsalMutexUnlock(&device->driver->mutex);
        return HDF_FAILURE;
    }
    frame->realPointNum = pointNum;
    frame->definedEvent = TOUCH_DOWN;
    /* Read the touch reporting data from the register. */
    (void)InputI2cRead(i2cClient, reg, GT_ADDR_LEN, buf, GT_POINT_SIZE * pointNum);
    /* Parse the touch reporting data. */
    ParsePointData(device, frame, buf, pointNum);
exit:
    OsalMutexUnlock(&device->driver->mutex);
    if (ChipCleanBuffer(i2cClient) != HDF_SUCCESS) {
        return HDF_FAILURE;
    }
    return HDF_SUCCESS;
}

static struct TouchChipOps g_sampleChipOps = {
    .Init = ChipInit,
    .Detect = ChipDetect,
    .Resume = ChipResume,
    .Suspend = ChipSuspend,
    .DataHandle = ChipDataHandle,
};

static TouchChipCfg *ChipConfigInstance(struct HdfDeviceObject *device)
{
    TouchChipCfg *chipCfg = (TouchChipCfg *)OsalMemAlloc(sizeof(TouchChipCfg));
    if (chipCfg == NULL) {
        HDF_LOGE("%s: instance chip config failed", __func__);
        return NULL;
    }
    (void)memset_s(chipCfg, sizeof(TouchChipCfg), 0, sizeof(TouchChipCfg));
    /* Parse the private configuration of the touchscreen. */
    if (ParseTouchChipConfig(device->property, chipCfg) != HDF_SUCCESS) {
        HDF_LOGE("%s: parse chip config failed", __func__);
        OsalMemFree(chipCfg);
        chipCfg = NULL;
    }
    return chipCfg;
}

static ChipDevice *ChipDeviceInstance(void)
{
    ChipDevice *chipDev = (ChipDevice *)OsalMemAlloc(sizeof(ChipDevice));
    if (chipDev == NULL) {
        HDF_LOGE("%s: instance chip device failed", __func__);
        return NULL;
    }
    (void)memset_s(chipDev, sizeof(ChipDevice), 0, sizeof(ChipDevice));
    return chipDev;
}

static void FreeChipConfig(TouchChipCfg *config)
{
    if (config->pwrSeq.pwrOn.buf != NULL) {
        OsalMemFree(config->pwrSeq.pwrOn.buf);
    }
    if (config->pwrSeq.pwrOff.buf != NULL) {
        OsalMemFree(config->pwrSeq.pwrOff.buf);
    }
    OsalMemFree(config);
}

static int32_t HdfSampleChipInit(struct HdfDeviceObject *device)
{
    TouchChipCfg *chipCfg = NULL;
    ChipDevice *chipDev = NULL;
    HDF_LOGE("%s: enter", __func__);
    if (device == NULL) {
        return HDF_ERR_INVALID_PARAM;
    }
    /* Parse the private configuration of the touchscreen. */
    chipCfg = ChipConfigInstance(device);
    if (chipCfg == NULL) {
        return HDF_ERR_MALLOC_FAIL;
    }
    /* Instantiate the touchscreen device. */
    chipDev = ChipDeviceInstance();
    if (chipDev == NULL) {
        goto freeCfg;
    }
    chipDev->chipCfg = chipCfg;
    chipDev->ops = &g_sampleChipOps;
    chipDev->chipName = chipCfg->chipName;
    chipDev->vendorName = chipCfg->vendorName;

   /* Register the touchscreen device with the platform driver. */
    if (RegisterChipDevice(chipDev) != HDF_SUCCESS) {
        goto freeDev;
    }
    HDF_LOGI("%s: exit succ, chipName = %s", __func__, chipCfg->chipName);
    return HDF_SUCCESS;

freeDev:
    OsalMemFree(chipDev);
freeCfg:
    FreeChipConfig(chipCfg);
    return HDF_FAILURE;
}

struct HdfDriverEntry g_touchSampleChipEntry = {
    .moduleVersion = 1,
    .moduleName = "HDF_TOUCH_SAMPLE",
    .Init = HdfSampleChipInit,
};

HDF_INIT(g_touchSampleChipEntry);
```

