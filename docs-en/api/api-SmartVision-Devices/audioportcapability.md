# AudioPortCapability<a name="EN-US_TOPIC_0000001055078131"></a>

-   [Overview](#section1031146899165630)
-   [Summary](#section1554321728165630)
-   [Data Fields](#pub-attribs)

## **Overview**<a name="section1031146899165630"></a>

**Related Modules:**

[Audio](audio.md)

**Description:**

Defines the audio port capability. 

## **Summary**<a name="section1554321728165630"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1032104451165630"></a>
<table><thead align="left"><tr id="row311980998165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p81313791165630"><a name="p81313791165630"></a><a name="p81313791165630"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1640354879165630"><a name="p1640354879165630"></a><a name="p1640354879165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1259383768165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p962612433165630"><a name="p962612433165630"></a><a name="p962612433165630"></a><a href="audio.md#ga00860eb6de81efe5b1654b45617fb902">deviceType</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1826000727165630"><a name="p1826000727165630"></a><a name="p1826000727165630"></a>uint32_t </p>
</td>
</tr>
<tr id="row594975544165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1985603827165630"><a name="p1985603827165630"></a><a name="p1985603827165630"></a><a href="audio.md#ga0485197a750c63938602b339a3b9c77f">deviceId</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1761710587165630"><a name="p1761710587165630"></a><a name="p1761710587165630"></a>uint32_t </p>
</td>
</tr>
<tr id="row961060986165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1003058124165630"><a name="p1003058124165630"></a><a name="p1003058124165630"></a><a href="audio.md#ga377ecdaf229087a7d17c220a65a7162f">hardwareMode</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p621505634165630"><a name="p621505634165630"></a><a name="p621505634165630"></a>bool </p>
</td>
</tr>
<tr id="row1615007138165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p719143383165630"><a name="p719143383165630"></a><a name="p719143383165630"></a><a href="audio.md#gaca895984cf53ddd8769d33c8298b0c6d">formatNum</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1839355529165630"><a name="p1839355529165630"></a><a name="p1839355529165630"></a>uint32_t </p>
</td>
</tr>
<tr id="row620481814165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2102253866165630"><a name="p2102253866165630"></a><a name="p2102253866165630"></a><a href="audio.md#gad01bfa329a21628287ee21df5000e34d">formats</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p173037614165630"><a name="p173037614165630"></a><a name="p173037614165630"></a>enum <a href="audio.md#ga98d5d077cca088ddf77314871474fe59">AudioFormat</a> * </p>
</td>
</tr>
<tr id="row2145287918165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1350403779165630"><a name="p1350403779165630"></a><a name="p1350403779165630"></a><a href="audio.md#ga30c8a08e5d939c0e9844d6d9a165c681">sampleRateMasks</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p237670452165630"><a name="p237670452165630"></a><a name="p237670452165630"></a>uint32_t </p>
</td>
</tr>
<tr id="row726985648165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p691633238165630"><a name="p691633238165630"></a><a name="p691633238165630"></a><a href="audio.md#ga357e90ee8116e04144f57e6f7d3d9efb">channelMasks</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p844176879165630"><a name="p844176879165630"></a><a name="p844176879165630"></a>enum <a href="audio.md#ga137eb03027d5947ea294b32f5095b83c">AudioChannelMask</a> </p>
</td>
</tr>
<tr id="row1963598512165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1022684010165630"><a name="p1022684010165630"></a><a name="p1022684010165630"></a><a href="audio.md#ga48253c4fbc171f241bb0494524891bb1">channelCount</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1452832214165630"><a name="p1452832214165630"></a><a name="p1452832214165630"></a>uint32_t </p>
</td>
</tr>
<tr id="row790813739165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p340179898165630"><a name="p340179898165630"></a><a name="p340179898165630"></a><a href="audio.md#gab784694fd6a60a3d5a3ae404cd6fe6fd">subPortsNum</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p727819451165630"><a name="p727819451165630"></a><a name="p727819451165630"></a>uint32_t </p>
</td>
</tr>
<tr id="row1087760332165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p907373171165630"><a name="p907373171165630"></a><a name="p907373171165630"></a><a href="audio.md#gaccd18b70e7d121169f3df5e53fe055f9">subPorts</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1910824881165630"><a name="p1910824881165630"></a><a name="p1910824881165630"></a>struct <a href="audiosubportcapability.md">AudioSubPortCapability</a> * </p>
</td>
</tr>
</tbody>
</table>

