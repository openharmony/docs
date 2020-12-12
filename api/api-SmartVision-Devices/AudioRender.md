# AudioRender<a name="ZH-CN_TOPIC_0000001054918145"></a>

-   [Overview](#section1801946826165630)
-   [Summary](#section1078987041165630)
-   [Data Fields](#pub-attribs)
-   [Details](#section422181551165630)
-   [Field](#section202261737165630)
-   [GetChannelMode](#aad3d5e4104167620eacb2ba23edce50e)
-   [GetLatency](#a56dff6bbe1c5ac8361b2e3238ab09563)
-   [GetRenderPosition](#a24072bec0e2cd75727b57ec3e14f7ccb)
-   [GetRenderSpeed](#af0a19dacb293d3fbe600902b93af1ee9)
-   [RenderFrame](#a463cab04d0805a5c7b3ba5884c468246)
-   [SetChannelMode](#ae5aad5b26ccdd65ba501620851c5ecec)
-   [SetRenderSpeed](#a5589427ae5a4ba6a8d2a19dd8eddbcd8)

## **Overview**<a name="section1801946826165630"></a>

**Related Modules:**

[Audio](Audio.md)

**Description:**

Provides capabilities for audio rendering, including controlling the rendering, setting audio attributes, scenes, and volume, obtaining hardware latency, and rendering audio frames. 

See also
:   [AudioControl](AudioControl.md) 

:    [AudioAttribute](AudioAttribute.md) 

:    [AudioScene](AudioScene.md) 

:    [AudioVolume](AudioVolume.md) 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1078987041165630"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table583249273165630"></a>
<table><thead align="left"><tr id="row519575427165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p741752475165630"><a name="p741752475165630"></a><a name="p741752475165630"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1556224858165630"><a name="p1556224858165630"></a><a name="p1556224858165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1307610117165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p691315309165630"><a name="p691315309165630"></a><a name="p691315309165630"></a>control </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1026032502165630"><a name="p1026032502165630"></a><a name="p1026032502165630"></a><strong id="a954721a6d70c6cc96d8a772740b5749b"><a name="a954721a6d70c6cc96d8a772740b5749b"></a><a name="a954721a6d70c6cc96d8a772740b5749b"></a></strong> struct <a href="AudioControl.md">AudioControl</a> </p>
<p id="p977638680165630"><a name="p977638680165630"></a><a name="p977638680165630"></a>Defines the audio control. For details, see <a href="AudioControl.md">AudioControl</a>. </p>
</td>
</tr>
<tr id="row35245260165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p219663709165630"><a name="p219663709165630"></a><a name="p219663709165630"></a>attr </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p432438150165630"><a name="p432438150165630"></a><a name="p432438150165630"></a><strong id="a6933f5dbf34758cea050e2e5d25e69e6"><a name="a6933f5dbf34758cea050e2e5d25e69e6"></a><a name="a6933f5dbf34758cea050e2e5d25e69e6"></a></strong> struct <a href="AudioAttribute.md">AudioAttribute</a> </p>
<p id="p371225361165630"><a name="p371225361165630"></a><a name="p371225361165630"></a>Defines the audio attribute. For details, see <a href="AudioAttribute.md">AudioAttribute</a>. </p>
</td>
</tr>
<tr id="row929120582165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p989566871165630"><a name="p989566871165630"></a><a name="p989566871165630"></a>scene </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p981896208165630"><a name="p981896208165630"></a><a name="p981896208165630"></a><strong id="adcbcb3e0a5c11e507bbf2f9a8809b099"><a name="adcbcb3e0a5c11e507bbf2f9a8809b099"></a><a name="adcbcb3e0a5c11e507bbf2f9a8809b099"></a></strong> struct <a href="AudioScene.md">AudioScene</a> </p>
<p id="p1094879870165630"><a name="p1094879870165630"></a><a name="p1094879870165630"></a>Defines the audio scene. For details, see <a href="AudioScene.md">AudioScene</a>. </p>
</td>
</tr>
<tr id="row1296021210165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p618579473165630"><a name="p618579473165630"></a><a name="p618579473165630"></a>volume </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p112458968165630"><a name="p112458968165630"></a><a name="p112458968165630"></a><strong id="aff73e1461efbc8b133418f0571f4b3a8"><a name="aff73e1461efbc8b133418f0571f4b3a8"></a><a name="aff73e1461efbc8b133418f0571f4b3a8"></a></strong> struct <a href="AudioVolume.md">AudioVolume</a> </p>
<p id="p1329846508165630"><a name="p1329846508165630"></a><a name="p1329846508165630"></a>Defines audio volume. For details, see <a href="AudioVolume.md">AudioVolume</a>. </p>
</td>
</tr>
<tr id="row1449575909165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1475439913165630"><a name="p1475439913165630"></a><a name="p1475439913165630"></a><a href="AudioRender.md#a56dff6bbe1c5ac8361b2e3238ab09563">GetLatency</a> )(struct <a href="AudioRender.md">AudioRender</a> *render, uint32_t *ms)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1908922108165630"><a name="p1908922108165630"></a><a name="p1908922108165630"></a>int32_t(* </p>
<p id="p777905213165630"><a name="p777905213165630"></a><a name="p777905213165630"></a>Obtains the estimated latency of the audio device driver. </p>
</td>
</tr>
<tr id="row819947078165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1732051824165630"><a name="p1732051824165630"></a><a name="p1732051824165630"></a><a href="AudioRender.md#a463cab04d0805a5c7b3ba5884c468246">RenderFrame</a> )(struct <a href="AudioRender.md">AudioRender</a> *render, const void *frame, uint64_t requestBytes, uint64_t *replyBytes)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1155815150165630"><a name="p1155815150165630"></a><a name="p1155815150165630"></a>int32_t(* </p>
<p id="p1506662447165630"><a name="p1506662447165630"></a><a name="p1506662447165630"></a>Writes a frame of output data (downlink data) into the audio driver for rendering. </p>
</td>
</tr>
<tr id="row150403123165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p71885676165630"><a name="p71885676165630"></a><a name="p71885676165630"></a><a href="AudioRender.md#a24072bec0e2cd75727b57ec3e14f7ccb">GetRenderPosition</a> )(struct <a href="AudioRender.md">AudioRender</a> *render, uint64_t *frames, struct <a href="AudioTimeStamp.md">AudioTimeStamp</a> *<a href="TIME.md#gae7841e681c8c9d59818568d39553642c">time</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p773332520165630"><a name="p773332520165630"></a><a name="p773332520165630"></a>int32_t(* </p>
<p id="p1549475463165630"><a name="p1549475463165630"></a><a name="p1549475463165630"></a>Obtains the last number of output audio frames. </p>
</td>
</tr>
<tr id="row246722412165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2121927758165630"><a name="p2121927758165630"></a><a name="p2121927758165630"></a><a href="AudioRender.md#a5589427ae5a4ba6a8d2a19dd8eddbcd8">SetRenderSpeed</a> )(struct <a href="AudioRender.md">AudioRender</a> *render, float speed)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1670179115165630"><a name="p1670179115165630"></a><a name="p1670179115165630"></a>int32_t(* </p>
<p id="p1519896748165630"><a name="p1519896748165630"></a><a name="p1519896748165630"></a>Sets the audio rendering speed. </p>
</td>
</tr>
<tr id="row1343887247165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p583964710165630"><a name="p583964710165630"></a><a name="p583964710165630"></a><a href="AudioRender.md#af0a19dacb293d3fbe600902b93af1ee9">GetRenderSpeed</a> )(struct <a href="AudioRender.md">AudioRender</a> *render, float *speed)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1462191970165630"><a name="p1462191970165630"></a><a name="p1462191970165630"></a>int32_t(* </p>
<p id="p709635514165630"><a name="p709635514165630"></a><a name="p709635514165630"></a>Obtains the current audio rendering speed. </p>
</td>
</tr>
<tr id="row1818061242165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1652994819165630"><a name="p1652994819165630"></a><a name="p1652994819165630"></a><a href="AudioRender.md#ae5aad5b26ccdd65ba501620851c5ecec">SetChannelMode</a> )(struct <a href="AudioRender.md">AudioRender</a> *render, enum <a href="Audio.md#ga78aab1fafb9657451804e42b42897123">AudioChannelMode</a> mode)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p36972693165630"><a name="p36972693165630"></a><a name="p36972693165630"></a>int32_t(* </p>
<p id="p1914326080165630"><a name="p1914326080165630"></a><a name="p1914326080165630"></a>Sets the channel mode for audio rendering. </p>
</td>
</tr>
<tr id="row819243467165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1962012832165630"><a name="p1962012832165630"></a><a name="p1962012832165630"></a><a href="AudioRender.md#aad3d5e4104167620eacb2ba23edce50e">GetChannelMode</a> )(struct <a href="AudioRender.md">AudioRender</a> *render, enum <a href="Audio.md#ga78aab1fafb9657451804e42b42897123">AudioChannelMode</a> *mode)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p487668782165630"><a name="p487668782165630"></a><a name="p487668782165630"></a>int32_t(* </p>
<p id="p696758517165630"><a name="p696758517165630"></a><a name="p696758517165630"></a>Obtains the current channel mode for audio rendering. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section422181551165630"></a>

## **Field **<a name="section202261737165630"></a>

## GetChannelMode<a name="aad3d5e4104167620eacb2ba23edce50e"></a>

```
int32_t(* AudioRender::GetChannelMode) (struct [AudioRender](AudioRender.md) *render, enum [AudioChannelMode](Audio.md#ga78aab1fafb9657451804e42b42897123) *mode)
```

 **Description:**

Obtains the current channel mode for audio rendering. 

**Parameters:**

<a name="table1479422161165630"></a>
<table><thead align="left"><tr id="row1312186405165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1254037518165630"><a name="p1254037518165630"></a><a name="p1254037518165630"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p446688904165630"><a name="p446688904165630"></a><a name="p446688904165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row105438113165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">render</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the <strong id="b1214978077165630"><a name="b1214978077165630"></a><a name="b1214978077165630"></a><a href="AudioRender.md">AudioRender</a></strong> object to operate. </td>
</tr>
<tr id="row518909084165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">mode</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the channel mode to obtain. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the mode is successfully obtained; returns a negative value otherwise. 

**See also:**

[SetChannelMode](AudioRender.md#ae5aad5b26ccdd65ba501620851c5ecec) 

## GetLatency<a name="a56dff6bbe1c5ac8361b2e3238ab09563"></a>

```
int32_t(* AudioRender::GetLatency) (struct [AudioRender](AudioRender.md) *render, uint32_t *ms)
```

 **Description:**

Obtains the estimated latency of the audio device driver. 

**Parameters:**

<a name="table1342001061165630"></a>
<table><thead align="left"><tr id="row954109909165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p27270789165630"><a name="p27270789165630"></a><a name="p27270789165630"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1898208079165630"><a name="p1898208079165630"></a><a name="p1898208079165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1491734707165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">render</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the <strong id="b1864643284165630"><a name="b1864643284165630"></a><a name="b1864643284165630"></a><a href="AudioRender.md">AudioRender</a></strong> object to operate. </td>
</tr>
<tr id="row1863804409165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">ms</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the latency (in milliseconds) to be obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the latency is obtained; returns a negative value otherwise. 

## GetRenderPosition<a name="a24072bec0e2cd75727b57ec3e14f7ccb"></a>

```
int32_t(* AudioRender::GetRenderPosition) (struct [AudioRender](AudioRender.md) *render, uint64_t *frames, struct [AudioTimeStamp](AudioTimeStamp.md) *[time](TIME.md#gae7841e681c8c9d59818568d39553642c))
```

 **Description:**

Obtains the last number of output audio frames. 

**Parameters:**

<a name="table1573388770165630"></a>
<table><thead align="left"><tr id="row42655883165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1356418689165630"><a name="p1356418689165630"></a><a name="p1356418689165630"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p483112585165630"><a name="p483112585165630"></a><a name="p483112585165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row182597291165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">render</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the <strong id="b391852111165630"><a name="b391852111165630"></a><a name="b391852111165630"></a><a href="AudioRender.md">AudioRender</a></strong> object to operate. </td>
</tr>
<tr id="row503805481165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">frames</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the last number of output audio frames. </td>
</tr>
<tr id="row498352287165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">time</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the timestamp associated with the frame. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the last number is obtained; returns a negative value otherwise. 

**See also:**

[RenderFrame](AudioRender.md#a463cab04d0805a5c7b3ba5884c468246) 

## GetRenderSpeed<a name="af0a19dacb293d3fbe600902b93af1ee9"></a>

```
int32_t(* AudioRender::GetRenderSpeed) (struct [AudioRender](AudioRender.md) *render, float *speed)
```

 **Description:**

Obtains the current audio rendering speed. 

**Parameters:**

<a name="table966855124165630"></a>
<table><thead align="left"><tr id="row716164234165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p225099539165630"><a name="p225099539165630"></a><a name="p225099539165630"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p701103142165630"><a name="p701103142165630"></a><a name="p701103142165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1596583673165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">render</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the <strong id="b1937386645165630"><a name="b1937386645165630"></a><a name="b1937386645165630"></a><a href="AudioRender.md">AudioRender</a></strong> object to operate. </td>
</tr>
<tr id="row386085092165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">speed</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the current rendering speed to obtain. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the speed is successfully obtained; returns a negative value otherwise. 

**See also:**

[SetRenderSpeed](AudioRender.md#a5589427ae5a4ba6a8d2a19dd8eddbcd8) 

## RenderFrame<a name="a463cab04d0805a5c7b3ba5884c468246"></a>

```
int32_t(* AudioRender::RenderFrame) (struct [AudioRender](AudioRender.md) *render, const void *frame, uint64_t requestBytes, uint64_t *replyBytes)
```

 **Description:**

Writes a frame of output data \(downlink data\) into the audio driver for rendering. 

**Parameters:**

<a name="table286345594165630"></a>
<table><thead align="left"><tr id="row1618546530165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1804989016165630"><a name="p1804989016165630"></a><a name="p1804989016165630"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p947742161165630"><a name="p947742161165630"></a><a name="p947742161165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row70649572165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">render</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the <strong id="b908909822165630"><a name="b908909822165630"></a><a name="b908909822165630"></a><a href="AudioRender.md">AudioRender</a></strong> object to operate. </td>
</tr>
<tr id="row2026795317165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">frame</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the frame to write. </td>
</tr>
<tr id="row2062217154165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">requestBytes</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the size of the frame, in bytes. </td>
</tr>
<tr id="row632745315165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">replyBytes</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the actual length (in bytes) of the audio data to write. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the data is written successfully; returns a negative value otherwise. 

## SetChannelMode<a name="ae5aad5b26ccdd65ba501620851c5ecec"></a>

```
int32_t(* AudioRender::SetChannelMode) (struct [AudioRender](AudioRender.md) *render, enum [AudioChannelMode](Audio.md#ga78aab1fafb9657451804e42b42897123) mode)
```

 **Description:**

Sets the channel mode for audio rendering. 

**Parameters:**

<a name="table593986487165630"></a>
<table><thead align="left"><tr id="row1228242967165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p175261138165630"><a name="p175261138165630"></a><a name="p175261138165630"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p106686877165630"><a name="p106686877165630"></a><a name="p106686877165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2071963340165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">render</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the <strong id="b857507293165630"><a name="b857507293165630"></a><a name="b857507293165630"></a><a href="AudioRender.md">AudioRender</a></strong> object to operate. </td>
</tr>
<tr id="row329016187165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">mode</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the channel mode to set. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the setting is successful; returns a negative value otherwise. 

**See also:**

[GetChannelMode](AudioRender.md#aad3d5e4104167620eacb2ba23edce50e) 

## SetRenderSpeed<a name="a5589427ae5a4ba6a8d2a19dd8eddbcd8"></a>

```
int32_t(* AudioRender::SetRenderSpeed) (struct [AudioRender](AudioRender.md) *render, float speed)
```

 **Description:**

Sets the audio rendering speed. 

**Parameters:**

<a name="table821829818165630"></a>
<table><thead align="left"><tr id="row1106136665165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p883940006165630"><a name="p883940006165630"></a><a name="p883940006165630"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1157378439165630"><a name="p1157378439165630"></a><a name="p1157378439165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1163267075165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">render</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the <strong id="b372136512165630"><a name="b372136512165630"></a><a name="b372136512165630"></a><a href="AudioRender.md">AudioRender</a></strong> object to operate. </td>
</tr>
<tr id="row1727326374165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">speed</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the rendering speed to set. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the setting is successful; returns a negative value otherwise. 

**See also:**

[GetRenderSpeed](AudioRender.md#af0a19dacb293d3fbe600902b93af1ee9) 

