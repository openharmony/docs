# ISurface<a name="EN-US_TOPIC_0000001055518092"></a>

-   [Overview](#section1540575515165631)
-   [Summary](#section446071761165631)
-   [Data Fields](#pub-attribs)
-   [Details](#section20802730165631)
-   [Field](#section1265100385165631)
-   [alpha0](#ac2aa13d6c25df5d1a1fcfa92da425d29)
-   [alpha1](#a4fd217bfeb9d0a73992c797a900ba632)
-   [bAlphaExt1555](#a9d9ba9ee72ae25c0e84bfba10fe52f9a)
-   [bAlphaMax255](#a17f87b9850f83633f427eeceb74c93a7)
-   [bYCbCrClut](#ad2693b11b0cefeed40070364f9e31e84)
-   [cbcrPhyAddr](#adc8bc02eb42a881adf57caf06ddff243)
-   [cbcrStride](#a835f95df55db296dbf92061da1aa9627)
-   [clutPhyAddr](#a98bca93c426df8030c0a67b8fba02525)
-   [enColorFmt](#a260d540d41736284edc5a27c1ff46963)
-   [height](#ae68d2e393fe150b1bde8c312c36945c6)
-   [phyAddr](#aeac36e064994bcf2f2f1acc4b0f6a1ea)
-   [stride](#a61ea4da3897aac944042e60df73554be)
-   [width](#a3cc2e909bab924936e8273a237ddbb65)

## **Overview**<a name="section1540575515165631"></a>

**Related Modules:**

[Display](display.md)

**Description:**

Stores surface information for hardware acceleration, such as draw image, and bit blit. 

## **Summary**<a name="section446071761165631"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table302289190165631"></a>
<table><thead align="left"><tr id="row265234285165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1018151953165631"><a name="p1018151953165631"></a><a name="p1018151953165631"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1239824126165631"><a name="p1239824126165631"></a><a name="p1239824126165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1751105728165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1156387686165631"><a name="p1156387686165631"></a><a name="p1156387686165631"></a><a href="isurface.md#aeac36e064994bcf2f2f1acc4b0f6a1ea">phyAddr</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p178702793165631"><a name="p178702793165631"></a><a name="p178702793165631"></a>uint64_t </p>
</td>
</tr>
<tr id="row1624892688165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p510732868165631"><a name="p510732868165631"></a><a name="p510732868165631"></a><a href="isurface.md#ae68d2e393fe150b1bde8c312c36945c6">height</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p51318841165631"><a name="p51318841165631"></a><a name="p51318841165631"></a>int32_t </p>
</td>
</tr>
<tr id="row1478131760165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1858506943165631"><a name="p1858506943165631"></a><a name="p1858506943165631"></a><a href="isurface.md#a3cc2e909bab924936e8273a237ddbb65">width</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1686170287165631"><a name="p1686170287165631"></a><a name="p1686170287165631"></a>int32_t </p>
</td>
</tr>
<tr id="row1346602825165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1135209546165631"><a name="p1135209546165631"></a><a name="p1135209546165631"></a><a href="isurface.md#a61ea4da3897aac944042e60df73554be">stride</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p41587403165631"><a name="p41587403165631"></a><a name="p41587403165631"></a>int32_t </p>
</td>
</tr>
<tr id="row1669704666165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1413758778165631"><a name="p1413758778165631"></a><a name="p1413758778165631"></a><a href="isurface.md#a260d540d41736284edc5a27c1ff46963">enColorFmt</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1636176778165631"><a name="p1636176778165631"></a><a name="p1636176778165631"></a><a href="codec.md#ga60883d4958a60b91661e97027a85072a">PixelFormat</a> </p>
</td>
</tr>
<tr id="row891351499165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1707571242165631"><a name="p1707571242165631"></a><a name="p1707571242165631"></a><a href="isurface.md#ad2693b11b0cefeed40070364f9e31e84">bYCbCrClut</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1198283157165631"><a name="p1198283157165631"></a><a name="p1198283157165631"></a>bool </p>
</td>
</tr>
<tr id="row365270198165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p183189322165631"><a name="p183189322165631"></a><a name="p183189322165631"></a><a href="isurface.md#a17f87b9850f83633f427eeceb74c93a7">bAlphaMax255</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p758608946165631"><a name="p758608946165631"></a><a name="p758608946165631"></a>bool </p>
</td>
</tr>
<tr id="row1587676849165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p506460194165631"><a name="p506460194165631"></a><a name="p506460194165631"></a><a href="isurface.md#a9d9ba9ee72ae25c0e84bfba10fe52f9a">bAlphaExt1555</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1139513380165631"><a name="p1139513380165631"></a><a name="p1139513380165631"></a>bool </p>
</td>
</tr>
<tr id="row1172689074165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1550285264165631"><a name="p1550285264165631"></a><a name="p1550285264165631"></a><a href="isurface.md#ac2aa13d6c25df5d1a1fcfa92da425d29">alpha0</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1900906990165631"><a name="p1900906990165631"></a><a name="p1900906990165631"></a>uint8_t </p>
</td>
</tr>
<tr id="row1129978837165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1452693932165631"><a name="p1452693932165631"></a><a name="p1452693932165631"></a><a href="isurface.md#a4fd217bfeb9d0a73992c797a900ba632">alpha1</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p415343364165631"><a name="p415343364165631"></a><a name="p415343364165631"></a>uint8_t </p>
</td>
</tr>
<tr id="row841925010165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p770095845165631"><a name="p770095845165631"></a><a name="p770095845165631"></a><a href="isurface.md#adc8bc02eb42a881adf57caf06ddff243">cbcrPhyAddr</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1879531534165631"><a name="p1879531534165631"></a><a name="p1879531534165631"></a>uint64_t </p>
</td>
</tr>
<tr id="row122361451165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1380217327165631"><a name="p1380217327165631"></a><a name="p1380217327165631"></a><a href="isurface.md#a835f95df55db296dbf92061da1aa9627">cbcrStride</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1340633950165631"><a name="p1340633950165631"></a><a name="p1340633950165631"></a>int32_t </p>
</td>
</tr>
<tr id="row765968684165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p177463884165631"><a name="p177463884165631"></a><a name="p177463884165631"></a><a href="isurface.md#a98bca93c426df8030c0a67b8fba02525">clutPhyAddr</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2048261407165631"><a name="p2048261407165631"></a><a name="p2048261407165631"></a>uint64_t </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section20802730165631"></a>

## **Field **<a name="section1265100385165631"></a>

## alpha0<a name="ac2aa13d6c25df5d1a1fcfa92da425d29"></a>

```
uint8_t ISurface::alpha0
```

 **Description:**

Value of alpha0, ranging from 0 to 255 

## alpha1<a name="a4fd217bfeb9d0a73992c797a900ba632"></a>

```
uint8_t ISurface::alpha1
```

 **Description:**

Value of alpha1, ranging from 0 to 255 

## bAlphaExt1555<a name="a9d9ba9ee72ae25c0e84bfba10fe52f9a"></a>

```
bool ISurface::bAlphaExt1555
```

 **Description:**

ARGB1555 alpha extension enable bit 

## bAlphaMax255<a name="a17f87b9850f83633f427eeceb74c93a7"></a>

```
bool ISurface::bAlphaMax255
```

 **Description:**

Maximum alpha value of an image \(255 or 128\) 

## bYCbCrClut<a name="ad2693b11b0cefeed40070364f9e31e84"></a>

```
bool ISurface::bYCbCrClut
```

 **Description:**

Whether the color lookup table \(CLUT\) is in the YCbCr space 

## cbcrPhyAddr<a name="adc8bc02eb42a881adf57caf06ddff243"></a>

```
uint64_t ISurface::cbcrPhyAddr
```

 **Description:**

CbCr physical address 

## cbcrStride<a name="a835f95df55db296dbf92061da1aa9627"></a>

```
int32_t ISurface::cbcrStride
```

 **Description:**

CbCr stride 

## clutPhyAddr<a name="a98bca93c426df8030c0a67b8fba02525"></a>

```
uint64_t ISurface::clutPhyAddr
```

 **Description:**

Start physical address of the CLUT, used for color extension or correction 

## enColorFmt<a name="a260d540d41736284edc5a27c1ff46963"></a>

```
[PixelFormat](codec.md#ga60883d4958a60b91661e97027a85072a) ISurface::enColorFmt
```

 **Description:**

Image format 

## height<a name="ae68d2e393fe150b1bde8c312c36945c6"></a>

```
int32_t ISurface::height
```

 **Description:**

Image height 

## phyAddr<a name="aeac36e064994bcf2f2f1acc4b0f6a1ea"></a>

```
uint64_t ISurface::phyAddr
```

 **Description:**

Start physical address of an image 

## stride<a name="a61ea4da3897aac944042e60df73554be"></a>

```
int32_t ISurface::stride
```

 **Description:**

Image stride 

## width<a name="a3cc2e909bab924936e8273a237ddbb65"></a>

```
int32_t ISurface::width
```

 **Description:**

Image width 

