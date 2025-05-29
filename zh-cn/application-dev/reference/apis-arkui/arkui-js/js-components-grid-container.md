# grid-container

>  **说明：**
> 从API version 5开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

栅格布局容器根节点，使用grid-row与grid-col进行栅格布局。

## 权限列表

无


## 子组件

仅支持&lt;grid-row&gt;。


## 属性

除支持[通用属性](js-components-common-attributes.md)外，还支持如下属性：

| 名称 | 类型 | 默认值 | 必填 | 描述 |
| -------- | -------- | -------- | -------- | -------- |
| columns | string&nbsp;\|&nbsp;number | auto | 否 | 设置当前布局总列数，使用string类型时仅支持auto，配置为auto时按照当前的sizetype决定总列数：<br/>-&nbsp;xs：2列。<br/>-&nbsp;sm：4列。<br/>-&nbsp;md：8列。<br/>-&nbsp;lg：12列。 |
| sizetype | string | auto | 否 | 设置当前栅格使用的响应尺寸类型，支持xs,&nbsp;sm,&nbsp;md,&nbsp;lg类型，使用auto时按照当前容器大小自动选择xs,&nbsp;sm,&nbsp;md,&nbsp;lg类型。 |
| gutter | &lt;length&gt; | 24px | 否 | 设置Gutter宽度。 |
| gridtemplate<sup>6+</sup> | string | default | 否 | 当设置了columns和sizetype属性为auto时，可以设置栅格容器的布局模板，通过布局模块设置不同响应尺寸下的Columns、Gutters和Margins，详见表 gridtemplate可选值说明。 |

**表1** gridtemplate可选值说明<sup>6+</sup>

|  | 模板值 | 可响应的**栅格断点系统** | Columns | Margins(px) | Gutters(px) |
| -------- | -------- | -------- | -------- | -------- | -------- |
| 默认栅格 | default | xs | 2 | 12 | 12 |
|              |         | sm                               | 4       | 24          | 24          |
|              |         | md                               | 8       | 32          | 24          |
|              |         | lg                               | 12      |48|24|
| 宫格布局栅格 | grid | sm(0&lt;设备水平分辨率&lt;600px) | 4 | 24 | 12 |
|              |         | md                               | 8       |32|12|
|              |         | lg                               | 12      |48|12|

>  **说明：**
>
> 本章中px单位是在js标签中配置了autoDesignWidth为true。<sup>6+</sup>


## 样式

除支持[通用样式](js-components-common-styles.md)外，还支持如下样式：

| 名称 | 类型 | 默认值 | 必填 | 描述 |
| -------- | -------- | -------- | -------- | -------- |
| justify-content | string | flex-start | 否 | flex容器当前行的主轴对齐格式，可选项有：<br/>-&nbsp;flex-start：项目位于容器的开头。<br/>-&nbsp;flex-end：项目位于容器的结尾。<br/>-&nbsp;center：项目位于容器的中心。<br/>-&nbsp;space-between：项目位于各行之间留有空白的容器内。<br/>-&nbsp;space-around：项目位于各行之前、之间、之后都留有空白的容器内。 |
| align-items | string | stretch | 否 | flex容器当前行的交叉轴对齐格式，可选值为：<br/>-&nbsp;stretch：弹性元素被在交叉轴方向被拉伸到与容器相同的高度或宽度。<br/>-&nbsp;flex-start：元素向交叉轴起点对齐。<br/>-&nbsp;flex-end：元素向交叉轴终点对齐。<br/>-&nbsp;center：元素在交叉轴居中。 |
| align-content | string | flex-start | 否 | 交叉轴中有额外的空间时，多行内容对齐格式，可选值为：<br/>-&nbsp;flex-start：所有行从交叉轴起点开始填充。第一行的交叉轴起点边和容器的交叉轴起点边对齐。接下来的每一行紧跟前一行。<br/>-&nbsp;flex-end：所有行从交叉轴末尾开始填充。最后一行的交叉轴终点和容器的交叉轴终点对齐。同时所有后续行与前一个对齐。<br/>-&nbsp;center：所有行朝向容器的中心填充。每行互相紧挨，相对于容器居中对齐。容器的交叉轴起点边和第一行的距离相等于容器的交叉轴终点边和最后一行的距离。<br/>-&nbsp;space-between：所有行在容器中平均分布。相邻两行间距相等。容器的交叉轴起点边和终点边分别与第一行和最后一行的边对齐。<br/>-&nbsp;space-around：所有行在容器中平均分布，相邻两行间距相等。容器的交叉轴起点边和终点边分别与第一行和最后一行的距离是相邻两行间距的一半。 |


## 事件

支持[通用事件](js-components-common-events.md)。


## 方法

除支持[通用方法](js-components-common-methods.md)外，还支持如下方法：

| 名称 | 参数 | 描述 |
| -------- | -------- | -------- |
| getColumns | - | 返回栅格容器列数。 |
| getColumnWidth | - | 返回栅格容器column宽度。 |
| getGutterWidth | - | 返回栅格容器gutter宽度。 |
| getSizeType | - | 返回当前容器响应尺寸类型（xs\|sm\|md\|lg）。 |


## 示例

详见[grid-col示例](js-components-grid-col.md#示例)。
