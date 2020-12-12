# WifiScanRequest<a name="EN-US_TOPIC_0000001055358150"></a>

-   [Overview](#section787413825165636)
-   [Summary](#section1986904495165636)
-   [Data Fields](#pub-attribs)

## **Overview**<a name="section787413825165636"></a>

**Related Modules:**

[WLAN](wlan.md)

**Description:**

Describes scan request parameters. 

**Since:**

1.0

## **Summary**<a name="section1986904495165636"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1357147790165636"></a>
<table><thead align="left"><tr id="row782876752165636"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p145597310165636"><a name="p145597310165636"></a><a name="p145597310165636"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1727482381165636"><a name="p1727482381165636"></a><a name="p1727482381165636"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1011728253165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1177241968165636"><a name="p1177241968165636"></a><a name="p1177241968165636"></a><a href="wlan.md#ga761056fae3d79073bbc33ad3f00a7319">ssids</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p901582261165636"><a name="p901582261165636"></a><a name="p901582261165636"></a>struct <a href="wifissid.md">WifiSsid</a> * </p>
</td>
</tr>
<tr id="row559060930165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1743395918165636"><a name="p1743395918165636"></a><a name="p1743395918165636"></a><a href="wlan.md#gaf7bf0f80492f28c7c285f8023505bb8e">nSsids</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1920317282165636"><a name="p1920317282165636"></a><a name="p1920317282165636"></a>uint32_t </p>
</td>
</tr>
<tr id="row216415683165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1081168012165636"><a name="p1081168012165636"></a><a name="p1081168012165636"></a><a href="wlan.md#ga3150e4a25b1800ee713e08fbf9077116">nChannels</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p555149329165636"><a name="p555149329165636"></a><a name="p555149329165636"></a>uint32_t </p>
</td>
</tr>
<tr id="row890290416165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p31276536165636"><a name="p31276536165636"></a><a name="p31276536165636"></a><a href="wlan.md#gaa26674156ac0814fbc1f45b8e11b7b9f">ieLen</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p445824538165636"><a name="p445824538165636"></a><a name="p445824538165636"></a>uint32_t </p>
</td>
</tr>
<tr id="row186944265165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p894074052165636"><a name="p894074052165636"></a><a name="p894074052165636"></a><a href="wlan.md#ga43dd029f6f34ccb0255e519aded47478">wiphy</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p981874535165636"><a name="p981874535165636"></a><a name="p981874535165636"></a>struct <a href="wiphy.md">Wiphy</a> * </p>
</td>
</tr>
<tr id="row54283863165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p388873148165636"><a name="p388873148165636"></a><a name="p388873148165636"></a><a href="wlan.md#gada8e463843d9e5fef133d41fd745dc42">dev</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1669344798165636"><a name="p1669344798165636"></a><a name="p1669344798165636"></a>struct <a href="netdevice.md">NetDevice</a> * </p>
</td>
</tr>
<tr id="row1081409807165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p107827764165636"><a name="p107827764165636"></a><a name="p107827764165636"></a><a href="wlan.md#ga09f1cdfc6c524ca96aed6b1894baa720">wdev</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p785631754165636"><a name="p785631754165636"></a><a name="p785631754165636"></a>struct <a href="wirelessdev.md">WirelessDev</a> * </p>
</td>
</tr>
<tr id="row1995146676165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1890046012165636"><a name="p1890046012165636"></a><a name="p1890046012165636"></a><a href="wlan.md#ga32ea10f832c5a03971033d5f44f3ef6c">aborted</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p663562196165636"><a name="p663562196165636"></a><a name="p663562196165636"></a>uint8_t </p>
</td>
</tr>
<tr id="row1789104074165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1679601001165636"><a name="p1679601001165636"></a><a name="p1679601001165636"></a><a href="wlan.md#ga5b6c8df255d62a73114aad42c1e4868d">prefixSsidScanFlag</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1906032657165636"><a name="p1906032657165636"></a><a name="p1906032657165636"></a>uint8_t </p>
</td>
</tr>
<tr id="row1596855218165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1779013365165636"><a name="p1779013365165636"></a><a name="p1779013365165636"></a><a href="wlan.md#ga9bb2fd298749eab513163e3a7a2b03ee">resv</a> [SCAN_REQUEST_RESV_SIZE]</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p346868919165636"><a name="p346868919165636"></a><a name="p346868919165636"></a>uint8_t </p>
</td>
</tr>
<tr id="row1845478647165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p66883455165636"><a name="p66883455165636"></a><a name="p66883455165636"></a><a href="wlan.md#ga92b16a60570fd1d28b948ee43f9b0124">ie</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p795002954165636"><a name="p795002954165636"></a><a name="p795002954165636"></a>uint8_t * </p>
</td>
</tr>
<tr id="row1632692775165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p26767548165636"><a name="p26767548165636"></a><a name="p26767548165636"></a><a href="wlan.md#gaabb5ffed3a294507d4f51d598fd98717">channels</a> [MAX_SCAN_CHANNELS]</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1259337941165636"><a name="p1259337941165636"></a><a name="p1259337941165636"></a>struct <a href="ieee80211channel.md">Ieee80211Channel</a> * </p>
</td>
</tr>
</tbody>
</table>

