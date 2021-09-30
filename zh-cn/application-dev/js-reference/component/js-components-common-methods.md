# 通用方法<a name="ZH-CN_TOPIC_0000001209252157"></a>

-   [this.$element\('id'\).animate\(Object, Object\)](#zh-cn_topic_0000001127284884_section844805134319)
-   [this.$element\('id'\).getBoundingClientRect\(\)6+](#zh-cn_topic_0000001127284884_section8611320155314)
-   [this.$element\('id'\).createIntersectionObserver\(\)6+](#zh-cn_topic_0000001127284884_section137899052719)

当组件通过id属性标识后，可以使用该id获取组件对象并调用相关组件方法。

<a name="zh-cn_topic_0000001127284884_t16791c2761d34150a3a89954b52d1453"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001127284884_r0148773c052c4f38bef9962bc22a16bf"><th class="cellrowborder" valign="top" width="15.310000000000002%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001127284884_ab430207c41eb4593a9fff4377fd60b27"><a name="zh-cn_topic_0000001127284884_ab430207c41eb4593a9fff4377fd60b27"></a><a name="zh-cn_topic_0000001127284884_ab430207c41eb4593a9fff4377fd60b27"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="28.610000000000003%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001127284884_adadb9fe3ee9d45ab8e55fad0a56ec311"><a name="zh-cn_topic_0000001127284884_adadb9fe3ee9d45ab8e55fad0a56ec311"></a><a name="zh-cn_topic_0000001127284884_adadb9fe3ee9d45ab8e55fad0a56ec311"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="8.19%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001127284884_p5451162571712"><a name="zh-cn_topic_0000001127284884_p5451162571712"></a><a name="zh-cn_topic_0000001127284884_p5451162571712"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="8.290000000000001%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001127284884_p17256161265111"><a name="zh-cn_topic_0000001127284884_p17256161265111"></a><a name="zh-cn_topic_0000001127284884_p17256161265111"></a>返回值</p>
</th>
<th class="cellrowborder" valign="top" width="39.6%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001127284884_a7a0dfce144d445e19289835b2e4c8697"><a name="zh-cn_topic_0000001127284884_a7a0dfce144d445e19289835b2e4c8697"></a><a name="zh-cn_topic_0000001127284884_a7a0dfce144d445e19289835b2e4c8697"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001127284884_row48146221457"><td class="cellrowborder" valign="top" width="15.310000000000002%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127284884_p168151422164511"><a name="zh-cn_topic_0000001127284884_p168151422164511"></a><a name="zh-cn_topic_0000001127284884_p168151422164511"></a>animate</p>
<p id="zh-cn_topic_0000001127284884_p564915003620"><a name="zh-cn_topic_0000001127284884_p564915003620"></a><a name="zh-cn_topic_0000001127284884_p564915003620"></a></p>
</td>
<td class="cellrowborder" valign="top" width="28.610000000000003%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127284884_p228224092010"><a name="zh-cn_topic_0000001127284884_p228224092010"></a><a name="zh-cn_topic_0000001127284884_p228224092010"></a>keyframes: <a href="#zh-cn_topic_0000001127284884_table1491078445">Keyframes</a>, options: <a href="#zh-cn_topic_0000001127284884_table587915341817">Options</a></p>
</td>
<td class="cellrowborder" valign="top" width="8.19%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127284884_p108159229458"><a name="zh-cn_topic_0000001127284884_p108159229458"></a><a name="zh-cn_topic_0000001127284884_p108159229458"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="8.290000000000001%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127284884_p6256112155112"><a name="zh-cn_topic_0000001127284884_p6256112155112"></a><a name="zh-cn_topic_0000001127284884_p6256112155112"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="39.6%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127284884_p15815102244511"><a name="zh-cn_topic_0000001127284884_p15815102244511"></a><a name="zh-cn_topic_0000001127284884_p15815102244511"></a>在组件上创建和运行动画的快捷方式。输入动画所需的keyframes和options，返回animation对象实例。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127284884_row143796917504"><td class="cellrowborder" valign="top" width="15.310000000000002%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127284884_p10117420125016"><a name="zh-cn_topic_0000001127284884_p10117420125016"></a><a name="zh-cn_topic_0000001127284884_p10117420125016"></a>getBoundingClientRect<sup id="zh-cn_topic_0000001127284884_sup14424201005214"><a name="zh-cn_topic_0000001127284884_sup14424201005214"></a><a name="zh-cn_topic_0000001127284884_sup14424201005214"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="28.610000000000003%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127284884_p13871830115012"><a name="zh-cn_topic_0000001127284884_p13871830115012"></a><a name="zh-cn_topic_0000001127284884_p13871830115012"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.19%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127284884_p163801097506"><a name="zh-cn_topic_0000001127284884_p163801097506"></a><a name="zh-cn_topic_0000001127284884_p163801097506"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.290000000000001%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127284884_p82562126516"><a name="zh-cn_topic_0000001127284884_p82562126516"></a><a name="zh-cn_topic_0000001127284884_p82562126516"></a><a href="#zh-cn_topic_0000001127284884_table115553448519">Rect</a></p>
</td>
<td class="cellrowborder" valign="top" width="39.6%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127284884_p738010925019"><a name="zh-cn_topic_0000001127284884_p738010925019"></a><a name="zh-cn_topic_0000001127284884_p738010925019"></a>获取元素的大小及其相对于窗口的位置。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127284884_row1843119299139"><td class="cellrowborder" valign="top" width="15.310000000000002%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127284884_p64327294132"><a name="zh-cn_topic_0000001127284884_p64327294132"></a><a name="zh-cn_topic_0000001127284884_p64327294132"></a>createIntersectionObserver<sup id="zh-cn_topic_0000001127284884_sup156638422811"><a name="zh-cn_topic_0000001127284884_sup156638422811"></a><a name="zh-cn_topic_0000001127284884_sup156638422811"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="28.610000000000003%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127284884_p18432429171313"><a name="zh-cn_topic_0000001127284884_p18432429171313"></a><a name="zh-cn_topic_0000001127284884_p18432429171313"></a><a href="#zh-cn_topic_0000001127284884_table143341035121917">ObserverParam</a></p>
</td>
<td class="cellrowborder" valign="top" width="8.19%" headers="mcps1.1.6.1.3 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="8.290000000000001%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127284884_p3432152915131"><a name="zh-cn_topic_0000001127284884_p3432152915131"></a><a name="zh-cn_topic_0000001127284884_p3432152915131"></a><a href="#zh-cn_topic_0000001127284884_table4259113611414">Observer</a></p>
</td>
<td class="cellrowborder" valign="top" width="39.6%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127284884_p343212921312"><a name="zh-cn_topic_0000001127284884_p343212921312"></a><a name="zh-cn_topic_0000001127284884_p343212921312"></a>返回Observer对象，用于监听组件在当前页面的变化。</p>
</td>
</tr>
</tbody>
</table>

**表 1**  Rect对象说明<sup>6+</sup>

<a name="zh-cn_topic_0000001127284884_table115553448519"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001127284884_row955534419511"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="zh-cn_topic_0000001127284884_p6555544165116"><a name="zh-cn_topic_0000001127284884_p6555544165116"></a><a name="zh-cn_topic_0000001127284884_p6555544165116"></a>属性</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="zh-cn_topic_0000001127284884_p16555194419519"><a name="zh-cn_topic_0000001127284884_p16555194419519"></a><a name="zh-cn_topic_0000001127284884_p16555194419519"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="zh-cn_topic_0000001127284884_p10555164415516"><a name="zh-cn_topic_0000001127284884_p10555164415516"></a><a name="zh-cn_topic_0000001127284884_p10555164415516"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001127284884_row1355564435118"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001127284884_p1955544465113"><a name="zh-cn_topic_0000001127284884_p1955544465113"></a><a name="zh-cn_topic_0000001127284884_p1955544465113"></a>width</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001127284884_p15555194485119"><a name="zh-cn_topic_0000001127284884_p15555194485119"></a><a name="zh-cn_topic_0000001127284884_p15555194485119"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001127284884_p9555184419514"><a name="zh-cn_topic_0000001127284884_p9555184419514"></a><a name="zh-cn_topic_0000001127284884_p9555184419514"></a>该元素的宽度。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127284884_row205556442517"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001127284884_p655544414513"><a name="zh-cn_topic_0000001127284884_p655544414513"></a><a name="zh-cn_topic_0000001127284884_p655544414513"></a>height</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001127284884_p7555134485117"><a name="zh-cn_topic_0000001127284884_p7555134485117"></a><a name="zh-cn_topic_0000001127284884_p7555134485117"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001127284884_p10555044105118"><a name="zh-cn_topic_0000001127284884_p10555044105118"></a><a name="zh-cn_topic_0000001127284884_p10555044105118"></a>该元素的高度。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127284884_row1255534465119"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001127284884_p95558448517"><a name="zh-cn_topic_0000001127284884_p95558448517"></a><a name="zh-cn_topic_0000001127284884_p95558448517"></a>left</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001127284884_p9555944185117"><a name="zh-cn_topic_0000001127284884_p9555944185117"></a><a name="zh-cn_topic_0000001127284884_p9555944185117"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001127284884_p1555144165118"><a name="zh-cn_topic_0000001127284884_p1555144165118"></a><a name="zh-cn_topic_0000001127284884_p1555144165118"></a>该元素左边界距离窗口的偏移。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127284884_row135552447511"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001127284884_p20555174465112"><a name="zh-cn_topic_0000001127284884_p20555174465112"></a><a name="zh-cn_topic_0000001127284884_p20555174465112"></a>top</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001127284884_p10555544175114"><a name="zh-cn_topic_0000001127284884_p10555544175114"></a><a name="zh-cn_topic_0000001127284884_p10555544175114"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001127284884_p155618445517"><a name="zh-cn_topic_0000001127284884_p155618445517"></a><a name="zh-cn_topic_0000001127284884_p155618445517"></a>该元素上边界距离窗口的偏移。</p>
</td>
</tr>
</tbody>
</table>

**表 2**  ObserverParam对象说明<sup>6+</sup>

<a name="zh-cn_topic_0000001127284884_table143341035121917"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001127284884_row11334163521916"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="zh-cn_topic_0000001127284884_p833411354195"><a name="zh-cn_topic_0000001127284884_p833411354195"></a><a name="zh-cn_topic_0000001127284884_p833411354195"></a>属性</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="zh-cn_topic_0000001127284884_p1233453551912"><a name="zh-cn_topic_0000001127284884_p1233453551912"></a><a name="zh-cn_topic_0000001127284884_p1233453551912"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="zh-cn_topic_0000001127284884_p173341835171912"><a name="zh-cn_topic_0000001127284884_p173341835171912"></a><a name="zh-cn_topic_0000001127284884_p173341835171912"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001127284884_row1633503511196"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001127284884_p933518359198"><a name="zh-cn_topic_0000001127284884_p933518359198"></a><a name="zh-cn_topic_0000001127284884_p933518359198"></a>ratios</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001127284884_p17335103510196"><a name="zh-cn_topic_0000001127284884_p17335103510196"></a><a name="zh-cn_topic_0000001127284884_p17335103510196"></a>Array&lt;number&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001127284884_p20335113514191"><a name="zh-cn_topic_0000001127284884_p20335113514191"></a><a name="zh-cn_topic_0000001127284884_p20335113514191"></a>组件超出或小于范围时触发observer的回调。</p>
</td>
</tr>
</tbody>
</table>

**表 3**  Observer对象支持的方法<sup>6+</sup>

<a name="zh-cn_topic_0000001127284884_table4259113611414"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001127284884_row925913612148"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="zh-cn_topic_0000001127284884_p3259336191410"><a name="zh-cn_topic_0000001127284884_p3259336191410"></a><a name="zh-cn_topic_0000001127284884_p3259336191410"></a>方法</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="zh-cn_topic_0000001127284884_p525920364144"><a name="zh-cn_topic_0000001127284884_p525920364144"></a><a name="zh-cn_topic_0000001127284884_p525920364144"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="zh-cn_topic_0000001127284884_p1225913612148"><a name="zh-cn_topic_0000001127284884_p1225913612148"></a><a name="zh-cn_topic_0000001127284884_p1225913612148"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001127284884_row32591036161415"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001127284884_p1025920369145"><a name="zh-cn_topic_0000001127284884_p1025920369145"></a><a name="zh-cn_topic_0000001127284884_p1025920369145"></a>observe</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001127284884_p92591636131412"><a name="zh-cn_topic_0000001127284884_p92591636131412"></a><a name="zh-cn_topic_0000001127284884_p92591636131412"></a>callback: function</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001127284884_p10259236191419"><a name="zh-cn_topic_0000001127284884_p10259236191419"></a><a name="zh-cn_topic_0000001127284884_p10259236191419"></a>开启observer的订阅方法。超出或小于阈值时触发callback。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127284884_row725903614146"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001127284884_p20259103631417"><a name="zh-cn_topic_0000001127284884_p20259103631417"></a><a name="zh-cn_topic_0000001127284884_p20259103631417"></a>unobserve</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001127284884_p1625953618140"><a name="zh-cn_topic_0000001127284884_p1625953618140"></a><a name="zh-cn_topic_0000001127284884_p1625953618140"></a>取消observer的订阅方法。</p>
</td>
</tr>
</tbody>
</table>

## this.$element\('_id_'\).animate\(Object, Object\)<a name="zh-cn_topic_0000001127284884_section844805134319"></a>

通过animate\(keyframes: Keyframes, options: Options\)方法获得animation对象。该对象支持动画属性，动画方法和动画事件。重复多次调用animate方法时，采用replace策略，最后一次调用时传入的参数生效。

**表 4**  Keyframes

<a name="zh-cn_topic_0000001127284884_table1491078445"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001127284884_row159311381240"><th class="cellrowborder" valign="top" width="23.56%" id="mcps1.2.4.1.1"><p id="zh-cn_topic_0000001127284884_p79311181544"><a name="zh-cn_topic_0000001127284884_p79311181544"></a><a name="zh-cn_topic_0000001127284884_p79311181544"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="23.95%" id="mcps1.2.4.1.2"><p id="zh-cn_topic_0000001127284884_p19311818417"><a name="zh-cn_topic_0000001127284884_p19311818417"></a><a name="zh-cn_topic_0000001127284884_p19311818417"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="52.49%" id="mcps1.2.4.1.3"><p id="zh-cn_topic_0000001127284884_p17931185415"><a name="zh-cn_topic_0000001127284884_p17931185415"></a><a name="zh-cn_topic_0000001127284884_p17931185415"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001127284884_row993198749"><td class="cellrowborder" valign="top" width="23.56%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001127284884_p10931080410"><a name="zh-cn_topic_0000001127284884_p10931080410"></a><a name="zh-cn_topic_0000001127284884_p10931080410"></a>frames</p>
</td>
<td class="cellrowborder" valign="top" width="23.95%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001127284884_p1493113816413"><a name="zh-cn_topic_0000001127284884_p1493113816413"></a><a name="zh-cn_topic_0000001127284884_p1493113816413"></a>Array&lt;Style&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="52.49%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001127284884_p15171240102918"><a name="zh-cn_topic_0000001127284884_p15171240102918"></a><a name="zh-cn_topic_0000001127284884_p15171240102918"></a>用于设置动画样式属性的对象列表。Style类型说明请见<a href="#zh-cn_topic_0000001127284884_table29075541349">表1 Style类型说明</a>。</p>
</td>
</tr>
</tbody>
</table>

**表 5**  Style类型说明

<a name="zh-cn_topic_0000001127284884_table29075541349"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001127284884_row1961954543"><th class="cellrowborder" valign="top" width="22.91%" id="mcps1.2.5.1.1"><p id="zh-cn_topic_0000001127284884_p119614542419"><a name="zh-cn_topic_0000001127284884_p119614542419"></a><a name="zh-cn_topic_0000001127284884_p119614542419"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="10.67%" id="mcps1.2.5.1.2"><p id="zh-cn_topic_0000001127284884_p2961954840"><a name="zh-cn_topic_0000001127284884_p2961954840"></a><a name="zh-cn_topic_0000001127284884_p2961954840"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="24.52%" id="mcps1.2.5.1.3"><p id="zh-cn_topic_0000001127284884_p15961145416415"><a name="zh-cn_topic_0000001127284884_p15961145416415"></a><a name="zh-cn_topic_0000001127284884_p15961145416415"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="41.9%" id="mcps1.2.5.1.4"><p id="zh-cn_topic_0000001127284884_p1196118542410"><a name="zh-cn_topic_0000001127284884_p1196118542410"></a><a name="zh-cn_topic_0000001127284884_p1196118542410"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001127284884_row1796113541041"><td class="cellrowborder" valign="top" width="22.91%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000001127284884_p129615545417"><a name="zh-cn_topic_0000001127284884_p129615545417"></a><a name="zh-cn_topic_0000001127284884_p129615545417"></a>width</p>
</td>
<td class="cellrowborder" valign="top" width="10.67%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000001127284884_p1296111541345"><a name="zh-cn_topic_0000001127284884_p1296111541345"></a><a name="zh-cn_topic_0000001127284884_p1296111541345"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="24.52%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000001127284884_p296117541140"><a name="zh-cn_topic_0000001127284884_p296117541140"></a><a name="zh-cn_topic_0000001127284884_p296117541140"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="41.9%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000001127284884_p1296112541247"><a name="zh-cn_topic_0000001127284884_p1296112541247"></a><a name="zh-cn_topic_0000001127284884_p1296112541247"></a>动画执行过程中设置到组件上的宽度值。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127284884_row149616548418"><td class="cellrowborder" valign="top" width="22.91%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000001127284884_p14961654846"><a name="zh-cn_topic_0000001127284884_p14961654846"></a><a name="zh-cn_topic_0000001127284884_p14961654846"></a>height</p>
</td>
<td class="cellrowborder" valign="top" width="10.67%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000001127284884_p1296113545416"><a name="zh-cn_topic_0000001127284884_p1296113545416"></a><a name="zh-cn_topic_0000001127284884_p1296113545416"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="24.52%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000001127284884_p11462818125515"><a name="zh-cn_topic_0000001127284884_p11462818125515"></a><a name="zh-cn_topic_0000001127284884_p11462818125515"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="41.9%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000001127284884_p1696216541448"><a name="zh-cn_topic_0000001127284884_p1696216541448"></a><a name="zh-cn_topic_0000001127284884_p1696216541448"></a>动画执行过程中设置到组件上的高度值。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127284884_row1962754242"><td class="cellrowborder" valign="top" width="22.91%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000001127284884_p14962145418411"><a name="zh-cn_topic_0000001127284884_p14962145418411"></a><a name="zh-cn_topic_0000001127284884_p14962145418411"></a>backgroundColor</p>
</td>
<td class="cellrowborder" valign="top" width="10.67%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000001127284884_p09628541446"><a name="zh-cn_topic_0000001127284884_p09628541446"></a><a name="zh-cn_topic_0000001127284884_p09628541446"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="24.52%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000001127284884_p39621754042"><a name="zh-cn_topic_0000001127284884_p39621754042"></a><a name="zh-cn_topic_0000001127284884_p39621754042"></a>none</p>
</td>
<td class="cellrowborder" valign="top" width="41.9%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000001127284884_p11962125420412"><a name="zh-cn_topic_0000001127284884_p11962125420412"></a><a name="zh-cn_topic_0000001127284884_p11962125420412"></a>动画执行过程中设置到组件上的背景颜色。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127284884_row99623548410"><td class="cellrowborder" valign="top" width="22.91%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000001127284884_p1896216541345"><a name="zh-cn_topic_0000001127284884_p1896216541345"></a><a name="zh-cn_topic_0000001127284884_p1896216541345"></a>opacity</p>
</td>
<td class="cellrowborder" valign="top" width="10.67%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000001127284884_p12409238152914"><a name="zh-cn_topic_0000001127284884_p12409238152914"></a><a name="zh-cn_topic_0000001127284884_p12409238152914"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="24.52%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000001127284884_p6962354649"><a name="zh-cn_topic_0000001127284884_p6962354649"></a><a name="zh-cn_topic_0000001127284884_p6962354649"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="41.9%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000001127284884_p1696275417410"><a name="zh-cn_topic_0000001127284884_p1696275417410"></a><a name="zh-cn_topic_0000001127284884_p1696275417410"></a>设置到组件上的透明度（介于0到1之间）。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127284884_row6141915145917"><td class="cellrowborder" valign="top" width="22.91%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000001127284884_p14778012599"><a name="zh-cn_topic_0000001127284884_p14778012599"></a><a name="zh-cn_topic_0000001127284884_p14778012599"></a>backgroundPosition</p>
</td>
<td class="cellrowborder" valign="top" width="10.67%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000001127284884_p151419151591"><a name="zh-cn_topic_0000001127284884_p151419151591"></a><a name="zh-cn_topic_0000001127284884_p151419151591"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="24.52%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000001127284884_p11551505916"><a name="zh-cn_topic_0000001127284884_p11551505916"></a><a name="zh-cn_topic_0000001127284884_p11551505916"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="41.9%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000001127284884_p615181514596"><a name="zh-cn_topic_0000001127284884_p615181514596"></a><a name="zh-cn_topic_0000001127284884_p615181514596"></a>格式为"x y"，单位为百分号或者px。</p>
<p id="zh-cn_topic_0000001127284884_p74641623022"><a name="zh-cn_topic_0000001127284884_p74641623022"></a><a name="zh-cn_topic_0000001127284884_p74641623022"></a>第一个值是水平位置，第二个值是垂直位置。</p>
<p id="zh-cn_topic_0000001127284884_p5609351927"><a name="zh-cn_topic_0000001127284884_p5609351927"></a><a name="zh-cn_topic_0000001127284884_p5609351927"></a>如果仅规定了一个值，另一个值为 50%。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127284884_row8962754643"><td class="cellrowborder" valign="top" width="22.91%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000001127284884_p7962145414417"><a name="zh-cn_topic_0000001127284884_p7962145414417"></a><a name="zh-cn_topic_0000001127284884_p7962145414417"></a>transformOrigin</p>
</td>
<td class="cellrowborder" valign="top" width="10.67%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000001127284884_p896213541048"><a name="zh-cn_topic_0000001127284884_p896213541048"></a><a name="zh-cn_topic_0000001127284884_p896213541048"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="24.52%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000001127284884_p169621454340"><a name="zh-cn_topic_0000001127284884_p169621454340"></a><a name="zh-cn_topic_0000001127284884_p169621454340"></a>'center center'</p>
</td>
<td class="cellrowborder" valign="top" width="41.9%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000001127284884_p12962115415412"><a name="zh-cn_topic_0000001127284884_p12962115415412"></a><a name="zh-cn_topic_0000001127284884_p12962115415412"></a>变换对象的中心点。</p>
<p id="zh-cn_topic_0000001127284884_p193331521134020"><a name="zh-cn_topic_0000001127284884_p193331521134020"></a><a name="zh-cn_topic_0000001127284884_p193331521134020"></a>第一个参数表示x轴的值，可以设置为left、center、right、长度值或百分比值。</p>
<p id="zh-cn_topic_0000001127284884_p6457202144018"><a name="zh-cn_topic_0000001127284884_p6457202144018"></a><a name="zh-cn_topic_0000001127284884_p6457202144018"></a>第二个参数表示y轴的值，可以设置为top、center、bottom、长度值或百分比值。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127284884_row496214548419"><td class="cellrowborder" valign="top" width="22.91%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000001127284884_p139621354144"><a name="zh-cn_topic_0000001127284884_p139621354144"></a><a name="zh-cn_topic_0000001127284884_p139621354144"></a>transform</p>
</td>
<td class="cellrowborder" valign="top" width="10.67%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000001127284884_p189624543418"><a name="zh-cn_topic_0000001127284884_p189624543418"></a><a name="zh-cn_topic_0000001127284884_p189624543418"></a><a href="js-components-common-animation.md#zh-cn_topic_0000001173164765_table28802443315">Transform</a></p>
</td>
<td class="cellrowborder" valign="top" width="24.52%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000001127284884_p1896218541242"><a name="zh-cn_topic_0000001127284884_p1896218541242"></a><a name="zh-cn_topic_0000001127284884_p1896218541242"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="41.9%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000001127284884_p19962454547"><a name="zh-cn_topic_0000001127284884_p19962454547"></a><a name="zh-cn_topic_0000001127284884_p19962454547"></a>设置到变换对象上的类型。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127284884_row18717853325"><td class="cellrowborder" valign="top" width="22.91%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000001127284884_p197170513218"><a name="zh-cn_topic_0000001127284884_p197170513218"></a><a name="zh-cn_topic_0000001127284884_p197170513218"></a>offset</p>
</td>
<td class="cellrowborder" valign="top" width="10.67%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000001127284884_p207175553213"><a name="zh-cn_topic_0000001127284884_p207175553213"></a><a name="zh-cn_topic_0000001127284884_p207175553213"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="24.52%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000001127284884_p1171719518322"><a name="zh-cn_topic_0000001127284884_p1171719518322"></a><a name="zh-cn_topic_0000001127284884_p1171719518322"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="41.9%" headers="mcps1.2.5.1.4 "><a name="zh-cn_topic_0000001127284884_ul768313101318"></a><a name="zh-cn_topic_0000001127284884_ul768313101318"></a><ul id="zh-cn_topic_0000001127284884_ul768313101318"><li>offset值（如果提供）必须在0.0到1.0（含）之间，并以升序排列。</li><li>若只有两帧，可以不填offset。</li><li>若超过两帧，offset必填。</li></ul>
</td>
</tr>
</tbody>
</table>

**表 6**  Options

<a name="zh-cn_topic_0000001127284884_table587915341817"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001127284884_row98794371819"><th class="cellrowborder" valign="top" width="18.89%" id="mcps1.2.5.1.1"><p id="zh-cn_topic_0000001127284884_p15879539188"><a name="zh-cn_topic_0000001127284884_p15879539188"></a><a name="zh-cn_topic_0000001127284884_p15879539188"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="27.560000000000002%" id="mcps1.2.5.1.2"><p id="zh-cn_topic_0000001127284884_p1487943181810"><a name="zh-cn_topic_0000001127284884_p1487943181810"></a><a name="zh-cn_topic_0000001127284884_p1487943181810"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="18.22%" id="mcps1.2.5.1.3"><p id="zh-cn_topic_0000001127284884_p178799381812"><a name="zh-cn_topic_0000001127284884_p178799381812"></a><a name="zh-cn_topic_0000001127284884_p178799381812"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="35.33%" id="mcps1.2.5.1.4"><p id="zh-cn_topic_0000001127284884_p187983181814"><a name="zh-cn_topic_0000001127284884_p187983181814"></a><a name="zh-cn_topic_0000001127284884_p187983181814"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001127284884_row178790311818"><td class="cellrowborder" valign="top" width="18.89%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000001127284884_p128791938181"><a name="zh-cn_topic_0000001127284884_p128791938181"></a><a name="zh-cn_topic_0000001127284884_p128791938181"></a>duration</p>
</td>
<td class="cellrowborder" valign="top" width="27.560000000000002%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000001127284884_p1587911311818"><a name="zh-cn_topic_0000001127284884_p1587911311818"></a><a name="zh-cn_topic_0000001127284884_p1587911311818"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="18.22%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000001127284884_p19879133161815"><a name="zh-cn_topic_0000001127284884_p19879133161815"></a><a name="zh-cn_topic_0000001127284884_p19879133161815"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="35.33%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000001127284884_p108808301819"><a name="zh-cn_topic_0000001127284884_p108808301819"></a><a name="zh-cn_topic_0000001127284884_p108808301819"></a>指定当前动画的运行时长（单位毫秒）。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127284884_row3880839187"><td class="cellrowborder" valign="top" width="18.89%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000001127284884_p1088053111812"><a name="zh-cn_topic_0000001127284884_p1088053111812"></a><a name="zh-cn_topic_0000001127284884_p1088053111812"></a>easing</p>
</td>
<td class="cellrowborder" valign="top" width="27.560000000000002%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000001127284884_p588019351814"><a name="zh-cn_topic_0000001127284884_p588019351814"></a><a name="zh-cn_topic_0000001127284884_p588019351814"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="18.22%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000001127284884_p188801731184"><a name="zh-cn_topic_0000001127284884_p188801731184"></a><a name="zh-cn_topic_0000001127284884_p188801731184"></a>linear</p>
</td>
<td class="cellrowborder" valign="top" width="35.33%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000001127284884_p888019319181"><a name="zh-cn_topic_0000001127284884_p888019319181"></a><a name="zh-cn_topic_0000001127284884_p888019319181"></a>描述动画的时间曲线，支持类型见<a href="#zh-cn_topic_0000001127284884_table3690154751817">表3 easing有效值说明</a>。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127284884_row2880833186"><td class="cellrowborder" valign="top" width="18.89%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000001127284884_p1688018319186"><a name="zh-cn_topic_0000001127284884_p1688018319186"></a><a name="zh-cn_topic_0000001127284884_p1688018319186"></a>delay</p>
</td>
<td class="cellrowborder" valign="top" width="27.560000000000002%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000001127284884_p1388017361816"><a name="zh-cn_topic_0000001127284884_p1388017361816"></a><a name="zh-cn_topic_0000001127284884_p1388017361816"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="18.22%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000001127284884_p6880930185"><a name="zh-cn_topic_0000001127284884_p6880930185"></a><a name="zh-cn_topic_0000001127284884_p6880930185"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="35.33%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000001127284884_p16880193111811"><a name="zh-cn_topic_0000001127284884_p16880193111811"></a><a name="zh-cn_topic_0000001127284884_p16880193111811"></a>设置动画执行的延迟时间（默认值表示无延迟）。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127284884_row188801316184"><td class="cellrowborder" valign="top" width="18.89%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000001127284884_p158801234188"><a name="zh-cn_topic_0000001127284884_p158801234188"></a><a name="zh-cn_topic_0000001127284884_p158801234188"></a>iterations</p>
</td>
<td class="cellrowborder" valign="top" width="27.560000000000002%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000001127284884_p178801430188"><a name="zh-cn_topic_0000001127284884_p178801430188"></a><a name="zh-cn_topic_0000001127284884_p178801430188"></a>number | string</p>
</td>
<td class="cellrowborder" valign="top" width="18.22%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000001127284884_p138801237184"><a name="zh-cn_topic_0000001127284884_p138801237184"></a><a name="zh-cn_topic_0000001127284884_p138801237184"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="35.33%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000001127284884_p1688020301816"><a name="zh-cn_topic_0000001127284884_p1688020301816"></a><a name="zh-cn_topic_0000001127284884_p1688020301816"></a>设置动画执行的次数。number表示固定次数，Infinity枚举表示无限次数播放。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127284884_row148806341814"><td class="cellrowborder" valign="top" width="18.89%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000001127284884_p488083201819"><a name="zh-cn_topic_0000001127284884_p488083201819"></a><a name="zh-cn_topic_0000001127284884_p488083201819"></a>direction<sup id="zh-cn_topic_0000001127284884_sup58815331816"><a name="zh-cn_topic_0000001127284884_sup58815331816"></a><a name="zh-cn_topic_0000001127284884_sup58815331816"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="27.560000000000002%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000001127284884_p58811336188"><a name="zh-cn_topic_0000001127284884_p58811336188"></a><a name="zh-cn_topic_0000001127284884_p58811336188"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="18.22%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000001127284884_p19881153131811"><a name="zh-cn_topic_0000001127284884_p19881153131811"></a><a name="zh-cn_topic_0000001127284884_p19881153131811"></a>normal</p>
</td>
<td class="cellrowborder" valign="top" width="35.33%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000001127284884_p3881193101815"><a name="zh-cn_topic_0000001127284884_p3881193101815"></a><a name="zh-cn_topic_0000001127284884_p3881193101815"></a>指定动画的播放模式：</p>
<p id="zh-cn_topic_0000001127284884_p1588153131811"><a name="zh-cn_topic_0000001127284884_p1588153131811"></a><a name="zh-cn_topic_0000001127284884_p1588153131811"></a>normal： 动画正向循环播放；</p>
<p id="zh-cn_topic_0000001127284884_p13881123111810"><a name="zh-cn_topic_0000001127284884_p13881123111810"></a><a name="zh-cn_topic_0000001127284884_p13881123111810"></a>reverse： 动画反向循环播放；</p>
<p id="zh-cn_topic_0000001127284884_p138810381815"><a name="zh-cn_topic_0000001127284884_p138810381815"></a><a name="zh-cn_topic_0000001127284884_p138810381815"></a>alternate：动画交替循环播放，奇数次正向播放，偶数次反向播放；</p>
<p id="zh-cn_topic_0000001127284884_p4881113131815"><a name="zh-cn_topic_0000001127284884_p4881113131815"></a><a name="zh-cn_topic_0000001127284884_p4881113131815"></a>alternate-reverse：动画反向交替循环播放，奇数次反向播放，偶数次正向播放。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127284884_row6881735184"><td class="cellrowborder" valign="top" width="18.89%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000001127284884_p198818313188"><a name="zh-cn_topic_0000001127284884_p198818313188"></a><a name="zh-cn_topic_0000001127284884_p198818313188"></a>fill</p>
</td>
<td class="cellrowborder" valign="top" width="27.560000000000002%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000001127284884_p6881932180"><a name="zh-cn_topic_0000001127284884_p6881932180"></a><a name="zh-cn_topic_0000001127284884_p6881932180"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="18.22%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000001127284884_p1488115331818"><a name="zh-cn_topic_0000001127284884_p1488115331818"></a><a name="zh-cn_topic_0000001127284884_p1488115331818"></a>none</p>
</td>
<td class="cellrowborder" valign="top" width="35.33%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000001127284884_p1688115317182"><a name="zh-cn_topic_0000001127284884_p1688115317182"></a><a name="zh-cn_topic_0000001127284884_p1688115317182"></a>指定动画开始和结束的状态：</p>
<p id="zh-cn_topic_0000001127284884_p8881153181813"><a name="zh-cn_topic_0000001127284884_p8881153181813"></a><a name="zh-cn_topic_0000001127284884_p8881153181813"></a>none：在动画执行之前和之后都不会应用任何样式到目标上。</p>
<p id="zh-cn_topic_0000001127284884_p1188143131812"><a name="zh-cn_topic_0000001127284884_p1188143131812"></a><a name="zh-cn_topic_0000001127284884_p1188143131812"></a>forwards：在动画结束后，目标将保留动画结束时的状态（在最后一个关键帧中定义）。</p>
<p id="zh-cn_topic_0000001127284884_p5881938182"><a name="zh-cn_topic_0000001127284884_p5881938182"></a><a name="zh-cn_topic_0000001127284884_p5881938182"></a>backwards<sup id="zh-cn_topic_0000001127284884_sup138811738182"><a name="zh-cn_topic_0000001127284884_sup138811738182"></a><a name="zh-cn_topic_0000001127284884_sup138811738182"></a>6+</sup>：动画将在animation-delay期间应用第一个关键帧中定义的值。当animation-direction为"normal"或"alternate"时应用from关键帧中的值，当animation-direction为"reverse"或"alternate-reverse"时应用to关键帧中的值。</p>
<p id="zh-cn_topic_0000001127284884_p1788173201814"><a name="zh-cn_topic_0000001127284884_p1788173201814"></a><a name="zh-cn_topic_0000001127284884_p1788173201814"></a>both<sup id="zh-cn_topic_0000001127284884_sup1588111341817"><a name="zh-cn_topic_0000001127284884_sup1588111341817"></a><a name="zh-cn_topic_0000001127284884_sup1588111341817"></a>6+</sup>：动画将遵循forwards和backwards的规则，从而在两个方向上扩展动画属性。</p>
</td>
</tr>
</tbody>
</table>

**表 7**  easing有效值说明

<a name="zh-cn_topic_0000001127284884_table3690154751817"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001127284884_row13690647151813"><th class="cellrowborder" valign="top" width="37.940000000000005%" id="mcps1.2.3.1.1"><p id="zh-cn_topic_0000001127284884_p3690247111819"><a name="zh-cn_topic_0000001127284884_p3690247111819"></a><a name="zh-cn_topic_0000001127284884_p3690247111819"></a>值</p>
</th>
<th class="cellrowborder" valign="top" width="62.06%" id="mcps1.2.3.1.2"><p id="zh-cn_topic_0000001127284884_p176901647121812"><a name="zh-cn_topic_0000001127284884_p176901647121812"></a><a name="zh-cn_topic_0000001127284884_p176901647121812"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001127284884_row0690134712189"><td class="cellrowborder" valign="top" width="37.940000000000005%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001127284884_p269084719187"><a name="zh-cn_topic_0000001127284884_p269084719187"></a><a name="zh-cn_topic_0000001127284884_p269084719187"></a>linear</p>
</td>
<td class="cellrowborder" valign="top" width="62.06%" headers="mcps1.2.3.1.2 "><p id="zh-cn_topic_0000001127284884_p269004718188"><a name="zh-cn_topic_0000001127284884_p269004718188"></a><a name="zh-cn_topic_0000001127284884_p269004718188"></a>动画线性变化。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127284884_row206901947121815"><td class="cellrowborder" valign="top" width="37.940000000000005%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001127284884_p969016479185"><a name="zh-cn_topic_0000001127284884_p969016479185"></a><a name="zh-cn_topic_0000001127284884_p969016479185"></a>ease-in</p>
</td>
<td class="cellrowborder" valign="top" width="62.06%" headers="mcps1.2.3.1.2 "><p id="zh-cn_topic_0000001127284884_p1169094710187"><a name="zh-cn_topic_0000001127284884_p1169094710187"></a><a name="zh-cn_topic_0000001127284884_p1169094710187"></a>动画速度先慢后快，cubic-bezier(0.42, 0.0, 1.0, 1.0)。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127284884_row11690174717183"><td class="cellrowborder" valign="top" width="37.940000000000005%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001127284884_p176901047111811"><a name="zh-cn_topic_0000001127284884_p176901047111811"></a><a name="zh-cn_topic_0000001127284884_p176901047111811"></a>ease-out</p>
</td>
<td class="cellrowborder" valign="top" width="62.06%" headers="mcps1.2.3.1.2 "><p id="zh-cn_topic_0000001127284884_p969119478180"><a name="zh-cn_topic_0000001127284884_p969119478180"></a><a name="zh-cn_topic_0000001127284884_p969119478180"></a>动画速度先快后慢，cubic-bezier(0.0, 0.0, 0.58, 1.0)。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127284884_row6691204712187"><td class="cellrowborder" valign="top" width="37.940000000000005%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001127284884_p1769111472182"><a name="zh-cn_topic_0000001127284884_p1769111472182"></a><a name="zh-cn_topic_0000001127284884_p1769111472182"></a>ease-in-out</p>
</td>
<td class="cellrowborder" valign="top" width="62.06%" headers="mcps1.2.3.1.2 "><p id="zh-cn_topic_0000001127284884_p6691104721812"><a name="zh-cn_topic_0000001127284884_p6691104721812"></a><a name="zh-cn_topic_0000001127284884_p6691104721812"></a>动画先加速后减速，cubic-bezier(0.42, 0.0, 0.58, 1.0)。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127284884_row1269154713187"><td class="cellrowborder" valign="top" width="37.940000000000005%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001127284884_p116910479183"><a name="zh-cn_topic_0000001127284884_p116910479183"></a><a name="zh-cn_topic_0000001127284884_p116910479183"></a>friction</p>
</td>
<td class="cellrowborder" valign="top" width="62.06%" headers="mcps1.2.3.1.2 "><p id="zh-cn_topic_0000001127284884_p176915478186"><a name="zh-cn_topic_0000001127284884_p176915478186"></a><a name="zh-cn_topic_0000001127284884_p176915478186"></a>阻尼曲线，cubic-bezier(0.2, 0.0, 0.2, 1.0)。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127284884_row469134713183"><td class="cellrowborder" valign="top" width="37.940000000000005%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001127284884_p1969124717186"><a name="zh-cn_topic_0000001127284884_p1969124717186"></a><a name="zh-cn_topic_0000001127284884_p1969124717186"></a>extreme-deceleration</p>
</td>
<td class="cellrowborder" valign="top" width="62.06%" headers="mcps1.2.3.1.2 "><p id="zh-cn_topic_0000001127284884_p6691547171811"><a name="zh-cn_topic_0000001127284884_p6691547171811"></a><a name="zh-cn_topic_0000001127284884_p6691547171811"></a>急缓曲线，cubic-bezier(0.0, 0.0, 0.0, 1.0)。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127284884_row1169113473183"><td class="cellrowborder" valign="top" width="37.940000000000005%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001127284884_p469194713185"><a name="zh-cn_topic_0000001127284884_p469194713185"></a><a name="zh-cn_topic_0000001127284884_p469194713185"></a>sharp</p>
</td>
<td class="cellrowborder" valign="top" width="62.06%" headers="mcps1.2.3.1.2 "><p id="zh-cn_topic_0000001127284884_p126915471189"><a name="zh-cn_topic_0000001127284884_p126915471189"></a><a name="zh-cn_topic_0000001127284884_p126915471189"></a>锐利曲线，cubic-bezier(0.33, 0.0, 0.67, 1.0)。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127284884_row1269174710185"><td class="cellrowborder" valign="top" width="37.940000000000005%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001127284884_p15691347171817"><a name="zh-cn_topic_0000001127284884_p15691347171817"></a><a name="zh-cn_topic_0000001127284884_p15691347171817"></a>rhythm</p>
</td>
<td class="cellrowborder" valign="top" width="62.06%" headers="mcps1.2.3.1.2 "><p id="zh-cn_topic_0000001127284884_p176921647121818"><a name="zh-cn_topic_0000001127284884_p176921647121818"></a><a name="zh-cn_topic_0000001127284884_p176921647121818"></a>节奏曲线，cubic-bezier(0.7, 0.0, 0.2, 1.0)。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127284884_row8692847191813"><td class="cellrowborder" valign="top" width="37.940000000000005%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001127284884_p10692124741817"><a name="zh-cn_topic_0000001127284884_p10692124741817"></a><a name="zh-cn_topic_0000001127284884_p10692124741817"></a>smooth</p>
</td>
<td class="cellrowborder" valign="top" width="62.06%" headers="mcps1.2.3.1.2 "><p id="zh-cn_topic_0000001127284884_p15692347111817"><a name="zh-cn_topic_0000001127284884_p15692347111817"></a><a name="zh-cn_topic_0000001127284884_p15692347111817"></a>平滑曲线，cubic-bezier(0.4, 0.0, 0.4, 1.0)。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127284884_row569218476183"><td class="cellrowborder" valign="top" width="37.940000000000005%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001127284884_p969214710189"><a name="zh-cn_topic_0000001127284884_p969214710189"></a><a name="zh-cn_topic_0000001127284884_p969214710189"></a>cubic-bezier(x1, y1, x2, y2)</p>
</td>
<td class="cellrowborder" valign="top" width="62.06%" headers="mcps1.2.3.1.2 "><p id="zh-cn_topic_0000001127284884_p1069234714187"><a name="zh-cn_topic_0000001127284884_p1069234714187"></a><a name="zh-cn_topic_0000001127284884_p1069234714187"></a>在三次贝塞尔函数中定义动画变化过程，入参的x和y值必须处于0-1之间。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127284884_row1269204715181"><td class="cellrowborder" valign="top" width="37.940000000000005%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001127284884_p569284741812"><a name="zh-cn_topic_0000001127284884_p569284741812"></a><a name="zh-cn_topic_0000001127284884_p569284741812"></a>steps(number, step-position)<sup id="zh-cn_topic_0000001127284884_sup1169219475185"><a name="zh-cn_topic_0000001127284884_sup1169219475185"></a><a name="zh-cn_topic_0000001127284884_sup1169219475185"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="62.06%" headers="mcps1.2.3.1.2 "><p id="zh-cn_topic_0000001127284884_p569218472189"><a name="zh-cn_topic_0000001127284884_p569218472189"></a><a name="zh-cn_topic_0000001127284884_p569218472189"></a>Step曲线。</p>
<p id="zh-cn_topic_0000001127284884_p1269244713185"><a name="zh-cn_topic_0000001127284884_p1269244713185"></a><a name="zh-cn_topic_0000001127284884_p1269244713185"></a>number必须设置，支持的类型为int。</p>
<p id="zh-cn_topic_0000001127284884_p8692164761815"><a name="zh-cn_topic_0000001127284884_p8692164761815"></a><a name="zh-cn_topic_0000001127284884_p8692164761815"></a>step-position参数可选，支持设置start或end，默认值为end。</p>
</td>
</tr>
</tbody>
</table>

-   返回值说明

    animation对象支持的属性：

    <a name="zh-cn_topic_0000001127284884_table11261733574"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001127284884_row2029411331076"><th class="cellrowborder" valign="top" width="16.48%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001127284884_p629463316716"><a name="zh-cn_topic_0000001127284884_p629463316716"></a><a name="zh-cn_topic_0000001127284884_p629463316716"></a>属性</p>
    </th>
    <th class="cellrowborder" valign="top" width="20.46%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001127284884_p129411331718"><a name="zh-cn_topic_0000001127284884_p129411331718"></a><a name="zh-cn_topic_0000001127284884_p129411331718"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="63.06%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001127284884_p11294123317716"><a name="zh-cn_topic_0000001127284884_p11294123317716"></a><a name="zh-cn_topic_0000001127284884_p11294123317716"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001127284884_row1429417331711"><td class="cellrowborder" valign="top" width="16.48%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001127284884_p1429416331375"><a name="zh-cn_topic_0000001127284884_p1429416331375"></a><a name="zh-cn_topic_0000001127284884_p1429416331375"></a>finished</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.46%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001127284884_p52943334720"><a name="zh-cn_topic_0000001127284884_p52943334720"></a><a name="zh-cn_topic_0000001127284884_p52943334720"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="63.06%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001127284884_p7294233876"><a name="zh-cn_topic_0000001127284884_p7294233876"></a><a name="zh-cn_topic_0000001127284884_p7294233876"></a>只读，用于表示当前动画是否已播放完成。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001127284884_row493817253419"><td class="cellrowborder" valign="top" width="16.48%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001127284884_p593913251444"><a name="zh-cn_topic_0000001127284884_p593913251444"></a><a name="zh-cn_topic_0000001127284884_p593913251444"></a>pending</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.46%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001127284884_p2939925349"><a name="zh-cn_topic_0000001127284884_p2939925349"></a><a name="zh-cn_topic_0000001127284884_p2939925349"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="63.06%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001127284884_p293911251414"><a name="zh-cn_topic_0000001127284884_p293911251414"></a><a name="zh-cn_topic_0000001127284884_p293911251414"></a>只读，用于表示当前动画是否处于等待其他异步操作完成的等待状态（例如启动一个延时播放的动画）。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001127284884_row11294123313714"><td class="cellrowborder" valign="top" width="16.48%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001127284884_p22943339718"><a name="zh-cn_topic_0000001127284884_p22943339718"></a><a name="zh-cn_topic_0000001127284884_p22943339718"></a>playState</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.46%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001127284884_p1129403315713"><a name="zh-cn_topic_0000001127284884_p1129403315713"></a><a name="zh-cn_topic_0000001127284884_p1129403315713"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="63.06%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001127284884_p1529417331719"><a name="zh-cn_topic_0000001127284884_p1529417331719"></a><a name="zh-cn_topic_0000001127284884_p1529417331719"></a>可读可写，动画的执行状态：</p>
    <a name="zh-cn_topic_0000001127284884_ul854516488179"></a><a name="zh-cn_topic_0000001127284884_ul854516488179"></a><ul id="zh-cn_topic_0000001127284884_ul854516488179"><li>idle：未执行状态，包括已结束或未开始。</li><li>running：动画正在运行。</li><li>paused：动画暂停。</li><li>finished：动画播放完成。</li></ul>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001127284884_row1581113368516"><td class="cellrowborder" valign="top" width="16.48%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001127284884_p128116361853"><a name="zh-cn_topic_0000001127284884_p128116361853"></a><a name="zh-cn_topic_0000001127284884_p128116361853"></a>startTime</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.46%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001127284884_p1281118361053"><a name="zh-cn_topic_0000001127284884_p1281118361053"></a><a name="zh-cn_topic_0000001127284884_p1281118361053"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="63.06%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001127284884_p1581133616512"><a name="zh-cn_topic_0000001127284884_p1581133616512"></a><a name="zh-cn_topic_0000001127284884_p1581133616512"></a>可读可写，动画播放开始的预定时间，用途类似于options参数中的delay。</p>
    </td>
    </tr>
    </tbody>
    </table>

    animation对象支持的方法：

    <a name="zh-cn_topic_0000001127284884_table17991117817"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001127284884_row18321722815"><th class="cellrowborder" valign="top" width="30.86%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001127284884_p9322211811"><a name="zh-cn_topic_0000001127284884_p9322211811"></a><a name="zh-cn_topic_0000001127284884_p9322211811"></a>方法</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.58%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001127284884_p53272783"><a name="zh-cn_topic_0000001127284884_p53272783"></a><a name="zh-cn_topic_0000001127284884_p53272783"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="58.56%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001127284884_p7321921788"><a name="zh-cn_topic_0000001127284884_p7321921788"></a><a name="zh-cn_topic_0000001127284884_p7321921788"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001127284884_row632623816"><td class="cellrowborder" valign="top" width="30.86%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001127284884_p0321827812"><a name="zh-cn_topic_0000001127284884_p0321827812"></a><a name="zh-cn_topic_0000001127284884_p0321827812"></a>play</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.58%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001127284884_p20321121812"><a name="zh-cn_topic_0000001127284884_p20321121812"></a><a name="zh-cn_topic_0000001127284884_p20321121812"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="58.56%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001127284884_p103222388"><a name="zh-cn_topic_0000001127284884_p103222388"></a><a name="zh-cn_topic_0000001127284884_p103222388"></a>组件播放动画。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001127284884_row12321721285"><td class="cellrowborder" valign="top" width="30.86%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001127284884_p1632321988"><a name="zh-cn_topic_0000001127284884_p1632321988"></a><a name="zh-cn_topic_0000001127284884_p1632321988"></a>finish</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.58%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001127284884_p832162782"><a name="zh-cn_topic_0000001127284884_p832162782"></a><a name="zh-cn_topic_0000001127284884_p832162782"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="58.56%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001127284884_p1329219819"><a name="zh-cn_topic_0000001127284884_p1329219819"></a><a name="zh-cn_topic_0000001127284884_p1329219819"></a>组件完成动画。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001127284884_row12321421087"><td class="cellrowborder" valign="top" width="30.86%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001127284884_p18331421383"><a name="zh-cn_topic_0000001127284884_p18331421383"></a><a name="zh-cn_topic_0000001127284884_p18331421383"></a>pause</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.58%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001127284884_p7332218813"><a name="zh-cn_topic_0000001127284884_p7332218813"></a><a name="zh-cn_topic_0000001127284884_p7332218813"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="58.56%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001127284884_p63317211815"><a name="zh-cn_topic_0000001127284884_p63317211815"></a><a name="zh-cn_topic_0000001127284884_p63317211815"></a>组件暂停动画。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001127284884_row153318215815"><td class="cellrowborder" valign="top" width="30.86%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001127284884_p2331021080"><a name="zh-cn_topic_0000001127284884_p2331021080"></a><a name="zh-cn_topic_0000001127284884_p2331021080"></a>cancel</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.58%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001127284884_p1133422818"><a name="zh-cn_topic_0000001127284884_p1133422818"></a><a name="zh-cn_topic_0000001127284884_p1133422818"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="58.56%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001127284884_p533162482"><a name="zh-cn_topic_0000001127284884_p533162482"></a><a name="zh-cn_topic_0000001127284884_p533162482"></a>组件取消动画。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001127284884_row833142687"><td class="cellrowborder" valign="top" width="30.86%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001127284884_p113313216816"><a name="zh-cn_topic_0000001127284884_p113313216816"></a><a name="zh-cn_topic_0000001127284884_p113313216816"></a>reverse</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.58%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001127284884_p17331321689"><a name="zh-cn_topic_0000001127284884_p17331321689"></a><a name="zh-cn_topic_0000001127284884_p17331321689"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="58.56%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001127284884_p1733521285"><a name="zh-cn_topic_0000001127284884_p1733521285"></a><a name="zh-cn_topic_0000001127284884_p1733521285"></a>组件倒播动画。</p>
    </td>
    </tr>
    </tbody>
    </table>

    animation对象支持的事件：

    <a name="zh-cn_topic_0000001127284884_table42538381785"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001127284884_row16274163811819"><th class="cellrowborder" valign="top" width="20.810000000000002%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001127284884_p13274123816814"><a name="zh-cn_topic_0000001127284884_p13274123816814"></a><a name="zh-cn_topic_0000001127284884_p13274123816814"></a>事件</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.19%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001127284884_p7274163812815"><a name="zh-cn_topic_0000001127284884_p7274163812815"></a><a name="zh-cn_topic_0000001127284884_p7274163812815"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001127284884_row117422274135"><td class="cellrowborder" valign="top" width="20.810000000000002%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001127284884_p47421127121318"><a name="zh-cn_topic_0000001127284884_p47421127121318"></a><a name="zh-cn_topic_0000001127284884_p47421127121318"></a>start<sup id="zh-cn_topic_0000001127284884_sup1414915482315"><a name="zh-cn_topic_0000001127284884_sup1414915482315"></a><a name="zh-cn_topic_0000001127284884_sup1414915482315"></a><span>6+</span></sup></p>
    </td>
    <td class="cellrowborder" valign="top" width="79.19%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001127284884_p167421827181315"><a name="zh-cn_topic_0000001127284884_p167421827181315"></a><a name="zh-cn_topic_0000001127284884_p167421827181315"></a>动画开始事件。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001127284884_row12749389813"><td class="cellrowborder" valign="top" width="20.810000000000002%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001127284884_p1927412381487"><a name="zh-cn_topic_0000001127284884_p1927412381487"></a><a name="zh-cn_topic_0000001127284884_p1927412381487"></a>cancel</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.19%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001127284884_p17274203812816"><a name="zh-cn_topic_0000001127284884_p17274203812816"></a><a name="zh-cn_topic_0000001127284884_p17274203812816"></a>动画被强制取消。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001127284884_row13274938488"><td class="cellrowborder" valign="top" width="20.810000000000002%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001127284884_p1727412383815"><a name="zh-cn_topic_0000001127284884_p1727412383815"></a><a name="zh-cn_topic_0000001127284884_p1727412383815"></a>finish</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.19%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001127284884_p1327416383814"><a name="zh-cn_topic_0000001127284884_p1327416383814"></a><a name="zh-cn_topic_0000001127284884_p1327416383814"></a>动画播放完成。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001127284884_row7836145011411"><td class="cellrowborder" valign="top" width="20.810000000000002%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001127284884_p208371050154117"><a name="zh-cn_topic_0000001127284884_p208371050154117"></a><a name="zh-cn_topic_0000001127284884_p208371050154117"></a>repeat</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.19%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001127284884_p583735020415"><a name="zh-cn_topic_0000001127284884_p583735020415"></a><a name="zh-cn_topic_0000001127284884_p583735020415"></a>动画重播事件。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   示例代码：

    ```
    <!-- xxx.hml -->
    <div class="container">
      <div id="idName" class="box"></div>
      <div class="buttonBox">
        <button @click="start">
          start
        </button>
        <button @click="cancel">
          cancels
        </button>
      </div>
    </div>
    ```

    ```
    /* xxx.css */
    .container {
      flex-direction: column;
      justify-content: center;
      align-items: center;
      width: 100%;
    }
    .box{
      width: 200px;
      height: 200px;
      background-color: #ff0000;
      margin-top: 30px;
    }
    .buttonBox{
      margin-top: 30px;
      width: 250px;
      justify-content: space-between;
    }
    button{
      background-color: #8e8b89;
      color: white;
      width: 100px;
      height: 40px;
      font-size: 24px;
    }
    ```

    ```
    // xxx.js
    import prompt from '@system.prompt';
    export default{
      data:{
        animation:'',
      },
      onInit(){
      },
      onShow(){
        var options = {
          duration: 1500,
          easing: 'friction',
          delay: 500,
          fill: 'forwards',
          iterations: 2,
          direction: 'normal',
        };
        var frames = [
          {transform: {translate: '-120px -0px'}, opacity: 0.1, offset: 0.0},
          {transform: {translate: '120px 0px'}, opacity: 1.0, offset: 1.0}
        ];
        this.animation = this.$element('idName').animate(frames, options);
        // handle finish event
        this.animation.onfinish = function(){
          prompt.showToast({
            message: "The animation is finished."
          });
        };
        // handle cancel event
        this.animation.oncancel = function(){
          prompt.showToast({
            message: "The animation is canceled."
          });
        };
        // handle repeat event
        this.animation.onrepeat = function(){
           prompt.showToast({
              message: "The animation is repeated."
           });
        };
      },
      start(){
        this.animation.play();
      },
      cancel(){
        this.animation.cancel();
      }
    }
    ```

    ![](figures/AnimationAPI裁剪.gif)


## this.$element\('_id_'\).getBoundingClientRect\(\)<sup>6+</sup><a name="zh-cn_topic_0000001127284884_section8611320155314"></a>

获取元素的大小及其相对于窗口的位置。

-   示例

    ```
    // xxx.js
    var rect = this.$element('id').getBoundingClientRect();
    console.info(`current element position is ${rect.left}, ${rect.top}`);
    ```


## this.$element\('_id_'\).createIntersectionObserver\(\)<sup>6+</sup><a name="zh-cn_topic_0000001127284884_section137899052719"></a>

监听元素在当前页面的可见范围。

-   示例

    ```
    // xxx.js
    let observer = this.$element('broad').createIntersectionObserver({
      ratios: [0.2, 0.5], // number
    });
    
    observer.observe((isVisible, ratio)=> {
        console.info('this element is ' + isVisible + 'ratio is ' + ratio)
    })
    
    observer.unobserve()
    ```


