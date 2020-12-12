# AudioAdapter<a name="EN-US_TOPIC_0000001054879522"></a>

-   [Overview](#section611392098165630)
-   [Summary](#section1187227500165630)
-   [Data Fields](#pub-attribs)
-   [Details](#section2025801532165630)
-   [Field](#section1769083627165630)
-   [CreateCapture](#a8a46358cdad8e0a9d15ac079713535f2)
-   [CreateRender](#a284ea2ad18ebac562ca7283652e61b50)
-   [DestroyCapture](#a1175a27c5273dab1acf8f8f3c4967637)
-   [DestroyRender](#a070a8d60f88134c58c4439d4419af913)
-   [GetPassthroughMode](#ad4c41f3193c5ec3da254f33e24241ea6)
-   [GetPortCapability](#a525ec7f3f3bb9975790e27f75145d0f6)
-   [InitAllPorts](#a3c46c9291d4c08d489454ffd78d4a1ee)
-   [SetPassthroughMode](#ac4e77085cdcc853de832a2b16b8dc69a)

## **Overview**<a name="section611392098165630"></a>

**Related Modules:**

[Audio](audio.md)

**Description:**

Provides audio adapter capabilities, including initializing ports, creating rendering and capturing tasks, and obtaining the port capability set. 

See also
:   [AudioRender](audiorender.md) 

:    [AudioCapture](audiocapture.md) 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1187227500165630"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table556752954165630"></a>
<table><thead align="left"><tr id="row1806372885165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p714653026165630"><a name="p714653026165630"></a><a name="p714653026165630"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1158360625165630"><a name="p1158360625165630"></a><a name="p1158360625165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1564252577165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1411027941165630"><a name="p1411027941165630"></a><a name="p1411027941165630"></a><a href="audioadapter.md#a3c46c9291d4c08d489454ffd78d4a1ee">InitAllPorts</a> )(struct <a href="audioadapter.md">AudioAdapter</a> *adapter)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p970988503165630"><a name="p970988503165630"></a><a name="p970988503165630"></a>int32_t(* </p>
<p id="p1822593338165630"><a name="p1822593338165630"></a><a name="p1822593338165630"></a>Initializes all ports of an audio adapter. </p>
</td>
</tr>
<tr id="row1034734293165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p893120226165630"><a name="p893120226165630"></a><a name="p893120226165630"></a><a href="audioadapter.md#a284ea2ad18ebac562ca7283652e61b50">CreateRender</a> )(struct <a href="audioadapter.md">AudioAdapter</a> *adapter, const struct <a href="audiodevicedescriptor.md">AudioDeviceDescriptor</a> *desc, const struct <a href="audiosampleattributes.md">AudioSampleAttributes</a> *attrs, struct <a href="audiorender.md">AudioRender</a> **render)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1972825867165630"><a name="p1972825867165630"></a><a name="p1972825867165630"></a>int32_t(* </p>
<p id="p206374907165630"><a name="p206374907165630"></a><a name="p206374907165630"></a>Creates an <strong id="b187922990165630"><a name="b187922990165630"></a><a name="b187922990165630"></a><a href="audiorender.md">AudioRender</a></strong> object. </p>
</td>
</tr>
<tr id="row1130444165165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p315107269165630"><a name="p315107269165630"></a><a name="p315107269165630"></a><a href="audioadapter.md#a070a8d60f88134c58c4439d4419af913">DestroyRender</a> )(struct <a href="audioadapter.md">AudioAdapter</a> *adapter, struct <a href="audiorender.md">AudioRender</a> *render)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1198421315165630"><a name="p1198421315165630"></a><a name="p1198421315165630"></a>int32_t(* </p>
<p id="p438530132165630"><a name="p438530132165630"></a><a name="p438530132165630"></a>Destroys an <strong id="b1204596536165630"><a name="b1204596536165630"></a><a name="b1204596536165630"></a><a href="audiorender.md">AudioRender</a></strong> object. </p>
</td>
</tr>
<tr id="row761766302165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p794060171165630"><a name="p794060171165630"></a><a name="p794060171165630"></a><a href="audioadapter.md#a8a46358cdad8e0a9d15ac079713535f2">CreateCapture</a> )(struct <a href="audioadapter.md">AudioAdapter</a> *adapter, const struct <a href="audiodevicedescriptor.md">AudioDeviceDescriptor</a> *desc, const struct <a href="audiosampleattributes.md">AudioSampleAttributes</a> *attrs, struct <a href="audiocapture.md">AudioCapture</a> **capture)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1554046369165630"><a name="p1554046369165630"></a><a name="p1554046369165630"></a>int32_t(* </p>
<p id="p662329403165630"><a name="p662329403165630"></a><a name="p662329403165630"></a>Creates an <strong id="b834259803165630"><a name="b834259803165630"></a><a name="b834259803165630"></a><a href="audiocapture.md">AudioCapture</a></strong> object. </p>
</td>
</tr>
<tr id="row427122420165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p501794459165630"><a name="p501794459165630"></a><a name="p501794459165630"></a><a href="audioadapter.md#a1175a27c5273dab1acf8f8f3c4967637">DestroyCapture</a> )(struct <a href="audioadapter.md">AudioAdapter</a> *adapter, struct <a href="audiocapture.md">AudioCapture</a> *capture)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1953375209165630"><a name="p1953375209165630"></a><a name="p1953375209165630"></a>int32_t(* </p>
<p id="p106139258165630"><a name="p106139258165630"></a><a name="p106139258165630"></a>Destroys an <strong id="b1795089805165630"><a name="b1795089805165630"></a><a name="b1795089805165630"></a><a href="audiocapture.md">AudioCapture</a></strong> object. </p>
</td>
</tr>
<tr id="row151959319165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1077596707165630"><a name="p1077596707165630"></a><a name="p1077596707165630"></a><a href="audioadapter.md#a525ec7f3f3bb9975790e27f75145d0f6">GetPortCapability</a> )(struct <a href="audioadapter.md">AudioAdapter</a> *adapter, const struct <a href="audioport.md">AudioPort</a> *port, struct <a href="audioportcapability.md">AudioPortCapability</a> *capability)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p205650217165630"><a name="p205650217165630"></a><a name="p205650217165630"></a>int32_t(* </p>
<p id="p857152900165630"><a name="p857152900165630"></a><a name="p857152900165630"></a>Obtains the capability set of the port driver for the audio adapter. </p>
</td>
</tr>
<tr id="row75731391165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p778904594165630"><a name="p778904594165630"></a><a name="p778904594165630"></a><a href="audioadapter.md#ac4e77085cdcc853de832a2b16b8dc69a">SetPassthroughMode</a> )(struct <a href="audioadapter.md">AudioAdapter</a> *adapter, const struct <a href="audioport.md">AudioPort</a> *port, enum <a href="audio.md#ga186d2d4f9a2ecacb80cd2cce2bd26f0e">AudioPortPassthroughMode</a> mode)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p692789056165630"><a name="p692789056165630"></a><a name="p692789056165630"></a>int32_t(* </p>
<p id="p1233543103165630"><a name="p1233543103165630"></a><a name="p1233543103165630"></a>Sets the passthrough data transmission mode of the audio port driver. </p>
</td>
</tr>
<tr id="row1268557467165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1295208374165630"><a name="p1295208374165630"></a><a name="p1295208374165630"></a><a href="audioadapter.md#ad4c41f3193c5ec3da254f33e24241ea6">GetPassthroughMode</a> )(struct <a href="audioadapter.md">AudioAdapter</a> *adapter, const struct <a href="audioport.md">AudioPort</a> *port, enum <a href="audio.md#ga186d2d4f9a2ecacb80cd2cce2bd26f0e">AudioPortPassthroughMode</a> *mode)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p277206106165630"><a name="p277206106165630"></a><a name="p277206106165630"></a>int32_t(* </p>
<p id="p465501831165630"><a name="p465501831165630"></a><a name="p465501831165630"></a>Obtains the passthrough data transmission mode of the audio port driver. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section2025801532165630"></a>

## **Field **<a name="section1769083627165630"></a>

## CreateCapture<a name="a8a46358cdad8e0a9d15ac079713535f2"></a>

```
int32_t(* AudioAdapter::CreateCapture) (struct [AudioAdapter](audioadapter.md) *adapter, const struct [AudioDeviceDescriptor](audiodevicedescriptor.md) *desc, const struct [AudioSampleAttributes](audiosampleattributes.md) *attrs, struct [AudioCapture](audiocapture.md) **capture)
```

 **Description:**

Creates an  **[AudioCapture](audiocapture.md)**  object. 

**Parameters:**

<a name="table2137339143165630"></a>
<table><thead align="left"><tr id="row1094804196165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p997271897165630"><a name="p997271897165630"></a><a name="p997271897165630"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p353799266165630"><a name="p353799266165630"></a><a name="p353799266165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row232059790165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">adapter</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the audio adapter to operate. </td>
</tr>
<tr id="row50564993165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">desc</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the descriptor of the audio adapter to start. </td>
</tr>
<tr id="row2041063878165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">attrs</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the audio sampling attributes to open. </td>
</tr>
<tr id="row1840611241165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">capture</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double pointer to the <strong id="b1649305452165630"><a name="b1649305452165630"></a><a name="b1649305452165630"></a><a href="audiocapture.md">AudioCapture</a></strong> object. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the  **[AudioCapture](audiocapture.md)**  object is created successfully; returns a negative value otherwise. 

**See also:**

[GetPortCapability](audioadapter.md#a525ec7f3f3bb9975790e27f75145d0f6) 

 [DestroyCapture](audioadapter.md#a1175a27c5273dab1acf8f8f3c4967637) 

## CreateRender<a name="a284ea2ad18ebac562ca7283652e61b50"></a>

```
int32_t(* AudioAdapter::CreateRender) (struct [AudioAdapter](audioadapter.md) *adapter, const struct [AudioDeviceDescriptor](audiodevicedescriptor.md) *desc, const struct [AudioSampleAttributes](audiosampleattributes.md) *attrs, struct [AudioRender](audiorender.md) **render)
```

 **Description:**

Creates an  **[AudioRender](audiorender.md)**  object. 

**Parameters:**

<a name="table792995601165630"></a>
<table><thead align="left"><tr id="row10015730165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1343629120165630"><a name="p1343629120165630"></a><a name="p1343629120165630"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2022291874165630"><a name="p2022291874165630"></a><a name="p2022291874165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1439256863165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">adapter</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the audio adapter to operate. </td>
</tr>
<tr id="row1095562649165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">desc</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the descriptor of the audio adapter to start. </td>
</tr>
<tr id="row1675934944165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">attrs</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the audio sampling attributes to open. </td>
</tr>
<tr id="row1708549715165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">render</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double pointer to the <strong id="b1089286258165630"><a name="b1089286258165630"></a><a name="b1089286258165630"></a><a href="audiorender.md">AudioRender</a></strong> object. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the  **[AudioRender](audiorender.md)**  object is created successfully; returns a negative value otherwise. 

**See also:**

[GetPortCapability](audioadapter.md#a525ec7f3f3bb9975790e27f75145d0f6) 

 [DestroyRender](audioadapter.md#a070a8d60f88134c58c4439d4419af913) 

## DestroyCapture<a name="a1175a27c5273dab1acf8f8f3c4967637"></a>

```
int32_t(* AudioAdapter::DestroyCapture) (struct [AudioAdapter](audioadapter.md) *adapter, struct [AudioCapture](audiocapture.md) *capture)
```

 **Description:**

Destroys an  **[AudioCapture](audiocapture.md)**  object. 

**Parameters:**

<a name="table282746375165630"></a>
<table><thead align="left"><tr id="row1315025724165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p240982892165630"><a name="p240982892165630"></a><a name="p240982892165630"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p382784377165630"><a name="p382784377165630"></a><a name="p382784377165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1861983121165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">adapter</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the audio adapter to operate. </td>
</tr>
<tr id="row1074432090165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">capture</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the <strong id="b926614670165630"><a name="b926614670165630"></a><a name="b926614670165630"></a><a href="audiocapture.md">AudioCapture</a></strong> object to operate. </td>
</tr>
</tbody>
</table>

**Attention:**

Do not destroy the object during audio capturing.

**Returns:**

Returns  **0**  if the  **[AudioCapture](audiocapture.md)**  object is destroyed; returns a negative value otherwise. 

**See also:**

[CreateCapture](audioadapter.md#a8a46358cdad8e0a9d15ac079713535f2) 

## DestroyRender<a name="a070a8d60f88134c58c4439d4419af913"></a>

```
int32_t(* AudioAdapter::DestroyRender) (struct [AudioAdapter](audioadapter.md) *adapter, struct [AudioRender](audiorender.md) *render)
```

 **Description:**

Destroys an  **[AudioRender](audiorender.md)**  object. 

**Parameters:**

<a name="table1112008383165630"></a>
<table><thead align="left"><tr id="row1239048110165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p91465375165630"><a name="p91465375165630"></a><a name="p91465375165630"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2060452849165630"><a name="p2060452849165630"></a><a name="p2060452849165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row420520185165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">adapter</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the audio adapter to operate. </td>
</tr>
<tr id="row2103121582165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">render</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the <strong id="b1994643129165630"><a name="b1994643129165630"></a><a name="b1994643129165630"></a><a href="audiorender.md">AudioRender</a></strong> object to operate. </td>
</tr>
</tbody>
</table>

**Attention:**

Do not destroy the object during audio rendering.

**Returns:**

Returns  **0**  if the  **[AudioRender](audiorender.md)**  object is destroyed; returns a negative value otherwise. 

**See also:**

[CreateRender](audioadapter.md#a284ea2ad18ebac562ca7283652e61b50) 

## GetPassthroughMode<a name="ad4c41f3193c5ec3da254f33e24241ea6"></a>

```
int32_t(* AudioAdapter::GetPassthroughMode) (struct [AudioAdapter](audioadapter.md) *adapter, const struct [AudioPort](audioport.md) *port, enum [AudioPortPassthroughMode](audio.md#ga186d2d4f9a2ecacb80cd2cce2bd26f0e) *mode)
```

 **Description:**

Obtains the passthrough data transmission mode of the audio port driver. 

**Parameters:**

<a name="table761188707165630"></a>
<table><thead align="left"><tr id="row1892027097165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p886449390165630"><a name="p886449390165630"></a><a name="p886449390165630"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p725930104165630"><a name="p725930104165630"></a><a name="p725930104165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1822294760165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">adapter</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the audio adapter to operate. </td>
</tr>
<tr id="row95807415165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">port</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the port. </td>
</tr>
<tr id="row1258673458165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">mode</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the passthrough transmission mode to obtain. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the mode is successfully obtained; returns a negative value otherwise. 

**See also:**

[SetPassthroughMode](audioadapter.md#ac4e77085cdcc853de832a2b16b8dc69a) 

## GetPortCapability<a name="a525ec7f3f3bb9975790e27f75145d0f6"></a>

```
int32_t(* AudioAdapter::GetPortCapability) (struct [AudioAdapter](audioadapter.md) *adapter, const struct [AudioPort](audioport.md) *port, struct [AudioPortCapability](audioportcapability.md) *capability)
```

 **Description:**

Obtains the capability set of the port driver for the audio adapter. 

**Parameters:**

<a name="table1561939129165630"></a>
<table><thead align="left"><tr id="row818419923165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1897463462165630"><a name="p1897463462165630"></a><a name="p1897463462165630"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p392404163165630"><a name="p392404163165630"></a><a name="p392404163165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row631601139165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">adapter</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the audio adapter to operate. </td>
</tr>
<tr id="row1030648389165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">port</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the port. </td>
</tr>
<tr id="row1155206115165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">capability</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the capability set to obtain. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the capability set is successfully obtained; returns a negative value otherwise. 

## InitAllPorts<a name="a3c46c9291d4c08d489454ffd78d4a1ee"></a>

```
int32_t(* AudioAdapter::InitAllPorts) (struct [AudioAdapter](audioadapter.md) *adapter)
```

 **Description:**

Initializes all ports of an audio adapter. 

Call this function before calling other driver functions to check whether the initialization is complete. If the initialization is not complete, wait for a while \(for example, 100 ms\) and perform the check again until the port initialization is complete.

**Parameters:**

<a name="table1975409468165630"></a>
<table><thead align="left"><tr id="row25267728165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1925334488165630"><a name="p1925334488165630"></a><a name="p1925334488165630"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p67213894165630"><a name="p67213894165630"></a><a name="p67213894165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row244188438165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">adapter</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the audio adapter to operate. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the initialization is successful; returns a negative value otherwise. 

## SetPassthroughMode<a name="ac4e77085cdcc853de832a2b16b8dc69a"></a>

```
int32_t(* AudioAdapter::SetPassthroughMode) (struct [AudioAdapter](audioadapter.md) *adapter, const struct [AudioPort](audioport.md) *port, enum [AudioPortPassthroughMode](audio.md#ga186d2d4f9a2ecacb80cd2cce2bd26f0e) mode)
```

 **Description:**

Sets the passthrough data transmission mode of the audio port driver. 

**Parameters:**

<a name="table624086282165630"></a>
<table><thead align="left"><tr id="row238948818165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p825021985165630"><a name="p825021985165630"></a><a name="p825021985165630"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1977467480165630"><a name="p1977467480165630"></a><a name="p1977467480165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row758512341165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">adapter</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the audio adapter to operate. </td>
</tr>
<tr id="row1997245497165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">port</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the port. </td>
</tr>
<tr id="row833941611165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">mode</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the passthrough transmission mode to set. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the setting is successful; returns a negative value otherwise. 

**See also:**

[GetPassthroughMode](audioadapter.md#ad4c41f3193c5ec3da254f33e24241ea6) 

