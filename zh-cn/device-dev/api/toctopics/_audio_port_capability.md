# AudioPortCapability<a name="ZH-CN_TOPIC_0000001343200717"></a>

## **概述**<a name="section1836007755083931"></a>

**所属模块:**

[Audio](_audio.md)

## **汇总**<a name="section931494260083931"></a>

## Public 属性<a name="pub-attribs"></a>

<a name="table324421111083931"></a>
<table><thead align="left"><tr id="row1871828882083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p37983515083931"><a name="p37983515083931"></a><a name="p37983515083931"></a>Public 属性</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1615647162083931"><a name="p1615647162083931"></a><a name="p1615647162083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row2083858200083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1336005325083931"><a name="p1336005325083931"></a><a name="p1336005325083931"></a><a href="_audio.md#ga826a77349d0acf2fa328afa778a4ffaa">deviceType</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1206673478083931p0"><a name="entry1206673478083931p0"></a><a name="entry1206673478083931p0"></a>设备输出、输入类型。</p>
</td>
</tr>
<tr id="row110814668083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p351855904083931"><a name="p351855904083931"></a><a name="p351855904083931"></a><a href="_audio.md#gab3b27f40121441aa52e1d98d78284ed6">deviceId</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1658187264083931"><a name="p1658187264083931"></a><a name="p1658187264083931"></a>绑定（bind）设备ID，唯一的设备识别符。</p>
</td>
</tr>
<tr id="row117408198083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2128086413083931"><a name="p2128086413083931"></a><a name="p2128086413083931"></a><a href="_audio.md#ga377ecdaf229087a7d17c220a65a7162f">hardwareMode</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p134581906083931"><a name="p134581906083931"></a><a name="p134581906083931"></a>是否支持设备绑定处理。</p>
</td>
</tr>
<tr id="row902413013083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p363293807083931"><a name="p363293807083931"></a><a name="p363293807083931"></a><a href="_audio.md#ga76561b05a62a2209dfea917c5e20e61b">formatNum</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry169306823083931p0"><a name="entry169306823083931p0"></a><a name="entry169306823083931p0"></a>支持的音频格式数目。</p>
</td>
</tr>
<tr id="row620608510083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1681073229083931"><a name="p1681073229083931"></a><a name="p1681073229083931"></a><a href="_audio.md#gad01bfa329a21628287ee21df5000e34d">formats</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1354817175083931"><a name="p1354817175083931"></a><a name="p1354817175083931"></a>支持的音频格式，详情参考<a href="_audio.md#ga98d5d077cca088ddf77314871474fe59">AudioFormat</a>。</p>
</td>
</tr>
<tr id="row1846485753083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2095993717083931"><a name="p2095993717083931"></a><a name="p2095993717083931"></a><a href="_audio.md#gab51ab0e0cb44a850a400d1c1647a3987">sampleRateMasks</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry371514619083931p0"><a name="entry371514619083931p0"></a><a name="entry371514619083931p0"></a>支持的音频采样频率（8k、16k、32k、48k）。</p>
</td>
</tr>
<tr id="row408899761083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1893511207083931"><a name="p1893511207083931"></a><a name="p1893511207083931"></a><a href="_audio.md#ga357e90ee8116e04144f57e6f7d3d9efb">channelMasks</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1551548869083931p0"><a name="entry1551548869083931p0"></a><a name="entry1551548869083931p0"></a>设备的声道布局掩码（mask），详情参考<a href="_audio.md#ga137eb03027d5947ea294b32f5095b83c">AudioChannelMask</a>。</p>
</td>
</tr>
<tr id="row1228017637083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1811646856083931"><a name="p1811646856083931"></a><a name="p1811646856083931"></a><a href="_audio.md#gab7efb55d59b00bf85033cd52f0772b96">channelCount</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p624949583083931"><a name="p624949583083931"></a><a name="p624949583083931"></a>支持的最大声道总数。</p>
</td>
</tr>
<tr id="row1039684298083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1201737470083931"><a name="p1201737470083931"></a><a name="p1201737470083931"></a><a href="_audio.md#ga1e34f5db33d02dbdd81090a51d28306d">subPortsNum</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1439320097083931p0"><a name="entry1439320097083931p0"></a><a name="entry1439320097083931p0"></a>支持的子端口数目（仅用于输出设备）。</p>
</td>
</tr>
<tr id="row441678488083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1859930517083931"><a name="p1859930517083931"></a><a name="p1859930517083931"></a><a href="_audio.md#gaccd18b70e7d121169f3df5e53fe055f9">subPorts</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1370924519083931p0"><a name="entry1370924519083931p0"></a><a name="entry1370924519083931p0"></a>支持的子端口列表。</p>
</td>
</tr>
<tr id="row1571475109083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1830594021083931"><a name="p1830594021083931"></a><a name="p1830594021083931"></a><a href="_audio.md#ga299b10cbeed72f805c909cd730a28017">supportSampleFormatNum</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1710968157083931"><a name="p1710968157083931"></a><a name="p1710968157083931"></a>支持的音频样本格式数量。</p>
</td>
</tr>
<tr id="row1316637094083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1690803849083931"><a name="p1690803849083931"></a><a name="p1690803849083931"></a><a href="_audio.md#gae33cb5df2a7b30ae2d2581f64d75f186">supportSampleFormats</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry264037215083931p0"><a name="entry264037215083931p0"></a><a name="entry264037215083931p0"></a>支持的音频样本格式，详请参考<a href="_codec.md#ga97cfd5633b2133e7ebe42dbb9b03e757">AudioSampleFormat</a>。</p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section380146136083931"></a>

音频端口的支持能力。

