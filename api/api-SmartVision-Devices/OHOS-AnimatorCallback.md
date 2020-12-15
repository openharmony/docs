# OHOS::AnimatorCallback<a name="ZH-CN_TOPIC_0000001055678110"></a>

-   [Overview](#section1362939213165633)
-   [Summary](#section1029534402165633)
-   [Public Member Functions](#pub-methods)

## **Overview**<a name="section1362939213165633"></a>

**Related Modules:**

[Graphic](Graphic.md)

**Description:**

Represents the animator callback. 

You need to implement the callback function to produce specific animator effects.

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1029534402165633"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table473937545165633"></a>
<table><thead align="left"><tr id="row681234901165633"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p669659001165633"><a name="p669659001165633"></a><a name="p669659001165633"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1500947618165633"><a name="p1500947618165633"></a><a name="p1500947618165633"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row47398461165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1335121127165633"><a name="p1335121127165633"></a><a name="p1335121127165633"></a><a href="Graphic.md#gace3debcfa4200de1951a8eae6421e5aa">Callback</a> (<a href="OHOS-UIView.md">UIView</a> *view)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1677734819165633"><a name="p1677734819165633"></a><a name="p1677734819165633"></a>virtual void </p>
<p id="p1750792516165633"><a name="p1750792516165633"></a><a name="p1750792516165633"></a>Called when each frame starts. This is a pure virtual function, which needs your inheritance and implementation. </p>
</td>
</tr>
<tr id="row1331925129165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p672549382165633"><a name="p672549382165633"></a><a name="p672549382165633"></a><a href="Graphic.md#ga33875ecdc72e4d8076be696a35667a8f">OnStop</a> (<a href="OHOS-UIView.md">UIView</a> &amp;view)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1241540631165633"><a name="p1241540631165633"></a><a name="p1241540631165633"></a>virtual void </p>
<p id="p1986378030165633"><a name="p1986378030165633"></a><a name="p1986378030165633"></a>Called when an animator stops. This is a pure virtual function, which needs your inheritance and implementation. </p>
</td>
</tr>
<tr id="row1705476933165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1452632694165633"><a name="p1452632694165633"></a><a name="p1452632694165633"></a><a href="Graphic.md#ga783aca5777750141552a5aba974ffdff">~AnimatorCallback</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p65388602165633"><a name="p65388602165633"></a><a name="p65388602165633"></a>virtual </p>
<p id="p1777908024165633"><a name="p1777908024165633"></a><a name="p1777908024165633"></a>A default destructor used to delete an <strong id="b1113224565165633"><a name="b1113224565165633"></a><a name="b1113224565165633"></a><a href="OHOS-AnimatorCallback.md">AnimatorCallback</a></strong> instance. </p>
</td>
</tr>
<tr id="row1893191182165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p913360905165633"><a name="p913360905165633"></a><a name="p913360905165633"></a><a href="Graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p977031315165633"><a name="p977031315165633"></a><a name="p977031315165633"></a>void * </p>
<p id="p1876316550165633"><a name="p1876316550165633"></a><a name="p1876316550165633"></a>Overrides the <strong id="b1390014224165633"><a name="b1390014224165633"></a><a name="b1390014224165633"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row2065867769165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1470575289165633"><a name="p1470575289165633"></a><a name="p1470575289165633"></a><a href="Graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p106626987165633"><a name="p106626987165633"></a><a name="p106626987165633"></a>void </p>
<p id="p1887484268165633"><a name="p1887484268165633"></a><a name="p1887484268165633"></a>Overrides the <strong id="b987349747165633"><a name="b987349747165633"></a><a name="b987349747165633"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

