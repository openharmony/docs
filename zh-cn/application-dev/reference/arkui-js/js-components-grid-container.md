# grid-container<a name="ZH-CN_TOPIC_0000001173324617"></a>

栅格布局容器根节点，使用grid-row与grid-col进行栅格布局。

## 权限列表<a name="section11257113618419"></a>

无

## 子组件<a name="section9288143101012"></a>

仅支持<grid-row\>。

## 属性<a name="section5248929161316"></a>

除支持[通用属性](js-components-common-attributes.md)外，还支持如下属性：

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="10.48%" id="mcps1.1.6.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.6.1.4"><p>必填</p>
</th>
<th class="cellrowborder" valign="top" width="35.76%" id="mcps1.1.6.1.5"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>columns</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p>string | number</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p>auto</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p>设置当前布局总列数，使用string类型时仅支持auto，配置为auto时按照当前的sizetype决定总列数：</p>
<ul><li>xs：2列</li><li>sm：4列</li><li>md：8列</li><li>lg：12列</li></ul>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>sizetype</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p>auto</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p>设置当前栅格使用的响应尺寸类型，支持xs, sm, md, lg类型，使用auto时按照当前容器大小自动选择xs, sm, md, lg类型。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>gutter</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p>24px</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p>设置Gutter宽度</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>gridtemplate<sup><span>6+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p>default</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p>当设置了columns和sizetype属性为auto时，可以设置栅格容器的布局模板，通过布局模块设置不同响应尺寸下的Columns、Gutters和Margins，详见<a href="#table135645386317">可选值说明</a>。</p>
</td>
</tr>
</tbody>
</table>

**表 1**  gridtemplate可选值说明<sup>6+</sup>

<a name="table135645386317"></a>
<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="11.52769446110778%" id="mcps1.2.7.1.1">&nbsp;&nbsp;</th>
<th class="cellrowborder" valign="top" width="14.487102579484104%" id="mcps1.2.7.1.2"><p>模板值</p>
</th>
<th class="cellrowborder" valign="top" width="18.49630073985203%" id="mcps1.2.7.1.3"><p>可响应的<strong>栅格断点系统</strong></p>
</th>
<th class="cellrowborder" valign="top" width="18.49630073985203%" id="mcps1.2.7.1.4"><p>Columns</p>
</th>
<th class="cellrowborder" valign="top" width="18.49630073985203%" id="mcps1.2.7.1.5"><p>Margins(px)</p>
</th>
<th class="cellrowborder" valign="top" width="18.49630073985203%" id="mcps1.2.7.1.6"><p>Gutters(px)</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" rowspan="4" valign="top" width="11.52769446110778%" headers="mcps1.2.7.1.1 "><p>默认栅格</p>
</td>
<td class="cellrowborder" rowspan="4" valign="top" width="14.487102579484104%" headers="mcps1.2.7.1.2 "><p>default</p>
</td>
<td class="cellrowborder" valign="top" width="18.49630073985203%" headers="mcps1.2.7.1.3 "><p>xs</p>
</td>
<td class="cellrowborder" valign="top" width="18.49630073985203%" headers="mcps1.2.7.1.4 "><p>2</p>
</td>
<td class="cellrowborder" valign="top" width="18.49630073985203%" headers="mcps1.2.7.1.5 "><p>12</p>
</td>
<td class="cellrowborder" valign="top" width="18.49630073985203%" headers="mcps1.2.7.1.6 "><p>12</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" headers="mcps1.2.7.1.1 "><p>sm</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.2 "><p>4</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.3 "><p>24</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.4 "><p>24</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" headers="mcps1.2.7.1.1 "><p>md</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.2 "><p>8</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.3 "><p>32</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.4 "><p>24</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" headers="mcps1.2.7.1.1 "><p>lg</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.2 "><p>12</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.3 "><p>48</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.4 "><p>24</p>
</td>
</tr>
<tr><td class="cellrowborder" rowspan="3" valign="top" width="11.52769446110778%" headers="mcps1.2.7.1.1 "><p>宫格布局栅格</p>
</td>
<td class="cellrowborder" rowspan="3" valign="top" width="14.487102579484104%" headers="mcps1.2.7.1.2 "><p>grid</p>
</td>
<td class="cellrowborder" valign="top" width="18.49630073985203%" headers="mcps1.2.7.1.3 "><p>sm(0&lt;设备水平分辨率&lt;600px)</p>
</td>
<td class="cellrowborder" valign="top" width="18.49630073985203%" headers="mcps1.2.7.1.4 "><p>4</p>
</td>
<td class="cellrowborder" valign="top" width="18.49630073985203%" headers="mcps1.2.7.1.5 "><p>24</p>
</td>
<td class="cellrowborder" valign="top" width="18.49630073985203%" headers="mcps1.2.7.1.6 "><p>12</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" headers="mcps1.2.7.1.1 "><p>md</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.2 "><p>8</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.3 "><p>32</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.4 "><p>12</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" headers="mcps1.2.7.1.1 "><p>lg</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.2 "><p>12</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.3 "><p>48</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.4 "><p>12</p>
</td>
</tr>
</tbody>
</table>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>-   本章中px单位是在js标签中配置了autoDesignWidth为true。<sup>6+</sup>

## 样式<a name="section16690243163414"></a>

除支持[通用样式](js-components-common-styles.md)外，还支持如下样式：

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="23.11768823117688%" id="mcps1.1.6.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="12.80871912808719%" id="mcps1.1.6.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="13.498650134986503%" id="mcps1.1.6.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.56924307569243%" id="mcps1.1.6.1.4"><p>必填</p>
</th>
<th class="cellrowborder" valign="top" width="43.00569943005699%" id="mcps1.1.6.1.5"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p>justify-content</p>
</td>
<td class="cellrowborder" valign="top" width="12.80871912808719%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.498650134986503%" headers="mcps1.1.6.1.3 "><p>flex-start</p>
</td>
<td class="cellrowborder" valign="top" width="7.56924307569243%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.00569943005699%" headers="mcps1.1.6.1.5 "><p>flex容器当前行的主轴对齐格式。可选项有：</p>
<ul><li>flex-start：项目位于容器的开头。</li><li>flex-end：项目位于容器的结尾。</li><li>center：项目位于容器的中心。</li><li>space-between：项目位于各行之间留有空白的容器内。</li><li>space-around：项目位于各行之前、之间、之后都留有空白的容器内。</li></ul>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p>align-items</p>
</td>
<td class="cellrowborder" valign="top" width="12.80871912808719%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.498650134986503%" headers="mcps1.1.6.1.3 "><p>stretch</p>
</td>
<td class="cellrowborder" valign="top" width="7.56924307569243%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.00569943005699%" headers="mcps1.1.6.1.5 "><p>flex容器当前行的交叉轴对齐格式，可选值为：</p>
<ul><li>stretch：弹性元素被在交叉轴方向被拉伸到与容器相同的高度或宽度。</li><li>flex-start：元素向交叉轴起点对齐。</li><li>flex-end：元素向交叉轴终点对齐。</li><li>center：元素在交叉轴居中。</li></ul>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p>align-content</p>
</td>
<td class="cellrowborder" valign="top" width="12.80871912808719%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.498650134986503%" headers="mcps1.1.6.1.3 "><p>flex-start</p>
</td>
<td class="cellrowborder" valign="top" width="7.56924307569243%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.00569943005699%" headers="mcps1.1.6.1.5 "><p>交叉轴中有额外的空间时，多行内容对齐格式，可选值为：</p>
<ul><li>flex-start：所有行从交叉轴起点开始填充。第一行的交叉轴起点边和容器的交叉轴起点边对齐。接下来的每一行紧跟前一行。</li><li>flex-end：所有行从交叉轴末尾开始填充。最后一行的交叉轴终点和容器的交叉轴终点对齐。同时所有后续行与前一个对齐。</li><li>center：所有行朝向容器的中心填充。每行互相紧挨，相对于容器居中对齐。容器的交叉轴起点边和第一行的距离相等于容器的交叉轴终点边和最后一行的距离。</li><li>space-between：所有行在容器中平均分布。相邻两行间距相等。容器的交叉轴起点边和终点边分别与第一行和最后一行的边对齐。</li><li>space-around：所有行在容器中平均分布，相邻两行间距相等。容器的交叉轴起点边和终点边分别与第一行和最后一行的距离是相邻两行间距的一半。</li></ul>
</td>
</tr>
</tbody>
</table>

## 事件<a name="section291933813509"></a>

支持[通用事件](js-components-common-events.md)。

## 方法<a name="section13156101584913"></a>

除支持[通用方法](js-components-common-methods.md)外，还支持如下方法：

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="23%" id="mcps1.1.4.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="32%" id="mcps1.1.4.1.2"><p>参数</p>
</th>
<th class="cellrowborder" valign="top" width="45%" id="mcps1.1.4.1.3"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="23%" headers="mcps1.1.4.1.1 "><p>getColumns</p>
</td>
<td class="cellrowborder" valign="top" width="32%" headers="mcps1.1.4.1.2 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="45%" headers="mcps1.1.4.1.3 "><p>返回栅格容器列数</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23%" headers="mcps1.1.4.1.1 "><p>getColumnWidth</p>
</td>
<td class="cellrowborder" valign="top" width="32%" headers="mcps1.1.4.1.2 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="45%" headers="mcps1.1.4.1.3 "><p>返回栅格容器column宽度</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23%" headers="mcps1.1.4.1.1 "><p>getGutterWidth</p>
</td>
<td class="cellrowborder" valign="top" width="32%" headers="mcps1.1.4.1.2 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="45%" headers="mcps1.1.4.1.3 "><p>返回栅格容器gutter宽度</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23%" headers="mcps1.1.4.1.1 "><p>getSizeType</p>
</td>
<td class="cellrowborder" valign="top" width="32%" headers="mcps1.1.4.1.2 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="45%" headers="mcps1.1.4.1.3 "><p>返回当前容器响应尺寸类型（xs|sm|md|lg）</p>
</td>
</tr>
</tbody>
</table>

## 示例<a name="section132671420142616"></a>

详见[grid-col示例](js-components-grid-col.md#section2021865273710)。

