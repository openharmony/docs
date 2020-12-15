# MultiMedia\_CameraStateCallback<a name="ZH-CN_TOPIC_0000001054918109"></a>

-   [Overview](#section1165669900165625)
-   [Summary](#section777205647165625)
-   [Files](#files)
-   [Data Structures](#nested-classes)
-   [Functions](#func-members)
-   [Details](#section583980644165625)
-   [Function](#section1662647736165625)
-   [CameraStateCallback\(\)](#gaa9499b36ed4aac41a67065f62342df70)
-   [OnConfigured\(\)](#ga5a0115afe9c5a7ddf8e9acd93a03fd21)
-   [OnConfigureFailed\(\)](#gab334119760044ef810ce8ac2301c0d16)
-   [OnCreated\(\)](#ga29901c517d444a013d44a99350905390)
-   [OnCreateFailed\(\)](#ga9844a6e2c1d4295fe23537a918bdc683)
-   [OnReleased\(\)](#ga4351c9011831fe3e93d986e5a287fe80)
-   [\~CameraStateCallback\(\)](#ga80ba3b334f93c4d9cab07bc749813f9a)

## **Overview**<a name="section1165669900165625"></a>

**Description:**

Provides callbacks for camera states to configure responses to the states. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section777205647165625"></a>

## Files<a name="files"></a>

<a name="table325926513165625"></a>
<table><thead align="left"><tr id="row1976108740165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1199772141165625"><a name="p1199772141165625"></a><a name="p1199772141165625"></a>File Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1215765055165625"><a name="p1215765055165625"></a><a name="p1215765055165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1010844524165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2016626256165625"><a name="p2016626256165625"></a><a name="p2016626256165625"></a><a href="camera_state_callback-h.md">camera_state_callback.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p940182879165625"><a name="p940182879165625"></a><a name="p940182879165625"></a>Declares functions in the <strong id="b765515030165625"><a name="b765515030165625"></a><a name="b765515030165625"></a>CameraStateCallback</strong> class. </p>
</td>
</tr>
</tbody>
</table>

## Data Structures<a name="nested-classes"></a>

<a name="table1891201003165625"></a>
<table><thead align="left"><tr id="row1396637126165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2025831381165625"><a name="p2025831381165625"></a><a name="p2025831381165625"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1977393081165625"><a name="p1977393081165625"></a><a name="p1977393081165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1961812801165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1389355678165625"><a name="p1389355678165625"></a><a name="p1389355678165625"></a><a href="OHOS-Media-CameraStateCallback.md">OHOS::Media::CameraStateCallback</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p68757378165625"><a name="p68757378165625"></a><a name="p68757378165625"></a>Provides functions to response to camera states. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table1463736818165625"></a>
<table><thead align="left"><tr id="row893358877165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1439601020165625"><a name="p1439601020165625"></a><a name="p1439601020165625"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1326287125165625"><a name="p1326287125165625"></a><a name="p1326287125165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1372153631165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1363326402165625"><a name="p1363326402165625"></a><a name="p1363326402165625"></a><a href="MultiMedia_CameraStateCallback.md#gaa9499b36ed4aac41a67065f62342df70">OHOS::Media::CameraStateCallback::CameraStateCallback</a> ()=default</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p775341331165625"><a name="p775341331165625"></a><a name="p775341331165625"></a> </p>
<p id="p1326325304165625"><a name="p1326325304165625"></a><a name="p1326325304165625"></a>A constructor used to create a <strong id="b1373383676165625"><a name="b1373383676165625"></a><a name="b1373383676165625"></a><a href="OHOS-Media-CameraStateCallback.md">CameraStateCallback</a></strong> instance. </p>
</td>
</tr>
<tr id="row615689196165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p452116902165625"><a name="p452116902165625"></a><a name="p452116902165625"></a><a href="MultiMedia_CameraStateCallback.md#ga80ba3b334f93c4d9cab07bc749813f9a">OHOS::Media::CameraStateCallback::~CameraStateCallback</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1430916199165625"><a name="p1430916199165625"></a><a name="p1430916199165625"></a>virtual </p>
<p id="p382137348165625"><a name="p382137348165625"></a><a name="p382137348165625"></a>A destructor used to delete the <strong id="b116680392165625"><a name="b116680392165625"></a><a name="b116680392165625"></a><a href="OHOS-Media-CameraStateCallback.md">CameraStateCallback</a></strong> instance. </p>
</td>
</tr>
<tr id="row1736489112165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2079203203165625"><a name="p2079203203165625"></a><a name="p2079203203165625"></a><a href="MultiMedia_CameraStateCallback.md#ga29901c517d444a013d44a99350905390">OHOS::Media::CameraStateCallback::OnCreated</a> (<a href="OHOS-Media-Camera.md">Camera</a> &amp;c)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p310041030165625"><a name="p310041030165625"></a><a name="p310041030165625"></a>virtual void </p>
<p id="p421089376165625"><a name="p421089376165625"></a><a name="p421089376165625"></a>Called when the camera is successfully created. </p>
</td>
</tr>
<tr id="row16849803165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1987718957165625"><a name="p1987718957165625"></a><a name="p1987718957165625"></a><a href="MultiMedia_CameraStateCallback.md#ga9844a6e2c1d4295fe23537a918bdc683">OHOS::Media::CameraStateCallback::OnCreateFailed</a> (const std::string cameraId, int32_t errorCode)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p891009904165625"><a name="p891009904165625"></a><a name="p891009904165625"></a>virtual void </p>
<p id="p797525170165625"><a name="p797525170165625"></a><a name="p797525170165625"></a>Called when the camera fails to be created. </p>
</td>
</tr>
<tr id="row1834386532165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p952659782165625"><a name="p952659782165625"></a><a name="p952659782165625"></a><a href="MultiMedia_CameraStateCallback.md#ga4351c9011831fe3e93d986e5a287fe80">OHOS::Media::CameraStateCallback::OnReleased</a> (<a href="OHOS-Media-Camera.md">Camera</a> &amp;c)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1132818242165625"><a name="p1132818242165625"></a><a name="p1132818242165625"></a>virtual void </p>
<p id="p68318810165625"><a name="p68318810165625"></a><a name="p68318810165625"></a>Called when the camera is released. </p>
</td>
</tr>
<tr id="row136099647165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1106413008165625"><a name="p1106413008165625"></a><a name="p1106413008165625"></a><a href="MultiMedia_CameraStateCallback.md#ga5a0115afe9c5a7ddf8e9acd93a03fd21">OHOS::Media::CameraStateCallback::OnConfigured</a> (<a href="OHOS-Media-Camera.md">Camera</a> &amp;c)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p434789248165625"><a name="p434789248165625"></a><a name="p434789248165625"></a>virtual void </p>
<p id="p2001956700165625"><a name="p2001956700165625"></a><a name="p2001956700165625"></a>Called when the camera is configured. </p>
</td>
</tr>
<tr id="row2116499455165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p74017518165625"><a name="p74017518165625"></a><a name="p74017518165625"></a><a href="MultiMedia_CameraStateCallback.md#gab334119760044ef810ce8ac2301c0d16">OHOS::Media::CameraStateCallback::OnConfigureFailed</a> (const std::string cameraId, int32_t errorCode)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p90649688165625"><a name="p90649688165625"></a><a name="p90649688165625"></a>virtual void </p>
<p id="p1377441217165625"><a name="p1377441217165625"></a><a name="p1377441217165625"></a>Called when the camera fails to be configured. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section583980644165625"></a>

## **Function **<a name="section1662647736165625"></a>

## CameraStateCallback\(\)<a name="gaa9499b36ed4aac41a67065f62342df70"></a>

```
OHOS::Media::CameraStateCallback::CameraStateCallback ()
```

 **Description:**

A constructor used to create a  **[CameraStateCallback](OHOS-Media-CameraStateCallback.md)**  instance. 

## OnConfigured\(\)<a name="ga5a0115afe9c5a7ddf8e9acd93a03fd21"></a>

```
virtual void OHOS::Media::CameraStateCallback::OnConfigured ([Camera](OHOS-Media-Camera.md) & c)
```

 **Description:**

Called when the camera is configured. 

**Parameters:**

<a name="table1252592424165625"></a>
<table><thead align="left"><tr id="row67747983165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p403100751165625"><a name="p403100751165625"></a><a name="p403100751165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1273746138165625"><a name="p1273746138165625"></a><a name="p1273746138165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row303385747165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">c</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">camera Indicates the <strong id="b143665597165625"><a name="b143665597165625"></a><a name="b143665597165625"></a><a href="OHOS-Media-Camera.md">Camera</a></strong> object. </td>
</tr>
</tbody>
</table>

## OnConfigureFailed\(\)<a name="gab334119760044ef810ce8ac2301c0d16"></a>

```
virtual void OHOS::Media::CameraStateCallback::OnConfigureFailed (const std::string cameraId, int32_t errorCode )
```

 **Description:**

Called when the camera fails to be configured. 

**Parameters:**

<a name="table1009215747165625"></a>
<table><thead align="left"><tr id="row800377537165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p140711168165625"><a name="p140711168165625"></a><a name="p140711168165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2070185972165625"><a name="p2070185972165625"></a><a name="p2070185972165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1001344028165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">c</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the <strong id="b1300899734165625"><a name="b1300899734165625"></a><a name="b1300899734165625"></a><a href="OHOS-Media-Camera.md">Camera</a></strong> object. </td>
</tr>
<tr id="row503857881165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">errorCode</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the error code. </td>
</tr>
</tbody>
</table>

## OnCreated\(\)<a name="ga29901c517d444a013d44a99350905390"></a>

```
virtual void OHOS::Media::CameraStateCallback::OnCreated ([Camera](OHOS-Media-Camera.md) & c)
```

 **Description:**

Called when the camera is successfully created. 

**Parameters:**

<a name="table627821607165625"></a>
<table><thead align="left"><tr id="row1751825005165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p335795612165625"><a name="p335795612165625"></a><a name="p335795612165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1631808944165625"><a name="p1631808944165625"></a><a name="p1631808944165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1979139323165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">c</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the <strong id="b534776260165625"><a name="b534776260165625"></a><a name="b534776260165625"></a><a href="OHOS-Media-Camera.md">Camera</a></strong> object. </td>
</tr>
</tbody>
</table>

## OnCreateFailed\(\)<a name="ga9844a6e2c1d4295fe23537a918bdc683"></a>

```
virtual void OHOS::Media::CameraStateCallback::OnCreateFailed (const std::string cameraId, int32_t errorCode )
```

 **Description:**

Called when the camera fails to be created. 

**Parameters:**

<a name="table1558284441165625"></a>
<table><thead align="left"><tr id="row434941713165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p933607243165625"><a name="p933607243165625"></a><a name="p933607243165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1485258944165625"><a name="p1485258944165625"></a><a name="p1485258944165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2071271148165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">cameraId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the camera ID. </td>
</tr>
<tr id="row2064954984165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">errorCode</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the error code. </td>
</tr>
</tbody>
</table>

## OnReleased\(\)<a name="ga4351c9011831fe3e93d986e5a287fe80"></a>

```
virtual void OHOS::Media::CameraStateCallback::OnReleased ([Camera](OHOS-Media-Camera.md) & c)
```

 **Description:**

Called when the camera is released. 

**Parameters:**

<a name="table1057637983165625"></a>
<table><thead align="left"><tr id="row804646087165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1259081388165625"><a name="p1259081388165625"></a><a name="p1259081388165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1537791315165625"><a name="p1537791315165625"></a><a name="p1537791315165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1779277717165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">c</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the <strong id="b231049881165625"><a name="b231049881165625"></a><a name="b231049881165625"></a><a href="OHOS-Media-Camera.md">Camera</a></strong> object. </td>
</tr>
</tbody>
</table>

## \~CameraStateCallback\(\)<a name="ga80ba3b334f93c4d9cab07bc749813f9a"></a>

```
virtual OHOS::Media::CameraStateCallback::~CameraStateCallback ()
```

 **Description:**

A destructor used to delete the  **[CameraStateCallback](OHOS-Media-CameraStateCallback.md)**  instance. 

