# AudioCapture<a name="ZH-CN_TOPIC_0000001291040552"></a>

## **概述**<a name="section111809388083931"></a>

**所属模块:**

[Audio](_audio.md)

## **汇总**<a name="section2072110785083931"></a>

## Public 属性<a name="pub-attribs"></a>

<a name="table1282879061083931"></a>
<table><thead align="left"><tr id="row2134208527083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1278295836083931"><a name="p1278295836083931"></a><a name="p1278295836083931"></a>Public 属性</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1879534412083931"><a name="p1879534412083931"></a><a name="p1879534412083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1814858281083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1229179272083931"><a name="p1229179272083931"></a><a name="p1229179272083931"></a><em id="a3722b1e55fa79af775b5d3acd08f29c4"><a name="a3722b1e55fa79af775b5d3acd08f29c4"></a><a name="a3722b1e55fa79af775b5d3acd08f29c4"></a></em>control</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1186039930083931"><a name="p1186039930083931"></a><a name="p1186039930083931"></a>音频控制能力接口，详情参考<a href="_audio_control.md">AudioControl</a></p>
</td>
</tr>
<tr id="row52117826083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1272535796083931"><a name="p1272535796083931"></a><a name="p1272535796083931"></a><em id="a3b1231763ecdab4d60809048136ae017"><a name="a3b1231763ecdab4d60809048136ae017"></a><a name="a3b1231763ecdab4d60809048136ae017"></a></em>attr</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2038403091083931"><a name="p2038403091083931"></a><a name="p2038403091083931"></a>音频属性能力接口，详情参考<a href="_audio_attribute.md">AudioAttribute</a></p>
</td>
</tr>
<tr id="row1492772799083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p972171177083931"><a name="p972171177083931"></a><a name="p972171177083931"></a><em id="a55ba54428fc285c97032ce27ae0ab4aa"><a name="a55ba54428fc285c97032ce27ae0ab4aa"></a><a name="a55ba54428fc285c97032ce27ae0ab4aa"></a></em>scene</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2101437238083931"><a name="p2101437238083931"></a><a name="p2101437238083931"></a>音频场景能力接口，详情参考<a href="_audio_scene.md">AudioScene</a></p>
</td>
</tr>
<tr id="row1436171369083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1322493898083931"><a name="p1322493898083931"></a><a name="p1322493898083931"></a><em id="a066923e8aff005d677c7b7c33a036f41"><a name="a066923e8aff005d677c7b7c33a036f41"></a><a name="a066923e8aff005d677c7b7c33a036f41"></a></em>volume</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1443838325083931"><a name="p1443838325083931"></a><a name="p1443838325083931"></a>音频音量能力接口，详情参考<a href="_audio_volume.md">AudioVolume</a></p>
</td>
</tr>
<tr id="row1904089925083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1787825382083931"><a name="p1787825382083931"></a><a name="p1787825382083931"></a>( <a href="_audio_capture.md#a89f1baf4b6177f91b9135e86cc8681da">CaptureFrame</a> )(struct <a href="_audio_capture.md">AudioCapture</a> *capture, void *frame, uint64_t requestBytes, uint64_t *replyBytes)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2047947889083931"><a name="p2047947889083931"></a><a name="p2047947889083931"></a>从音频驱动中录制（capture）一帧输入数据（录音，音频上行数据） <a href="_audio_capture.md#a89f1baf4b6177f91b9135e86cc8681da">更多...</a></p>
</td>
</tr>
<tr id="row1800693053083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1584482513083931"><a name="p1584482513083931"></a><a name="p1584482513083931"></a>( <a href="_audio_capture.md#ad307fd1eca38f257f865c1316db6e5d5">GetCapturePosition</a> )(struct <a href="_audio_capture.md">AudioCapture</a> *capture, uint64_t *frames, struct <a href="_audio_time_stamp.md">AudioTimeStamp</a> *time)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1539558515083931"><a name="p1539558515083931"></a><a name="p1539558515083931"></a>获取音频输入帧数的上一次计数 <a href="_audio_capture.md#ad307fd1eca38f257f865c1316db6e5d5">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section502566757083931"></a>

AudioCapture音频录音接口。

## **类成员变量说明**<a name="section982458572083931"></a>

## CaptureFrame<a name="a89f1baf4b6177f91b9135e86cc8681da"></a>

```
int32_t(* AudioCapture::CaptureFrame) (struct AudioCapture *capture, void *frame, uint64_t requestBytes, uint64_t *replyBytes)
```

**描述：**

从音频驱动中录制（capture）一帧输入数据（录音，音频上行数据）

**参数：**

<a name="table683039072083931"></a>
<table><thead align="left"><tr id="row423616684083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p469208004083931"><a name="p469208004083931"></a><a name="p469208004083931"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1392849085083931"><a name="p1392849085083931"></a><a name="p1392849085083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row2006218823083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry225324752083931p0"><a name="entry225324752083931p0"></a><a name="entry225324752083931p0"></a>capture</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1915325977083931p0"><a name="entry1915325977083931p0"></a><a name="entry1915325977083931p0"></a>待操作的音频录音接口对象</p>
</td>
</tr>
<tr id="row1523528944083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry272828607083931p0"><a name="entry272828607083931p0"></a><a name="entry272828607083931p0"></a>frame</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1413990201083931p0"><a name="entry1413990201083931p0"></a><a name="entry1413990201083931p0"></a>待存放输入数据的音频frame</p>
</td>
</tr>
<tr id="row2139285851083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1896298502083931p0"><a name="entry1896298502083931p0"></a><a name="entry1896298502083931p0"></a>requestBytes</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry210206270083931p0"><a name="entry210206270083931p0"></a><a name="entry210206270083931p0"></a>待存放输入数据的音频frame大小（字节数）</p>
</td>
</tr>
<tr id="row749229406083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry755121164083931p0"><a name="entry755121164083931p0"></a><a name="entry755121164083931p0"></a>replyBytes</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1116370230083931p0"><a name="entry1116370230083931p0"></a><a name="entry1116370230083931p0"></a>实际读取到的音频数据长度（字节数），获取后保存到replyBytes中</p>
</td>
</tr>
</tbody>
</table>

**返回：**

成功返回值0，失败返回负值

## GetCapturePosition<a name="ad307fd1eca38f257f865c1316db6e5d5"></a>

```
int32_t(* AudioCapture::GetCapturePosition) (struct AudioCapture *capture, uint64_t *frames, struct AudioTimeStamp *time)
```

**描述：**

获取音频输入帧数的上一次计数

**参数：**

<a name="table45737229083931"></a>
<table><thead align="left"><tr id="row992791177083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1087133261083931"><a name="p1087133261083931"></a><a name="p1087133261083931"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2068633776083931"><a name="p2068633776083931"></a><a name="p2068633776083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row732229805083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry909128753083931p0"><a name="entry909128753083931p0"></a><a name="entry909128753083931p0"></a>capture</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1068342070083931p0"><a name="entry1068342070083931p0"></a><a name="entry1068342070083931p0"></a>待操作的音频录音接口对象</p>
</td>
</tr>
<tr id="row77995547083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1766789645083931p0"><a name="entry1766789645083931p0"></a><a name="entry1766789645083931p0"></a>frames</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry150338839083931p0"><a name="entry150338839083931p0"></a><a name="entry150338839083931p0"></a>获取的音频帧计数保存到frames中</p>
</td>
</tr>
<tr id="row769252897083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1439185451083931p0"><a name="entry1439185451083931p0"></a><a name="entry1439185451083931p0"></a>time</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1971604374083931p0"><a name="entry1971604374083931p0"></a><a name="entry1971604374083931p0"></a>获取的关联时间戳保存到time中</p>
</td>
</tr>
</tbody>
</table>

**返回：**

成功返回值0，失败返回负值

**参见：**

[CaptureFrame](_audio_capture.md#a89f1baf4b6177f91b9135e86cc8681da)

