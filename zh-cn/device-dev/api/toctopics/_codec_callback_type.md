# CodecCallbackType<a name="ZH-CN_TOPIC_0000001343200725"></a>

## **概述**<a name="section180254974083931"></a>

**所属模块:**

[Codec](_codec.md)

## **汇总**<a name="section593043531083931"></a>

## Public 属性<a name="pub-attribs"></a>

<a name="table760268561083931"></a>
<table><thead align="left"><tr id="row181006424083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p696502968083931"><a name="p696502968083931"></a><a name="p696502968083931"></a>Public 属性</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p702986692083931"><a name="p702986692083931"></a><a name="p702986692083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row683607181083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p288064300083931"><a name="p288064300083931"></a><a name="p288064300083931"></a><a href="_codec.md#ga87a06c761822600a47770ef0586d550e">remote</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1531397824083931"><a name="p1531397824083931"></a><a name="p1531397824083931"></a>指向HdfRemoteService的指针。 <a href="_codec.md#ga87a06c761822600a47770ef0586d550e">更多...</a></p>
</td>
</tr>
<tr id="row1732709239083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1042927523083931"><a name="p1042927523083931"></a><a name="p1042927523083931"></a>( <a href="_codec.md#ga0efa14d0fda8a48b6da678b2634720f4">EventHandler</a> )(struct <a href="_codec_callback_type.md">CodecCallbackType</a> *self, enum OMX_EVENTTYPE event, struct <a href="_event_info.md">EventInfo</a> *info)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p452773934083931"><a name="p452773934083931"></a><a name="p452773934083931"></a>事件上报。 <a href="_codec.md#ga0efa14d0fda8a48b6da678b2634720f4">更多...</a></p>
</td>
</tr>
<tr id="row1330217173083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1476985464083931"><a name="p1476985464083931"></a><a name="p1476985464083931"></a>( <a href="_codec.md#gaf1112fd71b5a36c246e5ded83298f90e">EmptyBufferDone</a> )(struct <a href="_codec_callback_type.md">CodecCallbackType</a> *self, int8_t *appData, uint32_t appDataLen, const struct <a href="_omx_codec_buffer.md">OmxCodecBuffer</a> *buffer)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p927157441083931"><a name="p927157441083931"></a><a name="p927157441083931"></a>上报输入buffer编码或者解码处理完毕。 <a href="_codec.md#gaf1112fd71b5a36c246e5ded83298f90e">更多...</a></p>
</td>
</tr>
<tr id="row1160592426083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1483102527083931"><a name="p1483102527083931"></a><a name="p1483102527083931"></a>( <a href="_codec.md#ga5f9451090ac5d265e917df8048e9ed14">FillBufferDone</a> )(struct <a href="_codec_callback_type.md">CodecCallbackType</a> *self, int8_t *appData, uint32_t appDataLen, struct <a href="_omx_codec_buffer.md">OmxCodecBuffer</a> *buffer)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1707010475083931"><a name="p1707010475083931"></a><a name="p1707010475083931"></a>上报输出buffer填充完毕。 <a href="_codec.md#ga5f9451090ac5d265e917df8048e9ed14">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section2090894927083931"></a>

Codec回调接口定义。

提供了以下3种回调函数:

-   组件错误事件、命令完成事件、端口设置等事件回调，详见EventHandler。
-   输入端口处理完buffer回调，详见EmptyBufferDone。
-   输出端口填充完buffer回调，详见FillBufferDone。 通过以下两种方式注册回调:
-   创建组件时，通过CreateComponent方法。
-   当组件处于OMX\_StateLoaded状态时，通过SetCallbacks方法注册回调。

