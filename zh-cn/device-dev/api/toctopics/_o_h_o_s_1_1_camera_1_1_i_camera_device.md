# OHOS::Camera::ICameraDevice<a name="ZH-CN_TOPIC_0000001290561200"></a>

## **概述**<a name="section1973916912083932"></a>

**所属模块:**

[Camera](_camera.md)

## **汇总**<a name="section1854450437083932"></a>

## Public 成员函数<a name="pub-methods"></a>

<a name="table278843210083932"></a>
<table><thead align="left"><tr id="row1224989746083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1291600249083932"><a name="p1291600249083932"></a><a name="p1291600249083932"></a>Public 成员函数</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1449271686083932"><a name="p1449271686083932"></a><a name="p1449271686083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row37283274083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1730478471083932"><a name="p1730478471083932"></a><a name="p1730478471083932"></a><strong id="b510116330083932"><a name="b510116330083932"></a><a name="b510116330083932"></a>DECLARE_INTERFACE_DESCRIPTOR</strong> (u"HDI.Camera.V1_0.Device")</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p725971119211"><a name="p725971119211"></a><a name="p725971119211"></a>IPC通信token校验。</p>
</td>
</tr>
<tr id="row2106757462083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1947350856083932"><a name="p1947350856083932"></a><a name="p1947350856083932"></a><a href="_camera.md#gac49f0d8fc0ed8a2b8058fdd1bb695fa3">GetStreamOperator</a> (const OHOS::sptr&lt; <a href="_o_h_o_s_1_1_camera_1_1_i_stream_operator_callback.md">IStreamOperatorCallback</a> &gt; &amp;callback, OHOS::sptr&lt; <a href="_o_h_o_s_1_1_camera_1_1_i_stream_operator.md">IStreamOperator</a> &gt; &amp;streamOperator)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1592856161083932"><a name="p1592856161083932"></a><a name="p1592856161083932"></a>获取流操作句柄。 <a href="_camera.md#gac49f0d8fc0ed8a2b8058fdd1bb695fa3">更多...</a></p>
</td>
</tr>
<tr id="row1182653136083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p867970413083932"><a name="p867970413083932"></a><a name="p867970413083932"></a><a href="_camera.md#gaceecba48e611efeec8bdf44d750b41a2">UpdateSettings</a> (const std::shared_ptr&lt; CameraSetting &gt; &amp;settings)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1504682523083932"><a name="p1504682523083932"></a><a name="p1504682523083932"></a>更新设备控制参数。 <a href="_camera.md#gaceecba48e611efeec8bdf44d750b41a2">更多...</a></p>
</td>
</tr>
<tr id="row250107256083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p612293745083932"><a name="p612293745083932"></a><a name="p612293745083932"></a><a href="_camera.md#ga8adaa4f26fffa98626a2c7e731393174">SetResultMode</a> (const <a href="_camera.md#ga0290782009631708fe5351c54f019353">ResultCallbackMode</a> &amp;mode)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p950120570083932"><a name="p950120570083932"></a><a name="p950120570083932"></a>设置metadata上报模式，逐帧上报还是设备状态变化时上报。 <a href="_camera.md#ga8adaa4f26fffa98626a2c7e731393174">更多...</a></p>
</td>
</tr>
<tr id="row430143445083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1072785251083932"><a name="p1072785251083932"></a><a name="p1072785251083932"></a><a href="_camera.md#gaa1b81bee249efb9523a4d62659f28aef">GetEnabledResults</a> (std::vector&lt; MetaType &gt; &amp;results)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1271109314083932"><a name="p1271109314083932"></a><a name="p1271109314083932"></a>查询使能的metadata。 <a href="_camera.md#gaa1b81bee249efb9523a4d62659f28aef">更多...</a></p>
</td>
</tr>
<tr id="row1041911875083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1999320296083932"><a name="p1999320296083932"></a><a name="p1999320296083932"></a><a href="_camera.md#ga265b16a5b7969045b38de95bf782b75c">EnableResult</a> (const std::vector&lt; MetaType &gt; &amp;results)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1184569759083932"><a name="p1184569759083932"></a><a name="p1184569759083932"></a>打开metadata上报开关。 <a href="_camera.md#ga265b16a5b7969045b38de95bf782b75c">更多...</a></p>
</td>
</tr>
<tr id="row1326431521083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p465523708083932"><a name="p465523708083932"></a><a name="p465523708083932"></a><a href="_camera.md#ga68fd022b82dfba6d9431220faf9856bd">DisableResult</a> (const std::vector&lt; MetaType &gt; &amp;results)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p547641006083932"><a name="p547641006083932"></a><a name="p547641006083932"></a>关闭metadata上报开关。 <a href="_camera.md#ga68fd022b82dfba6d9431220faf9856bd">更多...</a></p>
</td>
</tr>
<tr id="row781074845083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1037625562083932"><a name="p1037625562083932"></a><a name="p1037625562083932"></a><a href="_camera.md#gadb49d58d852fb9edba89fd496c6a907b">Close</a> ()=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p964985918083932"><a name="p964985918083932"></a><a name="p964985918083932"></a>关闭Camera设备。 <a href="_camera.md#gadb49d58d852fb9edba89fd496c6a907b">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section1838491315618"></a>

Camera设备操作。

