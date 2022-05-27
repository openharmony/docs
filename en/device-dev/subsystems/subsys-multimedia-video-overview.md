# Audio/Video Overview<a name="EN-US_TOPIC_0000001051770578"></a>

OpenHarmony multimedia services help you to develop for audio and video playback and recording.

-   The media playback module facilitates the development of audio and video playback, including media file and stream playback, volume control, and playback progress control.
-   The media recording module supports the development of audio and video recording and provides functions to set the size of captured video, encoding bit rate, encoder type, video frame rate, audio sampling rate, and output file format.

## Basic Concepts<a name="section967213571204"></a>

It is considered good practice that you understand the following concepts before starting development:

-   Streaming media technology

    The streaming media technology refers to a process to encode continuous video and audio data and store the data on a network server. A viewer can watch and listen to the video and audio during download with no need to wait for the completion of download.


-   Video frame rate

    The frame rate is used to measure the number of displayed frames, which is the number of images transmitted per second. The more frames per second \(FPS\), the smoother the video.

-   Bit rate

    Bit rate is the number of bits transmitted per unit of time. The commonly used unit is kbit/s.

-   Sampling rate

    The sampling rate is the number of samples per second taken from continuous signals to form discrete signals. The unit is hertz \(Hz\).


## Encoding and Decoding<a name="section1582020483111"></a>

Available audio and video encoding and decoding capabilities vary depending on device types. The following table lists supported specifications for available development boards.

**Table  1**  Encoding and decoding specifications for different development boards

<a name="table1611142712535"></a>
<table><thead align="left"><tr id="row5129278531"><th class="cellrowborder" valign="top" width="7.520752075207521%" id="mcps1.2.5.1.1"><p id="p163711594517"><a name="p163711594517"></a><a name="p163711594517"></a>Device Type</p>
</th>
<th class="cellrowborder" valign="top" width="8.24082408240824%" id="mcps1.2.5.1.2"><p id="p1112727195316"><a name="p1112727195316"></a><a name="p1112727195316"></a>Development Board</p>
</th>
<th class="cellrowborder" valign="top" width="40.82408240824083%" id="mcps1.2.5.1.3"><p id="p14124279538"><a name="p14124279538"></a><a name="p14124279538"></a>Decoding</p>
</th>
<th class="cellrowborder" valign="top" width="43.41434143414341%" id="mcps1.2.5.1.4"><p id="p812132715535"><a name="p812132715535"></a><a name="p812132715535"></a>Encoding</p>
</th>
</tr>
</thead>
<tbody><tr id="row712427195316"><td class="cellrowborder" valign="top" width="7.520752075207521%" headers="mcps1.2.5.1.1 "><p id="p19371179459"><a name="p19371179459"></a><a name="p19371179459"></a>Cameras with a screen</p>
</td>
<td class="cellrowborder" valign="top" width="8.24082408240824%" headers="mcps1.2.5.1.2 "><p id="p1312182713535"><a name="p1312182713535"></a><a name="p1312182713535"></a>Hi3516</p>
</td>
<td class="cellrowborder" valign="top" width="40.82408240824083%" headers="mcps1.2.5.1.3 "><a name="ul178862023587"></a><a name="ul178862023587"></a><ul id="ul178862023587"><li>Audio: MPEG-4 AAC Profile (AAC LC), MPEG Audio Layer 3 (MP3), mono and dual channels, MPEG-4 (.mp4 and .m4a), and MP3 (.mp3) are supported.</li><li>Video: The H.265 (HEVC) and H.264 (AVC) (for streams encoded using a chip of the same type) and the MPEG-4 (.mp4) container format are supported.</li></ul>
</td>
<td class="cellrowborder" valign="top" width="43.41434143414341%" headers="mcps1.2.5.1.4 "><a name="ul5101301882"></a><a name="ul5101301882"></a><ul id="ul5101301882"><li>Audio: AAC-LC encoding, mono and dual channels, and the MPEG-4 (.mp4) container format are supported.</li><li>Video: H.264 and H.265 encoding and the MPEG-4 (.mp4) container format are supported.</li></ul>
</td>
</tr>
<tr id="row01212273532"><td class="cellrowborder" valign="top" width="7.520752075207521%" headers="mcps1.2.5.1.1 "><p id="p33711914515"><a name="p33711914515"></a><a name="p33711914515"></a>Cameras without a screen</p>
</td>
<td class="cellrowborder" valign="top" width="8.24082408240824%" headers="mcps1.2.5.1.2 "><p id="p51202713531"><a name="p51202713531"></a><a name="p51202713531"></a>Hi3518</p>
</td>
<td class="cellrowborder" valign="top" width="40.82408240824083%" headers="mcps1.2.5.1.3 "><a name="ul11786193316820"></a><a name="ul11786193316820"></a><ul id="ul11786193316820"><li>Audio: MPEG-4 AAC Profile (AAC LC), MPEG Audio Layer 3 (MP3), mono and dual channels, MPEG-4 (.mp4 and .m4a), and MP3 (.mp3) are supported.</li><li>Video: none</li></ul>
</td>
<td class="cellrowborder" valign="top" width="43.41434143414341%" headers="mcps1.2.5.1.4 "><a name="ul816485812814"></a><a name="ul816485812814"></a><ul id="ul816485812814"><li>Audio: AAC-LC encoding, mono and dual channels, and the MPEG-4 (.mp4) container format are supported.</li><li>Video: H.264 and H.265 encoding and the MPEG-4 (.mp4) container format are supported.</li></ul>
</td>
</tr>
<tr id="row1812172713534"><td class="cellrowborder" valign="top" width="7.520752075207521%" headers="mcps1.2.5.1.1 "><p id="p6371594514"><a name="p6371594514"></a><a name="p6371594514"></a>WLAN connecting devices</p>
</td>
<td class="cellrowborder" valign="top" width="8.24082408240824%" headers="mcps1.2.5.1.2 "><p id="p1212927165318"><a name="p1212927165318"></a><a name="p1212927165318"></a>Hi3861</p>
</td>
<td class="cellrowborder" valign="top" width="40.82408240824083%" headers="mcps1.2.5.1.3 "><p id="p9122271537"><a name="p9122271537"></a><a name="p9122271537"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="43.41434143414341%" headers="mcps1.2.5.1.4 "><p id="p2012122713531"><a name="p2012122713531"></a><a name="p2012122713531"></a>N/A</p>
</td>
</tr>
</tbody>
</table>

For details about the encoding and decoding specifications of Hi3516 and Hi3518, refer to their documentation.

