# SPI<a name="ZH-CN_TOPIC_0000001222282191"></a>

-   [概述](#section84922229152909)
-   [接口说明](#section752964871810)
-   [开发步骤](#section799667984152909)
-   [开发实例](#section956157227152909)

## 概述<a name="section84922229152909"></a>

SPI是串行外设接口（Serial Peripheral Interface）的缩写，在HDF框架中，SPI的接口适配模式采用独立服务模式，在这种模式下，每一个设备对象会独立发布一个设备服务来处理外部访问，设备管理器收到API的访问请求之后，通过提取该请求的参数，达到调用实际设备对象的相应内部方法的目的。独立服务模式可以直接借助HDFDeviceManager的服务管理能力，但需要为每个设备单独配置设备节点，增加内存占用。

**图 1**  SPI独立服务模式结构图<a name="fig666465313303"></a>  
![](figures/SPI独立服务模式结构图.png "SPI独立服务模式结构图")

## 接口说明<a name="section752964871810"></a>

SpiCntlrMethod定义：

```
struct SpiCntlrMethod {
  int32_t (*GetCfg)(struct SpiCntlr *cntlr, struct SpiCfg *cfg);
  int32_t (*SetCfg)(struct SpiCntlr *cntlr, struct SpiCfg *cfg);
  int32_t (*Transfer)(struct SpiCntlr *cntlr, struct SpiMsg *msg, uint32_t count);
  int32_t (*Open)(struct SpiCntlr *cntlr);
  int32_t (*Close)(struct SpiCntlr *cntlr);
};
```

**表 1**  SpiCntlrMethod结构体成员的回调函数功能说明

<a name="table7167123615321"></a>
<table><thead align="left"><tr id="row816783615326"><th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.1"><p id="p8167193643218"><a name="p8167193643218"></a><a name="p8167193643218"></a>成员函数</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.2"><p id="p31672362325"><a name="p31672362325"></a><a name="p31672362325"></a>入参</p>
</th>
<th class="cellrowborder" valign="top" width="24.98%" id="mcps1.2.5.1.3"><p id="p51673367328"><a name="p51673367328"></a><a name="p51673367328"></a>返回值</p>
</th>
<th class="cellrowborder" valign="top" width="25.019999999999996%" id="mcps1.2.5.1.4"><p id="p1116883619322"><a name="p1116883619322"></a><a name="p1116883619322"></a>功能</p>
</th>
</tr>
</thead>
<tbody><tr id="row816883693214"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p11683369329"><a name="p11683369329"></a><a name="p11683369329"></a>Transfer</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p6168736173213"><a name="p6168736173213"></a><a name="p6168736173213"></a>cntlr：结构体指针，核心层spi控制器；</br>msg：结构体指针，Spi消息；</br>count：uint32_t，消息个数；</p>
</td>
<td class="cellrowborder" valign="top" width="24.98%" headers="mcps1.2.5.1.3 "><p id="p19168736113216"><a name="p19168736113216"></a><a name="p19168736113216"></a>HDF_STATUS相关状态</p>
</td>
<td class="cellrowborder" valign="top" width="25.019999999999996%" headers="mcps1.2.5.1.4 "><p id="p18168236143218"><a name="p18168236143218"></a><a name="p18168236143218"></a>传输消息</p>
</td>
</tr>
<tr id="row3168113633211"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p4168636193212"><a name="p4168636193212"></a><a name="p4168636193212"></a>SetCfg</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p11168163643217"><a name="p11168163643217"></a><a name="p11168163643217"></a>cntlr；结构体指针，核心层spi控制器；</br>cfg：结构体指针，Spi属性；</p>
</td>
<td class="cellrowborder" valign="top" width="24.98%" headers="mcps1.2.5.1.3 "><p id="p101683367325"><a name="p101683367325"></a><a name="p101683367325"></a>HDF_STATUS相关状态</p>
</td>
<td class="cellrowborder" valign="top" width="25.019999999999996%" headers="mcps1.2.5.1.4 "><p id="p1216815368329"><a name="p1216815368329"></a><a name="p1216815368329"></a>设置控制器属性</p>
</td>
</tr>
<tr id="row13168183683215"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p11168436123220"><a name="p11168436123220"></a><a name="p11168436123220"></a>GetCfg</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p3168936133218"><a name="p3168936133218"></a><a name="p3168936133218"></a>cntlr：结构体指针，核心层spi控制器；</br>cfg：结构体指针，Spi属性；</p>
</td>
<td class="cellrowborder" valign="top" width="24.98%" headers="mcps1.2.5.1.3 "><p id="p18169036193219"><a name="p18169036193219"></a><a name="p18169036193219"></a>HDF_STATUS相关状态</p>
</td>
<td class="cellrowborder" valign="top" width="25.019999999999996%" headers="mcps1.2.5.1.4 "><p id="p3169136173219"><a name="p3169136173219"></a><a name="p3169136173219"></a>获取控制器属性</p>
</td>
</tr>
<tr id="row9169133643218"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p13169163615320"><a name="p13169163615320"></a><a name="p13169163615320"></a>Open</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p181697365327"><a name="p181697365327"></a><a name="p181697365327"></a>cntlr：结构体指针，核心层spi控制器；</p>
</td>
<td class="cellrowborder" valign="top" width="24.98%" headers="mcps1.2.5.1.3 "><p id="p1169163693216"><a name="p1169163693216"></a><a name="p1169163693216"></a>HDF_STATUS相关状态</p>
</td>
<td class="cellrowborder" valign="top" width="25.019999999999996%" headers="mcps1.2.5.1.4 "><p id="p1116963693218"><a name="p1116963693218"></a><a name="p1116963693218"></a>打开SPI</p>
</td>
</tr>
<tr id="row11169436153214"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p0169736153219"><a name="p0169736153219"></a><a name="p0169736153219"></a>Close</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p31691936193210"><a name="p31691936193210"></a><a name="p31691936193210"></a>cntlr：结构体指针，核心层spi控制器；</p>
</td>
<td class="cellrowborder" valign="top" width="24.98%" headers="mcps1.2.5.1.3 "><p id="p2169123617322"><a name="p2169123617322"></a><a name="p2169123617322"></a>HDF_STATUS相关状态</p>
</td>
<td class="cellrowborder" valign="top" width="25.019999999999996%" headers="mcps1.2.5.1.4 "><p id="p1169636103220"><a name="p1169636103220"></a><a name="p1169636103220"></a>关闭SPI</p>
</td>
</tr>
</tbody>
</table>

## 开发步骤<a name="section799667984152909"></a>

SPI模块适配HDF框架的三个环节是配置属性文件，实例化驱动入口，以及实例化核心层接口函数。

1.  **实例化驱动入口：**
    -   实例化HdfDriverEntry结构体成员。
    -   调用HDF\_INIT将HdfDriverEntry实例化对象注册到HDF框架中。

2.  **配置属性文件：**
    -   在device\_info.hcs文件中添加deviceNode描述。
    -   【可选】添加spi\_config.hcs器件属性文件。

3.  **实例化SPI控制器对象：**
    -   初始化SpiCntlr成员。
    -   实例化SpiCntlr成员SpiCntlrMethod。

        >![](../public_sys-resources/icon-note.gif) **说明：** 
        >实例化SpiCntlr成员SpiCntlrMethod，其定义和成员说明见[接口说明](#section752964871810)。


4.  **驱动调试：**

    【可选】针对新增驱动程序，建议验证驱动基本功能，例如spi控制状态，中断响应情况等。


## 开发实例<a name="section956157227152909"></a>

下方将以spi\_hi35xx.c为示例，展示需要厂商提供哪些内容来完整实现设备功能。

1.  驱动开发首先需要实例化驱动入口，驱动入口必须为HdfDriverEntry（在 hdf\_device\_desc.h 中定义）类型的全局变量，且moduleName要和device\_info.hcs中保持一致。HDF框架会将所有加载的驱动的HdfDriverEntry对象首地址汇总，形成一个类似数组的段地址空间，方便上层调用。

    一般在加载驱动时HDF会先调用Bind函数，再调用Init函数加载该驱动。当Init调用异常时，HDF框架会调用Release释放驱动资源并退出。

    SPI驱动入口参考：

    ```
    struct HdfDriverEntry g_hdfSpiDevice = {
        .moduleVersion = 1,
        .moduleName = "HDF_PLATFORM_SPI",//【必要 且与 HCS文件中里面的moduleName匹配】
        .Bind = HdfSpiDeviceBind,        //见Bind参考
        .Init = HdfSpiDeviceInit,        //见Init参考
        .Release = HdfSpiDeviceRelease,  //见Release参考
    };
    //调用HDF_INIT将驱动入口注册到HDF框架中
    HDF_INIT(g_hdfSpiDevice);
    ```

2.  完成驱动入口注册之后，下一步请在device\_info.hcs文件中添加deviceNode信息，并在 spi\_config.hcs 中配置器件属性。deviceNode信息与驱动入口注册相关，器件属性值与核心层SpiCntlr 成员的默认值或限制范围有密切关系。

    本例只有一个SPI控制器，如有多个器件信息，则需要在device\_info文件增加deviceNode信息，以及在spi\_config文件中增加对应的器件属性。

    -   device\_info.hcs 配置参考。

        ```
        root {
        device_info {
            match_attr = "hdf_manager";
            platform :: host {
            hostName = "platform_host";
            priority = 50;
            device_spi :: device {        //为每一个 SPI 控制器配置一个HDF设备节点
                device0 :: deviceNode {
                policy = 1;
                priority = 60;
                permission = 0644;
                moduleName = "HDF_PLATFORM_SPI";
                serviceName = "HDF_PLATFORM_SPI_0";
                deviceMatchAttr = "hisilicon_hi35xx_spi_0";
                }
                device1 :: deviceNode {
                policy = 1;
                priority = 60;
                permission = 0644;
                moduleName = "HDF_PLATFORM_SPI";             // 【必要】用于指定驱动名称，该字段的值必须和驱动入口结构的moduleName值一致
                serviceName = "HDF_PLATFORM_SPI_1";         // 【必要且唯一】驱动对外发布服务的名称
                deviceMatchAttr = "hisilicon_hi35xx_spi_1";// 需要与设备hcs文件中的 match_attr 匹配
                }
                ...
            }
            }
        }
        }
        ```

    -   spi\_config.hcs 配置参考。

        ```
        root {
        platform {
            spi_config {//每一个SPI控制器配置私有数据
            template spi_controller {//模板公共参数， 继承该模板的节点如果使用模板中的默认值， 则节点字段可以缺省
                serviceName = "";
                match_attr = "";
                transferMode = 0;     // 数据传输模式：中断传输(0),流控传输(1),DMA传输(2)
                busNum = 0;           // 总线号
                clkRate = 100000000;
                bitsPerWord = 8;      // 传输位宽
                mode = 19;            // SPI 数据的输入输出模式
                maxSpeedHz = 0;       // 最大时钟频率
                minSpeedHz = 0;       // 最小时钟频率
                speed = 2000000;      // 当前消息传输速度
                fifoSize = 256;       // FIFO大小
                numCs = 1;            // 片选号
                regBase = 0x120c0000; // 地址映射需要
                irqNum = 100;         // 中断号
                REG_CRG_SPI = 0x120100e4;       // CRG_REG_BASE(0x12010000) + 0x0e4
                CRG_SPI_CKEN = 0;
                CRG_SPI_RST = 0;
                REG_MISC_CTRL_SPI = 0x12030024; // MISC_REG_BASE(0x12030000) + 0x24
                MISC_CTRL_SPI_CS = 0;
                MISC_CTRL_SPI_CS_SHIFT = 0;
            }      
            controller_0x120c0000 :: spi_controller {
                busNum = 0;                //【必要】总线号
                CRG_SPI_CKEN = 0x10000;    // (0x1 << 16) 0:close clk, 1:open clk 
                CRG_SPI_RST = 0x1;         // (0x1 << 0) 0:cancel reset, 1:reset 
                match_attr = "hisilicon_hi35xx_spi_0";//【必要】需要和device_info.hcs中的deviceMatchAttr值一致
            }      
            controller_0x120c1000 :: spi_controller {
                busNum = 1;
                CRG_SPI_CKEN = 0x20000;    // (0x1 << 17) 0:close clk, 1:open clk
                CRG_SPI_RST = 0x2;         // (0x1 << 1) 0:cancel reset, 1:reset 
                match_attr = "hisilicon_hi35xx_spi_1"; 
                regBase = 0x120c1000;      //【必要】地址映射需要
                irqNum = 101;              //【必要】中断号
            }
            ...
            // 【可选】可新增，但需要在 device_info.hcs 添加对应的节点
            }
        }
        }
        ```

3.  完成驱动入口注册之后，最后一步就是以核心层SpiCntlr对象的初始化为核心，包括厂商自定义结构体（传递参数和数据），实例化SpiCntlr成员SpiCntlrMethod（让用户可以通过接口来调用驱动底层函数），实现HdfDriverEntry成员函数（Bind，Init，Release）。
    -   自定义结构体参考。

        从驱动的角度看，自定义结构体是参数和数据的载体，而且spi\_config.hcs文件中的数值会被HDF读入通过DeviceResourceIface来初始化结构体成员，一些重要数值也会传递给核心层对象，例如设备号、总线号等。

        ```
        struct Pl022 {//对应于hcs中的参数
            struct SpiCntlr *cntlr;
            struct DListHead deviceList;
            struct OsalSem sem;
            volatile unsigned char *phyBase;
            volatile unsigned char *regBase;
            uint32_t irqNum;
            uint32_t busNum;
            uint32_t numCs;
            uint32_t curCs;
            uint32_t speed;
            uint32_t fifoSize;
            uint32_t clkRate;
            uint32_t maxSpeedHz;
            uint32_t minSpeedHz;
            uint32_t regCrg;
            uint32_t clkEnBit;
            uint32_t clkRstBit;
            uint32_t regMiscCtrl;
            uint32_t miscCtrlCsShift;
            uint32_t miscCtrlCs;
            uint16_t mode;
            uint8_t bitsPerWord;
            uint8_t transferMode;
        };
        
        //SpiCntlr是核心层控制器结构体，其中的成员在Init函数中会被赋值
        struct SpiCntlr {
            struct IDeviceIoService service;
            struct HdfDeviceObject *device;
            uint32_t busNum;
            uint32_t numCs;
            uint32_t curCs;
            struct OsalMutex lock;
            struct SpiCntlrMethod *method;
            struct DListHead list;
            void *priv;
        };
        ```

    -   SpiCntlr成员回调函数结构体SpiCntlrMethod的实例化，其他成员在Init函数中初始化。

        ```
        // spi_hi35xx.c 中的示例：钩子函数的实例化
        struct SpiCntlrMethod g_method = {
            .Transfer = Pl022Transfer,
            .SetCfg = Pl022SetCfg,
            .GetCfg = Pl022GetCfg,
            .Open = Pl022Open,
            .Close = Pl022Close,
        };
        ```

    -   Bind 函数参考

        入参：

        HdfDeviceObject 是整个驱动对外暴露的接口参数，具备 HCS 配置文件的信息。

        返回值：

        HDF\_STATUS相关状态。

        函数说明：

        将 SpiCntlr 对象同 HdfDeviceObject 进行了关联。

        ```
        static int32_t HdfSpiDeviceBind(struct HdfDeviceObject *device)
        {
            ...
            return (SpiCntlrCreate(device) == NULL) ? HDF_FAILURE : HDF_SUCCESS;
        }
        
        struct SpiCntlr *SpiCntlrCreate(struct HdfDeviceObject *device)
        {
            struct SpiCntlr *cntlr = NULL;      //创建核心层 SpiCntlr 对象
            ...
            cntlr = (struct SpiCntlr *)OsalMemCalloc(sizeof(*cntlr));//分配内存
            ...
            cntlr->device = device;             //使HdfDeviceObject与SpiCntlr可以相互转化的前提
            device->service = &(cntlr->service);//使HdfDeviceObject与SpiCntlr可以相互转化的前提
            (void)OsalMutexInit(&cntlr->lock);  //锁初始化
            DListHeadInit(&cntlr->list);        //添加对应的节点
            cntlr->priv = NULL;
            return cntlr;
        }
        ```

    -   Init函数参考

        入参：

        HdfDeviceObject 是整个驱动对外暴露的接口参数，具备 HCS 配置文件的信息。

        返回值：

        HDF\_STATUS相关状态 （下表为部分展示，如需使用其他状态，可见/drivers/framework/include/utils/hdf\_base.h中HDF\_STATUS 定义）。

        **表 2**  init函数入参和返回值

        <a name="table4311552173914"></a>
        <table><thead align="left"><tr id="row8314152103916"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p331413523392"><a name="p331413523392"></a><a name="p331413523392"></a>状态(值)</p>
        </th>
        <th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p7314145220390"><a name="p7314145220390"></a><a name="p7314145220390"></a>问题描述</p>
        </th>
        </tr>
        </thead>
        <tbody><tr id="row93142052183918"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p93141252123914"><a name="p93141252123914"></a><a name="p93141252123914"></a>HDF_ERR_INVALID_OBJECT</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p331485215390"><a name="p331485215390"></a><a name="p331485215390"></a>控制器对象非法</p>
        </td>
        </tr>
        <tr id="row331445211399"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p83141352183917"><a name="p83141352183917"></a><a name="p83141352183917"></a>HDF_ERR_MALLOC_FAIL</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p15314175220397"><a name="p15314175220397"></a><a name="p15314175220397"></a>内存分配失败</p>
        </td>
        </tr>
        <tr id="row20314175213918"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p9314352113917"><a name="p9314352113917"></a><a name="p9314352113917"></a>HDF_ERR_INVALID_PARAM</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p131535273910"><a name="p131535273910"></a><a name="p131535273910"></a>参数非法</p>
        </td>
        </tr>
        <tr id="row1431565233911"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p0315052103915"><a name="p0315052103915"></a><a name="p0315052103915"></a>HDF_ERR_IO</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1831585215398"><a name="p1831585215398"></a><a name="p1831585215398"></a>I/O 错误</p>
        </td>
        </tr>
        <tr id="row2315152193914"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p7315185263919"><a name="p7315185263919"></a><a name="p7315185263919"></a>HDF_SUCCESS</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1731585213910"><a name="p1731585213910"></a><a name="p1731585213910"></a>初始化成功</p>
        </td>
        </tr>
        <tr id="row5315752163916"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p6315105211392"><a name="p6315105211392"></a><a name="p6315105211392"></a>HDF_FAILURE</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p83157528399"><a name="p83157528399"></a><a name="p83157528399"></a>初始化失败</p>
        </td>
        </tr>
        </tbody>
        </table>

        函数说明：

        初始化自定义结构体对象，初始化SpiCntlr成员。

        ```
        static int32_t HdfSpiDeviceInit(struct HdfDeviceObject *device)
        {
        int32_t ret;
        struct SpiCntlr *cntlr = NULL;
        ...
        cntlr = SpiCntlrFromDevice(device);//这里有HdfDeviceObject到SpiCntlr的强制转化，通过service成员，赋值见Bind函数
                                            //return (device == NULL) ? NULL : (struct SpiCntlr *)device->service;
        ...
        ret = Pl022Init(cntlr, device);//【必要】实例化厂商自定义操作对象，示例见下
        ...
        ret = Pl022Probe(cntlr->priv);
        ...
        return ret;
        }
        
        static int32_t Pl022Init(struct SpiCntlr *cntlr, const struct HdfDeviceObject *device)
        {
        int32_t ret;
        struct Pl022 *pl022 = NULL;
        ...
        pl022 = (struct Pl022 *)OsalMemCalloc(sizeof(*pl022));//申请内存
        ...
        ret = SpiGetBaseCfgFromHcs(pl022, device->property);  //初始化busNum, numCs, speed, fifoSize, clkRate,mode, bitsPerWord, transferMode参数值
        ...
        ret = SpiGetRegCfgFromHcs(pl022, device->property);   //初始化regBase, phyBase, irqNum, regCrg, clkEnBit,clkRstBit, regMiscCtrl, regMiscCtrl, miscCtrlCs,miscCtrlCsShift参数值
        ...
        //计算最大,最小速度对应的频率
        pl022->maxSpeedHz = (pl022->clkRate) / ((SCR_MIN + 1) * CPSDVSR_MIN);
        pl022->minSpeedHz = (pl022->clkRate) / ((SCR_MAX + 1) * CPSDVSR_MAX);
        DListHeadInit(&pl022->deviceList);//初始化DList链表
        pl022->cntlr = cntlr;                //使Pl022与SpiCntlr可以相互转化的前提
        cntlr->priv = pl022;              //使Pl022与SpiCntlr可以相互转化的前提
        cntlr->busNum = pl022->busNum;    //给SpiCntlr的busNum赋值
        cntlr->method = &g_method;        //SpiCntlrMethod的实例化对象的挂载
        ...
        ret = Pl022CreatAndInitDevice(pl022);
        if (ret != 0) {
            Pl022Release(pl022);             //初始化失败就释放Pl022对象
            return ret;
        }
        return 0;
        }
        ```

    -   Release函数参考

        入参：

        HdfDeviceObject 是整个驱动对外暴露的接口参数，具备 HCS 配置文件的信息。

        返回值：

        无。

        函数说明：

        释放内存和删除控制器，该函数需要在驱动入口结构体中赋值给 Release 接口， 当HDF框架调用Init函数初始化驱动失败时，可以调用 Release 释放驱动资源。所有强制转换获取相应对象的操作**前提**是在Init函数中具备对应赋值的操作。

        ```
        static void HdfSpiDeviceRelease(struct HdfDeviceObject *device)
        {
            struct SpiCntlr *cntlr = NULL;
            ...
            cntlr = SpiCntlrFromDevice(device);//这里有HdfDeviceObject到SpiCntlr的强制转化，通过service成员，赋值见Bind函数
                                            // return (device==NULL) ?NULL:(struct SpiCntlr *)device->service;
            ...
            if (cntlr->priv != NULL) {
                Pl022Remove((struct Pl022 *)cntlr->priv);//这里有SpiCntlr到Pl022的强制转化 
            }
            SpiCntlrDestroy(cntlr);                         //释放Pl022对象
        }
        ```



