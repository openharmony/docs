# MultiMedia\_CameraConfig<a name="EN-US_TOPIC_0000001054879486"></a>

-   [Overview](#section1789785181165625)
-   [Summary](#section287889359165625)
-   [Files](#files)
-   [Data Structures](#nested-classes)
-   [Functions](#func-members)
-   [Details](#section738387907165625)
-   [Function](#section32055410165625)
-   [CameraConfig\(\)](#ga6cca70f5dea34d6ede94d0b258c0a350)
-   [CreateCameraConfig\(\)](#ga26f37610abb783b48d3e94662523fa94)
-   [GetEventHandler\(\)](#ga65d8bb0bd5d996e51e4c6fa12a33931b)
-   [GetFrameStateCb\(\)](#gae4864312836d34b9ad56675ed3e523a1)
-   [SetFrameStateCallback\(\)](#gaf6d7f82e9439dce13b0213f84a35ab59)
-   [\~CameraConfig\(\)](#ga6730b1ff3808a97fe7095c1cd016d47c)

## **Overview**<a name="section1789785181165625"></a>

**Description:**

Defines the  **CameraConfig**  class for operations on camera configurations. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section287889359165625"></a>

## Files<a name="files"></a>

<a name="table2080315270165625"></a>
<table><thead align="left"><tr id="row622582917165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p833504956165625"><a name="p833504956165625"></a><a name="p833504956165625"></a>File Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1973724045165625"><a name="p1973724045165625"></a><a name="p1973724045165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1842750059165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1863397019165625"><a name="p1863397019165625"></a><a name="p1863397019165625"></a><a href="camera_config-h.md">camera_config.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p42197520165625"><a name="p42197520165625"></a><a name="p42197520165625"></a>Declares functions in the <strong id="b319047637165625"><a name="b319047637165625"></a><a name="b319047637165625"></a>CameraConfig</strong> class. </p>
</td>
</tr>
</tbody>
</table>

## Data Structures<a name="nested-classes"></a>

<a name="table1436272011165625"></a>
<table><thead align="left"><tr id="row1380581474165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2094073172165625"><a name="p2094073172165625"></a><a name="p2094073172165625"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1495218585165625"><a name="p1495218585165625"></a><a name="p1495218585165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1975050357165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2065109100165625"><a name="p2065109100165625"></a><a name="p2065109100165625"></a><a href="ohos-media-cameraconfig.md">OHOS::Media::CameraConfig</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p532481404165625"><a name="p532481404165625"></a><a name="p532481404165625"></a>Provides functions to configure camera parameters. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table1586417044165625"></a>
<table><thead align="left"><tr id="row1578935059165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1507831146165625"><a name="p1507831146165625"></a><a name="p1507831146165625"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p234532090165625"><a name="p234532090165625"></a><a name="p234532090165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1796244668165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1298646676165625"><a name="p1298646676165625"></a><a name="p1298646676165625"></a><a href="multimedia_cameraconfig.md#ga6730b1ff3808a97fe7095c1cd016d47c">OHOS::Media::CameraConfig::~CameraConfig</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1856792463165625"><a name="p1856792463165625"></a><a name="p1856792463165625"></a>virtual </p>
<p id="p188186992165625"><a name="p188186992165625"></a><a name="p188186992165625"></a>A destructor used to delete the <strong id="b661047619165625"><a name="b661047619165625"></a><a name="b661047619165625"></a><a href="ohos-media-cameraability.md">CameraAbility</a></strong> instance. </p>
</td>
</tr>
<tr id="row737668566165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1157890860165625"><a name="p1157890860165625"></a><a name="p1157890860165625"></a><a href="multimedia_cameraconfig.md#ga26f37610abb783b48d3e94662523fa94">OHOS::Media::CameraConfig::CreateCameraConfig</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p11357549165625"><a name="p11357549165625"></a><a name="p11357549165625"></a>static <a href="ohos-media-cameraconfig.md">CameraConfig</a> * </p>
<p id="p1611610328165625"><a name="p1611610328165625"></a><a name="p1611610328165625"></a>Creates the <strong id="b1357519026165625"><a name="b1357519026165625"></a><a name="b1357519026165625"></a><a href="ohos-media-cameraconfig.md">CameraConfig</a></strong> instance of this singleton class to configure and read the required parameters. </p>
</td>
</tr>
<tr id="row89865462165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p491577368165625"><a name="p491577368165625"></a><a name="p491577368165625"></a><a href="multimedia_cameraconfig.md#gaf6d7f82e9439dce13b0213f84a35ab59">OHOS::Media::CameraConfig::SetFrameStateCallback</a> (<a href="ohos-media-framestatecallback.md">FrameStateCallback</a> *callback, EventHandler *handler)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1920711853165625"><a name="p1920711853165625"></a><a name="p1920711853165625"></a>virtual void </p>
<p id="p562887237165625"><a name="p562887237165625"></a><a name="p562887237165625"></a>Sets a frame state callback to responds to state changes. </p>
</td>
</tr>
<tr id="row1997753874165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1755341581165625"><a name="p1755341581165625"></a><a name="p1755341581165625"></a><a href="multimedia_cameraconfig.md#ga65d8bb0bd5d996e51e4c6fa12a33931b">OHOS::Media::CameraConfig::GetEventHandler</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1710250902165625"><a name="p1710250902165625"></a><a name="p1710250902165625"></a>virtual EventHandler * </p>
<p id="p395239431165625"><a name="p395239431165625"></a><a name="p395239431165625"></a>Obtains the <strong id="b1189419059165625"><a name="b1189419059165625"></a><a name="b1189419059165625"></a>EventHandler</strong> object. </p>
</td>
</tr>
<tr id="row510329348165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1692640142165625"><a name="p1692640142165625"></a><a name="p1692640142165625"></a><a href="multimedia_cameraconfig.md#gae4864312836d34b9ad56675ed3e523a1">OHOS::Media::CameraConfig::GetFrameStateCb</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1356117966165625"><a name="p1356117966165625"></a><a name="p1356117966165625"></a>virtual <a href="ohos-media-framestatecallback.md">FrameStateCallback</a> * </p>
<p id="p512471081165625"><a name="p512471081165625"></a><a name="p512471081165625"></a>Obtains a <strong id="b252101486165625"><a name="b252101486165625"></a><a name="b252101486165625"></a><a href="ohos-media-framestatecallback.md">FrameStateCallback</a></strong> object. </p>
</td>
</tr>
<tr id="row3684760165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p212104922165625"><a name="p212104922165625"></a><a name="p212104922165625"></a><a href="multimedia_cameraconfig.md#ga6cca70f5dea34d6ede94d0b258c0a350">OHOS::Media::CameraConfig::CameraConfig</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1778476197165625"><a name="p1778476197165625"></a><a name="p1778476197165625"></a> </p>
<p id="p762028258165625"><a name="p762028258165625"></a><a name="p762028258165625"></a>A constructor used to create a <strong id="b1125766743165625"><a name="b1125766743165625"></a><a name="b1125766743165625"></a><a href="ohos-media-cameraconfig.md">CameraConfig</a></strong> instance. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section738387907165625"></a>

## **Function **<a name="section32055410165625"></a>

## CameraConfig\(\)<a name="ga6cca70f5dea34d6ede94d0b258c0a350"></a>

```
OHOS::Media::CameraConfig::CameraConfig ()
```

 **Description:**

A constructor used to create a  **[CameraConfig](ohos-media-cameraconfig.md)**  instance. 

## CreateCameraConfig\(\)<a name="ga26f37610abb783b48d3e94662523fa94"></a>

```
static [CameraConfig](ohos-media-cameraconfig.md)* OHOS::Media::CameraConfig::CreateCameraConfig ()
```

 **Description:**

Creates the  **[CameraConfig](ohos-media-cameraconfig.md)**  instance of this singleton class to configure and read the required parameters. 

**Returns:**

Returns the  **[CameraConfig](ohos-media-cameraconfig.md)**  instance if created; returns  **NULL**  otherwise. 

## GetEventHandler\(\)<a name="ga65d8bb0bd5d996e51e4c6fa12a33931b"></a>

```
virtual EventHandler* OHOS::Media::CameraConfig::GetEventHandler () const
```

 **Description:**

Obtains the  **EventHandler**  object. 

**Returns:**

Returns the pointer to the  **EventHandler**  object if obtained; returns  **NULL**  otherwise. 

## GetFrameStateCb\(\)<a name="gae4864312836d34b9ad56675ed3e523a1"></a>

```
virtual [FrameStateCallback](ohos-media-framestatecallback.md)* OHOS::Media::CameraConfig::GetFrameStateCb () const
```

 **Description:**

Obtains a  **[FrameStateCallback](ohos-media-framestatecallback.md)**  object. 

**Returns:**

Returns the pointer to the  **[FrameStateCallback](ohos-media-framestatecallback.md)**  object if obtained; returns  **NULL**  otherwise. 

## SetFrameStateCallback\(\)<a name="gaf6d7f82e9439dce13b0213f84a35ab59"></a>

```
virtual void OHOS::Media::CameraConfig::SetFrameStateCallback ([FrameStateCallback](ohos-media-framestatecallback.md) * callback, EventHandler * handler )
```

 **Description:**

Sets a frame state callback to responds to state changes. 

**Parameters:**

<a name="table178165036165625"></a>
<table><thead align="left"><tr id="row1733964190165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1490591727165625"><a name="p1490591727165625"></a><a name="p1490591727165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1844905525165625"><a name="p1844905525165625"></a><a name="p1844905525165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1204580429165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">callback</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the frame state callback. </td>
</tr>
<tr id="row1991645144165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handler</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the event handler. </td>
</tr>
</tbody>
</table>

## \~CameraConfig\(\)<a name="ga6730b1ff3808a97fe7095c1cd016d47c"></a>

```
virtual OHOS::Media::CameraConfig::~CameraConfig ()
```

 **Description:**

A destructor used to delete the  **[CameraAbility](ohos-media-cameraability.md)**  instance. 

