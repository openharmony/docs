# OHOS::Camera::ICameraHostCallback<a name="ZH-CN_TOPIC_0000001343200765"></a>

## **概述**<a name="section1349689082083932"></a>

**所属模块:**

[Camera](_camera.md)

## **汇总**<a name="section1499637170083932"></a>

## Public 成员函数<a name="pub-methods"></a>

<a name="table1068671601083932"></a>
<table><thead align="left"><tr id="row919933341083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p626945632083932"><a name="p626945632083932"></a><a name="p626945632083932"></a>Public 成员函数</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p4508520083932"><a name="p4508520083932"></a><a name="p4508520083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1968575671083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2033811461083932"><a name="p2033811461083932"></a><a name="p2033811461083932"></a><strong id="b1429162655083932"><a name="b1429162655083932"></a><a name="b1429162655083932"></a>DECLARE_INTERFACE_DESCRIPTOR</strong> (u"HDI.Camera.V1_0.HostCallback")</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p725971119211"><a name="p725971119211"></a><a name="p725971119211"></a>IPC通信token校验。</p>
</td>
</tr>
<tr id="row636925315083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p905265643083932"><a name="p905265643083932"></a><a name="p905265643083932"></a><a href="_camera.md#ga6be010418aea15a4d4af8719c87b2ec0">OnCameraStatus</a> (const std::string &amp;cameraId, <a href="_camera.md#gac2c065c30743f0053f460a6683845dad">CameraStatus</a> status)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1005222418083932"><a name="p1005222418083932"></a><a name="p1005222418083932"></a>用于Camera设备状态变化时上报状态信息给调用者。 <a href="_camera.md#ga6be010418aea15a4d4af8719c87b2ec0">更多...</a></p>
</td>
</tr>
<tr id="row896822169083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1032915321083932"><a name="p1032915321083932"></a><a name="p1032915321083932"></a><a href="_camera.md#ga98ee7a84744d5d6fa5c8c6b304739452">OnFlashlightStatus</a> (const std::string &amp;cameraId, <a href="_camera.md#ga1a82bc94cb6ff38f7fd0dfcffab71df3">FlashlightStatus</a> status)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1213124161083932"><a name="p1213124161083932"></a><a name="p1213124161083932"></a>用于在闪光灯状态变化时上报状态信息给调用者。 <a href="_camera.md#ga98ee7a84744d5d6fa5c8c6b304739452">更多...</a></p>
</td>
</tr>
<tr id="row856798018083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1984761747083932"><a name="p1984761747083932"></a><a name="p1984761747083932"></a><a href="_camera.md#ga0e8cefd5c1069d26c989dd4435aa4e01">OnCameraEvent</a> (const std::string &amp;cameraId, <a href="_camera.md#ga14253812c3a39d52d827589bf5e5b970">CameraEvent</a> event)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1095500790083932"><a name="p1095500790083932"></a><a name="p1095500790083932"></a>在相机事件发生时调用。 <a href="_camera.md#ga0e8cefd5c1069d26c989dd4435aa4e01">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section1838491315618"></a>

Camera服务的管理回调。

