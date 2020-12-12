# MultiMedia\_MediaCommon<a name="ZH-CN_TOPIC_0000001055678046"></a>

-   [Overview](#section1004268445165625)
-   [Summary](#section131157484165625)
-   [Files](#files)
-   [Data Structures](#nested-classes)
-   [Enumerations](#enum-members)
-   [Functions](#func-members)
-   [Details](#section217873255165625)
-   [Enumeration Type](#section1898325319165625)
-   [AudioBitWidth](#gae3e35ee2a2222a667fdebbc5b793ca7c)
-   [AudioCodecFormat](#gaa4ea6f314644ed287e0704be26c768b7)
-   [AudioSourceType](#gadc3158e093b995ca7b9b6aa32388ccdd)
-   [AudioStreamType](#gae7077e4211e48131ae544adb20fc494a)
-   [BufferFlags](#ga6f4847f443de5cdf3641386011335e21)
-   [FormatDataType](#gaa3bfacc6563d8ec8bc870f4b216b4f46)
-   [SourceType](#ga4052b7b55dfd94f1d07678e79d80b507)
-   [VideoCodecFormat](#ga797e6c5e38e23e730eff5bcc41427d7e)
-   [Function](#section1996891878165625)
-   [CopyFrom\(\)](#ga528134c9f87bf755077b3ef51d64e198)
-   [ErrCodeOffset\(\)](#ga5534cc5ecbcb6eb719f55d8695bbb481)
-   [Format\(\)](#ga42435567c8fd61fd2da4834465aca98e)
-   [GetBuffer\(\)](#ga8f897b8b2d5baf06e15accfeb97892ae)
-   [GetDoubleValue\(\) \[1/2\]](#gafe949ed0c2d9dcb5c5e57c7fde226f3e)
-   [GetDoubleValue\(\) \[2/2\]](#gac1ed56f6d35982f770d083dc16e97dbd)
-   [GetFloatValue\(\) \[1/2\]](#gac4e963a9fe320c0143ed33df5f737cb3)
-   [GetFloatValue\(\) \[2/2\]](#gada31b9cf5daa944104417442a5e459dc)
-   [GetFormatMap\(\)](#ga4adff4846515cef00987a360a4d117af)
-   [GetInt32Value\(\)](#gac116d67e5e80f1f9c1c573ceb24df36a)
-   [GetInt64Value\(\)](#ga1f24cb15577c40f7044f4beb96515cfc)
-   [GetIntValue\(\)](#ga798ef733a253558757f49714090b3969)
-   [GetLongValue\(\)](#ga7f1c503f40b78083cb9b9ae9ce93d3b4)
-   [GetSourceStream\(\)](#ga395325402881ad38ef40c9ebd13f174d)
-   [GetSourceStreamFormat\(\)](#gafbd3c732660124a1dc1d9dd0dfb51393)
-   [GetSourceType\(\)](#ga93a8f8b86a9385436f6bbce10a860770)
-   [GetSourceUri\(\)](#ga69ed2683ce3a632f6b2295fb398e4b7b)
-   [GetStringValue\(\) \[1/2\]](#ga089a3e44e128fb662b72c56b53c7068b)
-   [GetStringValue\(\) \[2/2\]](#ga9687bb5d98a92e7beb53dfe4ac44eec1)
-   [GetType\(\)](#ga178a65e0d58071de84e2dbc09ac93407)
-   [OnBufferAvailable\(\)](#gaaebd4fe9df44b434f410aec32cf23467)
-   [PutDoubleValue\(\)](#ga9a98a92eb4436301853a049b5f3313c6)
-   [PutFloatValue\(\)](#gabec9417120824f5bb9eb676be380016f)
-   [PutIntValue\(\)](#ga66771efe315d001e79a14d316c58718e)
-   [PutLongValue\(\)](#ga5b4477636095d80ec4e65c1be617c61c)
-   [PutStringValue\(\)](#gabdc104597559320256930f420eaab82f)
-   [QueueBuffer\(\)](#gaa62705632557f47f9fd9632157e53a21)
-   [SetParameters\(\)](#ga29f8c86744bda61f84920654c5f40df0)
-   [SetStreamCallback\(\)](#ga078516891396a86226c945e02c79c1f5)
-   [SetValue\(\) \[1/5\]](#gacbbf1dca947de8bce2e1a323a1c2664a)
-   [SetValue\(\) \[2/5\]](#ga5e9360adeb46e7b147757ca22c65c268)
-   [SetValue\(\) \[3/5\]](#gaa5ca8643885118cd0b3668d5497a90da)
-   [SetValue\(\) \[4/5\]](#gaa1a80e9075010faca14c5c71855efe2d)
-   [SetValue\(\) \[5/5\]](#gabb73fee1739b96b402a430f7879b2ca6)
-   [Source\(\) \[1/2\]](#gae3640fec3bb0f33f4076dc30e88dac61)
-   [Source\(\) \[2/2\]](#gab9bfa209ae382e3ba5d5242e8dfe5b20)
-   [Variable](#section357746916165625)
-   [BITRATE\_MODE\_CBR](#gaec6a6f6857ff914973ae8dbd6d24435d)
-   [BITRATE\_MODE\_CQ](#gaa1ea5c3322d75d18fbff0422b758d602)
-   [BITRATE\_MODE\_VBR](#gad5d276721fde992fff0b3302a6d2c1dc)
-   [CODEC\_MIME](#ga1b77959b9e9bb70ec3f3a85ddba29f81)
-   [COLOR\_FORMAT\_ARGB8888\_32BIT](#gaf8f714899f0b11248ea310f8b682ca52)
-   [COLOR\_FORMAT\_YUV420SP](#ga4a599efd2466cfef88ed7c8332341f28)
-   [deviceId](#gae354490defc2b40c8aeb7b98700cbbd0)
-   [deviceName](#gaa24e76abf7ecc4088c6888128109d3e8)
-   [ERR\_EARLY\_PREPARE](#ga780504ecfc7b140c8fcac6000d21d2cc)
-   [ERR\_ILLEGAL\_STATE](#ga7d62e4ebba157bb7891397f67686da20)
-   [ERR\_INVALID\_OPERATION](#gaea6d0afbc7c159296297185d13289c45)
-   [ERR\_INVALID\_PARAM](#gab54ceb09402da2ac1bec5e93a95dd5a2)
-   [ERR\_INVALID\_READ](#gaa3475307553e2de4dd7ef799bdc98c14)
-   [ERR\_NOFREE\_CHANNEL](#ga59c64e4fd1f5890b84e263cb8f1b4a86)
-   [ERR\_NOT\_STARTED](#ga09c48c16cb88d0f8860fb7bded0d1369)
-   [ERR\_READ\_BUFFER](#ga93ac3a083852a72b74871883236586ca)
-   [ERR\_SOURCE\_NOT\_SET](#gafad29c0ac3ef7729944bb907c9abc139)
-   [ERR\_UNKNOWN](#gaac1feac62b2f5501fb7ea1903c9f2cfc)
-   [ERROR](#ga9881ac3b69915a2e0e9c401759f77952)
-   [inputSourceType](#ga8c4f565aa744ec55a784529a843f853e)
-   [KEY\_IS\_SYNC\_FRAME](#gaa0ad827cdc16d18a73f280911c009cf1)
-   [KEY\_TIME\_US](#gadac31555c0ac0612c9f72356f9eb1685)
-   [MIME\_AUDIO\_AAC](#ga9cfdd72ca1bf4a012f2307985a37871f)
-   [MIME\_AUDIO\_RAW](#ga28a526cce33c93a3c3b797ca94fe03e9)
-   [SUCCESS](#gaad1937270d3d6c2012ed0e014bd2dc28)

## **Overview**<a name="section1004268445165625"></a>

**Description:**

Provides data types and media formats required for recording and playing audio and videos. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section131157484165625"></a>

## Files<a name="files"></a>

<a name="table1077952155165625"></a>
<table><thead align="left"><tr id="row1170996476165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p300334194165625"><a name="p300334194165625"></a><a name="p300334194165625"></a>File Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1223753507165625"><a name="p1223753507165625"></a><a name="p1223753507165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1195016009165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1790207441165625"><a name="p1790207441165625"></a><a name="p1790207441165625"></a><a href="format-h.md">format.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1750381368165625"><a name="p1750381368165625"></a><a name="p1750381368165625"></a>Declares the media formats provided in the Format class. </p>
</td>
</tr>
<tr id="row1540457114165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p155769206165625"><a name="p155769206165625"></a><a name="p155769206165625"></a><a href="media_errors-h.md">media_errors.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p14556879165625"><a name="p14556879165625"></a><a name="p14556879165625"></a>Declares the <strong id="b1127143656165625"><a name="b1127143656165625"></a><a name="b1127143656165625"></a>media_errors</strong> class to define errors that may occur during media operations. </p>
</td>
</tr>
<tr id="row1134823952165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p53609679165625"><a name="p53609679165625"></a><a name="p53609679165625"></a><a href="media_info-h.md">media_info.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p28966179165625"><a name="p28966179165625"></a><a name="p28966179165625"></a>Declares the <strong id="b1506185381165625"><a name="b1506185381165625"></a><a name="b1506185381165625"></a>media_info</strong> class and provides various audio, video, and codec types. </p>
</td>
</tr>
<tr id="row1945091066165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p553145899165625"><a name="p553145899165625"></a><a name="p553145899165625"></a><a href="source-h.md">source.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1572984151165625"><a name="p1572984151165625"></a><a name="p1572984151165625"></a>Declares the <strong id="b561685508165625"><a name="b561685508165625"></a><a name="b561685508165625"></a>Source</strong> class, which is used to implement source-related operations. </p>
</td>
</tr>
</tbody>
</table>

## Data Structures<a name="nested-classes"></a>

<a name="table1338344798165625"></a>
<table><thead align="left"><tr id="row1908141264165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p575547261165625"><a name="p575547261165625"></a><a name="p575547261165625"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2101024339165625"><a name="p2101024339165625"></a><a name="p2101024339165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row496267000165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2071783765165625"><a name="p2071783765165625"></a><a name="p2071783765165625"></a><a href="OHOS-Media-FormatData.md">OHOS::Media::FormatData</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1662525901165625"><a name="p1662525901165625"></a><a name="p1662525901165625"></a>Represents the data format. </p>
</td>
</tr>
<tr id="row935440827165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2019797251165625"><a name="p2019797251165625"></a><a name="p2019797251165625"></a><a href="OHOS-Media-Format.md">OHOS::Media::Format</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1595171889165625"><a name="p1595171889165625"></a><a name="p1595171889165625"></a>Saves and sets media metadata, such as the media playback duration. </p>
</td>
</tr>
<tr id="row1419938897165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1158833618165625"><a name="p1158833618165625"></a><a name="p1158833618165625"></a><a href="AudioDeviceDesc.md">AudioDeviceDesc</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1609440289165625"><a name="p1609440289165625"></a><a name="p1609440289165625"></a>Defines the audio Device Descriptor. </p>
</td>
</tr>
<tr id="row430415227165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p420299373165625"><a name="p420299373165625"></a><a name="p420299373165625"></a><a href="OHOS-Media-StreamCallback.md">OHOS::Media::StreamCallback</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p166883090165625"><a name="p166883090165625"></a><a name="p166883090165625"></a>Provides functions to obtain the address of a buffer memory and write the filled buffers into the playback queue. You need to implement the <strong id="b1690097161165625"><a name="b1690097161165625"></a><a name="b1690097161165625"></a><a href="OHOS-Media-StreamCallback.md">StreamCallback</a></strong> functions in a player object. </p>
</td>
</tr>
<tr id="row1592734099165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1194161265165625"><a name="p1194161265165625"></a><a name="p1194161265165625"></a><a href="OHOS-Media-StreamSource.md">OHOS::Media::StreamSource</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1103294091165625"><a name="p1103294091165625"></a><a name="p1103294091165625"></a>Provides functions related to the stream source for upper-layer applications. </p>
</td>
</tr>
<tr id="row1086338651165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2133104429165625"><a name="p2133104429165625"></a><a name="p2133104429165625"></a><a href="OHOS-Media-Source.md">OHOS::Media::Source</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p187672376165625"><a name="p187672376165625"></a><a name="p187672376165625"></a>Provides functions to implement source-related operations. </p>
</td>
</tr>
</tbody>
</table>

## Enumerations<a name="enum-members"></a>

<a name="table2034321478165625"></a>
<table><thead align="left"><tr id="row764950037165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p513883248165625"><a name="p513883248165625"></a><a name="p513883248165625"></a>Enumeration Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1762356344165625"><a name="p1762356344165625"></a><a name="p1762356344165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row927914690165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p263982591165625"><a name="p263982591165625"></a><a name="p263982591165625"></a><a href="MultiMedia_MediaCommon.md#gaa3bfacc6563d8ec8bc870f4b216b4f46">OHOS::Media::FormatDataType</a> : uint32_t {   <a href="MultiMedia_MediaCommon.md#ggaa3bfacc6563d8ec8bc870f4b216b4f46a3a3f84f7e1a28c0f91a12f8a3bcfe8ec">OHOS::Media::FORMAT_TYPE_NONE</a>, <a href="MultiMedia_MediaCommon.md#ggaa3bfacc6563d8ec8bc870f4b216b4f46a48d8e70734d5c29f8766ad12037ca3ae">OHOS::Media::FORMAT_TYPE_INT32</a>, <a href="MultiMedia_MediaCommon.md#ggaa3bfacc6563d8ec8bc870f4b216b4f46a108496713fc9bb4b77a8acf38a1396c9">OHOS::Media::FORMAT_TYPE_INT64</a>, <a href="MultiMedia_MediaCommon.md#ggaa3bfacc6563d8ec8bc870f4b216b4f46a3fd208a39e6c4f22d10882b03a547db1">OHOS::Media::FORMAT_TYPE_FLOAT</a>,   <a href="MultiMedia_MediaCommon.md#ggaa3bfacc6563d8ec8bc870f4b216b4f46abb224970f66920c7a443d19051fdc57f">OHOS::Media::FORMAT_TYPE_DOUBLE</a>, <a href="MultiMedia_MediaCommon.md#ggaa3bfacc6563d8ec8bc870f4b216b4f46a21c29eb61b772af7bead2a77a8c87cf6">OHOS::Media::FORMAT_TYPE_STRING</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p809199970165625"><a name="p809199970165625"></a><a name="p809199970165625"></a>Enumerates formats. </p>
</td>
</tr>
<tr id="row1321709311165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p129226206165625"><a name="p129226206165625"></a><a name="p129226206165625"></a><a href="MultiMedia_MediaCommon.md#gadc3158e093b995ca7b9b6aa32388ccdd">AudioSourceType</a> {   <a href="MultiMedia_MediaCommon.md#ggadc3158e093b995ca7b9b6aa32388ccddad728113cb6300764f0131e28290706c0">AUDIO_SOURCE_INVALID</a> = -1, <a href="MultiMedia_MediaCommon.md#ggadc3158e093b995ca7b9b6aa32388ccdda159b69cc6a9b75d6fed0da3e3db9a62f">AUDIO_SOURCE_DEFAULT</a> = 0, <a href="MultiMedia_MediaCommon.md#ggadc3158e093b995ca7b9b6aa32388ccdda732604b3a24d137429e2b83b31849bce">AUDIO_MIC</a> = 1, <a href="MultiMedia_MediaCommon.md#ggadc3158e093b995ca7b9b6aa32388ccddac94b34dbaa3e19d53b34096fbcd64d8d">AUDIO_VOICE_UPLINK</a> = 2,   <a href="MultiMedia_MediaCommon.md#ggadc3158e093b995ca7b9b6aa32388ccdda076ef2fc169a0b5f640e8433d77d1f45">AUDIO_VOICE_DOWNLINK</a> = 3, <a href="MultiMedia_MediaCommon.md#ggadc3158e093b995ca7b9b6aa32388ccdda3d978f472db3ff575a1b4ab84acbc15c">AUDIO_VOICE_CALL</a> = 4, <a href="MultiMedia_MediaCommon.md#ggadc3158e093b995ca7b9b6aa32388ccdda0d2b7337a260ae5c32abd843f5d52ec8">AUDIO_CAMCORDER</a> = 5, <a href="MultiMedia_MediaCommon.md#ggadc3158e093b995ca7b9b6aa32388ccdda2491fee4b6ca4dce9c05babc3c1168e8">AUDIO_VOICE_RECOGNITION</a> = 6,   <a href="MultiMedia_MediaCommon.md#ggadc3158e093b995ca7b9b6aa32388ccdda09ce48df53dbaea4ef4273614bdc5445">AUDIO_VOICE_COMMUNICATION</a> = 7, <a href="MultiMedia_MediaCommon.md#ggadc3158e093b995ca7b9b6aa32388ccddaef3dbfe38c377d77d0e40a9808012981">AUDIO_REMOTE_SUBMIX</a> = 8, <a href="MultiMedia_MediaCommon.md#ggadc3158e093b995ca7b9b6aa32388ccdda2fd32b7e954f7988ae41b63167948caf">AUDIO_UNPROCESSED</a> = 9, <a href="MultiMedia_MediaCommon.md#ggadc3158e093b995ca7b9b6aa32388ccdda532f7c38a1feb89c8cb3a4e07f0c2cbe">AUDIO_VOICE_PERFORMANCE</a> = 10,   <a href="MultiMedia_MediaCommon.md#ggadc3158e093b995ca7b9b6aa32388ccdda295b4d6de2ba41d7783fddbf1543e830">AUDIO_ECHO_REFERENCE</a> = 1997, <a href="MultiMedia_MediaCommon.md#ggadc3158e093b995ca7b9b6aa32388ccdda5492fbdf785a745195f80020dba4f37e">AUDIO_RADIO_TUNER</a> = 1998, <a href="MultiMedia_MediaCommon.md#ggadc3158e093b995ca7b9b6aa32388ccdda210886d5f821c08c5a36e71363d330f6">AUDIO_HOTWORD</a> = 1999, <a href="MultiMedia_MediaCommon.md#ggadc3158e093b995ca7b9b6aa32388ccddad0b4097d682e6cc4d7d92e5f0612a831">AUDIO_REMOTE_SUBMIX_EXTEND</a> = 10007 }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p652531398165625"><a name="p652531398165625"></a><a name="p652531398165625"></a>Enumerates audio source types. </p>
</td>
</tr>
<tr id="row152115790165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1205570459165625"><a name="p1205570459165625"></a><a name="p1205570459165625"></a><a href="MultiMedia_MediaCommon.md#gae7077e4211e48131ae544adb20fc494a">AudioStreamType</a> {   <a href="MultiMedia_MediaCommon.md#ggae7077e4211e48131ae544adb20fc494aa80d7bb9558588a28f24aec4c019fdbd6">TYPE_DEFAULT</a> = -1, <a href="MultiMedia_MediaCommon.md#ggae7077e4211e48131ae544adb20fc494aa431e273affaa22e18ec5a2a548b70e90">TYPE_MEDIA</a> = 0, <a href="MultiMedia_MediaCommon.md#ggae7077e4211e48131ae544adb20fc494aa5bfd254bb72236e9c463aefeb4343194">TYPE_VOICE_COMMUNICATION</a> = 1, <a href="MultiMedia_MediaCommon.md#ggae7077e4211e48131ae544adb20fc494aa0ae2b45a2675c159915c1e76f2f2c846">TYPE_SYSTEM</a> = 2,   <a href="MultiMedia_MediaCommon.md#ggae7077e4211e48131ae544adb20fc494aafe3e3697e6e9f7880cb90d40e1d4d708">TYPE_RING</a> = 3, <a href="MultiMedia_MediaCommon.md#ggae7077e4211e48131ae544adb20fc494aa801a700d4c9f12285930e9eeace6feb4">TYPE_MUSIC</a> = 4, <a href="MultiMedia_MediaCommon.md#ggae7077e4211e48131ae544adb20fc494aae93097f5314613a0eb5465187102bd5f">TYPE_ALARM</a> = 5, <a href="MultiMedia_MediaCommon.md#ggae7077e4211e48131ae544adb20fc494aa7f3c9297ca35f503b5f7b6cb36610ef6">TYPE_NOTIFICATION</a> = 6,   <a href="MultiMedia_MediaCommon.md#ggae7077e4211e48131ae544adb20fc494aac47f3bf77df994414bd9514f8264e277">TYPE_BLUETOOTH_SCO</a> = 7, <a href="MultiMedia_MediaCommon.md#ggae7077e4211e48131ae544adb20fc494aa00376353eb14c2d326026e6a7cdf6674">TYPE_ENFORCED_AUDIBLE</a> = 8, <a href="MultiMedia_MediaCommon.md#ggae7077e4211e48131ae544adb20fc494aad61d97f9466b24094407016ce4231f7b">TYPE_DTMF</a> = 9, <a href="MultiMedia_MediaCommon.md#ggae7077e4211e48131ae544adb20fc494aa8e6eb63161413e4bbb207dfb29efe95f">TYPE_TTS</a> = 10,   <a href="MultiMedia_MediaCommon.md#ggae7077e4211e48131ae544adb20fc494aa38333aca1beda5f77cc1ce3d0c322262">TYPE_ACCESSIBILITY</a> = 11 }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1911203833165625"><a name="p1911203833165625"></a><a name="p1911203833165625"></a>Enumerates audio stream types. </p>
</td>
</tr>
<tr id="row1501976739165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2130561041165625"><a name="p2130561041165625"></a><a name="p2130561041165625"></a><a href="MultiMedia_MediaCommon.md#ga797e6c5e38e23e730eff5bcc41427d7e">VideoCodecFormat</a> { <a href="MultiMedia_MediaCommon.md#gga797e6c5e38e23e730eff5bcc41427d7ea54ef59464d0b6788c6212bb1b5074503">VIDEO_DEFAULT</a> = 0, <a href="MultiMedia_MediaCommon.md#gga797e6c5e38e23e730eff5bcc41427d7eac3f3371ea9f44c4076fec8f0d8f818cf">H264</a> = 2, <a href="MultiMedia_MediaCommon.md#gga797e6c5e38e23e730eff5bcc41427d7eac2489c86e2690559ce3a00a03b15c324">HEVC</a> = 5 }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p185371252165625"><a name="p185371252165625"></a><a name="p185371252165625"></a>Enumerates video codec formats. </p>
</td>
</tr>
<tr id="row354935328165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1765015328165625"><a name="p1765015328165625"></a><a name="p1765015328165625"></a><a href="MultiMedia_MediaCommon.md#gaa4ea6f314644ed287e0704be26c768b7">AudioCodecFormat</a> {   <a href="MultiMedia_MediaCommon.md#ggaa4ea6f314644ed287e0704be26c768b7a4c4c5829b054bc468274700c56d65546">AUDIO_DEFAULT</a> = 0, <a href="MultiMedia_MediaCommon.md#ggaa4ea6f314644ed287e0704be26c768b7a9f7c5945c7d9d679395a7b06652c51ec">AAC_LC</a> = 1, <a href="MultiMedia_MediaCommon.md#ggaa4ea6f314644ed287e0704be26c768b7ac711be17b9264c9f814b11b7fcc3f1b6">AAC_HE_V1</a> = 2, <a href="MultiMedia_MediaCommon.md#ggaa4ea6f314644ed287e0704be26c768b7abf3ac142be84c7ee471a84570745a136">AAC_HE_V2</a> = 3,   <a href="MultiMedia_MediaCommon.md#ggaa4ea6f314644ed287e0704be26c768b7a1ba0b2e0c3a69a989dec92fc6132d8f2">AAC_LD</a> = 4, <a href="MultiMedia_MediaCommon.md#ggaa4ea6f314644ed287e0704be26c768b7a05b8c66394143a26c66268a39115c48a">AAC_ELD</a> = 5, <a href="MultiMedia_MediaCommon.md#ggaa4ea6f314644ed287e0704be26c768b7a5945910833e0d7ff1a9ff73208d9406a">FORMAT_BUTT</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1480673636165625"><a name="p1480673636165625"></a><a name="p1480673636165625"></a>Enumerates audio codec formats. </p>
</td>
</tr>
<tr id="row1266587444165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1162996090165625"><a name="p1162996090165625"></a><a name="p1162996090165625"></a><a href="MultiMedia_MediaCommon.md#gae3e35ee2a2222a667fdebbc5b793ca7c">AudioBitWidth</a> { <a href="MultiMedia_MediaCommon.md#ggae3e35ee2a2222a667fdebbc5b793ca7cac790b3e4ae89aa667da7dad7e79df6a8">BIT_WIDTH_8</a> = 8, <a href="MultiMedia_MediaCommon.md#ggae3e35ee2a2222a667fdebbc5b793ca7ca036f0b45813f96cb6b0f90de1722a780">BIT_WIDTH_16</a> = 16, <a href="MultiMedia_MediaCommon.md#ggae3e35ee2a2222a667fdebbc5b793ca7ca3d613870d00dad5bc83927eaef3c6ade">BIT_WIDTH_24</a> = 24, <a href="MultiMedia_MediaCommon.md#ggae3e35ee2a2222a667fdebbc5b793ca7cafe508a98e81909dc5985e7edc76104d4">BIT_WIDTH_BUTT</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1619588412165625"><a name="p1619588412165625"></a><a name="p1619588412165625"></a>Enumerates audio bit widths. </p>
</td>
</tr>
<tr id="row1958574742165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1980150371165625"><a name="p1980150371165625"></a><a name="p1980150371165625"></a><a href="MultiMedia_MediaCommon.md#ga4052b7b55dfd94f1d07678e79d80b507">OHOS::Media::SourceType</a> : int32_t { <a href="MultiMedia_MediaCommon.md#gga4052b7b55dfd94f1d07678e79d80b507ae456eda14b2359e13cc36f77af92c11b">OHOS::Media::SourceType::SOURCE_TYPE_URI</a> = 0, <a href="MultiMedia_MediaCommon.md#gga4052b7b55dfd94f1d07678e79d80b507a4134c6ec0b1a7fda26c38b8932e606e5">OHOS::Media::SourceType::SOURCE_TYPE_FD</a>, <a href="MultiMedia_MediaCommon.md#gga4052b7b55dfd94f1d07678e79d80b507a538f01f856d995123459a44642a7dc86">OHOS::Media::SourceType::SOURCE_TYPE_STREAM</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p139063847165625"><a name="p139063847165625"></a><a name="p139063847165625"></a>Enumerates media source types. </p>
</td>
</tr>
<tr id="row1634274796165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p491288483165625"><a name="p491288483165625"></a><a name="p491288483165625"></a><a href="MultiMedia_MediaCommon.md#ga6f4847f443de5cdf3641386011335e21">OHOS::Media::StreamCallback::BufferFlags</a> : uint32_t {   <a href="MultiMedia_MediaCommon.md#gga6f4847f443de5cdf3641386011335e21ac1a3ce4ddd663c55f87a8275ccf285ad">OHOS::Media::StreamCallback::STREAM_FLAG_SYNCFRAME</a> = 1, <a href="MultiMedia_MediaCommon.md#gga6f4847f443de5cdf3641386011335e21afd0d977a6a5d48657d694c9acb8ac2b5">OHOS::Media::StreamCallback::STREAM_FLAG_CODECCONFIG</a> = 2, <a href="MultiMedia_MediaCommon.md#gga6f4847f443de5cdf3641386011335e21aa76ecb4ee6077a1ad3ceac569b875487">OHOS::Media::StreamCallback::STREAM_FLAG_EOS</a> = 4, <a href="MultiMedia_MediaCommon.md#gga6f4847f443de5cdf3641386011335e21a29e735a1e41790c24cc9ac9e7342dd2a">OHOS::Media::StreamCallback::STREAM_FLAG_PARTIAL_FRAME</a> = 8,   <a href="MultiMedia_MediaCommon.md#gga6f4847f443de5cdf3641386011335e21a8b2c1f065ce398ac48bac2b8e62e481b">OHOS::Media::StreamCallback::STREAM_FLAG_ENDOFFRAME</a> = 16, <a href="MultiMedia_MediaCommon.md#gga6f4847f443de5cdf3641386011335e21a9001c389dd39f08025e76ae2872fad02">OHOS::Media::StreamCallback::STREAM_FLAG_MUXER_DATA</a> = 32 }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1819323736165625"><a name="p1819323736165625"></a><a name="p1819323736165625"></a>Enumerates buffer types of stream sources. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table806319461165625"></a>
<table><thead align="left"><tr id="row1680081442165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1776111194165625"><a name="p1776111194165625"></a><a name="p1776111194165625"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p759079834165625"><a name="p759079834165625"></a><a name="p759079834165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1665256013165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p19722781165625"><a name="p19722781165625"></a><a name="p19722781165625"></a><a href="MultiMedia_MediaCommon.md#ga178a65e0d58071de84e2dbc09ac93407">OHOS::Media::FormatData::GetType</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1471100800165625"><a name="p1471100800165625"></a><a name="p1471100800165625"></a><a href="MultiMedia_MediaCommon.md#gaa3bfacc6563d8ec8bc870f4b216b4f46">FormatDataType</a> </p>
<p id="p1194780699165625"><a name="p1194780699165625"></a><a name="p1194780699165625"></a>Obtains the format type. </p>
</td>
</tr>
<tr id="row1355332241165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p402576488165625"><a name="p402576488165625"></a><a name="p402576488165625"></a><a href="MultiMedia_MediaCommon.md#gaa1a80e9075010faca14c5c71855efe2d">OHOS::Media::FormatData::SetValue</a> (int32_t val)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1145842635165625"><a name="p1145842635165625"></a><a name="p1145842635165625"></a>bool </p>
<p id="p276478399165625"><a name="p276478399165625"></a><a name="p276478399165625"></a>Sets a 32-bit integer. </p>
</td>
</tr>
<tr id="row1858900371165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p348588454165625"><a name="p348588454165625"></a><a name="p348588454165625"></a><a href="MultiMedia_MediaCommon.md#gabb73fee1739b96b402a430f7879b2ca6">OHOS::Media::FormatData::SetValue</a> (int64_t val)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1258690248165625"><a name="p1258690248165625"></a><a name="p1258690248165625"></a>bool </p>
<p id="p835305722165625"><a name="p835305722165625"></a><a name="p835305722165625"></a>Sets a 64-bit long integer. </p>
</td>
</tr>
<tr id="row1655488537165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p438973970165625"><a name="p438973970165625"></a><a name="p438973970165625"></a><a href="MultiMedia_MediaCommon.md#gaa5ca8643885118cd0b3668d5497a90da">OHOS::Media::FormatData::SetValue</a> (float val)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1909475367165625"><a name="p1909475367165625"></a><a name="p1909475367165625"></a>bool </p>
<p id="p1399063356165625"><a name="p1399063356165625"></a><a name="p1399063356165625"></a>Sets a single-precision floating-point number. </p>
</td>
</tr>
<tr id="row1062827660165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p148362630165625"><a name="p148362630165625"></a><a name="p148362630165625"></a><a href="MultiMedia_MediaCommon.md#ga5e9360adeb46e7b147757ca22c65c268">OHOS::Media::FormatData::SetValue</a> (double val)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p7317190165625"><a name="p7317190165625"></a><a name="p7317190165625"></a>bool </p>
<p id="p2094398240165625"><a name="p2094398240165625"></a><a name="p2094398240165625"></a>Sets a double-precision floating-point number. </p>
</td>
</tr>
<tr id="row2003313373165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1514599090165625"><a name="p1514599090165625"></a><a name="p1514599090165625"></a><a href="MultiMedia_MediaCommon.md#gacbbf1dca947de8bce2e1a323a1c2664a">OHOS::Media::FormatData::SetValue</a> (const std::string &amp;val)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p14504517165625"><a name="p14504517165625"></a><a name="p14504517165625"></a>bool </p>
<p id="p883826123165625"><a name="p883826123165625"></a><a name="p883826123165625"></a>Sets a string. </p>
</td>
</tr>
<tr id="row230059459165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1093150956165625"><a name="p1093150956165625"></a><a name="p1093150956165625"></a><a href="MultiMedia_MediaCommon.md#gac116d67e5e80f1f9c1c573ceb24df36a">OHOS::Media::FormatData::GetInt32Value</a> (int32_t &amp;val) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1028773414165625"><a name="p1028773414165625"></a><a name="p1028773414165625"></a>bool </p>
<p id="p937099612165625"><a name="p937099612165625"></a><a name="p937099612165625"></a>Obtains a 32-bit integer. </p>
</td>
</tr>
<tr id="row1079452131165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2126819261165625"><a name="p2126819261165625"></a><a name="p2126819261165625"></a><a href="MultiMedia_MediaCommon.md#ga1f24cb15577c40f7044f4beb96515cfc">OHOS::Media::FormatData::GetInt64Value</a> (int64_t &amp;val) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1405354995165625"><a name="p1405354995165625"></a><a name="p1405354995165625"></a>bool </p>
<p id="p1801883438165625"><a name="p1801883438165625"></a><a name="p1801883438165625"></a>Obtains a long integer. </p>
</td>
</tr>
<tr id="row1206139010165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1134964634165625"><a name="p1134964634165625"></a><a name="p1134964634165625"></a><a href="MultiMedia_MediaCommon.md#gada31b9cf5daa944104417442a5e459dc">OHOS::Media::FormatData::GetFloatValue</a> (float &amp;val) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p810826732165625"><a name="p810826732165625"></a><a name="p810826732165625"></a>bool </p>
<p id="p600428644165625"><a name="p600428644165625"></a><a name="p600428644165625"></a>Obtains a single-precision floating-point number. </p>
</td>
</tr>
<tr id="row334836311165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p734932688165625"><a name="p734932688165625"></a><a name="p734932688165625"></a><a href="MultiMedia_MediaCommon.md#gac1ed56f6d35982f770d083dc16e97dbd">OHOS::Media::FormatData::GetDoubleValue</a> (double &amp;val) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p283758486165625"><a name="p283758486165625"></a><a name="p283758486165625"></a>bool </p>
<p id="p1700591798165625"><a name="p1700591798165625"></a><a name="p1700591798165625"></a>Obtains a double-precision floating-point number. </p>
</td>
</tr>
<tr id="row1546177816165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p432469905165625"><a name="p432469905165625"></a><a name="p432469905165625"></a><a href="MultiMedia_MediaCommon.md#ga9687bb5d98a92e7beb53dfe4ac44eec1">OHOS::Media::FormatData::GetStringValue</a> (std::string &amp;val) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p350780886165625"><a name="p350780886165625"></a><a name="p350780886165625"></a>bool </p>
<p id="p159557825165625"><a name="p159557825165625"></a><a name="p159557825165625"></a>Obtains a string. </p>
</td>
</tr>
<tr id="row1108345416165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p838041680165625"><a name="p838041680165625"></a><a name="p838041680165625"></a><a href="MultiMedia_MediaCommon.md#ga42435567c8fd61fd2da4834465aca98e">OHOS::Media::Format::Format</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p755713111165625"><a name="p755713111165625"></a><a name="p755713111165625"></a> </p>
<p id="p1960388516165625"><a name="p1960388516165625"></a><a name="p1960388516165625"></a>Default constructor of the <a href="OHOS-Media-Format.md">Format</a> instance. </p>
</td>
</tr>
<tr id="row253607380165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1216902142165625"><a name="p1216902142165625"></a><a name="p1216902142165625"></a><a href="MultiMedia_MediaCommon.md#ga66771efe315d001e79a14d316c58718e">OHOS::Media::Format::PutIntValue</a> (const std::string &amp;key, int32_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p105798092165625"><a name="p105798092165625"></a><a name="p105798092165625"></a>bool </p>
<p id="p1351059762165625"><a name="p1351059762165625"></a><a name="p1351059762165625"></a>Sets metadata of the integer type. </p>
</td>
</tr>
<tr id="row672149432165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p705126843165625"><a name="p705126843165625"></a><a name="p705126843165625"></a><a href="MultiMedia_MediaCommon.md#ga5b4477636095d80ec4e65c1be617c61c">OHOS::Media::Format::PutLongValue</a> (const std::string &amp;key, int64_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1967590038165625"><a name="p1967590038165625"></a><a name="p1967590038165625"></a>bool </p>
<p id="p18804343165625"><a name="p18804343165625"></a><a name="p18804343165625"></a>Sets metadata of the long integer type. </p>
</td>
</tr>
<tr id="row1045869292165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p253568126165625"><a name="p253568126165625"></a><a name="p253568126165625"></a><a href="MultiMedia_MediaCommon.md#gabec9417120824f5bb9eb676be380016f">OHOS::Media::Format::PutFloatValue</a> (const std::string &amp;key, float value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1458205870165625"><a name="p1458205870165625"></a><a name="p1458205870165625"></a>bool </p>
<p id="p96104731165625"><a name="p96104731165625"></a><a name="p96104731165625"></a>Sets metadata of the single-precision floating-point type. </p>
</td>
</tr>
<tr id="row1327255749165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1628594928165625"><a name="p1628594928165625"></a><a name="p1628594928165625"></a><a href="MultiMedia_MediaCommon.md#ga9a98a92eb4436301853a049b5f3313c6">OHOS::Media::Format::PutDoubleValue</a> (const std::string &amp;key, double value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2071352146165625"><a name="p2071352146165625"></a><a name="p2071352146165625"></a>bool </p>
<p id="p180357739165625"><a name="p180357739165625"></a><a name="p180357739165625"></a>Sets metadata of the double-precision floating-point type. </p>
</td>
</tr>
<tr id="row1764615984165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p608767054165625"><a name="p608767054165625"></a><a name="p608767054165625"></a><a href="MultiMedia_MediaCommon.md#gabdc104597559320256930f420eaab82f">OHOS::Media::Format::PutStringValue</a> (const std::string &amp;key, const std::string &amp;value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p106443234165625"><a name="p106443234165625"></a><a name="p106443234165625"></a>bool </p>
<p id="p517513190165625"><a name="p517513190165625"></a><a name="p517513190165625"></a>Sets metadata of the string type. </p>
</td>
</tr>
<tr id="row268698478165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1345120812165625"><a name="p1345120812165625"></a><a name="p1345120812165625"></a><a href="MultiMedia_MediaCommon.md#ga798ef733a253558757f49714090b3969">OHOS::Media::Format::GetIntValue</a> (const std::string &amp;key, int32_t &amp;value) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p571201930165625"><a name="p571201930165625"></a><a name="p571201930165625"></a>bool </p>
<p id="p40931987165625"><a name="p40931987165625"></a><a name="p40931987165625"></a>Obtains the metadata value of the integer type. </p>
</td>
</tr>
<tr id="row349630444165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1436391372165625"><a name="p1436391372165625"></a><a name="p1436391372165625"></a><a href="MultiMedia_MediaCommon.md#ga7f1c503f40b78083cb9b9ae9ce93d3b4">OHOS::Media::Format::GetLongValue</a> (const std::string &amp;key, int64_t &amp;value) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1328794394165625"><a name="p1328794394165625"></a><a name="p1328794394165625"></a>bool </p>
<p id="p1463321654165625"><a name="p1463321654165625"></a><a name="p1463321654165625"></a>Obtains the metadata value of the long integer type. </p>
</td>
</tr>
<tr id="row973320937165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p943251059165625"><a name="p943251059165625"></a><a name="p943251059165625"></a><a href="MultiMedia_MediaCommon.md#gac4e963a9fe320c0143ed33df5f737cb3">OHOS::Media::Format::GetFloatValue</a> (const std::string &amp;key, float &amp;value) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1685465322165625"><a name="p1685465322165625"></a><a name="p1685465322165625"></a>bool </p>
<p id="p1334980278165625"><a name="p1334980278165625"></a><a name="p1334980278165625"></a>Obtains the metadata value of the single-precision floating-point type. </p>
</td>
</tr>
<tr id="row1579871596165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p803960848165625"><a name="p803960848165625"></a><a name="p803960848165625"></a><a href="MultiMedia_MediaCommon.md#gafe949ed0c2d9dcb5c5e57c7fde226f3e">OHOS::Media::Format::GetDoubleValue</a> (const std::string &amp;key, double &amp;value) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p456174429165625"><a name="p456174429165625"></a><a name="p456174429165625"></a>bool </p>
<p id="p1528025455165625"><a name="p1528025455165625"></a><a name="p1528025455165625"></a>Obtains the metadata value of the double-precision floating-point type. </p>
</td>
</tr>
<tr id="row111609533165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1040692244165625"><a name="p1040692244165625"></a><a name="p1040692244165625"></a><a href="MultiMedia_MediaCommon.md#ga089a3e44e128fb662b72c56b53c7068b">OHOS::Media::Format::GetStringValue</a> (const std::string &amp;key, std::string &amp;value) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p610746244165625"><a name="p610746244165625"></a><a name="p610746244165625"></a>bool </p>
<p id="p927714335165625"><a name="p927714335165625"></a><a name="p927714335165625"></a>Obtains the metadata value of the string type. </p>
</td>
</tr>
<tr id="row2047981555165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1603630652165625"><a name="p1603630652165625"></a><a name="p1603630652165625"></a><a href="MultiMedia_MediaCommon.md#ga4adff4846515cef00987a360a4d117af">OHOS::Media::Format::GetFormatMap</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p157465724165625"><a name="p157465724165625"></a><a name="p157465724165625"></a>const std::map&lt; std::string, <a href="OHOS-Media-FormatData.md">FormatData</a> * &gt; &amp; </p>
<p id="p1765473518165625"><a name="p1765473518165625"></a><a name="p1765473518165625"></a>Obtains the metadata map. </p>
</td>
</tr>
<tr id="row1509454049165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p602760950165625"><a name="p602760950165625"></a><a name="p602760950165625"></a><a href="MultiMedia_MediaCommon.md#ga528134c9f87bf755077b3ef51d64e198">OHOS::Media::Format::CopyFrom</a> (const <a href="OHOS-Media-Format.md">Format</a> &amp;format)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p359835608165625"><a name="p359835608165625"></a><a name="p359835608165625"></a>bool </p>
<p id="p1642023914165625"><a name="p1642023914165625"></a><a name="p1642023914165625"></a>Sets all metadata to a specified format. </p>
</td>
</tr>
<tr id="row584437201165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p968924714165625"><a name="p968924714165625"></a><a name="p968924714165625"></a><a href="MultiMedia_MediaCommon.md#ga5534cc5ecbcb6eb719f55d8695bbb481">OHOS::Media::ErrCodeOffset</a> (unsigned int subsystem, unsigned int module=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1664288245165625"><a name="p1664288245165625"></a><a name="p1664288245165625"></a>constexpr ErrCode </p>
<p id="p1935804631165625"><a name="p1935804631165625"></a><a name="p1935804631165625"></a>Generates a start error code with a unique identifier based on specified subsystem and module bit numbers. </p>
</td>
</tr>
<tr id="row226210772165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2140218458165625"><a name="p2140218458165625"></a><a name="p2140218458165625"></a><a href="MultiMedia_MediaCommon.md#ga8f897b8b2d5baf06e15accfeb97892ae">OHOS::Media::StreamCallback::GetBuffer</a> (size_t <a href="UTILS.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1170891838165625"><a name="p1170891838165625"></a><a name="p1170891838165625"></a>virtual uint8_t * </p>
<p id="p444131900165625"><a name="p444131900165625"></a><a name="p444131900165625"></a>Obtains the virtual address of a buffer memory block based on its index. </p>
</td>
</tr>
<tr id="row745274761165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1042991619165625"><a name="p1042991619165625"></a><a name="p1042991619165625"></a><a href="MultiMedia_MediaCommon.md#gaa62705632557f47f9fd9632157e53a21">OHOS::Media::StreamCallback::QueueBuffer</a> (size_t <a href="UTILS.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>, size_t offset, size_t size, int64_t timestampUs, uint32_t flags)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p283550405165625"><a name="p283550405165625"></a><a name="p283550405165625"></a>virtual void </p>
<p id="p2076612877165625"><a name="p2076612877165625"></a><a name="p2076612877165625"></a>Writes the filled buffer memory block into the player memory. </p>
</td>
</tr>
<tr id="row1548932566165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2083621367165625"><a name="p2083621367165625"></a><a name="p2083621367165625"></a><a href="MultiMedia_MediaCommon.md#ga29f8c86744bda61f84920654c5f40df0">OHOS::Media::StreamCallback::SetParameters</a> (const <a href="OHOS-Media-Format.md">Format</a> &amp;params)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1365204258165625"><a name="p1365204258165625"></a><a name="p1365204258165625"></a>virtual void </p>
<p id="p1759226737165625"><a name="p1759226737165625"></a><a name="p1759226737165625"></a>Sets additional information about a stream. </p>
</td>
</tr>
<tr id="row1563599909165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p401916936165625"><a name="p401916936165625"></a><a name="p401916936165625"></a><a href="MultiMedia_MediaCommon.md#gaaebd4fe9df44b434f410aec32cf23467">OHOS::Media::StreamSource::OnBufferAvailable</a> (size_t <a href="UTILS.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>, size_t offset, size_t size)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1153191196165625"><a name="p1153191196165625"></a><a name="p1153191196165625"></a>virtual void </p>
<p id="p1067098424165625"><a name="p1067098424165625"></a><a name="p1067098424165625"></a>Notifies your application of the information about the buffer memory block that can be filled with data. </p>
</td>
</tr>
<tr id="row326808706165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p471744513165625"><a name="p471744513165625"></a><a name="p471744513165625"></a><a href="MultiMedia_MediaCommon.md#ga078516891396a86226c945e02c79c1f5">OHOS::Media::StreamSource::SetStreamCallback</a> (const std::shared_ptr&lt; <a href="OHOS-Media-StreamCallback.md">StreamCallback</a> &gt; &amp;callback)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p380857130165625"><a name="p380857130165625"></a><a name="p380857130165625"></a>virtual void </p>
<p id="p267718400165625"><a name="p267718400165625"></a><a name="p267718400165625"></a>Sets a callback function for your application. </p>
</td>
</tr>
<tr id="row1577468530165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p886727906165625"><a name="p886727906165625"></a><a name="p886727906165625"></a><a href="MultiMedia_MediaCommon.md#gab9bfa209ae382e3ba5d5242e8dfe5b20">OHOS::Media::Source::Source</a> (const std::string &amp;uri)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1877746237165625"><a name="p1877746237165625"></a><a name="p1877746237165625"></a> </p>
<p id="p1386451386165625"><a name="p1386451386165625"></a><a name="p1386451386165625"></a>A constructor used to create a <a href="OHOS-Media-Source.md">Source</a> instance based on a specified URI. </p>
</td>
</tr>
<tr id="row1328416244165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p846615814165625"><a name="p846615814165625"></a><a name="p846615814165625"></a><a href="MultiMedia_MediaCommon.md#gae3640fec3bb0f33f4076dc30e88dac61">OHOS::Media::Source::Source</a> (const std::shared_ptr&lt; <a href="OHOS-Media-StreamSource.md">StreamSource</a> &gt; &amp;stream, const <a href="OHOS-Media-Format.md">Format</a> &amp;formats)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p102902698165625"><a name="p102902698165625"></a><a name="p102902698165625"></a> </p>
<p id="p183313757165625"><a name="p183313757165625"></a><a name="p183313757165625"></a>A constructor used to create a <a href="OHOS-Media-Source.md">Source</a> instance based on the stream source and format information. </p>
</td>
</tr>
<tr id="row1522172192165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1289995261165625"><a name="p1289995261165625"></a><a name="p1289995261165625"></a><a href="MultiMedia_MediaCommon.md#ga93a8f8b86a9385436f6bbce10a860770">OHOS::Media::Source::GetSourceType</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1308041976165625"><a name="p1308041976165625"></a><a name="p1308041976165625"></a><a href="MultiMedia_MediaCommon.md#ga4052b7b55dfd94f1d07678e79d80b507">SourceType</a> </p>
<p id="p566506553165625"><a name="p566506553165625"></a><a name="p566506553165625"></a>Obtains the source type. </p>
</td>
</tr>
<tr id="row330614161165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1202816677165625"><a name="p1202816677165625"></a><a name="p1202816677165625"></a><a href="MultiMedia_MediaCommon.md#ga69ed2683ce3a632f6b2295fb398e4b7b">OHOS::Media::Source::GetSourceUri</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1832074551165625"><a name="p1832074551165625"></a><a name="p1832074551165625"></a>const std::string &amp; </p>
<p id="p586823552165625"><a name="p586823552165625"></a><a name="p586823552165625"></a>Obtains the media source URI. </p>
</td>
</tr>
<tr id="row104334477165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p12257862165625"><a name="p12257862165625"></a><a name="p12257862165625"></a><a href="MultiMedia_MediaCommon.md#ga395325402881ad38ef40c9ebd13f174d">OHOS::Media::Source::GetSourceStream</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p672920431165625"><a name="p672920431165625"></a><a name="p672920431165625"></a>const std::shared_ptr&lt; <a href="OHOS-Media-StreamSource.md">StreamSource</a> &gt; &amp; </p>
<p id="p589904547165625"><a name="p589904547165625"></a><a name="p589904547165625"></a>Obtains information about the media source stream. </p>
</td>
</tr>
<tr id="row1406528123165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p57516728165625"><a name="p57516728165625"></a><a name="p57516728165625"></a><a href="MultiMedia_MediaCommon.md#gafbd3c732660124a1dc1d9dd0dfb51393">OHOS::Media::Source::GetSourceStreamFormat</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1922529368165625"><a name="p1922529368165625"></a><a name="p1922529368165625"></a>const <a href="OHOS-Media-Format.md">Format</a> &amp; </p>
<p id="p1474538071165625"><a name="p1474538071165625"></a><a name="p1474538071165625"></a>Obtains the media source stream format. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section217873255165625"></a>

## **Enumeration Type **<a name="section1898325319165625"></a>

## AudioBitWidth<a name="gae3e35ee2a2222a667fdebbc5b793ca7c"></a>

```
enum [AudioBitWidth](MultiMedia_MediaCommon.md#gae3e35ee2a2222a667fdebbc5b793ca7c)
```

 **Description:**

Enumerates audio bit widths. 

<a name="table1374143861165625"></a>
<table><thead align="left"><tr id="row1219451458165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1380805419165625"><a name="p1380805419165625"></a><a name="p1380805419165625"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1078403720165625"><a name="p1078403720165625"></a><a name="p1078403720165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row843529756165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggae3e35ee2a2222a667fdebbc5b793ca7cac790b3e4ae89aa667da7dad7e79df6a8"><a name="ggae3e35ee2a2222a667fdebbc5b793ca7cac790b3e4ae89aa667da7dad7e79df6a8"></a><a name="ggae3e35ee2a2222a667fdebbc5b793ca7cac790b3e4ae89aa667da7dad7e79df6a8"></a></strong>BIT_WIDTH_8 </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p398623463165625"><a name="p398623463165625"></a><a name="p398623463165625"></a>8-bit width </p>
 </td>
</tr>
<tr id="row185447567165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggae3e35ee2a2222a667fdebbc5b793ca7ca036f0b45813f96cb6b0f90de1722a780"><a name="ggae3e35ee2a2222a667fdebbc5b793ca7ca036f0b45813f96cb6b0f90de1722a780"></a><a name="ggae3e35ee2a2222a667fdebbc5b793ca7ca036f0b45813f96cb6b0f90de1722a780"></a></strong>BIT_WIDTH_16 </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1367467421165625"><a name="p1367467421165625"></a><a name="p1367467421165625"></a>16-bit width </p>
 </td>
</tr>
<tr id="row559960127165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggae3e35ee2a2222a667fdebbc5b793ca7ca3d613870d00dad5bc83927eaef3c6ade"><a name="ggae3e35ee2a2222a667fdebbc5b793ca7ca3d613870d00dad5bc83927eaef3c6ade"></a><a name="ggae3e35ee2a2222a667fdebbc5b793ca7ca3d613870d00dad5bc83927eaef3c6ade"></a></strong>BIT_WIDTH_24 </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2016683034165625"><a name="p2016683034165625"></a><a name="p2016683034165625"></a>24-bit width </p>
 </td>
</tr>
<tr id="row1277797679165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggae3e35ee2a2222a667fdebbc5b793ca7cafe508a98e81909dc5985e7edc76104d4"><a name="ggae3e35ee2a2222a667fdebbc5b793ca7cafe508a98e81909dc5985e7edc76104d4"></a><a name="ggae3e35ee2a2222a667fdebbc5b793ca7cafe508a98e81909dc5985e7edc76104d4"></a></strong>BIT_WIDTH_BUTT </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p188553268165625"><a name="p188553268165625"></a><a name="p188553268165625"></a>Invalid value </p>
 </td>
</tr>
</tbody>
</table>

## AudioCodecFormat<a name="gaa4ea6f314644ed287e0704be26c768b7"></a>

```
enum [AudioCodecFormat](MultiMedia_MediaCommon.md#gaa4ea6f314644ed287e0704be26c768b7)
```

 **Description:**

Enumerates audio codec formats. 

<a name="table2016221600165625"></a>
<table><thead align="left"><tr id="row507068395165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1858202923165625"><a name="p1858202923165625"></a><a name="p1858202923165625"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p178866214165625"><a name="p178866214165625"></a><a name="p178866214165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row832193825165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaa4ea6f314644ed287e0704be26c768b7a4c4c5829b054bc468274700c56d65546"><a name="ggaa4ea6f314644ed287e0704be26c768b7a4c4c5829b054bc468274700c56d65546"></a><a name="ggaa4ea6f314644ed287e0704be26c768b7a4c4c5829b054bc468274700c56d65546"></a></strong>AUDIO_DEFAULT </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1757521997165625"><a name="p1757521997165625"></a><a name="p1757521997165625"></a>Default format </p>
 </td>
</tr>
<tr id="row1899947381165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaa4ea6f314644ed287e0704be26c768b7a9f7c5945c7d9d679395a7b06652c51ec"><a name="ggaa4ea6f314644ed287e0704be26c768b7a9f7c5945c7d9d679395a7b06652c51ec"></a><a name="ggaa4ea6f314644ed287e0704be26c768b7a9f7c5945c7d9d679395a7b06652c51ec"></a></strong>AAC_LC </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p270367618165625"><a name="p270367618165625"></a><a name="p270367618165625"></a>Advanced Audio Coding Low Complexity (AAC-LC) </p>
 </td>
</tr>
<tr id="row948855506165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaa4ea6f314644ed287e0704be26c768b7ac711be17b9264c9f814b11b7fcc3f1b6"><a name="ggaa4ea6f314644ed287e0704be26c768b7ac711be17b9264c9f814b11b7fcc3f1b6"></a><a name="ggaa4ea6f314644ed287e0704be26c768b7ac711be17b9264c9f814b11b7fcc3f1b6"></a></strong>AAC_HE_V1 </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p906955061165625"><a name="p906955061165625"></a><a name="p906955061165625"></a>High-Efficiency Advanced Audio Coding (AAC-HE), previously known as AAC+ or aacPlus v1 </p>
 </td>
</tr>
<tr id="row2137143602165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaa4ea6f314644ed287e0704be26c768b7abf3ac142be84c7ee471a84570745a136"><a name="ggaa4ea6f314644ed287e0704be26c768b7abf3ac142be84c7ee471a84570745a136"></a><a name="ggaa4ea6f314644ed287e0704be26c768b7abf3ac142be84c7ee471a84570745a136"></a></strong>AAC_HE_V2 </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1597648951165625"><a name="p1597648951165625"></a><a name="p1597648951165625"></a>AAC++ or aacPlus v2 </p>
 </td>
</tr>
<tr id="row1790396046165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaa4ea6f314644ed287e0704be26c768b7a1ba0b2e0c3a69a989dec92fc6132d8f2"><a name="ggaa4ea6f314644ed287e0704be26c768b7a1ba0b2e0c3a69a989dec92fc6132d8f2"></a><a name="ggaa4ea6f314644ed287e0704be26c768b7a1ba0b2e0c3a69a989dec92fc6132d8f2"></a></strong>AAC_LD </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p441695893165625"><a name="p441695893165625"></a><a name="p441695893165625"></a>Advanced Audio Coding Low Delay (AAC-LD) </p>
 </td>
</tr>
<tr id="row165698755165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaa4ea6f314644ed287e0704be26c768b7a05b8c66394143a26c66268a39115c48a"><a name="ggaa4ea6f314644ed287e0704be26c768b7a05b8c66394143a26c66268a39115c48a"></a><a name="ggaa4ea6f314644ed287e0704be26c768b7a05b8c66394143a26c66268a39115c48a"></a></strong>AAC_ELD </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1484525430165625"><a name="p1484525430165625"></a><a name="p1484525430165625"></a>Advanced Audio Coding Enhanced Low Delay (AAC-ELD) </p>
 </td>
</tr>
<tr id="row1789144398165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaa4ea6f314644ed287e0704be26c768b7a5945910833e0d7ff1a9ff73208d9406a"><a name="ggaa4ea6f314644ed287e0704be26c768b7a5945910833e0d7ff1a9ff73208d9406a"></a><a name="ggaa4ea6f314644ed287e0704be26c768b7a5945910833e0d7ff1a9ff73208d9406a"></a></strong>FORMAT_BUTT </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p523703310165625"><a name="p523703310165625"></a><a name="p523703310165625"></a>Invalid value </p>
 </td>
</tr>
</tbody>
</table>

## AudioSourceType<a name="gadc3158e093b995ca7b9b6aa32388ccdd"></a>

```
enum [AudioSourceType](MultiMedia_MediaCommon.md#gadc3158e093b995ca7b9b6aa32388ccdd)
```

 **Description:**

Enumerates audio source types. 

<a name="table683386066165625"></a>
<table><thead align="left"><tr id="row1800747361165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1413233822165625"><a name="p1413233822165625"></a><a name="p1413233822165625"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1960947583165625"><a name="p1960947583165625"></a><a name="p1960947583165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1721074256165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggadc3158e093b995ca7b9b6aa32388ccddad728113cb6300764f0131e28290706c0"><a name="ggadc3158e093b995ca7b9b6aa32388ccddad728113cb6300764f0131e28290706c0"></a><a name="ggadc3158e093b995ca7b9b6aa32388ccddad728113cb6300764f0131e28290706c0"></a></strong>AUDIO_SOURCE_INVALID </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p531480588165625"><a name="p531480588165625"></a><a name="p531480588165625"></a>Invalid audio source </p>
 </td>
</tr>
<tr id="row404780648165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggadc3158e093b995ca7b9b6aa32388ccdda159b69cc6a9b75d6fed0da3e3db9a62f"><a name="ggadc3158e093b995ca7b9b6aa32388ccdda159b69cc6a9b75d6fed0da3e3db9a62f"></a><a name="ggadc3158e093b995ca7b9b6aa32388ccdda159b69cc6a9b75d6fed0da3e3db9a62f"></a></strong>AUDIO_SOURCE_DEFAULT </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1194348913165625"><a name="p1194348913165625"></a><a name="p1194348913165625"></a>Default audio source </p>
 </td>
</tr>
<tr id="row538761286165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggadc3158e093b995ca7b9b6aa32388ccdda732604b3a24d137429e2b83b31849bce"><a name="ggadc3158e093b995ca7b9b6aa32388ccdda732604b3a24d137429e2b83b31849bce"></a><a name="ggadc3158e093b995ca7b9b6aa32388ccdda732604b3a24d137429e2b83b31849bce"></a></strong>AUDIO_MIC </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1096029757165625"><a name="p1096029757165625"></a><a name="p1096029757165625"></a>Microphone </p>
 </td>
</tr>
<tr id="row2111054659165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggadc3158e093b995ca7b9b6aa32388ccddac94b34dbaa3e19d53b34096fbcd64d8d"><a name="ggadc3158e093b995ca7b9b6aa32388ccddac94b34dbaa3e19d53b34096fbcd64d8d"></a><a name="ggadc3158e093b995ca7b9b6aa32388ccddac94b34dbaa3e19d53b34096fbcd64d8d"></a></strong>AUDIO_VOICE_UPLINK </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p398649691165625"><a name="p398649691165625"></a><a name="p398649691165625"></a>Uplink voice </p>
 </td>
</tr>
<tr id="row821070704165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggadc3158e093b995ca7b9b6aa32388ccdda076ef2fc169a0b5f640e8433d77d1f45"><a name="ggadc3158e093b995ca7b9b6aa32388ccdda076ef2fc169a0b5f640e8433d77d1f45"></a><a name="ggadc3158e093b995ca7b9b6aa32388ccdda076ef2fc169a0b5f640e8433d77d1f45"></a></strong>AUDIO_VOICE_DOWNLINK </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1336046310165625"><a name="p1336046310165625"></a><a name="p1336046310165625"></a>Downlink voice </p>
 </td>
</tr>
<tr id="row802675000165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggadc3158e093b995ca7b9b6aa32388ccdda3d978f472db3ff575a1b4ab84acbc15c"><a name="ggadc3158e093b995ca7b9b6aa32388ccdda3d978f472db3ff575a1b4ab84acbc15c"></a><a name="ggadc3158e093b995ca7b9b6aa32388ccdda3d978f472db3ff575a1b4ab84acbc15c"></a></strong>AUDIO_VOICE_CALL </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p467023698165625"><a name="p467023698165625"></a><a name="p467023698165625"></a>Voice call </p>
 </td>
</tr>
<tr id="row1743094146165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggadc3158e093b995ca7b9b6aa32388ccdda0d2b7337a260ae5c32abd843f5d52ec8"><a name="ggadc3158e093b995ca7b9b6aa32388ccdda0d2b7337a260ae5c32abd843f5d52ec8"></a><a name="ggadc3158e093b995ca7b9b6aa32388ccdda0d2b7337a260ae5c32abd843f5d52ec8"></a></strong>AUDIO_CAMCORDER </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p4680945165625"><a name="p4680945165625"></a><a name="p4680945165625"></a>Camcorder </p>
 </td>
</tr>
<tr id="row1705682117165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggadc3158e093b995ca7b9b6aa32388ccdda2491fee4b6ca4dce9c05babc3c1168e8"><a name="ggadc3158e093b995ca7b9b6aa32388ccdda2491fee4b6ca4dce9c05babc3c1168e8"></a><a name="ggadc3158e093b995ca7b9b6aa32388ccdda2491fee4b6ca4dce9c05babc3c1168e8"></a></strong>AUDIO_VOICE_RECOGNITION </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p601251199165625"><a name="p601251199165625"></a><a name="p601251199165625"></a>Voice recognition </p>
 </td>
</tr>
<tr id="row899983511165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggadc3158e093b995ca7b9b6aa32388ccdda09ce48df53dbaea4ef4273614bdc5445"><a name="ggadc3158e093b995ca7b9b6aa32388ccdda09ce48df53dbaea4ef4273614bdc5445"></a><a name="ggadc3158e093b995ca7b9b6aa32388ccdda09ce48df53dbaea4ef4273614bdc5445"></a></strong>AUDIO_VOICE_COMMUNICATION </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p326020979165625"><a name="p326020979165625"></a><a name="p326020979165625"></a>Voice communication </p>
 </td>
</tr>
<tr id="row1487583316165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggadc3158e093b995ca7b9b6aa32388ccddaef3dbfe38c377d77d0e40a9808012981"><a name="ggadc3158e093b995ca7b9b6aa32388ccddaef3dbfe38c377d77d0e40a9808012981"></a><a name="ggadc3158e093b995ca7b9b6aa32388ccddaef3dbfe38c377d77d0e40a9808012981"></a></strong>AUDIO_REMOTE_SUBMIX </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p761636574165625"><a name="p761636574165625"></a><a name="p761636574165625"></a>Remote submix </p>
 </td>
</tr>
<tr id="row842036152165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggadc3158e093b995ca7b9b6aa32388ccdda2fd32b7e954f7988ae41b63167948caf"><a name="ggadc3158e093b995ca7b9b6aa32388ccdda2fd32b7e954f7988ae41b63167948caf"></a><a name="ggadc3158e093b995ca7b9b6aa32388ccdda2fd32b7e954f7988ae41b63167948caf"></a></strong>AUDIO_UNPROCESSED </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1121674891165625"><a name="p1121674891165625"></a><a name="p1121674891165625"></a>Unprocessed audio </p>
 </td>
</tr>
<tr id="row750272721165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggadc3158e093b995ca7b9b6aa32388ccdda532f7c38a1feb89c8cb3a4e07f0c2cbe"><a name="ggadc3158e093b995ca7b9b6aa32388ccdda532f7c38a1feb89c8cb3a4e07f0c2cbe"></a><a name="ggadc3158e093b995ca7b9b6aa32388ccdda532f7c38a1feb89c8cb3a4e07f0c2cbe"></a></strong>AUDIO_VOICE_PERFORMANCE </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p113680861165625"><a name="p113680861165625"></a><a name="p113680861165625"></a>Voice performance </p>
 </td>
</tr>
<tr id="row1697089182165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggadc3158e093b995ca7b9b6aa32388ccdda295b4d6de2ba41d7783fddbf1543e830"><a name="ggadc3158e093b995ca7b9b6aa32388ccdda295b4d6de2ba41d7783fddbf1543e830"></a><a name="ggadc3158e093b995ca7b9b6aa32388ccdda295b4d6de2ba41d7783fddbf1543e830"></a></strong>AUDIO_ECHO_REFERENCE </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p179403118165625"><a name="p179403118165625"></a><a name="p179403118165625"></a>Echo reference </p>
 </td>
</tr>
<tr id="row1139303730165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggadc3158e093b995ca7b9b6aa32388ccdda5492fbdf785a745195f80020dba4f37e"><a name="ggadc3158e093b995ca7b9b6aa32388ccdda5492fbdf785a745195f80020dba4f37e"></a><a name="ggadc3158e093b995ca7b9b6aa32388ccdda5492fbdf785a745195f80020dba4f37e"></a></strong>AUDIO_RADIO_TUNER </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p847145090165625"><a name="p847145090165625"></a><a name="p847145090165625"></a>Radio tuner </p>
 </td>
</tr>
<tr id="row1393481307165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggadc3158e093b995ca7b9b6aa32388ccdda210886d5f821c08c5a36e71363d330f6"><a name="ggadc3158e093b995ca7b9b6aa32388ccdda210886d5f821c08c5a36e71363d330f6"></a><a name="ggadc3158e093b995ca7b9b6aa32388ccdda210886d5f821c08c5a36e71363d330f6"></a></strong>AUDIO_HOTWORD </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1408564255165625"><a name="p1408564255165625"></a><a name="p1408564255165625"></a>Hotword </p>
 </td>
</tr>
<tr id="row49808607165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggadc3158e093b995ca7b9b6aa32388ccddad0b4097d682e6cc4d7d92e5f0612a831"><a name="ggadc3158e093b995ca7b9b6aa32388ccddad0b4097d682e6cc4d7d92e5f0612a831"></a><a name="ggadc3158e093b995ca7b9b6aa32388ccddad0b4097d682e6cc4d7d92e5f0612a831"></a></strong>AUDIO_REMOTE_SUBMIX_EXTEND </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1351029880165625"><a name="p1351029880165625"></a><a name="p1351029880165625"></a>Extended remote submix </p>
 </td>
</tr>
</tbody>
</table>

## AudioStreamType<a name="gae7077e4211e48131ae544adb20fc494a"></a>

```
enum [AudioStreamType](MultiMedia_MediaCommon.md#gae7077e4211e48131ae544adb20fc494a)
```

 **Description:**

Enumerates audio stream types. 

<a name="table316217689165625"></a>
<table><thead align="left"><tr id="row1413333397165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2107838232165625"><a name="p2107838232165625"></a><a name="p2107838232165625"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p501421615165625"><a name="p501421615165625"></a><a name="p501421615165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row403336565165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggae7077e4211e48131ae544adb20fc494aa80d7bb9558588a28f24aec4c019fdbd6"><a name="ggae7077e4211e48131ae544adb20fc494aa80d7bb9558588a28f24aec4c019fdbd6"></a><a name="ggae7077e4211e48131ae544adb20fc494aa80d7bb9558588a28f24aec4c019fdbd6"></a></strong>TYPE_DEFAULT </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1762206146165625"><a name="p1762206146165625"></a><a name="p1762206146165625"></a>Default audio stream type </p>
 </td>
</tr>
<tr id="row733251785165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggae7077e4211e48131ae544adb20fc494aa431e273affaa22e18ec5a2a548b70e90"><a name="ggae7077e4211e48131ae544adb20fc494aa431e273affaa22e18ec5a2a548b70e90"></a><a name="ggae7077e4211e48131ae544adb20fc494aa431e273affaa22e18ec5a2a548b70e90"></a></strong>TYPE_MEDIA </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1404993709165625"><a name="p1404993709165625"></a><a name="p1404993709165625"></a>Media </p>
 </td>
</tr>
<tr id="row422426240165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggae7077e4211e48131ae544adb20fc494aa5bfd254bb72236e9c463aefeb4343194"><a name="ggae7077e4211e48131ae544adb20fc494aa5bfd254bb72236e9c463aefeb4343194"></a><a name="ggae7077e4211e48131ae544adb20fc494aa5bfd254bb72236e9c463aefeb4343194"></a></strong>TYPE_VOICE_COMMUNICATION </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p441722592165625"><a name="p441722592165625"></a><a name="p441722592165625"></a>Voice call </p>
 </td>
</tr>
<tr id="row2015881625165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggae7077e4211e48131ae544adb20fc494aa0ae2b45a2675c159915c1e76f2f2c846"><a name="ggae7077e4211e48131ae544adb20fc494aa0ae2b45a2675c159915c1e76f2f2c846"></a><a name="ggae7077e4211e48131ae544adb20fc494aa0ae2b45a2675c159915c1e76f2f2c846"></a></strong>TYPE_SYSTEM </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2002944661165625"><a name="p2002944661165625"></a><a name="p2002944661165625"></a>System sound </p>
 </td>
</tr>
<tr id="row486041025165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggae7077e4211e48131ae544adb20fc494aafe3e3697e6e9f7880cb90d40e1d4d708"><a name="ggae7077e4211e48131ae544adb20fc494aafe3e3697e6e9f7880cb90d40e1d4d708"></a><a name="ggae7077e4211e48131ae544adb20fc494aafe3e3697e6e9f7880cb90d40e1d4d708"></a></strong>TYPE_RING </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p633599098165625"><a name="p633599098165625"></a><a name="p633599098165625"></a>Ringtone </p>
 </td>
</tr>
<tr id="row953855617165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggae7077e4211e48131ae544adb20fc494aa801a700d4c9f12285930e9eeace6feb4"><a name="ggae7077e4211e48131ae544adb20fc494aa801a700d4c9f12285930e9eeace6feb4"></a><a name="ggae7077e4211e48131ae544adb20fc494aa801a700d4c9f12285930e9eeace6feb4"></a></strong>TYPE_MUSIC </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1259376428165625"><a name="p1259376428165625"></a><a name="p1259376428165625"></a>Music </p>
 </td>
</tr>
<tr id="row455406147165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggae7077e4211e48131ae544adb20fc494aae93097f5314613a0eb5465187102bd5f"><a name="ggae7077e4211e48131ae544adb20fc494aae93097f5314613a0eb5465187102bd5f"></a><a name="ggae7077e4211e48131ae544adb20fc494aae93097f5314613a0eb5465187102bd5f"></a></strong>TYPE_ALARM </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1360215435165625"><a name="p1360215435165625"></a><a name="p1360215435165625"></a>Alarm </p>
 </td>
</tr>
<tr id="row37845457165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggae7077e4211e48131ae544adb20fc494aa7f3c9297ca35f503b5f7b6cb36610ef6"><a name="ggae7077e4211e48131ae544adb20fc494aa7f3c9297ca35f503b5f7b6cb36610ef6"></a><a name="ggae7077e4211e48131ae544adb20fc494aa7f3c9297ca35f503b5f7b6cb36610ef6"></a></strong>TYPE_NOTIFICATION </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p75465217165625"><a name="p75465217165625"></a><a name="p75465217165625"></a>Notification </p>
 </td>
</tr>
<tr id="row988248256165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggae7077e4211e48131ae544adb20fc494aac47f3bf77df994414bd9514f8264e277"><a name="ggae7077e4211e48131ae544adb20fc494aac47f3bf77df994414bd9514f8264e277"></a><a name="ggae7077e4211e48131ae544adb20fc494aac47f3bf77df994414bd9514f8264e277"></a></strong>TYPE_BLUETOOTH_SCO </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1332373217165625"><a name="p1332373217165625"></a><a name="p1332373217165625"></a>Bluetooth Synchronous Connection-Oriented (SCO) </p>
 </td>
</tr>
<tr id="row1030281068165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggae7077e4211e48131ae544adb20fc494aa00376353eb14c2d326026e6a7cdf6674"><a name="ggae7077e4211e48131ae544adb20fc494aa00376353eb14c2d326026e6a7cdf6674"></a><a name="ggae7077e4211e48131ae544adb20fc494aa00376353eb14c2d326026e6a7cdf6674"></a></strong>TYPE_ENFORCED_AUDIBLE </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p10515858165625"><a name="p10515858165625"></a><a name="p10515858165625"></a>Enforced audible </p>
 </td>
</tr>
<tr id="row1787226162165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggae7077e4211e48131ae544adb20fc494aad61d97f9466b24094407016ce4231f7b"><a name="ggae7077e4211e48131ae544adb20fc494aad61d97f9466b24094407016ce4231f7b"></a><a name="ggae7077e4211e48131ae544adb20fc494aad61d97f9466b24094407016ce4231f7b"></a></strong>TYPE_DTMF </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1568212489165625"><a name="p1568212489165625"></a><a name="p1568212489165625"></a>Dual-tone multi-frequency (DTMF) </p>
 </td>
</tr>
<tr id="row2053338016165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggae7077e4211e48131ae544adb20fc494aa8e6eb63161413e4bbb207dfb29efe95f"><a name="ggae7077e4211e48131ae544adb20fc494aa8e6eb63161413e4bbb207dfb29efe95f"></a><a name="ggae7077e4211e48131ae544adb20fc494aa8e6eb63161413e4bbb207dfb29efe95f"></a></strong>TYPE_TTS </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p958261055165625"><a name="p958261055165625"></a><a name="p958261055165625"></a>Text-To-Speech (TTS) </p>
 </td>
</tr>
<tr id="row1592003390165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggae7077e4211e48131ae544adb20fc494aa38333aca1beda5f77cc1ce3d0c322262"><a name="ggae7077e4211e48131ae544adb20fc494aa38333aca1beda5f77cc1ce3d0c322262"></a><a name="ggae7077e4211e48131ae544adb20fc494aa38333aca1beda5f77cc1ce3d0c322262"></a></strong>TYPE_ACCESSIBILITY </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p943569516165625"><a name="p943569516165625"></a><a name="p943569516165625"></a>Accessibility </p>
 </td>
</tr>
</tbody>
</table>

## BufferFlags<a name="ga6f4847f443de5cdf3641386011335e21"></a>

```
enum [OHOS::Media::StreamCallback::BufferFlags](MultiMedia_MediaCommon.md#ga6f4847f443de5cdf3641386011335e21) : uint32_t
```

 **Description:**

Enumerates buffer types of stream sources. 

<a name="table2090984007165625"></a>
<table><thead align="left"><tr id="row1893951253165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1445607342165625"><a name="p1445607342165625"></a><a name="p1445607342165625"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p739541533165625"><a name="p739541533165625"></a><a name="p739541533165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1081355432165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga6f4847f443de5cdf3641386011335e21ac1a3ce4ddd663c55f87a8275ccf285ad"><a name="gga6f4847f443de5cdf3641386011335e21ac1a3ce4ddd663c55f87a8275ccf285ad"></a><a name="gga6f4847f443de5cdf3641386011335e21ac1a3ce4ddd663c55f87a8275ccf285ad"></a></strong>STREAM_FLAG_SYNCFRAME </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1574409889165625"><a name="p1574409889165625"></a><a name="p1574409889165625"></a>Synchronous frame </p>
 </td>
</tr>
<tr id="row238586934165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga6f4847f443de5cdf3641386011335e21afd0d977a6a5d48657d694c9acb8ac2b5"><a name="gga6f4847f443de5cdf3641386011335e21afd0d977a6a5d48657d694c9acb8ac2b5"></a><a name="gga6f4847f443de5cdf3641386011335e21afd0d977a6a5d48657d694c9acb8ac2b5"></a></strong>STREAM_FLAG_CODECCONFIG </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p61885000165625"><a name="p61885000165625"></a><a name="p61885000165625"></a>Codec configuration information </p>
 </td>
</tr>
<tr id="row2124602244165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga6f4847f443de5cdf3641386011335e21aa76ecb4ee6077a1ad3ceac569b875487"><a name="gga6f4847f443de5cdf3641386011335e21aa76ecb4ee6077a1ad3ceac569b875487"></a><a name="gga6f4847f443de5cdf3641386011335e21aa76ecb4ee6077a1ad3ceac569b875487"></a></strong>STREAM_FLAG_EOS </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1118104893165625"><a name="p1118104893165625"></a><a name="p1118104893165625"></a>End of Stream (EOS) </p>
 </td>
</tr>
<tr id="row2128324173165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga6f4847f443de5cdf3641386011335e21a29e735a1e41790c24cc9ac9e7342dd2a"><a name="gga6f4847f443de5cdf3641386011335e21a29e735a1e41790c24cc9ac9e7342dd2a"></a><a name="gga6f4847f443de5cdf3641386011335e21a29e735a1e41790c24cc9ac9e7342dd2a"></a></strong>STREAM_FLAG_PARTIAL_FRAME </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1723721006165625"><a name="p1723721006165625"></a><a name="p1723721006165625"></a>Part of a frame </p>
 </td>
</tr>
<tr id="row1650161773165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga6f4847f443de5cdf3641386011335e21a8b2c1f065ce398ac48bac2b8e62e481b"><a name="gga6f4847f443de5cdf3641386011335e21a8b2c1f065ce398ac48bac2b8e62e481b"></a><a name="gga6f4847f443de5cdf3641386011335e21a8b2c1f065ce398ac48bac2b8e62e481b"></a></strong>STREAM_FLAG_ENDOFFRAME </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1397665498165625"><a name="p1397665498165625"></a><a name="p1397665498165625"></a>End of a frame. It is used in pair with <strong id="b71422265165625"><a name="b71422265165625"></a><a name="b71422265165625"></a>STREAM_FLAG_PARTIAL_FRAME</strong>. </p>
 </td>
</tr>
<tr id="row512307197165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga6f4847f443de5cdf3641386011335e21a9001c389dd39f08025e76ae2872fad02"><a name="gga6f4847f443de5cdf3641386011335e21a9001c389dd39f08025e76ae2872fad02"></a><a name="gga6f4847f443de5cdf3641386011335e21a9001c389dd39f08025e76ae2872fad02"></a></strong>STREAM_FLAG_MUXER_DATA </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1541178885165625"><a name="p1541178885165625"></a><a name="p1541178885165625"></a>Container file data, such as MP4 file data (not supported yet) </p>
 </td>
</tr>
</tbody>
</table>

## FormatDataType<a name="gaa3bfacc6563d8ec8bc870f4b216b4f46"></a>

```
enum [OHOS::Media::FormatDataType](MultiMedia_MediaCommon.md#gaa3bfacc6563d8ec8bc870f4b216b4f46) : uint32_t
```

 **Description:**

Enumerates formats. 

<a name="table271264191165625"></a>
<table><thead align="left"><tr id="row1787490465165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p816857670165625"><a name="p816857670165625"></a><a name="p816857670165625"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1311050958165625"><a name="p1311050958165625"></a><a name="p1311050958165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1451891131165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaa3bfacc6563d8ec8bc870f4b216b4f46a3a3f84f7e1a28c0f91a12f8a3bcfe8ec"><a name="ggaa3bfacc6563d8ec8bc870f4b216b4f46a3a3f84f7e1a28c0f91a12f8a3bcfe8ec"></a><a name="ggaa3bfacc6563d8ec8bc870f4b216b4f46a3a3f84f7e1a28c0f91a12f8a3bcfe8ec"></a></strong>FORMAT_TYPE_NONE </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1696211675165625"><a name="p1696211675165625"></a><a name="p1696211675165625"></a>None </p>
 </td>
</tr>
<tr id="row90029923165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaa3bfacc6563d8ec8bc870f4b216b4f46a48d8e70734d5c29f8766ad12037ca3ae"><a name="ggaa3bfacc6563d8ec8bc870f4b216b4f46a48d8e70734d5c29f8766ad12037ca3ae"></a><a name="ggaa3bfacc6563d8ec8bc870f4b216b4f46a48d8e70734d5c29f8766ad12037ca3ae"></a></strong>FORMAT_TYPE_INT32 </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p163059861165625"><a name="p163059861165625"></a><a name="p163059861165625"></a>Int32 </p>
 </td>
</tr>
<tr id="row577881895165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaa3bfacc6563d8ec8bc870f4b216b4f46a108496713fc9bb4b77a8acf38a1396c9"><a name="ggaa3bfacc6563d8ec8bc870f4b216b4f46a108496713fc9bb4b77a8acf38a1396c9"></a><a name="ggaa3bfacc6563d8ec8bc870f4b216b4f46a108496713fc9bb4b77a8acf38a1396c9"></a></strong>FORMAT_TYPE_INT64 </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p61979009165625"><a name="p61979009165625"></a><a name="p61979009165625"></a>Int64 </p>
 </td>
</tr>
<tr id="row637532440165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaa3bfacc6563d8ec8bc870f4b216b4f46a3fd208a39e6c4f22d10882b03a547db1"><a name="ggaa3bfacc6563d8ec8bc870f4b216b4f46a3fd208a39e6c4f22d10882b03a547db1"></a><a name="ggaa3bfacc6563d8ec8bc870f4b216b4f46a3fd208a39e6c4f22d10882b03a547db1"></a></strong>FORMAT_TYPE_FLOAT </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1427423572165625"><a name="p1427423572165625"></a><a name="p1427423572165625"></a>Float </p>
 </td>
</tr>
<tr id="row1892681206165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaa3bfacc6563d8ec8bc870f4b216b4f46abb224970f66920c7a443d19051fdc57f"><a name="ggaa3bfacc6563d8ec8bc870f4b216b4f46abb224970f66920c7a443d19051fdc57f"></a><a name="ggaa3bfacc6563d8ec8bc870f4b216b4f46abb224970f66920c7a443d19051fdc57f"></a></strong>FORMAT_TYPE_DOUBLE </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1299100176165625"><a name="p1299100176165625"></a><a name="p1299100176165625"></a>Double </p>
 </td>
</tr>
<tr id="row1831640808165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaa3bfacc6563d8ec8bc870f4b216b4f46a21c29eb61b772af7bead2a77a8c87cf6"><a name="ggaa3bfacc6563d8ec8bc870f4b216b4f46a21c29eb61b772af7bead2a77a8c87cf6"></a><a name="ggaa3bfacc6563d8ec8bc870f4b216b4f46a21c29eb61b772af7bead2a77a8c87cf6"></a></strong>FORMAT_TYPE_STRING </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2133324823165625"><a name="p2133324823165625"></a><a name="p2133324823165625"></a>String </p>
 </td>
</tr>
</tbody>
</table>

## SourceType<a name="ga4052b7b55dfd94f1d07678e79d80b507"></a>

```
enum [OHOS::Media::SourceType](MultiMedia_MediaCommon.md#ga4052b7b55dfd94f1d07678e79d80b507) : int32_t
```

 **Description:**

Enumerates media source types. 

<a name="table553598456165625"></a>
<table><thead align="left"><tr id="row33020044165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1387452370165625"><a name="p1387452370165625"></a><a name="p1387452370165625"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2002089783165625"><a name="p2002089783165625"></a><a name="p2002089783165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1754487683165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga4052b7b55dfd94f1d07678e79d80b507ae456eda14b2359e13cc36f77af92c11b"><a name="gga4052b7b55dfd94f1d07678e79d80b507ae456eda14b2359e13cc36f77af92c11b"></a><a name="gga4052b7b55dfd94f1d07678e79d80b507ae456eda14b2359e13cc36f77af92c11b"></a></strong>SOURCE_TYPE_URI </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1742817981165625"><a name="p1742817981165625"></a><a name="p1742817981165625"></a>Local file path or network address </p>
 </td>
</tr>
<tr id="row666926818165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga4052b7b55dfd94f1d07678e79d80b507a4134c6ec0b1a7fda26c38b8932e606e5"><a name="gga4052b7b55dfd94f1d07678e79d80b507a4134c6ec0b1a7fda26c38b8932e606e5"></a><a name="gga4052b7b55dfd94f1d07678e79d80b507a4134c6ec0b1a7fda26c38b8932e606e5"></a></strong>SOURCE_TYPE_FD </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p639109615165625"><a name="p639109615165625"></a><a name="p639109615165625"></a>Local file descriptor </p>
 </td>
</tr>
<tr id="row432421146165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga4052b7b55dfd94f1d07678e79d80b507a538f01f856d995123459a44642a7dc86"><a name="gga4052b7b55dfd94f1d07678e79d80b507a538f01f856d995123459a44642a7dc86"></a><a name="gga4052b7b55dfd94f1d07678e79d80b507a538f01f856d995123459a44642a7dc86"></a></strong>SOURCE_TYPE_STREAM </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p974197830165625"><a name="p974197830165625"></a><a name="p974197830165625"></a>Stream data, such as Advanced Audio Coding (AAC) stream data </p>
 </td>
</tr>
</tbody>
</table>

## VideoCodecFormat<a name="ga797e6c5e38e23e730eff5bcc41427d7e"></a>

```
enum [VideoCodecFormat](MultiMedia_MediaCommon.md#ga797e6c5e38e23e730eff5bcc41427d7e)
```

 **Description:**

Enumerates video codec formats. 

<a name="table1536765434165625"></a>
<table><thead align="left"><tr id="row1075886971165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1045352840165625"><a name="p1045352840165625"></a><a name="p1045352840165625"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p459099676165625"><a name="p459099676165625"></a><a name="p459099676165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1646193789165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga797e6c5e38e23e730eff5bcc41427d7ea54ef59464d0b6788c6212bb1b5074503"><a name="gga797e6c5e38e23e730eff5bcc41427d7ea54ef59464d0b6788c6212bb1b5074503"></a><a name="gga797e6c5e38e23e730eff5bcc41427d7ea54ef59464d0b6788c6212bb1b5074503"></a></strong>VIDEO_DEFAULT </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1456710234165625"><a name="p1456710234165625"></a><a name="p1456710234165625"></a>Default format </p>
 </td>
</tr>
<tr id="row362956118165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga797e6c5e38e23e730eff5bcc41427d7eac3f3371ea9f44c4076fec8f0d8f818cf"><a name="gga797e6c5e38e23e730eff5bcc41427d7eac3f3371ea9f44c4076fec8f0d8f818cf"></a><a name="gga797e6c5e38e23e730eff5bcc41427d7eac3f3371ea9f44c4076fec8f0d8f818cf"></a></strong>H264 </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1569503039165625"><a name="p1569503039165625"></a><a name="p1569503039165625"></a>H.264 </p>
 </td>
</tr>
<tr id="row82362724165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga797e6c5e38e23e730eff5bcc41427d7eac2489c86e2690559ce3a00a03b15c324"><a name="gga797e6c5e38e23e730eff5bcc41427d7eac2489c86e2690559ce3a00a03b15c324"></a><a name="gga797e6c5e38e23e730eff5bcc41427d7eac2489c86e2690559ce3a00a03b15c324"></a></strong>HEVC </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p140772809165625"><a name="p140772809165625"></a><a name="p140772809165625"></a>High Efficiency Video Coding (HEVC) </p>
 </td>
</tr>
</tbody>
</table>

## **Function **<a name="section1996891878165625"></a>

## CopyFrom\(\)<a name="ga528134c9f87bf755077b3ef51d64e198"></a>

```
bool OHOS::Media::Format::CopyFrom (const [Format](OHOS-Media-Format.md) & format)
```

 **Description:**

Sets all metadata to a specified format. 

**Parameters:**

<a name="table1128062457165625"></a>
<table><thead align="left"><tr id="row1329179879165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p765173783165625"><a name="p765173783165625"></a><a name="p765173783165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2030342618165625"><a name="p2030342618165625"></a><a name="p2030342618165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1834219277165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">format</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the format. For details, see <a href="OHOS-Media-Format.md">Format</a>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **true**  if the setting is successful; returns  **false**  otherwise. 

## ErrCodeOffset\(\)<a name="ga5534cc5ecbcb6eb719f55d8695bbb481"></a>

```
constexpr ErrCode OHOS::Media::ErrCodeOffset (unsigned int subsystem, unsigned int module = 0 )
```

 **Description:**

Generates a start error code with a unique identifier based on specified subsystem and module bit numbers. 

**Parameters:**

<a name="table1586089303165625"></a>
<table><thead align="left"><tr id="row1402104380165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p87040845165625"><a name="p87040845165625"></a><a name="p87040845165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1540952574165625"><a name="p1540952574165625"></a><a name="p1540952574165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row84048668165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">subsystem</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the subsystem bit number. </td>
</tr>
<tr id="row1516739950165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">module</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the module bit number. </td>
</tr>
</tbody>
</table>

**Returns:**

## Format\(\)<a name="ga42435567c8fd61fd2da4834465aca98e"></a>

```
OHOS::Media::Format::Format ()
```

 **Description:**

Default constructor of the  [Format](OHOS-Media-Format.md)  instance. 

## GetBuffer\(\)<a name="ga8f897b8b2d5baf06e15accfeb97892ae"></a>

```
virtual uint8_t* OHOS::Media::StreamCallback::GetBuffer (size_t index)
```

 **Description:**

Obtains the virtual address of a buffer memory block based on its index. 

**Parameters:**

<a name="table1500710594165625"></a>
<table><thead align="left"><tr id="row1465843406165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1264963754165625"><a name="p1264963754165625"></a><a name="p1264963754165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2022060238165625"><a name="p2022060238165625"></a><a name="p2022060238165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2096581389165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">index</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the index of the buffer memory block. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the pointer to the virtual address of the buffer memory block. 

## GetDoubleValue\(\) \[1/2\]<a name="gafe949ed0c2d9dcb5c5e57c7fde226f3e"></a>

```
bool OHOS::Media::Format::GetDoubleValue (const std::string & key, double & value ) const
```

 **Description:**

Obtains the metadata value of the double-precision floating-point type. 

**Parameters:**

<a name="table1589446255165625"></a>
<table><thead align="left"><tr id="row1570198091165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1540256179165625"><a name="p1540256179165625"></a><a name="p1540256179165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p866937558165625"><a name="p866937558165625"></a><a name="p866937558165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1823786757165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">key</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the metadata key. </td>
</tr>
<tr id="row1100356548165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">value</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the metadata value to obtain, which is a double-precision floating-point number. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **true**  if the double-precision number is successfully obtained; returns  **false**  otherwise. 

## GetDoubleValue\(\) \[2/2\]<a name="gac1ed56f6d35982f770d083dc16e97dbd"></a>

```
bool OHOS::Media::FormatData::GetDoubleValue (double & val) const
```

 **Description:**

Obtains a double-precision floating-point number. 

**Parameters:**

<a name="table21129326165625"></a>
<table><thead align="left"><tr id="row294994239165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1746987542165625"><a name="p1746987542165625"></a><a name="p1746987542165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1085193845165625"><a name="p1085193845165625"></a><a name="p1085193845165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row756725266165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">val</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double-precision floating-point number to obtain. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **true**  if the double-precision number is successfully obtained; returns  **false**  otherwise. 

## GetFloatValue\(\) \[1/2\]<a name="gac4e963a9fe320c0143ed33df5f737cb3"></a>

```
bool OHOS::Media::Format::GetFloatValue (const std::string & key, float & value ) const
```

 **Description:**

Obtains the metadata value of the single-precision floating-point type. 

**Parameters:**

<a name="table925155690165625"></a>
<table><thead align="left"><tr id="row673312921165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p15260235165625"><a name="p15260235165625"></a><a name="p15260235165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p176028627165625"><a name="p176028627165625"></a><a name="p176028627165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2145759681165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">key</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the metadata key. </td>
</tr>
<tr id="row237305574165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">value</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the metadata value to obtain, which is a single-precision floating-point number. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **true**  if the single-precision number is successfully obtained; returns  **false**  otherwise. 

## GetFloatValue\(\) \[2/2\]<a name="gada31b9cf5daa944104417442a5e459dc"></a>

```
bool OHOS::Media::FormatData::GetFloatValue (float & val) const
```

 **Description:**

Obtains a single-precision floating-point number. 

**Parameters:**

<a name="table1474082368165625"></a>
<table><thead align="left"><tr id="row1908412637165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p515771001165625"><a name="p515771001165625"></a><a name="p515771001165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2065690733165625"><a name="p2065690733165625"></a><a name="p2065690733165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1497777709165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">val</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the single-precision floating-point number to obtain. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **true**  if the single-precision number is successfully obtained; returns  **false**  otherwise. 

## GetFormatMap\(\)<a name="ga4adff4846515cef00987a360a4d117af"></a>

```
const std::map<std::string, [FormatData](OHOS-Media-FormatData.md) *>& OHOS::Media::Format::GetFormatMap () const
```

 **Description:**

Obtains the metadata map. 

**Returns:**

Returns the map object. 

## GetInt32Value\(\)<a name="gac116d67e5e80f1f9c1c573ceb24df36a"></a>

```
bool OHOS::Media::FormatData::GetInt32Value (int32_t & val) const
```

 **Description:**

Obtains a 32-bit integer. 

**Parameters:**

<a name="table1801150451165625"></a>
<table><thead align="left"><tr id="row1797137190165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p527281924165625"><a name="p527281924165625"></a><a name="p527281924165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p65986223165625"><a name="p65986223165625"></a><a name="p65986223165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row54674398165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">val</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the 32-bit integer to obtain. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **true**  if the integer is successfully obtained; returns  **false**  otherwise. 

## GetInt64Value\(\)<a name="ga1f24cb15577c40f7044f4beb96515cfc"></a>

```
bool OHOS::Media::FormatData::GetInt64Value (int64_t & val) const
```

 **Description:**

Obtains a long integer. 

**Parameters:**

<a name="table610514539165625"></a>
<table><thead align="left"><tr id="row1347350008165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1888857888165625"><a name="p1888857888165625"></a><a name="p1888857888165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1210029975165625"><a name="p1210029975165625"></a><a name="p1210029975165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row38374324165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">val</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the long integer to obtain. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **true**  if the integer is successfully obtained; returns  **false**  otherwise. 

## GetIntValue\(\)<a name="ga798ef733a253558757f49714090b3969"></a>

```
bool OHOS::Media::Format::GetIntValue (const std::string & key, int32_t & value ) const
```

 **Description:**

Obtains the metadata value of the integer type. 

**Parameters:**

<a name="table635968755165625"></a>
<table><thead align="left"><tr id="row671230318165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2003161887165625"><a name="p2003161887165625"></a><a name="p2003161887165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p318643147165625"><a name="p318643147165625"></a><a name="p318643147165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1913289682165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">key</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the metadata key. </td>
</tr>
<tr id="row1705416942165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">value</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the metadata value to obtain, which is a 32-bit integer. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **true**  if the integer is successfully obtained; returns  **false**  otherwise. 

## GetLongValue\(\)<a name="ga7f1c503f40b78083cb9b9ae9ce93d3b4"></a>

```
bool OHOS::Media::Format::GetLongValue (const std::string & key, int64_t & value ) const
```

 **Description:**

Obtains the metadata value of the long integer type. 

**Parameters:**

<a name="table681138390165625"></a>
<table><thead align="left"><tr id="row1181537872165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2006949941165625"><a name="p2006949941165625"></a><a name="p2006949941165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1927730939165625"><a name="p1927730939165625"></a><a name="p1927730939165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row754239096165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">key</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the metadata key. </td>
</tr>
<tr id="row208083653165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">value</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the metadata value to obtain, which is a 64-bit long integer. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **true**  if the integer is successfully obtained; returns  **false**  otherwise. 

## GetSourceStream\(\)<a name="ga395325402881ad38ef40c9ebd13f174d"></a>

```
const std::shared_ptr<[StreamSource](OHOS-Media-StreamSource.md)>& OHOS::Media::Source::GetSourceStream () const
```

 **Description:**

Obtains information about the media source stream. 

This function is called only when the  [SourceType](Format.md#ga3ae727773c367ac1041d72ac770a0ab1)  is  [SOURCE\_TYPE\_STREAM](Format.md#gga3ae727773c367ac1041d72ac770a0ab1a7f632a791d8f6dfbe5940b5648d29e6c).

**Returns:**

Returns information about the media source stream. For details, see  [StreamSource](OHOS-Media-StreamSource.md). 

## GetSourceStreamFormat\(\)<a name="gafbd3c732660124a1dc1d9dd0dfb51393"></a>

```
const [Format](OHOS-Media-Format.md)& OHOS::Media::Source::GetSourceStreamFormat () const
```

 **Description:**

Obtains the media source stream format. 

**Returns:**

Returns the media source stream format. For details, see  [Format](OHOS-Media-Format.md). 

## GetSourceType\(\)<a name="ga93a8f8b86a9385436f6bbce10a860770"></a>

```
[SourceType](MultiMedia_MediaCommon.md#ga4052b7b55dfd94f1d07678e79d80b507) OHOS::Media::Source::GetSourceType () const
```

 **Description:**

Obtains the source type. 

**Returns:**

Returns the source type. For details, see  [SourceType](Format.md#ga3ae727773c367ac1041d72ac770a0ab1). 

## GetSourceUri\(\)<a name="ga69ed2683ce3a632f6b2295fb398e4b7b"></a>

```
const std::string& OHOS::Media::Source::GetSourceUri () const
```

 **Description:**

Obtains the media source URI. 

This function is called only when the  [SourceType](Format.md#ga3ae727773c367ac1041d72ac770a0ab1)  is  [SOURCE\_TYPE\_URI](Format.md#gga3ae727773c367ac1041d72ac770a0ab1a70d32ea5aeaa325764508722ba31403c).

**Returns:**

Returns the media source URI. 

## GetStringValue\(\) \[1/2\]<a name="ga089a3e44e128fb662b72c56b53c7068b"></a>

```
bool OHOS::Media::Format::GetStringValue (const std::string & key, std::string & value ) const
```

 **Description:**

Obtains the metadata value of the string type. 

**Parameters:**

<a name="table2055968043165625"></a>
<table><thead align="left"><tr id="row906299509165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p390852206165625"><a name="p390852206165625"></a><a name="p390852206165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1261434232165625"><a name="p1261434232165625"></a><a name="p1261434232165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1512681347165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">key</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the metadata key. </td>
</tr>
<tr id="row1489485064165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">value</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the metadata value to obtain, which is a string. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **true**  if the string is successfully obtained; returns  **false**  otherwise. 

## GetStringValue\(\) \[2/2\]<a name="ga9687bb5d98a92e7beb53dfe4ac44eec1"></a>

```
bool OHOS::Media::FormatData::GetStringValue (std::string & val) const
```

 **Description:**

Obtains a string. 

**Parameters:**

<a name="table1363176647165625"></a>
<table><thead align="left"><tr id="row840791276165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p758312153165625"><a name="p758312153165625"></a><a name="p758312153165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p377282729165625"><a name="p377282729165625"></a><a name="p377282729165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1748031538165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">val</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the string to obtain. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **true**  if the string is successfully obtained; returns  **false**  otherwise. 

## GetType\(\)<a name="ga178a65e0d58071de84e2dbc09ac93407"></a>

```
[FormatDataType](MultiMedia_MediaCommon.md#gaa3bfacc6563d8ec8bc870f4b216b4f46) OHOS::Media::FormatData::GetType () const
```

 **Description:**

Obtains the format type. 

**Returns:**

Returns the format type. For details, see  **OHOS::Media::FormatDataType**. 

## OnBufferAvailable\(\)<a name="gaaebd4fe9df44b434f410aec32cf23467"></a>

```
virtual void OHOS::Media::StreamSource::OnBufferAvailable (size_t index, size_t offset, size_t size )
```

 **Description:**

Notifies your application of the information about the buffer memory block that can be filled with data. 

**Parameters:**

<a name="table562963663165625"></a>
<table><thead align="left"><tr id="row1395344157165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1183766131165625"><a name="p1183766131165625"></a><a name="p1183766131165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1176984830165625"><a name="p1176984830165625"></a><a name="p1176984830165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row733232384165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">index</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the index of the buffer memory block. </td>
</tr>
<tr id="row2138602861165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">offset</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the start offset into which the data will be written. </td>
</tr>
<tr id="row177509329165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">size</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the size of data that the buffer memory block can store. </td>
</tr>
</tbody>
</table>

## PutDoubleValue\(\)<a name="ga9a98a92eb4436301853a049b5f3313c6"></a>

```
bool OHOS::Media::Format::PutDoubleValue (const std::string & key, double value )
```

 **Description:**

Sets metadata of the double-precision floating-point type. 

**Parameters:**

<a name="table194843603165625"></a>
<table><thead align="left"><tr id="row350969009165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1090175691165625"><a name="p1090175691165625"></a><a name="p1090175691165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p323609513165625"><a name="p323609513165625"></a><a name="p323609513165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1300984920165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">key</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the metadata key. </td>
</tr>
<tr id="row1084843003165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">value</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the metadata value, which is a double-precision floating-point number. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **true**  if the setting is successful; returns  **false**  otherwise. 

## PutFloatValue\(\)<a name="gabec9417120824f5bb9eb676be380016f"></a>

```
bool OHOS::Media::Format::PutFloatValue (const std::string & key, float value )
```

 **Description:**

Sets metadata of the single-precision floating-point type. 

**Parameters:**

<a name="table1164260420165625"></a>
<table><thead align="left"><tr id="row13970376165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1785368836165625"><a name="p1785368836165625"></a><a name="p1785368836165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1861428597165625"><a name="p1861428597165625"></a><a name="p1861428597165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1852561595165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">key</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the metadata key. </td>
</tr>
<tr id="row379854036165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">value</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the metadata value, which is a single-precision floating-point number. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **true**  if the metadata is successfully set; returns  **false**  otherwise. 

## PutIntValue\(\)<a name="ga66771efe315d001e79a14d316c58718e"></a>

```
bool OHOS::Media::Format::PutIntValue (const std::string & key, int32_t value )
```

 **Description:**

Sets metadata of the integer type. 

**Parameters:**

<a name="table179733478165625"></a>
<table><thead align="left"><tr id="row1075601280165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p631240600165625"><a name="p631240600165625"></a><a name="p631240600165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1927670320165625"><a name="p1927670320165625"></a><a name="p1927670320165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row521707735165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">key</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the metadata key. </td>
</tr>
<tr id="row403032994165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">value</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the metadata value, which is a 32-bit integer. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **true**  if the setting is successful; returns  **false**  otherwise. 

## PutLongValue\(\)<a name="ga5b4477636095d80ec4e65c1be617c61c"></a>

```
bool OHOS::Media::Format::PutLongValue (const std::string & key, int64_t value )
```

 **Description:**

Sets metadata of the long integer type. 

**Parameters:**

<a name="table1997261151165625"></a>
<table><thead align="left"><tr id="row1600674111165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1274092197165625"><a name="p1274092197165625"></a><a name="p1274092197165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1717743227165625"><a name="p1717743227165625"></a><a name="p1717743227165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1485615990165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">key</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the metadata key. </td>
</tr>
<tr id="row1725747169165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">value</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the metadata value, which is a 64-bit integer. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **true**  if the setting is successful; returns  **false**  otherwise. 

## PutStringValue\(\)<a name="gabdc104597559320256930f420eaab82f"></a>

```
bool OHOS::Media::Format::PutStringValue (const std::string & key, const std::string & value )
```

 **Description:**

Sets metadata of the string type. 

**Parameters:**

<a name="table803694096165625"></a>
<table><thead align="left"><tr id="row1640715055165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1327038225165625"><a name="p1327038225165625"></a><a name="p1327038225165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p528545324165625"><a name="p528545324165625"></a><a name="p528545324165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1740878823165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">key</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the metadata key. </td>
</tr>
<tr id="row112650133165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">value</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the metadata value, which is a string. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **true**  if the metadata is successfully set; returns  **false**  otherwise. 

## QueueBuffer\(\)<a name="gaa62705632557f47f9fd9632157e53a21"></a>

```
virtual void OHOS::Media::StreamCallback::QueueBuffer (size_t index, size_t offset, size_t size, int64_t timestampUs, uint32_t flags )
```

 **Description:**

Writes the filled buffer memory block into the player memory. 

**Parameters:**

<a name="table525255394165625"></a>
<table><thead align="left"><tr id="row2028652935165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1269461259165625"><a name="p1269461259165625"></a><a name="p1269461259165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1876508165165625"><a name="p1876508165165625"></a><a name="p1876508165165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row455226000165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">index</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the index of the buffer memory block. </td>
</tr>
<tr id="row1402518968165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">offset</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the start offset into which the buffer memory block will be written. </td>
</tr>
<tr id="row427094711165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">size</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the size of the data filled in the buffer memory block. </td>
</tr>
<tr id="row1447745095165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">timestampUs</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the timestamp of the frame filled in the buffer memory block. As data in AAC streams can be filled not on a frame basis, set this parameter to <strong id="b61474620165625"><a name="b61474620165625"></a><a name="b61474620165625"></a>0</strong> for AAC streams. </td>
</tr>
<tr id="row238021216165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">flags</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the type of the current buffer memory block. For details, see <a href="MultiMedia_MediaCommon.md#ga6f4847f443de5cdf3641386011335e21">BufferFlags</a>. </td>
</tr>
</tbody>
</table>

## SetParameters\(\)<a name="ga29f8c86744bda61f84920654c5f40df0"></a>

```
virtual void OHOS::Media::StreamCallback::SetParameters (const [Format](OHOS-Media-Format.md) & params)
```

 **Description:**

Sets additional information about a stream. 

**Parameters:**

<a name="table1245157560165625"></a>
<table><thead align="left"><tr id="row950587932165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1880531686165625"><a name="p1880531686165625"></a><a name="p1880531686165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1749560248165625"><a name="p1749560248165625"></a><a name="p1749560248165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1667430863165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">params</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the parameters for additional stream information. For details, see <a href="OHOS-Media-Format.md">Format</a>. </td>
</tr>
</tbody>
</table>

## SetStreamCallback\(\)<a name="ga078516891396a86226c945e02c79c1f5"></a>

```
virtual void OHOS::Media::StreamSource::SetStreamCallback (const std::shared_ptr< [StreamCallback](OHOS-Media-StreamCallback.md) > & callback)
```

 **Description:**

Sets a callback function for your application. 

**Parameters:**

<a name="table345276866165625"></a>
<table><thead align="left"><tr id="row1293210644165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p933527872165625"><a name="p933527872165625"></a><a name="p933527872165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2097052016165625"><a name="p2097052016165625"></a><a name="p2097052016165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2062479869165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">callback</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the <a href="OHOS-Media-StreamCallback.md">StreamCallback</a> function to set. </td>
</tr>
</tbody>
</table>

## SetValue\(\) \[1/5\]<a name="gacbbf1dca947de8bce2e1a323a1c2664a"></a>

```
bool OHOS::Media::FormatData::SetValue (const std::string & val)
```

 **Description:**

Sets a string. 

**Parameters:**

<a name="table1149006861165625"></a>
<table><thead align="left"><tr id="row1266747360165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1395838724165625"><a name="p1395838724165625"></a><a name="p1395838724165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p44134346165625"><a name="p44134346165625"></a><a name="p44134346165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1774019275165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">val</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the string to set. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **true**  if the setting is successful; returns  **false**  otherwise. 

## SetValue\(\) \[2/5\]<a name="ga5e9360adeb46e7b147757ca22c65c268"></a>

```
bool OHOS::Media::FormatData::SetValue (double val)
```

 **Description:**

Sets a double-precision floating-point number. 

**Parameters:**

<a name="table422191879165625"></a>
<table><thead align="left"><tr id="row573243094165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1900806995165625"><a name="p1900806995165625"></a><a name="p1900806995165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p978380023165625"><a name="p978380023165625"></a><a name="p978380023165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row305855275165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">val</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double-precision floating-point number to set. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **true**  if the double-precision floating-point number is successfully set; returns  **false**  otherwise. 

## SetValue\(\) \[3/5\]<a name="gaa5ca8643885118cd0b3668d5497a90da"></a>

```
bool OHOS::Media::FormatData::SetValue (float val)
```

 **Description:**

Sets a single-precision floating-point number. 

**Parameters:**

<a name="table333165861165625"></a>
<table><thead align="left"><tr id="row1149377367165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2048636745165625"><a name="p2048636745165625"></a><a name="p2048636745165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p603446043165625"><a name="p603446043165625"></a><a name="p603446043165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row935917007165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">val</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the single-precision floating-point number to set. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **true**  if the setting is successful; returns  **false**  otherwise. 

## SetValue\(\) \[4/5\]<a name="gaa1a80e9075010faca14c5c71855efe2d"></a>

```
bool OHOS::Media::FormatData::SetValue (int32_t val)
```

 **Description:**

Sets a 32-bit integer. 

**Parameters:**

<a name="table1793455439165625"></a>
<table><thead align="left"><tr id="row958832280165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p670474482165625"><a name="p670474482165625"></a><a name="p670474482165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1391775794165625"><a name="p1391775794165625"></a><a name="p1391775794165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row836789149165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">val</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the 32-bit integer to set. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **true**  if the setting is successful; returns  **false**  otherwise. 

## SetValue\(\) \[5/5\]<a name="gabb73fee1739b96b402a430f7879b2ca6"></a>

```
bool OHOS::Media::FormatData::SetValue (int64_t val)
```

 **Description:**

Sets a 64-bit long integer. 

**Parameters:**

<a name="table1273547987165625"></a>
<table><thead align="left"><tr id="row674334257165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p184999078165625"><a name="p184999078165625"></a><a name="p184999078165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p564580435165625"><a name="p564580435165625"></a><a name="p564580435165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row413487852165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">val</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the 64-bit long integer to set. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **true**  if the setting is successful; returns  **false**  otherwise. 

## Source\(\) \[1/2\]<a name="gae3640fec3bb0f33f4076dc30e88dac61"></a>

```
OHOS::Media::Source::Source (const std::shared_ptr< [StreamSource](OHOS-Media-StreamSource.md) > & stream, const [Format](OHOS-Media-Format.md) & formats )
```

 **Description:**

A constructor used to create a  [Source](OHOS-Media-Source.md)  instance based on the stream source and format information. 

**Parameters:**

<a name="table1075248601165625"></a>
<table><thead align="left"><tr id="row1218287965165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1454837515165625"><a name="p1454837515165625"></a><a name="p1454837515165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1396600828165625"><a name="p1396600828165625"></a><a name="p1396600828165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row15984663165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">stream</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the media source stream. For details, see <a href="OHOS-Media-StreamSource.md">StreamSource</a>. </td>
</tr>
<tr id="row1039462091165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">formats</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates stream data information, which is subject to the stream type. For example, the key is <strong id="b840595713165625"><a name="b840595713165625"></a><a name="b840595713165625"></a>CODEC_MIME</strong>, and the value is <strong id="b190591374165625"><a name="b190591374165625"></a><a name="b190591374165625"></a>MIME_AUDIO_AAC</strong>. For details, see <a href="OHOS-Media-Format.md">Format</a>. This parameter can be null if no information needs to be passed. </td>
</tr>
</tbody>
</table>

## Source\(\) \[2/2\]<a name="gab9bfa209ae382e3ba5d5242e8dfe5b20"></a>

```
OHOS::Media::Source::Source (const std::string & uri)
```

 **Description:**

A constructor used to create a  [Source](OHOS-Media-Source.md)  instance based on a specified URI. 

**Parameters:**

<a name="table1466417422165625"></a>
<table><thead align="left"><tr id="row1817866800165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p147685424165625"><a name="p147685424165625"></a><a name="p147685424165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p90731961165625"><a name="p90731961165625"></a><a name="p90731961165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2133672545165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">uri</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the media source URI, which can be a network URI or local file path. </td>
</tr>
</tbody>
</table>

## **Variable **<a name="section357746916165625"></a>

## BITRATE\_MODE\_CBR<a name="gaec6a6f6857ff914973ae8dbd6d24435d"></a>

```
const int BITRATE_MODE_CBR = 2
```

 **Description:**

Indicates the constant bit rate mode. In this mode, the codec keeps the output bit rate as constant as possible. 

## BITRATE\_MODE\_CQ<a name="gaa1ea5c3322d75d18fbff0422b758d602"></a>

```
const int BITRATE_MODE_CQ = 0
```

 **Description:**

Indicates the constant quality mode. In this mode, the bit rate is not limited to guarantee the image quality to the largest extent. 

## BITRATE\_MODE\_VBR<a name="gad5d276721fde992fff0b3302a6d2c1dc"></a>

```
const int BITRATE_MODE_VBR = 1
```

 **Description:**

Indicates the variable bit rate mode. In this mode, the codec dynamically adjusts the output bit rate based on the image complexity. The codec increases the bit rate if the image is complex and decreases the bit rate if the image is simple. 

## CODEC\_MIME<a name="ga1b77959b9e9bb70ec3f3a85ddba29f81"></a>

```
const char* OHOS::Media::CODEC_MIME
```

 **Description:**

Indicates the key representing the codec type. 

## COLOR\_FORMAT\_ARGB8888\_32BIT<a name="gaf8f714899f0b11248ea310f8b682ca52"></a>

```
const int32_t COLOR_FORMAT_ARGB8888_32BIT = 16
```

 **Description:**

Indicates the ARGB8888 color format. 

## COLOR\_FORMAT\_YUV420SP<a name="ga4a599efd2466cfef88ed7c8332341f28"></a>

```
const int32_t COLOR_FORMAT_YUV420SP = 21
```

 **Description:**

Indicates the YUV420SP color format. 

## deviceId<a name="gae354490defc2b40c8aeb7b98700cbbd0"></a>

```
uint32_t AudioDeviceDesc::deviceId
```

 **Description:**

Bits 31-24: reserved bits; bits 23-16: mode ID; bits 15-8: device ID; bits 7-0: channel ID 

## deviceName<a name="gaa24e76abf7ecc4088c6888128109d3e8"></a>

```
std::string AudioDeviceDesc::deviceName
```

 **Description:**

Device name 

## ERR\_EARLY\_PREPARE<a name="ga780504ecfc7b140c8fcac6000d21d2cc"></a>

```
const int32_t OHOS::Media::ERR_EARLY_PREPARE = BASE_MEDIA_ERR_OFFSET + 3
```

 **Description:**

Early media preparation 

## ERR\_ILLEGAL\_STATE<a name="ga7d62e4ebba157bb7891397f67686da20"></a>

```
const int32_t OHOS::Media::ERR_ILLEGAL_STATE = BASE_MEDIA_ERR_OFFSET + 1
```

 **Description:**

Status error 

## ERR\_INVALID\_OPERATION<a name="gaea6d0afbc7c159296297185d13289c45"></a>

```
const int32_t OHOS::Media::ERR_INVALID_OPERATION = BASE_MEDIA_ERR_OFFSET + 5
```

 **Description:**

Invalid operation 

## ERR\_INVALID\_PARAM<a name="gab54ceb09402da2ac1bec5e93a95dd5a2"></a>

```
const int32_t OHOS::Media::ERR_INVALID_PARAM = BASE_MEDIA_ERR_OFFSET + 2
```

 **Description:**

Invalid parameter 

## ERR\_INVALID\_READ<a name="gaa3475307553e2de4dd7ef799bdc98c14"></a>

```
const int32_t OHOS::Media::ERR_INVALID_READ = -1
```

 **Description:**

Invalid data size that has been read 

## ERR\_NOFREE\_CHANNEL<a name="ga59c64e4fd1f5890b84e263cb8f1b4a86"></a>

```
const int32_t OHOS::Media::ERR_NOFREE_CHANNEL = BASE_MEDIA_ERR_OFFSET + 6
```

 **Description:**

No idle channel 

## ERR\_NOT\_STARTED<a name="ga09c48c16cb88d0f8860fb7bded0d1369"></a>

```
const int32_t OHOS::Media::ERR_NOT_STARTED = BASE_MEDIA_ERR_OFFSET + 8
```

 **Description:**

Device not started 

## ERR\_READ\_BUFFER<a name="ga93ac3a083852a72b74871883236586ca"></a>

```
const int32_t OHOS::Media::ERR_READ_BUFFER = BASE_MEDIA_ERR_OFFSET + 7
```

 **Description:**

Buffer reading failed 

## ERR\_SOURCE\_NOT\_SET<a name="gafad29c0ac3ef7729944bb907c9abc139"></a>

```
const int32_t OHOS::Media::ERR_SOURCE_NOT_SET = BASE_MEDIA_ERR_OFFSET + 4
```

 **Description:**

No media source 

## ERR\_UNKNOWN<a name="gaac1feac62b2f5501fb7ea1903c9f2cfc"></a>

```
const int32_t OHOS::Media::ERR_UNKNOWN = BASE_MEDIA_ERR_OFFSET + 200
```

 **Description:**

Unknown error 

## ERROR<a name="ga9881ac3b69915a2e0e9c401759f77952"></a>

```
const int32_t OHOS::Media::ERROR = BASE_MEDIA_ERR_OFFSET
```

 **Description:**

Fail 

## inputSourceType<a name="ga8c4f565aa744ec55a784529a843f853e"></a>

```
[AudioSourceType](MultiMedia_MediaCommon.md#gadc3158e093b995ca7b9b6aa32388ccdd) AudioDeviceDesc::inputSourceType
```

 **Description:**

Type of the audio input source 

## KEY\_IS\_SYNC\_FRAME<a name="gaa0ad827cdc16d18a73f280911c009cf1"></a>

```
const std::string KEY_IS_SYNC_FRAME = "is-sync-frame"
```

 **Description:**

Indicates that the current frame is an Instantaneous Decoder Refresh \(IDR\) frame. 

## KEY\_TIME\_US<a name="gadac31555c0ac0612c9f72356f9eb1685"></a>

```
const std::string KEY_TIME_US = "timeUs"
```

 **Description:**

Indicates the frame timestamp. 

## MIME\_AUDIO\_AAC<a name="ga9cfdd72ca1bf4a012f2307985a37871f"></a>

```
const char* OHOS::Media::MIME_AUDIO_AAC
```

 **Description:**

Indicates the codec for Advanced Audio Coding \(AAC\) streams, which is a value of the codec type key. 

## MIME\_AUDIO\_RAW<a name="ga28a526cce33c93a3c3b797ca94fe03e9"></a>

```
const char* OHOS::Media::MIME_AUDIO_RAW
```

 **Description:**

Indicates the codec for RAW audios \(not supported yet\), which is a value of the codec type key. 

## SUCCESS<a name="gaad1937270d3d6c2012ed0e014bd2dc28"></a>

```
const int32_t OHOS::Media::SUCCESS = 0
```

 **Description:**

Success 

