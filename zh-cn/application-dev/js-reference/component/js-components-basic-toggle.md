# toggle<a name="ZH-CN_TOPIC_0000001164130770"></a>

-   [权限列表](#zh-cn_topic_0000001127125082_section11257113618419)
-   [子组件](#zh-cn_topic_0000001127125082_section9288143101012)
-   [属性](#zh-cn_topic_0000001127125082_section2598341175212)
-   [样式](#zh-cn_topic_0000001127125082_section3655917541)
-   [事件](#zh-cn_topic_0000001127125082_section3892191911214)
-   [方法](#zh-cn_topic_0000001127125082_section2279124532420)
-   [示例](#zh-cn_topic_0000001127125082_section520313404174)

状态按钮用于从一组选项中进行选择，并可能在界面上实时显示选择后的结果。通常这一组选项都是由状态按钮构成。

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从 API Version 5 开始支持。

## 权限列表<a name="zh-cn_topic_0000001127125082_section11257113618419"></a>

无

## 子组件<a name="zh-cn_topic_0000001127125082_section9288143101012"></a>

不支持。

## 属性<a name="zh-cn_topic_0000001127125082_section2598341175212"></a>

除支持[通用属性](js-components-common-attributes.md#ZH-CN_TOPIC_0000001163812208)外，还支持如下属性：

<a name="zh-cn_topic_0000001127125082_table20633101642315"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001127125082_row663331618238"><th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001127125082_a45273e2103004ff3bdd3375013e96a2a"><a name="zh-cn_topic_0000001127125082_a45273e2103004ff3bdd3375013e96a2a"></a><a name="zh-cn_topic_0000001127125082_a45273e2103004ff3bdd3375013e96a2a"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001127125082_ad5b10d4a60e44bb4a8bbb3b4416d7b27"><a name="zh-cn_topic_0000001127125082_ad5b10d4a60e44bb4a8bbb3b4416d7b27"></a><a name="zh-cn_topic_0000001127125082_ad5b10d4a60e44bb4a8bbb3b4416d7b27"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="10.48%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001127125082_ab2ae3d9f60d6475ab95ba095851a9d07"><a name="zh-cn_topic_0000001127125082_ab2ae3d9f60d6475ab95ba095851a9d07"></a><a name="zh-cn_topic_0000001127125082_ab2ae3d9f60d6475ab95ba095851a9d07"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001127125082_p2063810588455"><a name="zh-cn_topic_0000001127125082_p2063810588455"></a><a name="zh-cn_topic_0000001127125082_p2063810588455"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="35.76%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001127125082_af5c3b773ed0a42e589819a6c8d257ca1"><a name="zh-cn_topic_0000001127125082_af5c3b773ed0a42e589819a6c8d257ca1"></a><a name="zh-cn_topic_0000001127125082_af5c3b773ed0a42e589819a6c8d257ca1"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001127125082_row128581827123812"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125082_p158151581017"><a name="zh-cn_topic_0000001127125082_p158151581017"></a><a name="zh-cn_topic_0000001127125082_p158151581017"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125082_p98151887118"><a name="zh-cn_topic_0000001127125082_p98151887118"></a><a name="zh-cn_topic_0000001127125082_p98151887118"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125082_p78158817112"><a name="zh-cn_topic_0000001127125082_p78158817112"></a><a name="zh-cn_topic_0000001127125082_p78158817112"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125082_p8638135854515"><a name="zh-cn_topic_0000001127125082_p8638135854515"></a><a name="zh-cn_topic_0000001127125082_p8638135854515"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125082_p1981514819118"><a name="zh-cn_topic_0000001127125082_p1981514819118"></a><a name="zh-cn_topic_0000001127125082_p1981514819118"></a>状态按钮的文本值。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125082_row1314733811"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125082_p14144703815"><a name="zh-cn_topic_0000001127125082_p14144703815"></a><a name="zh-cn_topic_0000001127125082_p14144703815"></a>checked</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125082_p174104714389"><a name="zh-cn_topic_0000001127125082_p174104714389"></a><a name="zh-cn_topic_0000001127125082_p174104714389"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125082_p174134719389"><a name="zh-cn_topic_0000001127125082_p174134719389"></a><a name="zh-cn_topic_0000001127125082_p174134719389"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125082_p86381558144516"><a name="zh-cn_topic_0000001127125082_p86381558144516"></a><a name="zh-cn_topic_0000001127125082_p86381558144516"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125082_p184114763819"><a name="zh-cn_topic_0000001127125082_p184114763819"></a><a name="zh-cn_topic_0000001127125082_p184114763819"></a>状态按钮是否被选中。</p>
</td>
</tr>
</tbody>
</table>

## 样式<a name="zh-cn_topic_0000001127125082_section3655917541"></a>

除支持[通用样式](js-components-common-styles.md#ZH-CN_TOPIC_0000001163932190)外，还支持如下样式：

<a name="zh-cn_topic_0000001127125082_table83631117191317"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001127125082_row336351719135"><th class="cellrowborder" valign="top" width="17.928207179282072%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001127125082_p736319179132"><a name="zh-cn_topic_0000001127125082_p736319179132"></a><a name="zh-cn_topic_0000001127125082_p736319179132"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="14.088591140885912%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001127125082_p736311741311"><a name="zh-cn_topic_0000001127125082_p736311741311"></a><a name="zh-cn_topic_0000001127125082_p736311741311"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="21.41785821417858%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001127125082_p836331716138"><a name="zh-cn_topic_0000001127125082_p836331716138"></a><a name="zh-cn_topic_0000001127125082_p836331716138"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="6.979302069793021%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001127125082_p836314176137"><a name="zh-cn_topic_0000001127125082_p836314176137"></a><a name="zh-cn_topic_0000001127125082_p836314176137"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="39.58604139586041%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001127125082_p10363151721312"><a name="zh-cn_topic_0000001127125082_p10363151721312"></a><a name="zh-cn_topic_0000001127125082_p10363151721312"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001127125082_row203632017171314"><td class="cellrowborder" valign="top" width="17.928207179282072%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125082_p8363111761310"><a name="zh-cn_topic_0000001127125082_p8363111761310"></a><a name="zh-cn_topic_0000001127125082_p8363111761310"></a>color</p>
</td>
<td class="cellrowborder" valign="top" width="14.088591140885912%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125082_p18363101741314"><a name="zh-cn_topic_0000001127125082_p18363101741314"></a><a name="zh-cn_topic_0000001127125082_p18363101741314"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="21.41785821417858%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125082_p17456195124520"><a name="zh-cn_topic_0000001127125082_p17456195124520"></a><a name="zh-cn_topic_0000001127125082_p17456195124520"></a>#E5000000</p>
</td>
<td class="cellrowborder" valign="top" width="6.979302069793021%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125082_p18363317181316"><a name="zh-cn_topic_0000001127125082_p18363317181316"></a><a name="zh-cn_topic_0000001127125082_p18363317181316"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="39.58604139586041%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125082_p2363151712139"><a name="zh-cn_topic_0000001127125082_p2363151712139"></a><a name="zh-cn_topic_0000001127125082_p2363151712139"></a>状态按钮的文本颜色。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125082_row15363111781318"><td class="cellrowborder" valign="top" width="17.928207179282072%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125082_p18363111712132"><a name="zh-cn_topic_0000001127125082_p18363111712132"></a><a name="zh-cn_topic_0000001127125082_p18363111712132"></a>font-size</p>
</td>
<td class="cellrowborder" valign="top" width="14.088591140885912%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125082_p12364101716134"><a name="zh-cn_topic_0000001127125082_p12364101716134"></a><a name="zh-cn_topic_0000001127125082_p12364101716134"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="21.41785821417858%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125082_p0364117101318"><a name="zh-cn_topic_0000001127125082_p0364117101318"></a><a name="zh-cn_topic_0000001127125082_p0364117101318"></a>16px</p>
</td>
<td class="cellrowborder" valign="top" width="6.979302069793021%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125082_p6364161719139"><a name="zh-cn_topic_0000001127125082_p6364161719139"></a><a name="zh-cn_topic_0000001127125082_p6364161719139"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="39.58604139586041%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125082_p2364201716136"><a name="zh-cn_topic_0000001127125082_p2364201716136"></a><a name="zh-cn_topic_0000001127125082_p2364201716136"></a>状态按钮的文本尺寸。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125082_row1836411177134"><td class="cellrowborder" valign="top" width="17.928207179282072%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125082_p11364161781315"><a name="zh-cn_topic_0000001127125082_p11364161781315"></a><a name="zh-cn_topic_0000001127125082_p11364161781315"></a>allow-scale</p>
</td>
<td class="cellrowborder" valign="top" width="14.088591140885912%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125082_p133641917161317"><a name="zh-cn_topic_0000001127125082_p133641917161317"></a><a name="zh-cn_topic_0000001127125082_p133641917161317"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="21.41785821417858%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125082_p1336415173138"><a name="zh-cn_topic_0000001127125082_p1336415173138"></a><a name="zh-cn_topic_0000001127125082_p1336415173138"></a>true</p>
</td>
<td class="cellrowborder" valign="top" width="6.979302069793021%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125082_p536415173134"><a name="zh-cn_topic_0000001127125082_p536415173134"></a><a name="zh-cn_topic_0000001127125082_p536415173134"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="39.58604139586041%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125082_p536491719137"><a name="zh-cn_topic_0000001127125082_p536491719137"></a><a name="zh-cn_topic_0000001127125082_p536491719137"></a>状态按钮的文本尺寸是否跟随系统设置字体缩放尺寸进行放大缩小。</p>
<div class="note" id="zh-cn_topic_0000001127125082_note236431714138"><a name="zh-cn_topic_0000001127125082_note236431714138"></a><a name="zh-cn_topic_0000001127125082_note236431714138"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001127125082_p6364161721312"><a name="zh-cn_topic_0000001127125082_p6364161721312"></a><a name="zh-cn_topic_0000001127125082_p6364161721312"></a>如果在config描述文件中针对ability配置了fontSize的config-changes标签，则应用不会重启而直接生效。</p>
</div></div>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125082_row736421781317"><td class="cellrowborder" valign="top" width="17.928207179282072%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125082_p6364717181310"><a name="zh-cn_topic_0000001127125082_p6364717181310"></a><a name="zh-cn_topic_0000001127125082_p6364717181310"></a>font-style</p>
</td>
<td class="cellrowborder" valign="top" width="14.088591140885912%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125082_p18364121761313"><a name="zh-cn_topic_0000001127125082_p18364121761313"></a><a name="zh-cn_topic_0000001127125082_p18364121761313"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="21.41785821417858%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125082_p236413174139"><a name="zh-cn_topic_0000001127125082_p236413174139"></a><a name="zh-cn_topic_0000001127125082_p236413174139"></a>normal</p>
</td>
<td class="cellrowborder" valign="top" width="6.979302069793021%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125082_p153646178137"><a name="zh-cn_topic_0000001127125082_p153646178137"></a><a name="zh-cn_topic_0000001127125082_p153646178137"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="39.58604139586041%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125082_p7364131711318"><a name="zh-cn_topic_0000001127125082_p7364131711318"></a><a name="zh-cn_topic_0000001127125082_p7364131711318"></a>状态按钮的字体样式。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125082_row636418171130"><td class="cellrowborder" valign="top" width="17.928207179282072%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125082_p7364817161320"><a name="zh-cn_topic_0000001127125082_p7364817161320"></a><a name="zh-cn_topic_0000001127125082_p7364817161320"></a>font-weight</p>
</td>
<td class="cellrowborder" valign="top" width="14.088591140885912%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125082_p103641917161316"><a name="zh-cn_topic_0000001127125082_p103641917161316"></a><a name="zh-cn_topic_0000001127125082_p103641917161316"></a>number | string</p>
</td>
<td class="cellrowborder" valign="top" width="21.41785821417858%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125082_p1436451761313"><a name="zh-cn_topic_0000001127125082_p1436451761313"></a><a name="zh-cn_topic_0000001127125082_p1436451761313"></a>normal</p>
</td>
<td class="cellrowborder" valign="top" width="6.979302069793021%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125082_p143641717171314"><a name="zh-cn_topic_0000001127125082_p143641717171314"></a><a name="zh-cn_topic_0000001127125082_p143641717171314"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="39.58604139586041%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125082_p1736431716139"><a name="zh-cn_topic_0000001127125082_p1736431716139"></a><a name="zh-cn_topic_0000001127125082_p1736431716139"></a>状态按钮的字体粗细。见<a href="js-components-basic-text.md#zh-cn_topic_0000001127125018_section5775351116">text组件font-weight的样式属性</a>。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125082_row53641817161320"><td class="cellrowborder" valign="top" width="17.928207179282072%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125082_p19364171718135"><a name="zh-cn_topic_0000001127125082_p19364171718135"></a><a name="zh-cn_topic_0000001127125082_p19364171718135"></a>font-family</p>
</td>
<td class="cellrowborder" valign="top" width="14.088591140885912%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125082_p336415178135"><a name="zh-cn_topic_0000001127125082_p336415178135"></a><a name="zh-cn_topic_0000001127125082_p336415178135"></a>&lt;string&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="21.41785821417858%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125082_p10365131761314"><a name="zh-cn_topic_0000001127125082_p10365131761314"></a><a name="zh-cn_topic_0000001127125082_p10365131761314"></a>sans-serif</p>
</td>
<td class="cellrowborder" valign="top" width="6.979302069793021%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125082_p2036581716132"><a name="zh-cn_topic_0000001127125082_p2036581716132"></a><a name="zh-cn_topic_0000001127125082_p2036581716132"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="39.58604139586041%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125082_p133656177131"><a name="zh-cn_topic_0000001127125082_p133656177131"></a><a name="zh-cn_topic_0000001127125082_p133656177131"></a>状态按钮的字体列表，用逗号分隔，每个字体用字体名或者字体族名设置。列表中第一个系统中存在的或者通过<a href="js-components-common-customizing-font.md#ZH-CN_TOPIC_0000001163812210">自定义字体</a>指定的字体，会被选中作为文本的字体。</p>
</td>
</tr>
</tbody>
</table>

## 事件<a name="zh-cn_topic_0000001127125082_section3892191911214"></a>

除支持[通用事件](js-components-common-events.md#ZH-CN_TOPIC_0000001209412119)外，还支持如下事件：

<a name="zh-cn_topic_0000001127125082_table101871711203115"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001127125082_row1718751111316"><th class="cellrowborder" valign="top" width="24.852485248524854%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001127125082_a426b8903842d48fa8012a24ff3c997eb"><a name="zh-cn_topic_0000001127125082_a426b8903842d48fa8012a24ff3c997eb"></a><a name="zh-cn_topic_0000001127125082_a426b8903842d48fa8012a24ff3c997eb"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="29.552955295529554%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001127125082_a53448ba47e5e4ae9bf7774c90820e970"><a name="zh-cn_topic_0000001127125082_a53448ba47e5e4ae9bf7774c90820e970"></a><a name="zh-cn_topic_0000001127125082_a53448ba47e5e4ae9bf7774c90820e970"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="45.5945594559456%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001127125082_add489ff50c444f24b759162c7f4bad9a"><a name="zh-cn_topic_0000001127125082_add489ff50c444f24b759162c7f4bad9a"></a><a name="zh-cn_topic_0000001127125082_add489ff50c444f24b759162c7f4bad9a"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001127125082_row105681412318"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001127125082_p18889152411316"><a name="zh-cn_topic_0000001127125082_p18889152411316"></a><a name="zh-cn_topic_0000001127125082_p18889152411316"></a>change</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001127125082_p138891924103112"><a name="zh-cn_topic_0000001127125082_p138891924103112"></a><a name="zh-cn_topic_0000001127125082_p138891924103112"></a>{ checked：isChecked }</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001127125082_p1889002418312"><a name="zh-cn_topic_0000001127125082_p1889002418312"></a><a name="zh-cn_topic_0000001127125082_p1889002418312"></a>组件选中状态发生变化时触发。</p>
</td>
</tr>
</tbody>
</table>

## 方法<a name="zh-cn_topic_0000001127125082_section2279124532420"></a>

支持[通用方法](js-components-common-methods.md#ZH-CN_TOPIC_0000001209252157)。

## 示例<a name="zh-cn_topic_0000001127125082_section520313404174"></a>

```
<!-- xxx.hml -->
<div style="flex-direction: column;">
  <text class="margin">1. Multiple choice example</text>
  <div style="flex-wrap: wrap">
    <toggle class="margin" for="{{toggles}}">{{$item}}</toggle>
  </div>
  <text class="margin">2. Single choice example</text>
  <div style="flex-wrap: wrap">
    <toggle class="margin" for="{{toggle_list}}" id="{{$item.id}}" checked="{{$item.checked}}" 
      value="{{$item.name}}" @change="allchange" @click="allclick({{$item.id}})"></toggle>
  </div>
</div>
```

```
/* xxx.css */
.margin {
  margin: 7px;
}
```

```
// xxx.js
export default {
  data: {
    toggle_list: [
      { "id":"1001", "name":"Living room", "checked":true },
      { "id":"1002", "name":"Bedroom", "checked":false },
      { "id":"1003", "name":"Second bedroom", "checked":false },
      { "id":"1004", "name":"Kitchen", "checked":false },
      { "id":"1005", "name":"Study", "checked":false },
      { "id":"1006", "name":"Garden", "checked":false },
      { "id":"1007", "name":"Bathroom", "checked":false },
      { "id":"1008", "name":"Balcony", "checked":false },
    ],
    toggles: ["Living room","Bedroom","Kitchen","Study"],
    idx: ""
  },
  allclick(arg) {
    this.idx = arg
  },
  allchange(e) {
    if (e.checked === true) {
      for (var i = 0; i < this.toggle_list.length; i++) {
        if (this.toggle_list[i].id === this.idx) {
          this.toggle_list[i].checked = true
        } else {
          this.toggle_list[i].checked = false
        }
      }
    }
  }
}
```

![](figures/screenshot.png)

