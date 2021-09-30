# video<a name="ZH-CN_TOPIC_0000001163932210"></a>

-   [权限列表](#zh-cn_topic_0000001173164749_section11257113618419)
-   [子组件](#zh-cn_topic_0000001173164749_sc18e8342b29747dbbd70887cc3c0a22d)
-   [属性](#zh-cn_topic_0000001173164749_s50d82bce96774b86846ab2739d7ce18d)
-   [样式](#zh-cn_topic_0000001173164749_sfbde25405aca4513a9c938f2f339b770)
-   [事件](#zh-cn_topic_0000001173164749_section4181420161817)
-   [方法](#zh-cn_topic_0000001173164749_s557cc2f457ff42a193807500adae2f91)

视频播放组件。

## 权限列表<a name="zh-cn_topic_0000001173164749_section11257113618419"></a>

## 子组件<a name="zh-cn_topic_0000001173164749_sc18e8342b29747dbbd70887cc3c0a22d"></a>

不支持。

## 属性<a name="zh-cn_topic_0000001173164749_s50d82bce96774b86846ab2739d7ce18d"></a>

除支持[通用属性](js-components-common-attributes.md#ZH-CN_TOPIC_0000001163812208)外，还支持如下样式：

<a name="zh-cn_topic_0000001173164749_table20633101642315"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001173164749_row663331618238"><th class="cellrowborder" valign="top" width="15.479999999999999%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001173164749_aa872998ac2d84843a3c5161889afffef"><a name="zh-cn_topic_0000001173164749_aa872998ac2d84843a3c5161889afffef"></a><a name="zh-cn_topic_0000001173164749_aa872998ac2d84843a3c5161889afffef"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="13.04%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001173164749_ab2111648ee0e4f6d881be8954e7acaab"><a name="zh-cn_topic_0000001173164749_ab2111648ee0e4f6d881be8954e7acaab"></a><a name="zh-cn_topic_0000001173164749_ab2111648ee0e4f6d881be8954e7acaab"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="11.41%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001173164749_ab377d1c90900478ea4ecab51e9a058af"><a name="zh-cn_topic_0000001173164749_ab377d1c90900478ea4ecab51e9a058af"></a><a name="zh-cn_topic_0000001173164749_ab377d1c90900478ea4ecab51e9a058af"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="8.73%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001173164749_p824610360217"><a name="zh-cn_topic_0000001173164749_p824610360217"></a><a name="zh-cn_topic_0000001173164749_p824610360217"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="51.339999999999996%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001173164749_a1d574a0044ed42ec8a2603bc82734232"><a name="zh-cn_topic_0000001173164749_a1d574a0044ed42ec8a2603bc82734232"></a><a name="zh-cn_topic_0000001173164749_a1d574a0044ed42ec8a2603bc82734232"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001173164749_row174491921121516"><td class="cellrowborder" valign="top" width="15.479999999999999%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173164749_p886612215154"><a name="zh-cn_topic_0000001173164749_p886612215154"></a><a name="zh-cn_topic_0000001173164749_p886612215154"></a>muted</p>
</td>
<td class="cellrowborder" valign="top" width="13.04%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173164749_p2086602211514"><a name="zh-cn_topic_0000001173164749_p2086602211514"></a><a name="zh-cn_topic_0000001173164749_p2086602211514"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="11.41%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173164749_p17866222171514"><a name="zh-cn_topic_0000001173164749_p17866222171514"></a><a name="zh-cn_topic_0000001173164749_p17866222171514"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="8.73%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173164749_p6866102231512"><a name="zh-cn_topic_0000001173164749_p6866102231512"></a><a name="zh-cn_topic_0000001173164749_p6866102231512"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="51.339999999999996%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173164749_p58668224150"><a name="zh-cn_topic_0000001173164749_p58668224150"></a><a name="zh-cn_topic_0000001173164749_p58668224150"></a>视频是否静音播放。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164749_row198031871157"><td class="cellrowborder" valign="top" width="15.479999999999999%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173164749_p886615229150"><a name="zh-cn_topic_0000001173164749_p886615229150"></a><a name="zh-cn_topic_0000001173164749_p886615229150"></a>src</p>
</td>
<td class="cellrowborder" valign="top" width="13.04%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173164749_p18664223156"><a name="zh-cn_topic_0000001173164749_p18664223156"></a><a name="zh-cn_topic_0000001173164749_p18664223156"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="11.41%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173164749_p1786642214154"><a name="zh-cn_topic_0000001173164749_p1786642214154"></a><a name="zh-cn_topic_0000001173164749_p1786642214154"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.73%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173164749_p108661922191514"><a name="zh-cn_topic_0000001173164749_p108661922191514"></a><a name="zh-cn_topic_0000001173164749_p108661922191514"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="51.339999999999996%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173164749_p28661822121511"><a name="zh-cn_topic_0000001173164749_p28661822121511"></a><a name="zh-cn_topic_0000001173164749_p28661822121511"></a>播放视频内容的路径。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164749_row84223141151"><td class="cellrowborder" valign="top" width="15.479999999999999%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173164749_p1486615224155"><a name="zh-cn_topic_0000001173164749_p1486615224155"></a><a name="zh-cn_topic_0000001173164749_p1486615224155"></a>autoplay</p>
</td>
<td class="cellrowborder" valign="top" width="13.04%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173164749_p8866202219150"><a name="zh-cn_topic_0000001173164749_p8866202219150"></a><a name="zh-cn_topic_0000001173164749_p8866202219150"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="11.41%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173164749_p168661222171510"><a name="zh-cn_topic_0000001173164749_p168661222171510"></a><a name="zh-cn_topic_0000001173164749_p168661222171510"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="8.73%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173164749_p1786618220151"><a name="zh-cn_topic_0000001173164749_p1786618220151"></a><a name="zh-cn_topic_0000001173164749_p1786618220151"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="51.339999999999996%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173164749_p1386610221157"><a name="zh-cn_topic_0000001173164749_p1386610221157"></a><a name="zh-cn_topic_0000001173164749_p1386610221157"></a>视频是否自动播放。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164749_row4862225151"><td class="cellrowborder" valign="top" width="15.479999999999999%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173164749_p4867112211519"><a name="zh-cn_topic_0000001173164749_p4867112211519"></a><a name="zh-cn_topic_0000001173164749_p4867112211519"></a>controls</p>
</td>
<td class="cellrowborder" valign="top" width="13.04%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173164749_p486742231516"><a name="zh-cn_topic_0000001173164749_p486742231516"></a><a name="zh-cn_topic_0000001173164749_p486742231516"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="11.41%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173164749_p118671822171510"><a name="zh-cn_topic_0000001173164749_p118671822171510"></a><a name="zh-cn_topic_0000001173164749_p118671822171510"></a>true</p>
</td>
<td class="cellrowborder" valign="top" width="8.73%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173164749_p148678225153"><a name="zh-cn_topic_0000001173164749_p148678225153"></a><a name="zh-cn_topic_0000001173164749_p148678225153"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="51.339999999999996%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173164749_p1286742213153"><a name="zh-cn_topic_0000001173164749_p1286742213153"></a><a name="zh-cn_topic_0000001173164749_p1286742213153"></a>控制视频播放的控制栏是否显示，如果设置为false，则不显示控制栏。默认为true，由系统决定显示或隐藏控制栏。</p>
</td>
</tr>
</tbody>
</table>

## 样式<a name="zh-cn_topic_0000001173164749_sfbde25405aca4513a9c938f2f339b770"></a>

除支持[通用样式](js-components-common-styles.md#ZH-CN_TOPIC_0000001163932190)外，还支持如下样式：

<a name="zh-cn_topic_0000001173164749_table772815434205"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001173164749_row8728104352011"><th class="cellrowborder" valign="top" width="23.11768823117688%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001173164749_p8728104312012"><a name="zh-cn_topic_0000001173164749_p8728104312012"></a><a name="zh-cn_topic_0000001173164749_p8728104312012"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="20.477952204779523%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001173164749_p187282438206"><a name="zh-cn_topic_0000001173164749_p187282438206"></a><a name="zh-cn_topic_0000001173164749_p187282438206"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="8.869113088691131%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001173164749_p12729114318201"><a name="zh-cn_topic_0000001173164749_p12729114318201"></a><a name="zh-cn_topic_0000001173164749_p12729114318201"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.519248075192481%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001173164749_p17729104352013"><a name="zh-cn_topic_0000001173164749_p17729104352013"></a><a name="zh-cn_topic_0000001173164749_p17729104352013"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="40.01599840015999%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001173164749_p7729104317207"><a name="zh-cn_topic_0000001173164749_p7729104317207"></a><a name="zh-cn_topic_0000001173164749_p7729104317207"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001173164749_row117291043172018"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173164749_p15729184311209"><a name="zh-cn_topic_0000001173164749_p15729184311209"></a><a name="zh-cn_topic_0000001173164749_p15729184311209"></a>object-fit</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173164749_p117291543122015"><a name="zh-cn_topic_0000001173164749_p117291543122015"></a><a name="zh-cn_topic_0000001173164749_p117291543122015"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173164749_p672911431201"><a name="zh-cn_topic_0000001173164749_p672911431201"></a><a name="zh-cn_topic_0000001173164749_p672911431201"></a>contain</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173164749_p207294433207"><a name="zh-cn_topic_0000001173164749_p207294433207"></a><a name="zh-cn_topic_0000001173164749_p207294433207"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173164749_p1729184392013"><a name="zh-cn_topic_0000001173164749_p1729184392013"></a><a name="zh-cn_topic_0000001173164749_p1729184392013"></a>视频源的缩放类型，如果poster设置了值，那么此配置还会影响视频海报的缩放类型，可选值参考<a href="#zh-cn_topic_0000001173164749_t8eca568266d54af484fec0f84185e923">表1</a>。</p>
</td>
</tr>
</tbody>
</table>

**表 1**  object-fit 类型说明

<a name="zh-cn_topic_0000001173164749_t8eca568266d54af484fec0f84185e923"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001173164749_r9b22bdd1cd2d4050a840c205bd25f5f2"><th class="cellrowborder" valign="top" width="15.02%" id="mcps1.2.3.1.1"><p id="zh-cn_topic_0000001173164749_aaf9dd8d06c5b44b8a13e3c6e17e29493"><a name="zh-cn_topic_0000001173164749_aaf9dd8d06c5b44b8a13e3c6e17e29493"></a><a name="zh-cn_topic_0000001173164749_aaf9dd8d06c5b44b8a13e3c6e17e29493"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="84.98%" id="mcps1.2.3.1.2"><p id="zh-cn_topic_0000001173164749_a63d0fe8b723d4ddfa21fc1fbb3e48165"><a name="zh-cn_topic_0000001173164749_a63d0fe8b723d4ddfa21fc1fbb3e48165"></a><a name="zh-cn_topic_0000001173164749_a63d0fe8b723d4ddfa21fc1fbb3e48165"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001173164749_ref689a9f315e4ffea4cd2d1a19bd1773"><td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001173164749_p11586163511379"><a name="zh-cn_topic_0000001173164749_p11586163511379"></a><a name="zh-cn_topic_0000001173164749_p11586163511379"></a>fill</p>
</td>
<td class="cellrowborder" valign="top" width="84.98%" headers="mcps1.2.3.1.2 "><p id="zh-cn_topic_0000001173164749_p958611356373"><a name="zh-cn_topic_0000001173164749_p958611356373"></a><a name="zh-cn_topic_0000001173164749_p958611356373"></a>不保持宽高比进行放大缩小，使得图片填充满显示边界。</p>
</td>
</tr>
</tbody>
</table>

## 事件<a name="zh-cn_topic_0000001173164749_section4181420161817"></a>

除支持[通用事件](js-components-common-events.md#ZH-CN_TOPIC_0000001209412119)外，还支持如下事件：

<a name="zh-cn_topic_0000001173164749_table836435619510"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001173164749_row153658563517"><th class="cellrowborder" valign="top" width="24.852485248524854%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173164749_a426b8903842d48fa8012a24ff3c997eb"><a name="zh-cn_topic_0000001173164749_a426b8903842d48fa8012a24ff3c997eb"></a><a name="zh-cn_topic_0000001173164749_a426b8903842d48fa8012a24ff3c997eb"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="29.552955295529554%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173164749_a53448ba47e5e4ae9bf7774c90820e970"><a name="zh-cn_topic_0000001173164749_a53448ba47e5e4ae9bf7774c90820e970"></a><a name="zh-cn_topic_0000001173164749_a53448ba47e5e4ae9bf7774c90820e970"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="45.5945594559456%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173164749_add489ff50c444f24b759162c7f4bad9a"><a name="zh-cn_topic_0000001173164749_add489ff50c444f24b759162c7f4bad9a"></a><a name="zh-cn_topic_0000001173164749_add489ff50c444f24b759162c7f4bad9a"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001173164749_row116621079194"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164749_p14995128101920"><a name="zh-cn_topic_0000001173164749_p14995128101920"></a><a name="zh-cn_topic_0000001173164749_p14995128101920"></a>prepared</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164749_p1499513871918"><a name="zh-cn_topic_0000001173164749_p1499513871918"></a><a name="zh-cn_topic_0000001173164749_p1499513871918"></a>{ duration: value }<sup id="zh-cn_topic_0000001173164749_sup29931815101312"><a name="zh-cn_topic_0000001173164749_sup29931815101312"></a><a name="zh-cn_topic_0000001173164749_sup29931815101312"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164749_p1399519841911"><a name="zh-cn_topic_0000001173164749_p1399519841911"></a><a name="zh-cn_topic_0000001173164749_p1399519841911"></a>视频准备完成时触发该事件，通过duration可以获取视频时长，单位为s。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164749_row76639781919"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164749_p1899514821910"><a name="zh-cn_topic_0000001173164749_p1899514821910"></a><a name="zh-cn_topic_0000001173164749_p1899514821910"></a>start</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164749_p1899516816193"><a name="zh-cn_topic_0000001173164749_p1899516816193"></a><a name="zh-cn_topic_0000001173164749_p1899516816193"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164749_p8995182197"><a name="zh-cn_topic_0000001173164749_p8995182197"></a><a name="zh-cn_topic_0000001173164749_p8995182197"></a>播放时触发该事件。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164749_row1066387181915"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164749_p1899616891919"><a name="zh-cn_topic_0000001173164749_p1899616891919"></a><a name="zh-cn_topic_0000001173164749_p1899616891919"></a>pause</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164749_p109962861914"><a name="zh-cn_topic_0000001173164749_p109962861914"></a><a name="zh-cn_topic_0000001173164749_p109962861914"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164749_p1699615891918"><a name="zh-cn_topic_0000001173164749_p1699615891918"></a><a name="zh-cn_topic_0000001173164749_p1699615891918"></a>暂停时触发该事件。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164749_row1131820251916"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164749_p59966831917"><a name="zh-cn_topic_0000001173164749_p59966831917"></a><a name="zh-cn_topic_0000001173164749_p59966831917"></a>finish</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164749_p1799619831915"><a name="zh-cn_topic_0000001173164749_p1799619831915"></a><a name="zh-cn_topic_0000001173164749_p1799619831915"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164749_p199688111910"><a name="zh-cn_topic_0000001173164749_p199688111910"></a><a name="zh-cn_topic_0000001173164749_p199688111910"></a>播放结束时触发该事件。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164749_row11318921194"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164749_p09964811192"><a name="zh-cn_topic_0000001173164749_p09964811192"></a><a name="zh-cn_topic_0000001173164749_p09964811192"></a>error</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164749_p999616871916"><a name="zh-cn_topic_0000001173164749_p999616871916"></a><a name="zh-cn_topic_0000001173164749_p999616871916"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164749_p399615871913"><a name="zh-cn_topic_0000001173164749_p399615871913"></a><a name="zh-cn_topic_0000001173164749_p399615871913"></a>播放失败时触发该事件。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164749_row143184219194"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164749_p109962812198"><a name="zh-cn_topic_0000001173164749_p109962812198"></a><a name="zh-cn_topic_0000001173164749_p109962812198"></a>seeking</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164749_p6996118201915"><a name="zh-cn_topic_0000001173164749_p6996118201915"></a><a name="zh-cn_topic_0000001173164749_p6996118201915"></a>{ currenttime: value }</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164749_p1599615891917"><a name="zh-cn_topic_0000001173164749_p1599615891917"></a><a name="zh-cn_topic_0000001173164749_p1599615891917"></a>操作进度条过程时上报时间信息，单位为s。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164749_row1637115611818"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164749_p149964831912"><a name="zh-cn_topic_0000001173164749_p149964831912"></a><a name="zh-cn_topic_0000001173164749_p149964831912"></a>seeked</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164749_p19996182197"><a name="zh-cn_topic_0000001173164749_p19996182197"></a><a name="zh-cn_topic_0000001173164749_p19996182197"></a>{ currenttime: value }</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164749_p109961085199"><a name="zh-cn_topic_0000001173164749_p109961085199"></a><a name="zh-cn_topic_0000001173164749_p109961085199"></a>操作进度条完成后，上报播放时间信息，单位为s。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164749_row1766775361814"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164749_p129965831916"><a name="zh-cn_topic_0000001173164749_p129965831916"></a><a name="zh-cn_topic_0000001173164749_p129965831916"></a>timeupdate</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164749_p4996386196"><a name="zh-cn_topic_0000001173164749_p4996386196"></a><a name="zh-cn_topic_0000001173164749_p4996386196"></a>{ currenttime: value }</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164749_p179976820190"><a name="zh-cn_topic_0000001173164749_p179976820190"></a><a name="zh-cn_topic_0000001173164749_p179976820190"></a>播放进度变化时触发该事件，单位为s，更新时间间隔为250ms。</p>
</td>
</tr>
</tbody>
</table>

## 方法<a name="zh-cn_topic_0000001173164749_s557cc2f457ff42a193807500adae2f91"></a>

除支持[通用方法](js-components-common-methods.md#ZH-CN_TOPIC_0000001209252157)外，还支持如下方法：

<a name="zh-cn_topic_0000001173164749_t0b0d71e0664f479d9fbcfe2cf45b34a0"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001173164749_r80520812e64447b7a841590ba3d1ecf9"><th class="cellrowborder" valign="top" width="28.000000000000004%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173164749_ab440f3031e7242d1a1ee00ba387b151f"><a name="zh-cn_topic_0000001173164749_ab440f3031e7242d1a1ee00ba387b151f"></a><a name="zh-cn_topic_0000001173164749_ab440f3031e7242d1a1ee00ba387b151f"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="42%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173164749_a1e28b7e4cdc84e9eacc51b8ce51590df"><a name="zh-cn_topic_0000001173164749_a1e28b7e4cdc84e9eacc51b8ce51590df"></a><a name="zh-cn_topic_0000001173164749_a1e28b7e4cdc84e9eacc51b8ce51590df"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="30%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173164749_ad91f1de026e24e60b0fe5078f4226f65"><a name="zh-cn_topic_0000001173164749_ad91f1de026e24e60b0fe5078f4226f65"></a><a name="zh-cn_topic_0000001173164749_ad91f1de026e24e60b0fe5078f4226f65"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001173164749_rab3c226807734a8d874bf83c939d52ad"><td class="cellrowborder" valign="top" width="28.000000000000004%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164749_ac317a80879064915a1a09cef7e3070d2"><a name="zh-cn_topic_0000001173164749_ac317a80879064915a1a09cef7e3070d2"></a><a name="zh-cn_topic_0000001173164749_ac317a80879064915a1a09cef7e3070d2"></a>start</p>
</td>
<td class="cellrowborder" valign="top" width="42%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164749_a1589994065b74673b39ff67b72e3ec82"><a name="zh-cn_topic_0000001173164749_a1589994065b74673b39ff67b72e3ec82"></a><a name="zh-cn_topic_0000001173164749_a1589994065b74673b39ff67b72e3ec82"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164749_ad610eacf0ae748a0bd0611c6bd10d49d"><a name="zh-cn_topic_0000001173164749_ad610eacf0ae748a0bd0611c6bd10d49d"></a><a name="zh-cn_topic_0000001173164749_ad610eacf0ae748a0bd0611c6bd10d49d"></a>请求播放视频。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164749_r74d47c5360ae4f87936bde197795b0e5"><td class="cellrowborder" valign="top" width="28.000000000000004%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164749_a5488606f848644c1b250b35137b770f9"><a name="zh-cn_topic_0000001173164749_a5488606f848644c1b250b35137b770f9"></a><a name="zh-cn_topic_0000001173164749_a5488606f848644c1b250b35137b770f9"></a>pause</p>
</td>
<td class="cellrowborder" valign="top" width="42%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164749_a715471504ba24456b9c69a09898e8025"><a name="zh-cn_topic_0000001173164749_a715471504ba24456b9c69a09898e8025"></a><a name="zh-cn_topic_0000001173164749_a715471504ba24456b9c69a09898e8025"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164749_a4d7fc26ada3c4c9b86818e40259494e6"><a name="zh-cn_topic_0000001173164749_a4d7fc26ada3c4c9b86818e40259494e6"></a><a name="zh-cn_topic_0000001173164749_a4d7fc26ada3c4c9b86818e40259494e6"></a>请求暂停播放视频。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164749_rc1629488abde4974938cc5c17937dbc6"><td class="cellrowborder" valign="top" width="28.000000000000004%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164749_a74f637bafd5348bb96414961031ca01d"><a name="zh-cn_topic_0000001173164749_a74f637bafd5348bb96414961031ca01d"></a><a name="zh-cn_topic_0000001173164749_a74f637bafd5348bb96414961031ca01d"></a>setCurrentTime</p>
</td>
<td class="cellrowborder" valign="top" width="42%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164749_a65bc7bf0576a4e47bff523bd15ca560c"><a name="zh-cn_topic_0000001173164749_a65bc7bf0576a4e47bff523bd15ca560c"></a><a name="zh-cn_topic_0000001173164749_a65bc7bf0576a4e47bff523bd15ca560c"></a>{ currenttime: value }</p>
</td>
<td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164749_a421ac9c67d5444338709bb7be34d06ec"><a name="zh-cn_topic_0000001173164749_a421ac9c67d5444338709bb7be34d06ec"></a><a name="zh-cn_topic_0000001173164749_a421ac9c67d5444338709bb7be34d06ec"></a>指定视频播放的进度位置，单位为s。</p>
</td>
</tr>
</tbody>
</table>

