# hdf\_netbuf.h<a name="EN-US_TOPIC_0000001054479533"></a>

-   [Overview](#section1810358550165627)
-   [Summary](#section1845288754165627)
-   [Data Structures](#nested-classes)
-   [Macros](#define-members)
-   [Enumerations](#enum-members)
-   [Functions](#func-members)

## **Overview**<a name="section1810358550165627"></a>

**Related Modules:**

[WLAN](wlan.md)

**Description:**

Declares network data buffers and provides APIs for operating buffer queues. 

This file describes the following network data operations for network device driver development: Applying for, releasing, and moving a network data buffer Initializing a network data buffer queue, placing a network data buffer to a queue, and removing a network data buffer from a queue

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1845288754165627"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table1877807953165627"></a>
<table><thead align="left"><tr id="row1096935840165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1616208837165627"><a name="p1616208837165627"></a><a name="p1616208837165627"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p253454590165627"><a name="p253454590165627"></a><a name="p253454590165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row475070986165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1469151903165627"><a name="p1469151903165627"></a><a name="p1469151903165627"></a><a href="netbuf.md">NetBuf</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1208544945165627"><a name="p1208544945165627"></a><a name="p1208544945165627"></a>Records and saves a network data buffer. </p>
</td>
</tr>
<tr id="row1954369719165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1725582255165627"><a name="p1725582255165627"></a><a name="p1725582255165627"></a><a href="netbufqueue.md">NetBufQueue</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p179541488165627"><a name="p179541488165627"></a><a name="p179541488165627"></a>Indicates the queues for storing network data. </p>
</td>
</tr>
</tbody>
</table>

## Macros<a name="define-members"></a>

<a name="table1095267660165627"></a>
<table><thead align="left"><tr id="row2055000489165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p788556395165627"><a name="p788556395165627"></a><a name="p788556395165627"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1880346130165627"><a name="p1880346130165627"></a><a name="p1880346130165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row735171754165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2089024407165627"><a name="p2089024407165627"></a><a name="p2089024407165627"></a><a href="wlan.md#ga794c035a19a38acc000146a8f9a4ec80">MAX_NETBUF_RESEVER_SIZE</a>   68</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1399849264165627"><a name="p1399849264165627"></a><a name="p1399849264165627"></a>Defines the reserved field of a network data buffer used to store private information. </p>
</td>
</tr>
</tbody>
</table>

## Enumerations<a name="enum-members"></a>

<a name="table1622565092165627"></a>
<table><thead align="left"><tr id="row299545165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1613380687165627"><a name="p1613380687165627"></a><a name="p1613380687165627"></a>Enumeration Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1058157877165627"><a name="p1058157877165627"></a><a name="p1058157877165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row753478345165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1370675745165627"><a name="p1370675745165627"></a><a name="p1370675745165627"></a>{ <a href="wlan.md#ggafa231099d07583c3ed0981e0bb665f55a0e4808dd476b314c0fdbf417307f8b92">E_HEAD_BUF</a>, <a href="wlan.md#ggafa231099d07583c3ed0981e0bb665f55a4b374b76d2b9bb60c31a1a540369b6d4">E_DATA_BUF</a>, <a href="wlan.md#ggafa231099d07583c3ed0981e0bb665f55a316baeacb77ecf28631a76f1dbea872d">E_TAIL_BUF</a>, <a href="wlan.md#ggafa231099d07583c3ed0981e0bb665f55aeef2a730ef9f722cfbac0b24998f8e19">MAX_BUF_NUM</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p247540994165627"><a name="p247540994165627"></a><a name="p247540994165627"></a>Enumerates the segments of a network data buffer. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table106349793165627"></a>
<table><thead align="left"><tr id="row1139636155165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1327621808165627"><a name="p1327621808165627"></a><a name="p1327621808165627"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1579146798165627"><a name="p1579146798165627"></a><a name="p1579146798165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1907694655165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p306890226165627"><a name="p306890226165627"></a><a name="p306890226165627"></a><a href="wlan.md#ga6e754d5529b23b413d1fe00102a95db9">NetBufQueueInit</a> (struct <a href="netbufqueue.md">NetBufQueue</a> *q)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1502415704165627"><a name="p1502415704165627"></a><a name="p1502415704165627"></a>static void </p>
<p id="p753759159165627"><a name="p753759159165627"></a><a name="p753759159165627"></a>Initializes a network data buffer queue. </p>
</td>
</tr>
<tr id="row734998414165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1087161967165627"><a name="p1087161967165627"></a><a name="p1087161967165627"></a><a href="wlan.md#gaaa5c00efd1dedecf846af4dd108b6701">NetBufQueueSize</a> (const struct <a href="netbufqueue.md">NetBufQueue</a> *q)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p179042867165627"><a name="p179042867165627"></a><a name="p179042867165627"></a>static uint32_t </p>
<p id="p1105392821165627"><a name="p1105392821165627"></a><a name="p1105392821165627"></a>Obtains the size of a network data buffer queue. </p>
</td>
</tr>
<tr id="row448938582165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p107513843165627"><a name="p107513843165627"></a><a name="p107513843165627"></a><a href="wlan.md#ga36297284c60746f2b6895d94ea5e2dc3">NetBufQueueIsEmpty</a> (const struct <a href="netbufqueue.md">NetBufQueue</a> *q)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1410160746165627"><a name="p1410160746165627"></a><a name="p1410160746165627"></a>static bool </p>
<p id="p1976330618165627"><a name="p1976330618165627"></a><a name="p1976330618165627"></a>Checks whether the network data buffer queue is empty. </p>
</td>
</tr>
<tr id="row1623713954165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2061903267165627"><a name="p2061903267165627"></a><a name="p2061903267165627"></a><a href="wlan.md#ga25bf5d56e8afec1bc80080b20c3b7daa">NetBufQueueEnqueue</a> (struct <a href="netbufqueue.md">NetBufQueue</a> *q, struct <a href="netbuf.md">NetBuf</a> *nb)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p782439186165627"><a name="p782439186165627"></a><a name="p782439186165627"></a>void </p>
<p id="p1182564354165627"><a name="p1182564354165627"></a><a name="p1182564354165627"></a>Adds a network data buffer to the tail of a queue. </p>
</td>
</tr>
<tr id="row2131418713165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p248732820165627"><a name="p248732820165627"></a><a name="p248732820165627"></a><a href="wlan.md#ga5ebe7aff6d5187645869f067b0a8f659">NetBufQueueEnqueueHead</a> (struct <a href="netbufqueue.md">NetBufQueue</a> *q, struct <a href="netbuf.md">NetBuf</a> *nb)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1401218628165627"><a name="p1401218628165627"></a><a name="p1401218628165627"></a>void </p>
<p id="p112174054165627"><a name="p112174054165627"></a><a name="p112174054165627"></a>Adds a network data buffer to the header of a queue. </p>
</td>
</tr>
<tr id="row1001265675165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p186940383165627"><a name="p186940383165627"></a><a name="p186940383165627"></a><a href="wlan.md#ga4ad66d7ca7aabda3aef08fa541dc9ee4">NetBufQueueDequeue</a> (struct <a href="netbufqueue.md">NetBufQueue</a> *q)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p396344569165627"><a name="p396344569165627"></a><a name="p396344569165627"></a>struct <a href="netbuf.md">NetBuf</a> * </p>
<p id="p1744227841165627"><a name="p1744227841165627"></a><a name="p1744227841165627"></a>Obtains a network data buffer from the header of a queue and deletes it from the queue. </p>
</td>
</tr>
<tr id="row1428085764165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p779817003165627"><a name="p779817003165627"></a><a name="p779817003165627"></a><a href="wlan.md#ga390319a0419c26c73552bcee6b8d5c32">NetBufQueueDequeueTail</a> (struct <a href="netbufqueue.md">NetBufQueue</a> *q)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1624187936165627"><a name="p1624187936165627"></a><a name="p1624187936165627"></a>struct <a href="netbuf.md">NetBuf</a> * </p>
<p id="p1525052610165627"><a name="p1525052610165627"></a><a name="p1525052610165627"></a>Obtains a network data buffer from the tail of a queue and deletes it from the queue. </p>
</td>
</tr>
<tr id="row1051318731165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p383312028165627"><a name="p383312028165627"></a><a name="p383312028165627"></a><a href="wlan.md#ga082b7a173ca09288c3b418ce4e4faa7d">NetBufQueueAtHead</a> (const struct <a href="netbufqueue.md">NetBufQueue</a> *q)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1268166882165627"><a name="p1268166882165627"></a><a name="p1268166882165627"></a>static struct <a href="netbuf.md">NetBuf</a> * </p>
<p id="p1016150399165627"><a name="p1016150399165627"></a><a name="p1016150399165627"></a>Obtains the network data buffer from the header of a queue, without deleting it from the queue. </p>
</td>
</tr>
<tr id="row317090129165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p598312601165627"><a name="p598312601165627"></a><a name="p598312601165627"></a><a href="wlan.md#ga9de36bf1db57bd4eb042e87cb63dae69">NetBufQueueAtTail</a> (const struct <a href="netbufqueue.md">NetBufQueue</a> *q)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1792942912165627"><a name="p1792942912165627"></a><a name="p1792942912165627"></a>static struct <a href="netbuf.md">NetBuf</a> * </p>
<p id="p94791812165627"><a name="p94791812165627"></a><a name="p94791812165627"></a>Obtains the network data buffer from the tail of a queue, without deleting it from the queue. </p>
</td>
</tr>
<tr id="row1400641164165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p440787822165627"><a name="p440787822165627"></a><a name="p440787822165627"></a><a href="wlan.md#ga79045ebd1636c27bee454e9541498f33">NetBufQueueClear</a> (struct <a href="netbufqueue.md">NetBufQueue</a> *q)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1260962430165627"><a name="p1260962430165627"></a><a name="p1260962430165627"></a>void </p>
<p id="p495667371165627"><a name="p495667371165627"></a><a name="p495667371165627"></a>Clears a network data buffer queue and releases the network data buffer in the queue. </p>
</td>
</tr>
<tr id="row1778528452165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p408048807165627"><a name="p408048807165627"></a><a name="p408048807165627"></a><a href="wlan.md#ga2331e6b8c8f1ac4f00f8a1206fb1a3d8">NetBufQueueConcat</a> (struct <a href="netbufqueue.md">NetBufQueue</a> *q, struct <a href="netbufqueue.md">NetBufQueue</a> *add)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p799852927165627"><a name="p799852927165627"></a><a name="p799852927165627"></a>void </p>
<p id="p1229055486165627"><a name="p1229055486165627"></a><a name="p1229055486165627"></a>Moves all network data buffers from one queue to another and clears the source queue. </p>
</td>
</tr>
<tr id="row572442412165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p296705039165627"><a name="p296705039165627"></a><a name="p296705039165627"></a><a href="wlan.md#ga5ced2af63a9064b0e33d0aa4e86b3fc1">NetBufAlloc</a> (uint32_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1948065377165627"><a name="p1948065377165627"></a><a name="p1948065377165627"></a>struct <a href="netbuf.md">NetBuf</a> * </p>
<p id="p1864218325165627"><a name="p1864218325165627"></a><a name="p1864218325165627"></a>Applies for a network data buffer. </p>
</td>
</tr>
<tr id="row1518243212165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1754017880165627"><a name="p1754017880165627"></a><a name="p1754017880165627"></a><a href="wlan.md#ga9320642699593dfecd79dc30132dd4eb">NetBufFree</a> (struct <a href="netbuf.md">NetBuf</a> *nb)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p910223158165627"><a name="p910223158165627"></a><a name="p910223158165627"></a>void </p>
<p id="p1994617638165627"><a name="p1994617638165627"></a><a name="p1994617638165627"></a>Releases a network data buffer. </p>
</td>
</tr>
<tr id="row1262412756165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2127153203165627"><a name="p2127153203165627"></a><a name="p2127153203165627"></a><a href="wlan.md#ga74198f03268aadc025f6b76056b09604">NetBufDevAlloc</a> (const struct <a href="netdevice.md">NetDevice</a> *dev, uint32_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1936281185165627"><a name="p1936281185165627"></a><a name="p1936281185165627"></a>struct <a href="netbuf.md">NetBuf</a> * </p>
<p id="p1844069709165627"><a name="p1844069709165627"></a><a name="p1844069709165627"></a>Applies for a network data buffer based on the reserved space and requested size set by a network device. </p>
</td>
</tr>
<tr id="row1789192035165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1387701289165627"><a name="p1387701289165627"></a><a name="p1387701289165627"></a><a href="wlan.md#gac4ec1cedef616e61038dcb6dbf67d204">NetBufPush</a> (struct <a href="netbuf.md">NetBuf</a> *nb, uint32_t id, uint32_t len)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p790868309165627"><a name="p790868309165627"></a><a name="p790868309165627"></a>void * </p>
<p id="p1535019405165627"><a name="p1535019405165627"></a><a name="p1535019405165627"></a>Performs operations based on the segment ID of a network data buffer. The function is opposite to that of <a href="wlan.md#ga81f298aebc5b7772f173e2f6fadc004f">NetBufPop</a>. </p>
</td>
</tr>
<tr id="row1732264952165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2136161815165627"><a name="p2136161815165627"></a><a name="p2136161815165627"></a><a href="wlan.md#ga81f298aebc5b7772f173e2f6fadc004f">NetBufPop</a> (struct <a href="netbuf.md">NetBuf</a> *nb, uint32_t id, uint32_t len)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p101741842165627"><a name="p101741842165627"></a><a name="p101741842165627"></a>void * </p>
<p id="p1591934222165627"><a name="p1591934222165627"></a><a name="p1591934222165627"></a>Performs operations based on the segment ID of a network data buffer. The function is opposite to that of <a href="wlan.md#gac4ec1cedef616e61038dcb6dbf67d204">NetBufPush</a>. </p>
</td>
</tr>
<tr id="row327769946165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p41417951165627"><a name="p41417951165627"></a><a name="p41417951165627"></a><a href="wlan.md#gacd40d5004291b4aaa5c27703d9379c9c">NetBufGetAddress</a> (const struct <a href="netbuf.md">NetBuf</a> *nb, uint32_t id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1451061928165627"><a name="p1451061928165627"></a><a name="p1451061928165627"></a>static uint8_t * </p>
<p id="p323921560165627"><a name="p323921560165627"></a><a name="p323921560165627"></a>Obtains the address of a specified buffer segment in a network data buffer. </p>
</td>
</tr>
<tr id="row2049648165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1068846054165627"><a name="p1068846054165627"></a><a name="p1068846054165627"></a><a href="wlan.md#ga09245834fe9f55fe475a0dc226a6a709">NetBufGetRoom</a> (const struct <a href="netbuf.md">NetBuf</a> *nb, uint32_t id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p243494852165627"><a name="p243494852165627"></a><a name="p243494852165627"></a>static uint32_t </p>
<p id="p646483024165627"><a name="p646483024165627"></a><a name="p646483024165627"></a>Obtains the size of a specified buffer segment space in a network data buffer. </p>
</td>
</tr>
<tr id="row2040919510165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1216951380165627"><a name="p1216951380165627"></a><a name="p1216951380165627"></a><a href="wlan.md#ga67eeb57ebe467b9caa4f31734955727b">NetBufGetDataLen</a> (const struct <a href="netbuf.md">NetBuf</a> *nb)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1427880102165627"><a name="p1427880102165627"></a><a name="p1427880102165627"></a>static uint32_t </p>
<p id="p665014927165627"><a name="p665014927165627"></a><a name="p665014927165627"></a>Obtains the actual data length of the data segment of a network data buffer. </p>
</td>
</tr>
<tr id="row1528508587165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1929652497165627"><a name="p1929652497165627"></a><a name="p1929652497165627"></a><a href="wlan.md#ga623e0b15e65f317f746b53b9a4530bdd">NetBufResizeRoom</a> (struct <a href="netbuf.md">NetBuf</a> *nb, uint32_t head, uint32_t tail)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1684686251165627"><a name="p1684686251165627"></a><a name="p1684686251165627"></a>int32_t </p>
<p id="p1928102848165627"><a name="p1928102848165627"></a><a name="p1928102848165627"></a>Adjusts the size of a network data buffer space. </p>
</td>
</tr>
<tr id="row1273664859165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1393906037165627"><a name="p1393906037165627"></a><a name="p1393906037165627"></a><a href="wlan.md#ga89ee14a3da1b7b83325045af9c488ef8">NetBufConcat</a> (struct <a href="netbuf.md">NetBuf</a> *nb, struct <a href="netbuf.md">NetBuf</a> *cnb)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1779081157165627"><a name="p1779081157165627"></a><a name="p1779081157165627"></a>uint32_t </p>
<p id="p34917234165627"><a name="p34917234165627"></a><a name="p34917234165627"></a>Copies data in a network data buffer to another network data buffer. </p>
</td>
</tr>
<tr id="row560022338165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1956482721165627"><a name="p1956482721165627"></a><a name="p1956482721165627"></a><a href="wlan.md#ga8d44f8dbfa75583d0056702b5a2d32a1">Pbuf2NetBuf</a> (const struct <a href="netdevice.md">NetDevice</a> *netdev, struct pbuf *lwipBuf)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1438056026165627"><a name="p1438056026165627"></a><a name="p1438056026165627"></a>struct <a href="netbuf.md">NetBuf</a> * </p>
<p id="p1878474260165627"><a name="p1878474260165627"></a><a name="p1878474260165627"></a>Converts the <strong id="b39803349165627"><a name="b39803349165627"></a><a name="b39803349165627"></a>pbuf</strong> structure of Lightweight TCP/IP Stack (lwIP) to a network data buffer. </p>
</td>
</tr>
<tr id="row463722284165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1383708704165627"><a name="p1383708704165627"></a><a name="p1383708704165627"></a><a href="wlan.md#ga88e4943fc1b1f4e31f388bf8eec57476">NetBuf2Pbuf</a> (const struct <a href="netbuf.md">NetBuf</a> *nb)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1257900276165627"><a name="p1257900276165627"></a><a name="p1257900276165627"></a>struct pbuf * </p>
<p id="p1617451124165627"><a name="p1617451124165627"></a><a name="p1617451124165627"></a>Converts a network data buffer to the <strong id="b2093504872165627"><a name="b2093504872165627"></a><a name="b2093504872165627"></a>pbuf</strong> structure of Lightweight TCP/IP Stack (lwIP). </p>
</td>
</tr>
</tbody>
</table>

