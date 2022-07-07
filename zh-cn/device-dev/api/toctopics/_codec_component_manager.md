# CodecComponentManager<a name="ZH-CN_TOPIC_0000001343120321"></a>

## **概述**<a name="section536394310083931"></a>

**所属模块:**

[Codec](_codec.md)

## **汇总**<a name="section779030265083931"></a>

## Public 属性<a name="pub-attribs"></a>

<a name="table2088815182083931"></a>
<table><thead align="left"><tr id="row1007455302083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p682044816083931"><a name="p682044816083931"></a><a name="p682044816083931"></a>Public 属性</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p443488221083931"><a name="p443488221083931"></a><a name="p443488221083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1695866664083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p656918507083931"><a name="p656918507083931"></a><a name="p656918507083931"></a>(<a href="_codec_component_manager.md#a4b76d83ad7e21b6e6359164cfd45e400">GetComponentNum</a> )()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1708398800083931"><a name="p1708398800083931"></a><a name="p1708398800083931"></a>获取Codec编解码组件数量。 <a href="_codec_component_manager.md#a4b76d83ad7e21b6e6359164cfd45e400">更多...</a></p>
</td>
</tr>
<tr id="row1436893104083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1031027256083931"><a name="p1031027256083931"></a><a name="p1031027256083931"></a>( <a href="_codec_component_manager.md#a99f96d0a63819c6c2940b2eedbd0297c">GetComponentCapabilityList</a> )(<a href="_codec_comp_capability.md">CodecCompCapability</a> *capList, int32_t count)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1982565078083931"><a name="p1982565078083931"></a><a name="p1982565078083931"></a>获取编解码能力集表。 <a href="_codec_component_manager.md#a99f96d0a63819c6c2940b2eedbd0297c">更多...</a></p>
</td>
</tr>
<tr id="row1021936191083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2144124811083931"><a name="p2144124811083931"></a><a name="p2144124811083931"></a>( <a href="_codec_component_manager.md#a04d9a2e9aff41f4a11a7919f1796eacc">CreateComponent</a> )(struct <a href="_codec_component_type.md">CodecComponentType</a> **component, char *compName, void *appData, int32_t appDataSize, struct <a href="_codec_callback_type.md">CodecCallbackType</a> *callbacks)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p66210732083931"><a name="p66210732083931"></a><a name="p66210732083931"></a>创建Codec组件实例。 <a href="_codec_component_manager.md#a04d9a2e9aff41f4a11a7919f1796eacc">更多...</a></p>
</td>
</tr>
<tr id="row2053183109083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p127507468083931"><a name="p127507468083931"></a><a name="p127507468083931"></a>( <a href="_codec_component_manager.md#a823278b238de8732b5a42e5849263f17">DestoryComponent</a> )(struct <a href="_codec_component_type.md">CodecComponentType</a> *component)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p720628226083931"><a name="p720628226083931"></a><a name="p720628226083931"></a>销毁组件实例。 <a href="_codec_component_manager.md#a823278b238de8732b5a42e5849263f17">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section238285612083931"></a>

Codec组件管理类接口定义。

主要提供以下功能:

-   获取Codec编解码组件数量以及编解码能力集表。
-   创建/销毁Codec组件。

## **类成员变量说明**<a name="section377002382083931"></a>

## CreateComponent<a name="a04d9a2e9aff41f4a11a7919f1796eacc"></a>

```
int32_t(* CodecComponentManager::CreateComponent) (struct CodecComponentType **component, char *compName, void *appData, int32_t appDataSize, struct CodecCallbackType *callbacks)
```

**描述：**

创建Codec组件实例。

根据组件名称创建Codec组件实例。

**参数：**

<a name="table1698260758083931"></a>
<table><thead align="left"><tr id="row1609474174083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1145660555083931"><a name="p1145660555083931"></a><a name="p1145660555083931"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p698502482083931"><a name="p698502482083931"></a><a name="p698502482083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row831926929083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry174403884083931p0"><a name="entry174403884083931p0"></a><a name="entry174403884083931p0"></a>component</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1089734281083931p0"><a name="entry1089734281083931p0"></a><a name="entry1089734281083931p0"></a>输出参数，指向Codec组件的指针。</p>
</td>
</tr>
<tr id="row1673069535083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry583799863083931p0"><a name="entry583799863083931p0"></a><a name="entry583799863083931p0"></a>compName</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry928682782083931p0"><a name="entry928682782083931p0"></a><a name="entry928682782083931p0"></a>输入参数，组件名称。</p>
</td>
</tr>
<tr id="row1593379792083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2017906544083931p0"><a name="entry2017906544083931p0"></a><a name="entry2017906544083931p0"></a>appData</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry827698169083931p0"><a name="entry827698169083931p0"></a><a name="entry827698169083931p0"></a>输入参数，指向应用程序定义的值的指针，该值将在回调期间返回。</p>
</td>
</tr>
<tr id="row1771562843083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1230523445083931p0"><a name="entry1230523445083931p0"></a><a name="entry1230523445083931p0"></a>appDataSize</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1453662068083931p0"><a name="entry1453662068083931p0"></a><a name="entry1453662068083931p0"></a>输入参数，appData字节数。</p>
</td>
</tr>
<tr id="row191650334083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry795016683083931p0"><a name="entry795016683083931p0"></a><a name="entry795016683083931p0"></a>callbacks</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry626414727083931p0"><a name="entry626414727083931p0"></a><a name="entry626414727083931p0"></a>输入参数，回调接口，指向OMX_CALLBACKTYPE结构的指针，详见<a href="_codec_callback_type.md">CodecCallbackType</a>。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

HDF\_SUCCESS 表示创建组件成功。

HDF\_ERR\_INVALID\_PARAM 表示参数无效，创建组件失败。

HDF\_ERR\_INVALID\_OBJECT 表示对象无效，创建组件失败。

HDF\_ERR\_MALLOC\_FAIL 表示申请内存失败，创建组件失败。

## DestoryComponent<a name="a823278b238de8732b5a42e5849263f17"></a>

```
int32_t(* CodecComponentManager::DestoryComponent) (struct CodecComponentType *component)
```

**描述：**

销毁组件实例。

销毁指定的Codec组件。

**参数：**

<a name="table1194719818083931"></a>
<table><thead align="left"><tr id="row1555834004083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1943364094083931"><a name="p1943364094083931"></a><a name="p1943364094083931"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p453708450083931"><a name="p453708450083931"></a><a name="p453708450083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1443379906083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry362112187083931p0"><a name="entry362112187083931p0"></a><a name="entry362112187083931p0"></a>component</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1602601942083931p0"><a name="entry1602601942083931p0"></a><a name="entry1602601942083931p0"></a>输入参数，需要销毁的Codec组件。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

HDF\_SUCCESS 表示销毁组件成功。

HDF\_ERR\_INVALID\_PARAM 表示参数无效，销毁组件失败。

HDF\_ERR\_INVALID\_OBJECT 表示对象无效，销毁组件失败。

HDF\_ERR\_MALLOC\_FAIL 表示申请内存失败，销毁组件失败。

## GetComponentCapabilityList<a name="a99f96d0a63819c6c2940b2eedbd0297c"></a>

```
int32_t(* CodecComponentManager::GetComponentCapabilityList) (CodecCompCapability *capList, int32_t count)
```

**描述：**

获取编解码能力集表。

用户可通过此接口了解Codec模块提供了哪些编解码能力，对应的能力体现在[CodecCompCapability](_codec_comp_capability.md)结构体。

**参数：**

<a name="table404905286083931"></a>
<table><thead align="left"><tr id="row1628456047083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p348807084083931"><a name="p348807084083931"></a><a name="p348807084083931"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2062490980083931"><a name="p2062490980083931"></a><a name="p2062490980083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1601549055083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1576239176083931p0"><a name="entry1576239176083931p0"></a><a name="entry1576239176083931p0"></a>capList</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry173811239083931p0"><a name="entry173811239083931p0"></a><a name="entry173811239083931p0"></a>输出参数，返回全部组件的能力集表<a href="_codec_comp_capability.md">CodecCompCapability</a>。</p>
</td>
</tr>
<tr id="row2068132620083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry670018397083931p0"><a name="entry670018397083931p0"></a><a name="entry670018397083931p0"></a>count</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry2133091986083931p0"><a name="entry2133091986083931p0"></a><a name="entry2133091986083931p0"></a>输入参数，编解码组件数量，由<a href="_codec_component_manager.md#a4b76d83ad7e21b6e6359164cfd45e400">GetComponentNum</a>获得。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

HDF\_SUCCESS 表示获取能力集表成功。

HDF\_ERR\_INVALID\_PARAM 表示参数无效，获取能力集表失败。

HDF\_ERR\_INVALID\_OBJECT 表示对象无效，获取能力集表失败。

HDF\_ERR\_MALLOC\_FAIL 表示申请内存失败，获取能力集表失败。

## GetComponentNum<a name="a4b76d83ad7e21b6e6359164cfd45e400"></a>

```
int32_t(* CodecComponentManager::GetComponentNum) ()
```

**描述：**

获取Codec编解码组件数量。

通过此接口获取Codec编解码组件数量，用来获取全部编解码能力集。

**返回：**

Codec编解码组件数量。

