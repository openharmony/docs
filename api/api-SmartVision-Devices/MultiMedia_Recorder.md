# MultiMedia\_Recorder<a name="ZH-CN_TOPIC_0000001054799553"></a>

-   [Overview](#section1628426640165625)
-   [Summary](#section532867802165625)
-   [Files](#files)
-   [Data Structures](#nested-classes)
-   [Enumerations](#enum-members)
-   [Functions](#func-members)
-   [Details](#section1184400305165625)
-   [Enumeration Type](#section1963998659165625)
-   [DataSourceType](#gaccc05bb178cecd760369ea096dceae4c)
-   [FileSplitType](#ga8759c7e5a74964a584a716f4ec0b7edb)
-   [OutputFormatType](#ga3dfe2e61369bf1c081ce569e235354df)
-   [RecorderErrorType](#ga5132172c298fc1497d12040b6bd511cf)
-   [RecorderInfoType](#ga0db5cf9cc68d4b468e921a563248ffe0)
-   [VideoSourceType](#gad252d27f9ce4b6ae0756bfeaa5f34490)
-   [Function](#section552680935165625)
-   [GetSurface\(\)](#gad633e33fbbd5efcf4057aff3cc6e2b38)
-   [OnError\(\)](#ga822c915f1bfab8c380919f24f2ee4f54)
-   [OnInfo\(\)](#gac1f8bb191d90aac50119ea7ae4108407)
-   [Pause\(\)](#ga71da5cc2720b336f0daadbe09d61c695)
-   [Prepare\(\)](#ga15d2f3416bb735a0715e1e79be226387)
-   [Release\(\)](#ga116583c0d649f447c2dd272aae465cca)
-   [Reset\(\)](#gaebb808d5dd73b94b769b69e2b464c744)
-   [Resume\(\)](#gafd32ed157821800936a258a73af936be)
-   [SetAudioChannels\(\)](#ga77d76e5657cb3359e85521e08a456c7d)
-   [SetAudioEncoder\(\)](#gab37c9385fa1a56f686beb73c7dcc1b1b)
-   [SetAudioEncodingBitRate\(\)](#gac21a1a00c40cf58df84f1ba281b79a36)
-   [SetAudioSampleRate\(\)](#gab2b98616da55ec294053c0c25645c845)
-   [SetAudioSource\(\)](#gae287f59da8b3f1b6ca9f1c0e58a6565a)
-   [SetCaptureRate\(\)](#ga4f4a03fe881f48515874a699118fb84a)
-   [SetFileSplitDuration\(\)](#ga952ce2fada10d701e38e4ee29139e2af)
-   [SetMaxDuration\(\)](#gaf2806f0fddd17a3e59eb7c5c740470d6)
-   [SetMaxFileSize\(\)](#gaeed9ee49d9d1ac1497ec79bf9639c0bc)
-   [SetNextOutputFile\(\)](#ga8545fe87eb4bd399525e4c5fb414d7cb)
-   [SetOutputFile\(\)](#ga500d2bc895852fe292d7397d8450d091)
-   [SetOutputFormat\(\)](#gaffb7874aae331570ecedfe609a495468)
-   [SetOutputPath\(\)](#gaa5c898c1ad051b5c9f115ef15d952f18)
-   [SetParameter\(\)](#ga05cf279a460418b22d267527c83ede15)
-   [SetRecorderCallback\(\)](#ga882585460b0538680954ce6692610376)
-   [SetVideoEncoder\(\)](#gad9be6914af57fcf7acb7a5398118c614)
-   [SetVideoEncodingBitRate\(\)](#ga4e05a76b50abf790f29f06a0c1d4ecb8)
-   [SetVideoFrameRate\(\)](#gaeb90d4d75d80040aeaae354abd1d29d7)
-   [SetVideoSize\(\)](#ga43c0ee5b76f58a12c2c745839184a96b)
-   [SetVideoSource\(\)](#ga9e12ef9700d06c7620f9e3d7b4d844ca)
-   [Start\(\)](#gac3aaa32627f0799dea65e51356b91bfb)
-   [Stop\(\)](#ga1253f753cf9ed01dae5d57a37524dfa7)
-   [Variable](#section1577650583165625)
-   [RCORDER\_PRE\_CACHE\_DURATION](#gaaa77dd5c1745b9d5ba4b23c90206e936)

## **Overview**<a name="section1628426640165625"></a>

**Description:**

Defines the  **Recorder**  class and provides functions for audio and video recording. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section532867802165625"></a>

## Files<a name="files"></a>

<a name="table155313664165625"></a>
<table><thead align="left"><tr id="row1689615237165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1817042276165625"><a name="p1817042276165625"></a><a name="p1817042276165625"></a>File Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p41714176165625"><a name="p41714176165625"></a><a name="p41714176165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2128407175165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1585899371165625"><a name="p1585899371165625"></a><a name="p1585899371165625"></a><a href="recorder-h.md">recorder.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1878595529165625"><a name="p1878595529165625"></a><a name="p1878595529165625"></a>Declares the <strong id="b2082346453165625"><a name="b2082346453165625"></a><a name="b2082346453165625"></a>Recorder</strong> class for audio and video recording. </p>
</td>
</tr>
</tbody>
</table>

## Data Structures<a name="nested-classes"></a>

<a name="table860954426165625"></a>
<table><thead align="left"><tr id="row2040956872165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1595692268165625"><a name="p1595692268165625"></a><a name="p1595692268165625"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p578992391165625"><a name="p578992391165625"></a><a name="p578992391165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2014433664165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1900201516165625"><a name="p1900201516165625"></a><a name="p1900201516165625"></a><a href="OHOS-Media-RecorderCallback.md">OHOS::Media::RecorderCallback</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p312237472165625"><a name="p312237472165625"></a><a name="p312237472165625"></a>Provides listeners for recording errors and information events. </p>
</td>
</tr>
<tr id="row1041611920165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2132374681165625"><a name="p2132374681165625"></a><a name="p2132374681165625"></a><a href="OHOS-Media-Recorder.md">OHOS::Media::Recorder</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1771956976165625"><a name="p1771956976165625"></a><a name="p1771956976165625"></a>Provides functions for audio and video recording. </p>
</td>
</tr>
</tbody>
</table>

## Enumerations<a name="enum-members"></a>

<a name="table1210738318165625"></a>
<table><thead align="left"><tr id="row770577574165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1214757509165625"><a name="p1214757509165625"></a><a name="p1214757509165625"></a>Enumeration Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p591543752165625"><a name="p591543752165625"></a><a name="p591543752165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row947924212165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2083101189165625"><a name="p2083101189165625"></a><a name="p2083101189165625"></a><a href="MultiMedia_Recorder.md#gad252d27f9ce4b6ae0756bfeaa5f34490">OHOS::Media::VideoSourceType</a> : int32_t { <a href="MultiMedia_Recorder.md#ggad252d27f9ce4b6ae0756bfeaa5f34490ad137c55cd463c87ff8ea66c116da2e57">OHOS::Media::VIDEO_SOURCE_SURFACE_YUV</a> = 0, <a href="MultiMedia_Recorder.md#ggad252d27f9ce4b6ae0756bfeaa5f34490afcca9aba53005db99434c74f62803d6d">OHOS::Media::VIDEO_SOURCE_SURFACE_RGB</a>, <a href="MultiMedia_Recorder.md#ggad252d27f9ce4b6ae0756bfeaa5f34490a9316951d19d2ed845d2c0ef92c541eb8">OHOS::Media::VIDEO_SOURCE_SURFACE_ES</a>, <a href="MultiMedia_Recorder.md#ggad252d27f9ce4b6ae0756bfeaa5f34490af19a30a10d95948a7dab0317a4e2447b">OHOS::Media::VIDEO_SOURCE_BUTT</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p223254063165625"><a name="p223254063165625"></a><a name="p223254063165625"></a>Enumerates video source types. </p>
</td>
</tr>
<tr id="row749330763165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1031996993165625"><a name="p1031996993165625"></a><a name="p1031996993165625"></a><a href="MultiMedia_Recorder.md#gaccc05bb178cecd760369ea096dceae4c">OHOS::Media::DataSourceType</a> : int32_t { <a href="MultiMedia_Recorder.md#ggaccc05bb178cecd760369ea096dceae4ca18ab16c027cd6de93c4e64be806caed0">OHOS::Media::IMAGE</a> = 0 }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2027048464165625"><a name="p2027048464165625"></a><a name="p2027048464165625"></a>Enumerates data source types. </p>
</td>
</tr>
<tr id="row71491899165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p497590890165625"><a name="p497590890165625"></a><a name="p497590890165625"></a><a href="MultiMedia_Recorder.md#ga3dfe2e61369bf1c081ce569e235354df">OHOS::Media::OutputFormatType</a> : int32_t { <a href="MultiMedia_Recorder.md#gga3dfe2e61369bf1c081ce569e235354dfa5f2bb1abd7404320dcd46e7540a22586">OHOS::Media::FORMAT_DEFAULT</a> = 0, <a href="MultiMedia_Recorder.md#gga3dfe2e61369bf1c081ce569e235354dfac7e010e743dca6fc60780bb745707d57">OHOS::Media::FORMAT_MPEG_4</a>, <a href="MultiMedia_Recorder.md#gga3dfe2e61369bf1c081ce569e235354dfa2abf22281e8d5a30da1f0700d9bf45a3">OHOS::Media::FORMAT_TS</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p287992945165625"><a name="p287992945165625"></a><a name="p287992945165625"></a>Enumerates output file formats. </p>
</td>
</tr>
<tr id="row1987118298165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2041072367165625"><a name="p2041072367165625"></a><a name="p2041072367165625"></a><a href="MultiMedia_Recorder.md#ga8759c7e5a74964a584a716f4ec0b7edb">OHOS::Media::FileSplitType</a> : int32_t { <a href="MultiMedia_Recorder.md#gga8759c7e5a74964a584a716f4ec0b7edba9010fd43e012d61772ff5db3a9bdaf02">OHOS::Media::FILE_SPLIT_POST</a> = 0, <a href="MultiMedia_Recorder.md#gga8759c7e5a74964a584a716f4ec0b7edba01981748b792c27773467ea70099be65">OHOS::Media::FILE_SPLIT_PRE</a>, <a href="MultiMedia_Recorder.md#gga8759c7e5a74964a584a716f4ec0b7edbae05fb41e422f91399d2e2efc3e84943b">OHOS::Media::FILE_SPLIT_NORMAL</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1424870440165625"><a name="p1424870440165625"></a><a name="p1424870440165625"></a>Enumerates file split types. </p>
</td>
</tr>
<tr id="row1012514496165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1361188726165625"><a name="p1361188726165625"></a><a name="p1361188726165625"></a><a href="MultiMedia_Recorder.md#ga0db5cf9cc68d4b468e921a563248ffe0">OHOS::Media::RecorderCallback::RecorderInfoType</a> : int32_t {   <a href="MultiMedia_Recorder.md#gga0db5cf9cc68d4b468e921a563248ffe0af47b2244ca5d4a906657ace804c62ab5">OHOS::Media::RecorderCallback::RECORDER_INFO_MAX_DURATION_APPROACHING</a> = 0, <a href="MultiMedia_Recorder.md#gga0db5cf9cc68d4b468e921a563248ffe0ace19eeffeb7bfd809c0eecd831dfc4c8">OHOS::Media::RecorderCallback::RECORDER_INFO_MAX_FILESIZE_APPROACHING</a>, <a href="MultiMedia_Recorder.md#gga0db5cf9cc68d4b468e921a563248ffe0aa67fb963e882f4e45405e52a525d617e">OHOS::Media::RecorderCallback::RECORDER_INFO_MAX_DURATION_REACHED</a>, <a href="MultiMedia_Recorder.md#gga0db5cf9cc68d4b468e921a563248ffe0ad33be678eb5f4ec5c5db92d324ec0b27">OHOS::Media::RecorderCallback::RECORDER_INFO_MAX_FILESIZE_REACHED</a>,   <a href="MultiMedia_Recorder.md#gga0db5cf9cc68d4b468e921a563248ffe0ae27acecf4dec639f993091e2b4983d99">OHOS::Media::RecorderCallback::RECORDER_INFO_NEXT_OUTPUT_FILE_STARTED</a>, <a href="MultiMedia_Recorder.md#gga0db5cf9cc68d4b468e921a563248ffe0a0a2e4851229314e2d019b7418a13ce82">OHOS::Media::RecorderCallback::RECORDER_INFO_FILE_SPLIT_FINISHED</a>, <a href="MultiMedia_Recorder.md#gga0db5cf9cc68d4b468e921a563248ffe0abd5ed874b180a67a39c0edaa83a9e4d5">OHOS::Media::RecorderCallback::RECORDER_INFO_FILE_START_TIME_MS</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1797675503165625"><a name="p1797675503165625"></a><a name="p1797675503165625"></a>Enumerates recording information types. </p>
</td>
</tr>
<tr id="row351469527165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1656511848165625"><a name="p1656511848165625"></a><a name="p1656511848165625"></a><a href="MultiMedia_Recorder.md#ga5132172c298fc1497d12040b6bd511cf">OHOS::Media::RecorderCallback::RecorderErrorType</a> : int32_t { <a href="MultiMedia_Recorder.md#gga5132172c298fc1497d12040b6bd511cfa0e5cc2daf43191929754b01659128d79">OHOS::Media::RecorderCallback::RECORDER_ERROR_UNKNOWN</a> = 0 }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1548868554165625"><a name="p1548868554165625"></a><a name="p1548868554165625"></a>Enumerates recording error types. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table1090069004165625"></a>
<table><thead align="left"><tr id="row183784817165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p865995628165625"><a name="p865995628165625"></a><a name="p865995628165625"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p809925388165625"><a name="p809925388165625"></a><a name="p809925388165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1743165260165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p299237856165625"><a name="p299237856165625"></a><a name="p299237856165625"></a><a href="MultiMedia_Recorder.md#ga822c915f1bfab8c380919f24f2ee4f54">OHOS::Media::RecorderCallback::OnError</a> (int32_t errorType, int32_t errorCode)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1658574843165625"><a name="p1658574843165625"></a><a name="p1658574843165625"></a>virtual void </p>
<p id="p1335235941165625"><a name="p1335235941165625"></a><a name="p1335235941165625"></a>Called when an error occurs during recording. This callback is used to report recording errors. </p>
</td>
</tr>
<tr id="row2127801841165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1834887257165625"><a name="p1834887257165625"></a><a name="p1834887257165625"></a><a href="MultiMedia_Recorder.md#gac1f8bb191d90aac50119ea7ae4108407">OHOS::Media::RecorderCallback::OnInfo</a> (int32_t type, int32_t extra)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1373168540165625"><a name="p1373168540165625"></a><a name="p1373168540165625"></a>virtual void </p>
<p id="p1305258881165625"><a name="p1305258881165625"></a><a name="p1305258881165625"></a>Called when an information event occurs during recording. This callback is used to report recording information. </p>
</td>
</tr>
<tr id="row1869340870165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p392884675165625"><a name="p392884675165625"></a><a name="p392884675165625"></a><a href="MultiMedia_Recorder.md#ga9e12ef9700d06c7620f9e3d7b4d844ca">OHOS::Media::Recorder::SetVideoSource</a> (<a href="MultiMedia_Recorder.md#gad252d27f9ce4b6ae0756bfeaa5f34490">VideoSourceType</a> source, int32_t &amp;sourceId)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p185973288165625"><a name="p185973288165625"></a><a name="p185973288165625"></a>int32_t </p>
<p id="p2064094995165625"><a name="p2064094995165625"></a><a name="p2064094995165625"></a>Sets a video source for recording. </p>
</td>
</tr>
<tr id="row766742097165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1249796488165625"><a name="p1249796488165625"></a><a name="p1249796488165625"></a><a href="MultiMedia_Recorder.md#gad9be6914af57fcf7acb7a5398118c614">OHOS::Media::Recorder::SetVideoEncoder</a> (int32_t sourceId, <a href="MultiMedia_MediaCommon.md#ga797e6c5e38e23e730eff5bcc41427d7e">VideoCodecFormat</a> encoder)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p736330982165625"><a name="p736330982165625"></a><a name="p736330982165625"></a>int32_t </p>
<p id="p1501179777165625"><a name="p1501179777165625"></a><a name="p1501179777165625"></a>Sets a video encoder for recording. </p>
</td>
</tr>
<tr id="row817314962165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1420441970165625"><a name="p1420441970165625"></a><a name="p1420441970165625"></a><a href="MultiMedia_Recorder.md#ga43c0ee5b76f58a12c2c745839184a96b">OHOS::Media::Recorder::SetVideoSize</a> (int32_t sourceId, int32_t width, int32_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p537914163165625"><a name="p537914163165625"></a><a name="p537914163165625"></a>int32_t </p>
<p id="p1236466254165625"><a name="p1236466254165625"></a><a name="p1236466254165625"></a>Sets the width and height of the video to record. </p>
</td>
</tr>
<tr id="row601243690165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1908957533165625"><a name="p1908957533165625"></a><a name="p1908957533165625"></a><a href="MultiMedia_Recorder.md#gaeb90d4d75d80040aeaae354abd1d29d7">OHOS::Media::Recorder::SetVideoFrameRate</a> (int32_t sourceId, int32_t frameRate)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p13204468165625"><a name="p13204468165625"></a><a name="p13204468165625"></a>int32_t </p>
<p id="p1791009491165625"><a name="p1791009491165625"></a><a name="p1791009491165625"></a>Sets the frame rate of the video to record. </p>
</td>
</tr>
<tr id="row310285916165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p521194861165625"><a name="p521194861165625"></a><a name="p521194861165625"></a><a href="MultiMedia_Recorder.md#ga4e05a76b50abf790f29f06a0c1d4ecb8">OHOS::Media::Recorder::SetVideoEncodingBitRate</a> (int32_t sourceId, int32_t rate)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1389711914165625"><a name="p1389711914165625"></a><a name="p1389711914165625"></a>int32_t </p>
<p id="p138975016165625"><a name="p138975016165625"></a><a name="p138975016165625"></a>Sets the encoding bit rate of the video to record. </p>
</td>
</tr>
<tr id="row1592155440165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p708188946165625"><a name="p708188946165625"></a><a name="p708188946165625"></a><a href="MultiMedia_Recorder.md#ga4f4a03fe881f48515874a699118fb84a">OHOS::Media::Recorder::SetCaptureRate</a> (int32_t sourceId, double fps)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1757110886165625"><a name="p1757110886165625"></a><a name="p1757110886165625"></a>int32_t </p>
<p id="p1039718483165625"><a name="p1039718483165625"></a><a name="p1039718483165625"></a>Sets the video capture rate. </p>
</td>
</tr>
<tr id="row1835108896165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1416471765165625"><a name="p1416471765165625"></a><a name="p1416471765165625"></a><a href="MultiMedia_Recorder.md#gad633e33fbbd5efcf4057aff3cc6e2b38">OHOS::Media::Recorder::GetSurface</a> (int32_t sourceId)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p808345022165625"><a name="p808345022165625"></a><a name="p808345022165625"></a>std::shared_ptr&lt; <a href="OHOS-Surface.md">OHOS::Surface</a> &gt; </p>
<p id="p122051393165625"><a name="p122051393165625"></a><a name="p122051393165625"></a>Obtains the surface of the video source. </p>
</td>
</tr>
<tr id="row1686789448165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p337639498165625"><a name="p337639498165625"></a><a name="p337639498165625"></a><a href="MultiMedia_Recorder.md#gae287f59da8b3f1b6ca9f1c0e58a6565a">OHOS::Media::Recorder::SetAudioSource</a> (<a href="MultiMedia_MediaCommon.md#gadc3158e093b995ca7b9b6aa32388ccdd">AudioSourceType</a> source, int32_t &amp;sourceId)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p140536359165625"><a name="p140536359165625"></a><a name="p140536359165625"></a>int32_t </p>
<p id="p1528169442165625"><a name="p1528169442165625"></a><a name="p1528169442165625"></a>Sets the audio source for recording. </p>
</td>
</tr>
<tr id="row1725443150165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p181562325165625"><a name="p181562325165625"></a><a name="p181562325165625"></a><a href="MultiMedia_Recorder.md#gab37c9385fa1a56f686beb73c7dcc1b1b">OHOS::Media::Recorder::SetAudioEncoder</a> (int32_t sourceId, <a href="MultiMedia_MediaCommon.md#gaa4ea6f314644ed287e0704be26c768b7">AudioCodecFormat</a> encoder)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1377256200165625"><a name="p1377256200165625"></a><a name="p1377256200165625"></a>int32_t </p>
<p id="p58960735165625"><a name="p58960735165625"></a><a name="p58960735165625"></a>Sets an audio encoder for recording. </p>
</td>
</tr>
<tr id="row36406084165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1613948673165625"><a name="p1613948673165625"></a><a name="p1613948673165625"></a><a href="MultiMedia_Recorder.md#gab2b98616da55ec294053c0c25645c845">OHOS::Media::Recorder::SetAudioSampleRate</a> (int32_t sourceId, int32_t rate)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2020059663165625"><a name="p2020059663165625"></a><a name="p2020059663165625"></a>int32_t </p>
<p id="p432612330165625"><a name="p432612330165625"></a><a name="p432612330165625"></a>Sets the audio sampling rate for recording. </p>
</td>
</tr>
<tr id="row1840075736165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p141343360165625"><a name="p141343360165625"></a><a name="p141343360165625"></a><a href="MultiMedia_Recorder.md#ga77d76e5657cb3359e85521e08a456c7d">OHOS::Media::Recorder::SetAudioChannels</a> (int32_t sourceId, int32_t num)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p334614962165625"><a name="p334614962165625"></a><a name="p334614962165625"></a>int32_t </p>
<p id="p143098026165625"><a name="p143098026165625"></a><a name="p143098026165625"></a>Sets the number of audio channels to record. </p>
</td>
</tr>
<tr id="row1168567982165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1213932893165625"><a name="p1213932893165625"></a><a name="p1213932893165625"></a><a href="MultiMedia_Recorder.md#gac21a1a00c40cf58df84f1ba281b79a36">OHOS::Media::Recorder::SetAudioEncodingBitRate</a> (int32_t sourceId, int32_t bitRate)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p912065179165625"><a name="p912065179165625"></a><a name="p912065179165625"></a>int32_t </p>
<p id="p1498801305165625"><a name="p1498801305165625"></a><a name="p1498801305165625"></a>Sets the encoding bit rate of the audio to record. </p>
</td>
</tr>
<tr id="row1754555620165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2031075931165625"><a name="p2031075931165625"></a><a name="p2031075931165625"></a><a href="MultiMedia_Recorder.md#gaf2806f0fddd17a3e59eb7c5c740470d6">OHOS::Media::Recorder::SetMaxDuration</a> (int32_t duration)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1930629048165625"><a name="p1930629048165625"></a><a name="p1930629048165625"></a>int32_t </p>
<p id="p606065712165625"><a name="p606065712165625"></a><a name="p606065712165625"></a>Sets the maximum duration of a recorded file, in seconds. </p>
</td>
</tr>
<tr id="row1740939128165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1392640445165625"><a name="p1392640445165625"></a><a name="p1392640445165625"></a><a href="MultiMedia_Recorder.md#gaffb7874aae331570ecedfe609a495468">OHOS::Media::Recorder::SetOutputFormat</a> (<a href="MultiMedia_Recorder.md#ga3dfe2e61369bf1c081ce569e235354df">OutputFormatType</a> format)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1820281370165625"><a name="p1820281370165625"></a><a name="p1820281370165625"></a>int32_t </p>
<p id="p246318039165625"><a name="p246318039165625"></a><a name="p246318039165625"></a>Sets the output file format. </p>
</td>
</tr>
<tr id="row324243362165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p97096079165625"><a name="p97096079165625"></a><a name="p97096079165625"></a><a href="MultiMedia_Recorder.md#gaa5c898c1ad051b5c9f115ef15d952f18">OHOS::Media::Recorder::SetOutputPath</a> (const string &amp;path)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p476112189165625"><a name="p476112189165625"></a><a name="p476112189165625"></a>int32_t </p>
<p id="p1168189180165625"><a name="p1168189180165625"></a><a name="p1168189180165625"></a>Sets the output file path. </p>
</td>
</tr>
<tr id="row1114406281165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1861039369165625"><a name="p1861039369165625"></a><a name="p1861039369165625"></a><a href="MultiMedia_Recorder.md#ga500d2bc895852fe292d7397d8450d091">OHOS::Media::Recorder::SetOutputFile</a> (int32_t fd)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1165640504165625"><a name="p1165640504165625"></a><a name="p1165640504165625"></a>int32_t </p>
<p id="p1999073066165625"><a name="p1999073066165625"></a><a name="p1999073066165625"></a>Sets the file descriptor (FD) of the output file. </p>
</td>
</tr>
<tr id="row1423062815165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p939185573165625"><a name="p939185573165625"></a><a name="p939185573165625"></a><a href="MultiMedia_Recorder.md#ga8545fe87eb4bd399525e4c5fb414d7cb">OHOS::Media::Recorder::SetNextOutputFile</a> (int32_t fd)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p617554937165625"><a name="p617554937165625"></a><a name="p617554937165625"></a>int32_t </p>
<p id="p1569812971165625"><a name="p1569812971165625"></a><a name="p1569812971165625"></a>Sets the FD of the next output file. </p>
</td>
</tr>
<tr id="row1773791844165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p927268990165625"><a name="p927268990165625"></a><a name="p927268990165625"></a><a href="MultiMedia_Recorder.md#gaeed9ee49d9d1ac1497ec79bf9639c0bc">OHOS::Media::Recorder::SetMaxFileSize</a> (int64_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1398408862165625"><a name="p1398408862165625"></a><a name="p1398408862165625"></a>int32_t </p>
<p id="p399681628165625"><a name="p399681628165625"></a><a name="p399681628165625"></a>Sets the maximum size of a recorded file, in bytes. </p>
</td>
</tr>
<tr id="row40000179165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p240779174165625"><a name="p240779174165625"></a><a name="p240779174165625"></a><a href="MultiMedia_Recorder.md#ga882585460b0538680954ce6692610376">OHOS::Media::Recorder::SetRecorderCallback</a> (const std::shared_ptr&lt; <a href="OHOS-Media-RecorderCallback.md">RecorderCallback</a> &gt; &amp;callback)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p21074161165625"><a name="p21074161165625"></a><a name="p21074161165625"></a>int32_t </p>
<p id="p426793344165625"><a name="p426793344165625"></a><a name="p426793344165625"></a>Registers a recording listener. </p>
</td>
</tr>
<tr id="row1918776005165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p178763296165625"><a name="p178763296165625"></a><a name="p178763296165625"></a><a href="MultiMedia_Recorder.md#ga15d2f3416bb735a0715e1e79be226387">OHOS::Media::Recorder::Prepare</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1119169139165625"><a name="p1119169139165625"></a><a name="p1119169139165625"></a>int32_t </p>
<p id="p1035236453165625"><a name="p1035236453165625"></a><a name="p1035236453165625"></a>Prepares for recording. </p>
</td>
</tr>
<tr id="row1896419437165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1193825401165625"><a name="p1193825401165625"></a><a name="p1193825401165625"></a><a href="MultiMedia_Recorder.md#gac3aaa32627f0799dea65e51356b91bfb">OHOS::Media::Recorder::Start</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p936231263165625"><a name="p936231263165625"></a><a name="p936231263165625"></a>int32_t </p>
<p id="p2066141316165625"><a name="p2066141316165625"></a><a name="p2066141316165625"></a>Starts recording. </p>
</td>
</tr>
<tr id="row410160965165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p477323403165625"><a name="p477323403165625"></a><a name="p477323403165625"></a><a href="MultiMedia_Recorder.md#ga71da5cc2720b336f0daadbe09d61c695">OHOS::Media::Recorder::Pause</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p293532277165625"><a name="p293532277165625"></a><a name="p293532277165625"></a>int32_t </p>
<p id="p1968368084165625"><a name="p1968368084165625"></a><a name="p1968368084165625"></a>Pauses recording. </p>
</td>
</tr>
<tr id="row1325812585165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p955857412165625"><a name="p955857412165625"></a><a name="p955857412165625"></a><a href="MultiMedia_Recorder.md#gafd32ed157821800936a258a73af936be">OHOS::Media::Recorder::Resume</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p609891660165625"><a name="p609891660165625"></a><a name="p609891660165625"></a>int32_t </p>
<p id="p1167321526165625"><a name="p1167321526165625"></a><a name="p1167321526165625"></a>Resumes recording. </p>
</td>
</tr>
<tr id="row696571335165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p129810288165625"><a name="p129810288165625"></a><a name="p129810288165625"></a><a href="MultiMedia_Recorder.md#ga1253f753cf9ed01dae5d57a37524dfa7">OHOS::Media::Recorder::Stop</a> (bool block)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1989426929165625"><a name="p1989426929165625"></a><a name="p1989426929165625"></a>int32_t </p>
<p id="p9848087165625"><a name="p9848087165625"></a><a name="p9848087165625"></a>Stops recording. </p>
</td>
</tr>
<tr id="row515450989165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p726799340165625"><a name="p726799340165625"></a><a name="p726799340165625"></a><a href="MultiMedia_Recorder.md#gaebb808d5dd73b94b769b69e2b464c744">OHOS::Media::Recorder::Reset</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1267666208165625"><a name="p1267666208165625"></a><a name="p1267666208165625"></a>int32_t </p>
<p id="p1192604594165625"><a name="p1192604594165625"></a><a name="p1192604594165625"></a>Resets the recording. </p>
</td>
</tr>
<tr id="row227395782165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2073631674165625"><a name="p2073631674165625"></a><a name="p2073631674165625"></a><a href="MultiMedia_Recorder.md#ga116583c0d649f447c2dd272aae465cca">OHOS::Media::Recorder::Release</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1724670707165625"><a name="p1724670707165625"></a><a name="p1724670707165625"></a>int32_t </p>
<p id="p296944753165625"><a name="p296944753165625"></a><a name="p296944753165625"></a>Releases recording resources. </p>
</td>
</tr>
<tr id="row814117883165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p7818751165625"><a name="p7818751165625"></a><a name="p7818751165625"></a><a href="MultiMedia_Recorder.md#ga952ce2fada10d701e38e4ee29139e2af">OHOS::Media::Recorder::SetFileSplitDuration</a> (<a href="MultiMedia_Recorder.md#ga8759c7e5a74964a584a716f4ec0b7edb">FileSplitType</a> type, int64_t timestamp, uint32_t duration)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1276580610165625"><a name="p1276580610165625"></a><a name="p1276580610165625"></a>int32_t </p>
<p id="p2015819518165625"><a name="p2015819518165625"></a><a name="p2015819518165625"></a>Manually splits a video. </p>
</td>
</tr>
<tr id="row1980278132165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p983214528165625"><a name="p983214528165625"></a><a name="p983214528165625"></a><a href="MultiMedia_Recorder.md#ga05cf279a460418b22d267527c83ede15">OHOS::Media::Recorder::SetParameter</a> (int32_t sourceId, const <a href="OHOS-Media-Format.md">Format</a> &amp;format)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p518932741165625"><a name="p518932741165625"></a><a name="p518932741165625"></a>int32_t </p>
<p id="p1586667609165625"><a name="p1586667609165625"></a><a name="p1586667609165625"></a>Sets an extended parameter for recording, for example, <strong id="b2014033851165625"><a name="b2014033851165625"></a><a name="b2014033851165625"></a>RCORDER_PRE_CACHE_DURATION</strong>. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1184400305165625"></a>

## **Enumeration Type **<a name="section1963998659165625"></a>

## DataSourceType<a name="gaccc05bb178cecd760369ea096dceae4c"></a>

```
enum [OHOS::Media::DataSourceType](MultiMedia_Recorder.md#gaccc05bb178cecd760369ea096dceae4c) : int32_t
```

 **Description:**

Enumerates data source types. 

<a name="table1584364821165625"></a>
<table><thead align="left"><tr id="row191738772165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p743068986165625"><a name="p743068986165625"></a><a name="p743068986165625"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2104699621165625"><a name="p2104699621165625"></a><a name="p2104699621165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1518455309165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaccc05bb178cecd760369ea096dceae4ca18ab16c027cd6de93c4e64be806caed0"><a name="ggaccc05bb178cecd760369ea096dceae4ca18ab16c027cd6de93c4e64be806caed0"></a><a name="ggaccc05bb178cecd760369ea096dceae4ca18ab16c027cd6de93c4e64be806caed0"></a></strong>IMAGE </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1618777069165625"><a name="p1618777069165625"></a><a name="p1618777069165625"></a><a href="OHOS-Image.md">Image</a> data source </p>
 </td>
</tr>
</tbody>
</table>

## FileSplitType<a name="ga8759c7e5a74964a584a716f4ec0b7edb"></a>

```
enum [OHOS::Media::FileSplitType](MultiMedia_Recorder.md#ga8759c7e5a74964a584a716f4ec0b7edb) : int32_t
```

 **Description:**

Enumerates file split types. 

<a name="table1985142972165625"></a>
<table><thead align="left"><tr id="row1025964693165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1375336986165625"><a name="p1375336986165625"></a><a name="p1375336986165625"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p55103039165625"><a name="p55103039165625"></a><a name="p55103039165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1386467802165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga8759c7e5a74964a584a716f4ec0b7edba9010fd43e012d61772ff5db3a9bdaf02"><a name="gga8759c7e5a74964a584a716f4ec0b7edba9010fd43e012d61772ff5db3a9bdaf02"></a><a name="gga8759c7e5a74964a584a716f4ec0b7edba9010fd43e012d61772ff5db3a9bdaf02"></a></strong>FILE_SPLIT_POST </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1472966406165625"><a name="p1472966406165625"></a><a name="p1472966406165625"></a>Delayed/Backward split </p>
 </td>
</tr>
<tr id="row597509133165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga8759c7e5a74964a584a716f4ec0b7edba01981748b792c27773467ea70099be65"><a name="gga8759c7e5a74964a584a716f4ec0b7edba01981748b792c27773467ea70099be65"></a><a name="gga8759c7e5a74964a584a716f4ec0b7edba01981748b792c27773467ea70099be65"></a></strong>FILE_SPLIT_PRE </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1626411080165625"><a name="p1626411080165625"></a><a name="p1626411080165625"></a>Advanced/Forward split </p>
 </td>
</tr>
<tr id="row1856496793165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga8759c7e5a74964a584a716f4ec0b7edbae05fb41e422f91399d2e2efc3e84943b"><a name="gga8759c7e5a74964a584a716f4ec0b7edbae05fb41e422f91399d2e2efc3e84943b"></a><a name="gga8759c7e5a74964a584a716f4ec0b7edbae05fb41e422f91399d2e2efc3e84943b"></a></strong>FILE_SPLIT_NORMAL </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1957835281165625"><a name="p1957835281165625"></a><a name="p1957835281165625"></a>Normal split </p>
 </td>
</tr>
</tbody>
</table>

## OutputFormatType<a name="ga3dfe2e61369bf1c081ce569e235354df"></a>

```
enum [OHOS::Media::OutputFormatType](MultiMedia_Recorder.md#ga3dfe2e61369bf1c081ce569e235354df) : int32_t
```

 **Description:**

Enumerates output file formats. 

<a name="table555929568165625"></a>
<table><thead align="left"><tr id="row193409535165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p378350555165625"><a name="p378350555165625"></a><a name="p378350555165625"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p876004005165625"><a name="p876004005165625"></a><a name="p876004005165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row789575613165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga3dfe2e61369bf1c081ce569e235354dfa5f2bb1abd7404320dcd46e7540a22586"><a name="gga3dfe2e61369bf1c081ce569e235354dfa5f2bb1abd7404320dcd46e7540a22586"></a><a name="gga3dfe2e61369bf1c081ce569e235354dfa5f2bb1abd7404320dcd46e7540a22586"></a></strong>FORMAT_DEFAULT </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p765896427165625"><a name="p765896427165625"></a><a name="p765896427165625"></a>Default format </p>
 </td>
</tr>
<tr id="row477212355165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga3dfe2e61369bf1c081ce569e235354dfac7e010e743dca6fc60780bb745707d57"><a name="gga3dfe2e61369bf1c081ce569e235354dfac7e010e743dca6fc60780bb745707d57"></a><a name="gga3dfe2e61369bf1c081ce569e235354dfac7e010e743dca6fc60780bb745707d57"></a></strong>FORMAT_MPEG_4 </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1905232248165625"><a name="p1905232248165625"></a><a name="p1905232248165625"></a>MPEG4 format </p>
 </td>
</tr>
<tr id="row1801211516165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga3dfe2e61369bf1c081ce569e235354dfa2abf22281e8d5a30da1f0700d9bf45a3"><a name="gga3dfe2e61369bf1c081ce569e235354dfa2abf22281e8d5a30da1f0700d9bf45a3"></a><a name="gga3dfe2e61369bf1c081ce569e235354dfa2abf22281e8d5a30da1f0700d9bf45a3"></a></strong>FORMAT_TS </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2042902185165625"><a name="p2042902185165625"></a><a name="p2042902185165625"></a>TS format </p>
 </td>
</tr>
</tbody>
</table>

## RecorderErrorType<a name="ga5132172c298fc1497d12040b6bd511cf"></a>

```
enum [OHOS::Media::RecorderCallback::RecorderErrorType](MultiMedia_Recorder.md#ga5132172c298fc1497d12040b6bd511cf) : int32_t
```

 **Description:**

Enumerates recording error types. 

<a name="table489540687165625"></a>
<table><thead align="left"><tr id="row716271420165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1992421881165625"><a name="p1992421881165625"></a><a name="p1992421881165625"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1791037652165625"><a name="p1791037652165625"></a><a name="p1791037652165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2020002970165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga5132172c298fc1497d12040b6bd511cfa0e5cc2daf43191929754b01659128d79"><a name="gga5132172c298fc1497d12040b6bd511cfa0e5cc2daf43191929754b01659128d79"></a><a name="gga5132172c298fc1497d12040b6bd511cfa0e5cc2daf43191929754b01659128d79"></a></strong>RECORDER_ERROR_UNKNOWN </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p433295514165625"><a name="p433295514165625"></a><a name="p433295514165625"></a>Unknown error </p>
 </td>
</tr>
</tbody>
</table>

## RecorderInfoType<a name="ga0db5cf9cc68d4b468e921a563248ffe0"></a>

```
enum [OHOS::Media::RecorderCallback::RecorderInfoType](MultiMedia_Recorder.md#ga0db5cf9cc68d4b468e921a563248ffe0) : int32_t
```

 **Description:**

Enumerates recording information types. 

<a name="table1782863642165625"></a>
<table><thead align="left"><tr id="row252548521165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p845617400165625"><a name="p845617400165625"></a><a name="p845617400165625"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p390203004165625"><a name="p390203004165625"></a><a name="p390203004165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1694658963165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga0db5cf9cc68d4b468e921a563248ffe0af47b2244ca5d4a906657ace804c62ab5"><a name="gga0db5cf9cc68d4b468e921a563248ffe0af47b2244ca5d4a906657ace804c62ab5"></a><a name="gga0db5cf9cc68d4b468e921a563248ffe0af47b2244ca5d4a906657ace804c62ab5"></a></strong>RECORDER_INFO_MAX_DURATION_APPROACHING </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p200948449165625"><a name="p200948449165625"></a><a name="p200948449165625"></a>The recording duration is reaching the threshold specified by <strong id="b959221165625"><a name="b959221165625"></a><a name="b959221165625"></a>SetMaxDuration</strong>. This type of information is reported when only one second or 10% is left to reach the allowed duration. </p>
 </td>
</tr>
<tr id="row430100127165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga0db5cf9cc68d4b468e921a563248ffe0ace19eeffeb7bfd809c0eecd831dfc4c8"><a name="gga0db5cf9cc68d4b468e921a563248ffe0ace19eeffeb7bfd809c0eecd831dfc4c8"></a><a name="gga0db5cf9cc68d4b468e921a563248ffe0ace19eeffeb7bfd809c0eecd831dfc4c8"></a></strong>RECORDER_INFO_MAX_FILESIZE_APPROACHING </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2076090041165625"><a name="p2076090041165625"></a><a name="p2076090041165625"></a>The recorded file size is reaching the threshold specified by <strong id="b2132349486165625"><a name="b2132349486165625"></a><a name="b2132349486165625"></a>SetMaxFileSize</strong>. This type of information is reported when only 100 KB or 10% is left to reach the allowed size. </p>
 </td>
</tr>
<tr id="row426433661165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga0db5cf9cc68d4b468e921a563248ffe0aa67fb963e882f4e45405e52a525d617e"><a name="gga0db5cf9cc68d4b468e921a563248ffe0aa67fb963e882f4e45405e52a525d617e"></a><a name="gga0db5cf9cc68d4b468e921a563248ffe0aa67fb963e882f4e45405e52a525d617e"></a></strong>RECORDER_INFO_MAX_DURATION_REACHED </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1143843251165625"><a name="p1143843251165625"></a><a name="p1143843251165625"></a>The threshold specified by <strong id="b783314775165625"><a name="b783314775165625"></a><a name="b783314775165625"></a>SetMaxDuration</strong> is reached, and the recording ends. Before calling <strong id="b758453050165625"><a name="b758453050165625"></a><a name="b758453050165625"></a>SetOutputFile</strong>, you must close the file. </p>
 </td>
</tr>
<tr id="row1721218614165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga0db5cf9cc68d4b468e921a563248ffe0ad33be678eb5f4ec5c5db92d324ec0b27"><a name="gga0db5cf9cc68d4b468e921a563248ffe0ad33be678eb5f4ec5c5db92d324ec0b27"></a><a name="gga0db5cf9cc68d4b468e921a563248ffe0ad33be678eb5f4ec5c5db92d324ec0b27"></a></strong>RECORDER_INFO_MAX_FILESIZE_REACHED </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1535130251165625"><a name="p1535130251165625"></a><a name="p1535130251165625"></a>The threshold specified by <strong id="b2116012158165625"><a name="b2116012158165625"></a><a name="b2116012158165625"></a>SetMaxFileSize</strong> is reached, and the recording ends. Before calling <strong id="b329121284165625"><a name="b329121284165625"></a><a name="b329121284165625"></a>SetOutputFile</strong>, you must close the file. </p>
 </td>
</tr>
<tr id="row1150713506165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga0db5cf9cc68d4b468e921a563248ffe0ae27acecf4dec639f993091e2b4983d99"><a name="gga0db5cf9cc68d4b468e921a563248ffe0ae27acecf4dec639f993091e2b4983d99"></a><a name="gga0db5cf9cc68d4b468e921a563248ffe0ae27acecf4dec639f993091e2b4983d99"></a></strong>RECORDER_INFO_NEXT_OUTPUT_FILE_STARTED </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1580339676165625"><a name="p1580339676165625"></a><a name="p1580339676165625"></a>Recording started for the next output file. </p>
 </td>
</tr>
<tr id="row1590208081165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga0db5cf9cc68d4b468e921a563248ffe0a0a2e4851229314e2d019b7418a13ce82"><a name="gga0db5cf9cc68d4b468e921a563248ffe0a0a2e4851229314e2d019b7418a13ce82"></a><a name="gga0db5cf9cc68d4b468e921a563248ffe0a0a2e4851229314e2d019b7418a13ce82"></a></strong>RECORDER_INFO_FILE_SPLIT_FINISHED </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p735875646165625"><a name="p735875646165625"></a><a name="p735875646165625"></a>Manual file split completed. </p>
 </td>
</tr>
<tr id="row1436634446165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga0db5cf9cc68d4b468e921a563248ffe0abd5ed874b180a67a39c0edaa83a9e4d5"><a name="gga0db5cf9cc68d4b468e921a563248ffe0abd5ed874b180a67a39c0edaa83a9e4d5"></a><a name="gga0db5cf9cc68d4b468e921a563248ffe0abd5ed874b180a67a39c0edaa83a9e4d5"></a></strong>RECORDER_INFO_FILE_START_TIME_MS </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1971829214165625"><a name="p1971829214165625"></a><a name="p1971829214165625"></a>The start time position of the recording file is not supported. </p>
 </td>
</tr>
</tbody>
</table>

## VideoSourceType<a name="gad252d27f9ce4b6ae0756bfeaa5f34490"></a>

```
enum [OHOS::Media::VideoSourceType](MultiMedia_Recorder.md#gad252d27f9ce4b6ae0756bfeaa5f34490) : int32_t
```

 **Description:**

Enumerates video source types. 

<a name="table1893851963165625"></a>
<table><thead align="left"><tr id="row1502869715165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1502473831165625"><a name="p1502473831165625"></a><a name="p1502473831165625"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1159801323165625"><a name="p1159801323165625"></a><a name="p1159801323165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row748910332165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggad252d27f9ce4b6ae0756bfeaa5f34490ad137c55cd463c87ff8ea66c116da2e57"><a name="ggad252d27f9ce4b6ae0756bfeaa5f34490ad137c55cd463c87ff8ea66c116da2e57"></a><a name="ggad252d27f9ce4b6ae0756bfeaa5f34490ad137c55cd463c87ff8ea66c116da2e57"></a></strong>VIDEO_SOURCE_SURFACE_YUV </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1394035196165625"><a name="p1394035196165625"></a><a name="p1394035196165625"></a>YUV video data provided through <a href="Surface.md">Surface</a> </p>
 </td>
</tr>
<tr id="row1469561211165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggad252d27f9ce4b6ae0756bfeaa5f34490afcca9aba53005db99434c74f62803d6d"><a name="ggad252d27f9ce4b6ae0756bfeaa5f34490afcca9aba53005db99434c74f62803d6d"></a><a name="ggad252d27f9ce4b6ae0756bfeaa5f34490afcca9aba53005db99434c74f62803d6d"></a></strong>VIDEO_SOURCE_SURFACE_RGB </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p822478131165625"><a name="p822478131165625"></a><a name="p822478131165625"></a>RGB video data provided through <a href="Surface.md">Surface</a> </p>
 </td>
</tr>
<tr id="row251839654165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggad252d27f9ce4b6ae0756bfeaa5f34490a9316951d19d2ed845d2c0ef92c541eb8"><a name="ggad252d27f9ce4b6ae0756bfeaa5f34490a9316951d19d2ed845d2c0ef92c541eb8"></a><a name="ggad252d27f9ce4b6ae0756bfeaa5f34490a9316951d19d2ed845d2c0ef92c541eb8"></a></strong>VIDEO_SOURCE_SURFACE_ES </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1314486561165625"><a name="p1314486561165625"></a><a name="p1314486561165625"></a>Raw encoded data provided through <a href="Surface.md">Surface</a> </p>
 </td>
</tr>
<tr id="row674796797165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggad252d27f9ce4b6ae0756bfeaa5f34490af19a30a10d95948a7dab0317a4e2447b"><a name="ggad252d27f9ce4b6ae0756bfeaa5f34490af19a30a10d95948a7dab0317a4e2447b"></a><a name="ggad252d27f9ce4b6ae0756bfeaa5f34490af19a30a10d95948a7dab0317a4e2447b"></a></strong>VIDEO_SOURCE_BUTT </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p584685089165625"><a name="p584685089165625"></a><a name="p584685089165625"></a>Invalid value </p>
 </td>
</tr>
</tbody>
</table>

## **Function **<a name="section552680935165625"></a>

## GetSurface\(\)<a name="gad633e33fbbd5efcf4057aff3cc6e2b38"></a>

```
std::shared_ptr<[OHOS::Surface](OHOS-Surface.md)> OHOS::Media::Recorder::GetSurface (int32_t sourceId)
```

 **Description:**

Obtains the surface of the video source. 

**Parameters:**

<a name="table1017965912165625"></a>
<table><thead align="left"><tr id="row402111654165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p74069715165625"><a name="p74069715165625"></a><a name="p74069715165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1681452834165625"><a name="p1681452834165625"></a><a name="p1681452834165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1608843765165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sourceId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the video source ID, which can be obtained from <a href="MultiMedia_Recorder.md#ga9e12ef9700d06c7620f9e3d7b4d844ca">SetVideoSource</a>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the pointer to the surface. 

## OnError\(\)<a name="ga822c915f1bfab8c380919f24f2ee4f54"></a>

```
virtual void OHOS::Media::RecorderCallback::OnError (int32_t errorType, int32_t errorCode )
```

 **Description:**

Called when an error occurs during recording. This callback is used to report recording errors. 

**Parameters:**

<a name="table2042972903165625"></a>
<table><thead align="left"><tr id="row1493293724165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1734236831165625"><a name="p1734236831165625"></a><a name="p1734236831165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1093263640165625"><a name="p1093263640165625"></a><a name="p1093263640165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row341747279165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">errorType</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the error type. For details, see <a href="MultiMedia_Recorder.md#ga5132172c298fc1497d12040b6bd511cf">RecorderErrorType</a>. </td>
</tr>
<tr id="row155516811165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">errorCode</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the error code. </td>
</tr>
</tbody>
</table>

## OnInfo\(\)<a name="gac1f8bb191d90aac50119ea7ae4108407"></a>

```
virtual void OHOS::Media::RecorderCallback::OnInfo (int32_t type, int32_t extra )
```

 **Description:**

Called when an information event occurs during recording. This callback is used to report recording information. 

**Parameters:**

<a name="table1048118657165625"></a>
<table><thead align="left"><tr id="row1322905322165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p770224148165625"><a name="p770224148165625"></a><a name="p770224148165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1670835274165625"><a name="p1670835274165625"></a><a name="p1670835274165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1925316887165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">type</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the information type. For details, see <a href="MultiMedia_Recorder.md#ga0db5cf9cc68d4b468e921a563248ffe0">RecorderInfoType</a>. </td>
</tr>
<tr id="row1253216502165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">extra</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates other information, for example, the start time position of a recording file. </td>
</tr>
</tbody>
</table>

## Pause\(\)<a name="ga71da5cc2720b336f0daadbe09d61c695"></a>

```
int32_t OHOS::Media::Recorder::Pause ()
```

 **Description:**

Pauses recording. 

After  [Start](MultiMedia_Recorder.md#gac3aaa32627f0799dea65e51356b91bfb)  is called, you can call this function to pause recording. The audio and video source streams are not paused, and source data is discarded.

**Returns:**

Returns  **SUCCESS**  if the recording is paused; returns an error code defined in  [media\_errors.h](media_errors-h.md)  otherwise. 

## Prepare\(\)<a name="ga15d2f3416bb735a0715e1e79be226387"></a>

```
int32_t OHOS::Media::Recorder::Prepare ()
```

 **Description:**

Prepares for recording. 

This function must be called before  [Start](MultiMedia_Recorder.md#gac3aaa32627f0799dea65e51356b91bfb).

**Returns:**

Returns  **SUCCESS**  if the preparation is successful; returns an error code defined in  [media\_errors.h](media_errors-h.md)  otherwise. 

## Release\(\)<a name="ga116583c0d649f447c2dd272aae465cca"></a>

```
int32_t OHOS::Media::Recorder::Release ()
```

 **Description:**

Releases recording resources. 

**Returns:**

Returns  **SUCCESS**  if recording resources are released; returns an error code defined in  [media\_errors.h](media_errors-h.md)  otherwise. 

## Reset\(\)<a name="gaebb808d5dd73b94b769b69e2b464c744"></a>

```
int32_t OHOS::Media::Recorder::Reset ()
```

 **Description:**

Resets the recording. 

After the function is called, add a recording source by calling  [SetVideoSource](MultiMedia_Recorder.md#ga9e12ef9700d06c7620f9e3d7b4d844ca)  or  [SetAudioSource](MultiMedia_Recorder.md#gae287f59da8b3f1b6ca9f1c0e58a6565a), set related parameters, and call  [Start](MultiMedia_Recorder.md#gac3aaa32627f0799dea65e51356b91bfb)  to start recording again after  [Prepare](MultiMedia_Recorder.md#ga15d2f3416bb735a0715e1e79be226387)  is called.

**Returns:**

Returns  **SUCCESS**  if the recording is reset; returns an error code defined in  [media\_errors.h](media_errors-h.md)  otherwise. 

## Resume\(\)<a name="gafd32ed157821800936a258a73af936be"></a>

```
int32_t OHOS::Media::Recorder::Resume ()
```

 **Description:**

Resumes recording. 

You can call this function to resume recording after  [Pause](MultiMedia_Recorder.md#ga71da5cc2720b336f0daadbe09d61c695)  is called.

**Returns:**

Returns  **SUCCESS**  if the recording is resumed; returns an error code defined in  [media\_errors.h](media_errors-h.md)  otherwise. 

## SetAudioChannels\(\)<a name="ga77d76e5657cb3359e85521e08a456c7d"></a>

```
int32_t OHOS::Media::Recorder::SetAudioChannels (int32_t sourceId, int32_t num )
```

 **Description:**

Sets the number of audio channels to record. 

This function must be called after  [SetAudioSource](MultiMedia_Recorder.md#gae287f59da8b3f1b6ca9f1c0e58a6565a)  but before  [Prepare](MultiMedia_Recorder.md#ga15d2f3416bb735a0715e1e79be226387).

**Parameters:**

<a name="table1505795225165625"></a>
<table><thead align="left"><tr id="row1142805083165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p433801165625"><a name="p433801165625"></a><a name="p433801165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1354873971165625"><a name="p1354873971165625"></a><a name="p1354873971165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1645313415165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sourceId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the audio source ID, which can be obtained from <a href="MultiMedia_Recorder.md#gae287f59da8b3f1b6ca9f1c0e58a6565a">SetAudioSource</a>. </td>
</tr>
<tr id="row697040093165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">num</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the number of audio channels to set. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **SUCCESS**  if the setting is successful; returns an error code defined in  [media\_errors.h](media_errors-h.md)  otherwise. 

## SetAudioEncoder\(\)<a name="gab37c9385fa1a56f686beb73c7dcc1b1b"></a>

```
int32_t OHOS::Media::Recorder::SetAudioEncoder (int32_t sourceId, [AudioCodecFormat](MultiMedia_MediaCommon.md#gaa4ea6f314644ed287e0704be26c768b7) encoder )
```

 **Description:**

Sets an audio encoder for recording. 

If this function is not called, the output file does not contain the audio track. This function must be called after  [SetAudioSource](MultiMedia_Recorder.md#gae287f59da8b3f1b6ca9f1c0e58a6565a)  but before  [Prepare](MultiMedia_Recorder.md#ga15d2f3416bb735a0715e1e79be226387). 

**Parameters:**

<a name="table1626784439165625"></a>
<table><thead align="left"><tr id="row746833950165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p280230635165625"><a name="p280230635165625"></a><a name="p280230635165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p555337665165625"><a name="p555337665165625"></a><a name="p555337665165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row335415882165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sourceId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the audio source ID, which can be obtained from <a href="MultiMedia_Recorder.md#gae287f59da8b3f1b6ca9f1c0e58a6565a">SetAudioSource</a>. </td>
</tr>
<tr id="row2003742593165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">encoder</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the audio encoder to set. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **SUCCESS**  if the setting is successful; returns an error code defined in  [media\_errors.h](media_errors-h.md)  otherwise. 

## SetAudioEncodingBitRate\(\)<a name="gac21a1a00c40cf58df84f1ba281b79a36"></a>

```
int32_t OHOS::Media::Recorder::SetAudioEncodingBitRate (int32_t sourceId, int32_t bitRate )
```

 **Description:**

Sets the encoding bit rate of the audio to record. 

This function must be called after  [SetAudioSource](MultiMedia_Recorder.md#gae287f59da8b3f1b6ca9f1c0e58a6565a)  but before  [Prepare](MultiMedia_Recorder.md#ga15d2f3416bb735a0715e1e79be226387).

**Parameters:**

<a name="table569945784165625"></a>
<table><thead align="left"><tr id="row991085378165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1052173926165625"><a name="p1052173926165625"></a><a name="p1052173926165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1886210327165625"><a name="p1886210327165625"></a><a name="p1886210327165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2054590773165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sourceId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the audio source ID, which can be obtained from <a href="MultiMedia_Recorder.md#gae287f59da8b3f1b6ca9f1c0e58a6565a">SetAudioSource</a>. </td>
</tr>
<tr id="row1352896851165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">bitRate</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the audio encoding bit rate, in bit/s. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **SUCCESS**  if the setting is successful; returns an error code defined in  [media\_errors.h](media_errors-h.md)  otherwise. 

## SetAudioSampleRate\(\)<a name="gab2b98616da55ec294053c0c25645c845"></a>

```
int32_t OHOS::Media::Recorder::SetAudioSampleRate (int32_t sourceId, int32_t rate )
```

 **Description:**

Sets the audio sampling rate for recording. 

This function must be called after  [SetAudioSource](MultiMedia_Recorder.md#gae287f59da8b3f1b6ca9f1c0e58a6565a)  but before  [Prepare](MultiMedia_Recorder.md#ga15d2f3416bb735a0715e1e79be226387).

**Parameters:**

<a name="table32685028165625"></a>
<table><thead align="left"><tr id="row1034260464165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1736274465165625"><a name="p1736274465165625"></a><a name="p1736274465165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p935378925165625"><a name="p935378925165625"></a><a name="p935378925165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1952011900165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sourceId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the audio source ID, which can be obtained from <a href="MultiMedia_Recorder.md#gae287f59da8b3f1b6ca9f1c0e58a6565a">SetAudioSource</a>. </td>
</tr>
<tr id="row1049500645165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">rate</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the sampling rate of the audio per second. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **SUCCESS**  if the setting is successful; returns an error code defined in  [media\_errors.h](media_errors-h.md)  otherwise. 

## SetAudioSource\(\)<a name="gae287f59da8b3f1b6ca9f1c0e58a6565a"></a>

```
int32_t OHOS::Media::Recorder::SetAudioSource ([AudioSourceType](MultiMedia_MediaCommon.md#gadc3158e093b995ca7b9b6aa32388ccdd) source, int32_t & sourceId )
```

 **Description:**

Sets the audio source for recording. 

If this function is not called, the output file does not contain the audio track.

**Parameters:**

<a name="table1170129966165625"></a>
<table><thead align="left"><tr id="row1768704029165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1886735999165625"><a name="p1886735999165625"></a><a name="p1886735999165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p311068346165625"><a name="p311068346165625"></a><a name="p311068346165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2141170933165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">source</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the audio source type. For details, see <a href="MultiMedia_MediaCommon.md#gadc3158e093b995ca7b9b6aa32388ccdd">AudioSourceType</a>. </td>
</tr>
<tr id="row1018295884165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sourceId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the audio source ID. The value <strong id="b1830818143165625"><a name="b1830818143165625"></a><a name="b1830818143165625"></a>-1</strong> indicates an invalid ID and the setting fails. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **SUCCESS**  if the setting is successful; returns an error code defined in  [media\_errors.h](media_errors-h.md)  otherwise. 

## SetCaptureRate\(\)<a name="ga4f4a03fe881f48515874a699118fb84a"></a>

```
int32_t OHOS::Media::Recorder::SetCaptureRate (int32_t sourceId, double fps )
```

 **Description:**

Sets the video capture rate. 

This function must be called after  [SetVideoSource](MultiMedia_Recorder.md#ga9e12ef9700d06c7620f9e3d7b4d844ca)  but before  [Prepare](MultiMedia_Recorder.md#ga15d2f3416bb735a0715e1e79be226387). It is valid when the video source is YUV or RGB.

**Parameters:**

<a name="table1755340573165625"></a>
<table><thead align="left"><tr id="row556666995165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p770357890165625"><a name="p770357890165625"></a><a name="p770357890165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1548194315165625"><a name="p1548194315165625"></a><a name="p1548194315165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row340031483165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sourceId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the video source ID, which can be obtained from <a href="MultiMedia_Recorder.md#ga9e12ef9700d06c7620f9e3d7b4d844ca">SetVideoSource</a>. </td>
</tr>
<tr id="row768123517165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">fps</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the rate at which frames are captured per second. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **SUCCESS**  if the setting is successful; returns an error code defined in  [media\_errors.h](media_errors-h.md)  otherwise. 

## SetFileSplitDuration\(\)<a name="ga952ce2fada10d701e38e4ee29139e2af"></a>

```
int32_t OHOS::Media::Recorder::SetFileSplitDuration ([FileSplitType](MultiMedia_Recorder.md#ga8759c7e5a74964a584a716f4ec0b7edb) type, int64_t timestamp, uint32_t duration )
```

 **Description:**

Manually splits a video. 

This function must be called after  [Start](MultiMedia_Recorder.md#gac3aaa32627f0799dea65e51356b91bfb). After this function is called, the file is split based on the manual split type. After the manual split is complete, the initial split type is used. This function can be called again only after  **RECORDER\_INFO\_FILE\_SPLIT\_FINISHED**  is reported.

**Parameters:**

<a name="table2001481979165625"></a>
<table><thead align="left"><tr id="row1032258840165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1450487587165625"><a name="p1450487587165625"></a><a name="p1450487587165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p87335963165625"><a name="p87335963165625"></a><a name="p87335963165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row540268244165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">type</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the file split type. For details, see <strong id="b1992737578165625"><a name="b1992737578165625"></a><a name="b1992737578165625"></a>FileSplitType</strong>. </td>
</tr>
<tr id="row1663360155165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">timestamp</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the file split timestamp. This parameter is not supported currently and can be set to <strong id="b52256470165625"><a name="b52256470165625"></a><a name="b52256470165625"></a>-1</strong>. The recording module splits a file based on the call time. </td>
</tr>
<tr id="row825680098165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">duration</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the duration for splitting the file. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **SUCCESS**  if the video is manually split; returns an error code defined in  [media\_errors.h](media_errors-h.md)  otherwise. 

## SetMaxDuration\(\)<a name="gaf2806f0fddd17a3e59eb7c5c740470d6"></a>

```
int32_t OHOS::Media::Recorder::SetMaxDuration (int32_t duration)
```

 **Description:**

Sets the maximum duration of a recorded file, in seconds. 

This method must be called before  [Prepare](MultiMedia_Recorder.md#ga15d2f3416bb735a0715e1e79be226387). If the setting is valid,  **RECORDER\_INFO\_MAX\_DURATION\_APPROACHING**  is reported through  **OnInfo**  in the  [RecorderCallback](OHOS-Media-RecorderCallback.md)  class when only one second or 10% is left to reach the allowed duration. If the recording output file is set by calling  [SetOutputFile](MultiMedia_Recorder.md#ga500d2bc895852fe292d7397d8450d091), call  [SetNextOutputFile](MultiMedia_Recorder.md#ga8545fe87eb4bd399525e4c5fb414d7cb)  to set the next output file. Otherwise, the current file will be overwritten when the allowed duration is reached. 

**Parameters:**

<a name="table2026977889165625"></a>
<table><thead align="left"><tr id="row1040185753165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1122117233165625"><a name="p1122117233165625"></a><a name="p1122117233165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p88198799165625"><a name="p88198799165625"></a><a name="p88198799165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row482161847165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">duration</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the maximum recording duration to set. If the value is <strong id="b1759802488165625"><a name="b1759802488165625"></a><a name="b1759802488165625"></a>0</strong> or a negative number, a failure message is returned. The default duration is 60s. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **SUCCESS**  if the setting is successful; returns an error code defined in  [media\_errors.h](media_errors-h.md)  otherwise. 

## SetMaxFileSize\(\)<a name="gaeed9ee49d9d1ac1497ec79bf9639c0bc"></a>

```
int32_t OHOS::Media::Recorder::SetMaxFileSize (int64_t size)
```

 **Description:**

Sets the maximum size of a recorded file, in bytes. 

This function must be called before  [Prepare](MultiMedia_Recorder.md#ga15d2f3416bb735a0715e1e79be226387). If the setting is valid,  **RECORDER\_INFO\_MAX\_DURATION\_APPROACHING**  is reported through  **OnInfo**  in the  [RecorderCallback](OHOS-Media-RecorderCallback.md)  class when only 100 KB or 10% is left to reach the allowed size. If the recording output file is set by calling  [SetOutputFile](MultiMedia_Recorder.md#ga500d2bc895852fe292d7397d8450d091), call  [SetNextOutputFile](MultiMedia_Recorder.md#ga8545fe87eb4bd399525e4c5fb414d7cb)  to set the next output file. Otherwise, when the allowed size is reached, the current file will be overwritten. If  **MaxDuration**  is also set by calling  [SetMaxDuration](MultiMedia_Recorder.md#gaf2806f0fddd17a3e59eb7c5c740470d6),  **MaxDuration**  or  **MaxFileSize**  prevails depending on which of them is first satisfied.

**Parameters:**

<a name="table475941139165625"></a>
<table><thead align="left"><tr id="row1946967633165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p902974407165625"><a name="p902974407165625"></a><a name="p902974407165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1006682726165625"><a name="p1006682726165625"></a><a name="p1006682726165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1291455844165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">size</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the maximum file size to set. If the value is <strong id="b879797454165625"><a name="b879797454165625"></a><a name="b879797454165625"></a>0</strong> or a negative number, a failure message is returned. By default, the maximum size of a single file supported by the current file system is used as the limit. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **SUCCESS**  if the setting is successful; returns an error code defined in  [media\_errors.h](media_errors-h.md)  otherwise. 

## SetNextOutputFile\(\)<a name="ga8545fe87eb4bd399525e4c5fb414d7cb"></a>

```
int32_t OHOS::Media::Recorder::SetNextOutputFile (int32_t fd)
```

 **Description:**

Sets the FD of the next output file. 

If  [SetOutputFile](MultiMedia_Recorder.md#ga500d2bc895852fe292d7397d8450d091)  is successful, call this function to set the FD of the next output file after  **RECORDER\_INFO\_MAX\_DURATION\_APPROACHING**  or  **RECORDER\_INFO\_MAX\_FILESIZE\_APPROACHING**  is received.

**Parameters:**

<a name="table1312997381165625"></a>
<table><thead align="left"><tr id="row1892541271165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p233030846165625"><a name="p233030846165625"></a><a name="p233030846165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p370881923165625"><a name="p370881923165625"></a><a name="p370881923165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1585049950165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">fd</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the FD of the next output file. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **SUCCESS**  if the setting is successful; returns an error code defined in  [media\_errors.h](media_errors-h.md)  otherwise. 

## SetOutputFile\(\)<a name="ga500d2bc895852fe292d7397d8450d091"></a>

```
int32_t OHOS::Media::Recorder::SetOutputFile (int32_t fd)
```

 **Description:**

Sets the file descriptor \(FD\) of the output file. 

This function must be called before  [Prepare](MultiMedia_Recorder.md#ga15d2f3416bb735a0715e1e79be226387).

**Parameters:**

<a name="table1509840700165625"></a>
<table><thead align="left"><tr id="row1831072721165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p974675233165625"><a name="p974675233165625"></a><a name="p974675233165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p621827048165625"><a name="p621827048165625"></a><a name="p621827048165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1359131910165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">fd</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the FD of the file. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **SUCCESS**  if the setting is successful; returns an error code defined in  [media\_errors.h](media_errors-h.md)  otherwise. 

## SetOutputFormat\(\)<a name="gaffb7874aae331570ecedfe609a495468"></a>

```
int32_t OHOS::Media::Recorder::SetOutputFormat ([OutputFormatType](MultiMedia_Recorder.md#ga3dfe2e61369bf1c081ce569e235354df) format)
```

 **Description:**

Sets the output file format. 

This function must be called before  [Prepare](MultiMedia_Recorder.md#ga15d2f3416bb735a0715e1e79be226387).

**Parameters:**

<a name="table1796106931165625"></a>
<table><thead align="left"><tr id="row1990723767165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1069226789165625"><a name="p1069226789165625"></a><a name="p1069226789165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1285971786165625"><a name="p1285971786165625"></a><a name="p1285971786165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1193347519165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">format</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the output file format. For details, see <strong id="b879657148165625"><a name="b879657148165625"></a><a name="b879657148165625"></a>OutputFormatType</strong>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **SUCCESS**  if the setting is successful; returns an error code defined in  [media\_errors.h](media_errors-h.md)  otherwise. 

## SetOutputPath\(\)<a name="gaa5c898c1ad051b5c9f115ef15d952f18"></a>

```
int32_t OHOS::Media::Recorder::SetOutputPath (const string & path)
```

 **Description:**

Sets the output file path. 

This function must be called before  [Prepare](MultiMedia_Recorder.md#ga15d2f3416bb735a0715e1e79be226387)  and One of them  [SetOutputFile](MultiMedia_Recorder.md#ga500d2bc895852fe292d7397d8450d091)  must be set.

**Parameters:**

<a name="table129849551165625"></a>
<table><thead align="left"><tr id="row1665049195165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p812220951165625"><a name="p812220951165625"></a><a name="p812220951165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p243909874165625"><a name="p243909874165625"></a><a name="p243909874165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row973602590165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">path</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the output file path. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **SUCCESS**  if the setting is successful; returns an error code defined in  [media\_errors.h](media_errors-h.md)  otherwise. 

## SetParameter\(\)<a name="ga05cf279a460418b22d267527c83ede15"></a>

```
int32_t OHOS::Media::Recorder::SetParameter (int32_t sourceId, const [Format](OHOS-Media-Format.md) & format )
```

 **Description:**

Sets an extended parameter for recording, for example,  **RCORDER\_PRE\_CACHE\_DURATION**. 

**Parameters:**

<a name="table2069945259165625"></a>
<table><thead align="left"><tr id="row2060602229165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p785715504165625"><a name="p785715504165625"></a><a name="p785715504165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1324720104165625"><a name="p1324720104165625"></a><a name="p1324720104165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row722537855165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sourceId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the data source ID. The value <strong id="b1096933783165625"><a name="b1096933783165625"></a><a name="b1096933783165625"></a>-1</strong> indicates all sources. </td>
</tr>
<tr id="row392955411165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">format</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the string key and value. For details, see <a href="OHOS-Media-Format.md">Format</a> and <strong id="b851332751165625"><a name="b851332751165625"></a><a name="b851332751165625"></a>RCORDER_PRE_CACHE_DURATION</strong>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **SUCCESS**  if the setting is successful; returns an error code defined in  [media\_errors.h](media_errors-h.md)  otherwise. 

## SetRecorderCallback\(\)<a name="ga882585460b0538680954ce6692610376"></a>

```
int32_t OHOS::Media::Recorder::SetRecorderCallback (const std::shared_ptr< [RecorderCallback](OHOS-Media-RecorderCallback.md) > & callback)
```

 **Description:**

Registers a recording listener. 

This function must be called before  [Prepare](MultiMedia_Recorder.md#ga15d2f3416bb735a0715e1e79be226387).

**Parameters:**

<a name="table198502615165625"></a>
<table><thead align="left"><tr id="row941575464165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1201385918165625"><a name="p1201385918165625"></a><a name="p1201385918165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p570805735165625"><a name="p570805735165625"></a><a name="p570805735165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1494689526165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">callback</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the recording listener to register. For details, see <a href="OHOS-Media-RecorderCallback.md">RecorderCallback</a>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **SUCCESS**  if the listener is registered; returns an error code defined in  [media\_errors.h](media_errors-h.md)  otherwise. 

## SetVideoEncoder\(\)<a name="gad9be6914af57fcf7acb7a5398118c614"></a>

```
int32_t OHOS::Media::Recorder::SetVideoEncoder (int32_t sourceId, [VideoCodecFormat](MultiMedia_MediaCommon.md#ga797e6c5e38e23e730eff5bcc41427d7e) encoder )
```

 **Description:**

Sets a video encoder for recording. 

If this function is not called, the output file does not contain the video track. This function must be called after  [SetVideoSource](MultiMedia_Recorder.md#ga9e12ef9700d06c7620f9e3d7b4d844ca)  but before  [Prepare](MultiMedia_Recorder.md#ga15d2f3416bb735a0715e1e79be226387). 

**Parameters:**

<a name="table86494865165625"></a>
<table><thead align="left"><tr id="row639302071165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p541911701165625"><a name="p541911701165625"></a><a name="p541911701165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1161128753165625"><a name="p1161128753165625"></a><a name="p1161128753165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1203119863165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sourceId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the video source ID, which can be obtained from <a href="MultiMedia_Recorder.md#ga9e12ef9700d06c7620f9e3d7b4d844ca">SetVideoSource</a>. </td>
</tr>
<tr id="row1150689271165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">encoder</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the video encoder to set. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **SUCCESS**  if the setting is successful; returns an error code defined in  [media\_errors.h](media_errors-h.md)  otherwise. 

## SetVideoEncodingBitRate\(\)<a name="ga4e05a76b50abf790f29f06a0c1d4ecb8"></a>

```
int32_t OHOS::Media::Recorder::SetVideoEncodingBitRate (int32_t sourceId, int32_t rate )
```

 **Description:**

Sets the encoding bit rate of the video to record. 

This function must be called after  [SetVideoSource](MultiMedia_Recorder.md#ga9e12ef9700d06c7620f9e3d7b4d844ca)  but before  [Prepare](MultiMedia_Recorder.md#ga15d2f3416bb735a0715e1e79be226387).

**Parameters:**

<a name="table237347281165625"></a>
<table><thead align="left"><tr id="row1345881219165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p536220624165625"><a name="p536220624165625"></a><a name="p536220624165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p668278822165625"><a name="p668278822165625"></a><a name="p668278822165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1486441534165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sourceId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the video source ID, which can be obtained from <a href="MultiMedia_Recorder.md#ga9e12ef9700d06c7620f9e3d7b4d844ca">SetVideoSource</a>. </td>
</tr>
<tr id="row1797616011165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">rate</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the encoding bit rate to set. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **SUCCESS**  if the setting is successful; returns an error code defined in  [media\_errors.h](media_errors-h.md)  otherwise. 

## SetVideoFrameRate\(\)<a name="gaeb90d4d75d80040aeaae354abd1d29d7"></a>

```
int32_t OHOS::Media::Recorder::SetVideoFrameRate (int32_t sourceId, int32_t frameRate )
```

 **Description:**

Sets the frame rate of the video to record. 

This function must be called after  [SetVideoSource](MultiMedia_Recorder.md#ga9e12ef9700d06c7620f9e3d7b4d844ca)  but before  [Prepare](MultiMedia_Recorder.md#ga15d2f3416bb735a0715e1e79be226387).

**Parameters:**

<a name="table834152094165625"></a>
<table><thead align="left"><tr id="row1985354020165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p191002425165625"><a name="p191002425165625"></a><a name="p191002425165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1143710976165625"><a name="p1143710976165625"></a><a name="p1143710976165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1464325576165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sourceId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the video source ID, which can be obtained from <a href="MultiMedia_Recorder.md#ga9e12ef9700d06c7620f9e3d7b4d844ca">SetVideoSource</a>. </td>
</tr>
<tr id="row680925197165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">frameRate</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the frame rate to set. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **SUCCESS**  if the setting is successful; returns an error code defined in  [media\_errors.h](media_errors-h.md)  otherwise. 

## SetVideoSize\(\)<a name="ga43c0ee5b76f58a12c2c745839184a96b"></a>

```
int32_t OHOS::Media::Recorder::SetVideoSize (int32_t sourceId, int32_t width, int32_t height )
```

 **Description:**

Sets the width and height of the video to record. 

This function must be called after  [SetVideoSource](MultiMedia_Recorder.md#ga9e12ef9700d06c7620f9e3d7b4d844ca)  but before  [Prepare](MultiMedia_Recorder.md#ga15d2f3416bb735a0715e1e79be226387).

**Parameters:**

<a name="table510375395165625"></a>
<table><thead align="left"><tr id="row1728609297165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p922732653165625"><a name="p922732653165625"></a><a name="p922732653165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1405047737165625"><a name="p1405047737165625"></a><a name="p1405047737165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1597319453165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sourceId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the video source ID, which can be obtained from <a href="MultiMedia_Recorder.md#ga9e12ef9700d06c7620f9e3d7b4d844ca">SetVideoSource</a>. </td>
</tr>
<tr id="row179816678165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">width</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the video width to set. </td>
</tr>
<tr id="row522503261165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">height</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the video height to set. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **SUCCESS**  if the setting is successful; returns an error code defined in  [media\_errors.h](media_errors-h.md)  otherwise. 

## SetVideoSource\(\)<a name="ga9e12ef9700d06c7620f9e3d7b4d844ca"></a>

```
int32_t OHOS::Media::Recorder::SetVideoSource ([VideoSourceType](MultiMedia_Recorder.md#gad252d27f9ce4b6ae0756bfeaa5f34490) source, int32_t & sourceId )
```

 **Description:**

Sets a video source for recording. 

If this function is not called, the output file does not contain the video track.

**Parameters:**

<a name="table167987728165625"></a>
<table><thead align="left"><tr id="row2007341998165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p68349168165625"><a name="p68349168165625"></a><a name="p68349168165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2062753420165625"><a name="p2062753420165625"></a><a name="p2062753420165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row783778703165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">source</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the video source type. For details, see <strong id="b1612180082165625"><a name="b1612180082165625"></a><a name="b1612180082165625"></a>VideoSourceType</strong>. </td>
</tr>
<tr id="row335264368165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sourceId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the video source ID. The value <strong id="b304943150165625"><a name="b304943150165625"></a><a name="b304943150165625"></a>-1</strong> indicates an invalid ID and the setting fails.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **SUCCESS**  if the setting is successful; returns an error code defined in  [media\_errors.h](media_errors-h.md)  otherwise. 

## Start\(\)<a name="gac3aaa32627f0799dea65e51356b91bfb"></a>

```
int32_t OHOS::Media::Recorder::Start ()
```

 **Description:**

Starts recording. 

This function must be called after  [Prepare](MultiMedia_Recorder.md#ga15d2f3416bb735a0715e1e79be226387).

**Returns:**

Returns  **SUCCESS**  if the recording is started; returns an error code defined in  [media\_errors.h](media_errors-h.md)  otherwise. 

## Stop\(\)<a name="ga1253f753cf9ed01dae5d57a37524dfa7"></a>

```
int32_t OHOS::Media::Recorder::Stop (bool block)
```

 **Description:**

Stops recording. 

**Parameters:**

<a name="table1517216452165625"></a>
<table><thead align="left"><tr id="row888807462165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1217193402165625"><a name="p1217193402165625"></a><a name="p1217193402165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p722814440165625"><a name="p722814440165625"></a><a name="p722814440165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row371684298165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">block</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the stop mode. The value <strong id="b1538424005165625"><a name="b1538424005165625"></a><a name="b1538424005165625"></a>true</strong> indicates that the processing stops after all caches are processed, and <strong id="b2013049932165625"><a name="b2013049932165625"></a><a name="b2013049932165625"></a>false</strong> indicates that the processing stops immediately and all caches are discarded. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **SUCCESS**  if the recording is stopped; returns an error code defined in  [media\_errors.h](media_errors-h.md)  otherwise. 

## **Variable **<a name="section1577650583165625"></a>

## RCORDER\_PRE\_CACHE\_DURATION<a name="gaaa77dd5c1745b9d5ba4b23c90206e936"></a>

```
const string OHOS::Media::RCORDER_PRE_CACHE_DURATION = "pre-cache-duration"
```

 **Description:**

This constant can be used as the value of  [Format](OHOS-Media-Format.md)  in  [SetParameter](Parameter.md#ga2779b5e59d43308c51f7be38b9c98ddb)  to configure the duration for storing recorded data in the cache. 

