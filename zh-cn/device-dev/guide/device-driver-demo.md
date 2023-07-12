# 平台驱动开发示例<a name="ZH-CN_TOPIC_0000001157064271"></a>

## 概述<a name="section194201316174215"></a>

本文档将以I2C驱动为例，介绍如何基于HDF驱动框架完成平台驱动开发。

>![](../public_sys-resources/icon-caution.gif) **注意：** 
>本例仅作为平台驱动开发示例参考，开发者不可直接用于商用集成。

HDF驱动框架为常用外围设备提供了标准的驱动框架，驱动开发者只需将驱动适配至HDF驱动框架，即可通过HDF驱动框架提供的接口操作外围设备。

本文以I2C为例。其时序流程如[图1](#fig9596628607)所示。

**图 1**  I2C时序流程图<a name="fig9596628607"></a>  

![](figures/I2C时序流程图.png "I2C时序流程图")

## 环境准备<a name="section6926133918422"></a>

环境准备具体操作请参考[Hi3516标准系统入门](../quick-start/quickstart-appendix-hi3516-ide.md)完成环境搭建。

>![](../public_sys-resources/icon-notice.gif) **须知：** 
>本示例针对OpenHarmony轻量系统、小型系统、标准系统都适用，本文以标准系统为例。其他系统的开发者可参考对应系统的指导文档进行环境搭建。

## 开发<a name="section65801539470"></a>

### 文件说明<a name="section0708184454414"></a>

本例中涉及的文件及路径如下表：

**表 1**  文件说明

<a name="table15887645104012"></a>
<table><thead align="left"><tr id="row198881452404"><th class="cellrowborder" align="center" valign="top" width="13.489999999999998%" id="mcps1.2.4.1.1"><p id="p158742406488"><a name="p158742406488"></a><a name="p158742406488"></a>说明</p>
</th>
<th class="cellrowborder" align="center" valign="top" width="68.52000000000001%" id="mcps1.2.4.1.2"><p id="p6975142717432"><a name="p6975142717432"></a><a name="p6975142717432"></a>文件路径</p>
</th>
<th class="cellrowborder" align="center" valign="top" width="17.990000000000002%" id="mcps1.2.4.1.3"><p id="p98891454405"><a name="p98891454405"></a><a name="p98891454405"></a>操作</p>
</th>
</tr>
</thead>
<tbody><tr id="row1088914458407"><td class="cellrowborder" align="left" valign="top" width="13.489999999999998%" headers="mcps1.2.4.1.1 "><p id="p78741540104813"><a name="p78741540104813"></a><a name="p78741540104813"></a>示例文件</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="68.52000000000001%" headers="mcps1.2.4.1.2 "><p id="p1066541692916"><a name="p1066541692916"></a><a name="p1066541692916"></a>/drivers/adapter/khdf/linux/platform/i2c/i2c_sample.c</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="17.990000000000002%" headers="mcps1.2.4.1.3 "><p id="p208891445144012"><a name="p208891445144012"></a><a name="p208891445144012"></a>新增文件</p>
</td>
</tr>
<tr id="row1388984594013"><td class="cellrowborder" align="left" valign="top" width="13.489999999999998%" headers="mcps1.2.4.1.1 "><p id="p88741840104811"><a name="p88741840104811"></a><a name="p88741840104811"></a>设备服务文件</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="68.52000000000001%" headers="mcps1.2.4.1.2 "><p id="p486417183298"><a name="p486417183298"></a><a name="p486417183298"></a>/drivers/adapter/khdf/linux/hcs/device_info/device_info.hcs</p>
</td>
<td class="cellrowborder" rowspan="3" align="left" valign="top" width="17.990000000000002%" headers="mcps1.2.4.1.3 "><p id="p128898458401"><a name="p128898458401"></a><a name="p128898458401"></a></p>
<p id="p168904455404"><a name="p168904455404"></a><a name="p168904455404"></a>追加内容</p>
<p id="p7890124516405"><a name="p7890124516405"></a><a name="p7890124516405"></a></p>
</td>
</tr>
<tr id="row9889164513406"><td class="cellrowborder" align="left" valign="top" headers="mcps1.2.4.1.1 "><p id="p138741640124812"><a name="p138741640124812"></a><a name="p138741640124812"></a>配置参数文件</p>
</td>
<td class="cellrowborder" align="left" valign="top" headers="mcps1.2.4.1.2 "><p id="p26905191293"><a name="p26905191293"></a><a name="p26905191293"></a>/drivers/adapter/khdf/linux/hcs/platform/i2c_config.hcs</p>
</td>
</tr>
<tr id="row1189044513404"><td class="cellrowborder" align="left" valign="top" headers="mcps1.2.4.1.1 "><p id="p1687424074814"><a name="p1687424074814"></a><a name="p1687424074814"></a>编译文件</p>
</td>
<td class="cellrowborder" align="left" valign="top" headers="mcps1.2.4.1.2 "><p id="p1885032192917"><a name="p1885032192917"></a><a name="p1885032192917"></a>/drivers/adapter/khdf/linux/platform/i2c/Makefile</p>
</td>
</tr>
<tr id="row10890144564011"><td class="cellrowborder" align="left" valign="top" width="13.489999999999998%" headers="mcps1.2.4.1.1 "><p id="p118752040104810"><a name="p118752040104810"></a><a name="p118752040104810"></a>依赖头文件</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="68.52000000000001%" headers="mcps1.2.4.1.2 "><p id="p15821718182916"><a name="p15821718182916"></a><a name="p15821718182916"></a>/drivers/framework/include/core/hdf_device_desc.h</p>
</td>
<td class="cellrowborder" rowspan="2" align="left" valign="top" width="17.990000000000002%" headers="mcps1.2.4.1.3 "><p id="p989012451401"><a name="p989012451401"></a><a name="p989012451401"></a>作为头文件引用</p>
<p id="p1890134594014"><a name="p1890134594014"></a><a name="p1890134594014"></a></p>
</td>
</tr>
<tr id="row6890164564015"><td class="cellrowborder" align="left" valign="top" headers="mcps1.2.4.1.1 "><p id="p128756401484"><a name="p128756401484"></a><a name="p128756401484"></a>核心层头文件</p>
</td>
<td class="cellrowborder" align="left" valign="top" headers="mcps1.2.4.1.2 "><p id="p47681122152918"><a name="p47681122152918"></a><a name="p47681122152918"></a>/drivers/framework/support/platform/include/i2c_core.h</p>
</td>
</tr>
<tr id="row1499682234817"><td class="cellrowborder" align="left" valign="top" width="13.489999999999998%" headers="mcps1.2.4.1.1 "><p id="p1187513403487"><a name="p1187513403487"></a><a name="p1187513403487"></a>HCS配置入口文件</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="68.52000000000001%" headers="mcps1.2.4.1.2 "><p id="p499818225487"><a name="p499818225487"></a><a name="p499818225487"></a>/drivers/adapter/khdf/linux/hcs/hdf.hcs</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="17.990000000000002%" headers="mcps1.2.4.1.3 "><p id="p3998152254820"><a name="p3998152254820"></a><a name="p3998152254820"></a>HCS配置文件总入口</p>
</td>
</tr>
</tbody>
</table>

>![](../public_sys-resources/icon-caution.gif) **注意：** 
>本例程涉及的文件路径均作为演示，驱动开发者应根据实际情况确定具体的源文件存放位置。

### 实例化驱动入口<a name="section85325864412"></a>

实例化一个HdfDriverEntry 对象作为驱动入口。驱动入口必须为HdfDriverEntry（在hdf\_device\_desc.h中定义）类型的全局变量，且moduleName要和device\_info.hcs中保持一致。在加载驱动时HDF框架会先调用Bind函数，再调用Init函数加载该驱动，当Init调用异常时，HDF框架会调用Release释放驱动资源并退出。

I2C驱动中没有实现Bind方法，因为I2C控制器由manager管理，而在manager中已经实现了Bind方法，因此I2C驱动中无需再绑定服务。

实例化驱动入口的示例代码如下：

```
/* 定义驱动入口的对象，必须为HdfDriverEntry（在hdf_device_desc.h中定义）类型的全局变量 */
struct HdfDriverEntry g_sampleI2cDriverEntry = {
    .moduleVersion = 1,
    .Init = SampleI2cInit,
    .Release = SampleI2cRelease,
    .moduleName = "demo_i2c_driver",
};
/* 调用HDF_INIT将驱动入口注册到HDF框架中 */
HDF_INIT(g_sampleI2cDriverEntry);
```

### 设置相关参数<a name="section8155172019453"></a>

通过配置device\_info.hcs，并从HCS获取并解析设备的配置参数以确保驱动能够正确加载。

1.  添加设备服务节点（必选）。

    编辑device\_info.hcs，在device\_i2c :: device下添加驱动设备服务节点，示例如下：

    ```
     root {
        device_info {
            match_attr = "hdf_manager";
                device_i2c :: device {                        // i2c设备节点
    		device2 :: deviceNode {                   // i2c驱动的DeviceNode节点
                        policy = 0;                           // policy字段是驱动服务发布的策略
                        priority = 55;                        // 驱动启动优先级
                        permission = 0644;                    // 驱动创建设备节点权限
                        moduleName = "demo_i2c_driver";       // 驱动名称，该字段的值必须和驱动入口结构的moduleName值一致
                        serviceName = "DEMO_I2C_DRIVER";      // 驱动对外发布服务的名称，必须唯一
                        deviceMatchAttr = "demo_i2c_config";  // 驱动私有数据匹配的关键字，必须和驱动私有数据配置表中的
                                                              // match_attr值相等
                    }
                }
        }
    }
    
    ```

    >![](../public_sys-resources/icon-notice.gif) **须知：** 
    >配置文件中的priority（取值范围为整数0到200）是用来表示host和驱动的优先级，不同的host内的驱动，host的priority值越小，驱动加载优先级越高；同一个host内驱动的priority值越小，加载优先级越高，驱动的priority值相同则不保证加载顺序。

2.  添加配置参数（可选）。

    有时驱动可能会需要私有配置信息，以确保寄存器的配置可以满足不同产品的需求。如需要私有配置信息，则可以添加一个驱动的配置文件，用来存放一些驱动的默认配置信息，HDF框架在加载驱动的时候，会将对应的配置信息获取并保存在HdfDeviceObject 中的property里面，通过Bind和Init（参考[驱动开发](../driver/driver-overview-foundation.md)）传递给驱动。驱动开发者可新建配置文件，并在板级驱动hdf.hcs中引用新建的配置文件，本例中直接在原有的配置文件i2c\_config.hcs内添加配置参数。

    本例中编辑i2c\_config.hcs，添加配置参数：

    ```
    root {
        platform {
                i2c_config_demo {                
                match_attr = "demo_i2c_config";        // 该字段的值必须和device_info.hcs中的deviceMatchAttr值一致
    
                template i2c_controller {              // 参数模板
                    bus = 0;
                    reg_pbase = 0x120b0000;
                    reg_size = 0xd1;
                }
    
                controller_demo_0 :: i2c_controller {  // 两个I2C示例控制器
                    bus = 8;
                }
                controller_demo_1 :: i2c_controller {
                    bus = 9;
                }
            }
        }
    }
    ```

    match\_attr字段必须与device\_info.hcs中的deviceMatch\_Attr保持一致，在此文件中配置驱动需要的参数，通过match\_attr可匹配至对应的驱动，该驱动即可在Bind或Init中调用DeviceResourceGetIfaceInstance\(\)函数获取这些配置参数。

    若配置文件为新文件，则需要在板级配置入口文件hdf.hcs中引用该配置文件，例如：

    ```
    #include "device_info/device_info.hcs"
    #include "i2c/i2c_config.hcs"
    ```

    由于本例中在原有的i2c\_config.hcs内添加配置参数，没有新建配置文件，因此无需再将i2c\_config.hcs添加至板级配置入口文件中。

3.  驱动从HCS获取配置参数。

    在本例中，驱动需要通过HCS获取寄存器物理基地址、寄存器大小、总线号等参数，从而对控制器进行正确配置。

    ```
    /* 从HCS获取配置参数 */
    static int32_t SampleI2cReadDrs(struct SampleI2cCntlr *sampleCntlr, const struct DeviceResourceNode *node)
    {
        int32_t ret;
        struct DeviceResourceIface *drsOps = NULL;
    
        drsOps = DeviceResourceGetIfaceInstance(HDF_CONFIG_SOURCE);
        if (drsOps == NULL || drsOps->GetUint32 == NULL) {                         // 确保GetUint32方法可用
            HDF_LOGE("%s: invalid drs ops fail!", __func__);
            return HDF_FAILURE;
        }
    
        ret = drsOps->GetUint32(node, "reg_pbase", &sampleCntlr->regBasePhy, 0);   // 从HCS读取物理基地址reg_pbase
        if (ret != HDF_SUCCESS) {
            HDF_LOGE("%s: read regBase fail!", __func__);
            return ret;
        }
    
        ret = drsOps->GetUint16(node, "reg_size", &sampleCntlr->regSize, 0);       // 从HCS读取寄存器大小reg_size
        if (ret != HDF_SUCCESS) {
            HDF_LOGE("%s: read regsize fail!", __func__);
            return ret;
        }
    
        ret = drsOps->GetUint16(node, "bus", (uint16_t *)&sampleCntlr->bus, 0);    // 从HCS读取总线号bus
        if (ret != HDF_SUCCESS) {
            HDF_LOGE("%s: read bus fail!", __func__);
            return ret;
        }
    
        return HDF_SUCCESS;
    }
    ```


### 添加控制器<a name="section1335374114452"></a>

初始化控制器硬件，并调用核心层接口完成向核心层添加、删除设备，以及钩子函数的实现等。

1.  定义结构体，实现钩子函数并赋值至函数指针。

    I2cMethod结构体在i2c\_core.h中定义，其中通过函数指针的方式定义了I2C需要实现的方法，transfer方法为用于传输的钩子函数，在驱动中需要做具体实现并对函数指针赋值。

    示例代码如下：

    ```
    /* 自定义设备结构体，继承父类I2cCntlr */
    struct SampleI2cCntlr {
        struct I2cCntlr cntlr;
        OsalSpinlock spin;
        volatile unsigned char  *regBase;
        uint16_t regSize;
        int16_t bus;
        uint32_t regBasePhy;
    };
    
    /* 消息结构体，继承父类I2cMsg */
    struct SampleTransferData {
        struct I2cMsg *msgs;
        int16_t index;
        int16_t count;
    };
    /* 钩子函数实现 */
    static int32_t SampleI2cTransfer(struct I2cCntlr *cntlr, struct I2cMsg *msgs, int16_t count)
    {
        int32_t ret = HDF_SUCCESS;
        struct SampleI2cCntlr *sampleCntlr = NULL;
        struct SampleTransferData td;
    
        if (cntlr == NULL || cntlr->priv == NULL) {
            HDF_LOGE("SampleI2cTransfer: cntlr lor sampleCntlr is null!");
            return HDF_ERR_INVALID_OBJECT;
        }
        sampleCntlr = (struct SampleI2cCntlr *)cntlr;
    
        if (msgs == NULL || count <= 0) {
            HDF_LOGE("SampleI2cTransfer: err parms! count:%d", count);
            return HDF_ERR_INVALID_PARAM;
        }
        td.msgs = msgs;
        td.count = count;
        td.index = 0;
    
        HDF_LOGE("Successfully transmitted!");  // 表示此处传输成功
          
        td.index = count;                       // 经过处理，最后实际发送msg个数等于count，返回已发送个数，此句代替已省略的处理过程
        return (td.index > 0) ? td.index : ret;
    }
    /* 钩子函数赋值 */
    static struct I2cMethod g_method = {
        .transfer = SampleI2cTransfer,
    };
    ```

2.  编写驱动初始化函数。

    本例中使用SampleI2cInit作为驱动初始化函数的函数名（函数名称可由驱动开发者确定），该函数需要在驱动入口结构体中赋值给Init，以供HDF驱动框架调用从而达到初始化驱动的目的。该函数中需要对从HCS获取的配置参数进行解析，并按照这些参数创建控制器。示例如下：

    ```
    /* 解析参数，申请内存并创建控制器 */
    static int32_t SampleI2cParseAndInit(struct HdfDeviceObject *device, const struct DeviceResourceNode *node)
    {
        int32_t ret;
        struct SampleI2cCntlr *sampleCntlr = NULL;
        (void)device;
    
        sampleCntlr = (struct SampleI2cCntlr *)OsalMemCalloc(sizeof(*sampleCntlr));
        if (sampleCntlr == NULL) {
            HDF_LOGE("%s: malloc sampleCntlr fail!", __func__);
            return HDF_ERR_MALLOC_FAIL;
        }
    
        ret = SampleI2cReadDrs(sampleCntlr, node);              // 从HCS获取配置参数
        if (ret != HDF_SUCCESS) {
            HDF_LOGE("%s: read drs fail! ret:%d", __func__, ret);
            goto __ERR__;
        }
    
        sampleCntlr->regBase = OsalIoRemap(sampleCntlr->regBasePhy, sampleCntlr->regSize);
        if (sampleCntlr->regBase == NULL) {
            HDF_LOGE("%s: ioremap regBase fail!", __func__);
            ret = HDF_ERR_IO;
            goto __ERR__;
        }
    
        HDF_LOGE("The controller has been initialized!");       // 表示此处省略的控制器初始化操作已经成功
    
        sampleCntlr->cntlr.priv = (void *)node;
        sampleCntlr->cntlr.busId = sampleCntlr->bus;
        sampleCntlr->cntlr.ops = &g_method;
        (void)OsalSpinInit(&sampleCntlr->spin);                 // 初始化自旋锁
        ret = I2cCntlrAdd(&sampleCntlr->cntlr);                 // 向核心层添加控制器
        if (ret != HDF_SUCCESS) {
            HDF_LOGE("%s: add i2c controller fail:%d!", __func__, ret);
            goto __ERR__;
        }
    
        return HDF_SUCCESS;
    __ERR__:                                                    // 错误处理
        if (sampleCntlr != NULL) {
            if (sampleCntlr->regBase != NULL) {
                OsalIoUnmap((void *)sampleCntlr->regBase);      // 取消地址映射
                sampleCntlr->regBase = NULL;
            }
            OsalMemFree(sampleCntlr);                           // 释放内存
            sampleCntlr = NULL;
        }
        return ret;
    }
    /* 驱动入口初始化函数 */
    static int32_t SampleI2cInit(struct HdfDeviceObject *device)
    {
        int32_t ret;
        const struct DeviceResourceNode *childNode = NULL;
    
        HDF_LOGE("%s: Enter", __func__);
        if (device == NULL || device->property == NULL) {
            HDF_LOGE("%s: device or property is NULL", __func__);
            return HDF_ERR_INVALID_OBJECT;
        }
    
        ret = HDF_SUCCESS;
        DEV_RES_NODE_FOR_EACH_CHILD_NODE(device->property, childNode) {
            ret = SampleI2cParseAndInit(device, childNode);    // 调用解析参数和创建控制器的函数
            if (ret != HDF_SUCCESS) {
                break;
            }
        }
        return ret;
    }
    ```

3.  编写驱动释放函数。

    本例中使用SampleI2cRelease作为驱动释放函数的函数名（函数名称可由驱动开发者确定），该函数需要在驱动入口结构体中赋值给Release，当HDF框架调用Init函数初始化驱动失败时，将调用Release释放驱动资源。该函数中需包含释放内存和删除控制器等操作。示例如下：

    ```
    /* 删除控制器函数 */
    static void SampleI2cRemoveByNode(const struct DeviceResourceNode *node)
    {
        int32_t ret;
        int16_t bus;
        struct I2cCntlr *cntlr = NULL;
        struct SampleI2cCntlr *sampleCntlr = NULL;
        struct DeviceResourceIface *drsOps = NULL;
    
        drsOps = DeviceResourceGetIfaceInstance(HDF_CONFIG_SOURCE);
        if (drsOps == NULL || drsOps->GetUint32 == NULL) {
            HDF_LOGE("%s: invalid drs ops fail!", __func__);
            return;
        }
    
        ret = drsOps->GetUint16(node, "bus", (uint16_t *)&bus, 0); // 从HCS获取I2C总线号
        if (ret != HDF_SUCCESS) {
            HDF_LOGE("%s: read bus fail!", __func__);
            return;
        }
    
        cntlr = I2cCntlrGet(bus);
        if (cntlr != NULL && cntlr->priv == node) {                // 根据I2C总线号删除控制器
            I2cCntlrPut(cntlr);
            I2cCntlrRemove(cntlr);
            sampleCntlr = (struct SampleI2cCntlr *)cntlr;
            OsalIoUnmap((void *)sampleCntlr->regBase);
            OsalMemFree(sampleCntlr);
        }
        return;
    }
    /* 释放资源 */
    static void SampleI2cRelease(struct HdfDeviceObject *device)
    {
        const struct DeviceResourceNode *childNode = NULL;
    
        HDF_LOGI("%s: enter", __func__);
    
        if (device == NULL || device->property == NULL) {
            HDF_LOGE("%s: device or property is NULL", __func__);
            return;
        }
    
        DEV_RES_NODE_FOR_EACH_CHILD_NODE(device->property, childNode) {
            SampleI2cRemoveByNode(childNode);                       // 调用删除控制器函数
        }
    }
    ```


## 编译及烧录<a name="section164824754712"></a>

1. 编辑Makefile，添加源文件：

   ```
   include drivers/hdf/khdf/platform/platform.mk
   
   obj-y  += $(HDF_PLATFORM_FRAMEWORKS_ROOT)/src/i2c_core.o \
             $(HDF_PLATFORM_FRAMEWORKS_ROOT)/src/i2c_if.o \
             ./i2c_adapter.o \
             ./i2c_sample.o
   ```

   "./i2c\_sample.o"为本示例中在Makefile中追加的内容。

2. 编译及烧录。

   - 安装包方式具体操作请参考标准系统快速入门[编译](../quick-start/quickstart-appendix-hi3516-pkg.md#编译)和[烧录](../quick-start/quickstart-appendix-hi3516-pkg.md#烧录)。

   - IDE方式具体操作请参考标准系统快速入门[编译](../quick-start/quickstart-appendix-hi3516-ide.md#编译)和[烧录](../quick-start/quickstart-appendix-hi3516-ide.md#烧录)。


