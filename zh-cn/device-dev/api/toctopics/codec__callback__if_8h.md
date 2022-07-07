# codec\_callback\_if.h<a name="ZH-CN_TOPIC_0000001290721028"></a>

## **概述**<a name="section427965154083931"></a>

**所属模块:**

[Codec](_codec.md)

## **汇总**<a name="section1275682163083931"></a>

## 类<a name="nested-classes"></a>

<a name="table760937777083931"></a>
<table><thead align="left"><tr id="row1831046672083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1604228916083931"><a name="p1604228916083931"></a><a name="p1604228916083931"></a>类</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p857359399083931"><a name="p857359399083931"></a><a name="p857359399083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row2069697691083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p501140164083931"><a name="p501140164083931"></a><a name="p501140164083931"></a><a href="_codec_callback_type.md">CodecCallbackType</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1999704586083931"><a name="p1999704586083931"></a><a name="p1999704586083931"></a>Codec回调接口定义。 <a href="_codec_callback_type.md">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## 函数<a name="func-members"></a>

<a name="table1054908096083931"></a>
<table><thead align="left"><tr id="row1787961754083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p411332704083931"><a name="p411332704083931"></a><a name="p411332704083931"></a>函数</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p762235479083931"><a name="p762235479083931"></a><a name="p762235479083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1177109556083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p509148287083931"><a name="p509148287083931"></a><a name="p509148287083931"></a><a href="_codec.md#ga036d59f17648a3407a2b1758ec642007">CodecCallbackTypeGet</a> (struct HdfRemoteService *remote)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1071144358083931"><a name="p1071144358083931"></a><a name="p1071144358083931"></a>实例化CodecCallbackType对象。 <a href="_codec.md#ga036d59f17648a3407a2b1758ec642007">更多...</a></p>
</td>
</tr>
<tr id="row512467067083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p661859542083931"><a name="p661859542083931"></a><a name="p661859542083931"></a><a href="_codec.md#ga5f32a2c8a076072e6dfa6fac9f1403e3">CodecCallbackTypeRelease</a> (struct <a href="_codec_callback_type.md">CodecCallbackType</a> *instance)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1190503101083931"><a name="p1190503101083931"></a><a name="p1190503101083931"></a>释放CodecCallbackType对象。 <a href="_codec.md#ga5f32a2c8a076072e6dfa6fac9f1403e3">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section1072049907083931"></a>

主要包括回调函数接口定义。

Codec模块事件上报、上报输入buffer和输出buffer处理完毕等接口定义。

**Since：**

3.1

**Version：**

2.0

