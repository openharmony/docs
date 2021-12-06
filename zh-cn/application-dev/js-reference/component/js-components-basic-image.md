# image<a name="ZH-CN_TOPIC_0000001209252165"></a>

图片组件，用来渲染展示图片。

## 子组件<a name="zh-cn_topic_0000001173164699_section9288143101012"></a>

不支持。

## 属性<a name="zh-cn_topic_0000001173164699_section2907183951110"></a>

除支持[通用属性](js-components-common-attributes.md)外，还支持如下属性：

<a name="zh-cn_topic_0000001173164699_table20633101642315"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001173164699_row663331618238"><th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001173164699_aa872998ac2d84843a3c5161889afffef"><a name="zh-cn_topic_0000001173164699_aa872998ac2d84843a3c5161889afffef"></a><a name="zh-cn_topic_0000001173164699_aa872998ac2d84843a3c5161889afffef"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001173164699_ab2111648ee0e4f6d881be8954e7acaab"><a name="zh-cn_topic_0000001173164699_ab2111648ee0e4f6d881be8954e7acaab"></a><a name="zh-cn_topic_0000001173164699_ab2111648ee0e4f6d881be8954e7acaab"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="10.48%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001173164699_ab377d1c90900478ea4ecab51e9a058af"><a name="zh-cn_topic_0000001173164699_ab377d1c90900478ea4ecab51e9a058af"></a><a name="zh-cn_topic_0000001173164699_ab377d1c90900478ea4ecab51e9a058af"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001173164699_p824610360217"><a name="zh-cn_topic_0000001173164699_p824610360217"></a><a name="zh-cn_topic_0000001173164699_p824610360217"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="35.76%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001173164699_a1d574a0044ed42ec8a2603bc82734232"><a name="zh-cn_topic_0000001173164699_a1d574a0044ed42ec8a2603bc82734232"></a><a name="zh-cn_topic_0000001173164699_a1d574a0044ed42ec8a2603bc82734232"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001173164699_row10711153415392"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173164699_p13851942163912"><a name="zh-cn_topic_0000001173164699_p13851942163912"></a><a name="zh-cn_topic_0000001173164699_p13851942163912"></a>src</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173164699_p53851422390"><a name="zh-cn_topic_0000001173164699_p53851422390"></a><a name="zh-cn_topic_0000001173164699_p53851422390"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173164699_p193856420395"><a name="zh-cn_topic_0000001173164699_p193856420395"></a><a name="zh-cn_topic_0000001173164699_p193856420395"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173164699_p23851942103915"><a name="zh-cn_topic_0000001173164699_p23851942103915"></a><a name="zh-cn_topic_0000001173164699_p23851942103915"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173164699_p4386542163913"><a name="zh-cn_topic_0000001173164699_p4386542163913"></a><a name="zh-cn_topic_0000001173164699_p4386542163913"></a><span id="zh-cn_topic_0000001173164699_ph1386114233917"><a name="zh-cn_topic_0000001173164699_ph1386114233917"></a><a name="zh-cn_topic_0000001173164699_ph1386114233917"></a>图片的路径，支持本地路径，图片格式包括png、jpg、bmp、svg和gif。</span></p>
<p id="zh-cn_topic_0000001173164699_p2020265093811"><a name="zh-cn_topic_0000001173164699_p2020265093811"></a><a name="zh-cn_topic_0000001173164699_p2020265093811"></a>支持Base64字符串<sup id="zh-cn_topic_0000001173164699_sup792414482411"><a name="zh-cn_topic_0000001173164699_sup792414482411"></a><a name="zh-cn_topic_0000001173164699_sup792414482411"></a><span>6+</span></sup>。格式为data:image/[png | jpeg | bmp | webp];base64, [base64 data], 其中[base64 data]为Base64字符串数据。</p>
<p id="zh-cn_topic_0000001173164699_p158689315419"><a name="zh-cn_topic_0000001173164699_p158689315419"></a><a name="zh-cn_topic_0000001173164699_p158689315419"></a>支持dataability://的路径前缀，用于访问通过data ability提供的图片路径<sup id="zh-cn_topic_0000001173164699_sup1214217419478"><a name="zh-cn_topic_0000001173164699_sup1214217419478"></a><a name="zh-cn_topic_0000001173164699_sup1214217419478"></a><span>6+</span></sup>。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164699_row871123253917"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173164699_p11386134218396"><a name="zh-cn_topic_0000001173164699_p11386134218396"></a><a name="zh-cn_topic_0000001173164699_p11386134218396"></a>alt</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173164699_p338613422396"><a name="zh-cn_topic_0000001173164699_p338613422396"></a><a name="zh-cn_topic_0000001173164699_p338613422396"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173164699_p9386142203914"><a name="zh-cn_topic_0000001173164699_p9386142203914"></a><a name="zh-cn_topic_0000001173164699_p9386142203914"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173164699_p18386124213913"><a name="zh-cn_topic_0000001173164699_p18386124213913"></a><a name="zh-cn_topic_0000001173164699_p18386124213913"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173164699_p8386194283917"><a name="zh-cn_topic_0000001173164699_p8386194283917"></a><a name="zh-cn_topic_0000001173164699_p8386194283917"></a>占位图，当指定图片在加载中时显示。</p>
</td>
</tr>
</tbody>
</table>

## 样式<a name="zh-cn_topic_0000001173164699_section45171131134215"></a>

除支持[通用样式](js-components-common-styles.md)外，还支持如下属性：

<a name="zh-cn_topic_0000001173164699_table3635337165618"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001173164699_row163523745618"><th class="cellrowborder" valign="top" width="23.16768323167683%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001173164699_p763583711569"><a name="zh-cn_topic_0000001173164699_p763583711569"></a><a name="zh-cn_topic_0000001173164699_p763583711569"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="20.427957204279572%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001173164699_p76351837135618"><a name="zh-cn_topic_0000001173164699_p76351837135618"></a><a name="zh-cn_topic_0000001173164699_p76351837135618"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="8.869113088691131%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001173164699_p1963543714562"><a name="zh-cn_topic_0000001173164699_p1963543714562"></a><a name="zh-cn_topic_0000001173164699_p1963543714562"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.519248075192481%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001173164699_p163513712567"><a name="zh-cn_topic_0000001173164699_p163513712567"></a><a name="zh-cn_topic_0000001173164699_p163513712567"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="40.01599840015999%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001173164699_p16635113735617"><a name="zh-cn_topic_0000001173164699_p16635113735617"></a><a name="zh-cn_topic_0000001173164699_p16635113735617"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001173164699_row13635143745613"><td class="cellrowborder" valign="top" width="23.16768323167683%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173164699_p063616375563"><a name="zh-cn_topic_0000001173164699_p063616375563"></a><a name="zh-cn_topic_0000001173164699_p063616375563"></a>object-fit</p>
</td>
<td class="cellrowborder" valign="top" width="20.427957204279572%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173164699_p563673711568"><a name="zh-cn_topic_0000001173164699_p563673711568"></a><a name="zh-cn_topic_0000001173164699_p563673711568"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173164699_p1763616378564"><a name="zh-cn_topic_0000001173164699_p1763616378564"></a><a name="zh-cn_topic_0000001173164699_p1763616378564"></a>cover</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173164699_p1636537105617"><a name="zh-cn_topic_0000001173164699_p1636537105617"></a><a name="zh-cn_topic_0000001173164699_p1636537105617"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173164699_p186361237165612"><a name="zh-cn_topic_0000001173164699_p186361237165612"></a><a name="zh-cn_topic_0000001173164699_p186361237165612"></a>设置图片的缩放类型。可选值类型说明请见<a href="#zh-cn_topic_0000001173164699_table175851535113711">object-fit 类型说明</a>。（不支持svg格式）</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164699_row10636173719564"><td class="cellrowborder" valign="top" width="23.16768323167683%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173164699_p26361237195610"><a name="zh-cn_topic_0000001173164699_p26361237195610"></a><a name="zh-cn_topic_0000001173164699_p26361237195610"></a>match-text-direction</p>
</td>
<td class="cellrowborder" valign="top" width="20.427957204279572%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173164699_p563653795612"><a name="zh-cn_topic_0000001173164699_p563653795612"></a><a name="zh-cn_topic_0000001173164699_p563653795612"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173164699_p1636193725615"><a name="zh-cn_topic_0000001173164699_p1636193725615"></a><a name="zh-cn_topic_0000001173164699_p1636193725615"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173164699_p10636203725617"><a name="zh-cn_topic_0000001173164699_p10636203725617"></a><a name="zh-cn_topic_0000001173164699_p10636203725617"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173164699_p176361037175612"><a name="zh-cn_topic_0000001173164699_p176361037175612"></a><a name="zh-cn_topic_0000001173164699_p176361037175612"></a>图片是否跟随文字方向。（不支持svg格式）</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164699_row17636037135618"><td class="cellrowborder" valign="top" width="23.16768323167683%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173164699_p763614376564"><a name="zh-cn_topic_0000001173164699_p763614376564"></a><a name="zh-cn_topic_0000001173164699_p763614376564"></a>fit-original-size</p>
</td>
<td class="cellrowborder" valign="top" width="20.427957204279572%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173164699_p18636103795617"><a name="zh-cn_topic_0000001173164699_p18636103795617"></a><a name="zh-cn_topic_0000001173164699_p18636103795617"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173164699_p14636143719565"><a name="zh-cn_topic_0000001173164699_p14636143719565"></a><a name="zh-cn_topic_0000001173164699_p14636143719565"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173164699_p196362371564"><a name="zh-cn_topic_0000001173164699_p196362371564"></a><a name="zh-cn_topic_0000001173164699_p196362371564"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173164699_p166364377563"><a name="zh-cn_topic_0000001173164699_p166364377563"></a><a name="zh-cn_topic_0000001173164699_p166364377563"></a>image组件在未设置宽高的情况下是否适应图源尺寸（该属性为true时object-fit属性不生效），svg类型图源不支持该属性。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164699_row12824651173817"><td class="cellrowborder" valign="top" width="23.16768323167683%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173164699_p782418514382"><a name="zh-cn_topic_0000001173164699_p782418514382"></a><a name="zh-cn_topic_0000001173164699_p782418514382"></a>object-position<sup id="zh-cn_topic_0000001173164699_sup2034121882110"><a name="zh-cn_topic_0000001173164699_sup2034121882110"></a><a name="zh-cn_topic_0000001173164699_sup2034121882110"></a>7+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.427957204279572%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173164699_p15824185112385"><a name="zh-cn_topic_0000001173164699_p15824185112385"></a><a name="zh-cn_topic_0000001173164699_p15824185112385"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173164699_p178241651103815"><a name="zh-cn_topic_0000001173164699_p178241651103815"></a><a name="zh-cn_topic_0000001173164699_p178241651103815"></a>0px 0px</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173164699_p8824165110385"><a name="zh-cn_topic_0000001173164699_p8824165110385"></a><a name="zh-cn_topic_0000001173164699_p8824165110385"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173164699_p1582420513383"><a name="zh-cn_topic_0000001173164699_p1582420513383"></a><a name="zh-cn_topic_0000001173164699_p1582420513383"></a>设置图片在组价内展示的位置。</p>
<p id="zh-cn_topic_0000001173164699_p8751515174019"><a name="zh-cn_topic_0000001173164699_p8751515174019"></a><a name="zh-cn_topic_0000001173164699_p8751515174019"></a>设置类型有两种：</p>
<p id="zh-cn_topic_0000001173164699_p19751111518408"><a name="zh-cn_topic_0000001173164699_p19751111518408"></a><a name="zh-cn_topic_0000001173164699_p19751111518408"></a>1. 像素，单位px，示例 15px 15px 代表X轴或者Y轴移动的位置</p>
<p id="zh-cn_topic_0000001173164699_p119413158218"><a name="zh-cn_topic_0000001173164699_p119413158218"></a><a name="zh-cn_topic_0000001173164699_p119413158218"></a>2. 字符，可选值：</p>
<a name="zh-cn_topic_0000001173164699_ul1815918338215"></a><a name="zh-cn_topic_0000001173164699_ul1815918338215"></a><ul id="zh-cn_topic_0000001173164699_ul1815918338215"><li>left 图片显示在组件左侧；</li><li>top 图片显示在组件顶部位置；</li><li>right 图片显示在组件右侧位置；</li><li>bottom图片显示在组件底部位置。</li></ul>
</td>
</tr>
</tbody>
</table>

**表 1**  object-fit 类型说明

<a name="zh-cn_topic_0000001173164699_table175851535113711"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001173164699_row9585183516376"><th class="cellrowborder" valign="top" width="15.02%" id="mcps1.2.3.1.1"><p id="zh-cn_topic_0000001173164699_p25851835163714"><a name="zh-cn_topic_0000001173164699_p25851835163714"></a><a name="zh-cn_topic_0000001173164699_p25851835163714"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="84.98%" id="mcps1.2.3.1.2"><p id="zh-cn_topic_0000001173164699_p1058583583717"><a name="zh-cn_topic_0000001173164699_p1058583583717"></a><a name="zh-cn_topic_0000001173164699_p1058583583717"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001173164699_row658523520377"><td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001173164699_p1558553553710"><a name="zh-cn_topic_0000001173164699_p1558553553710"></a><a name="zh-cn_topic_0000001173164699_p1558553553710"></a>cover</p>
</td>
<td class="cellrowborder" valign="top" width="84.98%" headers="mcps1.2.3.1.2 "><p id="zh-cn_topic_0000001173164699_p4585103573718"><a name="zh-cn_topic_0000001173164699_p4585103573718"></a><a name="zh-cn_topic_0000001173164699_p4585103573718"></a>保持宽高比进行缩小或者放大，使得图片两边都大于或等于显示边界，居中显示。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164699_row8585133543716"><td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001173164699_p20585735123718"><a name="zh-cn_topic_0000001173164699_p20585735123718"></a><a name="zh-cn_topic_0000001173164699_p20585735123718"></a>contain</p>
</td>
<td class="cellrowborder" valign="top" width="84.98%" headers="mcps1.2.3.1.2 "><p id="zh-cn_topic_0000001173164699_p5585153523711"><a name="zh-cn_topic_0000001173164699_p5585153523711"></a><a name="zh-cn_topic_0000001173164699_p5585153523711"></a>保持宽高比进行缩小或者放大，使得图片完全显示在显示边界内，居中显示。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164699_row1758511351377"><td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001173164699_p11586163511379"><a name="zh-cn_topic_0000001173164699_p11586163511379"></a><a name="zh-cn_topic_0000001173164699_p11586163511379"></a>fill</p>
</td>
<td class="cellrowborder" valign="top" width="84.98%" headers="mcps1.2.3.1.2 "><p id="zh-cn_topic_0000001173164699_p958611356373"><a name="zh-cn_topic_0000001173164699_p958611356373"></a><a name="zh-cn_topic_0000001173164699_p958611356373"></a>不保持宽高比进行放大缩小，使得图片填充满显示边界。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164699_row15586143520371"><td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001173164699_p195866353376"><a name="zh-cn_topic_0000001173164699_p195866353376"></a><a name="zh-cn_topic_0000001173164699_p195866353376"></a>none</p>
</td>
<td class="cellrowborder" valign="top" width="84.98%" headers="mcps1.2.3.1.2 "><p id="zh-cn_topic_0000001173164699_p2586735113716"><a name="zh-cn_topic_0000001173164699_p2586735113716"></a><a name="zh-cn_topic_0000001173164699_p2586735113716"></a>保持原有尺寸进行居中显示。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164699_row165861035133718"><td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001173164699_p195861435173720"><a name="zh-cn_topic_0000001173164699_p195861435173720"></a><a name="zh-cn_topic_0000001173164699_p195861435173720"></a>scale-down</p>
</td>
<td class="cellrowborder" valign="top" width="84.98%" headers="mcps1.2.3.1.2 "><p id="zh-cn_topic_0000001173164699_p5586835173713"><a name="zh-cn_topic_0000001173164699_p5586835173713"></a><a name="zh-cn_topic_0000001173164699_p5586835173713"></a>保持宽高比居中显示，图片缩小或者保持不变。</p>
</td>
</tr>
</tbody>
</table>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>使用svg图片资源时：
>-   建议设置image组件的长宽，否则在父组件的长或宽为无穷大的场景下，svg资源将不会绘制；
>-   如果svg描述中未指定相应的长宽，则svg将会填满image组件区域；
>-   如果svg描述中指定了相应的长宽，和image组件本身的长宽效果如下：
>1.  如果image组件本身的长宽小于svg中的长宽，svg会被裁切，仅显示左上角部分；
>2.  如果image组件本身的长宽大于svg中的长宽，svg会被放置在image组件的左上角，image组件其他部分显示空白。

## 事件<a name="zh-cn_topic_0000001173164699_section3892191911214"></a>

除支持[通用事件](js-components-common-events.md)外，还支持如下事件：

<a name="zh-cn_topic_0000001173164699_table341925115454"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001173164699_row94208515453"><th class="cellrowborder" valign="top" width="24.91249124912491%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173164699_a426b8903842d48fa8012a24ff3c997eb"><a name="zh-cn_topic_0000001173164699_a426b8903842d48fa8012a24ff3c997eb"></a><a name="zh-cn_topic_0000001173164699_a426b8903842d48fa8012a24ff3c997eb"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="29.492949294929495%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173164699_a53448ba47e5e4ae9bf7774c90820e970"><a name="zh-cn_topic_0000001173164699_a53448ba47e5e4ae9bf7774c90820e970"></a><a name="zh-cn_topic_0000001173164699_a53448ba47e5e4ae9bf7774c90820e970"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="45.5945594559456%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173164699_add489ff50c444f24b759162c7f4bad9a"><a name="zh-cn_topic_0000001173164699_add489ff50c444f24b759162c7f4bad9a"></a><a name="zh-cn_topic_0000001173164699_add489ff50c444f24b759162c7f4bad9a"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001173164699_row370317364612"><td class="cellrowborder" valign="top" width="24.91249124912491%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164699_p1177515914469"><a name="zh-cn_topic_0000001173164699_p1177515914469"></a><a name="zh-cn_topic_0000001173164699_p1177515914469"></a>complete(Rich)</p>
</td>
<td class="cellrowborder" valign="top" width="29.492949294929495%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164699_p4775139144612"><a name="zh-cn_topic_0000001173164699_p4775139144612"></a><a name="zh-cn_topic_0000001173164699_p4775139144612"></a>{ width：width， height：height }</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164699_p1577514934614"><a name="zh-cn_topic_0000001173164699_p1577514934614"></a><a name="zh-cn_topic_0000001173164699_p1577514934614"></a>图片成功加载时触发该回调，返回成功加载的图源尺寸。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164699_row8120201134610"><td class="cellrowborder" valign="top" width="24.91249124912491%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164699_p8775992468"><a name="zh-cn_topic_0000001173164699_p8775992468"></a><a name="zh-cn_topic_0000001173164699_p8775992468"></a>error(Rich)</p>
</td>
<td class="cellrowborder" valign="top" width="29.492949294929495%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164699_p107755934612"><a name="zh-cn_topic_0000001173164699_p107755934612"></a><a name="zh-cn_topic_0000001173164699_p107755934612"></a>{ width：width， height：height }</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164699_p277510954617"><a name="zh-cn_topic_0000001173164699_p277510954617"></a><a name="zh-cn_topic_0000001173164699_p277510954617"></a>图片加载出现异常时触发该回调，异常时长宽为零。</p>
</td>
</tr>
</tbody>
</table>

## 方法<a name="zh-cn_topic_0000001173164699_section2279124532420"></a>

支持[通用方法](js-components-common-methods.md)。

## 示例<a name="zh-cn_topic_0000001173164699_section321147145519"></a>

```
<!-- xxx.hml -->
<div class="container">
  <image src="common/hw_rights.JPG"  style="width: 300px;height: 300px;object-fit:{{fit}};border: 1px solid red;">
  </image>

  <select class="selects" onchange="change_fit">
      <option for="{{fits}}" value="{{$item}}">{{$item}}</option>
  </select>
</div>
```

```
/* xxx.css */
.container {
  justify-content: center;
  align-items: center;
  flex-direction: column;
}
.selects{
  margin-top: 20px;
  width:300px;
  border:1px solid #808080;
  border-radius: 10px;
}
```

```
// xxx.js
export default {
  data: {
    fit:"cover",
    fits: ["cover", "contain", "fill", "none", "scale-down"],
  },
  change_fit(e) {
    this.fit = e.newValue;
  },
}
```

![](figures/GIF.gif)

