# OHOS::Media::StreamSource<a name="EN-US_TOPIC_0000001054879546"></a>

-   [Overview](#section694824669165633)
-   [Summary](#section1887496875165633)
-   [Public Member Functions](#pub-methods)

## **Overview**<a name="section694824669165633"></a>

**Related Modules:**

[MultiMedia\_MediaCommon](multimedia_mediacommon.md)

**Description:**

Provides functions related to the stream source for upper-layer applications. 

After the  **SetSource**  function is called, the player invokes  [OnBufferAvailable](multimedia_mediacommon.md#gaaebd4fe9df44b434f410aec32cf23467)  to notify your application of the buffer memory block that can be filled with data. The player can invoke  [SetStreamCallback](multimedia_mediacommon.md#ga078516891396a86226c945e02c79c1f5)  to register a callback for your application. For example, the  **GetBuffer**  callback obtains the address of the buffer block and sends the filled buffer memory block to the player. The buffer memory block is allocated and processed on the player.  **[StreamSource](ohos-media-streamsource.md)**is available only for the media source of the  **SOURCE\_TYPE\_STREAM**  type. For details, see  [SourceType](format.md#ga3ae727773c367ac1041d72ac770a0ab1). 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1887496875165633"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table767384912165633"></a>
<table><thead align="left"><tr id="row1063274123165633"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p967247282165633"><a name="p967247282165633"></a><a name="p967247282165633"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1482257334165633"><a name="p1482257334165633"></a><a name="p1482257334165633"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row776083373165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2008144799165633"><a name="p2008144799165633"></a><a name="p2008144799165633"></a><a href="multimedia_mediacommon.md#gaaebd4fe9df44b434f410aec32cf23467">OnBufferAvailable</a> (size_t <a href="utils.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>, size_t offset, size_t size)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p744364744165633"><a name="p744364744165633"></a><a name="p744364744165633"></a>virtual void </p>
<p id="p1355870248165633"><a name="p1355870248165633"></a><a name="p1355870248165633"></a>Notifies your application of the information about the buffer memory block that can be filled with data. </p>
</td>
</tr>
<tr id="row1072591066165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p975049594165633"><a name="p975049594165633"></a><a name="p975049594165633"></a><a href="multimedia_mediacommon.md#ga078516891396a86226c945e02c79c1f5">SetStreamCallback</a> (const std::shared_ptr&lt; <a href="ohos-media-streamcallback.md">StreamCallback</a> &gt; &amp;callback)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p428381454165633"><a name="p428381454165633"></a><a name="p428381454165633"></a>virtual void </p>
<p id="p305249052165633"><a name="p305249052165633"></a><a name="p305249052165633"></a>Sets a callback function for your application. </p>
</td>
</tr>
</tbody>
</table>

