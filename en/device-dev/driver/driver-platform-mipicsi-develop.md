# MIPI CSI<a name="EN-US_TOPIC_0000001198067744"></a>

-   [Overview](#section72226945170128)
-   [Available APIs](#section735525713405)
-   [How to Develop](#section378858277170128)
-   [Development Example](#section2049027816170128)

## Overview<a name="section72226945170128"></a>

Defined by the Mobile Industry Processor Interface \(MIPI\) Alliance, the Camera Serial Interface \(CSI\) is a specification that allows data to be transmitted from the camera to the host processor on mobile platforms. In the Hardware Driver Foundation \(HDF\), the MIPI CSI module uses the service-free mode for API adaptation. The service-free mode applies to the devices that do not provide user-mode APIs or the OS that does not distinguish the user mode and the kernel mode. In the service-free mode, DevHandle \(a void pointer\) directly points to the kernel-mode address of the device object.

**Figure  1**  Service-free mode<a name="fig260692723120"></a>  

![](figures/service-free-mode.png "Service-free mode")

## Available APIs<a name="section735525713405"></a>

MipiCsiCntlrMethod:

```
struct MipiCsiCntlrMethod {
    int32_t (*setComboDevAttr)(struct MipiCsiCntlr *cntlr, ComboDevAttr *pAttr);
    int32_t (*setPhyCmvmode)(struct MipiCsiCntlr *cntlr, uint8_t devno, PhyCmvMode cmvMode);
    int32_t (*setExtDataType)(struct MipiCsiCntlr *cntlr, ExtDataType* dataType);
    int32_t (*setHsMode)(struct MipiCsiCntlr *cntlr, LaneDivideMode laneDivideMode);
    int32_t (*enableClock)(struct MipiCsiCntlr *cntlr, uint8_t comboDev);
    int32_t (*disableClock)(struct MipiCsiCntlr *cntlr, uint8_t comboDev);
    int32_t (*resetRx)(struct MipiCsiCntlr *cntlr, uint8_t comboDev);
    int32_t (*unresetRx)(struct MipiCsiCntlr *cntlr, uint8_t comboDev);
    int32_t (*enableSensorClock)(struct MipiCsiCntlr *cntlr, uint8_t snsClkSource);
    int32_t (*disableSensorClock)(struct MipiCsiCntlr *cntlr, uint8_t snsClkSource);
    int32_t (*resetSensor)(struct MipiCsiCntlr *cntlr, uint8_t snsResetSource);
    int32_t (*unresetSensor)(struct MipiCsiCntlr *cntlr, uint8_t snsResetSource);
};
```

**Table  1**  Callbacks for the members in the MipiCsiCntlrMethod structure

<a name="table1233500677170128"></a>
<table><thead align="left"><tr id="row1000451054170128"><th class="cellrowborder" valign="top" width="20%" id="mcps1.2.6.1.1"><p id="entry1111988081170128p0"><a name="entry1111988081170128p0"></a><a name="entry1111988081170128p0"></a>Callback</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.2.6.1.2"><p id="entry1314377643170128p0"><a name="entry1314377643170128p0"></a><a name="entry1314377643170128p0"></a>Input Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.2.6.1.3"><p id="entry102571833170128p0"><a name="entry102571833170128p0"></a><a name="entry102571833170128p0"></a>Output Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.2.6.1.4"><p id="entry259883708170128p0"><a name="entry259883708170128p0"></a><a name="entry259883708170128p0"></a>Return Value</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.2.6.1.5"><p id="entry1719007141170128p0"><a name="entry1719007141170128p0"></a><a name="entry1719007141170128p0"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row893348241170128"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="entry2092857420170128p0"><a name="entry2092857420170128p0"></a><a name="entry2092857420170128p0"></a>setComboDevAttr</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p155578927170128"><a name="p155578927170128"></a><a name="p155578927170128"></a><strong id="b2983104693117"><a name="b2983104693117"></a><a name="b2983104693117"></a>cntlr</strong>: structure pointer to the MIPI CSI controller.</p>
<p id="p534134719170128"><a name="p534134719170128"></a><a name="p534134719170128"></a><strong id="b717683263220"><a name="b717683263220"></a><a name="b717683263220"></a>pAttr</strong>: structure pointer to the configuration structure of the MIPI CSI.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="entry1300850044170128p0"><a name="entry1300850044170128p0"></a><a name="entry1300850044170128p0"></a>–</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="entry1079550609170128p0"><a name="entry1079550609170128p0"></a><a name="entry1079550609170128p0"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="entry1104973652170128p0"><a name="entry1104973652170128p0"></a><a name="entry1104973652170128p0"></a>Sets the MIPI-CSI configuration.</p>
</td>
</tr>
<tr id="row1236584443170128"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="entry1263277119170128p0"><a name="entry1263277119170128p0"></a><a name="entry1263277119170128p0"></a>setPhyCmvmode</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p548503413170128"><a name="p548503413170128"></a><a name="p548503413170128"></a><strong id="b33316314348"><a name="b33316314348"></a><a name="b33316314348"></a>cntlr</strong>: structure pointer to the MIPI CSI controller.</p>
<p id="p1389106408170128"><a name="p1389106408170128"></a><a name="p1389106408170128"></a><strong id="b7288183093611"><a name="b7288183093611"></a><a name="b7288183093611"></a>devno</strong>: Device ID, which is of the uint8_t type.</p>
<p id="p118314402170128"><a name="p118314402170128"></a><a name="p118314402170128"></a><strong id="b1347113393714"><a name="b1347113393714"></a><a name="b1347113393714"></a>cmvMode</strong>: common-mode voltage (CMV) mode.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="entry886884421170128p0"><a name="entry886884421170128p0"></a><a name="entry886884421170128p0"></a>–</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="entry1542733203170128p0"><a name="entry1542733203170128p0"></a><a name="entry1542733203170128p0"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="entry1506663070170128p0"><a name="entry1506663070170128p0"></a><a name="entry1506663070170128p0"></a>Sets the CMV mode.</p>
</td>
</tr>
<tr id="row1486148936170128"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="entry1589217404170128p0"><a name="entry1589217404170128p0"></a><a name="entry1589217404170128p0"></a>setExtDataType</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p114389566170128"><a name="p114389566170128"></a><a name="p114389566170128"></a><strong id="b34053117344"><a name="b34053117344"></a><a name="b34053117344"></a>cntlr</strong>: structure pointer to the MIPI CSI controller.</p>
<p id="p996608377170128"><a name="p996608377170128"></a><a name="p996608377170128"></a><strong id="b784685684412"><a name="b784685684412"></a><a name="b784685684412"></a>dataType</strong>: structure pointer to the data that defines the YUV, original data formats, and bit depth.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="entry378080489170128p0"><a name="entry378080489170128p0"></a><a name="entry378080489170128p0"></a>–</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="entry851136224170128p0"><a name="entry851136224170128p0"></a><a name="entry851136224170128p0"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="entry1309676064170128p0"><a name="entry1309676064170128p0"></a><a name="entry1309676064170128p0"></a>Sets the YUV, RAW data format, and bit depth.</p>
</td>
</tr>
<tr id="row692364909170128"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="entry1017488702170128p0"><a name="entry1017488702170128p0"></a><a name="entry1017488702170128p0"></a>setHsMode</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p1054266120170128"><a name="p1054266120170128"></a><a name="p1054266120170128"></a><strong id="b144183117349"><a name="b144183117349"></a><a name="b144183117349"></a>cntlr</strong>: structure pointer to the MIPI CSI controller.</p>
<p id="p1574674418170128"><a name="p1574674418170128"></a><a name="p1574674418170128"></a><strong id="b18748194155516"><a name="b18748194155516"></a><a name="b18748194155516"></a>laneDivideMode</strong>: lane mode.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="entry1749069145170128p0"><a name="entry1749069145170128p0"></a><a name="entry1749069145170128p0"></a>–</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="entry1237801346170128p0"><a name="entry1237801346170128p0"></a><a name="entry1237801346170128p0"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="entry1643965522170128p0"><a name="entry1643965522170128p0"></a><a name="entry1643965522170128p0"></a>Sets the MIPI RX lane distribution.</p>
</td>
</tr>
<tr id="row1437392211170128"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="entry80806261170128p0"><a name="entry80806261170128p0"></a><a name="entry80806261170128p0"></a>enableClock</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p867235167170128"><a name="p867235167170128"></a><a name="p867235167170128"></a><strong id="b94263116342"><a name="b94263116342"></a><a name="b94263116342"></a>cntlr</strong>: structure pointer to the MIPI CSI controller.</p>
<p id="p1770663973170128"><a name="p1770663973170128"></a><a name="p1770663973170128"></a><strong id="b1342116531004"><a name="b1342116531004"></a><a name="b1342116531004"></a>comboDev</strong>: channel ID, which is of the uint8_t type.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="entry836736200170128p0"><a name="entry836736200170128p0"></a><a name="entry836736200170128p0"></a>–</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="entry918324954170128p0"><a name="entry918324954170128p0"></a><a name="entry918324954170128p0"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="entry373275246170128p0"><a name="entry373275246170128p0"></a><a name="entry373275246170128p0"></a>Enables the MIPI clock.</p>
</td>
</tr>
<tr id="row1944617165170128"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="entry1879109927170128p0"><a name="entry1879109927170128p0"></a><a name="entry1879109927170128p0"></a>disableClock</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p252627163170128"><a name="p252627163170128"></a><a name="p252627163170128"></a><strong id="b343103114343"><a name="b343103114343"></a><a name="b343103114343"></a>cntlr</strong>: structure pointer to the MIPI CSI controller.</p>
<p id="p573650189170128"><a name="p573650189170128"></a><a name="p573650189170128"></a><strong id="b1747970172618"><a name="b1747970172618"></a><a name="b1747970172618"></a>comboDev</strong>: channel ID, which is of the uint8_t type.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="entry8107921170128p0"><a name="entry8107921170128p0"></a><a name="entry8107921170128p0"></a>–</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="entry349207958170128p0"><a name="entry349207958170128p0"></a><a name="entry349207958170128p0"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="entry693552037170128p0"><a name="entry693552037170128p0"></a><a name="entry693552037170128p0"></a>Disables the MIPI clock.</p>
</td>
</tr>
<tr id="row168452313170128"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="entry536818735170128p0"><a name="entry536818735170128p0"></a><a name="entry536818735170128p0"></a>resetRx</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p1214231503170128"><a name="p1214231503170128"></a><a name="p1214231503170128"></a><strong id="b1043031153417"><a name="b1043031153417"></a><a name="b1043031153417"></a>cntlr</strong>: structure pointer to the MIPI CSI controller.</p>
<p id="p104793304170128"><a name="p104793304170128"></a><a name="p104793304170128"></a><strong id="b597920533269"><a name="b597920533269"></a><a name="b597920533269"></a>comboDev</strong>: channel ID, which is of the uint8_t type.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="entry349755171170128p0"><a name="entry349755171170128p0"></a><a name="entry349755171170128p0"></a>–</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="entry608378681170128p0"><a name="entry608378681170128p0"></a><a name="entry608378681170128p0"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="entry1692819512170128p0"><a name="entry1692819512170128p0"></a><a name="entry1692819512170128p0"></a>Resets the MIPI RX.</p>
</td>
</tr>
<tr id="row812174477170128"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="entry677771062170128p0"><a name="entry677771062170128p0"></a><a name="entry677771062170128p0"></a>unresetRx</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p1883220887170128"><a name="p1883220887170128"></a><a name="p1883220887170128"></a><strong id="b1202156153016"><a name="b1202156153016"></a><a name="b1202156153016"></a>cntlr</strong>: structure pointer to the MIPI CSI controller.</p>
<p id="p114324757170128"><a name="p114324757170128"></a><a name="p114324757170128"></a><strong id="b105520153110"><a name="b105520153110"></a><a name="b105520153110"></a>comboDev</strong>: channel ID, which is of the uint8_t type.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="entry2088687179170128p0"><a name="entry2088687179170128p0"></a><a name="entry2088687179170128p0"></a>–</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="entry250678538170128p0"><a name="entry250678538170128p0"></a><a name="entry250678538170128p0"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="entry1714667992170128p0"><a name="entry1714667992170128p0"></a><a name="entry1714667992170128p0"></a>Deasserts the reset of the MIPI RX.</p>
</td>
</tr>
<tr id="row1282919412170128"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="entry204916079170128p0"><a name="entry204916079170128p0"></a><a name="entry204916079170128p0"></a>enableSensorClock</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p217879421170128"><a name="p217879421170128"></a><a name="p217879421170128"></a><strong id="b197181237203211"><a name="b197181237203211"></a><a name="b197181237203211"></a>cntlr</strong>: structure pointer to the MIPI CSI controller.</p>
<p id="p2098908158170128"><a name="p2098908158170128"></a><a name="p2098908158170128"></a><strong id="b12861154993218"><a name="b12861154993218"></a><a name="b12861154993218"></a>snsClkSource</strong>: number of the clock signal cable of the sensor, which is of the uint8_t type.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="entry1290595383170128p0"><a name="entry1290595383170128p0"></a><a name="entry1290595383170128p0"></a>–</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="entry1313850176170128p0"><a name="entry1313850176170128p0"></a><a name="entry1313850176170128p0"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="entry384362703170128p0"><a name="entry384362703170128p0"></a><a name="entry384362703170128p0"></a>Enables the MIPI sensor clock.</p>
</td>
</tr>
<tr id="row1992432516170128"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="entry980444503170128p0"><a name="entry980444503170128p0"></a><a name="entry980444503170128p0"></a>disableSensorClock</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p1996780281170128"><a name="p1996780281170128"></a><a name="p1996780281170128"></a><strong id="b4445316347"><a name="b4445316347"></a><a name="b4445316347"></a>cntlr</strong>: structure pointer to the MIPI CSI controller.</p>
<p id="p2021170726170128"><a name="p2021170726170128"></a><a name="p2021170726170128"></a><strong id="b17971423820"><a name="b17971423820"></a><a name="b17971423820"></a>snsClkSource</strong>: number of the clock signal cable of the sensor, which is of the uint8_t type.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="entry1694413990170128p0"><a name="entry1694413990170128p0"></a><a name="entry1694413990170128p0"></a>–</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="entry1647081928170128p0"><a name="entry1647081928170128p0"></a><a name="entry1647081928170128p0"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="entry2011696236170128p0"><a name="entry2011696236170128p0"></a><a name="entry2011696236170128p0"></a>Disables the MIPI sensor clock.</p>
</td>
</tr>
<tr id="row1739370133170128"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="entry386036597170128p0"><a name="entry386036597170128p0"></a><a name="entry386036597170128p0"></a>resetSensor</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p1065048089170128"><a name="p1065048089170128"></a><a name="p1065048089170128"></a><strong id="b19451631183417"><a name="b19451631183417"></a><a name="b19451631183417"></a>cntlr</strong>: structure pointer to the MIPI CSI controller.</p>
<p id="p998202090170128"><a name="p998202090170128"></a><a name="p998202090170128"></a><strong id="b10443111911384"><a name="b10443111911384"></a><a name="b10443111911384"></a>snsClkSource</strong>: number of the clock signal cable of the sensor, which is of the uint8_t type.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="entry173182567170128p0"><a name="entry173182567170128p0"></a><a name="entry173182567170128p0"></a>–</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="entry879245456170128p0"><a name="entry879245456170128p0"></a><a name="entry879245456170128p0"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="entry944835652170128p0"><a name="entry944835652170128p0"></a><a name="entry944835652170128p0"></a>Resets the sensor.</p>
</td>
</tr>
<tr id="row1197566339170128"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="entry363281016170128p0"><a name="entry363281016170128p0"></a><a name="entry363281016170128p0"></a>unresetSensor</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p416483731170128"><a name="p416483731170128"></a><a name="p416483731170128"></a><strong id="b178488417385"><a name="b178488417385"></a><a name="b178488417385"></a>cntlr</strong>: structure pointer to the MIPI CSI controller.</p>
<p id="p1988272362170128"><a name="p1988272362170128"></a><a name="p1988272362170128"></a><strong id="b6353246183818"><a name="b6353246183818"></a><a name="b6353246183818"></a>snsClkSource</strong>: number of the clock signal cable of the sensor, which is of the uint8_t type.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="entry1658055665170128p0"><a name="entry1658055665170128p0"></a><a name="entry1658055665170128p0"></a>–</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="entry2142771023170128p0"><a name="entry2142771023170128p0"></a><a name="entry2142771023170128p0"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="entry791107803170128p0"><a name="entry791107803170128p0"></a><a name="entry791107803170128p0"></a>Deasserts the reset of a sensor.</p>
</td>
</tr>
</tbody>
</table>

## How to Develop<a name="section378858277170128"></a>

The MIPI CSI module adaptation involves the following steps:

1.  Instantiate the driver entry.
    -   Instantiate the  **HdfDriverEntry**  structure.
    -   Call  **HDF\_INIT**  to register the  **HdfDriverEntry**  instance with the HDF.

2.  Configure attribute files.
    -   Add the  **deviceNode**  information to the  **device\_info.hcs**  file.
    -   \(Optional\) Add the  **mipicsi\_config.hcs**  file.

3.  Instantiate the MIPI CSI controller object.
    -   Initialize  **MipiCsiCntlr**.
    -   Instantiate  **MipiCsiCntlrMethod**  in the  **MipiCsiCntlr**  object.

        >![](../public_sys-resources/icon-note.gif) **NOTE:** 
        >For details, see  [Available APIs](#available-apis).


4.  Debug the driver.
    -   \(Optional\) For new drivers, verify basic functions, for example, verify the information returned after the connect operation and whether data is successfully transmitted.


## Development Example<a name="section2049027816170128"></a>

The following uses  **mipi\_rx\_hi35xx.c**  as an example to present the contents that need to be provided by the vendor to implement device functions.

1.  Generally, you need to configure the device attributes in  **busxx\_config.hcs**  and add the  **deviceNode**  information to the  **device\_info.hcs**  file. The device attribute values are closely related to the default values or value range of the  **MipiCsiCntlr**  members at the core layer. The  **deviceNode**  information is related to the driver entry registration.

    >![](../public_sys-resources/icon-note.gif) **NOTE:** 
    >In this example, the MIPI controller attributes are defined in the source file. If required, add the  **deviceMatchAttr**  information to  **deviceNode**  in the  **device\_info**  file and add the** mipicsi\_config.hcs**  file.

    **device\_info.hcs**  configuration reference:

    ```
    root {
    device_info {
        match_attr = "hdf_manager";
        platform :: host {
        hostName = "platform_host";
        priority = 50;
        device_mipi_csi:: device {
            device0 :: deviceNode {
                policy = 0;
                priority = 160;
                permission = 0644;
                moduleName = "HDF_MIPI_RX"; // (Mandatory) Driver name, which must be the same as the moduleName in the driver entry.
              serviceName = "HDF_MIPI_RX";// (Mandatory) Unique name of the service published by the driver.
            }
        }
        }
    }
    }
    ```

2.  Instantiate the driver entry. The driver entry must be a global variable of the  **HdfDriverEntry**  type \(defined in  **hdf\_device\_desc.h**\), and the value of  **moduleName**  must be the same as that in  **device\_info.hcs**. The function pointer members of the  **HdfDriverEntry**  structure are filled by the vendors' operation functions. In the HDF, the start address of each  **HdfDriverEntry**  object of all loaded drivers is collected to form a segment address space similar to an array for the upper layer to invoke.

    Generally, the HDF calls the  **Bind**  function and then the  **Init**  function to load a driver. If  **Init**  fails to be called, the HDF calls  **Release**  to release driver resources and exit.

    MIPI CSI driver entry reference:

    ```
    struct HdfDriverEntry g_mipiCsiDriverEntry = {
        .moduleVersion = 1,
        .Init = Hi35xxMipiCsiInit,          // See the Init function.
        .Release = Hi35xxMipiCsiRelease,    //See the Release function.
        .moduleName = "HDF_MIPI_RX",        // (Mandatory) The value must be the same as that in the device_info.hcs file.
    };
    HDF_INIT(g_mipiCsiDriverEntry);         // Call HDF_INIT to register the driver entry with the HDF.
    ```

3.  Initialize the  **MipiCsiCntlr**  object at the core layer, including initializing the vendor custom structure \(passing parameters and data\), instantiating  **MipiCsiCntlrMethod**  \(used to call underlying functions of the driver\) in  **MipiCsiCntlr**, and implementing the  **HdfDriverEntry**  member functions \(**Bind**,  **Init**, and  **Release**\).
    -   Custom structure reference:

        >![](../public_sys-resources/icon-note.gif) **NOTE:** 
        >To the driver, the custom structure carries parameters and data. The values in the  **config**  file are used to initialize the structure members. In this example, the MIPI CSI attributes are defined in the source file. Therefore, the basic member structure is similar to that of  **MipiCsiCntlr**.

        ```
        typedef struct {
            /** Data type: 8-bit, 10-bit, 12-bit, 14-bit, or 16-bit */
            DataType inputDataType;
            /** MIPI WDM mode */
            MipiWdrMode wdrMode;
            /** laneId: -1 - disabled */
            short laneId[MIPI_LANE_NUM];
        
            union {
                /** Used for HI_MIPI_WDR_MODE_DT */
                short dataType[WDR_VC_NUM];
            };
        } MipiDevAttr;
        
        typedef struct {
            /** Device number. */
            uint8_t devno;
            /** Input mode, which can be MIPI, LVDS, sub-LVDS, HiSPi, or DC. */
            InputMode inputMode;
            MipiDataRate dataRate;
            /** Crop area of the MIPI RX device (same as the size of the input image of the sensor). */
            ImgRect imgRect;
        
            union {
                MipiDevAttr mipiAttr;
                LvdsDevAttr lvdsAttr;
            };
        } ComboDevAttr;
        
        // MipiCsiCntlr is the core layer controller structure. Its members are assigned with values by using the Init function.
        struct MipiCsiCntlr {
            /** Send the service provided by this controller when the driver is bound to the HDF. */
            struct IDeviceIoService service;
            /** Pass the pointer to the device when the driver is bound to the HDF. */
            struct HdfDeviceObject *device;
            /** Device number */
            unsigned int devNo;
            /** All APIs provided by the controller */
            struct MipiCsiCntlrMethod *ops;
            /** All APIs for controller debugging. Set it to null if the driver is not implemented. */
            struct MipiCsiCntlrDebugMethod *debugs;
            /** Controller context variable. */
            MipiDevCtx ctx;
            /** Spinlock used when the controller context variable is accessed. */
            OsalSpinlock ctxLock;
            /** Lock method when the controller is managed */
            struct OsalMutex lock;
            /** Pointer to anonymous data, which is used to store the CSI device structure */
            void *priv;
        };
        ```

    -   **\(Important\)**  Instantiate the callback function structure  **MipiCsiCntlrMethod**  in  **MipiCsiCntlr**. Other members are initialized by using the  **Init**  function.

        ```
        static struct MipiCsiCntlrMethod g_method = {
            .setComboDevAttr = Hi35xxSetComboDevAttr,
            .setPhyCmvmode = Hi35xxSetPhyCmvmode,
            .setExtDataType = Hi35xxSetExtDataType,
            .setHsMode = Hi35xxSetHsMode,
            .enableClock = Hi35xxEnableClock,
            .disableClock = Hi35xxDisableClock,
            .resetRx = Hi35xxResetRx,
            .unresetRx = Hi35xxUnresetRx,
            .enableSensorClock = Hi35xxEnableSensorClock,
            .disableSensorClock = Hi35xxDisableSensorClock,
            .resetSensor = Hi35xxResetSensor,
            .unresetSensor = Hi35xxUnresetSensor
        };
        ```

    -   Init function

        Input parameters:

        **HdfDeviceObject**, an interface parameter exposed by the driver, contains the .hcs configuration file information.

        Return values:

        HDF\_STATUS \(The following table lists some status. For details about other status, see  **HDF\_STATUS**  in the  **/drivers/framework/include/utils/hdf\_base.h**  file.\)

        <a name="table683892652170128"></a>
        <table><thead align="left"><tr id="row466801181170128"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="entry433041536170128p0"><a name="entry433041536170128p0"></a><a name="entry433041536170128p0"></a>Status (Value)</p>
        </th>
        <th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="entry1260647143170128p0"><a name="entry1260647143170128p0"></a><a name="entry1260647143170128p0"></a>Description</p>
        </th>
        </tr>
        </thead>
        <tbody><tr id="row2053721693170128"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry772353853170128p0"><a name="entry772353853170128p0"></a><a name="entry772353853170128p0"></a>HDF_ERR_INVALID_OBJECT</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry891453569170128p0"><a name="entry891453569170128p0"></a><a name="entry891453569170128p0"></a>Invalid object</p>
        </td>
        </tr>
        <tr id="row1654561941170128"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1037876509170128p0"><a name="entry1037876509170128p0"></a><a name="entry1037876509170128p0"></a>HDF_ERR_MALLOC_FAIL</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1354763041170128p0"><a name="entry1354763041170128p0"></a><a name="entry1354763041170128p0"></a>Failed to allocate memory</p>
        </td>
        </tr>
        <tr id="row515913237170128"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1517991694170128p0"><a name="entry1517991694170128p0"></a><a name="entry1517991694170128p0"></a>HDF_ERR_INVALID_PARAM</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry784824354170128p0"><a name="entry784824354170128p0"></a><a name="entry784824354170128p0"></a>Invalid parameter</p>
        </td>
        </tr>
        <tr id="row1055228061170128"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry771111180170128p0"><a name="entry771111180170128p0"></a><a name="entry771111180170128p0"></a>HDF_ERR_IO</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1302592910170128p0"><a name="entry1302592910170128p0"></a><a name="entry1302592910170128p0"></a>I/O error</p>
        </td>
        </tr>
        <tr id="row1131544928170128"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1360197988170128p0"><a name="entry1360197988170128p0"></a><a name="entry1360197988170128p0"></a>HDF_SUCCESS</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1609403118170128p0"><a name="entry1609403118170128p0"></a><a name="entry1609403118170128p0"></a>Operation successful</p>
        </td>
        </tr>
        <tr id="row1247344727170128"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry816278864170128p0"><a name="entry816278864170128p0"></a><a name="entry816278864170128p0"></a>HDF_FAILURE</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry814861870170128p0"><a name="entry814861870170128p0"></a><a name="entry814861870170128p0"></a>Operation failed</p>
        </td>
        </tr>
        </tbody>
        </table>

        Function description:

        Connects to the  **MipiCsiCntlrMethod**  instance, calls  **MipiCsiRegisterCntlr**, and performs other vendor-defined initialization operations.

        ```
        static int32_t Hi35xxMipiCsiInit(struct HdfDeviceObject *device)
        {
            int32_t ret;
        
            HDF_LOGI("%s: enter!", __func__);
            g_mipiCsi.priv = NULL;       // g_mipiTx is a global variable defined.
                                        //static struct MipiCsiCntlr g_mipiCsi = {
                                        //.devNo = 0
                                        //};
            g_mipiCsi.ops = &g_method;    // Connect to the MipiCsiCntlrMethod instance.
        #ifdef CONFIG_HI_PROC_SHOW_SUPPORT
            g_mipiCsi.debugs = &g_debugMethod;
        #endif
            ret = MipiCsiRegisterCntlr(&g_mipiCsi, device);    // (Mandatory) Call the function at the core layer and g_mipiTx to initialize global variables at the core layer.
            if (ret != HDF_SUCCESS) {
                HDF_LOGE("%s: [MipiCsiRegisterCntlr] failed!", __func__);
                return ret;
            }
        
            ret = MipiRxDrvInit(); // (Mandatory) Device initialization customized by the vendor.
            if (ret != HDF_SUCCESS) {
                HDF_LOGE("%s: [MipiRxDrvInit] failed.", __func__);
                return ret;
            }
        #ifdef MIPICSI_VFS_SUPPORT
            ret = MipiCsiDevModuleInit(g_mipiCsi.devNo);
            if (ret != HDF_SUCCESS) {
                HDF_LOGE("%s: [MipiCsiDevModuleInit] failed!", __func__);
                return ret;
            }
        #endif
        
            OsalSpinInit(&g_mipiCsi.ctxLock);
            HDF_LOGI("%s: load mipi csi driver success!", __func__);
        
            return ret;
        }
        
        // mipi_csi_core.c, core layer file.
        int32_t MipiCsiRegisterCntlr(struct MipiCsiCntlr *cntlr, struct HdfDeviceObject *device)
        {
        ...
        // Define the global variable static struct MipiCsiHandle g_mipiCsihandle[MAX_CNTLR_CNT];
            if (g_mipiCsihandle[cntlr->devNo].cntlr == NULL) {
                (void)OsalMutexInit(&g_mipiCsihandle[cntlr->devNo].lock);
                (void)OsalMutexInit(&(cntlr->lock));
        
                g_mipiCsihandle[cntlr->devNo].cntlr = cntlr;    // Initialize MipiCsiHandle.
                g_mipiCsihandle[cntlr->devNo].priv = NULL;
                 cntlr->device = device;                         // Enable conversion between HdfDeviceObject and MipiCsiHandle.
                device->service = &(cntlr->service);            // Enable conversion between HdfDeviceObject and MipiCsiHandle.
                cntlr->priv = NULL;
                HDF_LOGI("%s: success.", __func__);
        
                return HDF_SUCCESS;
            }
        
            HDF_LOGE("%s: cntlr already exists.", __func__);
            return HDF_FAILURE;
        }
        ```

    -   Release function

        Input parameters:

        **HdfDeviceObject**, an interface parameter exposed by the driver, contains the .hcs configuration file information.

        Return values:

        –

        Function description:

        Releases the memory and deletes the controller. This function assigns a value to the  **Release**  API in the driver entry structure. When the HDF fails to call the  **Init**  function to initialize the driver, the  **Release**  function can be called to release driver resources. All forced conversion operations for obtaining the corresponding object can be successful only when the  **Init**  function has the corresponding value assignment operations.

        ```
        static void Hi35xxMipiCsiRelease(struct HdfDeviceObject *device)
        {
            struct MipiCsiCntlr *cntlr = NULL;
            ...
            cntlr = MipiCsiCntlrFromDevice(device);    // A forced conversion from HdfDeviceObject to MipiCsiCntlr is involved.
                                                       //return (device == NULL) ? NULL : (struct MipiCsiCntlr *)device->service;
            ...
        
            OsalSpinDestroy(&cntlr->ctxLock);
        #ifdef MIPICSI_VFS_SUPPORT
            MipiCsiDevModuleExit(cntlr->devNo);
        #endif
            MipiRxDrvExit();                           // (Mandatory) Release the resources occupied by the vendor's devices.
             MipiCsiUnregisterCntlr(&g_mipiCsi);         // Null function
            g_mipiCsi.priv = NULL;
        
            HDF_LOGI("%s: unload mipi csi driver success!", __func__);
        }
        ```



