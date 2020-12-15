# NetDeviceInterFace<a name="EN-US_TOPIC_0000001055039526"></a>

-   [Overview](#section28535630165632)
-   [Summary](#section226138155165632)
-   [Data Fields](#pub-attribs)

## **Overview**<a name="section28535630165632"></a>

**Related Modules:**

[WLAN](wlan.md)

**Description:**

Defines interfaces that need to be implemented externally by network devices, including initializing, opening, and closing a network device. 

**Since:**

1.0

## **Summary**<a name="section226138155165632"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1335914067165632"></a>
<table><thead align="left"><tr id="row578091681165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p872589309165632"><a name="p872589309165632"></a><a name="p872589309165632"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p452549896165632"><a name="p452549896165632"></a><a name="p452549896165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row482155897165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1592528277165632"><a name="p1592528277165632"></a><a name="p1592528277165632"></a><a href="wlan.md#ga24cdc29146b8f84d021328e8a31269a5">init</a> )(struct <a href="netdevice.md">NetDevice</a> *netDev)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1709348059165632"><a name="p1709348059165632"></a><a name="p1709348059165632"></a>int32_t(* </p>
</td>
</tr>
<tr id="row2128972453165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1109259087165632"><a name="p1109259087165632"></a><a name="p1109259087165632"></a><a href="wlan.md#ga371e13402535662210549c3ca3303691">deInit</a> )(struct <a href="netdevice.md">NetDevice</a> *netDev)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p82521663165632"><a name="p82521663165632"></a><a name="p82521663165632"></a>void(* </p>
</td>
</tr>
<tr id="row2055261623165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1527932460165632"><a name="p1527932460165632"></a><a name="p1527932460165632"></a><a href="wlan.md#ga154f75bcfd914b1fb243041186b60a3f">open</a> )(struct <a href="netdevice.md">NetDevice</a> *netDev)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1387989929165632"><a name="p1387989929165632"></a><a name="p1387989929165632"></a>int32_t(* </p>
</td>
</tr>
<tr id="row1308688648165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p843061217165632"><a name="p843061217165632"></a><a name="p843061217165632"></a><a href="wlan.md#ga5e328f3dc0b610672889e66b33bb7cf8">stop</a> )(struct <a href="netdevice.md">NetDevice</a> *netDev)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p20605441165632"><a name="p20605441165632"></a><a name="p20605441165632"></a>int32_t(* </p>
</td>
</tr>
<tr id="row530066603165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1005549678165632"><a name="p1005549678165632"></a><a name="p1005549678165632"></a><a href="wlan.md#ga5d6e31f59da2eef0998deadd40e13304">xmit</a> )(struct <a href="netdevice.md">NetDevice</a> *netDev, struct <a href="netbuf.md">NetBuf</a> *netBuff)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p24242190165632"><a name="p24242190165632"></a><a name="p24242190165632"></a><a href="wlan.md#ga9fb4e578a15db1b0087d7b3831591ced">NetDevTxResult</a>(* </p>
</td>
</tr>
<tr id="row1792561429165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p317984803165632"><a name="p317984803165632"></a><a name="p317984803165632"></a><a href="wlan.md#ga6c3d34c3329316632c7f6b6b19d2f983">ioctl</a> )(struct <a href="netdevice.md">NetDevice</a> *netDev, <a href="ifreq.md">IfReq</a> *req, int32_t cmd)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1477467532165632"><a name="p1477467532165632"></a><a name="p1477467532165632"></a>int32_t(* </p>
</td>
</tr>
<tr id="row51502441165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1250246623165632"><a name="p1250246623165632"></a><a name="p1250246623165632"></a><a href="wlan.md#ga104f6b8049728769f54563aa242850b8">setMacAddr</a> )(struct <a href="netdevice.md">NetDevice</a> *netDev, void *addr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1768977209165632"><a name="p1768977209165632"></a><a name="p1768977209165632"></a>int32_t(* </p>
</td>
</tr>
<tr id="row1491967341165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1587615445165632"><a name="p1587615445165632"></a><a name="p1587615445165632"></a><a href="wlan.md#ga3dcf9dd183845770dc8589eb98e59fce">getStats</a> )(struct <a href="netdevice.md">NetDevice</a> *netDev)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p400209937165632"><a name="p400209937165632"></a><a name="p400209937165632"></a>struct NetDevStats *(* </p>
</td>
</tr>
<tr id="row1937936301165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1565145023165632"><a name="p1565145023165632"></a><a name="p1565145023165632"></a><a href="wlan.md#ga334e7e9c31ff9408ba67aed1cb96a174">setNetIfStatus</a> )(struct <a href="netdevice.md">NetDevice</a> *netDev, <a href="wlan.md#ga0fb482694e5eac3f48c75de1749c8baf">NetIfStatus</a> status)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1552538877165632"><a name="p1552538877165632"></a><a name="p1552538877165632"></a>void(* </p>
</td>
</tr>
<tr id="row806700971165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1886115038165632"><a name="p1886115038165632"></a><a name="p1886115038165632"></a><a href="wlan.md#ga3e08c5be1dbe6e4aa6fc1f930783c295">selectQueue</a> )(struct <a href="netdevice.md">NetDevice</a> *netDev, struct <a href="netbuf.md">NetBuf</a> *netBuff)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1177205981165632"><a name="p1177205981165632"></a><a name="p1177205981165632"></a>uint16_t(* </p>
</td>
</tr>
<tr id="row375000037165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p603006378165632"><a name="p603006378165632"></a><a name="p603006378165632"></a><a href="wlan.md#ga518102ebc29b985161160ae22b066faf">netifNotify</a> )(struct <a href="netdevice.md">NetDevice</a> *netDev, <a href="netdevnotify.md">NetDevNotify</a> *notify)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1176601600165632"><a name="p1176601600165632"></a><a name="p1176601600165632"></a>uint32_t(* </p>
</td>
</tr>
<tr id="row1359356539165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p419527525165632"><a name="p419527525165632"></a><a name="p419527525165632"></a><a href="wlan.md#ga2035c840c71a43b43451bfe0213ca04a">changeMtu</a> )(struct <a href="netdevice.md">NetDevice</a> *netDev, int32_t newMtu)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1139621358165632"><a name="p1139621358165632"></a><a name="p1139621358165632"></a>int32_t(* </p>
</td>
</tr>
<tr id="row923520200165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p360508141165632"><a name="p360508141165632"></a><a name="p360508141165632"></a><a href="wlan.md#ga8bb9ea881b1bdabe8c45f721310823b1">specialEtherTypeProcess</a> )(const struct <a href="netdevice.md">NetDevice</a> *netDev, struct <a href="netbuf.md">NetBuf</a> *buff)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p903847039165632"><a name="p903847039165632"></a><a name="p903847039165632"></a><a href="wlan.md#ga9c1d6e7df4468671742cb76f72b67af1">ProcessingResult</a>(* </p>
</td>
</tr>
</tbody>
</table>

