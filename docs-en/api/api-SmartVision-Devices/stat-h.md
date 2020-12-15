# stat.h<a name="EN-US_TOPIC_0000001055189449"></a>

-   [Overview](#section1651300868165629)
-   [Summary](#section1734096236165629)
-   [Data Structures](#nested-classes)
-   [Functions](#func-members)

## **Overview**<a name="section1651300868165629"></a>

**Related Modules:**

[FS](fs.md)

**Description:**

Provides functions for file and directory operations. 

These functions can be used for file system operations, such as file read/write, directory traversal, and file system mounting.

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1734096236165629"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table601255422165629"></a>
<table><thead align="left"><tr id="row1893552143165629"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p111073429165629"><a name="p111073429165629"></a><a name="p111073429165629"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1488097080165629"><a name="p1488097080165629"></a><a name="p1488097080165629"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row165570440165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p685433410165629"><a name="p685433410165629"></a><a name="p685433410165629"></a><a href="stat.md">stat</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1654483158165629"><a name="p1654483158165629"></a><a name="p1654483158165629"></a>Defines the file information structure. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table1744838374165629"></a>
<table><thead align="left"><tr id="row540531160165629"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p366093226165629"><a name="p366093226165629"></a><a name="p366093226165629"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1122614979165629"><a name="p1122614979165629"></a><a name="p1122614979165629"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1729723570165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1043269184165629"><a name="p1043269184165629"></a><a name="p1043269184165629"></a><a href="fs.md#gad2e0bcbe40344116102877f6268ee6ea">stat</a> (const char *__restrict path, struct <a href="stat.md">stat</a> *__restrict buf)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1026800915165629"><a name="p1026800915165629"></a><a name="p1026800915165629"></a>int </p>
<p id="p625438062165629"><a name="p625438062165629"></a><a name="p625438062165629"></a>Obtains file information. </p>
</td>
</tr>
<tr id="row3247904165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p907305803165629"><a name="p907305803165629"></a><a name="p907305803165629"></a><a href="fs.md#ga198a57e185e8a036ad06345623b84521">fstat</a> (int fd, struct <a href="stat.md">stat</a> *buf)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p543575877165629"><a name="p543575877165629"></a><a name="p543575877165629"></a>int </p>
<p id="p395536915165629"><a name="p395536915165629"></a><a name="p395536915165629"></a>Obtains file status information. </p>
</td>
</tr>
<tr id="row1515513331165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1797098891165629"><a name="p1797098891165629"></a><a name="p1797098891165629"></a><a href="fs.md#ga879b7c433a19b6b07b42edcf3871c40f">lstat</a> (const char *__restrict path, struct <a href="stat.md">stat</a> *__restrict buf)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2559506165629"><a name="p2559506165629"></a><a name="p2559506165629"></a>int </p>
<p id="p1989991958165629"><a name="p1989991958165629"></a><a name="p1989991958165629"></a>Obtains file information. </p>
</td>
</tr>
<tr id="row1108950883165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1292907396165629"><a name="p1292907396165629"></a><a name="p1292907396165629"></a><a href="fs.md#gaee98bbe743c2d14dbaa67f01c3fb9ed5">mkdir</a> (const char *pathname, mode_t mode)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1285230469165629"><a name="p1285230469165629"></a><a name="p1285230469165629"></a>int </p>
<p id="p1624896208165629"><a name="p1624896208165629"></a><a name="p1624896208165629"></a>Creates a directory. </p>
</td>
</tr>
<tr id="row1652233731165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p742320865165629"><a name="p742320865165629"></a><a name="p742320865165629"></a><a href="fs.md#ga6b0f61de936f648da290c92ed36192c4">mkfifo</a> (const char *name, mode_t mode)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p998531333165629"><a name="p998531333165629"></a><a name="p998531333165629"></a>int </p>
<p id="p1566046268165629"><a name="p1566046268165629"></a><a name="p1566046268165629"></a>Creates a named pipe to implement inter-process communication. </p>
</td>
</tr>
<tr id="row1804023050165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p437734412165629"><a name="p437734412165629"></a><a name="p437734412165629"></a><a href="fs.md#gae0b68526355956a8e3298fcb6a72e3bc">mkdirat</a> (int fd, const char *pathname, mode_t mode)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1600313344165629"><a name="p1600313344165629"></a><a name="p1600313344165629"></a>int </p>
<p id="p1586585909165629"><a name="p1586585909165629"></a><a name="p1586585909165629"></a>Creates a directory. </p>
</td>
</tr>
<tr id="row151161209165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2100683725165629"><a name="p2100683725165629"></a><a name="p2100683725165629"></a><a href="fs.md#ga1b893413bc424887bbe61f8d0952a0ee">chmod</a> (const char *pathname, mode_t mode)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1343963985165629"><a name="p1343963985165629"></a><a name="p1343963985165629"></a>int </p>
<p id="p1508260849165629"><a name="p1508260849165629"></a><a name="p1508260849165629"></a>Modifies permissions for a file. </p>
</td>
</tr>
<tr id="row2025331880165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1405609090165629"><a name="p1405609090165629"></a><a name="p1405609090165629"></a><a href="fs.md#ga556063623e479c26c64544024a046024">umask</a> (mode_t mode)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p132837906165629"><a name="p132837906165629"></a><a name="p132837906165629"></a>mode_t </p>
<p id="p372862181165629"><a name="p372862181165629"></a><a name="p372862181165629"></a>Sets umask for a process. </p>
</td>
</tr>
</tbody>
</table>

