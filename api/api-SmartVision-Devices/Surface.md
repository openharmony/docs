# Surface<a name="ZH-CN_TOPIC_0000001054479515"></a>

-   [Overview](#section528608066165625)
-   [Summary](#section2009569207165625)
-   [Files](#files)
-   [Data Structures](#nested-classes)
-   [Enumerations](#enum-members)
-   [Functions](#func-members)
-   [Details](#section1212638750165625)
-   [Enumeration Type](#section979445521165625)
-   [BufferConsumerUsage](#ga16d4d4f73d748455e45924ffbdd1e891)
-   [ImagePixelFormat](#gaa191d6e3b92a0f527744d43e056ae025)
-   [Function](#section158831175165625)
-   [AcquireBuffer\(\)](#ga7acd9899b1ca4eb02ed13d54c2aca0af)
-   [CancelBuffer\(\)](#ga6bae4ebcdc4e300eb5a076054f3379e4)
-   [CreateSurface\(\)](#ga49d6a759bec670ea5a47bee4eb252ae3)
-   [FlushBuffer\(\)](#ga8af29f3c031c1b3effe8de7366579329)
-   [GetFormat\(\)](#ga461caa118503a471c78ea09a8403a6ec)
-   [GetHeight\(\)](#ga0e6be0887bd69cf749c0d994bd826699)
-   [GetInt32\(\)](#ga54a916606158a8799fe421eb3842848e)
-   [GetInt64\(\)](#ga3a442c71aee865c7b7a9bb6505ce800a)
-   [GetPhyAddr\(\)](#ga5d797958fed83fdea15b3f6ad5ddf97e)
-   [GetQueueSize\(\)](#gaff365f4d3178798ff28f0aaab9f467de)
-   [GetSize\(\) \[1/2\]](#gaad9d0ca349b3f398b31c38ac9a650138)
-   [GetSize\(\) \[2/2\]](#ga88e74ff7dc0ae3beb23df3ed00a81fc9)
-   [GetStride\(\)](#ga5aabbb48f86992494c88ee2a7d00aa09)
-   [GetStrideAlignment\(\)](#ga0d5317e6a008b8fd0ee98ebd516a0e7c)
-   [GetUsage\(\)](#ga6a043b41406f282339bb68c1fc4793f9)
-   [GetUserData\(\)](#gadd1c8826fd3191cd5f6a52594c5ef3ba)
-   [GetVirAddr\(\)](#ga623d6c8ced742a36017bb71f6441b2a7)
-   [GetWidth\(\)](#ga1220bd15e73d891105d310cf37422b56)
-   [OnBufferAvailable\(\)](#ga9a99aa36b37197b2ca409b8f4e7335c7)
-   [RegisterConsumerListener\(\)](#ga4b997a5b9493ad6d2015f86766f12b02)
-   [ReleaseBuffer\(\)](#ga4150c81248f516882ef120731d9abb66)
-   [RequestBuffer\(\)](#gacc46ffcd4258b2660dc6cde05854c4ac)
-   [SetFormat\(\)](#ga8e44c9100296571a9294dc9851ef48dc)
-   [SetInt32\(\)](#gaf4b467cb2d7015d00f4bcf77c5b19875)
-   [SetInt64\(\)](#ga479eea3722e4d8448ead051c2f11cec5)
-   [SetQueueSize\(\)](#ga44138c9aa20a108358da26893b92150c)
-   [SetSize\(\) \[1/2\]](#ga818ee9015ff03d536b9a73d52f36b4f2)
-   [SetSize\(\) \[2/2\]](#ga3b2391ee37e762fa0fb093585c084714)
-   [SetStrideAlignment\(\)](#ga5b27f54101d9d3371038b73373c36530)
-   [SetUsage\(\)](#ga01df6145a5fda3ba72c50258634720b8)
-   [SetUserData\(\)](#gae264fef4c98719a7c34bc85442cd1a5b)
-   [SetWidthAndHeight\(\)](#ga260c12281c283e5a0b63a49f24bd0cc0)
-   [UnregisterConsumerListener\(\)](#ga0f303409d32d8d2b467888bf8fdc3223)
-   [\~Surface\(\)](#ga1d35e9b436057032ec4598f24e31dbfb)

## **Overview**<a name="section528608066165625"></a>

**Description:**

Provides the capabilities of applying for and releasing shared memory in multimedia and graphics scenarios. 

Provides shared memory for multimedia and graphics.

This module is used to apply for and release shared memory and is used by the multimedia and graphics modules across processes.

**Since:**

1.0

**Version:**

1.0

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section2009569207165625"></a>

## Files<a name="files"></a>

<a name="table1586048310165625"></a>
<table><thead align="left"><tr id="row537586621165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1503370647165625"><a name="p1503370647165625"></a><a name="p1503370647165625"></a>File Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1775754957165625"><a name="p1775754957165625"></a><a name="p1775754957165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row420306845165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p236213492165625"><a name="p236213492165625"></a><a name="p236213492165625"></a><a href="ibuffer_consumer_listener-h.md">ibuffer_consumer_listener.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p979147962165625"><a name="p979147962165625"></a><a name="p979147962165625"></a>Declares the consumer listener used to notify consumers when the surface status is updated. </p>
</td>
</tr>
<tr id="row1543186469165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p228335096165625"><a name="p228335096165625"></a><a name="p228335096165625"></a><a href="surface-h.md">surface.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p409821523165625"><a name="p409821523165625"></a><a name="p409821523165625"></a>Provides the capabilities of applying for and releasing shared memory in multimedia and graphics scenarios. </p>
</td>
</tr>
<tr id="row1597523642165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1194998187165625"><a name="p1194998187165625"></a><a name="p1194998187165625"></a><a href="surface_buffer-h.md">surface_buffer.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1322001795165625"><a name="p1322001795165625"></a><a name="p1322001795165625"></a>Provides functions such as setting the virtual address, size, and additional attributes of shared memory. </p>
</td>
</tr>
<tr id="row1461212545165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1292744976165625"><a name="p1292744976165625"></a><a name="p1292744976165625"></a><a href="surface_type-h.md">surface_type.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1973712419165625"><a name="p1973712419165625"></a><a name="p1973712419165625"></a>Provides the capabilities of setting shared memory parameters. </p>
</td>
</tr>
</tbody>
</table>

## Data Structures<a name="nested-classes"></a>

<a name="table142468924165625"></a>
<table><thead align="left"><tr id="row1474653193165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1990755830165625"><a name="p1990755830165625"></a><a name="p1990755830165625"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1157493838165625"><a name="p1157493838165625"></a><a name="p1157493838165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1206370046165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1478465158165625"><a name="p1478465158165625"></a><a name="p1478465158165625"></a><a href="OHOS-IBufferConsumerListener.md">OHOS::IBufferConsumerListener</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1628432551165625"><a name="p1628432551165625"></a><a name="p1628432551165625"></a>Defines the consumer listener used to notify consumers when the surface status is updated. </p>
</td>
</tr>
<tr id="row1232077141165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p353349509165625"><a name="p353349509165625"></a><a name="p353349509165625"></a><a href="OHOS-Surface.md">OHOS::Surface</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1732756678165625"><a name="p1732756678165625"></a><a name="p1732756678165625"></a>Defines the consumer listener used to notify consumers when the surface status is updated. </p>
</td>
</tr>
<tr id="row816352675165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p128686384165625"><a name="p128686384165625"></a><a name="p128686384165625"></a><a href="OHOS-SurfaceBuffer.md">OHOS::SurfaceBuffer</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p533560405165625"><a name="p533560405165625"></a><a name="p533560405165625"></a>Provides functions such as setting the virtual address, size, and additional attributes of shared memory. </p>
</td>
</tr>
</tbody>
</table>

## Enumerations<a name="enum-members"></a>

<a name="table91575023165625"></a>
<table><thead align="left"><tr id="row694496278165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p523764052165625"><a name="p523764052165625"></a><a name="p523764052165625"></a>Enumeration Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1037987833165625"><a name="p1037987833165625"></a><a name="p1037987833165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1318116916165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2104290387165625"><a name="p2104290387165625"></a><a name="p2104290387165625"></a><a href="Surface.md#ga16d4d4f73d748455e45924ffbdd1e891">OHOS::BufferConsumerUsage</a> {   <a href="Surface.md#gga16d4d4f73d748455e45924ffbdd1e891a59c0ac95bd7994b6eda43b34f59c237b">OHOS::BUFFER_CONSUMER_USAGE_SORTWARE</a> = 0, <a href="Surface.md#gga16d4d4f73d748455e45924ffbdd1e891abe0bc63ca1799ca0b2182e908780da7b">OHOS::BUFFER_CONSUMER_USAGE_HARDWARE</a>, <a href="Surface.md#gga16d4d4f73d748455e45924ffbdd1e891a93eebf8af6f264494a57771865c90b08">OHOS::BUFFER_CONSUMER_USAGE_HARDWARE_CONSUMER_CACHE</a>, <a href="Surface.md#gga16d4d4f73d748455e45924ffbdd1e891a7a31f6403b7aa4ba989e7cd5b3eb7a06">OHOS::BUFFER_CONSUMER_USAGE_HARDWARE_PRODUCER_CACHE</a>,   <a href="Surface.md#gga16d4d4f73d748455e45924ffbdd1e891a56aa1994f77d06504c40421f6555f1cf">OHOS::BUFFER_CONSUMER_USAGE_MAX</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p543571007165625"><a name="p543571007165625"></a><a name="p543571007165625"></a>Enumerates shared memory usage scenarios, including physically contiguous memory and virtual memory. </p>
</td>
</tr>
<tr id="row569439841165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1652057538165625"><a name="p1652057538165625"></a><a name="p1652057538165625"></a><a href="Surface.md#gaa191d6e3b92a0f527744d43e056ae025">OHOS::ImagePixelFormat</a> {   <a href="Surface.md#ggaa191d6e3b92a0f527744d43e056ae025a9690a1d8cf1d21fcad76876f122a12ab">OHOS::IMAGE_PIXEL_FORMAT_NONE</a> = 0, <a href="Surface.md#ggaa191d6e3b92a0f527744d43e056ae025aff11848c6a38afb3afdcbeaec2400055">OHOS::IMAGE_PIXEL_FORMAT_RGB565</a> = 101, <a href="Surface.md#ggaa191d6e3b92a0f527744d43e056ae025a9cf3bfb5153d8cf23f4c0d3bb9cc4f43">OHOS::IMAGE_PIXEL_FORMAT_ARGB1555</a>, <a href="Surface.md#ggaa191d6e3b92a0f527744d43e056ae025ad4774f5ba15cf25a3d0951f5986ab0d5">OHOS::IMAGE_PIXEL_FORMAT_RGB888</a>,   <a href="Surface.md#ggaa191d6e3b92a0f527744d43e056ae025a1a18541878a09cbca269918a7ef4796f">OHOS::IMAGE_PIXEL_FORMAT_ARGB8888</a>, <a href="Surface.md#ggaa191d6e3b92a0f527744d43e056ae025affcb2a4b4832e3c33789f9e8efffe7b0">OHOS::IMAGE_PIXEL_FORMAT_YUYV</a> = 201, <a href="Surface.md#ggaa191d6e3b92a0f527744d43e056ae025a4ec5bc985a5f49f26178ab18c074cfa6">OHOS::IMAGE_PIXEL_FORMAT_YVYU</a>, <a href="Surface.md#ggaa191d6e3b92a0f527744d43e056ae025a098b93504ac8e11c4d5d488930187f37">OHOS::IMAGE_PIXEL_FORMAT_UYVY</a>,   <a href="Surface.md#ggaa191d6e3b92a0f527744d43e056ae025a0e242cad6dae11690013c6771b80fc9b">OHOS::IMAGE_PIXEL_FORMAT_VYUY</a>, <a href="Surface.md#ggaa191d6e3b92a0f527744d43e056ae025ab690ca190de1686041f0d0c320427b1c">OHOS::IMAGE_PIXEL_FORMAT_AYUV</a>, <a href="Surface.md#ggaa191d6e3b92a0f527744d43e056ae025aa4e3c6974a86c29cf707f371ad1b0b49">OHOS::IMAGE_PIXEL_FORMAT_YUV410</a>, <a href="Surface.md#ggaa191d6e3b92a0f527744d43e056ae025a3c4c9612392a81fa2d1d305d08064146">OHOS::IMAGE_PIXEL_FORMAT_YVU410</a>,   <a href="Surface.md#ggaa191d6e3b92a0f527744d43e056ae025acc77b028562f155f1099de249b7bffae">OHOS::IMAGE_PIXEL_FORMAT_YUV411</a>, <a href="Surface.md#ggaa191d6e3b92a0f527744d43e056ae025a99cb00970d669d9ba2ac1049d19c60e4">OHOS::IMAGE_PIXEL_FORMAT_YVU411</a>, <a href="Surface.md#ggaa191d6e3b92a0f527744d43e056ae025acf60892315d8aee3d421f75d70db796f">OHOS::IMAGE_PIXEL_FORMAT_YUV420</a>, <a href="Surface.md#ggaa191d6e3b92a0f527744d43e056ae025ac3dfd6c2f350194d2a525a14d9e72b71">OHOS::IMAGE_PIXEL_FORMAT_YVU420</a>,   <a href="Surface.md#ggaa191d6e3b92a0f527744d43e056ae025ae87be6ce296c907d99381d1db48c288f">OHOS::IMAGE_PIXEL_FORMAT_YUV422</a>, <a href="Surface.md#ggaa191d6e3b92a0f527744d43e056ae025ab33d1df10479e267ca7c3cb6102d8dbb">OHOS::IMAGE_PIXEL_FORMAT_YVU422</a>, <a href="Surface.md#ggaa191d6e3b92a0f527744d43e056ae025a7f2a90344e786071a49db0da82b201e4">OHOS::IMAGE_PIXEL_FORMAT_YUV444</a>, <a href="Surface.md#ggaa191d6e3b92a0f527744d43e056ae025a4e18880bae5fa08cbd510f23f549087d">OHOS::IMAGE_PIXEL_FORMAT_YVU444</a>,   <a href="Surface.md#ggaa191d6e3b92a0f527744d43e056ae025a93a54b97b83f6e042c993d045be27a33">OHOS::IMAGE_PIXEL_FORMAT_NV12</a> = 301, <a href="Surface.md#ggaa191d6e3b92a0f527744d43e056ae025ab7d0f6b75189a47fdf613bbbeaa3b628">OHOS::IMAGE_PIXEL_FORMAT_NV21</a>, <a href="Surface.md#ggaa191d6e3b92a0f527744d43e056ae025a5fd084cc32d1fdbe8017fd210a7e3ffa">OHOS::IMAGE_PIXEL_FORMAT_NV16</a>, <a href="Surface.md#ggaa191d6e3b92a0f527744d43e056ae025a77a0063a555db3ca68a304e494f094cf">OHOS::IMAGE_PIXEL_FORMAT_NV61</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p875588127165625"><a name="p875588127165625"></a><a name="p875588127165625"></a>Enumerates a pixel format. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table1229451788165625"></a>
<table><thead align="left"><tr id="row1559159042165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p227047667165625"><a name="p227047667165625"></a><a name="p227047667165625"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1178187698165625"><a name="p1178187698165625"></a><a name="p1178187698165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1258826842165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p141854184165625"><a name="p141854184165625"></a><a name="p141854184165625"></a><a href="Surface.md#ga9a99aa36b37197b2ca409b8f4e7335c7">OHOS::IBufferConsumerListener::OnBufferAvailable</a> ()=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1459544693165625"><a name="p1459544693165625"></a><a name="p1459544693165625"></a>virtual void </p>
<p id="p1557826043165625"><a name="p1557826043165625"></a><a name="p1557826043165625"></a>Called to notify a consumer that a buffer is available for consumption. </p>
</td>
</tr>
<tr id="row764388282165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1742424299165625"><a name="p1742424299165625"></a><a name="p1742424299165625"></a><a href="Surface.md#ga49d6a759bec670ea5a47bee4eb252ae3">OHOS::Surface::CreateSurface</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p338777516165625"><a name="p338777516165625"></a><a name="p338777516165625"></a>static <a href="OHOS-Surface.md">Surface</a> * </p>
<p id="p1403148321165625"><a name="p1403148321165625"></a><a name="p1403148321165625"></a>A constructor used to create a <a href="Surface.md">Surface</a> object for consumers to use. </p>
</td>
</tr>
<tr id="row909114350165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p863348766165625"><a name="p863348766165625"></a><a name="p863348766165625"></a><a href="Surface.md#ga1d35e9b436057032ec4598f24e31dbfb">OHOS::Surface::~Surface</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p969503562165625"><a name="p969503562165625"></a><a name="p969503562165625"></a>virtual </p>
<p id="p561525475165625"><a name="p561525475165625"></a><a name="p561525475165625"></a>A destructor used to delete the <strong id="b1787143436165625"><a name="b1787143436165625"></a><a name="b1787143436165625"></a><a href="OHOS-Surface.md">Surface</a></strong> instance. </p>
</td>
</tr>
<tr id="row563857413165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1058806698165625"><a name="p1058806698165625"></a><a name="p1058806698165625"></a><a href="Surface.md#ga44138c9aa20a108358da26893b92150c">OHOS::Surface::SetQueueSize</a> (uint8_t queueSize)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1657523341165625"><a name="p1657523341165625"></a><a name="p1657523341165625"></a>virtual void </p>
<p id="p1748070088165625"><a name="p1748070088165625"></a><a name="p1748070088165625"></a>Sets the number of buffers that can be allocated to the surface. The default value is <strong id="b1243558217165625"><a name="b1243558217165625"></a><a name="b1243558217165625"></a>1</strong>. The value range is [1, 10]. </p>
</td>
</tr>
<tr id="row1892481305165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1942271090165625"><a name="p1942271090165625"></a><a name="p1942271090165625"></a><a href="Surface.md#gaff365f4d3178798ff28f0aaab9f467de">OHOS::Surface::GetQueueSize</a> ()=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2037438746165625"><a name="p2037438746165625"></a><a name="p2037438746165625"></a>virtual uint8_t </p>
<p id="p1804832329165625"><a name="p1804832329165625"></a><a name="p1804832329165625"></a>Obtains the number of surface buffers that can be allocated to the surface. The default value is <strong id="b2085041710165625"><a name="b2085041710165625"></a><a name="b2085041710165625"></a>1</strong>. The value range is [1, 10]. </p>
</td>
</tr>
<tr id="row1446357229165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1139634117165625"><a name="p1139634117165625"></a><a name="p1139634117165625"></a><a href="Surface.md#ga260c12281c283e5a0b63a49f24bd0cc0">OHOS::Surface::SetWidthAndHeight</a> (uint32_t width, uint32_t height)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p310905935165625"><a name="p310905935165625"></a><a name="p310905935165625"></a>virtual void </p>
<p id="p158917754165625"><a name="p158917754165625"></a><a name="p158917754165625"></a>Sets the width and height of the surface for calculating its stride and size. The default value range of width and height is (0,7680]. </p>
</td>
</tr>
<tr id="row930010333165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2036145929165625"><a name="p2036145929165625"></a><a name="p2036145929165625"></a><a href="Surface.md#ga1220bd15e73d891105d310cf37422b56">OHOS::Surface::GetWidth</a> ()=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1384008594165625"><a name="p1384008594165625"></a><a name="p1384008594165625"></a>virtual uint32_t </p>
<p id="p1769613509165625"><a name="p1769613509165625"></a><a name="p1769613509165625"></a>Obtains the width of the surface. </p>
</td>
</tr>
<tr id="row316508231165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p190410742165625"><a name="p190410742165625"></a><a name="p190410742165625"></a><a href="Surface.md#ga0e6be0887bd69cf749c0d994bd826699">OHOS::Surface::GetHeight</a> ()=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1231149759165625"><a name="p1231149759165625"></a><a name="p1231149759165625"></a>virtual uint32_t </p>
<p id="p1741636623165625"><a name="p1741636623165625"></a><a name="p1741636623165625"></a>Obtains the height of the surface. </p>
</td>
</tr>
<tr id="row1647941158165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p398032664165625"><a name="p398032664165625"></a><a name="p398032664165625"></a><a href="Surface.md#ga8e44c9100296571a9294dc9851ef48dc">OHOS::Surface::SetFormat</a> (uint32_t format)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p352428772165625"><a name="p352428772165625"></a><a name="p352428772165625"></a>virtual void </p>
<p id="p2126451455165625"><a name="p2126451455165625"></a><a name="p2126451455165625"></a>Sets the pixel format of the surface. For details, see <strong id="b1930115861165625"><a name="b1930115861165625"></a><a name="b1930115861165625"></a>ImageFormat</strong>. The default pixel format is <strong id="b1086418013165625"><a name="b1086418013165625"></a><a name="b1086418013165625"></a>IMAGE_PIXEL_FORMAT_RGB565</strong>. </p>
</td>
</tr>
<tr id="row443995273165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2049661138165625"><a name="p2049661138165625"></a><a name="p2049661138165625"></a><a href="Surface.md#ga461caa118503a471c78ea09a8403a6ec">OHOS::Surface::GetFormat</a> ()=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1709476988165625"><a name="p1709476988165625"></a><a name="p1709476988165625"></a>virtual uint32_t </p>
<p id="p64993457165625"><a name="p64993457165625"></a><a name="p64993457165625"></a>Obtains the pixel format of the surface. For details, see <strong id="b1171413717165625"><a name="b1171413717165625"></a><a name="b1171413717165625"></a>ImageFormat</strong>. The default pixel format is <strong id="b247447464165625"><a name="b247447464165625"></a><a name="b247447464165625"></a>IMAGE_PIXEL_FORMAT_RGB565</strong>. </p>
</td>
</tr>
<tr id="row114491282165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1316420195165625"><a name="p1316420195165625"></a><a name="p1316420195165625"></a><a href="Surface.md#ga5b27f54101d9d3371038b73373c36530">OHOS::Surface::SetStrideAlignment</a> (uint32_t strideAlignment)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p887729941165625"><a name="p887729941165625"></a><a name="p887729941165625"></a>virtual void </p>
<p id="p969066821165625"><a name="p969066821165625"></a><a name="p969066821165625"></a>Sets the number of bytes for stride alignment. </p>
</td>
</tr>
<tr id="row1751111962165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1803418478165625"><a name="p1803418478165625"></a><a name="p1803418478165625"></a><a href="Surface.md#ga0d5317e6a008b8fd0ee98ebd516a0e7c">OHOS::Surface::GetStrideAlignment</a> ()=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1108844516165625"><a name="p1108844516165625"></a><a name="p1108844516165625"></a>virtual uint32_t </p>
<p id="p308249767165625"><a name="p308249767165625"></a><a name="p308249767165625"></a>Obtains the number of bytes for stride alignment. By default, 4-byte aligned is used. </p>
</td>
</tr>
<tr id="row865095868165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1166653882165625"><a name="p1166653882165625"></a><a name="p1166653882165625"></a><a href="Surface.md#ga5aabbb48f86992494c88ee2a7d00aa09">OHOS::Surface::GetStride</a> ()=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2118645225165625"><a name="p2118645225165625"></a><a name="p2118645225165625"></a>virtual uint32_t </p>
<p id="p1733667781165625"><a name="p1733667781165625"></a><a name="p1733667781165625"></a>Obtains the stride of the surface. </p>
</td>
</tr>
<tr id="row2104004426165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2072471723165625"><a name="p2072471723165625"></a><a name="p2072471723165625"></a><a href="Surface.md#ga3b2391ee37e762fa0fb093585c084714">OHOS::Surface::SetSize</a> (uint32_t size)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1055533831165625"><a name="p1055533831165625"></a><a name="p1055533831165625"></a>virtual void </p>
<p id="p162236458165625"><a name="p162236458165625"></a><a name="p162236458165625"></a>Sets the size of the shared memory to allocate. </p>
</td>
</tr>
<tr id="row1774512895165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p466775643165625"><a name="p466775643165625"></a><a name="p466775643165625"></a><a href="Surface.md#ga88e74ff7dc0ae3beb23df3ed00a81fc9">OHOS::Surface::GetSize</a> ()=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p319145705165625"><a name="p319145705165625"></a><a name="p319145705165625"></a>virtual uint32_t </p>
<p id="p651659757165625"><a name="p651659757165625"></a><a name="p651659757165625"></a>Obtains the size of the shared memory to allocate. </p>
</td>
</tr>
<tr id="row1653288168165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p515192085165625"><a name="p515192085165625"></a><a name="p515192085165625"></a><a href="Surface.md#ga01df6145a5fda3ba72c50258634720b8">OHOS::Surface::SetUsage</a> (uint32_t usage)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1043323210165625"><a name="p1043323210165625"></a><a name="p1043323210165625"></a>virtual void </p>
<p id="p1810905630165625"><a name="p1810905630165625"></a><a name="p1810905630165625"></a>Sets the usage scenario of the buffer. Physically contiguous memory and virtual memory (by default) are supported. By default, virtual memory is allocated. </p>
</td>
</tr>
<tr id="row1933096457165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1318603433165625"><a name="p1318603433165625"></a><a name="p1318603433165625"></a><a href="Surface.md#ga6a043b41406f282339bb68c1fc4793f9">OHOS::Surface::GetUsage</a> ()=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1715186815165625"><a name="p1715186815165625"></a><a name="p1715186815165625"></a>virtual uint32_t </p>
<p id="p1879253229165625"><a name="p1879253229165625"></a><a name="p1879253229165625"></a>Obtains the usage scenario of the buffer. Physically contiguous memory and virtual memory are supported. </p>
</td>
</tr>
<tr id="row1687217428165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p417717348165625"><a name="p417717348165625"></a><a name="p417717348165625"></a><a href="Surface.md#gae264fef4c98719a7c34bc85442cd1a5b">OHOS::Surface::SetUserData</a> (const std::string &amp;key, const std::string &amp;value)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p982465935165625"><a name="p982465935165625"></a><a name="p982465935165625"></a>virtual void </p>
<p id="p322459362165625"><a name="p322459362165625"></a><a name="p322459362165625"></a>Sets surface user data, which is stored in the format of &lt;key, value&gt;. </p>
</td>
</tr>
<tr id="row246295166165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p696757416165625"><a name="p696757416165625"></a><a name="p696757416165625"></a><a href="Surface.md#gadd1c8826fd3191cd5f6a52594c5ef3ba">OHOS::Surface::GetUserData</a> (const std::string &amp;key)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1138918407165625"><a name="p1138918407165625"></a><a name="p1138918407165625"></a>virtual std::string </p>
<p id="p409687968165625"><a name="p409687968165625"></a><a name="p409687968165625"></a>Obtains surface user data. </p>
</td>
</tr>
<tr id="row307235021165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p366231422165625"><a name="p366231422165625"></a><a name="p366231422165625"></a><a href="Surface.md#gacc46ffcd4258b2660dc6cde05854c4ac">OHOS::Surface::RequestBuffer</a> (uint8_t <a href="PROCESS.md#gabf2fbcf6df59fd5234e9eed4db1a1804">wait</a>=0)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1427304454165625"><a name="p1427304454165625"></a><a name="p1427304454165625"></a>virtual <a href="OHOS-SurfaceBuffer.md">SurfaceBuffer</a> * </p>
<p id="p257697354165625"><a name="p257697354165625"></a><a name="p257697354165625"></a>Obtains a buffer to write data. </p>
</td>
</tr>
<tr id="row490271508165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1968692238165625"><a name="p1968692238165625"></a><a name="p1968692238165625"></a><a href="Surface.md#ga8af29f3c031c1b3effe8de7366579329">OHOS::Surface::FlushBuffer</a> (<a href="OHOS-SurfaceBuffer.md">SurfaceBuffer</a> *buffer)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p714661751165625"><a name="p714661751165625"></a><a name="p714661751165625"></a>virtual int32_t </p>
<p id="p1841305180165625"><a name="p1841305180165625"></a><a name="p1841305180165625"></a>Flushes a buffer to the dirty queue for consumers to use. </p>
</td>
</tr>
<tr id="row2040948717165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p233758252165625"><a name="p233758252165625"></a><a name="p233758252165625"></a><a href="Surface.md#ga7acd9899b1ca4eb02ed13d54c2aca0af">OHOS::Surface::AcquireBuffer</a> ()=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1161710293165625"><a name="p1161710293165625"></a><a name="p1161710293165625"></a>virtual <a href="OHOS-SurfaceBuffer.md">SurfaceBuffer</a> * </p>
<p id="p972068685165625"><a name="p972068685165625"></a><a name="p972068685165625"></a>Obtains a buffer. </p>
</td>
</tr>
<tr id="row384126377165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p437025407165625"><a name="p437025407165625"></a><a name="p437025407165625"></a><a href="Surface.md#ga4150c81248f516882ef120731d9abb66">OHOS::Surface::ReleaseBuffer</a> (<a href="OHOS-SurfaceBuffer.md">SurfaceBuffer</a> *buffer)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1801799084165625"><a name="p1801799084165625"></a><a name="p1801799084165625"></a>virtual bool </p>
<p id="p299255414165625"><a name="p299255414165625"></a><a name="p299255414165625"></a>Releases the consumed buffer. </p>
</td>
</tr>
<tr id="row1234375886165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p293338705165625"><a name="p293338705165625"></a><a name="p293338705165625"></a><a href="Surface.md#ga6bae4ebcdc4e300eb5a076054f3379e4">OHOS::Surface::CancelBuffer</a> (<a href="OHOS-SurfaceBuffer.md">SurfaceBuffer</a> *buffer)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p180271008165625"><a name="p180271008165625"></a><a name="p180271008165625"></a>virtual void </p>
<p id="p1169619386165625"><a name="p1169619386165625"></a><a name="p1169619386165625"></a>Releases a buffer to the free queue. </p>
</td>
</tr>
<tr id="row1660269262165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p288546402165625"><a name="p288546402165625"></a><a name="p288546402165625"></a><a href="Surface.md#ga4b997a5b9493ad6d2015f86766f12b02">OHOS::Surface::RegisterConsumerListener</a> (<a href="OHOS-IBufferConsumerListener.md">IBufferConsumerListener</a> &amp;listener)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p85293839165625"><a name="p85293839165625"></a><a name="p85293839165625"></a>virtual void </p>
<p id="p191358988165625"><a name="p191358988165625"></a><a name="p191358988165625"></a>Registers a consumer listener. </p>
</td>
</tr>
<tr id="row1216482431165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1782565255165625"><a name="p1782565255165625"></a><a name="p1782565255165625"></a><a href="Surface.md#ga0f303409d32d8d2b467888bf8fdc3223">OHOS::Surface::UnregisterConsumerListener</a> ()=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1846197443165625"><a name="p1846197443165625"></a><a name="p1846197443165625"></a>virtual void </p>
<p id="p789762190165625"><a name="p789762190165625"></a><a name="p789762190165625"></a>Unregisters the consumer listener. </p>
</td>
</tr>
<tr id="row1888027921165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p17719977165625"><a name="p17719977165625"></a><a name="p17719977165625"></a><a href="Surface.md#ga623d6c8ced742a36017bb71f6441b2a7">OHOS::SurfaceBuffer::GetVirAddr</a> () const =0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p823124721165625"><a name="p823124721165625"></a><a name="p823124721165625"></a>virtual void * </p>
<p id="p2088480068165625"><a name="p2088480068165625"></a><a name="p2088480068165625"></a>Obtains the virtual address of shared memory for producers and consumers. </p>
</td>
</tr>
<tr id="row1152927937165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1153132691165625"><a name="p1153132691165625"></a><a name="p1153132691165625"></a><a href="Surface.md#ga5d797958fed83fdea15b3f6ad5ddf97e">OHOS::SurfaceBuffer::GetPhyAddr</a> () const =0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p298553439165625"><a name="p298553439165625"></a><a name="p298553439165625"></a>virtual uint64_t </p>
<p id="p409705434165625"><a name="p409705434165625"></a><a name="p409705434165625"></a>Obtains the physical address of shared memory. </p>
</td>
</tr>
<tr id="row225127844165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1438020542165625"><a name="p1438020542165625"></a><a name="p1438020542165625"></a><a href="Surface.md#gaad9d0ca349b3f398b31c38ac9a650138">OHOS::SurfaceBuffer::GetSize</a> () const =0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p830331825165625"><a name="p830331825165625"></a><a name="p830331825165625"></a>virtual uint32_t </p>
<p id="p204352078165625"><a name="p204352078165625"></a><a name="p204352078165625"></a>Obtains the size of shared memory. </p>
</td>
</tr>
<tr id="row1644312799165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1504070675165625"><a name="p1504070675165625"></a><a name="p1504070675165625"></a><a href="Surface.md#ga818ee9015ff03d536b9a73d52f36b4f2">OHOS::SurfaceBuffer::SetSize</a> (uint32_t size)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1672185828165625"><a name="p1672185828165625"></a><a name="p1672185828165625"></a>virtual void </p>
<p id="p500159432165625"><a name="p500159432165625"></a><a name="p500159432165625"></a>Sets the size of shared memory. </p>
</td>
</tr>
<tr id="row2056875335165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1045654040165625"><a name="p1045654040165625"></a><a name="p1045654040165625"></a><a href="Surface.md#gaf4b467cb2d7015d00f4bcf77c5b19875">OHOS::SurfaceBuffer::SetInt32</a> (uint32_t key, int32_t value)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1507817988165625"><a name="p1507817988165625"></a><a name="p1507817988165625"></a>virtual int32_t </p>
<p id="p2015457635165625"><a name="p2015457635165625"></a><a name="p2015457635165625"></a>Sets an extra attribute value of the int32 type. </p>
</td>
</tr>
<tr id="row992527543165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1950601704165625"><a name="p1950601704165625"></a><a name="p1950601704165625"></a><a href="Surface.md#ga54a916606158a8799fe421eb3842848e">OHOS::SurfaceBuffer::GetInt32</a> (uint32_t key, int32_t &amp;value)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1393510644165625"><a name="p1393510644165625"></a><a name="p1393510644165625"></a>virtual int32_t </p>
<p id="p1625670627165625"><a name="p1625670627165625"></a><a name="p1625670627165625"></a>Obtains an extra attribute value of the int32 type. </p>
</td>
</tr>
<tr id="row1282813798165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p687566889165625"><a name="p687566889165625"></a><a name="p687566889165625"></a><a href="Surface.md#ga479eea3722e4d8448ead051c2f11cec5">OHOS::SurfaceBuffer::SetInt64</a> (uint32_t key, int64_t value)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1259422517165625"><a name="p1259422517165625"></a><a name="p1259422517165625"></a>virtual int32_t </p>
<p id="p976704388165625"><a name="p976704388165625"></a><a name="p976704388165625"></a>Sets an extra attribute value of the int64 type. </p>
</td>
</tr>
<tr id="row1719236486165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2103527767165625"><a name="p2103527767165625"></a><a name="p2103527767165625"></a><a href="Surface.md#ga3a442c71aee865c7b7a9bb6505ce800a">OHOS::SurfaceBuffer::GetInt64</a> (uint32_t key, int64_t &amp;value)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2112649363165625"><a name="p2112649363165625"></a><a name="p2112649363165625"></a>virtual int32_t </p>
<p id="p1497470145165625"><a name="p1497470145165625"></a><a name="p1497470145165625"></a>Obtains an extra attribute value of the int64 type. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1212638750165625"></a>

## **Enumeration Type **<a name="section979445521165625"></a>

## BufferConsumerUsage<a name="ga16d4d4f73d748455e45924ffbdd1e891"></a>

```
enum [OHOS::BufferConsumerUsage](Surface.md#ga16d4d4f73d748455e45924ffbdd1e891)
```

 **Description:**

Enumerates shared memory usage scenarios, including physically contiguous memory and virtual memory. 

<a name="table1389965038165625"></a>
<table><thead align="left"><tr id="row568698202165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1653433937165625"><a name="p1653433937165625"></a><a name="p1653433937165625"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p241204061165625"><a name="p241204061165625"></a><a name="p241204061165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row380849695165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga16d4d4f73d748455e45924ffbdd1e891a59c0ac95bd7994b6eda43b34f59c237b"><a name="gga16d4d4f73d748455e45924ffbdd1e891a59c0ac95bd7994b6eda43b34f59c237b"></a><a name="gga16d4d4f73d748455e45924ffbdd1e891a59c0ac95bd7994b6eda43b34f59c237b"></a></strong>BUFFER_CONSUMER_USAGE_SORTWARE </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1116083499165625"><a name="p1116083499165625"></a><a name="p1116083499165625"></a>Virtual memory </p>
 </td>
</tr>
<tr id="row1963490970165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga16d4d4f73d748455e45924ffbdd1e891abe0bc63ca1799ca0b2182e908780da7b"><a name="gga16d4d4f73d748455e45924ffbdd1e891abe0bc63ca1799ca0b2182e908780da7b"></a><a name="gga16d4d4f73d748455e45924ffbdd1e891abe0bc63ca1799ca0b2182e908780da7b"></a></strong>BUFFER_CONSUMER_USAGE_HARDWARE </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p708737568165625"><a name="p708737568165625"></a><a name="p708737568165625"></a>Physically contiguous memory. The cache is not used. </p>
 </td>
</tr>
<tr id="row648121233165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga16d4d4f73d748455e45924ffbdd1e891a93eebf8af6f264494a57771865c90b08"><a name="gga16d4d4f73d748455e45924ffbdd1e891a93eebf8af6f264494a57771865c90b08"></a><a name="gga16d4d4f73d748455e45924ffbdd1e891a93eebf8af6f264494a57771865c90b08"></a></strong>BUFFER_CONSUMER_USAGE_HARDWARE_CONSUMER_CACHE </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1669749311165625"><a name="p1669749311165625"></a><a name="p1669749311165625"></a>Physically contiguous memory. Consumers use the cache. </p>
 </td>
</tr>
<tr id="row1471717533165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga16d4d4f73d748455e45924ffbdd1e891a7a31f6403b7aa4ba989e7cd5b3eb7a06"><a name="gga16d4d4f73d748455e45924ffbdd1e891a7a31f6403b7aa4ba989e7cd5b3eb7a06"></a><a name="gga16d4d4f73d748455e45924ffbdd1e891a7a31f6403b7aa4ba989e7cd5b3eb7a06"></a></strong>BUFFER_CONSUMER_USAGE_HARDWARE_PRODUCER_CACHE </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1594213726165625"><a name="p1594213726165625"></a><a name="p1594213726165625"></a>Physically contiguous memory. Producers use the cache. </p>
 </td>
</tr>
<tr id="row1037714766165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga16d4d4f73d748455e45924ffbdd1e891a56aa1994f77d06504c40421f6555f1cf"><a name="gga16d4d4f73d748455e45924ffbdd1e891a56aa1994f77d06504c40421f6555f1cf"></a><a name="gga16d4d4f73d748455e45924ffbdd1e891a56aa1994f77d06504c40421f6555f1cf"></a></strong>BUFFER_CONSUMER_USAGE_MAX </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1253735214165625"><a name="p1253735214165625"></a><a name="p1253735214165625"></a>Valid maximum value, used to determine whether the current shared memory usage scenario is within a proper range. </p>
 </td>
</tr>
</tbody>
</table>

## ImagePixelFormat<a name="gaa191d6e3b92a0f527744d43e056ae025"></a>

```
enum [OHOS::ImagePixelFormat](Surface.md#gaa191d6e3b92a0f527744d43e056ae025)
```

 **Description:**

Enumerates a pixel format. 

<a name="table1568066528165625"></a>
<table><thead align="left"><tr id="row1465949037165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p106919255165625"><a name="p106919255165625"></a><a name="p106919255165625"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1841100350165625"><a name="p1841100350165625"></a><a name="p1841100350165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row30496900165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaa191d6e3b92a0f527744d43e056ae025a9690a1d8cf1d21fcad76876f122a12ab"><a name="ggaa191d6e3b92a0f527744d43e056ae025a9690a1d8cf1d21fcad76876f122a12ab"></a><a name="ggaa191d6e3b92a0f527744d43e056ae025a9690a1d8cf1d21fcad76876f122a12ab"></a></strong>IMAGE_PIXEL_FORMAT_NONE </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1807163251165625"><a name="p1807163251165625"></a><a name="p1807163251165625"></a>Invalid pixel format </p>
 </td>
</tr>
<tr id="row1331335501165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaa191d6e3b92a0f527744d43e056ae025aff11848c6a38afb3afdcbeaec2400055"><a name="ggaa191d6e3b92a0f527744d43e056ae025aff11848c6a38afb3afdcbeaec2400055"></a><a name="ggaa191d6e3b92a0f527744d43e056ae025aff11848c6a38afb3afdcbeaec2400055"></a></strong>IMAGE_PIXEL_FORMAT_RGB565 </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p372397345165625"><a name="p372397345165625"></a><a name="p372397345165625"></a>RGB565 pixel format </p>
 </td>
</tr>
<tr id="row2100812136165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaa191d6e3b92a0f527744d43e056ae025a9cf3bfb5153d8cf23f4c0d3bb9cc4f43"><a name="ggaa191d6e3b92a0f527744d43e056ae025a9cf3bfb5153d8cf23f4c0d3bb9cc4f43"></a><a name="ggaa191d6e3b92a0f527744d43e056ae025a9cf3bfb5153d8cf23f4c0d3bb9cc4f43"></a></strong>IMAGE_PIXEL_FORMAT_ARGB1555 </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p590098413165625"><a name="p590098413165625"></a><a name="p590098413165625"></a>ARGB555 pixel format </p>
 </td>
</tr>
<tr id="row834524439165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaa191d6e3b92a0f527744d43e056ae025ad4774f5ba15cf25a3d0951f5986ab0d5"><a name="ggaa191d6e3b92a0f527744d43e056ae025ad4774f5ba15cf25a3d0951f5986ab0d5"></a><a name="ggaa191d6e3b92a0f527744d43e056ae025ad4774f5ba15cf25a3d0951f5986ab0d5"></a></strong>IMAGE_PIXEL_FORMAT_RGB888 </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p85625058165625"><a name="p85625058165625"></a><a name="p85625058165625"></a>RGB888 pixel format </p>
 </td>
</tr>
<tr id="row2063185300165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaa191d6e3b92a0f527744d43e056ae025a1a18541878a09cbca269918a7ef4796f"><a name="ggaa191d6e3b92a0f527744d43e056ae025a1a18541878a09cbca269918a7ef4796f"></a><a name="ggaa191d6e3b92a0f527744d43e056ae025a1a18541878a09cbca269918a7ef4796f"></a></strong>IMAGE_PIXEL_FORMAT_ARGB8888 </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1228483837165625"><a name="p1228483837165625"></a><a name="p1228483837165625"></a>ARGB8888 pixel format </p>
 </td>
</tr>
<tr id="row1392928639165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaa191d6e3b92a0f527744d43e056ae025affcb2a4b4832e3c33789f9e8efffe7b0"><a name="ggaa191d6e3b92a0f527744d43e056ae025affcb2a4b4832e3c33789f9e8efffe7b0"></a><a name="ggaa191d6e3b92a0f527744d43e056ae025affcb2a4b4832e3c33789f9e8efffe7b0"></a></strong>IMAGE_PIXEL_FORMAT_YUYV </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p534947416165625"><a name="p534947416165625"></a><a name="p534947416165625"></a>YUYV pixel format </p>
 </td>
</tr>
<tr id="row538926618165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaa191d6e3b92a0f527744d43e056ae025a4ec5bc985a5f49f26178ab18c074cfa6"><a name="ggaa191d6e3b92a0f527744d43e056ae025a4ec5bc985a5f49f26178ab18c074cfa6"></a><a name="ggaa191d6e3b92a0f527744d43e056ae025a4ec5bc985a5f49f26178ab18c074cfa6"></a></strong>IMAGE_PIXEL_FORMAT_YVYU </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2143501104165625"><a name="p2143501104165625"></a><a name="p2143501104165625"></a>YVYU pixel format </p>
 </td>
</tr>
<tr id="row1696422435165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaa191d6e3b92a0f527744d43e056ae025a098b93504ac8e11c4d5d488930187f37"><a name="ggaa191d6e3b92a0f527744d43e056ae025a098b93504ac8e11c4d5d488930187f37"></a><a name="ggaa191d6e3b92a0f527744d43e056ae025a098b93504ac8e11c4d5d488930187f37"></a></strong>IMAGE_PIXEL_FORMAT_UYVY </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p169523720165625"><a name="p169523720165625"></a><a name="p169523720165625"></a>UYVY pixel format </p>
 </td>
</tr>
<tr id="row859938850165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaa191d6e3b92a0f527744d43e056ae025a0e242cad6dae11690013c6771b80fc9b"><a name="ggaa191d6e3b92a0f527744d43e056ae025a0e242cad6dae11690013c6771b80fc9b"></a><a name="ggaa191d6e3b92a0f527744d43e056ae025a0e242cad6dae11690013c6771b80fc9b"></a></strong>IMAGE_PIXEL_FORMAT_VYUY </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p45549491165625"><a name="p45549491165625"></a><a name="p45549491165625"></a>VYUY pixel format </p>
 </td>
</tr>
<tr id="row572223600165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaa191d6e3b92a0f527744d43e056ae025ab690ca190de1686041f0d0c320427b1c"><a name="ggaa191d6e3b92a0f527744d43e056ae025ab690ca190de1686041f0d0c320427b1c"></a><a name="ggaa191d6e3b92a0f527744d43e056ae025ab690ca190de1686041f0d0c320427b1c"></a></strong>IMAGE_PIXEL_FORMAT_AYUV </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p605249775165625"><a name="p605249775165625"></a><a name="p605249775165625"></a>AYUV pixel format </p>
 </td>
</tr>
<tr id="row377459974165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaa191d6e3b92a0f527744d43e056ae025aa4e3c6974a86c29cf707f371ad1b0b49"><a name="ggaa191d6e3b92a0f527744d43e056ae025aa4e3c6974a86c29cf707f371ad1b0b49"></a><a name="ggaa191d6e3b92a0f527744d43e056ae025aa4e3c6974a86c29cf707f371ad1b0b49"></a></strong>IMAGE_PIXEL_FORMAT_YUV410 </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2047083732165625"><a name="p2047083732165625"></a><a name="p2047083732165625"></a>YUV410 pixel format </p>
 </td>
</tr>
<tr id="row920341862165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaa191d6e3b92a0f527744d43e056ae025a3c4c9612392a81fa2d1d305d08064146"><a name="ggaa191d6e3b92a0f527744d43e056ae025a3c4c9612392a81fa2d1d305d08064146"></a><a name="ggaa191d6e3b92a0f527744d43e056ae025a3c4c9612392a81fa2d1d305d08064146"></a></strong>IMAGE_PIXEL_FORMAT_YVU410 </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p404778838165625"><a name="p404778838165625"></a><a name="p404778838165625"></a>YVU410 pixel format </p>
 </td>
</tr>
<tr id="row1687643437165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaa191d6e3b92a0f527744d43e056ae025acc77b028562f155f1099de249b7bffae"><a name="ggaa191d6e3b92a0f527744d43e056ae025acc77b028562f155f1099de249b7bffae"></a><a name="ggaa191d6e3b92a0f527744d43e056ae025acc77b028562f155f1099de249b7bffae"></a></strong>IMAGE_PIXEL_FORMAT_YUV411 </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1720080686165625"><a name="p1720080686165625"></a><a name="p1720080686165625"></a>YUV411 pixel format </p>
 </td>
</tr>
<tr id="row1308828509165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaa191d6e3b92a0f527744d43e056ae025a99cb00970d669d9ba2ac1049d19c60e4"><a name="ggaa191d6e3b92a0f527744d43e056ae025a99cb00970d669d9ba2ac1049d19c60e4"></a><a name="ggaa191d6e3b92a0f527744d43e056ae025a99cb00970d669d9ba2ac1049d19c60e4"></a></strong>IMAGE_PIXEL_FORMAT_YVU411 </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1826387310165625"><a name="p1826387310165625"></a><a name="p1826387310165625"></a>YVU411 pixel format </p>
 </td>
</tr>
<tr id="row946209310165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaa191d6e3b92a0f527744d43e056ae025acf60892315d8aee3d421f75d70db796f"><a name="ggaa191d6e3b92a0f527744d43e056ae025acf60892315d8aee3d421f75d70db796f"></a><a name="ggaa191d6e3b92a0f527744d43e056ae025acf60892315d8aee3d421f75d70db796f"></a></strong>IMAGE_PIXEL_FORMAT_YUV420 </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1407216796165625"><a name="p1407216796165625"></a><a name="p1407216796165625"></a>YUV420 pixel format </p>
 </td>
</tr>
<tr id="row1111635568165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaa191d6e3b92a0f527744d43e056ae025ac3dfd6c2f350194d2a525a14d9e72b71"><a name="ggaa191d6e3b92a0f527744d43e056ae025ac3dfd6c2f350194d2a525a14d9e72b71"></a><a name="ggaa191d6e3b92a0f527744d43e056ae025ac3dfd6c2f350194d2a525a14d9e72b71"></a></strong>IMAGE_PIXEL_FORMAT_YVU420 </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p339108636165625"><a name="p339108636165625"></a><a name="p339108636165625"></a>YVU420 pixel format </p>
 </td>
</tr>
<tr id="row2091785785165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaa191d6e3b92a0f527744d43e056ae025ae87be6ce296c907d99381d1db48c288f"><a name="ggaa191d6e3b92a0f527744d43e056ae025ae87be6ce296c907d99381d1db48c288f"></a><a name="ggaa191d6e3b92a0f527744d43e056ae025ae87be6ce296c907d99381d1db48c288f"></a></strong>IMAGE_PIXEL_FORMAT_YUV422 </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p306355248165625"><a name="p306355248165625"></a><a name="p306355248165625"></a>YUV422 pixel format </p>
 </td>
</tr>
<tr id="row144071394165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaa191d6e3b92a0f527744d43e056ae025ab33d1df10479e267ca7c3cb6102d8dbb"><a name="ggaa191d6e3b92a0f527744d43e056ae025ab33d1df10479e267ca7c3cb6102d8dbb"></a><a name="ggaa191d6e3b92a0f527744d43e056ae025ab33d1df10479e267ca7c3cb6102d8dbb"></a></strong>IMAGE_PIXEL_FORMAT_YVU422 </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1442647838165625"><a name="p1442647838165625"></a><a name="p1442647838165625"></a>YVU422 pixel format </p>
 </td>
</tr>
<tr id="row1748195261165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaa191d6e3b92a0f527744d43e056ae025a7f2a90344e786071a49db0da82b201e4"><a name="ggaa191d6e3b92a0f527744d43e056ae025a7f2a90344e786071a49db0da82b201e4"></a><a name="ggaa191d6e3b92a0f527744d43e056ae025a7f2a90344e786071a49db0da82b201e4"></a></strong>IMAGE_PIXEL_FORMAT_YUV444 </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p768482304165625"><a name="p768482304165625"></a><a name="p768482304165625"></a>YUV444 pixel format </p>
 </td>
</tr>
<tr id="row771910607165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaa191d6e3b92a0f527744d43e056ae025a4e18880bae5fa08cbd510f23f549087d"><a name="ggaa191d6e3b92a0f527744d43e056ae025a4e18880bae5fa08cbd510f23f549087d"></a><a name="ggaa191d6e3b92a0f527744d43e056ae025a4e18880bae5fa08cbd510f23f549087d"></a></strong>IMAGE_PIXEL_FORMAT_YVU444 </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p853376375165625"><a name="p853376375165625"></a><a name="p853376375165625"></a>YVU444 pixel format </p>
 </td>
</tr>
<tr id="row445997767165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaa191d6e3b92a0f527744d43e056ae025a93a54b97b83f6e042c993d045be27a33"><a name="ggaa191d6e3b92a0f527744d43e056ae025a93a54b97b83f6e042c993d045be27a33"></a><a name="ggaa191d6e3b92a0f527744d43e056ae025a93a54b97b83f6e042c993d045be27a33"></a></strong>IMAGE_PIXEL_FORMAT_NV12 </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p157505072165625"><a name="p157505072165625"></a><a name="p157505072165625"></a>NV12 pixel format </p>
 </td>
</tr>
<tr id="row651671828165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaa191d6e3b92a0f527744d43e056ae025ab7d0f6b75189a47fdf613bbbeaa3b628"><a name="ggaa191d6e3b92a0f527744d43e056ae025ab7d0f6b75189a47fdf613bbbeaa3b628"></a><a name="ggaa191d6e3b92a0f527744d43e056ae025ab7d0f6b75189a47fdf613bbbeaa3b628"></a></strong>IMAGE_PIXEL_FORMAT_NV21 </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p726289474165625"><a name="p726289474165625"></a><a name="p726289474165625"></a>NV21 pixel format </p>
 </td>
</tr>
<tr id="row1378670941165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaa191d6e3b92a0f527744d43e056ae025a5fd084cc32d1fdbe8017fd210a7e3ffa"><a name="ggaa191d6e3b92a0f527744d43e056ae025a5fd084cc32d1fdbe8017fd210a7e3ffa"></a><a name="ggaa191d6e3b92a0f527744d43e056ae025a5fd084cc32d1fdbe8017fd210a7e3ffa"></a></strong>IMAGE_PIXEL_FORMAT_NV16 </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1292598744165625"><a name="p1292598744165625"></a><a name="p1292598744165625"></a>NV16 pixel format </p>
 </td>
</tr>
<tr id="row1355029196165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggaa191d6e3b92a0f527744d43e056ae025a77a0063a555db3ca68a304e494f094cf"><a name="ggaa191d6e3b92a0f527744d43e056ae025a77a0063a555db3ca68a304e494f094cf"></a><a name="ggaa191d6e3b92a0f527744d43e056ae025a77a0063a555db3ca68a304e494f094cf"></a></strong>IMAGE_PIXEL_FORMAT_NV61 </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1071031611165625"><a name="p1071031611165625"></a><a name="p1071031611165625"></a>NV61 pixel format </p>
 </td>
</tr>
</tbody>
</table>

## **Function **<a name="section158831175165625"></a>

## AcquireBuffer\(\)<a name="ga7acd9899b1ca4eb02ed13d54c2aca0af"></a>

```
virtual [SurfaceBuffer](OHOS-SurfaceBuffer.md)* OHOS::Surface::AcquireBuffer ()
```

 **Description:**

Obtains a buffer. 

Consumers can use this function to obtain the buffer placed in the dirty queue by producers. If there is no buffer in the queue,  **nullptr**  is returned.

**Returns:**

Returns the pointer to the  [SurfaceBuffer](OHOS-SurfaceBuffer.md)  object. 

## CancelBuffer\(\)<a name="ga6bae4ebcdc4e300eb5a076054f3379e4"></a>

```
virtual void OHOS::Surface::CancelBuffer ([SurfaceBuffer](OHOS-SurfaceBuffer.md) * buffer)
```

 **Description:**

Releases a buffer to the free queue. 

**Parameters:**

<a name="table1918787784165625"></a>
<table><thead align="left"><tr id="row1106722680165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1799421217165625"><a name="p1799421217165625"></a><a name="p1799421217165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1492774417165625"><a name="p1492774417165625"></a><a name="p1492774417165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1808574850165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><a href="OHOS-SurfaceBuffer.md">SurfaceBuffer</a></td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the buffer to be released by producers. </td>
</tr>
</tbody>
</table>

## CreateSurface\(\)<a name="ga49d6a759bec670ea5a47bee4eb252ae3"></a>

```
static [Surface](OHOS-Surface.md)* OHOS::Surface::CreateSurface ()
```

 **Description:**

A constructor used to create a  [Surface](Surface.md)  object for consumers to use. 

In multi-process scenarios, this function is provided for consumers to obtain buffers generated by producers for consumption. In single-process scenarios, this function can be used by both consumers and producers. 

## FlushBuffer\(\)<a name="ga8af29f3c031c1b3effe8de7366579329"></a>

```
virtual int32_t OHOS::Surface::FlushBuffer ([SurfaceBuffer](OHOS-SurfaceBuffer.md) * buffer)
```

 **Description:**

Flushes a buffer to the dirty queue for consumers to use. 

**Parameters:**

<a name="table2118935584165625"></a>
<table><thead align="left"><tr id="row457563171165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1443410734165625"><a name="p1443410734165625"></a><a name="p1443410734165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p874819047165625"><a name="p874819047165625"></a><a name="p874819047165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row431294877165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><a href="OHOS-SurfaceBuffer.md">SurfaceBuffer</a></td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the buffer flushed by producers. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  otherwise. 

## GetFormat\(\)<a name="ga461caa118503a471c78ea09a8403a6ec"></a>

```
virtual uint32_t OHOS::Surface::GetFormat ()
```

 **Description:**

Obtains the pixel format of the surface. For details, see  **ImageFormat**. The default pixel format is  **IMAGE\_PIXEL\_FORMAT\_RGB565**. 

**Returns:**

Returns the pixel format. 

## GetHeight\(\)<a name="ga0e6be0887bd69cf749c0d994bd826699"></a>

```
virtual uint32_t OHOS::Surface::GetHeight ()
```

 **Description:**

Obtains the height of the surface. 

**Returns:**

Returns the surface height, in pixels. 

## GetInt32\(\)<a name="ga54a916606158a8799fe421eb3842848e"></a>

```
virtual int32_t OHOS::SurfaceBuffer::GetInt32 (uint32_t key, int32_t & value )
```

 **Description:**

Obtains an extra attribute value of the int32 type. 

Obtains an extra attribute value of the int32 type, The extra attribute is stored in the format of <key, value\>. Each key corresponds to a value. If the key does not exist or the value is not int32,  **-1**  is returned.

**Parameters:**

<a name="table1184806743165625"></a>
<table><thead align="left"><tr id="row1423102500165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p662587336165625"><a name="p662587336165625"></a><a name="p662587336165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p952788904165625"><a name="p952788904165625"></a><a name="p952788904165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row585759877165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">key</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the key of a key-value pair for which the value is to be obtained. </td>
</tr>
<tr id="row320502109165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">value</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the value of the key-value pair obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  otherwise. 

## GetInt64\(\)<a name="ga3a442c71aee865c7b7a9bb6505ce800a"></a>

```
virtual int32_t OHOS::SurfaceBuffer::GetInt64 (uint32_t key, int64_t & value )
```

 **Description:**

Obtains an extra attribute value of the int64 type. 

Obtains an extra attribute value of the int64 type, The extra attribute is stored in the format of <key, value\>. Each key corresponds to a value. If the key does not exist or the value is not int64,  **-1**  is returned.

**Parameters:**

<a name="table1072928951165625"></a>
<table><thead align="left"><tr id="row245063548165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1532398544165625"><a name="p1532398544165625"></a><a name="p1532398544165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p778520474165625"><a name="p778520474165625"></a><a name="p778520474165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row861793352165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">key</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the key of a key-value pair for which the value is to be obtained. </td>
</tr>
<tr id="row1745338857165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">value</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the value of the key-value pair obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  otherwise. 

## GetPhyAddr\(\)<a name="ga5d797958fed83fdea15b3f6ad5ddf97e"></a>

```
virtual uint64_t OHOS::SurfaceBuffer::GetPhyAddr () const
```

 **Description:**

Obtains the physical address of shared memory. 

**Returns:**

Returns the physical address of shared memory. 

## GetQueueSize\(\)<a name="gaff365f4d3178798ff28f0aaab9f467de"></a>

```
virtual uint8_t OHOS::Surface::GetQueueSize ()
```

 **Description:**

Obtains the number of surface buffers that can be allocated to the surface. The default value is  **1**. The value range is \[1, 10\]. 

**Returns:**

Returns the number of buffers. 

## GetSize\(\) \[1/2\]<a name="gaad9d0ca349b3f398b31c38ac9a650138"></a>

```
virtual uint32_t OHOS::SurfaceBuffer::GetSize () const
```

 **Description:**

Obtains the size of shared memory. 

**Returns:**

Returns the size of shared memory. 

## GetSize\(\) \[2/2\]<a name="ga88e74ff7dc0ae3beb23df3ed00a81fc9"></a>

```
virtual uint32_t OHOS::Surface::GetSize ()
```

 **Description:**

Obtains the size of the shared memory to allocate. 

**Returns:**

Returns the size of the shared memory. 

## GetStride\(\)<a name="ga5aabbb48f86992494c88ee2a7d00aa09"></a>

```
virtual uint32_t OHOS::Surface::GetStride ()
```

 **Description:**

Obtains the stride of the surface. 

**Returns:**

Returns the stride. 

## GetStrideAlignment\(\)<a name="ga0d5317e6a008b8fd0ee98ebd516a0e7c"></a>

```
virtual uint32_t OHOS::Surface::GetStrideAlignment ()
```

 **Description:**

Obtains the number of bytes for stride alignment. By default, 4-byte aligned is used. 

**Returns:**

Returns the number of bytes for stride alignment. 

## GetUsage\(\)<a name="ga6a043b41406f282339bb68c1fc4793f9"></a>

```
virtual uint32_t OHOS::Surface::GetUsage ()
```

 **Description:**

Obtains the usage scenario of the buffer. Physically contiguous memory and virtual memory are supported. 

**Returns:**

Returns the usage scenario of the buffer. For details, see  **BUFFER\_CONSUMER\_USAGE**. 

## GetUserData\(\)<a name="gadd1c8826fd3191cd5f6a52594c5ef3ba"></a>

```
virtual std::string OHOS::Surface::GetUserData (const std::string & key)
```

 **Description:**

Obtains surface user data. 

**Parameters:**

<a name="table650357399165625"></a>
<table><thead align="left"><tr id="row586141783165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1709480902165625"><a name="p1709480902165625"></a><a name="p1709480902165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1534482205165625"><a name="p1534482205165625"></a><a name="p1534482205165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1317900921165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">key</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the key of a key-value pair for which the value is to be obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the value of the key-value pair obtained. 

## GetVirAddr\(\)<a name="ga623d6c8ced742a36017bb71f6441b2a7"></a>

```
virtual void* OHOS::SurfaceBuffer::GetVirAddr () const
```

 **Description:**

Obtains the virtual address of shared memory for producers and consumers. 

**Returns:**

Returns the virtual address of shared memory. 

## GetWidth\(\)<a name="ga1220bd15e73d891105d310cf37422b56"></a>

```
virtual uint32_t OHOS::Surface::GetWidth ()
```

 **Description:**

Obtains the width of the surface. 

**Returns:**

Returns the surface width, in pixels. 

## OnBufferAvailable\(\)<a name="ga9a99aa36b37197b2ca409b8f4e7335c7"></a>

```
virtual void OHOS::IBufferConsumerListener::OnBufferAvailable ()
```

 **Description:**

Called to notify a consumer that a buffer is available for consumption. 

## RegisterConsumerListener\(\)<a name="ga4b997a5b9493ad6d2015f86766f12b02"></a>

```
virtual void OHOS::Surface::RegisterConsumerListener ([IBufferConsumerListener](OHOS-IBufferConsumerListener.md) & listener)
```

 **Description:**

Registers a consumer listener. 

When a buffer is placed in the dirty queue,  **OnBufferAvailable**  is called to notify consumers. If the listener is repeatedly registered, only the latest one is retained.

**Parameters:**

<a name="table2106278433165625"></a>
<table><thead align="left"><tr id="row2113920191165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2037302758165625"><a name="p2037302758165625"></a><a name="p2037302758165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1431108060165625"><a name="p1431108060165625"></a><a name="p1431108060165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row283528409165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><a href="OHOS-IBufferConsumerListener.md">IBufferConsumerListener</a></td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the listener to register. </td>
</tr>
</tbody>
</table>

## ReleaseBuffer\(\)<a name="ga4150c81248f516882ef120731d9abb66"></a>

```
virtual bool OHOS::Surface::ReleaseBuffer ([SurfaceBuffer](OHOS-SurfaceBuffer.md) * buffer)
```

 **Description:**

Releases the consumed buffer. 

After a consumer has used a  [SurfaceBuffer](OHOS-SurfaceBuffer.md)  object, the consumer can release it through  [ReleaseBuffer](Surface.md#ga4150c81248f516882ef120731d9abb66). The released object is placed into the free queue so that producers can apply for the object.

**Parameters:**

<a name="table1236674888165625"></a>
<table><thead align="left"><tr id="row1089269182165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1595485916165625"><a name="p1595485916165625"></a><a name="p1595485916165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2126068758165625"><a name="p2126068758165625"></a><a name="p2126068758165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2065189339165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><a href="OHOS-SurfaceBuffer.md">SurfaceBuffer</a></td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the buffer released. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **true**  if the buffer is released; returns  **false**  otherwise. 

## RequestBuffer\(\)<a name="gacc46ffcd4258b2660dc6cde05854c4ac"></a>

```
virtual [SurfaceBuffer](OHOS-SurfaceBuffer.md)* OHOS::Surface::RequestBuffer (uint8_t wait = 0)
```

 **Description:**

Obtains a buffer to write data. 

**Parameters:**

<a name="table1926591723165625"></a>
<table><thead align="left"><tr id="row1768384052165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p35209673165625"><a name="p35209673165625"></a><a name="p35209673165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p466699923165625"><a name="p466699923165625"></a><a name="p466699923165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row635424479165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">wait</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Specifies whether the function waits for an available buffer. If <strong id="b29962708165625"><a name="b29962708165625"></a><a name="b29962708165625"></a>wait</strong> is <strong id="b847768202165625"><a name="b847768202165625"></a><a name="b847768202165625"></a>1</strong>, the function waits until there is an available buffer in the free queue before returning a pointer. If the <strong id="b1533479543165625"><a name="b1533479543165625"></a><a name="b1533479543165625"></a>wait</strong> is <strong id="b46158302165625"><a name="b46158302165625"></a><a name="b46158302165625"></a>0</strong>, the function does not wait and returns <strong id="b1716765601165625"><a name="b1716765601165625"></a><a name="b1716765601165625"></a>nullptr</strong> if there is no buffer in the free queue. The default value is <strong id="b1441461071165625"><a name="b1441461071165625"></a><a name="b1441461071165625"></a>0</strong>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the pointer to the buffer if the operation is successful; returns  **nullptr**  otherwise. 

## SetFormat\(\)<a name="ga8e44c9100296571a9294dc9851ef48dc"></a>

```
virtual void OHOS::Surface::SetFormat (uint32_t format)
```

 **Description:**

Sets the pixel format of the surface. For details, see  **ImageFormat**. The default pixel format is  **IMAGE\_PIXEL\_FORMAT\_RGB565**. 

**Parameters:**

<a name="table571077180165625"></a>
<table><thead align="left"><tr id="row114995174165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1689780253165625"><a name="p1689780253165625"></a><a name="p1689780253165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p246582294165625"><a name="p246582294165625"></a><a name="p246582294165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1217924501165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">format</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pixel format to be set. </td>
</tr>
</tbody>
</table>

## SetInt32\(\)<a name="gaf4b467cb2d7015d00f4bcf77c5b19875"></a>

```
virtual int32_t OHOS::SurfaceBuffer::SetInt32 (uint32_t key, int32_t value )
```

 **Description:**

Sets an extra attribute value of the int32 type. 

Sets an extra attribute value of the int32 type, The extra attribute is stored in the format of <key, value\>. Each key corresponds to a value. If the same keys are used in two calls, the value in the second call overwrites that in the first call. 

**Parameters:**

<a name="table1382168139165625"></a>
<table><thead align="left"><tr id="row1106510927165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p888154968165625"><a name="p888154968165625"></a><a name="p888154968165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1508667525165625"><a name="p1508667525165625"></a><a name="p1508667525165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row820521800165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">key</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the key of a key-value pair to set. </td>
</tr>
<tr id="row23583261165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">value</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the value of the key-value pair to set. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  otherwise. 

## SetInt64\(\)<a name="ga479eea3722e4d8448ead051c2f11cec5"></a>

```
virtual int32_t OHOS::SurfaceBuffer::SetInt64 (uint32_t key, int64_t value )
```

 **Description:**

Sets an extra attribute value of the int64 type. 

Sets an extra attribute value of the int64 type. The storage mode of the extra attribute is <key, value\>. the value in the second call overwrites that in the first call.

**Parameters:**

<a name="table1701574550165625"></a>
<table><thead align="left"><tr id="row1516197232165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1726300346165625"><a name="p1726300346165625"></a><a name="p1726300346165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p470593468165625"><a name="p470593468165625"></a><a name="p470593468165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1364494013165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">key</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the key of a key-value pair to set. </td>
</tr>
<tr id="row1555114609165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">value</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the value of the key-value pair to set. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  otherwise. 

## SetQueueSize\(\)<a name="ga44138c9aa20a108358da26893b92150c"></a>

```
virtual void OHOS::Surface::SetQueueSize (uint8_t queueSize)
```

 **Description:**

Sets the number of buffers that can be allocated to the surface. The default value is  **1**. The value range is \[1, 10\]. 

**Parameters:**

<a name="table1879448565165625"></a>
<table><thead align="left"><tr id="row1201510581165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1982355514165625"><a name="p1982355514165625"></a><a name="p1982355514165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p31617135165625"><a name="p31617135165625"></a><a name="p31617135165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row90261785165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">queueSize</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the number of buffers to set. </td>
</tr>
</tbody>
</table>

## SetSize\(\) \[1/2\]<a name="ga818ee9015ff03d536b9a73d52f36b4f2"></a>

```
virtual void OHOS::SurfaceBuffer::SetSize (uint32_t size)
```

 **Description:**

Sets the size of shared memory. 

**Parameters:**

<a name="table1867491628165625"></a>
<table><thead align="left"><tr id="row1332047480165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1824299652165625"><a name="p1824299652165625"></a><a name="p1824299652165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p429534642165625"><a name="p429534642165625"></a><a name="p429534642165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1614842625165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">size</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the size of shared memory to set. </td>
</tr>
</tbody>
</table>

## SetSize\(\) \[2/2\]<a name="ga3b2391ee37e762fa0fb093585c084714"></a>

```
virtual void OHOS::Surface::SetSize (uint32_t size)
```

 **Description:**

Sets the size of the shared memory to allocate. 

**Parameters:**

<a name="table933774232165625"></a>
<table><thead align="left"><tr id="row1419586769165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1812741327165625"><a name="p1812741327165625"></a><a name="p1812741327165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p227638167165625"><a name="p227638167165625"></a><a name="p227638167165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row263306120165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">size</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the size of the shared memory. The value range is (0,58982400]. </td>
</tr>
</tbody>
</table>

## SetStrideAlignment\(\)<a name="ga5b27f54101d9d3371038b73373c36530"></a>

```
virtual void OHOS::Surface::SetStrideAlignment (uint32_t strideAlignment)
```

 **Description:**

Sets the number of bytes for stride alignment. 

By default, 4-byte aligned is used. The value range is \[4,32\].

**Parameters:**

<a name="table1444671405165625"></a>
<table><thead align="left"><tr id="row453881637165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p457775564165625"><a name="p457775564165625"></a><a name="p457775564165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p232947219165625"><a name="p232947219165625"></a><a name="p232947219165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1069148305165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">strideAlignment</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the number of bytes for stride alignment. </td>
</tr>
</tbody>
</table>

## SetUsage\(\)<a name="ga01df6145a5fda3ba72c50258634720b8"></a>

```
virtual void OHOS::Surface::SetUsage (uint32_t usage)
```

 **Description:**

Sets the usage scenario of the buffer. Physically contiguous memory and virtual memory \(by default\) are supported. By default, virtual memory is allocated. 

**Parameters:**

<a name="table286399341165625"></a>
<table><thead align="left"><tr id="row829342691165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1174296322165625"><a name="p1174296322165625"></a><a name="p1174296322165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2049103743165625"><a name="p2049103743165625"></a><a name="p2049103743165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1065327243165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">usage</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the usage scenario of the buffer. For details, see <strong id="b165564370165625"><a name="b165564370165625"></a><a name="b165564370165625"></a>BUFFER_CONSUMER_USAGE</strong>. </td>
</tr>
</tbody>
</table>

## SetUserData\(\)<a name="gae264fef4c98719a7c34bc85442cd1a5b"></a>

```
virtual void OHOS::Surface::SetUserData (const std::string & key, const std::string & value )
```

 **Description:**

Sets surface user data, which is stored in the format of <key, value\>. 

**Parameters:**

<a name="table1303187238165625"></a>
<table><thead align="left"><tr id="row1120340800165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p772253373165625"><a name="p772253373165625"></a><a name="p772253373165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p766465145165625"><a name="p766465145165625"></a><a name="p766465145165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2019817559165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">key</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the key of a key-value pair to store. </td>
</tr>
<tr id="row1685018752165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">value</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the value of the key-value pair to store. </td>
</tr>
</tbody>
</table>

## SetWidthAndHeight\(\)<a name="ga260c12281c283e5a0b63a49f24bd0cc0"></a>

```
virtual void OHOS::Surface::SetWidthAndHeight (uint32_t width, uint32_t height )
```

 **Description:**

Sets the width and height of the surface for calculating its stride and size. The default value range of width and height is \(0,7680\]. 

**Parameters:**

<a name="table642257962165625"></a>
<table><thead align="left"><tr id="row405795657165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p862618343165625"><a name="p862618343165625"></a><a name="p862618343165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p126281672165625"><a name="p126281672165625"></a><a name="p126281672165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row389129276165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">width</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the surface width, in pixels. </td>
</tr>
<tr id="row1007034417165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">height</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the surface height, in pixels. </td>
</tr>
</tbody>
</table>

## UnregisterConsumerListener\(\)<a name="ga0f303409d32d8d2b467888bf8fdc3223"></a>

```
virtual void OHOS::Surface::UnregisterConsumerListener ()
```

 **Description:**

Unregisters the consumer listener. 

After the listener is unregistered, no callback is triggered when a buffer is placed in the dirty queue.

## \~Surface\(\)<a name="ga1d35e9b436057032ec4598f24e31dbfb"></a>

```
virtual OHOS::Surface::~Surface ()
```

 **Description:**

A destructor used to delete the  **[Surface](OHOS-Surface.md)**  instance. 

This function releases the surface and all buffers applied for the surface.

