# recorder.h<a name="EN-US_TOPIC_0000001054479541"></a>

-   [Overview](#section882836656165628)
-   [Summary](#section2092301963165628)
-   [Data Structures](#nested-classes)
-   [Enumerations](#enum-members)

## **Overview**<a name="section882836656165628"></a>

**Related Modules:**

[MultiMedia\_Recorder](multimedia_recorder.md)

**Description:**

Declares the  **Recorder**  class for audio and video recording. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section2092301963165628"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table836791229165628"></a>
<table><thead align="left"><tr id="row909882162165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p855711725165628"><a name="p855711725165628"></a><a name="p855711725165628"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1440141522165628"><a name="p1440141522165628"></a><a name="p1440141522165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1226757676165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1591023097165628"><a name="p1591023097165628"></a><a name="p1591023097165628"></a><a href="ohos-media-recordercallback.md">OHOS::Media::RecorderCallback</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p75101327165628"><a name="p75101327165628"></a><a name="p75101327165628"></a>Provides listeners for recording errors and information events. </p>
</td>
</tr>
<tr id="row999524377165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p684141954165628"><a name="p684141954165628"></a><a name="p684141954165628"></a><a href="ohos-media-recorder.md">OHOS::Media::Recorder</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p527933266165628"><a name="p527933266165628"></a><a name="p527933266165628"></a>Provides functions for audio and video recording. </p>
</td>
</tr>
</tbody>
</table>

## Enumerations<a name="enum-members"></a>

<a name="table213692527165628"></a>
<table><thead align="left"><tr id="row1774335948165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1914189317165628"><a name="p1914189317165628"></a><a name="p1914189317165628"></a>Enumeration Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1496032814165628"><a name="p1496032814165628"></a><a name="p1496032814165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row863968020165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1575199972165628"><a name="p1575199972165628"></a><a name="p1575199972165628"></a><a href="multimedia_recorder.md#gad252d27f9ce4b6ae0756bfeaa5f34490">OHOS::Media::VideoSourceType</a> : int32_t { <a href="multimedia_recorder.md#ggad252d27f9ce4b6ae0756bfeaa5f34490ad137c55cd463c87ff8ea66c116da2e57">OHOS::Media::VIDEO_SOURCE_SURFACE_YUV</a> = 0, <a href="multimedia_recorder.md#ggad252d27f9ce4b6ae0756bfeaa5f34490afcca9aba53005db99434c74f62803d6d">OHOS::Media::VIDEO_SOURCE_SURFACE_RGB</a>, <a href="multimedia_recorder.md#ggad252d27f9ce4b6ae0756bfeaa5f34490a9316951d19d2ed845d2c0ef92c541eb8">OHOS::Media::VIDEO_SOURCE_SURFACE_ES</a>, <a href="multimedia_recorder.md#ggad252d27f9ce4b6ae0756bfeaa5f34490af19a30a10d95948a7dab0317a4e2447b">OHOS::Media::VIDEO_SOURCE_BUTT</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1651992334165628"><a name="p1651992334165628"></a><a name="p1651992334165628"></a>Enumerates video source types. </p>
</td>
</tr>
<tr id="row1702795926165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1930507820165628"><a name="p1930507820165628"></a><a name="p1930507820165628"></a><a href="multimedia_recorder.md#gaccc05bb178cecd760369ea096dceae4c">OHOS::Media::DataSourceType</a> : int32_t { <a href="multimedia_recorder.md#ggaccc05bb178cecd760369ea096dceae4ca18ab16c027cd6de93c4e64be806caed0">OHOS::Media::IMAGE</a> = 0 }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1716991786165628"><a name="p1716991786165628"></a><a name="p1716991786165628"></a>Enumerates data source types. </p>
</td>
</tr>
<tr id="row1673398237165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1996461058165628"><a name="p1996461058165628"></a><a name="p1996461058165628"></a><a href="multimedia_recorder.md#ga3dfe2e61369bf1c081ce569e235354df">OHOS::Media::OutputFormatType</a> : int32_t { <a href="multimedia_recorder.md#gga3dfe2e61369bf1c081ce569e235354dfa5f2bb1abd7404320dcd46e7540a22586">OHOS::Media::FORMAT_DEFAULT</a> = 0, <a href="multimedia_recorder.md#gga3dfe2e61369bf1c081ce569e235354dfac7e010e743dca6fc60780bb745707d57">OHOS::Media::FORMAT_MPEG_4</a>, <a href="multimedia_recorder.md#gga3dfe2e61369bf1c081ce569e235354dfa2abf22281e8d5a30da1f0700d9bf45a3">OHOS::Media::FORMAT_TS</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p19872771165628"><a name="p19872771165628"></a><a name="p19872771165628"></a>Enumerates output file formats. </p>
</td>
</tr>
<tr id="row780342831165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1487995393165628"><a name="p1487995393165628"></a><a name="p1487995393165628"></a><a href="multimedia_recorder.md#ga8759c7e5a74964a584a716f4ec0b7edb">OHOS::Media::FileSplitType</a> : int32_t { <a href="multimedia_recorder.md#gga8759c7e5a74964a584a716f4ec0b7edba9010fd43e012d61772ff5db3a9bdaf02">OHOS::Media::FILE_SPLIT_POST</a> = 0, <a href="multimedia_recorder.md#gga8759c7e5a74964a584a716f4ec0b7edba01981748b792c27773467ea70099be65">OHOS::Media::FILE_SPLIT_PRE</a>, <a href="multimedia_recorder.md#gga8759c7e5a74964a584a716f4ec0b7edbae05fb41e422f91399d2e2efc3e84943b">OHOS::Media::FILE_SPLIT_NORMAL</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p979857495165628"><a name="p979857495165628"></a><a name="p979857495165628"></a>Enumerates file split types. </p>
</td>
</tr>
</tbody>
</table>

