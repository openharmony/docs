# want.h<a name="EN-US_TOPIC_0000001054799587"></a>

-   [Overview](#section807817544165630)
-   [Summary](#section167245224165630)
-   [Data Structures](#nested-classes)
-   [Functions](#func-members)

## **Overview**<a name="section807817544165630"></a>

**Related Modules:**

[AbilityKit](abilitykit.md)

**Description:**

Declares the structure that provides abstract description of the operation to be performed, including the ability information and the carried data, and functions for setting data in the structure. 

You can use functions provided in this file to specify information about the ability to start.

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section167245224165630"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table773270144165630"></a>
<table><thead align="left"><tr id="row1646275533165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p207713181165630"><a name="p207713181165630"></a><a name="p207713181165630"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2124889538165630"><a name="p2124889538165630"></a><a name="p2124889538165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1934785869165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p657602695165630"><a name="p657602695165630"></a><a name="p657602695165630"></a><a href="want.md">Want</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2084486504165630"><a name="p2084486504165630"></a><a name="p2084486504165630"></a>Defines the abstract description of an operation, including information about the ability and the extra data to carry. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table1148026823165630"></a>
<table><thead align="left"><tr id="row736955540165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p232647041165630"><a name="p232647041165630"></a><a name="p232647041165630"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p718005571165630"><a name="p718005571165630"></a><a name="p718005571165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1520035305165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p591006943165630"><a name="p591006943165630"></a><a name="p591006943165630"></a><a href="abilitykit.md#ga62ca448e092c81497ffdd1f0b1c56938">ClearWant</a> (<a href="want.md">Want</a> *want)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1892737178165630"><a name="p1892737178165630"></a><a name="p1892737178165630"></a>void </p>
<p id="p1900904397165630"><a name="p1900904397165630"></a><a name="p1900904397165630"></a>Clears the memory of a specified <strong id="b1041018243165630"><a name="b1041018243165630"></a><a name="b1041018243165630"></a><a href="want.md">Want</a></strong> object. </p>
</td>
</tr>
<tr id="row1542818591165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p209992372165630"><a name="p209992372165630"></a><a name="p209992372165630"></a><a href="abilitykit.md#ga65f4d2eab99497e496dcd493bd0d047e">SetWantElement</a> (<a href="want.md">Want</a> *want, <a href="elementname.md">ElementName</a> element)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1381226605165630"><a name="p1381226605165630"></a><a name="p1381226605165630"></a>bool </p>
<p id="p1747935924165630"><a name="p1747935924165630"></a><a name="p1747935924165630"></a>Sets the <strong id="b614241236165630"><a name="b614241236165630"></a><a name="b614241236165630"></a>element</strong> variable for a specified <strong id="b942074311165630"><a name="b942074311165630"></a><a name="b942074311165630"></a><a href="want.md">Want</a></strong> object. </p>
</td>
</tr>
<tr id="row737395913165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p648999052165630"><a name="p648999052165630"></a><a name="p648999052165630"></a><a href="abilitykit.md#ga89a719b5f730bc5fde9f637a5ed630c9">SetWantData</a> (<a href="want.md">Want</a> *want, const void *data, uint16_t dataLength)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p239662768165630"><a name="p239662768165630"></a><a name="p239662768165630"></a>bool </p>
<p id="p1554751934165630"><a name="p1554751934165630"></a><a name="p1554751934165630"></a>Sets data to carry in a specified <strong id="b526237381165630"><a name="b526237381165630"></a><a name="b526237381165630"></a><a href="want.md">Want</a></strong> object for starting a particular ability. </p>
</td>
</tr>
<tr id="row1717139108165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1484082181165630"><a name="p1484082181165630"></a><a name="p1484082181165630"></a><a href="abilitykit.md#gab8e5fac952fc6407f20cd9b7185d3a65">SetWantSvcIdentity</a> (<a href="want.md">Want</a> *want, SvcIdentity sid)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2087773365165630"><a name="p2087773365165630"></a><a name="p2087773365165630"></a>bool </p>
<p id="p2102000006165630"><a name="p2102000006165630"></a><a name="p2102000006165630"></a>Sets the <strong id="b451655481165630"><a name="b451655481165630"></a><a name="b451655481165630"></a>sid</strong> member variable for a specified <strong id="b666596297165630"><a name="b666596297165630"></a><a name="b666596297165630"></a><a href="want.md">Want</a></strong> object. </p>
</td>
</tr>
<tr id="row351531887165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1970217353165630"><a name="p1970217353165630"></a><a name="p1970217353165630"></a><a href="abilitykit.md#ga31adc60981c10b22d0e9bbdc7126d17c">WantToUri</a> (<a href="want.md">Want</a> want)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1274134079165630"><a name="p1274134079165630"></a><a name="p1274134079165630"></a>const char * </p>
<p id="p1036388676165630"><a name="p1036388676165630"></a><a name="p1036388676165630"></a>Converts a specified <strong id="b343662571165630"><a name="b343662571165630"></a><a name="b343662571165630"></a><a href="want.md">Want</a></strong> object into a character string. </p>
</td>
</tr>
<tr id="row12855761165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p9908712165630"><a name="p9908712165630"></a><a name="p9908712165630"></a><a href="abilitykit.md#ga43226d0858faa92e83bea33aaf4b614c">WantParseUri</a> (const char *uri)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p863373036165630"><a name="p863373036165630"></a><a name="p863373036165630"></a><a href="want.md">Want</a> * </p>
<p id="p785495839165630"><a name="p785495839165630"></a><a name="p785495839165630"></a>Converts a specified character string into a <strong id="b316339403165630"><a name="b316339403165630"></a><a name="b316339403165630"></a><a href="want.md">Want</a></strong> object. </p>
</td>
</tr>
</tbody>
</table>

