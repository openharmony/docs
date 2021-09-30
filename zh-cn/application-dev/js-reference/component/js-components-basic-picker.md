# picker<a name="ZH-CN_TOPIC_0000001164130766"></a>

-   [权限列表](#zh-cn_topic_0000001173324637_section11257113618419)
-   [子组件](#zh-cn_topic_0000001173324637_section9288143101012)
-   [属性](#zh-cn_topic_0000001173324637_section2907183951110)
-   [样式](#zh-cn_topic_0000001173324637_section1299175511712)
-   [事件](#zh-cn_topic_0000001173324637_section1724215114357)
-   [方法](#zh-cn_topic_0000001173324637_section47669296127)
-   [示例](#zh-cn_topic_0000001173324637_section11956342165513)

滑动选择器组件，类型支持普通选择器、日期选择器、时间选择器、时间日期选择器和多列文本选择器。

## 权限列表<a name="zh-cn_topic_0000001173324637_section11257113618419"></a>

无

## 子组件<a name="zh-cn_topic_0000001173324637_section9288143101012"></a>

不支持。

## 属性<a name="zh-cn_topic_0000001173324637_section2907183951110"></a>

除支持[通用属性](js-components-common-attributes.md#ZH-CN_TOPIC_0000001163812208)外，还支持如下属性：↵

<a name="zh-cn_topic_0000001173324637_table20633101642315"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001173324637_row663331618238"><th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001173324637_aa872998ac2d84843a3c5161889afffef"><a name="zh-cn_topic_0000001173324637_aa872998ac2d84843a3c5161889afffef"></a><a name="zh-cn_topic_0000001173324637_aa872998ac2d84843a3c5161889afffef"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001173324637_ab2111648ee0e4f6d881be8954e7acaab"><a name="zh-cn_topic_0000001173324637_ab2111648ee0e4f6d881be8954e7acaab"></a><a name="zh-cn_topic_0000001173324637_ab2111648ee0e4f6d881be8954e7acaab"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="10.48%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001173324637_ab377d1c90900478ea4ecab51e9a058af"><a name="zh-cn_topic_0000001173324637_ab377d1c90900478ea4ecab51e9a058af"></a><a name="zh-cn_topic_0000001173324637_ab377d1c90900478ea4ecab51e9a058af"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.46%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001173324637_p824610360217"><a name="zh-cn_topic_0000001173324637_p824610360217"></a><a name="zh-cn_topic_0000001173324637_p824610360217"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="35.82%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001173324637_a1d574a0044ed42ec8a2603bc82734232"><a name="zh-cn_topic_0000001173324637_a1d574a0044ed42ec8a2603bc82734232"></a><a name="zh-cn_topic_0000001173324637_a1d574a0044ed42ec8a2603bc82734232"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001173324637_row297418523612"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324637_p1292865313615"><a name="zh-cn_topic_0000001173324637_p1292865313615"></a><a name="zh-cn_topic_0000001173324637_p1292865313615"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324637_p1092810536617"><a name="zh-cn_topic_0000001173324637_p1092810536617"></a><a name="zh-cn_topic_0000001173324637_p1092810536617"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324637_p192818533612"><a name="zh-cn_topic_0000001173324637_p192818533612"></a><a name="zh-cn_topic_0000001173324637_p192818533612"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.46%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324637_p492817531269"><a name="zh-cn_topic_0000001173324637_p492817531269"></a><a name="zh-cn_topic_0000001173324637_p492817531269"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.82%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324637_p99287536614"><a name="zh-cn_topic_0000001173324637_p99287536614"></a><a name="zh-cn_topic_0000001173324637_p99287536614"></a>该属性值不支持动态修改。可选择项有：</p>
<a name="zh-cn_topic_0000001173324637_ul17928553367"></a><a name="zh-cn_topic_0000001173324637_ul17928553367"></a><ul id="zh-cn_topic_0000001173324637_ul17928553367"><li>text：文本选择器。</li><li>date：日期选择器。</li><li>time：时间选择器。</li><li>datetime：日期时间选择器。</li><li>multi-text：多列文本选择器。</li></ul>
</td>
</tr>
</tbody>
</table>

普通选择器：type=text

<a name="zh-cn_topic_0000001173324637_ta708bd4856a044b79bae50a2ce6981b8"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001173324637_re08662644cee4140ad0d5bac7978cd9b"><th class="cellrowborder" valign="top" width="24.000000000000004%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001173324637_af5b093e471ec47119f04bf2fe91b6f64"><a name="zh-cn_topic_0000001173324637_af5b093e471ec47119f04bf2fe91b6f64"></a><a name="zh-cn_topic_0000001173324637_af5b093e471ec47119f04bf2fe91b6f64"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="10.810000000000002%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001173324637_a8c2c2f6a645749b7852ec7dcadaca702"><a name="zh-cn_topic_0000001173324637_a8c2c2f6a645749b7852ec7dcadaca702"></a><a name="zh-cn_topic_0000001173324637_a8c2c2f6a645749b7852ec7dcadaca702"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="8.63%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001173324637_aa63c3dd750aa44fb9ec9031e632f4f5f"><a name="zh-cn_topic_0000001173324637_aa63c3dd750aa44fb9ec9031e632f4f5f"></a><a name="zh-cn_topic_0000001173324637_aa63c3dd750aa44fb9ec9031e632f4f5f"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.850000000000001%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001173324637_aee9661e3366543aeac6aa37e48de4c87"><a name="zh-cn_topic_0000001173324637_aee9661e3366543aeac6aa37e48de4c87"></a><a name="zh-cn_topic_0000001173324637_aee9661e3366543aeac6aa37e48de4c87"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="48.71%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001173324637_a2dc04c78fce4402d9dead84ab8412bb3"><a name="zh-cn_topic_0000001173324637_a2dc04c78fce4402d9dead84ab8412bb3"></a><a name="zh-cn_topic_0000001173324637_a2dc04c78fce4402d9dead84ab8412bb3"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001173324637_re8122915226c4596b2bffeae21e37b10"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324637_p64901432865"><a name="zh-cn_topic_0000001173324637_p64901432865"></a><a name="zh-cn_topic_0000001173324637_p64901432865"></a>range</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324637_p194901326610"><a name="zh-cn_topic_0000001173324637_p194901326610"></a><a name="zh-cn_topic_0000001173324637_p194901326610"></a>Array</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324637_p16490183216616"><a name="zh-cn_topic_0000001173324637_p16490183216616"></a><a name="zh-cn_topic_0000001173324637_p16490183216616"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.850000000000001%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324637_p12490132765"><a name="zh-cn_topic_0000001173324637_p12490132765"></a><a name="zh-cn_topic_0000001173324637_p12490132765"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="48.71%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324637_p14907328610"><a name="zh-cn_topic_0000001173324637_p14907328610"></a><a name="zh-cn_topic_0000001173324637_p14907328610"></a>设置普通选择器的取值范围，如["15", "20", "25"]。</p>
<div class="note" id="zh-cn_topic_0000001173324637_note4860842141115"><a name="zh-cn_topic_0000001173324637_note4860842141115"></a><a name="zh-cn_topic_0000001173324637_note4860842141115"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001173324637_p1386074271117"><a name="zh-cn_topic_0000001173324637_p1386074271117"></a><a name="zh-cn_topic_0000001173324637_p1386074271117"></a>使用时需要使用数据绑定的方式，如range = {{data}}，js中声明相应变量：data：["15", "20", "25"]。</p>
</div></div>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324637_row2068183074711"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324637_p54902321765"><a name="zh-cn_topic_0000001173324637_p54902321765"></a><a name="zh-cn_topic_0000001173324637_p54902321765"></a>selected</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324637_p24901321469"><a name="zh-cn_topic_0000001173324637_p24901321469"></a><a name="zh-cn_topic_0000001173324637_p24901321469"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324637_p14901932863"><a name="zh-cn_topic_0000001173324637_p14901932863"></a><a name="zh-cn_topic_0000001173324637_p14901932863"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.850000000000001%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324637_p1049018321869"><a name="zh-cn_topic_0000001173324637_p1049018321869"></a><a name="zh-cn_topic_0000001173324637_p1049018321869"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="48.71%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324637_p649017329613"><a name="zh-cn_topic_0000001173324637_p649017329613"></a><a name="zh-cn_topic_0000001173324637_p649017329613"></a>设置普通选择器弹窗的默认取值，取值需要是 range 的索引值，该取值表示选择器弹窗时弹窗界面的默认选择值。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324637_row8381203074710"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324637_p1349019328615"><a name="zh-cn_topic_0000001173324637_p1349019328615"></a><a name="zh-cn_topic_0000001173324637_p1349019328615"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324637_p114903324614"><a name="zh-cn_topic_0000001173324637_p114903324614"></a><a name="zh-cn_topic_0000001173324637_p114903324614"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324637_p34909328614"><a name="zh-cn_topic_0000001173324637_p34909328614"></a><a name="zh-cn_topic_0000001173324637_p34909328614"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.850000000000001%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324637_p164909325610"><a name="zh-cn_topic_0000001173324637_p164909325610"></a><a name="zh-cn_topic_0000001173324637_p164909325610"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="48.71%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324637_p04904325616"><a name="zh-cn_topic_0000001173324637_p04904325616"></a><a name="zh-cn_topic_0000001173324637_p04904325616"></a>设置普通选择器的值。</p>
</td>
</tr>
</tbody>
</table>

日期选择器：type=date

<a name="zh-cn_topic_0000001173324637_table174784493618"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001173324637_row54789491561"><th class="cellrowborder" valign="top" width="24.000000000000004%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001173324637_p14781849561"><a name="zh-cn_topic_0000001173324637_p14781849561"></a><a name="zh-cn_topic_0000001173324637_p14781849561"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="10.810000000000002%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001173324637_p447834912613"><a name="zh-cn_topic_0000001173324637_p447834912613"></a><a name="zh-cn_topic_0000001173324637_p447834912613"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="8.63%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001173324637_p12479749564"><a name="zh-cn_topic_0000001173324637_p12479749564"></a><a name="zh-cn_topic_0000001173324637_p12479749564"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.15%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001173324637_p13479749560"><a name="zh-cn_topic_0000001173324637_p13479749560"></a><a name="zh-cn_topic_0000001173324637_p13479749560"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="49.410000000000004%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001173324637_p247913495610"><a name="zh-cn_topic_0000001173324637_p247913495610"></a><a name="zh-cn_topic_0000001173324637_p247913495610"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001173324637_row1047910498616"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324637_p167682562062"><a name="zh-cn_topic_0000001173324637_p167682562062"></a><a name="zh-cn_topic_0000001173324637_p167682562062"></a>start</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324637_p67689566612"><a name="zh-cn_topic_0000001173324637_p67689566612"></a><a name="zh-cn_topic_0000001173324637_p67689566612"></a>&lt;time&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324637_p1576817561266"><a name="zh-cn_topic_0000001173324637_p1576817561266"></a><a name="zh-cn_topic_0000001173324637_p1576817561266"></a>1970-1-1</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324637_p476819561368"><a name="zh-cn_topic_0000001173324637_p476819561368"></a><a name="zh-cn_topic_0000001173324637_p476819561368"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324637_p87681568618"><a name="zh-cn_topic_0000001173324637_p87681568618"></a><a name="zh-cn_topic_0000001173324637_p87681568618"></a>设置日期选择器的起始时间，格式为 YYYY-MM-DD。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324637_row3479549162"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324637_p117686568615"><a name="zh-cn_topic_0000001173324637_p117686568615"></a><a name="zh-cn_topic_0000001173324637_p117686568615"></a>end</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324637_p19768115614615"><a name="zh-cn_topic_0000001173324637_p19768115614615"></a><a name="zh-cn_topic_0000001173324637_p19768115614615"></a>&lt;time&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324637_p27686569618"><a name="zh-cn_topic_0000001173324637_p27686569618"></a><a name="zh-cn_topic_0000001173324637_p27686569618"></a>2100-12-31</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324637_p1076912564617"><a name="zh-cn_topic_0000001173324637_p1076912564617"></a><a name="zh-cn_topic_0000001173324637_p1076912564617"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324637_p1176915562611"><a name="zh-cn_topic_0000001173324637_p1176915562611"></a><a name="zh-cn_topic_0000001173324637_p1176915562611"></a>设置日期选择器的结束时间，格式为 YYYY-MM-DD。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324637_row147919493619"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324637_p20769056565"><a name="zh-cn_topic_0000001173324637_p20769056565"></a><a name="zh-cn_topic_0000001173324637_p20769056565"></a>selected</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324637_p1376935613619"><a name="zh-cn_topic_0000001173324637_p1376935613619"></a><a name="zh-cn_topic_0000001173324637_p1376935613619"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324637_p177694568616"><a name="zh-cn_topic_0000001173324637_p177694568616"></a><a name="zh-cn_topic_0000001173324637_p177694568616"></a>当前日期</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324637_p076925617611"><a name="zh-cn_topic_0000001173324637_p076925617611"></a><a name="zh-cn_topic_0000001173324637_p076925617611"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324637_p17695564620"><a name="zh-cn_topic_0000001173324637_p17695564620"></a><a name="zh-cn_topic_0000001173324637_p17695564620"></a>设置日期选择器弹窗的默认取值，格式为 YYYY-MM-DD，该取值表示选择器弹窗时弹窗界面的默认选择值。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324637_row5556142018016"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324637_p2556102015019"><a name="zh-cn_topic_0000001173324637_p2556102015019"></a><a name="zh-cn_topic_0000001173324637_p2556102015019"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324637_p55560209013"><a name="zh-cn_topic_0000001173324637_p55560209013"></a><a name="zh-cn_topic_0000001173324637_p55560209013"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324637_p55569201203"><a name="zh-cn_topic_0000001173324637_p55569201203"></a><a name="zh-cn_topic_0000001173324637_p55569201203"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324637_p14556142017019"><a name="zh-cn_topic_0000001173324637_p14556142017019"></a><a name="zh-cn_topic_0000001173324637_p14556142017019"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324637_p1855614200012"><a name="zh-cn_topic_0000001173324637_p1855614200012"></a><a name="zh-cn_topic_0000001173324637_p1855614200012"></a>设置日期选择器的值。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324637_row122372051111319"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324637_p2238125117139"><a name="zh-cn_topic_0000001173324637_p2238125117139"></a><a name="zh-cn_topic_0000001173324637_p2238125117139"></a>lunar<sup id="zh-cn_topic_0000001173324637_sup6301324133317"><a name="zh-cn_topic_0000001173324637_sup6301324133317"></a><a name="zh-cn_topic_0000001173324637_sup6301324133317"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324637_p023825181319"><a name="zh-cn_topic_0000001173324637_p023825181319"></a><a name="zh-cn_topic_0000001173324637_p023825181319"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324637_p18238115116134"><a name="zh-cn_topic_0000001173324637_p18238115116134"></a><a name="zh-cn_topic_0000001173324637_p18238115116134"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324637_p0238851121311"><a name="zh-cn_topic_0000001173324637_p0238851121311"></a><a name="zh-cn_topic_0000001173324637_p0238851121311"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324637_p14238195141316"><a name="zh-cn_topic_0000001173324637_p14238195141316"></a><a name="zh-cn_topic_0000001173324637_p14238195141316"></a>设置日期选择器弹窗界面是否为农历展示。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324637_row106371036261"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324637_p118782109269"><a name="zh-cn_topic_0000001173324637_p118782109269"></a><a name="zh-cn_topic_0000001173324637_p118782109269"></a>lunarswitch</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324637_p188781410192610"><a name="zh-cn_topic_0000001173324637_p188781410192610"></a><a name="zh-cn_topic_0000001173324637_p188781410192610"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324637_p14878181052613"><a name="zh-cn_topic_0000001173324637_p14878181052613"></a><a name="zh-cn_topic_0000001173324637_p14878181052613"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324637_p20878141062610"><a name="zh-cn_topic_0000001173324637_p20878141062610"></a><a name="zh-cn_topic_0000001173324637_p20878141062610"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324637_p9878910132617"><a name="zh-cn_topic_0000001173324637_p9878910132617"></a><a name="zh-cn_topic_0000001173324637_p9878910132617"></a>设置日期选择器是否显示农历开关。当值为true时，显示农历开关，点击农历开关可切换公历和农历。当值为false时，不显示农历开关。</p>
<div class="note" id="zh-cn_topic_0000001173324637_note799016359510"><a name="zh-cn_topic_0000001173324637_note799016359510"></a><a name="zh-cn_topic_0000001173324637_note799016359510"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001173324637_p49901135165115"><a name="zh-cn_topic_0000001173324637_p49901135165115"></a><a name="zh-cn_topic_0000001173324637_p49901135165115"></a>仅手机和平板设备支持。 当lunarswitch=true且lunar=true时，开关按钮处于被选中状态。</p>
</div></div>
</td>
</tr>
</tbody>
</table>

时间选择器：type=time

<a name="zh-cn_topic_0000001173324637_table89366820719"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001173324637_row49367819714"><th class="cellrowborder" valign="top" width="24.000000000000004%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001173324637_p1493614815715"><a name="zh-cn_topic_0000001173324637_p1493614815715"></a><a name="zh-cn_topic_0000001173324637_p1493614815715"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="10.810000000000002%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001173324637_p2936881677"><a name="zh-cn_topic_0000001173324637_p2936881677"></a><a name="zh-cn_topic_0000001173324637_p2936881677"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="8.63%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001173324637_p79362815719"><a name="zh-cn_topic_0000001173324637_p79362815719"></a><a name="zh-cn_topic_0000001173324637_p79362815719"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.15%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001173324637_p12936584719"><a name="zh-cn_topic_0000001173324637_p12936584719"></a><a name="zh-cn_topic_0000001173324637_p12936584719"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="49.410000000000004%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001173324637_p15936198876"><a name="zh-cn_topic_0000001173324637_p15936198876"></a><a name="zh-cn_topic_0000001173324637_p15936198876"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001173324637_row2937108277"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324637_p077212191171"><a name="zh-cn_topic_0000001173324637_p077212191171"></a><a name="zh-cn_topic_0000001173324637_p077212191171"></a>containsecond</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324637_p1177214198714"><a name="zh-cn_topic_0000001173324637_p1177214198714"></a><a name="zh-cn_topic_0000001173324637_p1177214198714"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324637_p87721619275"><a name="zh-cn_topic_0000001173324637_p87721619275"></a><a name="zh-cn_topic_0000001173324637_p87721619275"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324637_p127721919372"><a name="zh-cn_topic_0000001173324637_p127721919372"></a><a name="zh-cn_topic_0000001173324637_p127721919372"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324637_p13773101919719"><a name="zh-cn_topic_0000001173324637_p13773101919719"></a><a name="zh-cn_topic_0000001173324637_p13773101919719"></a>设置时间选择器是否包含秒。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324637_row1293719814712"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324637_p577314191171"><a name="zh-cn_topic_0000001173324637_p577314191171"></a><a name="zh-cn_topic_0000001173324637_p577314191171"></a>selected</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324637_p177735196711"><a name="zh-cn_topic_0000001173324637_p177735196711"></a><a name="zh-cn_topic_0000001173324637_p177735196711"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324637_p127734191714"><a name="zh-cn_topic_0000001173324637_p127734191714"></a><a name="zh-cn_topic_0000001173324637_p127734191714"></a>当前时间</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324637_p16773151914716"><a name="zh-cn_topic_0000001173324637_p16773151914716"></a><a name="zh-cn_topic_0000001173324637_p16773151914716"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324637_p57739191974"><a name="zh-cn_topic_0000001173324637_p57739191974"></a><a name="zh-cn_topic_0000001173324637_p57739191974"></a>设置时间选择器弹窗的默认取值，格式为 HH:mm；当包含秒时，格式为HH:mm:ss，</p>
<p id="zh-cn_topic_0000001173324637_p87411455722"><a name="zh-cn_topic_0000001173324637_p87411455722"></a><a name="zh-cn_topic_0000001173324637_p87411455722"></a>该取值表示选择器弹窗时弹窗界面的默认选择值。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324637_row179378815715"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324637_p1577313191078"><a name="zh-cn_topic_0000001173324637_p1577313191078"></a><a name="zh-cn_topic_0000001173324637_p1577313191078"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324637_p47731191717"><a name="zh-cn_topic_0000001173324637_p47731191717"></a><a name="zh-cn_topic_0000001173324637_p47731191717"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324637_p137731819271"><a name="zh-cn_topic_0000001173324637_p137731819271"></a><a name="zh-cn_topic_0000001173324637_p137731819271"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324637_p1977310195710"><a name="zh-cn_topic_0000001173324637_p1977310195710"></a><a name="zh-cn_topic_0000001173324637_p1977310195710"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324637_p117733191473"><a name="zh-cn_topic_0000001173324637_p117733191473"></a><a name="zh-cn_topic_0000001173324637_p117733191473"></a>设置时间选择器的值。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324637_row3976191332214"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324637_p7249338141710"><a name="zh-cn_topic_0000001173324637_p7249338141710"></a><a name="zh-cn_topic_0000001173324637_p7249338141710"></a>hours</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324637_p9642147162010"><a name="zh-cn_topic_0000001173324637_p9642147162010"></a><a name="zh-cn_topic_0000001173324637_p9642147162010"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324637_p10455132202312"><a name="zh-cn_topic_0000001173324637_p10455132202312"></a><a name="zh-cn_topic_0000001173324637_p10455132202312"></a>24<sup id="zh-cn_topic_0000001173324637_sup13455132211233"><a name="zh-cn_topic_0000001173324637_sup13455132211233"></a><a name="zh-cn_topic_0000001173324637_sup13455132211233"></a>1-4</sup></p>
<p id="zh-cn_topic_0000001173324637_p19642164711209"><a name="zh-cn_topic_0000001173324637_p19642164711209"></a><a name="zh-cn_topic_0000001173324637_p19642164711209"></a>-<sup id="zh-cn_topic_0000001173324637_sup14229658122718"><a name="zh-cn_topic_0000001173324637_sup14229658122718"></a><a name="zh-cn_topic_0000001173324637_sup14229658122718"></a><span>5+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324637_p1964254732010"><a name="zh-cn_topic_0000001173324637_p1964254732010"></a><a name="zh-cn_topic_0000001173324637_p1964254732010"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324637_p1642114782010"><a name="zh-cn_topic_0000001173324637_p1642114782010"></a><a name="zh-cn_topic_0000001173324637_p1642114782010"></a>设置时间选择器采用的时间格式，可选值：</p>
<a name="zh-cn_topic_0000001173324637_ul174074428121"></a><a name="zh-cn_topic_0000001173324637_ul174074428121"></a><ul id="zh-cn_topic_0000001173324637_ul174074428121"><li>12：按照12小时制显示，用上午和下午进行区分；</li><li>24：按照24小时制显示。<div class="note" id="zh-cn_topic_0000001173324637_note189471313104"><a name="zh-cn_topic_0000001173324637_note189471313104"></a><a name="zh-cn_topic_0000001173324637_note189471313104"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001173324637_p9947193114104"><a name="zh-cn_topic_0000001173324637_p9947193114104"></a><a name="zh-cn_topic_0000001173324637_p9947193114104"></a>默认值会依据系统当前所选地区和语言选择当地习惯的小时制(12小时制或24小时制)。<sup id="zh-cn_topic_0000001173324637_sup15655162732715"><a name="zh-cn_topic_0000001173324637_sup15655162732715"></a><a name="zh-cn_topic_0000001173324637_sup15655162732715"></a><span>5+</span></sup></p>
</div></div>
</li></ul>
</td>
</tr>
</tbody>
</table>

日期时间选择器：type=datetime，日期的选择范围为本年的日月。

<a name="zh-cn_topic_0000001173324637_table1188511392120"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001173324637_row16886193915128"><th class="cellrowborder" valign="top" width="24.000000000000004%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001173324637_p58868399129"><a name="zh-cn_topic_0000001173324637_p58868399129"></a><a name="zh-cn_topic_0000001173324637_p58868399129"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="10.810000000000002%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001173324637_p19886739161213"><a name="zh-cn_topic_0000001173324637_p19886739161213"></a><a name="zh-cn_topic_0000001173324637_p19886739161213"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="8.63%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001173324637_p138864393128"><a name="zh-cn_topic_0000001173324637_p138864393128"></a><a name="zh-cn_topic_0000001173324637_p138864393128"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.15%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001173324637_p288653914122"><a name="zh-cn_topic_0000001173324637_p288653914122"></a><a name="zh-cn_topic_0000001173324637_p288653914122"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="49.410000000000004%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001173324637_p1886193931212"><a name="zh-cn_topic_0000001173324637_p1886193931212"></a><a name="zh-cn_topic_0000001173324637_p1886193931212"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001173324637_row288753919128"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324637_p20887539141215"><a name="zh-cn_topic_0000001173324637_p20887539141215"></a><a name="zh-cn_topic_0000001173324637_p20887539141215"></a>selected</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324637_p788753910126"><a name="zh-cn_topic_0000001173324637_p788753910126"></a><a name="zh-cn_topic_0000001173324637_p788753910126"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324637_p16887539111214"><a name="zh-cn_topic_0000001173324637_p16887539111214"></a><a name="zh-cn_topic_0000001173324637_p16887539111214"></a>当前日期时间</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324637_p4887203911129"><a name="zh-cn_topic_0000001173324637_p4887203911129"></a><a name="zh-cn_topic_0000001173324637_p4887203911129"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324637_p988710393122"><a name="zh-cn_topic_0000001173324637_p988710393122"></a><a name="zh-cn_topic_0000001173324637_p988710393122"></a>设置日期时间选择器弹窗的默认取值，格式有两种，为月日时分MM-DD-HH-mm或者年月日时分YYYY-MM-DD-HH-mm，不设置年时，默认使用当前年，该取值表示选择器弹窗时弹窗界面的默认选择值。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324637_row1887173951219"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324637_p1288733931210"><a name="zh-cn_topic_0000001173324637_p1288733931210"></a><a name="zh-cn_topic_0000001173324637_p1288733931210"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324637_p1788703918124"><a name="zh-cn_topic_0000001173324637_p1788703918124"></a><a name="zh-cn_topic_0000001173324637_p1788703918124"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324637_p18887193911129"><a name="zh-cn_topic_0000001173324637_p18887193911129"></a><a name="zh-cn_topic_0000001173324637_p18887193911129"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324637_p88873396121"><a name="zh-cn_topic_0000001173324637_p88873396121"></a><a name="zh-cn_topic_0000001173324637_p88873396121"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324637_p1388773910128"><a name="zh-cn_topic_0000001173324637_p1388773910128"></a><a name="zh-cn_topic_0000001173324637_p1388773910128"></a>设置日期时间选择器的值。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324637_row25569188246"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324637_p655031510218"><a name="zh-cn_topic_0000001173324637_p655031510218"></a><a name="zh-cn_topic_0000001173324637_p655031510218"></a>hours</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324637_p1814251913247"><a name="zh-cn_topic_0000001173324637_p1814251913247"></a><a name="zh-cn_topic_0000001173324637_p1814251913247"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324637_p1097921216293"><a name="zh-cn_topic_0000001173324637_p1097921216293"></a><a name="zh-cn_topic_0000001173324637_p1097921216293"></a>24<sup id="zh-cn_topic_0000001173324637_sup1626816180414"><a name="zh-cn_topic_0000001173324637_sup1626816180414"></a><a name="zh-cn_topic_0000001173324637_sup1626816180414"></a>1-4</sup></p>
<p id="zh-cn_topic_0000001173324637_p797971210297"><a name="zh-cn_topic_0000001173324637_p797971210297"></a><a name="zh-cn_topic_0000001173324637_p797971210297"></a>-<sup id="zh-cn_topic_0000001173324637_sup13979712182910"><a name="zh-cn_topic_0000001173324637_sup13979712182910"></a><a name="zh-cn_topic_0000001173324637_sup13979712182910"></a><span>5+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324637_p171426196242"><a name="zh-cn_topic_0000001173324637_p171426196242"></a><a name="zh-cn_topic_0000001173324637_p171426196242"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324637_p1314251932418"><a name="zh-cn_topic_0000001173324637_p1314251932418"></a><a name="zh-cn_topic_0000001173324637_p1314251932418"></a>设置日期时间选择器采用的时间格式，可选值：</p>
<a name="zh-cn_topic_0000001173324637_ul4189124631213"></a><a name="zh-cn_topic_0000001173324637_ul4189124631213"></a><ul id="zh-cn_topic_0000001173324637_ul4189124631213"><li>12：按照12小时制显示，用上午和下午进行区分；</li><li>24：按照24小时制显示。<div class="note" id="zh-cn_topic_0000001173324637_note1563822112115"><a name="zh-cn_topic_0000001173324637_note1563822112115"></a><a name="zh-cn_topic_0000001173324637_note1563822112115"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001173324637_p1563882115113"><a name="zh-cn_topic_0000001173324637_p1563882115113"></a><a name="zh-cn_topic_0000001173324637_p1563882115113"></a>默认值会依据系统当前所选地区和语言选择当地习惯的小时制(12小时制或24小时制)。<sup id="zh-cn_topic_0000001173324637_sup1719092182914"><a name="zh-cn_topic_0000001173324637_sup1719092182914"></a><a name="zh-cn_topic_0000001173324637_sup1719092182914"></a><span>5+</span></sup></p>
</div></div>
</li></ul>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324637_row1742363212240"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324637_p17312155631610"><a name="zh-cn_topic_0000001173324637_p17312155631610"></a><a name="zh-cn_topic_0000001173324637_p17312155631610"></a>lunar<sup id="zh-cn_topic_0000001173324637_sup1613014514117"><a name="zh-cn_topic_0000001173324637_sup1613014514117"></a><a name="zh-cn_topic_0000001173324637_sup1613014514117"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324637_p23121856191617"><a name="zh-cn_topic_0000001173324637_p23121856191617"></a><a name="zh-cn_topic_0000001173324637_p23121856191617"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324637_p331265681617"><a name="zh-cn_topic_0000001173324637_p331265681617"></a><a name="zh-cn_topic_0000001173324637_p331265681617"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324637_p331265615166"><a name="zh-cn_topic_0000001173324637_p331265615166"></a><a name="zh-cn_topic_0000001173324637_p331265615166"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324637_p63124569165"><a name="zh-cn_topic_0000001173324637_p63124569165"></a><a name="zh-cn_topic_0000001173324637_p63124569165"></a>设置日期时间选择器弹窗界面是否为农历展示。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324637_row13832125261615"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324637_p23121056171615"><a name="zh-cn_topic_0000001173324637_p23121056171615"></a><a name="zh-cn_topic_0000001173324637_p23121056171615"></a>lunarswitch</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324637_p153121564169"><a name="zh-cn_topic_0000001173324637_p153121564169"></a><a name="zh-cn_topic_0000001173324637_p153121564169"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324637_p14312205651615"><a name="zh-cn_topic_0000001173324637_p14312205651615"></a><a name="zh-cn_topic_0000001173324637_p14312205651615"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324637_p12312856141615"><a name="zh-cn_topic_0000001173324637_p12312856141615"></a><a name="zh-cn_topic_0000001173324637_p12312856141615"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324637_p134738505123"><a name="zh-cn_topic_0000001173324637_p134738505123"></a><a name="zh-cn_topic_0000001173324637_p134738505123"></a>设置日期选择器是否显示农历开关。当值为true时，显示农历开关，点击农历开关可切换公历和农历。当值为false时，不显示农历开关。</p>
<div class="note" id="zh-cn_topic_0000001173324637_note5428114735118"><a name="zh-cn_topic_0000001173324637_note5428114735118"></a><a name="zh-cn_topic_0000001173324637_note5428114735118"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001173324637_p1342819474512"><a name="zh-cn_topic_0000001173324637_p1342819474512"></a><a name="zh-cn_topic_0000001173324637_p1342819474512"></a>仅手机和平板设备支持。 当lunarswitch=true且lunar=true时，开关按钮处于被选中状态。</p>
</div></div>
</td>
</tr>
</tbody>
</table>

多列文本选择器：type=multi-text

<a name="zh-cn_topic_0000001173324637_table1886619321772"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001173324637_row198671332179"><th class="cellrowborder" valign="top" width="24.000000000000004%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001173324637_p168677321871"><a name="zh-cn_topic_0000001173324637_p168677321871"></a><a name="zh-cn_topic_0000001173324637_p168677321871"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="10.810000000000002%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001173324637_p38670322711"><a name="zh-cn_topic_0000001173324637_p38670322711"></a><a name="zh-cn_topic_0000001173324637_p38670322711"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="8.63%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001173324637_p178670321276"><a name="zh-cn_topic_0000001173324637_p178670321276"></a><a name="zh-cn_topic_0000001173324637_p178670321276"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.15%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001173324637_p9867183215719"><a name="zh-cn_topic_0000001173324637_p9867183215719"></a><a name="zh-cn_topic_0000001173324637_p9867183215719"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="49.410000000000004%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001173324637_p168671324711"><a name="zh-cn_topic_0000001173324637_p168671324711"></a><a name="zh-cn_topic_0000001173324637_p168671324711"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001173324637_row3757154961319"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324637_p12757204951314"><a name="zh-cn_topic_0000001173324637_p12757204951314"></a><a name="zh-cn_topic_0000001173324637_p12757204951314"></a>columns</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324637_p13757124918137"><a name="zh-cn_topic_0000001173324637_p13757124918137"></a><a name="zh-cn_topic_0000001173324637_p13757124918137"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324637_p0757144914132"><a name="zh-cn_topic_0000001173324637_p0757144914132"></a><a name="zh-cn_topic_0000001173324637_p0757144914132"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324637_p14757149111317"><a name="zh-cn_topic_0000001173324637_p14757149111317"></a><a name="zh-cn_topic_0000001173324637_p14757149111317"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324637_p1675884931313"><a name="zh-cn_topic_0000001173324637_p1675884931313"></a><a name="zh-cn_topic_0000001173324637_p1675884931313"></a>设置多列文本选择器的列数。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324637_row3867103214710"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324637_p793074416717"><a name="zh-cn_topic_0000001173324637_p793074416717"></a><a name="zh-cn_topic_0000001173324637_p793074416717"></a>range</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324637_p793010441976"><a name="zh-cn_topic_0000001173324637_p793010441976"></a><a name="zh-cn_topic_0000001173324637_p793010441976"></a>二维Array</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324637_p7930174418712"><a name="zh-cn_topic_0000001173324637_p7930174418712"></a><a name="zh-cn_topic_0000001173324637_p7930174418712"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324637_p2930444971"><a name="zh-cn_topic_0000001173324637_p2930444971"></a><a name="zh-cn_topic_0000001173324637_p2930444971"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324637_p139301644675"><a name="zh-cn_topic_0000001173324637_p139301644675"></a><a name="zh-cn_topic_0000001173324637_p139301644675"></a>设置多列文本选择器的选择项，其中range 为二维数组。长度表示多少列，数组的每项表示每列的数据，如  [["a","b"], ["c","d"]]。</p>
<div class="note" id="zh-cn_topic_0000001173324637_note0651143101220"><a name="zh-cn_topic_0000001173324637_note0651143101220"></a><a name="zh-cn_topic_0000001173324637_note0651143101220"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001173324637_p15651335123"><a name="zh-cn_topic_0000001173324637_p15651335123"></a><a name="zh-cn_topic_0000001173324637_p15651335123"></a>使用时需要使用数据绑定的方式，如range = {{data}}，js中声明相应变量：data：[["a","b"], ["c","d"]]。</p>
</div></div>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324637_row18671332572"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324637_p693016441273"><a name="zh-cn_topic_0000001173324637_p693016441273"></a><a name="zh-cn_topic_0000001173324637_p693016441273"></a>selected</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324637_p159306448720"><a name="zh-cn_topic_0000001173324637_p159306448720"></a><a name="zh-cn_topic_0000001173324637_p159306448720"></a>Array</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324637_p18930544471"><a name="zh-cn_topic_0000001173324637_p18930544471"></a><a name="zh-cn_topic_0000001173324637_p18930544471"></a>[0,0,0,…]</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324637_p69305448719"><a name="zh-cn_topic_0000001173324637_p69305448719"></a><a name="zh-cn_topic_0000001173324637_p69305448719"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324637_p12930144373"><a name="zh-cn_topic_0000001173324637_p12930144373"></a><a name="zh-cn_topic_0000001173324637_p12930144373"></a>设置多列文本选择器弹窗的默认值，每一列被选中项对应的索引构成的数组，该取值表示选择器弹窗时弹窗界面的默认选择值。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324637_row1186818329711"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324637_p1693054420719"><a name="zh-cn_topic_0000001173324637_p1693054420719"></a><a name="zh-cn_topic_0000001173324637_p1693054420719"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324637_p69308446714"><a name="zh-cn_topic_0000001173324637_p69308446714"></a><a name="zh-cn_topic_0000001173324637_p69308446714"></a>Array</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324637_p1893014441578"><a name="zh-cn_topic_0000001173324637_p1893014441578"></a><a name="zh-cn_topic_0000001173324637_p1893014441578"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324637_p11930174414718"><a name="zh-cn_topic_0000001173324637_p11930174414718"></a><a name="zh-cn_topic_0000001173324637_p11930174414718"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324637_p5930344474"><a name="zh-cn_topic_0000001173324637_p5930344474"></a><a name="zh-cn_topic_0000001173324637_p5930344474"></a>设置多列文本选择器的值，每一列被选中项对应的值构成的数组。</p>
</td>
</tr>
</tbody>
</table>

## 样式<a name="zh-cn_topic_0000001173324637_section1299175511712"></a>

除支持[通用样式](js-components-common-styles.md#ZH-CN_TOPIC_0000001163932190)外，还支持如下样式：

<a name="zh-cn_topic_0000001173324637_table861635214361"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001173324637_row161725216363"><th class="cellrowborder" valign="top" width="14.318568143185681%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001173324637_p166171452183611"><a name="zh-cn_topic_0000001173324637_p166171452183611"></a><a name="zh-cn_topic_0000001173324637_p166171452183611"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="11.528847115288471%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001173324637_p0617952203612"><a name="zh-cn_topic_0000001173324637_p0617952203612"></a><a name="zh-cn_topic_0000001173324637_p0617952203612"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="13.268673132686734%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001173324637_p5617252183615"><a name="zh-cn_topic_0000001173324637_p5617252183615"></a><a name="zh-cn_topic_0000001173324637_p5617252183615"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="8.60913908609139%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001173324637_p561775273618"><a name="zh-cn_topic_0000001173324637_p561775273618"></a><a name="zh-cn_topic_0000001173324637_p561775273618"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="52.274772522747725%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001173324637_p12617185218369"><a name="zh-cn_topic_0000001173324637_p12617185218369"></a><a name="zh-cn_topic_0000001173324637_p12617185218369"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001173324637_row26174523369"><td class="cellrowborder" valign="top" width="14.318568143185681%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324637_p861715528369"><a name="zh-cn_topic_0000001173324637_p861715528369"></a><a name="zh-cn_topic_0000001173324637_p861715528369"></a>text-color</p>
</td>
<td class="cellrowborder" valign="top" width="11.528847115288471%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324637_p12617195219360"><a name="zh-cn_topic_0000001173324637_p12617195219360"></a><a name="zh-cn_topic_0000001173324637_p12617195219360"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.268673132686734%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324637_p156171552173616"><a name="zh-cn_topic_0000001173324637_p156171552173616"></a><a name="zh-cn_topic_0000001173324637_p156171552173616"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.60913908609139%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324637_p1961715522367"><a name="zh-cn_topic_0000001173324637_p1961715522367"></a><a name="zh-cn_topic_0000001173324637_p1961715522367"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.274772522747725%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324637_p761713528364"><a name="zh-cn_topic_0000001173324637_p761713528364"></a><a name="zh-cn_topic_0000001173324637_p761713528364"></a>选择器的文本颜色。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324637_row96178528368"><td class="cellrowborder" valign="top" width="14.318568143185681%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324637_p161785273614"><a name="zh-cn_topic_0000001173324637_p161785273614"></a><a name="zh-cn_topic_0000001173324637_p161785273614"></a>font-size</p>
</td>
<td class="cellrowborder" valign="top" width="11.528847115288471%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324637_p14618752123616"><a name="zh-cn_topic_0000001173324637_p14618752123616"></a><a name="zh-cn_topic_0000001173324637_p14618752123616"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.268673132686734%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324637_p4618145223618"><a name="zh-cn_topic_0000001173324637_p4618145223618"></a><a name="zh-cn_topic_0000001173324637_p4618145223618"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.60913908609139%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324637_p26189527366"><a name="zh-cn_topic_0000001173324637_p26189527366"></a><a name="zh-cn_topic_0000001173324637_p26189527366"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.274772522747725%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324637_p186188525363"><a name="zh-cn_topic_0000001173324637_p186188525363"></a><a name="zh-cn_topic_0000001173324637_p186188525363"></a>选择器的文本尺寸。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324637_row18618195220360"><td class="cellrowborder" valign="top" width="14.318568143185681%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324637_p13618205233610"><a name="zh-cn_topic_0000001173324637_p13618205233610"></a><a name="zh-cn_topic_0000001173324637_p13618205233610"></a>allow-scale</p>
</td>
<td class="cellrowborder" valign="top" width="11.528847115288471%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324637_p146184528362"><a name="zh-cn_topic_0000001173324637_p146184528362"></a><a name="zh-cn_topic_0000001173324637_p146184528362"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="13.268673132686734%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324637_p15618852133613"><a name="zh-cn_topic_0000001173324637_p15618852133613"></a><a name="zh-cn_topic_0000001173324637_p15618852133613"></a>true</p>
</td>
<td class="cellrowborder" valign="top" width="8.60913908609139%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324637_p12618652143612"><a name="zh-cn_topic_0000001173324637_p12618652143612"></a><a name="zh-cn_topic_0000001173324637_p12618652143612"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.274772522747725%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324637_p106188526364"><a name="zh-cn_topic_0000001173324637_p106188526364"></a><a name="zh-cn_topic_0000001173324637_p106188526364"></a>选择器的文本尺寸是否跟随系统设置字体缩放尺寸进行放大缩小。</p>
<div class="note" id="zh-cn_topic_0000001173324637_note17618552143613"><a name="zh-cn_topic_0000001173324637_note17618552143613"></a><a name="zh-cn_topic_0000001173324637_note17618552143613"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001173324637_p186187525369"><a name="zh-cn_topic_0000001173324637_p186187525369"></a><a name="zh-cn_topic_0000001173324637_p186187525369"></a>如果在config描述文件中针对ability配置了fontSize的config-changes标签，则应用不会重启而直接生效。</p>
</div></div>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324637_row13618135215369"><td class="cellrowborder" valign="top" width="14.318568143185681%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324637_p16618175233612"><a name="zh-cn_topic_0000001173324637_p16618175233612"></a><a name="zh-cn_topic_0000001173324637_p16618175233612"></a>letter-spacing</p>
</td>
<td class="cellrowborder" valign="top" width="11.528847115288471%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324637_p1618175253611"><a name="zh-cn_topic_0000001173324637_p1618175253611"></a><a name="zh-cn_topic_0000001173324637_p1618175253611"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.268673132686734%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324637_p13618052133610"><a name="zh-cn_topic_0000001173324637_p13618052133610"></a><a name="zh-cn_topic_0000001173324637_p13618052133610"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="8.60913908609139%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324637_p561811521364"><a name="zh-cn_topic_0000001173324637_p561811521364"></a><a name="zh-cn_topic_0000001173324637_p561811521364"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.274772522747725%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324637_p3619852193615"><a name="zh-cn_topic_0000001173324637_p3619852193615"></a><a name="zh-cn_topic_0000001173324637_p3619852193615"></a>选择器的字符间距。见<a href="js-components-basic-text.md#zh-cn_topic_0000001127125018_section5775351116">text组件的letter-spacing样式属性</a>。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324637_row166194521368"><td class="cellrowborder" valign="top" width="14.318568143185681%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324637_p76191552133617"><a name="zh-cn_topic_0000001173324637_p76191552133617"></a><a name="zh-cn_topic_0000001173324637_p76191552133617"></a>text-decoration</p>
</td>
<td class="cellrowborder" valign="top" width="11.528847115288471%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324637_p11619155211364"><a name="zh-cn_topic_0000001173324637_p11619155211364"></a><a name="zh-cn_topic_0000001173324637_p11619155211364"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.268673132686734%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324637_p166191252123618"><a name="zh-cn_topic_0000001173324637_p166191252123618"></a><a name="zh-cn_topic_0000001173324637_p166191252123618"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.60913908609139%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324637_p661975283615"><a name="zh-cn_topic_0000001173324637_p661975283615"></a><a name="zh-cn_topic_0000001173324637_p661975283615"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.274772522747725%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324637_p13619115293616"><a name="zh-cn_topic_0000001173324637_p13619115293616"></a><a name="zh-cn_topic_0000001173324637_p13619115293616"></a>选择器的文本修饰。见<a href="js-components-basic-text.md#zh-cn_topic_0000001127125018_section5775351116">text组件的text-decoration样式属性</a>。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324637_row18619205203619"><td class="cellrowborder" valign="top" width="14.318568143185681%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324637_p11619155203617"><a name="zh-cn_topic_0000001173324637_p11619155203617"></a><a name="zh-cn_topic_0000001173324637_p11619155203617"></a>font-style</p>
</td>
<td class="cellrowborder" valign="top" width="11.528847115288471%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324637_p2061910523364"><a name="zh-cn_topic_0000001173324637_p2061910523364"></a><a name="zh-cn_topic_0000001173324637_p2061910523364"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.268673132686734%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324637_p1561995212365"><a name="zh-cn_topic_0000001173324637_p1561995212365"></a><a name="zh-cn_topic_0000001173324637_p1561995212365"></a>normal</p>
</td>
<td class="cellrowborder" valign="top" width="8.60913908609139%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324637_p196193523361"><a name="zh-cn_topic_0000001173324637_p196193523361"></a><a name="zh-cn_topic_0000001173324637_p196193523361"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.274772522747725%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324637_p11619205253614"><a name="zh-cn_topic_0000001173324637_p11619205253614"></a><a name="zh-cn_topic_0000001173324637_p11619205253614"></a>选择器的字体样式。见<a href="js-components-basic-text.md#zh-cn_topic_0000001127125018_section5775351116">text组件的font-style样式属性</a>。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324637_row3619652133619"><td class="cellrowborder" valign="top" width="14.318568143185681%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324637_p7619135233617"><a name="zh-cn_topic_0000001173324637_p7619135233617"></a><a name="zh-cn_topic_0000001173324637_p7619135233617"></a>font-weight</p>
</td>
<td class="cellrowborder" valign="top" width="11.528847115288471%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324637_p13619165203616"><a name="zh-cn_topic_0000001173324637_p13619165203616"></a><a name="zh-cn_topic_0000001173324637_p13619165203616"></a>number | string</p>
</td>
<td class="cellrowborder" valign="top" width="13.268673132686734%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324637_p10619175217364"><a name="zh-cn_topic_0000001173324637_p10619175217364"></a><a name="zh-cn_topic_0000001173324637_p10619175217364"></a>normal</p>
</td>
<td class="cellrowborder" valign="top" width="8.60913908609139%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324637_p16619252163610"><a name="zh-cn_topic_0000001173324637_p16619252163610"></a><a name="zh-cn_topic_0000001173324637_p16619252163610"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.274772522747725%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324637_p762025283614"><a name="zh-cn_topic_0000001173324637_p762025283614"></a><a name="zh-cn_topic_0000001173324637_p762025283614"></a>选择器的字体粗细。见<a href="js-components-basic-text.md#zh-cn_topic_0000001127125018_section5775351116">text组件的font-weight样式属性</a>。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324637_row6620145263610"><td class="cellrowborder" valign="top" width="14.318568143185681%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324637_p186206524367"><a name="zh-cn_topic_0000001173324637_p186206524367"></a><a name="zh-cn_topic_0000001173324637_p186206524367"></a>font-family</p>
</td>
<td class="cellrowborder" valign="top" width="11.528847115288471%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324637_p1462035215367"><a name="zh-cn_topic_0000001173324637_p1462035215367"></a><a name="zh-cn_topic_0000001173324637_p1462035215367"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.268673132686734%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324637_p18620352103613"><a name="zh-cn_topic_0000001173324637_p18620352103613"></a><a name="zh-cn_topic_0000001173324637_p18620352103613"></a>sans-serif</p>
</td>
<td class="cellrowborder" valign="top" width="8.60913908609139%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324637_p9620135217365"><a name="zh-cn_topic_0000001173324637_p9620135217365"></a><a name="zh-cn_topic_0000001173324637_p9620135217365"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.274772522747725%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324637_p16620195219364"><a name="zh-cn_topic_0000001173324637_p16620195219364"></a><a name="zh-cn_topic_0000001173324637_p16620195219364"></a>选择器的字体列表，用逗号分隔，每个字体用字体名或者字体族名设置。列表中第一个系统中存在的或者通过<a href="js-components-common-customizing-font.md#ZH-CN_TOPIC_0000001163812210">自定义字体</a>指定的字体，会被选中作为文本的字体。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324637_row9620155217363"><td class="cellrowborder" valign="top" width="14.318568143185681%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324637_p146201152123616"><a name="zh-cn_topic_0000001173324637_p146201152123616"></a><a name="zh-cn_topic_0000001173324637_p146201152123616"></a>line-height</p>
</td>
<td class="cellrowborder" valign="top" width="11.528847115288471%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324637_p262035263611"><a name="zh-cn_topic_0000001173324637_p262035263611"></a><a name="zh-cn_topic_0000001173324637_p262035263611"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.268673132686734%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324637_p1062025219364"><a name="zh-cn_topic_0000001173324637_p1062025219364"></a><a name="zh-cn_topic_0000001173324637_p1062025219364"></a>0px</p>
</td>
<td class="cellrowborder" valign="top" width="8.60913908609139%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324637_p16620165213368"><a name="zh-cn_topic_0000001173324637_p16620165213368"></a><a name="zh-cn_topic_0000001173324637_p16620165213368"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.274772522747725%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324637_p1562017529368"><a name="zh-cn_topic_0000001173324637_p1562017529368"></a><a name="zh-cn_topic_0000001173324637_p1562017529368"></a>选择器的文本行高。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324637_row1662035223613"><td class="cellrowborder" valign="top" width="14.318568143185681%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324637_p66201752133616"><a name="zh-cn_topic_0000001173324637_p66201752133616"></a><a name="zh-cn_topic_0000001173324637_p66201752133616"></a>column-height<sup id="zh-cn_topic_0000001173324637_sup162018529360"><a name="zh-cn_topic_0000001173324637_sup162018529360"></a><a name="zh-cn_topic_0000001173324637_sup162018529360"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="11.528847115288471%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324637_p46200529364"><a name="zh-cn_topic_0000001173324637_p46200529364"></a><a name="zh-cn_topic_0000001173324637_p46200529364"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.268673132686734%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324637_p1562125212366"><a name="zh-cn_topic_0000001173324637_p1562125212366"></a><a name="zh-cn_topic_0000001173324637_p1562125212366"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.60913908609139%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324637_p1862185217363"><a name="zh-cn_topic_0000001173324637_p1862185217363"></a><a name="zh-cn_topic_0000001173324637_p1862185217363"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.274772522747725%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324637_p116215526369"><a name="zh-cn_topic_0000001173324637_p116215526369"></a><a name="zh-cn_topic_0000001173324637_p116215526369"></a>选择器的选择项列表高度。</p>
<div class="note" id="zh-cn_topic_0000001173324637_note769381335220"><a name="zh-cn_topic_0000001173324637_note769381335220"></a><a name="zh-cn_topic_0000001173324637_note769381335220"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001173324637_p18693101311524"><a name="zh-cn_topic_0000001173324637_p18693101311524"></a><a name="zh-cn_topic_0000001173324637_p18693101311524"></a>仅手机和平板设备支持。</p>
</div></div>
</td>
</tr>
</tbody>
</table>

## 事件<a name="zh-cn_topic_0000001173324637_section1724215114357"></a>

除支持[通用事件](js-components-common-events.md#ZH-CN_TOPIC_0000001209412119)外，还支持如下事件：

普通选择器：

<a name="zh-cn_topic_0000001173324637_table1024535153519"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001173324637_row14245051103519"><th class="cellrowborder" valign="top" width="15.370000000000001%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173324637_p024535163513"><a name="zh-cn_topic_0000001173324637_p024535163513"></a><a name="zh-cn_topic_0000001173324637_p024535163513"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="34.22%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173324637_p20245185119357"><a name="zh-cn_topic_0000001173324637_p20245185119357"></a><a name="zh-cn_topic_0000001173324637_p20245185119357"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="50.41%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173324637_p7245105143510"><a name="zh-cn_topic_0000001173324637_p7245105143510"></a><a name="zh-cn_topic_0000001173324637_p7245105143510"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001173324637_row1624595173510"><td class="cellrowborder" valign="top" width="15.370000000000001%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173324637_p1424518517357"><a name="zh-cn_topic_0000001173324637_p1424518517357"></a><a name="zh-cn_topic_0000001173324637_p1424518517357"></a>change</p>
</td>
<td class="cellrowborder" valign="top" width="34.22%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173324637_p52451351143515"><a name="zh-cn_topic_0000001173324637_p52451351143515"></a><a name="zh-cn_topic_0000001173324637_p52451351143515"></a>{ newValue:newValue, newSelected:newSelected }</p>
</td>
<td class="cellrowborder" valign="top" width="50.41%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173324637_p202450516358"><a name="zh-cn_topic_0000001173324637_p202450516358"></a><a name="zh-cn_topic_0000001173324637_p202450516358"></a>普通选择器选择值后点击弹窗中的确定按钮时触发该事件（newSelected为索引）。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324637_row152451751123518"><td class="cellrowborder" valign="top" width="15.370000000000001%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173324637_p13245251133518"><a name="zh-cn_topic_0000001173324637_p13245251133518"></a><a name="zh-cn_topic_0000001173324637_p13245251133518"></a>cancel</p>
</td>
<td class="cellrowborder" valign="top" width="34.22%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173324637_p52457518356"><a name="zh-cn_topic_0000001173324637_p52457518356"></a><a name="zh-cn_topic_0000001173324637_p52457518356"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="50.41%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173324637_p1724618510355"><a name="zh-cn_topic_0000001173324637_p1724618510355"></a><a name="zh-cn_topic_0000001173324637_p1724618510355"></a>用户点击弹窗中的取消按钮时触发该事件。</p>
</td>
</tr>
</tbody>
</table>

日期选择器：

<a name="zh-cn_topic_0000001173324637_table424655112352"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001173324637_row7246155163518"><th class="cellrowborder" valign="top" width="15.370000000000001%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173324637_p02465511352"><a name="zh-cn_topic_0000001173324637_p02465511352"></a><a name="zh-cn_topic_0000001173324637_p02465511352"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="34.22%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173324637_p7246351143517"><a name="zh-cn_topic_0000001173324637_p7246351143517"></a><a name="zh-cn_topic_0000001173324637_p7246351143517"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="50.41%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173324637_p424665133514"><a name="zh-cn_topic_0000001173324637_p424665133514"></a><a name="zh-cn_topic_0000001173324637_p424665133514"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001173324637_row82462051163517"><td class="cellrowborder" valign="top" width="15.370000000000001%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173324637_p424617518356"><a name="zh-cn_topic_0000001173324637_p424617518356"></a><a name="zh-cn_topic_0000001173324637_p424617518356"></a>change</p>
</td>
<td class="cellrowborder" valign="top" width="34.22%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173324637_p8246185133519"><a name="zh-cn_topic_0000001173324637_p8246185133519"></a><a name="zh-cn_topic_0000001173324637_p8246185133519"></a>{ year:year, month:month, day:day }</p>
</td>
<td class="cellrowborder" valign="top" width="50.41%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173324637_p192461451183514"><a name="zh-cn_topic_0000001173324637_p192461451183514"></a><a name="zh-cn_topic_0000001173324637_p192461451183514"></a>日期选择器选择值后点击弹窗中的确认按钮时触发该事件。</p>
<div class="note" id="zh-cn_topic_0000001173324637_note192461751103512"><a name="zh-cn_topic_0000001173324637_note192461751103512"></a><a name="zh-cn_topic_0000001173324637_note192461751103512"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001173324637_p16246125163517"><a name="zh-cn_topic_0000001173324637_p16246125163517"></a><a name="zh-cn_topic_0000001173324637_p16246125163517"></a>month值范围为： 0（1月）~11（12月）。<sup id="zh-cn_topic_0000001173324637_sup102461651123517"><a name="zh-cn_topic_0000001173324637_sup102461651123517"></a><a name="zh-cn_topic_0000001173324637_sup102461651123517"></a><span>5+</span></sup></p>
</div></div>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324637_row1424615115350"><td class="cellrowborder" valign="top" width="15.370000000000001%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173324637_p1724618511355"><a name="zh-cn_topic_0000001173324637_p1724618511355"></a><a name="zh-cn_topic_0000001173324637_p1724618511355"></a>cancel</p>
</td>
<td class="cellrowborder" valign="top" width="34.22%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173324637_p52467516353"><a name="zh-cn_topic_0000001173324637_p52467516353"></a><a name="zh-cn_topic_0000001173324637_p52467516353"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="50.41%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173324637_p172469518350"><a name="zh-cn_topic_0000001173324637_p172469518350"></a><a name="zh-cn_topic_0000001173324637_p172469518350"></a>用户点击弹窗中的取消按钮时触发该事件。</p>
</td>
</tr>
</tbody>
</table>

日期时间选择器：

<a name="zh-cn_topic_0000001173324637_table2024785114353"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001173324637_row2247551163520"><th class="cellrowborder" valign="top" width="15.370000000000001%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173324637_p824775114357"><a name="zh-cn_topic_0000001173324637_p824775114357"></a><a name="zh-cn_topic_0000001173324637_p824775114357"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="34.22%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173324637_p1324775113359"><a name="zh-cn_topic_0000001173324637_p1324775113359"></a><a name="zh-cn_topic_0000001173324637_p1324775113359"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="50.41%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173324637_p224785143516"><a name="zh-cn_topic_0000001173324637_p224785143516"></a><a name="zh-cn_topic_0000001173324637_p224785143516"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001173324637_row192475517358"><td class="cellrowborder" valign="top" width="15.370000000000001%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173324637_p724705119351"><a name="zh-cn_topic_0000001173324637_p724705119351"></a><a name="zh-cn_topic_0000001173324637_p724705119351"></a>change</p>
</td>
<td class="cellrowborder" valign="top" width="34.22%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173324637_p5247175116352"><a name="zh-cn_topic_0000001173324637_p5247175116352"></a><a name="zh-cn_topic_0000001173324637_p5247175116352"></a>{ year:year, month:month, day:day,  hour:hour, minute:minute}</p>
</td>
<td class="cellrowborder" valign="top" width="50.41%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173324637_p13247155111354"><a name="zh-cn_topic_0000001173324637_p13247155111354"></a><a name="zh-cn_topic_0000001173324637_p13247155111354"></a>日期时间选择器选择值后点击弹窗中的确认按钮时触发该事件。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324637_row172475516357"><td class="cellrowborder" valign="top" width="15.370000000000001%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173324637_p024755117352"><a name="zh-cn_topic_0000001173324637_p024755117352"></a><a name="zh-cn_topic_0000001173324637_p024755117352"></a>cancel</p>
</td>
<td class="cellrowborder" valign="top" width="34.22%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173324637_p1524775113519"><a name="zh-cn_topic_0000001173324637_p1524775113519"></a><a name="zh-cn_topic_0000001173324637_p1524775113519"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="50.41%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173324637_p102472518354"><a name="zh-cn_topic_0000001173324637_p102472518354"></a><a name="zh-cn_topic_0000001173324637_p102472518354"></a>用户点击弹窗中的取消按钮时触发该事件。</p>
</td>
</tr>
</tbody>
</table>

时间选择器：

<a name="zh-cn_topic_0000001173324637_table102472051113519"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001173324637_row162481151143512"><th class="cellrowborder" valign="top" width="15.370000000000001%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173324637_p18248145153511"><a name="zh-cn_topic_0000001173324637_p18248145153511"></a><a name="zh-cn_topic_0000001173324637_p18248145153511"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="34.22%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173324637_p1924810511351"><a name="zh-cn_topic_0000001173324637_p1924810511351"></a><a name="zh-cn_topic_0000001173324637_p1924810511351"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="50.41%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173324637_p152481851103514"><a name="zh-cn_topic_0000001173324637_p152481851103514"></a><a name="zh-cn_topic_0000001173324637_p152481851103514"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001173324637_row82481516354"><td class="cellrowborder" valign="top" width="15.370000000000001%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173324637_p824812519355"><a name="zh-cn_topic_0000001173324637_p824812519355"></a><a name="zh-cn_topic_0000001173324637_p824812519355"></a>change</p>
</td>
<td class="cellrowborder" valign="top" width="34.22%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173324637_p5248115183512"><a name="zh-cn_topic_0000001173324637_p5248115183512"></a><a name="zh-cn_topic_0000001173324637_p5248115183512"></a>{ hour:hour, minute:minute,</p>
<p id="zh-cn_topic_0000001173324637_p17248165153517"><a name="zh-cn_topic_0000001173324637_p17248165153517"></a><a name="zh-cn_topic_0000001173324637_p17248165153517"></a>[second:second] }</p>
</td>
<td class="cellrowborder" valign="top" width="50.41%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173324637_p824811519353"><a name="zh-cn_topic_0000001173324637_p824811519353"></a><a name="zh-cn_topic_0000001173324637_p824811519353"></a>时间选择器选择值后点击弹窗中的确认按钮时触发该事件，当使用时分秒时，还包含秒数据。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324637_row3248135118354"><td class="cellrowborder" valign="top" width="15.370000000000001%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173324637_p12249165113512"><a name="zh-cn_topic_0000001173324637_p12249165113512"></a><a name="zh-cn_topic_0000001173324637_p12249165113512"></a>cancel</p>
</td>
<td class="cellrowborder" valign="top" width="34.22%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173324637_p15249105114351"><a name="zh-cn_topic_0000001173324637_p15249105114351"></a><a name="zh-cn_topic_0000001173324637_p15249105114351"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="50.41%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173324637_p1249145115358"><a name="zh-cn_topic_0000001173324637_p1249145115358"></a><a name="zh-cn_topic_0000001173324637_p1249145115358"></a>用户点击弹窗中的取消按钮时触发该事件。</p>
</td>
</tr>
</tbody>
</table>

多列文本选择器：

<a name="zh-cn_topic_0000001173324637_table14249251153519"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001173324637_row152491451133516"><th class="cellrowborder" valign="top" width="13.969999999999999%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173324637_p202497516355"><a name="zh-cn_topic_0000001173324637_p202497516355"></a><a name="zh-cn_topic_0000001173324637_p202497516355"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="36.9%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173324637_p17249351103515"><a name="zh-cn_topic_0000001173324637_p17249351103515"></a><a name="zh-cn_topic_0000001173324637_p17249351103515"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="49.13%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173324637_p11249185111354"><a name="zh-cn_topic_0000001173324637_p11249185111354"></a><a name="zh-cn_topic_0000001173324637_p11249185111354"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001173324637_row13249351183510"><td class="cellrowborder" valign="top" width="13.969999999999999%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173324637_p1524916515353"><a name="zh-cn_topic_0000001173324637_p1524916515353"></a><a name="zh-cn_topic_0000001173324637_p1524916515353"></a>change</p>
</td>
<td class="cellrowborder" valign="top" width="36.9%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173324637_p1249195111352"><a name="zh-cn_topic_0000001173324637_p1249195111352"></a><a name="zh-cn_topic_0000001173324637_p1249195111352"></a>{ newValue:[newValue1, newValue2, newValue3, …], newSelected:[newSelected1, newSelected2, newSelected3, …] }</p>
</td>
<td class="cellrowborder" valign="top" width="49.13%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173324637_p10250165119356"><a name="zh-cn_topic_0000001173324637_p10250165119356"></a><a name="zh-cn_topic_0000001173324637_p10250165119356"></a>多列文本选择器选择值后点击弹窗中的确认按钮时触发该事件，其中：</p>
<a name="zh-cn_topic_0000001173324637_ul1425045115352"></a><a name="zh-cn_topic_0000001173324637_ul1425045115352"></a><ul id="zh-cn_topic_0000001173324637_ul1425045115352"><li>newValue：被选中项对应的值构成的数组。</li><li>newSelected：被选中项对应的索引构成的数组，两者的长度和range的长度一致。</li></ul>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324637_row325015143518"><td class="cellrowborder" valign="top" width="13.969999999999999%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173324637_p8250205119359"><a name="zh-cn_topic_0000001173324637_p8250205119359"></a><a name="zh-cn_topic_0000001173324637_p8250205119359"></a>columnchange</p>
</td>
<td class="cellrowborder" valign="top" width="36.9%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173324637_p1325015111351"><a name="zh-cn_topic_0000001173324637_p1325015111351"></a><a name="zh-cn_topic_0000001173324637_p1325015111351"></a>{ column:column, newValue:newValue, newSelected:newSelected }</p>
</td>
<td class="cellrowborder" valign="top" width="49.13%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173324637_p5250115112351"><a name="zh-cn_topic_0000001173324637_p5250115112351"></a><a name="zh-cn_topic_0000001173324637_p5250115112351"></a>多列文本选择器中某一列的值改变时触发该事件，其中：</p>
<a name="zh-cn_topic_0000001173324637_ul025095133520"></a><a name="zh-cn_topic_0000001173324637_ul025095133520"></a><ul id="zh-cn_topic_0000001173324637_ul025095133520"><li>column：第几列修改。</li><li>newValue：选中的值。</li><li>newSelected：选中值对应的索引。</li></ul>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324637_row1250651143510"><td class="cellrowborder" valign="top" width="13.969999999999999%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173324637_p62501519350"><a name="zh-cn_topic_0000001173324637_p62501519350"></a><a name="zh-cn_topic_0000001173324637_p62501519350"></a>cancel</p>
</td>
<td class="cellrowborder" valign="top" width="36.9%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173324637_p725015517358"><a name="zh-cn_topic_0000001173324637_p725015517358"></a><a name="zh-cn_topic_0000001173324637_p725015517358"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="49.13%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173324637_p325017519359"><a name="zh-cn_topic_0000001173324637_p325017519359"></a><a name="zh-cn_topic_0000001173324637_p325017519359"></a>用户点击弹窗中的取消按钮时触发该事件。</p>
</td>
</tr>
</tbody>
</table>

## 方法<a name="zh-cn_topic_0000001173324637_section47669296127"></a>

除支持[通用方法](js-components-common-methods.md#ZH-CN_TOPIC_0000001209252157)外，支持如下方法：

<a name="zh-cn_topic_0000001173324637_t26fe2ddff8674cc38a3a1ec490b76e2f"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001173324637_r237544a789f74f4599b0688cdb75239a"><th class="cellrowborder" valign="top" width="23%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173324637_a897dc10a0e4e45bc94f02c558c679435"><a name="zh-cn_topic_0000001173324637_a897dc10a0e4e45bc94f02c558c679435"></a><a name="zh-cn_topic_0000001173324637_a897dc10a0e4e45bc94f02c558c679435"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="32%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173324637_ac86c6eca347b48e9a749143ecf54f38f"><a name="zh-cn_topic_0000001173324637_ac86c6eca347b48e9a749143ecf54f38f"></a><a name="zh-cn_topic_0000001173324637_ac86c6eca347b48e9a749143ecf54f38f"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="45%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173324637_a0050d08b0c5744de88990d92ef35d3b1"><a name="zh-cn_topic_0000001173324637_a0050d08b0c5744de88990d92ef35d3b1"></a><a name="zh-cn_topic_0000001173324637_a0050d08b0c5744de88990d92ef35d3b1"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001173324637_r08b3c58c981c42a390dc730286c9ce95"><td class="cellrowborder" valign="top" width="23%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173324637_a6385a8ec6d534f7698eaf47b265bec85"><a name="zh-cn_topic_0000001173324637_a6385a8ec6d534f7698eaf47b265bec85"></a><a name="zh-cn_topic_0000001173324637_a6385a8ec6d534f7698eaf47b265bec85"></a>show</p>
</td>
<td class="cellrowborder" valign="top" width="32%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173324637_p178497012101"><a name="zh-cn_topic_0000001173324637_p178497012101"></a><a name="zh-cn_topic_0000001173324637_p178497012101"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173324637_p384919011103"><a name="zh-cn_topic_0000001173324637_p384919011103"></a><a name="zh-cn_topic_0000001173324637_p384919011103"></a>显示 picker。</p>
</td>
</tr>
</tbody>
</table>

## 示例<a name="zh-cn_topic_0000001173324637_section11956342165513"></a>

```
<!-- xxx.hml -->
<div class="container">
  <picker id="picker_text" type="text" value="{{textvalue}}" selected="{{textselect}}" range="{{rangetext}}" onchange="textonchange" oncancel="textoncancel" class="pickertext"></picker>

  <picker id="picker_date" type="date" value="{{datevalue}}" start="2002-2-5" end="2030-6-5" selected="{{dateselect}}" lunarswitch="true" onchange="dateonchange" oncancel="dateoncancel" class="pickerdate"></picker>

  <picker id="picker_time" type="time" value="{{timevalue}}" containsecond="{{containsecond}}" selected="{{timeselect}}" hours="12" onchange="timeonchange" oncancel="timeoncancel" class="pickertime"></picker>

  <picker id="picker_datetime" type="datetime" value="{{datetimevalue}}" selected="{{datetimeselect}}" hours="24" lunarswitch="true" onchange="datetimeonchange" oncancel="datetimeoncancel" class="pickerdatetime"></picker>

  <picker id="picker_multi" type="multi-text" value="{{multitextvalue}}" columns="3" range="{{multitext}}" selected="{{multitextselect}}" onchange="multitextonchange" oncancel="multitextoncancel" class="pickermuitl"></picker>
</div>
```

```
/* xxx.css */
.container {    
  flex-direction: column;
  justify-content: center;
  align-items: center;
}
.pickertext{    
  background-color: red;
  width: 300;
  height: 400;
}
.pickerdate{    
  background-color: #BEFF5B;
  width: 200;
  height: 200;
}
.pickertime{    
  background-color: #B764FF;
  width: 500;
  height: 200;
}
.pickerdatetime{    
  background-color: #FF6387;
  width: 100%;
  height: 300;
}
.pickermuitl{    
  background-color: #71FF31;
}
```

```
// xxx.js
import router from '@system.router';
import prompt from '@system.prompt';
export default {
  data: {    
    rangetext:['15', "20", "25"],    
    multitext:[["a", "b", "c"], ["e", "f", "g"], ["h", "i"], ["k", "l", "m"]],    
    textvalue:'default textvalue',    
    datevalue:'default datevalue',    
    timevalue:'default timevalue',    
    datetimevalue:'default datetimevalue',    
    multitextvalue:'default multitextvalue',    
    containsecond:true,    
    multitextselect:[1,2,0],    
    datetimeselect:'2012-5-6-11-25',    
    timeselect:'11:22:30',    
    dateselect:'2021-3-2',    
    textselect:'2'
  },
  textonchange(e) {    
    this.textvalue = e.newValue;    
    prompt.showToast({ message:"text:"+e.newValue+",newSelected:"+e.newSelected })
  },
  textoncancel(e) {    
    prompt.showToast({ message:"text: textoncancel" })
  },
  dateonchange(e) {    
    this.datevalue = e.year + "-" + e.month + "-" + e.day;    
    prompt.showToast({ message:"date:"+e.year+"-"+e.month+"-"+e.day })
  },
  dateoncancel() {    
    prompt.showToast({ message:"date: dateoncancel" })
  },
  timeonchange(e) {    
    if(this.containsecond){        
      this.timevalue=e.hour+":"+e.minute+":"+e.second;        
      prompt.showToast({ message:"时间:" + e.hour + ":" + e.minute + ":" + e.second })
    } else {        
      this.timevalue=e.hour+":"+e.minute;        
      prompt.showToast({ message:"时间:" + e.hour + ":" + e.minute })
    }},
  timeoncancel() {    
    prompt.showToast({ message:"timeoncancel" })
  },
  datetimeonchange(e) {    
    this.datetimevalue=e.year+"-"+e.month+"-"+e.day+" "+e.hour+":"+e.minute;    
    prompt.showToast({ message:"时间:"+e.month+"-"+e.day+" "+e.hour+":"+e.minute })
  },
  datetimeoncancel() {    
    prompt.showToast({ message:"datetimeoncancel" })
  },
  multitextonchange(e) {    
    this.multitextvalue=e.newValue;    
    prompt.showToast({ message:"多列文本更改" + e.newValue })
  },
  multitextoncancel() {    
    prompt.showToast({ message:"multitextoncancel" })
  },
  popup_picker() {    
    this.$element("picker_text").show();
  },
}
```

**图 1**  text<a name="zh-cn_topic_0000001173324637_fig0994231184518"></a>  
![](figures/text.png "text")

**图 2**  date<a name="zh-cn_topic_0000001173324637_fig4844164313500"></a>  


![](figures/date33.png)

**图 3**  time<a name="zh-cn_topic_0000001173324637_fig12393130145110"></a>  
![](figures/time.png "time")

**图 4**  datetime<a name="zh-cn_topic_0000001173324637_fig15761018155119"></a>  
![](figures/datetime.png "datetime")

**图 5**  multitext<a name="zh-cn_topic_0000001173324637_fig92262011524"></a>  
![](figures/multitext.png "multitext")

