# AudioPortCap<a name="ZH-CN_TOPIC_0000001291040556"></a>

## **概述**<a name="section843049202083931"></a>

**所属模块:**

[Codec](_codec.md)

## **汇总**<a name="section707603267083931"></a>

## Public 属性<a name="pub-attribs"></a>

<a name="table333841872083931"></a>
<table><thead align="left"><tr id="row49293889083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2002899292083931"><a name="p2002899292083931"></a><a name="p2002899292083931"></a>Public 属性</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1729132679083931"><a name="p1729132679083931"></a><a name="p1729132679083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row288138440083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2120593519083931"><a name="p2120593519083931"></a><a name="p2120593519083931"></a><a href="_audio_port_cap.md#a41697a35137464c8a614e10a8e7ac4c5">sampleFormats</a> [<a href="_codec.md#ga9bda75c363e9bcff915cdd521dd7ba84">SAMPLE_FMT_NUM</a>]</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry2015437056083931p0"><a name="entry2015437056083931p0"></a><a name="entry2015437056083931p0"></a>支持的音频采样格式，详见<a href="_codec.md#ga97cfd5633b2133e7ebe42dbb9b03e757">AudioSampleFormat</a>。</p>
</td>
</tr>
<tr id="row1904672689083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2000224586083931"><a name="p2000224586083931"></a><a name="p2000224586083931"></a><a href="_audio_port_cap.md#af5959ad491cbeb74fc455ae5a8a68941">sampleRate</a> [<a href="_codec.md#ga0d905eaa05b4b6fcec76924eb795d7fe">SAMPLE_RATE_NUM</a>]</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1498230461083931p0"><a name="entry1498230461083931p0"></a><a name="entry1498230461083931p0"></a>支持的音频采样率，详见<a href="_codec.md#gaa0280074adafe6d2581d31f71512b842">AudioSampleRate</a>。</p>
</td>
</tr>
<tr id="row1485045580083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2038141846083931"><a name="p2038141846083931"></a><a name="p2038141846083931"></a><a href="_audio_port_cap.md#abc672e1fb2e2c4b6f684130a68e45213">channelLayouts</a> [<a href="_codec.md#ga6511732d5b29a6781cf38783157f21e1">CHANNEL_NUM</a>]</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1109605671083931p0"><a name="entry1109605671083931p0"></a><a name="entry1109605671083931p0"></a>支持的音频通道数channel layouts。</p>
</td>
</tr>
<tr id="row1693416342083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p818294877083931"><a name="p818294877083931"></a><a name="p818294877083931"></a><a href="_audio_port_cap.md#ad7a55b2ad64e90082c1f13ddbfa70913">channelCount</a> [<a href="_codec.md#ga6511732d5b29a6781cf38783157f21e1">CHANNEL_NUM</a>]</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry952458205083931p0"><a name="entry952458205083931p0"></a><a name="entry952458205083931p0"></a>支持的音频通道数。</p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section18161004083931"></a>

定义音频编解码能力。

## **类成员变量说明**<a name="section939088493083931"></a>

## channelCount<a name="ad7a55b2ad64e90082c1f13ddbfa70913"></a>

```
int32_t AudioPortCap::channelCount[CHANNEL_NUM]
```

**描述：**

支持的音频通道数

## channelLayouts<a name="abc672e1fb2e2c4b6f684130a68e45213"></a>

```
int32_t AudioPortCap::channelLayouts[CHANNEL_NUM]
```

**描述：**

支持的音频通道数channel layouts

## sampleFormats<a name="a41697a35137464c8a614e10a8e7ac4c5"></a>

```
int32_t AudioPortCap::sampleFormats[SAMPLE_FMT_NUM]
```

**描述：**

支持的音频采样格式，详见[AudioSampleFormat](_codec.md#ga97cfd5633b2133e7ebe42dbb9b03e757)

## sampleRate<a name="af5959ad491cbeb74fc455ae5a8a68941"></a>

```
int32_t AudioPortCap::sampleRate[SAMPLE_RATE_NUM]
```

**描述：**

支持的音频采样率，详见[AudioSampleRate](_codec.md#gaa0280074adafe6d2581d31f71512b842)

