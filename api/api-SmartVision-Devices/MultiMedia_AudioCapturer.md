# MultiMedia\_AudioCapturer<a name="ZH-CN_TOPIC_0000001054718079"></a>

-   [Overview](#section684538670165625)
-   [Summary](#section535185799165625)
-   [Files](#files)
-   [Data Structures](#nested-classes)
-   [Enumerations](#enum-members)
-   [Functions](#func-members)
-   [Details](#section2051307272165625)
-   [Enumeration Type](#section1407711336165625)
-   [State](#ga3d8d6798a2346e57e241d16da673d508)
-   [Timebase](#gacdafb362a7da91799fa96163bca2a619)
-   [Function](#section200639590165625)
-   [GetAudioTime\(\)](#gae24a95aeba747852373ef408bb9bab12)
-   [GetCapturerInfo\(\)](#ga3921932035bfa99f7e7d8d0241344fca)
-   [GetFrameCount\(\)](#gaf603a793bb5e97f000b11f57fa944ce1)
-   [GetMinFrameCount\(\)](#gac3f12dec86f94438758ba1a6ff6ed7da)
-   [GetStatus\(\)](#gaf022f9b98b1776799e86b689f7544a5e)
-   [Read\(\)](#ga75bccf0f21f7d9adc5e580f40abfc7d2)
-   [Release\(\)](#gad68b60d6ca82d096cbfa0f4205f2ae9e)
-   [SetCapturerInfo\(\)](#gae2cf055c840ece71e22cb64c98c68a19)
-   [Start\(\)](#gac3391374f9a180d84aa5bd19236743a1)
-   [Stop\(\)](#ga498a8a4d0a2c09418944eab7728bdc7b)
-   [Variable](#section1593978958165625)
-   [audioFormat](#ga6a222ecc5112fb2925879dba686c12a3)
-   [bitRate](#gace7d68d68754fc267117003f7fc76522)
-   [bitWidth](#ga110704c5058747a6180c250b0a77d685)
-   [channelCount](#ga3219851b0a3e355a8519c9262f879e47)
-   [inputSource](#ga9c14165a8197521b8a539bd5408f66ed)
-   [sampleRate](#gab623e99855bc46fe9d3dbfacb67e419a)
-   [streamType](#gaaa038f040e203e553aba28e80f26f733)

## **Overview**<a name="section684538670165625"></a>

**Description:**

Declares APIs in the  **AudioCapturer**  class for audio capture. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section535185799165625"></a>

## Files<a name="files"></a>

<a name="table1888953163165625"></a>
<table><thead align="left"><tr id="row985726792165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1137158490165625"><a name="p1137158490165625"></a><a name="p1137158490165625"></a>File Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p396022117165625"><a name="p396022117165625"></a><a name="p396022117165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1756746063165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p160561875165625"><a name="p160561875165625"></a><a name="p160561875165625"></a><a href="audio_capturer-h.md">audio_capturer.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p412364151165625"><a name="p412364151165625"></a><a name="p412364151165625"></a>Provides the <strong id="b310966938165625"><a name="b310966938165625"></a><a name="b310966938165625"></a>AudioCapturer</strong> class to implement operations related to audio capture. </p>
</td>
</tr>
</tbody>
</table>

## Data Structures<a name="nested-classes"></a>

<a name="table387179793165625"></a>
<table><thead align="left"><tr id="row1508785646165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1746697134165625"><a name="p1746697134165625"></a><a name="p1746697134165625"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p763373547165625"><a name="p763373547165625"></a><a name="p763373547165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1146098983165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p423577031165625"><a name="p423577031165625"></a><a name="p423577031165625"></a><a href="OHOS-Audio-AudioCapturerInfo.md">OHOS::Audio::AudioCapturerInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p772193695165625"><a name="p772193695165625"></a><a name="p772193695165625"></a>Defines information about audio capture parameters, including the input source, audio codec format,sampling rate (Hz), number of audio channels, bit rate, and bit width. </p>
</td>
</tr>
<tr id="row72277551165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1952766981165625"><a name="p1952766981165625"></a><a name="p1952766981165625"></a><a href="OHOS-Audio-Timestamp.md">OHOS::Audio::Timestamp</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p679987000165625"><a name="p679987000165625"></a><a name="p679987000165625"></a>Represents timestamp information, including the frame position information and high-resolution time source. </p>
</td>
</tr>
<tr id="row844136217165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1402662377165625"><a name="p1402662377165625"></a><a name="p1402662377165625"></a><a href="OHOS-Audio-AudioCapturer.md">OHOS::Audio::AudioCapturer</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1738437431165625"><a name="p1738437431165625"></a><a name="p1738437431165625"></a>Provides functions for applications to implement audio capturing. </p>
</td>
</tr>
</tbody>
</table>

## Enumerations<a name="enum-members"></a>

<a name="table1006113005165625"></a>
<table><thead align="left"><tr id="row1875876646165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p117944430165625"><a name="p117944430165625"></a><a name="p117944430165625"></a>Enumeration Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1825511210165625"><a name="p1825511210165625"></a><a name="p1825511210165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1757508964165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p545157422165625"><a name="p545157422165625"></a><a name="p545157422165625"></a><a href="MultiMedia_AudioCapturer.md#gacdafb362a7da91799fa96163bca2a619">OHOS::Audio::Timestamp::Timebase</a> : int32_t { <a href="MultiMedia_AudioCapturer.md#ggacdafb362a7da91799fa96163bca2a619a109ce01d0775b5372b9b2cc517630d39">OHOS::Audio::Timestamp::Timebase::MONOTONIC</a> = 0, <a href="MultiMedia_AudioCapturer.md#ggacdafb362a7da91799fa96163bca2a619aa0bb084304634f8cf8c9d41c5b87c0c3">OHOS::Audio::Timestamp::Timebase::BOOTTIME</a> = 1 }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p652912394165625"><a name="p652912394165625"></a><a name="p652912394165625"></a>Enumerates the time base of this <strong id="b1578581195165625"><a name="b1578581195165625"></a><a name="b1578581195165625"></a>Timestamp</strong>. Different timing methods are supported. </p>
</td>
</tr>
<tr id="row1196063045165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p351333720165625"><a name="p351333720165625"></a><a name="p351333720165625"></a><a href="MultiMedia_AudioCapturer.md#ga3d8d6798a2346e57e241d16da673d508">OHOS::Audio::State</a> : uint32_t { <a href="MultiMedia_AudioCapturer.md#gga3d8d6798a2346e57e241d16da673d508a368f9c124fa478d643e6b3884bd4931c">OHOS::Audio::PREPPARED</a>, <a href="MultiMedia_AudioCapturer.md#gga3d8d6798a2346e57e241d16da673d508a6d83cfbb144468bcd7f1d0609ba1a401">OHOS::Audio::RECORDING</a>, <a href="MultiMedia_AudioCapturer.md#gga3d8d6798a2346e57e241d16da673d508abc10d40a09b83e61c72dd68daa457399">OHOS::Audio::STOPPED</a>, <a href="MultiMedia_AudioCapturer.md#gga3d8d6798a2346e57e241d16da673d508ab061f3539998a6bcec9b4c11357b5ff2">OHOS::Audio::RELEASED</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1486038443165625"><a name="p1486038443165625"></a><a name="p1486038443165625"></a>Enumerates the recording states of the current device. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table1957647351165625"></a>
<table><thead align="left"><tr id="row794828921165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p213299837165625"><a name="p213299837165625"></a><a name="p213299837165625"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p872837204165625"><a name="p872837204165625"></a><a name="p872837204165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1326106713165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p360831055165625"><a name="p360831055165625"></a><a name="p360831055165625"></a><a href="MultiMedia_AudioCapturer.md#gac3f12dec86f94438758ba1a6ff6ed7da">OHOS::Audio::AudioCapturer::GetMinFrameCount</a> (int32_t sampleRate, int32_t channelCount, <a href="MultiMedia_MediaCommon.md#gaa4ea6f314644ed287e0704be26c768b7">AudioCodecFormat</a> audioFormat, size_t &amp;frameCount)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p9056391165625"><a name="p9056391165625"></a><a name="p9056391165625"></a>static bool </p>
<p id="p352950686165625"><a name="p352950686165625"></a><a name="p352950686165625"></a>Obtains the minimum number of frames required in a specified condition, in bytes per sample. </p>
</td>
</tr>
<tr id="row1718329983165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p411064668165625"><a name="p411064668165625"></a><a name="p411064668165625"></a><a href="MultiMedia_AudioCapturer.md#gaf603a793bb5e97f000b11f57fa944ce1">OHOS::Audio::AudioCapturer::GetFrameCount</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p874158203165625"><a name="p874158203165625"></a><a name="p874158203165625"></a>uint64_t </p>
<p id="p612632209165625"><a name="p612632209165625"></a><a name="p612632209165625"></a>Obtains the number of frames required in the current condition, in bytes per sample. </p>
</td>
</tr>
<tr id="row1391832751165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p824553129165625"><a name="p824553129165625"></a><a name="p824553129165625"></a><a href="MultiMedia_AudioCapturer.md#gae2cf055c840ece71e22cb64c98c68a19">OHOS::Audio::AudioCapturer::SetCapturerInfo</a> (const <a href="OHOS-Audio-AudioCapturerInfo.md">AudioCapturerInfo</a> info)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1142365367165625"><a name="p1142365367165625"></a><a name="p1142365367165625"></a>int32_t </p>
<p id="p77045504165625"><a name="p77045504165625"></a><a name="p77045504165625"></a>Sets audio capture parameters. </p>
</td>
</tr>
<tr id="row1897759330165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1432964373165625"><a name="p1432964373165625"></a><a name="p1432964373165625"></a><a href="MultiMedia_AudioCapturer.md#ga3921932035bfa99f7e7d8d0241344fca">OHOS::Audio::AudioCapturer::GetCapturerInfo</a> (<a href="OHOS-Audio-AudioCapturerInfo.md">AudioCapturerInfo</a> &amp;info)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2135522208165625"><a name="p2135522208165625"></a><a name="p2135522208165625"></a>int32_t </p>
<p id="p1869334515165625"><a name="p1869334515165625"></a><a name="p1869334515165625"></a>Obtains audio capture parameters. </p>
</td>
</tr>
<tr id="row1861837999165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p843674697165625"><a name="p843674697165625"></a><a name="p843674697165625"></a><a href="MultiMedia_AudioCapturer.md#gac3391374f9a180d84aa5bd19236743a1">OHOS::Audio::AudioCapturer::Start</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p106401486165625"><a name="p106401486165625"></a><a name="p106401486165625"></a>bool </p>
<p id="p1669132550165625"><a name="p1669132550165625"></a><a name="p1669132550165625"></a>Starts audio recording. </p>
</td>
</tr>
<tr id="row651380746165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p778991703165625"><a name="p778991703165625"></a><a name="p778991703165625"></a><a href="MultiMedia_AudioCapturer.md#ga75bccf0f21f7d9adc5e580f40abfc7d2">OHOS::Audio::AudioCapturer::Read</a> (uint8_t *buffer, size_t userSize, bool isBlockingRead)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1637213593165625"><a name="p1637213593165625"></a><a name="p1637213593165625"></a>int32_t </p>
<p id="p960957303165625"><a name="p960957303165625"></a><a name="p960957303165625"></a>Reads audio data. </p>
</td>
</tr>
<tr id="row400725895165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1022155632165625"><a name="p1022155632165625"></a><a name="p1022155632165625"></a><a href="MultiMedia_AudioCapturer.md#gaf022f9b98b1776799e86b689f7544a5e">OHOS::Audio::AudioCapturer::GetStatus</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p799649637165625"><a name="p799649637165625"></a><a name="p799649637165625"></a><a href="MultiMedia_AudioCapturer.md#ga3d8d6798a2346e57e241d16da673d508">State</a> </p>
<p id="p497508635165625"><a name="p497508635165625"></a><a name="p497508635165625"></a>Obtains the audio capture state. </p>
</td>
</tr>
<tr id="row174691976165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1793700883165625"><a name="p1793700883165625"></a><a name="p1793700883165625"></a><a href="MultiMedia_AudioCapturer.md#gae24a95aeba747852373ef408bb9bab12">OHOS::Audio::AudioCapturer::GetAudioTime</a> (<a href="OHOS-Audio-Timestamp.md">Timestamp</a> &amp;timestamp, <a href="MultiMedia_AudioCapturer.md#gacdafb362a7da91799fa96163bca2a619">Timestamp::Timebase</a> base)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p313046673165625"><a name="p313046673165625"></a><a name="p313046673165625"></a>bool </p>
<p id="p1036724960165625"><a name="p1036724960165625"></a><a name="p1036724960165625"></a>Obtains the timestamp. </p>
</td>
</tr>
<tr id="row705599943165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p626810928165625"><a name="p626810928165625"></a><a name="p626810928165625"></a><a href="MultiMedia_AudioCapturer.md#ga498a8a4d0a2c09418944eab7728bdc7b">OHOS::Audio::AudioCapturer::Stop</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p103268253165625"><a name="p103268253165625"></a><a name="p103268253165625"></a>bool </p>
<p id="p1318509356165625"><a name="p1318509356165625"></a><a name="p1318509356165625"></a>Stops audio recording. </p>
</td>
</tr>
<tr id="row122690769165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1316789035165625"><a name="p1316789035165625"></a><a name="p1316789035165625"></a><a href="MultiMedia_AudioCapturer.md#gad68b60d6ca82d096cbfa0f4205f2ae9e">OHOS::Audio::AudioCapturer::Release</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p124412031165625"><a name="p124412031165625"></a><a name="p124412031165625"></a>bool </p>
<p id="p7890182165625"><a name="p7890182165625"></a><a name="p7890182165625"></a>Releases a local <strong id="b1032360476165625"><a name="b1032360476165625"></a><a name="b1032360476165625"></a><a href="OHOS-Audio-AudioCapturer.md">AudioCapturer</a></strong> object. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section2051307272165625"></a>

## **Enumeration Type **<a name="section1407711336165625"></a>

## State<a name="ga3d8d6798a2346e57e241d16da673d508"></a>

```
enum [OHOS::Audio::State](MultiMedia_AudioCapturer.md#ga3d8d6798a2346e57e241d16da673d508) : uint32_t
```

 **Description:**

Enumerates the recording states of the current device. 

<a name="table2084453275165625"></a>
<table><thead align="left"><tr id="row1471253849165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2146552402165625"><a name="p2146552402165625"></a><a name="p2146552402165625"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1830313511165625"><a name="p1830313511165625"></a><a name="p1830313511165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1124184924165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga3d8d6798a2346e57e241d16da673d508a368f9c124fa478d643e6b3884bd4931c"><a name="gga3d8d6798a2346e57e241d16da673d508a368f9c124fa478d643e6b3884bd4931c"></a><a name="gga3d8d6798a2346e57e241d16da673d508a368f9c124fa478d643e6b3884bd4931c"></a></strong>PREPPARED </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p374601307165625"><a name="p374601307165625"></a><a name="p374601307165625"></a>Prepared </p>
 </td>
</tr>
<tr id="row1357968208165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga3d8d6798a2346e57e241d16da673d508a6d83cfbb144468bcd7f1d0609ba1a401"><a name="gga3d8d6798a2346e57e241d16da673d508a6d83cfbb144468bcd7f1d0609ba1a401"></a><a name="gga3d8d6798a2346e57e241d16da673d508a6d83cfbb144468bcd7f1d0609ba1a401"></a></strong>RECORDING </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1591548647165625"><a name="p1591548647165625"></a><a name="p1591548647165625"></a>Recording </p>
 </td>
</tr>
<tr id="row1192805077165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga3d8d6798a2346e57e241d16da673d508abc10d40a09b83e61c72dd68daa457399"><a name="gga3d8d6798a2346e57e241d16da673d508abc10d40a09b83e61c72dd68daa457399"></a><a name="gga3d8d6798a2346e57e241d16da673d508abc10d40a09b83e61c72dd68daa457399"></a></strong>STOPPED </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1998492881165625"><a name="p1998492881165625"></a><a name="p1998492881165625"></a>Stopped </p>
 </td>
</tr>
<tr id="row574856242165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga3d8d6798a2346e57e241d16da673d508ab061f3539998a6bcec9b4c11357b5ff2"><a name="gga3d8d6798a2346e57e241d16da673d508ab061f3539998a6bcec9b4c11357b5ff2"></a><a name="gga3d8d6798a2346e57e241d16da673d508ab061f3539998a6bcec9b4c11357b5ff2"></a></strong>RELEASED </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p658021680165625"><a name="p658021680165625"></a><a name="p658021680165625"></a>Released </p>
 </td>
</tr>
</tbody>
</table>

## Timebase<a name="gacdafb362a7da91799fa96163bca2a619"></a>

```
enum [OHOS::Audio::Timestamp::Timebase](MultiMedia_AudioCapturer.md#gacdafb362a7da91799fa96163bca2a619) : int32_t
```

 **Description:**

Enumerates the time base of this  **[Timestamp](OHOS-Audio-Timestamp.md)**. Different timing methods are supported. 

<a name="table788347169165625"></a>
<table><thead align="left"><tr id="row255962549165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p946798513165625"><a name="p946798513165625"></a><a name="p946798513165625"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1422886163165625"><a name="p1422886163165625"></a><a name="p1422886163165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1748753620165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggacdafb362a7da91799fa96163bca2a619a109ce01d0775b5372b9b2cc517630d39"><a name="ggacdafb362a7da91799fa96163bca2a619a109ce01d0775b5372b9b2cc517630d39"></a><a name="ggacdafb362a7da91799fa96163bca2a619a109ce01d0775b5372b9b2cc517630d39"></a></strong>MONOTONIC </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p390441745165625"><a name="p390441745165625"></a><a name="p390441745165625"></a>Monotonically increasing time, excluding the system sleep time </p>
 </td>
</tr>
<tr id="row1393978341165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggacdafb362a7da91799fa96163bca2a619aa0bb084304634f8cf8c9d41c5b87c0c3"><a name="ggacdafb362a7da91799fa96163bca2a619aa0bb084304634f8cf8c9d41c5b87c0c3"></a><a name="ggacdafb362a7da91799fa96163bca2a619aa0bb084304634f8cf8c9d41c5b87c0c3"></a></strong>BOOTTIME </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p168883474165625"><a name="p168883474165625"></a><a name="p168883474165625"></a>Monotonically increasing time, including the system sleep time </p>
 </td>
</tr>
</tbody>
</table>

## **Function **<a name="section200639590165625"></a>

## GetAudioTime\(\)<a name="gae24a95aeba747852373ef408bb9bab12"></a>

```
bool OHOS::Audio::AudioCapturer::GetAudioTime ([Timestamp](OHOS-Audio-Timestamp.md) & timestamp, [Timestamp::Timebase](MultiMedia_AudioCapturer.md#gacdafb362a7da91799fa96163bca2a619) base )
```

 **Description:**

Obtains the timestamp. 

**Parameters:**

<a name="table1225208539165625"></a>
<table><thead align="left"><tr id="row2089008502165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1879222128165625"><a name="p1879222128165625"></a><a name="p1879222128165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p39180528165625"><a name="p39180528165625"></a><a name="p39180528165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1304400998165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">timestamp</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates a <a href="OHOS-Audio-Timestamp.md">Timestamp</a> instance reference provided by the caller. </td>
</tr>
<tr id="row662792664165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">base</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the time base, which can be <a href="MultiMedia_AudioCapturer.md#ggacdafb362a7da91799fa96163bca2a619aa0bb084304634f8cf8c9d41c5b87c0c3">Timestamp.Timebase.BOOTTIME</a> or <a href="MultiMedia_AudioCapturer.md#ggacdafb362a7da91799fa96163bca2a619a109ce01d0775b5372b9b2cc517630d39">Timestamp.Timebase.MONOTONIC</a>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **true**  if the timestamp is successfully obtained; returns  **false**  otherwise. 

## GetCapturerInfo\(\)<a name="ga3921932035bfa99f7e7d8d0241344fca"></a>

```
int32_t OHOS::Audio::AudioCapturer::GetCapturerInfo ([AudioCapturerInfo](OHOS-Audio-AudioCapturerInfo.md) & info)
```

 **Description:**

Obtains audio capture parameters. 

This function can be called after  [SetCapturerInfo](MultiMedia_AudioCapturer.md#gae2cf055c840ece71e22cb64c98c68a19)  is successful.

**Parameters:**

<a name="table1800410438165625"></a>
<table><thead align="left"><tr id="row1333878099165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p51178922165625"><a name="p51178922165625"></a><a name="p51178922165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2085832826165625"><a name="p2085832826165625"></a><a name="p2085832826165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row671649739165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">info</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates information about audio capture parameters. For details, see <a href="OHOS-Audio-AudioCapturerInfo.md">AudioCapturerInfo</a>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **SUCCESS**  if the parameter information is successfully obtained; returns an error code defined in  [media\_errors.h](media_errors-h.md)  otherwise. 

## GetFrameCount\(\)<a name="gaf603a793bb5e97f000b11f57fa944ce1"></a>

```
uint64_t OHOS::Audio::AudioCapturer::GetFrameCount ()
```

 **Description:**

Obtains the number of frames required in the current condition, in bytes per sample. 

**Returns:**

Returns the number of frames \(in bytes per sample\) if the operation is successful; returns  **-1**  if an exception occurs. 

## GetMinFrameCount\(\)<a name="gac3f12dec86f94438758ba1a6ff6ed7da"></a>

```
static bool OHOS::Audio::AudioCapturer::GetMinFrameCount (int32_t sampleRate, int32_t channelCount, [AudioCodecFormat](MultiMedia_MediaCommon.md#gaa4ea6f314644ed287e0704be26c768b7) audioFormat, size_t & frameCount )
```

 **Description:**

Obtains the minimum number of frames required in a specified condition, in bytes per sample. 

**Parameters:**

<a name="table795790526165625"></a>
<table><thead align="left"><tr id="row286969936165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1865049687165625"><a name="p1865049687165625"></a><a name="p1865049687165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p77793253165625"><a name="p77793253165625"></a><a name="p77793253165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row17944753165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sampleRate</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the audio sampling rate, in Hz. </td>
</tr>
<tr id="row1587754008165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">channelCount</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the number of audio recording channels. </td>
</tr>
<tr id="row918147244165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">audioFormat</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the audio data format. </td>
</tr>
<tr id="row1298812840165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">frameCount</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the minimum number of frames, in bytes per sample. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **true**  if the minimum number of frames is successfully obtained; returns  **false**  otherwise. 

## GetStatus\(\)<a name="gaf022f9b98b1776799e86b689f7544a5e"></a>

```
[State](MultiMedia_AudioCapturer.md#ga3d8d6798a2346e57e241d16da673d508) OHOS::Audio::AudioCapturer::GetStatus ()
```

 **Description:**

Obtains the audio capture state. 

**Returns:**

Returns the audio capture state defined in  [State](AbilityKit.md#ga5d74787dedbc4e11c1ab15bf487e61f8). 

## Read\(\)<a name="ga75bccf0f21f7d9adc5e580f40abfc7d2"></a>

```
int32_t OHOS::Audio::AudioCapturer::Read (uint8_t * buffer, size_t userSize, bool isBlockingRead )
```

 **Description:**

Reads audio data. 

**Parameters:**

<a name="table529083415165625"></a>
<table><thead align="left"><tr id="row113544028165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1305970571165625"><a name="p1305970571165625"></a><a name="p1305970571165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1479608386165625"><a name="p1479608386165625"></a><a name="p1479608386165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1820849413165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">buffer</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the buffer into which the audio data is to be written. </td>
</tr>
<tr id="row950547827165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">userSize</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the size of the buffer into which the audio data is to be written, in bytes. <strong id="b12662659165625"><a name="b12662659165625"></a><a name="b12662659165625"></a>userSize &gt;= frameCount * channelCount * BytesPerSample</strong> must evaluate to <strong id="b1872798991165625"><a name="b1872798991165625"></a><a name="b1872798991165625"></a>true</strong>. You can call <a href="MultiMedia_AudioCapturer.md#gaf603a793bb5e97f000b11f57fa944ce1">GetFrameCount</a> to obtain the <strong id="b146153847165625"><a name="b146153847165625"></a><a name="b146153847165625"></a>frameCount</strong> value. </td>
</tr>
<tr id="row94514093165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">isBlockingRead</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Specifies whether data reading will be blocked. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the size of the audio data read from the device. The value ranges from  **0**  to  **userSize**. If the reading fails, one of the following error codes is returned:  **ERR\_INVALID\_PARAM**: The input parameter is incorrect.  **ERR\_ILLEGAL\_STATE**: The  **[AudioCapturer](OHOS-Audio-AudioCapturer.md)**  instance is not initialized.  **ERR\_SOURCE\_NOT\_SET**: The state of hardware device instance is abnormal. 

## Release\(\)<a name="gad68b60d6ca82d096cbfa0f4205f2ae9e"></a>

```
bool OHOS::Audio::AudioCapturer::Release ()
```

 **Description:**

Releases a local  **[AudioCapturer](OHOS-Audio-AudioCapturer.md)**  object. 

**Returns:**

Returns  **true**  if the object is successfully released; returns  **false**  otherwise. 

## SetCapturerInfo\(\)<a name="gae2cf055c840ece71e22cb64c98c68a19"></a>

```
int32_t OHOS::Audio::AudioCapturer::SetCapturerInfo (const [AudioCapturerInfo](OHOS-Audio-AudioCapturerInfo.md) info)
```

 **Description:**

Sets audio capture parameters. 

**Parameters:**

<a name="table1542600843165625"></a>
<table><thead align="left"><tr id="row435800921165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1148179556165625"><a name="p1148179556165625"></a><a name="p1148179556165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p202058640165625"><a name="p202058640165625"></a><a name="p202058640165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1149101510165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">info</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates information about audio capture parameters to set. For details, see <a href="OHOS-Audio-AudioCapturerInfo.md">AudioCapturerInfo</a>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **SUCCESS**  if the setting is successful; returns an error code defined in  [media\_errors.h](media_errors-h.md)  otherwise. 

## Start\(\)<a name="gac3391374f9a180d84aa5bd19236743a1"></a>

```
bool OHOS::Audio::AudioCapturer::Start ()
```

 **Description:**

Starts audio recording. 

**Returns:**

Returns  **true**  if the recording is successfully started; returns  **false**  otherwise. 

## Stop\(\)<a name="ga498a8a4d0a2c09418944eab7728bdc7b"></a>

```
bool OHOS::Audio::AudioCapturer::Stop ()
```

 **Description:**

Stops audio recording. 

**Returns:**

Returns  **true**  if the recording is successfully stopped; returns  **false**  otherwise. 

## **Variable **<a name="section1593978958165625"></a>

## audioFormat<a name="ga6a222ecc5112fb2925879dba686c12a3"></a>

```
[AudioCodecFormat](MultiMedia_MediaCommon.md#gaa4ea6f314644ed287e0704be26c768b7) OHOS::Audio::AudioCapturerInfo::audioFormat = [AUDIO_DEFAULT](MultiMedia_MediaCommon.md#ggaa4ea6f314644ed287e0704be26c768b7a4c4c5829b054bc468274700c56d65546)
```

 **Description:**

Audio codec format 

## bitRate<a name="gace7d68d68754fc267117003f7fc76522"></a>

```
int32_t OHOS::Audio::AudioCapturerInfo::bitRate = 0
```

 **Description:**

Bit rate 

## bitWidth<a name="ga110704c5058747a6180c250b0a77d685"></a>

```
[AudioBitWidth](MultiMedia_MediaCommon.md#gae3e35ee2a2222a667fdebbc5b793ca7c) OHOS::Audio::AudioCapturerInfo::bitWidth = [BIT_WIDTH_16](MultiMedia_MediaCommon.md#ggae3e35ee2a2222a667fdebbc5b793ca7ca036f0b45813f96cb6b0f90de1722a780)
```

 **Description:**

Bit width 

## channelCount<a name="ga3219851b0a3e355a8519c9262f879e47"></a>

```
int32_t OHOS::Audio::AudioCapturerInfo::channelCount = 0
```

 **Description:**

Number of audio channels 

## inputSource<a name="ga9c14165a8197521b8a539bd5408f66ed"></a>

```
[AudioSourceType](MultiMedia_MediaCommon.md#gadc3158e093b995ca7b9b6aa32388ccdd) OHOS::Audio::AudioCapturerInfo::inputSource = [AUDIO_MIC](MultiMedia_MediaCommon.md#ggadc3158e093b995ca7b9b6aa32388ccdda732604b3a24d137429e2b83b31849bce)
```

 **Description:**

Audio source type 

## sampleRate<a name="gab623e99855bc46fe9d3dbfacb67e419a"></a>

```
int32_t OHOS::Audio::AudioCapturerInfo::sampleRate = 0
```

 **Description:**

Sampling rate 

## streamType<a name="gaaa038f040e203e553aba28e80f26f733"></a>

```
[AudioStreamType](MultiMedia_MediaCommon.md#gae7077e4211e48131ae544adb20fc494a) OHOS::Audio::AudioCapturerInfo::streamType = [TYPE_MEDIA](MultiMedia_MediaCommon.md#ggae7077e4211e48131ae544adb20fc494aa431e273affaa22e18ec5a2a548b70e90)
```

 **Description:**

Audio stream type 

