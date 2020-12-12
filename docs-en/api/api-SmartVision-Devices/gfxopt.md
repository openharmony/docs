# GfxOpt<a name="EN-US_TOPIC_0000001055678092"></a>

-   [Overview](#section1817863845165631)
-   [Summary](#section994812616165631)
-   [Data Fields](#pub-attribs)
-   [Details](#section1254484134165631)
-   [Field](#section1185676163165631)
-   [blendType](#ae1496544d54cd7a1f065bf8b061c6930)
-   [colorKeyFrom](#a6258754e9250402e52478d29eb2cf070)
-   [enableRop](#aa370e2a38a91f0762ddb48bdacf996c4)
-   [enableScale](#adc64f89952efe8c45ef77f3512190e2d)
-   [enAlpha](#a29ec54f7ca3a87aed83c4621979c6c0a)
-   [globalAlpha](#a812b71a7c6e8190e17307c726c31fc23)
-   [mirrorType](#a16e6d186004487eda4d78c5f8295cd64)
-   [ropType](#a171646d484843b2cc5c92cec8742766f)
-   [rotateType](#a3cf19bc3feeb0d286f526133cc0e027e)

## **Overview**<a name="section1817863845165631"></a>

**Related Modules:**

[Display](display.md)

**Description:**

Defines hardware acceleration options. 

## **Summary**<a name="section994812616165631"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1950903241165631"></a>
<table><thead align="left"><tr id="row535165104165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p883304784165631"><a name="p883304784165631"></a><a name="p883304784165631"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2093055221165631"><a name="p2093055221165631"></a><a name="p2093055221165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1274890685165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p67649396165631"><a name="p67649396165631"></a><a name="p67649396165631"></a><a href="gfxopt.md#a29ec54f7ca3a87aed83c4621979c6c0a">enAlpha</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1140727493165631"><a name="p1140727493165631"></a><a name="p1140727493165631"></a>bool </p>
</td>
</tr>
<tr id="row1781541885165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p479266816165631"><a name="p479266816165631"></a><a name="p479266816165631"></a><a href="gfxopt.md#a812b71a7c6e8190e17307c726c31fc23">globalAlpha</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1559719428165631"><a name="p1559719428165631"></a><a name="p1559719428165631"></a>uint32_t </p>
</td>
</tr>
<tr id="row310470698165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p687773223165631"><a name="p687773223165631"></a><a name="p687773223165631"></a><a href="gfxopt.md#ae1496544d54cd7a1f065bf8b061c6930">blendType</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p987828768165631"><a name="p987828768165631"></a><a name="p987828768165631"></a><a href="display.md#gaab1839ed4aab1030dfda801a51e68817">BlendType</a> </p>
</td>
</tr>
<tr id="row802600923165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2104406438165631"><a name="p2104406438165631"></a><a name="p2104406438165631"></a><a href="gfxopt.md#a6258754e9250402e52478d29eb2cf070">colorKeyFrom</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p737856097165631"><a name="p737856097165631"></a><a name="p737856097165631"></a><a href="display.md#ga4fe6fb05c7ba0048b1739d88f4d4878e">ColorKey</a> </p>
</td>
</tr>
<tr id="row1920173399165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1637951690165631"><a name="p1637951690165631"></a><a name="p1637951690165631"></a><a href="gfxopt.md#aa370e2a38a91f0762ddb48bdacf996c4">enableRop</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p285643922165631"><a name="p285643922165631"></a><a name="p285643922165631"></a>bool </p>
</td>
</tr>
<tr id="row1142334350165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1351198246165631"><a name="p1351198246165631"></a><a name="p1351198246165631"></a><a href="gfxopt.md#a171646d484843b2cc5c92cec8742766f">ropType</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1119834802165631"><a name="p1119834802165631"></a><a name="p1119834802165631"></a><a href="display.md#ga24265f7618fbdba53d3da4806d3097c4">RopType</a> </p>
</td>
</tr>
<tr id="row1496406255165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p536425117165631"><a name="p536425117165631"></a><a name="p536425117165631"></a><a href="gfxopt.md#adc64f89952efe8c45ef77f3512190e2d">enableScale</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1858058910165631"><a name="p1858058910165631"></a><a name="p1858058910165631"></a>bool </p>
</td>
</tr>
<tr id="row330475311165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p402691577165631"><a name="p402691577165631"></a><a name="p402691577165631"></a><a href="gfxopt.md#a3cf19bc3feeb0d286f526133cc0e027e">rotateType</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p759800257165631"><a name="p759800257165631"></a><a name="p759800257165631"></a><a href="display.md#gaa65f3b21a9a92ff022e435a7304126d2">TransformType</a> </p>
</td>
</tr>
<tr id="row1113776817165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1035729281165631"><a name="p1035729281165631"></a><a name="p1035729281165631"></a><a href="gfxopt.md#a16e6d186004487eda4d78c5f8295cd64">mirrorType</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1102106726165631"><a name="p1102106726165631"></a><a name="p1102106726165631"></a><a href="display.md#ga08d32376574b541d162d8534adb78fd0">MirrorType</a> </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1254484134165631"></a>

## **Field **<a name="section1185676163165631"></a>

## blendType<a name="ae1496544d54cd7a1f065bf8b061c6930"></a>

```
[BlendType](display.md#gaab1839ed4aab1030dfda801a51e68817) GfxOpt::blendType
```

 **Description:**

Blending type 

## colorKeyFrom<a name="a6258754e9250402e52478d29eb2cf070"></a>

```
[ColorKey](display.md#ga4fe6fb05c7ba0048b1739d88f4d4878e) GfxOpt::colorKeyFrom
```

 **Description:**

Color key mode 

## enableRop<a name="aa370e2a38a91f0762ddb48bdacf996c4"></a>

```
bool GfxOpt::enableRop
```

 **Description:**

Raster operations pipeline \(ROP\) enable bit 

## enableScale<a name="adc64f89952efe8c45ef77f3512190e2d"></a>

```
bool GfxOpt::enableScale
```

 **Description:**

Scaling enable bit 

## enAlpha<a name="a29ec54f7ca3a87aed83c4621979c6c0a"></a>

```
bool GfxOpt::enAlpha
```

 **Description:**

Alpha enable bit 

## globalAlpha<a name="a812b71a7c6e8190e17307c726c31fc23"></a>

```
uint32_t GfxOpt::globalAlpha
```

 **Description:**

Global alpha value 

## mirrorType<a name="a16e6d186004487eda4d78c5f8295cd64"></a>

```
[MirrorType](display.md#ga08d32376574b541d162d8534adb78fd0) GfxOpt::mirrorType
```

 **Description:**

Mirror type 

## ropType<a name="a171646d484843b2cc5c92cec8742766f"></a>

```
[RopType](display.md#ga24265f7618fbdba53d3da4806d3097c4) GfxOpt::ropType
```

 **Description:**

ROP type 

## rotateType<a name="a3cf19bc3feeb0d286f526133cc0e027e"></a>

```
[TransformType](display.md#gaa65f3b21a9a92ff022e435a7304126d2) GfxOpt::rotateType
```

 **Description:**

Rotation type 

