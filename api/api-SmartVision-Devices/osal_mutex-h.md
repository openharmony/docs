# osal\_mutex.h<a name="ZH-CN_TOPIC_0000001055039492"></a>

-   [Overview](#section247873507165628)
-   [Summary](#section287799635165628)
-   [Data Structures](#nested-classes)
-   [Macros](#define-members)
-   [Functions](#func-members)

## **Overview**<a name="section247873507165628"></a>

**Related Modules:**

[OSAL](OSAL.md)

**Description:**

Declares mutex types and interfaces. 

This file provides interfaces for initializing and destroying a mutex, locking a mutex, locking a mutex upon timeout, and unlocking a mutex. The mutex must be destroyed after being used.

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section287799635165628"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table2047770513165628"></a>
<table><thead align="left"><tr id="row185842918165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1173075938165628"><a name="p1173075938165628"></a><a name="p1173075938165628"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p870290886165628"><a name="p870290886165628"></a><a name="p870290886165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row774074353165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1362695741165628"><a name="p1362695741165628"></a><a name="p1362695741165628"></a><a href="OsalMutex.md">OsalMutex</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p348984783165628"><a name="p348984783165628"></a><a name="p348984783165628"></a>Describes a mutex. </p>
</td>
</tr>
</tbody>
</table>

## Macros<a name="define-members"></a>

<a name="table1551504458165628"></a>
<table><thead align="left"><tr id="row1628994327165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1674161130165628"><a name="p1674161130165628"></a><a name="p1674161130165628"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p867024876165628"><a name="p867024876165628"></a><a name="p867024876165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row803024621165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1121127683165628"><a name="p1121127683165628"></a><a name="p1121127683165628"></a><a href="OSAL.md#ga63b1e9f0b9eacddc211f9a481c2597b3">OSAL_DECLARE_MUTEX</a>(mutex)   struct <a href="OsalMutex.md">OsalMutex</a> mutex</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2110765814165628"><a name="p2110765814165628"></a><a name="p2110765814165628"></a>Defines a mutex. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table1773745591165628"></a>
<table><thead align="left"><tr id="row202692259165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1153128158165628"><a name="p1153128158165628"></a><a name="p1153128158165628"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1173255863165628"><a name="p1173255863165628"></a><a name="p1173255863165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row717817110165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p700941717165628"><a name="p700941717165628"></a><a name="p700941717165628"></a><a href="OSAL.md#ga9bbc55785f8a533b0b099956bcbe258e">OsalMutexInit</a> (struct <a href="OsalMutex.md">OsalMutex</a> *mutex)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1538947563165628"><a name="p1538947563165628"></a><a name="p1538947563165628"></a>int32_t </p>
<p id="p2114217260165628"><a name="p2114217260165628"></a><a name="p2114217260165628"></a>Initializes a mutex. </p>
</td>
</tr>
<tr id="row764695368165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1701519845165628"><a name="p1701519845165628"></a><a name="p1701519845165628"></a><a href="OSAL.md#gaa37328265ee97277516f6905f90a41b3">OsalMutexDestroy</a> (struct <a href="OsalMutex.md">OsalMutex</a> *mutex)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p602517345165628"><a name="p602517345165628"></a><a name="p602517345165628"></a>int32_t </p>
<p id="p1130955227165628"><a name="p1130955227165628"></a><a name="p1130955227165628"></a>Destroys a mutex. </p>
</td>
</tr>
<tr id="row1913185650165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2084828576165628"><a name="p2084828576165628"></a><a name="p2084828576165628"></a><a href="OSAL.md#ga45d893bf49a8fb8caf76fa5d31822e0e">OsalMutexLock</a> (struct <a href="OsalMutex.md">OsalMutex</a> *mutex)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p289548859165628"><a name="p289548859165628"></a><a name="p289548859165628"></a>int32_t </p>
<p id="p2100407817165628"><a name="p2100407817165628"></a><a name="p2100407817165628"></a>Locks a mutex. </p>
</td>
</tr>
<tr id="row1613085170165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p429698452165628"><a name="p429698452165628"></a><a name="p429698452165628"></a><a href="OSAL.md#ga57162c8f2e812ef3e5ace498bb85a3b6">OsalMutexTimedLock</a> (struct <a href="OsalMutex.md">OsalMutex</a> *mutex, uint32_t ms)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p320428275165628"><a name="p320428275165628"></a><a name="p320428275165628"></a>int32_t </p>
<p id="p1889509280165628"><a name="p1889509280165628"></a><a name="p1889509280165628"></a>Locks a mutex with a specified timeout duration. </p>
</td>
</tr>
<tr id="row1105095059165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1356200253165628"><a name="p1356200253165628"></a><a name="p1356200253165628"></a><a href="OSAL.md#gae76ffb4db66c988be5209e0dfdc7a35f">OsalMutexUnlock</a> (struct <a href="OsalMutex.md">OsalMutex</a> *mutex)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p480990989165628"><a name="p480990989165628"></a><a name="p480990989165628"></a>int32_t </p>
<p id="p940787684165628"><a name="p940787684165628"></a><a name="p940787684165628"></a>Unlocks a mutex. </p>
</td>
</tr>
</tbody>
</table>

