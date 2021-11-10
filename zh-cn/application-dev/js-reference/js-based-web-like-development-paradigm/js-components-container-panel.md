# panel<a name="ZH-CN_TOPIC_0000001127284828"></a>

可滑动面板。提供一种轻量的内容展示的窗口，可方便的在不同尺寸中切换。属于弹出式组件。

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从API Version 5 开始支持。

## 子组件<a name="section19368335134016"></a>

支持

## 属性<a name="section1100152194018"></a>

除支持[通用属性](js-components-common-attributes.md)外，还支持如下属性：

<a name="table20633101642315"></a>
<table><thead align="left"><tr id="row663331618238"><th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.1"><p id="a45273e2103004ff3bdd3375013e96a2a"><a name="a45273e2103004ff3bdd3375013e96a2a"></a><a name="a45273e2103004ff3bdd3375013e96a2a"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="23.169999999999998%" id="mcps1.1.6.1.2"><p id="ad5b10d4a60e44bb4a8bbb3b4416d7b27"><a name="ad5b10d4a60e44bb4a8bbb3b4416d7b27"></a><a name="ad5b10d4a60e44bb4a8bbb3b4416d7b27"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="10.59%" id="mcps1.1.6.1.3"><p id="ab2ae3d9f60d6475ab95ba095851a9d07"><a name="ab2ae3d9f60d6475ab95ba095851a9d07"></a><a name="ab2ae3d9f60d6475ab95ba095851a9d07"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.359999999999999%" id="mcps1.1.6.1.4"><p id="p824610360217"><a name="p824610360217"></a><a name="p824610360217"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="35.76%" id="mcps1.1.6.1.5"><p id="af5c3b773ed0a42e589819a6c8d257ca1"><a name="af5c3b773ed0a42e589819a6c8d257ca1"></a><a name="af5c3b773ed0a42e589819a6c8d257ca1"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row741201424216"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p1555482064215"><a name="p1555482064215"></a><a name="p1555482064215"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="23.169999999999998%" headers="mcps1.1.6.1.2 "><p id="p195541120124212"><a name="p195541120124212"></a><a name="p195541120124212"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.59%" headers="mcps1.1.6.1.3 "><p id="p05541220194219"><a name="p05541220194219"></a><a name="p05541220194219"></a>foldable</p>
</td>
<td class="cellrowborder" valign="top" width="7.359999999999999%" headers="mcps1.1.6.1.4 "><p id="p155541220104216"><a name="p155541220104216"></a><a name="p155541220104216"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p175541420104219"><a name="p175541420104219"></a><a name="p175541420104219"></a>设置可滑动面板类型，不可动态变更，可选值有：</p>
<a name="ul15554620204219"></a><a name="ul15554620204219"></a><ul id="ul15554620204219"><li><p id="p555417208423"><a name="p555417208423"></a><a name="p555417208423"></a>minibar：提供minibar和类全屏展示切换效果。</p>
</li><li><p id="p15554920204216"><a name="p15554920204216"></a><a name="p15554920204216"></a>foldable：内容永久展示类，提供大（类全屏）、中（类半屏）、小三种尺寸展示切换效果。</p>
</li><li><p id="p35545206423"><a name="p35545206423"></a><a name="p35545206423"></a>temporary：内容临时展示区，提供大（类全屏）、中（类半屏）两种尺寸展示切换效果。</p>
</li></ul>
</td>
</tr>
<tr id="row1815511615424"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p1755419206420"><a name="p1755419206420"></a><a name="p1755419206420"></a>mode</p>
</td>
<td class="cellrowborder" valign="top" width="23.169999999999998%" headers="mcps1.1.6.1.2 "><p id="p135544206422"><a name="p135544206422"></a><a name="p135544206422"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.59%" headers="mcps1.1.6.1.3 "><p id="p13554192010427"><a name="p13554192010427"></a><a name="p13554192010427"></a>full</p>
</td>
<td class="cellrowborder" valign="top" width="7.359999999999999%" headers="mcps1.1.6.1.4 "><p id="p155418205426"><a name="p155418205426"></a><a name="p155418205426"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p655415206425"><a name="p655415206425"></a><a name="p655415206425"></a>设置初始状态，mode参数可选值为：</p>
<a name="ol6554220154216"></a><a name="ol6554220154216"></a><ol id="ol6554220154216"><li><p id="p12554520154216"><a name="p12554520154216"></a><a name="p12554520154216"></a>mini：类型为minibar和foldable时，为最小状态；类型为temporary，则不生效。</p>
</li><li><p id="p1955422014218"><a name="p1955422014218"></a><a name="p1955422014218"></a>half: 类型为foldable和temporary时，为类半屏状态；类型为minibar，则不生效。</p>
</li><li><p id="p15541020134214"><a name="p15541020134214"></a><a name="p15541020134214"></a>full: 类全屏状态。</p>
</li></ol>
</td>
</tr>
<tr id="row1213173154220"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p855432019421"><a name="p855432019421"></a><a name="p855432019421"></a>dragbar</p>
</td>
<td class="cellrowborder" valign="top" width="23.169999999999998%" headers="mcps1.1.6.1.2 "><p id="p155482015422"><a name="p155482015422"></a><a name="p155482015422"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.59%" headers="mcps1.1.6.1.3 "><p id="p1955552064210"><a name="p1955552064210"></a><a name="p1955552064210"></a>true</p>
</td>
<td class="cellrowborder" valign="top" width="7.359999999999999%" headers="mcps1.1.6.1.4 "><p id="p755542024213"><a name="p755542024213"></a><a name="p755542024213"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p135551520114215"><a name="p135551520114215"></a><a name="p135551520114215"></a>设置是否存在dragbar，true表示存在，false表示不存在。</p>
</td>
</tr>
<tr id="row827211578416"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p55550201428"><a name="p55550201428"></a><a name="p55550201428"></a>fullheight</p>
</td>
<td class="cellrowborder" valign="top" width="23.169999999999998%" headers="mcps1.1.6.1.2 "><p id="p2055572012425"><a name="p2055572012425"></a><a name="p2055572012425"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.59%" headers="mcps1.1.6.1.3 "><p id="p145551220104214"><a name="p145551220104214"></a><a name="p145551220104214"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.359999999999999%" headers="mcps1.1.6.1.4 "><p id="p1555182013429"><a name="p1555182013429"></a><a name="p1555182013429"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p16555102011423"><a name="p16555102011423"></a><a name="p16555102011423"></a>指定full状态下的高度，默认为屏幕尺寸 - 8px。</p>
</td>
</tr>
<tr id="row9344751124116"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p10555162017420"><a name="p10555162017420"></a><a name="p10555162017420"></a>halfheight</p>
</td>
<td class="cellrowborder" valign="top" width="23.169999999999998%" headers="mcps1.1.6.1.2 "><p id="p1055572011422"><a name="p1055572011422"></a><a name="p1055572011422"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.59%" headers="mcps1.1.6.1.3 "><p id="p19555192018423"><a name="p19555192018423"></a><a name="p19555192018423"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.359999999999999%" headers="mcps1.1.6.1.4 "><p id="p5555720134214"><a name="p5555720134214"></a><a name="p5555720134214"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p17555320194211"><a name="p17555320194211"></a><a name="p17555320194211"></a>指定half状态下的高度，默认为屏幕尺寸的一半。</p>
</td>
</tr>
<tr id="row278634674117"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p18556132014422"><a name="p18556132014422"></a><a name="p18556132014422"></a>miniheight</p>
</td>
<td class="cellrowborder" valign="top" width="23.169999999999998%" headers="mcps1.1.6.1.2 "><p id="p5556920194212"><a name="p5556920194212"></a><a name="p5556920194212"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.59%" headers="mcps1.1.6.1.3 "><p id="p15561207425"><a name="p15561207425"></a><a name="p15561207425"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.359999999999999%" headers="mcps1.1.6.1.4 "><p id="p55565208428"><a name="p55565208428"></a><a name="p55565208428"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p115561020164217"><a name="p115561020164217"></a><a name="p115561020164217"></a>指定mini状态下的高度，默认为48px。</p>
</td>
</tr>
</tbody>
</table>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>-   不支持渲染属性，包括for、if和show。
>-   不支持focusable和disabled属性。

## 样式<a name="section1137118175437"></a>

仅支持如下样式：

<a name="table1744514388541"></a>
<table><thead align="left"><tr id="row1244614388545"><th class="cellrowborder" valign="top" width="23.11768823117688%" id="mcps1.1.6.1.1"><p id="a4e80fb5a797c4328af30d59e2c570c71"><a name="a4e80fb5a797c4328af30d59e2c570c71"></a><a name="a4e80fb5a797c4328af30d59e2c570c71"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="20.477952204779523%" id="mcps1.1.6.1.2"><p id="a4238bd3a376645a3ad8498d3916ed6c8"><a name="a4238bd3a376645a3ad8498d3916ed6c8"></a><a name="a4238bd3a376645a3ad8498d3916ed6c8"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="8.869113088691131%" id="mcps1.1.6.1.3"><p id="a5ece9efc3a1d464a868f9557e4784a97"><a name="a5ece9efc3a1d464a868f9557e4784a97"></a><a name="a5ece9efc3a1d464a868f9557e4784a97"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.519248075192481%" id="mcps1.1.6.1.4"><p id="p117421754619"><a name="p117421754619"></a><a name="p117421754619"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="40.01599840015999%" id="mcps1.1.6.1.5"><p id="a2454f35c1eef44b4bb681caaa3ce48fc"><a name="a2454f35c1eef44b4bb681caaa3ce48fc"></a><a name="a2454f35c1eef44b4bb681caaa3ce48fc"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row18446638145412"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="a541d1aa6d8ec43c28527ff9791c4cfc3"><a name="a541d1aa6d8ec43c28527ff9791c4cfc3"></a><a name="a541d1aa6d8ec43c28527ff9791c4cfc3"></a>padding</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="a4d96fa6350a84c17ad53830df77db84e"><a name="a4d96fa6350a84c17ad53830df77db84e"></a><a name="a4d96fa6350a84c17ad53830df77db84e"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="aaa8cc18f5e03468cac00fb13b44abe01"><a name="aaa8cc18f5e03468cac00fb13b44abe01"></a><a name="aaa8cc18f5e03468cac00fb13b44abe01"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="a268bdb972a1147b2b1fc6b930ca565e7"><a name="a268bdb972a1147b2b1fc6b930ca565e7"></a><a name="a268bdb972a1147b2b1fc6b930ca565e7"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><div class="p" id="a9d4f39d126ce4c4cb7652dc07238acf0"><a name="a9d4f39d126ce4c4cb7652dc07238acf0"></a><a name="a9d4f39d126ce4c4cb7652dc07238acf0"></a>该属性可以有1到4个值：<a name="udb68dd5e787d4dc4ba26465e8450efe7"></a><a name="udb68dd5e787d4dc4ba26465e8450efe7"></a><ul id="udb68dd5e787d4dc4ba26465e8450efe7"><li><p id="a95f9b1440265405fa0007c00d337dab3"><a name="a95f9b1440265405fa0007c00d337dab3"></a><a name="a95f9b1440265405fa0007c00d337dab3"></a>指定一个值时，该值指定四个边的内边距。</p>
</li><li><p id="a1c1fdd035aee4b3a8a61fc1a42c967e4"><a name="a1c1fdd035aee4b3a8a61fc1a42c967e4"></a><a name="a1c1fdd035aee4b3a8a61fc1a42c967e4"></a>指定两个值时，第一个值指定上下两边的内边距，第二个指定左右两边的内边距。</p>
</li><li><p id="a643af1b111eb4220a3703a37180c0735"><a name="a643af1b111eb4220a3703a37180c0735"></a><a name="a643af1b111eb4220a3703a37180c0735"></a>指定三个值时，第一个指定上边的内边距，第二个指定左右两边的内边距，第三个指定下边的内边距。</p>
</li><li><p id="ab8cfda39634d4ecf86eb772c1b654f7e"><a name="ab8cfda39634d4ecf86eb772c1b654f7e"></a><a name="ab8cfda39634d4ecf86eb772c1b654f7e"></a>指定四个值时分别为上、右、下、左边的内边距（顺时针顺序）。</p>
</li></ul>
</div>
</td>
</tr>
<tr id="row24464380544"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="a2b2d344bb3214009a6866bd4766407d3"><a name="a2b2d344bb3214009a6866bd4766407d3"></a><a name="a2b2d344bb3214009a6866bd4766407d3"></a>padding-[left|top|right|bottom]</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="aa67316592ce34e00bcbfaa90f10d08cf"><a name="aa67316592ce34e00bcbfaa90f10d08cf"></a><a name="aa67316592ce34e00bcbfaa90f10d08cf"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="a426b27187104497493502b4c45545091"><a name="a426b27187104497493502b4c45545091"></a><a name="a426b27187104497493502b4c45545091"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="a2018ad09e4c94cdf84d402e11c1410d5"><a name="a2018ad09e4c94cdf84d402e11c1410d5"></a><a name="a2018ad09e4c94cdf84d402e11c1410d5"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="ae34337bc334e4e15843bf03563f8572a"><a name="ae34337bc334e4e15843bf03563f8572a"></a><a name="ae34337bc334e4e15843bf03563f8572a"></a>设置左、上、右、下内边距属性。</p>
</td>
</tr>
<tr id="row1144723845412"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="aaff96272d36945239259ab5e76ec433e"><a name="aaff96272d36945239259ab5e76ec433e"></a><a name="aaff96272d36945239259ab5e76ec433e"></a>padding-[start|end]</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="a2dedafe206c84605a2686c505cbd2096"><a name="a2dedafe206c84605a2686c505cbd2096"></a><a name="a2dedafe206c84605a2686c505cbd2096"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="a27db5e428204402aa54deaa2c2630eac"><a name="a27db5e428204402aa54deaa2c2630eac"></a><a name="a27db5e428204402aa54deaa2c2630eac"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="a2952814e86f14ec6a133e606c78683d8"><a name="a2952814e86f14ec6a133e606c78683d8"></a><a name="a2952814e86f14ec6a133e606c78683d8"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="aaf71a7aed79445c18bb63ae5f5a00314"><a name="aaf71a7aed79445c18bb63ae5f5a00314"></a><a name="aaf71a7aed79445c18bb63ae5f5a00314"></a>设置起始和末端内边距属性。</p>
</td>
</tr>
<tr id="row11447438175410"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="ae3cc1b4f8cc94962aeaf8f3b52b4e9f0"><a name="ae3cc1b4f8cc94962aeaf8f3b52b4e9f0"></a><a name="ae3cc1b4f8cc94962aeaf8f3b52b4e9f0"></a>margin</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="a81d0391edfc04d1395d61d8053fa93d6"><a name="a81d0391edfc04d1395d61d8053fa93d6"></a><a name="a81d0391edfc04d1395d61d8053fa93d6"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="a9c42aa4dad8c4f58a9f85a3e2b4d1e15"><a name="a9c42aa4dad8c4f58a9f85a3e2b4d1e15"></a><a name="a9c42aa4dad8c4f58a9f85a3e2b4d1e15"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="a9be9fbee32844dea910afca9a2221bac"><a name="a9be9fbee32844dea910afca9a2221bac"></a><a name="a9be9fbee32844dea910afca9a2221bac"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="afe56536fd53c409db2033b4be7135555"><a name="afe56536fd53c409db2033b4be7135555"></a><a name="afe56536fd53c409db2033b4be7135555"></a>使用简写属性设置所有的外边距属性，该属性可以有1到4个值。</p>
<a name="u1fe7f0fee6294e3aabd5a16f16f62eaa"></a><a name="u1fe7f0fee6294e3aabd5a16f16f62eaa"></a><ul id="u1fe7f0fee6294e3aabd5a16f16f62eaa"><li><p id="a51f7d66473934ec6918040a4da7ed533"><a name="a51f7d66473934ec6918040a4da7ed533"></a><a name="a51f7d66473934ec6918040a4da7ed533"></a>只有一个值时，这个值会被指定给全部的四个边。</p>
</li><li><p id="a446e0dc7bfbc4aa580ede47e4af3901c"><a name="a446e0dc7bfbc4aa580ede47e4af3901c"></a><a name="a446e0dc7bfbc4aa580ede47e4af3901c"></a>两个值时，第一个值被匹配给上和下，第二个值被匹配给左和右。</p>
</li><li><p id="a2ce71640e6964e86acb7f6abd6e6aec8"><a name="a2ce71640e6964e86acb7f6abd6e6aec8"></a><a name="a2ce71640e6964e86acb7f6abd6e6aec8"></a>三个值时，第一个值被匹配给上, 第二个值被匹配给左和右，第三个值被匹配给下。</p>
</li><li><p id="a86622e9fbdeb409cb5afcc0b2c7fe651"><a name="a86622e9fbdeb409cb5afcc0b2c7fe651"></a><a name="a86622e9fbdeb409cb5afcc0b2c7fe651"></a>四个值时，会依次按上、右、下、左的顺序匹配 (即顺时针顺序)。</p>
</li></ul>
</td>
</tr>
<tr id="row144473383544"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="af348632f1a9045e2a46377d98e6a823f"><a name="af348632f1a9045e2a46377d98e6a823f"></a><a name="af348632f1a9045e2a46377d98e6a823f"></a>margin-[left|top|right|bottom]</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="aa2920472d95e4c59b3caa0c64dbf028b"><a name="aa2920472d95e4c59b3caa0c64dbf028b"></a><a name="aa2920472d95e4c59b3caa0c64dbf028b"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="a1086205d47a84dbcb8b537076d758d6f"><a name="a1086205d47a84dbcb8b537076d758d6f"></a><a name="a1086205d47a84dbcb8b537076d758d6f"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="a644285f82f7a4953b96b710055360358"><a name="a644285f82f7a4953b96b710055360358"></a><a name="a644285f82f7a4953b96b710055360358"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="a14777b85d0f7480b9e707f2986db519f"><a name="a14777b85d0f7480b9e707f2986db519f"></a><a name="a14777b85d0f7480b9e707f2986db519f"></a>设置左、上、右、下外边距属性。</p>
</td>
</tr>
<tr id="row944743811541"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="a2f323eb272624b5191876de68ebfd133"><a name="a2f323eb272624b5191876de68ebfd133"></a><a name="a2f323eb272624b5191876de68ebfd133"></a>margin-[start|end]</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001050791158_p157617124374"><a name="zh-cn_topic_0000001050791158_p157617124374"></a><a name="zh-cn_topic_0000001050791158_p157617124374"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="a3874f54c277642e198919edbafa4216b"><a name="a3874f54c277642e198919edbafa4216b"></a><a name="a3874f54c277642e198919edbafa4216b"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p117511744618"><a name="p117511744618"></a><a name="p117511744618"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="ae427df4a00bf46379ce337974a1d17df"><a name="ae427df4a00bf46379ce337974a1d17df"></a><a name="ae427df4a00bf46379ce337974a1d17df"></a>设置起始和末端外边距属性。</p>
</td>
</tr>
<tr id="row16447238155411"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="a5d03dcff88b94f7b894d65fdf08d1434"><a name="a5d03dcff88b94f7b894d65fdf08d1434"></a><a name="a5d03dcff88b94f7b894d65fdf08d1434"></a>border</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="a5ebca7bf3c34482eae9b3148bb3394de"><a name="a5ebca7bf3c34482eae9b3148bb3394de"></a><a name="a5ebca7bf3c34482eae9b3148bb3394de"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="a4bff92bcfc064eaf8ae31845ab40f95d"><a name="a4bff92bcfc064eaf8ae31845ab40f95d"></a><a name="a4bff92bcfc064eaf8ae31845ab40f95d"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p11175131715467"><a name="p11175131715467"></a><a name="p11175131715467"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="a18290265c858402dad42d13f5df9556f"><a name="a18290265c858402dad42d13f5df9556f"></a><a name="a18290265c858402dad42d13f5df9556f"></a>使用简写属性设置所有的边框属性，包含边框的宽度，样式，颜色属性，顺序设置为border-width、border-style、border-color，不设置时，各属性值为默认值。</p>
</td>
</tr>
<tr id="row4447138115414"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="a3247ae43aa8443f184f52e45ccd0ca07"><a name="a3247ae43aa8443f184f52e45ccd0ca07"></a><a name="a3247ae43aa8443f184f52e45ccd0ca07"></a>border-style</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="a3da2ed807521431e987b22e624574dc0"><a name="a3da2ed807521431e987b22e624574dc0"></a><a name="a3da2ed807521431e987b22e624574dc0"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="a0187620d3c154706944fc4c01734d48f"><a name="a0187620d3c154706944fc4c01734d48f"></a><a name="a0187620d3c154706944fc4c01734d48f"></a>solid</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p617531717464"><a name="p617531717464"></a><a name="p617531717464"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="a29372dc23f5f4307929d789f9b76472e"><a name="a29372dc23f5f4307929d789f9b76472e"></a><a name="a29372dc23f5f4307929d789f9b76472e"></a>使用简写属性设置所有边框的样式，可选值为：</p>
<a name="u5617b1dfdf2048739b8699b11a69d8db"></a><a name="u5617b1dfdf2048739b8699b11a69d8db"></a><ul id="u5617b1dfdf2048739b8699b11a69d8db"><li>dotted：显示为一系列圆点，圆点半径为border-width的一半。</li><li>dashed：显示为一系列短的方形虚线。</li></ul>
<a name="u9d6301312eda4022a25e3774fc603823"></a><a name="u9d6301312eda4022a25e3774fc603823"></a><ul id="u9d6301312eda4022a25e3774fc603823"><li>solid：显示为一条实线。</li></ul>
</td>
</tr>
<tr id="row1656512239262"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="a3264ee35efcd40aeb8ed5931bf62f9e3"><a name="a3264ee35efcd40aeb8ed5931bf62f9e3"></a><a name="a3264ee35efcd40aeb8ed5931bf62f9e3"></a>border-[left|top|right|bottom]-style</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="af7370e9f2bd3451bba0b2b0a865b8f43"><a name="af7370e9f2bd3451bba0b2b0a865b8f43"></a><a name="af7370e9f2bd3451bba0b2b0a865b8f43"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="a682f8be227ba4adfa13eac52c1c513b9"><a name="a682f8be227ba4adfa13eac52c1c513b9"></a><a name="a682f8be227ba4adfa13eac52c1c513b9"></a>solid</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="a2edc177990bb4674bea5fc0c2cadf1df"><a name="a2edc177990bb4674bea5fc0c2cadf1df"></a><a name="a2edc177990bb4674bea5fc0c2cadf1df"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="abfe3dfb0662b4a6c850a8d5d285dff6d"><a name="abfe3dfb0662b4a6c850a8d5d285dff6d"></a><a name="abfe3dfb0662b4a6c850a8d5d285dff6d"></a>分别设置左、上、右、下四个边框的样式，可选值为dotted、dashed、solid。</p>
</td>
</tr>
<tr id="row19448113811542"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="aca24a970df9c42d3bdd871a44ad17f2f"><a name="aca24a970df9c42d3bdd871a44ad17f2f"></a><a name="aca24a970df9c42d3bdd871a44ad17f2f"></a>border-[left|top|right|bottom]</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="af20792fd5492451096250fc7db910669"><a name="af20792fd5492451096250fc7db910669"></a><a name="af20792fd5492451096250fc7db910669"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="aa13a80ae5fad42289bae4fb76dc9efeb"><a name="aa13a80ae5fad42289bae4fb76dc9efeb"></a><a name="aa13a80ae5fad42289bae4fb76dc9efeb"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="a45d917a58f9e45f79c931a9ede2f7521"><a name="a45d917a58f9e45f79c931a9ede2f7521"></a><a name="a45d917a58f9e45f79c931a9ede2f7521"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="a5ec1cb3c8733406b91ad459e012f91f4"><a name="a5ec1cb3c8733406b91ad459e012f91f4"></a><a name="a5ec1cb3c8733406b91ad459e012f91f4"></a>使用简写属性设置对应位置的边框属性，包含边框的宽度，样式，颜色属性，顺序设置为border-width、border-style、border-color，不设置的值为默认值。</p>
</td>
</tr>
<tr id="row124481638165417"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="a5e2a85c8033f42d7b69cf67e5468e805"><a name="a5e2a85c8033f42d7b69cf67e5468e805"></a><a name="a5e2a85c8033f42d7b69cf67e5468e805"></a>border-width</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="a68368a57007c44faa8d926acac48f0df"><a name="a68368a57007c44faa8d926acac48f0df"></a><a name="a68368a57007c44faa8d926acac48f0df"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="a21a68501e60245b9beba967ead6cb1f9"><a name="a21a68501e60245b9beba967ead6cb1f9"></a><a name="a21a68501e60245b9beba967ead6cb1f9"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p16175131724618"><a name="p16175131724618"></a><a name="p16175131724618"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="aad1af0ece034401a8c56fb287c16320c"><a name="aad1af0ece034401a8c56fb287c16320c"></a><a name="aad1af0ece034401a8c56fb287c16320c"></a>使用简写属性设置元素的所有边框宽度<span id="p92ad4e18ef0242ffab6502da9096d725"><a name="p92ad4e18ef0242ffab6502da9096d725"></a><a name="p92ad4e18ef0242ffab6502da9096d725"></a>，或者单独为各边边框设置宽度</span>。</p>
</td>
</tr>
<tr id="row54481038165410"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="af71ca4e515d0470ea0867f157c125ffb"><a name="af71ca4e515d0470ea0867f157c125ffb"></a><a name="af71ca4e515d0470ea0867f157c125ffb"></a>border-[left|top|right|bottom]-width</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="a5d713a4524c94d88bb768770c4b9871b"><a name="a5d713a4524c94d88bb768770c4b9871b"></a><a name="a5d713a4524c94d88bb768770c4b9871b"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="a598e0a5a87cc4e1aad99441d0899c064"><a name="a598e0a5a87cc4e1aad99441d0899c064"></a><a name="a598e0a5a87cc4e1aad99441d0899c064"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p11175151717466"><a name="p11175151717466"></a><a name="p11175151717466"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="a0e87cf1edd0f474cb33591ce68b19296"><a name="a0e87cf1edd0f474cb33591ce68b19296"></a><a name="a0e87cf1edd0f474cb33591ce68b19296"></a>分别设置左、上、右、下四个边框的宽度。</p>
</td>
</tr>
<tr id="row1744817385547"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="a971adbece55a4864ad6a089be7eb12d2"><a name="a971adbece55a4864ad6a089be7eb12d2"></a><a name="a971adbece55a4864ad6a089be7eb12d2"></a>border-color</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="a2676a7ea563844569103471ed3d2bcb6"><a name="a2676a7ea563844569103471ed3d2bcb6"></a><a name="a2676a7ea563844569103471ed3d2bcb6"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="a6a41565e7f71412b91e94f6ba95b8a84"><a name="a6a41565e7f71412b91e94f6ba95b8a84"></a><a name="a6a41565e7f71412b91e94f6ba95b8a84"></a>black</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p1017518177465"><a name="p1017518177465"></a><a name="p1017518177465"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="a5c2063b884d84196b3a328d8029c5bbd"><a name="a5c2063b884d84196b3a328d8029c5bbd"></a><a name="a5c2063b884d84196b3a328d8029c5bbd"></a>使用简写属性设置元素的所有边框颜色<span id="p3fcdcb1daadb4ae99170771e07b29ad9"><a name="p3fcdcb1daadb4ae99170771e07b29ad9"></a><a name="p3fcdcb1daadb4ae99170771e07b29ad9"></a>，或者单独为各边边框设置颜色</span>。</p>
</td>
</tr>
<tr id="row844813835410"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="a7385c35d96a84cb9945ba0afe8f39f27"><a name="a7385c35d96a84cb9945ba0afe8f39f27"></a><a name="a7385c35d96a84cb9945ba0afe8f39f27"></a>border-[left|top|right|bottom]-color</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="adc421d4d9fe242968ccae293e5a1d8ca"><a name="adc421d4d9fe242968ccae293e5a1d8ca"></a><a name="adc421d4d9fe242968ccae293e5a1d8ca"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="a997049720b89455581e5ae2ea47c5f76"><a name="a997049720b89455581e5ae2ea47c5f76"></a><a name="a997049720b89455581e5ae2ea47c5f76"></a>black</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p11175417184611"><a name="p11175417184611"></a><a name="p11175417184611"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="a3a75202614f54b8d86865e6bdd23220e"><a name="a3a75202614f54b8d86865e6bdd23220e"></a><a name="a3a75202614f54b8d86865e6bdd23220e"></a>分别设置左、上、右、下四个边框的颜色。</p>
</td>
</tr>
<tr id="row944813389540"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="aeb41e1dcf38048a7a870b7fbc262d9b3"><a name="aeb41e1dcf38048a7a870b7fbc262d9b3"></a><a name="aeb41e1dcf38048a7a870b7fbc262d9b3"></a>border-radius</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="a1b2aa369911d430892c9c2ccc8c92eee"><a name="a1b2aa369911d430892c9c2ccc8c92eee"></a><a name="a1b2aa369911d430892c9c2ccc8c92eee"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="afebc1d7def134a30b454052ffd82fcd5"><a name="afebc1d7def134a30b454052ffd82fcd5"></a><a name="afebc1d7def134a30b454052ffd82fcd5"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="a7477a88e90164a46ba6b4dd7b6b39909"><a name="a7477a88e90164a46ba6b4dd7b6b39909"></a><a name="a7477a88e90164a46ba6b4dd7b6b39909"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="a3df8b3f3ec00490a9687f38cb6369c75"><a name="a3df8b3f3ec00490a9687f38cb6369c75"></a><a name="a3df8b3f3ec00490a9687f38cb6369c75"></a>border-radius属性是设置元素的外边框圆角半径。<span id="pd31b8005f869412fb273faeff4c26552"><a name="pd31b8005f869412fb273faeff4c26552"></a><a name="pd31b8005f869412fb273faeff4c26552"></a>设置border-radius时不能单独设置某一个方向的border-[left|top|right|bottom]-width，border-[left|top|right|bottom]-color ，如果要设置color和width，需要将四个方向一起设置（border-width、border-color）。</span></p>
</td>
</tr>
<tr id="row104494382546"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="a7f4cc47cb21f4241bc50c09595abe42b"><a name="a7f4cc47cb21f4241bc50c09595abe42b"></a><a name="a7f4cc47cb21f4241bc50c09595abe42b"></a>border-[top|bottom]-[left|right]-radius</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="af4577f8f400e44dd92306d77f0b600c7"><a name="af4577f8f400e44dd92306d77f0b600c7"></a><a name="af4577f8f400e44dd92306d77f0b600c7"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="adba608505d644afcb117ae14679054cf"><a name="adba608505d644afcb117ae14679054cf"></a><a name="adba608505d644afcb117ae14679054cf"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="af792dccde58c4e699a2a0b924d6111de"><a name="af792dccde58c4e699a2a0b924d6111de"></a><a name="af792dccde58c4e699a2a0b924d6111de"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="a41f1597c4e454492aaea4818c234d429"><a name="a41f1597c4e454492aaea4818c234d429"></a><a name="a41f1597c4e454492aaea4818c234d429"></a>分别设置左上，右上，右下和左下四个角的圆角半径。</p>
</td>
</tr>
<tr id="row1344912384548"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="a473248d0f1ad4a6b87934aab462b09ce"><a name="a473248d0f1ad4a6b87934aab462b09ce"></a><a name="a473248d0f1ad4a6b87934aab462b09ce"></a>background</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="a7c54e775a6bf4bbea277ff8927cc4c13"><a name="a7c54e775a6bf4bbea277ff8927cc4c13"></a><a name="a7c54e775a6bf4bbea277ff8927cc4c13"></a>&lt;linear-gradient&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="a5bbca83860ff4086bba1bf5b8698e28c"><a name="a5bbca83860ff4086bba1bf5b8698e28c"></a><a name="a5bbca83860ff4086bba1bf5b8698e28c"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="a047e39fe359445759a1ce07ca6d46a38"><a name="a047e39fe359445759a1ce07ca6d46a38"></a><a name="a047e39fe359445759a1ce07ca6d46a38"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="a2681658e98234c0bb3dfb1a8fc1ae346"><a name="a2681658e98234c0bb3dfb1a8fc1ae346"></a><a name="a2681658e98234c0bb3dfb1a8fc1ae346"></a>仅支持设置<a href="js-components-common-gradient.md">渐变样式</a>，与background-color、background-image不兼容。</p>
</td>
</tr>
<tr id="row15449838185416"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="af5c7b4fc3d8949b5aff81c5b49783259"><a name="af5c7b4fc3d8949b5aff81c5b49783259"></a><a name="af5c7b4fc3d8949b5aff81c5b49783259"></a>background-color</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="a3f45d99020c04479943ad07f262a591c"><a name="a3f45d99020c04479943ad07f262a591c"></a><a name="a3f45d99020c04479943ad07f262a591c"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="add693215147d46e59c859940cc4520e8"><a name="add693215147d46e59c859940cc4520e8"></a><a name="add693215147d46e59c859940cc4520e8"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="a5bd974fe26aa45409ff08d6d652b03e6"><a name="a5bd974fe26aa45409ff08d6d652b03e6"></a><a name="a5bd974fe26aa45409ff08d6d652b03e6"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="acd48c077d9964749ae766636b8ada95c"><a name="acd48c077d9964749ae766636b8ada95c"></a><a name="acd48c077d9964749ae766636b8ada95c"></a>设置背景颜色。</p>
</td>
</tr>
<tr id="row54491338115412"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="a9ebf9bd289374413a2834bab0e3b46d4"><a name="a9ebf9bd289374413a2834bab0e3b46d4"></a><a name="a9ebf9bd289374413a2834bab0e3b46d4"></a>background-image</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="a46c151a9e45b4ffcb4c45dfcb93214bd"><a name="a46c151a9e45b4ffcb4c45dfcb93214bd"></a><a name="a46c151a9e45b4ffcb4c45dfcb93214bd"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="a8be7284eb5884350ba591183a67d4060"><a name="a8be7284eb5884350ba591183a67d4060"></a><a name="a8be7284eb5884350ba591183a67d4060"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="a9ca4df413139442e8a520bc7c04dae02"><a name="a9ca4df413139442e8a520bc7c04dae02"></a><a name="a9ca4df413139442e8a520bc7c04dae02"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="aa236de4e56e349ff8c753d294e98abab"><a name="aa236de4e56e349ff8c753d294e98abab"></a><a name="aa236de4e56e349ff8c753d294e98abab"></a>设置背景图片。与background-color、background不兼容；支持本地图片资源地址。</p>
</td>
</tr>
<tr id="row6449238185416"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="a5def9eea1a2b42e9b040f0f898a2fcdf"><a name="a5def9eea1a2b42e9b040f0f898a2fcdf"></a><a name="a5def9eea1a2b42e9b040f0f898a2fcdf"></a>background-size</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><a name="uc9d67b59ab8c4f5d8f766deb0f8f657b"></a><a name="uc9d67b59ab8c4f5d8f766deb0f8f657b"></a><ul id="uc9d67b59ab8c4f5d8f766deb0f8f657b"><li>string</li><li>&lt;length&gt; &lt;length&gt;</li><li>&lt;percentage&gt; &lt;percentage&gt;</li></ul>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="a2d537661fce74b13acbcc7a95ea56f08"><a name="a2d537661fce74b13acbcc7a95ea56f08"></a><a name="a2d537661fce74b13acbcc7a95ea56f08"></a>auto</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="aa5ecaa85d6924436bb54a637b9d46c8c"><a name="aa5ecaa85d6924436bb54a637b9d46c8c"></a><a name="aa5ecaa85d6924436bb54a637b9d46c8c"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="a0709b83d5c8e4b75b1f0bb42d913ac02"><a name="a0709b83d5c8e4b75b1f0bb42d913ac02"></a><a name="a0709b83d5c8e4b75b1f0bb42d913ac02"></a>设置背景图片的大小。</p>
<a name="ub2423a2f8d96432f8c58c629288432c5"></a><a name="ub2423a2f8d96432f8c58c629288432c5"></a><ul id="ub2423a2f8d96432f8c58c629288432c5"><li>string可选值：<a name="uee8f5c89381a4ce682a5d557f8e558ee"></a><a name="uee8f5c89381a4ce682a5d557f8e558ee"></a><ul id="uee8f5c89381a4ce682a5d557f8e558ee"><li>contain：把图像扩展至最大尺寸，以使其高度和宽度完全适用内容区域。</li><li>cover：把背景图像扩展至足够大，以使背景图像完全覆盖背景区域；背景图像的某些部分也许无法显示在背景定位区域中。</li><li>auto：保持原图的比例不变。</li></ul>
</li><li>length值参数方式：<p id="a5b969a49f8074aae96a12e4232e47c5d"><a name="a5b969a49f8074aae96a12e4232e47c5d"></a><a name="a5b969a49f8074aae96a12e4232e47c5d"></a>设置背景图像的高度和宽度。第一个值设置宽度，第二个值设置高度。如果只设置一个值，则第二个值会被设置为 "auto"。</p>
</li><li>百分比参数方式：<p id="a19ef0a7986ce47f2b7fe614975e23cd9"><a name="a19ef0a7986ce47f2b7fe614975e23cd9"></a><a name="a19ef0a7986ce47f2b7fe614975e23cd9"></a>以父元素的百分比来设置背景图像的宽度和高度。第一个值设置宽度，第二个值设置高度。如果只设置一个值，则第二个值会被设置为 "auto"。</p>
</li></ul>
</td>
</tr>
<tr id="row94491238155415"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="a8e820e26428c4e008a691a8fc8c23294"><a name="a8e820e26428c4e008a691a8fc8c23294"></a><a name="a8e820e26428c4e008a691a8fc8c23294"></a>background-repeat</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="ab9ca7eb1f0fc48a9a3fc08b88fe11338"><a name="ab9ca7eb1f0fc48a9a3fc08b88fe11338"></a><a name="ab9ca7eb1f0fc48a9a3fc08b88fe11338"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="abbb032e6786d43568f7eea7b29611821"><a name="abbb032e6786d43568f7eea7b29611821"></a><a name="abbb032e6786d43568f7eea7b29611821"></a>repeat</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="a53d72f211cdc44b181973e27c6f03845"><a name="a53d72f211cdc44b181973e27c6f03845"></a><a name="a53d72f211cdc44b181973e27c6f03845"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="a64efc26d6e2c48a3a4032c71b8511085"><a name="a64efc26d6e2c48a3a4032c71b8511085"></a><a name="a64efc26d6e2c48a3a4032c71b8511085"></a>针对重复背景图像样式进行设置，背景图像默认在水平和垂直方向上重复。</p>
<a name="uee59e640d2304d56a0a5b396795a8cc5"></a><a name="uee59e640d2304d56a0a5b396795a8cc5"></a><ul id="uee59e640d2304d56a0a5b396795a8cc5"><li>repeat：在水平轴和竖直轴上同时重复绘制图片。</li><li>repeat-x：只在水平轴上重复绘制图片。</li><li>repeat-y：只在竖直轴上重复绘制图片。</li><li>no-repeat：不会重复绘制图片。</li></ul>
</td>
</tr>
<tr id="row94491738105419"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="a60e011e34e6c4b04a1c86ac873087eed"><a name="a60e011e34e6c4b04a1c86ac873087eed"></a><a name="a60e011e34e6c4b04a1c86ac873087eed"></a>background-position</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><a name="u2fe0f6beda39428780ca525d6dca1b30"></a><a name="u2fe0f6beda39428780ca525d6dca1b30"></a><ul id="u2fe0f6beda39428780ca525d6dca1b30"><li>string string</li><li>&lt;length&gt; &lt;length&gt;</li><li>&lt;percentage&gt; &lt;percentage&gt;</li></ul>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="ad96af7b5874e476db4b4cf968156a633"><a name="ad96af7b5874e476db4b4cf968156a633"></a><a name="ad96af7b5874e476db4b4cf968156a633"></a>0px 0px</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="a735a713fbf2c4d2c9be71a5eb26e5371"><a name="a735a713fbf2c4d2c9be71a5eb26e5371"></a><a name="a735a713fbf2c4d2c9be71a5eb26e5371"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><a name="ub1e24d41a33d4560a6637f7a16ee5140"></a><a name="ub1e24d41a33d4560a6637f7a16ee5140"></a><ul id="ub1e24d41a33d4560a6637f7a16ee5140"><li>关键词方式：如果仅规定了一个关键词，那么第二个值为"center"。两个值分别定义水平方向位置和竖直方向位置。<a name="uac6e07c1eb0244d79eeed180658cb6c6"></a><a name="uac6e07c1eb0244d79eeed180658cb6c6"></a><ul id="uac6e07c1eb0244d79eeed180658cb6c6"><li>left：水平方向上最左侧。</li><li>right：水平方向上最右侧。</li><li>top：竖直方向上最顶部。</li><li>bottom：竖直方向上最底部。</li><li>center：水平方向或竖直方向上中间位置。</li></ul>
</li></ul>
<a name="ua495746d9777430c973a5ec607309ac4"></a><a name="ua495746d9777430c973a5ec607309ac4"></a><ul id="ua495746d9777430c973a5ec607309ac4"><li>length值参数方式：第一个值是水平位置，第二个值是垂直位置。 左上角是 0 0。单位是像素 (0px 0px)  。如果仅规定了一个值，另外一个值将是50%。</li><li>百分比参数方式：第一个值是水平位置，第二个值是垂直位置。左上角是 0% 0%。右下角是 100% 100%。如果仅规定了一个值，另外一个值为50%。</li><li>可以混合使用&lt;percentage&gt;和&lt;length&gt;</li></ul>
</td>
</tr>
<tr id="row20450143885416"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="a529a69841d634cdfa9637284412e5cf1"><a name="a529a69841d634cdfa9637284412e5cf1"></a><a name="a529a69841d634cdfa9637284412e5cf1"></a>opacity</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="a0820f7d1c5b34d6eab999bd9dddfad6c"><a name="a0820f7d1c5b34d6eab999bd9dddfad6c"></a><a name="a0820f7d1c5b34d6eab999bd9dddfad6c"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="a35dd1b1eab3a421f9c95d512860d5bda"><a name="a35dd1b1eab3a421f9c95d512860d5bda"></a><a name="a35dd1b1eab3a421f9c95d512860d5bda"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="ad2fe0856816f4eaf9c10e2a1d74419a9"><a name="ad2fe0856816f4eaf9c10e2a1d74419a9"></a><a name="ad2fe0856816f4eaf9c10e2a1d74419a9"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="a2e8d180f3c914356af72e679446f4ab5"><a name="a2e8d180f3c914356af72e679446f4ab5"></a><a name="a2e8d180f3c914356af72e679446f4ab5"></a>元素的透明度，取值范围为0到1，1表示为不透明，0表示为完全透明。</p>
</td>
</tr>
</tbody>
</table>

## 事件<a name="section1614413538447"></a>

仅支持如下事件：

<a name="table836435619510"></a>
<table><thead align="left"><tr id="row153658563517"><th class="cellrowborder" valign="top" width="24.852485248524854%" id="mcps1.1.4.1.1"><p id="a0ff86a4560fa46bfbeb711d109869422"><a name="a0ff86a4560fa46bfbeb711d109869422"></a><a name="a0ff86a4560fa46bfbeb711d109869422"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="29.552955295529554%" id="mcps1.1.4.1.2"><p id="a4c85eb8ca18b4169a25c4a9263fa63ed"><a name="a4c85eb8ca18b4169a25c4a9263fa63ed"></a><a name="a4c85eb8ca18b4169a25c4a9263fa63ed"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="45.5945594559456%" id="mcps1.1.4.1.3"><p id="ab30b2353efa245fbad4d2aaa2ee33def"><a name="ab30b2353efa245fbad4d2aaa2ee33def"></a><a name="ab30b2353efa245fbad4d2aaa2ee33def"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row0576209174715"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="p1652031354715"><a name="p1652031354715"></a><a name="p1652031354715"></a>sizechange</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="p2520913204711"><a name="p2520913204711"></a><a name="p2520913204711"></a>{ size: { height: heightLength, width: widthLength }, mode: modeStr }</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="p8520101364714"><a name="p8520101364714"></a><a name="p8520101364714"></a>当可滑动面板发生状态变化时触发，mode参数可选值为：</p>
<a name="ol5520181316476"></a><a name="ol5520181316476"></a><ol id="ol5520181316476"><li><p id="p4520141364713"><a name="p4520141364713"></a><a name="p4520141364713"></a>mini：类型为minibar和foldable时，处于最小状态；</p>
</li><li><p id="p6520191324711"><a name="p6520191324711"></a><a name="p6520191324711"></a>half: 类型为foldable时，处于类半屏状态；</p>
</li><li><p id="p252018137477"><a name="p252018137477"></a><a name="p252018137477"></a>full: 类全屏状态。</p>
<div class="note" id="note1672712533287"><a name="note1672712533287"></a><a name="note1672712533287"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="p1672795314285"><a name="p1672795314285"></a><a name="p1672795314285"></a>返回的height值为内容区高度值，当dragbar属性为true时，panel本身的高度值为dragbar高度加上内容区高度。</p>
</div></div>
</li></ol>
</td>
</tr>
</tbody>
</table>

## 方法<a name="section165301745164719"></a>

仅支持如下方法：

<a name="table20753173210251"></a>
<table><thead align="left"><tr id="row575363214257"><th class="cellrowborder" valign="top" width="18.459999999999997%" id="mcps1.1.4.1.1"><p id="p157531032112517"><a name="p157531032112517"></a><a name="p157531032112517"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="30.769999999999996%" id="mcps1.1.4.1.2"><p id="p77531632132518"><a name="p77531632132518"></a><a name="p77531632132518"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="50.77%" id="mcps1.1.4.1.3"><p id="p147531232132512"><a name="p147531232132512"></a><a name="p147531232132512"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row15753113210251"><td class="cellrowborder" valign="top" width="18.459999999999997%" headers="mcps1.1.4.1.1 "><p id="p2314135812511"><a name="p2314135812511"></a><a name="p2314135812511"></a>show</p>
</td>
<td class="cellrowborder" valign="top" width="30.769999999999996%" headers="mcps1.1.4.1.2 "><p id="p7314115819256"><a name="p7314115819256"></a><a name="p7314115819256"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.1.4.1.3 "><p id="p0314958162512"><a name="p0314958162512"></a><a name="p0314958162512"></a>弹出panel可滑动面板。</p>
</td>
</tr>
<tr id="row393410526251"><td class="cellrowborder" valign="top" width="18.459999999999997%" headers="mcps1.1.4.1.1 "><p id="p7314358182512"><a name="p7314358182512"></a><a name="p7314358182512"></a>close</p>
</td>
<td class="cellrowborder" valign="top" width="30.769999999999996%" headers="mcps1.1.4.1.2 "><p id="p1231455814253"><a name="p1231455814253"></a><a name="p1231455814253"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.1.4.1.3 "><p id="p10314105842512"><a name="p10314105842512"></a><a name="p10314105842512"></a>关闭panel可滑动面板。</p>
</td>
</tr>
</tbody>
</table>

## 示例<a name="section36743614499"></a>

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
  showPanel() {
    this.$element('simplepanel').show()
  },
  closePanel() {
    this.$element('simplepanel').close()
  },
  changeMode(e) {
    this.modeFlag = e.mode
  }
}
```

![](figures/panel6.gif)

