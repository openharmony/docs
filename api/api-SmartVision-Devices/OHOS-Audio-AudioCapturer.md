# OHOS::Audio::AudioCapturer<a name="ZH-CN_TOPIC_0000001054718137"></a>

-   [Overview](#section384295052165635)
-   [Summary](#section1434045264165635)
-   [Public Member Functions](#pub-methods)
-   [Static Public Member Functions](#pub-static-methods)

## **Overview**<a name="section384295052165635"></a>

**Related Modules:**

[MultiMedia\_AudioCapturer](MultiMedia_AudioCapturer.md)

**Description:**

Provides functions for applications to implement audio capturing. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1434045264165635"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table701012798165635"></a>
<table><thead align="left"><tr id="row1258505174165635"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p629153874165635"><a name="p629153874165635"></a><a name="p629153874165635"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p579928693165635"><a name="p579928693165635"></a><a name="p579928693165635"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row809340769165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p624639778165635"><a name="p624639778165635"></a><a name="p624639778165635"></a><a href="MultiMedia_AudioCapturer.md#gaf603a793bb5e97f000b11f57fa944ce1">GetFrameCount</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1605022178165635"><a name="p1605022178165635"></a><a name="p1605022178165635"></a>uint64_t </p>
<p id="p333151772165635"><a name="p333151772165635"></a><a name="p333151772165635"></a>Obtains the number of frames required in the current condition, in bytes per sample. </p>
</td>
</tr>
<tr id="row1553215971165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p638787331165635"><a name="p638787331165635"></a><a name="p638787331165635"></a><a href="MultiMedia_AudioCapturer.md#gae2cf055c840ece71e22cb64c98c68a19">SetCapturerInfo</a> (const <a href="OHOS-Audio-AudioCapturerInfo.md">AudioCapturerInfo</a> info)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1489282351165635"><a name="p1489282351165635"></a><a name="p1489282351165635"></a>int32_t </p>
<p id="p1192178229165635"><a name="p1192178229165635"></a><a name="p1192178229165635"></a>Sets audio capture parameters. </p>
</td>
</tr>
<tr id="row591522420165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2044286318165635"><a name="p2044286318165635"></a><a name="p2044286318165635"></a><a href="MultiMedia_AudioCapturer.md#ga3921932035bfa99f7e7d8d0241344fca">GetCapturerInfo</a> (<a href="OHOS-Audio-AudioCapturerInfo.md">AudioCapturerInfo</a> &amp;info)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p640242950165635"><a name="p640242950165635"></a><a name="p640242950165635"></a>int32_t </p>
<p id="p2028952570165635"><a name="p2028952570165635"></a><a name="p2028952570165635"></a>Obtains audio capture parameters. </p>
</td>
</tr>
<tr id="row977235911165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2083665301165635"><a name="p2083665301165635"></a><a name="p2083665301165635"></a><a href="MultiMedia_AudioCapturer.md#gac3391374f9a180d84aa5bd19236743a1">Start</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p442955105165635"><a name="p442955105165635"></a><a name="p442955105165635"></a>bool </p>
<p id="p2101943382165635"><a name="p2101943382165635"></a><a name="p2101943382165635"></a>Starts audio recording. </p>
</td>
</tr>
<tr id="row1897488001165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2098012039165635"><a name="p2098012039165635"></a><a name="p2098012039165635"></a><a href="MultiMedia_AudioCapturer.md#ga75bccf0f21f7d9adc5e580f40abfc7d2">Read</a> (uint8_t *buffer, size_t userSize, bool isBlockingRead)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p57629727165635"><a name="p57629727165635"></a><a name="p57629727165635"></a>int32_t </p>
<p id="p350854479165635"><a name="p350854479165635"></a><a name="p350854479165635"></a>Reads audio data. </p>
</td>
</tr>
<tr id="row1347187717165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1584835253165635"><a name="p1584835253165635"></a><a name="p1584835253165635"></a><a href="MultiMedia_AudioCapturer.md#gaf022f9b98b1776799e86b689f7544a5e">GetStatus</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p786744679165635"><a name="p786744679165635"></a><a name="p786744679165635"></a><a href="MultiMedia_AudioCapturer.md#ga3d8d6798a2346e57e241d16da673d508">State</a> </p>
<p id="p2100787402165635"><a name="p2100787402165635"></a><a name="p2100787402165635"></a>Obtains the audio capture state. </p>
</td>
</tr>
<tr id="row432841205165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p685475113165635"><a name="p685475113165635"></a><a name="p685475113165635"></a><a href="MultiMedia_AudioCapturer.md#gae24a95aeba747852373ef408bb9bab12">GetAudioTime</a> (<a href="OHOS-Audio-Timestamp.md">Timestamp</a> &amp;timestamp, <a href="MultiMedia_AudioCapturer.md#gacdafb362a7da91799fa96163bca2a619">Timestamp::Timebase</a> base)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1958660624165635"><a name="p1958660624165635"></a><a name="p1958660624165635"></a>bool </p>
<p id="p489674517165635"><a name="p489674517165635"></a><a name="p489674517165635"></a>Obtains the timestamp. </p>
</td>
</tr>
<tr id="row1017949005165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p335589234165635"><a name="p335589234165635"></a><a name="p335589234165635"></a><a href="MultiMedia_AudioCapturer.md#ga498a8a4d0a2c09418944eab7728bdc7b">Stop</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1528635623165635"><a name="p1528635623165635"></a><a name="p1528635623165635"></a>bool </p>
<p id="p2092368062165635"><a name="p2092368062165635"></a><a name="p2092368062165635"></a>Stops audio recording. </p>
</td>
</tr>
<tr id="row1721729157165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1626336691165635"><a name="p1626336691165635"></a><a name="p1626336691165635"></a><a href="MultiMedia_AudioCapturer.md#gad68b60d6ca82d096cbfa0f4205f2ae9e">Release</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1472837572165635"><a name="p1472837572165635"></a><a name="p1472837572165635"></a>bool </p>
<p id="p1653375213165635"><a name="p1653375213165635"></a><a name="p1653375213165635"></a>Releases a local <strong id="b486981149165635"><a name="b486981149165635"></a><a name="b486981149165635"></a><a href="OHOS-Audio-AudioCapturer.md">AudioCapturer</a></strong> object. </p>
</td>
</tr>
</tbody>
</table>

## Static Public Member Functions<a name="pub-static-methods"></a>

<a name="table493928781165635"></a>
<table><thead align="left"><tr id="row455855702165635"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2037699556165635"><a name="p2037699556165635"></a><a name="p2037699556165635"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1461144362165635"><a name="p1461144362165635"></a><a name="p1461144362165635"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row747010397165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1398472102165635"><a name="p1398472102165635"></a><a name="p1398472102165635"></a><a href="MultiMedia_AudioCapturer.md#gac3f12dec86f94438758ba1a6ff6ed7da">GetMinFrameCount</a> (int32_t sampleRate, int32_t channelCount, <a href="MultiMedia_MediaCommon.md#gaa4ea6f314644ed287e0704be26c768b7">AudioCodecFormat</a> audioFormat, size_t &amp;frameCount)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p966348756165635"><a name="p966348756165635"></a><a name="p966348756165635"></a>static bool </p>
<p id="p402468931165635"><a name="p402468931165635"></a><a name="p402468931165635"></a>Obtains the minimum number of frames required in a specified condition, in bytes per sample. </p>
</td>
</tr>
</tbody>
</table>

