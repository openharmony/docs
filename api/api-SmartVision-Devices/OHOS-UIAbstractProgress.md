# OHOS::UIAbstractProgress<a name="ZH-CN_TOPIC_0000001055078159"></a>

-   [Overview](#section1542664288165633)
-   [Summary](#section346208303165633)
-   [Public Member Functions](#pub-methods)

## **Overview**<a name="section1542664288165633"></a>

**Related Modules:**

[Graphic](Graphic.md)

**Description:**

Represents the abstract base class which provides functions related to the progress bar. 

See also
:   [UIView](OHOS-UIView.md) 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section346208303165633"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table819440606165633"></a>
<table><thead align="left"><tr id="row1873465992165633"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1327909310165633"><a name="p1327909310165633"></a><a name="p1327909310165633"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1921401791165633"><a name="p1921401791165633"></a><a name="p1921401791165633"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row193587361165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1077309577165633"><a name="p1077309577165633"></a><a name="p1077309577165633"></a><a href="Graphic.md#ga8f9bfb4f42ee0e094501ff776e3336da">UIAbstractProgress</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1163626607165633"><a name="p1163626607165633"></a><a name="p1163626607165633"></a> </p>
<p id="p386219193165633"><a name="p386219193165633"></a><a name="p386219193165633"></a>A constructor used to create a <strong id="b765577514165633"><a name="b765577514165633"></a><a name="b765577514165633"></a><a href="OHOS-UIAbstractProgress.md">UIAbstractProgress</a></strong> instance. </p>
</td>
</tr>
<tr id="row2110827314165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p867639046165633"><a name="p867639046165633"></a><a name="p867639046165633"></a><a href="Graphic.md#ga5c1cf7239bf0c0f7d331e63df805b518">~UIAbstractProgress</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p216828954165633"><a name="p216828954165633"></a><a name="p216828954165633"></a>virtual </p>
<p id="p2020401888165633"><a name="p2020401888165633"></a><a name="p2020401888165633"></a>A destructor used to delete the <strong id="b1009273419165633"><a name="b1009273419165633"></a><a name="b1009273419165633"></a><a href="OHOS-UIAbstractProgress.md">UIAbstractProgress</a></strong> instance. </p>
</td>
</tr>
<tr id="row135138583165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p868284179165633"><a name="p868284179165633"></a><a name="p868284179165633"></a><a href="Graphic.md#ga79885b87d1935947f6980ae56f139083">GetViewType</a> () const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1274056799165633"><a name="p1274056799165633"></a><a name="p1274056799165633"></a>UIViewType </p>
<p id="p576009285165633"><a name="p576009285165633"></a><a name="p576009285165633"></a>Obtains the component type. </p>
</td>
</tr>
<tr id="row1360706457165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p938818212165633"><a name="p938818212165633"></a><a name="p938818212165633"></a><a href="Graphic.md#gacb680c1ddc9135371676df504dc6c8f2">EnableBackground</a> (bool enable)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2137072827165633"><a name="p2137072827165633"></a><a name="p2137072827165633"></a>void </p>
<p id="p1307144896165633"><a name="p1307144896165633"></a><a name="p1307144896165633"></a>Sets whether the background of the progress bar is visible. </p>
</td>
</tr>
<tr id="row1953103941165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1877508909165633"><a name="p1877508909165633"></a><a name="p1877508909165633"></a><a href="Graphic.md#ga5f65014431a6489ffa1d4949f9c4449b">SetValue</a> (int16_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1096770083165633"><a name="p1096770083165633"></a><a name="p1096770083165633"></a>void </p>
<p id="p1865027442165633"><a name="p1865027442165633"></a><a name="p1865027442165633"></a>Sets the current value for this progress bar. </p>
</td>
</tr>
<tr id="row1166106279165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p588043183165633"><a name="p588043183165633"></a><a name="p588043183165633"></a><a href="Graphic.md#ga6face76aa7972efeb6cbb8f525f23135">GetValue</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p693528351165633"><a name="p693528351165633"></a><a name="p693528351165633"></a>int16_t </p>
<p id="p1718147600165633"><a name="p1718147600165633"></a><a name="p1718147600165633"></a>Obtains the current value of this progress bar. </p>
</td>
</tr>
<tr id="row404687591165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p563739525165633"><a name="p563739525165633"></a><a name="p563739525165633"></a><a href="Graphic.md#ga089e3875453011499ad33ed89a44a699">SetRange</a> (int16_t rangeMax, int16_t rangeMin)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p884620547165633"><a name="p884620547165633"></a><a name="p884620547165633"></a>void </p>
<p id="p11339543165633"><a name="p11339543165633"></a><a name="p11339543165633"></a>Sets the range for this progress bar. </p>
</td>
</tr>
<tr id="row253414582165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p668745943165633"><a name="p668745943165633"></a><a name="p668745943165633"></a><a href="Graphic.md#ga68ab733afcf4224a799ccad2092d1d23">GetRangeMin</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1583956779165633"><a name="p1583956779165633"></a><a name="p1583956779165633"></a>int16_t </p>
<p id="p1389364925165633"><a name="p1389364925165633"></a><a name="p1389364925165633"></a>Obtains the minimum value of this progress bar. </p>
</td>
</tr>
<tr id="row966418703165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1909393444165633"><a name="p1909393444165633"></a><a name="p1909393444165633"></a><a href="Graphic.md#ga1840199f22d5d3e4ef58e41ac8f4febc">GetRangeMax</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p78446129165633"><a name="p78446129165633"></a><a name="p78446129165633"></a>int16_t </p>
<p id="p2064136804165633"><a name="p2064136804165633"></a><a name="p2064136804165633"></a>Obtains the maximum value of this progress bar. </p>
</td>
</tr>
<tr id="row1442198794165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p502783752165633"><a name="p502783752165633"></a><a name="p502783752165633"></a><a href="Graphic.md#ga5b3ec363e391f601e12bf937b9cf77db">SetImage</a> (const char *foregroundImage, const char *backgroundImage=nullptr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1065566748165633"><a name="p1065566748165633"></a><a name="p1065566748165633"></a>void </p>
<p id="p60846675165633"><a name="p60846675165633"></a><a name="p60846675165633"></a>Sets the image for this progress bar. </p>
</td>
</tr>
<tr id="row1815096034165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1765182387165633"><a name="p1765182387165633"></a><a name="p1765182387165633"></a><a href="Graphic.md#ga10723293ab9e384907dd9dacbc9ad448">SetImage</a> (const <a href="OHOS-ImageInfo.md">ImageInfo</a> *foregroundImage, const <a href="OHOS-ImageInfo.md">ImageInfo</a> *backgroundImage=nullptr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1581241292165633"><a name="p1581241292165633"></a><a name="p1581241292165633"></a>void </p>
<p id="p2021296272165633"><a name="p2021296272165633"></a><a name="p2021296272165633"></a>Sets the image as a pixel map for this progress bar. </p>
</td>
</tr>
<tr id="row1108583692165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p986100635165633"><a name="p986100635165633"></a><a name="p986100635165633"></a><a href="Graphic.md#ga747a29652b441a06d09a97a297aae9bb">SetStep</a> (uint16_t step)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p806674541165633"><a name="p806674541165633"></a><a name="p806674541165633"></a>void </p>
<p id="p1132529091165633"><a name="p1132529091165633"></a><a name="p1132529091165633"></a>Sets the step for this progress bar. </p>
</td>
</tr>
<tr id="row1718103688165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1532776125165633"><a name="p1532776125165633"></a><a name="p1532776125165633"></a><a href="Graphic.md#ga9c1678604605a54c2e338d283c46866d">GetStep</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p516823090165633"><a name="p516823090165633"></a><a name="p516823090165633"></a>uint16_t </p>
<p id="p755003787165633"><a name="p755003787165633"></a><a name="p755003787165633"></a>Obtains the current step of this progress bar. </p>
</td>
</tr>
<tr id="row165255827165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1860367066165633"><a name="p1860367066165633"></a><a name="p1860367066165633"></a><a href="Graphic.md#ga6817b5178e93e5f16f2b420cf5a171c1">SetBackgroundStyle</a> (const <a href="OHOS-Style.md">Style</a> &amp;style)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p640051272165633"><a name="p640051272165633"></a><a name="p640051272165633"></a>void </p>
<p id="p1778144818165633"><a name="p1778144818165633"></a><a name="p1778144818165633"></a>Sets the background style for this progress bar. </p>
</td>
</tr>
<tr id="row1576134360165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p818527891165633"><a name="p818527891165633"></a><a name="p818527891165633"></a><a href="Graphic.md#ga23acea0a42587746e35ec5f3a74af59f">SetBackgroundStyle</a> (uint8_t key, int64_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p663572843165633"><a name="p663572843165633"></a><a name="p663572843165633"></a>void </p>
<p id="p163411694165633"><a name="p163411694165633"></a><a name="p163411694165633"></a>Sets a background style for this progress bar. </p>
</td>
</tr>
<tr id="row1573773019165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p135525434165633"><a name="p135525434165633"></a><a name="p135525434165633"></a><a href="Graphic.md#gac2ca1212c23c11405b12ae0a46c7eff1">GetBackgroundStyle</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1656398819165633"><a name="p1656398819165633"></a><a name="p1656398819165633"></a>const <a href="OHOS-Style.md">Style</a> &amp; </p>
<p id="p419030496165633"><a name="p419030496165633"></a><a name="p419030496165633"></a>Obtains the background style of this progress bar. </p>
</td>
</tr>
<tr id="row1778552639165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p383946327165633"><a name="p383946327165633"></a><a name="p383946327165633"></a><a href="Graphic.md#ga946d3f2c39a79d45149118536b2557a9">GetBackgroundStyle</a> (uint8_t key) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p333554128165633"><a name="p333554128165633"></a><a name="p333554128165633"></a>int64_t </p>
<p id="p1862800043165633"><a name="p1862800043165633"></a><a name="p1862800043165633"></a>Obtains the value of a background style of this progress bar. </p>
</td>
</tr>
<tr id="row1763803638165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p912060984165633"><a name="p912060984165633"></a><a name="p912060984165633"></a><a href="Graphic.md#gaccebcfa35f98f9bc6be4bb8cc53eb11c">SetForegroundStyle</a> (const <a href="OHOS-Style.md">Style</a> &amp;style)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p568505918165633"><a name="p568505918165633"></a><a name="p568505918165633"></a>void </p>
<p id="p1946825391165633"><a name="p1946825391165633"></a><a name="p1946825391165633"></a>Sets the foreground style for this progress bar. </p>
</td>
</tr>
<tr id="row1518014113165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p692182828165633"><a name="p692182828165633"></a><a name="p692182828165633"></a><a href="Graphic.md#gae6386ca25603e42f06087f6b2ef65bae">SetForegroundStyle</a> (uint8_t key, int64_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1750773771165633"><a name="p1750773771165633"></a><a name="p1750773771165633"></a>void </p>
<p id="p337979087165633"><a name="p337979087165633"></a><a name="p337979087165633"></a>Sets a foreground style for this progress bar. </p>
</td>
</tr>
<tr id="row1449358872165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p328053400165633"><a name="p328053400165633"></a><a name="p328053400165633"></a><a href="Graphic.md#gac77f945f375f333f80bd70254b5c1f96">GetForegroundStyle</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1699426453165633"><a name="p1699426453165633"></a><a name="p1699426453165633"></a>const <a href="OHOS-Style.md">Style</a> &amp; </p>
<p id="p1953957287165633"><a name="p1953957287165633"></a><a name="p1953957287165633"></a>Obtains the foreground style of this progress bar. </p>
</td>
</tr>
<tr id="row1237326079165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p513417037165633"><a name="p513417037165633"></a><a name="p513417037165633"></a><a href="Graphic.md#ga74cd121dd1794d7e8d905b233bd98217">GetForegroundStyle</a> (uint8_t key) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2024717042165633"><a name="p2024717042165633"></a><a name="p2024717042165633"></a>int64_t </p>
<p id="p62367225165633"><a name="p62367225165633"></a><a name="p62367225165633"></a>Obtains the value of a foreground style of this progress bar. </p>
</td>
</tr>
<tr id="row1803354204165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1304745991165633"><a name="p1304745991165633"></a><a name="p1304745991165633"></a><a href="Graphic.md#gabdc0eb4d279212ea7c3ea7a1f9a85e13">SetCapType</a> (<a href="Graphic.md#ga2db3928cdf793f4950245a6841dd43d6">CapType</a> cap)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p407658528165633"><a name="p407658528165633"></a><a name="p407658528165633"></a>void </p>
<p id="p943560525165633"><a name="p943560525165633"></a><a name="p943560525165633"></a>Sets the type of caps on the background and foreground of the progress bar. </p>
</td>
</tr>
<tr id="row1241251774165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p90068937165633"><a name="p90068937165633"></a><a name="p90068937165633"></a><a href="Graphic.md#ga7aad5b50d945efe5f9304bc978b2001c">UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p260736883165633"><a name="p260736883165633"></a><a name="p260736883165633"></a> </p>
<p id="p1300831829165633"><a name="p1300831829165633"></a><a name="p1300831829165633"></a>A default constructor used to create an <strong id="b89918738165633"><a name="b89918738165633"></a><a name="b89918738165633"></a><a href="OHOS-UIView.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row486512557165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1862927532165633"><a name="p1862927532165633"></a><a name="p1862927532165633"></a><a href="Graphic.md#ga57d429bb1cd71782f3b825f1bc6b9362">UIView</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1760771883165633"><a name="p1760771883165633"></a><a name="p1760771883165633"></a> </p>
<p id="p1354389587165633"><a name="p1354389587165633"></a><a name="p1354389587165633"></a>A constructor used to create an <strong id="b325362255165633"><a name="b325362255165633"></a><a name="b325362255165633"></a><a href="OHOS-UIView.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row766235427165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2051524626165633"><a name="p2051524626165633"></a><a name="p2051524626165633"></a><a href="Graphic.md#ga17f0ffc1090bdcce0f88288da5962012">~UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1070730440165633"><a name="p1070730440165633"></a><a name="p1070730440165633"></a>virtual </p>
<p id="p657566552165633"><a name="p657566552165633"></a><a name="p657566552165633"></a>A destructor used to delete the <strong id="b1533441525165633"><a name="b1533441525165633"></a><a name="b1533441525165633"></a><a href="OHOS-UIView.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row1857654798165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1282367382165633"><a name="p1282367382165633"></a><a name="p1282367382165633"></a><a href="Graphic.md#gac295fe4851eed72f48e9a63771416d71">OnPreDraw</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1487310022165633"><a name="p1487310022165633"></a><a name="p1487310022165633"></a>virtual bool </p>
<p id="p1866178831165633"><a name="p1866178831165633"></a><a name="p1866178831165633"></a>Called before a view is drawn. This function is used to check whether the parent view of this view needs to be redrawn so as to optimize the drawing process. </p>
</td>
</tr>
<tr id="row493287537165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1762252839165633"><a name="p1762252839165633"></a><a name="p1762252839165633"></a><a href="Graphic.md#ga9a5f43bdc03cde30323b570bfb7ae425">OnDraw</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p175859169165633"><a name="p175859169165633"></a><a name="p175859169165633"></a>virtual void </p>
<p id="p2107205222165633"><a name="p2107205222165633"></a><a name="p2107205222165633"></a>Called when a view is drawn. </p>
</td>
</tr>
<tr id="row1880512964165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1834942456165633"><a name="p1834942456165633"></a><a name="p1834942456165633"></a><a href="Graphic.md#gab70473cd0d8fe7c9d4bb817caeee9153">OnPostDraw</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1868337917165633"><a name="p1868337917165633"></a><a name="p1868337917165633"></a>virtual void </p>
<p id="p747555794165633"><a name="p747555794165633"></a><a name="p747555794165633"></a>Called after a view is drawn. </p>
</td>
</tr>
<tr id="row1150618462165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1508425251165633"><a name="p1508425251165633"></a><a name="p1508425251165633"></a><a href="Graphic.md#ga81726238adeda1efa989be6ed4f4fe5b">ReMeasure</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1415952917165633"><a name="p1415952917165633"></a><a name="p1415952917165633"></a>virtual void </p>
<p id="p809651587165633"><a name="p809651587165633"></a><a name="p809651587165633"></a>Remeasures the view size. </p>
</td>
</tr>
<tr id="row1681350208165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1572957480165633"><a name="p1572957480165633"></a><a name="p1572957480165633"></a><a href="Graphic.md#ga2a9a38b8450fbb196277238a51fbbf99">Invalidate</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1611731521165633"><a name="p1611731521165633"></a><a name="p1611731521165633"></a>void </p>
<p id="p1658929327165633"><a name="p1658929327165633"></a><a name="p1658929327165633"></a>Refreshes the invalidated area of the view. </p>
</td>
</tr>
<tr id="row1221582175165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p338641924165633"><a name="p338641924165633"></a><a name="p338641924165633"></a><a href="Graphic.md#gaf0e6b65ced8b931642f2a80c195962d2">InvalidateRect</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1398044910165633"><a name="p1398044910165633"></a><a name="p1398044910165633"></a>void </p>
<p id="p2115248290165633"><a name="p2115248290165633"></a><a name="p2115248290165633"></a>Refreshes a view in a specified invalidated area. </p>
</td>
</tr>
<tr id="row2139241068165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1366089008165633"><a name="p1366089008165633"></a><a name="p1366089008165633"></a><a href="Graphic.md#gac311aa47301d727c35fc31f8630d016e">OnLongPressEvent</a> (const <a href="OHOS-LongPressEvent.md">LongPressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p370409848165633"><a name="p370409848165633"></a><a name="p370409848165633"></a>virtual bool </p>
<p id="p295281262165633"><a name="p295281262165633"></a><a name="p295281262165633"></a>Called when the view is long pressed. </p>
</td>
</tr>
<tr id="row1551658253165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p939876834165633"><a name="p939876834165633"></a><a name="p939876834165633"></a><a href="Graphic.md#gac0e10556ff99b8a92bfb11df6456d605">OnDragStartEvent</a> (const <a href="OHOS-DragEvent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p990905178165633"><a name="p990905178165633"></a><a name="p990905178165633"></a>virtual bool </p>
<p id="p1947859609165633"><a name="p1947859609165633"></a><a name="p1947859609165633"></a>Called when the view starts to drag. </p>
</td>
</tr>
<tr id="row1388278051165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1245673816165633"><a name="p1245673816165633"></a><a name="p1245673816165633"></a><a href="Graphic.md#ga46249c8caf06b81590d9450e30a31147">OnDragEvent</a> (const <a href="OHOS-DragEvent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p306850156165633"><a name="p306850156165633"></a><a name="p306850156165633"></a>virtual bool </p>
<p id="p1847799893165633"><a name="p1847799893165633"></a><a name="p1847799893165633"></a>Called when the view is being dragged. </p>
</td>
</tr>
<tr id="row252250126165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p181473724165633"><a name="p181473724165633"></a><a name="p181473724165633"></a><a href="Graphic.md#ga1799d33be73f64ed2066f50d7e65468d">OnDragEndEvent</a> (const <a href="OHOS-DragEvent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1513802379165633"><a name="p1513802379165633"></a><a name="p1513802379165633"></a>virtual bool </p>
<p id="p753756435165633"><a name="p753756435165633"></a><a name="p753756435165633"></a>Called when the view stops dragging. </p>
</td>
</tr>
<tr id="row1912379322165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1147093306165633"><a name="p1147093306165633"></a><a name="p1147093306165633"></a><a href="Graphic.md#gad08697a29aae4c58267f494b66b9a547">OnClickEvent</a> (const <a href="OHOS-ClickEvent.md">ClickEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1003529020165633"><a name="p1003529020165633"></a><a name="p1003529020165633"></a>virtual void </p>
<p id="p911175757165633"><a name="p911175757165633"></a><a name="p911175757165633"></a>Called when the view is clicked. </p>
</td>
</tr>
<tr id="row385910298165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1178988174165633"><a name="p1178988174165633"></a><a name="p1178988174165633"></a><a href="Graphic.md#gafa544ff2d27785a9410a80689f1ad3b1">OnPressEvent</a> (const <a href="OHOS-PressEvent.md">PressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1797642683165633"><a name="p1797642683165633"></a><a name="p1797642683165633"></a>virtual void </p>
<p id="p1759548560165633"><a name="p1759548560165633"></a><a name="p1759548560165633"></a>Called when the view is pressed. </p>
</td>
</tr>
<tr id="row1711023101165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1702111683165633"><a name="p1702111683165633"></a><a name="p1702111683165633"></a><a href="Graphic.md#ga7bd1a74563b059b03fbf66f9add53ee3">OnReleaseEvent</a> (const <a href="OHOS-ReleaseEvent.md">ReleaseEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p213149205165633"><a name="p213149205165633"></a><a name="p213149205165633"></a>virtual void </p>
<p id="p614998671165633"><a name="p614998671165633"></a><a name="p614998671165633"></a>Called when the view is released. </p>
</td>
</tr>
<tr id="row1160916252165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p201176950165633"><a name="p201176950165633"></a><a name="p201176950165633"></a><a href="Graphic.md#ga8f01ff25a33b20df0758f564148e579d">OnCancelEvent</a> (const <a href="OHOS-CancelEvent.md">CancelEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p654532935165633"><a name="p654532935165633"></a><a name="p654532935165633"></a>virtual void </p>
<p id="p1770186712165633"><a name="p1770186712165633"></a><a name="p1770186712165633"></a>Called when a click event on the view is canceled. </p>
</td>
</tr>
<tr id="row955956073165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1932393730165633"><a name="p1932393730165633"></a><a name="p1932393730165633"></a><a href="Graphic.md#gad8e3cf5f0dd003a6aa932ef04e7b59f2">SetOnDragListener</a> (<a href="OHOS-UIView-OnDragListener.md">OnDragListener</a> *onDragListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1374934817165633"><a name="p1374934817165633"></a><a name="p1374934817165633"></a>void </p>
<p id="p1391175866165633"><a name="p1391175866165633"></a><a name="p1391175866165633"></a>Sets a drag event listener for the view. </p>
</td>
</tr>
<tr id="row1244939740165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1809796840165633"><a name="p1809796840165633"></a><a name="p1809796840165633"></a><a href="Graphic.md#ga45a02cba4887c5c0b8e243941bcdc5cb">GetOnDragListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1709153025165633"><a name="p1709153025165633"></a><a name="p1709153025165633"></a><a href="OHOS-UIView-OnDragListener.md">OnDragListener</a> *&amp; </p>
<p id="p431968334165633"><a name="p431968334165633"></a><a name="p431968334165633"></a>Obtains the drag event listener for the view. </p>
</td>
</tr>
<tr id="row1950409014165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1585888834165633"><a name="p1585888834165633"></a><a name="p1585888834165633"></a><a href="Graphic.md#ga4564bf8d8c7184e9c02bf33c9e171fa3">SetOnClickListener</a> (<a href="OHOS-UIView-OnClickListener.md">OnClickListener</a> *onClickListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p189011886165633"><a name="p189011886165633"></a><a name="p189011886165633"></a>void </p>
<p id="p478520656165633"><a name="p478520656165633"></a><a name="p478520656165633"></a>Sets a click event listener for the view. </p>
</td>
</tr>
<tr id="row269600157165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p504130061165633"><a name="p504130061165633"></a><a name="p504130061165633"></a><a href="Graphic.md#ga35e885cb380c37245fa4305bba10cd4a">GetOnClickListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p612240631165633"><a name="p612240631165633"></a><a name="p612240631165633"></a><a href="OHOS-UIView-OnClickListener.md">OnClickListener</a> *&amp; </p>
<p id="p1797004946165633"><a name="p1797004946165633"></a><a name="p1797004946165633"></a>Obtains the click event listener for the view. </p>
</td>
</tr>
<tr id="row1377253927165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1276120009165633"><a name="p1276120009165633"></a><a name="p1276120009165633"></a><a href="Graphic.md#gabcbe7a0adce600424f7f0d5a7396eb5b">SetOnLongPressListener</a> (<a href="OHOS-UIView-OnLongPressListener.md">OnLongPressListener</a> *onLongPressListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p589769477165633"><a name="p589769477165633"></a><a name="p589769477165633"></a>void </p>
<p id="p972239130165633"><a name="p972239130165633"></a><a name="p972239130165633"></a>Sets a long-press event listener for the view. </p>
</td>
</tr>
<tr id="row1825621370165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1276594672165633"><a name="p1276594672165633"></a><a name="p1276594672165633"></a><a href="Graphic.md#gaafd4d354f5f111e758d046109fd7f656">GetOnLongPressListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p927390666165633"><a name="p927390666165633"></a><a name="p927390666165633"></a><a href="OHOS-UIView-OnLongPressListener.md">OnLongPressListener</a> *&amp; </p>
<p id="p1986039356165633"><a name="p1986039356165633"></a><a name="p1986039356165633"></a>Obtains the long-press event listener for the view. </p>
</td>
</tr>
<tr id="row1070363417165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1036571030165633"><a name="p1036571030165633"></a><a name="p1036571030165633"></a><a href="Graphic.md#gadd697fbf481f98d9d6ca8b67390071af">SetOnTouchListener</a> (<a href="OHOS-UIView-OnTouchListener.md">OnTouchListener</a> *onTouchListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1664878275165633"><a name="p1664878275165633"></a><a name="p1664878275165633"></a>void </p>
<p id="p1496971965165633"><a name="p1496971965165633"></a><a name="p1496971965165633"></a>Sets a touch event listener for the view. </p>
</td>
</tr>
<tr id="row260025659165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1911954589165633"><a name="p1911954589165633"></a><a name="p1911954589165633"></a><a href="Graphic.md#gae7c65c68653103dae85acdcef78777a6">GetTouchListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1705934883165633"><a name="p1705934883165633"></a><a name="p1705934883165633"></a><a href="OHOS-UIView-OnTouchListener.md">OnTouchListener</a> *&amp; </p>
<p id="p48037617165633"><a name="p48037617165633"></a><a name="p48037617165633"></a>Obtains the touch event listener for the view. </p>
</td>
</tr>
<tr id="row1649091193165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1576368390165633"><a name="p1576368390165633"></a><a name="p1576368390165633"></a><a href="Graphic.md#gaea9f334f2481e1c03a2cd8f3078d7c72">GetTargetView</a> (const <a href="OHOS-Point.md">Point</a> &amp;point, <a href="OHOS-UIView.md">UIView</a> **last)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p32269472165633"><a name="p32269472165633"></a><a name="p32269472165633"></a>virtual void </p>
<p id="p1521145984165633"><a name="p1521145984165633"></a><a name="p1521145984165633"></a>Obtains the top-level view based on specified coordinates. </p>
</td>
</tr>
<tr id="row1926541152165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p45815318165633"><a name="p45815318165633"></a><a name="p45815318165633"></a><a href="Graphic.md#gaeea67a3a84b4ffe9bfeda418b82184cc">SetParent</a> (<a href="OHOS-UIView.md">UIView</a> *parent)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1686119916165633"><a name="p1686119916165633"></a><a name="p1686119916165633"></a>void </p>
<p id="p402061325165633"><a name="p402061325165633"></a><a name="p402061325165633"></a>Sets the parent view for the view. </p>
</td>
</tr>
<tr id="row447148931165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p660639945165633"><a name="p660639945165633"></a><a name="p660639945165633"></a><a href="Graphic.md#ga706530e4a38108615d5e0c918685ec96">GetParent</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p397581567165633"><a name="p397581567165633"></a><a name="p397581567165633"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p452951760165633"><a name="p452951760165633"></a><a name="p452951760165633"></a>Obtains the parent view of the view. </p>
</td>
</tr>
<tr id="row837921281165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p58728734165633"><a name="p58728734165633"></a><a name="p58728734165633"></a><a href="Graphic.md#ga02bec5de07d93cabc45affba79eba4ad">SetNextSibling</a> (<a href="OHOS-UIView.md">UIView</a> *sibling)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2139158453165633"><a name="p2139158453165633"></a><a name="p2139158453165633"></a>void </p>
<p id="p1175072235165633"><a name="p1175072235165633"></a><a name="p1175072235165633"></a>Sets the next sibling view for the view. </p>
</td>
</tr>
<tr id="row476855703165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1368664420165633"><a name="p1368664420165633"></a><a name="p1368664420165633"></a><a href="Graphic.md#gab0030977b30ddc9f2e15dbc2f58937e6">GetNextSibling</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p442792220165633"><a name="p442792220165633"></a><a name="p442792220165633"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p663458148165633"><a name="p663458148165633"></a><a name="p663458148165633"></a>Obtains the next sibling view of the view. </p>
</td>
</tr>
<tr id="row753261495165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1020421918165633"><a name="p1020421918165633"></a><a name="p1020421918165633"></a><a href="Graphic.md#ga07e7e1f268bd6ce975f4f0f8487af5d0">SetVisible</a> (bool visible)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p608432374165633"><a name="p608432374165633"></a><a name="p608432374165633"></a>virtual void </p>
<p id="p644517748165633"><a name="p644517748165633"></a><a name="p644517748165633"></a>Sets whether the view is visible. </p>
</td>
</tr>
<tr id="row64173227165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1568766323165633"><a name="p1568766323165633"></a><a name="p1568766323165633"></a><a href="Graphic.md#gaee178fc0a86ac03a6bdf2ade0c1914c8">IsVisible</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p838114188165633"><a name="p838114188165633"></a><a name="p838114188165633"></a>bool </p>
<p id="p1088646947165633"><a name="p1088646947165633"></a><a name="p1088646947165633"></a>Checks whether the view is visible. </p>
</td>
</tr>
<tr id="row769168482165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1994564547165633"><a name="p1994564547165633"></a><a name="p1994564547165633"></a><a href="Graphic.md#gaf9fb55fd9aa397f7158f1515e90bce02">SetTouchable</a> (bool touch)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p319485327165633"><a name="p319485327165633"></a><a name="p319485327165633"></a>void </p>
<p id="p1239405810165633"><a name="p1239405810165633"></a><a name="p1239405810165633"></a>Sets whether the view is touchable. </p>
</td>
</tr>
<tr id="row2059927303165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2052718732165633"><a name="p2052718732165633"></a><a name="p2052718732165633"></a><a href="Graphic.md#ga502a53fb77b260fa36b5b3adf82e2340">IsTouchable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p72152231165633"><a name="p72152231165633"></a><a name="p72152231165633"></a>bool </p>
<p id="p181617399165633"><a name="p181617399165633"></a><a name="p181617399165633"></a>Checks whether the view is touchable. </p>
</td>
</tr>
<tr id="row456114599165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1291848009165633"><a name="p1291848009165633"></a><a name="p1291848009165633"></a><a href="Graphic.md#gab06abe0fe824c048f3b72974f9a8f0d0">SetDraggable</a> (bool draggable)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p846709484165633"><a name="p846709484165633"></a><a name="p846709484165633"></a>void </p>
<p id="p901355354165633"><a name="p901355354165633"></a><a name="p901355354165633"></a>Sets whether the view is draggable. </p>
</td>
</tr>
<tr id="row1815774952165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2139623036165633"><a name="p2139623036165633"></a><a name="p2139623036165633"></a><a href="Graphic.md#ga25bb796ff400c767d622cbed280fc500">IsDraggable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1593220669165633"><a name="p1593220669165633"></a><a name="p1593220669165633"></a>bool </p>
<p id="p1450450269165633"><a name="p1450450269165633"></a><a name="p1450450269165633"></a>Checks whether the view is draggable. </p>
</td>
</tr>
<tr id="row1564967396165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1641173375165633"><a name="p1641173375165633"></a><a name="p1641173375165633"></a><a href="Graphic.md#ga6c08e49bf7a82a7ebaef0f251e7a6f85">SetDragParentInstead</a> (bool dragParentInstead)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p66435040165633"><a name="p66435040165633"></a><a name="p66435040165633"></a>void </p>
<p id="p723051250165633"><a name="p723051250165633"></a><a name="p723051250165633"></a>Sets whether to transfer the drag event to the parent view for processing when the view is being dragged. </p>
</td>
</tr>
<tr id="row1897015881165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p596874264165633"><a name="p596874264165633"></a><a name="p596874264165633"></a><a href="Graphic.md#gaf0c462bc31e779b1898ad4cdfdad6faf">IsDragParentInstead</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1240030425165633"><a name="p1240030425165633"></a><a name="p1240030425165633"></a>bool </p>
<p id="p1559269593165633"><a name="p1559269593165633"></a><a name="p1559269593165633"></a>Obtains whether the view transfers a drag event to the parent view for processing. </p>
</td>
</tr>
<tr id="row1675783577165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p896382135165633"><a name="p896382135165633"></a><a name="p896382135165633"></a><a href="Graphic.md#ga86cb8d364f18494d67636c55babced5c">GetRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1284534099165633"><a name="p1284534099165633"></a><a name="p1284534099165633"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p1808529618165633"><a name="p1808529618165633"></a><a name="p1808529618165633"></a>Obtains the absolute rectangle area of the view. When the view has deformation such as rotation, the rectangle area is the intersection set of the absolute rectangle area and deformation matrix. </p>
</td>
</tr>
<tr id="row511437097165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2037440055165633"><a name="p2037440055165633"></a><a name="p2037440055165633"></a><a href="Graphic.md#ga06e79704a19f2a238982076cac3d059b">GetVisibleRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p6799494165633"><a name="p6799494165633"></a><a name="p6799494165633"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p1605371189165633"><a name="p1605371189165633"></a><a name="p1605371189165633"></a>Obtains the visible absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row449623366165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1211716860165633"><a name="p1211716860165633"></a><a name="p1211716860165633"></a><a href="Graphic.md#gab3f8993b3953f27bfc61d53429916cba">GetMaskedRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p621742058165633"><a name="p621742058165633"></a><a name="p621742058165633"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p546355001165633"><a name="p546355001165633"></a><a name="p546355001165633"></a>Obtains the valid absolute rectangle area of the view. The valid area refers to the area where the view can be displayed. Generally, the valid area is the same as the visible view area, but they may be different in the grid layout. </p>
</td>
</tr>
<tr id="row860789111165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p97869551165633"><a name="p97869551165633"></a><a name="p97869551165633"></a><a href="Graphic.md#ga64cf308a09999def1192f9c4e0f17f0a">GetOrigRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2059419142165633"><a name="p2059419142165633"></a><a name="p2059419142165633"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p2078199132165633"><a name="p2078199132165633"></a><a name="p2078199132165633"></a>Obtains the absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row1133877898165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1636588186165633"><a name="p1636588186165633"></a><a name="p1636588186165633"></a><a href="Graphic.md#ga9db88eae712676359d02a92be14fa316">GetContentRect</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p777584707165633"><a name="p777584707165633"></a><a name="p777584707165633"></a>virtual <a href="OHOS-Rect.md">Rect</a> </p>
<p id="p723078507165633"><a name="p723078507165633"></a><a name="p723078507165633"></a>Obtains the content of the absolute rectangle area of the view. This area excludes padding. </p>
</td>
</tr>
<tr id="row1398530423165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1615121043165633"><a name="p1615121043165633"></a><a name="p1615121043165633"></a><a href="Graphic.md#gae9b96837fa1d45648a2a6fbbfcc5eb4a">GetRelativeRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1998173227165633"><a name="p1998173227165633"></a><a name="p1998173227165633"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p2037422529165633"><a name="p2037422529165633"></a><a name="p2037422529165633"></a>Obtains the rectangular area of the view relative to the parent view, that is, the rectangular area relative to the coordinates of the parent view. </p>
</td>
</tr>
<tr id="row74725610165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p750473590165633"><a name="p750473590165633"></a><a name="p750473590165633"></a><a href="Graphic.md#gae6c5f3bcf99dc837bcecd60c38d3df5a">ResizeVisibleArea</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1154026066165633"><a name="p1154026066165633"></a><a name="p1154026066165633"></a>void </p>
<p id="p85364252165633"><a name="p85364252165633"></a><a name="p85364252165633"></a>Adjusts the size of the visible area. This operation may affect the final display size. </p>
</td>
</tr>
<tr id="row1319706337165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1670235565165633"><a name="p1670235565165633"></a><a name="p1670235565165633"></a><a href="Graphic.md#ga3375ec5ef059fd88c657af4552d2fa4f">SetWidth</a> (int16_t width)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1523419625165633"><a name="p1523419625165633"></a><a name="p1523419625165633"></a>virtual void </p>
<p id="p1248319512165633"><a name="p1248319512165633"></a><a name="p1248319512165633"></a>Sets the width for the view. </p>
</td>
</tr>
<tr id="row1231044169165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p410656845165633"><a name="p410656845165633"></a><a name="p410656845165633"></a><a href="Graphic.md#ga90cf8cffb98d71c30d6fc1d118442dbd">GetWidth</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p323587276165633"><a name="p323587276165633"></a><a name="p323587276165633"></a>virtual int16_t </p>
<p id="p1215162986165633"><a name="p1215162986165633"></a><a name="p1215162986165633"></a>Obtains the width for the view. </p>
</td>
</tr>
<tr id="row1704971226165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p697403137165633"><a name="p697403137165633"></a><a name="p697403137165633"></a><a href="Graphic.md#ga9c7110620d5dc3a7bd3efe1fc2edd125">SetHeight</a> (int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2036307256165633"><a name="p2036307256165633"></a><a name="p2036307256165633"></a>virtual void </p>
<p id="p131300947165633"><a name="p131300947165633"></a><a name="p131300947165633"></a>Sets the height for the view. </p>
</td>
</tr>
<tr id="row400164328165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p707808165633"><a name="p707808165633"></a><a name="p707808165633"></a><a href="Graphic.md#ga9b35f4603a561c7a9a29b023a022ac97">GetHeight</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1726786748165633"><a name="p1726786748165633"></a><a name="p1726786748165633"></a>virtual int16_t </p>
<p id="p1763992250165633"><a name="p1763992250165633"></a><a name="p1763992250165633"></a>Obtains the height for the view. </p>
</td>
</tr>
<tr id="row817087239165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p628649557165633"><a name="p628649557165633"></a><a name="p628649557165633"></a><a href="Graphic.md#gae985b607d2f0701911778bf20d640ccd">Resize</a> (int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1242091216165633"><a name="p1242091216165633"></a><a name="p1242091216165633"></a>virtual void </p>
<p id="p171686140165633"><a name="p171686140165633"></a><a name="p171686140165633"></a>Adjusts the size of the view. </p>
</td>
</tr>
<tr id="row1854127882165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p397217536165633"><a name="p397217536165633"></a><a name="p397217536165633"></a><a href="Graphic.md#gaded403626558d28e62bf5632ccbb24b5">SetX</a> (int16_t x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p417271832165633"><a name="p417271832165633"></a><a name="p417271832165633"></a>virtual void </p>
<p id="p502998417165633"><a name="p502998417165633"></a><a name="p502998417165633"></a>Sets the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row2123551156165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p75102898165633"><a name="p75102898165633"></a><a name="p75102898165633"></a><a href="Graphic.md#ga89dc5f8fb1cb4b2259dc0439185359f1">GetX</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1515143115165633"><a name="p1515143115165633"></a><a name="p1515143115165633"></a>int16_t </p>
<p id="p526155139165633"><a name="p526155139165633"></a><a name="p526155139165633"></a>Obtains the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row1115641413165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p16214404165633"><a name="p16214404165633"></a><a name="p16214404165633"></a><a href="Graphic.md#gaaa8edc224cf1c7deb2724fb225960877">SetY</a> (int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p671115448165633"><a name="p671115448165633"></a><a name="p671115448165633"></a>virtual void </p>
<p id="p617085041165633"><a name="p617085041165633"></a><a name="p617085041165633"></a>Sets the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row757443153165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p581652431165633"><a name="p581652431165633"></a><a name="p581652431165633"></a><a href="Graphic.md#ga193619d649204b0e9bb854d3b30275c3">GetY</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1706227479165633"><a name="p1706227479165633"></a><a name="p1706227479165633"></a>int16_t </p>
<p id="p608092698165633"><a name="p608092698165633"></a><a name="p608092698165633"></a>Obtains the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row1094342985165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2108131259165633"><a name="p2108131259165633"></a><a name="p2108131259165633"></a><a href="Graphic.md#gab34233f6aeae330b025969137d03e67a">SetPosition</a> (int16_t x, int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p181278134165633"><a name="p181278134165633"></a><a name="p181278134165633"></a>virtual void </p>
<p id="p650984240165633"><a name="p650984240165633"></a><a name="p650984240165633"></a>Sets the position for the view. </p>
</td>
</tr>
<tr id="row385941227165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1140413754165633"><a name="p1140413754165633"></a><a name="p1140413754165633"></a><a href="Graphic.md#gaf8ce4c009f23b7175b2b34bac4a74262">SetPosition</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1926649528165633"><a name="p1926649528165633"></a><a name="p1926649528165633"></a>virtual void </p>
<p id="p1813552921165633"><a name="p1813552921165633"></a><a name="p1813552921165633"></a>Adjusts the position and size of the view. </p>
</td>
</tr>
<tr id="row1223443915165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p752290097165633"><a name="p752290097165633"></a><a name="p752290097165633"></a><a href="Graphic.md#gab2ce8c11abbd55f40687f38a52511b11">IsViewGroup</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1473403685165633"><a name="p1473403685165633"></a><a name="p1473403685165633"></a>bool </p>
<p id="p670382314165633"><a name="p670382314165633"></a><a name="p670382314165633"></a>Checks whether the view is a container view. </p>
</td>
</tr>
<tr id="row1933947584165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p448812866165633"><a name="p448812866165633"></a><a name="p448812866165633"></a><a href="Graphic.md#ga980fc6824c64cfae6af8657aee17af88">SetIntercept</a> (bool isIntercept)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1017930003165633"><a name="p1017930003165633"></a><a name="p1017930003165633"></a>void </p>
<p id="p1536739304165633"><a name="p1536739304165633"></a><a name="p1536739304165633"></a>Sets whether to intercept the drag event. If intercepted, the view does not transfer the drag event to the parent view after local processing. </p>
</td>
</tr>
<tr id="row591201197165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p570671105165633"><a name="p570671105165633"></a><a name="p570671105165633"></a><a href="Graphic.md#ga8623abbbeff458c0cb2d7dc0d1f21e4a">SetTransformMap</a> (const <a href="OHOS-TransformMap.md">TransformMap</a> &amp;transMap)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1145003452165633"><a name="p1145003452165633"></a><a name="p1145003452165633"></a>void </p>
<p id="p1429372624165633"><a name="p1429372624165633"></a><a name="p1429372624165633"></a>Sets the affine transformation matrix. </p>
</td>
</tr>
<tr id="row834439080165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p680450889165633"><a name="p680450889165633"></a><a name="p680450889165633"></a><a href="Graphic.md#gab8cee5a7052a88722768c8ed1324abc1">GetTransformMap</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1733345857165633"><a name="p1733345857165633"></a><a name="p1733345857165633"></a><a href="OHOS-TransformMap.md">TransformMap</a> &amp; </p>
<p id="p664458626165633"><a name="p664458626165633"></a><a name="p664458626165633"></a>Obtains an affine transformation matrix. </p>
</td>
</tr>
<tr id="row1516076301165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p116170269165633"><a name="p116170269165633"></a><a name="p116170269165633"></a><a href="Graphic.md#ga0573aa25307c22319db4629781b5cad2">GetChildById</a> (const char *id) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2004098941165633"><a name="p2004098941165633"></a><a name="p2004098941165633"></a>virtual <a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p2008846658165633"><a name="p2008846658165633"></a><a name="p2008846658165633"></a>Obtains the child view of a specified ID. </p>
</td>
</tr>
<tr id="row937039262165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p972869470165633"><a name="p972869470165633"></a><a name="p972869470165633"></a><a href="Graphic.md#ga0caaa15c9b304673331e778a266be77f">SetViewId</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p58331923165633"><a name="p58331923165633"></a><a name="p58331923165633"></a>void </p>
<p id="p1369994044165633"><a name="p1369994044165633"></a><a name="p1369994044165633"></a>Sets the view ID. </p>
</td>
</tr>
<tr id="row311679238165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2085592974165633"><a name="p2085592974165633"></a><a name="p2085592974165633"></a><a href="Graphic.md#gad6c7644bd2abfa3c92d80776b0bd1936">GetViewId</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1740040857165633"><a name="p1740040857165633"></a><a name="p1740040857165633"></a>const char * </p>
<p id="p1300303861165633"><a name="p1300303861165633"></a><a name="p1300303861165633"></a>Obtains the view ID. </p>
</td>
</tr>
<tr id="row1358311452165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p589058182165633"><a name="p589058182165633"></a><a name="p589058182165633"></a><a href="Graphic.md#ga77a961aa53567c5214508b4569801c16">SetViewIndex</a> (int16_t <a href="UTILS.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p683117162165633"><a name="p683117162165633"></a><a name="p683117162165633"></a>void </p>
<p id="p1825676091165633"><a name="p1825676091165633"></a><a name="p1825676091165633"></a>Sets the view index. </p>
</td>
</tr>
<tr id="row458217431165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1245703308165633"><a name="p1245703308165633"></a><a name="p1245703308165633"></a><a href="Graphic.md#ga62f51715b6d420a296ebe0296717b906">GetViewIndex</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1619254821165633"><a name="p1619254821165633"></a><a name="p1619254821165633"></a>int16_t </p>
<p id="p1597343734165633"><a name="p1597343734165633"></a><a name="p1597343734165633"></a>Obtains the view index. </p>
</td>
</tr>
<tr id="row30456977165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1111735873165633"><a name="p1111735873165633"></a><a name="p1111735873165633"></a><a href="Graphic.md#gaca871fa2f8219e7ea9388e212d1f1e69">LayoutChildren</a> (bool neeInvalidate=false)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1532179699165633"><a name="p1532179699165633"></a><a name="p1532179699165633"></a>virtual void </p>
<p id="p803053732165633"><a name="p803053732165633"></a><a name="p803053732165633"></a>Lays out all child views according to the preset arrangement mode. </p>
</td>
</tr>
<tr id="row185074539165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1079739734165633"><a name="p1079739734165633"></a><a name="p1079739734165633"></a><a href="Graphic.md#ga443b86ee9275b0421b37a47bad3264dc">LayoutCenterOfParent</a> (int16_t xOffSet=0, int16_t yOffset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p743769563165633"><a name="p743769563165633"></a><a name="p743769563165633"></a>void </p>
<p id="p96543689165633"><a name="p96543689165633"></a><a name="p96543689165633"></a>Lays out the view in the center of the parent view. </p>
</td>
</tr>
<tr id="row1531937706165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1605563061165633"><a name="p1605563061165633"></a><a name="p1605563061165633"></a><a href="Graphic.md#ga94999b271f27cd5d6bfaf303f7d5c708">LayoutLeftOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1142804071165633"><a name="p1142804071165633"></a><a name="p1142804071165633"></a>void </p>
<p id="p1095903601165633"><a name="p1095903601165633"></a><a name="p1095903601165633"></a>Lays out the view on the left of the parent view. </p>
</td>
</tr>
<tr id="row622057220165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p344127120165633"><a name="p344127120165633"></a><a name="p344127120165633"></a><a href="Graphic.md#ga479528ed259b5539e423955f2b60517d">LayoutRightOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p961451512165633"><a name="p961451512165633"></a><a name="p961451512165633"></a>void </p>
<p id="p1009531481165633"><a name="p1009531481165633"></a><a name="p1009531481165633"></a>Lays out the view on the right of the parent view. </p>
</td>
</tr>
<tr id="row1518964678165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1828977192165633"><a name="p1828977192165633"></a><a name="p1828977192165633"></a><a href="Graphic.md#ga859288ea61ad23ba7e381bbc07769e83">LayoutTopOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1969049283165633"><a name="p1969049283165633"></a><a name="p1969049283165633"></a>void </p>
<p id="p1564827568165633"><a name="p1564827568165633"></a><a name="p1564827568165633"></a>Lays out the view on the top of the parent view. </p>
</td>
</tr>
<tr id="row1916273305165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1082735675165633"><a name="p1082735675165633"></a><a name="p1082735675165633"></a><a href="Graphic.md#ga809aeee4792ae58218a0bcfcb94d5cdc">LayoutBottomOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1331045693165633"><a name="p1331045693165633"></a><a name="p1331045693165633"></a>void </p>
<p id="p977361402165633"><a name="p977361402165633"></a><a name="p977361402165633"></a>Lays out the view on the bottom of the parent view. </p>
</td>
</tr>
<tr id="row1309851732165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p234154558165633"><a name="p234154558165633"></a><a name="p234154558165633"></a><a href="Graphic.md#gac7f5f2584c716a56fee3783f8dea6246">AlignLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1351692527165633"><a name="p1351692527165633"></a><a name="p1351692527165633"></a>void </p>
<p id="p15832634165633"><a name="p15832634165633"></a><a name="p15832634165633"></a>Aligns the view with the left of a sibling view. </p>
</td>
</tr>
<tr id="row735559151165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1816913764165633"><a name="p1816913764165633"></a><a name="p1816913764165633"></a><a href="Graphic.md#gabb1ac454cdf95593c1e387d5e272433c">AlignRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p261055542165633"><a name="p261055542165633"></a><a name="p261055542165633"></a>void </p>
<p id="p1379713152165633"><a name="p1379713152165633"></a><a name="p1379713152165633"></a>Aligns the view with the right of a sibling view. </p>
</td>
</tr>
<tr id="row414627063165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p170181312165633"><a name="p170181312165633"></a><a name="p170181312165633"></a><a href="Graphic.md#ga903d7cbc59bac06d728b7f6435c9a504">AlignTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p191499477165633"><a name="p191499477165633"></a><a name="p191499477165633"></a>void </p>
<p id="p441521053165633"><a name="p441521053165633"></a><a name="p441521053165633"></a>Aligns the view with the top of a sibling view. </p>
</td>
</tr>
<tr id="row866065184165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1761252022165633"><a name="p1761252022165633"></a><a name="p1761252022165633"></a><a href="Graphic.md#ga7607c3f9661932c495d080e9d92fb1a3">AlignBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1250402680165633"><a name="p1250402680165633"></a><a name="p1250402680165633"></a>void </p>
<p id="p1855422211165633"><a name="p1855422211165633"></a><a name="p1855422211165633"></a>Aligns the view with the bottom of a sibling view. </p>
</td>
</tr>
<tr id="row363218551165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1878869850165633"><a name="p1878869850165633"></a><a name="p1878869850165633"></a><a href="Graphic.md#gac23776dbc2fce7ff30d57438abfa5230">AlignHorCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p321729885165633"><a name="p321729885165633"></a><a name="p321729885165633"></a>void </p>
<p id="p808004141165633"><a name="p808004141165633"></a><a name="p808004141165633"></a>Aligns the view with the center of a sibling view in the x-axis. </p>
</td>
</tr>
<tr id="row464624644165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1456927532165633"><a name="p1456927532165633"></a><a name="p1456927532165633"></a><a href="Graphic.md#gad3caa27aa0cb73ec4656e7d23aa222de">AlignVerCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p625938029165633"><a name="p625938029165633"></a><a name="p625938029165633"></a>void </p>
<p id="p697795133165633"><a name="p697795133165633"></a><a name="p697795133165633"></a>Aligns the view with the center of a sibling view in the y-axis. </p>
</td>
</tr>
<tr id="row1546882525165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p359921483165633"><a name="p359921483165633"></a><a name="p359921483165633"></a><a href="Graphic.md#ga58f1a34a943c4492970f901d63bbc3d8">LayoutLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p64255059165633"><a name="p64255059165633"></a><a name="p64255059165633"></a>void </p>
<p id="p1190361392165633"><a name="p1190361392165633"></a><a name="p1190361392165633"></a>Lays out the view on the left of a sibling view. </p>
</td>
</tr>
<tr id="row1349361987165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p253627888165633"><a name="p253627888165633"></a><a name="p253627888165633"></a><a href="Graphic.md#gac4cd64de5291759add164825a323a0d6">LayoutRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1166226306165633"><a name="p1166226306165633"></a><a name="p1166226306165633"></a>void </p>
<p id="p1753695600165633"><a name="p1753695600165633"></a><a name="p1753695600165633"></a>Lays out the view on the right of a sibling view. </p>
</td>
</tr>
<tr id="row1206927093165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p142965415165633"><a name="p142965415165633"></a><a name="p142965415165633"></a><a href="Graphic.md#gaaa8385807e3a9bea46f8dcc326252a70">LayoutTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p31481581165633"><a name="p31481581165633"></a><a name="p31481581165633"></a>void </p>
<p id="p1560524100165633"><a name="p1560524100165633"></a><a name="p1560524100165633"></a>Lays out the view on the above of a sibling view. </p>
</td>
</tr>
<tr id="row515506790165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p193251699165633"><a name="p193251699165633"></a><a name="p193251699165633"></a><a href="Graphic.md#gaa23a68e8ef0fb13b362218e71cf67ace">LayoutBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2001644419165633"><a name="p2001644419165633"></a><a name="p2001644419165633"></a>void </p>
<p id="p728376639165633"><a name="p728376639165633"></a><a name="p728376639165633"></a>Lays out the view on the below of a sibling view. </p>
</td>
</tr>
<tr id="row1777568233165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1616986729165633"><a name="p1616986729165633"></a><a name="p1616986729165633"></a><a href="Graphic.md#ga535942844ebee554d413e960634a2867">SetStyle</a> (<a href="OHOS-Style.md">Style</a> &amp;style)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p774402862165633"><a name="p774402862165633"></a><a name="p774402862165633"></a>void </p>
<p id="p1493932730165633"><a name="p1493932730165633"></a><a name="p1493932730165633"></a>Sets the view style. </p>
</td>
</tr>
<tr id="row1695942537165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1598348354165633"><a name="p1598348354165633"></a><a name="p1598348354165633"></a><a href="Graphic.md#ga0945c2f05815dc2e466ef9ceaca2f700">SetStyle</a> (uint8_t key, int64_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p991382874165633"><a name="p991382874165633"></a><a name="p991382874165633"></a>virtual void </p>
<p id="p429615483165633"><a name="p429615483165633"></a><a name="p429615483165633"></a>Sets a style. </p>
</td>
</tr>
<tr id="row587855758165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p457794856165633"><a name="p457794856165633"></a><a name="p457794856165633"></a><a href="Graphic.md#ga4ea19bc9f4b487946c9e29e63b54a0e6">GetStyle</a> (uint8_t key) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1219416911165633"><a name="p1219416911165633"></a><a name="p1219416911165633"></a>virtual int64_t </p>
<p id="p1782672308165633"><a name="p1782672308165633"></a><a name="p1782672308165633"></a>Obtains the value of a style. </p>
</td>
</tr>
<tr id="row1696775452165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2024130756165633"><a name="p2024130756165633"></a><a name="p2024130756165633"></a><a href="Graphic.md#ga1b28213d4c2cd0f8324bce3fe56eb7bb">GetStyleConst</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p541528994165633"><a name="p541528994165633"></a><a name="p541528994165633"></a>const <a href="OHOS-Style.md">Style</a> &amp; </p>
<p id="p494425220165633"><a name="p494425220165633"></a><a name="p494425220165633"></a>Obtains the view style. This function applies to scenarios where the style does not need to be modified, which saves memory. </p>
</td>
</tr>
<tr id="row1333944307165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1632761691165633"><a name="p1632761691165633"></a><a name="p1632761691165633"></a><a href="Graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p106310226165633"><a name="p106310226165633"></a><a name="p106310226165633"></a>void * </p>
<p id="p1087541913165633"><a name="p1087541913165633"></a><a name="p1087541913165633"></a>Overrides the <strong id="b529983164165633"><a name="b529983164165633"></a><a name="b529983164165633"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row1273940740165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1949937528165633"><a name="p1949937528165633"></a><a name="p1949937528165633"></a><a href="Graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p156931889165633"><a name="p156931889165633"></a><a name="p156931889165633"></a>void </p>
<p id="p1554197624165633"><a name="p1554197624165633"></a><a name="p1554197624165633"></a>Overrides the <strong id="b823173592165633"><a name="b823173592165633"></a><a name="b823173592165633"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

