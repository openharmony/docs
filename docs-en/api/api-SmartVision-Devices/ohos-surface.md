# OHOS::Surface<a name="EN-US_TOPIC_0000001055039528"></a>

-   [Overview](#section83217545165632)
-   [Summary](#section1990804920165632)
-   [Public Member Functions](#pub-methods)
-   [Static Public Member Functions](#pub-static-methods)

## **Overview**<a name="section83217545165632"></a>

**Related Modules:**

[Surface](surface.md)

**Description:**

Defines the consumer listener used to notify consumers when the surface status is updated. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1990804920165632"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table1170130322165632"></a>
<table><thead align="left"><tr id="row41397100165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1458733599165632"><a name="p1458733599165632"></a><a name="p1458733599165632"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p116480274165632"><a name="p116480274165632"></a><a name="p116480274165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1677938489165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p572554068165632"><a name="p572554068165632"></a><a name="p572554068165632"></a><a href="surface.md#ga1d35e9b436057032ec4598f24e31dbfb">~Surface</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p885063604165632"><a name="p885063604165632"></a><a name="p885063604165632"></a>virtual </p>
<p id="p1770263223165632"><a name="p1770263223165632"></a><a name="p1770263223165632"></a>A destructor used to delete the <strong id="b1911276981165632"><a name="b1911276981165632"></a><a name="b1911276981165632"></a><a href="ohos-surface.md">Surface</a></strong> instance. </p>
</td>
</tr>
<tr id="row89291640165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p156411250165632"><a name="p156411250165632"></a><a name="p156411250165632"></a><a href="surface.md#ga44138c9aa20a108358da26893b92150c">SetQueueSize</a> (uint8_t queueSize)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1757794721165632"><a name="p1757794721165632"></a><a name="p1757794721165632"></a>virtual void </p>
<p id="p1336343177165632"><a name="p1336343177165632"></a><a name="p1336343177165632"></a>Sets the number of buffers that can be allocated to the surface. The default value is <strong id="b482991453165632"><a name="b482991453165632"></a><a name="b482991453165632"></a>1</strong>. The value range is [1, 10]. </p>
</td>
</tr>
<tr id="row628479350165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1342725111165632"><a name="p1342725111165632"></a><a name="p1342725111165632"></a><a href="surface.md#gaff365f4d3178798ff28f0aaab9f467de">GetQueueSize</a> ()=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p672163712165632"><a name="p672163712165632"></a><a name="p672163712165632"></a>virtual uint8_t </p>
<p id="p1053502922165632"><a name="p1053502922165632"></a><a name="p1053502922165632"></a>Obtains the number of surface buffers that can be allocated to the surface. The default value is <strong id="b659292280165632"><a name="b659292280165632"></a><a name="b659292280165632"></a>1</strong>. The value range is [1, 10]. </p>
</td>
</tr>
<tr id="row362363146165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1190562238165632"><a name="p1190562238165632"></a><a name="p1190562238165632"></a><a href="surface.md#ga260c12281c283e5a0b63a49f24bd0cc0">SetWidthAndHeight</a> (uint32_t width, uint32_t height)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1788628816165632"><a name="p1788628816165632"></a><a name="p1788628816165632"></a>virtual void </p>
<p id="p1162838147165632"><a name="p1162838147165632"></a><a name="p1162838147165632"></a>Sets the width and height of the surface for calculating its stride and size. The default value range of width and height is (0,7680]. </p>
</td>
</tr>
<tr id="row1394376706165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p26036699165632"><a name="p26036699165632"></a><a name="p26036699165632"></a><a href="surface.md#ga1220bd15e73d891105d310cf37422b56">GetWidth</a> ()=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p748437244165632"><a name="p748437244165632"></a><a name="p748437244165632"></a>virtual uint32_t </p>
<p id="p1132173156165632"><a name="p1132173156165632"></a><a name="p1132173156165632"></a>Obtains the width of the surface. </p>
</td>
</tr>
<tr id="row1477600501165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p663630768165632"><a name="p663630768165632"></a><a name="p663630768165632"></a><a href="surface.md#ga0e6be0887bd69cf749c0d994bd826699">GetHeight</a> ()=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1029328500165632"><a name="p1029328500165632"></a><a name="p1029328500165632"></a>virtual uint32_t </p>
<p id="p1291997979165632"><a name="p1291997979165632"></a><a name="p1291997979165632"></a>Obtains the height of the surface. </p>
</td>
</tr>
<tr id="row333120355165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1037850779165632"><a name="p1037850779165632"></a><a name="p1037850779165632"></a><a href="surface.md#ga8e44c9100296571a9294dc9851ef48dc">SetFormat</a> (uint32_t format)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2024695213165632"><a name="p2024695213165632"></a><a name="p2024695213165632"></a>virtual void </p>
<p id="p152237553165632"><a name="p152237553165632"></a><a name="p152237553165632"></a>Sets the pixel format of the surface. For details, see <strong id="b1855261394165632"><a name="b1855261394165632"></a><a name="b1855261394165632"></a>ImageFormat</strong>. The default pixel format is <strong id="b1466192518165632"><a name="b1466192518165632"></a><a name="b1466192518165632"></a>IMAGE_PIXEL_FORMAT_RGB565</strong>. </p>
</td>
</tr>
<tr id="row285627345165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2113025718165632"><a name="p2113025718165632"></a><a name="p2113025718165632"></a><a href="surface.md#ga461caa118503a471c78ea09a8403a6ec">GetFormat</a> ()=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p427720736165632"><a name="p427720736165632"></a><a name="p427720736165632"></a>virtual uint32_t </p>
<p id="p1746612911165632"><a name="p1746612911165632"></a><a name="p1746612911165632"></a>Obtains the pixel format of the surface. For details, see <strong id="b1181080506165632"><a name="b1181080506165632"></a><a name="b1181080506165632"></a>ImageFormat</strong>. The default pixel format is <strong id="b609294715165632"><a name="b609294715165632"></a><a name="b609294715165632"></a>IMAGE_PIXEL_FORMAT_RGB565</strong>. </p>
</td>
</tr>
<tr id="row55692671165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1851088557165632"><a name="p1851088557165632"></a><a name="p1851088557165632"></a><a href="surface.md#ga5b27f54101d9d3371038b73373c36530">SetStrideAlignment</a> (uint32_t strideAlignment)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p135729073165632"><a name="p135729073165632"></a><a name="p135729073165632"></a>virtual void </p>
<p id="p371826196165632"><a name="p371826196165632"></a><a name="p371826196165632"></a>Sets the number of bytes for stride alignment. </p>
</td>
</tr>
<tr id="row824472712165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2029378346165632"><a name="p2029378346165632"></a><a name="p2029378346165632"></a><a href="surface.md#ga0d5317e6a008b8fd0ee98ebd516a0e7c">GetStrideAlignment</a> ()=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1089232081165632"><a name="p1089232081165632"></a><a name="p1089232081165632"></a>virtual uint32_t </p>
<p id="p1821960425165632"><a name="p1821960425165632"></a><a name="p1821960425165632"></a>Obtains the number of bytes for stride alignment. By default, 4-byte aligned is used. </p>
</td>
</tr>
<tr id="row2082533680165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p150322202165632"><a name="p150322202165632"></a><a name="p150322202165632"></a><a href="surface.md#ga5aabbb48f86992494c88ee2a7d00aa09">GetStride</a> ()=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1601937201165632"><a name="p1601937201165632"></a><a name="p1601937201165632"></a>virtual uint32_t </p>
<p id="p1572817281165632"><a name="p1572817281165632"></a><a name="p1572817281165632"></a>Obtains the stride of the surface. </p>
</td>
</tr>
<tr id="row751150306165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1152320287165632"><a name="p1152320287165632"></a><a name="p1152320287165632"></a><a href="surface.md#ga3b2391ee37e762fa0fb093585c084714">SetSize</a> (uint32_t size)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p645673400165632"><a name="p645673400165632"></a><a name="p645673400165632"></a>virtual void </p>
<p id="p1564241572165632"><a name="p1564241572165632"></a><a name="p1564241572165632"></a>Sets the size of the shared memory to allocate. </p>
</td>
</tr>
<tr id="row1934481536165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1051327818165632"><a name="p1051327818165632"></a><a name="p1051327818165632"></a><a href="surface.md#ga88e74ff7dc0ae3beb23df3ed00a81fc9">GetSize</a> ()=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1337431191165632"><a name="p1337431191165632"></a><a name="p1337431191165632"></a>virtual uint32_t </p>
<p id="p1566072559165632"><a name="p1566072559165632"></a><a name="p1566072559165632"></a>Obtains the size of the shared memory to allocate. </p>
</td>
</tr>
<tr id="row1696085232165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p648216279165632"><a name="p648216279165632"></a><a name="p648216279165632"></a><a href="surface.md#ga01df6145a5fda3ba72c50258634720b8">SetUsage</a> (uint32_t usage)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1015874001165632"><a name="p1015874001165632"></a><a name="p1015874001165632"></a>virtual void </p>
<p id="p1579110831165632"><a name="p1579110831165632"></a><a name="p1579110831165632"></a>Sets the usage scenario of the buffer. Physically contiguous memory and virtual memory (by default) are supported. By default, virtual memory is allocated. </p>
</td>
</tr>
<tr id="row2123060289165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1014457314165632"><a name="p1014457314165632"></a><a name="p1014457314165632"></a><a href="surface.md#ga6a043b41406f282339bb68c1fc4793f9">GetUsage</a> ()=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2090603942165632"><a name="p2090603942165632"></a><a name="p2090603942165632"></a>virtual uint32_t </p>
<p id="p188316302165632"><a name="p188316302165632"></a><a name="p188316302165632"></a>Obtains the usage scenario of the buffer. Physically contiguous memory and virtual memory are supported. </p>
</td>
</tr>
<tr id="row1844366096165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1811398965165632"><a name="p1811398965165632"></a><a name="p1811398965165632"></a><a href="surface.md#gae264fef4c98719a7c34bc85442cd1a5b">SetUserData</a> (const std::string &amp;key, const std::string &amp;value)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1908573541165632"><a name="p1908573541165632"></a><a name="p1908573541165632"></a>virtual void </p>
<p id="p1908227989165632"><a name="p1908227989165632"></a><a name="p1908227989165632"></a>Sets surface user data, which is stored in the format of &lt;key, value&gt;. </p>
</td>
</tr>
<tr id="row1895089736165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p648316834165632"><a name="p648316834165632"></a><a name="p648316834165632"></a><a href="surface.md#gadd1c8826fd3191cd5f6a52594c5ef3ba">GetUserData</a> (const std::string &amp;key)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1998959135165632"><a name="p1998959135165632"></a><a name="p1998959135165632"></a>virtual std::string </p>
<p id="p1291744346165632"><a name="p1291744346165632"></a><a name="p1291744346165632"></a>Obtains surface user data. </p>
</td>
</tr>
<tr id="row1200996296165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p194399853165632"><a name="p194399853165632"></a><a name="p194399853165632"></a><a href="surface.md#gacc46ffcd4258b2660dc6cde05854c4ac">RequestBuffer</a> (uint8_t <a href="process.md#gabf2fbcf6df59fd5234e9eed4db1a1804">wait</a>=0)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p925354487165632"><a name="p925354487165632"></a><a name="p925354487165632"></a>virtual <a href="ohos-surfacebuffer.md">SurfaceBuffer</a> * </p>
<p id="p1021369407165632"><a name="p1021369407165632"></a><a name="p1021369407165632"></a>Obtains a buffer to write data. </p>
</td>
</tr>
<tr id="row1435595864165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p90094487165632"><a name="p90094487165632"></a><a name="p90094487165632"></a><a href="surface.md#ga8af29f3c031c1b3effe8de7366579329">FlushBuffer</a> (<a href="ohos-surfacebuffer.md">SurfaceBuffer</a> *buffer)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2021001064165632"><a name="p2021001064165632"></a><a name="p2021001064165632"></a>virtual int32_t </p>
<p id="p1096946680165632"><a name="p1096946680165632"></a><a name="p1096946680165632"></a>Flushes a buffer to the dirty queue for consumers to use. </p>
</td>
</tr>
<tr id="row1309675002165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2130893852165632"><a name="p2130893852165632"></a><a name="p2130893852165632"></a><a href="surface.md#ga7acd9899b1ca4eb02ed13d54c2aca0af">AcquireBuffer</a> ()=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1889739012165632"><a name="p1889739012165632"></a><a name="p1889739012165632"></a>virtual <a href="ohos-surfacebuffer.md">SurfaceBuffer</a> * </p>
<p id="p1403614607165632"><a name="p1403614607165632"></a><a name="p1403614607165632"></a>Obtains a buffer. </p>
</td>
</tr>
<tr id="row1188675043165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p740579970165632"><a name="p740579970165632"></a><a name="p740579970165632"></a><a href="surface.md#ga4150c81248f516882ef120731d9abb66">ReleaseBuffer</a> (<a href="ohos-surfacebuffer.md">SurfaceBuffer</a> *buffer)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1630258093165632"><a name="p1630258093165632"></a><a name="p1630258093165632"></a>virtual bool </p>
<p id="p312075768165632"><a name="p312075768165632"></a><a name="p312075768165632"></a>Releases the consumed buffer. </p>
</td>
</tr>
<tr id="row1531353708165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p238763687165632"><a name="p238763687165632"></a><a name="p238763687165632"></a><a href="surface.md#ga6bae4ebcdc4e300eb5a076054f3379e4">CancelBuffer</a> (<a href="ohos-surfacebuffer.md">SurfaceBuffer</a> *buffer)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1496118336165632"><a name="p1496118336165632"></a><a name="p1496118336165632"></a>virtual void </p>
<p id="p1856789477165632"><a name="p1856789477165632"></a><a name="p1856789477165632"></a>Releases a buffer to the free queue. </p>
</td>
</tr>
<tr id="row1721875554165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1016221752165632"><a name="p1016221752165632"></a><a name="p1016221752165632"></a><a href="surface.md#ga4b997a5b9493ad6d2015f86766f12b02">RegisterConsumerListener</a> (<a href="ohos-ibufferconsumerlistener.md">IBufferConsumerListener</a> &amp;listener)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p827804244165632"><a name="p827804244165632"></a><a name="p827804244165632"></a>virtual void </p>
<p id="p16154506165632"><a name="p16154506165632"></a><a name="p16154506165632"></a>Registers a consumer listener. </p>
</td>
</tr>
<tr id="row2114642655165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p189680282165632"><a name="p189680282165632"></a><a name="p189680282165632"></a><a href="surface.md#ga0f303409d32d8d2b467888bf8fdc3223">UnregisterConsumerListener</a> ()=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1499873932165632"><a name="p1499873932165632"></a><a name="p1499873932165632"></a>virtual void </p>
<p id="p1950305392165632"><a name="p1950305392165632"></a><a name="p1950305392165632"></a>Unregisters the consumer listener. </p>
</td>
</tr>
</tbody>
</table>

## Static Public Member Functions<a name="pub-static-methods"></a>

<a name="table1110829575165632"></a>
<table><thead align="left"><tr id="row1155988086165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1587683966165632"><a name="p1587683966165632"></a><a name="p1587683966165632"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2016349056165632"><a name="p2016349056165632"></a><a name="p2016349056165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2008949728165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1259936867165632"><a name="p1259936867165632"></a><a name="p1259936867165632"></a><a href="surface.md#ga49d6a759bec670ea5a47bee4eb252ae3">CreateSurface</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1754450069165632"><a name="p1754450069165632"></a><a name="p1754450069165632"></a>static <a href="ohos-surface.md">Surface</a> * </p>
<p id="p2124023241165632"><a name="p2124023241165632"></a><a name="p2124023241165632"></a>A constructor used to create a <a href="surface.md">Surface</a> object for consumers to use. </p>
</td>
</tr>
</tbody>
</table>

