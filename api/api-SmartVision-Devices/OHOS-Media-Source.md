# OHOS::Media::Source<a name="ZH-CN_TOPIC_0000001054799611"></a>

-   [Overview](#section255130152165632)
-   [Summary](#section1546565473165632)
-   [Public Member Functions](#pub-methods)

## **Overview**<a name="section255130152165632"></a>

**Related Modules:**

[MultiMedia\_MediaCommon](MultiMedia_MediaCommon.md)

**Description:**

Provides functions to implement source-related operations. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1546565473165632"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table2005311646165632"></a>
<table><thead align="left"><tr id="row1262191951165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1084468928165632"><a name="p1084468928165632"></a><a name="p1084468928165632"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1549766325165632"><a name="p1549766325165632"></a><a name="p1549766325165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row564519825165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1060380733165632"><a name="p1060380733165632"></a><a name="p1060380733165632"></a><a href="MultiMedia_MediaCommon.md#gab9bfa209ae382e3ba5d5242e8dfe5b20">Source</a> (const std::string &amp;uri)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p738658045165632"><a name="p738658045165632"></a><a name="p738658045165632"></a> </p>
<p id="p2122493632165632"><a name="p2122493632165632"></a><a name="p2122493632165632"></a>A constructor used to create a <a href="OHOS-Media-Source.md">Source</a> instance based on a specified URI. </p>
</td>
</tr>
<tr id="row1400252143165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1559079600165632"><a name="p1559079600165632"></a><a name="p1559079600165632"></a><a href="MultiMedia_MediaCommon.md#gae3640fec3bb0f33f4076dc30e88dac61">Source</a> (const std::shared_ptr&lt; <a href="OHOS-Media-StreamSource.md">StreamSource</a> &gt; &amp;stream, const <a href="OHOS-Media-Format.md">Format</a> &amp;formats)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p78673258165632"><a name="p78673258165632"></a><a name="p78673258165632"></a> </p>
<p id="p967293309165632"><a name="p967293309165632"></a><a name="p967293309165632"></a>A constructor used to create a <a href="OHOS-Media-Source.md">Source</a> instance based on the stream source and format information. </p>
</td>
</tr>
<tr id="row780028182165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p589677733165632"><a name="p589677733165632"></a><a name="p589677733165632"></a><a href="MultiMedia_MediaCommon.md#ga93a8f8b86a9385436f6bbce10a860770">GetSourceType</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1537457606165632"><a name="p1537457606165632"></a><a name="p1537457606165632"></a><a href="MultiMedia_MediaCommon.md#ga4052b7b55dfd94f1d07678e79d80b507">SourceType</a> </p>
<p id="p307177372165632"><a name="p307177372165632"></a><a name="p307177372165632"></a>Obtains the source type. </p>
</td>
</tr>
<tr id="row2050981259165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1660583137165632"><a name="p1660583137165632"></a><a name="p1660583137165632"></a><a href="MultiMedia_MediaCommon.md#ga69ed2683ce3a632f6b2295fb398e4b7b">GetSourceUri</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1968037257165632"><a name="p1968037257165632"></a><a name="p1968037257165632"></a>const std::string &amp; </p>
<p id="p2028143969165632"><a name="p2028143969165632"></a><a name="p2028143969165632"></a>Obtains the media source URI. </p>
</td>
</tr>
<tr id="row534081837165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1441144073165632"><a name="p1441144073165632"></a><a name="p1441144073165632"></a><a href="MultiMedia_MediaCommon.md#ga395325402881ad38ef40c9ebd13f174d">GetSourceStream</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1695198934165632"><a name="p1695198934165632"></a><a name="p1695198934165632"></a>const std::shared_ptr&lt; <a href="OHOS-Media-StreamSource.md">StreamSource</a> &gt; &amp; </p>
<p id="p1494839035165632"><a name="p1494839035165632"></a><a name="p1494839035165632"></a>Obtains information about the media source stream. </p>
</td>
</tr>
<tr id="row1441172813165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1101763145165632"><a name="p1101763145165632"></a><a name="p1101763145165632"></a><a href="MultiMedia_MediaCommon.md#gafbd3c732660124a1dc1d9dd0dfb51393">GetSourceStreamFormat</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p44572960165632"><a name="p44572960165632"></a><a name="p44572960165632"></a>const <a href="OHOS-Media-Format.md">Format</a> &amp; </p>
<p id="p539692111165632"><a name="p539692111165632"></a><a name="p539692111165632"></a>Obtains the media source stream format. </p>
</td>
</tr>
</tbody>
</table>

