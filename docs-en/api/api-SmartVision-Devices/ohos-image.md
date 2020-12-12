# OHOS::Image<a name="EN-US_TOPIC_0000001054598179"></a>

-   [Overview](#section1667437066165633)
-   [Summary](#section1743172949165633)
-   [Public Member Functions](#pub-methods)

## **Overview**<a name="section1667437066165633"></a>

**Related Modules:**

[Graphic](graphic.md)

**Description:**

Represents basic image attributes, including the image type and path. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1743172949165633"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table1435738243165633"></a>
<table><thead align="left"><tr id="row875374771165633"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1437658323165633"><a name="p1437658323165633"></a><a name="p1437658323165633"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1147419386165633"><a name="p1147419386165633"></a><a name="p1147419386165633"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1702089022165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p315751005165633"><a name="p315751005165633"></a><a name="p315751005165633"></a><a href="graphic.md#ga17210a2d5bb0be6d4b58efe249563d1b">Image</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2038786973165633"><a name="p2038786973165633"></a><a name="p2038786973165633"></a> </p>
<p id="p967407056165633"><a name="p967407056165633"></a><a name="p967407056165633"></a>A constructor used to create an <strong id="b318573611165633"><a name="b318573611165633"></a><a name="b318573611165633"></a><a href="ohos-image.md">Image</a></strong> instance. You can use this constructor when a component requires a map. </p>
</td>
</tr>
<tr id="row285883016165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1280871169165633"><a name="p1280871169165633"></a><a name="p1280871169165633"></a><a href="graphic.md#gaf3794ceb5acb543f8c526b5d9f6a1e4e">~Image</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p168204328165633"><a name="p168204328165633"></a><a name="p168204328165633"></a>virtual </p>
<p id="p706921967165633"><a name="p706921967165633"></a><a name="p706921967165633"></a>A destructor used to delete the <strong id="b742711058165633"><a name="b742711058165633"></a><a name="b742711058165633"></a><a href="ohos-image.md">Image</a></strong> instance. </p>
</td>
</tr>
<tr id="row257735217165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1050405752165633"><a name="p1050405752165633"></a><a name="p1050405752165633"></a><a href="graphic.md#ga592cbeb359a9d13274a6f4972aad3d79">GetImageInfo</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p294000843165633"><a name="p294000843165633"></a><a name="p294000843165633"></a>const <a href="ohos-imageinfo.md">ImageInfo</a> * </p>
<p id="p359350925165633"><a name="p359350925165633"></a><a name="p359350925165633"></a>Obtains the image information in an array. </p>
</td>
</tr>
<tr id="row441775480165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1687288383165633"><a name="p1687288383165633"></a><a name="p1687288383165633"></a><a href="graphic.md#gaa1552ae9813d324260a580c4ef5b0c9c">GetPath</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1308814735165633"><a name="p1308814735165633"></a><a name="p1308814735165633"></a>const char * </p>
<p id="p1829550538165633"><a name="p1829550538165633"></a><a name="p1829550538165633"></a>Obtains the image path in binary. </p>
</td>
</tr>
<tr id="row311601623165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1119193315165633"><a name="p1119193315165633"></a><a name="p1119193315165633"></a><a href="graphic.md#gadf426b0d958898df8ef2f9b7b1d278f1">GetHeader</a> (<a href="ohos-imageheader.md">ImageHeader</a> &amp;header) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1225570078165633"><a name="p1225570078165633"></a><a name="p1225570078165633"></a>void </p>
<p id="p1221989089165633"><a name="p1221989089165633"></a><a name="p1221989089165633"></a>Obtains the basic image information, including the image format, width, and height. </p>
</td>
</tr>
<tr id="row1421721141165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p623555067165633"><a name="p623555067165633"></a><a name="p623555067165633"></a><a href="graphic.md#ga7dc8490594e2bc7c9cf50c1237507239">GetSrcType</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2071107559165633"><a name="p2071107559165633"></a><a name="p2071107559165633"></a>uint8_t </p>
<p id="p1581231029165633"><a name="p1581231029165633"></a><a name="p1581231029165633"></a>Obtains the image type. </p>
</td>
</tr>
<tr id="row1580424114165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p53748903165633"><a name="p53748903165633"></a><a name="p53748903165633"></a><a href="graphic.md#ga4fe78bf99b160fc55770ba1979412c8e">SetSrc</a> (const char *src)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1970212915165633"><a name="p1970212915165633"></a><a name="p1970212915165633"></a>bool </p>
<p id="p1106675878165633"><a name="p1106675878165633"></a><a name="p1106675878165633"></a>Sets the image path. </p>
</td>
</tr>
<tr id="row1976617819165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1362549216165633"><a name="p1362549216165633"></a><a name="p1362549216165633"></a><a href="graphic.md#ga9471d489ab4d5b6848c1e50b4b7aac23">SetSrc</a> (const <a href="ohos-imageinfo.md">ImageInfo</a> *src)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p723847029165633"><a name="p723847029165633"></a><a name="p723847029165633"></a>bool </p>
<p id="p1937816940165633"><a name="p1937816940165633"></a><a name="p1937816940165633"></a>Sets the image information. </p>
</td>
</tr>
<tr id="row2102631950165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1594718919165633"><a name="p1594718919165633"></a><a name="p1594718919165633"></a><a href="graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p424673938165633"><a name="p424673938165633"></a><a name="p424673938165633"></a>void * </p>
<p id="p462132946165633"><a name="p462132946165633"></a><a name="p462132946165633"></a>Overrides the <strong id="b137547837165633"><a name="b137547837165633"></a><a name="b137547837165633"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row748978749165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2011192469165633"><a name="p2011192469165633"></a><a name="p2011192469165633"></a><a href="graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1295736406165633"><a name="p1295736406165633"></a><a name="p1295736406165633"></a>void </p>
<p id="p122545672165633"><a name="p122545672165633"></a><a name="p122545672165633"></a>Overrides the <strong id="b677817937165633"><a name="b677817937165633"></a><a name="b677817937165633"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

