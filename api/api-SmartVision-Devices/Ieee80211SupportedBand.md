# Ieee80211SupportedBand<a name="ZH-CN_TOPIC_0000001054598167"></a>

-   [Overview](#section14902251165632)
-   [Summary](#section1331534402165632)
-   [Data Fields](#pub-attribs)

## **Overview**<a name="section14902251165632"></a>

**Related Modules:**

[WLAN](WLAN.md)

**Description:**

Describes IEEE 802.11 band information. 

**Since:**

1.0

## **Summary**<a name="section1331534402165632"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table2029321219165632"></a>
<table><thead align="left"><tr id="row1685373466165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1215593641165632"><a name="p1215593641165632"></a><a name="p1215593641165632"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1399659574165632"><a name="p1399659574165632"></a><a name="p1399659574165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1230532529165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2011382296165632"><a name="p2011382296165632"></a><a name="p2011382296165632"></a><a href="WLAN.md#ga02df34a92ff5010c8b70ed8cdbd90fb1">channels</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p488125858165632"><a name="p488125858165632"></a><a name="p488125858165632"></a>struct <a href="Ieee80211Channel.md">Ieee80211Channel</a> * </p>
</td>
</tr>
<tr id="row1906466171165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p425407049165632"><a name="p425407049165632"></a><a name="p425407049165632"></a><a href="WLAN.md#ga4a0d4f26cbf81f839b25c2808e50856a">bitrates</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p815481848165632"><a name="p815481848165632"></a><a name="p815481848165632"></a>struct <a href="Ieee80211Rate.md">Ieee80211Rate</a> * </p>
</td>
</tr>
<tr id="row455502427165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1724822793165632"><a name="p1724822793165632"></a><a name="p1724822793165632"></a><a href="WLAN.md#gabfd4562987e1c8b6daea0d10ca8c2751">band</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1427082239165632"><a name="p1427082239165632"></a><a name="p1427082239165632"></a>enum <a href="WLAN.md#ga9882f415202cf9acb0f4cdfbc456a88d">Ieee80211Band</a> </p>
</td>
</tr>
<tr id="row990774316165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2044385083165632"><a name="p2044385083165632"></a><a name="p2044385083165632"></a><a href="WLAN.md#gaf075c96dac24e5b685d35481c78ecb01">nChannels</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p952621562165632"><a name="p952621562165632"></a><a name="p952621562165632"></a>int32_t </p>
</td>
</tr>
<tr id="row1369039504165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p502241244165632"><a name="p502241244165632"></a><a name="p502241244165632"></a><a href="WLAN.md#ga355299d64b9af1d889750bda9216734b">nBitrates</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1997433903165632"><a name="p1997433903165632"></a><a name="p1997433903165632"></a>int32_t </p>
</td>
</tr>
<tr id="row1987838241165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p370133514165632"><a name="p370133514165632"></a><a name="p370133514165632"></a><a href="WLAN.md#gaf1a61194a3fdac2516e391534e5e15d6">htCap</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1824362037165632"><a name="p1824362037165632"></a><a name="p1824362037165632"></a>struct <a href="Ieee80211StaHtCap.md">Ieee80211StaHtCap</a> </p>
</td>
</tr>
</tbody>
</table>

