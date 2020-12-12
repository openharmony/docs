# WifiFeature<a name="EN-US_TOPIC_0000001055678136"></a>

-   [Overview](#section355227530165636)
-   [Summary](#section1137732392165636)
-   [Data Fields](#pub-attribs)

## **Overview**<a name="section355227530165636"></a>

**Related Modules:**

[WLAN](wlan.md)

**Description:**

Defines a WLAN feature. 

**Since:**

1.0

## **Summary**<a name="section1137732392165636"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1860815896165636"></a>
<table><thead align="left"><tr id="row2124290649165636"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p535204166165636"><a name="p535204166165636"></a><a name="p535204166165636"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2085546969165636"><a name="p2085546969165636"></a><a name="p2085546969165636"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1303011588165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1483441851165636"><a name="p1483441851165636"></a><a name="p1483441851165636"></a><a href="wlan.md#gae63e4c5602dbc64bd9905d6b6a4e7aad">name</a> [<a href="wlan.md#gaf460a45a5e365279ca6bc5b3e8750542">MAX_WIFI_COMPONENT_NAME_LEN</a>]</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1308849000165636"><a name="p1308849000165636"></a><a name="p1308849000165636"></a>char </p>
</td>
</tr>
<tr id="row1788281900165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1398163328165636"><a name="p1398163328165636"></a><a name="p1398163328165636"></a><a href="wlan.md#ga213bff4c0d74fb3db3ff7c21bea781ae">chip</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1521562917165636"><a name="p1521562917165636"></a><a name="p1521562917165636"></a>struct <a href="hdfwifichipdata.md">HdfWifiChipData</a> * </p>
</td>
</tr>
<tr id="row1540298441165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1531013660165636"><a name="p1531013660165636"></a><a name="p1531013660165636"></a><a href="wlan.md#ga8b09c66c75ed9515bbf5f76e25c86e57">init</a> )(struct <a href="wififeature.md">WifiFeature</a> *feature)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1637773732165636"><a name="p1637773732165636"></a><a name="p1637773732165636"></a>int32_t(* </p>
</td>
</tr>
<tr id="row695101605165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p860652006165636"><a name="p860652006165636"></a><a name="p860652006165636"></a><a href="wlan.md#gaf03445197e62e8d5cc5de5c7bba185dd">deInit</a> )(struct <a href="wififeature.md">WifiFeature</a> *feature)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p986706683165636"><a name="p986706683165636"></a><a name="p986706683165636"></a>int32_t(* </p>
</td>
</tr>
</tbody>
</table>

