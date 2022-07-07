# OHOS::Camera::ICameraHost<a name="ZH-CN_TOPIC_0000001291040604"></a>

## **概述**<a name="section566899803083932"></a>

**所属模块:**

[Camera](_camera.md)

## **汇总**<a name="section1748339168083932"></a>

## Public 成员函数<a name="pub-methods"></a>

<a name="table1916395748083932"></a>
<table><thead align="left"><tr id="row423131984083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1500534002083932"><a name="p1500534002083932"></a><a name="p1500534002083932"></a>Public 成员函数</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1544549258083932"><a name="p1544549258083932"></a><a name="p1544549258083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row502773148083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p637917437083932"><a name="p637917437083932"></a><a name="p637917437083932"></a><strong id="b857478258083932"><a name="b857478258083932"></a><a name="b857478258083932"></a>DECLARE_INTERFACE_DESCRIPTOR</strong> (u"HDI.Camera.V1_0.Host")</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p725971119211"><a name="p725971119211"></a><a name="p725971119211"></a>IPC通信token校验。</p>
</td>
</tr>
<tr id="row1244983123083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1639391740083932"><a name="p1639391740083932"></a><a name="p1639391740083932"></a><a href="_camera.md#ga3caa092a17467ce472498046b13fe685">SetCallback</a> (const OHOS::sptr&lt; <a href="_o_h_o_s_1_1_camera_1_1_i_camera_host_callback.md">ICameraHostCallback</a> &gt; &amp;callback)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p488007936083932"><a name="p488007936083932"></a><a name="p488007936083932"></a>设置ICameraHost回调接口，回调函数参考 <a href="_o_h_o_s_1_1_camera_1_1_i_camera_host_callback.md">ICameraHostCallback</a>。 <a href="_camera.md#ga3caa092a17467ce472498046b13fe685">更多...</a></p>
</td>
</tr>
<tr id="row1544995366083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2016476304083932"><a name="p2016476304083932"></a><a name="p2016476304083932"></a><a href="_camera.md#gab3128eb3432a830b2cff6bcd999bca10">GetCameraIds</a> (std::vector&lt; std::string &gt; &amp;cameraIds)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1371252104083932"><a name="p1371252104083932"></a><a name="p1371252104083932"></a>获取当前可用的Camera设备ID列表。 <a href="_camera.md#gab3128eb3432a830b2cff6bcd999bca10">更多...</a></p>
</td>
</tr>
<tr id="row1734890268083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1807311433083932"><a name="p1807311433083932"></a><a name="p1807311433083932"></a><a href="_camera.md#gad813ea200395e42a3ec2a457cc04b93d">GetCameraAbility</a> (const std::string &amp;cameraId, std::shared_ptr&lt; CameraAbility &gt; &amp;ability)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1447401956083932"><a name="p1447401956083932"></a><a name="p1447401956083932"></a>获取Camera设备能力集合。 <a href="_camera.md#gad813ea200395e42a3ec2a457cc04b93d">更多...</a></p>
</td>
</tr>
<tr id="row599590274083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p35971118083932"><a name="p35971118083932"></a><a name="p35971118083932"></a><a href="_camera.md#gaf9e7aa942d3e31504d8ef5e710b029f1">OpenCamera</a> (const std::string &amp;cameraId, const OHOS::sptr&lt; <a href="_o_h_o_s_1_1_camera_1_1_i_camera_device_callback.md">ICameraDeviceCallback</a> &gt; &amp;callback, OHOS::sptr&lt; <a href="_o_h_o_s_1_1_camera_1_1_i_camera_device.md">ICameraDevice</a> &gt; &amp;device)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1640432092083932"><a name="p1640432092083932"></a><a name="p1640432092083932"></a>打开Camera设备。 <a href="_camera.md#gaf9e7aa942d3e31504d8ef5e710b029f1">更多...</a></p>
</td>
</tr>
<tr id="row2124594546083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1873068377083932"><a name="p1873068377083932"></a><a name="p1873068377083932"></a><a href="_camera.md#gaa8e9b572081e0a489ca2f6772a7c18e8">SetFlashlight</a> (const std::string &amp;cameraId, bool &amp;isEnable)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1249810201083932"><a name="p1249810201083932"></a><a name="p1249810201083932"></a>打开或关闭闪光灯。 <a href="_camera.md#gaa8e9b572081e0a489ca2f6772a7c18e8">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## 静态 Public 成员函数<a name="pub-static-methods"></a>

<a name="table250244550083932"></a>
<table><thead align="left"><tr id="row399894863083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p199143489083932"><a name="p199143489083932"></a><a name="p199143489083932"></a>静态 Public 成员函数</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1701056278083932"><a name="p1701056278083932"></a><a name="p1701056278083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row458444504083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1918527078083932"><a name="p1918527078083932"></a><a name="p1918527078083932"></a><a href="_camera.md#gaeec1c2ffe13be9abd9f4ab7b6fc83b21">Get</a> (const char *serviceName)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p395993057083932"><a name="p395993057083932"></a><a name="p395993057083932"></a>获取ICameraHost实例。 <a href="_camera.md#gaeec1c2ffe13be9abd9f4ab7b6fc83b21">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section1838491315618"></a>

Camera服务的管理类。

