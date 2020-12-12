# OHOS::Media::PlayerCallback<a name="EN-US_TOPIC_0000001055678104"></a>

-   [Overview](#section512944021165632)
-   [Summary](#section1995365483165632)
-   [Public Types](#pub-types)
-   [Public Member Functions](#pub-methods)

## **Overview**<a name="section512944021165632"></a>

**Related Modules:**

[MultiMedia\_Player](multimedia_player.md)

**Description:**

Provides listeners for events and exception notifications that occur during media playback. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1995365483165632"></a>

## Public Types<a name="pub-types"></a>

<a name="table1505319643165632"></a>
<table><thead align="left"><tr id="row525455356165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p985841413165632"><a name="p985841413165632"></a><a name="p985841413165632"></a>Public Type Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1558352995165632"><a name="p1558352995165632"></a><a name="p1558352995165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row451537470165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p416157927165632"><a name="p416157927165632"></a><a name="p416157927165632"></a><a href="multimedia_player.md#ga7dac9dac65cbbea7e411adcf2c314ac5">PlayerInfoType</a> : int32_t { <a href="multimedia_player.md#gga7dac9dac65cbbea7e411adcf2c314ac5ab5ccacbb568a9b3ce5fedc0ced4e683d">PLAYER_INFO_RENDER_START</a> = 0 }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">&nbsp;</td>
</tr>
</tbody>
</table>

## Public Member Functions<a name="pub-methods"></a>

<a name="table530012214165632"></a>
<table><thead align="left"><tr id="row981656416165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p174152670165632"><a name="p174152670165632"></a><a name="p174152670165632"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1467530991165632"><a name="p1467530991165632"></a><a name="p1467530991165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1506416429165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p569966650165632"><a name="p569966650165632"></a><a name="p569966650165632"></a><a href="multimedia_player.md#ga3b56f618340bf9a5590e6142b2311302">OnPlaybackComplete</a> ()=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p703420046165632"><a name="p703420046165632"></a><a name="p703420046165632"></a>virtual void </p>
<p id="p647221730165632"><a name="p647221730165632"></a><a name="p647221730165632"></a>Called when the playback is complete. </p>
</td>
</tr>
<tr id="row11976605165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1439409359165632"><a name="p1439409359165632"></a><a name="p1439409359165632"></a><a href="multimedia_player.md#ga3d0fdad57045f5e049b56de031d3e0fb">OnError</a> (int32_t errorType, int32_t errorCode)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p796044607165632"><a name="p796044607165632"></a><a name="p796044607165632"></a>virtual void </p>
<p id="p1689125927165632"><a name="p1689125927165632"></a><a name="p1689125927165632"></a>Called when a playback error occurs. </p>
</td>
</tr>
<tr id="row223596278165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1659921409165632"><a name="p1659921409165632"></a><a name="p1659921409165632"></a><a href="multimedia_player.md#gad2d3466c8a17ee4d622b87fa6a31b2bb">OnInfo</a> (int type, int extra)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1260821476165632"><a name="p1260821476165632"></a><a name="p1260821476165632"></a>virtual void </p>
<p id="p220116206165632"><a name="p220116206165632"></a><a name="p220116206165632"></a>Called when playback information is received. </p>
</td>
</tr>
<tr id="row567291723165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2062781795165632"><a name="p2062781795165632"></a><a name="p2062781795165632"></a><a href="multimedia_player.md#gac5b641f93621d90e616d18adaa016e8a">OnVideoSizeChanged</a> (int width, int height)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p546341855165632"><a name="p546341855165632"></a><a name="p546341855165632"></a>virtual void </p>
<p id="p150778245165632"><a name="p150778245165632"></a><a name="p150778245165632"></a>Called when the video image size changes. </p>
</td>
</tr>
<tr id="row2104650165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p576088170165632"><a name="p576088170165632"></a><a name="p576088170165632"></a><a href="multimedia_player.md#ga765c499e47dfaad5e557197e964eaca3">OnRewindToComplete</a> ()=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1659488586165632"><a name="p1659488586165632"></a><a name="p1659488586165632"></a>virtual void </p>
<p id="p372239032165632"><a name="p372239032165632"></a><a name="p372239032165632"></a>Called when the rewind is complete. </p>
</td>
</tr>
</tbody>
</table>

