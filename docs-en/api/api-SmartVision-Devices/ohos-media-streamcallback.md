# OHOS::Media::StreamCallback<a name="EN-US_TOPIC_0000001054479577"></a>

-   [Overview](#section1708185826165633)
-   [Summary](#section1272339314165633)
-   [Public Types](#pub-types)
-   [Public Member Functions](#pub-methods)

## **Overview**<a name="section1708185826165633"></a>

**Related Modules:**

[MultiMedia\_MediaCommon](multimedia_mediacommon.md)

**Description:**

Provides functions to obtain the address of a buffer memory and write the filled buffers into the playback queue. You need to implement the  **[StreamCallback](ohos-media-streamcallback.md)**  functions in a player object. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1272339314165633"></a>

## Public Types<a name="pub-types"></a>

<a name="table63944028165633"></a>
<table><thead align="left"><tr id="row1693108027165633"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1904410185165633"><a name="p1904410185165633"></a><a name="p1904410185165633"></a>Public Type Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1043076011165633"><a name="p1043076011165633"></a><a name="p1043076011165633"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1679373134165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p878098104165633"><a name="p878098104165633"></a><a name="p878098104165633"></a><a href="multimedia_mediacommon.md#ga6f4847f443de5cdf3641386011335e21">BufferFlags</a> : uint32_t {   <a href="multimedia_mediacommon.md#gga6f4847f443de5cdf3641386011335e21ac1a3ce4ddd663c55f87a8275ccf285ad">STREAM_FLAG_SYNCFRAME</a> = 1, <a href="multimedia_mediacommon.md#gga6f4847f443de5cdf3641386011335e21afd0d977a6a5d48657d694c9acb8ac2b5">STREAM_FLAG_CODECCONFIG</a> = 2, <a href="multimedia_mediacommon.md#gga6f4847f443de5cdf3641386011335e21aa76ecb4ee6077a1ad3ceac569b875487">STREAM_FLAG_EOS</a> = 4, <a href="multimedia_mediacommon.md#gga6f4847f443de5cdf3641386011335e21a29e735a1e41790c24cc9ac9e7342dd2a">STREAM_FLAG_PARTIAL_FRAME</a> = 8,   <a href="multimedia_mediacommon.md#gga6f4847f443de5cdf3641386011335e21a8b2c1f065ce398ac48bac2b8e62e481b">STREAM_FLAG_ENDOFFRAME</a> = 16, <a href="multimedia_mediacommon.md#gga6f4847f443de5cdf3641386011335e21a9001c389dd39f08025e76ae2872fad02">STREAM_FLAG_MUXER_DATA</a> = 32 }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p527673305165633"><a name="p527673305165633"></a><a name="p527673305165633"></a>Enumerates buffer types of stream sources. </p>
</td>
</tr>
</tbody>
</table>

## Public Member Functions<a name="pub-methods"></a>

<a name="table992329928165633"></a>
<table><thead align="left"><tr id="row1741074408165633"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1836182528165633"><a name="p1836182528165633"></a><a name="p1836182528165633"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1744498000165633"><a name="p1744498000165633"></a><a name="p1744498000165633"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row222622359165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1883436777165633"><a name="p1883436777165633"></a><a name="p1883436777165633"></a><a href="multimedia_mediacommon.md#ga8f897b8b2d5baf06e15accfeb97892ae">GetBuffer</a> (size_t <a href="utils.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1904063913165633"><a name="p1904063913165633"></a><a name="p1904063913165633"></a>virtual uint8_t * </p>
<p id="p1319476207165633"><a name="p1319476207165633"></a><a name="p1319476207165633"></a>Obtains the virtual address of a buffer memory block based on its index. </p>
</td>
</tr>
<tr id="row286748938165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1124499029165633"><a name="p1124499029165633"></a><a name="p1124499029165633"></a><a href="multimedia_mediacommon.md#gaa62705632557f47f9fd9632157e53a21">QueueBuffer</a> (size_t <a href="utils.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>, size_t offset, size_t size, int64_t timestampUs, uint32_t flags)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1324943117165633"><a name="p1324943117165633"></a><a name="p1324943117165633"></a>virtual void </p>
<p id="p1157408232165633"><a name="p1157408232165633"></a><a name="p1157408232165633"></a>Writes the filled buffer memory block into the player memory. </p>
</td>
</tr>
<tr id="row489701419165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1245102763165633"><a name="p1245102763165633"></a><a name="p1245102763165633"></a><a href="multimedia_mediacommon.md#ga29f8c86744bda61f84920654c5f40df0">SetParameters</a> (const <a href="ohos-media-format.md">Format</a> &amp;params)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1618735730165633"><a name="p1618735730165633"></a><a name="p1618735730165633"></a>virtual void </p>
<p id="p763045689165633"><a name="p763045689165633"></a><a name="p763045689165633"></a>Sets additional information about a stream. </p>
</td>
</tr>
</tbody>
</table>

