# codec\_component\_if.h<a name="ZH-CN_TOPIC_0000001343320969"></a>

## **概述**<a name="section497993033083931"></a>

**所属模块:**

[Codec](_codec.md)

## **汇总**<a name="section811596073083931"></a>

## 类<a name="nested-classes"></a>

<a name="table513225297083931"></a>
<table><thead align="left"><tr id="row1264623620083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1120124119083931"><a name="p1120124119083931"></a><a name="p1120124119083931"></a>类</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1927214248083931"><a name="p1927214248083931"></a><a name="p1927214248083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row343156650083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p444391154083931"><a name="p444391154083931"></a><a name="p444391154083931"></a><a href="_codec_component_type.md">CodecComponentType</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1801343626083931"><a name="p1801343626083931"></a><a name="p1801343626083931"></a>Codec组件接口定义。 <a href="_codec_component_type.md">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## 函数<a name="func-members"></a>

<a name="table765178727083931"></a>
<table><thead align="left"><tr id="row1396164578083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1629780693083931"><a name="p1629780693083931"></a><a name="p1629780693083931"></a>函数</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p786993512083931"><a name="p786993512083931"></a><a name="p786993512083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row789534353083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1817358591083931"><a name="p1817358591083931"></a><a name="p1817358591083931"></a><a href="_codec.md#gab1c9fbaca3df81fbbccda242e7fc1326">CodecComponentTypeGet</a> (struct HdfRemoteService *remote)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1127266929083931"><a name="p1127266929083931"></a><a name="p1127266929083931"></a>实例化CodecComponentType对象。 <a href="_codec.md#gab1c9fbaca3df81fbbccda242e7fc1326">更多...</a></p>
</td>
</tr>
<tr id="row2079833361083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1224130336083931"><a name="p1224130336083931"></a><a name="p1224130336083931"></a><a href="_codec.md#ga45d58909b669262e9436fd15ae8ac284">CodecComponentTypeRelease</a> (struct <a href="_codec_component_type.md">CodecComponentType</a> *instance)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1089083896083931"><a name="p1089083896083931"></a><a name="p1089083896083931"></a>释放CodecComponentType对象。 <a href="_codec.md#ga45d58909b669262e9436fd15ae8ac284">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section281443149083931"></a>

主要包括Codec组件接口定义。

Codec模块提供了获取组件信息、给组件发送命令、组件参数设置、buffer轮转和控制等接口定义。创建组件后，可使用下列接口进行编解码处理。

**Since：**

3.1

**Version：**

2.0

