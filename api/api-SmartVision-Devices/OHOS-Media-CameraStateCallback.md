# OHOS::Media::CameraStateCallback<a name="ZH-CN_TOPIC_0000001055358118"></a>

-   [Overview](#section807744296165632)
-   [Summary](#section1866436241165632)
-   [Public Member Functions](#pub-methods)

## **Overview**<a name="section807744296165632"></a>

**Related Modules:**

[MultiMedia\_CameraStateCallback](MultiMedia_CameraStateCallback.md)

**Description:**

Provides functions to response to camera states. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1866436241165632"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table1457968266165632"></a>
<table><thead align="left"><tr id="row193727598165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1400332362165632"><a name="p1400332362165632"></a><a name="p1400332362165632"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p971810114165632"><a name="p971810114165632"></a><a name="p971810114165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row512336711165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p478469609165632"><a name="p478469609165632"></a><a name="p478469609165632"></a><a href="MultiMedia_CameraStateCallback.md#gaa9499b36ed4aac41a67065f62342df70">CameraStateCallback</a> ()=default</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2104547723165632"><a name="p2104547723165632"></a><a name="p2104547723165632"></a> </p>
<p id="p133506212165632"><a name="p133506212165632"></a><a name="p133506212165632"></a>A constructor used to create a <strong id="b1292260332165632"><a name="b1292260332165632"></a><a name="b1292260332165632"></a><a href="OHOS-Media-CameraStateCallback.md">CameraStateCallback</a></strong> instance. </p>
</td>
</tr>
<tr id="row1168210938165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p495671685165632"><a name="p495671685165632"></a><a name="p495671685165632"></a><a href="MultiMedia_CameraStateCallback.md#ga80ba3b334f93c4d9cab07bc749813f9a">~CameraStateCallback</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p885842151165632"><a name="p885842151165632"></a><a name="p885842151165632"></a>virtual </p>
<p id="p126118412165632"><a name="p126118412165632"></a><a name="p126118412165632"></a>A destructor used to delete the <strong id="b744843556165632"><a name="b744843556165632"></a><a name="b744843556165632"></a><a href="OHOS-Media-CameraStateCallback.md">CameraStateCallback</a></strong> instance. </p>
</td>
</tr>
<tr id="row1915756797165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1356279350165632"><a name="p1356279350165632"></a><a name="p1356279350165632"></a><a href="MultiMedia_CameraStateCallback.md#ga29901c517d444a013d44a99350905390">OnCreated</a> (<a href="OHOS-Media-Camera.md">Camera</a> &amp;c)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1151453618165632"><a name="p1151453618165632"></a><a name="p1151453618165632"></a>virtual void </p>
<p id="p375189979165632"><a name="p375189979165632"></a><a name="p375189979165632"></a>Called when the camera is successfully created. </p>
</td>
</tr>
<tr id="row1613163321165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1372244872165632"><a name="p1372244872165632"></a><a name="p1372244872165632"></a><a href="MultiMedia_CameraStateCallback.md#ga9844a6e2c1d4295fe23537a918bdc683">OnCreateFailed</a> (const std::string cameraId, int32_t errorCode)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1336299619165632"><a name="p1336299619165632"></a><a name="p1336299619165632"></a>virtual void </p>
<p id="p955213333165632"><a name="p955213333165632"></a><a name="p955213333165632"></a>Called when the camera fails to be created. </p>
</td>
</tr>
<tr id="row669626471165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p937544833165632"><a name="p937544833165632"></a><a name="p937544833165632"></a><a href="MultiMedia_CameraStateCallback.md#ga4351c9011831fe3e93d986e5a287fe80">OnReleased</a> (<a href="OHOS-Media-Camera.md">Camera</a> &amp;c)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p713585037165632"><a name="p713585037165632"></a><a name="p713585037165632"></a>virtual void </p>
<p id="p2060021469165632"><a name="p2060021469165632"></a><a name="p2060021469165632"></a>Called when the camera is released. </p>
</td>
</tr>
<tr id="row1589542966165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p745894873165632"><a name="p745894873165632"></a><a name="p745894873165632"></a><a href="MultiMedia_CameraStateCallback.md#ga5a0115afe9c5a7ddf8e9acd93a03fd21">OnConfigured</a> (<a href="OHOS-Media-Camera.md">Camera</a> &amp;c)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p690405101165632"><a name="p690405101165632"></a><a name="p690405101165632"></a>virtual void </p>
<p id="p1557604117165632"><a name="p1557604117165632"></a><a name="p1557604117165632"></a>Called when the camera is configured. </p>
</td>
</tr>
<tr id="row169360114165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p68672178165632"><a name="p68672178165632"></a><a name="p68672178165632"></a><a href="MultiMedia_CameraStateCallback.md#gab334119760044ef810ce8ac2301c0d16">OnConfigureFailed</a> (const std::string cameraId, int32_t errorCode)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1473025290165632"><a name="p1473025290165632"></a><a name="p1473025290165632"></a>virtual void </p>
<p id="p1434756407165632"><a name="p1434756407165632"></a><a name="p1434756407165632"></a>Called when the camera fails to be configured. </p>
</td>
</tr>
</tbody>
</table>

