# AudioControl<a name="EN-US_TOPIC_0000001055078129"></a>

-   [Overview](#section1915690746165630)
-   [Summary](#section471008123165630)
-   [Data Fields](#pub-attribs)
-   [Details](#section1829845227165630)
-   [Field](#section1736957898165630)
-   [Flush](#acebc54c385b91ddc52b6b7849ddf12d0)
-   [Pause](#a16a26deffa17b9f143f602763a260908)
-   [Resume](#ac59c3e9a5ff9041989871f67253a1e8d)
-   [Start](#a80ddae13819bb1eb348ad4b57597e930)
-   [Stop](#a62e385e391ba1efed35021ee67ab9449)

## **Overview**<a name="section1915690746165630"></a>

**Related Modules:**

[Audio](audio.md)

**Description:**

Provides control-related APIs for audio rendering or capturing, including functions to start, stop, pause, and resume audio rendering or capturing, and flush data in the audio buffer. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section471008123165630"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table913651679165630"></a>
<table><thead align="left"><tr id="row424836748165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p663519468165630"><a name="p663519468165630"></a><a name="p663519468165630"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p262600805165630"><a name="p262600805165630"></a><a name="p262600805165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row590005424165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p590739177165630"><a name="p590739177165630"></a><a name="p590739177165630"></a><a href="audiocontrol.md#a80ddae13819bb1eb348ad4b57597e930">Start</a> )(<a href="audio.md#ga18675ddb073465fdeac33a897f675d79">AudioHandle</a> handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p197544312165630"><a name="p197544312165630"></a><a name="p197544312165630"></a>int32_t(* </p>
<p id="p1989052407165630"><a name="p1989052407165630"></a><a name="p1989052407165630"></a>Starts audio rendering or capturing. </p>
</td>
</tr>
<tr id="row930537539165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1644550050165630"><a name="p1644550050165630"></a><a name="p1644550050165630"></a><a href="audiocontrol.md#a62e385e391ba1efed35021ee67ab9449">Stop</a> )(<a href="audio.md#ga18675ddb073465fdeac33a897f675d79">AudioHandle</a> handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p775759175165630"><a name="p775759175165630"></a><a name="p775759175165630"></a>int32_t(* </p>
<p id="p1387787306165630"><a name="p1387787306165630"></a><a name="p1387787306165630"></a>Stops audio rendering or capturing. </p>
</td>
</tr>
<tr id="row1877722804165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p629612790165630"><a name="p629612790165630"></a><a name="p629612790165630"></a><a href="audiocontrol.md#a16a26deffa17b9f143f602763a260908">Pause</a> )(<a href="audio.md#ga18675ddb073465fdeac33a897f675d79">AudioHandle</a> handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1650865485165630"><a name="p1650865485165630"></a><a name="p1650865485165630"></a>int32_t(* </p>
<p id="p1754056862165630"><a name="p1754056862165630"></a><a name="p1754056862165630"></a>Pauses audio rendering or capturing. </p>
</td>
</tr>
<tr id="row1579269786165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1058729515165630"><a name="p1058729515165630"></a><a name="p1058729515165630"></a><a href="audiocontrol.md#ac59c3e9a5ff9041989871f67253a1e8d">Resume</a> )(<a href="audio.md#ga18675ddb073465fdeac33a897f675d79">AudioHandle</a> handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p960555401165630"><a name="p960555401165630"></a><a name="p960555401165630"></a>int32_t(* </p>
<p id="p874451493165630"><a name="p874451493165630"></a><a name="p874451493165630"></a>Resumes audio rendering or capturing. </p>
</td>
</tr>
<tr id="row958953951165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1727156708165630"><a name="p1727156708165630"></a><a name="p1727156708165630"></a><a href="audiocontrol.md#acebc54c385b91ddc52b6b7849ddf12d0">Flush</a> )(<a href="audio.md#ga18675ddb073465fdeac33a897f675d79">AudioHandle</a> handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p825093597165630"><a name="p825093597165630"></a><a name="p825093597165630"></a>int32_t(* </p>
<p id="p1897354020165630"><a name="p1897354020165630"></a><a name="p1897354020165630"></a>Flushes data in the audio buffer. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1829845227165630"></a>

## **Field **<a name="section1736957898165630"></a>

## Flush<a name="acebc54c385b91ddc52b6b7849ddf12d0"></a>

```
int32_t(* AudioControl::Flush) ([AudioHandle](audio.md#ga18675ddb073465fdeac33a897f675d79) handle)
```

 **Description:**

Flushes data in the audio buffer. 

**Parameters:**

<a name="table29286114165630"></a>
<table><thead align="left"><tr id="row904220018165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1244846179165630"><a name="p1244846179165630"></a><a name="p1244846179165630"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1546107614165630"><a name="p1546107614165630"></a><a name="p1546107614165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row357820310165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the audio handle. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the flush is successful; returns a negative value otherwise. 

## Pause<a name="a16a26deffa17b9f143f602763a260908"></a>

```
int32_t(* AudioControl::Pause) ([AudioHandle](audio.md#ga18675ddb073465fdeac33a897f675d79) handle)
```

 **Description:**

Pauses audio rendering or capturing. 

**Parameters:**

<a name="table861010930165630"></a>
<table><thead align="left"><tr id="row1124471426165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p765081605165630"><a name="p765081605165630"></a><a name="p765081605165630"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1234121424165630"><a name="p1234121424165630"></a><a name="p1234121424165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1246485012165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the audio handle. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the rendering or capturing is successfully paused; returns a negative value otherwise. 

**See also:**

[Resume](audiocontrol.md#ac59c3e9a5ff9041989871f67253a1e8d) 

## Resume<a name="ac59c3e9a5ff9041989871f67253a1e8d"></a>

```
int32_t(* AudioControl::Resume) ([AudioHandle](audio.md#ga18675ddb073465fdeac33a897f675d79) handle)
```

 **Description:**

Resumes audio rendering or capturing. 

**Parameters:**

<a name="table1441830116165630"></a>
<table><thead align="left"><tr id="row1351127097165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1699309689165630"><a name="p1699309689165630"></a><a name="p1699309689165630"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1220392696165630"><a name="p1220392696165630"></a><a name="p1220392696165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row405533148165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the audio handle. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the rendering or capturing is successfully resumed; returns a negative value otherwise. 

**See also:**

[Pause](audiocontrol.md#a16a26deffa17b9f143f602763a260908) 

## Start<a name="a80ddae13819bb1eb348ad4b57597e930"></a>

```
int32_t(* AudioControl::Start) ([AudioHandle](audio.md#ga18675ddb073465fdeac33a897f675d79) handle)
```

 **Description:**

Starts audio rendering or capturing. 

**Parameters:**

<a name="table2074490849165630"></a>
<table><thead align="left"><tr id="row111724500165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p387062710165630"><a name="p387062710165630"></a><a name="p387062710165630"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p660658480165630"><a name="p660658480165630"></a><a name="p660658480165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1473412452165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the audio handle. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the rendering or capturing is successfully started; returns a negative value otherwise. 

**See also:**

[Stop](audiocontrol.md#a62e385e391ba1efed35021ee67ab9449) 

## Stop<a name="a62e385e391ba1efed35021ee67ab9449"></a>

```
int32_t(* AudioControl::Stop) ([AudioHandle](audio.md#ga18675ddb073465fdeac33a897f675d79) handle)
```

 **Description:**

Stops audio rendering or capturing. 

**Parameters:**

<a name="table214475758165630"></a>
<table><thead align="left"><tr id="row639906630165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1700390875165630"><a name="p1700390875165630"></a><a name="p1700390875165630"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1305674072165630"><a name="p1305674072165630"></a><a name="p1305674072165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row771636090165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the audio handle. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the rendering or capturing is successfully stopped; returns a negative value otherwise. 

**See also:**

[Start](audiocontrol.md#a80ddae13819bb1eb348ad4b57597e930) 

