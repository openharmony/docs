# osal\_sem.h<a name="EN-US_TOPIC_0000001054479539"></a>

-   [Overview](#section458654899165628)
-   [Summary](#section1491335021165628)
-   [Data Structures](#nested-classes)
-   [Macros](#define-members)
-   [Functions](#func-members)

## **Overview**<a name="section458654899165628"></a>

**Related Modules:**

[OSAL](osal.md)

**Description:**

Declares semaphore structures and interfaces. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1491335021165628"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table381632040165628"></a>
<table><thead align="left"><tr id="row191032633165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2033435477165628"><a name="p2033435477165628"></a><a name="p2033435477165628"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p529141244165628"><a name="p529141244165628"></a><a name="p529141244165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1564362947165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1223375040165628"><a name="p1223375040165628"></a><a name="p1223375040165628"></a><a href="osalsem.md">OsalSem</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1108884631165628"><a name="p1108884631165628"></a><a name="p1108884631165628"></a>Describes a semaphore. </p>
</td>
</tr>
</tbody>
</table>

## Macros<a name="define-members"></a>

<a name="table532163514165628"></a>
<table><thead align="left"><tr id="row1134249231165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1774146609165628"><a name="p1774146609165628"></a><a name="p1774146609165628"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p568732124165628"><a name="p568732124165628"></a><a name="p568732124165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2138848524165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p45763204165628"><a name="p45763204165628"></a><a name="p45763204165628"></a><a href="osal.md#ga5e37d1f50835b70611517ad96146fc93">OSAL_DECLARE_SEMAPHORE</a>(sem)   struct <a href="osalsem.md">OsalSem</a> sem</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1802900064165628"><a name="p1802900064165628"></a><a name="p1802900064165628"></a>Defines a semaphore. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table938189813165628"></a>
<table><thead align="left"><tr id="row1932835887165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1357305394165628"><a name="p1357305394165628"></a><a name="p1357305394165628"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2043500708165628"><a name="p2043500708165628"></a><a name="p2043500708165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1362912717165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1058099861165628"><a name="p1058099861165628"></a><a name="p1058099861165628"></a><a href="osal.md#ga7e4325c951479e93abe072290162da0b">OsalSemInit</a> (struct <a href="osalsem.md">OsalSem</a> *sem, uint32_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p399164274165628"><a name="p399164274165628"></a><a name="p399164274165628"></a>int32_t </p>
<p id="p164428118165628"><a name="p164428118165628"></a><a name="p164428118165628"></a>Initializes a semaphore. </p>
</td>
</tr>
<tr id="row1826298042165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p394265467165628"><a name="p394265467165628"></a><a name="p394265467165628"></a><a href="osal.md#ga0000b9ee1421950d5b3a04cbc839c6af">OsalSemWait</a> (struct <a href="osalsem.md">OsalSem</a> *sem, uint32_t ms)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1763975817165628"><a name="p1763975817165628"></a><a name="p1763975817165628"></a>int32_t </p>
<p id="p1445361044165628"><a name="p1445361044165628"></a><a name="p1445361044165628"></a>Waits for a semaphore. </p>
</td>
</tr>
<tr id="row1258080163165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1285754804165628"><a name="p1285754804165628"></a><a name="p1285754804165628"></a><a href="osal.md#gadc3205b416d3fc8e1fa9c332b82e634a">OsalSemPost</a> (struct <a href="osalsem.md">OsalSem</a> *sem)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p438248227165628"><a name="p438248227165628"></a><a name="p438248227165628"></a>int32_t </p>
<p id="p1917762706165628"><a name="p1917762706165628"></a><a name="p1917762706165628"></a>Releases a semaphore. </p>
</td>
</tr>
<tr id="row1458541297165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1223564249165628"><a name="p1223564249165628"></a><a name="p1223564249165628"></a><a href="osal.md#ga0b6642005b8a128ac01f69385bd6969f">OsalSemDestroy</a> (struct <a href="osalsem.md">OsalSem</a> *sem)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p801832442165628"><a name="p801832442165628"></a><a name="p801832442165628"></a>int32_t </p>
<p id="p797300296165628"><a name="p797300296165628"></a><a name="p797300296165628"></a>Destroys a semaphore. </p>
</td>
</tr>
</tbody>
</table>

