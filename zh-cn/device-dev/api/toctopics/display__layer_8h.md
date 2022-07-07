# display\_layer.h<a name="ZH-CN_TOPIC_0000001290561132"></a>

## **概述**<a name="section691922589083931"></a>

**所属模块:**

[Display](_display.md)

## **汇总**<a name="section406589648083931"></a>

## 类<a name="nested-classes"></a>

<a name="table1291471051083931"></a>
<table><thead align="left"><tr id="row1017908096083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1167774215083931"><a name="p1167774215083931"></a><a name="p1167774215083931"></a>类</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1572179191083931"><a name="p1572179191083931"></a><a name="p1572179191083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1978962777083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p625524131083931"><a name="p625524131083931"></a><a name="p625524131083931"></a><a href="_layer_funcs.md">LayerFuncs</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p622389141083931"><a name="p622389141083931"></a><a name="p622389141083931"></a>显示图层驱动接口结构体，定义显示图层驱动接口函数指针。 <a href="_layer_funcs.md">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## 函数<a name="func-members"></a>

<a name="table1339436647083931"></a>
<table><thead align="left"><tr id="row322563820083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1876795349083931"><a name="p1876795349083931"></a><a name="p1876795349083931"></a>函数</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p565999150083931"><a name="p565999150083931"></a><a name="p565999150083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1744970053083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1806116721083931"><a name="p1806116721083931"></a><a name="p1806116721083931"></a><a href="_display.md#ga061e587306a5d0367ff228d64434c05d">LayerInitialize</a> (<a href="_layer_funcs.md">LayerFuncs</a> **funcs)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1093154848083931"><a name="p1093154848083931"></a><a name="p1093154848083931"></a>实现图层初始化功能，申请图层使用的资源，并获取图层提供的操作接口。 <a href="_display.md#ga061e587306a5d0367ff228d64434c05d">更多...</a></p>
</td>
</tr>
<tr id="row1031205702083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p130108481083931"><a name="p130108481083931"></a><a name="p130108481083931"></a><a href="_display.md#ga4e32b1a65cf243a9ac015b632a4eea0b">LayerUninitialize</a> (<a href="_layer_funcs.md">LayerFuncs</a> *funcs)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1854469853083931"><a name="p1854469853083931"></a><a name="p1854469853083931"></a>取消图层初始化功能，释放图层使用到的资源，并释放图层操作接口指针。 <a href="_display.md#ga4e32b1a65cf243a9ac015b632a4eea0b">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section420653158083931"></a>

显示图层驱动接口声明。

**Since：**

1.0

**Version：**

2.0

