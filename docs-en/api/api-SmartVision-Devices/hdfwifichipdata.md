# HdfWifiChipData<a name="EN-US_TOPIC_0000001055678094"></a>

-   [Overview](#section964646321165631)
-   [Summary](#section150586580165631)
-   [Data Fields](#pub-attribs)

## **Overview**<a name="section964646321165631"></a>

**Related Modules:**

[WLAN](wlan.md)

**Description:**

Defines a WLAN chip. 

**Since:**

1.0

## **Summary**<a name="section150586580165631"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1027739507165631"></a>
<table><thead align="left"><tr id="row364862960165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p135756599165631"><a name="p135756599165631"></a><a name="p135756599165631"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p455289294165631"><a name="p455289294165631"></a><a name="p455289294165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1006593415165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1613587156165631"><a name="p1613587156165631"></a><a name="p1613587156165631"></a><a href="wlan.md#ga4c59fb9385e56ed8017ee48d36bac554">type</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1368890312165631"><a name="p1368890312165631"></a><a name="p1368890312165631"></a>uint16_t </p>
</td>
</tr>
<tr id="row227485066165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p18999691165631"><a name="p18999691165631"></a><a name="p18999691165631"></a><a href="wlan.md#ga02ee61c30fc06116d5dee320eda37bfe">name</a> [<a href="wlan.md#gaf460a45a5e365279ca6bc5b3e8750542">MAX_WIFI_COMPONENT_NAME_LEN</a>]</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p457485182165631"><a name="p457485182165631"></a><a name="p457485182165631"></a>char </p>
</td>
</tr>
<tr id="row2095069819165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p297483168165631"><a name="p297483168165631"></a><a name="p297483168165631"></a><a href="wlan.md#ga920007113f95ee9ce9b0d51ca0cf42bc">ops</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p271537040165631"><a name="p271537040165631"></a><a name="p271537040165631"></a>struct <a href="wifimac80211ops.md">WifiMac80211Ops</a> * </p>
</td>
</tr>
<tr id="row1857377150165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1903060200165631"><a name="p1903060200165631"></a><a name="p1903060200165631"></a><a href="wlan.md#gabbafd20c6c6cc8eb20777cdd588b46cd">init</a> )(struct <a href="hdfwifichipdata.md">HdfWifiChipData</a> *chipData, const struct HdfConfigWifiChip *chipConfig)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p107192359165631"><a name="p107192359165631"></a><a name="p107192359165631"></a>int32_t(* </p>
</td>
</tr>
<tr id="row1711832291165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1769031686165631"><a name="p1769031686165631"></a><a name="p1769031686165631"></a><a href="wlan.md#gaf4ad8f670757555c0535b5a5fa5fa8d9">deinit</a> )(struct <a href="hdfwifichipdata.md">HdfWifiChipData</a> *chipData)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1924948465165631"><a name="p1924948465165631"></a><a name="p1924948465165631"></a>int32_t(* </p>
</td>
</tr>
</tbody>
</table>

