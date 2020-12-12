# OHOS::AbstractAdapter<a name="ZH-CN_TOPIC_0000001055518108"></a>

-   [Overview](#section1108330733165633)
-   [Summary](#section508897820165633)
-   [Public Member Functions](#pub-methods)

## **Overview**<a name="section1108330733165633"></a>

**Related Modules:**

[Graphic](Graphic.md)

**Description:**

Defines the base class for adapters. You can derive  **[AbstractAdapter](OHOS-AbstractAdapter.md)**  based on actual requirements and use the  **[GetView\(\)](Graphic.md#gab155b2f4a6d8fd97755dcd1e6d3d8361)**  and  **[GetCount\(\)](Graphic.md#ga67021b360d4097c475d5e24519b5276d)**  functions to implement adapters of different data types. For details, see  [TextAdapter](OHOS-TextAdapter.md). 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section508897820165633"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table543295938165633"></a>
<table><thead align="left"><tr id="row1372593646165633"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1307474476165633"><a name="p1307474476165633"></a><a name="p1307474476165633"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p427608560165633"><a name="p427608560165633"></a><a name="p427608560165633"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row76314259165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p864695965165633"><a name="p864695965165633"></a><a name="p864695965165633"></a><a href="Graphic.md#gab60e1c77fb98352bd62e56b550d75d88">AbstractAdapter</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p695636605165633"><a name="p695636605165633"></a><a name="p695636605165633"></a> </p>
<p id="p630404967165633"><a name="p630404967165633"></a><a name="p630404967165633"></a>A constructor used to create an <strong id="b614287071165633"><a name="b614287071165633"></a><a name="b614287071165633"></a><a href="OHOS-AbstractAdapter.md">AbstractAdapter</a></strong> instance. </p>
</td>
</tr>
<tr id="row814071078165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p761446819165633"><a name="p761446819165633"></a><a name="p761446819165633"></a><a href="Graphic.md#ga86fbbc62904d459ec4fa39bab7703af7">~AbstractAdapter</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1860326790165633"><a name="p1860326790165633"></a><a name="p1860326790165633"></a>virtual </p>
<p id="p543424066165633"><a name="p543424066165633"></a><a name="p543424066165633"></a>A destructor used to delete the <strong id="b1740301460165633"><a name="b1740301460165633"></a><a name="b1740301460165633"></a><a href="OHOS-AbstractAdapter.md">AbstractAdapter</a></strong> instance. </p>
</td>
</tr>
<tr id="row1589194364165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p313158366165633"><a name="p313158366165633"></a><a name="p313158366165633"></a><a href="Graphic.md#ga67021b360d4097c475d5e24519b5276d">GetCount</a> ()=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1121711562165633"><a name="p1121711562165633"></a><a name="p1121711562165633"></a>virtual uint16_t </p>
<p id="p1055952361165633"><a name="p1055952361165633"></a><a name="p1055952361165633"></a>Obtains the number of adapter data items. </p>
</td>
</tr>
<tr id="row1947846359165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1122493829165633"><a name="p1122493829165633"></a><a name="p1122493829165633"></a><a href="Graphic.md#gab155b2f4a6d8fd97755dcd1e6d3d8361">GetView</a> (<a href="OHOS-UIView.md">UIView</a> *inView, int16_t <a href="UTILS.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p386373641165633"><a name="p386373641165633"></a><a name="p386373641165633"></a>virtual <a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p519227157165633"><a name="p519227157165633"></a><a name="p519227157165633"></a>Obtains a <strong id="b1093181076165633"><a name="b1093181076165633"></a><a name="b1093181076165633"></a><a href="OHOS-UIView.md">UIView</a></strong> instance to convert adapter data into another <strong id="b767531038165633"><a name="b767531038165633"></a><a name="b767531038165633"></a><a href="OHOS-UIView.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row2050082347165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1416625694165633"><a name="p1416625694165633"></a><a name="p1416625694165633"></a><a href="Graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p274687077165633"><a name="p274687077165633"></a><a name="p274687077165633"></a>void * </p>
<p id="p310469831165633"><a name="p310469831165633"></a><a name="p310469831165633"></a>Overrides the <strong id="b115617379165633"><a name="b115617379165633"></a><a name="b115617379165633"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row1151550884165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1745812690165633"><a name="p1745812690165633"></a><a name="p1745812690165633"></a><a href="Graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p26718515165633"><a name="p26718515165633"></a><a name="p26718515165633"></a>void </p>
<p id="p477134882165633"><a name="p477134882165633"></a><a name="p477134882165633"></a>Overrides the <strong id="b1983563747165633"><a name="b1983563747165633"></a><a name="b1983563747165633"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

