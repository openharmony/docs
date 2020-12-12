# AudioAttribute<a name="ZH-CN_TOPIC_0000001055198120"></a>

-   [Overview](#section1896801825165630)
-   [Summary](#section1215842888165630)
-   [Data Fields](#pub-attribs)
-   [Details](#section424170924165630)
-   [Field](#section109559353165630)
-   [GetCurrentChannelId](#ad070369ffa9d88df541aaf0ffbbcfbfd)
-   [GetFrameCount](#ab31fee582dc33b9320e0a0e5d16ae0e6)
-   [GetFrameSize](#a74a23f0544ac688223e61fa71a307851)
-   [GetSampleAttributes](#a2f92d8704ef677a07d664c33342e4318)
-   [SetSampleAttributes](#a502fe4e4b97cd253244debcc67d45c4d)

## **Overview**<a name="section1896801825165630"></a>

**Related Modules:**

[Audio](Audio.md)

**Description:**

Provides attribute-related APIs for audio rendering or capturing, including functions to obtain frame information and set audio sampling attributes. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1215842888165630"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table813127139165630"></a>
<table><thead align="left"><tr id="row531457665165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1676146793165630"><a name="p1676146793165630"></a><a name="p1676146793165630"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p217598559165630"><a name="p217598559165630"></a><a name="p217598559165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1268453528165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1406238391165630"><a name="p1406238391165630"></a><a name="p1406238391165630"></a><a href="AudioAttribute.md#a74a23f0544ac688223e61fa71a307851">GetFrameSize</a> )(<a href="Audio.md#ga18675ddb073465fdeac33a897f675d79">AudioHandle</a> handle, uint64_t *size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2055117886165630"><a name="p2055117886165630"></a><a name="p2055117886165630"></a>int32_t(* </p>
<p id="p1213452819165630"><a name="p1213452819165630"></a><a name="p1213452819165630"></a>Obtains the audio frame size, that is, the length (in bytes) of a frame. </p>
</td>
</tr>
<tr id="row669401780165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1077974387165630"><a name="p1077974387165630"></a><a name="p1077974387165630"></a><a href="AudioAttribute.md#ab31fee582dc33b9320e0a0e5d16ae0e6">GetFrameCount</a> )(<a href="Audio.md#ga18675ddb073465fdeac33a897f675d79">AudioHandle</a> handle, uint64_t *count)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p630583296165630"><a name="p630583296165630"></a><a name="p630583296165630"></a>int32_t(* </p>
<p id="p1136116338165630"><a name="p1136116338165630"></a><a name="p1136116338165630"></a>Obtains the number of audio frames in the audio buffer. </p>
</td>
</tr>
<tr id="row757050202165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1072587895165630"><a name="p1072587895165630"></a><a name="p1072587895165630"></a><a href="AudioAttribute.md#a502fe4e4b97cd253244debcc67d45c4d">SetSampleAttributes</a> )(<a href="Audio.md#ga18675ddb073465fdeac33a897f675d79">AudioHandle</a> handle, const struct <a href="AudioSampleAttributes.md">AudioSampleAttributes</a> *attrs)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1023345903165630"><a name="p1023345903165630"></a><a name="p1023345903165630"></a>int32_t(* </p>
<p id="p1106266299165630"><a name="p1106266299165630"></a><a name="p1106266299165630"></a>Sets audio sampling attributes. </p>
</td>
</tr>
<tr id="row413853696165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p957093953165630"><a name="p957093953165630"></a><a name="p957093953165630"></a><a href="AudioAttribute.md#a2f92d8704ef677a07d664c33342e4318">GetSampleAttributes</a> )(<a href="Audio.md#ga18675ddb073465fdeac33a897f675d79">AudioHandle</a> handle, struct <a href="AudioSampleAttributes.md">AudioSampleAttributes</a> *attrs)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1666197557165630"><a name="p1666197557165630"></a><a name="p1666197557165630"></a>int32_t(* </p>
<p id="p719364657165630"><a name="p719364657165630"></a><a name="p719364657165630"></a>Obtains audio sampling attributes. </p>
</td>
</tr>
<tr id="row198024644165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p282854730165630"><a name="p282854730165630"></a><a name="p282854730165630"></a><a href="AudioAttribute.md#ad070369ffa9d88df541aaf0ffbbcfbfd">GetCurrentChannelId</a> )(<a href="Audio.md#ga18675ddb073465fdeac33a897f675d79">AudioHandle</a> handle, uint32_t *channelId)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p833944951165630"><a name="p833944951165630"></a><a name="p833944951165630"></a>int32_t(* </p>
<p id="p298153789165630"><a name="p298153789165630"></a><a name="p298153789165630"></a>Obtains the data channel ID of the audio. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section424170924165630"></a>

## **Field **<a name="section109559353165630"></a>

## GetCurrentChannelId<a name="ad070369ffa9d88df541aaf0ffbbcfbfd"></a>

```
int32_t(* AudioAttribute::GetCurrentChannelId) ([AudioHandle](Audio.md#ga18675ddb073465fdeac33a897f675d79) handle, uint32_t *channelId)
```

 **Description:**

Obtains the data channel ID of the audio. 

**Parameters:**

<a name="table1370364551165630"></a>
<table><thead align="left"><tr id="row124187666165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p246538358165630"><a name="p246538358165630"></a><a name="p246538358165630"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1658920087165630"><a name="p1658920087165630"></a><a name="p1658920087165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1724796309165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the audio handle. </td>
</tr>
<tr id="row368755810165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">channelId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the data channel ID. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the data channel ID is obtained; returns a negative value otherwise. 

## GetFrameCount<a name="ab31fee582dc33b9320e0a0e5d16ae0e6"></a>

```
int32_t(* AudioAttribute::GetFrameCount) ([AudioHandle](Audio.md#ga18675ddb073465fdeac33a897f675d79) handle, uint64_t *count)
```

 **Description:**

Obtains the number of audio frames in the audio buffer. 

**Parameters:**

<a name="table1046932222165630"></a>
<table><thead align="left"><tr id="row1253819951165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p340281978165630"><a name="p340281978165630"></a><a name="p340281978165630"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p840237136165630"><a name="p840237136165630"></a><a name="p840237136165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row22509538165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the audio handle. </td>
</tr>
<tr id="row1652524793165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">count</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the number of audio frames in the audio buffer. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the number of audio frames is obtained; returns a negative value otherwise. 

## GetFrameSize<a name="a74a23f0544ac688223e61fa71a307851"></a>

```
int32_t(* AudioAttribute::GetFrameSize) ([AudioHandle](Audio.md#ga18675ddb073465fdeac33a897f675d79) handle, uint64_t *size)
```

 **Description:**

Obtains the audio frame size, that is, the length \(in bytes\) of a frame. 

**Parameters:**

<a name="table1091781357165630"></a>
<table><thead align="left"><tr id="row1503692246165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p346085992165630"><a name="p346085992165630"></a><a name="p346085992165630"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2112379702165630"><a name="p2112379702165630"></a><a name="p2112379702165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row794146689165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the audio handle. </td>
</tr>
<tr id="row1353012076165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">size</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the audio frame size (in bytes). </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the audio frame size is obtained; returns a negative value otherwise. 

## GetSampleAttributes<a name="a2f92d8704ef677a07d664c33342e4318"></a>

```
int32_t(* AudioAttribute::GetSampleAttributes) ([AudioHandle](Audio.md#ga18675ddb073465fdeac33a897f675d79) handle, struct [AudioSampleAttributes](AudioSampleAttributes.md) *attrs)
```

 **Description:**

Obtains audio sampling attributes. 

**Parameters:**

<a name="table281052098165630"></a>
<table><thead align="left"><tr id="row1183120563165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1857612040165630"><a name="p1857612040165630"></a><a name="p1857612040165630"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1134854099165630"><a name="p1134854099165630"></a><a name="p1134854099165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row191244578165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the audio handle. </td>
</tr>
<tr id="row769815820165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">attrs</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the audio sampling attributes, such as the sampling rate, sampling precision, and channel. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if audio sampling attributes are obtained; returns a negative value otherwise. 

**See also:**

[SetSampleAttributes](AudioAttribute.md#a502fe4e4b97cd253244debcc67d45c4d) 

## SetSampleAttributes<a name="a502fe4e4b97cd253244debcc67d45c4d"></a>

```
int32_t(* AudioAttribute::SetSampleAttributes) ([AudioHandle](Audio.md#ga18675ddb073465fdeac33a897f675d79) handle, const struct [AudioSampleAttributes](AudioSampleAttributes.md) *attrs)
```

 **Description:**

Sets audio sampling attributes. 

**Parameters:**

<a name="table298221175165630"></a>
<table><thead align="left"><tr id="row515102222165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p647673690165630"><a name="p647673690165630"></a><a name="p647673690165630"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1693156902165630"><a name="p1693156902165630"></a><a name="p1693156902165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row168596454165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the audio handle. </td>
</tr>
<tr id="row2016887318165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">attrs</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the audio sampling attributes to set, such as the sampling rate, sampling precision, and channel. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the setting is successful; returns a negative value otherwise. 

**See also:**

[GetSampleAttributes](AudioAttribute.md#a2f92d8704ef677a07d664c33342e4318) 

