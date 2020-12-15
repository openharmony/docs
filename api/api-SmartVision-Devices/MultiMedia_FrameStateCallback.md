# MultiMedia\_FrameStateCallback<a name="ZH-CN_TOPIC_0000001055078093"></a>

-   [Overview](#section594449935165625)
-   [Summary](#section1998256790165625)
-   [Files](#files)
-   [Data Structures](#nested-classes)
-   [Functions](#func-members)
-   [Details](#section1902417098165625)
-   [Function](#section543315877165625)
-   [FrameStateCallback\(\)](#gab2557f65a2744911b66361a895450d67)
-   [OnFrameError\(\)](#ga8692c0a7433e0a98b6a6e364081c3b6a)
-   [OnFrameFinished\(\)](#gaad7c0bd2d27255a8b63d0f5fb75f3b1e)
-   [\~FrameStateCallback\(\)](#gad9ee33e328b523316313b79979b93abb)

## **Overview**<a name="section594449935165625"></a>

**Description:**

Provides callbacks for frame state changes, in which you can implement operations to response to the changes. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1998256790165625"></a>

## Files<a name="files"></a>

<a name="table342500398165625"></a>
<table><thead align="left"><tr id="row691447787165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p751043643165625"><a name="p751043643165625"></a><a name="p751043643165625"></a>File Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2017480487165625"><a name="p2017480487165625"></a><a name="p2017480487165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1198410639165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p49665126165625"><a name="p49665126165625"></a><a name="p49665126165625"></a><a href="camera_kit-h.md">camera_kit.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1096294533165625"><a name="p1096294533165625"></a><a name="p1096294533165625"></a>Declares functions in the <strong id="b1280500269165625"><a name="b1280500269165625"></a><a name="b1280500269165625"></a>CameraKit</strong> class. </p>
</td>
</tr>
</tbody>
</table>

## Data Structures<a name="nested-classes"></a>

<a name="table562214837165625"></a>
<table><thead align="left"><tr id="row1632562102165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1995484168165625"><a name="p1995484168165625"></a><a name="p1995484168165625"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p493769134165625"><a name="p493769134165625"></a><a name="p493769134165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1385698160165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p980005119165625"><a name="p980005119165625"></a><a name="p980005119165625"></a><a href="OHOS-Media-FrameStateCallback.md">OHOS::Media::FrameStateCallback</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1084649061165625"><a name="p1084649061165625"></a><a name="p1084649061165625"></a>Provides functions to listen for frame states and response to the state changes. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table634938471165625"></a>
<table><thead align="left"><tr id="row2047685711165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1408706100165625"><a name="p1408706100165625"></a><a name="p1408706100165625"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p577365442165625"><a name="p577365442165625"></a><a name="p577365442165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1021587308165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p879170954165625"><a name="p879170954165625"></a><a name="p879170954165625"></a><a href="MultiMedia_FrameStateCallback.md#gab2557f65a2744911b66361a895450d67">OHOS::Media::FrameStateCallback::FrameStateCallback</a> ()=default</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1485126932165625"><a name="p1485126932165625"></a><a name="p1485126932165625"></a> </p>
<p id="p272704566165625"><a name="p272704566165625"></a><a name="p272704566165625"></a>A constructor used to create a <strong id="b21536647165625"><a name="b21536647165625"></a><a name="b21536647165625"></a><a href="OHOS-Media-FrameStateCallback.md">FrameStateCallback</a></strong> instance. </p>
</td>
</tr>
<tr id="row1553233690165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p181215042165625"><a name="p181215042165625"></a><a name="p181215042165625"></a><a href="MultiMedia_FrameStateCallback.md#gad9ee33e328b523316313b79979b93abb">OHOS::Media::FrameStateCallback::~FrameStateCallback</a> ()=default</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p768586639165625"><a name="p768586639165625"></a><a name="p768586639165625"></a> </p>
<p id="p331965810165625"><a name="p331965810165625"></a><a name="p331965810165625"></a>A destructor used to delete the <strong id="b2039386072165625"><a name="b2039386072165625"></a><a name="b2039386072165625"></a><a href="OHOS-Media-FrameStateCallback.md">FrameStateCallback</a></strong> instance. </p>
</td>
</tr>
<tr id="row460520209165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p334739941165625"><a name="p334739941165625"></a><a name="p334739941165625"></a><a href="MultiMedia_FrameStateCallback.md#gaad7c0bd2d27255a8b63d0f5fb75f3b1e">OHOS::Media::FrameStateCallback::OnFrameFinished</a> (<a href="OHOS-Media-Camera.md">Camera</a> &amp;camera, <a href="OHOS-Media-FrameConfig.md">FrameConfig</a> &amp;frameConfig, FrameResult &amp;frameResult)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1013579507165625"><a name="p1013579507165625"></a><a name="p1013579507165625"></a>virtual void </p>
<p id="p8859331165625"><a name="p8859331165625"></a><a name="p8859331165625"></a>Called when the frame capture is finished. </p>
</td>
</tr>
<tr id="row260680905165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1378187304165625"><a name="p1378187304165625"></a><a name="p1378187304165625"></a><a href="MultiMedia_FrameStateCallback.md#ga8692c0a7433e0a98b6a6e364081c3b6a">OHOS::Media::FrameStateCallback::OnFrameError</a> (<a href="OHOS-Media-Camera.md">Camera</a> &amp;camera, <a href="OHOS-Media-FrameConfig.md">FrameConfig</a> &amp;frameConfig, int32_t errorCode, FrameResult &amp;frameResult)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1947086029165625"><a name="p1947086029165625"></a><a name="p1947086029165625"></a>virtual void </p>
<p id="p727039366165625"><a name="p727039366165625"></a><a name="p727039366165625"></a>Called when the frame capture fails. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1902417098165625"></a>

## **Function **<a name="section543315877165625"></a>

## FrameStateCallback\(\)<a name="gab2557f65a2744911b66361a895450d67"></a>

```
OHOS::Media::FrameStateCallback::FrameStateCallback ()
```

 **Description:**

A constructor used to create a  **[FrameStateCallback](OHOS-Media-FrameStateCallback.md)**  instance. 

## OnFrameError\(\)<a name="ga8692c0a7433e0a98b6a6e364081c3b6a"></a>

```
virtual void OHOS::Media::FrameStateCallback::OnFrameError ([Camera](OHOS-Media-Camera.md) & camera, [FrameConfig](OHOS-Media-FrameConfig.md) & frameConfig, int32_t errorCode, FrameResult & frameResult )
```

 **Description:**

Called when the frame capture fails. 

**Parameters:**

<a name="table1617194877165625"></a>
<table><thead align="left"><tr id="row1600252957165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p932903682165625"><a name="p932903682165625"></a><a name="p932903682165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p645004060165625"><a name="p645004060165625"></a><a name="p645004060165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row517757197165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">camera</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the camera. </td>
</tr>
<tr id="row2047869599165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">frameConfig</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the frame configuration. </td>
</tr>
<tr id="row185876850165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">errorCode</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the error code. </td>
</tr>
<tr id="row2109469379165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">frameResult</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the capture results. </td>
</tr>
</tbody>
</table>

## OnFrameFinished\(\)<a name="gaad7c0bd2d27255a8b63d0f5fb75f3b1e"></a>

```
virtual void OHOS::Media::FrameStateCallback::OnFrameFinished ([Camera](OHOS-Media-Camera.md) & camera, [FrameConfig](OHOS-Media-FrameConfig.md) & frameConfig, FrameResult & frameResult )
```

 **Description:**

Called when the frame capture is finished. 

**Parameters:**

<a name="table1229588815165625"></a>
<table><thead align="left"><tr id="row1815025952165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2051374534165625"><a name="p2051374534165625"></a><a name="p2051374534165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p945790631165625"><a name="p945790631165625"></a><a name="p945790631165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1787750064165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">camera</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the camera. </td>
</tr>
<tr id="row1319643321165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">frameConfig</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the frame configuration. </td>
</tr>
<tr id="row1020759396165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">frameResult</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the capture results. </td>
</tr>
</tbody>
</table>

## \~FrameStateCallback\(\)<a name="gad9ee33e328b523316313b79979b93abb"></a>

```
OHOS::Media::FrameStateCallback::~FrameStateCallback ()
```

 **Description:**

A destructor used to delete the  **[FrameStateCallback](OHOS-Media-FrameStateCallback.md)**  instance. 

