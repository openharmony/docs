# mem\_api.h<a name="EN-US_TOPIC_0000001055198104"></a>

-   [Overview](#section1608891609165628)
-   [Summary](#section53237454165628)
-   [Functions](#func-members)

## **Overview**<a name="section1608891609165628"></a>

**Related Modules:**

[Graphic](graphic.md)

**Description:**

Defines the functions for memory application and release. You can implement the  **malloc**  and  **free**  functions to manage the memory. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section53237454165628"></a>

## Functions<a name="func-members"></a>

<a name="table607480331165628"></a>
<table><thead align="left"><tr id="row1173988951165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p745273666165628"><a name="p745273666165628"></a><a name="p745273666165628"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p603174791165628"><a name="p603174791165628"></a><a name="p603174791165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1183365798165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p668826953165628"><a name="p668826953165628"></a><a name="p668826953165628"></a><a href="graphic.md#gab96b8c174b4a83369c8c7b10d9dadc3c">OHOS::ImageCacheMalloc</a> (const ImageInfo &amp;info)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1259523675165628"><a name="p1259523675165628"></a><a name="p1259523675165628"></a>void * </p>
<p id="p1139749863165628"><a name="p1139749863165628"></a><a name="p1139749863165628"></a>Applies for the image cache memory. You can customize the memory area when loading image resources. </p>
</td>
</tr>
<tr id="row2122936976165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p972786268165628"><a name="p972786268165628"></a><a name="p972786268165628"></a><a href="graphic.md#ga71fe0f3eb82083006b51fec59ad11088">OHOS::ImageCacheFree</a> (ImageInfo &amp;info)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p14278151165628"><a name="p14278151165628"></a><a name="p14278151165628"></a>void </p>
<p id="p838689016165628"><a name="p838689016165628"></a><a name="p838689016165628"></a>Releases the image cache memory. </p>
</td>
</tr>
<tr id="row1150899994165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p167270890165628"><a name="p167270890165628"></a><a name="p167270890165628"></a><a href="graphic.md#gafc7b2c7d0b427079d8b04b11cc4db009">OHOS::UIMalloc</a> (uint32_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2082321486165628"><a name="p2082321486165628"></a><a name="p2082321486165628"></a>void * </p>
<p id="p1163982249165628"><a name="p1163982249165628"></a><a name="p1163982249165628"></a>Applies for memory for the graphics module. You can implement this function to override the <strong id="b1763287792165628"><a name="b1763287792165628"></a><a name="b1763287792165628"></a>malloc</strong> and <strong id="b1596869430165628"><a name="b1596869430165628"></a><a name="b1596869430165628"></a>new</strong> functions. </p>
</td>
</tr>
<tr id="row1122601911165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p932151988165628"><a name="p932151988165628"></a><a name="p932151988165628"></a><a href="graphic.md#ga77914ea7bc96f6cb30f65ae2014746e8">OHOS::UIFree</a> (void *buffer)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p884556462165628"><a name="p884556462165628"></a><a name="p884556462165628"></a>void </p>
<p id="p740026363165628"><a name="p740026363165628"></a><a name="p740026363165628"></a>Releases memory for the graphics module. You can implement this function to override the <strong id="b832718068165628"><a name="b832718068165628"></a><a name="b832718068165628"></a>free</strong> and <strong id="b1588708807165628"><a name="b1588708807165628"></a><a name="b1588708807165628"></a>delete</strong> functions. </p>
</td>
</tr>
</tbody>
</table>

