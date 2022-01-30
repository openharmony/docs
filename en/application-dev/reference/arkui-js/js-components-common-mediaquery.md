# Media Query<a name="EN-US_TOPIC_0000001173164721"></a>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>-   The  **media**  attribute uses the actual size, physical pixel, and screen resolution of the device by default. Do not confuse them with the configuration based on basic screen width 720 px.

Media query is widely used on mobile devices. You may need to frequently modify the application style based on the device type or specific features and device parameters \(such as the screen resolution\). To keep up with your requirements, the media query component provides the following features:

1.  Allows you to design different layouts matching the device and application attributes.
2.  Synchronously updates the application page layouts when your screen changes dynamically \(for example, in the event of screen splitting or landscape/portrait orientation switching\).

## CSS Syntax Rules<a name="section168919480313"></a>

Use @media to import query statements. The rules are as follows:

```
@media [media-type] [and|not|only] [(media-feature)] {
  CSS-Code;
}
```

Examples:

@media screen and \(round-screen: true\) \{ … \} // The condition is met when the device screen is round.

@media \(max-height: 800\) \{ … \} // Range query. CSS level 3 is used.

@media \(height <= 800\) \{ ... \} // Range query. CSS level 4 is used, and the statement is equivalent to that of CSS level 3.

@media screen and \(device-type: tv\) or \(resolution < 2\) \{ ... \} // Multi-condition query that contains the media type and multiple media features.

## Referencing Resources on a Page<a name="section1993557745"></a>

Use @import to import media query. The rule is as follows:

```
@import url [media-type] [and|not|only] [(media-feature)];
```

Sample code:

```
@import '../common/style.css' screen and (min-width: 600) and (max-width: 1200);
```

## Media Type<a name="section17366633144"></a>

<a name="table153618443914"></a>
<table><thead align="left"><tr id="row143684113916"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p0361541396"><a name="p0361541396"></a><a name="p0361541396"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p133684203912"><a name="p133684203912"></a><a name="p133684203912"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1736124173913"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p836144193919"><a name="p836144193919"></a><a name="p836144193919"></a>screen</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p19361415397"><a name="p19361415397"></a><a name="p19361415397"></a>Media query based on screen-related parameters</p>
</td>
</tr>
</tbody>
</table>

## Media Logical Operation<a name="section9949248948"></a>

Media logical operators \(and, or, not, and only\) are used to implement complex media query. They can also be combined using comma \(,\). The following table describes the operators.

**Table  1**  Media logical operators

<a name="table885321414713"></a>
<table><thead align="left"><tr id="row68533142713"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p4853114372"><a name="p4853114372"></a><a name="p4853114372"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p8853131419715"><a name="p8853131419715"></a><a name="p8853131419715"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1485312143720"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p2854914679"><a name="p2854914679"></a><a name="p2854914679"></a>and</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p16614211014"><a name="p16614211014"></a><a name="p16614211014"></a>The <strong id="b58531219133515"><a name="b58531219133515"></a><a name="b58531219133515"></a>and</strong> operator is used to combine multiple media features into a media query, in a logical AND operation. The query is valid only when all media features are true. It can also combine media types and media functions.</p>
<p id="p1985411145715"><a name="p1985411145715"></a><a name="p1985411145715"></a>For example, <strong id="b173711673169"><a name="b173711673169"></a><a name="b173711673169"></a>screen and (device-type: wearable) and (max-height: 600)</strong> indicates that the query is valid when the device is a wearable and the maximum height of the application is less than or equal to 600 pixels.</p>
</td>
</tr>
<tr id="row1185414146717"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p8854191414716"><a name="p8854191414716"></a><a name="p8854191414716"></a>not</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p203046566106"><a name="p203046566106"></a><a name="p203046566106"></a>The <strong id="b192160136403"><a name="b192160136403"></a><a name="b192160136403"></a>not</strong> operator is used to perform a logical negation for a media query. <strong id="b6400101184118"><a name="b6400101184118"></a><a name="b6400101184118"></a>true</strong> is returned if the query condition is not met. Otherwise, <strong id="b0448111994110"><a name="b0448111994110"></a><a name="b0448111994110"></a>false</strong> is returned. In a media query list, logical negation is performed only for the media query using the <strong id="b395945418471"><a name="b395945418471"></a><a name="b395945418471"></a>not</strong> operator.</p>
<p id="p156455001010"><a name="p156455001010"></a><a name="p156455001010"></a>For example, <strong id="b1652072344913"><a name="b1652072344913"></a><a name="b1652072344913"></a>not screen and (min-height: 50) and (max-height: 600)</strong> indicates that the query is valid when the height of the application is less than 50 pixels or greater than 600 pixels.</p>
<div class="note" id="note14802175917349"><a name="note14802175917349"></a><a name="note14802175917349"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p10802165913349"><a name="p10802165913349"></a><a name="p10802165913349"></a>You must specify the media type when using the <strong id="b98446326516"><a name="b98446326516"></a><a name="b98446326516"></a>not</strong> operator.</p>
</div></div>
</td>
</tr>
<tr id="row7854914278"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p285421418718"><a name="p285421418718"></a><a name="p285421418718"></a>only</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p052516221183"><a name="p052516221183"></a><a name="p052516221183"></a>The <strong id="b1440018175537"><a name="b1440018175537"></a><a name="b1440018175537"></a>only</strong> operator applies the selected style only when the entire expression is matched. It can be used to prevent ambiguity while some browsers of earlier versions are processing the statements containing both media types and media features. For example:</p>
<p id="p79641292049"><a name="p79641292049"></a><a name="p79641292049"></a>screen and (min-height: 50)</p>
<p id="p1291414473456"><a name="p1291414473456"></a><a name="p1291414473456"></a>The browsers of earlier versions would mislead this sentence into <strong id="b4962851171020"><a name="b4962851171020"></a><a name="b4962851171020"></a>screen</strong>, causing the fact that the specified style is applied when only the media type is matched. In this case, the <strong id="b1075418316593"><a name="b1075418316593"></a><a name="b1075418316593"></a>only</strong> operator can be used to avoid this problem.</p>
<div class="note" id="note38311047113516"><a name="note38311047113516"></a><a name="note38311047113516"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p1831194717358"><a name="p1831194717358"></a><a name="p1831194717358"></a>You must specify the media type when using the <strong id="b33691344533"><a name="b33691344533"></a><a name="b33691344533"></a>only</strong> operator.</p>
</div></div>
</td>
</tr>
<tr id="row685471419718"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p885415141877"><a name="p885415141877"></a><a name="p885415141877"></a>,(comma)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p102861117191212"><a name="p102861117191212"></a><a name="p102861117191212"></a>The comma operator is used to combine multiple media features into one media query, in a logical OR operation. The query is valid if a media feature is true. The effect of a comma operator is equivalent to that of the <strong id="b6137112318212"><a name="b6137112318212"></a><a name="b6137112318212"></a>or</strong> operator.</p>
<p id="p9854131415710"><a name="p9854131415710"></a><a name="p9854131415710"></a>For example, <strong id="b581719430310"><a name="b581719430310"></a><a name="b581719430310"></a>screen and (min-height: 1000), (round-screen: true)</strong> evaluates to true when the application height is greater than or equal to 1000 pixels or the device screen is rounded.</p>
</td>
</tr>
<tr id="row88546141710"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p168543144714"><a name="p168543144714"></a><a name="p168543144714"></a>or</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p45834951417"><a name="p45834951417"></a><a name="p45834951417"></a>The <strong id="b345813341814"><a name="b345813341814"></a><a name="b345813341814"></a>or</strong> operator is used to combine multiple media features into one media query, in a logical OR operation. The query is valid if a media feature is true.</p>
<p id="p385419141878"><a name="p385419141878"></a><a name="p385419141878"></a>For example, <strong id="b67899251713"><a name="b67899251713"></a><a name="b67899251713"></a>screen and (max-height: 1000) or (round-screen: true)</strong> evaluates to true when the application height is less than or equal to 1000 pixels or the device screen is rounded.</p>
</td>
</tr>
</tbody>
</table>

At MediaQuery Level 4, range query is imported so that you can use the operators including <=, \>=, <, and \> besides the max- and min-operators.

**Table  2**  Media logical range operators

<a name="table1668215910289"></a>
<table><thead align="left"><tr id="row5683090285"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p468319912820"><a name="p468319912820"></a><a name="p468319912820"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p46831916284"><a name="p46831916284"></a><a name="p46831916284"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1468318918281"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p49711232172812"><a name="p49711232172812"></a><a name="p49711232172812"></a>&lt;=</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001173164721_p136831596288"><a name="en-us_topic_0000001173164721_p136831596288"></a><a name="en-us_topic_0000001173164721_p136831596288"></a>Less than or equal to, for example, screen and (50 &lt;= height).</p>
</td>
</tr>
<tr id="row1668311912810"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p116831991284"><a name="p116831991284"></a><a name="p116831991284"></a>&gt;=</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001173164721_p453664715285"><a name="en-us_topic_0000001173164721_p453664715285"></a><a name="en-us_topic_0000001173164721_p453664715285"></a>Greater than or equal to, for example, screen and (600 &gt;= height).</p>
</td>
</tr>
<tr id="row868311910281"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p146837922814"><a name="p146837922814"></a><a name="p146837922814"></a>&lt;</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001173164721_p3387258152815"><a name="en-us_topic_0000001173164721_p3387258152815"></a><a name="en-us_topic_0000001173164721_p3387258152815"></a>Less than, for example, screen and (50 &lt; height).</p>
</td>
</tr>
<tr id="row14896753202819"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p148971753172813"><a name="p148971753172813"></a><a name="p148971753172813"></a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001173164721_p10897195319286"><a name="en-us_topic_0000001173164721_p10897195319286"></a><a name="en-us_topic_0000001173164721_p10897195319286"></a>Greater than, for example, screen and (600 &gt; height).</p>
</td>
</tr>
</tbody>
</table>

## Media Features<a name="section192341841653"></a>

<a name="table108921335177"></a>
<table><thead align="left"><tr id="row4892113181716"><th class="cellrowborder" valign="top" width="49.96%" id="mcps1.1.3.1.1"><p id="p13892113101714"><a name="p13892113101714"></a><a name="p13892113101714"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="50.03999999999999%" id="mcps1.1.3.1.2"><p id="p1289210301711"><a name="p1289210301711"></a><a name="p1289210301711"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row489203101713"><td class="cellrowborder" valign="top" width="49.96%" headers="mcps1.1.3.1.1 "><p id="p1889213191718"><a name="p1889213191718"></a><a name="p1889213191718"></a>height</p>
</td>
<td class="cellrowborder" valign="top" width="50.03999999999999%" headers="mcps1.1.3.1.2 "><p id="p18892193111711"><a name="p18892193111711"></a><a name="p18892193111711"></a>Height of the display area on the application page.</p>
</td>
</tr>
<tr id="row689217301711"><td class="cellrowborder" valign="top" width="49.96%" headers="mcps1.1.3.1.1 "><p id="p289217314178"><a name="p289217314178"></a><a name="p289217314178"></a>min-height</p>
</td>
<td class="cellrowborder" valign="top" width="50.03999999999999%" headers="mcps1.1.3.1.2 "><p id="p1889213312176"><a name="p1889213312176"></a><a name="p1889213312176"></a>Minimum height of the display area on the application page.</p>
</td>
</tr>
<tr id="row389273101712"><td class="cellrowborder" valign="top" width="49.96%" headers="mcps1.1.3.1.1 "><p id="p889293191710"><a name="p889293191710"></a><a name="p889293191710"></a>max-height</p>
</td>
<td class="cellrowborder" valign="top" width="50.03999999999999%" headers="mcps1.1.3.1.2 "><p id="p1889214331718"><a name="p1889214331718"></a><a name="p1889214331718"></a>Maximum height of the display area on the application page.</p>
</td>
</tr>
<tr id="row18892153201712"><td class="cellrowborder" valign="top" width="49.96%" headers="mcps1.1.3.1.1 "><p id="p689212320171"><a name="p689212320171"></a><a name="p689212320171"></a>width</p>
</td>
<td class="cellrowborder" valign="top" width="50.03999999999999%" headers="mcps1.1.3.1.2 "><p id="p78925319176"><a name="p78925319176"></a><a name="p78925319176"></a>Width of the display area on the application page.</p>
</td>
</tr>
<tr id="row1689211313176"><td class="cellrowborder" valign="top" width="49.96%" headers="mcps1.1.3.1.1 "><p id="p1089215321715"><a name="p1089215321715"></a><a name="p1089215321715"></a>min-width</p>
</td>
<td class="cellrowborder" valign="top" width="50.03999999999999%" headers="mcps1.1.3.1.2 "><p id="p1189363121716"><a name="p1189363121716"></a><a name="p1189363121716"></a>Minimum width of the display area on the application page.</p>
</td>
</tr>
<tr id="row1989311319174"><td class="cellrowborder" valign="top" width="49.96%" headers="mcps1.1.3.1.1 "><p id="p208936381719"><a name="p208936381719"></a><a name="p208936381719"></a>max-width</p>
</td>
<td class="cellrowborder" valign="top" width="50.03999999999999%" headers="mcps1.1.3.1.2 "><p id="p7893103161712"><a name="p7893103161712"></a><a name="p7893103161712"></a>Maximum width of the display area on the application page.</p>
</td>
</tr>
<tr id="row108937312176"><td class="cellrowborder" valign="top" width="49.96%" headers="mcps1.1.3.1.1 "><p id="p089317321714"><a name="p089317321714"></a><a name="p089317321714"></a>resolution</p>
</td>
<td class="cellrowborder" valign="top" width="50.03999999999999%" headers="mcps1.1.3.1.2 "><p id="p1334199154717"><a name="p1334199154717"></a><a name="p1334199154717"></a>Resolution of the device. The unit can be dpi, dppx, or dpcm.</p>
<a name="ul194277378472"></a><a name="ul194277378472"></a><ul id="ul194277378472"><li>dpi indicates the number of physical pixels per inch. 1 dpi ≈ 0.39 dpcm.</li><li>dpcm indicates the number of physical pixels per centimeter. 1 dpcm ≈ 2.54 dpi.</li><li>dppx indicates the number of physical pixels in each pixel. The unit is 96 px = 1 inch, which is different from the calculation method of the pixel unit on the page. 1 dppx = 96 dpi.</li></ul>
</td>
</tr>
<tr id="row17126854121812"><td class="cellrowborder" valign="top" width="49.96%" headers="mcps1.1.3.1.1 "><p id="p1127175491814"><a name="p1127175491814"></a><a name="p1127175491814"></a>min-resolution</p>
</td>
<td class="cellrowborder" valign="top" width="50.03999999999999%" headers="mcps1.1.3.1.2 "><p id="p112735411187"><a name="p112735411187"></a><a name="p112735411187"></a>Minimum device resolution.</p>
</td>
</tr>
<tr id="row96981254171812"><td class="cellrowborder" valign="top" width="49.96%" headers="mcps1.1.3.1.1 "><p id="p96992542188"><a name="p96992542188"></a><a name="p96992542188"></a>max-resolution</p>
</td>
<td class="cellrowborder" valign="top" width="50.03999999999999%" headers="mcps1.1.3.1.2 "><p id="p6699125451818"><a name="p6699125451818"></a><a name="p6699125451818"></a>Maximum device resolution.</p>
</td>
</tr>
<tr id="row03341955131819"><td class="cellrowborder" valign="top" width="49.96%" headers="mcps1.1.3.1.1 "><p id="p173349555184"><a name="p173349555184"></a><a name="p173349555184"></a>orientation</p>
</td>
<td class="cellrowborder" valign="top" width="50.03999999999999%" headers="mcps1.1.3.1.2 "><p id="p9787195619207"><a name="p9787195619207"></a><a name="p9787195619207"></a>Screen orientation.</p>
<p id="p6781934164019"><a name="p6781934164019"></a><a name="p6781934164019"></a>Options are as follows:</p>
<a name="ul1570584418402"></a><a name="ul1570584418402"></a><ul id="ul1570584418402"><li><strong id="b2016814371471"><a name="b2016814371471"></a><a name="b2016814371471"></a>orientation: portrait</strong>: portrait screen orientation</li><li><strong id="b18780227184"><a name="b18780227184"></a><a name="b18780227184"></a>orientation: landscape</strong>: landscape screen orientation</li></ul>
</td>
</tr>
<tr id="row16484183812015"><td class="cellrowborder" valign="top" width="49.96%" headers="mcps1.1.3.1.1 "><p id="p6485163892016"><a name="p6485163892016"></a><a name="p6485163892016"></a>aspect-ratio</p>
</td>
<td class="cellrowborder" valign="top" width="50.03999999999999%" headers="mcps1.1.3.1.2 "><p id="p1587614152112"><a name="p1587614152112"></a><a name="p1587614152112"></a>Ratio of the width to the height of the display area on the application page.</p>
<p id="p10485138182013"><a name="p10485138182013"></a><a name="p10485138182013"></a>Example: <strong id="b1156626191620"><a name="b1156626191620"></a><a name="b1156626191620"></a>aspect-ratio:1/2</strong></p>
</td>
</tr>
<tr id="row1365523972016"><td class="cellrowborder" valign="top" width="49.96%" headers="mcps1.1.3.1.1 "><p id="p165573922013"><a name="p165573922013"></a><a name="p165573922013"></a>min-aspect-ratio</p>
</td>
<td class="cellrowborder" valign="top" width="50.03999999999999%" headers="mcps1.1.3.1.2 "><p id="p565623919203"><a name="p565623919203"></a><a name="p565623919203"></a>Minimum ratio of the width to the height of the display area on the application page.</p>
</td>
</tr>
<tr id="row13168408209"><td class="cellrowborder" valign="top" width="49.96%" headers="mcps1.1.3.1.1 "><p id="p1131644020200"><a name="p1131644020200"></a><a name="p1131644020200"></a>max-aspect-ratio</p>
</td>
<td class="cellrowborder" valign="top" width="50.03999999999999%" headers="mcps1.1.3.1.2 "><p id="p3316164032014"><a name="p3316164032014"></a><a name="p3316164032014"></a>Maximum ratio of the width to the height of the display area on the application page.</p>
</td>
</tr>
<tr id="row20982240192014"><td class="cellrowborder" valign="top" width="49.96%" headers="mcps1.1.3.1.1 "><p id="p18982140142017"><a name="p18982140142017"></a><a name="p18982140142017"></a>device-height</p>
</td>
<td class="cellrowborder" valign="top" width="50.03999999999999%" headers="mcps1.1.3.1.2 "><p id="p1198254032010"><a name="p1198254032010"></a><a name="p1198254032010"></a>Height of the device.</p>
</td>
</tr>
<tr id="row3944152920226"><td class="cellrowborder" valign="top" width="49.96%" headers="mcps1.1.3.1.1 "><p id="p494411291223"><a name="p494411291223"></a><a name="p494411291223"></a>min-device-height</p>
</td>
<td class="cellrowborder" valign="top" width="50.03999999999999%" headers="mcps1.1.3.1.2 "><p id="p9944112915227"><a name="p9944112915227"></a><a name="p9944112915227"></a>Minimum height of the device.</p>
</td>
</tr>
<tr id="row10362830102215"><td class="cellrowborder" valign="top" width="49.96%" headers="mcps1.1.3.1.1 "><p id="p436319306222"><a name="p436319306222"></a><a name="p436319306222"></a>max-device-height</p>
</td>
<td class="cellrowborder" valign="top" width="50.03999999999999%" headers="mcps1.1.3.1.2 "><p id="p5363230142216"><a name="p5363230142216"></a><a name="p5363230142216"></a>Maximum height of the device.</p>
</td>
</tr>
<tr id="row31411431152213"><td class="cellrowborder" valign="top" width="49.96%" headers="mcps1.1.3.1.1 "><p id="p714219311224"><a name="p714219311224"></a><a name="p714219311224"></a>device-width</p>
</td>
<td class="cellrowborder" valign="top" width="50.03999999999999%" headers="mcps1.1.3.1.2 "><p id="p114273117223"><a name="p114273117223"></a><a name="p114273117223"></a>Width of the device.</p>
</td>
</tr>
<tr id="row8465184718239"><td class="cellrowborder" valign="top" width="49.96%" headers="mcps1.1.3.1.1 "><p id="p646515471232"><a name="p646515471232"></a><a name="p646515471232"></a>min-device-width</p>
</td>
<td class="cellrowborder" valign="top" width="50.03999999999999%" headers="mcps1.1.3.1.2 "><p id="p44654479235"><a name="p44654479235"></a><a name="p44654479235"></a>Minimum width of the device.</p>
</td>
</tr>
<tr id="row98591247182319"><td class="cellrowborder" valign="top" width="49.96%" headers="mcps1.1.3.1.1 "><p id="p1685964722310"><a name="p1685964722310"></a><a name="p1685964722310"></a>max-device-width</p>
</td>
<td class="cellrowborder" valign="top" width="50.03999999999999%" headers="mcps1.1.3.1.2 "><p id="p1085954720232"><a name="p1085954720232"></a><a name="p1085954720232"></a>Maximum width of the device.</p>
</td>
</tr>
<tr id="row12501138114319"><td class="cellrowborder" valign="top" width="49.96%" headers="mcps1.1.3.1.1 "><p id="p925213810436"><a name="p925213810436"></a><a name="p925213810436"></a>round-screen</p>
</td>
<td class="cellrowborder" valign="top" width="50.03999999999999%" headers="mcps1.1.3.1.2 "><p id="p2252173810430"><a name="p2252173810430"></a><a name="p2252173810430"></a>Screen type. The value <strong id="b48688335141"><a name="b48688335141"></a><a name="b48688335141"></a>true</strong> indicates a circular screen, and <strong id="b1595424471412"><a name="b1595424471412"></a><a name="b1595424471412"></a>false</strong> indicates a non-circular screen.</p>
</td>
</tr>
<tr id="row5462165172517"><td class="cellrowborder" valign="top" width="49.96%" headers="mcps1.1.3.1.1 "><p id="a74279e95586943efad8e81aa02496d6d"><a name="a74279e95586943efad8e81aa02496d6d"></a><a name="a74279e95586943efad8e81aa02496d6d"></a>dark-mode<sup id="sup182210324279"><a name="sup182210324279"></a><a name="sup182210324279"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="50.03999999999999%" headers="mcps1.1.3.1.2 "><p id="p88509314207"><a name="p88509314207"></a><a name="p88509314207"></a>Whether the device is in dark mode. The value is <strong id="b535842285711"><a name="b535842285711"></a><a name="b535842285711"></a>true</strong> if the device is in dark mode and <strong id="b63668223573"><a name="b63668223573"></a><a name="b63668223573"></a>false</strong> otherwise.</p>
</td>
</tr>
</tbody>
</table>

## Sample Code<a name="section1018513818615"></a>

-   Sample code of the common media feature is as follows:

```
<!-- xxx.hml -->
<div>
  <div class="container">
    <text class="title">Hello World</text>
  </div>
</div>
```

```
/* xxx.css */
.container {
  width: 300px;
  height: 600px;
  background-color: #008000;
}
@media (device-type: tv) {
  .container {
    width: 500px;
    height: 500px;
    background-color: #fa8072;
  }
} 
@media (device-type: wearable) {
  .container {
    width: 300px;
    height: 300px;
    background-color: #008b8b;
  }
} 
```

