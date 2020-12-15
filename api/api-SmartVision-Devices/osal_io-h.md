# osal\_io.h<a name="ZH-CN_TOPIC_0000001055678068"></a>

-   [Overview](#section1499069912165628)
-   [Summary](#section1750465549165628)
-   [Macros](#define-members)
-   [Functions](#func-members)

## **Overview**<a name="section1499069912165628"></a>

**Related Modules:**

[OSAL](OSAL.md)

**Description:**

Declares I/O interfaces. 

This file provides operations, such as reading data from and writing data into an I/O address space, remapping an I/O address space to its virtual address space, and unmapping an I/O virtual address associated with the physical address.

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1750465549165628"></a>

## Macros<a name="define-members"></a>

<a name="table1027884754165628"></a>
<table><thead align="left"><tr id="row1891789561165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1129239065165628"><a name="p1129239065165628"></a><a name="p1129239065165628"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1651629952165628"><a name="p1651629952165628"></a><a name="p1651629952165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row89223992165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1846798169165628"><a name="p1846798169165628"></a><a name="p1846798169165628"></a><a href="OSAL.md#ga48e1f404639550c229aee3ec35a06d79">OSAL_WRITEB</a>(value, address)   writeb(value, address)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p535261551165628"><a name="p535261551165628"></a><a name="p535261551165628"></a>Writes one byte of data into an I/O address space. </p>
</td>
</tr>
<tr id="row1075195764165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1969913399165628"><a name="p1969913399165628"></a><a name="p1969913399165628"></a><a href="OSAL.md#ga3358a86c6bbb6f02ab108964962f441f">OSAL_WRITEW</a>(value, address)   writew(value, address)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p369346133165628"><a name="p369346133165628"></a><a name="p369346133165628"></a>Writes a short integer into an I/O address space. </p>
</td>
</tr>
<tr id="row321416310165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1974701261165628"><a name="p1974701261165628"></a><a name="p1974701261165628"></a><a href="OSAL.md#gaba47d67efad3ad9d1a33a35d2982bd49">OSAL_WRITEL</a>(value, address)   writel(value, address)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2123236353165628"><a name="p2123236353165628"></a><a name="p2123236353165628"></a>Writes an integer into an I/O address space. </p>
</td>
</tr>
<tr id="row1235569383165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1919223033165628"><a name="p1919223033165628"></a><a name="p1919223033165628"></a><a href="OSAL.md#ga3de1529efbdabd4fb2f144c6f48df70b">OSAL_READB</a>(address)   readb(address)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p502276687165628"><a name="p502276687165628"></a><a name="p502276687165628"></a>Reads one byte of data from an I/O address space. </p>
</td>
</tr>
<tr id="row848769688165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1286168044165628"><a name="p1286168044165628"></a><a name="p1286168044165628"></a><a href="OSAL.md#ga8bd523f234f24415fe733addd113e60b">OSAL_READW</a>(address)   readw(address)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p861561197165628"><a name="p861561197165628"></a><a name="p861561197165628"></a>Reads a short integer from an I/O address space. </p>
</td>
</tr>
<tr id="row1650509813165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p271864383165628"><a name="p271864383165628"></a><a name="p271864383165628"></a><a href="OSAL.md#ga14ce14451b2484b2e268a38757237f41">OSAL_READL</a>(address)   readl(address)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p107084247165628"><a name="p107084247165628"></a><a name="p107084247165628"></a>Reads an integer from an I/O address space. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table339670627165628"></a>
<table><thead align="left"><tr id="row901146171165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1633413388165628"><a name="p1633413388165628"></a><a name="p1633413388165628"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p275626578165628"><a name="p275626578165628"></a><a name="p275626578165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row563230736165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1940489976165628"><a name="p1940489976165628"></a><a name="p1940489976165628"></a><a href="OSAL.md#ga281757438906600ef89a13362151d955">OsalIoRemap</a> (unsigned long phys_addr, unsigned long size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p822992276165628"><a name="p822992276165628"></a><a name="p822992276165628"></a>static void * </p>
<p id="p2000840973165628"><a name="p2000840973165628"></a><a name="p2000840973165628"></a>Remaps an I/O physical address to its virtual address. </p>
</td>
</tr>
<tr id="row2083403390165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1963637374165628"><a name="p1963637374165628"></a><a name="p1963637374165628"></a><a href="OSAL.md#ga0a845edb56df0a35beeea338dc5121aa">OsalIoUnmap</a> (void *addr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1199797769165628"><a name="p1199797769165628"></a><a name="p1199797769165628"></a>static void </p>
<p id="p639507478165628"><a name="p639507478165628"></a><a name="p639507478165628"></a>Unmaps an I/O virtual address associated with the physical address. </p>
</td>
</tr>
</tbody>
</table>

