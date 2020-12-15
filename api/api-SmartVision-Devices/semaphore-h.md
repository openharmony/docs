# semaphore.h<a name="ZH-CN_TOPIC_0000001054748011"></a>

-   [Overview](#section240345738165629)
-   [Summary](#section65980240165629)
-   [Data Structures](#nested-classes)
-   [Macros](#define-members)
-   [Functions](#func-members)

## **Overview**<a name="section240345738165629"></a>

**Related Modules:**

[IPC](IPC.md)

**Description:**

Provides functions and structures related to semaphore operations. 

For example, you can use the functions to create, open, close, and delete semaphores, and perform P and V operations on semaphores.

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section65980240165629"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table154407341165629"></a>
<table><thead align="left"><tr id="row1085227233165629"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1330189677165629"><a name="p1330189677165629"></a><a name="p1330189677165629"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1907393431165629"><a name="p1907393431165629"></a><a name="p1907393431165629"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1542796773165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1890772681165629"><a name="p1890772681165629"></a><a name="p1890772681165629"></a><a href="sem_t.md">sem_t</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1751123594165629"><a name="p1751123594165629"></a><a name="p1751123594165629"></a>Defines semaphores. </p>
</td>
</tr>
</tbody>
</table>

## Macros<a name="define-members"></a>

<a name="table1914520469165629"></a>
<table><thead align="left"><tr id="row624028882165629"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1099125961165629"><a name="p1099125961165629"></a><a name="p1099125961165629"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1118680746165629"><a name="p1118680746165629"></a><a name="p1118680746165629"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1526626035165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1889972388165629"><a name="p1889972388165629"></a><a name="p1889972388165629"></a><a href="IPC.md#ga2ef55dcb46a51cb0f879f4c1724bdded">SEM_FAILED</a>   ((<a href="sem_t.md">sem_t</a> *)0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1904886791165629"><a name="p1904886791165629"></a><a name="p1904886791165629"></a>Defines the semaphore failure flag. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table442627440165629"></a>
<table><thead align="left"><tr id="row1757094948165629"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p297886683165629"><a name="p297886683165629"></a><a name="p297886683165629"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1834298616165629"><a name="p1834298616165629"></a><a name="p1834298616165629"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row451318583165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p735852890165629"><a name="p735852890165629"></a><a name="p735852890165629"></a><a href="IPC.md#ga4e398fea1080fd7919e5c72ee94e2fc5">sem_close</a> (<a href="sem_t.md">sem_t</a> *sem)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1241336994165629"><a name="p1241336994165629"></a><a name="p1241336994165629"></a>int </p>
<p id="p1155406573165629"><a name="p1155406573165629"></a><a name="p1155406573165629"></a>Closes a specified semaphore. </p>
</td>
</tr>
<tr id="row2141705357165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1208449804165629"><a name="p1208449804165629"></a><a name="p1208449804165629"></a><a href="IPC.md#ga6bc9a7dd941a9b5e319715b767af5682">sem_destroy</a> (<a href="sem_t.md">sem_t</a> *sem)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p736330363165629"><a name="p736330363165629"></a><a name="p736330363165629"></a>int </p>
<p id="p1674409459165629"><a name="p1674409459165629"></a><a name="p1674409459165629"></a>Destroys a specified anonymous semaphore that is no longer used. </p>
</td>
</tr>
<tr id="row223302149165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1114935275165629"><a name="p1114935275165629"></a><a name="p1114935275165629"></a><a href="IPC.md#ga934bcc3cbc0c67a9e3a8e7a43c023460">sem_getvalue</a> (<a href="sem_t.md">sem_t</a> *__restrict sem, int *__restrict sval)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p774783707165629"><a name="p774783707165629"></a><a name="p774783707165629"></a>int </p>
<p id="p1160017535165629"><a name="p1160017535165629"></a><a name="p1160017535165629"></a>Obtains the count value of a specified semaphore. </p>
</td>
</tr>
<tr id="row1102550631165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p469202087165629"><a name="p469202087165629"></a><a name="p469202087165629"></a><a href="IPC.md#ga532509bd8a6499f8193253192fb83a3d">sem_init</a> (<a href="sem_t.md">sem_t</a> *sem, int pshared, unsigned int value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p206682474165629"><a name="p206682474165629"></a><a name="p206682474165629"></a>int </p>
<p id="p715863595165629"><a name="p715863595165629"></a><a name="p715863595165629"></a>Creates and initializes an anonymous semaphore. </p>
</td>
</tr>
<tr id="row1129060033165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p397032659165629"><a name="p397032659165629"></a><a name="p397032659165629"></a><a href="IPC.md#ga015dce85cab8477c679cc47968958247">sem_post</a> (<a href="sem_t.md">sem_t</a> *sem)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p146048664165629"><a name="p146048664165629"></a><a name="p146048664165629"></a>int </p>
<p id="p487040262165629"><a name="p487040262165629"></a><a name="p487040262165629"></a>Increments the semaphore count by 1. </p>
</td>
</tr>
<tr id="row521893967165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p246765020165629"><a name="p246765020165629"></a><a name="p246765020165629"></a><a href="IPC.md#ga9d832817226c594e7628e2cc7ed7d723">sem_timedwait</a> (<a href="sem_t.md">sem_t</a> *__restrict sem, const struct <a href="timespec.md">timespec</a> *__restrict timeout)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p741852354165629"><a name="p741852354165629"></a><a name="p741852354165629"></a>int </p>
<p id="p1408902139165629"><a name="p1408902139165629"></a><a name="p1408902139165629"></a>Obtains the semaphore, with a timeout period specified. </p>
</td>
</tr>
<tr id="row959489698165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p100441704165629"><a name="p100441704165629"></a><a name="p100441704165629"></a><a href="IPC.md#ga4de7a9a334b01b6373b017aaefa07cf0">sem_trywait</a> (<a href="sem_t.md">sem_t</a> *sem)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1436120981165629"><a name="p1436120981165629"></a><a name="p1436120981165629"></a>int </p>
<p id="p855198811165629"><a name="p855198811165629"></a><a name="p855198811165629"></a>Attempts to obtain the semaphore. </p>
</td>
</tr>
<tr id="row1516002372165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p924757785165629"><a name="p924757785165629"></a><a name="p924757785165629"></a><a href="IPC.md#ga776256d1a473906f8b7490689bfcb75c">sem_unlink</a> (const char *name)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2096955246165629"><a name="p2096955246165629"></a><a name="p2096955246165629"></a>int </p>
<p id="p1755764254165629"><a name="p1755764254165629"></a><a name="p1755764254165629"></a>Deletes a specified semaphore. </p>
</td>
</tr>
<tr id="row1628592465165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p518793873165629"><a name="p518793873165629"></a><a name="p518793873165629"></a><a href="IPC.md#gaad70020dca2241a2b78e272ca033271b">sem_wait</a> (<a href="sem_t.md">sem_t</a> *sem)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p304798656165629"><a name="p304798656165629"></a><a name="p304798656165629"></a>int </p>
<p id="p865220836165629"><a name="p865220836165629"></a><a name="p865220836165629"></a>Obtains the semaphore. </p>
</td>
</tr>
</tbody>
</table>

