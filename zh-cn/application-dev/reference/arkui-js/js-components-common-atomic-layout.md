# 原子布局<a name="ZH-CN_TOPIC_0000001127125020"></a>

在屏幕形态和规格不同等情况下，布局效果需要实现自适应，因此系统提供了面向不同屏幕尺寸界面自适应适配的布局能力，称为原子布局。设计师可以考虑使用原子能力，定义元素在不同形态的尺寸界面上体现的自适应规则。开发者可以使用原子布局能力，快速实现让应用在多形态屏幕上有与设计效果相匹配的自适应效果。

## 隐藏能力<a name="section0441154013284"></a>

在非折行flex布局基础上，增加了显示优先级标记，可以调整组件内元素水平/垂直方向的显示优先级，根据当前组件容器的可用空间来显示内容。

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="15.65%" id="mcps1.1.5.1.1"><p>样式</p>
</th>
<th class="cellrowborder" valign="top" width="13.270000000000001%" id="mcps1.1.5.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="11.58%" id="mcps1.1.5.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="59.5%" id="mcps1.1.5.1.4"><p>说明</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="15.65%" headers="mcps1.1.5.1.1 "><p>display-index</p>
</td>
<td class="cellrowborder" valign="top" width="13.270000000000001%" headers="mcps1.1.5.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.58%" headers="mcps1.1.5.1.3 "><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="59.5%" headers="mcps1.1.5.1.4 "><p>适用于div等支持flex布局的容器组件中的子组件上，当容器组件在flex主轴上尺寸不足以显示全部内容时，按照display-index值从小到大的顺序进行隐藏，具有相同display-index值的组件同时隐藏，默认值为0，表示隐藏。</p>
</td>
</tr>
</tbody>
</table>

## 占比能力<a name="section13725752194418"></a>

在非折行的flex布局中，定义了占比能力的组件，保证指定元素始终在容器的某一个比例空间中进行布局。

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="15.65%" id="mcps1.1.5.1.1"><p>样式</p>
</th>
<th class="cellrowborder" valign="top" width="13.270000000000001%" id="mcps1.1.5.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="11.58%" id="mcps1.1.5.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="59.5%" id="mcps1.1.5.1.4"><p>说明</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="15.65%" headers="mcps1.1.5.1.1 "><p>flex-weight</p>
</td>
<td class="cellrowborder" valign="top" width="13.270000000000001%" headers="mcps1.1.5.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.58%" headers="mcps1.1.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="59.5%" headers="mcps1.1.5.1.4 "><p>指明当前元素在flex主轴方向上尺寸权值，当且仅当容器组件中所有节点均设置此属性时生效，当前元素尺寸为： 容器主轴尺寸 * 当前权值 / 所有子元素权值和。</p>
</td>
</tr>
</tbody>
</table>

## 固定比例<a name="section922215811557"></a>

定义了组件固定比例调整尺寸的能力。

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="15.65%" id="mcps1.1.5.1.1"><p>样式</p>
</th>
<th class="cellrowborder" valign="top" width="13.270000000000001%" id="mcps1.1.5.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="11.58%" id="mcps1.1.5.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="59.5%" id="mcps1.1.5.1.4"><p>说明</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="15.65%" headers="mcps1.1.5.1.1 "><p>aspect-ratio</p>
</td>
<td class="cellrowborder" valign="top" width="13.270000000000001%" headers="mcps1.1.5.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.58%" headers="mcps1.1.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="59.5%" headers="mcps1.1.5.1.4 "><p>1. 接受任意大于0的浮点值，定义为该节点的宽度与高度比，设置该属性后，该元素尺寸宽高比按照此属性值进行调整。</p>
<p>2. 遵守最大值与最小值的限制。</p>
<p>3. 在flex布局中，主轴尺寸先进行调整，后根据该尺寸调整交叉轴。</p>
</td>
</tr>
</tbody>
</table>

