# AudioAdapterDescriptor<a name="EN-US_TOPIC_0000001055518080"></a>

-   [Overview](#section893230250165630)
-   [Summary](#section1226914997165630)
-   [Data Fields](#pub-attribs)

## **Overview**<a name="section893230250165630"></a>

**Related Modules:**

[Audio](audio.md)

**Description:**

Defines the audio adapter descriptor. 

An audio adapter is a set of port drivers for a sound card, including the output and input ports. One port corresponds to multiple pins, and each pin belongs to a physical component \(such as a speaker or a wired headset\). 

## **Summary**<a name="section1226914997165630"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table440065913165630"></a>
<table><thead align="left"><tr id="row1175612797165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1043786435165630"><a name="p1043786435165630"></a><a name="p1043786435165630"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p685944180165630"><a name="p685944180165630"></a><a name="p685944180165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row331204580165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1445523328165630"><a name="p1445523328165630"></a><a name="p1445523328165630"></a><a href="audio.md#gadbe46bc7d9b4c20c409e30942ad794cf">adapterName</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1957971889165630"><a name="p1957971889165630"></a><a name="p1957971889165630"></a>const char * </p>
</td>
</tr>
<tr id="row1914271158165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1323215883165630"><a name="p1323215883165630"></a><a name="p1323215883165630"></a><a href="audio.md#ga2bef8f9b5ea3c1e30639fcb3ec8dd717">portNum</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2093788100165630"><a name="p2093788100165630"></a><a name="p2093788100165630"></a>uint32_t </p>
</td>
</tr>
<tr id="row779168859165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1064684078165630"><a name="p1064684078165630"></a><a name="p1064684078165630"></a><a href="audio.md#ga64d0c55b881fb0a3bc15b2fecea86f24">ports</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p696292495165630"><a name="p696292495165630"></a><a name="p696292495165630"></a>struct <a href="audioport.md">AudioPort</a> * </p>
</td>
</tr>
</tbody>
</table>

