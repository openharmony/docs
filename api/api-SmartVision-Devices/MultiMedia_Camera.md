# MultiMedia\_Camera<a name="ZH-CN_TOPIC_0000001055039470"></a>

-   [Overview](#section1860299487165625)
-   [Summary](#section982156197165625)
-   [Files](#files)
-   [Data Structures](#nested-classes)
-   [Functions](#func-members)
-   [Details](#section461139492165625)
-   [Function](#section1840478202165625)
-   [Camera\(\)](#ga7df4eba3316a6fe7c623e420c0a295e5)
-   [Configure\(\)](#ga5f240a74fefa168cbf94b4603b76ef7b)
-   [GetCameraConfig\(\)](#ga04cc021b827824d0363037b630326264)
-   [GetCameraId\(\)](#ga4b6fec3c9290e7d388147dcdd288b918)
-   [GetFrameConfig\(\)](#ga4e3f97ac484b85cd221a996689a3de61)
-   [Release\(\)](#ga7986d17e54fe9cd77df9465287fa5643)
-   [StopLoopingCapture\(\)](#ga564c26b845affb1dbe05d4d7982ed1ad)
-   [TriggerLoopingCapture\(\)](#ga1cd68b1b385da5224dbfdb6993c5cf08)
-   [TriggerSingleCapture\(\)](#gac05d783b1655fe505a4afa23496d7e84)
-   [\~Camera\(\)](#gab24c0e4ca1e15bb2a481fb1550955611)

## **Overview**<a name="section1860299487165625"></a>

**Description:**

Defines the  **Camera**  class for camera-related operations. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section982156197165625"></a>

## Files<a name="files"></a>

<a name="table622392796165625"></a>
<table><thead align="left"><tr id="row375810231165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2083253357165625"><a name="p2083253357165625"></a><a name="p2083253357165625"></a>File Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1422062246165625"><a name="p1422062246165625"></a><a name="p1422062246165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1702664793165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p408486916165625"><a name="p408486916165625"></a><a name="p408486916165625"></a><a href="camera-h.md">camera.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p714391676165625"><a name="p714391676165625"></a><a name="p714391676165625"></a>Declares functions in the <strong id="b1413002954165625"><a name="b1413002954165625"></a><a name="b1413002954165625"></a>Camera</strong> class to implement camera operations. </p>
</td>
</tr>
</tbody>
</table>

## Data Structures<a name="nested-classes"></a>

<a name="table1990628432165625"></a>
<table><thead align="left"><tr id="row850634626165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p692638728165625"><a name="p692638728165625"></a><a name="p692638728165625"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1631411477165625"><a name="p1631411477165625"></a><a name="p1631411477165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row553074601165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1956742353165625"><a name="p1956742353165625"></a><a name="p1956742353165625"></a><a href="OHOS-Media-Camera.md">OHOS::Media::Camera</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p656736905165625"><a name="p656736905165625"></a><a name="p656736905165625"></a>Provides functions in the <strong id="b629085735165625"><a name="b629085735165625"></a><a name="b629085735165625"></a><a href="OHOS-Media-Camera.md">Camera</a></strong> class to implement camera operations. operations. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table1614308358165625"></a>
<table><thead align="left"><tr id="row437548284165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2096648240165625"><a name="p2096648240165625"></a><a name="p2096648240165625"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p436817040165625"><a name="p436817040165625"></a><a name="p436817040165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1282565800165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1340300460165625"><a name="p1340300460165625"></a><a name="p1340300460165625"></a><a href="MultiMedia_Camera.md#gab24c0e4ca1e15bb2a481fb1550955611">OHOS::Media::Camera::~Camera</a> ()=default</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p156805891165625"><a name="p156805891165625"></a><a name="p156805891165625"></a>virtual </p>
<p id="p506909749165625"><a name="p506909749165625"></a><a name="p506909749165625"></a>A destructor used to delete the <strong id="b531311302165625"><a name="b531311302165625"></a><a name="b531311302165625"></a><a href="OHOS-Media-Camera.md">Camera</a></strong> instance. </p>
</td>
</tr>
<tr id="row1415519772165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p62443148165625"><a name="p62443148165625"></a><a name="p62443148165625"></a><a href="MultiMedia_Camera.md#ga4b6fec3c9290e7d388147dcdd288b918">OHOS::Media::Camera::GetCameraId</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p434130203165625"><a name="p434130203165625"></a><a name="p434130203165625"></a>virtual std::string </p>
<p id="p538236817165625"><a name="p538236817165625"></a><a name="p538236817165625"></a>Obtains the camera ID. </p>
</td>
</tr>
<tr id="row602915590165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1837518505165625"><a name="p1837518505165625"></a><a name="p1837518505165625"></a><a href="MultiMedia_Camera.md#ga04cc021b827824d0363037b630326264">OHOS::Media::Camera::GetCameraConfig</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1824575174165625"><a name="p1824575174165625"></a><a name="p1824575174165625"></a>virtual const <a href="OHOS-Media-CameraConfig.md">CameraConfig</a> * </p>
<p id="p186547890165625"><a name="p186547890165625"></a><a name="p186547890165625"></a>Obtains the camera configuration. You can use the obtained <strong id="b1944586074165625"><a name="b1944586074165625"></a><a name="b1944586074165625"></a><a href="OHOS-Media-CameraConfig.md">CameraConfig</a></strong> object to configure the camera. </p>
</td>
</tr>
<tr id="row1540432200165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p994703505165625"><a name="p994703505165625"></a><a name="p994703505165625"></a><a href="MultiMedia_Camera.md#ga4e3f97ac484b85cd221a996689a3de61">OHOS::Media::Camera::GetFrameConfig</a> (int32_t type)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1667113652165625"><a name="p1667113652165625"></a><a name="p1667113652165625"></a>virtual <a href="OHOS-Media-FrameConfig.md">FrameConfig</a> * </p>
<p id="p484291398165625"><a name="p484291398165625"></a><a name="p484291398165625"></a>Obtains the frame configuration. </p>
</td>
</tr>
<tr id="row797387234165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p997291732165625"><a name="p997291732165625"></a><a name="p997291732165625"></a><a href="MultiMedia_Camera.md#ga5f240a74fefa168cbf94b4603b76ef7b">OHOS::Media::Camera::Configure</a> (<a href="OHOS-Media-CameraConfig.md">CameraConfig</a> &amp;config)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p475727077165625"><a name="p475727077165625"></a><a name="p475727077165625"></a>virtual void </p>
<p id="p522304062165625"><a name="p522304062165625"></a><a name="p522304062165625"></a>Configures the camera using the <strong id="b1509204726165625"><a name="b1509204726165625"></a><a name="b1509204726165625"></a><a href="OHOS-Media-CameraConfig.md">CameraConfig</a></strong> object. </p>
</td>
</tr>
<tr id="row506773013165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p428408050165625"><a name="p428408050165625"></a><a name="p428408050165625"></a><a href="MultiMedia_Camera.md#ga1cd68b1b385da5224dbfdb6993c5cf08">OHOS::Media::Camera::TriggerLoopingCapture</a> (<a href="OHOS-Media-FrameConfig.md">FrameConfig</a> &amp;frameConfig)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1654451902165625"><a name="p1654451902165625"></a><a name="p1654451902165625"></a>virtual int32_t </p>
<p id="p1292580319165625"><a name="p1292580319165625"></a><a name="p1292580319165625"></a>Triggers looping-frame capture. </p>
</td>
</tr>
<tr id="row1922955038165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1348961266165625"><a name="p1348961266165625"></a><a name="p1348961266165625"></a><a href="MultiMedia_Camera.md#ga564c26b845affb1dbe05d4d7982ed1ad">OHOS::Media::Camera::StopLoopingCapture</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1514182528165625"><a name="p1514182528165625"></a><a name="p1514182528165625"></a>virtual void </p>
<p id="p1581185151165625"><a name="p1581185151165625"></a><a name="p1581185151165625"></a>Stops looping-frame capture. </p>
</td>
</tr>
<tr id="row1622525672165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p711396424165625"><a name="p711396424165625"></a><a name="p711396424165625"></a><a href="MultiMedia_Camera.md#gac05d783b1655fe505a4afa23496d7e84">OHOS::Media::Camera::TriggerSingleCapture</a> (<a href="OHOS-Media-FrameConfig.md">FrameConfig</a> &amp;frameConfig)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p945732199165625"><a name="p945732199165625"></a><a name="p945732199165625"></a>virtual int32_t </p>
<p id="p946557133165625"><a name="p946557133165625"></a><a name="p946557133165625"></a>Starts single-frame capture. The frame parameters are set through the <strong id="b1279063106165625"><a name="b1279063106165625"></a><a name="b1279063106165625"></a><a href="OHOS-Media-FrameConfig.md">FrameConfig</a></strong> object, and the captured image data is stored in the surface of the <strong id="b29358561165625"><a name="b29358561165625"></a><a name="b29358561165625"></a><a href="OHOS-Media-FrameConfig.md">FrameConfig</a></strong> object. </p>
</td>
</tr>
<tr id="row493308694165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1029535781165625"><a name="p1029535781165625"></a><a name="p1029535781165625"></a><a href="MultiMedia_Camera.md#ga7986d17e54fe9cd77df9465287fa5643">OHOS::Media::Camera::Release</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p190768284165625"><a name="p190768284165625"></a><a name="p190768284165625"></a>virtual void </p>
<p id="p851229369165625"><a name="p851229369165625"></a><a name="p851229369165625"></a>Releases the <strong id="b1469530350165625"><a name="b1469530350165625"></a><a name="b1469530350165625"></a><a href="OHOS-Media-Camera.md">Camera</a></strong> object and associated resources. </p>
</td>
</tr>
<tr id="row1178766037165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1641780691165625"><a name="p1641780691165625"></a><a name="p1641780691165625"></a><a href="MultiMedia_Camera.md#ga7df4eba3316a6fe7c623e420c0a295e5">OHOS::Media::Camera::Camera</a> ()=default</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1956740094165625"><a name="p1956740094165625"></a><a name="p1956740094165625"></a> </p>
<p id="p379551720165625"><a name="p379551720165625"></a><a name="p379551720165625"></a>A constructor used to create a <strong id="b1306779822165625"><a name="b1306779822165625"></a><a name="b1306779822165625"></a><a href="OHOS-Media-Camera.md">Camera</a></strong> instance. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section461139492165625"></a>

## **Function **<a name="section1840478202165625"></a>

## Camera\(\)<a name="ga7df4eba3316a6fe7c623e420c0a295e5"></a>

```
OHOS::Media::Camera::Camera ()
```

 **Description:**

A constructor used to create a  **[Camera](OHOS-Media-Camera.md)**  instance. 

## Configure\(\)<a name="ga5f240a74fefa168cbf94b4603b76ef7b"></a>

```
virtual void OHOS::Media::Camera::Configure ([CameraConfig](OHOS-Media-CameraConfig.md) & config)
```

 **Description:**

Configures the camera using the  **[CameraConfig](OHOS-Media-CameraConfig.md)**  object. 

**Parameters:**

<a name="table617465200165625"></a>
<table><thead align="left"><tr id="row1021269379165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p906807140165625"><a name="p906807140165625"></a><a name="p906807140165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1253297552165625"><a name="p1253297552165625"></a><a name="p1253297552165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1973188868165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">config</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the <strong id="b475331818165625"><a name="b475331818165625"></a><a name="b475331818165625"></a><a href="OHOS-Media-CameraConfig.md">CameraConfig</a></strong> object. </td>
</tr>
</tbody>
</table>

## GetCameraConfig\(\)<a name="ga04cc021b827824d0363037b630326264"></a>

```
virtual const [CameraConfig](OHOS-Media-CameraConfig.md)* OHOS::Media::Camera::GetCameraConfig () const
```

 **Description:**

Obtains the camera configuration. You can use the obtained  **[CameraConfig](OHOS-Media-CameraConfig.md)**  object to configure the camera. 

**Returns:**

Returns the pointer to the  **[CameraConfig](OHOS-Media-CameraConfig.md)**  object if obtained; returns  **NULL**  otherwise. 

## GetCameraId\(\)<a name="ga4b6fec3c9290e7d388147dcdd288b918"></a>

```
virtual std::string OHOS::Media::Camera::GetCameraId ()
```

 **Description:**

Obtains the camera ID. 

**Returns:**

Returns the camera ID if obtained; returns the "Error" string if the camera fails to be created. 

## GetFrameConfig\(\)<a name="ga4e3f97ac484b85cd221a996689a3de61"></a>

```
virtual [FrameConfig](OHOS-Media-FrameConfig.md)* OHOS::Media::Camera::GetFrameConfig (int32_t type)
```

 **Description:**

Obtains the frame configuration. 

**Parameters:**

<a name="table785343801165625"></a>
<table><thead align="left"><tr id="row1236055961165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1714757837165625"><a name="p1714757837165625"></a><a name="p1714757837165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p465005964165625"><a name="p465005964165625"></a><a name="p465005964165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row453369739165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">type</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the type of the frame configuration. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the pointer to the  **[FrameConfig](OHOS-Media-FrameConfig.md)**  object if obtained; returns  **NULL**  otherwise. 

## Release\(\)<a name="ga7986d17e54fe9cd77df9465287fa5643"></a>

```
virtual void OHOS::Media::Camera::Release ()
```

 **Description:**

Releases the  **[Camera](OHOS-Media-Camera.md)**  object and associated resources. 

## StopLoopingCapture\(\)<a name="ga564c26b845affb1dbe05d4d7982ed1ad"></a>

```
virtual void OHOS::Media::Camera::StopLoopingCapture ()
```

 **Description:**

Stops looping-frame capture. 

**Returns:**

Returns  **true**  if the looping-frame capture is successfully stopped; returns  **false**  otherwise. 

## TriggerLoopingCapture\(\)<a name="ga1cd68b1b385da5224dbfdb6993c5cf08"></a>

```
virtual int32_t OHOS::Media::Camera::TriggerLoopingCapture ([FrameConfig](OHOS-Media-FrameConfig.md) & frameConfig)
```

 **Description:**

Triggers looping-frame capture. 

**Parameters:**

<a name="table1368264656165625"></a>
<table><thead align="left"><tr id="row1945078834165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1517095610165625"><a name="p1517095610165625"></a><a name="p1517095610165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p997153928165625"><a name="p997153928165625"></a><a name="p997153928165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row173168922165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">fc</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the frame configuration. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **true**  if the looping-frame capture is successfully started; returns  **false**  otherwise. 

## TriggerSingleCapture\(\)<a name="gac05d783b1655fe505a4afa23496d7e84"></a>

```
virtual int32_t OHOS::Media::Camera::TriggerSingleCapture ([FrameConfig](OHOS-Media-FrameConfig.md) & frameConfig)
```

 **Description:**

Starts single-frame capture. The frame parameters are set through the  **[FrameConfig](OHOS-Media-FrameConfig.md)**  object, and the captured image data is stored in the surface of the  **[FrameConfig](OHOS-Media-FrameConfig.md)**  object. 

**Parameters:**

<a name="table813727291165625"></a>
<table><thead align="left"><tr id="row1193316194165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p997600247165625"><a name="p997600247165625"></a><a name="p997600247165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1101492684165625"><a name="p1101492684165625"></a><a name="p1101492684165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1314106772165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">fc</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the frame configuration. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **true**  if the single-frame capture is successfully started and the data is stored; returns  **false**  otherwise. 

## \~Camera\(\)<a name="gab24c0e4ca1e15bb2a481fb1550955611"></a>

```
virtual OHOS::Media::Camera::~Camera ()
```

 **Description:**

A destructor used to delete the  **[Camera](OHOS-Media-Camera.md)**  instance. 

