# MultiMedia\_Player<a name="ZH-CN_TOPIC_0000001055518042"></a>

-   [Overview](#section1987368586165625)
-   [Summary](#section525725604165625)
-   [Files](#files)
-   [Data Structures](#nested-classes)
-   [Enumerations](#enum-members)
-   [Functions](#func-members)
-   [Details](#section1769927466165625)
-   [Enumeration Type](#section40029736165625)
-   [PlayerInfoType](#ga7dac9dac65cbbea7e411adcf2c314ac5)
-   [PlayerSeekMode](#gad1574e5769b3174c2103a2a8b49e20d4)
-   [PlayerStates](#ga8b1147e57c4a67f63f193836302da2b7)
-   [Function](#section747638434165625)
-   [EnableSingleLooping\(\)](#gae19989aa6e80b768acd4eb019a2b60d2)
-   [GetCurrentTime\(\)](#ga8474b117a4c1bf5749406f26056b4802)
-   [GetDuration\(\)](#ga24ae07f65da4dafc4ec5aa28321625d8)
-   [GetVideoHeight\(\)](#ga726adc32a34134b30aabfbdb389c8357)
-   [GetVideoWidth\(\)](#ga9ed94bd43d896fa10066497377d7fbda)
-   [IsPlaying\(\)](#gaad6b2c35b1d5dfe453d158f7ff9e1379)
-   [IsSingleLooping\(\)](#gae4dd5d8fb92c836f5304f181a40b34d2)
-   [OnError\(\)](#ga3d0fdad57045f5e049b56de031d3e0fb)
-   [OnInfo\(\)](#gad2d3466c8a17ee4d622b87fa6a31b2bb)
-   [OnPlaybackComplete\(\)](#ga3b56f618340bf9a5590e6142b2311302)
-   [OnRewindToComplete\(\)](#ga765c499e47dfaad5e557197e964eaca3)
-   [OnVideoSizeChanged\(\)](#gac5b641f93621d90e616d18adaa016e8a)
-   [Pause\(\)](#gae1d2225ce60a9737cc902e586138a44f)
-   [Play\(\)](#gafecbbfe85c70cf4983f52d55b7205e3f)
-   [Prepare\(\)](#gade9bff3268e1c409273749a90700e056)
-   [Release\(\)](#ga00e24c0faed483c9d54e416ec2ffe6ac)
-   [Reset\(\)](#ga75e17ee0068d46d44a30709609821b85)
-   [Rewind\(\)](#ga406b6277d1e160e691d01f5f740480b3)
-   [SetPlayerCallback\(\)](#gabb6eca611514d5fc0b66df5ff2d70c2b)
-   [SetSource\(\)](#gacce284eac910970e405151fd3a1963c0)
-   [SetVideoSurface\(\)](#gac9d62210915ebcf3b462574302018501)
-   [SetVolume\(\)](#ga23ca57f0b1a288980e37153274c5f8b3)
-   [Stop\(\)](#gafe518a5b909ac0f0f066781caa3b55aa)

## **Overview**<a name="section1987368586165625"></a>

**Description:**

Defines the  **Player**  class and provides functions related to media playback. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section525725604165625"></a>

## Files<a name="files"></a>

<a name="table1695081084165625"></a>
<table><thead align="left"><tr id="row880899834165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1580256350165625"><a name="p1580256350165625"></a><a name="p1580256350165625"></a>File Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p132996110165625"><a name="p132996110165625"></a><a name="p132996110165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row753971658165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p654660719165625"><a name="p654660719165625"></a><a name="p654660719165625"></a><a href="player-h.md">player.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1926891914165625"><a name="p1926891914165625"></a><a name="p1926891914165625"></a>Declares the <strong id="b1735537598165625"><a name="b1735537598165625"></a><a name="b1735537598165625"></a>Player</strong> class, which is used to implement player-related operations. </p>
</td>
</tr>
</tbody>
</table>

## Data Structures<a name="nested-classes"></a>

<a name="table1264833793165625"></a>
<table><thead align="left"><tr id="row1970356294165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p557924600165625"><a name="p557924600165625"></a><a name="p557924600165625"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1270353241165625"><a name="p1270353241165625"></a><a name="p1270353241165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2145667499165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p976550520165625"><a name="p976550520165625"></a><a name="p976550520165625"></a><a href="OHOS-Media-PlayerCallback.md">OHOS::Media::PlayerCallback</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1480807111165625"><a name="p1480807111165625"></a><a name="p1480807111165625"></a>Provides listeners for events and exception notifications that occur during media playback. </p>
</td>
</tr>
<tr id="row546074091165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1804784722165625"><a name="p1804784722165625"></a><a name="p1804784722165625"></a><a href="OHOS-Media-Player.md">OHOS::Media::Player</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p976584807165625"><a name="p976584807165625"></a><a name="p976584807165625"></a>Provides functions for playing online movies, offline movies, and streams, for example, playing local movies and advanced audio coding (AAC) streams. </p>
</td>
</tr>
</tbody>
</table>

## Enumerations<a name="enum-members"></a>

<a name="table644623676165625"></a>
<table><thead align="left"><tr id="row951777255165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p776385294165625"><a name="p776385294165625"></a><a name="p776385294165625"></a>Enumeration Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p86744573165625"><a name="p86744573165625"></a><a name="p86744573165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row656611833165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p339665407165625"><a name="p339665407165625"></a><a name="p339665407165625"></a><a href="MultiMedia_Player.md#gad1574e5769b3174c2103a2a8b49e20d4">OHOS::Media::PlayerSeekMode</a> : int32_t {   <a href="MultiMedia_Player.md#ggad1574e5769b3174c2103a2a8b49e20d4a08be30187c1d180d77b375af6f35966c">OHOS::Media::PLAYER_SEEK_PREVIOUS_SYNC</a> = 0, <a href="MultiMedia_Player.md#ggad1574e5769b3174c2103a2a8b49e20d4a98aa52abc293a28728ef9d2e9019ae7d">OHOS::Media::PLAYER_SEEK_NEXT_SYNC</a>, <a href="MultiMedia_Player.md#ggad1574e5769b3174c2103a2a8b49e20d4ae6257ed93e90e2231eb3369a36027872">OHOS::Media::PLAYER_SEEK_CLOSEST_SYNC</a>, <a href="MultiMedia_Player.md#ggad1574e5769b3174c2103a2a8b49e20d4a0f6165a7f22f44f78bbb9004f2a55428">OHOS::Media::PLAYER_SEEK_CLOSEST</a>,   <a href="MultiMedia_Player.md#ggad1574e5769b3174c2103a2a8b49e20d4ada8db6c3cb45acbc0ff09cb3fe65fd94">OHOS::Media::PLAYER_SEEK_FRAME_INDEX</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1485567518165625"><a name="p1485567518165625"></a><a name="p1485567518165625"></a>Enumerates player seek modes. You can move the current playback position of the media to a given time position using the specified mode. </p>
</td>
</tr>
<tr id="row1968939963165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1197395465165625"><a name="p1197395465165625"></a><a name="p1197395465165625"></a><a href="MultiMedia_Player.md#ga8b1147e57c4a67f63f193836302da2b7">OHOS::Media::PlayerStates</a> : uint32_t {   <a href="MultiMedia_Player.md#gga8b1147e57c4a67f63f193836302da2b7a53755dd964e67b38f2b20a73043c6a15">OHOS::Media::PLAYER_STATE_ERROR</a> = 0, <a href="MultiMedia_Player.md#gga8b1147e57c4a67f63f193836302da2b7a422de416a9d98b7a11334080277e5a91">OHOS::Media::PLAYER_IDLE</a> = 1 &lt;&lt; 0, <a href="MultiMedia_Player.md#gga8b1147e57c4a67f63f193836302da2b7a9b85bb17a31e74c8913d3344a9890968">OHOS::Media::PLAYER_INITIALIZED</a> = 1 &lt;&lt; 1, <a href="MultiMedia_Player.md#gga8b1147e57c4a67f63f193836302da2b7a5f58beea6c3cfd9faf9d9dacb6d0de43">OHOS::Media::PLAYER_PREPARING</a> = 1 &lt;&lt; 2,   <a href="MultiMedia_Player.md#gga8b1147e57c4a67f63f193836302da2b7a992920b7152bf85ce28b0cbc2204a01b">OHOS::Media::PLAYER_PREPARED</a> = 1 &lt;&lt; 3, <a href="MultiMedia_Player.md#gga8b1147e57c4a67f63f193836302da2b7ab59f150a877432470b368cb6ae3c01d6">OHOS::Media::PLAYER_STARTED</a> = 1 &lt;&lt; 4, <a href="MultiMedia_Player.md#gga8b1147e57c4a67f63f193836302da2b7a865415ef0c33b942431a1814e84dd848">OHOS::Media::PLAYER_PAUSED</a> = 1 &lt;&lt; 5, <a href="MultiMedia_Player.md#gga8b1147e57c4a67f63f193836302da2b7a0d79ba704b9048d53deee264f6e6546d">OHOS::Media::PLAYER_STOPPED</a> = 1 &lt;&lt; 6,   <a href="MultiMedia_Player.md#gga8b1147e57c4a67f63f193836302da2b7ac5e465735c926d57e1bcb39eff208e51">OHOS::Media::PLAYER_PLAYBACK_COMPLETE</a> = 1 &lt;&lt; 7 }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p713779638165625"><a name="p713779638165625"></a><a name="p713779638165625"></a>Enumerates player states. </p>
</td>
</tr>
<tr id="row1381553907165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1482994909165625"><a name="p1482994909165625"></a><a name="p1482994909165625"></a><a href="MultiMedia_Player.md#ga7dac9dac65cbbea7e411adcf2c314ac5">OHOS::Media::PlayerCallback::PlayerInfoType</a> : int32_t { <a href="MultiMedia_Player.md#gga7dac9dac65cbbea7e411adcf2c314ac5ab5ccacbb568a9b3ce5fedc0ced4e683d">OHOS::Media::PlayerCallback::PLAYER_INFO_RENDER_START</a> = 0 }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">&nbsp;</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table807485849165625"></a>
<table><thead align="left"><tr id="row82001905165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p384910741165625"><a name="p384910741165625"></a><a name="p384910741165625"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p304240271165625"><a name="p304240271165625"></a><a name="p304240271165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row510122629165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p195221625165625"><a name="p195221625165625"></a><a name="p195221625165625"></a><a href="MultiMedia_Player.md#ga3b56f618340bf9a5590e6142b2311302">OHOS::Media::PlayerCallback::OnPlaybackComplete</a> ()=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p73097364165625"><a name="p73097364165625"></a><a name="p73097364165625"></a>virtual void </p>
<p id="p1265058499165625"><a name="p1265058499165625"></a><a name="p1265058499165625"></a>Called when the playback is complete. </p>
</td>
</tr>
<tr id="row1968116532165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2089590132165625"><a name="p2089590132165625"></a><a name="p2089590132165625"></a><a href="MultiMedia_Player.md#ga3d0fdad57045f5e049b56de031d3e0fb">OHOS::Media::PlayerCallback::OnError</a> (int32_t errorType, int32_t errorCode)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p455000284165625"><a name="p455000284165625"></a><a name="p455000284165625"></a>virtual void </p>
<p id="p15764428165625"><a name="p15764428165625"></a><a name="p15764428165625"></a>Called when a playback error occurs. </p>
</td>
</tr>
<tr id="row240697984165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1636451908165625"><a name="p1636451908165625"></a><a name="p1636451908165625"></a><a href="MultiMedia_Player.md#gad2d3466c8a17ee4d622b87fa6a31b2bb">OHOS::Media::PlayerCallback::OnInfo</a> (int type, int extra)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1103918872165625"><a name="p1103918872165625"></a><a name="p1103918872165625"></a>virtual void </p>
<p id="p2141670652165625"><a name="p2141670652165625"></a><a name="p2141670652165625"></a>Called when playback information is received. </p>
</td>
</tr>
<tr id="row1348065873165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1214421377165625"><a name="p1214421377165625"></a><a name="p1214421377165625"></a><a href="MultiMedia_Player.md#gac5b641f93621d90e616d18adaa016e8a">OHOS::Media::PlayerCallback::OnVideoSizeChanged</a> (int width, int height)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p585858587165625"><a name="p585858587165625"></a><a name="p585858587165625"></a>virtual void </p>
<p id="p570856545165625"><a name="p570856545165625"></a><a name="p570856545165625"></a>Called when the video image size changes. </p>
</td>
</tr>
<tr id="row909066098165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p97920152165625"><a name="p97920152165625"></a><a name="p97920152165625"></a><a href="MultiMedia_Player.md#ga765c499e47dfaad5e557197e964eaca3">OHOS::Media::PlayerCallback::OnRewindToComplete</a> ()=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1216933111165625"><a name="p1216933111165625"></a><a name="p1216933111165625"></a>virtual void </p>
<p id="p1159244037165625"><a name="p1159244037165625"></a><a name="p1159244037165625"></a>Called when the rewind is complete. </p>
</td>
</tr>
<tr id="row2041454171165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1719573933165625"><a name="p1719573933165625"></a><a name="p1719573933165625"></a><a href="MultiMedia_Player.md#gacce284eac910970e405151fd3a1963c0">OHOS::Media::Player::SetSource</a> (const <a href="OHOS-Media-Source.md">Source</a> &amp;source)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1197010968165625"><a name="p1197010968165625"></a><a name="p1197010968165625"></a>int32_t </p>
<p id="p1050300789165625"><a name="p1050300789165625"></a><a name="p1050300789165625"></a>Sets the playback source for the player. The corresponding source can be the file descriptor (FD) of the local file, local file URI, network URI, or media stream. </p>
</td>
</tr>
<tr id="row1073058756165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p537804982165625"><a name="p537804982165625"></a><a name="p537804982165625"></a><a href="MultiMedia_Player.md#gade9bff3268e1c409273749a90700e056">OHOS::Media::Player::Prepare</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p758115149165625"><a name="p758115149165625"></a><a name="p758115149165625"></a>int32_t </p>
<p id="p53541427165625"><a name="p53541427165625"></a><a name="p53541427165625"></a>Prepares the playback environment and buffers media data. </p>
</td>
</tr>
<tr id="row2123108378165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1429016778165625"><a name="p1429016778165625"></a><a name="p1429016778165625"></a><a href="MultiMedia_Player.md#gafecbbfe85c70cf4983f52d55b7205e3f">OHOS::Media::Player::Play</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1279949555165625"><a name="p1279949555165625"></a><a name="p1279949555165625"></a>int32_t </p>
<p id="p1561494113165625"><a name="p1561494113165625"></a><a name="p1561494113165625"></a>Starts or resumes playback. </p>
</td>
</tr>
<tr id="row223215679165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1452300658165625"><a name="p1452300658165625"></a><a name="p1452300658165625"></a><a href="MultiMedia_Player.md#gaad6b2c35b1d5dfe453d158f7ff9e1379">OHOS::Media::Player::IsPlaying</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1160378569165625"><a name="p1160378569165625"></a><a name="p1160378569165625"></a>bool </p>
<p id="p1214633750165625"><a name="p1214633750165625"></a><a name="p1214633750165625"></a>Checks whether the player is playing. </p>
</td>
</tr>
<tr id="row501646270165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1461645535165625"><a name="p1461645535165625"></a><a name="p1461645535165625"></a><a href="MultiMedia_Player.md#gae1d2225ce60a9737cc902e586138a44f">OHOS::Media::Player::Pause</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p959622823165625"><a name="p959622823165625"></a><a name="p959622823165625"></a>int32_t </p>
<p id="p1950266774165625"><a name="p1950266774165625"></a><a name="p1950266774165625"></a>Pauses playback. </p>
</td>
</tr>
<tr id="row964632791165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1523521180165625"><a name="p1523521180165625"></a><a name="p1523521180165625"></a><a href="MultiMedia_Player.md#gafe518a5b909ac0f0f066781caa3b55aa">OHOS::Media::Player::Stop</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1193325671165625"><a name="p1193325671165625"></a><a name="p1193325671165625"></a>int32_t </p>
<p id="p2108462466165625"><a name="p2108462466165625"></a><a name="p2108462466165625"></a>Stops playback. </p>
</td>
</tr>
<tr id="row385694993165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p142990412165625"><a name="p142990412165625"></a><a name="p142990412165625"></a><a href="MultiMedia_Player.md#ga406b6277d1e160e691d01f5f740480b3">OHOS::Media::Player::Rewind</a> (int64_t mSeconds, int32_t mode)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1431234792165625"><a name="p1431234792165625"></a><a name="p1431234792165625"></a>int32_t </p>
<p id="p67767487165625"><a name="p67767487165625"></a><a name="p67767487165625"></a>Changes the playback position. </p>
</td>
</tr>
<tr id="row931401542165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p405070575165625"><a name="p405070575165625"></a><a name="p405070575165625"></a><a href="MultiMedia_Player.md#ga23ca57f0b1a288980e37153274c5f8b3">OHOS::Media::Player::SetVolume</a> (float leftVolume, float rightVolume)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p737355408165625"><a name="p737355408165625"></a><a name="p737355408165625"></a>int32_t </p>
<p id="p1391662838165625"><a name="p1391662838165625"></a><a name="p1391662838165625"></a>Sets the volume of the player. </p>
</td>
</tr>
<tr id="row1589184532165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p791507096165625"><a name="p791507096165625"></a><a name="p791507096165625"></a><a href="MultiMedia_Player.md#gac9d62210915ebcf3b462574302018501">OHOS::Media::Player::SetVideoSurface</a> (<a href="OHOS-Surface.md">Surface</a> *surface)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1267321351165625"><a name="p1267321351165625"></a><a name="p1267321351165625"></a>int32_t </p>
<p id="p647196663165625"><a name="p647196663165625"></a><a name="p647196663165625"></a>Sets a surface for video playback. </p>
</td>
</tr>
<tr id="row838451138165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p472145332165625"><a name="p472145332165625"></a><a name="p472145332165625"></a><a href="MultiMedia_Player.md#gae19989aa6e80b768acd4eb019a2b60d2">OHOS::Media::Player::EnableSingleLooping</a> (bool loop)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p790701761165625"><a name="p790701761165625"></a><a name="p790701761165625"></a>int32_t </p>
<p id="p1946145136165625"><a name="p1946145136165625"></a><a name="p1946145136165625"></a>Sets loop playback. </p>
</td>
</tr>
<tr id="row1281763616165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p312909745165625"><a name="p312909745165625"></a><a name="p312909745165625"></a><a href="MultiMedia_Player.md#gae4dd5d8fb92c836f5304f181a40b34d2">OHOS::Media::Player::IsSingleLooping</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1098894843165625"><a name="p1098894843165625"></a><a name="p1098894843165625"></a>bool </p>
<p id="p340332108165625"><a name="p340332108165625"></a><a name="p340332108165625"></a>Checks whether the player is looping. </p>
</td>
</tr>
<tr id="row1736262918165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1728477216165625"><a name="p1728477216165625"></a><a name="p1728477216165625"></a><a href="MultiMedia_Player.md#ga8474b117a4c1bf5749406f26056b4802">OHOS::Media::Player::GetCurrentTime</a> (int64_t &amp;<a href="TIME.md#gae7841e681c8c9d59818568d39553642c">time</a>) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1718454337165625"><a name="p1718454337165625"></a><a name="p1718454337165625"></a>int32_t </p>
<p id="p2146736860165625"><a name="p2146736860165625"></a><a name="p2146736860165625"></a>Obtains the playback position, accurate to millisecond. </p>
</td>
</tr>
<tr id="row619011796165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1972143483165625"><a name="p1972143483165625"></a><a name="p1972143483165625"></a><a href="MultiMedia_Player.md#ga24ae07f65da4dafc4ec5aa28321625d8">OHOS::Media::Player::GetDuration</a> (int64_t &amp;duration) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p724767980165625"><a name="p724767980165625"></a><a name="p724767980165625"></a>int32_t </p>
<p id="p728328673165625"><a name="p728328673165625"></a><a name="p728328673165625"></a>Obtains the total duration of media files, in milliseconds. </p>
</td>
</tr>
<tr id="row472472748165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1178737123165625"><a name="p1178737123165625"></a><a name="p1178737123165625"></a><a href="MultiMedia_Player.md#ga9ed94bd43d896fa10066497377d7fbda">OHOS::Media::Player::GetVideoWidth</a> (int32_t &amp;videoWidth)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1851884840165625"><a name="p1851884840165625"></a><a name="p1851884840165625"></a>int32_t </p>
<p id="p521604428165625"><a name="p521604428165625"></a><a name="p521604428165625"></a>Obtains the width of the video. </p>
</td>
</tr>
<tr id="row409421169165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p396150422165625"><a name="p396150422165625"></a><a name="p396150422165625"></a><a href="MultiMedia_Player.md#ga726adc32a34134b30aabfbdb389c8357">OHOS::Media::Player::GetVideoHeight</a> (int32_t &amp;videoHeight)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p654050693165625"><a name="p654050693165625"></a><a name="p654050693165625"></a>int32_t </p>
<p id="p2077789302165625"><a name="p2077789302165625"></a><a name="p2077789302165625"></a>Obtains the height of the video. </p>
</td>
</tr>
<tr id="row1174078763165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p164445435165625"><a name="p164445435165625"></a><a name="p164445435165625"></a><a href="MultiMedia_Player.md#ga75e17ee0068d46d44a30709609821b85">OHOS::Media::Player::Reset</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1511834611165625"><a name="p1511834611165625"></a><a name="p1511834611165625"></a>int32_t </p>
<p id="p1878273481165625"><a name="p1878273481165625"></a><a name="p1878273481165625"></a>Restores the player to the initial state. </p>
</td>
</tr>
<tr id="row148323074165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2065897738165625"><a name="p2065897738165625"></a><a name="p2065897738165625"></a><a href="MultiMedia_Player.md#ga00e24c0faed483c9d54e416ec2ffe6ac">OHOS::Media::Player::Release</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1883225774165625"><a name="p1883225774165625"></a><a name="p1883225774165625"></a>int32_t </p>
<p id="p346190733165625"><a name="p346190733165625"></a><a name="p346190733165625"></a>Releases player resources. </p>
</td>
</tr>
<tr id="row1061282465165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1166439024165625"><a name="p1166439024165625"></a><a name="p1166439024165625"></a><a href="MultiMedia_Player.md#gabb6eca611514d5fc0b66df5ff2d70c2b">OHOS::Media::Player::SetPlayerCallback</a> (const std::shared_ptr&lt; <a href="OHOS-Media-PlayerCallback.md">PlayerCallback</a> &gt; &amp;cb)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2090330474165625"><a name="p2090330474165625"></a><a name="p2090330474165625"></a>void </p>
<p id="p328209284165625"><a name="p328209284165625"></a><a name="p328209284165625"></a>Registers a listener to receive events and exception notifications from the player. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1769927466165625"></a>

## **Enumeration Type **<a name="section40029736165625"></a>

## PlayerInfoType<a name="ga7dac9dac65cbbea7e411adcf2c314ac5"></a>

```
enum [OHOS::Media::PlayerCallback::PlayerInfoType](MultiMedia_Player.md#ga7dac9dac65cbbea7e411adcf2c314ac5) : int32_t
```

<a name="table1622740379165625"></a>
<table><thead align="left"><tr id="row884079883165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1201914167165625"><a name="p1201914167165625"></a><a name="p1201914167165625"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p228572326165625"><a name="p228572326165625"></a><a name="p228572326165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2019134785165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga7dac9dac65cbbea7e411adcf2c314ac5ab5ccacbb568a9b3ce5fedc0ced4e683d"><a name="gga7dac9dac65cbbea7e411adcf2c314ac5ab5ccacbb568a9b3ce5fedc0ced4e683d"></a><a name="gga7dac9dac65cbbea7e411adcf2c314ac5ab5ccacbb568a9b3ce5fedc0ced4e683d"></a></strong>PLAYER_INFO_RENDER_START </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1797884322165625"><a name="p1797884322165625"></a><a name="p1797884322165625"></a>Pushed the first video frame for rendering </p>
 </td>
</tr>
</tbody>
</table>

## PlayerSeekMode<a name="gad1574e5769b3174c2103a2a8b49e20d4"></a>

```
enum [OHOS::Media::PlayerSeekMode](MultiMedia_Player.md#gad1574e5769b3174c2103a2a8b49e20d4) : int32_t
```

 **Description:**

Enumerates player seek modes. You can move the current playback position of the media to a given time position using the specified mode. 

<a name="table1592859726165625"></a>
<table><thead align="left"><tr id="row181316719165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p626374056165625"><a name="p626374056165625"></a><a name="p626374056165625"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p155510776165625"><a name="p155510776165625"></a><a name="p155510776165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1828824819165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggad1574e5769b3174c2103a2a8b49e20d4a08be30187c1d180d77b375af6f35966c"><a name="ggad1574e5769b3174c2103a2a8b49e20d4a08be30187c1d180d77b375af6f35966c"></a><a name="ggad1574e5769b3174c2103a2a8b49e20d4a08be30187c1d180d77b375af6f35966c"></a></strong>PLAYER_SEEK_PREVIOUS_SYNC </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p225961509165625"><a name="p225961509165625"></a><a name="p225961509165625"></a>Moves the media position to the latest synchronization frame located before the given time position. </p>
 </td>
</tr>
<tr id="row1748386466165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggad1574e5769b3174c2103a2a8b49e20d4a98aa52abc293a28728ef9d2e9019ae7d"><a name="ggad1574e5769b3174c2103a2a8b49e20d4a98aa52abc293a28728ef9d2e9019ae7d"></a><a name="ggad1574e5769b3174c2103a2a8b49e20d4a98aa52abc293a28728ef9d2e9019ae7d"></a></strong>PLAYER_SEEK_NEXT_SYNC </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p894720178165625"><a name="p894720178165625"></a><a name="p894720178165625"></a>Moves the media position to the latest synchronization frame located after the given time position. </p>
 </td>
</tr>
<tr id="row2036697007165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggad1574e5769b3174c2103a2a8b49e20d4ae6257ed93e90e2231eb3369a36027872"><a name="ggad1574e5769b3174c2103a2a8b49e20d4ae6257ed93e90e2231eb3369a36027872"></a><a name="ggad1574e5769b3174c2103a2a8b49e20d4ae6257ed93e90e2231eb3369a36027872"></a></strong>PLAYER_SEEK_CLOSEST_SYNC </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1923246640165625"><a name="p1923246640165625"></a><a name="p1923246640165625"></a>Moves the media position to the latest synchronization frame located before or after the given time position. </p>
 </td>
</tr>
<tr id="row1763970302165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggad1574e5769b3174c2103a2a8b49e20d4a0f6165a7f22f44f78bbb9004f2a55428"><a name="ggad1574e5769b3174c2103a2a8b49e20d4a0f6165a7f22f44f78bbb9004f2a55428"></a><a name="ggad1574e5769b3174c2103a2a8b49e20d4a0f6165a7f22f44f78bbb9004f2a55428"></a></strong>PLAYER_SEEK_CLOSEST </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1461815660165625"><a name="p1461815660165625"></a><a name="p1461815660165625"></a>Moves the media position to the latest frame located before or after the given time position. </p>
 </td>
</tr>
<tr id="row358806922165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggad1574e5769b3174c2103a2a8b49e20d4ada8db6c3cb45acbc0ff09cb3fe65fd94"><a name="ggad1574e5769b3174c2103a2a8b49e20d4ada8db6c3cb45acbc0ff09cb3fe65fd94"></a><a name="ggad1574e5769b3174c2103a2a8b49e20d4ada8db6c3cb45acbc0ff09cb3fe65fd94"></a></strong>PLAYER_SEEK_FRAME_INDEX </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p225910427165625"><a name="p225910427165625"></a><a name="p225910427165625"></a>Moves the media position to a given frame index. </p>
 </td>
</tr>
</tbody>
</table>

## PlayerStates<a name="ga8b1147e57c4a67f63f193836302da2b7"></a>

```
enum [OHOS::Media::PlayerStates](MultiMedia_Player.md#ga8b1147e57c4a67f63f193836302da2b7) : uint32_t
```

 **Description:**

Enumerates player states. 

<a name="table1103546285165625"></a>
<table><thead align="left"><tr id="row1689703182165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1303436516165625"><a name="p1303436516165625"></a><a name="p1303436516165625"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p62481541165625"><a name="p62481541165625"></a><a name="p62481541165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2114630885165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga8b1147e57c4a67f63f193836302da2b7a53755dd964e67b38f2b20a73043c6a15"><a name="gga8b1147e57c4a67f63f193836302da2b7a53755dd964e67b38f2b20a73043c6a15"></a><a name="gga8b1147e57c4a67f63f193836302da2b7a53755dd964e67b38f2b20a73043c6a15"></a></strong>PLAYER_STATE_ERROR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1719884498165625"><a name="p1719884498165625"></a><a name="p1719884498165625"></a>Error </p>
 </td>
</tr>
<tr id="row829455060165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga8b1147e57c4a67f63f193836302da2b7a422de416a9d98b7a11334080277e5a91"><a name="gga8b1147e57c4a67f63f193836302da2b7a422de416a9d98b7a11334080277e5a91"></a><a name="gga8b1147e57c4a67f63f193836302da2b7a422de416a9d98b7a11334080277e5a91"></a></strong>PLAYER_IDLE </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1803126979165625"><a name="p1803126979165625"></a><a name="p1803126979165625"></a>Idle </p>
 </td>
</tr>
<tr id="row1134904487165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga8b1147e57c4a67f63f193836302da2b7a9b85bb17a31e74c8913d3344a9890968"><a name="gga8b1147e57c4a67f63f193836302da2b7a9b85bb17a31e74c8913d3344a9890968"></a><a name="gga8b1147e57c4a67f63f193836302da2b7a9b85bb17a31e74c8913d3344a9890968"></a></strong>PLAYER_INITIALIZED </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p906624643165625"><a name="p906624643165625"></a><a name="p906624643165625"></a>Initialized </p>
 </td>
</tr>
<tr id="row411365732165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga8b1147e57c4a67f63f193836302da2b7a5f58beea6c3cfd9faf9d9dacb6d0de43"><a name="gga8b1147e57c4a67f63f193836302da2b7a5f58beea6c3cfd9faf9d9dacb6d0de43"></a><a name="gga8b1147e57c4a67f63f193836302da2b7a5f58beea6c3cfd9faf9d9dacb6d0de43"></a></strong>PLAYER_PREPARING </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p484154979165625"><a name="p484154979165625"></a><a name="p484154979165625"></a>Preparing </p>
 </td>
</tr>
<tr id="row1490303365165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga8b1147e57c4a67f63f193836302da2b7a992920b7152bf85ce28b0cbc2204a01b"><a name="gga8b1147e57c4a67f63f193836302da2b7a992920b7152bf85ce28b0cbc2204a01b"></a><a name="gga8b1147e57c4a67f63f193836302da2b7a992920b7152bf85ce28b0cbc2204a01b"></a></strong>PLAYER_PREPARED </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p495957132165625"><a name="p495957132165625"></a><a name="p495957132165625"></a>Prepared </p>
 </td>
</tr>
<tr id="row655371589165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga8b1147e57c4a67f63f193836302da2b7ab59f150a877432470b368cb6ae3c01d6"><a name="gga8b1147e57c4a67f63f193836302da2b7ab59f150a877432470b368cb6ae3c01d6"></a><a name="gga8b1147e57c4a67f63f193836302da2b7ab59f150a877432470b368cb6ae3c01d6"></a></strong>PLAYER_STARTED </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p719786058165625"><a name="p719786058165625"></a><a name="p719786058165625"></a>Playback started </p>
 </td>
</tr>
<tr id="row754510724165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga8b1147e57c4a67f63f193836302da2b7a865415ef0c33b942431a1814e84dd848"><a name="gga8b1147e57c4a67f63f193836302da2b7a865415ef0c33b942431a1814e84dd848"></a><a name="gga8b1147e57c4a67f63f193836302da2b7a865415ef0c33b942431a1814e84dd848"></a></strong>PLAYER_PAUSED </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1615871692165625"><a name="p1615871692165625"></a><a name="p1615871692165625"></a>Playback paused </p>
 </td>
</tr>
<tr id="row2087560482165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga8b1147e57c4a67f63f193836302da2b7a0d79ba704b9048d53deee264f6e6546d"><a name="gga8b1147e57c4a67f63f193836302da2b7a0d79ba704b9048d53deee264f6e6546d"></a><a name="gga8b1147e57c4a67f63f193836302da2b7a0d79ba704b9048d53deee264f6e6546d"></a></strong>PLAYER_STOPPED </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1747023805165625"><a name="p1747023805165625"></a><a name="p1747023805165625"></a>Playback stopped </p>
 </td>
</tr>
<tr id="row1854521931165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga8b1147e57c4a67f63f193836302da2b7ac5e465735c926d57e1bcb39eff208e51"><a name="gga8b1147e57c4a67f63f193836302da2b7ac5e465735c926d57e1bcb39eff208e51"></a><a name="gga8b1147e57c4a67f63f193836302da2b7ac5e465735c926d57e1bcb39eff208e51"></a></strong>PLAYER_PLAYBACK_COMPLETE </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1348767765165625"><a name="p1348767765165625"></a><a name="p1348767765165625"></a>Playback completed </p>
 </td>
</tr>
</tbody>
</table>

## **Function **<a name="section747638434165625"></a>

## EnableSingleLooping\(\)<a name="gae19989aa6e80b768acd4eb019a2b60d2"></a>

```
int32_t OHOS::Media::Player::EnableSingleLooping (bool loop)
```

 **Description:**

Sets loop playback. 

**Parameters:**

<a name="table780690675165625"></a>
<table><thead align="left"><tr id="row1291081303165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1947967610165625"><a name="p1947967610165625"></a><a name="p1947967610165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p441554638165625"><a name="p441554638165625"></a><a name="p441554638165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row414829758165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">loop</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Specifies whether to enable loop playback. The value <strong id="b998887476165625"><a name="b998887476165625"></a><a name="b998887476165625"></a>true</strong> means to enable loop playback, and <strong id="b35254109165625"><a name="b35254109165625"></a><a name="b35254109165625"></a>false</strong> means to disable loop playback. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the setting is successful; returns  **-1**  otherwise. 

## GetCurrentTime\(\)<a name="ga8474b117a4c1bf5749406f26056b4802"></a>

```
int32_t OHOS::Media::Player::GetCurrentTime (int64_t & time) const
```

 **Description:**

Obtains the playback position, accurate to millisecond. 

**Parameters:**

<a name="table1353210542165625"></a>
<table><thead align="left"><tr id="row2058032475165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p882088046165625"><a name="p882088046165625"></a><a name="p882088046165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1129805295165625"><a name="p1129805295165625"></a><a name="p1129805295165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1468593937165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">time</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the playback position. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the playback position is obtained; returns  **-1**  otherwise. 

## GetDuration\(\)<a name="ga24ae07f65da4dafc4ec5aa28321625d8"></a>

```
int32_t OHOS::Media::Player::GetDuration (int64_t & duration) const
```

 **Description:**

Obtains the total duration of media files, in milliseconds. 

**Parameters:**

<a name="table1751744726165625"></a>
<table><thead align="left"><tr id="row370430810165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p569618964165625"><a name="p569618964165625"></a><a name="p569618964165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1490413868165625"><a name="p1490413868165625"></a><a name="p1490413868165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row11153933165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">duration</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the total duration of media files. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the total duration is obtained; returns  **-1**  otherwise. 

## GetVideoHeight\(\)<a name="ga726adc32a34134b30aabfbdb389c8357"></a>

```
int32_t OHOS::Media::Player::GetVideoHeight (int32_t & videoHeight)
```

 **Description:**

Obtains the height of the video. 

**Parameters:**

<a name="table174089804165625"></a>
<table><thead align="left"><tr id="row942741822165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1794240178165625"><a name="p1794240178165625"></a><a name="p1794240178165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1363918943165625"><a name="p1363918943165625"></a><a name="p1363918943165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1142005763165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">videoHeight</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the video height. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the video height is obtained; returns  **-1**  otherwise. 

## GetVideoWidth\(\)<a name="ga9ed94bd43d896fa10066497377d7fbda"></a>

```
int32_t OHOS::Media::Player::GetVideoWidth (int32_t & videoWidth)
```

 **Description:**

Obtains the width of the video. 

**Parameters:**

<a name="table358990056165625"></a>
<table><thead align="left"><tr id="row2068997676165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1728260472165625"><a name="p1728260472165625"></a><a name="p1728260472165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1417485553165625"><a name="p1417485553165625"></a><a name="p1417485553165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row421847011165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">videoWidth</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the video width. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the video width is obtained; returns  **-1**  otherwise. 

## IsPlaying\(\)<a name="gaad6b2c35b1d5dfe453d158f7ff9e1379"></a>

```
bool OHOS::Media::Player::IsPlaying ()
```

 **Description:**

Checks whether the player is playing. 

**Returns:**

Returns  **true**  if the player is playing; returns  **false**  otherwise. 

## IsSingleLooping\(\)<a name="gae4dd5d8fb92c836f5304f181a40b34d2"></a>

```
bool OHOS::Media::Player::IsSingleLooping ()
```

 **Description:**

Checks whether the player is looping. 

**Returns:**

Returns  **true**  if the player is looping; returns  **false**  otherwise. 

## OnError\(\)<a name="ga3d0fdad57045f5e049b56de031d3e0fb"></a>

```
virtual void OHOS::Media::PlayerCallback::OnError (int32_t errorType, int32_t errorCode )
```

 **Description:**

Called when a playback error occurs. 

**Parameters:**

<a name="table946286064165625"></a>
<table><thead align="left"><tr id="row936150030165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p280899002165625"><a name="p280899002165625"></a><a name="p280899002165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p554938832165625"><a name="p554938832165625"></a><a name="p554938832165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1808781532165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">errorType</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the error type. For details, see <strong id="b1403338692165625"><a name="b1403338692165625"></a><a name="b1403338692165625"></a>PlayerErrorType</strong>. </td>
</tr>
<tr id="row1261690742165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">errorCode</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the error code. </td>
</tr>
</tbody>
</table>

## OnInfo\(\)<a name="gad2d3466c8a17ee4d622b87fa6a31b2bb"></a>

```
virtual void OHOS::Media::PlayerCallback::OnInfo (int type, int extra )
```

 **Description:**

Called when playback information is received. 

**Parameters:**

<a name="table1739555767165625"></a>
<table><thead align="left"><tr id="row1664742304165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p747922478165625"><a name="p747922478165625"></a><a name="p747922478165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p837985765165625"><a name="p837985765165625"></a><a name="p837985765165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1354408895165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">type</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the information type. For details, see <a href="MultiMedia_Player.md#ga7dac9dac65cbbea7e411adcf2c314ac5">PlayerInfoType</a>. </td>
</tr>
<tr id="row1161660732165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">extra</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the information code. </td>
</tr>
</tbody>
</table>

## OnPlaybackComplete\(\)<a name="ga3b56f618340bf9a5590e6142b2311302"></a>

```
virtual void OHOS::Media::PlayerCallback::OnPlaybackComplete ()
```

 **Description:**

Called when the playback is complete. 

## OnRewindToComplete\(\)<a name="ga765c499e47dfaad5e557197e964eaca3"></a>

```
virtual void OHOS::Media::PlayerCallback::OnRewindToComplete ()
```

 **Description:**

Called when the rewind is complete. 

## OnVideoSizeChanged\(\)<a name="gac5b641f93621d90e616d18adaa016e8a"></a>

```
virtual void OHOS::Media::PlayerCallback::OnVideoSizeChanged (int width, int height )
```

 **Description:**

Called when the video image size changes. 

**Parameters:**

<a name="table2109377981165625"></a>
<table><thead align="left"><tr id="row1915767652165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p602556865165625"><a name="p602556865165625"></a><a name="p602556865165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1245261571165625"><a name="p1245261571165625"></a><a name="p1245261571165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row330800643165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">width</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the video width. </td>
</tr>
<tr id="row428320000165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">height</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the video height. </td>
</tr>
</tbody>
</table>

## Pause\(\)<a name="gae1d2225ce60a9737cc902e586138a44f"></a>

```
int32_t OHOS::Media::Player::Pause ()
```

 **Description:**

Pauses playback. 

**Returns:**

Returns  **0**  if the playback is paused; returns  **-1**  otherwise. 

## Play\(\)<a name="gafecbbfe85c70cf4983f52d55b7205e3f"></a>

```
int32_t OHOS::Media::Player::Play ()
```

 **Description:**

Starts or resumes playback. 

This function must be called after  [Prepare](MultiMedia_Player.md#gade9bff3268e1c409273749a90700e056). If the player state is  **Prepared**, this function is called to start playback. If the player state is  **Playback paused**, this function is called to resume playback. If the media is playing in an abnormal speed, this function is called to restore the playback speed to normal.

**Returns:**

Returns  **0**  if the playback starts or resumes; returns  **-1**  otherwise. 

## Prepare\(\)<a name="gade9bff3268e1c409273749a90700e056"></a>

```
int32_t OHOS::Media::Player::Prepare ()
```

 **Description:**

Prepares the playback environment and buffers media data. 

This function must be called after  [SetSource](MultiMedia_Player.md#gacce284eac910970e405151fd3a1963c0).

**Returns:**

Returns  **0**  if the playback environment is prepared and media data is buffered; returns  **-1**  otherwise. 

## Release\(\)<a name="ga00e24c0faed483c9d54e416ec2ffe6ac"></a>

```
int32_t OHOS::Media::Player::Release ()
```

 **Description:**

Releases player resources. 

**Returns:**

Returns  **0**  if player resources are released; returns  **-1**  otherwise. 

## Reset\(\)<a name="ga75e17ee0068d46d44a30709609821b85"></a>

```
int32_t OHOS::Media::Player::Reset ()
```

 **Description:**

Restores the player to the initial state. 

**Returns:**

Returns  **0**  if the player is restored; returns  **-1**  otherwise. 

## Rewind\(\)<a name="ga406b6277d1e160e691d01f5f740480b3"></a>

```
int32_t OHOS::Media::Player::Rewind (int64_t mSeconds, int32_t mode )
```

 **Description:**

Changes the playback position. 

This function can be used during playback or pause.

**Parameters:**

<a name="table1977015491165625"></a>
<table><thead align="left"><tr id="row2071016780165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p397919308165625"><a name="p397919308165625"></a><a name="p397919308165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p333633609165625"><a name="p333633609165625"></a><a name="p333633609165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row80187296165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">mSeconds</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the target playback position, accurate to second. </td>
</tr>
<tr id="row887868171165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">mode</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the player seek mode. For details, see <strong id="b1860050744165625"><a name="b1860050744165625"></a><a name="b1860050744165625"></a>PlayerSeekMode</strong>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the playback position is changed; returns  **-1**  otherwise. 

## SetPlayerCallback\(\)<a name="gabb6eca611514d5fc0b66df5ff2d70c2b"></a>

```
void OHOS::Media::Player::SetPlayerCallback (const std::shared_ptr< [PlayerCallback](OHOS-Media-PlayerCallback.md) > & cb)
```

 **Description:**

Registers a listener to receive events and exception notifications from the player. 

**Parameters:**

<a name="table993600438165625"></a>
<table><thead align="left"><tr id="row2089491075165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1064870937165625"><a name="p1064870937165625"></a><a name="p1064870937165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2021485635165625"><a name="p2021485635165625"></a><a name="p2021485635165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2090042447165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">cb</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the listener to register. For details, see <a href="OHOS-Media-PlayerCallback.md">PlayerCallback</a>. </td>
</tr>
</tbody>
</table>

## SetSource\(\)<a name="gacce284eac910970e405151fd3a1963c0"></a>

```
int32_t OHOS::Media::Player::SetSource (const [Source](OHOS-Media-Source.md) & source)
```

 **Description:**

Sets the playback source for the player. The corresponding source can be the file descriptor \(FD\) of the local file, local file URI, network URI, or media stream. 

**Parameters:**

<a name="table65302802165625"></a>
<table><thead align="left"><tr id="row1217637691165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p32490372165625"><a name="p32490372165625"></a><a name="p32490372165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p380983243165625"><a name="p380983243165625"></a><a name="p380983243165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1089303653165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">source</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the playback source. Currently, only local file URIs and media streams are supported. For details, see <a href="OHOS-Media-Source.md">Source</a>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the setting is successful; returns  **-1**  otherwise. 

## SetVideoSurface\(\)<a name="gac9d62210915ebcf3b462574302018501"></a>

```
int32_t OHOS::Media::Player::SetVideoSurface ([Surface](OHOS-Surface.md) * surface)
```

 **Description:**

Sets a surface for video playback. 

**Parameters:**

<a name="table1889354218165625"></a>
<table><thead align="left"><tr id="row118392359165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p975374283165625"><a name="p975374283165625"></a><a name="p975374283165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p833309785165625"><a name="p833309785165625"></a><a name="p833309785165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row80644799165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">surface</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the surface to set. For details, see <a href="Surface.md">Surface</a>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the setting is successful; returns  **-1**  otherwise. 

## SetVolume\(\)<a name="ga23ca57f0b1a288980e37153274c5f8b3"></a>

```
int32_t OHOS::Media::Player::SetVolume (float leftVolume, float rightVolume )
```

 **Description:**

Sets the volume of the player. 

This function can be used during playback or pause. The value  **0**  indicates no sound, and  **100**  indicates the original volume. If no audio device is started or no audio stream exists, the value  **-1**  is returned.

**Parameters:**

<a name="table1574438575165625"></a>
<table><thead align="left"><tr id="row1628368801165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p519161022165625"><a name="p519161022165625"></a><a name="p519161022165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1497673774165625"><a name="p1497673774165625"></a><a name="p1497673774165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1930638045165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">leftVolume</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the target volume of the left audio channel to set, ranging from 0 to 300. </td>
</tr>
<tr id="row1291880303165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">rightVolume</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the target volume of the right audio channel to set, ranging from 0 to 300. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the setting is successful; returns  **-1**  otherwise. 

## Stop\(\)<a name="gafe518a5b909ac0f0f066781caa3b55aa"></a>

```
int32_t OHOS::Media::Player::Stop ()
```

 **Description:**

Stops playback. 

**Returns:**

Returns  **0**  if the playback is stopped; returns  **-1**  otherwise. 

