# 原子布局<a name="ZH-CN_TOPIC_0000001127125020"></a>

在屏幕形态和规格不同等情况下，布局效果需要实现自适应，因此系统提供了面向不同屏幕尺寸界面自适应适配的布局能力，称为原子布局。设计师可以考虑使用原子能力，定义元素在不同形态的尺寸界面上体现的自适应规则。开发者可以使用原子布局能力，快速实现让应用在多形态屏幕上有与设计效果相匹配的自适应效果。

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从API Version 5 开始支持。

## 隐藏能力<a name="section0441154013284"></a>

在非折行flex布局基础上，增加了显示优先级标记，可以调整组件内元素水平/垂直方向的显示优先级，根据当前组件容器的可用空间来显示内容。

<a name="table14323142291413"></a>
<table><thead align="left"><tr id="row232317223144"><th class="cellrowborder" valign="top" width="15.65%" id="mcps1.1.5.1.1"><p id="p85051811127"><a name="p85051811127"></a><a name="p85051811127"></a>样式</p>
</th>
<th class="cellrowborder" valign="top" width="13.270000000000001%" id="mcps1.1.5.1.2"><p id="p2505915217"><a name="p2505915217"></a><a name="p2505915217"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="11.58%" id="mcps1.1.5.1.3"><p id="p8654516123719"><a name="p8654516123719"></a><a name="p8654516123719"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="59.5%" id="mcps1.1.5.1.4"><p id="p75054112213"><a name="p75054112213"></a><a name="p75054112213"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row23236222143"><td class="cellrowborder" valign="top" width="15.65%" headers="mcps1.1.5.1.1 "><p id="p1950519112213"><a name="p1950519112213"></a><a name="p1950519112213"></a>display-index</p>
</td>
<td class="cellrowborder" valign="top" width="13.270000000000001%" headers="mcps1.1.5.1.2 "><p id="p65059111213"><a name="p65059111213"></a><a name="p65059111213"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.58%" headers="mcps1.1.5.1.3 "><p id="p166547162374"><a name="p166547162374"></a><a name="p166547162374"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="59.5%" headers="mcps1.1.5.1.4 "><p id="p3505181129"><a name="p3505181129"></a><a name="p3505181129"></a>适用于div等支持flex布局的容器组件中的子组件上，当容器组件在flex主轴上尺寸不足以显示全部内容时，按照display-index值从小到大的顺序进行隐藏，具有相同display-index值的组件同时隐藏，默认值为0，表示隐藏。</p>
</td>
</tr>
</tbody>
</table>

## 占比能力<a name="section13725752194418"></a>

在非折行的flex布局中，定义了占比能力的组件，保证指定元素始终在容器的某一个比例空间中进行布局。

<a name="table337121117522"></a>
<table><thead align="left"><tr id="row9371811155218"><th class="cellrowborder" valign="top" width="15.65%" id="mcps1.1.5.1.1"><p id="p173711311175216"><a name="p173711311175216"></a><a name="p173711311175216"></a>样式</p>
</th>
<th class="cellrowborder" valign="top" width="13.270000000000001%" id="mcps1.1.5.1.2"><p id="p6371111119529"><a name="p6371111119529"></a><a name="p6371111119529"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="11.58%" id="mcps1.1.5.1.3"><p id="p337181145211"><a name="p337181145211"></a><a name="p337181145211"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="59.5%" id="mcps1.1.5.1.4"><p id="p33711211145213"><a name="p33711211145213"></a><a name="p33711211145213"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1237118111527"><td class="cellrowborder" valign="top" width="15.65%" headers="mcps1.1.5.1.1 "><p id="p17371711195218"><a name="p17371711195218"></a><a name="p17371711195218"></a>flex-weight</p>
</td>
<td class="cellrowborder" valign="top" width="13.270000000000001%" headers="mcps1.1.5.1.2 "><p id="p737191112523"><a name="p737191112523"></a><a name="p737191112523"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.58%" headers="mcps1.1.5.1.3 "><p id="p83711511205218"><a name="p83711511205218"></a><a name="p83711511205218"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="59.5%" headers="mcps1.1.5.1.4 "><p id="p337111112521"><a name="p337111112521"></a><a name="p337111112521"></a>指明当前元素在flex主轴方向上尺寸权值，当且仅当容器组件中所有节点均设置此属性时生效，当前元素尺寸为： 容器主轴尺寸 * 当前权值 / 所有子元素权值和。</p>
</td>
</tr>
</tbody>
</table>

## 固定比例<a name="section922215811557"></a>

定义了组件固定比例调整尺寸的能力。

<a name="table1077611191734"></a>
<table><thead align="left"><tr id="row377618191536"><th class="cellrowborder" valign="top" width="15.65%" id="mcps1.1.5.1.1"><p id="p1776101916316"><a name="p1776101916316"></a><a name="p1776101916316"></a>样式</p>
</th>
<th class="cellrowborder" valign="top" width="13.270000000000001%" id="mcps1.1.5.1.2"><p id="p277618191233"><a name="p277618191233"></a><a name="p277618191233"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="11.58%" id="mcps1.1.5.1.3"><p id="p57762194318"><a name="p57762194318"></a><a name="p57762194318"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="59.5%" id="mcps1.1.5.1.4"><p id="p2776151915313"><a name="p2776151915313"></a><a name="p2776151915313"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row67761119233"><td class="cellrowborder" valign="top" width="15.65%" headers="mcps1.1.5.1.1 "><p id="p10776181914317"><a name="p10776181914317"></a><a name="p10776181914317"></a>aspect-ratio</p>
</td>
<td class="cellrowborder" valign="top" width="13.270000000000001%" headers="mcps1.1.5.1.2 "><p id="p57762019636"><a name="p57762019636"></a><a name="p57762019636"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.58%" headers="mcps1.1.5.1.3 "><p id="p1777613191935"><a name="p1777613191935"></a><a name="p1777613191935"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="59.5%" headers="mcps1.1.5.1.4 "><p id="p12776121918313"><a name="p12776121918313"></a><a name="p12776121918313"></a>1. 接受任意大于0的浮点值，定义为该节点的宽度与高度比，设置该属性后，该元素尺寸宽高比按照此属性值进行调整。</p>
<p id="p3793145491117"><a name="p3793145491117"></a><a name="p3793145491117"></a>2. 遵守最大值与最小值的限制。</p>
<p id="p15216164731415"><a name="p15216164731415"></a><a name="p15216164731415"></a>3. 在flex布局中，主轴尺寸先进行调整，后根据该尺寸调整交叉轴。</p>
</td>
</tr>
</tbody>
</table>

