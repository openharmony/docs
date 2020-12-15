# ipc.h<a name="EN-US_TOPIC_0000001055707978"></a>

-   [Overview](#section2013890637165627)
-   [Summary](#section283093336165627)
-   [Macros](#define-members)

## **Overview**<a name="section2013890637165627"></a>

**Related Modules:**

[IPC](ipc.md)

**Description:**

Defines IPC-related macros. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section283093336165627"></a>

## Macros<a name="define-members"></a>

<a name="table446591829165627"></a>
<table><thead align="left"><tr id="row2000392341165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p841076946165627"><a name="p841076946165627"></a><a name="p841076946165627"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1458860860165627"><a name="p1458860860165627"></a><a name="p1458860860165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1704759018165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p110029976165627"><a name="p110029976165627"></a><a name="p110029976165627"></a><a href="ipc.md#gace43f23fcb66ddaad964bb8ea8de6e9c">IPC_CREAT</a>   01000</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p994078868165627"><a name="p994078868165627"></a><a name="p994078868165627"></a>Defines the input parameter used to create an IPC object. </p>
</td>
</tr>
<tr id="row218287810165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1488113656165627"><a name="p1488113656165627"></a><a name="p1488113656165627"></a><a href="ipc.md#gacd312ab97691605718a3ee9a1c7c63e9">IPC_EXCL</a>   02000</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1092306333165627"><a name="p1092306333165627"></a><a name="p1092306333165627"></a>Defines the input parameter used together with <a href="ipc.md#gace43f23fcb66ddaad964bb8ea8de6e9c">IPC_CREAT</a> to prevent duplicate key values during IPC creation. </p>
</td>
</tr>
<tr id="row382539924165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2046887088165627"><a name="p2046887088165627"></a><a name="p2046887088165627"></a><a href="ipc.md#ga5afdf5fc48bb22fa27fbd85627b189b9">IPC_NOWAIT</a>   04000</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p842074536165627"><a name="p842074536165627"></a><a name="p842074536165627"></a>Defines the input parameter that specifies whether the communication is in non-blocking mode. </p>
</td>
</tr>
<tr id="row2115372964165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p378278914165627"><a name="p378278914165627"></a><a name="p378278914165627"></a><a href="ipc.md#ga752c83032a7bec60c904d97508ea4599">IPC_RMID</a>   0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1503828585165627"><a name="p1503828585165627"></a><a name="p1503828585165627"></a>Defines the input parameter used to delete an IPC object. </p>
</td>
</tr>
<tr id="row70516034165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p861785351165627"><a name="p861785351165627"></a><a name="p861785351165627"></a><a href="ipc.md#ga1f1cdce55426e50878b1c71a4fc67a41">IPC_SET</a>   1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1324796830165627"><a name="p1324796830165627"></a><a name="p1324796830165627"></a>Defines the input parameter used to set information to the kernel. </p>
</td>
</tr>
<tr id="row1130782890165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p535819359165627"><a name="p535819359165627"></a><a name="p535819359165627"></a><a href="ipc.md#ga17d3735e2d47ffa00a2cdf3a066f40d0">IPC_INFO</a>   3</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1658382104165627"><a name="p1658382104165627"></a><a name="p1658382104165627"></a>Defines the input parameter used to obtain the system-level restriction information of a specified communication type, for example, <a href="shminfo.md">shminfo</a>. </p>
</td>
</tr>
<tr id="row1829602422165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1049947519165627"><a name="p1049947519165627"></a><a name="p1049947519165627"></a><a href="ipc.md#gae2b9b856a4a657c250b0b2e1cc0835d9">IPC_PRIVATE</a>   ((<a href="utils.md#ga4f8c894a6c2b415e55f3f858afd9e7f5">key_t</a>) 0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p858027798165627"><a name="p858027798165627"></a><a name="p858027798165627"></a>Defines the IPC object as a private object. </p>
</td>
</tr>
</tbody>
</table>

