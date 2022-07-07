# OHOS::Camera::IOfflineStreamOperator<a name="ZH-CN_TOPIC_0000001290840952"></a>

## **概述**<a name="section2089647566083932"></a>

**所属模块:**

[Camera](_camera.md)

## **汇总**<a name="section2102902109083932"></a>

## Public 成员函数<a name="pub-methods"></a>

<a name="table1837998429083932"></a>
<table><thead align="left"><tr id="row1991604943083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p596722862083932"><a name="p596722862083932"></a><a name="p596722862083932"></a>Public 成员函数</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1604695537083932"><a name="p1604695537083932"></a><a name="p1604695537083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1483166541083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p501506199083932"><a name="p501506199083932"></a><a name="p501506199083932"></a><strong id="b1435811742083932"><a name="b1435811742083932"></a><a name="b1435811742083932"></a>DECLARE_INTERFACE_DESCRIPTOR</strong> (u"HDI.Camera.V1_0.OfflineStreamOperator")</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p725971119211"><a name="p725971119211"></a><a name="p725971119211"></a>IPC通信token校验。</p>
</td>
</tr>
<tr id="row687835508083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1855495994083932"><a name="p1855495994083932"></a><a name="p1855495994083932"></a><a href="_camera.md#ga83a9be20ab64cc481c0e5403e1873a10">CancelCapture</a> (int captureId)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p378770972083932"><a name="p378770972083932"></a><a name="p378770972083932"></a>取消捕获请求。 <a href="_camera.md#ga83a9be20ab64cc481c0e5403e1873a10">更多...</a></p>
</td>
</tr>
<tr id="row226890679083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2119161829083932"><a name="p2119161829083932"></a><a name="p2119161829083932"></a><a href="_camera.md#ga21d854d9b73f4417a4d30e508b32df1c">ReleaseStreams</a> (const std::vector&lt; int &gt; &amp;streamIds)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1010877092083932"><a name="p1010877092083932"></a><a name="p1010877092083932"></a>释放离线流。 <a href="_camera.md#ga21d854d9b73f4417a4d30e508b32df1c">更多...</a></p>
</td>
</tr>
<tr id="row1818655948083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p854835884083932"><a name="p854835884083932"></a><a name="p854835884083932"></a><a href="_camera.md#ga94f3df7ad19a986a821202bb2f6f9697">Release</a> ()=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p258302100083932"><a name="p258302100083932"></a><a name="p258302100083932"></a>释放所有离线流。 <a href="_camera.md#ga94f3df7ad19a986a821202bb2f6f9697">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section1838491315618"></a>

离线流的操作类。

