# WifiMac80211Ops<a name="ZH-CN_TOPIC_0000001054598203"></a>

-   [Overview](#section99086567165636)
-   [Summary](#section52819345165636)
-   [Data Fields](#pub-attribs)

## **Overview**<a name="section99086567165636"></a>

**Related Modules:**

[WLAN](WLAN.md)

**Description:**

Describes MAC-layer control APIs that need to be implemented by the driver. 

**Since:**

1.0

## **Summary**<a name="section52819345165636"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table215476271165636"></a>
<table><thead align="left"><tr id="row1191406100165636"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1810780246165636"><a name="p1810780246165636"></a><a name="p1810780246165636"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1677734765165636"><a name="p1677734765165636"></a><a name="p1677734765165636"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1572516044165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1752954997165636"><a name="p1752954997165636"></a><a name="p1752954997165636"></a><a href="WLAN.md#ga0a4446bf704b9f4b673f68ff97002b1b">changeVirtualIntf</a> )(<a href="NetDevice.md">NetDevice</a> *netDev, uint8_t iftype, uint32_t *flags, struct <a href="VifParams.md">VifParams</a> *params)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p476947643165636"><a name="p476947643165636"></a><a name="p476947643165636"></a>int32_t(* </p>
</td>
</tr>
<tr id="row1209820239165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1570626825165636"><a name="p1570626825165636"></a><a name="p1570626825165636"></a><a href="WLAN.md#ga519c91a244639e25a8c604e284486873">setSsid</a> )(<a href="NetDevice.md">NetDevice</a> *netDev, const uint8_t *ssid, uint32_t ssidLen)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1436402665165636"><a name="p1436402665165636"></a><a name="p1436402665165636"></a>int32_t(* </p>
</td>
</tr>
<tr id="row1951579376165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p724877794165636"><a name="p724877794165636"></a><a name="p724877794165636"></a><a href="WLAN.md#ga37e19745783d5dbf8439b9f1f89ca6f5">setMeshId</a> )(<a href="NetDevice.md">NetDevice</a> *netDev, const char *meshId, uint32_t meshIdLen)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1382109685165636"><a name="p1382109685165636"></a><a name="p1382109685165636"></a>int32_t(* </p>
</td>
</tr>
<tr id="row1624077801165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1274402769165636"><a name="p1274402769165636"></a><a name="p1274402769165636"></a><a href="WLAN.md#ga177446df24b19e4ddca32e9719d6fe8e">setMacAddr</a> )(<a href="NetDevice.md">NetDevice</a> *netDev, <a href="WLAN.md#ga85f7d8a3795887f090e0a6439b1df6e1">Mac80211SetMacParam</a> *param)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p665558411165636"><a name="p665558411165636"></a><a name="p665558411165636"></a>int32_t(* </p>
</td>
</tr>
<tr id="row185425948165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p337956938165636"><a name="p337956938165636"></a><a name="p337956938165636"></a><a href="WLAN.md#ga833043e11a73c8f53cb918e25715939e">changeBeacon</a> )(<a href="NetDevice.md">NetDevice</a> *netDev, <a href="Mac80211beaconParam.md">Mac80211beaconParam</a> *param)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2041361120165636"><a name="p2041361120165636"></a><a name="p2041361120165636"></a>int32_t(* </p>
</td>
</tr>
<tr id="row321303955165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p502452907165636"><a name="p502452907165636"></a><a name="p502452907165636"></a><a href="WLAN.md#ga166ca94a9482995f3e1f58263eeeed02">setChannel</a> )(<a href="NetDevice.md">NetDevice</a> *netDev)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p272227747165636"><a name="p272227747165636"></a><a name="p272227747165636"></a>int32_t(* </p>
</td>
</tr>
<tr id="row137196167165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p194154850165636"><a name="p194154850165636"></a><a name="p194154850165636"></a><a href="WLAN.md#ga367902162f25b7b4c5b80372bb6a81f2">addKey</a> )(struct <a href="NetDevice.md">NetDevice</a> *netdev, uint8_t keyIndex, bool pairwise, const uint8_t *macAddr, struct <a href="KeyParams.md">KeyParams</a> *params)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1732039493165636"><a name="p1732039493165636"></a><a name="p1732039493165636"></a>int32_t(* </p>
</td>
</tr>
<tr id="row468213242165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1220588029165636"><a name="p1220588029165636"></a><a name="p1220588029165636"></a><a href="WLAN.md#ga7edb052049a9420b938085322c6a0418">delKey</a> )(struct <a href="NetDevice.md">NetDevice</a> *netdev, uint8_t keyIndex, bool pairwise, const uint8_t *macAddr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p495161692165636"><a name="p495161692165636"></a><a name="p495161692165636"></a>int32_t(* </p>
</td>
</tr>
<tr id="row495429290165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p160457882165636"><a name="p160457882165636"></a><a name="p160457882165636"></a><a href="WLAN.md#gae4e2e0af8777ab0bae98b1816664bddc">setDefaultKey</a> )(struct <a href="NetDevice.md">NetDevice</a> *netdev, uint8_t keyIndex, bool unicast, bool multicas)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p62214489165636"><a name="p62214489165636"></a><a name="p62214489165636"></a>int32_t(* </p>
</td>
</tr>
<tr id="row1067289015165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1777658828165636"><a name="p1777658828165636"></a><a name="p1777658828165636"></a><a href="WLAN.md#ga203437a6b1d66758f2217f7154ce1210">startAp</a> )(<a href="NetDevice.md">NetDevice</a> *netDev)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1199601327165636"><a name="p1199601327165636"></a><a name="p1199601327165636"></a>int32_t(* </p>
</td>
</tr>
<tr id="row1074757572165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p90196678165636"><a name="p90196678165636"></a><a name="p90196678165636"></a><a href="WLAN.md#gaf30acc8bd9ecd9bffbc46f423423266e">stopAp</a> )(<a href="NetDevice.md">NetDevice</a> *netDev)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p719653098165636"><a name="p719653098165636"></a><a name="p719653098165636"></a>int32_t(* </p>
</td>
</tr>
<tr id="row1034286684165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1669146170165636"><a name="p1669146170165636"></a><a name="p1669146170165636"></a><a href="WLAN.md#ga974552db5307795e70d5868edccecc1c">delStation</a> )(<a href="NetDevice.md">NetDevice</a> *netDev, const uint8_t *macAddr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2110710247165636"><a name="p2110710247165636"></a><a name="p2110710247165636"></a>int32_t(* </p>
</td>
</tr>
<tr id="row931613996165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1307484082165636"><a name="p1307484082165636"></a><a name="p1307484082165636"></a><a href="WLAN.md#ga9f26a0c3e31e1b57cc8b357964cce3db">connect</a> )(<a href="NetDevice.md">NetDevice</a> *netDev, <a href="WifiConnectParams.md">WifiConnectParams</a> *param)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p707423443165636"><a name="p707423443165636"></a><a name="p707423443165636"></a>int32_t(* </p>
</td>
</tr>
<tr id="row1524680917165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p841953125165636"><a name="p841953125165636"></a><a name="p841953125165636"></a><a href="WLAN.md#ga558d3d417f465ca592dc94c3040b2d1f">disconnect</a> )(<a href="NetDevice.md">NetDevice</a> *netDev, uint16_t reasonCode)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p282865874165636"><a name="p282865874165636"></a><a name="p282865874165636"></a>int32_t(* </p>
</td>
</tr>
<tr id="row355472563165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1174924538165636"><a name="p1174924538165636"></a><a name="p1174924538165636"></a><a href="WLAN.md#ga259da70c25a528287c433af2f7bcf530">startScan</a> )(<a href="NetDevice.md">NetDevice</a> *netDev, struct <a href="WifiScanRequest.md">WifiScanRequest</a> *param)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1828550624165636"><a name="p1828550624165636"></a><a name="p1828550624165636"></a>int32_t(* </p>
</td>
</tr>
<tr id="row94470439165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1210951849165636"><a name="p1210951849165636"></a><a name="p1210951849165636"></a><a href="WLAN.md#gab870d8100c1c9cb60b27c75a44bb30d4">abortScan</a> )(<a href="NetDevice.md">NetDevice</a> *netDev)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p470741226165636"><a name="p470741226165636"></a><a name="p470741226165636"></a>int32_t(* </p>
</td>
</tr>
</tbody>
</table>

