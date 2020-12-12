# NetDevice<a name="ZH-CN_TOPIC_0000001054799609"></a>

-   [Overview](#section1947383746165632)
-   [Summary](#section1882882274165632)
-   [Data Fields](#pub-attribs)

## **Overview**<a name="section1947383746165632"></a>

**Related Modules:**

[WLAN](WLAN.md)

**Description:**

Defines a network device, including the network interface category and name, and network port type. 

**Since:**

1.0

## **Summary**<a name="section1882882274165632"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1483352598165632"></a>
<table><thead align="left"><tr id="row114109549165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p875926470165632"><a name="p875926470165632"></a><a name="p875926470165632"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p992051384165632"><a name="p992051384165632"></a><a name="p992051384165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1133805256165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1130345516165632"><a name="p1130345516165632"></a><a name="p1130345516165632"></a><a href="WLAN.md#ga95102f11976f69a7c700944614fa06b2">netifCateg</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p631775678165632"><a name="p631775678165632"></a><a name="p631775678165632"></a><a href="WLAN.md#ga530241881cd17e03f8ae254ef1d9755e">NetIfCategory</a> </p>
</td>
</tr>
<tr id="row1757133474165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p10143033165632"><a name="p10143033165632"></a><a name="p10143033165632"></a><a href="WLAN.md#ga74b1c5d9a04465f4b47b36ece7470aab">name</a> [IFNAMSIZ]</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1140456177165632"><a name="p1140456177165632"></a><a name="p1140456177165632"></a>char </p>
</td>
</tr>
<tr id="row574039902165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p100589628165632"><a name="p100589628165632"></a><a name="p100589628165632"></a><a href="WLAN.md#ga4758167363bad30116f4bcdb4cc1ae2a">LinkLayerType</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p328128626165632"><a name="p328128626165632"></a><a name="p328128626165632"></a><a href="WLAN.md#gad3175955d2e6ef3c4f52da9b509d5b4a">NetLinkType</a> </p>
</td>
</tr>
<tr id="row603936364165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1925191082165632"><a name="p1925191082165632"></a><a name="p1925191082165632"></a><a href="WLAN.md#ga4a20c090f2e28ed317957d4ed5fc28fd">funType</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p820201734165632"><a name="p820201734165632"></a><a name="p820201734165632"></a><a href="IfType.md">IfType</a> </p>
</td>
</tr>
<tr id="row1237918536165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p86050365165632"><a name="p86050365165632"></a><a name="p86050365165632"></a><a href="WLAN.md#gacbe765a13d3de60f6c4f297234444553">macAddr</a> [<a href="WLAN.md#gae01dbae885bc8abecb82bd865515c081">MAC_ADDR_SIZE</a>]</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1398324197165632"><a name="p1398324197165632"></a><a name="p1398324197165632"></a>char </p>
</td>
</tr>
<tr id="row726697840165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2047769007165632"><a name="p2047769007165632"></a><a name="p2047769007165632"></a><a href="WLAN.md#ga01a8027b2e16aa30a6da3ee99c0f3890">flags</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2070559438165632"><a name="p2070559438165632"></a><a name="p2070559438165632"></a>uint32_t </p>
</td>
</tr>
<tr id="row2005624249165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p687430243165632"><a name="p687430243165632"></a><a name="p687430243165632"></a><a href="WLAN.md#ga3c55b245d63ce32ea02f2890fc8e75a8">mtu</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p846361958165632"><a name="p846361958165632"></a><a name="p846361958165632"></a>uint32_t </p>
</td>
</tr>
<tr id="row1323289203165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1864847639165632"><a name="p1864847639165632"></a><a name="p1864847639165632"></a><a href="WLAN.md#ga480ec41047ece56996f42b0f72a6e079">watchdogTime</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1034144754165632"><a name="p1034144754165632"></a><a name="p1034144754165632"></a>int32_t </p>
</td>
</tr>
<tr id="row1800412588165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1819430821165632"><a name="p1819430821165632"></a><a name="p1819430821165632"></a><a href="WLAN.md#gaf3cfb6012fad954900ccded1305e0e73">lastRxTime</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p683320509165632"><a name="p683320509165632"></a><a name="p683320509165632"></a>uint32_t </p>
</td>
</tr>
<tr id="row1965696563165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p4095004165632"><a name="p4095004165632"></a><a name="p4095004165632"></a><a href="WLAN.md#ga585cec837551180e542b29d263dd585c">hardHeaderLen</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p349377307165632"><a name="p349377307165632"></a><a name="p349377307165632"></a>uint16_t </p>
</td>
</tr>
<tr id="row1296208382165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1418029959165632"><a name="p1418029959165632"></a><a name="p1418029959165632"></a><a href="WLAN.md#ga9241a41c1cb62a68e3d8c93b9dfe4790">neededHeadRoom</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1885078820165632"><a name="p1885078820165632"></a><a name="p1885078820165632"></a>uint16_t </p>
</td>
</tr>
<tr id="row206166399165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1199402621165632"><a name="p1199402621165632"></a><a name="p1199402621165632"></a><a href="WLAN.md#ga3ad6638d07aef608b8d5e4b20a478e03">neededTailRoom</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1547070237165632"><a name="p1547070237165632"></a><a name="p1547070237165632"></a>uint16_t </p>
</td>
</tr>
<tr id="row462364880165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p589488386165632"><a name="p589488386165632"></a><a name="p589488386165632"></a><a href="WLAN.md#gafc2646cdc533135a303ca91bf9ebe7ec">addrLen</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1826736975165632"><a name="p1826736975165632"></a><a name="p1826736975165632"></a>uint8_t </p>
</td>
</tr>
<tr id="row1469378485165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p357520105165632"><a name="p357520105165632"></a><a name="p357520105165632"></a><a href="WLAN.md#gac2b0eefb68664e9458311017ce31275b">mlPriv</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1501677636165632"><a name="p1501677636165632"></a><a name="p1501677636165632"></a>void * </p>
</td>
</tr>
<tr id="row1691441322165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p899068585165632"><a name="p899068585165632"></a><a name="p899068585165632"></a><a href="WLAN.md#ga3d04317fd4d2c8932808d6dd07fedcf4">ieee80211Ptr</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2105649974165632"><a name="p2105649974165632"></a><a name="p2105649974165632"></a>struct <a href="WirelessDev.md">WirelessDev</a> * </p>
</td>
</tr>
<tr id="row44226805165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1968971122165632"><a name="p1968971122165632"></a><a name="p1968971122165632"></a><a href="WLAN.md#ga659f5eb4ee2cef37cb93acea357acb75">specialProcPriv</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p320735652165632"><a name="p320735652165632"></a><a name="p320735652165632"></a>void * </p>
</td>
</tr>
<tr id="row251875998165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p200591268165632"><a name="p200591268165632"></a><a name="p200591268165632"></a><a href="WLAN.md#gaf154f5a9cbf4d297bc6fc7550ae9a819">netDeviceIf</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p807146922165632"><a name="p807146922165632"></a><a name="p807146922165632"></a>struct <a href="NetDeviceInterFace.md">NetDeviceInterFace</a> * </p>
</td>
</tr>
<tr id="row237070841165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1737230671165632"><a name="p1737230671165632"></a><a name="p1737230671165632"></a><a href="WLAN.md#ga6f725a86ac73ba02449952d3f8fbcff9">owner</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1620037701165632"><a name="p1620037701165632"></a><a name="p1620037701165632"></a>struct <a href="NetDevice.md">NetDevice</a> * </p>
</td>
</tr>
<tr id="row1844381352165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1253983165165632"><a name="p1253983165165632"></a><a name="p1253983165165632"></a><a href="WLAN.md#gafdd796dab998fb2ff695af4d50abdc13">stats</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1597374025165632"><a name="p1597374025165632"></a><a name="p1597374025165632"></a>struct NetDevStats </p>
</td>
</tr>
</tbody>
</table>

