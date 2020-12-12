# Wiphy<a name="EN-US_TOPIC_0000001054479605"></a>

-   [Overview](#section914145313165636)
-   [Summary](#section1052327218165636)
-   [Data Fields](#pub-attribs)

## **Overview**<a name="section914145313165636"></a>

**Related Modules:**

[WLAN](wlan.md)

**Description:**

Describes a wiphy device. 

**Since:**

1.0

## **Summary**<a name="section1052327218165636"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table487213425165636"></a>
<table><thead align="left"><tr id="row747840710165636"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1825854131165636"><a name="p1825854131165636"></a><a name="p1825854131165636"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p706638314165636"><a name="p706638314165636"></a><a name="p706638314165636"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1413269096165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1727036709165636"><a name="p1727036709165636"></a><a name="p1727036709165636"></a><a href="wlan.md#ga5396b8e87fe6a6be0c7dd789fe289c50">permAddr</a> [WLAN_MAC_ADDR_LEN]</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1254474390165636"><a name="p1254474390165636"></a><a name="p1254474390165636"></a>uint8_t </p>
</td>
</tr>
<tr id="row1044219100165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p177276138165636"><a name="p177276138165636"></a><a name="p177276138165636"></a><a href="wlan.md#ga8d1059e645ca6684e9ea82044e03270b">addrMask</a> [WLAN_MAC_ADDR_LEN]</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1456780872165636"><a name="p1456780872165636"></a><a name="p1456780872165636"></a>uint8_t </p>
</td>
</tr>
<tr id="row1374446036165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1096343724165636"><a name="p1096343724165636"></a><a name="p1096343724165636"></a><a href="wlan.md#ga0f4b1664afa7f688b0e7fe974e8676a2">flags</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p399268185165636"><a name="p399268185165636"></a><a name="p399268185165636"></a>uint32_t </p>
</td>
</tr>
<tr id="row617447764165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2083952852165636"><a name="p2083952852165636"></a><a name="p2083952852165636"></a><a href="wlan.md#ga0c0e8af92ed7d85cbcc04bcf4f13a8b7">signalType</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1658474836165636"><a name="p1658474836165636"></a><a name="p1658474836165636"></a>uint8_t </p>
</td>
</tr>
<tr id="row1427276006165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1531551580165636"><a name="p1531551580165636"></a><a name="p1531551580165636"></a><a href="wlan.md#gac64622da7ddfc981d13380a66321ee61">maxScanSsids</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p469065123165636"><a name="p469065123165636"></a><a name="p469065123165636"></a>uint8_t </p>
</td>
</tr>
<tr id="row2130762681165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1316488975165636"><a name="p1316488975165636"></a><a name="p1316488975165636"></a><a href="wlan.md#ga33ab965c40e11c007cadf1116113ca21">interfaceModes</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p370157862165636"><a name="p370157862165636"></a><a name="p370157862165636"></a>uint16_t </p>
</td>
</tr>
<tr id="row1233785860165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p920174728165636"><a name="p920174728165636"></a><a name="p920174728165636"></a><a href="wlan.md#ga249fb8ce5c398f3c6588519e58cd11e9">maxScanIeLen</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1899085419165636"><a name="p1899085419165636"></a><a name="p1899085419165636"></a>uint16_t </p>
</td>
</tr>
<tr id="row1895820965165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1654667990165636"><a name="p1654667990165636"></a><a name="p1654667990165636"></a><a href="wlan.md#gabdd49dff12ed26c47f1935fb2bf3d873">aucRsv</a> [WIPHY_RSV_SIZE]</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p890051265165636"><a name="p890051265165636"></a><a name="p890051265165636"></a>uint8_t </p>
</td>
</tr>
<tr id="row1041439546165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1308984918165636"><a name="p1308984918165636"></a><a name="p1308984918165636"></a><a href="wlan.md#gab6cb6ce28cef7f1f5dc0d19380e8ad05">nCipherSuites</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1374356708165636"><a name="p1374356708165636"></a><a name="p1374356708165636"></a>int32_t </p>
</td>
</tr>
<tr id="row399693092165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1567956832165636"><a name="p1567956832165636"></a><a name="p1567956832165636"></a><a href="wlan.md#ga011f5a473787d4700441e4bf7387673a">cipherSuites</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p446377729165636"><a name="p446377729165636"></a><a name="p446377729165636"></a>const uint32_t * </p>
</td>
</tr>
<tr id="row1333729519165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1716096570165636"><a name="p1716096570165636"></a><a name="p1716096570165636"></a><a href="wlan.md#gafa733ea2e4b2efa2dc10938956a95f85">fragThreshold</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1831586924165636"><a name="p1831586924165636"></a><a name="p1831586924165636"></a>uint32_t </p>
</td>
</tr>
<tr id="row607583520165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p501873665165636"><a name="p501873665165636"></a><a name="p501873665165636"></a><a href="wlan.md#ga00874e60aa7dc8c7455732e633586813">rtsThreshold</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1692058875165636"><a name="p1692058875165636"></a><a name="p1692058875165636"></a>uint32_t </p>
</td>
</tr>
<tr id="row384388621165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p468064275165636"><a name="p468064275165636"></a><a name="p468064275165636"></a><a href="wlan.md#gaf3ab07acceaeff1edc793cb23d739ec5">bands</a> [<a href="wlan.md#gga9882f415202cf9acb0f4cdfbc456a88da703cf67d516a80d6dae1b1995017b9a4">IEEE80211_NUM_BANDS</a>]</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p262771771165636"><a name="p262771771165636"></a><a name="p262771771165636"></a>struct <a href="ieee80211supportedband.md">Ieee80211SupportedBand</a> * </p>
</td>
</tr>
<tr id="row2003823216165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p201031809165636"><a name="p201031809165636"></a><a name="p201031809165636"></a><a href="wlan.md#ga760737c03ad122b360ca8ed814869e4b">priv</a> [WIPHY_PRIV_SIZE]</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1841689193165636"><a name="p1841689193165636"></a><a name="p1841689193165636"></a>uint8_t </p>
</td>
</tr>
</tbody>
</table>

