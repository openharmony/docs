# OHOS::Camera::IStreamOperatorCallback<a name="ZH-CN_TOPIC_0000001343000889"></a>

## **概述**<a name="section1500593852083932"></a>

**所属模块:**

[Camera](_camera.md)

## **汇总**<a name="section2118015345083932"></a>

## Public 成员函数<a name="pub-methods"></a>

<a name="table692215221083932"></a>
<table><thead align="left"><tr id="row2049546298083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p461502297083932"><a name="p461502297083932"></a><a name="p461502297083932"></a>Public 成员函数</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p90023822083932"><a name="p90023822083932"></a><a name="p90023822083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1391392922083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1040941098083932"><a name="p1040941098083932"></a><a name="p1040941098083932"></a><strong id="b2058154453083932"><a name="b2058154453083932"></a><a name="b2058154453083932"></a>DECLARE_INTERFACE_DESCRIPTOR</strong> (u"HDI.Camera.V1_0.StreamOperatorCallback")</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p725971119211"><a name="p725971119211"></a><a name="p725971119211"></a>IPC通信token校验。</p>
</td>
</tr>
<tr id="row540491207083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p998841477083932"><a name="p998841477083932"></a><a name="p998841477083932"></a><a href="_camera.md#ga6389672b42dcead4067bbb06aa7b8c18">OnCaptureStarted</a> (int32_t captureId, const std::vector&lt; int32_t &gt; &amp;streamIds)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p942605090083932"><a name="p942605090083932"></a><a name="p942605090083932"></a>捕获开始回调，在捕获开始时调用。 <a href="_camera.md#ga6389672b42dcead4067bbb06aa7b8c18">更多...</a></p>
</td>
</tr>
<tr id="row1643176540083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1226253082083932"><a name="p1226253082083932"></a><a name="p1226253082083932"></a><a href="_camera.md#ga3761990cab402ce99251b26e3802070d">OnCaptureEnded</a> (int32_t captureId, const std::vector&lt; std::shared_ptr&lt; <a href="_o_h_o_s_1_1_camera_1_1_capture_ended_info.md">CaptureEndedInfo</a> &gt;&gt; &amp;infos)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p212423707083932"><a name="p212423707083932"></a><a name="p212423707083932"></a>捕获结束回调，在捕获结束时调用。 <a href="_camera.md#ga3761990cab402ce99251b26e3802070d">更多...</a></p>
</td>
</tr>
<tr id="row667766655083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2074506800083932"><a name="p2074506800083932"></a><a name="p2074506800083932"></a><a href="_camera.md#gacea9a4cf4bdd5fab5499da06ecdf9b8f">OnCaptureError</a> (int32_t captureId, const std::vector&lt; std::shared_ptr&lt; <a href="_o_h_o_s_1_1_camera_1_1_capture_error_info.md">CaptureErrorInfo</a> &gt;&gt; &amp;infos)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p438577888083932"><a name="p438577888083932"></a><a name="p438577888083932"></a>捕获错误回调，在捕获过程中发生错误时调用。 <a href="_camera.md#gacea9a4cf4bdd5fab5499da06ecdf9b8f">更多...</a></p>
</td>
</tr>
<tr id="row1535418890083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1171873708083932"><a name="p1171873708083932"></a><a name="p1171873708083932"></a><a href="_camera.md#gabf1554ca18f9724a7551a864e610534e">OnFrameShutter</a> (int32_t captureId, const std::vector&lt; int32_t &gt; &amp;streamIds, uint64_t timestamp)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1453317386083932"><a name="p1453317386083932"></a><a name="p1453317386083932"></a>帧捕获回调。 <a href="_camera.md#gabf1554ca18f9724a7551a864e610534e">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section1838491315618"></a>

流的操作回调类。

