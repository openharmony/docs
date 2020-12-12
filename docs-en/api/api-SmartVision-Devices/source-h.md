# source.h<a name="EN-US_TOPIC_0000001055678072"></a>

-   [Overview](#section940338861165629)
-   [Summary](#section358937917165629)
-   [Data Structures](#nested-classes)
-   [Enumerations](#enum-members)

## **Overview**<a name="section940338861165629"></a>

**Related Modules:**

[MultiMedia\_MediaCommon](multimedia_mediacommon.md)

**Description:**

Declares the  **Source**  class, which is used to implement source-related operations. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section358937917165629"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table1338438214165629"></a>
<table><thead align="left"><tr id="row1269235590165629"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p400231630165629"><a name="p400231630165629"></a><a name="p400231630165629"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2044713804165629"><a name="p2044713804165629"></a><a name="p2044713804165629"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2125760638165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p661330049165629"><a name="p661330049165629"></a><a name="p661330049165629"></a><a href="ohos-media-streamcallback.md">OHOS::Media::StreamCallback</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1686627188165629"><a name="p1686627188165629"></a><a name="p1686627188165629"></a>Provides functions to obtain the address of a buffer memory and write the filled buffers into the playback queue. You need to implement the <strong id="b1391281773165629"><a name="b1391281773165629"></a><a name="b1391281773165629"></a><a href="ohos-media-streamcallback.md">StreamCallback</a></strong> functions in a player object. </p>
</td>
</tr>
<tr id="row626534662165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1089529073165629"><a name="p1089529073165629"></a><a name="p1089529073165629"></a><a href="ohos-media-streamsource.md">OHOS::Media::StreamSource</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1928266407165629"><a name="p1928266407165629"></a><a name="p1928266407165629"></a>Provides functions related to the stream source for upper-layer applications. </p>
</td>
</tr>
<tr id="row918324836165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1946668018165629"><a name="p1946668018165629"></a><a name="p1946668018165629"></a><a href="ohos-media-source.md">OHOS::Media::Source</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p377517952165629"><a name="p377517952165629"></a><a name="p377517952165629"></a>Provides functions to implement source-related operations. </p>
</td>
</tr>
</tbody>
</table>

## Enumerations<a name="enum-members"></a>

<a name="table1651205383165629"></a>
<table><thead align="left"><tr id="row281550752165629"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1757409343165629"><a name="p1757409343165629"></a><a name="p1757409343165629"></a>Enumeration Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p715476901165629"><a name="p715476901165629"></a><a name="p715476901165629"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1150959693165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p443996446165629"><a name="p443996446165629"></a><a name="p443996446165629"></a><a href="multimedia_mediacommon.md#ga4052b7b55dfd94f1d07678e79d80b507">OHOS::Media::SourceType</a> : int32_t { <a href="multimedia_mediacommon.md#gga4052b7b55dfd94f1d07678e79d80b507ae456eda14b2359e13cc36f77af92c11b">OHOS::Media::SourceType::SOURCE_TYPE_URI</a> = 0, <a href="multimedia_mediacommon.md#gga4052b7b55dfd94f1d07678e79d80b507a4134c6ec0b1a7fda26c38b8932e606e5">OHOS::Media::SourceType::SOURCE_TYPE_FD</a>, <a href="multimedia_mediacommon.md#gga4052b7b55dfd94f1d07678e79d80b507a538f01f856d995123459a44642a7dc86">OHOS::Media::SourceType::SOURCE_TYPE_STREAM</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1193150460165629"><a name="p1193150460165629"></a><a name="p1193150460165629"></a>Enumerates media source types. </p>
</td>
</tr>
</tbody>
</table>

