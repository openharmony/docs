# display\_gralloc.h<a name="ZH-CN_TOPIC_0000001290721032"></a>

## **概述**<a name="section1831419197083931"></a>

**所属模块:**

[Display](_display.md)

## **汇总**<a name="section1910295773083931"></a>

## 类<a name="nested-classes"></a>

<a name="table229546653083931"></a>
<table><thead align="left"><tr id="row1458383363083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1060223888083931"><a name="p1060223888083931"></a><a name="p1060223888083931"></a>类</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p383462394083931"><a name="p383462394083931"></a><a name="p383462394083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row258368853083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1059520364083931"><a name="p1059520364083931"></a><a name="p1059520364083931"></a><a href="_gralloc_funcs.md">GrallocFuncs</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1627369387083931"><a name="p1627369387083931"></a><a name="p1627369387083931"></a>显示内存驱动接口结构体，定义显示内存驱动接口函数指针。 <a href="_gralloc_funcs.md">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## 函数<a name="func-members"></a>

<a name="table959194444083931"></a>
<table><thead align="left"><tr id="row236823436083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p384152488083931"><a name="p384152488083931"></a><a name="p384152488083931"></a>函数</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1683476473083931"><a name="p1683476473083931"></a><a name="p1683476473083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row712912013083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p220513549083931"><a name="p220513549083931"></a><a name="p220513549083931"></a><a href="_display.md#ga304347c32a67bf7b20ef5d2b5714e5fa">GrallocInitialize</a> (<a href="_gralloc_funcs.md">GrallocFuncs</a> **funcs)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2022326945083931"><a name="p2022326945083931"></a><a name="p2022326945083931"></a>初始化内存模块，并获取内存提供的操作接口。 <a href="_display.md#ga304347c32a67bf7b20ef5d2b5714e5fa">更多...</a></p>
</td>
</tr>
<tr id="row979169943083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1201745249083931"><a name="p1201745249083931"></a><a name="p1201745249083931"></a><a href="_display.md#ga8842b25f91c247606048ab2d5cdb338f">GrallocUninitialize</a> (<a href="_gralloc_funcs.md">GrallocFuncs</a> *funcs)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p406767323083931"><a name="p406767323083931"></a><a name="p406767323083931"></a>取消初始化内存模块，并释放内存操作接口指针。 <a href="_display.md#ga8842b25f91c247606048ab2d5cdb338f">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section104132897083931"></a>

显示内存驱动接口声明。

**Since：**

1.0

**Version：**

2.0

