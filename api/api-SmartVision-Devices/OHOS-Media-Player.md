# OHOS::Media::Player<a name="ZH-CN_TOPIC_0000001055518100"></a>

-   [Overview](#section1269825086165632)
-   [Summary](#section273161611165632)
-   [Public Member Functions](#pub-methods)

## **Overview**<a name="section1269825086165632"></a>

**Related Modules:**

[MultiMedia\_Player](MultiMedia_Player.md)

**Description:**

Provides functions for playing online movies, offline movies, and streams, for example, playing local movies and advanced audio coding \(AAC\) streams. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section273161611165632"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table1832660711165632"></a>
<table><thead align="left"><tr id="row1280726822165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1316929784165632"><a name="p1316929784165632"></a><a name="p1316929784165632"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p802271608165632"><a name="p802271608165632"></a><a name="p802271608165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1701794610165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1451067907165632"><a name="p1451067907165632"></a><a name="p1451067907165632"></a><a href="MultiMedia_Player.md#gacce284eac910970e405151fd3a1963c0">SetSource</a> (const <a href="OHOS-Media-Source.md">Source</a> &amp;source)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1854640295165632"><a name="p1854640295165632"></a><a name="p1854640295165632"></a>int32_t </p>
<p id="p916693749165632"><a name="p916693749165632"></a><a name="p916693749165632"></a>Sets the playback source for the player. The corresponding source can be the file descriptor (FD) of the local file, local file URI, network URI, or media stream. </p>
</td>
</tr>
<tr id="row638822904165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1485698933165632"><a name="p1485698933165632"></a><a name="p1485698933165632"></a><a href="MultiMedia_Player.md#gade9bff3268e1c409273749a90700e056">Prepare</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1083908773165632"><a name="p1083908773165632"></a><a name="p1083908773165632"></a>int32_t </p>
<p id="p1141879388165632"><a name="p1141879388165632"></a><a name="p1141879388165632"></a>Prepares the playback environment and buffers media data. </p>
</td>
</tr>
<tr id="row2122264356165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p227881955165632"><a name="p227881955165632"></a><a name="p227881955165632"></a><a href="MultiMedia_Player.md#gafecbbfe85c70cf4983f52d55b7205e3f">Play</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1003207097165632"><a name="p1003207097165632"></a><a name="p1003207097165632"></a>int32_t </p>
<p id="p1322104695165632"><a name="p1322104695165632"></a><a name="p1322104695165632"></a>Starts or resumes playback. </p>
</td>
</tr>
<tr id="row201114300165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1112201611165632"><a name="p1112201611165632"></a><a name="p1112201611165632"></a><a href="MultiMedia_Player.md#gaad6b2c35b1d5dfe453d158f7ff9e1379">IsPlaying</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p564489977165632"><a name="p564489977165632"></a><a name="p564489977165632"></a>bool </p>
<p id="p326771437165632"><a name="p326771437165632"></a><a name="p326771437165632"></a>Checks whether the player is playing. </p>
</td>
</tr>
<tr id="row1795157731165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1562097696165632"><a name="p1562097696165632"></a><a name="p1562097696165632"></a><a href="MultiMedia_Player.md#gae1d2225ce60a9737cc902e586138a44f">Pause</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p96358239165632"><a name="p96358239165632"></a><a name="p96358239165632"></a>int32_t </p>
<p id="p1543504776165632"><a name="p1543504776165632"></a><a name="p1543504776165632"></a>Pauses playback. </p>
</td>
</tr>
<tr id="row1970095190165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p519518221165632"><a name="p519518221165632"></a><a name="p519518221165632"></a><a href="MultiMedia_Player.md#gafe518a5b909ac0f0f066781caa3b55aa">Stop</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1872296853165632"><a name="p1872296853165632"></a><a name="p1872296853165632"></a>int32_t </p>
<p id="p118710768165632"><a name="p118710768165632"></a><a name="p118710768165632"></a>Stops playback. </p>
</td>
</tr>
<tr id="row981744925165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2092956416165632"><a name="p2092956416165632"></a><a name="p2092956416165632"></a><a href="MultiMedia_Player.md#ga406b6277d1e160e691d01f5f740480b3">Rewind</a> (int64_t mSeconds, int32_t mode)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p105773845165632"><a name="p105773845165632"></a><a name="p105773845165632"></a>int32_t </p>
<p id="p545358791165632"><a name="p545358791165632"></a><a name="p545358791165632"></a>Changes the playback position. </p>
</td>
</tr>
<tr id="row1205924116165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1118085014165632"><a name="p1118085014165632"></a><a name="p1118085014165632"></a><a href="MultiMedia_Player.md#ga23ca57f0b1a288980e37153274c5f8b3">SetVolume</a> (float leftVolume, float rightVolume)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1817971229165632"><a name="p1817971229165632"></a><a name="p1817971229165632"></a>int32_t </p>
<p id="p287032125165632"><a name="p287032125165632"></a><a name="p287032125165632"></a>Sets the volume of the player. </p>
</td>
</tr>
<tr id="row1625709068165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p665158133165632"><a name="p665158133165632"></a><a name="p665158133165632"></a><a href="MultiMedia_Player.md#gac9d62210915ebcf3b462574302018501">SetVideoSurface</a> (<a href="OHOS-Surface.md">Surface</a> *surface)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2144231998165632"><a name="p2144231998165632"></a><a name="p2144231998165632"></a>int32_t </p>
<p id="p2094787319165632"><a name="p2094787319165632"></a><a name="p2094787319165632"></a>Sets a surface for video playback. </p>
</td>
</tr>
<tr id="row478920695165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1463725435165632"><a name="p1463725435165632"></a><a name="p1463725435165632"></a><a href="MultiMedia_Player.md#gae19989aa6e80b768acd4eb019a2b60d2">EnableSingleLooping</a> (bool loop)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p11768762165632"><a name="p11768762165632"></a><a name="p11768762165632"></a>int32_t </p>
<p id="p1478237293165632"><a name="p1478237293165632"></a><a name="p1478237293165632"></a>Sets loop playback. </p>
</td>
</tr>
<tr id="row1909827153165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p353494157165632"><a name="p353494157165632"></a><a name="p353494157165632"></a><a href="MultiMedia_Player.md#gae4dd5d8fb92c836f5304f181a40b34d2">IsSingleLooping</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1985950247165632"><a name="p1985950247165632"></a><a name="p1985950247165632"></a>bool </p>
<p id="p610747166165632"><a name="p610747166165632"></a><a name="p610747166165632"></a>Checks whether the player is looping. </p>
</td>
</tr>
<tr id="row1953074509165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p331680160165632"><a name="p331680160165632"></a><a name="p331680160165632"></a><a href="MultiMedia_Player.md#ga8474b117a4c1bf5749406f26056b4802">GetCurrentTime</a> (int64_t &amp;<a href="TIME.md#gae7841e681c8c9d59818568d39553642c">time</a>) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2057474726165632"><a name="p2057474726165632"></a><a name="p2057474726165632"></a>int32_t </p>
<p id="p578658579165632"><a name="p578658579165632"></a><a name="p578658579165632"></a>Obtains the playback position, accurate to millisecond. </p>
</td>
</tr>
<tr id="row607682315165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2123406045165632"><a name="p2123406045165632"></a><a name="p2123406045165632"></a><a href="MultiMedia_Player.md#ga24ae07f65da4dafc4ec5aa28321625d8">GetDuration</a> (int64_t &amp;duration) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p922290565165632"><a name="p922290565165632"></a><a name="p922290565165632"></a>int32_t </p>
<p id="p940468390165632"><a name="p940468390165632"></a><a name="p940468390165632"></a>Obtains the total duration of media files, in milliseconds. </p>
</td>
</tr>
<tr id="row1114333968165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1607407914165632"><a name="p1607407914165632"></a><a name="p1607407914165632"></a><a href="MultiMedia_Player.md#ga9ed94bd43d896fa10066497377d7fbda">GetVideoWidth</a> (int32_t &amp;videoWidth)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p535470959165632"><a name="p535470959165632"></a><a name="p535470959165632"></a>int32_t </p>
<p id="p1302017378165632"><a name="p1302017378165632"></a><a name="p1302017378165632"></a>Obtains the width of the video. </p>
</td>
</tr>
<tr id="row564104920165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p137304841165632"><a name="p137304841165632"></a><a name="p137304841165632"></a><a href="MultiMedia_Player.md#ga726adc32a34134b30aabfbdb389c8357">GetVideoHeight</a> (int32_t &amp;videoHeight)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1295012428165632"><a name="p1295012428165632"></a><a name="p1295012428165632"></a>int32_t </p>
<p id="p587321224165632"><a name="p587321224165632"></a><a name="p587321224165632"></a>Obtains the height of the video. </p>
</td>
</tr>
<tr id="row1968868333165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p806258220165632"><a name="p806258220165632"></a><a name="p806258220165632"></a><a href="MultiMedia_Player.md#ga75e17ee0068d46d44a30709609821b85">Reset</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1688514829165632"><a name="p1688514829165632"></a><a name="p1688514829165632"></a>int32_t </p>
<p id="p1788534179165632"><a name="p1788534179165632"></a><a name="p1788534179165632"></a>Restores the player to the initial state. </p>
</td>
</tr>
<tr id="row1687254162165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p380937917165632"><a name="p380937917165632"></a><a name="p380937917165632"></a><a href="MultiMedia_Player.md#ga00e24c0faed483c9d54e416ec2ffe6ac">Release</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1006460927165632"><a name="p1006460927165632"></a><a name="p1006460927165632"></a>int32_t </p>
<p id="p1672304933165632"><a name="p1672304933165632"></a><a name="p1672304933165632"></a>Releases player resources. </p>
</td>
</tr>
<tr id="row344047475165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2086915909165632"><a name="p2086915909165632"></a><a name="p2086915909165632"></a><a href="MultiMedia_Player.md#gabb6eca611514d5fc0b66df5ff2d70c2b">SetPlayerCallback</a> (const std::shared_ptr&lt; <a href="OHOS-Media-PlayerCallback.md">PlayerCallback</a> &gt; &amp;cb)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p616404287165632"><a name="p616404287165632"></a><a name="p616404287165632"></a>void </p>
<p id="p1429780500165632"><a name="p1429780500165632"></a><a name="p1429780500165632"></a>Registers a listener to receive events and exception notifications from the player. </p>
</td>
</tr>
</tbody>
</table>

