# OHOS::Media::Recorder<a name="EN-US_TOPIC_0000001054598177"></a>

-   [Overview](#section467185584165633)
-   [Summary](#section1317467736165633)
-   [Public Member Functions](#pub-methods)

## **Overview**<a name="section467185584165633"></a>

**Related Modules:**

[MultiMedia\_Recorder](multimedia_recorder.md)

**Description:**

Provides functions for audio and video recording. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1317467736165633"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table143014246165633"></a>
<table><thead align="left"><tr id="row339596745165633"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p366266763165633"><a name="p366266763165633"></a><a name="p366266763165633"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1263586020165633"><a name="p1263586020165633"></a><a name="p1263586020165633"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1250106293165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p566242044165633"><a name="p566242044165633"></a><a name="p566242044165633"></a><a href="multimedia_recorder.md#ga9e12ef9700d06c7620f9e3d7b4d844ca">SetVideoSource</a> (<a href="multimedia_recorder.md#gad252d27f9ce4b6ae0756bfeaa5f34490">VideoSourceType</a> source, int32_t &amp;sourceId)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p102084738165633"><a name="p102084738165633"></a><a name="p102084738165633"></a>int32_t </p>
<p id="p908000366165633"><a name="p908000366165633"></a><a name="p908000366165633"></a>Sets a video source for recording. </p>
</td>
</tr>
<tr id="row974998591165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p13356818165633"><a name="p13356818165633"></a><a name="p13356818165633"></a><a href="multimedia_recorder.md#gad9be6914af57fcf7acb7a5398118c614">SetVideoEncoder</a> (int32_t sourceId, <a href="multimedia_mediacommon.md#ga797e6c5e38e23e730eff5bcc41427d7e">VideoCodecFormat</a> encoder)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1603223949165633"><a name="p1603223949165633"></a><a name="p1603223949165633"></a>int32_t </p>
<p id="p2103019723165633"><a name="p2103019723165633"></a><a name="p2103019723165633"></a>Sets a video encoder for recording. </p>
</td>
</tr>
<tr id="row1120162373165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p53483968165633"><a name="p53483968165633"></a><a name="p53483968165633"></a><a href="multimedia_recorder.md#ga43c0ee5b76f58a12c2c745839184a96b">SetVideoSize</a> (int32_t sourceId, int32_t width, int32_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p894291560165633"><a name="p894291560165633"></a><a name="p894291560165633"></a>int32_t </p>
<p id="p90193403165633"><a name="p90193403165633"></a><a name="p90193403165633"></a>Sets the width and height of the video to record. </p>
</td>
</tr>
<tr id="row847218336165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p605294316165633"><a name="p605294316165633"></a><a name="p605294316165633"></a><a href="multimedia_recorder.md#gaeb90d4d75d80040aeaae354abd1d29d7">SetVideoFrameRate</a> (int32_t sourceId, int32_t frameRate)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2140590457165633"><a name="p2140590457165633"></a><a name="p2140590457165633"></a>int32_t </p>
<p id="p994253246165633"><a name="p994253246165633"></a><a name="p994253246165633"></a>Sets the frame rate of the video to record. </p>
</td>
</tr>
<tr id="row280372027165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p844081368165633"><a name="p844081368165633"></a><a name="p844081368165633"></a><a href="multimedia_recorder.md#ga4e05a76b50abf790f29f06a0c1d4ecb8">SetVideoEncodingBitRate</a> (int32_t sourceId, int32_t rate)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1548790628165633"><a name="p1548790628165633"></a><a name="p1548790628165633"></a>int32_t </p>
<p id="p420599176165633"><a name="p420599176165633"></a><a name="p420599176165633"></a>Sets the encoding bit rate of the video to record. </p>
</td>
</tr>
<tr id="row1702804086165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p137542384165633"><a name="p137542384165633"></a><a name="p137542384165633"></a><a href="multimedia_recorder.md#ga4f4a03fe881f48515874a699118fb84a">SetCaptureRate</a> (int32_t sourceId, double fps)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p261557995165633"><a name="p261557995165633"></a><a name="p261557995165633"></a>int32_t </p>
<p id="p252871828165633"><a name="p252871828165633"></a><a name="p252871828165633"></a>Sets the video capture rate. </p>
</td>
</tr>
<tr id="row312438250165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p729272663165633"><a name="p729272663165633"></a><a name="p729272663165633"></a><a href="multimedia_recorder.md#gad633e33fbbd5efcf4057aff3cc6e2b38">GetSurface</a> (int32_t sourceId)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p14127794165633"><a name="p14127794165633"></a><a name="p14127794165633"></a>std::shared_ptr&lt; <a href="ohos-surface.md">OHOS::Surface</a> &gt; </p>
<p id="p1984761631165633"><a name="p1984761631165633"></a><a name="p1984761631165633"></a>Obtains the surface of the video source. </p>
</td>
</tr>
<tr id="row1934877170165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1525281957165633"><a name="p1525281957165633"></a><a name="p1525281957165633"></a><a href="multimedia_recorder.md#gae287f59da8b3f1b6ca9f1c0e58a6565a">SetAudioSource</a> (<a href="multimedia_mediacommon.md#gadc3158e093b995ca7b9b6aa32388ccdd">AudioSourceType</a> source, int32_t &amp;sourceId)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1239201120165633"><a name="p1239201120165633"></a><a name="p1239201120165633"></a>int32_t </p>
<p id="p375194948165633"><a name="p375194948165633"></a><a name="p375194948165633"></a>Sets the audio source for recording. </p>
</td>
</tr>
<tr id="row786205736165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1890643059165633"><a name="p1890643059165633"></a><a name="p1890643059165633"></a><a href="multimedia_recorder.md#gab37c9385fa1a56f686beb73c7dcc1b1b">SetAudioEncoder</a> (int32_t sourceId, <a href="multimedia_mediacommon.md#gaa4ea6f314644ed287e0704be26c768b7">AudioCodecFormat</a> encoder)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p367255894165633"><a name="p367255894165633"></a><a name="p367255894165633"></a>int32_t </p>
<p id="p1438802539165633"><a name="p1438802539165633"></a><a name="p1438802539165633"></a>Sets an audio encoder for recording. </p>
</td>
</tr>
<tr id="row1448670746165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p848351319165633"><a name="p848351319165633"></a><a name="p848351319165633"></a><a href="multimedia_recorder.md#gab2b98616da55ec294053c0c25645c845">SetAudioSampleRate</a> (int32_t sourceId, int32_t rate)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1646521279165633"><a name="p1646521279165633"></a><a name="p1646521279165633"></a>int32_t </p>
<p id="p451676902165633"><a name="p451676902165633"></a><a name="p451676902165633"></a>Sets the audio sampling rate for recording. </p>
</td>
</tr>
<tr id="row2042672216165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1511307421165633"><a name="p1511307421165633"></a><a name="p1511307421165633"></a><a href="multimedia_recorder.md#ga77d76e5657cb3359e85521e08a456c7d">SetAudioChannels</a> (int32_t sourceId, int32_t num)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p988224107165633"><a name="p988224107165633"></a><a name="p988224107165633"></a>int32_t </p>
<p id="p92762083165633"><a name="p92762083165633"></a><a name="p92762083165633"></a>Sets the number of audio channels to record. </p>
</td>
</tr>
<tr id="row1204511977165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p696152686165633"><a name="p696152686165633"></a><a name="p696152686165633"></a><a href="multimedia_recorder.md#gac21a1a00c40cf58df84f1ba281b79a36">SetAudioEncodingBitRate</a> (int32_t sourceId, int32_t bitRate)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2069898144165633"><a name="p2069898144165633"></a><a name="p2069898144165633"></a>int32_t </p>
<p id="p688293203165633"><a name="p688293203165633"></a><a name="p688293203165633"></a>Sets the encoding bit rate of the audio to record. </p>
</td>
</tr>
<tr id="row396684159165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p335447475165633"><a name="p335447475165633"></a><a name="p335447475165633"></a><a href="multimedia_recorder.md#gaf2806f0fddd17a3e59eb7c5c740470d6">SetMaxDuration</a> (int32_t duration)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1552032738165633"><a name="p1552032738165633"></a><a name="p1552032738165633"></a>int32_t </p>
<p id="p336886165633"><a name="p336886165633"></a><a name="p336886165633"></a>Sets the maximum duration of a recorded file, in seconds. </p>
</td>
</tr>
<tr id="row82945246165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p772331002165633"><a name="p772331002165633"></a><a name="p772331002165633"></a><a href="multimedia_recorder.md#gaffb7874aae331570ecedfe609a495468">SetOutputFormat</a> (<a href="multimedia_recorder.md#ga3dfe2e61369bf1c081ce569e235354df">OutputFormatType</a> format)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p994296957165633"><a name="p994296957165633"></a><a name="p994296957165633"></a>int32_t </p>
<p id="p1212384510165633"><a name="p1212384510165633"></a><a name="p1212384510165633"></a>Sets the output file format. </p>
</td>
</tr>
<tr id="row1370460977165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p447803206165633"><a name="p447803206165633"></a><a name="p447803206165633"></a><a href="multimedia_recorder.md#gaa5c898c1ad051b5c9f115ef15d952f18">SetOutputPath</a> (const string &amp;path)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1089082162165633"><a name="p1089082162165633"></a><a name="p1089082162165633"></a>int32_t </p>
<p id="p1719118805165633"><a name="p1719118805165633"></a><a name="p1719118805165633"></a>Sets the output file path. </p>
</td>
</tr>
<tr id="row616348541165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p523045123165633"><a name="p523045123165633"></a><a name="p523045123165633"></a><a href="multimedia_recorder.md#ga500d2bc895852fe292d7397d8450d091">SetOutputFile</a> (int32_t fd)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1027451029165633"><a name="p1027451029165633"></a><a name="p1027451029165633"></a>int32_t </p>
<p id="p1184555618165633"><a name="p1184555618165633"></a><a name="p1184555618165633"></a>Sets the file descriptor (FD) of the output file. </p>
</td>
</tr>
<tr id="row506349261165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1105762733165633"><a name="p1105762733165633"></a><a name="p1105762733165633"></a><a href="multimedia_recorder.md#ga8545fe87eb4bd399525e4c5fb414d7cb">SetNextOutputFile</a> (int32_t fd)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1480971762165633"><a name="p1480971762165633"></a><a name="p1480971762165633"></a>int32_t </p>
<p id="p1024883276165633"><a name="p1024883276165633"></a><a name="p1024883276165633"></a>Sets the FD of the next output file. </p>
</td>
</tr>
<tr id="row817278468165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1334566110165633"><a name="p1334566110165633"></a><a name="p1334566110165633"></a><a href="multimedia_recorder.md#gaeed9ee49d9d1ac1497ec79bf9639c0bc">SetMaxFileSize</a> (int64_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1034949192165633"><a name="p1034949192165633"></a><a name="p1034949192165633"></a>int32_t </p>
<p id="p409312085165633"><a name="p409312085165633"></a><a name="p409312085165633"></a>Sets the maximum size of a recorded file, in bytes. </p>
</td>
</tr>
<tr id="row1431638596165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p62245360165633"><a name="p62245360165633"></a><a name="p62245360165633"></a><a href="multimedia_recorder.md#ga882585460b0538680954ce6692610376">SetRecorderCallback</a> (const std::shared_ptr&lt; <a href="ohos-media-recordercallback.md">RecorderCallback</a> &gt; &amp;callback)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1919096918165633"><a name="p1919096918165633"></a><a name="p1919096918165633"></a>int32_t </p>
<p id="p1150554915165633"><a name="p1150554915165633"></a><a name="p1150554915165633"></a>Registers a recording listener. </p>
</td>
</tr>
<tr id="row770903133165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p113696628165633"><a name="p113696628165633"></a><a name="p113696628165633"></a><a href="multimedia_recorder.md#ga15d2f3416bb735a0715e1e79be226387">Prepare</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p11043979165633"><a name="p11043979165633"></a><a name="p11043979165633"></a>int32_t </p>
<p id="p1150776007165633"><a name="p1150776007165633"></a><a name="p1150776007165633"></a>Prepares for recording. </p>
</td>
</tr>
<tr id="row278460740165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p418201693165633"><a name="p418201693165633"></a><a name="p418201693165633"></a><a href="multimedia_recorder.md#gac3aaa32627f0799dea65e51356b91bfb">Start</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1495412890165633"><a name="p1495412890165633"></a><a name="p1495412890165633"></a>int32_t </p>
<p id="p198633145165633"><a name="p198633145165633"></a><a name="p198633145165633"></a>Starts recording. </p>
</td>
</tr>
<tr id="row954418264165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1479822999165633"><a name="p1479822999165633"></a><a name="p1479822999165633"></a><a href="multimedia_recorder.md#ga71da5cc2720b336f0daadbe09d61c695">Pause</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1641682369165633"><a name="p1641682369165633"></a><a name="p1641682369165633"></a>int32_t </p>
<p id="p576145624165633"><a name="p576145624165633"></a><a name="p576145624165633"></a>Pauses recording. </p>
</td>
</tr>
<tr id="row112877340165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p419239796165633"><a name="p419239796165633"></a><a name="p419239796165633"></a><a href="multimedia_recorder.md#gafd32ed157821800936a258a73af936be">Resume</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1839889986165633"><a name="p1839889986165633"></a><a name="p1839889986165633"></a>int32_t </p>
<p id="p1140600411165633"><a name="p1140600411165633"></a><a name="p1140600411165633"></a>Resumes recording. </p>
</td>
</tr>
<tr id="row1287510981165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1208373272165633"><a name="p1208373272165633"></a><a name="p1208373272165633"></a><a href="multimedia_recorder.md#ga1253f753cf9ed01dae5d57a37524dfa7">Stop</a> (bool block)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p217018072165633"><a name="p217018072165633"></a><a name="p217018072165633"></a>int32_t </p>
<p id="p1180576065165633"><a name="p1180576065165633"></a><a name="p1180576065165633"></a>Stops recording. </p>
</td>
</tr>
<tr id="row1168502860165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2012029679165633"><a name="p2012029679165633"></a><a name="p2012029679165633"></a><a href="multimedia_recorder.md#gaebb808d5dd73b94b769b69e2b464c744">Reset</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1226091696165633"><a name="p1226091696165633"></a><a name="p1226091696165633"></a>int32_t </p>
<p id="p1764422601165633"><a name="p1764422601165633"></a><a name="p1764422601165633"></a>Resets the recording. </p>
</td>
</tr>
<tr id="row260258745165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1205411906165633"><a name="p1205411906165633"></a><a name="p1205411906165633"></a><a href="multimedia_recorder.md#ga116583c0d649f447c2dd272aae465cca">Release</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1369812567165633"><a name="p1369812567165633"></a><a name="p1369812567165633"></a>int32_t </p>
<p id="p683008274165633"><a name="p683008274165633"></a><a name="p683008274165633"></a>Releases recording resources. </p>
</td>
</tr>
<tr id="row564701217165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p881448884165633"><a name="p881448884165633"></a><a name="p881448884165633"></a><a href="multimedia_recorder.md#ga952ce2fada10d701e38e4ee29139e2af">SetFileSplitDuration</a> (<a href="multimedia_recorder.md#ga8759c7e5a74964a584a716f4ec0b7edb">FileSplitType</a> type, int64_t timestamp, uint32_t duration)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1093949538165633"><a name="p1093949538165633"></a><a name="p1093949538165633"></a>int32_t </p>
<p id="p1242152819165633"><a name="p1242152819165633"></a><a name="p1242152819165633"></a>Manually splits a video. </p>
</td>
</tr>
<tr id="row1006686441165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1415684991165633"><a name="p1415684991165633"></a><a name="p1415684991165633"></a><a href="multimedia_recorder.md#ga05cf279a460418b22d267527c83ede15">SetParameter</a> (int32_t sourceId, const <a href="ohos-media-format.md">Format</a> &amp;format)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1202674427165633"><a name="p1202674427165633"></a><a name="p1202674427165633"></a>int32_t </p>
<p id="p1679135654165633"><a name="p1679135654165633"></a><a name="p1679135654165633"></a>Sets an extended parameter for recording, for example, <strong id="b2137694699165633"><a name="b2137694699165633"></a><a name="b2137694699165633"></a>RCORDER_PRE_CACHE_DURATION</strong>. </p>
</td>
</tr>
</tbody>
</table>

