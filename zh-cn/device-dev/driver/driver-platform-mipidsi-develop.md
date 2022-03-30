# MIPI-DSI<a name="ZH-CN_TOPIC_0000001222082237"></a>

-   [概述](#section1266787503161538)
-   [接口说明](#section752964871810)
-   [开发步骤](#section545182932161538)
-   [开发实例](#section1167576616161538)

## 概述<a name="section1266787503161538"></a>

DSI（Display Serial Interface）是由移动行业处理器接口联盟（Mobile Industry Processor Interface \(MIPI\) Alliance）制定的规范。在HDF框架中，MIPI-DSI的接口适配模式采用无服务模式，用于不需要在用户态提供API的设备类型，或者没有用户态和内核区分的OS系统，其关联方式是DevHandle直接指向设备对象内核态地址（DevHandle是一个void类型指针）。

**图 1**  DSI无服务模式结构图<a name="fig207610236189"></a>  
![](figures/无服务模式结构图.png "DSI无服务模式结构图")

## 接口说明<a name="section752964871810"></a>

MipiDsiCntlrMethod定义：

```
struct MipiDsiCntlrMethod { // 核心层结构体的成员函数
    int32_t (*setCntlrCfg)(struct MipiDsiCntlr *cntlr);
    int32_t (*setCmd)(struct MipiDsiCntlr *cntlr, struct DsiCmdDesc *cmd);
    int32_t (*getCmd)(struct MipiDsiCntlr *cntlr, struct DsiCmdDesc *cmd, uint32_t readLen, uint8_t *out);
    void (*toHs)(struct MipiDsiCntlr *cntlr);
    void (*toLp)(struct MipiDsiCntlr *cntlr);
    void (*enterUlps)(struct MipiDsiCntlr *cntlr);//【可选】进入超低功耗模式
    void (*exitUlps)(struct MipiDsiCntlr *cntlr); //【可选】退出超低功耗模式
    int32_t (*powerControl)(struct MipiDsiCntlr *cntlr, uint8_t enable);//【可选】使能/去使能功耗控制
    int32_t (*attach)(struct MipiDsiCntlr *cntlr);//【可选】将一个DSI设备连接上host
};
```

**表 1**  MipiDsiCntlrMethod成员的回调函数功能说明

<a name="table49321701800"></a>
<table><thead align="left"><tr id="row129321407019"><th class="cellrowborder" valign="top" width="20%" id="mcps1.2.6.1.1"><p id="p1793219014017"><a name="p1793219014017"></a><a name="p1793219014017"></a>成员函数</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.2.6.1.2"><p id="p11932130705"><a name="p11932130705"></a><a name="p11932130705"></a>入参</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.2.6.1.3"><p id="p1493216019019"><a name="p1493216019019"></a><a name="p1493216019019"></a>出参</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.2.6.1.4"><p id="p12932400019"><a name="p12932400019"></a><a name="p12932400019"></a>返回状态</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.2.6.1.5"><p id="p89322010019"><a name="p89322010019"></a><a name="p89322010019"></a>功能</p>
</th>
</tr>
</thead>
<tbody><tr id="row093219016016"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p9932209019"><a name="p9932209019"></a><a name="p9932209019"></a>setCntlrCfg</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p199321001705"><a name="p199321001705"></a><a name="p199321001705"></a>cntlr: 结构体指针，MipiDsi控制器 ;</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p093210106"><a name="p093210106"></a><a name="p093210106"></a>无</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p16932701709"><a name="p16932701709"></a><a name="p16932701709"></a>HDF_STATUS相关状态</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p3932130702"><a name="p3932130702"></a><a name="p3932130702"></a>设置控制器参数</p>
</td>
</tr>
<tr id="row593211015010"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p169331101014"><a name="p169331101014"></a><a name="p169331101014"></a>setCmd</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p189338015011"><a name="p189338015011"></a><a name="p189338015011"></a>cntlr: 结构体指针，MipiDsi控制器 ;cmd: 结构体指针,指令传入值</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p493300204"><a name="p493300204"></a><a name="p493300204"></a>无</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p49332011019"><a name="p49332011019"></a><a name="p49332011019"></a>HDF_STATUS相关状态</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p17933801808"><a name="p17933801808"></a><a name="p17933801808"></a>向显示设备发送指令</p>
</td>
</tr>
<tr id="row793312013010"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p13933120708"><a name="p13933120708"></a><a name="p13933120708"></a>getCmd</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p199331906010"><a name="p199331906010"></a><a name="p199331906010"></a>cntlr：结构体指针，MipiDsi控制器；</br>cmd：传入的命令描述结构体指针；</br>readLen：读取的数据大小；</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p139331001602"><a name="p139331001602"></a><a name="p139331001602"></a>out：结构体指针，用于存储读取的数据。</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p993390900"><a name="p993390900"></a><a name="p993390900"></a>HDF_STATUS相关状态</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p1933901007"><a name="p1933901007"></a><a name="p1933901007"></a>从显示设备读取信息指令</p>
</td>
</tr>
<tr id="row10933004013"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p493311019014"><a name="p493311019014"></a><a name="p493311019014"></a>toHs</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p189330016013"><a name="p189330016013"></a><a name="p189330016013"></a>cntlr: 结构体指针，MipiDsi控制器 ;</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p149338013010"><a name="p149338013010"></a><a name="p149338013010"></a>无</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p2933309015"><a name="p2933309015"></a><a name="p2933309015"></a>HDF_STATUS相关状态</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p8933709019"><a name="p8933709019"></a><a name="p8933709019"></a>设置为高速模式</p>
</td>
</tr>
<tr id="row99331502001"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p993311018016"><a name="p993311018016"></a><a name="p993311018016"></a>toLp</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p79337011013"><a name="p79337011013"></a><a name="p79337011013"></a>cntlr: 结构体指针，MipiDsi控制器 ;</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p169331301201"><a name="p169331301201"></a><a name="p169331301201"></a>无</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p39331407020"><a name="p39331407020"></a><a name="p39331407020"></a>HDF_STATUS相关状态</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p19933190507"><a name="p19933190507"></a><a name="p19933190507"></a>设置为低电模式</p>
</td>
</tr>
</tbody>
</table>

## 开发步骤<a name="section545182932161538"></a>

MIPI-DSI模块适配的三个环节是配置属性文件，实例化驱动入口，以及实例化核心层接口函数。

1.  **实例化驱动入口：**
    -   实例化HdfDriverEntry结构体成员。
    -   调用HDF\_INIT将HdfDriverEntry实例化对象注册到HDF框架中。

2.  **配置属性文件：**
    -   在device\_info.hcs文件中添加deviceNode描述。
    -   【可选】添加mipidsi\_config.hcs器件属性文件。

3.  **实例化MIPIDSI控制器对象：**
    -   初始化MipiDsiCntlr成员。
    -   实例化MipiDsiCntlr成员MipiDsiCntlrMethod。

        >![](../public_sys-resources/icon-note.gif) **说明：** 
        >实例化MipiDsiCntlr成员MipiDsiCntlrMethod，其定义和成员说明见[接口说明](#section752964871810)。


4.  **驱动调试：**

    【可选】针对新增驱动程序，建议验证驱动基本功能，例如挂载后的信息反馈，数据传输的成功与否等。


## 开发实例<a name="section1167576616161538"></a>

下方将以mipi\_tx\_hi35xx.c为示例，展示需要厂商提供哪些内容来完整实现设备功能。

1.  一般来说，驱动开发首先需要在 xx\_config.hcs 中配置器件属性，并在device\_info.hcs文件中添加deviceNode描述。器件属性值与核心层MipiDsiCntlr 成员的默认值或限制范围有密切关系，deviceNode信息与驱动入口注册相关。

    但本例中MIPI控制器无需配置额外属性，如有厂商需要，则需要在device\_info文件的deviceNode增加deviceMatchAttr信息，以及增加mipidsi\_config文件。

    device\_info.hcs 配置参考：

    ```
    root {
    device_info {
        match_attr = "hdf_manager";
        platform :: host {
        hostName = "platform_host";
        priority = 50;
        device_mipi_dsi:: device {
            device0 :: deviceNode {
            policy = 0;
            priority = 150;
            permission = 0644;
            moduleName = "HDF_MIPI_TX";   //【必要】用于指定驱动名称，需要与期望的驱动Entry中的moduleName一致；
            serviceName = "HDF_MIPI_TX";  // 【必要且唯一】驱动对外发布服务的名称
            }
        }
        }
    }
    }
    ```

2.  完成器件属性文件的配置之后，下一步请实例化驱动入口，驱动入口必须为HdfDriverEntry（在 hdf\_device\_desc.h 中定义）类型的全局变量，且moduleName要和device\_info.hcs中保持一致。HdfDriverEntry结构体的函数指针成员会被厂商操作函数填充，HDF框架会将所有加载的驱动的HdfDriverEntry对象首地址汇总，形成一个类似数组，方便调用。

    一般在加载驱动时HDF框架会先调用Bind函数，再调用Init函数加载该驱动。当Init调用异常时，HDF框架会调用Release释放驱动资源并退出。

    -   MIPI-DSI驱动入口参考。

        ```
        struct HdfDriverEntry g_mipiTxDriverEntry = {
            .moduleVersion = 1,             
            .Init = Hi35xxMipiTxInit,      //见Init参考
            .Release = Hi35xxMipiTxRelease,//见Release参考
            .moduleName = "HDF_MIPI_TX",   //【必要】需要与device_info.hcs 中保持一致。
        };
        HDF_INIT(g_mipiTxDriverEntry);     //调用HDF_INIT将驱动入口注册到HDF框架中
        ```

3.  完成驱动入口注册之后，最后一步就是以核心层MipiDsiCntlr对象的初始化为核心，包括厂商自定义结构体（传递参数和数据），实例化MipiDsiCntlr成员MipiDsiCntlrMethod（让用户可以通过接口来调用驱动底层函数），实现HdfDriverEntry成员函数（Bind，Init，Release）。
    -   自定义结构体参考。

        从驱动的角度看，自定义结构体是参数和数据的载体，一般来说，config文件中的数值也会用来初始化结构体成员，但本例的mipidsi无器件属性文件，故基本成员结构与MipiDsiCntlr无太大差异。

        ```
        typedef struct {
          unsigned int    devno;                // 设备号
          short           laneId[LANE_MAX_NUM]; // lane号
          OutPutModeTag   outputMode;           // 输出模式选择:刷新模式，命令行模式和视频流模式 
          VideoModeTag    videoMode;            // 显示设备的同步模式
          OutputFormatTag outputFormat;         // 输出DSI图像数据格式:RGB or YUV
          SyncInfoTag     syncInfo;             // 时序相关的设置
          unsigned int    phyDataRate;          // mbps 
          unsigned int    pixelClk;             // KHz
        } ComboDevCfgTag;
        
        // MipiDsiCntlr是核心层控制器结构体，其中的成员在Init函数中会被赋值
        struct MipiDsiCntlr {
          struct IDeviceIoService service;
          struct HdfDeviceObject *device;
          unsigned int devNo;          // 设备号
          struct MipiCfg cfg;
          struct MipiDsiCntlrMethod *ops;
          struct OsalMutex  lock;
          void *priv;
        };
        ```

    -   MipiDsiCntlr成员回调函数结构体MipiDsiCntlrMethod的实例化，其他成员在Init函数中初始化。

        ```
        static struct MipiDsiCntlrMethod g_method = {
            .setCntlrCfg = Hi35xxSetCntlrCfg,
            .setCmd = Hi35xxSetCmd,
            .getCmd = Hi35xxGetCmd,
            .toHs = Hi35xxToHs,
            .toLp = Hi35xxToLp,
        };
        ```

    -   Init函数参考

        入参：

        HdfDeviceObject 是整个驱动对外暴露的接口参数，具备 HCS 配置文件的信息。

        返回值：

        HDF\_STATUS相关状态 （下表为部分展示，如需使用其他状态，可见//drivers/framework/include/utils/hdf\_base.h中HDF\_STATUS 定义）。

        <a name="table344041707161538"></a>
        <table><thead align="left"><tr id="row1205250994161538"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="entry1646623665161538p0"><a name="entry1646623665161538p0"></a><a name="entry1646623665161538p0"></a>状态(值)</p>
        </th>
        <th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="entry36551796161538p0"><a name="entry36551796161538p0"></a><a name="entry36551796161538p0"></a>问题描述</p>
        </th>
        </tr>
        </thead>
        <tbody><tr id="row1245832689161538"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry635453137161538p0"><a name="entry635453137161538p0"></a><a name="entry635453137161538p0"></a>HDF_ERR_INVALID_OBJECT</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1681554112161538p0"><a name="entry1681554112161538p0"></a><a name="entry1681554112161538p0"></a>无效对象</p>
        </td>
        </tr>
        <tr id="row86233502161538"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2128705324161538p0"><a name="entry2128705324161538p0"></a><a name="entry2128705324161538p0"></a>HDF_ERR_MALLOC_FAIL</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1664050443161538p0"><a name="entry1664050443161538p0"></a><a name="entry1664050443161538p0"></a>内存分配失败</p>
        </td>
        </tr>
        <tr id="row230078441161538"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry325107899161538p0"><a name="entry325107899161538p0"></a><a name="entry325107899161538p0"></a>HDF_ERR_INVALID_PARAM</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry754791216161538p0"><a name="entry754791216161538p0"></a><a name="entry754791216161538p0"></a>无效参数</p>
        </td>
        </tr>
        <tr id="row20758403161538"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1970333605161538p0"><a name="entry1970333605161538p0"></a><a name="entry1970333605161538p0"></a>HDF_ERR_IO</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1122658595161538p0"><a name="entry1122658595161538p0"></a><a name="entry1122658595161538p0"></a>I/O 错误</p>
        </td>
        </tr>
        <tr id="row1425117417161538"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1844298129161538p0"><a name="entry1844298129161538p0"></a><a name="entry1844298129161538p0"></a>HDF_SUCCESS</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry712326009161538p0"><a name="entry712326009161538p0"></a><a name="entry712326009161538p0"></a>执行成功</p>
        </td>
        </tr>
        <tr id="row1899574933161538"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1964112434161538p0"><a name="entry1964112434161538p0"></a><a name="entry1964112434161538p0"></a>HDF_FAILURE</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1481231483161538p0"><a name="entry1481231483161538p0"></a><a name="entry1481231483161538p0"></a>执行失败</p>
        </td>
        </tr>
        </tbody>
        </table>

        函数说明：

        MipiDsiCntlrMethod的实例化对象的挂载，调用MipiDsiRegisterCntlr，以及其他厂商自定义初始化操作。

        ```
        static int32_t Hi35xxMipiTxInit(struct HdfDeviceObject *device)
        {
        int32_t ret;
        g_mipiTx.priv = NULL;    //g_mipiTx是定义的全局变量
                                //static struct MipiDsiCntlr g_mipiTx { 
                                //     .devNo=0
                                //};
        g_mipiTx.ops = &g_method;//MipiDsiCntlrMethod的实例化对象的挂载
        ret = MipiDsiRegisterCntlr(&g_mipiTx, device);//【必要】调用核心层函数和g_mipiTx初始化核心层全局变量
        ...
        return MipiTxDrvInit(0); //【必要】厂商对设备的初始化，形式不限
        }
        
        //mipi_dsi_core.c核心层
        int32_t MipiDsiRegisterCntlr(struct MipiDsiCntlr *cntlr, struct HdfDeviceObject *device)
        {
        ...
        //定义的全局变量:static struct MipiDsiHandle g_mipiDsihandle[MAX_CNTLR_CNT];
        if (g_mipiDsihandle[cntlr->devNo].cntlr == NULL) {
            (void)OsalMutexInit(&g_mipiDsihandle[cntlr->devNo].lock);
            (void)OsalMutexInit(&(cntlr->lock));
        
            g_mipiDsihandle[cntlr->devNo].cntlr = cntlr;//初始化MipiDsiHandle成员
            g_mipiDsihandle[cntlr->devNo].priv = NULL;  
            cntlr->device = device;                     //使HdfDeviceObject与MipiDsiHandle可以相互转化的前提
            device->service = &(cntlr->service);        //使HdfDeviceObject与MipiDsiHandle可以相互转化的前提
            cntlr->priv = NULL;    
            ...
            return HDF_SUCCESS;
        }
        ...
        return HDF_FAILURE;
        }
        ```

    -   Release函数参考

        入参：

        HdfDeviceObject 是整个驱动对外暴露的接口参数，具备 HCS 配置文件的信息。

        返回值：

        无。

        函数说明：

        该函数需要在驱动入口结构体中赋值给 Release 接口， 当 HDF 框架调用 Init 函数初始化驱动失败时，可以调用 Release 释放驱动资源， 该函数中需包含释放内存和删除控制器等操作。所有强制转换获取相应对象的操作前提是在Init函数中具备对应赋值的操作。

        ```
        static void Hi35xxMipiTxRelease(struct HdfDeviceObject *device)
        {
        struct MipiDsiCntlr *cntlr = NULL;
        ...
        cntlr = MipiDsiCntlrFromDevice(device);//这里有HdfDeviceObject到MipiDsiCntlr的强制转化
                                                //return (device == NULL) ? NULL : (struct MipiDsiCntlr *)device->service;
        ...
        MipiTxDrvExit();                       //【必要】对厂商设备所占资源的释放
        MipiDsiUnregisterCntlr(&g_mipiTx);     //空函数
        g_mipiTx.priv = NULL;
        HDF_LOGI("%s: unload mipi_tx driver 1212!", __func__);
        } 
        ```



