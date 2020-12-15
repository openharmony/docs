# Codec<a name="ZH-CN_TOPIC_0000001055078087"></a>

-   [Overview](#section1786836669165623)
-   [Summary](#section399828542165623)
-   [Files](#files)
-   [Data Structures](#nested-classes)
-   [Macros](#define-members)
-   [Typedefs](#typedef-members)
-   [Enumerations](#enum-members)
-   [Functions](#func-members)
-   [Details](#section794294671165623)
-   [Enumeration Type](#section1038214150165623)
-   [anonymous enum](#ga6b7b47dd702d9e331586d485013fd1ea)
-   [AllocateBufferMode](#gaeae808d52153b2e33c6815162bbd11e0)
-   [AudioBitRate](#gac8cc627a9912e6a338396a6f19bbba5d)
-   [AudioSampleRate](#gaa0280074adafe6d2581d31f71512b842)
-   [AudioSoundMode](#gacecb40e35c431a27385f7b439fc7a76c)
-   [AvCodecMime](#ga1bee586eafa91dfb60f94ba40fc95faa)
-   [BufferMode](#gacc0fd55192fd9f663121b037b06f41e8)
-   [BufferType](#gadf8e136713c0691010d2bec6ba63e9cf)
-   [CapsMask](#gae5751aa8514dcaf2217df12db5ef57a1)
-   [CodecType](#ga03b4b6ae5fb82af68d46aaea3d3e4d79)
-   [DirectionType](#ga8ef30fa9c08e08c8706653571f9f5b81)
-   [EventType](#ga2628ea8d12e8b2563c32f05dc7fff6fa)
-   [Level](#ga221b779e6bb7b8d40677d7642bfefac5)
-   [ParamKey](#ga575c56a2d6b42c48881cf47b0008d5a6)
-   [PicSize](#ga94981b885085085ed5f9dea406519b48)
-   [PixelFormat](#ga60883d4958a60b91661e97027a85072a)
-   [Profile](#ga85b10143618f300ff4f5bc6d45c72c01)
-   [StreamFlagType](#ga8a15793172118d64d8adeba0c8544e84)
-   [VenCodeGopMode](#ga9532f651a003219a262c440f5621d129)
-   [VenCodeRcMode](#ga94267d7ba495136561e1c65686b240f7)
-   [VideoField](#ga1420ddfb066b941fb55a153b869d9ccf)
-   [Function](#section106240538165623)
-   [CodecCreate\(\)](#ga74aa0395a51f004390f7a92fb68faddd)
-   [CodecDeinit\(\)](#ga2d6eb231ca7766990cfa8c1841637245)
-   [CodecDequeInput\(\)](#ga91d7e1566c90d7cb9ac846eecad0024f)
-   [CodecDequeueOutput\(\)](#gab575752467517eb8e6766773c1e3fb23)
-   [CodecDestroy\(\)](#ga1bc0592b05e4f687e2bef2ffb83102b8)
-   [CodecEnumerateCapbility\(\)](#gaf0bb69d2f8c5ad0fec6959b353ee1acd)
-   [CodecFlush\(\)](#gaa6ed6c24e29f8fdfbbb0a3d562260a6a)
-   [CodecGetCapbility\(\)](#ga1a6fbf6e84e01fdc1af59caa4203ce8e)
-   [CodecGetParameter\(\)](#ga1d812eac032e3e05cf5bf71b03e93f65)
-   [CodecInit\(\)](#gadb2714f1e7a69419cefd38a2ad1f9829)
-   [CodecQueueInput\(\)](#ga0daece8dbf22da84f926761c994819bc)
-   [CodecQueueOutput\(\)](#gac98f3505082c3cb2413d9e95eef9c804)
-   [CodecSetCallback\(\)](#ga28ec6149d05765ee75f4836e0b092406)
-   [CodecSetParameter\(\)](#gaa080cf23aa5f77b30f3b90a026d97cc0)
-   [CodecSetPortMode\(\)](#ga36a994c5f9f4d104aad0c24b5e8cbd37)
-   [CodecStart\(\)](#ga38c1744b0b4be5817ef49556ae665d18)
-   [CodecStop\(\)](#ga8e7913c052c2e45e193fb0aab3f5c7fd)

## **Overview**<a name="section1786836669165623"></a>

**Description:**

Defines codec-related APIs.

including custom data types and functions for initializing audio and video codecs, setting parameters, and controlling and transferring data.

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section399828542165623"></a>

## Files<a name="files"></a>

<a name="table1224029450165623"></a>
<table><thead align="left"><tr id="row1173942437165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p874703051165623"><a name="p874703051165623"></a><a name="p874703051165623"></a>File Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1775056399165623"><a name="p1775056399165623"></a><a name="p1775056399165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row899077050165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p679909182165623"><a name="p679909182165623"></a><a name="p679909182165623"></a><a href="codec_interface-h.md">codec_interface.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p290861306165623"><a name="p290861306165623"></a><a name="p290861306165623"></a>Declares codec-related APIs, including functions for initializing audio and video codecs, setting parameters, and controlling and transferring data.</p>
</td>
</tr>
<tr id="row1388060627165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1423345286165623"><a name="p1423345286165623"></a><a name="p1423345286165623"></a><a href="codec_type-h.md">codec_type.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p70225117165623"><a name="p70225117165623"></a><a name="p70225117165623"></a>Declares custom data types used in API declarations for the Codec module, including the codec types, audio and video parameters, input and output data, and callbacks.</p>
</td>
</tr>
</tbody>
</table>

## Data Structures<a name="nested-classes"></a>

<a name="table1410548073165623"></a>
<table><thead align="left"><tr id="row1175352083165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p521508240165623"><a name="p521508240165623"></a><a name="p521508240165623"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p683738707165623"><a name="p683738707165623"></a><a name="p683738707165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row889472919165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1394918481165623"><a name="p1394918481165623"></a><a name="p1394918481165623"></a><a href="Param.md">Param</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p741061505165623"><a name="p741061505165623"></a><a name="p741061505165623"></a>Describes the dynamic parameter structure, which is mainly used by <a href="Codec.md#ga74aa0395a51f004390f7a92fb68faddd">CodecCreate</a> and <a href="Codec.md#gaa080cf23aa5f77b30f3b90a026d97cc0">CodecSetParameter</a>.</p>
</td>
</tr>
<tr id="row984320186165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p587589736165623"><a name="p587589736165623"></a><a name="p587589736165623"></a><a href="BufferHandle.md">BufferHandle</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p498425962165623"><a name="p498425962165623"></a><a name="p498425962165623"></a>Defines the buffer handle type. The virtual address of a handle maps to its physical address.</p>
</td>
</tr>
<tr id="row1050875266165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1708470727165623"><a name="p1708470727165623"></a><a name="p1708470727165623"></a><a href="CodecBufferInfo.md">CodecBufferInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p339575376165623"><a name="p339575376165623"></a><a name="p339575376165623"></a>Describes buffer information.</p>
</td>
</tr>
<tr id="row2049837784165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p201446349165623"><a name="p201446349165623"></a><a name="p201446349165623"></a><a href="InputInfo.md">InputInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1231262811165623"><a name="p1231262811165623"></a><a name="p1231262811165623"></a>Describes input information.</p>
</td>
</tr>
<tr id="row1453119470165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1031950419165623"><a name="p1031950419165623"></a><a name="p1031950419165623"></a><a href="OutputInfo.md">OutputInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1244003426165623"><a name="p1244003426165623"></a><a name="p1244003426165623"></a>Describes output information.</p>
</td>
</tr>
<tr id="row1723058682165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p929846747165623"><a name="p929846747165623"></a><a name="p929846747165623"></a><a href="ResizableArray.md">ResizableArray</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2034676088165623"><a name="p2034676088165623"></a><a name="p2034676088165623"></a>Defines a variable-length queue.</p>
</td>
</tr>
<tr id="row642750870165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1239541397165623"><a name="p1239541397165623"></a><a name="p1239541397165623"></a><a href="Alginment.md">Alginment</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p610953210165623"><a name="p610953210165623"></a><a name="p610953210165623"></a>Defines the alignment.</p>
</td>
</tr>
<tr id="row869138491165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1773866274165623"><a name="p1773866274165623"></a><a name="p1773866274165623"></a><a href="Rect.md">Rect</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1287592938165623"><a name="p1287592938165623"></a><a name="p1287592938165623"></a>Defines a rectangle.</p>
</td>
</tr>
<tr id="row1874865479165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1082669376165623"><a name="p1082669376165623"></a><a name="p1082669376165623"></a><a href="Capbility.md">Capbility</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1098092358165623"><a name="p1098092358165623"></a><a name="p1098092358165623"></a>Defines the codec capability.</p>
</td>
</tr>
<tr id="row171762641165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p276703319165623"><a name="p276703319165623"></a><a name="p276703319165623"></a><a href="CodecCallback.md">CodecCallback</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p978647472165623"><a name="p978647472165623"></a><a name="p978647472165623"></a>Defines callbacks and their parameters.</p>
</td>
</tr>
</tbody>
</table>

## Macros<a name="define-members"></a>

<a name="table967939438165623"></a>
<table><thead align="left"><tr id="row1043214764165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p281424612165623"><a name="p281424612165623"></a><a name="p281424612165623"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2031759130165623"><a name="p2031759130165623"></a><a name="p2031759130165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1891480546165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1401476298165623"><a name="p1401476298165623"></a><a name="p1401476298165623"></a><em id="gab34cc95c32c06b8d63cfbe62247eb6e2"><a name="gab34cc95c32c06b8d63cfbe62247eb6e2"></a><a name="gab34cc95c32c06b8d63cfbe62247eb6e2"></a></em>ELEMENT_MAX_LEN    50</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p268360044165623"><a name="p268360044165623"></a><a name="p268360044165623"></a>Indicates the maximum number of reserved parameters in the array.</p>
</td>
</tr>
</tbody>
</table>

## Typedefs<a name="typedef-members"></a>

<a name="table1718072631165623"></a>
<table><thead align="left"><tr id="row104832303165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p186269876165623"><a name="p186269876165623"></a><a name="p186269876165623"></a>Typedef Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1187944427165623"><a name="p1187944427165623"></a><a name="p1187944427165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row67125491165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1779737513165623"><a name="p1779737513165623"></a><a name="p1779737513165623"></a>CODEC_HANDLETYPE</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p476353440165623"><a name="p476353440165623"></a><a name="p476353440165623"></a><strong id="ga9381a619f36ac8d5d7f467d2f0404183"><a name="ga9381a619f36ac8d5d7f467d2f0404183"></a><a name="ga9381a619f36ac8d5d7f467d2f0404183"></a></strong> typedef void *</p>
<p id="p1533106972165623"><a name="p1533106972165623"></a><a name="p1533106972165623"></a>Defines the pointer to the codec handle, which is the context information for function calls.</p>
</td>
</tr>
<tr id="row592545115165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p580094910165623"><a name="p580094910165623"></a><a name="p580094910165623"></a>ValueType</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1085803424165623"><a name="p1085803424165623"></a><a name="p1085803424165623"></a><strong id="gadfdccaf7fd554ae1df6169bb622deb1d"><a name="gadfdccaf7fd554ae1df6169bb622deb1d"></a><a name="gadfdccaf7fd554ae1df6169bb622deb1d"></a></strong> typedef void *</p>
<p id="p1893865406165623"><a name="p1893865406165623"></a><a name="p1893865406165623"></a>Defines the pointer to the type of the dynamic parameter value.</p>
</td>
</tr>
<tr id="row1271379021165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1691749785165623"><a name="p1691749785165623"></a><a name="p1691749785165623"></a>BufferHandle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p348109046165623"><a name="p348109046165623"></a><a name="p348109046165623"></a><strong id="ga5571ad9c720096768c508f1f38e2ef41"><a name="ga5571ad9c720096768c508f1f38e2ef41"></a><a name="ga5571ad9c720096768c508f1f38e2ef41"></a></strong> typedef struct <a href="BufferHandle.md">BufferHandle</a></p>
<p id="p1562378327165623"><a name="p1562378327165623"></a><a name="p1562378327165623"></a>Defines the buffer handle type. The virtual address of a handle maps to its physical address.</p>
</td>
</tr>
<tr id="row1065352025165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p576380277165623"><a name="p576380277165623"></a><a name="p576380277165623"></a>BufferType</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p471028559165623"><a name="p471028559165623"></a><a name="p471028559165623"></a><strong id="ga8dc4e7c329ad589f25019ca03aed9925"><a name="ga8dc4e7c329ad589f25019ca03aed9925"></a><a name="ga8dc4e7c329ad589f25019ca03aed9925"></a></strong> typedef enum <a href="Codec.md#gadf8e136713c0691010d2bec6ba63e9cf">BufferType</a></p>
<p id="p2049803804165623"><a name="p2049803804165623"></a><a name="p2049803804165623"></a>Enumerates buffer types.</p>
</td>
</tr>
<tr id="row21952967165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2120188627165623"><a name="p2120188627165623"></a><a name="p2120188627165623"></a>OutputInfo</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p160610748165623"><a name="p160610748165623"></a><a name="p160610748165623"></a><strong id="gab32442ed7057b2e9bd6b20ad35154cb8"><a name="gab32442ed7057b2e9bd6b20ad35154cb8"></a><a name="gab32442ed7057b2e9bd6b20ad35154cb8"></a></strong> typedef struct <a href="OutputInfo.md">OutputInfo</a></p>
<p id="p362378064165623"><a name="p362378064165623"></a><a name="p362378064165623"></a>Describes output information.</p>
</td>
</tr>
<tr id="row296101214165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1721424738165623"><a name="p1721424738165623"></a><a name="p1721424738165623"></a>AllocateBufferMode</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1263992650165623"><a name="p1263992650165623"></a><a name="p1263992650165623"></a><strong id="gaf59a3505491b6f0b5dff5d62372a9679"><a name="gaf59a3505491b6f0b5dff5d62372a9679"></a><a name="gaf59a3505491b6f0b5dff5d62372a9679"></a></strong> typedef enum <a href="Codec.md#gaeae808d52153b2e33c6815162bbd11e0">AllocateBufferMode</a></p>
<p id="p445713673165623"><a name="p445713673165623"></a><a name="p445713673165623"></a>Enumerates allocation modes of input and output buffers.</p>
</td>
</tr>
<tr id="row1721448325165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p400303782165623"><a name="p400303782165623"></a><a name="p400303782165623"></a>CapsMask</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1965048291165623"><a name="p1965048291165623"></a><a name="p1965048291165623"></a><strong id="ga09af5b0a9d5134ad4d44cbe8cbe7b887"><a name="ga09af5b0a9d5134ad4d44cbe8cbe7b887"></a><a name="ga09af5b0a9d5134ad4d44cbe8cbe7b887"></a></strong> typedef enum <a href="Codec.md#gae5751aa8514dcaf2217df12db5ef57a1">CapsMask</a></p>
<p id="p902959785165623"><a name="p902959785165623"></a><a name="p902959785165623"></a>Enumerates playback capabilities.</p>
</td>
</tr>
<tr id="row24560192165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1389320045165623"><a name="p1389320045165623"></a><a name="p1389320045165623"></a>CodecCapbility</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p729394122165623"><a name="p729394122165623"></a><a name="p729394122165623"></a><strong id="ga1876710b1f2fe1d80e8b9de9ff28e0e3"><a name="ga1876710b1f2fe1d80e8b9de9ff28e0e3"></a><a name="ga1876710b1f2fe1d80e8b9de9ff28e0e3"></a></strong> typedef struct <a href="Capbility.md">Capbility</a></p>
<p id="p1352246449165623"><a name="p1352246449165623"></a><a name="p1352246449165623"></a>Defines the codec capability.</p>
</td>
</tr>
<tr id="row955783201165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p920214055165623"><a name="p920214055165623"></a><a name="p920214055165623"></a>UINTPTR</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p50710902165623"><a name="p50710902165623"></a><a name="p50710902165623"></a><strong id="ga58d2f4a8d12daa1dcf4eb297f3ebaabc"><a name="ga58d2f4a8d12daa1dcf4eb297f3ebaabc"></a><a name="ga58d2f4a8d12daa1dcf4eb297f3ebaabc"></a></strong> typedef uintptr_t</p>
<p id="p236858234165623"><a name="p236858234165623"></a><a name="p236858234165623"></a>Redefines the unsigned pointer type, which is used for pointer conversion.</p>
</td>
</tr>
</tbody>
</table>

## Enumerations<a name="enum-members"></a>

<a name="table503488777165623"></a>
<table><thead align="left"><tr id="row1240111324165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p508421802165623"><a name="p508421802165623"></a><a name="p508421802165623"></a>Enumeration Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1191004841165623"><a name="p1191004841165623"></a><a name="p1191004841165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row546627340165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p521448337165623"><a name="p521448337165623"></a><a name="p521448337165623"></a><a href="Codec.md#ga03b4b6ae5fb82af68d46aaea3d3e4d79">CodecType</a> {   <a href="Codec.md#gga03b4b6ae5fb82af68d46aaea3d3e4d79a19c3c7765c55583a64e21938e2439261">VIDEO_DECODER</a>, <a href="Codec.md#gga03b4b6ae5fb82af68d46aaea3d3e4d79ad8044bc5b7d871723be90b5b6a094992">VIDEO_ENCODER</a>, <a href="Codec.md#gga03b4b6ae5fb82af68d46aaea3d3e4d79ae4ade329585f6c202847138e3f9cd4a4">AUDIO_DECODER</a>, <a href="Codec.md#gga03b4b6ae5fb82af68d46aaea3d3e4d79a7f7f3d3880168089c1de6d1ebc3dbb54">AUDIO_ENCODER</a>,   <a href="Codec.md#gga03b4b6ae5fb82af68d46aaea3d3e4d79a7314b0d0e4638eaaeb8690b8555a6546">INVALID_TYPE</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p528556848165623"><a name="p528556848165623"></a><a name="p528556848165623"></a>Enumerates codec types.</p>
</td>
</tr>
<tr id="row703847892165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p630075269165623"><a name="p630075269165623"></a><a name="p630075269165623"></a><a href="Codec.md#ga575c56a2d6b42c48881cf47b0008d5a6">ParamKey</a> {   <a href="Codec.md#gga575c56a2d6b42c48881cf47b0008d5a6aef2a08e0112230b41df402fd38efc1ed">KEY_MIMETYPE</a> = 0x01, <a href="Codec.md#gga575c56a2d6b42c48881cf47b0008d5a6a2c86d69eb4995dbadfdb6d289834f7f2">KEY_BUFFERSIZE</a>, <a href="Codec.md#gga575c56a2d6b42c48881cf47b0008d5a6a4c97de4e44d3c9778530ddd2cffe1728">KEY_LEFT_STREAM_FRAMES</a>, <a href="Codec.md#gga575c56a2d6b42c48881cf47b0008d5a6ac3e2aece8c07c078567996464d654e5a">KEY_CODEC_TYPE</a>,   <a href="Codec.md#gga575c56a2d6b42c48881cf47b0008d5a6ac1ff343954a9a979fd49bf6ef80d2589">KEY_DIRECTION_TYPE</a>, <a href="Codec.md#gga575c56a2d6b42c48881cf47b0008d5a6ad8c37ded7037d0e1eeb6e477ff72492f">KEY_BITRATE</a> = 0x500, <a href="Codec.md#gga575c56a2d6b42c48881cf47b0008d5a6adab65ac6751535b13f6275dbfa1ba90e">KEY_WIDTH</a> = 0x1000, <a href="Codec.md#gga575c56a2d6b42c48881cf47b0008d5a6a78fd0c2ba5fb7894ec4a164ff2b119b8">KEY_HEIGHT</a>,   <a href="Codec.md#gga575c56a2d6b42c48881cf47b0008d5a6ad25b08a51da92cb8928402bd2a99ec60">KEY_STRIDE</a>, <a href="Codec.md#gga575c56a2d6b42c48881cf47b0008d5a6ae45fd20d699c2a40110d510c26e2b0bb">KEY_VIDEO_FIELD</a>, <a href="Codec.md#gga575c56a2d6b42c48881cf47b0008d5a6a8b4fdf85f17f5bb549236a6280e36328">KEY_PIXEL_FORMAT</a>, <a href="Codec.md#gga575c56a2d6b42c48881cf47b0008d5a6abed5c9737ae85a1771f6d065692fdab1">KEY_VIDEO_RC_MODE</a>,   <a href="Codec.md#gga575c56a2d6b42c48881cf47b0008d5a6aae6cd2e1f70f313300e8579d2c6befbc">KEY_VIDEO_GOP_MODE</a>, <a href="Codec.md#gga575c56a2d6b42c48881cf47b0008d5a6a19a23598acca8b0d1dfa8bb48f58a7ef">KEY_VIDEO_PIC_SIZE</a>, <a href="Codec.md#gga575c56a2d6b42c48881cf47b0008d5a6ab05b2fdf7c66accbce8bd4c5689dbe31">KEY_VIDEO_PROFILE</a>, <a href="Codec.md#gga575c56a2d6b42c48881cf47b0008d5a6acdfdfbe59769faa9eb22c7fabf99ab77">KEY_VIDEO_FRAME_RATE</a>,   <a href="Codec.md#gga575c56a2d6b42c48881cf47b0008d5a6aa4b816f352799fbbbe85f3c5d91640ff">KEY_IMAGE_Q_FACTOR</a>, <a href="Codec.md#gga575c56a2d6b42c48881cf47b0008d5a6a513f3e7cbf10667949bd2f276b43227e">KEY_SAMPLE_RATE</a> = 0x1500, <a href="Codec.md#gga575c56a2d6b42c48881cf47b0008d5a6a1a00600fff0e7a378bc0c690451f1040">KEY_AUDIO_PROFILE</a>, <a href="Codec.md#gga575c56a2d6b42c48881cf47b0008d5a6a8c791931da4303642db329af0bb383a8">KEY_CHANNEL_COUNT</a>,   <a href="Codec.md#gga575c56a2d6b42c48881cf47b0008d5a6ae054dfca35dd75e795aa9af83390a4fd">KEY_BITWITH</a>, <a href="Codec.md#gga575c56a2d6b42c48881cf47b0008d5a6ade681ad9e4e270d52ed2127dc86a90c7">KEY_SOUND_MODE</a>, <a href="Codec.md#gga575c56a2d6b42c48881cf47b0008d5a6ab6ca06e65b7ee9808e07389507555b48">KEY_POINT_NUM_PER_FRAME</a>, <a href="Codec.md#gga575c56a2d6b42c48881cf47b0008d5a6a15bf33195ec3c6067084aa3fa047cad2">KEY_DEVICE_ID</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1841381550165623"><a name="p1841381550165623"></a><a name="p1841381550165623"></a>Enumerates indexes of parameter types.</p>
</td>
</tr>
<tr id="row1185096901165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1938958974165623"><a name="p1938958974165623"></a><a name="p1938958974165623"></a><a href="Codec.md#ga94267d7ba495136561e1c65686b240f7">VenCodeRcMode</a> {   <a href="Codec.md#gga94267d7ba495136561e1c65686b240f7af65e058f6076a39b864a5e5351c508a8">VENCOD_RC_CBR</a> = 0, <a href="Codec.md#gga94267d7ba495136561e1c65686b240f7ad40974ef1c63cc0fcef1106a69dc696a">VENCOD_RC_VBR</a>, <a href="Codec.md#gga94267d7ba495136561e1c65686b240f7ae4e2d1f85e783430a12ad412edf21ddc">VENCOD_RC_AVBR</a>, <a href="Codec.md#gga94267d7ba495136561e1c65686b240f7aa3294f73cd0cd078618ef9db4d3cb6f5">VENCOD_RC_QVBR</a>,   <a href="Codec.md#gga94267d7ba495136561e1c65686b240f7ad43d98e7b3b42efa4cc6d4d1a2298024">VENCOD_RC_CVBR</a>, <a href="Codec.md#gga94267d7ba495136561e1c65686b240f7a3e89e3affbe63967e5cdfc3b162d8ac9">VENCOD_RC_QPMAP</a>, <a href="Codec.md#gga94267d7ba495136561e1c65686b240f7ae9a1e0b19d79f1c2bdada4c5830e2584">VENCOD_RC_FIXQP</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1700095177165623"><a name="p1700095177165623"></a><a name="p1700095177165623"></a>Enumerates control modes of the channel encoding rate.</p>
</td>
</tr>
<tr id="row487528559165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p274045681165623"><a name="p274045681165623"></a><a name="p274045681165623"></a><a href="Codec.md#ga94981b885085085ed5f9dea406519b48">PicSize</a> {   <a href="Codec.md#gga94981b885085085ed5f9dea406519b48a373065e30654b1d097cb9725bec88962">Resolution_CIF</a>, <a href="Codec.md#gga94981b885085085ed5f9dea406519b48af6b390500e92b07d1c8829c7ce13fc9b">Resolution_360P</a>, <a href="Codec.md#gga94981b885085085ed5f9dea406519b48a7662d5257ffca575be7f343015f3e6ab">Resolution_D1_PAL</a>, <a href="Codec.md#gga94981b885085085ed5f9dea406519b48ae2644966a8e6b6595f90bc950fa9673d">Resolution_D1_NTSC</a>,   <a href="Codec.md#gga94981b885085085ed5f9dea406519b48ae6d83a5bdf1b754df6dc23b07d781a5e">Resolution_720P</a>, <a href="Codec.md#gga94981b885085085ed5f9dea406519b48a460ffc02a1f90e6194fca5f1fcfb513b">Resolution_1080P</a>, <a href="Codec.md#gga94981b885085085ed5f9dea406519b48ae26dfcd8b806ea2ec7236f5a43dba1a2">Resolution_INVALID</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p475973071165623"><a name="p475973071165623"></a><a name="p475973071165623"></a>Enumerates resolutions.</p>
</td>
</tr>
<tr id="row1432051413165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p468309582165623"><a name="p468309582165623"></a><a name="p468309582165623"></a><a href="Codec.md#ga9532f651a003219a262c440f5621d129">VenCodeGopMode</a> {   <a href="Codec.md#gga9532f651a003219a262c440f5621d129a1f3b41538fdbdbb9f920f740f89c7c95">VENCOD_GOPMODE_NORMALP</a> = 0, <a href="Codec.md#gga9532f651a003219a262c440f5621d129a6b063f65ef8ec77e360bbbd56c7b233f">VENCOD_GOPMODE_DUALP</a> = 1, <a href="Codec.md#gga9532f651a003219a262c440f5621d129a37226f50b4e07586d8bd8e22114e2324">VENCOD_GOPMODE_SMARTP</a> = 2, <a href="Codec.md#gga9532f651a003219a262c440f5621d129a8caa9e9fae7ca1d041ccb163bbcf92c6">VENCOD_GOPMODE_ADVSMARTP</a> = 3,   <a href="Codec.md#gga9532f651a003219a262c440f5621d129a7a120c500828b79e7a87e4f8a9d4378c">VENCOD_GOPMODE_BIPREDB</a> = 4, <a href="Codec.md#gga9532f651a003219a262c440f5621d129ae02038b7e71cb65c991676da17a11a73">VENCOD_GOPMODE_LOWDELAYB</a> = 5, <a href="Codec.md#gga9532f651a003219a262c440f5621d129a6b54943891a852da1b3e37cac4893b55">VENCOD_GOPMODE_INVALID</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p264534961165623"><a name="p264534961165623"></a><a name="p264534961165623"></a>Enumerates types of group of pictures (GOP).</p>
</td>
</tr>
<tr id="row508332528165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p635569408165623"><a name="p635569408165623"></a><a name="p635569408165623"></a><a href="Codec.md#ga1420ddfb066b941fb55a153b869d9ccf">VideoField</a> {   <a href="Codec.md#gga1420ddfb066b941fb55a153b869d9ccfadf9934801550e7c45e395d8e4704aff9">VID_FIELD_TOP</a> = 0x1, <a href="Codec.md#gga1420ddfb066b941fb55a153b869d9ccfa3de04ce552cc5a52d977256efed8611a">VID_FIELD_BOTTOM</a> = 0x2, <a href="Codec.md#gga1420ddfb066b941fb55a153b869d9ccfa9c3bffc837d46ece68154c98bfc4c303">VID_FIELD_INTERLACED</a> = 0x3, <a href="Codec.md#gga1420ddfb066b941fb55a153b869d9ccfaaf092a3bb1b706a47a425e7eff683526">VID_FIELD_FRAME</a> = 0x4,   <a href="Codec.md#gga1420ddfb066b941fb55a153b869d9ccfaedd6cdcd59983317521c2ac717884405">VID_FIELD_INVALID</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1816185919165623"><a name="p1816185919165623"></a><a name="p1816185919165623"></a>Enumerates video frame fields.</p>
</td>
</tr>
<tr id="row190744813165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p990211022165623"><a name="p990211022165623"></a><a name="p990211022165623"></a><a href="Codec.md#ga60883d4958a60b91661e97027a85072a">PixelFormat</a> {   <a href="#entry64317691165623p0">YVU_SEMIPLANAR_420</a> = 0, <a href="#entry1690581398165623p0">YVU_SEMIPLANAR_420_TILE</a>, <a href="#entry937265294165623p0">PIX_FORMAT_INVALID</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1491839167165623"><a name="p1491839167165623"></a><a name="p1491839167165623"></a>Enumerates pixel formats.</p>
</td>
</tr>
<tr id="row1624522694165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1219054802165623"><a name="p1219054802165623"></a><a name="p1219054802165623"></a><a href="Codec.md#gacecb40e35c431a27385f7b439fc7a76c">AudioSoundMode</a> { <a href="Codec.md#ggacecb40e35c431a27385f7b439fc7a76caef98cd29f4639de89778f1be521a1676">AUD_SOUND_MODE_MONO</a> = 0, <a href="Codec.md#ggacecb40e35c431a27385f7b439fc7a76ca9437f9e5186f7095fb50775eddc439d6">AUD_SOUND_MODE_STEREO</a> = 1, <a href="Codec.md#ggacecb40e35c431a27385f7b439fc7a76ca53160e7e334a8629bec602c42d2ee5e6">AUD_SOUND_MODE_INVALID</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p414188019165623"><a name="p414188019165623"></a><a name="p414188019165623"></a>Enumerates audio channel modes.</p>
</td>
</tr>
<tr id="row1532097781165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1797378054165623"><a name="p1797378054165623"></a><a name="p1797378054165623"></a><a href="Codec.md#gaa0280074adafe6d2581d31f71512b842">AudioSampleRate</a> {   <a href="Codec.md#ggaa0280074adafe6d2581d31f71512b842a65d5a1e4d1f048a33d29c9a3b6f540bd">AUD_SAMPLE_RATE_8000</a> = 8000, <a href="Codec.md#ggaa0280074adafe6d2581d31f71512b842ac8379e14b05cdac5edfcc931ac8b33a9">AUD_SAMPLE_RATE_12000</a> = 12000, <a href="Codec.md#ggaa0280074adafe6d2581d31f71512b842a57b1853b1e309bf1aa5b3a35b06b0f81">AUD_SAMPLE_RATE_11025</a> = 11025, <a href="Codec.md#ggaa0280074adafe6d2581d31f71512b842a43395f0fe94ae2949778468e4488c3ee">AUD_SAMPLE_RATE_16000</a> = 16000,   <a href="Codec.md#ggaa0280074adafe6d2581d31f71512b842a5e8155ecfa865686a66e004e37ce1e54">AUD_SAMPLE_RATE_22050</a> = 22050, <a href="Codec.md#ggaa0280074adafe6d2581d31f71512b842abd4c09d52f3da25adb108e9aa503119d">AUD_SAMPLE_RATE_24000</a> = 24000, <a href="Codec.md#ggaa0280074adafe6d2581d31f71512b842a1f94827fe757ad2857d970638b6f8d66">AUD_SAMPLE_RATE_32000</a> = 32000, <a href="Codec.md#ggaa0280074adafe6d2581d31f71512b842ac880553f2ee154a240d9414598e006a2">AUD_SAMPLE_RATE_44100</a> = 44100,   <a href="Codec.md#ggaa0280074adafe6d2581d31f71512b842ade6dd509c28b66127c42d2634866b89c">AUD_SAMPLE_RATE_48000</a> = 48000, <a href="Codec.md#ggaa0280074adafe6d2581d31f71512b842a925218c15bb8522796e623a09d99dbc3">AUD_SAMPLE_RATE_64000</a> = 64000, <a href="Codec.md#ggaa0280074adafe6d2581d31f71512b842a48336a808a2ebcf5956995140e2d73dd">AUD_SAMPLE_RATE_96000</a> = 96000, <a href="Codec.md#ggaa0280074adafe6d2581d31f71512b842a0cb82ce52fb70b359a0b2232f7f465a2">AUD_SAMPLE_RATE_INVALID</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p709950877165623"><a name="p709950877165623"></a><a name="p709950877165623"></a>Enumerates audio sampling rates.</p>
</td>
</tr>
<tr id="row1347095546165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p416801013165623"><a name="p416801013165623"></a><a name="p416801013165623"></a><a href="Codec.md#gac8cc627a9912e6a338396a6f19bbba5d">AudioBitRate</a> {   <a href="Codec.md#ggac8cc627a9912e6a338396a6f19bbba5da1b31811befaf84b164684a38fa022f43">AUD_AAC_BPS_8K</a> = 8000, <a href="Codec.md#ggac8cc627a9912e6a338396a6f19bbba5dab71f0668b9fc4955fe059339ea663e8e">AUD_AAC_BPS_16K</a> = 16000, <a href="Codec.md#ggac8cc627a9912e6a338396a6f19bbba5da3cc22f17e3fddb9d081aa3d826d31ac9">AUD_AAC_BPS_22K</a> = 22000, <a href="Codec.md#ggac8cc627a9912e6a338396a6f19bbba5dadb78faf7877b6f70fd9b55406dcbd6b0">AUD_AAC_BPS_24K</a> = 24000,   <a href="Codec.md#ggac8cc627a9912e6a338396a6f19bbba5da974bd8a79bb6004f84b670f2496a33b9">AUD_AAC_BPS_32K</a> = 32000, <a href="Codec.md#ggac8cc627a9912e6a338396a6f19bbba5da7d330b118800e19500f2f4a9b6af38f8">AUD_AAC_BPS_48K</a> = 48000, <a href="Codec.md#ggac8cc627a9912e6a338396a6f19bbba5da2b8757624080a60f39d848dac7820e99">AUD_AAC_BPS_64K</a> = 64000, <a href="Codec.md#ggac8cc627a9912e6a338396a6f19bbba5da5ff13a09a232327578c69159f7564da8">AUD_AAC_BPS_96K</a> = 96000,   <a href="Codec.md#ggac8cc627a9912e6a338396a6f19bbba5da8806920e563eca6c76b225185f24f191">AUD_AAC_BPS_128K</a> = 128000, <a href="Codec.md#ggac8cc627a9912e6a338396a6f19bbba5da7584ca8ebd583c448c5e2ff4957448f7">AUD_AAC_BPS_256K</a> = 256000, <a href="Codec.md#ggac8cc627a9912e6a338396a6f19bbba5dade0faf8053bab953b55bc3e4d20341d5">AUD_AAC_BPS_320K</a> = 320000 }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p497702031165623"><a name="p497702031165623"></a><a name="p497702031165623"></a>Enumerates audio bit rates.</p>
</td>
</tr>
<tr id="row1575948014165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2088839646165623"><a name="p2088839646165623"></a><a name="p2088839646165623"></a><a href="Codec.md#ga8a15793172118d64d8adeba0c8544e84">StreamFlagType</a> {   <a href="Codec.md#gga8a15793172118d64d8adeba0c8544e84ae0da6ed262d36cb4de4b63cd25889ea2">STREAM_FLAG_KEYFRAME</a> = 1, <a href="Codec.md#gga8a15793172118d64d8adeba0c8544e84a9a06fdc891d28272ba6651ca9791d166">STREAM_FLAG_CODEC_SPECIFIC_INF</a> = 2, <a href="Codec.md#gga8a15793172118d64d8adeba0c8544e84abe40ab8f6da71b5a7d6a382954dc5d4f">STREAM_FLAG_EOS</a> = 4, <a href="Codec.md#gga8a15793172118d64d8adeba0c8544e84a7809fe65541dc27f50ba4952685c34bd">STREAM_FLAG_PART_OF_FRAME</a> = 8,   <a href="Codec.md#gga8a15793172118d64d8adeba0c8544e84abb9a3fba052c516ac141e34ea9fa6dca">STREAM_FLAG_END_OF_FRAME</a> = 16 }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1073088047165623"><a name="p1073088047165623"></a><a name="p1073088047165623"></a>Enumerates stream flags.</p>
</td>
</tr>
<tr id="row1028648557165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2116281085165623"><a name="p2116281085165623"></a><a name="p2116281085165623"></a><a href="Codec.md#gadf8e136713c0691010d2bec6ba63e9cf">BufferType</a> { <a href="Codec.md#ggadf8e136713c0691010d2bec6ba63e9cfabc56eeb37d99d582a14b44fb0ef4cabc">BUFFER_TYPE_VIRTUAL</a> = 0, <a href="Codec.md#ggadf8e136713c0691010d2bec6ba63e9cfa4583aeaa2921c629ee785dbee184f421">BUFFER_TYPE_FD</a>, <a href="Codec.md#ggadf8e136713c0691010d2bec6ba63e9cfa4bc0e24b5ce589d284b1771fc27c3d09">BUFFER_TYPE_HANDLE</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1931862712165623"><a name="p1931862712165623"></a><a name="p1931862712165623"></a>Enumerates buffer types.</p>
</td>
</tr>
<tr id="row437945260165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1290219759165623"><a name="p1290219759165623"></a><a name="p1290219759165623"></a><a href="Codec.md#ga1bee586eafa91dfb60f94ba40fc95faa">AvCodecMime</a> {   <a href="Codec.md#gga1bee586eafa91dfb60f94ba40fc95faaa4deff5e22cd5e2e83b6042880ad31863">MEDIA_MIMETYPE_IMAGE_JPEG</a> = 0, <a href="Codec.md#gga1bee586eafa91dfb60f94ba40fc95faaa3db11a46c7f4bb848e6f0604268e41e3">MEDIA_MIMETYPE_VIDEO_AVC</a>, <a href="Codec.md#gga1bee586eafa91dfb60f94ba40fc95faaaaf430209c9262e6fcd5cd8f97dafe614">MEDIA_MIMETYPE_VIDEO_HEVC</a>, <a href="Codec.md#gga1bee586eafa91dfb60f94ba40fc95faaac03eb65aaf7aff393e223346feb30415">MEDIA_MIMETYPE_AUDIO_AAC</a>,   <a href="Codec.md#gga1bee586eafa91dfb60f94ba40fc95faaaa2fa953bd51d8ee18191315c7187fc96">MEDIA_MIMETYPE_INVALID</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p812254614165623"><a name="p812254614165623"></a><a name="p812254614165623"></a>Enumerates MIME types.</p>
</td>
</tr>
<tr id="row1513932714165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1458905562165623"><a name="p1458905562165623"></a><a name="p1458905562165623"></a><a href="Codec.md#ga85b10143618f300ff4f5bc6d45c72c01">Profile</a> {   <a href="Codec.md#gga85b10143618f300ff4f5bc6d45c72c01a6d67944b4958ad33b0eeb851bbcd169f">INVALID_PROFILE</a> = 0, <a href="Codec.md#gga85b10143618f300ff4f5bc6d45c72c01ad91765d6dcad7253a924d3cb30501e44">AAC_LC_PROFILE</a> = 0x1000, <a href="Codec.md#gga85b10143618f300ff4f5bc6d45c72c01aada4d857818cd9aa1ad62cdf608dab6b">AAC_MAIN_PROFILE</a>, <a href="Codec.md#gga85b10143618f300ff4f5bc6d45c72c01ab4255dc0e7450af4f526b85acbabfd3e">AAC_HE_V1_PROFILE</a>,   <a href="Codec.md#gga85b10143618f300ff4f5bc6d45c72c01a9b54f7a8c45ea6d4804133d8de4b8dd8">AAC_HE_V2_PROFILE</a>, <a href="Codec.md#gga85b10143618f300ff4f5bc6d45c72c01afaaacd4f6bdadac28b5cf49ae8f8470a">AAC_LD_PROFILE</a>, <a href="Codec.md#gga85b10143618f300ff4f5bc6d45c72c01a7c8028283d1ff60e486b3305bf8c1adc">AAC_ELD_PROFILE</a>, <a href="Codec.md#gga85b10143618f300ff4f5bc6d45c72c01a5bab002f00d3d7281aedc4807123a47a">AVC_BASELINE_PROFILE</a> = 0x2000,   <a href="Codec.md#gga85b10143618f300ff4f5bc6d45c72c01a323c1d6e02363f1717f7e6b33fd9a646">AVC_MAIN_PROFILE</a>, <a href="Codec.md#gga85b10143618f300ff4f5bc6d45c72c01ab9406e6bf30a0c128c3639cce51fe246">AVC_HIGH_PROFILE</a>, <a href="Codec.md#gga85b10143618f300ff4f5bc6d45c72c01ae0d37dc2c7d39753a80f6e0ba64e5e22">HEVC_MAIN_PROFILE</a> = 0x3000, <a href="Codec.md#gga85b10143618f300ff4f5bc6d45c72c01a811b9e02d8b0afa93e7ab8d2aa7e5de6">HEVC_MAIN_10_PROFILE</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1652116000165623"><a name="p1652116000165623"></a><a name="p1652116000165623"></a>Enumerates codec profiles.</p>
</td>
</tr>
<tr id="row427130939165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2107339599165623"><a name="p2107339599165623"></a><a name="p2107339599165623"></a><a href="Codec.md#ga221b779e6bb7b8d40677d7642bfefac5">Level</a> { <a href="Codec.md#gga221b779e6bb7b8d40677d7642bfefac5a6ab1f388a1a94d680bcbe808ec45a082">INVALID_LEVEL</a> = 0, <a href="Codec.md#gga221b779e6bb7b8d40677d7642bfefac5aee353b803bd93ba9e01e99e67b8afb49">AVC_LEVEL_1</a> = 0x1000, <a href="Codec.md#gga221b779e6bb7b8d40677d7642bfefac5a25819fec0bd7476c85122100b61536bb">HEVC_LEVEL_MAIN_1</a> = 0x2000, <a href="Codec.md#gga221b779e6bb7b8d40677d7642bfefac5ab21d7836b0849b87149b7cdd7924d862">HEVC_LEVEL_MAIN_2</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1872283002165623"><a name="p1872283002165623"></a><a name="p1872283002165623"></a>Enumerates codec levels.</p>
</td>
</tr>
<tr id="row55655678165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1848514372165623"><a name="p1848514372165623"></a><a name="p1848514372165623"></a><a href="Codec.md#gaeae808d52153b2e33c6815162bbd11e0">AllocateBufferMode</a> { <a href="Codec.md#ggaeae808d52153b2e33c6815162bbd11e0ae8110d24a63ec0b86785ea48c8ecca42">ALLOCATE_INPUT_BUFFER_CODEC</a> = 0x1, <a href="Codec.md#ggaeae808d52153b2e33c6815162bbd11e0ae09681fcb839aa54acd974d872e3020d">ALLOCATE_INPUT_BUFFER_USER</a> = 0x2, <a href="Codec.md#ggaeae808d52153b2e33c6815162bbd11e0a73f74ceb227e306dbe940289a138bdf9">ALLOCATE_OUTPUT_BUFFER_CODEC</a> = 0x4, <a href="Codec.md#ggaeae808d52153b2e33c6815162bbd11e0a81113cd1f553c8e05eb9bd59fdb58bed">ALLOCATE_OUTPUT_BUFFER_USER</a> = 0x8 }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2041764895165623"><a name="p2041764895165623"></a><a name="p2041764895165623"></a>Enumerates allocation modes of input and output buffers.</p>
</td>
</tr>
<tr id="row397026735165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p81918685165623"><a name="p81918685165623"></a><a name="p81918685165623"></a><a href="Codec.md#gae5751aa8514dcaf2217df12db5ef57a1">CapsMask</a> { <a href="Codec.md#ggae5751aa8514dcaf2217df12db5ef57a1afe6e93325882ea7c27503f79d0b2dcae">ADAPTIVE_PLAYBACK</a> = 0x1, <a href="Codec.md#ggae5751aa8514dcaf2217df12db5ef57a1ad0c1ab7c365efc53a4de146b91f1a10f">SECURE_PLAYBACK</a> = 0x2 }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p111166482165623"><a name="p111166482165623"></a><a name="p111166482165623"></a>Enumerates playback capabilities.</p>
</td>
</tr>
<tr id="row1332837039165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p539397278165623"><a name="p539397278165623"></a><a name="p539397278165623"></a><a href="Codec.md#ga2628ea8d12e8b2563c32f05dc7fff6fa">EventType</a> {   <a href="Codec.md#gga2628ea8d12e8b2563c32f05dc7fff6faa71cf6bf1e591a86cb536668cda0f2a00">EventError</a>, <a href="Codec.md#gga2628ea8d12e8b2563c32f05dc7fff6faaab9f6e22232b045b85118bdda8aac6db">EventFlushCompelte</a>, <a href="Codec.md#gga2628ea8d12e8b2563c32f05dc7fff6faa864f301176ff05ad003bc6e89eb2cb93">EventStopCompelte</a>, <a href="Codec.md#gga2628ea8d12e8b2563c32f05dc7fff6faaeb0fb0bb31b20a141d015d9a92c629ac">EventOutFormatChanged</a>,   <a href="Codec.md#gga2628ea8d12e8b2563c32f05dc7fff6faa70203255ab263a903886b8f774d5c4aa">EventMax</a> = 0x1FFFFFFF }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2064354634165623"><a name="p2064354634165623"></a><a name="p2064354634165623"></a>Enumerates event types.</p>
</td>
</tr>
<tr id="row175557834165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1811939200165623"><a name="p1811939200165623"></a><a name="p1811939200165623"></a><a href="Codec.md#ga8ef30fa9c08e08c8706653571f9f5b81">DirectionType</a> { <a href="Codec.md#gga8ef30fa9c08e08c8706653571f9f5b81a833326d0b04dd281eaf006c46842250d">INPUT_TYPE</a>, <a href="Codec.md#gga8ef30fa9c08e08c8706653571f9f5b81a9e3da5a3721894f1552c2715c1fbe95c">OUTPUT_TYPE</a>, <a href="Codec.md#gga8ef30fa9c08e08c8706653571f9f5b81a46bcae2d9d2268e6a0c9259b9aebfc2f">ALL_TYPE</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p598872876165623"><a name="p598872876165623"></a><a name="p598872876165623"></a>Enumerates input and output types.</p>
</td>
</tr>
<tr id="row1266304349165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p544947473165623"><a name="p544947473165623"></a><a name="p544947473165623"></a><a href="Codec.md#gacc0fd55192fd9f663121b037b06f41e8">BufferMode</a> { <a href="Codec.md#ggacc0fd55192fd9f663121b037b06f41e8adc7588f17692aa631f375290d50a2c8e">INTERNAL</a>, <a href="Codec.md#ggacc0fd55192fd9f663121b037b06f41e8a63fbb9fe7b9a695d3a65541465cb99d5">EXTERNAL</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p929255348165623"><a name="p929255348165623"></a><a name="p929255348165623"></a>Enumerates allocation types.</p>
</td>
</tr>
<tr id="row753091667165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2091529814165623"><a name="p2091529814165623"></a><a name="p2091529814165623"></a>{ <a href="Codec.md#gga6b7b47dd702d9e331586d485013fd1eaa750142c991cfbb45e81a11453c757cd8">CODEC_ERR_STREAM_BUF_FULL</a> = 100, <a href="Codec.md#gga6b7b47dd702d9e331586d485013fd1eaa07abd749dca99a6cde8e4d03acc075f6">CODEC_ERR_FRAME_BUF_EMPTY</a>, <a href="Codec.md#gga6b7b47dd702d9e331586d485013fd1eaa504a9ea3cbe78aa1ba2423ee702151ac">CODEC_RECEIVE_EOS</a>, <a href="Codec.md#gga6b7b47dd702d9e331586d485013fd1eaa969385c1fbe6b30ab16b87775b06a074">CODEC_ERR_INVALID_OP</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p838497937165623"><a name="p838497937165623"></a><a name="p838497937165623"></a>Enumerates codec error types.</p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table1488309659165623"></a>
<table><thead align="left"><tr id="row824723079165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p74193588165623"><a name="p74193588165623"></a><a name="p74193588165623"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1639378803165623"><a name="p1639378803165623"></a><a name="p1639378803165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row227041967165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p27300763165623"><a name="p27300763165623"></a><a name="p27300763165623"></a><a href="Codec.md#gadb2714f1e7a69419cefd38a2ad1f9829">CodecInit</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2019818102165623"><a name="p2019818102165623"></a><a name="p2019818102165623"></a>int32_t</p>
<p id="p1335540513165623"><a name="p1335540513165623"></a><a name="p1335540513165623"></a>Initializes the internal audio and video submodules of the codec.</p>
</td>
</tr>
<tr id="row2076438760165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1923874968165623"><a name="p1923874968165623"></a><a name="p1923874968165623"></a><a href="Codec.md#ga2d6eb231ca7766990cfa8c1841637245">CodecDeinit</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1110462835165623"><a name="p1110462835165623"></a><a name="p1110462835165623"></a>int32_t</p>
<p id="p1398266176165623"><a name="p1398266176165623"></a><a name="p1398266176165623"></a>Deinitializes the internal audio and video submodules of the codec.</p>
</td>
</tr>
<tr id="row495909515165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1688146782165623"><a name="p1688146782165623"></a><a name="p1688146782165623"></a><a href="Codec.md#gaf0bb69d2f8c5ad0fec6959b353ee1acd">CodecEnumerateCapbility</a> (uint32_t <a href="UTILS.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>, <a href="Codec.md#ga1876710b1f2fe1d80e8b9de9ff28e0e3">CodecCapbility</a> *cap)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1803091196165623"><a name="p1803091196165623"></a><a name="p1803091196165623"></a>int32_t</p>
<p id="p1038216654165623"><a name="p1038216654165623"></a><a name="p1038216654165623"></a>Obtains the capabilities of a specified media type based on an index.</p>
</td>
</tr>
<tr id="row76021500165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p681858379165623"><a name="p681858379165623"></a><a name="p681858379165623"></a><a href="Codec.md#ga1a6fbf6e84e01fdc1af59caa4203ce8e">CodecGetCapbility</a> (<a href="Codec.md#ga1bee586eafa91dfb60f94ba40fc95faa">AvCodecMime</a> mime, <a href="Codec.md#ga03b4b6ae5fb82af68d46aaea3d3e4d79">CodecType</a> type, uint32_t flags, <a href="Codec.md#ga1876710b1f2fe1d80e8b9de9ff28e0e3">CodecCapbility</a> *cap)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1337824452165623"><a name="p1337824452165623"></a><a name="p1337824452165623"></a>int32_t</p>
<p id="p543099127165623"><a name="p543099127165623"></a><a name="p543099127165623"></a>Obtains the capabilities of a specified media type.</p>
</td>
</tr>
<tr id="row1032086501165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p394341995165623"><a name="p394341995165623"></a><a name="p394341995165623"></a><a href="Codec.md#ga74aa0395a51f004390f7a92fb68faddd">CodecCreate</a> (const char *name, const <a href="Param.md">Param</a> *attr, int len, <a href="Codec.md#ga9381a619f36ac8d5d7f467d2f0404183">CODEC_HANDLETYPE</a> *handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p439356166165623"><a name="p439356166165623"></a><a name="p439356166165623"></a>int32_t</p>
<p id="p2112918482165623"><a name="p2112918482165623"></a><a name="p2112918482165623"></a>Creates a specific codec component and returns the component context through a handle.</p>
</td>
</tr>
<tr id="row1187865359165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p71490327165623"><a name="p71490327165623"></a><a name="p71490327165623"></a><a href="Codec.md#ga1bc0592b05e4f687e2bef2ffb83102b8">CodecDestroy</a> (<a href="Codec.md#ga9381a619f36ac8d5d7f467d2f0404183">CODEC_HANDLETYPE</a> handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1890841512165623"><a name="p1890841512165623"></a><a name="p1890841512165623"></a>int32_t</p>
<p id="p1626574316165623"><a name="p1626574316165623"></a><a name="p1626574316165623"></a>Destroys a codec component.</p>
</td>
</tr>
<tr id="row1063831248165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1358043961165623"><a name="p1358043961165623"></a><a name="p1358043961165623"></a><a href="Codec.md#ga36a994c5f9f4d104aad0c24b5e8cbd37">CodecSetPortMode</a> (<a href="Codec.md#ga9381a619f36ac8d5d7f467d2f0404183">CODEC_HANDLETYPE</a> handle, <a href="Codec.md#ga8ef30fa9c08e08c8706653571f9f5b81">DirectionType</a> type, <a href="Codec.md#gacc0fd55192fd9f663121b037b06f41e8">BufferMode</a> mode)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1521560860165623"><a name="p1521560860165623"></a><a name="p1521560860165623"></a>int32_t</p>
<p id="p1050572243165623"><a name="p1050572243165623"></a><a name="p1050572243165623"></a>Sets the input or output buffer mode.</p>
</td>
</tr>
<tr id="row37962305165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p680237184165623"><a name="p680237184165623"></a><a name="p680237184165623"></a><a href="Codec.md#gaa080cf23aa5f77b30f3b90a026d97cc0">CodecSetParameter</a> (<a href="Codec.md#ga9381a619f36ac8d5d7f467d2f0404183">CODEC_HANDLETYPE</a> handle, const <a href="Param.md">Param</a> *params, int paramCnt)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1037214716165623"><a name="p1037214716165623"></a><a name="p1037214716165623"></a>int32_t</p>
<p id="p1147345022165623"><a name="p1147345022165623"></a><a name="p1147345022165623"></a>Sets parameters required by a codec component.</p>
</td>
</tr>
<tr id="row1622355511165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p19465736165623"><a name="p19465736165623"></a><a name="p19465736165623"></a><a href="Codec.md#ga1d812eac032e3e05cf5bf71b03e93f65">CodecGetParameter</a> (<a href="Codec.md#ga9381a619f36ac8d5d7f467d2f0404183">CODEC_HANDLETYPE</a> handle, <a href="Param.md">Param</a> *params, int paramCnt)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1673293645165623"><a name="p1673293645165623"></a><a name="p1673293645165623"></a>int32_t</p>
<p id="p979895472165623"><a name="p979895472165623"></a><a name="p979895472165623"></a>Obtains parameters from a codec component.</p>
</td>
</tr>
<tr id="row1769872850165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p127698502165623"><a name="p127698502165623"></a><a name="p127698502165623"></a><a href="Codec.md#ga38c1744b0b4be5817ef49556ae665d18">CodecStart</a> (<a href="Codec.md#ga9381a619f36ac8d5d7f467d2f0404183">CODEC_HANDLETYPE</a> handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p801469000165623"><a name="p801469000165623"></a><a name="p801469000165623"></a>int32_t</p>
<p id="p1774921691165623"><a name="p1774921691165623"></a><a name="p1774921691165623"></a>Starts a codec component.</p>
</td>
</tr>
<tr id="row1881613211165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p387052825165623"><a name="p387052825165623"></a><a name="p387052825165623"></a><a href="Codec.md#ga8e7913c052c2e45e193fb0aab3f5c7fd">CodecStop</a> (<a href="Codec.md#ga9381a619f36ac8d5d7f467d2f0404183">CODEC_HANDLETYPE</a> handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1532643611165623"><a name="p1532643611165623"></a><a name="p1532643611165623"></a>int32_t</p>
<p id="p601891044165623"><a name="p601891044165623"></a><a name="p601891044165623"></a>Stops a codec component.</p>
</td>
</tr>
<tr id="row1028986857165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1869610577165623"><a name="p1869610577165623"></a><a name="p1869610577165623"></a><a href="Codec.md#gaa6ed6c24e29f8fdfbbb0a3d562260a6a">CodecFlush</a> (<a href="Codec.md#ga9381a619f36ac8d5d7f467d2f0404183">CODEC_HANDLETYPE</a> handle, <a href="Codec.md#ga8ef30fa9c08e08c8706653571f9f5b81">DirectionType</a> directType)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p71678534165623"><a name="p71678534165623"></a><a name="p71678534165623"></a>int32_t</p>
<p id="p372788199165623"><a name="p372788199165623"></a><a name="p372788199165623"></a>Clears the cache when the codec component is the running state.</p>
</td>
</tr>
<tr id="row1647179982165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p736867315165623"><a name="p736867315165623"></a><a name="p736867315165623"></a><a href="Codec.md#ga0daece8dbf22da84f926761c994819bc">CodecQueueInput</a> (<a href="Codec.md#ga9381a619f36ac8d5d7f467d2f0404183">CODEC_HANDLETYPE</a> handle, const <a href="InputInfo.md">InputInfo</a> *inputData, uint32_t timeoutMs)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1067965414165623"><a name="p1067965414165623"></a><a name="p1067965414165623"></a>int32_t</p>
<p id="p2072525979165623"><a name="p2072525979165623"></a><a name="p2072525979165623"></a>Queues input data.</p>
</td>
</tr>
<tr id="row753839874165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p944111111165623"><a name="p944111111165623"></a><a name="p944111111165623"></a><a href="Codec.md#ga91d7e1566c90d7cb9ac846eecad0024f">CodecDequeInput</a> (<a href="Codec.md#ga9381a619f36ac8d5d7f467d2f0404183">CODEC_HANDLETYPE</a> handle, uint32_t timeoutMs, <a href="InputInfo.md">InputInfo</a> *inputData)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p627531635165623"><a name="p627531635165623"></a><a name="p627531635165623"></a>int32_t</p>
<p id="p692043633165623"><a name="p692043633165623"></a><a name="p692043633165623"></a>Dequeues input data that has been used.</p>
</td>
</tr>
<tr id="row661389752165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p556239394165623"><a name="p556239394165623"></a><a name="p556239394165623"></a><a href="Codec.md#gac98f3505082c3cb2413d9e95eef9c804">CodecQueueOutput</a> (<a href="Codec.md#ga9381a619f36ac8d5d7f467d2f0404183">CODEC_HANDLETYPE</a> handle, <a href="OutputInfo.md">OutputInfo</a> *outInfo, uint32_t timeoutMs, int releaseFenceFd)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1316167490165623"><a name="p1316167490165623"></a><a name="p1316167490165623"></a>int32_t</p>
<p id="p1245141755165623"><a name="p1245141755165623"></a><a name="p1245141755165623"></a>Queues output data.</p>
</td>
</tr>
<tr id="row1706320508165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p745246877165623"><a name="p745246877165623"></a><a name="p745246877165623"></a><a href="Codec.md#gab575752467517eb8e6766773c1e3fb23">CodecDequeueOutput</a> (<a href="Codec.md#ga9381a619f36ac8d5d7f467d2f0404183">CODEC_HANDLETYPE</a> handle, uint32_t timeoutMs, int *acquireFd, <a href="OutputInfo.md">OutputInfo</a> *outInfo)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p61917914165623"><a name="p61917914165623"></a><a name="p61917914165623"></a>int32_t</p>
<p id="p36291783165623"><a name="p36291783165623"></a><a name="p36291783165623"></a>Dequeues output data.</p>
</td>
</tr>
<tr id="row211690775165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p778430932165623"><a name="p778430932165623"></a><a name="p778430932165623"></a><a href="Codec.md#ga28ec6149d05765ee75f4836e0b092406">CodecSetCallback</a> (<a href="Codec.md#ga9381a619f36ac8d5d7f467d2f0404183">CODEC_HANDLETYPE</a> handle, const <a href="CodecCallback.md">CodecCallback</a> *cb, <a href="Codec.md#ga58d2f4a8d12daa1dcf4eb297f3ebaabc">UINTPTR</a> instance)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p234529269165623"><a name="p234529269165623"></a><a name="p234529269165623"></a>int32_t</p>
<p id="p572152623165623"><a name="p572152623165623"></a><a name="p572152623165623"></a>Sets the callback function.</p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section794294671165623"></a>

## **Enumeration Type**<a name="section1038214150165623"></a>

## anonymous enum<a name="ga6b7b47dd702d9e331586d485013fd1ea"></a>

```
anonymous enum
```

**Description:**

Enumerates codec error types.

<a name="table10185793165623"></a>
<table><thead align="left"><tr id="row1822623348165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1558548910165623"><a name="p1558548910165623"></a><a name="p1558548910165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1278817773165623"><a name="p1278817773165623"></a><a name="p1278817773165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1775819763165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1825246584165623p0"><a name="entry1825246584165623p0"></a><a name="entry1825246584165623p0"></a><strong id="gga6b7b47dd702d9e331586d485013fd1eaa750142c991cfbb45e81a11453c757cd8"><a name="gga6b7b47dd702d9e331586d485013fd1eaa750142c991cfbb45e81a11453c757cd8"></a><a name="gga6b7b47dd702d9e331586d485013fd1eaa750142c991cfbb45e81a11453c757cd8"></a></strong>CODEC_ERR_STREAM_BUF_FULL</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1679363836165623"><a name="p1679363836165623"></a><a name="p1679363836165623"></a>Elementary stream buffer queue is full.</p>
<p id="p2817182318200"><a name="p2817182318200"></a><a name="p2817182318200"></a></p>
</td>
</tr>
<tr id="row1150518280165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1758530696165623p0"><a name="entry1758530696165623p0"></a><a name="entry1758530696165623p0"></a><strong id="gga6b7b47dd702d9e331586d485013fd1eaa07abd749dca99a6cde8e4d03acc075f6"><a name="gga6b7b47dd702d9e331586d485013fd1eaa07abd749dca99a6cde8e4d03acc075f6"></a><a name="gga6b7b47dd702d9e331586d485013fd1eaa07abd749dca99a6cde8e4d03acc075f6"></a></strong>CODEC_ERR_FRAME_BUF_EMPTY</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p500625095165623"><a name="p500625095165623"></a><a name="p500625095165623"></a>Frame buffer queue is empty.</p>
<p id="p88171823202010"><a name="p88171823202010"></a><a name="p88171823202010"></a></p>
</td>
</tr>
<tr id="row1687810518165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1309903700165623p0"><a name="entry1309903700165623p0"></a><a name="entry1309903700165623p0"></a><strong id="gga6b7b47dd702d9e331586d485013fd1eaa504a9ea3cbe78aa1ba2423ee702151ac"><a name="gga6b7b47dd702d9e331586d485013fd1eaa504a9ea3cbe78aa1ba2423ee702151ac"></a><a name="gga6b7b47dd702d9e331586d485013fd1eaa504a9ea3cbe78aa1ba2423ee702151ac"></a></strong>CODEC_RECEIVE_EOS</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1401554787165623"><a name="p1401554787165623"></a><a name="p1401554787165623"></a>End of streams</p>
<p id="p13817423102017"><a name="p13817423102017"></a><a name="p13817423102017"></a></p>
</td>
</tr>
<tr id="row746086788165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry801819255165623p0"><a name="entry801819255165623p0"></a><a name="entry801819255165623p0"></a><strong id="gga6b7b47dd702d9e331586d485013fd1eaa969385c1fbe6b30ab16b87775b06a074"><a name="gga6b7b47dd702d9e331586d485013fd1eaa969385c1fbe6b30ab16b87775b06a074"></a><a name="gga6b7b47dd702d9e331586d485013fd1eaa969385c1fbe6b30ab16b87775b06a074"></a></strong>CODEC_ERR_INVALID_OP</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p811981817165623"><a name="p811981817165623"></a><a name="p811981817165623"></a>Invalid operation</p>
<p id="p581718232200"><a name="p581718232200"></a><a name="p581718232200"></a></p>
</td>
</tr>
</tbody>
</table>

## AllocateBufferMode<a name="gaeae808d52153b2e33c6815162bbd11e0"></a>

```
enum [AllocateBufferMode](Codec.md#gaeae808d52153b2e33c6815162bbd11e0)
```

**Description:**

Enumerates allocation modes of input and output buffers.

<a name="table1371426571165623"></a>
<table><thead align="left"><tr id="row992035937165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p859114407165623"><a name="p859114407165623"></a><a name="p859114407165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1779053235165623"><a name="p1779053235165623"></a><a name="p1779053235165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1515325084165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1643526351165623p0"><a name="entry1643526351165623p0"></a><a name="entry1643526351165623p0"></a><strong id="ggaeae808d52153b2e33c6815162bbd11e0ae8110d24a63ec0b86785ea48c8ecca42"><a name="ggaeae808d52153b2e33c6815162bbd11e0ae8110d24a63ec0b86785ea48c8ecca42"></a><a name="ggaeae808d52153b2e33c6815162bbd11e0ae8110d24a63ec0b86785ea48c8ecca42"></a></strong>ALLOCATE_INPUT_BUFFER_CODEC</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1369498496165623"><a name="p1369498496165623"></a><a name="p1369498496165623"></a>Input buffer allocated within the Codec module</p>
<p id="p882282322012"><a name="p882282322012"></a><a name="p882282322012"></a></p>
</td>
</tr>
<tr id="row364956561165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1135253066165623p0"><a name="entry1135253066165623p0"></a><a name="entry1135253066165623p0"></a><strong id="ggaeae808d52153b2e33c6815162bbd11e0ae09681fcb839aa54acd974d872e3020d"><a name="ggaeae808d52153b2e33c6815162bbd11e0ae09681fcb839aa54acd974d872e3020d"></a><a name="ggaeae808d52153b2e33c6815162bbd11e0ae09681fcb839aa54acd974d872e3020d"></a></strong>ALLOCATE_INPUT_BUFFER_USER</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1503683761165623"><a name="p1503683761165623"></a><a name="p1503683761165623"></a>Input buffer allocated by an external user</p>
<p id="p4822162392019"><a name="p4822162392019"></a><a name="p4822162392019"></a></p>
</td>
</tr>
<tr id="row322565667165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1239846169165623p0"><a name="entry1239846169165623p0"></a><a name="entry1239846169165623p0"></a><strong id="ggaeae808d52153b2e33c6815162bbd11e0a73f74ceb227e306dbe940289a138bdf9"><a name="ggaeae808d52153b2e33c6815162bbd11e0a73f74ceb227e306dbe940289a138bdf9"></a><a name="ggaeae808d52153b2e33c6815162bbd11e0a73f74ceb227e306dbe940289a138bdf9"></a></strong>ALLOCATE_OUTPUT_BUFFER_CODEC</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p644574221165623"><a name="p644574221165623"></a><a name="p644574221165623"></a>Output buffer allocated within the Codec module</p>
<p id="p12822123122018"><a name="p12822123122018"></a><a name="p12822123122018"></a></p>
</td>
</tr>
<tr id="row1588181662165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry593473090165623p0"><a name="entry593473090165623p0"></a><a name="entry593473090165623p0"></a><strong id="ggaeae808d52153b2e33c6815162bbd11e0a81113cd1f553c8e05eb9bd59fdb58bed"><a name="ggaeae808d52153b2e33c6815162bbd11e0a81113cd1f553c8e05eb9bd59fdb58bed"></a><a name="ggaeae808d52153b2e33c6815162bbd11e0a81113cd1f553c8e05eb9bd59fdb58bed"></a></strong>ALLOCATE_OUTPUT_BUFFER_USER</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1680070235165623"><a name="p1680070235165623"></a><a name="p1680070235165623"></a>Output buffer allocated by an external user</p>
<p id="p17822523162014"><a name="p17822523162014"></a><a name="p17822523162014"></a></p>
</td>
</tr>
</tbody>
</table>

## AudioBitRate<a name="gac8cc627a9912e6a338396a6f19bbba5d"></a>

```
enum [AudioBitRate](Codec.md#gac8cc627a9912e6a338396a6f19bbba5d)
```

**Description:**

Enumerates audio bit rates.

<a name="table342145866165623"></a>
<table><thead align="left"><tr id="row1544792512165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1325576770165623"><a name="p1325576770165623"></a><a name="p1325576770165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p359608511165623"><a name="p359608511165623"></a><a name="p359608511165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1769351875165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry99616154165623p0"><a name="entry99616154165623p0"></a><a name="entry99616154165623p0"></a><strong id="ggac8cc627a9912e6a338396a6f19bbba5da1b31811befaf84b164684a38fa022f43"><a name="ggac8cc627a9912e6a338396a6f19bbba5da1b31811befaf84b164684a38fa022f43"></a><a name="ggac8cc627a9912e6a338396a6f19bbba5da1b31811befaf84b164684a38fa022f43"></a></strong>AUD_AAC_BPS_8K</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1096763359165623"><a name="p1096763359165623"></a><a name="p1096763359165623"></a>8 kbit/s</p>
<p id="p682662302013"><a name="p682662302013"></a><a name="p682662302013"></a></p>
</td>
</tr>
<tr id="row317741183165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry699040833165623p0"><a name="entry699040833165623p0"></a><a name="entry699040833165623p0"></a><strong id="ggac8cc627a9912e6a338396a6f19bbba5dab71f0668b9fc4955fe059339ea663e8e"><a name="ggac8cc627a9912e6a338396a6f19bbba5dab71f0668b9fc4955fe059339ea663e8e"></a><a name="ggac8cc627a9912e6a338396a6f19bbba5dab71f0668b9fc4955fe059339ea663e8e"></a></strong>AUD_AAC_BPS_16K</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1912475488165623"><a name="p1912475488165623"></a><a name="p1912475488165623"></a>16 kbit/s</p>
<p id="p88261423162020"><a name="p88261423162020"></a><a name="p88261423162020"></a></p>
</td>
</tr>
<tr id="row1114722007165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1140182262165623p0"><a name="entry1140182262165623p0"></a><a name="entry1140182262165623p0"></a><strong id="ggac8cc627a9912e6a338396a6f19bbba5da3cc22f17e3fddb9d081aa3d826d31ac9"><a name="ggac8cc627a9912e6a338396a6f19bbba5da3cc22f17e3fddb9d081aa3d826d31ac9"></a><a name="ggac8cc627a9912e6a338396a6f19bbba5da3cc22f17e3fddb9d081aa3d826d31ac9"></a></strong>AUD_AAC_BPS_22K</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p610585689165623"><a name="p610585689165623"></a><a name="p610585689165623"></a>22 kbit/s</p>
<p id="p148261123182020"><a name="p148261123182020"></a><a name="p148261123182020"></a></p>
</td>
</tr>
<tr id="row2104204688165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2138013792165623p0"><a name="entry2138013792165623p0"></a><a name="entry2138013792165623p0"></a><strong id="ggac8cc627a9912e6a338396a6f19bbba5dadb78faf7877b6f70fd9b55406dcbd6b0"><a name="ggac8cc627a9912e6a338396a6f19bbba5dadb78faf7877b6f70fd9b55406dcbd6b0"></a><a name="ggac8cc627a9912e6a338396a6f19bbba5dadb78faf7877b6f70fd9b55406dcbd6b0"></a></strong>AUD_AAC_BPS_24K</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1522818541165623"><a name="p1522818541165623"></a><a name="p1522818541165623"></a>24 kbit/s</p>
<p id="p88261823192014"><a name="p88261823192014"></a><a name="p88261823192014"></a></p>
</td>
</tr>
<tr id="row2055025125165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry36577394165623p0"><a name="entry36577394165623p0"></a><a name="entry36577394165623p0"></a><strong id="ggac8cc627a9912e6a338396a6f19bbba5da974bd8a79bb6004f84b670f2496a33b9"><a name="ggac8cc627a9912e6a338396a6f19bbba5da974bd8a79bb6004f84b670f2496a33b9"></a><a name="ggac8cc627a9912e6a338396a6f19bbba5da974bd8a79bb6004f84b670f2496a33b9"></a></strong>AUD_AAC_BPS_32K</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2088526466165623"><a name="p2088526466165623"></a><a name="p2088526466165623"></a>32 kbit/s</p>
<p id="p78261923132016"><a name="p78261923132016"></a><a name="p78261923132016"></a></p>
</td>
</tr>
<tr id="row1007955671165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry593703845165623p0"><a name="entry593703845165623p0"></a><a name="entry593703845165623p0"></a><strong id="ggac8cc627a9912e6a338396a6f19bbba5da7d330b118800e19500f2f4a9b6af38f8"><a name="ggac8cc627a9912e6a338396a6f19bbba5da7d330b118800e19500f2f4a9b6af38f8"></a><a name="ggac8cc627a9912e6a338396a6f19bbba5da7d330b118800e19500f2f4a9b6af38f8"></a></strong>AUD_AAC_BPS_48K</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p261659414165623"><a name="p261659414165623"></a><a name="p261659414165623"></a>48 kbit/s</p>
<p id="p11826132332020"><a name="p11826132332020"></a><a name="p11826132332020"></a></p>
</td>
</tr>
<tr id="row2056678512165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry823986207165623p0"><a name="entry823986207165623p0"></a><a name="entry823986207165623p0"></a><strong id="ggac8cc627a9912e6a338396a6f19bbba5da2b8757624080a60f39d848dac7820e99"><a name="ggac8cc627a9912e6a338396a6f19bbba5da2b8757624080a60f39d848dac7820e99"></a><a name="ggac8cc627a9912e6a338396a6f19bbba5da2b8757624080a60f39d848dac7820e99"></a></strong>AUD_AAC_BPS_64K</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2143148619165623"><a name="p2143148619165623"></a><a name="p2143148619165623"></a>64 kbit/s</p>
<p id="p6826423192014"><a name="p6826423192014"></a><a name="p6826423192014"></a></p>
</td>
</tr>
<tr id="row458145888165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry179318464165623p0"><a name="entry179318464165623p0"></a><a name="entry179318464165623p0"></a><strong id="ggac8cc627a9912e6a338396a6f19bbba5da5ff13a09a232327578c69159f7564da8"><a name="ggac8cc627a9912e6a338396a6f19bbba5da5ff13a09a232327578c69159f7564da8"></a><a name="ggac8cc627a9912e6a338396a6f19bbba5da5ff13a09a232327578c69159f7564da8"></a></strong>AUD_AAC_BPS_96K</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1695238987165623"><a name="p1695238987165623"></a><a name="p1695238987165623"></a>96 kbit/s</p>
<p id="p182682313207"><a name="p182682313207"></a><a name="p182682313207"></a></p>
</td>
</tr>
<tr id="row1944607467165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1275463374165623p0"><a name="entry1275463374165623p0"></a><a name="entry1275463374165623p0"></a><strong id="ggac8cc627a9912e6a338396a6f19bbba5da8806920e563eca6c76b225185f24f191"><a name="ggac8cc627a9912e6a338396a6f19bbba5da8806920e563eca6c76b225185f24f191"></a><a name="ggac8cc627a9912e6a338396a6f19bbba5da8806920e563eca6c76b225185f24f191"></a></strong>AUD_AAC_BPS_128K</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2104490780165623"><a name="p2104490780165623"></a><a name="p2104490780165623"></a>128 kbit/s</p>
<p id="p1282622316203"><a name="p1282622316203"></a><a name="p1282622316203"></a></p>
</td>
</tr>
<tr id="row920409019165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry879356263165623p0"><a name="entry879356263165623p0"></a><a name="entry879356263165623p0"></a><strong id="ggac8cc627a9912e6a338396a6f19bbba5da7584ca8ebd583c448c5e2ff4957448f7"><a name="ggac8cc627a9912e6a338396a6f19bbba5da7584ca8ebd583c448c5e2ff4957448f7"></a><a name="ggac8cc627a9912e6a338396a6f19bbba5da7584ca8ebd583c448c5e2ff4957448f7"></a></strong>AUD_AAC_BPS_256K</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1419695046165623"><a name="p1419695046165623"></a><a name="p1419695046165623"></a>256 kbit/s</p>
<p id="p582692322017"><a name="p582692322017"></a><a name="p582692322017"></a></p>
</td>
</tr>
<tr id="row1142515377165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1715182871165623p0"><a name="entry1715182871165623p0"></a><a name="entry1715182871165623p0"></a><strong id="ggac8cc627a9912e6a338396a6f19bbba5dade0faf8053bab953b55bc3e4d20341d5"><a name="ggac8cc627a9912e6a338396a6f19bbba5dade0faf8053bab953b55bc3e4d20341d5"></a><a name="ggac8cc627a9912e6a338396a6f19bbba5dade0faf8053bab953b55bc3e4d20341d5"></a></strong>AUD_AAC_BPS_320K</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2055208717165623"><a name="p2055208717165623"></a><a name="p2055208717165623"></a>320 kbit/s</p>
<p id="p38261023102014"><a name="p38261023102014"></a><a name="p38261023102014"></a></p>
</td>
</tr>
</tbody>
</table>

## AudioSampleRate<a name="gaa0280074adafe6d2581d31f71512b842"></a>

```
enum [AudioSampleRate](Codec.md#gaa0280074adafe6d2581d31f71512b842)
```

**Description:**

Enumerates audio sampling rates.

<a name="table511959818165623"></a>
<table><thead align="left"><tr id="row1743873024165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1249568045165623"><a name="p1249568045165623"></a><a name="p1249568045165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p665668674165623"><a name="p665668674165623"></a><a name="p665668674165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1005843036165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1987143228165623p0"><a name="entry1987143228165623p0"></a><a name="entry1987143228165623p0"></a><strong id="ggaa0280074adafe6d2581d31f71512b842a65d5a1e4d1f048a33d29c9a3b6f540bd"><a name="ggaa0280074adafe6d2581d31f71512b842a65d5a1e4d1f048a33d29c9a3b6f540bd"></a><a name="ggaa0280074adafe6d2581d31f71512b842a65d5a1e4d1f048a33d29c9a3b6f540bd"></a></strong>AUD_SAMPLE_RATE_8000</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p820147263165623"><a name="p820147263165623"></a><a name="p820147263165623"></a>8 KHz</p>
<p id="p58341323162011"><a name="p58341323162011"></a><a name="p58341323162011"></a></p>
</td>
</tr>
<tr id="row1333863103165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1826747644165623p0"><a name="entry1826747644165623p0"></a><a name="entry1826747644165623p0"></a><strong id="ggaa0280074adafe6d2581d31f71512b842ac8379e14b05cdac5edfcc931ac8b33a9"><a name="ggaa0280074adafe6d2581d31f71512b842ac8379e14b05cdac5edfcc931ac8b33a9"></a><a name="ggaa0280074adafe6d2581d31f71512b842ac8379e14b05cdac5edfcc931ac8b33a9"></a></strong>AUD_SAMPLE_RATE_12000</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p234191517165623"><a name="p234191517165623"></a><a name="p234191517165623"></a>12 KHz</p>
<p id="p1483422342011"><a name="p1483422342011"></a><a name="p1483422342011"></a></p>
</td>
</tr>
<tr id="row935193637165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry289032669165623p0"><a name="entry289032669165623p0"></a><a name="entry289032669165623p0"></a><strong id="ggaa0280074adafe6d2581d31f71512b842a57b1853b1e309bf1aa5b3a35b06b0f81"><a name="ggaa0280074adafe6d2581d31f71512b842a57b1853b1e309bf1aa5b3a35b06b0f81"></a><a name="ggaa0280074adafe6d2581d31f71512b842a57b1853b1e309bf1aa5b3a35b06b0f81"></a></strong>AUD_SAMPLE_RATE_11025</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1270311615165623"><a name="p1270311615165623"></a><a name="p1270311615165623"></a>11.025 KHz</p>
<p id="p2083472352012"><a name="p2083472352012"></a><a name="p2083472352012"></a></p>
</td>
</tr>
<tr id="row2049260697165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry179786736165623p0"><a name="entry179786736165623p0"></a><a name="entry179786736165623p0"></a><strong id="ggaa0280074adafe6d2581d31f71512b842a43395f0fe94ae2949778468e4488c3ee"><a name="ggaa0280074adafe6d2581d31f71512b842a43395f0fe94ae2949778468e4488c3ee"></a><a name="ggaa0280074adafe6d2581d31f71512b842a43395f0fe94ae2949778468e4488c3ee"></a></strong>AUD_SAMPLE_RATE_16000</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p445952646165623"><a name="p445952646165623"></a><a name="p445952646165623"></a>16 KHz</p>
<p id="p14835723112014"><a name="p14835723112014"></a><a name="p14835723112014"></a></p>
</td>
</tr>
<tr id="row108429788165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry961086230165623p0"><a name="entry961086230165623p0"></a><a name="entry961086230165623p0"></a><strong id="ggaa0280074adafe6d2581d31f71512b842a5e8155ecfa865686a66e004e37ce1e54"><a name="ggaa0280074adafe6d2581d31f71512b842a5e8155ecfa865686a66e004e37ce1e54"></a><a name="ggaa0280074adafe6d2581d31f71512b842a5e8155ecfa865686a66e004e37ce1e54"></a></strong>AUD_SAMPLE_RATE_22050</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2091712200165623"><a name="p2091712200165623"></a><a name="p2091712200165623"></a>22.050 KHz</p>
<p id="p1183517234208"><a name="p1183517234208"></a><a name="p1183517234208"></a></p>
</td>
</tr>
<tr id="row689583903165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry844879434165623p0"><a name="entry844879434165623p0"></a><a name="entry844879434165623p0"></a><strong id="ggaa0280074adafe6d2581d31f71512b842abd4c09d52f3da25adb108e9aa503119d"><a name="ggaa0280074adafe6d2581d31f71512b842abd4c09d52f3da25adb108e9aa503119d"></a><a name="ggaa0280074adafe6d2581d31f71512b842abd4c09d52f3da25adb108e9aa503119d"></a></strong>AUD_SAMPLE_RATE_24000</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p95881958165623"><a name="p95881958165623"></a><a name="p95881958165623"></a>24 KHz</p>
<p id="p13835142315208"><a name="p13835142315208"></a><a name="p13835142315208"></a></p>
</td>
</tr>
<tr id="row1545262005165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1632043754165623p0"><a name="entry1632043754165623p0"></a><a name="entry1632043754165623p0"></a><strong id="ggaa0280074adafe6d2581d31f71512b842a1f94827fe757ad2857d970638b6f8d66"><a name="ggaa0280074adafe6d2581d31f71512b842a1f94827fe757ad2857d970638b6f8d66"></a><a name="ggaa0280074adafe6d2581d31f71512b842a1f94827fe757ad2857d970638b6f8d66"></a></strong>AUD_SAMPLE_RATE_32000</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1435919348165623"><a name="p1435919348165623"></a><a name="p1435919348165623"></a>32 KHz</p>
<p id="p583514233208"><a name="p583514233208"></a><a name="p583514233208"></a></p>
</td>
</tr>
<tr id="row1193571606165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry566962117165623p0"><a name="entry566962117165623p0"></a><a name="entry566962117165623p0"></a><strong id="ggaa0280074adafe6d2581d31f71512b842ac880553f2ee154a240d9414598e006a2"><a name="ggaa0280074adafe6d2581d31f71512b842ac880553f2ee154a240d9414598e006a2"></a><a name="ggaa0280074adafe6d2581d31f71512b842ac880553f2ee154a240d9414598e006a2"></a></strong>AUD_SAMPLE_RATE_44100</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p416100972165623"><a name="p416100972165623"></a><a name="p416100972165623"></a>44.1 KHz</p>
<p id="p1183519233206"><a name="p1183519233206"></a><a name="p1183519233206"></a></p>
</td>
</tr>
<tr id="row1652126021165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry332820788165623p0"><a name="entry332820788165623p0"></a><a name="entry332820788165623p0"></a><strong id="ggaa0280074adafe6d2581d31f71512b842ade6dd509c28b66127c42d2634866b89c"><a name="ggaa0280074adafe6d2581d31f71512b842ade6dd509c28b66127c42d2634866b89c"></a><a name="ggaa0280074adafe6d2581d31f71512b842ade6dd509c28b66127c42d2634866b89c"></a></strong>AUD_SAMPLE_RATE_48000</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1654489526165623"><a name="p1654489526165623"></a><a name="p1654489526165623"></a>48 KHz</p>
<p id="p20835122372018"><a name="p20835122372018"></a><a name="p20835122372018"></a></p>
</td>
</tr>
<tr id="row802828970165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry558139094165623p0"><a name="entry558139094165623p0"></a><a name="entry558139094165623p0"></a><strong id="ggaa0280074adafe6d2581d31f71512b842a925218c15bb8522796e623a09d99dbc3"><a name="ggaa0280074adafe6d2581d31f71512b842a925218c15bb8522796e623a09d99dbc3"></a><a name="ggaa0280074adafe6d2581d31f71512b842a925218c15bb8522796e623a09d99dbc3"></a></strong>AUD_SAMPLE_RATE_64000</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1503147449165623"><a name="p1503147449165623"></a><a name="p1503147449165623"></a>64 KHz</p>
<p id="p48359230203"><a name="p48359230203"></a><a name="p48359230203"></a></p>
</td>
</tr>
<tr id="row1936936938165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1809750464165623p0"><a name="entry1809750464165623p0"></a><a name="entry1809750464165623p0"></a><strong id="ggaa0280074adafe6d2581d31f71512b842a48336a808a2ebcf5956995140e2d73dd"><a name="ggaa0280074adafe6d2581d31f71512b842a48336a808a2ebcf5956995140e2d73dd"></a><a name="ggaa0280074adafe6d2581d31f71512b842a48336a808a2ebcf5956995140e2d73dd"></a></strong>AUD_SAMPLE_RATE_96000</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1814580683165623"><a name="p1814580683165623"></a><a name="p1814580683165623"></a>96 KHz</p>
<p id="p283592342016"><a name="p283592342016"></a><a name="p283592342016"></a></p>
</td>
</tr>
<tr id="row626108318165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry188342506165623p0"><a name="entry188342506165623p0"></a><a name="entry188342506165623p0"></a><strong id="ggaa0280074adafe6d2581d31f71512b842a0cb82ce52fb70b359a0b2232f7f465a2"><a name="ggaa0280074adafe6d2581d31f71512b842a0cb82ce52fb70b359a0b2232f7f465a2"></a><a name="ggaa0280074adafe6d2581d31f71512b842a0cb82ce52fb70b359a0b2232f7f465a2"></a></strong>AUD_SAMPLE_RATE_INVALID</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p260048316165623"><a name="p260048316165623"></a><a name="p260048316165623"></a>Invalid sampling rate</p>
<p id="p11835823172010"><a name="p11835823172010"></a><a name="p11835823172010"></a></p>
</td>
</tr>
</tbody>
</table>

## AudioSoundMode<a name="gacecb40e35c431a27385f7b439fc7a76c"></a>

```
enum [AudioSoundMode](Codec.md#gacecb40e35c431a27385f7b439fc7a76c)
```

**Description:**

Enumerates audio channel modes.

<a name="table1949176654165623"></a>
<table><thead align="left"><tr id="row606565711165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p276753582165623"><a name="p276753582165623"></a><a name="p276753582165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p208367258165623"><a name="p208367258165623"></a><a name="p208367258165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1616826230165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry932606553165623p0"><a name="entry932606553165623p0"></a><a name="entry932606553165623p0"></a><strong id="ggacecb40e35c431a27385f7b439fc7a76caef98cd29f4639de89778f1be521a1676"><a name="ggacecb40e35c431a27385f7b439fc7a76caef98cd29f4639de89778f1be521a1676"></a><a name="ggacecb40e35c431a27385f7b439fc7a76caef98cd29f4639de89778f1be521a1676"></a></strong>AUD_SOUND_MODE_MONO</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1069402356165623"><a name="p1069402356165623"></a><a name="p1069402356165623"></a>Mono channel</p>
<p id="p4844122362016"><a name="p4844122362016"></a><a name="p4844122362016"></a></p>
</td>
</tr>
<tr id="row2000519532165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry647372055165623p0"><a name="entry647372055165623p0"></a><a name="entry647372055165623p0"></a><strong id="ggacecb40e35c431a27385f7b439fc7a76ca9437f9e5186f7095fb50775eddc439d6"><a name="ggacecb40e35c431a27385f7b439fc7a76ca9437f9e5186f7095fb50775eddc439d6"></a><a name="ggacecb40e35c431a27385f7b439fc7a76ca9437f9e5186f7095fb50775eddc439d6"></a></strong>AUD_SOUND_MODE_STEREO</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1405431153165623"><a name="p1405431153165623"></a><a name="p1405431153165623"></a>Stereo mode</p>
<p id="p6844923172012"><a name="p6844923172012"></a><a name="p6844923172012"></a></p>
</td>
</tr>
<tr id="row285428583165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1809269395165623p0"><a name="entry1809269395165623p0"></a><a name="entry1809269395165623p0"></a><strong id="ggacecb40e35c431a27385f7b439fc7a76ca53160e7e334a8629bec602c42d2ee5e6"><a name="ggacecb40e35c431a27385f7b439fc7a76ca53160e7e334a8629bec602c42d2ee5e6"></a><a name="ggacecb40e35c431a27385f7b439fc7a76ca53160e7e334a8629bec602c42d2ee5e6"></a></strong>AUD_SOUND_MODE_INVALID</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p432723868165623"><a name="p432723868165623"></a><a name="p432723868165623"></a>Invalid mode</p>
<p id="p1984415233201"><a name="p1984415233201"></a><a name="p1984415233201"></a></p>
</td>
</tr>
</tbody>
</table>

## AvCodecMime<a name="ga1bee586eafa91dfb60f94ba40fc95faa"></a>

```
enum [AvCodecMime](Codec.md#ga1bee586eafa91dfb60f94ba40fc95faa)
```

**Description:**

Enumerates MIME types.

<a name="table2059540354165623"></a>
<table><thead align="left"><tr id="row1686095901165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1987138454165623"><a name="p1987138454165623"></a><a name="p1987138454165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p601434252165623"><a name="p601434252165623"></a><a name="p601434252165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1829083715165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry133317159165623p0"><a name="entry133317159165623p0"></a><a name="entry133317159165623p0"></a><strong id="gga1bee586eafa91dfb60f94ba40fc95faaa4deff5e22cd5e2e83b6042880ad31863"><a name="gga1bee586eafa91dfb60f94ba40fc95faaa4deff5e22cd5e2e83b6042880ad31863"></a><a name="gga1bee586eafa91dfb60f94ba40fc95faaa4deff5e22cd5e2e83b6042880ad31863"></a></strong>MEDIA_MIMETYPE_IMAGE_JPEG</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p709523784165623"><a name="p709523784165623"></a><a name="p709523784165623"></a>JPEG image</p>
<p id="p684942322012"><a name="p684942322012"></a><a name="p684942322012"></a></p>
</td>
</tr>
<tr id="row1102373391165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry944591688165623p0"><a name="entry944591688165623p0"></a><a name="entry944591688165623p0"></a><strong id="gga1bee586eafa91dfb60f94ba40fc95faaa3db11a46c7f4bb848e6f0604268e41e3"><a name="gga1bee586eafa91dfb60f94ba40fc95faaa3db11a46c7f4bb848e6f0604268e41e3"></a><a name="gga1bee586eafa91dfb60f94ba40fc95faaa3db11a46c7f4bb848e6f0604268e41e3"></a></strong>MEDIA_MIMETYPE_VIDEO_AVC</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1363721199165623"><a name="p1363721199165623"></a><a name="p1363721199165623"></a>H.264 video</p>
<p id="p13849162342012"><a name="p13849162342012"></a><a name="p13849162342012"></a></p>
</td>
</tr>
<tr id="row1194511979165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1404146337165623p0"><a name="entry1404146337165623p0"></a><a name="entry1404146337165623p0"></a><strong id="gga1bee586eafa91dfb60f94ba40fc95faaaaf430209c9262e6fcd5cd8f97dafe614"><a name="gga1bee586eafa91dfb60f94ba40fc95faaaaf430209c9262e6fcd5cd8f97dafe614"></a><a name="gga1bee586eafa91dfb60f94ba40fc95faaaaf430209c9262e6fcd5cd8f97dafe614"></a></strong>MEDIA_MIMETYPE_VIDEO_HEVC</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p962466358165623"><a name="p962466358165623"></a><a name="p962466358165623"></a>H.265 video</p>
<p id="p7849923162014"><a name="p7849923162014"></a><a name="p7849923162014"></a></p>
</td>
</tr>
<tr id="row176706909165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1133394328165623p0"><a name="entry1133394328165623p0"></a><a name="entry1133394328165623p0"></a><strong id="gga1bee586eafa91dfb60f94ba40fc95faaac03eb65aaf7aff393e223346feb30415"><a name="gga1bee586eafa91dfb60f94ba40fc95faaac03eb65aaf7aff393e223346feb30415"></a><a name="gga1bee586eafa91dfb60f94ba40fc95faaac03eb65aaf7aff393e223346feb30415"></a></strong>MEDIA_MIMETYPE_AUDIO_AAC</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p522039013165623"><a name="p522039013165623"></a><a name="p522039013165623"></a>AAC audio</p>
<p id="p1884919239201"><a name="p1884919239201"></a><a name="p1884919239201"></a></p>
</td>
</tr>
<tr id="row570312703165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1407631267165623p0"><a name="entry1407631267165623p0"></a><a name="entry1407631267165623p0"></a><strong id="gga1bee586eafa91dfb60f94ba40fc95faaaa2fa953bd51d8ee18191315c7187fc96"><a name="gga1bee586eafa91dfb60f94ba40fc95faaaa2fa953bd51d8ee18191315c7187fc96"></a><a name="gga1bee586eafa91dfb60f94ba40fc95faaaa2fa953bd51d8ee18191315c7187fc96"></a></strong>MEDIA_MIMETYPE_INVALID</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p356513757165623"><a name="p356513757165623"></a><a name="p356513757165623"></a>Invalid MIME type</p>
<p id="p2849142362013"><a name="p2849142362013"></a><a name="p2849142362013"></a></p>
</td>
</tr>
</tbody>
</table>

## BufferMode<a name="gacc0fd55192fd9f663121b037b06f41e8"></a>

```
enum [BufferMode](Codec.md#gacc0fd55192fd9f663121b037b06f41e8)
```

**Description:**

Enumerates allocation types.

<a name="table683318068165623"></a>
<table><thead align="left"><tr id="row171812525165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1136669057165623"><a name="p1136669057165623"></a><a name="p1136669057165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p210135689165623"><a name="p210135689165623"></a><a name="p210135689165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1468579780165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1751467422165623p0"><a name="entry1751467422165623p0"></a><a name="entry1751467422165623p0"></a><strong id="ggacc0fd55192fd9f663121b037b06f41e8adc7588f17692aa631f375290d50a2c8e"><a name="ggacc0fd55192fd9f663121b037b06f41e8adc7588f17692aa631f375290d50a2c8e"></a><a name="ggacc0fd55192fd9f663121b037b06f41e8adc7588f17692aa631f375290d50a2c8e"></a></strong>INTERNAL</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1399212158165623"><a name="p1399212158165623"></a><a name="p1399212158165623"></a>Internal</p>
<p id="p11854192342013"><a name="p11854192342013"></a><a name="p11854192342013"></a></p>
</td>
</tr>
<tr id="row899828616165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1416020218165623p0"><a name="entry1416020218165623p0"></a><a name="entry1416020218165623p0"></a><strong id="ggacc0fd55192fd9f663121b037b06f41e8a63fbb9fe7b9a695d3a65541465cb99d5"><a name="ggacc0fd55192fd9f663121b037b06f41e8a63fbb9fe7b9a695d3a65541465cb99d5"></a><a name="ggacc0fd55192fd9f663121b037b06f41e8a63fbb9fe7b9a695d3a65541465cb99d5"></a></strong>EXTERNAL</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p226163797165623"><a name="p226163797165623"></a><a name="p226163797165623"></a>External</p>
<p id="p985411235208"><a name="p985411235208"></a><a name="p985411235208"></a></p>
</td>
</tr>
</tbody>
</table>

## BufferType<a name="gadf8e136713c0691010d2bec6ba63e9cf"></a>

```
enum [BufferType](Codec.md#gadf8e136713c0691010d2bec6ba63e9cf)
```

**Description:**

Enumerates buffer types.

<a name="table1195444120165623"></a>
<table><thead align="left"><tr id="row1678760690165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p763670311165623"><a name="p763670311165623"></a><a name="p763670311165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p936468262165623"><a name="p936468262165623"></a><a name="p936468262165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row824034398165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry201889076165623p0"><a name="entry201889076165623p0"></a><a name="entry201889076165623p0"></a><strong id="ggadf8e136713c0691010d2bec6ba63e9cfabc56eeb37d99d582a14b44fb0ef4cabc"><a name="ggadf8e136713c0691010d2bec6ba63e9cfabc56eeb37d99d582a14b44fb0ef4cabc"></a><a name="ggadf8e136713c0691010d2bec6ba63e9cfabc56eeb37d99d582a14b44fb0ef4cabc"></a></strong>BUFFER_TYPE_VIRTUAL</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1605275706165623"><a name="p1605275706165623"></a><a name="p1605275706165623"></a>Virtual memory</p>
<p id="p18567230206"><a name="p18567230206"></a><a name="p18567230206"></a></p>
</td>
</tr>
<tr id="row1496760687165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1924310323165623p0"><a name="entry1924310323165623p0"></a><a name="entry1924310323165623p0"></a><strong id="ggadf8e136713c0691010d2bec6ba63e9cfa4583aeaa2921c629ee785dbee184f421"><a name="ggadf8e136713c0691010d2bec6ba63e9cfa4583aeaa2921c629ee785dbee184f421"></a><a name="ggadf8e136713c0691010d2bec6ba63e9cfa4583aeaa2921c629ee785dbee184f421"></a></strong>BUFFER_TYPE_FD</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p435812586165623"><a name="p435812586165623"></a><a name="p435812586165623"></a>File descriptor, which can be used cross processes</p>
<p id="p1385619238206"><a name="p1385619238206"></a><a name="p1385619238206"></a></p>
</td>
</tr>
<tr id="row529594249165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1241018937165623p0"><a name="entry1241018937165623p0"></a><a name="entry1241018937165623p0"></a><strong id="ggadf8e136713c0691010d2bec6ba63e9cfa4bc0e24b5ce589d284b1771fc27c3d09"><a name="ggadf8e136713c0691010d2bec6ba63e9cfa4bc0e24b5ce589d284b1771fc27c3d09"></a><a name="ggadf8e136713c0691010d2bec6ba63e9cfa4bc0e24b5ce589d284b1771fc27c3d09"></a></strong>BUFFER_TYPE_HANDLE</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1206120756165623"><a name="p1206120756165623"></a><a name="p1206120756165623"></a>Handle, which can be used cross processes</p>
<p id="p1085616234205"><a name="p1085616234205"></a><a name="p1085616234205"></a></p>
</td>
</tr>
</tbody>
</table>

## CapsMask<a name="gae5751aa8514dcaf2217df12db5ef57a1"></a>

```
enum [CapsMask](Codec.md#gae5751aa8514dcaf2217df12db5ef57a1)
```

**Description:**

Enumerates playback capabilities.

<a name="table649832974165623"></a>
<table><thead align="left"><tr id="row1875365438165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p210343049165623"><a name="p210343049165623"></a><a name="p210343049165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1096673286165623"><a name="p1096673286165623"></a><a name="p1096673286165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1820137569165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1120845872165623p0"><a name="entry1120845872165623p0"></a><a name="entry1120845872165623p0"></a><strong id="ggae5751aa8514dcaf2217df12db5ef57a1afe6e93325882ea7c27503f79d0b2dcae"><a name="ggae5751aa8514dcaf2217df12db5ef57a1afe6e93325882ea7c27503f79d0b2dcae"></a><a name="ggae5751aa8514dcaf2217df12db5ef57a1afe6e93325882ea7c27503f79d0b2dcae"></a></strong>ADAPTIVE_PLAYBACK</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p872048266165623"><a name="p872048266165623"></a><a name="p872048266165623"></a>Adaptive playback</p>
<p id="p4860182315207"><a name="p4860182315207"></a><a name="p4860182315207"></a></p>
</td>
</tr>
<tr id="row14806948165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1624184580165623p0"><a name="entry1624184580165623p0"></a><a name="entry1624184580165623p0"></a><strong id="ggae5751aa8514dcaf2217df12db5ef57a1ad0c1ab7c365efc53a4de146b91f1a10f"><a name="ggae5751aa8514dcaf2217df12db5ef57a1ad0c1ab7c365efc53a4de146b91f1a10f"></a><a name="ggae5751aa8514dcaf2217df12db5ef57a1ad0c1ab7c365efc53a4de146b91f1a10f"></a></strong>SECURE_PLAYBACK</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2132129195165623"><a name="p2132129195165623"></a><a name="p2132129195165623"></a>Secure playback</p>
<p id="p4860142310207"><a name="p4860142310207"></a><a name="p4860142310207"></a></p>
</td>
</tr>
</tbody>
</table>

## CodecType<a name="ga03b4b6ae5fb82af68d46aaea3d3e4d79"></a>

```
enum [CodecType](Codec.md#ga03b4b6ae5fb82af68d46aaea3d3e4d79)
```

**Description:**

Enumerates codec types.

<a name="table265374386165623"></a>
<table><thead align="left"><tr id="row1627321373165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1688850927165623"><a name="p1688850927165623"></a><a name="p1688850927165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1206435521165623"><a name="p1206435521165623"></a><a name="p1206435521165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row813535519165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry845234023165623p0"><a name="entry845234023165623p0"></a><a name="entry845234023165623p0"></a><strong id="gga03b4b6ae5fb82af68d46aaea3d3e4d79a19c3c7765c55583a64e21938e2439261"><a name="gga03b4b6ae5fb82af68d46aaea3d3e4d79a19c3c7765c55583a64e21938e2439261"></a><a name="gga03b4b6ae5fb82af68d46aaea3d3e4d79a19c3c7765c55583a64e21938e2439261"></a></strong>VIDEO_DECODER</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p744077122165623"><a name="p744077122165623"></a><a name="p744077122165623"></a>Video decoding</p>
<p id="p138621235208"><a name="p138621235208"></a><a name="p138621235208"></a></p>
</td>
</tr>
<tr id="row1364889336165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry819515446165623p0"><a name="entry819515446165623p0"></a><a name="entry819515446165623p0"></a><strong id="gga03b4b6ae5fb82af68d46aaea3d3e4d79ad8044bc5b7d871723be90b5b6a094992"><a name="gga03b4b6ae5fb82af68d46aaea3d3e4d79ad8044bc5b7d871723be90b5b6a094992"></a><a name="gga03b4b6ae5fb82af68d46aaea3d3e4d79ad8044bc5b7d871723be90b5b6a094992"></a></strong>VIDEO_ENCODER</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1228545052165623"><a name="p1228545052165623"></a><a name="p1228545052165623"></a>Video encoding</p>
<p id="p3862723102018"><a name="p3862723102018"></a><a name="p3862723102018"></a></p>
</td>
</tr>
<tr id="row2035625421165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1620448263165623p0"><a name="entry1620448263165623p0"></a><a name="entry1620448263165623p0"></a><strong id="gga03b4b6ae5fb82af68d46aaea3d3e4d79ae4ade329585f6c202847138e3f9cd4a4"><a name="gga03b4b6ae5fb82af68d46aaea3d3e4d79ae4ade329585f6c202847138e3f9cd4a4"></a><a name="gga03b4b6ae5fb82af68d46aaea3d3e4d79ae4ade329585f6c202847138e3f9cd4a4"></a></strong>AUDIO_DECODER</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1289300375165623"><a name="p1289300375165623"></a><a name="p1289300375165623"></a>Audio decoding</p>
<p id="p1686242315208"><a name="p1686242315208"></a><a name="p1686242315208"></a></p>
</td>
</tr>
<tr id="row1932697669165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1981983269165623p0"><a name="entry1981983269165623p0"></a><a name="entry1981983269165623p0"></a><strong id="gga03b4b6ae5fb82af68d46aaea3d3e4d79a7f7f3d3880168089c1de6d1ebc3dbb54"><a name="gga03b4b6ae5fb82af68d46aaea3d3e4d79a7f7f3d3880168089c1de6d1ebc3dbb54"></a><a name="gga03b4b6ae5fb82af68d46aaea3d3e4d79a7f7f3d3880168089c1de6d1ebc3dbb54"></a></strong>AUDIO_ENCODER</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p117416346165623"><a name="p117416346165623"></a><a name="p117416346165623"></a>Audio encoding</p>
<p id="p286214238202"><a name="p286214238202"></a><a name="p286214238202"></a></p>
</td>
</tr>
<tr id="row2002146377165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry207538248165623p0"><a name="entry207538248165623p0"></a><a name="entry207538248165623p0"></a><strong id="gga03b4b6ae5fb82af68d46aaea3d3e4d79a7314b0d0e4638eaaeb8690b8555a6546"><a name="gga03b4b6ae5fb82af68d46aaea3d3e4d79a7314b0d0e4638eaaeb8690b8555a6546"></a><a name="gga03b4b6ae5fb82af68d46aaea3d3e4d79a7314b0d0e4638eaaeb8690b8555a6546"></a></strong>INVALID_TYPE</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1525998105165623"><a name="p1525998105165623"></a><a name="p1525998105165623"></a>Invalid type</p>
<p id="p15862223192017"><a name="p15862223192017"></a><a name="p15862223192017"></a></p>
</td>
</tr>
</tbody>
</table>

## DirectionType<a name="ga8ef30fa9c08e08c8706653571f9f5b81"></a>

```
enum [DirectionType](Codec.md#ga8ef30fa9c08e08c8706653571f9f5b81)
```

**Description:**

Enumerates input and output types.

<a name="table270993757165623"></a>
<table><thead align="left"><tr id="row673145016165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p608698110165623"><a name="p608698110165623"></a><a name="p608698110165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p350477326165623"><a name="p350477326165623"></a><a name="p350477326165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row296814805165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry456701249165623p0"><a name="entry456701249165623p0"></a><a name="entry456701249165623p0"></a><strong id="gga8ef30fa9c08e08c8706653571f9f5b81a833326d0b04dd281eaf006c46842250d"><a name="gga8ef30fa9c08e08c8706653571f9f5b81a833326d0b04dd281eaf006c46842250d"></a><a name="gga8ef30fa9c08e08c8706653571f9f5b81a833326d0b04dd281eaf006c46842250d"></a></strong>INPUT_TYPE</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p475220620165623"><a name="p475220620165623"></a><a name="p475220620165623"></a>Input</p>
<p id="p4868182315204"><a name="p4868182315204"></a><a name="p4868182315204"></a></p>
</td>
</tr>
<tr id="row1481585221165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1590564074165623p0"><a name="entry1590564074165623p0"></a><a name="entry1590564074165623p0"></a><strong id="gga8ef30fa9c08e08c8706653571f9f5b81a9e3da5a3721894f1552c2715c1fbe95c"><a name="gga8ef30fa9c08e08c8706653571f9f5b81a9e3da5a3721894f1552c2715c1fbe95c"></a><a name="gga8ef30fa9c08e08c8706653571f9f5b81a9e3da5a3721894f1552c2715c1fbe95c"></a></strong>OUTPUT_TYPE</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1470418476165623"><a name="p1470418476165623"></a><a name="p1470418476165623"></a>Output</p>
<p id="p486811235202"><a name="p486811235202"></a><a name="p486811235202"></a></p>
</td>
</tr>
<tr id="row1060852790165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1319057491165623p0"><a name="entry1319057491165623p0"></a><a name="entry1319057491165623p0"></a><strong id="gga8ef30fa9c08e08c8706653571f9f5b81a46bcae2d9d2268e6a0c9259b9aebfc2f"><a name="gga8ef30fa9c08e08c8706653571f9f5b81a46bcae2d9d2268e6a0c9259b9aebfc2f"></a><a name="gga8ef30fa9c08e08c8706653571f9f5b81a46bcae2d9d2268e6a0c9259b9aebfc2f"></a></strong>ALL_TYPE</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1885465143165623"><a name="p1885465143165623"></a><a name="p1885465143165623"></a>Input and output</p>
<p id="p586812313201"><a name="p586812313201"></a><a name="p586812313201"></a></p>
</td>
</tr>
</tbody>
</table>

## EventType<a name="ga2628ea8d12e8b2563c32f05dc7fff6fa"></a>

```
enum [EventType](Codec.md#ga2628ea8d12e8b2563c32f05dc7fff6fa)
```

**Description:**

Enumerates event types.

<a name="table417126154165623"></a>
<table><thead align="left"><tr id="row1459920575165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1607692234165623"><a name="p1607692234165623"></a><a name="p1607692234165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p20529969165623"><a name="p20529969165623"></a><a name="p20529969165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row571450358165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1768184909165623p0"><a name="entry1768184909165623p0"></a><a name="entry1768184909165623p0"></a><strong id="gga2628ea8d12e8b2563c32f05dc7fff6faa71cf6bf1e591a86cb536668cda0f2a00"><a name="gga2628ea8d12e8b2563c32f05dc7fff6faa71cf6bf1e591a86cb536668cda0f2a00"></a><a name="gga2628ea8d12e8b2563c32f05dc7fff6faa71cf6bf1e591a86cb536668cda0f2a00"></a></strong>EventError</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p522772165623"><a name="p522772165623"></a><a name="p522772165623"></a>Event error</p>
<p id="p9871623142013"><a name="p9871623142013"></a><a name="p9871623142013"></a></p>
</td>
</tr>
<tr id="row1330535883165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1881594220165623p0"><a name="entry1881594220165623p0"></a><a name="entry1881594220165623p0"></a><strong id="gga2628ea8d12e8b2563c32f05dc7fff6faaab9f6e22232b045b85118bdda8aac6db"><a name="gga2628ea8d12e8b2563c32f05dc7fff6faaab9f6e22232b045b85118bdda8aac6db"></a><a name="gga2628ea8d12e8b2563c32f05dc7fff6faaab9f6e22232b045b85118bdda8aac6db"></a></strong>EventFlushCompelte</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1934473705165623"><a name="p1934473705165623"></a><a name="p1934473705165623"></a>Buffer flush completed</p>
<p id="p5871112314204"><a name="p5871112314204"></a><a name="p5871112314204"></a></p>
</td>
</tr>
<tr id="row1375243555165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1332016132165623p0"><a name="entry1332016132165623p0"></a><a name="entry1332016132165623p0"></a><strong id="gga2628ea8d12e8b2563c32f05dc7fff6faa864f301176ff05ad003bc6e89eb2cb93"><a name="gga2628ea8d12e8b2563c32f05dc7fff6faa864f301176ff05ad003bc6e89eb2cb93"></a><a name="gga2628ea8d12e8b2563c32f05dc7fff6faa864f301176ff05ad003bc6e89eb2cb93"></a></strong>EventStopCompelte</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2120377777165623"><a name="p2120377777165623"></a><a name="p2120377777165623"></a>Codec stopped</p>
<p id="p1587118231209"><a name="p1587118231209"></a><a name="p1587118231209"></a></p>
</td>
</tr>
<tr id="row1869457576165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry38737689165623p0"><a name="entry38737689165623p0"></a><a name="entry38737689165623p0"></a><strong id="gga2628ea8d12e8b2563c32f05dc7fff6faaeb0fb0bb31b20a141d015d9a92c629ac"><a name="gga2628ea8d12e8b2563c32f05dc7fff6faaeb0fb0bb31b20a141d015d9a92c629ac"></a><a name="gga2628ea8d12e8b2563c32f05dc7fff6faaeb0fb0bb31b20a141d015d9a92c629ac"></a></strong>EventOutFormatChanged</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p574548242165623"><a name="p574548242165623"></a><a name="p574548242165623"></a>Output format changed</p>
<p id="p1871923122018"><a name="p1871923122018"></a><a name="p1871923122018"></a></p>
</td>
</tr>
<tr id="row409045115165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1304593436165623p0"><a name="entry1304593436165623p0"></a><a name="entry1304593436165623p0"></a><strong id="gga2628ea8d12e8b2563c32f05dc7fff6faa70203255ab263a903886b8f774d5c4aa"><a name="gga2628ea8d12e8b2563c32f05dc7fff6faa70203255ab263a903886b8f774d5c4aa"></a><a name="gga2628ea8d12e8b2563c32f05dc7fff6faa70203255ab263a903886b8f774d5c4aa"></a></strong>EventMax</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p977978531165623"><a name="p977978531165623"></a><a name="p977978531165623"></a>Maximum event value</p>
<p id="p4871152310209"><a name="p4871152310209"></a><a name="p4871152310209"></a></p>
</td>
</tr>
</tbody>
</table>

## Level<a name="ga221b779e6bb7b8d40677d7642bfefac5"></a>

```
enum [Level](Codec.md#ga221b779e6bb7b8d40677d7642bfefac5)
```

**Description:**

Enumerates codec levels.

<a name="table2127378080165623"></a>
<table><thead align="left"><tr id="row877354063165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1471038623165623"><a name="p1471038623165623"></a><a name="p1471038623165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1496199969165623"><a name="p1496199969165623"></a><a name="p1496199969165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row787750475165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry107710351165623p0"><a name="entry107710351165623p0"></a><a name="entry107710351165623p0"></a><strong id="gga221b779e6bb7b8d40677d7642bfefac5a6ab1f388a1a94d680bcbe808ec45a082"><a name="gga221b779e6bb7b8d40677d7642bfefac5a6ab1f388a1a94d680bcbe808ec45a082"></a><a name="gga221b779e6bb7b8d40677d7642bfefac5a6ab1f388a1a94d680bcbe808ec45a082"></a></strong>INVALID_LEVEL</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p38732216165623"><a name="p38732216165623"></a><a name="p38732216165623"></a>Invalid level</p>
<p id="p587617236207"><a name="p587617236207"></a><a name="p587617236207"></a></p>
</td>
</tr>
<tr id="row1110739428165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry948703963165623p0"><a name="entry948703963165623p0"></a><a name="entry948703963165623p0"></a><strong id="gga221b779e6bb7b8d40677d7642bfefac5aee353b803bd93ba9e01e99e67b8afb49"><a name="gga221b779e6bb7b8d40677d7642bfefac5aee353b803bd93ba9e01e99e67b8afb49"></a><a name="gga221b779e6bb7b8d40677d7642bfefac5aee353b803bd93ba9e01e99e67b8afb49"></a></strong>AVC_LEVEL_1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1570442161165623"><a name="p1570442161165623"></a><a name="p1570442161165623"></a>H.264 level 1</p>
<p id="p148765230200"><a name="p148765230200"></a><a name="p148765230200"></a></p>
</td>
</tr>
<tr id="row127745001165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry48131624165623p0"><a name="entry48131624165623p0"></a><a name="entry48131624165623p0"></a><strong id="gga221b779e6bb7b8d40677d7642bfefac5a25819fec0bd7476c85122100b61536bb"><a name="gga221b779e6bb7b8d40677d7642bfefac5a25819fec0bd7476c85122100b61536bb"></a><a name="gga221b779e6bb7b8d40677d7642bfefac5a25819fec0bd7476c85122100b61536bb"></a></strong>HEVC_LEVEL_MAIN_1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p720900386165623"><a name="p720900386165623"></a><a name="p720900386165623"></a>H.265 Main level 1</p>
<p id="p1387614236204"><a name="p1387614236204"></a><a name="p1387614236204"></a></p>
</td>
</tr>
<tr id="row957513397165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1393101236165623p0"><a name="entry1393101236165623p0"></a><a name="entry1393101236165623p0"></a><strong id="gga221b779e6bb7b8d40677d7642bfefac5ab21d7836b0849b87149b7cdd7924d862"><a name="gga221b779e6bb7b8d40677d7642bfefac5ab21d7836b0849b87149b7cdd7924d862"></a><a name="gga221b779e6bb7b8d40677d7642bfefac5ab21d7836b0849b87149b7cdd7924d862"></a></strong>HEVC_LEVEL_MAIN_2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1314976353165623"><a name="p1314976353165623"></a><a name="p1314976353165623"></a>H.265 Main level 2</p>
<p id="p487617236206"><a name="p487617236206"></a><a name="p487617236206"></a></p>
</td>
</tr>
</tbody>
</table>

## ParamKey<a name="ga575c56a2d6b42c48881cf47b0008d5a6"></a>

```
enum [ParamKey](Codec.md#ga575c56a2d6b42c48881cf47b0008d5a6)
```

**Description:**

Enumerates indexes of parameter types.

<a name="table1801126435165623"></a>
<table><thead align="left"><tr id="row682037542165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p138286845165623"><a name="p138286845165623"></a><a name="p138286845165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1843819628165623"><a name="p1843819628165623"></a><a name="p1843819628165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1975638208165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry727353088165623p0"><a name="entry727353088165623p0"></a><a name="entry727353088165623p0"></a><strong id="gga575c56a2d6b42c48881cf47b0008d5a6aef2a08e0112230b41df402fd38efc1ed"><a name="gga575c56a2d6b42c48881cf47b0008d5a6aef2a08e0112230b41df402fd38efc1ed"></a><a name="gga575c56a2d6b42c48881cf47b0008d5a6aef2a08e0112230b41df402fd38efc1ed"></a></strong>KEY_MIMETYPE</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p235806553165623"><a name="p235806553165623"></a><a name="p235806553165623"></a>MIME type. For the value type, see <a href="Codec.md#ga1bee586eafa91dfb60f94ba40fc95faa">AvCodecMime</a>.</p>
<p id="p11880323152017"><a name="p11880323152017"></a><a name="p11880323152017"></a></p>
</td>
</tr>
<tr id="row1628489182165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2106120079165623p0"><a name="entry2106120079165623p0"></a><a name="entry2106120079165623p0"></a><strong id="gga575c56a2d6b42c48881cf47b0008d5a6a2c86d69eb4995dbadfdb6d289834f7f2"><a name="gga575c56a2d6b42c48881cf47b0008d5a6a2c86d69eb4995dbadfdb6d289834f7f2"></a><a name="gga575c56a2d6b42c48881cf47b0008d5a6a2c86d69eb4995dbadfdb6d289834f7f2"></a></strong>KEY_BUFFERSIZE</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1731662001165623"><a name="p1731662001165623"></a><a name="p1731662001165623"></a>Buffer size. The value type is uint32_t.</p>
<p id="p1188018232208"><a name="p1188018232208"></a><a name="p1188018232208"></a></p>
</td>
</tr>
<tr id="row2073531349165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry612017806165623p0"><a name="entry612017806165623p0"></a><a name="entry612017806165623p0"></a><strong id="gga575c56a2d6b42c48881cf47b0008d5a6a4c97de4e44d3c9778530ddd2cffe1728"><a name="gga575c56a2d6b42c48881cf47b0008d5a6a4c97de4e44d3c9778530ddd2cffe1728"></a><a name="gga575c56a2d6b42c48881cf47b0008d5a6a4c97de4e44d3c9778530ddd2cffe1728"></a></strong>KEY_LEFT_STREAM_FRAMES</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p893539940165623"><a name="p893539940165623"></a><a name="p893539940165623"></a>Number of frames in the remaining data streams. The value type is uint32_t.</p>
<p id="p15880142315208"><a name="p15880142315208"></a><a name="p15880142315208"></a></p>
</td>
</tr>
<tr id="row1106461597165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1722145969165623p0"><a name="entry1722145969165623p0"></a><a name="entry1722145969165623p0"></a><strong id="gga575c56a2d6b42c48881cf47b0008d5a6ac3e2aece8c07c078567996464d654e5a"><a name="gga575c56a2d6b42c48881cf47b0008d5a6ac3e2aece8c07c078567996464d654e5a"></a><a name="gga575c56a2d6b42c48881cf47b0008d5a6ac3e2aece8c07c078567996464d654e5a"></a></strong>KEY_CODEC_TYPE</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p486117370165623"><a name="p486117370165623"></a><a name="p486117370165623"></a>Codec type. For the value type, see <a href="Codec.md#ga03b4b6ae5fb82af68d46aaea3d3e4d79">CodecType</a>.</p>
<p id="p1488092313207"><a name="p1488092313207"></a><a name="p1488092313207"></a></p>
</td>
</tr>
<tr id="row1185793488165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry153679744165623p0"><a name="entry153679744165623p0"></a><a name="entry153679744165623p0"></a><strong id="gga575c56a2d6b42c48881cf47b0008d5a6ac1ff343954a9a979fd49bf6ef80d2589"><a name="gga575c56a2d6b42c48881cf47b0008d5a6ac1ff343954a9a979fd49bf6ef80d2589"></a><a name="gga575c56a2d6b42c48881cf47b0008d5a6ac1ff343954a9a979fd49bf6ef80d2589"></a></strong>KEY_DIRECTION_TYPE</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p631080540165623"><a name="p631080540165623"></a><a name="p631080540165623"></a>Input/Output type. For the value type, see <a href="Codec.md#ga8ef30fa9c08e08c8706653571f9f5b81">DirectionType</a>.</p>
<p id="p788015231208"><a name="p788015231208"></a><a name="p788015231208"></a></p>
</td>
</tr>
<tr id="row1290091283165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1002515727165623p0"><a name="entry1002515727165623p0"></a><a name="entry1002515727165623p0"></a><strong id="gga575c56a2d6b42c48881cf47b0008d5a6ad8c37ded7037d0e1eeb6e477ff72492f"><a name="gga575c56a2d6b42c48881cf47b0008d5a6ad8c37ded7037d0e1eeb6e477ff72492f"></a><a name="gga575c56a2d6b42c48881cf47b0008d5a6ad8c37ded7037d0e1eeb6e477ff72492f"></a></strong>KEY_BITRATE</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1676729334165623"><a name="p1676729334165623"></a><a name="p1676729334165623"></a>Bit rate. The value type is uint32_t.</p>
<p id="p6880172320207"><a name="p6880172320207"></a><a name="p6880172320207"></a></p>
</td>
</tr>
<tr id="row192914355165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1849026113165623p0"><a name="entry1849026113165623p0"></a><a name="entry1849026113165623p0"></a><strong id="gga575c56a2d6b42c48881cf47b0008d5a6adab65ac6751535b13f6275dbfa1ba90e"><a name="gga575c56a2d6b42c48881cf47b0008d5a6adab65ac6751535b13f6275dbfa1ba90e"></a><a name="gga575c56a2d6b42c48881cf47b0008d5a6adab65ac6751535b13f6275dbfa1ba90e"></a></strong>KEY_WIDTH</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1224100877165623"><a name="p1224100877165623"></a><a name="p1224100877165623"></a>Width. The value type is uint32_t.</p>
<p id="p15880142362020"><a name="p15880142362020"></a><a name="p15880142362020"></a></p>
</td>
</tr>
<tr id="row102337092165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2088057006165623p0"><a name="entry2088057006165623p0"></a><a name="entry2088057006165623p0"></a><strong id="gga575c56a2d6b42c48881cf47b0008d5a6a78fd0c2ba5fb7894ec4a164ff2b119b8"><a name="gga575c56a2d6b42c48881cf47b0008d5a6a78fd0c2ba5fb7894ec4a164ff2b119b8"></a><a name="gga575c56a2d6b42c48881cf47b0008d5a6a78fd0c2ba5fb7894ec4a164ff2b119b8"></a></strong>KEY_HEIGHT</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1730292767165623"><a name="p1730292767165623"></a><a name="p1730292767165623"></a>Hight. The value type is uint32_t.</p>
<p id="p1188002317208"><a name="p1188002317208"></a><a name="p1188002317208"></a></p>
</td>
</tr>
<tr id="row372607052165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1610681409165623p0"><a name="entry1610681409165623p0"></a><a name="entry1610681409165623p0"></a><strong id="gga575c56a2d6b42c48881cf47b0008d5a6ad25b08a51da92cb8928402bd2a99ec60"><a name="gga575c56a2d6b42c48881cf47b0008d5a6ad25b08a51da92cb8928402bd2a99ec60"></a><a name="gga575c56a2d6b42c48881cf47b0008d5a6ad25b08a51da92cb8928402bd2a99ec60"></a></strong>KEY_STRIDE</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p308011453165623"><a name="p308011453165623"></a><a name="p308011453165623"></a>Stride. The value type is uint32_t.</p>
<p id="p12880132318202"><a name="p12880132318202"></a><a name="p12880132318202"></a></p>
</td>
</tr>
<tr id="row1061588090165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1918751782165623p0"><a name="entry1918751782165623p0"></a><a name="entry1918751782165623p0"></a><strong id="gga575c56a2d6b42c48881cf47b0008d5a6ae45fd20d699c2a40110d510c26e2b0bb"><a name="gga575c56a2d6b42c48881cf47b0008d5a6ae45fd20d699c2a40110d510c26e2b0bb"></a><a name="gga575c56a2d6b42c48881cf47b0008d5a6ae45fd20d699c2a40110d510c26e2b0bb"></a></strong>KEY_VIDEO_FIELD</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1675945569165623"><a name="p1675945569165623"></a><a name="p1675945569165623"></a>Video field. For the value type, see <a href="Codec.md#ga1420ddfb066b941fb55a153b869d9ccf">VideoField</a>.</p>
<p id="p1988014231206"><a name="p1988014231206"></a><a name="p1988014231206"></a></p>
</td>
</tr>
<tr id="row48823122165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry295568979165623p0"><a name="entry295568979165623p0"></a><a name="entry295568979165623p0"></a><strong id="gga575c56a2d6b42c48881cf47b0008d5a6a8b4fdf85f17f5bb549236a6280e36328"><a name="gga575c56a2d6b42c48881cf47b0008d5a6a8b4fdf85f17f5bb549236a6280e36328"></a><a name="gga575c56a2d6b42c48881cf47b0008d5a6a8b4fdf85f17f5bb549236a6280e36328"></a></strong>KEY_PIXEL_FORMAT</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1178607186165623"><a name="p1178607186165623"></a><a name="p1178607186165623"></a>Pixel format. For the value type, see <a href="Display.md#ga60883d4958a60b91661e97027a85072a">PixelFormat</a>.</p>
<p id="p08801823132019"><a name="p08801823132019"></a><a name="p08801823132019"></a></p>
</td>
</tr>
<tr id="row780615280165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry491024963165623p0"><a name="entry491024963165623p0"></a><a name="entry491024963165623p0"></a><strong id="gga575c56a2d6b42c48881cf47b0008d5a6abed5c9737ae85a1771f6d065692fdab1"><a name="gga575c56a2d6b42c48881cf47b0008d5a6abed5c9737ae85a1771f6d065692fdab1"></a><a name="gga575c56a2d6b42c48881cf47b0008d5a6abed5c9737ae85a1771f6d065692fdab1"></a></strong>KEY_VIDEO_RC_MODE</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p421372812165623"><a name="p421372812165623"></a><a name="p421372812165623"></a>Rate control mode. For the value type, see <a href="Codec.md#ga94267d7ba495136561e1c65686b240f7">VenCodeRcMode</a>.</p>
<p id="p388015238208"><a name="p388015238208"></a><a name="p388015238208"></a></p>
</td>
</tr>
<tr id="row2109553406165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1860682926165623p0"><a name="entry1860682926165623p0"></a><a name="entry1860682926165623p0"></a><strong id="gga575c56a2d6b42c48881cf47b0008d5a6aae6cd2e1f70f313300e8579d2c6befbc"><a name="gga575c56a2d6b42c48881cf47b0008d5a6aae6cd2e1f70f313300e8579d2c6befbc"></a><a name="gga575c56a2d6b42c48881cf47b0008d5a6aae6cd2e1f70f313300e8579d2c6befbc"></a></strong>KEY_VIDEO_GOP_MODE</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1747581768165623"><a name="p1747581768165623"></a><a name="p1747581768165623"></a>GOP mode. For the value type, see <a href="Codec.md#ga9532f651a003219a262c440f5621d129">VenCodeGopMode</a>.</p>
<p id="p168801723162014"><a name="p168801723162014"></a><a name="p168801723162014"></a></p>
</td>
</tr>
<tr id="row479082179165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1726151480165623p0"><a name="entry1726151480165623p0"></a><a name="entry1726151480165623p0"></a><strong id="gga575c56a2d6b42c48881cf47b0008d5a6a19a23598acca8b0d1dfa8bb48f58a7ef"><a name="gga575c56a2d6b42c48881cf47b0008d5a6a19a23598acca8b0d1dfa8bb48f58a7ef"></a><a name="gga575c56a2d6b42c48881cf47b0008d5a6a19a23598acca8b0d1dfa8bb48f58a7ef"></a></strong>KEY_VIDEO_PIC_SIZE</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p411518873165623"><a name="p411518873165623"></a><a name="p411518873165623"></a>Image resolution. For the value type, see <a href="Codec.md#ga94981b885085085ed5f9dea406519b48">PicSize</a>.</p>
<p id="p1288032342018"><a name="p1288032342018"></a><a name="p1288032342018"></a></p>
</td>
</tr>
<tr id="row629248175165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry181861693165623p0"><a name="entry181861693165623p0"></a><a name="entry181861693165623p0"></a><strong id="gga575c56a2d6b42c48881cf47b0008d5a6ab05b2fdf7c66accbce8bd4c5689dbe31"><a name="gga575c56a2d6b42c48881cf47b0008d5a6ab05b2fdf7c66accbce8bd4c5689dbe31"></a><a name="gga575c56a2d6b42c48881cf47b0008d5a6ab05b2fdf7c66accbce8bd4c5689dbe31"></a></strong>KEY_VIDEO_PROFILE</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p872067175165623"><a name="p872067175165623"></a><a name="p872067175165623"></a>Codec profile. The value type is uint32_t.</p>
<p id="p17880162316207"><a name="p17880162316207"></a><a name="p17880162316207"></a></p>
</td>
</tr>
<tr id="row999739567165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1569273394165623p0"><a name="entry1569273394165623p0"></a><a name="entry1569273394165623p0"></a><strong id="gga575c56a2d6b42c48881cf47b0008d5a6acdfdfbe59769faa9eb22c7fabf99ab77"><a name="gga575c56a2d6b42c48881cf47b0008d5a6acdfdfbe59769faa9eb22c7fabf99ab77"></a><a name="gga575c56a2d6b42c48881cf47b0008d5a6acdfdfbe59769faa9eb22c7fabf99ab77"></a></strong>KEY_VIDEO_FRAME_RATE</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1253393866165623"><a name="p1253393866165623"></a><a name="p1253393866165623"></a>Frame rate. The value type is uint32_t.</p>
<p id="p1688002313208"><a name="p1688002313208"></a><a name="p1688002313208"></a></p>
</td>
</tr>
<tr id="row2119351102165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry506014251165623p0"><a name="entry506014251165623p0"></a><a name="entry506014251165623p0"></a><strong id="gga575c56a2d6b42c48881cf47b0008d5a6aa4b816f352799fbbbe85f3c5d91640ff"><a name="gga575c56a2d6b42c48881cf47b0008d5a6aa4b816f352799fbbbe85f3c5d91640ff"></a><a name="gga575c56a2d6b42c48881cf47b0008d5a6aa4b816f352799fbbbe85f3c5d91640ff"></a></strong>KEY_IMAGE_Q_FACTOR</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1327990620165623"><a name="p1327990620165623"></a><a name="p1327990620165623"></a>Quality factor, range is [1, 99]. The value type is uint32_t</p>
<p id="p5880923142013"><a name="p5880923142013"></a><a name="p5880923142013"></a></p>
</td>
</tr>
<tr id="row992715831165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1220921705165623p0"><a name="entry1220921705165623p0"></a><a name="entry1220921705165623p0"></a><strong id="gga575c56a2d6b42c48881cf47b0008d5a6a513f3e7cbf10667949bd2f276b43227e"><a name="gga575c56a2d6b42c48881cf47b0008d5a6a513f3e7cbf10667949bd2f276b43227e"></a><a name="gga575c56a2d6b42c48881cf47b0008d5a6a513f3e7cbf10667949bd2f276b43227e"></a></strong>KEY_SAMPLE_RATE</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p930147465165623"><a name="p930147465165623"></a><a name="p930147465165623"></a>Sampling rate. The value type is uint32_t.</p>
<p id="p158809234208"><a name="p158809234208"></a><a name="p158809234208"></a></p>
</td>
</tr>
<tr id="row517470398165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry787700553165623p0"><a name="entry787700553165623p0"></a><a name="entry787700553165623p0"></a><strong id="gga575c56a2d6b42c48881cf47b0008d5a6a1a00600fff0e7a378bc0c690451f1040"><a name="gga575c56a2d6b42c48881cf47b0008d5a6a1a00600fff0e7a378bc0c690451f1040"></a><a name="gga575c56a2d6b42c48881cf47b0008d5a6a1a00600fff0e7a378bc0c690451f1040"></a></strong>KEY_AUDIO_PROFILE</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1760623495165623"><a name="p1760623495165623"></a><a name="p1760623495165623"></a>Audio encoding profile. The value type is uint32_t.</p>
<p id="p38801723142019"><a name="p38801723142019"></a><a name="p38801723142019"></a></p>
</td>
</tr>
<tr id="row1207289762165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry674639896165623p0"><a name="entry674639896165623p0"></a><a name="entry674639896165623p0"></a><strong id="gga575c56a2d6b42c48881cf47b0008d5a6a8c791931da4303642db329af0bb383a8"><a name="gga575c56a2d6b42c48881cf47b0008d5a6a8c791931da4303642db329af0bb383a8"></a><a name="gga575c56a2d6b42c48881cf47b0008d5a6a8c791931da4303642db329af0bb383a8"></a></strong>KEY_CHANNEL_COUNT</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p788639487165623"><a name="p788639487165623"></a><a name="p788639487165623"></a>Number of channels. The value type is uint32_t.</p>
<p id="p11880152342019"><a name="p11880152342019"></a><a name="p11880152342019"></a></p>
</td>
</tr>
<tr id="row986654710165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry412815366165623p0"><a name="entry412815366165623p0"></a><a name="entry412815366165623p0"></a><strong id="gga575c56a2d6b42c48881cf47b0008d5a6ae054dfca35dd75e795aa9af83390a4fd"><a name="gga575c56a2d6b42c48881cf47b0008d5a6ae054dfca35dd75e795aa9af83390a4fd"></a><a name="gga575c56a2d6b42c48881cf47b0008d5a6ae054dfca35dd75e795aa9af83390a4fd"></a></strong>KEY_BITWITH</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1394941565165623"><a name="p1394941565165623"></a><a name="p1394941565165623"></a>Bit width. For the value type, see <a href="MultiMedia_MediaCommon.md#gae3e35ee2a2222a667fdebbc5b793ca7c">AudioBitWidth</a>.</p>
<p id="p68801232200"><a name="p68801232200"></a><a name="p68801232200"></a></p>
</td>
</tr>
<tr id="row1466165253165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1750244304165623p0"><a name="entry1750244304165623p0"></a><a name="entry1750244304165623p0"></a><strong id="gga575c56a2d6b42c48881cf47b0008d5a6ade681ad9e4e270d52ed2127dc86a90c7"><a name="gga575c56a2d6b42c48881cf47b0008d5a6ade681ad9e4e270d52ed2127dc86a90c7"></a><a name="gga575c56a2d6b42c48881cf47b0008d5a6ade681ad9e4e270d52ed2127dc86a90c7"></a></strong>KEY_SOUND_MODE</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1291436215165623"><a name="p1291436215165623"></a><a name="p1291436215165623"></a>Audio channel mode. For the value type, see <a href="Codec.md#gacecb40e35c431a27385f7b439fc7a76c">AudioSoundMode</a>.</p>
<p id="p1588062362016"><a name="p1588062362016"></a><a name="p1588062362016"></a></p>
</td>
</tr>
<tr id="row1544183585165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry184760452165623p0"><a name="entry184760452165623p0"></a><a name="entry184760452165623p0"></a><strong id="gga575c56a2d6b42c48881cf47b0008d5a6ab6ca06e65b7ee9808e07389507555b48"><a name="gga575c56a2d6b42c48881cf47b0008d5a6ab6ca06e65b7ee9808e07389507555b48"></a><a name="gga575c56a2d6b42c48881cf47b0008d5a6ab6ca06e65b7ee9808e07389507555b48"></a></strong>KEY_POINT_NUM_PER_FRAME</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p487679614165623"><a name="p487679614165623"></a><a name="p487679614165623"></a>Number of sampling points per frame. The value type is uint32_t.</p>
<p id="p198813239209"><a name="p198813239209"></a><a name="p198813239209"></a></p>
</td>
</tr>
<tr id="row1279979647165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1526619422165623p0"><a name="entry1526619422165623p0"></a><a name="entry1526619422165623p0"></a><strong id="gga575c56a2d6b42c48881cf47b0008d5a6a15bf33195ec3c6067084aa3fa047cad2"><a name="gga575c56a2d6b42c48881cf47b0008d5a6a15bf33195ec3c6067084aa3fa047cad2"></a><a name="gga575c56a2d6b42c48881cf47b0008d5a6a15bf33195ec3c6067084aa3fa047cad2"></a></strong>KEY_DEVICE_ID</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p873391156165623"><a name="p873391156165623"></a><a name="p873391156165623"></a>Device ID. The value type is uint32_t.</p>
<p id="p388152352016"><a name="p388152352016"></a><a name="p388152352016"></a></p>
</td>
</tr>
</tbody>
</table>

## PicSize<a name="ga94981b885085085ed5f9dea406519b48"></a>

```
enum [PicSize](Codec.md#ga94981b885085085ed5f9dea406519b48)
```

**Description:**

Enumerates resolutions.

<a name="table2016602138165623"></a>
<table><thead align="left"><tr id="row928226775165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1927480566165623"><a name="p1927480566165623"></a><a name="p1927480566165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2112732409165623"><a name="p2112732409165623"></a><a name="p2112732409165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row148720195165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry415704533165623p0"><a name="entry415704533165623p0"></a><a name="entry415704533165623p0"></a><strong id="gga94981b885085085ed5f9dea406519b48a373065e30654b1d097cb9725bec88962"><a name="gga94981b885085085ed5f9dea406519b48a373065e30654b1d097cb9725bec88962"></a><a name="gga94981b885085085ed5f9dea406519b48a373065e30654b1d097cb9725bec88962"></a></strong>Resolution_CIF</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1488351345165623"><a name="p1488351345165623"></a><a name="p1488351345165623"></a>352x288</p>
<p id="p189772313201"><a name="p189772313201"></a><a name="p189772313201"></a></p>
</td>
</tr>
<tr id="row1769834883165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry44255525165623p0"><a name="entry44255525165623p0"></a><a name="entry44255525165623p0"></a><strong id="gga94981b885085085ed5f9dea406519b48af6b390500e92b07d1c8829c7ce13fc9b"><a name="gga94981b885085085ed5f9dea406519b48af6b390500e92b07d1c8829c7ce13fc9b"></a><a name="gga94981b885085085ed5f9dea406519b48af6b390500e92b07d1c8829c7ce13fc9b"></a></strong>Resolution_360P</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1954215038165623"><a name="p1954215038165623"></a><a name="p1954215038165623"></a>640x360</p>
<p id="p3897112332019"><a name="p3897112332019"></a><a name="p3897112332019"></a></p>
</td>
</tr>
<tr id="row371683006165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry895332608165623p0"><a name="entry895332608165623p0"></a><a name="entry895332608165623p0"></a><strong id="gga94981b885085085ed5f9dea406519b48a7662d5257ffca575be7f343015f3e6ab"><a name="gga94981b885085085ed5f9dea406519b48a7662d5257ffca575be7f343015f3e6ab"></a><a name="gga94981b885085085ed5f9dea406519b48a7662d5257ffca575be7f343015f3e6ab"></a></strong>Resolution_D1_PAL</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p819703181165623"><a name="p819703181165623"></a><a name="p819703181165623"></a>720x576</p>
<p id="p789718234209"><a name="p789718234209"></a><a name="p789718234209"></a></p>
</td>
</tr>
<tr id="row1330538845165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry571740924165623p0"><a name="entry571740924165623p0"></a><a name="entry571740924165623p0"></a><strong id="gga94981b885085085ed5f9dea406519b48ae2644966a8e6b6595f90bc950fa9673d"><a name="gga94981b885085085ed5f9dea406519b48ae2644966a8e6b6595f90bc950fa9673d"></a><a name="gga94981b885085085ed5f9dea406519b48ae2644966a8e6b6595f90bc950fa9673d"></a></strong>Resolution_D1_NTSC</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p481417079165623"><a name="p481417079165623"></a><a name="p481417079165623"></a>720x480</p>
<p id="p889782317207"><a name="p889782317207"></a><a name="p889782317207"></a></p>
</td>
</tr>
<tr id="row1330209254165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1565592855165623p0"><a name="entry1565592855165623p0"></a><a name="entry1565592855165623p0"></a><strong id="gga94981b885085085ed5f9dea406519b48ae6d83a5bdf1b754df6dc23b07d781a5e"><a name="gga94981b885085085ed5f9dea406519b48ae6d83a5bdf1b754df6dc23b07d781a5e"></a><a name="gga94981b885085085ed5f9dea406519b48ae6d83a5bdf1b754df6dc23b07d781a5e"></a></strong>Resolution_720P</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1071229828165623"><a name="p1071229828165623"></a><a name="p1071229828165623"></a>1280x720</p>
<p id="p14897123172019"><a name="p14897123172019"></a><a name="p14897123172019"></a></p>
</td>
</tr>
<tr id="row58516742165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1896610662165623p0"><a name="entry1896610662165623p0"></a><a name="entry1896610662165623p0"></a><strong id="gga94981b885085085ed5f9dea406519b48a460ffc02a1f90e6194fca5f1fcfb513b"><a name="gga94981b885085085ed5f9dea406519b48a460ffc02a1f90e6194fca5f1fcfb513b"></a><a name="gga94981b885085085ed5f9dea406519b48a460ffc02a1f90e6194fca5f1fcfb513b"></a></strong>Resolution_1080P</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1826243365165623"><a name="p1826243365165623"></a><a name="p1826243365165623"></a>1920x1080</p>
<p id="p10897523182013"><a name="p10897523182013"></a><a name="p10897523182013"></a></p>
</td>
</tr>
<tr id="row1398840341165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1830628919165623p0"><a name="entry1830628919165623p0"></a><a name="entry1830628919165623p0"></a><strong id="gga94981b885085085ed5f9dea406519b48ae26dfcd8b806ea2ec7236f5a43dba1a2"><a name="gga94981b885085085ed5f9dea406519b48ae26dfcd8b806ea2ec7236f5a43dba1a2"></a><a name="gga94981b885085085ed5f9dea406519b48ae26dfcd8b806ea2ec7236f5a43dba1a2"></a></strong>Resolution_INVALID</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1790987043165623"><a name="p1790987043165623"></a><a name="p1790987043165623"></a>Invalid resolution</p>
<p id="p1089714233203"><a name="p1089714233203"></a><a name="p1089714233203"></a></p>
</td>
</tr>
</tbody>
</table>

## PixelFormat<a name="ga60883d4958a60b91661e97027a85072a"></a>

```
enum [PixelFormat](Codec.md#ga60883d4958a60b91661e97027a85072a)
```

**Description:**

Enumerates pixel formats.

<a name="table813437920165623"></a>
<table><thead align="left"><tr id="row228254976165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1771787042165623"><a name="p1771787042165623"></a><a name="p1771787042165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1253382963165623"><a name="p1253382963165623"></a><a name="p1253382963165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1641782128165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry64317691165623p0"><a name="entry64317691165623p0"></a><a name="entry64317691165623p0"></a><strong id="gga60883d4958a60b91661e97027a85072aa442172344e87ea7d96a7675112f2a544"><a name="gga60883d4958a60b91661e97027a85072aa442172344e87ea7d96a7675112f2a544"></a><a name="gga60883d4958a60b91661e97027a85072aa442172344e87ea7d96a7675112f2a544"></a></strong>YVU_SEMIPLANAR_420</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p152027085165623"><a name="p152027085165623"></a><a name="p152027085165623"></a>YUV 420 SP</p>
<p id="p9903182312201"><a name="p9903182312201"></a><a name="p9903182312201"></a></p>
</td>
</tr>
<tr id="row281087380165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1690581398165623p0"><a name="entry1690581398165623p0"></a><a name="entry1690581398165623p0"></a><strong id="gga60883d4958a60b91661e97027a85072aac31c324ea9de2f481f8836586ed270b4"><a name="gga60883d4958a60b91661e97027a85072aac31c324ea9de2f481f8836586ed270b4"></a><a name="gga60883d4958a60b91661e97027a85072aac31c324ea9de2f481f8836586ed270b4"></a></strong>YVU_SEMIPLANAR_420_TILE</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p859161972165623"><a name="p859161972165623"></a><a name="p859161972165623"></a>YUV SP 420 TILE</p>
<p id="p139033238202"><a name="p139033238202"></a><a name="p139033238202"></a></p>
</td>
</tr>
<tr id="row719255236165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry937265294165623p0"><a name="entry937265294165623p0"></a><a name="entry937265294165623p0"></a><strong id="gga60883d4958a60b91661e97027a85072aa2518a2ff4cd9bda80aab9ddbc7477a32"><a name="gga60883d4958a60b91661e97027a85072aa2518a2ff4cd9bda80aab9ddbc7477a32"></a><a name="gga60883d4958a60b91661e97027a85072aa2518a2ff4cd9bda80aab9ddbc7477a32"></a></strong>PIX_FORMAT_INVALID</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p760880226165623"><a name="p760880226165623"></a><a name="p760880226165623"></a>Invalid format</p>
<p id="p11903623142014"><a name="p11903623142014"></a><a name="p11903623142014"></a></p>
</td>
</tr>
</tbody>
</table>

## Profile<a name="ga85b10143618f300ff4f5bc6d45c72c01"></a>

```
enum [Profile](Codec.md#ga85b10143618f300ff4f5bc6d45c72c01)
```

**Description:**

Enumerates codec profiles.

<a name="table1112623909165623"></a>
<table><thead align="left"><tr id="row912333967165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p708618923165623"><a name="p708618923165623"></a><a name="p708618923165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p931325385165623"><a name="p931325385165623"></a><a name="p931325385165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row425507970165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry969977549165623p0"><a name="entry969977549165623p0"></a><a name="entry969977549165623p0"></a><strong id="gga85b10143618f300ff4f5bc6d45c72c01a6d67944b4958ad33b0eeb851bbcd169f"><a name="gga85b10143618f300ff4f5bc6d45c72c01a6d67944b4958ad33b0eeb851bbcd169f"></a><a name="gga85b10143618f300ff4f5bc6d45c72c01a6d67944b4958ad33b0eeb851bbcd169f"></a></strong>INVALID_PROFILE</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p865881682165623"><a name="p865881682165623"></a><a name="p865881682165623"></a>Invalid profile</p>
<p id="p69352233205"><a name="p69352233205"></a><a name="p69352233205"></a></p>
</td>
</tr>
<tr id="row1753939373165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry968216624165623p0"><a name="entry968216624165623p0"></a><a name="entry968216624165623p0"></a><strong id="gga85b10143618f300ff4f5bc6d45c72c01ad91765d6dcad7253a924d3cb30501e44"><a name="gga85b10143618f300ff4f5bc6d45c72c01ad91765d6dcad7253a924d3cb30501e44"></a><a name="gga85b10143618f300ff4f5bc6d45c72c01ad91765d6dcad7253a924d3cb30501e44"></a></strong>AAC_LC_PROFILE</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p174792588165623"><a name="p174792588165623"></a><a name="p174792588165623"></a>AAC-Low Complex</p>
<p id="p993632312010"><a name="p993632312010"></a><a name="p993632312010"></a></p>
</td>
</tr>
<tr id="row546771172165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1918036997165623p0"><a name="entry1918036997165623p0"></a><a name="entry1918036997165623p0"></a><strong id="gga85b10143618f300ff4f5bc6d45c72c01aada4d857818cd9aa1ad62cdf608dab6b"><a name="gga85b10143618f300ff4f5bc6d45c72c01aada4d857818cd9aa1ad62cdf608dab6b"></a><a name="gga85b10143618f300ff4f5bc6d45c72c01aada4d857818cd9aa1ad62cdf608dab6b"></a></strong>AAC_MAIN_PROFILE</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p288510810165623"><a name="p288510810165623"></a><a name="p288510810165623"></a>AAC-Main</p>
<p id="p10936142318205"><a name="p10936142318205"></a><a name="p10936142318205"></a></p>
</td>
</tr>
<tr id="row2147373689165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2094364255165623p0"><a name="entry2094364255165623p0"></a><a name="entry2094364255165623p0"></a><strong id="gga85b10143618f300ff4f5bc6d45c72c01ab4255dc0e7450af4f526b85acbabfd3e"><a name="gga85b10143618f300ff4f5bc6d45c72c01ab4255dc0e7450af4f526b85acbabfd3e"></a><a name="gga85b10143618f300ff4f5bc6d45c72c01ab4255dc0e7450af4f526b85acbabfd3e"></a></strong>AAC_HE_V1_PROFILE</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1540153616165623"><a name="p1540153616165623"></a><a name="p1540153616165623"></a>HEAAC, AAC+, or AACPlusV1</p>
<p id="p15936323182011"><a name="p15936323182011"></a><a name="p15936323182011"></a></p>
</td>
</tr>
<tr id="row282203126165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry749384861165623p0"><a name="entry749384861165623p0"></a><a name="entry749384861165623p0"></a><strong id="gga85b10143618f300ff4f5bc6d45c72c01a9b54f7a8c45ea6d4804133d8de4b8dd8"><a name="gga85b10143618f300ff4f5bc6d45c72c01a9b54f7a8c45ea6d4804133d8de4b8dd8"></a><a name="gga85b10143618f300ff4f5bc6d45c72c01a9b54f7a8c45ea6d4804133d8de4b8dd8"></a></strong>AAC_HE_V2_PROFILE</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1084606534165623"><a name="p1084606534165623"></a><a name="p1084606534165623"></a>AAC++ or AACPlusV2</p>
<p id="p11936192332012"><a name="p11936192332012"></a><a name="p11936192332012"></a></p>
</td>
</tr>
<tr id="row837319901165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1600218462165623p0"><a name="entry1600218462165623p0"></a><a name="entry1600218462165623p0"></a><strong id="gga85b10143618f300ff4f5bc6d45c72c01afaaacd4f6bdadac28b5cf49ae8f8470a"><a name="gga85b10143618f300ff4f5bc6d45c72c01afaaacd4f6bdadac28b5cf49ae8f8470a"></a><a name="gga85b10143618f300ff4f5bc6d45c72c01afaaacd4f6bdadac28b5cf49ae8f8470a"></a></strong>AAC_LD_PROFILE</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1737890275165623"><a name="p1737890275165623"></a><a name="p1737890275165623"></a>AAC-Low Delay</p>
<p id="p1393642382014"><a name="p1393642382014"></a><a name="p1393642382014"></a></p>
</td>
</tr>
<tr id="row181668085165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1566200141165623p0"><a name="entry1566200141165623p0"></a><a name="entry1566200141165623p0"></a><strong id="gga85b10143618f300ff4f5bc6d45c72c01a7c8028283d1ff60e486b3305bf8c1adc"><a name="gga85b10143618f300ff4f5bc6d45c72c01a7c8028283d1ff60e486b3305bf8c1adc"></a><a name="gga85b10143618f300ff4f5bc6d45c72c01a7c8028283d1ff60e486b3305bf8c1adc"></a></strong>AAC_ELD_PROFILE</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p688815988165623"><a name="p688815988165623"></a><a name="p688815988165623"></a>AAC-Enhanced Low Delay</p>
<p id="p493620234206"><a name="p493620234206"></a><a name="p493620234206"></a></p>
</td>
</tr>
<tr id="row2130490852165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry617840784165623p0"><a name="entry617840784165623p0"></a><a name="entry617840784165623p0"></a><strong id="gga85b10143618f300ff4f5bc6d45c72c01a5bab002f00d3d7281aedc4807123a47a"><a name="gga85b10143618f300ff4f5bc6d45c72c01a5bab002f00d3d7281aedc4807123a47a"></a><a name="gga85b10143618f300ff4f5bc6d45c72c01a5bab002f00d3d7281aedc4807123a47a"></a></strong>AVC_BASELINE_PROFILE</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1145739187165623"><a name="p1145739187165623"></a><a name="p1145739187165623"></a>H.264 Baseline</p>
<p id="p0936132317206"><a name="p0936132317206"></a><a name="p0936132317206"></a></p>
</td>
</tr>
<tr id="row318848546165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry57066750165623p0"><a name="entry57066750165623p0"></a><a name="entry57066750165623p0"></a><strong id="gga85b10143618f300ff4f5bc6d45c72c01a323c1d6e02363f1717f7e6b33fd9a646"><a name="gga85b10143618f300ff4f5bc6d45c72c01a323c1d6e02363f1717f7e6b33fd9a646"></a><a name="gga85b10143618f300ff4f5bc6d45c72c01a323c1d6e02363f1717f7e6b33fd9a646"></a></strong>AVC_MAIN_PROFILE</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1606537059165623"><a name="p1606537059165623"></a><a name="p1606537059165623"></a>H.264 Main</p>
<p id="p6936423112017"><a name="p6936423112017"></a><a name="p6936423112017"></a></p>
</td>
</tr>
<tr id="row1734405709165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry915119893165623p0"><a name="entry915119893165623p0"></a><a name="entry915119893165623p0"></a><strong id="gga85b10143618f300ff4f5bc6d45c72c01ab9406e6bf30a0c128c3639cce51fe246"><a name="gga85b10143618f300ff4f5bc6d45c72c01ab9406e6bf30a0c128c3639cce51fe246"></a><a name="gga85b10143618f300ff4f5bc6d45c72c01ab9406e6bf30a0c128c3639cce51fe246"></a></strong>AVC_HIGH_PROFILE</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1842041017165623"><a name="p1842041017165623"></a><a name="p1842041017165623"></a>H.264 High</p>
<p id="p129360234205"><a name="p129360234205"></a><a name="p129360234205"></a></p>
</td>
</tr>
<tr id="row1323597301165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2031985160165623p0"><a name="entry2031985160165623p0"></a><a name="entry2031985160165623p0"></a><strong id="gga85b10143618f300ff4f5bc6d45c72c01ae0d37dc2c7d39753a80f6e0ba64e5e22"><a name="gga85b10143618f300ff4f5bc6d45c72c01ae0d37dc2c7d39753a80f6e0ba64e5e22"></a><a name="gga85b10143618f300ff4f5bc6d45c72c01ae0d37dc2c7d39753a80f6e0ba64e5e22"></a></strong>HEVC_MAIN_PROFILE</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1851977203165623"><a name="p1851977203165623"></a><a name="p1851977203165623"></a>H.265 Main</p>
<p id="p8936523152011"><a name="p8936523152011"></a><a name="p8936523152011"></a></p>
</td>
</tr>
<tr id="row298026944165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1756884350165623p0"><a name="entry1756884350165623p0"></a><a name="entry1756884350165623p0"></a><strong id="gga85b10143618f300ff4f5bc6d45c72c01a811b9e02d8b0afa93e7ab8d2aa7e5de6"><a name="gga85b10143618f300ff4f5bc6d45c72c01a811b9e02d8b0afa93e7ab8d2aa7e5de6"></a><a name="gga85b10143618f300ff4f5bc6d45c72c01a811b9e02d8b0afa93e7ab8d2aa7e5de6"></a></strong>HEVC_MAIN_10_PROFILE</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p202844748165623"><a name="p202844748165623"></a><a name="p202844748165623"></a>H.265 Main 10</p>
<p id="p993613236208"><a name="p993613236208"></a><a name="p993613236208"></a></p>
</td>
</tr>
</tbody>
</table>

## StreamFlagType<a name="ga8a15793172118d64d8adeba0c8544e84"></a>

```
enum [StreamFlagType](Codec.md#ga8a15793172118d64d8adeba0c8544e84)
```

**Description:**

Enumerates stream flags.

<a name="table1449274075165623"></a>
<table><thead align="left"><tr id="row1407703545165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1846877979165623"><a name="p1846877979165623"></a><a name="p1846877979165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1369994404165623"><a name="p1369994404165623"></a><a name="p1369994404165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1406155512165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1104116082165623p0"><a name="entry1104116082165623p0"></a><a name="entry1104116082165623p0"></a><strong id="gga8a15793172118d64d8adeba0c8544e84ae0da6ed262d36cb4de4b63cd25889ea2"><a name="gga8a15793172118d64d8adeba0c8544e84ae0da6ed262d36cb4de4b63cd25889ea2"></a><a name="gga8a15793172118d64d8adeba0c8544e84ae0da6ed262d36cb4de4b63cd25889ea2"></a></strong>STREAM_FLAG_KEYFRAME</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1111645130165623"><a name="p1111645130165623"></a><a name="p1111645130165623"></a>Keyframe</p>
<p id="p694722316205"><a name="p694722316205"></a><a name="p694722316205"></a></p>
</td>
</tr>
<tr id="row1819883163165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1010154709165623p0"><a name="entry1010154709165623p0"></a><a name="entry1010154709165623p0"></a><strong id="gga8a15793172118d64d8adeba0c8544e84a9a06fdc891d28272ba6651ca9791d166"><a name="gga8a15793172118d64d8adeba0c8544e84a9a06fdc891d28272ba6651ca9791d166"></a><a name="gga8a15793172118d64d8adeba0c8544e84a9a06fdc891d28272ba6651ca9791d166"></a></strong>STREAM_FLAG_CODEC_SPECIFIC_INF</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1633837834165623"><a name="p1633837834165623"></a><a name="p1633837834165623"></a>Codec specifications</p>
<p id="p15947162322015"><a name="p15947162322015"></a><a name="p15947162322015"></a></p>
</td>
</tr>
<tr id="row331269064165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1630963846165623p0"><a name="entry1630963846165623p0"></a><a name="entry1630963846165623p0"></a><strong id="gga8a15793172118d64d8adeba0c8544e84abe40ab8f6da71b5a7d6a382954dc5d4f"><a name="gga8a15793172118d64d8adeba0c8544e84abe40ab8f6da71b5a7d6a382954dc5d4f"></a><a name="gga8a15793172118d64d8adeba0c8544e84abe40ab8f6da71b5a7d6a382954dc5d4f"></a></strong>STREAM_FLAG_EOS</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1252358146165623"><a name="p1252358146165623"></a><a name="p1252358146165623"></a>End of streams</p>
<p id="p1894732322012"><a name="p1894732322012"></a><a name="p1894732322012"></a></p>
</td>
</tr>
<tr id="row159820026165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1753396384165623p0"><a name="entry1753396384165623p0"></a><a name="entry1753396384165623p0"></a><strong id="gga8a15793172118d64d8adeba0c8544e84a7809fe65541dc27f50ba4952685c34bd"><a name="gga8a15793172118d64d8adeba0c8544e84a7809fe65541dc27f50ba4952685c34bd"></a><a name="gga8a15793172118d64d8adeba0c8544e84a7809fe65541dc27f50ba4952685c34bd"></a></strong>STREAM_FLAG_PART_OF_FRAME</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p290598345165623"><a name="p290598345165623"></a><a name="p290598345165623"></a>Partial frame</p>
<p id="p13947192302016"><a name="p13947192302016"></a><a name="p13947192302016"></a></p>
</td>
</tr>
<tr id="row1543304399165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1530963484165623p0"><a name="entry1530963484165623p0"></a><a name="entry1530963484165623p0"></a><strong id="gga8a15793172118d64d8adeba0c8544e84abb9a3fba052c516ac141e34ea9fa6dca"><a name="gga8a15793172118d64d8adeba0c8544e84abb9a3fba052c516ac141e34ea9fa6dca"></a><a name="gga8a15793172118d64d8adeba0c8544e84abb9a3fba052c516ac141e34ea9fa6dca"></a></strong>STREAM_FLAG_END_OF_FRAME</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p506752295165623"><a name="p506752295165623"></a><a name="p506752295165623"></a>End of frames, used in pair with <strong id="b1379464564165623"><a name="b1379464564165623"></a><a name="b1379464564165623"></a> STREAM_FLAG_PART_OF_FRAME</strong></p>
<p id="p1794742372014"><a name="p1794742372014"></a><a name="p1794742372014"></a></p>
</td>
</tr>
</tbody>
</table>

## VenCodeGopMode<a name="ga9532f651a003219a262c440f5621d129"></a>

```
enum [VenCodeGopMode](Codec.md#ga9532f651a003219a262c440f5621d129)
```

**Description:**

Enumerates types of group of pictures \(GOP\).

<a name="table1601538946165623"></a>
<table><thead align="left"><tr id="row2029847358165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1518299967165623"><a name="p1518299967165623"></a><a name="p1518299967165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1626214543165623"><a name="p1626214543165623"></a><a name="p1626214543165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1909570893165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1638637968165623p0"><a name="entry1638637968165623p0"></a><a name="entry1638637968165623p0"></a><strong id="gga9532f651a003219a262c440f5621d129a1f3b41538fdbdbb9f920f740f89c7c95"><a name="gga9532f651a003219a262c440f5621d129a1f3b41538fdbdbb9f920f740f89c7c95"></a><a name="gga9532f651a003219a262c440f5621d129a1f3b41538fdbdbb9f920f740f89c7c95"></a></strong>VENCOD_GOPMODE_NORMALP</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p970589047165623"><a name="p970589047165623"></a><a name="p970589047165623"></a>P-frames using only one reference frame during encoding</p>
<p id="p595242382017"><a name="p595242382017"></a><a name="p595242382017"></a></p>
</td>
</tr>
<tr id="row757433230165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1150156006165623p0"><a name="entry1150156006165623p0"></a><a name="entry1150156006165623p0"></a><strong id="gga9532f651a003219a262c440f5621d129a6b063f65ef8ec77e360bbbd56c7b233f"><a name="gga9532f651a003219a262c440f5621d129a6b063f65ef8ec77e360bbbd56c7b233f"></a><a name="gga9532f651a003219a262c440f5621d129a6b063f65ef8ec77e360bbbd56c7b233f"></a></strong>VENCOD_GOPMODE_DUALP</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2009724085165623"><a name="p2009724085165623"></a><a name="p2009724085165623"></a>P-frames using two reference frames during encoding</p>
<p id="p59521323162017"><a name="p59521323162017"></a><a name="p59521323162017"></a></p>
</td>
</tr>
<tr id="row1794659248165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1387036166165623p0"><a name="entry1387036166165623p0"></a><a name="entry1387036166165623p0"></a><strong id="gga9532f651a003219a262c440f5621d129a37226f50b4e07586d8bd8e22114e2324"><a name="gga9532f651a003219a262c440f5621d129a37226f50b4e07586d8bd8e22114e2324"></a><a name="gga9532f651a003219a262c440f5621d129a37226f50b4e07586d8bd8e22114e2324"></a></strong>VENCOD_GOPMODE_SMARTP</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1813643737165623"><a name="p1813643737165623"></a><a name="p1813643737165623"></a>Smart P-frames for encoding</p>
<p id="p1895282318209"><a name="p1895282318209"></a><a name="p1895282318209"></a></p>
</td>
</tr>
<tr id="row1362350234165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1830492076165623p0"><a name="entry1830492076165623p0"></a><a name="entry1830492076165623p0"></a><strong id="gga9532f651a003219a262c440f5621d129a8caa9e9fae7ca1d041ccb163bbcf92c6"><a name="gga9532f651a003219a262c440f5621d129a8caa9e9fae7ca1d041ccb163bbcf92c6"></a><a name="gga9532f651a003219a262c440f5621d129a8caa9e9fae7ca1d041ccb163bbcf92c6"></a></strong>VENCOD_GOPMODE_ADVSMARTP</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1503389182165623"><a name="p1503389182165623"></a><a name="p1503389182165623"></a>Advanced smart P-frames for encoding</p>
<p id="p1895222332018"><a name="p1895222332018"></a><a name="p1895222332018"></a></p>
</td>
</tr>
<tr id="row1439150949165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1400178742165623p0"><a name="entry1400178742165623p0"></a><a name="entry1400178742165623p0"></a><strong id="gga9532f651a003219a262c440f5621d129a7a120c500828b79e7a87e4f8a9d4378c"><a name="gga9532f651a003219a262c440f5621d129a7a120c500828b79e7a87e4f8a9d4378c"></a><a name="gga9532f651a003219a262c440f5621d129a7a120c500828b79e7a87e4f8a9d4378c"></a></strong>VENCOD_GOPMODE_BIPREDB</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1310464147165623"><a name="p1310464147165623"></a><a name="p1310464147165623"></a>B-frames for encoding</p>
<p id="p7952172342013"><a name="p7952172342013"></a><a name="p7952172342013"></a></p>
</td>
</tr>
<tr id="row301716981165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1066246105165623p0"><a name="entry1066246105165623p0"></a><a name="entry1066246105165623p0"></a><strong id="gga9532f651a003219a262c440f5621d129ae02038b7e71cb65c991676da17a11a73"><a name="gga9532f651a003219a262c440f5621d129ae02038b7e71cb65c991676da17a11a73"></a><a name="gga9532f651a003219a262c440f5621d129ae02038b7e71cb65c991676da17a11a73"></a></strong>VENCOD_GOPMODE_LOWDELAYB</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2146602609165623"><a name="p2146602609165623"></a><a name="p2146602609165623"></a>B-frames using only previous frames as references during encoding.</p>
<p id="p49523232209"><a name="p49523232209"></a><a name="p49523232209"></a></p>
</td>
</tr>
<tr id="row734520399165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1085109824165623p0"><a name="entry1085109824165623p0"></a><a name="entry1085109824165623p0"></a><strong id="gga9532f651a003219a262c440f5621d129a6b54943891a852da1b3e37cac4893b55"><a name="gga9532f651a003219a262c440f5621d129a6b54943891a852da1b3e37cac4893b55"></a><a name="gga9532f651a003219a262c440f5621d129a6b54943891a852da1b3e37cac4893b55"></a></strong>VENCOD_GOPMODE_INVALID</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1163945167165623"><a name="p1163945167165623"></a><a name="p1163945167165623"></a>Invalid type</p>
<p id="p1395232312208"><a name="p1395232312208"></a><a name="p1395232312208"></a></p>
</td>
</tr>
</tbody>
</table>

## VenCodeRcMode<a name="ga94267d7ba495136561e1c65686b240f7"></a>

```
enum [VenCodeRcMode](Codec.md#ga94267d7ba495136561e1c65686b240f7)
```

**Description:**

Enumerates control modes of the channel encoding rate.

<a name="table1843808985165623"></a>
<table><thead align="left"><tr id="row1544984019165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p407656885165623"><a name="p407656885165623"></a><a name="p407656885165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p198508583165623"><a name="p198508583165623"></a><a name="p198508583165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row482517630165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1060462073165623p0"><a name="entry1060462073165623p0"></a><a name="entry1060462073165623p0"></a><strong id="gga94267d7ba495136561e1c65686b240f7af65e058f6076a39b864a5e5351c508a8"><a name="gga94267d7ba495136561e1c65686b240f7af65e058f6076a39b864a5e5351c508a8"></a><a name="gga94267d7ba495136561e1c65686b240f7af65e058f6076a39b864a5e5351c508a8"></a></strong>VENCOD_RC_CBR</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p541732453165623"><a name="p541732453165623"></a><a name="p541732453165623"></a>Fixed bit rate</p>
<p id="p1896382318201"><a name="p1896382318201"></a><a name="p1896382318201"></a></p>
</td>
</tr>
<tr id="row1584750727165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry800937002165623p0"><a name="entry800937002165623p0"></a><a name="entry800937002165623p0"></a><strong id="gga94267d7ba495136561e1c65686b240f7ad40974ef1c63cc0fcef1106a69dc696a"><a name="gga94267d7ba495136561e1c65686b240f7ad40974ef1c63cc0fcef1106a69dc696a"></a><a name="gga94267d7ba495136561e1c65686b240f7ad40974ef1c63cc0fcef1106a69dc696a"></a></strong>VENCOD_RC_VBR</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2058625334165623"><a name="p2058625334165623"></a><a name="p2058625334165623"></a>Variable bit rate</p>
<p id="p15963823172012"><a name="p15963823172012"></a><a name="p15963823172012"></a></p>
</td>
</tr>
<tr id="row1938255933165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry685851370165623p0"><a name="entry685851370165623p0"></a><a name="entry685851370165623p0"></a><strong id="gga94267d7ba495136561e1c65686b240f7ae4e2d1f85e783430a12ad412edf21ddc"><a name="gga94267d7ba495136561e1c65686b240f7ae4e2d1f85e783430a12ad412edf21ddc"></a><a name="gga94267d7ba495136561e1c65686b240f7ae4e2d1f85e783430a12ad412edf21ddc"></a></strong>VENCOD_RC_AVBR</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p90513224165623"><a name="p90513224165623"></a><a name="p90513224165623"></a>Adaptive variable bit rate</p>
<p id="p99631323152018"><a name="p99631323152018"></a><a name="p99631323152018"></a></p>
</td>
</tr>
<tr id="row1642615040165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1289391402165623p0"><a name="entry1289391402165623p0"></a><a name="entry1289391402165623p0"></a><strong id="gga94267d7ba495136561e1c65686b240f7aa3294f73cd0cd078618ef9db4d3cb6f5"><a name="gga94267d7ba495136561e1c65686b240f7aa3294f73cd0cd078618ef9db4d3cb6f5"></a><a name="gga94267d7ba495136561e1c65686b240f7aa3294f73cd0cd078618ef9db4d3cb6f5"></a></strong>VENCOD_RC_QVBR</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1068796723165623"><a name="p1068796723165623"></a><a name="p1068796723165623"></a>Quality-defined variable bit rate</p>
<p id="p13963623112011"><a name="p13963623112011"></a><a name="p13963623112011"></a></p>
</td>
</tr>
<tr id="row528077916165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry76491155165623p0"><a name="entry76491155165623p0"></a><a name="entry76491155165623p0"></a><strong id="gga94267d7ba495136561e1c65686b240f7ad43d98e7b3b42efa4cc6d4d1a2298024"><a name="gga94267d7ba495136561e1c65686b240f7ad43d98e7b3b42efa4cc6d4d1a2298024"></a><a name="gga94267d7ba495136561e1c65686b240f7ad43d98e7b3b42efa4cc6d4d1a2298024"></a></strong>VENCOD_RC_CVBR</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p93353348165623"><a name="p93353348165623"></a><a name="p93353348165623"></a>Constrained variable bit rate</p>
<p id="p9963323142018"><a name="p9963323142018"></a><a name="p9963323142018"></a></p>
</td>
</tr>
<tr id="row1189844131165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1079109039165623p0"><a name="entry1079109039165623p0"></a><a name="entry1079109039165623p0"></a><strong id="gga94267d7ba495136561e1c65686b240f7a3e89e3affbe63967e5cdfc3b162d8ac9"><a name="gga94267d7ba495136561e1c65686b240f7a3e89e3affbe63967e5cdfc3b162d8ac9"></a><a name="gga94267d7ba495136561e1c65686b240f7a3e89e3affbe63967e5cdfc3b162d8ac9"></a></strong>VENCOD_RC_QPMAP</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1927796734165623"><a name="p1927796734165623"></a><a name="p1927796734165623"></a>Configuration-mapped quantization parameters</p>
<p id="p896342318208"><a name="p896342318208"></a><a name="p896342318208"></a></p>
</td>
</tr>
<tr id="row1502320162165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry362799818165623p0"><a name="entry362799818165623p0"></a><a name="entry362799818165623p0"></a><strong id="gga94267d7ba495136561e1c65686b240f7ae9a1e0b19d79f1c2bdada4c5830e2584"><a name="gga94267d7ba495136561e1c65686b240f7ae9a1e0b19d79f1c2bdada4c5830e2584"></a><a name="gga94267d7ba495136561e1c65686b240f7ae9a1e0b19d79f1c2bdada4c5830e2584"></a></strong>VENCOD_RC_FIXQP</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p912485902165623"><a name="p912485902165623"></a><a name="p912485902165623"></a>Fixed quantization parameters</p>
<p id="p169631123192010"><a name="p169631123192010"></a><a name="p169631123192010"></a></p>
</td>
</tr>
</tbody>
</table>

## VideoField<a name="ga1420ddfb066b941fb55a153b869d9ccf"></a>

```
enum [VideoField](Codec.md#ga1420ddfb066b941fb55a153b869d9ccf)
```

**Description:**

Enumerates video frame fields.

<a name="table1808553530165623"></a>
<table><thead align="left"><tr id="row686513411165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1799065999165623"><a name="p1799065999165623"></a><a name="p1799065999165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p155099633165623"><a name="p155099633165623"></a><a name="p155099633165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1189461273165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry984136989165623p0"><a name="entry984136989165623p0"></a><a name="entry984136989165623p0"></a><strong id="gga1420ddfb066b941fb55a153b869d9ccfadf9934801550e7c45e395d8e4704aff9"><a name="gga1420ddfb066b941fb55a153b869d9ccfadf9934801550e7c45e395d8e4704aff9"></a><a name="gga1420ddfb066b941fb55a153b869d9ccfadf9934801550e7c45e395d8e4704aff9"></a></strong>VID_FIELD_TOP</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p473323962165623"><a name="p473323962165623"></a><a name="p473323962165623"></a>Top fields on even-number lines</p>
<p id="p1096911239200"><a name="p1096911239200"></a><a name="p1096911239200"></a></p>
</td>
</tr>
<tr id="row1731649839165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1231265786165623p0"><a name="entry1231265786165623p0"></a><a name="entry1231265786165623p0"></a><strong id="gga1420ddfb066b941fb55a153b869d9ccfa3de04ce552cc5a52d977256efed8611a"><a name="gga1420ddfb066b941fb55a153b869d9ccfa3de04ce552cc5a52d977256efed8611a"></a><a name="gga1420ddfb066b941fb55a153b869d9ccfa3de04ce552cc5a52d977256efed8611a"></a></strong>VID_FIELD_BOTTOM</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p891081358165623"><a name="p891081358165623"></a><a name="p891081358165623"></a>Bottom fields on odd-number lines</p>
<p id="p8969223122015"><a name="p8969223122015"></a><a name="p8969223122015"></a></p>
</td>
</tr>
<tr id="row625614924165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1980829385165623p0"><a name="entry1980829385165623p0"></a><a name="entry1980829385165623p0"></a><strong id="gga1420ddfb066b941fb55a153b869d9ccfa9c3bffc837d46ece68154c98bfc4c303"><a name="gga1420ddfb066b941fb55a153b869d9ccfa9c3bffc837d46ece68154c98bfc4c303"></a><a name="gga1420ddfb066b941fb55a153b869d9ccfa9c3bffc837d46ece68154c98bfc4c303"></a></strong>VID_FIELD_INTERLACED</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p36456728165623"><a name="p36456728165623"></a><a name="p36456728165623"></a>Interlaced fields</p>
<p id="p10969423182020"><a name="p10969423182020"></a><a name="p10969423182020"></a></p>
</td>
</tr>
<tr id="row1131499700165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry603305291165623p0"><a name="entry603305291165623p0"></a><a name="entry603305291165623p0"></a><strong id="gga1420ddfb066b941fb55a153b869d9ccfaaf092a3bb1b706a47a425e7eff683526"><a name="gga1420ddfb066b941fb55a153b869d9ccfaaf092a3bb1b706a47a425e7eff683526"></a><a name="gga1420ddfb066b941fb55a153b869d9ccfaaf092a3bb1b706a47a425e7eff683526"></a></strong>VID_FIELD_FRAME</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1885121975165623"><a name="p1885121975165623"></a><a name="p1885121975165623"></a>Non-interlaced frames</p>
<p id="p896916230204"><a name="p896916230204"></a><a name="p896916230204"></a></p>
</td>
</tr>
<tr id="row742230609165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry966372212165623p0"><a name="entry966372212165623p0"></a><a name="entry966372212165623p0"></a><strong id="gga1420ddfb066b941fb55a153b869d9ccfaedd6cdcd59983317521c2ac717884405"><a name="gga1420ddfb066b941fb55a153b869d9ccfaedd6cdcd59983317521c2ac717884405"></a><a name="gga1420ddfb066b941fb55a153b869d9ccfaedd6cdcd59983317521c2ac717884405"></a></strong>VID_FIELD_INVALID</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p528782494165623"><a name="p528782494165623"></a><a name="p528782494165623"></a>Invalid fields</p>
<p id="p14969162332012"><a name="p14969162332012"></a><a name="p14969162332012"></a></p>
</td>
</tr>
</tbody>
</table>

## **Function**<a name="section106240538165623"></a>

## CodecCreate\(\)<a name="ga74aa0395a51f004390f7a92fb68faddd"></a>

```
int32_t CodecCreate (const char * name, const [Param](Param.md) * attr, int len, [CODEC_HANDLETYPE](Codec.md#ga9381a619f36ac8d5d7f467d2f0404183) * handle )
```

**Description:**

Creates a specific codec component and returns the component context through a handle.

You can adjust the parameters required for creating a component based on service requirements.

**Parameters:**

<a name="table415265868165623"></a>
<table><thead align="left"><tr id="row901319356165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1963290744165623"><a name="p1963290744165623"></a><a name="p1963290744165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p854897807165623"><a name="p854897807165623"></a><a name="p854897807165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row432878086165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry243973500165623p0"><a name="entry243973500165623p0"></a><a name="entry243973500165623p0"></a>name</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1196451499165623p0"><a name="entry1196451499165623p0"></a><a name="entry1196451499165623p0"></a>Indicates the pointer to the unique name of the component, for example, <strong id="b1816599451165623"><a name="b1816599451165623"></a><a name="b1816599451165623"></a>codec.avc.hardware.decoder</strong>.</p>
</td>
</tr>
<tr id="row64188058165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1461462712165623p0"><a name="entry1461462712165623p0"></a><a name="entry1461462712165623p0"></a>attr</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry431420126165623p0"><a name="entry431420126165623p0"></a><a name="entry431420126165623p0"></a>Indicates the pointer to the parameters in the array required for creating the component.</p>
</td>
</tr>
<tr id="row924198835165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1935644300165623p0"><a name="entry1935644300165623p0"></a><a name="entry1935644300165623p0"></a>len</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry332424901165623p0"><a name="entry332424901165623p0"></a><a name="entry332424901165623p0"></a>Indicates the number of elements in the parameter array.</p>
</td>
</tr>
<tr id="row446300006165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1254694524165623p0"><a name="entry1254694524165623p0"></a><a name="entry1254694524165623p0"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry540881954165623p0"><a name="entry540881954165623p0"></a><a name="entry540881954165623p0"></a>Indicates the pointer to the codec handle returned.</p>
</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the codec component is created and the handle is available; returns a non-zero value otherwise.

## CodecDeinit\(\)<a name="ga2d6eb231ca7766990cfa8c1841637245"></a>

```
int32_t CodecDeinit ()
```

**Description:**

Deinitializes the internal audio and video submodules of the codec.

This function needs to be called only once in a process.

**Returns:**

Returns  **0**  if the deinitialization is successful; returns a non-zero value otherwise.

**See also:**

[CodecInit](Codec.md#gadb2714f1e7a69419cefd38a2ad1f9829)

## CodecDequeInput\(\)<a name="ga91d7e1566c90d7cb9ac846eecad0024f"></a>

```
int32_t CodecDequeInput ([CODEC_HANDLETYPE](Codec.md#ga9381a619f36ac8d5d7f467d2f0404183) handle, uint32_t timeoutMs, [InputInfo](InputInfo.md) * inputData )
```

**Description:**

Dequeues input data that has been used.

This function works with  [CodecQueueInput](Codec.md#ga0daece8dbf22da84f926761c994819bc)  to implement input data transmission.

**Parameters:**

<a name="table129878146165623"></a>
<table><thead align="left"><tr id="row1894829433165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1152915416165623"><a name="p1152915416165623"></a><a name="p1152915416165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p84619193165623"><a name="p84619193165623"></a><a name="p84619193165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row461323486165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1205186287165623p0"><a name="entry1205186287165623p0"></a><a name="entry1205186287165623p0"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1114411133165623p0"><a name="entry1114411133165623p0"></a><a name="entry1114411133165623p0"></a>Indicates the handle of the codec component.</p>
</td>
</tr>
<tr id="row1256172825165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1408148911165623p0"><a name="entry1408148911165623p0"></a><a name="entry1408148911165623p0"></a>timeoutMs</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1799853452165623p0"><a name="entry1799853452165623p0"></a><a name="entry1799853452165623p0"></a>Indicates the timeout duration. Generally, the value is less than or equal to <strong id="b2049073010165623"><a name="b2049073010165623"></a><a name="b2049073010165623"></a>3</strong> seconds.</p>
</td>
</tr>
<tr id="row130432253165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1870080696165623p0"><a name="entry1870080696165623p0"></a><a name="entry1870080696165623p0"></a>inputData</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1488519841165623p0"><a name="entry1488519841165623p0"></a><a name="entry1488519841165623p0"></a>Indicates the pointer to the input data that is used.</p>
</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value otherwise.

## CodecDequeueOutput\(\)<a name="gab575752467517eb8e6766773c1e3fb23"></a>

```
int32_t CodecDequeueOutput ([CODEC_HANDLETYPE](Codec.md#ga9381a619f36ac8d5d7f467d2f0404183) handle, uint32_t timeoutMs, int * acquireFd, [OutputInfo](OutputInfo.md) * outInfo )
```

**Description:**

Dequeues output data.

This function works with  [CodecQueueOutput](Codec.md#gac98f3505082c3cb2413d9e95eef9c804)  to implement output data transmission.

**Parameters:**

<a name="table2028478675165623"></a>
<table><thead align="left"><tr id="row1151654797165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2041739147165623"><a name="p2041739147165623"></a><a name="p2041739147165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p731163768165623"><a name="p731163768165623"></a><a name="p731163768165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1970595092165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2064478382165623p0"><a name="entry2064478382165623p0"></a><a name="entry2064478382165623p0"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1203486176165623p0"><a name="entry1203486176165623p0"></a><a name="entry1203486176165623p0"></a>Indicates the handle of the codec component.</p>
</td>
</tr>
<tr id="row86849102165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1385407896165623p0"><a name="entry1385407896165623p0"></a><a name="entry1385407896165623p0"></a>timeoutMs</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1890718790165623p0"><a name="entry1890718790165623p0"></a><a name="entry1890718790165623p0"></a>Indicates the timeout duration.</p>
</td>
</tr>
<tr id="row1404111421165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1912211234165623p0"><a name="entry1912211234165623p0"></a><a name="entry1912211234165623p0"></a>acquireFd</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry63141637165623p0"><a name="entry63141637165623p0"></a><a name="entry63141637165623p0"></a>Indicates that this parameter is derived from the codec mode. The output data can be used only after waiting for <strong id="b2031790744165623"><a name="b2031790744165623"></a><a name="b2031790744165623"></a>acquireFd</strong> is successful. The value <strong id="b974554768165623"><a name="b974554768165623"></a><a name="b974554768165623"></a>-1</strong> indicates that <strong id="b395152060165623"><a name="b395152060165623"></a><a name="b395152060165623"></a>acquireFd</strong> is invalid.</p>
</td>
</tr>
<tr id="row1832990312165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry383944982165623p0"><a name="entry383944982165623p0"></a><a name="entry383944982165623p0"></a>outInfo</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1385548750165623p0"><a name="entry1385548750165623p0"></a><a name="entry1385548750165623p0"></a>Indicates the pointer to the output data.</p>
</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value otherwise.

## CodecDestroy\(\)<a name="ga1bc0592b05e4f687e2bef2ffb83102b8"></a>

```
int32_t CodecDestroy ([CODEC_HANDLETYPE](Codec.md#ga9381a619f36ac8d5d7f467d2f0404183) handle)
```

**Description:**

Destroys a codec component.

**Parameters:**

<a name="table1169296036165623"></a>
<table><thead align="left"><tr id="row2036670729165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1183171321165623"><a name="p1183171321165623"></a><a name="p1183171321165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1194904728165623"><a name="p1194904728165623"></a><a name="p1194904728165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row392250357165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry381424013165623p0"><a name="entry381424013165623p0"></a><a name="entry381424013165623p0"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry2034237794165623p0"><a name="entry2034237794165623p0"></a><a name="entry2034237794165623p0"></a>Indicates the handle of the codec component.</p>
</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the codec component is destroyed; returns a non-zero value otherwise.

**See also:**

[CodecCreate](Codec.md#ga74aa0395a51f004390f7a92fb68faddd)

## CodecEnumerateCapbility\(\)<a name="gaf0bb69d2f8c5ad0fec6959b353ee1acd"></a>

```
int32_t CodecEnumerateCapbility (uint32_t index, [CodecCapbility](Codec.md#ga1876710b1f2fe1d80e8b9de9ff28e0e3) * cap )
```

**Description:**

Obtains the capabilities of a specified media type based on an index.

You can call this function repeatedly to obtain the codec capabilities until  **CODEC\_END**  is returned. The corresponding capabilities are described in the  **Capability**  structure, including the maximum and minimum resolutions, maximum and minimum bit rates, and supported profiles and levels. After obtaining the capabilities, determine whether they can meet your requirements, for example, whether specific media files can be played and whether audio and video frames can be compressed.

**Parameters:**

<a name="table1336028149165623"></a>
<table><thead align="left"><tr id="row237909131165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1908056102165623"><a name="p1908056102165623"></a><a name="p1908056102165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1333917530165623"><a name="p1333917530165623"></a><a name="p1333917530165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1001307780165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2069210508165623p0"><a name="entry2069210508165623p0"></a><a name="entry2069210508165623p0"></a>index</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1064575568165623p0"><a name="entry1064575568165623p0"></a><a name="entry1064575568165623p0"></a>Indicates the index of the capabilities.</p>
</td>
</tr>
<tr id="row659510209165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry820553254165623p0"><a name="entry820553254165623p0"></a><a name="entry820553254165623p0"></a>cap</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1485528430165623p0"><a name="entry1485528430165623p0"></a><a name="entry1485528430165623p0"></a>Indicates the pointer to the capabilities.</p>
</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **CODEC\_SUCCESS**  if the capabilities corresponding to the index are available; returns  **CODEC\_END**  otherwise.

## CodecFlush\(\)<a name="gaa6ed6c24e29f8fdfbbb0a3d562260a6a"></a>

```
int32_t CodecFlush ([CODEC_HANDLETYPE](Codec.md#ga9381a619f36ac8d5d7f467d2f0404183) handle, [DirectionType](Codec.md#ga8ef30fa9c08e08c8706653571f9f5b81) directType )
```

**Description:**

Clears the cache when the codec component is the running state.

Generally, this function is called when the seek operation is performed during playback.

**Parameters:**

<a name="table224046171165623"></a>
<table><thead align="left"><tr id="row1032036238165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1330604650165623"><a name="p1330604650165623"></a><a name="p1330604650165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p269520649165623"><a name="p269520649165623"></a><a name="p269520649165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1912574295165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1703092390165623p0"><a name="entry1703092390165623p0"></a><a name="entry1703092390165623p0"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry784594854165623p0"><a name="entry784594854165623p0"></a><a name="entry784594854165623p0"></a>Indicates the handle of the codec component.</p>
</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value otherwise.

## CodecGetCapbility\(\)<a name="ga1a6fbf6e84e01fdc1af59caa4203ce8e"></a>

```
int32_t CodecGetCapbility ([AvCodecMime](Codec.md#ga1bee586eafa91dfb60f94ba40fc95faa) mime, [CodecType](Codec.md#ga03b4b6ae5fb82af68d46aaea3d3e4d79) type, uint32_t flags, [CodecCapbility](Codec.md#ga1876710b1f2fe1d80e8b9de9ff28e0e3) * cap )
```

**Description:**

Obtains the capabilities of a specified media type.

You can call this function to obtain the codec capabilities. The corresponding capabilities are described in the  **Capability**  structure, including the maximum and minimum resolutions, maximum and minimum bit rates, and supported profiles and levels. After obtaining the capabilities, determine whether they can meet your requirements, for example, whether specific media files can be played and whether audio and video frames can be compressed.

**Parameters:**

<a name="table1331672877165623"></a>
<table><thead align="left"><tr id="row188068518165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p618074542165623"><a name="p618074542165623"></a><a name="p618074542165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1828738336165623"><a name="p1828738336165623"></a><a name="p1828738336165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1724241910165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry151201627165623p0"><a name="entry151201627165623p0"></a><a name="entry151201627165623p0"></a>mime</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1554401923165623p0"><a name="entry1554401923165623p0"></a><a name="entry1554401923165623p0"></a>Indicates the media type. For details, see <a href="Codec.md#ga1bee586eafa91dfb60f94ba40fc95faa">AvCodecMime</a>.</p>
</td>
</tr>
<tr id="row2027398265165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry273144779165623p0"><a name="entry273144779165623p0"></a><a name="entry273144779165623p0"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry460770466165623p0"><a name="entry460770466165623p0"></a><a name="entry460770466165623p0"></a>Indicates the audio and video codec types. For details, see <a href="Codec.md#ga03b4b6ae5fb82af68d46aaea3d3e4d79">CodecType</a>.</p>
</td>
</tr>
<tr id="row309917978165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1615378194165623p0"><a name="entry1615378194165623p0"></a><a name="entry1615378194165623p0"></a>flags</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry990729557165623p0"><a name="entry990729557165623p0"></a><a name="entry990729557165623p0"></a>Indicates the audio and video codec flags. <strong id="b1270678015165623"><a name="b1270678015165623"></a><a name="b1270678015165623"></a>0</strong> indicates hardware codec, and <strong id="b586553264165623"><a name="b586553264165623"></a><a name="b586553264165623"></a>1</strong> indicates software codec.</p>
</td>
</tr>
<tr id="row1660697182165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1881537062165623p0"><a name="entry1881537062165623p0"></a><a name="entry1881537062165623p0"></a>cap</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1189441861165623p0"><a name="entry1189441861165623p0"></a><a name="entry1189441861165623p0"></a>Indicates the pointer to the capabilities.</p>
</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the codec is supported and capabilities are available; returns a non-zero value if the codec is not supported or the capabilities are unavailable.

## CodecGetParameter\(\)<a name="ga1d812eac032e3e05cf5bf71b03e93f65"></a>

```
int32_t CodecGetParameter ([CODEC_HANDLETYPE](Codec.md#ga9381a619f36ac8d5d7f467d2f0404183) handle, [Param](Param.md) * params, int paramCnt )
```

**Description:**

Obtains parameters from a codec component.

This function must be called after  [CodecCreate](Codec.md#ga74aa0395a51f004390f7a92fb68faddd).

**Parameters:**

<a name="table512324058165623"></a>
<table><thead align="left"><tr id="row140056585165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1231962364165623"><a name="p1231962364165623"></a><a name="p1231962364165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1191931693165623"><a name="p1191931693165623"></a><a name="p1191931693165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1921301705165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1860880307165623p0"><a name="entry1860880307165623p0"></a><a name="entry1860880307165623p0"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1098424771165623p0"><a name="entry1098424771165623p0"></a><a name="entry1098424771165623p0"></a>Indicates the handle of the codec component.</p>
</td>
</tr>
<tr id="row782415348165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1207161273165623p0"><a name="entry1207161273165623p0"></a><a name="entry1207161273165623p0"></a>params</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1011714619165623p0"><a name="entry1011714619165623p0"></a><a name="entry1011714619165623p0"></a>Indicates the pointer to the parameters in the array used when the component is created.</p>
</td>
</tr>
<tr id="row1591534092165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry363308804165623p0"><a name="entry363308804165623p0"></a><a name="entry363308804165623p0"></a>paramCnt</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry518111034165623p0"><a name="entry518111034165623p0"></a><a name="entry518111034165623p0"></a>Indicates the number of elements in the parameter array.</p>
</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if all parameters to obtain are supported; returns a non-zero value otherwise.

**See also:**

[CodecSetParameter](Codec.md#gaa080cf23aa5f77b30f3b90a026d97cc0)

## CodecInit\(\)<a name="gadb2714f1e7a69419cefd38a2ad1f9829"></a>

```
int32_t CodecInit ()
```

**Description:**

Initializes the internal audio and video submodules of the codec.

This function needs to be called only once in a process.

**Returns:**

Returns  **0**  if the initialization is successful; returns a non-zero value otherwise.

**See also:**

[CodecDeinit](Codec.md#ga2d6eb231ca7766990cfa8c1841637245)

## CodecQueueInput\(\)<a name="ga0daece8dbf22da84f926761c994819bc"></a>

```
int32_t CodecQueueInput ([CODEC_HANDLETYPE](Codec.md#ga9381a619f36ac8d5d7f467d2f0404183) handle, const [InputInfo](InputInfo.md) * inputData, uint32_t timeoutMs )
```

**Description:**

Queues input data.

This function works with  [CodecDequeInput](Codec.md#ga91d7e1566c90d7cb9ac846eecad0024f)  to implement input data transmission.

**Parameters:**

<a name="table795018847165623"></a>
<table><thead align="left"><tr id="row846508610165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p332346395165623"><a name="p332346395165623"></a><a name="p332346395165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1652694800165623"><a name="p1652694800165623"></a><a name="p1652694800165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row357355777165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1740912167165623p0"><a name="entry1740912167165623p0"></a><a name="entry1740912167165623p0"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1486423225165623p0"><a name="entry1486423225165623p0"></a><a name="entry1486423225165623p0"></a>Indicates the handle of the codec component.</p>
</td>
</tr>
<tr id="row1839033406165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry783192397165623p0"><a name="entry783192397165623p0"></a><a name="entry783192397165623p0"></a>inputData</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1701104845165623p0"><a name="entry1701104845165623p0"></a><a name="entry1701104845165623p0"></a>Indicates the pointer to the input data.</p>
</td>
</tr>
<tr id="row962621700165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry275570521165623p0"><a name="entry275570521165623p0"></a><a name="entry275570521165623p0"></a>timeoutMs</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1159942435165623p0"><a name="entry1159942435165623p0"></a><a name="entry1159942435165623p0"></a>Indicates the timeout duration.</p>
</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value otherwise.

## CodecQueueOutput\(\)<a name="gac98f3505082c3cb2413d9e95eef9c804"></a>

```
int32_t CodecQueueOutput ([CODEC_HANDLETYPE](Codec.md#ga9381a619f36ac8d5d7f467d2f0404183) handle, [OutputInfo](OutputInfo.md) * outInfo, uint32_t timeoutMs, int releaseFenceFd )
```

**Description:**

Queues output data.

This function works with  [CodecDequeueOutput](Codec.md#gab575752467517eb8e6766773c1e3fb23)  to implement output data transmission.

**Parameters:**

<a name="table1621083179165623"></a>
<table><thead align="left"><tr id="row2034124956165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2007561559165623"><a name="p2007561559165623"></a><a name="p2007561559165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p767977174165623"><a name="p767977174165623"></a><a name="p767977174165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row404978930165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry105728502165623p0"><a name="entry105728502165623p0"></a><a name="entry105728502165623p0"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry507482430165623p0"><a name="entry507482430165623p0"></a><a name="entry507482430165623p0"></a>Indicates the handle of the codec component.</p>
</td>
</tr>
<tr id="row1897288263165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2104116936165623p0"><a name="entry2104116936165623p0"></a><a name="entry2104116936165623p0"></a>outInfo</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1204396216165623p0"><a name="entry1204396216165623p0"></a><a name="entry1204396216165623p0"></a>Indicates the pointer to the output data.</p>
</td>
</tr>
<tr id="row738008099165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1079580728165623p0"><a name="entry1079580728165623p0"></a><a name="entry1079580728165623p0"></a>timeoutMs</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1020571378165623p0"><a name="entry1020571378165623p0"></a><a name="entry1020571378165623p0"></a>Indicates the timeout duration.</p>
</td>
</tr>
<tr id="row2006711902165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1079278754165623p0"><a name="entry1079278754165623p0"></a><a name="entry1079278754165623p0"></a>releaseFenceFd</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry2068658895165623p0"><a name="entry2068658895165623p0"></a><a name="entry2068658895165623p0"></a>Indicates that the descriptor comes from a buffer consumer. The output data can be used only after waiting for <strong id="b811500889165623"><a name="b811500889165623"></a><a name="b811500889165623"></a>releaseFenceFd</strong> is successful. The value <strong id="b1031163191165623"><a name="b1031163191165623"></a><a name="b1031163191165623"></a>-1</strong> indicates that <strong id="b625036315165623"><a name="b625036315165623"></a><a name="b625036315165623"></a>releaseFenceFd</strong> is invalid.</p>
</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value otherwise.

## CodecSetCallback\(\)<a name="ga28ec6149d05765ee75f4836e0b092406"></a>

```
int32_t CodecSetCallback ([CODEC_HANDLETYPE](Codec.md#ga9381a619f36ac8d5d7f467d2f0404183) handle, const [CodecCallback](CodecCallback.md) * cb, [UINTPTR](Codec.md#ga58d2f4a8d12daa1dcf4eb297f3ebaabc) instance )
```

**Description:**

Sets the callback function.

The codec uses the callback function to notify the upper layer of events and asynchronously report available input/output information.

**Parameters:**

<a name="table92870444165623"></a>
<table><thead align="left"><tr id="row895458320165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1873072668165623"><a name="p1873072668165623"></a><a name="p1873072668165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p307867415165623"><a name="p307867415165623"></a><a name="p307867415165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row660866673165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2014983325165623p0"><a name="entry2014983325165623p0"></a><a name="entry2014983325165623p0"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry848731093165623p0"><a name="entry848731093165623p0"></a><a name="entry848731093165623p0"></a>Indicates the handle of the codec component.</p>
</td>
</tr>
<tr id="row483467393165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1097400715165623p0"><a name="entry1097400715165623p0"></a><a name="entry1097400715165623p0"></a>cb</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1078266696165623p0"><a name="entry1078266696165623p0"></a><a name="entry1078266696165623p0"></a>Indicates the pointer to the callback function. For details, see <a href="CodecCallback.md">CodecCallback</a>.</p>
</td>
</tr>
<tr id="row853510518165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry551596598165623p0"><a name="entry551596598165623p0"></a><a name="entry551596598165623p0"></a>instance</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1925556685165623p0"><a name="entry1925556685165623p0"></a><a name="entry1925556685165623p0"></a>Indicates the upper-layer instance to be notified.</p>
</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value otherwise.

## CodecSetParameter\(\)<a name="gaa080cf23aa5f77b30f3b90a026d97cc0"></a>

```
int32_t CodecSetParameter ([CODEC_HANDLETYPE](Codec.md#ga9381a619f36ac8d5d7f467d2f0404183) handle, const [Param](Param.md) * params, int paramCnt )
```

**Description:**

Sets parameters required by a codec component.

You should call this function to set parameters after  [CodecCreate](Codec.md#ga74aa0395a51f004390f7a92fb68faddd)  is called but before  [CodecStart](Codec.md#ga38c1744b0b4be5817ef49556ae665d18)  is called.

**Parameters:**

<a name="table954014077165623"></a>
<table><thead align="left"><tr id="row2019646240165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1436026489165623"><a name="p1436026489165623"></a><a name="p1436026489165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1171700396165623"><a name="p1171700396165623"></a><a name="p1171700396165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1968422939165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry85985223165623p0"><a name="entry85985223165623p0"></a><a name="entry85985223165623p0"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry311244140165623p0"><a name="entry311244140165623p0"></a><a name="entry311244140165623p0"></a>Indicates the handle of the codec component.</p>
</td>
</tr>
<tr id="row2083410672165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1999545117165623p0"><a name="entry1999545117165623p0"></a><a name="entry1999545117165623p0"></a>params</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1593116669165623p0"><a name="entry1593116669165623p0"></a><a name="entry1593116669165623p0"></a>Indicates the pointer to the parameters to set in the array.</p>
</td>
</tr>
<tr id="row1391853647165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1088510214165623p0"><a name="entry1088510214165623p0"></a><a name="entry1088510214165623p0"></a>paramCnt</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1969518525165623p0"><a name="entry1969518525165623p0"></a><a name="entry1969518525165623p0"></a>Indicates the number of elements in the parameter array.</p>
</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the setting is successful; returns a non-zero value otherwise.

**See also:**

[CodecGetParameter](Codec.md#ga1d812eac032e3e05cf5bf71b03e93f65)

## CodecSetPortMode\(\)<a name="ga36a994c5f9f4d104aad0c24b5e8cbd37"></a>

```
int32_t CodecSetPortMode ([CODEC_HANDLETYPE](Codec.md#ga9381a619f36ac8d5d7f467d2f0404183) handle, [DirectionType](Codec.md#ga8ef30fa9c08e08c8706653571f9f5b81) type, [BufferMode](Codec.md#gacc0fd55192fd9f663121b037b06f41e8) mode )
```

**Description:**

Sets the input or output buffer mode.

You can learn about the support of the codec input/output buffer for internal and external buffer modes by calling  [CodecGetCapbility](Codec.md#ga1a6fbf6e84e01fdc1af59caa4203ce8e). In this way, you can determine whether to use an internal or external buffer mode. If the current codec can use only the specific buffer mode, you do not need to set it.

**Parameters:**

<a name="table1772823408165623"></a>
<table><thead align="left"><tr id="row1788854922165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1271060639165623"><a name="p1271060639165623"></a><a name="p1271060639165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2048951433165623"><a name="p2048951433165623"></a><a name="p2048951433165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1262679035165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry901259990165623p0"><a name="entry901259990165623p0"></a><a name="entry901259990165623p0"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry917626217165623p0"><a name="entry917626217165623p0"></a><a name="entry917626217165623p0"></a>Indicates the handle of the codec component.</p>
</td>
</tr>
<tr id="row518655101165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1093565815165623p0"><a name="entry1093565815165623p0"></a><a name="entry1093565815165623p0"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry310127533165623p0"><a name="entry310127533165623p0"></a><a name="entry310127533165623p0"></a>Specifies whether the buffer type is an input type or an output type.</p>
</td>
</tr>
<tr id="row1850494814165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1925808627165623p0"><a name="entry1925808627165623p0"></a><a name="entry1925808627165623p0"></a>mode</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry126187904165623p0"><a name="entry126187904165623p0"></a><a name="entry126187904165623p0"></a>Specifies whether to use an internal or external buffer mode.</p>
</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the setting is successful; returns a non-zero value otherwise.

## CodecStart\(\)<a name="ga38c1744b0b4be5817ef49556ae665d18"></a>

```
int32_t CodecStart ([CODEC_HANDLETYPE](Codec.md#ga9381a619f36ac8d5d7f467d2f0404183) handle)
```

**Description:**

Starts a codec component.

You can restart a component after it is stopped.

**Parameters:**

<a name="table487343603165623"></a>
<table><thead align="left"><tr id="row1455666748165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1920817913165623"><a name="p1920817913165623"></a><a name="p1920817913165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p39022267165623"><a name="p39022267165623"></a><a name="p39022267165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row403360847165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry28663619165623p0"><a name="entry28663619165623p0"></a><a name="entry28663619165623p0"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry731590444165623p0"><a name="entry731590444165623p0"></a><a name="entry731590444165623p0"></a>Indicates the handle of the codec component.</p>
</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value otherwise.

## CodecStop\(\)<a name="ga8e7913c052c2e45e193fb0aab3f5c7fd"></a>

```
int32_t CodecStop ([CODEC_HANDLETYPE](Codec.md#ga9381a619f36ac8d5d7f467d2f0404183) handle)
```

**Description:**

Stops a codec component.

**Parameters:**

<a name="table1872475565165623"></a>
<table><thead align="left"><tr id="row1548979437165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1302334311165623"><a name="p1302334311165623"></a><a name="p1302334311165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p10154596165623"><a name="p10154596165623"></a><a name="p10154596165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row723631529165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2088727419165623p0"><a name="entry2088727419165623p0"></a><a name="entry2088727419165623p0"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1680481761165623p0"><a name="entry1680481761165623p0"></a><a name="entry1680481761165623p0"></a>Indicates the handle of the codec component.</p>
</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value otherwise.

