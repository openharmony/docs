# SDIO<a name="EN-US_TOPIC_0000001199682295"></a>


## Overview<a name="section1347805272150053"></a>

A Secure Digital Input Output \(SDIO\) card is an extension of the SD specification to cover I/O functions. SD and SDIO are called multimedia card \(MMCs\). In the Hardware Driver Foundation \(HDF\) framework, the SDIO module uses the independent service mode for API adaptation. In this mode, each device independently publishes a device service to handle external access requests. After receiving an access request from an API, the device manager extracts the parameters in the request to call the internal method of the target device. In the independent service mode, the service management capabilities of the HDFDeviceManager can be directly used. However, you need to configure a device node for each device, which increases the memory usage.

**Figure  1**  Independent service mode<a name="fig124181331222"></a>  
![](figures/independent-service-mode.png "independent-service-mode-12")

## Available APIs<a name="section752964871810"></a>

SdioDeviceOps

```
// Function template
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

**Table  1**  Callbacks for the members in the SdioDeviceOps structure

<a name="table878215448417"></a>
<table><thead align="left"><tr id="row17784344241"><th class="cellrowborder" valign="top" width="20%" id="mcps1.2.6.1.1"><p id="p67842444414"><a name="p67842444414"></a><a name="p67842444414"></a>Callback</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.2.6.1.2"><p id="p1978411444416"><a name="p1978411444416"></a><a name="p1978411444416"></a>Input Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.2.6.1.3"><p id="p87841441243"><a name="p87841441243"></a><a name="p87841441243"></a>Output Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.2.6.1.4"><p id="p12784174417415"><a name="p12784174417415"></a><a name="p12784174417415"></a>Return Value</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.2.6.1.5"><p id="p16784104418413"><a name="p16784104418413"></a><a name="p16784104418413"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row8784144449"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p1378415443418"><a name="p1378415443418"></a><a name="p1378415443418"></a>incrAddrReadBytes</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p13126132382019"><a name="p13126132382019"></a><a name="p13126132382019"></a><strong id="b5125152392019"><a name="b5125152392019"></a><a name="b5125152392019"></a>dev</strong>: structure pointer to the SDIO device controller.</p>
<p id="p539123116208"><a name="p539123116208"></a><a name="p539123116208"></a><strong id="b239531132010"><a name="b239531132010"></a><a name="b239531132010"></a>addr</strong>: SDIO address, which is of the uint32_t type.</p>
<p id="p177857442043"><a name="p177857442043"></a><a name="p177857442043"></a><strong id="b10613113712815"><a name="b10613113712815"></a><a name="b10613113712815"></a>size</strong>: size of the data to read, which is of the uint32_t type.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p207851447410"><a name="p207851447410"></a><a name="p207851447410"></a><strong id="b77141033182915"><a name="b77141033182915"></a><a name="b77141033182915"></a>data</strong>: pointer to the output value, which is of the uint8_t type.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p167851644547"><a name="p167851644547"></a><a name="p167851644547"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p37855441645"><a name="p37855441645"></a><a name="p37855441645"></a>Incrementally reads data of a given length from the specified SDIO address.</p>
</td>
</tr>
<tr id="row197851446413"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p5785174419412"><a name="p5785174419412"></a><a name="p5785174419412"></a>incrAddrWriteBytes</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p13541153612013"><a name="p13541153612013"></a><a name="p13541153612013"></a><strong id="b6541103617209"><a name="b6541103617209"></a><a name="b6541103617209"></a>dev</strong>: structure pointer to the SDIO device controller.</p>
<p id="p1455963952010"><a name="p1455963952010"></a><a name="p1455963952010"></a><strong id="b165592039142016"><a name="b165592039142016"></a><a name="b165592039142016"></a>data</strong>: pointer to the input value, which is of the uint8_t type.</p>
<p id="p7565542172010"><a name="p7565542172010"></a><a name="p7565542172010"></a><strong id="b0565342182016"><a name="b0565342182016"></a><a name="b0565342182016"></a>addr</strong>: SDIO address, which is of the uint32_t type.</p>
<p id="p078554411417"><a name="p078554411417"></a><a name="p078554411417"></a><strong id="b1773173211314"><a name="b1773173211314"></a><a name="b1773173211314"></a>size</strong>: size of the data to write, which is of the uint32_t type.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p678519441748"><a name="p678519441748"></a><a name="p678519441748"></a>–</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p778594419416"><a name="p778594419416"></a><a name="p778594419416"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p67851444445"><a name="p67851444445"></a><a name="p67851444445"></a>Incrementally writes data of a given length to the specified SDIO address.</p>
</td>
</tr>
<tr id="row11785154419412"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p978514412418"><a name="p978514412418"></a><a name="p978514412418"></a>fixedAddrReadBytes</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p35454464204"><a name="p35454464204"></a><a name="p35454464204"></a><strong id="b3545746122016"><a name="b3545746122016"></a><a name="b3545746122016"></a>dev</strong>: structure pointer to the SDIO device controller.</p>
<p id="p98261449132010"><a name="p98261449132010"></a><a name="p98261449132010"></a><strong id="b182684922010"><a name="b182684922010"></a><a name="b182684922010"></a>addr</strong>: SDIO address, which is of the uint32_t type.</p>
<p id="p4926105372014"><a name="p4926105372014"></a><a name="p4926105372014"></a><strong id="b10926175314206"><a name="b10926175314206"></a><a name="b10926175314206"></a>size</strong>: size of the data to read, which is of the uint32_t type.</p>
<p id="p15786144419415"><a name="p15786144419415"></a><a name="p15786144419415"></a><strong id="b17163219183711"><a name="b17163219183711"></a><a name="b17163219183711"></a>scatterLen</strong>: data length, which is of the uint32_t type.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p9786124418414"><a name="p9786124418414"></a><a name="p9786124418414"></a><strong id="b14137104917373"><a name="b14137104917373"></a><a name="b14137104917373"></a>data</strong>: pointer to the output value, which is of the uint8_t type.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p2078614441842"><a name="p2078614441842"></a><a name="p2078614441842"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p107861744143"><a name="p107861744143"></a><a name="p107861744143"></a>Reads data of a given length from a fixed SDIO address.</p>
</td>
</tr>
<tr id="row278618441241"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p137861244448"><a name="p137861244448"></a><a name="p137861244448"></a>fixedAddrWriteBytes</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p1080445917207"><a name="p1080445917207"></a><a name="p1080445917207"></a><strong id="b380445918202"><a name="b380445918202"></a><a name="b380445918202"></a>dev</strong>: structure pointer to the SDIO device controller.</p>
<p id="p0833423219"><a name="p0833423219"></a><a name="p0833423219"></a><strong id="b1583316216211"><a name="b1583316216211"></a><a name="b1583316216211"></a>data</strong>: pointer to the input value, which is of the uint8_t type.</p>
<p id="p6700146102112"><a name="p6700146102112"></a><a name="p6700146102112"></a><strong id="b117001967218"><a name="b117001967218"></a><a name="b117001967218"></a>addr</strong>: SDIO address, which is of the uint32_t type.</p>
<p id="p1068901013214"><a name="p1068901013214"></a><a name="p1068901013214"></a><strong id="b368914103212"><a name="b368914103212"></a><a name="b368914103212"></a>size</strong>: size of the data to write, which is of the uint32_t type.</p>
<p id="p77861444341"><a name="p77861444341"></a><a name="p77861444341"></a><strong id="b1654516614113"><a name="b1654516614113"></a><a name="b1654516614113"></a>scatterLen</strong>: data length, which is of the uint32_t type.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p5786244345"><a name="p5786244345"></a><a name="p5786244345"></a>–</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p147868442416"><a name="p147868442416"></a><a name="p147868442416"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p1478615441948"><a name="p1478615441948"></a><a name="p1478615441948"></a>Writes data of a given length to the fixed SDIO address.</p>
</td>
</tr>
<tr id="row1078694416418"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p12786154414413"><a name="p12786154414413"></a><a name="p12786154414413"></a>func0ReadBytes</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p97041515162116"><a name="p97041515162116"></a><a name="p97041515162116"></a><strong id="b470412150211"><a name="b470412150211"></a><a name="b470412150211"></a>dev</strong>: structure pointer to the SDIO device controller.</p>
<p id="p1029871817216"><a name="p1029871817216"></a><a name="p1029871817216"></a><strong id="b17298191818216"><a name="b17298191818216"></a><a name="b17298191818216"></a>addr</strong>: SDIO address, which is of the uint32_t type.</p>
<p id="p4786244541"><a name="p4786244541"></a><a name="p4786244541"></a><strong id="b207721914423"><a name="b207721914423"></a><a name="b207721914423"></a>size</strong>: size of the data to read, which is of the uint32_t type.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p37868445420"><a name="p37868445420"></a><a name="p37868445420"></a><strong id="b8335193874220"><a name="b8335193874220"></a><a name="b8335193874220"></a>data</strong>: pointer to the output value, which is of the uint8_t type.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p197874442416"><a name="p197874442416"></a><a name="p197874442416"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p107877441146"><a name="p107877441146"></a><a name="p107877441146"></a>Reads data of a given length from the address space of SDIO function 0.</p>
</td>
</tr>
<tr id="row1478794415414"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p12787644548"><a name="p12787644548"></a><a name="p12787644548"></a>func0WriteBytes</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p11251122313211"><a name="p11251122313211"></a><a name="p11251122313211"></a><strong id="b625117238213"><a name="b625117238213"></a><a name="b625117238213"></a>dev</strong>: structure pointer to the SDIO device controller.</p>
<p id="p172811926172111"><a name="p172811926172111"></a><a name="p172811926172111"></a><strong id="b528102618213"><a name="b528102618213"></a><a name="b528102618213"></a>data</strong>: pointer to the input value, which is of the uint8_t type.</p>
<p id="p17651829162116"><a name="p17651829162116"></a><a name="p17651829162116"></a><strong id="b1465142962118"><a name="b1465142962118"></a><a name="b1465142962118"></a>addr</strong>: SDIO address, which is of the uint32_t type.</p>
<p id="p67871544242"><a name="p67871544242"></a><a name="p67871544242"></a><strong id="b394817346436"><a name="b394817346436"></a><a name="b394817346436"></a>size</strong>: size of the data to write, which is of the uint32_t type.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p678774413416"><a name="p678774413416"></a><a name="p678774413416"></a>–</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p207871944648"><a name="p207871944648"></a><a name="p207871944648"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p57876441415"><a name="p57876441415"></a><a name="p57876441415"></a>Writes data of a given length to the address space of SDIO function 0.</p>
</td>
</tr>
<tr id="row157871441145"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p1878714442417"><a name="p1878714442417"></a><a name="p1878714442417"></a>setBlockSize</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p16155033152118"><a name="p16155033152118"></a><a name="p16155033152118"></a><strong id="b71556330213"><a name="b71556330213"></a><a name="b71556330213"></a>dev</strong>: structure pointer to the SDIO device controller.</p>
<p id="p187872445410"><a name="p187872445410"></a><a name="p187872445410"></a><strong id="b12844183820441"><a name="b12844183820441"></a><a name="b12844183820441"></a>blockSize</strong>: block size, which is of the uint32_t type.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p77878444415"><a name="p77878444415"></a><a name="p77878444415"></a>–</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p37871244243"><a name="p37871244243"></a><a name="p37871244243"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p378710441647"><a name="p378710441647"></a><a name="p378710441647"></a>Sets the block size.</p>
</td>
</tr>
<tr id="row15787344349"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p878819441048"><a name="p878819441048"></a><a name="p878819441048"></a>getCommonInfo</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p114691537132117"><a name="p114691537132117"></a><a name="p114691537132117"></a><strong id="b6469143713211"><a name="b6469143713211"></a><a name="b6469143713211"></a>dev</strong>: structure pointer to the SDIO device controller.</p>
<p id="p1078820442419"><a name="p1078820442419"></a><a name="p1078820442419"></a><strong id="b12145522184712"><a name="b12145522184712"></a><a name="b12145522184712"></a>infoType</strong>: info type, which is of the uint32_t type.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p678814411418"><a name="p678814411418"></a><a name="p678814411418"></a><strong id="b83512634819"><a name="b83512634819"></a><a name="b83512634819"></a>info</strong>: structure pointer to the output <strong id="b59131139164813"><a name="b59131139164813"></a><a name="b59131139164813"></a>SdioFuncInfo</strong>.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p1578894410419"><a name="p1578894410419"></a><a name="p1578894410419"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p7788444140"><a name="p7788444140"></a><a name="p7788444140"></a>Obtains <strong id="b176819272491"><a name="b176819272491"></a><a name="b176819272491"></a>CommonInfo</strong>. For details, see the <strong id="b1127411492595"><a name="b1127411492595"></a><a name="b1127411492595"></a>NOTE</strong> below this table.</p>
</td>
</tr>
<tr id="row7788154410416"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p6788104410419"><a name="p6788104410419"></a><a name="p6788104410419"></a>setCommonInfo</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p10540104472112"><a name="p10540104472112"></a><a name="p10540104472112"></a><strong id="b1954014420218"><a name="b1954014420218"></a><a name="b1954014420218"></a>dev</strong>: structure pointer to the SDIO device controller.</p>
<p id="p9107164817213"><a name="p9107164817213"></a><a name="p9107164817213"></a><strong id="b410734816213"><a name="b410734816213"></a><a name="b410734816213"></a>info</strong>: union pointer to the input <strong id="b610774812211"><a name="b610774812211"></a><a name="b610774812211"></a>SdioFuncInfo</strong>.</p>
<p id="p2078815442417"><a name="p2078815442417"></a><a name="p2078815442417"></a><strong id="b138611646185019"><a name="b138611646185019"></a><a name="b138611646185019"></a>infoType</strong>: info type, which is of the uint32_t type.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p13788644043"><a name="p13788644043"></a><a name="p13788644043"></a>–</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p19788134418420"><a name="p19788134418420"></a><a name="p19788134418420"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p1278814415412"><a name="p1278814415412"></a><a name="p1278814415412"></a>Sets <strong id="b840010395517"><a name="b840010395517"></a><a name="b840010395517"></a>CommonInfo</strong>. For details, see the <strong id="b44901724012"><a name="b44901724012"></a><a name="b44901724012"></a>NOTE</strong> below this table.</p>
</td>
</tr>
<tr id="row1788344744"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p2078819441745"><a name="p2078819441745"></a><a name="p2078819441745"></a>flushData</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p67888441442"><a name="p67888441442"></a><a name="p67888441442"></a><strong id="b4882145105215"><a name="b4882145105215"></a><a name="b4882145105215"></a>dev</strong>: structure pointer to the SDIO device controller.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p1478812441147"><a name="p1478812441147"></a><a name="p1478812441147"></a>–</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p3789174418420"><a name="p3789174418420"></a><a name="p3789174418420"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p578912441445"><a name="p578912441445"></a><a name="p578912441445"></a>Calls the function when the SDIO device needs to be re-initialized or an error occurs.</p>
</td>
</tr>
<tr id="row19789244142"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p778913441417"><a name="p778913441417"></a><a name="p778913441417"></a>enableFunc</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p12789144418412"><a name="p12789144418412"></a><a name="p12789144418412"></a><strong id="b1029151718538"><a name="b1029151718538"></a><a name="b1029151718538"></a>dev</strong>: structure pointer to the SDIO device controller.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p678964419417"><a name="p678964419417"></a><a name="p678964419417"></a>–</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p97891744946"><a name="p97891744946"></a><a name="p97891744946"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p127891445415"><a name="p127891445415"></a><a name="p127891445415"></a>Enables the SDIO device.</p>
</td>
</tr>
<tr id="row177898441647"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p978917447412"><a name="p978917447412"></a><a name="p978917447412"></a>disableFunc</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p1978911449418"><a name="p1978911449418"></a><a name="p1978911449418"></a><strong id="b529982985311"><a name="b529982985311"></a><a name="b529982985311"></a>dev</strong>: structure pointer to the SDIO device controller.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p57898448413"><a name="p57898448413"></a><a name="p57898448413"></a>–</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p77893441341"><a name="p77893441341"></a><a name="p77893441341"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p1479019449414"><a name="p1479019449414"></a><a name="p1479019449414"></a>Disables the SDIO device.</p>
</td>
</tr>
<tr id="row17908444415"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p1279017441140"><a name="p1279017441140"></a><a name="p1279017441140"></a>claimIrq</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p1867751642210"><a name="p1867751642210"></a><a name="p1867751642210"></a><strong id="b12677816192216"><a name="b12677816192216"></a><a name="b12677816192216"></a>dev</strong>: structure pointer to the SDIO device controller.</p>
<p id="p1279018442419"><a name="p1279018442419"></a><a name="p1279018442419"></a><strong id="b471593695213"><a name="b471593695213"></a><a name="b471593695213"></a>irqHandler</strong>: void function pointer to the IRQ handler.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p379084411411"><a name="p379084411411"></a><a name="p379084411411"></a>–</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p1179074410416"><a name="p1179074410416"></a><a name="p1179074410416"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p6790124418410"><a name="p6790124418410"></a><a name="p6790124418410"></a>Claims an SDIO IRQ.</p>
</td>
</tr>
<tr id="row177909441647"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p77900441411"><a name="p77900441411"></a><a name="p77900441411"></a>releaseIrq</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p27902441414"><a name="p27902441414"></a><a name="p27902441414"></a><strong id="b143101291537"><a name="b143101291537"></a><a name="b143101291537"></a>dev</strong>: structure pointer to the SDIO device controller.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p87906441742"><a name="p87906441742"></a><a name="p87906441742"></a>–</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p147906446419"><a name="p147906446419"></a><a name="p147906446419"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p77901544440"><a name="p77901544440"></a><a name="p77901544440"></a>Releases an SDIO IRQ.</p>
</td>
</tr>
<tr id="row97906449416"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p579024419411"><a name="p579024419411"></a><a name="p579024419411"></a>findFunc</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p181282417222"><a name="p181282417222"></a><a name="p181282417222"></a><strong id="b81210244229"><a name="b81210244229"></a><a name="b81210244229"></a>dev</strong>: structure pointer to the SDIO device controller.</p>
<p id="p5791184417414"><a name="p5791184417414"></a><a name="p5791184417414"></a><strong id="b34537192557"><a name="b34537192557"></a><a name="b34537192557"></a>configData</strong>: structure pointer to the key SDIO function information.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p1079112441345"><a name="p1079112441345"></a><a name="p1079112441345"></a>–</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p17916446420"><a name="p17916446420"></a><a name="p17916446420"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p779119441549"><a name="p779119441549"></a><a name="p779119441549"></a>Obtains the matching funcNum.</p>
</td>
</tr>
<tr id="row779116446417"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p679119448412"><a name="p679119448412"></a><a name="p679119448412"></a>claimHost</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p179116441547"><a name="p179116441547"></a><a name="p179116441547"></a><strong id="b931692913535"><a name="b931692913535"></a><a name="b931692913535"></a>dev</strong>: structure pointer to the SDIO device controller.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p97911144944"><a name="p97911144944"></a><a name="p97911144944"></a>–</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p12791244341"><a name="p12791244341"></a><a name="p12791244341"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p5791134412417"><a name="p5791134412417"></a><a name="p5791134412417"></a>Claims a host exclusively.</p>
</td>
</tr>
<tr id="row47911344746"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p279113441046"><a name="p279113441046"></a><a name="p279113441046"></a>releaseHost</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p67916449413"><a name="p67916449413"></a><a name="p67916449413"></a><strong id="b1632011295536"><a name="b1632011295536"></a><a name="b1632011295536"></a>dev</strong>: structure pointer to the SDIO device controller.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p37916441244"><a name="p37916441244"></a><a name="p37916441244"></a>–</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p97911044948"><a name="p97911044948"></a><a name="p97911044948"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p1792184413412"><a name="p1792184413412"></a><a name="p1792184413412"></a>Releases the exclusively claimed host.</p>
</td>
</tr>
</tbody>
</table>

>![](../public_sys-resources/icon-note.gif) **NOTE** 

>CommonInfo includes the following information:
>-   **maxBlockNum**: specifies the maximum number of blocks in a request.
>-   **maxBlockSize**: specifies the maximum number of bytes in a block.
>-   **maxRequestSize**: specifies the maximum number of bytes in a request.
>-   **enTimeout**: specifies the maximum timeout period, in milliseconds.
>-   **funcNum**: specifies the function number, which ranges from  **1**  to  **7**.
>-   **irqCap**: specifies the interrupt request \(IRQ\) capabilities.
>-   **\(void \*\)data**

## How to Develop<a name="section581179475150053"></a>

The SDIO module adaptation involves the following steps:

1.  Instantiate the driver entry.
    -   Instantiate the  **HdfDriverEntry**  structure.
    -   Call  **HDF\_INIT**  to register the  **HdfDriverEntry**  instance with the HDF.

2.  Configure attribute files.
    -   Add the  **deviceNode**  information to the  **device\_info.hcs**  file.
    -   \(Optional\) Add the  **sdio\_config.hcs**  file.

3.  Instantiate the SDIO controller object.
    -   Initialize  **SdioDevice**.
    -   Instantiate  **SdioDeviceOps**  in the  **SdioDevice**  object.

        >![](../public_sys-resources/icon-note.gif) **NOTE** 

        >For details, see [Available APIs](#available-apis).


4.  Debug the driver.
    -   \(Optional\) For new drivers, verify the basic functions, such as the SDIO control status and response to interrupts.


## Development Example<a name="section2112250242150053"></a>

The following uses  **sdio\_adapter.c**  as an example to present the contents that need to be provided by the vendor to implement device functions.

1.  Instantiate the driver entry. The driver entry must be a global variable of the  **HdfDriverEntry**  type \(defined in  **hdf\_device\_desc.h**\), and the value of  **moduleName**  must be the same as that in  **device\_info.hcs**. In the HDF, the start address of each  **HdfDriverEntry**  object of all loaded drivers is collected to form a segment address space similar to an array for the upper layer to invoke.

    Generally, HDF calls the  **Bind**  function and then the  **Init**  function to load a driver. If  **Init**  fails to be called, HDF calls  **Release**  to release driver resources and exit.

    -   SDIO driver entry reference

        ```
        struct HdfDriverEntry g_sdioDriverEntry = {
            .moduleVersion = 1,
                .Bind = Hi35xxLinuxSdioBind,       // See the Bind function.
          .Init = Hi35xxLinuxSdioInit,       // See the Init function.
            .Release = Hi35xxLinuxSdioRelease// See the Release function.
           .moduleName = "HDF_PLATFORM_SDIO",// (Mandatory) The value must be the same as that of moduleName in the .hcs file.
        };
        // Call HDF_INIT to register the driver entry with the HDF.
        HDF_INIT(g_sdioDriverEntry);
        ```

2.  Add the  **deviceNode**  information to the  **device\_info.hcs**  file and configure the device attributes in the  **sdio\_config.hcs**  file. The  **deviceNode**  information is related to registration of the driver entry. The device attribute values are closely related to the default values or value ranges of the  **SdioDevice**  members at the core layer.

    In this example, there is only one SDIO controller. If there are multiple SDIO controllers, you need to add the  **deviceNode**  information to the  **device\_info**  file and add the corresponding device attributes to the  **sdio\_config**  file.

    -   **device\_info.hcs**  configuration reference

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
                 moduleName = "HDF_PLATFORM_SDIO"; // (Mandatory) Driver name, which must be the same as the moduleName in the driver entry.
                 serviceName = "HDF_PLATFORM_MMC_2"; // (Mandatory) Unique name of the service published by the driver
                deviceMatchAttr = "hisilicon_hi35xx_sdio_0";// (Mandatory) Used to configure the private data of the controller. The value must be the same as the controller in sdio_config.hcs.
                }
              }
            }
          }
        }
        ```

    -   **sdio\_config.hcs**  configuration reference

        ```
        root {
          platform {
            sdio_config {
              template sdio_controller {
                match_attr = "";
                hostId = 2; // (Mandatory) It is set to 2. For details, see mmc_config.hcs.
                devType = 2; // (Mandatory) It is set to 2. For details, see mmc_config.hcs.
              }
              controller_0x2dd1 :: sdio_controller {
                  match_attr = "hisilicon_hi35xx_sdio_0";// (Mandatory) The value must be the same as that of deviceMatchAttr in device_info.hcs.
            }
          }
        }
        ```

3.  Initialize the  **SdioDevice**  object at the core layer, including initializing the vendor custom structure \(transferring parameters and data\), instantiating  **SdioDeviceOps**  \(used to call underlying functions of the driver\) in  **SdioDevice**, and implementing the  **HdfDriverEntry**  member functions \(**Bind**,  **Init**, and  **Release**\).

    -   Custom structure reference

        To the driver, the custom structure carries parameters and data. The values in the  **sdio\_config.hcs**  file are read by HDF, and the structure members are initialized through  **DeviceResourceIface**. Some important values are also passed to the objects at the core layer.

        ```
        typedef struct {
            uint32_t maxBlockNum; // Maximum number of blocks in a request.
            uint32_t maxBlockSize; // Maximum number of bytes in a block. The value range is 1 to 2048.
            uint32_t maxRequestSize; // Maximum number of bytes in a request. The value range is 1 to 2048.
            uint32_t enTimeout; // Maximum timeout period in milliseconds. The value cannot exceed one second.
            uint32_t funcNum; // Function number, which ranges from 1 to 7.
            uint32_t irqCap;         // IRQ capabilities.
            void *data;             // Private data.
        } SdioFuncInfo;
        
        // SdioDevice is the core layer controller structure. Its members are assigned with values by using the Bind function.
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

    -   Instantiate the callback function structure  **SdioDeviceOps**  in  **SdioDevice**. Other members are initialized by using the  **Init**  function.

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

    -   Bind function

        Input parameters:

        **HdfDeviceObject**, an interface parameter exposed by the driver, contains the .hcs configuration file information.

        Return values:

        HDF\_STATUS \(The following table lists some status. For details about other status, see  **HDF\_STATUS**  in the  **//drivers/framework/include/utils/hdf\_base.h**  file.\)

        **Table  2**  Input parameters and return values of the Bind function

        <a name="table297118388199"></a>
        <table><thead align="left"><tr id="row197133831916"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p1972138191917"><a name="p1972138191917"></a><a name="p1972138191917"></a>Status (Value)</p>
        </th>
        <th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p197213387192"><a name="p197213387192"></a><a name="p197213387192"></a>Description</p>
        </th>
        </tr>
        </thead>
        <tbody><tr id="row20972538191911"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p99721238181910"><a name="p99721238181910"></a><a name="p99721238181910"></a>HDF_ERR_INVALID_OBJECT</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1097243811914"><a name="p1097243811914"></a><a name="p1097243811914"></a>Invalid controller object</p>
        </td>
        </tr>
        <tr id="row5972203811199"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p16972838151919"><a name="p16972838151919"></a><a name="p16972838151919"></a>HDF_ERR_MALLOC_FAIL</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1397223817192"><a name="p1397223817192"></a><a name="p1397223817192"></a>Failed to allocate memory</p>
        </td>
        </tr>
        <tr id="row14972173831913"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p7972538131919"><a name="p7972538131919"></a><a name="p7972538131919"></a>HDF_ERR_INVALID_PARAM</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p15972138191913"><a name="p15972138191913"></a><a name="p15972138191913"></a>Invalid parameter</p>
        </td>
        </tr>
        <tr id="row59721938131918"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p199733380196"><a name="p199733380196"></a><a name="p199733380196"></a>HDF_ERR_IO</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p179731038101914"><a name="p179731038101914"></a><a name="p179731038101914"></a>I/O error</p>
        </td>
        </tr>
        <tr id="row1797316382198"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p16973203812195"><a name="p16973203812195"></a><a name="p16973203812195"></a>HDF_SUCCESS</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p297318386196"><a name="p297318386196"></a><a name="p297318386196"></a>Initialization successful</p>
        </td>
        </tr>
        <tr id="row16973838151918"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1497353819191"><a name="p1497353819191"></a><a name="p1497353819191"></a>HDF_FAILURE</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p109732038171917"><a name="p109732038171917"></a><a name="p109732038171917"></a>Initialization failed</p>
        </td>
        </tr>
        </tbody>
        </table>

        Function description:

        Initializes the custom structure object and  **SdioCntlr**, calls the  **SdioCntlrAdd**  function at the core layer, and performs other initialization operations customized by the vendor.

        ```
        static int32_t Hi35xxLinuxSdioBind(struct HdfDeviceObject *obj)
        {
            struct MmcCntlr *cntlr = NULL;
            int32_t ret;
            ...
         cntlr = (struct MmcCntlr *)OsalMemCalloc(sizeof(struct MmcCntlr));// Apply for memory.
            ...
            cntlr->ops = &g_sdioCntlrOps;  // (Mandatory) struct MmcCntlrOps g_sdioCntlrOps={
                                           // .rescanSdioDev = Hi35xxLinuxSdioRescan,};
            cntlr->hdfDevObj = obj; // (Mandatory) Enable conversion between HdfDeviceObject and MmcCntlr.
            obj->service = &cntlr->service; // (Mandatory) Enable conversion between HdfDeviceObject and MmcCntlr.
            ret = Hi35xxLinuxSdioCntlrParse(cntlr, obj);// (Mandatory) Initialize the index and devType of cntlr. If the initialization fails, execute goto _ERR.
            ...
            ret = MmcCntlrAdd(cntlr); // (Mandatory) Call the mmc_core.c function at the core layer. If the function fails to be called, execute goto _ERR.
            ...
               ret = MmcCntlrAllocDev(cntlr, (enum MmcDevType)cntlr->devType);// (Mandatory) Call the mmc_core.c function at the core layer. If the function fails to be called, execute goto _ERR.
            ...
            
            MmcDeviceAddOps(cntlr->curDev, &g_sdioDeviceOps);// (Mandatory) Call the function of mmc_core.c at the core layer to instantiate the hook.
            HDF_LOGD("Hi35xxLinuxSdioBind: Success!");
            return HDF_SUCCESS;
        
        _ERR:
            Hi35xxLinuxSdioDeleteCntlr(cntlr);
            HDF_LOGE("Hi35xxLinuxSdioBind: Fail!");
            return HDF_FAILURE;
        }
        ```

    -   Init function

        Input parameters:

        **HdfDeviceObject**, an interface parameter exposed by the driver, contains the .hcs configuration file information.

        Return values:

        HDF\_STATUS

        Function description:

        No operation. The vendor can add operations as required.

        ```
        static int32_t Hi35xxLinuxSdioInit(struct HdfDeviceObject *obj)
        {
            (void)obj;// No operation. The vendor can add operations as required.
            HDF_LOGD("Hi35xxLinuxSdioInit: Success!");
            return HDF_SUCCESS;
        }
        ```

    -   Release function

        Input parameters:

        **HdfDeviceObject**, an interface parameter exposed by the driver, contains the .hcs configuration file information.

        Return values:

        –

        Function description:

        Releases the memory and deletes the controller. This function assigns a value to the  **Release**  API in the driver entry structure. When the HDF fails to call the  **Init**  function to initialize the driver, the  **Release**  function can be called to release driver resources. All forced conversion operations for obtaining the corresponding object can be successful only when the  **Bind**  function has the corresponding value assignment operations.


    ```
    static void Hi35xxLinuxSdioRelease(struct HdfDeviceObject *obj)
    {
        if (obj == NULL) {
            return;
        }
        Hi35xxLinuxSdioDeleteCntlr((struct MmcCntlr *)obj->service);// (Mandatory) Custom function for releasing memory. A forced conversion from HdfDeviceObject to MmcCntlr is involved.
    }
    ```


