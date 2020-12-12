# resource.h<a name="EN-US_TOPIC_0000001055108025"></a>

-   [Overview](#section804036567165628)
-   [Summary](#section793825687165628)
-   [Macros](#define-members)
-   [Functions](#func-members)

## **Overview**<a name="section804036567165628"></a>

**Related Modules:**

[PROCESS](process.md)

**Description:**

Declares process-related structures and functions. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section793825687165628"></a>

## Macros<a name="define-members"></a>

<a name="table1977800813165628"></a>
<table><thead align="left"><tr id="row6415104165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p802746387165628"><a name="p802746387165628"></a><a name="p802746387165628"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1878933332165628"><a name="p1878933332165628"></a><a name="p1878933332165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1020833340165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1441627254165628"><a name="p1441627254165628"></a><a name="p1441627254165628"></a><a href="process.md#ga5aab1c88012d4b577b034e9291e87419">PRIO_PROCESS</a>   0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p454983528165628"><a name="p454983528165628"></a><a name="p454983528165628"></a>Defines a process ID. </p>
</td>
</tr>
<tr id="row1016917225165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2110801378165628"><a name="p2110801378165628"></a><a name="p2110801378165628"></a><a href="process.md#ga9156ecb2854d071998278d63a107a215">PRIO_PGRP</a>   1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p557206478165628"><a name="p557206478165628"></a><a name="p557206478165628"></a>Defines a process group ID. </p>
</td>
</tr>
<tr id="row1044572081165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1445364102165628"><a name="p1445364102165628"></a><a name="p1445364102165628"></a><a href="process.md#gaee947842544cb755f74360d1da4aa193">PRIO_USER</a>   2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1756419902165628"><a name="p1756419902165628"></a><a name="p1756419902165628"></a>Defines a valid user ID. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table764953353165628"></a>
<table><thead align="left"><tr id="row1717223452165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2109614803165628"><a name="p2109614803165628"></a><a name="p2109614803165628"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p214978936165628"><a name="p214978936165628"></a><a name="p214978936165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1668707585165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1298357411165628"><a name="p1298357411165628"></a><a name="p1298357411165628"></a><a href="process.md#gac2ee4921a8961060b4c7fcad8bf2b4e2">getpriority</a> (int which, <a href="utils.md#gab66157aef1dc726dccc825f07239da53">id_t</a> who)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p172408476165628"><a name="p172408476165628"></a><a name="p172408476165628"></a>int </p>
<p id="p1142031968165628"><a name="p1142031968165628"></a><a name="p1142031968165628"></a>Obtains the static priority of a specified ID. </p>
</td>
</tr>
<tr id="row925970088165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p187216906165628"><a name="p187216906165628"></a><a name="p187216906165628"></a><a href="process.md#ga0a8d4c8043a7748c25dd551dc69dcad2">setpriority</a> (int which, <a href="utils.md#gab66157aef1dc726dccc825f07239da53">id_t</a> who, int value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p879036949165628"><a name="p879036949165628"></a><a name="p879036949165628"></a>int </p>
<p id="p72050081165628"><a name="p72050081165628"></a><a name="p72050081165628"></a>Sets the static priority of a specified ID. </p>
</td>
</tr>
</tbody>
</table>

