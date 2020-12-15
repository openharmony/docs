# Display<a name="ZH-CN_TOPIC_0000001055198078"></a>

-   [Overview](#section716806483165623)
-   [Summary](#section501188316165623)
-   [Files](#files)
-   [Data Structures](#nested-classes)
-   [Enumerations](#enum-members)
-   [Functions](#func-members)
-   [Details](#section1742640738165623)
-   [Enumeration Type](#section1053702718165623)
-   [BlendType](#gaab1839ed4aab1030dfda801a51e68817)
-   [ColorKey](#ga4fe6fb05c7ba0048b1739d88f4d4878e)
-   [Connection](#gab0845c0c8d309ee865c78b095b00e671)
-   [DispErrCode](#ga12a925dadef7573cd74d63d06824f9b0)
-   [LayerType](#ga56943a0946e5f15e5e58054b8e7a04a4)
-   [MemType](#gabd31f838aefffa46191d0d7dc36a96b2)
-   [MirrorType](#ga08d32376574b541d162d8534adb78fd0)
-   [PixelFormat](#ga60883d4958a60b91661e97027a85072a)
-   [RopType](#ga24265f7618fbdba53d3da4806d3097c4)
-   [TransformType](#gaa65f3b21a9a92ff022e435a7304126d2)
-   [Function](#section2073407938165623)
-   [GfxInitialize\(\)](#ga251580eb0614b601ef2c901c722a59d3)
-   [GfxUninitialize\(\)](#ga32595139adb26cfaacf709661b29b347)
-   [GrallocInitialize\(\)](#ga304347c32a67bf7b20ef5d2b5714e5fa)
-   [GrallocUninitialize\(\)](#ga8842b25f91c247606048ab2d5cdb338f)
-   [LayerInitialize\(\)](#ga061e587306a5d0367ff228d64434c05d)
-   [LayerUninitialize\(\)](#ga4e32b1a65cf243a9ac015b632a4eea0b)

## **Overview**<a name="section716806483165623"></a>

**Description:**

Defines driver functions of the display module.

The driver functions provided for the GUI include the layer, hardware acceleration, memory, and callback functions.

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section501188316165623"></a>

## Files<a name="files"></a>

<a name="table537516762165623"></a>
<table><thead align="left"><tr id="row216252067165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1704405650165623"><a name="p1704405650165623"></a><a name="p1704405650165623"></a>File Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1516243288165623"><a name="p1516243288165623"></a><a name="p1516243288165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row707097491165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p227419883165623"><a name="p227419883165623"></a><a name="p227419883165623"></a><a href="display_gfx-h.md">display_gfx.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p599628780165623"><a name="p599628780165623"></a><a name="p599628780165623"></a>Declares the driver functions for implementing hardware acceleration.</p>
</td>
</tr>
<tr id="row1616331562165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p841181815165623"><a name="p841181815165623"></a><a name="p841181815165623"></a><a href="display_gralloc-h.md">display_gralloc.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p211914915165623"><a name="p211914915165623"></a><a name="p211914915165623"></a>Declares the driver functions for memory.</p>
</td>
</tr>
<tr id="row1951501157165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p282888348165623"><a name="p282888348165623"></a><a name="p282888348165623"></a><a href="display_layer-h.md">display_layer.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p850360625165623"><a name="p850360625165623"></a><a name="p850360625165623"></a>Declares the driver functions for implementing layer operations.</p>
</td>
</tr>
<tr id="row1603376711165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1286580385165623"><a name="p1286580385165623"></a><a name="p1286580385165623"></a><a href="display_type-h.md">display_type.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p345005928165623"><a name="p345005928165623"></a><a name="p345005928165623"></a>Declares the types used by the display driver functions.</p>
</td>
</tr>
</tbody>
</table>

## Data Structures<a name="nested-classes"></a>

<a name="table1587584405165623"></a>
<table><thead align="left"><tr id="row887005062165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1759861662165623"><a name="p1759861662165623"></a><a name="p1759861662165623"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p265309377165623"><a name="p265309377165623"></a><a name="p265309377165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row426383999165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p126944764165623"><a name="p126944764165623"></a><a name="p126944764165623"></a><a href="GfxFuncs.md">GfxFuncs</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1616051926165623"><a name="p1616051926165623"></a><a name="p1616051926165623"></a>Defines pointers to the hardware acceleration driver functions.</p>
</td>
</tr>
<tr id="row721967961165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p780872984165623"><a name="p780872984165623"></a><a name="p780872984165623"></a><a href="GrallocFuncs.md">GrallocFuncs</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1100450115165623"><a name="p1100450115165623"></a><a name="p1100450115165623"></a>Defines pointers to the memory driver functions.</p>
</td>
</tr>
<tr id="row1926328302165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p626237231165623"><a name="p626237231165623"></a><a name="p626237231165623"></a><a href="LayerFuncs.md">LayerFuncs</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p780338980165623"><a name="p780338980165623"></a><a name="p780338980165623"></a>Defines pointers to the layer driver functions.</p>
</td>
</tr>
<tr id="row1782016987165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1241386054165623"><a name="p1241386054165623"></a><a name="p1241386054165623"></a><a href="DisplayInfo.md">DisplayInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1287194800165623"><a name="p1287194800165623"></a><a name="p1287194800165623"></a>Defines display information.</p>
</td>
</tr>
<tr id="row1535800997165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1330499981165623"><a name="p1330499981165623"></a><a name="p1330499981165623"></a><a href="LayerInfo.md">LayerInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1858088893165623"><a name="p1858088893165623"></a><a name="p1858088893165623"></a>Defines layer information.</p>
</td>
</tr>
<tr id="row1567239572165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2133244806165623"><a name="p2133244806165623"></a><a name="p2133244806165623"></a><a href="LayerAlpha.md">LayerAlpha</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p127971617165623"><a name="p127971617165623"></a><a name="p127971617165623"></a>Defines alpha operations on a layer.</p>
</td>
</tr>
<tr id="row1599934535165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p383876122165623"><a name="p383876122165623"></a><a name="p383876122165623"></a><a href="BufferHandle.md">BufferHandle</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p119765705165623"><a name="p119765705165623"></a><a name="p119765705165623"></a>Defines the buffer handle type. The virtual address of a handle maps to its physical address.</p>
</td>
</tr>
<tr id="row2003758758165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p268287870165623"><a name="p268287870165623"></a><a name="p268287870165623"></a><a href="GrallocBuffer.md">GrallocBuffer</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p891969529165623"><a name="p891969529165623"></a><a name="p891969529165623"></a>Defines the memory buffer, including the buffer handle, memory type, memory size, and virtual memory address.</p>
</td>
</tr>
<tr id="row1797467130165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p731469376165623"><a name="p731469376165623"></a><a name="p731469376165623"></a><a href="BufferData.md">BufferData</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p482431277165623"><a name="p482431277165623"></a><a name="p482431277165623"></a>Defines buffer data of a layer, including the virtual and physical memory addresses.</p>
</td>
</tr>
<tr id="row451556557165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p679945638165623"><a name="p679945638165623"></a><a name="p679945638165623"></a><a href="LayerBuffer.md">LayerBuffer</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1913140217165623"><a name="p1913140217165623"></a><a name="p1913140217165623"></a>Defines the buffer, which is used to store layer data.</p>
</td>
</tr>
<tr id="row19166770165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1296914325165623"><a name="p1296914325165623"></a><a name="p1296914325165623"></a><a href="IRect.md">IRect</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1806736183165623"><a name="p1806736183165623"></a><a name="p1806736183165623"></a>Defines the coordinates of the upper left corner of a rectangle as well as its width and height to describe a rectangular area for an image.</p>
</td>
</tr>
<tr id="row1918442961165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1697106975165623"><a name="p1697106975165623"></a><a name="p1697106975165623"></a><a href="ISurface.md">ISurface</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p330810880165623"><a name="p330810880165623"></a><a name="p330810880165623"></a>Stores surface information for hardware acceleration, such as draw image, and bit blit.</p>
</td>
</tr>
<tr id="row1083149448165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2029701399165623"><a name="p2029701399165623"></a><a name="p2029701399165623"></a><a href="ILine.md">ILine</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1587517883165623"><a name="p1587517883165623"></a><a name="p1587517883165623"></a>Describes a line to help draw lines in hardware acceleration.</p>
</td>
</tr>
<tr id="row1533683795165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p324349713165623"><a name="p324349713165623"></a><a name="p324349713165623"></a><a href="ICircle.md">ICircle</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1033268296165623"><a name="p1033268296165623"></a><a name="p1033268296165623"></a>Describes a circle to help draw circles in hardware acceleration.</p>
</td>
</tr>
<tr id="row603479093165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p633021006165623"><a name="p633021006165623"></a><a name="p633021006165623"></a><a href="Rectangle.md">Rectangle</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p320819395165623"><a name="p320819395165623"></a><a name="p320819395165623"></a>Describes a rectangle to help draw rectangles in hardware acceleration.</p>
</td>
</tr>
<tr id="row897952977165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1714689842165623"><a name="p1714689842165623"></a><a name="p1714689842165623"></a><a href="GfxOpt.md">GfxOpt</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p451702884165623"><a name="p451702884165623"></a><a name="p451702884165623"></a>Defines hardware acceleration options.</p>
</td>
</tr>
</tbody>
</table>

## Enumerations<a name="enum-members"></a>

<a name="table1127478572165623"></a>
<table><thead align="left"><tr id="row1460643892165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p230971712165623"><a name="p230971712165623"></a><a name="p230971712165623"></a>Enumeration Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p677571543165623"><a name="p677571543165623"></a><a name="p677571543165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row266404568165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p720719575165623"><a name="p720719575165623"></a><a name="p720719575165623"></a><a href="Display.md#ga12a925dadef7573cd74d63d06824f9b0">DispErrCode</a> {   <a href="Display.md#gga12a925dadef7573cd74d63d06824f9b0a188daac95e787159d50ff9546536035b">DISPLAY_SUCCESS</a> = 0, <a href="Display.md#gga12a925dadef7573cd74d63d06824f9b0afdffc20c71fb142c3e7f01323a31d742">DISPLAY_FAILURE</a> = -1, <a href="Display.md#gga12a925dadef7573cd74d63d06824f9b0a5bdb0a826a652f51e6c82685ae08ede8">DISPLAY_FD_ERR</a> = -2, <a href="Display.md#gga12a925dadef7573cd74d63d06824f9b0a330e09be303bc7056f6115830bbd2370">DISPLAY_PARAM_ERR</a> = -3,   <a href="Display.md#gga12a925dadef7573cd74d63d06824f9b0a82fbcdba6c699059bc04b491c92424ac">DISPLAY_NULL_PTR</a> = -4, <a href="Display.md#gga12a925dadef7573cd74d63d06824f9b0a950a7bc41e893450315da9e73208f8c2">DISPLAY_NOT_SUPPORT</a> = -5, <a href="Display.md#gga12a925dadef7573cd74d63d06824f9b0af186ab511133fa3280c54d2c44358882">DISPLAY_NOMEM</a> = -6, <a href="Display.md#gga12a925dadef7573cd74d63d06824f9b0ac11b678fc04745ff4d91f4398b83c427">DISPLAY_SYS_BUSY</a> = -7,   <a href="Display.md#gga12a925dadef7573cd74d63d06824f9b0ad133674b9f3b857a12791479aaf58cf8">DISPLAY_NOT_PERM</a> = -8 }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1926376506165623"><a name="p1926376506165623"></a><a name="p1926376506165623"></a>Enumerates return values of the functions.</p>
</td>
</tr>
<tr id="row1135315980165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p538292573165623"><a name="p538292573165623"></a><a name="p538292573165623"></a><a href="Display.md#ga56943a0946e5f15e5e58054b8e7a04a4">LayerType</a> { <a href="Display.md#gga56943a0946e5f15e5e58054b8e7a04a4a6ef157ea82a5d4c1715b3cddcca38d6f">LAYER_TYPE_GRAPHIC</a>, <a href="Display.md#gga56943a0946e5f15e5e58054b8e7a04a4ac33e449941bc0e4d039b4b5bed853a78">LAYER_TYPE_OVERLAY</a>, <a href="Display.md#gga56943a0946e5f15e5e58054b8e7a04a4a0aef2c460a206fa00c742219d65be477">LAYER_TYPE_SDIEBAND</a>, <a href="Display.md#gga56943a0946e5f15e5e58054b8e7a04a4acd813c5ad9a2be97c85a97d4bdf1cb57">LAYER_TYPE_BUTT</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p735718474165623"><a name="p735718474165623"></a><a name="p735718474165623"></a>Enumerates layer types.</p>
</td>
</tr>
<tr id="row1275746414165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p764331750165623"><a name="p764331750165623"></a><a name="p764331750165623"></a><a href="Display.md#ga60883d4958a60b91661e97027a85072a">PixelFormat</a> {    <a href="Display.md#gga60883d4958a60b91661e97027a85072aabdea255b6e5f2920977f11d21445b34a">PIXEL_FMT_CLUT8</a> = 0,   <a href="Display.md#gga60883d4958a60b91661e97027a85072aa5740c66a546552c0c5a4bc06850af584">PIXEL_FMT_CLUT1</a>, <a href="Display.md#gga60883d4958a60b91661e97027a85072aabde13e8f357e39981973929309bb0e0e">PIXEL_FMT_CLUT4</a>, <a href="Display.md#gga60883d4958a60b91661e97027a85072aa5fae320872be3ffdda0d371cec048ec6">PIXEL_FMT_RGB_565</a>, <a href="Display.md#gga60883d4958a60b91661e97027a85072aa4c16147153b63d7ba71b257111afdd62">PIXEL_FMT_RGBA_5658</a>,   <a href="Display.md#gga60883d4958a60b91661e97027a85072aaa479ac0d983fde9b4f7f0e1a3b3e230f">PIXEL_FMT_RGBX_4444</a>, <a href="Display.md#gga60883d4958a60b91661e97027a85072aacbb91256e8c45a51410a9f6caae2d04c">PIXEL_FMT_RGBA_4444</a>, <a href="Display.md#gga60883d4958a60b91661e97027a85072aa7d18a83da06902c104208031ed487942">PIXEL_FMT_RGB_444</a>, <a href="Display.md#gga60883d4958a60b91661e97027a85072aa85e5dd1a0e547c0031baffd02abb31a0">PIXEL_FMT_RGBX_5551</a>,   <a href="Display.md#gga60883d4958a60b91661e97027a85072aadc1387526a271d8c6db7729de06474b1">PIXEL_FMT_RGBA_5551</a>, <a href="Display.md#gga60883d4958a60b91661e97027a85072aa720a429fa57133f6e27ef8c8fa1c404a">PIXEL_FMT_RGB_555</a>, <a href="Display.md#gga60883d4958a60b91661e97027a85072aa24a7181b7fb4019e7c19739bd9b65ff0">PIXEL_FMT_RGBX_8888</a>, <a href="Display.md#gga60883d4958a60b91661e97027a85072aa90b462672221691ed66cacb07dd2e05f">PIXEL_FMT_RGBA_8888</a>,   <a href="Display.md#gga60883d4958a60b91661e97027a85072aa7ff77397bf2cf52b4614a46264f8ce01">PIXEL_FMT_RGB_888</a>, <a href="Display.md#gga60883d4958a60b91661e97027a85072aaec581b908c291e2bd0155e25169f9629">PIXEL_FMT_BGR_565</a>, <a href="Display.md#gga60883d4958a60b91661e97027a85072aa6b5a7b35e00fc25146de0c9bf88b0230">PIXEL_FMT_BGRX_4444</a>, <a href="Display.md#gga60883d4958a60b91661e97027a85072aa2f3d4ada099b2e8d84ec4501fbc8bed9">PIXEL_FMT_BGRA_4444</a>,   <a href="Display.md#gga60883d4958a60b91661e97027a85072aaaf1a20dc0a597258cfe6aca806a8e0de">PIXEL_FMT_BGRX_5551</a>, <a href="Display.md#gga60883d4958a60b91661e97027a85072aa2319d4a75dae0b56776fa63d525e308b">PIXEL_FMT_BGRA_5551</a>, <a href="Display.md#gga60883d4958a60b91661e97027a85072aa1b19279f89c8cfb60e7d77ce23cd5f43">PIXEL_FMT_BGRX_8888</a>, <a href="Display.md#gga60883d4958a60b91661e97027a85072aaeb31c670120a1fbc96a0e0887997fe16">PIXEL_FMT_BGRA_8888</a>,   <a href="Display.md#gga60883d4958a60b91661e97027a85072aac73c2a84907a53ed95a329007b5c8992">PIXEL_FMT_YUV_422_I</a>, <a href="Display.md#gga60883d4958a60b91661e97027a85072aabdf1224848278508479ce97f637dd711">PIXEL_FMT_YCBCR_422_SP</a>, <a href="Display.md#gga60883d4958a60b91661e97027a85072aa8bf97d66e26b3aad7c83dfa70e2bc451">PIXEL_FMT_YCRCB_422_SP</a>, <a href="Display.md#gga60883d4958a60b91661e97027a85072aa0d1db50eb492f9073abdd2d662c56396">PIXEL_FMT_YCBCR_420_SP</a>,   <a href="Display.md#gga60883d4958a60b91661e97027a85072aa1fa43c8a197d5c974a35b8bf02ab386e">PIXEL_FMT_YCRCB_420_SP</a>, <a href="Display.md#gga60883d4958a60b91661e97027a85072aaa2fe085e63428ea76e1d975175001dc6">PIXEL_FMT_YCBCR_422_P</a>, <a href="Display.md#gga60883d4958a60b91661e97027a85072aab04eb6e1d940e42f3b4cc20c0a44c4ee">PIXEL_FMT_YCRCB_422_P</a>, <a href="Display.md#gga60883d4958a60b91661e97027a85072aa3d80e785bed28e2b3f5c7df563500962">PIXEL_FMT_YCBCR_420_P</a>,   <a href="Display.md#gga60883d4958a60b91661e97027a85072aa3dc5a0a5ad2f21218b446c477277210a">PIXEL_FMT_YCRCB_420_P</a>, <a href="Display.md#gga60883d4958a60b91661e97027a85072aa3980def5b133584bdb2982a71f07798e">PIXEL_FMT_YUYV_422_PKG</a>, <a href="Display.md#gga60883d4958a60b91661e97027a85072aadfd69bd5b421aad5bdd39d5f33317197">PIXEL_FMT_UYVY_422_PKG</a>, <a href="Display.md#gga60883d4958a60b91661e97027a85072aaf851031c336e8d9f57c940c5f52381f4">PIXEL_FMT_YVYU_422_PKG</a>,   <a href="Display.md#gga60883d4958a60b91661e97027a85072aa317a761939335025379d382074a1541c">PIXEL_FMT_VYUY_422_PKG</a>, <a href="Display.md#gga60883d4958a60b91661e97027a85072aa07086bb3356c9c88959eee00c0982684">PIXEL_FMT_BUTT</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1222029569165623"><a name="p1222029569165623"></a><a name="p1222029569165623"></a>Enumerates pixel formats.</p>
</td>
</tr>
<tr id="row478569474165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1207486108165623"><a name="p1207486108165623"></a><a name="p1207486108165623"></a><a href="Display.md#gaa65f3b21a9a92ff022e435a7304126d2">TransformType</a> {   <a href="Display.md#ggaa65f3b21a9a92ff022e435a7304126d2a68e349e9d45a8eba440e2a7a3ba31ec9">ROTATE_NONE</a> = 0, <a href="Display.md#ggaa65f3b21a9a92ff022e435a7304126d2a685062467b0c1a3164556335b467c886">ROTATE_90</a>, <a href="Display.md#ggaa65f3b21a9a92ff022e435a7304126d2a186263164422bb8f0eb5f7b7d195a3d1">ROTATE_180</a>, <a href="Display.md#ggaa65f3b21a9a92ff022e435a7304126d2a554e734d2a23790b248c5ce39816c18f">ROTATE_270</a>,   <a href="Display.md#ggaa65f3b21a9a92ff022e435a7304126d2a9b6ff871536aeef2a8e3ce4a753988ed">ROTATE_BUTT</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p983316604165623"><a name="p983316604165623"></a><a name="p983316604165623"></a>Enumerates transform types of images.</p>
</td>
</tr>
<tr id="row1415129592165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p84274648165623"><a name="p84274648165623"></a><a name="p84274648165623"></a><a href="Display.md#gabd31f838aefffa46191d0d7dc36a96b2">MemType</a> { <a href="Display.md#ggabd31f838aefffa46191d0d7dc36a96b2ad3379d0af95e2e9dcbcfdb016d1cf9b3">NORMAL_MEM</a> = 0, <a href="Display.md#ggabd31f838aefffa46191d0d7dc36a96b2a2ad949ccc994ad1718cb54929d762700">CACHE_MEM</a>, <a href="Display.md#ggabd31f838aefffa46191d0d7dc36a96b2a79f98876507c94448fed5f6f33683fb7">SHM_MEM</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1581624524165623"><a name="p1581624524165623"></a><a name="p1581624524165623"></a>Enumerates memory types.</p>
</td>
</tr>
<tr id="row1909803207165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1338033246165623"><a name="p1338033246165623"></a><a name="p1338033246165623"></a><a href="Display.md#gaab1839ed4aab1030dfda801a51e68817">BlendType</a> {   <a href="Display.md#ggaab1839ed4aab1030dfda801a51e68817ae410edb34509ca21425fe5872bbc7e2f">BLEND_NONE</a> = 0, <a href="Display.md#ggaab1839ed4aab1030dfda801a51e68817a6330cee419fbdafc0b25f0aa068814e5">BLEND_CLEAR</a>, <a href="Display.md#ggaab1839ed4aab1030dfda801a51e68817af01da0c255cdbf67d0774a67c2d221b5">BLEND_SRC</a>, <a href="Display.md#ggaab1839ed4aab1030dfda801a51e68817ad4c0cd02aa4b5f4849e2b29a26481dde">BLEND_SRCOVER</a>,   <a href="Display.md#ggaab1839ed4aab1030dfda801a51e68817a21f03e8d04a58ed0684b39eb84bdb89f">BLEND_DSTOVER</a>, <a href="Display.md#ggaab1839ed4aab1030dfda801a51e68817a74e681f6c9027bb2cf0bda3b72d2dd9e">BLEND_SRCIN</a>, <a href="Display.md#ggaab1839ed4aab1030dfda801a51e68817a19f528828d75c34e18375219f113d9bb">BLEND_DSTIN</a>, <a href="Display.md#ggaab1839ed4aab1030dfda801a51e68817a404e05a118462520e878c23f89808199">BLEND_SRCOUT</a>,   <a href="Display.md#ggaab1839ed4aab1030dfda801a51e68817ac0dc902b4928413d367376e4c842d909">BLEND_DSTOUT</a>, <a href="Display.md#ggaab1839ed4aab1030dfda801a51e68817ada473c7e3bf2b1102349489416aefefc">BLEND_SRCATOP</a>, <a href="Display.md#ggaab1839ed4aab1030dfda801a51e68817a0129b4506a06b1a6df297bcf685f5f89">BLEND_DSTATOP</a>, <a href="Display.md#ggaab1839ed4aab1030dfda801a51e68817adbdb329830e5b4d9fa2b17d5d6d7894f">BLEND_ADD</a>,   <a href="Display.md#ggaab1839ed4aab1030dfda801a51e68817a167c3b256e051244066d8e53cdd5529d">BLEND_XOR</a>, <a href="Display.md#ggaab1839ed4aab1030dfda801a51e68817a4686a5f30c73982d625a05db021e9b15">BLEND_DST</a>, <a href="Display.md#ggaab1839ed4aab1030dfda801a51e68817ae549aa3794365df8965a2c3853c8da99">BLEND_AKS</a>, <a href="Display.md#ggaab1839ed4aab1030dfda801a51e68817a3cc39f12fa8bceba626a33c2d82a8bf7">BLEND_AKD</a>,   <a href="Display.md#ggaab1839ed4aab1030dfda801a51e68817ad0650812ac2aa9eee228f48ac514b44a">BLEND_BUTT</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1784396786165623"><a name="p1784396786165623"></a><a name="p1784396786165623"></a>Enumerates image blending types.</p>
</td>
</tr>
<tr id="row1124803553165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1971371125165623"><a name="p1971371125165623"></a><a name="p1971371125165623"></a><a href="Display.md#ga24265f7618fbdba53d3da4806d3097c4">RopType</a> {   <a href="Display.md#gga24265f7618fbdba53d3da4806d3097c4a6358a786ec3b81000a07b343424cee0d">ROP_BLACK</a> = 0, <a href="Display.md#gga24265f7618fbdba53d3da4806d3097c4a96c89f7b89a9048d355b4dc467224f4c">ROP_NOTMERGEPEN</a>, <a href="Display.md#gga24265f7618fbdba53d3da4806d3097c4a54d054ea6920cb88f374f70e8d41f934">ROP_MASKNOTPEN</a>, <a href="Display.md#gga24265f7618fbdba53d3da4806d3097c4af4a5d5dc0f15249001cff7ef32fadef1">ROP_NOTCOPYPEN</a>,   <a href="Display.md#gga24265f7618fbdba53d3da4806d3097c4ad777eea18ba9f4e071b00aa060db00e3">ROP_MASKPENNOT</a>, <a href="Display.md#gga24265f7618fbdba53d3da4806d3097c4afa63c8e2a6a39d50954cb6316576b4e9">ROP_NOT</a>, <a href="Display.md#gga24265f7618fbdba53d3da4806d3097c4a79433776e85bb80ad0306ced0b82947c">ROP_XORPEN</a>, <a href="Display.md#gga24265f7618fbdba53d3da4806d3097c4ad6c4d2458a9caaa079a3e5907d636e8a">ROP_NOTMASKPEN</a>,   <a href="Display.md#gga24265f7618fbdba53d3da4806d3097c4a2a069e2105c5b8d4dac5d174c76eb9d4">ROP_MASKPEN</a>, <a href="Display.md#gga24265f7618fbdba53d3da4806d3097c4a33c37c5ce718e876f43141dc5a028375">ROP_NOTXORPEN</a>, <a href="Display.md#gga24265f7618fbdba53d3da4806d3097c4a2acacab882af44bba09878bd58e18695">ROP_NOP</a>, <a href="Display.md#gga24265f7618fbdba53d3da4806d3097c4afaea3c47612082914332b78ca8c331b3">ROP_MERGENOTPEN</a>,   <a href="Display.md#gga24265f7618fbdba53d3da4806d3097c4a91bae697f9dea25ac4d7be011958a45d">ROP_COPYPE</a>, <a href="Display.md#gga24265f7618fbdba53d3da4806d3097c4a3580b77320e4829da046b8739c61d6b8">ROP_MERGEPENNOT</a>, <a href="Display.md#gga24265f7618fbdba53d3da4806d3097c4a8195ac0d37e0d69b2cd71dd7362d3fd3">ROP_MERGEPEN</a>, <a href="Display.md#gga24265f7618fbdba53d3da4806d3097c4a533a614b27da8a81b67ada085b018618">ROP_WHITE</a>,   <a href="Display.md#gga24265f7618fbdba53d3da4806d3097c4aa858b07e214a7f62625e24776806c74b">ROP_BUTT</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p884979879165623"><a name="p884979879165623"></a><a name="p884979879165623"></a>Enumerates ROP types supported by hardware acceleration.</p>
</td>
</tr>
<tr id="row1505814502165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1665746164165623"><a name="p1665746164165623"></a><a name="p1665746164165623"></a><a href="Display.md#ga4fe6fb05c7ba0048b1739d88f4d4878e">ColorKey</a> { <a href="Display.md#gga4fe6fb05c7ba0048b1739d88f4d4878ea629b31de258db2ce01cb757b85bd5273">CKEY_NONE</a> = 0, <a href="Display.md#gga4fe6fb05c7ba0048b1739d88f4d4878ea5e3271e73dce39d0806ff8e9cba011bc">CKEY_SRC</a>, <a href="Display.md#gga4fe6fb05c7ba0048b1739d88f4d4878ea6921c2c202aa69293467baa6c33fae05">CKEY_DST</a>, <a href="Display.md#gga4fe6fb05c7ba0048b1739d88f4d4878ea32cedc8986de2c290bf2ec193d88cabf">CKEY_BUTT</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p761631973165623"><a name="p761631973165623"></a><a name="p761631973165623"></a>Enumerates color key types supported by hardware acceleration.</p>
</td>
</tr>
<tr id="row356740409165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p126660098165623"><a name="p126660098165623"></a><a name="p126660098165623"></a><a href="Display.md#ga08d32376574b541d162d8534adb78fd0">MirrorType</a> { <a href="Display.md#gga08d32376574b541d162d8534adb78fd0a5ad82fcc8af04f92571e185b61eeb309">MIRROR_NONE</a> = 0, <a href="Display.md#gga08d32376574b541d162d8534adb78fd0ae35099d9fd28c2974661bcce36a9ea5c">MIRROR_LR</a>, <a href="Display.md#gga08d32376574b541d162d8534adb78fd0afd82e59546a645fd29bc779c50bfa733">MIRROR_TB</a>, <a href="Display.md#gga08d32376574b541d162d8534adb78fd0ad9e357a2c2f7dc0e3ca5a351ec457410">MIRROR_BUTT</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1814488004165623"><a name="p1814488004165623"></a><a name="p1814488004165623"></a>Enumerates mirror types supported by hardware acceleration.</p>
</td>
</tr>
<tr id="row1786100090165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1012247552165623"><a name="p1012247552165623"></a><a name="p1012247552165623"></a><a href="Display.md#gab0845c0c8d309ee865c78b095b00e671">Connection</a> { <a href="Display.md#ggab0845c0c8d309ee865c78b095b00e671aef2863a469df3ea6871d640e3669a2f2">INVALID</a> = 0, <a href="Display.md#ggab0845c0c8d309ee865c78b095b00e671a7a691a2430ec26878897b5fbc9c22a4c">CONNECTED</a>, <a href="Display.md#ggab0845c0c8d309ee865c78b095b00e671acdaad1112073e3e2ea032424c38c34e1">DISCONNECTED</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1233823516165623"><a name="p1233823516165623"></a><a name="p1233823516165623"></a>Enumerates connection types of hot plugging.</p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table1310341971165623"></a>
<table><thead align="left"><tr id="row342538682165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1112953517165623"><a name="p1112953517165623"></a><a name="p1112953517165623"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p865880734165623"><a name="p865880734165623"></a><a name="p865880734165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row888336299165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1532094131165623"><a name="p1532094131165623"></a><a name="p1532094131165623"></a><a href="Display.md#ga251580eb0614b601ef2c901c722a59d3">GfxInitialize</a> (<a href="GfxFuncs.md">GfxFuncs</a> **funcs)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2109938436165623"><a name="p2109938436165623"></a><a name="p2109938436165623"></a>int32_t</p>
<p id="p746056009165623"><a name="p746056009165623"></a><a name="p746056009165623"></a>Initializes the hardware acceleration module to obtain the pointer to functions for hardware acceleration operations.</p>
</td>
</tr>
<tr id="row760458124165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p246494082165623"><a name="p246494082165623"></a><a name="p246494082165623"></a><a href="Display.md#ga32595139adb26cfaacf709661b29b347">GfxUninitialize</a> (<a href="GfxFuncs.md">GfxFuncs</a> *funcs)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1688877112165623"><a name="p1688877112165623"></a><a name="p1688877112165623"></a>int32_t</p>
<p id="p1615345237165623"><a name="p1615345237165623"></a><a name="p1615345237165623"></a>Deinitializes the hardware acceleration module to release the memory allocated to the pointer to functions for hardware acceleration operations.</p>
</td>
</tr>
<tr id="row973831667165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p186415108165623"><a name="p186415108165623"></a><a name="p186415108165623"></a><a href="Display.md#ga304347c32a67bf7b20ef5d2b5714e5fa">GrallocInitialize</a> (<a href="GrallocFuncs.md">GrallocFuncs</a> **funcs)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p894629112165623"><a name="p894629112165623"></a><a name="p894629112165623"></a>int32_t</p>
<p id="p1751688165165623"><a name="p1751688165165623"></a><a name="p1751688165165623"></a>Initializes the memory module to obtain the pointer to functions for memory operations.</p>
</td>
</tr>
<tr id="row2136651694165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p998556636165623"><a name="p998556636165623"></a><a name="p998556636165623"></a><a href="Display.md#ga8842b25f91c247606048ab2d5cdb338f">GrallocUninitialize</a> (<a href="GrallocFuncs.md">GrallocFuncs</a> *funcs)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1054991245165623"><a name="p1054991245165623"></a><a name="p1054991245165623"></a>int32_t</p>
<p id="p1868794523165623"><a name="p1868794523165623"></a><a name="p1868794523165623"></a>Deinitializes the memory module to release the memory allocated to the pointer to functions for memory operations.</p>
</td>
</tr>
<tr id="row690638744165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p718541914165623"><a name="p718541914165623"></a><a name="p718541914165623"></a><a href="Display.md#ga061e587306a5d0367ff228d64434c05d">LayerInitialize</a> (<a href="LayerFuncs.md">LayerFuncs</a> **funcs)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1389880113165623"><a name="p1389880113165623"></a><a name="p1389880113165623"></a>int32_t</p>
<p id="p1746227155165623"><a name="p1746227155165623"></a><a name="p1746227155165623"></a>Initializes the layer to apply for resources used by the layer and obtain the pointer to functions for layer operations.</p>
</td>
</tr>
<tr id="row1098074958165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p202154806165623"><a name="p202154806165623"></a><a name="p202154806165623"></a><a href="Display.md#ga4e32b1a65cf243a9ac015b632a4eea0b">LayerUninitialize</a> (<a href="LayerFuncs.md">LayerFuncs</a> *funcs)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p822218342165623"><a name="p822218342165623"></a><a name="p822218342165623"></a>int32_t</p>
<p id="p737682573165623"><a name="p737682573165623"></a><a name="p737682573165623"></a>Deinitializes the layer module to release the memory allocated to the pointer to functions for layer operations.</p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1742640738165623"></a>

## **Enumeration Type**<a name="section1053702718165623"></a>

## BlendType<a name="gaab1839ed4aab1030dfda801a51e68817"></a>

```
enum [BlendType](Display.md#gaab1839ed4aab1030dfda801a51e68817)
```

**Description:**

Enumerates image blending types.

The system combines images based on a specified blending type during hardware acceleration.

<a name="table413039206165623"></a>
<table><thead align="left"><tr id="row753284203165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2030265588165623"><a name="p2030265588165623"></a><a name="p2030265588165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1199696026165623"><a name="p1199696026165623"></a><a name="p1199696026165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2046559236165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry837936793165623p0"><a name="entry837936793165623p0"></a><a name="entry837936793165623p0"></a><strong id="ggaab1839ed4aab1030dfda801a51e68817ae410edb34509ca21425fe5872bbc7e2f"><a name="ggaab1839ed4aab1030dfda801a51e68817ae410edb34509ca21425fe5872bbc7e2f"></a><a name="ggaab1839ed4aab1030dfda801a51e68817ae410edb34509ca21425fe5872bbc7e2f"></a></strong>BLEND_NONE</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1357466056165623"><a name="p1357466056165623"></a><a name="p1357466056165623"></a>No blending</p>
<p id="p1614511248202"><a name="p1614511248202"></a><a name="p1614511248202"></a></p>
</td>
</tr>
<tr id="row89063971165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry535997515165623p0"><a name="entry535997515165623p0"></a><a name="entry535997515165623p0"></a><strong id="ggaab1839ed4aab1030dfda801a51e68817a6330cee419fbdafc0b25f0aa068814e5"><a name="ggaab1839ed4aab1030dfda801a51e68817a6330cee419fbdafc0b25f0aa068814e5"></a><a name="ggaab1839ed4aab1030dfda801a51e68817a6330cee419fbdafc0b25f0aa068814e5"></a></strong>BLEND_CLEAR</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p704890478165623"><a name="p704890478165623"></a><a name="p704890478165623"></a>CLEAR blending</p>
<p id="p1614514246200"><a name="p1614514246200"></a><a name="p1614514246200"></a></p>
</td>
</tr>
<tr id="row1115421154165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1988065141165623p0"><a name="entry1988065141165623p0"></a><a name="entry1988065141165623p0"></a><strong id="ggaab1839ed4aab1030dfda801a51e68817af01da0c255cdbf67d0774a67c2d221b5"><a name="ggaab1839ed4aab1030dfda801a51e68817af01da0c255cdbf67d0774a67c2d221b5"></a><a name="ggaab1839ed4aab1030dfda801a51e68817af01da0c255cdbf67d0774a67c2d221b5"></a></strong>BLEND_SRC</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p995336494165623"><a name="p995336494165623"></a><a name="p995336494165623"></a>SRC blending</p>
<p id="p1614522419205"><a name="p1614522419205"></a><a name="p1614522419205"></a></p>
</td>
</tr>
<tr id="row803106613165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry161669425165623p0"><a name="entry161669425165623p0"></a><a name="entry161669425165623p0"></a><strong id="ggaab1839ed4aab1030dfda801a51e68817ad4c0cd02aa4b5f4849e2b29a26481dde"><a name="ggaab1839ed4aab1030dfda801a51e68817ad4c0cd02aa4b5f4849e2b29a26481dde"></a><a name="ggaab1839ed4aab1030dfda801a51e68817ad4c0cd02aa4b5f4849e2b29a26481dde"></a></strong>BLEND_SRCOVER</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1317246876165623"><a name="p1317246876165623"></a><a name="p1317246876165623"></a>SRC_OVER blending</p>
<p id="p3145524102017"><a name="p3145524102017"></a><a name="p3145524102017"></a></p>
</td>
</tr>
<tr id="row1595934208165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry231560463165623p0"><a name="entry231560463165623p0"></a><a name="entry231560463165623p0"></a><strong id="ggaab1839ed4aab1030dfda801a51e68817a21f03e8d04a58ed0684b39eb84bdb89f"><a name="ggaab1839ed4aab1030dfda801a51e68817a21f03e8d04a58ed0684b39eb84bdb89f"></a><a name="ggaab1839ed4aab1030dfda801a51e68817a21f03e8d04a58ed0684b39eb84bdb89f"></a></strong>BLEND_DSTOVER</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1056704047165623"><a name="p1056704047165623"></a><a name="p1056704047165623"></a>DST_OVER blending</p>
<p id="p71453242207"><a name="p71453242207"></a><a name="p71453242207"></a></p>
</td>
</tr>
<tr id="row1317581269165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry278600533165623p0"><a name="entry278600533165623p0"></a><a name="entry278600533165623p0"></a><strong id="ggaab1839ed4aab1030dfda801a51e68817a74e681f6c9027bb2cf0bda3b72d2dd9e"><a name="ggaab1839ed4aab1030dfda801a51e68817a74e681f6c9027bb2cf0bda3b72d2dd9e"></a><a name="ggaab1839ed4aab1030dfda801a51e68817a74e681f6c9027bb2cf0bda3b72d2dd9e"></a></strong>BLEND_SRCIN</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1210480211165623"><a name="p1210480211165623"></a><a name="p1210480211165623"></a>SRC_IN blending</p>
<p id="p314518246200"><a name="p314518246200"></a><a name="p314518246200"></a></p>
</td>
</tr>
<tr id="row854582558165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1224776190165623p0"><a name="entry1224776190165623p0"></a><a name="entry1224776190165623p0"></a><strong id="ggaab1839ed4aab1030dfda801a51e68817a19f528828d75c34e18375219f113d9bb"><a name="ggaab1839ed4aab1030dfda801a51e68817a19f528828d75c34e18375219f113d9bb"></a><a name="ggaab1839ed4aab1030dfda801a51e68817a19f528828d75c34e18375219f113d9bb"></a></strong>BLEND_DSTIN</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p989876765165623"><a name="p989876765165623"></a><a name="p989876765165623"></a>DST_IN blending</p>
<p id="p16145424172019"><a name="p16145424172019"></a><a name="p16145424172019"></a></p>
</td>
</tr>
<tr id="row108922996165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1071063580165623p0"><a name="entry1071063580165623p0"></a><a name="entry1071063580165623p0"></a><strong id="ggaab1839ed4aab1030dfda801a51e68817a404e05a118462520e878c23f89808199"><a name="ggaab1839ed4aab1030dfda801a51e68817a404e05a118462520e878c23f89808199"></a><a name="ggaab1839ed4aab1030dfda801a51e68817a404e05a118462520e878c23f89808199"></a></strong>BLEND_SRCOUT</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1805331609165623"><a name="p1805331609165623"></a><a name="p1805331609165623"></a>SRC_OUT blending</p>
<p id="p1314542412202"><a name="p1314542412202"></a><a name="p1314542412202"></a></p>
</td>
</tr>
<tr id="row1849133275165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1551539808165623p0"><a name="entry1551539808165623p0"></a><a name="entry1551539808165623p0"></a><strong id="ggaab1839ed4aab1030dfda801a51e68817ac0dc902b4928413d367376e4c842d909"><a name="ggaab1839ed4aab1030dfda801a51e68817ac0dc902b4928413d367376e4c842d909"></a><a name="ggaab1839ed4aab1030dfda801a51e68817ac0dc902b4928413d367376e4c842d909"></a></strong>BLEND_DSTOUT</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1035845345165623"><a name="p1035845345165623"></a><a name="p1035845345165623"></a>DST_OUT blending</p>
<p id="p171451243207"><a name="p171451243207"></a><a name="p171451243207"></a></p>
</td>
</tr>
<tr id="row1225216863165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry429762088165623p0"><a name="entry429762088165623p0"></a><a name="entry429762088165623p0"></a><strong id="ggaab1839ed4aab1030dfda801a51e68817ada473c7e3bf2b1102349489416aefefc"><a name="ggaab1839ed4aab1030dfda801a51e68817ada473c7e3bf2b1102349489416aefefc"></a><a name="ggaab1839ed4aab1030dfda801a51e68817ada473c7e3bf2b1102349489416aefefc"></a></strong>BLEND_SRCATOP</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p292426071165623"><a name="p292426071165623"></a><a name="p292426071165623"></a>SRC_ATOP blending</p>
<p id="p10145142414209"><a name="p10145142414209"></a><a name="p10145142414209"></a></p>
</td>
</tr>
<tr id="row650895028165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1196328851165623p0"><a name="entry1196328851165623p0"></a><a name="entry1196328851165623p0"></a><strong id="ggaab1839ed4aab1030dfda801a51e68817a0129b4506a06b1a6df297bcf685f5f89"><a name="ggaab1839ed4aab1030dfda801a51e68817a0129b4506a06b1a6df297bcf685f5f89"></a><a name="ggaab1839ed4aab1030dfda801a51e68817a0129b4506a06b1a6df297bcf685f5f89"></a></strong>BLEND_DSTATOP</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1948198596165623"><a name="p1948198596165623"></a><a name="p1948198596165623"></a>DST_ATOP blending</p>
<p id="p51451624202011"><a name="p51451624202011"></a><a name="p51451624202011"></a></p>
</td>
</tr>
<tr id="row1642050592165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1828427737165623p0"><a name="entry1828427737165623p0"></a><a name="entry1828427737165623p0"></a><strong id="ggaab1839ed4aab1030dfda801a51e68817adbdb329830e5b4d9fa2b17d5d6d7894f"><a name="ggaab1839ed4aab1030dfda801a51e68817adbdb329830e5b4d9fa2b17d5d6d7894f"></a><a name="ggaab1839ed4aab1030dfda801a51e68817adbdb329830e5b4d9fa2b17d5d6d7894f"></a></strong>BLEND_ADD</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p606213176165623"><a name="p606213176165623"></a><a name="p606213176165623"></a>ADD blending</p>
<p id="p16145142416205"><a name="p16145142416205"></a><a name="p16145142416205"></a></p>
</td>
</tr>
<tr id="row596176431165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry390049202165623p0"><a name="entry390049202165623p0"></a><a name="entry390049202165623p0"></a><strong id="ggaab1839ed4aab1030dfda801a51e68817a167c3b256e051244066d8e53cdd5529d"><a name="ggaab1839ed4aab1030dfda801a51e68817a167c3b256e051244066d8e53cdd5529d"></a><a name="ggaab1839ed4aab1030dfda801a51e68817a167c3b256e051244066d8e53cdd5529d"></a></strong>BLEND_XOR</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1219627786165623"><a name="p1219627786165623"></a><a name="p1219627786165623"></a>XOR blending</p>
<p id="p12145182415202"><a name="p12145182415202"></a><a name="p12145182415202"></a></p>
</td>
</tr>
<tr id="row100809110165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1588627463165623p0"><a name="entry1588627463165623p0"></a><a name="entry1588627463165623p0"></a><strong id="ggaab1839ed4aab1030dfda801a51e68817a4686a5f30c73982d625a05db021e9b15"><a name="ggaab1839ed4aab1030dfda801a51e68817a4686a5f30c73982d625a05db021e9b15"></a><a name="ggaab1839ed4aab1030dfda801a51e68817a4686a5f30c73982d625a05db021e9b15"></a></strong>BLEND_DST</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1273764957165623"><a name="p1273764957165623"></a><a name="p1273764957165623"></a>DST blending</p>
<p id="p114512442013"><a name="p114512442013"></a><a name="p114512442013"></a></p>
</td>
</tr>
<tr id="row84873143165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry782951871165623p0"><a name="entry782951871165623p0"></a><a name="entry782951871165623p0"></a><strong id="ggaab1839ed4aab1030dfda801a51e68817ae549aa3794365df8965a2c3853c8da99"><a name="ggaab1839ed4aab1030dfda801a51e68817ae549aa3794365df8965a2c3853c8da99"></a><a name="ggaab1839ed4aab1030dfda801a51e68817ae549aa3794365df8965a2c3853c8da99"></a></strong>BLEND_AKS</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p434799672165623"><a name="p434799672165623"></a><a name="p434799672165623"></a>AKS blending</p>
<p id="p6145524132011"><a name="p6145524132011"></a><a name="p6145524132011"></a></p>
</td>
</tr>
<tr id="row744745065165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1642422937165623p0"><a name="entry1642422937165623p0"></a><a name="entry1642422937165623p0"></a><strong id="ggaab1839ed4aab1030dfda801a51e68817a3cc39f12fa8bceba626a33c2d82a8bf7"><a name="ggaab1839ed4aab1030dfda801a51e68817a3cc39f12fa8bceba626a33c2d82a8bf7"></a><a name="ggaab1839ed4aab1030dfda801a51e68817a3cc39f12fa8bceba626a33c2d82a8bf7"></a></strong>BLEND_AKD</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p312770686165623"><a name="p312770686165623"></a><a name="p312770686165623"></a>AKD blending</p>
<p id="p13145102492013"><a name="p13145102492013"></a><a name="p13145102492013"></a></p>
</td>
</tr>
<tr id="row971927615165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry268410892165623p0"><a name="entry268410892165623p0"></a><a name="entry268410892165623p0"></a><strong id="ggaab1839ed4aab1030dfda801a51e68817ad0650812ac2aa9eee228f48ac514b44a"><a name="ggaab1839ed4aab1030dfda801a51e68817ad0650812ac2aa9eee228f48ac514b44a"></a><a name="ggaab1839ed4aab1030dfda801a51e68817ad0650812ac2aa9eee228f48ac514b44a"></a></strong>BLEND_BUTT</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1778550923165623"><a name="p1778550923165623"></a><a name="p1778550923165623"></a>Null operation</p>
<p id="p1214512241202"><a name="p1214512241202"></a><a name="p1214512241202"></a></p>
</td>
</tr>
</tbody>
</table>

## ColorKey<a name="ga4fe6fb05c7ba0048b1739d88f4d4878e"></a>

```
enum [ColorKey](Display.md#ga4fe6fb05c7ba0048b1739d88f4d4878e)
```

**Description:**

Enumerates color key types supported by hardware acceleration.

<a name="table1603668161165623"></a>
<table><thead align="left"><tr id="row589238850165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1505134189165623"><a name="p1505134189165623"></a><a name="p1505134189165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p557490044165623"><a name="p557490044165623"></a><a name="p557490044165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row601377821165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1449981541165623p0"><a name="entry1449981541165623p0"></a><a name="entry1449981541165623p0"></a><strong id="gga4fe6fb05c7ba0048b1739d88f4d4878ea629b31de258db2ce01cb757b85bd5273"><a name="gga4fe6fb05c7ba0048b1739d88f4d4878ea629b31de258db2ce01cb757b85bd5273"></a><a name="gga4fe6fb05c7ba0048b1739d88f4d4878ea629b31de258db2ce01cb757b85bd5273"></a></strong>CKEY_NONE</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p892140358165623"><a name="p892140358165623"></a><a name="p892140358165623"></a>No color key</p>
<p id="p151617247209"><a name="p151617247209"></a><a name="p151617247209"></a></p>
</td>
</tr>
<tr id="row233622191165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1607005855165623p0"><a name="entry1607005855165623p0"></a><a name="entry1607005855165623p0"></a><strong id="gga4fe6fb05c7ba0048b1739d88f4d4878ea5e3271e73dce39d0806ff8e9cba011bc"><a name="gga4fe6fb05c7ba0048b1739d88f4d4878ea5e3271e73dce39d0806ff8e9cba011bc"></a><a name="gga4fe6fb05c7ba0048b1739d88f4d4878ea5e3271e73dce39d0806ff8e9cba011bc"></a></strong>CKEY_SRC</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p5481830165623"><a name="p5481830165623"></a><a name="p5481830165623"></a>Source color key</p>
<p id="p11161152482011"><a name="p11161152482011"></a><a name="p11161152482011"></a></p>
</td>
</tr>
<tr id="row1476882215165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1172474324165623p0"><a name="entry1172474324165623p0"></a><a name="entry1172474324165623p0"></a><strong id="gga4fe6fb05c7ba0048b1739d88f4d4878ea6921c2c202aa69293467baa6c33fae05"><a name="gga4fe6fb05c7ba0048b1739d88f4d4878ea6921c2c202aa69293467baa6c33fae05"></a><a name="gga4fe6fb05c7ba0048b1739d88f4d4878ea6921c2c202aa69293467baa6c33fae05"></a></strong>CKEY_DST</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p262884702165623"><a name="p262884702165623"></a><a name="p262884702165623"></a>Destination color key</p>
<p id="p8161122418209"><a name="p8161122418209"></a><a name="p8161122418209"></a></p>
</td>
</tr>
<tr id="row349134374165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1096495196165623p0"><a name="entry1096495196165623p0"></a><a name="entry1096495196165623p0"></a><strong id="gga4fe6fb05c7ba0048b1739d88f4d4878ea32cedc8986de2c290bf2ec193d88cabf"><a name="gga4fe6fb05c7ba0048b1739d88f4d4878ea32cedc8986de2c290bf2ec193d88cabf"></a><a name="gga4fe6fb05c7ba0048b1739d88f4d4878ea32cedc8986de2c290bf2ec193d88cabf"></a></strong>CKEY_BUTT</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1938486725165623"><a name="p1938486725165623"></a><a name="p1938486725165623"></a>Null operation</p>
<p id="p1716142452016"><a name="p1716142452016"></a><a name="p1716142452016"></a></p>
</td>
</tr>
</tbody>
</table>

## Connection<a name="gab0845c0c8d309ee865c78b095b00e671"></a>

```
enum [Connection](Display.md#gab0845c0c8d309ee865c78b095b00e671)
```

**Description:**

Enumerates connection types of hot plugging.

<a name="table30436356165623"></a>
<table><thead align="left"><tr id="row1220936257165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2129199887165623"><a name="p2129199887165623"></a><a name="p2129199887165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1170894652165623"><a name="p1170894652165623"></a><a name="p1170894652165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1832996110165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2070178837165623p0"><a name="entry2070178837165623p0"></a><a name="entry2070178837165623p0"></a><strong id="ggab0845c0c8d309ee865c78b095b00e671aef2863a469df3ea6871d640e3669a2f2"><a name="ggab0845c0c8d309ee865c78b095b00e671aef2863a469df3ea6871d640e3669a2f2"></a><a name="ggab0845c0c8d309ee865c78b095b00e671aef2863a469df3ea6871d640e3669a2f2"></a></strong>INVALID</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p610210282165623"><a name="p610210282165623"></a><a name="p610210282165623"></a>Invalid connection</p>
<p id="p21681242202"><a name="p21681242202"></a><a name="p21681242202"></a></p>
</td>
</tr>
<tr id="row129309091165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1530501374165623p0"><a name="entry1530501374165623p0"></a><a name="entry1530501374165623p0"></a><strong id="ggab0845c0c8d309ee865c78b095b00e671a7a691a2430ec26878897b5fbc9c22a4c"><a name="ggab0845c0c8d309ee865c78b095b00e671a7a691a2430ec26878897b5fbc9c22a4c"></a><a name="ggab0845c0c8d309ee865c78b095b00e671a7a691a2430ec26878897b5fbc9c22a4c"></a></strong>CONNECTED</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p749903281165623"><a name="p749903281165623"></a><a name="p749903281165623"></a>Connected</p>
<p id="p816852416206"><a name="p816852416206"></a><a name="p816852416206"></a></p>
</td>
</tr>
<tr id="row885465371165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry203455783165623p0"><a name="entry203455783165623p0"></a><a name="entry203455783165623p0"></a><strong id="ggab0845c0c8d309ee865c78b095b00e671acdaad1112073e3e2ea032424c38c34e1"><a name="ggab0845c0c8d309ee865c78b095b00e671acdaad1112073e3e2ea032424c38c34e1"></a><a name="ggab0845c0c8d309ee865c78b095b00e671acdaad1112073e3e2ea032424c38c34e1"></a></strong>DISCONNECTED</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2096466128165623"><a name="p2096466128165623"></a><a name="p2096466128165623"></a>Disconnected</p>
<p id="p14168172472013"><a name="p14168172472013"></a><a name="p14168172472013"></a></p>
</td>
</tr>
</tbody>
</table>

## DispErrCode<a name="ga12a925dadef7573cd74d63d06824f9b0"></a>

```
enum [DispErrCode](Display.md#ga12a925dadef7573cd74d63d06824f9b0)
```

**Description:**

Enumerates return values of the functions.

<a name="table1439793958165623"></a>
<table><thead align="left"><tr id="row2057897549165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p656000551165623"><a name="p656000551165623"></a><a name="p656000551165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2038357681165623"><a name="p2038357681165623"></a><a name="p2038357681165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1829467389165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1653585083165623p0"><a name="entry1653585083165623p0"></a><a name="entry1653585083165623p0"></a><strong id="gga12a925dadef7573cd74d63d06824f9b0a188daac95e787159d50ff9546536035b"><a name="gga12a925dadef7573cd74d63d06824f9b0a188daac95e787159d50ff9546536035b"></a><a name="gga12a925dadef7573cd74d63d06824f9b0a188daac95e787159d50ff9546536035b"></a></strong>DISPLAY_SUCCESS</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1532323104165623"><a name="p1532323104165623"></a><a name="p1532323104165623"></a>Success</p>
<p id="p11173172410208"><a name="p11173172410208"></a><a name="p11173172410208"></a></p>
</td>
</tr>
<tr id="row649440100165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1455011575165623p0"><a name="entry1455011575165623p0"></a><a name="entry1455011575165623p0"></a><strong id="gga12a925dadef7573cd74d63d06824f9b0afdffc20c71fb142c3e7f01323a31d742"><a name="gga12a925dadef7573cd74d63d06824f9b0afdffc20c71fb142c3e7f01323a31d742"></a><a name="gga12a925dadef7573cd74d63d06824f9b0afdffc20c71fb142c3e7f01323a31d742"></a></strong>DISPLAY_FAILURE</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2007270003165623"><a name="p2007270003165623"></a><a name="p2007270003165623"></a>Failure</p>
<p id="p17173192414206"><a name="p17173192414206"></a><a name="p17173192414206"></a></p>
</td>
</tr>
<tr id="row1880647534165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry595379204165623p0"><a name="entry595379204165623p0"></a><a name="entry595379204165623p0"></a><strong id="gga12a925dadef7573cd74d63d06824f9b0a5bdb0a826a652f51e6c82685ae08ede8"><a name="gga12a925dadef7573cd74d63d06824f9b0a5bdb0a826a652f51e6c82685ae08ede8"></a><a name="gga12a925dadef7573cd74d63d06824f9b0a5bdb0a826a652f51e6c82685ae08ede8"></a></strong>DISPLAY_FD_ERR</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p926292012165623"><a name="p926292012165623"></a><a name="p926292012165623"></a>File handle (FD) error</p>
<p id="p19173132411208"><a name="p19173132411208"></a><a name="p19173132411208"></a></p>
</td>
</tr>
<tr id="row1060981059165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry944624112165623p0"><a name="entry944624112165623p0"></a><a name="entry944624112165623p0"></a><strong id="gga12a925dadef7573cd74d63d06824f9b0a330e09be303bc7056f6115830bbd2370"><a name="gga12a925dadef7573cd74d63d06824f9b0a330e09be303bc7056f6115830bbd2370"></a><a name="gga12a925dadef7573cd74d63d06824f9b0a330e09be303bc7056f6115830bbd2370"></a></strong>DISPLAY_PARAM_ERR</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p652538468165623"><a name="p652538468165623"></a><a name="p652538468165623"></a>Parameter error</p>
<p id="p1517302418200"><a name="p1517302418200"></a><a name="p1517302418200"></a></p>
</td>
</tr>
<tr id="row378606389165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry392672337165623p0"><a name="entry392672337165623p0"></a><a name="entry392672337165623p0"></a><strong id="gga12a925dadef7573cd74d63d06824f9b0a82fbcdba6c699059bc04b491c92424ac"><a name="gga12a925dadef7573cd74d63d06824f9b0a82fbcdba6c699059bc04b491c92424ac"></a><a name="gga12a925dadef7573cd74d63d06824f9b0a82fbcdba6c699059bc04b491c92424ac"></a></strong>DISPLAY_NULL_PTR</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1676110376165623"><a name="p1676110376165623"></a><a name="p1676110376165623"></a>Null pointer</p>
<p id="p17173182416204"><a name="p17173182416204"></a><a name="p17173182416204"></a></p>
</td>
</tr>
<tr id="row269243223165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1214434644165623p0"><a name="entry1214434644165623p0"></a><a name="entry1214434644165623p0"></a><strong id="gga12a925dadef7573cd74d63d06824f9b0a950a7bc41e893450315da9e73208f8c2"><a name="gga12a925dadef7573cd74d63d06824f9b0a950a7bc41e893450315da9e73208f8c2"></a><a name="gga12a925dadef7573cd74d63d06824f9b0a950a7bc41e893450315da9e73208f8c2"></a></strong>DISPLAY_NOT_SUPPORT</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1090592939165623"><a name="p1090592939165623"></a><a name="p1090592939165623"></a>Unsupported feature</p>
<p id="p717382413204"><a name="p717382413204"></a><a name="p717382413204"></a></p>
</td>
</tr>
<tr id="row1943870623165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry999386679165623p0"><a name="entry999386679165623p0"></a><a name="entry999386679165623p0"></a><strong id="gga12a925dadef7573cd74d63d06824f9b0af186ab511133fa3280c54d2c44358882"><a name="gga12a925dadef7573cd74d63d06824f9b0af186ab511133fa3280c54d2c44358882"></a><a name="gga12a925dadef7573cd74d63d06824f9b0af186ab511133fa3280c54d2c44358882"></a></strong>DISPLAY_NOMEM</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1163301037165623"><a name="p1163301037165623"></a><a name="p1163301037165623"></a>Insufficient memory</p>
<p id="p917302432014"><a name="p917302432014"></a><a name="p917302432014"></a></p>
</td>
</tr>
<tr id="row1925046255165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry52427501165623p0"><a name="entry52427501165623p0"></a><a name="entry52427501165623p0"></a><strong id="gga12a925dadef7573cd74d63d06824f9b0ac11b678fc04745ff4d91f4398b83c427"><a name="gga12a925dadef7573cd74d63d06824f9b0ac11b678fc04745ff4d91f4398b83c427"></a><a name="gga12a925dadef7573cd74d63d06824f9b0ac11b678fc04745ff4d91f4398b83c427"></a></strong>DISPLAY_SYS_BUSY</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1912715810165623"><a name="p1912715810165623"></a><a name="p1912715810165623"></a>System busy</p>
<p id="p191735248205"><a name="p191735248205"></a><a name="p191735248205"></a></p>
</td>
</tr>
<tr id="row1206302238165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry952751210165623p0"><a name="entry952751210165623p0"></a><a name="entry952751210165623p0"></a><strong id="gga12a925dadef7573cd74d63d06824f9b0ad133674b9f3b857a12791479aaf58cf8"><a name="gga12a925dadef7573cd74d63d06824f9b0ad133674b9f3b857a12791479aaf58cf8"></a><a name="gga12a925dadef7573cd74d63d06824f9b0ad133674b9f3b857a12791479aaf58cf8"></a></strong>DISPLAY_NOT_PERM</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1608800364165623"><a name="p1608800364165623"></a><a name="p1608800364165623"></a>Forbidden operation</p>
<p id="p1317362472014"><a name="p1317362472014"></a><a name="p1317362472014"></a></p>
</td>
</tr>
</tbody>
</table>

## LayerType<a name="ga56943a0946e5f15e5e58054b8e7a04a4"></a>

```
enum [LayerType](Display.md#ga56943a0946e5f15e5e58054b8e7a04a4)
```

**Description:**

Enumerates layer types.

<a name="table1827159045165623"></a>
<table><thead align="left"><tr id="row2119533487165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1741961487165623"><a name="p1741961487165623"></a><a name="p1741961487165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1914721681165623"><a name="p1914721681165623"></a><a name="p1914721681165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row857872702165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1130253846165623p0"><a name="entry1130253846165623p0"></a><a name="entry1130253846165623p0"></a><strong id="gga56943a0946e5f15e5e58054b8e7a04a4a6ef157ea82a5d4c1715b3cddcca38d6f"><a name="gga56943a0946e5f15e5e58054b8e7a04a4a6ef157ea82a5d4c1715b3cddcca38d6f"></a><a name="gga56943a0946e5f15e5e58054b8e7a04a4a6ef157ea82a5d4c1715b3cddcca38d6f"></a></strong>LAYER_TYPE_GRAPHIC</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1515247283165623"><a name="p1515247283165623"></a><a name="p1515247283165623"></a>Graphic layer</p>
<p id="p19182132414208"><a name="p19182132414208"></a><a name="p19182132414208"></a></p>
</td>
</tr>
<tr id="row945923501165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1683495260165623p0"><a name="entry1683495260165623p0"></a><a name="entry1683495260165623p0"></a><strong id="gga56943a0946e5f15e5e58054b8e7a04a4ac33e449941bc0e4d039b4b5bed853a78"><a name="gga56943a0946e5f15e5e58054b8e7a04a4ac33e449941bc0e4d039b4b5bed853a78"></a><a name="gga56943a0946e5f15e5e58054b8e7a04a4ac33e449941bc0e4d039b4b5bed853a78"></a></strong>LAYER_TYPE_OVERLAY</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p68143153165623"><a name="p68143153165623"></a><a name="p68143153165623"></a>Overlay layer</p>
<p id="p21821024122015"><a name="p21821024122015"></a><a name="p21821024122015"></a></p>
</td>
</tr>
<tr id="row1288233974165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry914158622165623p0"><a name="entry914158622165623p0"></a><a name="entry914158622165623p0"></a><strong id="gga56943a0946e5f15e5e58054b8e7a04a4a0aef2c460a206fa00c742219d65be477"><a name="gga56943a0946e5f15e5e58054b8e7a04a4a0aef2c460a206fa00c742219d65be477"></a><a name="gga56943a0946e5f15e5e58054b8e7a04a4a0aef2c460a206fa00c742219d65be477"></a></strong>LAYER_TYPE_SDIEBAND</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1211857880165623"><a name="p1211857880165623"></a><a name="p1211857880165623"></a>Sideband layer</p>
<p id="p1182824172017"><a name="p1182824172017"></a><a name="p1182824172017"></a></p>
</td>
</tr>
<tr id="row604850371165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry930812449165623p0"><a name="entry930812449165623p0"></a><a name="entry930812449165623p0"></a><strong id="gga56943a0946e5f15e5e58054b8e7a04a4acd813c5ad9a2be97c85a97d4bdf1cb57"><a name="gga56943a0946e5f15e5e58054b8e7a04a4acd813c5ad9a2be97c85a97d4bdf1cb57"></a><a name="gga56943a0946e5f15e5e58054b8e7a04a4acd813c5ad9a2be97c85a97d4bdf1cb57"></a></strong>LAYER_TYPE_BUTT</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p432283043165623"><a name="p432283043165623"></a><a name="p432283043165623"></a>Empty layer</p>
<p id="p16182182412013"><a name="p16182182412013"></a><a name="p16182182412013"></a></p>
</td>
</tr>
</tbody>
</table>

## MemType<a name="gabd31f838aefffa46191d0d7dc36a96b2"></a>

```
enum [MemType](Display.md#gabd31f838aefffa46191d0d7dc36a96b2)
```

**Description:**

Enumerates memory types.

Memory is allocated based on the type specified by the GUI.

<a name="table498373742165623"></a>
<table><thead align="left"><tr id="row292720480165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1705329691165623"><a name="p1705329691165623"></a><a name="p1705329691165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1263822413165623"><a name="p1263822413165623"></a><a name="p1263822413165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1708459212165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry224096309165623p0"><a name="entry224096309165623p0"></a><a name="entry224096309165623p0"></a><strong id="ggabd31f838aefffa46191d0d7dc36a96b2ad3379d0af95e2e9dcbcfdb016d1cf9b3"><a name="ggabd31f838aefffa46191d0d7dc36a96b2ad3379d0af95e2e9dcbcfdb016d1cf9b3"></a><a name="ggabd31f838aefffa46191d0d7dc36a96b2ad3379d0af95e2e9dcbcfdb016d1cf9b3"></a></strong>NORMAL_MEM</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1380216808165623"><a name="p1380216808165623"></a><a name="p1380216808165623"></a>Memory without cache</p>
<p id="p618682462020"><a name="p618682462020"></a><a name="p618682462020"></a></p>
</td>
</tr>
<tr id="row739575662165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1574901291165623p0"><a name="entry1574901291165623p0"></a><a name="entry1574901291165623p0"></a><strong id="ggabd31f838aefffa46191d0d7dc36a96b2a2ad949ccc994ad1718cb54929d762700"><a name="ggabd31f838aefffa46191d0d7dc36a96b2a2ad949ccc994ad1718cb54929d762700"></a><a name="ggabd31f838aefffa46191d0d7dc36a96b2a2ad949ccc994ad1718cb54929d762700"></a></strong>CACHE_MEM</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p3043556165623"><a name="p3043556165623"></a><a name="p3043556165623"></a>Memory with cache</p>
<p id="p20186112452010"><a name="p20186112452010"></a><a name="p20186112452010"></a></p>
</td>
</tr>
<tr id="row1467691880165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry614580275165623p0"><a name="entry614580275165623p0"></a><a name="entry614580275165623p0"></a><strong id="ggabd31f838aefffa46191d0d7dc36a96b2a79f98876507c94448fed5f6f33683fb7"><a name="ggabd31f838aefffa46191d0d7dc36a96b2a79f98876507c94448fed5f6f33683fb7"></a><a name="ggabd31f838aefffa46191d0d7dc36a96b2a79f98876507c94448fed5f6f33683fb7"></a></strong>SHM_MEM</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p713270948165623"><a name="p713270948165623"></a><a name="p713270948165623"></a>Shared memory</p>
<p id="p1218632413204"><a name="p1218632413204"></a><a name="p1218632413204"></a></p>
</td>
</tr>
</tbody>
</table>

## MirrorType<a name="ga08d32376574b541d162d8534adb78fd0"></a>

```
enum [MirrorType](Display.md#ga08d32376574b541d162d8534adb78fd0)
```

**Description:**

Enumerates mirror types supported by hardware acceleration.

<a name="table1058816805165623"></a>
<table><thead align="left"><tr id="row2050890372165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p220275056165623"><a name="p220275056165623"></a><a name="p220275056165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p702574693165623"><a name="p702574693165623"></a><a name="p702574693165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row554197721165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry197217733165623p0"><a name="entry197217733165623p0"></a><a name="entry197217733165623p0"></a><strong id="gga08d32376574b541d162d8534adb78fd0a5ad82fcc8af04f92571e185b61eeb309"><a name="gga08d32376574b541d162d8534adb78fd0a5ad82fcc8af04f92571e185b61eeb309"></a><a name="gga08d32376574b541d162d8534adb78fd0a5ad82fcc8af04f92571e185b61eeb309"></a></strong>MIRROR_NONE</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1124144491165623"><a name="p1124144491165623"></a><a name="p1124144491165623"></a>No mirror</p>
<p id="p51897241205"><a name="p51897241205"></a><a name="p51897241205"></a></p>
</td>
</tr>
<tr id="row533198971165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1420172453165623p0"><a name="entry1420172453165623p0"></a><a name="entry1420172453165623p0"></a><strong id="gga08d32376574b541d162d8534adb78fd0ae35099d9fd28c2974661bcce36a9ea5c"><a name="gga08d32376574b541d162d8534adb78fd0ae35099d9fd28c2974661bcce36a9ea5c"></a><a name="gga08d32376574b541d162d8534adb78fd0ae35099d9fd28c2974661bcce36a9ea5c"></a></strong>MIRROR_LR</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p376528239165623"><a name="p376528239165623"></a><a name="p376528239165623"></a>Left and right mirrors</p>
<p id="p91901324112010"><a name="p91901324112010"></a><a name="p91901324112010"></a></p>
</td>
</tr>
<tr id="row1347909758165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1280433470165623p0"><a name="entry1280433470165623p0"></a><a name="entry1280433470165623p0"></a><strong id="gga08d32376574b541d162d8534adb78fd0afd82e59546a645fd29bc779c50bfa733"><a name="gga08d32376574b541d162d8534adb78fd0afd82e59546a645fd29bc779c50bfa733"></a><a name="gga08d32376574b541d162d8534adb78fd0afd82e59546a645fd29bc779c50bfa733"></a></strong>MIRROR_TB</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p178421642165623"><a name="p178421642165623"></a><a name="p178421642165623"></a>Top and bottom mirrors</p>
<p id="p16190152410200"><a name="p16190152410200"></a><a name="p16190152410200"></a></p>
</td>
</tr>
<tr id="row652128482165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1058657692165623p0"><a name="entry1058657692165623p0"></a><a name="entry1058657692165623p0"></a><strong id="gga08d32376574b541d162d8534adb78fd0ad9e357a2c2f7dc0e3ca5a351ec457410"><a name="gga08d32376574b541d162d8534adb78fd0ad9e357a2c2f7dc0e3ca5a351ec457410"></a><a name="gga08d32376574b541d162d8534adb78fd0ad9e357a2c2f7dc0e3ca5a351ec457410"></a></strong>MIRROR_BUTT</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p497215943165623"><a name="p497215943165623"></a><a name="p497215943165623"></a>Null operation</p>
<p id="p5190122411202"><a name="p5190122411202"></a><a name="p5190122411202"></a></p>
</td>
</tr>
</tbody>
</table>

## PixelFormat<a name="ga60883d4958a60b91661e97027a85072a"></a>

```
enum [PixelFormat](Codec.md#ga60883d4958a60b91661e97027a85072a)
```

**Description:**

Enumerates pixel formats.

<a name="table60411932165623"></a>
<table><thead align="left"><tr id="row1447181446165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1105817930165623"><a name="p1105817930165623"></a><a name="p1105817930165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1158560114165623"><a name="p1158560114165623"></a><a name="p1158560114165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row103257974165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2120528234165623p0"><a name="entry2120528234165623p0"></a><a name="entry2120528234165623p0"></a><strong id="gga60883d4958a60b91661e97027a85072aabdea255b6e5f2920977f11d21445b34a"><a name="gga60883d4958a60b91661e97027a85072aabdea255b6e5f2920977f11d21445b34a"></a><a name="gga60883d4958a60b91661e97027a85072aabdea255b6e5f2920977f11d21445b34a"></a></strong>PIXEL_FMT_CLUT8</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p829753599165623"><a name="p829753599165623"></a><a name="p829753599165623"></a>CLUT8 format</p>
<p id="p1419482492012"><a name="p1419482492012"></a><a name="p1419482492012"></a></p>
</td>
</tr>
<tr id="row393298842165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry240812923165623p0"><a name="entry240812923165623p0"></a><a name="entry240812923165623p0"></a><strong id="gga60883d4958a60b91661e97027a85072aa5740c66a546552c0c5a4bc06850af584"><a name="gga60883d4958a60b91661e97027a85072aa5740c66a546552c0c5a4bc06850af584"></a><a name="gga60883d4958a60b91661e97027a85072aa5740c66a546552c0c5a4bc06850af584"></a></strong>PIXEL_FMT_CLUT1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1751341896165623"><a name="p1751341896165623"></a><a name="p1751341896165623"></a>CLUT1 format</p>
<p id="p151941124192013"><a name="p151941124192013"></a><a name="p151941124192013"></a></p>
</td>
</tr>
<tr id="row289007995165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1676822799165623p0"><a name="entry1676822799165623p0"></a><a name="entry1676822799165623p0"></a><strong id="gga60883d4958a60b91661e97027a85072aabde13e8f357e39981973929309bb0e0e"><a name="gga60883d4958a60b91661e97027a85072aabde13e8f357e39981973929309bb0e0e"></a><a name="gga60883d4958a60b91661e97027a85072aabde13e8f357e39981973929309bb0e0e"></a></strong>PIXEL_FMT_CLUT4</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p126166835165623"><a name="p126166835165623"></a><a name="p126166835165623"></a>CLUT4 format</p>
<p id="p319432432014"><a name="p319432432014"></a><a name="p319432432014"></a></p>
</td>
</tr>
<tr id="row533184151165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry827703011165623p0"><a name="entry827703011165623p0"></a><a name="entry827703011165623p0"></a><strong id="gga60883d4958a60b91661e97027a85072aa5fae320872be3ffdda0d371cec048ec6"><a name="gga60883d4958a60b91661e97027a85072aa5fae320872be3ffdda0d371cec048ec6"></a><a name="gga60883d4958a60b91661e97027a85072aa5fae320872be3ffdda0d371cec048ec6"></a></strong>PIXEL_FMT_RGB_565</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2110075173165623"><a name="p2110075173165623"></a><a name="p2110075173165623"></a>RGB565 format</p>
<p id="p1819410245204"><a name="p1819410245204"></a><a name="p1819410245204"></a></p>
</td>
</tr>
<tr id="row1957812753165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry547983803165623p0"><a name="entry547983803165623p0"></a><a name="entry547983803165623p0"></a><strong id="gga60883d4958a60b91661e97027a85072aa4c16147153b63d7ba71b257111afdd62"><a name="gga60883d4958a60b91661e97027a85072aa4c16147153b63d7ba71b257111afdd62"></a><a name="gga60883d4958a60b91661e97027a85072aa4c16147153b63d7ba71b257111afdd62"></a></strong>PIXEL_FMT_RGBA_5658</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1200690642165623"><a name="p1200690642165623"></a><a name="p1200690642165623"></a>RGBA5658 format</p>
<p id="p9194724112014"><a name="p9194724112014"></a><a name="p9194724112014"></a></p>
</td>
</tr>
<tr id="row1684734388165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry731625326165623p0"><a name="entry731625326165623p0"></a><a name="entry731625326165623p0"></a><strong id="gga60883d4958a60b91661e97027a85072aaa479ac0d983fde9b4f7f0e1a3b3e230f"><a name="gga60883d4958a60b91661e97027a85072aaa479ac0d983fde9b4f7f0e1a3b3e230f"></a><a name="gga60883d4958a60b91661e97027a85072aaa479ac0d983fde9b4f7f0e1a3b3e230f"></a></strong>PIXEL_FMT_RGBX_4444</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p587811714165623"><a name="p587811714165623"></a><a name="p587811714165623"></a>RGBX4444 format</p>
<p id="p91941924202011"><a name="p91941924202011"></a><a name="p91941924202011"></a></p>
</td>
</tr>
<tr id="row2084511923165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry352526829165623p0"><a name="entry352526829165623p0"></a><a name="entry352526829165623p0"></a><strong id="gga60883d4958a60b91661e97027a85072aacbb91256e8c45a51410a9f6caae2d04c"><a name="gga60883d4958a60b91661e97027a85072aacbb91256e8c45a51410a9f6caae2d04c"></a><a name="gga60883d4958a60b91661e97027a85072aacbb91256e8c45a51410a9f6caae2d04c"></a></strong>PIXEL_FMT_RGBA_4444</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1266453295165623"><a name="p1266453295165623"></a><a name="p1266453295165623"></a>RGBA4444 format</p>
<p id="p11194122422018"><a name="p11194122422018"></a><a name="p11194122422018"></a></p>
</td>
</tr>
<tr id="row1711640179165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1225741423165623p0"><a name="entry1225741423165623p0"></a><a name="entry1225741423165623p0"></a><strong id="gga60883d4958a60b91661e97027a85072aa7d18a83da06902c104208031ed487942"><a name="gga60883d4958a60b91661e97027a85072aa7d18a83da06902c104208031ed487942"></a><a name="gga60883d4958a60b91661e97027a85072aa7d18a83da06902c104208031ed487942"></a></strong>PIXEL_FMT_RGB_444</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1047605624165623"><a name="p1047605624165623"></a><a name="p1047605624165623"></a>RGB444 format</p>
<p id="p51945244207"><a name="p51945244207"></a><a name="p51945244207"></a></p>
</td>
</tr>
<tr id="row377845735165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry558399166165623p0"><a name="entry558399166165623p0"></a><a name="entry558399166165623p0"></a><strong id="gga60883d4958a60b91661e97027a85072aa85e5dd1a0e547c0031baffd02abb31a0"><a name="gga60883d4958a60b91661e97027a85072aa85e5dd1a0e547c0031baffd02abb31a0"></a><a name="gga60883d4958a60b91661e97027a85072aa85e5dd1a0e547c0031baffd02abb31a0"></a></strong>PIXEL_FMT_RGBX_5551</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p926244100165623"><a name="p926244100165623"></a><a name="p926244100165623"></a>RGBX5551 format</p>
<p id="p191942024132014"><a name="p191942024132014"></a><a name="p191942024132014"></a></p>
</td>
</tr>
<tr id="row1730469713165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2053403596165623p0"><a name="entry2053403596165623p0"></a><a name="entry2053403596165623p0"></a><strong id="gga60883d4958a60b91661e97027a85072aadc1387526a271d8c6db7729de06474b1"><a name="gga60883d4958a60b91661e97027a85072aadc1387526a271d8c6db7729de06474b1"></a><a name="gga60883d4958a60b91661e97027a85072aadc1387526a271d8c6db7729de06474b1"></a></strong>PIXEL_FMT_RGBA_5551</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p89448507165623"><a name="p89448507165623"></a><a name="p89448507165623"></a>RGBA5551 format</p>
<p id="p119452412205"><a name="p119452412205"></a><a name="p119452412205"></a></p>
</td>
</tr>
<tr id="row1910931350165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1393630377165623p0"><a name="entry1393630377165623p0"></a><a name="entry1393630377165623p0"></a><strong id="gga60883d4958a60b91661e97027a85072aa720a429fa57133f6e27ef8c8fa1c404a"><a name="gga60883d4958a60b91661e97027a85072aa720a429fa57133f6e27ef8c8fa1c404a"></a><a name="gga60883d4958a60b91661e97027a85072aa720a429fa57133f6e27ef8c8fa1c404a"></a></strong>PIXEL_FMT_RGB_555</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p776965084165623"><a name="p776965084165623"></a><a name="p776965084165623"></a>RGB555 format</p>
<p id="p1194132422017"><a name="p1194132422017"></a><a name="p1194132422017"></a></p>
</td>
</tr>
<tr id="row379104648165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1146865132165623p0"><a name="entry1146865132165623p0"></a><a name="entry1146865132165623p0"></a><strong id="gga60883d4958a60b91661e97027a85072aa24a7181b7fb4019e7c19739bd9b65ff0"><a name="gga60883d4958a60b91661e97027a85072aa24a7181b7fb4019e7c19739bd9b65ff0"></a><a name="gga60883d4958a60b91661e97027a85072aa24a7181b7fb4019e7c19739bd9b65ff0"></a></strong>PIXEL_FMT_RGBX_8888</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p922261618165623"><a name="p922261618165623"></a><a name="p922261618165623"></a>RGBX8888 format</p>
<p id="p111941324142017"><a name="p111941324142017"></a><a name="p111941324142017"></a></p>
</td>
</tr>
<tr id="row1957985543165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry108871915165623p0"><a name="entry108871915165623p0"></a><a name="entry108871915165623p0"></a><strong id="gga60883d4958a60b91661e97027a85072aa90b462672221691ed66cacb07dd2e05f"><a name="gga60883d4958a60b91661e97027a85072aa90b462672221691ed66cacb07dd2e05f"></a><a name="gga60883d4958a60b91661e97027a85072aa90b462672221691ed66cacb07dd2e05f"></a></strong>PIXEL_FMT_RGBA_8888</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1667585243165623"><a name="p1667585243165623"></a><a name="p1667585243165623"></a>RGBA8888 format</p>
<p id="p19194224192014"><a name="p19194224192014"></a><a name="p19194224192014"></a></p>
</td>
</tr>
<tr id="row1355479772165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry432062354165623p0"><a name="entry432062354165623p0"></a><a name="entry432062354165623p0"></a><strong id="gga60883d4958a60b91661e97027a85072aa7ff77397bf2cf52b4614a46264f8ce01"><a name="gga60883d4958a60b91661e97027a85072aa7ff77397bf2cf52b4614a46264f8ce01"></a><a name="gga60883d4958a60b91661e97027a85072aa7ff77397bf2cf52b4614a46264f8ce01"></a></strong>PIXEL_FMT_RGB_888</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1985363515165623"><a name="p1985363515165623"></a><a name="p1985363515165623"></a>RGB888 format</p>
<p id="p1619410248205"><a name="p1619410248205"></a><a name="p1619410248205"></a></p>
</td>
</tr>
<tr id="row47492373165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1161096338165623p0"><a name="entry1161096338165623p0"></a><a name="entry1161096338165623p0"></a><strong id="gga60883d4958a60b91661e97027a85072aaec581b908c291e2bd0155e25169f9629"><a name="gga60883d4958a60b91661e97027a85072aaec581b908c291e2bd0155e25169f9629"></a><a name="gga60883d4958a60b91661e97027a85072aaec581b908c291e2bd0155e25169f9629"></a></strong>PIXEL_FMT_BGR_565</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p541612129165623"><a name="p541612129165623"></a><a name="p541612129165623"></a>BGR565 format</p>
<p id="p19194202472010"><a name="p19194202472010"></a><a name="p19194202472010"></a></p>
</td>
</tr>
<tr id="row1247648752165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry674515338165623p0"><a name="entry674515338165623p0"></a><a name="entry674515338165623p0"></a><strong id="gga60883d4958a60b91661e97027a85072aa6b5a7b35e00fc25146de0c9bf88b0230"><a name="gga60883d4958a60b91661e97027a85072aa6b5a7b35e00fc25146de0c9bf88b0230"></a><a name="gga60883d4958a60b91661e97027a85072aa6b5a7b35e00fc25146de0c9bf88b0230"></a></strong>PIXEL_FMT_BGRX_4444</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1743451196165623"><a name="p1743451196165623"></a><a name="p1743451196165623"></a>BGRX4444 format</p>
<p id="p13194152472015"><a name="p13194152472015"></a><a name="p13194152472015"></a></p>
</td>
</tr>
<tr id="row2057239384165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1248181027165623p0"><a name="entry1248181027165623p0"></a><a name="entry1248181027165623p0"></a><strong id="gga60883d4958a60b91661e97027a85072aa2f3d4ada099b2e8d84ec4501fbc8bed9"><a name="gga60883d4958a60b91661e97027a85072aa2f3d4ada099b2e8d84ec4501fbc8bed9"></a><a name="gga60883d4958a60b91661e97027a85072aa2f3d4ada099b2e8d84ec4501fbc8bed9"></a></strong>PIXEL_FMT_BGRA_4444</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p275280331165623"><a name="p275280331165623"></a><a name="p275280331165623"></a>BGRA4444 format</p>
<p id="p61941124182020"><a name="p61941124182020"></a><a name="p61941124182020"></a></p>
</td>
</tr>
<tr id="row813822225165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1664366819165623p0"><a name="entry1664366819165623p0"></a><a name="entry1664366819165623p0"></a><strong id="gga60883d4958a60b91661e97027a85072aaaf1a20dc0a597258cfe6aca806a8e0de"><a name="gga60883d4958a60b91661e97027a85072aaaf1a20dc0a597258cfe6aca806a8e0de"></a><a name="gga60883d4958a60b91661e97027a85072aaaf1a20dc0a597258cfe6aca806a8e0de"></a></strong>PIXEL_FMT_BGRX_5551</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p397189922165623"><a name="p397189922165623"></a><a name="p397189922165623"></a>BGRX5551 format</p>
<p id="p819417246205"><a name="p819417246205"></a><a name="p819417246205"></a></p>
</td>
</tr>
<tr id="row1228768677165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry997890579165623p0"><a name="entry997890579165623p0"></a><a name="entry997890579165623p0"></a><strong id="gga60883d4958a60b91661e97027a85072aa2319d4a75dae0b56776fa63d525e308b"><a name="gga60883d4958a60b91661e97027a85072aa2319d4a75dae0b56776fa63d525e308b"></a><a name="gga60883d4958a60b91661e97027a85072aa2319d4a75dae0b56776fa63d525e308b"></a></strong>PIXEL_FMT_BGRA_5551</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1420828028165623"><a name="p1420828028165623"></a><a name="p1420828028165623"></a>BGRA5551 format</p>
<p id="p19194122415208"><a name="p19194122415208"></a><a name="p19194122415208"></a></p>
</td>
</tr>
<tr id="row959630703165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1832742088165623p0"><a name="entry1832742088165623p0"></a><a name="entry1832742088165623p0"></a><strong id="gga60883d4958a60b91661e97027a85072aa1b19279f89c8cfb60e7d77ce23cd5f43"><a name="gga60883d4958a60b91661e97027a85072aa1b19279f89c8cfb60e7d77ce23cd5f43"></a><a name="gga60883d4958a60b91661e97027a85072aa1b19279f89c8cfb60e7d77ce23cd5f43"></a></strong>PIXEL_FMT_BGRX_8888</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p525473415165623"><a name="p525473415165623"></a><a name="p525473415165623"></a>BGRX8888 format</p>
<p id="p1519419245209"><a name="p1519419245209"></a><a name="p1519419245209"></a></p>
</td>
</tr>
<tr id="row585237529165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry755751148165623p0"><a name="entry755751148165623p0"></a><a name="entry755751148165623p0"></a><strong id="gga60883d4958a60b91661e97027a85072aaeb31c670120a1fbc96a0e0887997fe16"><a name="gga60883d4958a60b91661e97027a85072aaeb31c670120a1fbc96a0e0887997fe16"></a><a name="gga60883d4958a60b91661e97027a85072aaeb31c670120a1fbc96a0e0887997fe16"></a></strong>PIXEL_FMT_BGRA_8888</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p512948060165623"><a name="p512948060165623"></a><a name="p512948060165623"></a>BGRA8888 format</p>
<p id="p3194152412014"><a name="p3194152412014"></a><a name="p3194152412014"></a></p>
</td>
</tr>
<tr id="row1837014561165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1683995845165623p0"><a name="entry1683995845165623p0"></a><a name="entry1683995845165623p0"></a><strong id="gga60883d4958a60b91661e97027a85072aac73c2a84907a53ed95a329007b5c8992"><a name="gga60883d4958a60b91661e97027a85072aac73c2a84907a53ed95a329007b5c8992"></a><a name="gga60883d4958a60b91661e97027a85072aac73c2a84907a53ed95a329007b5c8992"></a></strong>PIXEL_FMT_YUV_422_I</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1194554786165623"><a name="p1194554786165623"></a><a name="p1194554786165623"></a>YUV422 interleaved format</p>
<p id="p7194224182018"><a name="p7194224182018"></a><a name="p7194224182018"></a></p>
</td>
</tr>
<tr id="row518172786165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1117804649165623p0"><a name="entry1117804649165623p0"></a><a name="entry1117804649165623p0"></a><strong id="gga60883d4958a60b91661e97027a85072aabdf1224848278508479ce97f637dd711"><a name="gga60883d4958a60b91661e97027a85072aabdf1224848278508479ce97f637dd711"></a><a name="gga60883d4958a60b91661e97027a85072aabdf1224848278508479ce97f637dd711"></a></strong>PIXEL_FMT_YCBCR_422_SP</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1001623600165623"><a name="p1001623600165623"></a><a name="p1001623600165623"></a>YCBCR422 semi-planar format</p>
<p id="p121942243209"><a name="p121942243209"></a><a name="p121942243209"></a></p>
</td>
</tr>
<tr id="row1710529340165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1113695650165623p0"><a name="entry1113695650165623p0"></a><a name="entry1113695650165623p0"></a><strong id="gga60883d4958a60b91661e97027a85072aa8bf97d66e26b3aad7c83dfa70e2bc451"><a name="gga60883d4958a60b91661e97027a85072aa8bf97d66e26b3aad7c83dfa70e2bc451"></a><a name="gga60883d4958a60b91661e97027a85072aa8bf97d66e26b3aad7c83dfa70e2bc451"></a></strong>PIXEL_FMT_YCRCB_422_SP</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1256686189165623"><a name="p1256686189165623"></a><a name="p1256686189165623"></a>YCRCB422 semi-planar format</p>
<p id="p1219419244203"><a name="p1219419244203"></a><a name="p1219419244203"></a></p>
</td>
</tr>
<tr id="row772616238165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1485781864165623p0"><a name="entry1485781864165623p0"></a><a name="entry1485781864165623p0"></a><strong id="gga60883d4958a60b91661e97027a85072aa0d1db50eb492f9073abdd2d662c56396"><a name="gga60883d4958a60b91661e97027a85072aa0d1db50eb492f9073abdd2d662c56396"></a><a name="gga60883d4958a60b91661e97027a85072aa0d1db50eb492f9073abdd2d662c56396"></a></strong>PIXEL_FMT_YCBCR_420_SP</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p320457732165623"><a name="p320457732165623"></a><a name="p320457732165623"></a>YCBCR420 semi-planar format</p>
<p id="p81952243207"><a name="p81952243207"></a><a name="p81952243207"></a></p>
</td>
</tr>
<tr id="row1916311607165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry790365080165623p0"><a name="entry790365080165623p0"></a><a name="entry790365080165623p0"></a><strong id="gga60883d4958a60b91661e97027a85072aa1fa43c8a197d5c974a35b8bf02ab386e"><a name="gga60883d4958a60b91661e97027a85072aa1fa43c8a197d5c974a35b8bf02ab386e"></a><a name="gga60883d4958a60b91661e97027a85072aa1fa43c8a197d5c974a35b8bf02ab386e"></a></strong>PIXEL_FMT_YCRCB_420_SP</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p665887380165623"><a name="p665887380165623"></a><a name="p665887380165623"></a>YCRCB420 semi-planar format</p>
<p id="p181951724102013"><a name="p181951724102013"></a><a name="p181951724102013"></a></p>
</td>
</tr>
<tr id="row439477469165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry943145229165623p0"><a name="entry943145229165623p0"></a><a name="entry943145229165623p0"></a><strong id="gga60883d4958a60b91661e97027a85072aaa2fe085e63428ea76e1d975175001dc6"><a name="gga60883d4958a60b91661e97027a85072aaa2fe085e63428ea76e1d975175001dc6"></a><a name="gga60883d4958a60b91661e97027a85072aaa2fe085e63428ea76e1d975175001dc6"></a></strong>PIXEL_FMT_YCBCR_422_P</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p804313341165623"><a name="p804313341165623"></a><a name="p804313341165623"></a>YCBCR422 planar format</p>
<p id="p19195142417206"><a name="p19195142417206"></a><a name="p19195142417206"></a></p>
</td>
</tr>
<tr id="row2113585832165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1415895770165623p0"><a name="entry1415895770165623p0"></a><a name="entry1415895770165623p0"></a><strong id="gga60883d4958a60b91661e97027a85072aab04eb6e1d940e42f3b4cc20c0a44c4ee"><a name="gga60883d4958a60b91661e97027a85072aab04eb6e1d940e42f3b4cc20c0a44c4ee"></a><a name="gga60883d4958a60b91661e97027a85072aab04eb6e1d940e42f3b4cc20c0a44c4ee"></a></strong>PIXEL_FMT_YCRCB_422_P</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1751409947165623"><a name="p1751409947165623"></a><a name="p1751409947165623"></a>YCRCB422 planar format</p>
<p id="p2195112412016"><a name="p2195112412016"></a><a name="p2195112412016"></a></p>
</td>
</tr>
<tr id="row1212628161165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry54580335165623p0"><a name="entry54580335165623p0"></a><a name="entry54580335165623p0"></a><strong id="gga60883d4958a60b91661e97027a85072aa3d80e785bed28e2b3f5c7df563500962"><a name="gga60883d4958a60b91661e97027a85072aa3d80e785bed28e2b3f5c7df563500962"></a><a name="gga60883d4958a60b91661e97027a85072aa3d80e785bed28e2b3f5c7df563500962"></a></strong>PIXEL_FMT_YCBCR_420_P</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p103871800165623"><a name="p103871800165623"></a><a name="p103871800165623"></a>YCBCR420 planar format</p>
<p id="p4195202452013"><a name="p4195202452013"></a><a name="p4195202452013"></a></p>
</td>
</tr>
<tr id="row264741618165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry249503495165623p0"><a name="entry249503495165623p0"></a><a name="entry249503495165623p0"></a><strong id="gga60883d4958a60b91661e97027a85072aa3dc5a0a5ad2f21218b446c477277210a"><a name="gga60883d4958a60b91661e97027a85072aa3dc5a0a5ad2f21218b446c477277210a"></a><a name="gga60883d4958a60b91661e97027a85072aa3dc5a0a5ad2f21218b446c477277210a"></a></strong>PIXEL_FMT_YCRCB_420_P</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1837907355165623"><a name="p1837907355165623"></a><a name="p1837907355165623"></a>YCRCB420 planar format</p>
<p id="p19195724122014"><a name="p19195724122014"></a><a name="p19195724122014"></a></p>
</td>
</tr>
<tr id="row1405129438165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1605111256165623p0"><a name="entry1605111256165623p0"></a><a name="entry1605111256165623p0"></a><strong id="gga60883d4958a60b91661e97027a85072aa3980def5b133584bdb2982a71f07798e"><a name="gga60883d4958a60b91661e97027a85072aa3980def5b133584bdb2982a71f07798e"></a><a name="gga60883d4958a60b91661e97027a85072aa3980def5b133584bdb2982a71f07798e"></a></strong>PIXEL_FMT_YUYV_422_PKG</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1751307994165623"><a name="p1751307994165623"></a><a name="p1751307994165623"></a>YUYV422 packed format</p>
<p id="p519515242207"><a name="p519515242207"></a><a name="p519515242207"></a></p>
</td>
</tr>
<tr id="row1211184806165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry916188540165623p0"><a name="entry916188540165623p0"></a><a name="entry916188540165623p0"></a><strong id="gga60883d4958a60b91661e97027a85072aadfd69bd5b421aad5bdd39d5f33317197"><a name="gga60883d4958a60b91661e97027a85072aadfd69bd5b421aad5bdd39d5f33317197"></a><a name="gga60883d4958a60b91661e97027a85072aadfd69bd5b421aad5bdd39d5f33317197"></a></strong>PIXEL_FMT_UYVY_422_PKG</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1203162311165623"><a name="p1203162311165623"></a><a name="p1203162311165623"></a>UYVY422 packed format</p>
<p id="p111951524152018"><a name="p111951524152018"></a><a name="p111951524152018"></a></p>
</td>
</tr>
<tr id="row472265263165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1829176728165623p0"><a name="entry1829176728165623p0"></a><a name="entry1829176728165623p0"></a><strong id="gga60883d4958a60b91661e97027a85072aaf851031c336e8d9f57c940c5f52381f4"><a name="gga60883d4958a60b91661e97027a85072aaf851031c336e8d9f57c940c5f52381f4"></a><a name="gga60883d4958a60b91661e97027a85072aaf851031c336e8d9f57c940c5f52381f4"></a></strong>PIXEL_FMT_YVYU_422_PKG</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1621990447165623"><a name="p1621990447165623"></a><a name="p1621990447165623"></a>YVYU422 packed format</p>
<p id="p10195102410200"><a name="p10195102410200"></a><a name="p10195102410200"></a></p>
</td>
</tr>
<tr id="row2068692147165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2005736209165623p0"><a name="entry2005736209165623p0"></a><a name="entry2005736209165623p0"></a><strong id="gga60883d4958a60b91661e97027a85072aa317a761939335025379d382074a1541c"><a name="gga60883d4958a60b91661e97027a85072aa317a761939335025379d382074a1541c"></a><a name="gga60883d4958a60b91661e97027a85072aa317a761939335025379d382074a1541c"></a></strong>PIXEL_FMT_VYUY_422_PKG</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1804713612165623"><a name="p1804713612165623"></a><a name="p1804713612165623"></a>VYUY422 packed format</p>
<p id="p1019562402011"><a name="p1019562402011"></a><a name="p1019562402011"></a></p>
</td>
</tr>
<tr id="row1597434351165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry968182107165623p0"><a name="entry968182107165623p0"></a><a name="entry968182107165623p0"></a><strong id="gga60883d4958a60b91661e97027a85072aa07086bb3356c9c88959eee00c0982684"><a name="gga60883d4958a60b91661e97027a85072aa07086bb3356c9c88959eee00c0982684"></a><a name="gga60883d4958a60b91661e97027a85072aa07086bb3356c9c88959eee00c0982684"></a></strong>PIXEL_FMT_BUTT</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1509596752165623"><a name="p1509596752165623"></a><a name="p1509596752165623"></a>Invalid pixel format</p>
<p id="p13195024172012"><a name="p13195024172012"></a><a name="p13195024172012"></a></p>
</td>
</tr>
</tbody>
</table>

## RopType<a name="ga24265f7618fbdba53d3da4806d3097c4"></a>

```
enum [RopType](Display.md#ga24265f7618fbdba53d3da4806d3097c4)
```

**Description:**

Enumerates ROP types supported by hardware acceleration.

ROP performs bitwise Boolean operations \(including bitwise AND and bitwise OR\) on the RGB color and alpha values of the foreground bitmap with those of the background bitmap, and then outputs the result.

<a name="table812484978165623"></a>
<table><thead align="left"><tr id="row409958552165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1037614215165623"><a name="p1037614215165623"></a><a name="p1037614215165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1510859407165623"><a name="p1510859407165623"></a><a name="p1510859407165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row27177802165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry884088940165623p0"><a name="entry884088940165623p0"></a><a name="entry884088940165623p0"></a><strong id="gga24265f7618fbdba53d3da4806d3097c4a6358a786ec3b81000a07b343424cee0d"><a name="gga24265f7618fbdba53d3da4806d3097c4a6358a786ec3b81000a07b343424cee0d"></a><a name="gga24265f7618fbdba53d3da4806d3097c4a6358a786ec3b81000a07b343424cee0d"></a></strong>ROP_BLACK</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1741228109165623"><a name="p1741228109165623"></a><a name="p1741228109165623"></a>Blackness</p>
<p id="p20221524192018"><a name="p20221524192018"></a><a name="p20221524192018"></a></p>
</td>
</tr>
<tr id="row573178033165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry219086809165623p0"><a name="entry219086809165623p0"></a><a name="entry219086809165623p0"></a><strong id="gga24265f7618fbdba53d3da4806d3097c4a96c89f7b89a9048d355b4dc467224f4c"><a name="gga24265f7618fbdba53d3da4806d3097c4a96c89f7b89a9048d355b4dc467224f4c"></a><a name="gga24265f7618fbdba53d3da4806d3097c4a96c89f7b89a9048d355b4dc467224f4c"></a></strong>ROP_NOTMERGEPEN</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1464879071165623"><a name="p1464879071165623"></a><a name="p1464879071165623"></a>~(S2+S1)</p>
<p id="p192211524152019"><a name="p192211524152019"></a><a name="p192211524152019"></a></p>
</td>
</tr>
<tr id="row381946159165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1140837015165623p0"><a name="entry1140837015165623p0"></a><a name="entry1140837015165623p0"></a><strong id="gga24265f7618fbdba53d3da4806d3097c4a54d054ea6920cb88f374f70e8d41f934"><a name="gga24265f7618fbdba53d3da4806d3097c4a54d054ea6920cb88f374f70e8d41f934"></a><a name="gga24265f7618fbdba53d3da4806d3097c4a54d054ea6920cb88f374f70e8d41f934"></a></strong>ROP_MASKNOTPEN</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1965695071165623"><a name="p1965695071165623"></a><a name="p1965695071165623"></a>~S2&amp;S1</p>
<p id="p162217245203"><a name="p162217245203"></a><a name="p162217245203"></a></p>
</td>
</tr>
<tr id="row1574809660165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1723525962165623p0"><a name="entry1723525962165623p0"></a><a name="entry1723525962165623p0"></a><strong id="gga24265f7618fbdba53d3da4806d3097c4af4a5d5dc0f15249001cff7ef32fadef1"><a name="gga24265f7618fbdba53d3da4806d3097c4af4a5d5dc0f15249001cff7ef32fadef1"></a><a name="gga24265f7618fbdba53d3da4806d3097c4af4a5d5dc0f15249001cff7ef32fadef1"></a></strong>ROP_NOTCOPYPEN</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p612911833165623"><a name="p612911833165623"></a><a name="p612911833165623"></a>~S2</p>
<p id="p82211224172013"><a name="p82211224172013"></a><a name="p82211224172013"></a></p>
</td>
</tr>
<tr id="row786496159165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1213768472165623p0"><a name="entry1213768472165623p0"></a><a name="entry1213768472165623p0"></a><strong id="gga24265f7618fbdba53d3da4806d3097c4ad777eea18ba9f4e071b00aa060db00e3"><a name="gga24265f7618fbdba53d3da4806d3097c4ad777eea18ba9f4e071b00aa060db00e3"></a><a name="gga24265f7618fbdba53d3da4806d3097c4ad777eea18ba9f4e071b00aa060db00e3"></a></strong>ROP_MASKPENNOT</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1952986528165623"><a name="p1952986528165623"></a><a name="p1952986528165623"></a>S2&amp;~S1</p>
<p id="p15221122472011"><a name="p15221122472011"></a><a name="p15221122472011"></a></p>
</td>
</tr>
<tr id="row1493408562165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1768001786165623p0"><a name="entry1768001786165623p0"></a><a name="entry1768001786165623p0"></a><strong id="gga24265f7618fbdba53d3da4806d3097c4afa63c8e2a6a39d50954cb6316576b4e9"><a name="gga24265f7618fbdba53d3da4806d3097c4afa63c8e2a6a39d50954cb6316576b4e9"></a><a name="gga24265f7618fbdba53d3da4806d3097c4afa63c8e2a6a39d50954cb6316576b4e9"></a></strong>ROP_NOT</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2070081147165623"><a name="p2070081147165623"></a><a name="p2070081147165623"></a>~S1</p>
<p id="p162213243201"><a name="p162213243201"></a><a name="p162213243201"></a></p>
</td>
</tr>
<tr id="row443497098165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1980894858165623p0"><a name="entry1980894858165623p0"></a><a name="entry1980894858165623p0"></a><strong id="gga24265f7618fbdba53d3da4806d3097c4a79433776e85bb80ad0306ced0b82947c"><a name="gga24265f7618fbdba53d3da4806d3097c4a79433776e85bb80ad0306ced0b82947c"></a><a name="gga24265f7618fbdba53d3da4806d3097c4a79433776e85bb80ad0306ced0b82947c"></a></strong>ROP_XORPEN</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p86922723165623"><a name="p86922723165623"></a><a name="p86922723165623"></a>S2^S1</p>
<p id="p622122432010"><a name="p622122432010"></a><a name="p622122432010"></a></p>
</td>
</tr>
<tr id="row438127959165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1844155066165623p0"><a name="entry1844155066165623p0"></a><a name="entry1844155066165623p0"></a><strong id="gga24265f7618fbdba53d3da4806d3097c4ad6c4d2458a9caaa079a3e5907d636e8a"><a name="gga24265f7618fbdba53d3da4806d3097c4ad6c4d2458a9caaa079a3e5907d636e8a"></a><a name="gga24265f7618fbdba53d3da4806d3097c4ad6c4d2458a9caaa079a3e5907d636e8a"></a></strong>ROP_NOTMASKPEN</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p675409925165623"><a name="p675409925165623"></a><a name="p675409925165623"></a>~(S2&amp;S1)</p>
<p id="p11221024172017"><a name="p11221024172017"></a><a name="p11221024172017"></a></p>
</td>
</tr>
<tr id="row244916934165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1464253256165623p0"><a name="entry1464253256165623p0"></a><a name="entry1464253256165623p0"></a><strong id="gga24265f7618fbdba53d3da4806d3097c4a2a069e2105c5b8d4dac5d174c76eb9d4"><a name="gga24265f7618fbdba53d3da4806d3097c4a2a069e2105c5b8d4dac5d174c76eb9d4"></a><a name="gga24265f7618fbdba53d3da4806d3097c4a2a069e2105c5b8d4dac5d174c76eb9d4"></a></strong>ROP_MASKPEN</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1708990751165623"><a name="p1708990751165623"></a><a name="p1708990751165623"></a>S2&amp;S1</p>
<p id="p20221162414201"><a name="p20221162414201"></a><a name="p20221162414201"></a></p>
</td>
</tr>
<tr id="row1453649858165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry671811663165623p0"><a name="entry671811663165623p0"></a><a name="entry671811663165623p0"></a><strong id="gga24265f7618fbdba53d3da4806d3097c4a33c37c5ce718e876f43141dc5a028375"><a name="gga24265f7618fbdba53d3da4806d3097c4a33c37c5ce718e876f43141dc5a028375"></a><a name="gga24265f7618fbdba53d3da4806d3097c4a33c37c5ce718e876f43141dc5a028375"></a></strong>ROP_NOTXORPEN</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1838255338165623"><a name="p1838255338165623"></a><a name="p1838255338165623"></a>~(S2^S1)</p>
<p id="p142212245209"><a name="p142212245209"></a><a name="p142212245209"></a></p>
</td>
</tr>
<tr id="row1673845494165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry47443128165623p0"><a name="entry47443128165623p0"></a><a name="entry47443128165623p0"></a><strong id="gga24265f7618fbdba53d3da4806d3097c4a2acacab882af44bba09878bd58e18695"><a name="gga24265f7618fbdba53d3da4806d3097c4a2acacab882af44bba09878bd58e18695"></a><a name="gga24265f7618fbdba53d3da4806d3097c4a2acacab882af44bba09878bd58e18695"></a></strong>ROP_NOP</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p102866306165623"><a name="p102866306165623"></a><a name="p102866306165623"></a>S1</p>
<p id="p6221524152014"><a name="p6221524152014"></a><a name="p6221524152014"></a></p>
</td>
</tr>
<tr id="row1713266554165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1826165686165623p0"><a name="entry1826165686165623p0"></a><a name="entry1826165686165623p0"></a><strong id="gga24265f7618fbdba53d3da4806d3097c4afaea3c47612082914332b78ca8c331b3"><a name="gga24265f7618fbdba53d3da4806d3097c4afaea3c47612082914332b78ca8c331b3"></a><a name="gga24265f7618fbdba53d3da4806d3097c4afaea3c47612082914332b78ca8c331b3"></a></strong>ROP_MERGENOTPEN</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1634405847165623"><a name="p1634405847165623"></a><a name="p1634405847165623"></a>~S2+S1</p>
<p id="p15221122420201"><a name="p15221122420201"></a><a name="p15221122420201"></a></p>
</td>
</tr>
<tr id="row1836314553165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1414480501165623p0"><a name="entry1414480501165623p0"></a><a name="entry1414480501165623p0"></a><strong id="gga24265f7618fbdba53d3da4806d3097c4a91bae697f9dea25ac4d7be011958a45d"><a name="gga24265f7618fbdba53d3da4806d3097c4a91bae697f9dea25ac4d7be011958a45d"></a><a name="gga24265f7618fbdba53d3da4806d3097c4a91bae697f9dea25ac4d7be011958a45d"></a></strong>ROP_COPYPE</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1554139726165623"><a name="p1554139726165623"></a><a name="p1554139726165623"></a>S2</p>
<p id="p16221132462014"><a name="p16221132462014"></a><a name="p16221132462014"></a></p>
</td>
</tr>
<tr id="row1388502708165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry486284952165623p0"><a name="entry486284952165623p0"></a><a name="entry486284952165623p0"></a><strong id="gga24265f7618fbdba53d3da4806d3097c4a3580b77320e4829da046b8739c61d6b8"><a name="gga24265f7618fbdba53d3da4806d3097c4a3580b77320e4829da046b8739c61d6b8"></a><a name="gga24265f7618fbdba53d3da4806d3097c4a3580b77320e4829da046b8739c61d6b8"></a></strong>ROP_MERGEPENNOT</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1394684612165623"><a name="p1394684612165623"></a><a name="p1394684612165623"></a>S2+~S1</p>
<p id="p422162415206"><a name="p422162415206"></a><a name="p422162415206"></a></p>
</td>
</tr>
<tr id="row1013965263165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1719817108165623p0"><a name="entry1719817108165623p0"></a><a name="entry1719817108165623p0"></a><strong id="gga24265f7618fbdba53d3da4806d3097c4a8195ac0d37e0d69b2cd71dd7362d3fd3"><a name="gga24265f7618fbdba53d3da4806d3097c4a8195ac0d37e0d69b2cd71dd7362d3fd3"></a><a name="gga24265f7618fbdba53d3da4806d3097c4a8195ac0d37e0d69b2cd71dd7362d3fd3"></a></strong>ROP_MERGEPEN</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1006527208165623"><a name="p1006527208165623"></a><a name="p1006527208165623"></a>S2+S1</p>
<p id="p1522118242209"><a name="p1522118242209"></a><a name="p1522118242209"></a></p>
</td>
</tr>
<tr id="row731429167165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1673095062165623p0"><a name="entry1673095062165623p0"></a><a name="entry1673095062165623p0"></a><strong id="gga24265f7618fbdba53d3da4806d3097c4a533a614b27da8a81b67ada085b018618"><a name="gga24265f7618fbdba53d3da4806d3097c4a533a614b27da8a81b67ada085b018618"></a><a name="gga24265f7618fbdba53d3da4806d3097c4a533a614b27da8a81b67ada085b018618"></a></strong>ROP_WHITE</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1021082323165623"><a name="p1021082323165623"></a><a name="p1021082323165623"></a>Whiteness</p>
<p id="p18221122482010"><a name="p18221122482010"></a><a name="p18221122482010"></a></p>
</td>
</tr>
<tr id="row1880469928165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry792741787165623p0"><a name="entry792741787165623p0"></a><a name="entry792741787165623p0"></a><strong id="gga24265f7618fbdba53d3da4806d3097c4aa858b07e214a7f62625e24776806c74b"><a name="gga24265f7618fbdba53d3da4806d3097c4aa858b07e214a7f62625e24776806c74b"></a><a name="gga24265f7618fbdba53d3da4806d3097c4aa858b07e214a7f62625e24776806c74b"></a></strong>ROP_BUTT</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p809714950165623"><a name="p809714950165623"></a><a name="p809714950165623"></a>Invalid ROP type</p>
<p id="p1722182482013"><a name="p1722182482013"></a><a name="p1722182482013"></a></p>
</td>
</tr>
</tbody>
</table>

## TransformType<a name="gaa65f3b21a9a92ff022e435a7304126d2"></a>

```
enum [TransformType](Display.md#gaa65f3b21a9a92ff022e435a7304126d2)
```

**Description:**

Enumerates transform types of images.

<a name="table1739202513165623"></a>
<table><thead align="left"><tr id="row160726177165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1711259161165623"><a name="p1711259161165623"></a><a name="p1711259161165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p770906974165623"><a name="p770906974165623"></a><a name="p770906974165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1199312990165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1918949892165623p0"><a name="entry1918949892165623p0"></a><a name="entry1918949892165623p0"></a><strong id="ggaa65f3b21a9a92ff022e435a7304126d2a68e349e9d45a8eba440e2a7a3ba31ec9"><a name="ggaa65f3b21a9a92ff022e435a7304126d2a68e349e9d45a8eba440e2a7a3ba31ec9"></a><a name="ggaa65f3b21a9a92ff022e435a7304126d2a68e349e9d45a8eba440e2a7a3ba31ec9"></a></strong>ROTATE_NONE</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p991404083165623"><a name="p991404083165623"></a><a name="p991404083165623"></a>No rotation</p>
<p id="p3233524122011"><a name="p3233524122011"></a><a name="p3233524122011"></a></p>
</td>
</tr>
<tr id="row1142750312165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1116523232165623p0"><a name="entry1116523232165623p0"></a><a name="entry1116523232165623p0"></a><strong id="ggaa65f3b21a9a92ff022e435a7304126d2a685062467b0c1a3164556335b467c886"><a name="ggaa65f3b21a9a92ff022e435a7304126d2a685062467b0c1a3164556335b467c886"></a><a name="ggaa65f3b21a9a92ff022e435a7304126d2a685062467b0c1a3164556335b467c886"></a></strong>ROTATE_90</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2003974720165623"><a name="p2003974720165623"></a><a name="p2003974720165623"></a>Rotation by 90 degrees</p>
<p id="p10233102442015"><a name="p10233102442015"></a><a name="p10233102442015"></a></p>
</td>
</tr>
<tr id="row61316208165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1709250174165623p0"><a name="entry1709250174165623p0"></a><a name="entry1709250174165623p0"></a><strong id="ggaa65f3b21a9a92ff022e435a7304126d2a186263164422bb8f0eb5f7b7d195a3d1"><a name="ggaa65f3b21a9a92ff022e435a7304126d2a186263164422bb8f0eb5f7b7d195a3d1"></a><a name="ggaa65f3b21a9a92ff022e435a7304126d2a186263164422bb8f0eb5f7b7d195a3d1"></a></strong>ROTATE_180</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p800014535165623"><a name="p800014535165623"></a><a name="p800014535165623"></a>Rotation by 180 degrees</p>
<p id="p1123342442014"><a name="p1123342442014"></a><a name="p1123342442014"></a></p>
</td>
</tr>
<tr id="row1244934427165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry533260770165623p0"><a name="entry533260770165623p0"></a><a name="entry533260770165623p0"></a><strong id="ggaa65f3b21a9a92ff022e435a7304126d2a554e734d2a23790b248c5ce39816c18f"><a name="ggaa65f3b21a9a92ff022e435a7304126d2a554e734d2a23790b248c5ce39816c18f"></a><a name="ggaa65f3b21a9a92ff022e435a7304126d2a554e734d2a23790b248c5ce39816c18f"></a></strong>ROTATE_270</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p654428043165623"><a name="p654428043165623"></a><a name="p654428043165623"></a>Rotation by 270 degrees</p>
<p id="p17233142417209"><a name="p17233142417209"></a><a name="p17233142417209"></a></p>
</td>
</tr>
<tr id="row864006266165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry451613697165623p0"><a name="entry451613697165623p0"></a><a name="entry451613697165623p0"></a><strong id="ggaa65f3b21a9a92ff022e435a7304126d2a9b6ff871536aeef2a8e3ce4a753988ed"><a name="ggaa65f3b21a9a92ff022e435a7304126d2a9b6ff871536aeef2a8e3ce4a753988ed"></a><a name="ggaa65f3b21a9a92ff022e435a7304126d2a9b6ff871536aeef2a8e3ce4a753988ed"></a></strong>ROTATE_BUTT</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p409190875165623"><a name="p409190875165623"></a><a name="p409190875165623"></a>Invalid operation</p>
<p id="p132338247208"><a name="p132338247208"></a><a name="p132338247208"></a></p>
</td>
</tr>
</tbody>
</table>

## **Function**<a name="section2073407938165623"></a>

## GfxInitialize\(\)<a name="ga251580eb0614b601ef2c901c722a59d3"></a>

```
int32_t GfxInitialize ([GfxFuncs](GfxFuncs.md) ** funcs)
```

**Description:**

Initializes the hardware acceleration module to obtain the pointer to functions for hardware acceleration operations.

**Parameters:**

<a name="table311713136165623"></a>
<table><thead align="left"><tr id="row1068826487165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p47871243165623"><a name="p47871243165623"></a><a name="p47871243165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p183024421165623"><a name="p183024421165623"></a><a name="p183024421165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2078717164165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry873994534165623p0"><a name="entry873994534165623p0"></a><a name="entry873994534165623p0"></a>funcs</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1262943327165623p0"><a name="entry1262943327165623p0"></a><a name="entry1262943327165623p0"></a>Indicates the double pointer to functions for hardware acceleration operations. Memory is allocated automatically when you initiate the hardware acceleration module, so you can simply use the pointer to gain access to the functions.</p>
</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns an error code defined in  [DispErrCode](Display.md#ga12a925dadef7573cd74d63d06824f9b0)  otherwise.

**See also:**

[GfxUninitialize](Display.md#ga32595139adb26cfaacf709661b29b347)

## GfxUninitialize\(\)<a name="ga32595139adb26cfaacf709661b29b347"></a>

```
int32_t GfxUninitialize ([GfxFuncs](GfxFuncs.md) * funcs)
```

**Description:**

Deinitializes the hardware acceleration module to release the memory allocated to the pointer to functions for hardware acceleration operations.

**Parameters:**

<a name="table930859488165623"></a>
<table><thead align="left"><tr id="row840545168165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2113813761165623"><a name="p2113813761165623"></a><a name="p2113813761165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1414737273165623"><a name="p1414737273165623"></a><a name="p1414737273165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1925996845165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1060745960165623p0"><a name="entry1060745960165623p0"></a><a name="entry1060745960165623p0"></a>funcs</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry708713561165623p0"><a name="entry708713561165623p0"></a><a name="entry708713561165623p0"></a>Indicates the pointer to functions for hardware acceleration operations.</p>
</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns an error code defined in  [DispErrCode](Display.md#ga12a925dadef7573cd74d63d06824f9b0)  otherwise.

**See also:**

[GfxInitialize](Display.md#ga251580eb0614b601ef2c901c722a59d3)

## GrallocInitialize\(\)<a name="ga304347c32a67bf7b20ef5d2b5714e5fa"></a>

```
int32_t GrallocInitialize ([GrallocFuncs](GrallocFuncs.md) ** funcs)
```

**Description:**

Initializes the memory module to obtain the pointer to functions for memory operations.

**Parameters:**

<a name="table1761471434165623"></a>
<table><thead align="left"><tr id="row1679489828165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1988587987165623"><a name="p1988587987165623"></a><a name="p1988587987165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1099511817165623"><a name="p1099511817165623"></a><a name="p1099511817165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1070125787165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry923397211165623p0"><a name="entry923397211165623p0"></a><a name="entry923397211165623p0"></a>funcs</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry586882869165623p0"><a name="entry586882869165623p0"></a><a name="entry586882869165623p0"></a>Indicates the double pointer to functions for memory operations. Memory is allocated automatically when you initiate the memory module initialization, so you can simply use the pointer to gain access to the functions.</p>
</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns an error code defined in  [DispErrCode](Display.md#ga12a925dadef7573cd74d63d06824f9b0)  otherwise.

## GrallocUninitialize\(\)<a name="ga8842b25f91c247606048ab2d5cdb338f"></a>

```
int32_t GrallocUninitialize ([GrallocFuncs](GrallocFuncs.md) * funcs)
```

**Description:**

Deinitializes the memory module to release the memory allocated to the pointer to functions for memory operations.

**Parameters:**

<a name="table349547647165623"></a>
<table><thead align="left"><tr id="row1722747332165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1073083901165623"><a name="p1073083901165623"></a><a name="p1073083901165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1983048356165623"><a name="p1983048356165623"></a><a name="p1983048356165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row101809574165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1729609738165623p0"><a name="entry1729609738165623p0"></a><a name="entry1729609738165623p0"></a>funcs</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry479132591165623p0"><a name="entry479132591165623p0"></a><a name="entry479132591165623p0"></a>Indicates the pointer to functions for memory operations.</p>
</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns an error code defined in  [DispErrCode](Display.md#ga12a925dadef7573cd74d63d06824f9b0)  otherwise.

## LayerInitialize\(\)<a name="ga061e587306a5d0367ff228d64434c05d"></a>

```
int32_t LayerInitialize ([LayerFuncs](LayerFuncs.md) ** funcs)
```

**Description:**

Initializes the layer to apply for resources used by the layer and obtain the pointer to functions for layer operations.

**Parameters:**

<a name="table1518620413165623"></a>
<table><thead align="left"><tr id="row798073422165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p840806297165623"><a name="p840806297165623"></a><a name="p840806297165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p12332673165623"><a name="p12332673165623"></a><a name="p12332673165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1997866799165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry373094250165623p0"><a name="entry373094250165623p0"></a><a name="entry373094250165623p0"></a>funcs</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry431820374165623p0"><a name="entry431820374165623p0"></a><a name="entry431820374165623p0"></a>Indicates the double pointer to functions for layer operations. Memory is allocated automatically when you initiate the layer module, so you can simply use the pointer to gain access to the functions.</p>
</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns an error code defined in  [DispErrCode](Display.md#ga12a925dadef7573cd74d63d06824f9b0)  otherwise.

**See also:**

[LayerUninitialize](Display.md#ga4e32b1a65cf243a9ac015b632a4eea0b)

## LayerUninitialize\(\)<a name="ga4e32b1a65cf243a9ac015b632a4eea0b"></a>

```
int32_t LayerUninitialize ([LayerFuncs](LayerFuncs.md) * funcs)
```

**Description:**

Deinitializes the layer module to release the memory allocated to the pointer to functions for layer operations.

**Parameters:**

<a name="table626806512165623"></a>
<table><thead align="left"><tr id="row1620108934165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p542043193165623"><a name="p542043193165623"></a><a name="p542043193165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p444944644165623"><a name="p444944644165623"></a><a name="p444944644165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row831802710165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry19478289165623p0"><a name="entry19478289165623p0"></a><a name="entry19478289165623p0"></a>funcs</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry492505191165623p0"><a name="entry492505191165623p0"></a><a name="entry492505191165623p0"></a>Indicates the pointer to functions for layer operations.</p>
</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns an error code defined in  [DispErrCode](Display.md#ga12a925dadef7573cd74d63d06824f9b0)  otherwise.

**See also:**

[LayerInitialize](Display.md#ga061e587306a5d0367ff228d64434c05d)

