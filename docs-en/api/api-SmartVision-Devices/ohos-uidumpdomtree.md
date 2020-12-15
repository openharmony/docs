# OHOS::UIDumpDomTree<a name="EN-US_TOPIC_0000001055518118"></a>

-   [Overview](#section1195032736165635)
-   [Summary](#section1107489991165635)
-   [Public Member Functions](#pub-methods)
-   [Static Public Member Functions](#pub-static-methods)

## **Overview**<a name="section1195032736165635"></a>

**Related Modules:**

[Graphic](graphic.md)

**Description:**

Provides functions for exporting information about a specified DOM node or information about the DOM tree starting from a specified DOM node. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1107489991165635"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table273380348165635"></a>
<table><thead align="left"><tr id="row1710505727165635"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1288380849165635"><a name="p1288380849165635"></a><a name="p1288380849165635"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1439012825165635"><a name="p1439012825165635"></a><a name="p1439012825165635"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row980657512165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p872657293165635"><a name="p872657293165635"></a><a name="p872657293165635"></a><a href="graphic.md#ga04fbff1f92851a2ac55c4575cbc132e9">DumpDomTree</a> (const char *id, const char *path)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p869443478165635"><a name="p869443478165635"></a><a name="p869443478165635"></a>bool </p>
<p id="p572328608165635"><a name="p572328608165635"></a><a name="p572328608165635"></a>Exports information about a DOM tree starting from a specified DOM node and saves the information to a specified path. </p>
</td>
</tr>
<tr id="row1170912091165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1181394499165635"><a name="p1181394499165635"></a><a name="p1181394499165635"></a><a href="graphic.md#ga25384e441719c58d5cfdc3c67f1e8625">DumpDomTree</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p673811074165635"><a name="p673811074165635"></a><a name="p673811074165635"></a>bool </p>
<p id="p658046699165635"><a name="p658046699165635"></a><a name="p658046699165635"></a>Exports information about a DOM tree starting from a specified DOM node and saves the information to the default path. The default path is <strong id="b1180033932165635"><a name="b1180033932165635"></a><a name="b1180033932165635"></a>DEFAULT_DUMP_DOM_TREE_PATH</strong>. </p>
</td>
</tr>
<tr id="row232310251165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p927260532165635"><a name="p927260532165635"></a><a name="p927260532165635"></a><a href="graphic.md#ga812e123f85aa3ff687908e19d23fc54f">DumpDomNode</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p865949444165635"><a name="p865949444165635"></a><a name="p865949444165635"></a>char * </p>
<p id="p1613830603165635"><a name="p1613830603165635"></a><a name="p1613830603165635"></a>Exports information about a specified DOM node. </p>
</td>
</tr>
<tr id="row394812125165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p986716783165635"><a name="p986716783165635"></a><a name="p986716783165635"></a><a href="graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p195698620165635"><a name="p195698620165635"></a><a name="p195698620165635"></a>void * </p>
<p id="p198249020165635"><a name="p198249020165635"></a><a name="p198249020165635"></a>Overrides the <strong id="b1958348960165635"><a name="b1958348960165635"></a><a name="b1958348960165635"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row1889245362165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1524525580165635"><a name="p1524525580165635"></a><a name="p1524525580165635"></a><a href="graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1916393525165635"><a name="p1916393525165635"></a><a name="p1916393525165635"></a>void </p>
<p id="p1525139886165635"><a name="p1525139886165635"></a><a name="p1525139886165635"></a>Overrides the <strong id="b159039784165635"><a name="b159039784165635"></a><a name="b159039784165635"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

## Static Public Member Functions<a name="pub-static-methods"></a>

<a name="table591930121165635"></a>
<table><thead align="left"><tr id="row928522283165635"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1329468419165635"><a name="p1329468419165635"></a><a name="p1329468419165635"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2002468723165635"><a name="p2002468723165635"></a><a name="p2002468723165635"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1205851665165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1957312904165635"><a name="p1957312904165635"></a><a name="p1957312904165635"></a><a href="graphic.md#ga9f1bc7dc04063baeb71a3d3106be2b51">GetInstance</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1292255558165635"><a name="p1292255558165635"></a><a name="p1292255558165635"></a>static <a href="ohos-uidumpdomtree.md">UIDumpDomTree</a> * </p>
<p id="p222701120165635"><a name="p222701120165635"></a><a name="p222701120165635"></a>Obtains an instance in singleton pattern. </p>
</td>
</tr>
</tbody>
</table>

