# OHOS::Text<a name="ZH-CN_TOPIC_0000001055678112"></a>

-   [Overview](#section287293264165633)
-   [Summary](#section1477764112165633)
-   [Public Member Functions](#pub-methods)
-   [Static Public Attributes](#pub-static-attribs)

## **Overview**<a name="section287293264165633"></a>

**Related Modules:**

[Graphic](Graphic.md)

**Description:**

Represents the base class of  **[Text](OHOS-Text.md)**, providing the text attribute setting and text drawing capabilities for components that require font display. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1477764112165633"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table1181582692165633"></a>
<table><thead align="left"><tr id="row2012921755165633"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p189282387165633"><a name="p189282387165633"></a><a name="p189282387165633"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p905375154165633"><a name="p905375154165633"></a><a name="p905375154165633"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2130262248165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p898649762165633"><a name="p898649762165633"></a><a name="p898649762165633"></a><a href="Graphic.md#ga7ea8e1b0f5e199317c3134b575431ce6">Text</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p654298672165633"><a name="p654298672165633"></a><a name="p654298672165633"></a> </p>
<p id="p1944335414165633"><a name="p1944335414165633"></a><a name="p1944335414165633"></a>A constructor used to create a <strong id="b1714496153165633"><a name="b1714496153165633"></a><a name="b1714496153165633"></a><a href="OHOS-Text.md">Text</a></strong> instance. </p>
</td>
</tr>
<tr id="row834925338165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1564013751165633"><a name="p1564013751165633"></a><a name="p1564013751165633"></a><a href="Graphic.md#gae15585b395b286ee404a57a61baa81f1">~Text</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p807359014165633"><a name="p807359014165633"></a><a name="p807359014165633"></a>virtual </p>
<p id="p784109995165633"><a name="p784109995165633"></a><a name="p784109995165633"></a>A destructor used to delete the <strong id="b1213956191165633"><a name="b1213956191165633"></a><a name="b1213956191165633"></a><a href="OHOS-Text.md">Text</a></strong> instance. </p>
</td>
</tr>
<tr id="row402857692165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p227627241165633"><a name="p227627241165633"></a><a name="p227627241165633"></a><a href="Graphic.md#gaf4c592a07fe20af21e0ddae2d8203d96">SetText</a> (const char *text)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p573368035165633"><a name="p573368035165633"></a><a name="p573368035165633"></a>void </p>
<p id="p1032867720165633"><a name="p1032867720165633"></a><a name="p1032867720165633"></a>Sets the content for this text. </p>
</td>
</tr>
<tr id="row982487907165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1339087735165633"><a name="p1339087735165633"></a><a name="p1339087735165633"></a><a href="Graphic.md#gafcc64349913763e8d7feaf7bd9cbd639">GetText</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p705228622165633"><a name="p705228622165633"></a><a name="p705228622165633"></a>const char * </p>
<p id="p792697927165633"><a name="p792697927165633"></a><a name="p792697927165633"></a>Obtains the content of this text. </p>
</td>
</tr>
<tr id="row946048689165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1625292339165633"><a name="p1625292339165633"></a><a name="p1625292339165633"></a><a href="Graphic.md#ga1c1a26e57098662f787a1bb44bb9da8c">SetFont</a> (const char *name, uint8_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1516746392165633"><a name="p1516746392165633"></a><a name="p1516746392165633"></a>void </p>
<p id="p2034133132165633"><a name="p2034133132165633"></a><a name="p2034133132165633"></a>Sets the font name and size. </p>
</td>
</tr>
<tr id="row351397052165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p216260506165633"><a name="p216260506165633"></a><a name="p216260506165633"></a><a href="Graphic.md#gac27135182c89eabec65e22df079dc413">SetFontId</a> (uint8_t fontId)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p623579889165633"><a name="p623579889165633"></a><a name="p623579889165633"></a>void </p>
<p id="p263047102165633"><a name="p263047102165633"></a><a name="p263047102165633"></a>Sets the font ID. </p>
</td>
</tr>
<tr id="row633299936165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p580416942165633"><a name="p580416942165633"></a><a name="p580416942165633"></a><a href="Graphic.md#ga32ba629806e9d8553bbcd441b4e66d55">GetFontId</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1987603744165633"><a name="p1987603744165633"></a><a name="p1987603744165633"></a>uint8_t </p>
<p id="p1252945984165633"><a name="p1252945984165633"></a><a name="p1252945984165633"></a>Obtains the font ID. </p>
</td>
</tr>
<tr id="row1736979044165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2054091703165633"><a name="p2054091703165633"></a><a name="p2054091703165633"></a><a href="Graphic.md#ga96801aa6350a8533496b0718d67f0b9c">SetDirect</a> (<a href="Graphic.md#ga0c108f97781843f67c101b47b6c00cf0">UITextLanguageDirect</a> direct)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1225371140165633"><a name="p1225371140165633"></a><a name="p1225371140165633"></a>void </p>
<p id="p338431257165633"><a name="p338431257165633"></a><a name="p338431257165633"></a>Sets the direction for this text. </p>
</td>
</tr>
<tr id="row1809650745165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p182268786165633"><a name="p182268786165633"></a><a name="p182268786165633"></a><a href="Graphic.md#gacd469d16b0f3a8e7406d736f5e857996">GetDirect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1243707535165633"><a name="p1243707535165633"></a><a name="p1243707535165633"></a><a href="Graphic.md#ga0c108f97781843f67c101b47b6c00cf0">UITextLanguageDirect</a> </p>
<p id="p1658702644165633"><a name="p1658702644165633"></a><a name="p1658702644165633"></a>Obtains the direction of this text. </p>
</td>
</tr>
<tr id="row341994769165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1915730520165633"><a name="p1915730520165633"></a><a name="p1915730520165633"></a><a href="Graphic.md#gad4721f5014971f6017aaaa5cc0af6845">SetAlign</a> (<a href="Graphic.md#ga3f99b58f731a37cacde72d5e0c934593">UITextLanguageAlignment</a> horizontalAlign, <a href="Graphic.md#ga3f99b58f731a37cacde72d5e0c934593">UITextLanguageAlignment</a> verticalAlign=TEXT_ALIGNMENT_TOP)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p594617937165633"><a name="p594617937165633"></a><a name="p594617937165633"></a>void </p>
<p id="p68744692165633"><a name="p68744692165633"></a><a name="p68744692165633"></a>Sets the alignment mode for this text. </p>
</td>
</tr>
<tr id="row55114541165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p888015188165633"><a name="p888015188165633"></a><a name="p888015188165633"></a><a href="Graphic.md#ga3c17868fb06a77f43587c67de4ca5ab6">GetHorAlign</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p682289636165633"><a name="p682289636165633"></a><a name="p682289636165633"></a><a href="Graphic.md#ga3f99b58f731a37cacde72d5e0c934593">UITextLanguageAlignment</a> </p>
<p id="p1657776201165633"><a name="p1657776201165633"></a><a name="p1657776201165633"></a>Obtains the horizontal alignment mode. </p>
</td>
</tr>
<tr id="row1599267286165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1905952365165633"><a name="p1905952365165633"></a><a name="p1905952365165633"></a><a href="Graphic.md#gac312f642e12cfad8d974f8159984864e">GetVerAlign</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1680202971165633"><a name="p1680202971165633"></a><a name="p1680202971165633"></a><a href="Graphic.md#ga3f99b58f731a37cacde72d5e0c934593">UITextLanguageAlignment</a> </p>
<p id="p342012524165633"><a name="p342012524165633"></a><a name="p342012524165633"></a>Obtains the vertical alignment mode. </p>
</td>
</tr>
<tr id="row1088464854165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1150096059165633"><a name="p1150096059165633"></a><a name="p1150096059165633"></a><a href="Graphic.md#ga2ec83b586a0a7ebe402bb70a31be2ca6">SetTextRotation</a> (LabelRotateDegree angle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1944511508165633"><a name="p1944511508165633"></a><a name="p1944511508165633"></a>void </p>
<p id="p1032713718165633"><a name="p1032713718165633"></a><a name="p1032713718165633"></a>Sets the clockwise rotation angle for this text. </p>
</td>
</tr>
<tr id="row652051122165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1929110061165633"><a name="p1929110061165633"></a><a name="p1929110061165633"></a><a href="Graphic.md#ga2dcc364f56ffa8bada573c7f96c92b0e">GetTextRotation</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1201565555165633"><a name="p1201565555165633"></a><a name="p1201565555165633"></a>LabelRotateDegree </p>
<p id="p1687379663165633"><a name="p1687379663165633"></a><a name="p1687379663165633"></a>Obtains the clockwise rotation degree of this text. </p>
</td>
</tr>
<tr id="row232624534165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1867399125165633"><a name="p1867399125165633"></a><a name="p1867399125165633"></a><a href="Graphic.md#gae36f3e226f23d8d7dff174054f60a741">GetTextRotateDegree</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p895424853165633"><a name="p895424853165633"></a><a name="p895424853165633"></a>uint16_t </p>
<p id="p1946723013165633"><a name="p1946723013165633"></a><a name="p1946723013165633"></a>Obtains the number of text rotation degrees. </p>
</td>
</tr>
<tr id="row932198189165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1092458929165633"><a name="p1092458929165633"></a><a name="p1092458929165633"></a><a href="Graphic.md#ga7e3e2deccb36992428d7984681329f09">GetTextSize</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p645998932165633"><a name="p645998932165633"></a><a name="p645998932165633"></a><a href="OHOS-Point.md">Point</a> </p>
<p id="p566515519165633"><a name="p566515519165633"></a><a name="p566515519165633"></a>Obtains the size of this text. </p>
</td>
</tr>
<tr id="row1819373501165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1627429230165633"><a name="p1627429230165633"></a><a name="p1627429230165633"></a><a href="Graphic.md#ga7aa8b64ece3c4b3bf592dc88fc7c11d2">SetExpandWidth</a> (bool expand)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1687676546165633"><a name="p1687676546165633"></a><a name="p1687676546165633"></a>void </p>
<p id="p1827816160165633"><a name="p1827816160165633"></a><a name="p1827816160165633"></a>Sets whether to adapt the component width to this text. </p>
</td>
</tr>
<tr id="row1549808378165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1789544778165633"><a name="p1789544778165633"></a><a name="p1789544778165633"></a><a href="Graphic.md#gaab55ac2d3f8e45b4bfb5fd5ae07d1edd">IsExpandWidth</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p356080775165633"><a name="p356080775165633"></a><a name="p356080775165633"></a>bool </p>
<p id="p1084599348165633"><a name="p1084599348165633"></a><a name="p1084599348165633"></a>Checks whether the component width adapts to this text. </p>
</td>
</tr>
<tr id="row2102456337165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1984471995165633"><a name="p1984471995165633"></a><a name="p1984471995165633"></a><a href="Graphic.md#gac08f297a1593424d754450c75bc47045">SetExpandHeight</a> (bool expand)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1635658824165633"><a name="p1635658824165633"></a><a name="p1635658824165633"></a>void </p>
<p id="p1080179379165633"><a name="p1080179379165633"></a><a name="p1080179379165633"></a>Sets whether to adapt the component height to this text. </p>
</td>
</tr>
<tr id="row571448025165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p711006266165633"><a name="p711006266165633"></a><a name="p711006266165633"></a><a href="Graphic.md#ga09475a9cd4e86b19d4c3d4206ea5ffc6">IsExpandHeight</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1819873151165633"><a name="p1819873151165633"></a><a name="p1819873151165633"></a>bool </p>
<p id="p494608104165633"><a name="p494608104165633"></a><a name="p494608104165633"></a>Checks whether the component height adapts to this text. </p>
</td>
</tr>
<tr id="row1326402185165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1867643070165633"><a name="p1867643070165633"></a><a name="p1867643070165633"></a><a href="Graphic.md#ga302dc8ff172b67c104363710f4b53cb0">GetEllipsisIndex</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;textRect, const <a href="OHOS-Style.md">Style</a> &amp;style)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1215977900165633"><a name="p1215977900165633"></a><a name="p1215977900165633"></a>uint16_t </p>
<p id="p377473637165633"><a name="p377473637165633"></a><a name="p377473637165633"></a>Obtains the index of the character from where text will be replaced by ellipses based on the text rectangle and style. </p>
</td>
</tr>
<tr id="row1312798439165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p216907866165633"><a name="p216907866165633"></a><a name="p216907866165633"></a><a href="Graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p380845889165633"><a name="p380845889165633"></a><a name="p380845889165633"></a>void * </p>
<p id="p84227341165633"><a name="p84227341165633"></a><a name="p84227341165633"></a>Overrides the <strong id="b1565272995165633"><a name="b1565272995165633"></a><a name="b1565272995165633"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row410240502165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p889584639165633"><a name="p889584639165633"></a><a name="p889584639165633"></a><a href="Graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p450455343165633"><a name="p450455343165633"></a><a name="p450455343165633"></a>void </p>
<p id="p991539012165633"><a name="p991539012165633"></a><a name="p991539012165633"></a>Overrides the <strong id="b1380469622165633"><a name="b1380469622165633"></a><a name="b1380469622165633"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

## Static Public Attributes<a name="pub-static-attribs"></a>

<a name="table1958888601165633"></a>
<table><thead align="left"><tr id="row337961446165633"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p636306486165633"><a name="p636306486165633"></a><a name="p636306486165633"></a>Static Public Attribute Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2055534881165633"><a name="p2055534881165633"></a><a name="p2055534881165633"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1094300976165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p399550119165633"><a name="p399550119165633"></a><a name="p399550119165633"></a><a href="Graphic.md#gaeacbcd7308bba53ba1154424143cd349">TEXT_ELLIPSIS_END_INV</a> = 0xFFFF</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">&nbsp;</td>
</tr>
</tbody>
</table>

