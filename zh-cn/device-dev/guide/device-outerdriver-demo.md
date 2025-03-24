# 外设驱动开发示例<a name="ZH-CN_TOPIC_0000001157063303"></a>


## 概述<a name="section86753818426"></a>

本文档将介绍如何基于Hi3516DV300开发板完成基于HDF\_Input模型的触摸屏器件驱动开发，从而使开发者快速入门，进行基于OpenHarmony的外设驱动开发。

### 硬件资源简介<a name="section123071189431"></a>

Hi3516DV300开发板套件所提供的触摸屏器件IC为GT911，该器件采用标准I2C与主机通信，通过6pin软排线与主板连接。6pin分布以及实物连接图如下图所示：

![](figures/6-pin-distribution-and-physical-connection.png)

### Input模型简介<a name="section53684425430"></a>

Input驱动模型核心部分由设备管理层、公共驱动层、器件驱动层组成。其中：

-   设备管理层：主要为各类输入设备驱动提供input设备的注册、注销接口，同时统一管理input设备列表。
-   公共驱动层：负责对板级硬件进行初始化、硬件中断处理、向manager注册input设备等。
-   器件驱动层：通过适配平台驱动预留的差异化接口，实现器件驱动开发量最小化。

此外，Input模型预先实现了数据通道以及设备配置信息解析等函数。

关于Input模型的详细介绍请参考《[Touchscreen开发概述](../driver/driver-peripherals-touch-des.md#概述)》。

## 环境搭建<a name="section661075474418"></a>

环境准备具体操作请参考[快速入门环境搭建章节](../quick-start/quickstart-overview.md)。

>![](../public_sys-resources/icon-notice.gif) **须知：** 
>本示例针对OpenHarmony轻量系统、小型系统、标准系统都适用，本文以标准系统为例。其他系统的开发者可参考对应系统的指导文档进行环境搭建。

## TouchScreen器件驱动开发<a name="section15233162984520"></a>

基于Input模型适配一款触摸屏IC需要完成的具体工作见下。

### 配置设备描述信息<a name="section16761205604515"></a>

驱动注册到HDF框架所需要的设备驱动描述信息，如驱动是否加载以及加载次序等。

配置文件路径：./drivers/adapter/khdf/linux/hcs/device\_info/device\_info.hcs

device\_info.hcs中的信息主要提供给HDF框架使用，包含了Input模型各层驱动注册到HDF框架所必需的信息，开发者无特殊场景需求无需改动。各驱动层私有配置信息通过“deviceMatchAttr”字段与input\_config.hcs中的“match\_attr”相关内容进行匹配。

配置文件中与input模块相关的内容如下所示，相关字段的详细含义可以参考《[驱动配置](../driver/driver-overview-foundation.md)》：

```
input :: host {
            hostName = "input_host";
            priority = 100;
            device_input_manager :: device {              // Input管理层设备描述信息。
                device0 :: deviceNode {
                    policy = 2;                           // 向内核用户态均发布服务。
                    priority = 100;                       // input管理层驱动优先级默认为100。
                    preload = 0;                          // 加载该驱动。
                    permission = 0660;                    // 驱动创建设备节点权限。
                    moduleName = "HDF_INPUT_MANAGER";     // 与驱动入口的moduleName匹配。
                    serviceName = "hdf_input_host";       // HDF框架生成的节点名。
                    deviceMatchAttr = "";                 // manager目前不需要私有配置，因此为空。
                }
            }

            device_hdf_touch :: device {                  // Input公共驱动层设备描述信息。
                device0 :: deviceNode {
                    policy = 2;                           // 向内核用户态均发布服务。
                    priority = 120;                       // input公共驱动优先级默认为120。
                    preload = 0;                          // 加载该驱动。
                    permission = 0660;                    // 驱动创建设备节点权限。
                    moduleName = "HDF_TOUCH";             // 与驱动入口的moduleName匹配。
                    serviceName = "hdf_input_event1";     // HDF框架生成的节点名。
                    deviceMatchAttr = "touch_device1";    // 与私有配置信息中的“match_attr”字段保持一致。
                }
            }

            device_touch_chip :: device {                 // Input器件驱动层信息。
                device0 :: deviceNode {
                    policy = 0;                           // 向内核用户态均不发布服务。
                    priority = 130;                       // input器件驱动优先级默认为130。
                    preload = 0;                          // 加载该驱动。
                    permission = 0660;                    // 驱动创建设备节点权限。
                    moduleName = "HDF_TOUCH_GT911";       // 与驱动入口的moduleName匹配。
                    serviceName = "hdf_touch_gt911_service";// HDF框架生成的节点名。
                    deviceMatchAttr = "zsj_gt911_5p5";    // 与私有配置信息中的“match_attr”字段保持一致。
                }
            }
  }
```

该配置文件中需要重点关注的字段有：

“priority”决定驱动加载顺序；

“preload”决定驱动是否加载；

“moduleName”需要与驱动注册入口处的“moduleName”字段保持一致；

“serviceName”HDF框架依据该字段创建节点名；

“deviceMatchAttr”需要与私有配置信息中的“match\_attr”字段保持一致。

通过配置设备描述信息，使得HDF框架通过moduleName与注册至驱动入口的代码相匹配，保证了驱动的正常加载，通过priority字段保证了各驱动的加载顺序。

### 配置Touchscreen器件信息<a name="section156331030144617"></a>

器件私有信息包括上下电时序等，平台硬件信息包括器件连接主板的GPIO端口信息等。

配置文件路径：./drivers/adapter/khdf/linux/hcs/input/input\_config.hcs

input\_config.hcs中的信息由驱动代码进行读取解析，主要由公共驱动层的私有配置信息及器件驱动层的私有配置信息组成。文件中的配置包含板级硬件信息及器件私有配置信息，实际业务开发时，可根据具体需求增删及修改对应内容。

```
root {                                                              
    input_config {
        touchConfig {
            touch0 {                                                 // 第一款触摸屏。
                boardConfig {                                        // 板级硬件信息。
                    match_attr = "touch_device1";                    // 与设备描述配置信息中公共驱动层私有配置信息的“match_attr”字段保持一致。    
                    inputAttr {
                        /* 0:touch 1:key 2:keyboard 3:mouse 4:button 5:crown 6:encoder */
                        inputType = 0;                               // input类型为touch。
                        solutionX = 480;                             // 分辨率X信息。
                        solutionY = 960;                             // 分辨率Y信息。
                        devName = "main_touch";                      // 设备名称。
                    }
                    busConfig {
                        /* 0:i2c 1:spi */
                        busType = 0;                                 // GT911采用I2C通信。
                        busNum = 6;                                  // 与主机芯片第6路I2C通信。
                        clkGpio = 86;                                // 主机芯片SCL管脚。
                        dataGpio = 87;                               // 主机芯片SDA管脚。
                        i2cClkIomux = [0x114f0048, 0x403];           // SCL管脚配置信息。
                        i2cDataIomux = [0x114f004c, 0x403];          // SDA管脚配置信息。
                    }
                    pinConfig {
                        rstGpio = 3;                                 // 复位管脚连接主机芯片的3号管脚。
                        intGpio = 4;                                 // 中断管脚连接主机芯片的4号管脚。
                        rstRegCfg = [0x112f0094, 0x400];             // 复位管脚配置信息。
                        intRegCfg = [0x112f0098, 0x400];             // 中断管脚配置信息。
                    }
                    powerConfig {
                        /* 0:unused 1:ldo 2:gpio 3:pmic */
                        vccType = 2;                                  // GPIO供电。
                        vccNum = 20;                                  // gpio20。
                        vccValue = 1800;                              // 电压幅值为1800mV。
                        vciType = 1;                                  // LDO供电。
                        vciNum = 12;                                  // ldo12。
                        vciValue = 3300;                              // 电压幅值为3300mV。
                    }

                    featureConfig {
                        capacitanceTest = 0;                          // 容值测试。
                        gestureMode = 0;                              // 手势模式。
                        gloverMode = 0;                               // 手套模式。
                        coverMode = 0;                                // 皮套模式。
                        chargerMode = 0;                              // 充电模式。
                        knuckleMode = 0;                              // 指关节模式。
                    }
                }
                chipConfig {                                          // 器件私有信息配置。
                    template touchChip {                              // 模板。
                        match_attr = "";
                        chipName = "gt911";                           // 触摸屏IC型号。
                        vendorName = "zsj";                           // 供应商。
                        chipInfo = "AAAA11222";                       // 1~4字符代表产品名，5~6字符代表IC型号，7~9字符代表模型型号。
                        busType = 0;                                  // 0代表I2C，1代表SPI。
                        deviceAddr = 0x5D;                            // 器件IC通信地址。
                        irqFlag = 2;                                  // 1代表上升沿触发，2代表下降沿触发，4代表高电平触发，8代表低电平触发。
                        maxSpeed = 400;                               // 最大通信速率为400Hz。
                        chipVersion = 0;                              // 触摸屏IC版本号。
                        powerSequence {
                             /* 上电时序的配置含义说明：
                               [类型, 状态, 方向 , 延时]
                               <type> 0代表空，1代表vcc电源（1.8V），2代表VCI电源（3.3V），3代表复位管脚，4代表中断管脚
                               <status> 0代表下电或拉低，1代表上电或拉高，2代表无操作
                               <dir> 0代表输入方向，1代表输出方向，2代表无操作
                               <delay> 代表延时多少毫秒, 例如20代表延时20ms
                             */
                            powerOnSeq = [4, 0, 1, 0,                 // 中断管脚配置为输出，且进行拉低。
                                         3, 0, 1, 10,                 // 复位管脚配置为输出，且进行拉低，延时10ms。
                                         3, 1, 2, 60,                 // 复位管脚无操作，且进行拉高，延时60ms。
                                         4, 2, 0, 0];                 // 中断管脚配置为输入。
                            suspendSeq = [3, 0, 2, 10];               // 复位管脚无操作，且进行拉低，延时10ms。
                            resumeSeq = [3, 1, 2, 10];                // 复位管脚无操作，且进行拉高，延时10ms。
                            powerOffSeq = [3, 0, 2, 10,               // 复位管脚无操作，且进行拉低，延时10ms。
                                           1, 0, 2, 20];              // 电源正极管脚无操作，且进行拉低，延时20ms。
                        }
                    }

                    chip0 :: touchChip {
                        match_attr = "zsj_gt911_5p5";                 // 与设备描述配置信息中器件私有配置信息的“match_attr”字段保持一致。
                        chipInfo = "ZIDN45100";                       // 产品名+模组编号+芯片编号的组合信息 用于给用户态区分当前器件。
                        chipVersion = 0;                              // IC型号的版本。
                    }
                }
            }
        }
    }
}
```

示例中“touchConfig”包含了“touch0”，"touch0"包含了“boardConfig”与“chipConfig”；“boardConfig”字段包含了Hi3516DV300板级硬件信息，“chipConfig”包含了触摸屏器件的私有信息，如果需要替换触摸屏器件，重新配置“chipConfig”对应的字段信息即可。同时产品可以配置多款触摸屏，示例中用“touch0”代表了套件中默认的触摸屏的硬件接口以及器件的配置信息，如产品需要配置副屏，可在与“touch0”并列的位置配置“touch1”的信息。

### 适配器件私有驱动<a name="section17127331595"></a>

Input模型对Input设备开发流程进行了抽象，开发者只需要适配器件驱动层，无需改动管理驱动层以及公共驱动层。

Input模型由三层驱动组成，开发者适配一款全新触摸屏驱动只需要适配器件驱动层即可，重点实现差异化接口，本小节以代码示例的形式展示开发者需要重点完成的工作。

1.  触摸屏器件差异化接口适配。

    示例代码路径：./drivers/framework/model/input/driver/touchscreen/touch\_gt911.c

    ```
    static struct TouchChipOps g_gt911ChipOps = {                                  // 器件IC接口。
        .Init = ChipInit,                                                          // 初始化。
        .Detect = ChipDetect,                                                      // 器件检测。
        .Resume = ChipResume,                                                      // 唤醒。
        .Suspend = ChipSuspend,                                                    // 休眠。
        .DataHandle = ChipDataHandle,                                              // 器件数据读取。
        .UpdateFirmware = UpdateFirmware,                                          // 固件升级。
    };
    
    /* 不同触摸屏厂家使用的IC不一样，对应的寄存器操作也不一样，因此器件驱动层代码重点适配差异化接口部分，如下示例代码展示了GT911的数据解析*/
    
    static int32_t ChipDataHandle(ChipDevice *device)
    {
        ...
        /*  GT911获取坐标之前需先读取状态寄存器  */
        reg[0] = (GT_BUF_STATE_ADDR >> ONE_BYTE_OFFSET) & ONE_BYTE_MASK; 
        reg[1] = GT_BUF_STATE_ADDR & ONE_BYTE_MASK;
        ret = InputI2cRead(i2cClient, reg, GT_ADDR_LEN, &touchStatus, 1);
        if (ret < 0 || touchStatus == GT_EVENT_INVALID) {
            return HDF_FAILURE;
        }
        ...
        /* 根据状态寄存器的值读取数据寄存器数据 */
        reg[0] = (GT_X_LOW_BYTE_BASE >> ONE_BYTE_OFFSET) & ONE_BYTE_MASK;
        reg[1] = GT_X_LOW_BYTE_BASE & ONE_BYTE_MASK;
        pointNum = touchStatus & GT_FINGER_NUM_MASK;
        if (pointNum == 0 || pointNum > MAX_SUPPORT_POINT) {
            HDF_LOGE("%s: pointNum is invalid, %u", __func__, pointNum);
            (void)ChipCleanBuffer(i2cClient);
            OsalMutexUnlock(&device->driver->mutex);
            return HDF_FAILURE;
        }
        frame->realPointNum = pointNum;
        frame->definedEvent = TOUCH_DOWN;
        (void)InputI2cRead(i2cClient, reg, GT_ADDR_LEN, buf, GT_POINT_SIZE * pointNum);
        /* 对获取的数据进行解析 */
        ParsePointData(device, frame, buf, pointNum);
        ...
    }
    static void ParsePointData(ChipDevice *device, FrameData *frame, uint8_t *buf, uint8_t pointNum)
    {
        ...
        /* 每个坐标值由两个字节组成，对获取的单字节数据进行拼接得到最终的坐标值 */
        for (i = 0; i < pointNum; i++) {
                frame->fingers[i].trackId = buf[GT_POINT_SIZE * i + GT_TRACK_ID];
                frame->fingers[i].y = (buf[GT_POINT_SIZE * i + GT_X_LOW] & ONE_BYTE_MASK) |
                                      ((buf[GT_POINT_SIZE * i + GT_X_HIGH] & ONE_BYTE_MASK) << ONE_BYTE_OFFSET);
                frame->fingers[i].x = (buf[GT_POINT_SIZE * i + GT_Y_LOW] & ONE_BYTE_MASK) |
                                      ((buf[GT_POINT_SIZE * i + GT_Y_HIGH] & ONE_BYTE_MASK) << ONE_BYTE_OFFSET);
                /* 对解析出来的坐标值进行打印 */
                HDF_LOGD("%s: x = %d, y = %d", __func__, frame->fingers[i].x, frame->fingers[i].y);
         }
    }
    ```

2.  器件层驱动初始化及注册驱动至HDF框架。

    示例代码路径：./drivers/framework/model/input/driver/touchscreen/touch\_gt911.c

    ```
    static int32_t HdfGoodixChipInit(struct HdfDeviceObject *device)
    {
        ...
        /* 器件配置结构体内存申请、配置信息解析及挂载 */
        chipCfg = ChipConfigInstance(device);
        ...
        /* 器件实例化 */
        chipDev = ChipDeviceInstance();
        ...
        /* 器件信息挂载及器件私有操作挂载 */
        chipDev->chipCfg = chipCfg;
        chipDev->ops = &g_gt911ChipOps;
        ...
        /* 注册器件驱动至平台驱动 */
        RegisterChipDevice(chipDev);
        ...
    }
    struct HdfDriverEntry g_touchGoodixChipEntry = {
        .moduleVersion = 1,
        .moduleName = "HDF_TOUCH_GT911",   // 该moduleName与device_info.hcs文件中器件驱动层的moduleName信息相匹配。
        .Init = HdfGoodixChipInit,         // 器件驱动初始化函数。
    };
    HDF_INIT(g_touchGoodixChipEntry);      // 注册器件驱动至HDF框架。
    ```

    器件私有驱动层主要实现了各器件厂商差异较大的部分，如器件休眠唤醒、数据解析以及固件升级等。

    至此，基于HDF框架及Input模型的触摸屏驱动适配完成。


## 编译及烧录<a name="section16465031164711"></a>

1.  编辑Makefile文件，添加本示例中的内容：

    文件路径：./drivers/adapter/khdf/linux/model/input/Makefile

    添加内容如下：

    ```
    obj-$(CONFIG_DRIVERS_HDF_TP_5P5_GT911) += \
                  $(INPUT_ROOT_DIR)/touchscreen/touch_gt911.o
    ```

    其中touch\_gt911.o为本示例中追加的内容。

2.  具体编译及烧录操作请参考[标准系统快速入门的编译及烧录章节](../quick-start/quickstart-overview.md)。

## 调试验证<a name="section62577313482"></a>

如下所示为开机启动日志部分截取

```
[I/HDF_INPUT_DRV] HdfInputManagerInit: enter                            // 管理驱动层初始化。                 
[I/HDF_INPUT_DRV] HdfInputManagerInit: exit succ                        // 初始化成功。                   
[I/osal_cdev] add cdev hdf_input_host success                                                                                                                   
[I/HDF_LOG_TAG] HdfTouchDriverProbe: enter                              // 公共驱动层初始化。                    
[I/HDF_LOG_TAG] HdfTouchDriverProbe: main_touch exit succ               // 初始化成功。                     
[I/osal_cdev] add cdev hdf_input_event1 success                                                                                                                 
[I/HDF_INPUT_DRV] HdfGoodixChipInit: enter                              // 器件驱动层初始化。                                        
[I/HDF_INPUT_DRV] ChipDetect: IC FW version is 0x1060                           
[I/HDF_INPUT_DRV] Product_ID: 911_1060, x_sol = 960, y_sol = 480                
[I/HDF_LOG_TAG] ChipDriverInit: chipDetect succ, ret = 0                                                        
[I/HDF_LOG_TAG] InputDeviceInstance: inputDev->devName = main_touch                      
[I/HDF_INPUT_DRV] HdfGoodixChipInit: exit succ, chipName = gt911        // 初始化成功。 
```

## Input模型工作流程解析<a name="section1578569154917"></a>

为了让开发者更清晰的了解Input模型工作流程，本节将对input模型加载的关键流程代码进行说明。

>![](../public_sys-resources/icon-notice.gif) **须知：** 
>本章节为Input模型工作流程说明，开发者无需进行开发。

### 私有配置信息解析<a name="section1310113815495"></a>

示例代码路径：./drivers/framework/model/input/driver/input\_config\_parser.c

根据OSAL提供的配置解析函数，可以将hcs文件中各字段含义进行解析，具体请参考input\_config\_parser.c中各函数的实现。如果提供的模板不能满足需求，在hcs文件中添加相应信息后，需要根据添加的字段开发相应的解析函数。

```
static int32_t ParseAttr(struct DeviceResourceIface *parser, const struct DeviceResourceNode *attrNode, BoardAttrCfg *attr)
{
    int32_t ret;
    ret = parser->GetUint8(attrNode, "inputType", &attr->devType, 0);     // 获取inputType字段信息，保存在BoardAttrCfg结构体中。
    CHECK_PARSER_RET(ret, "GetUint8");
    ...
    return HDF_SUCCESS;
}
```

### 管理驱动层初始化及注册驱动至HDF框架<a name="section614512119500"></a>

示例代码路径：./drivers/framework/model/input/driver/hdf\_input\_device\_manager.c

```
static int32_t HdfInputManagerInit(struct HdfDeviceObject *device)
{ 
    /* 分配内存给manager，manager中将存放所有input设备 */
    g_inputManager = InputManagerInstance();
    ...
}
struct HdfDriverEntry g_hdfInputEntry = {
    .moduleVersion = 1,
    .moduleName = "HDF_INPUT_MANAGER",
    .Bind = HdfInputManagerBind,
    .Init = HdfInputManagerInit,
    .Release = HdfInputManagerRelease,
};

HDF_INIT(g_hdfInputEntry);                                               //驱动注册入口。
```

### 公共驱动层初始化及注册驱动至HDF框架<a name="section16194201755019"></a>

示例代码路径：./drivers/framework/model/input/driver/hdf\_touch.c

```
static int32_t HdfTouchDriverProbe(struct HdfDeviceObject *device)
{
    ...
    /* 板级信息结构体内存申请及hcs配置信息解析 */
    boardCfg = BoardConfigInstance(device);
    ...
    /* 公共驱动结构体内存申请 */
    touchDriver = TouchDriverInstance();
    ...
    /* 依据解析出的板级信息进行公共资源初始化，如IIC初始化 */
    ret = TouchDriverInit(touchDriver, boardCfg);
    if (ret == HDF_SUCCESS) {
        ...
        /* 添加驱动至公共驱动层驱动管理链表，当设备与驱动进行绑定时使用该链表进行查询 */
        AddTouchDriver(touchDriver);
        ...
    }
    ...
}
struct HdfDriverEntry g_hdfTouchEntry = {
    .moduleVersion = 1,
    .moduleName = "HDF_TOUCH",
    .Bind = HdfTouchDriverBind,
    .Init = HdfTouchDriverProbe,
    .Release = HdfTouchDriverRelease,
};
                               
HDF_INIT(g_hdfTouchEntry);                                              //驱动注册入口。
```

### 器件驱动层初始化及注册驱动至HDF框架<a name="section1090743312505"></a>

具体请参考[适配器件私有驱动](#section17127331595)器件层驱动初始化及注册驱动至HDF框架部分。

### 具体调用逻辑串联函数<a name="section81801147529"></a>

Input模型管理层驱动init函数初始化了设备管理链表，公共驱动层初始化函数完成了相关结构体的内存申请。器件驱动相关信息通过RegisterChipDevice函数对公共驱动层相关结构体进行信息填充，同时完成了相关硬件信息的初始化（如中断注册等），绑定设备与驱动组成inputDev通过RegisterInputDevice函数向驱动管理层进行注册，在RegisterInputDevice函数中主要实现了将inputDev向设备管理链表的添加等功能。如下所示为两个函数的实现部分：

```
//函数具体实现代码位置 ：./drivers/framework/model/input/driver/hdf_touch.c
int32_t RegisterChipDevice(ChipDevice *chipDev)
{
    ...
    /* 绑定设备与驱动，从而通过InputDeviceInstance函数创建inputDev */
    DeviceBindDriver(chipDev);
    ...
    /* 主要包含器件中断注册及中断处理函数,中断处理函数中有数据上报用户态的数据通道 */
    ChipDriverInit(chipDev);
    ...
    /* 申请内存实例化InputDev */
    inputDev = InputDeviceInstance(chipDev);
    ...
    /* 将InputDev设备注册至input驱动管理层 */
    RegisterInputDevice(inputDev);
    ...
}

//函数具体实现代码位置 ：./drivers/framework/model/input/driver/hdf_input_device_manager.c
int32_t RegisterInputDevice(InputDevice *inputDev)
{
    ...
    /* 申请ID，该ID对于不同input设备唯一 */
    ret = AllocDeviceID(inputDev);
    ...
    /* 该函数包含了对hid类设备的特殊处理，对于触摸屏驱动，该函数无实质操作； */
    CreateDeviceNode(inputDev);
    /* 内核态数据传送至用户态需使用IOService能力，需要申请buffer */
    AllocPackageBuffer(inputDev);
    /* 将input设备添加进设备全局管理链表 */
    AddInputDevice(inputDev);
    ...
}
```

