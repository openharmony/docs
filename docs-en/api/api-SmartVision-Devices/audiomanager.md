# AudioManager<a name="EN-US_TOPIC_0000001054598151"></a>

-   [Overview](#section92245219165630)
-   [Summary](#section1284654492165630)
-   [Data Fields](#pub-attribs)
-   [Details](#section1307104535165630)
-   [Field](#section435920409165630)
-   [GetAllAdapters](#a93a0ffb0df907fabcfca827d31dadf39)
-   [LoadAdapter](#ab090e9c760a2888b55acc7baa4222ccb)
-   [UnloadAdapter](#a556137764c5bf784972ba79303720fc3)

## **Overview**<a name="section92245219165630"></a>

**Related Modules:**

[Audio](audio.md)

**Description:**

Manages audio adapters through a specific adapter driver program loaded based on the given audio adapter descriptor. 

See also
:   [AudioAdapter](audioadapter.md) 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1284654492165630"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1340527142165630"></a>
<table><thead align="left"><tr id="row194446610165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1369309278165630"><a name="p1369309278165630"></a><a name="p1369309278165630"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2049272097165630"><a name="p2049272097165630"></a><a name="p2049272097165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row152334548165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1140648746165630"><a name="p1140648746165630"></a><a name="p1140648746165630"></a><a href="audiomanager.md#a93a0ffb0df907fabcfca827d31dadf39">GetAllAdapters</a> )(struct <a href="audiomanager.md">AudioManager</a> *manager, struct <a href="audioadapterdescriptor.md">AudioAdapterDescriptor</a> **descs, int32_t *size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1247730582165630"><a name="p1247730582165630"></a><a name="p1247730582165630"></a>int32_t(* </p>
<p id="p1123591801165630"><a name="p1123591801165630"></a><a name="p1123591801165630"></a>Obtains the list of all adapters supported by an audio driver. </p>
</td>
</tr>
<tr id="row341552850165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1057224458165630"><a name="p1057224458165630"></a><a name="p1057224458165630"></a><a href="audiomanager.md#ab090e9c760a2888b55acc7baa4222ccb">LoadAdapter</a> )(struct <a href="audiomanager.md">AudioManager</a> *manager, const struct <a href="audioadapterdescriptor.md">AudioAdapterDescriptor</a> *desc, struct <a href="audioadapter.md">AudioAdapter</a> **adapter)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1283791807165630"><a name="p1283791807165630"></a><a name="p1283791807165630"></a>int32_t(* </p>
<p id="p1190771390165630"><a name="p1190771390165630"></a><a name="p1190771390165630"></a>Loads the driver for an audio adapter. </p>
</td>
</tr>
<tr id="row1688834293165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p431049628165630"><a name="p431049628165630"></a><a name="p431049628165630"></a><a href="audiomanager.md#a556137764c5bf784972ba79303720fc3">UnloadAdapter</a> )(struct <a href="audiomanager.md">AudioManager</a> *manager, struct <a href="audioadapter.md">AudioAdapter</a> *adapter)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1864726231165630"><a name="p1864726231165630"></a><a name="p1864726231165630"></a>void(* </p>
<p id="p47368279165630"><a name="p47368279165630"></a><a name="p47368279165630"></a>Unloads the driver of an audio adapter. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1307104535165630"></a>

## **Field **<a name="section435920409165630"></a>

## GetAllAdapters<a name="a93a0ffb0df907fabcfca827d31dadf39"></a>

```
int32_t(* AudioManager::GetAllAdapters) (struct [AudioManager](audiomanager.md) *manager, struct [AudioAdapterDescriptor](audioadapterdescriptor.md) **descs, int32_t *size)
```

 **Description:**

Obtains the list of all adapters supported by an audio driver. 

**Parameters:**

<a name="table535628776165630"></a>
<table><thead align="left"><tr id="row1870233404165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p362707567165630"><a name="p362707567165630"></a><a name="p362707567165630"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1279436868165630"><a name="p1279436868165630"></a><a name="p1279436868165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row785083072165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">manager</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the audio adapter manager to operate. </td>
</tr>
<tr id="row930088954165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">descs</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double pointer to the audio adapter list. </td>
</tr>
<tr id="row1923415004165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">size</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the length of the list. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the list is obtained successfully; returns a negative value otherwise. 

**See also:**

[LoadAdapter](audiomanager.md#ab090e9c760a2888b55acc7baa4222ccb) 

## LoadAdapter<a name="ab090e9c760a2888b55acc7baa4222ccb"></a>

```
int32_t(* AudioManager::LoadAdapter) (struct [AudioManager](audiomanager.md) *manager, const struct [AudioAdapterDescriptor](audioadapterdescriptor.md) *desc, struct [AudioAdapter](audioadapter.md) **adapter)
```

 **Description:**

Loads the driver for an audio adapter. 

For example, to load a USB driver, you may need to load a dynamic-link library \(\*.so\) in specific implementation.

**Parameters:**

<a name="table1759120842165630"></a>
<table><thead align="left"><tr id="row1066157795165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p327376939165630"><a name="p327376939165630"></a><a name="p327376939165630"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p240796819165630"><a name="p240796819165630"></a><a name="p240796819165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1815017019165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">manager</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the audio adapter manager to operate. </td>
</tr>
<tr id="row1919094764165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">desc</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the descriptor of the audio adapter. </td>
</tr>
<tr id="row685686252165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">adapter</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double pointer to the audio adapter. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the driver is loaded successfully; returns a negative value otherwise. 

**See also:**

[GetAllAdapters](audiomanager.md#a93a0ffb0df907fabcfca827d31dadf39) 

 [UnloadAdapter](audiomanager.md#a556137764c5bf784972ba79303720fc3) 

## UnloadAdapter<a name="a556137764c5bf784972ba79303720fc3"></a>

```
void(* AudioManager::UnloadAdapter) (struct [AudioManager](audiomanager.md) *manager, struct [AudioAdapter](audioadapter.md) *adapter)
```

 **Description:**

Unloads the driver of an audio adapter. 

**Parameters:**

<a name="table202502867165630"></a>
<table><thead align="left"><tr id="row976104235165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1302960254165630"><a name="p1302960254165630"></a><a name="p1302960254165630"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p972442855165630"><a name="p972442855165630"></a><a name="p972442855165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row321427427165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">manager</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the audio adapter manager to operate. </td>
</tr>
<tr id="row2141599177165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">adapter</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the audio adapter whose driver will be unloaded. </td>
</tr>
</tbody>
</table>

**See also:**

[LoadAdapter](audiomanager.md#ab090e9c760a2888b55acc7baa4222ccb) 

