# OHOS::UITextureMapper<a name="EN-US_TOPIC_0000001055039544"></a>

-   [Overview](#section165925275165634)
-   [Summary](#section57266859165634)
-   [Data Structures](#nested-classes)
-   [Public Member Functions](#pub-methods)
-   [Additional Inherited Members](#inherited)

## **Overview**<a name="section165925275165634"></a>

**Related Modules:**

[Graphic](graphic.md)

**Description:**

Rotates and scales images. 

See also
:   [UIImageView](ohos-uiimageview.md) 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section57266859165634"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table504211847165634"></a>
<table><thead align="left"><tr id="row1026134852165634"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p863188395165634"><a name="p863188395165634"></a><a name="p863188395165634"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p738504744165634"><a name="p738504744165634"></a><a name="p738504744165634"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1740297464165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1752372489165634"><a name="p1752372489165634"></a><a name="p1752372489165634"></a><a href="ohos-uitexturemapper-animatorstoplistener.md">AnimatorStopListener</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p795989990165634"><a name="p795989990165634"></a><a name="p795989990165634"></a>Represents a listener that contains a callback to be invoked when this animator stops. </p>
</td>
</tr>
</tbody>
</table>

## Public Member Functions<a name="pub-methods"></a>

<a name="table449339514165634"></a>
<table><thead align="left"><tr id="row1956158738165634"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1314005202165634"><a name="p1314005202165634"></a><a name="p1314005202165634"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p663729981165634"><a name="p663729981165634"></a><a name="p663729981165634"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1271976189165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1272949851165634"><a name="p1272949851165634"></a><a name="p1272949851165634"></a><a href="graphic.md#gaff111e4883be7412bfd6a41d769d9e77">UITextureMapper</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1183517751165634"><a name="p1183517751165634"></a><a name="p1183517751165634"></a> </p>
<p id="p1339078270165634"><a name="p1339078270165634"></a><a name="p1339078270165634"></a>A constructor used to create a <strong id="b753552600165634"><a name="b753552600165634"></a><a name="b753552600165634"></a><a href="ohos-uitexturemapper.md">UITextureMapper</a></strong> instance. </p>
</td>
</tr>
<tr id="row938136855165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p883471493165634"><a name="p883471493165634"></a><a name="p883471493165634"></a><a href="graphic.md#ga6c7e34e3ecc1d300e647483aed10c4cf">~UITextureMapper</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p142148514165634"><a name="p142148514165634"></a><a name="p142148514165634"></a>virtual </p>
<p id="p2113819024165634"><a name="p2113819024165634"></a><a name="p2113819024165634"></a>A destructor used to delete the <strong id="b1982764379165634"><a name="b1982764379165634"></a><a name="b1982764379165634"></a><a href="ohos-uitexturemapper.md">UITextureMapper</a></strong> instance. </p>
</td>
</tr>
<tr id="row2006217275165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p352977012165634"><a name="p352977012165634"></a><a name="p352977012165634"></a><a href="graphic.md#ga5cb1566d1fdd815004a37349dc458203">GetViewType</a> () const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1776133616165634"><a name="p1776133616165634"></a><a name="p1776133616165634"></a>UIViewType </p>
<p id="p1086401603165634"><a name="p1086401603165634"></a><a name="p1086401603165634"></a>Obtains the view type. </p>
</td>
</tr>
<tr id="row1182540056165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1574210624165634"><a name="p1574210624165634"></a><a name="p1574210624165634"></a><a href="graphic.md#ga83f0469f24917e59c3c6d7b331928014">Start</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1166253688165634"><a name="p1166253688165634"></a><a name="p1166253688165634"></a>void </p>
<p id="p452325740165634"><a name="p452325740165634"></a><a name="p452325740165634"></a>Starts this animator. </p>
</td>
</tr>
<tr id="row268498415165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p867089034165634"><a name="p867089034165634"></a><a name="p867089034165634"></a><a href="graphic.md#ga98a7e074315fdf49b6a9c0663848c9aa">SetRotateStart</a> (int16_t start)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1088975788165634"><a name="p1088975788165634"></a><a name="p1088975788165634"></a>void </p>
<p id="p1250450252165634"><a name="p1250450252165634"></a><a name="p1250450252165634"></a>Sets the start angle of rotation for this image. </p>
</td>
</tr>
<tr id="row1046113408165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1587634065165634"><a name="p1587634065165634"></a><a name="p1587634065165634"></a><a href="graphic.md#ga9bb2570b86ef683f8a501e98f8689ed5">SetRotateEnd</a> (int16_t end)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1348621573165634"><a name="p1348621573165634"></a><a name="p1348621573165634"></a>void </p>
<p id="p1959734690165634"><a name="p1959734690165634"></a><a name="p1959734690165634"></a>Sets the end angle of rotation for this image. </p>
</td>
</tr>
<tr id="row409563521165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1243934614165634"><a name="p1243934614165634"></a><a name="p1243934614165634"></a><a href="graphic.md#ga31a2295a15e2e990a1f2484f5756609b">SetScaleStart</a> (float start)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1121056814165634"><a name="p1121056814165634"></a><a name="p1121056814165634"></a>void </p>
<p id="p1509029336165634"><a name="p1509029336165634"></a><a name="p1509029336165634"></a>Sets the start ratio for scaling this image. </p>
</td>
</tr>
<tr id="row1397070837165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1712528981165634"><a name="p1712528981165634"></a><a name="p1712528981165634"></a><a href="graphic.md#ga7c7c54ce9ab139498ba286762286c0c0">SetScaleEnd</a> (float end)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1859569197165634"><a name="p1859569197165634"></a><a name="p1859569197165634"></a>void </p>
<p id="p1825786005165634"><a name="p1825786005165634"></a><a name="p1825786005165634"></a>Sets the end ratio for scaling this image. </p>
</td>
</tr>
<tr id="row1421465126165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p516435760165634"><a name="p516435760165634"></a><a name="p516435760165634"></a><a href="graphic.md#gac2727b2cd7aa7abead44717cf0ce7b3c">SetDurationTime</a> (uint16_t durationTime)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1546622664165634"><a name="p1546622664165634"></a><a name="p1546622664165634"></a>void </p>
<p id="p1882079393165634"><a name="p1882079393165634"></a><a name="p1882079393165634"></a>Sets the duration for this animator, in milliseconds. </p>
</td>
</tr>
<tr id="row1132983698165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p651946005165634"><a name="p651946005165634"></a><a name="p651946005165634"></a><a href="graphic.md#gaa2d428cb1098dafb21e7dd24f6ba612f">SetDelayTime</a> (uint16_t delayTime)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p365052218165634"><a name="p365052218165634"></a><a name="p365052218165634"></a>void </p>
<p id="p1769795177165634"><a name="p1769795177165634"></a><a name="p1769795177165634"></a>Sets the delay time for this animator, in milliseconds. </p>
</td>
</tr>
<tr id="row737763488165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p386273639165634"><a name="p386273639165634"></a><a name="p386273639165634"></a><a href="graphic.md#ga0f099914c2daa13dc6acf3fb28c3f45a">SetEasingFunc</a> (EasingFunc easingFunc)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p929123438165634"><a name="p929123438165634"></a><a name="p929123438165634"></a>void </p>
<p id="p1790327024165634"><a name="p1790327024165634"></a><a name="p1790327024165634"></a>Sets the easing function for this animator. </p>
</td>
</tr>
<tr id="row989605977165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1763352944165634"><a name="p1763352944165634"></a><a name="p1763352944165634"></a><a href="graphic.md#gac838ad321786766c6d4020504b07b93b">Cancel</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1584497615165634"><a name="p1584497615165634"></a><a name="p1584497615165634"></a>void </p>
<p id="p2036494048165634"><a name="p2036494048165634"></a><a name="p2036494048165634"></a>Cancels this animator. </p>
</td>
</tr>
<tr id="row1342266860165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1015324343165634"><a name="p1015324343165634"></a><a name="p1015324343165634"></a><a href="graphic.md#gac18ead79047d6f63e1ceb5fc52bbff68">Reset</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1229900594165634"><a name="p1229900594165634"></a><a name="p1229900594165634"></a>void </p>
<p id="p779861564165634"><a name="p779861564165634"></a><a name="p779861564165634"></a>Displays the original image. </p>
</td>
</tr>
<tr id="row40558580165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1810062965165634"><a name="p1810062965165634"></a><a name="p1810062965165634"></a><a href="graphic.md#ga44fa62a21869361527a8af1a10e5276e">SetPivot</a> (int16_t x, int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p567589533165634"><a name="p567589533165634"></a><a name="p567589533165634"></a>void </p>
<p id="p515808429165634"><a name="p515808429165634"></a><a name="p515808429165634"></a>Sets the coordinates of the rotation and scaling pivots for this image. </p>
</td>
</tr>
<tr id="row175045369165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1301987049165634"><a name="p1301987049165634"></a><a name="p1301987049165634"></a><a href="graphic.md#gaab25406cdcb4af33cfd2cc2c31037d27">SetAnimatorStopListener</a> (<a href="ohos-uitexturemapper-animatorstoplistener.md">AnimatorStopListener</a> *listener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1634952625165634"><a name="p1634952625165634"></a><a name="p1634952625165634"></a>void </p>
<p id="p1481476614165634"><a name="p1481476614165634"></a><a name="p1481476614165634"></a>Sets the listener for the stop of this animator. </p>
</td>
</tr>
<tr id="row1923146300165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1186005279165634"><a name="p1186005279165634"></a><a name="p1186005279165634"></a><a href="graphic.md#ga3db47186dbc7a0cb996c23abcdaf2c38">UIImageView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1847763184165634"><a name="p1847763184165634"></a><a name="p1847763184165634"></a> </p>
<p id="p438144047165634"><a name="p438144047165634"></a><a name="p438144047165634"></a>A default constructor used to create a <strong id="b1062384723165634"><a name="b1062384723165634"></a><a name="b1062384723165634"></a><a href="ohos-uiimageview.md">UIImageView</a></strong> instance. </p>
</td>
</tr>
<tr id="row1132044628165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1630095104165634"><a name="p1630095104165634"></a><a name="p1630095104165634"></a><a href="graphic.md#ga8be6fe17af73ab21f97effa26dbacaca">~UIImageView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1764770583165634"><a name="p1764770583165634"></a><a name="p1764770583165634"></a>virtual </p>
<p id="p1457966525165634"><a name="p1457966525165634"></a><a name="p1457966525165634"></a>A destructor used to delete the <strong id="b1319111482165634"><a name="b1319111482165634"></a><a name="b1319111482165634"></a><a href="ohos-uiimageview.md">UIImageView</a></strong> instance. </p>
</td>
</tr>
<tr id="row130325496165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p989125539165634"><a name="p989125539165634"></a><a name="p989125539165634"></a><a href="graphic.md#ga20ea7dd2d8ddb16cf9750ccdcc2a2803">GetWidth</a> () override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2089444814165634"><a name="p2089444814165634"></a><a name="p2089444814165634"></a>int16_t </p>
<p id="p2079099633165634"><a name="p2079099633165634"></a><a name="p2079099633165634"></a>Obtains the width of this image view. </p>
</td>
</tr>
<tr id="row2061656789165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p944657158165634"><a name="p944657158165634"></a><a name="p944657158165634"></a><a href="graphic.md#gaddc6e68c67782eaad40977c6c2256cdd">GetHeight</a> () override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1582180725165634"><a name="p1582180725165634"></a><a name="p1582180725165634"></a>int16_t </p>
<p id="p2137933992165634"><a name="p2137933992165634"></a><a name="p2137933992165634"></a>Obtains the height of this image view. </p>
</td>
</tr>
<tr id="row1893495817165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p714588714165634"><a name="p714588714165634"></a><a name="p714588714165634"></a><a href="graphic.md#ga5d79816831f61406c1c8bd300da9973e">OnPreDraw</a> (const <a href="ohos-rect.md">Rect</a> &amp;invalidatedArea) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1372662884165634"><a name="p1372662884165634"></a><a name="p1372662884165634"></a>bool </p>
<p id="p1804302937165634"><a name="p1804302937165634"></a><a name="p1804302937165634"></a>Checks whether this image view needs to be covered to optimize the drawing process. </p>
</td>
</tr>
<tr id="row1922037058165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1632272818165634"><a name="p1632272818165634"></a><a name="p1632272818165634"></a><a href="graphic.md#ga565cecb8ac66f2009dc4783da9bdc699">OnDraw</a> (const <a href="ohos-rect.md">Rect</a> &amp;invalidatedArea) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p432378377165634"><a name="p432378377165634"></a><a name="p432378377165634"></a>void </p>
<p id="p51328245165634"><a name="p51328245165634"></a><a name="p51328245165634"></a>Draws this image view. </p>
</td>
</tr>
<tr id="row1777345296165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1303456069165634"><a name="p1303456069165634"></a><a name="p1303456069165634"></a><a href="graphic.md#ga4e2dac4fd52a54a828f13db5ab51d110">SetSrc</a> (const char *src)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p377782518165634"><a name="p377782518165634"></a><a name="p377782518165634"></a>void </p>
<p id="p744907885165634"><a name="p744907885165634"></a><a name="p744907885165634"></a>Sets the image path. </p>
</td>
</tr>
<tr id="row1954046552165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1973327679165634"><a name="p1973327679165634"></a><a name="p1973327679165634"></a><a href="graphic.md#ga18a9eed434132ac60c127ca1fc03e663">SetSrc</a> (const <a href="ohos-imageinfo.md">ImageInfo</a> *src)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1829884443165634"><a name="p1829884443165634"></a><a name="p1829884443165634"></a>void </p>
<p id="p1660267127165634"><a name="p1660267127165634"></a><a name="p1660267127165634"></a>Sets the image information. </p>
</td>
</tr>
<tr id="row1599882353165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1864216477165634"><a name="p1864216477165634"></a><a name="p1864216477165634"></a><a href="graphic.md#gab3f60d7eff9b467c64edc90293dbb21d">SetAutoEnable</a> (bool enable)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1319214889165634"><a name="p1319214889165634"></a><a name="p1319214889165634"></a>void </p>
<p id="p323827444165634"><a name="p323827444165634"></a><a name="p323827444165634"></a>Sets whether the image view size needs to be adaptive to the image size. </p>
</td>
</tr>
<tr id="row1796923318165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p394682582165634"><a name="p394682582165634"></a><a name="p394682582165634"></a><a href="graphic.md#ga339c80c2f8f05ff0d79638dc61c71d5a">SetBlurLevel</a> (BlurLevel level)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1992378449165634"><a name="p1992378449165634"></a><a name="p1992378449165634"></a>void </p>
<p id="p917382388165634"><a name="p917382388165634"></a><a name="p917382388165634"></a>Sets the blur level for this image when it is rotated or scaled. </p>
</td>
</tr>
<tr id="row1810046759165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p792887155165634"><a name="p792887155165634"></a><a name="p792887155165634"></a><a href="graphic.md#ga8c891ce7719b97f6d49b0554caa371cb">GetBlurLevel</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p261351846165634"><a name="p261351846165634"></a><a name="p261351846165634"></a>BlurLevel </p>
<p id="p2020161372165634"><a name="p2020161372165634"></a><a name="p2020161372165634"></a>Obtains the blur level of this image when it is rotated or scaled. </p>
</td>
</tr>
<tr id="row572574910165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1856715916165634"><a name="p1856715916165634"></a><a name="p1856715916165634"></a><a href="graphic.md#gacd3bafd7cd7dfb83d46d4fae36eae612">SetTransformAlgorithm</a> (TransformAlgorithm algorithm)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1777115970165634"><a name="p1777115970165634"></a><a name="p1777115970165634"></a>void </p>
<p id="p2065251812165634"><a name="p2065251812165634"></a><a name="p2065251812165634"></a>Sets the algorithm used for image rotation and scaling. </p>
</td>
</tr>
<tr id="row2070908784165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p708637076165634"><a name="p708637076165634"></a><a name="p708637076165634"></a><a href="graphic.md#gac7b75c6fa653d3ac0c8bc9062939d293">GetTransformAlgorithm</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p177835378165634"><a name="p177835378165634"></a><a name="p177835378165634"></a>TransformAlgorithm </p>
<p id="p190116768165634"><a name="p190116768165634"></a><a name="p190116768165634"></a>Obtains the algorithm used for image rotation and scaling. </p>
</td>
</tr>
<tr id="row440107381165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1522849974165634"><a name="p1522849974165634"></a><a name="p1522849974165634"></a><a href="graphic.md#ga3824befafd4f4dda003195ca2bbef399">GetPath</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1168620955165634"><a name="p1168620955165634"></a><a name="p1168620955165634"></a>const char * </p>
<p id="p1899214655165634"><a name="p1899214655165634"></a><a name="p1899214655165634"></a>Obtains the image path.</p>
</td>
</tr>
<tr id="row655371162165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p685346694165634"><a name="p685346694165634"></a><a name="p685346694165634"></a><a href="graphic.md#gaa9fbde27be3e3ea2fc6b4dabbf588af8">GetImageInfo</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p847284989165634"><a name="p847284989165634"></a><a name="p847284989165634"></a>const <a href="ohos-imageinfo.md">ImageInfo</a> * </p>
<p id="p888447733165634"><a name="p888447733165634"></a><a name="p888447733165634"></a>Obtains image information.</p>
</td>
</tr>
<tr id="row786456574165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p978715929165634"><a name="p978715929165634"></a><a name="p978715929165634"></a><a href="graphic.md#ga07da08c8507a3dbee5c21ea0de170a16">GetSrcType</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p376619184165634"><a name="p376619184165634"></a><a name="p376619184165634"></a>uint8_t </p>
<p id="p977651435165634"><a name="p977651435165634"></a><a name="p977651435165634"></a>Obtains the image type.</p>
</td>
</tr>
<tr id="row1757848439165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2059939207165634"><a name="p2059939207165634"></a><a name="p2059939207165634"></a><a href="graphic.md#ga7aad5b50d945efe5f9304bc978b2001c">UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1890453328165634"><a name="p1890453328165634"></a><a name="p1890453328165634"></a> </p>
<p id="p1363225450165634"><a name="p1363225450165634"></a><a name="p1363225450165634"></a>A default constructor used to create an <strong id="b2113252224165634"><a name="b2113252224165634"></a><a name="b2113252224165634"></a><a href="ohos-uiview.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row1074379672165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p187737092165634"><a name="p187737092165634"></a><a name="p187737092165634"></a><a href="graphic.md#ga57d429bb1cd71782f3b825f1bc6b9362">UIView</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p547271167165634"><a name="p547271167165634"></a><a name="p547271167165634"></a> </p>
<p id="p548341697165634"><a name="p548341697165634"></a><a name="p548341697165634"></a>A constructor used to create an <strong id="b521755490165634"><a name="b521755490165634"></a><a name="b521755490165634"></a><a href="ohos-uiview.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row1591711049165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1241847608165634"><a name="p1241847608165634"></a><a name="p1241847608165634"></a><a href="graphic.md#ga17f0ffc1090bdcce0f88288da5962012">~UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p433100409165634"><a name="p433100409165634"></a><a name="p433100409165634"></a>virtual </p>
<p id="p24059597165634"><a name="p24059597165634"></a><a name="p24059597165634"></a>A destructor used to delete the <strong id="b2021388880165634"><a name="b2021388880165634"></a><a name="b2021388880165634"></a><a href="ohos-uiview.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row2046209347165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p133786594165634"><a name="p133786594165634"></a><a name="p133786594165634"></a><a href="graphic.md#gab70473cd0d8fe7c9d4bb817caeee9153">OnPostDraw</a> (const <a href="ohos-rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p60453016165634"><a name="p60453016165634"></a><a name="p60453016165634"></a>virtual void </p>
<p id="p1904345584165634"><a name="p1904345584165634"></a><a name="p1904345584165634"></a>Called after a view is drawn. </p>
</td>
</tr>
<tr id="row1881769568165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p580837972165634"><a name="p580837972165634"></a><a name="p580837972165634"></a><a href="graphic.md#ga2a9a38b8450fbb196277238a51fbbf99">Invalidate</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p775763261165634"><a name="p775763261165634"></a><a name="p775763261165634"></a>void </p>
<p id="p1496232782165634"><a name="p1496232782165634"></a><a name="p1496232782165634"></a>Refreshes the invalidated area of the view. </p>
</td>
</tr>
<tr id="row1386837250165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p682402097165634"><a name="p682402097165634"></a><a name="p682402097165634"></a><a href="graphic.md#gaf0e6b65ced8b931642f2a80c195962d2">InvalidateRect</a> (const <a href="ohos-rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1659770571165634"><a name="p1659770571165634"></a><a name="p1659770571165634"></a>void </p>
<p id="p1185249209165634"><a name="p1185249209165634"></a><a name="p1185249209165634"></a>Refreshes a view in a specified invalidated area. </p>
</td>
</tr>
<tr id="row1513568200165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p393687284165634"><a name="p393687284165634"></a><a name="p393687284165634"></a><a href="graphic.md#gac311aa47301d727c35fc31f8630d016e">OnLongPressEvent</a> (const <a href="ohos-longpressevent.md">LongPressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p843117088165634"><a name="p843117088165634"></a><a name="p843117088165634"></a>virtual bool </p>
<p id="p1368027314165634"><a name="p1368027314165634"></a><a name="p1368027314165634"></a>Called when the view is long pressed. </p>
</td>
</tr>
<tr id="row1247454928165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p595528898165634"><a name="p595528898165634"></a><a name="p595528898165634"></a><a href="graphic.md#gac0e10556ff99b8a92bfb11df6456d605">OnDragStartEvent</a> (const <a href="ohos-dragevent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p409995922165634"><a name="p409995922165634"></a><a name="p409995922165634"></a>virtual bool </p>
<p id="p671508831165634"><a name="p671508831165634"></a><a name="p671508831165634"></a>Called when the view starts to drag. </p>
</td>
</tr>
<tr id="row1005522253165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1645333100165634"><a name="p1645333100165634"></a><a name="p1645333100165634"></a><a href="graphic.md#ga46249c8caf06b81590d9450e30a31147">OnDragEvent</a> (const <a href="ohos-dragevent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1339612098165634"><a name="p1339612098165634"></a><a name="p1339612098165634"></a>virtual bool </p>
<p id="p2128559433165634"><a name="p2128559433165634"></a><a name="p2128559433165634"></a>Called when the view is being dragged. </p>
</td>
</tr>
<tr id="row1291751333165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1980335302165634"><a name="p1980335302165634"></a><a name="p1980335302165634"></a><a href="graphic.md#ga1799d33be73f64ed2066f50d7e65468d">OnDragEndEvent</a> (const <a href="ohos-dragevent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1619662113165634"><a name="p1619662113165634"></a><a name="p1619662113165634"></a>virtual bool </p>
<p id="p1441443141165634"><a name="p1441443141165634"></a><a name="p1441443141165634"></a>Called when the view stops dragging. </p>
</td>
</tr>
<tr id="row996578669165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p329316812165634"><a name="p329316812165634"></a><a name="p329316812165634"></a><a href="graphic.md#gad08697a29aae4c58267f494b66b9a547">OnClickEvent</a> (const <a href="ohos-clickevent.md">ClickEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2029753790165634"><a name="p2029753790165634"></a><a name="p2029753790165634"></a>virtual void </p>
<p id="p573337913165634"><a name="p573337913165634"></a><a name="p573337913165634"></a>Called when the view is clicked. </p>
</td>
</tr>
<tr id="row716678582165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p648818539165634"><a name="p648818539165634"></a><a name="p648818539165634"></a><a href="graphic.md#gafa544ff2d27785a9410a80689f1ad3b1">OnPressEvent</a> (const <a href="ohos-pressevent.md">PressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2108476209165634"><a name="p2108476209165634"></a><a name="p2108476209165634"></a>virtual void </p>
<p id="p1424435367165634"><a name="p1424435367165634"></a><a name="p1424435367165634"></a>Called when the view is pressed. </p>
</td>
</tr>
<tr id="row1947168290165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1422158477165634"><a name="p1422158477165634"></a><a name="p1422158477165634"></a><a href="graphic.md#ga7bd1a74563b059b03fbf66f9add53ee3">OnReleaseEvent</a> (const <a href="ohos-releaseevent.md">ReleaseEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1947688848165634"><a name="p1947688848165634"></a><a name="p1947688848165634"></a>virtual void </p>
<p id="p937792832165634"><a name="p937792832165634"></a><a name="p937792832165634"></a>Called when the view is released. </p>
</td>
</tr>
<tr id="row1294135731165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1953094005165634"><a name="p1953094005165634"></a><a name="p1953094005165634"></a><a href="graphic.md#ga8f01ff25a33b20df0758f564148e579d">OnCancelEvent</a> (const <a href="ohos-cancelevent.md">CancelEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p96601604165634"><a name="p96601604165634"></a><a name="p96601604165634"></a>virtual void </p>
<p id="p1553756825165634"><a name="p1553756825165634"></a><a name="p1553756825165634"></a>Called when a click event on the view is canceled. </p>
</td>
</tr>
<tr id="row814076565165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p484317829165634"><a name="p484317829165634"></a><a name="p484317829165634"></a><a href="graphic.md#gad8e3cf5f0dd003a6aa932ef04e7b59f2">SetOnDragListener</a> (<a href="ohos-uiview-ondraglistener.md">OnDragListener</a> *onDragListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p229304297165634"><a name="p229304297165634"></a><a name="p229304297165634"></a>void </p>
<p id="p1904662687165634"><a name="p1904662687165634"></a><a name="p1904662687165634"></a>Sets a drag event listener for the view. </p>
</td>
</tr>
<tr id="row2100248548165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1439873456165634"><a name="p1439873456165634"></a><a name="p1439873456165634"></a><a href="graphic.md#ga45a02cba4887c5c0b8e243941bcdc5cb">GetOnDragListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p368082903165634"><a name="p368082903165634"></a><a name="p368082903165634"></a><a href="ohos-uiview-ondraglistener.md">OnDragListener</a> *&amp; </p>
<p id="p1694363617165634"><a name="p1694363617165634"></a><a name="p1694363617165634"></a>Obtains the drag event listener for the view. </p>
</td>
</tr>
<tr id="row880587068165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1146502251165634"><a name="p1146502251165634"></a><a name="p1146502251165634"></a><a href="graphic.md#ga4564bf8d8c7184e9c02bf33c9e171fa3">SetOnClickListener</a> (<a href="ohos-uiview-onclicklistener.md">OnClickListener</a> *onClickListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1553323669165634"><a name="p1553323669165634"></a><a name="p1553323669165634"></a>void </p>
<p id="p1459537726165634"><a name="p1459537726165634"></a><a name="p1459537726165634"></a>Sets a click event listener for the view. </p>
</td>
</tr>
<tr id="row392256409165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1306346421165634"><a name="p1306346421165634"></a><a name="p1306346421165634"></a><a href="graphic.md#ga35e885cb380c37245fa4305bba10cd4a">GetOnClickListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1658769783165634"><a name="p1658769783165634"></a><a name="p1658769783165634"></a><a href="ohos-uiview-onclicklistener.md">OnClickListener</a> *&amp; </p>
<p id="p281541484165634"><a name="p281541484165634"></a><a name="p281541484165634"></a>Obtains the click event listener for the view. </p>
</td>
</tr>
<tr id="row230919565165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p680191623165634"><a name="p680191623165634"></a><a name="p680191623165634"></a><a href="graphic.md#gabcbe7a0adce600424f7f0d5a7396eb5b">SetOnLongPressListener</a> (<a href="ohos-uiview-onlongpresslistener.md">OnLongPressListener</a> *onLongPressListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p351132454165634"><a name="p351132454165634"></a><a name="p351132454165634"></a>void </p>
<p id="p1693793024165634"><a name="p1693793024165634"></a><a name="p1693793024165634"></a>Sets a long-press event listener for the view. </p>
</td>
</tr>
<tr id="row2112764132165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p848989878165634"><a name="p848989878165634"></a><a name="p848989878165634"></a><a href="graphic.md#gaafd4d354f5f111e758d046109fd7f656">GetOnLongPressListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1704839781165634"><a name="p1704839781165634"></a><a name="p1704839781165634"></a><a href="ohos-uiview-onlongpresslistener.md">OnLongPressListener</a> *&amp; </p>
<p id="p2146055395165634"><a name="p2146055395165634"></a><a name="p2146055395165634"></a>Obtains the long-press event listener for the view. </p>
</td>
</tr>
<tr id="row1561802900165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1102116029165634"><a name="p1102116029165634"></a><a name="p1102116029165634"></a><a href="graphic.md#gadd697fbf481f98d9d6ca8b67390071af">SetOnTouchListener</a> (<a href="ohos-uiview-ontouchlistener.md">OnTouchListener</a> *onTouchListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1033321136165634"><a name="p1033321136165634"></a><a name="p1033321136165634"></a>void </p>
<p id="p873757249165634"><a name="p873757249165634"></a><a name="p873757249165634"></a>Sets a touch event listener for the view. </p>
</td>
</tr>
<tr id="row1953162874165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p286305563165634"><a name="p286305563165634"></a><a name="p286305563165634"></a><a href="graphic.md#gae7c65c68653103dae85acdcef78777a6">GetTouchListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1085128625165634"><a name="p1085128625165634"></a><a name="p1085128625165634"></a><a href="ohos-uiview-ontouchlistener.md">OnTouchListener</a> *&amp; </p>
<p id="p625003563165634"><a name="p625003563165634"></a><a name="p625003563165634"></a>Obtains the touch event listener for the view. </p>
</td>
</tr>
<tr id="row1669030155165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2000723324165634"><a name="p2000723324165634"></a><a name="p2000723324165634"></a><a href="graphic.md#gaea9f334f2481e1c03a2cd8f3078d7c72">GetTargetView</a> (const <a href="ohos-point.md">Point</a> &amp;point, <a href="ohos-uiview.md">UIView</a> **last)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1150623296165634"><a name="p1150623296165634"></a><a name="p1150623296165634"></a>virtual void </p>
<p id="p1344222594165634"><a name="p1344222594165634"></a><a name="p1344222594165634"></a>Obtains the top-level view based on specified coordinates. </p>
</td>
</tr>
<tr id="row630141544165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1157700279165634"><a name="p1157700279165634"></a><a name="p1157700279165634"></a><a href="graphic.md#gaeea67a3a84b4ffe9bfeda418b82184cc">SetParent</a> (<a href="ohos-uiview.md">UIView</a> *parent)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1445725006165634"><a name="p1445725006165634"></a><a name="p1445725006165634"></a>void </p>
<p id="p1599493298165634"><a name="p1599493298165634"></a><a name="p1599493298165634"></a>Sets the parent view for the view. </p>
</td>
</tr>
<tr id="row1605123867165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p652500601165634"><a name="p652500601165634"></a><a name="p652500601165634"></a><a href="graphic.md#ga706530e4a38108615d5e0c918685ec96">GetParent</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2012188725165634"><a name="p2012188725165634"></a><a name="p2012188725165634"></a><a href="ohos-uiview.md">UIView</a> * </p>
<p id="p1983591400165634"><a name="p1983591400165634"></a><a name="p1983591400165634"></a>Obtains the parent view of the view. </p>
</td>
</tr>
<tr id="row1983581590165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1462918553165634"><a name="p1462918553165634"></a><a name="p1462918553165634"></a><a href="graphic.md#ga02bec5de07d93cabc45affba79eba4ad">SetNextSibling</a> (<a href="ohos-uiview.md">UIView</a> *sibling)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p639655490165634"><a name="p639655490165634"></a><a name="p639655490165634"></a>void </p>
<p id="p1977700249165634"><a name="p1977700249165634"></a><a name="p1977700249165634"></a>Sets the next sibling view for the view. </p>
</td>
</tr>
<tr id="row179722813165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1709126644165634"><a name="p1709126644165634"></a><a name="p1709126644165634"></a><a href="graphic.md#gab0030977b30ddc9f2e15dbc2f58937e6">GetNextSibling</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p340501892165634"><a name="p340501892165634"></a><a name="p340501892165634"></a><a href="ohos-uiview.md">UIView</a> * </p>
<p id="p1868385073165634"><a name="p1868385073165634"></a><a name="p1868385073165634"></a>Obtains the next sibling view of the view. </p>
</td>
</tr>
<tr id="row265982346165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p838598831165634"><a name="p838598831165634"></a><a name="p838598831165634"></a><a href="graphic.md#ga07e7e1f268bd6ce975f4f0f8487af5d0">SetVisible</a> (bool visible)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1962148374165634"><a name="p1962148374165634"></a><a name="p1962148374165634"></a>virtual void </p>
<p id="p1676867682165634"><a name="p1676867682165634"></a><a name="p1676867682165634"></a>Sets whether the view is visible. </p>
</td>
</tr>
<tr id="row1372205216165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1311193294165634"><a name="p1311193294165634"></a><a name="p1311193294165634"></a><a href="graphic.md#gaee178fc0a86ac03a6bdf2ade0c1914c8">IsVisible</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p742980331165634"><a name="p742980331165634"></a><a name="p742980331165634"></a>bool </p>
<p id="p2060994844165634"><a name="p2060994844165634"></a><a name="p2060994844165634"></a>Checks whether the view is visible. </p>
</td>
</tr>
<tr id="row277955697165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1371057364165634"><a name="p1371057364165634"></a><a name="p1371057364165634"></a><a href="graphic.md#gaf9fb55fd9aa397f7158f1515e90bce02">SetTouchable</a> (bool touch)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p505045829165634"><a name="p505045829165634"></a><a name="p505045829165634"></a>void </p>
<p id="p230656002165634"><a name="p230656002165634"></a><a name="p230656002165634"></a>Sets whether the view is touchable. </p>
</td>
</tr>
<tr id="row876770609165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1130817371165634"><a name="p1130817371165634"></a><a name="p1130817371165634"></a><a href="graphic.md#ga502a53fb77b260fa36b5b3adf82e2340">IsTouchable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p684702535165634"><a name="p684702535165634"></a><a name="p684702535165634"></a>bool </p>
<p id="p259357013165634"><a name="p259357013165634"></a><a name="p259357013165634"></a>Checks whether the view is touchable. </p>
</td>
</tr>
<tr id="row1124544476165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1276485774165634"><a name="p1276485774165634"></a><a name="p1276485774165634"></a><a href="graphic.md#gab06abe0fe824c048f3b72974f9a8f0d0">SetDraggable</a> (bool draggable)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p964410624165634"><a name="p964410624165634"></a><a name="p964410624165634"></a>void </p>
<p id="p1666772360165634"><a name="p1666772360165634"></a><a name="p1666772360165634"></a>Sets whether the view is draggable. </p>
</td>
</tr>
<tr id="row101121289165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1511608288165634"><a name="p1511608288165634"></a><a name="p1511608288165634"></a><a href="graphic.md#ga25bb796ff400c767d622cbed280fc500">IsDraggable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1268657982165634"><a name="p1268657982165634"></a><a name="p1268657982165634"></a>bool </p>
<p id="p1913843375165634"><a name="p1913843375165634"></a><a name="p1913843375165634"></a>Checks whether the view is draggable. </p>
</td>
</tr>
<tr id="row1999391388165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p493050679165634"><a name="p493050679165634"></a><a name="p493050679165634"></a><a href="graphic.md#ga6c08e49bf7a82a7ebaef0f251e7a6f85">SetDragParentInstead</a> (bool dragParentInstead)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p859965011165634"><a name="p859965011165634"></a><a name="p859965011165634"></a>void </p>
<p id="p566474378165634"><a name="p566474378165634"></a><a name="p566474378165634"></a>Sets whether to transfer the drag event to the parent view for processing when the view is being dragged. </p>
</td>
</tr>
<tr id="row156018850165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p656734993165634"><a name="p656734993165634"></a><a name="p656734993165634"></a><a href="graphic.md#gaf0c462bc31e779b1898ad4cdfdad6faf">IsDragParentInstead</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p451451032165634"><a name="p451451032165634"></a><a name="p451451032165634"></a>bool </p>
<p id="p1084040837165634"><a name="p1084040837165634"></a><a name="p1084040837165634"></a>Obtains whether the view transfers a drag event to the parent view for processing. </p>
</td>
</tr>
<tr id="row10317254165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p711194285165634"><a name="p711194285165634"></a><a name="p711194285165634"></a><a href="graphic.md#ga86cb8d364f18494d67636c55babced5c">GetRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p568770156165634"><a name="p568770156165634"></a><a name="p568770156165634"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p1577809020165634"><a name="p1577809020165634"></a><a name="p1577809020165634"></a>Obtains the absolute rectangle area of the view. When the view has deformation such as rotation, the rectangle area is the intersection set of the absolute rectangle area and deformation matrix. </p>
</td>
</tr>
<tr id="row78276410165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p514205927165634"><a name="p514205927165634"></a><a name="p514205927165634"></a><a href="graphic.md#ga06e79704a19f2a238982076cac3d059b">GetVisibleRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1568256378165634"><a name="p1568256378165634"></a><a name="p1568256378165634"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p591189009165634"><a name="p591189009165634"></a><a name="p591189009165634"></a>Obtains the visible absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row872462278165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p818803585165634"><a name="p818803585165634"></a><a name="p818803585165634"></a><a href="graphic.md#gab3f8993b3953f27bfc61d53429916cba">GetMaskedRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p127815301165634"><a name="p127815301165634"></a><a name="p127815301165634"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p160242588165634"><a name="p160242588165634"></a><a name="p160242588165634"></a>Obtains the valid absolute rectangle area of the view. The valid area refers to the area where the view can be displayed. Generally, the valid area is the same as the visible view area, but they may be different in the grid layout. </p>
</td>
</tr>
<tr id="row834275531165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p943168054165634"><a name="p943168054165634"></a><a name="p943168054165634"></a><a href="graphic.md#ga64cf308a09999def1192f9c4e0f17f0a">GetOrigRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p38639305165634"><a name="p38639305165634"></a><a name="p38639305165634"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p565366075165634"><a name="p565366075165634"></a><a name="p565366075165634"></a>Obtains the absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row82710872165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1130092932165634"><a name="p1130092932165634"></a><a name="p1130092932165634"></a><a href="graphic.md#ga9db88eae712676359d02a92be14fa316">GetContentRect</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p758397834165634"><a name="p758397834165634"></a><a name="p758397834165634"></a>virtual <a href="ohos-rect.md">Rect</a> </p>
<p id="p1570896865165634"><a name="p1570896865165634"></a><a name="p1570896865165634"></a>Obtains the content of the absolute rectangle area of the view. This area excludes padding. </p>
</td>
</tr>
<tr id="row1726645066165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1246251225165634"><a name="p1246251225165634"></a><a name="p1246251225165634"></a><a href="graphic.md#gae9b96837fa1d45648a2a6fbbfcc5eb4a">GetRelativeRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p725669796165634"><a name="p725669796165634"></a><a name="p725669796165634"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p487870426165634"><a name="p487870426165634"></a><a name="p487870426165634"></a>Obtains the rectangular area of the view relative to the parent view, that is, the rectangular area relative to the coordinates of the parent view. </p>
</td>
</tr>
<tr id="row1162164665165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1750785407165634"><a name="p1750785407165634"></a><a name="p1750785407165634"></a><a href="graphic.md#gae6c5f3bcf99dc837bcecd60c38d3df5a">ResizeVisibleArea</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1455820922165634"><a name="p1455820922165634"></a><a name="p1455820922165634"></a>void </p>
<p id="p1199876382165634"><a name="p1199876382165634"></a><a name="p1199876382165634"></a>Adjusts the size of the visible area. This operation may affect the final display size. </p>
</td>
</tr>
<tr id="row113687404165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p195766740165634"><a name="p195766740165634"></a><a name="p195766740165634"></a><a href="graphic.md#ga3375ec5ef059fd88c657af4552d2fa4f">SetWidth</a> (int16_t width)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p684889762165634"><a name="p684889762165634"></a><a name="p684889762165634"></a>virtual void </p>
<p id="p155645193165634"><a name="p155645193165634"></a><a name="p155645193165634"></a>Sets the width for the view. </p>
</td>
</tr>
<tr id="row2005560319165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p792905287165634"><a name="p792905287165634"></a><a name="p792905287165634"></a><a href="graphic.md#ga9c7110620d5dc3a7bd3efe1fc2edd125">SetHeight</a> (int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1351990544165634"><a name="p1351990544165634"></a><a name="p1351990544165634"></a>virtual void </p>
<p id="p472036706165634"><a name="p472036706165634"></a><a name="p472036706165634"></a>Sets the height for the view. </p>
</td>
</tr>
<tr id="row1457281248165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1682047406165634"><a name="p1682047406165634"></a><a name="p1682047406165634"></a><a href="graphic.md#gae985b607d2f0701911778bf20d640ccd">Resize</a> (int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2093633781165634"><a name="p2093633781165634"></a><a name="p2093633781165634"></a>virtual void </p>
<p id="p1194665976165634"><a name="p1194665976165634"></a><a name="p1194665976165634"></a>Adjusts the size of the view. </p>
</td>
</tr>
<tr id="row1579373658165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1354902640165634"><a name="p1354902640165634"></a><a name="p1354902640165634"></a><a href="graphic.md#gaded403626558d28e62bf5632ccbb24b5">SetX</a> (int16_t x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1966654344165634"><a name="p1966654344165634"></a><a name="p1966654344165634"></a>virtual void </p>
<p id="p637085136165634"><a name="p637085136165634"></a><a name="p637085136165634"></a>Sets the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row874695636165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p325660328165634"><a name="p325660328165634"></a><a name="p325660328165634"></a><a href="graphic.md#ga89dc5f8fb1cb4b2259dc0439185359f1">GetX</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p527034682165634"><a name="p527034682165634"></a><a name="p527034682165634"></a>int16_t </p>
<p id="p1191757613165634"><a name="p1191757613165634"></a><a name="p1191757613165634"></a>Obtains the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row1100527874165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p829785116165634"><a name="p829785116165634"></a><a name="p829785116165634"></a><a href="graphic.md#gaaa8edc224cf1c7deb2724fb225960877">SetY</a> (int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1078931603165634"><a name="p1078931603165634"></a><a name="p1078931603165634"></a>virtual void </p>
<p id="p271244460165634"><a name="p271244460165634"></a><a name="p271244460165634"></a>Sets the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row582410328165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p817526412165634"><a name="p817526412165634"></a><a name="p817526412165634"></a><a href="graphic.md#ga193619d649204b0e9bb854d3b30275c3">GetY</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p388876182165634"><a name="p388876182165634"></a><a name="p388876182165634"></a>int16_t </p>
<p id="p1081312308165634"><a name="p1081312308165634"></a><a name="p1081312308165634"></a>Obtains the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row2090881575165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1484309497165634"><a name="p1484309497165634"></a><a name="p1484309497165634"></a><a href="graphic.md#gab34233f6aeae330b025969137d03e67a">SetPosition</a> (int16_t x, int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1845755524165634"><a name="p1845755524165634"></a><a name="p1845755524165634"></a>virtual void </p>
<p id="p970548041165634"><a name="p970548041165634"></a><a name="p970548041165634"></a>Sets the position for the view. </p>
</td>
</tr>
<tr id="row1830723385165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1365676315165634"><a name="p1365676315165634"></a><a name="p1365676315165634"></a><a href="graphic.md#gaf8ce4c009f23b7175b2b34bac4a74262">SetPosition</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p542478669165634"><a name="p542478669165634"></a><a name="p542478669165634"></a>virtual void </p>
<p id="p110553247165634"><a name="p110553247165634"></a><a name="p110553247165634"></a>Adjusts the position and size of the view. </p>
</td>
</tr>
<tr id="row881892466165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p448247084165634"><a name="p448247084165634"></a><a name="p448247084165634"></a><a href="graphic.md#gab2ce8c11abbd55f40687f38a52511b11">IsViewGroup</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1699093141165634"><a name="p1699093141165634"></a><a name="p1699093141165634"></a>bool </p>
<p id="p1042222156165634"><a name="p1042222156165634"></a><a name="p1042222156165634"></a>Checks whether the view is a container view. </p>
</td>
</tr>
<tr id="row929880986165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1744423863165634"><a name="p1744423863165634"></a><a name="p1744423863165634"></a><a href="graphic.md#ga980fc6824c64cfae6af8657aee17af88">SetIntercept</a> (bool isIntercept)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1209380365165634"><a name="p1209380365165634"></a><a name="p1209380365165634"></a>void </p>
<p id="p2066076968165634"><a name="p2066076968165634"></a><a name="p2066076968165634"></a>Sets whether to intercept the drag event. If intercepted, the view does not transfer the drag event to the parent view after local processing. </p>
</td>
</tr>
<tr id="row1800366883165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1273446527165634"><a name="p1273446527165634"></a><a name="p1273446527165634"></a><a href="graphic.md#ga8623abbbeff458c0cb2d7dc0d1f21e4a">SetTransformMap</a> (const <a href="ohos-transformmap.md">TransformMap</a> &amp;transMap)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1913258518165634"><a name="p1913258518165634"></a><a name="p1913258518165634"></a>void </p>
<p id="p78626917165634"><a name="p78626917165634"></a><a name="p78626917165634"></a>Sets the affine transformation matrix. </p>
</td>
</tr>
<tr id="row981688629165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p98372242165634"><a name="p98372242165634"></a><a name="p98372242165634"></a><a href="graphic.md#gab8cee5a7052a88722768c8ed1324abc1">GetTransformMap</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1308057109165634"><a name="p1308057109165634"></a><a name="p1308057109165634"></a><a href="ohos-transformmap.md">TransformMap</a> &amp; </p>
<p id="p2088736008165634"><a name="p2088736008165634"></a><a name="p2088736008165634"></a>Obtains an affine transformation matrix. </p>
</td>
</tr>
<tr id="row208437178165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p779132858165634"><a name="p779132858165634"></a><a name="p779132858165634"></a><a href="graphic.md#ga0573aa25307c22319db4629781b5cad2">GetChildById</a> (const char *id) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p623374129165634"><a name="p623374129165634"></a><a name="p623374129165634"></a>virtual <a href="ohos-uiview.md">UIView</a> * </p>
<p id="p738681607165634"><a name="p738681607165634"></a><a name="p738681607165634"></a>Obtains the child view of a specified ID. </p>
</td>
</tr>
<tr id="row1052944180165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1339341130165634"><a name="p1339341130165634"></a><a name="p1339341130165634"></a><a href="graphic.md#ga0caaa15c9b304673331e778a266be77f">SetViewId</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1650771724165634"><a name="p1650771724165634"></a><a name="p1650771724165634"></a>void </p>
<p id="p1186628683165634"><a name="p1186628683165634"></a><a name="p1186628683165634"></a>Sets the view ID. </p>
</td>
</tr>
<tr id="row1231155465165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1113022483165634"><a name="p1113022483165634"></a><a name="p1113022483165634"></a><a href="graphic.md#gad6c7644bd2abfa3c92d80776b0bd1936">GetViewId</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p458939760165634"><a name="p458939760165634"></a><a name="p458939760165634"></a>const char * </p>
<p id="p634344800165634"><a name="p634344800165634"></a><a name="p634344800165634"></a>Obtains the view ID. </p>
</td>
</tr>
<tr id="row2087342850165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p22870733165634"><a name="p22870733165634"></a><a name="p22870733165634"></a><a href="graphic.md#ga77a961aa53567c5214508b4569801c16">SetViewIndex</a> (int16_t <a href="utils.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1615588343165634"><a name="p1615588343165634"></a><a name="p1615588343165634"></a>void </p>
<p id="p312547968165634"><a name="p312547968165634"></a><a name="p312547968165634"></a>Sets the view index. </p>
</td>
</tr>
<tr id="row1929792054165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p943744959165634"><a name="p943744959165634"></a><a name="p943744959165634"></a><a href="graphic.md#ga62f51715b6d420a296ebe0296717b906">GetViewIndex</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1847329259165634"><a name="p1847329259165634"></a><a name="p1847329259165634"></a>int16_t </p>
<p id="p37232319165634"><a name="p37232319165634"></a><a name="p37232319165634"></a>Obtains the view index. </p>
</td>
</tr>
<tr id="row1249779675165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p948528241165634"><a name="p948528241165634"></a><a name="p948528241165634"></a><a href="graphic.md#gaca871fa2f8219e7ea9388e212d1f1e69">LayoutChildren</a> (bool neeInvalidate=false)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1497597407165634"><a name="p1497597407165634"></a><a name="p1497597407165634"></a>virtual void </p>
<p id="p2111410002165634"><a name="p2111410002165634"></a><a name="p2111410002165634"></a>Lays out all child views according to the preset arrangement mode. </p>
</td>
</tr>
<tr id="row1930558980165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p98614607165634"><a name="p98614607165634"></a><a name="p98614607165634"></a><a href="graphic.md#ga443b86ee9275b0421b37a47bad3264dc">LayoutCenterOfParent</a> (int16_t xOffSet=0, int16_t yOffset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1093110430165634"><a name="p1093110430165634"></a><a name="p1093110430165634"></a>void </p>
<p id="p813116533165634"><a name="p813116533165634"></a><a name="p813116533165634"></a>Lays out the view in the center of the parent view. </p>
</td>
</tr>
<tr id="row446605968165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p95429536165634"><a name="p95429536165634"></a><a name="p95429536165634"></a><a href="graphic.md#ga94999b271f27cd5d6bfaf303f7d5c708">LayoutLeftOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2017664166165634"><a name="p2017664166165634"></a><a name="p2017664166165634"></a>void </p>
<p id="p1215236822165634"><a name="p1215236822165634"></a><a name="p1215236822165634"></a>Lays out the view on the left of the parent view. </p>
</td>
</tr>
<tr id="row97891256165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1658200499165634"><a name="p1658200499165634"></a><a name="p1658200499165634"></a><a href="graphic.md#ga479528ed259b5539e423955f2b60517d">LayoutRightOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2102759143165634"><a name="p2102759143165634"></a><a name="p2102759143165634"></a>void </p>
<p id="p1984172786165634"><a name="p1984172786165634"></a><a name="p1984172786165634"></a>Lays out the view on the right of the parent view. </p>
</td>
</tr>
<tr id="row581092839165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p384590900165634"><a name="p384590900165634"></a><a name="p384590900165634"></a><a href="graphic.md#ga859288ea61ad23ba7e381bbc07769e83">LayoutTopOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p453204288165634"><a name="p453204288165634"></a><a name="p453204288165634"></a>void </p>
<p id="p1102919906165634"><a name="p1102919906165634"></a><a name="p1102919906165634"></a>Lays out the view on the top of the parent view. </p>
</td>
</tr>
<tr id="row1824555330165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1570263756165634"><a name="p1570263756165634"></a><a name="p1570263756165634"></a><a href="graphic.md#ga809aeee4792ae58218a0bcfcb94d5cdc">LayoutBottomOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p31224992165634"><a name="p31224992165634"></a><a name="p31224992165634"></a>void </p>
<p id="p1927498039165634"><a name="p1927498039165634"></a><a name="p1927498039165634"></a>Lays out the view on the bottom of the parent view. </p>
</td>
</tr>
<tr id="row750989831165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p921682058165634"><a name="p921682058165634"></a><a name="p921682058165634"></a><a href="graphic.md#gac7f5f2584c716a56fee3783f8dea6246">AlignLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p157600238165634"><a name="p157600238165634"></a><a name="p157600238165634"></a>void </p>
<p id="p1679055798165634"><a name="p1679055798165634"></a><a name="p1679055798165634"></a>Aligns the view with the left of a sibling view. </p>
</td>
</tr>
<tr id="row232042966165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p264130202165634"><a name="p264130202165634"></a><a name="p264130202165634"></a><a href="graphic.md#gabb1ac454cdf95593c1e387d5e272433c">AlignRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p165493601165634"><a name="p165493601165634"></a><a name="p165493601165634"></a>void </p>
<p id="p674786799165634"><a name="p674786799165634"></a><a name="p674786799165634"></a>Aligns the view with the right of a sibling view. </p>
</td>
</tr>
<tr id="row639689366165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1303540044165634"><a name="p1303540044165634"></a><a name="p1303540044165634"></a><a href="graphic.md#ga903d7cbc59bac06d728b7f6435c9a504">AlignTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1334116414165634"><a name="p1334116414165634"></a><a name="p1334116414165634"></a>void </p>
<p id="p166343237165634"><a name="p166343237165634"></a><a name="p166343237165634"></a>Aligns the view with the top of a sibling view. </p>
</td>
</tr>
<tr id="row395506330165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p427169252165634"><a name="p427169252165634"></a><a name="p427169252165634"></a><a href="graphic.md#ga7607c3f9661932c495d080e9d92fb1a3">AlignBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p342758156165634"><a name="p342758156165634"></a><a name="p342758156165634"></a>void </p>
<p id="p604769141165634"><a name="p604769141165634"></a><a name="p604769141165634"></a>Aligns the view with the bottom of a sibling view. </p>
</td>
</tr>
<tr id="row1172142763165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p158012259165634"><a name="p158012259165634"></a><a name="p158012259165634"></a><a href="graphic.md#gac23776dbc2fce7ff30d57438abfa5230">AlignHorCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1567835316165634"><a name="p1567835316165634"></a><a name="p1567835316165634"></a>void </p>
<p id="p1185292068165634"><a name="p1185292068165634"></a><a name="p1185292068165634"></a>Aligns the view with the center of a sibling view in the x-axis. </p>
</td>
</tr>
<tr id="row618402413165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1073410726165634"><a name="p1073410726165634"></a><a name="p1073410726165634"></a><a href="graphic.md#gad3caa27aa0cb73ec4656e7d23aa222de">AlignVerCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p587810440165634"><a name="p587810440165634"></a><a name="p587810440165634"></a>void </p>
<p id="p591905797165634"><a name="p591905797165634"></a><a name="p591905797165634"></a>Aligns the view with the center of a sibling view in the y-axis. </p>
</td>
</tr>
<tr id="row1775196904165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p887207848165634"><a name="p887207848165634"></a><a name="p887207848165634"></a><a href="graphic.md#ga58f1a34a943c4492970f901d63bbc3d8">LayoutLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p230064019165634"><a name="p230064019165634"></a><a name="p230064019165634"></a>void </p>
<p id="p2052548911165634"><a name="p2052548911165634"></a><a name="p2052548911165634"></a>Lays out the view on the left of a sibling view. </p>
</td>
</tr>
<tr id="row1410279682165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p214989929165634"><a name="p214989929165634"></a><a name="p214989929165634"></a><a href="graphic.md#gac4cd64de5291759add164825a323a0d6">LayoutRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p810714966165634"><a name="p810714966165634"></a><a name="p810714966165634"></a>void </p>
<p id="p1987886041165634"><a name="p1987886041165634"></a><a name="p1987886041165634"></a>Lays out the view on the right of a sibling view. </p>
</td>
</tr>
<tr id="row456615834165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1170246454165634"><a name="p1170246454165634"></a><a name="p1170246454165634"></a><a href="graphic.md#gaaa8385807e3a9bea46f8dcc326252a70">LayoutTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p288342075165634"><a name="p288342075165634"></a><a name="p288342075165634"></a>void </p>
<p id="p809156907165634"><a name="p809156907165634"></a><a name="p809156907165634"></a>Lays out the view on the above of a sibling view. </p>
</td>
</tr>
<tr id="row146793259165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1621168216165634"><a name="p1621168216165634"></a><a name="p1621168216165634"></a><a href="graphic.md#gaa23a68e8ef0fb13b362218e71cf67ace">LayoutBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p914482633165634"><a name="p914482633165634"></a><a name="p914482633165634"></a>void </p>
<p id="p552208311165634"><a name="p552208311165634"></a><a name="p552208311165634"></a>Lays out the view on the below of a sibling view. </p>
</td>
</tr>
<tr id="row1023263272165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p143331425165634"><a name="p143331425165634"></a><a name="p143331425165634"></a><a href="graphic.md#ga535942844ebee554d413e960634a2867">SetStyle</a> (<a href="ohos-style.md">Style</a> &amp;style)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p58216692165634"><a name="p58216692165634"></a><a name="p58216692165634"></a>void </p>
<p id="p370139853165634"><a name="p370139853165634"></a><a name="p370139853165634"></a>Sets the view style. </p>
</td>
</tr>
<tr id="row1258120508165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1041391534165634"><a name="p1041391534165634"></a><a name="p1041391534165634"></a><a href="graphic.md#ga0945c2f05815dc2e466ef9ceaca2f700">SetStyle</a> (uint8_t key, int64_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p352341367165634"><a name="p352341367165634"></a><a name="p352341367165634"></a>virtual void </p>
<p id="p1302798576165634"><a name="p1302798576165634"></a><a name="p1302798576165634"></a>Sets a style. </p>
</td>
</tr>
<tr id="row1277454314165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1339498244165634"><a name="p1339498244165634"></a><a name="p1339498244165634"></a><a href="graphic.md#ga4ea19bc9f4b487946c9e29e63b54a0e6">GetStyle</a> (uint8_t key) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p639885027165634"><a name="p639885027165634"></a><a name="p639885027165634"></a>virtual int64_t </p>
<p id="p168180368165634"><a name="p168180368165634"></a><a name="p168180368165634"></a>Obtains the value of a style. </p>
</td>
</tr>
<tr id="row702313030165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1066077702165634"><a name="p1066077702165634"></a><a name="p1066077702165634"></a><a href="graphic.md#ga1b28213d4c2cd0f8324bce3fe56eb7bb">GetStyleConst</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1637976440165634"><a name="p1637976440165634"></a><a name="p1637976440165634"></a>const <a href="ohos-style.md">Style</a> &amp; </p>
<p id="p844495338165634"><a name="p844495338165634"></a><a name="p844495338165634"></a>Obtains the view style. This function applies to scenarios where the style does not need to be modified, which saves memory. </p>
</td>
</tr>
<tr id="row440170032165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1470800028165634"><a name="p1470800028165634"></a><a name="p1470800028165634"></a><a href="graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2072604924165634"><a name="p2072604924165634"></a><a name="p2072604924165634"></a>void * </p>
<p id="p615475809165634"><a name="p615475809165634"></a><a name="p615475809165634"></a>Overrides the <strong id="b386737332165634"><a name="b386737332165634"></a><a name="b386737332165634"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row51308892165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p885437909165634"><a name="p885437909165634"></a><a name="p885437909165634"></a><a href="graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1061204173165634"><a name="p1061204173165634"></a><a name="p1061204173165634"></a>void </p>
<p id="p2121107279165634"><a name="p2121107279165634"></a><a name="p2121107279165634"></a>Overrides the <strong id="b1924050967165634"><a name="b1924050967165634"></a><a name="b1924050967165634"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

## Additional Inherited Members<a name="inherited"></a>

<a name="table438661091165634"></a>
<table><thead align="left"><tr id="row1406157270165634"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1943769817165634"><a name="p1943769817165634"></a><a name="p1943769817165634"></a>Additional Inherited Member Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1508623429165634"><a name="p1508623429165634"></a><a name="p1508623429165634"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1580865361165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1635974394165634"><a name="p1635974394165634"></a><a name="p1635974394165634"></a><a href="graphic.md#ga3e530646bd55e49f0e5b0052e121f040">imageWidth_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1463360816165634"><a name="p1463360816165634"></a><a name="p1463360816165634"></a>Represents the width of this image. </p>
</td>
</tr>
<tr id="row702592194165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1173394319165634"><a name="p1173394319165634"></a><a name="p1173394319165634"></a><a href="graphic.md#ga5a7112d86d7b11b904b57c853817621d">imageHeight_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1065962968165634"><a name="p1065962968165634"></a><a name="p1065962968165634"></a>Represents the height of this image. </p>
</td>
</tr>
<tr id="row1149073089165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1773706739165634"><a name="p1773706739165634"></a><a name="p1773706739165634"></a><a href="graphic.md#gac13c0b542f4d7f789754bacf572894b2">autoEnable_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1087420877165634"><a name="p1087420877165634"></a><a name="p1087420877165634"></a>Specifies whether automatic adaptation is enabled. </p>
</td>
</tr>
<tr id="row1251652104165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p904229592165634"><a name="p904229592165634"></a><a name="p904229592165634"></a><a href="graphic.md#ga687a71ca22c04a7e761969f1fab1b06f">needRefresh_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2104062540165634"><a name="p2104062540165634"></a><a name="p2104062540165634"></a>Specifies whether a refresh is needed. </p>
</td>
</tr>
<tr id="row1299371365165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1023886757165634"><a name="p1023886757165634"></a><a name="p1023886757165634"></a><a href="graphic.md#gacbbee3e74893c43864b116779d97ad09">colorFormat_</a>: 4</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1770283809165634"><a name="p1770283809165634"></a><a name="p1770283809165634"></a>Represents the color format of this image. </p>
</td>
</tr>
<tr id="row1996618841165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p174738321165634"><a name="p174738321165634"></a><a name="p174738321165634"></a><a href="graphic.md#ga1c57bd4af56c49a11060e32b6e33066c">blurLevel_</a>: 2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1270380577165634"><a name="p1270380577165634"></a><a name="p1270380577165634"></a>Represents the blur level of this image when it is rotated or scaled. </p>
</td>
</tr>
<tr id="row279739108165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p826992521165634"><a name="p826992521165634"></a><a name="p826992521165634"></a><a href="graphic.md#ga5a8f8683c377c59c6a3c193f18468e60">algorithm_</a>: 1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p446341726165634"><a name="p446341726165634"></a><a name="p446341726165634"></a>Represents the algorithm used for image rotation and scaling. </p>
</td>
</tr>
</tbody>
</table>

