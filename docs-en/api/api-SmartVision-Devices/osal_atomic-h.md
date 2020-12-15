# osal\_atomic.h<a name="EN-US_TOPIC_0000001054598135"></a>

-   [Overview](#section1874200677165628)
-   [Summary](#section151742198165628)
-   [Data Structures](#nested-classes)
-   [Functions](#func-members)

## **Overview**<a name="section1874200677165628"></a>

**Related Modules:**

[OSAL](osal.md)

**Description:**

Declares atomic and bit operation interfaces. 

This file provides interfaces such as reading and setting an atomic, incrementing and decrementing an atomic counter by 1. This file also provides interfaces such as checking the bit status of a variable, and setting and clearing the bit value of a variable.

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section151742198165628"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table568390195165628"></a>
<table><thead align="left"><tr id="row958383795165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p415956263165628"><a name="p415956263165628"></a><a name="p415956263165628"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p560558006165628"><a name="p560558006165628"></a><a name="p560558006165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1123203724165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1780537238165628"><a name="p1780537238165628"></a><a name="p1780537238165628"></a><a href="osalatomic.md">OsalAtomic</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1845733684165628"><a name="p1845733684165628"></a><a name="p1845733684165628"></a>Describes an atomic. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table411839865165628"></a>
<table><thead align="left"><tr id="row293451604165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1503537959165628"><a name="p1503537959165628"></a><a name="p1503537959165628"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p132506227165628"><a name="p132506227165628"></a><a name="p132506227165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row232797211165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1543498844165628"><a name="p1543498844165628"></a><a name="p1543498844165628"></a><a href="osal.md#gaf7b7a860f5cf11bda3008ce16a5d79d5">OsalAtomicRead</a> (const <a href="osalatomic.md">OsalAtomic</a> *v)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1418366636165628"><a name="p1418366636165628"></a><a name="p1418366636165628"></a>int32_t </p>
<p id="p1323455743165628"><a name="p1323455743165628"></a><a name="p1323455743165628"></a>Reads the counter of an atomic. </p>
</td>
</tr>
<tr id="row1620430794165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2091767801165628"><a name="p2091767801165628"></a><a name="p2091767801165628"></a><a href="osal.md#ga0b82ac10305c7ec5ae46707034b866c3">OsalAtomicSet</a> (<a href="osalatomic.md">OsalAtomic</a> *v, int32_t counter)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1626375415165628"><a name="p1626375415165628"></a><a name="p1626375415165628"></a>void </p>
<p id="p743035368165628"><a name="p743035368165628"></a><a name="p743035368165628"></a>Sets the counter for an atomic. </p>
</td>
</tr>
<tr id="row1780661273165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1899995602165628"><a name="p1899995602165628"></a><a name="p1899995602165628"></a><a href="osal.md#ga11214c11a9b875cb8ba0a67aeccc6ac9">OsalAtomicInc</a> (<a href="osalatomic.md">OsalAtomic</a> *v)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1016751568165628"><a name="p1016751568165628"></a><a name="p1016751568165628"></a>void </p>
<p id="p614034752165628"><a name="p614034752165628"></a><a name="p614034752165628"></a>Increments the counter of an atomic by 1. </p>
</td>
</tr>
<tr id="row2129966431165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p380462304165628"><a name="p380462304165628"></a><a name="p380462304165628"></a><a href="osal.md#gaa411f380e6b21c8467260030ceee38ff">OsalAtomicDec</a> (<a href="osalatomic.md">OsalAtomic</a> *v)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p432447863165628"><a name="p432447863165628"></a><a name="p432447863165628"></a>void </p>
<p id="p624862935165628"><a name="p624862935165628"></a><a name="p624862935165628"></a>Decrements the counter of an atomic by 1. </p>
</td>
</tr>
<tr id="row2105735976165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1850083180165628"><a name="p1850083180165628"></a><a name="p1850083180165628"></a><a href="osal.md#gaf02c15a3593cac4add3f661b63aebf81">OsalTestBit</a> (unsigned long nr, const volatile unsigned long *addr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1339801781165628"><a name="p1339801781165628"></a><a name="p1339801781165628"></a>int32_t </p>
<p id="p502848986165628"><a name="p502848986165628"></a><a name="p502848986165628"></a>Tests the value of a specified bit of a variable. </p>
</td>
</tr>
<tr id="row1849260098165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p120626478165628"><a name="p120626478165628"></a><a name="p120626478165628"></a><a href="osal.md#gac0ff99812a327a4a595802a23b41b46f">OsalTestSetBit</a> (unsigned long nr, volatile unsigned long *addr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p864473947165628"><a name="p864473947165628"></a><a name="p864473947165628"></a>int32_t </p>
<p id="p839972098165628"><a name="p839972098165628"></a><a name="p839972098165628"></a>Sets the value of a specified bit of the variable and returns the bit value before the setting. </p>
</td>
</tr>
<tr id="row1578276733165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p364739960165628"><a name="p364739960165628"></a><a name="p364739960165628"></a><a href="osal.md#ga8665e70c704921f443fd2db8193ff7cc">OsalTestClearBit</a> (unsigned long nr, volatile unsigned long *addr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1268335550165628"><a name="p1268335550165628"></a><a name="p1268335550165628"></a>int32_t </p>
<p id="p1102916874165628"><a name="p1102916874165628"></a><a name="p1102916874165628"></a>Clears the value of a specified bit of the variable and returns the bit value before clearing. </p>
</td>
</tr>
<tr id="row1798517081165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p394853263165628"><a name="p394853263165628"></a><a name="p394853263165628"></a><a href="osal.md#gae3e5b84f326aa1a2c4b8427509f80cd9">OsalClearBit</a> (unsigned long nr, volatile unsigned long *addr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1405474227165628"><a name="p1405474227165628"></a><a name="p1405474227165628"></a>void </p>
<p id="p1202022210165628"><a name="p1202022210165628"></a><a name="p1202022210165628"></a>Clears the value of a specified bit of the variable. </p>
</td>
</tr>
</tbody>
</table>

