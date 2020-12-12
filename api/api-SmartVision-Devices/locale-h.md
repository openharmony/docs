# locale.h<a name="ZH-CN_TOPIC_0000001055387984"></a>

-   [Overview](#section622754302165628)
-   [Summary](#section1727967508165628)
-   [Data Structures](#nested-classes)
-   [Macros](#define-members)

## **Overview**<a name="section622754302165628"></a>

**Related Modules:**

[IO](IO.md)

**Description:**

Provides functions to set and obtain the locale language environment. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1727967508165628"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table1970468386165628"></a>
<table><thead align="left"><tr id="row1338253294165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1557119661165628"><a name="p1557119661165628"></a><a name="p1557119661165628"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1393230335165628"><a name="p1393230335165628"></a><a name="p1393230335165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1010076622165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1576987523165628"><a name="p1576987523165628"></a><a name="p1576987523165628"></a><a href="lconv.md">lconv</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1372444350165628"><a name="p1372444350165628"></a><a name="p1372444350165628"></a>Indicates format information about a number. </p>
</td>
</tr>
</tbody>
</table>

## Macros<a name="define-members"></a>

<a name="table713882229165628"></a>
<table><thead align="left"><tr id="row530167195165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p332954361165628"><a name="p332954361165628"></a><a name="p332954361165628"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p713915657165628"><a name="p713915657165628"></a><a name="p713915657165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row310711222165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1068985568165628"><a name="p1068985568165628"></a><a name="p1068985568165628"></a><a href="IO.md#ga07c66689961056725d7f50231d740ba9">LC_CTYPE</a>   0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p606131354165628"><a name="p606131354165628"></a><a name="p606131354165628"></a>Language symbol type, which affects character classification and case conversion. </p>
</td>
</tr>
<tr id="row1218662258165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p447347480165628"><a name="p447347480165628"></a><a name="p447347480165628"></a><a href="IO.md#ga158abb82c565096465ade138c98970d0">LC_NUMERIC</a>   1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p81807616165628"><a name="p81807616165628"></a><a name="p81807616165628"></a>Number type, which affects the number format. </p>
</td>
</tr>
<tr id="row109301173165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1380338050165628"><a name="p1380338050165628"></a><a name="p1380338050165628"></a><a href="IO.md#gaa652c62b53b6bf728d592bfbdc7d5852">LC_TIME</a>   2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1746477329165628"><a name="p1746477329165628"></a><a name="p1746477329165628"></a>Time type, which affects date and time formats. </p>
</td>
</tr>
<tr id="row644333405165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1461512589165628"><a name="p1461512589165628"></a><a name="p1461512589165628"></a><a href="IO.md#gaab9cf7b1a206fb75e5884934c8d676db">LC_COLLATE</a>   3</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p991703434165628"><a name="p991703434165628"></a><a name="p991703434165628"></a>Character sorting type, which affects string comparison and sorting habits. </p>
</td>
</tr>
<tr id="row328181962165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2080455833165628"><a name="p2080455833165628"></a><a name="p2080455833165628"></a><a href="IO.md#ga6d033a83772ef6e6c10dbf13a6a58fb7">LC_MONETARY</a>   4</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p416355514165628"><a name="p416355514165628"></a><a name="p416355514165628"></a>Monetary type, which affects monetary information. </p>
</td>
</tr>
<tr id="row282645018165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2105787320165628"><a name="p2105787320165628"></a><a name="p2105787320165628"></a><a href="IO.md#ga7195d6f0a8d1b9d164a3988a1b8249e8">LC_MESSAGES</a>   5</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1150529830165628"><a name="p1150529830165628"></a><a name="p1150529830165628"></a>Message type, which affects prompt information, error information, status information, titles, labels, buttons, and menus. </p>
</td>
</tr>
<tr id="row133018850165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1789123842165628"><a name="p1789123842165628"></a><a name="p1789123842165628"></a><a href="IO.md#ga9cc5213b5dca4f8e48e64586ee444c33">LC_ALL</a>   6</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1184094435165628"><a name="p1184094435165628"></a><a name="p1184094435165628"></a>All types, which affect all content of locale settings. If <strong id="b1285579497165628"><a name="b1285579497165628"></a><a name="b1285579497165628"></a>LC_ALL</strong> is set, the locale information of all types is set to be consistent with <strong id="b280688041165628"><a name="b280688041165628"></a><a name="b280688041165628"></a>LC_ALL</strong>. </p>
</td>
</tr>
</tbody>
</table>

