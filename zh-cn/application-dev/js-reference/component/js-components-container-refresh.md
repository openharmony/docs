# refresh<a name="ZH-CN_TOPIC_0000001209210699"></a>

-   [权限列表](#zh-cn_topic_0000001173164669_section11257113618419)
-   [子组件](#zh-cn_topic_0000001173164669_section9288143101012)
-   [属性](#zh-cn_topic_0000001173164669_section2907183951110)
-   [样式](#zh-cn_topic_0000001173164669_section1893981522413)
-   [事件](#zh-cn_topic_0000001173164669_section3892191911214)
-   [方法](#zh-cn_topic_0000001173164669_section2279124532420)
-   [示例](#zh-cn_topic_0000001173164669_section1050103282219)

下拉刷新容器。

## 权限列表<a name="zh-cn_topic_0000001173164669_section11257113618419"></a>

无

## 子组件<a name="zh-cn_topic_0000001173164669_section9288143101012"></a>

支持。

## 属性<a name="zh-cn_topic_0000001173164669_section2907183951110"></a>

除支持[通用属性](js-components-common-attributes.md#ZH-CN_TOPIC_0000001163812208)外，还支持如下属性：

<a name="zh-cn_topic_0000001173164669_table20633101642315"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001173164669_row663331618238"><th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001173164669_aa872998ac2d84843a3c5161889afffef"><a name="zh-cn_topic_0000001173164669_aa872998ac2d84843a3c5161889afffef"></a><a name="zh-cn_topic_0000001173164669_aa872998ac2d84843a3c5161889afffef"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001173164669_ab2111648ee0e4f6d881be8954e7acaab"><a name="zh-cn_topic_0000001173164669_ab2111648ee0e4f6d881be8954e7acaab"></a><a name="zh-cn_topic_0000001173164669_ab2111648ee0e4f6d881be8954e7acaab"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="10.48%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001173164669_ab377d1c90900478ea4ecab51e9a058af"><a name="zh-cn_topic_0000001173164669_ab377d1c90900478ea4ecab51e9a058af"></a><a name="zh-cn_topic_0000001173164669_ab377d1c90900478ea4ecab51e9a058af"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001173164669_p824610360217"><a name="zh-cn_topic_0000001173164669_p824610360217"></a><a name="zh-cn_topic_0000001173164669_p824610360217"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="35.76%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001173164669_a1d574a0044ed42ec8a2603bc82734232"><a name="zh-cn_topic_0000001173164669_a1d574a0044ed42ec8a2603bc82734232"></a><a name="zh-cn_topic_0000001173164669_a1d574a0044ed42ec8a2603bc82734232"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001173164669_row9157554193514"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173164669_p178012583610"><a name="zh-cn_topic_0000001173164669_p178012583610"></a><a name="zh-cn_topic_0000001173164669_p178012583610"></a>offset</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173164669_p1880112512360"><a name="zh-cn_topic_0000001173164669_p1880112512360"></a><a name="zh-cn_topic_0000001173164669_p1880112512360"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173164669_p4801551360"><a name="zh-cn_topic_0000001173164669_p4801551360"></a><a name="zh-cn_topic_0000001173164669_p4801551360"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173164669_p880112519366"><a name="zh-cn_topic_0000001173164669_p880112519366"></a><a name="zh-cn_topic_0000001173164669_p880112519366"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173164669_p380114563617"><a name="zh-cn_topic_0000001173164669_p380114563617"></a><a name="zh-cn_topic_0000001173164669_p380114563617"></a>刷新组件静止时距离父组件顶部的距离。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164669_row125231450153511"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173164669_p1380145163611"><a name="zh-cn_topic_0000001173164669_p1380145163611"></a><a name="zh-cn_topic_0000001173164669_p1380145163611"></a>refreshing</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173164669_p108011457365"><a name="zh-cn_topic_0000001173164669_p108011457365"></a><a name="zh-cn_topic_0000001173164669_p108011457365"></a><span>boolean</span></p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173164669_p128011554364"><a name="zh-cn_topic_0000001173164669_p128011554364"></a><a name="zh-cn_topic_0000001173164669_p128011554364"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173164669_p480119563613"><a name="zh-cn_topic_0000001173164669_p480119563613"></a><a name="zh-cn_topic_0000001173164669_p480119563613"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173164669_p28011856362"><a name="zh-cn_topic_0000001173164669_p28011856362"></a><a name="zh-cn_topic_0000001173164669_p28011856362"></a>用于标识刷新组件当前是否正在刷新。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164669_row1752375015356"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173164669_p1480116513611"><a name="zh-cn_topic_0000001173164669_p1480116513611"></a><a name="zh-cn_topic_0000001173164669_p1480116513611"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173164669_p11801105143616"><a name="zh-cn_topic_0000001173164669_p11801105143616"></a><a name="zh-cn_topic_0000001173164669_p11801105143616"></a><span>string</span></p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173164669_p198028518361"><a name="zh-cn_topic_0000001173164669_p198028518361"></a><a name="zh-cn_topic_0000001173164669_p198028518361"></a>auto</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173164669_p680275173619"><a name="zh-cn_topic_0000001173164669_p680275173619"></a><a name="zh-cn_topic_0000001173164669_p680275173619"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173164669_p9802205183619"><a name="zh-cn_topic_0000001173164669_p9802205183619"></a><a name="zh-cn_topic_0000001173164669_p9802205183619"></a>设置组件刷新时的动效。两个可选值，不支持动态修改。</p>
<a name="zh-cn_topic_0000001173164669_ul0802951367"></a><a name="zh-cn_topic_0000001173164669_ul0802951367"></a><ul id="zh-cn_topic_0000001173164669_ul0802951367"><li>auto: 默认效果，列表界面拉到顶后，列表不移动，下拉后有转圈弹出。</li><li>pulldown: 列表界面拉到顶后，可以继续往下滑动一段距离触发刷新，刷新完成后有回弹效果（如果子组件含有list，防止下拉效果冲突，需将list的scrolleffect设置为no）。</li></ul>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164669_row2303174523514"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173164669_p17802951363"><a name="zh-cn_topic_0000001173164669_p17802951363"></a><a name="zh-cn_topic_0000001173164669_p17802951363"></a>lasttime</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173164669_p580235153616"><a name="zh-cn_topic_0000001173164669_p580235153616"></a><a name="zh-cn_topic_0000001173164669_p580235153616"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173164669_p198026510362"><a name="zh-cn_topic_0000001173164669_p198026510362"></a><a name="zh-cn_topic_0000001173164669_p198026510362"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173164669_p118029511366"><a name="zh-cn_topic_0000001173164669_p118029511366"></a><a name="zh-cn_topic_0000001173164669_p118029511366"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173164669_p1880211583612"><a name="zh-cn_topic_0000001173164669_p1880211583612"></a><a name="zh-cn_topic_0000001173164669_p1880211583612"></a>是否显示上次更新时间，字符串格式为：“上次更新时间：XXXX ”，XXXX 按照时间日期显示规范显示，不可动态修改（建议type为pulldown时使用，固定距离位于内容下拉区域底部，使用时注意offset属性设置，防止出现重叠）。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164669_row119861446131017"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173164669_p1098734616104"><a name="zh-cn_topic_0000001173164669_p1098734616104"></a><a name="zh-cn_topic_0000001173164669_p1098734616104"></a>timeoffset<sup id="zh-cn_topic_0000001173164669_sup2158132916489"><a name="zh-cn_topic_0000001173164669_sup2158132916489"></a><a name="zh-cn_topic_0000001173164669_sup2158132916489"></a><span>6+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173164669_p59872046111017"><a name="zh-cn_topic_0000001173164669_p59872046111017"></a><a name="zh-cn_topic_0000001173164669_p59872046111017"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173164669_p1198724661014"><a name="zh-cn_topic_0000001173164669_p1198724661014"></a><a name="zh-cn_topic_0000001173164669_p1198724661014"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173164669_p298764616106"><a name="zh-cn_topic_0000001173164669_p298764616106"></a><a name="zh-cn_topic_0000001173164669_p298764616106"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173164669_p12987154619106"><a name="zh-cn_topic_0000001173164669_p12987154619106"></a><a name="zh-cn_topic_0000001173164669_p12987154619106"></a>设置更新时间距离父组件顶部的距离。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164669_row08492042113518"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173164669_p11802105143616"><a name="zh-cn_topic_0000001173164669_p11802105143616"></a><a name="zh-cn_topic_0000001173164669_p11802105143616"></a>friction</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173164669_p1180265153613"><a name="zh-cn_topic_0000001173164669_p1180265153613"></a><a name="zh-cn_topic_0000001173164669_p1180265153613"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173164669_p128026563620"><a name="zh-cn_topic_0000001173164669_p128026563620"></a><a name="zh-cn_topic_0000001173164669_p128026563620"></a>42</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173164669_p11802185153615"><a name="zh-cn_topic_0000001173164669_p11802185153615"></a><a name="zh-cn_topic_0000001173164669_p11802185153615"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173164669_p118021351362"><a name="zh-cn_topic_0000001173164669_p118021351362"></a><a name="zh-cn_topic_0000001173164669_p118021351362"></a>下拉摩擦系数，取值范围：0-100，数值越大refresh组件跟手性高，数值越小refresh跟手性低。</p>
<div class="note" id="zh-cn_topic_0000001173164669_note204304260349"><a name="zh-cn_topic_0000001173164669_note204304260349"></a><a name="zh-cn_topic_0000001173164669_note204304260349"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001173164669_p1343012264345"><a name="zh-cn_topic_0000001173164669_p1343012264345"></a><a name="zh-cn_topic_0000001173164669_p1343012264345"></a>仅手机、平板和智能穿戴设备支持。</p>
</div></div>
</td>
</tr>
</tbody>
</table>

## 样式<a name="zh-cn_topic_0000001173164669_section1893981522413"></a>

除支持[通用样式](js-components-common-styles.md#ZH-CN_TOPIC_0000001163932190)外，还支持如下样式：

<a name="zh-cn_topic_0000001173164669_table1493916152248"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001173164669_row16940141532414"><th class="cellrowborder" valign="top" width="25.03%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001173164669_p994031519247"><a name="zh-cn_topic_0000001173164669_p994031519247"></a><a name="zh-cn_topic_0000001173164669_p994031519247"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="18.86%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001173164669_p179406154245"><a name="zh-cn_topic_0000001173164669_p179406154245"></a><a name="zh-cn_topic_0000001173164669_p179406154245"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="10.76%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001173164669_p15940161517242"><a name="zh-cn_topic_0000001173164669_p15940161517242"></a><a name="zh-cn_topic_0000001173164669_p15940161517242"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.449999999999999%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001173164669_p1694061552419"><a name="zh-cn_topic_0000001173164669_p1694061552419"></a><a name="zh-cn_topic_0000001173164669_p1694061552419"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="37.9%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001173164669_p29401815132419"><a name="zh-cn_topic_0000001173164669_p29401815132419"></a><a name="zh-cn_topic_0000001173164669_p29401815132419"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001173164669_row109404152249"><td class="cellrowborder" valign="top" width="25.03%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173164669_p994017159246"><a name="zh-cn_topic_0000001173164669_p994017159246"></a><a name="zh-cn_topic_0000001173164669_p994017159246"></a>background-color</p>
</td>
<td class="cellrowborder" valign="top" width="18.86%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173164669_p12940201582418"><a name="zh-cn_topic_0000001173164669_p12940201582418"></a><a name="zh-cn_topic_0000001173164669_p12940201582418"></a><span>&lt;</span><span>color</span><span>&gt;</span></p>
</td>
<td class="cellrowborder" valign="top" width="10.76%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173164669_p16940215132418"><a name="zh-cn_topic_0000001173164669_p16940215132418"></a><a name="zh-cn_topic_0000001173164669_p16940215132418"></a>white</p>
</td>
<td class="cellrowborder" valign="top" width="7.449999999999999%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173164669_p14940151592415"><a name="zh-cn_topic_0000001173164669_p14940151592415"></a><a name="zh-cn_topic_0000001173164669_p14940151592415"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="37.9%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173164669_p12940181519248"><a name="zh-cn_topic_0000001173164669_p12940181519248"></a><a name="zh-cn_topic_0000001173164669_p12940181519248"></a>用于设置刷新组件的背景颜色。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164669_row169401315182419"><td class="cellrowborder" valign="top" width="25.03%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173164669_p69401415152410"><a name="zh-cn_topic_0000001173164669_p69401415152410"></a><a name="zh-cn_topic_0000001173164669_p69401415152410"></a>progress-color</p>
</td>
<td class="cellrowborder" valign="top" width="18.86%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173164669_p16940161522412"><a name="zh-cn_topic_0000001173164669_p16940161522412"></a><a name="zh-cn_topic_0000001173164669_p16940161522412"></a><span>&lt;</span><span>color</span><span>&gt;</span></p>
</td>
<td class="cellrowborder" valign="top" width="10.76%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173164669_p2940171518246"><a name="zh-cn_topic_0000001173164669_p2940171518246"></a><a name="zh-cn_topic_0000001173164669_p2940171518246"></a>black</p>
</td>
<td class="cellrowborder" valign="top" width="7.449999999999999%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173164669_p594041514245"><a name="zh-cn_topic_0000001173164669_p594041514245"></a><a name="zh-cn_topic_0000001173164669_p594041514245"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="37.9%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173164669_p169402151243"><a name="zh-cn_topic_0000001173164669_p169402151243"></a><a name="zh-cn_topic_0000001173164669_p169402151243"></a>用于设置刷新组件的loading颜色。</p>
</td>
</tr>
</tbody>
</table>

## 事件<a name="zh-cn_topic_0000001173164669_section3892191911214"></a>

仅支持如下事件：

<a name="zh-cn_topic_0000001173164669_table71957715020"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001173164669_row4224147104"><th class="cellrowborder" valign="top" width="18.459999999999997%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173164669_p11224575017"><a name="zh-cn_topic_0000001173164669_p11224575017"></a><a name="zh-cn_topic_0000001173164669_p11224575017"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="30.79%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173164669_p13225377018"><a name="zh-cn_topic_0000001173164669_p13225377018"></a><a name="zh-cn_topic_0000001173164669_p13225377018"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="50.74999999999999%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173164669_p19225197001"><a name="zh-cn_topic_0000001173164669_p19225197001"></a><a name="zh-cn_topic_0000001173164669_p19225197001"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001173164669_row9225278016"><td class="cellrowborder" valign="top" width="18.459999999999997%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164669_p6225187706"><a name="zh-cn_topic_0000001173164669_p6225187706"></a><a name="zh-cn_topic_0000001173164669_p6225187706"></a>refresh</p>
</td>
<td class="cellrowborder" valign="top" width="30.79%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164669_p1422514714013"><a name="zh-cn_topic_0000001173164669_p1422514714013"></a><a name="zh-cn_topic_0000001173164669_p1422514714013"></a>{ refreshing: refreshingValue }</p>
</td>
<td class="cellrowborder" valign="top" width="50.74999999999999%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164669_p15225575017"><a name="zh-cn_topic_0000001173164669_p15225575017"></a><a name="zh-cn_topic_0000001173164669_p15225575017"></a>下拉刷新状态变化时触发。可能值：</p>
<a name="zh-cn_topic_0000001173164669_ul96951626943"></a><a name="zh-cn_topic_0000001173164669_ul96951626943"></a><ul id="zh-cn_topic_0000001173164669_ul96951626943"><li>false：当前处于下拉刷新过程中。</li><li>true：当前未处于下拉刷新过程中。</li></ul>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164669_row13275847193920"><td class="cellrowborder" valign="top" width="18.459999999999997%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164669_p42761147173920"><a name="zh-cn_topic_0000001173164669_p42761147173920"></a><a name="zh-cn_topic_0000001173164669_p42761147173920"></a>pulldown</p>
</td>
<td class="cellrowborder" valign="top" width="30.79%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164669_p227664711392"><a name="zh-cn_topic_0000001173164669_p227664711392"></a><a name="zh-cn_topic_0000001173164669_p227664711392"></a>{ state: string }</p>
</td>
<td class="cellrowborder" valign="top" width="50.74999999999999%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164669_p527644753917"><a name="zh-cn_topic_0000001173164669_p527644753917"></a><a name="zh-cn_topic_0000001173164669_p527644753917"></a>下拉开始和松手时触发。可能值：</p>
<a name="zh-cn_topic_0000001173164669_ul225113709"></a><a name="zh-cn_topic_0000001173164669_ul225113709"></a><ul id="zh-cn_topic_0000001173164669_ul225113709"><li>start：表示开始下拉。</li><li>end：表示结束下拉。</li></ul>
</td>
</tr>
</tbody>
</table>

## 方法<a name="zh-cn_topic_0000001173164669_section2279124532420"></a>

不支持[通用方法](js-components-common-methods.md#ZH-CN_TOPIC_0000001209252157)。

## 示例<a name="zh-cn_topic_0000001173164669_section1050103282219"></a>

```
<!-- xxx.hml -->
<div class="container">
  <refresh refreshing="{{fresh}}" onrefresh="refresh">
    <list class="list" scrolleffect="no">
      <list-item class="listitem" for="list">
        <div class="content">
          <text class="text">{{$item}}</text>
        </div>
      </list-item>
    </list>
  </refresh>
</div>
```

```
/* xxx.css */
.container {
  flex-direction: column;
  align-items: center;
  width: 100%;
  height: 100%;
}

.list {
  width: 100%;
  height: 100%;
}

.listitem {
  width: 100%;
  height: 150px;
}

.content {
  width: 100%;
  height: 100%;
  flex-direction: column;
  align-items: center;
  justify-content: center;
}

.text {
  font-size: 35px;
  font-weight: bold;
}
```

```
// xxx.js
import prompt from '@system.prompt';
export default {
  data: {
    list:[],
    fresh:false
  },
  onInit() {
    this.list = [];
    for (var i = 0; i <= 3; i++) {
      var item = '列表元素' + i;
      this.list.push(item);
    }
  },
  refresh: function (e) {
    prompt.showToast({
      message: '刷新中...'
    })
    var that = this;
    that.fresh = e.refreshing;
    setTimeout(function () {
      that.fresh = false;
      var addItem = '更新元素';
      that.list.unshift(addItem);
      prompt.showToast({
        message: '刷新完成!'
      })
    }, 2000)
  }
}
```

![](figures/zh-cn_image_0000001150719520.gif)

