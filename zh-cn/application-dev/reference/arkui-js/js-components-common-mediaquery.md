# 媒体查询<a name="ZH-CN_TOPIC_0000001173164721"></a>

媒体查询（Media Query）在移动设备上应用十分广泛，开发者经常需要根据设备的大致类型或者特定的特征和设备参数（例如屏幕分辨率）来修改应用的样式。为此媒体查询提供了如下功能：

1.  针对设备和应用的属性信息，可以设计出相匹配的布局样式。
2.  当屏幕发生动态改变时（比如分屏、横竖屏切换），应用页面布局同步更新。

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>media属性值默认为设备的真实尺寸大小、物理像素和真实的屏幕分辨率。请勿与以720px为基准的项目配置宽度px混淆。

## CSS语法规则<a name="section168919480313"></a>

使用@media来引入查询语句，具体规则如下：

```
@media [media-type] [and|not|only] [(media-feature)] {
  CSS-Code;
}
```

例子：

@media screen and \(round-screen: true\) \{ … \} // 当设备屏幕是圆形时条件成立

@media \(max-height: 800\) \{ … \} // 范围查询，CSS level 3 写法

@media \(height <= 800\) \{ … \} // 范围查询，CSS level 4 写法，与CSS level3写法等价

@media screen and \(device-type: tv\) or \(resolution < 2\) \{ … \} // 同时包含媒体类型和多个媒体特征的多条件复杂语句查询

## 页面中引用资源<a name="section1993557745"></a>

通过@import方式引入媒体查询，具体使用方法如下：

```
@import url [media-type] [and|not|only] [(media-feature)];
```

例如：

```
@import '../common/style.css' screen and (min-width: 600) and (max-width: 1200);
```

## 媒体类型<a name="section17366633144"></a>

<a name="table153618443914"></a>
<table><thead align="left"><tr id="row143684113916"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p0361541396"><a name="p0361541396"></a><a name="p0361541396"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p133684203912"><a name="p133684203912"></a><a name="p133684203912"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1736124173913"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p836144193919"><a name="p836144193919"></a><a name="p836144193919"></a>screen</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p19361415397"><a name="p19361415397"></a><a name="p19361415397"></a>按屏幕相关参数进行媒体查询。</p>
</td>
</tr>
</tbody>
</table>

## 媒体逻辑操作<a name="section9949248948"></a>

媒体逻辑操作符：and、or、not、only用于构成复杂媒体查询，也可以通过comma（,）将其组合起来，详细解释说明如下表。

**表 1**  媒体逻辑操作符

<a name="table885321414713"></a>
<table><thead align="left"><tr id="row68533142713"><th class="cellrowborder" valign="top" width="20.02%" id="mcps1.2.3.1.1"><p id="p4853114372"><a name="p4853114372"></a><a name="p4853114372"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="79.97999999999999%" id="mcps1.2.3.1.2"><p id="p8853131419715"><a name="p8853131419715"></a><a name="p8853131419715"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1485312143720"><td class="cellrowborder" valign="top" width="20.02%" headers="mcps1.2.3.1.1 "><p id="p2854914679"><a name="p2854914679"></a><a name="p2854914679"></a>and</p>
</td>
<td class="cellrowborder" valign="top" width="79.97999999999999%" headers="mcps1.2.3.1.2 "><p id="p16614211014"><a name="p16614211014"></a><a name="p16614211014"></a>将多个媒体特征（Media Feature）以“与”的方式连接成一个媒体查询，只有当所有媒体特征都为true，查询条件成立。另外，它还可以将媒体类型和媒体功能结合起来。</p>
<p id="p1985411145715"><a name="p1985411145715"></a><a name="p1985411145715"></a>例如：screen and (device-type: wearable) and (max-height: 600) 表示当设备类型是智能穿戴同时应用的最大高度小于等于600个像素单位时成立。</p>
</td>
</tr>
<tr id="row1185414146717"><td class="cellrowborder" valign="top" width="20.02%" headers="mcps1.2.3.1.1 "><p id="p8854191414716"><a name="p8854191414716"></a><a name="p8854191414716"></a>not</p>
</td>
<td class="cellrowborder" valign="top" width="79.97999999999999%" headers="mcps1.2.3.1.2 "><p id="p203046566106"><a name="p203046566106"></a><a name="p203046566106"></a>取反媒体查询结果，媒体查询结果不成立时返回true，否则返回false。在媒体查询列表中应用not，则not仅取反应用它的媒体查询。</p>
<p id="p156455001010"><a name="p156455001010"></a><a name="p156455001010"></a>例如：not screen and (min-height: 50) and (max-height: 600) 表示当应用高度小于50个像素单位或者大于600个像素单位时成立。</p>
<div class="note" id="note14802175917349"><a name="note14802175917349"></a><a name="note14802175917349"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="p10802165913349"><a name="p10802165913349"></a><a name="p10802165913349"></a>使用not运算符时必须指定媒体类型。</p>
</div></div>
</td>
</tr>
<tr id="row7854914278"><td class="cellrowborder" valign="top" width="20.02%" headers="mcps1.2.3.1.1 "><p id="p285421418718"><a name="p285421418718"></a><a name="p285421418718"></a>only</p>
</td>
<td class="cellrowborder" valign="top" width="79.97999999999999%" headers="mcps1.2.3.1.2 "><p id="p052516221183"><a name="p052516221183"></a><a name="p052516221183"></a>当整个表达式都匹配时，才会应用选择的样式，可以应用在防止某些较早的版本的浏览器上产生歧义的场景。一些较早版本的浏览器对于同时包含了媒体类型和媒体特征的语句会产生歧义，比如：</p>
<p id="p79641292049"><a name="p79641292049"></a><a name="p79641292049"></a>screen and (min-height: 50)</p>
<p id="p1291414473456"><a name="p1291414473456"></a><a name="p1291414473456"></a>老版本浏览器会将这句话理解成screen，从而导致仅仅匹配到媒体类型（screen），就应用了指定样式，使用only可以很好地规避这种情况。</p>
<div class="note" id="note38311047113516"><a name="note38311047113516"></a><a name="note38311047113516"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="p1831194717358"><a name="p1831194717358"></a><a name="p1831194717358"></a>使用only时必须指定媒体类型。</p>
</div></div>
</td>
</tr>
<tr id="row685471419718"><td class="cellrowborder" valign="top" width="20.02%" headers="mcps1.2.3.1.1 "><p id="p885415141877"><a name="p885415141877"></a><a name="p885415141877"></a>,(comma)</p>
</td>
<td class="cellrowborder" valign="top" width="79.97999999999999%" headers="mcps1.2.3.1.2 "><p id="p102861117191212"><a name="p102861117191212"></a><a name="p102861117191212"></a>将多个媒体特征以“或”的方式连接成一个媒体查询，如果存在结果为true的媒体特征，则查询条件成立。其效果等同于or运算符。</p>
<p id="p9854131415710"><a name="p9854131415710"></a><a name="p9854131415710"></a>例如：screen and (min-height: 1000),  （round-screen：true） 表示当应用高度大于等于1000个像素单位或者设备屏幕是圆形时，条件成立。</p>
</td>
</tr>
<tr id="row88546141710"><td class="cellrowborder" valign="top" width="20.02%" headers="mcps1.2.3.1.1 "><p id="p168543144714"><a name="p168543144714"></a><a name="p168543144714"></a>or</p>
</td>
<td class="cellrowborder" valign="top" width="79.97999999999999%" headers="mcps1.2.3.1.2 "><p id="p45834951417"><a name="p45834951417"></a><a name="p45834951417"></a>将多个媒体特征以“或”的方式连接成一个媒体查询，如果存在结果为true的媒体特征，则查询条件成立。</p>
<p id="p385419141878"><a name="p385419141878"></a><a name="p385419141878"></a>例如：screen and (max-height: 1000) or  （round-screen：true）表示当应用高度小于等于1000个像素单位或者设备屏幕是圆形时，条件成立。</p>
</td>
</tr>
</tbody>
</table>

在MediaQuery Level 4中引入了范围查询，使其能够使用max-，min-的同时，也支持了<=，\>=，<，\>操作符。

**表 2**  媒体逻辑范围操作符

<a name="table1668215910289"></a>
<table><thead align="left"><tr id="row5683090285"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p468319912820"><a name="p468319912820"></a><a name="p468319912820"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p46831916284"><a name="p46831916284"></a><a name="p46831916284"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1468318918281"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p49711232172812"><a name="p49711232172812"></a><a name="p49711232172812"></a>&lt;=</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p136831596288"><a name="p136831596288"></a><a name="p136831596288"></a>小于等于，例如：screen and (50 &lt;= height)。</p>
</td>
</tr>
<tr id="row1668311912810"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p116831991284"><a name="p116831991284"></a><a name="p116831991284"></a>&gt;=</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p453664715285"><a name="p453664715285"></a><a name="p453664715285"></a>大于等于，例如：screen and (600 &gt;= height)。</p>
</td>
</tr>
<tr id="row868311910281"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p146837922814"><a name="p146837922814"></a><a name="p146837922814"></a>&lt;</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p3387258152815"><a name="p3387258152815"></a><a name="p3387258152815"></a>小于，例如：screen and (50 &lt; height)。</p>
</td>
</tr>
<tr id="row14896753202819"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p148971753172813"><a name="p148971753172813"></a><a name="p148971753172813"></a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p10897195319286"><a name="p10897195319286"></a><a name="p10897195319286"></a>大于，例如：screen and (600 &gt; height)。</p>
</td>
</tr>
</tbody>
</table>

## 媒体特征<a name="section192341841653"></a>

<a name="table108921335177"></a>
<table><thead align="left"><tr id="row4892113181716"><th class="cellrowborder" valign="top" width="34.11%" id="mcps1.1.3.1.1"><p id="p13892113101714"><a name="p13892113101714"></a><a name="p13892113101714"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="65.89%" id="mcps1.1.3.1.2"><p id="p1289210301711"><a name="p1289210301711"></a><a name="p1289210301711"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row489203101713"><td class="cellrowborder" valign="top" width="34.11%" headers="mcps1.1.3.1.1 "><p id="p1889213191718"><a name="p1889213191718"></a><a name="p1889213191718"></a>height</p>
</td>
<td class="cellrowborder" valign="top" width="65.89%" headers="mcps1.1.3.1.2 "><p id="p18892193111711"><a name="p18892193111711"></a><a name="p18892193111711"></a>应用页面显示区域的高度。</p>
</td>
</tr>
<tr id="row689217301711"><td class="cellrowborder" valign="top" width="34.11%" headers="mcps1.1.3.1.1 "><p id="p289217314178"><a name="p289217314178"></a><a name="p289217314178"></a>min-height</p>
</td>
<td class="cellrowborder" valign="top" width="65.89%" headers="mcps1.1.3.1.2 "><p id="p1889213312176"><a name="p1889213312176"></a><a name="p1889213312176"></a>应用页面显示区域的最小高度。</p>
</td>
</tr>
<tr id="row389273101712"><td class="cellrowborder" valign="top" width="34.11%" headers="mcps1.1.3.1.1 "><p id="p889293191710"><a name="p889293191710"></a><a name="p889293191710"></a>max-height</p>
</td>
<td class="cellrowborder" valign="top" width="65.89%" headers="mcps1.1.3.1.2 "><p id="p1889214331718"><a name="p1889214331718"></a><a name="p1889214331718"></a>应用页面显示区域的最大高度。</p>
</td>
</tr>
<tr id="row18892153201712"><td class="cellrowborder" valign="top" width="34.11%" headers="mcps1.1.3.1.1 "><p id="p689212320171"><a name="p689212320171"></a><a name="p689212320171"></a>width</p>
</td>
<td class="cellrowborder" valign="top" width="65.89%" headers="mcps1.1.3.1.2 "><p id="p78925319176"><a name="p78925319176"></a><a name="p78925319176"></a>应用页面显示区域的宽度。</p>
</td>
</tr>
<tr id="row1689211313176"><td class="cellrowborder" valign="top" width="34.11%" headers="mcps1.1.3.1.1 "><p id="p1089215321715"><a name="p1089215321715"></a><a name="p1089215321715"></a>min-width</p>
</td>
<td class="cellrowborder" valign="top" width="65.89%" headers="mcps1.1.3.1.2 "><p id="p1189363121716"><a name="p1189363121716"></a><a name="p1189363121716"></a>应用页面显示区域的最小宽度。</p>
</td>
</tr>
<tr id="row1989311319174"><td class="cellrowborder" valign="top" width="34.11%" headers="mcps1.1.3.1.1 "><p id="p208936381719"><a name="p208936381719"></a><a name="p208936381719"></a>max-width</p>
</td>
<td class="cellrowborder" valign="top" width="65.89%" headers="mcps1.1.3.1.2 "><p id="p7893103161712"><a name="p7893103161712"></a><a name="p7893103161712"></a>应用页面显示区域的最大宽度。</p>
</td>
</tr>
<tr id="row108937312176"><td class="cellrowborder" valign="top" width="34.11%" headers="mcps1.1.3.1.1 "><p id="p089317321714"><a name="p089317321714"></a><a name="p089317321714"></a>resolution</p>
</td>
<td class="cellrowborder" valign="top" width="65.89%" headers="mcps1.1.3.1.2 "><p id="p1334199154717"><a name="p1334199154717"></a><a name="p1334199154717"></a>设备的分辨率，支持dpi，dppx和dpcm单位。其中：</p>
<a name="ul194277378472"></a><a name="ul194277378472"></a><ul id="ul194277378472"><li>dpi表示每英寸中物理像素个数，1dpi≈0.39dpcm；</li><li>dpcm表示每厘米上的物理像素个数，1dpcm ≈ 2.54dpi；</li><li>dppx表示每个px中的物理像素数（此单位按96px=1英寸为基准，与页面中的px单位计算方式不同），1dppx = 96dpi。</li></ul>
</td>
</tr>
<tr id="row17126854121812"><td class="cellrowborder" valign="top" width="34.11%" headers="mcps1.1.3.1.1 "><p id="p1127175491814"><a name="p1127175491814"></a><a name="p1127175491814"></a>min-resolution</p>
</td>
<td class="cellrowborder" valign="top" width="65.89%" headers="mcps1.1.3.1.2 "><p id="p112735411187"><a name="p112735411187"></a><a name="p112735411187"></a>设备的最小分辨率。</p>
</td>
</tr>
<tr id="row96981254171812"><td class="cellrowborder" valign="top" width="34.11%" headers="mcps1.1.3.1.1 "><p id="p96992542188"><a name="p96992542188"></a><a name="p96992542188"></a>max-resolution</p>
</td>
<td class="cellrowborder" valign="top" width="65.89%" headers="mcps1.1.3.1.2 "><p id="p6699125451818"><a name="p6699125451818"></a><a name="p6699125451818"></a>设备的最大分辨率。</p>
</td>
</tr>
<tr id="row03341955131819"><td class="cellrowborder" valign="top" width="34.11%" headers="mcps1.1.3.1.1 "><p id="p173349555184"><a name="p173349555184"></a><a name="p173349555184"></a>orientation</p>
</td>
<td class="cellrowborder" valign="top" width="65.89%" headers="mcps1.1.3.1.2 "><p id="p9787195619207"><a name="p9787195619207"></a><a name="p9787195619207"></a>屏幕的方向。</p>
<p id="p6781934164019"><a name="p6781934164019"></a><a name="p6781934164019"></a>可选值：</p>
<a name="ul1570584418402"></a><a name="ul1570584418402"></a><ul id="ul1570584418402"><li>orientation: portrait（设备竖屏）</li><li>orientation: landscape（设备横屏）</li></ul>
</td>
</tr>
<tr id="row16484183812015"><td class="cellrowborder" valign="top" width="34.11%" headers="mcps1.1.3.1.1 "><p id="p6485163892016"><a name="p6485163892016"></a><a name="p6485163892016"></a>aspect-ratio</p>
</td>
<td class="cellrowborder" valign="top" width="65.89%" headers="mcps1.1.3.1.2 "><p id="p1587614152112"><a name="p1587614152112"></a><a name="p1587614152112"></a>应用页面显示区域的宽度与高度的比值。</p>
<p id="p10485138182013"><a name="p10485138182013"></a><a name="p10485138182013"></a>例如：aspect-ratio:1/2</p>
</td>
</tr>
<tr id="row1365523972016"><td class="cellrowborder" valign="top" width="34.11%" headers="mcps1.1.3.1.1 "><p id="p165573922013"><a name="p165573922013"></a><a name="p165573922013"></a>min-aspect-ratio</p>
</td>
<td class="cellrowborder" valign="top" width="65.89%" headers="mcps1.1.3.1.2 "><p id="p565623919203"><a name="p565623919203"></a><a name="p565623919203"></a>应用页面显示区域的宽度与高度的最小比值。</p>
</td>
</tr>
<tr id="row13168408209"><td class="cellrowborder" valign="top" width="34.11%" headers="mcps1.1.3.1.1 "><p id="p1131644020200"><a name="p1131644020200"></a><a name="p1131644020200"></a>max-aspect-ratio</p>
</td>
<td class="cellrowborder" valign="top" width="65.89%" headers="mcps1.1.3.1.2 "><p id="p3316164032014"><a name="p3316164032014"></a><a name="p3316164032014"></a>应用页面显示区域的宽度与高度的最大比值。</p>
</td>
</tr>
<tr id="row20982240192014"><td class="cellrowborder" valign="top" width="34.11%" headers="mcps1.1.3.1.1 "><p id="p18982140142017"><a name="p18982140142017"></a><a name="p18982140142017"></a>device-height</p>
</td>
<td class="cellrowborder" valign="top" width="65.89%" headers="mcps1.1.3.1.2 "><p id="p1198254032010"><a name="p1198254032010"></a><a name="p1198254032010"></a>设备的高度。</p>
</td>
</tr>
<tr id="row3944152920226"><td class="cellrowborder" valign="top" width="34.11%" headers="mcps1.1.3.1.1 "><p id="p494411291223"><a name="p494411291223"></a><a name="p494411291223"></a>min-device-height</p>
</td>
<td class="cellrowborder" valign="top" width="65.89%" headers="mcps1.1.3.1.2 "><p id="p9944112915227"><a name="p9944112915227"></a><a name="p9944112915227"></a>设备的最小高度。</p>
</td>
</tr>
<tr id="row10362830102215"><td class="cellrowborder" valign="top" width="34.11%" headers="mcps1.1.3.1.1 "><p id="p436319306222"><a name="p436319306222"></a><a name="p436319306222"></a>max-device-height</p>
</td>
<td class="cellrowborder" valign="top" width="65.89%" headers="mcps1.1.3.1.2 "><p id="p5363230142216"><a name="p5363230142216"></a><a name="p5363230142216"></a>设备的最大高度。</p>
</td>
</tr>
<tr id="row31411431152213"><td class="cellrowborder" valign="top" width="34.11%" headers="mcps1.1.3.1.1 "><p id="p714219311224"><a name="p714219311224"></a><a name="p714219311224"></a>device-width</p>
</td>
<td class="cellrowborder" valign="top" width="65.89%" headers="mcps1.1.3.1.2 "><p id="p114273117223"><a name="p114273117223"></a><a name="p114273117223"></a>设备的宽度。</p>
</td>
</tr>
<tr id="row8465184718239"><td class="cellrowborder" valign="top" width="34.11%" headers="mcps1.1.3.1.1 "><p id="p646515471232"><a name="p646515471232"></a><a name="p646515471232"></a>min-device-width</p>
</td>
<td class="cellrowborder" valign="top" width="65.89%" headers="mcps1.1.3.1.2 "><p id="p44654479235"><a name="p44654479235"></a><a name="p44654479235"></a>设备的最小宽度。</p>
</td>
</tr>
<tr id="row98591247182319"><td class="cellrowborder" valign="top" width="34.11%" headers="mcps1.1.3.1.1 "><p id="p1685964722310"><a name="p1685964722310"></a><a name="p1685964722310"></a>max-device-width</p>
</td>
<td class="cellrowborder" valign="top" width="65.89%" headers="mcps1.1.3.1.2 "><p id="p1085954720232"><a name="p1085954720232"></a><a name="p1085954720232"></a>设备的最大宽度。</p>
</td>
</tr>
<tr id="row12501138114319"><td class="cellrowborder" valign="top" width="34.11%" headers="mcps1.1.3.1.1 "><p id="p925213810436"><a name="p925213810436"></a><a name="p925213810436"></a>round-screen</p>
</td>
<td class="cellrowborder" valign="top" width="65.89%" headers="mcps1.1.3.1.2 "><p id="p2252173810430"><a name="p2252173810430"></a><a name="p2252173810430"></a>屏幕类型，圆形屏幕为true， 非圆形屏幕为 false。</p>
</td>
</tr>
<tr id="row5462165172517"><td class="cellrowborder" valign="top" width="34.11%" headers="mcps1.1.3.1.1 "><p id="a74279e95586943efad8e81aa02496d6d"><a name="a74279e95586943efad8e81aa02496d6d"></a><a name="a74279e95586943efad8e81aa02496d6d"></a>dark-mode<sup id="sup182210324279"><a name="sup182210324279"></a><a name="sup182210324279"></a><span>6+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="65.89%" headers="mcps1.1.3.1.2 "><p id="p88509314207"><a name="p88509314207"></a><a name="p88509314207"></a>系统为深色模式时为true，否则为false。</p>
</td>
</tr>
</tbody>
</table>

## 示例代码<a name="section1018513818615"></a>

-   通用媒体特征示例代码：

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

