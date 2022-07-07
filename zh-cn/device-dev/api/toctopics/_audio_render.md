# AudioRender<a name="ZH-CN_TOPIC_0000001290840904"></a>

## **概述**<a name="section1095172291083931"></a>

**所属模块:**

[Audio](_audio.md)

## **汇总**<a name="section1951983101083931"></a>

## Public 属性<a name="pub-attribs"></a>

<a name="table1965304896083931"></a>
<table><thead align="left"><tr id="row392818734083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p926839573083931"><a name="p926839573083931"></a><a name="p926839573083931"></a>Public 属性</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p641349292083931"><a name="p641349292083931"></a><a name="p641349292083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row963153193083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1855293694083931"><a name="p1855293694083931"></a><a name="p1855293694083931"></a><em id="a954721a6d70c6cc96d8a772740b5749b"><a name="a954721a6d70c6cc96d8a772740b5749b"></a><a name="a954721a6d70c6cc96d8a772740b5749b"></a></em>control</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1363136198083931"><a name="p1363136198083931"></a><a name="p1363136198083931"></a>音频控制能力接口，详情参考<a href="_audio_control.md">AudioControl</a></p>
</td>
</tr>
<tr id="row1581143140083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p14398145083931"><a name="p14398145083931"></a><a name="p14398145083931"></a><em id="a6933f5dbf34758cea050e2e5d25e69e6"><a name="a6933f5dbf34758cea050e2e5d25e69e6"></a><a name="a6933f5dbf34758cea050e2e5d25e69e6"></a></em>attr</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p75194939083931"><a name="p75194939083931"></a><a name="p75194939083931"></a>音频属性能力接口，详情参考<a href="_audio_attribute.md">AudioAttribute</a></p>
</td>
</tr>
<tr id="row1512217310083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p805713282083931"><a name="p805713282083931"></a><a name="p805713282083931"></a><em id="adcbcb3e0a5c11e507bbf2f9a8809b099"><a name="adcbcb3e0a5c11e507bbf2f9a8809b099"></a><a name="adcbcb3e0a5c11e507bbf2f9a8809b099"></a></em>scene</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1869171066083931"><a name="p1869171066083931"></a><a name="p1869171066083931"></a>音频场景能力接口，详情参考<a href="_audio_scene.md">AudioScene</a></p>
</td>
</tr>
<tr id="row843800949083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1568465270083931"><a name="p1568465270083931"></a><a name="p1568465270083931"></a><em id="aff73e1461efbc8b133418f0571f4b3a8"><a name="aff73e1461efbc8b133418f0571f4b3a8"></a><a name="aff73e1461efbc8b133418f0571f4b3a8"></a></em>volume</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1693253815083931"><a name="p1693253815083931"></a><a name="p1693253815083931"></a>音频音量能力接口，详情参考<a href="_audio_volume.md">AudioVolume</a></p>
</td>
</tr>
<tr id="row1881086046083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p83938289083931"><a name="p83938289083931"></a><a name="p83938289083931"></a>( <a href="_audio_render.md#a56dff6bbe1c5ac8361b2e3238ab09563">GetLatency</a> )(struct <a href="_audio_render.md">AudioRender</a> *render, uint32_t *ms)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p33217622083931"><a name="p33217622083931"></a><a name="p33217622083931"></a>获取音频硬件驱动估计的延迟时间 <a href="_audio_render.md#a56dff6bbe1c5ac8361b2e3238ab09563">更多...</a></p>
</td>
</tr>
<tr id="row666813322083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p30170392083931"><a name="p30170392083931"></a><a name="p30170392083931"></a>( <a href="_audio_render.md#a463cab04d0805a5c7b3ba5884c468246">RenderFrame</a> )(struct <a href="_audio_render.md">AudioRender</a> *render, const void *frame, uint64_t requestBytes, uint64_t *replyBytes)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1473825274083931"><a name="p1473825274083931"></a><a name="p1473825274083931"></a>往音频驱动中播放（render）一帧输出数据（放音，音频下行数据） <a href="_audio_render.md#a463cab04d0805a5c7b3ba5884c468246">更多...</a></p>
</td>
</tr>
<tr id="row1687330077083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p638444306083931"><a name="p638444306083931"></a><a name="p638444306083931"></a>( <a href="_audio_render.md#a24072bec0e2cd75727b57ec3e14f7ccb">GetRenderPosition</a> )(struct <a href="_audio_render.md">AudioRender</a> *render, uint64_t *frames, struct <a href="_audio_time_stamp.md">AudioTimeStamp</a> *time)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p785986826083931"><a name="p785986826083931"></a><a name="p785986826083931"></a>获取音频输出帧数的上一次计数 <a href="_audio_render.md#a24072bec0e2cd75727b57ec3e14f7ccb">更多...</a></p>
</td>
</tr>
<tr id="row115636252083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1513216636083931"><a name="p1513216636083931"></a><a name="p1513216636083931"></a>( <a href="_audio_render.md#a5589427ae5a4ba6a8d2a19dd8eddbcd8">SetRenderSpeed</a> )(struct <a href="_audio_render.md">AudioRender</a> *render, float speed)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1534226206083931"><a name="p1534226206083931"></a><a name="p1534226206083931"></a>设置一个音频的播放速度 <a href="_audio_render.md#a5589427ae5a4ba6a8d2a19dd8eddbcd8">更多...</a></p>
</td>
</tr>
<tr id="row465939463083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p860593368083931"><a name="p860593368083931"></a><a name="p860593368083931"></a>( <a href="_audio_render.md#af0a19dacb293d3fbe600902b93af1ee9">GetRenderSpeed</a> )(struct <a href="_audio_render.md">AudioRender</a> *render, float *speed)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p480032094083931"><a name="p480032094083931"></a><a name="p480032094083931"></a>获取一个音频当前的播放速度 <a href="_audio_render.md#af0a19dacb293d3fbe600902b93af1ee9">更多...</a></p>
</td>
</tr>
<tr id="row2081565147083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1509925979083931"><a name="p1509925979083931"></a><a name="p1509925979083931"></a>( <a href="_audio_render.md#ae5aad5b26ccdd65ba501620851c5ecec">SetChannelMode</a> )(struct <a href="_audio_render.md">AudioRender</a> *render, enum <a href="_audio.md#ga78aab1fafb9657451804e42b42897123">AudioChannelMode</a> mode)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1830467935083931"><a name="p1830467935083931"></a><a name="p1830467935083931"></a>设置音频播放的通道模式 <a href="_audio_render.md#ae5aad5b26ccdd65ba501620851c5ecec">更多...</a></p>
</td>
</tr>
<tr id="row825165306083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1504031052083931"><a name="p1504031052083931"></a><a name="p1504031052083931"></a>( <a href="_audio_render.md#aad3d5e4104167620eacb2ba23edce50e">GetChannelMode</a> )(struct <a href="_audio_render.md">AudioRender</a> *render, enum <a href="_audio.md#ga78aab1fafb9657451804e42b42897123">AudioChannelMode</a> *mode)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1688200259083931"><a name="p1688200259083931"></a><a name="p1688200259083931"></a>获取音频播放当前的通道模式 <a href="_audio_render.md#aad3d5e4104167620eacb2ba23edce50e">更多...</a></p>
</td>
</tr>
<tr id="row519812830083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p274342611083931"><a name="p274342611083931"></a><a name="p274342611083931"></a>( <a href="_audio_render.md#acb40275d0f402e8e38539e71f89f31a1">RegCallback</a> )(struct <a href="_audio_render.md">AudioRender</a> *render, <a href="_audio.md#ga72392c98621c7bf035e9907bb5547542">RenderCallback</a> callback, void *cookie)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p719599972083931"><a name="p719599972083931"></a><a name="p719599972083931"></a>注册音频回调函数，用于放音过程中缓冲区数据写、DrainBuffer完成通知 <a href="_audio_render.md#acb40275d0f402e8e38539e71f89f31a1">更多...</a></p>
</td>
</tr>
<tr id="row2140410181083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p344692283083931"><a name="p344692283083931"></a><a name="p344692283083931"></a>( <a href="_audio_render.md#aa210f1f9a656b386ea0fb74d8c7adf4a">DrainBuffer</a> )(struct <a href="_audio_render.md">AudioRender</a> *render, enum <a href="_audio.md#ga6359642a80d38bd309683186d904306d">AudioDrainNotifyType</a> *type)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1409875064083931"><a name="p1409875064083931"></a><a name="p1409875064083931"></a>排空缓冲区中的数据 <a href="_audio_render.md#aa210f1f9a656b386ea0fb74d8c7adf4a">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section203988883083931"></a>

AudioRender音频播放接口

提供音频播放支持的驱动能力，包括音频控制、音频属性、音频场景、音频音量、获取硬件延迟时间、播放音频帧数据（render frame）等

**参见：**

[AudioControl](_audio_control.md)

[AudioAttribute](_audio_attribute.md)

[AudioScene](_audio_scene.md)

[AudioVolume](_audio_volume.md)

**Since：**

1.0

**Version：**

1.0

## **类成员变量说明**<a name="section1766549767083931"></a>

## DrainBuffer<a name="aa210f1f9a656b386ea0fb74d8c7adf4a"></a>

```
int32_t(* AudioRender::DrainBuffer) (struct AudioRender *render, enum AudioDrainNotifyType *type)
```

**描述：**

排空缓冲区中的数据

**参数：**

<a name="table1103776991083931"></a>
<table><thead align="left"><tr id="row1190908166083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p185476520083931"><a name="p185476520083931"></a><a name="p185476520083931"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p409129425083931"><a name="p409129425083931"></a><a name="p409129425083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row652374756083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry679527344083931p0"><a name="entry679527344083931p0"></a><a name="entry679527344083931p0"></a>render</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry311407052083931p0"><a name="entry311407052083931p0"></a><a name="entry311407052083931p0"></a>待操作的音频播放接口对象</p>
</td>
</tr>
<tr id="row167530017083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry833408707083931p0"><a name="entry833408707083931p0"></a><a name="entry833408707083931p0"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry91697620083931p0"><a name="entry91697620083931p0"></a><a name="entry91697620083931p0"></a>DrainBuffer的操作类型，详情请参考<a href="_audio.md#ga6359642a80d38bd309683186d904306d">AudioDrainNotifyType</a></p>
</td>
</tr>
</tbody>
</table>

**返回：**

成功返回值0，失败返回负值

**参见：**

[RegCallback](_audio_render.md#acb40275d0f402e8e38539e71f89f31a1)

## GetChannelMode<a name="aad3d5e4104167620eacb2ba23edce50e"></a>

```
int32_t(* AudioRender::GetChannelMode) (struct AudioRender *render, enum AudioChannelMode *mode)
```

**描述：**

获取音频播放当前的通道模式

**参数：**

<a name="table551614281083931"></a>
<table><thead align="left"><tr id="row1718125782083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1332777547083931"><a name="p1332777547083931"></a><a name="p1332777547083931"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p459682800083931"><a name="p459682800083931"></a><a name="p459682800083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row300610195083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry993639149083931p0"><a name="entry993639149083931p0"></a><a name="entry993639149083931p0"></a>render</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry802332141083931p0"><a name="entry802332141083931p0"></a><a name="entry802332141083931p0"></a>待操作的音频播放接口对象</p>
</td>
</tr>
<tr id="row536002028083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2115946767083931p0"><a name="entry2115946767083931p0"></a><a name="entry2115946767083931p0"></a>mode</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry2024335221083931p0"><a name="entry2024335221083931p0"></a><a name="entry2024335221083931p0"></a>获取的通道模式保存到mode中</p>
</td>
</tr>
</tbody>
</table>

**返回：**

成功返回值0，失败返回负值

**参见：**

[SetChannelMode](_audio_render.md#ae5aad5b26ccdd65ba501620851c5ecec)

## GetLatency<a name="a56dff6bbe1c5ac8361b2e3238ab09563"></a>

```
int32_t(* AudioRender::GetLatency) (struct AudioRender *render, uint32_t *ms)
```

**描述：**

获取音频硬件驱动估计的延迟时间

**参数：**

<a name="table1537846459083931"></a>
<table><thead align="left"><tr id="row2035970622083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2034792047083931"><a name="p2034792047083931"></a><a name="p2034792047083931"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p972068763083931"><a name="p972068763083931"></a><a name="p972068763083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row590324004083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry509523605083931p0"><a name="entry509523605083931p0"></a><a name="entry509523605083931p0"></a>render</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1832496634083931p0"><a name="entry1832496634083931p0"></a><a name="entry1832496634083931p0"></a>待操作的音频播放接口对象</p>
</td>
</tr>
<tr id="row1480647947083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry86658779083931p0"><a name="entry86658779083931p0"></a><a name="entry86658779083931p0"></a>ms</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry505006205083931p0"><a name="entry505006205083931p0"></a><a name="entry505006205083931p0"></a>获取的延迟时间（单位：毫秒）保存到ms中</p>
</td>
</tr>
</tbody>
</table>

**返回：**

成功返回值0，失败返回负值

## GetRenderPosition<a name="a24072bec0e2cd75727b57ec3e14f7ccb"></a>

```
int32_t(* AudioRender::GetRenderPosition) (struct AudioRender *render, uint64_t *frames, struct AudioTimeStamp *time)
```

**描述：**

获取音频输出帧数的上一次计数

**参数：**

<a name="table480153135083931"></a>
<table><thead align="left"><tr id="row1561444702083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1087675857083931"><a name="p1087675857083931"></a><a name="p1087675857083931"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1969106687083931"><a name="p1969106687083931"></a><a name="p1969106687083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row60911093083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry118260392083931p0"><a name="entry118260392083931p0"></a><a name="entry118260392083931p0"></a>render</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1544061190083931p0"><a name="entry1544061190083931p0"></a><a name="entry1544061190083931p0"></a>待操作的音频播放接口对象</p>
</td>
</tr>
<tr id="row926171220083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry717384741083931p0"><a name="entry717384741083931p0"></a><a name="entry717384741083931p0"></a>frames</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry314123295083931p0"><a name="entry314123295083931p0"></a><a name="entry314123295083931p0"></a>获取的音频帧计数保存到frames中</p>
</td>
</tr>
<tr id="row1048577918083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1517819116083931p0"><a name="entry1517819116083931p0"></a><a name="entry1517819116083931p0"></a>time</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1366771627083931p0"><a name="entry1366771627083931p0"></a><a name="entry1366771627083931p0"></a>获取的关联时间戳保存到time中</p>
</td>
</tr>
</tbody>
</table>

**返回：**

成功返回值0，失败返回负值

**参见：**

[RenderFrame](_audio_render.md#a463cab04d0805a5c7b3ba5884c468246)

## GetRenderSpeed<a name="af0a19dacb293d3fbe600902b93af1ee9"></a>

```
int32_t(* AudioRender::GetRenderSpeed) (struct AudioRender *render, float *speed)
```

**描述：**

获取一个音频当前的播放速度

**参数：**

<a name="table391204161083931"></a>
<table><thead align="left"><tr id="row252251372083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1868099302083931"><a name="p1868099302083931"></a><a name="p1868099302083931"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p643878612083931"><a name="p643878612083931"></a><a name="p643878612083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row20498641083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry554610764083931p0"><a name="entry554610764083931p0"></a><a name="entry554610764083931p0"></a>render</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1805705110083931p0"><a name="entry1805705110083931p0"></a><a name="entry1805705110083931p0"></a>待操作的音频播放接口对象</p>
</td>
</tr>
<tr id="row2025956716083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1474439043083931p0"><a name="entry1474439043083931p0"></a><a name="entry1474439043083931p0"></a>speed</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1498060763083931p0"><a name="entry1498060763083931p0"></a><a name="entry1498060763083931p0"></a>获取的播放速度保存到speed中</p>
</td>
</tr>
</tbody>
</table>

**返回：**

成功返回值0，失败返回负值

**参见：**

[SetRenderSpeed](_audio_render.md#a5589427ae5a4ba6a8d2a19dd8eddbcd8)

## RegCallback<a name="acb40275d0f402e8e38539e71f89f31a1"></a>

```
int32_t(* AudioRender::RegCallback) (struct AudioRender *render, RenderCallback callback, void *cookie)
```

**描述：**

注册音频回调函数，用于放音过程中缓冲区数据写、DrainBuffer完成通知

**参数：**

<a name="table1843880429083931"></a>
<table><thead align="left"><tr id="row1983811614083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1316327358083931"><a name="p1316327358083931"></a><a name="p1316327358083931"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1543535625083931"><a name="p1543535625083931"></a><a name="p1543535625083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1524876748083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry89918125083931p0"><a name="entry89918125083931p0"></a><a name="entry89918125083931p0"></a>render</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry716974605083931p0"><a name="entry716974605083931p0"></a><a name="entry716974605083931p0"></a>待操作的音频播放接口对象</p>
</td>
</tr>
<tr id="row198783274083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry900540573083931p0"><a name="entry900540573083931p0"></a><a name="entry900540573083931p0"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry977456218083931p0"><a name="entry977456218083931p0"></a><a name="entry977456218083931p0"></a>注册的回调函数</p>
</td>
</tr>
<tr id="row619043854083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry247920973083931p0"><a name="entry247920973083931p0"></a><a name="entry247920973083931p0"></a>cookie</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1563947233083931p0"><a name="entry1563947233083931p0"></a><a name="entry1563947233083931p0"></a>回调函数的入参</p>
</td>
</tr>
</tbody>
</table>

**返回：**

成功返回值0，失败返回负值

**参见：**

[RegCallback](_audio_render.md#acb40275d0f402e8e38539e71f89f31a1)

## RenderFrame<a name="a463cab04d0805a5c7b3ba5884c468246"></a>

```
int32_t(* AudioRender::RenderFrame) (struct AudioRender *render, const void *frame, uint64_t requestBytes, uint64_t *replyBytes)
```

**描述：**

往音频驱动中播放（render）一帧输出数据（放音，音频下行数据）

**参数：**

<a name="table734611183083931"></a>
<table><thead align="left"><tr id="row1189155800083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p295043899083931"><a name="p295043899083931"></a><a name="p295043899083931"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p724253805083931"><a name="p724253805083931"></a><a name="p724253805083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1226047145083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry992570290083931p0"><a name="entry992570290083931p0"></a><a name="entry992570290083931p0"></a>render</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry852981500083931p0"><a name="entry852981500083931p0"></a><a name="entry852981500083931p0"></a>待操作的音频播放接口对象</p>
</td>
</tr>
<tr id="row342078316083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry458661977083931p0"><a name="entry458661977083931p0"></a><a name="entry458661977083931p0"></a>frame</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1325452639083931p0"><a name="entry1325452639083931p0"></a><a name="entry1325452639083931p0"></a>待写入的输出数据的音频frame</p>
</td>
</tr>
<tr id="row1753992191083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry16174634083931p0"><a name="entry16174634083931p0"></a><a name="entry16174634083931p0"></a>requestBytes</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry9797259083931p0"><a name="entry9797259083931p0"></a><a name="entry9797259083931p0"></a>待写入的输出数据的音频frame大小（字节数）</p>
</td>
</tr>
<tr id="row13010479083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1702639640083931p0"><a name="entry1702639640083931p0"></a><a name="entry1702639640083931p0"></a>replyBytes</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1140942504083931p0"><a name="entry1140942504083931p0"></a><a name="entry1140942504083931p0"></a>实际写入的音频数据长度（字节数），获取后保存到replyBytes中</p>
</td>
</tr>
</tbody>
</table>

**返回：**

成功返回值0，失败返回负值

## SetChannelMode<a name="ae5aad5b26ccdd65ba501620851c5ecec"></a>

```
int32_t(* AudioRender::SetChannelMode) (struct AudioRender *render, enum AudioChannelMode mode)
```

**描述：**

设置音频播放的通道模式

**参数：**

<a name="table1530905300083931"></a>
<table><thead align="left"><tr id="row1732593892083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1811499423083931"><a name="p1811499423083931"></a><a name="p1811499423083931"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1055717425083931"><a name="p1055717425083931"></a><a name="p1055717425083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row700967427083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1882432122083931p0"><a name="entry1882432122083931p0"></a><a name="entry1882432122083931p0"></a>render</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry899382911083931p0"><a name="entry899382911083931p0"></a><a name="entry899382911083931p0"></a>待操作的音频播放接口对象</p>
</td>
</tr>
<tr id="row1314347846083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry231988368083931p0"><a name="entry231988368083931p0"></a><a name="entry231988368083931p0"></a>speed</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry282405233083931p0"><a name="entry282405233083931p0"></a><a name="entry282405233083931p0"></a>待设置的通道模式</p>
</td>
</tr>
</tbody>
</table>

**返回：**

成功返回值0，失败返回负值

**参见：**

[GetChannelMode](_audio_render.md#aad3d5e4104167620eacb2ba23edce50e)

## SetRenderSpeed<a name="a5589427ae5a4ba6a8d2a19dd8eddbcd8"></a>

```
int32_t(* AudioRender::SetRenderSpeed) (struct AudioRender *render, float speed)
```

**描述：**

设置一个音频的播放速度

**参数：**

<a name="table161921859083931"></a>
<table><thead align="left"><tr id="row482016821083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p160898980083931"><a name="p160898980083931"></a><a name="p160898980083931"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1677576230083931"><a name="p1677576230083931"></a><a name="p1677576230083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row429133279083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry346376755083931p0"><a name="entry346376755083931p0"></a><a name="entry346376755083931p0"></a>render</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1874226327083931p0"><a name="entry1874226327083931p0"></a><a name="entry1874226327083931p0"></a>待操作的音频播放接口对象</p>
</td>
</tr>
<tr id="row1757368948083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1165421142083931p0"><a name="entry1165421142083931p0"></a><a name="entry1165421142083931p0"></a>speed</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1686259433083931p0"><a name="entry1686259433083931p0"></a><a name="entry1686259433083931p0"></a>待设置的播放速度</p>
</td>
</tr>
</tbody>
</table>

**返回：**

成功返回值0，失败返回负值

**参见：**

[GetRenderSpeed](_audio_render.md#af0a19dacb293d3fbe600902b93af1ee9)

