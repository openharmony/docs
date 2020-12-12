# OHOS::UIImageAnimatorView<a name="ZH-CN_TOPIC_0000001054918179"></a>

-   [Overview](#section2142144765165634)
-   [Summary](#section176200730165634)
-   [Data Structures](#nested-classes)
-   [Public Member Functions](#pub-methods)
-   [Additional Inherited Members](#inherited)

## **Overview**<a name="section2142144765165634"></a>

**Related Modules:**

[Graphic](Graphic.md)

**Description:**

Represents an image animator. 

Images are switched at a specified interval to form an animator.

See also
:   [UIImageView](OHOS-UIImageView.md) 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section176200730165634"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table304846467165634"></a>
<table><thead align="left"><tr id="row947874033165634"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p727207303165634"><a name="p727207303165634"></a><a name="p727207303165634"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p258303728165634"><a name="p258303728165634"></a><a name="p258303728165634"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2077230357165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2014211125165634"><a name="p2014211125165634"></a><a name="p2014211125165634"></a><a href="OHOS-UIImageAnimatorView-AnimatorStopListener.md">AnimatorStopListener</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1266515151165634"><a name="p1266515151165634"></a><a name="p1266515151165634"></a>Represents a listener that contains a callback to be invoked when this animator stops. </p>
</td>
</tr>
</tbody>
</table>

## Public Member Functions<a name="pub-methods"></a>

<a name="table1392745979165634"></a>
<table><thead align="left"><tr id="row693909569165634"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p607462262165634"><a name="p607462262165634"></a><a name="p607462262165634"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1697496261165634"><a name="p1697496261165634"></a><a name="p1697496261165634"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row356116301165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p92307108165634"><a name="p92307108165634"></a><a name="p92307108165634"></a><a href="Graphic.md#ga0506b7e6730f07b6e78371b479326b54">UIImageAnimatorView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p58812458165634"><a name="p58812458165634"></a><a name="p58812458165634"></a> </p>
<p id="p1967916370165634"><a name="p1967916370165634"></a><a name="p1967916370165634"></a>A constructor used to create a <strong id="b2098183825165634"><a name="b2098183825165634"></a><a name="b2098183825165634"></a><a href="OHOS-UIImageAnimatorView.md">UIImageAnimatorView</a></strong> instance. </p>
</td>
</tr>
<tr id="row1003838019165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p827562412165634"><a name="p827562412165634"></a><a name="p827562412165634"></a><a href="Graphic.md#ga72c8450b3c27dd0429691667a6d66dd1">~UIImageAnimatorView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p416218676165634"><a name="p416218676165634"></a><a name="p416218676165634"></a>virtual </p>
<p id="p1322710439165634"><a name="p1322710439165634"></a><a name="p1322710439165634"></a>A destructor used to delete the <strong id="b699004170165634"><a name="b699004170165634"></a><a name="b699004170165634"></a><a href="OHOS-UIImageAnimatorView.md">UIImageAnimatorView</a></strong> instance. </p>
</td>
</tr>
<tr id="row250762773165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1656003366165634"><a name="p1656003366165634"></a><a name="p1656003366165634"></a><a href="Graphic.md#ga831167c9f5000af808638eac56d6ec19">GetViewType</a> () const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p437238821165634"><a name="p437238821165634"></a><a name="p437238821165634"></a>UIViewType </p>
<p id="p332856360165634"><a name="p332856360165634"></a><a name="p332856360165634"></a>Obtains the view type. </p>
</td>
</tr>
<tr id="row2008027675165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p312816919165634"><a name="p312816919165634"></a><a name="p312816919165634"></a><a href="Graphic.md#ga6d585adbcbd0d236df848b48ff1b7ece">SetImageAnimatorSrc</a> (const char *imageSrc, uint8_t imageNum, uint16_t timeOfUpdate)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1569074875165634"><a name="p1569074875165634"></a><a name="p1569074875165634"></a>void </p>
<p id="p1632983245165634"><a name="p1632983245165634"></a><a name="p1632983245165634"></a>Sets the images and speed for this animator. </p>
</td>
</tr>
<tr id="row765171354165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p261672012165634"><a name="p261672012165634"></a><a name="p261672012165634"></a><a href="Graphic.md#ga4b2c4bc9d0ab881439d5ec728adc0b1a">SetImageAnimatorSrc</a> (const char *imageSrc, uint8_t imageNum)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1243852762165634"><a name="p1243852762165634"></a><a name="p1243852762165634"></a>void </p>
<p id="p2064104587165634"><a name="p2064104587165634"></a><a name="p2064104587165634"></a>Sets the images for this animator. </p>
</td>
</tr>
<tr id="row319614565165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p784217712165634"><a name="p784217712165634"></a><a name="p784217712165634"></a><a href="Graphic.md#ga0ee52a2ca252957199034c1234dc4f64">SetTimeOfUpdate</a> (uint16_t timeOfUpdate)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1553223045165634"><a name="p1553223045165634"></a><a name="p1553223045165634"></a>void </p>
<p id="p1017664992165634"><a name="p1017664992165634"></a><a name="p1017664992165634"></a>Sets the speed for this animator. </p>
</td>
</tr>
<tr id="row1527879406165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p185508284165634"><a name="p185508284165634"></a><a name="p185508284165634"></a><a href="Graphic.md#ga24411b0b4d9f619532aa879ee6ee7af1">GetTimeOfUpdate</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p774597987165634"><a name="p774597987165634"></a><a name="p774597987165634"></a>uint16_t </p>
<p id="p1720305849165634"><a name="p1720305849165634"></a><a name="p1720305849165634"></a>Obtains the speed of this animator. </p>
</td>
</tr>
<tr id="row1230982252165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p844974620165634"><a name="p844974620165634"></a><a name="p844974620165634"></a><a href="Graphic.md#gad4bd7aaf1100aac86a2cde8728ae8ee0">SetTimeOfPause</a> (uint16_t timeOfPause)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1166055757165634"><a name="p1166055757165634"></a><a name="p1166055757165634"></a>void </p>
<p id="p333686573165634"><a name="p333686573165634"></a><a name="p333686573165634"></a>Sets the interval between two playbacks of an infinitely repeated animator. </p>
</td>
</tr>
<tr id="row528536148165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1208507506165634"><a name="p1208507506165634"></a><a name="p1208507506165634"></a><a href="Graphic.md#ga8bd6ba744209193fd1f3e630e6cf1c5a">GetTimeOfPause</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p146908866165634"><a name="p146908866165634"></a><a name="p146908866165634"></a>uint16_t </p>
<p id="p1051702615165634"><a name="p1051702615165634"></a><a name="p1051702615165634"></a>Obtains the interval between two playbacks of an infinitely repeated animator. </p>
</td>
</tr>
<tr id="row1054288852165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p385106048165634"><a name="p385106048165634"></a><a name="p385106048165634"></a><a href="Graphic.md#gadc1064a27f9b95a2797c33793b2110ee">GetImageAnimatorSrc</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p183894724165634"><a name="p183894724165634"></a><a name="p183894724165634"></a>const <a href="OHOS-ImageAnimatorInfo.md">ImageAnimatorInfo</a> * </p>
<p id="p1583892269165634"><a name="p1583892269165634"></a><a name="p1583892269165634"></a>Obtains the image array of this frame animator. </p>
</td>
</tr>
<tr id="row211397493165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p907588181165634"><a name="p907588181165634"></a><a name="p907588181165634"></a><a href="Graphic.md#ga1da191cab1e6b4ffb3a87b50fbe4f7ed">GetImageAnimatorImageNum</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p143396350165634"><a name="p143396350165634"></a><a name="p143396350165634"></a>uint8_t </p>
<p id="p1091349537165634"><a name="p1091349537165634"></a><a name="p1091349537165634"></a>Obtains the number of images. </p>
</td>
</tr>
<tr id="row1309216952165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1870179595165634"><a name="p1870179595165634"></a><a name="p1870179595165634"></a><a href="Graphic.md#ga0e41547fd9d55ff85d6b800e59957370">SetSizeFixed</a> (bool fixed)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p353673886165634"><a name="p353673886165634"></a><a name="p353673886165634"></a>void </p>
<p id="p578564977165634"><a name="p578564977165634"></a><a name="p578564977165634"></a>Sets whether the image size is fixed to the view size. </p>
</td>
</tr>
<tr id="row739417298165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p606320309165634"><a name="p606320309165634"></a><a name="p606320309165634"></a><a href="Graphic.md#gabf4bad201ee9ef8aa484677b1daa3ba4">IsSizeFixed</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1712358281165634"><a name="p1712358281165634"></a><a name="p1712358281165634"></a>bool </p>
<p id="p1660977154165634"><a name="p1660977154165634"></a><a name="p1660977154165634"></a>Checks whether the image size is fixed to the view size. </p>
</td>
</tr>
<tr id="row253462439165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1663642109165634"><a name="p1663642109165634"></a><a name="p1663642109165634"></a><a href="Graphic.md#ga0368d596c01e1a6093d7476fce548a38">SetRepeat</a> (bool repeat)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p18748019165634"><a name="p18748019165634"></a><a name="p18748019165634"></a>void </p>
<p id="p1949021914165634"><a name="p1949021914165634"></a><a name="p1949021914165634"></a>Sets whether to play this animator for infinite times. </p>
</td>
</tr>
<tr id="row1839130220165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1657005069165634"><a name="p1657005069165634"></a><a name="p1657005069165634"></a><a href="Graphic.md#ga5e3700fe3d572ed6329237480bd4b5d2">IsRepeat</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1168407231165634"><a name="p1168407231165634"></a><a name="p1168407231165634"></a>bool </p>
<p id="p671014970165634"><a name="p671014970165634"></a><a name="p671014970165634"></a>Checks whether this animator is played for infinite times. </p>
</td>
</tr>
<tr id="row913853368165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p613809268165634"><a name="p613809268165634"></a><a name="p613809268165634"></a><a href="Graphic.md#ga8d0a02c46af6bea17323c715620b6212">SetRepeatTimes</a> (uint32_t times)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1161990259165634"><a name="p1161990259165634"></a><a name="p1161990259165634"></a>void </p>
<p id="p1634426851165634"><a name="p1634426851165634"></a><a name="p1634426851165634"></a>Sets the playback times for this animator. </p>
</td>
</tr>
<tr id="row424259595165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1947869062165634"><a name="p1947869062165634"></a><a name="p1947869062165634"></a><a href="Graphic.md#gae900ab627983fb255dc0d1672c1f3a03">GetRepeatTimes</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p249033139165634"><a name="p249033139165634"></a><a name="p249033139165634"></a>uint32_t </p>
<p id="p952986990165634"><a name="p952986990165634"></a><a name="p952986990165634"></a>Obtains the playback times. </p>
</td>
</tr>
<tr id="row1479163608165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p596480713165634"><a name="p596480713165634"></a><a name="p596480713165634"></a><a href="Graphic.md#gaad46659a26146d0edccad42f45f85d6c">GetState</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p325401561165634"><a name="p325401561165634"></a><a name="p325401561165634"></a>uint8_t </p>
<p id="p77081124165634"><a name="p77081124165634"></a><a name="p77081124165634"></a>Obtains the current state of this animator. </p>
</td>
</tr>
<tr id="row1177664684165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1856378128165634"><a name="p1856378128165634"></a><a name="p1856378128165634"></a><a href="Graphic.md#ga38a53936c930f4d75ccd9d9c6a5b9afa">SetReverse</a> (bool reverse)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1080212223165634"><a name="p1080212223165634"></a><a name="p1080212223165634"></a>void </p>
<p id="p1421573815165634"><a name="p1421573815165634"></a><a name="p1421573815165634"></a>Sets the playback sequence for this animator. </p>
</td>
</tr>
<tr id="row1096340489165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1847989630165634"><a name="p1847989630165634"></a><a name="p1847989630165634"></a><a href="Graphic.md#ga35b508048046b7adf938de5cc4004724">IsReverse</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p280048385165634"><a name="p280048385165634"></a><a name="p280048385165634"></a>bool </p>
<p id="p1447139146165634"><a name="p1447139146165634"></a><a name="p1447139146165634"></a>Obtains the playback sequence of this animator. </p>
</td>
</tr>
<tr id="row524475291165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p245883070165634"><a name="p245883070165634"></a><a name="p245883070165634"></a><a href="Graphic.md#ga99fb1b9b27ee65f812085f93e05330a6">Start</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p695547394165634"><a name="p695547394165634"></a><a name="p695547394165634"></a>void </p>
<p id="p1144064908165634"><a name="p1144064908165634"></a><a name="p1144064908165634"></a>Starts this animator. </p>
</td>
</tr>
<tr id="row1569821684165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p952148761165634"><a name="p952148761165634"></a><a name="p952148761165634"></a><a href="Graphic.md#ga1887f1afd8e85c0a9c781e182fe5afc3">Stop</a> (bool needReset=true)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p498442619165634"><a name="p498442619165634"></a><a name="p498442619165634"></a>void </p>
<p id="p2089735336165634"><a name="p2089735336165634"></a><a name="p2089735336165634"></a>Stops this animator. </p>
</td>
</tr>
<tr id="row1528399635165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p347323884165634"><a name="p347323884165634"></a><a name="p347323884165634"></a><a href="Graphic.md#gab8af32245cdf31fcc0a9d0a5d681774c">Pause</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1693482756165634"><a name="p1693482756165634"></a><a name="p1693482756165634"></a>void </p>
<p id="p1313100308165634"><a name="p1313100308165634"></a><a name="p1313100308165634"></a>Pauses this animator at the current image. </p>
</td>
</tr>
<tr id="row822513770165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1239683630165634"><a name="p1239683630165634"></a><a name="p1239683630165634"></a><a href="Graphic.md#ga051f03136d8c00295162f53acbe6da97">Resume</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2097268886165634"><a name="p2097268886165634"></a><a name="p2097268886165634"></a>void </p>
<p id="p1659625583165634"><a name="p1659625583165634"></a><a name="p1659625583165634"></a>Resumes this animator from the current image. </p>
</td>
</tr>
<tr id="row76517230165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2012476823165634"><a name="p2012476823165634"></a><a name="p2012476823165634"></a><a href="Graphic.md#ga80b4b917c30226c1b1f7169e3eb8ed8d">SetAnimatorStopListener</a> (<a href="OHOS-UIImageAnimatorView-AnimatorStopListener.md">AnimatorStopListener</a> *listener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1806586492165634"><a name="p1806586492165634"></a><a name="p1806586492165634"></a>void </p>
<p id="p1977814718165634"><a name="p1977814718165634"></a><a name="p1977814718165634"></a>Sets the listener for the stop of this animator. </p>
</td>
</tr>
<tr id="row1910039442165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p659548199165634"><a name="p659548199165634"></a><a name="p659548199165634"></a><a href="Graphic.md#ga3db47186dbc7a0cb996c23abcdaf2c38">UIImageView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p395543985165634"><a name="p395543985165634"></a><a name="p395543985165634"></a> </p>
<p id="p1712215404165634"><a name="p1712215404165634"></a><a name="p1712215404165634"></a>A default constructor used to create a <strong id="b1783221606165634"><a name="b1783221606165634"></a><a name="b1783221606165634"></a><a href="OHOS-UIImageView.md">UIImageView</a></strong> instance. </p>
</td>
</tr>
<tr id="row1869855977165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2005249940165634"><a name="p2005249940165634"></a><a name="p2005249940165634"></a><a href="Graphic.md#ga8be6fe17af73ab21f97effa26dbacaca">~UIImageView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1125813948165634"><a name="p1125813948165634"></a><a name="p1125813948165634"></a>virtual </p>
<p id="p1434709264165634"><a name="p1434709264165634"></a><a name="p1434709264165634"></a>A destructor used to delete the <strong id="b1202600250165634"><a name="b1202600250165634"></a><a name="b1202600250165634"></a><a href="OHOS-UIImageView.md">UIImageView</a></strong> instance. </p>
</td>
</tr>
<tr id="row529894453165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1497577368165634"><a name="p1497577368165634"></a><a name="p1497577368165634"></a><a href="Graphic.md#ga5dc99855271c582e960e0952cca8227c">GetViewType</a> () const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1175482135165634"><a name="p1175482135165634"></a><a name="p1175482135165634"></a>UIViewType </p>
<p id="p2092118085165634"><a name="p2092118085165634"></a><a name="p2092118085165634"></a>Obtains the view type. </p>
</td>
</tr>
<tr id="row1742566713165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p116454008165634"><a name="p116454008165634"></a><a name="p116454008165634"></a><a href="Graphic.md#ga20ea7dd2d8ddb16cf9750ccdcc2a2803">GetWidth</a> () override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1088728666165634"><a name="p1088728666165634"></a><a name="p1088728666165634"></a>int16_t </p>
<p id="p1594245912165634"><a name="p1594245912165634"></a><a name="p1594245912165634"></a>Obtains the width of this image view. </p>
</td>
</tr>
<tr id="row1454367765165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2080689324165634"><a name="p2080689324165634"></a><a name="p2080689324165634"></a><a href="Graphic.md#gaddc6e68c67782eaad40977c6c2256cdd">GetHeight</a> () override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p336064607165634"><a name="p336064607165634"></a><a name="p336064607165634"></a>int16_t </p>
<p id="p409567503165634"><a name="p409567503165634"></a><a name="p409567503165634"></a>Obtains the height of this image view. </p>
</td>
</tr>
<tr id="row1196963042165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p508540660165634"><a name="p508540660165634"></a><a name="p508540660165634"></a><a href="Graphic.md#ga5d79816831f61406c1c8bd300da9973e">OnPreDraw</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1670043287165634"><a name="p1670043287165634"></a><a name="p1670043287165634"></a>bool </p>
<p id="p1296535607165634"><a name="p1296535607165634"></a><a name="p1296535607165634"></a>Checks whether this image view needs to be covered to optimize the drawing process. </p>
</td>
</tr>
<tr id="row1081166406165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1921313688165634"><a name="p1921313688165634"></a><a name="p1921313688165634"></a><a href="Graphic.md#ga565cecb8ac66f2009dc4783da9bdc699">OnDraw</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p94037025165634"><a name="p94037025165634"></a><a name="p94037025165634"></a>void </p>
<p id="p4634770165634"><a name="p4634770165634"></a><a name="p4634770165634"></a>Draws this image view. </p>
</td>
</tr>
<tr id="row1043598506165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1486474878165634"><a name="p1486474878165634"></a><a name="p1486474878165634"></a><a href="Graphic.md#ga4e2dac4fd52a54a828f13db5ab51d110">SetSrc</a> (const char *src)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p989022337165634"><a name="p989022337165634"></a><a name="p989022337165634"></a>void </p>
<p id="p2083419432165634"><a name="p2083419432165634"></a><a name="p2083419432165634"></a>Sets the image path. </p>
</td>
</tr>
<tr id="row2126644074165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1891604412165634"><a name="p1891604412165634"></a><a name="p1891604412165634"></a><a href="Graphic.md#ga18a9eed434132ac60c127ca1fc03e663">SetSrc</a> (const <a href="OHOS-ImageInfo.md">ImageInfo</a> *src)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p146359563165634"><a name="p146359563165634"></a><a name="p146359563165634"></a>void </p>
<p id="p1161854396165634"><a name="p1161854396165634"></a><a name="p1161854396165634"></a>Sets the image information. </p>
</td>
</tr>
<tr id="row1207885811165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p627345766165634"><a name="p627345766165634"></a><a name="p627345766165634"></a><a href="Graphic.md#gab3f60d7eff9b467c64edc90293dbb21d">SetAutoEnable</a> (bool enable)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1237671802165634"><a name="p1237671802165634"></a><a name="p1237671802165634"></a>void </p>
<p id="p381959872165634"><a name="p381959872165634"></a><a name="p381959872165634"></a>Sets whether the image view size needs to be adaptive to the image size. </p>
</td>
</tr>
<tr id="row1102286633165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p299624537165634"><a name="p299624537165634"></a><a name="p299624537165634"></a><a href="Graphic.md#ga339c80c2f8f05ff0d79638dc61c71d5a">SetBlurLevel</a> (BlurLevel level)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1368115049165634"><a name="p1368115049165634"></a><a name="p1368115049165634"></a>void </p>
<p id="p1657025402165634"><a name="p1657025402165634"></a><a name="p1657025402165634"></a>Sets the blur level for this image when it is rotated or scaled. </p>
</td>
</tr>
<tr id="row432001848165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p881376230165634"><a name="p881376230165634"></a><a name="p881376230165634"></a><a href="Graphic.md#ga8c891ce7719b97f6d49b0554caa371cb">GetBlurLevel</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p194811933165634"><a name="p194811933165634"></a><a name="p194811933165634"></a>BlurLevel </p>
<p id="p557114346165634"><a name="p557114346165634"></a><a name="p557114346165634"></a>Obtains the blur level of this image when it is rotated or scaled. </p>
</td>
</tr>
<tr id="row570833411165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p955684048165634"><a name="p955684048165634"></a><a name="p955684048165634"></a><a href="Graphic.md#gacd3bafd7cd7dfb83d46d4fae36eae612">SetTransformAlgorithm</a> (TransformAlgorithm algorithm)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p962134928165634"><a name="p962134928165634"></a><a name="p962134928165634"></a>void </p>
<p id="p1744613366165634"><a name="p1744613366165634"></a><a name="p1744613366165634"></a>Sets the algorithm used for image rotation and scaling. </p>
</td>
</tr>
<tr id="row120271857165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p15765460165634"><a name="p15765460165634"></a><a name="p15765460165634"></a><a href="Graphic.md#gac7b75c6fa653d3ac0c8bc9062939d293">GetTransformAlgorithm</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p765489151165634"><a name="p765489151165634"></a><a name="p765489151165634"></a>TransformAlgorithm </p>
<p id="p605139783165634"><a name="p605139783165634"></a><a name="p605139783165634"></a>Obtains the algorithm used for image rotation and scaling. </p>
</td>
</tr>
<tr id="row684742886165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p308824047165634"><a name="p308824047165634"></a><a name="p308824047165634"></a><a href="Graphic.md#ga3824befafd4f4dda003195ca2bbef399">GetPath</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1050665013165634"><a name="p1050665013165634"></a><a name="p1050665013165634"></a>const char * </p>
<p id="p1504266573165634"><a name="p1504266573165634"></a><a name="p1504266573165634"></a>获取图片路径 </p>
</td>
</tr>
<tr id="row1692960068165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p704965913165634"><a name="p704965913165634"></a><a name="p704965913165634"></a><a href="Graphic.md#gaa9fbde27be3e3ea2fc6b4dabbf588af8">GetImageInfo</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p939116226165634"><a name="p939116226165634"></a><a name="p939116226165634"></a>const <a href="OHOS-ImageInfo.md">ImageInfo</a> * </p>
<p id="p1269161836165634"><a name="p1269161836165634"></a><a name="p1269161836165634"></a>获取图片信息 </p>
</td>
</tr>
<tr id="row1284041113165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1930784449165634"><a name="p1930784449165634"></a><a name="p1930784449165634"></a><a href="Graphic.md#ga07da08c8507a3dbee5c21ea0de170a16">GetSrcType</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1348216302165634"><a name="p1348216302165634"></a><a name="p1348216302165634"></a>uint8_t </p>
<p id="p560628898165634"><a name="p560628898165634"></a><a name="p560628898165634"></a>获取图片类型 </p>
</td>
</tr>
<tr id="row832664079165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p194814628165634"><a name="p194814628165634"></a><a name="p194814628165634"></a><a href="Graphic.md#ga7aad5b50d945efe5f9304bc978b2001c">UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p439151511165634"><a name="p439151511165634"></a><a name="p439151511165634"></a> </p>
<p id="p491625694165634"><a name="p491625694165634"></a><a name="p491625694165634"></a>A default constructor used to create an <strong id="b1079462915165634"><a name="b1079462915165634"></a><a name="b1079462915165634"></a><a href="OHOS-UIView.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row1793298227165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1303131123165634"><a name="p1303131123165634"></a><a name="p1303131123165634"></a><a href="Graphic.md#ga57d429bb1cd71782f3b825f1bc6b9362">UIView</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p567782081165634"><a name="p567782081165634"></a><a name="p567782081165634"></a> </p>
<p id="p1263683488165634"><a name="p1263683488165634"></a><a name="p1263683488165634"></a>A constructor used to create an <strong id="b1701532868165634"><a name="b1701532868165634"></a><a name="b1701532868165634"></a><a href="OHOS-UIView.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row17829076165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1763992596165634"><a name="p1763992596165634"></a><a name="p1763992596165634"></a><a href="Graphic.md#ga17f0ffc1090bdcce0f88288da5962012">~UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1036811207165634"><a name="p1036811207165634"></a><a name="p1036811207165634"></a>virtual </p>
<p id="p355284553165634"><a name="p355284553165634"></a><a name="p355284553165634"></a>A destructor used to delete the <strong id="b1707212689165634"><a name="b1707212689165634"></a><a name="b1707212689165634"></a><a href="OHOS-UIView.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row2014101960165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p457042622165634"><a name="p457042622165634"></a><a name="p457042622165634"></a><a href="Graphic.md#gab70473cd0d8fe7c9d4bb817caeee9153">OnPostDraw</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p224150269165634"><a name="p224150269165634"></a><a name="p224150269165634"></a>virtual void </p>
<p id="p773064229165634"><a name="p773064229165634"></a><a name="p773064229165634"></a>Called after a view is drawn. </p>
</td>
</tr>
<tr id="row372572980165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1314810963165634"><a name="p1314810963165634"></a><a name="p1314810963165634"></a><a href="Graphic.md#ga2a9a38b8450fbb196277238a51fbbf99">Invalidate</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1930296640165634"><a name="p1930296640165634"></a><a name="p1930296640165634"></a>void </p>
<p id="p975591011165634"><a name="p975591011165634"></a><a name="p975591011165634"></a>Refreshes the invalidated area of the view. </p>
</td>
</tr>
<tr id="row1429814207165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1642303725165634"><a name="p1642303725165634"></a><a name="p1642303725165634"></a><a href="Graphic.md#gaf0e6b65ced8b931642f2a80c195962d2">InvalidateRect</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1662795246165634"><a name="p1662795246165634"></a><a name="p1662795246165634"></a>void </p>
<p id="p777072186165634"><a name="p777072186165634"></a><a name="p777072186165634"></a>Refreshes a view in a specified invalidated area. </p>
</td>
</tr>
<tr id="row1327287275165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1771815227165634"><a name="p1771815227165634"></a><a name="p1771815227165634"></a><a href="Graphic.md#gac311aa47301d727c35fc31f8630d016e">OnLongPressEvent</a> (const <a href="OHOS-LongPressEvent.md">LongPressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1960328701165634"><a name="p1960328701165634"></a><a name="p1960328701165634"></a>virtual bool </p>
<p id="p878924300165634"><a name="p878924300165634"></a><a name="p878924300165634"></a>Called when the view is long pressed. </p>
</td>
</tr>
<tr id="row1722252184165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1957427394165634"><a name="p1957427394165634"></a><a name="p1957427394165634"></a><a href="Graphic.md#gac0e10556ff99b8a92bfb11df6456d605">OnDragStartEvent</a> (const <a href="OHOS-DragEvent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p318480680165634"><a name="p318480680165634"></a><a name="p318480680165634"></a>virtual bool </p>
<p id="p1612582951165634"><a name="p1612582951165634"></a><a name="p1612582951165634"></a>Called when the view starts to drag. </p>
</td>
</tr>
<tr id="row1067541558165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1658796361165634"><a name="p1658796361165634"></a><a name="p1658796361165634"></a><a href="Graphic.md#ga46249c8caf06b81590d9450e30a31147">OnDragEvent</a> (const <a href="OHOS-DragEvent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1055791212165634"><a name="p1055791212165634"></a><a name="p1055791212165634"></a>virtual bool </p>
<p id="p1613996148165634"><a name="p1613996148165634"></a><a name="p1613996148165634"></a>Called when the view is being dragged. </p>
</td>
</tr>
<tr id="row1694409035165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p630753035165634"><a name="p630753035165634"></a><a name="p630753035165634"></a><a href="Graphic.md#ga1799d33be73f64ed2066f50d7e65468d">OnDragEndEvent</a> (const <a href="OHOS-DragEvent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p204145038165634"><a name="p204145038165634"></a><a name="p204145038165634"></a>virtual bool </p>
<p id="p1896995684165634"><a name="p1896995684165634"></a><a name="p1896995684165634"></a>Called when the view stops dragging. </p>
</td>
</tr>
<tr id="row1758705887165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p948804655165634"><a name="p948804655165634"></a><a name="p948804655165634"></a><a href="Graphic.md#gad08697a29aae4c58267f494b66b9a547">OnClickEvent</a> (const <a href="OHOS-ClickEvent.md">ClickEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1400868755165634"><a name="p1400868755165634"></a><a name="p1400868755165634"></a>virtual void </p>
<p id="p1431024190165634"><a name="p1431024190165634"></a><a name="p1431024190165634"></a>Called when the view is clicked. </p>
</td>
</tr>
<tr id="row1120954520165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p802081546165634"><a name="p802081546165634"></a><a name="p802081546165634"></a><a href="Graphic.md#gafa544ff2d27785a9410a80689f1ad3b1">OnPressEvent</a> (const <a href="OHOS-PressEvent.md">PressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1660927005165634"><a name="p1660927005165634"></a><a name="p1660927005165634"></a>virtual void </p>
<p id="p1273369016165634"><a name="p1273369016165634"></a><a name="p1273369016165634"></a>Called when the view is pressed. </p>
</td>
</tr>
<tr id="row892622631165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p764972943165634"><a name="p764972943165634"></a><a name="p764972943165634"></a><a href="Graphic.md#ga7bd1a74563b059b03fbf66f9add53ee3">OnReleaseEvent</a> (const <a href="OHOS-ReleaseEvent.md">ReleaseEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1886753805165634"><a name="p1886753805165634"></a><a name="p1886753805165634"></a>virtual void </p>
<p id="p847250994165634"><a name="p847250994165634"></a><a name="p847250994165634"></a>Called when the view is released. </p>
</td>
</tr>
<tr id="row1164138185165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1111565586165634"><a name="p1111565586165634"></a><a name="p1111565586165634"></a><a href="Graphic.md#ga8f01ff25a33b20df0758f564148e579d">OnCancelEvent</a> (const <a href="OHOS-CancelEvent.md">CancelEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2047888582165634"><a name="p2047888582165634"></a><a name="p2047888582165634"></a>virtual void </p>
<p id="p1171279405165634"><a name="p1171279405165634"></a><a name="p1171279405165634"></a>Called when a click event on the view is canceled. </p>
</td>
</tr>
<tr id="row1133677397165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p447518340165634"><a name="p447518340165634"></a><a name="p447518340165634"></a><a href="Graphic.md#gad8e3cf5f0dd003a6aa932ef04e7b59f2">SetOnDragListener</a> (<a href="OHOS-UIView-OnDragListener.md">OnDragListener</a> *onDragListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p39738138165634"><a name="p39738138165634"></a><a name="p39738138165634"></a>void </p>
<p id="p368616469165634"><a name="p368616469165634"></a><a name="p368616469165634"></a>Sets a drag event listener for the view. </p>
</td>
</tr>
<tr id="row1787735355165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1942038774165634"><a name="p1942038774165634"></a><a name="p1942038774165634"></a><a href="Graphic.md#ga45a02cba4887c5c0b8e243941bcdc5cb">GetOnDragListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1205141380165634"><a name="p1205141380165634"></a><a name="p1205141380165634"></a><a href="OHOS-UIView-OnDragListener.md">OnDragListener</a> *&amp; </p>
<p id="p537223722165634"><a name="p537223722165634"></a><a name="p537223722165634"></a>Obtains the drag event listener for the view. </p>
</td>
</tr>
<tr id="row120887453165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1749852587165634"><a name="p1749852587165634"></a><a name="p1749852587165634"></a><a href="Graphic.md#ga4564bf8d8c7184e9c02bf33c9e171fa3">SetOnClickListener</a> (<a href="OHOS-UIView-OnClickListener.md">OnClickListener</a> *onClickListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1590088050165634"><a name="p1590088050165634"></a><a name="p1590088050165634"></a>void </p>
<p id="p1600537207165634"><a name="p1600537207165634"></a><a name="p1600537207165634"></a>Sets a click event listener for the view. </p>
</td>
</tr>
<tr id="row1320839945165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1957647652165634"><a name="p1957647652165634"></a><a name="p1957647652165634"></a><a href="Graphic.md#ga35e885cb380c37245fa4305bba10cd4a">GetOnClickListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p663880643165634"><a name="p663880643165634"></a><a name="p663880643165634"></a><a href="OHOS-UIView-OnClickListener.md">OnClickListener</a> *&amp; </p>
<p id="p1709014895165634"><a name="p1709014895165634"></a><a name="p1709014895165634"></a>Obtains the click event listener for the view. </p>
</td>
</tr>
<tr id="row234897231165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p34259783165634"><a name="p34259783165634"></a><a name="p34259783165634"></a><a href="Graphic.md#gabcbe7a0adce600424f7f0d5a7396eb5b">SetOnLongPressListener</a> (<a href="OHOS-UIView-OnLongPressListener.md">OnLongPressListener</a> *onLongPressListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1118058218165634"><a name="p1118058218165634"></a><a name="p1118058218165634"></a>void </p>
<p id="p1203277947165634"><a name="p1203277947165634"></a><a name="p1203277947165634"></a>Sets a long-press event listener for the view. </p>
</td>
</tr>
<tr id="row1604057530165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p301388583165634"><a name="p301388583165634"></a><a name="p301388583165634"></a><a href="Graphic.md#gaafd4d354f5f111e758d046109fd7f656">GetOnLongPressListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1173779991165634"><a name="p1173779991165634"></a><a name="p1173779991165634"></a><a href="OHOS-UIView-OnLongPressListener.md">OnLongPressListener</a> *&amp; </p>
<p id="p1066162914165634"><a name="p1066162914165634"></a><a name="p1066162914165634"></a>Obtains the long-press event listener for the view. </p>
</td>
</tr>
<tr id="row1307142915165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p826567224165634"><a name="p826567224165634"></a><a name="p826567224165634"></a><a href="Graphic.md#gadd697fbf481f98d9d6ca8b67390071af">SetOnTouchListener</a> (<a href="OHOS-UIView-OnTouchListener.md">OnTouchListener</a> *onTouchListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1462728617165634"><a name="p1462728617165634"></a><a name="p1462728617165634"></a>void </p>
<p id="p1004483207165634"><a name="p1004483207165634"></a><a name="p1004483207165634"></a>Sets a touch event listener for the view. </p>
</td>
</tr>
<tr id="row2013383409165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p372867288165634"><a name="p372867288165634"></a><a name="p372867288165634"></a><a href="Graphic.md#gae7c65c68653103dae85acdcef78777a6">GetTouchListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1334406412165634"><a name="p1334406412165634"></a><a name="p1334406412165634"></a><a href="OHOS-UIView-OnTouchListener.md">OnTouchListener</a> *&amp; </p>
<p id="p748868831165634"><a name="p748868831165634"></a><a name="p748868831165634"></a>Obtains the touch event listener for the view. </p>
</td>
</tr>
<tr id="row122451409165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p804955617165634"><a name="p804955617165634"></a><a name="p804955617165634"></a><a href="Graphic.md#gaea9f334f2481e1c03a2cd8f3078d7c72">GetTargetView</a> (const <a href="OHOS-Point.md">Point</a> &amp;point, <a href="OHOS-UIView.md">UIView</a> **last)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1833762396165634"><a name="p1833762396165634"></a><a name="p1833762396165634"></a>virtual void </p>
<p id="p258100843165634"><a name="p258100843165634"></a><a name="p258100843165634"></a>Obtains the top-level view based on specified coordinates. </p>
</td>
</tr>
<tr id="row1181216535165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p480748237165634"><a name="p480748237165634"></a><a name="p480748237165634"></a><a href="Graphic.md#gaeea67a3a84b4ffe9bfeda418b82184cc">SetParent</a> (<a href="OHOS-UIView.md">UIView</a> *parent)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p664352282165634"><a name="p664352282165634"></a><a name="p664352282165634"></a>void </p>
<p id="p1870219189165634"><a name="p1870219189165634"></a><a name="p1870219189165634"></a>Sets the parent view for the view. </p>
</td>
</tr>
<tr id="row1801621713165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p742858273165634"><a name="p742858273165634"></a><a name="p742858273165634"></a><a href="Graphic.md#ga706530e4a38108615d5e0c918685ec96">GetParent</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1571139047165634"><a name="p1571139047165634"></a><a name="p1571139047165634"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p87463202165634"><a name="p87463202165634"></a><a name="p87463202165634"></a>Obtains the parent view of the view. </p>
</td>
</tr>
<tr id="row1506748933165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2077873640165634"><a name="p2077873640165634"></a><a name="p2077873640165634"></a><a href="Graphic.md#ga02bec5de07d93cabc45affba79eba4ad">SetNextSibling</a> (<a href="OHOS-UIView.md">UIView</a> *sibling)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1238820570165634"><a name="p1238820570165634"></a><a name="p1238820570165634"></a>void </p>
<p id="p1410815641165634"><a name="p1410815641165634"></a><a name="p1410815641165634"></a>Sets the next sibling view for the view. </p>
</td>
</tr>
<tr id="row400085053165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p273643496165634"><a name="p273643496165634"></a><a name="p273643496165634"></a><a href="Graphic.md#gab0030977b30ddc9f2e15dbc2f58937e6">GetNextSibling</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p798923373165634"><a name="p798923373165634"></a><a name="p798923373165634"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p1668455087165634"><a name="p1668455087165634"></a><a name="p1668455087165634"></a>Obtains the next sibling view of the view. </p>
</td>
</tr>
<tr id="row978140581165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1425099947165634"><a name="p1425099947165634"></a><a name="p1425099947165634"></a><a href="Graphic.md#ga07e7e1f268bd6ce975f4f0f8487af5d0">SetVisible</a> (bool visible)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1336322831165634"><a name="p1336322831165634"></a><a name="p1336322831165634"></a>virtual void </p>
<p id="p1457029833165634"><a name="p1457029833165634"></a><a name="p1457029833165634"></a>Sets whether the view is visible. </p>
</td>
</tr>
<tr id="row1257986196165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1643674429165634"><a name="p1643674429165634"></a><a name="p1643674429165634"></a><a href="Graphic.md#gaee178fc0a86ac03a6bdf2ade0c1914c8">IsVisible</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1417807429165634"><a name="p1417807429165634"></a><a name="p1417807429165634"></a>bool </p>
<p id="p1947831043165634"><a name="p1947831043165634"></a><a name="p1947831043165634"></a>Checks whether the view is visible. </p>
</td>
</tr>
<tr id="row1566824199165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1683099595165634"><a name="p1683099595165634"></a><a name="p1683099595165634"></a><a href="Graphic.md#gaf9fb55fd9aa397f7158f1515e90bce02">SetTouchable</a> (bool touch)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p316279600165634"><a name="p316279600165634"></a><a name="p316279600165634"></a>void </p>
<p id="p1843499079165634"><a name="p1843499079165634"></a><a name="p1843499079165634"></a>Sets whether the view is touchable. </p>
</td>
</tr>
<tr id="row98894424165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p424540578165634"><a name="p424540578165634"></a><a name="p424540578165634"></a><a href="Graphic.md#ga502a53fb77b260fa36b5b3adf82e2340">IsTouchable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p757392569165634"><a name="p757392569165634"></a><a name="p757392569165634"></a>bool </p>
<p id="p229733786165634"><a name="p229733786165634"></a><a name="p229733786165634"></a>Checks whether the view is touchable. </p>
</td>
</tr>
<tr id="row398648734165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1591099584165634"><a name="p1591099584165634"></a><a name="p1591099584165634"></a><a href="Graphic.md#gab06abe0fe824c048f3b72974f9a8f0d0">SetDraggable</a> (bool draggable)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1461046712165634"><a name="p1461046712165634"></a><a name="p1461046712165634"></a>void </p>
<p id="p1223648941165634"><a name="p1223648941165634"></a><a name="p1223648941165634"></a>Sets whether the view is draggable. </p>
</td>
</tr>
<tr id="row1348797531165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p823493889165634"><a name="p823493889165634"></a><a name="p823493889165634"></a><a href="Graphic.md#ga25bb796ff400c767d622cbed280fc500">IsDraggable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1828102369165634"><a name="p1828102369165634"></a><a name="p1828102369165634"></a>bool </p>
<p id="p369769988165634"><a name="p369769988165634"></a><a name="p369769988165634"></a>Checks whether the view is draggable. </p>
</td>
</tr>
<tr id="row2075794106165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1766895524165634"><a name="p1766895524165634"></a><a name="p1766895524165634"></a><a href="Graphic.md#ga6c08e49bf7a82a7ebaef0f251e7a6f85">SetDragParentInstead</a> (bool dragParentInstead)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2104463196165634"><a name="p2104463196165634"></a><a name="p2104463196165634"></a>void </p>
<p id="p1804637686165634"><a name="p1804637686165634"></a><a name="p1804637686165634"></a>Sets whether to transfer the drag event to the parent view for processing when the view is being dragged. </p>
</td>
</tr>
<tr id="row876309312165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1233265160165634"><a name="p1233265160165634"></a><a name="p1233265160165634"></a><a href="Graphic.md#gaf0c462bc31e779b1898ad4cdfdad6faf">IsDragParentInstead</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1893401161165634"><a name="p1893401161165634"></a><a name="p1893401161165634"></a>bool </p>
<p id="p1797235461165634"><a name="p1797235461165634"></a><a name="p1797235461165634"></a>Obtains whether the view transfers a drag event to the parent view for processing. </p>
</td>
</tr>
<tr id="row1008753148165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1751895381165634"><a name="p1751895381165634"></a><a name="p1751895381165634"></a><a href="Graphic.md#ga86cb8d364f18494d67636c55babced5c">GetRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p960355929165634"><a name="p960355929165634"></a><a name="p960355929165634"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p955592965165634"><a name="p955592965165634"></a><a name="p955592965165634"></a>Obtains the absolute rectangle area of the view. When the view has deformation such as rotation, the rectangle area is the intersection set of the absolute rectangle area and deformation matrix. </p>
</td>
</tr>
<tr id="row322357515165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p35303541165634"><a name="p35303541165634"></a><a name="p35303541165634"></a><a href="Graphic.md#ga06e79704a19f2a238982076cac3d059b">GetVisibleRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1350144441165634"><a name="p1350144441165634"></a><a name="p1350144441165634"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p861216619165634"><a name="p861216619165634"></a><a name="p861216619165634"></a>Obtains the visible absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row722886550165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1927806921165634"><a name="p1927806921165634"></a><a name="p1927806921165634"></a><a href="Graphic.md#gab3f8993b3953f27bfc61d53429916cba">GetMaskedRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p951632939165634"><a name="p951632939165634"></a><a name="p951632939165634"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p620884040165634"><a name="p620884040165634"></a><a name="p620884040165634"></a>Obtains the valid absolute rectangle area of the view. The valid area refers to the area where the view can be displayed. Generally, the valid area is the same as the visible view area, but they may be different in the grid layout. </p>
</td>
</tr>
<tr id="row1245307899165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p216934889165634"><a name="p216934889165634"></a><a name="p216934889165634"></a><a href="Graphic.md#ga64cf308a09999def1192f9c4e0f17f0a">GetOrigRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1320300056165634"><a name="p1320300056165634"></a><a name="p1320300056165634"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p859833869165634"><a name="p859833869165634"></a><a name="p859833869165634"></a>Obtains the absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row1826274379165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1526363075165634"><a name="p1526363075165634"></a><a name="p1526363075165634"></a><a href="Graphic.md#ga9db88eae712676359d02a92be14fa316">GetContentRect</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1018763078165634"><a name="p1018763078165634"></a><a name="p1018763078165634"></a>virtual <a href="OHOS-Rect.md">Rect</a> </p>
<p id="p1221487475165634"><a name="p1221487475165634"></a><a name="p1221487475165634"></a>Obtains the content of the absolute rectangle area of the view. This area excludes padding. </p>
</td>
</tr>
<tr id="row413445071165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1877070873165634"><a name="p1877070873165634"></a><a name="p1877070873165634"></a><a href="Graphic.md#gae9b96837fa1d45648a2a6fbbfcc5eb4a">GetRelativeRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p310432299165634"><a name="p310432299165634"></a><a name="p310432299165634"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p380381049165634"><a name="p380381049165634"></a><a name="p380381049165634"></a>Obtains the rectangular area of the view relative to the parent view, that is, the rectangular area relative to the coordinates of the parent view. </p>
</td>
</tr>
<tr id="row1018056102165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p80487705165634"><a name="p80487705165634"></a><a name="p80487705165634"></a><a href="Graphic.md#gae6c5f3bcf99dc837bcecd60c38d3df5a">ResizeVisibleArea</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1530200963165634"><a name="p1530200963165634"></a><a name="p1530200963165634"></a>void </p>
<p id="p1606807282165634"><a name="p1606807282165634"></a><a name="p1606807282165634"></a>Adjusts the size of the visible area. This operation may affect the final display size. </p>
</td>
</tr>
<tr id="row405571354165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1144076752165634"><a name="p1144076752165634"></a><a name="p1144076752165634"></a><a href="Graphic.md#ga3375ec5ef059fd88c657af4552d2fa4f">SetWidth</a> (int16_t width)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1756562678165634"><a name="p1756562678165634"></a><a name="p1756562678165634"></a>virtual void </p>
<p id="p2013099391165634"><a name="p2013099391165634"></a><a name="p2013099391165634"></a>Sets the width for the view. </p>
</td>
</tr>
<tr id="row300109395165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p287322924165634"><a name="p287322924165634"></a><a name="p287322924165634"></a><a href="Graphic.md#ga9c7110620d5dc3a7bd3efe1fc2edd125">SetHeight</a> (int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p587948123165634"><a name="p587948123165634"></a><a name="p587948123165634"></a>virtual void </p>
<p id="p598769020165634"><a name="p598769020165634"></a><a name="p598769020165634"></a>Sets the height for the view. </p>
</td>
</tr>
<tr id="row1952355215165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p88276364165634"><a name="p88276364165634"></a><a name="p88276364165634"></a><a href="Graphic.md#gae985b607d2f0701911778bf20d640ccd">Resize</a> (int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1127064073165634"><a name="p1127064073165634"></a><a name="p1127064073165634"></a>virtual void </p>
<p id="p1988553192165634"><a name="p1988553192165634"></a><a name="p1988553192165634"></a>Adjusts the size of the view. </p>
</td>
</tr>
<tr id="row1122160441165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1327334721165634"><a name="p1327334721165634"></a><a name="p1327334721165634"></a><a href="Graphic.md#gaded403626558d28e62bf5632ccbb24b5">SetX</a> (int16_t x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1097061333165634"><a name="p1097061333165634"></a><a name="p1097061333165634"></a>virtual void </p>
<p id="p1912635786165634"><a name="p1912635786165634"></a><a name="p1912635786165634"></a>Sets the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row218035268165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p493583456165634"><a name="p493583456165634"></a><a name="p493583456165634"></a><a href="Graphic.md#ga89dc5f8fb1cb4b2259dc0439185359f1">GetX</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1139861227165634"><a name="p1139861227165634"></a><a name="p1139861227165634"></a>int16_t </p>
<p id="p155489239165634"><a name="p155489239165634"></a><a name="p155489239165634"></a>Obtains the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row1155179147165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1863899298165634"><a name="p1863899298165634"></a><a name="p1863899298165634"></a><a href="Graphic.md#gaaa8edc224cf1c7deb2724fb225960877">SetY</a> (int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p173283901165634"><a name="p173283901165634"></a><a name="p173283901165634"></a>virtual void </p>
<p id="p1460669214165634"><a name="p1460669214165634"></a><a name="p1460669214165634"></a>Sets the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row1768014248165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1809169407165634"><a name="p1809169407165634"></a><a name="p1809169407165634"></a><a href="Graphic.md#ga193619d649204b0e9bb854d3b30275c3">GetY</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p597213895165634"><a name="p597213895165634"></a><a name="p597213895165634"></a>int16_t </p>
<p id="p449408420165634"><a name="p449408420165634"></a><a name="p449408420165634"></a>Obtains the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row1767867719165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p682273799165634"><a name="p682273799165634"></a><a name="p682273799165634"></a><a href="Graphic.md#gab34233f6aeae330b025969137d03e67a">SetPosition</a> (int16_t x, int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2132402622165634"><a name="p2132402622165634"></a><a name="p2132402622165634"></a>virtual void </p>
<p id="p789066074165634"><a name="p789066074165634"></a><a name="p789066074165634"></a>Sets the position for the view. </p>
</td>
</tr>
<tr id="row216906613165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1521371575165634"><a name="p1521371575165634"></a><a name="p1521371575165634"></a><a href="Graphic.md#gaf8ce4c009f23b7175b2b34bac4a74262">SetPosition</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p190270571165634"><a name="p190270571165634"></a><a name="p190270571165634"></a>virtual void </p>
<p id="p863415514165634"><a name="p863415514165634"></a><a name="p863415514165634"></a>Adjusts the position and size of the view. </p>
</td>
</tr>
<tr id="row1578091309165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p544760697165634"><a name="p544760697165634"></a><a name="p544760697165634"></a><a href="Graphic.md#gab2ce8c11abbd55f40687f38a52511b11">IsViewGroup</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1849721549165634"><a name="p1849721549165634"></a><a name="p1849721549165634"></a>bool </p>
<p id="p1025758816165634"><a name="p1025758816165634"></a><a name="p1025758816165634"></a>Checks whether the view is a container view. </p>
</td>
</tr>
<tr id="row391116271165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1578353804165634"><a name="p1578353804165634"></a><a name="p1578353804165634"></a><a href="Graphic.md#ga980fc6824c64cfae6af8657aee17af88">SetIntercept</a> (bool isIntercept)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1989857343165634"><a name="p1989857343165634"></a><a name="p1989857343165634"></a>void </p>
<p id="p639743570165634"><a name="p639743570165634"></a><a name="p639743570165634"></a>Sets whether to intercept the drag event. If intercepted, the view does not transfer the drag event to the parent view after local processing. </p>
</td>
</tr>
<tr id="row529440022165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p242108425165634"><a name="p242108425165634"></a><a name="p242108425165634"></a><a href="Graphic.md#ga8623abbbeff458c0cb2d7dc0d1f21e4a">SetTransformMap</a> (const <a href="OHOS-TransformMap.md">TransformMap</a> &amp;transMap)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1655520330165634"><a name="p1655520330165634"></a><a name="p1655520330165634"></a>void </p>
<p id="p602126790165634"><a name="p602126790165634"></a><a name="p602126790165634"></a>Sets the affine transformation matrix. </p>
</td>
</tr>
<tr id="row1497700549165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1058102589165634"><a name="p1058102589165634"></a><a name="p1058102589165634"></a><a href="Graphic.md#gab8cee5a7052a88722768c8ed1324abc1">GetTransformMap</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1707890582165634"><a name="p1707890582165634"></a><a name="p1707890582165634"></a><a href="OHOS-TransformMap.md">TransformMap</a> &amp; </p>
<p id="p1673248222165634"><a name="p1673248222165634"></a><a name="p1673248222165634"></a>Obtains an affine transformation matrix. </p>
</td>
</tr>
<tr id="row1489093664165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p306446151165634"><a name="p306446151165634"></a><a name="p306446151165634"></a><a href="Graphic.md#ga0573aa25307c22319db4629781b5cad2">GetChildById</a> (const char *id) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2005980271165634"><a name="p2005980271165634"></a><a name="p2005980271165634"></a>virtual <a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p1069459519165634"><a name="p1069459519165634"></a><a name="p1069459519165634"></a>Obtains the child view of a specified ID. </p>
</td>
</tr>
<tr id="row1433794231165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p840101332165634"><a name="p840101332165634"></a><a name="p840101332165634"></a><a href="Graphic.md#ga0caaa15c9b304673331e778a266be77f">SetViewId</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1551256646165634"><a name="p1551256646165634"></a><a name="p1551256646165634"></a>void </p>
<p id="p1508308052165634"><a name="p1508308052165634"></a><a name="p1508308052165634"></a>Sets the view ID. </p>
</td>
</tr>
<tr id="row717958670165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p841248931165634"><a name="p841248931165634"></a><a name="p841248931165634"></a><a href="Graphic.md#gad6c7644bd2abfa3c92d80776b0bd1936">GetViewId</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1047240249165634"><a name="p1047240249165634"></a><a name="p1047240249165634"></a>const char * </p>
<p id="p1410603380165634"><a name="p1410603380165634"></a><a name="p1410603380165634"></a>Obtains the view ID. </p>
</td>
</tr>
<tr id="row1890925709165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p543186776165634"><a name="p543186776165634"></a><a name="p543186776165634"></a><a href="Graphic.md#ga77a961aa53567c5214508b4569801c16">SetViewIndex</a> (int16_t <a href="UTILS.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1345647025165634"><a name="p1345647025165634"></a><a name="p1345647025165634"></a>void </p>
<p id="p1382909189165634"><a name="p1382909189165634"></a><a name="p1382909189165634"></a>Sets the view index. </p>
</td>
</tr>
<tr id="row756133881165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1120933969165634"><a name="p1120933969165634"></a><a name="p1120933969165634"></a><a href="Graphic.md#ga62f51715b6d420a296ebe0296717b906">GetViewIndex</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p723959695165634"><a name="p723959695165634"></a><a name="p723959695165634"></a>int16_t </p>
<p id="p307262629165634"><a name="p307262629165634"></a><a name="p307262629165634"></a>Obtains the view index. </p>
</td>
</tr>
<tr id="row720707171165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1097910899165634"><a name="p1097910899165634"></a><a name="p1097910899165634"></a><a href="Graphic.md#gaca871fa2f8219e7ea9388e212d1f1e69">LayoutChildren</a> (bool neeInvalidate=false)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p925870082165634"><a name="p925870082165634"></a><a name="p925870082165634"></a>virtual void </p>
<p id="p459200546165634"><a name="p459200546165634"></a><a name="p459200546165634"></a>Lays out all child views according to the preset arrangement mode. </p>
</td>
</tr>
<tr id="row1206065654165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1579352043165634"><a name="p1579352043165634"></a><a name="p1579352043165634"></a><a href="Graphic.md#ga443b86ee9275b0421b37a47bad3264dc">LayoutCenterOfParent</a> (int16_t xOffSet=0, int16_t yOffset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p621264336165634"><a name="p621264336165634"></a><a name="p621264336165634"></a>void </p>
<p id="p1033650200165634"><a name="p1033650200165634"></a><a name="p1033650200165634"></a>Lays out the view in the center of the parent view. </p>
</td>
</tr>
<tr id="row1962683497165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1113589797165634"><a name="p1113589797165634"></a><a name="p1113589797165634"></a><a href="Graphic.md#ga94999b271f27cd5d6bfaf303f7d5c708">LayoutLeftOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1698704323165634"><a name="p1698704323165634"></a><a name="p1698704323165634"></a>void </p>
<p id="p375120686165634"><a name="p375120686165634"></a><a name="p375120686165634"></a>Lays out the view on the left of the parent view. </p>
</td>
</tr>
<tr id="row1870292479165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1937911808165634"><a name="p1937911808165634"></a><a name="p1937911808165634"></a><a href="Graphic.md#ga479528ed259b5539e423955f2b60517d">LayoutRightOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p756763725165634"><a name="p756763725165634"></a><a name="p756763725165634"></a>void </p>
<p id="p24759277165634"><a name="p24759277165634"></a><a name="p24759277165634"></a>Lays out the view on the right of the parent view. </p>
</td>
</tr>
<tr id="row923769075165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1561941212165634"><a name="p1561941212165634"></a><a name="p1561941212165634"></a><a href="Graphic.md#ga859288ea61ad23ba7e381bbc07769e83">LayoutTopOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p501780494165634"><a name="p501780494165634"></a><a name="p501780494165634"></a>void </p>
<p id="p1600641280165634"><a name="p1600641280165634"></a><a name="p1600641280165634"></a>Lays out the view on the top of the parent view. </p>
</td>
</tr>
<tr id="row3158103165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p661864769165634"><a name="p661864769165634"></a><a name="p661864769165634"></a><a href="Graphic.md#ga809aeee4792ae58218a0bcfcb94d5cdc">LayoutBottomOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1176749466165634"><a name="p1176749466165634"></a><a name="p1176749466165634"></a>void </p>
<p id="p760352452165634"><a name="p760352452165634"></a><a name="p760352452165634"></a>Lays out the view on the bottom of the parent view. </p>
</td>
</tr>
<tr id="row1023007246165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p592034753165634"><a name="p592034753165634"></a><a name="p592034753165634"></a><a href="Graphic.md#gac7f5f2584c716a56fee3783f8dea6246">AlignLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p789160452165634"><a name="p789160452165634"></a><a name="p789160452165634"></a>void </p>
<p id="p1459662900165634"><a name="p1459662900165634"></a><a name="p1459662900165634"></a>Aligns the view with the left of a sibling view. </p>
</td>
</tr>
<tr id="row1567402950165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p60381878165634"><a name="p60381878165634"></a><a name="p60381878165634"></a><a href="Graphic.md#gabb1ac454cdf95593c1e387d5e272433c">AlignRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1490960469165634"><a name="p1490960469165634"></a><a name="p1490960469165634"></a>void </p>
<p id="p1498919280165634"><a name="p1498919280165634"></a><a name="p1498919280165634"></a>Aligns the view with the right of a sibling view. </p>
</td>
</tr>
<tr id="row1347268723165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1066540962165634"><a name="p1066540962165634"></a><a name="p1066540962165634"></a><a href="Graphic.md#ga903d7cbc59bac06d728b7f6435c9a504">AlignTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p121231491165634"><a name="p121231491165634"></a><a name="p121231491165634"></a>void </p>
<p id="p1523620850165634"><a name="p1523620850165634"></a><a name="p1523620850165634"></a>Aligns the view with the top of a sibling view. </p>
</td>
</tr>
<tr id="row1082501502165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p974130003165634"><a name="p974130003165634"></a><a name="p974130003165634"></a><a href="Graphic.md#ga7607c3f9661932c495d080e9d92fb1a3">AlignBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1509719500165634"><a name="p1509719500165634"></a><a name="p1509719500165634"></a>void </p>
<p id="p328020689165634"><a name="p328020689165634"></a><a name="p328020689165634"></a>Aligns the view with the bottom of a sibling view. </p>
</td>
</tr>
<tr id="row1932203456165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p45321791165634"><a name="p45321791165634"></a><a name="p45321791165634"></a><a href="Graphic.md#gac23776dbc2fce7ff30d57438abfa5230">AlignHorCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p413579323165634"><a name="p413579323165634"></a><a name="p413579323165634"></a>void </p>
<p id="p1027788678165634"><a name="p1027788678165634"></a><a name="p1027788678165634"></a>Aligns the view with the center of a sibling view in the x-axis. </p>
</td>
</tr>
<tr id="row105507304165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1171987917165634"><a name="p1171987917165634"></a><a name="p1171987917165634"></a><a href="Graphic.md#gad3caa27aa0cb73ec4656e7d23aa222de">AlignVerCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1560597802165634"><a name="p1560597802165634"></a><a name="p1560597802165634"></a>void </p>
<p id="p787808221165634"><a name="p787808221165634"></a><a name="p787808221165634"></a>Aligns the view with the center of a sibling view in the y-axis. </p>
</td>
</tr>
<tr id="row771517354165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1860738599165634"><a name="p1860738599165634"></a><a name="p1860738599165634"></a><a href="Graphic.md#ga58f1a34a943c4492970f901d63bbc3d8">LayoutLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p447272482165634"><a name="p447272482165634"></a><a name="p447272482165634"></a>void </p>
<p id="p1639656839165634"><a name="p1639656839165634"></a><a name="p1639656839165634"></a>Lays out the view on the left of a sibling view. </p>
</td>
</tr>
<tr id="row1824372558165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p768078077165634"><a name="p768078077165634"></a><a name="p768078077165634"></a><a href="Graphic.md#gac4cd64de5291759add164825a323a0d6">LayoutRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p181189810165634"><a name="p181189810165634"></a><a name="p181189810165634"></a>void </p>
<p id="p144627140165634"><a name="p144627140165634"></a><a name="p144627140165634"></a>Lays out the view on the right of a sibling view. </p>
</td>
</tr>
<tr id="row1092921092165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1966722661165634"><a name="p1966722661165634"></a><a name="p1966722661165634"></a><a href="Graphic.md#gaaa8385807e3a9bea46f8dcc326252a70">LayoutTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p955969158165634"><a name="p955969158165634"></a><a name="p955969158165634"></a>void </p>
<p id="p616458405165634"><a name="p616458405165634"></a><a name="p616458405165634"></a>Lays out the view on the above of a sibling view. </p>
</td>
</tr>
<tr id="row1540827581165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1830210218165634"><a name="p1830210218165634"></a><a name="p1830210218165634"></a><a href="Graphic.md#gaa23a68e8ef0fb13b362218e71cf67ace">LayoutBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p937852371165634"><a name="p937852371165634"></a><a name="p937852371165634"></a>void </p>
<p id="p1125915582165634"><a name="p1125915582165634"></a><a name="p1125915582165634"></a>Lays out the view on the below of a sibling view. </p>
</td>
</tr>
<tr id="row51852810165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p155573587165634"><a name="p155573587165634"></a><a name="p155573587165634"></a><a href="Graphic.md#ga535942844ebee554d413e960634a2867">SetStyle</a> (<a href="OHOS-Style.md">Style</a> &amp;style)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p343314638165634"><a name="p343314638165634"></a><a name="p343314638165634"></a>void </p>
<p id="p616356713165634"><a name="p616356713165634"></a><a name="p616356713165634"></a>Sets the view style. </p>
</td>
</tr>
<tr id="row1624265385165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1074989864165634"><a name="p1074989864165634"></a><a name="p1074989864165634"></a><a href="Graphic.md#ga0945c2f05815dc2e466ef9ceaca2f700">SetStyle</a> (uint8_t key, int64_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p642452224165634"><a name="p642452224165634"></a><a name="p642452224165634"></a>virtual void </p>
<p id="p1798817246165634"><a name="p1798817246165634"></a><a name="p1798817246165634"></a>Sets a style. </p>
</td>
</tr>
<tr id="row1671850257165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p412620497165634"><a name="p412620497165634"></a><a name="p412620497165634"></a><a href="Graphic.md#ga4ea19bc9f4b487946c9e29e63b54a0e6">GetStyle</a> (uint8_t key) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1698366828165634"><a name="p1698366828165634"></a><a name="p1698366828165634"></a>virtual int64_t </p>
<p id="p772253503165634"><a name="p772253503165634"></a><a name="p772253503165634"></a>Obtains the value of a style. </p>
</td>
</tr>
<tr id="row1241863355165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1491526132165634"><a name="p1491526132165634"></a><a name="p1491526132165634"></a><a href="Graphic.md#ga1b28213d4c2cd0f8324bce3fe56eb7bb">GetStyleConst</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p223567753165634"><a name="p223567753165634"></a><a name="p223567753165634"></a>const <a href="OHOS-Style.md">Style</a> &amp; </p>
<p id="p1949552023165634"><a name="p1949552023165634"></a><a name="p1949552023165634"></a>Obtains the view style. This function applies to scenarios where the style does not need to be modified, which saves memory. </p>
</td>
</tr>
<tr id="row952753111165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1005503064165634"><a name="p1005503064165634"></a><a name="p1005503064165634"></a><a href="Graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p906331054165634"><a name="p906331054165634"></a><a name="p906331054165634"></a>void * </p>
<p id="p830644175165634"><a name="p830644175165634"></a><a name="p830644175165634"></a>Overrides the <strong id="b205754455165634"><a name="b205754455165634"></a><a name="b205754455165634"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row1180420575165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p770092485165634"><a name="p770092485165634"></a><a name="p770092485165634"></a><a href="Graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1869427835165634"><a name="p1869427835165634"></a><a name="p1869427835165634"></a>void </p>
<p id="p499020975165634"><a name="p499020975165634"></a><a name="p499020975165634"></a>Overrides the <strong id="b1470134039165634"><a name="b1470134039165634"></a><a name="b1470134039165634"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

## Additional Inherited Members<a name="inherited"></a>

<a name="table300713365165634"></a>
<table><thead align="left"><tr id="row623668439165634"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p656917322165634"><a name="p656917322165634"></a><a name="p656917322165634"></a>Additional Inherited Member Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1544299815165634"><a name="p1544299815165634"></a><a name="p1544299815165634"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1733692569165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1541693447165634"><a name="p1541693447165634"></a><a name="p1541693447165634"></a><a href="Graphic.md#ga3e530646bd55e49f0e5b0052e121f040">imageWidth_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p903363979165634"><a name="p903363979165634"></a><a name="p903363979165634"></a>Represents the width of this image. </p>
</td>
</tr>
<tr id="row1304871878165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1357410305165634"><a name="p1357410305165634"></a><a name="p1357410305165634"></a><a href="Graphic.md#ga5a7112d86d7b11b904b57c853817621d">imageHeight_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p252380907165634"><a name="p252380907165634"></a><a name="p252380907165634"></a>Represents the height of this image. </p>
</td>
</tr>
<tr id="row1829886127165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p641631355165634"><a name="p641631355165634"></a><a name="p641631355165634"></a><a href="Graphic.md#gac13c0b542f4d7f789754bacf572894b2">autoEnable_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p748370872165634"><a name="p748370872165634"></a><a name="p748370872165634"></a>Specifies whether automatic adaptation is enabled. </p>
</td>
</tr>
<tr id="row1947681883165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1552367908165634"><a name="p1552367908165634"></a><a name="p1552367908165634"></a><a href="Graphic.md#ga687a71ca22c04a7e761969f1fab1b06f">needRefresh_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1681703521165634"><a name="p1681703521165634"></a><a name="p1681703521165634"></a>Specifies whether a refresh is needed. </p>
</td>
</tr>
<tr id="row2002281458165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1449750665165634"><a name="p1449750665165634"></a><a name="p1449750665165634"></a><a href="Graphic.md#gacbbee3e74893c43864b116779d97ad09">colorFormat_</a>: 4</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p269865025165634"><a name="p269865025165634"></a><a name="p269865025165634"></a>Represents the color format of this image. </p>
</td>
</tr>
<tr id="row722827070165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p540180215165634"><a name="p540180215165634"></a><a name="p540180215165634"></a><a href="Graphic.md#ga1c57bd4af56c49a11060e32b6e33066c">blurLevel_</a>: 2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p45618319165634"><a name="p45618319165634"></a><a name="p45618319165634"></a>Represents the blur level of this image when it is rotated or scaled. </p>
</td>
</tr>
<tr id="row261801462165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p298357201165634"><a name="p298357201165634"></a><a name="p298357201165634"></a><a href="Graphic.md#ga5a8f8683c377c59c6a3c193f18468e60">algorithm_</a>: 1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2140109662165634"><a name="p2140109662165634"></a><a name="p2140109662165634"></a>Represents the algorithm used for image rotation and scaling. </p>
</td>
</tr>
</tbody>
</table>

