# player.h<a name="EN-US_TOPIC_0000001054918131"></a>

-   [Overview](#section871819368165628)
-   [Summary](#section878444633165628)
-   [Data Structures](#nested-classes)
-   [Enumerations](#enum-members)

## **Overview**<a name="section871819368165628"></a>

**Related Modules:**

[MultiMedia\_Player](multimedia_player.md)

**Description:**

Declares the  **Player**  class, which is used to implement player-related operations. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section878444633165628"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table1742426935165628"></a>
<table><thead align="left"><tr id="row871448854165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2003435446165628"><a name="p2003435446165628"></a><a name="p2003435446165628"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1277065276165628"><a name="p1277065276165628"></a><a name="p1277065276165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1302277683165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p335414439165628"><a name="p335414439165628"></a><a name="p335414439165628"></a><a href="ohos-media-playercallback.md">OHOS::Media::PlayerCallback</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p321100188165628"><a name="p321100188165628"></a><a name="p321100188165628"></a>Provides listeners for events and exception notifications that occur during media playback. </p>
</td>
</tr>
<tr id="row1972804703165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1363563672165628"><a name="p1363563672165628"></a><a name="p1363563672165628"></a><a href="ohos-media-player.md">OHOS::Media::Player</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p201139486165628"><a name="p201139486165628"></a><a name="p201139486165628"></a>Provides functions for playing online movies, offline movies, and streams, for example, playing local movies and advanced audio coding (AAC) streams. </p>
</td>
</tr>
</tbody>
</table>

## Enumerations<a name="enum-members"></a>

<a name="table430555893165628"></a>
<table><thead align="left"><tr id="row998032954165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1719439677165628"><a name="p1719439677165628"></a><a name="p1719439677165628"></a>Enumeration Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p73073638165628"><a name="p73073638165628"></a><a name="p73073638165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1502477780165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1730282364165628"><a name="p1730282364165628"></a><a name="p1730282364165628"></a><a href="multimedia_player.md#gad1574e5769b3174c2103a2a8b49e20d4">OHOS::Media::PlayerSeekMode</a> : int32_t {   <a href="multimedia_player.md#ggad1574e5769b3174c2103a2a8b49e20d4a08be30187c1d180d77b375af6f35966c">OHOS::Media::PLAYER_SEEK_PREVIOUS_SYNC</a> = 0, <a href="multimedia_player.md#ggad1574e5769b3174c2103a2a8b49e20d4a98aa52abc293a28728ef9d2e9019ae7d">OHOS::Media::PLAYER_SEEK_NEXT_SYNC</a>, <a href="multimedia_player.md#ggad1574e5769b3174c2103a2a8b49e20d4ae6257ed93e90e2231eb3369a36027872">OHOS::Media::PLAYER_SEEK_CLOSEST_SYNC</a>, <a href="multimedia_player.md#ggad1574e5769b3174c2103a2a8b49e20d4a0f6165a7f22f44f78bbb9004f2a55428">OHOS::Media::PLAYER_SEEK_CLOSEST</a>,   <a href="multimedia_player.md#ggad1574e5769b3174c2103a2a8b49e20d4ada8db6c3cb45acbc0ff09cb3fe65fd94">OHOS::Media::PLAYER_SEEK_FRAME_INDEX</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1759773589165628"><a name="p1759773589165628"></a><a name="p1759773589165628"></a>Enumerates player seek modes. You can move the current playback position of the media to a given time position using the specified mode. </p>
</td>
</tr>
<tr id="row392783882165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p641572162165628"><a name="p641572162165628"></a><a name="p641572162165628"></a><a href="multimedia_player.md#ga8b1147e57c4a67f63f193836302da2b7">OHOS::Media::PlayerStates</a> : uint32_t {   <a href="multimedia_player.md#gga8b1147e57c4a67f63f193836302da2b7a53755dd964e67b38f2b20a73043c6a15">OHOS::Media::PLAYER_STATE_ERROR</a> = 0, <a href="multimedia_player.md#gga8b1147e57c4a67f63f193836302da2b7a422de416a9d98b7a11334080277e5a91">OHOS::Media::PLAYER_IDLE</a> = 1 &lt;&lt; 0, <a href="multimedia_player.md#gga8b1147e57c4a67f63f193836302da2b7a9b85bb17a31e74c8913d3344a9890968">OHOS::Media::PLAYER_INITIALIZED</a> = 1 &lt;&lt; 1, <a href="multimedia_player.md#gga8b1147e57c4a67f63f193836302da2b7a5f58beea6c3cfd9faf9d9dacb6d0de43">OHOS::Media::PLAYER_PREPARING</a> = 1 &lt;&lt; 2,   <a href="multimedia_player.md#gga8b1147e57c4a67f63f193836302da2b7a992920b7152bf85ce28b0cbc2204a01b">OHOS::Media::PLAYER_PREPARED</a> = 1 &lt;&lt; 3, <a href="multimedia_player.md#gga8b1147e57c4a67f63f193836302da2b7ab59f150a877432470b368cb6ae3c01d6">OHOS::Media::PLAYER_STARTED</a> = 1 &lt;&lt; 4, <a href="multimedia_player.md#gga8b1147e57c4a67f63f193836302da2b7a865415ef0c33b942431a1814e84dd848">OHOS::Media::PLAYER_PAUSED</a> = 1 &lt;&lt; 5, <a href="multimedia_player.md#gga8b1147e57c4a67f63f193836302da2b7a0d79ba704b9048d53deee264f6e6546d">OHOS::Media::PLAYER_STOPPED</a> = 1 &lt;&lt; 6,   <a href="multimedia_player.md#gga8b1147e57c4a67f63f193836302da2b7ac5e465735c926d57e1bcb39eff208e51">OHOS::Media::PLAYER_PLAYBACK_COMPLETE</a> = 1 &lt;&lt; 7 }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p184256991165628"><a name="p184256991165628"></a><a name="p184256991165628"></a>Enumerates player states. </p>
</td>
</tr>
</tbody>
</table>

