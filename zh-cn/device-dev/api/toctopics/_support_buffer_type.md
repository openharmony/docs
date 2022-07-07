# SupportBufferType<a name="ZH-CN_TOPIC_0000001343120373"></a>

## **概述**<a name="section2016508885083932"></a>

**所属模块:**

[Codec](_codec.md)

## **汇总**<a name="section1045404756083932"></a>

## Public 属性<a name="pub-attribs"></a>

<a name="table1158755096083932"></a>
<table><thead align="left"><tr id="row1789384561083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p29357563083932"><a name="p29357563083932"></a><a name="p29357563083932"></a>Public 属性</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p591543850083932"><a name="p591543850083932"></a><a name="p591543850083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1261881667083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1142596964083932"><a name="p1142596964083932"></a><a name="p1142596964083932"></a><a href="_support_buffer_type.md#af0f72548f14c7facd90c2a8c30e37e9f">size</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1126051924083932p0"><a name="entry1126051924083932p0"></a><a name="entry1126051924083932p0"></a>结构体大小</p>
</td>
</tr>
<tr id="row1379835094083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p576467248083932"><a name="p576467248083932"></a><a name="p576467248083932"></a><a href="_support_buffer_type.md#a9ada30305ee77515186cdb40252d5254">version</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1170749845083932p0"><a name="entry1170749845083932p0"></a><a name="entry1170749845083932p0"></a>组件版本信息</p>
</td>
</tr>
<tr id="row115230125083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1464257192083932"><a name="p1464257192083932"></a><a name="p1464257192083932"></a><a href="_support_buffer_type.md#a1f454b48c5fe57ea57eaf91a35e6dddd">portIndex</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry637257399083932p0"><a name="entry637257399083932p0"></a><a name="entry637257399083932p0"></a>端口索引</p>
</td>
</tr>
<tr id="row1141463850083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p241427447083932"><a name="p241427447083932"></a><a name="p241427447083932"></a><a href="_support_buffer_type.md#a446cc316417e3a4b88fdbce44de46c1f">bufferTypes</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry2019283464083932p0"><a name="entry2019283464083932p0"></a><a name="entry2019283464083932p0"></a>支持的所有Buffer类型</p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section1777115443083932"></a>

SupportBuffer类型定义。

## **类成员变量说明**<a name="section4539710083932"></a>

## bufferTypes<a name="a446cc316417e3a4b88fdbce44de46c1f"></a>

```
uint32_t SupportBufferType::bufferTypes
```

**描述：**

支持的所有Buffer类型

## portIndex<a name="a1f454b48c5fe57ea57eaf91a35e6dddd"></a>

```
uint32_t SupportBufferType::portIndex
```

**描述：**

端口索引

## size<a name="af0f72548f14c7facd90c2a8c30e37e9f"></a>

```
uint32_t SupportBufferType::size
```

**描述：**

结构体大小

## version<a name="a9ada30305ee77515186cdb40252d5254"></a>

```
union OMX_VERSIONTYPE SupportBufferType::version
```

**描述：**

组件版本信息

