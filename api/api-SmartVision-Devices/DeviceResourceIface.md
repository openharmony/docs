# DeviceResourceIface<a name="ZH-CN_TOPIC_0000001054918151"></a>

-   [Overview](#section793276185165631)
-   [Summary](#section1215722636165631)
-   [Data Fields](#pub-attribs)
-   [Details](#section156908930165631)
-   [Field](#section1644935392165631)
-   [GetBool](#a0a3446a50f3644a29cf812af0c915f8a)
-   [GetChildNode](#a70d5844ef0f0c35b9eb3bbba177bccc0)
-   [GetElemNum](#a0fafd4d32592ce2fbe951807995c5ab3)
-   [GetNodeByMatchAttr](#a8d7c819ee3d00ded8eef01b0594f3571)
-   [GetNodeByRefAttr](#a8066548056633048c008e7a29aac8c8f)
-   [GetRootNode](#adc489c2c907ebf9a098c91ba110a2c37)
-   [GetString](#a1989a47b8d61401e57ee523e01bc25ee)
-   [GetStringArrayElem](#a787eb71963c16c96bca913729078dd9d)
-   [GetUint16](#a1d3191febf1c9a0731a1614295a1529b)
-   [GetUint16Array](#a54977ca0fd60515bad5e33adf830fc64)
-   [GetUint16ArrayElem](#a27abcf7cdca0b25b6e620b75590e0a2d)
-   [GetUint32](#a87cf305ff9cabdbeb5011e6c04106b9e)
-   [GetUint32Array](#a2ed5d24a45946e270b4416c400839966)
-   [GetUint32ArrayElem](#a942b67fcd814a37d92e33f3de33c2ff5)
-   [GetUint64](#a3c364db9381da16449bb96d6be86aed8)
-   [GetUint64Array](#ab378caa47c5b01c31ca602d4eaa3046f)
-   [GetUint64ArrayElem](#aac32428eb3762de48514bd14348fd230)
-   [GetUint8](#a5610a62186ad18320dadcad7077fb3bb)
-   [GetUint8Array](#a067d741f2c3938ca08be2282e741b0a4)
-   [GetUint8ArrayElem](#a0973933ace2447ec38a82e7995e2c5af)

## **Overview**<a name="section793276185165631"></a>

**Related Modules:**

[DriverConfig](DriverConfig.md)

**Description:**

Provides functions for obtaining information about the device resource configuration tree. 

This structure provides functions for obtaining information about the device resource configuration tree, including the root node, the  **unit**  attribute data, and the  **String**  attribute data.

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1215722636165631"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table14074637165631"></a>
<table><thead align="left"><tr id="row1660654855165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1474959508165631"><a name="p1474959508165631"></a><a name="p1474959508165631"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p211974142165631"><a name="p211974142165631"></a><a name="p211974142165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1517817293165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p296209858165631"><a name="p296209858165631"></a><a name="p296209858165631"></a><a href="DeviceResourceIface.md#adc489c2c907ebf9a098c91ba110a2c37">GetRootNode</a> )(void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p657660321165631"><a name="p657660321165631"></a><a name="p657660321165631"></a>const struct <a href="DeviceResourceNode.md">DeviceResourceNode</a> *(* </p>
<p id="p1864296661165631"><a name="p1864296661165631"></a><a name="p1864296661165631"></a>Obtains the root node of the configuration tree. </p>
</td>
</tr>
<tr id="row184643633165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1891252256165631"><a name="p1891252256165631"></a><a name="p1891252256165631"></a><a href="DeviceResourceIface.md#a0a3446a50f3644a29cf812af0c915f8a">GetBool</a> )(const struct <a href="DeviceResourceNode.md">DeviceResourceNode</a> *node, const char *attrName)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1543450353165631"><a name="p1543450353165631"></a><a name="p1543450353165631"></a>bool(* </p>
<p id="p1332205778165631"><a name="p1332205778165631"></a><a name="p1332205778165631"></a>Obtains the value of a <strong id="b294476514165631"><a name="b294476514165631"></a><a name="b294476514165631"></a>BOOL</strong> attribute of a configuration tree node. </p>
</td>
</tr>
<tr id="row24386246165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1877696665165631"><a name="p1877696665165631"></a><a name="p1877696665165631"></a><a href="DeviceResourceIface.md#a5610a62186ad18320dadcad7077fb3bb">GetUint8</a> )(const struct <a href="DeviceResourceNode.md">DeviceResourceNode</a> *node, const char *attrName, uint8_t *value, uint8_t def)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p416067496165631"><a name="p416067496165631"></a><a name="p416067496165631"></a>int32_t(* </p>
<p id="p545876317165631"><a name="p545876317165631"></a><a name="p545876317165631"></a>Obtains the value of a <strong id="b1381539365165631"><a name="b1381539365165631"></a><a name="b1381539365165631"></a>Uint8</strong> attribute of a configuration tree node. </p>
</td>
</tr>
<tr id="row1714789283165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p361308537165631"><a name="p361308537165631"></a><a name="p361308537165631"></a><a href="DeviceResourceIface.md#a0973933ace2447ec38a82e7995e2c5af">GetUint8ArrayElem</a> )(const struct <a href="DeviceResourceNode.md">DeviceResourceNode</a> *node, const char *attrName, uint32_t <a href="UTILS.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>, uint8_t *value, uint8_t def)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p127612942165631"><a name="p127612942165631"></a><a name="p127612942165631"></a>int32_t(* </p>
<p id="p1474782160165631"><a name="p1474782160165631"></a><a name="p1474782160165631"></a>Obtains the value of a <strong id="b1652544848165631"><a name="b1652544848165631"></a><a name="b1652544848165631"></a>Unit8</strong> array attribute numbered <strong id="b653297554165631"><a name="b653297554165631"></a><a name="b653297554165631"></a>index</strong> of a configuration tree node. </p>
</td>
</tr>
<tr id="row2115601654165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p782639932165631"><a name="p782639932165631"></a><a name="p782639932165631"></a><a href="DeviceResourceIface.md#a067d741f2c3938ca08be2282e741b0a4">GetUint8Array</a> )(const struct <a href="DeviceResourceNode.md">DeviceResourceNode</a> *node, const char *attrName, uint8_t *value, uint32_t len, uint8_t def)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1234435858165631"><a name="p1234435858165631"></a><a name="p1234435858165631"></a>int32_t(* </p>
<p id="p1752475180165631"><a name="p1752475180165631"></a><a name="p1752475180165631"></a>Obtains the values of a <strong id="b2130551964165631"><a name="b2130551964165631"></a><a name="b2130551964165631"></a>Uint8</strong> array attribute of a configuration tree node. </p>
</td>
</tr>
<tr id="row777554337165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1674931727165631"><a name="p1674931727165631"></a><a name="p1674931727165631"></a><a href="DeviceResourceIface.md#a1d3191febf1c9a0731a1614295a1529b">GetUint16</a> )(const struct <a href="DeviceResourceNode.md">DeviceResourceNode</a> *node, const char *attrName, uint16_t *value, uint16_t def)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p138245544165631"><a name="p138245544165631"></a><a name="p138245544165631"></a>int32_t(* </p>
<p id="p229380631165631"><a name="p229380631165631"></a><a name="p229380631165631"></a>Obtains the value of a <strong id="b708548245165631"><a name="b708548245165631"></a><a name="b708548245165631"></a>Uint16</strong> attribute of a configuration tree node. </p>
</td>
</tr>
<tr id="row342596580165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1321921371165631"><a name="p1321921371165631"></a><a name="p1321921371165631"></a><a href="DeviceResourceIface.md#a27abcf7cdca0b25b6e620b75590e0a2d">GetUint16ArrayElem</a> )(const struct <a href="DeviceResourceNode.md">DeviceResourceNode</a> *node, const char *attrName, uint32_t <a href="UTILS.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>, uint16_t *value, uint16_t def)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1760703093165631"><a name="p1760703093165631"></a><a name="p1760703093165631"></a>int32_t(* </p>
<p id="p1486773747165631"><a name="p1486773747165631"></a><a name="p1486773747165631"></a>Obtains the value of a <strong id="b1161331416165631"><a name="b1161331416165631"></a><a name="b1161331416165631"></a>Uint16</strong> array attribute numbered <strong id="b1595996888165631"><a name="b1595996888165631"></a><a name="b1595996888165631"></a>index</strong> of a configuration tree node. </p>
</td>
</tr>
<tr id="row692631805165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1403432961165631"><a name="p1403432961165631"></a><a name="p1403432961165631"></a><a href="DeviceResourceIface.md#a54977ca0fd60515bad5e33adf830fc64">GetUint16Array</a> )(const struct <a href="DeviceResourceNode.md">DeviceResourceNode</a> *node, const char *attrName, uint16_t *value, uint32_t len, uint16_t def)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1973187843165631"><a name="p1973187843165631"></a><a name="p1973187843165631"></a>int32_t(* </p>
<p id="p1970924013165631"><a name="p1970924013165631"></a><a name="p1970924013165631"></a>Obtains the values of a <strong id="b450097204165631"><a name="b450097204165631"></a><a name="b450097204165631"></a>Uint16</strong> array attribute of a configuration tree node. </p>
</td>
</tr>
<tr id="row446845620165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2019608394165631"><a name="p2019608394165631"></a><a name="p2019608394165631"></a><a href="DeviceResourceIface.md#a87cf305ff9cabdbeb5011e6c04106b9e">GetUint32</a> )(const struct <a href="DeviceResourceNode.md">DeviceResourceNode</a> *node, const char *attrName, uint32_t *value, uint32_t def)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p758603732165631"><a name="p758603732165631"></a><a name="p758603732165631"></a>int32_t(* </p>
<p id="p1052825342165631"><a name="p1052825342165631"></a><a name="p1052825342165631"></a>Obtains the value of a <strong id="b1301668369165631"><a name="b1301668369165631"></a><a name="b1301668369165631"></a>Uint32</strong> attribute of a configuration tree node. </p>
</td>
</tr>
<tr id="row1027214878165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1408185509165631"><a name="p1408185509165631"></a><a name="p1408185509165631"></a><a href="DeviceResourceIface.md#a942b67fcd814a37d92e33f3de33c2ff5">GetUint32ArrayElem</a> )(const struct <a href="DeviceResourceNode.md">DeviceResourceNode</a> *node, const char *attrName, uint32_t <a href="UTILS.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>, uint32_t *value, uint32_t def)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1194184535165631"><a name="p1194184535165631"></a><a name="p1194184535165631"></a>int32_t(* </p>
<p id="p379139366165631"><a name="p379139366165631"></a><a name="p379139366165631"></a>Obtains the value of a <strong id="b57490501165631"><a name="b57490501165631"></a><a name="b57490501165631"></a>Uint32</strong> array attribute numbered <strong id="b879183025165631"><a name="b879183025165631"></a><a name="b879183025165631"></a>index</strong> of a configuration tree node. </p>
</td>
</tr>
<tr id="row2017168259165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1047950562165631"><a name="p1047950562165631"></a><a name="p1047950562165631"></a><a href="DeviceResourceIface.md#a2ed5d24a45946e270b4416c400839966">GetUint32Array</a> )(const struct <a href="DeviceResourceNode.md">DeviceResourceNode</a> *node, const char *attrName, uint32_t *value, uint32_t len, uint32_t def)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p169690072165631"><a name="p169690072165631"></a><a name="p169690072165631"></a>int32_t(* </p>
<p id="p385184239165631"><a name="p385184239165631"></a><a name="p385184239165631"></a>Obtains the values of a <strong id="b1528571927165631"><a name="b1528571927165631"></a><a name="b1528571927165631"></a>Uint32</strong> array attribute of a configuration tree node. </p>
</td>
</tr>
<tr id="row1944526012165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1193279848165631"><a name="p1193279848165631"></a><a name="p1193279848165631"></a><a href="DeviceResourceIface.md#a3c364db9381da16449bb96d6be86aed8">GetUint64</a> )(const struct <a href="DeviceResourceNode.md">DeviceResourceNode</a> *node, const char *attrName, uint64_t *value, uint64_t def)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p619482685165631"><a name="p619482685165631"></a><a name="p619482685165631"></a>int32_t(* </p>
<p id="p248646781165631"><a name="p248646781165631"></a><a name="p248646781165631"></a>Obtains the value of a <strong id="b1682710684165631"><a name="b1682710684165631"></a><a name="b1682710684165631"></a>Uint64</strong> attribute of a configuration tree node. </p>
</td>
</tr>
<tr id="row1174116716165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p526408664165631"><a name="p526408664165631"></a><a name="p526408664165631"></a><a href="DeviceResourceIface.md#aac32428eb3762de48514bd14348fd230">GetUint64ArrayElem</a> )(const struct <a href="DeviceResourceNode.md">DeviceResourceNode</a> *node, const char *attrName, uint32_t <a href="UTILS.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>, uint64_t *value, uint64_t def)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1947999105165631"><a name="p1947999105165631"></a><a name="p1947999105165631"></a>int32_t(* </p>
<p id="p978843037165631"><a name="p978843037165631"></a><a name="p978843037165631"></a>Obtains the value of a <strong id="b2030009991165631"><a name="b2030009991165631"></a><a name="b2030009991165631"></a>Uint64</strong> array attribute numbered <strong id="b2068572218165631"><a name="b2068572218165631"></a><a name="b2068572218165631"></a>index</strong> of a configuration tree node. </p>
</td>
</tr>
<tr id="row171244118165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1273553273165631"><a name="p1273553273165631"></a><a name="p1273553273165631"></a><a href="DeviceResourceIface.md#ab378caa47c5b01c31ca602d4eaa3046f">GetUint64Array</a> )(const struct <a href="DeviceResourceNode.md">DeviceResourceNode</a> *node, const char *attrName, uint64_t *value, uint32_t len, uint64_t def)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1794835509165631"><a name="p1794835509165631"></a><a name="p1794835509165631"></a>int32_t(* </p>
<p id="p1648592353165631"><a name="p1648592353165631"></a><a name="p1648592353165631"></a>Obtains the values of a <strong id="b1212667154165631"><a name="b1212667154165631"></a><a name="b1212667154165631"></a>Uint64</strong> array attribute of a configuration tree node. </p>
</td>
</tr>
<tr id="row47694950165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1377402439165631"><a name="p1377402439165631"></a><a name="p1377402439165631"></a><a href="DeviceResourceIface.md#a1989a47b8d61401e57ee523e01bc25ee">GetString</a> )(const struct <a href="DeviceResourceNode.md">DeviceResourceNode</a> *node, const char *attrName, const char **value, const char *def)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1339588979165631"><a name="p1339588979165631"></a><a name="p1339588979165631"></a>int32_t(* </p>
<p id="p1695855612165631"><a name="p1695855612165631"></a><a name="p1695855612165631"></a>Obtains the value of a <strong id="b16303928165631"><a name="b16303928165631"></a><a name="b16303928165631"></a>String</strong> attribute of a configuration tree node. </p>
</td>
</tr>
<tr id="row548003541165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1312098536165631"><a name="p1312098536165631"></a><a name="p1312098536165631"></a><a href="DeviceResourceIface.md#a787eb71963c16c96bca913729078dd9d">GetStringArrayElem</a> )(const struct <a href="DeviceResourceNode.md">DeviceResourceNode</a> *node, const char *attrName, uint32_t <a href="UTILS.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>, const char **value, const char *def)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p482518616165631"><a name="p482518616165631"></a><a name="p482518616165631"></a>int32_t(* </p>
<p id="p1981838426165631"><a name="p1981838426165631"></a><a name="p1981838426165631"></a>Obtains the value of a <strong id="b283795222165631"><a name="b283795222165631"></a><a name="b283795222165631"></a>String</strong> array attribute numbered <strong id="b77121217165631"><a name="b77121217165631"></a><a name="b77121217165631"></a>index</strong> of a configuration tree node. </p>
</td>
</tr>
<tr id="row179464343165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1330439709165631"><a name="p1330439709165631"></a><a name="p1330439709165631"></a><a href="DeviceResourceIface.md#a0fafd4d32592ce2fbe951807995c5ab3">GetElemNum</a> )(const struct <a href="DeviceResourceNode.md">DeviceResourceNode</a> *node, const char *attrName)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1693129563165631"><a name="p1693129563165631"></a><a name="p1693129563165631"></a>int32_t(* </p>
<p id="p851900636165631"><a name="p851900636165631"></a><a name="p851900636165631"></a>Obtains the number of values for an array attribute of a configuration tree node. </p>
</td>
</tr>
<tr id="row2022494257165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1055426215165631"><a name="p1055426215165631"></a><a name="p1055426215165631"></a><a href="DeviceResourceIface.md#a8d7c819ee3d00ded8eef01b0594f3571">GetNodeByMatchAttr</a> )(const struct <a href="DeviceResourceNode.md">DeviceResourceNode</a> *node, const char *attrValue)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p95998987165631"><a name="p95998987165631"></a><a name="p95998987165631"></a>const struct <a href="DeviceResourceNode.md">DeviceResourceNode</a> *(* </p>
<p id="p686087046165631"><a name="p686087046165631"></a><a name="p686087046165631"></a>Obtains a specified child node of the current tree node based on the value of a specific reserved attribute (for example, the reserved attribute of the HCS is <strong id="b946495763165631"><a name="b946495763165631"></a><a name="b946495763165631"></a>match_attr</strong>). </p>
</td>
</tr>
<tr id="row1461243811165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p918816598165631"><a name="p918816598165631"></a><a name="p918816598165631"></a><a href="DeviceResourceIface.md#a70d5844ef0f0c35b9eb3bbba177bccc0">GetChildNode</a> )(const struct <a href="DeviceResourceNode.md">DeviceResourceNode</a> *node, const char *nodeName)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1440769109165631"><a name="p1440769109165631"></a><a name="p1440769109165631"></a>const struct <a href="DeviceResourceNode.md">DeviceResourceNode</a> *(* </p>
<p id="p52480960165631"><a name="p52480960165631"></a><a name="p52480960165631"></a>Obtains the child node with a specified node name from a parent node. </p>
</td>
</tr>
<tr id="row2101977296165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2116030827165631"><a name="p2116030827165631"></a><a name="p2116030827165631"></a><a href="DeviceResourceIface.md#a8066548056633048c008e7a29aac8c8f">GetNodeByRefAttr</a> )(const struct <a href="DeviceResourceNode.md">DeviceResourceNode</a> *node, const char *attrName)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p710320213165631"><a name="p710320213165631"></a><a name="p710320213165631"></a>const struct <a href="DeviceResourceNode.md">DeviceResourceNode</a> *(* </p>
<p id="p1889808401165631"><a name="p1889808401165631"></a><a name="p1889808401165631"></a>Obtains the node that is specified by a node-type attribute of a configuration tree node. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section156908930165631"></a>

## **Field **<a name="section1644935392165631"></a>

## GetBool<a name="a0a3446a50f3644a29cf812af0c915f8a"></a>

```
bool(* DeviceResourceIface::GetBool) (const struct [DeviceResourceNode](DeviceResourceNode.md) *node, const char *attrName)
```

 **Description:**

Obtains the value of a  **BOOL**  attribute of a configuration tree node. 

**Parameters:**

<a name="table351765913165631"></a>
<table><thead align="left"><tr id="row1814056183165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2098039110165631"><a name="p2098039110165631"></a><a name="p2098039110165631"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1831379759165631"><a name="p1831379759165631"></a><a name="p1831379759165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1602715942165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">node</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the configuration tree node. </td>
</tr>
<tr id="row1994088512165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">attrName</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the name of the attribute.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **true**  if the operation is successful and the value of the  **BOOL**  attribute is  **true**; returns  **false**  otherwise. 

## GetChildNode<a name="a70d5844ef0f0c35b9eb3bbba177bccc0"></a>

```
const struct [DeviceResourceNode](DeviceResourceNode.md)*(* DeviceResourceIface::GetChildNode) (const struct [DeviceResourceNode](DeviceResourceNode.md) *node, const char *nodeName)
```

 **Description:**

Obtains the child node with a specified node name from a parent node. 

**Parameters:**

<a name="table601267706165631"></a>
<table><thead align="left"><tr id="row951053068165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p132855589165631"><a name="p132855589165631"></a><a name="p132855589165631"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p95456680165631"><a name="p95456680165631"></a><a name="p95456680165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row532178642165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">node</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the parent node. </td>
</tr>
<tr id="row432575820165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">nodeName</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the name of the child node to obtain.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns the child nodes if the operation is successful; returns  **NULL**  otherwise. 

## GetElemNum<a name="a0fafd4d32592ce2fbe951807995c5ab3"></a>

```
int32_t(* DeviceResourceIface::GetElemNum) (const struct [DeviceResourceNode](DeviceResourceNode.md) *node, const char *attrName)
```

 **Description:**

Obtains the number of values for an array attribute of a configuration tree node. 

**Parameters:**

<a name="table1207729349165631"></a>
<table><thead align="left"><tr id="row343820051165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p755783827165631"><a name="p755783827165631"></a><a name="p755783827165631"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p136127511165631"><a name="p136127511165631"></a><a name="p136127511165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row636064787165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">node</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the configuration tree node. </td>
</tr>
<tr id="row5007959165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">attrName</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the name of the array attribute.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns the number of values for an array attribute if the operation is successful; return a negative value otherwise. 

## GetNodeByMatchAttr<a name="a8d7c819ee3d00ded8eef01b0594f3571"></a>

```
const struct [DeviceResourceNode](DeviceResourceNode.md)*(* DeviceResourceIface::GetNodeByMatchAttr) (const struct [DeviceResourceNode](DeviceResourceNode.md) *node, const char *attrValue)
```

 **Description:**

Obtains a specified child node of the current tree node based on the value of a specific reserved attribute \(for example, the reserved attribute of the HCS is  **match\_attr**\). 

There is a specific reserved attribute in the syntax of the device resource configuration source file. If this attribute is set for a tree node, you can obtain the node based on the attribute value. Users can set the attribute value based on the usage of their own nodes, but they must ensure that the attribute values are unique.

**Parameters:**

<a name="table1254355059165631"></a>
<table><thead align="left"><tr id="row83766968165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p75947005165631"><a name="p75947005165631"></a><a name="p75947005165631"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p577437988165631"><a name="p577437988165631"></a><a name="p577437988165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row382806999165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">node</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the node for whom a child node is to be obtained. The node can be the child node's parent node or grandparent node. </td>
</tr>
<tr id="row275953212165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">attrValue</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the value of the reserved attribute configured for the child node.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns the target node if the operation is successful; returns  **NULL**  otherwise. 

## GetNodeByRefAttr<a name="a8066548056633048c008e7a29aac8c8f"></a>

```
const struct [DeviceResourceNode](DeviceResourceNode.md)*(* DeviceResourceIface::GetNodeByRefAttr) (const struct [DeviceResourceNode](DeviceResourceNode.md) *node, const char *attrName)
```

 **Description:**

Obtains the node that is specified by a node-type attribute of a configuration tree node. 

If the attribute value is a configuration tree node, the path of the node is converted to a globally unique  **hashValue**  when the device resource source file is compiled \(for example, the compilation tool of the HCS source file is hc-gen\). For details about the  **hashValue**, see  **DeviceResourceNode**. When you obtain a tree node using the node-type attribute, you obtain the  **hashValue**  through the node-type attribute first, and then traverse the tree to obtain the tree node corresponding to the  **hashValue**.

**Parameters:**

<a name="table967330752165631"></a>
<table><thead align="left"><tr id="row1124447088165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p309462799165631"><a name="p309462799165631"></a><a name="p309462799165631"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1907754605165631"><a name="p1907754605165631"></a><a name="p1907754605165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row411449890165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">node</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the tree node whose attribute is to obtain. </td>
</tr>
<tr id="row285502209165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">attrName</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the name of attribute whose value is a node path. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the target node if the operation is successful; returns  **NULL**  otherwise. 

## GetRootNode<a name="adc489c2c907ebf9a098c91ba110a2c37"></a>

```
const struct [DeviceResourceNode](DeviceResourceNode.md)*(* DeviceResourceIface::GetRootNode) (void)
```

 **Description:**

Obtains the root node of the configuration tree. 

When the driver framework is started, a configuration tree is created. You can use this function to obtain the root node of the configuration tree.

**Returns:**

Returns the root node of the configuration tree if the operation is successful; returns  **NULL**  otherwise. 

## GetString<a name="a1989a47b8d61401e57ee523e01bc25ee"></a>

```
int32_t(* DeviceResourceIface::GetString) (const struct [DeviceResourceNode](DeviceResourceNode.md) *node, const char *attrName, const char **value, const char *def)
```

 **Description:**

Obtains the value of a  **String**  attribute of a configuration tree node. 

**Parameters:**

<a name="table103638320165631"></a>
<table><thead align="left"><tr id="row1132401881165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p4458590165631"><a name="p4458590165631"></a><a name="p4458590165631"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p421162938165631"><a name="p421162938165631"></a><a name="p421162938165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row303421899165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">node</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the configuration tree node. </td>
</tr>
<tr id="row1917569702165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">attrName</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the name of the attribute. </td>
</tr>
<tr id="row1492695671165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">value</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double pointer to the memory where the obtained data is stored. The string memory is provided by the function implementer. Users only need to transfer the double pointer. The memory cannot be released after being used. </td>
</tr>
<tr id="row1166077188165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">def</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the value to be passed to <strong id="b1288195953165631"><a name="b1288195953165631"></a><a name="b1288195953165631"></a>value</strong> if the operation fails.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a negative value otherwise. 

## GetStringArrayElem<a name="a787eb71963c16c96bca913729078dd9d"></a>

```
int32_t(* DeviceResourceIface::GetStringArrayElem) (const struct [DeviceResourceNode](DeviceResourceNode.md) *node, const char *attrName, uint32_t [index](UTILS.md#ga1d3748ca570dcb09a2fb28e8015107dd), const char **value, const char *def)
```

 **Description:**

Obtains the value of a  **String**  array attribute numbered  **index**  of a configuration tree node. 

**Parameters:**

<a name="table265802527165631"></a>
<table><thead align="left"><tr id="row1400538517165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1578909187165631"><a name="p1578909187165631"></a><a name="p1578909187165631"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p865224502165631"><a name="p865224502165631"></a><a name="p865224502165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row16500108165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">node</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the configuration tree node. </td>
</tr>
<tr id="row262468959165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">attrName</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the name of the array attribute. </td>
</tr>
<tr id="row734895007165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">index</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the number of the index (counting from 0) where the value is to obtain. </td>
</tr>
<tr id="row1243495249165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">value</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double pointer to the memory where the obtained data is stored. The string memory is provided by the function implementer. Users only need to transfer the double pointer. The memory cannot be released after being used. </td>
</tr>
<tr id="row1659537483165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">def</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">def Indicates the value to be passed to <strong id="b203280583165631"><a name="b203280583165631"></a><a name="b203280583165631"></a>value</strong> if the operation fails.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a negative value otherwise. 

## GetUint16<a name="a1d3191febf1c9a0731a1614295a1529b"></a>

```
int32_t(* DeviceResourceIface::GetUint16) (const struct [DeviceResourceNode](DeviceResourceNode.md) *node, const char *attrName, uint16_t *value, uint16_t def)
```

 **Description:**

Obtains the value of a  **Uint16**  attribute of a configuration tree node. 

**Parameters:**

<a name="table168200840165631"></a>
<table><thead align="left"><tr id="row324992704165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2116564454165631"><a name="p2116564454165631"></a><a name="p2116564454165631"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p618666549165631"><a name="p618666549165631"></a><a name="p618666549165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row495243476165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">node</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the configuration tree node. </td>
</tr>
<tr id="row129115217165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">attrName</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the name of the attribute. </td>
</tr>
<tr id="row953197033165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">value</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the memory that stores the obtained data. The memory is applied by the user. </td>
</tr>
<tr id="row1340648067165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">def</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the value to fill into the memory pointed by <strong id="b1158150703165631"><a name="b1158150703165631"></a><a name="b1158150703165631"></a>value</strong> if the operation fails.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a negative value otherwise. 

## GetUint16Array<a name="a54977ca0fd60515bad5e33adf830fc64"></a>

```
int32_t(* DeviceResourceIface::GetUint16Array) (const struct [DeviceResourceNode](DeviceResourceNode.md) *node, const char *attrName, uint16_t *value, uint32_t len, uint16_t def)
```

 **Description:**

Obtains the values of a  **Uint16**  array attribute of a configuration tree node. 

**Parameters:**

<a name="table114371158165631"></a>
<table><thead align="left"><tr id="row1646431700165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p195512333165631"><a name="p195512333165631"></a><a name="p195512333165631"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p312076198165631"><a name="p312076198165631"></a><a name="p312076198165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row113986182165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">node</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the configuration tree node. </td>
</tr>
<tr id="row1696026550165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">attrName</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the name of the array attribute. </td>
</tr>
<tr id="row419655288165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">value</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the array that stores the obtained data. The memory of the array is applied by the user. </td>
</tr>
<tr id="row799533472165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">len</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the length of the array. </td>
</tr>
<tr id="row1784015457165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">def</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the value to fill into <strong id="b909516473165631"><a name="b909516473165631"></a><a name="b909516473165631"></a>value</strong> if the operation fails. If the obtained attribute value contains 32-bit or 64-bit data, the element corresponding to the 32-bit or 64-bit data in the array is filled using the value of <strong id="b1732170865165631"><a name="b1732170865165631"></a><a name="b1732170865165631"></a>def</strong>, and the other elements are filled with the actual value obtained. If the failure is caused by other exceptions, the first element in the array is filled using the value of <strong id="b1835900521165631"><a name="b1835900521165631"></a><a name="b1835900521165631"></a>def</strong>.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a negative value otherwise. 

## GetUint16ArrayElem<a name="a27abcf7cdca0b25b6e620b75590e0a2d"></a>

```
int32_t(* DeviceResourceIface::GetUint16ArrayElem) (const struct [DeviceResourceNode](DeviceResourceNode.md) *node, const char *attrName, uint32_t [index](UTILS.md#ga1d3748ca570dcb09a2fb28e8015107dd), uint16_t *value, uint16_t def)
```

 **Description:**

Obtains the value of a  **Uint16**  array attribute numbered  **index**  of a configuration tree node. 

**Parameters:**

<a name="table1297037794165631"></a>
<table><thead align="left"><tr id="row1779307863165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1360926135165631"><a name="p1360926135165631"></a><a name="p1360926135165631"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p781202887165631"><a name="p781202887165631"></a><a name="p781202887165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1698288886165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">node</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the configuration tree node. </td>
</tr>
<tr id="row1874917821165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">attrName</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the name of the array attribute. </td>
</tr>
<tr id="row1538695303165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">index</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the number of the index (counting from 0) where the value is to obtain. </td>
</tr>
<tr id="row986816033165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">value</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the memory that stores the obtained data. The memory is applied by the user. </td>
</tr>
<tr id="row823902597165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">def</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the value to fill into the memory pointed by <strong id="b694925564165631"><a name="b694925564165631"></a><a name="b694925564165631"></a>value</strong> if the operation fails.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a negative value otherwise. 

## GetUint32<a name="a87cf305ff9cabdbeb5011e6c04106b9e"></a>

```
int32_t(* DeviceResourceIface::GetUint32) (const struct [DeviceResourceNode](DeviceResourceNode.md) *node, const char *attrName, uint32_t *value, uint32_t def)
```

 **Description:**

Obtains the value of a  **Uint32**  attribute of a configuration tree node. 

**Parameters:**

<a name="table1479712765165631"></a>
<table><thead align="left"><tr id="row247042138165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p622559688165631"><a name="p622559688165631"></a><a name="p622559688165631"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1596283604165631"><a name="p1596283604165631"></a><a name="p1596283604165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row797309342165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">node</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the configuration tree node. </td>
</tr>
<tr id="row1522526773165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">attrName</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the name of the attribute. </td>
</tr>
<tr id="row1473050861165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">value</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the memory that stores the obtained data. The memory is applied by the user. </td>
</tr>
<tr id="row820799742165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">def</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the value to fill into the memory pointed by <strong id="b1729540375165631"><a name="b1729540375165631"></a><a name="b1729540375165631"></a>value</strong> if the operation fails.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a negative value otherwise. 

## GetUint32Array<a name="a2ed5d24a45946e270b4416c400839966"></a>

```
int32_t(* DeviceResourceIface::GetUint32Array) (const struct [DeviceResourceNode](DeviceResourceNode.md) *node, const char *attrName, uint32_t *value, uint32_t len, uint32_t def)
```

 **Description:**

Obtains the values of a  **Uint32**  array attribute of a configuration tree node. 

**Parameters:**

<a name="table332568293165631"></a>
<table><thead align="left"><tr id="row2017209802165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1734998669165631"><a name="p1734998669165631"></a><a name="p1734998669165631"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p106848094165631"><a name="p106848094165631"></a><a name="p106848094165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1847194435165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">node</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the configuration tree node. </td>
</tr>
<tr id="row26460753165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">attrName</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the name of the array attribute. </td>
</tr>
<tr id="row1377098875165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">value</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to an array that stores the obtained data. </td>
</tr>
<tr id="row358430152165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">len</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the array that stores the obtained data. The memory of the array is applied by the user. </td>
</tr>
<tr id="row2125105009165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">def</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the value to fill into <strong id="b1378989966165631"><a name="b1378989966165631"></a><a name="b1378989966165631"></a>value</strong> if the operation fails. If the obtained attribute value contains 64-bit data, the element corresponding to the 64-bit data in the array is filled using the value of <strong id="b1354429983165631"><a name="b1354429983165631"></a><a name="b1354429983165631"></a>def</strong>, and the other elements are filled with the actual value obtained. If the failure is caused by other exceptions, the first element in the array is filled using the value of <strong id="b1771556695165631"><a name="b1771556695165631"></a><a name="b1771556695165631"></a>def</strong>.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a negative value otherwise. 

## GetUint32ArrayElem<a name="a942b67fcd814a37d92e33f3de33c2ff5"></a>

```
int32_t(* DeviceResourceIface::GetUint32ArrayElem) (const struct [DeviceResourceNode](DeviceResourceNode.md) *node, const char *attrName, uint32_t [index](UTILS.md#ga1d3748ca570dcb09a2fb28e8015107dd), uint32_t *value, uint32_t def)
```

 **Description:**

Obtains the value of a  **Uint32**  array attribute numbered  **index**  of a configuration tree node. 

**Parameters:**

<a name="table855842718165631"></a>
<table><thead align="left"><tr id="row1537803433165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1373015852165631"><a name="p1373015852165631"></a><a name="p1373015852165631"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p152239038165631"><a name="p152239038165631"></a><a name="p152239038165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row30998081165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">node</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the configuration tree node. </td>
</tr>
<tr id="row936115558165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">attrName</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the name of the array attribute. </td>
</tr>
<tr id="row22226938165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">index</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the number of the index (counting from 0) where the value is to obtain. </td>
</tr>
<tr id="row692726761165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">value</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the memory that stores the obtained data. The memory is applied by the user. </td>
</tr>
<tr id="row1963221285165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">def</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the value to fill into the memory pointed by <strong id="b1898640619165631"><a name="b1898640619165631"></a><a name="b1898640619165631"></a>value</strong> if the operation fails.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a negative value otherwise. 

## GetUint64<a name="a3c364db9381da16449bb96d6be86aed8"></a>

```
int32_t(* DeviceResourceIface::GetUint64) (const struct [DeviceResourceNode](DeviceResourceNode.md) *node, const char *attrName, uint64_t *value, uint64_t def)
```

 **Description:**

Obtains the value of a  **Uint64**  attribute of a configuration tree node. 

**Parameters:**

<a name="table991323790165631"></a>
<table><thead align="left"><tr id="row1766569833165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1422553686165631"><a name="p1422553686165631"></a><a name="p1422553686165631"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p667471269165631"><a name="p667471269165631"></a><a name="p667471269165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row876642205165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">node</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the configuration tree node. </td>
</tr>
<tr id="row727231121165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">attrName</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the name of the attribute. </td>
</tr>
<tr id="row562776807165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">value</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the memory that stores the obtained data. The memory is applied by the user. </td>
</tr>
<tr id="row810850110165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">def</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the value to fill into the memory pointed by <strong id="b198890008165631"><a name="b198890008165631"></a><a name="b198890008165631"></a>value</strong> if the operation fails.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a negative value otherwise. 

## GetUint64Array<a name="ab378caa47c5b01c31ca602d4eaa3046f"></a>

```
int32_t(* DeviceResourceIface::GetUint64Array) (const struct [DeviceResourceNode](DeviceResourceNode.md) *node, const char *attrName, uint64_t *value, uint32_t len, uint64_t def)
```

 **Description:**

Obtains the values of a  **Uint64**  array attribute of a configuration tree node. 

**Parameters:**

<a name="table948261786165631"></a>
<table><thead align="left"><tr id="row1323243244165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2090132676165631"><a name="p2090132676165631"></a><a name="p2090132676165631"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1942116358165631"><a name="p1942116358165631"></a><a name="p1942116358165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1854940008165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">node</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the configuration tree node. </td>
</tr>
<tr id="row143824058165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">attrName</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the name of the array attribute. </td>
</tr>
<tr id="row714973920165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">value</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the array that stores the obtained data. The memory of the array is applied by the user. </td>
</tr>
<tr id="row1894476319165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">len</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the length of the array. </td>
</tr>
<tr id="row1257562460165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">def</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the value to fill into the first element in the <strong id="b2563248165631"><a name="b2563248165631"></a><a name="b2563248165631"></a>value</strong> array if the operation fails.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a negative value otherwise. 

## GetUint64ArrayElem<a name="aac32428eb3762de48514bd14348fd230"></a>

```
int32_t(* DeviceResourceIface::GetUint64ArrayElem) (const struct [DeviceResourceNode](DeviceResourceNode.md) *node, const char *attrName, uint32_t [index](UTILS.md#ga1d3748ca570dcb09a2fb28e8015107dd), uint64_t *value, uint64_t def)
```

 **Description:**

Obtains the value of a  **Uint64**  array attribute numbered  **index**  of a configuration tree node. 

**Parameters:**

<a name="table771181256165631"></a>
<table><thead align="left"><tr id="row1188523666165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p355483395165631"><a name="p355483395165631"></a><a name="p355483395165631"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p993059403165631"><a name="p993059403165631"></a><a name="p993059403165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row546636967165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">node</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the configuration tree node. </td>
</tr>
<tr id="row2020925131165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">attrName</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the name of the array attribute. </td>
</tr>
<tr id="row842440782165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">index</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the number of the index (counting from 0) where the value is to obtain. </td>
</tr>
<tr id="row1161960136165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">value</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the memory that stores the obtained data. The memory is applied by the user. </td>
</tr>
<tr id="row30660007165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">def</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the value to fill into the memory pointed by <strong id="b1409558053165631"><a name="b1409558053165631"></a><a name="b1409558053165631"></a>value</strong> if the operation fails.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a negative value otherwise. 

## GetUint8<a name="a5610a62186ad18320dadcad7077fb3bb"></a>

```
int32_t(* DeviceResourceIface::GetUint8) (const struct [DeviceResourceNode](DeviceResourceNode.md) *node, const char *attrName, uint8_t *value, uint8_t def)
```

 **Description:**

Obtains the value of a  **Uint8**  attribute of a configuration tree node. 

**Parameters:**

<a name="table1510682750165631"></a>
<table><thead align="left"><tr id="row599733021165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p548521990165631"><a name="p548521990165631"></a><a name="p548521990165631"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1013444633165631"><a name="p1013444633165631"></a><a name="p1013444633165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row657397173165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">node</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the configuration tree node. </td>
</tr>
<tr id="row1515955009165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">attrName</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the name of the attribute. </td>
</tr>
<tr id="row1806384387165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">value</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the memory that stores the obtained data. The memory is applied by the user. </td>
</tr>
<tr id="row406054893165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">def</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the value to fill into the memory pointed by <strong id="b24789241165631"><a name="b24789241165631"></a><a name="b24789241165631"></a>value</strong> if the operation fails.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the attribute value is obtained successfully; returns a negative value otherwise. 

## GetUint8Array<a name="a067d741f2c3938ca08be2282e741b0a4"></a>

```
int32_t(* DeviceResourceIface::GetUint8Array) (const struct [DeviceResourceNode](DeviceResourceNode.md) *node, const char *attrName, uint8_t *value, uint32_t len, uint8_t def)
```

 **Description:**

Obtains the values of a  **Uint8**  array attribute of a configuration tree node. 

**Parameters:**

<a name="table1224632520165631"></a>
<table><thead align="left"><tr id="row2047905803165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1541023033165631"><a name="p1541023033165631"></a><a name="p1541023033165631"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p935389431165631"><a name="p935389431165631"></a><a name="p935389431165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row836100333165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">node</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the configuration tree node. </td>
</tr>
<tr id="row1095939957165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">attrName</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the name of the array attribute. </td>
</tr>
<tr id="row523257520165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">value</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the array that stores the obtained data. The memory of the array is applied by the user. </td>
</tr>
<tr id="row1267235733165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">len</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the length of the array. </td>
</tr>
<tr id="row1481903349165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">def</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the value to fill into <strong id="b462144759165631"><a name="b462144759165631"></a><a name="b462144759165631"></a>value</strong> if the operation fails. If the obtained attribute value contains 16-bit, 32-bit, or 64-bit data, the element corresponding to the 16-bit, 32-bit, or 64-bit data in the array is filled using the value of <strong id="b19333478165631"><a name="b19333478165631"></a><a name="b19333478165631"></a>def</strong>, and the other elements are filled with the actual value obtained. If the failure is caused by other exceptions, the first element in the array is filled using the value of <strong id="b1370823017165631"><a name="b1370823017165631"></a><a name="b1370823017165631"></a>def</strong>.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a negative value otherwise. 

## GetUint8ArrayElem<a name="a0973933ace2447ec38a82e7995e2c5af"></a>

```
int32_t(* DeviceResourceIface::GetUint8ArrayElem) (const struct [DeviceResourceNode](DeviceResourceNode.md) *node, const char *attrName, uint32_t [index](UTILS.md#ga1d3748ca570dcb09a2fb28e8015107dd), uint8_t *value, uint8_t def)
```

 **Description:**

Obtains the value of a  **Unit8**  array attribute numbered  **index**  of a configuration tree node. 

**Parameters:**

<a name="table1949947083165631"></a>
<table><thead align="left"><tr id="row518469952165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p275592693165631"><a name="p275592693165631"></a><a name="p275592693165631"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p684069981165631"><a name="p684069981165631"></a><a name="p684069981165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row639358711165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">node</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the configuration tree node. </td>
</tr>
<tr id="row1282436455165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">attrName</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the name of the array attribute. </td>
</tr>
<tr id="row1981614112165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">index</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the number of the index (counting from 0) where the value is to obtain. </td>
</tr>
<tr id="row1315791065165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">value</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the memory that stores the obtained data. The memory is applied by the user. </td>
</tr>
<tr id="row1140015110165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">def</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the value to fill into the memory pointed by <strong id="b1891033513165631"><a name="b1891033513165631"></a><a name="b1891033513165631"></a>value</strong> if the operation fails.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the array attribute value is obtained successfully; returns a negative value otherwise. 

