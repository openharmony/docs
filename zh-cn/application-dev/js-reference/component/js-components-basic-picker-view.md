# picker-view<a name="ZH-CN_TOPIC_0000001164290714"></a>

-   [子组件](#zh-cn_topic_0000001127125108_section54292411343)
-   [属性](#zh-cn_topic_0000001127125108_section121957126347)
-   [样式](#zh-cn_topic_0000001127125108_section198061172344)
-   [事件](#zh-cn_topic_0000001127125108_section103398253399)
-   [方法](#zh-cn_topic_0000001127125108_section718304515396)
-   [示例](#zh-cn_topic_0000001127125108_section738534695417)

嵌入页面的滑动选择器。

## 子组件<a name="zh-cn_topic_0000001127125108_section54292411343"></a>

不支持。

## 属性<a name="zh-cn_topic_0000001127125108_section121957126347"></a>

除支持[通用属性](js-components-common-attributes.md#ZH-CN_TOPIC_0000001163812208)外，还支持如下属性：

<a name="zh-cn_topic_0000001127125108_table20633101642315"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001127125108_row663331618238"><th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001127125108_aa872998ac2d84843a3c5161889afffef"><a name="zh-cn_topic_0000001127125108_aa872998ac2d84843a3c5161889afffef"></a><a name="zh-cn_topic_0000001127125108_aa872998ac2d84843a3c5161889afffef"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001127125108_ab2111648ee0e4f6d881be8954e7acaab"><a name="zh-cn_topic_0000001127125108_ab2111648ee0e4f6d881be8954e7acaab"></a><a name="zh-cn_topic_0000001127125108_ab2111648ee0e4f6d881be8954e7acaab"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="10.48%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001127125108_ab377d1c90900478ea4ecab51e9a058af"><a name="zh-cn_topic_0000001127125108_ab377d1c90900478ea4ecab51e9a058af"></a><a name="zh-cn_topic_0000001127125108_ab377d1c90900478ea4ecab51e9a058af"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001127125108_p824610360217"><a name="zh-cn_topic_0000001127125108_p824610360217"></a><a name="zh-cn_topic_0000001127125108_p824610360217"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="35.76%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001127125108_a1d574a0044ed42ec8a2603bc82734232"><a name="zh-cn_topic_0000001127125108_a1d574a0044ed42ec8a2603bc82734232"></a><a name="zh-cn_topic_0000001127125108_a1d574a0044ed42ec8a2603bc82734232"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001127125108_row6290565914"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125108_p136971571796"><a name="zh-cn_topic_0000001127125108_p136971571796"></a><a name="zh-cn_topic_0000001127125108_p136971571796"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125108_p36971373918"><a name="zh-cn_topic_0000001127125108_p36971373918"></a><a name="zh-cn_topic_0000001127125108_p36971373918"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125108_p3697774912"><a name="zh-cn_topic_0000001127125108_p3697774912"></a><a name="zh-cn_topic_0000001127125108_p3697774912"></a>text</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125108_p12697377919"><a name="zh-cn_topic_0000001127125108_p12697377919"></a><a name="zh-cn_topic_0000001127125108_p12697377919"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125108_p126974719915"><a name="zh-cn_topic_0000001127125108_p126974719915"></a><a name="zh-cn_topic_0000001127125108_p126974719915"></a>设置滑动选择器的类型，该属性不支持动态修改，可选项有：</p>
<a name="zh-cn_topic_0000001127125108_ul16977711916"></a><a name="zh-cn_topic_0000001127125108_ul16977711916"></a><ul id="zh-cn_topic_0000001127125108_ul16977711916"><li>text：文本选择器。</li><li>time：时间选择器。</li><li>date：日期选择器。</li><li>datetime：日期时间选择器。</li><li>multi-text：多列文本选择器。</li></ul>
</td>
</tr>
</tbody>
</table>

文本选择器：type=text

<a name="zh-cn_topic_0000001127125108_ta708bd4856a044b79bae50a2ce6981b8"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001127125108_re08662644cee4140ad0d5bac7978cd9b"><th class="cellrowborder" valign="top" width="24.007599240075994%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001127125108_af5b093e471ec47119f04bf2fe91b6f64"><a name="zh-cn_topic_0000001127125108_af5b093e471ec47119f04bf2fe91b6f64"></a><a name="zh-cn_topic_0000001127125108_af5b093e471ec47119f04bf2fe91b6f64"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="10.808919108089192%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001127125108_a8c2c2f6a645749b7852ec7dcadaca702"><a name="zh-cn_topic_0000001127125108_a8c2c2f6a645749b7852ec7dcadaca702"></a><a name="zh-cn_topic_0000001127125108_a8c2c2f6a645749b7852ec7dcadaca702"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="8.62913708629137%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001127125108_aa63c3dd750aa44fb9ec9031e632f4f5f"><a name="zh-cn_topic_0000001127125108_aa63c3dd750aa44fb9ec9031e632f4f5f"></a><a name="zh-cn_topic_0000001127125108_aa63c3dd750aa44fb9ec9031e632f4f5f"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.14928507149285%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001127125108_aee9661e3366543aeac6aa37e48de4c87"><a name="zh-cn_topic_0000001127125108_aee9661e3366543aeac6aa37e48de4c87"></a><a name="zh-cn_topic_0000001127125108_aee9661e3366543aeac6aa37e48de4c87"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="49.4050594940506%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001127125108_a2dc04c78fce4402d9dead84ab8412bb3"><a name="zh-cn_topic_0000001127125108_a2dc04c78fce4402d9dead84ab8412bb3"></a><a name="zh-cn_topic_0000001127125108_a2dc04c78fce4402d9dead84ab8412bb3"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001127125108_re8122915226c4596b2bffeae21e37b10"><td class="cellrowborder" valign="top" width="24.007599240075994%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125108_p64901432865"><a name="zh-cn_topic_0000001127125108_p64901432865"></a><a name="zh-cn_topic_0000001127125108_p64901432865"></a>range</p>
</td>
<td class="cellrowborder" valign="top" width="10.808919108089192%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125108_p194901326610"><a name="zh-cn_topic_0000001127125108_p194901326610"></a><a name="zh-cn_topic_0000001127125108_p194901326610"></a>Array</p>
</td>
<td class="cellrowborder" valign="top" width="8.62913708629137%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125108_p16490183216616"><a name="zh-cn_topic_0000001127125108_p16490183216616"></a><a name="zh-cn_topic_0000001127125108_p16490183216616"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.14928507149285%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125108_p12490132765"><a name="zh-cn_topic_0000001127125108_p12490132765"></a><a name="zh-cn_topic_0000001127125108_p12490132765"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.4050594940506%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125108_p879110395507"><a name="zh-cn_topic_0000001127125108_p879110395507"></a><a name="zh-cn_topic_0000001127125108_p879110395507"></a>设置文本选择器的取值范围。</p>
<div class="note" id="zh-cn_topic_0000001127125108_note195791919121"><a name="zh-cn_topic_0000001127125108_note195791919121"></a><a name="zh-cn_topic_0000001127125108_note195791919121"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001127125108_p11957191913124"><a name="zh-cn_topic_0000001127125108_p11957191913124"></a><a name="zh-cn_topic_0000001127125108_p11957191913124"></a>使用时需要使用数据绑定的方式，如range = {{data}}，js中声明相应变量：data：["15", "20", "25"]。</p>
</div></div>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125108_row2068183074711"><td class="cellrowborder" valign="top" width="24.007599240075994%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125108_p54902321765"><a name="zh-cn_topic_0000001127125108_p54902321765"></a><a name="zh-cn_topic_0000001127125108_p54902321765"></a>selected</p>
</td>
<td class="cellrowborder" valign="top" width="10.808919108089192%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125108_p24901321469"><a name="zh-cn_topic_0000001127125108_p24901321469"></a><a name="zh-cn_topic_0000001127125108_p24901321469"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.62913708629137%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125108_p14901932863"><a name="zh-cn_topic_0000001127125108_p14901932863"></a><a name="zh-cn_topic_0000001127125108_p14901932863"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.14928507149285%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125108_p1049018321869"><a name="zh-cn_topic_0000001127125108_p1049018321869"></a><a name="zh-cn_topic_0000001127125108_p1049018321869"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.4050594940506%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125108_p649017329613"><a name="zh-cn_topic_0000001127125108_p649017329613"></a><a name="zh-cn_topic_0000001127125108_p649017329613"></a>设置文本选择器的默认选择值，该值需要为range的索引。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125108_row1045119531711"><td class="cellrowborder" valign="top" width="24.007599240075994%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125108_p54526530112"><a name="zh-cn_topic_0000001127125108_p54526530112"></a><a name="zh-cn_topic_0000001127125108_p54526530112"></a><span>indicator</span>prefix</p>
</td>
<td class="cellrowborder" valign="top" width="10.808919108089192%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125108_p24521553119"><a name="zh-cn_topic_0000001127125108_p24521553119"></a><a name="zh-cn_topic_0000001127125108_p24521553119"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.62913708629137%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125108_p14524531315"><a name="zh-cn_topic_0000001127125108_p14524531315"></a><a name="zh-cn_topic_0000001127125108_p14524531315"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.14928507149285%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125108_p134526535117"><a name="zh-cn_topic_0000001127125108_p134526535117"></a><a name="zh-cn_topic_0000001127125108_p134526535117"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.4050594940506%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125108_p114526534115"><a name="zh-cn_topic_0000001127125108_p114526534115"></a><a name="zh-cn_topic_0000001127125108_p114526534115"></a>文本选择器选定值增加的前缀字段。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125108_row115191458171210"><td class="cellrowborder" valign="top" width="24.007599240075994%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125108_p2052015584123"><a name="zh-cn_topic_0000001127125108_p2052015584123"></a><a name="zh-cn_topic_0000001127125108_p2052015584123"></a>indicatorsuffix</p>
</td>
<td class="cellrowborder" valign="top" width="10.808919108089192%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125108_p0520458141213"><a name="zh-cn_topic_0000001127125108_p0520458141213"></a><a name="zh-cn_topic_0000001127125108_p0520458141213"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.62913708629137%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125108_p25201358191214"><a name="zh-cn_topic_0000001127125108_p25201358191214"></a><a name="zh-cn_topic_0000001127125108_p25201358191214"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.14928507149285%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125108_p952085813124"><a name="zh-cn_topic_0000001127125108_p952085813124"></a><a name="zh-cn_topic_0000001127125108_p952085813124"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.4050594940506%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125108_p175201958121212"><a name="zh-cn_topic_0000001127125108_p175201958121212"></a><a name="zh-cn_topic_0000001127125108_p175201958121212"></a>文本选择器选定值增加的后缀字段。</p>
</td>
</tr>
</tbody>
</table>

时间选择器：type=time

<a name="zh-cn_topic_0000001127125108_table89366820719"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001127125108_row49367819714"><th class="cellrowborder" valign="top" width="24%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001127125108_p1493614815715"><a name="zh-cn_topic_0000001127125108_p1493614815715"></a><a name="zh-cn_topic_0000001127125108_p1493614815715"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="10.83%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001127125108_p2936881677"><a name="zh-cn_topic_0000001127125108_p2936881677"></a><a name="zh-cn_topic_0000001127125108_p2936881677"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="8.61%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001127125108_p79362815719"><a name="zh-cn_topic_0000001127125108_p79362815719"></a><a name="zh-cn_topic_0000001127125108_p79362815719"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.1499999999999995%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001127125108_p12936584719"><a name="zh-cn_topic_0000001127125108_p12936584719"></a><a name="zh-cn_topic_0000001127125108_p12936584719"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="49.41%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001127125108_p15936198876"><a name="zh-cn_topic_0000001127125108_p15936198876"></a><a name="zh-cn_topic_0000001127125108_p15936198876"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001127125108_row2937108277"><td class="cellrowborder" valign="top" width="24%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125108_p077212191171"><a name="zh-cn_topic_0000001127125108_p077212191171"></a><a name="zh-cn_topic_0000001127125108_p077212191171"></a>containsecond</p>
</td>
<td class="cellrowborder" valign="top" width="10.83%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125108_p1177214198714"><a name="zh-cn_topic_0000001127125108_p1177214198714"></a><a name="zh-cn_topic_0000001127125108_p1177214198714"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="8.61%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125108_p87721619275"><a name="zh-cn_topic_0000001127125108_p87721619275"></a><a name="zh-cn_topic_0000001127125108_p87721619275"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.1499999999999995%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125108_p127721919372"><a name="zh-cn_topic_0000001127125108_p127721919372"></a><a name="zh-cn_topic_0000001127125108_p127721919372"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.41%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125108_p13773101919719"><a name="zh-cn_topic_0000001127125108_p13773101919719"></a><a name="zh-cn_topic_0000001127125108_p13773101919719"></a>时间选择器是否包含秒。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125108_row1293719814712"><td class="cellrowborder" valign="top" width="24%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125108_p577314191171"><a name="zh-cn_topic_0000001127125108_p577314191171"></a><a name="zh-cn_topic_0000001127125108_p577314191171"></a>selected</p>
</td>
<td class="cellrowborder" valign="top" width="10.83%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125108_p177735196711"><a name="zh-cn_topic_0000001127125108_p177735196711"></a><a name="zh-cn_topic_0000001127125108_p177735196711"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.61%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125108_p127734191714"><a name="zh-cn_topic_0000001127125108_p127734191714"></a><a name="zh-cn_topic_0000001127125108_p127734191714"></a><span id="zh-cn_topic_0000001127125108_ph61411732205214"><a name="zh-cn_topic_0000001127125108_ph61411732205214"></a><a name="zh-cn_topic_0000001127125108_ph61411732205214"></a>当前时间</span></p>
</td>
<td class="cellrowborder" valign="top" width="7.1499999999999995%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125108_p16773151914716"><a name="zh-cn_topic_0000001127125108_p16773151914716"></a><a name="zh-cn_topic_0000001127125108_p16773151914716"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.41%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125108_p5241145091814"><a name="zh-cn_topic_0000001127125108_p5241145091814"></a><a name="zh-cn_topic_0000001127125108_p5241145091814"></a>设置时间选择器的默认取值，格式为 HH:mm；</p>
<p id="zh-cn_topic_0000001127125108_p57739191974"><a name="zh-cn_topic_0000001127125108_p57739191974"></a><a name="zh-cn_topic_0000001127125108_p57739191974"></a>当包含秒时，格式为HH:mm:ss。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125108_row3976191332214"><td class="cellrowborder" valign="top" width="24%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125108_p095363112111"><a name="zh-cn_topic_0000001127125108_p095363112111"></a><a name="zh-cn_topic_0000001127125108_p095363112111"></a>hours</p>
</td>
<td class="cellrowborder" valign="top" width="10.83%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125108_p6953193114218"><a name="zh-cn_topic_0000001127125108_p6953193114218"></a><a name="zh-cn_topic_0000001127125108_p6953193114218"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.61%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125108_p16934121142417"><a name="zh-cn_topic_0000001127125108_p16934121142417"></a><a name="zh-cn_topic_0000001127125108_p16934121142417"></a>24<sup id="zh-cn_topic_0000001127125108_sup169341019245"><a name="zh-cn_topic_0000001127125108_sup169341019245"></a><a name="zh-cn_topic_0000001127125108_sup169341019245"></a>1-4</sup></p>
<p id="zh-cn_topic_0000001127125108_p81051142202817"><a name="zh-cn_topic_0000001127125108_p81051142202817"></a><a name="zh-cn_topic_0000001127125108_p81051142202817"></a>-<sup id="zh-cn_topic_0000001127125108_sup14229658122718"><a name="zh-cn_topic_0000001127125108_sup14229658122718"></a><a name="zh-cn_topic_0000001127125108_sup14229658122718"></a><span>5+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="7.1499999999999995%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125108_p0953193112117"><a name="zh-cn_topic_0000001127125108_p0953193112117"></a><a name="zh-cn_topic_0000001127125108_p0953193112117"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.41%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125108_p1095393116216"><a name="zh-cn_topic_0000001127125108_p1095393116216"></a><a name="zh-cn_topic_0000001127125108_p1095393116216"></a>设置时间选择器采用的时间格式，可选值：</p>
<a name="zh-cn_topic_0000001127125108_ul11382144442112"></a><a name="zh-cn_topic_0000001127125108_ul11382144442112"></a><ul id="zh-cn_topic_0000001127125108_ul11382144442112"><li>12：按照12小时制显示，用上午和下午进行区分；</li><li>24：按照24小时制显示。<div class="note" id="zh-cn_topic_0000001127125108_note189471313104"><a name="zh-cn_topic_0000001127125108_note189471313104"></a><a name="zh-cn_topic_0000001127125108_note189471313104"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001127125108_p9947193114104"><a name="zh-cn_topic_0000001127125108_p9947193114104"></a><a name="zh-cn_topic_0000001127125108_p9947193114104"></a>默认值会依据系统当前所选地区和语言选择当地习惯的小时制(12小时制或24小时制)。<sup id="zh-cn_topic_0000001127125108_sup319942110314"><a name="zh-cn_topic_0000001127125108_sup319942110314"></a><a name="zh-cn_topic_0000001127125108_sup319942110314"></a><span>5+</span></sup></p>
</div></div>
</li></ul>
</td>
</tr>
</tbody>
</table>

日期选择器：type=date

<a name="zh-cn_topic_0000001127125108_table174784493618"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001127125108_row54789491561"><th class="cellrowborder" valign="top" width="24.000000000000004%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001127125108_p14781849561"><a name="zh-cn_topic_0000001127125108_p14781849561"></a><a name="zh-cn_topic_0000001127125108_p14781849561"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="10.810000000000002%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001127125108_p447834912613"><a name="zh-cn_topic_0000001127125108_p447834912613"></a><a name="zh-cn_topic_0000001127125108_p447834912613"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="8.63%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001127125108_p12479749564"><a name="zh-cn_topic_0000001127125108_p12479749564"></a><a name="zh-cn_topic_0000001127125108_p12479749564"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.15%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001127125108_p13479749560"><a name="zh-cn_topic_0000001127125108_p13479749560"></a><a name="zh-cn_topic_0000001127125108_p13479749560"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="49.410000000000004%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001127125108_p247913495610"><a name="zh-cn_topic_0000001127125108_p247913495610"></a><a name="zh-cn_topic_0000001127125108_p247913495610"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001127125108_row1047910498616"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125108_p167682562062"><a name="zh-cn_topic_0000001127125108_p167682562062"></a><a name="zh-cn_topic_0000001127125108_p167682562062"></a>start</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125108_p67689566612"><a name="zh-cn_topic_0000001127125108_p67689566612"></a><a name="zh-cn_topic_0000001127125108_p67689566612"></a>&lt;time&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125108_p1576817561266"><a name="zh-cn_topic_0000001127125108_p1576817561266"></a><a name="zh-cn_topic_0000001127125108_p1576817561266"></a>1970-1-1</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125108_p476819561368"><a name="zh-cn_topic_0000001127125108_p476819561368"></a><a name="zh-cn_topic_0000001127125108_p476819561368"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125108_p87681568618"><a name="zh-cn_topic_0000001127125108_p87681568618"></a><a name="zh-cn_topic_0000001127125108_p87681568618"></a>设置日期选择器的起始时间，格式为 YYYY-MM-DD。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125108_row3479549162"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125108_p117686568615"><a name="zh-cn_topic_0000001127125108_p117686568615"></a><a name="zh-cn_topic_0000001127125108_p117686568615"></a>end</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125108_p19768115614615"><a name="zh-cn_topic_0000001127125108_p19768115614615"></a><a name="zh-cn_topic_0000001127125108_p19768115614615"></a>&lt;time&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125108_p27686569618"><a name="zh-cn_topic_0000001127125108_p27686569618"></a><a name="zh-cn_topic_0000001127125108_p27686569618"></a>2100-12-31</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125108_p1076912564617"><a name="zh-cn_topic_0000001127125108_p1076912564617"></a><a name="zh-cn_topic_0000001127125108_p1076912564617"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125108_p1176915562611"><a name="zh-cn_topic_0000001127125108_p1176915562611"></a><a name="zh-cn_topic_0000001127125108_p1176915562611"></a>设置日期选择器的结束时间，格式为 YYYY-MM-DD。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125108_row147919493619"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125108_p20769056565"><a name="zh-cn_topic_0000001127125108_p20769056565"></a><a name="zh-cn_topic_0000001127125108_p20769056565"></a>selected</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125108_p1376935613619"><a name="zh-cn_topic_0000001127125108_p1376935613619"></a><a name="zh-cn_topic_0000001127125108_p1376935613619"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125108_p177694568616"><a name="zh-cn_topic_0000001127125108_p177694568616"></a><a name="zh-cn_topic_0000001127125108_p177694568616"></a>当前日期</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125108_p076925617611"><a name="zh-cn_topic_0000001127125108_p076925617611"></a><a name="zh-cn_topic_0000001127125108_p076925617611"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125108_p17695564620"><a name="zh-cn_topic_0000001127125108_p17695564620"></a><a name="zh-cn_topic_0000001127125108_p17695564620"></a>设置日期选择器的默认选择值，格式为 YYYY-MM-DD。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125108_row106371036261"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125108_p2238125117139"><a name="zh-cn_topic_0000001127125108_p2238125117139"></a><a name="zh-cn_topic_0000001127125108_p2238125117139"></a>lunar<sup id="zh-cn_topic_0000001127125108_sup6301324133317"><a name="zh-cn_topic_0000001127125108_sup6301324133317"></a><a name="zh-cn_topic_0000001127125108_sup6301324133317"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125108_p023825181319"><a name="zh-cn_topic_0000001127125108_p023825181319"></a><a name="zh-cn_topic_0000001127125108_p023825181319"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125108_p18238115116134"><a name="zh-cn_topic_0000001127125108_p18238115116134"></a><a name="zh-cn_topic_0000001127125108_p18238115116134"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125108_p0238851121311"><a name="zh-cn_topic_0000001127125108_p0238851121311"></a><a name="zh-cn_topic_0000001127125108_p0238851121311"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125108_p14238195141316"><a name="zh-cn_topic_0000001127125108_p14238195141316"></a><a name="zh-cn_topic_0000001127125108_p14238195141316"></a>设置日期选择器弹窗界面是否为农历展示。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125108_row11239329191713"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125108_p13816132171719"><a name="zh-cn_topic_0000001127125108_p13816132171719"></a><a name="zh-cn_topic_0000001127125108_p13816132171719"></a>lunarswitch</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125108_p2081653261720"><a name="zh-cn_topic_0000001127125108_p2081653261720"></a><a name="zh-cn_topic_0000001127125108_p2081653261720"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125108_p1816103221715"><a name="zh-cn_topic_0000001127125108_p1816103221715"></a><a name="zh-cn_topic_0000001127125108_p1816103221715"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125108_p1181663281714"><a name="zh-cn_topic_0000001127125108_p1181663281714"></a><a name="zh-cn_topic_0000001127125108_p1181663281714"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125108_p781663212178"><a name="zh-cn_topic_0000001127125108_p781663212178"></a><a name="zh-cn_topic_0000001127125108_p781663212178"></a>设置日期选择器是否显示农历开关，显示农历开关时，可以在弹窗界面展现农历的开关由于公历和农历切换。在设置显示农历时，开关状态为开，当设置不显示农历时，开关状态为关。手机生效。</p>
<div class="note" id="zh-cn_topic_0000001127125108_note1688512355211"><a name="zh-cn_topic_0000001127125108_note1688512355211"></a><a name="zh-cn_topic_0000001127125108_note1688512355211"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001127125108_p488582345212"><a name="zh-cn_topic_0000001127125108_p488582345212"></a><a name="zh-cn_topic_0000001127125108_p488582345212"></a>仅手机和平板设备支持。</p>
</div></div>
</td>
</tr>
</tbody>
</table>

日期时间选择器：type=datetime，日期的选择范围为本年的日月。

<a name="zh-cn_topic_0000001127125108_table1188511392120"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001127125108_row16886193915128"><th class="cellrowborder" valign="top" width="24.000000000000004%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001127125108_p58868399129"><a name="zh-cn_topic_0000001127125108_p58868399129"></a><a name="zh-cn_topic_0000001127125108_p58868399129"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="10.810000000000002%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001127125108_p19886739161213"><a name="zh-cn_topic_0000001127125108_p19886739161213"></a><a name="zh-cn_topic_0000001127125108_p19886739161213"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="8.63%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001127125108_p138864393128"><a name="zh-cn_topic_0000001127125108_p138864393128"></a><a name="zh-cn_topic_0000001127125108_p138864393128"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.15%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001127125108_p288653914122"><a name="zh-cn_topic_0000001127125108_p288653914122"></a><a name="zh-cn_topic_0000001127125108_p288653914122"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="49.410000000000004%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001127125108_p1886193931212"><a name="zh-cn_topic_0000001127125108_p1886193931212"></a><a name="zh-cn_topic_0000001127125108_p1886193931212"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001127125108_row288753919128"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125108_p20887539141215"><a name="zh-cn_topic_0000001127125108_p20887539141215"></a><a name="zh-cn_topic_0000001127125108_p20887539141215"></a>selected</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125108_p788753910126"><a name="zh-cn_topic_0000001127125108_p788753910126"></a><a name="zh-cn_topic_0000001127125108_p788753910126"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125108_p16887539111214"><a name="zh-cn_topic_0000001127125108_p16887539111214"></a><a name="zh-cn_topic_0000001127125108_p16887539111214"></a>当前日期时间</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125108_p4887203911129"><a name="zh-cn_topic_0000001127125108_p4887203911129"></a><a name="zh-cn_topic_0000001127125108_p4887203911129"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125108_p33848571013"><a name="zh-cn_topic_0000001127125108_p33848571013"></a><a name="zh-cn_topic_0000001127125108_p33848571013"></a>设置日期时间选择器的默认取值，格式有两种，为月日时分MM-DD-HH-mm或者年月日时分YYYY-MM-DD-HH-mm，不设置年时，默认使用当前年，该取值表示选择器弹窗时弹窗界面的默认选择值。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125108_row25569188246"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125108_p7249338141710"><a name="zh-cn_topic_0000001127125108_p7249338141710"></a><a name="zh-cn_topic_0000001127125108_p7249338141710"></a>hours</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125108_p1814251913247"><a name="zh-cn_topic_0000001127125108_p1814251913247"></a><a name="zh-cn_topic_0000001127125108_p1814251913247"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125108_p51424195244"><a name="zh-cn_topic_0000001127125108_p51424195244"></a><a name="zh-cn_topic_0000001127125108_p51424195244"></a>24<sup id="zh-cn_topic_0000001127125108_sup1626816180414"><a name="zh-cn_topic_0000001127125108_sup1626816180414"></a><a name="zh-cn_topic_0000001127125108_sup1626816180414"></a>1-4</sup></p>
<p id="zh-cn_topic_0000001127125108_p52731028173117"><a name="zh-cn_topic_0000001127125108_p52731028173117"></a><a name="zh-cn_topic_0000001127125108_p52731028173117"></a>-<sup id="zh-cn_topic_0000001127125108_sup627311285313"><a name="zh-cn_topic_0000001127125108_sup627311285313"></a><a name="zh-cn_topic_0000001127125108_sup627311285313"></a><span>5+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125108_p171426196242"><a name="zh-cn_topic_0000001127125108_p171426196242"></a><a name="zh-cn_topic_0000001127125108_p171426196242"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125108_p1314251932418"><a name="zh-cn_topic_0000001127125108_p1314251932418"></a><a name="zh-cn_topic_0000001127125108_p1314251932418"></a>设置日期时间选择器采用的时间格式，可选值：</p>
<a name="zh-cn_topic_0000001127125108_ul15923173119204"></a><a name="zh-cn_topic_0000001127125108_ul15923173119204"></a><ul id="zh-cn_topic_0000001127125108_ul15923173119204"><li>12：按照12小时制显示，用上午和下午进行区分；</li><li>24：按照24小时制显示。<div class="note" id="zh-cn_topic_0000001127125108_note1880145011113"><a name="zh-cn_topic_0000001127125108_note1880145011113"></a><a name="zh-cn_topic_0000001127125108_note1880145011113"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001127125108_p1988165031111"><a name="zh-cn_topic_0000001127125108_p1988165031111"></a><a name="zh-cn_topic_0000001127125108_p1988165031111"></a>默认值会依据系统当前所选地区和语言选择当地习惯的小时制(12小时制或24小时制)。<sup id="zh-cn_topic_0000001127125108_sup11183114910314"><a name="zh-cn_topic_0000001127125108_sup11183114910314"></a><a name="zh-cn_topic_0000001127125108_sup11183114910314"></a><span>5+</span></sup></p>
</div></div>
</li></ul>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125108_row1742363212240"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125108_p1820281519182"><a name="zh-cn_topic_0000001127125108_p1820281519182"></a><a name="zh-cn_topic_0000001127125108_p1820281519182"></a>lunar<sup id="zh-cn_topic_0000001127125108_sup370711541116"><a name="zh-cn_topic_0000001127125108_sup370711541116"></a><a name="zh-cn_topic_0000001127125108_sup370711541116"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125108_p9202131571819"><a name="zh-cn_topic_0000001127125108_p9202131571819"></a><a name="zh-cn_topic_0000001127125108_p9202131571819"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125108_p520313152182"><a name="zh-cn_topic_0000001127125108_p520313152182"></a><a name="zh-cn_topic_0000001127125108_p520313152182"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125108_p142031715201812"><a name="zh-cn_topic_0000001127125108_p142031715201812"></a><a name="zh-cn_topic_0000001127125108_p142031715201812"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125108_p16203181541812"><a name="zh-cn_topic_0000001127125108_p16203181541812"></a><a name="zh-cn_topic_0000001127125108_p16203181541812"></a>设置日期时间选择器弹窗界面是否为农历展示。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125108_row34576125180"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125108_p120351520182"><a name="zh-cn_topic_0000001127125108_p120351520182"></a><a name="zh-cn_topic_0000001127125108_p120351520182"></a>lunarswitch</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125108_p5203415171819"><a name="zh-cn_topic_0000001127125108_p5203415171819"></a><a name="zh-cn_topic_0000001127125108_p5203415171819"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125108_p120317151181"><a name="zh-cn_topic_0000001127125108_p120317151181"></a><a name="zh-cn_topic_0000001127125108_p120317151181"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125108_p16203115101819"><a name="zh-cn_topic_0000001127125108_p16203115101819"></a><a name="zh-cn_topic_0000001127125108_p16203115101819"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125108_p12203111510184"><a name="zh-cn_topic_0000001127125108_p12203111510184"></a><a name="zh-cn_topic_0000001127125108_p12203111510184"></a>设置日期时间选择器是否显示农历开关，显示农历开关时，可以在弹窗界面展现农历的开关由于公历和农历切换。在设置显示农历时，开关状态为开，当设置不显示农历时，开关状态为关。手机生效。</p>
<div class="note" id="zh-cn_topic_0000001127125108_note11541837195218"><a name="zh-cn_topic_0000001127125108_note11541837195218"></a><a name="zh-cn_topic_0000001127125108_note11541837195218"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001127125108_p454119371529"><a name="zh-cn_topic_0000001127125108_p454119371529"></a><a name="zh-cn_topic_0000001127125108_p454119371529"></a>仅手机和平板设备支持。</p>
</div></div>
</td>
</tr>
</tbody>
</table>

多列文本选择器：type=multi-text

<a name="zh-cn_topic_0000001127125108_table1886619321772"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001127125108_row198671332179"><th class="cellrowborder" valign="top" width="24.000000000000004%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001127125108_p168677321871"><a name="zh-cn_topic_0000001127125108_p168677321871"></a><a name="zh-cn_topic_0000001127125108_p168677321871"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="10.810000000000002%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001127125108_p38670322711"><a name="zh-cn_topic_0000001127125108_p38670322711"></a><a name="zh-cn_topic_0000001127125108_p38670322711"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="8.63%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001127125108_p178670321276"><a name="zh-cn_topic_0000001127125108_p178670321276"></a><a name="zh-cn_topic_0000001127125108_p178670321276"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.15%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001127125108_p9867183215719"><a name="zh-cn_topic_0000001127125108_p9867183215719"></a><a name="zh-cn_topic_0000001127125108_p9867183215719"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="49.410000000000004%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001127125108_p168671324711"><a name="zh-cn_topic_0000001127125108_p168671324711"></a><a name="zh-cn_topic_0000001127125108_p168671324711"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001127125108_row3757154961319"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125108_p12757204951314"><a name="zh-cn_topic_0000001127125108_p12757204951314"></a><a name="zh-cn_topic_0000001127125108_p12757204951314"></a>columns</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125108_p13757124918137"><a name="zh-cn_topic_0000001127125108_p13757124918137"></a><a name="zh-cn_topic_0000001127125108_p13757124918137"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125108_p0757144914132"><a name="zh-cn_topic_0000001127125108_p0757144914132"></a><a name="zh-cn_topic_0000001127125108_p0757144914132"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125108_p14757149111317"><a name="zh-cn_topic_0000001127125108_p14757149111317"></a><a name="zh-cn_topic_0000001127125108_p14757149111317"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125108_p1675884931313"><a name="zh-cn_topic_0000001127125108_p1675884931313"></a><a name="zh-cn_topic_0000001127125108_p1675884931313"></a>设置多列文本选择器的列数。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125108_row3867103214710"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125108_p793074416717"><a name="zh-cn_topic_0000001127125108_p793074416717"></a><a name="zh-cn_topic_0000001127125108_p793074416717"></a>range</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125108_p793010441976"><a name="zh-cn_topic_0000001127125108_p793010441976"></a><a name="zh-cn_topic_0000001127125108_p793010441976"></a>二维Array</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125108_p7930174418712"><a name="zh-cn_topic_0000001127125108_p7930174418712"></a><a name="zh-cn_topic_0000001127125108_p7930174418712"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125108_p2930444971"><a name="zh-cn_topic_0000001127125108_p2930444971"></a><a name="zh-cn_topic_0000001127125108_p2930444971"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125108_p139301644675"><a name="zh-cn_topic_0000001127125108_p139301644675"></a><a name="zh-cn_topic_0000001127125108_p139301644675"></a>设置多列文本选择器的选择值，该值为二维数组。长度表示多少列，数组的每项表示每列的数据，如  [["a","b"], ["c","d"]]。</p>
<div class="note" id="zh-cn_topic_0000001127125108_note112201642121219"><a name="zh-cn_topic_0000001127125108_note112201642121219"></a><a name="zh-cn_topic_0000001127125108_note112201642121219"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001127125108_p8220114221212"><a name="zh-cn_topic_0000001127125108_p8220114221212"></a><a name="zh-cn_topic_0000001127125108_p8220114221212"></a>使用时需要使用数据绑定的方式，如range = {{data}}，js中声明相应变量：data：[["a","b"], ["c","d"]]。</p>
</div></div>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125108_row18671332572"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125108_p693016441273"><a name="zh-cn_topic_0000001127125108_p693016441273"></a><a name="zh-cn_topic_0000001127125108_p693016441273"></a>selected</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125108_p159306448720"><a name="zh-cn_topic_0000001127125108_p159306448720"></a><a name="zh-cn_topic_0000001127125108_p159306448720"></a>Array</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125108_p18930544471"><a name="zh-cn_topic_0000001127125108_p18930544471"></a><a name="zh-cn_topic_0000001127125108_p18930544471"></a>[0,0,0,…]</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125108_p69305448719"><a name="zh-cn_topic_0000001127125108_p69305448719"></a><a name="zh-cn_topic_0000001127125108_p69305448719"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125108_p12930144373"><a name="zh-cn_topic_0000001127125108_p12930144373"></a><a name="zh-cn_topic_0000001127125108_p12930144373"></a>设置多列文本选择器的默认值，每一列被选中项对应的索引构成的数组，该取值表示选择器弹窗时弹窗界面的默认选择值。</p>
</td>
</tr>
</tbody>
</table>

## 样式<a name="zh-cn_topic_0000001127125108_section198061172344"></a>

除支持[通用样式](js-components-common-styles.md#ZH-CN_TOPIC_0000001163932190)外，还支持如下样式：

<a name="zh-cn_topic_0000001127125108_table94919235408"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001127125108_row1349111237406"><th class="cellrowborder" valign="top" width="23.11768823117688%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001127125108_p13491122316409"><a name="zh-cn_topic_0000001127125108_p13491122316409"></a><a name="zh-cn_topic_0000001127125108_p13491122316409"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="20.477952204779523%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001127125108_p649192317408"><a name="zh-cn_topic_0000001127125108_p649192317408"></a><a name="zh-cn_topic_0000001127125108_p649192317408"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="10.47895210478952%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001127125108_p1849162384015"><a name="zh-cn_topic_0000001127125108_p1849162384015"></a><a name="zh-cn_topic_0000001127125108_p1849162384015"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="5.909409059094091%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001127125108_p449162318408"><a name="zh-cn_topic_0000001127125108_p449162318408"></a><a name="zh-cn_topic_0000001127125108_p449162318408"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="40.01599840015999%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001127125108_p12491102344016"><a name="zh-cn_topic_0000001127125108_p12491102344016"></a><a name="zh-cn_topic_0000001127125108_p12491102344016"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001127125108_row114923234409"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125108_p1849262316408"><a name="zh-cn_topic_0000001127125108_p1849262316408"></a><a name="zh-cn_topic_0000001127125108_p1849262316408"></a>color</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125108_p1249252318405"><a name="zh-cn_topic_0000001127125108_p1249252318405"></a><a name="zh-cn_topic_0000001127125108_p1249252318405"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.47895210478952%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125108_p9492162315401"><a name="zh-cn_topic_0000001127125108_p9492162315401"></a><a name="zh-cn_topic_0000001127125108_p9492162315401"></a>#ffffff</p>
</td>
<td class="cellrowborder" valign="top" width="5.909409059094091%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125108_p134923233404"><a name="zh-cn_topic_0000001127125108_p134923233404"></a><a name="zh-cn_topic_0000001127125108_p134923233404"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125108_p84926239401"><a name="zh-cn_topic_0000001127125108_p84926239401"></a><a name="zh-cn_topic_0000001127125108_p84926239401"></a>候选项字体颜色。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125108_row1249232316406"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125108_p14492122354013"><a name="zh-cn_topic_0000001127125108_p14492122354013"></a><a name="zh-cn_topic_0000001127125108_p14492122354013"></a>font-size</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125108_p249222310403"><a name="zh-cn_topic_0000001127125108_p249222310403"></a><a name="zh-cn_topic_0000001127125108_p249222310403"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.47895210478952%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125108_p1149212231402"><a name="zh-cn_topic_0000001127125108_p1149212231402"></a><a name="zh-cn_topic_0000001127125108_p1149212231402"></a>16px</p>
</td>
<td class="cellrowborder" valign="top" width="5.909409059094091%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125108_p1849282317409"><a name="zh-cn_topic_0000001127125108_p1849282317409"></a><a name="zh-cn_topic_0000001127125108_p1849282317409"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125108_p19492112316406"><a name="zh-cn_topic_0000001127125108_p19492112316406"></a><a name="zh-cn_topic_0000001127125108_p19492112316406"></a>候选项字体尺寸，类型length，单位px。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125108_row1249262314017"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125108_p54925236401"><a name="zh-cn_topic_0000001127125108_p54925236401"></a><a name="zh-cn_topic_0000001127125108_p54925236401"></a>selected-color</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125108_p449219234408"><a name="zh-cn_topic_0000001127125108_p449219234408"></a><a name="zh-cn_topic_0000001127125108_p449219234408"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.47895210478952%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125108_p54924238408"><a name="zh-cn_topic_0000001127125108_p54924238408"></a><a name="zh-cn_topic_0000001127125108_p54924238408"></a>#ff0a69f7</p>
</td>
<td class="cellrowborder" valign="top" width="5.909409059094091%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125108_p949242334013"><a name="zh-cn_topic_0000001127125108_p949242334013"></a><a name="zh-cn_topic_0000001127125108_p949242334013"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125108_p20492152334010"><a name="zh-cn_topic_0000001127125108_p20492152334010"></a><a name="zh-cn_topic_0000001127125108_p20492152334010"></a>选中项字体颜色。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125108_row10492423134013"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125108_p174938237409"><a name="zh-cn_topic_0000001127125108_p174938237409"></a><a name="zh-cn_topic_0000001127125108_p174938237409"></a>selected-font-size</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125108_p9493182314010"><a name="zh-cn_topic_0000001127125108_p9493182314010"></a><a name="zh-cn_topic_0000001127125108_p9493182314010"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.47895210478952%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125108_p16493223104019"><a name="zh-cn_topic_0000001127125108_p16493223104019"></a><a name="zh-cn_topic_0000001127125108_p16493223104019"></a>20px</p>
</td>
<td class="cellrowborder" valign="top" width="5.909409059094091%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125108_p74931223124013"><a name="zh-cn_topic_0000001127125108_p74931223124013"></a><a name="zh-cn_topic_0000001127125108_p74931223124013"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125108_p449342311407"><a name="zh-cn_topic_0000001127125108_p449342311407"></a><a name="zh-cn_topic_0000001127125108_p449342311407"></a>选中项字体尺寸，类型length，单位px。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125108_row84941623134017"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125108_p104941323114011"><a name="zh-cn_topic_0000001127125108_p104941323114011"></a><a name="zh-cn_topic_0000001127125108_p104941323114011"></a>disappear-color<sup id="zh-cn_topic_0000001127125108_sup54941523144015"><a name="zh-cn_topic_0000001127125108_sup54941523144015"></a><a name="zh-cn_topic_0000001127125108_sup54941523144015"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125108_p349412319400"><a name="zh-cn_topic_0000001127125108_p349412319400"></a><a name="zh-cn_topic_0000001127125108_p349412319400"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.47895210478952%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125108_p14942236409"><a name="zh-cn_topic_0000001127125108_p14942236409"></a><a name="zh-cn_topic_0000001127125108_p14942236409"></a>#ffffff</p>
</td>
<td class="cellrowborder" valign="top" width="5.909409059094091%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125108_p10494123164013"><a name="zh-cn_topic_0000001127125108_p10494123164013"></a><a name="zh-cn_topic_0000001127125108_p10494123164013"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125108_p20494323144012"><a name="zh-cn_topic_0000001127125108_p20494323144012"></a><a name="zh-cn_topic_0000001127125108_p20494323144012"></a>渐变消失项的字体颜色。消失项是在一列中有五个选项场景下最上和最下的两个选项。</p>
<div class="note" id="zh-cn_topic_0000001127125108_note682125718522"><a name="zh-cn_topic_0000001127125108_note682125718522"></a><a name="zh-cn_topic_0000001127125108_note682125718522"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001127125108_p17821185711521"><a name="zh-cn_topic_0000001127125108_p17821185711521"></a><a name="zh-cn_topic_0000001127125108_p17821185711521"></a>仅手机和平板设备支持。</p>
</div></div>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125108_row1949432318405"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125108_p1549419237407"><a name="zh-cn_topic_0000001127125108_p1549419237407"></a><a name="zh-cn_topic_0000001127125108_p1549419237407"></a>disappear-font-size<sup id="zh-cn_topic_0000001127125108_sup0494132313404"><a name="zh-cn_topic_0000001127125108_sup0494132313404"></a><a name="zh-cn_topic_0000001127125108_sup0494132313404"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125108_p144940238404"><a name="zh-cn_topic_0000001127125108_p144940238404"></a><a name="zh-cn_topic_0000001127125108_p144940238404"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.47895210478952%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125108_p64941023194020"><a name="zh-cn_topic_0000001127125108_p64941023194020"></a><a name="zh-cn_topic_0000001127125108_p64941023194020"></a>14px</p>
</td>
<td class="cellrowborder" valign="top" width="5.909409059094091%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125108_p1949522364020"><a name="zh-cn_topic_0000001127125108_p1949522364020"></a><a name="zh-cn_topic_0000001127125108_p1949522364020"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125108_p1549532364020"><a name="zh-cn_topic_0000001127125108_p1549532364020"></a><a name="zh-cn_topic_0000001127125108_p1549532364020"></a>渐变消失项的字体尺寸。消失项是在一列中有五个选项场景下最上和最下的两个选项。</p>
<div class="note" id="zh-cn_topic_0000001127125108_note17211975317"><a name="zh-cn_topic_0000001127125108_note17211975317"></a><a name="zh-cn_topic_0000001127125108_note17211975317"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001127125108_p1821895535"><a name="zh-cn_topic_0000001127125108_p1821895535"></a><a name="zh-cn_topic_0000001127125108_p1821895535"></a>仅手机和平板设备支持。</p>
</div></div>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125108_row19495152311405"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125108_p154951237400"><a name="zh-cn_topic_0000001127125108_p154951237400"></a><a name="zh-cn_topic_0000001127125108_p154951237400"></a>font-family</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125108_p3495192316402"><a name="zh-cn_topic_0000001127125108_p3495192316402"></a><a name="zh-cn_topic_0000001127125108_p3495192316402"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.47895210478952%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125108_p8495172324010"><a name="zh-cn_topic_0000001127125108_p8495172324010"></a><a name="zh-cn_topic_0000001127125108_p8495172324010"></a>sans-serif</p>
</td>
<td class="cellrowborder" valign="top" width="5.909409059094091%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125108_p134951723154010"><a name="zh-cn_topic_0000001127125108_p134951723154010"></a><a name="zh-cn_topic_0000001127125108_p134951723154010"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125108_p124957233408"><a name="zh-cn_topic_0000001127125108_p124957233408"></a><a name="zh-cn_topic_0000001127125108_p124957233408"></a>选项字体类型。字体列表，用逗号分隔，每个字体用字体名或者字体族名设置。列表中第一个系统中存在的或者通过<a href="js-components-common-customizing-font.md#ZH-CN_TOPIC_0000001163812210">自定义字体</a>指定的字体，会被选中作为文本的字体。</p>
</td>
</tr>
</tbody>
</table>

## 事件<a name="zh-cn_topic_0000001127125108_section103398253399"></a>

仅支持如下事件：

type=text：

<a name="zh-cn_topic_0000001127125108_table17339225123915"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001127125108_row1339925143920"><th class="cellrowborder" valign="top" width="16.16161616161616%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001127125108_p8340925103911"><a name="zh-cn_topic_0000001127125108_p8340925103911"></a><a name="zh-cn_topic_0000001127125108_p8340925103911"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="41.41414141414141%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001127125108_p2340325113912"><a name="zh-cn_topic_0000001127125108_p2340325113912"></a><a name="zh-cn_topic_0000001127125108_p2340325113912"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="42.42424242424242%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001127125108_p1534013255394"><a name="zh-cn_topic_0000001127125108_p1534013255394"></a><a name="zh-cn_topic_0000001127125108_p1534013255394"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001127125108_row15340192543910"><td class="cellrowborder" valign="top" width="16.16161616161616%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001127125108_p334016258395"><a name="zh-cn_topic_0000001127125108_p334016258395"></a><a name="zh-cn_topic_0000001127125108_p334016258395"></a>change</p>
</td>
<td class="cellrowborder" valign="top" width="41.41414141414141%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001127125108_p93401725183918"><a name="zh-cn_topic_0000001127125108_p93401725183918"></a><a name="zh-cn_topic_0000001127125108_p93401725183918"></a>{ newValue: newValue, newSelected: newSelected }</p>
</td>
<td class="cellrowborder" valign="top" width="42.42424242424242%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001127125108_p17340122515397"><a name="zh-cn_topic_0000001127125108_p17340122515397"></a><a name="zh-cn_topic_0000001127125108_p17340122515397"></a>文本选择器选定值后触发该事件。</p>
</td>
</tr>
</tbody>
</table>

type=time：

<a name="zh-cn_topic_0000001127125108_table13340325133918"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001127125108_row20340125143918"><th class="cellrowborder" valign="top" width="16.16161616161616%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001127125108_p14340152533917"><a name="zh-cn_topic_0000001127125108_p14340152533917"></a><a name="zh-cn_topic_0000001127125108_p14340152533917"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="41.41414141414141%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001127125108_p1634082553920"><a name="zh-cn_topic_0000001127125108_p1634082553920"></a><a name="zh-cn_topic_0000001127125108_p1634082553920"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="42.42424242424242%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001127125108_p134072523914"><a name="zh-cn_topic_0000001127125108_p134072523914"></a><a name="zh-cn_topic_0000001127125108_p134072523914"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001127125108_row1434032553920"><td class="cellrowborder" valign="top" width="16.16161616161616%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001127125108_p3341625183910"><a name="zh-cn_topic_0000001127125108_p3341625183910"></a><a name="zh-cn_topic_0000001127125108_p3341625183910"></a>change</p>
</td>
<td class="cellrowborder" valign="top" width="41.41414141414141%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001127125108_p1634122513911"><a name="zh-cn_topic_0000001127125108_p1634122513911"></a><a name="zh-cn_topic_0000001127125108_p1634122513911"></a>{ hour: hour, minute: minute<span id="zh-cn_topic_0000001127125108_ph734120255396"><a name="zh-cn_topic_0000001127125108_ph734120255396"></a><a name="zh-cn_topic_0000001127125108_ph734120255396"></a>, [second:second] </span>}</p>
</td>
<td class="cellrowborder" valign="top" width="42.42424242424242%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001127125108_p4341225133916"><a name="zh-cn_topic_0000001127125108_p4341225133916"></a><a name="zh-cn_topic_0000001127125108_p4341225133916"></a>时间选择器选定值后触发该事件。</p>
<p id="zh-cn_topic_0000001127125108_p1341192514397"><a name="zh-cn_topic_0000001127125108_p1341192514397"></a><a name="zh-cn_topic_0000001127125108_p1341192514397"></a>包含秒时，返回时分秒。</p>
</td>
</tr>
</tbody>
</table>

type=date：

<a name="zh-cn_topic_0000001127125108_table103414254397"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001127125108_row234142553912"><th class="cellrowborder" valign="top" width="15.370000000000001%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001127125108_p7341125153916"><a name="zh-cn_topic_0000001127125108_p7341125153916"></a><a name="zh-cn_topic_0000001127125108_p7341125153916"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="34.22%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001127125108_p1834182593915"><a name="zh-cn_topic_0000001127125108_p1834182593915"></a><a name="zh-cn_topic_0000001127125108_p1834182593915"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="50.41%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001127125108_p5341142593910"><a name="zh-cn_topic_0000001127125108_p5341142593910"></a><a name="zh-cn_topic_0000001127125108_p5341142593910"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001127125108_row83411325103912"><td class="cellrowborder" valign="top" width="15.370000000000001%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001127125108_p6341122553914"><a name="zh-cn_topic_0000001127125108_p6341122553914"></a><a name="zh-cn_topic_0000001127125108_p6341122553914"></a>change</p>
</td>
<td class="cellrowborder" valign="top" width="34.22%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001127125108_p17341192563911"><a name="zh-cn_topic_0000001127125108_p17341192563911"></a><a name="zh-cn_topic_0000001127125108_p17341192563911"></a>{ year:year, month:month, day:day }</p>
</td>
<td class="cellrowborder" valign="top" width="50.41%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001127125108_p103419259392"><a name="zh-cn_topic_0000001127125108_p103419259392"></a><a name="zh-cn_topic_0000001127125108_p103419259392"></a>日期选择器选择值后触发该事件。</p>
</td>
</tr>
</tbody>
</table>

type=datetime：

<a name="zh-cn_topic_0000001127125108_table6342192514395"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001127125108_row43421725183919"><th class="cellrowborder" valign="top" width="15.370000000000001%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001127125108_p17342325173911"><a name="zh-cn_topic_0000001127125108_p17342325173911"></a><a name="zh-cn_topic_0000001127125108_p17342325173911"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="34.22%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001127125108_p63421825113915"><a name="zh-cn_topic_0000001127125108_p63421825113915"></a><a name="zh-cn_topic_0000001127125108_p63421825113915"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="50.41%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001127125108_p634217257395"><a name="zh-cn_topic_0000001127125108_p634217257395"></a><a name="zh-cn_topic_0000001127125108_p634217257395"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001127125108_row1234216257392"><td class="cellrowborder" valign="top" width="15.370000000000001%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001127125108_p5342725203916"><a name="zh-cn_topic_0000001127125108_p5342725203916"></a><a name="zh-cn_topic_0000001127125108_p5342725203916"></a>change</p>
</td>
<td class="cellrowborder" valign="top" width="34.22%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001127125108_p20342132512395"><a name="zh-cn_topic_0000001127125108_p20342132512395"></a><a name="zh-cn_topic_0000001127125108_p20342132512395"></a>{ year:year, month:month, day:day,  hour:hour, minute:minute }</p>
</td>
<td class="cellrowborder" valign="top" width="50.41%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001127125108_p11342102563910"><a name="zh-cn_topic_0000001127125108_p11342102563910"></a><a name="zh-cn_topic_0000001127125108_p11342102563910"></a>日期时间选择器选择值后触发该事件。</p>
</td>
</tr>
</tbody>
</table>

type=multi-text：

<a name="zh-cn_topic_0000001127125108_table5342325203913"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001127125108_row153422255390"><th class="cellrowborder" valign="top" width="13.969999999999999%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001127125108_p153431725153916"><a name="zh-cn_topic_0000001127125108_p153431725153916"></a><a name="zh-cn_topic_0000001127125108_p153431725153916"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="36.9%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001127125108_p11343102523916"><a name="zh-cn_topic_0000001127125108_p11343102523916"></a><a name="zh-cn_topic_0000001127125108_p11343102523916"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="49.13%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001127125108_p16343925193913"><a name="zh-cn_topic_0000001127125108_p16343925193913"></a><a name="zh-cn_topic_0000001127125108_p16343925193913"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001127125108_row103430256392"><td class="cellrowborder" valign="top" width="13.969999999999999%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001127125108_p19343122514399"><a name="zh-cn_topic_0000001127125108_p19343122514399"></a><a name="zh-cn_topic_0000001127125108_p19343122514399"></a>columnchange</p>
</td>
<td class="cellrowborder" valign="top" width="36.9%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001127125108_p12343102573913"><a name="zh-cn_topic_0000001127125108_p12343102573913"></a><a name="zh-cn_topic_0000001127125108_p12343102573913"></a>{ column:column, newValue:newValue, newSelected:newSelected }</p>
</td>
<td class="cellrowborder" valign="top" width="49.13%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001127125108_p1534352593917"><a name="zh-cn_topic_0000001127125108_p1534352593917"></a><a name="zh-cn_topic_0000001127125108_p1534352593917"></a>多列文本选择器某一列的值改变时触发该事件，column：第几列修改，newValue：选中的值，newSelected：选中值对应的索引。</p>
</td>
</tr>
</tbody>
</table>

## 方法<a name="zh-cn_topic_0000001127125108_section718304515396"></a>

不支持。

## 示例<a name="zh-cn_topic_0000001127125108_section738534695417"></a>

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

