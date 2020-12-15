# TcpHeader<a name="EN-US_TOPIC_0000001054598201"></a>

-   [Overview](#section1543189514165636)
-   [Summary](#section683402754165636)
-   [Data Fields](#pub-attribs)

## **Overview**<a name="section1543189514165636"></a>

**Related Modules:**

[WLAN](wlan.md)

**Description:**

Defines the TCP header information of a data frame, including the source port number and destination port number. 

**Since:**

1.0

## **Summary**<a name="section683402754165636"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1258253794165636"></a>
<table><thead align="left"><tr id="row957267033165636"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p372484470165636"><a name="p372484470165636"></a><a name="p372484470165636"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1425958488165636"><a name="p1425958488165636"></a><a name="p1425958488165636"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row390532129165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p125525975165636"><a name="p125525975165636"></a><a name="p125525975165636"></a><a href="wlan.md#gae29f9cbe74e4e7f7543e74bb8d039f15">sPort</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1342022216165636"><a name="p1342022216165636"></a><a name="p1342022216165636"></a>uint16_t </p>
</td>
</tr>
<tr id="row695057441165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p933765124165636"><a name="p933765124165636"></a><a name="p933765124165636"></a><a href="wlan.md#ga2a188a6b8ee0eccceefe0e17818e8707">dPort</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p804387580165636"><a name="p804387580165636"></a><a name="p804387580165636"></a>uint16_t </p>
</td>
</tr>
<tr id="row718897652165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p689793302165636"><a name="p689793302165636"></a><a name="p689793302165636"></a><a href="wlan.md#ga5409de9f82a50bf5113dafb316118d4b">seqNum</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p941822208165636"><a name="p941822208165636"></a><a name="p941822208165636"></a>uint32_t </p>
</td>
</tr>
<tr id="row1493396848165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p670480125165636"><a name="p670480125165636"></a><a name="p670480125165636"></a><a href="wlan.md#ga223c54c5ebb2d92ed5f6c50115663b86">ackNum</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p255420915165636"><a name="p255420915165636"></a><a name="p255420915165636"></a>uint32_t </p>
</td>
</tr>
<tr id="row429461712165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p320882291165636"><a name="p320882291165636"></a><a name="p320882291165636"></a><a href="wlan.md#gabac9ba66ff160d881083b1f173f411f9">offset</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p930462736165636"><a name="p930462736165636"></a><a name="p930462736165636"></a>uint8_t </p>
</td>
</tr>
<tr id="row315758484165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p362585230165636"><a name="p362585230165636"></a><a name="p362585230165636"></a><a href="wlan.md#ga66be1d87b4d2576cee91cd3867b93701">flags</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p610144225165636"><a name="p610144225165636"></a><a name="p610144225165636"></a>uint8_t </p>
</td>
</tr>
<tr id="row1088302810165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2107413114165636"><a name="p2107413114165636"></a><a name="p2107413114165636"></a><a href="wlan.md#ga55cc45eeabc0f857e51e8864ae45de8e">window</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1401286527165636"><a name="p1401286527165636"></a><a name="p1401286527165636"></a>uint16_t </p>
</td>
</tr>
<tr id="row684272793165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p56039300165636"><a name="p56039300165636"></a><a name="p56039300165636"></a><a href="wlan.md#gab32c75fd1d8d8985d9861157907a3a74">check</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p499661259165636"><a name="p499661259165636"></a><a name="p499661259165636"></a>uint16_t </p>
</td>
</tr>
<tr id="row517720430165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p603266792165636"><a name="p603266792165636"></a><a name="p603266792165636"></a><a href="wlan.md#ga0c402826ed93d697342d8b1108db7754">urgent</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1574479926165636"><a name="p1574479926165636"></a><a name="p1574479926165636"></a>uint16_t </p>
</td>
</tr>
</tbody>
</table>

