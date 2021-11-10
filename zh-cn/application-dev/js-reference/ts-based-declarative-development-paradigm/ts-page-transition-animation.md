# 页面间转场<a name="ZH-CN_TOPIC_0000001119927608"></a>

页面转场通过在全局pageTransition方法内配置页面入场组件和页面退场组件来自定义页面转场动效。

<a name="table290mcpsimp"></a>
<table><thead align="left"><tr id="row296mcpsimp"><th class="cellrowborder" valign="top" width="22.12%" id="mcps1.1.4.1.1"><p id="p298mcpsimp"><a name="p298mcpsimp"></a><a name="p298mcpsimp"></a>组件名称</p>
</th>
<th class="cellrowborder" valign="top" width="17.31%" id="mcps1.1.4.1.2"><p id="p300mcpsimp"><a name="p300mcpsimp"></a><a name="p300mcpsimp"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="60.57%" id="mcps1.1.4.1.3"><p id="p302mcpsimp"><a name="p302mcpsimp"></a><a name="p302mcpsimp"></a>参数描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row303mcpsimp"><td class="cellrowborder" valign="top" width="22.12%" headers="mcps1.1.4.1.1 "><p id="p2047213614526"><a name="p2047213614526"></a><a name="p2047213614526"></a>PageTransitionEnter</p>
</td>
<td class="cellrowborder" valign="top" width="17.31%" headers="mcps1.1.4.1.2 "><p id="p25634210247"><a name="p25634210247"></a><a name="p25634210247"></a>Object</p>
</td>
<td class="cellrowborder" valign="top" width="60.57%" headers="mcps1.1.4.1.3 "><p id="p309mcpsimp"><a name="p309mcpsimp"></a><a name="p309mcpsimp"></a>页面入场组件，用于自定义当前页面的入场效果，详见<a href="#li1947672255711">动效参数说明</a>。</p>
</td>
</tr>
<tr id="row310mcpsimp"><td class="cellrowborder" valign="top" width="22.12%" headers="mcps1.1.4.1.1 "><p id="p312mcpsimp"><a name="p312mcpsimp"></a><a name="p312mcpsimp"></a>PageTransitionExit</p>
</td>
<td class="cellrowborder" valign="top" width="17.31%" headers="mcps1.1.4.1.2 "><p id="p229674132017"><a name="p229674132017"></a><a name="p229674132017"></a>Object</p>
</td>
<td class="cellrowborder" valign="top" width="60.57%" headers="mcps1.1.4.1.3 "><p id="p316mcpsimp"><a name="p316mcpsimp"></a><a name="p316mcpsimp"></a>页面退场组件，用于自定义当前页面的退场效果，详见<a href="#li1947672255711">动效参数说明</a>。</p>
</td>
</tr>
</tbody>
</table>

-   <a name="li1947672255711"></a>动效参数说明

    <a name="table5380mcpsimp"></a>
    <table><thead align="left"><tr id="row5388mcpsimp"><th class="cellrowborder" valign="top" width="10.67961165048544%" id="mcps1.1.6.1.1"><p id="p5390mcpsimp"><a name="p5390mcpsimp"></a><a name="p5390mcpsimp"></a>参数名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="17.47572815533981%" id="mcps1.1.6.1.2"><p id="p5392mcpsimp"><a name="p5392mcpsimp"></a><a name="p5392mcpsimp"></a>参数类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.92233009708738%" id="mcps1.1.6.1.3"><p id="p5394mcpsimp"><a name="p5394mcpsimp"></a><a name="p5394mcpsimp"></a>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.116504854368934%" id="mcps1.1.6.1.4"><p id="p5396mcpsimp"><a name="p5396mcpsimp"></a><a name="p5396mcpsimp"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="50.80582524271845%" id="mcps1.1.6.1.5"><p id="p5398mcpsimp"><a name="p5398mcpsimp"></a><a name="p5398mcpsimp"></a>参数描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row5399mcpsimp"><td class="cellrowborder" valign="top" width="10.67961165048544%" headers="mcps1.1.6.1.1 "><p id="p5401mcpsimp"><a name="p5401mcpsimp"></a><a name="p5401mcpsimp"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="17.47572815533981%" headers="mcps1.1.6.1.2 "><p id="p5403mcpsimp"><a name="p5403mcpsimp"></a><a name="p5403mcpsimp"></a><a href="#li1364031695819">RouteType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="10.92233009708738%" headers="mcps1.1.6.1.3 "><p id="p5405mcpsimp"><a name="p5405mcpsimp"></a><a name="p5405mcpsimp"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.116504854368934%" headers="mcps1.1.6.1.4 "><p id="p5407mcpsimp"><a name="p5407mcpsimp"></a><a name="p5407mcpsimp"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="50.80582524271845%" headers="mcps1.1.6.1.5 "><p id="p5409mcpsimp"><a name="p5409mcpsimp"></a><a name="p5409mcpsimp"></a>不配置时表明pop为push时效果的逆播。</p>
    </td>
    </tr>
    <tr id="row5410mcpsimp"><td class="cellrowborder" valign="top" width="10.67961165048544%" headers="mcps1.1.6.1.1 "><p id="p5412mcpsimp"><a name="p5412mcpsimp"></a><a name="p5412mcpsimp"></a>duration</p>
    </td>
    <td class="cellrowborder" valign="top" width="17.47572815533981%" headers="mcps1.1.6.1.2 "><p id="p5414mcpsimp"><a name="p5414mcpsimp"></a><a name="p5414mcpsimp"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.92233009708738%" headers="mcps1.1.6.1.3 "><p id="p5416mcpsimp"><a name="p5416mcpsimp"></a><a name="p5416mcpsimp"></a>1000</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.116504854368934%" headers="mcps1.1.6.1.4 "><p id="p5418mcpsimp"><a name="p5418mcpsimp"></a><a name="p5418mcpsimp"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="50.80582524271845%" headers="mcps1.1.6.1.5 "><p id="p5420mcpsimp"><a name="p5420mcpsimp"></a><a name="p5420mcpsimp"></a>动画时长，单位为毫秒。</p>
    </td>
    </tr>
    <tr id="row5421mcpsimp"><td class="cellrowborder" valign="top" width="10.67961165048544%" headers="mcps1.1.6.1.1 "><p id="p5423mcpsimp"><a name="p5423mcpsimp"></a><a name="p5423mcpsimp"></a>curve</p>
    </td>
    <td class="cellrowborder" valign="top" width="17.47572815533981%" headers="mcps1.1.6.1.2 "><p id="p5425mcpsimp"><a name="p5425mcpsimp"></a><a name="p5425mcpsimp"></a>Curve | Curves</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.92233009708738%" headers="mcps1.1.6.1.3 "><p id="p5427mcpsimp"><a name="p5427mcpsimp"></a><a name="p5427mcpsimp"></a>Linear</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.116504854368934%" headers="mcps1.1.6.1.4 "><p id="p5429mcpsimp"><a name="p5429mcpsimp"></a><a name="p5429mcpsimp"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="50.80582524271845%" headers="mcps1.1.6.1.5 "><p id="p5431mcpsimp"><a name="p5431mcpsimp"></a><a name="p5431mcpsimp"></a>动画曲线，有效值参见<a href="ts-animatorproperty.md#li16621545614">Curve</a> 说明。</p>
    </td>
    </tr>
    <tr id="row5432mcpsimp"><td class="cellrowborder" valign="top" width="10.67961165048544%" headers="mcps1.1.6.1.1 "><p id="p5434mcpsimp"><a name="p5434mcpsimp"></a><a name="p5434mcpsimp"></a>delay</p>
    </td>
    <td class="cellrowborder" valign="top" width="17.47572815533981%" headers="mcps1.1.6.1.2 "><p id="p5436mcpsimp"><a name="p5436mcpsimp"></a><a name="p5436mcpsimp"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.92233009708738%" headers="mcps1.1.6.1.3 "><p id="p5438mcpsimp"><a name="p5438mcpsimp"></a><a name="p5438mcpsimp"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.116504854368934%" headers="mcps1.1.6.1.4 "><p id="p5440mcpsimp"><a name="p5440mcpsimp"></a><a name="p5440mcpsimp"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="50.80582524271845%" headers="mcps1.1.6.1.5 "><p id="p5442mcpsimp"><a name="p5442mcpsimp"></a><a name="p5442mcpsimp"></a>动画延迟时长，单位为毫秒，默认不延时播放。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   <a name="li1364031695819"></a>RouteType枚举说明

    <a name="table3452114216394"></a>
    <table><thead align="left"><tr id="row245219426397"><th class="cellrowborder" valign="top" width="25.2%" id="mcps1.1.3.1.1"><p id="p545244283914"><a name="p545244283914"></a><a name="p545244283914"></a>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.8%" id="mcps1.1.3.1.2"><p id="p2452114203917"><a name="p2452114203917"></a><a name="p2452114203917"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row6452144218390"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p34529427398"><a name="p34529427398"></a><a name="p34529427398"></a>Pop</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p1245211421393"><a name="p1245211421393"></a><a name="p1245211421393"></a>PageA跳转到PageB时，PageA为Exit+Push，PageB为Enter+Push。</p>
    </td>
    </tr>
    <tr id="row12452184217398"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p54523425398"><a name="p54523425398"></a><a name="p54523425398"></a>Push</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p745215426391"><a name="p745215426391"></a><a name="p745215426391"></a>PageB返回至PageA时，PageA为Enter+Pop，PageB为Exit+Pop。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 属性<a name="section4182144743016"></a>

PageTransitionEnter和PageTransitionExit组件支持的属性：

<a name="table5448mcpsimp"></a>
<table><thead align="left"><tr id="row5456mcpsimp"><th class="cellrowborder" valign="top" width="10.679611650485436%" id="mcps1.1.6.1.1"><p id="p5458mcpsimp"><a name="p5458mcpsimp"></a><a name="p5458mcpsimp"></a>参数名称</p>
</th>
<th class="cellrowborder" valign="top" width="19.28155339805825%" id="mcps1.1.6.1.2"><p id="p5460mcpsimp"><a name="p5460mcpsimp"></a><a name="p5460mcpsimp"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="14.24271844660194%" id="mcps1.1.6.1.3"><p id="p5462mcpsimp"><a name="p5462mcpsimp"></a><a name="p5462mcpsimp"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="9.155339805825243%" id="mcps1.1.6.1.4"><p id="p5464mcpsimp"><a name="p5464mcpsimp"></a><a name="p5464mcpsimp"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="46.640776699029125%" id="mcps1.1.6.1.5"><p id="p5466mcpsimp"><a name="p5466mcpsimp"></a><a name="p5466mcpsimp"></a>参数描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row5467mcpsimp"><td class="cellrowborder" valign="top" width="10.679611650485436%" headers="mcps1.1.6.1.1 "><p id="p5469mcpsimp"><a name="p5469mcpsimp"></a><a name="p5469mcpsimp"></a>slide</p>
</td>
<td class="cellrowborder" valign="top" width="19.28155339805825%" headers="mcps1.1.6.1.2 "><p id="p5471mcpsimp"><a name="p5471mcpsimp"></a><a name="p5471mcpsimp"></a>SlideEffect</p>
</td>
<td class="cellrowborder" valign="top" width="14.24271844660194%" headers="mcps1.1.6.1.3 "><p id="p5473mcpsimp"><a name="p5473mcpsimp"></a><a name="p5473mcpsimp"></a>Right</p>
</td>
<td class="cellrowborder" valign="top" width="9.155339805825243%" headers="mcps1.1.6.1.4 "><p id="p5475mcpsimp"><a name="p5475mcpsimp"></a><a name="p5475mcpsimp"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="46.640776699029125%" headers="mcps1.1.6.1.5 "><p id="p5477mcpsimp"><a name="p5477mcpsimp"></a><a name="p5477mcpsimp"></a>设置转场的滑入效果，有效值参见<a href="#li81331342185820">SlideEffect</a>说明。</p>
</td>
</tr>
<tr id="row5478mcpsimp"><td class="cellrowborder" valign="top" width="10.679611650485436%" headers="mcps1.1.6.1.1 "><p id="p5480mcpsimp"><a name="p5480mcpsimp"></a><a name="p5480mcpsimp"></a>translate</p>
</td>
<td class="cellrowborder" valign="top" width="19.28155339805825%" headers="mcps1.1.6.1.2 "><p id="p2093081910118"><a name="p2093081910118"></a><a name="p2093081910118"></a>{</p>
<p id="p18561221131115"><a name="p18561221131115"></a><a name="p18561221131115"></a>x? : number,</p>
<p id="p133781031191110"><a name="p133781031191110"></a><a name="p133781031191110"></a>y? : number,</p>
<p id="p298143417110"><a name="p298143417110"></a><a name="p298143417110"></a>z? : number</p>
<p id="p5482mcpsimp"><a name="p5482mcpsimp"></a><a name="p5482mcpsimp"></a>}</p>
</td>
<td class="cellrowborder" valign="top" width="14.24271844660194%" headers="mcps1.1.6.1.3 "><p id="p5484mcpsimp"><a name="p5484mcpsimp"></a><a name="p5484mcpsimp"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="9.155339805825243%" headers="mcps1.1.6.1.4 "><p id="p5486mcpsimp"><a name="p5486mcpsimp"></a><a name="p5486mcpsimp"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="46.640776699029125%" headers="mcps1.1.6.1.5 "><p id="p5488mcpsimp"><a name="p5488mcpsimp"></a><a name="p5488mcpsimp"></a>设置页面转场时的平移效果，为入场时起点和退场时终点的值，和slide同时设置时默认生效slide。</p>
</td>
</tr>
<tr id="row5489mcpsimp"><td class="cellrowborder" valign="top" width="10.679611650485436%" headers="mcps1.1.6.1.1 "><p id="p5491mcpsimp"><a name="p5491mcpsimp"></a><a name="p5491mcpsimp"></a>scale</p>
</td>
<td class="cellrowborder" valign="top" width="19.28155339805825%" headers="mcps1.1.6.1.2 "><p id="p1042583691118"><a name="p1042583691118"></a><a name="p1042583691118"></a>{</p>
<p id="p14822103741113"><a name="p14822103741113"></a><a name="p14822103741113"></a>x? : number,</p>
<p id="p13761744161112"><a name="p13761744161112"></a><a name="p13761744161112"></a>y? : number,</p>
<p id="p596404721113"><a name="p596404721113"></a><a name="p596404721113"></a>z? : number,</p>
<p id="p8894104961112"><a name="p8894104961112"></a><a name="p8894104961112"></a>centerX? : number,</p>
<p id="p484952201111"><a name="p484952201111"></a><a name="p484952201111"></a>centerY? : number</p>
<p id="p5493mcpsimp"><a name="p5493mcpsimp"></a><a name="p5493mcpsimp"></a>}</p>
</td>
<td class="cellrowborder" valign="top" width="14.24271844660194%" headers="mcps1.1.6.1.3 "><p id="p5495mcpsimp"><a name="p5495mcpsimp"></a><a name="p5495mcpsimp"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="9.155339805825243%" headers="mcps1.1.6.1.4 "><p id="p5497mcpsimp"><a name="p5497mcpsimp"></a><a name="p5497mcpsimp"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="46.640776699029125%" headers="mcps1.1.6.1.5 "><p id="p5499mcpsimp"><a name="p5499mcpsimp"></a><a name="p5499mcpsimp"></a>设置页面转场时的缩放效果，为入场时起点和退场时终点的值。</p>
</td>
</tr>
<tr id="row5500mcpsimp"><td class="cellrowborder" valign="top" width="10.679611650485436%" headers="mcps1.1.6.1.1 "><p id="p5502mcpsimp"><a name="p5502mcpsimp"></a><a name="p5502mcpsimp"></a>opacity</p>
</td>
<td class="cellrowborder" valign="top" width="19.28155339805825%" headers="mcps1.1.6.1.2 "><p id="p5504mcpsimp"><a name="p5504mcpsimp"></a><a name="p5504mcpsimp"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="14.24271844660194%" headers="mcps1.1.6.1.3 "><p id="p5506mcpsimp"><a name="p5506mcpsimp"></a><a name="p5506mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="9.155339805825243%" headers="mcps1.1.6.1.4 "><p id="p5508mcpsimp"><a name="p5508mcpsimp"></a><a name="p5508mcpsimp"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="46.640776699029125%" headers="mcps1.1.6.1.5 "><p id="p5510mcpsimp"><a name="p5510mcpsimp"></a><a name="p5510mcpsimp"></a>设置入场的起点透明度值或者退场的终点透明度值。</p>
</td>
</tr>
</tbody>
</table>

-   <a name="li81331342185820"></a>SlideEffect枚举说明

    <a name="table131131547175411"></a>
    <table><thead align="left"><tr id="row14113947145414"><th class="cellrowborder" valign="top" width="25.2%" id="mcps1.1.3.1.1"><p id="p1111344785419"><a name="p1111344785419"></a><a name="p1111344785419"></a>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.8%" id="mcps1.1.3.1.2"><p id="p711318475541"><a name="p711318475541"></a><a name="p711318475541"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row81131047205413"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p17113947195417"><a name="p17113947195417"></a><a name="p17113947195417"></a>Left</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p5113347125413"><a name="p5113347125413"></a><a name="p5113347125413"></a>设置到入场时表示从左边滑入，出场时表示滑出到左边。</p>
    </td>
    </tr>
    <tr id="row311314471543"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p1911324735411"><a name="p1911324735411"></a><a name="p1911324735411"></a>Right</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p12113247195416"><a name="p12113247195416"></a><a name="p12113247195416"></a>设置到入场时表示从右边滑入，出场时表示滑出到右边。</p>
    </td>
    </tr>
    <tr id="row9452134213392"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p510719111403"><a name="p510719111403"></a><a name="p510719111403"></a>Top</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p154533425394"><a name="p154533425394"></a><a name="p154533425394"></a>设置到入场时表示从上边滑入，出场时表示滑出到上边。</p>
    </td>
    </tr>
    <tr id="row1345313424399"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p1766215124010"><a name="p1766215124010"></a><a name="p1766215124010"></a>Bottom</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p1245319426394"><a name="p1245319426394"></a><a name="p1245319426394"></a>设置到入场时表示从下边滑入，出场时表示滑出到下边。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 事件<a name="section141860153013"></a>

PageTransitionEnter和PageTransitionExit组件支持的事件：

<a name="table5518mcpsimp"></a>
<table><thead align="left"><tr id="row5524mcpsimp"><th class="cellrowborder" colspan="2" valign="top" id="mcps1.1.4.1.1"><p id="p5528mcpsimp"><a name="p5528mcpsimp"></a><a name="p5528mcpsimp"></a>事件</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.1.4.1.2"><p id="p5530mcpsimp"><a name="p5530mcpsimp"></a><a name="p5530mcpsimp"></a>功能描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row5531mcpsimp"><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p id="p5533mcpsimp"><a name="p5533mcpsimp"></a><a name="p5533mcpsimp"></a>onEnter(type: RouteType, progress: number) =&gt; void</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p5537mcpsimp"><a name="p5537mcpsimp"></a><a name="p5537mcpsimp"></a>回调入参为当前入场动画的归一化进度[0 - 1]。</p>
</td>
</tr>
<tr id="row5538mcpsimp"><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p id="p5540mcpsimp"><a name="p5540mcpsimp"></a><a name="p5540mcpsimp"></a>onExit(type: RouteType, progress: number) =&gt; void</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p5544mcpsimp"><a name="p5544mcpsimp"></a><a name="p5544mcpsimp"></a>回调入参为当前退场动画的归一化进度[0 - 1]。</p>
</td>
</tr>
</tbody>
</table>

## 示例<a name="section675104083920"></a>

自定义方式1：配置了当前页面的入场动画为淡入，退场动画为缩小。

```
// index.ets
@Entry
@Component
struct PageTransitionExample1 {
  @State scale: number = 1
  @State opacity: number = 1
  @State active: boolean = false
  build() {
  Column() {
      Navigator({ target: 'pages/page1', type: NavigationType.Push }) {
        Image($r('app.media.bg1')).width("100%").height("100%")
      }
      .onClick(() => {
        this.active = true
      })
    }.scale({ x: this.scale }).opacity(this.opacity)
  }
// 自定义方式1：完全自定义转场过程的效果
  pageTransition() {
    PageTransitionEnter({ duration: 1200, curve: Curve.Linear })
      .onEnter((type: RouteType, progress: number) => {
        this.scale = 1
        this.opacity = progress
      }) // 进场过程中会逐帧触发onEnter回调，入参为动效的归一化进度(0% -- 100%)
    PageTransitionExit({ duration: 1500, curve: Curve.Ease })
      .onExit((type: RouteType, progress: number) => {
        this.scale = 1 - progress
        this.opacity = 1
      }) // 退场过程中会逐帧触发onExit回调，入参为动效的归一化进度(0% -- 100%)
  }
}
```

```
// page1.ets
@Entry
@Component
struct AExample {
  @State scale: number = 1
  @State opacity: number = 1
  @State active: boolean = false
  build() {
    Column() {
      Navigator({ target: 'pages/index' ,type: NavigationType.Push}) {
        Image($r('app.media.bg2')).width("100%").height("100%")
      }
    }.height("100%").width("100%").scale({ x: this.scale }).opacity(this.opacity)
  }
// 自定义方式1：完全自定义转场过程的效果
  pageTransition() {
    PageTransitionEnter({ duration: 1200, curve: Curve.Linear })
      .onEnter((type: RouteType, progress: number) => {
        this.scale = 1
        this.opacity = progress
      }) // 进场过程中会逐帧触发onEnter回调，入参为动效的归一化进度(0% -- 100%)
    PageTransitionExit({ duration: 1500, curve: Curve.Ease })
      .onExit((type: RouteType, progress: number) => {
        this.scale = 1 - progress
        this.opacity = 1
      }) // 退场过程中会逐帧触发onExit回调，入参为动效的归一化进度(0% -- 100%)
  }
}
```

![](figures/PageTransition1.gif)

自定义方式2：配置了当前页面的入场动画为从左侧滑入，退场为缩小加透明度变化。

```
// index.ets 
@Entry
@Component
struct PageTransitionExample {
  @State scale: number = 1
  @State opacity: number = 1
  @State active: boolean = false

  build() {
    Column() {
      Navigator({ target: 'pages/page1', type: NavigationType.Push }) {
        Image($r('app.media.bg1')).width("100%").height("100%")
      }
      .onClick(() => {
        this.active = true
      })
    }.scale({ x: this.scale }).opacity(this.opacity)
  }

// 自定义方式2：使用系统提供的多种默认效果(平移、缩放、透明度等)
  pageTransition() {
    PageTransitionEnter({ duration: 1200 })
      .slide(SlideEffect.Left)
    PageTransitionExit({ delay: 100 })
      .translate({ x: 100.0, y: 100.0 })
      .opacity(0)
  }
}
```

```
// page1.ets
@Entry
@Component
struct PageTransitionExample1 {
  @State scale: number = 1
  @State opacity: number = 1
  @State active: boolean = false

  build() {
    Column() {
      Navigator({ target: 'pages/index', type: NavigationType.Push }) {
        Image($r('app.media.bg2')).width  ("100%").height("100%")
      }
      .onClick(() => {
        this.active = true
      })
    }.scale({ x: this.scale }).opacity(this.opacity)
  }

// 自定义方式2：使用系统提供的多种默认效果(平移、缩放、透明度等)
  pageTransition() {
    PageTransitionEnter({ duration: 1200 })
      .slide(SlideEffect.Left)
    PageTransitionExit({ delay: 100 })
      .translate({ x: 100.0, y: 100.0 })
      .opacity(0)
  }
}
```

![](figures/PageTransition2.gif)

