# AudioVolume<a name="EN-US_TOPIC_0000001054598153"></a>

-   [Overview](#section1226262637165630)
-   [Summary](#section1494919611165630)
-   [Data Fields](#pub-attribs)
-   [Details](#section816896005165630)
-   [Field](#section916202426165630)
-   [GetGain](#a5ff7f9e5b763d20822a1fadecc5a8db7)
-   [GetGainThreshold](#aa42ff18fa2b7e6780acf120ea49054ed)
-   [GetMute](#a75fcb5bda7e0ca9b823187f6056ad1d4)
-   [GetVolume](#a649524ce280ecdb62ddacb78e1a63439)
-   [SetGain](#ab667c5f8754d0b10121451a57abbe429)
-   [SetMute](#a79c127fa37eb2dbf8dc5fe9f0ed4421e)
-   [SetVolume](#aebf67caf924cba5f3be9d0f395390908)

## **Overview**<a name="section1226262637165630"></a>

**Related Modules:**

[Audio](audio.md)

**Description:**

Provides volume-related APIs for audio rendering or capturing, including functions to set the mute operation, volume, and gain. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1494919611165630"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1792616372165630"></a>
<table><thead align="left"><tr id="row1361613065165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1872487465165630"><a name="p1872487465165630"></a><a name="p1872487465165630"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p228375178165630"><a name="p228375178165630"></a><a name="p228375178165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row66366686165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1671931227165630"><a name="p1671931227165630"></a><a name="p1671931227165630"></a><a href="audiovolume.md#a79c127fa37eb2dbf8dc5fe9f0ed4421e">SetMute</a> )(<a href="audio.md#ga18675ddb073465fdeac33a897f675d79">AudioHandle</a> handle, bool mute)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1893677993165630"><a name="p1893677993165630"></a><a name="p1893677993165630"></a>int32_t(* </p>
<p id="p165369336165630"><a name="p165369336165630"></a><a name="p165369336165630"></a>Sets the mute operation for the audio. </p>
</td>
</tr>
<tr id="row414924271165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1510943443165630"><a name="p1510943443165630"></a><a name="p1510943443165630"></a><a href="audiovolume.md#a75fcb5bda7e0ca9b823187f6056ad1d4">GetMute</a> )(<a href="audio.md#ga18675ddb073465fdeac33a897f675d79">AudioHandle</a> handle, bool *mute)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2041184352165630"><a name="p2041184352165630"></a><a name="p2041184352165630"></a>int32_t(* </p>
<p id="p159541961165630"><a name="p159541961165630"></a><a name="p159541961165630"></a>Obtains the mute operation set for the audio. </p>
</td>
</tr>
<tr id="row932589688165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1044221255165630"><a name="p1044221255165630"></a><a name="p1044221255165630"></a><a href="audiovolume.md#aebf67caf924cba5f3be9d0f395390908">SetVolume</a> )(<a href="audio.md#ga18675ddb073465fdeac33a897f675d79">AudioHandle</a> handle, float volume)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p461668928165630"><a name="p461668928165630"></a><a name="p461668928165630"></a>int32_t(* </p>
<p id="p1178130362165630"><a name="p1178130362165630"></a><a name="p1178130362165630"></a>Sets the audio volume. </p>
</td>
</tr>
<tr id="row227114722165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2114153180165630"><a name="p2114153180165630"></a><a name="p2114153180165630"></a><a href="audiovolume.md#a649524ce280ecdb62ddacb78e1a63439">GetVolume</a> )(<a href="audio.md#ga18675ddb073465fdeac33a897f675d79">AudioHandle</a> handle, float *volume)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1083692459165630"><a name="p1083692459165630"></a><a name="p1083692459165630"></a>int32_t(* </p>
<p id="p705264234165630"><a name="p705264234165630"></a><a name="p705264234165630"></a>Obtains the audio volume. </p>
</td>
</tr>
<tr id="row132951764165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1510998621165630"><a name="p1510998621165630"></a><a name="p1510998621165630"></a><a href="audiovolume.md#aa42ff18fa2b7e6780acf120ea49054ed">GetGainThreshold</a> )(<a href="audio.md#ga18675ddb073465fdeac33a897f675d79">AudioHandle</a> handle, float *min, float *max)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p76391916165630"><a name="p76391916165630"></a><a name="p76391916165630"></a>int32_t(* </p>
<p id="p297914872165630"><a name="p297914872165630"></a><a name="p297914872165630"></a>Obtains the range of the audio gain. </p>
</td>
</tr>
<tr id="row36827990165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1953531896165630"><a name="p1953531896165630"></a><a name="p1953531896165630"></a><a href="audiovolume.md#a5ff7f9e5b763d20822a1fadecc5a8db7">GetGain</a> )(<a href="audio.md#ga18675ddb073465fdeac33a897f675d79">AudioHandle</a> handle, float *gain)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1632445786165630"><a name="p1632445786165630"></a><a name="p1632445786165630"></a>int32_t(* </p>
<p id="p73787185165630"><a name="p73787185165630"></a><a name="p73787185165630"></a>Obtains the audio gain. </p>
</td>
</tr>
<tr id="row1128626165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p682096576165630"><a name="p682096576165630"></a><a name="p682096576165630"></a><a href="audiovolume.md#ab667c5f8754d0b10121451a57abbe429">SetGain</a> )(<a href="audio.md#ga18675ddb073465fdeac33a897f675d79">AudioHandle</a> handle, float gain)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1276213199165630"><a name="p1276213199165630"></a><a name="p1276213199165630"></a>int32_t(* </p>
<p id="p1641007725165630"><a name="p1641007725165630"></a><a name="p1641007725165630"></a>Sets the audio gain. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section816896005165630"></a>

## **Field **<a name="section916202426165630"></a>

## GetGain<a name="a5ff7f9e5b763d20822a1fadecc5a8db7"></a>

```
int32_t(* AudioVolume::GetGain) ([AudioHandle](audio.md#ga18675ddb073465fdeac33a897f675d79) handle, float *gain)
```

 **Description:**

Obtains the audio gain. 

**Parameters:**

<a name="table2019327117165630"></a>
<table><thead align="left"><tr id="row1958435862165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p725400505165630"><a name="p725400505165630"></a><a name="p725400505165630"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1724393084165630"><a name="p1724393084165630"></a><a name="p1724393084165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row722080466165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the audio handle. </td>
</tr>
<tr id="row1567684520165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">gain</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the audio gain. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the audio gain is obtained; returns a negative value otherwise. 

**See also:**

[GetGainThreshold](audiovolume.md#aa42ff18fa2b7e6780acf120ea49054ed) 

 [SetGain](audiovolume.md#ab667c5f8754d0b10121451a57abbe429) 

## GetGainThreshold<a name="aa42ff18fa2b7e6780acf120ea49054ed"></a>

```
int32_t(* AudioVolume::GetGainThreshold) ([AudioHandle](audio.md#ga18675ddb073465fdeac33a897f675d79) handle, float *min, float *max)
```

 **Description:**

Obtains the range of the audio gain. 

The audio gain can be expressed in one of the following two ways \(depending on the chip platform\), corresponding to two types of value ranges: 

**Parameters:**

<a name="table1894408723165630"></a>
<table><thead align="left"><tr id="row64681476165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p301929939165630"><a name="p301929939165630"></a><a name="p301929939165630"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2016815651165630"><a name="p2016815651165630"></a><a name="p2016815651165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row809325827165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the audio handle. </td>
</tr>
<tr id="row1572647179165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">min</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the minimum value of the range. </td>
</tr>
<tr id="row1667223967165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">max</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the maximum value of the range. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the range is obtained; returns a negative value otherwise. 

**See also:**

[GetGain](audiovolume.md#a5ff7f9e5b763d20822a1fadecc5a8db7) 

 [SetGain](audiovolume.md#ab667c5f8754d0b10121451a57abbe429) 

## GetMute<a name="a75fcb5bda7e0ca9b823187f6056ad1d4"></a>

```
int32_t(* AudioVolume::GetMute) ([AudioHandle](audio.md#ga18675ddb073465fdeac33a897f675d79) handle, bool *mute)
```

 **Description:**

Obtains the mute operation set for the audio. 

**Parameters:**

<a name="table759443696165630"></a>
<table><thead align="left"><tr id="row1103036903165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p74843054165630"><a name="p74843054165630"></a><a name="p74843054165630"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1141931866165630"><a name="p1141931866165630"></a><a name="p1141931866165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row88505289165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the audio handle. </td>
</tr>
<tr id="row1987231941165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">mute</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the mute operation set for the audio. Value <strong id="b846269249165630"><a name="b846269249165630"></a><a name="b846269249165630"></a>true</strong> means that the audio is muted, and <strong id="b1081351625165630"><a name="b1081351625165630"></a><a name="b1081351625165630"></a>false</strong> means the opposite. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the mute operation is obtained; returns a negative value otherwise. 

**See also:**

[SetMute](audiovolume.md#a79c127fa37eb2dbf8dc5fe9f0ed4421e) 

## GetVolume<a name="a649524ce280ecdb62ddacb78e1a63439"></a>

```
int32_t(* AudioVolume::GetVolume) ([AudioHandle](audio.md#ga18675ddb073465fdeac33a897f675d79) handle, float *volume)
```

 **Description:**

Obtains the audio volume. 

**Parameters:**

<a name="table896809371165630"></a>
<table><thead align="left"><tr id="row1722616916165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p163702130165630"><a name="p163702130165630"></a><a name="p163702130165630"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p452462005165630"><a name="p452462005165630"></a><a name="p452462005165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row427725757165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the audio handle. </td>
</tr>
<tr id="row650509617165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">volume</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the volume to obtain. The value ranges from 0.0 to 1.0. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the volume is obtained; returns a negative value otherwise. 

**See also:**

[SetVolume](audiovolume.md#aebf67caf924cba5f3be9d0f395390908) 

## SetGain<a name="ab667c5f8754d0b10121451a57abbe429"></a>

```
int32_t(* AudioVolume::SetGain) ([AudioHandle](audio.md#ga18675ddb073465fdeac33a897f675d79) handle, float gain)
```

 **Description:**

Sets the audio gain. 

**Parameters:**

<a name="table1978259504165630"></a>
<table><thead align="left"><tr id="row760676907165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p139495584165630"><a name="p139495584165630"></a><a name="p139495584165630"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p423600497165630"><a name="p423600497165630"></a><a name="p423600497165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row412570313165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the audio handle. </td>
</tr>
<tr id="row2106778411165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">gain</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the audio gain to set. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the setting is successful; returns a negative value otherwise. 

**See also:**

[GetGainThreshold](audiovolume.md#aa42ff18fa2b7e6780acf120ea49054ed) 

 [GetGain](audiovolume.md#a5ff7f9e5b763d20822a1fadecc5a8db7) 

## SetMute<a name="a79c127fa37eb2dbf8dc5fe9f0ed4421e"></a>

```
int32_t(* AudioVolume::SetMute) ([AudioHandle](audio.md#ga18675ddb073465fdeac33a897f675d79) handle, bool mute)
```

 **Description:**

Sets the mute operation for the audio. 

**Parameters:**

<a name="table279989646165630"></a>
<table><thead align="left"><tr id="row242638122165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1812111574165630"><a name="p1812111574165630"></a><a name="p1812111574165630"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p950316042165630"><a name="p950316042165630"></a><a name="p950316042165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1633600664165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the audio handle. </td>
</tr>
<tr id="row1846689571165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">mute</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Specifies whether to mute the audio. Value <strong id="b119634681165630"><a name="b119634681165630"></a><a name="b119634681165630"></a>true</strong> means to mute the audio, and <strong id="b515994639165630"><a name="b515994639165630"></a><a name="b515994639165630"></a>false</strong> means the opposite. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the setting is successful; returns a negative value otherwise. 

**See also:**

[GetMute](audiovolume.md#a75fcb5bda7e0ca9b823187f6056ad1d4) 

## SetVolume<a name="aebf67caf924cba5f3be9d0f395390908"></a>

```
int32_t(* AudioVolume::SetVolume) ([AudioHandle](audio.md#ga18675ddb073465fdeac33a897f675d79) handle, float volume)
```

 **Description:**

Sets the audio volume. 

The volume ranges from 0.0 to 1.0. If the volume level in an audio service ranges from 0 to 15,  **0.0**  indicates that the audio is muted, and  **1.0**  indicates the maximum volume level \(15\).

**Parameters:**

<a name="table1279802537165630"></a>
<table><thead align="left"><tr id="row2072535665165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p294966785165630"><a name="p294966785165630"></a><a name="p294966785165630"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1966033554165630"><a name="p1966033554165630"></a><a name="p1966033554165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1632613951165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the audio handle. </td>
</tr>
<tr id="row539967185165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">volume</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the volume to set. The value ranges from 0.0 to 1.0. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the setting is successful; returns a negative value otherwise. 

**See also:**

[GetVolume](audiovolume.md#a649524ce280ecdb62ddacb78e1a63439) 

