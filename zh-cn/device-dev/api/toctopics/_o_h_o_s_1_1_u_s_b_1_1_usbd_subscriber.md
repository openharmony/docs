# OHOS::USB::UsbdSubscriber<a name="ZH-CN_TOPIC_0000001343120365"></a>

## **概述**<a name="section2097824945083932"></a>

**所属模块:**

[USB](_u_s_b.md)

## **汇总**<a name="section763233319083932"></a>

## Public 成员函数<a name="pub-methods"></a>

<a name="table275416462083932"></a>
<table><thead align="left"><tr id="row1826976580083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p621974184083932"><a name="p621974184083932"></a><a name="p621974184083932"></a>Public 成员函数</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p298907518083932"><a name="p298907518083932"></a><a name="p298907518083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row642155143083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p625560399083932"><a name="p625560399083932"></a><a name="p625560399083932"></a><a href="_u_s_b.md#gacf2831a8da732d14ff05474354f36c9c">DeviceEvent</a> (const <a href="_o_h_o_s_1_1_u_s_b_1_1_usb_info.md">UsbInfo</a> &amp;info)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1399481852083932"><a name="p1399481852083932"></a><a name="p1399481852083932"></a>设备事件。 <a href="_u_s_b.md#gacf2831a8da732d14ff05474354f36c9c">更多...</a></p>
</td>
</tr>
<tr id="row2049826467083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1154908558083932"><a name="p1154908558083932"></a><a name="p1154908558083932"></a><a href="_u_s_b.md#ga7a8e3586b1466ba417c9075b66871eed">PortChangedEvent</a> (int32_t portId, int32_t powerRole, int32_t dataRole, int32_t mode)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p663572675083932"><a name="p663572675083932"></a><a name="p663572675083932"></a>端口改变事件。 <a href="_u_s_b.md#ga7a8e3586b1466ba417c9075b66871eed">更多...</a></p>
</td>
</tr>
<tr id="row131381266083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p120045815083932"><a name="p120045815083932"></a><a name="p120045815083932"></a><a href="_u_s_b.md#ga74912415049f54b0a1bfdaa3660078bf">OnRemoteRequest</a> (uint32_t code, MessageParcel &amp;data, MessageParcel &amp;reply, MessageOption &amp;option) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p918457147083932"><a name="p918457147083932"></a><a name="p918457147083932"></a>远程请求。 <a href="_u_s_b.md#ga74912415049f54b0a1bfdaa3660078bf">更多...</a></p>
</td>
</tr>
</tbody>
</table>

