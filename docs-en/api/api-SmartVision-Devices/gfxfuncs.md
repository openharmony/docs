# GfxFuncs<a name="EN-US_TOPIC_0000001054598159"></a>

-   [Overview](#section1836335825165631)
-   [Summary](#section2026088827165631)
-   [Data Fields](#pub-attribs)
-   [Details](#section2110107619165631)
-   [Field](#section1301358906165631)
-   [Blit](#ab5bf93f23b73413e7aa7618a202364d7)
-   [DeinitGfx](#ad86b127aad2a6e7f01e07b77054d42b3)
-   [DrawCircle](#acac8893b6bf7ab9abdad1b563c4ab6f2)
-   [DrawLine](#a5715347b14918e0dca51a9fd7b3d1a47)
-   [DrawRectangle](#a96785cdbc636179fc51026fc589cac17)
-   [FillRect](#a12cf050a4c0d76f9816008fb102c7330)
-   [InitGfx](#a3ec8ed6a467ed0c88e4dd723723c0f41)
-   [Sync](#aa1d93d9b5bc48cf48acb358ef531998a)

## **Overview**<a name="section1836335825165631"></a>

**Related Modules:**

[Display](display.md)

**Description:**

Defines pointers to the hardware acceleration driver functions. 

## **Summary**<a name="section2026088827165631"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1341567323165631"></a>
<table><thead align="left"><tr id="row2135443371165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1096543092165631"><a name="p1096543092165631"></a><a name="p1096543092165631"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1546500005165631"><a name="p1546500005165631"></a><a name="p1546500005165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1010270694165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1354796280165631"><a name="p1354796280165631"></a><a name="p1354796280165631"></a><a href="gfxfuncs.md#a3ec8ed6a467ed0c88e4dd723723c0f41">InitGfx</a> )(void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p696552656165631"><a name="p696552656165631"></a><a name="p696552656165631"></a>int32_t(* </p>
<p id="p956255082165631"><a name="p956255082165631"></a><a name="p956255082165631"></a>Initializes hardware acceleration. </p>
</td>
</tr>
<tr id="row1211322686165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1007368523165631"><a name="p1007368523165631"></a><a name="p1007368523165631"></a><a href="gfxfuncs.md#ad86b127aad2a6e7f01e07b77054d42b3">DeinitGfx</a> )(void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1211280589165631"><a name="p1211280589165631"></a><a name="p1211280589165631"></a>int32_t(* </p>
<p id="p1522584226165631"><a name="p1522584226165631"></a><a name="p1522584226165631"></a>Deinitializes hardware acceleration. </p>
</td>
</tr>
<tr id="row918229323165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p487373170165631"><a name="p487373170165631"></a><a name="p487373170165631"></a><a href="gfxfuncs.md#a12cf050a4c0d76f9816008fb102c7330">FillRect</a> )(<a href="isurface.md">ISurface</a> *surface, <a href="irect.md">IRect</a> *rect, uint32_t color, <a href="gfxopt.md">GfxOpt</a> *opt)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1009676444165631"><a name="p1009676444165631"></a><a name="p1009676444165631"></a>int32_t(* </p>
<p id="p694041280165631"><a name="p694041280165631"></a><a name="p694041280165631"></a>Fills a rectangle with a given color on the canvas. </p>
</td>
</tr>
<tr id="row1665692523165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p325741225165631"><a name="p325741225165631"></a><a name="p325741225165631"></a><a href="gfxfuncs.md#a96785cdbc636179fc51026fc589cac17">DrawRectangle</a> )(<a href="isurface.md">ISurface</a> *surface, <a href="rectangle.md">Rectangle</a> *rect, uint32_t color, <a href="gfxopt.md">GfxOpt</a> *opt)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p592242632165631"><a name="p592242632165631"></a><a name="p592242632165631"></a>int32_t(* </p>
<p id="p123472340165631"><a name="p123472340165631"></a><a name="p123472340165631"></a>Draws a rectangle with a given color on the canvas. </p>
</td>
</tr>
<tr id="row535404516165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p602330457165631"><a name="p602330457165631"></a><a name="p602330457165631"></a><a href="gfxfuncs.md#a5715347b14918e0dca51a9fd7b3d1a47">DrawLine</a> )(<a href="isurface.md">ISurface</a> *surface, <a href="iline.md">ILine</a> *line, <a href="gfxopt.md">GfxOpt</a> *opt)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p282813652165631"><a name="p282813652165631"></a><a name="p282813652165631"></a>int32_t(* </p>
<p id="p2021375143165631"><a name="p2021375143165631"></a><a name="p2021375143165631"></a>Draws a straight line with a given color on the canvas. </p>
</td>
</tr>
<tr id="row759662821165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2038222382165631"><a name="p2038222382165631"></a><a name="p2038222382165631"></a><a href="gfxfuncs.md#acac8893b6bf7ab9abdad1b563c4ab6f2">DrawCircle</a> )(<a href="isurface.md">ISurface</a> *surface, <a href="icircle.md">ICircle</a> *circle, <a href="gfxopt.md">GfxOpt</a> *opt)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1075648383165631"><a name="p1075648383165631"></a><a name="p1075648383165631"></a>int32_t(* </p>
<p id="p524621631165631"><a name="p524621631165631"></a><a name="p524621631165631"></a>Draws a circle with a specified center and radius on the canvas using a given color. </p>
</td>
</tr>
<tr id="row1925523198165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2034644577165631"><a name="p2034644577165631"></a><a name="p2034644577165631"></a><a href="gfxfuncs.md#ab5bf93f23b73413e7aa7618a202364d7">Blit</a> )(<a href="isurface.md">ISurface</a> *srcSurface, <a href="irect.md">IRect</a> *srcRect, <a href="isurface.md">ISurface</a> *dstSurface, <a href="irect.md">IRect</a> *dstRect)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1524389321165631"><a name="p1524389321165631"></a><a name="p1524389321165631"></a>int32_t(* </p>
<p id="p1364001435165631"><a name="p1364001435165631"></a><a name="p1364001435165631"></a>Blits bitmaps. </p>
</td>
</tr>
<tr id="row1237784321165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p856706219165631"><a name="p856706219165631"></a><a name="p856706219165631"></a><a href="gfxfuncs.md#aa1d93d9b5bc48cf48acb358ef531998a">Sync</a> )(void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1297660300165631"><a name="p1297660300165631"></a><a name="p1297660300165631"></a>int32_t(* </p>
<p id="p177224456165631"><a name="p177224456165631"></a><a name="p177224456165631"></a>Synchronizes hardware acceleration. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section2110107619165631"></a>

## **Field **<a name="section1301358906165631"></a>

## Blit<a name="ab5bf93f23b73413e7aa7618a202364d7"></a>

```
int32_t(* GfxFuncs::Blit) ([ISurface](isurface.md) *srcSurface, [IRect](irect.md) *srcRect, [ISurface](isurface.md) *dstSurface, [IRect](irect.md) *dstRect)
```

 **Description:**

Blits bitmaps. 

During bit blit, color space conversion \(CSC\), scaling, and rotation can be implemented.

**Parameters:**

<a name="table2056538317165631"></a>
<table><thead align="left"><tr id="row1877683857165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2025059337165631"><a name="p2025059337165631"></a><a name="p2025059337165631"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1594989025165631"><a name="p1594989025165631"></a><a name="p1594989025165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1203918015165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">srcSurface</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the source bitmap. </td>
</tr>
<tr id="row645468873165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">srcRect</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the rectangle of the source bitmap. </td>
</tr>
<tr id="row2075388012165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">dstSurface</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the destination bitmap. </td>
</tr>
<tr id="row1537327544165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">dstRect</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the rectangle of the destination bitmap.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns an error code defined in  [DispErrCode](display.md#ga12a925dadef7573cd74d63d06824f9b0)  otherwise. 

**See also:**

Blit3 

## DeinitGfx<a name="ad86b127aad2a6e7f01e07b77054d42b3"></a>

```
int32_t(* GfxFuncs::DeinitGfx) (void)
```

 **Description:**

Deinitializes hardware acceleration. 

**Returns:**

Returns  **0**  if the operation is successful; returns an error code defined in  [DispErrCode](display.md#ga12a925dadef7573cd74d63d06824f9b0)  otherwise. 

**See also:**

[InitGfx](gfxfuncs.md#a3ec8ed6a467ed0c88e4dd723723c0f41) 

## DrawCircle<a name="acac8893b6bf7ab9abdad1b563c4ab6f2"></a>

```
int32_t(* GfxFuncs::DrawCircle) ([ISurface](isurface.md) *surface, [ICircle](icircle.md) *circle, [GfxOpt](gfxopt.md) *opt)
```

 **Description:**

Draws a circle with a specified center and radius on the canvas using a given color. 

**Parameters:**

<a name="table1785123837165631"></a>
<table><thead align="left"><tr id="row54485907165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p584026952165631"><a name="p584026952165631"></a><a name="p584026952165631"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1873615849165631"><a name="p1873615849165631"></a><a name="p1873615849165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row387113229165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">surface</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the canvas. </td>
</tr>
<tr id="row594478632165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">circle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the circle to draw. </td>
</tr>
<tr id="row1454321848165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">opt</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the hardware acceleration option.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns an error code defined in  [DispErrCode](display.md#ga12a925dadef7573cd74d63d06824f9b0)  otherwise. 

## DrawLine<a name="a5715347b14918e0dca51a9fd7b3d1a47"></a>

```
int32_t(* GfxFuncs::DrawLine) ([ISurface](isurface.md) *surface, [ILine](iline.md) *line, [GfxOpt](gfxopt.md) *opt)
```

 **Description:**

Draws a straight line with a given color on the canvas. 

**Parameters:**

<a name="table1484875698165631"></a>
<table><thead align="left"><tr id="row823471223165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1058825235165631"><a name="p1058825235165631"></a><a name="p1058825235165631"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1697461739165631"><a name="p1697461739165631"></a><a name="p1697461739165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1444891286165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">surface</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the canvas. </td>
</tr>
<tr id="row1904615609165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">line</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the line to draw. </td>
</tr>
<tr id="row961523803165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">opt</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the hardware acceleration option.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns an error code defined in  [DispErrCode](display.md#ga12a925dadef7573cd74d63d06824f9b0)  otherwise. 

## DrawRectangle<a name="a96785cdbc636179fc51026fc589cac17"></a>

```
int32_t(* GfxFuncs::DrawRectangle) ([ISurface](isurface.md) *surface, [Rectangle](rectangle.md) *rect, uint32_t color, [GfxOpt](gfxopt.md) *opt)
```

 **Description:**

Draws a rectangle with a given color on the canvas. 

**Parameters:**

<a name="table1999364072165631"></a>
<table><thead align="left"><tr id="row484943985165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p231606181165631"><a name="p231606181165631"></a><a name="p231606181165631"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2083151164165631"><a name="p2083151164165631"></a><a name="p2083151164165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row210029790165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">surface</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the canvas. </td>
</tr>
<tr id="row449366765165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">rect</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the rectangle to draw. </td>
</tr>
<tr id="row1362231959165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">color</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the color to draw. </td>
</tr>
<tr id="row1394925635165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">opt</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the hardware acceleration option.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns an error code defined in  [DispErrCode](display.md#ga12a925dadef7573cd74d63d06824f9b0)  otherwise. 

**See also:**

[FillRect](gfxfuncs.md#a12cf050a4c0d76f9816008fb102c7330) 

## FillRect<a name="a12cf050a4c0d76f9816008fb102c7330"></a>

```
int32_t(* GfxFuncs::FillRect) ([ISurface](isurface.md) *surface, [IRect](irect.md) *rect, uint32_t color, [GfxOpt](gfxopt.md) *opt)
```

 **Description:**

Fills a rectangle with a given color on the canvas. 

**Parameters:**

<a name="table244132045165631"></a>
<table><thead align="left"><tr id="row873618784165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p654189530165631"><a name="p654189530165631"></a><a name="p654189530165631"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p123018026165631"><a name="p123018026165631"></a><a name="p123018026165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row189884563165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">surface</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the canvas. </td>
</tr>
<tr id="row2015727955165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">rect</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the rectangle to fill. </td>
</tr>
<tr id="row1437680251165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">color</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the color to fill. </td>
</tr>
<tr id="row331343953165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">opt</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the hardware acceleration option.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns an error code defined in  [DispErrCode](display.md#ga12a925dadef7573cd74d63d06824f9b0)  otherwise. 

## InitGfx<a name="a3ec8ed6a467ed0c88e4dd723723c0f41"></a>

```
int32_t(* GfxFuncs::InitGfx) (void)
```

 **Description:**

Initializes hardware acceleration. 

**Returns:**

Returns  **0**  if the operation is successful; returns an error code defined in  [DispErrCode](display.md#ga12a925dadef7573cd74d63d06824f9b0)  otherwise. 

**See also:**

[DeinitGfx](gfxfuncs.md#ad86b127aad2a6e7f01e07b77054d42b3) 

## Sync<a name="aa1d93d9b5bc48cf48acb358ef531998a"></a>

```
int32_t(* GfxFuncs::Sync) (void)
```

 **Description:**

Synchronizes hardware acceleration. 

Use this function for hardware acceleration synchronization when hardware acceleration is used to draw and blit bitmaps. This function blocks the process until hardware acceleration is complete.

**Parameters:**

<a name="table2085519189165631"></a>
<table><thead align="left"><tr id="row1553342968165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1789200100165631"><a name="p1789200100165631"></a><a name="p1789200100165631"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1373268286165631"><a name="p1373268286165631"></a><a name="p1373268286165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1573160615165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">timeOut</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the timeout duration for hardware acceleration synchronization. The value <strong id="b558456136165631"><a name="b558456136165631"></a><a name="b558456136165631"></a>0</strong> indicates no timeout, so the process waits until hardware acceleration is complete.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns an error code defined in  [DispErrCode](display.md#ga12a925dadef7573cd74d63d06824f9b0)  otherwise. 

