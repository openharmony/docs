# AudioScene<a name="ZH-CN_TOPIC_0000001290561156"></a>

## **概述**<a name="section1390110427083931"></a>

**所属模块:**

[Audio](_audio.md)

## **汇总**<a name="section676143427083931"></a>

## Public 属性<a name="pub-attribs"></a>

<a name="table1548968283083931"></a>
<table><thead align="left"><tr id="row508960140083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p131963679083931"><a name="p131963679083931"></a><a name="p131963679083931"></a>Public 属性</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p308318785083931"><a name="p308318785083931"></a><a name="p308318785083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1905741580083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1774249476083931"><a name="p1774249476083931"></a><a name="p1774249476083931"></a>( <a href="_audio_scene.md#a9b485404b2ec3b8bc2b8d1b73401d45c">CheckSceneCapability</a> )(<a href="_audio.md#ga18675ddb073465fdeac33a897f675d79">AudioHandle</a> handle, const struct <a href="_audio_scene_descriptor.md">AudioSceneDescriptor</a> *scene, bool *supported)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1102978490083931"><a name="p1102978490083931"></a><a name="p1102978490083931"></a>是否支持某个音频场景的配置 <a href="_audio_scene.md#a9b485404b2ec3b8bc2b8d1b73401d45c">更多...</a></p>
</td>
</tr>
<tr id="row618486432083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p903615294083931"><a name="p903615294083931"></a><a name="p903615294083931"></a>( <a href="_audio_scene.md#aacdbf3a9f488a7e71f3a5a23c68c0068">SelectScene</a> )(<a href="_audio.md#ga18675ddb073465fdeac33a897f675d79">AudioHandle</a> handle, const struct <a href="_audio_scene_descriptor.md">AudioSceneDescriptor</a> *scene)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p590566994083931"><a name="p590566994083931"></a><a name="p590566994083931"></a>选择音频场景 <a href="_audio_scene.md#aacdbf3a9f488a7e71f3a5a23c68c0068">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section168644445083931"></a>

AudioScene音频场景接口。

提供音频播放（render）或录音（capture）需要的公共场景驱动能力，包括选择音频场景等。

**Since：**

1.0

**Version：**

1.0

## **类成员变量说明**<a name="section105423886083931"></a>

## CheckSceneCapability<a name="a9b485404b2ec3b8bc2b8d1b73401d45c"></a>

```
int32_t(* AudioScene::CheckSceneCapability) (AudioHandle handle, const struct AudioSceneDescriptor *scene, bool *supported)
```

**描述：**

是否支持某个音频场景的配置

**参数：**

<a name="table1809610754083931"></a>
<table><thead align="left"><tr id="row1032477485083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p744129620083931"><a name="p744129620083931"></a><a name="p744129620083931"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p501318274083931"><a name="p501318274083931"></a><a name="p501318274083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1768129242083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2022172902083931p0"><a name="entry2022172902083931p0"></a><a name="entry2022172902083931p0"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1411865835083931p0"><a name="entry1411865835083931p0"></a><a name="entry1411865835083931p0"></a>待操作的音频句柄</p>
</td>
</tr>
<tr id="row1721789949083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1273165653083931p0"><a name="entry1273165653083931p0"></a><a name="entry1273165653083931p0"></a>scene</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1065246657083931p0"><a name="entry1065246657083931p0"></a><a name="entry1065246657083931p0"></a>待获取的音频场景描述符</p>
</td>
</tr>
<tr id="row105909782083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1116605968083931p0"><a name="entry1116605968083931p0"></a><a name="entry1116605968083931p0"></a>supported</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1971299547083931p0"><a name="entry1971299547083931p0"></a><a name="entry1971299547083931p0"></a>是否支持的状态保存到supported中，true表示支持，false表示不支持</p>
</td>
</tr>
</tbody>
</table>

**返回：**

成功返回值0，失败返回负值

**参见：**

[SelectScene](_audio_scene.md#aacdbf3a9f488a7e71f3a5a23c68c0068)

## SelectScene<a name="aacdbf3a9f488a7e71f3a5a23c68c0068"></a>

```
int32_t(* AudioScene::SelectScene) (AudioHandle handle, const struct AudioSceneDescriptor *scene)
```

**描述：**

选择音频场景

1.  选择一个非常具体的音频场景（应用场景和输出设备的组合），例如同样是使用手机中的喇叭作为输出设备
    -   在媒体播放场景scene为media\_speaker
    -   在语音通话免提场景scene为voice\_speaker

2.  只是选择一个音频场景，例如使用场景为媒体播放（media）、电影播放（movie）、游戏播放（game）
3.  只是选择一个音频输出设备，例如输出设备为听筒（receiver）、喇叭（speaker）、有线耳机（headset）

**参数：**

<a name="table1192730941083931"></a>
<table><thead align="left"><tr id="row428808779083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1021174700083931"><a name="p1021174700083931"></a><a name="p1021174700083931"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p845913000083931"><a name="p845913000083931"></a><a name="p845913000083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1610798110083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry249214317083931p0"><a name="entry249214317083931p0"></a><a name="entry249214317083931p0"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1852541812083931p0"><a name="entry1852541812083931p0"></a><a name="entry1852541812083931p0"></a>待操作的音频句柄</p>
</td>
</tr>
<tr id="row1125494564083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1945229072083931p0"><a name="entry1945229072083931p0"></a><a name="entry1945229072083931p0"></a>scene</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry556329364083931p0"><a name="entry556329364083931p0"></a><a name="entry556329364083931p0"></a>待设置的音频场景描述符</p>
</td>
</tr>
</tbody>
</table>

**返回：**

成功返回值0，失败返回负值

**参见：**

[CheckSceneCapability](_audio_scene.md#a9b485404b2ec3b8bc2b8d1b73401d45c)

