# chart<a name="EN-US_TOPIC_0000001115974738"></a>

-   [Permission List](#en-us_topic_0000001059148552_section11257113618419)
-   [Child Component](#en-us_topic_0000001059148552_section9288143101012)
-   [Attribute](#en-us_topic_0000001059148552_section2907183951110)
-   [Method](#en-us_topic_0000001059148552_section5955645132417)
-   [Event](#en-us_topic_0000001059148552_section749131815264)
-   [Style](#en-us_topic_0000001059148552_section5775351116)
-   [Example Code](#en-us_topic_0000001059148552_section164885329456)

The  **<chart\>**  component displays line charts, gauge charts, and bar charts.

## Permission List<a name="en-us_topic_0000001059148552_section11257113618419"></a>

None

## Child Component<a name="en-us_topic_0000001059148552_section9288143101012"></a>

Not supported

## Attribute<a name="en-us_topic_0000001059148552_section2907183951110"></a>

<a name="en-us_topic_0000001059148552_table20633101642315"></a>
<table><thead align="left"><tr id="en-us_topic_0000001059148552_row663331618238"><th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.1"><p id="en-us_topic_0000001059148552_en-us_topic_0000001058340523_a9ba8c579217b4b8b841b035f1d28b20e"><a name="en-us_topic_0000001059148552_en-us_topic_0000001058340523_a9ba8c579217b4b8b841b035f1d28b20e"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001058340523_a9ba8c579217b4b8b841b035f1d28b20e"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.2"><p id="en-us_topic_0000001059148552_en-us_topic_0000001058340523_a633002333b024497914a4b172446f14e"><a name="en-us_topic_0000001059148552_en-us_topic_0000001058340523_a633002333b024497914a4b172446f14e"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001058340523_a633002333b024497914a4b172446f14e"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="10.48%" id="mcps1.1.6.1.3"><p id="en-us_topic_0000001059148552_en-us_topic_0000001058340523_a4950f7884c6540b9ad523ac34657d952"><a name="en-us_topic_0000001059148552_en-us_topic_0000001058340523_a4950f7884c6540b9ad523ac34657d952"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001058340523_a4950f7884c6540b9ad523ac34657d952"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.6.1.4"><p id="en-us_topic_0000001059148552_p824610360217"><a name="en-us_topic_0000001059148552_p824610360217"></a><a name="en-us_topic_0000001059148552_p824610360217"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="35.76%" id="mcps1.1.6.1.5"><p id="en-us_topic_0000001059148552_en-us_topic_0000001058340523_a1313564aa9404a338447087d5918c17d"><a name="en-us_topic_0000001059148552_en-us_topic_0000001058340523_a1313564aa9404a338447087d5918c17d"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001058340523_a1313564aa9404a338447087d5918c17d"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001059148552_row176434366222"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001059148552_p157531437142216"><a name="en-us_topic_0000001059148552_p157531437142216"></a><a name="en-us_topic_0000001059148552_p157531437142216"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001059148552_p975314374228"><a name="en-us_topic_0000001059148552_p975314374228"></a><a name="en-us_topic_0000001059148552_p975314374228"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001059148552_p2753113711229"><a name="en-us_topic_0000001059148552_p2753113711229"></a><a name="en-us_topic_0000001059148552_p2753113711229"></a>line</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001059148552_p117532375222"><a name="en-us_topic_0000001059148552_p117532375222"></a><a name="en-us_topic_0000001059148552_p117532375222"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001059148552_p12753143712225"><a name="en-us_topic_0000001059148552_p12753143712225"></a><a name="en-us_topic_0000001059148552_p12753143712225"></a>Chart type. Dynamic modification is not supported. Available values include:</p>
<a name="en-us_topic_0000001059148552_ul2754143714229"></a><a name="en-us_topic_0000001059148552_ul2754143714229"></a><ul id="en-us_topic_0000001059148552_ul2754143714229"><li><strong id="en-us_topic_0000001059148552_b380817522531"><a name="en-us_topic_0000001059148552_b380817522531"></a><a name="en-us_topic_0000001059148552_b380817522531"></a>bar</strong>: bar chart</li><li><strong id="en-us_topic_0000001059148552_b47791053195316"><a name="en-us_topic_0000001059148552_b47791053195316"></a><a name="en-us_topic_0000001059148552_b47791053195316"></a>line</strong>: line chart</li><li><strong id="en-us_topic_0000001059148552_b10329326115314"><a name="en-us_topic_0000001059148552_b10329326115314"></a><a name="en-us_topic_0000001059148552_b10329326115314"></a>gauge</strong>: gauge chart</li><li><strong id="en-us_topic_0000001059148552_b118466531142"><a name="en-us_topic_0000001059148552_b118466531142"></a><a name="en-us_topic_0000001059148552_b118466531142"></a>progress</strong><sup id="en-us_topic_0000001059148552_sup116561549162915"><a name="en-us_topic_0000001059148552_sup116561549162915"></a><a name="en-us_topic_0000001059148552_sup116561549162915"></a>5+</sup>: circle chart of progresses</li><li><strong id="en-us_topic_0000001059148552_b91066210159"><a name="en-us_topic_0000001059148552_b91066210159"></a><a name="en-us_topic_0000001059148552_b91066210159"></a>loading</strong><sup id="en-us_topic_0000001059148552_sup1246145116541"><a name="en-us_topic_0000001059148552_sup1246145116541"></a><a name="en-us_topic_0000001059148552_sup1246145116541"></a>5+</sup>: circle chart of loading processes</li><li><strong id="en-us_topic_0000001059148552_b187912701513"><a name="en-us_topic_0000001059148552_b187912701513"></a><a name="en-us_topic_0000001059148552_b187912701513"></a>rainbow</strong><sup id="en-us_topic_0000001059148552_sup13727185218542"><a name="en-us_topic_0000001059148552_sup13727185218542"></a><a name="en-us_topic_0000001059148552_sup13727185218542"></a>5+</sup>: circle chart of proportions</li></ul>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row38691133172215"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001059148552_p4754173712219"><a name="en-us_topic_0000001059148552_p4754173712219"></a><a name="en-us_topic_0000001059148552_p4754173712219"></a>options</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001059148552_p1675423715225"><a name="en-us_topic_0000001059148552_p1675423715225"></a><a name="en-us_topic_0000001059148552_p1675423715225"></a><a href="#en-us_topic_0000001059148552_table12775365017">ChartOptions</a></p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001059148552_p27541437112214"><a name="en-us_topic_0000001059148552_p27541437112214"></a><a name="en-us_topic_0000001059148552_p27541437112214"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001059148552_p1475493712214"><a name="en-us_topic_0000001059148552_p1475493712214"></a><a name="en-us_topic_0000001059148552_p1475493712214"></a>No </p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001059148552_p19754143732218"><a name="en-us_topic_0000001059148552_p19754143732218"></a><a name="en-us_topic_0000001059148552_p19754143732218"></a>Chart parameters. You must set parameters for bar charts and line charts. Parameter settings for gauge charts do not take effect. You can set the minimum value, maximum value, scale, and line width of the x-axis or y-axis, whether to display the x-axis and y-axis, and whether the line is smooth. Dynamic modification is not supported.</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row1541629182218"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001059148552_p57547371229"><a name="en-us_topic_0000001059148552_p57547371229"></a><a name="en-us_topic_0000001059148552_p57547371229"></a>datasets</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001059148552_p117541437172215"><a name="en-us_topic_0000001059148552_p117541437172215"></a><a name="en-us_topic_0000001059148552_p117541437172215"></a>Array&lt;<a href="#en-us_topic_0000001059148552_table13810518157">ChartDataset</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001059148552_p7754203711221"><a name="en-us_topic_0000001059148552_p7754203711221"></a><a name="en-us_topic_0000001059148552_p7754203711221"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001059148552_p18754183732216"><a name="en-us_topic_0000001059148552_p18754183732216"></a><a name="en-us_topic_0000001059148552_p18754183732216"></a>No </p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001059148552_p775483772214"><a name="en-us_topic_0000001059148552_p775483772214"></a><a name="en-us_topic_0000001059148552_p775483772214"></a>Data set. You must set data sets for bar charts and line charts. Data set for a gauge chart does not take effect. You can set multiple datasets and their background colors.</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row28045213017"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001059148552_p18811552104"><a name="en-us_topic_0000001059148552_p18811552104"></a><a name="en-us_topic_0000001059148552_p18811552104"></a>segments<sup id="en-us_topic_0000001059148552_sup567222913217"><a name="en-us_topic_0000001059148552_sup567222913217"></a><a name="en-us_topic_0000001059148552_sup567222913217"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001059148552_p481105219011"><a name="en-us_topic_0000001059148552_p481105219011"></a><a name="en-us_topic_0000001059148552_p481105219011"></a><a href="#en-us_topic_0000001059148552_table2596183616210">DataSegment</a> | Array&lt;<a href="#en-us_topic_0000001059148552_table2596183616210">DataSegment</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001059148552_p188135220013"><a name="en-us_topic_0000001059148552_p188135220013"></a><a name="en-us_topic_0000001059148552_p188135220013"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001059148552_p78112529019"><a name="en-us_topic_0000001059148552_p78112529019"></a><a name="en-us_topic_0000001059148552_p78112529019"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001059148552_p1455632813277"><a name="en-us_topic_0000001059148552_p1455632813277"></a><a name="en-us_topic_0000001059148552_p1455632813277"></a>Data structures used by <strong id="en-us_topic_0000001059148552_b1997913981710"><a name="en-us_topic_0000001059148552_b1997913981710"></a><a name="en-us_topic_0000001059148552_b1997913981710"></a>progress</strong>, <strong id="en-us_topic_0000001059148552_b991191118176"><a name="en-us_topic_0000001059148552_b991191118176"></a><a name="en-us_topic_0000001059148552_b991191118176"></a>loading</strong>, and <strong id="en-us_topic_0000001059148552_b962820295179"><a name="en-us_topic_0000001059148552_b962820295179"></a><a name="en-us_topic_0000001059148552_b962820295179"></a>rainbow</strong> charts.</p>
<p id="en-us_topic_0000001059148552_p19327195813510"><a name="en-us_topic_0000001059148552_p19327195813510"></a><a name="en-us_topic_0000001059148552_p19327195813510"></a><strong id="en-us_topic_0000001059148552_b196601530164710"><a name="en-us_topic_0000001059148552_b196601530164710"></a><a name="en-us_topic_0000001059148552_b196601530164710"></a>DataSegment</strong> is available for <strong id="en-us_topic_0000001059148552_b1066083012472"><a name="en-us_topic_0000001059148552_b1066083012472"></a><a name="en-us_topic_0000001059148552_b1066083012472"></a>progress</strong> and <strong id="en-us_topic_0000001059148552_b16660143054719"><a name="en-us_topic_0000001059148552_b16660143054719"></a><a name="en-us_topic_0000001059148552_b16660143054719"></a>loading</strong> charts.</p>
<p id="en-us_topic_0000001059148552_p14326258457"><a name="en-us_topic_0000001059148552_p14326258457"></a><a name="en-us_topic_0000001059148552_p14326258457"></a><strong id="en-us_topic_0000001059148552_b1044023344716"><a name="en-us_topic_0000001059148552_b1044023344716"></a><a name="en-us_topic_0000001059148552_b1044023344716"></a>Array&lt;<a href="#en-us_topic_0000001059148552_table2596183616210">DataSegment</a>&gt;</strong> is available for <strong id="en-us_topic_0000001059148552_b194405335477"><a name="en-us_topic_0000001059148552_b194405335477"></a><a name="en-us_topic_0000001059148552_b194405335477"></a>rainbow</strong> charts. A maximum of nine <strong id="en-us_topic_0000001059148552_b15441133114716"><a name="en-us_topic_0000001059148552_b15441133114716"></a><a name="en-us_topic_0000001059148552_b15441133114716"></a>DataSegment</strong> are supported in the array.</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row132072752211"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001059148552_p1720712712227"><a name="en-us_topic_0000001059148552_p1720712712227"></a><a name="en-us_topic_0000001059148552_p1720712712227"></a>effects<sup id="en-us_topic_0000001059148552_sup98541850278"><a name="en-us_topic_0000001059148552_sup98541850278"></a><a name="en-us_topic_0000001059148552_sup98541850278"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001059148552_p520815752212"><a name="en-us_topic_0000001059148552_p520815752212"></a><a name="en-us_topic_0000001059148552_p520815752212"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001059148552_p220877132211"><a name="en-us_topic_0000001059148552_p220877132211"></a><a name="en-us_topic_0000001059148552_p220877132211"></a>true</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001059148552_p1820820719229"><a name="en-us_topic_0000001059148552_p1820820719229"></a><a name="en-us_topic_0000001059148552_p1820820719229"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001059148552_p92085712225"><a name="en-us_topic_0000001059148552_p92085712225"></a><a name="en-us_topic_0000001059148552_p92085712225"></a>Whether to enable the effects for <strong id="en-us_topic_0000001059148552_b7262163754711"><a name="en-us_topic_0000001059148552_b7262163754711"></a><a name="en-us_topic_0000001059148552_b7262163754711"></a>progress</strong> and <strong id="en-us_topic_0000001059148552_b12263437134715"><a name="en-us_topic_0000001059148552_b12263437134715"></a><a name="en-us_topic_0000001059148552_b12263437134715"></a>rainbow</strong> charts.</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row36332165231"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001058340523_adb8a73146d764f2aab50fc046169ab26"><a name="en-us_topic_0000001059148552_en-us_topic_0000001058340523_adb8a73146d764f2aab50fc046169ab26"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001058340523_adb8a73146d764f2aab50fc046169ab26"></a>id</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001058340523_a06898db2627246f78e85d4fbadeee85c"><a name="en-us_topic_0000001059148552_en-us_topic_0000001058340523_a06898db2627246f78e85d4fbadeee85c"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001058340523_a06898db2627246f78e85d4fbadeee85c"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001058340523_ae685ead324a647bcba1bbb45c9402dd6"><a name="en-us_topic_0000001059148552_en-us_topic_0000001058340523_ae685ead324a647bcba1bbb45c9402dd6"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001058340523_ae685ead324a647bcba1bbb45c9402dd6"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001059148552_p42461736102118"><a name="en-us_topic_0000001059148552_p42461736102118"></a><a name="en-us_topic_0000001059148552_p42461736102118"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001058340523_a692121725a9b4ebbae65cd22b94b672e"><a name="en-us_topic_0000001059148552_en-us_topic_0000001058340523_a692121725a9b4ebbae65cd22b94b672e"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001058340523_a692121725a9b4ebbae65cd22b94b672e"></a>Unique ID of a component.</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row13633131616239"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001058340523_a7c032d302e1d437eac59680e066308b0"><a name="en-us_topic_0000001059148552_en-us_topic_0000001058340523_a7c032d302e1d437eac59680e066308b0"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001058340523_a7c032d302e1d437eac59680e066308b0"></a>style</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001058340523_a6ba72f5c52df4fba9b02b5dffa26677e"><a name="en-us_topic_0000001059148552_en-us_topic_0000001058340523_a6ba72f5c52df4fba9b02b5dffa26677e"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001058340523_a6ba72f5c52df4fba9b02b5dffa26677e"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001058340523_a23cec1f95fd04ff1b3b20f58844ea654"><a name="en-us_topic_0000001059148552_en-us_topic_0000001058340523_a23cec1f95fd04ff1b3b20f58844ea654"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001058340523_a23cec1f95fd04ff1b3b20f58844ea654"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001059148552_p17246836142119"><a name="en-us_topic_0000001059148552_p17246836142119"></a><a name="en-us_topic_0000001059148552_p17246836142119"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001058340523_ab9c92d331da44a0e9114f6760340680a"><a name="en-us_topic_0000001059148552_en-us_topic_0000001058340523_ab9c92d331da44a0e9114f6760340680a"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001058340523_ab9c92d331da44a0e9114f6760340680a"></a>Style declaration of a component.</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row10634131610230"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001058340523_a3e97d6d2a5b84e06bf619049840a00a8"><a name="en-us_topic_0000001059148552_en-us_topic_0000001058340523_a3e97d6d2a5b84e06bf619049840a00a8"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001058340523_a3e97d6d2a5b84e06bf619049840a00a8"></a>class</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001058340523_af0974175e9434735b035a4db9146aa04"><a name="en-us_topic_0000001059148552_en-us_topic_0000001058340523_af0974175e9434735b035a4db9146aa04"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001058340523_af0974175e9434735b035a4db9146aa04"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001058340523_aa5caace6225b440eba13dc2230f3ef0f"><a name="en-us_topic_0000001059148552_en-us_topic_0000001058340523_aa5caace6225b440eba13dc2230f3ef0f"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001058340523_aa5caace6225b440eba13dc2230f3ef0f"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001059148552_p324614367213"><a name="en-us_topic_0000001059148552_p324614367213"></a><a name="en-us_topic_0000001059148552_p324614367213"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001058340523_a2f6321cf45ae481983a88dcc2f900900"><a name="en-us_topic_0000001059148552_en-us_topic_0000001058340523_a2f6321cf45ae481983a88dcc2f900900"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001058340523_a2f6321cf45ae481983a88dcc2f900900"></a>Style class of a component, which is used to refer to a style table.</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row1634171618236"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001058340523_p1786251117156"><a name="en-us_topic_0000001059148552_en-us_topic_0000001058340523_p1786251117156"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001058340523_p1786251117156"></a>ref</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001058340523_p1086241119157"><a name="en-us_topic_0000001059148552_en-us_topic_0000001058340523_p1086241119157"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001058340523_p1086241119157"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001058340523_p586281111151"><a name="en-us_topic_0000001059148552_en-us_topic_0000001058340523_p586281111151"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001058340523_p586281111151"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001059148552_p1624612362219"><a name="en-us_topic_0000001059148552_p1624612362219"></a><a name="en-us_topic_0000001059148552_p1624612362219"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001058340523_p113416153342"><a name="en-us_topic_0000001059148552_en-us_topic_0000001058340523_p113416153342"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001058340523_p113416153342"></a>Used to register reference information of child elements<span id="en-us_topic_0000001059148552_en-us_topic_0000001058340523_ph5815920163518"><a name="en-us_topic_0000001059148552_en-us_topic_0000001058340523_ph5815920163518"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001058340523_ph5815920163518"></a> or child components</span>. The reference information is registered with the parent component on <strong id="en-us_topic_0000001059148552_en-us_topic_0000001058340523_b08212202354"><a name="en-us_topic_0000001059148552_en-us_topic_0000001058340523_b08212202354"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001058340523_b08212202354"></a>$refs</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row1863421642313"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001058340523_ab8d3c8007e0a42b9962e0db009e7be9d"><a name="en-us_topic_0000001059148552_en-us_topic_0000001058340523_ab8d3c8007e0a42b9962e0db009e7be9d"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001058340523_ab8d3c8007e0a42b9962e0db009e7be9d"></a>disabled</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001058340523_a05782d6a1a5d42918bc95813dca610d6"><a name="en-us_topic_0000001059148552_en-us_topic_0000001058340523_a05782d6a1a5d42918bc95813dca610d6"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001058340523_a05782d6a1a5d42918bc95813dca610d6"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001058340523_a3e2f721f63a74e4b974e9bd5e2f88994"><a name="en-us_topic_0000001059148552_en-us_topic_0000001058340523_a3e2f721f63a74e4b974e9bd5e2f88994"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001058340523_a3e2f721f63a74e4b974e9bd5e2f88994"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001059148552_p192476368214"><a name="en-us_topic_0000001059148552_p192476368214"></a><a name="en-us_topic_0000001059148552_p192476368214"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001058340523_a4065980a1e914cf98acce5250ee4ae5a"><a name="en-us_topic_0000001059148552_en-us_topic_0000001058340523_a4065980a1e914cf98acce5250ee4ae5a"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001058340523_a4065980a1e914cf98acce5250ee4ae5a"></a>Whether a component is disabled. If it is disabled, it cannot respond to user interaction.</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row1263451617236"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001058340523_a751c9d46a62348ec902c7fdf97468b9d"><a name="en-us_topic_0000001059148552_en-us_topic_0000001058340523_a751c9d46a62348ec902c7fdf97468b9d"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001058340523_a751c9d46a62348ec902c7fdf97468b9d"></a>data</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001058340523_a8e6d1bb4d0bc423fb8466ee3acd1882f"><a name="en-us_topic_0000001059148552_en-us_topic_0000001058340523_a8e6d1bb4d0bc423fb8466ee3acd1882f"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001058340523_a8e6d1bb4d0bc423fb8466ee3acd1882f"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001058340523_ab8cb15c9c3444b13b64945788131dce6"><a name="en-us_topic_0000001059148552_en-us_topic_0000001058340523_ab8cb15c9c3444b13b64945788131dce6"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001058340523_ab8cb15c9c3444b13b64945788131dce6"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001059148552_p22471736132114"><a name="en-us_topic_0000001059148552_p22471736132114"></a><a name="en-us_topic_0000001059148552_p22471736132114"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001058340523_aa3f56a32296b4e85bcda2d2c00d0884f"><a name="en-us_topic_0000001059148552_en-us_topic_0000001058340523_aa3f56a32296b4e85bcda2d2c00d0884f"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001058340523_aa3f56a32296b4e85bcda2d2c00d0884f"></a>Attribute set for a component to facilitate data storage and reading.</p>
</td>
</tr>
</tbody>
</table>

**Table  1**  ChartOptions

<a name="en-us_topic_0000001059148552_table12775365017"></a>
<table><thead align="left"><tr id="en-us_topic_0000001059148552_row6277153195013"><th class="cellrowborder" valign="top" width="16%" id="mcps1.2.6.1.1"><p id="en-us_topic_0000001059148552_p1192913820507"><a name="en-us_topic_0000001059148552_p1192913820507"></a><a name="en-us_topic_0000001059148552_p1192913820507"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="17%" id="mcps1.2.6.1.2"><p id="en-us_topic_0000001059148552_p2929188125011"><a name="en-us_topic_0000001059148552_p2929188125011"></a><a name="en-us_topic_0000001059148552_p2929188125011"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="13%" id="mcps1.2.6.1.3"><p id="en-us_topic_0000001059148552_p6929688508"><a name="en-us_topic_0000001059148552_p6929688508"></a><a name="en-us_topic_0000001059148552_p6929688508"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="16%" id="mcps1.2.6.1.4"><p id="en-us_topic_0000001059148552_p1392938165014"><a name="en-us_topic_0000001059148552_p1392938165014"></a><a name="en-us_topic_0000001059148552_p1392938165014"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="38%" id="mcps1.2.6.1.5"><p id="en-us_topic_0000001059148552_p2092914815016"><a name="en-us_topic_0000001059148552_p2092914815016"></a><a name="en-us_topic_0000001059148552_p2092914815016"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001059148552_row2277638503"><td class="cellrowborder" valign="top" width="16%" headers="mcps1.2.6.1.1 "><p id="en-us_topic_0000001059148552_p127818375011"><a name="en-us_topic_0000001059148552_p127818375011"></a><a name="en-us_topic_0000001059148552_p127818375011"></a>xAxis</p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.2.6.1.2 "><p id="en-us_topic_0000001059148552_p18278183115020"><a name="en-us_topic_0000001059148552_p18278183115020"></a><a name="en-us_topic_0000001059148552_p18278183115020"></a><a href="#en-us_topic_0000001059148552_table11312112919528">ChartAxis</a></p>
</td>
<td class="cellrowborder" valign="top" width="13%" headers="mcps1.2.6.1.3 "><p id="en-us_topic_0000001059148552_p1327817316507"><a name="en-us_topic_0000001059148552_p1327817316507"></a><a name="en-us_topic_0000001059148552_p1327817316507"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.2.6.1.4 "><p id="en-us_topic_0000001059148552_p427813385011"><a name="en-us_topic_0000001059148552_p427813385011"></a><a name="en-us_topic_0000001059148552_p427813385011"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="38%" headers="mcps1.2.6.1.5 "><p id="en-us_topic_0000001059148552_p1795144819490"><a name="en-us_topic_0000001059148552_p1795144819490"></a><a name="en-us_topic_0000001059148552_p1795144819490"></a>X-axis parameters. You can set the minimum value, maximum value, and scale of the x-axis, and whether to display the x-axis.</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row14660105412507"><td class="cellrowborder" valign="top" width="16%" headers="mcps1.2.6.1.1 "><p id="en-us_topic_0000001059148552_p16611654205018"><a name="en-us_topic_0000001059148552_p16611654205018"></a><a name="en-us_topic_0000001059148552_p16611654205018"></a>yAxis</p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.2.6.1.2 "><p id="en-us_topic_0000001059148552_p1518631821017"><a name="en-us_topic_0000001059148552_p1518631821017"></a><a name="en-us_topic_0000001059148552_p1518631821017"></a><a href="#en-us_topic_0000001059148552_table11312112919528">ChartAxis</a></p>
</td>
<td class="cellrowborder" valign="top" width="13%" headers="mcps1.2.6.1.3 "><p id="en-us_topic_0000001059148552_p19661554145015"><a name="en-us_topic_0000001059148552_p19661554145015"></a><a name="en-us_topic_0000001059148552_p19661554145015"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.2.6.1.4 "><p id="en-us_topic_0000001059148552_p466145416502"><a name="en-us_topic_0000001059148552_p466145416502"></a><a name="en-us_topic_0000001059148552_p466145416502"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="38%" headers="mcps1.2.6.1.5 "><p id="en-us_topic_0000001059148552_p14661554125010"><a name="en-us_topic_0000001059148552_p14661554125010"></a><a name="en-us_topic_0000001059148552_p14661554125010"></a>Y-axis parameters. You can set the minimum value, maximum value, and scale of the y-axis, and whether to display the y-axis.</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row1816015565013"><td class="cellrowborder" valign="top" width="16%" headers="mcps1.2.6.1.1 "><p id="en-us_topic_0000001059148552_p1816005585019"><a name="en-us_topic_0000001059148552_p1816005585019"></a><a name="en-us_topic_0000001059148552_p1816005585019"></a>series</p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.2.6.1.2 "><p id="en-us_topic_0000001059148552_p91601455135019"><a name="en-us_topic_0000001059148552_p91601455135019"></a><a name="en-us_topic_0000001059148552_p91601455135019"></a><a href="#en-us_topic_0000001059148552_table029562010560">ChartSeries</a></p>
</td>
<td class="cellrowborder" valign="top" width="13%" headers="mcps1.2.6.1.3 "><p id="en-us_topic_0000001059148552_p416015565016"><a name="en-us_topic_0000001059148552_p416015565016"></a><a name="en-us_topic_0000001059148552_p416015565016"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.2.6.1.4 "><p id="en-us_topic_0000001059148552_p12160135565014"><a name="en-us_topic_0000001059148552_p12160135565014"></a><a name="en-us_topic_0000001059148552_p12160135565014"></a>No </p>
</td>
<td class="cellrowborder" valign="top" width="38%" headers="mcps1.2.6.1.5 "><p id="en-us_topic_0000001059148552_p236434673016"><a name="en-us_topic_0000001059148552_p236434673016"></a><a name="en-us_topic_0000001059148552_p236434673016"></a>Data sequence parameters.</p>
<a name="en-us_topic_0000001059148552_ul4402155710308"></a><a name="en-us_topic_0000001059148552_ul4402155710308"></a><ul id="en-us_topic_0000001059148552_ul4402155710308"><li>Line style, such as the line width and whether the line is smooth.</li><li>Style and size of the white point at the start of the line.</li></ul>
<div class="note" id="en-us_topic_0000001059148552_note163611718126"><a name="en-us_topic_0000001059148552_note163611718126"></a><a name="en-us_topic_0000001059148552_note163611718126"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000001059148552_p15361117191211"><a name="en-us_topic_0000001059148552_p15361117191211"></a><a name="en-us_topic_0000001059148552_p15361117191211"></a>Only line charts support this attribute.</p>
</div></div>
</td>
</tr>
</tbody>
</table>

**Table  2**  ChartDataset

<a name="en-us_topic_0000001059148552_table13810518157"></a>
<table><thead align="left"><tr id="en-us_topic_0000001059148552_row1839105121514"><th class="cellrowborder" valign="top" width="16.56%" id="mcps1.2.6.1.1"><p id="en-us_topic_0000001059148552_p106956431614"><a name="en-us_topic_0000001059148552_p106956431614"></a><a name="en-us_topic_0000001059148552_p106956431614"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="16.830000000000002%" id="mcps1.2.6.1.2"><p id="en-us_topic_0000001059148552_p0695204111617"><a name="en-us_topic_0000001059148552_p0695204111617"></a><a name="en-us_topic_0000001059148552_p0695204111617"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="12.989999999999998%" id="mcps1.2.6.1.3"><p id="en-us_topic_0000001059148552_p1069514141614"><a name="en-us_topic_0000001059148552_p1069514141614"></a><a name="en-us_topic_0000001059148552_p1069514141614"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="9.33%" id="mcps1.2.6.1.4"><p id="en-us_topic_0000001059148552_p969564191616"><a name="en-us_topic_0000001059148552_p969564191616"></a><a name="en-us_topic_0000001059148552_p969564191616"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="44.29%" id="mcps1.2.6.1.5"><p id="en-us_topic_0000001059148552_p1169616441615"><a name="en-us_topic_0000001059148552_p1169616441615"></a><a name="en-us_topic_0000001059148552_p1169616441615"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001059148552_row1383242819553"><td class="cellrowborder" valign="top" width="16.56%" headers="mcps1.2.6.1.1 "><p id="en-us_topic_0000001059148552_p13832192819557"><a name="en-us_topic_0000001059148552_p13832192819557"></a><a name="en-us_topic_0000001059148552_p13832192819557"></a>strokeColor</p>
</td>
<td class="cellrowborder" valign="top" width="16.830000000000002%" headers="mcps1.2.6.1.2 "><p id="en-us_topic_0000001059148552_p18321928145512"><a name="en-us_topic_0000001059148552_p18321928145512"></a><a name="en-us_topic_0000001059148552_p18321928145512"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="12.989999999999998%" headers="mcps1.2.6.1.3 "><p id="en-us_topic_0000001059148552_p1283202816559"><a name="en-us_topic_0000001059148552_p1283202816559"></a><a name="en-us_topic_0000001059148552_p1283202816559"></a>#ff6384</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.2.6.1.4 "><p id="en-us_topic_0000001059148552_p128322028155519"><a name="en-us_topic_0000001059148552_p128322028155519"></a><a name="en-us_topic_0000001059148552_p128322028155519"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="44.29%" headers="mcps1.2.6.1.5 "><p id="en-us_topic_0000001059148552_p383218285552"><a name="en-us_topic_0000001059148552_p383218285552"></a><a name="en-us_topic_0000001059148552_p383218285552"></a>Line color.</p>
<div class="note" id="en-us_topic_0000001059148552_note149682371351"><a name="en-us_topic_0000001059148552_note149682371351"></a><a name="en-us_topic_0000001059148552_note149682371351"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000001059148552_p189688371757"><a name="en-us_topic_0000001059148552_p189688371757"></a><a name="en-us_topic_0000001059148552_p189688371757"></a>Only line charts support this attribute.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row207559395562"><td class="cellrowborder" valign="top" width="16.56%" headers="mcps1.2.6.1.1 "><p id="en-us_topic_0000001059148552_p177551539205614"><a name="en-us_topic_0000001059148552_p177551539205614"></a><a name="en-us_topic_0000001059148552_p177551539205614"></a>fillColor</p>
</td>
<td class="cellrowborder" valign="top" width="16.830000000000002%" headers="mcps1.2.6.1.2 "><p id="en-us_topic_0000001059148552_p15755143911563"><a name="en-us_topic_0000001059148552_p15755143911563"></a><a name="en-us_topic_0000001059148552_p15755143911563"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="12.989999999999998%" headers="mcps1.2.6.1.3 "><p id="en-us_topic_0000001059148552_p9755939185618"><a name="en-us_topic_0000001059148552_p9755939185618"></a><a name="en-us_topic_0000001059148552_p9755939185618"></a>#ff6384</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.2.6.1.4 "><p id="en-us_topic_0000001059148552_p1875553995610"><a name="en-us_topic_0000001059148552_p1875553995610"></a><a name="en-us_topic_0000001059148552_p1875553995610"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="44.29%" headers="mcps1.2.6.1.5 "><p id="en-us_topic_0000001059148552_p975563915619"><a name="en-us_topic_0000001059148552_p975563915619"></a><a name="en-us_topic_0000001059148552_p975563915619"></a>Fill color. For line charts, the value indicates the gradient color to fill.</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row16221319185010"><td class="cellrowborder" valign="top" width="16.56%" headers="mcps1.2.6.1.1 "><p id="en-us_topic_0000001059148552_p1939135171519"><a name="en-us_topic_0000001059148552_p1939135171519"></a><a name="en-us_topic_0000001059148552_p1939135171519"></a>data</p>
</td>
<td class="cellrowborder" valign="top" width="16.830000000000002%" headers="mcps1.2.6.1.2 "><p id="en-us_topic_0000001059148552_p93945114156"><a name="en-us_topic_0000001059148552_p93945114156"></a><a name="en-us_topic_0000001059148552_p93945114156"></a>Array&lt;number&gt; | Array&lt;<a href="#en-us_topic_0000001059148552_table1470733752019">Point</a>&gt;<sup id="en-us_topic_0000001059148552_sup748712541259"><a name="en-us_topic_0000001059148552_sup748712541259"></a><a name="en-us_topic_0000001059148552_sup748712541259"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="12.989999999999998%" headers="mcps1.2.6.1.3 "><p id="en-us_topic_0000001059148552_p1839951201514"><a name="en-us_topic_0000001059148552_p1839951201514"></a><a name="en-us_topic_0000001059148552_p1839951201514"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.2.6.1.4 "><p id="en-us_topic_0000001059148552_p4391651201517"><a name="en-us_topic_0000001059148552_p4391651201517"></a><a name="en-us_topic_0000001059148552_p4391651201517"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="44.29%" headers="mcps1.2.6.1.5 "><p id="en-us_topic_0000001059148552_p113975114159"><a name="en-us_topic_0000001059148552_p113975114159"></a><a name="en-us_topic_0000001059148552_p113975114159"></a>Data of the drawn line or bar.</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row284113911529"><td class="cellrowborder" valign="top" width="16.56%" headers="mcps1.2.6.1.1 "><p id="en-us_topic_0000001059148552_p884110975213"><a name="en-us_topic_0000001059148552_p884110975213"></a><a name="en-us_topic_0000001059148552_p884110975213"></a>gradient</p>
</td>
<td class="cellrowborder" valign="top" width="16.830000000000002%" headers="mcps1.2.6.1.2 "><p id="en-us_topic_0000001059148552_p168411494528"><a name="en-us_topic_0000001059148552_p168411494528"></a><a name="en-us_topic_0000001059148552_p168411494528"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="12.989999999999998%" headers="mcps1.2.6.1.3 "><p id="en-us_topic_0000001059148552_p7841992522"><a name="en-us_topic_0000001059148552_p7841992522"></a><a name="en-us_topic_0000001059148552_p7841992522"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.2.6.1.4 "><p id="en-us_topic_0000001059148552_p1684159195214"><a name="en-us_topic_0000001059148552_p1684159195214"></a><a name="en-us_topic_0000001059148552_p1684159195214"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="44.29%" headers="mcps1.2.6.1.5 "><p id="en-us_topic_0000001059148552_p198414916522"><a name="en-us_topic_0000001059148552_p198414916522"></a><a name="en-us_topic_0000001059148552_p198414916522"></a>Whether to display the gradient color.</p>
<div class="note" id="en-us_topic_0000001059148552_note55873241061"><a name="en-us_topic_0000001059148552_note55873241061"></a><a name="en-us_topic_0000001059148552_note55873241061"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000001059148552_p1558712410616"><a name="en-us_topic_0000001059148552_p1558712410616"></a><a name="en-us_topic_0000001059148552_p1558712410616"></a>Only line charts support this attribute.</p>
</div></div>
</td>
</tr>
</tbody>
</table>

**Table  3**  ChartAxis

<a name="en-us_topic_0000001059148552_table11312112919528"></a>
<table><thead align="left"><tr id="en-us_topic_0000001059148552_row1031252917522"><th class="cellrowborder" valign="top" width="16.650000000000002%" id="mcps1.2.6.1.1"><p id="en-us_topic_0000001059148552_p7835550165517"><a name="en-us_topic_0000001059148552_p7835550165517"></a><a name="en-us_topic_0000001059148552_p7835550165517"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="16.3%" id="mcps1.2.6.1.2"><p id="en-us_topic_0000001059148552_p2083515012555"><a name="en-us_topic_0000001059148552_p2083515012555"></a><a name="en-us_topic_0000001059148552_p2083515012555"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="12.91%" id="mcps1.2.6.1.3"><p id="en-us_topic_0000001059148552_p1283545016551"><a name="en-us_topic_0000001059148552_p1283545016551"></a><a name="en-us_topic_0000001059148552_p1283545016551"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="9.5%" id="mcps1.2.6.1.4"><p id="en-us_topic_0000001059148552_p18351650135519"><a name="en-us_topic_0000001059148552_p18351650135519"></a><a name="en-us_topic_0000001059148552_p18351650135519"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="44.64%" id="mcps1.2.6.1.5"><p id="en-us_topic_0000001059148552_p10835105017555"><a name="en-us_topic_0000001059148552_p10835105017555"></a><a name="en-us_topic_0000001059148552_p10835105017555"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001059148552_row231352916527"><td class="cellrowborder" valign="top" width="16.650000000000002%" headers="mcps1.2.6.1.1 "><p id="en-us_topic_0000001059148552_p13313529145212"><a name="en-us_topic_0000001059148552_p13313529145212"></a><a name="en-us_topic_0000001059148552_p13313529145212"></a>min</p>
</td>
<td class="cellrowborder" valign="top" width="16.3%" headers="mcps1.2.6.1.2 "><p id="en-us_topic_0000001059148552_p14313429185211"><a name="en-us_topic_0000001059148552_p14313429185211"></a><a name="en-us_topic_0000001059148552_p14313429185211"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="12.91%" headers="mcps1.2.6.1.3 "><p id="en-us_topic_0000001059148552_p19313152995219"><a name="en-us_topic_0000001059148552_p19313152995219"></a><a name="en-us_topic_0000001059148552_p19313152995219"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="9.5%" headers="mcps1.2.6.1.4 "><p id="en-us_topic_0000001059148552_p03131429165220"><a name="en-us_topic_0000001059148552_p03131429165220"></a><a name="en-us_topic_0000001059148552_p03131429165220"></a>No </p>
</td>
<td class="cellrowborder" valign="top" width="44.64%" headers="mcps1.2.6.1.5 "><p id="en-us_topic_0000001059148552_p15313529165215"><a name="en-us_topic_0000001059148552_p15313529165215"></a><a name="en-us_topic_0000001059148552_p15313529165215"></a>Minimum value of the axis.</p>
<div class="note" id="en-us_topic_0000001059148552_note947711273197"><a name="en-us_topic_0000001059148552_note947711273197"></a><a name="en-us_topic_0000001059148552_note947711273197"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000001059148552_p5477102781911"><a name="en-us_topic_0000001059148552_p5477102781911"></a><a name="en-us_topic_0000001059148552_p5477102781911"></a>Negative numbers are not supported. Only line charts support this attribute.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row10177207165517"><td class="cellrowborder" valign="top" width="16.650000000000002%" headers="mcps1.2.6.1.1 "><p id="en-us_topic_0000001059148552_p191773713559"><a name="en-us_topic_0000001059148552_p191773713559"></a><a name="en-us_topic_0000001059148552_p191773713559"></a>max</p>
</td>
<td class="cellrowborder" valign="top" width="16.3%" headers="mcps1.2.6.1.2 "><p id="en-us_topic_0000001059148552_p11771076557"><a name="en-us_topic_0000001059148552_p11771076557"></a><a name="en-us_topic_0000001059148552_p11771076557"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="12.91%" headers="mcps1.2.6.1.3 "><p id="en-us_topic_0000001059148552_p13177127165511"><a name="en-us_topic_0000001059148552_p13177127165511"></a><a name="en-us_topic_0000001059148552_p13177127165511"></a>100</p>
</td>
<td class="cellrowborder" valign="top" width="9.5%" headers="mcps1.2.6.1.4 "><p id="en-us_topic_0000001059148552_p171774715517"><a name="en-us_topic_0000001059148552_p171774715517"></a><a name="en-us_topic_0000001059148552_p171774715517"></a>No </p>
</td>
<td class="cellrowborder" valign="top" width="44.64%" headers="mcps1.2.6.1.5 "><p id="en-us_topic_0000001059148552_p111771705519"><a name="en-us_topic_0000001059148552_p111771705519"></a><a name="en-us_topic_0000001059148552_p111771705519"></a>Maximum value of the axis.</p>
<div class="note" id="en-us_topic_0000001059148552_note1287217389195"><a name="en-us_topic_0000001059148552_note1287217389195"></a><a name="en-us_topic_0000001059148552_note1287217389195"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000001059148552_p17872153817197"><a name="en-us_topic_0000001059148552_p17872153817197"></a><a name="en-us_topic_0000001059148552_p17872153817197"></a>Negative numbers are not supported. Only line charts support this attribute.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row54401875553"><td class="cellrowborder" valign="top" width="16.650000000000002%" headers="mcps1.2.6.1.1 "><p id="en-us_topic_0000001059148552_p544037145514"><a name="en-us_topic_0000001059148552_p544037145514"></a><a name="en-us_topic_0000001059148552_p544037145514"></a>axisTick</p>
</td>
<td class="cellrowborder" valign="top" width="16.3%" headers="mcps1.2.6.1.2 "><p id="en-us_topic_0000001059148552_p844011745512"><a name="en-us_topic_0000001059148552_p844011745512"></a><a name="en-us_topic_0000001059148552_p844011745512"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="12.91%" headers="mcps1.2.6.1.3 "><p id="en-us_topic_0000001059148552_p9440277558"><a name="en-us_topic_0000001059148552_p9440277558"></a><a name="en-us_topic_0000001059148552_p9440277558"></a>10</p>
</td>
<td class="cellrowborder" valign="top" width="9.5%" headers="mcps1.2.6.1.4 "><p id="en-us_topic_0000001059148552_p194406755518"><a name="en-us_topic_0000001059148552_p194406755518"></a><a name="en-us_topic_0000001059148552_p194406755518"></a>No </p>
</td>
<td class="cellrowborder" valign="top" width="44.64%" headers="mcps1.2.6.1.5 "><p id="en-us_topic_0000001059148552_p1144027105511"><a name="en-us_topic_0000001059148552_p1144027105511"></a><a name="en-us_topic_0000001059148552_p1144027105511"></a>Number of scales displayed on the axis.</p>
<div class="note" id="en-us_topic_0000001059148552_note18942121511202"><a name="en-us_topic_0000001059148552_note18942121511202"></a><a name="en-us_topic_0000001059148552_note18942121511202"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000001059148552_p4709421681"><a name="en-us_topic_0000001059148552_p4709421681"></a><a name="en-us_topic_0000001059148552_p4709421681"></a>The value ranges from 1 to 20. The display effect depends on the calculation result of Number of pixels occupied by the image width/(<strong id="en-us_topic_0000001059148552_b17205813354"><a name="en-us_topic_0000001059148552_b17205813354"></a><a name="en-us_topic_0000001059148552_b17205813354"></a>max</strong>-<strong id="en-us_topic_0000001059148552_b182718418359"><a name="en-us_topic_0000001059148552_b182718418359"></a><a name="en-us_topic_0000001059148552_b182718418359"></a>min</strong>).</p>
<p id="en-us_topic_0000001059148552_p234142016205"><a name="en-us_topic_0000001059148552_p234142016205"></a><a name="en-us_topic_0000001059148552_p234142016205"></a>In the bar chart, the number of bars in each group of data is the same as the number of scales, and the bars are displayed at the scales.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row6558148125516"><td class="cellrowborder" valign="top" width="16.650000000000002%" headers="mcps1.2.6.1.1 "><p id="en-us_topic_0000001059148552_p1555818865515"><a name="en-us_topic_0000001059148552_p1555818865515"></a><a name="en-us_topic_0000001059148552_p1555818865515"></a>display</p>
</td>
<td class="cellrowborder" valign="top" width="16.3%" headers="mcps1.2.6.1.2 "><p id="en-us_topic_0000001059148552_p1755910815552"><a name="en-us_topic_0000001059148552_p1755910815552"></a><a name="en-us_topic_0000001059148552_p1755910815552"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="12.91%" headers="mcps1.2.6.1.3 "><p id="en-us_topic_0000001059148552_p2559108195515"><a name="en-us_topic_0000001059148552_p2559108195515"></a><a name="en-us_topic_0000001059148552_p2559108195515"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="9.5%" headers="mcps1.2.6.1.4 "><p id="en-us_topic_0000001059148552_p185597805514"><a name="en-us_topic_0000001059148552_p185597805514"></a><a name="en-us_topic_0000001059148552_p185597805514"></a>No </p>
</td>
<td class="cellrowborder" valign="top" width="44.64%" headers="mcps1.2.6.1.5 "><p id="en-us_topic_0000001059148552_p1655910815551"><a name="en-us_topic_0000001059148552_p1655910815551"></a><a name="en-us_topic_0000001059148552_p1655910815551"></a>Whether to display the axis.</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row1382114065515"><td class="cellrowborder" valign="top" width="16.650000000000002%" headers="mcps1.2.6.1.1 "><p id="en-us_topic_0000001059148552_p188221209555"><a name="en-us_topic_0000001059148552_p188221209555"></a><a name="en-us_topic_0000001059148552_p188221209555"></a>color</p>
</td>
<td class="cellrowborder" valign="top" width="16.3%" headers="mcps1.2.6.1.2 "><p id="en-us_topic_0000001059148552_p1782214025517"><a name="en-us_topic_0000001059148552_p1782214025517"></a><a name="en-us_topic_0000001059148552_p1782214025517"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="12.91%" headers="mcps1.2.6.1.3 "><p id="en-us_topic_0000001059148552_p482220185512"><a name="en-us_topic_0000001059148552_p482220185512"></a><a name="en-us_topic_0000001059148552_p482220185512"></a>#c0c0c0</p>
</td>
<td class="cellrowborder" valign="top" width="9.5%" headers="mcps1.2.6.1.4 "><p id="en-us_topic_0000001059148552_p782214015553"><a name="en-us_topic_0000001059148552_p782214015553"></a><a name="en-us_topic_0000001059148552_p782214015553"></a>No </p>
</td>
<td class="cellrowborder" valign="top" width="44.64%" headers="mcps1.2.6.1.5 "><p id="en-us_topic_0000001059148552_p4822202556"><a name="en-us_topic_0000001059148552_p4822202556"></a><a name="en-us_topic_0000001059148552_p4822202556"></a>Axis color.</p>
</td>
</tr>
</tbody>
</table>

**Table  4**  ChartSeries

<a name="en-us_topic_0000001059148552_table029562010560"></a>
<table><thead align="left"><tr id="en-us_topic_0000001059148552_row9295192095610"><th class="cellrowborder" valign="top" width="17%" id="mcps1.2.6.1.1"><p id="en-us_topic_0000001059148552_p10617123345612"><a name="en-us_topic_0000001059148552_p10617123345612"></a><a name="en-us_topic_0000001059148552_p10617123345612"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="16.39%" id="mcps1.2.6.1.2"><p id="en-us_topic_0000001059148552_p9617133175613"><a name="en-us_topic_0000001059148552_p9617133175613"></a><a name="en-us_topic_0000001059148552_p9617133175613"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="12.82%" id="mcps1.2.6.1.3"><p id="en-us_topic_0000001059148552_p3617153315562"><a name="en-us_topic_0000001059148552_p3617153315562"></a><a name="en-us_topic_0000001059148552_p3617153315562"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="10.11%" id="mcps1.2.6.1.4"><p id="en-us_topic_0000001059148552_p4617163305612"><a name="en-us_topic_0000001059148552_p4617163305612"></a><a name="en-us_topic_0000001059148552_p4617163305612"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="43.68%" id="mcps1.2.6.1.5"><p id="en-us_topic_0000001059148552_p1561718337569"><a name="en-us_topic_0000001059148552_p1561718337569"></a><a name="en-us_topic_0000001059148552_p1561718337569"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001059148552_row13295162011563"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.2.6.1.1 "><p id="en-us_topic_0000001059148552_p2296820185612"><a name="en-us_topic_0000001059148552_p2296820185612"></a><a name="en-us_topic_0000001059148552_p2296820185612"></a>lineStyle</p>
</td>
<td class="cellrowborder" valign="top" width="16.39%" headers="mcps1.2.6.1.2 "><p id="en-us_topic_0000001059148552_p529652005615"><a name="en-us_topic_0000001059148552_p529652005615"></a><a name="en-us_topic_0000001059148552_p529652005615"></a><a href="#en-us_topic_0000001059148552_table7790183513918">ChartLineStyle</a></p>
</td>
<td class="cellrowborder" valign="top" width="12.82%" headers="mcps1.2.6.1.3 "><p id="en-us_topic_0000001059148552_p629612208561"><a name="en-us_topic_0000001059148552_p629612208561"></a><a name="en-us_topic_0000001059148552_p629612208561"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="10.11%" headers="mcps1.2.6.1.4 "><p id="en-us_topic_0000001059148552_p129632065619"><a name="en-us_topic_0000001059148552_p129632065619"></a><a name="en-us_topic_0000001059148552_p129632065619"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="43.68%" headers="mcps1.2.6.1.5 "><p id="en-us_topic_0000001059148552_p929652045614"><a name="en-us_topic_0000001059148552_p929652045614"></a><a name="en-us_topic_0000001059148552_p929652045614"></a>Line style, such as the line width and whether the line is smooth.</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row1829652010566"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.2.6.1.1 "><p id="en-us_topic_0000001059148552_p17296112017565"><a name="en-us_topic_0000001059148552_p17296112017565"></a><a name="en-us_topic_0000001059148552_p17296112017565"></a>headPoint</p>
</td>
<td class="cellrowborder" valign="top" width="16.39%" headers="mcps1.2.6.1.2 "><p id="en-us_topic_0000001059148552_p1829632018566"><a name="en-us_topic_0000001059148552_p1829632018566"></a><a name="en-us_topic_0000001059148552_p1829632018566"></a><a href="#en-us_topic_0000001059148552_table1435760101317">PointStyle</a></p>
</td>
<td class="cellrowborder" valign="top" width="12.82%" headers="mcps1.2.6.1.3 "><p id="en-us_topic_0000001059148552_p52966203569"><a name="en-us_topic_0000001059148552_p52966203569"></a><a name="en-us_topic_0000001059148552_p52966203569"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="10.11%" headers="mcps1.2.6.1.4 "><p id="en-us_topic_0000001059148552_p17296020155611"><a name="en-us_topic_0000001059148552_p17296020155611"></a><a name="en-us_topic_0000001059148552_p17296020155611"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="43.68%" headers="mcps1.2.6.1.5 "><p id="en-us_topic_0000001059148552_p14296132015616"><a name="en-us_topic_0000001059148552_p14296132015616"></a><a name="en-us_topic_0000001059148552_p14296132015616"></a>Style and size of the white point at the start of the line.</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row416985481620"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.2.6.1.1 "><p id="en-us_topic_0000001059148552_p816915441619"><a name="en-us_topic_0000001059148552_p816915441619"></a><a name="en-us_topic_0000001059148552_p816915441619"></a>topPoint</p>
</td>
<td class="cellrowborder" valign="top" width="16.39%" headers="mcps1.2.6.1.2 "><p id="en-us_topic_0000001059148552_p13169145471618"><a name="en-us_topic_0000001059148552_p13169145471618"></a><a name="en-us_topic_0000001059148552_p13169145471618"></a><a href="#en-us_topic_0000001059148552_table1435760101317">PointStyle</a></p>
</td>
<td class="cellrowborder" valign="top" width="12.82%" headers="mcps1.2.6.1.3 "><p id="en-us_topic_0000001059148552_p816995416164"><a name="en-us_topic_0000001059148552_p816995416164"></a><a name="en-us_topic_0000001059148552_p816995416164"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="10.11%" headers="mcps1.2.6.1.4 "><p id="en-us_topic_0000001059148552_p2017015417166"><a name="en-us_topic_0000001059148552_p2017015417166"></a><a name="en-us_topic_0000001059148552_p2017015417166"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="43.68%" headers="mcps1.2.6.1.5 "><p id="en-us_topic_0000001059148552_p98810719197"><a name="en-us_topic_0000001059148552_p98810719197"></a><a name="en-us_topic_0000001059148552_p98810719197"></a>Style and size of the top point.</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row9719195771616"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.2.6.1.1 "><p id="en-us_topic_0000001059148552_p12719857161614"><a name="en-us_topic_0000001059148552_p12719857161614"></a><a name="en-us_topic_0000001059148552_p12719857161614"></a>bottomPoint</p>
</td>
<td class="cellrowborder" valign="top" width="16.39%" headers="mcps1.2.6.1.2 "><p id="en-us_topic_0000001059148552_p631412816137"><a name="en-us_topic_0000001059148552_p631412816137"></a><a name="en-us_topic_0000001059148552_p631412816137"></a><a href="#en-us_topic_0000001059148552_table1435760101317">PointStyle</a></p>
</td>
<td class="cellrowborder" valign="top" width="12.82%" headers="mcps1.2.6.1.3 "><p id="en-us_topic_0000001059148552_p1771995719166"><a name="en-us_topic_0000001059148552_p1771995719166"></a><a name="en-us_topic_0000001059148552_p1771995719166"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="10.11%" headers="mcps1.2.6.1.4 "><p id="en-us_topic_0000001059148552_p77192571166"><a name="en-us_topic_0000001059148552_p77192571166"></a><a name="en-us_topic_0000001059148552_p77192571166"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="43.68%" headers="mcps1.2.6.1.5 "><p id="en-us_topic_0000001059148552_p10719357111610"><a name="en-us_topic_0000001059148552_p10719357111610"></a><a name="en-us_topic_0000001059148552_p10719357111610"></a>Style and size of the bottom point.</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row1165515117356"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.2.6.1.1 "><p id="en-us_topic_0000001059148552_p1065610143518"><a name="en-us_topic_0000001059148552_p1065610143518"></a><a name="en-us_topic_0000001059148552_p1065610143518"></a>loop</p>
</td>
<td class="cellrowborder" valign="top" width="16.39%" headers="mcps1.2.6.1.2 "><p id="en-us_topic_0000001059148552_p8656121143511"><a name="en-us_topic_0000001059148552_p8656121143511"></a><a name="en-us_topic_0000001059148552_p8656121143511"></a><a href="#en-us_topic_0000001059148552_table13982347173714">ChartLoop</a></p>
</td>
<td class="cellrowborder" valign="top" width="12.82%" headers="mcps1.2.6.1.3 "><p id="en-us_topic_0000001059148552_p765611163510"><a name="en-us_topic_0000001059148552_p765611163510"></a><a name="en-us_topic_0000001059148552_p765611163510"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="10.11%" headers="mcps1.2.6.1.4 "><p id="en-us_topic_0000001059148552_p1965671123510"><a name="en-us_topic_0000001059148552_p1965671123510"></a><a name="en-us_topic_0000001059148552_p1965671123510"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="43.68%" headers="mcps1.2.6.1.5 "><p id="en-us_topic_0000001059148552_p19656131113517"><a name="en-us_topic_0000001059148552_p19656131113517"></a><a name="en-us_topic_0000001059148552_p19656131113517"></a>Whether to start drawing again when the screen is looped.</p>
</td>
</tr>
</tbody>
</table>

**Table  5**  ChartLineStyle

<a name="en-us_topic_0000001059148552_table7790183513918"></a>
<table><thead align="left"><tr id="en-us_topic_0000001059148552_row167906351914"><th class="cellrowborder" valign="top" width="17.09%" id="mcps1.2.6.1.1"><p id="en-us_topic_0000001059148552_p15238040191012"><a name="en-us_topic_0000001059148552_p15238040191012"></a><a name="en-us_topic_0000001059148552_p15238040191012"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="16.91%" id="mcps1.2.6.1.2"><p id="en-us_topic_0000001059148552_p142381440151020"><a name="en-us_topic_0000001059148552_p142381440151020"></a><a name="en-us_topic_0000001059148552_p142381440151020"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="12.690000000000001%" id="mcps1.2.6.1.3"><p id="en-us_topic_0000001059148552_p723814051011"><a name="en-us_topic_0000001059148552_p723814051011"></a><a name="en-us_topic_0000001059148552_p723814051011"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="10.24%" id="mcps1.2.6.1.4"><p id="en-us_topic_0000001059148552_p623818402108"><a name="en-us_topic_0000001059148552_p623818402108"></a><a name="en-us_topic_0000001059148552_p623818402108"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="43.07%" id="mcps1.2.6.1.5"><p id="en-us_topic_0000001059148552_p1223834091020"><a name="en-us_topic_0000001059148552_p1223834091020"></a><a name="en-us_topic_0000001059148552_p1223834091020"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001059148552_row47909350912"><td class="cellrowborder" valign="top" width="17.09%" headers="mcps1.2.6.1.1 "><p id="en-us_topic_0000001059148552_p13791135393"><a name="en-us_topic_0000001059148552_p13791135393"></a><a name="en-us_topic_0000001059148552_p13791135393"></a>width</p>
</td>
<td class="cellrowborder" valign="top" width="16.91%" headers="mcps1.2.6.1.2 "><p id="en-us_topic_0000001059148552_p5791123511915"><a name="en-us_topic_0000001059148552_p5791123511915"></a><a name="en-us_topic_0000001059148552_p5791123511915"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="12.690000000000001%" headers="mcps1.2.6.1.3 "><p id="en-us_topic_0000001059148552_p1479120352916"><a name="en-us_topic_0000001059148552_p1479120352916"></a><a name="en-us_topic_0000001059148552_p1479120352916"></a>1px</p>
</td>
<td class="cellrowborder" valign="top" width="10.24%" headers="mcps1.2.6.1.4 "><p id="en-us_topic_0000001059148552_p87911135691"><a name="en-us_topic_0000001059148552_p87911135691"></a><a name="en-us_topic_0000001059148552_p87911135691"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="43.07%" headers="mcps1.2.6.1.5 "><p id="en-us_topic_0000001059148552_p47917356918"><a name="en-us_topic_0000001059148552_p47917356918"></a><a name="en-us_topic_0000001059148552_p47917356918"></a>Line width.</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row1279183510911"><td class="cellrowborder" valign="top" width="17.09%" headers="mcps1.2.6.1.1 "><p id="en-us_topic_0000001059148552_p107913351297"><a name="en-us_topic_0000001059148552_p107913351297"></a><a name="en-us_topic_0000001059148552_p107913351297"></a>smooth</p>
</td>
<td class="cellrowborder" valign="top" width="16.91%" headers="mcps1.2.6.1.2 "><p id="en-us_topic_0000001059148552_p1479113515915"><a name="en-us_topic_0000001059148552_p1479113515915"></a><a name="en-us_topic_0000001059148552_p1479113515915"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="12.690000000000001%" headers="mcps1.2.6.1.3 "><p id="en-us_topic_0000001059148552_p179111356910"><a name="en-us_topic_0000001059148552_p179111356910"></a><a name="en-us_topic_0000001059148552_p179111356910"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="10.24%" headers="mcps1.2.6.1.4 "><p id="en-us_topic_0000001059148552_p979117355914"><a name="en-us_topic_0000001059148552_p979117355914"></a><a name="en-us_topic_0000001059148552_p979117355914"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="43.07%" headers="mcps1.2.6.1.5 "><p id="en-us_topic_0000001059148552_p1879113353920"><a name="en-us_topic_0000001059148552_p1879113353920"></a><a name="en-us_topic_0000001059148552_p1879113353920"></a>Whether the line is smooth.</p>
</td>
</tr>
</tbody>
</table>

**Table  6**  PointStyle

<a name="en-us_topic_0000001059148552_table1435760101317"></a>
<table><thead align="left"><tr id="en-us_topic_0000001059148552_row0357180181315"><th class="cellrowborder" valign="top" width="17.09%" id="mcps1.2.6.1.1"><p id="en-us_topic_0000001059148552_p763402181310"><a name="en-us_topic_0000001059148552_p763402181310"></a><a name="en-us_topic_0000001059148552_p763402181310"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="17.09%" id="mcps1.2.6.1.2"><p id="en-us_topic_0000001059148552_p963402171313"><a name="en-us_topic_0000001059148552_p963402171313"></a><a name="en-us_topic_0000001059148552_p963402171313"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="12.64%" id="mcps1.2.6.1.3"><p id="en-us_topic_0000001059148552_p166343212133"><a name="en-us_topic_0000001059148552_p166343212133"></a><a name="en-us_topic_0000001059148552_p166343212133"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="10.549999999999999%" id="mcps1.2.6.1.4"><p id="en-us_topic_0000001059148552_p4634621111311"><a name="en-us_topic_0000001059148552_p4634621111311"></a><a name="en-us_topic_0000001059148552_p4634621111311"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="42.63%" id="mcps1.2.6.1.5"><p id="en-us_topic_0000001059148552_p2063413215132"><a name="en-us_topic_0000001059148552_p2063413215132"></a><a name="en-us_topic_0000001059148552_p2063413215132"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001059148552_row53581105131"><td class="cellrowborder" valign="top" width="17.09%" headers="mcps1.2.6.1.1 "><p id="en-us_topic_0000001059148552_p12358803137"><a name="en-us_topic_0000001059148552_p12358803137"></a><a name="en-us_topic_0000001059148552_p12358803137"></a>shape</p>
</td>
<td class="cellrowborder" valign="top" width="17.09%" headers="mcps1.2.6.1.2 "><p id="en-us_topic_0000001059148552_p19358190201313"><a name="en-us_topic_0000001059148552_p19358190201313"></a><a name="en-us_topic_0000001059148552_p19358190201313"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="12.64%" headers="mcps1.2.6.1.3 "><p id="en-us_topic_0000001059148552_p1358170141315"><a name="en-us_topic_0000001059148552_p1358170141315"></a><a name="en-us_topic_0000001059148552_p1358170141315"></a>circle</p>
</td>
<td class="cellrowborder" valign="top" width="10.549999999999999%" headers="mcps1.2.6.1.4 "><p id="en-us_topic_0000001059148552_p0358203135"><a name="en-us_topic_0000001059148552_p0358203135"></a><a name="en-us_topic_0000001059148552_p0358203135"></a>No </p>
</td>
<td class="cellrowborder" valign="top" width="42.63%" headers="mcps1.2.6.1.5 "><p id="en-us_topic_0000001059148552_p113581206134"><a name="en-us_topic_0000001059148552_p113581206134"></a><a name="en-us_topic_0000001059148552_p113581206134"></a>Shape of the highlight point. Available values are as follows:</p>
<a name="en-us_topic_0000001059148552_ul107389175319"></a><a name="en-us_topic_0000001059148552_ul107389175319"></a><ul id="en-us_topic_0000001059148552_ul107389175319"><li>Circle</li><li>Square</li><li>Triangle</li></ul>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row143581011317"><td class="cellrowborder" valign="top" width="17.09%" headers="mcps1.2.6.1.1 "><p id="en-us_topic_0000001059148552_p19358200201311"><a name="en-us_topic_0000001059148552_p19358200201311"></a><a name="en-us_topic_0000001059148552_p19358200201311"></a>size</p>
</td>
<td class="cellrowborder" valign="top" width="17.09%" headers="mcps1.2.6.1.2 "><p id="en-us_topic_0000001059148552_p93585011135"><a name="en-us_topic_0000001059148552_p93585011135"></a><a name="en-us_topic_0000001059148552_p93585011135"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="12.64%" headers="mcps1.2.6.1.3 "><p id="en-us_topic_0000001059148552_p203581081313"><a name="en-us_topic_0000001059148552_p203581081313"></a><a name="en-us_topic_0000001059148552_p203581081313"></a>5px</p>
</td>
<td class="cellrowborder" valign="top" width="10.549999999999999%" headers="mcps1.2.6.1.4 "><p id="en-us_topic_0000001059148552_p183582008137"><a name="en-us_topic_0000001059148552_p183582008137"></a><a name="en-us_topic_0000001059148552_p183582008137"></a>No </p>
</td>
<td class="cellrowborder" valign="top" width="42.63%" headers="mcps1.2.6.1.5 "><p id="en-us_topic_0000001059148552_p2358502135"><a name="en-us_topic_0000001059148552_p2358502135"></a><a name="en-us_topic_0000001059148552_p2358502135"></a>Size of the highlight point.</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row957985594815"><td class="cellrowborder" valign="top" width="17.09%" headers="mcps1.2.6.1.1 "><p id="en-us_topic_0000001059148552_p11579165564814"><a name="en-us_topic_0000001059148552_p11579165564814"></a><a name="en-us_topic_0000001059148552_p11579165564814"></a>strokeWidth</p>
</td>
<td class="cellrowborder" valign="top" width="17.09%" headers="mcps1.2.6.1.2 "><p id="en-us_topic_0000001059148552_p657916559486"><a name="en-us_topic_0000001059148552_p657916559486"></a><a name="en-us_topic_0000001059148552_p657916559486"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="12.64%" headers="mcps1.2.6.1.3 "><p id="en-us_topic_0000001059148552_p12579105514489"><a name="en-us_topic_0000001059148552_p12579105514489"></a><a name="en-us_topic_0000001059148552_p12579105514489"></a>1px</p>
</td>
<td class="cellrowborder" valign="top" width="10.549999999999999%" headers="mcps1.2.6.1.4 "><p id="en-us_topic_0000001059148552_p958015514480"><a name="en-us_topic_0000001059148552_p958015514480"></a><a name="en-us_topic_0000001059148552_p958015514480"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="42.63%" headers="mcps1.2.6.1.5 "><p id="en-us_topic_0000001059148552_p3580115534814"><a name="en-us_topic_0000001059148552_p3580115534814"></a><a name="en-us_topic_0000001059148552_p3580115534814"></a>Stroke width.</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row51421313317"><td class="cellrowborder" valign="top" width="17.09%" headers="mcps1.2.6.1.1 "><p id="en-us_topic_0000001059148552_p151432333315"><a name="en-us_topic_0000001059148552_p151432333315"></a><a name="en-us_topic_0000001059148552_p151432333315"></a>strokeColor</p>
</td>
<td class="cellrowborder" valign="top" width="17.09%" headers="mcps1.2.6.1.2 "><p id="en-us_topic_0000001059148552_p1914312363315"><a name="en-us_topic_0000001059148552_p1914312363315"></a><a name="en-us_topic_0000001059148552_p1914312363315"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="12.64%" headers="mcps1.2.6.1.3 "><p id="en-us_topic_0000001059148552_p114319316335"><a name="en-us_topic_0000001059148552_p114319316335"></a><a name="en-us_topic_0000001059148552_p114319316335"></a>#ff0000</p>
</td>
<td class="cellrowborder" valign="top" width="10.549999999999999%" headers="mcps1.2.6.1.4 "><p id="en-us_topic_0000001059148552_p11431036331"><a name="en-us_topic_0000001059148552_p11431036331"></a><a name="en-us_topic_0000001059148552_p11431036331"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="42.63%" headers="mcps1.2.6.1.5 "><p id="en-us_topic_0000001059148552_p181441434339"><a name="en-us_topic_0000001059148552_p181441434339"></a><a name="en-us_topic_0000001059148552_p181441434339"></a>Frame color.</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row1312214335332"><td class="cellrowborder" valign="top" width="17.09%" headers="mcps1.2.6.1.1 "><p id="en-us_topic_0000001059148552_p10123233193310"><a name="en-us_topic_0000001059148552_p10123233193310"></a><a name="en-us_topic_0000001059148552_p10123233193310"></a>fillColor</p>
</td>
<td class="cellrowborder" valign="top" width="17.09%" headers="mcps1.2.6.1.2 "><p id="en-us_topic_0000001059148552_p12123233123310"><a name="en-us_topic_0000001059148552_p12123233123310"></a><a name="en-us_topic_0000001059148552_p12123233123310"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="12.64%" headers="mcps1.2.6.1.3 "><p id="en-us_topic_0000001059148552_p10123143343313"><a name="en-us_topic_0000001059148552_p10123143343313"></a><a name="en-us_topic_0000001059148552_p10123143343313"></a>#ff0000</p>
</td>
<td class="cellrowborder" valign="top" width="10.549999999999999%" headers="mcps1.2.6.1.4 "><p id="en-us_topic_0000001059148552_p16123163317338"><a name="en-us_topic_0000001059148552_p16123163317338"></a><a name="en-us_topic_0000001059148552_p16123163317338"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="42.63%" headers="mcps1.2.6.1.5 "><p id="en-us_topic_0000001059148552_p6123433193311"><a name="en-us_topic_0000001059148552_p6123433193311"></a><a name="en-us_topic_0000001059148552_p6123433193311"></a>Fill color.</p>
</td>
</tr>
</tbody>
</table>

**Table  7**  ChartLoop

<a name="en-us_topic_0000001059148552_table13982347173714"></a>
<table><thead align="left"><tr id="en-us_topic_0000001059148552_row1498384714371"><th class="cellrowborder" valign="top" width="17.31%" id="mcps1.2.6.1.1"><p id="en-us_topic_0000001059148552_p1640543183916"><a name="en-us_topic_0000001059148552_p1640543183916"></a><a name="en-us_topic_0000001059148552_p1640543183916"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="17.65%" id="mcps1.2.6.1.2"><p id="en-us_topic_0000001059148552_p18640043143916"><a name="en-us_topic_0000001059148552_p18640043143916"></a><a name="en-us_topic_0000001059148552_p18640043143916"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="11.62%" id="mcps1.2.6.1.3"><p id="en-us_topic_0000001059148552_p12640144317398"><a name="en-us_topic_0000001059148552_p12640144317398"></a><a name="en-us_topic_0000001059148552_p12640144317398"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="11.39%" id="mcps1.2.6.1.4"><p id="en-us_topic_0000001059148552_p1764014343915"><a name="en-us_topic_0000001059148552_p1764014343915"></a><a name="en-us_topic_0000001059148552_p1764014343915"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="42.03%" id="mcps1.2.6.1.5"><p id="en-us_topic_0000001059148552_p1064084314395"><a name="en-us_topic_0000001059148552_p1064084314395"></a><a name="en-us_topic_0000001059148552_p1064084314395"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001059148552_row8983164710376"><td class="cellrowborder" valign="top" width="17.31%" headers="mcps1.2.6.1.1 "><p id="en-us_topic_0000001059148552_p11983147113716"><a name="en-us_topic_0000001059148552_p11983147113716"></a><a name="en-us_topic_0000001059148552_p11983147113716"></a>margin</p>
</td>
<td class="cellrowborder" valign="top" width="17.65%" headers="mcps1.2.6.1.2 "><p id="en-us_topic_0000001059148552_p1898316477374"><a name="en-us_topic_0000001059148552_p1898316477374"></a><a name="en-us_topic_0000001059148552_p1898316477374"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="11.62%" headers="mcps1.2.6.1.3 "><p id="en-us_topic_0000001059148552_p139841479376"><a name="en-us_topic_0000001059148552_p139841479376"></a><a name="en-us_topic_0000001059148552_p139841479376"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="11.39%" headers="mcps1.2.6.1.4 "><p id="en-us_topic_0000001059148552_p169842479376"><a name="en-us_topic_0000001059148552_p169842479376"></a><a name="en-us_topic_0000001059148552_p169842479376"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="42.03%" headers="mcps1.2.6.1.5 "><p id="en-us_topic_0000001059148552_p798434723720"><a name="en-us_topic_0000001059148552_p798434723720"></a><a name="en-us_topic_0000001059148552_p798434723720"></a>Number of erased points (horizontal distance between the latest drawn point and the earliest point). You are not advised to use <strong id="en-us_topic_0000001059148552_b16357142745814"><a name="en-us_topic_0000001059148552_b16357142745814"></a><a name="en-us_topic_0000001059148552_b16357142745814"></a>margin</strong> together with <strong id="en-us_topic_0000001059148552_b188717325586"><a name="en-us_topic_0000001059148552_b188717325586"></a><a name="en-us_topic_0000001059148552_b188717325586"></a>topPoint</strong>, <strong id="en-us_topic_0000001059148552_b32281537165815"><a name="en-us_topic_0000001059148552_b32281537165815"></a><a name="en-us_topic_0000001059148552_b32281537165815"></a>bottomPoint</strong>, or <strong id="en-us_topic_0000001059148552_b2578114315585"><a name="en-us_topic_0000001059148552_b2578114315585"></a><a name="en-us_topic_0000001059148552_b2578114315585"></a>headPoint</strong> for lite devices. If you do so, there is a possibility that the point is in the erase area and invisible.</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row109849472372"><td class="cellrowborder" valign="top" width="17.31%" headers="mcps1.2.6.1.1 "><p id="en-us_topic_0000001059148552_p09841047183715"><a name="en-us_topic_0000001059148552_p09841047183715"></a><a name="en-us_topic_0000001059148552_p09841047183715"></a>gradient</p>
</td>
<td class="cellrowborder" valign="top" width="17.65%" headers="mcps1.2.6.1.2 "><p id="en-us_topic_0000001059148552_p92761838193812"><a name="en-us_topic_0000001059148552_p92761838193812"></a><a name="en-us_topic_0000001059148552_p92761838193812"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="11.62%" headers="mcps1.2.6.1.3 "><p id="en-us_topic_0000001059148552_p127603819380"><a name="en-us_topic_0000001059148552_p127603819380"></a><a name="en-us_topic_0000001059148552_p127603819380"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="11.39%" headers="mcps1.2.6.1.4 "><p id="en-us_topic_0000001059148552_p227733816384"><a name="en-us_topic_0000001059148552_p227733816384"></a><a name="en-us_topic_0000001059148552_p227733816384"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="42.03%" headers="mcps1.2.6.1.5 "><p id="en-us_topic_0000001059148552_p13277173823811"><a name="en-us_topic_0000001059148552_p13277173823811"></a><a name="en-us_topic_0000001059148552_p13277173823811"></a>Whether to perform gradient erase.</p>
</td>
</tr>
</tbody>
</table>

**Table  8**  Point<sup>5+</sup>

<a name="en-us_topic_0000001059148552_table1470733752019"></a>
<table><thead align="left"><tr id="en-us_topic_0000001059148552_row177072373203"><th class="cellrowborder" valign="top" width="11.85%" id="mcps1.2.6.1.1"><p id="en-us_topic_0000001059148552_p1770793715201"><a name="en-us_topic_0000001059148552_p1770793715201"></a><a name="en-us_topic_0000001059148552_p1770793715201"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="12.030000000000001%" id="mcps1.2.6.1.2"><p id="en-us_topic_0000001059148552_p137073372202"><a name="en-us_topic_0000001059148552_p137073372202"></a><a name="en-us_topic_0000001059148552_p137073372202"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="9.83%" id="mcps1.2.6.1.3"><p id="en-us_topic_0000001059148552_p47078377208"><a name="en-us_topic_0000001059148552_p47078377208"></a><a name="en-us_topic_0000001059148552_p47078377208"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="9.04%" id="mcps1.2.6.1.4"><p id="en-us_topic_0000001059148552_p1470719376206"><a name="en-us_topic_0000001059148552_p1470719376206"></a><a name="en-us_topic_0000001059148552_p1470719376206"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="57.25%" id="mcps1.2.6.1.5"><p id="en-us_topic_0000001059148552_p1370783712017"><a name="en-us_topic_0000001059148552_p1370783712017"></a><a name="en-us_topic_0000001059148552_p1370783712017"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001059148552_row137071737112010"><td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.2.6.1.1 "><p id="en-us_topic_0000001059148552_p9707153711207"><a name="en-us_topic_0000001059148552_p9707153711207"></a><a name="en-us_topic_0000001059148552_p9707153711207"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.2.6.1.2 "><p id="en-us_topic_0000001059148552_p157081437132013"><a name="en-us_topic_0000001059148552_p157081437132013"></a><a name="en-us_topic_0000001059148552_p157081437132013"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="9.83%" headers="mcps1.2.6.1.3 "><p id="en-us_topic_0000001059148552_p970833722016"><a name="en-us_topic_0000001059148552_p970833722016"></a><a name="en-us_topic_0000001059148552_p970833722016"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.2.6.1.4 "><p id="en-us_topic_0000001059148552_p2070812378209"><a name="en-us_topic_0000001059148552_p2070812378209"></a><a name="en-us_topic_0000001059148552_p2070812378209"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="57.25%" headers="mcps1.2.6.1.5 "><p id="en-us_topic_0000001059148552_p188430361213"><a name="en-us_topic_0000001059148552_p188430361213"></a><a name="en-us_topic_0000001059148552_p188430361213"></a>Y coordinate of the point to draw.</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row13708173719202"><td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.2.6.1.1 "><p id="en-us_topic_0000001059148552_p18708143772014"><a name="en-us_topic_0000001059148552_p18708143772014"></a><a name="en-us_topic_0000001059148552_p18708143772014"></a>pointStyle</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.2.6.1.2 "><p id="en-us_topic_0000001059148552_p77081637172018"><a name="en-us_topic_0000001059148552_p77081637172018"></a><a name="en-us_topic_0000001059148552_p77081637172018"></a><a href="#en-us_topic_0000001059148552_table1435760101317">PointStyle</a></p>
</td>
<td class="cellrowborder" valign="top" width="9.83%" headers="mcps1.2.6.1.3 "><p id="en-us_topic_0000001059148552_p270803719206"><a name="en-us_topic_0000001059148552_p270803719206"></a><a name="en-us_topic_0000001059148552_p270803719206"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.2.6.1.4 "><p id="en-us_topic_0000001059148552_p19708133782018"><a name="en-us_topic_0000001059148552_p19708133782018"></a><a name="en-us_topic_0000001059148552_p19708133782018"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="57.25%" headers="mcps1.2.6.1.5 "><p id="en-us_topic_0000001059148552_p12708203712010"><a name="en-us_topic_0000001059148552_p12708203712010"></a><a name="en-us_topic_0000001059148552_p12708203712010"></a>Style of the point.</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row431291710242"><td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.2.6.1.1 "><p id="en-us_topic_0000001059148552_p13131917162412"><a name="en-us_topic_0000001059148552_p13131917162412"></a><a name="en-us_topic_0000001059148552_p13131917162412"></a>description</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.2.6.1.2 "><p id="en-us_topic_0000001059148552_p1231341710240"><a name="en-us_topic_0000001059148552_p1231341710240"></a><a name="en-us_topic_0000001059148552_p1231341710240"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.83%" headers="mcps1.2.6.1.3 "><p id="en-us_topic_0000001059148552_p14313121716241"><a name="en-us_topic_0000001059148552_p14313121716241"></a><a name="en-us_topic_0000001059148552_p14313121716241"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.2.6.1.4 "><p id="en-us_topic_0000001059148552_p13139178245"><a name="en-us_topic_0000001059148552_p13139178245"></a><a name="en-us_topic_0000001059148552_p13139178245"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="57.25%" headers="mcps1.2.6.1.5 "><p id="en-us_topic_0000001059148552_p11313171716246"><a name="en-us_topic_0000001059148552_p11313171716246"></a><a name="en-us_topic_0000001059148552_p11313171716246"></a>Description text of the point.</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row431301902517"><td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.2.6.1.1 "><p id="en-us_topic_0000001059148552_p1931461914251"><a name="en-us_topic_0000001059148552_p1931461914251"></a><a name="en-us_topic_0000001059148552_p1931461914251"></a>textLocation</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.2.6.1.2 "><p id="en-us_topic_0000001059148552_p1331471915257"><a name="en-us_topic_0000001059148552_p1331471915257"></a><a name="en-us_topic_0000001059148552_p1331471915257"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.83%" headers="mcps1.2.6.1.3 "><p id="en-us_topic_0000001059148552_p331431992516"><a name="en-us_topic_0000001059148552_p331431992516"></a><a name="en-us_topic_0000001059148552_p331431992516"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.2.6.1.4 "><p id="en-us_topic_0000001059148552_p33145199254"><a name="en-us_topic_0000001059148552_p33145199254"></a><a name="en-us_topic_0000001059148552_p33145199254"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="57.25%" headers="mcps1.2.6.1.5 "><p id="en-us_topic_0000001059148552_p6108637185"><a name="en-us_topic_0000001059148552_p6108637185"></a><a name="en-us_topic_0000001059148552_p6108637185"></a>Description text position relative to the point. Available values are as follows: </p>
<p id="en-us_topic_0000001059148552_p15749138180"><a name="en-us_topic_0000001059148552_p15749138180"></a><a name="en-us_topic_0000001059148552_p15749138180"></a><strong id="en-us_topic_0000001059148552_b117496386820"><a name="en-us_topic_0000001059148552_b117496386820"></a><a name="en-us_topic_0000001059148552_b117496386820"></a>top</strong>: above the point </p>
<p id="en-us_topic_0000001059148552_p65480401482"><a name="en-us_topic_0000001059148552_p65480401482"></a><a name="en-us_topic_0000001059148552_p65480401482"></a><strong id="en-us_topic_0000001059148552_b105484402815"><a name="en-us_topic_0000001059148552_b105484402815"></a><a name="en-us_topic_0000001059148552_b105484402815"></a>bottom</strong>: below the point </p>
<p id="en-us_topic_0000001059148552_p20314141922517"><a name="en-us_topic_0000001059148552_p20314141922517"></a><a name="en-us_topic_0000001059148552_p20314141922517"></a><strong id="en-us_topic_0000001059148552_b171799461313"><a name="en-us_topic_0000001059148552_b171799461313"></a><a name="en-us_topic_0000001059148552_b171799461313"></a>none</strong>: not displayed</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row48671150122613"><td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.2.6.1.1 "><p id="en-us_topic_0000001059148552_p486819509261"><a name="en-us_topic_0000001059148552_p486819509261"></a><a name="en-us_topic_0000001059148552_p486819509261"></a>textColor</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.2.6.1.2 "><p id="en-us_topic_0000001059148552_p12868165002617"><a name="en-us_topic_0000001059148552_p12868165002617"></a><a name="en-us_topic_0000001059148552_p12868165002617"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="9.83%" headers="mcps1.2.6.1.3 "><p id="en-us_topic_0000001059148552_p4868205002616"><a name="en-us_topic_0000001059148552_p4868205002616"></a><a name="en-us_topic_0000001059148552_p4868205002616"></a>#000000</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.2.6.1.4 "><p id="en-us_topic_0000001059148552_p1286825017267"><a name="en-us_topic_0000001059148552_p1286825017267"></a><a name="en-us_topic_0000001059148552_p1286825017267"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="57.25%" headers="mcps1.2.6.1.5 "><p id="en-us_topic_0000001059148552_p13868150162611"><a name="en-us_topic_0000001059148552_p13868150162611"></a><a name="en-us_topic_0000001059148552_p13868150162611"></a>Color of the description text.</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row9703542172713"><td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.2.6.1.1 "><p id="en-us_topic_0000001059148552_p1870364214275"><a name="en-us_topic_0000001059148552_p1870364214275"></a><a name="en-us_topic_0000001059148552_p1870364214275"></a>lineDash</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.2.6.1.2 "><p id="en-us_topic_0000001059148552_p1470334222718"><a name="en-us_topic_0000001059148552_p1470334222718"></a><a name="en-us_topic_0000001059148552_p1470334222718"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.83%" headers="mcps1.2.6.1.3 "><p id="en-us_topic_0000001059148552_p1670324217274"><a name="en-us_topic_0000001059148552_p1670324217274"></a><a name="en-us_topic_0000001059148552_p1670324217274"></a>solid</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.2.6.1.4 "><p id="en-us_topic_0000001059148552_p197033423272"><a name="en-us_topic_0000001059148552_p197033423272"></a><a name="en-us_topic_0000001059148552_p197033423272"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="57.25%" headers="mcps1.2.6.1.5 "><p id="en-us_topic_0000001059148552_p570304202712"><a name="en-us_topic_0000001059148552_p570304202712"></a><a name="en-us_topic_0000001059148552_p570304202712"></a>Dashed line pattern. You can set the dash length and space length between the dashes. For example, <strong id="en-us_topic_0000001059148552_b7111914270"><a name="en-us_topic_0000001059148552_b7111914270"></a><a name="en-us_topic_0000001059148552_b7111914270"></a>"dashed, 5, 5"</strong> indicates a dashed line with each dash in 5 px and a 5 px space between each two dashes. Default value <strong id="en-us_topic_0000001059148552_b08251016203215"><a name="en-us_topic_0000001059148552_b08251016203215"></a><a name="en-us_topic_0000001059148552_b08251016203215"></a>"solid"</strong> indicates a solid line.</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row15389105792810"><td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.2.6.1.1 "><p id="en-us_topic_0000001059148552_p15389357102818"><a name="en-us_topic_0000001059148552_p15389357102818"></a><a name="en-us_topic_0000001059148552_p15389357102818"></a>lineColor</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.2.6.1.2 "><p id="en-us_topic_0000001059148552_p3389135711281"><a name="en-us_topic_0000001059148552_p3389135711281"></a><a name="en-us_topic_0000001059148552_p3389135711281"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="9.83%" headers="mcps1.2.6.1.3 "><p id="en-us_topic_0000001059148552_p135711197293"><a name="en-us_topic_0000001059148552_p135711197293"></a><a name="en-us_topic_0000001059148552_p135711197293"></a>#000000</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.2.6.1.4 "><p id="en-us_topic_0000001059148552_p17389105762819"><a name="en-us_topic_0000001059148552_p17389105762819"></a><a name="en-us_topic_0000001059148552_p17389105762819"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="57.25%" headers="mcps1.2.6.1.5 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059148552_p19389175716289"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059148552_p19389175716289"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059148552_p19389175716289"></a>Line color. If this attribute is not set, the <strong id="en-us_topic_0000001059148552_b17128123414344"><a name="en-us_topic_0000001059148552_b17128123414344"></a><a name="en-us_topic_0000001059148552_b17128123414344"></a>strokeColor</strong> is used by default.</p>
</td>
</tr>
</tbody>
</table>

**Table  9**  DataSegment<sup>5+</sup>

<a name="en-us_topic_0000001059148552_table2596183616210"></a>
<table><thead align="left"><tr id="en-us_topic_0000001059148552_row15969362212"><th class="cellrowborder" valign="top" width="11.85%" id="mcps1.2.6.1.1"><p id="en-us_topic_0000001059148552_p159616362220"><a name="en-us_topic_0000001059148552_p159616362220"></a><a name="en-us_topic_0000001059148552_p159616362220"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="12.030000000000001%" id="mcps1.2.6.1.2"><p id="en-us_topic_0000001059148552_p175961136723"><a name="en-us_topic_0000001059148552_p175961136723"></a><a name="en-us_topic_0000001059148552_p175961136723"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="9.83%" id="mcps1.2.6.1.3"><p id="en-us_topic_0000001059148552_p259612361126"><a name="en-us_topic_0000001059148552_p259612361126"></a><a name="en-us_topic_0000001059148552_p259612361126"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="9.04%" id="mcps1.2.6.1.4"><p id="en-us_topic_0000001059148552_p135975361628"><a name="en-us_topic_0000001059148552_p135975361628"></a><a name="en-us_topic_0000001059148552_p135975361628"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="57.25%" id="mcps1.2.6.1.5"><p id="en-us_topic_0000001059148552_p13597136925"><a name="en-us_topic_0000001059148552_p13597136925"></a><a name="en-us_topic_0000001059148552_p13597136925"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001059148552_row165974360212"><td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.2.6.1.1 "><p id="en-us_topic_0000001059148552_p21970268105"><a name="en-us_topic_0000001059148552_p21970268105"></a><a name="en-us_topic_0000001059148552_p21970268105"></a>startColor</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.2.6.1.2 "><p id="en-us_topic_0000001059148552_p21981526141010"><a name="en-us_topic_0000001059148552_p21981526141010"></a><a name="en-us_topic_0000001059148552_p21981526141010"></a>Color</p>
</td>
<td class="cellrowborder" valign="top" width="9.83%" headers="mcps1.2.6.1.3 "><p id="en-us_topic_0000001059148552_p71988268108"><a name="en-us_topic_0000001059148552_p71988268108"></a><a name="en-us_topic_0000001059148552_p71988268108"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.2.6.1.4 "><p id="en-us_topic_0000001059148552_p6597133616215"><a name="en-us_topic_0000001059148552_p6597133616215"></a><a name="en-us_topic_0000001059148552_p6597133616215"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="57.25%" headers="mcps1.2.6.1.5 "><p id="en-us_topic_0000001059148552_p5652139121119"><a name="en-us_topic_0000001059148552_p5652139121119"></a><a name="en-us_topic_0000001059148552_p5652139121119"></a>Color of the start position. If this attribute is set, <strong id="en-us_topic_0000001059148552_b14583141810491"><a name="en-us_topic_0000001059148552_b14583141810491"></a><a name="en-us_topic_0000001059148552_b14583141810491"></a>endColor</strong> must be set. If this attribute is not set, the default color array preset in the system is used. For details about the color values, see the next table.</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row559719369213"><td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.2.6.1.1 "><p id="en-us_topic_0000001059148552_p1419812651017"><a name="en-us_topic_0000001059148552_p1419812651017"></a><a name="en-us_topic_0000001059148552_p1419812651017"></a>endColor</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.2.6.1.2 "><p id="en-us_topic_0000001059148552_p8198182631012"><a name="en-us_topic_0000001059148552_p8198182631012"></a><a name="en-us_topic_0000001059148552_p8198182631012"></a>Color</p>
</td>
<td class="cellrowborder" valign="top" width="9.83%" headers="mcps1.2.6.1.3 "><p id="en-us_topic_0000001059148552_p17198122612107"><a name="en-us_topic_0000001059148552_p17198122612107"></a><a name="en-us_topic_0000001059148552_p17198122612107"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.2.6.1.4 "><p id="en-us_topic_0000001059148552_p059710361211"><a name="en-us_topic_0000001059148552_p059710361211"></a><a name="en-us_topic_0000001059148552_p059710361211"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="57.25%" headers="mcps1.2.6.1.5 "><p id="en-us_topic_0000001059148552_p11652139131117"><a name="en-us_topic_0000001059148552_p11652139131117"></a><a name="en-us_topic_0000001059148552_p11652139131117"></a>Color of the end position. If this attribute is set, <strong id="en-us_topic_0000001059148552_b12654176135111"><a name="en-us_topic_0000001059148552_b12654176135111"></a><a name="en-us_topic_0000001059148552_b12654176135111"></a>startColor</strong> must be set.</p>
<p id="en-us_topic_0000001059148552_p10128174015175"><a name="en-us_topic_0000001059148552_p10128174015175"></a><a name="en-us_topic_0000001059148552_p10128174015175"></a>If this attribute is not set, the default color array preset in the system is used.</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row85973361925"><td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.2.6.1.1 "><p id="en-us_topic_0000001059148552_p91981926191015"><a name="en-us_topic_0000001059148552_p91981926191015"></a><a name="en-us_topic_0000001059148552_p91981926191015"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.2.6.1.2 "><p id="en-us_topic_0000001059148552_p1219813268100"><a name="en-us_topic_0000001059148552_p1219813268100"></a><a name="en-us_topic_0000001059148552_p1219813268100"></a>double</p>
</td>
<td class="cellrowborder" valign="top" width="9.83%" headers="mcps1.2.6.1.3 "><p id="en-us_topic_0000001059148552_p01988268105"><a name="en-us_topic_0000001059148552_p01988268105"></a><a name="en-us_topic_0000001059148552_p01988268105"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.2.6.1.4 "><p id="en-us_topic_0000001059148552_p1959819361216"><a name="en-us_topic_0000001059148552_p1959819361216"></a><a name="en-us_topic_0000001059148552_p1959819361216"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="57.25%" headers="mcps1.2.6.1.5 "><p id="en-us_topic_0000001059148552_p106521339131120"><a name="en-us_topic_0000001059148552_p106521339131120"></a><a name="en-us_topic_0000001059148552_p106521339131120"></a>Percentage for the current data segment. The maximum value is <strong id="en-us_topic_0000001059148552_b9780144416522"><a name="en-us_topic_0000001059148552_b9780144416522"></a><a name="en-us_topic_0000001059148552_b9780144416522"></a>100</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row85983361124"><td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.2.6.1.1 "><p id="en-us_topic_0000001059148552_p1119816260101"><a name="en-us_topic_0000001059148552_p1119816260101"></a><a name="en-us_topic_0000001059148552_p1119816260101"></a>name</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.2.6.1.2 "><p id="en-us_topic_0000001059148552_p6198226161014"><a name="en-us_topic_0000001059148552_p6198226161014"></a><a name="en-us_topic_0000001059148552_p6198226161014"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.83%" headers="mcps1.2.6.1.3 "><p id="en-us_topic_0000001059148552_p1519852614107"><a name="en-us_topic_0000001059148552_p1519852614107"></a><a name="en-us_topic_0000001059148552_p1519852614107"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.2.6.1.4 "><p id="en-us_topic_0000001059148552_p25984367213"><a name="en-us_topic_0000001059148552_p25984367213"></a><a name="en-us_topic_0000001059148552_p25984367213"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="57.25%" headers="mcps1.2.6.1.5 "><p id="en-us_topic_0000001059148552_p11653339151117"><a name="en-us_topic_0000001059148552_p11653339151117"></a><a name="en-us_topic_0000001059148552_p11653339151117"></a>Name of this data segment.</p>
</td>
</tr>
</tbody>
</table>

<a name="en-us_topic_0000001059148552_table19699121263711"></a>
<table><thead align="left"><tr id="en-us_topic_0000001059148552_row106991512133715"><th class="cellrowborder" valign="top" width="5.8205820582058205%" id="mcps1.1.4.1.1"><p id="en-us_topic_0000001059148552_p9699181218379"><a name="en-us_topic_0000001059148552_p9699181218379"></a><a name="en-us_topic_0000001059148552_p9699181218379"></a>Data Segment</p>
</th>
<th class="cellrowborder" valign="top" width="41.7941794179418%" id="mcps1.1.4.1.2"><p id="en-us_topic_0000001059148552_p1699171219372"><a name="en-us_topic_0000001059148552_p1699171219372"></a><a name="en-us_topic_0000001059148552_p1699171219372"></a>Light Mode</p>
</th>
<th class="cellrowborder" valign="top" width="52.38523852385239%" id="mcps1.1.4.1.3"><p id="en-us_topic_0000001059148552_p16699112103710"><a name="en-us_topic_0000001059148552_p16699112103710"></a><a name="en-us_topic_0000001059148552_p16699112103710"></a>Dark Mode</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001059148552_row9699112163711"><td class="cellrowborder" valign="top" width="5.8205820582058205%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001059148552_p36992012193712"><a name="en-us_topic_0000001059148552_p36992012193712"></a><a name="en-us_topic_0000001059148552_p36992012193712"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="41.7941794179418%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001059148552_p15700712163717"><a name="en-us_topic_0000001059148552_p15700712163717"></a><a name="en-us_topic_0000001059148552_p15700712163717"></a>Start color: #f7ce00; end color: #f99b11</p>
</td>
<td class="cellrowborder" valign="top" width="52.38523852385239%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001059148552_p5700512173712"><a name="en-us_topic_0000001059148552_p5700512173712"></a><a name="en-us_topic_0000001059148552_p5700512173712"></a>Start color: #d1a738; end color: #eb933d</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row53180543816"><td class="cellrowborder" valign="top" width="5.8205820582058205%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001059148552_p931816516385"><a name="en-us_topic_0000001059148552_p931816516385"></a><a name="en-us_topic_0000001059148552_p931816516385"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="41.7941794179418%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001059148552_p2590113224315"><a name="en-us_topic_0000001059148552_p2590113224315"></a><a name="en-us_topic_0000001059148552_p2590113224315"></a>Start color: #f76223; end color: #f2400a</p>
</td>
<td class="cellrowborder" valign="top" width="52.38523852385239%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001059148552_p153182553814"><a name="en-us_topic_0000001059148552_p153182553814"></a><a name="en-us_topic_0000001059148552_p153182553814"></a>Start color: #e67d50; end color: #d9542b</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row5161209163810"><td class="cellrowborder" valign="top" width="5.8205820582058205%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001059148552_p1616120910383"><a name="en-us_topic_0000001059148552_p1616120910383"></a><a name="en-us_topic_0000001059148552_p1616120910383"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="41.7941794179418%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001059148552_p91616973812"><a name="en-us_topic_0000001059148552_p91616973812"></a><a name="en-us_topic_0000001059148552_p91616973812"></a>Start color: #f772ac; end color: #e65392</p>
</td>
<td class="cellrowborder" valign="top" width="52.38523852385239%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001059148552_p2161189183817"><a name="en-us_topic_0000001059148552_p2161189183817"></a><a name="en-us_topic_0000001059148552_p2161189183817"></a>Start color: #d5749e; end color: #d6568d</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row956361913385"><td class="cellrowborder" valign="top" width="5.8205820582058205%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001059148552_p12563181918388"><a name="en-us_topic_0000001059148552_p12563181918388"></a><a name="en-us_topic_0000001059148552_p12563181918388"></a>3</p>
</td>
<td class="cellrowborder" valign="top" width="41.7941794179418%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001059148552_p25633192386"><a name="en-us_topic_0000001059148552_p25633192386"></a><a name="en-us_topic_0000001059148552_p25633192386"></a>Start color: #a575eb; end color: #a12df7</p>
</td>
<td class="cellrowborder" valign="top" width="52.38523852385239%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001059148552_p25631219183815"><a name="en-us_topic_0000001059148552_p25631219183815"></a><a name="en-us_topic_0000001059148552_p25631219183815"></a>Start color: #9973d1; end color: #5552d9</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row893012813389"><td class="cellrowborder" valign="top" width="5.8205820582058205%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001059148552_p1393092815385"><a name="en-us_topic_0000001059148552_p1393092815385"></a><a name="en-us_topic_0000001059148552_p1393092815385"></a>4</p>
</td>
<td class="cellrowborder" valign="top" width="41.7941794179418%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001059148552_p493092812387"><a name="en-us_topic_0000001059148552_p493092812387"></a><a name="en-us_topic_0000001059148552_p493092812387"></a>Start color: #7b79f7; end color: #4b48f7</p>
</td>
<td class="cellrowborder" valign="top" width="52.38523852385239%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001059148552_p6930228123813"><a name="en-us_topic_0000001059148552_p6930228123813"></a><a name="en-us_topic_0000001059148552_p6930228123813"></a>Start color: #7977d9; end color: #f99b11</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row11109426123812"><td class="cellrowborder" valign="top" width="5.8205820582058205%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001059148552_p1010912612382"><a name="en-us_topic_0000001059148552_p1010912612382"></a><a name="en-us_topic_0000001059148552_p1010912612382"></a>5</p>
</td>
<td class="cellrowborder" valign="top" width="41.7941794179418%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001059148552_p4109026173811"><a name="en-us_topic_0000001059148552_p4109026173811"></a><a name="en-us_topic_0000001059148552_p4109026173811"></a>Start color: #4b8af3; end color: #007dff</p>
</td>
<td class="cellrowborder" valign="top" width="52.38523852385239%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001059148552_p2109026173816"><a name="en-us_topic_0000001059148552_p2109026173816"></a><a name="en-us_topic_0000001059148552_p2109026173816"></a>Start color: #4c81d9; end color: #217bd9</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row1569813163818"><td class="cellrowborder" valign="top" width="5.8205820582058205%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001059148552_p196911318389"><a name="en-us_topic_0000001059148552_p196911318389"></a><a name="en-us_topic_0000001059148552_p196911318389"></a>6</p>
</td>
<td class="cellrowborder" valign="top" width="41.7941794179418%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001059148552_p186971323817"><a name="en-us_topic_0000001059148552_p186971323817"></a><a name="en-us_topic_0000001059148552_p186971323817"></a>Start color: #73c1e6; end color: #4fb4e3</p>
</td>
<td class="cellrowborder" valign="top" width="52.38523852385239%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001059148552_p169513183810"><a name="en-us_topic_0000001059148552_p169513183810"></a><a name="en-us_topic_0000001059148552_p169513183810"></a>Start color: #5ea6d1; end color: #4895c2</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row1428922313819"><td class="cellrowborder" valign="top" width="5.8205820582058205%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001059148552_p628912231384"><a name="en-us_topic_0000001059148552_p628912231384"></a><a name="en-us_topic_0000001059148552_p628912231384"></a>7</p>
</td>
<td class="cellrowborder" valign="top" width="41.7941794179418%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001059148552_p0289823193820"><a name="en-us_topic_0000001059148552_p0289823193820"></a><a name="en-us_topic_0000001059148552_p0289823193820"></a>Start color: #a5d61d; end color: #69d14f</p>
</td>
<td class="cellrowborder" valign="top" width="52.38523852385239%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001059148552_p12289192316386"><a name="en-us_topic_0000001059148552_p12289192316386"></a><a name="en-us_topic_0000001059148552_p12289192316386"></a>Start color: #91c23a; end color: #70ba5d</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row10565416153819"><td class="cellrowborder" valign="top" width="5.8205820582058205%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001059148552_p156516165388"><a name="en-us_topic_0000001059148552_p156516165388"></a><a name="en-us_topic_0000001059148552_p156516165388"></a>8</p>
</td>
<td class="cellrowborder" valign="top" width="41.7941794179418%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001059148552_p175652016143816"><a name="en-us_topic_0000001059148552_p175652016143816"></a><a name="en-us_topic_0000001059148552_p175652016143816"></a>Start color: #a2a2b0; end color: #8e8e93</p>
</td>
<td class="cellrowborder" valign="top" width="52.38523852385239%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001059148552_p5565101633813"><a name="en-us_topic_0000001059148552_p5565101633813"></a><a name="en-us_topic_0000001059148552_p5565101633813"></a>Start color: #8c8c99; end color: #6b6b76</p>
</td>
</tr>
</tbody>
</table>

For gauge charts, the following attribute is supported.

<a name="en-us_topic_0000001059148552_table591221715358"></a>
<table><thead align="left"><tr id="en-us_topic_0000001059148552_row7912417143518"><th class="cellrowborder" valign="top" width="23.52%" id="mcps1.1.6.1.1"><p id="en-us_topic_0000001059148552_p19912161763516"><a name="en-us_topic_0000001059148552_p19912161763516"></a><a name="en-us_topic_0000001059148552_p19912161763516"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="11.76%" id="mcps1.1.6.1.2"><p id="en-us_topic_0000001059148552_p11912151718350"><a name="en-us_topic_0000001059148552_p11912151718350"></a><a name="en-us_topic_0000001059148552_p11912151718350"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="11.72%" id="mcps1.1.6.1.3"><p id="en-us_topic_0000001059148552_p1791231713518"><a name="en-us_topic_0000001059148552_p1791231713518"></a><a name="en-us_topic_0000001059148552_p1791231713518"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="8%" id="mcps1.1.6.1.4"><p id="en-us_topic_0000001059148552_p7913161710357"><a name="en-us_topic_0000001059148552_p7913161710357"></a><a name="en-us_topic_0000001059148552_p7913161710357"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="45%" id="mcps1.1.6.1.5"><p id="en-us_topic_0000001059148552_p9913111717353"><a name="en-us_topic_0000001059148552_p9913111717353"></a><a name="en-us_topic_0000001059148552_p9913111717353"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001059148552_row99131917123518"><td class="cellrowborder" valign="top" width="23.52%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001059148552_p1091312179351"><a name="en-us_topic_0000001059148552_p1091312179351"></a><a name="en-us_topic_0000001059148552_p1091312179351"></a>percent</p>
</td>
<td class="cellrowborder" valign="top" width="11.76%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001059148552_p20913111723518"><a name="en-us_topic_0000001059148552_p20913111723518"></a><a name="en-us_topic_0000001059148552_p20913111723518"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.72%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001059148552_p891361723510"><a name="en-us_topic_0000001059148552_p891361723510"></a><a name="en-us_topic_0000001059148552_p891361723510"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="8%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001059148552_p1913151711357"><a name="en-us_topic_0000001059148552_p1913151711357"></a><a name="en-us_topic_0000001059148552_p1913151711357"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="45%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001059148552_p39134178350"><a name="en-us_topic_0000001059148552_p39134178350"></a><a name="en-us_topic_0000001059148552_p39134178350"></a>Percentage of the current value to the total value. The value ranges from 0 to 100.</p>
</td>
</tr>
</tbody>
</table>

## Method<a name="en-us_topic_0000001059148552_section5955645132417"></a>

<a name="en-us_topic_0000001059148552_table826516417256"></a>
<table><thead align="left"><tr id="en-us_topic_0000001059148552_row3266741172514"><th class="cellrowborder" valign="top" width="8.630863086308631%" id="mcps1.1.4.1.1"><p id="en-us_topic_0000001059148552_p7266164172516"><a name="en-us_topic_0000001059148552_p7266164172516"></a><a name="en-us_topic_0000001059148552_p7266164172516"></a>Method</p>
</th>
<th class="cellrowborder" valign="top" width="58.035803580358035%" id="mcps1.1.4.1.2"><p id="en-us_topic_0000001059148552_p2266184113251"><a name="en-us_topic_0000001059148552_p2266184113251"></a><a name="en-us_topic_0000001059148552_p2266184113251"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.3"><p id="en-us_topic_0000001059148552_p1226616411255"><a name="en-us_topic_0000001059148552_p1226616411255"></a><a name="en-us_topic_0000001059148552_p1226616411255"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001059148552_row172666416259"><td class="cellrowborder" valign="top" width="8.630863086308631%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001059148552_p526615416255"><a name="en-us_topic_0000001059148552_p526615416255"></a><a name="en-us_topic_0000001059148552_p526615416255"></a>append</p>
</td>
<td class="cellrowborder" valign="top" width="58.035803580358035%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001059148552_p962415556399"><a name="en-us_topic_0000001059148552_p962415556399"></a><a name="en-us_topic_0000001059148552_p962415556399"></a>{</p>
<p id="en-us_topic_0000001059148552_p118975913395"><a name="en-us_topic_0000001059148552_p118975913395"></a><a name="en-us_topic_0000001059148552_p118975913395"></a>serial: number, // Set the data subscript of the line chart to be updated.</p>
<p id="en-us_topic_0000001059148552_p191641035401"><a name="en-us_topic_0000001059148552_p191641035401"></a><a name="en-us_topic_0000001059148552_p191641035401"></a>data: Array&lt;number&gt;, // Set the new data.</p>
<p id="en-us_topic_0000001059148552_p10266114120253"><a name="en-us_topic_0000001059148552_p10266114120253"></a><a name="en-us_topic_0000001059148552_p10266114120253"></a>}</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001059148552_p1526615419258"><a name="en-us_topic_0000001059148552_p1526615419258"></a><a name="en-us_topic_0000001059148552_p1526615419258"></a>Data is dynamically added to an existing data sequence. The target sequence is specified based on <strong id="en-us_topic_0000001059148552_b181361720173312"><a name="en-us_topic_0000001059148552_b181361720173312"></a><a name="en-us_topic_0000001059148552_b181361720173312"></a>serial</strong>, which is the subscript of the datasets array and starts from 0. <strong id="en-us_topic_0000001059148552_b2513193515314"><a name="en-us_topic_0000001059148552_b2513193515314"></a><a name="en-us_topic_0000001059148552_b2513193515314"></a>datasets[index].data</strong> is not updated. Only line charts support this attribute. The value is incremented by 1 based on the horizontal coordinate and is related to the <strong id="en-us_topic_0000001059148552_b16836711978"><a name="en-us_topic_0000001059148552_b16836711978"></a><a name="en-us_topic_0000001059148552_b16836711978"></a>xAxis min/max</strong> setting.</p>
</td>
</tr>
</tbody>
</table>

## Event<a name="en-us_topic_0000001059148552_section749131815264"></a>

<a name="en-us_topic_0000001059148552_table836435619510"></a>
<table><thead align="left"><tr id="en-us_topic_0000001059148552_en-us_topic_0000001058460527_rf3d0da15d2f64cd492dfa1e7d98890a5"><th class="cellrowborder" valign="top" width="15.02%" id="mcps1.1.4.1.1"><p id="en-us_topic_0000001059148552_en-us_topic_0000001058460527_a487aa1c493e84ca68567b4b65051674d"><a name="en-us_topic_0000001059148552_en-us_topic_0000001058460527_a487aa1c493e84ca68567b4b65051674d"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001058460527_a487aa1c493e84ca68567b4b65051674d"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="23.05%" id="mcps1.1.4.1.2"><p id="en-us_topic_0000001059148552_en-us_topic_0000001058460527_adc4b506cda3043508da6ee7649c12ca4"><a name="en-us_topic_0000001059148552_en-us_topic_0000001058460527_adc4b506cda3043508da6ee7649c12ca4"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001058460527_adc4b506cda3043508da6ee7649c12ca4"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="61.92999999999999%" id="mcps1.1.4.1.3"><p id="en-us_topic_0000001059148552_en-us_topic_0000001058460527_a59e4cbe58a5c42a7a4585bc8365783bc"><a name="en-us_topic_0000001059148552_en-us_topic_0000001058460527_a59e4cbe58a5c42a7a4585bc8365783bc"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001058460527_a59e4cbe58a5c42a7a4585bc8365783bc"></a>Triggered when</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001059148552_en-us_topic_0000001058460527_r7683acd1d0964f31840d03c9aeb32fca"><td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001058460527_a58fb4b1d870f466e955cf5ea879c4d4a"><a name="en-us_topic_0000001059148552_en-us_topic_0000001058460527_a58fb4b1d870f466e955cf5ea879c4d4a"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001058460527_a58fb4b1d870f466e955cf5ea879c4d4a"></a>touchstart</p>
</td>
<td class="cellrowborder" valign="top" width="23.05%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001058460527_abefebd99301b4bdebb798d1b9df24d8d"><a name="en-us_topic_0000001059148552_en-us_topic_0000001058460527_abefebd99301b4bdebb798d1b9df24d8d"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001058460527_abefebd99301b4bdebb798d1b9df24d8d"></a><a href="universal-events.md#en-us_topic_0000001058460527_tdb541af4e4db41d7a92e9b6e3c93f606">TouchEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="61.92999999999999%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001058460527_afa4290e2620f4f5fbdcb74dcae84e536"><a name="en-us_topic_0000001059148552_en-us_topic_0000001058460527_afa4290e2620f4f5fbdcb74dcae84e536"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001058460527_afa4290e2620f4f5fbdcb74dcae84e536"></a>The tapping starts</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_en-us_topic_0000001058460527_r7f70ef6c895e4d2d95325887fee7d62e"><td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001058460527_a23e0317cfee94650be4dcd2280c3e94e"><a name="en-us_topic_0000001059148552_en-us_topic_0000001058460527_a23e0317cfee94650be4dcd2280c3e94e"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001058460527_a23e0317cfee94650be4dcd2280c3e94e"></a>touchmove</p>
</td>
<td class="cellrowborder" valign="top" width="23.05%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001058460527_aea26e4f9575044dc8fb65080f3a6684a"><a name="en-us_topic_0000001059148552_en-us_topic_0000001058460527_aea26e4f9575044dc8fb65080f3a6684a"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001058460527_aea26e4f9575044dc8fb65080f3a6684a"></a><a href="universal-events.md#en-us_topic_0000001058460527_tdb541af4e4db41d7a92e9b6e3c93f606">TouchEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="61.92999999999999%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001058460527_a37f7cc43d82c4ee18512bd079349079d"><a name="en-us_topic_0000001059148552_en-us_topic_0000001058460527_a37f7cc43d82c4ee18512bd079349079d"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001058460527_a37f7cc43d82c4ee18512bd079349079d"></a>The tapping moves</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_en-us_topic_0000001058460527_ra5c278d41f9045ed9d95e13165974bf4"><td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001058460527_ad0728eeac06143bbb4a6fdf1ed5c6d91"><a name="en-us_topic_0000001059148552_en-us_topic_0000001058460527_ad0728eeac06143bbb4a6fdf1ed5c6d91"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001058460527_ad0728eeac06143bbb4a6fdf1ed5c6d91"></a>touchcancel</p>
</td>
<td class="cellrowborder" valign="top" width="23.05%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001058460527_a59e2819eae2b4d3e935991b43156347b"><a name="en-us_topic_0000001059148552_en-us_topic_0000001058460527_a59e2819eae2b4d3e935991b43156347b"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001058460527_a59e2819eae2b4d3e935991b43156347b"></a><a href="universal-events.md#en-us_topic_0000001058460527_tdb541af4e4db41d7a92e9b6e3c93f606">TouchEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="61.92999999999999%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001058460527_a739d9ef0db624f6284554aeaeddffa0a"><a name="en-us_topic_0000001059148552_en-us_topic_0000001058460527_a739d9ef0db624f6284554aeaeddffa0a"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001058460527_a739d9ef0db624f6284554aeaeddffa0a"></a>The tapping is interrupted</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_en-us_topic_0000001058460527_rddfe06969173404d96b60c402a7e783c"><td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001058460527_a233e2f6ff39f49fd97b8f233875d01d4"><a name="en-us_topic_0000001059148552_en-us_topic_0000001058460527_a233e2f6ff39f49fd97b8f233875d01d4"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001058460527_a233e2f6ff39f49fd97b8f233875d01d4"></a>touchend</p>
</td>
<td class="cellrowborder" valign="top" width="23.05%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001058460527_a439e69aaf158448e99b3c81cbc9fd624"><a name="en-us_topic_0000001059148552_en-us_topic_0000001058460527_a439e69aaf158448e99b3c81cbc9fd624"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001058460527_a439e69aaf158448e99b3c81cbc9fd624"></a><a href="universal-events.md#en-us_topic_0000001058460527_tdb541af4e4db41d7a92e9b6e3c93f606">TouchEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="61.92999999999999%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001058460527_a05c0fe4e05ef4154acee8a06ad56a2de"><a name="en-us_topic_0000001059148552_en-us_topic_0000001058460527_a05c0fe4e05ef4154acee8a06ad56a2de"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001058460527_a05c0fe4e05ef4154acee8a06ad56a2de"></a>The tapping ends</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_en-us_topic_0000001058460527_rec1121b8bebc4a3f9ed9a906d061746e"><td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001058460527_a2fb4de45b1594f6fa1a7da45ce0db57f"><a name="en-us_topic_0000001059148552_en-us_topic_0000001058460527_a2fb4de45b1594f6fa1a7da45ce0db57f"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001058460527_a2fb4de45b1594f6fa1a7da45ce0db57f"></a>click</p>
</td>
<td class="cellrowborder" valign="top" width="23.05%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001058460527_af86bf1da40504ed2a8d14213a42536ab"><a name="en-us_topic_0000001059148552_en-us_topic_0000001058460527_af86bf1da40504ed2a8d14213a42536ab"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001058460527_af86bf1da40504ed2a8d14213a42536ab"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="61.92999999999999%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001058460527_a1d32f00c38c440ddaa63c3f3e01d4e09"><a name="en-us_topic_0000001059148552_en-us_topic_0000001058460527_a1d32f00c38c440ddaa63c3f3e01d4e09"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001058460527_a1d32f00c38c440ddaa63c3f3e01d4e09"></a>A component is clicked</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_en-us_topic_0000001058460527_r95f500ef9402487ea42e829d69606f90"><td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001058460527_aa7dc63d1b4924872bbff6a6a100e928f"><a name="en-us_topic_0000001059148552_en-us_topic_0000001058460527_aa7dc63d1b4924872bbff6a6a100e928f"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001058460527_aa7dc63d1b4924872bbff6a6a100e928f"></a>longpress</p>
</td>
<td class="cellrowborder" valign="top" width="23.05%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001058460527_a39186f4ff74544d89ace56ea87d9937b"><a name="en-us_topic_0000001059148552_en-us_topic_0000001058460527_a39186f4ff74544d89ace56ea87d9937b"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001058460527_a39186f4ff74544d89ace56ea87d9937b"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="61.92999999999999%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001058460527_a44b8585170304b5596c41714772e605e"><a name="en-us_topic_0000001059148552_en-us_topic_0000001058460527_a44b8585170304b5596c41714772e605e"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001058460527_a44b8585170304b5596c41714772e605e"></a>A component is long pressed</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_en-us_topic_0000001058460527_row117014569616"><td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001058460527_p12706561061"><a name="en-us_topic_0000001059148552_en-us_topic_0000001058460527_p12706561061"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001058460527_p12706561061"></a>swipe<sup id="en-us_topic_0000001059148552_en-us_topic_0000001058460527_sup35424382912"><a name="en-us_topic_0000001059148552_en-us_topic_0000001058460527_sup35424382912"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001058460527_sup35424382912"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="23.05%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001058460527_p11711056161"><a name="en-us_topic_0000001059148552_en-us_topic_0000001058460527_p11711056161"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001058460527_p11711056161"></a><a href="universal-events.md#en-us_topic_0000001058460527_table111811577714">SwipeEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="61.92999999999999%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001058460527_p2711556162"><a name="en-us_topic_0000001059148552_en-us_topic_0000001058460527_p2711556162"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001058460527_p2711556162"></a>A user quickly swipes on a component.</p>
</td>
</tr>
</tbody>
</table>

## Style<a name="en-us_topic_0000001059148552_section5775351116"></a>

<a name="en-us_topic_0000001059148552_table124404442319"></a>
<table><thead align="left"><tr id="en-us_topic_0000001059148552_row244104482316"><th class="cellrowborder" valign="top" width="23.11768823117688%" id="mcps1.1.6.1.1"><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a14a0c012a26248cfbec6b13dcc4f2cbe"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a14a0c012a26248cfbec6b13dcc4f2cbe"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a14a0c012a26248cfbec6b13dcc4f2cbe"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="20.477952204779523%" id="mcps1.1.6.1.2"><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a8dc328a555a74157a00de86181fc3a7b"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a8dc328a555a74157a00de86181fc3a7b"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a8dc328a555a74157a00de86181fc3a7b"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="8.869113088691131%" id="mcps1.1.6.1.3"><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a41a31e48d0c74ad4982add2655515c82"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a41a31e48d0c74ad4982add2655515c82"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a41a31e48d0c74ad4982add2655515c82"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="7.519248075192481%" id="mcps1.1.6.1.4"><p id="en-us_topic_0000001059148552_p124544472310"><a name="en-us_topic_0000001059148552_p124544472310"></a><a name="en-us_topic_0000001059148552_p124544472310"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="40.01599840015999%" id="mcps1.1.6.1.5"><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_af7a726e456f7485c87bd4e0527bc6584"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_af7a726e456f7485c87bd4e0527bc6584"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_af7a726e456f7485c87bd4e0527bc6584"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001059148552_row17669103214585"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001059148552_p7998445185811"><a name="en-us_topic_0000001059148552_p7998445185811"></a><a name="en-us_topic_0000001059148552_p7998445185811"></a>stroke-width</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001059148552_p69981045185815"><a name="en-us_topic_0000001059148552_p69981045185815"></a><a name="en-us_topic_0000001059148552_p69981045185815"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001059148552_p399924517587"><a name="en-us_topic_0000001059148552_p399924517587"></a><a name="en-us_topic_0000001059148552_p399924517587"></a>32px (<strong id="en-us_topic_0000001059148552_b18760253113612"><a name="en-us_topic_0000001059148552_b18760253113612"></a><a name="en-us_topic_0000001059148552_b18760253113612"></a>gauge</strong> charts)</p>
<p id="en-us_topic_0000001059148552_p496875411249"><a name="en-us_topic_0000001059148552_p496875411249"></a><a name="en-us_topic_0000001059148552_p496875411249"></a>24px (<strong id="en-us_topic_0000001059148552_b513445814226"><a name="en-us_topic_0000001059148552_b513445814226"></a><a name="en-us_topic_0000001059148552_b513445814226"></a>rainbow</strong> charts)</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001059148552_p119991145175819"><a name="en-us_topic_0000001059148552_p119991145175819"></a><a name="en-us_topic_0000001059148552_p119991145175819"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001059148552_p169991245175817"><a name="en-us_topic_0000001059148552_p169991245175817"></a><a name="en-us_topic_0000001059148552_p169991245175817"></a>Width of the scale bar for <strong id="en-us_topic_0000001059148552_b87491134152415"><a name="en-us_topic_0000001059148552_b87491134152415"></a><a name="en-us_topic_0000001059148552_b87491134152415"></a>gauge</strong><span id="en-us_topic_0000001059148552_ph13553164411532"><a name="en-us_topic_0000001059148552_ph13553164411532"></a><a name="en-us_topic_0000001059148552_ph13553164411532"></a> and <strong id="en-us_topic_0000001059148552_b125075528532"><a name="en-us_topic_0000001059148552_b125075528532"></a><a name="en-us_topic_0000001059148552_b125075528532"></a>rainbow</strong></span> charts.</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row267010322582"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001059148552_p19991145195813"><a name="en-us_topic_0000001059148552_p19991145195813"></a><a name="en-us_topic_0000001059148552_p19991145195813"></a>start-angle</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001059148552_p099994545812"><a name="en-us_topic_0000001059148552_p099994545812"></a><a name="en-us_topic_0000001059148552_p099994545812"></a>&lt;deg&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001059148552_p1599934517582"><a name="en-us_topic_0000001059148552_p1599934517582"></a><a name="en-us_topic_0000001059148552_p1599934517582"></a>240 (<strong id="en-us_topic_0000001059148552_b261719915266"><a name="en-us_topic_0000001059148552_b261719915266"></a><a name="en-us_topic_0000001059148552_b261719915266"></a>gauge</strong> charts)</p>
<p id="en-us_topic_0000001059148552_p18138163412238"><a name="en-us_topic_0000001059148552_p18138163412238"></a><a name="en-us_topic_0000001059148552_p18138163412238"></a>0 (<strong id="en-us_topic_0000001059148552_b87861144102514"><a name="en-us_topic_0000001059148552_b87861144102514"></a><a name="en-us_topic_0000001059148552_b87861144102514"></a>rainbow</strong> charts)</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001059148552_p59994457581"><a name="en-us_topic_0000001059148552_p59994457581"></a><a name="en-us_topic_0000001059148552_p59994457581"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001059148552_p1099914513588"><a name="en-us_topic_0000001059148552_p1099914513588"></a><a name="en-us_topic_0000001059148552_p1099914513588"></a>Start angle of the scale bar for <strong id="en-us_topic_0000001059148552_b1609185210263"><a name="en-us_topic_0000001059148552_b1609185210263"></a><a name="en-us_topic_0000001059148552_b1609185210263"></a>gauge</strong><span id="en-us_topic_0000001059148552_ph19730142615547"><a name="en-us_topic_0000001059148552_ph19730142615547"></a><a name="en-us_topic_0000001059148552_ph19730142615547"></a>and <strong id="en-us_topic_0000001059148552_b884734842613"><a name="en-us_topic_0000001059148552_b884734842613"></a><a name="en-us_topic_0000001059148552_b884734842613"></a>rainbow</strong></span> charts, which starts from the direction of zero o'clock. The value ranges from 0 to 360.</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row10670143216582"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001059148552_p11999445135820"><a name="en-us_topic_0000001059148552_p11999445135820"></a><a name="en-us_topic_0000001059148552_p11999445135820"></a>total-angle</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001059148552_p49998454589"><a name="en-us_topic_0000001059148552_p49998454589"></a><a name="en-us_topic_0000001059148552_p49998454589"></a>&lt;deg&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001059148552_p299913451581"><a name="en-us_topic_0000001059148552_p299913451581"></a><a name="en-us_topic_0000001059148552_p299913451581"></a>240 (<strong id="en-us_topic_0000001059148552_b82262662820"><a name="en-us_topic_0000001059148552_b82262662820"></a><a name="en-us_topic_0000001059148552_b82262662820"></a>gauge</strong> charts)</p>
<p id="en-us_topic_0000001059148552_p1539919952411"><a name="en-us_topic_0000001059148552_p1539919952411"></a><a name="en-us_topic_0000001059148552_p1539919952411"></a>360 (<strong id="en-us_topic_0000001059148552_b664058172810"><a name="en-us_topic_0000001059148552_b664058172810"></a><a name="en-us_topic_0000001059148552_b664058172810"></a>rainbow</strong> charts)</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001059148552_p199984585810"><a name="en-us_topic_0000001059148552_p199984585810"></a><a name="en-us_topic_0000001059148552_p199984585810"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001059148552_p169991545145820"><a name="en-us_topic_0000001059148552_p169991545145820"></a><a name="en-us_topic_0000001059148552_p169991545145820"></a>Total length of the scale bar for <strong id="en-us_topic_0000001059148552_b4142940182820"><a name="en-us_topic_0000001059148552_b4142940182820"></a><a name="en-us_topic_0000001059148552_b4142940182820"></a>gauge</strong><span id="en-us_topic_0000001059148552_ph1865121432318"><a name="en-us_topic_0000001059148552_ph1865121432318"></a><a name="en-us_topic_0000001059148552_ph1865121432318"></a> and <strong id="en-us_topic_0000001059148552_b0142154014286"><a name="en-us_topic_0000001059148552_b0142154014286"></a><a name="en-us_topic_0000001059148552_b0142154014286"></a>rainbow</strong></span> charts. The value ranges from –360 to 360. A negative number indicates the anticlockwise direction.</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row1967063205815"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001059148552_p1299915458588"><a name="en-us_topic_0000001059148552_p1299915458588"></a><a name="en-us_topic_0000001059148552_p1299915458588"></a>center-x</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001059148552_p12999154515819"><a name="en-us_topic_0000001059148552_p12999154515819"></a><a name="en-us_topic_0000001059148552_p12999154515819"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001059148552_p20146205816"><a name="en-us_topic_0000001059148552_p20146205816"></a><a name="en-us_topic_0000001059148552_p20146205816"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001059148552_p60144615819"><a name="en-us_topic_0000001059148552_p60144615819"></a><a name="en-us_topic_0000001059148552_p60144615819"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001059148552_p12015465581"><a name="en-us_topic_0000001059148552_p12015465581"></a><a name="en-us_topic_0000001059148552_p12015465581"></a>Center of the scale bar of the gauge component. This style is supported by the gauge chart only. This style takes precedence over the <strong id="en-us_topic_0000001059148552_b1116220342476"><a name="en-us_topic_0000001059148552_b1116220342476"></a><a name="en-us_topic_0000001059148552_b1116220342476"></a>position</strong> style in the common styles, and must be used together with <strong id="en-us_topic_0000001059148552_b14129141895413"><a name="en-us_topic_0000001059148552_b14129141895413"></a><a name="en-us_topic_0000001059148552_b14129141895413"></a>center-y</strong> and <strong id="en-us_topic_0000001059148552_b513515182543"><a name="en-us_topic_0000001059148552_b513515182543"></a><a name="en-us_topic_0000001059148552_b513515182543"></a>radius</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row18269202217586"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001059148552_p13024605818"><a name="en-us_topic_0000001059148552_p13024605818"></a><a name="en-us_topic_0000001059148552_p13024605818"></a>center-y</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001059148552_p90114645817"><a name="en-us_topic_0000001059148552_p90114645817"></a><a name="en-us_topic_0000001059148552_p90114645817"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001059148552_p60546165812"><a name="en-us_topic_0000001059148552_p60546165812"></a><a name="en-us_topic_0000001059148552_p60546165812"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001059148552_p50846185813"><a name="en-us_topic_0000001059148552_p50846185813"></a><a name="en-us_topic_0000001059148552_p50846185813"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001059148552_p17054610588"><a name="en-us_topic_0000001059148552_p17054610588"></a><a name="en-us_topic_0000001059148552_p17054610588"></a>Center of the scale bar of the gauge component. This style is supported by the gauge chart only. This style takes precedence over the <strong id="en-us_topic_0000001059148552_b198543134913"><a name="en-us_topic_0000001059148552_b198543134913"></a><a name="en-us_topic_0000001059148552_b198543134913"></a>position</strong> style in the common styles, and must be used together with <strong id="en-us_topic_0000001059148552_b5497122013546"><a name="en-us_topic_0000001059148552_b5497122013546"></a><a name="en-us_topic_0000001059148552_b5497122013546"></a>center-x</strong> and <strong id="en-us_topic_0000001059148552_b0498620115413"><a name="en-us_topic_0000001059148552_b0498620115413"></a><a name="en-us_topic_0000001059148552_b0498620115413"></a>radius</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row1264611017585"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001059148552_p10034655819"><a name="en-us_topic_0000001059148552_p10034655819"></a><a name="en-us_topic_0000001059148552_p10034655819"></a>radius</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001059148552_p60746145819"><a name="en-us_topic_0000001059148552_p60746145819"></a><a name="en-us_topic_0000001059148552_p60746145819"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001059148552_p40104655820"><a name="en-us_topic_0000001059148552_p40104655820"></a><a name="en-us_topic_0000001059148552_p40104655820"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001059148552_p15018469585"><a name="en-us_topic_0000001059148552_p15018469585"></a><a name="en-us_topic_0000001059148552_p15018469585"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001059148552_p13010468584"><a name="en-us_topic_0000001059148552_p13010468584"></a><a name="en-us_topic_0000001059148552_p13010468584"></a>Radius of the scale bar of the gauge component. This style is supported by the gauge chart only. This style takes precedence over the <strong id="en-us_topic_0000001059148552_b91381042517"><a name="en-us_topic_0000001059148552_b91381042517"></a><a name="en-us_topic_0000001059148552_b91381042517"></a>width</strong> and <strong id="en-us_topic_0000001059148552_b10941110165113"><a name="en-us_topic_0000001059148552_b10941110165113"></a><a name="en-us_topic_0000001059148552_b10941110165113"></a>height</strong> in the common styles, and must be used together with <strong id="en-us_topic_0000001059148552_b737582218548"><a name="en-us_topic_0000001059148552_b737582218548"></a><a name="en-us_topic_0000001059148552_b737582218548"></a>center-x</strong> and <strong id="en-us_topic_0000001059148552_b18375112215413"><a name="en-us_topic_0000001059148552_b18375112215413"></a><a name="en-us_topic_0000001059148552_b18375112215413"></a>center-y</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row6213184185812"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001059148552_p130104612581"><a name="en-us_topic_0000001059148552_p130104612581"></a><a name="en-us_topic_0000001059148552_p130104612581"></a>colors</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001059148552_p1608468585"><a name="en-us_topic_0000001059148552_p1608468585"></a><a name="en-us_topic_0000001059148552_p1608468585"></a>Array</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001059148552_p13084655814"><a name="en-us_topic_0000001059148552_p13084655814"></a><a name="en-us_topic_0000001059148552_p13084655814"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001059148552_p1311346145814"><a name="en-us_topic_0000001059148552_p1311346145814"></a><a name="en-us_topic_0000001059148552_p1311346145814"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001059148552_p1411446105819"><a name="en-us_topic_0000001059148552_p1411446105819"></a><a name="en-us_topic_0000001059148552_p1411446105819"></a>Color of each section for the scale bar of the gauge component.</p>
<p id="en-us_topic_0000001059148552_p1515461580"><a name="en-us_topic_0000001059148552_p1515461580"></a><a name="en-us_topic_0000001059148552_p1515461580"></a>For example,<strong id="en-us_topic_0000001059148552_b1786062281317"><a name="en-us_topic_0000001059148552_b1786062281317"></a><a name="en-us_topic_0000001059148552_b1786062281317"></a> colors: #ff0000, #00ff00</strong>. This style is supported by the gauge chart only.</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row151804815583"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001059148552_p31246165816"><a name="en-us_topic_0000001059148552_p31246165816"></a><a name="en-us_topic_0000001059148552_p31246165816"></a>weights</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001059148552_p812046125810"><a name="en-us_topic_0000001059148552_p812046125810"></a><a name="en-us_topic_0000001059148552_p812046125810"></a>Array</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001059148552_p171046155813"><a name="en-us_topic_0000001059148552_p171046155813"></a><a name="en-us_topic_0000001059148552_p171046155813"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001059148552_p8174615582"><a name="en-us_topic_0000001059148552_p8174615582"></a><a name="en-us_topic_0000001059148552_p8174615582"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001059148552_p8117461589"><a name="en-us_topic_0000001059148552_p8117461589"></a><a name="en-us_topic_0000001059148552_p8117461589"></a>Weight of each section for the scale bar of the gauge component.</p>
<p id="en-us_topic_0000001059148552_p141134635812"><a name="en-us_topic_0000001059148552_p141134635812"></a><a name="en-us_topic_0000001059148552_p141134635812"></a>For example, weights: 2, 2. This style is supported by the gauge chart only.</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row4208131313017"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001059148552_p1120821312307"><a name="en-us_topic_0000001059148552_p1120821312307"></a><a name="en-us_topic_0000001059148552_p1120821312307"></a>font-family<sup id="en-us_topic_0000001059148552_sup1710278132714"><a name="en-us_topic_0000001059148552_sup1710278132714"></a><a name="en-us_topic_0000001059148552_sup1710278132714"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001059148552_p7208613163010"><a name="en-us_topic_0000001059148552_p7208613163010"></a><a name="en-us_topic_0000001059148552_p7208613163010"></a>Array</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001059148552_p172081613163020"><a name="en-us_topic_0000001059148552_p172081613163020"></a><a name="en-us_topic_0000001059148552_p172081613163020"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001059148552_p120812138308"><a name="en-us_topic_0000001059148552_p120812138308"></a><a name="en-us_topic_0000001059148552_p120812138308"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001059148552_p9208131313017"><a name="en-us_topic_0000001059148552_p9208131313017"></a><a name="en-us_topic_0000001059148552_p9208131313017"></a>Font style of the description text. You can use <a href="custom-font-styles.md#EN-US_TOPIC_0000001162414611">Custom Font Styles</a>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row118919117314"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001059148552_p7892161116317"><a name="en-us_topic_0000001059148552_p7892161116317"></a><a name="en-us_topic_0000001059148552_p7892161116317"></a>font-size<sup id="en-us_topic_0000001059148552_sup17808141112279"><a name="en-us_topic_0000001059148552_sup17808141112279"></a><a name="en-us_topic_0000001059148552_sup17808141112279"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001059148552_p138921611123116"><a name="en-us_topic_0000001059148552_p138921611123116"></a><a name="en-us_topic_0000001059148552_p138921611123116"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001059148552_p168921111183112"><a name="en-us_topic_0000001059148552_p168921111183112"></a><a name="en-us_topic_0000001059148552_p168921111183112"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001059148552_p15892181113114"><a name="en-us_topic_0000001059148552_p15892181113114"></a><a name="en-us_topic_0000001059148552_p15892181113114"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001059148552_p389213115318"><a name="en-us_topic_0000001059148552_p389213115318"></a><a name="en-us_topic_0000001059148552_p389213115318"></a>Font size of the description text.</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row2045114414233"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a8bc81ecef4934adf91deb1d6167045d7"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a8bc81ecef4934adf91deb1d6167045d7"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a8bc81ecef4934adf91deb1d6167045d7"></a>width</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a59692217b9c94353a020a2f0a20f01a7"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a59692217b9c94353a020a2f0a20f01a7"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a59692217b9c94353a020a2f0a20f01a7"></a>&lt;length&gt; | &lt;percentage&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p3948114217528"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p3948114217528"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p3948114217528"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001059148552_p1045104416236"><a name="en-us_topic_0000001059148552_p1045104416236"></a><a name="en-us_topic_0000001059148552_p1045104416236"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p624653010258"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p624653010258"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p624653010258"></a>Component width.</p>
<p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p84811050134010"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p84811050134010"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p84811050134010"></a>If this attribute is not set, the width required for the element content is used. </p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row64520448231"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a738cc687552c4b8cb1aa9f9e7d9ea8c2"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a738cc687552c4b8cb1aa9f9e7d9ea8c2"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a738cc687552c4b8cb1aa9f9e7d9ea8c2"></a>height</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a82c5d9c65b3646ec92afe5f0f47a2149"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a82c5d9c65b3646ec92afe5f0f47a2149"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a82c5d9c65b3646ec92afe5f0f47a2149"></a>&lt;length&gt;<span id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ph11748352163918"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ph11748352163918"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ph11748352163918"></a></span> | &lt;percentage&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a7e6c7daafecf475888d0420835662eb4"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a7e6c7daafecf475888d0420835662eb4"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a7e6c7daafecf475888d0420835662eb4"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001059148552_p3461344132317"><a name="en-us_topic_0000001059148552_p3461344132317"></a><a name="en-us_topic_0000001059148552_p3461344132317"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p1477601264"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p1477601264"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p1477601264"></a>Component height.</p>
<p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p208761554184020"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p208761554184020"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p208761554184020"></a>If this length attribute is not set, the length required for the element content is used. </p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row84624411233"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a8ff18465b8f0453c836067e5902b7eb6"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a8ff18465b8f0453c836067e5902b7eb6"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a8ff18465b8f0453c836067e5902b7eb6"></a>padding</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a53628f36a25a4823a901d5b66860f44e"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a53628f36a25a4823a901d5b66860f44e"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a53628f36a25a4823a901d5b66860f44e"></a>&lt;length&gt; | &lt;percentage&gt;<sup id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_sup1886516813013"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_sup1886516813013"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_sup1886516813013"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_adc824deaee924821a47a798b589f22c8"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_adc824deaee924821a47a798b589f22c8"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_adc824deaee924821a47a798b589f22c8"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p19729127112814"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p19729127112814"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p19729127112814"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p157435053316"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p157435053316"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p157435053316"></a>Shorthand attribute to set all padding attributes.</p>
<div class="p" id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a68a6d5ddc59c49f0aaddd82e75932524"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a68a6d5ddc59c49f0aaddd82e75932524"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a68a6d5ddc59c49f0aaddd82e75932524"></a>The attribute can have one to four values:<a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ul15202134923211"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ul15202134923211"></a><ul id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ul15202134923211"><li><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p10614155353215"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p10614155353215"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p10614155353215"></a>If you set only one value, it specifies the padding for four sides.</p>
</li><li><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p10614175393216"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p10614175393216"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p10614175393216"></a>If you set two values, the first value specifies the top and bottom padding, and the second value specifies the left and right padding.</p>
</li><li><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p8614205393214"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p8614205393214"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p8614205393214"></a>If you set three values, the first value specifies the top padding, the second value specifies the left and right padding, and the third value specifies the bottom padding.</p>
</li><li><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p106141853193215"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p106141853193215"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p106141853193215"></a>If you set four values, they respectively specify the padding for top, right, bottom, and left sides (in clockwise order).</p>
</li></ul>
</div>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row1047174420236"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ab0185a7b5a4944f3b38f8c71c8ca794d"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ab0185a7b5a4944f3b38f8c71c8ca794d"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ab0185a7b5a4944f3b38f8c71c8ca794d"></a>padding-[left|top|right|bottom]</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a49dd523e2f1b4253a19231e776dc1951"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a49dd523e2f1b4253a19231e776dc1951"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a49dd523e2f1b4253a19231e776dc1951"></a>&lt;length&gt; | &lt;percentage&gt;<sup id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_sup19949912807"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_sup19949912807"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_sup19949912807"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_af52ecd93919b4fa08ae4d376e3d544a2"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_af52ecd93919b4fa08ae4d376e3d544a2"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_af52ecd93919b4fa08ae4d376e3d544a2"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p11729374289"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p11729374289"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p11729374289"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a3575ab240d384ab1a21119ea3428ab7d"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a3575ab240d384ab1a21119ea3428ab7d"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a3575ab240d384ab1a21119ea3428ab7d"></a>Left, top, right, and bottom padding (in px).</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row74764442310"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p769124717365"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p769124717365"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p769124717365"></a>padding-[start|end]</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p157617124374"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p157617124374"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p157617124374"></a>&lt;length&gt; | &lt;percentage&gt;<sup id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_sup8490161513019"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_sup8490161513019"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_sup8490161513019"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p1069144703616"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p1069144703616"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p1069144703616"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p1373027182819"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p1373027182819"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p1373027182819"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p1269184753610"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p1269184753610"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p1269184753610"></a>Start and end padding.</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row148104492318"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_afa508e5429d948b2b561943d6b2f0f31"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_afa508e5429d948b2b561943d6b2f0f31"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_afa508e5429d948b2b561943d6b2f0f31"></a>margin</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a4dab4f9d97a74a27a45b7ef1d2ab08e6"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a4dab4f9d97a74a27a45b7ef1d2ab08e6"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a4dab4f9d97a74a27a45b7ef1d2ab08e6"></a>&lt;length&gt; | &lt;percentage&gt;<sup id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_sup1433352175220"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_sup1433352175220"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_sup1433352175220"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a5e3c234d78214e8180b51d237adda154"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a5e3c234d78214e8180b51d237adda154"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a5e3c234d78214e8180b51d237adda154"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p4730774285"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p4730774285"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p4730774285"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a1d350e36a773420baf5ebb930cd5ad66"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a1d350e36a773420baf5ebb930cd5ad66"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a1d350e36a773420baf5ebb930cd5ad66"></a>Shorthand attribute to set margins for all sides in a declaration. The attribute can have one to four values:</p>
<a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ul5333133311105"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ul5333133311105"></a><ul id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ul5333133311105"><li><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p03345339103"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p03345339103"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p03345339103"></a>If you set only one value, it specifies the margin for all the four sides.</p>
</li><li><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p1133420334108"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p1133420334108"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p1133420334108"></a>If you set two values, the first value is for the top and bottom sides and the second value for the left and right sides.</p>
</li><li><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p193341533191015"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p193341533191015"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p193341533191015"></a>If you set three values, the first value is for the top, the second value for the left and right, and the third value for the bottom.</p>
</li><li><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p733412334102"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p733412334102"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p733412334102"></a>If you set four values, they are margins for top, right, bottom, and left sides, respectively.</p>
</li></ul>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row4481044182319"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a70939a36b2b04dd8bec21f5bddc8637e"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a70939a36b2b04dd8bec21f5bddc8637e"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a70939a36b2b04dd8bec21f5bddc8637e"></a>margin-[left|top|right|bottom]</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ae53ac9ac370d483990e04ea9789c1e49"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ae53ac9ac370d483990e04ea9789c1e49"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ae53ac9ac370d483990e04ea9789c1e49"></a>&lt;length&gt; | &lt;percentage&gt;<sup id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_sup378331720532"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_sup378331720532"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_sup378331720532"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a180cd037e6174e5c82f35a3a66b6f2ec"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a180cd037e6174e5c82f35a3a66b6f2ec"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a180cd037e6174e5c82f35a3a66b6f2ec"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p773013742811"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p773013742811"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p773013742811"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a487d09add6e54c5c89fa4f22e9318271"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a487d09add6e54c5c89fa4f22e9318271"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a487d09add6e54c5c89fa4f22e9318271"></a>Left, top, right, and bottom margins.</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row549194422314"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p9492107123816"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p9492107123816"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p9492107123816"></a>margin-[start|end]</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p157617124374_1"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p157617124374_1"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p157617124374_1"></a>&lt;length&gt; | &lt;percentage&gt;<sup id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_sup8490161513019_1"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_sup8490161513019_1"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_sup8490161513019_1"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p1549213793811"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p1549213793811"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p1549213793811"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001059148552_p1649144142317"><a name="en-us_topic_0000001059148552_p1649144142317"></a><a name="en-us_topic_0000001059148552_p1649144142317"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p1049212715388"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p1049212715388"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p1049212715388"></a>Start and end margins.</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row1549154472313"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a222bb48f24014f2eb2b16a1a840bbebb"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a222bb48f24014f2eb2b16a1a840bbebb"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a222bb48f24014f2eb2b16a1a840bbebb"></a>border</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a79b4eaf9983c44d0aad39ff04d0997a8"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a79b4eaf9983c44d0aad39ff04d0997a8"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a79b4eaf9983c44d0aad39ff04d0997a8"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_aac320f4f0a42401aa7fa778d9829d77c"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_aac320f4f0a42401aa7fa778d9829d77c"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_aac320f4f0a42401aa7fa778d9829d77c"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001059148552_p144934412239"><a name="en-us_topic_0000001059148552_p144934412239"></a><a name="en-us_topic_0000001059148552_p144934412239"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a9cd962871a4c467a8e1ef452621d5cd7"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a9cd962871a4c467a8e1ef452621d5cd7"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a9cd962871a4c467a8e1ef452621d5cd7"></a>Shorthand attribute to set all borders. You can set <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b79128342503"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b79128342503"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b79128342503"></a>border-width</strong>, <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b9366173919505"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b9366173919505"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b9366173919505"></a>border-style</strong>, and <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b184351248205019"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b184351248205019"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b184351248205019"></a>border-color</strong> in sequence. Default values are used for attributes that are not set.</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row10491344102313"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a987708c0864a4128af094334f1b024b3"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a987708c0864a4128af094334f1b024b3"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a987708c0864a4128af094334f1b024b3"></a>border-style</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p513631613319"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p513631613319"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p513631613319"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a2567083af59c40e58e3e4d9b0ddf1485"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a2567083af59c40e58e3e4d9b0ddf1485"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a2567083af59c40e58e3e4d9b0ddf1485"></a>solid</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001059148552_p19503442237"><a name="en-us_topic_0000001059148552_p19503442237"></a><a name="en-us_topic_0000001059148552_p19503442237"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p342285712314"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p342285712314"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p342285712314"></a>Shorthand attribute to set the style for all borders. Available values are as follows:</p>
<a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ul1470834505612"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ul1470834505612"></a><ul id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ul1470834505612"><li><strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b143453286360"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b143453286360"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b143453286360"></a>dotted</strong>: Dotted border. The radius of a dot is half of border-width.</li><li><strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b792117280367"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b792117280367"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b792117280367"></a>dashed</strong>: Dashed border</li></ul>
<a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ul15621125545612"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ul15621125545612"></a><ul id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ul15621125545612"><li><strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b1335862963610"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b1335862963610"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b1335862963610"></a>solid</strong>: Solid border</li></ul>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row158901822154418"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001059148552_p589112225442"><a name="en-us_topic_0000001059148552_p589112225442"></a><a name="en-us_topic_0000001059148552_p589112225442"></a>border-[left|top|right|bottom]-style</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001059148552_p6891102211445"><a name="en-us_topic_0000001059148552_p6891102211445"></a><a name="en-us_topic_0000001059148552_p6891102211445"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001059148552_p118911422104419"><a name="en-us_topic_0000001059148552_p118911422104419"></a><a name="en-us_topic_0000001059148552_p118911422104419"></a>solid</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001059148552_p1891132284413"><a name="en-us_topic_0000001059148552_p1891132284413"></a><a name="en-us_topic_0000001059148552_p1891132284413"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001059148552_p16891102274415"><a name="en-us_topic_0000001059148552_p16891102274415"></a><a name="en-us_topic_0000001059148552_p16891102274415"></a>Styles of the left, top, right, and bottom borders. The available values are <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b17769171311540"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b17769171311540"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b17769171311540"></a>dotted</strong>, <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b237141519547"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b237141519547"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b237141519547"></a>dashed</strong>, and <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b8949161613540"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b8949161613540"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b8949161613540"></a>solid</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row851154492314"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a8afd82b1aba547d3b0188b749518b2de"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a8afd82b1aba547d3b0188b749518b2de"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a8afd82b1aba547d3b0188b749518b2de"></a>border-[left|top|right|bottom]</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ac4b8a3b39e5446b5868f1f2989dc9590"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ac4b8a3b39e5446b5868f1f2989dc9590"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ac4b8a3b39e5446b5868f1f2989dc9590"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a3420bc82bd17458ab82fa996ade7064c"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a3420bc82bd17458ab82fa996ade7064c"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a3420bc82bd17458ab82fa996ade7064c"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p67303762810"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p67303762810"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p67303762810"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_af4178a066c344412afbd38f4b0c44818"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_af4178a066c344412afbd38f4b0c44818"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_af4178a066c344412afbd38f4b0c44818"></a>Shorthand attribute to set the borders for every side respectively. You can set <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b122415514554"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b122415514554"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b122415514554"></a>border-width</strong>, <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b12296178135513"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b12296178135513"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b12296178135513"></a>border-style</strong>, and <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b1129701210553"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b1129701210553"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b1129701210553"></a>border-color</strong> in sequence. Default values are used for attributes that are not set.</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row051194492320"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_adf0e0afedc774afca9cda0e509391029"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_adf0e0afedc774afca9cda0e509391029"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_adf0e0afedc774afca9cda0e509391029"></a>border-width</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a0782ea2c45eb4864a8df82f30dd2cd5f"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a0782ea2c45eb4864a8df82f30dd2cd5f"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a0782ea2c45eb4864a8df82f30dd2cd5f"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a395cbedd521145bd820b9171ee2dd7ac"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a395cbedd521145bd820b9171ee2dd7ac"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a395cbedd521145bd820b9171ee2dd7ac"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001059148552_p75274482319"><a name="en-us_topic_0000001059148552_p75274482319"></a><a name="en-us_topic_0000001059148552_p75274482319"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a7ae60621ea3341818a03bfdffa641894"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a7ae60621ea3341818a03bfdffa641894"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a7ae60621ea3341818a03bfdffa641894"></a>Shorthand attribute to set the width of all borders<span id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ph07997369365"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ph07997369365"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ph07997369365"></a>, or separately set the width of each border</span>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row65213443238"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a7371edc07c664266a2e1866f31ad0d0c"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a7371edc07c664266a2e1866f31ad0d0c"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a7371edc07c664266a2e1866f31ad0d0c"></a>border-[left|top|right|bottom]-width</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a2faa532b841948a7b6598542b4eccc7b"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a2faa532b841948a7b6598542b4eccc7b"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a2faa532b841948a7b6598542b4eccc7b"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a87f38cfa47f54bc18c32f9671c0f9ca6"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a87f38cfa47f54bc18c32f9671c0f9ca6"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a87f38cfa47f54bc18c32f9671c0f9ca6"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001059148552_p45294472317"><a name="en-us_topic_0000001059148552_p45294472317"></a><a name="en-us_topic_0000001059148552_p45294472317"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a20386e66c3834d5f96cf9435c4715c5b"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a20386e66c3834d5f96cf9435c4715c5b"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a20386e66c3834d5f96cf9435c4715c5b"></a>Attribute to set widths of left, top, right, and bottom borders.</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row052134419238"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a40a816cf0a03489d81f209a8aa7d81a6"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a40a816cf0a03489d81f209a8aa7d81a6"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a40a816cf0a03489d81f209a8aa7d81a6"></a>border-color</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_afcc7c948ae0947b2a78002d31f2f9748"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_afcc7c948ae0947b2a78002d31f2f9748"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_afcc7c948ae0947b2a78002d31f2f9748"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ae0909d2b896342f9b2196fe0dce72920"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ae0909d2b896342f9b2196fe0dce72920"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ae0909d2b896342f9b2196fe0dce72920"></a>black</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001059148552_p9521044142317"><a name="en-us_topic_0000001059148552_p9521044142317"></a><a name="en-us_topic_0000001059148552_p9521044142317"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a76fd98995e1d4217aa703fecd69325c7"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a76fd98995e1d4217aa703fecd69325c7"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a76fd98995e1d4217aa703fecd69325c7"></a>Shorthand attribute to set the color of all borders<span id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ph9587639113619"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ph9587639113619"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ph9587639113619"></a>, or separately set the color of each border</span>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row1852144442315"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a2afc646d6a2549548bcd5c4b9bed1fb5"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a2afc646d6a2549548bcd5c4b9bed1fb5"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a2afc646d6a2549548bcd5c4b9bed1fb5"></a>border-[left|top|right|bottom]-color</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a34556866a4f54f5da88f148fc698867b"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a34556866a4f54f5da88f148fc698867b"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a34556866a4f54f5da88f148fc698867b"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a8ff58e18553846a38e82c69149e2aa30"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a8ff58e18553846a38e82c69149e2aa30"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a8ff58e18553846a38e82c69149e2aa30"></a>black</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001059148552_p105314412314"><a name="en-us_topic_0000001059148552_p105314412314"></a><a name="en-us_topic_0000001059148552_p105314412314"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a5c85947d388c4c7fbf0de07b022bb44e"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a5c85947d388c4c7fbf0de07b022bb44e"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a5c85947d388c4c7fbf0de07b022bb44e"></a>Attribute to set colors of left, top, right, and bottom borders.</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row953844182310"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a65974e3078c447a383fb9237cc4ffa32"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a65974e3078c447a383fb9237cc4ffa32"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a65974e3078c447a383fb9237cc4ffa32"></a>border-radius</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a413fd0aea8b243349a19f825e96ee8b6"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a413fd0aea8b243349a19f825e96ee8b6"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a413fd0aea8b243349a19f825e96ee8b6"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_af786857698c74e259f52589a6670a0a1"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_af786857698c74e259f52589a6670a0a1"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_af786857698c74e259f52589a6670a0a1"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p67306752816"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p67306752816"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p67306752816"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a52ca834f42124d3b8b12bbf54914fc96"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a52ca834f42124d3b8b12bbf54914fc96"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a52ca834f42124d3b8b12bbf54914fc96"></a>Attribute to set the radius of round borders of an element. <span id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ph1249443123611"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ph1249443123611"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ph1249443123611"></a>This attribute cannot be used to set the width, color, or style of a specific border. To set the width or color, you need to set <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b124211434362"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b124211434362"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b124211434362"></a>border-width</strong>, <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b124894383615"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b124894383615"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b124894383615"></a>border-color</strong>, or <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b7166134516465"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b7166134516465"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b7166134516465"></a>border-style</strong> for all the borders at the same time.</span></p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row2541944162318"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a466f1f8bc2fb404e82e8417c5133eacb"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a466f1f8bc2fb404e82e8417c5133eacb"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a466f1f8bc2fb404e82e8417c5133eacb"></a>border-[top|bottom]-[left|right]-radius</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a499fe910d0284647abc48b1bd0eb4868"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a499fe910d0284647abc48b1bd0eb4868"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a499fe910d0284647abc48b1bd0eb4868"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ac142d1054eee499f948069f46129c492"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ac142d1054eee499f948069f46129c492"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ac142d1054eee499f948069f46129c492"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p27305718283"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p27305718283"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p27305718283"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a63757091a86c4ced97f0c39d37a2117c"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a63757091a86c4ced97f0c39d37a2117c"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a63757091a86c4ced97f0c39d37a2117c"></a>Attribute to receptively set the radii of upper-left, upper-right, lower-right, and lower-left rounded corners</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row0548446238"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ae335be2c6150440fb31b40b1ca117858"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ae335be2c6150440fb31b40b1ca117858"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ae335be2c6150440fb31b40b1ca117858"></a>background</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a394a81171c5c4d1aa81b94fc5d2f0f07"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a394a81171c5c4d1aa81b94fc5d2f0f07"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a394a81171c5c4d1aa81b94fc5d2f0f07"></a>&lt;linear-gradient&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a0734de04e90e470cb608e8d5f42c6874"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a0734de04e90e470cb608e8d5f42c6874"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a0734de04e90e470cb608e8d5f42c6874"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p15730197132811"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p15730197132811"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p15730197132811"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a1d2985ee819d4cfd87861080354def51"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a1d2985ee819d4cfd87861080354def51"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a1d2985ee819d4cfd87861080354def51"></a>This attribute supports <a href="gradient-styles.md#EN-US_TOPIC_0000001115974726">Gradient Styles</a> only but is not compatible with <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b389373419292"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b389373419292"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b389373419292"></a>background-color</strong> or <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b0399637142918"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b0399637142918"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b0399637142918"></a>background-image</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row754174410234"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a2977672444224b738a566c61225961c2"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a2977672444224b738a566c61225961c2"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a2977672444224b738a566c61225961c2"></a>background-color</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a87186748ed7c4694aef0095d8a7f8e43"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a87186748ed7c4694aef0095d8a7f8e43"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a87186748ed7c4694aef0095d8a7f8e43"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a2775a3cca8994bec9b754af0d2455eb5"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a2775a3cca8994bec9b754af0d2455eb5"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a2775a3cca8994bec9b754af0d2455eb5"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p17730577282"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p17730577282"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p17730577282"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a372b6089bf9746f091c91fa49b571f1d"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a372b6089bf9746f091c91fa49b571f1d"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a372b6089bf9746f091c91fa49b571f1d"></a>Background color.</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row455124419234"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ab2dff80cd59c4db1bf4293172f89735e"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ab2dff80cd59c4db1bf4293172f89735e"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ab2dff80cd59c4db1bf4293172f89735e"></a>background-image</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ad9a7e9f2469b45238a6a0ac6da232286"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ad9a7e9f2469b45238a6a0ac6da232286"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ad9a7e9f2469b45238a6a0ac6da232286"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a73fb72c96edd488ba74c364568e345c6"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a73fb72c96edd488ba74c364568e345c6"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a73fb72c96edd488ba74c364568e345c6"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p7730976285"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p7730976285"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p7730976285"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a24de29e3cb4d476fabe55d48d69350a8"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a24de29e3cb4d476fabe55d48d69350a8"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a24de29e3cb4d476fabe55d48d69350a8"></a>Background image. Currently, this attribute is not compatible with <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b17699154763620"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b17699154763620"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b17699154763620"></a>background-color</strong> or <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b87001647163613"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b87001647163613"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b87001647163613"></a>background</strong>. Local image resources are supported.</p>
<p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p45914251572"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p45914251572"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p45914251572"></a>Example:</p>
<p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p16184973578"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p16184973578"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p16184973578"></a>background-image: url("/common/background.png")</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row185515446230"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_af81424fd1fbf4f5da65ea5d136390494"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_af81424fd1fbf4f5da65ea5d136390494"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_af81424fd1fbf4f5da65ea5d136390494"></a>background-size</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ul1065173641310"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ul1065173641310"></a><ul id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ul1065173641310"><li>string</li><li>&lt;length&gt; &lt;length&gt;</li><li>&lt;percentage&gt; &lt;percentage&gt;</li></ul>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a222f4e09239a4ab08880d1d9544d337c"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a222f4e09239a4ab08880d1d9544d337c"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a222f4e09239a4ab08880d1d9544d337c"></a>auto</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p137309714282"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p137309714282"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p137309714282"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p91971112114318"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p91971112114318"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p91971112114318"></a>Background image size.</p>
<a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ul41331853154111"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ul41331853154111"></a><ul id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ul41331853154111"><li>The <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b1229715499365"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b1229715499365"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b1229715499365"></a>string</strong> values are as follows:<a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ul13611494111"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ul13611494111"></a><ul id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ul13611494111"><li><strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b4759749163610"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b4759749163610"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b4759749163610"></a>contain</strong>: Expands the image to the maximum size so that the height and width of the image are applicable to the content area.</li><li><strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b437619381712"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b437619381712"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b437619381712"></a>cover</strong>: Extends the background image to a large enough size so that the background image completely covers the background area. Some parts of the image may not be displayed in the background area.</li><li><strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b1425512535366"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b1425512535366"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b1425512535366"></a>auto</strong>: The original image width-height ratio is retained.</li></ul>
</li><li>The two <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b13309145193614"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b13309145193614"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b13309145193614"></a>&lt;length&gt;</strong> values are as follows:<p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p1840244924418"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p1840244924418"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p1840244924418"></a>Width and height of the background image. The first value indicates the width, and the second value indicates the height. If you only set one value, the other value is set to <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b146661156143617"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b146661156143617"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b146661156143617"></a>auto</strong> by default.</p>
</li><li>The two <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b1667415763613"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b1667415763613"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b1667415763613"></a>&lt;percentage&gt;</strong> values are as follows:<p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p17936154410457"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p17936154410457"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p17936154410457"></a>Width and height of the background image in percentage of the parent element. The first value indicates the width, and the second value indicates the height. If you only set one value, the other value is set to <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b1524319254"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b1524319254"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b1524319254"></a>auto</strong> by default.</p>
</li></ul>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row105744416236"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a9957170386754fb5b648ba2114bd52d4"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a9957170386754fb5b648ba2114bd52d4"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a9957170386754fb5b648ba2114bd52d4"></a>background-repeat</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a155b4cc325e747279694d36c2fa69bcc"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a155b4cc325e747279694d36c2fa69bcc"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a155b4cc325e747279694d36c2fa69bcc"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a82029c0dc1d540cf994f690b451c48f4"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a82029c0dc1d540cf994f690b451c48f4"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a82029c0dc1d540cf994f690b451c48f4"></a>repeat</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p1673015702810"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p1673015702810"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p1673015702810"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_afb8e41c117884b368a0f1df348be8e54"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_afb8e41c117884b368a0f1df348be8e54"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_afb8e41c117884b368a0f1df348be8e54"></a>How a background image is repeatedly drawn. By default, a background image is repeated both horizontally and vertically.</p>
<a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ul8236153103612"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ul8236153103612"></a><ul id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ul8236153103612"><li><strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b1363463710"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b1363463710"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b1363463710"></a>repeat</strong>: Repeatedly draws images along the x-axis and y-axis at the same time.</li><li><strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b267416916377"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b267416916377"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b267416916377"></a>repeat-x</strong>: Repeatedly draws images along the x-axis.</li><li><strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b625561011379"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b625561011379"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b625561011379"></a>repeat-y</strong>: Repeatedly draws images along the y-axis.</li><li><strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b1122181133715"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b1122181133715"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b1122181133715"></a>no-repeat</strong>: The image is not drawn repeatedly.</li></ul>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row057194419232"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a709eb4a9fa87428897bebb4a98693df2"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a709eb4a9fa87428897bebb4a98693df2"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a709eb4a9fa87428897bebb4a98693df2"></a>background-position</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ul8874155216502"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ul8874155216502"></a><ul id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ul8874155216502"><li>string string</li><li>&lt;length&gt; &lt;length&gt;</li><li>&lt;percentage&gt; &lt;percentage&gt;</li></ul>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a6f8f5d1c92f447bd868a841ad1a33cb1"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a6f8f5d1c92f447bd868a841ad1a33cb1"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a6f8f5d1c92f447bd868a841ad1a33cb1"></a>0px 0px</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p173010720280"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p173010720280"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p173010720280"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ul1590812103363"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ul1590812103363"></a><ul id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ul1590812103363"><li>Using keywords: If only one keyword is specified, the other value is <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b5234102011540"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b5234102011540"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b5234102011540"></a>center</strong> by default. The two values define the horizontal position and vertical position, respectively.<a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ul1453531734716"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ul1453531734716"></a><ul id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ul1453531734716"><li><strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b0982111273712"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b0982111273712"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b0982111273712"></a>left</strong>: leftmost in the horizontal direction</li><li><strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b866713583912"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b866713583912"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b866713583912"></a>right</strong>: rightmost in the horizontal direction</li><li><strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b5886013193716"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b5886013193716"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b5886013193716"></a>top</strong>: top in the vertical direction</li><li><strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b84197142376"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b84197142376"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b84197142376"></a>bottom</strong>: bottom in the vertical direction</li><li><strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b14894114103710"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b14894114103710"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b14894114103710"></a>center</strong>: center position</li></ul>
</li></ul>
<a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ul10908121023615"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ul10908121023615"></a><ul id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ul10908121023615"><li>Using <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b11401615193715"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b11401615193715"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b11401615193715"></a>&lt;length&gt;</strong>: The first value indicates the horizontal position, and the second value indicates the vertical position. <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b1341381819379"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b1341381819379"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b1341381819379"></a>0 0</strong> indicates the upper left corner. The unit is pixel. If only one value is specified, the other one is <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b48671516183714"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b48671516183714"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b48671516183714"></a>50%</strong>.</li><li>Using <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b5492717163712"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b5492717163712"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b5492717163712"></a>&lt;percentage&gt;</strong>: The first value indicates the horizontal position, and the second value indicates the vertical position. <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b164741723183712"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b164741723183712"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b164741723183712"></a>0% 0%</strong> indicates the upper left corner. <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b64022245377"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b64022245377"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b64022245377"></a>100% 100%</strong> indicates the lower right corner. If only one value is specified, the other one is <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b7893424163718"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b7893424163718"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b7893424163718"></a>50%</strong>.</li><li>Using both <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b154811725193718"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b154811725193718"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b154811725193718"></a>&lt;percentage&gt;</strong> and <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b34834254377"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b34834254377"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b34834254377"></a>&lt;length&gt;</strong>.</li></ul>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row1259204418231"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p134581712103910"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p134581712103910"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p134581712103910"></a>opacity</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a45185999ae584676af4c36467c2ade8b"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a45185999ae584676af4c36467c2ade8b"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a45185999ae584676af4c36467c2ade8b"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a09ff20dda8e44794bca18c84f413d972"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a09ff20dda8e44794bca18c84f413d972"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a09ff20dda8e44794bca18c84f413d972"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p1873011722814"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p1873011722814"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p1873011722814"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p122515161139"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p122515161139"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p122515161139"></a>Transparency of an element. The value ranges from <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b1871715526385"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b1871715526385"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b1871715526385"></a>0</strong> to <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b177181452103815"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b177181452103815"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b177181452103815"></a>1</strong>. The value <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b13718155210380"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b13718155210380"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b13718155210380"></a>1</strong> means opaque, and <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b6718152103818"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b6718152103818"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b6718152103818"></a>0</strong> means completely transparent.</p>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row75984472312"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_aeda9e2f8d8344958bf4f43d429dcb55e"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_aeda9e2f8d8344958bf4f43d429dcb55e"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_aeda9e2f8d8344958bf4f43d429dcb55e"></a>display</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p1544115441446"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p1544115441446"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p1544115441446"></a>string</p>
<p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_aaaa164aa970b490fb048e5f260f1c661"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_aaaa164aa970b490fb048e5f260f1c661"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_aaaa164aa970b490fb048e5f260f1c661"></a></p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_aa5ce61466c9847dbb7f44852338d9006"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_aa5ce61466c9847dbb7f44852338d9006"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_aa5ce61466c9847dbb7f44852338d9006"></a>flex</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p167303762818"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p167303762818"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p167303762818"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p23704018414"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p23704018414"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p23704018414"></a>How and whether to display the box containing an element. Available values are as follows:</p>
<a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ul12227103394916"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ul12227103394916"></a><ul id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ul12227103394916"><li><strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b57468289377"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b57468289377"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b57468289377"></a>flex</strong>: flexible layout</li><li><strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b18887133293920"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b18887133293920"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b18887133293920"></a>none</strong>: The element is hidden.</li></ul>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row1060044172311"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_aa2ed1da39c8e4ad78829712734226ab9"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_aa2ed1da39c8e4ad78829712734226ab9"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_aa2ed1da39c8e4ad78829712734226ab9"></a>visibility</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p15475737486"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p15475737486"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p15475737486"></a>string</p>
<p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_aabfb0eb044194745af56c313f40e7781"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_aabfb0eb044194745af56c313f40e7781"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_aabfb0eb044194745af56c313f40e7781"></a></p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_acaca80d4ef9a4f0d87adf92cb2d1ff9a"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_acaca80d4ef9a4f0d87adf92cb2d1ff9a"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_acaca80d4ef9a4f0d87adf92cb2d1ff9a"></a>visible</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p57301471281"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p57301471281"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p57301471281"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p1568839154517"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p1568839154517"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p1568839154517"></a>Whether to display an element. Invisible borders occupy layout space. (To remove the borders, set the <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b15844103015378"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b15844103015378"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b15844103015378"></a>display</strong> attribute to <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b4845153013712"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b4845153013712"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b4845153013712"></a>none</strong>.) Available values are as follows:</p>
<a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ul751984164920"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ul751984164920"></a><ul id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ul751984164920"><li><strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b17429331133711"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b17429331133711"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b17429331133711"></a>visible</strong>: The element is visible.</li><li><strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b109191231193710"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b109191231193710"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b109191231193710"></a>hidden</strong>: The element is hidden but still takes up space.</li></ul>
<div class="note" id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_note4549524649"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_note4549524649"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_note4549524649"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p25499241642"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p25499241642"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p25499241642"></a>If both <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b719810016405"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b719810016405"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b719810016405"></a>visibility</strong> and <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b187052264018"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b187052264018"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b187052264018"></a>display</strong> are set, only <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b107788924011"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b107788924011"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b107788924011"></a>display</strong> takes effect.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row260114472318"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ad74a6a48aca7439e9344c18c26b4177e"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ad74a6a48aca7439e9344c18c26b4177e"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ad74a6a48aca7439e9344c18c26b4177e"></a>flex</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a2e6e5192a1534872be5fcfd9f83e3fdc"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a2e6e5192a1534872be5fcfd9f83e3fdc"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a2e6e5192a1534872be5fcfd9f83e3fdc"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a8512eda38e25410685be8a8992890257"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a8512eda38e25410685be8a8992890257"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a8512eda38e25410685be8a8992890257"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p1373057132812"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p1373057132812"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p1373057132812"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a11c317cdfa7d4066878d86c6b3bcbd82"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a11c317cdfa7d4066878d86c6b3bcbd82"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a11c317cdfa7d4066878d86c6b3bcbd82"></a>How to divide available space of the parent component for a child component.</p>
<p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p6968144051814"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p6968144051814"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p6968144051814"></a>You can set one, two<sup id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_sup894453017315"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_sup894453017315"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_sup894453017315"></a>5+</sup>, or three<sup id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_sup1255142393114"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_sup1255142393114"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_sup1255142393114"></a>5+</sup> values for this style.</p>
<p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p16733313171911"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p16733313171911"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p16733313171911"></a>Set one value in either of the following ways:</p>
<a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ul93371539192211"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ul93371539192211"></a><ul id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ul93371539192211"><li>A unitless number to set <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b152581117781"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b152581117781"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b152581117781"></a>flex-grow</strong>.</li><li>A valid width value<sup id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_sup133014373318"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_sup133014373318"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_sup133014373318"></a>5+</sup> to set <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b182101331199"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b182101331199"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b182101331199"></a>flex-basis</strong>.</li></ul>
<p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p6786171632018"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p6786171632018"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p6786171632018"></a>Set two values<sup id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_sup39514502313"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_sup39514502313"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_sup39514502313"></a>5+</sup> in the following ways:</p>
<p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p6400429122011"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p6400429122011"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p6400429122011"></a>The first value must be a unitless number used to set <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b171516283129"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b171516283129"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b171516283129"></a>flex-grow</strong>. The second value must be either of the following:</p>
<a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ul767043502219"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ul767043502219"></a><ul id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ul767043502219"><li>A unitless number to set <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b1428375141313"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b1428375141313"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b1428375141313"></a>flex-shrink</strong>.</li><li>A valid width value to set <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b1632495651416"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b1632495651416"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b1632495651416"></a>flex-basis</strong>.</li></ul>
<p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p748416351217"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p748416351217"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p748416351217"></a>Set three values<sup id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_sup168671312151514"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_sup168671312151514"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_sup168671312151514"></a>5+</sup> in the following ways:</p>
<p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p7373204832111"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p7373204832111"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p7373204832111"></a>The first value must be a unitless number used to set <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b19419131221612"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b19419131221612"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b19419131221612"></a>flex-grow</strong>. The second value must be a unitless number used to set <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b19378733181612"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b19378733181612"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b19378733181612"></a>flex-shrink</strong>. The third value must be a valid width value used to set <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b47717118176"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b47717118176"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b47717118176"></a>flex-basis</strong>.</p>
<div class="note" id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_note34891253201520"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_note34891253201520"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_note34891253201520"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p1248915538152"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p1248915538152"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p1248915538152"></a>This style takes effect only when the container is any of the following components: <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b17156153131"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b17156153131"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b17156153131"></a>&lt;div&gt;</strong>, <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b1201415151311"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b1201415151311"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b1201415151311"></a>&lt;list-item&gt;</strong>, <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b72031515132"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b72031515132"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b72031515132"></a>&lt;refresh&gt;</strong>, <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b1920131551310"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b1920131551310"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b1920131551310"></a>&lt;stepper-item&gt;</strong><sup id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_sup17201815121317"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_sup17201815121317"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_sup17201815121317"></a>5+</sup>, and <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b2211915121313"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b2211915121313"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b2211915121313"></a>&lt;tabs&gt;</strong>.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row1161174412318"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a5d88cacaaf5c4f6a87390ab916b695c6"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a5d88cacaaf5c4f6a87390ab916b695c6"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a5d88cacaaf5c4f6a87390ab916b695c6"></a>flex-grow</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a2c379e3af283446da446f1631e572efd"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a2c379e3af283446da446f1631e572efd"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a2c379e3af283446da446f1631e572efd"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_aa374f6c7415a4ee48a06930d76c55be7"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_aa374f6c7415a4ee48a06930d76c55be7"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_aa374f6c7415a4ee48a06930d76c55be7"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001059148552_p461154472318"><a name="en-us_topic_0000001059148552_p461154472318"></a><a name="en-us_topic_0000001059148552_p461154472318"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p4437122419557"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p4437122419557"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p4437122419557"></a>How much a child component will grow. The value specifies allocation of the remaining space on the main axis of the parent component. Size of available space = Container size - Total size of all child components. Value <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b1682343583716"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b1682343583716"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b1682343583716"></a>0</strong> indicates that the child component does not grow.</p>
<div class="note" id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_note201231734212"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_note201231734212"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_note201231734212"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p184555314553"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p184555314553"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p184555314553"></a>This style takes effect only when the container is any of the following components: <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b18575165615499"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b18575165615499"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b18575165615499"></a>&lt;div&gt;</strong>, <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b8575165618495"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b8575165618495"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b8575165618495"></a>&lt;list-item&gt;</strong>, <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b125751756164917"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b125751756164917"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b125751756164917"></a>&lt;refresh&gt;</strong>, <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b15751456104920"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b15751456104920"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b15751456104920"></a>&lt;stepper-item&gt;</strong><sup id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_sup257595611492"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_sup257595611492"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_sup257595611492"></a>5+</sup>, and <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b55761856114912"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b55761856114912"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b55761856114912"></a>&lt;tabs&gt;</strong>.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row146184419238"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ac65ef7e2b1f24a13b09c495f643168c9"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ac65ef7e2b1f24a13b09c495f643168c9"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ac65ef7e2b1f24a13b09c495f643168c9"></a>flex-shrink</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a98e7d367f0e649699892ae5bad6ade37"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a98e7d367f0e649699892ae5bad6ade37"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a98e7d367f0e649699892ae5bad6ade37"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a422d978368814d12a33201cb839060ee"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a422d978368814d12a33201cb839060ee"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a422d978368814d12a33201cb839060ee"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001059148552_p6629442237"><a name="en-us_topic_0000001059148552_p6629442237"></a><a name="en-us_topic_0000001059148552_p6629442237"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ab032342dfe56460ca742800de482ca0f"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ab032342dfe56460ca742800de482ca0f"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ab032342dfe56460ca742800de482ca0f"></a>How much a child component will shrink. The shrink occurs only when the sum of default child component widths is greater than that of the parent component. Value <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b783242395"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b783242395"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b783242395"></a>0</strong> indicates that the child component does not shrink.</p>
<div class="note" id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_note147160917217"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_note147160917217"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_note147160917217"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p844914328577"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p844914328577"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p844914328577"></a>This style takes effect only when the container is any of the following components: <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b1168212543127"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b1168212543127"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b1168212543127"></a>&lt;div&gt;</strong>, <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b76821454121211"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b76821454121211"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b76821454121211"></a>&lt;list-item&gt;</strong>, <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b1168255411126"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b1168255411126"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b1168255411126"></a>&lt;refresh&gt;</strong>, <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b10682155415120"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b10682155415120"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b10682155415120"></a>&lt;stepper-item&gt;</strong><sup id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_sup10683145491215"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_sup10683145491215"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_sup10683145491215"></a>5+</sup>, and <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b1868385461211"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b1868385461211"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b1868385461211"></a>&lt;tabs&gt;</strong>.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row56212444236"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a82c323a994634032963169eeee1a55e4"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a82c323a994634032963169eeee1a55e4"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a82c323a994634032963169eeee1a55e4"></a>flex-basis</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p1148910787"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p1148910787"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p1148910787"></a>&lt;length&gt;</p>
<p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a43613cf0c2184c0d8b44e8d292f6edb7"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a43613cf0c2184c0d8b44e8d292f6edb7"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a43613cf0c2184c0d8b44e8d292f6edb7"></a></p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ab9e1c7dc25f840e58993af05c1d32109"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ab9e1c7dc25f840e58993af05c1d32109"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ab9e1c7dc25f840e58993af05c1d32109"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001059148552_p16621944152310"><a name="en-us_topic_0000001059148552_p16621944152310"></a><a name="en-us_topic_0000001059148552_p16621944152310"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a0993ef9b0ef64785a76e6310dd834f09"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a0993ef9b0ef64785a76e6310dd834f09"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a0993ef9b0ef64785a76e6310dd834f09"></a>Initial length of the flex item on the main axis.</p>
<div class="note" id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_note62848141222"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_note62848141222"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_note62848141222"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p16711745115718"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p16711745115718"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p16711745115718"></a>This style takes effect only when the container is any of the following components: <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b18795155631219"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b18795155631219"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b18795155631219"></a>&lt;div&gt;</strong>, <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b107951056121217"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b107951056121217"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b107951056121217"></a>&lt;list-item&gt;</strong>, <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b2795105619128"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b2795105619128"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b2795105619128"></a>&lt;refresh&gt;</strong>, <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b1579510564126"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b1579510564126"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b1579510564126"></a>&lt;stepper-item&gt;</strong><sup id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_sup187953565122"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_sup187953565122"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_sup187953565122"></a>5+</sup>, and <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b11796456201211"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b11796456201211"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b11796456201211"></a>&lt;tabs&gt;</strong>.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row1621844162310"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a50180d720a374549ae72c848e53320cb"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a50180d720a374549ae72c848e53320cb"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a50180d720a374549ae72c848e53320cb"></a>position</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a63672ed9a4c040f7a6ec9c8089b79bb6"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a63672ed9a4c040f7a6ec9c8089b79bb6"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a63672ed9a4c040f7a6ec9c8089b79bb6"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a2666820c71eb420485e4d20e55b4eabe"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a2666820c71eb420485e4d20e55b4eabe"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a2666820c71eb420485e4d20e55b4eabe"></a>relative</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p1173107172814"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p1173107172814"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p1173107172814"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ae28abf4e47a740efbd45a8f280577912"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ae28abf4e47a740efbd45a8f280577912"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ae28abf4e47a740efbd45a8f280577912"></a>Positioning type of an element. Dynamic changes are not supported.</p>
<a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ul17185232185014"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ul17185232185014"></a><ul id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ul17185232185014"><li><strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b1894911155394"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b1894911155394"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b1894911155394"></a>fixed</strong>: The element is positioned related to the browser window.</li><li><strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b823115152390"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b823115152390"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b823115152390"></a>absolute</strong>: The element is positioned absolutely to its parent element.</li><li><strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b736151417395"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b736151417395"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b736151417395"></a>relative</strong>: The element is positioned relative to its normal position.</li></ul>
<div class="note" id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_note167617191219"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_note167617191219"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_note167617191219"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p1839092815101"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p1839092815101"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p1839092815101"></a>The <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b13941713133910"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b13941713133910"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b13941713133910"></a>absolute</strong> attribute takes effect only when the parent component is <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b1099913173916"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b1099913173916"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b1099913173916"></a>&lt;div&gt;</strong> or <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b181001413123919"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b181001413123919"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b181001413123919"></a>&lt;stack&gt;</strong>.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000001059148552_row4631644172319"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a70405cb9696b4329ac7625af93310018"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a70405cb9696b4329ac7625af93310018"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a70405cb9696b4329ac7625af93310018"></a>[left|top<span id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ph14927143614712"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ph14927143614712"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ph14927143614712"></a>|right|bottom</span>]</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p1849062221214"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p1849062221214"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p1849062221214"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a579ac7c03d1d46758ebaacd565d86ed3"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a579ac7c03d1d46758ebaacd565d86ed3"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a579ac7c03d1d46758ebaacd565d86ed3"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p187314719288"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p187314719288"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_p187314719288"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a9a662a62cd9b40eaa0cb9ca082b6d1c2"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a9a662a62cd9b40eaa0cb9ca082b6d1c2"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_a9a662a62cd9b40eaa0cb9ca082b6d1c2"></a><strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b481348173914"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b481348173914"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b481348173914"></a>left|top</strong><span id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ph4818118173914"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ph4818118173914"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ph4818118173914"></a><strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b68143833912"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b68143833912"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b68143833912"></a>|right|bottom</strong></span> must be used together with <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b881916818394"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b881916818394"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b881916818394"></a>position</strong> to determine the offset position of an element.</p>
<a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ul12671003525"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ul12671003525"></a><ul id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_ul12671003525"><li>The <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b885117712398"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b885117712398"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b885117712398"></a>left</strong> attribute specifies the left edge position of the element. This attribute defines the offset between the left edge of a positioned element and that of a block included in the element.</li><li>The <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b65591759395"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b65591759395"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b65591759395"></a>top</strong> attribute specifies the top edge position of the element. This attribute defines the offset between the top edge of a positioned element and that of a block included in the element.</li><li>The <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b179013323910"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b179013323910"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b179013323910"></a>right</strong> attribute specifies the right edge position of the element. This attribute defines the offset between the right edge of a positioned element and that of a block included in the element. </li><li>The <strong id="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b77091602397"><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b77091602397"></a><a name="en-us_topic_0000001059148552_en-us_topic_0000001059340528_b77091602397"></a>bottom</strong> attribute specifies the bottom edge position of the element. This attribute defines the offset between the bottom edge of a positioned element and that of a block included in the element. </li></ul>
</td>
</tr>
</tbody>
</table>

## Example Code<a name="en-us_topic_0000001059148552_section164885329456"></a>

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

    ![](figures/en-us_image_0000001059148590.png)

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

    ![](figures/barchart.png)

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

    ![](figures/gauge.png)


