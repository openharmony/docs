# select.h<a name="ZH-CN_TOPIC_0000001055069410"></a>

-   [Overview](#section1168340154165629)
-   [Summary](#section2031522111165629)
-   [Data Structures](#nested-classes)
-   [Macros](#define-members)
-   [Typedefs](#typedef-members)
-   [Functions](#func-members)

## **Overview**<a name="section1168340154165629"></a>

**Related Modules:**

[IO](IO.md)

**Description:**

Provides functions and structures related to I/O multiplexing. 

These functions can be used to implement I/O multiplexing.

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section2031522111165629"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table228278956165629"></a>
<table><thead align="left"><tr id="row1459866195165629"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p969709101165629"><a name="p969709101165629"></a><a name="p969709101165629"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1483597166165629"><a name="p1483597166165629"></a><a name="p1483597166165629"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row214457321165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1433912225165629"><a name="p1433912225165629"></a><a name="p1433912225165629"></a><a href="fd_set.md">fd_set</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1567800561165629"><a name="p1567800561165629"></a><a name="p1567800561165629"></a>Defines a file descriptor set. </p>
</td>
</tr>
</tbody>
</table>

## Macros<a name="define-members"></a>

<a name="table910098562165629"></a>
<table><thead align="left"><tr id="row344840143165629"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p53469393165629"><a name="p53469393165629"></a><a name="p53469393165629"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p185512209165629"><a name="p185512209165629"></a><a name="p185512209165629"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1093822336165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p389528327165629"><a name="p389528327165629"></a><a name="p389528327165629"></a><a href="IO.md#ga86c5dbf5a99358e288f573d6a1e0873f">FD_SETSIZE</a>   1024</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1126574927165629"><a name="p1126574927165629"></a><a name="p1126574927165629"></a>Defines the size of <strong id="b293056585165629"><a name="b293056585165629"></a><a name="b293056585165629"></a><a href="fd_set.md">fd_set</a></strong>, that is, the maximum number of monitored files. </p>
</td>
</tr>
<tr id="row1445290646165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1433811032165629"><a name="p1433811032165629"></a><a name="p1433811032165629"></a><a href="IO.md#ga92ab86a10f942411365b9078833559f0">FD_ZERO</a>(s)   do { int __i; unsigned long *__b=(s)-&gt;fds_bits; for(__i=sizeof (<a href="fd_set.md">fd_set</a>)/sizeof (long); __i; __i--) *__b++=0; } while(0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1557430530165629"><a name="p1557430530165629"></a><a name="p1557430530165629"></a>Clears all elements in the file descriptor set. </p>
</td>
</tr>
<tr id="row372038682165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1590576336165629"><a name="p1590576336165629"></a><a name="p1590576336165629"></a><a href="IO.md#gaa7701be461ce602ff7043cbd898a0c53">FD_SET</a>(d, s)   ((s)-&gt;fds_bits[(d)/(8*sizeof(long))] |= (1UL&lt;&lt;((d)%(8*sizeof(long)))))</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1196374856165629"><a name="p1196374856165629"></a><a name="p1196374856165629"></a>Adds a file descriptor to a set. </p>
</td>
</tr>
<tr id="row173495769165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1437305984165629"><a name="p1437305984165629"></a><a name="p1437305984165629"></a><a href="IO.md#ga60efc4a969e971f91b7a73bcace62e58">FD_CLR</a>(d, s)   ((s)-&gt;fds_bits[(d)/(8*sizeof(long))] &amp;= ~(1UL&lt;&lt;((d)%(8*sizeof(long)))))</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p543965595165629"><a name="p543965595165629"></a><a name="p543965595165629"></a>Removes a file descriptor from a set. </p>
</td>
</tr>
<tr id="row56460858165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1350270784165629"><a name="p1350270784165629"></a><a name="p1350270784165629"></a><a href="IO.md#ga99a3a0e4d7d1d3eb7be68f37554c0a30">FD_ISSET</a>(d, s)   !!((s)-&gt;fds_bits[(d)/(8*sizeof(long))] &amp; (1UL&lt;&lt;((d)%(8*sizeof(long)))))</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p299994608165629"><a name="p299994608165629"></a><a name="p299994608165629"></a>Checks whether a file descriptor is in a set. </p>
</td>
</tr>
</tbody>
</table>

## Typedefs<a name="typedef-members"></a>

<a name="table1346687191165629"></a>
<table><thead align="left"><tr id="row1754366573165629"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1460546940165629"><a name="p1460546940165629"></a><a name="p1460546940165629"></a>Typedef Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1970684091165629"><a name="p1970684091165629"></a><a name="p1970684091165629"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row77825668165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1063990067165629"><a name="p1063990067165629"></a><a name="p1063990067165629"></a><a href="IO.md#gaf78c256e09db7de8ea18def79fc5e6b2">fd_mask</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1137087195165629"><a name="p1137087195165629"></a><a name="p1137087195165629"></a> typedef unsigned long </p>
<p id="p577025005165629"><a name="p577025005165629"></a><a name="p577025005165629"></a>Defines <strong id="b1725764961165629"><a name="b1725764961165629"></a><a name="b1725764961165629"></a><a href="fd_set.md">fd_set</a></strong> as the alias of the element type. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table1254070856165629"></a>
<table><thead align="left"><tr id="row358553598165629"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p390712409165629"><a name="p390712409165629"></a><a name="p390712409165629"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p776245884165629"><a name="p776245884165629"></a><a name="p776245884165629"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1914494833165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p989002301165629"><a name="p989002301165629"></a><a name="p989002301165629"></a><a href="IO.md#gaf916439863bed6ba92594e390c227c7e">select</a> (int nfds, <a href="fd_set.md">fd_set</a> *__restrict readfds, <a href="fd_set.md">fd_set</a> *__restrict writefds, <a href="fd_set.md">fd_set</a> *__restrict exceptfds, struct <a href="timeval.md">timeval</a> *__restrict timeout)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p743201396165629"><a name="p743201396165629"></a><a name="p743201396165629"></a>int </p>
<p id="p507845870165629"><a name="p507845870165629"></a><a name="p507845870165629"></a>Monitors the I/O events of multiple file descriptors. </p>
</td>
</tr>
</tbody>
</table>

