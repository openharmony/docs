# panel<a name="ZH-CN_TOPIC_0000001115974732"></a>

-   [权限列表](#zh-cn_topic_0000001062321291_section11257113618419)
-   [子组件](#zh-cn_topic_0000001062321291_section19368335134016)
-   [属性](#zh-cn_topic_0000001062321291_section1100152194018)
-   [样式](#zh-cn_topic_0000001062321291_section1137118175437)
-   [事件](#zh-cn_topic_0000001062321291_section1614413538447)
-   [方法](#zh-cn_topic_0000001062321291_section165301745164719)
-   [示例](#zh-cn_topic_0000001062321291_section36743614499)

可滑动面板。提供一种轻量的内容展示的窗口，可方便的在不同尺寸中切换。属于弹出式组件。

>![](public_sys-resources/icon-note.gif) **说明：** 
>从API Version 5 开始支持。

## 权限列表<a name="zh-cn_topic_0000001062321291_section11257113618419"></a>

无

## 子组件<a name="zh-cn_topic_0000001062321291_section19368335134016"></a>

支持

## 属性<a name="zh-cn_topic_0000001062321291_section1100152194018"></a>

<a name="zh-cn_topic_0000001062321291_table20633101642315"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001062321291_row663331618238"><th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p942mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p942mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p942mcpsimp"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="23.169999999999998%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p944mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p944mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p944mcpsimp"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="10.59%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p946mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p946mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p946mcpsimp"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.359999999999999%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001062321291_p824610360217"><a name="zh-cn_topic_0000001062321291_p824610360217"></a><a name="zh-cn_topic_0000001062321291_p824610360217"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="35.76%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p948mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p948mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p948mcpsimp"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001062321291_row741201424216"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001062321291_p1555482064215"><a name="zh-cn_topic_0000001062321291_p1555482064215"></a><a name="zh-cn_topic_0000001062321291_p1555482064215"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="23.169999999999998%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001062321291_p195541120124212"><a name="zh-cn_topic_0000001062321291_p195541120124212"></a><a name="zh-cn_topic_0000001062321291_p195541120124212"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.59%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001062321291_p05541220194219"><a name="zh-cn_topic_0000001062321291_p05541220194219"></a><a name="zh-cn_topic_0000001062321291_p05541220194219"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.359999999999999%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001062321291_p155541220104216"><a name="zh-cn_topic_0000001062321291_p155541220104216"></a><a name="zh-cn_topic_0000001062321291_p155541220104216"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001062321291_p175541420104219"><a name="zh-cn_topic_0000001062321291_p175541420104219"></a><a name="zh-cn_topic_0000001062321291_p175541420104219"></a>设置可滑动面板类型，不可动态变更，可选值有：</p>
<a name="zh-cn_topic_0000001062321291_ul15554620204219"></a><a name="zh-cn_topic_0000001062321291_ul15554620204219"></a><ul id="zh-cn_topic_0000001062321291_ul15554620204219"><li><p id="zh-cn_topic_0000001062321291_p555417208423"><a name="zh-cn_topic_0000001062321291_p555417208423"></a><a name="zh-cn_topic_0000001062321291_p555417208423"></a>minibar：提供minibar和类全屏展示切换效果。</p>
</li><li><p id="zh-cn_topic_0000001062321291_p15554920204216"><a name="zh-cn_topic_0000001062321291_p15554920204216"></a><a name="zh-cn_topic_0000001062321291_p15554920204216"></a>foldable：内容永久展示类，提供大（类全屏）、中（类半屏）、小三种尺寸展示切换效果。</p>
</li><li><p id="zh-cn_topic_0000001062321291_p35545206423"><a name="zh-cn_topic_0000001062321291_p35545206423"></a><a name="zh-cn_topic_0000001062321291_p35545206423"></a>temporary：内容临时展示区，提供大（类全屏）、中（类半屏）两种尺寸展示切换效果。</p>
</li></ul>
</td>
</tr>
<tr id="zh-cn_topic_0000001062321291_row1815511615424"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001062321291_p1755419206420"><a name="zh-cn_topic_0000001062321291_p1755419206420"></a><a name="zh-cn_topic_0000001062321291_p1755419206420"></a>mode</p>
</td>
<td class="cellrowborder" valign="top" width="23.169999999999998%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001062321291_p135544206422"><a name="zh-cn_topic_0000001062321291_p135544206422"></a><a name="zh-cn_topic_0000001062321291_p135544206422"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.59%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001062321291_p13554192010427"><a name="zh-cn_topic_0000001062321291_p13554192010427"></a><a name="zh-cn_topic_0000001062321291_p13554192010427"></a>full</p>
</td>
<td class="cellrowborder" valign="top" width="7.359999999999999%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001062321291_p155418205426"><a name="zh-cn_topic_0000001062321291_p155418205426"></a><a name="zh-cn_topic_0000001062321291_p155418205426"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001062321291_p655415206425"><a name="zh-cn_topic_0000001062321291_p655415206425"></a><a name="zh-cn_topic_0000001062321291_p655415206425"></a>设置初始状态，mode参数可选值为：</p>
<a name="zh-cn_topic_0000001062321291_ol6554220154216"></a><a name="zh-cn_topic_0000001062321291_ol6554220154216"></a><ol id="zh-cn_topic_0000001062321291_ol6554220154216"><li><p id="zh-cn_topic_0000001062321291_p12554520154216"><a name="zh-cn_topic_0000001062321291_p12554520154216"></a><a name="zh-cn_topic_0000001062321291_p12554520154216"></a>mini：类型为minibar和foldable时，为最小状态；类型为temporary，则不生效。</p>
</li><li><p id="zh-cn_topic_0000001062321291_p1955422014218"><a name="zh-cn_topic_0000001062321291_p1955422014218"></a><a name="zh-cn_topic_0000001062321291_p1955422014218"></a>half: 类型为foldable和temporary时，为类半屏状态；类型为minibar，则不生效。</p>
</li><li><p id="zh-cn_topic_0000001062321291_p15541020134214"><a name="zh-cn_topic_0000001062321291_p15541020134214"></a><a name="zh-cn_topic_0000001062321291_p15541020134214"></a>full: 类全屏状态。</p>
</li></ol>
</td>
</tr>
<tr id="zh-cn_topic_0000001062321291_row1213173154220"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001062321291_p855432019421"><a name="zh-cn_topic_0000001062321291_p855432019421"></a><a name="zh-cn_topic_0000001062321291_p855432019421"></a>dragbar</p>
</td>
<td class="cellrowborder" valign="top" width="23.169999999999998%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001062321291_p155482015422"><a name="zh-cn_topic_0000001062321291_p155482015422"></a><a name="zh-cn_topic_0000001062321291_p155482015422"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.59%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001062321291_p1955552064210"><a name="zh-cn_topic_0000001062321291_p1955552064210"></a><a name="zh-cn_topic_0000001062321291_p1955552064210"></a>true</p>
</td>
<td class="cellrowborder" valign="top" width="7.359999999999999%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001062321291_p755542024213"><a name="zh-cn_topic_0000001062321291_p755542024213"></a><a name="zh-cn_topic_0000001062321291_p755542024213"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001062321291_p135551520114215"><a name="zh-cn_topic_0000001062321291_p135551520114215"></a><a name="zh-cn_topic_0000001062321291_p135551520114215"></a>设置是否存在dragbar，true表示存在，false表示不存在。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001062321291_row827211578416"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001062321291_p55550201428"><a name="zh-cn_topic_0000001062321291_p55550201428"></a><a name="zh-cn_topic_0000001062321291_p55550201428"></a>fullheight</p>
</td>
<td class="cellrowborder" valign="top" width="23.169999999999998%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001062321291_p2055572012425"><a name="zh-cn_topic_0000001062321291_p2055572012425"></a><a name="zh-cn_topic_0000001062321291_p2055572012425"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.59%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001062321291_p145551220104214"><a name="zh-cn_topic_0000001062321291_p145551220104214"></a><a name="zh-cn_topic_0000001062321291_p145551220104214"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.359999999999999%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001062321291_p1555182013429"><a name="zh-cn_topic_0000001062321291_p1555182013429"></a><a name="zh-cn_topic_0000001062321291_p1555182013429"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001062321291_p16555102011423"><a name="zh-cn_topic_0000001062321291_p16555102011423"></a><a name="zh-cn_topic_0000001062321291_p16555102011423"></a>指定full状态下的高度，默认为屏幕尺寸 - 8px。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001062321291_row9344751124116"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001062321291_p10555162017420"><a name="zh-cn_topic_0000001062321291_p10555162017420"></a><a name="zh-cn_topic_0000001062321291_p10555162017420"></a>halfheight</p>
</td>
<td class="cellrowborder" valign="top" width="23.169999999999998%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001062321291_p1055572011422"><a name="zh-cn_topic_0000001062321291_p1055572011422"></a><a name="zh-cn_topic_0000001062321291_p1055572011422"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.59%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001062321291_p19555192018423"><a name="zh-cn_topic_0000001062321291_p19555192018423"></a><a name="zh-cn_topic_0000001062321291_p19555192018423"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.359999999999999%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001062321291_p5555720134214"><a name="zh-cn_topic_0000001062321291_p5555720134214"></a><a name="zh-cn_topic_0000001062321291_p5555720134214"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001062321291_p17555320194211"><a name="zh-cn_topic_0000001062321291_p17555320194211"></a><a name="zh-cn_topic_0000001062321291_p17555320194211"></a>指定half状态下的高度，默认为屏幕尺寸的一半。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001062321291_row278634674117"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001062321291_p18556132014422"><a name="zh-cn_topic_0000001062321291_p18556132014422"></a><a name="zh-cn_topic_0000001062321291_p18556132014422"></a>miniheight</p>
</td>
<td class="cellrowborder" valign="top" width="23.169999999999998%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001062321291_p5556920194212"><a name="zh-cn_topic_0000001062321291_p5556920194212"></a><a name="zh-cn_topic_0000001062321291_p5556920194212"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.59%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001062321291_p15561207425"><a name="zh-cn_topic_0000001062321291_p15561207425"></a><a name="zh-cn_topic_0000001062321291_p15561207425"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.359999999999999%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001062321291_p55565208428"><a name="zh-cn_topic_0000001062321291_p55565208428"></a><a name="zh-cn_topic_0000001062321291_p55565208428"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001062321291_p115561020164217"><a name="zh-cn_topic_0000001062321291_p115561020164217"></a><a name="zh-cn_topic_0000001062321291_p115561020164217"></a>指定mini状态下的高度，默认为48px。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001062321291_row36332165231"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p952mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p952mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p952mcpsimp"></a>id</p>
</td>
<td class="cellrowborder" valign="top" width="23.169999999999998%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p954mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p954mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p954mcpsimp"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.59%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p956mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p956mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p956mcpsimp"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.359999999999999%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001062321291_p42461736102118"><a name="zh-cn_topic_0000001062321291_p42461736102118"></a><a name="zh-cn_topic_0000001062321291_p42461736102118"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p958mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p958mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p958mcpsimp"></a>组件的唯一标识。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001062321291_row13633131616239"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p961mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p961mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p961mcpsimp"></a>style</p>
</td>
<td class="cellrowborder" valign="top" width="23.169999999999998%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p963mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p963mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p963mcpsimp"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.59%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p965mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p965mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p965mcpsimp"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.359999999999999%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001062321291_p17246836142119"><a name="zh-cn_topic_0000001062321291_p17246836142119"></a><a name="zh-cn_topic_0000001062321291_p17246836142119"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p967mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p967mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p967mcpsimp"></a>组件的样式声明。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001062321291_row10634131610230"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p970mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p970mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p970mcpsimp"></a>class</p>
</td>
<td class="cellrowborder" valign="top" width="23.169999999999998%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p972mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p972mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p972mcpsimp"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.59%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p974mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p974mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p974mcpsimp"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.359999999999999%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001062321291_p324614367213"><a name="zh-cn_topic_0000001062321291_p324614367213"></a><a name="zh-cn_topic_0000001062321291_p324614367213"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p976mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p976mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p976mcpsimp"></a>组件的样式类，用于引用样式表。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001062321291_row1634171618236"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_p1786251117156"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_p1786251117156"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_p1786251117156"></a>ref</p>
</td>
<td class="cellrowborder" valign="top" width="23.169999999999998%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_p1086241119157"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_p1086241119157"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_p1086241119157"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.59%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_p586281111151"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_p586281111151"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_p586281111151"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.359999999999999%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001062321291_p1624612362219"><a name="zh-cn_topic_0000001062321291_p1624612362219"></a><a name="zh-cn_topic_0000001062321291_p1624612362219"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_p113416153342"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_p113416153342"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_p113416153342"></a>用来指定指向子元素<span id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_ph56099211134"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_ph56099211134"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_ph56099211134"></a>或子组件</span>的引用信息，该引用将注册到父组件的$refs 属性对象上。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001062321291_row1263451617236"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p997mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p997mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p997mcpsimp"></a>data</p>
</td>
<td class="cellrowborder" valign="top" width="23.169999999999998%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p999mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p999mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p999mcpsimp"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.59%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p1001mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p1001mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p1001mcpsimp"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.359999999999999%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001062321291_p22471736132114"><a name="zh-cn_topic_0000001062321291_p22471736132114"></a><a name="zh-cn_topic_0000001062321291_p22471736132114"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p1003mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p1003mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050831187_zh-cn_topic_0000000000611464_p1003mcpsimp"></a>给当前组件设置data属性，进行相应的数据存储和读取。</p>
</td>
</tr>
</tbody>
</table>

>![](public_sys-resources/icon-note.gif) **说明：** 
>panel可滑动面板暂不支持渲染属性，包括for、if和show。

## 样式<a name="zh-cn_topic_0000001062321291_section1137118175437"></a>

<a name="zh-cn_topic_0000001062321291_table1744514388541"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001062321291_row1244614388545"><th class="cellrowborder" valign="top" width="23.11768823117688%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1060mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1060mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1060mcpsimp"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="20.477952204779523%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1062mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1062mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1062mcpsimp"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="8.869113088691131%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1064mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1064mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1064mcpsimp"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.519248075192481%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001062321291_p117421754619"><a name="zh-cn_topic_0000001062321291_p117421754619"></a><a name="zh-cn_topic_0000001062321291_p117421754619"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="40.01599840015999%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1066mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1066mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1066mcpsimp"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001062321291_row18446638145412"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1088mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1088mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1088mcpsimp"></a>padding</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1090mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1090mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1090mcpsimp"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1092mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1092mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1092mcpsimp"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p19729127112814"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p19729127112814"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p19729127112814"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><div class="p" id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1094mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1094mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1094mcpsimp"></a>该属性可以有1到4个值：<a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_ul15202134923211"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_ul15202134923211"></a><ul id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_ul15202134923211"><li><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p10614155353215"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p10614155353215"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p10614155353215"></a>指定一个值时，该值指定四个边的内边距。</p>
</li><li><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p10614175393216"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p10614175393216"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p10614175393216"></a>指定两个值时，第一个值指定上下两边的内边距，第二个指定左右两边的内边距。</p>
</li><li><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p8614205393214"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p8614205393214"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p8614205393214"></a>指定三个值时，第一个指定上边的内边距，第二个指定左右两边的内边距，第三个指定下边的内边距。</p>
</li><li><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p106141853193215"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p106141853193215"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p106141853193215"></a>指定四个值时分别为上、右、下、左边的内边距（顺时针顺序）。</p>
</li></ul>
</div>
</td>
</tr>
<tr id="zh-cn_topic_0000001062321291_row24464380544"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1097mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1097mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1097mcpsimp"></a>padding-[left|top|right|bottom]</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1099mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1099mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1099mcpsimp"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1101mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1101mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1101mcpsimp"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p11729374289"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p11729374289"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p11729374289"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1103mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1103mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1103mcpsimp"></a>设置左、上、右、下内边距属性。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001062321291_row1144723845412"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p769124717365"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p769124717365"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p769124717365"></a>padding-[start|end]</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p157617124374"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p157617124374"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p157617124374"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p1069144703616"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p1069144703616"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p1069144703616"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p1373027182819"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p1373027182819"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p1373027182819"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p1269184753610"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p1269184753610"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p1269184753610"></a>设置起始和末端内边距属性。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001062321291_row11447438175410"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1106mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1106mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1106mcpsimp"></a>margin</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1108mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1108mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1108mcpsimp"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1110mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1110mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1110mcpsimp"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p4730774285"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p4730774285"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p4730774285"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1112mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1112mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1112mcpsimp"></a>使用简写属性设置所有的外边距属性，该属性可以有1到4个值。</p>
<a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_ul5333133311105"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_ul5333133311105"></a><ul id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_ul5333133311105"><li><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p03345339103"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p03345339103"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p03345339103"></a>只有一个值时，这个值会被指定给全部的四个边。</p>
</li><li><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p1133420334108"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p1133420334108"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p1133420334108"></a>两个值时，第一个值被匹配给上和下，第二个值被匹配给左和右。</p>
</li><li><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p193341533191015"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p193341533191015"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p193341533191015"></a>三个值时，第一个值被匹配给上, 第二个值被匹配给左和右，第三个值被匹配给下。</p>
</li><li><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p733412334102"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p733412334102"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p733412334102"></a>四个值时，会依次按上、右、下、左的顺序匹配 (即顺时针顺序)。</p>
</li></ul>
</td>
</tr>
<tr id="zh-cn_topic_0000001062321291_row144473383544"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1115mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1115mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1115mcpsimp"></a>margin-[left|top|right|bottom]</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1117mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1117mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1117mcpsimp"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1119mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1119mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1119mcpsimp"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p773013742811"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p773013742811"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p773013742811"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1121mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1121mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1121mcpsimp"></a>设置左、上、右、下外边距属性。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001062321291_row944743811541"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p9492107123816"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p9492107123816"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p9492107123816"></a>margin-[start|end]</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p157617124374_1"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p157617124374_1"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p157617124374_1"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p1549213793811"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p1549213793811"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p1549213793811"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001062321291_p117511744618"><a name="zh-cn_topic_0000001062321291_p117511744618"></a><a name="zh-cn_topic_0000001062321291_p117511744618"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p1049212715388"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p1049212715388"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p1049212715388"></a>设置起始和末端外边距属性。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001062321291_row16447238155411"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1124mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1124mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1124mcpsimp"></a>border</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1126mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1126mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1126mcpsimp"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1128mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1128mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1128mcpsimp"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001062321291_p11175131715467"><a name="zh-cn_topic_0000001062321291_p11175131715467"></a><a name="zh-cn_topic_0000001062321291_p11175131715467"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1130mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1130mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1130mcpsimp"></a>使用简写属性设置所有的边框属性，包含边框的宽度，样式，颜色属性，顺序设置为border-width、border-style、border-color，不设置时，各属性值为默认值。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001062321291_row4447138115414"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1133mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1133mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1133mcpsimp"></a>border-style</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p513631613319"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p513631613319"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p513631613319"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1137mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1137mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1137mcpsimp"></a>solid</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001062321291_p617531717464"><a name="zh-cn_topic_0000001062321291_p617531717464"></a><a name="zh-cn_topic_0000001062321291_p617531717464"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p342285712314"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p342285712314"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p342285712314"></a>使用简写属性设置所有边框的样式，可选值为：</p>
<a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_ul1470834505612"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_ul1470834505612"></a><ul id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_ul1470834505612"><li>dotted：显示为一系列圆点，圆点半径为border-width的一半。</li><li>dashed：显示为一系列短的方形虚线。</li></ul>
<a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_ul15621125545612"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_ul15621125545612"></a><ul id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_ul15621125545612"><li>solid：显示为一条实线。</li></ul>
</td>
</tr>
<tr id="zh-cn_topic_0000001062321291_row1656512239262"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p119531437370"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p119531437370"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p119531437370"></a>border-[left|top|right|bottom]-style</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p129532037175"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p129532037175"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p129532037175"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p495312372717"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p495312372717"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p495312372717"></a>solid</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p169534375717"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p169534375717"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p169534375717"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p595353718719"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p595353718719"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p595353718719"></a>分别设置左、上、右、下四个边框的样式，可选值为dotted、dashed、solid。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001062321291_row19448113811542"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1142mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1142mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1142mcpsimp"></a>border-[left|top|right|bottom]</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1144mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1144mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1144mcpsimp"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1146mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1146mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1146mcpsimp"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p67303762810"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p67303762810"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p67303762810"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1148mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1148mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1148mcpsimp"></a>使用简写属性设置对应位置的边框属性，包含边框的宽度，样式，颜色属性，顺序设置为border-width、border-style、border-color，不设置的值为默认值。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001062321291_row124481638165417"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1151mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1151mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1151mcpsimp"></a>border-width</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1153mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1153mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1153mcpsimp"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1155mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1155mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1155mcpsimp"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001062321291_p16175131724618"><a name="zh-cn_topic_0000001062321291_p16175131724618"></a><a name="zh-cn_topic_0000001062321291_p16175131724618"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1157mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1157mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1157mcpsimp"></a>使用简写属性设置元素的所有边框宽度<span id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_ph13216153653618"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_ph13216153653618"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_ph13216153653618"></a>，或者单独为各边边框设置宽度</span>。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001062321291_row54481038165410"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1160mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1160mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1160mcpsimp"></a>border-[left|top|right|bottom]-width</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1162mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1162mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1162mcpsimp"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1164mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1164mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1164mcpsimp"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001062321291_p11175151717466"><a name="zh-cn_topic_0000001062321291_p11175151717466"></a><a name="zh-cn_topic_0000001062321291_p11175151717466"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1166mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1166mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1166mcpsimp"></a>分别设置左、上、右、下四个边框的宽度。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001062321291_row1744817385547"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1169mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1169mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1169mcpsimp"></a>border-color</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1171mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1171mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1171mcpsimp"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1173mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1173mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1173mcpsimp"></a>black</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001062321291_p1017518177465"><a name="zh-cn_topic_0000001062321291_p1017518177465"></a><a name="zh-cn_topic_0000001062321291_p1017518177465"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1175mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1175mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1175mcpsimp"></a>使用简写属性设置元素的所有边框颜色<span id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_ph112821853719"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_ph112821853719"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_ph112821853719"></a>，或者单独为各边边框设置颜色</span>。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001062321291_row844813835410"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1178mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1178mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1178mcpsimp"></a>border-[left|top|right|bottom]-color</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1180mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1180mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1180mcpsimp"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1182mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1182mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1182mcpsimp"></a>black</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001062321291_p11175417184611"><a name="zh-cn_topic_0000001062321291_p11175417184611"></a><a name="zh-cn_topic_0000001062321291_p11175417184611"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1184mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1184mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1184mcpsimp"></a>分别设置左、上、右、下四个边框的颜色。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001062321291_row944813389540"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1187mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1187mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1187mcpsimp"></a>border-radius</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1189mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1189mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1189mcpsimp"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1191mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1191mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1191mcpsimp"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p67306752816"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p67306752816"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p67306752816"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p18998933174117"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p18998933174117"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p18998933174117"></a>border-radius属性是设置元素的外边框圆角半径。<span id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_ph817510495223"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_ph817510495223"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_ph817510495223"></a>设置border-radius时不能单独设置某一个方向的border-[left|top|right|bottom]-width，border-[left|top|right|bottom]-color ，如果要设置color和width，需要将四个方向一起设置（border-width、border-color）。</span></p>
</td>
</tr>
<tr id="zh-cn_topic_0000001062321291_row104494382546"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1198mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1198mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1198mcpsimp"></a>border-[top|bottom]-[left|right]-radius</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1200mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1200mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1200mcpsimp"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1202mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1202mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1202mcpsimp"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p27305718283"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p27305718283"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p27305718283"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1204mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1204mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1204mcpsimp"></a>分别设置左上，右上，右下和左下四个角的圆角半径。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001062321291_row1344912384548"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1207mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1207mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1207mcpsimp"></a>background</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1209mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1209mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1209mcpsimp"></a>&lt;linear-gradient&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1211mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1211mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1211mcpsimp"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p15730197132811"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p15730197132811"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p15730197132811"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1213mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1213mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1213mcpsimp"></a>仅支持设置<a href="渐变样式.md#ZH-CN_TOPIC_0000001115974726">渐变样式</a>，与background-color、background-image不兼容。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001062321291_row15449838185416"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1217mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1217mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1217mcpsimp"></a>background-color</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1219mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1219mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1219mcpsimp"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1221mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1221mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1221mcpsimp"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p17730577282"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p17730577282"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p17730577282"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1223mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1223mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1223mcpsimp"></a>设置背景颜色。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001062321291_row54491338115412"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1226mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1226mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1226mcpsimp"></a>background-image</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1228mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1228mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1228mcpsimp"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1230mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1230mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1230mcpsimp"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p7730976285"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p7730976285"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p7730976285"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1232mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1232mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1232mcpsimp"></a>设置背景图片。与background-color、background不兼容；支持本地图片资源地址。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001062321291_row6449238185416"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p15157115065817"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p15157115065817"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p15157115065817"></a>background-size</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_ul1065173641310"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_ul1065173641310"></a><ul id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_ul1065173641310"><li>string</li><li>&lt;length&gt; &lt;length&gt;</li><li>&lt;percentage&gt; &lt;percentage&gt;</li></ul>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p8157195019585"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p8157195019585"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p8157195019585"></a>auto</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p137309714282"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p137309714282"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p137309714282"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p91971112114318"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p91971112114318"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p91971112114318"></a>设置背景图片的大小。</p>
<a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_ul41331853154111"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_ul41331853154111"></a><ul id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_ul41331853154111"><li>string可选值：<a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_ul13611494111"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_ul13611494111"></a><ul id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_ul13611494111"><li>contain：把图像扩展至最大尺寸，以使其高度和宽度完全适用内容区域。</li><li>cover：把背景图像扩展至足够大，以使背景图像完全覆盖背景区域；背景图像的某些部分也许无法显示在背景定位区域中。</li><li>auto：保持原图的比例不变。</li></ul>
</li><li>length值参数方式：<p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p1840244924418"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p1840244924418"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p1840244924418"></a>设置背景图像的高度和宽度。第一个值设置宽度，第二个值设置高度。如果只设置一个值，则第二个值会被设置为 "auto"。</p>
</li><li>百分比参数方式：<p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p17936154410457"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p17936154410457"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p17936154410457"></a>以父元素的百分比来设置背景图像的宽度和高度。第一个值设置宽度，第二个值设置高度。如果只设置一个值，则第二个值会被设置为 "auto"。</p>
</li></ul>
</td>
</tr>
<tr id="zh-cn_topic_0000001062321291_row94491238155415"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1235mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1235mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1235mcpsimp"></a>background-repeat</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1237mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1237mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1237mcpsimp"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1239mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1239mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1239mcpsimp"></a>repeat</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p1673015702810"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p1673015702810"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p1673015702810"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1241mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1241mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1241mcpsimp"></a>针对重复背景图像样式进行设置，背景图像默认在水平和垂直方向上重复。</p>
<a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_ul8236153103612"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_ul8236153103612"></a><ul id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_ul8236153103612"><li>repeat：在水平轴和竖直轴上同时重复绘制图片。</li><li>repeat-x：只在水平轴上重复绘制图片。</li><li>repeat-y：只在竖直轴上重复绘制图片。</li><li>no-repeat：不会重复绘制图片。</li></ul>
</td>
</tr>
<tr id="zh-cn_topic_0000001062321291_row94491738105419"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1244mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1244mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1244mcpsimp"></a>background-position</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_ul8874155216502"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_ul8874155216502"></a><ul id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_ul8874155216502"><li>string string</li><li>&lt;length&gt; &lt;length&gt;</li><li>&lt;percentage&gt; &lt;percentage&gt;</li></ul>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1248mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1248mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1248mcpsimp"></a>0px 0px</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p173010720280"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p173010720280"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p173010720280"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_ul1590812103363"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_ul1590812103363"></a><ul id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_ul1590812103363"><li>关键词方式：如果仅规定了一个关键词，那么第二个值为"center"。两个值分别定义水平方向位置和竖直方向位置。<a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_ul1453531734716"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_ul1453531734716"></a><ul id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_ul1453531734716"><li>left：水平方向上最左侧。</li><li>right：水平方向上最右侧。</li><li>top：竖直方向上最顶部。</li><li>bottom：竖直方向上最底部。</li><li>center：水平方向或竖直方向上中间位置。</li></ul>
</li></ul>
<a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_ul10908121023615"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_ul10908121023615"></a><ul id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_ul10908121023615"><li>length值参数方式：第一个值是水平位置，第二个值是垂直位置。 左上角是 0 0。单位是像素 (0px 0px)  。如果仅规定了一个值，另外一个值将是50%。</li><li>百分比参数方式：第一个值是水平位置，第二个值是垂直位置。左上角是 0% 0%。右下角是 100% 100%。如果仅规定了一个值，另外一个值为50%。</li><li>可以混合使用&lt;percentage&gt;和&lt;length&gt;</li></ul>
</td>
</tr>
<tr id="zh-cn_topic_0000001062321291_row20450143885416"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p134581712103910"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p134581712103910"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p134581712103910"></a>opacity</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1267mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1267mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1267mcpsimp"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1269mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1269mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_zh-cn_topic_0000000000611468_p1269mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p1873011722814"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p1873011722814"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p1873011722814"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p122515161139"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p122515161139"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001050791158_p122515161139"></a>元素的透明度，取值范围为0到1，1表示为不透明，0表示为完全透明。</p>
</td>
</tr>
</tbody>
</table>

## 事件<a name="zh-cn_topic_0000001062321291_section1614413538447"></a>

<a name="zh-cn_topic_0000001062321291_table836435619510"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001062321291_row153658563517"><th class="cellrowborder" valign="top" width="24.852485248524854%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001051151132_zh-cn_topic_0000000000611460_p619mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001051151132_zh-cn_topic_0000000000611460_p619mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001051151132_zh-cn_topic_0000000000611460_p619mcpsimp"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="29.552955295529554%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001051151132_zh-cn_topic_0000000000611460_p621mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001051151132_zh-cn_topic_0000000000611460_p621mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001051151132_zh-cn_topic_0000000000611460_p621mcpsimp"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="45.5945594559456%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001062321291_zh-cn_topic_0000001051151132_zh-cn_topic_0000000000611460_p623mcpsimp"><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001051151132_zh-cn_topic_0000000000611460_p623mcpsimp"></a><a name="zh-cn_topic_0000001062321291_zh-cn_topic_0000001051151132_zh-cn_topic_0000000000611460_p623mcpsimp"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001062321291_row0576209174715"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001062321291_p1652031354715"><a name="zh-cn_topic_0000001062321291_p1652031354715"></a><a name="zh-cn_topic_0000001062321291_p1652031354715"></a>sizechange</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001062321291_p2520913204711"><a name="zh-cn_topic_0000001062321291_p2520913204711"></a><a name="zh-cn_topic_0000001062321291_p2520913204711"></a>{ size: { height: heightLength, width: widthLength }, mode: modeStr }</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001062321291_p8520101364714"><a name="zh-cn_topic_0000001062321291_p8520101364714"></a><a name="zh-cn_topic_0000001062321291_p8520101364714"></a>当可滑动面板发生状态变化时触发，mode参数可选值为：</p>
<a name="zh-cn_topic_0000001062321291_ol5520181316476"></a><a name="zh-cn_topic_0000001062321291_ol5520181316476"></a><ol id="zh-cn_topic_0000001062321291_ol5520181316476"><li><p id="zh-cn_topic_0000001062321291_p4520141364713"><a name="zh-cn_topic_0000001062321291_p4520141364713"></a><a name="zh-cn_topic_0000001062321291_p4520141364713"></a>mini：类型为minibar和foldable时，处于最小状态；</p>
</li><li><p id="zh-cn_topic_0000001062321291_p6520191324711"><a name="zh-cn_topic_0000001062321291_p6520191324711"></a><a name="zh-cn_topic_0000001062321291_p6520191324711"></a>half: 类型为foldable时，处于类半屏状态；</p>
</li><li><p id="zh-cn_topic_0000001062321291_p252018137477"><a name="zh-cn_topic_0000001062321291_p252018137477"></a><a name="zh-cn_topic_0000001062321291_p252018137477"></a>full: 类全屏状态。</p>
<div class="note" id="zh-cn_topic_0000001062321291_note1672712533287"><a name="zh-cn_topic_0000001062321291_note1672712533287"></a><a name="zh-cn_topic_0000001062321291_note1672712533287"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001062321291_p1672795314285"><a name="zh-cn_topic_0000001062321291_p1672795314285"></a><a name="zh-cn_topic_0000001062321291_p1672795314285"></a>返回的height值为内容区高度值，当dragbar属性为true时，panel本身的高度值为dragbar高度加上内容区高度。</p>
</div></div>
</li></ol>
</td>
</tr>
</tbody>
</table>

## 方法<a name="zh-cn_topic_0000001062321291_section165301745164719"></a>

<a name="zh-cn_topic_0000001062321291_table20753173210251"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001062321291_row575363214257"><th class="cellrowborder" valign="top" width="18.459999999999997%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001062321291_p157531032112517"><a name="zh-cn_topic_0000001062321291_p157531032112517"></a><a name="zh-cn_topic_0000001062321291_p157531032112517"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="30.769999999999996%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001062321291_p77531632132518"><a name="zh-cn_topic_0000001062321291_p77531632132518"></a><a name="zh-cn_topic_0000001062321291_p77531632132518"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="50.77%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001062321291_p147531232132512"><a name="zh-cn_topic_0000001062321291_p147531232132512"></a><a name="zh-cn_topic_0000001062321291_p147531232132512"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001062321291_row15753113210251"><td class="cellrowborder" valign="top" width="18.459999999999997%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001062321291_p2314135812511"><a name="zh-cn_topic_0000001062321291_p2314135812511"></a><a name="zh-cn_topic_0000001062321291_p2314135812511"></a>show</p>
</td>
<td class="cellrowborder" valign="top" width="30.769999999999996%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001062321291_p7314115819256"><a name="zh-cn_topic_0000001062321291_p7314115819256"></a><a name="zh-cn_topic_0000001062321291_p7314115819256"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001062321291_p0314958162512"><a name="zh-cn_topic_0000001062321291_p0314958162512"></a><a name="zh-cn_topic_0000001062321291_p0314958162512"></a>弹出panel可滑动面板。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001062321291_row393410526251"><td class="cellrowborder" valign="top" width="18.459999999999997%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001062321291_p7314358182512"><a name="zh-cn_topic_0000001062321291_p7314358182512"></a><a name="zh-cn_topic_0000001062321291_p7314358182512"></a>close</p>
</td>
<td class="cellrowborder" valign="top" width="30.769999999999996%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001062321291_p1231455814253"><a name="zh-cn_topic_0000001062321291_p1231455814253"></a><a name="zh-cn_topic_0000001062321291_p1231455814253"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001062321291_p10314105842512"><a name="zh-cn_topic_0000001062321291_p10314105842512"></a><a name="zh-cn_topic_0000001062321291_p10314105842512"></a>关闭panel可滑动面板。</p>
</td>
</tr>
</tbody>
</table>

## 示例<a name="zh-cn_topic_0000001062321291_section36743614499"></a>

```
<!-- xxx.hml -->
<div class="doc-page">
  <div class="btn-div">
    <button type="capsule" value="Click here" onclick="showPanel"></button>
  </div>
  <panel id="simplepanel" type="foldable" mode="half" onsizechange="changeMode" miniheight="200px">
    <div class="panel-div">
      <div class="inner-txt">
        <text class="txt">Simple panel in {{modeFlag}} mode</text>
      </div>
      <div class="inner-btn">
        <button type="capsule" value="Close" onclick="closePanel"></button>
      </div>
    </div>
  </panel>
</div>
```

```
/* xxx.css */
.doc-page {
  flex-direction: column;
  justify-content: center;
  align-items: center;
}
.btn-div {
  width: 100%;
  height: 200px;
  flex-direction: column;
  align-items: center;
  justify-content: center;
}
.txt {
  color: #000000;
  font-weight: bold;
  font-size: 39px;
}
.panel-div {
  width: 100%;
  flex-direction: column;
  align-items: center;
}
.inner-txt {
  width: 100%;
  height: 160px;
  flex-direction: column;
  align-items: center;
  justify-content: center;
}
.inner-btn {
  width: 100%;
  height: 120px;
  justify-content: center;
  align-items: center;
}
```

```
// xxx.js
export default {
  data: {
    modeFlag: "half"
  },
  showPanel(e) {
    this.$element('simplepanel').show()
  },
  closePanel(e) {
    this.$element('simplepanel').close()
  },
  changeMode(e) {
    this.modeFlag = e.mode
  }
}
```

![](figures/panel6.gif)

