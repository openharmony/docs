# OHOS::UIBoxProgress<a name="ZH-CN_TOPIC_0000001055198152"></a>

-   [Overview](#section378130425165634)
-   [Summary](#section719337315165634)
-   [Public Types](#pub-types)
-   [Public Member Functions](#pub-methods)

## **Overview**<a name="section378130425165634"></a>

**Related Modules:**

[Graphic](Graphic.md)

**Description:**

Represents a linear progress bar. 

This class is used to set the range and current value to display the linear progress bar which can be in multiple directions.

See also
:   [UIAbstractProgress](OHOS-UIAbstractProgress.md) 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section719337315165634"></a>

## Public Types<a name="pub-types"></a>

<a name="table377810911165634"></a>
<table><thead align="left"><tr id="row1395293928165634"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p665177132165634"><a name="p665177132165634"></a><a name="p665177132165634"></a>Public Type Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p105405434165634"><a name="p105405434165634"></a><a name="p105405434165634"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1620291514165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p50235465165634"><a name="p50235465165634"></a><a name="p50235465165634"></a><a href="Graphic.md#ga4a7a2c192206c8b18379f42a5fd176eb">Direction</a> : uint8_t { <a href="Graphic.md#gga4a7a2c192206c8b18379f42a5fd176eba43cb7d46f0e18f315d43b82024093b51">Direction::DIR_LEFT_TO_RIGHT</a>, <a href="Graphic.md#gga4a7a2c192206c8b18379f42a5fd176eba49e31df5a7fc02ee8c2f85b5e15f0145">Direction::DIR_RIGHT_TO_LEFT</a>, <a href="Graphic.md#gga4a7a2c192206c8b18379f42a5fd176eba68baeaa89ae4576fc3d9ac732f87a116">Direction::DIR_TOP_TO_BOTTOM</a>, <a href="Graphic.md#gga4a7a2c192206c8b18379f42a5fd176eba78b28982b481790c740bc9b2c1292baa">Direction::DIR_BOTTOM_TO_TOP</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1080450237165634"><a name="p1080450237165634"></a><a name="p1080450237165634"></a>Enumerates the directions of the progress bar. </p>
</td>
</tr>
</tbody>
</table>

## Public Member Functions<a name="pub-methods"></a>

<a name="table61047254165634"></a>
<table><thead align="left"><tr id="row847161660165634"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p685209470165634"><a name="p685209470165634"></a><a name="p685209470165634"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2075993219165634"><a name="p2075993219165634"></a><a name="p2075993219165634"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row741305406165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1075327333165634"><a name="p1075327333165634"></a><a name="p1075327333165634"></a><a href="Graphic.md#ga315a532a3e0aa658a64d2f7739483f35">UIBoxProgress</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p564945465165634"><a name="p564945465165634"></a><a name="p564945465165634"></a> </p>
<p id="p1551659869165634"><a name="p1551659869165634"></a><a name="p1551659869165634"></a>A constructor used to create a <strong id="b1634462976165634"><a name="b1634462976165634"></a><a name="b1634462976165634"></a><a href="OHOS-UIBoxProgress.md">UIBoxProgress</a></strong> instance. </p>
</td>
</tr>
<tr id="row622654916165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1367320767165634"><a name="p1367320767165634"></a><a name="p1367320767165634"></a><a href="Graphic.md#ga7a5eefc7d4ad253a286444e76146af7f">~UIBoxProgress</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1359453506165634"><a name="p1359453506165634"></a><a name="p1359453506165634"></a>virtual </p>
<p id="p204521453165634"><a name="p204521453165634"></a><a name="p204521453165634"></a>A destructor used to delete the <strong id="b1575844379165634"><a name="b1575844379165634"></a><a name="b1575844379165634"></a><a href="OHOS-UIBoxProgress.md">UIBoxProgress</a></strong> instance. </p>
</td>
</tr>
<tr id="row476668036165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p632042301165634"><a name="p632042301165634"></a><a name="p632042301165634"></a><a href="Graphic.md#gaa2d380d48776748583f51297715af0b5">GetViewType</a> () const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p387291311165634"><a name="p387291311165634"></a><a name="p387291311165634"></a>UIViewType </p>
<p id="p1019137898165634"><a name="p1019137898165634"></a><a name="p1019137898165634"></a>Obtains the view type. </p>
</td>
</tr>
<tr id="row2116983786165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p482964582165634"><a name="p482964582165634"></a><a name="p482964582165634"></a><a href="Graphic.md#ga4b3eeb9de2443182480a71cadb23178c">SetWidth</a> (int16_t width) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1566550581165634"><a name="p1566550581165634"></a><a name="p1566550581165634"></a>void </p>
<p id="p580429152165634"><a name="p580429152165634"></a><a name="p580429152165634"></a>Sets the width for the view holding this progress bar. </p>
</td>
</tr>
<tr id="row66158818165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1519406530165634"><a name="p1519406530165634"></a><a name="p1519406530165634"></a><a href="Graphic.md#ga54299cb7561cee9a03d0fc9d0ddda784">SetHeight</a> (int16_t height) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1634704649165634"><a name="p1634704649165634"></a><a name="p1634704649165634"></a>void </p>
<p id="p178060457165634"><a name="p178060457165634"></a><a name="p178060457165634"></a>Sets the height for this view. </p>
</td>
</tr>
<tr id="row2036802507165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1642448935165634"><a name="p1642448935165634"></a><a name="p1642448935165634"></a><a href="Graphic.md#ga3e2e7d0c37b4945a3f4f456c20cb0177">SetDirection</a> (const <a href="Graphic.md#ga4a7a2c192206c8b18379f42a5fd176eb">Direction</a> &amp;direction)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1834545356165634"><a name="p1834545356165634"></a><a name="p1834545356165634"></a>void </p>
<p id="p881444351165634"><a name="p881444351165634"></a><a name="p881444351165634"></a>Sets the direction for this progress bar. </p>
</td>
</tr>
<tr id="row1104476953165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1651124616165634"><a name="p1651124616165634"></a><a name="p1651124616165634"></a><a href="Graphic.md#ga493699e8d0e934d7fb3d5502529a1c5e">GetDirection</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1399809197165634"><a name="p1399809197165634"></a><a name="p1399809197165634"></a><a href="Graphic.md#ga4a7a2c192206c8b18379f42a5fd176eb">Direction</a> </p>
<p id="p1920326017165634"><a name="p1920326017165634"></a><a name="p1920326017165634"></a>Obtains the direction of this progress bar. </p>
</td>
</tr>
<tr id="row748580511165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p371829491165634"><a name="p371829491165634"></a><a name="p371829491165634"></a><a href="Graphic.md#gada3cf1819e826ee0aed4a40ef00b91a6">SetValidWidth</a> (int16_t width)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2122269877165634"><a name="p2122269877165634"></a><a name="p2122269877165634"></a>void </p>
<p id="p721216655165634"><a name="p721216655165634"></a><a name="p721216655165634"></a>Sets the actual width for this progress bar. </p>
</td>
</tr>
<tr id="row1506494273165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p427888361165634"><a name="p427888361165634"></a><a name="p427888361165634"></a><a href="Graphic.md#ga6577d38d85234e08f709dd0ae131b255">GetValidWidth</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2142916132165634"><a name="p2142916132165634"></a><a name="p2142916132165634"></a>int16_t </p>
<p id="p24313358165634"><a name="p24313358165634"></a><a name="p24313358165634"></a>Obtains the actual width of this progress bar. </p>
</td>
</tr>
<tr id="row403623488165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1353823666165634"><a name="p1353823666165634"></a><a name="p1353823666165634"></a><a href="Graphic.md#ga6958b8273ad7a5563dfa19267cc3a13c">SetValidHeight</a> (int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1331509835165634"><a name="p1331509835165634"></a><a name="p1331509835165634"></a>void </p>
<p id="p703446966165634"><a name="p703446966165634"></a><a name="p703446966165634"></a>Sets the actual height for this progress bar. </p>
</td>
</tr>
<tr id="row2002272002165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1777221024165634"><a name="p1777221024165634"></a><a name="p1777221024165634"></a><a href="Graphic.md#ga1e6c92b20c4931a058c0b7775bf180c9">GetValidHeight</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1430830009165634"><a name="p1430830009165634"></a><a name="p1430830009165634"></a>int16_t </p>
<p id="p1930841510165634"><a name="p1930841510165634"></a><a name="p1930841510165634"></a>Obtains the actual height of this progress bar. </p>
</td>
</tr>
<tr id="row939189622165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2035837572165634"><a name="p2035837572165634"></a><a name="p2035837572165634"></a><a href="Graphic.md#ga3321d9b9b156423bdc0abcb8e99efb0d">OnDraw</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1862459370165634"><a name="p1862459370165634"></a><a name="p1862459370165634"></a>void </p>
<p id="p1857452778165634"><a name="p1857452778165634"></a><a name="p1857452778165634"></a>Called when a view is drawn. </p>
</td>
</tr>
<tr id="row1329810039165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p308188283165634"><a name="p308188283165634"></a><a name="p308188283165634"></a><a href="Graphic.md#ga8f9bfb4f42ee0e094501ff776e3336da">UIAbstractProgress</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1753507737165634"><a name="p1753507737165634"></a><a name="p1753507737165634"></a> </p>
<p id="p2015663323165634"><a name="p2015663323165634"></a><a name="p2015663323165634"></a>A constructor used to create a <strong id="b2110420368165634"><a name="b2110420368165634"></a><a name="b2110420368165634"></a><a href="OHOS-UIAbstractProgress.md">UIAbstractProgress</a></strong> instance. </p>
</td>
</tr>
<tr id="row1969941943165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1603323923165634"><a name="p1603323923165634"></a><a name="p1603323923165634"></a><a href="Graphic.md#ga5c1cf7239bf0c0f7d331e63df805b518">~UIAbstractProgress</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p400656165165634"><a name="p400656165165634"></a><a name="p400656165165634"></a>virtual </p>
<p id="p835940583165634"><a name="p835940583165634"></a><a name="p835940583165634"></a>A destructor used to delete the <strong id="b1044674401165634"><a name="b1044674401165634"></a><a name="b1044674401165634"></a><a href="OHOS-UIAbstractProgress.md">UIAbstractProgress</a></strong> instance. </p>
</td>
</tr>
<tr id="row1644136427165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1005940747165634"><a name="p1005940747165634"></a><a name="p1005940747165634"></a><a href="Graphic.md#gacb680c1ddc9135371676df504dc6c8f2">EnableBackground</a> (bool enable)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p593830912165634"><a name="p593830912165634"></a><a name="p593830912165634"></a>void </p>
<p id="p1769037141165634"><a name="p1769037141165634"></a><a name="p1769037141165634"></a>Sets whether the background of the progress bar is visible. </p>
</td>
</tr>
<tr id="row904101001165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p18931387165634"><a name="p18931387165634"></a><a name="p18931387165634"></a><a href="Graphic.md#ga5f65014431a6489ffa1d4949f9c4449b">SetValue</a> (int16_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p99045073165634"><a name="p99045073165634"></a><a name="p99045073165634"></a>void </p>
<p id="p1249002025165634"><a name="p1249002025165634"></a><a name="p1249002025165634"></a>Sets the current value for this progress bar. </p>
</td>
</tr>
<tr id="row432891501165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p669269000165634"><a name="p669269000165634"></a><a name="p669269000165634"></a><a href="Graphic.md#ga6face76aa7972efeb6cbb8f525f23135">GetValue</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1513088711165634"><a name="p1513088711165634"></a><a name="p1513088711165634"></a>int16_t </p>
<p id="p968006223165634"><a name="p968006223165634"></a><a name="p968006223165634"></a>Obtains the current value of this progress bar. </p>
</td>
</tr>
<tr id="row1276307551165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p856954958165634"><a name="p856954958165634"></a><a name="p856954958165634"></a><a href="Graphic.md#ga089e3875453011499ad33ed89a44a699">SetRange</a> (int16_t rangeMax, int16_t rangeMin)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p383843360165634"><a name="p383843360165634"></a><a name="p383843360165634"></a>void </p>
<p id="p1381626606165634"><a name="p1381626606165634"></a><a name="p1381626606165634"></a>Sets the range for this progress bar. </p>
</td>
</tr>
<tr id="row522620613165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1191182030165634"><a name="p1191182030165634"></a><a name="p1191182030165634"></a><a href="Graphic.md#ga68ab733afcf4224a799ccad2092d1d23">GetRangeMin</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p983315536165634"><a name="p983315536165634"></a><a name="p983315536165634"></a>int16_t </p>
<p id="p1742172401165634"><a name="p1742172401165634"></a><a name="p1742172401165634"></a>Obtains the minimum value of this progress bar. </p>
</td>
</tr>
<tr id="row1158567634165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p760070694165634"><a name="p760070694165634"></a><a name="p760070694165634"></a><a href="Graphic.md#ga1840199f22d5d3e4ef58e41ac8f4febc">GetRangeMax</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1083131221165634"><a name="p1083131221165634"></a><a name="p1083131221165634"></a>int16_t </p>
<p id="p1661406666165634"><a name="p1661406666165634"></a><a name="p1661406666165634"></a>Obtains the maximum value of this progress bar. </p>
</td>
</tr>
<tr id="row723812038165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1008919838165634"><a name="p1008919838165634"></a><a name="p1008919838165634"></a><a href="Graphic.md#ga5b3ec363e391f601e12bf937b9cf77db">SetImage</a> (const char *foregroundImage, const char *backgroundImage=nullptr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1580227453165634"><a name="p1580227453165634"></a><a name="p1580227453165634"></a>void </p>
<p id="p1821631929165634"><a name="p1821631929165634"></a><a name="p1821631929165634"></a>Sets the image for this progress bar. </p>
</td>
</tr>
<tr id="row366275766165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p683277644165634"><a name="p683277644165634"></a><a name="p683277644165634"></a><a href="Graphic.md#ga10723293ab9e384907dd9dacbc9ad448">SetImage</a> (const <a href="OHOS-ImageInfo.md">ImageInfo</a> *foregroundImage, const <a href="OHOS-ImageInfo.md">ImageInfo</a> *backgroundImage=nullptr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p181537685165634"><a name="p181537685165634"></a><a name="p181537685165634"></a>void </p>
<p id="p1499446070165634"><a name="p1499446070165634"></a><a name="p1499446070165634"></a>Sets the image as a pixel map for this progress bar. </p>
</td>
</tr>
<tr id="row32630199165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1661453866165634"><a name="p1661453866165634"></a><a name="p1661453866165634"></a><a href="Graphic.md#ga747a29652b441a06d09a97a297aae9bb">SetStep</a> (uint16_t step)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2095509242165634"><a name="p2095509242165634"></a><a name="p2095509242165634"></a>void </p>
<p id="p783453161165634"><a name="p783453161165634"></a><a name="p783453161165634"></a>Sets the step for this progress bar. </p>
</td>
</tr>
<tr id="row972452131165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1340724335165634"><a name="p1340724335165634"></a><a name="p1340724335165634"></a><a href="Graphic.md#ga9c1678604605a54c2e338d283c46866d">GetStep</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p754478044165634"><a name="p754478044165634"></a><a name="p754478044165634"></a>uint16_t </p>
<p id="p1904456079165634"><a name="p1904456079165634"></a><a name="p1904456079165634"></a>Obtains the current step of this progress bar. </p>
</td>
</tr>
<tr id="row1106671355165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p548823887165634"><a name="p548823887165634"></a><a name="p548823887165634"></a><a href="Graphic.md#ga6817b5178e93e5f16f2b420cf5a171c1">SetBackgroundStyle</a> (const <a href="OHOS-Style.md">Style</a> &amp;style)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p193047347165634"><a name="p193047347165634"></a><a name="p193047347165634"></a>void </p>
<p id="p1799098646165634"><a name="p1799098646165634"></a><a name="p1799098646165634"></a>Sets the background style for this progress bar. </p>
</td>
</tr>
<tr id="row492784401165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1850159546165634"><a name="p1850159546165634"></a><a name="p1850159546165634"></a><a href="Graphic.md#ga23acea0a42587746e35ec5f3a74af59f">SetBackgroundStyle</a> (uint8_t key, int64_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1219038801165634"><a name="p1219038801165634"></a><a name="p1219038801165634"></a>void </p>
<p id="p543900411165634"><a name="p543900411165634"></a><a name="p543900411165634"></a>Sets a background style for this progress bar. </p>
</td>
</tr>
<tr id="row862561042165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1119586029165634"><a name="p1119586029165634"></a><a name="p1119586029165634"></a><a href="Graphic.md#gac2ca1212c23c11405b12ae0a46c7eff1">GetBackgroundStyle</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1998781780165634"><a name="p1998781780165634"></a><a name="p1998781780165634"></a>const <a href="OHOS-Style.md">Style</a> &amp; </p>
<p id="p1493629180165634"><a name="p1493629180165634"></a><a name="p1493629180165634"></a>Obtains the background style of this progress bar. </p>
</td>
</tr>
<tr id="row70989251165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p912952097165634"><a name="p912952097165634"></a><a name="p912952097165634"></a><a href="Graphic.md#ga946d3f2c39a79d45149118536b2557a9">GetBackgroundStyle</a> (uint8_t key) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p234126192165634"><a name="p234126192165634"></a><a name="p234126192165634"></a>int64_t </p>
<p id="p842415236165634"><a name="p842415236165634"></a><a name="p842415236165634"></a>Obtains the value of a background style of this progress bar. </p>
</td>
</tr>
<tr id="row517622241165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1818282239165634"><a name="p1818282239165634"></a><a name="p1818282239165634"></a><a href="Graphic.md#gaccebcfa35f98f9bc6be4bb8cc53eb11c">SetForegroundStyle</a> (const <a href="OHOS-Style.md">Style</a> &amp;style)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p132562693165634"><a name="p132562693165634"></a><a name="p132562693165634"></a>void </p>
<p id="p819371965165634"><a name="p819371965165634"></a><a name="p819371965165634"></a>Sets the foreground style for this progress bar. </p>
</td>
</tr>
<tr id="row347408601165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p415508692165634"><a name="p415508692165634"></a><a name="p415508692165634"></a><a href="Graphic.md#gae6386ca25603e42f06087f6b2ef65bae">SetForegroundStyle</a> (uint8_t key, int64_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p403758804165634"><a name="p403758804165634"></a><a name="p403758804165634"></a>void </p>
<p id="p1590680402165634"><a name="p1590680402165634"></a><a name="p1590680402165634"></a>Sets a foreground style for this progress bar. </p>
</td>
</tr>
<tr id="row174478783165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p659064239165634"><a name="p659064239165634"></a><a name="p659064239165634"></a><a href="Graphic.md#gac77f945f375f333f80bd70254b5c1f96">GetForegroundStyle</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1918600192165634"><a name="p1918600192165634"></a><a name="p1918600192165634"></a>const <a href="OHOS-Style.md">Style</a> &amp; </p>
<p id="p465245448165634"><a name="p465245448165634"></a><a name="p465245448165634"></a>Obtains the foreground style of this progress bar. </p>
</td>
</tr>
<tr id="row373221594165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1114652376165634"><a name="p1114652376165634"></a><a name="p1114652376165634"></a><a href="Graphic.md#ga74cd121dd1794d7e8d905b233bd98217">GetForegroundStyle</a> (uint8_t key) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1560321319165634"><a name="p1560321319165634"></a><a name="p1560321319165634"></a>int64_t </p>
<p id="p1738511157165634"><a name="p1738511157165634"></a><a name="p1738511157165634"></a>Obtains the value of a foreground style of this progress bar. </p>
</td>
</tr>
<tr id="row932103090165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1229451791165634"><a name="p1229451791165634"></a><a name="p1229451791165634"></a><a href="Graphic.md#gabdc0eb4d279212ea7c3ea7a1f9a85e13">SetCapType</a> (<a href="Graphic.md#ga2db3928cdf793f4950245a6841dd43d6">CapType</a> cap)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1267063907165634"><a name="p1267063907165634"></a><a name="p1267063907165634"></a>void </p>
<p id="p2043336422165634"><a name="p2043336422165634"></a><a name="p2043336422165634"></a>Sets the type of caps on the background and foreground of the progress bar. </p>
</td>
</tr>
<tr id="row1345025472165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1407708927165634"><a name="p1407708927165634"></a><a name="p1407708927165634"></a><a href="Graphic.md#ga7aad5b50d945efe5f9304bc978b2001c">UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p611029242165634"><a name="p611029242165634"></a><a name="p611029242165634"></a> </p>
<p id="p2030699758165634"><a name="p2030699758165634"></a><a name="p2030699758165634"></a>A default constructor used to create an <strong id="b470655494165634"><a name="b470655494165634"></a><a name="b470655494165634"></a><a href="OHOS-UIView.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row936209701165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1020128883165634"><a name="p1020128883165634"></a><a name="p1020128883165634"></a><a href="Graphic.md#ga57d429bb1cd71782f3b825f1bc6b9362">UIView</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1296004522165634"><a name="p1296004522165634"></a><a name="p1296004522165634"></a> </p>
<p id="p555076735165634"><a name="p555076735165634"></a><a name="p555076735165634"></a>A constructor used to create an <strong id="b515141591165634"><a name="b515141591165634"></a><a name="b515141591165634"></a><a href="OHOS-UIView.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row2080910613165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p969342490165634"><a name="p969342490165634"></a><a name="p969342490165634"></a><a href="Graphic.md#ga17f0ffc1090bdcce0f88288da5962012">~UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1546125924165634"><a name="p1546125924165634"></a><a name="p1546125924165634"></a>virtual </p>
<p id="p7227234165634"><a name="p7227234165634"></a><a name="p7227234165634"></a>A destructor used to delete the <strong id="b1559456223165634"><a name="b1559456223165634"></a><a name="b1559456223165634"></a><a href="OHOS-UIView.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row170500052165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1082775690165634"><a name="p1082775690165634"></a><a name="p1082775690165634"></a><a href="Graphic.md#gac295fe4851eed72f48e9a63771416d71">OnPreDraw</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2114525534165634"><a name="p2114525534165634"></a><a name="p2114525534165634"></a>virtual bool </p>
<p id="p524516071165634"><a name="p524516071165634"></a><a name="p524516071165634"></a>Called before a view is drawn. This function is used to check whether the parent view of this view needs to be redrawn so as to optimize the drawing process. </p>
</td>
</tr>
<tr id="row1791981221165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p963580634165634"><a name="p963580634165634"></a><a name="p963580634165634"></a><a href="Graphic.md#gab70473cd0d8fe7c9d4bb817caeee9153">OnPostDraw</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1327730763165634"><a name="p1327730763165634"></a><a name="p1327730763165634"></a>virtual void </p>
<p id="p630982758165634"><a name="p630982758165634"></a><a name="p630982758165634"></a>Called after a view is drawn. </p>
</td>
</tr>
<tr id="row436054061165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2095841234165634"><a name="p2095841234165634"></a><a name="p2095841234165634"></a><a href="Graphic.md#ga81726238adeda1efa989be6ed4f4fe5b">ReMeasure</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1517803674165634"><a name="p1517803674165634"></a><a name="p1517803674165634"></a>virtual void </p>
<p id="p129427558165634"><a name="p129427558165634"></a><a name="p129427558165634"></a>Remeasures the view size. </p>
</td>
</tr>
<tr id="row1840108199165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1734826864165634"><a name="p1734826864165634"></a><a name="p1734826864165634"></a><a href="Graphic.md#ga2a9a38b8450fbb196277238a51fbbf99">Invalidate</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p553065358165634"><a name="p553065358165634"></a><a name="p553065358165634"></a>void </p>
<p id="p1540202979165634"><a name="p1540202979165634"></a><a name="p1540202979165634"></a>Refreshes the invalidated area of the view. </p>
</td>
</tr>
<tr id="row877709053165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1704889722165634"><a name="p1704889722165634"></a><a name="p1704889722165634"></a><a href="Graphic.md#gaf0e6b65ced8b931642f2a80c195962d2">InvalidateRect</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p599421442165634"><a name="p599421442165634"></a><a name="p599421442165634"></a>void </p>
<p id="p1921400395165634"><a name="p1921400395165634"></a><a name="p1921400395165634"></a>Refreshes a view in a specified invalidated area. </p>
</td>
</tr>
<tr id="row1835927198165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2062673223165634"><a name="p2062673223165634"></a><a name="p2062673223165634"></a><a href="Graphic.md#gac311aa47301d727c35fc31f8630d016e">OnLongPressEvent</a> (const <a href="OHOS-LongPressEvent.md">LongPressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1051389660165634"><a name="p1051389660165634"></a><a name="p1051389660165634"></a>virtual bool </p>
<p id="p1983094987165634"><a name="p1983094987165634"></a><a name="p1983094987165634"></a>Called when the view is long pressed. </p>
</td>
</tr>
<tr id="row889109505165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1616289835165634"><a name="p1616289835165634"></a><a name="p1616289835165634"></a><a href="Graphic.md#gac0e10556ff99b8a92bfb11df6456d605">OnDragStartEvent</a> (const <a href="OHOS-DragEvent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1853175828165634"><a name="p1853175828165634"></a><a name="p1853175828165634"></a>virtual bool </p>
<p id="p774731944165634"><a name="p774731944165634"></a><a name="p774731944165634"></a>Called when the view starts to drag. </p>
</td>
</tr>
<tr id="row484630983165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p968591998165634"><a name="p968591998165634"></a><a name="p968591998165634"></a><a href="Graphic.md#ga46249c8caf06b81590d9450e30a31147">OnDragEvent</a> (const <a href="OHOS-DragEvent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1400287008165634"><a name="p1400287008165634"></a><a name="p1400287008165634"></a>virtual bool </p>
<p id="p1271749537165634"><a name="p1271749537165634"></a><a name="p1271749537165634"></a>Called when the view is being dragged. </p>
</td>
</tr>
<tr id="row1376128069165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p545110359165634"><a name="p545110359165634"></a><a name="p545110359165634"></a><a href="Graphic.md#ga1799d33be73f64ed2066f50d7e65468d">OnDragEndEvent</a> (const <a href="OHOS-DragEvent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1063977822165634"><a name="p1063977822165634"></a><a name="p1063977822165634"></a>virtual bool </p>
<p id="p380257681165634"><a name="p380257681165634"></a><a name="p380257681165634"></a>Called when the view stops dragging. </p>
</td>
</tr>
<tr id="row163397175165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p12450086165634"><a name="p12450086165634"></a><a name="p12450086165634"></a><a href="Graphic.md#gad08697a29aae4c58267f494b66b9a547">OnClickEvent</a> (const <a href="OHOS-ClickEvent.md">ClickEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1359692868165634"><a name="p1359692868165634"></a><a name="p1359692868165634"></a>virtual void </p>
<p id="p2112340873165634"><a name="p2112340873165634"></a><a name="p2112340873165634"></a>Called when the view is clicked. </p>
</td>
</tr>
<tr id="row521772622165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1039426899165634"><a name="p1039426899165634"></a><a name="p1039426899165634"></a><a href="Graphic.md#gafa544ff2d27785a9410a80689f1ad3b1">OnPressEvent</a> (const <a href="OHOS-PressEvent.md">PressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p796786715165634"><a name="p796786715165634"></a><a name="p796786715165634"></a>virtual void </p>
<p id="p965314460165634"><a name="p965314460165634"></a><a name="p965314460165634"></a>Called when the view is pressed. </p>
</td>
</tr>
<tr id="row5689659165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1327707979165634"><a name="p1327707979165634"></a><a name="p1327707979165634"></a><a href="Graphic.md#ga7bd1a74563b059b03fbf66f9add53ee3">OnReleaseEvent</a> (const <a href="OHOS-ReleaseEvent.md">ReleaseEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p702320669165634"><a name="p702320669165634"></a><a name="p702320669165634"></a>virtual void </p>
<p id="p1774855337165634"><a name="p1774855337165634"></a><a name="p1774855337165634"></a>Called when the view is released. </p>
</td>
</tr>
<tr id="row1017084785165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1732533323165634"><a name="p1732533323165634"></a><a name="p1732533323165634"></a><a href="Graphic.md#ga8f01ff25a33b20df0758f564148e579d">OnCancelEvent</a> (const <a href="OHOS-CancelEvent.md">CancelEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p10580257165634"><a name="p10580257165634"></a><a name="p10580257165634"></a>virtual void </p>
<p id="p537862593165634"><a name="p537862593165634"></a><a name="p537862593165634"></a>Called when a click event on the view is canceled. </p>
</td>
</tr>
<tr id="row1940485091165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p687561507165634"><a name="p687561507165634"></a><a name="p687561507165634"></a><a href="Graphic.md#gad8e3cf5f0dd003a6aa932ef04e7b59f2">SetOnDragListener</a> (<a href="OHOS-UIView-OnDragListener.md">OnDragListener</a> *onDragListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p438111148165634"><a name="p438111148165634"></a><a name="p438111148165634"></a>void </p>
<p id="p2110207722165634"><a name="p2110207722165634"></a><a name="p2110207722165634"></a>Sets a drag event listener for the view. </p>
</td>
</tr>
<tr id="row460929948165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1225660936165634"><a name="p1225660936165634"></a><a name="p1225660936165634"></a><a href="Graphic.md#ga45a02cba4887c5c0b8e243941bcdc5cb">GetOnDragListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1332340815165634"><a name="p1332340815165634"></a><a name="p1332340815165634"></a><a href="OHOS-UIView-OnDragListener.md">OnDragListener</a> *&amp; </p>
<p id="p1999929827165634"><a name="p1999929827165634"></a><a name="p1999929827165634"></a>Obtains the drag event listener for the view. </p>
</td>
</tr>
<tr id="row708720567165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1528338645165634"><a name="p1528338645165634"></a><a name="p1528338645165634"></a><a href="Graphic.md#ga4564bf8d8c7184e9c02bf33c9e171fa3">SetOnClickListener</a> (<a href="OHOS-UIView-OnClickListener.md">OnClickListener</a> *onClickListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1468096071165634"><a name="p1468096071165634"></a><a name="p1468096071165634"></a>void </p>
<p id="p1157393032165634"><a name="p1157393032165634"></a><a name="p1157393032165634"></a>Sets a click event listener for the view. </p>
</td>
</tr>
<tr id="row1583535550165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1648599917165634"><a name="p1648599917165634"></a><a name="p1648599917165634"></a><a href="Graphic.md#ga35e885cb380c37245fa4305bba10cd4a">GetOnClickListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2135504298165634"><a name="p2135504298165634"></a><a name="p2135504298165634"></a><a href="OHOS-UIView-OnClickListener.md">OnClickListener</a> *&amp; </p>
<p id="p207816040165634"><a name="p207816040165634"></a><a name="p207816040165634"></a>Obtains the click event listener for the view. </p>
</td>
</tr>
<tr id="row784156510165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1924758555165634"><a name="p1924758555165634"></a><a name="p1924758555165634"></a><a href="Graphic.md#gabcbe7a0adce600424f7f0d5a7396eb5b">SetOnLongPressListener</a> (<a href="OHOS-UIView-OnLongPressListener.md">OnLongPressListener</a> *onLongPressListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p960916172165634"><a name="p960916172165634"></a><a name="p960916172165634"></a>void </p>
<p id="p1321971844165634"><a name="p1321971844165634"></a><a name="p1321971844165634"></a>Sets a long-press event listener for the view. </p>
</td>
</tr>
<tr id="row1759792148165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1727447258165634"><a name="p1727447258165634"></a><a name="p1727447258165634"></a><a href="Graphic.md#gaafd4d354f5f111e758d046109fd7f656">GetOnLongPressListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1574950609165634"><a name="p1574950609165634"></a><a name="p1574950609165634"></a><a href="OHOS-UIView-OnLongPressListener.md">OnLongPressListener</a> *&amp; </p>
<p id="p147826795165634"><a name="p147826795165634"></a><a name="p147826795165634"></a>Obtains the long-press event listener for the view. </p>
</td>
</tr>
<tr id="row2062300831165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p127215000165634"><a name="p127215000165634"></a><a name="p127215000165634"></a><a href="Graphic.md#gadd697fbf481f98d9d6ca8b67390071af">SetOnTouchListener</a> (<a href="OHOS-UIView-OnTouchListener.md">OnTouchListener</a> *onTouchListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2115413870165634"><a name="p2115413870165634"></a><a name="p2115413870165634"></a>void </p>
<p id="p2020626898165634"><a name="p2020626898165634"></a><a name="p2020626898165634"></a>Sets a touch event listener for the view. </p>
</td>
</tr>
<tr id="row1048433555165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1974115413165634"><a name="p1974115413165634"></a><a name="p1974115413165634"></a><a href="Graphic.md#gae7c65c68653103dae85acdcef78777a6">GetTouchListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p27167969165634"><a name="p27167969165634"></a><a name="p27167969165634"></a><a href="OHOS-UIView-OnTouchListener.md">OnTouchListener</a> *&amp; </p>
<p id="p1463473045165634"><a name="p1463473045165634"></a><a name="p1463473045165634"></a>Obtains the touch event listener for the view. </p>
</td>
</tr>
<tr id="row1101972677165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2088383838165634"><a name="p2088383838165634"></a><a name="p2088383838165634"></a><a href="Graphic.md#gaea9f334f2481e1c03a2cd8f3078d7c72">GetTargetView</a> (const <a href="OHOS-Point.md">Point</a> &amp;point, <a href="OHOS-UIView.md">UIView</a> **last)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1634752414165634"><a name="p1634752414165634"></a><a name="p1634752414165634"></a>virtual void </p>
<p id="p378247484165634"><a name="p378247484165634"></a><a name="p378247484165634"></a>Obtains the top-level view based on specified coordinates. </p>
</td>
</tr>
<tr id="row815522927165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1514626907165634"><a name="p1514626907165634"></a><a name="p1514626907165634"></a><a href="Graphic.md#gaeea67a3a84b4ffe9bfeda418b82184cc">SetParent</a> (<a href="OHOS-UIView.md">UIView</a> *parent)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p378778005165634"><a name="p378778005165634"></a><a name="p378778005165634"></a>void </p>
<p id="p619699050165634"><a name="p619699050165634"></a><a name="p619699050165634"></a>Sets the parent view for the view. </p>
</td>
</tr>
<tr id="row997161605165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1041972499165634"><a name="p1041972499165634"></a><a name="p1041972499165634"></a><a href="Graphic.md#ga706530e4a38108615d5e0c918685ec96">GetParent</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p829830197165634"><a name="p829830197165634"></a><a name="p829830197165634"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p1617679881165634"><a name="p1617679881165634"></a><a name="p1617679881165634"></a>Obtains the parent view of the view. </p>
</td>
</tr>
<tr id="row1409277551165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1764692832165634"><a name="p1764692832165634"></a><a name="p1764692832165634"></a><a href="Graphic.md#ga02bec5de07d93cabc45affba79eba4ad">SetNextSibling</a> (<a href="OHOS-UIView.md">UIView</a> *sibling)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1951334001165634"><a name="p1951334001165634"></a><a name="p1951334001165634"></a>void </p>
<p id="p1786301454165634"><a name="p1786301454165634"></a><a name="p1786301454165634"></a>Sets the next sibling view for the view. </p>
</td>
</tr>
<tr id="row297093978165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1758107907165634"><a name="p1758107907165634"></a><a name="p1758107907165634"></a><a href="Graphic.md#gab0030977b30ddc9f2e15dbc2f58937e6">GetNextSibling</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1295951128165634"><a name="p1295951128165634"></a><a name="p1295951128165634"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p2092430886165634"><a name="p2092430886165634"></a><a name="p2092430886165634"></a>Obtains the next sibling view of the view. </p>
</td>
</tr>
<tr id="row2140152312165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p875219474165634"><a name="p875219474165634"></a><a name="p875219474165634"></a><a href="Graphic.md#ga07e7e1f268bd6ce975f4f0f8487af5d0">SetVisible</a> (bool visible)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p776690433165634"><a name="p776690433165634"></a><a name="p776690433165634"></a>virtual void </p>
<p id="p541970104165634"><a name="p541970104165634"></a><a name="p541970104165634"></a>Sets whether the view is visible. </p>
</td>
</tr>
<tr id="row481658140165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p558129558165634"><a name="p558129558165634"></a><a name="p558129558165634"></a><a href="Graphic.md#gaee178fc0a86ac03a6bdf2ade0c1914c8">IsVisible</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1002286019165634"><a name="p1002286019165634"></a><a name="p1002286019165634"></a>bool </p>
<p id="p177194476165634"><a name="p177194476165634"></a><a name="p177194476165634"></a>Checks whether the view is visible. </p>
</td>
</tr>
<tr id="row1263481698165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p647091147165634"><a name="p647091147165634"></a><a name="p647091147165634"></a><a href="Graphic.md#gaf9fb55fd9aa397f7158f1515e90bce02">SetTouchable</a> (bool touch)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1735794255165634"><a name="p1735794255165634"></a><a name="p1735794255165634"></a>void </p>
<p id="p1720232090165634"><a name="p1720232090165634"></a><a name="p1720232090165634"></a>Sets whether the view is touchable. </p>
</td>
</tr>
<tr id="row1223381695165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p475433000165634"><a name="p475433000165634"></a><a name="p475433000165634"></a><a href="Graphic.md#ga502a53fb77b260fa36b5b3adf82e2340">IsTouchable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p820272018165634"><a name="p820272018165634"></a><a name="p820272018165634"></a>bool </p>
<p id="p2004751907165634"><a name="p2004751907165634"></a><a name="p2004751907165634"></a>Checks whether the view is touchable. </p>
</td>
</tr>
<tr id="row982151784165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1626012029165634"><a name="p1626012029165634"></a><a name="p1626012029165634"></a><a href="Graphic.md#gab06abe0fe824c048f3b72974f9a8f0d0">SetDraggable</a> (bool draggable)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p371379018165634"><a name="p371379018165634"></a><a name="p371379018165634"></a>void </p>
<p id="p1754378916165634"><a name="p1754378916165634"></a><a name="p1754378916165634"></a>Sets whether the view is draggable. </p>
</td>
</tr>
<tr id="row174505746165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p323592591165634"><a name="p323592591165634"></a><a name="p323592591165634"></a><a href="Graphic.md#ga25bb796ff400c767d622cbed280fc500">IsDraggable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1325195565165634"><a name="p1325195565165634"></a><a name="p1325195565165634"></a>bool </p>
<p id="p1488962776165634"><a name="p1488962776165634"></a><a name="p1488962776165634"></a>Checks whether the view is draggable. </p>
</td>
</tr>
<tr id="row605598876165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1809353626165634"><a name="p1809353626165634"></a><a name="p1809353626165634"></a><a href="Graphic.md#ga6c08e49bf7a82a7ebaef0f251e7a6f85">SetDragParentInstead</a> (bool dragParentInstead)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1698495333165634"><a name="p1698495333165634"></a><a name="p1698495333165634"></a>void </p>
<p id="p2060600126165634"><a name="p2060600126165634"></a><a name="p2060600126165634"></a>Sets whether to transfer the drag event to the parent view for processing when the view is being dragged. </p>
</td>
</tr>
<tr id="row111182077165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p912649263165634"><a name="p912649263165634"></a><a name="p912649263165634"></a><a href="Graphic.md#gaf0c462bc31e779b1898ad4cdfdad6faf">IsDragParentInstead</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p144820537165634"><a name="p144820537165634"></a><a name="p144820537165634"></a>bool </p>
<p id="p1496042173165634"><a name="p1496042173165634"></a><a name="p1496042173165634"></a>Obtains whether the view transfers a drag event to the parent view for processing. </p>
</td>
</tr>
<tr id="row836635960165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p605891448165634"><a name="p605891448165634"></a><a name="p605891448165634"></a><a href="Graphic.md#ga86cb8d364f18494d67636c55babced5c">GetRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1519497595165634"><a name="p1519497595165634"></a><a name="p1519497595165634"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p765970174165634"><a name="p765970174165634"></a><a name="p765970174165634"></a>Obtains the absolute rectangle area of the view. When the view has deformation such as rotation, the rectangle area is the intersection set of the absolute rectangle area and deformation matrix. </p>
</td>
</tr>
<tr id="row668667526165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p466100287165634"><a name="p466100287165634"></a><a name="p466100287165634"></a><a href="Graphic.md#ga06e79704a19f2a238982076cac3d059b">GetVisibleRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1158163977165634"><a name="p1158163977165634"></a><a name="p1158163977165634"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p750451613165634"><a name="p750451613165634"></a><a name="p750451613165634"></a>Obtains the visible absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row820816650165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1420799141165634"><a name="p1420799141165634"></a><a name="p1420799141165634"></a><a href="Graphic.md#gab3f8993b3953f27bfc61d53429916cba">GetMaskedRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p134494946165634"><a name="p134494946165634"></a><a name="p134494946165634"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p2069910574165634"><a name="p2069910574165634"></a><a name="p2069910574165634"></a>Obtains the valid absolute rectangle area of the view. The valid area refers to the area where the view can be displayed. Generally, the valid area is the same as the visible view area, but they may be different in the grid layout. </p>
</td>
</tr>
<tr id="row908627492165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1211126624165634"><a name="p1211126624165634"></a><a name="p1211126624165634"></a><a href="Graphic.md#ga64cf308a09999def1192f9c4e0f17f0a">GetOrigRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2041693067165634"><a name="p2041693067165634"></a><a name="p2041693067165634"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p1679905487165634"><a name="p1679905487165634"></a><a name="p1679905487165634"></a>Obtains the absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row1940971384165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1441755979165634"><a name="p1441755979165634"></a><a name="p1441755979165634"></a><a href="Graphic.md#ga9db88eae712676359d02a92be14fa316">GetContentRect</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p984867098165634"><a name="p984867098165634"></a><a name="p984867098165634"></a>virtual <a href="OHOS-Rect.md">Rect</a> </p>
<p id="p1063397342165634"><a name="p1063397342165634"></a><a name="p1063397342165634"></a>Obtains the content of the absolute rectangle area of the view. This area excludes padding. </p>
</td>
</tr>
<tr id="row1482976620165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p379207265165634"><a name="p379207265165634"></a><a name="p379207265165634"></a><a href="Graphic.md#gae9b96837fa1d45648a2a6fbbfcc5eb4a">GetRelativeRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p567771345165634"><a name="p567771345165634"></a><a name="p567771345165634"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p112680676165634"><a name="p112680676165634"></a><a name="p112680676165634"></a>Obtains the rectangular area of the view relative to the parent view, that is, the rectangular area relative to the coordinates of the parent view. </p>
</td>
</tr>
<tr id="row1507520788165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p574102187165634"><a name="p574102187165634"></a><a name="p574102187165634"></a><a href="Graphic.md#gae6c5f3bcf99dc837bcecd60c38d3df5a">ResizeVisibleArea</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p691251655165634"><a name="p691251655165634"></a><a name="p691251655165634"></a>void </p>
<p id="p912774574165634"><a name="p912774574165634"></a><a name="p912774574165634"></a>Adjusts the size of the visible area. This operation may affect the final display size. </p>
</td>
</tr>
<tr id="row863490905165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p211586916165634"><a name="p211586916165634"></a><a name="p211586916165634"></a><a href="Graphic.md#ga90cf8cffb98d71c30d6fc1d118442dbd">GetWidth</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1332020000165634"><a name="p1332020000165634"></a><a name="p1332020000165634"></a>virtual int16_t </p>
<p id="p1817345447165634"><a name="p1817345447165634"></a><a name="p1817345447165634"></a>Obtains the width for the view. </p>
</td>
</tr>
<tr id="row319305247165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1776252206165634"><a name="p1776252206165634"></a><a name="p1776252206165634"></a><a href="Graphic.md#ga9b35f4603a561c7a9a29b023a022ac97">GetHeight</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1441234048165634"><a name="p1441234048165634"></a><a name="p1441234048165634"></a>virtual int16_t </p>
<p id="p1471808586165634"><a name="p1471808586165634"></a><a name="p1471808586165634"></a>Obtains the height for the view. </p>
</td>
</tr>
<tr id="row1934114002165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1783930648165634"><a name="p1783930648165634"></a><a name="p1783930648165634"></a><a href="Graphic.md#gae985b607d2f0701911778bf20d640ccd">Resize</a> (int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1579248204165634"><a name="p1579248204165634"></a><a name="p1579248204165634"></a>virtual void </p>
<p id="p561531497165634"><a name="p561531497165634"></a><a name="p561531497165634"></a>Adjusts the size of the view. </p>
</td>
</tr>
<tr id="row1214964679165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1112578459165634"><a name="p1112578459165634"></a><a name="p1112578459165634"></a><a href="Graphic.md#gaded403626558d28e62bf5632ccbb24b5">SetX</a> (int16_t x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1600105170165634"><a name="p1600105170165634"></a><a name="p1600105170165634"></a>virtual void </p>
<p id="p1862429429165634"><a name="p1862429429165634"></a><a name="p1862429429165634"></a>Sets the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row1986179213165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p568536207165634"><a name="p568536207165634"></a><a name="p568536207165634"></a><a href="Graphic.md#ga89dc5f8fb1cb4b2259dc0439185359f1">GetX</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1024652455165634"><a name="p1024652455165634"></a><a name="p1024652455165634"></a>int16_t </p>
<p id="p637581226165634"><a name="p637581226165634"></a><a name="p637581226165634"></a>Obtains the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row1277775503165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1149453608165634"><a name="p1149453608165634"></a><a name="p1149453608165634"></a><a href="Graphic.md#gaaa8edc224cf1c7deb2724fb225960877">SetY</a> (int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p463667621165634"><a name="p463667621165634"></a><a name="p463667621165634"></a>virtual void </p>
<p id="p1631810330165634"><a name="p1631810330165634"></a><a name="p1631810330165634"></a>Sets the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row1905378355165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p28797221165634"><a name="p28797221165634"></a><a name="p28797221165634"></a><a href="Graphic.md#ga193619d649204b0e9bb854d3b30275c3">GetY</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p791292845165634"><a name="p791292845165634"></a><a name="p791292845165634"></a>int16_t </p>
<p id="p881442632165634"><a name="p881442632165634"></a><a name="p881442632165634"></a>Obtains the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row2128879068165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1572128739165634"><a name="p1572128739165634"></a><a name="p1572128739165634"></a><a href="Graphic.md#gab34233f6aeae330b025969137d03e67a">SetPosition</a> (int16_t x, int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p973494492165634"><a name="p973494492165634"></a><a name="p973494492165634"></a>virtual void </p>
<p id="p1486884482165634"><a name="p1486884482165634"></a><a name="p1486884482165634"></a>Sets the position for the view. </p>
</td>
</tr>
<tr id="row1337449499165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2005354615165634"><a name="p2005354615165634"></a><a name="p2005354615165634"></a><a href="Graphic.md#gaf8ce4c009f23b7175b2b34bac4a74262">SetPosition</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2090394489165634"><a name="p2090394489165634"></a><a name="p2090394489165634"></a>virtual void </p>
<p id="p204612883165634"><a name="p204612883165634"></a><a name="p204612883165634"></a>Adjusts the position and size of the view. </p>
</td>
</tr>
<tr id="row2124875187165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1846412282165634"><a name="p1846412282165634"></a><a name="p1846412282165634"></a><a href="Graphic.md#gab2ce8c11abbd55f40687f38a52511b11">IsViewGroup</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2124255574165634"><a name="p2124255574165634"></a><a name="p2124255574165634"></a>bool </p>
<p id="p1924274007165634"><a name="p1924274007165634"></a><a name="p1924274007165634"></a>Checks whether the view is a container view. </p>
</td>
</tr>
<tr id="row1693870292165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p183421949165634"><a name="p183421949165634"></a><a name="p183421949165634"></a><a href="Graphic.md#ga980fc6824c64cfae6af8657aee17af88">SetIntercept</a> (bool isIntercept)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1946707777165634"><a name="p1946707777165634"></a><a name="p1946707777165634"></a>void </p>
<p id="p86350667165634"><a name="p86350667165634"></a><a name="p86350667165634"></a>Sets whether to intercept the drag event. If intercepted, the view does not transfer the drag event to the parent view after local processing. </p>
</td>
</tr>
<tr id="row1300643980165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p503415724165634"><a name="p503415724165634"></a><a name="p503415724165634"></a><a href="Graphic.md#ga8623abbbeff458c0cb2d7dc0d1f21e4a">SetTransformMap</a> (const <a href="OHOS-TransformMap.md">TransformMap</a> &amp;transMap)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p307152639165634"><a name="p307152639165634"></a><a name="p307152639165634"></a>void </p>
<p id="p2098200352165634"><a name="p2098200352165634"></a><a name="p2098200352165634"></a>Sets the affine transformation matrix. </p>
</td>
</tr>
<tr id="row1531779561165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1187825587165634"><a name="p1187825587165634"></a><a name="p1187825587165634"></a><a href="Graphic.md#gab8cee5a7052a88722768c8ed1324abc1">GetTransformMap</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1831455453165634"><a name="p1831455453165634"></a><a name="p1831455453165634"></a><a href="OHOS-TransformMap.md">TransformMap</a> &amp; </p>
<p id="p552632008165634"><a name="p552632008165634"></a><a name="p552632008165634"></a>Obtains an affine transformation matrix. </p>
</td>
</tr>
<tr id="row1635300106165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1142624988165634"><a name="p1142624988165634"></a><a name="p1142624988165634"></a><a href="Graphic.md#ga0573aa25307c22319db4629781b5cad2">GetChildById</a> (const char *id) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1298888966165634"><a name="p1298888966165634"></a><a name="p1298888966165634"></a>virtual <a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p1580663168165634"><a name="p1580663168165634"></a><a name="p1580663168165634"></a>Obtains the child view of a specified ID. </p>
</td>
</tr>
<tr id="row903928829165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p977500581165634"><a name="p977500581165634"></a><a name="p977500581165634"></a><a href="Graphic.md#ga0caaa15c9b304673331e778a266be77f">SetViewId</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1175895011165634"><a name="p1175895011165634"></a><a name="p1175895011165634"></a>void </p>
<p id="p1159810879165634"><a name="p1159810879165634"></a><a name="p1159810879165634"></a>Sets the view ID. </p>
</td>
</tr>
<tr id="row1863882310165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p84473861165634"><a name="p84473861165634"></a><a name="p84473861165634"></a><a href="Graphic.md#gad6c7644bd2abfa3c92d80776b0bd1936">GetViewId</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p897208741165634"><a name="p897208741165634"></a><a name="p897208741165634"></a>const char * </p>
<p id="p1540837634165634"><a name="p1540837634165634"></a><a name="p1540837634165634"></a>Obtains the view ID. </p>
</td>
</tr>
<tr id="row60756548165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p658718619165634"><a name="p658718619165634"></a><a name="p658718619165634"></a><a href="Graphic.md#ga77a961aa53567c5214508b4569801c16">SetViewIndex</a> (int16_t <a href="UTILS.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p727479786165634"><a name="p727479786165634"></a><a name="p727479786165634"></a>void </p>
<p id="p1955005053165634"><a name="p1955005053165634"></a><a name="p1955005053165634"></a>Sets the view index. </p>
</td>
</tr>
<tr id="row168768956165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p656430416165634"><a name="p656430416165634"></a><a name="p656430416165634"></a><a href="Graphic.md#ga62f51715b6d420a296ebe0296717b906">GetViewIndex</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1071831826165634"><a name="p1071831826165634"></a><a name="p1071831826165634"></a>int16_t </p>
<p id="p679344502165634"><a name="p679344502165634"></a><a name="p679344502165634"></a>Obtains the view index. </p>
</td>
</tr>
<tr id="row811961678165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p998928212165634"><a name="p998928212165634"></a><a name="p998928212165634"></a><a href="Graphic.md#gaca871fa2f8219e7ea9388e212d1f1e69">LayoutChildren</a> (bool neeInvalidate=false)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p182786810165634"><a name="p182786810165634"></a><a name="p182786810165634"></a>virtual void </p>
<p id="p186100418165634"><a name="p186100418165634"></a><a name="p186100418165634"></a>Lays out all child views according to the preset arrangement mode. </p>
</td>
</tr>
<tr id="row1231041023165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p515171970165634"><a name="p515171970165634"></a><a name="p515171970165634"></a><a href="Graphic.md#ga443b86ee9275b0421b37a47bad3264dc">LayoutCenterOfParent</a> (int16_t xOffSet=0, int16_t yOffset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p652179263165634"><a name="p652179263165634"></a><a name="p652179263165634"></a>void </p>
<p id="p841216110165634"><a name="p841216110165634"></a><a name="p841216110165634"></a>Lays out the view in the center of the parent view. </p>
</td>
</tr>
<tr id="row1819992284165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p283716224165634"><a name="p283716224165634"></a><a name="p283716224165634"></a><a href="Graphic.md#ga94999b271f27cd5d6bfaf303f7d5c708">LayoutLeftOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p572741857165634"><a name="p572741857165634"></a><a name="p572741857165634"></a>void </p>
<p id="p62503088165634"><a name="p62503088165634"></a><a name="p62503088165634"></a>Lays out the view on the left of the parent view. </p>
</td>
</tr>
<tr id="row320873119165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p841247719165634"><a name="p841247719165634"></a><a name="p841247719165634"></a><a href="Graphic.md#ga479528ed259b5539e423955f2b60517d">LayoutRightOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p570612197165634"><a name="p570612197165634"></a><a name="p570612197165634"></a>void </p>
<p id="p165143923165634"><a name="p165143923165634"></a><a name="p165143923165634"></a>Lays out the view on the right of the parent view. </p>
</td>
</tr>
<tr id="row1646634896165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1300125302165634"><a name="p1300125302165634"></a><a name="p1300125302165634"></a><a href="Graphic.md#ga859288ea61ad23ba7e381bbc07769e83">LayoutTopOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2049353357165634"><a name="p2049353357165634"></a><a name="p2049353357165634"></a>void </p>
<p id="p1833559634165634"><a name="p1833559634165634"></a><a name="p1833559634165634"></a>Lays out the view on the top of the parent view. </p>
</td>
</tr>
<tr id="row1292215350165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1816497719165634"><a name="p1816497719165634"></a><a name="p1816497719165634"></a><a href="Graphic.md#ga809aeee4792ae58218a0bcfcb94d5cdc">LayoutBottomOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1719776053165634"><a name="p1719776053165634"></a><a name="p1719776053165634"></a>void </p>
<p id="p1250318729165634"><a name="p1250318729165634"></a><a name="p1250318729165634"></a>Lays out the view on the bottom of the parent view. </p>
</td>
</tr>
<tr id="row1836357296165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1443700902165634"><a name="p1443700902165634"></a><a name="p1443700902165634"></a><a href="Graphic.md#gac7f5f2584c716a56fee3783f8dea6246">AlignLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1880086426165634"><a name="p1880086426165634"></a><a name="p1880086426165634"></a>void </p>
<p id="p1316723049165634"><a name="p1316723049165634"></a><a name="p1316723049165634"></a>Aligns the view with the left of a sibling view. </p>
</td>
</tr>
<tr id="row1230436665165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1751997592165634"><a name="p1751997592165634"></a><a name="p1751997592165634"></a><a href="Graphic.md#gabb1ac454cdf95593c1e387d5e272433c">AlignRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1940312455165634"><a name="p1940312455165634"></a><a name="p1940312455165634"></a>void </p>
<p id="p154688471165634"><a name="p154688471165634"></a><a name="p154688471165634"></a>Aligns the view with the right of a sibling view. </p>
</td>
</tr>
<tr id="row1712159735165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1308210796165634"><a name="p1308210796165634"></a><a name="p1308210796165634"></a><a href="Graphic.md#ga903d7cbc59bac06d728b7f6435c9a504">AlignTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2141539491165634"><a name="p2141539491165634"></a><a name="p2141539491165634"></a>void </p>
<p id="p127499988165634"><a name="p127499988165634"></a><a name="p127499988165634"></a>Aligns the view with the top of a sibling view. </p>
</td>
</tr>
<tr id="row567793610165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p766764085165634"><a name="p766764085165634"></a><a name="p766764085165634"></a><a href="Graphic.md#ga7607c3f9661932c495d080e9d92fb1a3">AlignBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p464086161165634"><a name="p464086161165634"></a><a name="p464086161165634"></a>void </p>
<p id="p590860268165634"><a name="p590860268165634"></a><a name="p590860268165634"></a>Aligns the view with the bottom of a sibling view. </p>
</td>
</tr>
<tr id="row1232956287165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2064994142165634"><a name="p2064994142165634"></a><a name="p2064994142165634"></a><a href="Graphic.md#gac23776dbc2fce7ff30d57438abfa5230">AlignHorCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1014266283165634"><a name="p1014266283165634"></a><a name="p1014266283165634"></a>void </p>
<p id="p1957375240165634"><a name="p1957375240165634"></a><a name="p1957375240165634"></a>Aligns the view with the center of a sibling view in the x-axis. </p>
</td>
</tr>
<tr id="row1301267022165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p907511868165634"><a name="p907511868165634"></a><a name="p907511868165634"></a><a href="Graphic.md#gad3caa27aa0cb73ec4656e7d23aa222de">AlignVerCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2081719414165634"><a name="p2081719414165634"></a><a name="p2081719414165634"></a>void </p>
<p id="p1021508429165634"><a name="p1021508429165634"></a><a name="p1021508429165634"></a>Aligns the view with the center of a sibling view in the y-axis. </p>
</td>
</tr>
<tr id="row881476935165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1704865321165634"><a name="p1704865321165634"></a><a name="p1704865321165634"></a><a href="Graphic.md#ga58f1a34a943c4492970f901d63bbc3d8">LayoutLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1553775408165634"><a name="p1553775408165634"></a><a name="p1553775408165634"></a>void </p>
<p id="p205755212165634"><a name="p205755212165634"></a><a name="p205755212165634"></a>Lays out the view on the left of a sibling view. </p>
</td>
</tr>
<tr id="row1387022771165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p370909019165634"><a name="p370909019165634"></a><a name="p370909019165634"></a><a href="Graphic.md#gac4cd64de5291759add164825a323a0d6">LayoutRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1423498235165634"><a name="p1423498235165634"></a><a name="p1423498235165634"></a>void </p>
<p id="p114903246165634"><a name="p114903246165634"></a><a name="p114903246165634"></a>Lays out the view on the right of a sibling view. </p>
</td>
</tr>
<tr id="row699710011165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1581710806165634"><a name="p1581710806165634"></a><a name="p1581710806165634"></a><a href="Graphic.md#gaaa8385807e3a9bea46f8dcc326252a70">LayoutTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p957609366165634"><a name="p957609366165634"></a><a name="p957609366165634"></a>void </p>
<p id="p1973428502165634"><a name="p1973428502165634"></a><a name="p1973428502165634"></a>Lays out the view on the above of a sibling view. </p>
</td>
</tr>
<tr id="row837511756165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p413218331165634"><a name="p413218331165634"></a><a name="p413218331165634"></a><a href="Graphic.md#gaa23a68e8ef0fb13b362218e71cf67ace">LayoutBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1699524798165634"><a name="p1699524798165634"></a><a name="p1699524798165634"></a>void </p>
<p id="p706953206165634"><a name="p706953206165634"></a><a name="p706953206165634"></a>Lays out the view on the below of a sibling view. </p>
</td>
</tr>
<tr id="row84492769165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1122869126165634"><a name="p1122869126165634"></a><a name="p1122869126165634"></a><a href="Graphic.md#ga535942844ebee554d413e960634a2867">SetStyle</a> (<a href="OHOS-Style.md">Style</a> &amp;style)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p631866357165634"><a name="p631866357165634"></a><a name="p631866357165634"></a>void </p>
<p id="p487977512165634"><a name="p487977512165634"></a><a name="p487977512165634"></a>Sets the view style. </p>
</td>
</tr>
<tr id="row1147249104165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1949695203165634"><a name="p1949695203165634"></a><a name="p1949695203165634"></a><a href="Graphic.md#ga0945c2f05815dc2e466ef9ceaca2f700">SetStyle</a> (uint8_t key, int64_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p496993560165634"><a name="p496993560165634"></a><a name="p496993560165634"></a>virtual void </p>
<p id="p897445792165634"><a name="p897445792165634"></a><a name="p897445792165634"></a>Sets a style. </p>
</td>
</tr>
<tr id="row1782397127165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1685295794165634"><a name="p1685295794165634"></a><a name="p1685295794165634"></a><a href="Graphic.md#ga4ea19bc9f4b487946c9e29e63b54a0e6">GetStyle</a> (uint8_t key) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p478534912165634"><a name="p478534912165634"></a><a name="p478534912165634"></a>virtual int64_t </p>
<p id="p53854726165634"><a name="p53854726165634"></a><a name="p53854726165634"></a>Obtains the value of a style. </p>
</td>
</tr>
<tr id="row1183226644165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1113420041165634"><a name="p1113420041165634"></a><a name="p1113420041165634"></a><a href="Graphic.md#ga1b28213d4c2cd0f8324bce3fe56eb7bb">GetStyleConst</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p8706790165634"><a name="p8706790165634"></a><a name="p8706790165634"></a>const <a href="OHOS-Style.md">Style</a> &amp; </p>
<p id="p1857393315165634"><a name="p1857393315165634"></a><a name="p1857393315165634"></a>Obtains the view style. This function applies to scenarios where the style does not need to be modified, which saves memory. </p>
</td>
</tr>
<tr id="row851498350165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1526345465165634"><a name="p1526345465165634"></a><a name="p1526345465165634"></a><a href="Graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p916127614165634"><a name="p916127614165634"></a><a name="p916127614165634"></a>void * </p>
<p id="p999409005165634"><a name="p999409005165634"></a><a name="p999409005165634"></a>Overrides the <strong id="b1927608732165634"><a name="b1927608732165634"></a><a name="b1927608732165634"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row515694702165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p919636859165634"><a name="p919636859165634"></a><a name="p919636859165634"></a><a href="Graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p125895107165634"><a name="p125895107165634"></a><a name="p125895107165634"></a>void </p>
<p id="p1763020331165634"><a name="p1763020331165634"></a><a name="p1763020331165634"></a>Overrides the <strong id="b864176639165634"><a name="b864176639165634"></a><a name="b864176639165634"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

