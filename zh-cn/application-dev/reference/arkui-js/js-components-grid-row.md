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

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="23.11768823117688%" id="mcps1.1.6.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="20.477952204779523%" id="mcps1.1.6.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="8.869113088691131%" id="mcps1.1.6.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.519248075192481%" id="mcps1.1.6.1.4"><p>必填</p>
</th>
<th class="cellrowborder" valign="top" width="40.01599840015999%" id="mcps1.1.6.1.5"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p>flex-wrap</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p>nowrap</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p>flex容器是单行还是多行显示，该值暂不支持动态修改。可选项有：</p>
<ul><li>nowrap：不换行，单行显示。</li><li>wrap：换行，多行显示。</li></ul>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p>justify-content</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p>flex-start</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p>flex容器当前行的主轴对齐格式。可选项有：</p>
<ul><li>flex-start：项目位于容器的开头。</li><li>flex-end：项目位于容器的结尾。</li><li>center：项目位于容器的中心。</li><li>space-between：项目位于各行之间留有空白的容器内。</li><li>space-around：项目位于各行之前、之间、之后都留有空白的容器内。</li></ul>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p>align-items</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p>flex-start</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p>flex容器当前行的交叉轴对齐格式，可选值为：</p>
<ul><li>stretch：弹性元素被在交叉轴方向被拉伸到与容器相同的高度或宽度。</li><li>flex-start：元素向交叉轴起点对齐。</li><li>flex-end：元素向交叉轴终点对齐。</li><li>center：元素在交叉轴居中。</li></ul>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p>align-content</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p>flex-start</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p>交叉轴中有额外的空间时，多行内容对齐格式，可选值为：</p>
<ul><li>flex-start：所有行从交叉轴起点开始填充。第一行的交叉轴起点边和容器的交叉轴起点边对齐。接下来的每一行紧跟前一行。</li><li>flex-end：所有行从交叉轴末尾开始填充。最后一行的交叉轴终点和容器的交叉轴终点对齐。同时所有后续行与前一个对齐。</li><li>center：所有行朝向容器的中心填充。每行互相紧挨，相对于容器居中对齐。容器的交叉轴起点边和第一行的距离相等于容器的交叉轴终点边和最后一行的距离。</li><li>space-between：所有行在容器中平均分布。相邻两行间距相等。容器的交叉轴起点边和终点边分别与第一行和最后一行的边对齐。</li><li>space-around：所有行在容器中平均分布，相邻两行间距相等。容器的交叉轴起点边和终点边分别与第一行和最后一行的距离是相邻两行间距的一半。</li></ul>
</td>
</tr>
</tbody>
</table>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>不支持宽度相关样式。

## 事件<a name="section1417950207"></a>

支持[通用事件](js-components-common-events.md)。

## 方法<a name="section2279124532420"></a>

支持[通用方法](js-components-common-methods.md)。

## 示例<a name="section634316188515"></a>

详见[grid-col示例](js-components-grid-col.md#section2021865273710)。

