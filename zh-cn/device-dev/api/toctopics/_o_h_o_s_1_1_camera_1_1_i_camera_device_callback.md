# OHOS::Camera::ICameraDeviceCallback<a name="ZH-CN_TOPIC_0000001343321041"></a>

## **概述**<a name="section1913256078083932"></a>

**所属模块:**

[Camera](_camera.md)

## **汇总**<a name="section1243652605083932"></a>

## Public 成员函数<a name="pub-methods"></a>

<a name="table241175930083932"></a>
<table><thead align="left"><tr id="row1401244398083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p113732323083932"><a name="p113732323083932"></a><a name="p113732323083932"></a>Public 成员函数</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p96773181083932"><a name="p96773181083932"></a><a name="p96773181083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row508031185083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1277780554083932"><a name="p1277780554083932"></a><a name="p1277780554083932"></a><strong id="b174107219083932"><a name="b174107219083932"></a><a name="b174107219083932"></a>DECLARE_INTERFACE_DESCRIPTOR</strong> (u"HDI.Camera.V1_0.DeviceCallback")</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry12698931083932p0"><a name="entry12698931083932p0"></a><a name="entry12698931083932p0"></a>IPC通信token校验。</p>
</td>
</tr>
<tr id="row268227914083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1303577585083932"><a name="p1303577585083932"></a><a name="p1303577585083932"></a><a href="_camera.md#ga8a2014d4173fc7fae08e62b9d85b5333">OnError</a> (<a href="_camera.md#ga4d1b650185695d9df8652593a7bc522d">ErrorType</a> type, int32_t errorCode)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1129137941083932"><a name="p1129137941083932"></a><a name="p1129137941083932"></a>设备发生错误时调用，由调用者实现，用于返回错误信息给调用者。 <a href="_camera.md#ga8a2014d4173fc7fae08e62b9d85b5333">更多...</a></p>
</td>
</tr>
<tr id="row599724291083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1218083250083932"><a name="p1218083250083932"></a><a name="p1218083250083932"></a><a href="_camera.md#gaaf9511e740682143565285edabc0b4ff">OnResult</a> (uint64_t timestamp, const std::shared_ptr&lt; CameraMetadata &gt; &amp;result)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p354508740083932"><a name="p354508740083932"></a><a name="p354508740083932"></a>上报camera设备相关的metadata的回调，上报方式查看 <a href="_camera.md#ga8adaa4f26fffa98626a2c7e731393174">SetResultMode</a>。 <a href="_camera.md#gaaf9511e740682143565285edabc0b4ff">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section1838491315618"></a>

Camera设备操作回调。

