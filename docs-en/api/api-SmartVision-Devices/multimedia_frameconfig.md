# MultiMedia\_FrameConfig<a name="EN-US_TOPIC_0000001055358062"></a>

-   [Overview](#section1826838220165625)
-   [Summary](#section2063584699165625)
-   [Files](#files)
-   [Data Structures](#nested-classes)
-   [Functions](#func-members)
-   [Details](#section562581684165625)
-   [Function](#section1303191587165625)
-   [AddSurface\(\)](#ga16760311713db03bf06ea0a6d6622013)
-   [FrameConfig\(\) \[1/2\]](#ga043537d52f5db46d981f9e89848b0fba)
-   [FrameConfig\(\) \[2/2\]](#gac8f74ff3689605a59a17997bdeaec1fc)
-   [GetFrameConfigType\(\)](#ga382977445a583ed0424c5ccf581e824c)
-   [GetParameter\(\)](#ga05147491c6e25df54d75d5ed0c201d65)
-   [GetSurfaces\(\)](#ga955d04df96c009e4699ea6ed46d9e758)
-   [RemoveSurface\(\)](#ga9ac4bc5e52840ee579482a3836774762)
-   [SetParameter\(\)](#ga6b4ee39d1c1bf219e4a84df470f6007a)
-   [\~FrameConfig\(\)](#gaa2e58c2ce602d9263b76596374823616)

## **Overview**<a name="section1826838220165625"></a>

**Description:**

Defines the  **FrameConfig**  class for operations related to frame configurations. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section2063584699165625"></a>

## Files<a name="files"></a>

<a name="table1001483506165625"></a>
<table><thead align="left"><tr id="row1127866165165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1110105892165625"><a name="p1110105892165625"></a><a name="p1110105892165625"></a>File Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1491707007165625"><a name="p1491707007165625"></a><a name="p1491707007165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row738934853165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p31403055165625"><a name="p31403055165625"></a><a name="p31403055165625"></a><a href="frame_config-h.md">frame_config.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1443041818165625"><a name="p1443041818165625"></a><a name="p1443041818165625"></a>Declares APIs of the <strong id="b1539263610165625"><a name="b1539263610165625"></a><a name="b1539263610165625"></a>FrameConfig</strong> class. </p>
</td>
</tr>
</tbody>
</table>

## Data Structures<a name="nested-classes"></a>

<a name="table1971802229165625"></a>
<table><thead align="left"><tr id="row574830850165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1841486247165625"><a name="p1841486247165625"></a><a name="p1841486247165625"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1377247249165625"><a name="p1377247249165625"></a><a name="p1377247249165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row386821398165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1267097769165625"><a name="p1267097769165625"></a><a name="p1267097769165625"></a><a href="ohos-media-frameconfig.md">OHOS::Media::FrameConfig</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1297408991165625"><a name="p1297408991165625"></a><a name="p1297408991165625"></a>Provides functions to configure frames. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table2098592745165625"></a>
<table><thead align="left"><tr id="row296268224165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p906717823165625"><a name="p906717823165625"></a><a name="p906717823165625"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1325645866165625"><a name="p1325645866165625"></a><a name="p1325645866165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1658047745165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p566083981165625"><a name="p566083981165625"></a><a name="p566083981165625"></a><a href="multimedia_frameconfig.md#ga043537d52f5db46d981f9e89848b0fba">OHOS::Media::FrameConfig::FrameConfig</a> ()=delete</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p398558154165625"><a name="p398558154165625"></a><a name="p398558154165625"></a> </p>
<p id="p1355783015165625"><a name="p1355783015165625"></a><a name="p1355783015165625"></a>A constructor used to create a <strong id="b1610271946165625"><a name="b1610271946165625"></a><a name="b1610271946165625"></a><a href="ohos-media-frameconfig.md">FrameConfig</a></strong> instance. </p>
</td>
</tr>
<tr id="row1496878191165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p806949071165625"><a name="p806949071165625"></a><a name="p806949071165625"></a><a href="multimedia_frameconfig.md#gac8f74ff3689605a59a17997bdeaec1fc">OHOS::Media::FrameConfig::FrameConfig</a> (int32_t type)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1941745805165625"><a name="p1941745805165625"></a><a name="p1941745805165625"></a> </p>
<p id="p1523632036165625"><a name="p1523632036165625"></a><a name="p1523632036165625"></a>A constructor used to create a <strong id="b1229169710165625"><a name="b1229169710165625"></a><a name="b1229169710165625"></a><a href="ohos-media-frameconfig.md">FrameConfig</a></strong> instance based on the configuration mode. </p>
</td>
</tr>
<tr id="row706550708165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2117950222165625"><a name="p2117950222165625"></a><a name="p2117950222165625"></a><a href="multimedia_frameconfig.md#gaa2e58c2ce602d9263b76596374823616">OHOS::Media::FrameConfig::~FrameConfig</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1817647380165625"><a name="p1817647380165625"></a><a name="p1817647380165625"></a> </p>
<p id="p412211749165625"><a name="p412211749165625"></a><a name="p412211749165625"></a>A destructor used to delete the <strong id="b579138232165625"><a name="b579138232165625"></a><a name="b579138232165625"></a><a href="ohos-media-frameconfig.md">FrameConfig</a></strong> instance. </p>
</td>
</tr>
<tr id="row932379979165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p341662348165625"><a name="p341662348165625"></a><a name="p341662348165625"></a><a href="multimedia_frameconfig.md#ga382977445a583ed0424c5ccf581e824c">OHOS::Media::FrameConfig::GetFrameConfigType</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1177385601165625"><a name="p1177385601165625"></a><a name="p1177385601165625"></a>int32_t </p>
<p id="p1468355315165625"><a name="p1468355315165625"></a><a name="p1468355315165625"></a>Obtains the frame configuration type. </p>
</td>
</tr>
<tr id="row6591970165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1767721014165625"><a name="p1767721014165625"></a><a name="p1767721014165625"></a><a href="multimedia_frameconfig.md#ga955d04df96c009e4699ea6ed46d9e758">OHOS::Media::FrameConfig::GetSurfaces</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1336074055165625"><a name="p1336074055165625"></a><a name="p1336074055165625"></a>std::list&lt; <a href="ohos-surface.md">Surface</a> * &gt; </p>
<p id="p234473821165625"><a name="p234473821165625"></a><a name="p234473821165625"></a>Obtains a list of shared memories (surface objects). </p>
</td>
</tr>
<tr id="row675166114165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p621865556165625"><a name="p621865556165625"></a><a name="p621865556165625"></a><a href="multimedia_frameconfig.md#ga16760311713db03bf06ea0a6d6622013">OHOS::Media::FrameConfig::AddSurface</a> (<a href="ohos-surface.md">Surface</a> &amp;surface)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1467379152165625"><a name="p1467379152165625"></a><a name="p1467379152165625"></a>void </p>
<p id="p1574130228165625"><a name="p1574130228165625"></a><a name="p1574130228165625"></a>Adds a surface (an object of shared memory). </p>
</td>
</tr>
<tr id="row2146065240165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p947872276165625"><a name="p947872276165625"></a><a name="p947872276165625"></a><a href="multimedia_frameconfig.md#ga9ac4bc5e52840ee579482a3836774762">OHOS::Media::FrameConfig::RemoveSurface</a> (<a href="ohos-surface.md">Surface</a> &amp;surface)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1071281368165625"><a name="p1071281368165625"></a><a name="p1071281368165625"></a>void </p>
<p id="p807302450165625"><a name="p807302450165625"></a><a name="p807302450165625"></a>Removes a surface (an object of shared memory). You can call this function to release the surface when your application does not need to obtain data. </p>
</td>
</tr>
<tr id="row2042438453165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1704136924165625"><a name="p1704136924165625"></a><a name="p1704136924165625"></a><a href="multimedia_frameconfig.md#ga6b4ee39d1c1bf219e4a84df470f6007a">OHOS::Media::FrameConfig::SetParameter</a> (uint32_t key, const T value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p778638255165625"><a name="p778638255165625"></a><a name="p778638255165625"></a>template&lt;typename T &gt; void </p>
<p id="p1345107024165625"><a name="p1345107024165625"></a><a name="p1345107024165625"></a>Sets the common parameter. </p>
</td>
</tr>
<tr id="row584550147165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1485223143165625"><a name="p1485223143165625"></a><a name="p1485223143165625"></a><a href="multimedia_frameconfig.md#ga05147491c6e25df54d75d5ed0c201d65">OHOS::Media::FrameConfig::GetParameter</a> (uint32_t key, T &amp;value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p569170455165625"><a name="p569170455165625"></a><a name="p569170455165625"></a>template&lt;typename T &gt; void </p>
<p id="p475377562165625"><a name="p475377562165625"></a><a name="p475377562165625"></a>Obtains the value of a common parameter based on its key. For details, see <strong id="b32488407165625"><a name="b32488407165625"></a><a name="b32488407165625"></a>CAMERA_FUC_KEY</strong>. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section562581684165625"></a>

## **Function **<a name="section1303191587165625"></a>

## AddSurface\(\)<a name="ga16760311713db03bf06ea0a6d6622013"></a>

```
void OHOS::Media::FrameConfig::AddSurface ([Surface](ohos-surface.md) & surface)
```

 **Description:**

Adds a surface \(an object of shared memory\). 

**Parameters:**

<a name="table1865409677165625"></a>
<table><thead align="left"><tr id="row517987071165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p633770495165625"><a name="p633770495165625"></a><a name="p633770495165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p120934734165625"><a name="p120934734165625"></a><a name="p120934734165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row934912128165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">surface</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the surface to add. </td>
</tr>
</tbody>
</table>

## FrameConfig\(\) \[1/2\]<a name="ga043537d52f5db46d981f9e89848b0fba"></a>

```
OHOS::Media::FrameConfig::FrameConfig ()
```

 **Description:**

A constructor used to create a  **[FrameConfig](ohos-media-frameconfig.md)**  instance. 

## FrameConfig\(\) \[2/2\]<a name="gac8f74ff3689605a59a17997bdeaec1fc"></a>

```
OHOS::Media::FrameConfig::FrameConfig (int32_t type)
```

 **Description:**

A constructor used to create a  **[FrameConfig](ohos-media-frameconfig.md)**  instance based on the configuration mode. 

**Parameters:**

<a name="table949883997165625"></a>
<table><thead align="left"><tr id="row1010687324165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p369330865165625"><a name="p369330865165625"></a><a name="p369330865165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1686060775165625"><a name="p1686060775165625"></a><a name="p1686060775165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row330332720165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">type</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the frame configuration mode, which can be <strong id="b1685955216165625"><a name="b1685955216165625"></a><a name="b1685955216165625"></a>FRAME_CONFIG_PREVIEW</strong>, &lt;b&gt;FRAME_CONFIG_RECORD, or <strong id="b471292757165625"><a name="b471292757165625"></a><a name="b471292757165625"></a>FRAME_CONFIG_CAPTURE</strong>. </td>
</tr>
</tbody>
</table>

## GetFrameConfigType\(\)<a name="ga382977445a583ed0424c5ccf581e824c"></a>

```
int32_t OHOS::Media::FrameConfig::GetFrameConfigType ()
```

 **Description:**

Obtains the frame configuration type. 

**Returns:**

Returns the frame configuration type if obtained; returns  **-1**  otherwise. 

## GetParameter\(\)<a name="ga05147491c6e25df54d75d5ed0c201d65"></a>

```
void OHOS::Media::FrameConfig::GetParameter (uint32_t key, T & value )
```

 **Description:**

Obtains the value of a common parameter based on its key. For details, see  **CAMERA\_FUC\_KEY**. 

**Parameters:**

<a name="table651029366165625"></a>
<table><thead align="left"><tr id="row880814238165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1065065460165625"><a name="p1065065460165625"></a><a name="p1065065460165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p242219357165625"><a name="p242219357165625"></a><a name="p242219357165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1350161147165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">key</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the common parameter key. </td>
</tr>
</tbody>
</table>

## GetSurfaces\(\)<a name="ga955d04df96c009e4699ea6ed46d9e758"></a>

```
std::list<[Surface](ohos-surface.md) *> OHOS::Media::FrameConfig::GetSurfaces ()
```

 **Description:**

Obtains a list of shared memories \(surface objects\). 

**Returns:**

Returns the list of shared memories if obtained; returns  **NULL**  otherwise. 

## RemoveSurface\(\)<a name="ga9ac4bc5e52840ee579482a3836774762"></a>

```
void OHOS::Media::FrameConfig::RemoveSurface ([Surface](ohos-surface.md) & surface)
```

 **Description:**

Removes a surface \(an object of shared memory\). You can call this function to release the surface when your application does not need to obtain data. 

**Parameters:**

<a name="table907351372165625"></a>
<table><thead align="left"><tr id="row467090732165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p537701159165625"><a name="p537701159165625"></a><a name="p537701159165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p696906112165625"><a name="p696906112165625"></a><a name="p696906112165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row770629631165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">surface</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the surface to remove. </td>
</tr>
</tbody>
</table>

## SetParameter\(\)<a name="ga6b4ee39d1c1bf219e4a84df470f6007a"></a>

```
void OHOS::Media::FrameConfig::SetParameter (uint32_t key, const T value )
```

 **Description:**

Sets the common parameter. 

**Parameters:**

<a name="table2020429200165625"></a>
<table><thead align="left"><tr id="row962113405165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p995064599165625"><a name="p995064599165625"></a><a name="p995064599165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p77302065165625"><a name="p77302065165625"></a><a name="p77302065165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1125715368165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">key</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the common parameter key to set. </td>
</tr>
<tr id="row1850454250165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">value</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the common parameter value to set. </td>
</tr>
</tbody>
</table>

## \~FrameConfig\(\)<a name="gaa2e58c2ce602d9263b76596374823616"></a>

```
OHOS::Media::FrameConfig::~FrameConfig ()
```

 **Description:**

A destructor used to delete the  **[FrameConfig](ohos-media-frameconfig.md)**  instance. 

