# ifaddrs.h<a name="ZH-CN_TOPIC_0000001055189445"></a>

-   [Overview](#section1224699199165627)
-   [Summary](#section1160842586165627)
-   [Data Structures](#nested-classes)
-   [Functions](#func-members)

## **Overview**<a name="section1224699199165627"></a>

**Related Modules:**

[NET](NET.md)

**Description:**

Provides functions and data structures related to network operations. 

For example, you can use the functions to send and receive network data, manage network addresses, and convert bytes.

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1160842586165627"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table2020074866165627"></a>
<table><thead align="left"><tr id="row1944351849165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2089803429165627"><a name="p2089803429165627"></a><a name="p2089803429165627"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1021104638165627"><a name="p1021104638165627"></a><a name="p1021104638165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1442319618165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p328792912165627"><a name="p328792912165627"></a><a name="p328792912165627"></a><a href="ifaddrs.md">ifaddrs</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2130236461165627"><a name="p2130236461165627"></a><a name="p2130236461165627"></a>Defines the network interface information. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table1741062756165627"></a>
<table><thead align="left"><tr id="row950537030165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1349746996165627"><a name="p1349746996165627"></a><a name="p1349746996165627"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1180373493165627"><a name="p1180373493165627"></a><a name="p1180373493165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row609152019165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1511552167165627"><a name="p1511552167165627"></a><a name="p1511552167165627"></a><a href="NET.md#gabfdd6ca5469fe73ed88ba94bf8db57cc">freeifaddrs</a> (struct <a href="ifaddrs.md">ifaddrs</a> *ifp)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1248559790165627"><a name="p1248559790165627"></a><a name="p1248559790165627"></a>void </p>
<p id="p276431313165627"><a name="p276431313165627"></a><a name="p276431313165627"></a>Frees the network interface information obtained by <strong id="b960925843165627"><a name="b960925843165627"></a><a name="b960925843165627"></a>getifaddrs</strong>. </p>
</td>
</tr>
</tbody>
</table>

