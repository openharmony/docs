# chart<a name="EN-US_TOPIC_0000001127125088"></a>

The  **<chart\>**  component displays line charts, gauge charts, and bar charts.

## Required Permissions<a name="section11257113618419"></a>

None

## Child Component<a name="section9288143101012"></a>

Not supported

## Attributes<a name="section2907183951110"></a>

In addition to the attributes in  [Universal Attributes](js-components-common-attributes.md), the following attributes are supported.

<a name="table20633101642315"></a>
<table><thead align="left"><tr id="row663331618238"><th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.1"><p id="aa872998ac2d84843a3c5161889afffef"><a name="aa872998ac2d84843a3c5161889afffef"></a><a name="aa872998ac2d84843a3c5161889afffef"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.2"><p id="ab2111648ee0e4f6d881be8954e7acaab"><a name="ab2111648ee0e4f6d881be8954e7acaab"></a><a name="ab2111648ee0e4f6d881be8954e7acaab"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="10.48%" id="mcps1.1.6.1.3"><p id="ab377d1c90900478ea4ecab51e9a058af"><a name="ab377d1c90900478ea4ecab51e9a058af"></a><a name="ab377d1c90900478ea4ecab51e9a058af"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.6.1.4"><p id="p824610360217"><a name="p824610360217"></a><a name="p824610360217"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="35.76%" id="mcps1.1.6.1.5"><p id="a1d574a0044ed42ec8a2603bc82734232"><a name="a1d574a0044ed42ec8a2603bc82734232"></a><a name="a1d574a0044ed42ec8a2603bc82734232"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row176434366222"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p157531437142216"><a name="p157531437142216"></a><a name="p157531437142216"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p975314374228"><a name="p975314374228"></a><a name="p975314374228"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p2753113711229"><a name="p2753113711229"></a><a name="p2753113711229"></a>line</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p117532375222"><a name="p117532375222"></a><a name="p117532375222"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p12753143712225"><a name="p12753143712225"></a><a name="p12753143712225"></a>Chart type. Dynamic modification is not supported. Available values include:</p>
<a name="ul2754143714229"></a><a name="ul2754143714229"></a><ul id="ul2754143714229"><li><strong id="b380817522531"><a name="b380817522531"></a><a name="b380817522531"></a>bar</strong>: bar chart</li><li><strong id="b47791053195316"><a name="b47791053195316"></a><a name="b47791053195316"></a>line</strong>: line chart</li><li><strong id="b10329326115314"><a name="b10329326115314"></a><a name="b10329326115314"></a>gauge</strong>: gauge chart</li><li><strong id="b118466531142"><a name="b118466531142"></a><a name="b118466531142"></a>progress</strong><sup id="sup116561549162915"><a name="sup116561549162915"></a><a name="sup116561549162915"></a>5+</sup>: circle chart of progresses</li><li><strong id="b91066210159"><a name="b91066210159"></a><a name="b91066210159"></a>loading</strong><sup id="sup1246145116541"><a name="sup1246145116541"></a><a name="sup1246145116541"></a>5+</sup>: circle chart of loading processes</li><li><strong id="b187912701513"><a name="b187912701513"></a><a name="b187912701513"></a>rainbow</strong><sup id="sup13727185218542"><a name="sup13727185218542"></a><a name="sup13727185218542"></a>5+</sup>: circle chart of proportions</li></ul>
</td>
</tr>
<tr id="row38691133172215"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p4754173712219"><a name="p4754173712219"></a><a name="p4754173712219"></a>options</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p1675423715225"><a name="p1675423715225"></a><a name="p1675423715225"></a><a href="#table12775365017">ChartOptions</a></p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p27541437112214"><a name="p27541437112214"></a><a name="p27541437112214"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p1475493712214"><a name="p1475493712214"></a><a name="p1475493712214"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p19754143732218"><a name="p19754143732218"></a><a name="p19754143732218"></a>Chart parameters. You must set parameters for bar charts and line charts. Parameter settings for gauge charts do not take effect. You can set the minimum value, maximum value, scale, and line width of the x-axis or y-axis, whether to display the x-axis and y-axis, and whether the line is smooth. Dynamic modification is not supported.</p>
</td>
</tr>
<tr id="row1541629182218"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p57547371229"><a name="p57547371229"></a><a name="p57547371229"></a>datasets</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p117541437172215"><a name="p117541437172215"></a><a name="p117541437172215"></a>Array&lt;<a href="#table13810518157">ChartDataset</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p7754203711221"><a name="p7754203711221"></a><a name="p7754203711221"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p18754183732216"><a name="p18754183732216"></a><a name="p18754183732216"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p775483772214"><a name="p775483772214"></a><a name="p775483772214"></a>Data set. You must set data sets for bar charts and line charts. Data set for a gauge chart does not take effect. You can set multiple datasets and their background colors.</p>
</td>
</tr>
<tr id="row28045213017"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p18811552104"><a name="p18811552104"></a><a name="p18811552104"></a>segments<sup id="sup567222913217"><a name="sup567222913217"></a><a name="sup567222913217"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p481105219011"><a name="p481105219011"></a><a name="p481105219011"></a><a href="#table2596183616210">DataSegment</a> | Array&lt;<a href="#table2596183616210">DataSegment</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p188135220013"><a name="p188135220013"></a><a name="p188135220013"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p78112529019"><a name="p78112529019"></a><a name="p78112529019"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p1455632813277"><a name="p1455632813277"></a><a name="p1455632813277"></a>Data structures used by <strong id="b1997913981710"><a name="b1997913981710"></a><a name="b1997913981710"></a>progress</strong>, <strong id="b991191118176"><a name="b991191118176"></a><a name="b991191118176"></a>loading</strong>, and <strong id="b962820295179"><a name="b962820295179"></a><a name="b962820295179"></a>rainbow</strong> charts.</p>
<p id="p19327195813510"><a name="p19327195813510"></a><a name="p19327195813510"></a><strong id="b196601530164710"><a name="b196601530164710"></a><a name="b196601530164710"></a>DataSegment</strong> is available for <strong id="b1066083012472"><a name="b1066083012472"></a><a name="b1066083012472"></a>progress</strong> and <strong id="b16660143054719"><a name="b16660143054719"></a><a name="b16660143054719"></a>loading</strong> charts.</p>
<p id="p14326258457"><a name="p14326258457"></a><a name="p14326258457"></a><strong id="b1044023344716"><a name="b1044023344716"></a><a name="b1044023344716"></a>Array&lt;<a href="#table2596183616210">DataSegment</a>&gt;</strong> is available for <strong id="b194405335477"><a name="b194405335477"></a><a name="b194405335477"></a>rainbow</strong> charts. A maximum of nine <strong id="b15441133114716"><a name="b15441133114716"></a><a name="b15441133114716"></a>DataSegment</strong> are supported in the array.</p>
<div class="note" id="note74451328478"><a name="note74451328478"></a><a name="note74451328478"></a><span class="notetitle"> </span><div class="notebody"><p id="p1744552174711"><a name="p1744552174711"></a><a name="p1744552174711"></a></p>
</div></div>
</td>
</tr>
<tr id="row132072752211"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p1720712712227"><a name="p1720712712227"></a><a name="p1720712712227"></a>effects<sup id="sup98541850278"><a name="sup98541850278"></a><a name="sup98541850278"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p520815752212"><a name="p520815752212"></a><a name="p520815752212"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p220877132211"><a name="p220877132211"></a><a name="p220877132211"></a>true</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p1820820719229"><a name="p1820820719229"></a><a name="p1820820719229"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p92085712225"><a name="p92085712225"></a><a name="p92085712225"></a>Whether to enable the effects for <strong id="b7262163754711"><a name="b7262163754711"></a><a name="b7262163754711"></a>progress</strong> and <strong id="b12263437134715"><a name="b12263437134715"></a><a name="b12263437134715"></a>rainbow</strong> charts.</p>
<div class="note" id="note15640931164717"><a name="note15640931164717"></a><a name="note15640931164717"></a><span class="notetitle">  </span><div class="notebody"><p id="p2064014318476"><a name="p2064014318476"></a><a name="p2064014318476"></a></p>
</div></div>
</td>
</tr>
<tr id="row1133155620405"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p3133956174018"><a name="p3133956174018"></a><a name="p3133956174018"></a>animationduration<sup id="sup1079943994111"><a name="sup1079943994111"></a><a name="sup1079943994111"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p81331564406"><a name="p81331564406"></a><a name="p81331564406"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p21331356194015"><a name="p21331356194015"></a><a name="p21331356194015"></a>3000</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p6133256124018"><a name="p6133256124018"></a><a name="p6133256124018"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p181331564408"><a name="p181331564408"></a><a name="p181331564408"></a>Animation duration for expanding a <strong id="b538918433184"><a name="b538918433184"></a><a name="b538918433184"></a>rainbow</strong> chart, in milliseconds.</p>
<div class="note" id="note12117134774716"><a name="note12117134774716"></a><a name="note12117134774716"></a><span class="notetitle">  </span><div class="notebody"><p id="p12117124720471"><a name="p12117124720471"></a><a name="p12117124720471"></a></p>
</div></div>
</td>
</tr>
</tbody>
</table>

**Table  1**  ChartOptions

<a name="table12775365017"></a>
<table><thead align="left"><tr id="row6277153195013"><th class="cellrowborder" valign="top" width="16%" id="mcps1.2.6.1.1"><p id="p1192913820507"><a name="p1192913820507"></a><a name="p1192913820507"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="17%" id="mcps1.2.6.1.2"><p id="p2929188125011"><a name="p2929188125011"></a><a name="p2929188125011"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="13%" id="mcps1.2.6.1.3"><p id="p6929688508"><a name="p6929688508"></a><a name="p6929688508"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="16%" id="mcps1.2.6.1.4"><p id="p1392938165014"><a name="p1392938165014"></a><a name="p1392938165014"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="38%" id="mcps1.2.6.1.5"><p id="p2092914815016"><a name="p2092914815016"></a><a name="p2092914815016"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2277638503"><td class="cellrowborder" valign="top" width="16%" headers="mcps1.2.6.1.1 "><p id="p127818375011"><a name="p127818375011"></a><a name="p127818375011"></a>xAxis</p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.2.6.1.2 "><p id="p18278183115020"><a name="p18278183115020"></a><a name="p18278183115020"></a><a href="#table11312112919528">ChartAxis</a></p>
</td>
<td class="cellrowborder" valign="top" width="13%" headers="mcps1.2.6.1.3 "><p id="p1327817316507"><a name="p1327817316507"></a><a name="p1327817316507"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.2.6.1.4 "><p id="p427813385011"><a name="p427813385011"></a><a name="p427813385011"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="38%" headers="mcps1.2.6.1.5 "><p id="p1795144819490"><a name="p1795144819490"></a><a name="p1795144819490"></a>X-axis parameters. You can set the minimum value, maximum value, and scale of the x-axis, and whether to display the x-axis.</p>
</td>
</tr>
<tr id="row14660105412507"><td class="cellrowborder" valign="top" width="16%" headers="mcps1.2.6.1.1 "><p id="p16611654205018"><a name="p16611654205018"></a><a name="p16611654205018"></a>yAxis</p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.2.6.1.2 "><p id="p1518631821017"><a name="p1518631821017"></a><a name="p1518631821017"></a><a href="#table11312112919528">ChartAxis</a></p>
</td>
<td class="cellrowborder" valign="top" width="13%" headers="mcps1.2.6.1.3 "><p id="p19661554145015"><a name="p19661554145015"></a><a name="p19661554145015"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.2.6.1.4 "><p id="p466145416502"><a name="p466145416502"></a><a name="p466145416502"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="38%" headers="mcps1.2.6.1.5 "><p id="p14661554125010"><a name="p14661554125010"></a><a name="p14661554125010"></a>Y-axis parameters. You can set the minimum value, maximum value, and scale of the y-axis, and whether to display the y-axis.</p>
</td>
</tr>
<tr id="row1816015565013"><td class="cellrowborder" valign="top" width="16%" headers="mcps1.2.6.1.1 "><p id="p1816005585019"><a name="p1816005585019"></a><a name="p1816005585019"></a>series</p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.2.6.1.2 "><p id="p91601455135019"><a name="p91601455135019"></a><a name="p91601455135019"></a><a href="#table029562010560">ChartSeries</a></p>
</td>
<td class="cellrowborder" valign="top" width="13%" headers="mcps1.2.6.1.3 "><p id="p416015565016"><a name="p416015565016"></a><a name="p416015565016"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.2.6.1.4 "><p id="p12160135565014"><a name="p12160135565014"></a><a name="p12160135565014"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="38%" headers="mcps1.2.6.1.5 "><p id="p236434673016"><a name="p236434673016"></a><a name="p236434673016"></a>Data sequence parameters.</p>
<a name="ul4402155710308"></a><a name="ul4402155710308"></a><ul id="ul4402155710308"><li>Line style, such as the line width and whether the line is smooth.</li><li>Style and size of the white point at the start of the line.</li></ul>
<div class="note" id="note163611718126"><a name="note163611718126"></a><a name="note163611718126"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p15361117191211"><a name="p15361117191211"></a><a name="p15361117191211"></a>Only line charts support this attribute.</p>
</div></div>
</td>
</tr>
</tbody>
</table>

**Table  2**  ChartDataset

<a name="table13810518157"></a>
<table><thead align="left"><tr id="row1839105121514"><th class="cellrowborder" valign="top" width="16.56%" id="mcps1.2.6.1.1"><p id="p106956431614"><a name="p106956431614"></a><a name="p106956431614"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="16.830000000000002%" id="mcps1.2.6.1.2"><p id="p0695204111617"><a name="p0695204111617"></a><a name="p0695204111617"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="12.989999999999998%" id="mcps1.2.6.1.3"><p id="p1069514141614"><a name="p1069514141614"></a><a name="p1069514141614"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="9.33%" id="mcps1.2.6.1.4"><p id="p969564191616"><a name="p969564191616"></a><a name="p969564191616"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="44.29%" id="mcps1.2.6.1.5"><p id="p1169616441615"><a name="p1169616441615"></a><a name="p1169616441615"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1383242819553"><td class="cellrowborder" valign="top" width="16.56%" headers="mcps1.2.6.1.1 "><p id="p13832192819557"><a name="p13832192819557"></a><a name="p13832192819557"></a>strokeColor</p>
</td>
<td class="cellrowborder" valign="top" width="16.830000000000002%" headers="mcps1.2.6.1.2 "><p id="p18321928145512"><a name="p18321928145512"></a><a name="p18321928145512"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="12.989999999999998%" headers="mcps1.2.6.1.3 "><p id="p1283202816559"><a name="p1283202816559"></a><a name="p1283202816559"></a>#ff6384</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.2.6.1.4 "><p id="p128322028155519"><a name="p128322028155519"></a><a name="p128322028155519"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="44.29%" headers="mcps1.2.6.1.5 "><p id="p383218285552"><a name="p383218285552"></a><a name="p383218285552"></a>Line color.</p>
<div class="note" id="note149682371351"><a name="note149682371351"></a><a name="note149682371351"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p189688371757"><a name="p189688371757"></a><a name="p189688371757"></a>Only line charts support this attribute.</p>
</div></div>
</td>
</tr>
<tr id="row207559395562"><td class="cellrowborder" valign="top" width="16.56%" headers="mcps1.2.6.1.1 "><p id="p177551539205614"><a name="p177551539205614"></a><a name="p177551539205614"></a>fillColor</p>
</td>
<td class="cellrowborder" valign="top" width="16.830000000000002%" headers="mcps1.2.6.1.2 "><p id="p15755143911563"><a name="p15755143911563"></a><a name="p15755143911563"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="12.989999999999998%" headers="mcps1.2.6.1.3 "><p id="p9755939185618"><a name="p9755939185618"></a><a name="p9755939185618"></a>#ff6384</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.2.6.1.4 "><p id="p1875553995610"><a name="p1875553995610"></a><a name="p1875553995610"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="44.29%" headers="mcps1.2.6.1.5 "><p id="p975563915619"><a name="p975563915619"></a><a name="p975563915619"></a>Fill color. For line charts, the value indicates the gradient color to fill.</p>
</td>
</tr>
<tr id="row16221319185010"><td class="cellrowborder" valign="top" width="16.56%" headers="mcps1.2.6.1.1 "><p id="p1939135171519"><a name="p1939135171519"></a><a name="p1939135171519"></a>data</p>
</td>
<td class="cellrowborder" valign="top" width="16.830000000000002%" headers="mcps1.2.6.1.2 "><p id="p93945114156"><a name="p93945114156"></a><a name="p93945114156"></a>Array&lt;number&gt; | Array&lt;<a href="#table1470733752019">Point</a>&gt;<sup id="sup748712541259"><a name="sup748712541259"></a><a name="sup748712541259"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="12.989999999999998%" headers="mcps1.2.6.1.3 "><p id="p1839951201514"><a name="p1839951201514"></a><a name="p1839951201514"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.2.6.1.4 "><p id="p4391651201517"><a name="p4391651201517"></a><a name="p4391651201517"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="44.29%" headers="mcps1.2.6.1.5 "><p id="p113975114159"><a name="p113975114159"></a><a name="p113975114159"></a>Data of the drawn line or bar.</p>
</td>
</tr>
<tr id="row284113911529"><td class="cellrowborder" valign="top" width="16.56%" headers="mcps1.2.6.1.1 "><p id="p884110975213"><a name="p884110975213"></a><a name="p884110975213"></a>gradient</p>
</td>
<td class="cellrowborder" valign="top" width="16.830000000000002%" headers="mcps1.2.6.1.2 "><p id="p168411494528"><a name="p168411494528"></a><a name="p168411494528"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="12.989999999999998%" headers="mcps1.2.6.1.3 "><p id="p7841992522"><a name="p7841992522"></a><a name="p7841992522"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.2.6.1.4 "><p id="p1684159195214"><a name="p1684159195214"></a><a name="p1684159195214"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="44.29%" headers="mcps1.2.6.1.5 "><p id="p198414916522"><a name="p198414916522"></a><a name="p198414916522"></a>Whether to display the gradient color.</p>
<div class="note" id="note55873241061"><a name="note55873241061"></a><a name="note55873241061"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p1558712410616"><a name="p1558712410616"></a><a name="p1558712410616"></a>Only line charts support this attribute.</p>
</div></div>
</td>
</tr>
</tbody>
</table>

**Table  3**  ChartAxis

<a name="table11312112919528"></a>
<table><thead align="left"><tr id="row1031252917522"><th class="cellrowborder" valign="top" width="16.650000000000002%" id="mcps1.2.6.1.1"><p id="p7835550165517"><a name="p7835550165517"></a><a name="p7835550165517"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="16.3%" id="mcps1.2.6.1.2"><p id="p2083515012555"><a name="p2083515012555"></a><a name="p2083515012555"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="12.91%" id="mcps1.2.6.1.3"><p id="p1283545016551"><a name="p1283545016551"></a><a name="p1283545016551"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="9.5%" id="mcps1.2.6.1.4"><p id="p18351650135519"><a name="p18351650135519"></a><a name="p18351650135519"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="44.64%" id="mcps1.2.6.1.5"><p id="p10835105017555"><a name="p10835105017555"></a><a name="p10835105017555"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row231352916527"><td class="cellrowborder" valign="top" width="16.650000000000002%" headers="mcps1.2.6.1.1 "><p id="p13313529145212"><a name="p13313529145212"></a><a name="p13313529145212"></a>min</p>
</td>
<td class="cellrowborder" valign="top" width="16.3%" headers="mcps1.2.6.1.2 "><p id="p14313429185211"><a name="p14313429185211"></a><a name="p14313429185211"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="12.91%" headers="mcps1.2.6.1.3 "><p id="p19313152995219"><a name="p19313152995219"></a><a name="p19313152995219"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="9.5%" headers="mcps1.2.6.1.4 "><p id="p03131429165220"><a name="p03131429165220"></a><a name="p03131429165220"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="44.64%" headers="mcps1.2.6.1.5 "><p id="p15313529165215"><a name="p15313529165215"></a><a name="p15313529165215"></a>Minimum value of the axis.</p>
<div class="note" id="note947711273197"><a name="note947711273197"></a><a name="note947711273197"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p5477102781911"><a name="p5477102781911"></a><a name="p5477102781911"></a>Only line charts support negative numbers.</p>
</div></div>
</td>
</tr>
<tr id="row10177207165517"><td class="cellrowborder" valign="top" width="16.650000000000002%" headers="mcps1.2.6.1.1 "><p id="p191773713559"><a name="p191773713559"></a><a name="p191773713559"></a>max</p>
</td>
<td class="cellrowborder" valign="top" width="16.3%" headers="mcps1.2.6.1.2 "><p id="p11771076557"><a name="p11771076557"></a><a name="p11771076557"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="12.91%" headers="mcps1.2.6.1.3 "><p id="p13177127165511"><a name="p13177127165511"></a><a name="p13177127165511"></a>100</p>
</td>
<td class="cellrowborder" valign="top" width="9.5%" headers="mcps1.2.6.1.4 "><p id="p171774715517"><a name="p171774715517"></a><a name="p171774715517"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="44.64%" headers="mcps1.2.6.1.5 "><p id="p111771705519"><a name="p111771705519"></a><a name="p111771705519"></a>Maximum value of the axis.</p>
<div class="note" id="note1287217389195"><a name="note1287217389195"></a><a name="note1287217389195"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p17872153817197"><a name="p17872153817197"></a><a name="p17872153817197"></a>Only line charts support negative numbers.</p>
</div></div>
</td>
</tr>
<tr id="row54401875553"><td class="cellrowborder" valign="top" width="16.650000000000002%" headers="mcps1.2.6.1.1 "><p id="p544037145514"><a name="p544037145514"></a><a name="p544037145514"></a>axisTick</p>
</td>
<td class="cellrowborder" valign="top" width="16.3%" headers="mcps1.2.6.1.2 "><p id="p844011745512"><a name="p844011745512"></a><a name="p844011745512"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="12.91%" headers="mcps1.2.6.1.3 "><p id="p9440277558"><a name="p9440277558"></a><a name="p9440277558"></a>10</p>
</td>
<td class="cellrowborder" valign="top" width="9.5%" headers="mcps1.2.6.1.4 "><p id="p194406755518"><a name="p194406755518"></a><a name="p194406755518"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="44.64%" headers="mcps1.2.6.1.5 "><p id="p1144027105511"><a name="p1144027105511"></a><a name="p1144027105511"></a>Number of scales displayed on the axis.</p>
<div class="note" id="note18942121511202"><a name="note18942121511202"></a><a name="note18942121511202"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p4709421681"><a name="p4709421681"></a><a name="p4709421681"></a>The value ranges from 1 to 20. The display effect depends on the calculation result of Number of pixels occupied by the image width/(<strong id="b17205813354"><a name="b17205813354"></a><a name="b17205813354"></a>max</strong>-<strong id="b182718418359"><a name="b182718418359"></a><a name="b182718418359"></a>min</strong>).</p>
<p id="p234142016205"><a name="p234142016205"></a><a name="p234142016205"></a>In the bar chart, the number of bars in each group of data is the same as the number of scales, and the bars are displayed at the scales.</p>
</div></div>
</td>
</tr>
<tr id="row6558148125516"><td class="cellrowborder" valign="top" width="16.650000000000002%" headers="mcps1.2.6.1.1 "><p id="p1555818865515"><a name="p1555818865515"></a><a name="p1555818865515"></a>display</p>
</td>
<td class="cellrowborder" valign="top" width="16.3%" headers="mcps1.2.6.1.2 "><p id="p1755910815552"><a name="p1755910815552"></a><a name="p1755910815552"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="12.91%" headers="mcps1.2.6.1.3 "><p id="p2559108195515"><a name="p2559108195515"></a><a name="p2559108195515"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="9.5%" headers="mcps1.2.6.1.4 "><p id="p185597805514"><a name="p185597805514"></a><a name="p185597805514"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="44.64%" headers="mcps1.2.6.1.5 "><p id="p1655910815551"><a name="p1655910815551"></a><a name="p1655910815551"></a>Whether to display the axis.</p>
</td>
</tr>
<tr id="row1382114065515"><td class="cellrowborder" valign="top" width="16.650000000000002%" headers="mcps1.2.6.1.1 "><p id="p188221209555"><a name="p188221209555"></a><a name="p188221209555"></a>color</p>
</td>
<td class="cellrowborder" valign="top" width="16.3%" headers="mcps1.2.6.1.2 "><p id="p1782214025517"><a name="p1782214025517"></a><a name="p1782214025517"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="12.91%" headers="mcps1.2.6.1.3 "><p id="p482220185512"><a name="p482220185512"></a><a name="p482220185512"></a>#c0c0c0</p>
</td>
<td class="cellrowborder" valign="top" width="9.5%" headers="mcps1.2.6.1.4 "><p id="p782214015553"><a name="p782214015553"></a><a name="p782214015553"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="44.64%" headers="mcps1.2.6.1.5 "><p id="p4822202556"><a name="p4822202556"></a><a name="p4822202556"></a>Axis color.</p>
</td>
</tr>
</tbody>
</table>

**Table  4**  ChartSeries

<a name="table029562010560"></a>
<table><thead align="left"><tr id="row9295192095610"><th class="cellrowborder" valign="top" width="17%" id="mcps1.2.6.1.1"><p id="p10617123345612"><a name="p10617123345612"></a><a name="p10617123345612"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="16.39%" id="mcps1.2.6.1.2"><p id="p9617133175613"><a name="p9617133175613"></a><a name="p9617133175613"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="12.82%" id="mcps1.2.6.1.3"><p id="p3617153315562"><a name="p3617153315562"></a><a name="p3617153315562"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="10.11%" id="mcps1.2.6.1.4"><p id="p4617163305612"><a name="p4617163305612"></a><a name="p4617163305612"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="43.68%" id="mcps1.2.6.1.5"><p id="p1561718337569"><a name="p1561718337569"></a><a name="p1561718337569"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row13295162011563"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.2.6.1.1 "><p id="p2296820185612"><a name="p2296820185612"></a><a name="p2296820185612"></a>lineStyle</p>
</td>
<td class="cellrowborder" valign="top" width="16.39%" headers="mcps1.2.6.1.2 "><p id="p529652005615"><a name="p529652005615"></a><a name="p529652005615"></a><a href="#table7790183513918">ChartLineStyle</a></p>
</td>
<td class="cellrowborder" valign="top" width="12.82%" headers="mcps1.2.6.1.3 "><p id="p629612208561"><a name="p629612208561"></a><a name="p629612208561"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="10.11%" headers="mcps1.2.6.1.4 "><p id="p129632065619"><a name="p129632065619"></a><a name="p129632065619"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="43.68%" headers="mcps1.2.6.1.5 "><p id="p929652045614"><a name="p929652045614"></a><a name="p929652045614"></a>Line style, such as the line width and whether the line is smooth.</p>
</td>
</tr>
<tr id="row1829652010566"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.2.6.1.1 "><p id="p17296112017565"><a name="p17296112017565"></a><a name="p17296112017565"></a>headPoint</p>
</td>
<td class="cellrowborder" valign="top" width="16.39%" headers="mcps1.2.6.1.2 "><p id="p1829632018566"><a name="p1829632018566"></a><a name="p1829632018566"></a><a href="#table1435760101317">PointStyle</a></p>
</td>
<td class="cellrowborder" valign="top" width="12.82%" headers="mcps1.2.6.1.3 "><p id="p52966203569"><a name="p52966203569"></a><a name="p52966203569"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="10.11%" headers="mcps1.2.6.1.4 "><p id="p17296020155611"><a name="p17296020155611"></a><a name="p17296020155611"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="43.68%" headers="mcps1.2.6.1.5 "><p id="p14296132015616"><a name="p14296132015616"></a><a name="p14296132015616"></a>Style and size of the white point at the start of the line.</p>
</td>
</tr>
<tr id="row416985481620"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.2.6.1.1 "><p id="p816915441619"><a name="p816915441619"></a><a name="p816915441619"></a>topPoint</p>
</td>
<td class="cellrowborder" valign="top" width="16.39%" headers="mcps1.2.6.1.2 "><p id="p13169145471618"><a name="p13169145471618"></a><a name="p13169145471618"></a><a href="#table1435760101317">PointStyle</a></p>
</td>
<td class="cellrowborder" valign="top" width="12.82%" headers="mcps1.2.6.1.3 "><p id="p816995416164"><a name="p816995416164"></a><a name="p816995416164"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="10.11%" headers="mcps1.2.6.1.4 "><p id="p2017015417166"><a name="p2017015417166"></a><a name="p2017015417166"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="43.68%" headers="mcps1.2.6.1.5 "><p id="p98810719197"><a name="p98810719197"></a><a name="p98810719197"></a>Style and size of the top point.</p>
</td>
</tr>
<tr id="row9719195771616"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.2.6.1.1 "><p id="p12719857161614"><a name="p12719857161614"></a><a name="p12719857161614"></a>bottomPoint</p>
</td>
<td class="cellrowborder" valign="top" width="16.39%" headers="mcps1.2.6.1.2 "><p id="p631412816137"><a name="p631412816137"></a><a name="p631412816137"></a><a href="#table1435760101317">PointStyle</a></p>
</td>
<td class="cellrowborder" valign="top" width="12.82%" headers="mcps1.2.6.1.3 "><p id="p1771995719166"><a name="p1771995719166"></a><a name="p1771995719166"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="10.11%" headers="mcps1.2.6.1.4 "><p id="p77192571166"><a name="p77192571166"></a><a name="p77192571166"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="43.68%" headers="mcps1.2.6.1.5 "><p id="p10719357111610"><a name="p10719357111610"></a><a name="p10719357111610"></a>Style and size of the bottom point.</p>
</td>
</tr>
<tr id="row1165515117356"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.2.6.1.1 "><p id="p1065610143518"><a name="p1065610143518"></a><a name="p1065610143518"></a>loop</p>
</td>
<td class="cellrowborder" valign="top" width="16.39%" headers="mcps1.2.6.1.2 "><p id="p8656121143511"><a name="p8656121143511"></a><a name="p8656121143511"></a><a href="#table13982347173714">ChartLoop</a></p>
</td>
<td class="cellrowborder" valign="top" width="12.82%" headers="mcps1.2.6.1.3 "><p id="p765611163510"><a name="p765611163510"></a><a name="p765611163510"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="10.11%" headers="mcps1.2.6.1.4 "><p id="p1965671123510"><a name="p1965671123510"></a><a name="p1965671123510"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="43.68%" headers="mcps1.2.6.1.5 "><p id="p19656131113517"><a name="p19656131113517"></a><a name="p19656131113517"></a>Whether to start drawing again when the screen is looped.</p>
</td>
</tr>
</tbody>
</table>

**Table  5**  ChartLineStyle

<a name="table7790183513918"></a>
<table><thead align="left"><tr id="row167906351914"><th class="cellrowborder" valign="top" width="17.09%" id="mcps1.2.6.1.1"><p id="p15238040191012"><a name="p15238040191012"></a><a name="p15238040191012"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="16.91%" id="mcps1.2.6.1.2"><p id="p142381440151020"><a name="p142381440151020"></a><a name="p142381440151020"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="12.690000000000001%" id="mcps1.2.6.1.3"><p id="p723814051011"><a name="p723814051011"></a><a name="p723814051011"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="10.24%" id="mcps1.2.6.1.4"><p id="p623818402108"><a name="p623818402108"></a><a name="p623818402108"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="43.07%" id="mcps1.2.6.1.5"><p id="p1223834091020"><a name="p1223834091020"></a><a name="p1223834091020"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row47909350912"><td class="cellrowborder" valign="top" width="17.09%" headers="mcps1.2.6.1.1 "><p id="p13791135393"><a name="p13791135393"></a><a name="p13791135393"></a>width</p>
</td>
<td class="cellrowborder" valign="top" width="16.91%" headers="mcps1.2.6.1.2 "><p id="p5791123511915"><a name="p5791123511915"></a><a name="p5791123511915"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="12.690000000000001%" headers="mcps1.2.6.1.3 "><p id="p1479120352916"><a name="p1479120352916"></a><a name="p1479120352916"></a>1px</p>
</td>
<td class="cellrowborder" valign="top" width="10.24%" headers="mcps1.2.6.1.4 "><p id="p87911135691"><a name="p87911135691"></a><a name="p87911135691"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="43.07%" headers="mcps1.2.6.1.5 "><p id="p47917356918"><a name="p47917356918"></a><a name="p47917356918"></a>Line width.</p>
</td>
</tr>
<tr id="row1279183510911"><td class="cellrowborder" valign="top" width="17.09%" headers="mcps1.2.6.1.1 "><p id="p107913351297"><a name="p107913351297"></a><a name="p107913351297"></a>smooth</p>
</td>
<td class="cellrowborder" valign="top" width="16.91%" headers="mcps1.2.6.1.2 "><p id="p1479113515915"><a name="p1479113515915"></a><a name="p1479113515915"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="12.690000000000001%" headers="mcps1.2.6.1.3 "><p id="p179111356910"><a name="p179111356910"></a><a name="p179111356910"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="10.24%" headers="mcps1.2.6.1.4 "><p id="p979117355914"><a name="p979117355914"></a><a name="p979117355914"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="43.07%" headers="mcps1.2.6.1.5 "><p id="p1879113353920"><a name="p1879113353920"></a><a name="p1879113353920"></a>Whether the line is smooth.</p>
</td>
</tr>
</tbody>
</table>

**Table  6**  PointStyle

<a name="table1435760101317"></a>
<table><thead align="left"><tr id="row0357180181315"><th class="cellrowborder" valign="top" width="17.09%" id="mcps1.2.6.1.1"><p id="p763402181310"><a name="p763402181310"></a><a name="p763402181310"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="17.09%" id="mcps1.2.6.1.2"><p id="p963402171313"><a name="p963402171313"></a><a name="p963402171313"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="12.64%" id="mcps1.2.6.1.3"><p id="p166343212133"><a name="p166343212133"></a><a name="p166343212133"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="10.549999999999999%" id="mcps1.2.6.1.4"><p id="p4634621111311"><a name="p4634621111311"></a><a name="p4634621111311"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="42.63%" id="mcps1.2.6.1.5"><p id="p2063413215132"><a name="p2063413215132"></a><a name="p2063413215132"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row53581105131"><td class="cellrowborder" valign="top" width="17.09%" headers="mcps1.2.6.1.1 "><p id="p12358803137"><a name="p12358803137"></a><a name="p12358803137"></a>shape</p>
</td>
<td class="cellrowborder" valign="top" width="17.09%" headers="mcps1.2.6.1.2 "><p id="p19358190201313"><a name="p19358190201313"></a><a name="p19358190201313"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="12.64%" headers="mcps1.2.6.1.3 "><p id="p1358170141315"><a name="p1358170141315"></a><a name="p1358170141315"></a>circle</p>
</td>
<td class="cellrowborder" valign="top" width="10.549999999999999%" headers="mcps1.2.6.1.4 "><p id="p0358203135"><a name="p0358203135"></a><a name="p0358203135"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="42.63%" headers="mcps1.2.6.1.5 "><p id="p113581206134"><a name="p113581206134"></a><a name="p113581206134"></a>Shape of the highlight point. Available values are as follows:</p>
<a name="ul107389175319"></a><a name="ul107389175319"></a><ul id="ul107389175319"><li>Circle</li><li>Square</li><li>Triangle</li></ul>
</td>
</tr>
<tr id="row143581011317"><td class="cellrowborder" valign="top" width="17.09%" headers="mcps1.2.6.1.1 "><p id="p19358200201311"><a name="p19358200201311"></a><a name="p19358200201311"></a>size</p>
</td>
<td class="cellrowborder" valign="top" width="17.09%" headers="mcps1.2.6.1.2 "><p id="p93585011135"><a name="p93585011135"></a><a name="p93585011135"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="12.64%" headers="mcps1.2.6.1.3 "><p id="p203581081313"><a name="p203581081313"></a><a name="p203581081313"></a>5px</p>
</td>
<td class="cellrowborder" valign="top" width="10.549999999999999%" headers="mcps1.2.6.1.4 "><p id="p183582008137"><a name="p183582008137"></a><a name="p183582008137"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="42.63%" headers="mcps1.2.6.1.5 "><p id="p2358502135"><a name="p2358502135"></a><a name="p2358502135"></a>Size of the highlight point.</p>
</td>
</tr>
<tr id="row957985594815"><td class="cellrowborder" valign="top" width="17.09%" headers="mcps1.2.6.1.1 "><p id="p11579165564814"><a name="p11579165564814"></a><a name="p11579165564814"></a>strokeWidth</p>
</td>
<td class="cellrowborder" valign="top" width="17.09%" headers="mcps1.2.6.1.2 "><p id="p657916559486"><a name="p657916559486"></a><a name="p657916559486"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="12.64%" headers="mcps1.2.6.1.3 "><p id="p12579105514489"><a name="p12579105514489"></a><a name="p12579105514489"></a>1px</p>
</td>
<td class="cellrowborder" valign="top" width="10.549999999999999%" headers="mcps1.2.6.1.4 "><p id="p958015514480"><a name="p958015514480"></a><a name="p958015514480"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="42.63%" headers="mcps1.2.6.1.5 "><p id="p3580115534814"><a name="p3580115534814"></a><a name="p3580115534814"></a>Stroke width.</p>
</td>
</tr>
<tr id="row51421313317"><td class="cellrowborder" valign="top" width="17.09%" headers="mcps1.2.6.1.1 "><p id="p151432333315"><a name="p151432333315"></a><a name="p151432333315"></a>strokeColor</p>
</td>
<td class="cellrowborder" valign="top" width="17.09%" headers="mcps1.2.6.1.2 "><p id="p1914312363315"><a name="p1914312363315"></a><a name="p1914312363315"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="12.64%" headers="mcps1.2.6.1.3 "><p id="p114319316335"><a name="p114319316335"></a><a name="p114319316335"></a>#ff0000</p>
</td>
<td class="cellrowborder" valign="top" width="10.549999999999999%" headers="mcps1.2.6.1.4 "><p id="p11431036331"><a name="p11431036331"></a><a name="p11431036331"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="42.63%" headers="mcps1.2.6.1.5 "><p id="p181441434339"><a name="p181441434339"></a><a name="p181441434339"></a>Frame color.</p>
</td>
</tr>
<tr id="row1312214335332"><td class="cellrowborder" valign="top" width="17.09%" headers="mcps1.2.6.1.1 "><p id="p10123233193310"><a name="p10123233193310"></a><a name="p10123233193310"></a>fillColor</p>
</td>
<td class="cellrowborder" valign="top" width="17.09%" headers="mcps1.2.6.1.2 "><p id="p12123233123310"><a name="p12123233123310"></a><a name="p12123233123310"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="12.64%" headers="mcps1.2.6.1.3 "><p id="p10123143343313"><a name="p10123143343313"></a><a name="p10123143343313"></a>#ff0000</p>
</td>
<td class="cellrowborder" valign="top" width="10.549999999999999%" headers="mcps1.2.6.1.4 "><p id="p16123163317338"><a name="p16123163317338"></a><a name="p16123163317338"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="42.63%" headers="mcps1.2.6.1.5 "><p id="p6123433193311"><a name="p6123433193311"></a><a name="p6123433193311"></a>Fill color.</p>
</td>
</tr>
</tbody>
</table>

**Table  7**  ChartLoop

<a name="table13982347173714"></a>
<table><thead align="left"><tr id="row1498384714371"><th class="cellrowborder" valign="top" width="17.31%" id="mcps1.2.6.1.1"><p id="p1640543183916"><a name="p1640543183916"></a><a name="p1640543183916"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="17.65%" id="mcps1.2.6.1.2"><p id="p18640043143916"><a name="p18640043143916"></a><a name="p18640043143916"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="11.62%" id="mcps1.2.6.1.3"><p id="p12640144317398"><a name="p12640144317398"></a><a name="p12640144317398"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="11.39%" id="mcps1.2.6.1.4"><p id="p1764014343915"><a name="p1764014343915"></a><a name="p1764014343915"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="42.03%" id="mcps1.2.6.1.5"><p id="p1064084314395"><a name="p1064084314395"></a><a name="p1064084314395"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row8983164710376"><td class="cellrowborder" valign="top" width="17.31%" headers="mcps1.2.6.1.1 "><p id="p11983147113716"><a name="p11983147113716"></a><a name="p11983147113716"></a>margin</p>
</td>
<td class="cellrowborder" valign="top" width="17.65%" headers="mcps1.2.6.1.2 "><p id="p1898316477374"><a name="p1898316477374"></a><a name="p1898316477374"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="11.62%" headers="mcps1.2.6.1.3 "><p id="p139841479376"><a name="p139841479376"></a><a name="p139841479376"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="11.39%" headers="mcps1.2.6.1.4 "><p id="p169842479376"><a name="p169842479376"></a><a name="p169842479376"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="42.03%" headers="mcps1.2.6.1.5 "><p id="p798434723720"><a name="p798434723720"></a><a name="p798434723720"></a>Number of erased points (horizontal distance between the latest drawn point and the earliest point). You are not advised to use <strong id="b16357142745814"><a name="b16357142745814"></a><a name="b16357142745814"></a>margin</strong> together with <strong id="b188717325586"><a name="b188717325586"></a><a name="b188717325586"></a>topPoint</strong>, <strong id="b32281537165815"><a name="b32281537165815"></a><a name="b32281537165815"></a>bottomPoint</strong>, or <strong id="b2578114315585"><a name="b2578114315585"></a><a name="b2578114315585"></a>headPoint</strong> for lite devices. If you do so, there is a possibility that the point is in the erase area and invisible.</p>
</td>
</tr>
<tr id="row109849472372"><td class="cellrowborder" valign="top" width="17.31%" headers="mcps1.2.6.1.1 "><p id="p09841047183715"><a name="p09841047183715"></a><a name="p09841047183715"></a>gradient</p>
</td>
<td class="cellrowborder" valign="top" width="17.65%" headers="mcps1.2.6.1.2 "><p id="p92761838193812"><a name="p92761838193812"></a><a name="p92761838193812"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="11.62%" headers="mcps1.2.6.1.3 "><p id="p127603819380"><a name="p127603819380"></a><a name="p127603819380"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="11.39%" headers="mcps1.2.6.1.4 "><p id="p227733816384"><a name="p227733816384"></a><a name="p227733816384"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="42.03%" headers="mcps1.2.6.1.5 "><p id="p13277173823811"><a name="p13277173823811"></a><a name="p13277173823811"></a>Whether to perform gradient erase.</p>
</td>
</tr>
</tbody>
</table>

**Table  8**  Point<sup>5+</sup>

<a name="table1470733752019"></a>
<table><thead align="left"><tr id="row177072373203"><th class="cellrowborder" valign="top" width="11.85%" id="mcps1.2.6.1.1"><p id="p1770793715201"><a name="p1770793715201"></a><a name="p1770793715201"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="12.030000000000001%" id="mcps1.2.6.1.2"><p id="p137073372202"><a name="p137073372202"></a><a name="p137073372202"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="9.83%" id="mcps1.2.6.1.3"><p id="p47078377208"><a name="p47078377208"></a><a name="p47078377208"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="9.04%" id="mcps1.2.6.1.4"><p id="p1470719376206"><a name="p1470719376206"></a><a name="p1470719376206"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="57.25%" id="mcps1.2.6.1.5"><p id="p1370783712017"><a name="p1370783712017"></a><a name="p1370783712017"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row137071737112010"><td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.2.6.1.1 "><p id="p9707153711207"><a name="p9707153711207"></a><a name="p9707153711207"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.2.6.1.2 "><p id="p157081437132013"><a name="p157081437132013"></a><a name="p157081437132013"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="9.83%" headers="mcps1.2.6.1.3 "><p id="p970833722016"><a name="p970833722016"></a><a name="p970833722016"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.2.6.1.4 "><p id="p2070812378209"><a name="p2070812378209"></a><a name="p2070812378209"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="57.25%" headers="mcps1.2.6.1.5 "><p id="p188430361213"><a name="p188430361213"></a><a name="p188430361213"></a>Y coordinate of the point to draw.</p>
</td>
</tr>
<tr id="row13708173719202"><td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.2.6.1.1 "><p id="p18708143772014"><a name="p18708143772014"></a><a name="p18708143772014"></a>pointStyle</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.2.6.1.2 "><p id="p77081637172018"><a name="p77081637172018"></a><a name="p77081637172018"></a><a href="#table1435760101317">PointStyle</a></p>
</td>
<td class="cellrowborder" valign="top" width="9.83%" headers="mcps1.2.6.1.3 "><p id="p270803719206"><a name="p270803719206"></a><a name="p270803719206"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.2.6.1.4 "><p id="p19708133782018"><a name="p19708133782018"></a><a name="p19708133782018"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="57.25%" headers="mcps1.2.6.1.5 "><p id="p12708203712010"><a name="p12708203712010"></a><a name="p12708203712010"></a>Style of the point.</p>
</td>
</tr>
<tr id="row431291710242"><td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.2.6.1.1 "><p id="p13131917162412"><a name="p13131917162412"></a><a name="p13131917162412"></a>description</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.2.6.1.2 "><p id="p1231341710240"><a name="p1231341710240"></a><a name="p1231341710240"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.83%" headers="mcps1.2.6.1.3 "><p id="p14313121716241"><a name="p14313121716241"></a><a name="p14313121716241"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.2.6.1.4 "><p id="p13139178245"><a name="p13139178245"></a><a name="p13139178245"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="57.25%" headers="mcps1.2.6.1.5 "><p id="p11313171716246"><a name="p11313171716246"></a><a name="p11313171716246"></a>Description text of the point.</p>
</td>
</tr>
<tr id="row431301902517"><td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.2.6.1.1 "><p id="p1931461914251"><a name="p1931461914251"></a><a name="p1931461914251"></a>textLocation</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.2.6.1.2 "><p id="p1331471915257"><a name="p1331471915257"></a><a name="p1331471915257"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.83%" headers="mcps1.2.6.1.3 "><p id="p331431992516"><a name="p331431992516"></a><a name="p331431992516"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.2.6.1.4 "><p id="p33145199254"><a name="p33145199254"></a><a name="p33145199254"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="57.25%" headers="mcps1.2.6.1.5 "><p id="p6108637185"><a name="p6108637185"></a><a name="p6108637185"></a>Description text position relative to the point. Available values are as follows: </p>
<p id="p15749138180"><a name="p15749138180"></a><a name="p15749138180"></a><strong id="b117496386820"><a name="b117496386820"></a><a name="b117496386820"></a>top</strong>: above the point </p>
<p id="p65480401482"><a name="p65480401482"></a><a name="p65480401482"></a><strong id="b105484402815"><a name="b105484402815"></a><a name="b105484402815"></a>bottom</strong>: below the point </p>
<p id="p20314141922517"><a name="p20314141922517"></a><a name="p20314141922517"></a><strong id="b171799461313"><a name="b171799461313"></a><a name="b171799461313"></a>none</strong>: not displayed</p>
</td>
</tr>
<tr id="row48671150122613"><td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.2.6.1.1 "><p id="p486819509261"><a name="p486819509261"></a><a name="p486819509261"></a>textColor</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.2.6.1.2 "><p id="p12868165002617"><a name="p12868165002617"></a><a name="p12868165002617"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="9.83%" headers="mcps1.2.6.1.3 "><p id="p4868205002616"><a name="p4868205002616"></a><a name="p4868205002616"></a>#000000</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.2.6.1.4 "><p id="p1286825017267"><a name="p1286825017267"></a><a name="p1286825017267"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="57.25%" headers="mcps1.2.6.1.5 "><p id="p13868150162611"><a name="p13868150162611"></a><a name="p13868150162611"></a>Color of the description text.</p>
</td>
</tr>
<tr id="row9703542172713"><td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.2.6.1.1 "><p id="p1870364214275"><a name="p1870364214275"></a><a name="p1870364214275"></a>lineDash</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.2.6.1.2 "><p id="p1470334222718"><a name="p1470334222718"></a><a name="p1470334222718"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.83%" headers="mcps1.2.6.1.3 "><p id="p1670324217274"><a name="p1670324217274"></a><a name="p1670324217274"></a>solid</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.2.6.1.4 "><p id="p197033423272"><a name="p197033423272"></a><a name="p197033423272"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="57.25%" headers="mcps1.2.6.1.5 "><p id="p570304202712"><a name="p570304202712"></a><a name="p570304202712"></a>Dashed line pattern. You can set the dash length and space length between the dashes. For example, <strong id="b7111914270"><a name="b7111914270"></a><a name="b7111914270"></a>"dashed, 5, 5"</strong> indicates a dashed line with each dash in 5 px and a 5 px space between each two dashes. Default value <strong id="b08251016203215"><a name="b08251016203215"></a><a name="b08251016203215"></a>"solid"</strong> indicates a solid line.</p>
</td>
</tr>
<tr id="row15389105792810"><td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.2.6.1.1 "><p id="p15389357102818"><a name="p15389357102818"></a><a name="p15389357102818"></a>lineColor</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.2.6.1.2 "><p id="p3389135711281"><a name="p3389135711281"></a><a name="p3389135711281"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="9.83%" headers="mcps1.2.6.1.3 "><p id="p135711197293"><a name="p135711197293"></a><a name="p135711197293"></a>#000000</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.2.6.1.4 "><p id="p17389105762819"><a name="p17389105762819"></a><a name="p17389105762819"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="57.25%" headers="mcps1.2.6.1.5 "><p id="a83b9b1430350465dbd6a99d5a0338e2c"><a name="a83b9b1430350465dbd6a99d5a0338e2c"></a><a name="a83b9b1430350465dbd6a99d5a0338e2c"></a>Line color. If this attribute is not set, the <strong id="b17128123414344"><a name="b17128123414344"></a><a name="b17128123414344"></a>strokeColor</strong> is used by default.</p>
</td>
</tr>
</tbody>
</table>

**Table  9**  DataSegment<sup>5+</sup>

<a name="table2596183616210"></a>
<table><thead align="left"><tr id="row15969362212"><th class="cellrowborder" valign="top" width="11.85%" id="mcps1.2.6.1.1"><p id="p159616362220"><a name="p159616362220"></a><a name="p159616362220"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="12.030000000000001%" id="mcps1.2.6.1.2"><p id="p175961136723"><a name="p175961136723"></a><a name="p175961136723"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="9.83%" id="mcps1.2.6.1.3"><p id="p259612361126"><a name="p259612361126"></a><a name="p259612361126"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="9.04%" id="mcps1.2.6.1.4"><p id="p135975361628"><a name="p135975361628"></a><a name="p135975361628"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="57.25%" id="mcps1.2.6.1.5"><p id="p13597136925"><a name="p13597136925"></a><a name="p13597136925"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row165974360212"><td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.2.6.1.1 "><p id="p21970268105"><a name="p21970268105"></a><a name="p21970268105"></a>startColor</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.2.6.1.2 "><p id="p21981526141010"><a name="p21981526141010"></a><a name="p21981526141010"></a>Color</p>
</td>
<td class="cellrowborder" valign="top" width="9.83%" headers="mcps1.2.6.1.3 "><p id="p71988268108"><a name="p71988268108"></a><a name="p71988268108"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.2.6.1.4 "><p id="p6597133616215"><a name="p6597133616215"></a><a name="p6597133616215"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="57.25%" headers="mcps1.2.6.1.5 "><p id="p5652139121119"><a name="p5652139121119"></a><a name="p5652139121119"></a>Color of the start position. If this attribute is set, <strong id="b14583141810491"><a name="b14583141810491"></a><a name="b14583141810491"></a>endColor</strong> must be set. If this attribute is not set, the default color array preset in the system is used. For details about the color values, see the next table.</p>
</td>
</tr>
<tr id="row559719369213"><td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.2.6.1.1 "><p id="p1419812651017"><a name="p1419812651017"></a><a name="p1419812651017"></a>endColor</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.2.6.1.2 "><p id="p8198182631012"><a name="p8198182631012"></a><a name="p8198182631012"></a>Color</p>
</td>
<td class="cellrowborder" valign="top" width="9.83%" headers="mcps1.2.6.1.3 "><p id="p17198122612107"><a name="p17198122612107"></a><a name="p17198122612107"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.2.6.1.4 "><p id="p059710361211"><a name="p059710361211"></a><a name="p059710361211"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="57.25%" headers="mcps1.2.6.1.5 "><p id="p11652139131117"><a name="p11652139131117"></a><a name="p11652139131117"></a>Color of the end position. If this attribute is set, <strong id="b12654176135111"><a name="b12654176135111"></a><a name="b12654176135111"></a>startColor</strong> must be set.</p>
<p id="p10128174015175"><a name="p10128174015175"></a><a name="p10128174015175"></a>If this attribute is not set, the default color array preset in the system is used.</p>
</td>
</tr>
<tr id="row85973361925"><td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.2.6.1.1 "><p id="p91981926191015"><a name="p91981926191015"></a><a name="p91981926191015"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.2.6.1.2 "><p id="p1219813268100"><a name="p1219813268100"></a><a name="p1219813268100"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="9.83%" headers="mcps1.2.6.1.3 "><p id="p01988268105"><a name="p01988268105"></a><a name="p01988268105"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.2.6.1.4 "><p id="p1959819361216"><a name="p1959819361216"></a><a name="p1959819361216"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="57.25%" headers="mcps1.2.6.1.5 "><p id="p106521339131120"><a name="p106521339131120"></a><a name="p106521339131120"></a>Percentage for the current data segment. The maximum value is <strong id="b9780144416522"><a name="b9780144416522"></a><a name="b9780144416522"></a>100</strong>.</p>
</td>
</tr>
<tr id="row85983361124"><td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.2.6.1.1 "><p id="p1119816260101"><a name="p1119816260101"></a><a name="p1119816260101"></a>name</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.2.6.1.2 "><p id="p6198226161014"><a name="p6198226161014"></a><a name="p6198226161014"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.83%" headers="mcps1.2.6.1.3 "><p id="p1519852614107"><a name="p1519852614107"></a><a name="p1519852614107"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.2.6.1.4 "><p id="p25984367213"><a name="p25984367213"></a><a name="p25984367213"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="57.25%" headers="mcps1.2.6.1.5 "><p id="p11653339151117"><a name="p11653339151117"></a><a name="p11653339151117"></a>Name of this data segment.</p>
</td>
</tr>
</tbody>
</table>

<a name="table19699121263711"></a>
<table><thead align="left"><tr id="row106991512133715"><th class="cellrowborder" valign="top" width="5.8205820582058205%" id="mcps1.1.4.1.1"><p id="p9699181218379"><a name="p9699181218379"></a><a name="p9699181218379"></a>Data Segment</p>
</th>
<th class="cellrowborder" valign="top" width="41.7941794179418%" id="mcps1.1.4.1.2"><p id="p1699171219372"><a name="p1699171219372"></a><a name="p1699171219372"></a>Light Mode</p>
</th>
<th class="cellrowborder" valign="top" width="52.38523852385239%" id="mcps1.1.4.1.3"><p id="p16699112103710"><a name="p16699112103710"></a><a name="p16699112103710"></a>Dark Mode</p>
</th>
</tr>
</thead>
<tbody><tr id="row9699112163711"><td class="cellrowborder" valign="top" width="5.8205820582058205%" headers="mcps1.1.4.1.1 "><p id="p36992012193712"><a name="p36992012193712"></a><a name="p36992012193712"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="41.7941794179418%" headers="mcps1.1.4.1.2 "><p id="p15700712163717"><a name="p15700712163717"></a><a name="p15700712163717"></a>Start color: #f7ce00; end color: #f99b11</p>
</td>
<td class="cellrowborder" valign="top" width="52.38523852385239%" headers="mcps1.1.4.1.3 "><p id="p5700512173712"><a name="p5700512173712"></a><a name="p5700512173712"></a>Start color: #d1a738; end color: #eb933d</p>
</td>
</tr>
<tr id="row53180543816"><td class="cellrowborder" valign="top" width="5.8205820582058205%" headers="mcps1.1.4.1.1 "><p id="p931816516385"><a name="p931816516385"></a><a name="p931816516385"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="41.7941794179418%" headers="mcps1.1.4.1.2 "><p id="p2590113224315"><a name="p2590113224315"></a><a name="p2590113224315"></a>Start color: #f76223; end color: #f2400a</p>
</td>
<td class="cellrowborder" valign="top" width="52.38523852385239%" headers="mcps1.1.4.1.3 "><p id="p153182553814"><a name="p153182553814"></a><a name="p153182553814"></a>Start color: #e67d50; end color: #d9542b</p>
</td>
</tr>
<tr id="row5161209163810"><td class="cellrowborder" valign="top" width="5.8205820582058205%" headers="mcps1.1.4.1.1 "><p id="p1616120910383"><a name="p1616120910383"></a><a name="p1616120910383"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="41.7941794179418%" headers="mcps1.1.4.1.2 "><p id="p91616973812"><a name="p91616973812"></a><a name="p91616973812"></a>Start color: #f772ac; end color: #e65392</p>
</td>
<td class="cellrowborder" valign="top" width="52.38523852385239%" headers="mcps1.1.4.1.3 "><p id="p2161189183817"><a name="p2161189183817"></a><a name="p2161189183817"></a>Start color: #d5749e; end color: #d6568d</p>
</td>
</tr>
<tr id="row956361913385"><td class="cellrowborder" valign="top" width="5.8205820582058205%" headers="mcps1.1.4.1.1 "><p id="p12563181918388"><a name="p12563181918388"></a><a name="p12563181918388"></a>3</p>
</td>
<td class="cellrowborder" valign="top" width="41.7941794179418%" headers="mcps1.1.4.1.2 "><p id="p25633192386"><a name="p25633192386"></a><a name="p25633192386"></a>Start color: #a575eb; end color: #a12df7</p>
</td>
<td class="cellrowborder" valign="top" width="52.38523852385239%" headers="mcps1.1.4.1.3 "><p id="p25631219183815"><a name="p25631219183815"></a><a name="p25631219183815"></a>Start color: #9973d1; end color: #5552d9</p>
</td>
</tr>
<tr id="row893012813389"><td class="cellrowborder" valign="top" width="5.8205820582058205%" headers="mcps1.1.4.1.1 "><p id="p1393092815385"><a name="p1393092815385"></a><a name="p1393092815385"></a>4</p>
</td>
<td class="cellrowborder" valign="top" width="41.7941794179418%" headers="mcps1.1.4.1.2 "><p id="p493092812387"><a name="p493092812387"></a><a name="p493092812387"></a>Start color: #7b79f7; end color: #4b48f7</p>
</td>
<td class="cellrowborder" valign="top" width="52.38523852385239%" headers="mcps1.1.4.1.3 "><p id="p6930228123813"><a name="p6930228123813"></a><a name="p6930228123813"></a>Start color: #7977d9; end color: #f99b11</p>
</td>
</tr>
<tr id="row11109426123812"><td class="cellrowborder" valign="top" width="5.8205820582058205%" headers="mcps1.1.4.1.1 "><p id="p1010912612382"><a name="p1010912612382"></a><a name="p1010912612382"></a>5</p>
</td>
<td class="cellrowborder" valign="top" width="41.7941794179418%" headers="mcps1.1.4.1.2 "><p id="p4109026173811"><a name="p4109026173811"></a><a name="p4109026173811"></a>Start color: #4b8af3; end color: #007dff</p>
</td>
<td class="cellrowborder" valign="top" width="52.38523852385239%" headers="mcps1.1.4.1.3 "><p id="p2109026173816"><a name="p2109026173816"></a><a name="p2109026173816"></a>Start color: #4c81d9; end color: #217bd9</p>
</td>
</tr>
<tr id="row1569813163818"><td class="cellrowborder" valign="top" width="5.8205820582058205%" headers="mcps1.1.4.1.1 "><p id="p196911318389"><a name="p196911318389"></a><a name="p196911318389"></a>6</p>
</td>
<td class="cellrowborder" valign="top" width="41.7941794179418%" headers="mcps1.1.4.1.2 "><p id="p186971323817"><a name="p186971323817"></a><a name="p186971323817"></a>Start color: #73c1e6; end color: #4fb4e3</p>
</td>
<td class="cellrowborder" valign="top" width="52.38523852385239%" headers="mcps1.1.4.1.3 "><p id="p169513183810"><a name="p169513183810"></a><a name="p169513183810"></a>Start color: #5ea6d1; end color: #4895c2</p>
</td>
</tr>
<tr id="row1428922313819"><td class="cellrowborder" valign="top" width="5.8205820582058205%" headers="mcps1.1.4.1.1 "><p id="p628912231384"><a name="p628912231384"></a><a name="p628912231384"></a>7</p>
</td>
<td class="cellrowborder" valign="top" width="41.7941794179418%" headers="mcps1.1.4.1.2 "><p id="p0289823193820"><a name="p0289823193820"></a><a name="p0289823193820"></a>Start color: #a5d61d; end color: #69d14f</p>
</td>
<td class="cellrowborder" valign="top" width="52.38523852385239%" headers="mcps1.1.4.1.3 "><p id="p12289192316386"><a name="p12289192316386"></a><a name="p12289192316386"></a>Start color: #91c23a; end color: #70ba5d</p>
</td>
</tr>
<tr id="row10565416153819"><td class="cellrowborder" valign="top" width="5.8205820582058205%" headers="mcps1.1.4.1.1 "><p id="p156516165388"><a name="p156516165388"></a><a name="p156516165388"></a>8</p>
</td>
<td class="cellrowborder" valign="top" width="41.7941794179418%" headers="mcps1.1.4.1.2 "><p id="p175652016143816"><a name="p175652016143816"></a><a name="p175652016143816"></a>Start color: #a2a2b0; end color: #8e8e93</p>
</td>
<td class="cellrowborder" valign="top" width="52.38523852385239%" headers="mcps1.1.4.1.3 "><p id="p5565101633813"><a name="p5565101633813"></a><a name="p5565101633813"></a>Start color: #8c8c99; end color: #6b6b76</p>
</td>
</tr>
</tbody>
</table>

For gauge charts, the following attribute is supported.

<a name="table591221715358"></a>
<table><thead align="left"><tr id="row7912417143518"><th class="cellrowborder" valign="top" width="23.52%" id="mcps1.1.6.1.1"><p id="p19912161763516"><a name="p19912161763516"></a><a name="p19912161763516"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="11.76%" id="mcps1.1.6.1.2"><p id="p11912151718350"><a name="p11912151718350"></a><a name="p11912151718350"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="11.72%" id="mcps1.1.6.1.3"><p id="p1791231713518"><a name="p1791231713518"></a><a name="p1791231713518"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="8%" id="mcps1.1.6.1.4"><p id="p7913161710357"><a name="p7913161710357"></a><a name="p7913161710357"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="45%" id="mcps1.1.6.1.5"><p id="p9913111717353"><a name="p9913111717353"></a><a name="p9913111717353"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row99131917123518"><td class="cellrowborder" valign="top" width="23.52%" headers="mcps1.1.6.1.1 "><p id="p1091312179351"><a name="p1091312179351"></a><a name="p1091312179351"></a>percent</p>
</td>
<td class="cellrowborder" valign="top" width="11.76%" headers="mcps1.1.6.1.2 "><p id="p20913111723518"><a name="p20913111723518"></a><a name="p20913111723518"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.72%" headers="mcps1.1.6.1.3 "><p id="p891361723510"><a name="p891361723510"></a><a name="p891361723510"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="8%" headers="mcps1.1.6.1.4 "><p id="p1913151711357"><a name="p1913151711357"></a><a name="p1913151711357"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="45%" headers="mcps1.1.6.1.5 "><p id="p39134178350"><a name="p39134178350"></a><a name="p39134178350"></a>Percentage of the current value to the total value. The value ranges from 0 to 100.</p>
</td>
</tr>
</tbody>
</table>

## Styles<a name="section5775351116"></a>

In addition to the styles in  [Universal Styles](js-components-common-styles.md), the following styles are supported.

<a name="table16167160154918"></a>
<table><thead align="left"><tr id="row916790104917"><th class="cellrowborder" valign="top" width="23.11768823117688%" id="mcps1.1.6.1.1"><p id="p516718013494"><a name="p516718013494"></a><a name="p516718013494"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="20.477952204779523%" id="mcps1.1.6.1.2"><p id="p131682094915"><a name="p131682094915"></a><a name="p131682094915"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="8.869113088691131%" id="mcps1.1.6.1.3"><p id="p1816816074917"><a name="p1816816074917"></a><a name="p1816816074917"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="7.519248075192481%" id="mcps1.1.6.1.4"><p id="p81681406495"><a name="p81681406495"></a><a name="p81681406495"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="40.01599840015999%" id="mcps1.1.6.1.5"><p id="p31682054916"><a name="p31682054916"></a><a name="p31682054916"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row5168305498"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p816816014492"><a name="p816816014492"></a><a name="p816816014492"></a>stroke-width</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="p5168160154919"><a name="p5168160154919"></a><a name="p5168160154919"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="p1116819014497"><a name="p1116819014497"></a><a name="p1116819014497"></a>32px (<strong id="b18760253113612"><a name="b18760253113612"></a><a name="b18760253113612"></a>gauge</strong> charts)</p>
<p id="p1616812094911"><a name="p1616812094911"></a><a name="p1616812094911"></a>24px (<strong id="b513445814226"><a name="b513445814226"></a><a name="b513445814226"></a>rainbow</strong> charts)</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p171681805495"><a name="p171681805495"></a><a name="p171681805495"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p21684012495"><a name="p21684012495"></a><a name="p21684012495"></a>Width of the scale bar for <strong id="b87491134152415"><a name="b87491134152415"></a><a name="b87491134152415"></a>gauge</strong><span id="ph616840154918"><a name="ph616840154918"></a><a name="ph616840154918"></a>and <strong id="b125075528532"><a name="b125075528532"></a><a name="b125075528532"></a>rainbow</strong></span> charts.</p>
</td>
</tr>
<tr id="row1716813094910"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p1916811017495"><a name="p1916811017495"></a><a name="p1916811017495"></a>start-angle</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="p1416812019496"><a name="p1416812019496"></a><a name="p1416812019496"></a>&lt;deg&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="p171685064917"><a name="p171685064917"></a><a name="p171685064917"></a>240 (<strong id="b261719915266"><a name="b261719915266"></a><a name="b261719915266"></a>gauge</strong> charts)</p>
<p id="p116813013494"><a name="p116813013494"></a><a name="p116813013494"></a>0 (<strong id="b87861144102514"><a name="b87861144102514"></a><a name="b87861144102514"></a>rainbow</strong> charts)</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p15169180194910"><a name="p15169180194910"></a><a name="p15169180194910"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p7169800499"><a name="p7169800499"></a><a name="p7169800499"></a>Start angle of the scale bar for <strong id="b1609185210263"><a name="b1609185210263"></a><a name="b1609185210263"></a>gauge</strong><span id="ph41696012491"><a name="ph41696012491"></a><a name="ph41696012491"></a> and <strong id="b28951759171916"><a name="b28951759171916"></a><a name="b28951759171916"></a>rainbow</strong></span> charts, which starts from the direction of zero o'clock. The value ranges from 0 to 360.</p>
</td>
</tr>
<tr id="row11698018494"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p716950134916"><a name="p716950134916"></a><a name="p716950134916"></a>total-angle</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="p161691012494"><a name="p161691012494"></a><a name="p161691012494"></a>&lt;deg&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="p16169140134920"><a name="p16169140134920"></a><a name="p16169140134920"></a>240 (<strong id="b82262662820"><a name="b82262662820"></a><a name="b82262662820"></a>gauge</strong> charts)</p>
<p id="p5169170184918"><a name="p5169170184918"></a><a name="p5169170184918"></a>360 (<strong id="b664058172810"><a name="b664058172810"></a><a name="b664058172810"></a>rainbow</strong> charts)</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p21699094912"><a name="p21699094912"></a><a name="p21699094912"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p31692011497"><a name="p31692011497"></a><a name="p31692011497"></a>Total length of the scale bar for <strong id="b4142940182820"><a name="b4142940182820"></a><a name="b4142940182820"></a>gauge</strong><span id="ph1016980124914"><a name="ph1016980124914"></a><a name="ph1016980124914"></a> and <strong id="b1867663912208"><a name="b1867663912208"></a><a name="b1867663912208"></a>rainbow</strong></span> charts. The value ranges from –360 to 360. A negative number indicates the anticlockwise direction.</p>
</td>
</tr>
<tr id="row141698034916"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p181694074916"><a name="p181694074916"></a><a name="p181694074916"></a>center-x</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="p181691305493"><a name="p181691305493"></a><a name="p181691305493"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="p1716980174916"><a name="p1716980174916"></a><a name="p1716980174916"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p81695024910"><a name="p81695024910"></a><a name="p81695024910"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p1416960174911"><a name="p1416960174911"></a><a name="p1416960174911"></a>Center of the scale bar of the gauge component. This style is supported by the gauge chart only. This style takes precedence over the <strong id="b1116220342476"><a name="b1116220342476"></a><a name="b1116220342476"></a>position</strong> style in the common styles, and must be used together with <strong id="b382682912114"><a name="b382682912114"></a><a name="b382682912114"></a>center-y</strong> and <strong id="b1482811294120"><a name="b1482811294120"></a><a name="b1482811294120"></a>radius</strong>. This style is supported by the gauge chart only.</p>
</td>
</tr>
<tr id="row3169150184914"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p7169002498"><a name="p7169002498"></a><a name="p7169002498"></a>center-y</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="p17170406499"><a name="p17170406499"></a><a name="p17170406499"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="p121705094916"><a name="p121705094916"></a><a name="p121705094916"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p191706020496"><a name="p191706020496"></a><a name="p191706020496"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p18170170194913"><a name="p18170170194913"></a><a name="p18170170194913"></a>Center of the scale bar of the gauge component. This style is supported by the gauge chart only. This style takes precedence over the <strong id="b1629744408"><a name="b1629744408"></a><a name="b1629744408"></a>position</strong> style in the common styles, and must be used together with <strong id="b02839331014"><a name="b02839331014"></a><a name="b02839331014"></a>center-x</strong> and <strong id="b1928518331711"><a name="b1928518331711"></a><a name="b1928518331711"></a>radius</strong>. This style is supported by the gauge chart only.</p>
</td>
</tr>
<tr id="row6170208490"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p1317016019498"><a name="p1317016019498"></a><a name="p1317016019498"></a>radius</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="p1717012014495"><a name="p1717012014495"></a><a name="p1717012014495"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="p1317019013497"><a name="p1317019013497"></a><a name="p1317019013497"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p1717013074913"><a name="p1717013074913"></a><a name="p1717013074913"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p7170507496"><a name="p7170507496"></a><a name="p7170507496"></a>Radius of the scale bar of the gauge component. This style is supported by the gauge chart only. This style takes precedence over the <strong id="b91381042517"><a name="b91381042517"></a><a name="b91381042517"></a>width</strong> and <strong id="b10941110165113"><a name="b10941110165113"></a><a name="b10941110165113"></a>height</strong> in the common styles, and must be used together with <strong id="b569715431526"><a name="b569715431526"></a><a name="b569715431526"></a>center-x</strong> and <strong id="b1370511431924"><a name="b1370511431924"></a><a name="b1370511431924"></a>center-y</strong>. This style is supported by the gauge chart only.</p>
</td>
</tr>
<tr id="row121701019491"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p181706004913"><a name="p181706004913"></a><a name="p181706004913"></a>colors</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="p017013014920"><a name="p017013014920"></a><a name="p017013014920"></a>Array</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="p1417012054917"><a name="p1417012054917"></a><a name="p1417012054917"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p10170130184918"><a name="p10170130184918"></a><a name="p10170130184918"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p1817012014490"><a name="p1817012014490"></a><a name="p1817012014490"></a>Color of each section for the scale bar of the gauge component.</p>
<p id="p1617017094918"><a name="p1617017094918"></a><a name="p1617017094918"></a>For example,<strong id="b1786062281317"><a name="b1786062281317"></a><a name="b1786062281317"></a> colors: #ff0000, #00ff00</strong>. This style is supported by the gauge chart only.</p>
</td>
</tr>
<tr id="row101710024913"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p141715084914"><a name="p141715084914"></a><a name="p141715084914"></a>weights</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="p20171201495"><a name="p20171201495"></a><a name="p20171201495"></a>Array</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="p1117140144911"><a name="p1117140144911"></a><a name="p1117140144911"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p71716012490"><a name="p71716012490"></a><a name="p71716012490"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p3171160114915"><a name="p3171160114915"></a><a name="p3171160114915"></a>Weight of each section for the scale bar of the gauge component.</p>
<p id="p2171140124910"><a name="p2171140124910"></a><a name="p2171140124910"></a>For example, weights: 2, 2. This style is supported by the gauge chart only.</p>
</td>
</tr>
<tr id="row6171100114916"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p117115044916"><a name="p117115044916"></a><a name="p117115044916"></a>font-family<sup id="sup111711400490"><a name="sup111711400490"></a><a name="sup111711400490"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="p917160104910"><a name="p917160104910"></a><a name="p917160104910"></a>Array</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="p117113014494"><a name="p117113014494"></a><a name="p117113014494"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p517117018496"><a name="p517117018496"></a><a name="p517117018496"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p1417110074919"><a name="p1417110074919"></a><a name="p1417110074919"></a>Font style of the description text. You can use <a href="js-components-common-customizing-font.md">Custom Font Styles</a>.</p>
</td>
</tr>
<tr id="row1117115018499"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p151710024910"><a name="p151710024910"></a><a name="p151710024910"></a>font-size<sup id="sup917220194912"><a name="sup917220194912"></a><a name="sup917220194912"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="p01728014915"><a name="p01728014915"></a><a name="p01728014915"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="p5172120114913"><a name="p5172120114913"></a><a name="p5172120114913"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p71729010499"><a name="p71729010499"></a><a name="p71729010499"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p1517210104914"><a name="p1517210104914"></a><a name="p1517210104914"></a>Font size of the description text.</p>
</td>
</tr>
</tbody>
</table>

## Events<a name="section749131815264"></a>

Events in  [Universal Events](js-components-common-events.md)  are supported.

## Methods<a name="section4480852195018"></a>

In addition to the methods in  [Universal Methods](js-components-common-methods.md), the following events are supported.

<a name="table7480052145013"></a>
<table><thead align="left"><tr id="row64801152175016"><th class="cellrowborder" valign="top" width="8.630863086308631%" id="mcps1.1.4.1.1"><p id="p184801352105010"><a name="p184801352105010"></a><a name="p184801352105010"></a>Method</p>
</th>
<th class="cellrowborder" valign="top" width="58.035803580358035%" id="mcps1.1.4.1.2"><p id="p134801052175010"><a name="p134801052175010"></a><a name="p134801052175010"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.3"><p id="p3480452115015"><a name="p3480452115015"></a><a name="p3480452115015"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1148112528509"><td class="cellrowborder" valign="top" width="8.630863086308631%" headers="mcps1.1.4.1.1 "><p id="p548115219507"><a name="p548115219507"></a><a name="p548115219507"></a>append</p>
</td>
<td class="cellrowborder" valign="top" width="58.035803580358035%" headers="mcps1.1.4.1.2 "><p id="p9481135295014"><a name="p9481135295014"></a><a name="p9481135295014"></a>{</p>
<p id="p1348165210500"><a name="p1348165210500"></a><a name="p1348165210500"></a>serial: number, // Set the data subscript of the line chart to be updated.</p>
<p id="p15481175285010"><a name="p15481175285010"></a><a name="p15481175285010"></a>data: Array&lt;number&gt;, // Set the new data.</p>
<p id="p948113523503"><a name="p948113523503"></a><a name="p948113523503"></a>}</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p7481952105010"><a name="p7481952105010"></a><a name="p7481952105010"></a>Data is dynamically added to an existing data sequence. The target sequence is specified based on <strong id="b181361720173312"><a name="b181361720173312"></a><a name="b181361720173312"></a>serial</strong>, which is the subscript of the datasets array and starts from 0. <strong id="b2513193515314"><a name="b2513193515314"></a><a name="b2513193515314"></a>datasets[index].data</strong> is not updated. Only line charts support this attribute. The value is incremented by 1 based on the horizontal coordinate and is related to the <strong id="b16836711978"><a name="b16836711978"></a><a name="b16836711978"></a>xAxis min/max</strong> setting.</p>
</td>
</tr>
</tbody>
</table>

## Example Code<a name="section164885329456"></a>

1.  Line chart

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

    ![](figures/en-us_image_0000001173324843.png)

2.  Bar chart

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

    ![](figures/en-us_image_0000001173164929.png)

3.  Gauge chart

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

    ![](figures/en-us_image_0000001127125264.png)

