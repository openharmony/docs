# IpHeader<a name="ZH-CN_TOPIC_0000001055518094"></a>

-   [Overview](#section1856131933165632)
-   [Summary](#section1052057861165632)
-   [Data Fields](#pub-attribs)

## **Overview**<a name="section1856131933165632"></a>

**Related Modules:**

[WLAN](WLAN.md)

**Description:**

Defines the IP header information of a data frame, including the version number, service type, and total length. 

**Since:**

1.0

## **Summary**<a name="section1052057861165632"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1322264937165632"></a>
<table><thead align="left"><tr id="row133936277165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2131990649165632"><a name="p2131990649165632"></a><a name="p2131990649165632"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p149057318165632"><a name="p149057318165632"></a><a name="p149057318165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row463329557165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1691928953165632"><a name="p1691928953165632"></a><a name="p1691928953165632"></a><a href="WLAN.md#gae31602cb3fb4f012749e6d44e73bd5bf">versionAndHl</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p961002220165632"><a name="p961002220165632"></a><a name="p961002220165632"></a>uint8_t </p>
</td>
</tr>
<tr id="row1295448149165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1671525682165632"><a name="p1671525682165632"></a><a name="p1671525682165632"></a><a href="WLAN.md#ga324f15b4a41342c026ce3ad253ed9498">tos</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2036678307165632"><a name="p2036678307165632"></a><a name="p2036678307165632"></a>uint8_t </p>
</td>
</tr>
<tr id="row1986125502165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p420581864165632"><a name="p420581864165632"></a><a name="p420581864165632"></a><a href="WLAN.md#ga35aa269c5b304d238c65aedaa28e3da5">totLen</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1718645618165632"><a name="p1718645618165632"></a><a name="p1718645618165632"></a>uint16_t </p>
</td>
</tr>
<tr id="row2065587742165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p877673313165632"><a name="p877673313165632"></a><a name="p877673313165632"></a><a href="WLAN.md#ga2d5c09b859bc0faddc8a42339973bdd4">id</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1332923578165632"><a name="p1332923578165632"></a><a name="p1332923578165632"></a>uint16_t </p>
</td>
</tr>
<tr id="row2087730690165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1010193495165632"><a name="p1010193495165632"></a><a name="p1010193495165632"></a><a href="WLAN.md#gaf329df46f50a5dcf4dd87c103317401b">fragInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1224771366165632"><a name="p1224771366165632"></a><a name="p1224771366165632"></a>uint16_t </p>
</td>
</tr>
<tr id="row1493269089165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p71614495165632"><a name="p71614495165632"></a><a name="p71614495165632"></a><a href="WLAN.md#gad380e64b2d33d75ce04d65126b54fb8f">ttl</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1737990268165632"><a name="p1737990268165632"></a><a name="p1737990268165632"></a>uint8_t </p>
</td>
</tr>
<tr id="row815555460165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p558826578165632"><a name="p558826578165632"></a><a name="p558826578165632"></a><a href="WLAN.md#ga029ab0914b5854efe279e442aec3b423">protocol</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1111639087165632"><a name="p1111639087165632"></a><a name="p1111639087165632"></a>uint8_t </p>
</td>
</tr>
<tr id="row268398211165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1902157892165632"><a name="p1902157892165632"></a><a name="p1902157892165632"></a><a href="WLAN.md#gaf3b4d16f68ab697df71ca8589f00397c">check</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1099311539165632"><a name="p1099311539165632"></a><a name="p1099311539165632"></a>uint16_t </p>
</td>
</tr>
<tr id="row1247957607165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p160703916165632"><a name="p160703916165632"></a><a name="p160703916165632"></a><a href="WLAN.md#ga22e36dfd118fbe9deee40135f87a0568">sAddr</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p854874056165632"><a name="p854874056165632"></a><a name="p854874056165632"></a>uint32_t </p>
</td>
</tr>
<tr id="row642838745165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p26955081165632"><a name="p26955081165632"></a><a name="p26955081165632"></a><a href="WLAN.md#ga5124eb108341354708e52775df8899ef">dAddr</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1202649955165632"><a name="p1202649955165632"></a><a name="p1202649955165632"></a>uint32_t </p>
</td>
</tr>
</tbody>
</table>

