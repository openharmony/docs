# MIPI DSI

## Overview

The Display Serial Interface \(DSI\) is a specification stipulated by the Mobile Industry Processor Interface \(MIPI\) Alliance, aiming to reduce the cost of display controllers in a mobile device. It defines a serial bus and communication protocol among the host, the source of image data, and the target device. In this way, the DSI can send pixel data or commands to peripherals \(usually LCDs or similar display devices\) in serial mode, or reads information such as status and pixel from the peripherals.

MIPI DSI is capable of working in both high speed \(HS\) mode and low power \(LP\) mode. All data lanes can only travel from the DSI host to a peripheral in HS mode, except the first data lane, which can also receive data such as status information and pixels from the peripheral in LP mode. The clock lane is dedicated to transmitting synchronization clock signals in HS mode.
[Figure 1](#fig1122611461203)  shows a simplified DSI interface. Conceptually, a DSI-compliant interface has the same features as interfaces complying with DBI-2 and DPI-2 standards. It sends pixels or commands to a peripheral and can read status or pixel information from the peripheral. The main difference is that the DSI serializes all pixel data, commands, and events that, in traditional interfaces, are conveyed to and from the peripheral on a parallel data bus with additional control signals.

   **Figure  1** DSI transmitting and receiving interface<a name="fig1122611461203"></a>  
    ![](figures/dsi-transmitting-and-receiving-interface.png "dsi-transmitting-and-receiving-interface")


## Available APIs

**Table  1** APIs for MIPI DSI

<a name="table4199102313245"></a>
<table><thead align="left"><tr id="row1619910238244"><th class="cellrowborder" valign="top" width="26.619999999999997%" id="mcps1.2.4.1.1"><p id="p141991023182411"><a name="p141991023182411"></a><a name="p141991023182411"></a>Capability</p>
</th>
<th class="cellrowborder" valign="top" width="28.910000000000004%" id="mcps1.2.4.1.2"><p id="p1199102315247"><a name="p1199102315247"></a><a name="p1199102315247"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="44.47%" id="mcps1.2.4.1.3"><p id="p719918232240"><a name="p719918232240"></a><a name="p719918232240"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row15199023172414"><td class="cellrowborder" rowspan="2" valign="top" width="26.619999999999997%" headers="mcps1.2.4.1.1 "><p id="p919902312413"><a name="p919902312413"></a><a name="p919902312413"></a>Setting/Obtaining MIPI DSI configuration parameters</p>
</td>
<td class="cellrowborder" valign="top" width="28.910000000000004%" headers="mcps1.2.4.1.2 "><p id="p21995232243"><a name="p21995232243"></a><a name="p21995232243"></a>MipiDsiSetCfg</p>
</td>
<td class="cellrowborder" valign="top" width="44.47%" headers="mcps1.2.4.1.3 "><p id="p919911233240"><a name="p919911233240"></a><a name="p919911233240"></a>Sets configuration parameters for a MIPI DSI device.</p>
</td>
</tr>
<tr id="row171996232248"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p7199623152412"><a name="p7199623152412"></a><a name="p7199623152412"></a>MipiDsiGetCfg</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1119919235248"><a name="p1119919235248"></a><a name="p1119919235248"></a>Obtains configuration parameters of a MIPI DSI device.</p>
</td>
</tr>
<tr id="row91994239242"><td class="cellrowborder" rowspan="2" valign="top" width="26.619999999999997%" headers="mcps1.2.4.1.1 "><p id="p101998233245"><a name="p101998233245"></a><a name="p101998233245"></a>Obtaining /Releasing device handles</p>
</td>
<td class="cellrowborder" valign="top" width="28.910000000000004%" headers="mcps1.2.4.1.2 "><p id="p51991323112415"><a name="p51991323112415"></a><a name="p51991323112415"></a>MipiDsiOpen</p>
</td>
<td class="cellrowborder" valign="top" width="44.47%" headers="mcps1.2.4.1.3 "><p id="p11991623182415"><a name="p11991623182415"></a><a name="p11991623182415"></a>Obtains a MIPI DSI device handle.</p>
</td>
</tr>
<tr id="row12199192352411"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p131991123172412"><a name="p131991123172412"></a><a name="p131991123172412"></a>MipiDsiClose</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p520062313249"><a name="p520062313249"></a><a name="p520062313249"></a>Releases a specified MIPI DSI device handle.</p>
</td>
</tr>
<tr id="row7200152382417"><td class="cellrowborder" rowspan="2" valign="top" width="26.619999999999997%" headers="mcps1.2.4.1.1 "><p id="p8200202312241"><a name="p8200202312241"></a><a name="p8200202312241"></a>Setting the LP or HS mode</p>
</td>
<td class="cellrowborder" valign="top" width="28.910000000000004%" headers="mcps1.2.4.1.2 "><p id="p6200192318247"><a name="p6200192318247"></a><a name="p6200192318247"></a>MipiDsiSetLpMode</p>
</td>
<td class="cellrowborder" valign="top" width="44.47%" headers="mcps1.2.4.1.3 "><p id="p16200192319240"><a name="p16200192319240"></a><a name="p16200192319240"></a>Sets LP mode for a MIPI DSI device.</p>
</td>
</tr>
<tr id="row122001523182417"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p22009236249"><a name="p22009236249"></a><a name="p22009236249"></a>MipiDsiSetHsMode</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p22001423192418"><a name="p22001423192418"></a><a name="p22001423192418"></a>Sets HS mode for a MIPI DSI device.</p>
</td>
</tr>
<tr id="row52002237248"><td class="cellrowborder" rowspan="2" valign="top" width="26.619999999999997%" headers="mcps1.2.4.1.1 "><p id="p10200162332412"><a name="p10200162332412"></a><a name="p10200162332412"></a>Reading/Sending commands</p>
</td>
<td class="cellrowborder" valign="top" width="28.910000000000004%" headers="mcps1.2.4.1.2 "><p id="p19200142315249"><a name="p19200142315249"></a><a name="p19200142315249"></a>MipiDsiTx</p>
</td>
<td class="cellrowborder" valign="top" width="44.47%" headers="mcps1.2.4.1.3 "><p id="p1020082319243"><a name="p1020082319243"></a><a name="p1020082319243"></a>Sends a display command set (DCS) command for sending data.</p>
</td>
</tr>
<tr id="row6200162372416"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p18200112392417"><a name="p18200112392417"></a><a name="p18200112392417"></a>MipiDsiRx</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p9200102312249"><a name="p9200102312249"></a><a name="p9200102312249"></a>Receives a DCS command for reading data with the specified length.</p>
</td>
</tr>
</tbody>
</table>

>![](../public_sys-resources/icon-note.gif) **NOTE**<br> All functions described in this document can be called only in kernel space.

## Usage Guidelines

### How to Use

The figure below illustrates how to use the APIs.

**Figure  2** Using MIPI DSI driver APIs

 ![](figures/using-mipi-dsi-process.png)

### Obtaining a MIPI DSI Device Handle<a name="section5126155683811"></a>

Before performing MIPI DSI communication, obtain a MIPI DSI device handle by calling **MipiDsiOpen**. This function returns a MIPI DSI device handle with a specified channel ID.

DevHandle MipiDsiOpen\(uint8\_t id\);

**Table  2** Description of **MipiDsiOpen**

<a name="table7603619123820"></a>
<table><thead align="left"><tr id="row1060351914386"><th class="cellrowborder" valign="top" width="20.66%" id="mcps1.2.3.1.1"><p id="p14603181917382"><a name="p14603181917382"></a><a name="p14603181917382"></a><strong id="b824620346298"><a name="b824620346298"></a><a name="b824620346298"></a>Parameter</strong></p>
</th>
<th class="cellrowborder" valign="top" width="79.34%" id="mcps1.2.3.1.2"><p id="p36031519183819"><a name="p36031519183819"></a><a name="p36031519183819"></a><strong id="b465435112910"><a name="b465435112910"></a><a name="b465435112910"></a>Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row960361918383"><td class="cellrowborder" valign="top" width="20.66%" headers="mcps1.2.3.1.1 "><p id="p8603161903818"><a name="p8603161903818"></a><a name="p8603161903818"></a>id</p>
</td>
<td class="cellrowborder" valign="top" width="79.34%" headers="mcps1.2.3.1.2 "><p id="p19603111916381"><a name="p19603111916381"></a><a name="p19603111916381"></a>MIPI DSI channel ID.</p>
</td>
</tr>
<tr id="row11410612183019"><td class="cellrowborder" valign="top" width="20.66%" headers="mcps1.2.3.1.1 "><p id="p460381915385"><a name="p460381915385"></a><a name="p460381915385"></a><strong id="b132118377294"><a name="b132118377294"></a><a name="b132118377294"></a>Return Value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="79.34%" headers="mcps1.2.3.1.2 "><p id="p96031619153812"><a name="p96031619153812"></a><a name="p96031619153812"></a><strong id="b1661638162915"><a name="b1661638162915"></a><a name="b1661638162915"></a>Description</strong></p>
</td>
</tr>
<tr id="row15410111273017"><td class="cellrowborder" valign="top" width="20.66%" headers="mcps1.2.3.1.1 "><p id="p1060418195389"><a name="p1060418195389"></a><a name="p1060418195389"></a>NULL</p>
</td>
<td class="cellrowborder" valign="top" width="79.34%" headers="mcps1.2.3.1.2 "><p id="p760471912388"><a name="p760471912388"></a><a name="p760471912388"></a>Failed to receive the specified command.</p>
</td>
</tr>
<tr id="row1241081213303"><td class="cellrowborder" valign="top" width="20.66%" headers="mcps1.2.3.1.1 "><p id="p5604719133811"><a name="p5604719133811"></a><a name="p5604719133811"></a>Device handle</p>
</td>
<td class="cellrowborder" valign="top" width="79.34%" headers="mcps1.2.3.1.2 "><p id="p3604181933818"><a name="p3604181933818"></a><a name="p3604181933818"></a>MIPI DSI device handle with a specified channel ID, whose data type is <strong id="b643184319293"><a name="b643184319293"></a><a name="b643184319293"></a>DevHandle</strong>.</p>
</td>
</tr>
</tbody>
</table>

The following example shows how to obtain a MIPI DSI device handle with the channel ID **0**:

```
DevHandle mipiDsiHandle = NULL;  /* Device handle */
chnId = 0;      /* MIPI DSI channel ID */

/* Obtain the MIPI DSI device handle based on a specified channel ID. */
mipiDsiHandle = MipiDsiOpen(chnId);
if (mipiDsiHandle == NULL) {
    HDF_LOGE("MipiDsiOpen: failed\n");
    return;
}
```

### Setting MIPI DSI Configuration Parameters<a name="section201164274344"></a>

-   Set MIPI DSI configuration parameters by calling the following function:

int32\_t MipiDsiSetCfg\(DevHandle handle, struct MipiCfg \*cfg\);

**Table  3** Description of **MipiDsiSetCfg**

<a name="table10692555281"></a>
<table><thead align="left"><tr id="row116914559288"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p1169195516288"><a name="p1169195516288"></a><a name="p1169195516288"></a><strong id="b1804534152914"><a name="b1804534152914"></a><a name="b1804534152914"></a>Parameter</strong></p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p769125512286"><a name="p769125512286"></a><a name="p769125512286"></a><strong id="b461693511292"><a name="b461693511292"></a><a name="b461693511292"></a>Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row4691155142812"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p66935515288"><a name="p66935515288"></a><a name="p66935515288"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p863714348217"><a name="p863714348217"></a><a name="p863714348217"></a>MIPI DSI device handle.</p>
</td>
</tr>
<tr id="row469145572817"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p46915519287"><a name="p46915519287"></a><a name="p46915519287"></a>cfg</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p76995518289"><a name="p76995518289"></a><a name="p76995518289"></a>Pointer to MIPI DSI configuration parameters.</p>
</td>
</tr>
<tr id="row16913554284"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p16955512812"><a name="p16955512812"></a><a name="p16955512812"></a><strong id="b1696737132913"><a name="b1696737132913"></a><a name="b1696737132913"></a>Return Value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p206945502813"><a name="p206945502813"></a><a name="p206945502813"></a><strong id="b42104011299"><a name="b42104011299"></a><a name="b42104011299"></a>Description</strong></p>
</td>
</tr>
<tr id="row146914556283"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p669175582818"><a name="p669175582818"></a><a name="p669175582818"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p169205511283"><a name="p169205511283"></a><a name="p169205511283"></a>Succeeded in setting MIPI DSI configuration parameters.</p>
</td>
</tr>
<tr id="row5694558283"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p269175516286"><a name="p269175516286"></a><a name="p269175516286"></a>Negative value</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p11691554280"><a name="p11691554280"></a><a name="p11691554280"></a>Failed to set MIPI DSI configuration parameters.</p>
</td>
</tr>
</tbody>
</table>

```
int32_t ret;
struct MipiCfg cfg = {0};

/* Configuration parameters of the connected device are as follows: */
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
/* Set MIPI DSI configuration parameters. */
ret = MipiDsiSetCfg(mipiDsiHandle, &cfg);
if (ret != 0) {
    HDF_LOGE("%s: SetMipiCfg fail! ret=%d\n", __func__, ret);
    return -1;
}
```

-   Obtain MIPI DSI configuration parameters by calling the following function:

int32\_t MipiDsiGetCfg\(DevHandle handle, struct MipiCfg \*cfg\);

**Table  4** Description of **MipiDsiGetCfg**

<a name="table7709554280"></a>
<table><thead align="left"><tr id="row670115515282"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p470205515287"><a name="p470205515287"></a><a name="p470205515287"></a><strong id="b14806334142912"><a name="b14806334142912"></a><a name="b14806334142912"></a>Parameter</strong></p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p270755162817"><a name="p270755162817"></a><a name="p270755162817"></a><strong id="b6618113519294"><a name="b6618113519294"></a><a name="b6618113519294"></a>Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row57014555286"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p11701155172815"><a name="p11701155172815"></a><a name="p11701155172815"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p57015510283"><a name="p57015510283"></a><a name="p57015510283"></a>MIPI DSI device handle.</p>
</td>
</tr>
<tr id="row1870155192815"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p137115572815"><a name="p137115572815"></a><a name="p137115572815"></a>cfg</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p771195522818"><a name="p771195522818"></a><a name="p771195522818"></a>Pointer to MIPI DSI configuration parameters.</p>
</td>
</tr>
<tr id="row12718555283"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1871175515289"><a name="p1871175515289"></a><a name="p1871175515289"></a><strong id="b8698737142912"><a name="b8698737142912"></a><a name="b8698737142912"></a>Return Value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p771955182813"><a name="p771955182813"></a><a name="p771955182813"></a><strong id="b84194010291"><a name="b84194010291"></a><a name="b84194010291"></a>Description</strong></p>
</td>
</tr>
<tr id="row1071155582812"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p6718551282"><a name="p6718551282"></a><a name="p6718551282"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p171195516285"><a name="p171195516285"></a><a name="p171195516285"></a>Succeeded in receiving the specified command.</p>
</td>
</tr>
<tr id="row97135519282"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p11711355162815"><a name="p11711355162815"></a><a name="p11711355162815"></a>Negative value</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p77116555286"><a name="p77116555286"></a><a name="p77116555286"></a>Failed to receive the specified command.</p>
</td>
</tr>
</tbody>
</table>

```
int32_t ret;
struct MipiCfg cfg;
memset(&cfg, 0, sizeof(struct MipiCfg));
ret = MipiDsiGetCfg(mipiDsiHandle, &cfg);
if (ret != HDF_SUCCESS) {
    HDF_LOGE("%s: GetMipiCfg fail!\n", __func__);
    return HDF_FAILURE;
}
```

### Sending/Receiving the Pointer to a Command<a name="section199401342173415"></a>

-   Send the pointer to a specified command by calling the following function:

int32\_t MipiDsiTx\(PalHandle handle, struct DsiCmdDesc \*cmd\);

**Table  5** Description of **MipiDsiTx**

<a name="table1018490043"></a>
<table><thead align="left"><tr id="row31848013417"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p1415816132411"><a name="p1415816132411"></a><a name="p1415816132411"></a><strong id="b1280873492913"><a name="b1280873492913"></a><a name="b1280873492913"></a>Parameter</strong></p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p11158111316410"><a name="p11158111316410"></a><a name="p11158111316410"></a><strong id="b1461953592915"><a name="b1461953592915"></a><a name="b1461953592915"></a>Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row10184701945"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p104891871157"><a name="p104891871157"></a><a name="p104891871157"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p204891671156"><a name="p204891671156"></a><a name="p204891671156"></a>MIPI DSI device handle.</p>
</td>
</tr>
<tr id="row928111518418"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p4282955412"><a name="p4282955412"></a><a name="p4282955412"></a>cmd</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p7282752412"><a name="p7282752412"></a><a name="p7282752412"></a>Pointer to the command to be sent.</p>
</td>
</tr>
<tr id="row17393154515328"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p8158313248"><a name="p8158313248"></a><a name="p8158313248"></a><strong id="b969917374296"><a name="b969917374296"></a><a name="b969917374296"></a>Return Value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p161591413741"><a name="p161591413741"></a><a name="p161591413741"></a><strong id="b1351140142912"><a name="b1351140142912"></a><a name="b1351140142912"></a>Description</strong></p>
</td>
</tr>
<tr id="row339324593215"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p103191916578"><a name="p103191916578"></a><a name="p103191916578"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1231981611712"><a name="p1231981611712"></a><a name="p1231981611712"></a>Succeeded in sending the specified command.</p>
</td>
</tr>
<tr id="row15393184519323"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p531916166716"><a name="p531916166716"></a><a name="p531916166716"></a>Negative value</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p93191161174"><a name="p93191161174"></a><a name="p93191161174"></a>Failed to send the specified command.</p>
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

-   Receive a specified command by calling the following function:

int32\_t MipiDsiRx\(DevHandle handle, struct DsiCmdDesc \*cmd, uint32\_t readLen, uint8\_t \*out\);

**Table  6** Description of **MipiDsiRx**

<a name="table223910318361"></a>
<table><thead align="left"><tr id="row924033173613"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p16240143143611"><a name="p16240143143611"></a><a name="p16240143143611"></a><strong id="b19809334172910"><a name="b19809334172910"></a><a name="b19809334172910"></a>Parameter</strong></p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p32401031113610"><a name="p32401031113610"></a><a name="p32401031113610"></a><strong id="b4620163552915"><a name="b4620163552915"></a><a name="b4620163552915"></a>Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row024043193619"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p16231153542520"><a name="p16231153542520"></a><a name="p16231153542520"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p122311535122518"><a name="p122311535122518"></a><a name="p122311535122518"></a>MIPI DSI device handle.</p>
</td>
</tr>
<tr id="row192401331163613"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p8706172453614"><a name="p8706172453614"></a><a name="p8706172453614"></a>cmd</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p0706424183610"><a name="p0706424183610"></a><a name="p0706424183610"></a>Pointer to the command to be received.</p>
</td>
</tr>
<tr id="row12646535173616"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p16465359364"><a name="p16465359364"></a><a name="p16465359364"></a>readLen</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p564617356360"><a name="p564617356360"></a><a name="p564617356360"></a>Length of the data to read.</p>
</td>
</tr>
<tr id="row919916426361"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p11199942153616"><a name="p11199942153616"></a><a name="p11199942153616"></a>out</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p91991042143618"><a name="p91991042143618"></a><a name="p91991042143618"></a>Pointer to the read data.</p>
</td>
</tr>
<tr id="row14240133143619"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1723253542518"><a name="p1723253542518"></a><a name="p1723253542518"></a><strong id="b47011237142916"><a name="b47011237142916"></a><a name="b47011237142916"></a>Return Value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p223217356253"><a name="p223217356253"></a><a name="p223217356253"></a><strong id="b15616408294"><a name="b15616408294"></a><a name="b15616408294"></a>Description</strong></p>
</td>
</tr>
<tr id="row424093120369"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1123203518257"><a name="p1123203518257"></a><a name="p1123203518257"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p62324353251"><a name="p62324353251"></a><a name="p62324353251"></a>Succeeded in receiving the specified command.</p>
</td>
</tr>
<tr id="row18241531153610"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p42321635122517"><a name="p42321635122517"></a><a name="p42321635122517"></a>Negative value</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p323283510252"><a name="p323283510252"></a><a name="p323283510252"></a>Failed to receive the specified command.</p>
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
MipiDsiSetLpMode(mipiDsiHandle);
ret = MipiDsiRx(mipiDsiHandle, cmdRead, sizeof(readVal), &readVal);
MipiDsiSetHsMode(mipiDsiHandle);
if (ret != HDF_SUCCESS) {
    HDF_LOGE("%s: MipiDsiRx fail! ret=%d\n", __func__, ret);
    HdfFree(cmdRead->payload);
    HdfFree(cmdRead);
    return HDF_FAILURE;
}
HdfFree(cmdRead->payload);
HdfFree(cmdRead);
```

### Releasing the MIPI DSI Device Handle<a name="section161011610357"></a>

After the MIPI DSI communication, release the MIPI DSI device handle by calling the following function:

void MipiDsiClose\(DevHandle handle\);

This function releases the resources requested by **MipiDsiOpen**.

**Table  7** Description of **MipiDsiClose**

<a name="table72517953115"></a>
<table><thead align="left"><tr id="row1525793312"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p115402031153111"><a name="p115402031153111"></a><a name="p115402031153111"></a><strong id="b1487612133120"><a name="b1487612133120"></a><a name="b1487612133120"></a>Parameter</strong></p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p65406313319"><a name="p65406313319"></a><a name="p65406313319"></a><strong id="b6397192316313"><a name="b6397192316313"></a><a name="b6397192316313"></a>Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row1926109193116"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p105419317318"><a name="p105419317318"></a><a name="p105419317318"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p132442255912"><a name="p132442255912"></a><a name="p132442255912"></a>MIPI DSI device handle.</p>
</td>
</tr>
</tbody>
</table>

```
MipiDsiClose(mipiHandle); /* Release the MIPI DSI device handle */
```

## Usage Example<a name="section17470126123520"></a>

The following is an example of using a MIPI DSI device:

```
#include "hdf.h"
#include "mipi_dsi_if.h"

void PalMipiDsiTestSample(void)
{
    uint8_t chnId;
    int32_t ret;  
    DevHandle mipiDsiHandle = NULL;
    
    /* Device channel ID */
    chnId = 0; 
    /* Obtain the MIPI DSI device handle based on a specified channel ID. */
    mipiDsiHandle = MipiDsiOpen(chnId);
    if (mipiDsiHandle == NULL) {
        HDF_LOGE("MipiDsiOpen: failed!\n");
        return;
    }
    /* MIPI DSI configuration parameters */
    struct MipiCfg cfg = {0};
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
    /* Set MIPI DSI configuration parameters. */
    ret = MipiDsiSetCfg(mipiDsiHandle, &cfg);
    if (ret != 0) {
        HDF_LOGE("%s: SetMipiCfg fail! ret=%d\n", __func__, ret);
        return;
    }
    /* Send the command for initializing the PANEL register. */
    struct DsiCmdDesc *cmd = OsalMemCalloc(sizeof(struct DsiCmdDesc));
    if (cmd == NULL) {
        return;
    }
    cmd->dtype = DTYPE_DCS_WRITE;
    cmd->dlen = 1;
    cmd->payload = OsalMemCalloc(sizeof(uint8_t));
    if (cmd->payload == NULL) {
        HdfFree(cmd);
        return;
    }
    *(cmd->payload) = DTYPE_GEN_LWRITE;
    MipiDsiSetLpMode(mipiHandle);
    ret = MipiDsiTx(mipiHandle, cmd);
    MipiDsiSetHsMode(mipiHandle);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%s: MipiDsiTx fail! ret=%d\n", __func__, ret);
        HdfFree(cmd->payload);
        HdfFree(cmd);
        return;
    }
    HdfFree(cmd->payload);
    HdfFree(cmd);
    /* Pointer to the register that reads the PANEL status */
    uint8_t readVal = 0;
    struct DsiCmdDesc *cmdRead = OsalMemCalloc(sizeof(struct DsiCmdDesc));
    if (cmdRead == NULL) {
        return;
    }
    cmdRead->dtype = DTYPE_DCS_READ;
    cmdRead->dlen = 1;
    cmdRead->payload = OsalMemCalloc(sizeof(uint8_t));
    if (cmdRead->payload == NULL) {
        HdfFree(cmdRead);
        return;
    }
    *(cmdRead->payload) = DDIC_REG_STATUS;
    MipiDsiSetLpMode(mipiDsiHandle);
    ret = MipiDsiRx(mipiDsiHandle, cmdRead, sizeof(readVal), &readVal);
    MipiDsiSetHsMode(mipiDsiHandle);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%s: MipiDsiRx fail! ret=%d\n", __func__, ret);
        HdfFree(cmdRead->payload);
        HdfFree(cmdRead);
        return;
    }
    HdfFree(cmdRead->payload);
    HdfFree(cmdRead);
    /* Release the MIPI DSI device handle. */
    MipiDsiClose(handle); 
}
```