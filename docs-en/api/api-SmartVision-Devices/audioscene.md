# AudioScene<a name="EN-US_TOPIC_0000001054718117"></a>

-   [Overview](#section363513269165630)
-   [Summary](#section868572158165630)
-   [Data Fields](#pub-attribs)
-   [Details](#section396807424165630)
-   [Field](#section649234473165630)
-   [CheckSceneCapability](#a9b485404b2ec3b8bc2b8d1b73401d45c)
-   [SelectScene](#aacdbf3a9f488a7e71f3a5a23c68c0068)

## **Overview**<a name="section363513269165630"></a>

**Related Modules:**

[Audio](audio.md)

**Description:**

Provides scene-related APIs for audio rendering or capturing, including functions to select an audio scene and check whether the configuration of an audio scene is supported. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section868572158165630"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table395166268165630"></a>
<table><thead align="left"><tr id="row745628450165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1733721890165630"><a name="p1733721890165630"></a><a name="p1733721890165630"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2057353778165630"><a name="p2057353778165630"></a><a name="p2057353778165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1907289026165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2074566717165630"><a name="p2074566717165630"></a><a name="p2074566717165630"></a><a href="audioscene.md#a9b485404b2ec3b8bc2b8d1b73401d45c">CheckSceneCapability</a> )(<a href="audio.md#ga18675ddb073465fdeac33a897f675d79">AudioHandle</a> handle, const struct <a href="audioscenedescriptor.md">AudioSceneDescriptor</a> *scene, bool *supported)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1845022823165630"><a name="p1845022823165630"></a><a name="p1845022823165630"></a>int32_t(* </p>
<p id="p1667896909165630"><a name="p1667896909165630"></a><a name="p1667896909165630"></a>Checks whether the configuration of an audio scene is supported. </p>
</td>
</tr>
<tr id="row354360920165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1306087091165630"><a name="p1306087091165630"></a><a name="p1306087091165630"></a><a href="audioscene.md#aacdbf3a9f488a7e71f3a5a23c68c0068">SelectScene</a> )(<a href="audio.md#ga18675ddb073465fdeac33a897f675d79">AudioHandle</a> handle, const struct <a href="audioscenedescriptor.md">AudioSceneDescriptor</a> *scene)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1407047279165630"><a name="p1407047279165630"></a><a name="p1407047279165630"></a>int32_t(* </p>
<p id="p79342700165630"><a name="p79342700165630"></a><a name="p79342700165630"></a>Selects an audio scene. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section396807424165630"></a>

## **Field **<a name="section649234473165630"></a>

## CheckSceneCapability<a name="a9b485404b2ec3b8bc2b8d1b73401d45c"></a>

```
int32_t(* AudioScene::CheckSceneCapability) ([AudioHandle](audio.md#ga18675ddb073465fdeac33a897f675d79) handle, const struct [AudioSceneDescriptor](audioscenedescriptor.md) *scene, bool *supported)
```

 **Description:**

Checks whether the configuration of an audio scene is supported. 

**Parameters:**

<a name="table363433310165630"></a>
<table><thead align="left"><tr id="row1715501585165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p72003945165630"><a name="p72003945165630"></a><a name="p72003945165630"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p418730622165630"><a name="p418730622165630"></a><a name="p418730622165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row124828279165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the audio handle. </td>
</tr>
<tr id="row1503801719165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">scene</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the descriptor of the audio scene. </td>
</tr>
<tr id="row1483715887165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">supported</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the variable specifying whether the configuration is supported. Value <strong id="b657474469165630"><a name="b657474469165630"></a><a name="b657474469165630"></a>true</strong> means that the configuration is supported, and <strong id="b1307982512165630"><a name="b1307982512165630"></a><a name="b1307982512165630"></a>false</strong> means the opposite. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the result is obtained; returns a negative value otherwise. 

**See also:**

[SelectScene](audioscene.md#aacdbf3a9f488a7e71f3a5a23c68c0068) 

## SelectScene<a name="aacdbf3a9f488a7e71f3a5a23c68c0068"></a>

```
int32_t(* AudioScene::SelectScene) ([AudioHandle](audio.md#ga18675ddb073465fdeac33a897f675d79) handle, const struct [AudioSceneDescriptor](audioscenedescriptor.md) *scene)
```

 **Description:**

Selects an audio scene. 

**Parameters:**

<a name="table1842803044165630"></a>
<table><thead align="left"><tr id="row1584316640165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1289673619165630"><a name="p1289673619165630"></a><a name="p1289673619165630"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1182488991165630"><a name="p1182488991165630"></a><a name="p1182488991165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1507735045165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the audio handle. </td>
</tr>
<tr id="row47068069165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">scene</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the descriptor of the audio scene to select. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the scene is selected successfully; returns a negative value otherwise. 

**See also:**

[CheckSceneCapability](audioscene.md#a9b485404b2ec3b8bc2b8d1b73401d45c) 

