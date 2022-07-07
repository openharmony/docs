# OHOS::Camera::IStreamOperator<a name="ZH-CN_TOPIC_0000001343120361"></a>

## **概述**<a name="section244864783083932"></a>

**所属模块:**

[Camera](_camera.md)

## **汇总**<a name="section1570026444083932"></a>

## Public 成员函数<a name="pub-methods"></a>

<a name="table1477875093083932"></a>
<table><thead align="left"><tr id="row316721325083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2138268361083932"><a name="p2138268361083932"></a><a name="p2138268361083932"></a>Public 成员函数</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p630497257083932"><a name="p630497257083932"></a><a name="p630497257083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1565010370083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p872227181083932"><a name="p872227181083932"></a><a name="p872227181083932"></a><strong id="b1544697058083932"><a name="b1544697058083932"></a><a name="b1544697058083932"></a>DECLARE_INTERFACE_DESCRIPTOR</strong> (u"HDI.Camera.V1_0.StreamOperator")</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry425252750083932p0"><a name="entry425252750083932p0"></a><a name="entry425252750083932p0"></a>IPC通信token校验。</p>
</td>
</tr>
<tr id="row524606302083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p278941395083932"><a name="p278941395083932"></a><a name="p278941395083932"></a><a href="_camera.md#ga2ebad5dbf7873a2b3ab27900c4f5b0a7">IsStreamsSupported</a> (<a href="_camera.md#gac397708a7aefbcf48c8a32b8af367ffd">OperationMode</a> mode, const std::shared_ptr&lt; CameraMetadata &gt; &amp;modeSetting, const std::vector&lt; std::shared_ptr&lt; <a href="_o_h_o_s_1_1_camera_1_1_stream_info.md">StreamInfo</a> &gt;&gt; &amp;info, <a href="_camera.md#ga2de5b91b51f744902c071f89d9302d56">StreamSupportType</a> &amp;type)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p334940935083932"><a name="p334940935083932"></a><a name="p334940935083932"></a>查询是否支持添加参数对应的流 <a href="_camera.md#ga2ebad5dbf7873a2b3ab27900c4f5b0a7">更多...</a></p>
</td>
</tr>
<tr id="row2017577584083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p732402231083932"><a name="p732402231083932"></a><a name="p732402231083932"></a><a href="_camera.md#gac16ffa2d2f81bb62eb9ce556a0293c71">CreateStreams</a> (const std::vector&lt; std::shared_ptr&lt; <a href="_o_h_o_s_1_1_camera_1_1_stream_info.md">StreamInfo</a> &gt;&gt; &amp;streamInfos)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1922105795083932"><a name="p1922105795083932"></a><a name="p1922105795083932"></a>创建流。 <a href="_camera.md#gac16ffa2d2f81bb62eb9ce556a0293c71">更多...</a></p>
</td>
</tr>
<tr id="row935786603083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p220172890083932"><a name="p220172890083932"></a><a name="p220172890083932"></a><a href="_camera.md#ga02abdd9797d1464a0adddf750a9b1eaf">ReleaseStreams</a> (const std::vector&lt; int &gt; &amp;streamIds)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1741813492083932"><a name="p1741813492083932"></a><a name="p1741813492083932"></a>释放流。 <a href="_camera.md#ga02abdd9797d1464a0adddf750a9b1eaf">更多...</a></p>
</td>
</tr>
<tr id="row1332539334083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1300840208083932"><a name="p1300840208083932"></a><a name="p1300840208083932"></a><a href="_camera.md#gab94792910f425ade060edcda5c5706d1">CommitStreams</a> (<a href="_camera.md#gac397708a7aefbcf48c8a32b8af367ffd">OperationMode</a> mode, const std::shared_ptr&lt; CameraMetadata &gt; &amp;modeSetting)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p247790596083932"><a name="p247790596083932"></a><a name="p247790596083932"></a>配置流。 <a href="_camera.md#gab94792910f425ade060edcda5c5706d1">更多...</a></p>
</td>
</tr>
<tr id="row1145182027083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1549700531083932"><a name="p1549700531083932"></a><a name="p1549700531083932"></a><a href="_camera.md#gac10fdfea46cfb848faaf94c09456840d">GetStreamAttributes</a> (std::vector&lt; std::shared_ptr&lt; <a href="_o_h_o_s_1_1_camera_1_1_stream_attribute.md">StreamAttribute</a> &gt;&gt; &amp;attributes)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p63549536083932"><a name="p63549536083932"></a><a name="p63549536083932"></a>获取流的属性。 <a href="_camera.md#gac10fdfea46cfb848faaf94c09456840d">更多...</a></p>
</td>
</tr>
<tr id="row1245676570083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1223426129083932"><a name="p1223426129083932"></a><a name="p1223426129083932"></a><a href="_camera.md#gad17206bf96c260a9384f224d65a230af">AttachBufferQueue</a> (int streamId, const OHOS::sptr&lt; OHOS::IBufferProducer &gt; &amp;producer)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1604799339083932"><a name="p1604799339083932"></a><a name="p1604799339083932"></a>绑定生产者句柄和指定流。 <a href="_camera.md#gad17206bf96c260a9384f224d65a230af">更多...</a></p>
</td>
</tr>
<tr id="row2040427008083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1671806680083932"><a name="p1671806680083932"></a><a name="p1671806680083932"></a><a href="_camera.md#gaad1232a57faf5c55ecfdab1c04f98951">DetachBufferQueue</a> (int streamId)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1456028712083932"><a name="p1456028712083932"></a><a name="p1456028712083932"></a>解除生产者句柄和指定流的绑定关系。 <a href="_camera.md#gaad1232a57faf5c55ecfdab1c04f98951">更多...</a></p>
</td>
</tr>
<tr id="row682205652083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p274396032083932"><a name="p274396032083932"></a><a name="p274396032083932"></a><a href="_camera.md#ga9fb8042cb01262bc08da16159975cf50">Capture</a> (int captureId, const std::shared_ptr&lt; <a href="_o_h_o_s_1_1_camera_1_1_capture_info.md">CaptureInfo</a> &gt; &amp;info, bool isStreaming)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1796532507083932"><a name="p1796532507083932"></a><a name="p1796532507083932"></a>捕获图像。 <a href="_camera.md#ga9fb8042cb01262bc08da16159975cf50">更多...</a></p>
</td>
</tr>
<tr id="row1066845093083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1161735894083932"><a name="p1161735894083932"></a><a name="p1161735894083932"></a><a href="_camera.md#ga77100b740f501c309a573f9783313a61">CancelCapture</a> (int captureId)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1848310317083932"><a name="p1848310317083932"></a><a name="p1848310317083932"></a>取消捕获。 <a href="_camera.md#ga77100b740f501c309a573f9783313a61">更多...</a></p>
</td>
</tr>
<tr id="row1997832180083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p297630837083932"><a name="p297630837083932"></a><a name="p297630837083932"></a><a href="_camera.md#gab97102d0e2d5bc1008924581fa9526fc">ChangeToOfflineStream</a> (const std::vector&lt; int &gt; &amp;streamIds, OHOS::sptr&lt; <a href="_o_h_o_s_1_1_camera_1_1_i_stream_operator_callback.md">IStreamOperatorCallback</a> &gt; &amp;callback, OHOS::sptr&lt; <a href="_o_h_o_s_1_1_camera_1_1_i_offline_stream_operator.md">IOfflineStreamOperator</a> &gt; &amp;offlineOperator)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p161201305083932"><a name="p161201305083932"></a><a name="p161201305083932"></a>将指定流转换成离线流。 <a href="_camera.md#gab97102d0e2d5bc1008924581fa9526fc">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section1838491315618"></a>

流的操作类。

