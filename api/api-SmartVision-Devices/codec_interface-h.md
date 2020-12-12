# codec\_interface.h<a name="ZH-CN_TOPIC_0000001054718089"></a>

-   [Overview](#section516593123165626)
-   [Summary](#section1395341176165626)
-   [Functions](#func-members)

## **Overview**<a name="section516593123165626"></a>

**Related Modules:**

[Codec](Codec.md)

**Description:**

Declares codec-related APIs, including functions for initializing audio and video codecs, setting parameters, and controlling and transferring data. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1395341176165626"></a>

## Functions<a name="func-members"></a>

<a name="table1998532644165626"></a>
<table><thead align="left"><tr id="row600911596165626"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p896438349165626"><a name="p896438349165626"></a><a name="p896438349165626"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1401746334165626"><a name="p1401746334165626"></a><a name="p1401746334165626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1606486391165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1983113737165626"><a name="p1983113737165626"></a><a name="p1983113737165626"></a><a href="Codec.md#gadb2714f1e7a69419cefd38a2ad1f9829">CodecInit</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1208134664165626"><a name="p1208134664165626"></a><a name="p1208134664165626"></a>int32_t </p>
<p id="p2093382462165626"><a name="p2093382462165626"></a><a name="p2093382462165626"></a>Initializes the internal audio and video submodules of the codec. </p>
</td>
</tr>
<tr id="row1280428752165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1465852597165626"><a name="p1465852597165626"></a><a name="p1465852597165626"></a><a href="Codec.md#ga2d6eb231ca7766990cfa8c1841637245">CodecDeinit</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p503509565165626"><a name="p503509565165626"></a><a name="p503509565165626"></a>int32_t </p>
<p id="p1872124543165626"><a name="p1872124543165626"></a><a name="p1872124543165626"></a>Deinitializes the internal audio and video submodules of the codec. </p>
</td>
</tr>
<tr id="row1410383530165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2024981350165626"><a name="p2024981350165626"></a><a name="p2024981350165626"></a><a href="Codec.md#gaf0bb69d2f8c5ad0fec6959b353ee1acd">CodecEnumerateCapbility</a> (uint32_t <a href="UTILS.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>, <a href="Codec.md#ga1876710b1f2fe1d80e8b9de9ff28e0e3">CodecCapbility</a> *cap)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p470741345165626"><a name="p470741345165626"></a><a name="p470741345165626"></a>int32_t </p>
<p id="p840064435165626"><a name="p840064435165626"></a><a name="p840064435165626"></a>Obtains the capabilities of a specified media type based on an index. </p>
</td>
</tr>
<tr id="row69968727165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p175848900165626"><a name="p175848900165626"></a><a name="p175848900165626"></a><a href="Codec.md#ga1a6fbf6e84e01fdc1af59caa4203ce8e">CodecGetCapbility</a> (<a href="Codec.md#ga1bee586eafa91dfb60f94ba40fc95faa">AvCodecMime</a> mime, <a href="Codec.md#ga03b4b6ae5fb82af68d46aaea3d3e4d79">CodecType</a> type, uint32_t flags, <a href="Codec.md#ga1876710b1f2fe1d80e8b9de9ff28e0e3">CodecCapbility</a> *cap)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p398282047165626"><a name="p398282047165626"></a><a name="p398282047165626"></a>int32_t </p>
<p id="p921278625165626"><a name="p921278625165626"></a><a name="p921278625165626"></a>Obtains the capabilities of a specified media type. </p>
</td>
</tr>
<tr id="row48435604165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1101177193165626"><a name="p1101177193165626"></a><a name="p1101177193165626"></a><a href="Codec.md#ga74aa0395a51f004390f7a92fb68faddd">CodecCreate</a> (const char *name, const <a href="Param.md">Param</a> *attr, int len, <a href="Codec.md#ga9381a619f36ac8d5d7f467d2f0404183">CODEC_HANDLETYPE</a> *handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p650215628165626"><a name="p650215628165626"></a><a name="p650215628165626"></a>int32_t </p>
<p id="p1077309177165626"><a name="p1077309177165626"></a><a name="p1077309177165626"></a>Creates a specific codec component and returns the component context through a handle. </p>
</td>
</tr>
<tr id="row527829161165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1370535713165626"><a name="p1370535713165626"></a><a name="p1370535713165626"></a><a href="Codec.md#ga1bc0592b05e4f687e2bef2ffb83102b8">CodecDestroy</a> (<a href="Codec.md#ga9381a619f36ac8d5d7f467d2f0404183">CODEC_HANDLETYPE</a> handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p56371738165626"><a name="p56371738165626"></a><a name="p56371738165626"></a>int32_t </p>
<p id="p1038518504165626"><a name="p1038518504165626"></a><a name="p1038518504165626"></a>Destroys a codec component. </p>
</td>
</tr>
<tr id="row691081503165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2117429630165626"><a name="p2117429630165626"></a><a name="p2117429630165626"></a><a href="Codec.md#ga36a994c5f9f4d104aad0c24b5e8cbd37">CodecSetPortMode</a> (<a href="Codec.md#ga9381a619f36ac8d5d7f467d2f0404183">CODEC_HANDLETYPE</a> handle, <a href="Codec.md#ga8ef30fa9c08e08c8706653571f9f5b81">DirectionType</a> type, <a href="Codec.md#gacc0fd55192fd9f663121b037b06f41e8">BufferMode</a> mode)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1310525745165626"><a name="p1310525745165626"></a><a name="p1310525745165626"></a>int32_t </p>
<p id="p351893800165626"><a name="p351893800165626"></a><a name="p351893800165626"></a>Sets the input or output buffer mode. </p>
</td>
</tr>
<tr id="row1041685674165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p52940493165626"><a name="p52940493165626"></a><a name="p52940493165626"></a><a href="Codec.md#gaa080cf23aa5f77b30f3b90a026d97cc0">CodecSetParameter</a> (<a href="Codec.md#ga9381a619f36ac8d5d7f467d2f0404183">CODEC_HANDLETYPE</a> handle, const <a href="Param.md">Param</a> *params, int paramCnt)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p592320025165626"><a name="p592320025165626"></a><a name="p592320025165626"></a>int32_t </p>
<p id="p613028712165626"><a name="p613028712165626"></a><a name="p613028712165626"></a>Sets parameters required by a codec component. </p>
</td>
</tr>
<tr id="row1124728414165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p192097014165626"><a name="p192097014165626"></a><a name="p192097014165626"></a><a href="Codec.md#ga1d812eac032e3e05cf5bf71b03e93f65">CodecGetParameter</a> (<a href="Codec.md#ga9381a619f36ac8d5d7f467d2f0404183">CODEC_HANDLETYPE</a> handle, <a href="Param.md">Param</a> *params, int paramCnt)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1197236486165626"><a name="p1197236486165626"></a><a name="p1197236486165626"></a>int32_t </p>
<p id="p2068523323165626"><a name="p2068523323165626"></a><a name="p2068523323165626"></a>Obtains parameters from a codec component. </p>
</td>
</tr>
<tr id="row1223870417165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1755477794165626"><a name="p1755477794165626"></a><a name="p1755477794165626"></a><a href="Codec.md#ga38c1744b0b4be5817ef49556ae665d18">CodecStart</a> (<a href="Codec.md#ga9381a619f36ac8d5d7f467d2f0404183">CODEC_HANDLETYPE</a> handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1541350278165626"><a name="p1541350278165626"></a><a name="p1541350278165626"></a>int32_t </p>
<p id="p1220410498165626"><a name="p1220410498165626"></a><a name="p1220410498165626"></a>Starts a codec component. </p>
</td>
</tr>
<tr id="row1543920487165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p803306740165626"><a name="p803306740165626"></a><a name="p803306740165626"></a><a href="Codec.md#ga8e7913c052c2e45e193fb0aab3f5c7fd">CodecStop</a> (<a href="Codec.md#ga9381a619f36ac8d5d7f467d2f0404183">CODEC_HANDLETYPE</a> handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p279989704165626"><a name="p279989704165626"></a><a name="p279989704165626"></a>int32_t </p>
<p id="p223361051165626"><a name="p223361051165626"></a><a name="p223361051165626"></a>Stops a codec component. </p>
</td>
</tr>
<tr id="row1280606277165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1491489590165626"><a name="p1491489590165626"></a><a name="p1491489590165626"></a><a href="Codec.md#gaa6ed6c24e29f8fdfbbb0a3d562260a6a">CodecFlush</a> (<a href="Codec.md#ga9381a619f36ac8d5d7f467d2f0404183">CODEC_HANDLETYPE</a> handle, <a href="Codec.md#ga8ef30fa9c08e08c8706653571f9f5b81">DirectionType</a> directType)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1475382639165626"><a name="p1475382639165626"></a><a name="p1475382639165626"></a>int32_t </p>
<p id="p1061758893165626"><a name="p1061758893165626"></a><a name="p1061758893165626"></a>Clears the cache when the codec component is the running state. </p>
</td>
</tr>
<tr id="row399855696165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p586724939165626"><a name="p586724939165626"></a><a name="p586724939165626"></a><a href="Codec.md#ga0daece8dbf22da84f926761c994819bc">CodecQueueInput</a> (<a href="Codec.md#ga9381a619f36ac8d5d7f467d2f0404183">CODEC_HANDLETYPE</a> handle, const <a href="InputInfo.md">InputInfo</a> *inputData, uint32_t timeoutMs)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p813408483165626"><a name="p813408483165626"></a><a name="p813408483165626"></a>int32_t </p>
<p id="p2137729859165626"><a name="p2137729859165626"></a><a name="p2137729859165626"></a>Queues input data. </p>
</td>
</tr>
<tr id="row959036559165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1779005070165626"><a name="p1779005070165626"></a><a name="p1779005070165626"></a><a href="Codec.md#ga91d7e1566c90d7cb9ac846eecad0024f">CodecDequeInput</a> (<a href="Codec.md#ga9381a619f36ac8d5d7f467d2f0404183">CODEC_HANDLETYPE</a> handle, uint32_t timeoutMs, <a href="InputInfo.md">InputInfo</a> *inputData)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p598321231165626"><a name="p598321231165626"></a><a name="p598321231165626"></a>int32_t </p>
<p id="p1466973588165626"><a name="p1466973588165626"></a><a name="p1466973588165626"></a>Dequeues input data that has been used. </p>
</td>
</tr>
<tr id="row1871774712165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p164139946165626"><a name="p164139946165626"></a><a name="p164139946165626"></a><a href="Codec.md#gac98f3505082c3cb2413d9e95eef9c804">CodecQueueOutput</a> (<a href="Codec.md#ga9381a619f36ac8d5d7f467d2f0404183">CODEC_HANDLETYPE</a> handle, <a href="OutputInfo.md">OutputInfo</a> *outInfo, uint32_t timeoutMs, int releaseFenceFd)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p243215018165626"><a name="p243215018165626"></a><a name="p243215018165626"></a>int32_t </p>
<p id="p627720905165626"><a name="p627720905165626"></a><a name="p627720905165626"></a>Queues output data. </p>
</td>
</tr>
<tr id="row644462729165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1749305746165626"><a name="p1749305746165626"></a><a name="p1749305746165626"></a><a href="Codec.md#gab575752467517eb8e6766773c1e3fb23">CodecDequeueOutput</a> (<a href="Codec.md#ga9381a619f36ac8d5d7f467d2f0404183">CODEC_HANDLETYPE</a> handle, uint32_t timeoutMs, int *acquireFd, <a href="OutputInfo.md">OutputInfo</a> *outInfo)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p424109557165626"><a name="p424109557165626"></a><a name="p424109557165626"></a>int32_t </p>
<p id="p1068637696165626"><a name="p1068637696165626"></a><a name="p1068637696165626"></a>Dequeues output data. </p>
</td>
</tr>
<tr id="row1136716561165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1268372963165626"><a name="p1268372963165626"></a><a name="p1268372963165626"></a><a href="Codec.md#ga28ec6149d05765ee75f4836e0b092406">CodecSetCallback</a> (<a href="Codec.md#ga9381a619f36ac8d5d7f467d2f0404183">CODEC_HANDLETYPE</a> handle, const <a href="CodecCallback.md">CodecCallback</a> *cb, <a href="Codec.md#ga58d2f4a8d12daa1dcf4eb297f3ebaabc">UINTPTR</a> instance)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p120966706165626"><a name="p120966706165626"></a><a name="p120966706165626"></a>int32_t </p>
<p id="p702906019165626"><a name="p702906019165626"></a><a name="p702906019165626"></a>Sets the callback function. </p>
</td>
</tr>
</tbody>
</table>

