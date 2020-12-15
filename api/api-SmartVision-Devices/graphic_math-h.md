# graphic\_math.h<a name="ZH-CN_TOPIC_0000001054879500"></a>

-   [Overview](#section169940290165627)
-   [Summary](#section1582251001165627)
-   [Data Structures](#nested-classes)
-   [Macros](#define-members)

## **Overview**<a name="section169940290165627"></a>

**Related Modules:**

[Graphic](Graphic.md)

**Description:**

Defines mathematical operation functions and types, including trigonometric functions, two-dimensional vectors, three-dimensional vectors, and matrices. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1582251001165627"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table615479880165627"></a>
<table><thead align="left"><tr id="row294990664165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p117876622165627"><a name="p117876622165627"></a><a name="p117876622165627"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1141592462165627"><a name="p1141592462165627"></a><a name="p1141592462165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1966469934165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p15135488165627"><a name="p15135488165627"></a><a name="p15135488165627"></a><a href="OHOS-Vector2-T.md">OHOS::Vector2&lt; T &gt;</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2085308094165627"><a name="p2085308094165627"></a><a name="p2085308094165627"></a>Defines the two-dimensional vector, and provides basic mathematical operations such as vector assignment, scalar product, cross product, addition, and subtraction. </p>
</td>
</tr>
<tr id="row1043399072165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p920319796165627"><a name="p920319796165627"></a><a name="p920319796165627"></a><a href="OHOS-Vector3-T.md">OHOS::Vector3&lt; T &gt;</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1618550835165627"><a name="p1618550835165627"></a><a name="p1618550835165627"></a>Defines the 3-dimensional vector, and provides basic operators such as [] and ==. </p>
</td>
</tr>
<tr id="row718073807165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p195168612165627"><a name="p195168612165627"></a><a name="p195168612165627"></a><a href="OHOS-Matrix3-T.md">OHOS::Matrix3&lt; T &gt;</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2114321366165627"><a name="p2114321366165627"></a><a name="p2114321366165627"></a>Defines a 3 x 3 matrix. </p>
</td>
</tr>
</tbody>
</table>

## Macros<a name="define-members"></a>

<a name="table1640443790165627"></a>
<table><thead align="left"><tr id="row1005035773165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1349712228165627"><a name="p1349712228165627"></a><a name="p1349712228165627"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1693174842165627"><a name="p1693174842165627"></a><a name="p1693174842165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row269498015165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p607896197165627"><a name="p607896197165627"></a><a name="p607896197165627"></a><a href="Graphic.md#ga3e18a38ff2f4dbf813d85d14ae7cc7f6">MATH_MAX</a>(a, b)   ((a) &gt; (b) ? (a) : (b))</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p699259503165627"><a name="p699259503165627"></a><a name="p699259503165627"></a>Larger of a and b. </p>
</td>
</tr>
<tr id="row830073419165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1654678393165627"><a name="p1654678393165627"></a><a name="p1654678393165627"></a><a href="Graphic.md#ga0707ec809a1938e6b07386ce8e403313">MATH_MIN</a>(a, b)   ((a) &lt; (b) ? (a) : (b))</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p35198953165627"><a name="p35198953165627"></a><a name="p35198953165627"></a>Smaller of a and b. </p>
</td>
</tr>
<tr id="row1552158338165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1003597210165627"><a name="p1003597210165627"></a><a name="p1003597210165627"></a><a href="Graphic.md#ga1336a0214be7acc7fb308f2f88542e39">MATH_ABS</a>(x)   ((x) &gt; 0 ? (x) : (-(x)))</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1870448561165627"><a name="p1870448561165627"></a><a name="p1870448561165627"></a>Absolute value of x. </p>
</td>
</tr>
<tr id="row615081308165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p830558212165627"><a name="p830558212165627"></a><a name="p830558212165627"></a><a href="Graphic.md#ga16f420abdb8bee5c5323d203fa1ca43b">MATH_MINUS</a>(a, b)   ((a) &lt; (b) ? ((b) - (a)) : ((a) - (b)))</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1086566952165627"><a name="p1086566952165627"></a><a name="p1086566952165627"></a>Difference between a and b. </p>
</td>
</tr>
</tbody>
</table>

