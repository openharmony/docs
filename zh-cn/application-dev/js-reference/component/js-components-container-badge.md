# badge<a name="ZH-CN_TOPIC_0000001164290706"></a>

应用中如果有需用户关注的新事件提醒，可以采用新事件标记来标识。

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从API Version 5 开始支持。

## 权限列表<a name="zh-cn_topic_0000001173324629_section11257113618419"></a>

无

## 子组件<a name="zh-cn_topic_0000001173324629_section9288143101012"></a>

支持单个子组件。

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>仅支持单子组件节点，如果使用多子组件节点，默认使用第一个子组件节点。

## 属性<a name="zh-cn_topic_0000001173324629_section1355418214459"></a>

除支持[通用属性](js-components-common-attributes.md)外，还支持如下属性：

<a name="zh-cn_topic_0000001173324629_table3871294431"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001173324629_row12871029184318"><th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001173324629_p087529184319"><a name="zh-cn_topic_0000001173324629_p087529184319"></a><a name="zh-cn_topic_0000001173324629_p087529184319"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="12.61%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001173324629_p2087629204319"><a name="zh-cn_topic_0000001173324629_p2087629204319"></a><a name="zh-cn_topic_0000001173324629_p2087629204319"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="14.21%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001173324629_p1287112911432"><a name="zh-cn_topic_0000001173324629_p1287112911432"></a><a name="zh-cn_topic_0000001173324629_p1287112911432"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001173324629_p1687929124312"><a name="zh-cn_topic_0000001173324629_p1687929124312"></a><a name="zh-cn_topic_0000001173324629_p1687929124312"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="42.54%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001173324629_p138732916431"><a name="zh-cn_topic_0000001173324629_p138732916431"></a><a name="zh-cn_topic_0000001173324629_p138732916431"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001173324629_row887192994311"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324629_p2087102919434"><a name="zh-cn_topic_0000001173324629_p2087102919434"></a><a name="zh-cn_topic_0000001173324629_p2087102919434"></a>placement</p>
</td>
<td class="cellrowborder" valign="top" width="12.61%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324629_p188822916435"><a name="zh-cn_topic_0000001173324629_p188822916435"></a><a name="zh-cn_topic_0000001173324629_p188822916435"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="14.21%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324629_p10889298434"><a name="zh-cn_topic_0000001173324629_p10889298434"></a><a name="zh-cn_topic_0000001173324629_p10889298434"></a>rightTop</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324629_p1881929194314"><a name="zh-cn_topic_0000001173324629_p1881929194314"></a><a name="zh-cn_topic_0000001173324629_p1881929194314"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="42.54%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324629_p1788142954315"><a name="zh-cn_topic_0000001173324629_p1788142954315"></a><a name="zh-cn_topic_0000001173324629_p1788142954315"></a>事件提醒的数字标记或者圆点标记的位置，可选值为：</p>
<a name="zh-cn_topic_0000001173324629_ul1388112944320"></a><a name="zh-cn_topic_0000001173324629_ul1388112944320"></a><ul id="zh-cn_topic_0000001173324629_ul1388112944320"><li>right：位于组件右边框。</li><li>rightTop：位于组件边框右上角。</li><li>left：位于组件左边框。</li></ul>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324629_row6887294431"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324629_p28822974315"><a name="zh-cn_topic_0000001173324629_p28822974315"></a><a name="zh-cn_topic_0000001173324629_p28822974315"></a>count</p>
</td>
<td class="cellrowborder" valign="top" width="12.61%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324629_p188129194313"><a name="zh-cn_topic_0000001173324629_p188129194313"></a><a name="zh-cn_topic_0000001173324629_p188129194313"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="14.21%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324629_p288102954310"><a name="zh-cn_topic_0000001173324629_p288102954310"></a><a name="zh-cn_topic_0000001173324629_p288102954310"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324629_p158852915433"><a name="zh-cn_topic_0000001173324629_p158852915433"></a><a name="zh-cn_topic_0000001173324629_p158852915433"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="42.54%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324629_p19881229144313"><a name="zh-cn_topic_0000001173324629_p19881229144313"></a><a name="zh-cn_topic_0000001173324629_p19881229144313"></a>设置提醒的消息数，默认为0。当设置相应的提醒消息数大于0时，消息提醒会变成数字标记类型，未设置消息数或者消息数不大于0时，消息提醒将采用圆点标记。</p>
<div class="note" id="zh-cn_topic_0000001173324629_note388629144318"><a name="zh-cn_topic_0000001173324629_note388629144318"></a><a name="zh-cn_topic_0000001173324629_note388629144318"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001173324629_p488929174319"><a name="zh-cn_topic_0000001173324629_p488929174319"></a><a name="zh-cn_topic_0000001173324629_p488929174319"></a>当数字设置为大于maxcount时，将使用maxcount显示。</p>
<p id="zh-cn_topic_0000001173324629_p16106238105113"><a name="zh-cn_topic_0000001173324629_p16106238105113"></a><a name="zh-cn_topic_0000001173324629_p16106238105113"></a>count属性最大支持整数值为2147483647。</p>
</div></div>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324629_row1088152994313"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324629_p1488329174315"><a name="zh-cn_topic_0000001173324629_p1488329174315"></a><a name="zh-cn_topic_0000001173324629_p1488329174315"></a>visible</p>
</td>
<td class="cellrowborder" valign="top" width="12.61%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324629_p1888102934319"><a name="zh-cn_topic_0000001173324629_p1888102934319"></a><a name="zh-cn_topic_0000001173324629_p1888102934319"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="14.21%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324629_p88820291436"><a name="zh-cn_topic_0000001173324629_p88820291436"></a><a name="zh-cn_topic_0000001173324629_p88820291436"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324629_p10881329184320"><a name="zh-cn_topic_0000001173324629_p10881329184320"></a><a name="zh-cn_topic_0000001173324629_p10881329184320"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="42.54%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324629_p988112917435"><a name="zh-cn_topic_0000001173324629_p988112917435"></a><a name="zh-cn_topic_0000001173324629_p988112917435"></a>是否显示消息提醒，当收到新信息提醒时可以设置该属性为true，显示相应的消息提醒，如果需要使用数字标记类型，同时需要设置相应的count属性。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324629_row138862934313"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324629_p98872919436"><a name="zh-cn_topic_0000001173324629_p98872919436"></a><a name="zh-cn_topic_0000001173324629_p98872919436"></a>maxcount</p>
</td>
<td class="cellrowborder" valign="top" width="12.61%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324629_p28822920432"><a name="zh-cn_topic_0000001173324629_p28822920432"></a><a name="zh-cn_topic_0000001173324629_p28822920432"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="14.21%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324629_p28842944318"><a name="zh-cn_topic_0000001173324629_p28842944318"></a><a name="zh-cn_topic_0000001173324629_p28842944318"></a>99</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324629_p158810298438"><a name="zh-cn_topic_0000001173324629_p158810298438"></a><a name="zh-cn_topic_0000001173324629_p158810298438"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="42.54%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324629_p3881229164317"><a name="zh-cn_topic_0000001173324629_p3881229164317"></a><a name="zh-cn_topic_0000001173324629_p3881229164317"></a>最大消息数限制，当收到新信息提醒大于该限制时，标识数字会进行省略，仅显示maxcount+。</p>
<div class="note" id="zh-cn_topic_0000001173324629_note046285914515"><a name="zh-cn_topic_0000001173324629_note046285914515"></a><a name="zh-cn_topic_0000001173324629_note046285914515"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001173324629_p114631559205118"><a name="zh-cn_topic_0000001173324629_p114631559205118"></a><a name="zh-cn_topic_0000001173324629_p114631559205118"></a>maxcount属性最大支持整数值为2147483647。</p>
</div></div>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324629_row18881929154314"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324629_p188122934312"><a name="zh-cn_topic_0000001173324629_p188122934312"></a><a name="zh-cn_topic_0000001173324629_p188122934312"></a>config</p>
</td>
<td class="cellrowborder" valign="top" width="12.61%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324629_p128910296432"><a name="zh-cn_topic_0000001173324629_p128910296432"></a><a name="zh-cn_topic_0000001173324629_p128910296432"></a><a href="#zh-cn_topic_0000001173324629_table525042221515">BadgeConfig</a></p>
</td>
<td class="cellrowborder" valign="top" width="14.21%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324629_p389529124317"><a name="zh-cn_topic_0000001173324629_p389529124317"></a><a name="zh-cn_topic_0000001173324629_p389529124317"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324629_p589142984319"><a name="zh-cn_topic_0000001173324629_p589142984319"></a><a name="zh-cn_topic_0000001173324629_p589142984319"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="42.54%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324629_p4890291437"><a name="zh-cn_topic_0000001173324629_p4890291437"></a><a name="zh-cn_topic_0000001173324629_p4890291437"></a>设置新事件标记相关配置属性。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324629_row08922919437"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324629_p12894299435"><a name="zh-cn_topic_0000001173324629_p12894299435"></a><a name="zh-cn_topic_0000001173324629_p12894299435"></a>label<sup id="zh-cn_topic_0000001173324629_sup14890292436"><a name="zh-cn_topic_0000001173324629_sup14890292436"></a><a name="zh-cn_topic_0000001173324629_sup14890292436"></a><span>6+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="12.61%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324629_p18896292438"><a name="zh-cn_topic_0000001173324629_p18896292438"></a><a name="zh-cn_topic_0000001173324629_p18896292438"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="14.21%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324629_p1889429194315"><a name="zh-cn_topic_0000001173324629_p1889429194315"></a><a name="zh-cn_topic_0000001173324629_p1889429194315"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324629_p6891729124318"><a name="zh-cn_topic_0000001173324629_p6891729124318"></a><a name="zh-cn_topic_0000001173324629_p6891729124318"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="42.54%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324629_p15894294432"><a name="zh-cn_topic_0000001173324629_p15894294432"></a><a name="zh-cn_topic_0000001173324629_p15894294432"></a>设置新事件提醒的文本值。</p>
<div class="note" id="zh-cn_topic_0000001173324629_note168915299438"><a name="zh-cn_topic_0000001173324629_note168915299438"></a><a name="zh-cn_topic_0000001173324629_note168915299438"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001173324629_p118982994316"><a name="zh-cn_topic_0000001173324629_p118982994316"></a><a name="zh-cn_topic_0000001173324629_p118982994316"></a>使用该属性时，count和maxcount属性不生效。</p>
</div></div>
</td>
</tr>
</tbody>
</table>

**表 1**  BadgeConfig

<a name="zh-cn_topic_0000001173324629_table525042221515"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001173324629_row10250162216151"><th class="cellrowborder" valign="top" width="15.370000000000001%" id="mcps1.2.6.1.1"><p id="zh-cn_topic_0000001173324629_p256733317156"><a name="zh-cn_topic_0000001173324629_p256733317156"></a><a name="zh-cn_topic_0000001173324629_p256733317156"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="13.62%" id="mcps1.2.6.1.2"><p id="zh-cn_topic_0000001173324629_p13567143391514"><a name="zh-cn_topic_0000001173324629_p13567143391514"></a><a name="zh-cn_topic_0000001173324629_p13567143391514"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="12.46%" id="mcps1.2.6.1.3"><p id="zh-cn_topic_0000001173324629_p165679339152"><a name="zh-cn_topic_0000001173324629_p165679339152"></a><a name="zh-cn_topic_0000001173324629_p165679339152"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.22%" id="mcps1.2.6.1.4"><p id="zh-cn_topic_0000001173324629_p1018465012153"><a name="zh-cn_topic_0000001173324629_p1018465012153"></a><a name="zh-cn_topic_0000001173324629_p1018465012153"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="51.33%" id="mcps1.2.6.1.5"><p id="zh-cn_topic_0000001173324629_p1250142241516"><a name="zh-cn_topic_0000001173324629_p1250142241516"></a><a name="zh-cn_topic_0000001173324629_p1250142241516"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001173324629_row1425022251510"><td class="cellrowborder" valign="top" width="15.370000000000001%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001173324629_p6944185918156"><a name="zh-cn_topic_0000001173324629_p6944185918156"></a><a name="zh-cn_topic_0000001173324629_p6944185918156"></a>badgeColor</p>
</td>
<td class="cellrowborder" valign="top" width="13.62%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001173324629_p3944185918156"><a name="zh-cn_topic_0000001173324629_p3944185918156"></a><a name="zh-cn_topic_0000001173324629_p3944185918156"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="12.46%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001173324629_p494412594152"><a name="zh-cn_topic_0000001173324629_p494412594152"></a><a name="zh-cn_topic_0000001173324629_p494412594152"></a>#fa2a2d</p>
</td>
<td class="cellrowborder" valign="top" width="7.22%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001173324629_p2018411507152"><a name="zh-cn_topic_0000001173324629_p2018411507152"></a><a name="zh-cn_topic_0000001173324629_p2018411507152"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="51.33%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001173324629_p12623249168"><a name="zh-cn_topic_0000001173324629_p12623249168"></a><a name="zh-cn_topic_0000001173324629_p12623249168"></a>新事件标记背景色。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324629_row1325114221159"><td class="cellrowborder" valign="top" width="15.370000000000001%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001173324629_p189441459101515"><a name="zh-cn_topic_0000001173324629_p189441459101515"></a><a name="zh-cn_topic_0000001173324629_p189441459101515"></a>textColor</p>
</td>
<td class="cellrowborder" valign="top" width="13.62%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001173324629_p18944175915154"><a name="zh-cn_topic_0000001173324629_p18944175915154"></a><a name="zh-cn_topic_0000001173324629_p18944175915154"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="12.46%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001173324629_p29441859141514"><a name="zh-cn_topic_0000001173324629_p29441859141514"></a><a name="zh-cn_topic_0000001173324629_p29441859141514"></a>#ffffff</p>
</td>
<td class="cellrowborder" valign="top" width="7.22%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001173324629_p31843506151"><a name="zh-cn_topic_0000001173324629_p31843506151"></a><a name="zh-cn_topic_0000001173324629_p31843506151"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="51.33%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001173324629_p196231461610"><a name="zh-cn_topic_0000001173324629_p196231461610"></a><a name="zh-cn_topic_0000001173324629_p196231461610"></a>数字标记的数字文本颜色。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324629_row132511522131513"><td class="cellrowborder" valign="top" width="15.370000000000001%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001173324629_p7945175918154"><a name="zh-cn_topic_0000001173324629_p7945175918154"></a><a name="zh-cn_topic_0000001173324629_p7945175918154"></a>textSize</p>
</td>
<td class="cellrowborder" valign="top" width="13.62%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001173324629_p1594515919158"><a name="zh-cn_topic_0000001173324629_p1594515919158"></a><a name="zh-cn_topic_0000001173324629_p1594515919158"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="12.46%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001173324629_p189451259121511"><a name="zh-cn_topic_0000001173324629_p189451259121511"></a><a name="zh-cn_topic_0000001173324629_p189451259121511"></a>10px</p>
</td>
<td class="cellrowborder" valign="top" width="7.22%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001173324629_p14184125016151"><a name="zh-cn_topic_0000001173324629_p14184125016151"></a><a name="zh-cn_topic_0000001173324629_p14184125016151"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="51.33%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001173324629_p1962474101618"><a name="zh-cn_topic_0000001173324629_p1962474101618"></a><a name="zh-cn_topic_0000001173324629_p1962474101618"></a>数字标记的数字文本大小。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324629_row225122212159"><td class="cellrowborder" valign="top" width="15.370000000000001%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001173324629_p1394585918156"><a name="zh-cn_topic_0000001173324629_p1394585918156"></a><a name="zh-cn_topic_0000001173324629_p1394585918156"></a>badgeSize</p>
</td>
<td class="cellrowborder" valign="top" width="13.62%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001173324629_p159451459111519"><a name="zh-cn_topic_0000001173324629_p159451459111519"></a><a name="zh-cn_topic_0000001173324629_p159451459111519"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="12.46%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001173324629_p694545961517"><a name="zh-cn_topic_0000001173324629_p694545961517"></a><a name="zh-cn_topic_0000001173324629_p694545961517"></a>6px</p>
</td>
<td class="cellrowborder" valign="top" width="7.22%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001173324629_p10184135015153"><a name="zh-cn_topic_0000001173324629_p10184135015153"></a><a name="zh-cn_topic_0000001173324629_p10184135015153"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="51.33%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001173324629_p1962410411162"><a name="zh-cn_topic_0000001173324629_p1962410411162"></a><a name="zh-cn_topic_0000001173324629_p1962410411162"></a>圆点标记的默认大小</p>
</td>
</tr>
</tbody>
</table>

## 样式<a name="zh-cn_topic_0000001173324629_section5775351116"></a>

支持[通用样式](js-components-common-styles.md)。

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>badge组件的子组件大小不能超过badge组件本身的大小，否则子组件不会绘制。

## 事件<a name="zh-cn_topic_0000001173324629_section43461940193518"></a>

支持[通用事件](js-components-common-events.md)。

## 方法<a name="zh-cn_topic_0000001173324629_section2279124532420"></a>

支持[通用方法](js-components-common-methods.md)。

## 示例<a name="zh-cn_topic_0000001173324629_section3510104413431"></a>

```
<!-- xxx.hml -->
<div class="container">
  <badge class="badge" config="{{badgeconfig}}" visible="true" count="100" maxcount="99">
    <text class="text1">example</text>
  </badge>
  <badge class="badge" visible="true" count="0">
    <text class="text2">example</text>
  </badge>
</div>
```

```
/* xxx.css */
.container {
  flex-direction: column;
  width: 100%;
  align-items: center;
}
.badge {
  width: 50%;
  margin-top: 100px;
}
.text1 {
  background-color: #f9a01e;
  font-size: 50px;
}
.text2 {
  background-color: #46b1e3;
  font-size: 50px;
}
```

```
// xxx.js
export default {
  data:{
    badgeconfig:{
      badgeColor:"#0a59f7",
      textColor:"#ffffff",
    }
  }
}
```

![](figures/捕获.png)

