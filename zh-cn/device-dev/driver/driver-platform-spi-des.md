# SPI<a name="ZH-CN_TOPIC_0000001053057951"></a>

-   [概述](#section193356154511)
    -   [接口说明](#section232141411476)

-   [使用指导](#section71363452477)
    -   [使用流程](#section32846814820)
    -   [获取SPI设备句柄](#section1927265711481)
    -   [获取SPI设备属性](#section541133418493)
    -   [配置SPI设备属性](#section7870106145010)
    -   [进行SPI通信](#section13324155195013)
    -   [销毁SPI设备句柄](#section19661632135117)

-   [使用实例](#section06541058155120)

## 概述<a name="section193356154511"></a>

-   SPI是串行外设接口（Serial Peripheral Interface）的缩写，是一种高速的，全双工，同步的通信总线。
-   SPI是由Motorola公司开发，用于在主设备和从设备之间进行通信，常用于与闪存、实时时钟、传感器以及模数转换器等进行通信。
-   SPI以主从方式工作，通常有一个主设备和一个或者多个从设备。主设备和从设备之间一般用4根线相连，它们分别是：
    -   SCLK – 时钟信号，由主设备产生；
    -   MOSI – 主设备数据输出，从设备数据输入；
    -   MISO – 主设备数据输入，从设备数据输出；
    -   CS – 片选，从设备使能信号，由主设备控制。


-   一个主设备和两个从设备的连接示意图如[图1](#fig15227181812587)所示，Device A和Device B共享主设备的SCLK、MISO和MOSI三根引脚，Device A的片选CS0连接主设备的CS0，Device B的片选CS1连接主设备的CS1。

**图 1**  SPI主从设备连接示意图。<a name="fig15227181812587"></a>  


![](figure/zh-cn_image_0000001123742254.png)

-   SPI通信通常由主设备发起，通过以下步骤完成一次通信：

1.  通过CS选中要通信的从设备，在任意时刻，一个主设备上最多只能有一个从设备被选中。
2.  通过SCLK给选中的从设备提供时钟信号。
3.  基于SCLK时钟信号，主设备数据通过MOSI发送给从设备，同时通过MISO接收从设备发送的数据，完成通信。

-   根据SCLK时钟信号的CPOL（Clock Polarity，时钟极性）和CPHA（Clock Phase，时钟相位）的不同组合，SPI有以下四种工作模式：
    -   CPOL=0，CPHA=0 时钟信号idle状态为低电平，第一个时钟边沿采样数据。
    -   CPOL=0，CPHA=1 时钟信号idle状态为低电平，第二个时钟边沿采样数据。
    -   CPOL=1，CPHA=0 时钟信号idle状态为高电平，第一个时钟边沿采样数据。
    -   CPOL=1，CPHA=1 时钟信号idle状态为高电平，第二个时钟边沿采样数据。


-   SPI接口定义了操作SPI设备的通用方法集合，包括：
    -   SPI设备句柄获取和释放。
    -   SPI读写:  从SPI设备读取或写入指定长度数据。
    -   SPI自定义传输：通过消息传输结构体执行任意读写组合过程。
    -   SPI设备配置：获取和设置SPI设备属性。


>![](../public_sys-resources/icon-note.gif) **说明：** 
>当前只支持主机模式，不支持从机模式。

### 接口说明<a name="section232141411476"></a>

**表 1**  SPI驱动API接口功能介绍

<a name="table1731550155318"></a>
<table><thead align="left"><tr id="row4419501537"><th class="cellrowborder" align="left" valign="top" width="20.857914208579142%" id="mcps1.2.4.1.1"><p id="p641050105320"><a name="p641050105320"></a><a name="p641050105320"></a>功能分类</p>
</th>
<th class="cellrowborder" align="left" valign="top" width="23.36766323367663%" id="mcps1.2.4.1.2"><p id="p54150165315"><a name="p54150165315"></a><a name="p54150165315"></a>接口名</p>
</th>
<th class="cellrowborder" align="left" valign="top" width="55.77442255774422%" id="mcps1.2.4.1.3"><p id="p941150145313"><a name="p941150145313"></a><a name="p941150145313"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1651292212306"><td class="cellrowborder" rowspan="2" valign="top" width="20.857914208579142%" headers="mcps1.2.4.1.1 "><p id="p1387414255305"><a name="p1387414255305"></a><a name="p1387414255305"></a>SPI设备句柄获取释放接口</p>
</td>
<td class="cellrowborder" valign="top" width="23.36766323367663%" headers="mcps1.2.4.1.2 "><p id="p8874825143014"><a name="p8874825143014"></a><a name="p8874825143014"></a>SpiOpen</p>
</td>
<td class="cellrowborder" valign="top" width="55.77442255774422%" headers="mcps1.2.4.1.3 "><p id="p1087432513307"><a name="p1087432513307"></a><a name="p1087432513307"></a>获取SPI设备句柄</p>
</td>
</tr>
<tr id="row1429083612305"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1956614106311"><a name="p1956614106311"></a><a name="p1956614106311"></a>SpiClose</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p829111362306"><a name="p829111362306"></a><a name="p829111362306"></a>释放SPI设备句柄</p>
</td>
</tr>
<tr id="row34145016535"><td class="cellrowborder" rowspan="3" valign="top" width="20.857914208579142%" headers="mcps1.2.4.1.1 "><p id="p229610227124"><a name="p229610227124"></a><a name="p229610227124"></a>SPI读写接口</p>
</td>
<td class="cellrowborder" valign="top" width="23.36766323367663%" headers="mcps1.2.4.1.2 "><p id="p19389143041518"><a name="p19389143041518"></a><a name="p19389143041518"></a>SpiRead</p>
</td>
<td class="cellrowborder" valign="top" width="55.77442255774422%" headers="mcps1.2.4.1.3 "><p id="p8738101941716"><a name="p8738101941716"></a><a name="p8738101941716"></a>读取指定长度的数据</p>
</td>
</tr>
<tr id="row5632152611414"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p143890309153"><a name="p143890309153"></a><a name="p143890309153"></a>SpiWrite</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p573815197171"><a name="p573815197171"></a><a name="p573815197171"></a>写入指定长度的数据</p>
</td>
</tr>
<tr id="row1766145611414"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p183904373018"><a name="p183904373018"></a><a name="p183904373018"></a>SpiTransfer</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1639011313303"><a name="p1639011313303"></a><a name="p1639011313303"></a>SPI数据传输接口</p>
</td>
</tr>
<tr id="row1020919129159"><td class="cellrowborder" rowspan="2" valign="top" width="20.857914208579142%" headers="mcps1.2.4.1.1 "><p id="p82092126154"><a name="p82092126154"></a><a name="p82092126154"></a>SPI设备配置接口</p>
<p id="p6794153701111"><a name="p6794153701111"></a><a name="p6794153701111"></a></p>
</td>
<td class="cellrowborder" valign="top" width="23.36766323367663%" headers="mcps1.2.4.1.2 "><p id="p1739013012154"><a name="p1739013012154"></a><a name="p1739013012154"></a>SpiSetCfg</p>
</td>
<td class="cellrowborder" valign="top" width="55.77442255774422%" headers="mcps1.2.4.1.3 "><p id="p073910197173"><a name="p073910197173"></a><a name="p073910197173"></a>根据指定参数，配置SPI设备</p>
</td>
</tr>
<tr id="row379443710118"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p4333154919111"><a name="p4333154919111"></a><a name="p4333154919111"></a>SpiGetCfg</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p11333649171117"><a name="p11333649171117"></a><a name="p11333649171117"></a>获取SPI设备配置参数</p>
</td>
</tr>
</tbody>
</table>

>![](../public_sys-resources/icon-note.gif) **说明：** 
>本文涉及的所有接口，仅限内核态使用，不支持在用户态使用。

## 使用指导<a name="section71363452477"></a>

### 使用流程<a name="section32846814820"></a>

使用SPI的一般流程如[图2](#fig23885455594)所示。

**图 2**  SPI使用流程图<a name="fig23885455594"></a>  


![](figure/zh-cn_image_0000001123703482.png)

### 获取SPI设备句柄<a name="section1927265711481"></a>

在使用SPI进行通信时，首先要调用SpiOpen获取SPI设备句柄，该函数会返回指定总线号和片选号的SPI设备句柄。

DevHandle SpiOpen\(const struct SpiDevInfo \*info\); 

**表 2**  SpiOpen参数和返回值描述

<a name="table7603619123820"></a>
<table><tbody><tr id="row1060351914386"><td class="cellrowborder" valign="top" width="50%"><p id="p14603181917382"><a name="p14603181917382"></a><a name="p14603181917382"></a><strong id="b743851872411"><a name="b743851872411"></a><a name="b743851872411"></a>参数</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p36031519183819"><a name="p36031519183819"></a><a name="p36031519183819"></a><strong id="b545016183242"><a name="b545016183242"></a><a name="b545016183242"></a>参数描述</strong></p>
</td>
</tr>
<tr id="row1960431983813"><td class="cellrowborder" valign="top" width="50%"><p id="p3604719123817"><a name="p3604719123817"></a><a name="p3604719123817"></a>info</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p1560441923818"><a name="p1560441923818"></a><a name="p1560441923818"></a>SPI设备描述符</p>
</td>
</tr>
<tr id="row380484160"><td class="cellrowborder" valign="top" width="50%"><p id="p460381915385"><a name="p460381915385"></a><a name="p460381915385"></a><strong id="b209091422131617"><a name="b209091422131617"></a><a name="b209091422131617"></a>返回值</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p96031619153812"><a name="p96031619153812"></a><a name="p96031619153812"></a><strong id="b126401632121619"><a name="b126401632121619"></a><a name="b126401632121619"></a>返回值描述</strong></p>
</td>
</tr>
<tr id="row5793818161"><td class="cellrowborder" valign="top" width="50%"><p id="p1060418195389"><a name="p1060418195389"></a><a name="p1060418195389"></a>NULL</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p760471912388"><a name="p760471912388"></a><a name="p760471912388"></a>获取SPI设备句柄失败</p>
</td>
</tr>
<tr id="row187914871618"><td class="cellrowborder" valign="top" width="50%"><p id="p5604719133811"><a name="p5604719133811"></a><a name="p5604719133811"></a>设备句柄</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p3604181933818"><a name="p3604181933818"></a><a name="p3604181933818"></a>对应的SPI设备句柄</p>
</td>
</tr>
</tbody>
</table>

假设系统中的SPI设备总线号为0，片选号为0，获取该SPI设备句柄的示例如下：

```
struct SpiDevInfo spiDevinfo;       /* SPI设备描述符 */
DevHandle spiHandle = NULL; /* SPI设备句柄  */
spiDevinfo.busNum = 0;              /* SPI设备总线号 */
spiDevinfo.csNum = 0;               /* SPI设备片选号 */

/* 获取SPI设备句柄 */
spiHandle = SpiOpen(&spiDevinfo);
if (spiHandle == NULL) {
    HDF_LOGE("SpiOpen: failed\n");
    return;
}
```

### 获取SPI设备属性<a name="section541133418493"></a>

在获取到SPI设备句柄之后，需要配置SPI设备属性。配置SPI设备属性之前，可以先获取SPI设备属性，获取SPI设备属性的函数如下所示：

int32\_t SpiGetCfg\(DevHandle handle, struct SpiCfg \*cfg\);

**表 3**  SpiGetCfg参数和返回值描述

<a name="table14209152141313"></a>
<table><tbody><tr id="row1420918529133"><td class="cellrowborder" valign="top" width="50%"><p id="p42091852141314"><a name="p42091852141314"></a><a name="p42091852141314"></a><strong id="b2209135217139"><a name="b2209135217139"></a><a name="b2209135217139"></a>参数</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p202099523137"><a name="p202099523137"></a><a name="p202099523137"></a><strong id="b16209195201319"><a name="b16209195201319"></a><a name="b16209195201319"></a>参数描述</strong></p>
</td>
</tr>
<tr id="row142091352171310"><td class="cellrowborder" valign="top" width="50%"><p id="p1520915529131"><a name="p1520915529131"></a><a name="p1520915529131"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p720995291310"><a name="p720995291310"></a><a name="p720995291310"></a>SPI设备句柄</p>
</td>
</tr>
<tr id="row6209152161314"><td class="cellrowborder" valign="top" width="50%"><p id="p720916522139"><a name="p720916522139"></a><a name="p720916522139"></a>cfg</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p172091452131319"><a name="p172091452131319"></a><a name="p172091452131319"></a>SPI设备配置参数</p>
</td>
</tr>
<tr id="row12092522139"><td class="cellrowborder" valign="top" width="50%"><p id="p18209125211134"><a name="p18209125211134"></a><a name="p18209125211134"></a><strong id="b2209155219132"><a name="b2209155219132"></a><a name="b2209155219132"></a>返回值</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p420975231318"><a name="p420975231318"></a><a name="p420975231318"></a><strong id="b4209165210132"><a name="b4209165210132"></a><a name="b4209165210132"></a>返回值描述</strong></p>
</td>
</tr>
<tr id="row8209155251310"><td class="cellrowborder" valign="top" width="50%"><p id="p13210145291312"><a name="p13210145291312"></a><a name="p13210145291312"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p152101952141315"><a name="p152101952141315"></a><a name="p152101952141315"></a>获取配置成功</p>
</td>
</tr>
<tr id="row102101452121320"><td class="cellrowborder" valign="top" width="50%"><p id="p10210175219134"><a name="p10210175219134"></a><a name="p10210175219134"></a>负数</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p72101252101312"><a name="p72101252101312"></a><a name="p72101252101312"></a>获取配置失败</p>
</td>
</tr>
</tbody>
</table>

```
int32_t ret;
struct SpiCfg cfg = {0};                /* SPI配置信息*/
ret = SpiGetCfg(spiHandle, &cfg);       /* 配置SPI设备属性 */
if (ret != 0) {
    HDF_LOGE("SpiGetCfg: failed, ret %d\n", ret);
}
```

### 配置SPI设备属性<a name="section7870106145010"></a>

在获取到SPI设备句柄之后，需要配置SPI设备属性，配置SPI设备属性的函数如下所示：

int32\_t SpiSetCfg\(DevHandle handle, struct SpiCfg \*cfg\);

**表 4**  SpiSetCfg参数和返回值描述

<a name="table219052945210"></a>
<table><tbody><tr id="row14191192918522"><td class="cellrowborder" valign="top" width="50%"><p id="p17424155016529"><a name="p17424155016529"></a><a name="p17424155016529"></a><strong id="b13808393249"><a name="b13808393249"></a><a name="b13808393249"></a>参数</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p942512508520"><a name="p942512508520"></a><a name="p942512508520"></a><strong id="b78202962416"><a name="b78202962416"></a><a name="b78202962416"></a>参数描述</strong></p>
</td>
</tr>
<tr id="row219152915524"><td class="cellrowborder" valign="top" width="50%"><p id="p2191122985218"><a name="p2191122985218"></a><a name="p2191122985218"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p1519162913524"><a name="p1519162913524"></a><a name="p1519162913524"></a>SPI设备句柄</p>
</td>
</tr>
<tr id="row1719110297526"><td class="cellrowborder" valign="top" width="50%"><p id="p181911292523"><a name="p181911292523"></a><a name="p181911292523"></a>cfg</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p91911729155216"><a name="p91911729155216"></a><a name="p91911729155216"></a>SPI设备配置参数</p>
</td>
</tr>
<tr id="row036524131716"><td class="cellrowborder" valign="top" width="50%"><p id="p6425165035214"><a name="p6425165035214"></a><a name="p6425165035214"></a><strong id="b61219451173"><a name="b61219451173"></a><a name="b61219451173"></a>返回值</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p18425650165215"><a name="p18425650165215"></a><a name="p18425650165215"></a><strong id="b826124514172"><a name="b826124514172"></a><a name="b826124514172"></a>返回值描述</strong></p>
</td>
</tr>
<tr id="row43653411178"><td class="cellrowborder" valign="top" width="50%"><p id="p1319132918520"><a name="p1319132918520"></a><a name="p1319132918520"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p1719117292522"><a name="p1719117292522"></a><a name="p1719117292522"></a>配置成功</p>
</td>
</tr>
<tr id="row536594171715"><td class="cellrowborder" valign="top" width="50%"><p id="p719119296522"><a name="p719119296522"></a><a name="p719119296522"></a>负数</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p20191192925212"><a name="p20191192925212"></a><a name="p20191192925212"></a>配置失败</p>
</td>
</tr>
</tbody>
</table>

```
int32_t ret;
struct SpiCfg cfg = {0};                     /* SPI配置信息*/
cfg.mode = SPI_MODE_LOOP;                    /* 以回环模式进行通信 */
cfg.transferMode = PAL_SPI_POLLING_TRANSFER; /* 以轮询的方式进行通信 */
cfg.maxSpeedHz = 115200;                     /* 最大传输频率 */ 
cfg.bitsPerWord = 8;                         /* 读写位宽为8个比特 */
ret = SpiSetCfg(spiHandle, &cfg);            /* 配置SPI设备属性 */
if (ret != 0) {
    HDF_LOGE("SpiSetCfg: failed, ret %d\n", ret);
}
```

### 进行SPI通信<a name="section13324155195013"></a>

-   向SPI设备写入指定长度的数据

如果只向SPI设备写一次数据，则可以通过以下函数完成：

int32\_t SpiWrite\(DevHandle handle, uint8\_t \*buf, uint32\_t len\);

**表 5**  SpiWrite参数和返回值描述

<a name="table1018490043"></a>
<table><tbody><tr id="row31848013417"><td class="cellrowborder" valign="top" width="50%"><p id="p1415816132411"><a name="p1415816132411"></a><a name="p1415816132411"></a><strong id="b011110449230"><a name="b011110449230"></a><a name="b011110449230"></a>参数</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p11158111316410"><a name="p11158111316410"></a><a name="p11158111316410"></a><strong id="b18123204410230"><a name="b18123204410230"></a><a name="b18123204410230"></a>参数描述</strong></p>
</td>
</tr>
<tr id="row10184701945"><td class="cellrowborder" valign="top" width="50%"><p id="p104891871157"><a name="p104891871157"></a><a name="p104891871157"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p204891671156"><a name="p204891671156"></a><a name="p204891671156"></a>SPI设备句柄</p>
</td>
</tr>
<tr id="row928111518418"><td class="cellrowborder" valign="top" width="50%"><p id="p4282955412"><a name="p4282955412"></a><a name="p4282955412"></a>buf</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p7282752412"><a name="p7282752412"></a><a name="p7282752412"></a>待写入数据的指针</p>
</td>
</tr>
<tr id="row149041113651"><td class="cellrowborder" valign="top" width="50%"><p id="p139051213357"><a name="p139051213357"></a><a name="p139051213357"></a>len</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p16905313854"><a name="p16905313854"></a><a name="p16905313854"></a>待写入的数据长度</p>
</td>
</tr>
<tr id="row1148818622017"><td class="cellrowborder" valign="top" width="50%"><p id="p8158313248"><a name="p8158313248"></a><a name="p8158313248"></a><strong id="b1197324122018"><a name="b1197324122018"></a><a name="b1197324122018"></a>返回值</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p161591413741"><a name="p161591413741"></a><a name="p161591413741"></a><strong id="b15219182419209"><a name="b15219182419209"></a><a name="b15219182419209"></a>返回值描述</strong></p>
</td>
</tr>
<tr id="row14488762202"><td class="cellrowborder" valign="top" width="50%"><p id="p103191916578"><a name="p103191916578"></a><a name="p103191916578"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p1231981611712"><a name="p1231981611712"></a><a name="p1231981611712"></a>写入成功</p>
</td>
</tr>
<tr id="row164881464201"><td class="cellrowborder" valign="top" width="50%"><p id="p531916166716"><a name="p531916166716"></a><a name="p531916166716"></a>负数</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p93191161174"><a name="p93191161174"></a><a name="p93191161174"></a>写入失败</p>
</td>
</tr>
</tbody>
</table>

```
int32_t ret;
uint8_t wbuff[4] = {0x12, 0x34, 0x56, 0x78};
/* 向SPI设备写入指定长度的数据 */
ret = SpiWrite(spiHandle, wbuff, 4);
if (ret != 0) {
    HDF_LOGE("SpiWrite: failed, ret %d\n", ret);
}
```

-   从SPI设备读取指定长度的数据

如果只读取一次数据，则可以通过以下函数完成：

int32\_t SpiRead\(DevHandle handle, uint8\_t \*buf, uint32\_t len\); 

**表 6**  SpiRead参数和返回值描述

<a name="table0265191412124"></a>
<table><tbody><tr id="row42651914141213"><td class="cellrowborder" valign="top" width="50%"><p id="p1483184123"><a name="p1483184123"></a><a name="p1483184123"></a><strong id="b81201431172318"><a name="b81201431172318"></a><a name="b81201431172318"></a>参数</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p9831871216"><a name="p9831871216"></a><a name="p9831871216"></a><strong id="b31321731122316"><a name="b31321731122316"></a><a name="b31321731122316"></a>参数描述</strong></p>
</td>
</tr>
<tr id="row1926651415123"><td class="cellrowborder" valign="top" width="50%"><p id="p389183129"><a name="p389183129"></a><a name="p389183129"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p168151817124"><a name="p168151817124"></a><a name="p168151817124"></a>SPI设备句柄</p>
</td>
</tr>
<tr id="row202661414201220"><td class="cellrowborder" valign="top" width="50%"><p id="p158161821210"><a name="p158161821210"></a><a name="p158161821210"></a>buf</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p98131811126"><a name="p98131811126"></a><a name="p98131811126"></a>待读取数据的指针</p>
</td>
</tr>
<tr id="row1926621451212"><td class="cellrowborder" valign="top" width="50%"><p id="p2918182124"><a name="p2918182124"></a><a name="p2918182124"></a>len</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p169718191220"><a name="p169718191220"></a><a name="p169718191220"></a>待读取的数据长度</p>
</td>
</tr>
<tr id="row05841310206"><td class="cellrowborder" valign="top" width="50%"><p id="p38171818128"><a name="p38171818128"></a><a name="p38171818128"></a><strong id="b33485467201"><a name="b33485467201"></a><a name="b33485467201"></a>返回值</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p881918161220"><a name="p881918161220"></a><a name="p881918161220"></a><strong id="b13361846112013"><a name="b13361846112013"></a><a name="b13361846112013"></a>返回值描述</strong></p>
</td>
</tr>
<tr id="row15584173192016"><td class="cellrowborder" valign="top" width="50%"><p id="p14871820128"><a name="p14871820128"></a><a name="p14871820128"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p88118101211"><a name="p88118101211"></a><a name="p88118101211"></a>读取成功</p>
</td>
</tr>
<tr id="row1058418317204"><td class="cellrowborder" valign="top" width="50%"><p id="p10841817125"><a name="p10841817125"></a><a name="p10841817125"></a>负数</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p986183127"><a name="p986183127"></a><a name="p986183127"></a>读取失败</p>
</td>
</tr>
</tbody>
</table>

```
int32_t ret;
uint8_t rbuff[4] = {0};
/* 从SPI设备读取指定长度的数据 */
ret = SpiRead(spiHandle, rbuff, 4);
if (ret != 0) {
    HDF_LOGE("SpiRead: failed, ret %d\n", ret);
}
```

-   自定义传输

如果需要发起一次自定义传输，则可以通过以下函数完成：

int32\_t SpiTransfer\(DevHandle handle, struct SpiMsg \*msgs, uint32\_t count\);

**表 7**  SpiTransfer参数和返回值描述

<a name="table1934414174212"></a>
<table><tbody><tr id="row1134415176216"><td class="cellrowborder" valign="top" width="50%"><p id="p13295152320217"><a name="p13295152320217"></a><a name="p13295152320217"></a><strong id="b14726194114224"><a name="b14726194114224"></a><a name="b14726194114224"></a>参数</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p1295112352115"><a name="p1295112352115"></a><a name="p1295112352115"></a><strong id="b6744541162218"><a name="b6744541162218"></a><a name="b6744541162218"></a>参数描述</strong></p>
</td>
</tr>
<tr id="row5344101702113"><td class="cellrowborder" valign="top" width="50%"><p id="p19295132382111"><a name="p19295132382111"></a><a name="p19295132382111"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p829510232213"><a name="p829510232213"></a><a name="p829510232213"></a>SPI设备句柄</p>
</td>
</tr>
<tr id="row17344171722117"><td class="cellrowborder" valign="top" width="50%"><p id="p9295122332113"><a name="p9295122332113"></a><a name="p9295122332113"></a>msgs</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p202951238218"><a name="p202951238218"></a><a name="p202951238218"></a>待传输数据的数组</p>
</td>
</tr>
<tr id="row45812466213"><td class="cellrowborder" valign="top" width="50%"><p id="p1659246112117"><a name="p1659246112117"></a><a name="p1659246112117"></a>count</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p259124622119"><a name="p259124622119"></a><a name="p259124622119"></a>msgs数组长度</p>
</td>
</tr>
<tr id="row45187318214"><td class="cellrowborder" valign="top" width="50%"><p id="p17295142322113"><a name="p17295142322113"></a><a name="p17295142322113"></a><strong id="b6754144472117"><a name="b6754144472117"></a><a name="b6754144472117"></a>返回值</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p142959232211"><a name="p142959232211"></a><a name="p142959232211"></a><strong id="b107682446216"><a name="b107682446216"></a><a name="b107682446216"></a>返回值描述</strong></p>
</td>
</tr>
<tr id="row175186313217"><td class="cellrowborder" valign="top" width="50%"><p id="p929532313211"><a name="p929532313211"></a><a name="p929532313211"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p829512237217"><a name="p829512237217"></a><a name="p829512237217"></a>执行成功</p>
</td>
</tr>
<tr id="row1451803152114"><td class="cellrowborder" valign="top" width="50%"><p id="p12958234217"><a name="p12958234217"></a><a name="p12958234217"></a>负数</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p1295192312112"><a name="p1295192312112"></a><a name="p1295192312112"></a>执行失败</p>
</td>
</tr>
</tbody>
</table>

```
int32_t ret;
uint8_t wbuff[1] = {0x12};
uint8_t rbuff[1] = {0};
struct SpiMsg msg;        /* 自定义传输的消息*/
msg.wbuf = wbuff;         /* 写入的数据 */
msg.rbuf = rbuff;         /* 读取的数据 */
msg.len = 1;              /* 读取、写入数据的长度都是1 */
msg.csChange = 1;         /* 进行下一次传输前关闭片选 */
msg.delayUs = 0;          /* 进行下一次传输前不进行延时 */
msg.speed = 115200;       /* 本次传输的速度 */
/* 进行一次自定义传输，传输的msg个数为1 */
ret = SpiTransfer(spiHandle, &msg, 1);
if (ret != 0) {
    HDF_LOGE("SpiTransfer: failed, ret %d\n", ret);
}
```

### 销毁SPI设备句柄<a name="section19661632135117"></a>

SPI通信完成之后，需要销毁SPI设备句柄，销毁SPI设备句柄的函数如下所示：

void SpiClose\(DevHandle handle\);

该函数会释放掉申请的资源。

**表 8**  SpiClose参数描述

<a name="table72517953115"></a>
<table><tbody><tr id="row1525793312"><td class="cellrowborder" valign="top" width="50%"><p id="p115402031153111"><a name="p115402031153111"></a><a name="p115402031153111"></a><strong id="b691142582513"><a name="b691142582513"></a><a name="b691142582513"></a>参数</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p65406313319"><a name="p65406313319"></a><a name="p65406313319"></a><strong id="b1892414252254"><a name="b1892414252254"></a><a name="b1892414252254"></a>参数描述</strong></p>
</td>
</tr>
<tr id="row1926109193116"><td class="cellrowborder" valign="top" width="50%"><p id="p105419317318"><a name="p105419317318"></a><a name="p105419317318"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p16541153110317"><a name="p16541153110317"></a><a name="p16541153110317"></a>SPI设备句柄</p>
</td>
</tr>
</tbody>
</table>

```
SpiClose(spiHandle); /* 销毁SPI设备句柄 */
```

## 使用实例<a name="section06541058155120"></a>

SPI设备完整的使用示例如下所示，首先获取SPI设备句柄，然后配置SPI设备属性，接着调用读写接口进行数据传输，最后销毁SPI设备句柄。

```
#include "hdf_log.h"
#include "spi_if.h"

void SpiTestSample(void)
{
    int32_t ret;
    struct SpiCfg cfg;                  /* SPI配置信息 */
    struct SpiDevInfo spiDevinfo;       /* SPI设备描述符 */
    DevHandle spiHandle = NULL; /* SPI设备句柄 */
    struct SpiMsg msg;                  /* 自定义传输的消息 */
    uint8_t rbuff[4] = { 0 };
    uint8_t wbuff[4] = { 0x12, 0x34, 0x56, 0x78 };
    uint8_t wbuff2[4] = { 0xa1, 0xb2, 0xc3, 0xd4 };

    spiDevinfo.busNum = 0;              /* SPI设备总线号 */
    spiDevinfo.csNum = 0;               /* SPI设备片选号 */
    spiHandle = SpiOpen(&spiDevinfo);   /* 根据spiDevinfo获取SPI设备句柄 */
    if (spiHandle == NULL) {
        HDF_LOGE("SpiOpen: failed\n");
        return;
    }
    /* 获取SPI设备属性 */
    ret = SpiGetCfg(spiHandle, &cfg);
    if (ret != 0) {
        HDF_LOGE("SpiGetCfg: failed, ret %d\n", ret);
        goto err;
    }
    cfg.maxSpeedHz = 115200;                /* 将最大时钟频率改为115200 */
    cfg.bitsPerWord = 8;                    /* 传输位宽改为8比特 */
    /* 配置SPI设备属性 */
    ret = SpiSetCfg(spiHandle, &cfg);
    if (ret != 0) {
        HDF_LOGE("SpiSetCfg: failed, ret %d\n", ret);
        goto err;
    }
    /* 向SPI设备写入指定长度的数据 */
    ret = SpiWrite(spiHandle, wbuff, 4);
    if (ret != 0) {
        HDF_LOGE("SpiWrite: failed, ret %d\n", ret);
        goto err;
    }
    /* 从SPI设备读取指定长度的数据 */
    ret = SpiRead(spiHandle, rbuff, 4);
    if (ret != 0) {
        HDF_LOGE("SpiRead: failed, ret %d\n", ret);
        goto err;
    }
    msg.wbuf = wbuff2;  /* 写入的数据 */
    msg.rbuf = rbuff;   /* 读取的数据 */
    msg.len = 4;        /* 读取写入数据的长度为4 */
    msg.csChange = 1;   /* 进行下一次传输前关闭片选 */
    msg.delayUs = 0;    /* 进行下一次传输前不进行延时 */
    msg.speed = 115200; /* 本次传输的速度 */
    /* 进行一次自定义传输，传输的msg个数为1 */
    ret = SpiTransfer(spiHandle, &msg, 1);
    if (ret != 0) {
        HDF_LOGE("SpiTransfer: failed, ret %d\n", ret);
        goto err;
    }
err:
    /* 销毁SPI设备句柄 */
    SpiClose(spiHandle);
}
```

