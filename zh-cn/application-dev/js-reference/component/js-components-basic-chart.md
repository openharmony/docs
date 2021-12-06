# chart<a name="ZH-CN_TOPIC_0000001163932200"></a>

图表组件，用于呈现线形图、柱状图、量规图界面。

## 权限列表<a name="zh-cn_topic_0000001127125088_section11257113618419"></a>

无

## 子组件<a name="zh-cn_topic_0000001127125088_section9288143101012"></a>

不支持。

## 属性<a name="zh-cn_topic_0000001127125088_section2907183951110"></a>

除支持[通用属性](js-components-common-attributes.md)外，还支持如下属性：

<a name="zh-cn_topic_0000001127125088_table20633101642315"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001127125088_row663331618238"><th class="cellrowborder" valign="top" width="19.56%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001127125088_aa872998ac2d84843a3c5161889afffef"><a name="zh-cn_topic_0000001127125088_aa872998ac2d84843a3c5161889afffef"></a><a name="zh-cn_topic_0000001127125088_aa872998ac2d84843a3c5161889afffef"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="13.62%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001127125088_ab2111648ee0e4f6d881be8954e7acaab"><a name="zh-cn_topic_0000001127125088_ab2111648ee0e4f6d881be8954e7acaab"></a><a name="zh-cn_topic_0000001127125088_ab2111648ee0e4f6d881be8954e7acaab"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="10.72%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001127125088_ab377d1c90900478ea4ecab51e9a058af"><a name="zh-cn_topic_0000001127125088_ab377d1c90900478ea4ecab51e9a058af"></a><a name="zh-cn_topic_0000001127125088_ab377d1c90900478ea4ecab51e9a058af"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="8.43%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001127125088_p824610360217"><a name="zh-cn_topic_0000001127125088_p824610360217"></a><a name="zh-cn_topic_0000001127125088_p824610360217"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="47.67%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001127125088_a1d574a0044ed42ec8a2603bc82734232"><a name="zh-cn_topic_0000001127125088_a1d574a0044ed42ec8a2603bc82734232"></a><a name="zh-cn_topic_0000001127125088_a1d574a0044ed42ec8a2603bc82734232"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001127125088_row176434366222"><td class="cellrowborder" valign="top" width="19.56%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125088_p157531437142216"><a name="zh-cn_topic_0000001127125088_p157531437142216"></a><a name="zh-cn_topic_0000001127125088_p157531437142216"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="13.62%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125088_p975314374228"><a name="zh-cn_topic_0000001127125088_p975314374228"></a><a name="zh-cn_topic_0000001127125088_p975314374228"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.72%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125088_p2753113711229"><a name="zh-cn_topic_0000001127125088_p2753113711229"></a><a name="zh-cn_topic_0000001127125088_p2753113711229"></a>line</p>
</td>
<td class="cellrowborder" valign="top" width="8.43%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125088_p117532375222"><a name="zh-cn_topic_0000001127125088_p117532375222"></a><a name="zh-cn_topic_0000001127125088_p117532375222"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.67%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125088_p12753143712225"><a name="zh-cn_topic_0000001127125088_p12753143712225"></a><a name="zh-cn_topic_0000001127125088_p12753143712225"></a>设置图表类型（不支持动态修改），可选项有：</p>
<a name="zh-cn_topic_0000001127125088_ul2754143714229"></a><a name="zh-cn_topic_0000001127125088_ul2754143714229"></a><ul id="zh-cn_topic_0000001127125088_ul2754143714229"><li>bar：柱状图。</li><li>line：线形图。</li><li>gauge：量规图。</li><li>progress<sup id="zh-cn_topic_0000001127125088_sup116561549162915"><a name="zh-cn_topic_0000001127125088_sup116561549162915"></a><a name="zh-cn_topic_0000001127125088_sup116561549162915"></a><span>5+</span></sup>：进度类圆形图表。</li><li>loading<sup id="zh-cn_topic_0000001127125088_sup1246145116541"><a name="zh-cn_topic_0000001127125088_sup1246145116541"></a><a name="zh-cn_topic_0000001127125088_sup1246145116541"></a><span>5+</span></sup>：加载类圆形图表。</li><li>rainbow<sup id="zh-cn_topic_0000001127125088_sup13727185218542"><a name="zh-cn_topic_0000001127125088_sup13727185218542"></a><a name="zh-cn_topic_0000001127125088_sup13727185218542"></a><span>5+</span></sup>：占比类圆形图表。</li></ul>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125088_row38691133172215"><td class="cellrowborder" valign="top" width="19.56%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125088_p4754173712219"><a name="zh-cn_topic_0000001127125088_p4754173712219"></a><a name="zh-cn_topic_0000001127125088_p4754173712219"></a>options</p>
</td>
<td class="cellrowborder" valign="top" width="13.62%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125088_p1675423715225"><a name="zh-cn_topic_0000001127125088_p1675423715225"></a><a name="zh-cn_topic_0000001127125088_p1675423715225"></a><a href="#zh-cn_topic_0000001127125088_table12775365017">ChartOptions</a></p>
</td>
<td class="cellrowborder" valign="top" width="10.72%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125088_p27541437112214"><a name="zh-cn_topic_0000001127125088_p27541437112214"></a><a name="zh-cn_topic_0000001127125088_p27541437112214"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.43%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125088_p1475493712214"><a name="zh-cn_topic_0000001127125088_p1475493712214"></a><a name="zh-cn_topic_0000001127125088_p1475493712214"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.67%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125088_p19754143732218"><a name="zh-cn_topic_0000001127125088_p19754143732218"></a><a name="zh-cn_topic_0000001127125088_p19754143732218"></a>图表参数设置，柱状图和线形图必须设置参数设置，量规图不生效。可以设置x轴、y轴的最小值、最大值、刻度数、是否显示，线条宽度、是否平滑等。（不支持动态修改）</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125088_row1541629182218"><td class="cellrowborder" valign="top" width="19.56%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125088_p57547371229"><a name="zh-cn_topic_0000001127125088_p57547371229"></a><a name="zh-cn_topic_0000001127125088_p57547371229"></a>datasets</p>
</td>
<td class="cellrowborder" valign="top" width="13.62%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125088_p117541437172215"><a name="zh-cn_topic_0000001127125088_p117541437172215"></a><a name="zh-cn_topic_0000001127125088_p117541437172215"></a>Array&lt;<a href="#zh-cn_topic_0000001127125088_table13810518157">ChartDataset</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.72%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125088_p7754203711221"><a name="zh-cn_topic_0000001127125088_p7754203711221"></a><a name="zh-cn_topic_0000001127125088_p7754203711221"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.43%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125088_p18754183732216"><a name="zh-cn_topic_0000001127125088_p18754183732216"></a><a name="zh-cn_topic_0000001127125088_p18754183732216"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.67%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125088_p775483772214"><a name="zh-cn_topic_0000001127125088_p775483772214"></a><a name="zh-cn_topic_0000001127125088_p775483772214"></a>数据集合，柱状图和线形图必须设置数据集合，量规图不生效。可以设置多条数据集及其背景色。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125088_row28045213017"><td class="cellrowborder" valign="top" width="19.56%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125088_p18811552104"><a name="zh-cn_topic_0000001127125088_p18811552104"></a><a name="zh-cn_topic_0000001127125088_p18811552104"></a>segments<sup id="zh-cn_topic_0000001127125088_sup567222913217"><a name="zh-cn_topic_0000001127125088_sup567222913217"></a><a name="zh-cn_topic_0000001127125088_sup567222913217"></a><span>5+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="13.62%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125088_p481105219011"><a name="zh-cn_topic_0000001127125088_p481105219011"></a><a name="zh-cn_topic_0000001127125088_p481105219011"></a><a href="#zh-cn_topic_0000001127125088_table2596183616210">DataSegment</a> | Array&lt;<a href="#zh-cn_topic_0000001127125088_table2596183616210">DataSegment</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.72%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125088_p188135220013"><a name="zh-cn_topic_0000001127125088_p188135220013"></a><a name="zh-cn_topic_0000001127125088_p188135220013"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.43%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125088_p78112529019"><a name="zh-cn_topic_0000001127125088_p78112529019"></a><a name="zh-cn_topic_0000001127125088_p78112529019"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.67%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125088_p1455632813277"><a name="zh-cn_topic_0000001127125088_p1455632813277"></a><a name="zh-cn_topic_0000001127125088_p1455632813277"></a>进度类、加载类和占比类圆形图表使用的数据结构。</p>
<p id="zh-cn_topic_0000001127125088_p19327195813510"><a name="zh-cn_topic_0000001127125088_p19327195813510"></a><a name="zh-cn_topic_0000001127125088_p19327195813510"></a>DataSegment针对进度类和加载类圆形图表使用，</p>
<p id="zh-cn_topic_0000001127125088_p14326258457"><a name="zh-cn_topic_0000001127125088_p14326258457"></a><a name="zh-cn_topic_0000001127125088_p14326258457"></a>Array&lt;<a href="#zh-cn_topic_0000001127125088_table2596183616210">DataSegment</a>&gt;针对占比类图标使用，DataSegment最多9个。</p>
<div class="note" id="zh-cn_topic_0000001127125088_note74451328478"><a name="zh-cn_topic_0000001127125088_note74451328478"></a><a name="zh-cn_topic_0000001127125088_note74451328478"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001127125088_p1744552174711"><a name="zh-cn_topic_0000001127125088_p1744552174711"></a><a name="zh-cn_topic_0000001127125088_p1744552174711"></a>仅手机和平板设备支持。</p>
</div></div>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125088_row132072752211"><td class="cellrowborder" valign="top" width="19.56%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125088_p1720712712227"><a name="zh-cn_topic_0000001127125088_p1720712712227"></a><a name="zh-cn_topic_0000001127125088_p1720712712227"></a>effects<sup id="zh-cn_topic_0000001127125088_sup98541850278"><a name="zh-cn_topic_0000001127125088_sup98541850278"></a><a name="zh-cn_topic_0000001127125088_sup98541850278"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="13.62%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125088_p520815752212"><a name="zh-cn_topic_0000001127125088_p520815752212"></a><a name="zh-cn_topic_0000001127125088_p520815752212"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.72%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125088_p220877132211"><a name="zh-cn_topic_0000001127125088_p220877132211"></a><a name="zh-cn_topic_0000001127125088_p220877132211"></a>true</p>
</td>
<td class="cellrowborder" valign="top" width="8.43%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125088_p1820820719229"><a name="zh-cn_topic_0000001127125088_p1820820719229"></a><a name="zh-cn_topic_0000001127125088_p1820820719229"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.67%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125088_p92085712225"><a name="zh-cn_topic_0000001127125088_p92085712225"></a><a name="zh-cn_topic_0000001127125088_p92085712225"></a>是否开启占比类、进度类圆形图表特效。</p>
<div class="note" id="zh-cn_topic_0000001127125088_note15640931164717"><a name="zh-cn_topic_0000001127125088_note15640931164717"></a><a name="zh-cn_topic_0000001127125088_note15640931164717"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001127125088_p2064014318476"><a name="zh-cn_topic_0000001127125088_p2064014318476"></a><a name="zh-cn_topic_0000001127125088_p2064014318476"></a>仅手机和平板设备支持。</p>
</div></div>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125088_row1133155620405"><td class="cellrowborder" valign="top" width="19.56%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125088_p3133956174018"><a name="zh-cn_topic_0000001127125088_p3133956174018"></a><a name="zh-cn_topic_0000001127125088_p3133956174018"></a>animationduration<sup id="zh-cn_topic_0000001127125088_sup1079943994111"><a name="zh-cn_topic_0000001127125088_sup1079943994111"></a><a name="zh-cn_topic_0000001127125088_sup1079943994111"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="13.62%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125088_p81331564406"><a name="zh-cn_topic_0000001127125088_p81331564406"></a><a name="zh-cn_topic_0000001127125088_p81331564406"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.72%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125088_p21331356194015"><a name="zh-cn_topic_0000001127125088_p21331356194015"></a><a name="zh-cn_topic_0000001127125088_p21331356194015"></a>3000</p>
</td>
<td class="cellrowborder" valign="top" width="8.43%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125088_p6133256124018"><a name="zh-cn_topic_0000001127125088_p6133256124018"></a><a name="zh-cn_topic_0000001127125088_p6133256124018"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.67%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125088_p181331564408"><a name="zh-cn_topic_0000001127125088_p181331564408"></a><a name="zh-cn_topic_0000001127125088_p181331564408"></a>设置占比类圆形图表展开动画时长，单位为ms。</p>
<div class="note" id="zh-cn_topic_0000001127125088_note12117134774716"><a name="zh-cn_topic_0000001127125088_note12117134774716"></a><a name="zh-cn_topic_0000001127125088_note12117134774716"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001127125088_p12117124720471"><a name="zh-cn_topic_0000001127125088_p12117124720471"></a><a name="zh-cn_topic_0000001127125088_p12117124720471"></a>仅手机和平板设备支持。</p>
</div></div>
</td>
</tr>
</tbody>
</table>

**表 1**  ChartOptions

<a name="zh-cn_topic_0000001127125088_table12775365017"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001127125088_row6277153195013"><th class="cellrowborder" valign="top" width="16.3%" id="mcps1.2.6.1.1"><p id="zh-cn_topic_0000001127125088_p1192913820507"><a name="zh-cn_topic_0000001127125088_p1192913820507"></a><a name="zh-cn_topic_0000001127125088_p1192913820507"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="11.24%" id="mcps1.2.6.1.2"><p id="zh-cn_topic_0000001127125088_p2929188125011"><a name="zh-cn_topic_0000001127125088_p2929188125011"></a><a name="zh-cn_topic_0000001127125088_p2929188125011"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="8.690000000000001%" id="mcps1.2.6.1.3"><p id="zh-cn_topic_0000001127125088_p6929688508"><a name="zh-cn_topic_0000001127125088_p6929688508"></a><a name="zh-cn_topic_0000001127125088_p6929688508"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.7299999999999995%" id="mcps1.2.6.1.4"><p id="zh-cn_topic_0000001127125088_p1392938165014"><a name="zh-cn_topic_0000001127125088_p1392938165014"></a><a name="zh-cn_topic_0000001127125088_p1392938165014"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="56.04%" id="mcps1.2.6.1.5"><p id="zh-cn_topic_0000001127125088_p2092914815016"><a name="zh-cn_topic_0000001127125088_p2092914815016"></a><a name="zh-cn_topic_0000001127125088_p2092914815016"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001127125088_row2277638503"><td class="cellrowborder" valign="top" width="16.3%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001127125088_p127818375011"><a name="zh-cn_topic_0000001127125088_p127818375011"></a><a name="zh-cn_topic_0000001127125088_p127818375011"></a>xAxis</p>
</td>
<td class="cellrowborder" valign="top" width="11.24%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001127125088_p18278183115020"><a name="zh-cn_topic_0000001127125088_p18278183115020"></a><a name="zh-cn_topic_0000001127125088_p18278183115020"></a><a href="#zh-cn_topic_0000001127125088_table11312112919528">ChartAxis</a></p>
</td>
<td class="cellrowborder" valign="top" width="8.690000000000001%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001127125088_p1327817316507"><a name="zh-cn_topic_0000001127125088_p1327817316507"></a><a name="zh-cn_topic_0000001127125088_p1327817316507"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.7299999999999995%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001127125088_p427813385011"><a name="zh-cn_topic_0000001127125088_p427813385011"></a><a name="zh-cn_topic_0000001127125088_p427813385011"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="56.04%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001127125088_p1795144819490"><a name="zh-cn_topic_0000001127125088_p1795144819490"></a><a name="zh-cn_topic_0000001127125088_p1795144819490"></a>x轴参数设置。可以设置x轴最小值、最大值、刻度数以及是否显示。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125088_row14660105412507"><td class="cellrowborder" valign="top" width="16.3%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001127125088_p16611654205018"><a name="zh-cn_topic_0000001127125088_p16611654205018"></a><a name="zh-cn_topic_0000001127125088_p16611654205018"></a>yAxis</p>
</td>
<td class="cellrowborder" valign="top" width="11.24%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001127125088_p1518631821017"><a name="zh-cn_topic_0000001127125088_p1518631821017"></a><a name="zh-cn_topic_0000001127125088_p1518631821017"></a><a href="#zh-cn_topic_0000001127125088_table11312112919528">ChartAxis</a></p>
</td>
<td class="cellrowborder" valign="top" width="8.690000000000001%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001127125088_p19661554145015"><a name="zh-cn_topic_0000001127125088_p19661554145015"></a><a name="zh-cn_topic_0000001127125088_p19661554145015"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.7299999999999995%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001127125088_p466145416502"><a name="zh-cn_topic_0000001127125088_p466145416502"></a><a name="zh-cn_topic_0000001127125088_p466145416502"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="56.04%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001127125088_p14661554125010"><a name="zh-cn_topic_0000001127125088_p14661554125010"></a><a name="zh-cn_topic_0000001127125088_p14661554125010"></a>y轴参数设置。可以设置y轴最小值、最大值、刻度数以及是否显示。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125088_row1816015565013"><td class="cellrowborder" valign="top" width="16.3%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001127125088_p1816005585019"><a name="zh-cn_topic_0000001127125088_p1816005585019"></a><a name="zh-cn_topic_0000001127125088_p1816005585019"></a>series</p>
</td>
<td class="cellrowborder" valign="top" width="11.24%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001127125088_p91601455135019"><a name="zh-cn_topic_0000001127125088_p91601455135019"></a><a name="zh-cn_topic_0000001127125088_p91601455135019"></a><a href="#zh-cn_topic_0000001127125088_table029562010560">ChartSeries</a></p>
</td>
<td class="cellrowborder" valign="top" width="8.690000000000001%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001127125088_p416015565016"><a name="zh-cn_topic_0000001127125088_p416015565016"></a><a name="zh-cn_topic_0000001127125088_p416015565016"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.7299999999999995%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001127125088_p12160135565014"><a name="zh-cn_topic_0000001127125088_p12160135565014"></a><a name="zh-cn_topic_0000001127125088_p12160135565014"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="56.04%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001127125088_p1916095511501"><a name="zh-cn_topic_0000001127125088_p1916095511501"></a><a name="zh-cn_topic_0000001127125088_p1916095511501"></a>数据序列参数设置。可以设置1）线的样式，如线宽、是否平滑；2）设置线最前端位置白点的样式和大小。</p>
<div class="note" id="zh-cn_topic_0000001127125088_note163611718126"><a name="zh-cn_topic_0000001127125088_note163611718126"></a><a name="zh-cn_topic_0000001127125088_note163611718126"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001127125088_p15361117191211"><a name="zh-cn_topic_0000001127125088_p15361117191211"></a><a name="zh-cn_topic_0000001127125088_p15361117191211"></a>仅线形图支持。</p>
</div></div>
</td>
</tr>
</tbody>
</table>

**表 2**  ChartDataset

<a name="zh-cn_topic_0000001127125088_table13810518157"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001127125088_row1839105121514"><th class="cellrowborder" valign="top" width="16.56%" id="mcps1.2.6.1.1"><p id="zh-cn_topic_0000001127125088_p106956431614"><a name="zh-cn_topic_0000001127125088_p106956431614"></a><a name="zh-cn_topic_0000001127125088_p106956431614"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="16.830000000000002%" id="mcps1.2.6.1.2"><p id="zh-cn_topic_0000001127125088_p0695204111617"><a name="zh-cn_topic_0000001127125088_p0695204111617"></a><a name="zh-cn_topic_0000001127125088_p0695204111617"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="12.989999999999998%" id="mcps1.2.6.1.3"><p id="zh-cn_topic_0000001127125088_p1069514141614"><a name="zh-cn_topic_0000001127125088_p1069514141614"></a><a name="zh-cn_topic_0000001127125088_p1069514141614"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="9.33%" id="mcps1.2.6.1.4"><p id="zh-cn_topic_0000001127125088_p969564191616"><a name="zh-cn_topic_0000001127125088_p969564191616"></a><a name="zh-cn_topic_0000001127125088_p969564191616"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="44.29%" id="mcps1.2.6.1.5"><p id="zh-cn_topic_0000001127125088_p1169616441615"><a name="zh-cn_topic_0000001127125088_p1169616441615"></a><a name="zh-cn_topic_0000001127125088_p1169616441615"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001127125088_row1383242819553"><td class="cellrowborder" valign="top" width="16.56%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001127125088_p13832192819557"><a name="zh-cn_topic_0000001127125088_p13832192819557"></a><a name="zh-cn_topic_0000001127125088_p13832192819557"></a>strokeColor</p>
</td>
<td class="cellrowborder" valign="top" width="16.830000000000002%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001127125088_p18321928145512"><a name="zh-cn_topic_0000001127125088_p18321928145512"></a><a name="zh-cn_topic_0000001127125088_p18321928145512"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="12.989999999999998%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001127125088_p1283202816559"><a name="zh-cn_topic_0000001127125088_p1283202816559"></a><a name="zh-cn_topic_0000001127125088_p1283202816559"></a>#ff6384</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001127125088_p128322028155519"><a name="zh-cn_topic_0000001127125088_p128322028155519"></a><a name="zh-cn_topic_0000001127125088_p128322028155519"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="44.29%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001127125088_p383218285552"><a name="zh-cn_topic_0000001127125088_p383218285552"></a><a name="zh-cn_topic_0000001127125088_p383218285552"></a>线条颜色。</p>
<div class="note" id="zh-cn_topic_0000001127125088_note149682371351"><a name="zh-cn_topic_0000001127125088_note149682371351"></a><a name="zh-cn_topic_0000001127125088_note149682371351"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001127125088_p189688371757"><a name="zh-cn_topic_0000001127125088_p189688371757"></a><a name="zh-cn_topic_0000001127125088_p189688371757"></a>仅线形图支持。</p>
</div></div>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125088_row207559395562"><td class="cellrowborder" valign="top" width="16.56%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001127125088_p177551539205614"><a name="zh-cn_topic_0000001127125088_p177551539205614"></a><a name="zh-cn_topic_0000001127125088_p177551539205614"></a>fillColor</p>
</td>
<td class="cellrowborder" valign="top" width="16.830000000000002%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001127125088_p15755143911563"><a name="zh-cn_topic_0000001127125088_p15755143911563"></a><a name="zh-cn_topic_0000001127125088_p15755143911563"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="12.989999999999998%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001127125088_p9755939185618"><a name="zh-cn_topic_0000001127125088_p9755939185618"></a><a name="zh-cn_topic_0000001127125088_p9755939185618"></a>#ff6384</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001127125088_p1875553995610"><a name="zh-cn_topic_0000001127125088_p1875553995610"></a><a name="zh-cn_topic_0000001127125088_p1875553995610"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="44.29%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001127125088_p975563915619"><a name="zh-cn_topic_0000001127125088_p975563915619"></a><a name="zh-cn_topic_0000001127125088_p975563915619"></a>填充颜色。线形图表示填充的渐变颜色。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125088_row16221319185010"><td class="cellrowborder" valign="top" width="16.56%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001127125088_p1939135171519"><a name="zh-cn_topic_0000001127125088_p1939135171519"></a><a name="zh-cn_topic_0000001127125088_p1939135171519"></a>data</p>
</td>
<td class="cellrowborder" valign="top" width="16.830000000000002%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001127125088_p93945114156"><a name="zh-cn_topic_0000001127125088_p93945114156"></a><a name="zh-cn_topic_0000001127125088_p93945114156"></a>Array&lt;number&gt; | Array&lt;<a href="#zh-cn_topic_0000001127125088_table1470733752019">Point</a>&gt;<sup id="zh-cn_topic_0000001127125088_sup748712541259"><a name="zh-cn_topic_0000001127125088_sup748712541259"></a><a name="zh-cn_topic_0000001127125088_sup748712541259"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="12.989999999999998%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001127125088_p1839951201514"><a name="zh-cn_topic_0000001127125088_p1839951201514"></a><a name="zh-cn_topic_0000001127125088_p1839951201514"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001127125088_p4391651201517"><a name="zh-cn_topic_0000001127125088_p4391651201517"></a><a name="zh-cn_topic_0000001127125088_p4391651201517"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="44.29%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001127125088_p113975114159"><a name="zh-cn_topic_0000001127125088_p113975114159"></a><a name="zh-cn_topic_0000001127125088_p113975114159"></a>设置绘制线或柱中的点集。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125088_row284113911529"><td class="cellrowborder" valign="top" width="16.56%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001127125088_p884110975213"><a name="zh-cn_topic_0000001127125088_p884110975213"></a><a name="zh-cn_topic_0000001127125088_p884110975213"></a>gradient</p>
</td>
<td class="cellrowborder" valign="top" width="16.830000000000002%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001127125088_p168411494528"><a name="zh-cn_topic_0000001127125088_p168411494528"></a><a name="zh-cn_topic_0000001127125088_p168411494528"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="12.989999999999998%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001127125088_p7841992522"><a name="zh-cn_topic_0000001127125088_p7841992522"></a><a name="zh-cn_topic_0000001127125088_p7841992522"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001127125088_p1684159195214"><a name="zh-cn_topic_0000001127125088_p1684159195214"></a><a name="zh-cn_topic_0000001127125088_p1684159195214"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="44.29%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001127125088_p198414916522"><a name="zh-cn_topic_0000001127125088_p198414916522"></a><a name="zh-cn_topic_0000001127125088_p198414916522"></a>设置是否显示填充渐变颜色。</p>
<div class="note" id="zh-cn_topic_0000001127125088_note55873241061"><a name="zh-cn_topic_0000001127125088_note55873241061"></a><a name="zh-cn_topic_0000001127125088_note55873241061"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001127125088_p1558712410616"><a name="zh-cn_topic_0000001127125088_p1558712410616"></a><a name="zh-cn_topic_0000001127125088_p1558712410616"></a>仅线形图支持。</p>
</div></div>
</td>
</tr>
</tbody>
</table>

**表 3**  ChartAxis

<a name="zh-cn_topic_0000001127125088_table11312112919528"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001127125088_row1031252917522"><th class="cellrowborder" valign="top" width="10.18%" id="mcps1.2.6.1.1"><p id="zh-cn_topic_0000001127125088_p7835550165517"><a name="zh-cn_topic_0000001127125088_p7835550165517"></a><a name="zh-cn_topic_0000001127125088_p7835550165517"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="12.91%" id="mcps1.2.6.1.2"><p id="zh-cn_topic_0000001127125088_p2083515012555"><a name="zh-cn_topic_0000001127125088_p2083515012555"></a><a name="zh-cn_topic_0000001127125088_p2083515012555"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="8.870000000000001%" id="mcps1.2.6.1.3"><p id="zh-cn_topic_0000001127125088_p1283545016551"><a name="zh-cn_topic_0000001127125088_p1283545016551"></a><a name="zh-cn_topic_0000001127125088_p1283545016551"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.02%" id="mcps1.2.6.1.4"><p id="zh-cn_topic_0000001127125088_p18351650135519"><a name="zh-cn_topic_0000001127125088_p18351650135519"></a><a name="zh-cn_topic_0000001127125088_p18351650135519"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="61.019999999999996%" id="mcps1.2.6.1.5"><p id="zh-cn_topic_0000001127125088_p10835105017555"><a name="zh-cn_topic_0000001127125088_p10835105017555"></a><a name="zh-cn_topic_0000001127125088_p10835105017555"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001127125088_row231352916527"><td class="cellrowborder" valign="top" width="10.18%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001127125088_p13313529145212"><a name="zh-cn_topic_0000001127125088_p13313529145212"></a><a name="zh-cn_topic_0000001127125088_p13313529145212"></a>min</p>
</td>
<td class="cellrowborder" valign="top" width="12.91%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001127125088_p14313429185211"><a name="zh-cn_topic_0000001127125088_p14313429185211"></a><a name="zh-cn_topic_0000001127125088_p14313429185211"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.870000000000001%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001127125088_p19313152995219"><a name="zh-cn_topic_0000001127125088_p19313152995219"></a><a name="zh-cn_topic_0000001127125088_p19313152995219"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.02%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001127125088_p03131429165220"><a name="zh-cn_topic_0000001127125088_p03131429165220"></a><a name="zh-cn_topic_0000001127125088_p03131429165220"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="61.019999999999996%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001127125088_p15313529165215"><a name="zh-cn_topic_0000001127125088_p15313529165215"></a><a name="zh-cn_topic_0000001127125088_p15313529165215"></a>轴的最小值。</p>
<div class="note" id="zh-cn_topic_0000001127125088_note947711273197"><a name="zh-cn_topic_0000001127125088_note947711273197"></a><a name="zh-cn_topic_0000001127125088_note947711273197"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001127125088_p5477102781911"><a name="zh-cn_topic_0000001127125088_p5477102781911"></a><a name="zh-cn_topic_0000001127125088_p5477102781911"></a>仅线形图支持负数。</p>
</div></div>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125088_row10177207165517"><td class="cellrowborder" valign="top" width="10.18%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001127125088_p191773713559"><a name="zh-cn_topic_0000001127125088_p191773713559"></a><a name="zh-cn_topic_0000001127125088_p191773713559"></a>max</p>
</td>
<td class="cellrowborder" valign="top" width="12.91%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001127125088_p11771076557"><a name="zh-cn_topic_0000001127125088_p11771076557"></a><a name="zh-cn_topic_0000001127125088_p11771076557"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.870000000000001%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001127125088_p13177127165511"><a name="zh-cn_topic_0000001127125088_p13177127165511"></a><a name="zh-cn_topic_0000001127125088_p13177127165511"></a>100</p>
</td>
<td class="cellrowborder" valign="top" width="7.02%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001127125088_p171774715517"><a name="zh-cn_topic_0000001127125088_p171774715517"></a><a name="zh-cn_topic_0000001127125088_p171774715517"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="61.019999999999996%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001127125088_p111771705519"><a name="zh-cn_topic_0000001127125088_p111771705519"></a><a name="zh-cn_topic_0000001127125088_p111771705519"></a>轴的最大值。</p>
<div class="note" id="zh-cn_topic_0000001127125088_note1287217389195"><a name="zh-cn_topic_0000001127125088_note1287217389195"></a><a name="zh-cn_topic_0000001127125088_note1287217389195"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001127125088_p17872153817197"><a name="zh-cn_topic_0000001127125088_p17872153817197"></a><a name="zh-cn_topic_0000001127125088_p17872153817197"></a>仅线形图支持负数。</p>
</div></div>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125088_row54401875553"><td class="cellrowborder" valign="top" width="10.18%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001127125088_p544037145514"><a name="zh-cn_topic_0000001127125088_p544037145514"></a><a name="zh-cn_topic_0000001127125088_p544037145514"></a>axisTick</p>
</td>
<td class="cellrowborder" valign="top" width="12.91%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001127125088_p844011745512"><a name="zh-cn_topic_0000001127125088_p844011745512"></a><a name="zh-cn_topic_0000001127125088_p844011745512"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.870000000000001%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001127125088_p9440277558"><a name="zh-cn_topic_0000001127125088_p9440277558"></a><a name="zh-cn_topic_0000001127125088_p9440277558"></a>10</p>
</td>
<td class="cellrowborder" valign="top" width="7.02%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001127125088_p194406755518"><a name="zh-cn_topic_0000001127125088_p194406755518"></a><a name="zh-cn_topic_0000001127125088_p194406755518"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="61.019999999999996%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001127125088_p1144027105511"><a name="zh-cn_topic_0000001127125088_p1144027105511"></a><a name="zh-cn_topic_0000001127125088_p1144027105511"></a>轴显示的刻度数量。</p>
<div class="note" id="zh-cn_topic_0000001127125088_note18942121511202"><a name="zh-cn_topic_0000001127125088_note18942121511202"></a><a name="zh-cn_topic_0000001127125088_note18942121511202"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001127125088_p4709421681"><a name="zh-cn_topic_0000001127125088_p4709421681"></a><a name="zh-cn_topic_0000001127125088_p4709421681"></a>仅支持1~20，且具体显示的效果与如下计算值有关（图的宽度所占的像素/（max-min））。</p>
<p id="zh-cn_topic_0000001127125088_p234142016205"><a name="zh-cn_topic_0000001127125088_p234142016205"></a><a name="zh-cn_topic_0000001127125088_p234142016205"></a>在柱状图中，每组数据显示的柱子数量与刻度数量一致，且柱子显示在刻度处。</p>
</div></div>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125088_row6558148125516"><td class="cellrowborder" valign="top" width="10.18%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001127125088_p1555818865515"><a name="zh-cn_topic_0000001127125088_p1555818865515"></a><a name="zh-cn_topic_0000001127125088_p1555818865515"></a>display</p>
</td>
<td class="cellrowborder" valign="top" width="12.91%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001127125088_p1755910815552"><a name="zh-cn_topic_0000001127125088_p1755910815552"></a><a name="zh-cn_topic_0000001127125088_p1755910815552"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="8.870000000000001%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001127125088_p2559108195515"><a name="zh-cn_topic_0000001127125088_p2559108195515"></a><a name="zh-cn_topic_0000001127125088_p2559108195515"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.02%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001127125088_p185597805514"><a name="zh-cn_topic_0000001127125088_p185597805514"></a><a name="zh-cn_topic_0000001127125088_p185597805514"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="61.019999999999996%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001127125088_p1655910815551"><a name="zh-cn_topic_0000001127125088_p1655910815551"></a><a name="zh-cn_topic_0000001127125088_p1655910815551"></a>是否显示轴。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125088_row1382114065515"><td class="cellrowborder" valign="top" width="10.18%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001127125088_p188221209555"><a name="zh-cn_topic_0000001127125088_p188221209555"></a><a name="zh-cn_topic_0000001127125088_p188221209555"></a>color</p>
</td>
<td class="cellrowborder" valign="top" width="12.91%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001127125088_p1782214025517"><a name="zh-cn_topic_0000001127125088_p1782214025517"></a><a name="zh-cn_topic_0000001127125088_p1782214025517"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.870000000000001%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001127125088_p482220185512"><a name="zh-cn_topic_0000001127125088_p482220185512"></a><a name="zh-cn_topic_0000001127125088_p482220185512"></a>#c0c0c0</p>
</td>
<td class="cellrowborder" valign="top" width="7.02%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001127125088_p782214015553"><a name="zh-cn_topic_0000001127125088_p782214015553"></a><a name="zh-cn_topic_0000001127125088_p782214015553"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="61.019999999999996%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001127125088_p4822202556"><a name="zh-cn_topic_0000001127125088_p4822202556"></a><a name="zh-cn_topic_0000001127125088_p4822202556"></a>轴颜色。</p>
</td>
</tr>
</tbody>
</table>

**表 4**  ChartSeries

<a name="zh-cn_topic_0000001127125088_table029562010560"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001127125088_row9295192095610"><th class="cellrowborder" valign="top" width="17%" id="mcps1.2.6.1.1"><p id="zh-cn_topic_0000001127125088_p10617123345612"><a name="zh-cn_topic_0000001127125088_p10617123345612"></a><a name="zh-cn_topic_0000001127125088_p10617123345612"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="16.39%" id="mcps1.2.6.1.2"><p id="zh-cn_topic_0000001127125088_p9617133175613"><a name="zh-cn_topic_0000001127125088_p9617133175613"></a><a name="zh-cn_topic_0000001127125088_p9617133175613"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="12.82%" id="mcps1.2.6.1.3"><p id="zh-cn_topic_0000001127125088_p3617153315562"><a name="zh-cn_topic_0000001127125088_p3617153315562"></a><a name="zh-cn_topic_0000001127125088_p3617153315562"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="10.11%" id="mcps1.2.6.1.4"><p id="zh-cn_topic_0000001127125088_p4617163305612"><a name="zh-cn_topic_0000001127125088_p4617163305612"></a><a name="zh-cn_topic_0000001127125088_p4617163305612"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="43.68%" id="mcps1.2.6.1.5"><p id="zh-cn_topic_0000001127125088_p1561718337569"><a name="zh-cn_topic_0000001127125088_p1561718337569"></a><a name="zh-cn_topic_0000001127125088_p1561718337569"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001127125088_row13295162011563"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001127125088_p2296820185612"><a name="zh-cn_topic_0000001127125088_p2296820185612"></a><a name="zh-cn_topic_0000001127125088_p2296820185612"></a>lineStyle</p>
</td>
<td class="cellrowborder" valign="top" width="16.39%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001127125088_p529652005615"><a name="zh-cn_topic_0000001127125088_p529652005615"></a><a name="zh-cn_topic_0000001127125088_p529652005615"></a><a href="#zh-cn_topic_0000001127125088_table7790183513918">ChartLineStyle</a></p>
</td>
<td class="cellrowborder" valign="top" width="12.82%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001127125088_p629612208561"><a name="zh-cn_topic_0000001127125088_p629612208561"></a><a name="zh-cn_topic_0000001127125088_p629612208561"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="10.11%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001127125088_p129632065619"><a name="zh-cn_topic_0000001127125088_p129632065619"></a><a name="zh-cn_topic_0000001127125088_p129632065619"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.68%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001127125088_p929652045614"><a name="zh-cn_topic_0000001127125088_p929652045614"></a><a name="zh-cn_topic_0000001127125088_p929652045614"></a>线样式设置，如线宽、是否平滑。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125088_row1829652010566"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001127125088_p17296112017565"><a name="zh-cn_topic_0000001127125088_p17296112017565"></a><a name="zh-cn_topic_0000001127125088_p17296112017565"></a>headPoint</p>
</td>
<td class="cellrowborder" valign="top" width="16.39%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001127125088_p1829632018566"><a name="zh-cn_topic_0000001127125088_p1829632018566"></a><a name="zh-cn_topic_0000001127125088_p1829632018566"></a><a href="#zh-cn_topic_0000001127125088_table1435760101317">PointStyle</a></p>
</td>
<td class="cellrowborder" valign="top" width="12.82%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001127125088_p52966203569"><a name="zh-cn_topic_0000001127125088_p52966203569"></a><a name="zh-cn_topic_0000001127125088_p52966203569"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="10.11%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001127125088_p17296020155611"><a name="zh-cn_topic_0000001127125088_p17296020155611"></a><a name="zh-cn_topic_0000001127125088_p17296020155611"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.68%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001127125088_p14296132015616"><a name="zh-cn_topic_0000001127125088_p14296132015616"></a><a name="zh-cn_topic_0000001127125088_p14296132015616"></a>线最前端位置白点的样式和大小。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125088_row416985481620"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001127125088_p816915441619"><a name="zh-cn_topic_0000001127125088_p816915441619"></a><a name="zh-cn_topic_0000001127125088_p816915441619"></a>topPoint</p>
</td>
<td class="cellrowborder" valign="top" width="16.39%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001127125088_p13169145471618"><a name="zh-cn_topic_0000001127125088_p13169145471618"></a><a name="zh-cn_topic_0000001127125088_p13169145471618"></a><a href="#zh-cn_topic_0000001127125088_table1435760101317">PointStyle</a></p>
</td>
<td class="cellrowborder" valign="top" width="12.82%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001127125088_p816995416164"><a name="zh-cn_topic_0000001127125088_p816995416164"></a><a name="zh-cn_topic_0000001127125088_p816995416164"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="10.11%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001127125088_p2017015417166"><a name="zh-cn_topic_0000001127125088_p2017015417166"></a><a name="zh-cn_topic_0000001127125088_p2017015417166"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.68%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001127125088_p98810719197"><a name="zh-cn_topic_0000001127125088_p98810719197"></a><a name="zh-cn_topic_0000001127125088_p98810719197"></a>最高点的样式和大小。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125088_row9719195771616"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001127125088_p12719857161614"><a name="zh-cn_topic_0000001127125088_p12719857161614"></a><a name="zh-cn_topic_0000001127125088_p12719857161614"></a>bottomPoint</p>
</td>
<td class="cellrowborder" valign="top" width="16.39%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001127125088_p631412816137"><a name="zh-cn_topic_0000001127125088_p631412816137"></a><a name="zh-cn_topic_0000001127125088_p631412816137"></a><a href="#zh-cn_topic_0000001127125088_table1435760101317">PointStyle</a></p>
</td>
<td class="cellrowborder" valign="top" width="12.82%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001127125088_p1771995719166"><a name="zh-cn_topic_0000001127125088_p1771995719166"></a><a name="zh-cn_topic_0000001127125088_p1771995719166"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="10.11%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001127125088_p77192571166"><a name="zh-cn_topic_0000001127125088_p77192571166"></a><a name="zh-cn_topic_0000001127125088_p77192571166"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.68%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001127125088_p10719357111610"><a name="zh-cn_topic_0000001127125088_p10719357111610"></a><a name="zh-cn_topic_0000001127125088_p10719357111610"></a>最低点的样式和大小。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125088_row1165515117356"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001127125088_p1065610143518"><a name="zh-cn_topic_0000001127125088_p1065610143518"></a><a name="zh-cn_topic_0000001127125088_p1065610143518"></a>loop</p>
</td>
<td class="cellrowborder" valign="top" width="16.39%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001127125088_p8656121143511"><a name="zh-cn_topic_0000001127125088_p8656121143511"></a><a name="zh-cn_topic_0000001127125088_p8656121143511"></a><a href="#zh-cn_topic_0000001127125088_table13982347173714">ChartLoop</a></p>
</td>
<td class="cellrowborder" valign="top" width="12.82%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001127125088_p765611163510"><a name="zh-cn_topic_0000001127125088_p765611163510"></a><a name="zh-cn_topic_0000001127125088_p765611163510"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="10.11%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001127125088_p1965671123510"><a name="zh-cn_topic_0000001127125088_p1965671123510"></a><a name="zh-cn_topic_0000001127125088_p1965671123510"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.68%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001127125088_p19656131113517"><a name="zh-cn_topic_0000001127125088_p19656131113517"></a><a name="zh-cn_topic_0000001127125088_p19656131113517"></a>设置屏幕显示满时，是否需要重头开始绘制。</p>
</td>
</tr>
</tbody>
</table>

**表 5**  ChartLineStyle

<a name="zh-cn_topic_0000001127125088_table7790183513918"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001127125088_row167906351914"><th class="cellrowborder" valign="top" width="17.09%" id="mcps1.2.6.1.1"><p id="zh-cn_topic_0000001127125088_p15238040191012"><a name="zh-cn_topic_0000001127125088_p15238040191012"></a><a name="zh-cn_topic_0000001127125088_p15238040191012"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="16.91%" id="mcps1.2.6.1.2"><p id="zh-cn_topic_0000001127125088_p142381440151020"><a name="zh-cn_topic_0000001127125088_p142381440151020"></a><a name="zh-cn_topic_0000001127125088_p142381440151020"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="12.690000000000001%" id="mcps1.2.6.1.3"><p id="zh-cn_topic_0000001127125088_p723814051011"><a name="zh-cn_topic_0000001127125088_p723814051011"></a><a name="zh-cn_topic_0000001127125088_p723814051011"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="10.24%" id="mcps1.2.6.1.4"><p id="zh-cn_topic_0000001127125088_p623818402108"><a name="zh-cn_topic_0000001127125088_p623818402108"></a><a name="zh-cn_topic_0000001127125088_p623818402108"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="43.07%" id="mcps1.2.6.1.5"><p id="zh-cn_topic_0000001127125088_p1223834091020"><a name="zh-cn_topic_0000001127125088_p1223834091020"></a><a name="zh-cn_topic_0000001127125088_p1223834091020"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001127125088_row47909350912"><td class="cellrowborder" valign="top" width="17.09%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001127125088_p13791135393"><a name="zh-cn_topic_0000001127125088_p13791135393"></a><a name="zh-cn_topic_0000001127125088_p13791135393"></a>width</p>
</td>
<td class="cellrowborder" valign="top" width="16.91%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001127125088_p5791123511915"><a name="zh-cn_topic_0000001127125088_p5791123511915"></a><a name="zh-cn_topic_0000001127125088_p5791123511915"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="12.690000000000001%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001127125088_p1479120352916"><a name="zh-cn_topic_0000001127125088_p1479120352916"></a><a name="zh-cn_topic_0000001127125088_p1479120352916"></a>1px</p>
</td>
<td class="cellrowborder" valign="top" width="10.24%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001127125088_p87911135691"><a name="zh-cn_topic_0000001127125088_p87911135691"></a><a name="zh-cn_topic_0000001127125088_p87911135691"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.07%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001127125088_p47917356918"><a name="zh-cn_topic_0000001127125088_p47917356918"></a><a name="zh-cn_topic_0000001127125088_p47917356918"></a>线宽设置。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125088_row1279183510911"><td class="cellrowborder" valign="top" width="17.09%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001127125088_p107913351297"><a name="zh-cn_topic_0000001127125088_p107913351297"></a><a name="zh-cn_topic_0000001127125088_p107913351297"></a>smooth</p>
</td>
<td class="cellrowborder" valign="top" width="16.91%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001127125088_p1479113515915"><a name="zh-cn_topic_0000001127125088_p1479113515915"></a><a name="zh-cn_topic_0000001127125088_p1479113515915"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="12.690000000000001%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001127125088_p179111356910"><a name="zh-cn_topic_0000001127125088_p179111356910"></a><a name="zh-cn_topic_0000001127125088_p179111356910"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="10.24%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001127125088_p979117355914"><a name="zh-cn_topic_0000001127125088_p979117355914"></a><a name="zh-cn_topic_0000001127125088_p979117355914"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.07%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001127125088_p1879113353920"><a name="zh-cn_topic_0000001127125088_p1879113353920"></a><a name="zh-cn_topic_0000001127125088_p1879113353920"></a>是否平滑。</p>
</td>
</tr>
</tbody>
</table>

**表 6**  PointStyle

<a name="zh-cn_topic_0000001127125088_table1435760101317"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001127125088_row0357180181315"><th class="cellrowborder" valign="top" width="17.09%" id="mcps1.2.6.1.1"><p id="zh-cn_topic_0000001127125088_p763402181310"><a name="zh-cn_topic_0000001127125088_p763402181310"></a><a name="zh-cn_topic_0000001127125088_p763402181310"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="17.09%" id="mcps1.2.6.1.2"><p id="zh-cn_topic_0000001127125088_p963402171313"><a name="zh-cn_topic_0000001127125088_p963402171313"></a><a name="zh-cn_topic_0000001127125088_p963402171313"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="12.64%" id="mcps1.2.6.1.3"><p id="zh-cn_topic_0000001127125088_p166343212133"><a name="zh-cn_topic_0000001127125088_p166343212133"></a><a name="zh-cn_topic_0000001127125088_p166343212133"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="10.549999999999999%" id="mcps1.2.6.1.4"><p id="zh-cn_topic_0000001127125088_p4634621111311"><a name="zh-cn_topic_0000001127125088_p4634621111311"></a><a name="zh-cn_topic_0000001127125088_p4634621111311"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="42.63%" id="mcps1.2.6.1.5"><p id="zh-cn_topic_0000001127125088_p2063413215132"><a name="zh-cn_topic_0000001127125088_p2063413215132"></a><a name="zh-cn_topic_0000001127125088_p2063413215132"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001127125088_row53581105131"><td class="cellrowborder" valign="top" width="17.09%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001127125088_p12358803137"><a name="zh-cn_topic_0000001127125088_p12358803137"></a><a name="zh-cn_topic_0000001127125088_p12358803137"></a>shape</p>
</td>
<td class="cellrowborder" valign="top" width="17.09%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001127125088_p19358190201313"><a name="zh-cn_topic_0000001127125088_p19358190201313"></a><a name="zh-cn_topic_0000001127125088_p19358190201313"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="12.64%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001127125088_p1358170141315"><a name="zh-cn_topic_0000001127125088_p1358170141315"></a><a name="zh-cn_topic_0000001127125088_p1358170141315"></a>circle</p>
</td>
<td class="cellrowborder" valign="top" width="10.549999999999999%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001127125088_p0358203135"><a name="zh-cn_topic_0000001127125088_p0358203135"></a><a name="zh-cn_topic_0000001127125088_p0358203135"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="42.63%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001127125088_p113581206134"><a name="zh-cn_topic_0000001127125088_p113581206134"></a><a name="zh-cn_topic_0000001127125088_p113581206134"></a>高亮点的形状。可选值为：</p>
<a name="zh-cn_topic_0000001127125088_ul107389175319"></a><a name="zh-cn_topic_0000001127125088_ul107389175319"></a><ul id="zh-cn_topic_0000001127125088_ul107389175319"><li>circle：圆形。</li><li>square：方形。</li><li>triangle：三角形。</li></ul>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125088_row143581011317"><td class="cellrowborder" valign="top" width="17.09%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001127125088_p19358200201311"><a name="zh-cn_topic_0000001127125088_p19358200201311"></a><a name="zh-cn_topic_0000001127125088_p19358200201311"></a>size</p>
</td>
<td class="cellrowborder" valign="top" width="17.09%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001127125088_p93585011135"><a name="zh-cn_topic_0000001127125088_p93585011135"></a><a name="zh-cn_topic_0000001127125088_p93585011135"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="12.64%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001127125088_p203581081313"><a name="zh-cn_topic_0000001127125088_p203581081313"></a><a name="zh-cn_topic_0000001127125088_p203581081313"></a>5px</p>
</td>
<td class="cellrowborder" valign="top" width="10.549999999999999%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001127125088_p183582008137"><a name="zh-cn_topic_0000001127125088_p183582008137"></a><a name="zh-cn_topic_0000001127125088_p183582008137"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="42.63%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001127125088_p2358502135"><a name="zh-cn_topic_0000001127125088_p2358502135"></a><a name="zh-cn_topic_0000001127125088_p2358502135"></a>高亮点的大小。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125088_row957985594815"><td class="cellrowborder" valign="top" width="17.09%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001127125088_p11579165564814"><a name="zh-cn_topic_0000001127125088_p11579165564814"></a><a name="zh-cn_topic_0000001127125088_p11579165564814"></a>strokeWidth</p>
</td>
<td class="cellrowborder" valign="top" width="17.09%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001127125088_p657916559486"><a name="zh-cn_topic_0000001127125088_p657916559486"></a><a name="zh-cn_topic_0000001127125088_p657916559486"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="12.64%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001127125088_p12579105514489"><a name="zh-cn_topic_0000001127125088_p12579105514489"></a><a name="zh-cn_topic_0000001127125088_p12579105514489"></a>1px</p>
</td>
<td class="cellrowborder" valign="top" width="10.549999999999999%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001127125088_p958015514480"><a name="zh-cn_topic_0000001127125088_p958015514480"></a><a name="zh-cn_topic_0000001127125088_p958015514480"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="42.63%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001127125088_p3580115534814"><a name="zh-cn_topic_0000001127125088_p3580115534814"></a><a name="zh-cn_topic_0000001127125088_p3580115534814"></a>边框宽度</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125088_row51421313317"><td class="cellrowborder" valign="top" width="17.09%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001127125088_p151432333315"><a name="zh-cn_topic_0000001127125088_p151432333315"></a><a name="zh-cn_topic_0000001127125088_p151432333315"></a>strokeColor</p>
</td>
<td class="cellrowborder" valign="top" width="17.09%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001127125088_p1914312363315"><a name="zh-cn_topic_0000001127125088_p1914312363315"></a><a name="zh-cn_topic_0000001127125088_p1914312363315"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="12.64%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001127125088_p114319316335"><a name="zh-cn_topic_0000001127125088_p114319316335"></a><a name="zh-cn_topic_0000001127125088_p114319316335"></a>#ff0000</p>
</td>
<td class="cellrowborder" valign="top" width="10.549999999999999%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001127125088_p11431036331"><a name="zh-cn_topic_0000001127125088_p11431036331"></a><a name="zh-cn_topic_0000001127125088_p11431036331"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="42.63%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001127125088_p181441434339"><a name="zh-cn_topic_0000001127125088_p181441434339"></a><a name="zh-cn_topic_0000001127125088_p181441434339"></a>边框颜色。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125088_row1312214335332"><td class="cellrowborder" valign="top" width="17.09%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001127125088_p10123233193310"><a name="zh-cn_topic_0000001127125088_p10123233193310"></a><a name="zh-cn_topic_0000001127125088_p10123233193310"></a>fillColor</p>
</td>
<td class="cellrowborder" valign="top" width="17.09%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001127125088_p12123233123310"><a name="zh-cn_topic_0000001127125088_p12123233123310"></a><a name="zh-cn_topic_0000001127125088_p12123233123310"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="12.64%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001127125088_p10123143343313"><a name="zh-cn_topic_0000001127125088_p10123143343313"></a><a name="zh-cn_topic_0000001127125088_p10123143343313"></a>#ff0000</p>
</td>
<td class="cellrowborder" valign="top" width="10.549999999999999%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001127125088_p16123163317338"><a name="zh-cn_topic_0000001127125088_p16123163317338"></a><a name="zh-cn_topic_0000001127125088_p16123163317338"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="42.63%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001127125088_p6123433193311"><a name="zh-cn_topic_0000001127125088_p6123433193311"></a><a name="zh-cn_topic_0000001127125088_p6123433193311"></a>填充颜色。</p>
</td>
</tr>
</tbody>
</table>

**表 7**  ChartLoop

<a name="zh-cn_topic_0000001127125088_table13982347173714"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001127125088_row1498384714371"><th class="cellrowborder" valign="top" width="11.85%" id="mcps1.2.6.1.1"><p id="zh-cn_topic_0000001127125088_p1640543183916"><a name="zh-cn_topic_0000001127125088_p1640543183916"></a><a name="zh-cn_topic_0000001127125088_p1640543183916"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="12.030000000000001%" id="mcps1.2.6.1.2"><p id="zh-cn_topic_0000001127125088_p18640043143916"><a name="zh-cn_topic_0000001127125088_p18640043143916"></a><a name="zh-cn_topic_0000001127125088_p18640043143916"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="9.83%" id="mcps1.2.6.1.3"><p id="zh-cn_topic_0000001127125088_p12640144317398"><a name="zh-cn_topic_0000001127125088_p12640144317398"></a><a name="zh-cn_topic_0000001127125088_p12640144317398"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="9.04%" id="mcps1.2.6.1.4"><p id="zh-cn_topic_0000001127125088_p1764014343915"><a name="zh-cn_topic_0000001127125088_p1764014343915"></a><a name="zh-cn_topic_0000001127125088_p1764014343915"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="57.25%" id="mcps1.2.6.1.5"><p id="zh-cn_topic_0000001127125088_p1064084314395"><a name="zh-cn_topic_0000001127125088_p1064084314395"></a><a name="zh-cn_topic_0000001127125088_p1064084314395"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001127125088_row8983164710376"><td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001127125088_p11983147113716"><a name="zh-cn_topic_0000001127125088_p11983147113716"></a><a name="zh-cn_topic_0000001127125088_p11983147113716"></a>margin</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001127125088_p1898316477374"><a name="zh-cn_topic_0000001127125088_p1898316477374"></a><a name="zh-cn_topic_0000001127125088_p1898316477374"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="9.83%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001127125088_p139841479376"><a name="zh-cn_topic_0000001127125088_p139841479376"></a><a name="zh-cn_topic_0000001127125088_p139841479376"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001127125088_p169842479376"><a name="zh-cn_topic_0000001127125088_p169842479376"></a><a name="zh-cn_topic_0000001127125088_p169842479376"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="57.25%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001127125088_p798434723720"><a name="zh-cn_topic_0000001127125088_p798434723720"></a><a name="zh-cn_topic_0000001127125088_p798434723720"></a>擦除点的个数（最新绘制的点与最老的点之间的横向距离）。注意：轻量设备margin和topPoint/bottomPoint/headPoint同时使用时，有概率出现point正好位于擦除区域的情况，导致point不可见，因此不建议同时使用。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125088_row109849472372"><td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001127125088_p09841047183715"><a name="zh-cn_topic_0000001127125088_p09841047183715"></a><a name="zh-cn_topic_0000001127125088_p09841047183715"></a>gradient</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001127125088_p92761838193812"><a name="zh-cn_topic_0000001127125088_p92761838193812"></a><a name="zh-cn_topic_0000001127125088_p92761838193812"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="9.83%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001127125088_p127603819380"><a name="zh-cn_topic_0000001127125088_p127603819380"></a><a name="zh-cn_topic_0000001127125088_p127603819380"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001127125088_p227733816384"><a name="zh-cn_topic_0000001127125088_p227733816384"></a><a name="zh-cn_topic_0000001127125088_p227733816384"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="57.25%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001127125088_p13277173823811"><a name="zh-cn_topic_0000001127125088_p13277173823811"></a><a name="zh-cn_topic_0000001127125088_p13277173823811"></a>是否需要渐变擦除。</p>
</td>
</tr>
</tbody>
</table>

**表 8**  Point<sup>5+</sup>

<a name="zh-cn_topic_0000001127125088_table1470733752019"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001127125088_row177072373203"><th class="cellrowborder" valign="top" width="11.85%" id="mcps1.2.6.1.1"><p id="zh-cn_topic_0000001127125088_p1770793715201"><a name="zh-cn_topic_0000001127125088_p1770793715201"></a><a name="zh-cn_topic_0000001127125088_p1770793715201"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="12.030000000000001%" id="mcps1.2.6.1.2"><p id="zh-cn_topic_0000001127125088_p137073372202"><a name="zh-cn_topic_0000001127125088_p137073372202"></a><a name="zh-cn_topic_0000001127125088_p137073372202"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="9.83%" id="mcps1.2.6.1.3"><p id="zh-cn_topic_0000001127125088_p47078377208"><a name="zh-cn_topic_0000001127125088_p47078377208"></a><a name="zh-cn_topic_0000001127125088_p47078377208"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="9.04%" id="mcps1.2.6.1.4"><p id="zh-cn_topic_0000001127125088_p1470719376206"><a name="zh-cn_topic_0000001127125088_p1470719376206"></a><a name="zh-cn_topic_0000001127125088_p1470719376206"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="57.25%" id="mcps1.2.6.1.5"><p id="zh-cn_topic_0000001127125088_p1370783712017"><a name="zh-cn_topic_0000001127125088_p1370783712017"></a><a name="zh-cn_topic_0000001127125088_p1370783712017"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001127125088_row137071737112010"><td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001127125088_p9707153711207"><a name="zh-cn_topic_0000001127125088_p9707153711207"></a><a name="zh-cn_topic_0000001127125088_p9707153711207"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001127125088_p157081437132013"><a name="zh-cn_topic_0000001127125088_p157081437132013"></a><a name="zh-cn_topic_0000001127125088_p157081437132013"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="9.83%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001127125088_p970833722016"><a name="zh-cn_topic_0000001127125088_p970833722016"></a><a name="zh-cn_topic_0000001127125088_p970833722016"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001127125088_p2070812378209"><a name="zh-cn_topic_0000001127125088_p2070812378209"></a><a name="zh-cn_topic_0000001127125088_p2070812378209"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="57.25%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001127125088_p188430361213"><a name="zh-cn_topic_0000001127125088_p188430361213"></a><a name="zh-cn_topic_0000001127125088_p188430361213"></a>表示绘制点的Y轴坐标。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125088_row13708173719202"><td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001127125088_p18708143772014"><a name="zh-cn_topic_0000001127125088_p18708143772014"></a><a name="zh-cn_topic_0000001127125088_p18708143772014"></a>pointStyle</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001127125088_p77081637172018"><a name="zh-cn_topic_0000001127125088_p77081637172018"></a><a name="zh-cn_topic_0000001127125088_p77081637172018"></a><a href="#zh-cn_topic_0000001127125088_table1435760101317">PointStyle</a></p>
</td>
<td class="cellrowborder" valign="top" width="9.83%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001127125088_p270803719206"><a name="zh-cn_topic_0000001127125088_p270803719206"></a><a name="zh-cn_topic_0000001127125088_p270803719206"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001127125088_p19708133782018"><a name="zh-cn_topic_0000001127125088_p19708133782018"></a><a name="zh-cn_topic_0000001127125088_p19708133782018"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="57.25%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001127125088_p12708203712010"><a name="zh-cn_topic_0000001127125088_p12708203712010"></a><a name="zh-cn_topic_0000001127125088_p12708203712010"></a>表示当前数据点的绘制样式。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125088_row431291710242"><td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001127125088_p13131917162412"><a name="zh-cn_topic_0000001127125088_p13131917162412"></a><a name="zh-cn_topic_0000001127125088_p13131917162412"></a>description</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001127125088_p1231341710240"><a name="zh-cn_topic_0000001127125088_p1231341710240"></a><a name="zh-cn_topic_0000001127125088_p1231341710240"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.83%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001127125088_p14313121716241"><a name="zh-cn_topic_0000001127125088_p14313121716241"></a><a name="zh-cn_topic_0000001127125088_p14313121716241"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001127125088_p13139178245"><a name="zh-cn_topic_0000001127125088_p13139178245"></a><a name="zh-cn_topic_0000001127125088_p13139178245"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="57.25%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001127125088_p11313171716246"><a name="zh-cn_topic_0000001127125088_p11313171716246"></a><a name="zh-cn_topic_0000001127125088_p11313171716246"></a>表示当前点的注释内容。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125088_row431301902517"><td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001127125088_p1931461914251"><a name="zh-cn_topic_0000001127125088_p1931461914251"></a><a name="zh-cn_topic_0000001127125088_p1931461914251"></a>textLocation</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001127125088_p1331471915257"><a name="zh-cn_topic_0000001127125088_p1331471915257"></a><a name="zh-cn_topic_0000001127125088_p1331471915257"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.83%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001127125088_p331431992516"><a name="zh-cn_topic_0000001127125088_p331431992516"></a><a name="zh-cn_topic_0000001127125088_p331431992516"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001127125088_p33145199254"><a name="zh-cn_topic_0000001127125088_p33145199254"></a><a name="zh-cn_topic_0000001127125088_p33145199254"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="57.25%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001127125088_p20314141922517"><a name="zh-cn_topic_0000001127125088_p20314141922517"></a><a name="zh-cn_topic_0000001127125088_p20314141922517"></a>可选值为top，bottom，none。分别表示注释的绘制位置位于点的上方，下方，以及不绘制。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125088_row48671150122613"><td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001127125088_p486819509261"><a name="zh-cn_topic_0000001127125088_p486819509261"></a><a name="zh-cn_topic_0000001127125088_p486819509261"></a>textColor</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001127125088_p12868165002617"><a name="zh-cn_topic_0000001127125088_p12868165002617"></a><a name="zh-cn_topic_0000001127125088_p12868165002617"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="9.83%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001127125088_p4868205002616"><a name="zh-cn_topic_0000001127125088_p4868205002616"></a><a name="zh-cn_topic_0000001127125088_p4868205002616"></a>#000000</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001127125088_p1286825017267"><a name="zh-cn_topic_0000001127125088_p1286825017267"></a><a name="zh-cn_topic_0000001127125088_p1286825017267"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="57.25%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001127125088_p13868150162611"><a name="zh-cn_topic_0000001127125088_p13868150162611"></a><a name="zh-cn_topic_0000001127125088_p13868150162611"></a>表示注释文字的颜色。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125088_row9703542172713"><td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001127125088_p1870364214275"><a name="zh-cn_topic_0000001127125088_p1870364214275"></a><a name="zh-cn_topic_0000001127125088_p1870364214275"></a>lineDash</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001127125088_p1470334222718"><a name="zh-cn_topic_0000001127125088_p1470334222718"></a><a name="zh-cn_topic_0000001127125088_p1470334222718"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.83%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001127125088_p1670324217274"><a name="zh-cn_topic_0000001127125088_p1670324217274"></a><a name="zh-cn_topic_0000001127125088_p1670324217274"></a>solid</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001127125088_p197033423272"><a name="zh-cn_topic_0000001127125088_p197033423272"></a><a name="zh-cn_topic_0000001127125088_p197033423272"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="57.25%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001127125088_p570304202712"><a name="zh-cn_topic_0000001127125088_p570304202712"></a><a name="zh-cn_topic_0000001127125088_p570304202712"></a>表示绘制当前线段虚线的样式。“dashed， 5， 5”表示纯虚线，绘制5px的实线后留5px的空白。“solid”表示绘制实线。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125088_row15389105792810"><td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001127125088_p15389357102818"><a name="zh-cn_topic_0000001127125088_p15389357102818"></a><a name="zh-cn_topic_0000001127125088_p15389357102818"></a>lineColor</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001127125088_p3389135711281"><a name="zh-cn_topic_0000001127125088_p3389135711281"></a><a name="zh-cn_topic_0000001127125088_p3389135711281"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="9.83%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001127125088_p135711197293"><a name="zh-cn_topic_0000001127125088_p135711197293"></a><a name="zh-cn_topic_0000001127125088_p135711197293"></a>#000000</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001127125088_p17389105762819"><a name="zh-cn_topic_0000001127125088_p17389105762819"></a><a name="zh-cn_topic_0000001127125088_p17389105762819"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="57.25%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001127125088_a83b9b1430350465dbd6a99d5a0338e2c"><a name="zh-cn_topic_0000001127125088_a83b9b1430350465dbd6a99d5a0338e2c"></a><a name="zh-cn_topic_0000001127125088_a83b9b1430350465dbd6a99d5a0338e2c"></a>表示绘制当前线段的颜色。此颜色不设置会默认使用整体的strokeColor。</p>
</td>
</tr>
</tbody>
</table>

**表 9**  DataSegment<sup>5+</sup>

<a name="zh-cn_topic_0000001127125088_table2596183616210"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001127125088_row15969362212"><th class="cellrowborder" valign="top" width="11.85%" id="mcps1.2.6.1.1"><p id="zh-cn_topic_0000001127125088_p159616362220"><a name="zh-cn_topic_0000001127125088_p159616362220"></a><a name="zh-cn_topic_0000001127125088_p159616362220"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="12.030000000000001%" id="mcps1.2.6.1.2"><p id="zh-cn_topic_0000001127125088_p175961136723"><a name="zh-cn_topic_0000001127125088_p175961136723"></a><a name="zh-cn_topic_0000001127125088_p175961136723"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="9.83%" id="mcps1.2.6.1.3"><p id="zh-cn_topic_0000001127125088_p259612361126"><a name="zh-cn_topic_0000001127125088_p259612361126"></a><a name="zh-cn_topic_0000001127125088_p259612361126"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="9.04%" id="mcps1.2.6.1.4"><p id="zh-cn_topic_0000001127125088_p135975361628"><a name="zh-cn_topic_0000001127125088_p135975361628"></a><a name="zh-cn_topic_0000001127125088_p135975361628"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="57.25%" id="mcps1.2.6.1.5"><p id="zh-cn_topic_0000001127125088_p13597136925"><a name="zh-cn_topic_0000001127125088_p13597136925"></a><a name="zh-cn_topic_0000001127125088_p13597136925"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001127125088_row165974360212"><td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001127125088_p21970268105"><a name="zh-cn_topic_0000001127125088_p21970268105"></a><a name="zh-cn_topic_0000001127125088_p21970268105"></a>startColor</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001127125088_p21981526141010"><a name="zh-cn_topic_0000001127125088_p21981526141010"></a><a name="zh-cn_topic_0000001127125088_p21981526141010"></a>Color</p>
</td>
<td class="cellrowborder" valign="top" width="9.83%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001127125088_p71988268108"><a name="zh-cn_topic_0000001127125088_p71988268108"></a><a name="zh-cn_topic_0000001127125088_p71988268108"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001127125088_p6597133616215"><a name="zh-cn_topic_0000001127125088_p6597133616215"></a><a name="zh-cn_topic_0000001127125088_p6597133616215"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="57.25%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001127125088_p5652139121119"><a name="zh-cn_topic_0000001127125088_p5652139121119"></a><a name="zh-cn_topic_0000001127125088_p5652139121119"></a>起始位置的颜色，设置startColor必须设置endColor。不设置startColor时，会使用系统默认预置的颜色数组，具体颜色值见下表。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125088_row559719369213"><td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001127125088_p1419812651017"><a name="zh-cn_topic_0000001127125088_p1419812651017"></a><a name="zh-cn_topic_0000001127125088_p1419812651017"></a>endColor</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001127125088_p8198182631012"><a name="zh-cn_topic_0000001127125088_p8198182631012"></a><a name="zh-cn_topic_0000001127125088_p8198182631012"></a>Color</p>
</td>
<td class="cellrowborder" valign="top" width="9.83%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001127125088_p17198122612107"><a name="zh-cn_topic_0000001127125088_p17198122612107"></a><a name="zh-cn_topic_0000001127125088_p17198122612107"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001127125088_p059710361211"><a name="zh-cn_topic_0000001127125088_p059710361211"></a><a name="zh-cn_topic_0000001127125088_p059710361211"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="57.25%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001127125088_p11652139131117"><a name="zh-cn_topic_0000001127125088_p11652139131117"></a><a name="zh-cn_topic_0000001127125088_p11652139131117"></a>终止位置的颜色，设置endColor必须设置startColor。</p>
<p id="zh-cn_topic_0000001127125088_p10128174015175"><a name="zh-cn_topic_0000001127125088_p10128174015175"></a><a name="zh-cn_topic_0000001127125088_p10128174015175"></a>不设置startColor时，会使用系统默认预置的颜色数组。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125088_row85973361925"><td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001127125088_p91981926191015"><a name="zh-cn_topic_0000001127125088_p91981926191015"></a><a name="zh-cn_topic_0000001127125088_p91981926191015"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001127125088_p1219813268100"><a name="zh-cn_topic_0000001127125088_p1219813268100"></a><a name="zh-cn_topic_0000001127125088_p1219813268100"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="9.83%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001127125088_p01988268105"><a name="zh-cn_topic_0000001127125088_p01988268105"></a><a name="zh-cn_topic_0000001127125088_p01988268105"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001127125088_p1959819361216"><a name="zh-cn_topic_0000001127125088_p1959819361216"></a><a name="zh-cn_topic_0000001127125088_p1959819361216"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="57.25%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001127125088_p106521339131120"><a name="zh-cn_topic_0000001127125088_p106521339131120"></a><a name="zh-cn_topic_0000001127125088_p106521339131120"></a>占比数据的所占份额，最大100。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125088_row85983361124"><td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001127125088_p1119816260101"><a name="zh-cn_topic_0000001127125088_p1119816260101"></a><a name="zh-cn_topic_0000001127125088_p1119816260101"></a>name</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001127125088_p6198226161014"><a name="zh-cn_topic_0000001127125088_p6198226161014"></a><a name="zh-cn_topic_0000001127125088_p6198226161014"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.83%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001127125088_p1519852614107"><a name="zh-cn_topic_0000001127125088_p1519852614107"></a><a name="zh-cn_topic_0000001127125088_p1519852614107"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001127125088_p25984367213"><a name="zh-cn_topic_0000001127125088_p25984367213"></a><a name="zh-cn_topic_0000001127125088_p25984367213"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="57.25%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001127125088_p11653339151117"><a name="zh-cn_topic_0000001127125088_p11653339151117"></a><a name="zh-cn_topic_0000001127125088_p11653339151117"></a>此类数据的名称。</p>
</td>
</tr>
</tbody>
</table>

<a name="zh-cn_topic_0000001127125088_table19699121263711"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001127125088_row106991512133715"><th class="cellrowborder" valign="top" width="5.8205820582058205%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001127125088_p9699181218379"><a name="zh-cn_topic_0000001127125088_p9699181218379"></a><a name="zh-cn_topic_0000001127125088_p9699181218379"></a>数据组</p>
</th>
<th class="cellrowborder" valign="top" width="41.7941794179418%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001127125088_p1699171219372"><a name="zh-cn_topic_0000001127125088_p1699171219372"></a><a name="zh-cn_topic_0000001127125088_p1699171219372"></a>浅色主题</p>
</th>
<th class="cellrowborder" valign="top" width="52.38523852385239%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001127125088_p16699112103710"><a name="zh-cn_topic_0000001127125088_p16699112103710"></a><a name="zh-cn_topic_0000001127125088_p16699112103710"></a>深色主题</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001127125088_row9699112163711"><td class="cellrowborder" valign="top" width="5.8205820582058205%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001127125088_p36992012193712"><a name="zh-cn_topic_0000001127125088_p36992012193712"></a><a name="zh-cn_topic_0000001127125088_p36992012193712"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="41.7941794179418%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001127125088_p15700712163717"><a name="zh-cn_topic_0000001127125088_p15700712163717"></a><a name="zh-cn_topic_0000001127125088_p15700712163717"></a>起始颜色：#f7ce00，结束颜色：#f99b11</p>
</td>
<td class="cellrowborder" valign="top" width="52.38523852385239%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001127125088_p5700512173712"><a name="zh-cn_topic_0000001127125088_p5700512173712"></a><a name="zh-cn_topic_0000001127125088_p5700512173712"></a>起始颜色：#d1a738，结束颜色：#eb933d</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125088_row53180543816"><td class="cellrowborder" valign="top" width="5.8205820582058205%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001127125088_p931816516385"><a name="zh-cn_topic_0000001127125088_p931816516385"></a><a name="zh-cn_topic_0000001127125088_p931816516385"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="41.7941794179418%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001127125088_p2590113224315"><a name="zh-cn_topic_0000001127125088_p2590113224315"></a><a name="zh-cn_topic_0000001127125088_p2590113224315"></a>起始颜色：#f76223，结束颜色：#f2400a</p>
</td>
<td class="cellrowborder" valign="top" width="52.38523852385239%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001127125088_p153182553814"><a name="zh-cn_topic_0000001127125088_p153182553814"></a><a name="zh-cn_topic_0000001127125088_p153182553814"></a>起始颜色：#e67d50，结束颜色：#d9542b</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125088_row5161209163810"><td class="cellrowborder" valign="top" width="5.8205820582058205%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001127125088_p1616120910383"><a name="zh-cn_topic_0000001127125088_p1616120910383"></a><a name="zh-cn_topic_0000001127125088_p1616120910383"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="41.7941794179418%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001127125088_p91616973812"><a name="zh-cn_topic_0000001127125088_p91616973812"></a><a name="zh-cn_topic_0000001127125088_p91616973812"></a>起始颜色：#f772ac，结束颜色：#e65392</p>
</td>
<td class="cellrowborder" valign="top" width="52.38523852385239%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001127125088_p2161189183817"><a name="zh-cn_topic_0000001127125088_p2161189183817"></a><a name="zh-cn_topic_0000001127125088_p2161189183817"></a>起始颜色：#d5749e，结束颜色：#d6568d</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125088_row956361913385"><td class="cellrowborder" valign="top" width="5.8205820582058205%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001127125088_p12563181918388"><a name="zh-cn_topic_0000001127125088_p12563181918388"></a><a name="zh-cn_topic_0000001127125088_p12563181918388"></a>3</p>
</td>
<td class="cellrowborder" valign="top" width="41.7941794179418%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001127125088_p25633192386"><a name="zh-cn_topic_0000001127125088_p25633192386"></a><a name="zh-cn_topic_0000001127125088_p25633192386"></a>起始颜色：#a575eb，结束颜色：#a12df7</p>
</td>
<td class="cellrowborder" valign="top" width="52.38523852385239%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001127125088_p25631219183815"><a name="zh-cn_topic_0000001127125088_p25631219183815"></a><a name="zh-cn_topic_0000001127125088_p25631219183815"></a>起始颜色：#9973d1，结束颜色：#5552d9</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125088_row893012813389"><td class="cellrowborder" valign="top" width="5.8205820582058205%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001127125088_p1393092815385"><a name="zh-cn_topic_0000001127125088_p1393092815385"></a><a name="zh-cn_topic_0000001127125088_p1393092815385"></a>4</p>
</td>
<td class="cellrowborder" valign="top" width="41.7941794179418%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001127125088_p493092812387"><a name="zh-cn_topic_0000001127125088_p493092812387"></a><a name="zh-cn_topic_0000001127125088_p493092812387"></a>起始颜色：#7b79f7，结束颜色：#4b48f7</p>
</td>
<td class="cellrowborder" valign="top" width="52.38523852385239%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001127125088_p6930228123813"><a name="zh-cn_topic_0000001127125088_p6930228123813"></a><a name="zh-cn_topic_0000001127125088_p6930228123813"></a>起始颜色：#7977d9，结束颜色：#f99b11</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125088_row11109426123812"><td class="cellrowborder" valign="top" width="5.8205820582058205%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001127125088_p1010912612382"><a name="zh-cn_topic_0000001127125088_p1010912612382"></a><a name="zh-cn_topic_0000001127125088_p1010912612382"></a>5</p>
</td>
<td class="cellrowborder" valign="top" width="41.7941794179418%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001127125088_p4109026173811"><a name="zh-cn_topic_0000001127125088_p4109026173811"></a><a name="zh-cn_topic_0000001127125088_p4109026173811"></a>起始颜色：#4b8af3，结束颜色：#007dff</p>
</td>
<td class="cellrowborder" valign="top" width="52.38523852385239%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001127125088_p2109026173816"><a name="zh-cn_topic_0000001127125088_p2109026173816"></a><a name="zh-cn_topic_0000001127125088_p2109026173816"></a>起始颜色：#4c81d9，结束颜色：#217bd9</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125088_row1569813163818"><td class="cellrowborder" valign="top" width="5.8205820582058205%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001127125088_p196911318389"><a name="zh-cn_topic_0000001127125088_p196911318389"></a><a name="zh-cn_topic_0000001127125088_p196911318389"></a>6</p>
</td>
<td class="cellrowborder" valign="top" width="41.7941794179418%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001127125088_p186971323817"><a name="zh-cn_topic_0000001127125088_p186971323817"></a><a name="zh-cn_topic_0000001127125088_p186971323817"></a>起始颜色：#73c1e6，结束颜色：#4fb4e3</p>
</td>
<td class="cellrowborder" valign="top" width="52.38523852385239%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001127125088_p169513183810"><a name="zh-cn_topic_0000001127125088_p169513183810"></a><a name="zh-cn_topic_0000001127125088_p169513183810"></a>起始颜色：#5ea6d1，结束颜色：#4895c2</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125088_row1428922313819"><td class="cellrowborder" valign="top" width="5.8205820582058205%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001127125088_p628912231384"><a name="zh-cn_topic_0000001127125088_p628912231384"></a><a name="zh-cn_topic_0000001127125088_p628912231384"></a>7</p>
</td>
<td class="cellrowborder" valign="top" width="41.7941794179418%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001127125088_p0289823193820"><a name="zh-cn_topic_0000001127125088_p0289823193820"></a><a name="zh-cn_topic_0000001127125088_p0289823193820"></a>起始颜色：#a5d61d，结束颜色：#69d14f</p>
</td>
<td class="cellrowborder" valign="top" width="52.38523852385239%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001127125088_p12289192316386"><a name="zh-cn_topic_0000001127125088_p12289192316386"></a><a name="zh-cn_topic_0000001127125088_p12289192316386"></a>起始颜色：#91c23a，结束颜色：#70ba5d</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125088_row10565416153819"><td class="cellrowborder" valign="top" width="5.8205820582058205%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001127125088_p156516165388"><a name="zh-cn_topic_0000001127125088_p156516165388"></a><a name="zh-cn_topic_0000001127125088_p156516165388"></a>8</p>
</td>
<td class="cellrowborder" valign="top" width="41.7941794179418%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001127125088_p175652016143816"><a name="zh-cn_topic_0000001127125088_p175652016143816"></a><a name="zh-cn_topic_0000001127125088_p175652016143816"></a>起始颜色：#a2a2b0，结束颜色：#8e8e93</p>
</td>
<td class="cellrowborder" valign="top" width="52.38523852385239%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001127125088_p5565101633813"><a name="zh-cn_topic_0000001127125088_p5565101633813"></a><a name="zh-cn_topic_0000001127125088_p5565101633813"></a>起始颜色：#8c8c99，结束颜色：#6b6b76</p>
</td>
</tr>
</tbody>
</table>

当类型为量规图时，还支持如下属性：

<a name="zh-cn_topic_0000001127125088_table591221715358"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001127125088_row7912417143518"><th class="cellrowborder" valign="top" width="23.52%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001127125088_p19912161763516"><a name="zh-cn_topic_0000001127125088_p19912161763516"></a><a name="zh-cn_topic_0000001127125088_p19912161763516"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="11.76%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001127125088_p11912151718350"><a name="zh-cn_topic_0000001127125088_p11912151718350"></a><a name="zh-cn_topic_0000001127125088_p11912151718350"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="11.72%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001127125088_p1791231713518"><a name="zh-cn_topic_0000001127125088_p1791231713518"></a><a name="zh-cn_topic_0000001127125088_p1791231713518"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="8%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001127125088_p7913161710357"><a name="zh-cn_topic_0000001127125088_p7913161710357"></a><a name="zh-cn_topic_0000001127125088_p7913161710357"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="45%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001127125088_p9913111717353"><a name="zh-cn_topic_0000001127125088_p9913111717353"></a><a name="zh-cn_topic_0000001127125088_p9913111717353"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001127125088_row99131917123518"><td class="cellrowborder" valign="top" width="23.52%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125088_p1091312179351"><a name="zh-cn_topic_0000001127125088_p1091312179351"></a><a name="zh-cn_topic_0000001127125088_p1091312179351"></a>percent</p>
</td>
<td class="cellrowborder" valign="top" width="11.76%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125088_p20913111723518"><a name="zh-cn_topic_0000001127125088_p20913111723518"></a><a name="zh-cn_topic_0000001127125088_p20913111723518"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.72%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125088_p891361723510"><a name="zh-cn_topic_0000001127125088_p891361723510"></a><a name="zh-cn_topic_0000001127125088_p891361723510"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="8%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125088_p1913151711357"><a name="zh-cn_topic_0000001127125088_p1913151711357"></a><a name="zh-cn_topic_0000001127125088_p1913151711357"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="45%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125088_p39134178350"><a name="zh-cn_topic_0000001127125088_p39134178350"></a><a name="zh-cn_topic_0000001127125088_p39134178350"></a>当前值占整体的百分比，取值范围为0-100。</p>
</td>
</tr>
</tbody>
</table>

## 样式<a name="zh-cn_topic_0000001127125088_section5775351116"></a>

除支持[通用样式](js-components-common-styles.md)外，还支持如下样式：

<a name="zh-cn_topic_0000001127125088_table16167160154918"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001127125088_row916790104917"><th class="cellrowborder" valign="top" width="23.11768823117688%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001127125088_p516718013494"><a name="zh-cn_topic_0000001127125088_p516718013494"></a><a name="zh-cn_topic_0000001127125088_p516718013494"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="20.477952204779523%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001127125088_p131682094915"><a name="zh-cn_topic_0000001127125088_p131682094915"></a><a name="zh-cn_topic_0000001127125088_p131682094915"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="8.869113088691131%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001127125088_p1816816074917"><a name="zh-cn_topic_0000001127125088_p1816816074917"></a><a name="zh-cn_topic_0000001127125088_p1816816074917"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.519248075192481%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001127125088_p81681406495"><a name="zh-cn_topic_0000001127125088_p81681406495"></a><a name="zh-cn_topic_0000001127125088_p81681406495"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="40.01599840015999%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001127125088_p31682054916"><a name="zh-cn_topic_0000001127125088_p31682054916"></a><a name="zh-cn_topic_0000001127125088_p31682054916"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001127125088_row5168305498"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125088_p816816014492"><a name="zh-cn_topic_0000001127125088_p816816014492"></a><a name="zh-cn_topic_0000001127125088_p816816014492"></a>stroke-width</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125088_p5168160154919"><a name="zh-cn_topic_0000001127125088_p5168160154919"></a><a name="zh-cn_topic_0000001127125088_p5168160154919"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125088_p1116819014497"><a name="zh-cn_topic_0000001127125088_p1116819014497"></a><a name="zh-cn_topic_0000001127125088_p1116819014497"></a>32px（量规）</p>
<p id="zh-cn_topic_0000001127125088_p1616812094911"><a name="zh-cn_topic_0000001127125088_p1616812094911"></a><a name="zh-cn_topic_0000001127125088_p1616812094911"></a>24px（占比类圆形图表）</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125088_p171681805495"><a name="zh-cn_topic_0000001127125088_p171681805495"></a><a name="zh-cn_topic_0000001127125088_p171681805495"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125088_p21684012495"><a name="zh-cn_topic_0000001127125088_p21684012495"></a><a name="zh-cn_topic_0000001127125088_p21684012495"></a>量规<span id="zh-cn_topic_0000001127125088_ph616840154918"><a name="zh-cn_topic_0000001127125088_ph616840154918"></a><a name="zh-cn_topic_0000001127125088_ph616840154918"></a>、占比类圆形图表</span>组件刻度条的宽度。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125088_row1716813094910"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125088_p1916811017495"><a name="zh-cn_topic_0000001127125088_p1916811017495"></a><a name="zh-cn_topic_0000001127125088_p1916811017495"></a>start-angle</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125088_p1416812019496"><a name="zh-cn_topic_0000001127125088_p1416812019496"></a><a name="zh-cn_topic_0000001127125088_p1416812019496"></a>&lt;deg&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125088_p171685064917"><a name="zh-cn_topic_0000001127125088_p171685064917"></a><a name="zh-cn_topic_0000001127125088_p171685064917"></a>240（量规）</p>
<p id="zh-cn_topic_0000001127125088_p116813013494"><a name="zh-cn_topic_0000001127125088_p116813013494"></a><a name="zh-cn_topic_0000001127125088_p116813013494"></a>0（占比类圆形图表）</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125088_p15169180194910"><a name="zh-cn_topic_0000001127125088_p15169180194910"></a><a name="zh-cn_topic_0000001127125088_p15169180194910"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125088_p7169800499"><a name="zh-cn_topic_0000001127125088_p7169800499"></a><a name="zh-cn_topic_0000001127125088_p7169800499"></a>量规<span id="zh-cn_topic_0000001127125088_ph41696012491"><a name="zh-cn_topic_0000001127125088_ph41696012491"></a><a name="zh-cn_topic_0000001127125088_ph41696012491"></a>、占比类圆形图表</span>组件刻度条起始角度，以时钟0点为基线。范围为0到360。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125088_row11698018494"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125088_p716950134916"><a name="zh-cn_topic_0000001127125088_p716950134916"></a><a name="zh-cn_topic_0000001127125088_p716950134916"></a>total-angle</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125088_p161691012494"><a name="zh-cn_topic_0000001127125088_p161691012494"></a><a name="zh-cn_topic_0000001127125088_p161691012494"></a>&lt;deg&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125088_p16169140134920"><a name="zh-cn_topic_0000001127125088_p16169140134920"></a><a name="zh-cn_topic_0000001127125088_p16169140134920"></a>240（量规）</p>
<p id="zh-cn_topic_0000001127125088_p5169170184918"><a name="zh-cn_topic_0000001127125088_p5169170184918"></a><a name="zh-cn_topic_0000001127125088_p5169170184918"></a>360（占比类圆形图表）</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125088_p21699094912"><a name="zh-cn_topic_0000001127125088_p21699094912"></a><a name="zh-cn_topic_0000001127125088_p21699094912"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125088_p31692011497"><a name="zh-cn_topic_0000001127125088_p31692011497"></a><a name="zh-cn_topic_0000001127125088_p31692011497"></a>量规<span id="zh-cn_topic_0000001127125088_ph1016980124914"><a name="zh-cn_topic_0000001127125088_ph1016980124914"></a><a name="zh-cn_topic_0000001127125088_ph1016980124914"></a>、占比类圆形图表</span>组件刻度条总长度，范围为-360到360，负数标识起点到终点为逆时针。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125088_row141698034916"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125088_p181694074916"><a name="zh-cn_topic_0000001127125088_p181694074916"></a><a name="zh-cn_topic_0000001127125088_p181694074916"></a>center-x</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125088_p181691305493"><a name="zh-cn_topic_0000001127125088_p181691305493"></a><a name="zh-cn_topic_0000001127125088_p181691305493"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125088_p1716980174916"><a name="zh-cn_topic_0000001127125088_p1716980174916"></a><a name="zh-cn_topic_0000001127125088_p1716980174916"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125088_p81695024910"><a name="zh-cn_topic_0000001127125088_p81695024910"></a><a name="zh-cn_topic_0000001127125088_p81695024910"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125088_p1416960174911"><a name="zh-cn_topic_0000001127125088_p1416960174911"></a><a name="zh-cn_topic_0000001127125088_p1416960174911"></a>量规组件刻度条中心位置，该样式优先于通用样式的position样式。该样式需要和center-y和radius一起配置才能生效。（仅量规图支持）</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125088_row3169150184914"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125088_p7169002498"><a name="zh-cn_topic_0000001127125088_p7169002498"></a><a name="zh-cn_topic_0000001127125088_p7169002498"></a>center-y</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125088_p17170406499"><a name="zh-cn_topic_0000001127125088_p17170406499"></a><a name="zh-cn_topic_0000001127125088_p17170406499"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125088_p121705094916"><a name="zh-cn_topic_0000001127125088_p121705094916"></a><a name="zh-cn_topic_0000001127125088_p121705094916"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125088_p191706020496"><a name="zh-cn_topic_0000001127125088_p191706020496"></a><a name="zh-cn_topic_0000001127125088_p191706020496"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125088_p18170170194913"><a name="zh-cn_topic_0000001127125088_p18170170194913"></a><a name="zh-cn_topic_0000001127125088_p18170170194913"></a>量规组件刻度条中心位置，该样式优先于通用样式的position样式。该样式需要和center-x和radius一起配置才能生效。（仅量规图支持）</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125088_row6170208490"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125088_p1317016019498"><a name="zh-cn_topic_0000001127125088_p1317016019498"></a><a name="zh-cn_topic_0000001127125088_p1317016019498"></a>radius</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125088_p1717012014495"><a name="zh-cn_topic_0000001127125088_p1717012014495"></a><a name="zh-cn_topic_0000001127125088_p1717012014495"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125088_p1317019013497"><a name="zh-cn_topic_0000001127125088_p1317019013497"></a><a name="zh-cn_topic_0000001127125088_p1317019013497"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125088_p1717013074913"><a name="zh-cn_topic_0000001127125088_p1717013074913"></a><a name="zh-cn_topic_0000001127125088_p1717013074913"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125088_p7170507496"><a name="zh-cn_topic_0000001127125088_p7170507496"></a><a name="zh-cn_topic_0000001127125088_p7170507496"></a>量规组件刻度条半径，该样式优先于通用样式的width和height样式。该样式需要和center-x和center-y一起配置才能生效。（仅量规图支持）</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125088_row121701019491"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125088_p181706004913"><a name="zh-cn_topic_0000001127125088_p181706004913"></a><a name="zh-cn_topic_0000001127125088_p181706004913"></a>colors</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125088_p017013014920"><a name="zh-cn_topic_0000001127125088_p017013014920"></a><a name="zh-cn_topic_0000001127125088_p017013014920"></a>Array</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125088_p1417012054917"><a name="zh-cn_topic_0000001127125088_p1417012054917"></a><a name="zh-cn_topic_0000001127125088_p1417012054917"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125088_p10170130184918"><a name="zh-cn_topic_0000001127125088_p10170130184918"></a><a name="zh-cn_topic_0000001127125088_p10170130184918"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125088_p1817012014490"><a name="zh-cn_topic_0000001127125088_p1817012014490"></a><a name="zh-cn_topic_0000001127125088_p1817012014490"></a>量规组件刻度条每一个区段的颜色。</p>
<p id="zh-cn_topic_0000001127125088_p1617017094918"><a name="zh-cn_topic_0000001127125088_p1617017094918"></a><a name="zh-cn_topic_0000001127125088_p1617017094918"></a>如：colors: #ff0000, #00ff00。（仅量规图支持）</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125088_row101710024913"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125088_p141715084914"><a name="zh-cn_topic_0000001127125088_p141715084914"></a><a name="zh-cn_topic_0000001127125088_p141715084914"></a>weights</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125088_p20171201495"><a name="zh-cn_topic_0000001127125088_p20171201495"></a><a name="zh-cn_topic_0000001127125088_p20171201495"></a>Array</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125088_p1117140144911"><a name="zh-cn_topic_0000001127125088_p1117140144911"></a><a name="zh-cn_topic_0000001127125088_p1117140144911"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125088_p71716012490"><a name="zh-cn_topic_0000001127125088_p71716012490"></a><a name="zh-cn_topic_0000001127125088_p71716012490"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125088_p3171160114915"><a name="zh-cn_topic_0000001127125088_p3171160114915"></a><a name="zh-cn_topic_0000001127125088_p3171160114915"></a>量规组件刻度条每一个区段的权重。</p>
<p id="zh-cn_topic_0000001127125088_p2171140124910"><a name="zh-cn_topic_0000001127125088_p2171140124910"></a><a name="zh-cn_topic_0000001127125088_p2171140124910"></a>如：weights: 2, 2。（仅量规图支持）</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125088_row6171100114916"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125088_p117115044916"><a name="zh-cn_topic_0000001127125088_p117115044916"></a><a name="zh-cn_topic_0000001127125088_p117115044916"></a>font-family<sup id="zh-cn_topic_0000001127125088_sup111711400490"><a name="zh-cn_topic_0000001127125088_sup111711400490"></a><a name="zh-cn_topic_0000001127125088_sup111711400490"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125088_p917160104910"><a name="zh-cn_topic_0000001127125088_p917160104910"></a><a name="zh-cn_topic_0000001127125088_p917160104910"></a>Array</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125088_p117113014494"><a name="zh-cn_topic_0000001127125088_p117113014494"></a><a name="zh-cn_topic_0000001127125088_p117113014494"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125088_p517117018496"><a name="zh-cn_topic_0000001127125088_p517117018496"></a><a name="zh-cn_topic_0000001127125088_p517117018496"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125088_p1417110074919"><a name="zh-cn_topic_0000001127125088_p1417110074919"></a><a name="zh-cn_topic_0000001127125088_p1417110074919"></a>表示绘制注释的字体样式，支持<a href="js-components-common-customizing-font.md">自定义字体</a>。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125088_row1117115018499"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125088_p151710024910"><a name="zh-cn_topic_0000001127125088_p151710024910"></a><a name="zh-cn_topic_0000001127125088_p151710024910"></a>font-size<sup id="zh-cn_topic_0000001127125088_sup917220194912"><a name="zh-cn_topic_0000001127125088_sup917220194912"></a><a name="zh-cn_topic_0000001127125088_sup917220194912"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125088_p01728014915"><a name="zh-cn_topic_0000001127125088_p01728014915"></a><a name="zh-cn_topic_0000001127125088_p01728014915"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125088_p5172120114913"><a name="zh-cn_topic_0000001127125088_p5172120114913"></a><a name="zh-cn_topic_0000001127125088_p5172120114913"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125088_p71729010499"><a name="zh-cn_topic_0000001127125088_p71729010499"></a><a name="zh-cn_topic_0000001127125088_p71729010499"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125088_p1517210104914"><a name="zh-cn_topic_0000001127125088_p1517210104914"></a><a name="zh-cn_topic_0000001127125088_p1517210104914"></a>表示绘制注释的字体的大小。</p>
</td>
</tr>
</tbody>
</table>

## 事件<a name="zh-cn_topic_0000001127125088_section749131815264"></a>

支持[通用事件](js-components-common-events.md)。

## 方法<a name="zh-cn_topic_0000001127125088_section4480852195018"></a>

除支持[通用方法](js-components-common-methods.md)外，还支持如下方法：

<a name="zh-cn_topic_0000001127125088_table7480052145013"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001127125088_row64801152175016"><th class="cellrowborder" valign="top" width="8.630863086308631%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001127125088_p184801352105010"><a name="zh-cn_topic_0000001127125088_p184801352105010"></a><a name="zh-cn_topic_0000001127125088_p184801352105010"></a>方法</p>
</th>
<th class="cellrowborder" valign="top" width="58.035803580358035%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001127125088_p134801052175010"><a name="zh-cn_topic_0000001127125088_p134801052175010"></a><a name="zh-cn_topic_0000001127125088_p134801052175010"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001127125088_p3480452115015"><a name="zh-cn_topic_0000001127125088_p3480452115015"></a><a name="zh-cn_topic_0000001127125088_p3480452115015"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001127125088_row1148112528509"><td class="cellrowborder" valign="top" width="8.630863086308631%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001127125088_p548115219507"><a name="zh-cn_topic_0000001127125088_p548115219507"></a><a name="zh-cn_topic_0000001127125088_p548115219507"></a>append</p>
</td>
<td class="cellrowborder" valign="top" width="58.035803580358035%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001127125088_p9481135295014"><a name="zh-cn_topic_0000001127125088_p9481135295014"></a><a name="zh-cn_topic_0000001127125088_p9481135295014"></a>{</p>
<p id="zh-cn_topic_0000001127125088_p1348165210500"><a name="zh-cn_topic_0000001127125088_p1348165210500"></a><a name="zh-cn_topic_0000001127125088_p1348165210500"></a>serial: number, // 设置要更新的线形图数据下标</p>
<p id="zh-cn_topic_0000001127125088_p15481175285010"><a name="zh-cn_topic_0000001127125088_p15481175285010"></a><a name="zh-cn_topic_0000001127125088_p15481175285010"></a>data: Array&lt;number&gt;, // 设置新增的数据</p>
<p id="zh-cn_topic_0000001127125088_p948113523503"><a name="zh-cn_topic_0000001127125088_p948113523503"></a><a name="zh-cn_topic_0000001127125088_p948113523503"></a>}</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001127125088_p7481952105010"><a name="zh-cn_topic_0000001127125088_p7481952105010"></a><a name="zh-cn_topic_0000001127125088_p7481952105010"></a>往已有的数据序列中动态添加数据，根据serial指定目标序列，serial为datasets数组的下标，从0开始。注意：不会更新datasets[index].data。仅线形图支持，按横坐标加1递增（与xAxis min/max设置相关）。</p>
</td>
</tr>
</tbody>
</table>

## 示例<a name="zh-cn_topic_0000001127125088_section164885329456"></a>

1.  线形图

    ```
    <!-- xxx.hml -->
    <div class="container">
      <stack class="chart-region">
        <image class="chart-background" src="common/background.png"></image>
        <chart class="chart-data" type="line" ref="linechart" options="{{lineOps}}" datasets="{{lineData}}"></chart>
      </stack>
      <button value="Add data" onclick="addData"></button>
    </div>
    ```

    ```
    /* xxx.css */
    .container {
      flex-direction: column;
      justify-content: center;
      align-items: center;
    }
    .chart-region {
      height: 400px;
      width: 700px;
    }
    .chart-background {
      object-fit: fill;
    }
    .chart-data {
      width: 700px;
      height: 600px;
    }
    button {
      width: 100%;
      height: 50px;
      background-color: #F4F2F1;
      text-color: #0C81F3;
    }
    ```

    ```
    // xxx.js
    export default {
      data: {
        lineData: [
          {
            strokeColor: '#0081ff',
            fillColor: '#cce5ff',
            data: [763, 550, 551, 554, 731, 654, 525, 696, 595, 628, 791, 505, 613, 575, 475, 553, 491, 680, 657, 716],
            gradient: true,
          }
        ],
        lineOps: {
          xAxis: {
            min: 0,
            max: 20,
            display: false,
          },
          yAxis: {
            min: 0,
            max: 1000,
            display: false,
          },
          series: {
            lineStyle: {
              width: "5px",
              smooth: true,
            },
            headPoint: {
              shape: "circle",
              size: 20,
              strokeWidth: 5,
              fillColor: '#ffffff',
              strokeColor: '#007aff',
              display: true,
            },
            loop: {
              margin: 2,
              gradient: true,
            }
          }
        },
      },
      addData() {
        this.$refs.linechart.append({
          serial: 0,
          data: [Math.floor(Math.random() * 400) + 400]
        })
      }
    }
    ```

    ![](figures/zh-cn_image_0000001212320069.png)

2.  柱状图

    ```
    <!-- xxx.hml -->
    <div class="container">
      <stack class="data-region">
        <image class="data-background" src="common/background.png"></image>
        <chart class="data-bar" type="bar" id="bar-chart" options="{{barOps}}" datasets="{{barData}}"></chart>
      </stack>
    </div>
    ```

    ```
    /* xxx.css */
    .container {
      flex-direction: column;
      justify-content: center;
      align-items: center;
    }
    .data-region {
      height: 400px;
      width: 700px;
    }
    .data-background {
      object-fit: fill;
    }
    .data-bar {
      width: 700px;
      height: 400px;
    }
    ```

    ```
    // xxx.js
    export default {
      data: {
        barData: [
          {
            fillColor: '#f07826',
            data: [763, 550, 551, 554, 731, 654, 525, 696, 595, 628],
          },
          {
            fillColor: '#cce5ff',
            data: [535, 776, 615, 444, 694, 785, 677, 609, 562, 410],
          },
          {
            fillColor: '#ff88bb',
            data: [673, 500, 574, 483, 702, 583, 437, 506, 693, 657],
          },
        ],
        barOps: {
          xAxis: {
            min: 0,
            max: 20,
            display: false,
            axisTick: 10,
          },
          yAxis: {
            min: 0,
            max: 1000,
            display: false,
          },
        },
      }
    }
    ```

    ![](figures/barchart.png)

3.  量规图

    ```
    <!-- xxx.hml -->
    <div class="container">
      <div class="gauge-region">
        <chart class="data-gauge" type="gauge" percent = "50"></chart>
      </div>
    </div>
    ```

    ```
    /* xxx.css */
    .container {
      flex-direction: column;
      justify-content: center;
      align-items: center;
    }
    .gauge-region {
      height: 400px;
      width: 400px;
    }
    .data-gauge {
      colors: #83f115, #fd3636, #3bf8ff;
      weights: 4, 2, 1;
    }
    ```

    ![](figures/gauge.png)


