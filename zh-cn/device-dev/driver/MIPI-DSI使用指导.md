# MIPI DSI使用指导<a name="ZH-CN_TOPIC_0000001063082539"></a>

-   [使用流程](#section8982671284)
-   [获取MIPI-DSI操作句柄](#section57982569176)
-   [MIPI-DSI相应配置](#section5935410201815)
-   [发送/回读控制指令](#section611661316194)
-   [释放MIPI-DSI操作句柄](#section217313211199)

## 使用流程<a name="section8982671284"></a>

使用MIPI-DSI的一般流程如[图1](#fig99821771782)所示。

**图 1**  MIPI-DSI使用流程图<a name="fig99821771782"></a>  


![](figures/zh-cn_image_0000001072553354.png)

## 获取MIPI-DSI操作句柄<a name="section57982569176"></a>

在进行MIPI-DSI进行通信前，首先要调用MipiDsiOpen获取操作句柄，该函数会返回指定通道ID的操作句柄。

DevHandle MipiDsiOpen\(uint8\_t id\);

**表 1**  MipiDsiOpen的参数和返回值描述

<a name="table7603619123820"></a>
<table><tbody><tr id="row1060351914386"><td class="cellrowborder" valign="top" width="20.66%"><p id="p14603181917382"><a name="p14603181917382"></a><a name="p14603181917382"></a><strong id="b16510829133012"><a name="b16510829133012"></a><a name="b16510829133012"></a>参数</strong></p>
</td>
<td class="cellrowborder" valign="top" width="79.34%"><p id="p36031519183819"><a name="p36031519183819"></a><a name="p36031519183819"></a><strong id="b65222293309"><a name="b65222293309"></a><a name="b65222293309"></a>参数描述</strong></p>
</td>
</tr>
<tr id="row960361918383"><td class="cellrowborder" valign="top" width="20.66%"><p id="p8603161903818"><a name="p8603161903818"></a><a name="p8603161903818"></a>id</p>
</td>
<td class="cellrowborder" valign="top" width="79.34%"><p id="p19603111916381"><a name="p19603111916381"></a><a name="p19603111916381"></a>MIPI DSI通道ID</p>
</td>
</tr>
<tr id="row11410612183019"><td class="cellrowborder" valign="top" width="20.66%"><p id="p460381915385"><a name="p460381915385"></a><a name="p460381915385"></a><strong id="b4349113243013"><a name="b4349113243013"></a><a name="b4349113243013"></a>返回值</strong></p>
</td>
<td class="cellrowborder" valign="top" width="79.34%"><p id="p96031619153812"><a name="p96031619153812"></a><a name="p96031619153812"></a><strong id="b63502322308"><a name="b63502322308"></a><a name="b63502322308"></a>返回值描述</strong></p>
</td>
</tr>
<tr id="row15410111273017"><td class="cellrowborder" valign="top" width="20.66%"><p id="p1060418195389"><a name="p1060418195389"></a><a name="p1060418195389"></a>NULL</p>
</td>
<td class="cellrowborder" valign="top" width="79.34%"><p id="p760471912388"><a name="p760471912388"></a><a name="p760471912388"></a>获取失败</p>
</td>
</tr>
<tr id="row1241081213303"><td class="cellrowborder" valign="top" width="20.66%"><p id="p5604719133811"><a name="p5604719133811"></a><a name="p5604719133811"></a>设备句柄</p>
</td>
<td class="cellrowborder" valign="top" width="79.34%"><p id="p3604181933818"><a name="p3604181933818"></a><a name="p3604181933818"></a>获取到指令通道的操作句柄, 类型为DevHandle</p>
</td>
</tr>
</tbody>
</table>

假设系统中的MIPI-DSI通道为0，获取该通道操作句柄的示例如下：

```
DevHandle mipiDsiHandle = NULL;  /* 设备句柄 */
chnId = 0;      /* MIPI-DSI通道ID */

/* 获取操作句柄 */
mipiDsiHandle = MipiDsiOpen(chnId);
if (mipiDsiHandle == NULL) {
    HDF_LOGE("MipiDsiOpen: failed\n");
    return;
}
```

## MIPI-DSI相应配置<a name="section5935410201815"></a>

-   写入MIPI-DSI配置

int32\_t MipiDsiSetCfg\(DevHandle handle, struct MipiCfg \*cfg\);

**表 2**  MipiDsiSetCfg的参数和返回值描述

<a name="table10692555281"></a>
<table><tbody><tr id="row116914559288"><td class="cellrowborder" valign="top" width="50%"><p id="p1169195516288"><a name="p1169195516288"></a><a name="p1169195516288"></a><strong id="b106965519281"><a name="b106965519281"></a><a name="b106965519281"></a>参数</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p769125512286"><a name="p769125512286"></a><a name="p769125512286"></a><strong id="b969105516280"><a name="b969105516280"></a><a name="b969105516280"></a>参数描述</strong></p>
</td>
</tr>
<tr id="row4691155142812"><td class="cellrowborder" valign="top" width="50%"><p id="p66935515288"><a name="p66935515288"></a><a name="p66935515288"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p863714348217"><a name="p863714348217"></a><a name="p863714348217"></a>操作句柄</p>
</td>
</tr>
<tr id="row469145572817"><td class="cellrowborder" valign="top" width="50%"><p id="p46915519287"><a name="p46915519287"></a><a name="p46915519287"></a>cfg</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p76995518289"><a name="p76995518289"></a><a name="p76995518289"></a>MIPI-DSI相应配置buf 指针</p>
</td>
</tr>
<tr id="row16913554284"><td class="cellrowborder" valign="top" width="50%"><p id="p16955512812"><a name="p16955512812"></a><a name="p16955512812"></a><strong id="b17691155152810"><a name="b17691155152810"></a><a name="b17691155152810"></a>返回值</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p206945502813"><a name="p206945502813"></a><a name="p206945502813"></a><strong id="b196955572818"><a name="b196955572818"></a><a name="b196955572818"></a>返回值描述</strong></p>
</td>
</tr>
<tr id="row146914556283"><td class="cellrowborder" valign="top" width="50%"><p id="p669175582818"><a name="p669175582818"></a><a name="p669175582818"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p169205511283"><a name="p169205511283"></a><a name="p169205511283"></a>设置成功</p>
</td>
</tr>
<tr id="row5694558283"><td class="cellrowborder" valign="top" width="50%"><p id="p269175516286"><a name="p269175516286"></a><a name="p269175516286"></a>负数</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p11691554280"><a name="p11691554280"></a><a name="p11691554280"></a>设置失败</p>
</td>
</tr>
</tbody>
</table>

```
int32_t ret;
struct MipiCfg cfg = {0};

/* 当前对接的屏幕配置如下 */
cfg.lane = DSI_4_LANES;
cfg.mode = DSI_CMD_MODE;
cfg.burstMode = VIDEO_NON_BURST_MODE_SYNC_EVENTS;
cfg.format = FORMAT_RGB_24_BIT;
cfg.pixelClk = 174;
cfg.phyDataRate = 384;
cfg.timingInfo.hsaPixels = 50;
cfg.timingInfo.hbpPixels = 55;
cfg.timingInfo.hlinePixels = 1200;
cfg.timingInfo.yResLines = 1800;
cfg.timingInfo.vbpLines = 33;
cfg.timingInfo.vsaLines = 76;
cfg.timingInfo.vfpLines = 120;
cfg.timingInfo.xResPixels = 1342;
/* 写入配置数据 */
ret = MipiDsiSetCfg(g_handle, &cfg);
if (ret != 0) {
    HDF_LOGE("%s: SetMipiCfg fail! ret=%d\n", __func__, ret);
    return -1;
}
```

-   获取当前MIPI-DSI的配置

int32\_t MipiDsiGetCfg\(DevHandle handle, struct MipiCfg \*cfg\);

**表 3**  MipiDsiGetCfg的参数和返回值描述

<a name="table7709554280"></a>
<table><tbody><tr id="row670115515282"><td class="cellrowborder" valign="top" width="50%"><p id="p470205515287"><a name="p470205515287"></a><a name="p470205515287"></a><strong id="b1770105522820"><a name="b1770105522820"></a><a name="b1770105522820"></a>参数</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p270755162817"><a name="p270755162817"></a><a name="p270755162817"></a><strong id="b170165512817"><a name="b170165512817"></a><a name="b170165512817"></a>参数描述</strong></p>
</td>
</tr>
<tr id="row57014555286"><td class="cellrowborder" valign="top" width="50%"><p id="p11701155172815"><a name="p11701155172815"></a><a name="p11701155172815"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p57015510283"><a name="p57015510283"></a><a name="p57015510283"></a>操作句柄</p>
</td>
</tr>
<tr id="row1870155192815"><td class="cellrowborder" valign="top" width="50%"><p id="p137115572815"><a name="p137115572815"></a><a name="p137115572815"></a>cfg</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p771195522818"><a name="p771195522818"></a><a name="p771195522818"></a>MIPI-DSI相应配置buf 指针</p>
</td>
</tr>
<tr id="row12718555283"><td class="cellrowborder" valign="top" width="50%"><p id="p1871175515289"><a name="p1871175515289"></a><a name="p1871175515289"></a><strong id="b871185592819"><a name="b871185592819"></a><a name="b871185592819"></a>返回值</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p771955182813"><a name="p771955182813"></a><a name="p771955182813"></a><strong id="b147175532813"><a name="b147175532813"></a><a name="b147175532813"></a>返回值描述</strong></p>
</td>
</tr>
<tr id="row1071155582812"><td class="cellrowborder" valign="top" width="50%"><p id="p6718551282"><a name="p6718551282"></a><a name="p6718551282"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p171195516285"><a name="p171195516285"></a><a name="p171195516285"></a>获取成功</p>
</td>
</tr>
<tr id="row97135519282"><td class="cellrowborder" valign="top" width="50%"><p id="p11711355162815"><a name="p11711355162815"></a><a name="p11711355162815"></a>负数</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p77116555286"><a name="p77116555286"></a><a name="p77116555286"></a>获取失败</p>
</td>
</tr>
</tbody>
</table>

```
int32_t ret;
struct MipiCfg cfg;
memset(&cfg, 0, sizeof(struct MipiCfg));
ret = MipiDsiGetCfg(g_handle, &cfg);
if (ret != HDF_SUCCESS) {
    HDF_LOGE("%s: GetMipiCfg fail!\n", __func__);
    return HDF_FAILURE;
}
```

## 发送/回读控制指令<a name="section611661316194"></a>

-   发送指令

int32\_t MipiDsiTx\(PalHandle handle, struct DsiCmdDesc \*cmd\);

**表 4**  MipiDsiTx的参数和返回值描述

<a name="table1018490043"></a>
<table><tbody><tr id="row31848013417"><td class="cellrowborder" valign="top" width="50%"><p id="p1415816132411"><a name="p1415816132411"></a><a name="p1415816132411"></a><strong id="b129796117337"><a name="b129796117337"></a><a name="b129796117337"></a>参数</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p11158111316410"><a name="p11158111316410"></a><a name="p11158111316410"></a><strong id="b1699118123314"><a name="b1699118123314"></a><a name="b1699118123314"></a>参数描述</strong></p>
</td>
</tr>
<tr id="row10184701945"><td class="cellrowborder" valign="top" width="50%"><p id="p104891871157"><a name="p104891871157"></a><a name="p104891871157"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p204891671156"><a name="p204891671156"></a><a name="p204891671156"></a>操作句柄</p>
</td>
</tr>
<tr id="row928111518418"><td class="cellrowborder" valign="top" width="50%"><p id="p4282955412"><a name="p4282955412"></a><a name="p4282955412"></a>cmd</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p7282752412"><a name="p7282752412"></a><a name="p7282752412"></a>需要发送的指令数据指针</p>
</td>
</tr>
<tr id="row17393154515328"><td class="cellrowborder" valign="top" width="50%"><p id="p8158313248"><a name="p8158313248"></a><a name="p8158313248"></a><strong id="b18542051332"><a name="b18542051332"></a><a name="b18542051332"></a>返回值</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p161591413741"><a name="p161591413741"></a><a name="p161591413741"></a><strong id="b45520523313"><a name="b45520523313"></a><a name="b45520523313"></a>返回值描述</strong></p>
</td>
</tr>
<tr id="row339324593215"><td class="cellrowborder" valign="top" width="50%"><p id="p103191916578"><a name="p103191916578"></a><a name="p103191916578"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p1231981611712"><a name="p1231981611712"></a><a name="p1231981611712"></a>发送成功</p>
</td>
</tr>
<tr id="row15393184519323"><td class="cellrowborder" valign="top" width="50%"><p id="p531916166716"><a name="p531916166716"></a><a name="p531916166716"></a>负数</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p93191161174"><a name="p93191161174"></a><a name="p93191161174"></a>发送失败</p>
</td>
</tr>
</tbody>
</table>

```
int32_t ret;
struct DsiCmdDesc *cmd = OsalMemCalloc(sizeof(struct DsiCmdDesc));
if (cmd == NULL) {
    return HDF_FAILURE;
}
cmd->dtype = DTYPE_DCS_WRITE;
cmd->dlen = 1;
cmd->payload = OsalMemCalloc(sizeof(uint8_t));
if (cmd->payload == NULL) {
    HdfFree(cmd);
    return HDF_FAILURE;
}
*(cmd->payload) = DTYPE_GEN_LWRITE;
MipiDsiSetLpMode(mipiHandle);
ret = MipiDsiTx(mipiHandle, cmd);
MipiDsiSetHsMode(mipiHandle);
if (ret != HDF_SUCCESS) {
    HDF_LOGE("%s: PalMipiDsiTx fail! ret=%d\n", __func__, ret);
    HdfFree(cmd->payload);
    HdfFree(cmd);
    return HDF_FAILURE;
}
HdfFree(cmd->payload);
HdfFree(cmd);
```

-   回读指令

int32\_t MipiDsiRx\(DevHandle handle, struct DsiCmdDesc \*cmd, uint32\_t readLen, uint8\_t \*out\);

**表 5**  MipiDsiRx的参数和返回值描述

<a name="table223910318361"></a>
<table><tbody><tr id="row924033173613"><td class="cellrowborder" valign="top" width="50%"><p id="p16240143143611"><a name="p16240143143611"></a><a name="p16240143143611"></a><strong id="b1724033112363"><a name="b1724033112363"></a><a name="b1724033112363"></a>参数</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p32401031113610"><a name="p32401031113610"></a><a name="p32401031113610"></a><strong id="b1324013111363"><a name="b1324013111363"></a><a name="b1324013111363"></a>参数描述</strong></p>
</td>
</tr>
<tr id="row024043193619"><td class="cellrowborder" valign="top" width="50%"><p id="p16231153542520"><a name="p16231153542520"></a><a name="p16231153542520"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p122311535122518"><a name="p122311535122518"></a><a name="p122311535122518"></a>操作句柄</p>
</td>
</tr>
<tr id="row192401331163613"><td class="cellrowborder" valign="top" width="50%"><p id="p8706172453614"><a name="p8706172453614"></a><a name="p8706172453614"></a>cmd</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p0706424183610"><a name="p0706424183610"></a><a name="p0706424183610"></a>需要回读的指令数据指针</p>
</td>
</tr>
<tr id="row12646535173616"><td class="cellrowborder" valign="top" width="50%"><p id="p16465359364"><a name="p16465359364"></a><a name="p16465359364"></a>readLen</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p564617356360"><a name="p564617356360"></a><a name="p564617356360"></a>期望回读的数据长度</p>
</td>
</tr>
<tr id="row919916426361"><td class="cellrowborder" valign="top" width="50%"><p id="p11199942153616"><a name="p11199942153616"></a><a name="p11199942153616"></a>out</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p91991042143618"><a name="p91991042143618"></a><a name="p91991042143618"></a>回读的数据buf指针</p>
</td>
</tr>
<tr id="row14240133143619"><td class="cellrowborder" valign="top" width="50%"><p id="p1723253542518"><a name="p1723253542518"></a><a name="p1723253542518"></a><strong id="b4232173517256"><a name="b4232173517256"></a><a name="b4232173517256"></a>返回值</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p223217356253"><a name="p223217356253"></a><a name="p223217356253"></a><strong id="b7232103510259"><a name="b7232103510259"></a><a name="b7232103510259"></a>返回值描述</strong></p>
</td>
</tr>
<tr id="row424093120369"><td class="cellrowborder" valign="top" width="50%"><p id="p1123203518257"><a name="p1123203518257"></a><a name="p1123203518257"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p62324353251"><a name="p62324353251"></a><a name="p62324353251"></a>获取成功</p>
</td>
</tr>
<tr id="row18241531153610"><td class="cellrowborder" valign="top" width="50%"><p id="p42321635122517"><a name="p42321635122517"></a><a name="p42321635122517"></a>负数</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p323283510252"><a name="p323283510252"></a><a name="p323283510252"></a>获取失败</p>
</td>
</tr>
</tbody>
</table>

```
int32_t ret;
uint8_t readVal = 0;

struct DsiCmdDesc *cmdRead = OsalMemCalloc(sizeof(struct DsiCmdDesc));
if (cmdRead == NULL) {
    return HDF_FAILURE;
}
cmdRead->dtype = DTYPE_DCS_READ;
cmdRead->dlen = 1;
cmdRead->payload = OsalMemCalloc(sizeof(uint8_t));
if (cmdRead->payload == NULL) {
    HdfFree(cmdRead);
    return HDF_FAILURE;
}
*(cmdRead->payload) = DDIC_REG_STATUS;
MipiDsiSetLpMode(g_handle);
ret = MipiDsiRx(g_handle, cmdRead, sizeof(readVal), &readVal);
MipiDsiSetHsMode(g_handle);
if (ret != HDF_SUCCESS) {
    HDF_LOGE("%s: MipiDsiRx fail! ret=%d\n", __func__, ret);
    HdfFree(cmdRead->payload);
    HdfFree(cmdRead);
    return HDF_FAILURE;
}
HdfFree(cmdRead->payload);
HdfFree(cmdRead);
```

## 释放MIPI-DSI操作句柄<a name="section217313211199"></a>

MIPI-DSI使用完成之后，需要释放操作句柄，释放句柄的函数如下所示：

void MipiDsiClose\(DevHandle handle\);

该函数会释放掉由MipiDsiOpen申请的资源。

**表 6**  MipiDsiClose的参数和返回值描述

<a name="table72517953115"></a>
<table><thead align="left"><tr id="row1525793312"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p115402031153111"><a name="p115402031153111"></a><a name="p115402031153111"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p65406313319"><a name="p65406313319"></a><a name="p65406313319"></a>参数描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1926109193116"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p105419317318"><a name="p105419317318"></a><a name="p105419317318"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p132442255912"><a name="p132442255912"></a><a name="p132442255912"></a>MIPI-DSI操作句柄</p>
</td>
</tr>
</tbody>
</table>

```
MipiDsiClose(mipiHandle); /* 释放掉MIPI-DSI操作句柄 */
```

