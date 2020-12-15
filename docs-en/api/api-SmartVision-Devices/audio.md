# Audio<a name="EN-US_TOPIC_0000001054479511"></a>

-   [Overview](#section1599351033165623)
-   [Summary](#section1361003411165623)
-   [Files](#files)
-   [Data Structures](#nested-classes)
-   [Typedefs](#typedef-members)
-   [Enumerations](#enum-members)
-   [Functions](#func-members)
-   [Details](#section1693660607165623)
-   [Enumeration Type](#section1289870715165623)
-   [AudioCategory](#gaf210d41d152890f3aaf2aaac99bd28d5)
-   [AudioChannelMask](#ga137eb03027d5947ea294b32f5095b83c)
-   [AudioChannelMode](#ga78aab1fafb9657451804e42b42897123)
-   [AudioFormat](#ga98d5d077cca088ddf77314871474fe59)
-   [AudioPortDirection](#ga68ff7140b15790debbac4bbc62f8e9f8)
-   [AudioPortPassthroughMode](#ga186d2d4f9a2ecacb80cd2cce2bd26f0e)
-   [AudioPortPin](#gaa7114aeeccf3ac4f5f7e1d880bcfa835)
-   [AudioSampleRatesMask](#ga7053fcaa56d1dc47d2fcd83ee131fe4c)
-   [Function](#section521503694165623)
-   [GetAudioManagerFuncs\(\)](#ga0c7824f4fe89625d3c9b1d0534ad0151)
-   [Variable](#section1960727737165623)
-   [adapterName](#gadbe46bc7d9b4c20c409e30942ad794cf)
-   [channelCount \[1/2\]](#ga9c629d8ad8f0119d9b0acae3f2ed9b78)
-   [channelCount \[2/2\]](#ga48253c4fbc171f241bb0494524891bb1)
-   [channelMasks](#ga357e90ee8116e04144f57e6f7d3d9efb)
-   [desc \[1/4\]](#ga560700ce0e6f047a617e21b41e0425b9)
-   [desc \[2/4\]](#gab855beab3a08e8c9a7f814cce53e2001)
-   [desc \[3/4\]](#ga81e44604a869f47c88c3f9503b9287e1)
-   [desc \[4/4\]](#gafe579a4229429c8665d1c3d95fc1f964)
-   [deviceId](#ga0485197a750c63938602b339a3b9c77f)
-   [deviceType](#ga00860eb6de81efe5b1654b45617fb902)
-   [dir](#ga144336f0f64927730a184c16d8c27698)
-   [format](#ga441305acec64ee1ed840c8920e167c9e)
-   [formatNum](#gaca895984cf53ddd8769d33c8298b0c6d)
-   [formats](#gad01bfa329a21628287ee21df5000e34d)
-   [hardwareMode](#ga377ecdaf229087a7d17c220a65a7162f)
-   [id](#ga3e54db28a854f634bd847919e7ae8e32)
-   [interleaved](#gab00c777b594436a4fae1a4bcdad70c6d)
-   [mask](#ga958a6104e7ab64f75618015bfb097a32)
-   [pins](#gab2e66ca83a7ef39211b53d4afe7b7b73)
-   [portId \[1/3\]](#gaa534605f1ef1993f47063c3f7fbccbde)
-   [portId \[2/3\]](#gabc4bdf3c11cada00cfebbd9b1218ab3a)
-   [portId \[3/3\]](#ga4b35c30d09b716f0bd2c7c22587e3f7a)
-   [portName](#ga6cbf88ceff4bcd03b125d45873e654a1)
-   [portNum](#ga2bef8f9b5ea3c1e30639fcb3ec8dd717)
-   [ports](#ga64d0c55b881fb0a3bc15b2fecea86f24)
-   [sampleRate](#gaa322b72a4cdf9007c75814853e7ad4af)
-   [sampleRateMasks](#ga30c8a08e5d939c0e9844d6d9a165c681)
-   [scene](#ga3246105a88851b68c71e16a511ea6b47)
-   [subPorts](#gaccd18b70e7d121169f3df5e53fe055f9)
-   [subPortsNum](#gab784694fd6a60a3d5a3ae404cd6fe6fd)
-   [tvNSec](#gadae6151a2f7e0432dbaf6e89e743de9c)
-   [tvSec](#gaa6205cc4d86425bc23f2d860f44644ce)
-   [type](#ga658c38c76290ea6c8b9e0a2ddf7d1db4)

## **Overview**<a name="section1599351033165623"></a>

**Description:**

Defines audio-related APIs, including custom data types and functions for loading drivers, accessing a driver adapter, and rendering and capturing audios. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1361003411165623"></a>

## Files<a name="files"></a>

<a name="table1168632461165623"></a>
<table><thead align="left"><tr id="row141474878165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1531313803165623"><a name="p1531313803165623"></a><a name="p1531313803165623"></a>File Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p115047479165623"><a name="p115047479165623"></a><a name="p115047479165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row429872976165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1169756605165623"><a name="p1169756605165623"></a><a name="p1169756605165623"></a><a href="audio_adapter-h.md">audio_adapter.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p990677477165623"><a name="p990677477165623"></a><a name="p990677477165623"></a>Declares APIs for operations related to the audio adapter. </p>
</td>
</tr>
<tr id="row1868432324165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p754494986165623"><a name="p754494986165623"></a><a name="p754494986165623"></a><a href="audio_attribute-h.md">audio_attribute.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p68662884165623"><a name="p68662884165623"></a><a name="p68662884165623"></a>Declares APIs for audio attributes. </p>
</td>
</tr>
<tr id="row1620052951165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p46727262165623"><a name="p46727262165623"></a><a name="p46727262165623"></a><a href="audio_capture-h.md">audio_capture.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1659673919165623"><a name="p1659673919165623"></a><a name="p1659673919165623"></a>Declares APIs for audio capturing. </p>
</td>
</tr>
<tr id="row1911092248165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p845098667165623"><a name="p845098667165623"></a><a name="p845098667165623"></a><a href="audio_control-h.md">audio_control.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2024921161165623"><a name="p2024921161165623"></a><a name="p2024921161165623"></a>Declares APIs for audio control. </p>
</td>
</tr>
<tr id="row1035530097165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2085433306165623"><a name="p2085433306165623"></a><a name="p2085433306165623"></a><a href="audio_manager-h.md">audio_manager.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1101436455165623"><a name="p1101436455165623"></a><a name="p1101436455165623"></a>Declares APIs for audio adapter management and loading. </p>
</td>
</tr>
<tr id="row1986706998165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1440368951165623"><a name="p1440368951165623"></a><a name="p1440368951165623"></a><a href="audio_render-h.md">audio_render.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1203760883165623"><a name="p1203760883165623"></a><a name="p1203760883165623"></a>Declares APIs for audio rendering. </p>
</td>
</tr>
<tr id="row550326219165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p69958760165623"><a name="p69958760165623"></a><a name="p69958760165623"></a><a href="audio_scene-h.md">audio_scene.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p526874801165623"><a name="p526874801165623"></a><a name="p526874801165623"></a>Declares APIs for audio scenes. </p>
</td>
</tr>
<tr id="row416745478165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2025998834165623"><a name="p2025998834165623"></a><a name="p2025998834165623"></a><a href="audio_types-h.md">audio_types.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p398912655165623"><a name="p398912655165623"></a><a name="p398912655165623"></a>Defines custom data types used in API declarations for the audio module, including audio ports, adapter descriptors, device descriptors, scene descriptors, sampling attributes, and timestamp. </p>
</td>
</tr>
<tr id="row179600216165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1516236281165623"><a name="p1516236281165623"></a><a name="p1516236281165623"></a><a href="audio_volume-h.md">audio_volume.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2018667507165623"><a name="p2018667507165623"></a><a name="p2018667507165623"></a>Declares APIs for audio volume. </p>
</td>
</tr>
</tbody>
</table>

## Data Structures<a name="nested-classes"></a>

<a name="table259539039165623"></a>
<table><thead align="left"><tr id="row1818562973165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p245159791165623"><a name="p245159791165623"></a><a name="p245159791165623"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1242168077165623"><a name="p1242168077165623"></a><a name="p1242168077165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row239668558165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p438192124165623"><a name="p438192124165623"></a><a name="p438192124165623"></a><a href="audioadapter.md">AudioAdapter</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p880835074165623"><a name="p880835074165623"></a><a name="p880835074165623"></a>Provides audio adapter capabilities, including initializing ports, creating rendering and capturing tasks, and obtaining the port capability set. </p>
</td>
</tr>
<tr id="row1485042461165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2088782766165623"><a name="p2088782766165623"></a><a name="p2088782766165623"></a><a href="audioattribute.md">AudioAttribute</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p437333177165623"><a name="p437333177165623"></a><a name="p437333177165623"></a>Provides attribute-related APIs for audio rendering or capturing, including functions to obtain frame information and set audio sampling attributes. </p>
</td>
</tr>
<tr id="row1027159935165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1546365008165623"><a name="p1546365008165623"></a><a name="p1546365008165623"></a><a href="audiocapture.md">AudioCapture</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2119288074165623"><a name="p2119288074165623"></a><a name="p2119288074165623"></a>Provides capabilities for audio capturing, including controlling the capturing, setting audio attributes, scenes, and volume, and capturing audio frames. </p>
</td>
</tr>
<tr id="row950637663165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2079729676165623"><a name="p2079729676165623"></a><a name="p2079729676165623"></a><a href="audiocontrol.md">AudioControl</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1493860525165623"><a name="p1493860525165623"></a><a name="p1493860525165623"></a>Provides control-related APIs for audio rendering or capturing, including functions to start, stop, pause, and resume audio rendering or capturing, and flush data in the audio buffer. </p>
</td>
</tr>
<tr id="row1448185765165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2069965493165623"><a name="p2069965493165623"></a><a name="p2069965493165623"></a><a href="audiomanager.md">AudioManager</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p288962300165623"><a name="p288962300165623"></a><a name="p288962300165623"></a>Manages audio adapters through a specific adapter driver program loaded based on the given audio adapter descriptor. </p>
</td>
</tr>
<tr id="row2133381411165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p955985137165623"><a name="p955985137165623"></a><a name="p955985137165623"></a><a href="audiorender.md">AudioRender</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1109336680165623"><a name="p1109336680165623"></a><a name="p1109336680165623"></a>Provides capabilities for audio rendering, including controlling the rendering, setting audio attributes, scenes, and volume, obtaining hardware latency, and rendering audio frames. </p>
</td>
</tr>
<tr id="row950752826165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p809449475165623"><a name="p809449475165623"></a><a name="p809449475165623"></a><a href="audioscene.md">AudioScene</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1734934175165623"><a name="p1734934175165623"></a><a name="p1734934175165623"></a>Provides scene-related APIs for audio rendering or capturing, including functions to select an audio scene and check whether the configuration of an audio scene is supported. </p>
</td>
</tr>
<tr id="row1096212107165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1053343373165623"><a name="p1053343373165623"></a><a name="p1053343373165623"></a><a href="audioport.md">AudioPort</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p474106265165623"><a name="p474106265165623"></a><a name="p474106265165623"></a>Defines the audio port. </p>
</td>
</tr>
<tr id="row1111947989165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p116408070165623"><a name="p116408070165623"></a><a name="p116408070165623"></a><a href="audioadapterdescriptor.md">AudioAdapterDescriptor</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1441122639165623"><a name="p1441122639165623"></a><a name="p1441122639165623"></a>Defines the audio adapter descriptor. </p>
</td>
</tr>
<tr id="row249924241165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1904198241165623"><a name="p1904198241165623"></a><a name="p1904198241165623"></a><a href="audiodevicedescriptor.md">AudioDeviceDescriptor</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1583519048165623"><a name="p1583519048165623"></a><a name="p1583519048165623"></a>Defines the audio device descriptor. </p>
</td>
</tr>
<tr id="row1635095973165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1935699400165623"><a name="p1935699400165623"></a><a name="p1935699400165623"></a><a href="audioscenedescriptor.md">AudioSceneDescriptor</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1437470721165623"><a name="p1437470721165623"></a><a name="p1437470721165623"></a>Defines the audio scene descriptor. </p>
</td>
</tr>
<tr id="row867691687165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p854778670165623"><a name="p854778670165623"></a><a name="p854778670165623"></a><a href="audioscenedescriptor-scenedesc.md">AudioSceneDescriptor::SceneDesc</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2007929769165623"><a name="p2007929769165623"></a><a name="p2007929769165623"></a>Describes the audio scene. </p>
</td>
</tr>
<tr id="row196659138165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1572302446165623"><a name="p1572302446165623"></a><a name="p1572302446165623"></a><a href="audiosampleattributes.md">AudioSampleAttributes</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1071798492165623"><a name="p1071798492165623"></a><a name="p1071798492165623"></a>Defines audio sampling attributes. </p>
</td>
</tr>
<tr id="row683709541165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1477977750165623"><a name="p1477977750165623"></a><a name="p1477977750165623"></a><a href="audiotimestamp.md">AudioTimeStamp</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p771386694165623"><a name="p771386694165623"></a><a name="p771386694165623"></a>Defines the audio timestamp, which is a substitute for POSIX <strong id="b2147051719165623"><a name="b2147051719165623"></a><a name="b2147051719165623"></a>timespec</strong>. </p>
</td>
</tr>
<tr id="row716285290165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1066876877165623"><a name="p1066876877165623"></a><a name="p1066876877165623"></a><a href="audiosubportcapability.md">AudioSubPortCapability</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2069401904165623"><a name="p2069401904165623"></a><a name="p2069401904165623"></a>Defines the sub-port capability. </p>
</td>
</tr>
<tr id="row927158306165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1213923137165623"><a name="p1213923137165623"></a><a name="p1213923137165623"></a><a href="audioportcapability.md">AudioPortCapability</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p555911653165623"><a name="p555911653165623"></a><a name="p555911653165623"></a>Defines the audio port capability. </p>
</td>
</tr>
<tr id="row1883940470165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p362019067165623"><a name="p362019067165623"></a><a name="p362019067165623"></a><a href="audiovolume.md">AudioVolume</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1894923260165623"><a name="p1894923260165623"></a><a name="p1894923260165623"></a>Provides volume-related APIs for audio rendering or capturing, including functions to set the mute operation, volume, and gain. </p>
</td>
</tr>
</tbody>
</table>

## Typedefs<a name="typedef-members"></a>

<a name="table65404770165623"></a>
<table><thead align="left"><tr id="row1827108869165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1336027397165623"><a name="p1336027397165623"></a><a name="p1336027397165623"></a>Typedef Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1857747516165623"><a name="p1857747516165623"></a><a name="p1857747516165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1681700783165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p499604536165623"><a name="p499604536165623"></a><a name="p499604536165623"></a>AudioHandle </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p604207739165623"><a name="p604207739165623"></a><a name="p604207739165623"></a><strong id="ga18675ddb073465fdeac33a897f675d79"><a name="ga18675ddb073465fdeac33a897f675d79"></a><a name="ga18675ddb073465fdeac33a897f675d79"></a></strong> typedef void * </p>
<p id="p16544215165623"><a name="p16544215165623"></a><a name="p16544215165623"></a>Defines the audio handle. </p>
</td>
</tr>
</tbody>
</table>

## Enumerations<a name="enum-members"></a>

<a name="table245640106165623"></a>
<table><thead align="left"><tr id="row1108013999165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1458563653165623"><a name="p1458563653165623"></a><a name="p1458563653165623"></a>Enumeration Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1087654671165623"><a name="p1087654671165623"></a><a name="p1087654671165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1820452184165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1713622551165623"><a name="p1713622551165623"></a><a name="p1713622551165623"></a><a href="audio.md#ga68ff7140b15790debbac4bbc62f8e9f8">AudioPortDirection</a> { <a href="audio.md#gga68ff7140b15790debbac4bbc62f8e9f8af54f110a0f64337d474989fbac06bc22">PORT_OUT</a> = 0x1u, <a href="audio.md#gga68ff7140b15790debbac4bbc62f8e9f8a154a6db110515b7afde52d3a36d57846">PORT_IN</a> = 0x2u, <a href="audio.md#gga68ff7140b15790debbac4bbc62f8e9f8a87e14fe9da9c332ba29185b9213d7bbf">PORT_OUT_IN</a> = 0x3u }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1592133909165623"><a name="p1592133909165623"></a><a name="p1592133909165623"></a>Enumerates the audio port type. </p>
</td>
</tr>
<tr id="row1383550929165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1814541676165623"><a name="p1814541676165623"></a><a name="p1814541676165623"></a><a href="audio.md#gaa7114aeeccf3ac4f5f7e1d880bcfa835">AudioPortPin</a> {   <a href="audio.md#ggaa7114aeeccf3ac4f5f7e1d880bcfa835ad2f867652c04c17517db7731af03bf20">PIN_NONE</a> = 0x0u, <a href="audio.md#ggaa7114aeeccf3ac4f5f7e1d880bcfa835ab1070439bab93e06446c21157771dd6f">PIN_OUT_SPEAKER</a> = 0x1u, <a href="audio.md#ggaa7114aeeccf3ac4f5f7e1d880bcfa835a271013721c8840cc2700c19b3ff8d0a6">PIN_OUT_HEADSET</a> = 0x2u, <a href="audio.md#ggaa7114aeeccf3ac4f5f7e1d880bcfa835a411e9037214c75d22c9080505cf9cae6">PIN_OUT_LINEOUT</a> = 0x4u,   <a href="audio.md#ggaa7114aeeccf3ac4f5f7e1d880bcfa835ab4aaa2ec71ec77480f60743cd79340b9">PIN_OUT_HDMI</a> = 0x8u, <a href="audio.md#ggaa7114aeeccf3ac4f5f7e1d880bcfa835a336001f5685d9c206b1251714553b485">PIN_IN_MIC</a> = 0x8000001u, <a href="audio.md#ggaa7114aeeccf3ac4f5f7e1d880bcfa835aaeca21ac0a7b249905d1cea5b683f574">PIN_IN_HS_MIC</a> = 0x8000002u, <a href="audio.md#ggaa7114aeeccf3ac4f5f7e1d880bcfa835a5146add03ff98f06648567bb0e02a477">PIN_IN_LINEIN</a> = 0x8000004u }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1260365389165623"><a name="p1260365389165623"></a><a name="p1260365389165623"></a>Enumerates the pin of an audio adapter. </p>
</td>
</tr>
<tr id="row797487722165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1578369501165623"><a name="p1578369501165623"></a><a name="p1578369501165623"></a><a href="audio.md#gaf210d41d152890f3aaf2aaac99bd28d5">AudioCategory</a> { <a href="audio.md#ggaf210d41d152890f3aaf2aaac99bd28d5a6ac6cfd90dcc34de100c1cecb3df44c3">AUDIO_IN_MEDIA</a> = 0, <a href="audio.md#ggaf210d41d152890f3aaf2aaac99bd28d5a474576c773934a0df994bad4cf781b41">AUDIO_IN_COMMUNICATION</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1766403120165623"><a name="p1766403120165623"></a><a name="p1766403120165623"></a>Enumerates the audio category. </p>
</td>
</tr>
<tr id="row1236334476165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2075231383165623"><a name="p2075231383165623"></a><a name="p2075231383165623"></a><a href="audio.md#ga98d5d077cca088ddf77314871474fe59">AudioFormat</a> {   <a href="audio.md#gga98d5d077cca088ddf77314871474fe59a321cc2160af35aa86b8ee55f231ef1e6">AUDIO_FORMAT_PCM_8_BIT</a> = 0x1u, <a href="audio.md#gga98d5d077cca088ddf77314871474fe59ae188cf87c8f2e6218c74b3b2385068e6">AUDIO_FORMAT_PCM_16_BIT</a> = 0x2u, <a href="audio.md#gga98d5d077cca088ddf77314871474fe59a21eb864e2117df577dcd90ad81da3b14">AUDIO_FORMAT_PCM_24_BIT</a> = 0x3u, <a href="audio.md#gga98d5d077cca088ddf77314871474fe59adf7a0bf1f3dd15c9c43fac07c0c6ea26">AUDIO_FORMAT_PCM_32_BIT</a> = 0x4u,   <a href="audio.md#gga98d5d077cca088ddf77314871474fe59a5a781e6f8b145066ae7fb2c310804bab">AUDIO_FORMAT_AAC_MAIN</a> = 0x1000001u, <a href="audio.md#gga98d5d077cca088ddf77314871474fe59a3d4bc5d534d0452635455ed8d2cade57">AUDIO_FORMAT_AAC_LC</a> = 0x1000002u, <a href="audio.md#gga98d5d077cca088ddf77314871474fe59ad4baf87ff9f4684c03483c572052b700">AUDIO_FORMAT_AAC_LD</a> = 0x1000003u, <a href="audio.md#gga98d5d077cca088ddf77314871474fe59a4b8d42988fecf03e2bf73c4395501852">AUDIO_FORMAT_AAC_ELD</a> = 0x1000004u,   <a href="audio.md#gga98d5d077cca088ddf77314871474fe59abaddb86f122d3185de9407dbc673bf0e">AUDIO_FORMAT_AAC_HE_V1</a> = 0x1000005u, <a href="audio.md#gga98d5d077cca088ddf77314871474fe59ab610e0121e0b5076b3f78831e3c237fd">AUDIO_FORMAT_AAC_HE_V2</a> = 0x1000006u }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1769730660165623"><a name="p1769730660165623"></a><a name="p1769730660165623"></a>Enumerates the audio format. </p>
</td>
</tr>
<tr id="row48771753165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p609190683165623"><a name="p609190683165623"></a><a name="p609190683165623"></a><a href="audio.md#ga137eb03027d5947ea294b32f5095b83c">AudioChannelMask</a> { <a href="audio.md#gga137eb03027d5947ea294b32f5095b83ca0419483310bfc5abe46a0c586070ed18">AUDIO_CHANNEL_FRONT_LEFT</a> = 0x1, <a href="audio.md#gga137eb03027d5947ea294b32f5095b83ca05525a25c5912eda05e9a8786a743a75">AUDIO_CHANNEL_FRONT_RIGHT</a> = 0x2, <a href="audio.md#gga137eb03027d5947ea294b32f5095b83ca0479e1cd2137cbbad68efae1d2b2c9a9">AUDIO_CHANNEL_MONO</a> = 0x1u, <a href="audio.md#gga137eb03027d5947ea294b32f5095b83ca70f2212ea5439c13f7fcba3e30b15c1a">AUDIO_CHANNEL_STEREO</a> = 0x3u }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p100815167165623"><a name="p100815167165623"></a><a name="p100815167165623"></a>Enumerates the audio channel mask. </p>
</td>
</tr>
<tr id="row639143652165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p553829931165623"><a name="p553829931165623"></a><a name="p553829931165623"></a><a href="audio.md#ga7053fcaa56d1dc47d2fcd83ee131fe4c">AudioSampleRatesMask</a> {   <a href="audio.md#gga7053fcaa56d1dc47d2fcd83ee131fe4ca046a26906a4df81bfc38c583ba3606e9">AUDIO_SAMPLE_RATE_MASK_8000</a> = 0x1u, <a href="audio.md#gga7053fcaa56d1dc47d2fcd83ee131fe4caf1f34aa763f2bf6d5f43178f2d335d10">AUDIO_SAMPLE_RATE_MASK_12000</a> = 0x2u, <a href="audio.md#gga7053fcaa56d1dc47d2fcd83ee131fe4ca5f13b000ef455b858506fc90d17e2dd7">AUDIO_SAMPLE_RATE_MASK_11025</a> = 0x4u, <a href="audio.md#gga7053fcaa56d1dc47d2fcd83ee131fe4ca3102248493467e00d16c2cf1971635a7">AUDIO_SAMPLE_RATE_MASK_16000</a> = 0x8u,   <a href="audio.md#gga7053fcaa56d1dc47d2fcd83ee131fe4cae7cfb2244a15cd133373cfa5e96ec82e">AUDIO_SAMPLE_RATE_MASK_22050</a> = 0x10u, <a href="audio.md#gga7053fcaa56d1dc47d2fcd83ee131fe4cacce4defc0cf23abfe52d399b4aa68fdf">AUDIO_SAMPLE_RATE_MASK_24000</a> = 0x20u, <a href="audio.md#gga7053fcaa56d1dc47d2fcd83ee131fe4ca5594285d8ef3897e9f29a15e0795b814">AUDIO_SAMPLE_RATE_MASK_32000</a> = 0x40u, <a href="audio.md#gga7053fcaa56d1dc47d2fcd83ee131fe4ca52345265822f55a62b2e038438daf37e">AUDIO_SAMPLE_RATE_MASK_44100</a> = 0x80u,   <a href="audio.md#gga7053fcaa56d1dc47d2fcd83ee131fe4caa52c49624fecf6d9f1d075d0d3ad0bbf">AUDIO_SAMPLE_RATE_MASK_48000</a> = 0x100u, <a href="audio.md#gga7053fcaa56d1dc47d2fcd83ee131fe4caf111a8b9762ec169361a106ba7efdb0f">AUDIO_SAMPLE_RATE_MASK_64000</a> = 0x200u, <a href="audio.md#gga7053fcaa56d1dc47d2fcd83ee131fe4caa9e4deb07b2a7c32e5a19b8c81d9fd0d">AUDIO_SAMPLE_RATE_MASK_96000</a> = 0x400u, <a href="audio.md#gga7053fcaa56d1dc47d2fcd83ee131fe4ca41f8d22ab95c84d0acb3d0c78679274c">AUDIO_SAMPLE_RATE_MASK_INVALID</a> = 0xFFFFFFFFu }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p770849685165623"><a name="p770849685165623"></a><a name="p770849685165623"></a>Enumerates masks of audio sampling rates. </p>
</td>
</tr>
<tr id="row1448943871165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p333001123165623"><a name="p333001123165623"></a><a name="p333001123165623"></a><a href="audio.md#ga186d2d4f9a2ecacb80cd2cce2bd26f0e">AudioPortPassthroughMode</a> { <a href="audio.md#gga186d2d4f9a2ecacb80cd2cce2bd26f0ea48da60ec7958d35e8884e67cc32cb465">PORT_PASSTHROUGH_LPCM</a> = 0x1, <a href="audio.md#gga186d2d4f9a2ecacb80cd2cce2bd26f0eaf44936c424fbadafda9e1a12829b291f">PORT_PASSTHROUGH_RAW</a> = 0x2, <a href="audio.md#gga186d2d4f9a2ecacb80cd2cce2bd26f0eada09d902428d269446b94c2b7e9eb95e">PORT_PASSTHROUGH_HBR2LBR</a> = 0x4, <a href="audio.md#gga186d2d4f9a2ecacb80cd2cce2bd26f0ea6fd7a77031d807247e159c3deec07e11">PORT_PASSTHROUGH_AUTO</a> = 0x8 }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1046700066165623"><a name="p1046700066165623"></a><a name="p1046700066165623"></a>Enumerates the passthrough data transmission mode of an audio port. </p>
</td>
</tr>
<tr id="row322247925165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p56029472165623"><a name="p56029472165623"></a><a name="p56029472165623"></a><a href="audio.md#ga78aab1fafb9657451804e42b42897123">AudioChannelMode</a> {   <a href="audio.md#gga78aab1fafb9657451804e42b42897123aa97ec21f6627e1dfd4854b5b470cdfba">AUDIO_CHANNEL_NORMAL</a> = 0, <a href="audio.md#gga78aab1fafb9657451804e42b42897123a47fd61e4531acb6b5cc058ac26af5d51">AUDIO_CHANNEL_BOTH_LEFT</a>, <a href="audio.md#gga78aab1fafb9657451804e42b42897123a3341b11cad1d47bda2b4a2be60dda023">AUDIO_CHANNEL_BOTH_RIGHT</a>, <a href="audio.md#gga78aab1fafb9657451804e42b42897123a3f2e41939cc24c51213d8730c32e74e9">AUDIO_CHANNEL_EXCHANGE</a>,   <a href="audio.md#gga78aab1fafb9657451804e42b42897123a2c1537bccd5c2a05d1c515e58ec4481e">AUDIO_CHANNEL_MIX</a>, <a href="audio.md#gga78aab1fafb9657451804e42b42897123a485c0423ce07fbb7f844a387ed9bb546">AUDIO_CHANNEL_LEFT_MUTE</a>, <a href="audio.md#gga78aab1fafb9657451804e42b42897123a0878cdf6f3e0d9ae9ae1f61b7f74257e">AUDIO_CHANNEL_RIGHT_MUTE</a>, <a href="audio.md#gga78aab1fafb9657451804e42b42897123a22540143eb96abf8176e73c19fc0d8e5">AUDIO_CHANNEL_BOTH_MUTE</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1283019996165623"><a name="p1283019996165623"></a><a name="p1283019996165623"></a>Enumerates channel modes for audio rendering. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table1821680575165623"></a>
<table><thead align="left"><tr id="row836243178165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p54328664165623"><a name="p54328664165623"></a><a name="p54328664165623"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2112739999165623"><a name="p2112739999165623"></a><a name="p2112739999165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row522335786165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1816462515165623"><a name="p1816462515165623"></a><a name="p1816462515165623"></a><a href="audio.md#ga0c7824f4fe89625d3c9b1d0534ad0151">GetAudioManagerFuncs</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p541486673165623"><a name="p541486673165623"></a><a name="p541486673165623"></a>struct <a href="audiomanager.md">AudioManager</a> * </p>
<p id="p1358470193165623"><a name="p1358470193165623"></a><a name="p1358470193165623"></a>Obtains the operation function list of the <a href="audiomanager.md">AudioManager</a> class. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1693660607165623"></a>

## **Enumeration Type **<a name="section1289870715165623"></a>

## AudioCategory<a name="gaf210d41d152890f3aaf2aaac99bd28d5"></a>

```
enum [AudioCategory](audio.md#gaf210d41d152890f3aaf2aaac99bd28d5)
```

 **Description:**

Enumerates the audio category. 

<a name="table1100263685165623"></a>
<table><thead align="left"><tr id="row359230879165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p129230481165623"><a name="p129230481165623"></a><a name="p129230481165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1909440033165623"><a name="p1909440033165623"></a><a name="p1909440033165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1806685012165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaf210d41d152890f3aaf2aaac99bd28d5a6ac6cfd90dcc34de100c1cecb3df44c3"><a name="ggaf210d41d152890f3aaf2aaac99bd28d5a6ac6cfd90dcc34de100c1cecb3df44c3"></a><a name="ggaf210d41d152890f3aaf2aaac99bd28d5a6ac6cfd90dcc34de100c1cecb3df44c3"></a></strong>AUDIO_IN_MEDIA </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p706779711165623"><a name="p706779711165623"></a><a name="p706779711165623"></a>Media </p>
 </td>
</tr>
<tr id="row2023625960165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaf210d41d152890f3aaf2aaac99bd28d5a474576c773934a0df994bad4cf781b41"><a name="ggaf210d41d152890f3aaf2aaac99bd28d5a474576c773934a0df994bad4cf781b41"></a><a name="ggaf210d41d152890f3aaf2aaac99bd28d5a474576c773934a0df994bad4cf781b41"></a></strong>AUDIO_IN_COMMUNICATION </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2090142578165623"><a name="p2090142578165623"></a><a name="p2090142578165623"></a>Communications </p>
 </td>
</tr>
</tbody>
</table>

## AudioChannelMask<a name="ga137eb03027d5947ea294b32f5095b83c"></a>

```
enum [AudioChannelMask](audio.md#ga137eb03027d5947ea294b32f5095b83c)
```

 **Description:**

Enumerates the audio channel mask. 

A mask describes an audio channel position. 

<a name="table1483038998165623"></a>
<table><thead align="left"><tr id="row1879613250165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1586235295165623"><a name="p1586235295165623"></a><a name="p1586235295165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p474415914165623"><a name="p474415914165623"></a><a name="p474415914165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row620872028165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga137eb03027d5947ea294b32f5095b83ca0419483310bfc5abe46a0c586070ed18"><a name="gga137eb03027d5947ea294b32f5095b83ca0419483310bfc5abe46a0c586070ed18"></a><a name="gga137eb03027d5947ea294b32f5095b83ca0419483310bfc5abe46a0c586070ed18"></a></strong>AUDIO_CHANNEL_FRONT_LEFT </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p338662663165623"><a name="p338662663165623"></a><a name="p338662663165623"></a>Front left channel </p>
 </td>
</tr>
<tr id="row1996197008165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga137eb03027d5947ea294b32f5095b83ca05525a25c5912eda05e9a8786a743a75"><a name="gga137eb03027d5947ea294b32f5095b83ca05525a25c5912eda05e9a8786a743a75"></a><a name="gga137eb03027d5947ea294b32f5095b83ca05525a25c5912eda05e9a8786a743a75"></a></strong>AUDIO_CHANNEL_FRONT_RIGHT </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1809857325165623"><a name="p1809857325165623"></a><a name="p1809857325165623"></a>Front right channel </p>
 </td>
</tr>
<tr id="row1840058631165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga137eb03027d5947ea294b32f5095b83ca0479e1cd2137cbbad68efae1d2b2c9a9"><a name="gga137eb03027d5947ea294b32f5095b83ca0479e1cd2137cbbad68efae1d2b2c9a9"></a><a name="gga137eb03027d5947ea294b32f5095b83ca0479e1cd2137cbbad68efae1d2b2c9a9"></a></strong>AUDIO_CHANNEL_MONO </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p35527635165623"><a name="p35527635165623"></a><a name="p35527635165623"></a>Mono channel </p>
 </td>
</tr>
<tr id="row1248886998165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga137eb03027d5947ea294b32f5095b83ca70f2212ea5439c13f7fcba3e30b15c1a"><a name="gga137eb03027d5947ea294b32f5095b83ca70f2212ea5439c13f7fcba3e30b15c1a"></a><a name="gga137eb03027d5947ea294b32f5095b83ca70f2212ea5439c13f7fcba3e30b15c1a"></a></strong>AUDIO_CHANNEL_STEREO </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1162038637165623"><a name="p1162038637165623"></a><a name="p1162038637165623"></a>Stereo channel, consisting of front left and front right channels </p>
 </td>
</tr>
</tbody>
</table>

## AudioChannelMode<a name="ga78aab1fafb9657451804e42b42897123"></a>

```
enum [AudioChannelMode](audio.md#ga78aab1fafb9657451804e42b42897123)
```

 **Description:**

Enumerates channel modes for audio rendering. 

**Attention:**

The following modes are set for rendering dual-channel audios. Others are not supported. 

<a name="table2073526126165623"></a>
<table><thead align="left"><tr id="row552527430165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p126815385165623"><a name="p126815385165623"></a><a name="p126815385165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1022233172165623"><a name="p1022233172165623"></a><a name="p1022233172165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1277859384165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga78aab1fafb9657451804e42b42897123aa97ec21f6627e1dfd4854b5b470cdfba"><a name="gga78aab1fafb9657451804e42b42897123aa97ec21f6627e1dfd4854b5b470cdfba"></a><a name="gga78aab1fafb9657451804e42b42897123aa97ec21f6627e1dfd4854b5b470cdfba"></a></strong>AUDIO_CHANNEL_NORMAL </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1318699603165623"><a name="p1318699603165623"></a><a name="p1318699603165623"></a>Normal mode. No processing is required. </p>
 </td>
</tr>
<tr id="row1775817539165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga78aab1fafb9657451804e42b42897123a47fd61e4531acb6b5cc058ac26af5d51"><a name="gga78aab1fafb9657451804e42b42897123a47fd61e4531acb6b5cc058ac26af5d51"></a><a name="gga78aab1fafb9657451804e42b42897123a47fd61e4531acb6b5cc058ac26af5d51"></a></strong>AUDIO_CHANNEL_BOTH_LEFT </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1527185546165623"><a name="p1527185546165623"></a><a name="p1527185546165623"></a>Two left channels </p>
 </td>
</tr>
<tr id="row2045596619165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga78aab1fafb9657451804e42b42897123a3341b11cad1d47bda2b4a2be60dda023"><a name="gga78aab1fafb9657451804e42b42897123a3341b11cad1d47bda2b4a2be60dda023"></a><a name="gga78aab1fafb9657451804e42b42897123a3341b11cad1d47bda2b4a2be60dda023"></a></strong>AUDIO_CHANNEL_BOTH_RIGHT </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1506255470165623"><a name="p1506255470165623"></a><a name="p1506255470165623"></a>Two right channels </p>
 </td>
</tr>
<tr id="row279486929165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga78aab1fafb9657451804e42b42897123a3f2e41939cc24c51213d8730c32e74e9"><a name="gga78aab1fafb9657451804e42b42897123a3f2e41939cc24c51213d8730c32e74e9"></a><a name="gga78aab1fafb9657451804e42b42897123a3f2e41939cc24c51213d8730c32e74e9"></a></strong>AUDIO_CHANNEL_EXCHANGE </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2033835919165623"><a name="p2033835919165623"></a><a name="p2033835919165623"></a>Data exchange between the left and right channels. The left channel takes the audio stream of the right channel, and the right channel takes that of the left channel. </p>
 </td>
</tr>
<tr id="row1005169386165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga78aab1fafb9657451804e42b42897123a2c1537bccd5c2a05d1c515e58ec4481e"><a name="gga78aab1fafb9657451804e42b42897123a2c1537bccd5c2a05d1c515e58ec4481e"></a><a name="gga78aab1fafb9657451804e42b42897123a2c1537bccd5c2a05d1c515e58ec4481e"></a></strong>AUDIO_CHANNEL_MIX </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1840293329165623"><a name="p1840293329165623"></a><a name="p1840293329165623"></a>Mix of streams of the left and right channels </p>
 </td>
</tr>
<tr id="row87341879165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga78aab1fafb9657451804e42b42897123a485c0423ce07fbb7f844a387ed9bb546"><a name="gga78aab1fafb9657451804e42b42897123a485c0423ce07fbb7f844a387ed9bb546"></a><a name="gga78aab1fafb9657451804e42b42897123a485c0423ce07fbb7f844a387ed9bb546"></a></strong>AUDIO_CHANNEL_LEFT_MUTE </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p474989630165623"><a name="p474989630165623"></a><a name="p474989630165623"></a>Left channel muted. The stream of the right channel is output. </p>
 </td>
</tr>
<tr id="row1388740284165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga78aab1fafb9657451804e42b42897123a0878cdf6f3e0d9ae9ae1f61b7f74257e"><a name="gga78aab1fafb9657451804e42b42897123a0878cdf6f3e0d9ae9ae1f61b7f74257e"></a><a name="gga78aab1fafb9657451804e42b42897123a0878cdf6f3e0d9ae9ae1f61b7f74257e"></a></strong>AUDIO_CHANNEL_RIGHT_MUTE </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p245090329165623"><a name="p245090329165623"></a><a name="p245090329165623"></a>Right channel muted. The stream of the left channel is output. </p>
 </td>
</tr>
<tr id="row1021784845165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga78aab1fafb9657451804e42b42897123a22540143eb96abf8176e73c19fc0d8e5"><a name="gga78aab1fafb9657451804e42b42897123a22540143eb96abf8176e73c19fc0d8e5"></a><a name="gga78aab1fafb9657451804e42b42897123a22540143eb96abf8176e73c19fc0d8e5"></a></strong>AUDIO_CHANNEL_BOTH_MUTE </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1990337335165623"><a name="p1990337335165623"></a><a name="p1990337335165623"></a>Both left and right channels muted </p>
 </td>
</tr>
</tbody>
</table>

## AudioFormat<a name="ga98d5d077cca088ddf77314871474fe59"></a>

```
enum [AudioFormat](audio.md#ga98d5d077cca088ddf77314871474fe59)
```

 **Description:**

Enumerates the audio format. 

<a name="table48060774165623"></a>
<table><thead align="left"><tr id="row1880772607165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p108253596165623"><a name="p108253596165623"></a><a name="p108253596165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1418701991165623"><a name="p1418701991165623"></a><a name="p1418701991165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1358481039165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga98d5d077cca088ddf77314871474fe59a321cc2160af35aa86b8ee55f231ef1e6"><a name="gga98d5d077cca088ddf77314871474fe59a321cc2160af35aa86b8ee55f231ef1e6"></a><a name="gga98d5d077cca088ddf77314871474fe59a321cc2160af35aa86b8ee55f231ef1e6"></a></strong>AUDIO_FORMAT_PCM_8_BIT </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1857405656165623"><a name="p1857405656165623"></a><a name="p1857405656165623"></a>8-bit PCM </p>
 </td>
</tr>
<tr id="row415337328165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga98d5d077cca088ddf77314871474fe59ae188cf87c8f2e6218c74b3b2385068e6"><a name="gga98d5d077cca088ddf77314871474fe59ae188cf87c8f2e6218c74b3b2385068e6"></a><a name="gga98d5d077cca088ddf77314871474fe59ae188cf87c8f2e6218c74b3b2385068e6"></a></strong>AUDIO_FORMAT_PCM_16_BIT </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2111591172165623"><a name="p2111591172165623"></a><a name="p2111591172165623"></a>16-bit PCM </p>
 </td>
</tr>
<tr id="row1543004915165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga98d5d077cca088ddf77314871474fe59a21eb864e2117df577dcd90ad81da3b14"><a name="gga98d5d077cca088ddf77314871474fe59a21eb864e2117df577dcd90ad81da3b14"></a><a name="gga98d5d077cca088ddf77314871474fe59a21eb864e2117df577dcd90ad81da3b14"></a></strong>AUDIO_FORMAT_PCM_24_BIT </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p424905776165623"><a name="p424905776165623"></a><a name="p424905776165623"></a>24-bit PCM </p>
 </td>
</tr>
<tr id="row1944290854165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga98d5d077cca088ddf77314871474fe59adf7a0bf1f3dd15c9c43fac07c0c6ea26"><a name="gga98d5d077cca088ddf77314871474fe59adf7a0bf1f3dd15c9c43fac07c0c6ea26"></a><a name="gga98d5d077cca088ddf77314871474fe59adf7a0bf1f3dd15c9c43fac07c0c6ea26"></a></strong>AUDIO_FORMAT_PCM_32_BIT </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1825253865165623"><a name="p1825253865165623"></a><a name="p1825253865165623"></a>32-bit PCM </p>
 </td>
</tr>
<tr id="row1312971560165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga98d5d077cca088ddf77314871474fe59a5a781e6f8b145066ae7fb2c310804bab"><a name="gga98d5d077cca088ddf77314871474fe59a5a781e6f8b145066ae7fb2c310804bab"></a><a name="gga98d5d077cca088ddf77314871474fe59a5a781e6f8b145066ae7fb2c310804bab"></a></strong>AUDIO_FORMAT_AAC_MAIN </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1614313264165623"><a name="p1614313264165623"></a><a name="p1614313264165623"></a>AAC main </p>
 </td>
</tr>
<tr id="row1046696333165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga98d5d077cca088ddf77314871474fe59a3d4bc5d534d0452635455ed8d2cade57"><a name="gga98d5d077cca088ddf77314871474fe59a3d4bc5d534d0452635455ed8d2cade57"></a><a name="gga98d5d077cca088ddf77314871474fe59a3d4bc5d534d0452635455ed8d2cade57"></a></strong>AUDIO_FORMAT_AAC_LC </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p284341979165623"><a name="p284341979165623"></a><a name="p284341979165623"></a>AAC LC </p>
 </td>
</tr>
<tr id="row1018167589165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga98d5d077cca088ddf77314871474fe59ad4baf87ff9f4684c03483c572052b700"><a name="gga98d5d077cca088ddf77314871474fe59ad4baf87ff9f4684c03483c572052b700"></a><a name="gga98d5d077cca088ddf77314871474fe59ad4baf87ff9f4684c03483c572052b700"></a></strong>AUDIO_FORMAT_AAC_LD </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1658076886165623"><a name="p1658076886165623"></a><a name="p1658076886165623"></a>AAC LD </p>
 </td>
</tr>
<tr id="row1803671908165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga98d5d077cca088ddf77314871474fe59a4b8d42988fecf03e2bf73c4395501852"><a name="gga98d5d077cca088ddf77314871474fe59a4b8d42988fecf03e2bf73c4395501852"></a><a name="gga98d5d077cca088ddf77314871474fe59a4b8d42988fecf03e2bf73c4395501852"></a></strong>AUDIO_FORMAT_AAC_ELD </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1714666706165623"><a name="p1714666706165623"></a><a name="p1714666706165623"></a>AAC ELD </p>
 </td>
</tr>
<tr id="row1847099027165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga98d5d077cca088ddf77314871474fe59abaddb86f122d3185de9407dbc673bf0e"><a name="gga98d5d077cca088ddf77314871474fe59abaddb86f122d3185de9407dbc673bf0e"></a><a name="gga98d5d077cca088ddf77314871474fe59abaddb86f122d3185de9407dbc673bf0e"></a></strong>AUDIO_FORMAT_AAC_HE_V1 </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1423708737165623"><a name="p1423708737165623"></a><a name="p1423708737165623"></a>AAC HE_V1 </p>
 </td>
</tr>
<tr id="row583084403165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga98d5d077cca088ddf77314871474fe59ab610e0121e0b5076b3f78831e3c237fd"><a name="gga98d5d077cca088ddf77314871474fe59ab610e0121e0b5076b3f78831e3c237fd"></a><a name="gga98d5d077cca088ddf77314871474fe59ab610e0121e0b5076b3f78831e3c237fd"></a></strong>AUDIO_FORMAT_AAC_HE_V2 </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p494409662165623"><a name="p494409662165623"></a><a name="p494409662165623"></a>AAC HE_V2 </p>
 </td>
</tr>
</tbody>
</table>

## AudioPortDirection<a name="ga68ff7140b15790debbac4bbc62f8e9f8"></a>

```
enum [AudioPortDirection](audio.md#ga68ff7140b15790debbac4bbc62f8e9f8)
```

 **Description:**

Enumerates the audio port type. 

<a name="table1284052923165623"></a>
<table><thead align="left"><tr id="row1175634133165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1497299572165623"><a name="p1497299572165623"></a><a name="p1497299572165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p84909788165623"><a name="p84909788165623"></a><a name="p84909788165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1487644733165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga68ff7140b15790debbac4bbc62f8e9f8af54f110a0f64337d474989fbac06bc22"><a name="gga68ff7140b15790debbac4bbc62f8e9f8af54f110a0f64337d474989fbac06bc22"></a><a name="gga68ff7140b15790debbac4bbc62f8e9f8af54f110a0f64337d474989fbac06bc22"></a></strong>PORT_OUT </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p758174528165623"><a name="p758174528165623"></a><a name="p758174528165623"></a>Output port </p>
 </td>
</tr>
<tr id="row36600521165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga68ff7140b15790debbac4bbc62f8e9f8a154a6db110515b7afde52d3a36d57846"><a name="gga68ff7140b15790debbac4bbc62f8e9f8a154a6db110515b7afde52d3a36d57846"></a><a name="gga68ff7140b15790debbac4bbc62f8e9f8a154a6db110515b7afde52d3a36d57846"></a></strong>PORT_IN </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1133972802165623"><a name="p1133972802165623"></a><a name="p1133972802165623"></a>Input port </p>
 </td>
</tr>
<tr id="row170433420165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga68ff7140b15790debbac4bbc62f8e9f8a87e14fe9da9c332ba29185b9213d7bbf"><a name="gga68ff7140b15790debbac4bbc62f8e9f8a87e14fe9da9c332ba29185b9213d7bbf"></a><a name="gga68ff7140b15790debbac4bbc62f8e9f8a87e14fe9da9c332ba29185b9213d7bbf"></a></strong>PORT_OUT_IN </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1067152747165623"><a name="p1067152747165623"></a><a name="p1067152747165623"></a>Input/output port, supporting both audio input and output </p>
 </td>
</tr>
</tbody>
</table>

## AudioPortPassthroughMode<a name="ga186d2d4f9a2ecacb80cd2cce2bd26f0e"></a>

```
enum [AudioPortPassthroughMode](audio.md#ga186d2d4f9a2ecacb80cd2cce2bd26f0e)
```

 **Description:**

Enumerates the passthrough data transmission mode of an audio port. 

<a name="table1634440247165623"></a>
<table><thead align="left"><tr id="row1295204962165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1733816403165623"><a name="p1733816403165623"></a><a name="p1733816403165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p459059605165623"><a name="p459059605165623"></a><a name="p459059605165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row804097234165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga186d2d4f9a2ecacb80cd2cce2bd26f0ea48da60ec7958d35e8884e67cc32cb465"><a name="gga186d2d4f9a2ecacb80cd2cce2bd26f0ea48da60ec7958d35e8884e67cc32cb465"></a><a name="gga186d2d4f9a2ecacb80cd2cce2bd26f0ea48da60ec7958d35e8884e67cc32cb465"></a></strong>PORT_PASSTHROUGH_LPCM </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p251177306165623"><a name="p251177306165623"></a><a name="p251177306165623"></a>Stereo PCM </p>
 </td>
</tr>
<tr id="row698037442165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga186d2d4f9a2ecacb80cd2cce2bd26f0eaf44936c424fbadafda9e1a12829b291f"><a name="gga186d2d4f9a2ecacb80cd2cce2bd26f0eaf44936c424fbadafda9e1a12829b291f"></a><a name="gga186d2d4f9a2ecacb80cd2cce2bd26f0eaf44936c424fbadafda9e1a12829b291f"></a></strong>PORT_PASSTHROUGH_RAW </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1059508972165623"><a name="p1059508972165623"></a><a name="p1059508972165623"></a>HDMI passthrough </p>
 </td>
</tr>
<tr id="row389743823165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga186d2d4f9a2ecacb80cd2cce2bd26f0eada09d902428d269446b94c2b7e9eb95e"><a name="gga186d2d4f9a2ecacb80cd2cce2bd26f0eada09d902428d269446b94c2b7e9eb95e"></a><a name="gga186d2d4f9a2ecacb80cd2cce2bd26f0eada09d902428d269446b94c2b7e9eb95e"></a></strong>PORT_PASSTHROUGH_HBR2LBR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1347265236165623"><a name="p1347265236165623"></a><a name="p1347265236165623"></a>Blu-ray next-generation audio output with reduced specifications </p>
 </td>
</tr>
<tr id="row2057924958165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga186d2d4f9a2ecacb80cd2cce2bd26f0ea6fd7a77031d807247e159c3deec07e11"><a name="gga186d2d4f9a2ecacb80cd2cce2bd26f0ea6fd7a77031d807247e159c3deec07e11"></a><a name="gga186d2d4f9a2ecacb80cd2cce2bd26f0ea6fd7a77031d807247e159c3deec07e11"></a></strong>PORT_PASSTHROUGH_AUTO </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p976827363165623"><a name="p976827363165623"></a><a name="p976827363165623"></a>Mode automatically matched based on the HDMI EDID </p>
 </td>
</tr>
</tbody>
</table>

## AudioPortPin<a name="gaa7114aeeccf3ac4f5f7e1d880bcfa835"></a>

```
enum [AudioPortPin](audio.md#gaa7114aeeccf3ac4f5f7e1d880bcfa835)
```

 **Description:**

Enumerates the pin of an audio adapter. 

<a name="table542714650165623"></a>
<table><thead align="left"><tr id="row925046358165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p214101487165623"><a name="p214101487165623"></a><a name="p214101487165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1098974466165623"><a name="p1098974466165623"></a><a name="p1098974466165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row71884823165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaa7114aeeccf3ac4f5f7e1d880bcfa835ad2f867652c04c17517db7731af03bf20"><a name="ggaa7114aeeccf3ac4f5f7e1d880bcfa835ad2f867652c04c17517db7731af03bf20"></a><a name="ggaa7114aeeccf3ac4f5f7e1d880bcfa835ad2f867652c04c17517db7731af03bf20"></a></strong>PIN_NONE </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p332515442165623"><a name="p332515442165623"></a><a name="p332515442165623"></a>Invalid pin </p>
 </td>
</tr>
<tr id="row398290450165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaa7114aeeccf3ac4f5f7e1d880bcfa835ab1070439bab93e06446c21157771dd6f"><a name="ggaa7114aeeccf3ac4f5f7e1d880bcfa835ab1070439bab93e06446c21157771dd6f"></a><a name="ggaa7114aeeccf3ac4f5f7e1d880bcfa835ab1070439bab93e06446c21157771dd6f"></a></strong>PIN_OUT_SPEAKER </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1022876947165623"><a name="p1022876947165623"></a><a name="p1022876947165623"></a>Speaker output pin </p>
 </td>
</tr>
<tr id="row1178717975165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaa7114aeeccf3ac4f5f7e1d880bcfa835a271013721c8840cc2700c19b3ff8d0a6"><a name="ggaa7114aeeccf3ac4f5f7e1d880bcfa835a271013721c8840cc2700c19b3ff8d0a6"></a><a name="ggaa7114aeeccf3ac4f5f7e1d880bcfa835a271013721c8840cc2700c19b3ff8d0a6"></a></strong>PIN_OUT_HEADSET </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p425944096165623"><a name="p425944096165623"></a><a name="p425944096165623"></a>Wired headset pin for output </p>
 </td>
</tr>
<tr id="row756483412165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaa7114aeeccf3ac4f5f7e1d880bcfa835a411e9037214c75d22c9080505cf9cae6"><a name="ggaa7114aeeccf3ac4f5f7e1d880bcfa835a411e9037214c75d22c9080505cf9cae6"></a><a name="ggaa7114aeeccf3ac4f5f7e1d880bcfa835a411e9037214c75d22c9080505cf9cae6"></a></strong>PIN_OUT_LINEOUT </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1625264750165623"><a name="p1625264750165623"></a><a name="p1625264750165623"></a>Line-out pin </p>
 </td>
</tr>
<tr id="row816337037165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaa7114aeeccf3ac4f5f7e1d880bcfa835ab4aaa2ec71ec77480f60743cd79340b9"><a name="ggaa7114aeeccf3ac4f5f7e1d880bcfa835ab4aaa2ec71ec77480f60743cd79340b9"></a><a name="ggaa7114aeeccf3ac4f5f7e1d880bcfa835ab4aaa2ec71ec77480f60743cd79340b9"></a></strong>PIN_OUT_HDMI </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p914105296165623"><a name="p914105296165623"></a><a name="p914105296165623"></a>HDMI output pin </p>
 </td>
</tr>
<tr id="row781770379165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaa7114aeeccf3ac4f5f7e1d880bcfa835a336001f5685d9c206b1251714553b485"><a name="ggaa7114aeeccf3ac4f5f7e1d880bcfa835a336001f5685d9c206b1251714553b485"></a><a name="ggaa7114aeeccf3ac4f5f7e1d880bcfa835a336001f5685d9c206b1251714553b485"></a></strong>PIN_IN_MIC </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1580205262165623"><a name="p1580205262165623"></a><a name="p1580205262165623"></a>Microphone input pin </p>
 </td>
</tr>
<tr id="row897674069165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaa7114aeeccf3ac4f5f7e1d880bcfa835aaeca21ac0a7b249905d1cea5b683f574"><a name="ggaa7114aeeccf3ac4f5f7e1d880bcfa835aaeca21ac0a7b249905d1cea5b683f574"></a><a name="ggaa7114aeeccf3ac4f5f7e1d880bcfa835aaeca21ac0a7b249905d1cea5b683f574"></a></strong>PIN_IN_HS_MIC </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1985354357165623"><a name="p1985354357165623"></a><a name="p1985354357165623"></a>Wired headset microphone pin for input </p>
 </td>
</tr>
<tr id="row1800096174165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaa7114aeeccf3ac4f5f7e1d880bcfa835a5146add03ff98f06648567bb0e02a477"><a name="ggaa7114aeeccf3ac4f5f7e1d880bcfa835a5146add03ff98f06648567bb0e02a477"></a><a name="ggaa7114aeeccf3ac4f5f7e1d880bcfa835a5146add03ff98f06648567bb0e02a477"></a></strong>PIN_IN_LINEIN </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1366460421165623"><a name="p1366460421165623"></a><a name="p1366460421165623"></a>Line-in pin </p>
 </td>
</tr>
</tbody>
</table>

## AudioSampleRatesMask<a name="ga7053fcaa56d1dc47d2fcd83ee131fe4c"></a>

```
enum [AudioSampleRatesMask](audio.md#ga7053fcaa56d1dc47d2fcd83ee131fe4c)
```

 **Description:**

Enumerates masks of audio sampling rates. 

<a name="table1979470379165623"></a>
<table><thead align="left"><tr id="row1041458457165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1231916919165623"><a name="p1231916919165623"></a><a name="p1231916919165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p435993173165623"><a name="p435993173165623"></a><a name="p435993173165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1837527590165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga7053fcaa56d1dc47d2fcd83ee131fe4ca046a26906a4df81bfc38c583ba3606e9"><a name="gga7053fcaa56d1dc47d2fcd83ee131fe4ca046a26906a4df81bfc38c583ba3606e9"></a><a name="gga7053fcaa56d1dc47d2fcd83ee131fe4ca046a26906a4df81bfc38c583ba3606e9"></a></strong>AUDIO_SAMPLE_RATE_MASK_8000 </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1372065318165623"><a name="p1372065318165623"></a><a name="p1372065318165623"></a>8 kHz </p>
 </td>
</tr>
<tr id="row1143026425165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga7053fcaa56d1dc47d2fcd83ee131fe4caf1f34aa763f2bf6d5f43178f2d335d10"><a name="gga7053fcaa56d1dc47d2fcd83ee131fe4caf1f34aa763f2bf6d5f43178f2d335d10"></a><a name="gga7053fcaa56d1dc47d2fcd83ee131fe4caf1f34aa763f2bf6d5f43178f2d335d10"></a></strong>AUDIO_SAMPLE_RATE_MASK_12000 </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p187900182165623"><a name="p187900182165623"></a><a name="p187900182165623"></a>12 kHz </p>
 </td>
</tr>
<tr id="row2067589737165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga7053fcaa56d1dc47d2fcd83ee131fe4ca5f13b000ef455b858506fc90d17e2dd7"><a name="gga7053fcaa56d1dc47d2fcd83ee131fe4ca5f13b000ef455b858506fc90d17e2dd7"></a><a name="gga7053fcaa56d1dc47d2fcd83ee131fe4ca5f13b000ef455b858506fc90d17e2dd7"></a></strong>AUDIO_SAMPLE_RATE_MASK_11025 </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1265102039165623"><a name="p1265102039165623"></a><a name="p1265102039165623"></a>11.025 kHz </p>
 </td>
</tr>
<tr id="row1892987895165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga7053fcaa56d1dc47d2fcd83ee131fe4ca3102248493467e00d16c2cf1971635a7"><a name="gga7053fcaa56d1dc47d2fcd83ee131fe4ca3102248493467e00d16c2cf1971635a7"></a><a name="gga7053fcaa56d1dc47d2fcd83ee131fe4ca3102248493467e00d16c2cf1971635a7"></a></strong>AUDIO_SAMPLE_RATE_MASK_16000 </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1527559755165623"><a name="p1527559755165623"></a><a name="p1527559755165623"></a>16 kHz </p>
 </td>
</tr>
<tr id="row565547287165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga7053fcaa56d1dc47d2fcd83ee131fe4cae7cfb2244a15cd133373cfa5e96ec82e"><a name="gga7053fcaa56d1dc47d2fcd83ee131fe4cae7cfb2244a15cd133373cfa5e96ec82e"></a><a name="gga7053fcaa56d1dc47d2fcd83ee131fe4cae7cfb2244a15cd133373cfa5e96ec82e"></a></strong>AUDIO_SAMPLE_RATE_MASK_22050 </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1958614075165623"><a name="p1958614075165623"></a><a name="p1958614075165623"></a>22.050 kHz </p>
 </td>
</tr>
<tr id="row1718916936165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga7053fcaa56d1dc47d2fcd83ee131fe4cacce4defc0cf23abfe52d399b4aa68fdf"><a name="gga7053fcaa56d1dc47d2fcd83ee131fe4cacce4defc0cf23abfe52d399b4aa68fdf"></a><a name="gga7053fcaa56d1dc47d2fcd83ee131fe4cacce4defc0cf23abfe52d399b4aa68fdf"></a></strong>AUDIO_SAMPLE_RATE_MASK_24000 </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1522837968165623"><a name="p1522837968165623"></a><a name="p1522837968165623"></a>24 kHz </p>
 </td>
</tr>
<tr id="row1735061053165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga7053fcaa56d1dc47d2fcd83ee131fe4ca5594285d8ef3897e9f29a15e0795b814"><a name="gga7053fcaa56d1dc47d2fcd83ee131fe4ca5594285d8ef3897e9f29a15e0795b814"></a><a name="gga7053fcaa56d1dc47d2fcd83ee131fe4ca5594285d8ef3897e9f29a15e0795b814"></a></strong>AUDIO_SAMPLE_RATE_MASK_32000 </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1468792546165623"><a name="p1468792546165623"></a><a name="p1468792546165623"></a>32 kHz </p>
 </td>
</tr>
<tr id="row1117958095165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga7053fcaa56d1dc47d2fcd83ee131fe4ca52345265822f55a62b2e038438daf37e"><a name="gga7053fcaa56d1dc47d2fcd83ee131fe4ca52345265822f55a62b2e038438daf37e"></a><a name="gga7053fcaa56d1dc47d2fcd83ee131fe4ca52345265822f55a62b2e038438daf37e"></a></strong>AUDIO_SAMPLE_RATE_MASK_44100 </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1746316103165623"><a name="p1746316103165623"></a><a name="p1746316103165623"></a>44.1 kHz </p>
 </td>
</tr>
<tr id="row2130877164165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga7053fcaa56d1dc47d2fcd83ee131fe4caa52c49624fecf6d9f1d075d0d3ad0bbf"><a name="gga7053fcaa56d1dc47d2fcd83ee131fe4caa52c49624fecf6d9f1d075d0d3ad0bbf"></a><a name="gga7053fcaa56d1dc47d2fcd83ee131fe4caa52c49624fecf6d9f1d075d0d3ad0bbf"></a></strong>AUDIO_SAMPLE_RATE_MASK_48000 </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1871422630165623"><a name="p1871422630165623"></a><a name="p1871422630165623"></a>48 kHz </p>
 </td>
</tr>
<tr id="row876531100165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga7053fcaa56d1dc47d2fcd83ee131fe4caf111a8b9762ec169361a106ba7efdb0f"><a name="gga7053fcaa56d1dc47d2fcd83ee131fe4caf111a8b9762ec169361a106ba7efdb0f"></a><a name="gga7053fcaa56d1dc47d2fcd83ee131fe4caf111a8b9762ec169361a106ba7efdb0f"></a></strong>AUDIO_SAMPLE_RATE_MASK_64000 </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1492809925165623"><a name="p1492809925165623"></a><a name="p1492809925165623"></a>64 kHz </p>
 </td>
</tr>
<tr id="row1238882071165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga7053fcaa56d1dc47d2fcd83ee131fe4caa9e4deb07b2a7c32e5a19b8c81d9fd0d"><a name="gga7053fcaa56d1dc47d2fcd83ee131fe4caa9e4deb07b2a7c32e5a19b8c81d9fd0d"></a><a name="gga7053fcaa56d1dc47d2fcd83ee131fe4caa9e4deb07b2a7c32e5a19b8c81d9fd0d"></a></strong>AUDIO_SAMPLE_RATE_MASK_96000 </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1835740620165623"><a name="p1835740620165623"></a><a name="p1835740620165623"></a>96 kHz </p>
 </td>
</tr>
<tr id="row1350104922165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga7053fcaa56d1dc47d2fcd83ee131fe4ca41f8d22ab95c84d0acb3d0c78679274c"><a name="gga7053fcaa56d1dc47d2fcd83ee131fe4ca41f8d22ab95c84d0acb3d0c78679274c"></a><a name="gga7053fcaa56d1dc47d2fcd83ee131fe4ca41f8d22ab95c84d0acb3d0c78679274c"></a></strong>AUDIO_SAMPLE_RATE_MASK_INVALID </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p666343507165623"><a name="p666343507165623"></a><a name="p666343507165623"></a>Invalid sampling rate </p>
 </td>
</tr>
</tbody>
</table>

## **Function **<a name="section521503694165623"></a>

## GetAudioManagerFuncs\(\)<a name="ga0c7824f4fe89625d3c9b1d0534ad0151"></a>

```
struct [AudioManager](audiomanager.md)* GetAudioManagerFuncs (void )
```

 **Description:**

Obtains the operation function list of the  [AudioManager](audiomanager.md)  class. 

**Returns:**

Returns the pointer to the  **[AudioManager](audiomanager.md)**  object if the list is obtained; returns  **NULL**  otherwise. 

## **Variable **<a name="section1960727737165623"></a>

## adapterName<a name="gadbe46bc7d9b4c20c409e30942ad794cf"></a>

```
const char* AudioAdapterDescriptor::adapterName
```

 **Description:**

Name of the audio adapter 

## channelCount \[1/2\]<a name="ga9c629d8ad8f0119d9b0acae3f2ed9b78"></a>

```
uint32_t AudioSampleAttributes::channelCount
```

 **Description:**

Number of audio channels. For example, for the mono channel, the value is 1, and for the stereo channel, the value is 2. 

## channelCount \[2/2\]<a name="ga48253c4fbc171f241bb0494524891bb1"></a>

```
uint32_t AudioPortCapability::channelCount
```

 **Description:**

Supported maximum number of audio channels 

## channelMasks<a name="ga357e90ee8116e04144f57e6f7d3d9efb"></a>

```
enum [AudioChannelMask](audio.md#ga137eb03027d5947ea294b32f5095b83c) AudioPortCapability::channelMasks
```

 **Description:**

Audio channel layout mask of the device. For details, see  [AudioChannelMask](audio.md#ga137eb03027d5947ea294b32f5095b83c). 

## desc \[1/4\]<a name="ga560700ce0e6f047a617e21b41e0425b9"></a>

```
const char* AudioDeviceDescriptor::desc
```

 **Description:**

Audio device name 

## desc \[2/4\]<a name="gab855beab3a08e8c9a7f814cce53e2001"></a>

```
struct [AudioDeviceDescriptor](audiodevicedescriptor.md) AudioSceneDescriptor::desc
```

 **Description:**

Audio device descriptor 

## desc \[3/4\]<a name="ga81e44604a869f47c88c3f9503b9287e1"></a>

```
const char* AudioSceneDescriptor::SceneDesc::desc
```

 **Description:**

Name of the audio scene 

## desc \[4/4\]<a name="gafe579a4229429c8665d1c3d95fc1f964"></a>

```
const char* AudioSubPortCapability::desc
```

 **Description:**

Sub-port name 

## deviceId<a name="ga0485197a750c63938602b339a3b9c77f"></a>

```
uint32_t AudioPortCapability::deviceId
```

 **Description:**

Device ID used for device binding 

## deviceType<a name="ga00860eb6de81efe5b1654b45617fb902"></a>

```
uint32_t AudioPortCapability::deviceType
```

 **Description:**

Device type \(output or input\) 

## dir<a name="ga144336f0f64927730a184c16d8c27698"></a>

```
enum [AudioPortDirection](audio.md#ga68ff7140b15790debbac4bbc62f8e9f8) AudioPort::dir
```

 **Description:**

Audio port type. For details, see  [AudioPortDirection](audio.md#ga68ff7140b15790debbac4bbc62f8e9f8) 

## format<a name="ga441305acec64ee1ed840c8920e167c9e"></a>

```
enum [AudioFormat](audio.md#ga98d5d077cca088ddf77314871474fe59) AudioSampleAttributes::format
```

 **Description:**

Audio data format. For details, see  [AudioFormat](audio.md#ga98d5d077cca088ddf77314871474fe59). 

## formatNum<a name="gaca895984cf53ddd8769d33c8298b0c6d"></a>

```
uint32_t AudioPortCapability::formatNum
```

 **Description:**

Number of the supported audio formats 

## formats<a name="gad01bfa329a21628287ee21df5000e34d"></a>

```
enum [AudioFormat](audio.md#ga98d5d077cca088ddf77314871474fe59)* AudioPortCapability::formats
```

 **Description:**

Supported audio formats. For details, see  [AudioFormat](audio.md#ga98d5d077cca088ddf77314871474fe59). 

## hardwareMode<a name="ga377ecdaf229087a7d17c220a65a7162f"></a>

```
bool AudioPortCapability::hardwareMode
```

 **Description:**

Whether to support device binding 

## id<a name="ga3e54db28a854f634bd847919e7ae8e32"></a>

```
uint32_t AudioSceneDescriptor::SceneDesc::id
```

 **Description:**

Audio scene ID 

## interleaved<a name="gab00c777b594436a4fae1a4bcdad70c6d"></a>

```
bool AudioSampleAttributes::interleaved
```

 **Description:**

Interleaving flag of audio data 

## mask<a name="ga958a6104e7ab64f75618015bfb097a32"></a>

```
enum [AudioPortPassthroughMode](audio.md#ga186d2d4f9a2ecacb80cd2cce2bd26f0e) AudioSubPortCapability::mask
```

 **Description:**

Passthrough mode of data transmission. For details, see  [AudioPortPassthroughMode](audio.md#ga186d2d4f9a2ecacb80cd2cce2bd26f0e). 

## pins<a name="gab2e66ca83a7ef39211b53d4afe7b7b73"></a>

```
enum [AudioPortPin](audio.md#gaa7114aeeccf3ac4f5f7e1d880bcfa835) AudioDeviceDescriptor::pins
```

 **Description:**

Pins of audio ports \(input and output\). For details, see  [AudioPortPin](audio.md#gaa7114aeeccf3ac4f5f7e1d880bcfa835). 

## portId \[1/3\]<a name="gaa534605f1ef1993f47063c3f7fbccbde"></a>

```
uint32_t AudioPort::portId
```

 **Description:**

Audio port ID 

## portId \[2/3\]<a name="gabc4bdf3c11cada00cfebbd9b1218ab3a"></a>

```
uint32_t AudioDeviceDescriptor::portId
```

 **Description:**

Audio port ID 

## portId \[3/3\]<a name="ga4b35c30d09b716f0bd2c7c22587e3f7a"></a>

```
uint32_t AudioSubPortCapability::portId
```

 **Description:**

Sub-port ID 

## portName<a name="ga6cbf88ceff4bcd03b125d45873e654a1"></a>

```
const char* AudioPort::portName
```

 **Description:**

Audio port name 

## portNum<a name="ga2bef8f9b5ea3c1e30639fcb3ec8dd717"></a>

```
uint32_t AudioAdapterDescriptor::portNum
```

 **Description:**

Number of ports supported by an audio adapter 

## ports<a name="ga64d0c55b881fb0a3bc15b2fecea86f24"></a>

```
struct [AudioPort](audioport.md)* AudioAdapterDescriptor::ports
```

 **Description:**

List of ports supported by an audio adapter 

## sampleRate<a name="gaa322b72a4cdf9007c75814853e7ad4af"></a>

```
uint32_t AudioSampleAttributes::sampleRate
```

 **Description:**

Audio sampling rate 

## sampleRateMasks<a name="ga30c8a08e5d939c0e9844d6d9a165c681"></a>

```
uint32_t AudioPortCapability::sampleRateMasks
```

 **Description:**

Supported audio sampling rates \(8 kHz, 16 kHz, 32 kHz, and 48 kHz\) 

## scene<a name="ga3246105a88851b68c71e16a511ea6b47"></a>

```
union [AudioSceneDescriptor::SceneDesc](audioscenedescriptor-scenedesc.md) AudioSceneDescriptor::scene
```

 **Description:**

The  **scene**  object 

## subPorts<a name="gaccd18b70e7d121169f3df5e53fe055f9"></a>

```
struct [AudioSubPortCapability](audiosubportcapability.md)* AudioPortCapability::subPorts
```

 **Description:**

List of supported sub-ports 

## subPortsNum<a name="gab784694fd6a60a3d5a3ae404cd6fe6fd"></a>

```
uint32_t AudioPortCapability::subPortsNum
```

 **Description:**

Number of supported sub-ports \(for output devices only\) 

## tvNSec<a name="gadae6151a2f7e0432dbaf6e89e743de9c"></a>

```
int64_t AudioTimeStamp::tvNSec
```

 **Description:**

Nanoseconds 

## tvSec<a name="gaa6205cc4d86425bc23f2d860f44644ce"></a>

```
int64_t AudioTimeStamp::tvSec
```

 **Description:**

Seconds 

## type<a name="ga658c38c76290ea6c8b9e0a2ddf7d1db4"></a>

```
enum [AudioCategory](audio.md#gaf210d41d152890f3aaf2aaac99bd28d5) AudioSampleAttributes::type
```

 **Description:**

Audio type. For details, see  [AudioCategory](audio.md#gaf210d41d152890f3aaf2aaac99bd28d5) 

