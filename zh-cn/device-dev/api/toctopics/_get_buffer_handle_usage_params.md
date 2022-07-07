# GetBufferHandleUsageParams<a name="ZH-CN_TOPIC_0000001343321013"></a>

## **概述**<a name="section1254915429083932"></a>

**所属模块:**

[Codec](_codec.md)

## **汇总**<a name="section1415200580083932"></a>

## Public 属性<a name="pub-attribs"></a>

<a name="table1077335240083932"></a>
<table><thead align="left"><tr id="row1251080518083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p242348234083932"><a name="p242348234083932"></a><a name="p242348234083932"></a>Public 属性</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1692889306083932"><a name="p1692889306083932"></a><a name="p1692889306083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1418805293083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1737165271083932"><a name="p1737165271083932"></a><a name="p1737165271083932"></a><a href="_get_buffer_handle_usage_params.md#ac6cf8d851ee0a489ea58e71fb6425300">size</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1261070359083932p0"><a name="entry1261070359083932p0"></a><a name="entry1261070359083932p0"></a>结构体大小</p>
</td>
</tr>
<tr id="row1959793940083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1603767162083932"><a name="p1603767162083932"></a><a name="p1603767162083932"></a><a href="_get_buffer_handle_usage_params.md#a46d1a44401e63c23b5638559a8da087e">version</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p562313181963"><a name="p562313181963"></a><a name="p562313181963"></a>组件版本信息</p>
</td>
</tr>
<tr id="row472487721083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p236786066083932"><a name="p236786066083932"></a><a name="p236786066083932"></a><a href="_get_buffer_handle_usage_params.md#a3293a2ba5712c47414aae9f098eda0a5">portIndex</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1684240192083932p0"><a name="entry1684240192083932p0"></a><a name="entry1684240192083932p0"></a>端口索引</p>
</td>
</tr>
<tr id="row43285471083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1345870163083932"><a name="p1345870163083932"></a><a name="p1345870163083932"></a><a href="_get_buffer_handle_usage_params.md#aff9fe9abcc9f25621d6b70686fc373b7">usage</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry936882918083932p0"><a name="entry936882918083932p0"></a><a name="entry936882918083932p0"></a>使用率</p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section1226738004083932"></a>

BufferHandleUsage类型定义。

## **类成员变量说明**<a name="section84064572083932"></a>

## portIndex<a name="a3293a2ba5712c47414aae9f098eda0a5"></a>

```
uint32_t GetBufferHandleUsageParams::portIndex
```

**描述：**

端口索引

## size<a name="ac6cf8d851ee0a489ea58e71fb6425300"></a>

```
uint32_t GetBufferHandleUsageParams::size
```

**描述：**

结构体大小

## usage<a name="aff9fe9abcc9f25621d6b70686fc373b7"></a>

```
uint32_t GetBufferHandleUsageParams::usage
```

**描述：**

usage

## version<a name="a46d1a44401e63c23b5638559a8da087e"></a>

```
union OMX_VERSIONTYPE GetBufferHandleUsageParams::version
```

**描述：**

组件版本信息

