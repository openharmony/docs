# audio\_capturer.h<a name="EN-US_TOPIC_0000001054879490"></a>

-   [Overview](#section1073505584165626)
-   [Summary](#section1913449047165626)
-   [Data Structures](#nested-classes)
-   [Enumerations](#enum-members)

## **Overview**<a name="section1073505584165626"></a>

**Related Modules:**

[MultiMedia\_AudioCapturer](multimedia_audiocapturer.md)

**Description:**

Provides the  **AudioCapturer**  class to implement operations related to audio capture. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1913449047165626"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table1696614604165626"></a>
<table><thead align="left"><tr id="row949666040165626"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p737820652165626"><a name="p737820652165626"></a><a name="p737820652165626"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p414554528165626"><a name="p414554528165626"></a><a name="p414554528165626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row283124221165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p282227888165626"><a name="p282227888165626"></a><a name="p282227888165626"></a><a href="ohos-audio-audiocapturerinfo.md">OHOS::Audio::AudioCapturerInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1789230176165626"><a name="p1789230176165626"></a><a name="p1789230176165626"></a>Defines information about audio capture parameters, including the input source, audio codec format,sampling rate (Hz), number of audio channels, bit rate, and bit width. </p>
</td>
</tr>
<tr id="row179357931165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p764423471165626"><a name="p764423471165626"></a><a name="p764423471165626"></a><a href="ohos-audio-timestamp.md">OHOS::Audio::Timestamp</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p484423922165626"><a name="p484423922165626"></a><a name="p484423922165626"></a>Represents timestamp information, including the frame position information and high-resolution time source. </p>
</td>
</tr>
<tr id="row1268828389165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1252470899165626"><a name="p1252470899165626"></a><a name="p1252470899165626"></a><a href="ohos-audio-audiocapturer.md">OHOS::Audio::AudioCapturer</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p467499339165626"><a name="p467499339165626"></a><a name="p467499339165626"></a>Provides functions for applications to implement audio capturing. </p>
</td>
</tr>
</tbody>
</table>

## Enumerations<a name="enum-members"></a>

<a name="table1013972093165626"></a>
<table><thead align="left"><tr id="row1296226782165626"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1803192023165626"><a name="p1803192023165626"></a><a name="p1803192023165626"></a>Enumeration Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p401866113165626"><a name="p401866113165626"></a><a name="p401866113165626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1311563284165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1786475737165626"><a name="p1786475737165626"></a><a name="p1786475737165626"></a><a href="multimedia_audiocapturer.md#ga3d8d6798a2346e57e241d16da673d508">OHOS::Audio::State</a> : uint32_t { <a href="multimedia_audiocapturer.md#gga3d8d6798a2346e57e241d16da673d508a368f9c124fa478d643e6b3884bd4931c">OHOS::Audio::PREPPARED</a>, <a href="multimedia_audiocapturer.md#gga3d8d6798a2346e57e241d16da673d508a6d83cfbb144468bcd7f1d0609ba1a401">OHOS::Audio::RECORDING</a>, <a href="multimedia_audiocapturer.md#gga3d8d6798a2346e57e241d16da673d508abc10d40a09b83e61c72dd68daa457399">OHOS::Audio::STOPPED</a>, <a href="multimedia_audiocapturer.md#gga3d8d6798a2346e57e241d16da673d508ab061f3539998a6bcec9b4c11357b5ff2">OHOS::Audio::RELEASED</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1578323611165626"><a name="p1578323611165626"></a><a name="p1578323611165626"></a>Enumerates the recording states of the current device. </p>
</td>
</tr>
</tbody>
</table>

