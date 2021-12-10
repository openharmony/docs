# picker-view<a name="ZH-CN_TOPIC_0000001127125108"></a>

嵌入页面的滑动选择器。

## 子组件<a name="section54292411343"></a>

不支持。

## 属性<a name="section121957126347"></a>

除支持[通用属性](js-components-common-attributes.md)外，还支持如下属性：

<a name="table20633101642315"></a>
<table><thead align="left"><tr id="row663331618238"><th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.1"><p id="aa872998ac2d84843a3c5161889afffef"><a name="aa872998ac2d84843a3c5161889afffef"></a><a name="aa872998ac2d84843a3c5161889afffef"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.2"><p id="ab2111648ee0e4f6d881be8954e7acaab"><a name="ab2111648ee0e4f6d881be8954e7acaab"></a><a name="ab2111648ee0e4f6d881be8954e7acaab"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="10.48%" id="mcps1.1.6.1.3"><p id="ab377d1c90900478ea4ecab51e9a058af"><a name="ab377d1c90900478ea4ecab51e9a058af"></a><a name="ab377d1c90900478ea4ecab51e9a058af"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.6.1.4"><p id="p824610360217"><a name="p824610360217"></a><a name="p824610360217"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="35.76%" id="mcps1.1.6.1.5"><p id="a1d574a0044ed42ec8a2603bc82734232"><a name="a1d574a0044ed42ec8a2603bc82734232"></a><a name="a1d574a0044ed42ec8a2603bc82734232"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row6290565914"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p136971571796"><a name="p136971571796"></a><a name="p136971571796"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p36971373918"><a name="p36971373918"></a><a name="p36971373918"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p3697774912"><a name="p3697774912"></a><a name="p3697774912"></a>text</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p12697377919"><a name="p12697377919"></a><a name="p12697377919"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p126974719915"><a name="p126974719915"></a><a name="p126974719915"></a>设置滑动选择器的类型，该属性不支持动态修改，可选项有：</p>
<a name="ul16977711916"></a><a name="ul16977711916"></a><ul id="ul16977711916"><li>text：文本选择器。</li><li>time：时间选择器。</li><li>date：日期选择器。</li><li>datetime：日期时间选择器。</li><li>multi-text：多列文本选择器。</li></ul>
</td>
</tr>
</tbody>
</table>

文本选择器：type=text

<a name="ta708bd4856a044b79bae50a2ce6981b8"></a>
<table><thead align="left"><tr id="re08662644cee4140ad0d5bac7978cd9b"><th class="cellrowborder" valign="top" width="24.007599240075994%" id="mcps1.1.6.1.1"><p id="af5b093e471ec47119f04bf2fe91b6f64"><a name="af5b093e471ec47119f04bf2fe91b6f64"></a><a name="af5b093e471ec47119f04bf2fe91b6f64"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="10.808919108089192%" id="mcps1.1.6.1.2"><p id="a8c2c2f6a645749b7852ec7dcadaca702"><a name="a8c2c2f6a645749b7852ec7dcadaca702"></a><a name="a8c2c2f6a645749b7852ec7dcadaca702"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="8.62913708629137%" id="mcps1.1.6.1.3"><p id="aa63c3dd750aa44fb9ec9031e632f4f5f"><a name="aa63c3dd750aa44fb9ec9031e632f4f5f"></a><a name="aa63c3dd750aa44fb9ec9031e632f4f5f"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.14928507149285%" id="mcps1.1.6.1.4"><p id="aee9661e3366543aeac6aa37e48de4c87"><a name="aee9661e3366543aeac6aa37e48de4c87"></a><a name="aee9661e3366543aeac6aa37e48de4c87"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="49.4050594940506%" id="mcps1.1.6.1.5"><p id="a2dc04c78fce4402d9dead84ab8412bb3"><a name="a2dc04c78fce4402d9dead84ab8412bb3"></a><a name="a2dc04c78fce4402d9dead84ab8412bb3"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="re8122915226c4596b2bffeae21e37b10"><td class="cellrowborder" valign="top" width="24.007599240075994%" headers="mcps1.1.6.1.1 "><p id="p64901432865"><a name="p64901432865"></a><a name="p64901432865"></a>range</p>
</td>
<td class="cellrowborder" valign="top" width="10.808919108089192%" headers="mcps1.1.6.1.2 "><p id="p194901326610"><a name="p194901326610"></a><a name="p194901326610"></a>Array</p>
</td>
<td class="cellrowborder" valign="top" width="8.62913708629137%" headers="mcps1.1.6.1.3 "><p id="p16490183216616"><a name="p16490183216616"></a><a name="p16490183216616"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.14928507149285%" headers="mcps1.1.6.1.4 "><p id="p12490132765"><a name="p12490132765"></a><a name="p12490132765"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.4050594940506%" headers="mcps1.1.6.1.5 "><p id="p879110395507"><a name="p879110395507"></a><a name="p879110395507"></a>设置文本选择器的取值范围。</p>
<div class="note" id="note195791919121"><a name="note195791919121"></a><a name="note195791919121"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="p11957191913124"><a name="p11957191913124"></a><a name="p11957191913124"></a>使用时需要使用数据绑定的方式，如range = {{data}}，js中声明相应变量：data：["15", "20", "25"]。</p>
</div></div>
</td>
</tr>
<tr id="row2068183074711"><td class="cellrowborder" valign="top" width="24.007599240075994%" headers="mcps1.1.6.1.1 "><p id="p54902321765"><a name="p54902321765"></a><a name="p54902321765"></a>selected</p>
</td>
<td class="cellrowborder" valign="top" width="10.808919108089192%" headers="mcps1.1.6.1.2 "><p id="p24901321469"><a name="p24901321469"></a><a name="p24901321469"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.62913708629137%" headers="mcps1.1.6.1.3 "><p id="p14901932863"><a name="p14901932863"></a><a name="p14901932863"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.14928507149285%" headers="mcps1.1.6.1.4 "><p id="p1049018321869"><a name="p1049018321869"></a><a name="p1049018321869"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.4050594940506%" headers="mcps1.1.6.1.5 "><p id="p649017329613"><a name="p649017329613"></a><a name="p649017329613"></a>设置文本选择器的默认选择值，该值需要为range的索引。</p>
</td>
</tr>
<tr id="row1045119531711"><td class="cellrowborder" valign="top" width="24.007599240075994%" headers="mcps1.1.6.1.1 "><p id="p54526530112"><a name="p54526530112"></a><a name="p54526530112"></a><span>indicator</span>prefix</p>
</td>
<td class="cellrowborder" valign="top" width="10.808919108089192%" headers="mcps1.1.6.1.2 "><p id="p24521553119"><a name="p24521553119"></a><a name="p24521553119"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.62913708629137%" headers="mcps1.1.6.1.3 "><p id="p14524531315"><a name="p14524531315"></a><a name="p14524531315"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.14928507149285%" headers="mcps1.1.6.1.4 "><p id="p134526535117"><a name="p134526535117"></a><a name="p134526535117"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.4050594940506%" headers="mcps1.1.6.1.5 "><p id="p114526534115"><a name="p114526534115"></a><a name="p114526534115"></a>文本选择器选定值增加的前缀字段。</p>
</td>
</tr>
<tr id="row115191458171210"><td class="cellrowborder" valign="top" width="24.007599240075994%" headers="mcps1.1.6.1.1 "><p id="p2052015584123"><a name="p2052015584123"></a><a name="p2052015584123"></a>indicatorsuffix</p>
</td>
<td class="cellrowborder" valign="top" width="10.808919108089192%" headers="mcps1.1.6.1.2 "><p id="p0520458141213"><a name="p0520458141213"></a><a name="p0520458141213"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.62913708629137%" headers="mcps1.1.6.1.3 "><p id="p25201358191214"><a name="p25201358191214"></a><a name="p25201358191214"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.14928507149285%" headers="mcps1.1.6.1.4 "><p id="p952085813124"><a name="p952085813124"></a><a name="p952085813124"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.4050594940506%" headers="mcps1.1.6.1.5 "><p id="p175201958121212"><a name="p175201958121212"></a><a name="p175201958121212"></a>文本选择器选定值增加的后缀字段。</p>
</td>
</tr>
</tbody>
</table>

时间选择器：type=time

<a name="table89366820719"></a>
<table><thead align="left"><tr id="row49367819714"><th class="cellrowborder" valign="top" width="24%" id="mcps1.1.6.1.1"><p id="p1493614815715"><a name="p1493614815715"></a><a name="p1493614815715"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="10.83%" id="mcps1.1.6.1.2"><p id="p2936881677"><a name="p2936881677"></a><a name="p2936881677"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="8.61%" id="mcps1.1.6.1.3"><p id="p79362815719"><a name="p79362815719"></a><a name="p79362815719"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.1499999999999995%" id="mcps1.1.6.1.4"><p id="p12936584719"><a name="p12936584719"></a><a name="p12936584719"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="49.41%" id="mcps1.1.6.1.5"><p id="p15936198876"><a name="p15936198876"></a><a name="p15936198876"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row2937108277"><td class="cellrowborder" valign="top" width="24%" headers="mcps1.1.6.1.1 "><p id="p077212191171"><a name="p077212191171"></a><a name="p077212191171"></a>containsecond</p>
</td>
<td class="cellrowborder" valign="top" width="10.83%" headers="mcps1.1.6.1.2 "><p id="p1177214198714"><a name="p1177214198714"></a><a name="p1177214198714"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="8.61%" headers="mcps1.1.6.1.3 "><p id="p87721619275"><a name="p87721619275"></a><a name="p87721619275"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.1499999999999995%" headers="mcps1.1.6.1.4 "><p id="p127721919372"><a name="p127721919372"></a><a name="p127721919372"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.41%" headers="mcps1.1.6.1.5 "><p id="p13773101919719"><a name="p13773101919719"></a><a name="p13773101919719"></a>时间选择器是否包含秒。</p>
</td>
</tr>
<tr id="row1293719814712"><td class="cellrowborder" valign="top" width="24%" headers="mcps1.1.6.1.1 "><p id="p577314191171"><a name="p577314191171"></a><a name="p577314191171"></a>selected</p>
</td>
<td class="cellrowborder" valign="top" width="10.83%" headers="mcps1.1.6.1.2 "><p id="p177735196711"><a name="p177735196711"></a><a name="p177735196711"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.61%" headers="mcps1.1.6.1.3 "><p id="p127734191714"><a name="p127734191714"></a><a name="p127734191714"></a><span id="ph61411732205214"><a name="ph61411732205214"></a><a name="ph61411732205214"></a>当前时间</span></p>
</td>
<td class="cellrowborder" valign="top" width="7.1499999999999995%" headers="mcps1.1.6.1.4 "><p id="p16773151914716"><a name="p16773151914716"></a><a name="p16773151914716"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.41%" headers="mcps1.1.6.1.5 "><p id="p5241145091814"><a name="p5241145091814"></a><a name="p5241145091814"></a>设置时间选择器的默认取值，格式为 HH:mm；</p>
<p id="p57739191974"><a name="p57739191974"></a><a name="p57739191974"></a>当包含秒时，格式为HH:mm:ss。</p>
</td>
</tr>
<tr id="row3976191332214"><td class="cellrowborder" valign="top" width="24%" headers="mcps1.1.6.1.1 "><p id="p095363112111"><a name="p095363112111"></a><a name="p095363112111"></a>hours</p>
</td>
<td class="cellrowborder" valign="top" width="10.83%" headers="mcps1.1.6.1.2 "><p id="p6953193114218"><a name="p6953193114218"></a><a name="p6953193114218"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.61%" headers="mcps1.1.6.1.3 "><p id="p16934121142417"><a name="p16934121142417"></a><a name="p16934121142417"></a>24<sup id="sup169341019245"><a name="sup169341019245"></a><a name="sup169341019245"></a>1-4</sup></p>
<p id="p81051142202817"><a name="p81051142202817"></a><a name="p81051142202817"></a>-<sup id="sup14229658122718"><a name="sup14229658122718"></a><a name="sup14229658122718"></a><span>5+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="7.1499999999999995%" headers="mcps1.1.6.1.4 "><p id="p0953193112117"><a name="p0953193112117"></a><a name="p0953193112117"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.41%" headers="mcps1.1.6.1.5 "><p id="p1095393116216"><a name="p1095393116216"></a><a name="p1095393116216"></a>设置时间选择器采用的时间格式，可选值：</p>
<a name="ul11382144442112"></a><a name="ul11382144442112"></a><ul id="ul11382144442112"><li>12：按照12小时制显示，用上午和下午进行区分；</li><li>24：按照24小时制显示。<div class="note" id="note189471313104"><a name="note189471313104"></a><a name="note189471313104"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="p9947193114104"><a name="p9947193114104"></a><a name="p9947193114104"></a>默认值会依据系统当前所选地区和语言选择当地习惯的小时制(12小时制或24小时制)。<sup id="sup319942110314"><a name="sup319942110314"></a><a name="sup319942110314"></a><span>5+</span></sup></p>
</div></div>
</li></ul>
</td>
</tr>
</tbody>
</table>

日期选择器：type=date

<a name="table174784493618"></a>
<table><thead align="left"><tr id="row54789491561"><th class="cellrowborder" valign="top" width="24.000000000000004%" id="mcps1.1.6.1.1"><p id="p14781849561"><a name="p14781849561"></a><a name="p14781849561"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="10.810000000000002%" id="mcps1.1.6.1.2"><p id="p447834912613"><a name="p447834912613"></a><a name="p447834912613"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="8.63%" id="mcps1.1.6.1.3"><p id="p12479749564"><a name="p12479749564"></a><a name="p12479749564"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.15%" id="mcps1.1.6.1.4"><p id="p13479749560"><a name="p13479749560"></a><a name="p13479749560"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="49.410000000000004%" id="mcps1.1.6.1.5"><p id="p247913495610"><a name="p247913495610"></a><a name="p247913495610"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1047910498616"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="p167682562062"><a name="p167682562062"></a><a name="p167682562062"></a>start</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="p67689566612"><a name="p67689566612"></a><a name="p67689566612"></a>&lt;time&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="p1576817561266"><a name="p1576817561266"></a><a name="p1576817561266"></a>1970-1-1</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="p476819561368"><a name="p476819561368"></a><a name="p476819561368"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="p87681568618"><a name="p87681568618"></a><a name="p87681568618"></a>设置日期选择器的起始时间，格式为 YYYY-MM-DD。</p>
</td>
</tr>
<tr id="row3479549162"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="p117686568615"><a name="p117686568615"></a><a name="p117686568615"></a>end</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="p19768115614615"><a name="p19768115614615"></a><a name="p19768115614615"></a>&lt;time&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="p27686569618"><a name="p27686569618"></a><a name="p27686569618"></a>2100-12-31</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="p1076912564617"><a name="p1076912564617"></a><a name="p1076912564617"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="p1176915562611"><a name="p1176915562611"></a><a name="p1176915562611"></a>设置日期选择器的结束时间，格式为 YYYY-MM-DD。</p>
</td>
</tr>
<tr id="row147919493619"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="p20769056565"><a name="p20769056565"></a><a name="p20769056565"></a>selected</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="p1376935613619"><a name="p1376935613619"></a><a name="p1376935613619"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="p177694568616"><a name="p177694568616"></a><a name="p177694568616"></a>当前日期</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="p076925617611"><a name="p076925617611"></a><a name="p076925617611"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="p17695564620"><a name="p17695564620"></a><a name="p17695564620"></a>设置日期选择器的默认选择值，格式为 YYYY-MM-DD。</p>
</td>
</tr>
<tr id="row106371036261"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="p2238125117139"><a name="p2238125117139"></a><a name="p2238125117139"></a>lunar<sup id="sup6301324133317"><a name="sup6301324133317"></a><a name="sup6301324133317"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="p023825181319"><a name="p023825181319"></a><a name="p023825181319"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="p18238115116134"><a name="p18238115116134"></a><a name="p18238115116134"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="p0238851121311"><a name="p0238851121311"></a><a name="p0238851121311"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="p14238195141316"><a name="p14238195141316"></a><a name="p14238195141316"></a>设置日期选择器弹窗界面是否为农历展示。</p>
</td>
</tr>
<tr id="row11239329191713"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="p13816132171719"><a name="p13816132171719"></a><a name="p13816132171719"></a>lunarswitch</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="p2081653261720"><a name="p2081653261720"></a><a name="p2081653261720"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="p1816103221715"><a name="p1816103221715"></a><a name="p1816103221715"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="p1181663281714"><a name="p1181663281714"></a><a name="p1181663281714"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="p781663212178"><a name="p781663212178"></a><a name="p781663212178"></a>设置日期选择器是否显示农历开关，显示农历开关时，可以在弹窗界面展现农历的开关由于公历和农历切换。在设置显示农历时，开关状态为开，当设置不显示农历时，开关状态为关。手机生效。</p>
<div class="note" id="note1688512355211"><a name="note1688512355211"></a><a name="note1688512355211"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="p488582345212"><a name="p488582345212"></a><a name="p488582345212"></a>仅手机和平板设备支持。</p>
</div></div>
</td>
</tr>
</tbody>
</table>

日期时间选择器：type=datetime，日期的选择范围为本年的日月。

<a name="table1188511392120"></a>
<table><thead align="left"><tr id="row16886193915128"><th class="cellrowborder" valign="top" width="24.000000000000004%" id="mcps1.1.6.1.1"><p id="p58868399129"><a name="p58868399129"></a><a name="p58868399129"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="10.810000000000002%" id="mcps1.1.6.1.2"><p id="p19886739161213"><a name="p19886739161213"></a><a name="p19886739161213"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="8.63%" id="mcps1.1.6.1.3"><p id="p138864393128"><a name="p138864393128"></a><a name="p138864393128"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.15%" id="mcps1.1.6.1.4"><p id="p288653914122"><a name="p288653914122"></a><a name="p288653914122"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="49.410000000000004%" id="mcps1.1.6.1.5"><p id="p1886193931212"><a name="p1886193931212"></a><a name="p1886193931212"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row288753919128"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="p20887539141215"><a name="p20887539141215"></a><a name="p20887539141215"></a>selected</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="p788753910126"><a name="p788753910126"></a><a name="p788753910126"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="p16887539111214"><a name="p16887539111214"></a><a name="p16887539111214"></a>当前日期时间</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="p4887203911129"><a name="p4887203911129"></a><a name="p4887203911129"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="p33848571013"><a name="p33848571013"></a><a name="p33848571013"></a>设置日期时间选择器的默认取值，格式有两种，为月日时分MM-DD-HH-mm或者年月日时分YYYY-MM-DD-HH-mm，不设置年时，默认使用当前年，该取值表示选择器弹窗时弹窗界面的默认选择值。</p>
</td>
</tr>
<tr id="row25569188246"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="p7249338141710"><a name="p7249338141710"></a><a name="p7249338141710"></a>hours</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="p1814251913247"><a name="p1814251913247"></a><a name="p1814251913247"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="p51424195244"><a name="p51424195244"></a><a name="p51424195244"></a>24<sup id="sup1626816180414"><a name="sup1626816180414"></a><a name="sup1626816180414"></a>1-4</sup></p>
<p id="p52731028173117"><a name="p52731028173117"></a><a name="p52731028173117"></a>-<sup id="sup627311285313"><a name="sup627311285313"></a><a name="sup627311285313"></a><span>5+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="p171426196242"><a name="p171426196242"></a><a name="p171426196242"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="p1314251932418"><a name="p1314251932418"></a><a name="p1314251932418"></a>设置日期时间选择器采用的时间格式，可选值：</p>
<a name="ul15923173119204"></a><a name="ul15923173119204"></a><ul id="ul15923173119204"><li>12：按照12小时制显示，用上午和下午进行区分；</li><li>24：按照24小时制显示。<div class="note" id="note1880145011113"><a name="note1880145011113"></a><a name="note1880145011113"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="p1988165031111"><a name="p1988165031111"></a><a name="p1988165031111"></a>默认值会依据系统当前所选地区和语言选择当地习惯的小时制(12小时制或24小时制)。<sup id="sup11183114910314"><a name="sup11183114910314"></a><a name="sup11183114910314"></a><span>5+</span></sup></p>
</div></div>
</li></ul>
</td>
</tr>
<tr id="row1742363212240"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="p1820281519182"><a name="p1820281519182"></a><a name="p1820281519182"></a>lunar<sup id="sup370711541116"><a name="sup370711541116"></a><a name="sup370711541116"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="p9202131571819"><a name="p9202131571819"></a><a name="p9202131571819"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="p520313152182"><a name="p520313152182"></a><a name="p520313152182"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="p142031715201812"><a name="p142031715201812"></a><a name="p142031715201812"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="p16203181541812"><a name="p16203181541812"></a><a name="p16203181541812"></a>设置日期时间选择器弹窗界面是否为农历展示。</p>
</td>
</tr>
<tr id="row34576125180"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="p120351520182"><a name="p120351520182"></a><a name="p120351520182"></a>lunarswitch</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="p5203415171819"><a name="p5203415171819"></a><a name="p5203415171819"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="p120317151181"><a name="p120317151181"></a><a name="p120317151181"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="p16203115101819"><a name="p16203115101819"></a><a name="p16203115101819"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="p12203111510184"><a name="p12203111510184"></a><a name="p12203111510184"></a>设置日期时间选择器是否显示农历开关，显示农历开关时，可以在弹窗界面展现农历的开关由于公历和农历切换。在设置显示农历时，开关状态为开，当设置不显示农历时，开关状态为关。手机生效。</p>
<div class="note" id="note11541837195218"><a name="note11541837195218"></a><a name="note11541837195218"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="p454119371529"><a name="p454119371529"></a><a name="p454119371529"></a>仅手机和平板设备支持。</p>
</div></div>
</td>
</tr>
</tbody>
</table>

多列文本选择器：type=multi-text

<a name="table1886619321772"></a>
<table><thead align="left"><tr id="row198671332179"><th class="cellrowborder" valign="top" width="24.000000000000004%" id="mcps1.1.6.1.1"><p id="p168677321871"><a name="p168677321871"></a><a name="p168677321871"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="10.810000000000002%" id="mcps1.1.6.1.2"><p id="p38670322711"><a name="p38670322711"></a><a name="p38670322711"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="8.63%" id="mcps1.1.6.1.3"><p id="p178670321276"><a name="p178670321276"></a><a name="p178670321276"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.15%" id="mcps1.1.6.1.4"><p id="p9867183215719"><a name="p9867183215719"></a><a name="p9867183215719"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="49.410000000000004%" id="mcps1.1.6.1.5"><p id="p168671324711"><a name="p168671324711"></a><a name="p168671324711"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row3757154961319"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="p12757204951314"><a name="p12757204951314"></a><a name="p12757204951314"></a>columns</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="p13757124918137"><a name="p13757124918137"></a><a name="p13757124918137"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="p0757144914132"><a name="p0757144914132"></a><a name="p0757144914132"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="p14757149111317"><a name="p14757149111317"></a><a name="p14757149111317"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="p1675884931313"><a name="p1675884931313"></a><a name="p1675884931313"></a>设置多列文本选择器的列数。</p>
</td>
</tr>
<tr id="row3867103214710"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="p793074416717"><a name="p793074416717"></a><a name="p793074416717"></a>range</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="p793010441976"><a name="p793010441976"></a><a name="p793010441976"></a>二维Array</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="p7930174418712"><a name="p7930174418712"></a><a name="p7930174418712"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="p2930444971"><a name="p2930444971"></a><a name="p2930444971"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="p139301644675"><a name="p139301644675"></a><a name="p139301644675"></a>设置多列文本选择器的选择值，该值为二维数组。长度表示多少列，数组的每项表示每列的数据，如  [["a","b"], ["c","d"]]。</p>
<div class="note" id="note112201642121219"><a name="note112201642121219"></a><a name="note112201642121219"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="p8220114221212"><a name="p8220114221212"></a><a name="p8220114221212"></a>使用时需要使用数据绑定的方式，如range = {{data}}，js中声明相应变量：data：[["a","b"], ["c","d"]]。</p>
</div></div>
</td>
</tr>
<tr id="row18671332572"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="p693016441273"><a name="p693016441273"></a><a name="p693016441273"></a>selected</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="p159306448720"><a name="p159306448720"></a><a name="p159306448720"></a>Array</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="p18930544471"><a name="p18930544471"></a><a name="p18930544471"></a>[0,0,0,…]</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="p69305448719"><a name="p69305448719"></a><a name="p69305448719"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="p12930144373"><a name="p12930144373"></a><a name="p12930144373"></a>设置多列文本选择器的默认值，每一列被选中项对应的索引构成的数组，该取值表示选择器弹窗时弹窗界面的默认选择值。</p>
</td>
</tr>
</tbody>
</table>

## 样式<a name="section198061172344"></a>

除支持[通用样式](js-components-common-styles.md)外，还支持如下样式：

<a name="table94919235408"></a>
<table><thead align="left"><tr id="row1349111237406"><th class="cellrowborder" valign="top" width="23.11768823117688%" id="mcps1.1.6.1.1"><p id="p13491122316409"><a name="p13491122316409"></a><a name="p13491122316409"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="20.477952204779523%" id="mcps1.1.6.1.2"><p id="p649192317408"><a name="p649192317408"></a><a name="p649192317408"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="10.47895210478952%" id="mcps1.1.6.1.3"><p id="p1849162384015"><a name="p1849162384015"></a><a name="p1849162384015"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="5.909409059094091%" id="mcps1.1.6.1.4"><p id="p449162318408"><a name="p449162318408"></a><a name="p449162318408"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="40.01599840015999%" id="mcps1.1.6.1.5"><p id="p12491102344016"><a name="p12491102344016"></a><a name="p12491102344016"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row114923234409"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p1849262316408"><a name="p1849262316408"></a><a name="p1849262316408"></a>color</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="p1249252318405"><a name="p1249252318405"></a><a name="p1249252318405"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.47895210478952%" headers="mcps1.1.6.1.3 "><p id="p9492162315401"><a name="p9492162315401"></a><a name="p9492162315401"></a>#ffffff</p>
</td>
<td class="cellrowborder" valign="top" width="5.909409059094091%" headers="mcps1.1.6.1.4 "><p id="p134923233404"><a name="p134923233404"></a><a name="p134923233404"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p84926239401"><a name="p84926239401"></a><a name="p84926239401"></a>候选项字体颜色。</p>
</td>
</tr>
<tr id="row1249232316406"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p14492122354013"><a name="p14492122354013"></a><a name="p14492122354013"></a>font-size</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="p249222310403"><a name="p249222310403"></a><a name="p249222310403"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.47895210478952%" headers="mcps1.1.6.1.3 "><p id="p1149212231402"><a name="p1149212231402"></a><a name="p1149212231402"></a>16px</p>
</td>
<td class="cellrowborder" valign="top" width="5.909409059094091%" headers="mcps1.1.6.1.4 "><p id="p1849282317409"><a name="p1849282317409"></a><a name="p1849282317409"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p19492112316406"><a name="p19492112316406"></a><a name="p19492112316406"></a>候选项字体尺寸，类型length，单位px。</p>
</td>
</tr>
<tr id="row1249262314017"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p54925236401"><a name="p54925236401"></a><a name="p54925236401"></a>selected-color</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="p449219234408"><a name="p449219234408"></a><a name="p449219234408"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.47895210478952%" headers="mcps1.1.6.1.3 "><p id="p54924238408"><a name="p54924238408"></a><a name="p54924238408"></a>#ff0a69f7</p>
</td>
<td class="cellrowborder" valign="top" width="5.909409059094091%" headers="mcps1.1.6.1.4 "><p id="p949242334013"><a name="p949242334013"></a><a name="p949242334013"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p20492152334010"><a name="p20492152334010"></a><a name="p20492152334010"></a>选中项字体颜色。</p>
</td>
</tr>
<tr id="row10492423134013"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p174938237409"><a name="p174938237409"></a><a name="p174938237409"></a>selected-font-size</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="p9493182314010"><a name="p9493182314010"></a><a name="p9493182314010"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.47895210478952%" headers="mcps1.1.6.1.3 "><p id="p16493223104019"><a name="p16493223104019"></a><a name="p16493223104019"></a>20px</p>
</td>
<td class="cellrowborder" valign="top" width="5.909409059094091%" headers="mcps1.1.6.1.4 "><p id="p74931223124013"><a name="p74931223124013"></a><a name="p74931223124013"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p449342311407"><a name="p449342311407"></a><a name="p449342311407"></a>选中项字体尺寸，类型length，单位px。</p>
</td>
</tr>
<tr id="row84941623134017"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p104941323114011"><a name="p104941323114011"></a><a name="p104941323114011"></a>disappear-color<sup id="sup54941523144015"><a name="sup54941523144015"></a><a name="sup54941523144015"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="p349412319400"><a name="p349412319400"></a><a name="p349412319400"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.47895210478952%" headers="mcps1.1.6.1.3 "><p id="p14942236409"><a name="p14942236409"></a><a name="p14942236409"></a>#ffffff</p>
</td>
<td class="cellrowborder" valign="top" width="5.909409059094091%" headers="mcps1.1.6.1.4 "><p id="p10494123164013"><a name="p10494123164013"></a><a name="p10494123164013"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p20494323144012"><a name="p20494323144012"></a><a name="p20494323144012"></a>渐变消失项的字体颜色。消失项是在一列中有五个选项场景下最上和最下的两个选项。</p>
<div class="note" id="note682125718522"><a name="note682125718522"></a><a name="note682125718522"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="p17821185711521"><a name="p17821185711521"></a><a name="p17821185711521"></a>仅手机和平板设备支持。</p>
</div></div>
</td>
</tr>
<tr id="row1949432318405"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p1549419237407"><a name="p1549419237407"></a><a name="p1549419237407"></a>disappear-font-size<sup id="sup0494132313404"><a name="sup0494132313404"></a><a name="sup0494132313404"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="p144940238404"><a name="p144940238404"></a><a name="p144940238404"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.47895210478952%" headers="mcps1.1.6.1.3 "><p id="p64941023194020"><a name="p64941023194020"></a><a name="p64941023194020"></a>14px</p>
</td>
<td class="cellrowborder" valign="top" width="5.909409059094091%" headers="mcps1.1.6.1.4 "><p id="p1949522364020"><a name="p1949522364020"></a><a name="p1949522364020"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p1549532364020"><a name="p1549532364020"></a><a name="p1549532364020"></a>渐变消失项的字体尺寸。消失项是在一列中有五个选项场景下最上和最下的两个选项。</p>
<div class="note" id="note17211975317"><a name="note17211975317"></a><a name="note17211975317"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="p1821895535"><a name="p1821895535"></a><a name="p1821895535"></a>仅手机和平板设备支持。</p>
</div></div>
</td>
</tr>
<tr id="row19495152311405"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p154951237400"><a name="p154951237400"></a><a name="p154951237400"></a>font-family</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="p3495192316402"><a name="p3495192316402"></a><a name="p3495192316402"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.47895210478952%" headers="mcps1.1.6.1.3 "><p id="p8495172324010"><a name="p8495172324010"></a><a name="p8495172324010"></a>sans-serif</p>
</td>
<td class="cellrowborder" valign="top" width="5.909409059094091%" headers="mcps1.1.6.1.4 "><p id="p134951723154010"><a name="p134951723154010"></a><a name="p134951723154010"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p124957233408"><a name="p124957233408"></a><a name="p124957233408"></a>选项字体类型。字体列表，用逗号分隔，每个字体用字体名或者字体族名设置。列表中第一个系统中存在的或者通过<a href="js-components-common-customizing-font.md">自定义字体</a>指定的字体，会被选中作为文本的字体。</p>
</td>
</tr>
</tbody>
</table>

## 事件<a name="section103398253399"></a>

仅支持如下事件：

type=text：

<a name="table17339225123915"></a>
<table><thead align="left"><tr id="row1339925143920"><th class="cellrowborder" valign="top" width="16.16161616161616%" id="mcps1.1.4.1.1"><p id="p8340925103911"><a name="p8340925103911"></a><a name="p8340925103911"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="41.41414141414141%" id="mcps1.1.4.1.2"><p id="p2340325113912"><a name="p2340325113912"></a><a name="p2340325113912"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="42.42424242424242%" id="mcps1.1.4.1.3"><p id="p1534013255394"><a name="p1534013255394"></a><a name="p1534013255394"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row15340192543910"><td class="cellrowborder" valign="top" width="16.16161616161616%" headers="mcps1.1.4.1.1 "><p id="p334016258395"><a name="p334016258395"></a><a name="p334016258395"></a>change</p>
</td>
<td class="cellrowborder" valign="top" width="41.41414141414141%" headers="mcps1.1.4.1.2 "><p id="p93401725183918"><a name="p93401725183918"></a><a name="p93401725183918"></a>{ newValue: newValue, newSelected: newSelected }</p>
</td>
<td class="cellrowborder" valign="top" width="42.42424242424242%" headers="mcps1.1.4.1.3 "><p id="p17340122515397"><a name="p17340122515397"></a><a name="p17340122515397"></a>文本选择器选定值后触发该事件。</p>
</td>
</tr>
</tbody>
</table>

type=time：

<a name="table13340325133918"></a>
<table><thead align="left"><tr id="row20340125143918"><th class="cellrowborder" valign="top" width="16.16161616161616%" id="mcps1.1.4.1.1"><p id="p14340152533917"><a name="p14340152533917"></a><a name="p14340152533917"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="41.41414141414141%" id="mcps1.1.4.1.2"><p id="p1634082553920"><a name="p1634082553920"></a><a name="p1634082553920"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="42.42424242424242%" id="mcps1.1.4.1.3"><p id="p134072523914"><a name="p134072523914"></a><a name="p134072523914"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1434032553920"><td class="cellrowborder" valign="top" width="16.16161616161616%" headers="mcps1.1.4.1.1 "><p id="p3341625183910"><a name="p3341625183910"></a><a name="p3341625183910"></a>change</p>
</td>
<td class="cellrowborder" valign="top" width="41.41414141414141%" headers="mcps1.1.4.1.2 "><p id="p1634122513911"><a name="p1634122513911"></a><a name="p1634122513911"></a>{ hour: hour, minute: minute<span id="ph734120255396"><a name="ph734120255396"></a><a name="ph734120255396"></a>, [second:second] </span>}</p>
</td>
<td class="cellrowborder" valign="top" width="42.42424242424242%" headers="mcps1.1.4.1.3 "><p id="p4341225133916"><a name="p4341225133916"></a><a name="p4341225133916"></a>时间选择器选定值后触发该事件。</p>
<p id="p1341192514397"><a name="p1341192514397"></a><a name="p1341192514397"></a>包含秒时，返回时分秒。</p>
</td>
</tr>
</tbody>
</table>

type=date：

<a name="table103414254397"></a>
<table><thead align="left"><tr id="row234142553912"><th class="cellrowborder" valign="top" width="15.370000000000001%" id="mcps1.1.4.1.1"><p id="p7341125153916"><a name="p7341125153916"></a><a name="p7341125153916"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="34.22%" id="mcps1.1.4.1.2"><p id="p1834182593915"><a name="p1834182593915"></a><a name="p1834182593915"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="50.41%" id="mcps1.1.4.1.3"><p id="p5341142593910"><a name="p5341142593910"></a><a name="p5341142593910"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row83411325103912"><td class="cellrowborder" valign="top" width="15.370000000000001%" headers="mcps1.1.4.1.1 "><p id="p6341122553914"><a name="p6341122553914"></a><a name="p6341122553914"></a>change</p>
</td>
<td class="cellrowborder" valign="top" width="34.22%" headers="mcps1.1.4.1.2 "><p id="p17341192563911"><a name="p17341192563911"></a><a name="p17341192563911"></a>{ year:year, month:month, day:day }</p>
</td>
<td class="cellrowborder" valign="top" width="50.41%" headers="mcps1.1.4.1.3 "><p id="p103419259392"><a name="p103419259392"></a><a name="p103419259392"></a>日期选择器选择值后触发该事件。</p>
</td>
</tr>
</tbody>
</table>

type=datetime：

<a name="table6342192514395"></a>
<table><thead align="left"><tr id="row43421725183919"><th class="cellrowborder" valign="top" width="15.370000000000001%" id="mcps1.1.4.1.1"><p id="p17342325173911"><a name="p17342325173911"></a><a name="p17342325173911"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="34.22%" id="mcps1.1.4.1.2"><p id="p63421825113915"><a name="p63421825113915"></a><a name="p63421825113915"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="50.41%" id="mcps1.1.4.1.3"><p id="p634217257395"><a name="p634217257395"></a><a name="p634217257395"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1234216257392"><td class="cellrowborder" valign="top" width="15.370000000000001%" headers="mcps1.1.4.1.1 "><p id="p5342725203916"><a name="p5342725203916"></a><a name="p5342725203916"></a>change</p>
</td>
<td class="cellrowborder" valign="top" width="34.22%" headers="mcps1.1.4.1.2 "><p id="p20342132512395"><a name="p20342132512395"></a><a name="p20342132512395"></a>{ year:year, month:month, day:day,  hour:hour, minute:minute }</p>
</td>
<td class="cellrowborder" valign="top" width="50.41%" headers="mcps1.1.4.1.3 "><p id="p11342102563910"><a name="p11342102563910"></a><a name="p11342102563910"></a>日期时间选择器选择值后触发该事件。</p>
</td>
</tr>
</tbody>
</table>

type=multi-text：

<a name="table5342325203913"></a>
<table><thead align="left"><tr id="row153422255390"><th class="cellrowborder" valign="top" width="13.969999999999999%" id="mcps1.1.4.1.1"><p id="p153431725153916"><a name="p153431725153916"></a><a name="p153431725153916"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="36.9%" id="mcps1.1.4.1.2"><p id="p11343102523916"><a name="p11343102523916"></a><a name="p11343102523916"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="49.13%" id="mcps1.1.4.1.3"><p id="p16343925193913"><a name="p16343925193913"></a><a name="p16343925193913"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row103430256392"><td class="cellrowborder" valign="top" width="13.969999999999999%" headers="mcps1.1.4.1.1 "><p id="p19343122514399"><a name="p19343122514399"></a><a name="p19343122514399"></a>columnchange</p>
</td>
<td class="cellrowborder" valign="top" width="36.9%" headers="mcps1.1.4.1.2 "><p id="p12343102573913"><a name="p12343102573913"></a><a name="p12343102573913"></a>{ column:column, newValue:newValue, newSelected:newSelected }</p>
</td>
<td class="cellrowborder" valign="top" width="49.13%" headers="mcps1.1.4.1.3 "><p id="p1534352593917"><a name="p1534352593917"></a><a name="p1534352593917"></a>多列文本选择器某一列的值改变时触发该事件，column：第几列修改，newValue：选中的值，newSelected：选中值对应的索引。</p>
</td>
</tr>
</tbody>
</table>

## 方法<a name="section718304515396"></a>

不支持。

## 示例<a name="section738534695417"></a>

```
<!-- xxx.hml -->
<div class="container" @swipe="handleSwipe">
  <text class="title">
    Selected：{{time}}
  </text>
  <picker-view class="time-picker" type="time" selected="{{defaultTime}}" @change="handleChange"></picker-view>
</div>
```

```
/* xxx.css */
.container {
  flex-direction: column;
  justify-content: center;
  align-items: center;
  left: 0px;
  top: 0px;
  width: 454px;
  height: 454px;
}
.title {
  font-size: 30px;
  text-align: center;
}
.time-picker {
  width: 500px;
  height: 400px;
  margin-top: 20px;
}
```

```
/* xxx.js */
export default {
  data: {
    defaultTime: "",
    time: "",
  },
  onInit() {
    this.defaultTime = this.now();
  },
  handleChange(data) {
    this.time = this.concat(data.hour, data.minute);
  },
  now() {
    const date = new Date();
    const hours = date.getHours();
    const minutes = date.getMinutes();
    return this.concat(hours, minutes);
  },

  fill(value) {
    return (value > 9 ? "" : "0") + value;
  },

  concat(hours, minutes) {
    return `${this.fill(hours)}:${this.fill(minutes)}`;
  },
}
```

![](figures/sssssss.png)

