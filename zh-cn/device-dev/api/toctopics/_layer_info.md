# LayerInfo<a name="ZH-CN_TOPIC_0000001290561196"></a>

## **概述**<a name="section1405976814083932"></a>

**所属模块:**

[Display](_display.md)

## **汇总**<a name="section452987900083932"></a>

## Public 属性<a name="pub-attribs"></a>

<a name="table59101111083932"></a>
<table><thead align="left"><tr id="row1554612320083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1656623094083932"><a name="p1656623094083932"></a><a name="p1656623094083932"></a>Public 属性</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1899978537083932"><a name="p1899978537083932"></a><a name="p1899978537083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row577850202083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p724077149083932"><a name="p724077149083932"></a><a name="p724077149083932"></a><a href="_display.md#ga31b0ef7b0a83950c56dd1cafd20c9509">width</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry900966527083932p0"><a name="entry900966527083932p0"></a><a name="entry900966527083932p0"></a>图层宽度</p>
</td>
</tr>
<tr id="row1512482550083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1866886049083932"><a name="p1866886049083932"></a><a name="p1866886049083932"></a><a href="_display.md#gaab83825af07139338b4536e45fe6d8fc">height</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry592602318083932p0"><a name="entry592602318083932p0"></a><a name="entry592602318083932p0"></a>图层高度</p>
</td>
</tr>
<tr id="row2140477542083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1619795921083932"><a name="p1619795921083932"></a><a name="p1619795921083932"></a><a href="_display.md#gade3a008d2aeccc966c226a60eb59e7ae">type</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p628228266083931"><a name="p628228266083931"></a><a name="p628228266083931"></a>图层类型，包括图形层、视频层和媒体播放模式。</p>
</td>
</tr>
<tr id="row122840942083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1529678365083932"><a name="p1529678365083932"></a><a name="p1529678365083932"></a><a href="_display.md#gabf13f41732fac1713e51ab377c27922a">bpp</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1347024241083932p0"><a name="entry1347024241083932p0"></a><a name="entry1347024241083932p0"></a>每像素所占bit数</p>
</td>
</tr>
<tr id="row1661431943083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p472813725083932"><a name="p472813725083932"></a><a name="p472813725083932"></a><a href="_display.md#ga3a05038829a72f6afa87d504712f9117">pixFormat</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1844745122083931"><a name="p1844745122083931"></a><a name="p1844745122083931"></a>图层像素格式</p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section1800341594083932"></a>

定义图层信息结构体。

在创建图层时，需要将LayerInfo传递给创建图层接口，创建图层接口根据图层信息创建相应图层。

