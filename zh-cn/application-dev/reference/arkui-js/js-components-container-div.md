# div<a name="ZH-CN_TOPIC_0000001127125106"></a>

基础容器，用作页面结构的根节点或将内容进行分组。

## 权限列表<a name="section11257113618419"></a>

无

## 子组件<a name="section9288143101012"></a>

支持。

## 属性<a name="section2907183951110"></a>

支持[通用属性](js-components-common-attributes.md)。

## 样式<a name="section10683162023215"></a>

除支持[组件通用样式](js-components-common-styles.md)外，还支持如下样式：

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="21.18788121187881%" id="mcps1.1.6.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="16.648335166483353%" id="mcps1.1.6.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="13.618638136186382%" id="mcps1.1.6.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.329267073292671%" id="mcps1.1.6.1.4"><p>必填</p>
</th>
<th class="cellrowborder" valign="top" width="41.21587841215879%" id="mcps1.1.6.1.5"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="21.18788121187881%" headers="mcps1.1.6.1.1 "><p>flex-direction</p>
</td>
<td class="cellrowborder" valign="top" width="16.648335166483353%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.618638136186382%" headers="mcps1.1.6.1.3 "><p>row</p>
</td>
<td class="cellrowborder" valign="top" width="7.329267073292671%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="41.21587841215879%" headers="mcps1.1.6.1.5 "><p>flex容器主轴方向。可选项有：</p>
<ul><li>column：垂直方向从上到下。</li><li>row：水平方向从左到右。</li></ul>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="21.18788121187881%" headers="mcps1.1.6.1.1 "><p>flex-wrap</p>
</td>
<td class="cellrowborder" valign="top" width="16.648335166483353%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.618638136186382%" headers="mcps1.1.6.1.3 "><p>nowrap</p>
</td>
<td class="cellrowborder" valign="top" width="7.329267073292671%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="41.21587841215879%" headers="mcps1.1.6.1.5 "><p>flex容器是单行还是多行显示，该值暂不支持动态修改。可选项有：</p>
<ul><li>nowrap：不换行，单行显示。</li><li>wrap：换行，多行显示。</li></ul>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="21.18788121187881%" headers="mcps1.1.6.1.1 "><p>justify-content</p>
</td>
<td class="cellrowborder" valign="top" width="16.648335166483353%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.618638136186382%" headers="mcps1.1.6.1.3 "><p>flex-start</p>
</td>
<td class="cellrowborder" valign="top" width="7.329267073292671%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="41.21587841215879%" headers="mcps1.1.6.1.5 "><p>flex容器当前行的主轴对齐格式。可选项有：</p>
<ul><li>flex-start：项目位于容器的开头。</li><li>flex-end：项目位于容器的结尾。</li><li>center：项目位于容器的中心。</li><li>space-between：项目位于各行之间留有空白的容器内。</li><li>space-around：项目位于各行之前、之间、之后都留有空白的容器内。</li><li>space-evenly<sup><span>5+</span></sup>:  均匀排列每个元素，每个元素之间的间隔相等。</li></ul>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="21.18788121187881%" headers="mcps1.1.6.1.1 "><p>align-items</p>
</td>
<td class="cellrowborder" valign="top" width="16.648335166483353%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.618638136186382%" headers="mcps1.1.6.1.3 "><p>stretch</p>
</td>
<td class="cellrowborder" valign="top" width="7.329267073292671%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="41.21587841215879%" headers="mcps1.1.6.1.5 "><p>flex容器当前行的交叉轴对齐格式，可选值为：</p>
<ul><li>stretch：弹性元素在交叉轴方向被拉伸到与容器相同的高度或宽度。</li><li>flex-start：元素向交叉轴起点对齐。</li><li>flex-end：元素向交叉轴终点对齐。</li><li>center：元素在交叉轴居中。</li></ul>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="21.18788121187881%" headers="mcps1.1.6.1.1 "><p>align-content</p>
</td>
<td class="cellrowborder" valign="top" width="16.648335166483353%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.618638136186382%" headers="mcps1.1.6.1.3 "><p>flex-start</p>
</td>
<td class="cellrowborder" valign="top" width="7.329267073292671%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="41.21587841215879%" headers="mcps1.1.6.1.5 "><p>交叉轴中有额外的空间时，多行内容对齐格式，可选值为：</p>
<ul><li>flex-start：所有行从交叉轴起点开始填充。第一行的交叉轴起点边和容器的交叉轴起点边对齐。接下来的每一行紧跟前一行。</li><li>flex-end：所有行从交叉轴末尾开始填充。最后一行的交叉轴终点和容器的交叉轴终点对齐。同时所有后续行与前一个对齐。</li><li>center：所有行朝向容器的中心填充。每行互相紧挨，相对于容器居中对齐。容器的交叉轴起点边和第一行的距离相等于容器的交叉轴终点边和最后一行的距离。</li><li>space-between：所有行在容器中平均分布。相邻两行间距相等。容器的交叉轴起点边和终点边分别与第一行和最后一行的边对齐。</li><li>space-around：所有行在容器中平均分布，相邻两行间距相等。容器的交叉轴起点边和终点边分别与第一行和最后一行的距离是相邻两行间距的一半。</li></ul>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="21.18788121187881%" headers="mcps1.1.6.1.1 "><p>display</p>
</td>
<td class="cellrowborder" valign="top" width="16.648335166483353%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.618638136186382%" headers="mcps1.1.6.1.3 "><p>flex</p>
</td>
<td class="cellrowborder" valign="top" width="7.329267073292671%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="41.21587841215879%" headers="mcps1.1.6.1.5 "><p>确定该元素视图框的类型，该值暂不支持动态修改。可选值为：</p>
<ul><li>flex：弹性布局</li><li>grid：网格布局</li><li>none：不渲染此元素</li></ul>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="21.18788121187881%" headers="mcps1.1.6.1.1 "><p>grid-template-[columns|rows]</p>
</td>
<td class="cellrowborder" valign="top" width="16.648335166483353%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.618638136186382%" headers="mcps1.1.6.1.3 "><p>1行1列</p>
</td>
<td class="cellrowborder" valign="top" width="7.329267073292671%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="41.21587841215879%" headers="mcps1.1.6.1.5 "><p>用于设置当前网格布局行和列的数量，不设置时默认1行1列，仅当display为grid时生效。</p>
<p>示例：如设置grid-template-columns为：</p>
<ul><li>50px 100px 60px：分三列，第一列50px，第二列100px，第三列60px；</li><li>1fr 1fr 2fr：分三列，将父组件允许的宽分为4等份，第一列占1份，第二列占一份，第三列占2份；</li><li>30% 20% 50%：分三列，将父组件允许的宽为基准，第一列占30%，第二列占20%，第三列占50%；</li><li>repeat(2,100px)：分两列，第一列100px，第二列100px；</li><li>repeat(auto-fill,100px)<sup>5+</sup>：按照每列100px的大小和交叉轴大小计算最大正整数重复次数，按照该重复次数布满交叉轴；</li><li>auto 1fr 1fr：分三列，第一列自适应内部子组件所需宽度，剩余空间分为两等份，第二列占一份，第三列占一份。</li></ul>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="21.18788121187881%" headers="mcps1.1.6.1.1 "><p>grid-[columns|rows]-gap</p>
</td>
<td class="cellrowborder" valign="top" width="16.648335166483353%" headers="mcps1.1.6.1.2 "><p>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.618638136186382%" headers="mcps1.1.6.1.3 "><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.329267073292671%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="41.21587841215879%" headers="mcps1.1.6.1.5 "><p>用于设置行与行的间距或者列与列的间距，也可以支持通过grid-gap设置相同的行列间距，仅当display为grid时生效。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="21.18788121187881%" headers="mcps1.1.6.1.1 "><p>grid-row-[start|end]</p>
</td>
<td class="cellrowborder" valign="top" width="16.648335166483353%" headers="mcps1.1.6.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="13.618638136186382%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.329267073292671%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="41.21587841215879%" headers="mcps1.1.6.1.5 "><p>用于设置当前元素在网格布局中的起止行号，仅当父组件display样式为grid时生效（仅div支持display样式设置为grid）。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="21.18788121187881%" headers="mcps1.1.6.1.1 "><p>grid-column-[start|end]</p>
</td>
<td class="cellrowborder" valign="top" width="16.648335166483353%" headers="mcps1.1.6.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="13.618638136186382%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.329267073292671%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="41.21587841215879%" headers="mcps1.1.6.1.5 "><p>用于设置当前元素在网格布局中的起止列号，仅当父组件display样式为grid时生效（仅div支持display样式设置为grid）。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="21.18788121187881%" headers="mcps1.1.6.1.1 "><p>grid-auto-flow<sup>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="16.648335166483353%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.618638136186382%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.329267073292671%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="41.21587841215879%" headers="mcps1.1.6.1.5 "><p>使用框架自动布局算法进行网格的布局，可选值为：</p>
<ul><li>row：逐行填充元素，如果行空间不够，则新增行；</li><li>column：逐列填充元素，如果列空间不够，则新增列。</li></ul>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="21.18788121187881%" headers="mcps1.1.6.1.1 "><p>overflow<sup>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="16.648335166483353%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.618638136186382%" headers="mcps1.1.6.1.3 "><p>visible</p>
</td>
<td class="cellrowborder" valign="top" width="7.329267073292671%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="41.21587841215879%" headers="mcps1.1.6.1.5 "><p>设置元素内容区超过元素本身大小时的表现形式。</p>
<ul><li>visible：多个子元素内容超过元素大小时，显示在元素外面；</li><li>hidden：元素内容超过元素大小时，进行裁切显示；</li><li>scroll：元素内容超过元素大小时，进行滚动显示并展示滚动条（当前只支持纵向）。</li></ul>
<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><ul><li>overflow: scroll样式需要元素设置固定的大小。</li></ul>
</div></div>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="21.18788121187881%" headers="mcps1.1.6.1.1 "><p>align-items<sup><span>6+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="16.648335166483353%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.618638136186382%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.329267073292671%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="41.21587841215879%" headers="mcps1.1.6.1.5 "><p>设置容器中元素交叉轴上的对齐方式：</p>
<ul><li>stretch：Flex容器内容在交叉轴方向被拉伸到与容器相同的高度或宽度；</li><li>flex-start：Flex布局容器内元素向交叉轴起点对齐；</li><li>flex-end：Flex布局容器内元素向交叉轴终点对齐；</li><li>center：Flex布局容器内元素在交叉轴居中对齐；</li><li>baseline：如Flex布局纵向排列，则该值与'flex-start'等效。横向布局时，内容元素存在文本时按照文本基线对齐，否则底部对齐。</li></ul>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="21.18788121187881%" headers="mcps1.1.6.1.1 "><p>scrollbar-color<sup>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="16.648335166483353%" headers="mcps1.1.6.1.2 "><p>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.618638136186382%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.329267073292671%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="41.21587841215879%" headers="mcps1.1.6.1.5 "><p>设置滚动条的颜色。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="21.18788121187881%" headers="mcps1.1.6.1.1 "><p>scrollbar-width<sup>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="16.648335166483353%" headers="mcps1.1.6.1.2 "><p>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.618638136186382%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.329267073292671%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="41.21587841215879%" headers="mcps1.1.6.1.5 "><p>设置滚动条的宽度。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="21.18788121187881%" headers="mcps1.1.6.1.1 "><p>overscroll-effect<sup>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="16.648335166483353%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.618638136186382%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.329267073292671%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="41.21587841215879%" headers="mcps1.1.6.1.5 "><p>设置滚动边缘效果，可选值为：</p>
<ul><li>spring：弹性物理动效，滑动到边缘后可以根据初始速度或通过触摸事件继续滑动一段距离，松手后回弹；</li><li>fade：渐隐物理动效，滑动到边缘后展示一个波浪形的渐隐，根据速度和滑动距离的变化渐隐也会发送一定的变化；</li><li>none：滑动到边缘后无效果</li></ul>
</td>
</tr>
</tbody>
</table>

## 事件<a name="section77341431152917"></a>

除支持[通用事件](js-components-common-events.md)外，还支持如下事件：

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="16.18%" id="mcps1.1.4.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="21.89%" id="mcps1.1.4.1.2"><p>参数</p>
</th>
<th class="cellrowborder" valign="top" width="61.92999999999999%" id="mcps1.1.4.1.3"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="16.18%" headers="mcps1.1.4.1.1 "><p>reachstart<sup><span>6+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="21.89%" headers="mcps1.1.4.1.2 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="61.92999999999999%" headers="mcps1.1.4.1.3 "><p>当页面滑动到最开始的点时触发的事件回调，当flex-direction: row时才会触发。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="16.18%" headers="mcps1.1.4.1.1 "><p>reachend<sup>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="21.89%" headers="mcps1.1.4.1.2 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="61.92999999999999%" headers="mcps1.1.4.1.3 "><p>当页面滑动到最末尾的点时触发的事件回调，当flex-direction: row时才会触发。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="16.18%" headers="mcps1.1.4.1.1 "><p>reachtop<sup>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="21.89%" headers="mcps1.1.4.1.2 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="61.92999999999999%" headers="mcps1.1.4.1.3 "><p>当页面滑动到最上部的点时触发的事件回调，当flex-direction: column时才会触发。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="16.18%" headers="mcps1.1.4.1.1 "><p>reachbottom<sup>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="21.89%" headers="mcps1.1.4.1.2 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="61.92999999999999%" headers="mcps1.1.4.1.3 "><p>当页面滑动到最下部的点时触发的事件回调，当flex-direction: column时才会触发。</p>
</td>
</tr>
</tbody>
</table>

## 方法<a name="section2279124532420"></a>

除支持[通用方法](js-components-common-methods.md)外，还支持如下方法：

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="17.07%" id="mcps1.1.5.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="11.84%" id="mcps1.1.5.1.2"><p>参数</p>
</th>
<th class="cellrowborder" valign="top" width="13.66%" id="mcps1.1.5.1.3"><p>返回值</p>
</th>
<th class="cellrowborder" valign="top" width="57.43000000000001%" id="mcps1.1.5.1.4"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="17.07%" headers="mcps1.1.5.1.1 "><p>getScrollOffset<sup><span>6+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="11.84%" headers="mcps1.1.5.1.2 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="13.66%" headers="mcps1.1.5.1.3 "><p><a href="#table154011838131719">ScrollOffset</a></p>
</td>
<td class="cellrowborder" valign="top" width="57.43000000000001%" headers="mcps1.1.5.1.4 "><p>获取元素内容的滚动偏移。</p>
<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><ul><li>需要设置overflow样式为scroll，默认滚动方向与容器方向一致。</li></ul>
</div></div>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="17.07%" headers="mcps1.1.5.1.1 "><p>scrollBy<sup><span>6+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="11.84%" headers="mcps1.1.5.1.2 "><p><a href="#table1139175871819">ScrollParam</a></p>
</td>
<td class="cellrowborder" valign="top" width="13.66%" headers="mcps1.1.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="57.43000000000001%" headers="mcps1.1.5.1.4 "><p>指定元素内容的滚动偏移。</p>
<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><ul><li>需要设置overflow样式为scroll。</li></ul>
</div></div>
</td>
</tr>
</tbody>
</table>

**表 1**  ScrollOffset<sup>6+</sup>

<a name="table154011838131719"></a>
<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p>x</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p>在x轴方向的偏移，单位为px。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p>y</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p>在y轴方向的偏移，单位为px。</p>
</td>
</tr>
</tbody>
</table>

**表 2**  ScrollParam<sup>6+</sup>

<a name="table1139175871819"></a>
<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p>dx</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p>水平方向滑动的偏移量，单位px。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p>dy</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p>垂直方向滑动的偏移量，单位px。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p>smooth</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p>是否平滑处理。</p>
</td>
</tr>
</tbody>
</table>

## 示例<a name="section1241545010391"></a>

1.  Flex样式

    ```
    <!-- xxx.hml -->
    <div class="container">
      <div class="flex-box">
        <div class="flex-item color-primary"></div>
        <div class="flex-item color-warning"></div>
        <div class="flex-item color-success"></div>
      </div>
    </div>
    ```

    ```
    /* xxx.css */
    .container {
      flex-direction: column;
      justify-content: center;
      align-items: center;
      width: 454px;
      height: 454px;
    }
    .flex-box {
      justify-content: space-around;
      align-items: center;
      width: 400px;
      height: 140px;
      background-color: #ffffff;
    }
    .flex-item {
      width: 120px;
      height: 120px;
      border-radius: 16px;
    }
    .color-primary {
      background-color: #007dff;
    }
    .color-warning {
      background-color: #ff7500;
    }
    .color-success {
      background-color: #41ba41;
    }
    ```

    ![](figures/zh-cn_image_0000001127285076.png)

2.  Flex Wrap样式

    ```
    <!-- xxx.hml -->
    <div class="container">
      <div class="flex-box">
        <div class="flex-item color-primary"></div>
        <div class="flex-item color-warning"></div>
        <div class="flex-item color-success"></div>
      </div>
    </div>
    ```

    ```
    /* xxx.css */
    .container {
      flex-direction: column;
      justify-content: center;
      align-items: center;
      width: 454px;
      height: 454px;
    }
    .flex-box {
      justify-content: space-around;
      align-items: center;
      flex-wrap: wrap;
      width: 300px;
      height: 250px;
      background-color: #ffffff;
    }
    .flex-item {
      width: 120px;
      height: 120px;
      border-radius: 16px;
    }
    .color-primary {
      background-color: #007dff;
    }
    .color-warning {
      background-color: #ff7500;
    }
    .color-success {
      background-color: #41ba41;
    }
    ```

    ![](figures/22.png)

3.  Grid样式

    ```
    <!-- xxx.hml -->
    <div class="common grid-parent">
      <div class="grid-child grid-left-top"></div>
      <div class="grid-child grid-left-bottom"></div>
      <div class="grid-child grid-right-top"></div>
      <div class="grid-child grid-right-bottom"></div>
    </div>
    ```

    ```
    /* xxx.css */
    .common {
      width: 400px;
      height: 400px;
      background-color: #ffffff;
      align-items: center;
      justify-content: center;
      margin: 24px;
    }
    .grid-parent {
      display: grid;
      grid-template-columns: 35% 35%;
      grid-columns-gap: 24px;
      grid-rows-gap: 24px;
      grid-template-rows: 35% 35%;
    }
    .grid-child {
      width: 100%;
      height: 100%;
      border-radius: 8px;
    }
    .grid-left-top {
      grid-row-start: 0;
      grid-column-start: 0;
      grid-row-end: 0;
      grid-column-end: 0;
      background-color: #3f56ea;
    }
    .grid-left-bottom {
      grid-row-start: 1;
      grid-column-start: 0;
      grid-row-end: 1;
      grid-column-end: 0;
      background-color: #00aaee;
    }
    .grid-right-top {
      grid-row-start: 0;
      grid-column-start: 1;
      grid-row-end: 0;
      grid-column-end: 1;
      background-color: #00bfc9;
    }
    .grid-right-bottom {
      grid-row-start: 1;
      grid-column-start: 1;
      grid-row-end: 1;
      grid-column-end: 1;
      background-color: #47cc47;
    }
    ```

    ![](figures/11.png)

4.  拖拽<sup>7+</sup>

    ```
    <!-- xxx.hml -->
    <div class="container">
      <div class="content" ondragstart="dragstart" ondrag="drag" ondragend="dragend" style="position: absolute;left: {{left}};top:{{top}};">
      </div>
    </div>
    ```

    ```
    /* xxx.css */
    .container {
      flex-direction: column;
    }
    .content{
      width: 200px;
      height: 200px;
      background-color: red;
    }
    ```

    ```
    // xxx.js
    import prompt from '@system.prompt';
    export default {
      data:{
        left:0,
        top:0,
      },
      dragstart(e){
        prompt.showToast({
          message: 'Start to be dragged'
        })
      },
      drag(e){
        this.left = e.globalX;
        this.top = e.globalY;
      },
      dragend(e){
        prompt.showToast({
          message: 'End Drag'
        })
       },
    }
    ```

    ![](figures/9.gif)

    ```
    <!-- xxx.hml -->
    <div class="container">
      <div class="content" ondrag="drag" style="position: absolute;left: {{left}};top: {{top}};"></div>
      <div style="width: 500px; height: 500px; background-color: yellow; position: fixed; left: 15%; top: 30%; opacity:0.3"
        ondragenter="dragenter" ondragover="dragover" ondragleave="dragleave" ondrop="drop">
      </div>
    </div>
    ```

    ```
    /* xxx.css */
    .container {
      flex-direction: column;
      width: 100%;
      position: relative;
      max-width: 100%;
    }
    .content{
      width: 200px;
      height: 200px;
      background-color: red;
      position: absolute;
    }
    ```

    ```
    // xxx.js
    import prompt from '@system.prompt';
    export default {
      data:{
        left:0,
        top:0,
      },
      drag(e){
        this.left = e.globalX;
        this.top = e.globalY;
      },
      dragenter(e){
        prompt.showToast({
          message: 'enter'
        })
      },
      dragover(e){
        prompt.showToast({
          message: 'over'
        })
      },
      dragleave(e){
        prompt.showToast({
          message: 'leave'
        })
      },
      drop(e){
        prompt.showToast({
          message: 'drop'
        })
      }
    }
    ```

    ![](figures/6.gif)

5.  手指捏合<sup>7+</sup>

    ```
    <!-- xxx.hml -->
    <div class="container">
      <div class="content "onpinchstart="pinchstart" onpinchend="pinchend" onpinchupdate="pinchupdate"
        onpinchcancel=" pinchcancel"> 
      </div>
    </div>
    ```

    ```
    /* xxx.css */
    .container {
      flex-direction: column;
      justify-content: center;
      align-items: center;
      width: 454px;
      height: 454px;}
    .content{
      width: 400px;
      height: 400px;
      background-color: aqua;
      margin:30px
    }
    ```

    ```
    // xxx.js
    import prompt from '@system.prompt';
    export default {
      pinchstart(e){
        prompt.showToast({
          message: 'pinchstart!!!'
        })
      },
      pinchupdate(e){
        prompt.showToast({
          message: 'Two-finger pinch update'
        })
      },
      pinchend(e){
        prompt.showToast({
          message: 'Finished with two fingers pinching'
        })
      },
      pinchcancel(e){
        prompt.showToast({
          message: 'Finger pinching is interrupted'
        })
      }
    }
    ```

    ![](figures/5.gif)


