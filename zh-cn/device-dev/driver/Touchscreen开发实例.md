# Touchscreen开发实例<a name="ZH-CN_TOPIC_0000001052576212"></a>

-   [设备描述配置](#section85281142102317)
-   [板级配置及器件私有配置](#section189081946192410)
-   [添加器件驱动](#section19856687253)

本实例提供touchscreen驱动开发示例，并简要对具体关键点进行开发说明。

## 设备描述配置<a name="section85281142102317"></a>

如下配置主要包含input驱动模型各模块层级信息，具体原理可参考[HDF驱动开发指南](驱动开发.md)，HDF框架依据该配置信息实现对Input模型各模块的依次加载等。

```
input :: host {
            hostName = "input_host";
            priority = 100;
            device_input_manager :: device {
                device0 :: deviceNode {
                    policy = 2;        // 向外发布服务
                    priority = 100;    // 加载优先级，在input模块内，manager模块优先级应为最高
                    preload = 0;       // 加载该驱动 0:加载 1:不加载
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

## 板级配置及器件私有配置<a name="section189081946192410"></a>

如下配置包含板级硬件配置及器件私有数据配置，实际业务开发时，可根据具体需求增删及修改如下配置文件信息。

```
root {
    input_config {
        touchConfig {
            touch0 {
                boardConfig {
                    match_attr = "touch_device1";
                    inputAttr {
                        inputType = 0;           // 0代表触摸屏
                        solutionX = 480; 
                        solutionY = 960;
                        devName = "main_touch";  // 设备名称
                    }
                    busConfig {
                        busType = 0;             // 0代表I2C
                        busNum = 6;
                        clkGpio = 86;
                        dataGpio = 87;
                        i2cClkIomux = [0x114f0048, 0x403];  // i2c_clk对应pin的寄存器配置
                        i2cDataIomux = [0x114f004c, 0x403]; // i2c_data对应pin的寄存器配置
                    }
                    pinConfig {
                        rstGpio = 3;
                        intGpio = 4;
                        rstRegCfg = [0x112f0094, 0x400];  // reset对应pin的寄存器配置
                        intRegCfg = [0x112f0098, 0x400];  // interrupt对应pin的寄存器配置
                    }
                    powerConfig {
                        vccType = 2;       // 1代表LDO、2代表GPIO、3代表PMIC
                        vccNum = 20;       // GPIO号为20
                        vccValue = 1800;   // 电压幅值为1800mV
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
                        chipInfo = "AAAA11222";  // 1~4字符代表产品名，5~6字符代表IC型号，7~9字符代表模型型号
                        busType = 0;
                        deviceAddr = 0x5D;
                        irqFlag = 2;             // 1代表上升沿触发，2代表下降沿触发，4代表高电平触发，8代表低电平触发
                        maxSpeed = 400;
                        chipVersion = 0;
                        powerSequence {
                            /* 上电时序的配置含义说明：
                               [类型, 状态, 方向 , 延时]
                               <type> 0代表空，1代表vcc电源（1.8V），2代表VCI电源（3.3V），3代表复位管脚，4代表中断管脚
                               <status> 0代表下电或拉低，1代表上电或拉高，2代表无操作
                               <dir> 0代表输入方向，1代表输出方向，2代表无操作
                               <delay> 代表延时多少毫秒, 例如20代表延时20ms
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

## 添加器件驱动<a name="section19856687253"></a>

在器件驱动中，主要实现了平台预留的差异化接口，以器件数据获取及解析进行示例说明。具体开发过程，需要根据实际使用的单板及器件进行适配。

```
/* 将从器件中读取到的报点数据解析为坐标 */
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
/* 从器件中获取报点数据 */
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
    /* 从寄存器中读取报点值 */
    (void)InputI2cRead(i2cClient, reg, GT_ADDR_LEN, buf, GT_POINT_SIZE * pointNum);
    /* 解析报点值 */
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
    /* 解析器件私有配置 */
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
    /* 器件私有配置解析 */
    chipCfg = ChipConfigInstance(device);
    if (chipCfg == NULL) {
        return HDF_ERR_MALLOC_FAIL;
    }
    /* 器件设备实例化 */
    chipDev = ChipDeviceInstance();
    if (chipDev == NULL) {
        goto freeCfg;
    }
    chipDev->chipCfg = chipCfg;
    chipDev->ops = &g_sampleChipOps;
    chipDev->chipName = chipCfg->chipName;
    chipDev->vendorName = chipCfg->vendorName;

   /* 器件设备注册到平台驱动 */
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

