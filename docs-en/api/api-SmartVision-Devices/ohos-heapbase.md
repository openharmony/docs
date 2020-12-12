# OHOS::HeapBase<a name="EN-US_TOPIC_0000001054879564"></a>

-   [Overview](#section525567033165635)
-   [Summary](#section1671315637165635)
-   [Public Member Functions](#pub-methods)

## **Overview**<a name="section525567033165635"></a>

**Related Modules:**

[Graphic](graphic.md)

**Description:**

Defines the base class, overriding the  **new**  and  **delete**  functions. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1671315637165635"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table1803248403165635"></a>
<table><thead align="left"><tr id="row407844895165635"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1860318297165635"><a name="p1860318297165635"></a><a name="p1860318297165635"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1825448128165635"><a name="p1825448128165635"></a><a name="p1825448128165635"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row16563574165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p46717345165635"><a name="p46717345165635"></a><a name="p46717345165635"></a><a href="graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1736430017165635"><a name="p1736430017165635"></a><a name="p1736430017165635"></a>void * </p>
<p id="p612447414165635"><a name="p612447414165635"></a><a name="p612447414165635"></a>Overrides the <strong id="b516264529165635"><a name="b516264529165635"></a><a name="b516264529165635"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row1588612434165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p728500880165635"><a name="p728500880165635"></a><a name="p728500880165635"></a><a href="graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2010845822165635"><a name="p2010845822165635"></a><a name="p2010845822165635"></a>void </p>
<p id="p1212048119165635"><a name="p1212048119165635"></a><a name="p1212048119165635"></a>Overrides the <strong id="b1250059789165635"><a name="b1250059789165635"></a><a name="b1250059789165635"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

