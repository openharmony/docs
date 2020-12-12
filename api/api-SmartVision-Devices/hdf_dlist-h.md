# hdf\_dlist.h<a name="ZH-CN_TOPIC_0000001054598129"></a>

-   [Overview](#section736120864165627)
-   [Summary](#section700537946165627)
-   [Data Structures](#nested-classes)
-   [Macros](#define-members)
-   [Functions](#func-members)

## **Overview**<a name="section736120864165627"></a>

**Related Modules:**

[DriverUtils](DriverUtils.md)

**Description:**

Declares doubly linked list structures and interfaces. 

This file provides interfaces such as inserting a node from the head or tail of a doubly linked list, checking whether a doubly linked list is empty, traversing a doubly linked list, and merging doubly linked lists.

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section700537946165627"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table1841395502165627"></a>
<table><thead align="left"><tr id="row1133649226165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p556586659165627"><a name="p556586659165627"></a><a name="p556586659165627"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1043591379165627"><a name="p1043591379165627"></a><a name="p1043591379165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1941443457165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1180062720165627"><a name="p1180062720165627"></a><a name="p1180062720165627"></a><a href="DListHead.md">DListHead</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1231334759165627"><a name="p1231334759165627"></a><a name="p1231334759165627"></a>Describes a doubly linked list. </p>
</td>
</tr>
</tbody>
</table>

## Macros<a name="define-members"></a>

<a name="table1493436664165627"></a>
<table><thead align="left"><tr id="row1963225656165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p498333243165627"><a name="p498333243165627"></a><a name="p498333243165627"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p289972871165627"><a name="p289972871165627"></a><a name="p289972871165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1554451755165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1599420504165627"><a name="p1599420504165627"></a><a name="p1599420504165627"></a><a href="DriverUtils.md#ga818b9cca761fe7bc18e4e417da772976">CONTAINER_OF</a>(ptr, type, member)   (type *)((char *)(ptr) - (char *)&amp;((type *)0)-&gt;member)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1063984414165627"><a name="p1063984414165627"></a><a name="p1063984414165627"></a>Obtains the address of a structure variable from its member address. </p>
</td>
</tr>
<tr id="row2028371877165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p552908058165627"><a name="p552908058165627"></a><a name="p552908058165627"></a><a href="DriverUtils.md#ga203de9c01fefc8bbbae746685794cfcc">DLIST_FIRST_ENTRY</a>(ptr, type, member)   <a href="DriverUtils.md#ga818b9cca761fe7bc18e4e417da772976">CONTAINER_OF</a>((ptr)-&gt;next, type, member)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p311029301165627"><a name="p311029301165627"></a><a name="p311029301165627"></a>Obtains the first node of a doubly linked list. </p>
</td>
</tr>
<tr id="row662313354165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p783840849165627"><a name="p783840849165627"></a><a name="p783840849165627"></a><a href="DriverUtils.md#ga25ac08cc864bd59050f7e2ca77df1f23">DLIST_LAST_ENTRY</a>(ptr, type, member)   <a href="DriverUtils.md#ga818b9cca761fe7bc18e4e417da772976">CONTAINER_OF</a>((ptr)-&gt;prev, type, member)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1660835897165627"><a name="p1660835897165627"></a><a name="p1660835897165627"></a>Obtains the last node of a doubly linked list. </p>
</td>
</tr>
<tr id="row39684662165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p875887414165627"><a name="p875887414165627"></a><a name="p875887414165627"></a><a href="DriverUtils.md#ga2b53b2bcf35b8cfb32e429cacbcc0a8d">DLIST_FOR_EACH_ENTRY</a>(pos, head, type, member)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1401517525165627"><a name="p1401517525165627"></a><a name="p1401517525165627"></a>Traverses all nodes in a doubly linked list. </p>
</td>
</tr>
<tr id="row7587792165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2038089420165627"><a name="p2038089420165627"></a><a name="p2038089420165627"></a><a href="DriverUtils.md#ga8e6f49c1fed85c031f29e8acce377ea0">DLIST_FOR_EACH_ENTRY_SAFE</a>(pos, tmp, head, type, member)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p455010189165627"><a name="p455010189165627"></a><a name="p455010189165627"></a>Traverses all nodes in a doubly linked list. This function is used to delete the nodes pointed to by <strong id="b123119334165627"><a name="b123119334165627"></a><a name="b123119334165627"></a>pos</strong> during traversal. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table1838318761165627"></a>
<table><thead align="left"><tr id="row1131798703165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p372096971165627"><a name="p372096971165627"></a><a name="p372096971165627"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1512667745165627"><a name="p1512667745165627"></a><a name="p1512667745165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row719192897165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p280470882165627"><a name="p280470882165627"></a><a name="p280470882165627"></a><a href="DriverUtils.md#ga0a86a18ad591f485663834799dd38dea">DListHeadInit</a> (struct <a href="DListHead.md">DListHead</a> *head)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p164666892165627"><a name="p164666892165627"></a><a name="p164666892165627"></a>static void </p>
<p id="p416751403165627"><a name="p416751403165627"></a><a name="p416751403165627"></a>Initializes a doubly linked list. </p>
</td>
</tr>
<tr id="row372064275165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1490275977165627"><a name="p1490275977165627"></a><a name="p1490275977165627"></a><a href="DriverUtils.md#ga9b4053294ad63f0bdacb4841a14ba208">DListIsEmpty</a> (const struct <a href="DListHead.md">DListHead</a> *head)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1423769086165627"><a name="p1423769086165627"></a><a name="p1423769086165627"></a>static bool </p>
<p id="p772596634165627"><a name="p772596634165627"></a><a name="p772596634165627"></a>Checks whether a doubly linked list is empty. </p>
</td>
</tr>
<tr id="row1115559084165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1960849135165627"><a name="p1960849135165627"></a><a name="p1960849135165627"></a><a href="DriverUtils.md#ga42d23fa1f55097bae91664c5e4a78e1e">DListRemove</a> (struct <a href="DListHead.md">DListHead</a> *<a href="entry.md">entry</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1121209127165627"><a name="p1121209127165627"></a><a name="p1121209127165627"></a>static void </p>
<p id="p140450068165627"><a name="p140450068165627"></a><a name="p140450068165627"></a>Removes a node from a doubly linked list. </p>
</td>
</tr>
<tr id="row352826413165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p466473573165627"><a name="p466473573165627"></a><a name="p466473573165627"></a><a href="DriverUtils.md#ga60e796c868630dd403ef4fdcc60c12e8">DListInsertHead</a> (struct <a href="DListHead.md">DListHead</a> *<a href="entry.md">entry</a>, struct <a href="DListHead.md">DListHead</a> *head)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1976619480165627"><a name="p1976619480165627"></a><a name="p1976619480165627"></a>static void </p>
<p id="p1269977845165627"><a name="p1269977845165627"></a><a name="p1269977845165627"></a>Inserts a node from the head of a doubly linked list. </p>
</td>
</tr>
<tr id="row1884798005165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2114951067165627"><a name="p2114951067165627"></a><a name="p2114951067165627"></a><a href="DriverUtils.md#gaa1d386162f8f6401fe8ac6d70d237517">DListInsertTail</a> (struct <a href="DListHead.md">DListHead</a> *<a href="entry.md">entry</a>, struct <a href="DListHead.md">DListHead</a> *head)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1245173653165627"><a name="p1245173653165627"></a><a name="p1245173653165627"></a>static void </p>
<p id="p557148196165627"><a name="p557148196165627"></a><a name="p557148196165627"></a>Inserts a node from the tail of a doubly linked list. </p>
</td>
</tr>
<tr id="row228721574165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p406625092165627"><a name="p406625092165627"></a><a name="p406625092165627"></a><a href="DriverUtils.md#gac4acad10a7c49cc4b2d773aedbfa1e11">DListMerge</a> (struct <a href="DListHead.md">DListHead</a> *list, struct <a href="DListHead.md">DListHead</a> *head)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p807404672165627"><a name="p807404672165627"></a><a name="p807404672165627"></a>static void </p>
<p id="p544063750165627"><a name="p544063750165627"></a><a name="p544063750165627"></a>Merges two linked lists by adding the list specified by <strong id="b774776004165627"><a name="b774776004165627"></a><a name="b774776004165627"></a>list</strong> to the head of the list specified by <strong id="b100067757165627"><a name="b100067757165627"></a><a name="b100067757165627"></a>head</strong> and initializes the merged list. </p>
</td>
</tr>
</tbody>
</table>

