# Format<a name="EN-US_TOPIC_0000001055358056"></a>

-   [Overview](#section343241842165623)
-   [Summary](#section394624958165623)
-   [Files](#files)
-   [Data Structures](#nested-classes)
-   [Macros](#define-members)
-   [Typedefs](#typedef-members)
-   [Enumerations](#enum-members)
-   [Functions](#func-members)
-   [Details](#section1693197691165623)
-   [Macro Definition](#section935031532165623)
-   [FORMAT\_INVALID\_PROGRAM\_ID](#gab4007b017f1edad143959af034e32bf7)
-   [FORMAT\_INVALID\_TRACK\_ID](#ga62037bb16334896e1bb6d35a71618881)
-   [FORMAT\_LANGUAGE\_LEN](#gaa70508bb1089c99f9aa3d59fcbdfa8eb)
-   [FORMAT\_MAX\_LANGUAGE\_NUM](#gac2d2d077edb8e9bb9f85ab6350015c5b)
-   [FORMAT\_TITLE\_LEN](#gadb635fac84a9d62e99c69e75d4de85c3)
-   [URL\_LEN](#ga1ac54dd3b9b49c1800b5f502a87650be)
-   [Typedef](#section545940743165623)
-   [CALLBACK\_HANDLE](#gab928f39c359734527bda3fd160f89331)
-   [Enumeration Type](#section1904403459165623)
-   [AudioSampleFmt](#gadf0700999998f587f0017c4d02977b22)
-   [CodecFormat](#gaf7ed135f15d4b218d41705bac0122ba7)
-   [DataFlags](#gacff079fdf8427c743f9197ea5be33a7f)
-   [FormatErrorType](#ga31e7fcf42722fa15e4e5489c2fef9092)
-   [FormatInfoType](#ga6f00342925d3d5e586c76f8695985cad)
-   [FormatSeekMode](#ga14aa9d18a71eff4a0b70f748f0377c94)
-   [FrameType](#gad495a9f61af7fff07d7e97979d1ab854)
-   [KeyType](#gaab0feaba617470cb4aa830dc5935238c)
-   [ManualSplitType](#ga10d9833450f29129d249c41d9acb4bc4)
-   [OutputFormat](#gaeb712c6c6c0a8af0dfd79f451ecb9277)
-   [OutputType](#ga4e0517338e6c4a31a2addafc06d4f3a3)
-   [SourceType](#ga3ae727773c367ac1041d72ac770a0ab1)
-   [SubtitleFormat](#gadac45ce4731516c262292c15433439b3)
-   [SubtitleFrameType](#ga43b7f046e365a89697272d850b0517b7)
-   [TrackSourceType](#ga953bc46f95d7b2d8866838d792f8f6aa)
-   [TrackType](#gad80740dd555f7d3688d2c4d9f44d3b04)
-   [Function](#section1772238272165623)
-   [FormatDeInit\(\)](#gabb574933ebb4f3d1d2ed299e79aeee2c)
-   [FormatDemuxerCreate\(\)](#ga183fbc31f2c9877ef56464abcccef374)
-   [FormatDemuxerDestory\(\)](#ga98fd9a5a5d1ffd275fc46f898ca08413)
-   [FormatDemuxerFreeFrame\(\)](#ga291b805de194c695b72eb5ad721103d5)
-   [FormatDemuxerGetBufferConfig\(\)](#ga565cbb52c95a95aab4dcc957fe998b5f)
-   [FormatDemuxerGetFileInfo\(\)](#gad807d61c65e89629c7eed8f97426fd5a)
-   [FormatDemuxerGetParameter\(\)](#ga6c2a1aa9fdf1db8e2f14a3a92ffa23d5)
-   [FormatDemuxerGetSelectedTrack\(\)](#gab6ef68051ee2ed0015e721bedb1af61c)
-   [FormatDemuxerPrepare\(\)](#gacfcf40d869a48125bd67d17f8a4fc3ce)
-   [FormatDemuxerReadFrame\(\)](#ga7b20e1b88413d20a348d7f796917cd94)
-   [FormatDemuxerSeek\(\)](#gad53f1e848f3c2e0c8fa056a312b2ed6c)
-   [FormatDemuxerSelectTrack\(\)](#ga1d9cb94614e207def34f13eaa16ef2b7)
-   [FormatDemuxerSetBufferConfig\(\)](#gad2a15f3fa640f3f9e8e684d71b3a12cb)
-   [FormatDemuxerSetCallBack\(\)](#ga9ef126fc3132b556d49a275799e7753b)
-   [FormatDemuxerSetParameter\(\)](#ga92d859ba4745ce26b94595daaa40462d)
-   [FormatDemuxerStart\(\)](#ga08544b1ba3373bf5cb211586e8195673)
-   [FormatDemuxerStop\(\)](#ga8a693d8be0b4b688d99e513608884e91)
-   [FormatDemuxerUnselectTrack\(\)](#gaf5fd5bab9613d133827054f157d5520e)
-   [FormatInit\(\)](#gae10a50c8f3de6e54ee0dc3937f755920)
-   [FormatMuxerAddTrack\(\)](#ga94e9ab3e534b69a358b7cc16e4f79b78)
-   [FormatMuxerCreate\(\)](#ga9c390276cb90f4753c32af5aa5c600ad)
-   [FormatMuxerDestory\(\)](#gaa41d46cef6d5e81c85614edbf824d803)
-   [FormatMuxerGetParameter\(\)](#ga67dd7361dedf335496afef19d54e4138)
-   [FormatMuxerSetCallBack\(\)](#ga108cd7e319ade568f71890d57585f153)
-   [FormatMuxerSetFileSplitDuration\(\)](#ga6eed6b5e7522e102f2d79d0dd33fd2a9)
-   [FormatMuxerSetLocation\(\)](#ga967ba14fa1231eed2942b87a09deb953)
-   [FormatMuxerSetMaxFileDuration\(\)](#gae931061d822c4ffe447e9ba40a991597)
-   [FormatMuxerSetMaxFileSize\(\)](#ga6f3ba422c9bbca4c1d5a7a3fe85dd9b9)
-   [FormatMuxerSetNextOutputFile\(\)](#gaa936b56996294d76977537267fef058c)
-   [FormatMuxerSetOrientation\(\)](#ga96fc57913c3202d2d23704c69d660be5)
-   [FormatMuxerSetParameter\(\)](#gad4335ebaa7c165b885a00fe61aae0cd9)
-   [FormatMuxerStart\(\)](#ga9a2af831a6f4a63dc85d2c23b5c7c81b)
-   [FormatMuxerStop\(\)](#ga66a3a5a1ec6d01fcbd6339f7eee1151b)
-   [FormatMuxerWriteFrame\(\)](#ga82037d271e77da206e16582e774ee048)

## **Overview**<a name="section343241842165623"></a>

**Description:**

Defines format-related APIs. 

For example, you use this module to define custom data types and to initialize, create, destroy the muxer and demuxer, and set their parameters. Also, you can read demuxer data frames, select demuxer tracks, add muxer tracks, and write data frames into a container.

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section394624958165623"></a>

## Files<a name="files"></a>

<a name="table250203027165623"></a>
<table><thead align="left"><tr id="row610913252165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1577344995165623"><a name="p1577344995165623"></a><a name="p1577344995165623"></a>File Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p836228030165623"><a name="p836228030165623"></a><a name="p836228030165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1096925972165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p15944504165623"><a name="p15944504165623"></a><a name="p15944504165623"></a><a href="format_interface-h.md">format_interface.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p475897884165623"><a name="p475897884165623"></a><a name="p475897884165623"></a>Declares format-related APIs. </p>
</td>
</tr>
<tr id="row1675969777165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2017796879165623"><a name="p2017796879165623"></a><a name="p2017796879165623"></a><a href="format_type-h.md">format_type.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1518322087165623"><a name="p1518322087165623"></a><a name="p1518322087165623"></a>Declares format-related structures and enumerations, including custom data types for file information, programs, information about audio and video subtitle tracks, source data types, output data types, split types, and data frames. </p>
</td>
</tr>
<tr id="row1259765074165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2048036229165623"><a name="p2048036229165623"></a><a name="p2048036229165623"></a><a href="parameter_item-h.md">parameter_item.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p784622393165623"><a name="p784622393165623"></a><a name="p784622393165623"></a>Defines format-related structures and enumerations used to configure and obtain dynamic parameters. </p>
</td>
</tr>
</tbody>
</table>

## Data Structures<a name="nested-classes"></a>

<a name="table1687654606165623"></a>
<table><thead align="left"><tr id="row627814147165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1662035498165623"><a name="p1662035498165623"></a><a name="p1662035498165623"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1616930809165623"><a name="p1616930809165623"></a><a name="p1616930809165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row595080176165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2067397916165623"><a name="p2067397916165623"></a><a name="p2067397916165623"></a><a href="formatbuffersetting.md">FormatBufferSetting</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p720254626165623"><a name="p720254626165623"></a><a name="p720254626165623"></a>Defines the buffer configuration. </p>
</td>
</tr>
<tr id="row1645954427165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2015009108165623"><a name="p2015009108165623"></a><a name="p2015009108165623"></a><a href="formatframe.md">FormatFrame</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p890785090165623"><a name="p890785090165623"></a><a name="p890785090165623"></a>Defines the data frame, which is used for data transferring. </p>
</td>
</tr>
<tr id="row1213719876165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p62041723165623"><a name="p62041723165623"></a><a name="p62041723165623"></a><a href="audiotrackinfo.md">AudioTrackInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1967809993165623"><a name="p1967809993165623"></a><a name="p1967809993165623"></a>Defines audio track information. </p>
</td>
</tr>
<tr id="row1467662400165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2094896841165623"><a name="p2094896841165623"></a><a name="p2094896841165623"></a><a href="videotrackinfo.md">VideoTrackInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1449714193165623"><a name="p1449714193165623"></a><a name="p1449714193165623"></a>Defines video track information. </p>
</td>
</tr>
<tr id="row452650548165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1470266738165623"><a name="p1470266738165623"></a><a name="p1470266738165623"></a><a href="subimageinfo.md">SubImageInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2034803978165623"><a name="p2034803978165623"></a><a name="p2034803978165623"></a>Defines image information. </p>
</td>
</tr>
<tr id="row11639638165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p697079382165623"><a name="p697079382165623"></a><a name="p697079382165623"></a><a href="imagetrackinfo.md">ImageTrackInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p938926616165623"><a name="p938926616165623"></a><a name="p938926616165623"></a>Defines image stream information. </p>
</td>
</tr>
<tr id="row21457439165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1423457559165623"><a name="p1423457559165623"></a><a name="p1423457559165623"></a><a href="subtitletrackinfo.md">SubtitleTrackInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p730490394165623"><a name="p730490394165623"></a><a name="p730490394165623"></a>Defines subtitle stream information. </p>
</td>
</tr>
<tr id="row2113580990165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1165335162165623"><a name="p1165335162165623"></a><a name="p1165335162165623"></a><a href="trackinfo.md">TrackInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1886310891165623"><a name="p1886310891165623"></a><a name="p1886310891165623"></a>Defines track information. </p>
</td>
</tr>
<tr id="row652245687165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p817987684165623"><a name="p817987684165623"></a><a name="p817987684165623"></a><a href="programinfo.md">ProgramInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1445760414165623"><a name="p1445760414165623"></a><a name="p1445760414165623"></a>Defines program information. </p>
</td>
</tr>
<tr id="row1953215496165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1000748606165623"><a name="p1000748606165623"></a><a name="p1000748606165623"></a><a href="fileinfo.md">FileInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p203103760165623"><a name="p203103760165623"></a><a name="p203103760165623"></a>Defines movie file information. </p>
</td>
</tr>
<tr id="row876092577165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1355292561165623"><a name="p1355292561165623"></a><a name="p1355292561165623"></a><a href="bufferstream.md">BufferStream</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1975980095165623"><a name="p1975980095165623"></a><a name="p1975980095165623"></a>Defines the function for reading stream data. </p>
</td>
</tr>
<tr id="row1337458068165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2061227101165623"><a name="p2061227101165623"></a><a name="p2061227101165623"></a><a href="formatsource.md">FormatSource</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1423586976165623"><a name="p1423586976165623"></a><a name="p1423586976165623"></a>Defines the demuxer data source. </p>
</td>
</tr>
<tr id="row2094789294165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p840122104165623"><a name="p840122104165623"></a><a name="p840122104165623"></a><a href="formatoutputconfig.md">FormatOutputConfig</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p413565377165623"><a name="p413565377165623"></a><a name="p413565377165623"></a>Defines the muxer output configuration. </p>
</td>
</tr>
<tr id="row1426835597165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p116666317165623"><a name="p116666317165623"></a><a name="p116666317165623"></a><a href="videotracksourceinfo.md">VideoTrackSourceInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p914230487165623"><a name="p914230487165623"></a><a name="p914230487165623"></a>Defines information about the muxer video source. </p>
</td>
</tr>
<tr id="row450856238165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1405520809165623"><a name="p1405520809165623"></a><a name="p1405520809165623"></a><a href="audiotracksourceinfo.md">AudioTrackSourceInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p174209595165623"><a name="p174209595165623"></a><a name="p174209595165623"></a>Defines information about the muxer audio source. </p>
</td>
</tr>
<tr id="row1817563508165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1770130943165623"><a name="p1770130943165623"></a><a name="p1770130943165623"></a><a href="datatracksourceinfo.md">DataTrackSourceInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p487338996165623"><a name="p487338996165623"></a><a name="p487338996165623"></a>Defines information about the muxer data source. </p>
</td>
</tr>
<tr id="row977916800165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1671441253165623"><a name="p1671441253165623"></a><a name="p1671441253165623"></a><a href="tracksource.md">TrackSource</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1173429380165623"><a name="p1173429380165623"></a><a name="p1173429380165623"></a>Defines information about the muxer source. </p>
</td>
</tr>
<tr id="row967508974165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p343660224165623"><a name="p343660224165623"></a><a name="p343660224165623"></a><a href="formatcallback.md">FormatCallback</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1482530861165623"><a name="p1482530861165623"></a><a name="p1482530861165623"></a>Defines listener callbacks for the format. </p>
</td>
</tr>
<tr id="row391025592165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1701951486165623"><a name="p1701951486165623"></a><a name="p1701951486165623"></a><a href="parameteritem.md">ParameterItem</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p254575910165623"><a name="p254575910165623"></a><a name="p254575910165623"></a>Defines a structure for configuring and obtaining dynamic parameters. </p>
</td>
</tr>
</tbody>
</table>

## Macros<a name="define-members"></a>

<a name="table740249954165623"></a>
<table><thead align="left"><tr id="row27297566165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1985174483165623"><a name="p1985174483165623"></a><a name="p1985174483165623"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p449799254165623"><a name="p449799254165623"></a><a name="p449799254165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row471773813165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2062757896165623"><a name="p2062757896165623"></a><a name="p2062757896165623"></a><a href="format.md#gac2d2d077edb8e9bb9f85ab6350015c5b">FORMAT_MAX_LANGUAGE_NUM</a>   4</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">&nbsp;</td>
</tr>
<tr id="row177950246165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p537607314165623"><a name="p537607314165623"></a><a name="p537607314165623"></a><a href="format.md#gaa70508bb1089c99f9aa3d59fcbdfa8eb">FORMAT_LANGUAGE_LEN</a>   4</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">&nbsp;</td>
</tr>
<tr id="row1787947060165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1291679543165623"><a name="p1291679543165623"></a><a name="p1291679543165623"></a><a href="format.md#gadb635fac84a9d62e99c69e75d4de85c3">FORMAT_TITLE_LEN</a>   64</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">&nbsp;</td>
</tr>
<tr id="row410523882165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1592186064165623"><a name="p1592186064165623"></a><a name="p1592186064165623"></a><a href="format.md#ga62037bb16334896e1bb6d35a71618881">FORMAT_INVALID_TRACK_ID</a>   -1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">&nbsp;</td>
</tr>
<tr id="row162527848165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1760064838165623"><a name="p1760064838165623"></a><a name="p1760064838165623"></a><a href="format.md#gab4007b017f1edad143959af034e32bf7">FORMAT_INVALID_PROGRAM_ID</a>   -1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">&nbsp;</td>
</tr>
<tr id="row1905098762165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1650195357165623"><a name="p1650195357165623"></a><a name="p1650195357165623"></a><a href="format.md#ga1ac54dd3b9b49c1800b5f502a87650be">URL_LEN</a>   4096</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">&nbsp;</td>
</tr>
</tbody>
</table>

## Typedefs<a name="typedef-members"></a>

<a name="table2039952153165623"></a>
<table><thead align="left"><tr id="row1797848854165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1907900378165623"><a name="p1907900378165623"></a><a name="p1907900378165623"></a>Typedef Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1034923117165623"><a name="p1034923117165623"></a><a name="p1034923117165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1169572934165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1085399161165623"><a name="p1085399161165623"></a><a name="p1085399161165623"></a><a href="format.md#gab928f39c359734527bda3fd160f89331">CALLBACK_HANDLE</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p368680988165623"><a name="p368680988165623"></a><a name="p368680988165623"></a>typedef void * </p>
<p id="p2097768501165623"><a name="p2097768501165623"></a><a name="p2097768501165623"></a>Indicates the pointer to the callback handle for listening the muxer. </p>
</td>
</tr>
</tbody>
</table>

## Enumerations<a name="enum-members"></a>

<a name="table1712164498165623"></a>
<table><thead align="left"><tr id="row144706643165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p958390343165623"><a name="p958390343165623"></a><a name="p958390343165623"></a>Enumeration Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1457473339165623"><a name="p1457473339165623"></a><a name="p1457473339165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1255481134165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1391248396165623"><a name="p1391248396165623"></a><a name="p1391248396165623"></a><a href="format.md#gad495a9f61af7fff07d7e97979d1ab854">FrameType</a> {   <a href="format.md#ggad495a9f61af7fff07d7e97979d1ab854a54c4b682d718fd6c8e5f224ee2fad841">FRAME_TYPE_NONE</a>, <a href="format.md#ggad495a9f61af7fff07d7e97979d1ab854a709dd5ff367a8ff7669fda5386291796">FRAME_TYPE_AUDIO</a>, <a href="format.md#ggad495a9f61af7fff07d7e97979d1ab854a7670f4378c84a94fb65f6c30c4b1a096">FRAME_TYPE_VIDEO</a>, <a href="format.md#ggad495a9f61af7fff07d7e97979d1ab854a90bb6db5c310d60ccd4a6ec1b172e9e5">FRAME_TYPE_IMAGE</a>,   <a href="format.md#ggad495a9f61af7fff07d7e97979d1ab854a3b43393b8fff68297e4daf0c32193704">FRAME_TYPE_SUB</a>, <a href="format.md#ggad495a9f61af7fff07d7e97979d1ab854a75641aebcb420f0f661dc8acefdc9b30">FRAME_TYPE_DATA</a>, <a href="format.md#ggad495a9f61af7fff07d7e97979d1ab854a7afc81a56325cb4a7356663ccd270931">FRAME_TYPE_BUT</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p337151454165623"><a name="p337151454165623"></a><a name="p337151454165623"></a>Enumerates data frame types. </p>
</td>
</tr>
<tr id="row920898472165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p283652804165623"><a name="p283652804165623"></a><a name="p283652804165623"></a><a href="format.md#ga14aa9d18a71eff4a0b70f748f0377c94">FormatSeekMode</a> { <a href="format.md#gga14aa9d18a71eff4a0b70f748f0377c94a59c30f44f3b65ff91ee18441315dbbcc">FORMAT_SEEK_MODE_FORWARD_KEY</a>, <a href="format.md#gga14aa9d18a71eff4a0b70f748f0377c94a00f9ebeb7f829675bde8cad3832efcdd">FORMAT_SEEK_MODE_BACKWARD_KEY</a>, <a href="format.md#gga14aa9d18a71eff4a0b70f748f0377c94a605cab737a9cfc0a06f911efa117646d">FORMAT_SEEK_MODE_CLOSEST_KEY</a>, <a href="format.md#gga14aa9d18a71eff4a0b70f748f0377c94a1a87eaf0f3e52132aba4563232a6f248">SEEK_MODE_BUT</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2038230432165623"><a name="p2038230432165623"></a><a name="p2038230432165623"></a>Enumerates seek modes. </p>
</td>
</tr>
<tr id="row526811283165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1299878444165623"><a name="p1299878444165623"></a><a name="p1299878444165623"></a><a href="format.md#gaf7ed135f15d4b218d41705bac0122ba7">CodecFormat</a> {   <a href="format.md#ggaf7ed135f15d4b218d41705bac0122ba7aa0c89a6d185559b38e63265976dde7f4">CODEC_H264</a> = 0, <a href="format.md#ggaf7ed135f15d4b218d41705bac0122ba7a4adc0c5e441be1b1a642f481e3111cae">CODEC_H265</a>, <a href="format.md#ggaf7ed135f15d4b218d41705bac0122ba7ab6432cb3fb17152277af1f486e182612">CODEC_JPEG</a>, <a href="format.md#ggaf7ed135f15d4b218d41705bac0122ba7a8a0888876671d503c2c5e15059461c06">CODEC_AAC</a>,   <a href="format.md#ggaf7ed135f15d4b218d41705bac0122ba7a44fd5227148450a7870e202d50110509">CODEC_G711A</a>, <a href="format.md#ggaf7ed135f15d4b218d41705bac0122ba7a3ac447dc6b8707c70f6fc6d4e0c552d5">CODEC_G711U</a>, <a href="format.md#ggaf7ed135f15d4b218d41705bac0122ba7ae3014fa1161193bc92227ea0895e1dfb">CODEC_PCM</a>, <a href="format.md#ggaf7ed135f15d4b218d41705bac0122ba7a2a0119a66bcbe797c1bac3057a802c9a">CODEC_MP3</a>,   <a href="format.md#ggaf7ed135f15d4b218d41705bac0122ba7a0bccf3a2f309d8c485283d386322f07b">CODEC_BUT</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p447884345165623"><a name="p447884345165623"></a><a name="p447884345165623"></a>Enumerates audio, video, and image encoding formats. </p>
</td>
</tr>
<tr id="row562403248165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p947223379165623"><a name="p947223379165623"></a><a name="p947223379165623"></a><a href="format.md#gadf0700999998f587f0017c4d02977b22">AudioSampleFmt</a> {   <a href="format.md#ggadf0700999998f587f0017c4d02977b22a650b7f83085e55b6e728fd3ec5beec50">AUDIO_SAMPLE_FMT_S8</a> = 0, <a href="format.md#ggadf0700999998f587f0017c4d02977b22a40335eaa7ca378540941909ed02b51a0">AUDIO_SAMPLE_FMT_S16</a>, <a href="format.md#ggadf0700999998f587f0017c4d02977b22af55ab2a69453af86f0c1602d3645f5f9">AUDIO_SAMPLE_FMT_S24</a>, <a href="format.md#ggadf0700999998f587f0017c4d02977b22ab98feafb8396c0190a4fb719a15ab7c5">AUDIO_SAMPLE_FMT_S32</a>,   <a href="format.md#ggadf0700999998f587f0017c4d02977b22ac2fb27a42b3f79e51dd71ce05b42f9db">AUDIO_SAMPLE_FMT_FLOAT</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p208942886165623"><a name="p208942886165623"></a><a name="p208942886165623"></a>Enumerates audio sampling formats. </p>
</td>
</tr>
<tr id="row842944214165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1352836568165623"><a name="p1352836568165623"></a><a name="p1352836568165623"></a><a href="format.md#ga43b7f046e365a89697272d850b0517b7">SubtitleFrameType</a> { <a href="format.md#gga43b7f046e365a89697272d850b0517b7a6bc8b3dca40c75f6dd22feea62cbdac7">HI_SVR_SUBTITLE_BITMAP</a> = 0x0, <a href="format.md#gga43b7f046e365a89697272d850b0517b7a3ee7a0476e395ec2689f754e58d512a0">HI_SVR_SUBTITLE_TEXT</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p128697178165623"><a name="p128697178165623"></a><a name="p128697178165623"></a>Enumerates subtitle frame types. </p>
</td>
</tr>
<tr id="row1883346558165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1775544769165623"><a name="p1775544769165623"></a><a name="p1775544769165623"></a><a href="format.md#gadac45ce4731516c262292c15433439b3">SubtitleFormat</a> {   <a href="format.md#ggadac45ce4731516c262292c15433439b3abe03cb7d3bb87dcfc197b9e9db7a66f6">FORMAT_SUB_ASS</a> = 0x0, <a href="format.md#ggadac45ce4731516c262292c15433439b3a569e5e22b1c3bf5b9f4cc3f596cfc6db">FORMAT_SUB_LRC</a>, <a href="format.md#ggadac45ce4731516c262292c15433439b3a26f41cfe561866b43a9757b5902c7609">FORMAT_SUB_SRT</a>, <a href="format.md#ggadac45ce4731516c262292c15433439b3ac6665b95ccb70e7a7d87dda6370821ff">FORMAT_SUB_SMI</a>,   <a href="format.md#ggadac45ce4731516c262292c15433439b3a07a0a164bb0081359639cfdef57aa2c2">FORMAT_SUB_SUB</a>, <a href="format.md#ggadac45ce4731516c262292c15433439b3a5ad9a3ec464416e8395e3e0f6595c253">FORMAT_SUB_TXT</a>, <a href="format.md#ggadac45ce4731516c262292c15433439b3a9f573cd39fab8fc143480bf1eb973574">FORMAT_SUB_HDMV_PGS</a>, <a href="format.md#ggadac45ce4731516c262292c15433439b3a641b27aab74dbbcd88d7d8612b60caad">FORMAT_SUB_DVB_SUB</a>,   <a href="format.md#ggadac45ce4731516c262292c15433439b3a91ab0e8c1931fc3b4f2350a8e18672a6">FORMAT_SUB_DVD_SUB</a>, <a href="format.md#ggadac45ce4731516c262292c15433439b3a0750bc81000513246d5785d0ef2c0099">FORMAT_SUB_TTML</a>, <a href="format.md#ggadac45ce4731516c262292c15433439b3ad9de45a6ae50e5443e2d0418b1cdde61">FORMAT_SUB_WEBVTT</a>, <a href="format.md#ggadac45ce4731516c262292c15433439b3a52ed4b60bc3d33d43753555e1edf50d7">FORMAT_SUB_BUTT</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1848012288165623"><a name="p1848012288165623"></a><a name="p1848012288165623"></a>Enumerates subtitle file formats. </p>
</td>
</tr>
<tr id="row563663579165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p788027962165623"><a name="p788027962165623"></a><a name="p788027962165623"></a><a href="format.md#gad80740dd555f7d3688d2c4d9f44d3b04">TrackType</a> {   <a href="format.md#ggad80740dd555f7d3688d2c4d9f44d3b04aae00a139d1f3bbfef9dbda6803497b62">TRACK_TYPE_VIDEO</a>, <a href="format.md#ggad80740dd555f7d3688d2c4d9f44d3b04aab84be45f332c1bd8ab31d9404c6d944">TRACK_TYPE_AUDIO</a>, <a href="format.md#ggad80740dd555f7d3688d2c4d9f44d3b04a3c834b6afb84a38aa490253a3abc5f66">TRACK_TYPE_IMAGE</a>, <a href="format.md#ggad80740dd555f7d3688d2c4d9f44d3b04aff6cb64c75689ea5b11063e0984956f4">TRACK_TYPE_SUB</a>,   <a href="format.md#ggad80740dd555f7d3688d2c4d9f44d3b04abe0c58f8c0a492959631b8f41dbe2af7">TRACK_TYPE_DATA</a>, <a href="format.md#ggad80740dd555f7d3688d2c4d9f44d3b04ad3a1729659a9a6453a2d2bda67cb2c22">TRACK_TYPE_BUT</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1043687791165623"><a name="p1043687791165623"></a><a name="p1043687791165623"></a>Enumerates track types. </p>
</td>
</tr>
<tr id="row1300104026165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p169698746165623"><a name="p169698746165623"></a><a name="p169698746165623"></a><a href="format.md#gacff079fdf8427c743f9197ea5be33a7f">DataFlags</a> {   <a href="format.md#ggacff079fdf8427c743f9197ea5be33a7faf5d58e6ec118e0660b53c7a7df2fdc8b">DATA_FLAG_NONE</a> = 0, <a href="format.md#ggacff079fdf8427c743f9197ea5be33a7fad000cf60ee0b16f1ea7fedbcdb1a9fa0">DATA_FLAG_SYNCFRAME</a> = 1, <a href="format.md#ggacff079fdf8427c743f9197ea5be33a7fa9200ae4b5fc3c72f2e70c9a49c2ebbb0">DATA_FLAG_CODECCONFIG</a> = 2, <a href="format.md#ggacff079fdf8427c743f9197ea5be33a7fabaa169afc64ef32b743217c8194fd8b9">DATA_FLAG_EOS</a> = 4,   <a href="format.md#ggacff079fdf8427c743f9197ea5be33a7fa26019220bb1298308f5c3dcd8a071f63">DATA_FLAG_PARTIAL_FRAME</a> = 8, <a href="format.md#ggacff079fdf8427c743f9197ea5be33a7fa5fd5b55061c6e94a8a12f9cf9d2009a7">DATA_FLAG_ENDOFFRAME</a> = 16, <a href="format.md#ggacff079fdf8427c743f9197ea5be33a7faeb92d052f544e6cde910fb669790a804">DATA_FLAG_MUXER_DATA</a> = 32 }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1474170555165623"><a name="p1474170555165623"></a><a name="p1474170555165623"></a>Enumerates flags of raw stream data. </p>
</td>
</tr>
<tr id="row431291767165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p798890803165623"><a name="p798890803165623"></a><a name="p798890803165623"></a><a href="format.md#ga3ae727773c367ac1041d72ac770a0ab1">SourceType</a> { <a href="format.md#gga3ae727773c367ac1041d72ac770a0ab1a126568132b92d49365d94c4aa00cdde4">SOURCE_TYPE_FD</a> = 0, <a href="format.md#gga3ae727773c367ac1041d72ac770a0ab1a70d32ea5aeaa325764508722ba31403c">SOURCE_TYPE_URI</a>, <a href="format.md#gga3ae727773c367ac1041d72ac770a0ab1a7f632a791d8f6dfbe5940b5648d29e6c">SOURCE_TYPE_STREAM</a>, <a href="format.md#gga3ae727773c367ac1041d72ac770a0ab1ad41c2f0bdca46364d6cd86fc5d4710d3">SOURCE_TYPE_BUT</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1726649930165623"><a name="p1726649930165623"></a><a name="p1726649930165623"></a>Enumerates types of the demuxer data source. </p>
</td>
</tr>
<tr id="row758125611165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p464027198165623"><a name="p464027198165623"></a><a name="p464027198165623"></a><a href="format.md#gaeb712c6c6c0a8af0dfd79f451ecb9277">OutputFormat</a> {   <a href="format.md#ggaeb712c6c6c0a8af0dfd79f451ecb9277a5a01488de2f310872db03b7a6ad26423">OUTPUT_FORMAT_MPEG_4</a> = 0, <a href="format.md#ggaeb712c6c6c0a8af0dfd79f451ecb9277a9eaec301329c61d07d2fe19ca473abc2">OUTPUT_FORMAT_TS</a> = 1, <a href="format.md#ggaeb712c6c6c0a8af0dfd79f451ecb9277a3a0cc99ed9dcc44245dd91591b7accac">OUTPUT_FORMAT_THREE_GPP</a> = 2, <a href="format.md#ggaeb712c6c6c0a8af0dfd79f451ecb9277a68afc7e60f3cdacd5e1fb9a5dcf0ebdb">OUTPUT_FORMAT_HEIF</a> = 3,   <a href="format.md#ggaeb712c6c6c0a8af0dfd79f451ecb9277abb34ec8353ace07dbfd698c05343800d">OUTPUT_FORMAT_OGG</a> = 4, <a href="format.md#ggaeb712c6c6c0a8af0dfd79f451ecb9277a00eb675fb0d802a5143f4f718ea854e3">OUTPUT_FORMAT_INVALID</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1965053778165623"><a name="p1965053778165623"></a><a name="p1965053778165623"></a>Enumerates output file formats. </p>
</td>
</tr>
<tr id="row313753530165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p557428957165623"><a name="p557428957165623"></a><a name="p557428957165623"></a><a href="format.md#ga6f00342925d3d5e586c76f8695985cad">FormatInfoType</a> {   <a href="format.md#gga6f00342925d3d5e586c76f8695985cadaf6214216fd62faa4fc5e20d0d0ba60bf">MUXER_INFO_MAX_DURATION_APPROACHING</a> = 0, <a href="format.md#gga6f00342925d3d5e586c76f8695985cadafc74f41e73f13a29a83b3a13ea6e66e1">MUXER_INFO_MAX_FILESIZE_APPROACHING</a>, <a href="format.md#gga6f00342925d3d5e586c76f8695985cada9722ce52063f6247d5fb17470eb9559e">MUXER_INFO_MAX_DURATION_REACHED</a>, <a href="format.md#gga6f00342925d3d5e586c76f8695985cada71704a053cf3e30c7bf91522b27da8c2">MUXER_INFO_MAX_FILESIZE_REACHED</a>,   <a href="format.md#gga6f00342925d3d5e586c76f8695985cadae63cbc02cf7dc61073b739c08cc58ff4">MUXER_INFO_NEXT_OUTPUT_FILE_STARTED</a>, <a href="format.md#gga6f00342925d3d5e586c76f8695985cada3cf56a06f5990ab657d61bd7e57c1783">MUXER_INFO_FILE_SPLIT_FINISHED</a>, <a href="format.md#gga6f00342925d3d5e586c76f8695985cada5d3901c368e7a4f719134c98c4fa8313">MUXER_INFO_FILE_START_TIME_MS</a>, <a href="format.md#gga6f00342925d3d5e586c76f8695985cadaeb00ffb6342b7ede6b5efe81fa842374">DEMUXER_INFO_PREPARED</a> = 10000,   <a href="format.md#gga6f00342925d3d5e586c76f8695985cada929a71c6b58dfcd974e960b99139a758">DEMUXER_INFO_SEEK_COMPLETE</a>, <a href="format.md#gga6f00342925d3d5e586c76f8695985cada2c4b1c086d55b4d5bf3fedbbf115cf63">DEMUXER_INFO_NETWORK_DISCONNECTED</a>, <a href="format.md#gga6f00342925d3d5e586c76f8695985cadac157e535a1828f3b87c9cc3e6fd8773b">DEMUXER_INFO_NETWORK_RECONNECTED</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p978843104165623"><a name="p978843104165623"></a><a name="p978843104165623"></a>Enumerates types of callback information. </p>
</td>
</tr>
<tr id="row629209131165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p994189674165623"><a name="p994189674165623"></a><a name="p994189674165623"></a><a href="format.md#ga31e7fcf42722fa15e4e5489c2fef9092">FormatErrorType</a> </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1894731300165623"><a name="p1894731300165623"></a><a name="p1894731300165623"></a>Enumerates callback error types. </p>
</td>
</tr>
<tr id="row528518061165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p111243564165623"><a name="p111243564165623"></a><a name="p111243564165623"></a><a href="format.md#ga4e0517338e6c4a31a2addafc06d4f3a3">OutputType</a> { <a href="format.md#gga4e0517338e6c4a31a2addafc06d4f3a3a14ea73c5ea45e0f9b6976d24ac1119e9">OUTPUT_TYPE_FD</a> = 0, <a href="format.md#gga4e0517338e6c4a31a2addafc06d4f3a3a67f14fbe9f23ae5acd2ffc7b00fd6740">OUTPUT_TYPE_URI</a>, <a href="format.md#gga4e0517338e6c4a31a2addafc06d4f3a3a169d19953026c9c3fed4e4433624ca7c">OUTPUT_TYPE_INVALID</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1389769560165623"><a name="p1389769560165623"></a><a name="p1389769560165623"></a>Enumerates muxer output types. </p>
</td>
</tr>
<tr id="row1540707326165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p490594866165623"><a name="p490594866165623"></a><a name="p490594866165623"></a><a href="format.md#ga10d9833450f29129d249c41d9acb4bc4">ManualSplitType</a> { <a href="format.md#gga10d9833450f29129d249c41d9acb4bc4ad283396b08ef486b6615977c881a8724">MANUAL_SPLIT_POST</a> = 0, <a href="format.md#gga10d9833450f29129d249c41d9acb4bc4ae1c9eea90aaf796ffc5932cc50548716">MANUAL_SPLIT_PRE</a>, <a href="format.md#gga10d9833450f29129d249c41d9acb4bc4a2b3ef6d50352019e54db9736e6dde05e">MANUAL_SPLIT_NORMAL</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p134650499165623"><a name="p134650499165623"></a><a name="p134650499165623"></a>Enumerates manual split types for the muxer. </p>
</td>
</tr>
<tr id="row1096993202165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1344575163165623"><a name="p1344575163165623"></a><a name="p1344575163165623"></a><a href="format.md#ga953bc46f95d7b2d8866838d792f8f6aa">TrackSourceType</a> { <a href="format.md#gga953bc46f95d7b2d8866838d792f8f6aaa59d8c33314397a4ae8c1ca7b9e4eb40f">TRACK_SOURCE_TYPE_VIDEO</a> = 0, <a href="format.md#gga953bc46f95d7b2d8866838d792f8f6aaa5e9f39cae59134e444907af8b372b7a4">TRACK_SOURCE_TYPE_AUDIO</a>, <a href="format.md#gga953bc46f95d7b2d8866838d792f8f6aaa5d0d794425327268d08990d26a21f50c">TRACK_SOURCE_TYPE_DATA</a>, <a href="format.md#gga953bc46f95d7b2d8866838d792f8f6aaa0fae189aab417f7c9756523f15a20cca">TRACK_SOURCE_TYPE_INVALID</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p480938539165623"><a name="p480938539165623"></a><a name="p480938539165623"></a>Enumerates types of the muxer source track. </p>
</td>
</tr>
<tr id="row350471295165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p538697116165623"><a name="p538697116165623"></a><a name="p538697116165623"></a><a href="format.md#gaab0feaba617470cb4aa830dc5935238c">KeyType</a> { <a href="format.md#ggaab0feaba617470cb4aa830dc5935238ca5a467ebeae7cb5f1568c3d881f545e70">KEY_TYPE_MIME</a> = 0x6d696d65, <a href="format.md#ggaab0feaba617470cb4aa830dc5935238ca9e29390ad126492d6aeb3a96fe60dfd0">KEY_TYPE_HTTP_HEADERS</a> = 0x68706864, <a href="format.md#ggaab0feaba617470cb4aa830dc5935238ca493efb89298fa6070eb02f4a4e1dc3da">KEY_TYPE_LANGUAGE</a> = 0x6c616e67, <a href="format.md#ggaab0feaba617470cb4aa830dc5935238ca1208cc2b99c8ac61f8fb68fd743cb231">KEY_TYPE_PRE_CACHE</a> = 0x70726361 }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1528178917165623"><a name="p1528178917165623"></a><a name="p1528178917165623"></a>Enumerates key types used for setting and obtaining parameters. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table933240167165623"></a>
<table><thead align="left"><tr id="row820996716165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p811220981165623"><a name="p811220981165623"></a><a name="p811220981165623"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2063226119165623"><a name="p2063226119165623"></a><a name="p2063226119165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1844264796165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p755028651165623"><a name="p755028651165623"></a><a name="p755028651165623"></a><a href="format.md#gae10a50c8f3de6e54ee0dc3937f755920">FormatInit</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1242915667165623"><a name="p1242915667165623"></a><a name="p1242915667165623"></a>void </p>
<p id="p111094735165623"><a name="p111094735165623"></a><a name="p111094735165623"></a>Initializes the format. </p>
</td>
</tr>
<tr id="row1077819785165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2103834666165623"><a name="p2103834666165623"></a><a name="p2103834666165623"></a><a href="format.md#gabb574933ebb4f3d1d2ed299e79aeee2c">FormatDeInit</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1830372221165623"><a name="p1830372221165623"></a><a name="p1830372221165623"></a>void </p>
<p id="p413268243165623"><a name="p413268243165623"></a><a name="p413268243165623"></a>Deinitializes the format. </p>
</td>
</tr>
<tr id="row150387820165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1503193651165623"><a name="p1503193651165623"></a><a name="p1503193651165623"></a><a href="format.md#ga183fbc31f2c9877ef56464abcccef374">FormatDemuxerCreate</a> (const <a href="formatsource.md">FormatSource</a> *source, void **handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1823919191165623"><a name="p1823919191165623"></a><a name="p1823919191165623"></a>int32_t </p>
<p id="p934039441165623"><a name="p934039441165623"></a><a name="p934039441165623"></a>Creates a demuxer component and returns its context handle. </p>
</td>
</tr>
<tr id="row1304009896165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p359602892165623"><a name="p359602892165623"></a><a name="p359602892165623"></a><a href="format.md#ga92d859ba4745ce26b94595daaa40462d">FormatDemuxerSetParameter</a> (const void *handle, int32_t trackId, const <a href="parameteritem.md">ParameterItem</a> *metaData, int32_t metaDataCnt)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1643835809165623"><a name="p1643835809165623"></a><a name="p1643835809165623"></a>int32_t </p>
<p id="p1503876581165623"><a name="p1503876581165623"></a><a name="p1503876581165623"></a>Sets demuxer attributes. </p>
</td>
</tr>
<tr id="row2142835417165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2055520104165623"><a name="p2055520104165623"></a><a name="p2055520104165623"></a><a href="format.md#ga6c2a1aa9fdf1db8e2f14a3a92ffa23d5">FormatDemuxerGetParameter</a> (const void *handle, int32_t trackId, <a href="parameteritem.md">ParameterItem</a> *metaData)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1407815916165623"><a name="p1407815916165623"></a><a name="p1407815916165623"></a>int32_t </p>
<p id="p1301959890165623"><a name="p1301959890165623"></a><a name="p1301959890165623"></a>Obtains demuxer attributes. </p>
</td>
</tr>
<tr id="row133740851165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1772548814165623"><a name="p1772548814165623"></a><a name="p1772548814165623"></a><a href="format.md#ga9ef126fc3132b556d49a275799e7753b">FormatDemuxerSetCallBack</a> (void *handle, const <a href="formatcallback.md">FormatCallback</a> *callBack)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p190549299165623"><a name="p190549299165623"></a><a name="p190549299165623"></a>int32_t </p>
<p id="p58293675165623"><a name="p58293675165623"></a><a name="p58293675165623"></a>Sets a callback for the demuxer. </p>
</td>
</tr>
<tr id="row1860036587165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2139481597165623"><a name="p2139481597165623"></a><a name="p2139481597165623"></a><a href="format.md#gad2a15f3fa640f3f9e8e684d71b3a12cb">FormatDemuxerSetBufferConfig</a> (void *handle, const <a href="formatbuffersetting.md">FormatBufferSetting</a> *setting)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p846887256165623"><a name="p846887256165623"></a><a name="p846887256165623"></a>int32_t </p>
<p id="p2017650404165623"><a name="p2017650404165623"></a><a name="p2017650404165623"></a>Sets buffer information for the demuxer. </p>
</td>
</tr>
<tr id="row521682762165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1447912952165623"><a name="p1447912952165623"></a><a name="p1447912952165623"></a><a href="format.md#ga565cbb52c95a95aab4dcc957fe998b5f">FormatDemuxerGetBufferConfig</a> (const void *handle, <a href="formatbuffersetting.md">FormatBufferSetting</a> *setting)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2085886825165623"><a name="p2085886825165623"></a><a name="p2085886825165623"></a>int32_t </p>
<p id="p1893284010165623"><a name="p1893284010165623"></a><a name="p1893284010165623"></a>Obtains the buffer information of the demuxer. </p>
</td>
</tr>
<tr id="row69748648165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1341824415165623"><a name="p1341824415165623"></a><a name="p1341824415165623"></a><a href="format.md#gacfcf40d869a48125bd67d17f8a4fc3ce">FormatDemuxerPrepare</a> (void *handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1559228308165623"><a name="p1559228308165623"></a><a name="p1559228308165623"></a>int32_t </p>
<p id="p74895411165623"><a name="p74895411165623"></a><a name="p74895411165623"></a>Makes preparations for the demuxer. </p>
</td>
</tr>
<tr id="row313550628165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1411842222165623"><a name="p1411842222165623"></a><a name="p1411842222165623"></a><a href="format.md#gad807d61c65e89629c7eed8f97426fd5a">FormatDemuxerGetFileInfo</a> (void *handle, <a href="fileinfo.md">FileInfo</a> *info)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p658152068165623"><a name="p658152068165623"></a><a name="p658152068165623"></a>int32_t </p>
<p id="p1382807930165623"><a name="p1382807930165623"></a><a name="p1382807930165623"></a>Obtains the attributes of a media file. </p>
</td>
</tr>
<tr id="row1714377447165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p763406904165623"><a name="p763406904165623"></a><a name="p763406904165623"></a><a href="format.md#ga1d9cb94614e207def34f13eaa16ef2b7">FormatDemuxerSelectTrack</a> (const void *handle, int32_t programId, int32_t trackId)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1603822183165623"><a name="p1603822183165623"></a><a name="p1603822183165623"></a>int32_t </p>
<p id="p1816766834165623"><a name="p1816766834165623"></a><a name="p1816766834165623"></a>Selects a specified media track. </p>
</td>
</tr>
<tr id="row379064837165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2126768572165623"><a name="p2126768572165623"></a><a name="p2126768572165623"></a><a href="format.md#gaf5fd5bab9613d133827054f157d5520e">FormatDemuxerUnselectTrack</a> (const void *handle, int32_t programId, int32_t trackId)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p831593918165623"><a name="p831593918165623"></a><a name="p831593918165623"></a>int32_t </p>
<p id="p1638167675165623"><a name="p1638167675165623"></a><a name="p1638167675165623"></a>Unselects a specified media track from which the demuxer reads data frames. </p>
</td>
</tr>
<tr id="row1728457774165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p747718419165623"><a name="p747718419165623"></a><a name="p747718419165623"></a><a href="format.md#ga08544b1ba3373bf5cb211586e8195673">FormatDemuxerStart</a> (void *handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p472919004165623"><a name="p472919004165623"></a><a name="p472919004165623"></a>int32_t </p>
<p id="p2065128431165623"><a name="p2065128431165623"></a><a name="p2065128431165623"></a>Starts the demuxer. </p>
</td>
</tr>
<tr id="row1236456457165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p745418417165623"><a name="p745418417165623"></a><a name="p745418417165623"></a><a href="format.md#gab6ef68051ee2ed0015e721bedb1af61c">FormatDemuxerGetSelectedTrack</a> (const void *handle, int32_t *programId, int32_t trackId[], int32_t *nums)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p914495799165623"><a name="p914495799165623"></a><a name="p914495799165623"></a>int32_t </p>
<p id="p1922062147165623"><a name="p1922062147165623"></a><a name="p1922062147165623"></a>Obtains the ID of the media track selected by the demuxer for output. </p>
</td>
</tr>
<tr id="row1601749423165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1575282067165623"><a name="p1575282067165623"></a><a name="p1575282067165623"></a><a href="format.md#ga7b20e1b88413d20a348d7f796917cd94">FormatDemuxerReadFrame</a> (const void *handle, <a href="formatframe.md">FormatFrame</a> *frame, int32_t timeOutMs)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p667962426165623"><a name="p667962426165623"></a><a name="p667962426165623"></a>int32_t </p>
<p id="p1442261924165623"><a name="p1442261924165623"></a><a name="p1442261924165623"></a>Reads data frames. </p>
</td>
</tr>
<tr id="row772272457165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2031338687165623"><a name="p2031338687165623"></a><a name="p2031338687165623"></a><a href="format.md#ga291b805de194c695b72eb5ad721103d5">FormatDemuxerFreeFrame</a> (void *handle, <a href="formatframe.md">FormatFrame</a> *frame)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p996974448165623"><a name="p996974448165623"></a><a name="p996974448165623"></a>int32_t </p>
<p id="p1907162268165623"><a name="p1907162268165623"></a><a name="p1907162268165623"></a>Frees data frames. </p>
</td>
</tr>
<tr id="row1275034819165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1766327035165623"><a name="p1766327035165623"></a><a name="p1766327035165623"></a><a href="format.md#gad53f1e848f3c2e0c8fa056a312b2ed6c">FormatDemuxerSeek</a> (const void *handle, int32_t streamIndex, int64_t timeStampUs, <a href="format.md#ga14aa9d18a71eff4a0b70f748f0377c94">FormatSeekMode</a> mode)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1882035686165623"><a name="p1882035686165623"></a><a name="p1882035686165623"></a>int32_t </p>
<p id="p737680748165623"><a name="p737680748165623"></a><a name="p737680748165623"></a>Seeks for a specified position for the demuxer. </p>
</td>
</tr>
<tr id="row9269540165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1751032276165623"><a name="p1751032276165623"></a><a name="p1751032276165623"></a><a href="format.md#ga8a693d8be0b4b688d99e513608884e91">FormatDemuxerStop</a> (void *handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1617633495165623"><a name="p1617633495165623"></a><a name="p1617633495165623"></a>int32_t </p>
<p id="p556139307165623"><a name="p556139307165623"></a><a name="p556139307165623"></a>Stops the demuxer from working. </p>
</td>
</tr>
<tr id="row1925435068165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1102255907165623"><a name="p1102255907165623"></a><a name="p1102255907165623"></a><a href="format.md#ga98fd9a5a5d1ffd275fc46f898ca08413">FormatDemuxerDestory</a> (void *handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p535994976165623"><a name="p535994976165623"></a><a name="p535994976165623"></a>int32_t </p>
<p id="p1106155159165623"><a name="p1106155159165623"></a><a name="p1106155159165623"></a>Destroys demuxer resources. </p>
</td>
</tr>
<tr id="row1309026237165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1834163810165623"><a name="p1834163810165623"></a><a name="p1834163810165623"></a><a href="format.md#ga9c390276cb90f4753c32af5aa5c600ad">FormatMuxerCreate</a> (void **handle, <a href="formatoutputconfig.md">FormatOutputConfig</a> *outputConfig)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1944811923165623"><a name="p1944811923165623"></a><a name="p1944811923165623"></a>int32_t </p>
<p id="p1538548047165623"><a name="p1538548047165623"></a><a name="p1538548047165623"></a>Creates a muxer and returns its context handle. </p>
</td>
</tr>
<tr id="row2039848350165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1212073261165623"><a name="p1212073261165623"></a><a name="p1212073261165623"></a><a href="format.md#gaa41d46cef6d5e81c85614edbf824d803">FormatMuxerDestory</a> (const void *handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1470332722165623"><a name="p1470332722165623"></a><a name="p1470332722165623"></a>int32_t </p>
<p id="p1625239268165623"><a name="p1625239268165623"></a><a name="p1625239268165623"></a>Destroys a muxer and release its resources created by calling <a href="format.md#ga9c390276cb90f4753c32af5aa5c600ad">FormatMuxerCreate</a>. </p>
</td>
</tr>
<tr id="row734417748165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1010298774165623"><a name="p1010298774165623"></a><a name="p1010298774165623"></a><a href="format.md#ga94e9ab3e534b69a358b7cc16e4f79b78">FormatMuxerAddTrack</a> (void *handle, const <a href="tracksource.md">TrackSource</a> *trackSource)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p255395739165623"><a name="p255395739165623"></a><a name="p255395739165623"></a>int32_t </p>
<p id="p438058823165623"><a name="p438058823165623"></a><a name="p438058823165623"></a>Adds a media track source for the muxer. For details about track sources, see <a href="tracksource.md">TrackSource</a>. </p>
</td>
</tr>
<tr id="row2088898752165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p679738753165623"><a name="p679738753165623"></a><a name="p679738753165623"></a><a href="format.md#ga108cd7e319ade568f71890d57585f153">FormatMuxerSetCallBack</a> (void *handle, const <a href="formatcallback.md">FormatCallback</a> *callBack)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1992679820165623"><a name="p1992679820165623"></a><a name="p1992679820165623"></a>int32_t </p>
<p id="p386759818165623"><a name="p386759818165623"></a><a name="p386759818165623"></a>Sets a callback for the muxer. For details about the callback, see <a href="formatcallback.md">FormatCallback</a>. </p>
</td>
</tr>
<tr id="row837241182165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p311005994165623"><a name="p311005994165623"></a><a name="p311005994165623"></a><a href="format.md#ga96fc57913c3202d2d23704c69d660be5">FormatMuxerSetOrientation</a> (void *handle, int degrees)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p682540213165623"><a name="p682540213165623"></a><a name="p682540213165623"></a>int32_t </p>
<p id="p2080996877165623"><a name="p2080996877165623"></a><a name="p2080996877165623"></a>Sets the orientation of the video track for the muxer. </p>
</td>
</tr>
<tr id="row525208949165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p810706744165623"><a name="p810706744165623"></a><a name="p810706744165623"></a><a href="format.md#ga967ba14fa1231eed2942b87a09deb953">FormatMuxerSetLocation</a> (const void *handle, int latitude, int longitude)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1501911472165623"><a name="p1501911472165623"></a><a name="p1501911472165623"></a>int32_t </p>
<p id="p1884826551165623"><a name="p1884826551165623"></a><a name="p1884826551165623"></a>Sets the geographical information for the output file of the muxer. </p>
</td>
</tr>
<tr id="row854391280165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p876895107165623"><a name="p876895107165623"></a><a name="p876895107165623"></a><a href="format.md#ga6f3ba422c9bbca4c1d5a7a3fe85dd9b9">FormatMuxerSetMaxFileSize</a> (void *handle, int64_t bytes)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p670089933165623"><a name="p670089933165623"></a><a name="p670089933165623"></a>int32_t </p>
<p id="p2026362138165623"><a name="p2026362138165623"></a><a name="p2026362138165623"></a>Sets the maximum size (in bytes) for the output file of the muxer. </p>
</td>
</tr>
<tr id="row686499665165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p609055196165623"><a name="p609055196165623"></a><a name="p609055196165623"></a><a href="format.md#gae931061d822c4ffe447e9ba40a991597">FormatMuxerSetMaxFileDuration</a> (void *handle, int64_t durationUs)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p595208781165623"><a name="p595208781165623"></a><a name="p595208781165623"></a>int32_t </p>
<p id="p813166693165623"><a name="p813166693165623"></a><a name="p813166693165623"></a>Sets the maximum duration (in seconds) for the output file. </p>
</td>
</tr>
<tr id="row521304747165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1631054359165623"><a name="p1631054359165623"></a><a name="p1631054359165623"></a><a href="format.md#ga6eed6b5e7522e102f2d79d0dd33fd2a9">FormatMuxerSetFileSplitDuration</a> (const void *handle, <a href="format.md#ga10d9833450f29129d249c41d9acb4bc4">ManualSplitType</a> type, int64_t timestampUs, uint32_t durationUs)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1382263737165623"><a name="p1382263737165623"></a><a name="p1382263737165623"></a>int32_t </p>
<p id="p931770097165623"><a name="p931770097165623"></a><a name="p931770097165623"></a>Manually splits a file. </p>
</td>
</tr>
<tr id="row337527041165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1607739310165623"><a name="p1607739310165623"></a><a name="p1607739310165623"></a><a href="format.md#ga9a2af831a6f4a63dc85d2c23b5c7c81b">FormatMuxerStart</a> (void *handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p282320124165623"><a name="p282320124165623"></a><a name="p282320124165623"></a>int32_t </p>
<p id="p1431121901165623"><a name="p1431121901165623"></a><a name="p1431121901165623"></a>Starts the muxer. </p>
</td>
</tr>
<tr id="row1868421595165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p293093368165623"><a name="p293093368165623"></a><a name="p293093368165623"></a><a href="format.md#ga82037d271e77da206e16582e774ee048">FormatMuxerWriteFrame</a> (const void *handle, const <a href="formatframe.md">FormatFrame</a> *frameData)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2122943427165623"><a name="p2122943427165623"></a><a name="p2122943427165623"></a>int32_t </p>
<p id="p2109516850165623"><a name="p2109516850165623"></a><a name="p2109516850165623"></a>Writes data frames into the muxer. </p>
</td>
</tr>
<tr id="row1978609186165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1460454019165623"><a name="p1460454019165623"></a><a name="p1460454019165623"></a><a href="format.md#gaa936b56996294d76977537267fef058c">FormatMuxerSetNextOutputFile</a> (const void *handle, int32_t fd)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p246763512165623"><a name="p246763512165623"></a><a name="p246763512165623"></a>int32_t </p>
<p id="p1812164582165623"><a name="p1812164582165623"></a><a name="p1812164582165623"></a>Sets the descriptor for the next output file. </p>
</td>
</tr>
<tr id="row982187776165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1716274908165623"><a name="p1716274908165623"></a><a name="p1716274908165623"></a><a href="format.md#ga66a3a5a1ec6d01fcbd6339f7eee1151b">FormatMuxerStop</a> (const void *handle, bool block)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p923634305165623"><a name="p923634305165623"></a><a name="p923634305165623"></a>int32_t </p>
<p id="p652827748165623"><a name="p652827748165623"></a><a name="p652827748165623"></a>Stops the muxer that was started by calling <a href="format.md#ga9a2af831a6f4a63dc85d2c23b5c7c81b">FormatMuxerStart</a>. </p>
</td>
</tr>
<tr id="row344101853165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p541516812165623"><a name="p541516812165623"></a><a name="p541516812165623"></a><a href="format.md#gad4335ebaa7c165b885a00fe61aae0cd9">FormatMuxerSetParameter</a> (void *handle, int32_t trackId, const <a href="parameteritem.md">ParameterItem</a> *item, int32_t itemNum)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1468446702165623"><a name="p1468446702165623"></a><a name="p1468446702165623"></a>int32_t </p>
<p id="p110418830165623"><a name="p110418830165623"></a><a name="p110418830165623"></a>Sets muxer attributes. </p>
</td>
</tr>
<tr id="row29289391165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p750579548165623"><a name="p750579548165623"></a><a name="p750579548165623"></a><a href="format.md#ga67dd7361dedf335496afef19d54e4138">FormatMuxerGetParameter</a> (void *handle, int32_t trackId, <a href="parameteritem.md">ParameterItem</a> *item, int32_t itemNum)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p245615988165623"><a name="p245615988165623"></a><a name="p245615988165623"></a>int32_t </p>
<p id="p1667325243165623"><a name="p1667325243165623"></a><a name="p1667325243165623"></a>Obtains muxer attributes. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1693197691165623"></a>

## **Macro Definition **<a name="section935031532165623"></a>

## FORMAT\_INVALID\_PROGRAM\_ID<a name="gab4007b017f1edad143959af034e32bf7"></a>

```
#define FORMAT_INVALID_PROGRAM_ID   -1
```

 **Description:**

Indicates an invalid program ID. 

## FORMAT\_INVALID\_TRACK\_ID<a name="ga62037bb16334896e1bb6d35a71618881"></a>

```
#define FORMAT_INVALID_TRACK_ID   -1
```

 **Description:**

Indicates an invalid track ID. 

## FORMAT\_LANGUAGE\_LEN<a name="gaa70508bb1089c99f9aa3d59fcbdfa8eb"></a>

```
#define FORMAT_LANGUAGE_LEN   4
```

 **Description:**

Indicates the number of characters contained in the language description. 

## FORMAT\_MAX\_LANGUAGE\_NUM<a name="gac2d2d077edb8e9bb9f85ab6350015c5b"></a>

```
#define FORMAT_MAX_LANGUAGE_NUM   4
```

 **Description:**

Indicates the number of languages in the subtitle file. 

## FORMAT\_TITLE\_LEN<a name="gadb635fac84a9d62e99c69e75d4de85c3"></a>

```
#define FORMAT_TITLE_LEN   64
```

 **Description:**

Indicates the number of title characters. 

## URL\_LEN<a name="ga1ac54dd3b9b49c1800b5f502a87650be"></a>

```
#define URL_LEN   4096
```

 **Description:**

Indicates the URL length. 

## **Typedef **<a name="section545940743165623"></a>

## CALLBACK\_HANDLE<a name="gab928f39c359734527bda3fd160f89331"></a>

```
typedef void* [CALLBACK_HANDLE](format.md#gab928f39c359734527bda3fd160f89331)
```

 **Description:**

Indicates the pointer to the callback handle for listening the muxer. 

## **Enumeration Type **<a name="section1904403459165623"></a>

## AudioSampleFmt<a name="gadf0700999998f587f0017c4d02977b22"></a>

```
enum [AudioSampleFmt](format.md#gadf0700999998f587f0017c4d02977b22)
```

 **Description:**

Enumerates audio sampling formats. 

<a name="table1703266305165623"></a>
<table><thead align="left"><tr id="row712431680165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p706648843165623"><a name="p706648843165623"></a><a name="p706648843165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1642221585165623"><a name="p1642221585165623"></a><a name="p1642221585165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1619370400165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggadf0700999998f587f0017c4d02977b22a650b7f83085e55b6e728fd3ec5beec50"><a name="ggadf0700999998f587f0017c4d02977b22a650b7f83085e55b6e728fd3ec5beec50"></a><a name="ggadf0700999998f587f0017c4d02977b22a650b7f83085e55b6e728fd3ec5beec50"></a></strong>AUDIO_SAMPLE_FMT_S8 </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p433891978165623"><a name="p433891978165623"></a><a name="p433891978165623"></a>8-bit integer for a single sample </p>
 </td>
</tr>
<tr id="row1636732632165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggadf0700999998f587f0017c4d02977b22a40335eaa7ca378540941909ed02b51a0"><a name="ggadf0700999998f587f0017c4d02977b22a40335eaa7ca378540941909ed02b51a0"></a><a name="ggadf0700999998f587f0017c4d02977b22a40335eaa7ca378540941909ed02b51a0"></a></strong>AUDIO_SAMPLE_FMT_S16 </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1720003503165623"><a name="p1720003503165623"></a><a name="p1720003503165623"></a>16-bit integer for a single sample </p>
 </td>
</tr>
<tr id="row1760314876165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggadf0700999998f587f0017c4d02977b22af55ab2a69453af86f0c1602d3645f5f9"><a name="ggadf0700999998f587f0017c4d02977b22af55ab2a69453af86f0c1602d3645f5f9"></a><a name="ggadf0700999998f587f0017c4d02977b22af55ab2a69453af86f0c1602d3645f5f9"></a></strong>AUDIO_SAMPLE_FMT_S24 </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2088509496165623"><a name="p2088509496165623"></a><a name="p2088509496165623"></a>24-bit integer for a single sample </p>
 </td>
</tr>
<tr id="row318430599165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggadf0700999998f587f0017c4d02977b22ab98feafb8396c0190a4fb719a15ab7c5"><a name="ggadf0700999998f587f0017c4d02977b22ab98feafb8396c0190a4fb719a15ab7c5"></a><a name="ggadf0700999998f587f0017c4d02977b22ab98feafb8396c0190a4fb719a15ab7c5"></a></strong>AUDIO_SAMPLE_FMT_S32 </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1692251660165623"><a name="p1692251660165623"></a><a name="p1692251660165623"></a>32-bit integer for a single sample </p>
 </td>
</tr>
<tr id="row2111774906165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggadf0700999998f587f0017c4d02977b22ac2fb27a42b3f79e51dd71ce05b42f9db"><a name="ggadf0700999998f587f0017c4d02977b22ac2fb27a42b3f79e51dd71ce05b42f9db"></a><a name="ggadf0700999998f587f0017c4d02977b22ac2fb27a42b3f79e51dd71ce05b42f9db"></a></strong>AUDIO_SAMPLE_FMT_FLOAT </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p667541825165623"><a name="p667541825165623"></a><a name="p667541825165623"></a>Single-precision floating point number for a single sample </p>
 </td>
</tr>
</tbody>
</table>

## CodecFormat<a name="gaf7ed135f15d4b218d41705bac0122ba7"></a>

```
enum [CodecFormat](format.md#gaf7ed135f15d4b218d41705bac0122ba7)
```

 **Description:**

Enumerates audio, video, and image encoding formats. 

<a name="table945099217165623"></a>
<table><thead align="left"><tr id="row1547089884165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1228203636165623"><a name="p1228203636165623"></a><a name="p1228203636165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1937223491165623"><a name="p1937223491165623"></a><a name="p1937223491165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2052915370165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaf7ed135f15d4b218d41705bac0122ba7aa0c89a6d185559b38e63265976dde7f4"><a name="ggaf7ed135f15d4b218d41705bac0122ba7aa0c89a6d185559b38e63265976dde7f4"></a><a name="ggaf7ed135f15d4b218d41705bac0122ba7aa0c89a6d185559b38e63265976dde7f4"></a></strong>CODEC_H264 </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1282264787165623"><a name="p1282264787165623"></a><a name="p1282264787165623"></a>H264 or AVC </p>
 </td>
</tr>
<tr id="row91235951165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaf7ed135f15d4b218d41705bac0122ba7a4adc0c5e441be1b1a642f481e3111cae"><a name="ggaf7ed135f15d4b218d41705bac0122ba7a4adc0c5e441be1b1a642f481e3111cae"></a><a name="ggaf7ed135f15d4b218d41705bac0122ba7a4adc0c5e441be1b1a642f481e3111cae"></a></strong>CODEC_H265 </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1795421317165623"><a name="p1795421317165623"></a><a name="p1795421317165623"></a>H265 or HEVC </p>
 </td>
</tr>
<tr id="row1448883496165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaf7ed135f15d4b218d41705bac0122ba7ab6432cb3fb17152277af1f486e182612"><a name="ggaf7ed135f15d4b218d41705bac0122ba7ab6432cb3fb17152277af1f486e182612"></a><a name="ggaf7ed135f15d4b218d41705bac0122ba7ab6432cb3fb17152277af1f486e182612"></a></strong>CODEC_JPEG </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1476376587165623"><a name="p1476376587165623"></a><a name="p1476376587165623"></a>JPEG </p>
 </td>
</tr>
<tr id="row2015631058165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaf7ed135f15d4b218d41705bac0122ba7a8a0888876671d503c2c5e15059461c06"><a name="ggaf7ed135f15d4b218d41705bac0122ba7a8a0888876671d503c2c5e15059461c06"></a><a name="ggaf7ed135f15d4b218d41705bac0122ba7a8a0888876671d503c2c5e15059461c06"></a></strong>CODEC_AAC </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1219580702165623"><a name="p1219580702165623"></a><a name="p1219580702165623"></a>AAC </p>
 </td>
</tr>
<tr id="row549940364165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaf7ed135f15d4b218d41705bac0122ba7a44fd5227148450a7870e202d50110509"><a name="ggaf7ed135f15d4b218d41705bac0122ba7a44fd5227148450a7870e202d50110509"></a><a name="ggaf7ed135f15d4b218d41705bac0122ba7a44fd5227148450a7870e202d50110509"></a></strong>CODEC_G711A </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p968507008165623"><a name="p968507008165623"></a><a name="p968507008165623"></a>G711A </p>
 </td>
</tr>
<tr id="row828836482165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaf7ed135f15d4b218d41705bac0122ba7a3ac447dc6b8707c70f6fc6d4e0c552d5"><a name="ggaf7ed135f15d4b218d41705bac0122ba7a3ac447dc6b8707c70f6fc6d4e0c552d5"></a><a name="ggaf7ed135f15d4b218d41705bac0122ba7a3ac447dc6b8707c70f6fc6d4e0c552d5"></a></strong>CODEC_G711U </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1617263756165623"><a name="p1617263756165623"></a><a name="p1617263756165623"></a>G711u </p>
 </td>
</tr>
<tr id="row1088885335165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaf7ed135f15d4b218d41705bac0122ba7ae3014fa1161193bc92227ea0895e1dfb"><a name="ggaf7ed135f15d4b218d41705bac0122ba7ae3014fa1161193bc92227ea0895e1dfb"></a><a name="ggaf7ed135f15d4b218d41705bac0122ba7ae3014fa1161193bc92227ea0895e1dfb"></a></strong>CODEC_PCM </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p125805214165623"><a name="p125805214165623"></a><a name="p125805214165623"></a>PCM </p>
 </td>
</tr>
<tr id="row193571630165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaf7ed135f15d4b218d41705bac0122ba7a2a0119a66bcbe797c1bac3057a802c9a"><a name="ggaf7ed135f15d4b218d41705bac0122ba7a2a0119a66bcbe797c1bac3057a802c9a"></a><a name="ggaf7ed135f15d4b218d41705bac0122ba7a2a0119a66bcbe797c1bac3057a802c9a"></a></strong>CODEC_MP3 </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1818980206165623"><a name="p1818980206165623"></a><a name="p1818980206165623"></a>MP3 </p>
 </td>
</tr>
<tr id="row384657248165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaf7ed135f15d4b218d41705bac0122ba7a0bccf3a2f309d8c485283d386322f07b"><a name="ggaf7ed135f15d4b218d41705bac0122ba7a0bccf3a2f309d8c485283d386322f07b"></a><a name="ggaf7ed135f15d4b218d41705bac0122ba7a0bccf3a2f309d8c485283d386322f07b"></a></strong>CODEC_BUT </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p61204984165623"><a name="p61204984165623"></a><a name="p61204984165623"></a>Undefined format </p>
 </td>
</tr>
</tbody>
</table>

## DataFlags<a name="gacff079fdf8427c743f9197ea5be33a7f"></a>

```
enum [DataFlags](format.md#gacff079fdf8427c743f9197ea5be33a7f)
```

 **Description:**

Enumerates flags of raw stream data. 

<a name="table738061832165623"></a>
<table><thead align="left"><tr id="row313345316165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1927435491165623"><a name="p1927435491165623"></a><a name="p1927435491165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p596472070165623"><a name="p596472070165623"></a><a name="p596472070165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1555166517165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggacff079fdf8427c743f9197ea5be33a7faf5d58e6ec118e0660b53c7a7df2fdc8b"><a name="ggacff079fdf8427c743f9197ea5be33a7faf5d58e6ec118e0660b53c7a7df2fdc8b"></a><a name="ggacff079fdf8427c743f9197ea5be33a7faf5d58e6ec118e0660b53c7a7df2fdc8b"></a></strong>DATA_FLAG_NONE </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p759398453165623"><a name="p759398453165623"></a><a name="p759398453165623"></a>None </p>
 </td>
</tr>
<tr id="row650509809165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggacff079fdf8427c743f9197ea5be33a7fad000cf60ee0b16f1ea7fedbcdb1a9fa0"><a name="ggacff079fdf8427c743f9197ea5be33a7fad000cf60ee0b16f1ea7fedbcdb1a9fa0"></a><a name="ggacff079fdf8427c743f9197ea5be33a7fad000cf60ee0b16f1ea7fedbcdb1a9fa0"></a></strong>DATA_FLAG_SYNCFRAME </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1166358591165623"><a name="p1166358591165623"></a><a name="p1166358591165623"></a>Synchronization frame </p>
 </td>
</tr>
<tr id="row515307513165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggacff079fdf8427c743f9197ea5be33a7fa9200ae4b5fc3c72f2e70c9a49c2ebbb0"><a name="ggacff079fdf8427c743f9197ea5be33a7fa9200ae4b5fc3c72f2e70c9a49c2ebbb0"></a><a name="ggacff079fdf8427c743f9197ea5be33a7fa9200ae4b5fc3c72f2e70c9a49c2ebbb0"></a></strong>DATA_FLAG_CODECCONFIG </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1346569451165623"><a name="p1346569451165623"></a><a name="p1346569451165623"></a>Codec configuration information </p>
 </td>
</tr>
<tr id="row1760631798165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggacff079fdf8427c743f9197ea5be33a7fabaa169afc64ef32b743217c8194fd8b9"><a name="ggacff079fdf8427c743f9197ea5be33a7fabaa169afc64ef32b743217c8194fd8b9"></a><a name="ggacff079fdf8427c743f9197ea5be33a7fabaa169afc64ef32b743217c8194fd8b9"></a></strong>DATA_FLAG_EOS </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1333772654165623"><a name="p1333772654165623"></a><a name="p1333772654165623"></a>End of a single stream </p>
 </td>
</tr>
<tr id="row1438209577165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggacff079fdf8427c743f9197ea5be33a7fa26019220bb1298308f5c3dcd8a071f63"><a name="ggacff079fdf8427c743f9197ea5be33a7fa26019220bb1298308f5c3dcd8a071f63"></a><a name="ggacff079fdf8427c743f9197ea5be33a7fa26019220bb1298308f5c3dcd8a071f63"></a></strong>DATA_FLAG_PARTIAL_FRAME </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p267511716165623"><a name="p267511716165623"></a><a name="p267511716165623"></a>Partial synchronization frame. This flag is used for multiple segments (except for the last one) into which a single frame is divided. </p>
 </td>
</tr>
<tr id="row605006358165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggacff079fdf8427c743f9197ea5be33a7fa5fd5b55061c6e94a8a12f9cf9d2009a7"><a name="ggacff079fdf8427c743f9197ea5be33a7fa5fd5b55061c6e94a8a12f9cf9d2009a7"></a><a name="ggacff079fdf8427c743f9197ea5be33a7fa5fd5b55061c6e94a8a12f9cf9d2009a7"></a></strong>DATA_FLAG_ENDOFFRAME </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p196131825165623"><a name="p196131825165623"></a><a name="p196131825165623"></a>End of a frame. This flag is used in pair with <strong id="b1611574337165623"><a name="b1611574337165623"></a><a name="b1611574337165623"></a>DATA_FLAG_PARTIAL_FRAME</strong> for the last segment of the frame. </p>
 </td>
</tr>
<tr id="row788269549165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggacff079fdf8427c743f9197ea5be33a7faeb92d052f544e6cde910fb669790a804"><a name="ggacff079fdf8427c743f9197ea5be33a7faeb92d052f544e6cde910fb669790a804"></a><a name="ggacff079fdf8427c743f9197ea5be33a7faeb92d052f544e6cde910fb669790a804"></a></strong>DATA_FLAG_MUXER_DATA </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1003339918165623"><a name="p1003339918165623"></a><a name="p1003339918165623"></a>Encapsulated data with its container </p>
 </td>
</tr>
</tbody>
</table>

## FormatErrorType<a name="ga31e7fcf42722fa15e4e5489c2fef9092"></a>

```
enum [FormatErrorType](format.md#ga31e7fcf42722fa15e4e5489c2fef9092)
```

 **Description:**

Enumerates callback error types. 

## FormatInfoType<a name="ga6f00342925d3d5e586c76f8695985cad"></a>

```
enum [FormatInfoType](format.md#ga6f00342925d3d5e586c76f8695985cad)
```

 **Description:**

Enumerates types of callback information. 

<a name="table1510548243165623"></a>
<table><thead align="left"><tr id="row1322766515165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p266206557165623"><a name="p266206557165623"></a><a name="p266206557165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2013805044165623"><a name="p2013805044165623"></a><a name="p2013805044165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2027379670165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga6f00342925d3d5e586c76f8695985cadaf6214216fd62faa4fc5e20d0d0ba60bf"><a name="gga6f00342925d3d5e586c76f8695985cadaf6214216fd62faa4fc5e20d0d0ba60bf"></a><a name="gga6f00342925d3d5e586c76f8695985cadaf6214216fd62faa4fc5e20d0d0ba60bf"></a></strong>MUXER_INFO_MAX_DURATION_APPROACHING </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1506055805165623"><a name="p1506055805165623"></a><a name="p1506055805165623"></a>The capturing duration is reaching the threshold specified by <a href="format.md#gae931061d822c4ffe447e9ba40a991597">FormatMuxerSetMaxFileDuration</a>. This information is reported when only one second or 10% is left to reach the allowed duration. </p>
 </td>
</tr>
<tr id="row800762250165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga6f00342925d3d5e586c76f8695985cadafc74f41e73f13a29a83b3a13ea6e66e1"><a name="gga6f00342925d3d5e586c76f8695985cadafc74f41e73f13a29a83b3a13ea6e66e1"></a><a name="gga6f00342925d3d5e586c76f8695985cadafc74f41e73f13a29a83b3a13ea6e66e1"></a></strong>MUXER_INFO_MAX_FILESIZE_APPROACHING </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p873066120165623"><a name="p873066120165623"></a><a name="p873066120165623"></a>The captured file size is reaching the threshold specified by <a href="format.md#ga6f3ba422c9bbca4c1d5a7a3fe85dd9b9">FormatMuxerSetMaxFileSize</a>. This information is reported when only 100 KB or 10% is left to reach the allowed size. </p>
 </td>
</tr>
<tr id="row8164819165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga6f00342925d3d5e586c76f8695985cada9722ce52063f6247d5fb17470eb9559e"><a name="gga6f00342925d3d5e586c76f8695985cada9722ce52063f6247d5fb17470eb9559e"></a><a name="gga6f00342925d3d5e586c76f8695985cada9722ce52063f6247d5fb17470eb9559e"></a></strong>MUXER_INFO_MAX_DURATION_REACHED </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p464163753165623"><a name="p464163753165623"></a><a name="p464163753165623"></a>The capturing duration reached the threshold specified by <a href="format.md#gae931061d822c4ffe447e9ba40a991597">FormatMuxerSetMaxFileDuration</a>, and the capturing is ended. If the file is set by a file descriptor, the caller needs to close the file. </p>
 </td>
</tr>
<tr id="row392377608165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga6f00342925d3d5e586c76f8695985cada71704a053cf3e30c7bf91522b27da8c2"><a name="gga6f00342925d3d5e586c76f8695985cada71704a053cf3e30c7bf91522b27da8c2"></a><a name="gga6f00342925d3d5e586c76f8695985cada71704a053cf3e30c7bf91522b27da8c2"></a></strong>MUXER_INFO_MAX_FILESIZE_REACHED </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p368902342165623"><a name="p368902342165623"></a><a name="p368902342165623"></a>The captured file size reached the threshold specified by <a href="format.md#ga6f3ba422c9bbca4c1d5a7a3fe85dd9b9">FormatMuxerSetMaxFileSize</a>, and the capturing is ended. If the file is set by a file descriptor, the caller needs to close the file. </p>
 </td>
</tr>
<tr id="row1727706372165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga6f00342925d3d5e586c76f8695985cadae63cbc02cf7dc61073b739c08cc58ff4"><a name="gga6f00342925d3d5e586c76f8695985cadae63cbc02cf7dc61073b739c08cc58ff4"></a><a name="gga6f00342925d3d5e586c76f8695985cadae63cbc02cf7dc61073b739c08cc58ff4"></a></strong>MUXER_INFO_NEXT_OUTPUT_FILE_STARTED </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p818428253165623"><a name="p818428253165623"></a><a name="p818428253165623"></a>The capturing started for the next output file. </p>
 </td>
</tr>
<tr id="row427412989165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga6f00342925d3d5e586c76f8695985cada3cf56a06f5990ab657d61bd7e57c1783"><a name="gga6f00342925d3d5e586c76f8695985cada3cf56a06f5990ab657d61bd7e57c1783"></a><a name="gga6f00342925d3d5e586c76f8695985cada3cf56a06f5990ab657d61bd7e57c1783"></a></strong>MUXER_INFO_FILE_SPLIT_FINISHED </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p587813264165623"><a name="p587813264165623"></a><a name="p587813264165623"></a>Manual file split is completed. </p>
 </td>
</tr>
<tr id="row2059981954165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga6f00342925d3d5e586c76f8695985cada5d3901c368e7a4f719134c98c4fa8313"><a name="gga6f00342925d3d5e586c76f8695985cada5d3901c368e7a4f719134c98c4fa8313"></a><a name="gga6f00342925d3d5e586c76f8695985cada5d3901c368e7a4f719134c98c4fa8313"></a></strong>MUXER_INFO_FILE_START_TIME_MS </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1236467561165623"><a name="p1236467561165623"></a><a name="p1236467561165623"></a>Start time of the captured file </p>
 </td>
</tr>
<tr id="row1030424811165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga6f00342925d3d5e586c76f8695985cadaeb00ffb6342b7ede6b5efe81fa842374"><a name="gga6f00342925d3d5e586c76f8695985cadaeb00ffb6342b7ede6b5efe81fa842374"></a><a name="gga6f00342925d3d5e586c76f8695985cadaeb00ffb6342b7ede6b5efe81fa842374"></a></strong>DEMUXER_INFO_PREPARED </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2032732170165623"><a name="p2032732170165623"></a><a name="p2032732170165623"></a>The prepare function is asynchronously executed. This information is reported after the execution is complete. </p>
 </td>
</tr>
<tr id="row1003740705165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga6f00342925d3d5e586c76f8695985cada929a71c6b58dfcd974e960b99139a758"><a name="gga6f00342925d3d5e586c76f8695985cada929a71c6b58dfcd974e960b99139a758"></a><a name="gga6f00342925d3d5e586c76f8695985cada929a71c6b58dfcd974e960b99139a758"></a></strong>DEMUXER_INFO_SEEK_COMPLETE </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1614671620165623"><a name="p1614671620165623"></a><a name="p1614671620165623"></a>The seek function is asynchronously executed. This information is reported after the execution is complete. </p>
 </td>
</tr>
<tr id="row1727440927165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga6f00342925d3d5e586c76f8695985cada2c4b1c086d55b4d5bf3fedbbf115cf63"><a name="gga6f00342925d3d5e586c76f8695985cada2c4b1c086d55b4d5bf3fedbbf115cf63"></a><a name="gga6f00342925d3d5e586c76f8695985cada2c4b1c086d55b4d5bf3fedbbf115cf63"></a></strong>DEMUXER_INFO_NETWORK_DISCONNECTED </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p620302704165623"><a name="p620302704165623"></a><a name="p620302704165623"></a>The network is disconnected during network playback. </p>
 </td>
</tr>
<tr id="row1864773448165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga6f00342925d3d5e586c76f8695985cadac157e535a1828f3b87c9cc3e6fd8773b"><a name="gga6f00342925d3d5e586c76f8695985cadac157e535a1828f3b87c9cc3e6fd8773b"></a><a name="gga6f00342925d3d5e586c76f8695985cadac157e535a1828f3b87c9cc3e6fd8773b"></a></strong>DEMUXER_INFO_NETWORK_RECONNECTED </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1729100787165623"><a name="p1729100787165623"></a><a name="p1729100787165623"></a>The network is automatically reconnected during network playback. </p>
 </td>
</tr>
</tbody>
</table>

## FormatSeekMode<a name="ga14aa9d18a71eff4a0b70f748f0377c94"></a>

```
enum [FormatSeekMode](format.md#ga14aa9d18a71eff4a0b70f748f0377c94)
```

 **Description:**

Enumerates seek modes. 

<a name="table1592710919165623"></a>
<table><thead align="left"><tr id="row685942165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1687565343165623"><a name="p1687565343165623"></a><a name="p1687565343165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p22772178165623"><a name="p22772178165623"></a><a name="p22772178165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row348899439165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga14aa9d18a71eff4a0b70f748f0377c94a59c30f44f3b65ff91ee18441315dbbcc"><a name="gga14aa9d18a71eff4a0b70f748f0377c94a59c30f44f3b65ff91ee18441315dbbcc"></a><a name="gga14aa9d18a71eff4a0b70f748f0377c94a59c30f44f3b65ff91ee18441315dbbcc"></a></strong>FORMAT_SEEK_MODE_FORWARD_KEY </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p779546940165623"><a name="p779546940165623"></a><a name="p779546940165623"></a>Seeks forwards for the keyframe closest to specified position. </p>
 </td>
</tr>
<tr id="row25722173165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga14aa9d18a71eff4a0b70f748f0377c94a00f9ebeb7f829675bde8cad3832efcdd"><a name="gga14aa9d18a71eff4a0b70f748f0377c94a00f9ebeb7f829675bde8cad3832efcdd"></a><a name="gga14aa9d18a71eff4a0b70f748f0377c94a00f9ebeb7f829675bde8cad3832efcdd"></a></strong>FORMAT_SEEK_MODE_BACKWARD_KEY </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p592512484165623"><a name="p592512484165623"></a><a name="p592512484165623"></a>Seeks backwards for the keyframe closest to specified position. </p>
 </td>
</tr>
<tr id="row1423605906165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga14aa9d18a71eff4a0b70f748f0377c94a605cab737a9cfc0a06f911efa117646d"><a name="gga14aa9d18a71eff4a0b70f748f0377c94a605cab737a9cfc0a06f911efa117646d"></a><a name="gga14aa9d18a71eff4a0b70f748f0377c94a605cab737a9cfc0a06f911efa117646d"></a></strong>FORMAT_SEEK_MODE_CLOSEST_KEY </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p289366924165623"><a name="p289366924165623"></a><a name="p289366924165623"></a>Seeks for the keyframe closest to specified position. </p>
 </td>
</tr>
<tr id="row184276529165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga14aa9d18a71eff4a0b70f748f0377c94a1a87eaf0f3e52132aba4563232a6f248"><a name="gga14aa9d18a71eff4a0b70f748f0377c94a1a87eaf0f3e52132aba4563232a6f248"></a><a name="gga14aa9d18a71eff4a0b70f748f0377c94a1a87eaf0f3e52132aba4563232a6f248"></a></strong>SEEK_MODE_BUT </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1822664744165623"><a name="p1822664744165623"></a><a name="p1822664744165623"></a>Undefined mode </p>
 </td>
</tr>
</tbody>
</table>

## FrameType<a name="gad495a9f61af7fff07d7e97979d1ab854"></a>

```
enum [FrameType](format.md#gad495a9f61af7fff07d7e97979d1ab854)
```

 **Description:**

Enumerates data frame types. 

<a name="table1204411671165623"></a>
<table><thead align="left"><tr id="row1851258896165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1986870913165623"><a name="p1986870913165623"></a><a name="p1986870913165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1461597091165623"><a name="p1461597091165623"></a><a name="p1461597091165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row783092066165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggad495a9f61af7fff07d7e97979d1ab854a54c4b682d718fd6c8e5f224ee2fad841"><a name="ggad495a9f61af7fff07d7e97979d1ab854a54c4b682d718fd6c8e5f224ee2fad841"></a><a name="ggad495a9f61af7fff07d7e97979d1ab854a54c4b682d718fd6c8e5f224ee2fad841"></a></strong>FRAME_TYPE_NONE </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p824501817165623"><a name="p824501817165623"></a><a name="p824501817165623"></a>Unknown type, which can be used for transport stream (TS) packets </p>
 </td>
</tr>
<tr id="row693229246165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggad495a9f61af7fff07d7e97979d1ab854a709dd5ff367a8ff7669fda5386291796"><a name="ggad495a9f61af7fff07d7e97979d1ab854a709dd5ff367a8ff7669fda5386291796"></a><a name="ggad495a9f61af7fff07d7e97979d1ab854a709dd5ff367a8ff7669fda5386291796"></a></strong>FRAME_TYPE_AUDIO </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2100143595165623"><a name="p2100143595165623"></a><a name="p2100143595165623"></a>Audio frame </p>
 </td>
</tr>
<tr id="row576648559165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggad495a9f61af7fff07d7e97979d1ab854a7670f4378c84a94fb65f6c30c4b1a096"><a name="ggad495a9f61af7fff07d7e97979d1ab854a7670f4378c84a94fb65f6c30c4b1a096"></a><a name="ggad495a9f61af7fff07d7e97979d1ab854a7670f4378c84a94fb65f6c30c4b1a096"></a></strong>FRAME_TYPE_VIDEO </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p184524023165623"><a name="p184524023165623"></a><a name="p184524023165623"></a>Video frame </p>
 </td>
</tr>
<tr id="row1671585815165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggad495a9f61af7fff07d7e97979d1ab854a90bb6db5c310d60ccd4a6ec1b172e9e5"><a name="ggad495a9f61af7fff07d7e97979d1ab854a90bb6db5c310d60ccd4a6ec1b172e9e5"></a><a name="ggad495a9f61af7fff07d7e97979d1ab854a90bb6db5c310d60ccd4a6ec1b172e9e5"></a></strong>FRAME_TYPE_IMAGE </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p112920900165623"><a name="p112920900165623"></a><a name="p112920900165623"></a>Image frame </p>
 </td>
</tr>
<tr id="row670102419165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggad495a9f61af7fff07d7e97979d1ab854a3b43393b8fff68297e4daf0c32193704"><a name="ggad495a9f61af7fff07d7e97979d1ab854a3b43393b8fff68297e4daf0c32193704"></a><a name="ggad495a9f61af7fff07d7e97979d1ab854a3b43393b8fff68297e4daf0c32193704"></a></strong>FRAME_TYPE_SUB </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p328214674165623"><a name="p328214674165623"></a><a name="p328214674165623"></a>Subtitle frame </p>
 </td>
</tr>
<tr id="row1613779740165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggad495a9f61af7fff07d7e97979d1ab854a75641aebcb420f0f661dc8acefdc9b30"><a name="ggad495a9f61af7fff07d7e97979d1ab854a75641aebcb420f0f661dc8acefdc9b30"></a><a name="ggad495a9f61af7fff07d7e97979d1ab854a75641aebcb420f0f661dc8acefdc9b30"></a></strong>FRAME_TYPE_DATA </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1152953735165623"><a name="p1152953735165623"></a><a name="p1152953735165623"></a>Data </p>
 </td>
</tr>
<tr id="row1096706647165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggad495a9f61af7fff07d7e97979d1ab854a7afc81a56325cb4a7356663ccd270931"><a name="ggad495a9f61af7fff07d7e97979d1ab854a7afc81a56325cb4a7356663ccd270931"></a><a name="ggad495a9f61af7fff07d7e97979d1ab854a7afc81a56325cb4a7356663ccd270931"></a></strong>FRAME_TYPE_BUT </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p86172049165623"><a name="p86172049165623"></a><a name="p86172049165623"></a>Undefined type </p>
 </td>
</tr>
</tbody>
</table>

## KeyType<a name="gaab0feaba617470cb4aa830dc5935238c"></a>

```
enum [KeyType](format.md#gaab0feaba617470cb4aa830dc5935238c)
```

 **Description:**

Enumerates key types used for setting and obtaining parameters. 

<a name="table401054920165623"></a>
<table><thead align="left"><tr id="row2116671668165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1642755159165623"><a name="p1642755159165623"></a><a name="p1642755159165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1036911643165623"><a name="p1036911643165623"></a><a name="p1036911643165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1532465784165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaab0feaba617470cb4aa830dc5935238ca5a467ebeae7cb5f1568c3d881f545e70"><a name="ggaab0feaba617470cb4aa830dc5935238ca5a467ebeae7cb5f1568c3d881f545e70"></a><a name="ggaab0feaba617470cb4aa830dc5935238ca5a467ebeae7cb5f1568c3d881f545e70"></a></strong>KEY_TYPE_MIME </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p132262313165623"><a name="p132262313165623"></a><a name="p132262313165623"></a>MIME type. The value type is <strong id="b1054849456165623"><a name="b1054849456165623"></a><a name="b1054849456165623"></a>cstring</strong>. </p>
 </td>
</tr>
<tr id="row670018780165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaab0feaba617470cb4aa830dc5935238ca9e29390ad126492d6aeb3a96fe60dfd0"><a name="ggaab0feaba617470cb4aa830dc5935238ca9e29390ad126492d6aeb3a96fe60dfd0"></a><a name="ggaab0feaba617470cb4aa830dc5935238ca9e29390ad126492d6aeb3a96fe60dfd0"></a></strong>KEY_TYPE_HTTP_HEADERS </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1410099488165623"><a name="p1410099488165623"></a><a name="p1410099488165623"></a>HTTP header. The value type is <strong id="b1129232692165623"><a name="b1129232692165623"></a><a name="b1129232692165623"></a>cstring</strong>. </p>
 </td>
</tr>
<tr id="row1021035941165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaab0feaba617470cb4aa830dc5935238ca493efb89298fa6070eb02f4a4e1dc3da"><a name="ggaab0feaba617470cb4aa830dc5935238ca493efb89298fa6070eb02f4a4e1dc3da"></a><a name="ggaab0feaba617470cb4aa830dc5935238ca493efb89298fa6070eb02f4a4e1dc3da"></a></strong>KEY_TYPE_LANGUAGE </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1911920571165623"><a name="p1911920571165623"></a><a name="p1911920571165623"></a>Track language, which is usually the language of audio and subtitles. The value type is <strong id="b193206805165623"><a name="b193206805165623"></a><a name="b193206805165623"></a>cstring</strong>. </p>
 </td>
</tr>
<tr id="row759392121165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaab0feaba617470cb4aa830dc5935238ca1208cc2b99c8ac61f8fb68fd743cb231"><a name="ggaab0feaba617470cb4aa830dc5935238ca1208cc2b99c8ac61f8fb68fd743cb231"></a><a name="ggaab0feaba617470cb4aa830dc5935238ca1208cc2b99c8ac61f8fb68fd743cb231"></a></strong>KEY_TYPE_PRE_CACHE </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2119593296165623"><a name="p2119593296165623"></a><a name="p2119593296165623"></a>Precapture cache size. The value type is <strong id="b728220094165623"><a name="b728220094165623"></a><a name="b728220094165623"></a>int</strong> </p>
 </td>
</tr>
</tbody>
</table>

## ManualSplitType<a name="ga10d9833450f29129d249c41d9acb4bc4"></a>

```
enum [ManualSplitType](format.md#ga10d9833450f29129d249c41d9acb4bc4)
```

 **Description:**

Enumerates manual split types for the muxer. 

<a name="table975540443165623"></a>
<table><thead align="left"><tr id="row947964900165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1636916241165623"><a name="p1636916241165623"></a><a name="p1636916241165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1769636733165623"><a name="p1769636733165623"></a><a name="p1769636733165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row898098283165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga10d9833450f29129d249c41d9acb4bc4ad283396b08ef486b6615977c881a8724"><a name="gga10d9833450f29129d249c41d9acb4bc4ad283396b08ef486b6615977c881a8724"></a><a name="gga10d9833450f29129d249c41d9acb4bc4ad283396b08ef486b6615977c881a8724"></a></strong>MANUAL_SPLIT_POST </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p921650363165623"><a name="p921650363165623"></a><a name="p921650363165623"></a>Search forwards from the current I-frame and split the file at the closest I-frame. </p>
 </td>
</tr>
<tr id="row1710089942165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga10d9833450f29129d249c41d9acb4bc4ae1c9eea90aaf796ffc5932cc50548716"><a name="gga10d9833450f29129d249c41d9acb4bc4ae1c9eea90aaf796ffc5932cc50548716"></a><a name="gga10d9833450f29129d249c41d9acb4bc4ae1c9eea90aaf796ffc5932cc50548716"></a></strong>MANUAL_SPLIT_PRE </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p693852952165623"><a name="p693852952165623"></a><a name="p693852952165623"></a>Search backwards from the current I-frame and split the file at the closest I-frame. </p>
 </td>
</tr>
<tr id="row295320042165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga10d9833450f29129d249c41d9acb4bc4a2b3ef6d50352019e54db9736e6dde05e"><a name="gga10d9833450f29129d249c41d9acb4bc4a2b3ef6d50352019e54db9736e6dde05e"></a><a name="gga10d9833450f29129d249c41d9acb4bc4a2b3ef6d50352019e54db9736e6dde05e"></a></strong>MANUAL_SPLIT_NORMAL </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p218342922165623"><a name="p218342922165623"></a><a name="p218342922165623"></a>Normal split </p>
 </td>
</tr>
</tbody>
</table>

## OutputFormat<a name="gaeb712c6c6c0a8af0dfd79f451ecb9277"></a>

```
enum [OutputFormat](format.md#gaeb712c6c6c0a8af0dfd79f451ecb9277)
```

 **Description:**

Enumerates output file formats. 

<a name="table647864388165623"></a>
<table><thead align="left"><tr id="row752964208165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p738497662165623"><a name="p738497662165623"></a><a name="p738497662165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1993489296165623"><a name="p1993489296165623"></a><a name="p1993489296165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2097906643165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaeb712c6c6c0a8af0dfd79f451ecb9277a5a01488de2f310872db03b7a6ad26423"><a name="ggaeb712c6c6c0a8af0dfd79f451ecb9277a5a01488de2f310872db03b7a6ad26423"></a><a name="ggaeb712c6c6c0a8af0dfd79f451ecb9277a5a01488de2f310872db03b7a6ad26423"></a></strong>OUTPUT_FORMAT_MPEG_4 </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1414699236165623"><a name="p1414699236165623"></a><a name="p1414699236165623"></a>MP4 </p>
 </td>
</tr>
<tr id="row1042385870165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaeb712c6c6c0a8af0dfd79f451ecb9277a9eaec301329c61d07d2fe19ca473abc2"><a name="ggaeb712c6c6c0a8af0dfd79f451ecb9277a9eaec301329c61d07d2fe19ca473abc2"></a><a name="ggaeb712c6c6c0a8af0dfd79f451ecb9277a9eaec301329c61d07d2fe19ca473abc2"></a></strong>OUTPUT_FORMAT_TS </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p558247847165623"><a name="p558247847165623"></a><a name="p558247847165623"></a>TS </p>
 </td>
</tr>
<tr id="row2038987772165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaeb712c6c6c0a8af0dfd79f451ecb9277a3a0cc99ed9dcc44245dd91591b7accac"><a name="ggaeb712c6c6c0a8af0dfd79f451ecb9277a3a0cc99ed9dcc44245dd91591b7accac"></a><a name="ggaeb712c6c6c0a8af0dfd79f451ecb9277a3a0cc99ed9dcc44245dd91591b7accac"></a></strong>OUTPUT_FORMAT_THREE_GPP </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1051012987165623"><a name="p1051012987165623"></a><a name="p1051012987165623"></a>3GPP </p>
 </td>
</tr>
<tr id="row1892565156165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaeb712c6c6c0a8af0dfd79f451ecb9277a68afc7e60f3cdacd5e1fb9a5dcf0ebdb"><a name="ggaeb712c6c6c0a8af0dfd79f451ecb9277a68afc7e60f3cdacd5e1fb9a5dcf0ebdb"></a><a name="ggaeb712c6c6c0a8af0dfd79f451ecb9277a68afc7e60f3cdacd5e1fb9a5dcf0ebdb"></a></strong>OUTPUT_FORMAT_HEIF </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p981510716165623"><a name="p981510716165623"></a><a name="p981510716165623"></a>HEIF </p>
 </td>
</tr>
<tr id="row2034168899165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaeb712c6c6c0a8af0dfd79f451ecb9277abb34ec8353ace07dbfd698c05343800d"><a name="ggaeb712c6c6c0a8af0dfd79f451ecb9277abb34ec8353ace07dbfd698c05343800d"></a><a name="ggaeb712c6c6c0a8af0dfd79f451ecb9277abb34ec8353ace07dbfd698c05343800d"></a></strong>OUTPUT_FORMAT_OGG </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p660286815165623"><a name="p660286815165623"></a><a name="p660286815165623"></a>Ogg </p>
 </td>
</tr>
<tr id="row154367261165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaeb712c6c6c0a8af0dfd79f451ecb9277a00eb675fb0d802a5143f4f718ea854e3"><a name="ggaeb712c6c6c0a8af0dfd79f451ecb9277a00eb675fb0d802a5143f4f718ea854e3"></a><a name="ggaeb712c6c6c0a8af0dfd79f451ecb9277a00eb675fb0d802a5143f4f718ea854e3"></a></strong>OUTPUT_FORMAT_INVALID </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1403688532165623"><a name="p1403688532165623"></a><a name="p1403688532165623"></a>Invalid format </p>
 </td>
</tr>
</tbody>
</table>

## OutputType<a name="ga4e0517338e6c4a31a2addafc06d4f3a3"></a>

```
enum [OutputType](format.md#ga4e0517338e6c4a31a2addafc06d4f3a3)
```

 **Description:**

Enumerates muxer output types. 

<a name="table1863226639165623"></a>
<table><thead align="left"><tr id="row516722010165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1933553207165623"><a name="p1933553207165623"></a><a name="p1933553207165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p225054152165623"><a name="p225054152165623"></a><a name="p225054152165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row505521392165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga4e0517338e6c4a31a2addafc06d4f3a3a14ea73c5ea45e0f9b6976d24ac1119e9"><a name="gga4e0517338e6c4a31a2addafc06d4f3a3a14ea73c5ea45e0f9b6976d24ac1119e9"></a><a name="gga4e0517338e6c4a31a2addafc06d4f3a3a14ea73c5ea45e0f9b6976d24ac1119e9"></a></strong>OUTPUT_TYPE_FD </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1638044799165623"><a name="p1638044799165623"></a><a name="p1638044799165623"></a>File descriptor </p>
 </td>
</tr>
<tr id="row1158006240165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga4e0517338e6c4a31a2addafc06d4f3a3a67f14fbe9f23ae5acd2ffc7b00fd6740"><a name="gga4e0517338e6c4a31a2addafc06d4f3a3a67f14fbe9f23ae5acd2ffc7b00fd6740"></a><a name="gga4e0517338e6c4a31a2addafc06d4f3a3a67f14fbe9f23ae5acd2ffc7b00fd6740"></a></strong>OUTPUT_TYPE_URI </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1964886643165623"><a name="p1964886643165623"></a><a name="p1964886643165623"></a>Local file URI </p>
 </td>
</tr>
<tr id="row997027327165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga4e0517338e6c4a31a2addafc06d4f3a3a169d19953026c9c3fed4e4433624ca7c"><a name="gga4e0517338e6c4a31a2addafc06d4f3a3a169d19953026c9c3fed4e4433624ca7c"></a><a name="gga4e0517338e6c4a31a2addafc06d4f3a3a169d19953026c9c3fed4e4433624ca7c"></a></strong>OUTPUT_TYPE_INVALID </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1695138322165623"><a name="p1695138322165623"></a><a name="p1695138322165623"></a>Undefined type </p>
 </td>
</tr>
</tbody>
</table>

## SourceType<a name="ga3ae727773c367ac1041d72ac770a0ab1"></a>

```
enum [SourceType](format.md#ga3ae727773c367ac1041d72ac770a0ab1)
```

 **Description:**

Enumerates types of the demuxer data source. 

<a name="table1328562663165623"></a>
<table><thead align="left"><tr id="row622920173165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1576593247165623"><a name="p1576593247165623"></a><a name="p1576593247165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p568100053165623"><a name="p568100053165623"></a><a name="p568100053165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row215107687165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga3ae727773c367ac1041d72ac770a0ab1a126568132b92d49365d94c4aa00cdde4"><a name="gga3ae727773c367ac1041d72ac770a0ab1a126568132b92d49365d94c4aa00cdde4"></a><a name="gga3ae727773c367ac1041d72ac770a0ab1a126568132b92d49365d94c4aa00cdde4"></a></strong>SOURCE_TYPE_FD </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1879633212165623"><a name="p1879633212165623"></a><a name="p1879633212165623"></a>File descriptor </p>
 </td>
</tr>
<tr id="row731339721165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga3ae727773c367ac1041d72ac770a0ab1a70d32ea5aeaa325764508722ba31403c"><a name="gga3ae727773c367ac1041d72ac770a0ab1a70d32ea5aeaa325764508722ba31403c"></a><a name="gga3ae727773c367ac1041d72ac770a0ab1a70d32ea5aeaa325764508722ba31403c"></a></strong>SOURCE_TYPE_URI </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p393485668165623"><a name="p393485668165623"></a><a name="p393485668165623"></a>URI, which can be a network address or a local file path </p>
 </td>
</tr>
<tr id="row897016360165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga3ae727773c367ac1041d72ac770a0ab1a7f632a791d8f6dfbe5940b5648d29e6c"><a name="gga3ae727773c367ac1041d72ac770a0ab1a7f632a791d8f6dfbe5940b5648d29e6c"></a><a name="gga3ae727773c367ac1041d72ac770a0ab1a7f632a791d8f6dfbe5940b5648d29e6c"></a></strong>SOURCE_TYPE_STREAM </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2070641395165623"><a name="p2070641395165623"></a><a name="p2070641395165623"></a>Streams </p>
 </td>
</tr>
<tr id="row597262376165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga3ae727773c367ac1041d72ac770a0ab1ad41c2f0bdca46364d6cd86fc5d4710d3"><a name="gga3ae727773c367ac1041d72ac770a0ab1ad41c2f0bdca46364d6cd86fc5d4710d3"></a><a name="gga3ae727773c367ac1041d72ac770a0ab1ad41c2f0bdca46364d6cd86fc5d4710d3"></a></strong>SOURCE_TYPE_BUT </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p795307878165623"><a name="p795307878165623"></a><a name="p795307878165623"></a>Undefined source </p>
 </td>
</tr>
</tbody>
</table>

## SubtitleFormat<a name="gadac45ce4731516c262292c15433439b3"></a>

```
enum [SubtitleFormat](format.md#gadac45ce4731516c262292c15433439b3)
```

 **Description:**

Enumerates subtitle file formats. 

<a name="table2043427472165623"></a>
<table><thead align="left"><tr id="row1255953011165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1834839950165623"><a name="p1834839950165623"></a><a name="p1834839950165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1268962899165623"><a name="p1268962899165623"></a><a name="p1268962899165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1499289393165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggadac45ce4731516c262292c15433439b3abe03cb7d3bb87dcfc197b9e9db7a66f6"><a name="ggadac45ce4731516c262292c15433439b3abe03cb7d3bb87dcfc197b9e9db7a66f6"></a><a name="ggadac45ce4731516c262292c15433439b3abe03cb7d3bb87dcfc197b9e9db7a66f6"></a></strong>FORMAT_SUB_ASS </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1337537161165623"><a name="p1337537161165623"></a><a name="p1337537161165623"></a>ASS </p>
 </td>
</tr>
<tr id="row1976735925165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggadac45ce4731516c262292c15433439b3a569e5e22b1c3bf5b9f4cc3f596cfc6db"><a name="ggadac45ce4731516c262292c15433439b3a569e5e22b1c3bf5b9f4cc3f596cfc6db"></a><a name="ggadac45ce4731516c262292c15433439b3a569e5e22b1c3bf5b9f4cc3f596cfc6db"></a></strong>FORMAT_SUB_LRC </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1899754016165623"><a name="p1899754016165623"></a><a name="p1899754016165623"></a>LRC </p>
 </td>
</tr>
<tr id="row2142608832165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggadac45ce4731516c262292c15433439b3a26f41cfe561866b43a9757b5902c7609"><a name="ggadac45ce4731516c262292c15433439b3a26f41cfe561866b43a9757b5902c7609"></a><a name="ggadac45ce4731516c262292c15433439b3a26f41cfe561866b43a9757b5902c7609"></a></strong>FORMAT_SUB_SRT </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p786831301165623"><a name="p786831301165623"></a><a name="p786831301165623"></a>SRT </p>
 </td>
</tr>
<tr id="row1600207550165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggadac45ce4731516c262292c15433439b3ac6665b95ccb70e7a7d87dda6370821ff"><a name="ggadac45ce4731516c262292c15433439b3ac6665b95ccb70e7a7d87dda6370821ff"></a><a name="ggadac45ce4731516c262292c15433439b3ac6665b95ccb70e7a7d87dda6370821ff"></a></strong>FORMAT_SUB_SMI </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1890980702165623"><a name="p1890980702165623"></a><a name="p1890980702165623"></a>SMI </p>
 </td>
</tr>
<tr id="row845059997165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggadac45ce4731516c262292c15433439b3a07a0a164bb0081359639cfdef57aa2c2"><a name="ggadac45ce4731516c262292c15433439b3a07a0a164bb0081359639cfdef57aa2c2"></a><a name="ggadac45ce4731516c262292c15433439b3a07a0a164bb0081359639cfdef57aa2c2"></a></strong>FORMAT_SUB_SUB </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1850262128165623"><a name="p1850262128165623"></a><a name="p1850262128165623"></a>SUB </p>
 </td>
</tr>
<tr id="row1967121263165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggadac45ce4731516c262292c15433439b3a5ad9a3ec464416e8395e3e0f6595c253"><a name="ggadac45ce4731516c262292c15433439b3a5ad9a3ec464416e8395e3e0f6595c253"></a><a name="ggadac45ce4731516c262292c15433439b3a5ad9a3ec464416e8395e3e0f6595c253"></a></strong>FORMAT_SUB_TXT </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p151749380165623"><a name="p151749380165623"></a><a name="p151749380165623"></a>RAW UTF-8 </p>
 </td>
</tr>
<tr id="row2048809097165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggadac45ce4731516c262292c15433439b3a9f573cd39fab8fc143480bf1eb973574"><a name="ggadac45ce4731516c262292c15433439b3a9f573cd39fab8fc143480bf1eb973574"></a><a name="ggadac45ce4731516c262292c15433439b3a9f573cd39fab8fc143480bf1eb973574"></a></strong>FORMAT_SUB_HDMV_PGS </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p465765058165623"><a name="p465765058165623"></a><a name="p465765058165623"></a>HDMV PGS </p>
 </td>
</tr>
<tr id="row1878249992165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggadac45ce4731516c262292c15433439b3a641b27aab74dbbcd88d7d8612b60caad"><a name="ggadac45ce4731516c262292c15433439b3a641b27aab74dbbcd88d7d8612b60caad"></a><a name="ggadac45ce4731516c262292c15433439b3a641b27aab74dbbcd88d7d8612b60caad"></a></strong>FORMAT_SUB_DVB_SUB </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p527298011165623"><a name="p527298011165623"></a><a name="p527298011165623"></a>DVB </p>
 </td>
</tr>
<tr id="row583313206165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggadac45ce4731516c262292c15433439b3a91ab0e8c1931fc3b4f2350a8e18672a6"><a name="ggadac45ce4731516c262292c15433439b3a91ab0e8c1931fc3b4f2350a8e18672a6"></a><a name="ggadac45ce4731516c262292c15433439b3a91ab0e8c1931fc3b4f2350a8e18672a6"></a></strong>FORMAT_SUB_DVD_SUB </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p266492849165623"><a name="p266492849165623"></a><a name="p266492849165623"></a>DVD </p>
 </td>
</tr>
<tr id="row695411227165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggadac45ce4731516c262292c15433439b3a0750bc81000513246d5785d0ef2c0099"><a name="ggadac45ce4731516c262292c15433439b3a0750bc81000513246d5785d0ef2c0099"></a><a name="ggadac45ce4731516c262292c15433439b3a0750bc81000513246d5785d0ef2c0099"></a></strong>FORMAT_SUB_TTML </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2052794178165623"><a name="p2052794178165623"></a><a name="p2052794178165623"></a>TTML </p>
 </td>
</tr>
<tr id="row1621478280165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggadac45ce4731516c262292c15433439b3ad9de45a6ae50e5443e2d0418b1cdde61"><a name="ggadac45ce4731516c262292c15433439b3ad9de45a6ae50e5443e2d0418b1cdde61"></a><a name="ggadac45ce4731516c262292c15433439b3ad9de45a6ae50e5443e2d0418b1cdde61"></a></strong>FORMAT_SUB_WEBVTT </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1881633270165623"><a name="p1881633270165623"></a><a name="p1881633270165623"></a>WebVTT </p>
 </td>
</tr>
<tr id="row1388561379165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggadac45ce4731516c262292c15433439b3a52ed4b60bc3d33d43753555e1edf50d7"><a name="ggadac45ce4731516c262292c15433439b3a52ed4b60bc3d33d43753555e1edf50d7"></a><a name="ggadac45ce4731516c262292c15433439b3a52ed4b60bc3d33d43753555e1edf50d7"></a></strong>FORMAT_SUB_BUTT </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p246023086165623"><a name="p246023086165623"></a><a name="p246023086165623"></a>Undefined format </p>
 </td>
</tr>
</tbody>
</table>

## SubtitleFrameType<a name="ga43b7f046e365a89697272d850b0517b7"></a>

```
enum [SubtitleFrameType](format.md#ga43b7f046e365a89697272d850b0517b7)
```

 **Description:**

Enumerates subtitle frame types. 

<a name="table1677640356165623"></a>
<table><thead align="left"><tr id="row16871841165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p679649297165623"><a name="p679649297165623"></a><a name="p679649297165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p772726536165623"><a name="p772726536165623"></a><a name="p772726536165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row782213639165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga43b7f046e365a89697272d850b0517b7a6bc8b3dca40c75f6dd22feea62cbdac7"><a name="gga43b7f046e365a89697272d850b0517b7a6bc8b3dca40c75f6dd22feea62cbdac7"></a><a name="gga43b7f046e365a89697272d850b0517b7a6bc8b3dca40c75f6dd22feea62cbdac7"></a></strong>HI_SVR_SUBTITLE_BITMAP </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p294233722165623"><a name="p294233722165623"></a><a name="p294233722165623"></a>Bitmap (BMP) </p>
 </td>
</tr>
<tr id="row885878874165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga43b7f046e365a89697272d850b0517b7a3ee7a0476e395ec2689f754e58d512a0"><a name="gga43b7f046e365a89697272d850b0517b7a3ee7a0476e395ec2689f754e58d512a0"></a><a name="gga43b7f046e365a89697272d850b0517b7a3ee7a0476e395ec2689f754e58d512a0"></a></strong>HI_SVR_SUBTITLE_TEXT </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1719849632165623"><a name="p1719849632165623"></a><a name="p1719849632165623"></a>Text </p>
 </td>
</tr>
</tbody>
</table>

## TrackSourceType<a name="ga953bc46f95d7b2d8866838d792f8f6aa"></a>

```
enum [TrackSourceType](format.md#ga953bc46f95d7b2d8866838d792f8f6aa)
```

 **Description:**

Enumerates types of the muxer source track. 

<a name="table281900538165623"></a>
<table><thead align="left"><tr id="row1925275360165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p478643079165623"><a name="p478643079165623"></a><a name="p478643079165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p485372182165623"><a name="p485372182165623"></a><a name="p485372182165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row927387878165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga953bc46f95d7b2d8866838d792f8f6aaa59d8c33314397a4ae8c1ca7b9e4eb40f"><a name="gga953bc46f95d7b2d8866838d792f8f6aaa59d8c33314397a4ae8c1ca7b9e4eb40f"></a><a name="gga953bc46f95d7b2d8866838d792f8f6aaa59d8c33314397a4ae8c1ca7b9e4eb40f"></a></strong>TRACK_SOURCE_TYPE_VIDEO </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p91925396165623"><a name="p91925396165623"></a><a name="p91925396165623"></a>Video track </p>
 </td>
</tr>
<tr id="row85598891165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga953bc46f95d7b2d8866838d792f8f6aaa5e9f39cae59134e444907af8b372b7a4"><a name="gga953bc46f95d7b2d8866838d792f8f6aaa5e9f39cae59134e444907af8b372b7a4"></a><a name="gga953bc46f95d7b2d8866838d792f8f6aaa5e9f39cae59134e444907af8b372b7a4"></a></strong>TRACK_SOURCE_TYPE_AUDIO </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p57509440165623"><a name="p57509440165623"></a><a name="p57509440165623"></a>Audio track </p>
 </td>
</tr>
<tr id="row1663858554165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga953bc46f95d7b2d8866838d792f8f6aaa5d0d794425327268d08990d26a21f50c"><a name="gga953bc46f95d7b2d8866838d792f8f6aaa5d0d794425327268d08990d26a21f50c"></a><a name="gga953bc46f95d7b2d8866838d792f8f6aaa5d0d794425327268d08990d26a21f50c"></a></strong>TRACK_SOURCE_TYPE_DATA </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1322552695165623"><a name="p1322552695165623"></a><a name="p1322552695165623"></a>Data track </p>
 </td>
</tr>
<tr id="row304532427165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga953bc46f95d7b2d8866838d792f8f6aaa0fae189aab417f7c9756523f15a20cca"><a name="gga953bc46f95d7b2d8866838d792f8f6aaa0fae189aab417f7c9756523f15a20cca"></a><a name="gga953bc46f95d7b2d8866838d792f8f6aaa0fae189aab417f7c9756523f15a20cca"></a></strong>TRACK_SOURCE_TYPE_INVALID </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1975863407165623"><a name="p1975863407165623"></a><a name="p1975863407165623"></a>Invalid type </p>
 </td>
</tr>
</tbody>
</table>

## TrackType<a name="gad80740dd555f7d3688d2c4d9f44d3b04"></a>

```
enum [TrackType](format.md#gad80740dd555f7d3688d2c4d9f44d3b04)
```

 **Description:**

Enumerates track types. 

<a name="table1440830009165623"></a>
<table><thead align="left"><tr id="row1314789067165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p189831107165623"><a name="p189831107165623"></a><a name="p189831107165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1081788838165623"><a name="p1081788838165623"></a><a name="p1081788838165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1144371643165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggad80740dd555f7d3688d2c4d9f44d3b04aae00a139d1f3bbfef9dbda6803497b62"><a name="ggad80740dd555f7d3688d2c4d9f44d3b04aae00a139d1f3bbfef9dbda6803497b62"></a><a name="ggad80740dd555f7d3688d2c4d9f44d3b04aae00a139d1f3bbfef9dbda6803497b62"></a></strong>TRACK_TYPE_VIDEO </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2017391783165623"><a name="p2017391783165623"></a><a name="p2017391783165623"></a>Video track </p>
 </td>
</tr>
<tr id="row174273958165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggad80740dd555f7d3688d2c4d9f44d3b04aab84be45f332c1bd8ab31d9404c6d944"><a name="ggad80740dd555f7d3688d2c4d9f44d3b04aab84be45f332c1bd8ab31d9404c6d944"></a><a name="ggad80740dd555f7d3688d2c4d9f44d3b04aab84be45f332c1bd8ab31d9404c6d944"></a></strong>TRACK_TYPE_AUDIO </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p568091265165623"><a name="p568091265165623"></a><a name="p568091265165623"></a>Audio track </p>
 </td>
</tr>
<tr id="row358956027165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggad80740dd555f7d3688d2c4d9f44d3b04a3c834b6afb84a38aa490253a3abc5f66"><a name="ggad80740dd555f7d3688d2c4d9f44d3b04a3c834b6afb84a38aa490253a3abc5f66"></a><a name="ggad80740dd555f7d3688d2c4d9f44d3b04a3c834b6afb84a38aa490253a3abc5f66"></a></strong>TRACK_TYPE_IMAGE </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1222917741165623"><a name="p1222917741165623"></a><a name="p1222917741165623"></a>Image track </p>
 </td>
</tr>
<tr id="row1347245621165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggad80740dd555f7d3688d2c4d9f44d3b04aff6cb64c75689ea5b11063e0984956f4"><a name="ggad80740dd555f7d3688d2c4d9f44d3b04aff6cb64c75689ea5b11063e0984956f4"></a><a name="ggad80740dd555f7d3688d2c4d9f44d3b04aff6cb64c75689ea5b11063e0984956f4"></a></strong>TRACK_TYPE_SUB </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p10470657165623"><a name="p10470657165623"></a><a name="p10470657165623"></a>Subtitle track </p>
 </td>
</tr>
<tr id="row2006104306165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggad80740dd555f7d3688d2c4d9f44d3b04abe0c58f8c0a492959631b8f41dbe2af7"><a name="ggad80740dd555f7d3688d2c4d9f44d3b04abe0c58f8c0a492959631b8f41dbe2af7"></a><a name="ggad80740dd555f7d3688d2c4d9f44d3b04abe0c58f8c0a492959631b8f41dbe2af7"></a></strong>TRACK_TYPE_DATA </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1030622847165623"><a name="p1030622847165623"></a><a name="p1030622847165623"></a>Data track </p>
 </td>
</tr>
<tr id="row2111461424165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggad80740dd555f7d3688d2c4d9f44d3b04ad3a1729659a9a6453a2d2bda67cb2c22"><a name="ggad80740dd555f7d3688d2c4d9f44d3b04ad3a1729659a9a6453a2d2bda67cb2c22"></a><a name="ggad80740dd555f7d3688d2c4d9f44d3b04ad3a1729659a9a6453a2d2bda67cb2c22"></a></strong>TRACK_TYPE_BUT </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1750604811165623"><a name="p1750604811165623"></a><a name="p1750604811165623"></a>Undefined track </p>
 </td>
</tr>
</tbody>
</table>

## **Function **<a name="section1772238272165623"></a>

## FormatDeInit\(\)<a name="gabb574933ebb4f3d1d2ed299e79aeee2c"></a>

```
void FormatDeInit (void )
```

 **Description:**

Deinitializes the format. 

You can call this function to deinitialize the demuxer and muxer. This function works in pair with  [FormatInit](format.md#gae10a50c8f3de6e54ee0dc3937f755920).

## FormatDemuxerCreate\(\)<a name="ga183fbc31f2c9877ef56464abcccef374"></a>

```
int32_t FormatDemuxerCreate (const [FormatSource](formatsource.md) * source, void ** handle )
```

 **Description:**

Creates a demuxer component and returns its context handle. 

This function returns the demuxer context handle without probing the container format or obtaining stream information.

**Parameters:**

<a name="table97718259165623"></a>
<table><thead align="left"><tr id="row1890900774165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1710975378165623"><a name="p1710975378165623"></a><a name="p1710975378165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1040838545165623"><a name="p1040838545165623"></a><a name="p1040838545165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row174018426165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">source</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the format source of the demuxer. For details, see <a href="formatsource.md">FormatSource</a>. </td>
</tr>
<tr id="row1963472290165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double pointer to the demuxer context handle. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value otherwise. 

## FormatDemuxerDestory\(\)<a name="ga98fd9a5a5d1ffd275fc46f898ca08413"></a>

```
int32_t FormatDemuxerDestory (void * handle)
```

 **Description:**

Destroys demuxer resources. 

This function works in pair with  [FormatDemuxerCreate](format.md#ga183fbc31f2c9877ef56464abcccef374). If you do not call this function, resource leakage may occur.

**Parameters:**

<a name="table100921538165623"></a>
<table><thead align="left"><tr id="row1038294780165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1595879616165623"><a name="p1595879616165623"></a><a name="p1595879616165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1244180751165623"><a name="p1244180751165623"></a><a name="p1244180751165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1176691908165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the demuxer context handle. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value otherwise. 

## FormatDemuxerFreeFrame\(\)<a name="ga291b805de194c695b72eb5ad721103d5"></a>

```
int32_t FormatDemuxerFreeFrame (void * handle, [FormatFrame](formatframe.md) * frame )
```

 **Description:**

Frees data frames. 

You can call this function to free the data frames obtained by calling  [FormatDemuxerReadFrame](format.md#ga7b20e1b88413d20a348d7f796917cd94).

**Parameters:**

<a name="table983719558165623"></a>
<table><thead align="left"><tr id="row46772615165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1159790440165623"><a name="p1159790440165623"></a><a name="p1159790440165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1535916661165623"><a name="p1535916661165623"></a><a name="p1535916661165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1213268165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the demuxer context handle. </td>
</tr>
<tr id="row438262704165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">frame</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the data structure <a href="formatframe.md">FormatFrame</a>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value otherwise. 

## FormatDemuxerGetBufferConfig\(\)<a name="ga565cbb52c95a95aab4dcc957fe998b5f"></a>

```
int32_t FormatDemuxerGetBufferConfig (const void * handle, [FormatBufferSetting](formatbuffersetting.md) * setting )
```

 **Description:**

Obtains the buffer information of the demuxer. 

If there is a buffer mechanism in the demuxer, you can call this function to obtain the maximum buffer size and time.

**Parameters:**

<a name="table2011747907165623"></a>
<table><thead align="left"><tr id="row923508917165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p456976577165623"><a name="p456976577165623"></a><a name="p456976577165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p441229364165623"><a name="p441229364165623"></a><a name="p441229364165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row752728788165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the demuxer context handle. </td>
</tr>
<tr id="row694958598165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">setting</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the maximum demuxer buffer size and time, as defined in <a href="formatbuffersetting.md">FormatBufferSetting</a>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value otherwise. 

## FormatDemuxerGetFileInfo\(\)<a name="gad807d61c65e89629c7eed8f97426fd5a"></a>

```
int32_t FormatDemuxerGetFileInfo (void * handle, [FileInfo](fileinfo.md) * info )
```

 **Description:**

Obtains the attributes of a media file. 

The attributes contain file, program, and stream attributes. This function should be called after  [FormatDemuxerPrepare](format.md#gacfcf40d869a48125bd67d17f8a4fc3ce)  is called.

**Parameters:**

<a name="table995590214165623"></a>
<table><thead align="left"><tr id="row1774699425165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2146936905165623"><a name="p2146936905165623"></a><a name="p2146936905165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1284796356165623"><a name="p1284796356165623"></a><a name="p1284796356165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row825289000165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the demuxer context handle. </td>
</tr>
<tr id="row1042241984165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">info</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the source attributes, as defined in <a href="fileinfo.md">FileInfo</a>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value otherwise. 

## FormatDemuxerGetParameter\(\)<a name="ga6c2a1aa9fdf1db8e2f14a3a92ffa23d5"></a>

```
int32_t FormatDemuxerGetParameter (const void * handle, int32_t trackId, [ParameterItem](parameteritem.md) * metaData )
```

 **Description:**

Obtains demuxer attributes. 

You can call this function to obtain the HTTP header, HTTP referer, and other extension items for the demuxer after  [FormatDemuxerCreate](format.md#ga183fbc31f2c9877ef56464abcccef374)  is called. The demuxer will store the value in the  **metaData**  based on the key.If the demuxer has allocated memory for the  **metaData**  to store the value, the caller should manually free the memory.

**Parameters:**

<a name="table215408504165623"></a>
<table><thead align="left"><tr id="row1188635133165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p106530309165623"><a name="p106530309165623"></a><a name="p106530309165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1878972651165623"><a name="p1878972651165623"></a><a name="p1878972651165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1650513817165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the demuxer context handle. </td>
</tr>
<tr id="row511674088165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">trackId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Identifies the track. If the value is an invalid value (<strong id="b396409985165623"><a name="b396409985165623"></a><a name="b396409985165623"></a>-1</strong>), this parameter identifies the file or program. </td>
</tr>
<tr id="row1468365421165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">metaData</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the buffer for storing the parameters values that the demuxer has searched for based on the input key. For details, see <a href="parameteritem.md">ParameterItem</a>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value otherwise. 

## FormatDemuxerGetSelectedTrack\(\)<a name="gab6ef68051ee2ed0015e721bedb1af61c"></a>

```
int32_t FormatDemuxerGetSelectedTrack (const void * handle, int32_t * programId, int32_t trackId[], int32_t * nums )
```

 **Description:**

Obtains the ID of the media track selected by the demuxer for output. 

The demuxer automatically selects the default program and its media tracks. However, if the program and media tracks have changed after  [FormatDemuxerSelectTrack](format.md#ga1d9cb94614e207def34f13eaa16ef2b7)  and  [FormatDemuxerUnselectTrack](format.md#gaf5fd5bab9613d133827054f157d5520e)  are called, you can obtain the currently selected program and media tracks by calling this function \(**FormatDemuxerGetSelectedTrack**.

**Parameters:**

<a name="table1875403121165623"></a>
<table><thead align="left"><tr id="row1345499935165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p869923503165623"><a name="p869923503165623"></a><a name="p869923503165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p373751073165623"><a name="p373751073165623"></a><a name="p373751073165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1343012992165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the demuxer context handle. </td>
</tr>
<tr id="row440939323165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">programId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Identifies the pointer to the program. </td>
</tr>
<tr id="row599067612165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">trackId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Identifies the array of selected media tracks. This parameter works in pair with <strong id="b2021870764165623"><a name="b2021870764165623"></a><a name="b2021870764165623"></a>nums</strong>. </td>
</tr>
<tr id="row1287777182165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">nums</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the total number of selected media tracks. This parameter works in pair with <strong id="b1132516006165623"><a name="b1132516006165623"></a><a name="b1132516006165623"></a>trackId</strong>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value otherwise. 

## FormatDemuxerPrepare\(\)<a name="gacfcf40d869a48125bd67d17f8a4fc3ce"></a>

```
int32_t FormatDemuxerPrepare (void * handle)
```

 **Description:**

Makes preparations for the demuxer. 

This function triggers the demuxer to probe the media file container format and parse stream information. You can obtain media file attributes only after this function is called.

**Parameters:**

<a name="table1904838756165623"></a>
<table><thead align="left"><tr id="row1782978368165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1657402186165623"><a name="p1657402186165623"></a><a name="p1657402186165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p838075646165623"><a name="p838075646165623"></a><a name="p838075646165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1912089715165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the demuxer context handle. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value otherwise. 

## FormatDemuxerReadFrame\(\)<a name="ga7b20e1b88413d20a348d7f796917cd94"></a>

```
int32_t FormatDemuxerReadFrame (const void * handle, [FormatFrame](formatframe.md) * frame, int32_t timeOutMs )
```

 **Description:**

Reads data frames. 

After the data frames are read, you need to call  **FormatDemuxerFreeFame**  to free them.

**Parameters:**

<a name="table1824120199165623"></a>
<table><thead align="left"><tr id="row528883607165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p597160853165623"><a name="p597160853165623"></a><a name="p597160853165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1399701854165623"><a name="p1399701854165623"></a><a name="p1399701854165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1321025657165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the demuxer context handle. </td>
</tr>
<tr id="row2034773684165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">frame</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the data structure <a href="formatframe.md">FormatFrame</a>. </td>
</tr>
<tr id="row629764548165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">timeOutMs</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the time required for waiting data frame read. The value <strong id="b248555230165623"><a name="b248555230165623"></a><a name="b248555230165623"></a>0</strong> indicates that data frames are immediately read without any wait. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value otherwise. 

## FormatDemuxerSeek\(\)<a name="gad53f1e848f3c2e0c8fa056a312b2ed6c"></a>

```
int32_t FormatDemuxerSeek (const void * handle, int32_t streamIndex, int64_t timeStampUs, [FormatSeekMode](format.md#ga14aa9d18a71eff4a0b70f748f0377c94) mode )
```

 **Description:**

Seeks for a specified position for the demuxer. 

After being started, the demuxer seeks for a specified position to read data frames. You can specify the position close to the time specified by  **streamIndex**.

**Parameters:**

<a name="table548106665165623"></a>
<table><thead align="left"><tr id="row958709308165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1396168964165623"><a name="p1396168964165623"></a><a name="p1396168964165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p489232648165623"><a name="p489232648165623"></a><a name="p489232648165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row543137925165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the demuxer context handle. </td>
</tr>
<tr id="row793056861165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">streamIndex</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Identifies the stream in the media file. </td>
</tr>
<tr id="row76223564165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">timeStampUs</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the target position, in microseconds. </td>
</tr>
<tr id="row1845445302165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">mode</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the seek mode, as defined in <a href="format.md#ga14aa9d18a71eff4a0b70f748f0377c94">FormatSeekMode</a>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value otherwise. 

## FormatDemuxerSelectTrack\(\)<a name="ga1d9cb94614e207def34f13eaa16ef2b7"></a>

```
int32_t FormatDemuxerSelectTrack (const void * handle, int32_t programId, int32_t trackId )
```

 **Description:**

Selects a specified media track. 

The media tracks to select must belong to the same program. If you do not call this function, the default media tracks of the default program are selected. If  **programId**  is valid but  **trackId**  is invalid, the default media track of the specified program is used.

**Parameters:**

<a name="table1588651911165623"></a>
<table><thead align="left"><tr id="row803079733165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p505631359165623"><a name="p505631359165623"></a><a name="p505631359165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p975221900165623"><a name="p975221900165623"></a><a name="p975221900165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1672348625165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the demuxer context handle. </td>
</tr>
<tr id="row568357922165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">programId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Identifies the program. </td>
</tr>
<tr id="row1564911102165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">trackId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Identifies the media track. If a valid value is passed, the media track must belong to the specified program. If an invalid value is passed, the default media track of the specified program is used. If multiple audio tracks are specified, the player determines which audio track to use. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value otherwise. 

## FormatDemuxerSetBufferConfig\(\)<a name="gad2a15f3fa640f3f9e8e684d71b3a12cb"></a>

```
int32_t FormatDemuxerSetBufferConfig (void * handle, const [FormatBufferSetting](formatbuffersetting.md) * setting )
```

 **Description:**

Sets buffer information for the demuxer. 

If there is a buffer mechanism in the demuxer, you can call this function to set the maximum buffer size and time. Alternatively, you can disable the buffer mechanism by setting the buffer size and time to  **0**  in the  **setting**  parameter. If there is no buffer mechanism or the default setting is retained, you can skip this function.

**Parameters:**

<a name="table1985811549165623"></a>
<table><thead align="left"><tr id="row2028812295165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p762962810165623"><a name="p762962810165623"></a><a name="p762962810165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p490350057165623"><a name="p490350057165623"></a><a name="p490350057165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row267480296165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the demuxer context handle. </td>
</tr>
<tr id="row681339213165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">setting</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the maximum demuxer buffer size and time, as defined in <a href="formatbuffersetting.md">FormatBufferSetting</a>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value otherwise. 

## FormatDemuxerSetCallBack\(\)<a name="ga9ef126fc3132b556d49a275799e7753b"></a>

```
int32_t FormatDemuxerSetCallBack (void * handle, const [FormatCallback](formatcallback.md) * callBack )
```

 **Description:**

Sets a callback for the demuxer. 

The callback will be invoked to notify the upper layer of internal events of the demuxer.

**Parameters:**

<a name="table1947612759165623"></a>
<table><thead align="left"><tr id="row1092688202165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1158807656165623"><a name="p1158807656165623"></a><a name="p1158807656165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p374294062165623"><a name="p374294062165623"></a><a name="p374294062165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row531297258165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the demuxer context handle. </td>
</tr>
<tr id="row15182651165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">callBack</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the callback, as defined in <a href="formatcallback.md">FormatCallback</a>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value otherwise. 

## FormatDemuxerSetParameter\(\)<a name="ga92d859ba4745ce26b94595daaa40462d"></a>

```
int32_t FormatDemuxerSetParameter (const void * handle, int32_t trackId, const [ParameterItem](parameteritem.md) * metaData, int32_t metaDataCnt )
```

 **Description:**

Sets demuxer attributes. 

You can call this function to set the HTTP header, HTTP referer, and other extension items for the demuxer after  [FormatDemuxerCreate](format.md#ga183fbc31f2c9877ef56464abcccef374)  is called.

**Parameters:**

<a name="table495097228165623"></a>
<table><thead align="left"><tr id="row778730764165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1797078891165623"><a name="p1797078891165623"></a><a name="p1797078891165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p679012086165623"><a name="p679012086165623"></a><a name="p679012086165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row730637971165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the demuxer context handle. </td>
</tr>
<tr id="row866114026165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">trackId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Identifies the track. If the value is an invalid value (<strong id="b937163178165623"><a name="b937163178165623"></a><a name="b937163178165623"></a>-1</strong>), this parameter identifies the file or program. </td>
</tr>
<tr id="row1549061300165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">metaData</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to an array of key-value pairs representing parameter names and values. For details, see <a href="parameteritem.md">ParameterItem</a>. </td>
</tr>
<tr id="row1377596650165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">metaDataCnt</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the number of key-value pairs in the array. This parameter works in pair with <strong id="b164697193165623"><a name="b164697193165623"></a><a name="b164697193165623"></a>metaData</strong>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value otherwise. 

## FormatDemuxerStart\(\)<a name="ga08544b1ba3373bf5cb211586e8195673"></a>

```
int32_t FormatDemuxerStart (void * handle)
```

 **Description:**

Starts the demuxer. 

After being started, the caller can read data frames from the demuxer. This function should be called after  [FormatDemuxerPrepare](format.md#gacfcf40d869a48125bd67d17f8a4fc3ce)  is called.

**Parameters:**

<a name="table693189020165623"></a>
<table><thead align="left"><tr id="row1974631095165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1461705277165623"><a name="p1461705277165623"></a><a name="p1461705277165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1648012997165623"><a name="p1648012997165623"></a><a name="p1648012997165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row552386252165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the demuxer context handle. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value otherwise. 

## FormatDemuxerStop\(\)<a name="ga8a693d8be0b4b688d99e513608884e91"></a>

```
int32_t FormatDemuxerStop (void * handle)
```

 **Description:**

Stops the demuxer from working. 

After this function is called, the demuxer cannot resume decapsulation.

**Parameters:**

<a name="table576191848165623"></a>
<table><thead align="left"><tr id="row877518802165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1588792491165623"><a name="p1588792491165623"></a><a name="p1588792491165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p722372286165623"><a name="p722372286165623"></a><a name="p722372286165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2025783997165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the demuxer context handle. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value otherwise. 

## FormatDemuxerUnselectTrack\(\)<a name="gaf5fd5bab9613d133827054f157d5520e"></a>

```
int32_t FormatDemuxerUnselectTrack (const void * handle, int32_t programId, int32_t trackId )
```

 **Description:**

Unselects a specified media track from which the demuxer reads data frames. 

The demuxer can read all media tracks of the default program. You can call this function to unselect all or certain tracks of a specified program that the demuxer is expected not to read. If  **trackId**  is invalid, the demuxer will read none of the tracks of the specified program.

**Parameters:**

<a name="table2114959185165623"></a>
<table><thead align="left"><tr id="row617787292165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p118269805165623"><a name="p118269805165623"></a><a name="p118269805165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p202480713165623"><a name="p202480713165623"></a><a name="p202480713165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row544637757165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the demuxer context handle. </td>
</tr>
<tr id="row548590453165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">programId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Identifies the program. </td>
</tr>
<tr id="row1500206583165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">trackId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Identifies the media track that the demuxer will unselect. This parameter works in pair with <strong id="b480605923165623"><a name="b480605923165623"></a><a name="b480605923165623"></a>programId</strong>. If a valid value is passed, the media track must belong to the program specified by <strong id="b1818979826165623"><a name="b1818979826165623"></a><a name="b1818979826165623"></a>programId</strong>. If an invalid value is passed, and all media tracks of the specified program are unselected. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value otherwise. 

## FormatInit\(\)<a name="gae10a50c8f3de6e54ee0dc3937f755920"></a>

```
void FormatInit (void )
```

 **Description:**

Initializes the format. 

You can call this function to initialize the demuxer and muxer. This function should always be called before other format-specific functions, and it can be called only once within a process.

## FormatMuxerAddTrack\(\)<a name="ga94e9ab3e534b69a358b7cc16e4f79b78"></a>

```
int32_t FormatMuxerAddTrack (void * handle, const [TrackSource](tracksource.md) * trackSource )
```

 **Description:**

Adds a media track source for the muxer. For details about track sources, see  [TrackSource](tracksource.md). 

This function must be called after  [FormatMuxerCreate](format.md#ga9c390276cb90f4753c32af5aa5c600ad)  is successfully called and before  [FormatMuxerStart](format.md#ga9a2af831a6f4a63dc85d2c23b5c7c81b)  is called.

**Parameters:**

<a name="table271810108165623"></a>
<table><thead align="left"><tr id="row2042625667165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p730141422165623"><a name="p730141422165623"></a><a name="p730141422165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p22979370165623"><a name="p22979370165623"></a><a name="p22979370165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1775722626165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the muxer context handle. </td>
</tr>
<tr id="row1838844246165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">trackSource</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the track source. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value otherwise. 

## FormatMuxerCreate\(\)<a name="ga9c390276cb90f4753c32af5aa5c600ad"></a>

```
int32_t FormatMuxerCreate (void ** handle, [FormatOutputConfig](formatoutputconfig.md) * outputConfig )
```

 **Description:**

Creates a muxer and returns its context handle. 

**Parameters:**

<a name="table2098547994165623"></a>
<table><thead align="left"><tr id="row639127496165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p205416921165623"><a name="p205416921165623"></a><a name="p205416921165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p532297280165623"><a name="p532297280165623"></a><a name="p532297280165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row395657906165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double pointer to the muxer context handle. </td>
</tr>
<tr id="row318842842165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">outputConfig</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the muxer output configuration, as defined in <a href="formatoutputconfig.md">FormatOutputConfig</a>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value otherwise. 

## FormatMuxerDestory\(\)<a name="gaa41d46cef6d5e81c85614edbf824d803"></a>

```
int32_t FormatMuxerDestory (const void * handle)
```

 **Description:**

Destroys a muxer and release its resources created by calling  [FormatMuxerCreate](format.md#ga9c390276cb90f4753c32af5aa5c600ad). 

**Parameters:**

<a name="table1423590852165623"></a>
<table><thead align="left"><tr id="row68046168165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1486531270165623"><a name="p1486531270165623"></a><a name="p1486531270165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1683720792165623"><a name="p1683720792165623"></a><a name="p1683720792165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row150465303165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the muxer context handle. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value otherwise. 

## FormatMuxerGetParameter\(\)<a name="ga67dd7361dedf335496afef19d54e4138"></a>

```
int32_t FormatMuxerGetParameter (void * handle, int32_t trackId, [ParameterItem](parameteritem.md) * item, int32_t itemNum )
```

 **Description:**

Obtains muxer attributes. 

This is an extended function that can be used to obtain muxer or track attributes. The demuxer then obtains the muxer attributes based on the key contained in  **item**.

**Parameters:**

<a name="table969926964165623"></a>
<table><thead align="left"><tr id="row1570911261165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p411184138165623"><a name="p411184138165623"></a><a name="p411184138165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1355506705165623"><a name="p1355506705165623"></a><a name="p1355506705165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1675766586165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the muxer context handle. </td>
</tr>
<tr id="row1314896309165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">trackId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Identifies the media track. If the value is <a href="format.md#ga62037bb16334896e1bb6d35a71618881">FORMAT_INVALID_TRACK_ID</a>, this function obtains the muxer attributes. </td>
</tr>
<tr id="row1674701103165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">item</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the items carrying muxer attributes. You can specify multiple items at a time in this parameter, which works in pair with <strong id="b1960111600165623"><a name="b1960111600165623"></a><a name="b1960111600165623"></a>itemNum</strong>. </td>
</tr>
<tr id="row1416890924165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">itemNum</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the number of attributes set at a time. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value if any requested attribute fails to be obtained or is not found. 

## FormatMuxerSetCallBack\(\)<a name="ga108cd7e319ade568f71890d57585f153"></a>

```
int32_t FormatMuxerSetCallBack (void * handle, const [FormatCallback](formatcallback.md) * callBack )
```

 **Description:**

Sets a callback for the muxer. For details about the callback, see  [FormatCallback](formatcallback.md). 

This function should be called after  [FormatMuxerCreate](format.md#ga9c390276cb90f4753c32af5aa5c600ad)  is successfully called.

**Parameters:**

<a name="table1282559770165623"></a>
<table><thead align="left"><tr id="row634329998165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p642159109165623"><a name="p642159109165623"></a><a name="p642159109165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p465766571165623"><a name="p465766571165623"></a><a name="p465766571165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row656082507165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the muxer context handle. </td>
</tr>
<tr id="row1467777728165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><a href="formatcallback.md">FormatCallback</a></td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the muxer callback to set. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value otherwise. 

## FormatMuxerSetFileSplitDuration\(\)<a name="ga6eed6b5e7522e102f2d79d0dd33fd2a9"></a>

```
int32_t FormatMuxerSetFileSplitDuration (const void * handle, [ManualSplitType](format.md#ga10d9833450f29129d249c41d9acb4bc4) type, int64_t timestampUs, uint32_t durationUs )
```

 **Description:**

Manually splits a file. 

This function can be called after  [FormatMuxerStart](format.md#ga9a2af831a6f4a63dc85d2c23b5c7c81b)  is called. Once this function is called, the file is split based on the manual split type. After manual split is complete, file split will proceed to use the initially set split type. You can call this function again only after the  [MUXER\_INFO\_FILE\_SPLIT\_FINISHED](format.md#gga6f00342925d3d5e586c76f8695985cada3cf56a06f5990ab657d61bd7e57c1783)  event is reported.

**Parameters:**

<a name="table1631395484165623"></a>
<table><thead align="left"><tr id="row1179958510165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p398793829165623"><a name="p398793829165623"></a><a name="p398793829165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p511967123165623"><a name="p511967123165623"></a><a name="p511967123165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1106763678165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the muxer context handle. </td>
</tr>
<tr id="row1235804332165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">type</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the file split type, as defined in <strong id="b936627493165623"><a name="b936627493165623"></a><a name="b936627493165623"></a>FileSplitType</strong>. </td>
</tr>
<tr id="row1209681808165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">timestamp</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the file split timestamp. This parameter is not supported currently. The value <strong id="b1473603036165623"><a name="b1473603036165623"></a><a name="b1473603036165623"></a>�C1</strong> indicates that the file is split at the time this function is called. </td>
</tr>
<tr id="row185655918165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">duration</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the period from the file split time to the time the next output file starts. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value otherwise. 

## FormatMuxerSetLocation\(\)<a name="ga967ba14fa1231eed2942b87a09deb953"></a>

```
int32_t FormatMuxerSetLocation (const void * handle, int latitude, int longitude )
```

 **Description:**

Sets the geographical information for the output file of the muxer. 

This function should be called after  [FormatMuxerCreate](format.md#ga9c390276cb90f4753c32af5aa5c600ad)  is successfully called.

**Parameters:**

<a name="table994302964165623"></a>
<table><thead align="left"><tr id="row389135577165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1760239661165623"><a name="p1760239661165623"></a><a name="p1760239661165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1966483181165623"><a name="p1966483181165623"></a><a name="p1966483181165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row861906562165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the muxer context handle. </td>
</tr>
<tr id="row855769533165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">latitude</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the latitude, within the range [-90,90]. </td>
</tr>
<tr id="row675571600165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">longitude</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the longitude, within the range [-180,180]. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value otherwise. 

## FormatMuxerSetMaxFileDuration\(\)<a name="gae931061d822c4ffe447e9ba40a991597"></a>

```
int32_t FormatMuxerSetMaxFileDuration (void * handle, int64_t durationUs )
```

 **Description:**

Sets the maximum duration \(in seconds\) for the output file. 

You need to call this function before calling  [FormatMuxerStart](format.md#ga9a2af831a6f4a63dc85d2c23b5c7c81b). If the maximum duration you set is valid and capturing is approaching 90% of that duration or the remaining duration is 1s, the message  [MUXER\_INFO\_MAX\_DURATION\_APPROACHING](format.md#gga6f00342925d3d5e586c76f8695985cadaf6214216fd62faa4fc5e20d0d0ba60bf)  is reported via  **OnInfo**  of  [FormatCallback](formatcallback.md). If the output file has been set by calling  [FormatMuxerCreate](format.md#ga9c390276cb90f4753c32af5aa5c600ad), you need to call  [FormatMuxerSetNextOutputFile](format.md#gaa936b56996294d76977537267fef058c)  to set the next output file. Otherwise, the current output file will be overwritten when the capturing reaches the maximum duration you set.

**Parameters:**

<a name="table1252282379165623"></a>
<table><thead align="left"><tr id="row2120260222165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p286267502165623"><a name="p286267502165623"></a><a name="p286267502165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1693248866165623"><a name="p1693248866165623"></a><a name="p1693248866165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1107289587165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the muxer context handle. </td>
</tr>
<tr id="row1848380331165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">duration</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the maximum duration to set, in seconds. If the value is <strong id="b1184701914165623"><a name="b1184701914165623"></a><a name="b1184701914165623"></a>0</strong> or negative, the operation fails. In this case, the default duration (60 seconds) will be used. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value otherwise. 

## FormatMuxerSetMaxFileSize\(\)<a name="ga6f3ba422c9bbca4c1d5a7a3fe85dd9b9"></a>

```
int32_t FormatMuxerSetMaxFileSize (void * handle, int64_t bytes )
```

 **Description:**

Sets the maximum size \(in bytes\) for the output file of the muxer. 

This function should be called after  [FormatMuxerCreate](format.md#ga9c390276cb90f4753c32af5aa5c600ad)  is successfully called.

**Parameters:**

<a name="table1142210168165623"></a>
<table><thead align="left"><tr id="row2133787563165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p148865252165623"><a name="p148865252165623"></a><a name="p148865252165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1473590748165623"><a name="p1473590748165623"></a><a name="p1473590748165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row256048585165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the muxer context handle. </td>
</tr>
<tr id="row776889748165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">bytes</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the maximum size of a file, in bytes. If the value is <strong id="b1289247059165623"><a name="b1289247059165623"></a><a name="b1289247059165623"></a>0</strong> or negative, the operation fails and the maximum size does not take effect. In this case, the maximum size of a single file supported by the current file system is used as the value of this parameter. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value otherwise. 

## FormatMuxerSetNextOutputFile\(\)<a name="gaa936b56996294d76977537267fef058c"></a>

```
int32_t FormatMuxerSetNextOutputFile (const void * handle, int32_t fd )
```

 **Description:**

Sets the descriptor for the next output file. 

If  [FormatMuxerCreate](format.md#ga9c390276cb90f4753c32af5aa5c600ad)  is successfully called and the file descriptor involved is valid, you can call this function \(**FormatMuxerSetNextOutputFile**\) upon receiving the message  [MUXER\_INFO\_MAX\_FILESIZE\_APPROACHING](format.md#gga6f00342925d3d5e586c76f8695985cadafc74f41e73f13a29a83b3a13ea6e66e1)  or  [MUXER\_INFO\_MAX\_DURATION\_APPROACHING](format.md#gga6f00342925d3d5e586c76f8695985cadaf6214216fd62faa4fc5e20d0d0ba60bf).

**Parameters:**

<a name="table513919164165623"></a>
<table><thead align="left"><tr id="row88762387165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1624452863165623"><a name="p1624452863165623"></a><a name="p1624452863165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2065251626165623"><a name="p2065251626165623"></a><a name="p2065251626165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row872209939165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the muxer context handle. </td>
</tr>
<tr id="row598904512165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">fd</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the file descriptor to set. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value otherwise. 

## FormatMuxerSetOrientation\(\)<a name="ga96fc57913c3202d2d23704c69d660be5"></a>

```
int32_t FormatMuxerSetOrientation (void * handle, int degrees )
```

 **Description:**

Sets the orientation of the video track for the muxer. 

This function should be called after  [FormatMuxerAddTrack](format.md#ga94e9ab3e534b69a358b7cc16e4f79b78)  is successfully called. The following degrees are supported: 0, 90, 180, and 270.

**Parameters:**

<a name="table1609639404165623"></a>
<table><thead align="left"><tr id="row733667946165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p212005570165623"><a name="p212005570165623"></a><a name="p212005570165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p182631939165623"><a name="p182631939165623"></a><a name="p182631939165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1174062498165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the muxer context handle. </td>
</tr>
<tr id="row964141702165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">degrees</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the clockwise angle of the video track. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value otherwise. 

## FormatMuxerSetParameter\(\)<a name="gad4335ebaa7c165b885a00fe61aae0cd9"></a>

```
int32_t FormatMuxerSetParameter (void * handle, int32_t trackId, const [ParameterItem](parameteritem.md) * item, int32_t itemNum )
```

 **Description:**

Sets muxer attributes. 

This is an extended function that can be used to add MP4-dedicated boxes and tags \(such as  **exif**\).

**Parameters:**

<a name="table1771756380165623"></a>
<table><thead align="left"><tr id="row2015357116165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p289936181165623"><a name="p289936181165623"></a><a name="p289936181165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p950039448165623"><a name="p950039448165623"></a><a name="p950039448165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row72257298165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the muxer context handle. </td>
</tr>
<tr id="row1059026493165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">trackId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Identifies the media track. If the value is <a href="format.md#ga62037bb16334896e1bb6d35a71618881">FORMAT_INVALID_TRACK_ID</a>, this function sets the muxer attributes. </td>
</tr>
<tr id="row1165036665165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">item</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the items carrying muxer attributes. You can specify multiple items at a time in this parameter, which works in pair with <strong id="b240888249165623"><a name="b240888249165623"></a><a name="b240888249165623"></a>itemNum</strong>. </td>
</tr>
<tr id="row152666991165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">itemNum</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the number of attributes set at a time. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value otherwise. 

## FormatMuxerStart\(\)<a name="ga9a2af831a6f4a63dc85d2c23b5c7c81b"></a>

```
int32_t FormatMuxerStart (void * handle)
```

 **Description:**

Starts the muxer. 

You can call this function to encapsulate media data after the muxer is created, media tracks are added, and related parameters are set.

**Parameters:**

<a name="table1575551049165623"></a>
<table><thead align="left"><tr id="row954714052165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1111261193165623"><a name="p1111261193165623"></a><a name="p1111261193165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1489298613165623"><a name="p1489298613165623"></a><a name="p1489298613165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row21338737165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the muxer context handle. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value otherwise. 

## FormatMuxerStop\(\)<a name="ga66a3a5a1ec6d01fcbd6339f7eee1151b"></a>

```
int32_t FormatMuxerStop (const void * handle, bool block )
```

 **Description:**

Stops the muxer that was started by calling  [FormatMuxerStart](format.md#ga9a2af831a6f4a63dc85d2c23b5c7c81b). 

**Parameters:**

<a name="table482022292165623"></a>
<table><thead align="left"><tr id="row1660315023165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p587935967165623"><a name="p587935967165623"></a><a name="p587935967165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1748064948165623"><a name="p1748064948165623"></a><a name="p1748064948165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row490954492165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the muxer context handle. </td>
</tr>
<tr id="row1776944102165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">block</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates how to stop the muxer. The value <strong id="b1815213606165623"><a name="b1815213606165623"></a><a name="b1815213606165623"></a>true</strong> indicates that the muxer is stopped after all buffered data is processed, and <strong id="b774129730165623"><a name="b774129730165623"></a><a name="b774129730165623"></a>false</strong> indicates that the buffered data is discarded and the muxer is immediately stopped. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value otherwise. 

## FormatMuxerWriteFrame\(\)<a name="ga82037d271e77da206e16582e774ee048"></a>

```
int32_t FormatMuxerWriteFrame (const void * handle, const [FormatFrame](formatframe.md) * frameData )
```

 **Description:**

Writes data frames into the muxer. 

This function should be called after  [FormatMuxerCreate](format.md#ga9c390276cb90f4753c32af5aa5c600ad)  is successfully called.

**Parameters:**

<a name="table1220228983165623"></a>
<table><thead align="left"><tr id="row782959457165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1060352107165623"><a name="p1060352107165623"></a><a name="p1060352107165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1231379312165623"><a name="p1231379312165623"></a><a name="p1231379312165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row672186377165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the muxer context handle. </td>
</tr>
<tr id="row1462699303165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">frameData</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the data structure <a href="formatframe.md">FormatFrame</a>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value otherwise. 

