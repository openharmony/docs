# OHOS::Audio::AudioCapturerInfo<a name="ZH-CN_TOPIC_0000001054598171"></a>

-   [Overview](#section684418868165635)
-   [Summary](#section925744169165635)
-   [Data Fields](#pub-attribs)

## **Overview**<a name="section684418868165635"></a>

**Related Modules:**

[MultiMedia\_AudioCapturer](MultiMedia_AudioCapturer.md)

**Description:**

Defines information about audio capture parameters, including the input source, audio codec format,sampling rate \(Hz\), number of audio channels, bit rate, and bit width. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section925744169165635"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1981034443165635"></a>
<table><thead align="left"><tr id="row989076365165635"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2080569352165635"><a name="p2080569352165635"></a><a name="p2080569352165635"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1192089956165635"><a name="p1192089956165635"></a><a name="p1192089956165635"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row617615247165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p72076057165635"><a name="p72076057165635"></a><a name="p72076057165635"></a><a href="MultiMedia_AudioCapturer.md#ga9c14165a8197521b8a539bd5408f66ed">inputSource</a> = <a href="MultiMedia_MediaCommon.md#ggadc3158e093b995ca7b9b6aa32388ccdda732604b3a24d137429e2b83b31849bce">AUDIO_MIC</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1618682274165635"><a name="p1618682274165635"></a><a name="p1618682274165635"></a><a href="MultiMedia_MediaCommon.md#gadc3158e093b995ca7b9b6aa32388ccdd">AudioSourceType</a> </p>
</td>
</tr>
<tr id="row2060841313165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1399651145165635"><a name="p1399651145165635"></a><a name="p1399651145165635"></a><a href="MultiMedia_AudioCapturer.md#ga6a222ecc5112fb2925879dba686c12a3">audioFormat</a> = <a href="MultiMedia_MediaCommon.md#ggaa4ea6f314644ed287e0704be26c768b7a4c4c5829b054bc468274700c56d65546">AUDIO_DEFAULT</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1681032007165635"><a name="p1681032007165635"></a><a name="p1681032007165635"></a><a href="MultiMedia_MediaCommon.md#gaa4ea6f314644ed287e0704be26c768b7">AudioCodecFormat</a> </p>
</td>
</tr>
<tr id="row1123553412165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p992018768165635"><a name="p992018768165635"></a><a name="p992018768165635"></a><a href="MultiMedia_AudioCapturer.md#gab623e99855bc46fe9d3dbfacb67e419a">sampleRate</a> = 0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p468153372165635"><a name="p468153372165635"></a><a name="p468153372165635"></a>int32_t </p>
</td>
</tr>
<tr id="row661828613165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1136355886165635"><a name="p1136355886165635"></a><a name="p1136355886165635"></a><a href="MultiMedia_AudioCapturer.md#ga3219851b0a3e355a8519c9262f879e47">channelCount</a> = 0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p99588475165635"><a name="p99588475165635"></a><a name="p99588475165635"></a>int32_t </p>
</td>
</tr>
<tr id="row573992203165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p713218999165635"><a name="p713218999165635"></a><a name="p713218999165635"></a><a href="MultiMedia_AudioCapturer.md#gace7d68d68754fc267117003f7fc76522">bitRate</a> = 0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p6957630165635"><a name="p6957630165635"></a><a name="p6957630165635"></a>int32_t </p>
</td>
</tr>
<tr id="row429710942165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1381173057165635"><a name="p1381173057165635"></a><a name="p1381173057165635"></a><a href="MultiMedia_AudioCapturer.md#gaaa038f040e203e553aba28e80f26f733">streamType</a> = <a href="MultiMedia_MediaCommon.md#ggae7077e4211e48131ae544adb20fc494aa431e273affaa22e18ec5a2a548b70e90">TYPE_MEDIA</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p845791076165635"><a name="p845791076165635"></a><a name="p845791076165635"></a><a href="MultiMedia_MediaCommon.md#gae7077e4211e48131ae544adb20fc494a">AudioStreamType</a> </p>
</td>
</tr>
<tr id="row469606699165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1757894609165635"><a name="p1757894609165635"></a><a name="p1757894609165635"></a><a href="MultiMedia_AudioCapturer.md#ga110704c5058747a6180c250b0a77d685">bitWidth</a> = <a href="MultiMedia_MediaCommon.md#ggae3e35ee2a2222a667fdebbc5b793ca7ca036f0b45813f96cb6b0f90de1722a780">BIT_WIDTH_16</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p249507200165635"><a name="p249507200165635"></a><a name="p249507200165635"></a><a href="MultiMedia_MediaCommon.md#gae3e35ee2a2222a667fdebbc5b793ca7c">AudioBitWidth</a> </p>
</td>
</tr>
</tbody>
</table>

