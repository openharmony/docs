# format\_type.h<a name="ZH-CN_TOPIC_0000001054918121"></a>

-   [Overview](#section1810931434165627)
-   [Summary](#section1600142835165627)
-   [Data Structures](#nested-classes)
-   [Macros](#define-members)
-   [Typedefs](#typedef-members)
-   [Enumerations](#enum-members)

## **Overview**<a name="section1810931434165627"></a>

**Related Modules:**

[Format](Format.md)

**Description:**

Declares format-related structures and enumerations, including custom data types for file information, programs, information about audio and video subtitle tracks, source data types, output data types, split types, and data frames. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1600142835165627"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table707372582165627"></a>
<table><thead align="left"><tr id="row584190355165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p357899371165627"><a name="p357899371165627"></a><a name="p357899371165627"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1250183526165627"><a name="p1250183526165627"></a><a name="p1250183526165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row633232628165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1192002204165627"><a name="p1192002204165627"></a><a name="p1192002204165627"></a><a href="FormatBufferSetting.md">FormatBufferSetting</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p476379870165627"><a name="p476379870165627"></a><a name="p476379870165627"></a>Defines the buffer configuration. </p>
</td>
</tr>
<tr id="row1049293646165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1185017210165627"><a name="p1185017210165627"></a><a name="p1185017210165627"></a><a href="FormatFrame.md">FormatFrame</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p318226972165627"><a name="p318226972165627"></a><a name="p318226972165627"></a>Defines the data frame, which is used for data transferring. </p>
</td>
</tr>
<tr id="row926454050165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1628199024165627"><a name="p1628199024165627"></a><a name="p1628199024165627"></a><a href="AudioTrackInfo.md">AudioTrackInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p712560562165627"><a name="p712560562165627"></a><a name="p712560562165627"></a>Defines audio track information. </p>
</td>
</tr>
<tr id="row1224109289165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p726484863165627"><a name="p726484863165627"></a><a name="p726484863165627"></a><a href="VideoTrackInfo.md">VideoTrackInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1319814050165627"><a name="p1319814050165627"></a><a name="p1319814050165627"></a>Defines video track information. </p>
</td>
</tr>
<tr id="row1624460974165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p534443193165627"><a name="p534443193165627"></a><a name="p534443193165627"></a><a href="SubImageInfo.md">SubImageInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p793641882165627"><a name="p793641882165627"></a><a name="p793641882165627"></a>Defines image information. </p>
</td>
</tr>
<tr id="row830396287165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1128272172165627"><a name="p1128272172165627"></a><a name="p1128272172165627"></a><a href="ImageTrackInfo.md">ImageTrackInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p635854460165627"><a name="p635854460165627"></a><a name="p635854460165627"></a>Defines image stream information. </p>
</td>
</tr>
<tr id="row1966600619165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1670343480165627"><a name="p1670343480165627"></a><a name="p1670343480165627"></a><a href="SubtitleTrackInfo.md">SubtitleTrackInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p972700690165627"><a name="p972700690165627"></a><a name="p972700690165627"></a>Defines subtitle stream information. </p>
</td>
</tr>
<tr id="row1932101252165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p406930579165627"><a name="p406930579165627"></a><a name="p406930579165627"></a><a href="TrackInfo.md">TrackInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p40296931165627"><a name="p40296931165627"></a><a name="p40296931165627"></a>Defines track information. </p>
</td>
</tr>
<tr id="row678950908165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p133503545165627"><a name="p133503545165627"></a><a name="p133503545165627"></a><a href="ProgramInfo.md">ProgramInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p755367827165627"><a name="p755367827165627"></a><a name="p755367827165627"></a>Defines program information. </p>
</td>
</tr>
<tr id="row1143461416165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p887734498165627"><a name="p887734498165627"></a><a name="p887734498165627"></a><a href="FileInfo.md">FileInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1923423884165627"><a name="p1923423884165627"></a><a name="p1923423884165627"></a>Defines movie file information. </p>
</td>
</tr>
<tr id="row1744893045165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p859215481165627"><a name="p859215481165627"></a><a name="p859215481165627"></a><a href="BufferStream.md">BufferStream</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p520219581165627"><a name="p520219581165627"></a><a name="p520219581165627"></a>Defines the function for reading stream data. </p>
</td>
</tr>
<tr id="row391108989165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p110983833165627"><a name="p110983833165627"></a><a name="p110983833165627"></a><a href="FormatSource.md">FormatSource</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1264348240165627"><a name="p1264348240165627"></a><a name="p1264348240165627"></a>Defines the demuxer data source. </p>
</td>
</tr>
<tr id="row1339017895165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p98456268165627"><a name="p98456268165627"></a><a name="p98456268165627"></a><a href="FormatOutputConfig.md">FormatOutputConfig</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1310279331165627"><a name="p1310279331165627"></a><a name="p1310279331165627"></a>Defines the muxer output configuration. </p>
</td>
</tr>
<tr id="row620432458165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p681996579165627"><a name="p681996579165627"></a><a name="p681996579165627"></a><a href="VideoTrackSourceInfo.md">VideoTrackSourceInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1115722856165627"><a name="p1115722856165627"></a><a name="p1115722856165627"></a>Defines information about the muxer video source. </p>
</td>
</tr>
<tr id="row283571307165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p687872330165627"><a name="p687872330165627"></a><a name="p687872330165627"></a><a href="AudioTrackSourceInfo.md">AudioTrackSourceInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p175339482165627"><a name="p175339482165627"></a><a name="p175339482165627"></a>Defines information about the muxer audio source. </p>
</td>
</tr>
<tr id="row984287560165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p256297504165627"><a name="p256297504165627"></a><a name="p256297504165627"></a><a href="DataTrackSourceInfo.md">DataTrackSourceInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1923975159165627"><a name="p1923975159165627"></a><a name="p1923975159165627"></a>Defines information about the muxer data source. </p>
</td>
</tr>
<tr id="row234046257165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1119242134165627"><a name="p1119242134165627"></a><a name="p1119242134165627"></a><a href="TrackSource.md">TrackSource</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p813937287165627"><a name="p813937287165627"></a><a name="p813937287165627"></a>Defines information about the muxer source. </p>
</td>
</tr>
<tr id="row1314082390165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1839270756165627"><a name="p1839270756165627"></a><a name="p1839270756165627"></a><a href="FormatCallback.md">FormatCallback</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1832208464165627"><a name="p1832208464165627"></a><a name="p1832208464165627"></a>Defines listener callbacks for the format. </p>
</td>
</tr>
</tbody>
</table>

## Macros<a name="define-members"></a>

<a name="table1601608652165627"></a>
<table><thead align="left"><tr id="row185844511165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p274118258165627"><a name="p274118258165627"></a><a name="p274118258165627"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1635818316165627"><a name="p1635818316165627"></a><a name="p1635818316165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row544557018165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p57516022165627"><a name="p57516022165627"></a><a name="p57516022165627"></a><a href="Format.md#gac2d2d077edb8e9bb9f85ab6350015c5b">FORMAT_MAX_LANGUAGE_NUM</a>   4</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">&nbsp;</td>
</tr>
<tr id="row1861832669165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p629306915165627"><a name="p629306915165627"></a><a name="p629306915165627"></a><a href="Format.md#gaa70508bb1089c99f9aa3d59fcbdfa8eb">FORMAT_LANGUAGE_LEN</a>   4</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">&nbsp;</td>
</tr>
<tr id="row764007021165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p978452386165627"><a name="p978452386165627"></a><a name="p978452386165627"></a><a href="Format.md#gadb635fac84a9d62e99c69e75d4de85c3">FORMAT_TITLE_LEN</a>   64</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">&nbsp;</td>
</tr>
<tr id="row770706374165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1871804345165627"><a name="p1871804345165627"></a><a name="p1871804345165627"></a><a href="Format.md#ga62037bb16334896e1bb6d35a71618881">FORMAT_INVALID_TRACK_ID</a>   -1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">&nbsp;</td>
</tr>
<tr id="row843561403165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p180175037165627"><a name="p180175037165627"></a><a name="p180175037165627"></a><a href="Format.md#gab4007b017f1edad143959af034e32bf7">FORMAT_INVALID_PROGRAM_ID</a>   -1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">&nbsp;</td>
</tr>
<tr id="row1074547157165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1495508781165627"><a name="p1495508781165627"></a><a name="p1495508781165627"></a><a href="Format.md#ga1ac54dd3b9b49c1800b5f502a87650be">URL_LEN</a>   4096</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">&nbsp;</td>
</tr>
</tbody>
</table>

## Typedefs<a name="typedef-members"></a>

<a name="table1350928372165627"></a>
<table><thead align="left"><tr id="row2045775428165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2028608554165627"><a name="p2028608554165627"></a><a name="p2028608554165627"></a>Typedef Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p191031610165627"><a name="p191031610165627"></a><a name="p191031610165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row132734363165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p902355713165627"><a name="p902355713165627"></a><a name="p902355713165627"></a><a href="Format.md#gab928f39c359734527bda3fd160f89331">CALLBACK_HANDLE</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p506458060165627"><a name="p506458060165627"></a><a name="p506458060165627"></a>typedef void * </p>
<p id="p388488856165627"><a name="p388488856165627"></a><a name="p388488856165627"></a>Indicates the pointer to the callback handle for listening the muxer. </p>
</td>
</tr>
</tbody>
</table>

## Enumerations<a name="enum-members"></a>

<a name="table787481507165627"></a>
<table><thead align="left"><tr id="row1453942993165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1806995090165627"><a name="p1806995090165627"></a><a name="p1806995090165627"></a>Enumeration Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1944069156165627"><a name="p1944069156165627"></a><a name="p1944069156165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row825027426165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p9813396165627"><a name="p9813396165627"></a><a name="p9813396165627"></a><a href="Format.md#gad495a9f61af7fff07d7e97979d1ab854">FrameType</a> {   <a href="Format.md#ggad495a9f61af7fff07d7e97979d1ab854a54c4b682d718fd6c8e5f224ee2fad841">FRAME_TYPE_NONE</a>, <a href="Format.md#ggad495a9f61af7fff07d7e97979d1ab854a709dd5ff367a8ff7669fda5386291796">FRAME_TYPE_AUDIO</a>, <a href="Format.md#ggad495a9f61af7fff07d7e97979d1ab854a7670f4378c84a94fb65f6c30c4b1a096">FRAME_TYPE_VIDEO</a>, <a href="Format.md#ggad495a9f61af7fff07d7e97979d1ab854a90bb6db5c310d60ccd4a6ec1b172e9e5">FRAME_TYPE_IMAGE</a>,   <a href="Format.md#ggad495a9f61af7fff07d7e97979d1ab854a3b43393b8fff68297e4daf0c32193704">FRAME_TYPE_SUB</a>, <a href="Format.md#ggad495a9f61af7fff07d7e97979d1ab854a75641aebcb420f0f661dc8acefdc9b30">FRAME_TYPE_DATA</a>, <a href="Format.md#ggad495a9f61af7fff07d7e97979d1ab854a7afc81a56325cb4a7356663ccd270931">FRAME_TYPE_BUT</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1066995931165627"><a name="p1066995931165627"></a><a name="p1066995931165627"></a>Enumerates data frame types. </p>
</td>
</tr>
<tr id="row1116655145165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1320926603165627"><a name="p1320926603165627"></a><a name="p1320926603165627"></a><a href="Format.md#ga14aa9d18a71eff4a0b70f748f0377c94">FormatSeekMode</a> { <a href="Format.md#gga14aa9d18a71eff4a0b70f748f0377c94a59c30f44f3b65ff91ee18441315dbbcc">FORMAT_SEEK_MODE_FORWARD_KEY</a>, <a href="Format.md#gga14aa9d18a71eff4a0b70f748f0377c94a00f9ebeb7f829675bde8cad3832efcdd">FORMAT_SEEK_MODE_BACKWARD_KEY</a>, <a href="Format.md#gga14aa9d18a71eff4a0b70f748f0377c94a605cab737a9cfc0a06f911efa117646d">FORMAT_SEEK_MODE_CLOSEST_KEY</a>, <a href="Format.md#gga14aa9d18a71eff4a0b70f748f0377c94a1a87eaf0f3e52132aba4563232a6f248">SEEK_MODE_BUT</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1382255229165627"><a name="p1382255229165627"></a><a name="p1382255229165627"></a>Enumerates seek modes. </p>
</td>
</tr>
<tr id="row121688647165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1131146107165627"><a name="p1131146107165627"></a><a name="p1131146107165627"></a><a href="Format.md#gaf7ed135f15d4b218d41705bac0122ba7">CodecFormat</a> {   <a href="Format.md#ggaf7ed135f15d4b218d41705bac0122ba7aa0c89a6d185559b38e63265976dde7f4">CODEC_H264</a> = 0, <a href="Format.md#ggaf7ed135f15d4b218d41705bac0122ba7a4adc0c5e441be1b1a642f481e3111cae">CODEC_H265</a>, <a href="Format.md#ggaf7ed135f15d4b218d41705bac0122ba7ab6432cb3fb17152277af1f486e182612">CODEC_JPEG</a>, <a href="Format.md#ggaf7ed135f15d4b218d41705bac0122ba7a8a0888876671d503c2c5e15059461c06">CODEC_AAC</a>,   <a href="Format.md#ggaf7ed135f15d4b218d41705bac0122ba7a44fd5227148450a7870e202d50110509">CODEC_G711A</a>, <a href="Format.md#ggaf7ed135f15d4b218d41705bac0122ba7a3ac447dc6b8707c70f6fc6d4e0c552d5">CODEC_G711U</a>, <a href="Format.md#ggaf7ed135f15d4b218d41705bac0122ba7ae3014fa1161193bc92227ea0895e1dfb">CODEC_PCM</a>, <a href="Format.md#ggaf7ed135f15d4b218d41705bac0122ba7a2a0119a66bcbe797c1bac3057a802c9a">CODEC_MP3</a>,   <a href="Format.md#ggaf7ed135f15d4b218d41705bac0122ba7a0bccf3a2f309d8c485283d386322f07b">CODEC_BUT</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1002013924165627"><a name="p1002013924165627"></a><a name="p1002013924165627"></a>Enumerates audio, video, and image encoding formats. </p>
</td>
</tr>
<tr id="row341097821165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p485141530165627"><a name="p485141530165627"></a><a name="p485141530165627"></a><a href="Format.md#gadf0700999998f587f0017c4d02977b22">AudioSampleFmt</a> {   <a href="Format.md#ggadf0700999998f587f0017c4d02977b22a650b7f83085e55b6e728fd3ec5beec50">AUDIO_SAMPLE_FMT_S8</a> = 0, <a href="Format.md#ggadf0700999998f587f0017c4d02977b22a40335eaa7ca378540941909ed02b51a0">AUDIO_SAMPLE_FMT_S16</a>, <a href="Format.md#ggadf0700999998f587f0017c4d02977b22af55ab2a69453af86f0c1602d3645f5f9">AUDIO_SAMPLE_FMT_S24</a>, <a href="Format.md#ggadf0700999998f587f0017c4d02977b22ab98feafb8396c0190a4fb719a15ab7c5">AUDIO_SAMPLE_FMT_S32</a>,   <a href="Format.md#ggadf0700999998f587f0017c4d02977b22ac2fb27a42b3f79e51dd71ce05b42f9db">AUDIO_SAMPLE_FMT_FLOAT</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p869303250165627"><a name="p869303250165627"></a><a name="p869303250165627"></a>Enumerates audio sampling formats. </p>
</td>
</tr>
<tr id="row105931313165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1809001533165627"><a name="p1809001533165627"></a><a name="p1809001533165627"></a><a href="Format.md#ga43b7f046e365a89697272d850b0517b7">SubtitleFrameType</a> { <a href="Format.md#gga43b7f046e365a89697272d850b0517b7a6bc8b3dca40c75f6dd22feea62cbdac7">HI_SVR_SUBTITLE_BITMAP</a> = 0x0, <a href="Format.md#gga43b7f046e365a89697272d850b0517b7a3ee7a0476e395ec2689f754e58d512a0">HI_SVR_SUBTITLE_TEXT</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p572033718165627"><a name="p572033718165627"></a><a name="p572033718165627"></a>Enumerates subtitle frame types. </p>
</td>
</tr>
<tr id="row1408754441165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p230231255165627"><a name="p230231255165627"></a><a name="p230231255165627"></a><a href="Format.md#gadac45ce4731516c262292c15433439b3">SubtitleFormat</a> {   <a href="Format.md#ggadac45ce4731516c262292c15433439b3abe03cb7d3bb87dcfc197b9e9db7a66f6">FORMAT_SUB_ASS</a> = 0x0, <a href="Format.md#ggadac45ce4731516c262292c15433439b3a569e5e22b1c3bf5b9f4cc3f596cfc6db">FORMAT_SUB_LRC</a>, <a href="Format.md#ggadac45ce4731516c262292c15433439b3a26f41cfe561866b43a9757b5902c7609">FORMAT_SUB_SRT</a>, <a href="Format.md#ggadac45ce4731516c262292c15433439b3ac6665b95ccb70e7a7d87dda6370821ff">FORMAT_SUB_SMI</a>,   <a href="Format.md#ggadac45ce4731516c262292c15433439b3a07a0a164bb0081359639cfdef57aa2c2">FORMAT_SUB_SUB</a>, <a href="Format.md#ggadac45ce4731516c262292c15433439b3a5ad9a3ec464416e8395e3e0f6595c253">FORMAT_SUB_TXT</a>, <a href="Format.md#ggadac45ce4731516c262292c15433439b3a9f573cd39fab8fc143480bf1eb973574">FORMAT_SUB_HDMV_PGS</a>, <a href="Format.md#ggadac45ce4731516c262292c15433439b3a641b27aab74dbbcd88d7d8612b60caad">FORMAT_SUB_DVB_SUB</a>,   <a href="Format.md#ggadac45ce4731516c262292c15433439b3a91ab0e8c1931fc3b4f2350a8e18672a6">FORMAT_SUB_DVD_SUB</a>, <a href="Format.md#ggadac45ce4731516c262292c15433439b3a0750bc81000513246d5785d0ef2c0099">FORMAT_SUB_TTML</a>, <a href="Format.md#ggadac45ce4731516c262292c15433439b3ad9de45a6ae50e5443e2d0418b1cdde61">FORMAT_SUB_WEBVTT</a>, <a href="Format.md#ggadac45ce4731516c262292c15433439b3a52ed4b60bc3d33d43753555e1edf50d7">FORMAT_SUB_BUTT</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p629101636165627"><a name="p629101636165627"></a><a name="p629101636165627"></a>Enumerates subtitle file formats. </p>
</td>
</tr>
<tr id="row1172844999165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1125185989165627"><a name="p1125185989165627"></a><a name="p1125185989165627"></a><a href="Format.md#gad80740dd555f7d3688d2c4d9f44d3b04">TrackType</a> {   <a href="Format.md#ggad80740dd555f7d3688d2c4d9f44d3b04aae00a139d1f3bbfef9dbda6803497b62">TRACK_TYPE_VIDEO</a>, <a href="Format.md#ggad80740dd555f7d3688d2c4d9f44d3b04aab84be45f332c1bd8ab31d9404c6d944">TRACK_TYPE_AUDIO</a>, <a href="Format.md#ggad80740dd555f7d3688d2c4d9f44d3b04a3c834b6afb84a38aa490253a3abc5f66">TRACK_TYPE_IMAGE</a>, <a href="Format.md#ggad80740dd555f7d3688d2c4d9f44d3b04aff6cb64c75689ea5b11063e0984956f4">TRACK_TYPE_SUB</a>,   <a href="Format.md#ggad80740dd555f7d3688d2c4d9f44d3b04abe0c58f8c0a492959631b8f41dbe2af7">TRACK_TYPE_DATA</a>, <a href="Format.md#ggad80740dd555f7d3688d2c4d9f44d3b04ad3a1729659a9a6453a2d2bda67cb2c22">TRACK_TYPE_BUT</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1424675836165627"><a name="p1424675836165627"></a><a name="p1424675836165627"></a>Enumerates track types. </p>
</td>
</tr>
<tr id="row634787354165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1251595560165627"><a name="p1251595560165627"></a><a name="p1251595560165627"></a><a href="Format.md#gacff079fdf8427c743f9197ea5be33a7f">DataFlags</a> {   <a href="Format.md#ggacff079fdf8427c743f9197ea5be33a7faf5d58e6ec118e0660b53c7a7df2fdc8b">DATA_FLAG_NONE</a> = 0, <a href="Format.md#ggacff079fdf8427c743f9197ea5be33a7fad000cf60ee0b16f1ea7fedbcdb1a9fa0">DATA_FLAG_SYNCFRAME</a> = 1, <a href="Format.md#ggacff079fdf8427c743f9197ea5be33a7fa9200ae4b5fc3c72f2e70c9a49c2ebbb0">DATA_FLAG_CODECCONFIG</a> = 2, <a href="Format.md#ggacff079fdf8427c743f9197ea5be33a7fabaa169afc64ef32b743217c8194fd8b9">DATA_FLAG_EOS</a> = 4,   <a href="Format.md#ggacff079fdf8427c743f9197ea5be33a7fa26019220bb1298308f5c3dcd8a071f63">DATA_FLAG_PARTIAL_FRAME</a> = 8, <a href="Format.md#ggacff079fdf8427c743f9197ea5be33a7fa5fd5b55061c6e94a8a12f9cf9d2009a7">DATA_FLAG_ENDOFFRAME</a> = 16, <a href="Format.md#ggacff079fdf8427c743f9197ea5be33a7faeb92d052f544e6cde910fb669790a804">DATA_FLAG_MUXER_DATA</a> = 32 }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p106027910165627"><a name="p106027910165627"></a><a name="p106027910165627"></a>Enumerates flags of raw stream data. </p>
</td>
</tr>
<tr id="row789648906165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p37787105165627"><a name="p37787105165627"></a><a name="p37787105165627"></a><a href="Format.md#ga3ae727773c367ac1041d72ac770a0ab1">SourceType</a> { <a href="Format.md#gga3ae727773c367ac1041d72ac770a0ab1a126568132b92d49365d94c4aa00cdde4">SOURCE_TYPE_FD</a> = 0, <a href="Format.md#gga3ae727773c367ac1041d72ac770a0ab1a70d32ea5aeaa325764508722ba31403c">SOURCE_TYPE_URI</a>, <a href="Format.md#gga3ae727773c367ac1041d72ac770a0ab1a7f632a791d8f6dfbe5940b5648d29e6c">SOURCE_TYPE_STREAM</a>, <a href="Format.md#gga3ae727773c367ac1041d72ac770a0ab1ad41c2f0bdca46364d6cd86fc5d4710d3">SOURCE_TYPE_BUT</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p762309761165627"><a name="p762309761165627"></a><a name="p762309761165627"></a>Enumerates types of the demuxer data source. </p>
</td>
</tr>
<tr id="row491578216165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1741662106165627"><a name="p1741662106165627"></a><a name="p1741662106165627"></a><a href="Format.md#gaeb712c6c6c0a8af0dfd79f451ecb9277">OutputFormat</a> {   <a href="Format.md#ggaeb712c6c6c0a8af0dfd79f451ecb9277a5a01488de2f310872db03b7a6ad26423">OUTPUT_FORMAT_MPEG_4</a> = 0, <a href="Format.md#ggaeb712c6c6c0a8af0dfd79f451ecb9277a9eaec301329c61d07d2fe19ca473abc2">OUTPUT_FORMAT_TS</a> = 1, <a href="Format.md#ggaeb712c6c6c0a8af0dfd79f451ecb9277a3a0cc99ed9dcc44245dd91591b7accac">OUTPUT_FORMAT_THREE_GPP</a> = 2, <a href="Format.md#ggaeb712c6c6c0a8af0dfd79f451ecb9277a68afc7e60f3cdacd5e1fb9a5dcf0ebdb">OUTPUT_FORMAT_HEIF</a> = 3,   <a href="Format.md#ggaeb712c6c6c0a8af0dfd79f451ecb9277abb34ec8353ace07dbfd698c05343800d">OUTPUT_FORMAT_OGG</a> = 4, <a href="Format.md#ggaeb712c6c6c0a8af0dfd79f451ecb9277a00eb675fb0d802a5143f4f718ea854e3">OUTPUT_FORMAT_INVALID</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1494490223165627"><a name="p1494490223165627"></a><a name="p1494490223165627"></a>Enumerates output file formats. </p>
</td>
</tr>
<tr id="row1469122608165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p653205725165627"><a name="p653205725165627"></a><a name="p653205725165627"></a><a href="Format.md#ga6f00342925d3d5e586c76f8695985cad">FormatInfoType</a> {   <a href="Format.md#gga6f00342925d3d5e586c76f8695985cadaf6214216fd62faa4fc5e20d0d0ba60bf">MUXER_INFO_MAX_DURATION_APPROACHING</a> = 0, <a href="Format.md#gga6f00342925d3d5e586c76f8695985cadafc74f41e73f13a29a83b3a13ea6e66e1">MUXER_INFO_MAX_FILESIZE_APPROACHING</a>, <a href="Format.md#gga6f00342925d3d5e586c76f8695985cada9722ce52063f6247d5fb17470eb9559e">MUXER_INFO_MAX_DURATION_REACHED</a>, <a href="Format.md#gga6f00342925d3d5e586c76f8695985cada71704a053cf3e30c7bf91522b27da8c2">MUXER_INFO_MAX_FILESIZE_REACHED</a>,   <a href="Format.md#gga6f00342925d3d5e586c76f8695985cadae63cbc02cf7dc61073b739c08cc58ff4">MUXER_INFO_NEXT_OUTPUT_FILE_STARTED</a>, <a href="Format.md#gga6f00342925d3d5e586c76f8695985cada3cf56a06f5990ab657d61bd7e57c1783">MUXER_INFO_FILE_SPLIT_FINISHED</a>, <a href="Format.md#gga6f00342925d3d5e586c76f8695985cada5d3901c368e7a4f719134c98c4fa8313">MUXER_INFO_FILE_START_TIME_MS</a>, <a href="Format.md#gga6f00342925d3d5e586c76f8695985cadaeb00ffb6342b7ede6b5efe81fa842374">DEMUXER_INFO_PREPARED</a> = 10000,   <a href="Format.md#gga6f00342925d3d5e586c76f8695985cada929a71c6b58dfcd974e960b99139a758">DEMUXER_INFO_SEEK_COMPLETE</a>, <a href="Format.md#gga6f00342925d3d5e586c76f8695985cada2c4b1c086d55b4d5bf3fedbbf115cf63">DEMUXER_INFO_NETWORK_DISCONNECTED</a>, <a href="Format.md#gga6f00342925d3d5e586c76f8695985cadac157e535a1828f3b87c9cc3e6fd8773b">DEMUXER_INFO_NETWORK_RECONNECTED</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p348063854165627"><a name="p348063854165627"></a><a name="p348063854165627"></a>Enumerates types of callback information. </p>
</td>
</tr>
<tr id="row113281929165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p775738603165627"><a name="p775738603165627"></a><a name="p775738603165627"></a><a href="Format.md#ga31e7fcf42722fa15e4e5489c2fef9092">FormatErrorType</a> </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1067801688165627"><a name="p1067801688165627"></a><a name="p1067801688165627"></a>Enumerates callback error types. </p>
</td>
</tr>
<tr id="row1411046732165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1306696371165627"><a name="p1306696371165627"></a><a name="p1306696371165627"></a><a href="Format.md#ga4e0517338e6c4a31a2addafc06d4f3a3">OutputType</a> { <a href="Format.md#gga4e0517338e6c4a31a2addafc06d4f3a3a14ea73c5ea45e0f9b6976d24ac1119e9">OUTPUT_TYPE_FD</a> = 0, <a href="Format.md#gga4e0517338e6c4a31a2addafc06d4f3a3a67f14fbe9f23ae5acd2ffc7b00fd6740">OUTPUT_TYPE_URI</a>, <a href="Format.md#gga4e0517338e6c4a31a2addafc06d4f3a3a169d19953026c9c3fed4e4433624ca7c">OUTPUT_TYPE_INVALID</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1934239769165627"><a name="p1934239769165627"></a><a name="p1934239769165627"></a>Enumerates muxer output types. </p>
</td>
</tr>
<tr id="row2086442104165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p880164004165627"><a name="p880164004165627"></a><a name="p880164004165627"></a><a href="Format.md#ga10d9833450f29129d249c41d9acb4bc4">ManualSplitType</a> { <a href="Format.md#gga10d9833450f29129d249c41d9acb4bc4ad283396b08ef486b6615977c881a8724">MANUAL_SPLIT_POST</a> = 0, <a href="Format.md#gga10d9833450f29129d249c41d9acb4bc4ae1c9eea90aaf796ffc5932cc50548716">MANUAL_SPLIT_PRE</a>, <a href="Format.md#gga10d9833450f29129d249c41d9acb4bc4a2b3ef6d50352019e54db9736e6dde05e">MANUAL_SPLIT_NORMAL</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p135985016165627"><a name="p135985016165627"></a><a name="p135985016165627"></a>Enumerates manual split types for the muxer. </p>
</td>
</tr>
<tr id="row761992679165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1351064282165627"><a name="p1351064282165627"></a><a name="p1351064282165627"></a><a href="Format.md#ga953bc46f95d7b2d8866838d792f8f6aa">TrackSourceType</a> { <a href="Format.md#gga953bc46f95d7b2d8866838d792f8f6aaa59d8c33314397a4ae8c1ca7b9e4eb40f">TRACK_SOURCE_TYPE_VIDEO</a> = 0, <a href="Format.md#gga953bc46f95d7b2d8866838d792f8f6aaa5e9f39cae59134e444907af8b372b7a4">TRACK_SOURCE_TYPE_AUDIO</a>, <a href="Format.md#gga953bc46f95d7b2d8866838d792f8f6aaa5d0d794425327268d08990d26a21f50c">TRACK_SOURCE_TYPE_DATA</a>, <a href="Format.md#gga953bc46f95d7b2d8866838d792f8f6aaa0fae189aab417f7c9756523f15a20cca">TRACK_SOURCE_TYPE_INVALID</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1341173228165627"><a name="p1341173228165627"></a><a name="p1341173228165627"></a>Enumerates types of the muxer source track. </p>
</td>
</tr>
</tbody>
</table>

