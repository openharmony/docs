# SDIO<a name="ZH-CN_TOPIC_0000001176922484"></a>

-   [概述](#section1347805272150053)
-   [接口说明](#section752964871810)
-   [开发步骤](#section581179475150053)
-   [开发实例](#section2112250242150053)

## 概述<a name="section1347805272150053"></a>

SDIO由SD卡发展而来，被统称为mmc（MultiMediaCard），相关技术差别不大,在HDF框架中，SDIO的接口适配模式采用独立服务模式，在这种模式下，每一个设备对象会独立发布一个设备服务来处理外部访问，设备管理器收到API的访问请求之后，通过提取该请求的参数，达到调用实际设备对象的相应内部方法的目的。独立服务模式可以直接借助HDFDeviceManager的服务管理能力，但需要为每个设备单独配置设备节点，增加内存占用。

**图 1**  SDIO独立服务模式结构图<a name="fig124181331222"></a>  
![](figures/SDIO独立服务模式结构图.png "SDIO独立服务模式结构图")

## 接口说明<a name="section752964871810"></a>

SdioDeviceOps定义：

```
// 函数模板
struct SdioDeviceOps {
  int32_t (*incrAddrReadBytes)(struct SdioDevice *dev, uint8_t *data, uint32_t addr, uint32_t size);
  int32_t (*incrAddrWriteBytes)(struct SdioDevice *dev, uint8_t *data, uint32_t addr, uint32_t size);
  int32_t (*fixedAddrReadBytes)(struct SdioDevice *dev, uint8_t *data, uint32_t addr, uint32_t size, uint32_t scatterLen);
  int32_t (*fixedAddrWriteBytes)(struct SdioDevice *dev, uint8_t *data, uint32_t addr, uint32_t size, uint32_t scatterLen);
  int32_t (*func0ReadBytes)(struct SdioDevice *dev, uint8_t *data, uint32_t addr, uint32_t size);
  int32_t (*func0WriteBytes)(struct SdioDevice *dev, uint8_t *data, uint32_t addr, uint32_t size);
  int32_t (*setBlockSize)(struct SdioDevice *dev, uint32_t blockSize);
  int32_t (*getCommonInfo)(struct SdioDevice *dev, SdioCommonInfo *info, uint32_t infoType);
  int32_t (*setCommonInfo)(struct SdioDevice *dev, SdioCommonInfo *info, uint32_t infoType);
  int32_t (*flushData)(struct SdioDevice *dev);
  int32_t (*enableFunc)(struct SdioDevice *dev);
  int32_t (*disableFunc)(struct SdioDevice *dev);
  int32_t (*claimIrq)(struct SdioDevice *dev, SdioIrqHandler *irqHandler);
  int32_t (*releaseIrq)(struct SdioDevice *dev);
  int32_t (*findFunc)(struct SdioDevice *dev, struct SdioFunctionConfig *configData);
  int32_t (*claimHost)(struct SdioDevice *dev);
  int32_t (*releaseHost)(struct SdioDevice *dev);
};
```

**表 1**  SdioDeviceOps结构体成员的回调函数功能说明

<a name="table878215448417"></a>
<table><thead align="left"><tr id="row17784344241"><th class="cellrowborder" valign="top" width="20%" id="mcps1.2.6.1.1"><p id="p67842444414"><a name="p67842444414"></a><a name="p67842444414"></a>函数</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.2.6.1.2"><p id="p1978411444416"><a name="p1978411444416"></a><a name="p1978411444416"></a>入参</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.2.6.1.3"><p id="p87841441243"><a name="p87841441243"></a><a name="p87841441243"></a>出参</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.2.6.1.4"><p id="p12784174417415"><a name="p12784174417415"></a><a name="p12784174417415"></a>返回值</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.2.6.1.5"><p id="p16784104418413"><a name="p16784104418413"></a><a name="p16784104418413"></a>功能</p>
</th>
</tr>
</thead>
<tbody><tr id="row8784144449"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p1378415443418"><a name="p1378415443418"></a><a name="p1378415443418"></a>incrAddrReadBytes</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p177857442043"><a name="p177857442043"></a><a name="p177857442043"></a>dev: 结构体指针,SDIO设备控制器;addr: uint32_t,地址值;size: uint32_t,大小</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p207851447410"><a name="p207851447410"></a><a name="p207851447410"></a>data: uint8_t指针,传出值;</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p167851644547"><a name="p167851644547"></a><a name="p167851644547"></a>HDF_STATUS相关状态</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p37855441645"><a name="p37855441645"></a><a name="p37855441645"></a>从指定的SDIO地址增量读取给定长度的数据</p>
</td>
</tr>
<tr id="row197851446413"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p5785174419412"><a name="p5785174419412"></a><a name="p5785174419412"></a>incrAddrWriteBytes</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p078554411417"><a name="p078554411417"></a><a name="p078554411417"></a>dev: 结构体指针,SDIO设备控制器;data: uint8_t指针,传入值;addr: uint32_t,地址值;size: uint32_t,大小</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p678519441748"><a name="p678519441748"></a><a name="p678519441748"></a>无</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p778594419416"><a name="p778594419416"></a><a name="p778594419416"></a>HDF_STATUS相关状态</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p67851444445"><a name="p67851444445"></a><a name="p67851444445"></a>将给定长度的数据增量写入指定的SDIO地址</p>
</td>
</tr>
<tr id="row11785154419412"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p978514412418"><a name="p978514412418"></a><a name="p978514412418"></a>fixedAddrReadBytes</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p15786144419415"><a name="p15786144419415"></a><a name="p15786144419415"></a>dev: 结构体指针,SDIO设备控制器;addr: uint32_t,地址值;size: uint32_t,大小;scatterLen: uint32_t,数据长度；</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p9786124418414"><a name="p9786124418414"></a><a name="p9786124418414"></a>data: uint8_t指针,传出值;</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p2078614441842"><a name="p2078614441842"></a><a name="p2078614441842"></a>HDF_STATUS相关状态</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p107861744143"><a name="p107861744143"></a><a name="p107861744143"></a>从固定SDIO地址读取给定长度的数据。</p>
</td>
</tr>
<tr id="row278618441241"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p137861244448"><a name="p137861244448"></a><a name="p137861244448"></a>fixedAddrWriteBytes</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p77861444341"><a name="p77861444341"></a><a name="p77861444341"></a>dev: 结构体指针,SDIO设备控制器;data: uint8_t指针,传入值;addr: uint32_t,地址值;size: uint32_t,大小;scatterLen: uint32_t,数据长度;</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p5786244345"><a name="p5786244345"></a><a name="p5786244345"></a>无</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p147868442416"><a name="p147868442416"></a><a name="p147868442416"></a>HDF_STATUS相关状态</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p1478615441948"><a name="p1478615441948"></a><a name="p1478615441948"></a>将给定长度的数据写入固定SDIO地址</p>
</td>
</tr>
<tr id="row1078694416418"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p12786154414413"><a name="p12786154414413"></a><a name="p12786154414413"></a>func0ReadBytes</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p4786244541"><a name="p4786244541"></a><a name="p4786244541"></a>dev: 结构体指针,SDIO设备控制器;addr: uint32_t,地址值;size: uint32_t,大小;</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p37868445420"><a name="p37868445420"></a><a name="p37868445420"></a>data: uint8_t指针,传出值;</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p197874442416"><a name="p197874442416"></a><a name="p197874442416"></a>HDF_STATUS相关状态</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p107877441146"><a name="p107877441146"></a><a name="p107877441146"></a>从SDIO函数0的地址空间读取给定长度的数据。</p>
</td>
</tr>
<tr id="row1478794415414"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p12787644548"><a name="p12787644548"></a><a name="p12787644548"></a>func0WriteBytes</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p67871544242"><a name="p67871544242"></a><a name="p67871544242"></a>dev: 结构体指针,SDIO设备控制器;data: uint8_t指针,传入值;addr: uint32_t,地址值;size: uint32_t,大小;</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p678774413416"><a name="p678774413416"></a><a name="p678774413416"></a>无</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p207871944648"><a name="p207871944648"></a><a name="p207871944648"></a>HDF_STATUS相关状态</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p57876441415"><a name="p57876441415"></a><a name="p57876441415"></a>将给定长度的数据写入SDIO函数0的地址空间。</p>
</td>
</tr>
<tr id="row157871441145"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p1878714442417"><a name="p1878714442417"></a><a name="p1878714442417"></a>setBlockSize</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p187872445410"><a name="p187872445410"></a><a name="p187872445410"></a>dev: 结构体指针,SDIO设备控制器;blockSize: uint32_t,Block大小</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p77878444415"><a name="p77878444415"></a><a name="p77878444415"></a>无</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p37871244243"><a name="p37871244243"></a><a name="p37871244243"></a>HDF_STATUS相关状态</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p378710441647"><a name="p378710441647"></a><a name="p378710441647"></a>设置block大小</p>
</td>
</tr>
<tr id="row15787344349"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p878819441048"><a name="p878819441048"></a><a name="p878819441048"></a>getCommonInfo</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p1078820442419"><a name="p1078820442419"></a><a name="p1078820442419"></a>dev: 联合体指针,SDIO设备控制器;infoType: uint32_t,info类型;</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p678814411418"><a name="p678814411418"></a><a name="p678814411418"></a>info: 结构体指针,传出SdioFuncInfo信息;</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p1578894410419"><a name="p1578894410419"></a><a name="p1578894410419"></a>HDF_STATUS相关状态</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p7788444140"><a name="p7788444140"></a><a name="p7788444140"></a>获取CommonInfo，说明见下</p>
</td>
</tr>
<tr id="row7788154410416"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p6788104410419"><a name="p6788104410419"></a><a name="p6788104410419"></a>setCommonInfo</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p2078815442417"><a name="p2078815442417"></a><a name="p2078815442417"></a>dev: 结构体指针,SDIO设备控制器;info: 联合体指针，SdioFuncInfo信息传入;infoType: uint32_t,info类型;</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p13788644043"><a name="p13788644043"></a><a name="p13788644043"></a>无</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p19788134418420"><a name="p19788134418420"></a><a name="p19788134418420"></a>HDF_STATUS相关状态</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p1278814415412"><a name="p1278814415412"></a><a name="p1278814415412"></a>设置CommonInfo，说明见下</p>
</td>
</tr>
<tr id="row1788344744"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p2078819441745"><a name="p2078819441745"></a><a name="p2078819441745"></a>flushData</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p67888441442"><a name="p67888441442"></a><a name="p67888441442"></a>dev: 结构体指针,SDIO设备控制器;</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p1478812441147"><a name="p1478812441147"></a><a name="p1478812441147"></a>无</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p3789174418420"><a name="p3789174418420"></a><a name="p3789174418420"></a>HDF_STATUS相关状态</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p578912441445"><a name="p578912441445"></a><a name="p578912441445"></a>当SDIO需要重新初始化或发生意外错误时调用的函数</p>
</td>
</tr>
<tr id="row19789244142"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p778913441417"><a name="p778913441417"></a><a name="p778913441417"></a>enableFunc</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p12789144418412"><a name="p12789144418412"></a><a name="p12789144418412"></a>dev: 结构体指针,SDIO设备控制器;</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p678964419417"><a name="p678964419417"></a><a name="p678964419417"></a>无</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p97891744946"><a name="p97891744946"></a><a name="p97891744946"></a>HDF_STATUS相关状态</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p127891445415"><a name="p127891445415"></a><a name="p127891445415"></a>使能SDIO设备</p>
</td>
</tr>
<tr id="row177898441647"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p978917447412"><a name="p978917447412"></a><a name="p978917447412"></a>disableFunc</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p1978911449418"><a name="p1978911449418"></a><a name="p1978911449418"></a>dev: 结构体指针,SDIO设备控制器;</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p57898448413"><a name="p57898448413"></a><a name="p57898448413"></a>无</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p77893441341"><a name="p77893441341"></a><a name="p77893441341"></a>HDF_STATUS相关状态</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p1479019449414"><a name="p1479019449414"></a><a name="p1479019449414"></a>去使能SDIO设备</p>
</td>
</tr>
<tr id="row17908444415"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p1279017441140"><a name="p1279017441140"></a><a name="p1279017441140"></a>claimIrq</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p1279018442419"><a name="p1279018442419"></a><a name="p1279018442419"></a>dev: 结构体指针,SDIO设备控制器;irqHandler: void函数指针;</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p379084411411"><a name="p379084411411"></a><a name="p379084411411"></a>无</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p1179074410416"><a name="p1179074410416"></a><a name="p1179074410416"></a>HDF_STATUS相关状态</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p6790124418410"><a name="p6790124418410"></a><a name="p6790124418410"></a>注册SDIO中断</p>
</td>
</tr>
<tr id="row177909441647"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p77900441411"><a name="p77900441411"></a><a name="p77900441411"></a>releaseIrq</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p27902441414"><a name="p27902441414"></a><a name="p27902441414"></a>dev: 结构体指针,SDIO设备控制器;</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p87906441742"><a name="p87906441742"></a><a name="p87906441742"></a>无</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p147906446419"><a name="p147906446419"></a><a name="p147906446419"></a>HDF_STATUS相关状态</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p77901544440"><a name="p77901544440"></a><a name="p77901544440"></a>释放SDIO中断</p>
</td>
</tr>
<tr id="row97906449416"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p579024419411"><a name="p579024419411"></a><a name="p579024419411"></a>findFunc</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p5791184417414"><a name="p5791184417414"></a><a name="p5791184417414"></a>dev: 结构体指针,SDIO设备控制器;configData: 结构体指针, SDIO函数关键信息</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p1079112441345"><a name="p1079112441345"></a><a name="p1079112441345"></a>无</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p17916446420"><a name="p17916446420"></a><a name="p17916446420"></a>HDF_STATUS相关状态</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p779119441549"><a name="p779119441549"></a><a name="p779119441549"></a>寻找匹配的funcNum</p>
</td>
</tr>
<tr id="row779116446417"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p679119448412"><a name="p679119448412"></a><a name="p679119448412"></a>claimHost</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p179116441547"><a name="p179116441547"></a><a name="p179116441547"></a>dev: 结构体指针,SDIO设备控制器;</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p97911144944"><a name="p97911144944"></a><a name="p97911144944"></a>无</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p12791244341"><a name="p12791244341"></a><a name="p12791244341"></a>HDF_STATUS相关状态</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p5791134412417"><a name="p5791134412417"></a><a name="p5791134412417"></a>独占HOST</p>
</td>
</tr>
<tr id="row47911344746"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p279113441046"><a name="p279113441046"></a><a name="p279113441046"></a>releaseHost</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p67916449413"><a name="p67916449413"></a><a name="p67916449413"></a>dev: 结构体指针,SDIO设备控制器;</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p37916441244"><a name="p37916441244"></a><a name="p37916441244"></a>无</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p97911044948"><a name="p97911044948"></a><a name="p97911044948"></a>HDF_STATUS相关状态</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p1792184413412"><a name="p1792184413412"></a><a name="p1792184413412"></a>释放HOST</p>
</td>
</tr>
</tbody>
</table>

>![](../public_sys-resources/icon-note.gif) **说明：** 
>CommonInfo包括maxBlockNum\(单个request中最大block数\), maxBlockSize\(单个block最大字节数\), maxRequestSize\(单个Request最大字节数\), enTimeout\(最大超时时间,毫秒\), funcNum\(功能编号1\~7\), irqCap\(IRQ capabilities\), \(void \*\)data.

## 开发步骤<a name="section581179475150053"></a>

SDIO模块适配HDF框架的三个环节是配置属性文件，实例化驱动入口，以及填充核心层接口函数。

1.  **实例化驱动入口：**
    -   实例化HdfDriverEntry结构体成员。
    -   调用HDF\_INIT将HdfDriverEntry实例化对象注册到HDF框架中。

2.  **配置属性文件：**
    -   在device\_info.hcs文件中添加deviceNode描述。
    -   【可选】添加sdio\_config.hcs器件属性文件。

3.  **实例化SDIO控制器对象：**
    -   初始化SdioDevice成员。
    -   实例化SdioDevice成员SdioDeviceOps。

        >![](../public_sys-resources/icon-note.gif) **说明：** 
        >实例化SdioDevice成员SdioDeviceOps，其定义和成员说明见[SdioDeviceOps定义](#section482911395315)和[表1](#table878215448417)


4.  **驱动调试：**

    【可选】针对新增驱动程序，建议验证驱动基本功能，例如SDIO控制状态，中断响应情况等。


## 开发实例<a name="section2112250242150053"></a>

下方将以sdio\_adapter.c为示例，展示需要厂商提供哪些内容来完整实现设备功能。

1.  驱动开发首先需要实例化驱动入口，驱动入口必须为HdfDriverEntry（在 hdf\_device\_desc.h 中定义）类型的全局变量，且moduleName要和device\_info.hcs中保持一致。HDF框架会将所有加载的驱动的HdfDriverEntry对象首地址汇总，形成一个类似数组的段地址空间，方便上层调用。

    一般在加载驱动时HDF会先调用Bind函数，再调用Init函数加载该驱动。当Init调用异常时，HDF框架会调用Release释放驱动资源并退出。

    SDIO 驱动入口参考：

    ```
    struct HdfDriverEntry g_sdioDriverEntry = {
        .moduleVersion = 1,
        .Bind = Hi35xxLinuxSdioBind,      //见Bind参考
        .Init = Hi35xxLinuxSdioInit,      //见Init参考
        .Release = Hi35xxLinuxSdioRelease,//见Release参考
        .moduleName = "HDF_PLATFORM_SDIO",//【必要 且与 HCS文件中里面的moduleName匹配】
    };
    //调用HDF_INIT将驱动入口注册到HDF框架中 
    HDF_INIT(g_sdioDriverEntry);
    ```

2.  完成驱动入口注册之后，下一步请在device\_info.hcs文件中添加deviceNode信息，并在 sdio\_config.hcs 中配置器件属性。deviceNode信息与驱动入口注册相关，器件属性值与核心层SdioDevice成员的默认值或限制范围有密切关系。

    本例只有一个SDIO控制器，如有多个器件信息，则需要在device\_info文件增加deviceNode信息，以及在sdio\_config文件中增加对应的器件属性。

    -   device\_info.hcs 配置参考：

        ```
         root {
          device_info {
            match_attr = "hdf_manager";
            platform :: host {
              hostName = "platform_host";
              priority = 50;
              device_sdio :: device {
                device0 :: deviceNode {
                  policy = 1;
                  priority = 70;
                  permission = 0644;
                  moduleName = "HDF_PLATFORM_SDIO";   //【必要】用于指定驱动名称，需要与驱动Entry中的moduleName一致；
                  serviceName = "HDF_PLATFORM_MMC_2"; //【必要】驱动对外发布服务的名称，必须唯一
                  deviceMatchAttr = "hisilicon_hi35xx_sdio_0";//【必要】用于配置控制器私有数据，要与sdio_config.hcs中对应控制器保持一致
                }
              }
            }
          }
        }
        ```

    -   sdio\_config.hcs 配置参考：

        ```
        root {
          platform {
            sdio_config {
              template sdio_controller {
                match_attr = "";
                hostId = 2;  //【必要】模式固定为2，在mmc_config.hcs有介绍
                devType = 2; //【必要】模式固定为2，在mmc_config.hcs有介绍
              }
              controller_0x2dd1 :: sdio_controller {
                match_attr = "hisilicon_hi35xx_sdio_0";//【必要】需要和device_info.hcs中的deviceMatchAttr值一致
            }
          }
        }
        ```

3.  完成驱动入口注册之后，最后一步就是以核心层SdioDevice对象的初始化为核心，包括厂商自定义结构体（传递参数和数据），实例化SdioDevice成员SdioDeviceOps（让用户可以通过接口来调用驱动底层函数），实现HdfDriverEntry成员函数（Bind，Init，Release）。
    -   自定义结构体参考：

        从驱动的角度看，自定义结构体是参数和数据的载体，而且sdio\_config.hcs文件中的数值会被HDF读入通过DeviceResourceIface来初始化结构体成员，一些重要数值也会传递给核心层对象。

        ```
        typedef struct {
            uint32_t maxBlockNum;    // 单个request最大的block个数
            uint32_t maxBlockSize;   // 单个block最大的字节数1~2048
            uint32_t maxRequestSize; // 单个request最大的字节数 1~2048
            uint32_t enTimeout;      // 最大超时时间，单位毫秒，且不能超过一秒
            uint32_t funcNum;        // 函数编号1~7
            uint32_t irqCap;         // 中断能力
            void *data;              // 私有数据
        } SdioFuncInfo;
        
        //SdioDevice是核心层控制器结构体，其中的成员在Bind函数中会被赋值
        struct SdioDevice {
            struct SdDevice sd;
            struct SdioDeviceOps *sdioOps;
            struct SdioRegister sdioReg;
            uint32_t functions;
            struct SdioFunction *sdioFunc[SDIO_MAX_FUNCTION_NUMBER];
            struct SdioFunction *curFunction;
            struct OsalThread thread;  /* irq thread */
            struct OsalSem sem;
            bool irqPending;
            bool threadRunning;
        };
        ```

    -   SdioDevice成员回调函数结构体SdioDeviceOps的实例化，其他成员在Init函数中初始化。

        ```
        static struct SdioDeviceOps g_sdioDeviceOps = {
            .incrAddrReadBytes   = Hi35xxLinuxSdioIncrAddrReadBytes,
            .incrAddrWriteBytes  = Hi35xxLinuxSdioIncrAddrWriteBytes,
            .fixedAddrReadBytes  = Hi35xxLinuxSdioFixedAddrReadBytes,
            .fixedAddrWriteBytes = Hi35xxLinuxSdioFixedAddrWriteBytes,
            .func0ReadBytes  = Hi35xxLinuxSdioFunc0ReadBytes,
            .func0WriteBytes = Hi35xxLinuxSdioFunc0WriteBytes,
            .setBlockSize    = Hi35xxLinuxSdioSetBlockSize,
            .getCommonInfo   = Hi35xxLinuxSdioGetCommonInfo,
            .setCommonInfo   = Hi35xxLinuxSdioSetCommonInfo,
            .flushData       = Hi35xxLinuxSdioFlushData,
            .enableFunc      = Hi35xxLinuxSdioEnableFunc,
            .disableFunc = Hi35xxLinuxSdioDisableFunc,
            .claimIrq    = Hi35xxLinuxSdioClaimIrq,
            .releaseIrq  = Hi35xxLinuxSdioReleaseIrq,
            .findFunc    = Hi35xxLinuxSdioFindFunc,
            .claimHost   = Hi35xxLinuxSdioClaimHost,
            .releaseHost = Hi35xxLinuxSdioReleaseHost,
        };
        ```

    -   Bind函数参考

        入参：

        HdfDeviceObject 是整个驱动对外暴露的接口参数，具备 HCS 配置文件的信息。

        返回值：

        HDF\_STATUS相关状态 （下表为部分展示，如需使用其他状态，可见//drivers/framework/include/utils/hdf\_base.h中HDF\_STATUS 定义）。

        **表 2**  Bind函数入参及返回值

        <a name="table297118388199"></a>
        <table><thead align="left"><tr id="row197133831916"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p1972138191917"><a name="p1972138191917"></a><a name="p1972138191917"></a>状态(值)</p>
        </th>
        <th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p197213387192"><a name="p197213387192"></a><a name="p197213387192"></a>问题描述</p>
        </th>
        </tr>
        </thead>
        <tbody><tr id="row20972538191911"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p99721238181910"><a name="p99721238181910"></a><a name="p99721238181910"></a>HDF_ERR_INVALID_OBJECT</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1097243811914"><a name="p1097243811914"></a><a name="p1097243811914"></a>控制器对象非法</p>
        </td>
        </tr>
        <tr id="row5972203811199"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p16972838151919"><a name="p16972838151919"></a><a name="p16972838151919"></a>HDF_ERR_MALLOC_FAIL</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1397223817192"><a name="p1397223817192"></a><a name="p1397223817192"></a>内存分配失败</p>
        </td>
        </tr>
        <tr id="row14972173831913"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p7972538131919"><a name="p7972538131919"></a><a name="p7972538131919"></a>HDF_ERR_INVALID_PARAM</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p15972138191913"><a name="p15972138191913"></a><a name="p15972138191913"></a>参数非法</p>
        </td>
        </tr>
        <tr id="row59721938131918"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p199733380196"><a name="p199733380196"></a><a name="p199733380196"></a>HDF_ERR_IO</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p179731038101914"><a name="p179731038101914"></a><a name="p179731038101914"></a>I/O 错误</p>
        </td>
        </tr>
        <tr id="row1797316382198"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p16973203812195"><a name="p16973203812195"></a><a name="p16973203812195"></a>HDF_SUCCESS</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p297318386196"><a name="p297318386196"></a><a name="p297318386196"></a>初始化成功</p>
        </td>
        </tr>
        <tr id="row16973838151918"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1497353819191"><a name="p1497353819191"></a><a name="p1497353819191"></a>HDF_FAILURE</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p109732038171917"><a name="p109732038171917"></a><a name="p109732038171917"></a>初始化失败</p>
        </td>
        </tr>
        </tbody>
        </table>

        函数说明：

        初始化自定义结构体对象，初始化SdioCntlr成员，调用核心层SdioCntlrAdd函数，以及其他厂商自定义初始化操作。

        ```
        static int32_t Hi35xxLinuxSdioBind(struct HdfDeviceObject *obj)
        {
            struct MmcCntlr *cntlr = NULL;
            int32_t ret;
            ...
            cntlr = (struct MmcCntlr *)OsalMemCalloc(sizeof(struct MmcCntlr));// 分配内存
            ...
            cntlr->ops = &g_sdioCntlrOps;  //【必要】struct MmcCntlrOps g_sdioCntlrOps={
                                           // .rescanSdioDev = Hi35xxLinuxSdioRescan,};
            cntlr->hdfDevObj = obj;        //【必要】使HdfDeviceObject与MmcCntlr可以相互转化的前提
            obj->service = &cntlr->service;//【必要】使HdfDeviceObject与MmcCntlr可以相互转化的前提    
            ret = Hi35xxLinuxSdioCntlrParse(cntlr, obj);//【必要】初始化cntlr 的 index, devType, 失败则 goto _ERR;
            ...
            ret = MmcCntlrAdd(cntlr);       //【必要】调用核心层mmc_core.c的函数， 失败则 goto _ERR;
            ...
            ret = MmcCntlrAllocDev(cntlr, (enum MmcDevType)cntlr->devType);//【必要】调用核心层mmc_core.c的函数， 失败则 goto _ERR;
            ...
            
            MmcDeviceAddOps(cntlr->curDev, &g_sdioDeviceOps);//【必要】调用核心层mmc_core.c的函数， 钩子函数挂载
            HDF_LOGD("Hi35xxLinuxSdioBind: Success!");
            return HDF_SUCCESS;
        
        _ERR:
            Hi35xxLinuxSdioDeleteCntlr(cntlr);
            HDF_LOGE("Hi35xxLinuxSdioBind: Fail!");
            return HDF_FAILURE;
        }
        ```

    -   Init函数参考

        入参：

        HdfDeviceObject 是整个驱动对外暴露的接口参数，具备 HCS 配置文件的信息。

        返回值：

        HDF\_STATUS相关状态。

        函数说明：

        无操作，可根据厂商需要添加。

        ```
        static int32_t Hi35xxLinuxSdioInit(struct HdfDeviceObject *obj)
        {
            (void)obj;//无操作，可根据厂商需要添加
            HDF_LOGD("Hi35xxLinuxSdioInit: Success!");
            return HDF_SUCCESS;
        }
        ```

    -   Release函数参考

        入参：

        HdfDeviceObject 是整个驱动对外暴露的接口参数，具备 HCS 配置文件的信息。

        返回值：

        无。

        函数说明：

        释放内存和删除控制器，该函数需要在驱动入口结构体中赋值给 Release 接口， 当HDF框架调用Init函数初始化驱动失败时，可以调用 Release 释放驱动资源。所有强制转换获取相应对象的操作前提是在Bind函数中具备对应赋值的操作。

        ```
        static void Hi35xxLinuxSdioRelease(struct HdfDeviceObject *obj)
        {
            if (obj == NULL) {
                return;
            }
            Hi35xxLinuxSdioDeleteCntlr((struct MmcCntlr *)obj->service);//【必要】自定义的内存释放函数,这里有HdfDeviceObject到MmcCntlr的强制转化
        }
        ```



