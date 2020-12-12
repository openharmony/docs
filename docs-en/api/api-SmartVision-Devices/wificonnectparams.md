# WifiConnectParams<a name="EN-US_TOPIC_0000001055078181"></a>

-   [Overview](#section215637015165636)
-   [Summary](#section1406209241165636)
-   [Data Fields](#pub-attribs)

## **Overview**<a name="section215637015165636"></a>

**Related Modules:**

[WLAN](wlan.md)

**Description:**

Describes parameters for a connection request. 

**Since:**

1.0

## **Summary**<a name="section1406209241165636"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1671510484165636"></a>
<table><thead align="left"><tr id="row1364073816165636"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1040463327165636"><a name="p1040463327165636"></a><a name="p1040463327165636"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1200998485165636"><a name="p1200998485165636"></a><a name="p1200998485165636"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1383011665165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1712401913165636"><a name="p1712401913165636"></a><a name="p1712401913165636"></a><a href="wlan.md#ga0c59333afe2ac58387c92260a8268de7">channel</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p669471347165636"><a name="p669471347165636"></a><a name="p669471347165636"></a>struct <a href="ieee80211channel.md">Ieee80211Channel</a> * </p>
</td>
</tr>
<tr id="row1835476391165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1314227081165636"><a name="p1314227081165636"></a><a name="p1314227081165636"></a><a href="wlan.md#gaf088c497d633df51d8bee24e7a778c22">bssid</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p194402713165636"><a name="p194402713165636"></a><a name="p194402713165636"></a>uint8_t * </p>
</td>
</tr>
<tr id="row764158590165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p325240269165636"><a name="p325240269165636"></a><a name="p325240269165636"></a><a href="wlan.md#ga875dd450960cc445dd2a12355bc6912c">ssid</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p37476567165636"><a name="p37476567165636"></a><a name="p37476567165636"></a>uint8_t * </p>
</td>
</tr>
<tr id="row1413145747165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p506798665165636"><a name="p506798665165636"></a><a name="p506798665165636"></a><a href="wlan.md#ga8274aa0c44fe19a615c38c67eb799c87">ie</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1141229432165636"><a name="p1141229432165636"></a><a name="p1141229432165636"></a>uint8_t * </p>
</td>
</tr>
<tr id="row753960643165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p433019940165636"><a name="p433019940165636"></a><a name="p433019940165636"></a><a href="wlan.md#ga18a38015e45de3571893b8c1edea991a">ssidLen</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p677928831165636"><a name="p677928831165636"></a><a name="p677928831165636"></a>uint32_t </p>
</td>
</tr>
<tr id="row1918183699165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2076707448165636"><a name="p2076707448165636"></a><a name="p2076707448165636"></a><a href="wlan.md#gad5c61386055631b64c953fa46c2aad24">ieLen</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p924975470165636"><a name="p924975470165636"></a><a name="p924975470165636"></a>uint32_t </p>
</td>
</tr>
<tr id="row1495289934165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1614295662165636"><a name="p1614295662165636"></a><a name="p1614295662165636"></a><a href="wlan.md#gaa91e37ddf709a3553a6352623ea8c341">crypto</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1444606663165636"><a name="p1444606663165636"></a><a name="p1444606663165636"></a>struct <a href="cryptosettings.md">CryptoSettings</a> </p>
</td>
</tr>
<tr id="row1128346399165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1273590188165636"><a name="p1273590188165636"></a><a name="p1273590188165636"></a><a href="wlan.md#ga6ca72a4cfcb196dda7c2ca2562a1b20b">key</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1583334014165636"><a name="p1583334014165636"></a><a name="p1583334014165636"></a>const uint8_t * </p>
</td>
</tr>
<tr id="row211378995165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p791497356165636"><a name="p791497356165636"></a><a name="p791497356165636"></a><a href="wlan.md#ga2c9cdaa7b998a7ffb4378f4a6cedbb75">authType</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2032316211165636"><a name="p2032316211165636"></a><a name="p2032316211165636"></a>uint8_t </p>
</td>
</tr>
<tr id="row96130914165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p570470218165636"><a name="p570470218165636"></a><a name="p570470218165636"></a><a href="wlan.md#ga81e32b68cb7ae4a68b1d42633fc181fe">privacy</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1169012960165636"><a name="p1169012960165636"></a><a name="p1169012960165636"></a>uint8_t </p>
</td>
</tr>
<tr id="row13553950165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1268223687165636"><a name="p1268223687165636"></a><a name="p1268223687165636"></a><a href="wlan.md#ga98603c2c633e6ca1ad940269cfb01e58">keyLen</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p928280112165636"><a name="p928280112165636"></a><a name="p928280112165636"></a>uint8_t </p>
</td>
</tr>
<tr id="row1113056771165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p134190814165636"><a name="p134190814165636"></a><a name="p134190814165636"></a><a href="wlan.md#ga27eb8efb66b131f8495baf2dcaee6eb6">keyIdx</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p588229553165636"><a name="p588229553165636"></a><a name="p588229553165636"></a>uint8_t </p>
</td>
</tr>
<tr id="row179775733165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1615525256165636"><a name="p1615525256165636"></a><a name="p1615525256165636"></a><a href="wlan.md#ga8212747b66b319e95586ad90d4191300">mfp</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1377816606165636"><a name="p1377816606165636"></a><a name="p1377816606165636"></a>uint8_t </p>
</td>
</tr>
<tr id="row2058081110165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1203438345165636"><a name="p1203438345165636"></a><a name="p1203438345165636"></a><a href="wlan.md#gac0b10633f99311af30dd220ae9d19e34">aucResv</a> [WIFI_CONNECT_PARM_RESV_SIZE]</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1815939212165636"><a name="p1815939212165636"></a><a name="p1815939212165636"></a>uint8_t </p>
</td>
</tr>
</tbody>
</table>

