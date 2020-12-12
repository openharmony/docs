# NetBufQueue<a name="EN-US_TOPIC_0000001055678102"></a>

-   [Overview](#section834705767165632)
-   [Summary](#section1547105223165632)
-   [Data Fields](#pub-attribs)

## **Overview**<a name="section834705767165632"></a>

**Related Modules:**

[WLAN](wlan.md)

**Description:**

Indicates the queues for storing network data. 

Queues can be used to process multiple pieces of network data in a centralized manner, improving efficiency.

**Since:**

1.0

## **Summary**<a name="section1547105223165632"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table583821857165632"></a>
<table><thead align="left"><tr id="row193534090165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p506843694165632"><a name="p506843694165632"></a><a name="p506843694165632"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1044687201165632"><a name="p1044687201165632"></a><a name="p1044687201165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1035982233165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p758213022165632"><a name="p758213022165632"></a><a name="p758213022165632"></a><a href="wlan.md#ga473ab87a57006bb6ed69c5e5ea666f5c">dlist</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1187630885165632"><a name="p1187630885165632"></a><a name="p1187630885165632"></a>struct <a href="dlisthead.md">DListHead</a> </p>
</td>
</tr>
<tr id="row1320195716165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1806592447165632"><a name="p1806592447165632"></a><a name="p1806592447165632"></a><a href="wlan.md#gab8e922b274e1854731b5fd22d8dde62d">size</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p154065019165632"><a name="p154065019165632"></a><a name="p154065019165632"></a>uint32_t </p>
</td>
</tr>
<tr id="row919110129165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1970290096165632"><a name="p1970290096165632"></a><a name="p1970290096165632"></a><a href="wlan.md#gadd22ee64f7d9703d6c4cde54b512aaa0">lock</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p247766835165632"><a name="p247766835165632"></a><a name="p247766835165632"></a>struct Spinlock </p>
</td>
</tr>
</tbody>
</table>

