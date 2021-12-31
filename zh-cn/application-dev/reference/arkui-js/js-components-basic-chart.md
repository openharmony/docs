# chart<a name="ZH-CN_TOPIC_0000001127125088"></a>

图表组件，用于呈现线形图、柱状图、量规图界面。

## 权限列表<a name="section11257113618419"></a>

无

## 子组件<a name="section9288143101012"></a>

不支持。

## 属性<a name="section2907183951110"></a>

除支持[通用属性](js-components-common-attributes.md)外，还支持如下属性：

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="19.56%" id="mcps1.1.6.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="13.62%" id="mcps1.1.6.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="10.72%" id="mcps1.1.6.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="8.43%" id="mcps1.1.6.1.4"><p>必填</p>
</th>
<th class="cellrowborder" valign="top" width="47.67%" id="mcps1.1.6.1.5"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="19.56%" headers="mcps1.1.6.1.1 "><p>type</p>
</td>
<td class="cellrowborder" valign="top" width="13.62%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.72%" headers="mcps1.1.6.1.3 "><p>line</p>
</td>
<td class="cellrowborder" valign="top" width="8.43%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.67%" headers="mcps1.1.6.1.5 "><p>设置图表类型（不支持动态修改），可选项有：</p>
<ul><li>bar：柱状图。</li><li>line：线形图。</li><li>gauge：量规图。</li><li>progress<sup><span>5+</span></sup>：进度类圆形图表。</li><li>loading<sup><span>5+</span></sup>：加载类圆形图表。</li><li>rainbow<sup><span>5+</span></sup>：占比类圆形图表。</li></ul>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="19.56%" headers="mcps1.1.6.1.1 "><p>options</p>
</td>
<td class="cellrowborder" valign="top" width="13.62%" headers="mcps1.1.6.1.2 "><p><a href="#table12775365017">ChartOptions</a></p>
</td>
<td class="cellrowborder" valign="top" width="10.72%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.43%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.67%" headers="mcps1.1.6.1.5 "><p>图表参数设置，柱状图和线形图必须设置参数设置，量规图不生效。可以设置x轴、y轴的最小值、最大值、刻度数、是否显示，线条宽度、是否平滑等。（不支持动态修改）</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="19.56%" headers="mcps1.1.6.1.1 "><p>datasets</p>
</td>
<td class="cellrowborder" valign="top" width="13.62%" headers="mcps1.1.6.1.2 "><p>Array&lt;<a href="#table13810518157">ChartDataset</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.72%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.43%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.67%" headers="mcps1.1.6.1.5 "><p>数据集合，柱状图和线形图必须设置数据集合，量规图不生效。可以设置多条数据集及其背景色。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="19.56%" headers="mcps1.1.6.1.1 "><p>segments<sup><span>5+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="13.62%" headers="mcps1.1.6.1.2 "><p><a href="#table2596183616210">DataSegment</a> | Array&lt;<a href="#table2596183616210">DataSegment</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.72%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.43%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.67%" headers="mcps1.1.6.1.5 "><p>进度类、加载类和占比类圆形图表使用的数据结构。</p>
<p>DataSegment针对进度类和加载类圆形图表使用，</p>
<p>Array&lt;<a href="#table2596183616210">DataSegment</a>&gt;针对占比类图标使用，DataSegment最多9个。</p>
<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>仅手机和平板设备支持。</p>
</div></div>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="19.56%" headers="mcps1.1.6.1.1 "><p>effects<sup>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="13.62%" headers="mcps1.1.6.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.72%" headers="mcps1.1.6.1.3 "><p>true</p>
</td>
<td class="cellrowborder" valign="top" width="8.43%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.67%" headers="mcps1.1.6.1.5 "><p>是否开启占比类、进度类圆形图表特效。</p>
<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>仅手机和平板设备支持。</p>
</div></div>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="19.56%" headers="mcps1.1.6.1.1 "><p>animationduration<sup>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="13.62%" headers="mcps1.1.6.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.72%" headers="mcps1.1.6.1.3 "><p>3000</p>
</td>
<td class="cellrowborder" valign="top" width="8.43%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.67%" headers="mcps1.1.6.1.5 "><p>设置占比类圆形图表展开动画时长，单位为ms。</p>
<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>仅手机和平板设备支持。</p>
</div></div>
</td>
</tr>
</tbody>
</table>

**表 1**  ChartOptions

<a name="table12775365017"></a>
<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="16.3%" id="mcps1.2.6.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="11.24%" id="mcps1.2.6.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="8.690000000000001%" id="mcps1.2.6.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.7299999999999995%" id="mcps1.2.6.1.4"><p>必填</p>
</th>
<th class="cellrowborder" valign="top" width="56.04%" id="mcps1.2.6.1.5"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="16.3%" headers="mcps1.2.6.1.1 "><p>xAxis</p>
</td>
<td class="cellrowborder" valign="top" width="11.24%" headers="mcps1.2.6.1.2 "><p><a href="#table11312112919528">ChartAxis</a></p>
</td>
<td class="cellrowborder" valign="top" width="8.690000000000001%" headers="mcps1.2.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.7299999999999995%" headers="mcps1.2.6.1.4 "><p>是</p>
</td>
<td class="cellrowborder" valign="top" width="56.04%" headers="mcps1.2.6.1.5 "><p>x轴参数设置。可以设置x轴最小值、最大值、刻度数以及是否显示。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="16.3%" headers="mcps1.2.6.1.1 "><p>yAxis</p>
</td>
<td class="cellrowborder" valign="top" width="11.24%" headers="mcps1.2.6.1.2 "><p><a href="#table11312112919528">ChartAxis</a></p>
</td>
<td class="cellrowborder" valign="top" width="8.690000000000001%" headers="mcps1.2.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.7299999999999995%" headers="mcps1.2.6.1.4 "><p>是</p>
</td>
<td class="cellrowborder" valign="top" width="56.04%" headers="mcps1.2.6.1.5 "><p>y轴参数设置。可以设置y轴最小值、最大值、刻度数以及是否显示。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="16.3%" headers="mcps1.2.6.1.1 "><p>series</p>
</td>
<td class="cellrowborder" valign="top" width="11.24%" headers="mcps1.2.6.1.2 "><p><a href="#table029562010560">ChartSeries</a></p>
</td>
<td class="cellrowborder" valign="top" width="8.690000000000001%" headers="mcps1.2.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.7299999999999995%" headers="mcps1.2.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="56.04%" headers="mcps1.2.6.1.5 "><p>数据序列参数设置。可以设置1）线的样式，如线宽、是否平滑；2）设置线最前端位置白点的样式和大小。</p>
<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>仅线形图支持。</p>
</div></div>
</td>
</tr>
</tbody>
</table>

**表 2**  ChartDataset

<a name="table13810518157"></a>
<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="16.56%" id="mcps1.2.6.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="16.830000000000002%" id="mcps1.2.6.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="12.989999999999998%" id="mcps1.2.6.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="9.33%" id="mcps1.2.6.1.4"><p>必填</p>
</th>
<th class="cellrowborder" valign="top" width="44.29%" id="mcps1.2.6.1.5"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="16.56%" headers="mcps1.2.6.1.1 "><p>strokeColor</p>
</td>
<td class="cellrowborder" valign="top" width="16.830000000000002%" headers="mcps1.2.6.1.2 "><p>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="12.989999999999998%" headers="mcps1.2.6.1.3 "><p>#ff6384</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.2.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="44.29%" headers="mcps1.2.6.1.5 "><p>线条颜色。</p>
<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>仅线形图支持。</p>
</div></div>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="16.56%" headers="mcps1.2.6.1.1 "><p>fillColor</p>
</td>
<td class="cellrowborder" valign="top" width="16.830000000000002%" headers="mcps1.2.6.1.2 "><p>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="12.989999999999998%" headers="mcps1.2.6.1.3 "><p>#ff6384</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.2.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="44.29%" headers="mcps1.2.6.1.5 "><p>填充颜色。线形图表示填充的渐变颜色。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="16.56%" headers="mcps1.2.6.1.1 "><p>data</p>
</td>
<td class="cellrowborder" valign="top" width="16.830000000000002%" headers="mcps1.2.6.1.2 "><p>Array&lt;number&gt; | Array&lt;<a href="#table1470733752019">Point</a>&gt;<sup>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="12.989999999999998%" headers="mcps1.2.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.2.6.1.4 "><p>是</p>
</td>
<td class="cellrowborder" valign="top" width="44.29%" headers="mcps1.2.6.1.5 "><p>设置绘制线或柱中的点集。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="16.56%" headers="mcps1.2.6.1.1 "><p>gradient</p>
</td>
<td class="cellrowborder" valign="top" width="16.830000000000002%" headers="mcps1.2.6.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="12.989999999999998%" headers="mcps1.2.6.1.3 "><p>false</p>
</td>
<td class="cellrowborder" valign="top" width="9.33%" headers="mcps1.2.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="44.29%" headers="mcps1.2.6.1.5 "><p>设置是否显示填充渐变颜色。</p>
<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>仅线形图支持。</p>
</div></div>
</td>
</tr>
</tbody>
</table>

**表 3**  ChartAxis

<a name="table11312112919528"></a>
<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="10.18%" id="mcps1.2.6.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="12.91%" id="mcps1.2.6.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="11.75%" id="mcps1.2.6.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="10.059999999999999%" id="mcps1.2.6.1.4"><p>必填</p>
</th>
<th class="cellrowborder" valign="top" width="55.1%" id="mcps1.2.6.1.5"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="10.18%" headers="mcps1.2.6.1.1 "><p>min</p>
</td>
<td class="cellrowborder" valign="top" width="12.91%" headers="mcps1.2.6.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.75%" headers="mcps1.2.6.1.3 "><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="10.059999999999999%" headers="mcps1.2.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="55.1%" headers="mcps1.2.6.1.5 "><p>轴的最小值。</p>
<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>仅线形图支持负数。</p>
</div></div>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="10.18%" headers="mcps1.2.6.1.1 "><p>max</p>
</td>
<td class="cellrowborder" valign="top" width="12.91%" headers="mcps1.2.6.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.75%" headers="mcps1.2.6.1.3 "><p>100</p>
</td>
<td class="cellrowborder" valign="top" width="10.059999999999999%" headers="mcps1.2.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="55.1%" headers="mcps1.2.6.1.5 "><p>轴的最大值。</p>
<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>仅线形图支持负数。</p>
</div></div>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="10.18%" headers="mcps1.2.6.1.1 "><p>axisTick</p>
</td>
<td class="cellrowborder" valign="top" width="12.91%" headers="mcps1.2.6.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.75%" headers="mcps1.2.6.1.3 "><p>10</p>
</td>
<td class="cellrowborder" valign="top" width="10.059999999999999%" headers="mcps1.2.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="55.1%" headers="mcps1.2.6.1.5 "><p>轴显示的刻度数量。</p>
<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>仅支持1~20，且具体显示的效果与如下计算值有关（图的宽度所占的像素/（max-min））。</p>
<p>在柱状图中，每组数据显示的柱子数量与刻度数量一致，且柱子显示在刻度处。</p>
</div></div>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="10.18%" headers="mcps1.2.6.1.1 "><p>display</p>
</td>
<td class="cellrowborder" valign="top" width="12.91%" headers="mcps1.2.6.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="11.75%" headers="mcps1.2.6.1.3 "><p>false</p>
</td>
<td class="cellrowborder" valign="top" width="10.059999999999999%" headers="mcps1.2.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="55.1%" headers="mcps1.2.6.1.5 "><p>是否显示轴。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="10.18%" headers="mcps1.2.6.1.1 "><p>color</p>
</td>
<td class="cellrowborder" valign="top" width="12.91%" headers="mcps1.2.6.1.2 "><p>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="11.75%" headers="mcps1.2.6.1.3 "><p>#c0c0c0</p>
</td>
<td class="cellrowborder" valign="top" width="10.059999999999999%" headers="mcps1.2.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="55.1%" headers="mcps1.2.6.1.5 "><p>轴颜色。</p>
</td>
</tr>
</tbody>
</table>

**表 4**  ChartSeries

<a name="table029562010560"></a>
<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="17%" id="mcps1.2.6.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="16.39%" id="mcps1.2.6.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="12.82%" id="mcps1.2.6.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="10.11%" id="mcps1.2.6.1.4"><p>必填</p>
</th>
<th class="cellrowborder" valign="top" width="43.68%" id="mcps1.2.6.1.5"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="17%" headers="mcps1.2.6.1.1 "><p>lineStyle</p>
</td>
<td class="cellrowborder" valign="top" width="16.39%" headers="mcps1.2.6.1.2 "><p><a href="#table7790183513918">ChartLineStyle</a></p>
</td>
<td class="cellrowborder" valign="top" width="12.82%" headers="mcps1.2.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="10.11%" headers="mcps1.2.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.68%" headers="mcps1.2.6.1.5 "><p>线样式设置，如线宽、是否平滑。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="17%" headers="mcps1.2.6.1.1 "><p>headPoint</p>
</td>
<td class="cellrowborder" valign="top" width="16.39%" headers="mcps1.2.6.1.2 "><p><a href="#table1435760101317">PointStyle</a></p>
</td>
<td class="cellrowborder" valign="top" width="12.82%" headers="mcps1.2.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="10.11%" headers="mcps1.2.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.68%" headers="mcps1.2.6.1.5 "><p>线最前端位置白点的样式和大小。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="17%" headers="mcps1.2.6.1.1 "><p>topPoint</p>
</td>
<td class="cellrowborder" valign="top" width="16.39%" headers="mcps1.2.6.1.2 "><p><a href="#table1435760101317">PointStyle</a></p>
</td>
<td class="cellrowborder" valign="top" width="12.82%" headers="mcps1.2.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="10.11%" headers="mcps1.2.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.68%" headers="mcps1.2.6.1.5 "><p>最高点的样式和大小。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="17%" headers="mcps1.2.6.1.1 "><p>bottomPoint</p>
</td>
<td class="cellrowborder" valign="top" width="16.39%" headers="mcps1.2.6.1.2 "><p><a href="#table1435760101317">PointStyle</a></p>
</td>
<td class="cellrowborder" valign="top" width="12.82%" headers="mcps1.2.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="10.11%" headers="mcps1.2.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.68%" headers="mcps1.2.6.1.5 "><p>最低点的样式和大小。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="17%" headers="mcps1.2.6.1.1 "><p>loop</p>
</td>
<td class="cellrowborder" valign="top" width="16.39%" headers="mcps1.2.6.1.2 "><p><a href="#table13982347173714">ChartLoop</a></p>
</td>
<td class="cellrowborder" valign="top" width="12.82%" headers="mcps1.2.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="10.11%" headers="mcps1.2.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.68%" headers="mcps1.2.6.1.5 "><p>设置屏幕显示满时，是否需要重头开始绘制。</p>
</td>
</tr>
</tbody>
</table>

**表 5**  ChartLineStyle

<a name="table7790183513918"></a>
<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="17.09%" id="mcps1.2.6.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="16.91%" id="mcps1.2.6.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="12.690000000000001%" id="mcps1.2.6.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="10.24%" id="mcps1.2.6.1.4"><p>必填</p>
</th>
<th class="cellrowborder" valign="top" width="43.07%" id="mcps1.2.6.1.5"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="17.09%" headers="mcps1.2.6.1.1 "><p>width</p>
</td>
<td class="cellrowborder" valign="top" width="16.91%" headers="mcps1.2.6.1.2 "><p>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="12.690000000000001%" headers="mcps1.2.6.1.3 "><p>1px</p>
</td>
<td class="cellrowborder" valign="top" width="10.24%" headers="mcps1.2.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.07%" headers="mcps1.2.6.1.5 "><p>线宽设置。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="17.09%" headers="mcps1.2.6.1.1 "><p>smooth</p>
</td>
<td class="cellrowborder" valign="top" width="16.91%" headers="mcps1.2.6.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="12.690000000000001%" headers="mcps1.2.6.1.3 "><p>false</p>
</td>
<td class="cellrowborder" valign="top" width="10.24%" headers="mcps1.2.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="43.07%" headers="mcps1.2.6.1.5 "><p>是否平滑。</p>
</td>
</tr>
</tbody>
</table>

**表 6**  PointStyle

<a name="table1435760101317"></a>
<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="17.09%" id="mcps1.2.6.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="17.09%" id="mcps1.2.6.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="12.64%" id="mcps1.2.6.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="10.549999999999999%" id="mcps1.2.6.1.4"><p>必填</p>
</th>
<th class="cellrowborder" valign="top" width="42.63%" id="mcps1.2.6.1.5"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="17.09%" headers="mcps1.2.6.1.1 "><p>shape</p>
</td>
<td class="cellrowborder" valign="top" width="17.09%" headers="mcps1.2.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="12.64%" headers="mcps1.2.6.1.3 "><p>circle</p>
</td>
<td class="cellrowborder" valign="top" width="10.549999999999999%" headers="mcps1.2.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="42.63%" headers="mcps1.2.6.1.5 "><p>高亮点的形状。可选值为：</p>
<ul><li>circle：圆形。</li><li>square：方形。</li><li>triangle：三角形。</li></ul>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="17.09%" headers="mcps1.2.6.1.1 "><p>size</p>
</td>
<td class="cellrowborder" valign="top" width="17.09%" headers="mcps1.2.6.1.2 "><p>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="12.64%" headers="mcps1.2.6.1.3 "><p>5px</p>
</td>
<td class="cellrowborder" valign="top" width="10.549999999999999%" headers="mcps1.2.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="42.63%" headers="mcps1.2.6.1.5 "><p>高亮点的大小。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="17.09%" headers="mcps1.2.6.1.1 "><p>strokeWidth</p>
</td>
<td class="cellrowborder" valign="top" width="17.09%" headers="mcps1.2.6.1.2 "><p>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="12.64%" headers="mcps1.2.6.1.3 "><p>1px</p>
</td>
<td class="cellrowborder" valign="top" width="10.549999999999999%" headers="mcps1.2.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="42.63%" headers="mcps1.2.6.1.5 "><p>边框宽度</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="17.09%" headers="mcps1.2.6.1.1 "><p>strokeColor</p>
</td>
<td class="cellrowborder" valign="top" width="17.09%" headers="mcps1.2.6.1.2 "><p>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="12.64%" headers="mcps1.2.6.1.3 "><p>#ff0000</p>
</td>
<td class="cellrowborder" valign="top" width="10.549999999999999%" headers="mcps1.2.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="42.63%" headers="mcps1.2.6.1.5 "><p>边框颜色。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="17.09%" headers="mcps1.2.6.1.1 "><p>fillColor</p>
</td>
<td class="cellrowborder" valign="top" width="17.09%" headers="mcps1.2.6.1.2 "><p>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="12.64%" headers="mcps1.2.6.1.3 "><p>#ff0000</p>
</td>
<td class="cellrowborder" valign="top" width="10.549999999999999%" headers="mcps1.2.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="42.63%" headers="mcps1.2.6.1.5 "><p>填充颜色。</p>
</td>
</tr>
</tbody>
</table>

**表 7**  ChartLoop

<a name="table13982347173714"></a>
<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="11.85%" id="mcps1.2.6.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="12.030000000000001%" id="mcps1.2.6.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="9.83%" id="mcps1.2.6.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="9.04%" id="mcps1.2.6.1.4"><p>必填</p>
</th>
<th class="cellrowborder" valign="top" width="57.25%" id="mcps1.2.6.1.5"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.2.6.1.1 "><p>margin</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.2.6.1.2 "><p>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="9.83%" headers="mcps1.2.6.1.3 "><p>1</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.2.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="57.25%" headers="mcps1.2.6.1.5 "><p>擦除点的个数（最新绘制的点与最老的点之间的横向距离）。注意：轻量设备margin和topPoint/bottomPoint/headPoint同时使用时，有概率出现point正好位于擦除区域的情况，导致point不可见，因此不建议同时使用。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.2.6.1.1 "><p>gradient</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.2.6.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="9.83%" headers="mcps1.2.6.1.3 "><p>false</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.2.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="57.25%" headers="mcps1.2.6.1.5 "><p>是否需要渐变擦除。</p>
</td>
</tr>
</tbody>
</table>

**表 8**  Point<sup>5+</sup>

<a name="table1470733752019"></a>
<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="11.85%" id="mcps1.2.6.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="12.030000000000001%" id="mcps1.2.6.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="9.83%" id="mcps1.2.6.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="9.04%" id="mcps1.2.6.1.4"><p>必填</p>
</th>
<th class="cellrowborder" valign="top" width="57.25%" id="mcps1.2.6.1.5"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.2.6.1.1 "><p>value</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.2.6.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="9.83%" headers="mcps1.2.6.1.3 "><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.2.6.1.4 "><p>是</p>
</td>
<td class="cellrowborder" valign="top" width="57.25%" headers="mcps1.2.6.1.5 "><p>表示绘制点的Y轴坐标。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.2.6.1.1 "><p>pointStyle</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.2.6.1.2 "><p><a href="#table1435760101317">PointStyle</a></p>
</td>
<td class="cellrowborder" valign="top" width="9.83%" headers="mcps1.2.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.2.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="57.25%" headers="mcps1.2.6.1.5 "><p>表示当前数据点的绘制样式。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.2.6.1.1 "><p>description</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.2.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.83%" headers="mcps1.2.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.2.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="57.25%" headers="mcps1.2.6.1.5 "><p>表示当前点的注释内容。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.2.6.1.1 "><p>textLocation</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.2.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.83%" headers="mcps1.2.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.2.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="57.25%" headers="mcps1.2.6.1.5 "><p>可选值为top，bottom，none。分别表示注释的绘制位置位于点的上方，下方，以及不绘制。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.2.6.1.1 "><p>textColor</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.2.6.1.2 "><p>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="9.83%" headers="mcps1.2.6.1.3 "><p>#000000</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.2.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="57.25%" headers="mcps1.2.6.1.5 "><p>表示注释文字的颜色。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.2.6.1.1 "><p>lineDash</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.2.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.83%" headers="mcps1.2.6.1.3 "><p>solid</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.2.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="57.25%" headers="mcps1.2.6.1.5 "><p>表示绘制当前线段虚线的样式。“dashed， 5， 5”表示纯虚线，绘制5px的实线后留5px的空白。“solid”表示绘制实线。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.2.6.1.1 "><p>lineColor</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.2.6.1.2 "><p>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="9.83%" headers="mcps1.2.6.1.3 "><p>#000000</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.2.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="57.25%" headers="mcps1.2.6.1.5 "><p>表示绘制当前线段的颜色。此颜色不设置会默认使用整体的strokeColor。</p>
</td>
</tr>
</tbody>
</table>

**表 9**  DataSegment<sup>5+</sup>

<a name="table2596183616210"></a>
<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="11.85%" id="mcps1.2.6.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="12.030000000000001%" id="mcps1.2.6.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="9.83%" id="mcps1.2.6.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="9.04%" id="mcps1.2.6.1.4"><p>必填</p>
</th>
<th class="cellrowborder" valign="top" width="57.25%" id="mcps1.2.6.1.5"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.2.6.1.1 "><p>startColor</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.2.6.1.2 "><p>Color</p>
</td>
<td class="cellrowborder" valign="top" width="9.83%" headers="mcps1.2.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.2.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="57.25%" headers="mcps1.2.6.1.5 "><p>起始位置的颜色，设置startColor必须设置endColor。不设置startColor时，会使用系统默认预置的颜色数组，具体颜色值见下表。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.2.6.1.1 "><p>endColor</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.2.6.1.2 "><p>Color</p>
</td>
<td class="cellrowborder" valign="top" width="9.83%" headers="mcps1.2.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.2.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="57.25%" headers="mcps1.2.6.1.5 "><p>终止位置的颜色，设置endColor必须设置startColor。</p>
<p>不设置startColor时，会使用系统默认预置的颜色数组。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.2.6.1.1 "><p>value</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.2.6.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="9.83%" headers="mcps1.2.6.1.3 "><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.2.6.1.4 "><p>是</p>
</td>
<td class="cellrowborder" valign="top" width="57.25%" headers="mcps1.2.6.1.5 "><p>占比数据的所占份额，最大100。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.2.6.1.1 "><p>name</p>
</td>
<td class="cellrowborder" valign="top" width="12.030000000000001%" headers="mcps1.2.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.83%" headers="mcps1.2.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.2.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="57.25%" headers="mcps1.2.6.1.5 "><p>此类数据的名称。</p>
</td>
</tr>
</tbody>
</table>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="5.8205820582058205%" id="mcps1.1.4.1.1"><p>数据组</p>
</th>
<th class="cellrowborder" valign="top" width="41.7941794179418%" id="mcps1.1.4.1.2"><p>浅色主题</p>
</th>
<th class="cellrowborder" valign="top" width="52.38523852385239%" id="mcps1.1.4.1.3"><p>深色主题</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="5.8205820582058205%" headers="mcps1.1.4.1.1 "><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="41.7941794179418%" headers="mcps1.1.4.1.2 "><p>起始颜色：#f7ce00，结束颜色：#f99b11</p>
</td>
<td class="cellrowborder" valign="top" width="52.38523852385239%" headers="mcps1.1.4.1.3 "><p>起始颜色：#d1a738，结束颜色：#eb933d</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="5.8205820582058205%" headers="mcps1.1.4.1.1 "><p>1</p>
</td>
<td class="cellrowborder" valign="top" width="41.7941794179418%" headers="mcps1.1.4.1.2 "><p>起始颜色：#f76223，结束颜色：#f2400a</p>
</td>
<td class="cellrowborder" valign="top" width="52.38523852385239%" headers="mcps1.1.4.1.3 "><p>起始颜色：#e67d50，结束颜色：#d9542b</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="5.8205820582058205%" headers="mcps1.1.4.1.1 "><p>2</p>
</td>
<td class="cellrowborder" valign="top" width="41.7941794179418%" headers="mcps1.1.4.1.2 "><p>起始颜色：#f772ac，结束颜色：#e65392</p>
</td>
<td class="cellrowborder" valign="top" width="52.38523852385239%" headers="mcps1.1.4.1.3 "><p>起始颜色：#d5749e，结束颜色：#d6568d</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="5.8205820582058205%" headers="mcps1.1.4.1.1 "><p>3</p>
</td>
<td class="cellrowborder" valign="top" width="41.7941794179418%" headers="mcps1.1.4.1.2 "><p>起始颜色：#a575eb，结束颜色：#a12df7</p>
</td>
<td class="cellrowborder" valign="top" width="52.38523852385239%" headers="mcps1.1.4.1.3 "><p>起始颜色：#9973d1，结束颜色：#5552d9</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="5.8205820582058205%" headers="mcps1.1.4.1.1 "><p>4</p>
</td>
<td class="cellrowborder" valign="top" width="41.7941794179418%" headers="mcps1.1.4.1.2 "><p>起始颜色：#7b79f7，结束颜色：#4b48f7</p>
</td>
<td class="cellrowborder" valign="top" width="52.38523852385239%" headers="mcps1.1.4.1.3 "><p>起始颜色：#7977d9，结束颜色：#f99b11</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="5.8205820582058205%" headers="mcps1.1.4.1.1 "><p>5</p>
</td>
<td class="cellrowborder" valign="top" width="41.7941794179418%" headers="mcps1.1.4.1.2 "><p>起始颜色：#4b8af3，结束颜色：#007dff</p>
</td>
<td class="cellrowborder" valign="top" width="52.38523852385239%" headers="mcps1.1.4.1.3 "><p>起始颜色：#4c81d9，结束颜色：#217bd9</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="5.8205820582058205%" headers="mcps1.1.4.1.1 "><p>6</p>
</td>
<td class="cellrowborder" valign="top" width="41.7941794179418%" headers="mcps1.1.4.1.2 "><p>起始颜色：#73c1e6，结束颜色：#4fb4e3</p>
</td>
<td class="cellrowborder" valign="top" width="52.38523852385239%" headers="mcps1.1.4.1.3 "><p>起始颜色：#5ea6d1，结束颜色：#4895c2</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="5.8205820582058205%" headers="mcps1.1.4.1.1 "><p>7</p>
</td>
<td class="cellrowborder" valign="top" width="41.7941794179418%" headers="mcps1.1.4.1.2 "><p>起始颜色：#a5d61d，结束颜色：#69d14f</p>
</td>
<td class="cellrowborder" valign="top" width="52.38523852385239%" headers="mcps1.1.4.1.3 "><p>起始颜色：#91c23a，结束颜色：#70ba5d</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="5.8205820582058205%" headers="mcps1.1.4.1.1 "><p>8</p>
</td>
<td class="cellrowborder" valign="top" width="41.7941794179418%" headers="mcps1.1.4.1.2 "><p>起始颜色：#a2a2b0，结束颜色：#8e8e93</p>
</td>
<td class="cellrowborder" valign="top" width="52.38523852385239%" headers="mcps1.1.4.1.3 "><p>起始颜色：#8c8c99，结束颜色：#6b6b76</p>
</td>
</tr>
</tbody>
</table>

当类型为量规图时，还支持如下属性：

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="23.52%" id="mcps1.1.6.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="11.76%" id="mcps1.1.6.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="11.72%" id="mcps1.1.6.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="8%" id="mcps1.1.6.1.4"><p>必填</p>
</th>
<th class="cellrowborder" valign="top" width="45%" id="mcps1.1.6.1.5"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="23.52%" headers="mcps1.1.6.1.1 "><p>percent</p>
</td>
<td class="cellrowborder" valign="top" width="11.76%" headers="mcps1.1.6.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.72%" headers="mcps1.1.6.1.3 "><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="8%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="45%" headers="mcps1.1.6.1.5 "><p>当前值占整体的百分比，取值范围为0-100。</p>
</td>
</tr>
</tbody>
</table>

## 样式<a name="section5775351116"></a>

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
<tbody><tr><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p>stroke-width</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p>32px（量规）</p>
<p>24px（占比类圆形图表）</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p>量规<span>、占比类圆形图表</span>组件刻度条的宽度。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p>start-angle</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p>&lt;deg&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p>240（量规）</p>
<p>0（占比类圆形图表）</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p>量规<span>、占比类圆形图表</span>组件刻度条起始角度，以时钟0点为基线。范围为0到360。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p>total-angle</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p>&lt;deg&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p>240（量规）</p>
<p>360（占比类圆形图表）</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p>量规<span>、占比类圆形图表</span>组件刻度条总长度，范围为-360到360，负数标识起点到终点为逆时针。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p>center-x</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p>量规组件刻度条中心位置，该样式优先于通用样式的position样式。该样式需要和center-y和radius一起配置才能生效。（仅量规图支持）</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p>center-y</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p>量规组件刻度条中心位置，该样式优先于通用样式的position样式。该样式需要和center-x和radius一起配置才能生效。（仅量规图支持）</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p>radius</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p>量规组件刻度条半径，该样式优先于通用样式的width和height样式。该样式需要和center-x和center-y一起配置才能生效。（仅量规图支持）</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p>colors</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p>Array</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p>量规组件刻度条每一个区段的颜色。</p>
<p>如：colors: #ff0000, #00ff00。（仅量规图支持）</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p>weights</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p>Array</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p>量规组件刻度条每一个区段的权重。</p>
<p>如：weights: 2, 2。（仅量规图支持）</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p>font-family<sup>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p>Array</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p>表示绘制注释的字体样式，支持<a href="js-components-common-customizing-font.md">自定义字体</a>。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p>font-size<sup>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p>表示绘制注释的字体的大小。</p>
</td>
</tr>
</tbody>
</table>

## 事件<a name="section749131815264"></a>

支持[通用事件](js-components-common-events.md)。

## 方法<a name="section4480852195018"></a>

除支持[通用方法](js-components-common-methods.md)外，还支持如下方法：

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="13.881388138813882%" id="mcps1.1.4.1.1"><p>方法</p>
</th>
<th class="cellrowborder" valign="top" width="52.78527852785279%" id="mcps1.1.4.1.2"><p>参数</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.3"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="13.881388138813882%" headers="mcps1.1.4.1.1 "><p>append</p>
</td>
<td class="cellrowborder" valign="top" width="52.78527852785279%" headers="mcps1.1.4.1.2 "><p>{</p>
<p>serial: number, // 设置要更新的线形图数据下标</p>
<p>data: Array&lt;number&gt;, // 设置新增的数据</p>
<p>}</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p>往已有的数据序列中动态添加数据，根据serial指定目标序列，serial为datasets数组的下标，从0开始。注意：不会更新datasets[index].data。仅线形图支持，按横坐标加1递增（与xAxis min/max设置相关）。</p>
</td>
</tr>
</tbody>
</table>

## 示例<a name="section164885329456"></a>

1.  线形图

    ```
    <!-- xxx.hml -->
    <div class="container">
      <stack class="chart-region">
        <image class="chart-background" src="common/background.png"></image>
        <chart class="chart-data" type="line" ref="linechart" options="{{lineOps}}" datasets="{{lineData}}"></chart>
      </stack>
      <button value="Add data" onclick="addData"></button>
    </div>
    ```

    ```
    /* xxx.css */
    .container {
      flex-direction: column;
      justify-content: center;
      align-items: center;
    }
    .chart-region {
      height: 400px;
      width: 700px;
    }
    .chart-background {
      object-fit: fill;
    }
    .chart-data {
      width: 700px;
      height: 600px;
    }
    button {
      width: 100%;
      height: 50px;
      background-color: #F4F2F1;
      text-color: #0C81F3;
    }
    ```

    ```
    // xxx.js
    export default {
      data: {
        lineData: [
          {
            strokeColor: '#0081ff',
            fillColor: '#cce5ff',
            data: [763, 550, 551, 554, 731, 654, 525, 696, 595, 628, 791, 505, 613, 575, 475, 553, 491, 680, 657, 716],
            gradient: true,
          }
        ],
        lineOps: {
          xAxis: {
            min: 0,
            max: 20,
            display: false,
          },
          yAxis: {
            min: 0,
            max: 1000,
            display: false,
          },
          series: {
            lineStyle: {
              width: "5px",
              smooth: true,
            },
            headPoint: {
              shape: "circle",
              size: 20,
              strokeWidth: 5,
              fillColor: '#ffffff',
              strokeColor: '#007aff',
              display: true,
            },
            loop: {
              margin: 2,
              gradient: true,
            }
          }
        },
      },
      addData() {
        this.$refs.linechart.append({
          serial: 0,
          data: [Math.floor(Math.random() * 400) + 400]
        })
      }
    }
    ```

    ![](figures/zh-cn_image_0000001173324843.png)

2.  柱状图

    ```
    <!-- xxx.hml -->
    <div class="container">
      <stack class="data-region">
        <image class="data-background" src="common/background.png"></image>
        <chart class="data-bar" type="bar" id="bar-chart" options="{{barOps}}" datasets="{{barData}}"></chart>
      </stack>
    </div>
    ```

    ```
    /* xxx.css */
    .container {
      flex-direction: column;
      justify-content: center;
      align-items: center;
    }
    .data-region {
      height: 400px;
      width: 700px;
    }
    .data-background {
      object-fit: fill;
    }
    .data-bar {
      width: 700px;
      height: 400px;
    }
    ```

    ```
    // xxx.js
    export default {
      data: {
        barData: [
          {
            fillColor: '#f07826',
            data: [763, 550, 551, 554, 731, 654, 525, 696, 595, 628],
          },
          {
            fillColor: '#cce5ff',
            data: [535, 776, 615, 444, 694, 785, 677, 609, 562, 410],
          },
          {
            fillColor: '#ff88bb',
            data: [673, 500, 574, 483, 702, 583, 437, 506, 693, 657],
          },
        ],
        barOps: {
          xAxis: {
            min: 0,
            max: 20,
            display: false,
            axisTick: 10,
          },
          yAxis: {
            min: 0,
            max: 1000,
            display: false,
          },
        },
      }
    }
    ```

    ![](figures/barchart.png)

3.  量规图

    ```
    <!-- xxx.hml -->
    <div class="container">
      <div class="gauge-region">
        <chart class="data-gauge" type="gauge" percent = "50"></chart>
      </div>
    </div>
    ```

    ```
    /* xxx.css */
    .container {
      flex-direction: column;
      justify-content: center;
      align-items: center;
    }
    .gauge-region {
      height: 400px;
      width: 400px;
    }
    .data-gauge {
      colors: #83f115, #fd3636, #3bf8ff;
      weights: 4, 2, 1;
    }
    ```

    ![](figures/gauge.png)


