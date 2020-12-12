# osal\_file.h<a name="EN-US_TOPIC_0000001054918129"></a>

-   [Overview](#section1236723941165628)
-   [Summary](#section514887224165628)
-   [Data Structures](#nested-classes)
-   [Macros](#define-members)
-   [Functions](#func-members)

## **Overview**<a name="section1236723941165628"></a>

**Related Modules:**

[OSAL](osal.md)

**Description:**

Declares the file structures and interfaces. 

This file provides interfaces for opening, closing, reading, and writing a file, and setting the read/write offset.

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section514887224165628"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table279700510165628"></a>
<table><thead align="left"><tr id="row167175355165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p138897375165628"><a name="p138897375165628"></a><a name="p138897375165628"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p308993412165628"><a name="p308993412165628"></a><a name="p308993412165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1885288094165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p349296775165628"><a name="p349296775165628"></a><a name="p349296775165628"></a><a href="osalfile.md">OsalFile</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1769227540165628"><a name="p1769227540165628"></a><a name="p1769227540165628"></a>Declares a file type. </p>
</td>
</tr>
</tbody>
</table>

## Macros<a name="define-members"></a>

<a name="table2082051989165628"></a>
<table><thead align="left"><tr id="row1984562109165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1065651203165628"><a name="p1065651203165628"></a><a name="p1065651203165628"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1740126809165628"><a name="p1740126809165628"></a><a name="p1740126809165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1473635320165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p933861181165628"><a name="p933861181165628"></a><a name="p933861181165628"></a><a href="osal.md#gab208afeed35dd98f6a0ccf807e9c722d">OSAL_O_RD_ONLY</a>   0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p30363541165628"><a name="p30363541165628"></a><a name="p30363541165628"></a>Opens a file in read-only mode. </p>
</td>
</tr>
<tr id="row1254450708165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1990724619165628"><a name="p1990724619165628"></a><a name="p1990724619165628"></a><a href="osal.md#ga1e37c3fb82a2bcff729f97478bc28f81">OSAL_O_WR_ONLY</a>   1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1558119141165628"><a name="p1558119141165628"></a><a name="p1558119141165628"></a>Opens a file in write-only mode. </p>
</td>
</tr>
<tr id="row1576733771165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1721602911165628"><a name="p1721602911165628"></a><a name="p1721602911165628"></a><a href="osal.md#gabac6ceec2cb877ae0c4c0c89f2e13451">OSAL_O_RDWR</a>   2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p474770173165628"><a name="p474770173165628"></a><a name="p474770173165628"></a>Opens a file in read and write mode. </p>
</td>
</tr>
<tr id="row1683688480165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p357440263165628"><a name="p357440263165628"></a><a name="p357440263165628"></a><a href="osal.md#ga9cb465f6d142e859258e14199702906e">OSAL_S_IREAD</a>   00400</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p241692792165628"><a name="p241692792165628"></a><a name="p241692792165628"></a>Defines the read permission for the owner. </p>
</td>
</tr>
<tr id="row1509200785165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p337284508165628"><a name="p337284508165628"></a><a name="p337284508165628"></a><a href="osal.md#gaf93f6ab3441029a84b5f04904daf68be">OSAL_S_IWRITE</a>   00200</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1316570095165628"><a name="p1316570095165628"></a><a name="p1316570095165628"></a>Defines the write permission for the owner. </p>
</td>
</tr>
<tr id="row1232820036165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1292608322165628"><a name="p1292608322165628"></a><a name="p1292608322165628"></a><a href="osal.md#gaa168a8495f19631b9d4de6e5da688e26">OSAL_S_IEXEC</a>   00100</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1808116880165628"><a name="p1808116880165628"></a><a name="p1808116880165628"></a>Defines the execution permission for the owner. </p>
</td>
</tr>
<tr id="row2126590443165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1417724347165628"><a name="p1417724347165628"></a><a name="p1417724347165628"></a><a href="osal.md#ga008dcb6a04b63ef620c25aa5b41f211a">OSAL_S_IRGRP</a>   00040</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p50653261165628"><a name="p50653261165628"></a><a name="p50653261165628"></a>Defines the read permission for the group. </p>
</td>
</tr>
<tr id="row1138796422165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1294480156165628"><a name="p1294480156165628"></a><a name="p1294480156165628"></a><a href="osal.md#ga982f1e009c6caeb8060e6442a866803f">OSAL_S_IWGRP</a>   00020</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1744603841165628"><a name="p1744603841165628"></a><a name="p1744603841165628"></a>Defines the write permission for the group. </p>
</td>
</tr>
<tr id="row1151492656165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p711834024165628"><a name="p711834024165628"></a><a name="p711834024165628"></a><a href="osal.md#gaa1e6fa403fcd99229902e9a8cd98a74c">OSAL_S_IXGRP</a>   00010</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p591083819165628"><a name="p591083819165628"></a><a name="p591083819165628"></a>Defines the execution permission for the group. </p>
</td>
</tr>
<tr id="row1439995357165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1010188261165628"><a name="p1010188261165628"></a><a name="p1010188261165628"></a><a href="osal.md#ga01e4a94482a048060c250d3d5d899cd6">OSAL_S_IROTH</a>   00004</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p798500243165628"><a name="p798500243165628"></a><a name="p798500243165628"></a>Defines the read permission for others. </p>
</td>
</tr>
<tr id="row1878288229165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p469899703165628"><a name="p469899703165628"></a><a name="p469899703165628"></a><a href="osal.md#gaea63281bfbac42036bb549c2bda2d192">OSAL_S_IWOTH</a>   00002</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1150696442165628"><a name="p1150696442165628"></a><a name="p1150696442165628"></a>Defines the write permission for others. </p>
</td>
</tr>
<tr id="row389867340165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1864265983165628"><a name="p1864265983165628"></a><a name="p1864265983165628"></a><a href="osal.md#ga9e308388be9855050060a87a93191d5e">OSAL_S_IXOTH</a>   00001</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p519812952165628"><a name="p519812952165628"></a><a name="p519812952165628"></a>Defines the execution permission for others. </p>
</td>
</tr>
<tr id="row252889263165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p230122993165628"><a name="p230122993165628"></a><a name="p230122993165628"></a><a href="osal.md#ga110fc469c88e83828679a3dedb4b5f3d">OSAL_SEEK_SET</a>   0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1471817606165628"><a name="p1471817606165628"></a><a name="p1471817606165628"></a>Defines the offset from the file header. </p>
</td>
</tr>
<tr id="row950669985165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2099558211165628"><a name="p2099558211165628"></a><a name="p2099558211165628"></a><a href="osal.md#ga2ae6c04da45367479db0f914b250a0a7">OSAL_SEEK_CUR</a>   1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1820473415165628"><a name="p1820473415165628"></a><a name="p1820473415165628"></a>Defines the offset from the current position. </p>
</td>
</tr>
<tr id="row760296838165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1677111713165628"><a name="p1677111713165628"></a><a name="p1677111713165628"></a><a href="osal.md#gaf282e1e5207b934c0c71ce9558ac1940">OSAL_SEEK_END</a>   2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1939666641165628"><a name="p1939666641165628"></a><a name="p1939666641165628"></a>Defines the offset from the end of the file. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table1995911343165628"></a>
<table><thead align="left"><tr id="row414063010165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1950470248165628"><a name="p1950470248165628"></a><a name="p1950470248165628"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p689235664165628"><a name="p689235664165628"></a><a name="p689235664165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1620924219165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1487095731165628"><a name="p1487095731165628"></a><a name="p1487095731165628"></a><a href="osal.md#ga6707125b6ac5e13912a181877f18f292">OsalFileOpen</a> (<a href="osalfile.md">OsalFile</a> *file, const char *path, int flags, uint32_t rights)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p210191097165628"><a name="p210191097165628"></a><a name="p210191097165628"></a>int32_t </p>
<p id="p568868437165628"><a name="p568868437165628"></a><a name="p568868437165628"></a>Opens a file. </p>
</td>
</tr>
<tr id="row573814370165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1951350405165628"><a name="p1951350405165628"></a><a name="p1951350405165628"></a><a href="osal.md#ga305f575f875ff26bb907c67c23dfb16a">OsalFileWrite</a> (<a href="osalfile.md">OsalFile</a> *file, const void *string, uint32_t length)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p943661694165628"><a name="p943661694165628"></a><a name="p943661694165628"></a>ssize_t </p>
<p id="p2053163291165628"><a name="p2053163291165628"></a><a name="p2053163291165628"></a>Writes a file. </p>
</td>
</tr>
<tr id="row1463891536165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1364570509165628"><a name="p1364570509165628"></a><a name="p1364570509165628"></a><a href="osal.md#ga8786ab2baa8669e79173ab7ab47d67bb">OsalFileClose</a> (<a href="osalfile.md">OsalFile</a> *file)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1109604158165628"><a name="p1109604158165628"></a><a name="p1109604158165628"></a>void </p>
<p id="p2003695682165628"><a name="p2003695682165628"></a><a name="p2003695682165628"></a>Closes a file. </p>
</td>
</tr>
<tr id="row423470417165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p660767518165628"><a name="p660767518165628"></a><a name="p660767518165628"></a><a href="osal.md#gac8ebc8dc4b9ce9725875868f69fd17a8">OsalFileRead</a> (<a href="osalfile.md">OsalFile</a> *file, void *buf, uint32_t length)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1116287114165628"><a name="p1116287114165628"></a><a name="p1116287114165628"></a>ssize_t </p>
<p id="p1477465236165628"><a name="p1477465236165628"></a><a name="p1477465236165628"></a>Reads a file. </p>
</td>
</tr>
<tr id="row1205206402165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p568021087165628"><a name="p568021087165628"></a><a name="p568021087165628"></a><a href="osal.md#gaada4d66f4bb789bb4113e4084da6dea2">OsalFileLseek</a> (<a href="osalfile.md">OsalFile</a> *file, off_t offset, int32_t whence)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p999701665165628"><a name="p999701665165628"></a><a name="p999701665165628"></a>off_t </p>
<p id="p986056287165628"><a name="p986056287165628"></a><a name="p986056287165628"></a>Sets the file read/write offset. </p>
</td>
</tr>
</tbody>
</table>

