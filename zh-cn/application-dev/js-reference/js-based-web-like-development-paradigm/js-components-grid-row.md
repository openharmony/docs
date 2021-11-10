# grid-row<a name="ZH-CN_TOPIC_0000001173324663"></a>

grid-row是栅格布局容器grid-container的子容器组件，使用flex横向布局，排列每个grid-col容器，justify-content与align-items默认为flex-start，支持折行显示。

## 权限列表<a name="section11257113618419"></a>

无

## 子组件<a name="section9288143101012"></a>

仅支持<grid-col\>。

## 属性<a name="section631751545214"></a>

支持[通用属性](js-components-common-attributes.md)。

## 样式<a name="section9475356165220"></a>

除支持[通用样式](js-components-common-styles.md)外，还支持如下样式：

<a name="table1583612162713"></a>
<table><thead align="left"><tr id="row148360114276"><th class="cellrowborder" valign="top" width="23.11768823117688%" id="mcps1.1.6.1.1"><p id="p08361619274"><a name="p08361619274"></a><a name="p08361619274"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="20.477952204779523%" id="mcps1.1.6.1.2"><p id="p48361812276"><a name="p48361812276"></a><a name="p48361812276"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="8.869113088691131%" id="mcps1.1.6.1.3"><p id="p198367112715"><a name="p198367112715"></a><a name="p198367112715"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.519248075192481%" id="mcps1.1.6.1.4"><p id="p1183610152710"><a name="p1183610152710"></a><a name="p1183610152710"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="40.01599840015999%" id="mcps1.1.6.1.5"><p id="p48362162718"><a name="p48362162718"></a><a name="p48362162718"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row17836181102717"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p1283681182714"><a name="p1283681182714"></a><a name="p1283681182714"></a>flex-wrap</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="p11837111182712"><a name="p11837111182712"></a><a name="p11837111182712"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="p1083741172718"><a name="p1083741172718"></a><a name="p1083741172718"></a>nowrap</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p108371218276"><a name="p108371218276"></a><a name="p108371218276"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p883731162713"><a name="p883731162713"></a><a name="p883731162713"></a>flex容器是单行还是多行显示，该值暂不支持动态修改。可选项有：</p>
<a name="ul1583771142719"></a><a name="ul1583771142719"></a><ul id="ul1583771142719"><li>nowrap：不换行，单行显示。</li><li>wrap：换行，多行显示。</li></ul>
</td>
</tr>
<tr id="row14837111202712"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p1883781162717"><a name="p1883781162717"></a><a name="p1883781162717"></a>justify-content</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="p183731102715"><a name="p183731102715"></a><a name="p183731102715"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="p13837111279"><a name="p13837111279"></a><a name="p13837111279"></a>flex-start</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p13837111162713"><a name="p13837111162713"></a><a name="p13837111162713"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p198371919278"><a name="p198371919278"></a><a name="p198371919278"></a>flex容器当前行的主轴对齐格式。可选项有：</p>
<a name="ul20837121152717"></a><a name="ul20837121152717"></a><ul id="ul20837121152717"><li>flex-start：项目位于容器的开头。</li><li>flex-end：项目位于容器的结尾。</li><li>center：项目位于容器的中心。</li><li>space-between：项目位于各行之间留有空白的容器内。</li><li>space-around：项目位于各行之前、之间、之后都留有空白的容器内。</li></ul>
</td>
</tr>
<tr id="row188387162714"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p0838913278"><a name="p0838913278"></a><a name="p0838913278"></a>align-items</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="p138385114274"><a name="p138385114274"></a><a name="p138385114274"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="p983811122713"><a name="p983811122713"></a><a name="p983811122713"></a>flex-start</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p1883812110278"><a name="p1883812110278"></a><a name="p1883812110278"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p983813116271"><a name="p983813116271"></a><a name="p983813116271"></a>flex容器当前行的交叉轴对齐格式，可选值为：</p>
<a name="ul2838201122714"></a><a name="ul2838201122714"></a><ul id="ul2838201122714"><li>stretch：弹性元素被在交叉轴方向被拉伸到与容器相同的高度或宽度。</li><li>flex-start：元素向交叉轴起点对齐。</li><li>flex-end：元素向交叉轴终点对齐。</li><li>center：元素在交叉轴居中。</li></ul>
</td>
</tr>
<tr id="row13839918275"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p88391714276"><a name="p88391714276"></a><a name="p88391714276"></a>align-content</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="p283919116277"><a name="p283919116277"></a><a name="p283919116277"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="p18839181182720"><a name="p18839181182720"></a><a name="p18839181182720"></a>flex-start</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p1683911142717"><a name="p1683911142717"></a><a name="p1683911142717"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p148392011271"><a name="p148392011271"></a><a name="p148392011271"></a>交叉轴中有额外的空间时，多行内容对齐格式，可选值为：</p>
<a name="ul15839101102715"></a><a name="ul15839101102715"></a><ul id="ul15839101102715"><li>flex-start：所有行从交叉轴起点开始填充。第一行的交叉轴起点边和容器的交叉轴起点边对齐。接下来的每一行紧跟前一行。</li><li>flex-end：所有行从交叉轴末尾开始填充。最后一行的交叉轴终点和容器的交叉轴终点对齐。同时所有后续行与前一个对齐。</li><li>center：所有行朝向容器的中心填充。每行互相紧挨，相对于容器居中对齐。容器的交叉轴起点边和第一行的距离相等于容器的交叉轴终点边和最后一行的距离。</li><li>space-between：所有行在容器中平均分布。相邻两行间距相等。容器的交叉轴起点边和终点边分别与第一行和最后一行的边对齐。</li><li>space-around：所有行在容器中平均分布，相邻两行间距相等。容器的交叉轴起点边和终点边分别与第一行和最后一行的距离是相邻两行间距的一半。</li></ul>
</td>
</tr>
</tbody>
</table>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>-   不支持宽度相关样式。

## 事件<a name="section1417950207"></a>

支持[通用事件](js-components-common-events.md)。

## 方法<a name="section2279124532420"></a>

支持[通用方法](js-components-common-methods.md)。

## 示例<a name="section634316188515"></a>

详见[grid-col示例](js-components-grid-col.md#section2021865273710)。

