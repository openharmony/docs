# osal\_mem.h<a name="ZH-CN_TOPIC_0000001054799575"></a>

-   [Overview](#section264351791165628)
-   [Summary](#section1623289608165628)
-   [Functions](#func-members)

## **Overview**<a name="section264351791165628"></a>

**Related Modules:**

[OSAL](OSAL.md)

**Description:**

Declares the driver memory request and release interfaces. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1623289608165628"></a>

## Functions<a name="func-members"></a>

<a name="table1394391056165628"></a>
<table><thead align="left"><tr id="row1831083381165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2020121311165628"><a name="p2020121311165628"></a><a name="p2020121311165628"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1146345938165628"><a name="p1146345938165628"></a><a name="p1146345938165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row648697050165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p212009161165628"><a name="p212009161165628"></a><a name="p212009161165628"></a><a href="OSAL.md#ga0a1c85eaad6c1588ed091e0e89b74ed2">OsalMemAlloc</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p683337207165628"><a name="p683337207165628"></a><a name="p683337207165628"></a>void * </p>
<p id="p2011018175165628"><a name="p2011018175165628"></a><a name="p2011018175165628"></a>Allocates memory of a specified size. </p>
</td>
</tr>
<tr id="row1554638819165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p813151503165628"><a name="p813151503165628"></a><a name="p813151503165628"></a><a href="OSAL.md#ga7a6d0f6400e835bcbe9ec655bc9f43ee">OsalMemCalloc</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1627805811165628"><a name="p1627805811165628"></a><a name="p1627805811165628"></a>void * </p>
<p id="p529362085165628"><a name="p529362085165628"></a><a name="p529362085165628"></a>Allocates memory of a specified size, and clears the allocated memory. </p>
</td>
</tr>
<tr id="row635022409165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2020778472165628"><a name="p2020778472165628"></a><a name="p2020778472165628"></a><a href="OSAL.md#gaf6d1b6e5583d9e1ca5abf5048bb3bad9">OsalMemAllocAlign</a> (size_t alignment, size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p42340739165628"><a name="p42340739165628"></a><a name="p42340739165628"></a>void * </p>
<p id="p1259830207165628"><a name="p1259830207165628"></a><a name="p1259830207165628"></a>Allocates memory of a specified size, and aligns the memory address on a given boundary. </p>
</td>
</tr>
<tr id="row592645800165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p73189751165628"><a name="p73189751165628"></a><a name="p73189751165628"></a><a href="OSAL.md#ga20dc9c415433effea4d481180a50cfa1">OsalMemFree</a> (void *mem)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p740883761165628"><a name="p740883761165628"></a><a name="p740883761165628"></a>void </p>
<p id="p1769750833165628"><a name="p1769750833165628"></a><a name="p1769750833165628"></a>Releases memory. </p>
</td>
</tr>
</tbody>
</table>

