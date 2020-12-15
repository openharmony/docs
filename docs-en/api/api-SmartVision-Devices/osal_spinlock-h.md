# osal\_spinlock.h<a name="EN-US_TOPIC_0000001054879508"></a>

-   [Overview](#section835764281165628)
-   [Summary](#section641614913165628)
-   [Data Structures](#nested-classes)
-   [Macros](#define-members)
-   [Functions](#func-members)

## **Overview**<a name="section835764281165628"></a>

**Related Modules:**

[OSAL](osal.md)

**Description:**

Declares spinlock types and interfaces. 

This file provides the interfaces for initializing, destroying, obtaining, and releasing a spinlock, the interfaces for obtaining a spinlock and disabling the interrupt request \(IRQ\), releasing a spinlock and enabling the IRQ, obtaining a spinlock, disabling the IRQ, and saving its status, and releasing a spinlock, enabling the IRQ, and restoring the saved IRQ status. The spinlock needs to be destroyed when it is no longer used.

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section641614913165628"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table281767139165628"></a>
<table><thead align="left"><tr id="row1621766097165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1826705641165628"><a name="p1826705641165628"></a><a name="p1826705641165628"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1238029823165628"><a name="p1238029823165628"></a><a name="p1238029823165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row891199077165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1346704501165628"><a name="p1346704501165628"></a><a name="p1346704501165628"></a><a href="osalspinlock.md">OsalSpinlock</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1185180481165628"><a name="p1185180481165628"></a><a name="p1185180481165628"></a>Describes a spinlock. </p>
</td>
</tr>
</tbody>
</table>

## Macros<a name="define-members"></a>

<a name="table1484619299165628"></a>
<table><thead align="left"><tr id="row419129824165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2082550780165628"><a name="p2082550780165628"></a><a name="p2082550780165628"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2069273501165628"><a name="p2069273501165628"></a><a name="p2069273501165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1938050965165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1567868274165628"><a name="p1567868274165628"></a><a name="p1567868274165628"></a><a href="osal.md#gad624af1547135d60073f38b7f31ad826">OSAL_DECLARE_SPINLOCK</a>(spinlock)   <a href="osalspinlock.md">OsalSpinlock</a> spinlock</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1112794201165628"><a name="p1112794201165628"></a><a name="p1112794201165628"></a>Defines a spinlock. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table1532378473165628"></a>
<table><thead align="left"><tr id="row516720234165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1548489285165628"><a name="p1548489285165628"></a><a name="p1548489285165628"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p460583261165628"><a name="p460583261165628"></a><a name="p460583261165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1952705272165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1595068169165628"><a name="p1595068169165628"></a><a name="p1595068169165628"></a><a href="osal.md#gae36a2d6e4e0191273c9f86a918befb5c">OsalSpinInit</a> (<a href="osalspinlock.md">OsalSpinlock</a> *spinlock)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1906539093165628"><a name="p1906539093165628"></a><a name="p1906539093165628"></a>int32_t </p>
<p id="p684678485165628"><a name="p684678485165628"></a><a name="p684678485165628"></a>Initializes a spinlock. </p>
</td>
</tr>
<tr id="row1784406108165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1861499502165628"><a name="p1861499502165628"></a><a name="p1861499502165628"></a><a href="osal.md#gacd3824f292ddef395bd1a4a7b5546470">OsalSpinDestroy</a> (<a href="osalspinlock.md">OsalSpinlock</a> *spinlock)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1846286462165628"><a name="p1846286462165628"></a><a name="p1846286462165628"></a>int32_t </p>
<p id="p2017935940165628"><a name="p2017935940165628"></a><a name="p2017935940165628"></a>Destroys a spinlock. </p>
</td>
</tr>
<tr id="row54311918165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p442357527165628"><a name="p442357527165628"></a><a name="p442357527165628"></a><a href="osal.md#gae1c4b9ac8ea2a4820d73c20ae017dbd7">OsalSpinLock</a> (<a href="osalspinlock.md">OsalSpinlock</a> *spinlock)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1375683196165628"><a name="p1375683196165628"></a><a name="p1375683196165628"></a>int32_t </p>
<p id="p1332424968165628"><a name="p1332424968165628"></a><a name="p1332424968165628"></a>Obtains a spinlock. </p>
</td>
</tr>
<tr id="row1554548189165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1158892717165628"><a name="p1158892717165628"></a><a name="p1158892717165628"></a><a href="osal.md#gada1f1826b19dc900af370a2bcd9681b9">OsalSpinUnlock</a> (<a href="osalspinlock.md">OsalSpinlock</a> *spinlock)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p338823225165628"><a name="p338823225165628"></a><a name="p338823225165628"></a>int32_t </p>
<p id="p701728301165628"><a name="p701728301165628"></a><a name="p701728301165628"></a>Releases a spinlock. </p>
</td>
</tr>
<tr id="row2090372179165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1041387969165628"><a name="p1041387969165628"></a><a name="p1041387969165628"></a><a href="osal.md#ga7d409ec573a06078112a8ffae14afce5">OsalSpinLockIrq</a> (<a href="osalspinlock.md">OsalSpinlock</a> *spinlock)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p255628736165628"><a name="p255628736165628"></a><a name="p255628736165628"></a>int32_t </p>
<p id="p590443602165628"><a name="p590443602165628"></a><a name="p590443602165628"></a>Obtains a spinlock and disables the IRQ. </p>
</td>
</tr>
<tr id="row1107622242165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1314952154165628"><a name="p1314952154165628"></a><a name="p1314952154165628"></a><a href="osal.md#ga7d7848d572fbda413b3b5770e95a234e">OsalSpinUnlockIrq</a> (<a href="osalspinlock.md">OsalSpinlock</a> *spinlock)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1174127500165628"><a name="p1174127500165628"></a><a name="p1174127500165628"></a>int32_t </p>
<p id="p1652128036165628"><a name="p1652128036165628"></a><a name="p1652128036165628"></a>Releases a spinlock and enables the IRQ. </p>
</td>
</tr>
<tr id="row1158341083165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p300161311165628"><a name="p300161311165628"></a><a name="p300161311165628"></a><a href="osal.md#gab711d8d56055e78dd85f84bc530a4d3f">OsalSpinLockIrqSave</a> (<a href="osalspinlock.md">OsalSpinlock</a> *spinlock, uint32_t *flags)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1923094343165628"><a name="p1923094343165628"></a><a name="p1923094343165628"></a>int32_t </p>
<p id="p1599979281165628"><a name="p1599979281165628"></a><a name="p1599979281165628"></a>Obtains a spinlock, disables the IRQ, and saves its status. </p>
</td>
</tr>
<tr id="row474118604165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1629533597165628"><a name="p1629533597165628"></a><a name="p1629533597165628"></a><a href="osal.md#ga3be4dbde6c9ae740b012e49ab90e7a8a">OsalSpinUnlockIrqRestore</a> (<a href="osalspinlock.md">OsalSpinlock</a> *spinlock, uint32_t *flags)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1845132604165628"><a name="p1845132604165628"></a><a name="p1845132604165628"></a>int32_t </p>
<p id="p1106089909165628"><a name="p1106089909165628"></a><a name="p1106089909165628"></a>Releases a spinlock, enables the IRQ, and restores the saved IRQ status. </p>
</td>
</tr>
</tbody>
</table>

