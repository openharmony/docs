# Capbility<a name="ZH-CN_TOPIC_0000001055198124"></a>

-   [Overview](#section749981014165631)
-   [Summary](#section1164889656165631)
-   [Data Fields](#pub-attribs)
-   [Details](#section1024502433165631)
-   [Field](#section483310989165631)
-   [allocateMask](#aed3e8869cfc5842e22d445588c493622)
-   [capsMask](#a8bde7a8bbe0a8acbc134dd51521cfbdf)
-   [maxBitRate](#af0abc05742fc15f22960641bc32b274b)
-   [maxSize](#a1781db5047e1c552a5983b039121ee9f)
-   [mime](#a7828502f8ef57adf7822b65f72f496be)
-   [minBitRate](#aee07db6d7bd5b0d68accea81be6bc4f2)
-   [minInputBufferNum](#a53d07b315a98736d45fc94bae43343eb)
-   [minOutputBufferNum](#ac6ddc30ed893bc43980392027d96b689)
-   [minSize](#a48f8a48ef6ddd6304ce137b11a33cf8c)
-   [supportLevels](#aa1c3910c3552de9ac2c39907f679cbf7)
-   [supportPixelFormats](#a059387b07149edb590b3174510296662)
-   [supportProfiles](#ab20f0a14b1d43e3a694f350e1a069811)
-   [type](#a21fa5ad7f3b8c3a9e625e4a6e26b56b8)
-   [whAlignment](#aeccf15947ba85e01429d350c724be846)

## **Overview**<a name="section749981014165631"></a>

**Related Modules:**

[Codec](Codec.md)

**Description:**

Defines the codec capability. 

## **Summary**<a name="section1164889656165631"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1181570076165631"></a>
<table><thead align="left"><tr id="row1019223111165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1107480116165631"><a name="p1107480116165631"></a><a name="p1107480116165631"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p141901428165631"><a name="p141901428165631"></a><a name="p141901428165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row277305335165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2091825723165631"><a name="p2091825723165631"></a><a name="p2091825723165631"></a><a href="Capbility.md#a7828502f8ef57adf7822b65f72f496be">mime</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p618179652165631"><a name="p618179652165631"></a><a name="p618179652165631"></a><a href="Codec.md#ga1bee586eafa91dfb60f94ba40fc95faa">AvCodecMime</a> </p>
</td>
</tr>
<tr id="row569516057165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p688856427165631"><a name="p688856427165631"></a><a name="p688856427165631"></a><a href="Capbility.md#a21fa5ad7f3b8c3a9e625e4a6e26b56b8">type</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1463416952165631"><a name="p1463416952165631"></a><a name="p1463416952165631"></a><a href="Codec.md#ga03b4b6ae5fb82af68d46aaea3d3e4d79">CodecType</a> </p>
</td>
</tr>
<tr id="row200012176165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1970383343165631"><a name="p1970383343165631"></a><a name="p1970383343165631"></a><a href="Capbility.md#aeccf15947ba85e01429d350c724be846">whAlignment</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1520534803165631"><a name="p1520534803165631"></a><a name="p1520534803165631"></a><a href="Alginment.md">Alginment</a> </p>
</td>
</tr>
<tr id="row1494512233165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p186646436165631"><a name="p186646436165631"></a><a name="p186646436165631"></a><a href="Capbility.md#a48f8a48ef6ddd6304ce137b11a33cf8c">minSize</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1885157231165631"><a name="p1885157231165631"></a><a name="p1885157231165631"></a><a href="Rect.md">Rect</a> </p>
</td>
</tr>
<tr id="row574267888165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2102458885165631"><a name="p2102458885165631"></a><a name="p2102458885165631"></a><a href="Capbility.md#a1781db5047e1c552a5983b039121ee9f">maxSize</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1423007795165631"><a name="p1423007795165631"></a><a name="p1423007795165631"></a><a href="Rect.md">Rect</a> </p>
</td>
</tr>
<tr id="row458628774165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2088897320165631"><a name="p2088897320165631"></a><a name="p2088897320165631"></a><a href="Capbility.md#aee07db6d7bd5b0d68accea81be6bc4f2">minBitRate</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p845593669165631"><a name="p845593669165631"></a><a name="p845593669165631"></a>uint64_t </p>
</td>
</tr>
<tr id="row1570555285165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p220653208165631"><a name="p220653208165631"></a><a name="p220653208165631"></a><a href="Capbility.md#af0abc05742fc15f22960641bc32b274b">maxBitRate</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p258805433165631"><a name="p258805433165631"></a><a name="p258805433165631"></a>uint64_t </p>
</td>
</tr>
<tr id="row1791441486165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p293897053165631"><a name="p293897053165631"></a><a name="p293897053165631"></a><a href="Capbility.md#ab20f0a14b1d43e3a694f350e1a069811">supportProfiles</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2084931780165631"><a name="p2084931780165631"></a><a name="p2084931780165631"></a><a href="ResizableArray.md">ResizableArray</a> </p>
</td>
</tr>
<tr id="row2005792720165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2107793875165631"><a name="p2107793875165631"></a><a name="p2107793875165631"></a><a href="Capbility.md#aa1c3910c3552de9ac2c39907f679cbf7">supportLevels</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p726019739165631"><a name="p726019739165631"></a><a name="p726019739165631"></a><a href="ResizableArray.md">ResizableArray</a> </p>
</td>
</tr>
<tr id="row368064617165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1836681879165631"><a name="p1836681879165631"></a><a name="p1836681879165631"></a><a href="Capbility.md#a059387b07149edb590b3174510296662">supportPixelFormats</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1555785390165631"><a name="p1555785390165631"></a><a name="p1555785390165631"></a><a href="ResizableArray.md">ResizableArray</a> </p>
</td>
</tr>
<tr id="row868412876165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1237216490165631"><a name="p1237216490165631"></a><a name="p1237216490165631"></a><a href="Capbility.md#a53d07b315a98736d45fc94bae43343eb">minInputBufferNum</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2137690056165631"><a name="p2137690056165631"></a><a name="p2137690056165631"></a>uint32_t </p>
</td>
</tr>
<tr id="row447448975165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1057414127165631"><a name="p1057414127165631"></a><a name="p1057414127165631"></a><a href="Capbility.md#ac6ddc30ed893bc43980392027d96b689">minOutputBufferNum</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1906989529165631"><a name="p1906989529165631"></a><a name="p1906989529165631"></a>uint32_t </p>
</td>
</tr>
<tr id="row1008174104165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p921142784165631"><a name="p921142784165631"></a><a name="p921142784165631"></a><a href="Capbility.md#aed3e8869cfc5842e22d445588c493622">allocateMask</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p927653653165631"><a name="p927653653165631"></a><a name="p927653653165631"></a>uint32_t </p>
</td>
</tr>
<tr id="row217565967165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1828438518165631"><a name="p1828438518165631"></a><a name="p1828438518165631"></a><a href="Capbility.md#a8bde7a8bbe0a8acbc134dd51521cfbdf">capsMask</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1729627116165631"><a name="p1729627116165631"></a><a name="p1729627116165631"></a>uint32_t </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1024502433165631"></a>

## **Field **<a name="section483310989165631"></a>

## allocateMask<a name="aed3e8869cfc5842e22d445588c493622"></a>

```
uint32_t Capbility::allocateMask
```

 **Description:**

Buffer allocation mode. For details, see  [AllocateBufferMode](Codec.md#gaf59a3505491b6f0b5dff5d62372a9679). 

## capsMask<a name="a8bde7a8bbe0a8acbc134dd51521cfbdf"></a>

```
uint32_t Capbility::capsMask
```

 **Description:**

Capability mask. For details, see  [CapsMask](Codec.md#ga09af5b0a9d5134ad4d44cbe8cbe7b887). 

## maxBitRate<a name="af0abc05742fc15f22960641bc32b274b"></a>

```
uint64_t Capbility::maxBitRate
```

 **Description:**

Maximum bit rate supported 

## maxSize<a name="a1781db5047e1c552a5983b039121ee9f"></a>

```
[Rect](Rect.md) Capbility::maxSize
```

 **Description:**

Maximum resolution supported 

## mime<a name="a7828502f8ef57adf7822b65f72f496be"></a>

```
[AvCodecMime](Codec.md#ga1bee586eafa91dfb60f94ba40fc95faa) Capbility::mime
```

 **Description:**

MIME type 

## minBitRate<a name="aee07db6d7bd5b0d68accea81be6bc4f2"></a>

```
uint64_t Capbility::minBitRate
```

 **Description:**

Minimum bit rate supported 

## minInputBufferNum<a name="a53d07b315a98736d45fc94bae43343eb"></a>

```
uint32_t Capbility::minInputBufferNum
```

 **Description:**

Minimum number of input buffers required for running 

## minOutputBufferNum<a name="ac6ddc30ed893bc43980392027d96b689"></a>

```
uint32_t Capbility::minOutputBufferNum
```

 **Description:**

Minimum number of output buffers required for running 

## minSize<a name="a48f8a48ef6ddd6304ce137b11a33cf8c"></a>

```
[Rect](Rect.md) Capbility::minSize
```

 **Description:**

Minimum resolution supported 

## supportLevels<a name="aa1c3910c3552de9ac2c39907f679cbf7"></a>

```
[ResizableArray](ResizableArray.md) Capbility::supportLevels
```

 **Description:**

Supported levels 

## supportPixelFormats<a name="a059387b07149edb590b3174510296662"></a>

```
[ResizableArray](ResizableArray.md) Capbility::supportPixelFormats
```

 **Description:**

Supported pixel formats 

## supportProfiles<a name="ab20f0a14b1d43e3a694f350e1a069811"></a>

```
[ResizableArray](ResizableArray.md) Capbility::supportProfiles
```

 **Description:**

Supported profiles 

## type<a name="a21fa5ad7f3b8c3a9e625e4a6e26b56b8"></a>

```
[CodecType](Codec.md#ga03b4b6ae5fb82af68d46aaea3d3e4d79) Capbility::type
```

 **Description:**

Codec type 

## whAlignment<a name="aeccf15947ba85e01429d350c724be846"></a>

```
[Alginment](Alginment.md) Capbility::whAlignment
```

 **Description:**

Value to align with the width and height 

