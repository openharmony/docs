# codec\_common\_type.h<a name="ZH-CN_TOPIC_0000001290561128"></a>

## **概述**<a name="section1420719827083931"></a>

**所属模块:**

[Codec](_codec.md)

## **汇总**<a name="section1187802163083931"></a>

## 类<a name="nested-classes"></a>

<a name="table532060211083931"></a>
<table><thead align="left"><tr id="row1701852058083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1193077249083931"><a name="p1193077249083931"></a><a name="p1193077249083931"></a>类</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1928510140083931"><a name="p1928510140083931"></a><a name="p1928510140083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1989869506083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p867615439083931"><a name="p867615439083931"></a><a name="p867615439083931"></a><a href="_alignment.md">Alignment</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1552780288083931"><a name="p1552780288083931"></a><a name="p1552780288083931"></a>对齐结构定义，包含宽高的对齐值 <a href="_alignment.md">更多...</a></p>
</td>
</tr>
<tr id="row2082731578083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1706669023083931"><a name="p1706669023083931"></a><a name="p1706669023083931"></a><a href="_rect.md">Rect</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1153113688083931"><a name="p1153113688083931"></a><a name="p1153113688083931"></a>矩形的定义 <a href="_rect.md">更多...</a></p>
</td>
</tr>
<tr id="row2039328627083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p673054246083931"><a name="p673054246083931"></a><a name="p673054246083931"></a><a href="_range_value.md">RangeValue</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p145894295083931"><a name="p145894295083931"></a><a name="p145894295083931"></a>取值范围的定义 <a href="_range_value.md">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## 枚举<a name="enum-members"></a>

<a name="table1049237727083931"></a>
<table><thead align="left"><tr id="row1561517057083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p731679420083931"><a name="p731679420083931"></a><a name="p731679420083931"></a>枚举</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p780310974083931"><a name="p780310974083931"></a><a name="p780310974083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1673859201083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p420067167083931"><a name="p420067167083931"></a><a name="p420067167083931"></a><a href="_codec.md#ga03b4b6ae5fb82af68d46aaea3d3e4d79">CodecType</a> {   <a href="_codec.md#gga03b4b6ae5fb82af68d46aaea3d3e4d79a19c3c7765c55583a64e21938e2439261">VIDEO_DECODER</a>, <a href="_codec.md#gga03b4b6ae5fb82af68d46aaea3d3e4d79ad8044bc5b7d871723be90b5b6a094992">VIDEO_ENCODER</a>, <a href="_codec.md#gga03b4b6ae5fb82af68d46aaea3d3e4d79ae4ade329585f6c202847138e3f9cd4a4">AUDIO_DECODER</a>, <a href="_codec.md#gga03b4b6ae5fb82af68d46aaea3d3e4d79a7f7f3d3880168089c1de6d1ebc3dbb54">AUDIO_ENCODER</a>,   <a href="_codec.md#gga03b4b6ae5fb82af68d46aaea3d3e4d79a7314b0d0e4638eaaeb8690b8555a6546">INVALID_TYPE</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p20276589083931"><a name="p20276589083931"></a><a name="p20276589083931"></a>枚举编解码的类型 <a href="_codec.md#ga03b4b6ae5fb82af68d46aaea3d3e4d79">更多...</a></p>
</td>
</tr>
<tr id="row1296377973083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p690028847083931"><a name="p690028847083931"></a><a name="p690028847083931"></a><a href="_codec.md#ga85b10143618f300ff4f5bc6d45c72c01">Profile</a> {   <a href="_codec.md#gga85b10143618f300ff4f5bc6d45c72c01a6d67944b4958ad33b0eeb851bbcd169f">INVALID_PROFILE</a> = 0, <a href="_codec.md#gga85b10143618f300ff4f5bc6d45c72c01ad91765d6dcad7253a924d3cb30501e44">AAC_LC_PROFILE</a> = 0x1000, <a href="_codec.md#gga85b10143618f300ff4f5bc6d45c72c01aada4d857818cd9aa1ad62cdf608dab6b">AAC_MAIN_PROFILE</a>, <a href="_codec.md#gga85b10143618f300ff4f5bc6d45c72c01ab4255dc0e7450af4f526b85acbabfd3e">AAC_HE_V1_PROFILE</a>,   <a href="_codec.md#gga85b10143618f300ff4f5bc6d45c72c01a9b54f7a8c45ea6d4804133d8de4b8dd8">AAC_HE_V2_PROFILE</a>, <a href="_codec.md#gga85b10143618f300ff4f5bc6d45c72c01afaaacd4f6bdadac28b5cf49ae8f8470a">AAC_LD_PROFILE</a>, <a href="_codec.md#gga85b10143618f300ff4f5bc6d45c72c01a7c8028283d1ff60e486b3305bf8c1adc">AAC_ELD_PROFILE</a>, <a href="_codec.md#gga85b10143618f300ff4f5bc6d45c72c01a5bab002f00d3d7281aedc4807123a47a">AVC_BASELINE_PROFILE</a> = 0x2000,   <a href="_codec.md#gga85b10143618f300ff4f5bc6d45c72c01a323c1d6e02363f1717f7e6b33fd9a646">AVC_MAIN_PROFILE</a>, <a href="_codec.md#gga85b10143618f300ff4f5bc6d45c72c01ab9406e6bf30a0c128c3639cce51fe246">AVC_HIGH_PROFILE</a>, <a href="_codec.md#gga85b10143618f300ff4f5bc6d45c72c01ae0d37dc2c7d39753a80f6e0ba64e5e22">HEVC_MAIN_PROFILE</a> = 0x3000, <a href="_codec.md#gga85b10143618f300ff4f5bc6d45c72c01a811b9e02d8b0afa93e7ab8d2aa7e5de6">HEVC_MAIN_10_PROFILE</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p500664636083931"><a name="p500664636083931"></a><a name="p500664636083931"></a>枚举Codec规格 <a href="_codec.md#ga85b10143618f300ff4f5bc6d45c72c01">更多...</a></p>
</td>
</tr>
<tr id="row622226143083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1496297988083931"><a name="p1496297988083931"></a><a name="p1496297988083931"></a><a href="_codec.md#gaa0280074adafe6d2581d31f71512b842">AudioSampleRate</a> {   <a href="_codec.md#ggaa0280074adafe6d2581d31f71512b842a65d5a1e4d1f048a33d29c9a3b6f540bd">AUD_SAMPLE_RATE_8000</a> = 8000, <a href="_codec.md#ggaa0280074adafe6d2581d31f71512b842ac8379e14b05cdac5edfcc931ac8b33a9">AUD_SAMPLE_RATE_12000</a> = 12000, <a href="_codec.md#ggaa0280074adafe6d2581d31f71512b842a57b1853b1e309bf1aa5b3a35b06b0f81">AUD_SAMPLE_RATE_11025</a> = 11025, <a href="_codec.md#ggaa0280074adafe6d2581d31f71512b842a43395f0fe94ae2949778468e4488c3ee">AUD_SAMPLE_RATE_16000</a> = 16000,   <a href="_codec.md#ggaa0280074adafe6d2581d31f71512b842a5e8155ecfa865686a66e004e37ce1e54">AUD_SAMPLE_RATE_22050</a> = 22050, <a href="_codec.md#ggaa0280074adafe6d2581d31f71512b842abd4c09d52f3da25adb108e9aa503119d">AUD_SAMPLE_RATE_24000</a> = 24000, <a href="_codec.md#ggaa0280074adafe6d2581d31f71512b842a1f94827fe757ad2857d970638b6f8d66">AUD_SAMPLE_RATE_32000</a> = 32000, <a href="_codec.md#ggaa0280074adafe6d2581d31f71512b842ac880553f2ee154a240d9414598e006a2">AUD_SAMPLE_RATE_44100</a> = 44100,   <a href="_codec.md#ggaa0280074adafe6d2581d31f71512b842ade6dd509c28b66127c42d2634866b89c">AUD_SAMPLE_RATE_48000</a> = 48000, <a href="_codec.md#ggaa0280074adafe6d2581d31f71512b842a925218c15bb8522796e623a09d99dbc3">AUD_SAMPLE_RATE_64000</a> = 64000, <a href="_codec.md#ggaa0280074adafe6d2581d31f71512b842a48336a808a2ebcf5956995140e2d73dd">AUD_SAMPLE_RATE_96000</a> = 96000, <a href="_codec.md#ggaa0280074adafe6d2581d31f71512b842a0cb82ce52fb70b359a0b2232f7f465a2">AUD_SAMPLE_RATE_INVALID</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p245425770083931"><a name="p245425770083931"></a><a name="p245425770083931"></a>枚举音频采样率 <a href="_codec.md#gaa0280074adafe6d2581d31f71512b842">更多...</a></p>
</td>
</tr>
<tr id="row1116617022083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1065745090083931"><a name="p1065745090083931"></a><a name="p1065745090083931"></a><a href="_codec.md#ga9e2fbfb8a5881de2f495933f90f23b3f">CodecCapsMask</a> { <a href="_codec.md#gga9e2fbfb8a5881de2f495933f90f23b3fa30c688a80d3e64a3f5c2a13da89eef3c">CODEC_CAP_ADAPTIVE_PLAYBACK</a> = 0x1, <a href="_codec.md#gga9e2fbfb8a5881de2f495933f90f23b3fa33911c21f51bcd1980645cac6d0729ca">CODEC_CAP_SECURE_PLAYBACK</a> = 0x2, <a href="_codec.md#gga9e2fbfb8a5881de2f495933f90f23b3fa423e1b0d0a7dc9e4abeeded920aafb5b">CODEC_CAP_TUNNEL_PLAYBACK</a> = 0x4, <a href="_codec.md#gga9e2fbfb8a5881de2f495933f90f23b3fa0da8339e6a216573d7dc3b8d4380d96d">CODEC_CAP_MULTI_PLANE</a> = 0x10000 }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1893191836083931"><a name="p1893191836083931"></a><a name="p1893191836083931"></a>枚举播放能力 <a href="_codec.md#ga9e2fbfb8a5881de2f495933f90f23b3f">更多...</a></p>
</td>
</tr>
<tr id="row1221152519083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p117456880083931"><a name="p117456880083931"></a><a name="p117456880083931"></a><a href="_codec.md#ga5bec468886b760c542669b1615613dc4">CodecProcessMode</a> {   <a href="_codec.md#gga5bec468886b760c542669b1615613dc4a0324b4efc6d2095c788806bf387955fe">PROCESS_BLOCKING_INPUT_BUFFER</a> = 0X1, <a href="_codec.md#gga5bec468886b760c542669b1615613dc4acba39cb03563db7f38634009575fdc21">PROCESS_BLOCKING_OUTPUT_BUFFER</a> = 0X2, <a href="_codec.md#gga5bec468886b760c542669b1615613dc4a2ebd571bd15c86c289b04617e78584ec">PROCESS_BLOCKING_CONTROL_FLOW</a> = 0X4, <a href="_codec.md#gga5bec468886b760c542669b1615613dc4a73009c59abb2943e3363ad0aeefa81c1">PROCESS_NONBLOCKING_INPUT_BUFFER</a> = 0X100,   <a href="_codec.md#gga5bec468886b760c542669b1615613dc4ab943f6f6a762a47e663b74f42941fe9e">PROCESS_NONBLOCKING_OUTPUT_BUFFER</a> = 0X200, <a href="_codec.md#gga5bec468886b760c542669b1615613dc4a5421710be01e8656530fb22f39e766ea">PROCESS_NONBLOCKING_CONTROL_FLOW</a> = 0X400 }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p883038319083931"><a name="p883038319083931"></a><a name="p883038319083931"></a>枚举编解码处理模式 <a href="_codec.md#ga5bec468886b760c542669b1615613dc4">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section1937267825083931"></a>

Codec模块接口定义中使用的自定义数据类型。

Codec模块接口定义中使用的自定义数据类型，包括编解码类型、音视频参数、buffer定义等。

**Since：**

3.1

**Version：**

2.0

