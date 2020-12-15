# poll.h<a name="EN-US_TOPIC_0000001055387986"></a>

-   [Overview](#section491284639165628)
-   [Summary](#section924043502165628)
-   [Data Structures](#nested-classes)
-   [Macros](#define-members)
-   [Typedefs](#typedef-members)
-   [Functions](#func-members)

## **Overview**<a name="section491284639165628"></a>

**Related Modules:**

[IO](io.md)

**Description:**

Declares I/O multiplexing functions. 

You can use the functions provided in this file to perform I/O multiplexing.

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section924043502165628"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table703169282165628"></a>
<table><thead align="left"><tr id="row1754173531165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1058743985165628"><a name="p1058743985165628"></a><a name="p1058743985165628"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2133184989165628"><a name="p2133184989165628"></a><a name="p2133184989165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row121614324165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p623527271165628"><a name="p623527271165628"></a><a name="p623527271165628"></a><a href="pollfd.md">pollfd</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1206698829165628"><a name="p1206698829165628"></a><a name="p1206698829165628"></a>Defines I/O multiplexing. </p>
</td>
</tr>
</tbody>
</table>

## Macros<a name="define-members"></a>

<a name="table204666428165628"></a>
<table><thead align="left"><tr id="row1467821973165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p793300282165628"><a name="p793300282165628"></a><a name="p793300282165628"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p726756834165628"><a name="p726756834165628"></a><a name="p726756834165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row9127468165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p681672995165628"><a name="p681672995165628"></a><a name="p681672995165628"></a><a href="io.md#ga52ac479a805051f59643588b096024ff">POLLIN</a>   0x001</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p438329664165628"><a name="p438329664165628"></a><a name="p438329664165628"></a>POLLIN event. </p>
</td>
</tr>
<tr id="row334325161165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p931820439165628"><a name="p931820439165628"></a><a name="p931820439165628"></a><a href="io.md#gab6f53b89c7a4cc5e8349f7c778d85168">POLLPRI</a>   0x002</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1197750726165628"><a name="p1197750726165628"></a><a name="p1197750726165628"></a>POLLPRI event. </p>
</td>
</tr>
<tr id="row199636907165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1829391257165628"><a name="p1829391257165628"></a><a name="p1829391257165628"></a><a href="io.md#ga91b3c67129ac7675062f316b840a0d58">POLLOUT</a>   0x004</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2017885515165628"><a name="p2017885515165628"></a><a name="p2017885515165628"></a>POLLOUT event. </p>
</td>
</tr>
<tr id="row1555564752165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1459003025165628"><a name="p1459003025165628"></a><a name="p1459003025165628"></a><a href="io.md#gab1c532446408c98559d4aaaeeeb99820">POLLERR</a>   0x008</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1310018690165628"><a name="p1310018690165628"></a><a name="p1310018690165628"></a>POLLERR event. </p>
</td>
</tr>
<tr id="row1774410902165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1409639718165628"><a name="p1409639718165628"></a><a name="p1409639718165628"></a><a href="io.md#ga262754fe6bdf27c2cd3da43284ec8536">POLLHUP</a>   0x010</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1488363236165628"><a name="p1488363236165628"></a><a name="p1488363236165628"></a>POLLHUP event. </p>
</td>
</tr>
<tr id="row1099723858165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p700733389165628"><a name="p700733389165628"></a><a name="p700733389165628"></a><a href="io.md#gae8bffe35c61e12fb7b408b89721896df">POLLNVAL</a>   0x020</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p417713222165628"><a name="p417713222165628"></a><a name="p417713222165628"></a>POLLNVAL event. </p>
</td>
</tr>
</tbody>
</table>

## Typedefs<a name="typedef-members"></a>

<a name="table2031109892165628"></a>
<table><thead align="left"><tr id="row1816937203165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1883648786165628"><a name="p1883648786165628"></a><a name="p1883648786165628"></a>Typedef Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p762247693165628"><a name="p762247693165628"></a><a name="p762247693165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1312454647165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1952430895165628"><a name="p1952430895165628"></a><a name="p1952430895165628"></a><a href="io.md#ga0af7a8bdafcd5532e620a11f0d373d52">nfds_t</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1612423634165628"><a name="p1612423634165628"></a><a name="p1612423634165628"></a> typedef unsigned long </p>
<p id="p1067438352165628"><a name="p1067438352165628"></a><a name="p1067438352165628"></a>Number of poll types. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table1388755181165628"></a>
<table><thead align="left"><tr id="row203687318165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1508589012165628"><a name="p1508589012165628"></a><a name="p1508589012165628"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1238280548165628"><a name="p1238280548165628"></a><a name="p1238280548165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1088929531165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1816503821165628"><a name="p1816503821165628"></a><a name="p1816503821165628"></a><a href="io.md#gab7fc0f6be5f13c81de180c1288ba3b6f">poll</a> (struct <a href="pollfd.md">pollfd</a> fds[], <a href="io.md#ga0af7a8bdafcd5532e620a11f0d373d52">nfds_t</a> nfds, int timeout)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p830926262165628"><a name="p830926262165628"></a><a name="p830926262165628"></a>int </p>
<p id="p765194699165628"><a name="p765194699165628"></a><a name="p765194699165628"></a>Defines the I/O multiplexing system. </p>
</td>
</tr>
</tbody>
</table>

