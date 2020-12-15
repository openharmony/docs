# ScannedBssInfo<a name="EN-US_TOPIC_0000001054479603"></a>

-   [Overview](#section1536667015165636)
-   [Summary](#section364452738165636)
-   [Data Fields](#pub-attribs)

## **Overview**<a name="section1536667015165636"></a>

**Related Modules:**

[WLAN](wlan.md)

**Description:**

Represents the scanned BSS information. 

**Since:**

1.0

## **Summary**<a name="section364452738165636"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table748712838165636"></a>
<table><thead align="left"><tr id="row569146697165636"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1387192961165636"><a name="p1387192961165636"></a><a name="p1387192961165636"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p807257238165636"><a name="p807257238165636"></a><a name="p807257238165636"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1994404656165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p697504402165636"><a name="p697504402165636"></a><a name="p697504402165636"></a><a href="wlan.md#ga20f18f7993df9723a0f3e7520ae715e2">signal</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p397307493165636"><a name="p397307493165636"></a><a name="p397307493165636"></a>int32_t </p>
</td>
</tr>
<tr id="row381101722165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p319462368165636"><a name="p319462368165636"></a><a name="p319462368165636"></a><a href="wlan.md#ga9489887bd02837a40e9560f1a4acd211">freq</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p999174161165636"><a name="p999174161165636"></a><a name="p999174161165636"></a>int16_t </p>
</td>
</tr>
<tr id="row2004425608165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p573641744165636"><a name="p573641744165636"></a><a name="p573641744165636"></a><a href="wlan.md#ga6d31899685b7a552a5322e93b0ffd972">arry</a> [2]</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p632155639165636"><a name="p632155639165636"></a><a name="p632155639165636"></a>uint8_t </p>
</td>
</tr>
<tr id="row203085988165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p298927015165636"><a name="p298927015165636"></a><a name="p298927015165636"></a><a href="wlan.md#gaa40e6cfe80596087c25e256215123890">mgmtLen</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1464509796165636"><a name="p1464509796165636"></a><a name="p1464509796165636"></a>uint32_t </p>
</td>
</tr>
<tr id="row604338530165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p33951463165636"><a name="p33951463165636"></a><a name="p33951463165636"></a><a href="wlan.md#ga345b0140ecaa55ffc7c85bf96548efc9">mgmt</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2079469347165636"><a name="p2079469347165636"></a><a name="p2079469347165636"></a>struct <a href="ieee80211mgmt.md">Ieee80211Mgmt</a> * </p>
</td>
</tr>
</tbody>
</table>

