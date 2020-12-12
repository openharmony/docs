# NetBuf<a name="ZH-CN_TOPIC_0000001054718135"></a>

-   [Overview](#section1797512922165632)
-   [Summary](#section1216851582165632)
-   [Data Fields](#pub-attribs)

## **Overview**<a name="section1797512922165632"></a>

**Related Modules:**

[WLAN](WLAN.md)

**Description:**

Records and saves a network data buffer. 

This structure is used to transmit network data between the protocol stack and network driver.

**Since:**

1.0

## **Summary**<a name="section1216851582165632"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1582189319165632"></a>
<table><thead align="left"><tr id="row1700017515165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p963220196165632"><a name="p963220196165632"></a><a name="p963220196165632"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1504527074165632"><a name="p1504527074165632"></a><a name="p1504527074165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row878220951165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p457670618165632"><a name="p457670618165632"></a><a name="p457670618165632"></a><a href="WLAN.md#ga6de94d9c8f9dd8d608a091673fa130c4">dlist</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2064435952165632"><a name="p2064435952165632"></a><a name="p2064435952165632"></a>struct <a href="DListHead.md">DListHead</a> </p>
</td>
</tr>
<tr id="row479757650165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p394866196165632"><a name="p394866196165632"></a><a name="p394866196165632"></a><a href="WLAN.md#ga49eacbbc8b4231a05464768103b8593f">bufs</a> [<a href="WLAN.md#ggafa231099d07583c3ed0981e0bb665f55aeef2a730ef9f722cfbac0b24998f8e19">MAX_BUF_NUM</a>]</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p62029289165632"><a name="p62029289165632"></a><a name="p62029289165632"></a>struct BufField </p>
</td>
</tr>
<tr id="row1020309146165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1775419622165632"><a name="p1775419622165632"></a><a name="p1775419622165632"></a><a href="WLAN.md#gad94b7aff082f5d891a3250dfc6307ce0">mem</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p109566830165632"><a name="p109566830165632"></a><a name="p109566830165632"></a>uint8_t * </p>
</td>
</tr>
<tr id="row1373514903165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2131453888165632"><a name="p2131453888165632"></a><a name="p2131453888165632"></a><a href="WLAN.md#ga559e952054ce59e81d2ff9b38634b60c">len</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2117804666165632"><a name="p2117804666165632"></a><a name="p2117804666165632"></a>uint32_t </p>
</td>
</tr>
<tr id="row258055373165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p563186249165632"><a name="p563186249165632"></a><a name="p563186249165632"></a><a href="WLAN.md#gafb7e6f774a44888f5c44c3dffc6c5616">dataLen</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p847654304165632"><a name="p847654304165632"></a><a name="p847654304165632"></a>uint32_t </p>
</td>
</tr>
<tr id="row307488166165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1332978091165632"><a name="p1332978091165632"></a><a name="p1332978091165632"></a><a href="WLAN.md#gafa78f2abfa4f977cfb3bd52a6ae05d61">dev</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p464070963165632"><a name="p464070963165632"></a><a name="p464070963165632"></a>void * </p>
</td>
</tr>
<tr id="row197322321165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1034628022165632"><a name="p1034628022165632"></a><a name="p1034628022165632"></a><a href="WLAN.md#gaa56eababaaaeda2ec724f21889a20ccd">qmap</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1256282825165632"><a name="p1256282825165632"></a><a name="p1256282825165632"></a>uint32_t </p>
</td>
</tr>
<tr id="row840053715165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1160806442165632"><a name="p1160806442165632"></a><a name="p1160806442165632"></a><a href="WLAN.md#ga197b5045451ca25a03f478df0bd03514">rsv</a> [<a href="WLAN.md#ga794c035a19a38acc000146a8f9a4ec80">MAX_NETBUF_RESEVER_SIZE</a>]</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p343049365165632"><a name="p343049365165632"></a><a name="p343049365165632"></a>uint8_t </p>
</td>
</tr>
</tbody>
</table>

