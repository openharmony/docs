# format\_interface.h<a name="EN-US_TOPIC_0000001054598127"></a>

-   [Overview](#section515357501165627)
-   [Summary](#section1550078186165627)
-   [Functions](#func-members)

## **Overview**<a name="section515357501165627"></a>

**Related Modules:**

[Format](format.md)

**Description:**

Declares format-related APIs. 

For example, you use the functions provided in this file to define custom data types and to initialize, create, destroy the muxer and demuxer, and set their parameters. Also, you can read demuxer data frames, select demuxer tracks, add muxer tracks, and write data frames into a container.

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1550078186165627"></a>

## Functions<a name="func-members"></a>

<a name="table1710821664165627"></a>
<table><thead align="left"><tr id="row1391618758165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1691244625165627"><a name="p1691244625165627"></a><a name="p1691244625165627"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1035835868165627"><a name="p1035835868165627"></a><a name="p1035835868165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1165695674165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p100149459165627"><a name="p100149459165627"></a><a name="p100149459165627"></a><a href="format.md#gae10a50c8f3de6e54ee0dc3937f755920">FormatInit</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p630665307165627"><a name="p630665307165627"></a><a name="p630665307165627"></a>void </p>
<p id="p2105804899165627"><a name="p2105804899165627"></a><a name="p2105804899165627"></a>Initializes the format. </p>
</td>
</tr>
<tr id="row1021231664165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p813852159165627"><a name="p813852159165627"></a><a name="p813852159165627"></a><a href="format.md#gabb574933ebb4f3d1d2ed299e79aeee2c">FormatDeInit</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1093887722165627"><a name="p1093887722165627"></a><a name="p1093887722165627"></a>void </p>
<p id="p542054498165627"><a name="p542054498165627"></a><a name="p542054498165627"></a>Deinitializes the format. </p>
</td>
</tr>
<tr id="row112841053165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1247494105165627"><a name="p1247494105165627"></a><a name="p1247494105165627"></a><a href="format.md#ga183fbc31f2c9877ef56464abcccef374">FormatDemuxerCreate</a> (const <a href="formatsource.md">FormatSource</a> *source, void **handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p753191972165627"><a name="p753191972165627"></a><a name="p753191972165627"></a>int32_t </p>
<p id="p2001005608165627"><a name="p2001005608165627"></a><a name="p2001005608165627"></a>Creates a demuxer component and returns its context handle. </p>
</td>
</tr>
<tr id="row1564488296165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1056728134165627"><a name="p1056728134165627"></a><a name="p1056728134165627"></a><a href="format.md#ga92d859ba4745ce26b94595daaa40462d">FormatDemuxerSetParameter</a> (const void *handle, int32_t trackId, const <a href="parameteritem.md">ParameterItem</a> *metaData, int32_t metaDataCnt)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1400440562165627"><a name="p1400440562165627"></a><a name="p1400440562165627"></a>int32_t </p>
<p id="p792205709165627"><a name="p792205709165627"></a><a name="p792205709165627"></a>Sets demuxer attributes. </p>
</td>
</tr>
<tr id="row1183756339165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p262805825165627"><a name="p262805825165627"></a><a name="p262805825165627"></a><a href="format.md#ga6c2a1aa9fdf1db8e2f14a3a92ffa23d5">FormatDemuxerGetParameter</a> (const void *handle, int32_t trackId, <a href="parameteritem.md">ParameterItem</a> *metaData)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2141978025165627"><a name="p2141978025165627"></a><a name="p2141978025165627"></a>int32_t </p>
<p id="p1446368932165627"><a name="p1446368932165627"></a><a name="p1446368932165627"></a>Obtains demuxer attributes. </p>
</td>
</tr>
<tr id="row431512608165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1157619831165627"><a name="p1157619831165627"></a><a name="p1157619831165627"></a><a href="format.md#ga9ef126fc3132b556d49a275799e7753b">FormatDemuxerSetCallBack</a> (void *handle, const <a href="formatcallback.md">FormatCallback</a> *callBack)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p624675043165627"><a name="p624675043165627"></a><a name="p624675043165627"></a>int32_t </p>
<p id="p383665297165627"><a name="p383665297165627"></a><a name="p383665297165627"></a>Sets a callback for the demuxer. </p>
</td>
</tr>
<tr id="row1302092972165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1283241006165627"><a name="p1283241006165627"></a><a name="p1283241006165627"></a><a href="format.md#gad2a15f3fa640f3f9e8e684d71b3a12cb">FormatDemuxerSetBufferConfig</a> (void *handle, const <a href="formatbuffersetting.md">FormatBufferSetting</a> *setting)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p188585497165627"><a name="p188585497165627"></a><a name="p188585497165627"></a>int32_t </p>
<p id="p837436757165627"><a name="p837436757165627"></a><a name="p837436757165627"></a>Sets buffer information for the demuxer. </p>
</td>
</tr>
<tr id="row1174139392165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1430235551165627"><a name="p1430235551165627"></a><a name="p1430235551165627"></a><a href="format.md#ga565cbb52c95a95aab4dcc957fe998b5f">FormatDemuxerGetBufferConfig</a> (const void *handle, <a href="formatbuffersetting.md">FormatBufferSetting</a> *setting)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2030223520165627"><a name="p2030223520165627"></a><a name="p2030223520165627"></a>int32_t </p>
<p id="p2125741251165627"><a name="p2125741251165627"></a><a name="p2125741251165627"></a>Obtains the buffer information of the demuxer. </p>
</td>
</tr>
<tr id="row120563301165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1468921609165627"><a name="p1468921609165627"></a><a name="p1468921609165627"></a><a href="format.md#gacfcf40d869a48125bd67d17f8a4fc3ce">FormatDemuxerPrepare</a> (void *handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p73266648165627"><a name="p73266648165627"></a><a name="p73266648165627"></a>int32_t </p>
<p id="p1397172234165627"><a name="p1397172234165627"></a><a name="p1397172234165627"></a>Makes preparations for the demuxer. </p>
</td>
</tr>
<tr id="row994326264165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1122625086165627"><a name="p1122625086165627"></a><a name="p1122625086165627"></a><a href="format.md#gad807d61c65e89629c7eed8f97426fd5a">FormatDemuxerGetFileInfo</a> (void *handle, <a href="fileinfo.md">FileInfo</a> *info)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p520531220165627"><a name="p520531220165627"></a><a name="p520531220165627"></a>int32_t </p>
<p id="p559197355165627"><a name="p559197355165627"></a><a name="p559197355165627"></a>Obtains the attributes of a media file. </p>
</td>
</tr>
<tr id="row125690927165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p347968507165627"><a name="p347968507165627"></a><a name="p347968507165627"></a><a href="format.md#ga1d9cb94614e207def34f13eaa16ef2b7">FormatDemuxerSelectTrack</a> (const void *handle, int32_t programId, int32_t trackId)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1339691209165627"><a name="p1339691209165627"></a><a name="p1339691209165627"></a>int32_t </p>
<p id="p1738159284165627"><a name="p1738159284165627"></a><a name="p1738159284165627"></a>Selects a specified media track. </p>
</td>
</tr>
<tr id="row1306143331165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1462661643165627"><a name="p1462661643165627"></a><a name="p1462661643165627"></a><a href="format.md#gaf5fd5bab9613d133827054f157d5520e">FormatDemuxerUnselectTrack</a> (const void *handle, int32_t programId, int32_t trackId)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p748674099165627"><a name="p748674099165627"></a><a name="p748674099165627"></a>int32_t </p>
<p id="p1917910013165627"><a name="p1917910013165627"></a><a name="p1917910013165627"></a>Unselects a specified media track from which the demuxer reads data frames. </p>
</td>
</tr>
<tr id="row948702713165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1897668229165627"><a name="p1897668229165627"></a><a name="p1897668229165627"></a><a href="format.md#ga08544b1ba3373bf5cb211586e8195673">FormatDemuxerStart</a> (void *handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1911684038165627"><a name="p1911684038165627"></a><a name="p1911684038165627"></a>int32_t </p>
<p id="p1259747235165627"><a name="p1259747235165627"></a><a name="p1259747235165627"></a>Starts the demuxer. </p>
</td>
</tr>
<tr id="row1130612156165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1085510606165627"><a name="p1085510606165627"></a><a name="p1085510606165627"></a><a href="format.md#gab6ef68051ee2ed0015e721bedb1af61c">FormatDemuxerGetSelectedTrack</a> (const void *handle, int32_t *programId, int32_t trackId[], int32_t *nums)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1200625913165627"><a name="p1200625913165627"></a><a name="p1200625913165627"></a>int32_t </p>
<p id="p697336322165627"><a name="p697336322165627"></a><a name="p697336322165627"></a>Obtains the ID of the media track selected by the demuxer for output. </p>
</td>
</tr>
<tr id="row344709899165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p688854786165627"><a name="p688854786165627"></a><a name="p688854786165627"></a><a href="format.md#ga7b20e1b88413d20a348d7f796917cd94">FormatDemuxerReadFrame</a> (const void *handle, <a href="formatframe.md">FormatFrame</a> *frame, int32_t timeOutMs)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1326122720165627"><a name="p1326122720165627"></a><a name="p1326122720165627"></a>int32_t </p>
<p id="p879777683165627"><a name="p879777683165627"></a><a name="p879777683165627"></a>Reads data frames. </p>
</td>
</tr>
<tr id="row1272578872165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1092467200165627"><a name="p1092467200165627"></a><a name="p1092467200165627"></a><a href="format.md#ga291b805de194c695b72eb5ad721103d5">FormatDemuxerFreeFrame</a> (void *handle, <a href="formatframe.md">FormatFrame</a> *frame)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p355241808165627"><a name="p355241808165627"></a><a name="p355241808165627"></a>int32_t </p>
<p id="p1990097380165627"><a name="p1990097380165627"></a><a name="p1990097380165627"></a>Frees data frames. </p>
</td>
</tr>
<tr id="row2133323030165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1160213345165627"><a name="p1160213345165627"></a><a name="p1160213345165627"></a><a href="format.md#gad53f1e848f3c2e0c8fa056a312b2ed6c">FormatDemuxerSeek</a> (const void *handle, int32_t streamIndex, int64_t timeStampUs, <a href="format.md#ga14aa9d18a71eff4a0b70f748f0377c94">FormatSeekMode</a> mode)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2069324750165627"><a name="p2069324750165627"></a><a name="p2069324750165627"></a>int32_t </p>
<p id="p663007822165627"><a name="p663007822165627"></a><a name="p663007822165627"></a>Seeks for a specified position for the demuxer. </p>
</td>
</tr>
<tr id="row1991493811165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1949458871165627"><a name="p1949458871165627"></a><a name="p1949458871165627"></a><a href="format.md#ga8a693d8be0b4b688d99e513608884e91">FormatDemuxerStop</a> (void *handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p837935701165627"><a name="p837935701165627"></a><a name="p837935701165627"></a>int32_t </p>
<p id="p603125994165627"><a name="p603125994165627"></a><a name="p603125994165627"></a>Stops the demuxer from working. </p>
</td>
</tr>
<tr id="row1496976552165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p640858260165627"><a name="p640858260165627"></a><a name="p640858260165627"></a><a href="format.md#ga98fd9a5a5d1ffd275fc46f898ca08413">FormatDemuxerDestory</a> (void *handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p507760813165627"><a name="p507760813165627"></a><a name="p507760813165627"></a>int32_t </p>
<p id="p819852149165627"><a name="p819852149165627"></a><a name="p819852149165627"></a>Destroys demuxer resources. </p>
</td>
</tr>
<tr id="row1749769590165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p810474246165627"><a name="p810474246165627"></a><a name="p810474246165627"></a><a href="format.md#ga9c390276cb90f4753c32af5aa5c600ad">FormatMuxerCreate</a> (void **handle, <a href="formatoutputconfig.md">FormatOutputConfig</a> *outputConfig)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1911325468165627"><a name="p1911325468165627"></a><a name="p1911325468165627"></a>int32_t </p>
<p id="p629835468165627"><a name="p629835468165627"></a><a name="p629835468165627"></a>Creates a muxer and returns its context handle. </p>
</td>
</tr>
<tr id="row8790995165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p336837706165627"><a name="p336837706165627"></a><a name="p336837706165627"></a><a href="format.md#gaa41d46cef6d5e81c85614edbf824d803">FormatMuxerDestory</a> (const void *handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1223619714165627"><a name="p1223619714165627"></a><a name="p1223619714165627"></a>int32_t </p>
<p id="p258836279165627"><a name="p258836279165627"></a><a name="p258836279165627"></a>Destroys a muxer and release its resources created by calling <a href="format.md#ga9c390276cb90f4753c32af5aa5c600ad">FormatMuxerCreate</a>. </p>
</td>
</tr>
<tr id="row700558017165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p225120416165627"><a name="p225120416165627"></a><a name="p225120416165627"></a><a href="format.md#ga94e9ab3e534b69a358b7cc16e4f79b78">FormatMuxerAddTrack</a> (void *handle, const <a href="tracksource.md">TrackSource</a> *trackSource)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1076332036165627"><a name="p1076332036165627"></a><a name="p1076332036165627"></a>int32_t </p>
<p id="p1595136232165627"><a name="p1595136232165627"></a><a name="p1595136232165627"></a>Adds a media track source for the muxer. For details about track sources, see <a href="tracksource.md">TrackSource</a>. </p>
</td>
</tr>
<tr id="row2096433933165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p741874128165627"><a name="p741874128165627"></a><a name="p741874128165627"></a><a href="format.md#ga108cd7e319ade568f71890d57585f153">FormatMuxerSetCallBack</a> (void *handle, const <a href="formatcallback.md">FormatCallback</a> *callBack)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1216595941165627"><a name="p1216595941165627"></a><a name="p1216595941165627"></a>int32_t </p>
<p id="p1294399529165627"><a name="p1294399529165627"></a><a name="p1294399529165627"></a>Sets a callback for the muxer. For details about the callback, see <a href="formatcallback.md">FormatCallback</a>. </p>
</td>
</tr>
<tr id="row1837959161165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p743246938165627"><a name="p743246938165627"></a><a name="p743246938165627"></a><a href="format.md#ga96fc57913c3202d2d23704c69d660be5">FormatMuxerSetOrientation</a> (void *handle, int degrees)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p216424925165627"><a name="p216424925165627"></a><a name="p216424925165627"></a>int32_t </p>
<p id="p1255651401165627"><a name="p1255651401165627"></a><a name="p1255651401165627"></a>Sets the orientation of the video track for the muxer. </p>
</td>
</tr>
<tr id="row1240244614165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1350450266165627"><a name="p1350450266165627"></a><a name="p1350450266165627"></a><a href="format.md#ga967ba14fa1231eed2942b87a09deb953">FormatMuxerSetLocation</a> (const void *handle, int latitude, int longitude)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p545873385165627"><a name="p545873385165627"></a><a name="p545873385165627"></a>int32_t </p>
<p id="p1213133505165627"><a name="p1213133505165627"></a><a name="p1213133505165627"></a>Sets the geographical information for the output file of the muxer. </p>
</td>
</tr>
<tr id="row1531033646165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1291857074165627"><a name="p1291857074165627"></a><a name="p1291857074165627"></a><a href="format.md#ga6f3ba422c9bbca4c1d5a7a3fe85dd9b9">FormatMuxerSetMaxFileSize</a> (void *handle, int64_t bytes)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p943313208165627"><a name="p943313208165627"></a><a name="p943313208165627"></a>int32_t </p>
<p id="p680359711165627"><a name="p680359711165627"></a><a name="p680359711165627"></a>Sets the maximum size (in bytes) for the output file of the muxer. </p>
</td>
</tr>
<tr id="row1382395033165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1173696912165627"><a name="p1173696912165627"></a><a name="p1173696912165627"></a><a href="format.md#gae931061d822c4ffe447e9ba40a991597">FormatMuxerSetMaxFileDuration</a> (void *handle, int64_t durationUs)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p304022280165627"><a name="p304022280165627"></a><a name="p304022280165627"></a>int32_t </p>
<p id="p910703384165627"><a name="p910703384165627"></a><a name="p910703384165627"></a>Sets the maximum duration (in seconds) for the output file. </p>
</td>
</tr>
<tr id="row1414316763165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p133941824165627"><a name="p133941824165627"></a><a name="p133941824165627"></a><a href="format.md#ga6eed6b5e7522e102f2d79d0dd33fd2a9">FormatMuxerSetFileSplitDuration</a> (const void *handle, <a href="format.md#ga10d9833450f29129d249c41d9acb4bc4">ManualSplitType</a> type, int64_t timestampUs, uint32_t durationUs)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1635902256165627"><a name="p1635902256165627"></a><a name="p1635902256165627"></a>int32_t </p>
<p id="p1455317989165627"><a name="p1455317989165627"></a><a name="p1455317989165627"></a>Manually splits a file. </p>
</td>
</tr>
<tr id="row681404417165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p825242578165627"><a name="p825242578165627"></a><a name="p825242578165627"></a><a href="format.md#ga9a2af831a6f4a63dc85d2c23b5c7c81b">FormatMuxerStart</a> (void *handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p772906800165627"><a name="p772906800165627"></a><a name="p772906800165627"></a>int32_t </p>
<p id="p1465538147165627"><a name="p1465538147165627"></a><a name="p1465538147165627"></a>Starts the muxer. </p>
</td>
</tr>
<tr id="row1049182404165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p84963218165627"><a name="p84963218165627"></a><a name="p84963218165627"></a><a href="format.md#ga82037d271e77da206e16582e774ee048">FormatMuxerWriteFrame</a> (const void *handle, const <a href="formatframe.md">FormatFrame</a> *frameData)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1772308418165627"><a name="p1772308418165627"></a><a name="p1772308418165627"></a>int32_t </p>
<p id="p1004998966165627"><a name="p1004998966165627"></a><a name="p1004998966165627"></a>Writes data frames into the muxer. </p>
</td>
</tr>
<tr id="row1087501433165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p671895345165627"><a name="p671895345165627"></a><a name="p671895345165627"></a><a href="format.md#gaa936b56996294d76977537267fef058c">FormatMuxerSetNextOutputFile</a> (const void *handle, int32_t fd)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1281891605165627"><a name="p1281891605165627"></a><a name="p1281891605165627"></a>int32_t </p>
<p id="p798911083165627"><a name="p798911083165627"></a><a name="p798911083165627"></a>Sets the descriptor for the next output file. </p>
</td>
</tr>
<tr id="row1581690619165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p421200976165627"><a name="p421200976165627"></a><a name="p421200976165627"></a><a href="format.md#ga66a3a5a1ec6d01fcbd6339f7eee1151b">FormatMuxerStop</a> (const void *handle, bool block)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1122349906165627"><a name="p1122349906165627"></a><a name="p1122349906165627"></a>int32_t </p>
<p id="p2039454512165627"><a name="p2039454512165627"></a><a name="p2039454512165627"></a>Stops the muxer that was started by calling <a href="format.md#ga9a2af831a6f4a63dc85d2c23b5c7c81b">FormatMuxerStart</a>. </p>
</td>
</tr>
<tr id="row1471354207165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p277421030165627"><a name="p277421030165627"></a><a name="p277421030165627"></a><a href="format.md#gad4335ebaa7c165b885a00fe61aae0cd9">FormatMuxerSetParameter</a> (void *handle, int32_t trackId, const <a href="parameteritem.md">ParameterItem</a> *item, int32_t itemNum)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p450544217165627"><a name="p450544217165627"></a><a name="p450544217165627"></a>int32_t </p>
<p id="p948563446165627"><a name="p948563446165627"></a><a name="p948563446165627"></a>Sets muxer attributes. </p>
</td>
</tr>
<tr id="row1480180949165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p367456917165627"><a name="p367456917165627"></a><a name="p367456917165627"></a><a href="format.md#ga67dd7361dedf335496afef19d54e4138">FormatMuxerGetParameter</a> (void *handle, int32_t trackId, <a href="parameteritem.md">ParameterItem</a> *item, int32_t itemNum)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2078836663165627"><a name="p2078836663165627"></a><a name="p2078836663165627"></a>int32_t </p>
<p id="p806283329165627"><a name="p806283329165627"></a><a name="p806283329165627"></a>Obtains muxer attributes. </p>
</td>
</tr>
</tbody>
</table>

