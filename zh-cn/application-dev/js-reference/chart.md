# chart<a name="ZH-CN_TOPIC_0000001115974738"></a>

-   [权限列表](#zh-cn_topic_0000001059148552_section11257113618419)
-   [子组件](#zh-cn_topic_0000001059148552_section9288143101012)
-   [属性](#zh-cn_topic_0000001059148552_section2907183951110)
-   [方法](#zh-cn_topic_0000001059148552_section5955645132417)
-   [事件](#zh-cn_topic_0000001059148552_section749131815264)
-   [样式](#zh-cn_topic_0000001059148552_section5775351116)
-   [示例](#zh-cn_topic_0000001059148552_section164885329456)

图表组件，用于呈现线形图、柱状图、量规图界面。

## 权限列表<a name="zh-cn_topic_0000001059148552_section11257113618419"></a>

无

## 子组件<a name="zh-cn_topic_0000001059148552_section9288143101012"></a>

不支持。

## 属性<a name="zh-cn_topic_0000001059148552_section2907183951110"></a>

<a name="zh-cn_topic_0000001059148552_table20633101642315"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001059148552_row663331618238"><th class="cellrowborder" valign="top" width="16.86%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_a9ba8c579217b4b8b841b035f1d28b20e"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_a9ba8c579217b4b8b841b035f1d28b20e"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_a9ba8c579217b4b8b841b035f1d28b20e"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="16.24%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_a633002333b024497914a4b172446f14e"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_a633002333b024497914a4b172446f14e"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_a633002333b024497914a4b172446f14e"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="10.8%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_a4950f7884c6540b9ad523ac34657d952"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_a4950f7884c6540b9ad523ac34657d952"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_a4950f7884c6540b9ad523ac34657d952"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="8.43%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001059148552_p824610360217"><a name="zh-cn_topic_0000001059148552_p824610360217"></a><a name="zh-cn_topic_0000001059148552_p824610360217"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="47.67%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_a1313564aa9404a338447087d5918c17d"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_a1313564aa9404a338447087d5918c17d"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_a1313564aa9404a338447087d5918c17d"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001059148552_row176434366222"><td class="cellrowborder" valign="top" width="16.86%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001059148552_p157531437142216"><a name="zh-cn_topic_0000001059148552_p157531437142216"></a><a name="zh-cn_topic_0000001059148552_p157531437142216"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="16.24%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001059148552_p975314374228"><a name="zh-cn_topic_0000001059148552_p975314374228"></a><a name="zh-cn_topic_0000001059148552_p975314374228"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001059148552_p2753113711229"><a name="zh-cn_topic_0000001059148552_p2753113711229"></a><a name="zh-cn_topic_0000001059148552_p2753113711229"></a>line</p>
</td>
<td class="cellrowborder" valign="top" width="8.43%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001059148552_p117532375222"><a name="zh-cn_topic_0000001059148552_p117532375222"></a><a name="zh-cn_topic_0000001059148552_p117532375222"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.67%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001059148552_p12753143712225"><a name="zh-cn_topic_0000001059148552_p12753143712225"></a><a name="zh-cn_topic_0000001059148552_p12753143712225"></a>设置图表类型（不支持动态修改），可选项有：</p>
<a name="zh-cn_topic_0000001059148552_ul2754143714229"></a><a name="zh-cn_topic_0000001059148552_ul2754143714229"></a><ul id="zh-cn_topic_0000001059148552_ul2754143714229"><li>bar：柱状图。</li><li>line：线形图。</li><li>gauge：量规图。</li><li>progress<sup id="zh-cn_topic_0000001059148552_sup116561549162915"><a name="zh-cn_topic_0000001059148552_sup116561549162915"></a><a name="zh-cn_topic_0000001059148552_sup116561549162915"></a><span>5+</span></sup>：进度类圆形图表。</li><li>loading<sup id="zh-cn_topic_0000001059148552_sup1246145116541"><a name="zh-cn_topic_0000001059148552_sup1246145116541"></a><a name="zh-cn_topic_0000001059148552_sup1246145116541"></a><span>5+</span></sup>：加载类圆形图表。</li><li>rainbow<sup id="zh-cn_topic_0000001059148552_sup13727185218542"><a name="zh-cn_topic_0000001059148552_sup13727185218542"></a><a name="zh-cn_topic_0000001059148552_sup13727185218542"></a><span>5+</span></sup>：占比类圆形图表。</li></ul>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row38691133172215"><td class="cellrowborder" valign="top" width="16.86%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001059148552_p4754173712219"><a name="zh-cn_topic_0000001059148552_p4754173712219"></a><a name="zh-cn_topic_0000001059148552_p4754173712219"></a>options</p>
</td>
<td class="cellrowborder" valign="top" width="16.24%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001059148552_p1675423715225"><a name="zh-cn_topic_0000001059148552_p1675423715225"></a><a name="zh-cn_topic_0000001059148552_p1675423715225"></a><a href="#zh-cn_topic_0000001059148552_table12775365017">ChartOptions</a></p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001059148552_p27541437112214"><a name="zh-cn_topic_0000001059148552_p27541437112214"></a><a name="zh-cn_topic_0000001059148552_p27541437112214"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.43%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001059148552_p1475493712214"><a name="zh-cn_topic_0000001059148552_p1475493712214"></a><a name="zh-cn_topic_0000001059148552_p1475493712214"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.67%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001059148552_p19754143732218"><a name="zh-cn_topic_0000001059148552_p19754143732218"></a><a name="zh-cn_topic_0000001059148552_p19754143732218"></a>图表参数设置，柱状图和线形图必须设置参数设置，量规图不生效。可以设置x轴、y轴的最小值、最大值、刻度数、是否显示，线条宽度、是否平滑等。（不支持动态修改）</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row1541629182218"><td class="cellrowborder" valign="top" width="16.86%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001059148552_p57547371229"><a name="zh-cn_topic_0000001059148552_p57547371229"></a><a name="zh-cn_topic_0000001059148552_p57547371229"></a>datasets</p>
</td>
<td class="cellrowborder" valign="top" width="16.24%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001059148552_p117541437172215"><a name="zh-cn_topic_0000001059148552_p117541437172215"></a><a name="zh-cn_topic_0000001059148552_p117541437172215"></a>Array&lt;<a href="#zh-cn_topic_0000001059148552_table13810518157">ChartDataset</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001059148552_p7754203711221"><a name="zh-cn_topic_0000001059148552_p7754203711221"></a><a name="zh-cn_topic_0000001059148552_p7754203711221"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.43%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001059148552_p18754183732216"><a name="zh-cn_topic_0000001059148552_p18754183732216"></a><a name="zh-cn_topic_0000001059148552_p18754183732216"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.67%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001059148552_p775483772214"><a name="zh-cn_topic_0000001059148552_p775483772214"></a><a name="zh-cn_topic_0000001059148552_p775483772214"></a>数据集合，柱状图和线形图必须设置数据集合，量规图不生效。可以设置多条数据集及其背景色。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row28045213017"><td class="cellrowborder" valign="top" width="16.86%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001059148552_p18811552104"><a name="zh-cn_topic_0000001059148552_p18811552104"></a><a name="zh-cn_topic_0000001059148552_p18811552104"></a>segments<sup id="zh-cn_topic_0000001059148552_sup567222913217"><a name="zh-cn_topic_0000001059148552_sup567222913217"></a><a name="zh-cn_topic_0000001059148552_sup567222913217"></a><span>5+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="16.24%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001059148552_p481105219011"><a name="zh-cn_topic_0000001059148552_p481105219011"></a><a name="zh-cn_topic_0000001059148552_p481105219011"></a><a href="#zh-cn_topic_0000001059148552_table2596183616210">DataSegment</a> | Array&lt;<a href="#zh-cn_topic_0000001059148552_table2596183616210">DataSegment</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001059148552_p188135220013"><a name="zh-cn_topic_0000001059148552_p188135220013"></a><a name="zh-cn_topic_0000001059148552_p188135220013"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.43%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001059148552_p78112529019"><a name="zh-cn_topic_0000001059148552_p78112529019"></a><a name="zh-cn_topic_0000001059148552_p78112529019"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.67%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001059148552_p1455632813277"><a name="zh-cn_topic_0000001059148552_p1455632813277"></a><a name="zh-cn_topic_0000001059148552_p1455632813277"></a>进度类、加载类和占比类圆形图表使用的数据结构。</p>
<p id="zh-cn_topic_0000001059148552_p19327195813510"><a name="zh-cn_topic_0000001059148552_p19327195813510"></a><a name="zh-cn_topic_0000001059148552_p19327195813510"></a>DataSegment针对进度类和加载类圆形图表使用，</p>
<p id="zh-cn_topic_0000001059148552_p14326258457"><a name="zh-cn_topic_0000001059148552_p14326258457"></a><a name="zh-cn_topic_0000001059148552_p14326258457"></a>Array&lt;<a href="#zh-cn_topic_0000001059148552_table2596183616210">DataSegment</a>&gt;针对占比类图标使用，DataSegment最多9个。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row132072752211"><td class="cellrowborder" valign="top" width="16.86%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001059148552_p1720712712227"><a name="zh-cn_topic_0000001059148552_p1720712712227"></a><a name="zh-cn_topic_0000001059148552_p1720712712227"></a>effects<sup id="zh-cn_topic_0000001059148552_sup98541850278"><a name="zh-cn_topic_0000001059148552_sup98541850278"></a><a name="zh-cn_topic_0000001059148552_sup98541850278"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="16.24%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001059148552_p520815752212"><a name="zh-cn_topic_0000001059148552_p520815752212"></a><a name="zh-cn_topic_0000001059148552_p520815752212"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001059148552_p220877132211"><a name="zh-cn_topic_0000001059148552_p220877132211"></a><a name="zh-cn_topic_0000001059148552_p220877132211"></a>true</p>
</td>
<td class="cellrowborder" valign="top" width="8.43%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001059148552_p1820820719229"><a name="zh-cn_topic_0000001059148552_p1820820719229"></a><a name="zh-cn_topic_0000001059148552_p1820820719229"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.67%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001059148552_p92085712225"><a name="zh-cn_topic_0000001059148552_p92085712225"></a><a name="zh-cn_topic_0000001059148552_p92085712225"></a>是否开启占比类、进度类圆形图表特效。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row36332165231"><td class="cellrowborder" valign="top" width="16.86%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_adb8a73146d764f2aab50fc046169ab26"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_adb8a73146d764f2aab50fc046169ab26"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_adb8a73146d764f2aab50fc046169ab26"></a>id</p>
</td>
<td class="cellrowborder" valign="top" width="16.24%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_a06898db2627246f78e85d4fbadeee85c"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_a06898db2627246f78e85d4fbadeee85c"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_a06898db2627246f78e85d4fbadeee85c"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_ae685ead324a647bcba1bbb45c9402dd6"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_ae685ead324a647bcba1bbb45c9402dd6"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_ae685ead324a647bcba1bbb45c9402dd6"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.43%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001059148552_p42461736102118"><a name="zh-cn_topic_0000001059148552_p42461736102118"></a><a name="zh-cn_topic_0000001059148552_p42461736102118"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.67%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_a692121725a9b4ebbae65cd22b94b672e"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_a692121725a9b4ebbae65cd22b94b672e"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_a692121725a9b4ebbae65cd22b94b672e"></a>组件的唯一标识。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row13633131616239"><td class="cellrowborder" valign="top" width="16.86%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_a7c032d302e1d437eac59680e066308b0"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_a7c032d302e1d437eac59680e066308b0"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_a7c032d302e1d437eac59680e066308b0"></a>style</p>
</td>
<td class="cellrowborder" valign="top" width="16.24%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_a6ba72f5c52df4fba9b02b5dffa26677e"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_a6ba72f5c52df4fba9b02b5dffa26677e"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_a6ba72f5c52df4fba9b02b5dffa26677e"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_a23cec1f95fd04ff1b3b20f58844ea654"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_a23cec1f95fd04ff1b3b20f58844ea654"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_a23cec1f95fd04ff1b3b20f58844ea654"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.43%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001059148552_p17246836142119"><a name="zh-cn_topic_0000001059148552_p17246836142119"></a><a name="zh-cn_topic_0000001059148552_p17246836142119"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.67%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_ab9c92d331da44a0e9114f6760340680a"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_ab9c92d331da44a0e9114f6760340680a"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_ab9c92d331da44a0e9114f6760340680a"></a>组件的样式声明。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row10634131610230"><td class="cellrowborder" valign="top" width="16.86%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_a3e97d6d2a5b84e06bf619049840a00a8"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_a3e97d6d2a5b84e06bf619049840a00a8"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_a3e97d6d2a5b84e06bf619049840a00a8"></a>class</p>
</td>
<td class="cellrowborder" valign="top" width="16.24%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_af0974175e9434735b035a4db9146aa04"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_af0974175e9434735b035a4db9146aa04"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_af0974175e9434735b035a4db9146aa04"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_aa5caace6225b440eba13dc2230f3ef0f"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_aa5caace6225b440eba13dc2230f3ef0f"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_aa5caace6225b440eba13dc2230f3ef0f"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.43%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001059148552_p324614367213"><a name="zh-cn_topic_0000001059148552_p324614367213"></a><a name="zh-cn_topic_0000001059148552_p324614367213"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.67%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_a2f6321cf45ae481983a88dcc2f900900"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_a2f6321cf45ae481983a88dcc2f900900"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_a2f6321cf45ae481983a88dcc2f900900"></a>组件的样式类，用于引用样式表。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row1634171618236"><td class="cellrowborder" valign="top" width="16.86%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_p1786251117156"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_p1786251117156"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_p1786251117156"></a>ref</p>
</td>
<td class="cellrowborder" valign="top" width="16.24%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_p1086241119157"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_p1086241119157"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_p1086241119157"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_p586281111151"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_p586281111151"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_p586281111151"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.43%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001059148552_p1624612362219"><a name="zh-cn_topic_0000001059148552_p1624612362219"></a><a name="zh-cn_topic_0000001059148552_p1624612362219"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.67%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_p113416153342"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_p113416153342"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_p113416153342"></a>用来指定指向子元素<span id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_ph56099211134"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_ph56099211134"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_ph56099211134"></a>或子组件</span>的引用信息，该引用将注册到父组件的$refs 属性对象上。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row1863421642313"><td class="cellrowborder" valign="top" width="16.86%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_ab8d3c8007e0a42b9962e0db009e7be9d"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_ab8d3c8007e0a42b9962e0db009e7be9d"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_ab8d3c8007e0a42b9962e0db009e7be9d"></a>disabled</p>
</td>
<td class="cellrowborder" valign="top" width="16.24%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_a05782d6a1a5d42918bc95813dca610d6"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_a05782d6a1a5d42918bc95813dca610d6"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_a05782d6a1a5d42918bc95813dca610d6"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_a3e2f721f63a74e4b974e9bd5e2f88994"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_a3e2f721f63a74e4b974e9bd5e2f88994"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_a3e2f721f63a74e4b974e9bd5e2f88994"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="8.43%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001059148552_p192476368214"><a name="zh-cn_topic_0000001059148552_p192476368214"></a><a name="zh-cn_topic_0000001059148552_p192476368214"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.67%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_a4065980a1e914cf98acce5250ee4ae5a"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_a4065980a1e914cf98acce5250ee4ae5a"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_a4065980a1e914cf98acce5250ee4ae5a"></a>当前组件是否被禁用，在禁用场景下，组件将无法响应用户交互。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row1263451617236"><td class="cellrowborder" valign="top" width="16.86%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_a751c9d46a62348ec902c7fdf97468b9d"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_a751c9d46a62348ec902c7fdf97468b9d"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_a751c9d46a62348ec902c7fdf97468b9d"></a>data</p>
</td>
<td class="cellrowborder" valign="top" width="16.24%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_a8e6d1bb4d0bc423fb8466ee3acd1882f"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_a8e6d1bb4d0bc423fb8466ee3acd1882f"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_a8e6d1bb4d0bc423fb8466ee3acd1882f"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_ab8cb15c9c3444b13b64945788131dce6"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_ab8cb15c9c3444b13b64945788131dce6"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_ab8cb15c9c3444b13b64945788131dce6"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.43%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001059148552_p22471736132114"><a name="zh-cn_topic_0000001059148552_p22471736132114"></a><a name="zh-cn_topic_0000001059148552_p22471736132114"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.67%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_aa3f56a32296b4e85bcda2d2c00d0884f"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_aa3f56a32296b4e85bcda2d2c00d0884f"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058340523_aa3f56a32296b4e85bcda2d2c00d0884f"></a>给当前组件设置data属性，进行相应的数据存储和读取。</p>
</td>
</tr>
</tbody>
</table>

**表 1**  ChartOptions

<a name="zh-cn_topic_0000001059148552_table12775365017"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001059148552_row6277153195013"><th class="cellrowborder" valign="top" width="16.3%" id="mcps1.2.6.1.1"><p id="zh-cn_topic_0000001059148552_p1192913820507"><a name="zh-cn_topic_0000001059148552_p1192913820507"></a><a name="zh-cn_topic_0000001059148552_p1192913820507"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="11.24%" id="mcps1.2.6.1.2"><p id="zh-cn_topic_0000001059148552_p2929188125011"><a name="zh-cn_topic_0000001059148552_p2929188125011"></a><a name="zh-cn_topic_0000001059148552_p2929188125011"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="8.690000000000001%" id="mcps1.2.6.1.3"><p id="zh-cn_topic_0000001059148552_p6929688508"><a name="zh-cn_topic_0000001059148552_p6929688508"></a><a name="zh-cn_topic_0000001059148552_p6929688508"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.7299999999999995%" id="mcps1.2.6.1.4"><p id="zh-cn_topic_0000001059148552_p1392938165014"><a name="zh-cn_topic_0000001059148552_p1392938165014"></a><a name="zh-cn_topic_0000001059148552_p1392938165014"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="56.04%" id="mcps1.2.6.1.5"><p id="zh-cn_topic_0000001059148552_p2092914815016"><a name="zh-cn_topic_0000001059148552_p2092914815016"></a><a name="zh-cn_topic_0000001059148552_p2092914815016"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001059148552_row2277638503"><td class="cellrowborder" valign="top" width="16.3%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001059148552_p127818375011"><a name="zh-cn_topic_0000001059148552_p127818375011"></a><a name="zh-cn_topic_0000001059148552_p127818375011"></a>xAxis</p>
</td>
<td class="cellrowborder" valign="top" width="11.24%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001059148552_p18278183115020"><a name="zh-cn_topic_0000001059148552_p18278183115020"></a><a name="zh-cn_topic_0000001059148552_p18278183115020"></a><a href="#zh-cn_topic_0000001059148552_table11312112919528">ChartAxis</a></p>
</td>
<td class="cellrowborder" valign="top" width="8.690000000000001%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001059148552_p1327817316507"><a name="zh-cn_topic_0000001059148552_p1327817316507"></a><a name="zh-cn_topic_0000001059148552_p1327817316507"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.7299999999999995%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001059148552_p427813385011"><a name="zh-cn_topic_0000001059148552_p427813385011"></a><a name="zh-cn_topic_0000001059148552_p427813385011"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="56.04%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001059148552_p1795144819490"><a name="zh-cn_topic_0000001059148552_p1795144819490"></a><a name="zh-cn_topic_0000001059148552_p1795144819490"></a>x轴参数设置。可以设置x轴最小值、最大值、刻度数以及是否显示。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row14660105412507"><td class="cellrowborder" valign="top" width="16.3%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001059148552_p16611654205018"><a name="zh-cn_topic_0000001059148552_p16611654205018"></a><a name="zh-cn_topic_0000001059148552_p16611654205018"></a>yAxis</p>
</td>
<td class="cellrowborder" valign="top" width="11.24%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001059148552_p1518631821017"><a name="zh-cn_topic_0000001059148552_p1518631821017"></a><a name="zh-cn_topic_0000001059148552_p1518631821017"></a><a href="#zh-cn_topic_0000001059148552_table11312112919528">ChartAxis</a></p>
</td>
<td class="cellrowborder" valign="top" width="8.690000000000001%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001059148552_p19661554145015"><a name="zh-cn_topic_0000001059148552_p19661554145015"></a><a name="zh-cn_topic_0000001059148552_p19661554145015"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.7299999999999995%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001059148552_p466145416502"><a name="zh-cn_topic_0000001059148552_p466145416502"></a><a name="zh-cn_topic_0000001059148552_p466145416502"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="56.04%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001059148552_p14661554125010"><a name="zh-cn_topic_0000001059148552_p14661554125010"></a><a name="zh-cn_topic_0000001059148552_p14661554125010"></a>y轴参数设置。可以设置y轴最小值、最大值、刻度数以及是否显示。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row1816015565013"><td class="cellrowborder" valign="top" width="16.3%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001059148552_p1816005585019"><a name="zh-cn_topic_0000001059148552_p1816005585019"></a><a name="zh-cn_topic_0000001059148552_p1816005585019"></a>series</p>
</td>
<td class="cellrowborder" valign="top" width="11.24%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001059148552_p91601455135019"><a name="zh-cn_topic_0000001059148552_p91601455135019"></a><a name="zh-cn_topic_0000001059148552_p91601455135019"></a><a href="#zh-cn_topic_0000001059148552_table029562010560">ChartSeries</a></p>
</td>
<td class="cellrowborder" valign="top" width="8.690000000000001%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001059148552_p416015565016"><a name="zh-cn_topic_0000001059148552_p416015565016"></a><a name="zh-cn_topic_0000001059148552_p416015565016"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.7299999999999995%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001059148552_p12160135565014"><a name="zh-cn_topic_0000001059148552_p12160135565014"></a><a name="zh-cn_topic_0000001059148552_p12160135565014"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="56.04%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001059148552_p1916095511501"><a name="zh-cn_topic_0000001059148552_p1916095511501"></a><a name="zh-cn_topic_0000001059148552_p1916095511501"></a>数据序列参数设置。可以设置1）线的样式，如线宽、是否平滑；2）设置线最前端位置白点的样式和大小。</p>
<div class="note" id="zh-cn_topic_0000001059148552_note163611718126"><a name="zh-cn_topic_0000001059148552_note163611718126"></a><a name="zh-cn_topic_0000001059148552_note163611718126"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001059148552_p15361117191211"><a name="zh-cn_topic_0000001059148552_p15361117191211"></a><a name="zh-cn_topic_0000001059148552_p15361117191211"></a>仅线形图支持。</p>
</div></div>
</td>
</tr>
</tbody>
</table>

**表 2**  ChartDataset

<a name="zh-cn_topic_0000001059148552_table13810518157"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001059148552_row1839105121514"><th class="cellrowborder" valign="top" width="16.56%" id="mcps1.2.6.1.1"><p id="zh-cn_topic_0000001059148552_p106956431614"><a name="zh-cn_topic_0000001059148552_p106956431614"></a><a name="zh-cn_topic_0000001059148552_p106956431614"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="16.830000000000002%" id="mcps1.2.6.1.2"><p id="zh-cn_topic_0000001059148552_p0695204111617"><a name="zh-cn_topic_0000001059148552_p0695204111617"></a><a name="zh-cn_topic_0000001059148552_p0695204111617"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="12.989999999999998%" id="mcps1.2.6.1.3"><p id="zh-cn_topic_0000001059148552_p1069514141614"><a name="zh-cn_topic_0000001059148552_p1069514141614"></a><a name="zh-cn_topic_0000001059148552_p1069514141614"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="9.33%" id="mcps1.2.6.1.4"><p id="zh-cn_topic_0000001059148552_p969564191616"><a name="zh-cn_topic_0000001059148552_p969564191616"></a><a name="zh-cn_topic_0000001059148552_p969564191616"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="44.29%" id="mcps1.2.6.1.5"><p id="zh-cn_topic_0000001059148552_p1169616441615"><a name="zh-cn_topic_0000001059148552_p1169616441615"></a><a name="zh-cn_topic_0000001059148552_p1169616441615"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001059148552_row1383242819553"><td class="cellrowborder" valign="top" width="16.56%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001059148552_p13832192819557"><a name="zh-cn_topic_0000001059148552_p13832192819557"></a><a name="zh-cn_topic_0000001059148552_p13832192819557"></a>strokeColor</p>
</td>
<td class="cellrowborder" valign="top" width="16.830000000000002%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001059148552_p18321928145512"><a name="zh-cn_topic_0000001059148552_p18321928145512"></a><a name="zh-cn_topic_0000001059148552_p18321928145512"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="12.989999999999998%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001059148552_p1283202816559"><a name="zh-cn_topic_0000001059148552_p1283202816559"></a><a name="zh-cn_topic_0000001059148552_p1283202816559"></a>#ff6384</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001059148552_p128322028155519"><a name="zh-cn_topic_0000001059148552_p128322028155519"></a><a name="zh-cn_topic_0000001059148552_p128322028155519"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="44.29%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001059148552_p383218285552"><a name="zh-cn_topic_0000001059148552_p383218285552"></a><a name="zh-cn_topic_0000001059148552_p383218285552"></a>线条颜色。</p>
<div class="note" id="zh-cn_topic_0000001059148552_note149682371351"><a name="zh-cn_topic_0000001059148552_note149682371351"></a><a name="zh-cn_topic_0000001059148552_note149682371351"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001059148552_p189688371757"><a name="zh-cn_topic_0000001059148552_p189688371757"></a><a name="zh-cn_topic_0000001059148552_p189688371757"></a>仅线形图支持。</p>
</div></div>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row207559395562"><td class="cellrowborder" valign="top" width="16.56%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001059148552_p177551539205614"><a name="zh-cn_topic_0000001059148552_p177551539205614"></a><a name="zh-cn_topic_0000001059148552_p177551539205614"></a>fillColor</p>
</td>
<td class="cellrowborder" valign="top" width="16.830000000000002%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001059148552_p15755143911563"><a name="zh-cn_topic_0000001059148552_p15755143911563"></a><a name="zh-cn_topic_0000001059148552_p15755143911563"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="12.989999999999998%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001059148552_p9755939185618"><a name="zh-cn_topic_0000001059148552_p9755939185618"></a><a name="zh-cn_topic_0000001059148552_p9755939185618"></a>#ff6384</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001059148552_p1875553995610"><a name="zh-cn_topic_0000001059148552_p1875553995610"></a><a name="zh-cn_topic_0000001059148552_p1875553995610"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="44.29%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001059148552_p975563915619"><a name="zh-cn_topic_0000001059148552_p975563915619"></a><a name="zh-cn_topic_0000001059148552_p975563915619"></a>填充颜色。线形图表示填充的渐变颜色。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row16221319185010"><td class="cellrowborder" valign="top" width="16.56%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001059148552_p1939135171519"><a name="zh-cn_topic_0000001059148552_p1939135171519"></a><a name="zh-cn_topic_0000001059148552_p1939135171519"></a>data</p>
</td>
<td class="cellrowborder" valign="top" width="16.830000000000002%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001059148552_p93945114156"><a name="zh-cn_topic_0000001059148552_p93945114156"></a><a name="zh-cn_topic_0000001059148552_p93945114156"></a>Array&lt;number&gt; | Array&lt;<a href="#zh-cn_topic_0000001059148552_table1470733752019">Point</a>&gt;<sup id="zh-cn_topic_0000001059148552_sup748712541259"><a name="zh-cn_topic_0000001059148552_sup748712541259"></a><a name="zh-cn_topic_0000001059148552_sup748712541259"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="12.989999999999998%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001059148552_p1839951201514"><a name="zh-cn_topic_0000001059148552_p1839951201514"></a><a name="zh-cn_topic_0000001059148552_p1839951201514"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001059148552_p4391651201517"><a name="zh-cn_topic_0000001059148552_p4391651201517"></a><a name="zh-cn_topic_0000001059148552_p4391651201517"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="44.29%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001059148552_p113975114159"><a name="zh-cn_topic_0000001059148552_p113975114159"></a><a name="zh-cn_topic_0000001059148552_p113975114159"></a>设置绘制线或柱中的点集。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row284113911529"><td class="cellrowborder" valign="top" width="16.56%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001059148552_p884110975213"><a name="zh-cn_topic_0000001059148552_p884110975213"></a><a name="zh-cn_topic_0000001059148552_p884110975213"></a>gradient</p>
</td>
<td class="cellrowborder" valign="top" width="16.830000000000002%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001059148552_p168411494528"><a name="zh-cn_topic_0000001059148552_p168411494528"></a><a name="zh-cn_topic_0000001059148552_p168411494528"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="12.989999999999998%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001059148552_p7841992522"><a name="zh-cn_topic_0000001059148552_p7841992522"></a><a name="zh-cn_topic_0000001059148552_p7841992522"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001059148552_p1684159195214"><a name="zh-cn_topic_0000001059148552_p1684159195214"></a><a name="zh-cn_topic_0000001059148552_p1684159195214"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="44.29%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001059148552_p198414916522"><a name="zh-cn_topic_0000001059148552_p198414916522"></a><a name="zh-cn_topic_0000001059148552_p198414916522"></a>设置是否显示填充渐变颜色。</p>
<div class="note" id="zh-cn_topic_0000001059148552_note55873241061"><a name="zh-cn_topic_0000001059148552_note55873241061"></a><a name="zh-cn_topic_0000001059148552_note55873241061"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001059148552_p1558712410616"><a name="zh-cn_topic_0000001059148552_p1558712410616"></a><a name="zh-cn_topic_0000001059148552_p1558712410616"></a>仅线形图支持。</p>
</div></div>
</td>
</tr>
</tbody>
</table>

**表 3**  ChartAxis

<a name="zh-cn_topic_0000001059148552_table11312112919528"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001059148552_row1031252917522"><th class="cellrowborder" valign="top" width="10.18%" id="mcps1.2.6.1.1"><p id="zh-cn_topic_0000001059148552_p7835550165517"><a name="zh-cn_topic_0000001059148552_p7835550165517"></a><a name="zh-cn_topic_0000001059148552_p7835550165517"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="12.91%" id="mcps1.2.6.1.2"><p id="zh-cn_topic_0000001059148552_p2083515012555"><a name="zh-cn_topic_0000001059148552_p2083515012555"></a><a name="zh-cn_topic_0000001059148552_p2083515012555"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="8.870000000000001%" id="mcps1.2.6.1.3"><p id="zh-cn_topic_0000001059148552_p1283545016551"><a name="zh-cn_topic_0000001059148552_p1283545016551"></a><a name="zh-cn_topic_0000001059148552_p1283545016551"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.02%" id="mcps1.2.6.1.4"><p id="zh-cn_topic_0000001059148552_p18351650135519"><a name="zh-cn_topic_0000001059148552_p18351650135519"></a><a name="zh-cn_topic_0000001059148552_p18351650135519"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="61.019999999999996%" id="mcps1.2.6.1.5"><p id="zh-cn_topic_0000001059148552_p10835105017555"><a name="zh-cn_topic_0000001059148552_p10835105017555"></a><a name="zh-cn_topic_0000001059148552_p10835105017555"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001059148552_row231352916527"><td class="cellrowborder" valign="top" width="10.18%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001059148552_p13313529145212"><a name="zh-cn_topic_0000001059148552_p13313529145212"></a><a name="zh-cn_topic_0000001059148552_p13313529145212"></a>min</p>
</td>
<td class="cellrowborder" valign="top" width="12.91%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001059148552_p14313429185211"><a name="zh-cn_topic_0000001059148552_p14313429185211"></a><a name="zh-cn_topic_0000001059148552_p14313429185211"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.870000000000001%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001059148552_p19313152995219"><a name="zh-cn_topic_0000001059148552_p19313152995219"></a><a name="zh-cn_topic_0000001059148552_p19313152995219"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.02%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001059148552_p03131429165220"><a name="zh-cn_topic_0000001059148552_p03131429165220"></a><a name="zh-cn_topic_0000001059148552_p03131429165220"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="61.019999999999996%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001059148552_p15313529165215"><a name="zh-cn_topic_0000001059148552_p15313529165215"></a><a name="zh-cn_topic_0000001059148552_p15313529165215"></a>轴的最小值。</p>
<div class="note" id="zh-cn_topic_0000001059148552_note947711273197"><a name="zh-cn_topic_0000001059148552_note947711273197"></a><a name="zh-cn_topic_0000001059148552_note947711273197"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001059148552_p5477102781911"><a name="zh-cn_topic_0000001059148552_p5477102781911"></a><a name="zh-cn_topic_0000001059148552_p5477102781911"></a>不支持负数。仅线形图支持。</p>
</div></div>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row10177207165517"><td class="cellrowborder" valign="top" width="10.18%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001059148552_p191773713559"><a name="zh-cn_topic_0000001059148552_p191773713559"></a><a name="zh-cn_topic_0000001059148552_p191773713559"></a>max</p>
</td>
<td class="cellrowborder" valign="top" width="12.91%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001059148552_p11771076557"><a name="zh-cn_topic_0000001059148552_p11771076557"></a><a name="zh-cn_topic_0000001059148552_p11771076557"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.870000000000001%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001059148552_p13177127165511"><a name="zh-cn_topic_0000001059148552_p13177127165511"></a><a name="zh-cn_topic_0000001059148552_p13177127165511"></a>100</p>
</td>
<td class="cellrowborder" valign="top" width="7.02%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001059148552_p171774715517"><a name="zh-cn_topic_0000001059148552_p171774715517"></a><a name="zh-cn_topic_0000001059148552_p171774715517"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="61.019999999999996%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001059148552_p111771705519"><a name="zh-cn_topic_0000001059148552_p111771705519"></a><a name="zh-cn_topic_0000001059148552_p111771705519"></a>轴的最大值。</p>
<div class="note" id="zh-cn_topic_0000001059148552_note1287217389195"><a name="zh-cn_topic_0000001059148552_note1287217389195"></a><a name="zh-cn_topic_0000001059148552_note1287217389195"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001059148552_p17872153817197"><a name="zh-cn_topic_0000001059148552_p17872153817197"></a><a name="zh-cn_topic_0000001059148552_p17872153817197"></a>不支持负数。仅线形图支持。</p>
</div></div>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row54401875553"><td class="cellrowborder" valign="top" width="10.18%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001059148552_p544037145514"><a name="zh-cn_topic_0000001059148552_p544037145514"></a><a name="zh-cn_topic_0000001059148552_p544037145514"></a>axisTick</p>
</td>
<td class="cellrowborder" valign="top" width="12.91%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001059148552_p844011745512"><a name="zh-cn_topic_0000001059148552_p844011745512"></a><a name="zh-cn_topic_0000001059148552_p844011745512"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.870000000000001%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001059148552_p9440277558"><a name="zh-cn_topic_0000001059148552_p9440277558"></a><a name="zh-cn_topic_0000001059148552_p9440277558"></a>10</p>
</td>
<td class="cellrowborder" valign="top" width="7.02%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001059148552_p194406755518"><a name="zh-cn_topic_0000001059148552_p194406755518"></a><a name="zh-cn_topic_0000001059148552_p194406755518"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="61.019999999999996%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001059148552_p1144027105511"><a name="zh-cn_topic_0000001059148552_p1144027105511"></a><a name="zh-cn_topic_0000001059148552_p1144027105511"></a>轴显示的刻度数量。</p>
<div class="note" id="zh-cn_topic_0000001059148552_note18942121511202"><a name="zh-cn_topic_0000001059148552_note18942121511202"></a><a name="zh-cn_topic_0000001059148552_note18942121511202"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001059148552_p4709421681"><a name="zh-cn_topic_0000001059148552_p4709421681"></a><a name="zh-cn_topic_0000001059148552_p4709421681"></a>仅支持1~20，且具体显示的效果与如下计算值有关（图的宽度所占的像素/（max-min））。</p>
<p id="zh-cn_topic_0000001059148552_p234142016205"><a name="zh-cn_topic_0000001059148552_p234142016205"></a><a name="zh-cn_topic_0000001059148552_p234142016205"></a>在柱状图中，每组数据显示的柱子数量与刻度数量一致，且柱子显示在刻度处。</p>
</div></div>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row6558148125516"><td class="cellrowborder" valign="top" width="10.18%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001059148552_p1555818865515"><a name="zh-cn_topic_0000001059148552_p1555818865515"></a><a name="zh-cn_topic_0000001059148552_p1555818865515"></a>display</p>
</td>
<td class="cellrowborder" valign="top" width="12.91%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001059148552_p1755910815552"><a name="zh-cn_topic_0000001059148552_p1755910815552"></a><a name="zh-cn_topic_0000001059148552_p1755910815552"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="8.870000000000001%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001059148552_p2559108195515"><a name="zh-cn_topic_0000001059148552_p2559108195515"></a><a name="zh-cn_topic_0000001059148552_p2559108195515"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.02%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001059148552_p185597805514"><a name="zh-cn_topic_0000001059148552_p185597805514"></a><a name="zh-cn_topic_0000001059148552_p185597805514"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="61.019999999999996%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001059148552_p1655910815551"><a name="zh-cn_topic_0000001059148552_p1655910815551"></a><a name="zh-cn_topic_0000001059148552_p1655910815551"></a>是否显示轴。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row1382114065515"><td class="cellrowborder" valign="top" width="10.18%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001059148552_p188221209555"><a name="zh-cn_topic_0000001059148552_p188221209555"></a><a name="zh-cn_topic_0000001059148552_p188221209555"></a>color</p>
</td>
<td class="cellrowborder" valign="top" width="12.91%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001059148552_p1782214025517"><a name="zh-cn_topic_0000001059148552_p1782214025517"></a><a name="zh-cn_topic_0000001059148552_p1782214025517"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.870000000000001%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001059148552_p482220185512"><a name="zh-cn_topic_0000001059148552_p482220185512"></a><a name="zh-cn_topic_0000001059148552_p482220185512"></a>#c0c0c0</p>
</td>
<td class="cellrowborder" valign="top" width="7.02%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001059148552_p782214015553"><a name="zh-cn_topic_0000001059148552_p782214015553"></a><a name="zh-cn_topic_0000001059148552_p782214015553"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="61.019999999999996%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001059148552_p4822202556"><a name="zh-cn_topic_0000001059148552_p4822202556"></a><a name="zh-cn_topic_0000001059148552_p4822202556"></a>轴颜色。</p>
</td>
</tr>
</tbody>
</table>

**表 4**  ChartSeries

<a name="zh-cn_topic_0000001059148552_table029562010560"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001059148552_row9295192095610"><th class="cellrowborder" valign="top" width="17%" id="mcps1.2.6.1.1"><p id="zh-cn_topic_0000001059148552_p10617123345612"><a name="zh-cn_topic_0000001059148552_p10617123345612"></a><a name="zh-cn_topic_0000001059148552_p10617123345612"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="16.39%" id="mcps1.2.6.1.2"><p id="zh-cn_topic_0000001059148552_p9617133175613"><a name="zh-cn_topic_0000001059148552_p9617133175613"></a><a name="zh-cn_topic_0000001059148552_p9617133175613"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="12.82%" id="mcps1.2.6.1.3"><p id="zh-cn_topic_0000001059148552_p3617153315562"><a name="zh-cn_topic_0000001059148552_p3617153315562"></a><a name="zh-cn_topic_0000001059148552_p3617153315562"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="10.11%" id="mcps1.2.6.1.4"><p id="zh-cn_topic_0000001059148552_p4617163305612"><a name="zh-cn_topic_0000001059148552_p4617163305612"></a><a name="zh-cn_topic_0000001059148552_p4617163305612"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="43.68%" id="mcps1.2.6.1.5"><p id="zh-cn_topic_0000001059148552_p1561718337569"><a name="zh-cn_topic_0000001059148552_p1561718337569"></a><a name="zh-cn_topic_0000001059148552_p1561718337569"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001059148552_row13295162011563"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001059148552_p2296820185612"><a name="zh-cn_topic_0000001059148552_p2296820185612"></a><a name="zh-cn_topic_0000001059148552_p2296820185612"></a>lineStyle</p>
</td>
<td class="cellrowborder" valign="top" width="16.39%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001059148552_p529652005615"><a name="zh-cn_topic_0000001059148552_p529652005615"></a><a name="zh-cn_topic_0000001059148552_p529652005615"></a><a href="#zh-cn_topic_0000001059148552_table7790183513918">ChartLineStyle</a></p>
</td>
<td class="cellrowborder" valign="top" width="12.82%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001059148552_p629612208561"><a name="zh-cn_topic_0000001059148552_p629612208561"></a><a name="zh-cn_topic_0000001059148552_p629612208561"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="10.11%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001059148552_p129632065619"><a name="zh-cn_topic_0000001059148552_p129632065619"></a><a name="zh-cn_topic_0000001059148552_p129632065619"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.68%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001059148552_p929652045614"><a name="zh-cn_topic_0000001059148552_p929652045614"></a><a name="zh-cn_topic_0000001059148552_p929652045614"></a>线样式设置，如线宽、是否平滑。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row1829652010566"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001059148552_p17296112017565"><a name="zh-cn_topic_0000001059148552_p17296112017565"></a><a name="zh-cn_topic_0000001059148552_p17296112017565"></a>headPoint</p>
</td>
<td class="cellrowborder" valign="top" width="16.39%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001059148552_p1829632018566"><a name="zh-cn_topic_0000001059148552_p1829632018566"></a><a name="zh-cn_topic_0000001059148552_p1829632018566"></a><a href="#zh-cn_topic_0000001059148552_table1435760101317">PointStyle</a></p>
</td>
<td class="cellrowborder" valign="top" width="12.82%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001059148552_p52966203569"><a name="zh-cn_topic_0000001059148552_p52966203569"></a><a name="zh-cn_topic_0000001059148552_p52966203569"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="10.11%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001059148552_p17296020155611"><a name="zh-cn_topic_0000001059148552_p17296020155611"></a><a name="zh-cn_topic_0000001059148552_p17296020155611"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.68%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001059148552_p14296132015616"><a name="zh-cn_topic_0000001059148552_p14296132015616"></a><a name="zh-cn_topic_0000001059148552_p14296132015616"></a>线最前端位置白点的样式和大小。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row416985481620"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001059148552_p816915441619"><a name="zh-cn_topic_0000001059148552_p816915441619"></a><a name="zh-cn_topic_0000001059148552_p816915441619"></a>topPoint</p>
</td>
<td class="cellrowborder" valign="top" width="16.39%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001059148552_p13169145471618"><a name="zh-cn_topic_0000001059148552_p13169145471618"></a><a name="zh-cn_topic_0000001059148552_p13169145471618"></a><a href="#zh-cn_topic_0000001059148552_table1435760101317">PointStyle</a></p>
</td>
<td class="cellrowborder" valign="top" width="12.82%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001059148552_p816995416164"><a name="zh-cn_topic_0000001059148552_p816995416164"></a><a name="zh-cn_topic_0000001059148552_p816995416164"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="10.11%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001059148552_p2017015417166"><a name="zh-cn_topic_0000001059148552_p2017015417166"></a><a name="zh-cn_topic_0000001059148552_p2017015417166"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.68%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001059148552_p98810719197"><a name="zh-cn_topic_0000001059148552_p98810719197"></a><a name="zh-cn_topic_0000001059148552_p98810719197"></a>最高点的样式和大小。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row9719195771616"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001059148552_p12719857161614"><a name="zh-cn_topic_0000001059148552_p12719857161614"></a><a name="zh-cn_topic_0000001059148552_p12719857161614"></a>bottomPoint</p>
</td>
<td class="cellrowborder" valign="top" width="16.39%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001059148552_p631412816137"><a name="zh-cn_topic_0000001059148552_p631412816137"></a><a name="zh-cn_topic_0000001059148552_p631412816137"></a><a href="#zh-cn_topic_0000001059148552_table1435760101317">PointStyle</a></p>
</td>
<td class="cellrowborder" valign="top" width="12.82%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001059148552_p1771995719166"><a name="zh-cn_topic_0000001059148552_p1771995719166"></a><a name="zh-cn_topic_0000001059148552_p1771995719166"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="10.11%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001059148552_p77192571166"><a name="zh-cn_topic_0000001059148552_p77192571166"></a><a name="zh-cn_topic_0000001059148552_p77192571166"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.68%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001059148552_p10719357111610"><a name="zh-cn_topic_0000001059148552_p10719357111610"></a><a name="zh-cn_topic_0000001059148552_p10719357111610"></a>最低点的样式和大小。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row1165515117356"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001059148552_p1065610143518"><a name="zh-cn_topic_0000001059148552_p1065610143518"></a><a name="zh-cn_topic_0000001059148552_p1065610143518"></a>loop</p>
</td>
<td class="cellrowborder" valign="top" width="16.39%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001059148552_p8656121143511"><a name="zh-cn_topic_0000001059148552_p8656121143511"></a><a name="zh-cn_topic_0000001059148552_p8656121143511"></a><a href="#zh-cn_topic_0000001059148552_table13982347173714">ChartLoop</a></p>
</td>
<td class="cellrowborder" valign="top" width="12.82%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001059148552_p765611163510"><a name="zh-cn_topic_0000001059148552_p765611163510"></a><a name="zh-cn_topic_0000001059148552_p765611163510"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="10.11%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001059148552_p1965671123510"><a name="zh-cn_topic_0000001059148552_p1965671123510"></a><a name="zh-cn_topic_0000001059148552_p1965671123510"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.68%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001059148552_p19656131113517"><a name="zh-cn_topic_0000001059148552_p19656131113517"></a><a name="zh-cn_topic_0000001059148552_p19656131113517"></a>设置屏幕显示满时，是否需要重头开始绘制。</p>
</td>
</tr>
</tbody>
</table>

**表 5**  ChartLineStyle

<a name="zh-cn_topic_0000001059148552_table7790183513918"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001059148552_row167906351914"><th class="cellrowborder" valign="top" width="17.09%" id="mcps1.2.6.1.1"><p id="zh-cn_topic_0000001059148552_p15238040191012"><a name="zh-cn_topic_0000001059148552_p15238040191012"></a><a name="zh-cn_topic_0000001059148552_p15238040191012"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="16.91%" id="mcps1.2.6.1.2"><p id="zh-cn_topic_0000001059148552_p142381440151020"><a name="zh-cn_topic_0000001059148552_p142381440151020"></a><a name="zh-cn_topic_0000001059148552_p142381440151020"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="12.690000000000001%" id="mcps1.2.6.1.3"><p id="zh-cn_topic_0000001059148552_p723814051011"><a name="zh-cn_topic_0000001059148552_p723814051011"></a><a name="zh-cn_topic_0000001059148552_p723814051011"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="10.24%" id="mcps1.2.6.1.4"><p id="zh-cn_topic_0000001059148552_p623818402108"><a name="zh-cn_topic_0000001059148552_p623818402108"></a><a name="zh-cn_topic_0000001059148552_p623818402108"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="43.07%" id="mcps1.2.6.1.5"><p id="zh-cn_topic_0000001059148552_p1223834091020"><a name="zh-cn_topic_0000001059148552_p1223834091020"></a><a name="zh-cn_topic_0000001059148552_p1223834091020"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001059148552_row47909350912"><td class="cellrowborder" valign="top" width="17.09%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001059148552_p13791135393"><a name="zh-cn_topic_0000001059148552_p13791135393"></a><a name="zh-cn_topic_0000001059148552_p13791135393"></a>width</p>
</td>
<td class="cellrowborder" valign="top" width="16.91%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001059148552_p5791123511915"><a name="zh-cn_topic_0000001059148552_p5791123511915"></a><a name="zh-cn_topic_0000001059148552_p5791123511915"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="12.690000000000001%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001059148552_p1479120352916"><a name="zh-cn_topic_0000001059148552_p1479120352916"></a><a name="zh-cn_topic_0000001059148552_p1479120352916"></a>1px</p>
</td>
<td class="cellrowborder" valign="top" width="10.24%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001059148552_p87911135691"><a name="zh-cn_topic_0000001059148552_p87911135691"></a><a name="zh-cn_topic_0000001059148552_p87911135691"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.07%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001059148552_p47917356918"><a name="zh-cn_topic_0000001059148552_p47917356918"></a><a name="zh-cn_topic_0000001059148552_p47917356918"></a>线宽设置。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row1279183510911"><td class="cellrowborder" valign="top" width="17.09%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001059148552_p107913351297"><a name="zh-cn_topic_0000001059148552_p107913351297"></a><a name="zh-cn_topic_0000001059148552_p107913351297"></a>smooth</p>
</td>
<td class="cellrowborder" valign="top" width="16.91%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001059148552_p1479113515915"><a name="zh-cn_topic_0000001059148552_p1479113515915"></a><a name="zh-cn_topic_0000001059148552_p1479113515915"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="12.690000000000001%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001059148552_p179111356910"><a name="zh-cn_topic_0000001059148552_p179111356910"></a><a name="zh-cn_topic_0000001059148552_p179111356910"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="10.24%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001059148552_p979117355914"><a name="zh-cn_topic_0000001059148552_p979117355914"></a><a name="zh-cn_topic_0000001059148552_p979117355914"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.07%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001059148552_p1879113353920"><a name="zh-cn_topic_0000001059148552_p1879113353920"></a><a name="zh-cn_topic_0000001059148552_p1879113353920"></a>是否平滑。</p>
</td>
</tr>
</tbody>
</table>

**表 6**  PointStyle

<a name="zh-cn_topic_0000001059148552_table1435760101317"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001059148552_row0357180181315"><th class="cellrowborder" valign="top" width="17.09%" id="mcps1.2.6.1.1"><p id="zh-cn_topic_0000001059148552_p763402181310"><a name="zh-cn_topic_0000001059148552_p763402181310"></a><a name="zh-cn_topic_0000001059148552_p763402181310"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="17.09%" id="mcps1.2.6.1.2"><p id="zh-cn_topic_0000001059148552_p963402171313"><a name="zh-cn_topic_0000001059148552_p963402171313"></a><a name="zh-cn_topic_0000001059148552_p963402171313"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="12.64%" id="mcps1.2.6.1.3"><p id="zh-cn_topic_0000001059148552_p166343212133"><a name="zh-cn_topic_0000001059148552_p166343212133"></a><a name="zh-cn_topic_0000001059148552_p166343212133"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="10.549999999999999%" id="mcps1.2.6.1.4"><p id="zh-cn_topic_0000001059148552_p4634621111311"><a name="zh-cn_topic_0000001059148552_p4634621111311"></a><a name="zh-cn_topic_0000001059148552_p4634621111311"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="42.63%" id="mcps1.2.6.1.5"><p id="zh-cn_topic_0000001059148552_p2063413215132"><a name="zh-cn_topic_0000001059148552_p2063413215132"></a><a name="zh-cn_topic_0000001059148552_p2063413215132"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001059148552_row53581105131"><td class="cellrowborder" valign="top" width="17.09%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001059148552_p12358803137"><a name="zh-cn_topic_0000001059148552_p12358803137"></a><a name="zh-cn_topic_0000001059148552_p12358803137"></a>shape</p>
</td>
<td class="cellrowborder" valign="top" width="17.09%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001059148552_p19358190201313"><a name="zh-cn_topic_0000001059148552_p19358190201313"></a><a name="zh-cn_topic_0000001059148552_p19358190201313"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="12.64%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001059148552_p1358170141315"><a name="zh-cn_topic_0000001059148552_p1358170141315"></a><a name="zh-cn_topic_0000001059148552_p1358170141315"></a>circle</p>
</td>
<td class="cellrowborder" valign="top" width="10.549999999999999%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001059148552_p0358203135"><a name="zh-cn_topic_0000001059148552_p0358203135"></a><a name="zh-cn_topic_0000001059148552_p0358203135"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="42.63%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001059148552_p113581206134"><a name="zh-cn_topic_0000001059148552_p113581206134"></a><a name="zh-cn_topic_0000001059148552_p113581206134"></a>高亮点的形状。可选值为：</p>
<a name="zh-cn_topic_0000001059148552_ul107389175319"></a><a name="zh-cn_topic_0000001059148552_ul107389175319"></a><ul id="zh-cn_topic_0000001059148552_ul107389175319"><li>circle：圆形。</li><li>square：方形。</li><li>triangle：三角形。</li></ul>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row143581011317"><td class="cellrowborder" valign="top" width="17.09%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001059148552_p19358200201311"><a name="zh-cn_topic_0000001059148552_p19358200201311"></a><a name="zh-cn_topic_0000001059148552_p19358200201311"></a>size</p>
</td>
<td class="cellrowborder" valign="top" width="17.09%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001059148552_p93585011135"><a name="zh-cn_topic_0000001059148552_p93585011135"></a><a name="zh-cn_topic_0000001059148552_p93585011135"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="12.64%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001059148552_p203581081313"><a name="zh-cn_topic_0000001059148552_p203581081313"></a><a name="zh-cn_topic_0000001059148552_p203581081313"></a>5px</p>
</td>
<td class="cellrowborder" valign="top" width="10.549999999999999%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001059148552_p183582008137"><a name="zh-cn_topic_0000001059148552_p183582008137"></a><a name="zh-cn_topic_0000001059148552_p183582008137"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="42.63%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001059148552_p2358502135"><a name="zh-cn_topic_0000001059148552_p2358502135"></a><a name="zh-cn_topic_0000001059148552_p2358502135"></a>高亮点的大小。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row957985594815"><td class="cellrowborder" valign="top" width="17.09%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001059148552_p11579165564814"><a name="zh-cn_topic_0000001059148552_p11579165564814"></a><a name="zh-cn_topic_0000001059148552_p11579165564814"></a>strokeWidth</p>
</td>
<td class="cellrowborder" valign="top" width="17.09%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001059148552_p657916559486"><a name="zh-cn_topic_0000001059148552_p657916559486"></a><a name="zh-cn_topic_0000001059148552_p657916559486"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="12.64%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001059148552_p12579105514489"><a name="zh-cn_topic_0000001059148552_p12579105514489"></a><a name="zh-cn_topic_0000001059148552_p12579105514489"></a>1px</p>
</td>
<td class="cellrowborder" valign="top" width="10.549999999999999%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001059148552_p958015514480"><a name="zh-cn_topic_0000001059148552_p958015514480"></a><a name="zh-cn_topic_0000001059148552_p958015514480"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="42.63%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001059148552_p3580115534814"><a name="zh-cn_topic_0000001059148552_p3580115534814"></a><a name="zh-cn_topic_0000001059148552_p3580115534814"></a>边框宽度</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row51421313317"><td class="cellrowborder" valign="top" width="17.09%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001059148552_p151432333315"><a name="zh-cn_topic_0000001059148552_p151432333315"></a><a name="zh-cn_topic_0000001059148552_p151432333315"></a>strokeColor</p>
</td>
<td class="cellrowborder" valign="top" width="17.09%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001059148552_p1914312363315"><a name="zh-cn_topic_0000001059148552_p1914312363315"></a><a name="zh-cn_topic_0000001059148552_p1914312363315"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="12.64%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001059148552_p114319316335"><a name="zh-cn_topic_0000001059148552_p114319316335"></a><a name="zh-cn_topic_0000001059148552_p114319316335"></a>#ff0000</p>
</td>
<td class="cellrowborder" valign="top" width="10.549999999999999%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001059148552_p11431036331"><a name="zh-cn_topic_0000001059148552_p11431036331"></a><a name="zh-cn_topic_0000001059148552_p11431036331"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="42.63%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001059148552_p181441434339"><a name="zh-cn_topic_0000001059148552_p181441434339"></a><a name="zh-cn_topic_0000001059148552_p181441434339"></a>边框颜色。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row1312214335332"><td class="cellrowborder" valign="top" width="17.09%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001059148552_p10123233193310"><a name="zh-cn_topic_0000001059148552_p10123233193310"></a><a name="zh-cn_topic_0000001059148552_p10123233193310"></a>fillColor</p>
</td>
<td class="cellrowborder" valign="top" width="17.09%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001059148552_p12123233123310"><a name="zh-cn_topic_0000001059148552_p12123233123310"></a><a name="zh-cn_topic_0000001059148552_p12123233123310"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="12.64%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001059148552_p10123143343313"><a name="zh-cn_topic_0000001059148552_p10123143343313"></a><a name="zh-cn_topic_0000001059148552_p10123143343313"></a>#ff0000</p>
</td>
<td class="cellrowborder" valign="top" width="10.549999999999999%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001059148552_p16123163317338"><a name="zh-cn_topic_0000001059148552_p16123163317338"></a><a name="zh-cn_topic_0000001059148552_p16123163317338"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="42.63%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001059148552_p6123433193311"><a name="zh-cn_topic_0000001059148552_p6123433193311"></a><a name="zh-cn_topic_0000001059148552_p6123433193311"></a>填充颜色。</p>
</td>
</tr>
</tbody>
</table>

**表 7**  ChartLoop

<a name="zh-cn_topic_0000001059148552_table13982347173714"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001059148552_row1498384714371"><th class="cellrowborder" valign="top" width="11.85%" id="mcps1.2.6.1.1"><p id="zh-cn_topic_0000001059148552_p1640543183916"><a name="zh-cn_topic_0000001059148552_p1640543183916"></a><a name="zh-cn_topic_0000001059148552_p1640543183916"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="12.030000000000001%" id="mcps1.2.6.1.2"><p id="zh-cn_topic_0000001059148552_p18640043143916"><a name="zh-cn_topic_0000001059148552_p18640043143916"></a><a name="zh-cn_topic_0000001059148552_p18640043143916"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="9.83%" id="mcps1.2.6.1.3"><p id="zh-cn_topic_0000001059148552_p12640144317398"><a name="zh-cn_topic_0000001059148552_p12640144317398"></a><a name="zh-cn_topic_0000001059148552_p12640144317398"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="9.04%" id="mcps1.2.6.1.4"><p id="zh-cn_topic_0000001059148552_p1764014343915"><a name="zh-cn_topic_0000001059148552_p1764014343915"></a><a name="zh-cn_topic_0000001059148552_p1764014343915"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="57.25%" id="mcps1.2.6.1.5"><p id="zh-cn_topic_0000001059148552_p1064084314395"><a name="zh-cn_topic_0000001059148552_p1064084314395"></a><a name="zh-cn_topic_0000001059148552_p1064084314395"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001059148552_row8983164710376"><td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001059148552_p11983147113716"><a name="zh-cn_topic_0000001059148552_p11983147113716"></a><a name="zh-cn_topic_0000001059148552_p11983147113716"></a>margin</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001059148552_p1898316477374"><a name="zh-cn_topic_0000001059148552_p1898316477374"></a><a name="zh-cn_topic_0000001059148552_p1898316477374"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="9.83%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001059148552_p139841479376"><a name="zh-cn_topic_0000001059148552_p139841479376"></a><a name="zh-cn_topic_0000001059148552_p139841479376"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001059148552_p169842479376"><a name="zh-cn_topic_0000001059148552_p169842479376"></a><a name="zh-cn_topic_0000001059148552_p169842479376"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="57.25%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001059148552_p798434723720"><a name="zh-cn_topic_0000001059148552_p798434723720"></a><a name="zh-cn_topic_0000001059148552_p798434723720"></a>擦除点的个数（最新绘制的点与最老的点之间的横向距离）。注意：轻量设备margin和topPoint/bottomPoint/headPoint同时使用时，有概率出现point正好位于擦除区域的情况，导致point不可见，因此不建议同时使用。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row109849472372"><td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001059148552_p09841047183715"><a name="zh-cn_topic_0000001059148552_p09841047183715"></a><a name="zh-cn_topic_0000001059148552_p09841047183715"></a>gradient</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001059148552_p92761838193812"><a name="zh-cn_topic_0000001059148552_p92761838193812"></a><a name="zh-cn_topic_0000001059148552_p92761838193812"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="9.83%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001059148552_p127603819380"><a name="zh-cn_topic_0000001059148552_p127603819380"></a><a name="zh-cn_topic_0000001059148552_p127603819380"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001059148552_p227733816384"><a name="zh-cn_topic_0000001059148552_p227733816384"></a><a name="zh-cn_topic_0000001059148552_p227733816384"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="57.25%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001059148552_p13277173823811"><a name="zh-cn_topic_0000001059148552_p13277173823811"></a><a name="zh-cn_topic_0000001059148552_p13277173823811"></a>是否需要渐变擦除。</p>
</td>
</tr>
</tbody>
</table>

**表 8**  Point<sup>5+</sup>

<a name="zh-cn_topic_0000001059148552_table1470733752019"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001059148552_row177072373203"><th class="cellrowborder" valign="top" width="11.85%" id="mcps1.2.6.1.1"><p id="zh-cn_topic_0000001059148552_p1770793715201"><a name="zh-cn_topic_0000001059148552_p1770793715201"></a><a name="zh-cn_topic_0000001059148552_p1770793715201"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="12.030000000000001%" id="mcps1.2.6.1.2"><p id="zh-cn_topic_0000001059148552_p137073372202"><a name="zh-cn_topic_0000001059148552_p137073372202"></a><a name="zh-cn_topic_0000001059148552_p137073372202"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="9.83%" id="mcps1.2.6.1.3"><p id="zh-cn_topic_0000001059148552_p47078377208"><a name="zh-cn_topic_0000001059148552_p47078377208"></a><a name="zh-cn_topic_0000001059148552_p47078377208"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="9.04%" id="mcps1.2.6.1.4"><p id="zh-cn_topic_0000001059148552_p1470719376206"><a name="zh-cn_topic_0000001059148552_p1470719376206"></a><a name="zh-cn_topic_0000001059148552_p1470719376206"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="57.25%" id="mcps1.2.6.1.5"><p id="zh-cn_topic_0000001059148552_p1370783712017"><a name="zh-cn_topic_0000001059148552_p1370783712017"></a><a name="zh-cn_topic_0000001059148552_p1370783712017"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001059148552_row137071737112010"><td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001059148552_p9707153711207"><a name="zh-cn_topic_0000001059148552_p9707153711207"></a><a name="zh-cn_topic_0000001059148552_p9707153711207"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001059148552_p157081437132013"><a name="zh-cn_topic_0000001059148552_p157081437132013"></a><a name="zh-cn_topic_0000001059148552_p157081437132013"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="9.83%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001059148552_p970833722016"><a name="zh-cn_topic_0000001059148552_p970833722016"></a><a name="zh-cn_topic_0000001059148552_p970833722016"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001059148552_p2070812378209"><a name="zh-cn_topic_0000001059148552_p2070812378209"></a><a name="zh-cn_topic_0000001059148552_p2070812378209"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="57.25%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001059148552_p188430361213"><a name="zh-cn_topic_0000001059148552_p188430361213"></a><a name="zh-cn_topic_0000001059148552_p188430361213"></a>表示绘制点的Y轴坐标。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row13708173719202"><td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001059148552_p18708143772014"><a name="zh-cn_topic_0000001059148552_p18708143772014"></a><a name="zh-cn_topic_0000001059148552_p18708143772014"></a>pointStyle</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001059148552_p77081637172018"><a name="zh-cn_topic_0000001059148552_p77081637172018"></a><a name="zh-cn_topic_0000001059148552_p77081637172018"></a><a href="#zh-cn_topic_0000001059148552_table1435760101317">PointStyle</a></p>
</td>
<td class="cellrowborder" valign="top" width="9.83%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001059148552_p270803719206"><a name="zh-cn_topic_0000001059148552_p270803719206"></a><a name="zh-cn_topic_0000001059148552_p270803719206"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001059148552_p19708133782018"><a name="zh-cn_topic_0000001059148552_p19708133782018"></a><a name="zh-cn_topic_0000001059148552_p19708133782018"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="57.25%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001059148552_p12708203712010"><a name="zh-cn_topic_0000001059148552_p12708203712010"></a><a name="zh-cn_topic_0000001059148552_p12708203712010"></a>表示当前数据点的绘制样式。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row431291710242"><td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001059148552_p13131917162412"><a name="zh-cn_topic_0000001059148552_p13131917162412"></a><a name="zh-cn_topic_0000001059148552_p13131917162412"></a>description</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001059148552_p1231341710240"><a name="zh-cn_topic_0000001059148552_p1231341710240"></a><a name="zh-cn_topic_0000001059148552_p1231341710240"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.83%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001059148552_p14313121716241"><a name="zh-cn_topic_0000001059148552_p14313121716241"></a><a name="zh-cn_topic_0000001059148552_p14313121716241"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001059148552_p13139178245"><a name="zh-cn_topic_0000001059148552_p13139178245"></a><a name="zh-cn_topic_0000001059148552_p13139178245"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="57.25%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001059148552_p11313171716246"><a name="zh-cn_topic_0000001059148552_p11313171716246"></a><a name="zh-cn_topic_0000001059148552_p11313171716246"></a>表示当前点的注释内容。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row431301902517"><td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001059148552_p1931461914251"><a name="zh-cn_topic_0000001059148552_p1931461914251"></a><a name="zh-cn_topic_0000001059148552_p1931461914251"></a>textLocation</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001059148552_p1331471915257"><a name="zh-cn_topic_0000001059148552_p1331471915257"></a><a name="zh-cn_topic_0000001059148552_p1331471915257"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.83%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001059148552_p331431992516"><a name="zh-cn_topic_0000001059148552_p331431992516"></a><a name="zh-cn_topic_0000001059148552_p331431992516"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001059148552_p33145199254"><a name="zh-cn_topic_0000001059148552_p33145199254"></a><a name="zh-cn_topic_0000001059148552_p33145199254"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="57.25%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001059148552_p20314141922517"><a name="zh-cn_topic_0000001059148552_p20314141922517"></a><a name="zh-cn_topic_0000001059148552_p20314141922517"></a>可选值为top，bottom，none。分别表示注释的绘制位置位于点的上方，下方，以及不绘制。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row48671150122613"><td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001059148552_p486819509261"><a name="zh-cn_topic_0000001059148552_p486819509261"></a><a name="zh-cn_topic_0000001059148552_p486819509261"></a>textColor</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001059148552_p12868165002617"><a name="zh-cn_topic_0000001059148552_p12868165002617"></a><a name="zh-cn_topic_0000001059148552_p12868165002617"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="9.83%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001059148552_p4868205002616"><a name="zh-cn_topic_0000001059148552_p4868205002616"></a><a name="zh-cn_topic_0000001059148552_p4868205002616"></a>#000000</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001059148552_p1286825017267"><a name="zh-cn_topic_0000001059148552_p1286825017267"></a><a name="zh-cn_topic_0000001059148552_p1286825017267"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="57.25%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001059148552_p13868150162611"><a name="zh-cn_topic_0000001059148552_p13868150162611"></a><a name="zh-cn_topic_0000001059148552_p13868150162611"></a>表示注释文字的颜色。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row9703542172713"><td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001059148552_p1870364214275"><a name="zh-cn_topic_0000001059148552_p1870364214275"></a><a name="zh-cn_topic_0000001059148552_p1870364214275"></a>lineDash</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001059148552_p1470334222718"><a name="zh-cn_topic_0000001059148552_p1470334222718"></a><a name="zh-cn_topic_0000001059148552_p1470334222718"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.83%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001059148552_p1670324217274"><a name="zh-cn_topic_0000001059148552_p1670324217274"></a><a name="zh-cn_topic_0000001059148552_p1670324217274"></a>solid</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001059148552_p197033423272"><a name="zh-cn_topic_0000001059148552_p197033423272"></a><a name="zh-cn_topic_0000001059148552_p197033423272"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="57.25%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001059148552_p570304202712"><a name="zh-cn_topic_0000001059148552_p570304202712"></a><a name="zh-cn_topic_0000001059148552_p570304202712"></a>表示绘制当前线段虚线的样式。“dashed， 5， 5”表示纯虚线，绘制5px的实线后留5px的空白。“solid”表示绘制实线。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row15389105792810"><td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001059148552_p15389357102818"><a name="zh-cn_topic_0000001059148552_p15389357102818"></a><a name="zh-cn_topic_0000001059148552_p15389357102818"></a>lineColor</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001059148552_p3389135711281"><a name="zh-cn_topic_0000001059148552_p3389135711281"></a><a name="zh-cn_topic_0000001059148552_p3389135711281"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="9.83%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001059148552_p135711197293"><a name="zh-cn_topic_0000001059148552_p135711197293"></a><a name="zh-cn_topic_0000001059148552_p135711197293"></a>#000000</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001059148552_p17389105762819"><a name="zh-cn_topic_0000001059148552_p17389105762819"></a><a name="zh-cn_topic_0000001059148552_p17389105762819"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="57.25%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059148552_p19389175716289"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059148552_p19389175716289"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059148552_p19389175716289"></a>表示绘制当前线段的颜色。此颜色不设置会默认使用整体的strokeColor。</p>
</td>
</tr>
</tbody>
</table>

**表 9**  DataSegment<sup>5+</sup>

<a name="zh-cn_topic_0000001059148552_table2596183616210"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001059148552_row15969362212"><th class="cellrowborder" valign="top" width="11.85%" id="mcps1.2.6.1.1"><p id="zh-cn_topic_0000001059148552_p159616362220"><a name="zh-cn_topic_0000001059148552_p159616362220"></a><a name="zh-cn_topic_0000001059148552_p159616362220"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="12.030000000000001%" id="mcps1.2.6.1.2"><p id="zh-cn_topic_0000001059148552_p175961136723"><a name="zh-cn_topic_0000001059148552_p175961136723"></a><a name="zh-cn_topic_0000001059148552_p175961136723"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="9.83%" id="mcps1.2.6.1.3"><p id="zh-cn_topic_0000001059148552_p259612361126"><a name="zh-cn_topic_0000001059148552_p259612361126"></a><a name="zh-cn_topic_0000001059148552_p259612361126"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="9.04%" id="mcps1.2.6.1.4"><p id="zh-cn_topic_0000001059148552_p135975361628"><a name="zh-cn_topic_0000001059148552_p135975361628"></a><a name="zh-cn_topic_0000001059148552_p135975361628"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="57.25%" id="mcps1.2.6.1.5"><p id="zh-cn_topic_0000001059148552_p13597136925"><a name="zh-cn_topic_0000001059148552_p13597136925"></a><a name="zh-cn_topic_0000001059148552_p13597136925"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001059148552_row165974360212"><td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001059148552_p21970268105"><a name="zh-cn_topic_0000001059148552_p21970268105"></a><a name="zh-cn_topic_0000001059148552_p21970268105"></a>startColor</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001059148552_p21981526141010"><a name="zh-cn_topic_0000001059148552_p21981526141010"></a><a name="zh-cn_topic_0000001059148552_p21981526141010"></a>Color</p>
</td>
<td class="cellrowborder" valign="top" width="9.83%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001059148552_p71988268108"><a name="zh-cn_topic_0000001059148552_p71988268108"></a><a name="zh-cn_topic_0000001059148552_p71988268108"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001059148552_p6597133616215"><a name="zh-cn_topic_0000001059148552_p6597133616215"></a><a name="zh-cn_topic_0000001059148552_p6597133616215"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="57.25%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001059148552_p5652139121119"><a name="zh-cn_topic_0000001059148552_p5652139121119"></a><a name="zh-cn_topic_0000001059148552_p5652139121119"></a>起始位置的颜色，设置startColor必须设置endColor。不设置startColor时，会使用系统默认预置的颜色数组，具体颜色值见下表。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row559719369213"><td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001059148552_p1419812651017"><a name="zh-cn_topic_0000001059148552_p1419812651017"></a><a name="zh-cn_topic_0000001059148552_p1419812651017"></a>endColor</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001059148552_p8198182631012"><a name="zh-cn_topic_0000001059148552_p8198182631012"></a><a name="zh-cn_topic_0000001059148552_p8198182631012"></a>Color</p>
</td>
<td class="cellrowborder" valign="top" width="9.83%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001059148552_p17198122612107"><a name="zh-cn_topic_0000001059148552_p17198122612107"></a><a name="zh-cn_topic_0000001059148552_p17198122612107"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001059148552_p059710361211"><a name="zh-cn_topic_0000001059148552_p059710361211"></a><a name="zh-cn_topic_0000001059148552_p059710361211"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="57.25%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001059148552_p11652139131117"><a name="zh-cn_topic_0000001059148552_p11652139131117"></a><a name="zh-cn_topic_0000001059148552_p11652139131117"></a>终止位置的颜色，设置endColor必须设置startColor。</p>
<p id="zh-cn_topic_0000001059148552_p10128174015175"><a name="zh-cn_topic_0000001059148552_p10128174015175"></a><a name="zh-cn_topic_0000001059148552_p10128174015175"></a>不设置startColor时，会使用系统默认预置的颜色数组。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row85973361925"><td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001059148552_p91981926191015"><a name="zh-cn_topic_0000001059148552_p91981926191015"></a><a name="zh-cn_topic_0000001059148552_p91981926191015"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001059148552_p1219813268100"><a name="zh-cn_topic_0000001059148552_p1219813268100"></a><a name="zh-cn_topic_0000001059148552_p1219813268100"></a>double</p>
</td>
<td class="cellrowborder" valign="top" width="9.83%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001059148552_p01988268105"><a name="zh-cn_topic_0000001059148552_p01988268105"></a><a name="zh-cn_topic_0000001059148552_p01988268105"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001059148552_p1959819361216"><a name="zh-cn_topic_0000001059148552_p1959819361216"></a><a name="zh-cn_topic_0000001059148552_p1959819361216"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="57.25%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001059148552_p106521339131120"><a name="zh-cn_topic_0000001059148552_p106521339131120"></a><a name="zh-cn_topic_0000001059148552_p106521339131120"></a>占比数据的所占份额，最大100。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row85983361124"><td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.2.6.1.1 "><p id="zh-cn_topic_0000001059148552_p1119816260101"><a name="zh-cn_topic_0000001059148552_p1119816260101"></a><a name="zh-cn_topic_0000001059148552_p1119816260101"></a>name</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.2.6.1.2 "><p id="zh-cn_topic_0000001059148552_p6198226161014"><a name="zh-cn_topic_0000001059148552_p6198226161014"></a><a name="zh-cn_topic_0000001059148552_p6198226161014"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.83%" headers="mcps1.2.6.1.3 "><p id="zh-cn_topic_0000001059148552_p1519852614107"><a name="zh-cn_topic_0000001059148552_p1519852614107"></a><a name="zh-cn_topic_0000001059148552_p1519852614107"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.2.6.1.4 "><p id="zh-cn_topic_0000001059148552_p25984367213"><a name="zh-cn_topic_0000001059148552_p25984367213"></a><a name="zh-cn_topic_0000001059148552_p25984367213"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="57.25%" headers="mcps1.2.6.1.5 "><p id="zh-cn_topic_0000001059148552_p11653339151117"><a name="zh-cn_topic_0000001059148552_p11653339151117"></a><a name="zh-cn_topic_0000001059148552_p11653339151117"></a>此类数据的名称。</p>
</td>
</tr>
</tbody>
</table>

<a name="zh-cn_topic_0000001059148552_table19699121263711"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001059148552_row106991512133715"><th class="cellrowborder" valign="top" width="5.8205820582058205%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001059148552_p9699181218379"><a name="zh-cn_topic_0000001059148552_p9699181218379"></a><a name="zh-cn_topic_0000001059148552_p9699181218379"></a>数据组</p>
</th>
<th class="cellrowborder" valign="top" width="41.7941794179418%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001059148552_p1699171219372"><a name="zh-cn_topic_0000001059148552_p1699171219372"></a><a name="zh-cn_topic_0000001059148552_p1699171219372"></a>浅色主题</p>
</th>
<th class="cellrowborder" valign="top" width="52.38523852385239%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001059148552_p16699112103710"><a name="zh-cn_topic_0000001059148552_p16699112103710"></a><a name="zh-cn_topic_0000001059148552_p16699112103710"></a>深色主题</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001059148552_row9699112163711"><td class="cellrowborder" valign="top" width="5.8205820582058205%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001059148552_p36992012193712"><a name="zh-cn_topic_0000001059148552_p36992012193712"></a><a name="zh-cn_topic_0000001059148552_p36992012193712"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="41.7941794179418%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001059148552_p15700712163717"><a name="zh-cn_topic_0000001059148552_p15700712163717"></a><a name="zh-cn_topic_0000001059148552_p15700712163717"></a>起始颜色：#f7ce00，结束颜色：#f99b11</p>
</td>
<td class="cellrowborder" valign="top" width="52.38523852385239%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001059148552_p5700512173712"><a name="zh-cn_topic_0000001059148552_p5700512173712"></a><a name="zh-cn_topic_0000001059148552_p5700512173712"></a>起始颜色：#d1a738，结束颜色：#eb933d</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row53180543816"><td class="cellrowborder" valign="top" width="5.8205820582058205%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001059148552_p931816516385"><a name="zh-cn_topic_0000001059148552_p931816516385"></a><a name="zh-cn_topic_0000001059148552_p931816516385"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="41.7941794179418%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001059148552_p2590113224315"><a name="zh-cn_topic_0000001059148552_p2590113224315"></a><a name="zh-cn_topic_0000001059148552_p2590113224315"></a>起始颜色：#f76223，结束颜色：#f2400a</p>
</td>
<td class="cellrowborder" valign="top" width="52.38523852385239%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001059148552_p153182553814"><a name="zh-cn_topic_0000001059148552_p153182553814"></a><a name="zh-cn_topic_0000001059148552_p153182553814"></a>起始颜色：#e67d50，结束颜色：#d9542b</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row5161209163810"><td class="cellrowborder" valign="top" width="5.8205820582058205%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001059148552_p1616120910383"><a name="zh-cn_topic_0000001059148552_p1616120910383"></a><a name="zh-cn_topic_0000001059148552_p1616120910383"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="41.7941794179418%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001059148552_p91616973812"><a name="zh-cn_topic_0000001059148552_p91616973812"></a><a name="zh-cn_topic_0000001059148552_p91616973812"></a>起始颜色：#f772ac，结束颜色：#e65392</p>
</td>
<td class="cellrowborder" valign="top" width="52.38523852385239%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001059148552_p2161189183817"><a name="zh-cn_topic_0000001059148552_p2161189183817"></a><a name="zh-cn_topic_0000001059148552_p2161189183817"></a>起始颜色：#d5749e，结束颜色：#d6568d</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row956361913385"><td class="cellrowborder" valign="top" width="5.8205820582058205%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001059148552_p12563181918388"><a name="zh-cn_topic_0000001059148552_p12563181918388"></a><a name="zh-cn_topic_0000001059148552_p12563181918388"></a>3</p>
</td>
<td class="cellrowborder" valign="top" width="41.7941794179418%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001059148552_p25633192386"><a name="zh-cn_topic_0000001059148552_p25633192386"></a><a name="zh-cn_topic_0000001059148552_p25633192386"></a>起始颜色：#a575eb，结束颜色：#a12df7</p>
</td>
<td class="cellrowborder" valign="top" width="52.38523852385239%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001059148552_p25631219183815"><a name="zh-cn_topic_0000001059148552_p25631219183815"></a><a name="zh-cn_topic_0000001059148552_p25631219183815"></a>起始颜色：#9973d1，结束颜色：#5552d9</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row893012813389"><td class="cellrowborder" valign="top" width="5.8205820582058205%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001059148552_p1393092815385"><a name="zh-cn_topic_0000001059148552_p1393092815385"></a><a name="zh-cn_topic_0000001059148552_p1393092815385"></a>4</p>
</td>
<td class="cellrowborder" valign="top" width="41.7941794179418%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001059148552_p493092812387"><a name="zh-cn_topic_0000001059148552_p493092812387"></a><a name="zh-cn_topic_0000001059148552_p493092812387"></a>起始颜色：#7b79f7，结束颜色：#4b48f7</p>
</td>
<td class="cellrowborder" valign="top" width="52.38523852385239%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001059148552_p6930228123813"><a name="zh-cn_topic_0000001059148552_p6930228123813"></a><a name="zh-cn_topic_0000001059148552_p6930228123813"></a>起始颜色：#7977d9，结束颜色：#f99b11</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row11109426123812"><td class="cellrowborder" valign="top" width="5.8205820582058205%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001059148552_p1010912612382"><a name="zh-cn_topic_0000001059148552_p1010912612382"></a><a name="zh-cn_topic_0000001059148552_p1010912612382"></a>5</p>
</td>
<td class="cellrowborder" valign="top" width="41.7941794179418%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001059148552_p4109026173811"><a name="zh-cn_topic_0000001059148552_p4109026173811"></a><a name="zh-cn_topic_0000001059148552_p4109026173811"></a>起始颜色：#4b8af3，结束颜色：#007dff</p>
</td>
<td class="cellrowborder" valign="top" width="52.38523852385239%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001059148552_p2109026173816"><a name="zh-cn_topic_0000001059148552_p2109026173816"></a><a name="zh-cn_topic_0000001059148552_p2109026173816"></a>起始颜色：#4c81d9，结束颜色：#217bd9</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row1569813163818"><td class="cellrowborder" valign="top" width="5.8205820582058205%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001059148552_p196911318389"><a name="zh-cn_topic_0000001059148552_p196911318389"></a><a name="zh-cn_topic_0000001059148552_p196911318389"></a>6</p>
</td>
<td class="cellrowborder" valign="top" width="41.7941794179418%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001059148552_p186971323817"><a name="zh-cn_topic_0000001059148552_p186971323817"></a><a name="zh-cn_topic_0000001059148552_p186971323817"></a>起始颜色：#73c1e6，结束颜色：#4fb4e3</p>
</td>
<td class="cellrowborder" valign="top" width="52.38523852385239%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001059148552_p169513183810"><a name="zh-cn_topic_0000001059148552_p169513183810"></a><a name="zh-cn_topic_0000001059148552_p169513183810"></a>起始颜色：#5ea6d1，结束颜色：#4895c2</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row1428922313819"><td class="cellrowborder" valign="top" width="5.8205820582058205%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001059148552_p628912231384"><a name="zh-cn_topic_0000001059148552_p628912231384"></a><a name="zh-cn_topic_0000001059148552_p628912231384"></a>7</p>
</td>
<td class="cellrowborder" valign="top" width="41.7941794179418%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001059148552_p0289823193820"><a name="zh-cn_topic_0000001059148552_p0289823193820"></a><a name="zh-cn_topic_0000001059148552_p0289823193820"></a>起始颜色：#a5d61d，结束颜色：#69d14f</p>
</td>
<td class="cellrowborder" valign="top" width="52.38523852385239%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001059148552_p12289192316386"><a name="zh-cn_topic_0000001059148552_p12289192316386"></a><a name="zh-cn_topic_0000001059148552_p12289192316386"></a>起始颜色：#91c23a，结束颜色：#70ba5d</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row10565416153819"><td class="cellrowborder" valign="top" width="5.8205820582058205%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001059148552_p156516165388"><a name="zh-cn_topic_0000001059148552_p156516165388"></a><a name="zh-cn_topic_0000001059148552_p156516165388"></a>8</p>
</td>
<td class="cellrowborder" valign="top" width="41.7941794179418%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001059148552_p175652016143816"><a name="zh-cn_topic_0000001059148552_p175652016143816"></a><a name="zh-cn_topic_0000001059148552_p175652016143816"></a>起始颜色：#a2a2b0，结束颜色：#8e8e93</p>
</td>
<td class="cellrowborder" valign="top" width="52.38523852385239%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001059148552_p5565101633813"><a name="zh-cn_topic_0000001059148552_p5565101633813"></a><a name="zh-cn_topic_0000001059148552_p5565101633813"></a>起始颜色：#8c8c99，结束颜色：#6b6b76</p>
</td>
</tr>
</tbody>
</table>

当类型为量规图时，还支持如下属性：

<a name="zh-cn_topic_0000001059148552_table591221715358"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001059148552_row7912417143518"><th class="cellrowborder" valign="top" width="23.52%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001059148552_p19912161763516"><a name="zh-cn_topic_0000001059148552_p19912161763516"></a><a name="zh-cn_topic_0000001059148552_p19912161763516"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="11.76%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001059148552_p11912151718350"><a name="zh-cn_topic_0000001059148552_p11912151718350"></a><a name="zh-cn_topic_0000001059148552_p11912151718350"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="11.72%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001059148552_p1791231713518"><a name="zh-cn_topic_0000001059148552_p1791231713518"></a><a name="zh-cn_topic_0000001059148552_p1791231713518"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="8%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001059148552_p7913161710357"><a name="zh-cn_topic_0000001059148552_p7913161710357"></a><a name="zh-cn_topic_0000001059148552_p7913161710357"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="45%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001059148552_p9913111717353"><a name="zh-cn_topic_0000001059148552_p9913111717353"></a><a name="zh-cn_topic_0000001059148552_p9913111717353"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001059148552_row99131917123518"><td class="cellrowborder" valign="top" width="23.52%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001059148552_p1091312179351"><a name="zh-cn_topic_0000001059148552_p1091312179351"></a><a name="zh-cn_topic_0000001059148552_p1091312179351"></a>percent</p>
</td>
<td class="cellrowborder" valign="top" width="11.76%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001059148552_p20913111723518"><a name="zh-cn_topic_0000001059148552_p20913111723518"></a><a name="zh-cn_topic_0000001059148552_p20913111723518"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.72%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001059148552_p891361723510"><a name="zh-cn_topic_0000001059148552_p891361723510"></a><a name="zh-cn_topic_0000001059148552_p891361723510"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="8%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001059148552_p1913151711357"><a name="zh-cn_topic_0000001059148552_p1913151711357"></a><a name="zh-cn_topic_0000001059148552_p1913151711357"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="45%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001059148552_p39134178350"><a name="zh-cn_topic_0000001059148552_p39134178350"></a><a name="zh-cn_topic_0000001059148552_p39134178350"></a>当前值占整体的百分比，取值范围为0-100。</p>
</td>
</tr>
</tbody>
</table>

## 方法<a name="zh-cn_topic_0000001059148552_section5955645132417"></a>

<a name="zh-cn_topic_0000001059148552_table826516417256"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001059148552_row3266741172514"><th class="cellrowborder" valign="top" width="8.630863086308631%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001059148552_p7266164172516"><a name="zh-cn_topic_0000001059148552_p7266164172516"></a><a name="zh-cn_topic_0000001059148552_p7266164172516"></a>方法</p>
</th>
<th class="cellrowborder" valign="top" width="58.035803580358035%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001059148552_p2266184113251"><a name="zh-cn_topic_0000001059148552_p2266184113251"></a><a name="zh-cn_topic_0000001059148552_p2266184113251"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001059148552_p1226616411255"><a name="zh-cn_topic_0000001059148552_p1226616411255"></a><a name="zh-cn_topic_0000001059148552_p1226616411255"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001059148552_row172666416259"><td class="cellrowborder" valign="top" width="8.630863086308631%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001059148552_p526615416255"><a name="zh-cn_topic_0000001059148552_p526615416255"></a><a name="zh-cn_topic_0000001059148552_p526615416255"></a>append</p>
</td>
<td class="cellrowborder" valign="top" width="58.035803580358035%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001059148552_p962415556399"><a name="zh-cn_topic_0000001059148552_p962415556399"></a><a name="zh-cn_topic_0000001059148552_p962415556399"></a>{</p>
<p id="zh-cn_topic_0000001059148552_p118975913395"><a name="zh-cn_topic_0000001059148552_p118975913395"></a><a name="zh-cn_topic_0000001059148552_p118975913395"></a>serial: number, // 设置要更新的线形图数据下标</p>
<p id="zh-cn_topic_0000001059148552_p191641035401"><a name="zh-cn_topic_0000001059148552_p191641035401"></a><a name="zh-cn_topic_0000001059148552_p191641035401"></a>data: Array&lt;number&gt;, // 设置新增的数据</p>
<p id="zh-cn_topic_0000001059148552_p10266114120253"><a name="zh-cn_topic_0000001059148552_p10266114120253"></a><a name="zh-cn_topic_0000001059148552_p10266114120253"></a>}</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001059148552_p1526615419258"><a name="zh-cn_topic_0000001059148552_p1526615419258"></a><a name="zh-cn_topic_0000001059148552_p1526615419258"></a>往已有的数据序列中动态添加数据，根据serial指定目标序列，serial为datasets数组的下标，从0开始。注意：不会更新datasets[index].data。仅线形图支持，按横坐标加1递增（与xAxis min/max设置相关）。</p>
</td>
</tr>
</tbody>
</table>

## 事件<a name="zh-cn_topic_0000001059148552_section749131815264"></a>

<a name="zh-cn_topic_0000001059148552_table836435619510"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_rf3d0da15d2f64cd492dfa1e7d98890a5"><th class="cellrowborder" valign="top" width="16.18%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_a487aa1c493e84ca68567b4b65051674d"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_a487aa1c493e84ca68567b4b65051674d"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_a487aa1c493e84ca68567b4b65051674d"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="21.89%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_adc4b506cda3043508da6ee7649c12ca4"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_adc4b506cda3043508da6ee7649c12ca4"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_adc4b506cda3043508da6ee7649c12ca4"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="61.92999999999999%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_a59e4cbe58a5c42a7a4585bc8365783bc"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_a59e4cbe58a5c42a7a4585bc8365783bc"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_a59e4cbe58a5c42a7a4585bc8365783bc"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_r7683acd1d0964f31840d03c9aeb32fca"><td class="cellrowborder" valign="top" width="16.18%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_a58fb4b1d870f466e955cf5ea879c4d4a"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_a58fb4b1d870f466e955cf5ea879c4d4a"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_a58fb4b1d870f466e955cf5ea879c4d4a"></a>touchstart</p>
</td>
<td class="cellrowborder" valign="top" width="21.89%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_abefebd99301b4bdebb798d1b9df24d8d"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_abefebd99301b4bdebb798d1b9df24d8d"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_abefebd99301b4bdebb798d1b9df24d8d"></a><a href="通用事件.md#zh-cn_topic_0000001058460527_tdb541af4e4db41d7a92e9b6e3c93f606">TouchEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="61.92999999999999%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_afa4290e2620f4f5fbdcb74dcae84e536"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_afa4290e2620f4f5fbdcb74dcae84e536"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_afa4290e2620f4f5fbdcb74dcae84e536"></a>手指刚触摸屏幕时触发该事件。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_r7f70ef6c895e4d2d95325887fee7d62e"><td class="cellrowborder" valign="top" width="16.18%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_a23e0317cfee94650be4dcd2280c3e94e"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_a23e0317cfee94650be4dcd2280c3e94e"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_a23e0317cfee94650be4dcd2280c3e94e"></a>touchmove</p>
</td>
<td class="cellrowborder" valign="top" width="21.89%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_aea26e4f9575044dc8fb65080f3a6684a"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_aea26e4f9575044dc8fb65080f3a6684a"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_aea26e4f9575044dc8fb65080f3a6684a"></a><a href="通用事件.md#zh-cn_topic_0000001058460527_tdb541af4e4db41d7a92e9b6e3c93f606">TouchEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="61.92999999999999%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_a37f7cc43d82c4ee18512bd079349079d"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_a37f7cc43d82c4ee18512bd079349079d"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_a37f7cc43d82c4ee18512bd079349079d"></a>手指触摸屏幕后移动时触发该事件。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_ra5c278d41f9045ed9d95e13165974bf4"><td class="cellrowborder" valign="top" width="16.18%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_ad0728eeac06143bbb4a6fdf1ed5c6d91"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_ad0728eeac06143bbb4a6fdf1ed5c6d91"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_ad0728eeac06143bbb4a6fdf1ed5c6d91"></a>touchcancel</p>
</td>
<td class="cellrowborder" valign="top" width="21.89%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_a59e2819eae2b4d3e935991b43156347b"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_a59e2819eae2b4d3e935991b43156347b"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_a59e2819eae2b4d3e935991b43156347b"></a><a href="通用事件.md#zh-cn_topic_0000001058460527_tdb541af4e4db41d7a92e9b6e3c93f606">TouchEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="61.92999999999999%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_a739d9ef0db624f6284554aeaeddffa0a"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_a739d9ef0db624f6284554aeaeddffa0a"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_a739d9ef0db624f6284554aeaeddffa0a"></a>手指触摸屏幕中动作被打断时触发该事件。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_rddfe06969173404d96b60c402a7e783c"><td class="cellrowborder" valign="top" width="16.18%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_a233e2f6ff39f49fd97b8f233875d01d4"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_a233e2f6ff39f49fd97b8f233875d01d4"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_a233e2f6ff39f49fd97b8f233875d01d4"></a>touchend</p>
</td>
<td class="cellrowborder" valign="top" width="21.89%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_a439e69aaf158448e99b3c81cbc9fd624"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_a439e69aaf158448e99b3c81cbc9fd624"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_a439e69aaf158448e99b3c81cbc9fd624"></a><a href="通用事件.md#zh-cn_topic_0000001058460527_tdb541af4e4db41d7a92e9b6e3c93f606">TouchEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="61.92999999999999%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_a05c0fe4e05ef4154acee8a06ad56a2de"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_a05c0fe4e05ef4154acee8a06ad56a2de"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_a05c0fe4e05ef4154acee8a06ad56a2de"></a>手指触摸结束离开屏幕时触发该事件。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_rec1121b8bebc4a3f9ed9a906d061746e"><td class="cellrowborder" valign="top" width="16.18%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_a2fb4de45b1594f6fa1a7da45ce0db57f"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_a2fb4de45b1594f6fa1a7da45ce0db57f"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_a2fb4de45b1594f6fa1a7da45ce0db57f"></a>click</p>
</td>
<td class="cellrowborder" valign="top" width="21.89%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_af86bf1da40504ed2a8d14213a42536ab"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_af86bf1da40504ed2a8d14213a42536ab"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_af86bf1da40504ed2a8d14213a42536ab"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="61.92999999999999%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_a1d32f00c38c440ddaa63c3f3e01d4e09"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_a1d32f00c38c440ddaa63c3f3e01d4e09"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_a1d32f00c38c440ddaa63c3f3e01d4e09"></a>点击动作触发该事件。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_r95f500ef9402487ea42e829d69606f90"><td class="cellrowborder" valign="top" width="16.18%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_aa7dc63d1b4924872bbff6a6a100e928f"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_aa7dc63d1b4924872bbff6a6a100e928f"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_aa7dc63d1b4924872bbff6a6a100e928f"></a>longpress</p>
</td>
<td class="cellrowborder" valign="top" width="21.89%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_a39186f4ff74544d89ace56ea87d9937b"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_a39186f4ff74544d89ace56ea87d9937b"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_a39186f4ff74544d89ace56ea87d9937b"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="61.92999999999999%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_a44b8585170304b5596c41714772e605e"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_a44b8585170304b5596c41714772e605e"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_a44b8585170304b5596c41714772e605e"></a>长按动作触发该事件。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_row117014569616"><td class="cellrowborder" valign="top" width="16.18%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_p12706561061"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_p12706561061"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_p12706561061"></a>swipe<sup id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_sup35424382912"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_sup35424382912"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_sup35424382912"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="21.89%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_p11711056161"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_p11711056161"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_p11711056161"></a><a href="通用事件.md#zh-cn_topic_0000001058460527_table111811577714">SwipeEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="61.92999999999999%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_p2711556162"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_p2711556162"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001058460527_p2711556162"></a>组件上快速滑动后触发。</p>
</td>
</tr>
</tbody>
</table>

## 样式<a name="zh-cn_topic_0000001059148552_section5775351116"></a>

<a name="zh-cn_topic_0000001059148552_table124404442319"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001059148552_row244104482316"><th class="cellrowborder" valign="top" width="23.11768823117688%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a14a0c012a26248cfbec6b13dcc4f2cbe"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a14a0c012a26248cfbec6b13dcc4f2cbe"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a14a0c012a26248cfbec6b13dcc4f2cbe"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="20.477952204779523%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a8dc328a555a74157a00de86181fc3a7b"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a8dc328a555a74157a00de86181fc3a7b"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a8dc328a555a74157a00de86181fc3a7b"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="8.869113088691131%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a41a31e48d0c74ad4982add2655515c82"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a41a31e48d0c74ad4982add2655515c82"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a41a31e48d0c74ad4982add2655515c82"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.519248075192481%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001059148552_p124544472310"><a name="zh-cn_topic_0000001059148552_p124544472310"></a><a name="zh-cn_topic_0000001059148552_p124544472310"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="40.01599840015999%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_af7a726e456f7485c87bd4e0527bc6584"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_af7a726e456f7485c87bd4e0527bc6584"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_af7a726e456f7485c87bd4e0527bc6584"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001059148552_row17669103214585"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001059148552_p7998445185811"><a name="zh-cn_topic_0000001059148552_p7998445185811"></a><a name="zh-cn_topic_0000001059148552_p7998445185811"></a>stroke-width</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001059148552_p69981045185815"><a name="zh-cn_topic_0000001059148552_p69981045185815"></a><a name="zh-cn_topic_0000001059148552_p69981045185815"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001059148552_p399924517587"><a name="zh-cn_topic_0000001059148552_p399924517587"></a><a name="zh-cn_topic_0000001059148552_p399924517587"></a>32px（量规）</p>
<p id="zh-cn_topic_0000001059148552_p496875411249"><a name="zh-cn_topic_0000001059148552_p496875411249"></a><a name="zh-cn_topic_0000001059148552_p496875411249"></a>24px（占比类圆形图表）</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001059148552_p119991145175819"><a name="zh-cn_topic_0000001059148552_p119991145175819"></a><a name="zh-cn_topic_0000001059148552_p119991145175819"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001059148552_p169991245175817"><a name="zh-cn_topic_0000001059148552_p169991245175817"></a><a name="zh-cn_topic_0000001059148552_p169991245175817"></a>量规<span id="zh-cn_topic_0000001059148552_ph058224162417"><a name="zh-cn_topic_0000001059148552_ph058224162417"></a><a name="zh-cn_topic_0000001059148552_ph058224162417"></a>、占比类圆形图表</span>组件刻度条的宽度。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row267010322582"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001059148552_p19991145195813"><a name="zh-cn_topic_0000001059148552_p19991145195813"></a><a name="zh-cn_topic_0000001059148552_p19991145195813"></a>start-angle</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001059148552_p099994545812"><a name="zh-cn_topic_0000001059148552_p099994545812"></a><a name="zh-cn_topic_0000001059148552_p099994545812"></a>&lt;deg&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001059148552_p1599934517582"><a name="zh-cn_topic_0000001059148552_p1599934517582"></a><a name="zh-cn_topic_0000001059148552_p1599934517582"></a>240（量规）</p>
<p id="zh-cn_topic_0000001059148552_p18138163412238"><a name="zh-cn_topic_0000001059148552_p18138163412238"></a><a name="zh-cn_topic_0000001059148552_p18138163412238"></a>0（占比类圆形图表）</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001059148552_p59994457581"><a name="zh-cn_topic_0000001059148552_p59994457581"></a><a name="zh-cn_topic_0000001059148552_p59994457581"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001059148552_p1099914513588"><a name="zh-cn_topic_0000001059148552_p1099914513588"></a><a name="zh-cn_topic_0000001059148552_p1099914513588"></a>量规<span id="zh-cn_topic_0000001059148552_ph89237454228"><a name="zh-cn_topic_0000001059148552_ph89237454228"></a><a name="zh-cn_topic_0000001059148552_ph89237454228"></a>、占比类圆形图表</span>组件刻度条起始角度，以时钟0点为基线。范围为0到360。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row10670143216582"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001059148552_p11999445135820"><a name="zh-cn_topic_0000001059148552_p11999445135820"></a><a name="zh-cn_topic_0000001059148552_p11999445135820"></a>total-angle</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001059148552_p49998454589"><a name="zh-cn_topic_0000001059148552_p49998454589"></a><a name="zh-cn_topic_0000001059148552_p49998454589"></a>&lt;deg&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001059148552_p299913451581"><a name="zh-cn_topic_0000001059148552_p299913451581"></a><a name="zh-cn_topic_0000001059148552_p299913451581"></a>240（量规）</p>
<p id="zh-cn_topic_0000001059148552_p1539919952411"><a name="zh-cn_topic_0000001059148552_p1539919952411"></a><a name="zh-cn_topic_0000001059148552_p1539919952411"></a>360（占比类圆形图表）</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001059148552_p199984585810"><a name="zh-cn_topic_0000001059148552_p199984585810"></a><a name="zh-cn_topic_0000001059148552_p199984585810"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001059148552_p169991545145820"><a name="zh-cn_topic_0000001059148552_p169991545145820"></a><a name="zh-cn_topic_0000001059148552_p169991545145820"></a>量规<span id="zh-cn_topic_0000001059148552_ph1865121432318"><a name="zh-cn_topic_0000001059148552_ph1865121432318"></a><a name="zh-cn_topic_0000001059148552_ph1865121432318"></a>、占比类圆形图表</span>组件刻度条总长度，范围为-360到360，负数标识起点到终点为逆时针。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row1967063205815"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001059148552_p1299915458588"><a name="zh-cn_topic_0000001059148552_p1299915458588"></a><a name="zh-cn_topic_0000001059148552_p1299915458588"></a>center-x</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001059148552_p12999154515819"><a name="zh-cn_topic_0000001059148552_p12999154515819"></a><a name="zh-cn_topic_0000001059148552_p12999154515819"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001059148552_p20146205816"><a name="zh-cn_topic_0000001059148552_p20146205816"></a><a name="zh-cn_topic_0000001059148552_p20146205816"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001059148552_p60144615819"><a name="zh-cn_topic_0000001059148552_p60144615819"></a><a name="zh-cn_topic_0000001059148552_p60144615819"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001059148552_p12015465581"><a name="zh-cn_topic_0000001059148552_p12015465581"></a><a name="zh-cn_topic_0000001059148552_p12015465581"></a>量规组件刻度条中心位置，该样式优先于通用样式的position样式。该样式需要和center-y和radius一起配置才能生效。（仅量规图支持）</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row18269202217586"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001059148552_p13024605818"><a name="zh-cn_topic_0000001059148552_p13024605818"></a><a name="zh-cn_topic_0000001059148552_p13024605818"></a>center-y</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001059148552_p90114645817"><a name="zh-cn_topic_0000001059148552_p90114645817"></a><a name="zh-cn_topic_0000001059148552_p90114645817"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001059148552_p60546165812"><a name="zh-cn_topic_0000001059148552_p60546165812"></a><a name="zh-cn_topic_0000001059148552_p60546165812"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001059148552_p50846185813"><a name="zh-cn_topic_0000001059148552_p50846185813"></a><a name="zh-cn_topic_0000001059148552_p50846185813"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001059148552_p17054610588"><a name="zh-cn_topic_0000001059148552_p17054610588"></a><a name="zh-cn_topic_0000001059148552_p17054610588"></a>量规组件刻度条中心位置，该样式优先于通用样式的position样式。该样式需要和center-x和radius一起配置才能生效。（仅量规图支持）</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row1264611017585"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001059148552_p10034655819"><a name="zh-cn_topic_0000001059148552_p10034655819"></a><a name="zh-cn_topic_0000001059148552_p10034655819"></a>radius</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001059148552_p60746145819"><a name="zh-cn_topic_0000001059148552_p60746145819"></a><a name="zh-cn_topic_0000001059148552_p60746145819"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001059148552_p40104655820"><a name="zh-cn_topic_0000001059148552_p40104655820"></a><a name="zh-cn_topic_0000001059148552_p40104655820"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001059148552_p15018469585"><a name="zh-cn_topic_0000001059148552_p15018469585"></a><a name="zh-cn_topic_0000001059148552_p15018469585"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001059148552_p13010468584"><a name="zh-cn_topic_0000001059148552_p13010468584"></a><a name="zh-cn_topic_0000001059148552_p13010468584"></a>量规组件刻度条半径，该样式优先于通用样式的width和height样式。该样式需要和center-x和center-y一起配置才能生效。（仅量规图支持）</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row6213184185812"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001059148552_p130104612581"><a name="zh-cn_topic_0000001059148552_p130104612581"></a><a name="zh-cn_topic_0000001059148552_p130104612581"></a>colors</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001059148552_p1608468585"><a name="zh-cn_topic_0000001059148552_p1608468585"></a><a name="zh-cn_topic_0000001059148552_p1608468585"></a>Array</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001059148552_p13084655814"><a name="zh-cn_topic_0000001059148552_p13084655814"></a><a name="zh-cn_topic_0000001059148552_p13084655814"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001059148552_p1311346145814"><a name="zh-cn_topic_0000001059148552_p1311346145814"></a><a name="zh-cn_topic_0000001059148552_p1311346145814"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001059148552_p1411446105819"><a name="zh-cn_topic_0000001059148552_p1411446105819"></a><a name="zh-cn_topic_0000001059148552_p1411446105819"></a>量规组件刻度条每一个区段的颜色。</p>
<p id="zh-cn_topic_0000001059148552_p1515461580"><a name="zh-cn_topic_0000001059148552_p1515461580"></a><a name="zh-cn_topic_0000001059148552_p1515461580"></a>如：colors: #ff0000, #00ff00。（仅量规图支持）</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row151804815583"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001059148552_p31246165816"><a name="zh-cn_topic_0000001059148552_p31246165816"></a><a name="zh-cn_topic_0000001059148552_p31246165816"></a>weights</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001059148552_p812046125810"><a name="zh-cn_topic_0000001059148552_p812046125810"></a><a name="zh-cn_topic_0000001059148552_p812046125810"></a>Array</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001059148552_p171046155813"><a name="zh-cn_topic_0000001059148552_p171046155813"></a><a name="zh-cn_topic_0000001059148552_p171046155813"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001059148552_p8174615582"><a name="zh-cn_topic_0000001059148552_p8174615582"></a><a name="zh-cn_topic_0000001059148552_p8174615582"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001059148552_p8117461589"><a name="zh-cn_topic_0000001059148552_p8117461589"></a><a name="zh-cn_topic_0000001059148552_p8117461589"></a>量规组件刻度条每一个区段的权重。</p>
<p id="zh-cn_topic_0000001059148552_p141134635812"><a name="zh-cn_topic_0000001059148552_p141134635812"></a><a name="zh-cn_topic_0000001059148552_p141134635812"></a>如：weights: 2, 2。（仅量规图支持）</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row4208131313017"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001059148552_p1120821312307"><a name="zh-cn_topic_0000001059148552_p1120821312307"></a><a name="zh-cn_topic_0000001059148552_p1120821312307"></a>font-family<sup id="zh-cn_topic_0000001059148552_sup1710278132714"><a name="zh-cn_topic_0000001059148552_sup1710278132714"></a><a name="zh-cn_topic_0000001059148552_sup1710278132714"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001059148552_p7208613163010"><a name="zh-cn_topic_0000001059148552_p7208613163010"></a><a name="zh-cn_topic_0000001059148552_p7208613163010"></a>Array</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001059148552_p172081613163020"><a name="zh-cn_topic_0000001059148552_p172081613163020"></a><a name="zh-cn_topic_0000001059148552_p172081613163020"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001059148552_p120812138308"><a name="zh-cn_topic_0000001059148552_p120812138308"></a><a name="zh-cn_topic_0000001059148552_p120812138308"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001059148552_p9208131313017"><a name="zh-cn_topic_0000001059148552_p9208131313017"></a><a name="zh-cn_topic_0000001059148552_p9208131313017"></a>表示绘制注释的字体样式，支持<a href="自定义字体样式.md#ZH-CN_TOPIC_0000001162414611">自定义字体</a>。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row118919117314"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001059148552_p7892161116317"><a name="zh-cn_topic_0000001059148552_p7892161116317"></a><a name="zh-cn_topic_0000001059148552_p7892161116317"></a>font-size<sup id="zh-cn_topic_0000001059148552_sup17808141112279"><a name="zh-cn_topic_0000001059148552_sup17808141112279"></a><a name="zh-cn_topic_0000001059148552_sup17808141112279"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001059148552_p138921611123116"><a name="zh-cn_topic_0000001059148552_p138921611123116"></a><a name="zh-cn_topic_0000001059148552_p138921611123116"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001059148552_p168921111183112"><a name="zh-cn_topic_0000001059148552_p168921111183112"></a><a name="zh-cn_topic_0000001059148552_p168921111183112"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001059148552_p15892181113114"><a name="zh-cn_topic_0000001059148552_p15892181113114"></a><a name="zh-cn_topic_0000001059148552_p15892181113114"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001059148552_p389213115318"><a name="zh-cn_topic_0000001059148552_p389213115318"></a><a name="zh-cn_topic_0000001059148552_p389213115318"></a>表示绘制注释的字体的大小。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row2045114414233"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a8bc81ecef4934adf91deb1d6167045d7"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a8bc81ecef4934adf91deb1d6167045d7"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a8bc81ecef4934adf91deb1d6167045d7"></a>width</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a59692217b9c94353a020a2f0a20f01a7"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a59692217b9c94353a020a2f0a20f01a7"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a59692217b9c94353a020a2f0a20f01a7"></a>&lt;length&gt; | &lt;percentage&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p3948114217528"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p3948114217528"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p3948114217528"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001059148552_p1045104416236"><a name="zh-cn_topic_0000001059148552_p1045104416236"></a><a name="zh-cn_topic_0000001059148552_p1045104416236"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p624653010258"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p624653010258"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p624653010258"></a>设置组件自身的宽度。</p>
<p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p84811050134010"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p84811050134010"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p84811050134010"></a>缺省时使用元素自身内容需要的宽度。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row64520448231"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a738cc687552c4b8cb1aa9f9e7d9ea8c2"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a738cc687552c4b8cb1aa9f9e7d9ea8c2"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a738cc687552c4b8cb1aa9f9e7d9ea8c2"></a>height</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a82c5d9c65b3646ec92afe5f0f47a2149"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a82c5d9c65b3646ec92afe5f0f47a2149"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a82c5d9c65b3646ec92afe5f0f47a2149"></a>&lt;length&gt;<span id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ph11748352163918"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ph11748352163918"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ph11748352163918"></a></span> | &lt;percentage&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a7e6c7daafecf475888d0420835662eb4"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a7e6c7daafecf475888d0420835662eb4"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a7e6c7daafecf475888d0420835662eb4"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001059148552_p3461344132317"><a name="zh-cn_topic_0000001059148552_p3461344132317"></a><a name="zh-cn_topic_0000001059148552_p3461344132317"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p1477601264"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p1477601264"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p1477601264"></a>设置组件自身的高度。</p>
<p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p208761554184020"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p208761554184020"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p208761554184020"></a>缺省时使用元素自身内容需要的高度。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row84624411233"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a8ff18465b8f0453c836067e5902b7eb6"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a8ff18465b8f0453c836067e5902b7eb6"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a8ff18465b8f0453c836067e5902b7eb6"></a>padding</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a53628f36a25a4823a901d5b66860f44e"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a53628f36a25a4823a901d5b66860f44e"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a53628f36a25a4823a901d5b66860f44e"></a>&lt;length&gt; | &lt;percentage&gt;<sup id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_sup1886516813013"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_sup1886516813013"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_sup1886516813013"></a><span>5+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_adc824deaee924821a47a798b589f22c8"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_adc824deaee924821a47a798b589f22c8"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_adc824deaee924821a47a798b589f22c8"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p19729127112814"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p19729127112814"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p19729127112814"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p157435053316"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p157435053316"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p157435053316"></a>使用简写属性设置所有的内边距属性。</p>
<div class="p" id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a68a6d5ddc59c49f0aaddd82e75932524"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a68a6d5ddc59c49f0aaddd82e75932524"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a68a6d5ddc59c49f0aaddd82e75932524"></a>该属性可以有1到4个值：<a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ul15202134923211"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ul15202134923211"></a><ul id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ul15202134923211"><li><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p10614155353215"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p10614155353215"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p10614155353215"></a>指定一个值时，该值指定四个边的内边距。</p>
</li><li><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p10614175393216"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p10614175393216"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p10614175393216"></a>指定两个值时，第一个值指定上下两边的内边距，第二个指定左右两边的内边距。</p>
</li><li><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p8614205393214"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p8614205393214"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p8614205393214"></a>指定三个值时，第一个指定上边的内边距，第二个指定左右两边的内边距，第三个指定下边的内边距。</p>
</li><li><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p106141853193215"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p106141853193215"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p106141853193215"></a>指定四个值时分别为上、右、下、左边的内边距（顺时针顺序）。</p>
</li></ul>
</div>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row1047174420236"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ab0185a7b5a4944f3b38f8c71c8ca794d"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ab0185a7b5a4944f3b38f8c71c8ca794d"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ab0185a7b5a4944f3b38f8c71c8ca794d"></a>padding-[left|top|right|bottom]</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a49dd523e2f1b4253a19231e776dc1951"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a49dd523e2f1b4253a19231e776dc1951"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a49dd523e2f1b4253a19231e776dc1951"></a>&lt;length&gt; | &lt;percentage&gt;<sup id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_sup19949912807"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_sup19949912807"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_sup19949912807"></a><span>5+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_af52ecd93919b4fa08ae4d376e3d544a2"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_af52ecd93919b4fa08ae4d376e3d544a2"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_af52ecd93919b4fa08ae4d376e3d544a2"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p11729374289"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p11729374289"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p11729374289"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a3575ab240d384ab1a21119ea3428ab7d"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a3575ab240d384ab1a21119ea3428ab7d"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a3575ab240d384ab1a21119ea3428ab7d"></a>设置左、上、右、下内边距属性。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row74764442310"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p769124717365"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p769124717365"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p769124717365"></a>padding-[start|end]</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p157617124374"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p157617124374"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p157617124374"></a>&lt;length&gt; | &lt;percentage&gt;<sup id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_sup8490161513019"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_sup8490161513019"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_sup8490161513019"></a><span>5+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p1069144703616"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p1069144703616"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p1069144703616"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p1373027182819"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p1373027182819"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p1373027182819"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p1269184753610"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p1269184753610"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p1269184753610"></a>设置起始和末端内边距属性。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row148104492318"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_afa508e5429d948b2b561943d6b2f0f31"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_afa508e5429d948b2b561943d6b2f0f31"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_afa508e5429d948b2b561943d6b2f0f31"></a>margin</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a4dab4f9d97a74a27a45b7ef1d2ab08e6"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a4dab4f9d97a74a27a45b7ef1d2ab08e6"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a4dab4f9d97a74a27a45b7ef1d2ab08e6"></a>&lt;length&gt; | &lt;percentage&gt;<sup id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_sup1433352175220"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_sup1433352175220"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_sup1433352175220"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a5e3c234d78214e8180b51d237adda154"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a5e3c234d78214e8180b51d237adda154"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a5e3c234d78214e8180b51d237adda154"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p4730774285"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p4730774285"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p4730774285"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a1d350e36a773420baf5ebb930cd5ad66"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a1d350e36a773420baf5ebb930cd5ad66"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a1d350e36a773420baf5ebb930cd5ad66"></a>使用简写属性设置所有的外边距属性，该属性可以有1到4个值。</p>
<a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ul5333133311105"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ul5333133311105"></a><ul id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ul5333133311105"><li><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p03345339103"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p03345339103"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p03345339103"></a>只有一个值时，这个值会被指定给全部的四个边。</p>
</li><li><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p1133420334108"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p1133420334108"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p1133420334108"></a>两个值时，第一个值被匹配给上和下，第二个值被匹配给左和右。</p>
</li><li><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p193341533191015"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p193341533191015"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p193341533191015"></a>三个值时，第一个值被匹配给上, 第二个值被匹配给左和右，第三个值被匹配给下。</p>
</li><li><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p733412334102"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p733412334102"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p733412334102"></a>四个值时，会依次按上、右、下、左的顺序匹配 (即顺时针顺序)。</p>
</li></ul>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row4481044182319"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a70939a36b2b04dd8bec21f5bddc8637e"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a70939a36b2b04dd8bec21f5bddc8637e"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a70939a36b2b04dd8bec21f5bddc8637e"></a>margin-[left|top|right|bottom]</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ae53ac9ac370d483990e04ea9789c1e49"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ae53ac9ac370d483990e04ea9789c1e49"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ae53ac9ac370d483990e04ea9789c1e49"></a>&lt;length&gt; | &lt;percentage&gt;<sup id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_sup378331720532"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_sup378331720532"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_sup378331720532"></a><span>5+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a180cd037e6174e5c82f35a3a66b6f2ec"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a180cd037e6174e5c82f35a3a66b6f2ec"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a180cd037e6174e5c82f35a3a66b6f2ec"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p773013742811"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p773013742811"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p773013742811"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a487d09add6e54c5c89fa4f22e9318271"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a487d09add6e54c5c89fa4f22e9318271"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a487d09add6e54c5c89fa4f22e9318271"></a>设置左、上、右、下外边距属性。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row549194422314"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p9492107123816"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p9492107123816"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p9492107123816"></a>margin-[start|end]</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p157617124374_1"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p157617124374_1"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p157617124374_1"></a>&lt;length&gt; | &lt;percentage&gt;<sup id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_sup8490161513019_1"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_sup8490161513019_1"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_sup8490161513019_1"></a><span>5+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p1549213793811"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p1549213793811"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p1549213793811"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001059148552_p1649144142317"><a name="zh-cn_topic_0000001059148552_p1649144142317"></a><a name="zh-cn_topic_0000001059148552_p1649144142317"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p1049212715388"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p1049212715388"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p1049212715388"></a>设置起始和末端外边距属性。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row1549154472313"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a222bb48f24014f2eb2b16a1a840bbebb"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a222bb48f24014f2eb2b16a1a840bbebb"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a222bb48f24014f2eb2b16a1a840bbebb"></a>border</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a79b4eaf9983c44d0aad39ff04d0997a8"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a79b4eaf9983c44d0aad39ff04d0997a8"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a79b4eaf9983c44d0aad39ff04d0997a8"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_aac320f4f0a42401aa7fa778d9829d77c"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_aac320f4f0a42401aa7fa778d9829d77c"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_aac320f4f0a42401aa7fa778d9829d77c"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001059148552_p144934412239"><a name="zh-cn_topic_0000001059148552_p144934412239"></a><a name="zh-cn_topic_0000001059148552_p144934412239"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a9cd962871a4c467a8e1ef452621d5cd7"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a9cd962871a4c467a8e1ef452621d5cd7"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a9cd962871a4c467a8e1ef452621d5cd7"></a>使用简写属性设置所有的边框属性，包含边框的宽度，样式，颜色属性，顺序设置为border-width、border-style、border-color，不设置时，各属性值为默认值。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row10491344102313"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a987708c0864a4128af094334f1b024b3"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a987708c0864a4128af094334f1b024b3"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a987708c0864a4128af094334f1b024b3"></a>border-style</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p513631613319"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p513631613319"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p513631613319"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a2567083af59c40e58e3e4d9b0ddf1485"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a2567083af59c40e58e3e4d9b0ddf1485"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a2567083af59c40e58e3e4d9b0ddf1485"></a>solid</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001059148552_p19503442237"><a name="zh-cn_topic_0000001059148552_p19503442237"></a><a name="zh-cn_topic_0000001059148552_p19503442237"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p342285712314"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p342285712314"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p342285712314"></a>使用简写属性设置所有边框的样式，可选值为：</p>
<a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ul1470834505612"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ul1470834505612"></a><ul id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ul1470834505612"><li>dotted：显示为一系列圆点，圆点半径为border-width的一半。</li><li>dashed：显示为一系列短的方形虚线。</li></ul>
<a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ul15621125545612"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ul15621125545612"></a><ul id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ul15621125545612"><li>solid：显示为一条实线。</li></ul>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row158901822154418"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001059148552_p589112225442"><a name="zh-cn_topic_0000001059148552_p589112225442"></a><a name="zh-cn_topic_0000001059148552_p589112225442"></a>border-[left|top|right|bottom]-style</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001059148552_p6891102211445"><a name="zh-cn_topic_0000001059148552_p6891102211445"></a><a name="zh-cn_topic_0000001059148552_p6891102211445"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001059148552_p118911422104419"><a name="zh-cn_topic_0000001059148552_p118911422104419"></a><a name="zh-cn_topic_0000001059148552_p118911422104419"></a>solid</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001059148552_p1891132284413"><a name="zh-cn_topic_0000001059148552_p1891132284413"></a><a name="zh-cn_topic_0000001059148552_p1891132284413"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001059148552_p16891102274415"><a name="zh-cn_topic_0000001059148552_p16891102274415"></a><a name="zh-cn_topic_0000001059148552_p16891102274415"></a>分别设置左、上、右、下四个边框的样式，可选值为dotted、dashed、solid。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row851154492314"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a8afd82b1aba547d3b0188b749518b2de"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a8afd82b1aba547d3b0188b749518b2de"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a8afd82b1aba547d3b0188b749518b2de"></a>border-[left|top|right|bottom]</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ac4b8a3b39e5446b5868f1f2989dc9590"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ac4b8a3b39e5446b5868f1f2989dc9590"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ac4b8a3b39e5446b5868f1f2989dc9590"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a3420bc82bd17458ab82fa996ade7064c"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a3420bc82bd17458ab82fa996ade7064c"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a3420bc82bd17458ab82fa996ade7064c"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p67303762810"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p67303762810"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p67303762810"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_af4178a066c344412afbd38f4b0c44818"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_af4178a066c344412afbd38f4b0c44818"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_af4178a066c344412afbd38f4b0c44818"></a>使用简写属性设置对应位置的边框属性，包含边框的宽度，样式，颜色属性，顺序设置为border-width、border-style、border-color，不设置的值为默认值。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row051194492320"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_adf0e0afedc774afca9cda0e509391029"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_adf0e0afedc774afca9cda0e509391029"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_adf0e0afedc774afca9cda0e509391029"></a>border-width</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a0782ea2c45eb4864a8df82f30dd2cd5f"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a0782ea2c45eb4864a8df82f30dd2cd5f"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a0782ea2c45eb4864a8df82f30dd2cd5f"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a395cbedd521145bd820b9171ee2dd7ac"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a395cbedd521145bd820b9171ee2dd7ac"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a395cbedd521145bd820b9171ee2dd7ac"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001059148552_p75274482319"><a name="zh-cn_topic_0000001059148552_p75274482319"></a><a name="zh-cn_topic_0000001059148552_p75274482319"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a7ae60621ea3341818a03bfdffa641894"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a7ae60621ea3341818a03bfdffa641894"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a7ae60621ea3341818a03bfdffa641894"></a>使用简写属性设置元素的所有边框宽度<span id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ph13216153653618"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ph13216153653618"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ph13216153653618"></a>，或者单独为各边边框设置宽度</span>。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row65213443238"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a7371edc07c664266a2e1866f31ad0d0c"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a7371edc07c664266a2e1866f31ad0d0c"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a7371edc07c664266a2e1866f31ad0d0c"></a>border-[left|top|right|bottom]-width</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a2faa532b841948a7b6598542b4eccc7b"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a2faa532b841948a7b6598542b4eccc7b"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a2faa532b841948a7b6598542b4eccc7b"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a87f38cfa47f54bc18c32f9671c0f9ca6"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a87f38cfa47f54bc18c32f9671c0f9ca6"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a87f38cfa47f54bc18c32f9671c0f9ca6"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001059148552_p45294472317"><a name="zh-cn_topic_0000001059148552_p45294472317"></a><a name="zh-cn_topic_0000001059148552_p45294472317"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a20386e66c3834d5f96cf9435c4715c5b"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a20386e66c3834d5f96cf9435c4715c5b"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a20386e66c3834d5f96cf9435c4715c5b"></a>分别设置左、上、右、下四个边框的宽度。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row052134419238"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a40a816cf0a03489d81f209a8aa7d81a6"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a40a816cf0a03489d81f209a8aa7d81a6"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a40a816cf0a03489d81f209a8aa7d81a6"></a>border-color</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_afcc7c948ae0947b2a78002d31f2f9748"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_afcc7c948ae0947b2a78002d31f2f9748"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_afcc7c948ae0947b2a78002d31f2f9748"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ae0909d2b896342f9b2196fe0dce72920"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ae0909d2b896342f9b2196fe0dce72920"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ae0909d2b896342f9b2196fe0dce72920"></a>black</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001059148552_p9521044142317"><a name="zh-cn_topic_0000001059148552_p9521044142317"></a><a name="zh-cn_topic_0000001059148552_p9521044142317"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a76fd98995e1d4217aa703fecd69325c7"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a76fd98995e1d4217aa703fecd69325c7"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a76fd98995e1d4217aa703fecd69325c7"></a>使用简写属性设置元素的所有边框颜色<span id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ph112821853719"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ph112821853719"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ph112821853719"></a>，或者单独为各边边框设置颜色</span>。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row1852144442315"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a2afc646d6a2549548bcd5c4b9bed1fb5"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a2afc646d6a2549548bcd5c4b9bed1fb5"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a2afc646d6a2549548bcd5c4b9bed1fb5"></a>border-[left|top|right|bottom]-color</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a34556866a4f54f5da88f148fc698867b"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a34556866a4f54f5da88f148fc698867b"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a34556866a4f54f5da88f148fc698867b"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a8ff58e18553846a38e82c69149e2aa30"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a8ff58e18553846a38e82c69149e2aa30"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a8ff58e18553846a38e82c69149e2aa30"></a>black</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001059148552_p105314412314"><a name="zh-cn_topic_0000001059148552_p105314412314"></a><a name="zh-cn_topic_0000001059148552_p105314412314"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a5c85947d388c4c7fbf0de07b022bb44e"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a5c85947d388c4c7fbf0de07b022bb44e"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a5c85947d388c4c7fbf0de07b022bb44e"></a>分别设置左、上、右、下四个边框的颜色。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row953844182310"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a65974e3078c447a383fb9237cc4ffa32"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a65974e3078c447a383fb9237cc4ffa32"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a65974e3078c447a383fb9237cc4ffa32"></a>border-radius</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a413fd0aea8b243349a19f825e96ee8b6"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a413fd0aea8b243349a19f825e96ee8b6"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a413fd0aea8b243349a19f825e96ee8b6"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_af786857698c74e259f52589a6670a0a1"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_af786857698c74e259f52589a6670a0a1"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_af786857698c74e259f52589a6670a0a1"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p67306752816"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p67306752816"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p67306752816"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a52ca834f42124d3b8b12bbf54914fc96"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a52ca834f42124d3b8b12bbf54914fc96"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a52ca834f42124d3b8b12bbf54914fc96"></a>border-radius属性是设置元素的外边框圆角半径。<span id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ph817510495223"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ph817510495223"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ph817510495223"></a>设置border-radius时不能单独设置某一个方向的border-[left|top|right|bottom]-width，border-[left|top|right|bottom]-color ，border-[left|top|right|bottom]-style，如果要设置color、width和style，需要将四个方向一起设置（border-width、border-color、border-style）。</span></p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row2541944162318"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a466f1f8bc2fb404e82e8417c5133eacb"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a466f1f8bc2fb404e82e8417c5133eacb"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a466f1f8bc2fb404e82e8417c5133eacb"></a>border-[top|bottom]-[left|right]-radius</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a499fe910d0284647abc48b1bd0eb4868"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a499fe910d0284647abc48b1bd0eb4868"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a499fe910d0284647abc48b1bd0eb4868"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ac142d1054eee499f948069f46129c492"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ac142d1054eee499f948069f46129c492"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ac142d1054eee499f948069f46129c492"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p27305718283"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p27305718283"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p27305718283"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a63757091a86c4ced97f0c39d37a2117c"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a63757091a86c4ced97f0c39d37a2117c"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a63757091a86c4ced97f0c39d37a2117c"></a>分别设置左上，右上，右下和左下四个角的圆角半径。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row0548446238"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ae335be2c6150440fb31b40b1ca117858"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ae335be2c6150440fb31b40b1ca117858"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ae335be2c6150440fb31b40b1ca117858"></a>background</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a394a81171c5c4d1aa81b94fc5d2f0f07"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a394a81171c5c4d1aa81b94fc5d2f0f07"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a394a81171c5c4d1aa81b94fc5d2f0f07"></a>&lt;linear-gradient&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a0734de04e90e470cb608e8d5f42c6874"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a0734de04e90e470cb608e8d5f42c6874"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a0734de04e90e470cb608e8d5f42c6874"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p15730197132811"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p15730197132811"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p15730197132811"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a1d2985ee819d4cfd87861080354def51"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a1d2985ee819d4cfd87861080354def51"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a1d2985ee819d4cfd87861080354def51"></a>仅支持设置<a href="渐变样式.md#ZH-CN_TOPIC_0000001115974726">渐变样式</a>，与background-color、background-image不兼容。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row754174410234"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a2977672444224b738a566c61225961c2"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a2977672444224b738a566c61225961c2"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a2977672444224b738a566c61225961c2"></a>background-color</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a87186748ed7c4694aef0095d8a7f8e43"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a87186748ed7c4694aef0095d8a7f8e43"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a87186748ed7c4694aef0095d8a7f8e43"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a2775a3cca8994bec9b754af0d2455eb5"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a2775a3cca8994bec9b754af0d2455eb5"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a2775a3cca8994bec9b754af0d2455eb5"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p17730577282"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p17730577282"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p17730577282"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a372b6089bf9746f091c91fa49b571f1d"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a372b6089bf9746f091c91fa49b571f1d"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a372b6089bf9746f091c91fa49b571f1d"></a>设置背景颜色。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row455124419234"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ab2dff80cd59c4db1bf4293172f89735e"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ab2dff80cd59c4db1bf4293172f89735e"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ab2dff80cd59c4db1bf4293172f89735e"></a>background-image</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ad9a7e9f2469b45238a6a0ac6da232286"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ad9a7e9f2469b45238a6a0ac6da232286"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ad9a7e9f2469b45238a6a0ac6da232286"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a73fb72c96edd488ba74c364568e345c6"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a73fb72c96edd488ba74c364568e345c6"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a73fb72c96edd488ba74c364568e345c6"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p7730976285"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p7730976285"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p7730976285"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a24de29e3cb4d476fabe55d48d69350a8"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a24de29e3cb4d476fabe55d48d69350a8"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a24de29e3cb4d476fabe55d48d69350a8"></a>设置背景图片。与background-color、background不兼容；支持本地图片资源地址。</p>
<p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p434668142510"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p434668142510"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p434668142510"></a>示例：</p>
<a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ul11766913172513"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ul11766913172513"></a><ul id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ul11766913172513"><li>background-image: url("/common/background.png")</li></ul>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row185515446230"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_af81424fd1fbf4f5da65ea5d136390494"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_af81424fd1fbf4f5da65ea5d136390494"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_af81424fd1fbf4f5da65ea5d136390494"></a>background-size</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ul1065173641310"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ul1065173641310"></a><ul id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ul1065173641310"><li>string</li><li>&lt;length&gt; &lt;length&gt;</li><li>&lt;percentage&gt; &lt;percentage&gt;</li></ul>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a222f4e09239a4ab08880d1d9544d337c"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a222f4e09239a4ab08880d1d9544d337c"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a222f4e09239a4ab08880d1d9544d337c"></a>auto</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p137309714282"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p137309714282"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p137309714282"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p91971112114318"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p91971112114318"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p91971112114318"></a>设置背景图片的大小。</p>
<a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ul41331853154111"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ul41331853154111"></a><ul id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ul41331853154111"><li>string可选值：<a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ul13611494111"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ul13611494111"></a><ul id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ul13611494111"><li>contain：把图像扩展至最大尺寸，以使其高度和宽度完全适用内容区域。</li><li>cover：把背景图像扩展至足够大，以使背景图像完全覆盖背景区域；背景图像的某些部分也许无法显示在背景定位区域中。</li><li>auto：保持原图的比例不变。</li></ul>
</li><li>length值参数方式：<p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p1840244924418"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p1840244924418"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p1840244924418"></a>设置背景图像的高度和宽度。第一个值设置宽度，第二个值设置高度。如果只设置一个值，则第二个值会被设置为 "auto"。</p>
</li><li>百分比参数方式：<p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p17936154410457"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p17936154410457"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p17936154410457"></a>以父元素的百分比来设置背景图像的宽度和高度。第一个值设置宽度，第二个值设置高度。如果只设置一个值，则第二个值会被设置为 "auto"。</p>
</li></ul>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row105744416236"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a9957170386754fb5b648ba2114bd52d4"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a9957170386754fb5b648ba2114bd52d4"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a9957170386754fb5b648ba2114bd52d4"></a>background-repeat</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a155b4cc325e747279694d36c2fa69bcc"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a155b4cc325e747279694d36c2fa69bcc"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a155b4cc325e747279694d36c2fa69bcc"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a82029c0dc1d540cf994f690b451c48f4"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a82029c0dc1d540cf994f690b451c48f4"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a82029c0dc1d540cf994f690b451c48f4"></a>repeat</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p1673015702810"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p1673015702810"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p1673015702810"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_afb8e41c117884b368a0f1df348be8e54"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_afb8e41c117884b368a0f1df348be8e54"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_afb8e41c117884b368a0f1df348be8e54"></a>针对重复背景图像样式进行设置，背景图像默认在水平和垂直方向上重复。</p>
<a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ul8236153103612"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ul8236153103612"></a><ul id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ul8236153103612"><li>repeat：在水平轴和竖直轴上同时重复绘制图片。</li><li>repeat-x：只在水平轴上重复绘制图片。</li><li>repeat-y：只在竖直轴上重复绘制图片。</li><li>no-repeat：不会重复绘制图片。</li></ul>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row057194419232"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a709eb4a9fa87428897bebb4a98693df2"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a709eb4a9fa87428897bebb4a98693df2"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a709eb4a9fa87428897bebb4a98693df2"></a>background-position</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ul8874155216502"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ul8874155216502"></a><ul id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ul8874155216502"><li>string string</li><li>&lt;length&gt; &lt;length&gt;</li><li>&lt;percentage&gt; &lt;percentage&gt;</li></ul>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a6f8f5d1c92f447bd868a841ad1a33cb1"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a6f8f5d1c92f447bd868a841ad1a33cb1"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a6f8f5d1c92f447bd868a841ad1a33cb1"></a>0px 0px</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p173010720280"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p173010720280"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p173010720280"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ul1590812103363"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ul1590812103363"></a><ul id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ul1590812103363"><li>关键词方式：如果仅规定了一个关键词，那么第二个值为"center"。两个值分别定义水平方向位置和竖直方向位置。<a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ul1453531734716"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ul1453531734716"></a><ul id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ul1453531734716"><li>left：水平方向上最左侧。</li><li>right：水平方向上最右侧。</li><li>top：竖直方向上最顶部。</li><li>bottom：竖直方向上最底部。</li><li>center：水平方向或竖直方向上中间位置。</li></ul>
</li></ul>
<a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ul10908121023615"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ul10908121023615"></a><ul id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ul10908121023615"><li>length值参数方式：第一个值是水平位置，第二个值是垂直位置。 左上角是 0 0。单位是像素 (0px 0px)  。如果仅规定了一个值，另外一个值将是50%。</li><li>百分比参数方式：第一个值是水平位置，第二个值是垂直位置。左上角是 0% 0%。右下角是 100% 100%。如果仅规定了一个值，另外一个值为50%。</li><li>可以混合使用&lt;percentage&gt;和&lt;length&gt;</li></ul>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row1259204418231"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p134581712103910"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p134581712103910"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p134581712103910"></a>opacity</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a45185999ae584676af4c36467c2ade8b"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a45185999ae584676af4c36467c2ade8b"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a45185999ae584676af4c36467c2ade8b"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a09ff20dda8e44794bca18c84f413d972"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a09ff20dda8e44794bca18c84f413d972"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a09ff20dda8e44794bca18c84f413d972"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p1873011722814"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p1873011722814"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p1873011722814"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p122515161139"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p122515161139"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p122515161139"></a>元素的透明度，取值范围为0到1，1表示为不透明，0表示为完全透明。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row75984472312"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_aeda9e2f8d8344958bf4f43d429dcb55e"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_aeda9e2f8d8344958bf4f43d429dcb55e"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_aeda9e2f8d8344958bf4f43d429dcb55e"></a>display</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p1544115441446"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p1544115441446"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p1544115441446"></a>string</p>
<p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_aaaa164aa970b490fb048e5f260f1c661"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_aaaa164aa970b490fb048e5f260f1c661"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_aaaa164aa970b490fb048e5f260f1c661"></a></p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_aa5ce61466c9847dbb7f44852338d9006"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_aa5ce61466c9847dbb7f44852338d9006"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_aa5ce61466c9847dbb7f44852338d9006"></a>flex</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p167303762818"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p167303762818"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p167303762818"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p23704018414"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p23704018414"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p23704018414"></a>确定一个元素所产生的框的类型，可选值为：</p>
<a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ul12227103394916"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ul12227103394916"></a><ul id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ul12227103394916"><li>flex：弹性布局。</li><li>none：不渲染此元素。</li></ul>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row1060044172311"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_aa2ed1da39c8e4ad78829712734226ab9"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_aa2ed1da39c8e4ad78829712734226ab9"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_aa2ed1da39c8e4ad78829712734226ab9"></a>visibility</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p15475737486"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p15475737486"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p15475737486"></a>string</p>
<p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_aabfb0eb044194745af56c313f40e7781"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_aabfb0eb044194745af56c313f40e7781"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_aabfb0eb044194745af56c313f40e7781"></a></p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_acaca80d4ef9a4f0d87adf92cb2d1ff9a"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_acaca80d4ef9a4f0d87adf92cb2d1ff9a"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_acaca80d4ef9a4f0d87adf92cb2d1ff9a"></a>visible</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p57301471281"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p57301471281"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p57301471281"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p1568839154517"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p1568839154517"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p1568839154517"></a>是否显示元素所产生的框。不可见的框会占用布局（将'display'属性设置为'none'来完全去除框），可选值为：</p>
<a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ul751984164920"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ul751984164920"></a><ul id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ul751984164920"><li>visible：元素正常显示。</li><li>hidden：隐藏元素，但是其他元素的布局不改变，相当于此元素变成透明。</li></ul>
<div class="note" id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_note4549524649"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_note4549524649"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_note4549524649"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p25499241642"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p25499241642"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p25499241642"></a>visibility和display样式都设置时，仅display生效</p>
</div></div>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row260114472318"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ad74a6a48aca7439e9344c18c26b4177e"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ad74a6a48aca7439e9344c18c26b4177e"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ad74a6a48aca7439e9344c18c26b4177e"></a>flex</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a2e6e5192a1534872be5fcfd9f83e3fdc"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a2e6e5192a1534872be5fcfd9f83e3fdc"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a2e6e5192a1534872be5fcfd9f83e3fdc"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a8512eda38e25410685be8a8992890257"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a8512eda38e25410685be8a8992890257"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a8512eda38e25410685be8a8992890257"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p1373057132812"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p1373057132812"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p1373057132812"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a11c317cdfa7d4066878d86c6b3bcbd82"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a11c317cdfa7d4066878d86c6b3bcbd82"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a11c317cdfa7d4066878d86c6b3bcbd82"></a>规定当前组件如何适应父组件中的可用空间。</p>
<p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p6968144051814"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p6968144051814"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p6968144051814"></a>flex可以指定1个，2个<sup id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_sup894453017315"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_sup894453017315"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_sup894453017315"></a>5+</sup>或3个<sup id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_sup1255142393114"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_sup1255142393114"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_sup1255142393114"></a>5+</sup>值。</p>
<p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p16733313171911"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p16733313171911"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p16733313171911"></a>单值语法：</p>
<a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ul93371539192211"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ul93371539192211"></a><ul id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ul93371539192211"><li>一个无单位数：用来设置组件的flex-grow</li><li>一个有效的宽度值<sup id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_sup133014373318"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_sup133014373318"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_sup133014373318"></a>5+</sup>：用来设置组件的flex-basis</li></ul>
<p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p6786171632018"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p6786171632018"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p6786171632018"></a>双值语法<sup id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_sup39514502313"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_sup39514502313"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_sup39514502313"></a>5+</sup>：</p>
<p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p6400429122011"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p6400429122011"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p6400429122011"></a>第一个值必须是无单位数，用来设置组件的flex-grow。第二个值是以下之一：</p>
<a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ul767043502219"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ul767043502219"></a><ul id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ul767043502219"><li>一个无单位数：用来设置组件的flex-shrink</li><li>一个有效的宽度值：用来设置组件的flex-basis</li></ul>
<p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p748416351217"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p748416351217"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p748416351217"></a>三值语法<sup id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_sup718215417318"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_sup718215417318"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_sup718215417318"></a>5+</sup>：</p>
<p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p7373204832111"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p7373204832111"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p7373204832111"></a>第一个值必须是无单位数，用来设置组件的flex-grow；第二个值必须是无单位数，用来设置组件的flex-shrink；第三个值必须是一个有效的宽度值，用来设置组件的flex-basis。</p>
<div class="note" id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_note34891253201520"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_note34891253201520"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_note34891253201520"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p1248915538152"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p1248915538152"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p1248915538152"></a>仅父容器为&lt;div&gt;、&lt;list-item&gt;、&lt;tabs&gt;、&lt;refresh&gt;、&lt;stepper-item&gt;<sup id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_sup7842840112718"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_sup7842840112718"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_sup7842840112718"></a><span>5+</span></sup>时生效。</p>
</div></div>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row1161174412318"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a5d88cacaaf5c4f6a87390ab916b695c6"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a5d88cacaaf5c4f6a87390ab916b695c6"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a5d88cacaaf5c4f6a87390ab916b695c6"></a>flex-grow</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a2c379e3af283446da446f1631e572efd"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a2c379e3af283446da446f1631e572efd"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a2c379e3af283446da446f1631e572efd"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_aa374f6c7415a4ee48a06930d76c55be7"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_aa374f6c7415a4ee48a06930d76c55be7"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_aa374f6c7415a4ee48a06930d76c55be7"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001059148552_p461154472318"><a name="zh-cn_topic_0000001059148552_p461154472318"></a><a name="zh-cn_topic_0000001059148552_p461154472318"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p4437122419557"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p4437122419557"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p4437122419557"></a>设置组件的拉伸样式，指定父组件容器主轴方向上剩余空间（容器本身大小减去所有flex子元素占用的大小）的分配权重。0为不伸展。</p>
<div class="note" id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_note201231734212"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_note201231734212"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_note201231734212"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p184555314553"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p184555314553"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p184555314553"></a>仅父容器为&lt;div&gt;、&lt;list-item&gt;、&lt;tabs&gt;、&lt;refresh&gt;、&lt;stepper-item&gt;<sup id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_sup19626155192720"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_sup19626155192720"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_sup19626155192720"></a><span>5+</span></sup>时生效。</p>
</div></div>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row146184419238"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ac65ef7e2b1f24a13b09c495f643168c9"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ac65ef7e2b1f24a13b09c495f643168c9"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ac65ef7e2b1f24a13b09c495f643168c9"></a>flex-shrink</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a98e7d367f0e649699892ae5bad6ade37"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a98e7d367f0e649699892ae5bad6ade37"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a98e7d367f0e649699892ae5bad6ade37"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a422d978368814d12a33201cb839060ee"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a422d978368814d12a33201cb839060ee"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a422d978368814d12a33201cb839060ee"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001059148552_p6629442237"><a name="zh-cn_topic_0000001059148552_p6629442237"></a><a name="zh-cn_topic_0000001059148552_p6629442237"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ab032342dfe56460ca742800de482ca0f"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ab032342dfe56460ca742800de482ca0f"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ab032342dfe56460ca742800de482ca0f"></a>设置组件的收缩样式，元素仅在默认宽度之和大于容器的时候才会发生收缩，0为不收缩。</p>
<div class="note" id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_note147160917217"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_note147160917217"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_note147160917217"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p844914328577"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p844914328577"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p844914328577"></a>仅父容器为&lt;div&gt;、&lt;list-item&gt;、&lt;tabs&gt;、&lt;refresh&gt;、&lt;stepper-item&gt;<sup id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_sup7848105319275"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_sup7848105319275"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_sup7848105319275"></a><span>5+</span></sup>时生效。</p>
</div></div>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row56212444236"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a82c323a994634032963169eeee1a55e4"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a82c323a994634032963169eeee1a55e4"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a82c323a994634032963169eeee1a55e4"></a>flex-basis</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p1148910787"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p1148910787"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p1148910787"></a>&lt;length&gt;</p>
<p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a43613cf0c2184c0d8b44e8d292f6edb7"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a43613cf0c2184c0d8b44e8d292f6edb7"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a43613cf0c2184c0d8b44e8d292f6edb7"></a></p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ab9e1c7dc25f840e58993af05c1d32109"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ab9e1c7dc25f840e58993af05c1d32109"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ab9e1c7dc25f840e58993af05c1d32109"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001059148552_p16621944152310"><a name="zh-cn_topic_0000001059148552_p16621944152310"></a><a name="zh-cn_topic_0000001059148552_p16621944152310"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a0993ef9b0ef64785a76e6310dd834f09"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a0993ef9b0ef64785a76e6310dd834f09"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a0993ef9b0ef64785a76e6310dd834f09"></a>设置组件在主轴方向上的初始大小。</p>
<div class="note" id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_note62848141222"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_note62848141222"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_note62848141222"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p16711745115718"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p16711745115718"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p16711745115718"></a>仅父容器为&lt;div&gt;、&lt;list-item&gt;、&lt;tabs&gt;、&lt;refresh&gt;、&lt;stepper-item&gt;<sup id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_sup378825517272"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_sup378825517272"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_sup378825517272"></a><span>5+</span></sup>时生效。</p>
</div></div>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row1621844162310"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a50180d720a374549ae72c848e53320cb"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a50180d720a374549ae72c848e53320cb"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a50180d720a374549ae72c848e53320cb"></a>position</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a63672ed9a4c040f7a6ec9c8089b79bb6"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a63672ed9a4c040f7a6ec9c8089b79bb6"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a63672ed9a4c040f7a6ec9c8089b79bb6"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a2666820c71eb420485e4d20e55b4eabe"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a2666820c71eb420485e4d20e55b4eabe"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a2666820c71eb420485e4d20e55b4eabe"></a>relative</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p1173107172814"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p1173107172814"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p1173107172814"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ae28abf4e47a740efbd45a8f280577912"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ae28abf4e47a740efbd45a8f280577912"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ae28abf4e47a740efbd45a8f280577912"></a>设置元素的定位类型，不支持动态变更。</p>
<a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ul17185232185014"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ul17185232185014"></a><ul id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ul17185232185014"><li>fixed：相对与整个界面进行定位。</li><li>absolute：相对于父元素进行定位。</li><li>relative：相对于其正常位置进行定位。</li></ul>
<div class="note" id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_note167617191219"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_note167617191219"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_note167617191219"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p1839092815101"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p1839092815101"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p1839092815101"></a>absolute属性仅在父容器为&lt;div&gt;、&lt;stack&gt;时生效。</p>
</div></div>
</td>
</tr>
<tr id="zh-cn_topic_0000001059148552_row4631644172319"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a70405cb9696b4329ac7625af93310018"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a70405cb9696b4329ac7625af93310018"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a70405cb9696b4329ac7625af93310018"></a>[left|top<span id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ph14927143614712"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ph14927143614712"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ph14927143614712"></a>|right|bottom</span>]</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p1849062221214"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p1849062221214"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p1849062221214"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a579ac7c03d1d46758ebaacd565d86ed3"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a579ac7c03d1d46758ebaacd565d86ed3"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a579ac7c03d1d46758ebaacd565d86ed3"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p187314719288"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p187314719288"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_p187314719288"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a9a662a62cd9b40eaa0cb9ca082b6d1c2"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a9a662a62cd9b40eaa0cb9ca082b6d1c2"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_a9a662a62cd9b40eaa0cb9ca082b6d1c2"></a>left|top<span id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ph116191353154713"><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ph116191353154713"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ph116191353154713"></a>|right|bottom</span>需要配合position样式使用，来确定元素的偏移位置。</p>
<a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ul12671003525"></a><a name="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ul12671003525"></a><ul id="zh-cn_topic_0000001059148552_zh-cn_topic_0000001059340528_ul12671003525"><li>left属性规定元素的左边缘。该属性定义了定位元素左外边距边界与其包含块左边界之间的偏移。</li><li>top属性规定元素的顶部边缘。该属性定义了一个定位元素的上外边距边界与其包含块上边界之间的偏移。</li><li>right属性规定元素的右边缘。该属性定义了定位元素右外边距边界与其包含块右边界之间的偏移。</li><li>bottom属性规定元素的底部边缘。该属性定义了一个定位元素的下外边距边界与其包含块下边界之间的偏移。</li></ul>
</td>
</tr>
</tbody>
</table>

## 示例<a name="zh-cn_topic_0000001059148552_section164885329456"></a>

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

    ![](figures/zh-cn_image_0000001059148590.png)

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


