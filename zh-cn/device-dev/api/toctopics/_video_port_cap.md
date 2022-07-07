# VideoPortCap<a name="ZH-CN_TOPIC_0000001343000905"></a>

## **概述**<a name="section5583691083932"></a>

**所属模块:**

[Codec](_codec.md)

## **汇总**<a name="section1788581403083932"></a>

## Public 属性<a name="pub-attribs"></a>

<a name="table197029112083932"></a>
<table><thead align="left"><tr id="row1715150043083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p184790953083932"><a name="p184790953083932"></a><a name="p184790953083932"></a>Public 属性</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p398806320083932"><a name="p398806320083932"></a><a name="p398806320083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row670173564083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1964347475083932"><a name="p1964347475083932"></a><a name="p1964347475083932"></a><a href="_video_port_cap.md#a2ede82f29a48ab4fc0fbf1089db6e938">minSize</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1620013134911"><a name="p1620013134911"></a><a name="p1620013134911"></a>支持的最小分辨率</p>
</td>
</tr>
<tr id="row893545235083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1884799174083932"><a name="p1884799174083932"></a><a name="p1884799174083932"></a><a href="_video_port_cap.md#af3efd98fcf73ba41581df4fbda1869f0">maxSize</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p57065171192"><a name="p57065171192"></a><a name="p57065171192"></a>支持的最大分辨率</p>
</td>
</tr>
<tr id="row606238083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1103111980083932"><a name="p1103111980083932"></a><a name="p1103111980083932"></a><a href="_video_port_cap.md#a5a72d2c21afce873f0ca0088d58775ce">whAlignment</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1503776156083932p0"><a name="entry1503776156083932p0"></a><a name="entry1503776156083932p0"></a>宽高对齐值</p>
</td>
</tr>
<tr id="row429418691083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1324971906083932"><a name="p1324971906083932"></a><a name="p1324971906083932"></a><a href="_video_port_cap.md#a6e055aa4dead7ceb610b45a54c132ee0">blockCount</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1723891208083932p0"><a name="entry1723891208083932p0"></a><a name="entry1723891208083932p0"></a>支持的块数量范围</p>
</td>
</tr>
<tr id="row1669349429083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p471334365083932"><a name="p471334365083932"></a><a name="p471334365083932"></a><a href="_video_port_cap.md#a23501088d925b232a94cd805f64d70ca">blocksPerSecond</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p15934440899"><a name="p15934440899"></a><a name="p15934440899"></a>每秒可处理的块数量范围</p>
</td>
</tr>
<tr id="row1421105908083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p914476698083932"><a name="p914476698083932"></a><a name="p914476698083932"></a><a href="_video_port_cap.md#a3e8514247bd850d6b63367191171ae60">blockSize</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p149461235293"><a name="p149461235293"></a><a name="p149461235293"></a>支持的块大小</p>
</td>
</tr>
<tr id="row490917712083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1198615620083932"><a name="p1198615620083932"></a><a name="p1198615620083932"></a><a href="_video_port_cap.md#abd939e06e8277cb602fbbfd778927830">supportPixFmts</a> [<a href="_codec.md#gadb8c6478388b68c09835ebe093a8920a">PIX_FORMAT_NUM</a>]</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1315175912911"><a name="p1315175912911"></a><a name="p1315175912911"></a>支持的像素格式</p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section1819776246083932"></a>

定义视频编解码能力。

## **类成员变量说明**<a name="section585613476083932"></a>

## blockCount<a name="a6e055aa4dead7ceb610b45a54c132ee0"></a>

```
RangeValue VideoPortCap::blockCount
```

**描述：**

支持的块数量范围

## blockSize<a name="a3e8514247bd850d6b63367191171ae60"></a>

```
Rect VideoPortCap::blockSize
```

**描述：**

支持的块大小

## blocksPerSecond<a name="a23501088d925b232a94cd805f64d70ca"></a>

```
RangeValue VideoPortCap::blocksPerSecond
```

**描述：**

每秒可处理的块数量范围

## maxSize<a name="af3efd98fcf73ba41581df4fbda1869f0"></a>

```
Rect VideoPortCap::maxSize
```

**描述：**

支持的最大分辨率

## minSize<a name="a2ede82f29a48ab4fc0fbf1089db6e938"></a>

```
Rect VideoPortCap::minSize
```

**描述：**

支持的最小分辨率

## supportPixFmts<a name="abd939e06e8277cb602fbbfd778927830"></a>

```
int32_t VideoPortCap::supportPixFmts[PIX_FORMAT_NUM]
```

**描述：**

支持的像素格式，详见**OMX\_COLOR\_FORMATTYPE**。

## whAlignment<a name="a5a72d2c21afce873f0ca0088d58775ce"></a>

```
Alignment VideoPortCap::whAlignment
```

**描述：**

宽高对齐值

