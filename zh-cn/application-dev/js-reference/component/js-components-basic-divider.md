# divider<a name="ZH-CN_TOPIC_0000001209412129"></a>

-   [权限列表](#zh-cn_topic_0000001127125060_section11257113618419)
-   [子组件](#zh-cn_topic_0000001127125060_section9288143101012)
-   [属性](#zh-cn_topic_0000001127125060_section2907183951110)
-   [样式](#zh-cn_topic_0000001127125060_section5775351116)
-   [事件](#zh-cn_topic_0000001127125060_section1944813319536)
-   [方法](#zh-cn_topic_0000001127125060_section163401342195315)
-   [示例](#zh-cn_topic_0000001127125060_section230641814493)

提供分隔器组件，分隔不同内容块/内容元素。可用于列表或界面布局。

## 权限列表<a name="zh-cn_topic_0000001127125060_section11257113618419"></a>

无

## 子组件<a name="zh-cn_topic_0000001127125060_section9288143101012"></a>

不支持。

## 属性<a name="zh-cn_topic_0000001127125060_section2907183951110"></a>

除支持[通用属性](js-components-common-attributes.md#ZH-CN_TOPIC_0000001163812208)外，还支持如下属性：

<a name="zh-cn_topic_0000001127125060_table20633101642315"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001127125060_row663331618238"><th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001127125060_aa872998ac2d84843a3c5161889afffef"><a name="zh-cn_topic_0000001127125060_aa872998ac2d84843a3c5161889afffef"></a><a name="zh-cn_topic_0000001127125060_aa872998ac2d84843a3c5161889afffef"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001127125060_ab2111648ee0e4f6d881be8954e7acaab"><a name="zh-cn_topic_0000001127125060_ab2111648ee0e4f6d881be8954e7acaab"></a><a name="zh-cn_topic_0000001127125060_ab2111648ee0e4f6d881be8954e7acaab"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="10.48%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001127125060_ab377d1c90900478ea4ecab51e9a058af"><a name="zh-cn_topic_0000001127125060_ab377d1c90900478ea4ecab51e9a058af"></a><a name="zh-cn_topic_0000001127125060_ab377d1c90900478ea4ecab51e9a058af"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001127125060_p824610360217"><a name="zh-cn_topic_0000001127125060_p824610360217"></a><a name="zh-cn_topic_0000001127125060_p824610360217"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="35.76%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001127125060_a1d574a0044ed42ec8a2603bc82734232"><a name="zh-cn_topic_0000001127125060_a1d574a0044ed42ec8a2603bc82734232"></a><a name="zh-cn_topic_0000001127125060_a1d574a0044ed42ec8a2603bc82734232"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001127125060_row14446349178"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125060_p15694934121713"><a name="zh-cn_topic_0000001127125060_p15694934121713"></a><a name="zh-cn_topic_0000001127125060_p15694934121713"></a>vertical</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125060_p0694434171720"><a name="zh-cn_topic_0000001127125060_p0694434171720"></a><a name="zh-cn_topic_0000001127125060_p0694434171720"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125060_p2694103415179"><a name="zh-cn_topic_0000001127125060_p2694103415179"></a><a name="zh-cn_topic_0000001127125060_p2694103415179"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125060_p13694103471711"><a name="zh-cn_topic_0000001127125060_p13694103471711"></a><a name="zh-cn_topic_0000001127125060_p13694103471711"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125060_p1769433401719"><a name="zh-cn_topic_0000001127125060_p1769433401719"></a><a name="zh-cn_topic_0000001127125060_p1769433401719"></a>使用水平分割线还是垂直分割线，默认水平。</p>
</td>
</tr>
</tbody>
</table>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>-   不支持focusable、disabled属性。

## 样式<a name="zh-cn_topic_0000001127125060_section5775351116"></a>

仅支持如下样式：

<a name="zh-cn_topic_0000001127125060_table156669187471"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001127125060_row966601820476"><th class="cellrowborder" valign="top" width="18.209640397857694%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001127125060_p1366616188472"><a name="zh-cn_topic_0000001127125060_p1366616188472"></a><a name="zh-cn_topic_0000001127125060_p1366616188472"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="14.135424636572303%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001127125060_p26661418194711"><a name="zh-cn_topic_0000001127125060_p26661418194711"></a><a name="zh-cn_topic_0000001127125060_p26661418194711"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="22.083014537107886%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001127125060_p36661718194710"><a name="zh-cn_topic_0000001127125060_p36661718194710"></a><a name="zh-cn_topic_0000001127125060_p36661718194710"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="6.7999234889058915%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001127125060_p16666141812475"><a name="zh-cn_topic_0000001127125060_p16666141812475"></a><a name="zh-cn_topic_0000001127125060_p16666141812475"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="38.77199693955624%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001127125060_p16667718174712"><a name="zh-cn_topic_0000001127125060_p16667718174712"></a><a name="zh-cn_topic_0000001127125060_p16667718174712"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001127125060_row186671218144718"><td class="cellrowborder" valign="top" width="18.209640397857694%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125060_p666720180479"><a name="zh-cn_topic_0000001127125060_p666720180479"></a><a name="zh-cn_topic_0000001127125060_p666720180479"></a>margin</p>
</td>
<td class="cellrowborder" valign="top" width="14.135424636572303%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125060_p666714189478"><a name="zh-cn_topic_0000001127125060_p666714189478"></a><a name="zh-cn_topic_0000001127125060_p666714189478"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="22.083014537107886%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125060_p18667181834719"><a name="zh-cn_topic_0000001127125060_p18667181834719"></a><a name="zh-cn_topic_0000001127125060_p18667181834719"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="6.7999234889058915%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125060_p9667171834720"><a name="zh-cn_topic_0000001127125060_p9667171834720"></a><a name="zh-cn_topic_0000001127125060_p9667171834720"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="38.77199693955624%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125060_p8667191824717"><a name="zh-cn_topic_0000001127125060_p8667191824717"></a><a name="zh-cn_topic_0000001127125060_p8667191824717"></a>使用简写属性设置所有的外边距属性，该属性可以有1到4个值。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125060_row1758549135917"><td class="cellrowborder" valign="top" width="18.209640397857694%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125060_a70939a36b2b04dd8bec21f5bddc8637e"><a name="zh-cn_topic_0000001127125060_a70939a36b2b04dd8bec21f5bddc8637e"></a><a name="zh-cn_topic_0000001127125060_a70939a36b2b04dd8bec21f5bddc8637e"></a>margin-[left|top|right|bottom]</p>
</td>
<td class="cellrowborder" valign="top" width="14.135424636572303%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125060_ae53ac9ac370d483990e04ea9789c1e49"><a name="zh-cn_topic_0000001127125060_ae53ac9ac370d483990e04ea9789c1e49"></a><a name="zh-cn_topic_0000001127125060_ae53ac9ac370d483990e04ea9789c1e49"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="22.083014537107886%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125060_a180cd037e6174e5c82f35a3a66b6f2ec"><a name="zh-cn_topic_0000001127125060_a180cd037e6174e5c82f35a3a66b6f2ec"></a><a name="zh-cn_topic_0000001127125060_a180cd037e6174e5c82f35a3a66b6f2ec"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="6.7999234889058915%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125060_a487d09add6e54c5c89fa4f22e9318271"><a name="zh-cn_topic_0000001127125060_a487d09add6e54c5c89fa4f22e9318271"></a><a name="zh-cn_topic_0000001127125060_a487d09add6e54c5c89fa4f22e9318271"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="38.77199693955624%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125060_p696123114464"><a name="zh-cn_topic_0000001127125060_p696123114464"></a><a name="zh-cn_topic_0000001127125060_p696123114464"></a>使用简写属性设置左、上、右、下外边距属性，类型length，单位px，默认值0。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125060_row1487514596294"><td class="cellrowborder" valign="top" width="18.209640397857694%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125060_p71673109308"><a name="zh-cn_topic_0000001127125060_p71673109308"></a><a name="zh-cn_topic_0000001127125060_p71673109308"></a>color</p>
</td>
<td class="cellrowborder" valign="top" width="14.135424636572303%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125060_p516781011309"><a name="zh-cn_topic_0000001127125060_p516781011309"></a><a name="zh-cn_topic_0000001127125060_p516781011309"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="22.083014537107886%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125060_p416718104300"><a name="zh-cn_topic_0000001127125060_p416718104300"></a><a name="zh-cn_topic_0000001127125060_p416718104300"></a>#08000000</p>
</td>
<td class="cellrowborder" valign="top" width="6.7999234889058915%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125060_p1016741053017"><a name="zh-cn_topic_0000001127125060_p1016741053017"></a><a name="zh-cn_topic_0000001127125060_p1016741053017"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="38.77199693955624%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125060_p116711013301"><a name="zh-cn_topic_0000001127125060_p116711013301"></a><a name="zh-cn_topic_0000001127125060_p116711013301"></a>设置分割线颜色。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125060_row1055218083014"><td class="cellrowborder" valign="top" width="18.209640397857694%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125060_p10167710193019"><a name="zh-cn_topic_0000001127125060_p10167710193019"></a><a name="zh-cn_topic_0000001127125060_p10167710193019"></a>stroke-width</p>
</td>
<td class="cellrowborder" valign="top" width="14.135424636572303%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125060_p6167121093018"><a name="zh-cn_topic_0000001127125060_p6167121093018"></a><a name="zh-cn_topic_0000001127125060_p6167121093018"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="22.083014537107886%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125060_p31671010113017"><a name="zh-cn_topic_0000001127125060_p31671010113017"></a><a name="zh-cn_topic_0000001127125060_p31671010113017"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="6.7999234889058915%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125060_p3167181019303"><a name="zh-cn_topic_0000001127125060_p3167181019303"></a><a name="zh-cn_topic_0000001127125060_p3167181019303"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="38.77199693955624%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125060_p13167101016307"><a name="zh-cn_topic_0000001127125060_p13167101016307"></a><a name="zh-cn_topic_0000001127125060_p13167101016307"></a>设置分割线宽度。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125060_row56167193020"><td class="cellrowborder" valign="top" width="18.209640397857694%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125060_p161695103305"><a name="zh-cn_topic_0000001127125060_p161695103305"></a><a name="zh-cn_topic_0000001127125060_p161695103305"></a>display</p>
</td>
<td class="cellrowborder" valign="top" width="14.135424636572303%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125060_p34141720115716"><a name="zh-cn_topic_0000001127125060_p34141720115716"></a><a name="zh-cn_topic_0000001127125060_p34141720115716"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="22.083014537107886%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125060_p17169310133020"><a name="zh-cn_topic_0000001127125060_p17169310133020"></a><a name="zh-cn_topic_0000001127125060_p17169310133020"></a>flex</p>
</td>
<td class="cellrowborder" valign="top" width="6.7999234889058915%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125060_p3169101019308"><a name="zh-cn_topic_0000001127125060_p3169101019308"></a><a name="zh-cn_topic_0000001127125060_p3169101019308"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="38.77199693955624%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125060_p1416912102303"><a name="zh-cn_topic_0000001127125060_p1416912102303"></a><a name="zh-cn_topic_0000001127125060_p1416912102303"></a>确定分割线所产生的框的类型。值flex/none，默认值flex。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125060_row1836619303"><td class="cellrowborder" valign="top" width="18.209640397857694%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125060_p81691410143017"><a name="zh-cn_topic_0000001127125060_p81691410143017"></a><a name="zh-cn_topic_0000001127125060_p81691410143017"></a>visibility</p>
</td>
<td class="cellrowborder" valign="top" width="14.135424636572303%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125060_p51691710173018"><a name="zh-cn_topic_0000001127125060_p51691710173018"></a><a name="zh-cn_topic_0000001127125060_p51691710173018"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="22.083014537107886%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125060_p14169101053017"><a name="zh-cn_topic_0000001127125060_p14169101053017"></a><a name="zh-cn_topic_0000001127125060_p14169101053017"></a>visible</p>
</td>
<td class="cellrowborder" valign="top" width="6.7999234889058915%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125060_p1016919104306"><a name="zh-cn_topic_0000001127125060_p1016919104306"></a><a name="zh-cn_topic_0000001127125060_p1016919104306"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="38.77199693955624%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125060_p13169101011309"><a name="zh-cn_topic_0000001127125060_p13169101011309"></a><a name="zh-cn_topic_0000001127125060_p13169101011309"></a>是否显示分割线。不可见的框会占用布局。visible代表显示元素，hidden代表不显示元素。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125060_row19262114111135"><td class="cellrowborder" valign="top" width="18.209640397857694%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125060_p1126317411138"><a name="zh-cn_topic_0000001127125060_p1126317411138"></a><a name="zh-cn_topic_0000001127125060_p1126317411138"></a>line-cap</p>
</td>
<td class="cellrowborder" valign="top" width="14.135424636572303%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125060_p13140171172312"><a name="zh-cn_topic_0000001127125060_p13140171172312"></a><a name="zh-cn_topic_0000001127125060_p13140171172312"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="22.083014537107886%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125060_p926310414130"><a name="zh-cn_topic_0000001127125060_p926310414130"></a><a name="zh-cn_topic_0000001127125060_p926310414130"></a>butt</p>
</td>
<td class="cellrowborder" valign="top" width="6.7999234889058915%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125060_p172631041181314"><a name="zh-cn_topic_0000001127125060_p172631041181314"></a><a name="zh-cn_topic_0000001127125060_p172631041181314"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="38.77199693955624%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125060_p1826374117137"><a name="zh-cn_topic_0000001127125060_p1826374117137"></a><a name="zh-cn_topic_0000001127125060_p1826374117137"></a>设置分割线条的端点样式，默认为butt，可选值为：</p>
<a name="zh-cn_topic_0000001127125060_ul169886211615"></a><a name="zh-cn_topic_0000001127125060_ul169886211615"></a><ul id="zh-cn_topic_0000001127125060_ul169886211615"><li>butt：分割线两端为平行线；</li><li>round：分割线两端额外添加半圆；</li><li>square：分割线两端额外添加半方形；</li></ul>
<div class="note" id="zh-cn_topic_0000001127125060_note46927357715"><a name="zh-cn_topic_0000001127125060_note46927357715"></a><a name="zh-cn_topic_0000001127125060_note46927357715"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001127125060_p126922351571"><a name="zh-cn_topic_0000001127125060_p126922351571"></a><a name="zh-cn_topic_0000001127125060_p126922351571"></a>round和square会额外增加一个线宽的分割线长度。</p>
</div></div>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125060_row3222184412411"><td class="cellrowborder" valign="top" width="18.209640397857694%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125060_ad74a6a48aca7439e9344c18c26b4177e"><a name="zh-cn_topic_0000001127125060_ad74a6a48aca7439e9344c18c26b4177e"></a><a name="zh-cn_topic_0000001127125060_ad74a6a48aca7439e9344c18c26b4177e"></a>flex</p>
</td>
<td class="cellrowborder" valign="top" width="14.135424636572303%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125060_a2e6e5192a1534872be5fcfd9f83e3fdc"><a name="zh-cn_topic_0000001127125060_a2e6e5192a1534872be5fcfd9f83e3fdc"></a><a name="zh-cn_topic_0000001127125060_a2e6e5192a1534872be5fcfd9f83e3fdc"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="22.083014537107886%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125060_a8512eda38e25410685be8a8992890257"><a name="zh-cn_topic_0000001127125060_a8512eda38e25410685be8a8992890257"></a><a name="zh-cn_topic_0000001127125060_a8512eda38e25410685be8a8992890257"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="6.7999234889058915%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125060_p14201322964"><a name="zh-cn_topic_0000001127125060_p14201322964"></a><a name="zh-cn_topic_0000001127125060_p14201322964"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="38.77199693955624%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125060_p368291715615"><a name="zh-cn_topic_0000001127125060_p368291715615"></a><a name="zh-cn_topic_0000001127125060_p368291715615"></a>规定了分割线如何适应父组件中的可用空间。它作为一个简写属性，用来设置组件的flex-grow。</p>
<div class="note" id="zh-cn_topic_0000001127125060_note1368217171461"><a name="zh-cn_topic_0000001127125060_note1368217171461"></a><a name="zh-cn_topic_0000001127125060_note1368217171461"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001127125060_p76821817460"><a name="zh-cn_topic_0000001127125060_p76821817460"></a><a name="zh-cn_topic_0000001127125060_p76821817460"></a>仅父容器为&lt;div&gt;、&lt;list-item&gt;、&lt;tabs&gt;时生效。</p>
</div></div>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125060_row879744718418"><td class="cellrowborder" valign="top" width="18.209640397857694%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125060_a5d88cacaaf5c4f6a87390ab916b695c6"><a name="zh-cn_topic_0000001127125060_a5d88cacaaf5c4f6a87390ab916b695c6"></a><a name="zh-cn_topic_0000001127125060_a5d88cacaaf5c4f6a87390ab916b695c6"></a>flex-grow</p>
</td>
<td class="cellrowborder" valign="top" width="14.135424636572303%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125060_a2c379e3af283446da446f1631e572efd"><a name="zh-cn_topic_0000001127125060_a2c379e3af283446da446f1631e572efd"></a><a name="zh-cn_topic_0000001127125060_a2c379e3af283446da446f1631e572efd"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="22.083014537107886%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125060_aa374f6c7415a4ee48a06930d76c55be7"><a name="zh-cn_topic_0000001127125060_aa374f6c7415a4ee48a06930d76c55be7"></a><a name="zh-cn_topic_0000001127125060_aa374f6c7415a4ee48a06930d76c55be7"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="6.7999234889058915%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125060_p1335271877"><a name="zh-cn_topic_0000001127125060_p1335271877"></a><a name="zh-cn_topic_0000001127125060_p1335271877"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="38.77199693955624%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125060_p13246193876"><a name="zh-cn_topic_0000001127125060_p13246193876"></a><a name="zh-cn_topic_0000001127125060_p13246193876"></a>设置分割线的伸展因子，指定父组件容器主轴方向上剩余空间（容器本身大小减去所有flex项加起来的大小）的分配系数。0为不伸展。</p>
<div class="note" id="zh-cn_topic_0000001127125060_note62462313719"><a name="zh-cn_topic_0000001127125060_note62462313719"></a><a name="zh-cn_topic_0000001127125060_note62462313719"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001127125060_p1324610312715"><a name="zh-cn_topic_0000001127125060_p1324610312715"></a><a name="zh-cn_topic_0000001127125060_p1324610312715"></a>仅父容器为&lt;div&gt;、&lt;list-item&gt;、&lt;tabs&gt;时生效。</p>
</div></div>
<p id="zh-cn_topic_0000001127125060_p14246435713"><a name="zh-cn_topic_0000001127125060_p14246435713"></a><a name="zh-cn_topic_0000001127125060_p14246435713"></a></p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125060_row187966501419"><td class="cellrowborder" valign="top" width="18.209640397857694%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125060_ac65ef7e2b1f24a13b09c495f643168c9"><a name="zh-cn_topic_0000001127125060_ac65ef7e2b1f24a13b09c495f643168c9"></a><a name="zh-cn_topic_0000001127125060_ac65ef7e2b1f24a13b09c495f643168c9"></a>flex-shrink</p>
</td>
<td class="cellrowborder" valign="top" width="14.135424636572303%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125060_a98e7d367f0e649699892ae5bad6ade37"><a name="zh-cn_topic_0000001127125060_a98e7d367f0e649699892ae5bad6ade37"></a><a name="zh-cn_topic_0000001127125060_a98e7d367f0e649699892ae5bad6ade37"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="22.083014537107886%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125060_a422d978368814d12a33201cb839060ee"><a name="zh-cn_topic_0000001127125060_a422d978368814d12a33201cb839060ee"></a><a name="zh-cn_topic_0000001127125060_a422d978368814d12a33201cb839060ee"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="6.7999234889058915%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125060_p164884516713"><a name="zh-cn_topic_0000001127125060_p164884516713"></a><a name="zh-cn_topic_0000001127125060_p164884516713"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="38.77199693955624%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125060_p13640114214710"><a name="zh-cn_topic_0000001127125060_p13640114214710"></a><a name="zh-cn_topic_0000001127125060_p13640114214710"></a>设置分割线的收缩因子，flex元素仅在默认宽度之和大于容器的时候才会发生收缩，0为不收缩。</p>
<div class="note" id="zh-cn_topic_0000001127125060_note364074212713"><a name="zh-cn_topic_0000001127125060_note364074212713"></a><a name="zh-cn_topic_0000001127125060_note364074212713"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001127125060_p186406427711"><a name="zh-cn_topic_0000001127125060_p186406427711"></a><a name="zh-cn_topic_0000001127125060_p186406427711"></a>仅父容器为&lt;div&gt;、&lt;list-item&gt;、&lt;tabs&gt;时生效。</p>
</div></div>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125060_row438316531843"><td class="cellrowborder" valign="top" width="18.209640397857694%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125060_a82c323a994634032963169eeee1a55e4"><a name="zh-cn_topic_0000001127125060_a82c323a994634032963169eeee1a55e4"></a><a name="zh-cn_topic_0000001127125060_a82c323a994634032963169eeee1a55e4"></a>flex-basis</p>
</td>
<td class="cellrowborder" valign="top" width="14.135424636572303%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125060_p1148910787"><a name="zh-cn_topic_0000001127125060_p1148910787"></a><a name="zh-cn_topic_0000001127125060_p1148910787"></a>&lt;length&gt;</p>
<p id="zh-cn_topic_0000001127125060_a43613cf0c2184c0d8b44e8d292f6edb7"><a name="zh-cn_topic_0000001127125060_a43613cf0c2184c0d8b44e8d292f6edb7"></a><a name="zh-cn_topic_0000001127125060_a43613cf0c2184c0d8b44e8d292f6edb7"></a></p>
</td>
<td class="cellrowborder" valign="top" width="22.083014537107886%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125060_ab9e1c7dc25f840e58993af05c1d32109"><a name="zh-cn_topic_0000001127125060_ab9e1c7dc25f840e58993af05c1d32109"></a><a name="zh-cn_topic_0000001127125060_ab9e1c7dc25f840e58993af05c1d32109"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="6.7999234889058915%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125060_p124162561774"><a name="zh-cn_topic_0000001127125060_p124162561774"></a><a name="zh-cn_topic_0000001127125060_p124162561774"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="38.77199693955624%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125060_p192811541574"><a name="zh-cn_topic_0000001127125060_p192811541574"></a><a name="zh-cn_topic_0000001127125060_p192811541574"></a>设置分割线在主轴方向上的初始大小。</p>
<div class="note" id="zh-cn_topic_0000001127125060_note162817541279"><a name="zh-cn_topic_0000001127125060_note162817541279"></a><a name="zh-cn_topic_0000001127125060_note162817541279"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001127125060_p1928115418713"><a name="zh-cn_topic_0000001127125060_p1928115418713"></a><a name="zh-cn_topic_0000001127125060_p1928115418713"></a>仅父容器为&lt;div&gt;、&lt;list-item&gt;、&lt;tabs&gt;时生效。</p>
</div></div>
</td>
</tr>
</tbody>
</table>

## 事件<a name="zh-cn_topic_0000001127125060_section1944813319536"></a>

不支持。

## 方法<a name="zh-cn_topic_0000001127125060_section163401342195315"></a>

不支持。

## 示例<a name="zh-cn_topic_0000001127125060_section230641814493"></a>

```
<!-- xxx.hml -->
<div class="container">   
  <div class="content">        
    <divider class="divider" vertical="false"></divider>    
  </div>
</div>
```

```
/* xxx.css */
.container {    
  margin: 20px;
  flex-direction:column;
  width:100%;
  height:100%;
  align-items:center;
}
.content{    
  width:80%;
  height:40%;
  border:1px solid #000000;
  align-items: center;
  justify-content: center;
  flex-direction:column;
}
.divider {    
  margin: 10px;
  color: #ff0000ff;
  stroke-width: 3px;
  line-cap: round;
}
```

![](figures/1.jpg)

