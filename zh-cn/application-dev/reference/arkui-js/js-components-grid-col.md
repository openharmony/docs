# grid-col<a name="ZH-CN_TOPIC_0000001237760449"></a>

grid-col是栅格布局容器grid-row的子容器组件。

## 权限列表<a name="section11257113618419"></a>

无

## 子组件<a name="section9288143101012"></a>

支持。

## 属性<a name="section1976213199113"></a>

除支持[通用属性](js-components-common-attributes.md)外，还支持如下属性：

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="10.48%" id="mcps1.1.6.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.449999999999999%" id="mcps1.1.6.1.4"><p>必填</p>
</th>
<th class="cellrowborder" valign="top" width="35.83%" id="mcps1.1.6.1.5"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>xs</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p>number|object</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.449999999999999%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.83%" headers="mcps1.1.6.1.5 "><p>在分辨率为xs模式下，设置该项占用列数与偏移列数，当值为number类型时，仅设置列数，也可通过object同时设置占用列数与偏移列数，如{"span": 1, "offset": 0}</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>sm</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p>number|object</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.449999999999999%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.83%" headers="mcps1.1.6.1.5 "><p>在分辨率为sm模式下，该项占用列数与偏移列数，当值为number类型时，仅设置列数，也可通过object同时设置占用列数与偏移列数，如{"span": 1, "offset": 0}</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>md</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p>number|object</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.449999999999999%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.83%" headers="mcps1.1.6.1.5 "><p>在分辨率为md模式下，该项占用列数与偏移列数，当值为number类型时，仅设置列数，也可通过object同时设置占用列数与偏移列数，如{"span": 1, "offset": 0}</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>lg</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p>number|object</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.449999999999999%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.83%" headers="mcps1.1.6.1.5 "><p>在分辨率为lg模式下，该项占用列数与偏移列数，当值为number类型时，仅设置列数，也可通过object同时设置占用列数与偏移列数，如{"span": 1, "offset": 0}</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>span</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p>1</p>
</td>
<td class="cellrowborder" valign="top" width="7.449999999999999%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.83%" headers="mcps1.1.6.1.5 "><p>在未设置明确断点时，默认占用列数</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>offset</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.449999999999999%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.83%" headers="mcps1.1.6.1.5 "><p>未设置具体分辨率模式下偏移时，当前元素延容器布局方向，默认偏移的列数</p>
</td>
</tr>
</tbody>
</table>

## 样式<a name="section1948816404128"></a>

除支持[通用样式](js-components-common-styles.md)外，还支持如下样式：

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="23.11768823117688%" id="mcps1.1.6.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="12.218778122187782%" id="mcps1.1.6.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="13.03869613038696%" id="mcps1.1.6.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="8.4991500849915%" id="mcps1.1.6.1.4"><p>必填</p>
</th>
<th class="cellrowborder" valign="top" width="43.12568743125688%" id="mcps1.1.6.1.5"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p>flex-direction</p>
</td>
<td class="cellrowborder" valign="top" width="12.218778122187782%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.03869613038696%" headers="mcps1.1.6.1.3 "><p>row</p>
</td>
<td class="cellrowborder" valign="top" width="8.4991500849915%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.12568743125688%" headers="mcps1.1.6.1.5 "><p>flex容器主轴方向。可选项有：</p>
<ul><li>column：垂直方向从上到下</li><li>row：水平方向从左到右</li></ul>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p>flex-wrap</p>
</td>
<td class="cellrowborder" valign="top" width="12.218778122187782%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.03869613038696%" headers="mcps1.1.6.1.3 "><p>nowrap</p>
</td>
<td class="cellrowborder" valign="top" width="8.4991500849915%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.12568743125688%" headers="mcps1.1.6.1.5 "><p>flex容器是单行还是多行显示，该值暂不支持动态修改。可选项有：</p>
<ul><li>nowrap：不换行，单行显示。</li><li>wrap：换行，多行显示。</li></ul>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p>justify-content</p>
</td>
<td class="cellrowborder" valign="top" width="12.218778122187782%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.03869613038696%" headers="mcps1.1.6.1.3 "><p>flex-start</p>
</td>
<td class="cellrowborder" valign="top" width="8.4991500849915%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.12568743125688%" headers="mcps1.1.6.1.5 "><p>flex容器当前行的主轴对齐格式。可选项有：</p>
<ul><li>flex-start：项目位于容器的开头。</li><li>flex-end：项目位于容器的结尾。</li><li>center：项目位于容器的中心。</li><li>space-between：项目位于各行之间留有空白的容器内。</li><li>space-around：项目位于各行之前、之间、之后都留有空白的容器内。</li></ul>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p>align-items</p>
</td>
<td class="cellrowborder" valign="top" width="12.218778122187782%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.03869613038696%" headers="mcps1.1.6.1.3 "><p>stretch</p>
</td>
<td class="cellrowborder" valign="top" width="8.4991500849915%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.12568743125688%" headers="mcps1.1.6.1.5 "><p>flex容器当前行的交叉轴对齐格式，可选值为：</p>
<ul><li>stretch：弹性元素被在交叉轴方向被拉伸到与容器相同的高度或宽度。</li><li>flex-start：元素向交叉轴起点对齐。</li><li>flex-end：元素向交叉轴终点对齐。</li><li>center：元素在交叉轴居中。</li></ul>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p>align-content</p>
</td>
<td class="cellrowborder" valign="top" width="12.218778122187782%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.03869613038696%" headers="mcps1.1.6.1.3 "><p>flex-start</p>
</td>
<td class="cellrowborder" valign="top" width="8.4991500849915%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.12568743125688%" headers="mcps1.1.6.1.5 "><p>交叉轴中有额外的空间时，多行内容对齐格式，可选值为：</p>
<ul><li>flex-start：所有行从交叉轴起点开始填充。第一行的交叉轴起点边和容器的交叉轴起点边对齐。接下来的每一行紧跟前一行。</li><li>flex-end：所有行从交叉轴末尾开始填充。最后一行的交叉轴终点和容器的交叉轴终点对齐。同时所有后续行与前一个对齐。</li><li>center：所有行朝向容器的中心填充。每行互相紧挨，相对于容器居中对齐。容器的交叉轴起点边和第一行的距离相等于容器的交叉轴终点边和最后一行的距离。</li><li>space-between：所有行在容器中平均分布。相邻两行间距相等。容器的交叉轴起点边和终点边分别与第一行和最后一行的边对齐。</li><li>space-around：所有行在容器中平均分布，相邻两行间距相等。容器的交叉轴起点边和终点边分别与第一行和最后一行的距离是相邻两行间距的一半。</li></ul>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p>display</p>
</td>
<td class="cellrowborder" valign="top" width="12.218778122187782%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.03869613038696%" headers="mcps1.1.6.1.3 "><p>flex</p>
</td>
<td class="cellrowborder" valign="top" width="8.4991500849915%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.12568743125688%" headers="mcps1.1.6.1.5 "><p>确定该元素视图框的类型，该值暂不支持动态修改。可选值为：</p>
<ul><li>flex：弹性布局</li><li>grid：网格布局</li><li>none：不渲染此元素</li></ul>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p>grid-template-[columns|rows]</p>
</td>
<td class="cellrowborder" valign="top" width="12.218778122187782%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.03869613038696%" headers="mcps1.1.6.1.3 "><p>1行1列</p>
</td>
<td class="cellrowborder" valign="top" width="8.4991500849915%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.12568743125688%" headers="mcps1.1.6.1.5 "><p>用于设置当前网格布局行和列的数量，不设置时默认1行1列，仅当display为grid时生效。</p>
<p>示例：如设置grid-template-columns为：</p>
<p>(1) 50px 100px 60px：分三列，第一列50px，第二列100px，第三列60px；</p>
<p>(2) 1fr 1fr 2fr：分三列，将父组件允许的宽分为4等份，第一列占1份，第二列占一份，第三列占2份；</p>
<p>(3) 30% 20% 50%：分三列，将父组件允许的宽为基准，第一列占30%，第二列占20%，第三列占50%；</p>
<p>(4) repeat(2,100px)：分两列，第一列100px，第二列100px；</p>
<p>(5) auto 1fr 1fr：分三列，第一列自适应内部子组件所需宽度，剩余空间分为两等份，第二列占一份，第三列占一份。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p>grid-[columns|rows]-gap</p>
</td>
<td class="cellrowborder" valign="top" width="12.218778122187782%" headers="mcps1.1.6.1.2 "><p>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.03869613038696%" headers="mcps1.1.6.1.3 "><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="8.4991500849915%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.12568743125688%" headers="mcps1.1.6.1.5 "><p>用于设置行与行的间距或者列与列的间距，也可以支持通过grid-gap设置相同的行列间距，仅当display为grid时生效。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p>grid-row-[start|end]</p>
</td>
<td class="cellrowborder" valign="top" width="12.218778122187782%" headers="mcps1.1.6.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="13.03869613038696%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.4991500849915%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.12568743125688%" headers="mcps1.1.6.1.5 "><p>用于设置当前元素在网格布局中的起止行号，仅当父组件display样式为grid时生效（仅div支持display样式设置为grid）。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p>grid-column-[start|end]</p>
</td>
<td class="cellrowborder" valign="top" width="12.218778122187782%" headers="mcps1.1.6.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="13.03869613038696%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.4991500849915%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.12568743125688%" headers="mcps1.1.6.1.5 "><p>用于设置当前元素在网格布局中的起止列号，仅当父组件display样式为grid时生效（仅div支持display样式设置为grid）。</p>
</td>
</tr>
</tbody>
</table>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>不支持宽度相关样式。

## 事件<a name="section94351031102113"></a>

支持[通用事件](js-components-common-events.md)。

## 方法<a name="section2279124532420"></a>

支持[通用方法](js-components-common-methods.md)。

## 示例<a name="section2021865273710"></a>

```
<!-- index.hml -->
<div class="container">
  <grid-container id="mygrid" columns="5" gutter="20px" style="background-color: pink;">
    <grid-row style="height:400px;justify-content:space-around;">
      <grid-col span="2">
        <div style="align-items: center;justify-content: center;height: 100%;width: 100%;">
          <text style="color: dodgerblue;" onclick="getCol">Element text</text>
        </div>
      </grid-col>
      <grid-col span="3" style="background-color:orange;">
        <div style="width: 100%;height: 100%;padding: 20px;align-items: center;">
          <text onclick="getColWidth">Element text</text>
        </div>
      </grid-col>
    </grid-row>
  </grid-container>
</div>
```

```
/* index.css */
.container {
  flex-direction: column;
  padding-top: 80px;
}
```

```
// index.js
import prompt from '@system.prompt';
export default {
  getCol(e) {
    this.$element('mygrid').getColumns(function (result) {
      prompt.showToast({
        message: e.target.id + ' result = ' + result,
        duration: 3000,
      });
    })
  },
  getColWidth(e) {
    this.$element('mygrid').getColumnWidth(function (result) {
      prompt.showToast({
        message: e.target.id + ' result = ' + result,
        duration: 3000,
      });
    })
  }
}
```

![](figures/grid.gif)

