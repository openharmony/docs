# div<a name="ZH-CN_TOPIC_0000001209570693"></a>

-   [权限列表](#zh-cn_topic_0000001127125106_section11257113618419)
-   [子组件](#zh-cn_topic_0000001127125106_section9288143101012)
-   [属性](#zh-cn_topic_0000001127125106_section2907183951110)
-   [样式](#zh-cn_topic_0000001127125106_section10683162023215)
-   [事件](#zh-cn_topic_0000001127125106_section77341431152917)
-   [方法](#zh-cn_topic_0000001127125106_section2279124532420)
-   [示例](#zh-cn_topic_0000001127125106_section1241545010391)

基础容器，用作页面结构的根节点或将内容进行分组。

## 权限列表<a name="zh-cn_topic_0000001127125106_section11257113618419"></a>

无

## 子组件<a name="zh-cn_topic_0000001127125106_section9288143101012"></a>

支持。

## 属性<a name="zh-cn_topic_0000001127125106_section2907183951110"></a>

支持[通用属性](js-components-common-attributes.md#ZH-CN_TOPIC_0000001163812208)。

## 样式<a name="zh-cn_topic_0000001127125106_section10683162023215"></a>

除支持[组件通用样式](js-components-common-styles.md#ZH-CN_TOPIC_0000001163932190)外，还支持如下样式：

<a name="zh-cn_topic_0000001127125106_table268312017326"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001127125106_row1268413205327"><th class="cellrowborder" valign="top" width="21.18788121187881%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001127125106_p76841320163214"><a name="zh-cn_topic_0000001127125106_p76841320163214"></a><a name="zh-cn_topic_0000001127125106_p76841320163214"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="16.648335166483353%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001127125106_p1068492019329"><a name="zh-cn_topic_0000001127125106_p1068492019329"></a><a name="zh-cn_topic_0000001127125106_p1068492019329"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="13.618638136186382%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001127125106_p1468462043218"><a name="zh-cn_topic_0000001127125106_p1468462043218"></a><a name="zh-cn_topic_0000001127125106_p1468462043218"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.329267073292671%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001127125106_p968416201324"><a name="zh-cn_topic_0000001127125106_p968416201324"></a><a name="zh-cn_topic_0000001127125106_p968416201324"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="41.21587841215879%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001127125106_p1068412019321"><a name="zh-cn_topic_0000001127125106_p1068412019321"></a><a name="zh-cn_topic_0000001127125106_p1068412019321"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001127125106_row1768452033213"><td class="cellrowborder" valign="top" width="21.18788121187881%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125106_p1868410208328"><a name="zh-cn_topic_0000001127125106_p1868410208328"></a><a name="zh-cn_topic_0000001127125106_p1868410208328"></a>flex-direction</p>
</td>
<td class="cellrowborder" valign="top" width="16.648335166483353%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125106_p16684720193210"><a name="zh-cn_topic_0000001127125106_p16684720193210"></a><a name="zh-cn_topic_0000001127125106_p16684720193210"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.618638136186382%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125106_p168432083216"><a name="zh-cn_topic_0000001127125106_p168432083216"></a><a name="zh-cn_topic_0000001127125106_p168432083216"></a>row</p>
</td>
<td class="cellrowborder" valign="top" width="7.329267073292671%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125106_p26841120163215"><a name="zh-cn_topic_0000001127125106_p26841120163215"></a><a name="zh-cn_topic_0000001127125106_p26841120163215"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="41.21587841215879%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125106_p9684162011326"><a name="zh-cn_topic_0000001127125106_p9684162011326"></a><a name="zh-cn_topic_0000001127125106_p9684162011326"></a>flex容器主轴方向。可选项有：</p>
<a name="zh-cn_topic_0000001127125106_ul166842020123216"></a><a name="zh-cn_topic_0000001127125106_ul166842020123216"></a><ul id="zh-cn_topic_0000001127125106_ul166842020123216"><li>column：垂直方向从上到下。</li><li>row：水平方向从左到右。</li></ul>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125106_row1568472073219"><td class="cellrowborder" valign="top" width="21.18788121187881%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125106_p156841120203210"><a name="zh-cn_topic_0000001127125106_p156841120203210"></a><a name="zh-cn_topic_0000001127125106_p156841120203210"></a>flex-wrap</p>
</td>
<td class="cellrowborder" valign="top" width="16.648335166483353%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125106_p668422017329"><a name="zh-cn_topic_0000001127125106_p668422017329"></a><a name="zh-cn_topic_0000001127125106_p668422017329"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.618638136186382%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125106_p176841220203217"><a name="zh-cn_topic_0000001127125106_p176841220203217"></a><a name="zh-cn_topic_0000001127125106_p176841220203217"></a>nowrap</p>
</td>
<td class="cellrowborder" valign="top" width="7.329267073292671%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125106_p16851520143211"><a name="zh-cn_topic_0000001127125106_p16851520143211"></a><a name="zh-cn_topic_0000001127125106_p16851520143211"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="41.21587841215879%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125106_p9685102083216"><a name="zh-cn_topic_0000001127125106_p9685102083216"></a><a name="zh-cn_topic_0000001127125106_p9685102083216"></a>flex容器是单行还是多行显示，该值暂不支持动态修改。可选项有：</p>
<a name="zh-cn_topic_0000001127125106_ul2685520133215"></a><a name="zh-cn_topic_0000001127125106_ul2685520133215"></a><ul id="zh-cn_topic_0000001127125106_ul2685520133215"><li>nowrap：不换行，单行显示。</li><li>wrap：换行，多行显示。</li></ul>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125106_row56851920123213"><td class="cellrowborder" valign="top" width="21.18788121187881%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125106_p56857201320"><a name="zh-cn_topic_0000001127125106_p56857201320"></a><a name="zh-cn_topic_0000001127125106_p56857201320"></a>justify-content</p>
</td>
<td class="cellrowborder" valign="top" width="16.648335166483353%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125106_p268572015329"><a name="zh-cn_topic_0000001127125106_p268572015329"></a><a name="zh-cn_topic_0000001127125106_p268572015329"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.618638136186382%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125106_p96851220103216"><a name="zh-cn_topic_0000001127125106_p96851220103216"></a><a name="zh-cn_topic_0000001127125106_p96851220103216"></a>flex-start</p>
</td>
<td class="cellrowborder" valign="top" width="7.329267073292671%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125106_p1368522019327"><a name="zh-cn_topic_0000001127125106_p1368522019327"></a><a name="zh-cn_topic_0000001127125106_p1368522019327"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="41.21587841215879%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125106_p2685520183214"><a name="zh-cn_topic_0000001127125106_p2685520183214"></a><a name="zh-cn_topic_0000001127125106_p2685520183214"></a>flex容器当前行的主轴对齐格式。可选项有：</p>
<a name="zh-cn_topic_0000001127125106_ul10685142083220"></a><a name="zh-cn_topic_0000001127125106_ul10685142083220"></a><ul id="zh-cn_topic_0000001127125106_ul10685142083220"><li>flex-start：项目位于容器的开头。</li><li>flex-end：项目位于容器的结尾。</li><li>center：项目位于容器的中心。</li><li>space-between：项目位于各行之间留有空白的容器内。</li><li>space-around：项目位于各行之前、之间、之后都留有空白的容器内。</li><li>space-evenly<sup id="zh-cn_topic_0000001127125106_sup11685320153214"><a name="zh-cn_topic_0000001127125106_sup11685320153214"></a><a name="zh-cn_topic_0000001127125106_sup11685320153214"></a><span>5+</span></sup>:  均匀排列每个元素，每个元素之间的间隔相等。</li></ul>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125106_row1268518207327"><td class="cellrowborder" valign="top" width="21.18788121187881%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125106_p16685172073216"><a name="zh-cn_topic_0000001127125106_p16685172073216"></a><a name="zh-cn_topic_0000001127125106_p16685172073216"></a>align-items</p>
</td>
<td class="cellrowborder" valign="top" width="16.648335166483353%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125106_p14686102043215"><a name="zh-cn_topic_0000001127125106_p14686102043215"></a><a name="zh-cn_topic_0000001127125106_p14686102043215"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.618638136186382%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125106_p12686192073219"><a name="zh-cn_topic_0000001127125106_p12686192073219"></a><a name="zh-cn_topic_0000001127125106_p12686192073219"></a>stretch</p>
</td>
<td class="cellrowborder" valign="top" width="7.329267073292671%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125106_p968619206323"><a name="zh-cn_topic_0000001127125106_p968619206323"></a><a name="zh-cn_topic_0000001127125106_p968619206323"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="41.21587841215879%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125106_p968612093212"><a name="zh-cn_topic_0000001127125106_p968612093212"></a><a name="zh-cn_topic_0000001127125106_p968612093212"></a>flex容器当前行的交叉轴对齐格式，可选值为：</p>
<a name="zh-cn_topic_0000001127125106_ul1668642083219"></a><a name="zh-cn_topic_0000001127125106_ul1668642083219"></a><ul id="zh-cn_topic_0000001127125106_ul1668642083219"><li>stretch：弹性元素在交叉轴方向被拉伸到与容器相同的高度或宽度。</li><li>flex-start：元素向交叉轴起点对齐。</li><li>flex-end：元素向交叉轴终点对齐。</li><li>center：元素在交叉轴居中。</li></ul>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125106_row13686520193219"><td class="cellrowborder" valign="top" width="21.18788121187881%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125106_p18686620103213"><a name="zh-cn_topic_0000001127125106_p18686620103213"></a><a name="zh-cn_topic_0000001127125106_p18686620103213"></a>align-content</p>
</td>
<td class="cellrowborder" valign="top" width="16.648335166483353%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125106_p368682043219"><a name="zh-cn_topic_0000001127125106_p368682043219"></a><a name="zh-cn_topic_0000001127125106_p368682043219"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.618638136186382%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125106_p76864208322"><a name="zh-cn_topic_0000001127125106_p76864208322"></a><a name="zh-cn_topic_0000001127125106_p76864208322"></a>flex-start</p>
</td>
<td class="cellrowborder" valign="top" width="7.329267073292671%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125106_p17687720143219"><a name="zh-cn_topic_0000001127125106_p17687720143219"></a><a name="zh-cn_topic_0000001127125106_p17687720143219"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="41.21587841215879%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125106_p10687112023210"><a name="zh-cn_topic_0000001127125106_p10687112023210"></a><a name="zh-cn_topic_0000001127125106_p10687112023210"></a>交叉轴中有额外的空间时，多行内容对齐格式，可选值为：</p>
<a name="zh-cn_topic_0000001127125106_ul156878209329"></a><a name="zh-cn_topic_0000001127125106_ul156878209329"></a><ul id="zh-cn_topic_0000001127125106_ul156878209329"><li>flex-start：所有行从交叉轴起点开始填充。第一行的交叉轴起点边和容器的交叉轴起点边对齐。接下来的每一行紧跟前一行。</li><li>flex-end：所有行从交叉轴末尾开始填充。最后一行的交叉轴终点和容器的交叉轴终点对齐。同时所有后续行与前一个对齐。</li><li>center：所有行朝向容器的中心填充。每行互相紧挨，相对于容器居中对齐。容器的交叉轴起点边和第一行的距离相等于容器的交叉轴终点边和最后一行的距离。</li><li>space-between：所有行在容器中平均分布。相邻两行间距相等。容器的交叉轴起点边和终点边分别与第一行和最后一行的边对齐。</li><li>space-around：所有行在容器中平均分布，相邻两行间距相等。容器的交叉轴起点边和终点边分别与第一行和最后一行的距离是相邻两行间距的一半。</li></ul>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125106_row668711200324"><td class="cellrowborder" valign="top" width="21.18788121187881%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125106_p1368732083214"><a name="zh-cn_topic_0000001127125106_p1368732083214"></a><a name="zh-cn_topic_0000001127125106_p1368732083214"></a>display</p>
</td>
<td class="cellrowborder" valign="top" width="16.648335166483353%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125106_p8687320183211"><a name="zh-cn_topic_0000001127125106_p8687320183211"></a><a name="zh-cn_topic_0000001127125106_p8687320183211"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.618638136186382%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125106_p168742043213"><a name="zh-cn_topic_0000001127125106_p168742043213"></a><a name="zh-cn_topic_0000001127125106_p168742043213"></a>flex</p>
</td>
<td class="cellrowborder" valign="top" width="7.329267073292671%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125106_p36871820113217"><a name="zh-cn_topic_0000001127125106_p36871820113217"></a><a name="zh-cn_topic_0000001127125106_p36871820113217"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="41.21587841215879%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125106_p7687920123212"><a name="zh-cn_topic_0000001127125106_p7687920123212"></a><a name="zh-cn_topic_0000001127125106_p7687920123212"></a>确定该元素视图框的类型，该值暂不支持动态修改。可选值为：</p>
<a name="zh-cn_topic_0000001127125106_ul168702017322"></a><a name="zh-cn_topic_0000001127125106_ul168702017322"></a><ul id="zh-cn_topic_0000001127125106_ul168702017322"><li>flex：弹性布局</li><li>grid：网格布局</li><li>none：不渲染此元素</li></ul>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125106_row136872020123214"><td class="cellrowborder" valign="top" width="21.18788121187881%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125106_p126872208322"><a name="zh-cn_topic_0000001127125106_p126872208322"></a><a name="zh-cn_topic_0000001127125106_p126872208322"></a>grid-template-[columns|rows]</p>
</td>
<td class="cellrowborder" valign="top" width="16.648335166483353%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125106_p9687142016324"><a name="zh-cn_topic_0000001127125106_p9687142016324"></a><a name="zh-cn_topic_0000001127125106_p9687142016324"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.618638136186382%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125106_p9688112033216"><a name="zh-cn_topic_0000001127125106_p9688112033216"></a><a name="zh-cn_topic_0000001127125106_p9688112033216"></a>1行1列</p>
</td>
<td class="cellrowborder" valign="top" width="7.329267073292671%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125106_p1068812003213"><a name="zh-cn_topic_0000001127125106_p1068812003213"></a><a name="zh-cn_topic_0000001127125106_p1068812003213"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="41.21587841215879%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125106_p186883207326"><a name="zh-cn_topic_0000001127125106_p186883207326"></a><a name="zh-cn_topic_0000001127125106_p186883207326"></a>用于设置当前网格布局行和列的数量，不设置时默认1行1列，仅当display为grid时生效。</p>
<p id="zh-cn_topic_0000001127125106_p7688172013211"><a name="zh-cn_topic_0000001127125106_p7688172013211"></a><a name="zh-cn_topic_0000001127125106_p7688172013211"></a>示例：如设置grid-template-columns为：</p>
<a name="zh-cn_topic_0000001127125106_ul3688920133220"></a><a name="zh-cn_topic_0000001127125106_ul3688920133220"></a><ul id="zh-cn_topic_0000001127125106_ul3688920133220"><li>50px 100px 60px：分三列，第一列50px，第二列100px，第三列60px；</li><li>1fr 1fr 2fr：分三列，将父组件允许的宽分为4等份，第一列占1份，第二列占一份，第三列占2份；</li><li>30% 20% 50%：分三列，将父组件允许的宽为基准，第一列占30%，第二列占20%，第三列占50%；</li><li>repeat(2,100px)：分两列，第一列100px，第二列100px；</li><li>repeat(auto-fill,100px)<sup id="zh-cn_topic_0000001127125106_sup3688112073216"><a name="zh-cn_topic_0000001127125106_sup3688112073216"></a><a name="zh-cn_topic_0000001127125106_sup3688112073216"></a>5+</sup>：按照每列100px的大小和交叉轴大小计算最大正整数重复次数，按照该重复次数布满交叉轴；</li><li>auto 1fr 1fr：分三列，第一列自适应内部子组件所需宽度，剩余空间分为两等份，第二列占一份，第三列占一份。</li></ul>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125106_row106881920143218"><td class="cellrowborder" valign="top" width="21.18788121187881%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125106_p66881020173213"><a name="zh-cn_topic_0000001127125106_p66881020173213"></a><a name="zh-cn_topic_0000001127125106_p66881020173213"></a>grid-[columns|rows]-gap</p>
</td>
<td class="cellrowborder" valign="top" width="16.648335166483353%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125106_p16688192063214"><a name="zh-cn_topic_0000001127125106_p16688192063214"></a><a name="zh-cn_topic_0000001127125106_p16688192063214"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.618638136186382%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125106_p15688920143215"><a name="zh-cn_topic_0000001127125106_p15688920143215"></a><a name="zh-cn_topic_0000001127125106_p15688920143215"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.329267073292671%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125106_p16688162003215"><a name="zh-cn_topic_0000001127125106_p16688162003215"></a><a name="zh-cn_topic_0000001127125106_p16688162003215"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="41.21587841215879%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125106_p96881920183213"><a name="zh-cn_topic_0000001127125106_p96881920183213"></a><a name="zh-cn_topic_0000001127125106_p96881920183213"></a>用于设置行与行的间距或者列与列的间距，也可以支持通过grid-gap设置相同的行列间距，仅当display为grid时生效。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125106_row1268882053219"><td class="cellrowborder" valign="top" width="21.18788121187881%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125106_p1668942011327"><a name="zh-cn_topic_0000001127125106_p1668942011327"></a><a name="zh-cn_topic_0000001127125106_p1668942011327"></a>grid-row-[start|end]</p>
</td>
<td class="cellrowborder" valign="top" width="16.648335166483353%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125106_p11689620143210"><a name="zh-cn_topic_0000001127125106_p11689620143210"></a><a name="zh-cn_topic_0000001127125106_p11689620143210"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="13.618638136186382%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125106_p66891920143215"><a name="zh-cn_topic_0000001127125106_p66891920143215"></a><a name="zh-cn_topic_0000001127125106_p66891920143215"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.329267073292671%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125106_p17689152083218"><a name="zh-cn_topic_0000001127125106_p17689152083218"></a><a name="zh-cn_topic_0000001127125106_p17689152083218"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="41.21587841215879%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125106_p16689132033212"><a name="zh-cn_topic_0000001127125106_p16689132033212"></a><a name="zh-cn_topic_0000001127125106_p16689132033212"></a>用于设置当前元素在网格布局中的起止行号，仅当父组件display样式为grid时生效（仅div支持display样式设置为grid）。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125106_row1968942013212"><td class="cellrowborder" valign="top" width="21.18788121187881%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125106_p26894201323"><a name="zh-cn_topic_0000001127125106_p26894201323"></a><a name="zh-cn_topic_0000001127125106_p26894201323"></a>grid-column-[start|end]</p>
</td>
<td class="cellrowborder" valign="top" width="16.648335166483353%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125106_p18689122018329"><a name="zh-cn_topic_0000001127125106_p18689122018329"></a><a name="zh-cn_topic_0000001127125106_p18689122018329"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="13.618638136186382%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125106_p26894206327"><a name="zh-cn_topic_0000001127125106_p26894206327"></a><a name="zh-cn_topic_0000001127125106_p26894206327"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.329267073292671%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125106_p668914203321"><a name="zh-cn_topic_0000001127125106_p668914203321"></a><a name="zh-cn_topic_0000001127125106_p668914203321"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="41.21587841215879%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125106_p1168942083212"><a name="zh-cn_topic_0000001127125106_p1168942083212"></a><a name="zh-cn_topic_0000001127125106_p1168942083212"></a>用于设置当前元素在网格布局中的起止列号，仅当父组件display样式为grid时生效（仅div支持display样式设置为grid）。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125106_row1689120153217"><td class="cellrowborder" valign="top" width="21.18788121187881%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125106_p368912011325"><a name="zh-cn_topic_0000001127125106_p368912011325"></a><a name="zh-cn_topic_0000001127125106_p368912011325"></a>grid-auto-flow<sup id="zh-cn_topic_0000001127125106_sup26892020153214"><a name="zh-cn_topic_0000001127125106_sup26892020153214"></a><a name="zh-cn_topic_0000001127125106_sup26892020153214"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="16.648335166483353%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125106_p20689112043215"><a name="zh-cn_topic_0000001127125106_p20689112043215"></a><a name="zh-cn_topic_0000001127125106_p20689112043215"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.618638136186382%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125106_p186893207322"><a name="zh-cn_topic_0000001127125106_p186893207322"></a><a name="zh-cn_topic_0000001127125106_p186893207322"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.329267073292671%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125106_p20689182003216"><a name="zh-cn_topic_0000001127125106_p20689182003216"></a><a name="zh-cn_topic_0000001127125106_p20689182003216"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="41.21587841215879%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125106_p176891320123210"><a name="zh-cn_topic_0000001127125106_p176891320123210"></a><a name="zh-cn_topic_0000001127125106_p176891320123210"></a>使用框架自动布局算法进行网格的布局，可选值为：</p>
<a name="zh-cn_topic_0000001127125106_ul12689152083220"></a><a name="zh-cn_topic_0000001127125106_ul12689152083220"></a><ul id="zh-cn_topic_0000001127125106_ul12689152083220"><li>row：逐行填充元素，如果行空间不够，则新增行；</li><li>column：逐列填充元素，如果列空间不够，则新增列。</li></ul>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125106_row8465152118595"><td class="cellrowborder" valign="top" width="21.18788121187881%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125106_p446513211597"><a name="zh-cn_topic_0000001127125106_p446513211597"></a><a name="zh-cn_topic_0000001127125106_p446513211597"></a>overflow<sup id="zh-cn_topic_0000001127125106_sup14860336125911"><a name="zh-cn_topic_0000001127125106_sup14860336125911"></a><a name="zh-cn_topic_0000001127125106_sup14860336125911"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="16.648335166483353%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125106_p6465172105918"><a name="zh-cn_topic_0000001127125106_p6465172105918"></a><a name="zh-cn_topic_0000001127125106_p6465172105918"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.618638136186382%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125106_p1546592111596"><a name="zh-cn_topic_0000001127125106_p1546592111596"></a><a name="zh-cn_topic_0000001127125106_p1546592111596"></a>visible</p>
</td>
<td class="cellrowborder" valign="top" width="7.329267073292671%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125106_p18465221125911"><a name="zh-cn_topic_0000001127125106_p18465221125911"></a><a name="zh-cn_topic_0000001127125106_p18465221125911"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="41.21587841215879%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125106_p146532175915"><a name="zh-cn_topic_0000001127125106_p146532175915"></a><a name="zh-cn_topic_0000001127125106_p146532175915"></a>设置元素内容区超过元素本身大小时的表现形式。</p>
<a name="zh-cn_topic_0000001127125106_ul531213221202"></a><a name="zh-cn_topic_0000001127125106_ul531213221202"></a><ul id="zh-cn_topic_0000001127125106_ul531213221202"><li>visible：多个子元素内容超过元素大小时，显示在元素外面；</li><li>hidden：元素内容超过元素大小时，进行裁切显示；</li><li>scroll：元素内容超过元素大小时，进行滚动显示并展示滚动条（当前只支持纵向）。</li></ul>
<div class="note" id="zh-cn_topic_0000001127125106_note1571135818019"><a name="zh-cn_topic_0000001127125106_note1571135818019"></a><a name="zh-cn_topic_0000001127125106_note1571135818019"></a><span class="notetitle"> 说明： </span><div class="notebody"><a name="zh-cn_topic_0000001127125106_ul8327981218"></a><a name="zh-cn_topic_0000001127125106_ul8327981218"></a><ul id="zh-cn_topic_0000001127125106_ul8327981218"><li>overflow: scroll样式需要元素设置固定的大小。</li></ul>
</div></div>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125106_row83713507010"><td class="cellrowborder" valign="top" width="21.18788121187881%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125106_p2037105016016"><a name="zh-cn_topic_0000001127125106_p2037105016016"></a><a name="zh-cn_topic_0000001127125106_p2037105016016"></a>align-items<sup id="zh-cn_topic_0000001127125106_sup1453123611119"><a name="zh-cn_topic_0000001127125106_sup1453123611119"></a><a name="zh-cn_topic_0000001127125106_sup1453123611119"></a><span>6+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="16.648335166483353%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125106_p183721550309"><a name="zh-cn_topic_0000001127125106_p183721550309"></a><a name="zh-cn_topic_0000001127125106_p183721550309"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.618638136186382%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125106_p5372165019019"><a name="zh-cn_topic_0000001127125106_p5372165019019"></a><a name="zh-cn_topic_0000001127125106_p5372165019019"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.329267073292671%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125106_p93721501701"><a name="zh-cn_topic_0000001127125106_p93721501701"></a><a name="zh-cn_topic_0000001127125106_p93721501701"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="41.21587841215879%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125106_p17372155018015"><a name="zh-cn_topic_0000001127125106_p17372155018015"></a><a name="zh-cn_topic_0000001127125106_p17372155018015"></a>设置容器中元素交叉轴上的对齐方式：</p>
<a name="zh-cn_topic_0000001127125106_ul7910135512514"></a><a name="zh-cn_topic_0000001127125106_ul7910135512514"></a><ul id="zh-cn_topic_0000001127125106_ul7910135512514"><li>stretch：Flex容器内容在交叉轴方向被拉伸到与容器相同的高度或宽度；</li><li>flex-start：Flex布局容器内元素向交叉轴起点对齐；</li><li>flex-end：Flex布局容器内元素向交叉轴终点对齐；</li><li>center：Flex布局容器内元素在交叉轴居中对齐；</li><li>baseline：如Flex布局纵向排列，则该值与'flex-start'等效。横向布局时，内容元素存在文本时按照文本基线对齐，否则底部对齐。</li></ul>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125106_row1629945313212"><td class="cellrowborder" valign="top" width="21.18788121187881%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125106_p829911534213"><a name="zh-cn_topic_0000001127125106_p829911534213"></a><a name="zh-cn_topic_0000001127125106_p829911534213"></a>scrollbar-color<sup id="zh-cn_topic_0000001127125106_sup843916381239"><a name="zh-cn_topic_0000001127125106_sup843916381239"></a><a name="zh-cn_topic_0000001127125106_sup843916381239"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="16.648335166483353%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125106_p122991553112113"><a name="zh-cn_topic_0000001127125106_p122991553112113"></a><a name="zh-cn_topic_0000001127125106_p122991553112113"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.618638136186382%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125106_p17299253132120"><a name="zh-cn_topic_0000001127125106_p17299253132120"></a><a name="zh-cn_topic_0000001127125106_p17299253132120"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.329267073292671%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125106_p9299135342110"><a name="zh-cn_topic_0000001127125106_p9299135342110"></a><a name="zh-cn_topic_0000001127125106_p9299135342110"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="41.21587841215879%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125106_p14300165317215"><a name="zh-cn_topic_0000001127125106_p14300165317215"></a><a name="zh-cn_topic_0000001127125106_p14300165317215"></a>设置滚动条的颜色。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125106_row17334859142112"><td class="cellrowborder" valign="top" width="21.18788121187881%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125106_p1433575912212"><a name="zh-cn_topic_0000001127125106_p1433575912212"></a><a name="zh-cn_topic_0000001127125106_p1433575912212"></a>scrollbar-width<sup id="zh-cn_topic_0000001127125106_sup10700174022317"><a name="zh-cn_topic_0000001127125106_sup10700174022317"></a><a name="zh-cn_topic_0000001127125106_sup10700174022317"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="16.648335166483353%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125106_p3335165919217"><a name="zh-cn_topic_0000001127125106_p3335165919217"></a><a name="zh-cn_topic_0000001127125106_p3335165919217"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.618638136186382%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125106_p6335175914219"><a name="zh-cn_topic_0000001127125106_p6335175914219"></a><a name="zh-cn_topic_0000001127125106_p6335175914219"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.329267073292671%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125106_p13335759172115"><a name="zh-cn_topic_0000001127125106_p13335759172115"></a><a name="zh-cn_topic_0000001127125106_p13335759172115"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="41.21587841215879%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125106_p533510595217"><a name="zh-cn_topic_0000001127125106_p533510595217"></a><a name="zh-cn_topic_0000001127125106_p533510595217"></a>设置滚动条的宽度。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125106_row103571044227"><td class="cellrowborder" valign="top" width="21.18788121187881%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127125106_p23581146229"><a name="zh-cn_topic_0000001127125106_p23581146229"></a><a name="zh-cn_topic_0000001127125106_p23581146229"></a>overscroll-effect<sup id="zh-cn_topic_0000001127125106_sup8319241142311"><a name="zh-cn_topic_0000001127125106_sup8319241142311"></a><a name="zh-cn_topic_0000001127125106_sup8319241142311"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="16.648335166483353%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127125106_p17358204182217"><a name="zh-cn_topic_0000001127125106_p17358204182217"></a><a name="zh-cn_topic_0000001127125106_p17358204182217"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.618638136186382%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127125106_p4358124122211"><a name="zh-cn_topic_0000001127125106_p4358124122211"></a><a name="zh-cn_topic_0000001127125106_p4358124122211"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.329267073292671%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127125106_p1835816422213"><a name="zh-cn_topic_0000001127125106_p1835816422213"></a><a name="zh-cn_topic_0000001127125106_p1835816422213"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="41.21587841215879%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127125106_p153581140221"><a name="zh-cn_topic_0000001127125106_p153581140221"></a><a name="zh-cn_topic_0000001127125106_p153581140221"></a>设置滚动边缘效果，可选值为：</p>
<a name="zh-cn_topic_0000001127125106_ul2660123592519"></a><a name="zh-cn_topic_0000001127125106_ul2660123592519"></a><ul id="zh-cn_topic_0000001127125106_ul2660123592519"><li>spring：弹性物理动效，滑动到边缘后可以根据初始速度或通过触摸事件继续滑动一段距离，松手后回弹；</li><li>fade：渐隐物理动效，滑动到边缘后展示一个波浪形的渐隐，根据速度和滑动距离的变化渐隐也会发送一定的变化；</li><li>none：滑动到边缘后无效果</li></ul>
</td>
</tr>
</tbody>
</table>

## 事件<a name="zh-cn_topic_0000001127125106_section77341431152917"></a>

除支持[通用事件](js-components-common-events.md#ZH-CN_TOPIC_0000001209412119)外，还支持如下事件：

<a name="zh-cn_topic_0000001127125106_tf7a840896dc848b5ab17a18b50036601"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001127125106_rf3d0da15d2f64cd492dfa1e7d98890a5"><th class="cellrowborder" valign="top" width="16.18%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001127125106_a487aa1c493e84ca68567b4b65051674d"><a name="zh-cn_topic_0000001127125106_a487aa1c493e84ca68567b4b65051674d"></a><a name="zh-cn_topic_0000001127125106_a487aa1c493e84ca68567b4b65051674d"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="21.89%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001127125106_adc4b506cda3043508da6ee7649c12ca4"><a name="zh-cn_topic_0000001127125106_adc4b506cda3043508da6ee7649c12ca4"></a><a name="zh-cn_topic_0000001127125106_adc4b506cda3043508da6ee7649c12ca4"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="61.92999999999999%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001127125106_a59e4cbe58a5c42a7a4585bc8365783bc"><a name="zh-cn_topic_0000001127125106_a59e4cbe58a5c42a7a4585bc8365783bc"></a><a name="zh-cn_topic_0000001127125106_a59e4cbe58a5c42a7a4585bc8365783bc"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001127125106_row19193181433116"><td class="cellrowborder" valign="top" width="16.18%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001127125106_p919321419315"><a name="zh-cn_topic_0000001127125106_p919321419315"></a><a name="zh-cn_topic_0000001127125106_p919321419315"></a>reachstart<sup id="zh-cn_topic_0000001127125106_sup18542427173112"><a name="zh-cn_topic_0000001127125106_sup18542427173112"></a><a name="zh-cn_topic_0000001127125106_sup18542427173112"></a><span>6+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="21.89%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001127125106_p11805161217520"><a name="zh-cn_topic_0000001127125106_p11805161217520"></a><a name="zh-cn_topic_0000001127125106_p11805161217520"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="61.92999999999999%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001127125106_p617863613413"><a name="zh-cn_topic_0000001127125106_p617863613413"></a><a name="zh-cn_topic_0000001127125106_p617863613413"></a>当页面滑动到最开始的点时触发的事件回调，当flex-direction: row时才会触发。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125106_row1812350173410"><td class="cellrowborder" valign="top" width="16.18%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001127125106_p3812150173411"><a name="zh-cn_topic_0000001127125106_p3812150173411"></a><a name="zh-cn_topic_0000001127125106_p3812150173411"></a>reachend<sup id="zh-cn_topic_0000001127125106_sup1959668163514"><a name="zh-cn_topic_0000001127125106_sup1959668163514"></a><a name="zh-cn_topic_0000001127125106_sup1959668163514"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="21.89%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001127125106_p173576151454"><a name="zh-cn_topic_0000001127125106_p173576151454"></a><a name="zh-cn_topic_0000001127125106_p173576151454"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="61.92999999999999%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001127125106_p1480216408412"><a name="zh-cn_topic_0000001127125106_p1480216408412"></a><a name="zh-cn_topic_0000001127125106_p1480216408412"></a>当页面滑动到最末尾的点时触发的事件回调，当flex-direction: row时才会触发。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125106_row177991024193516"><td class="cellrowborder" valign="top" width="16.18%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001127125106_p1799132411359"><a name="zh-cn_topic_0000001127125106_p1799132411359"></a><a name="zh-cn_topic_0000001127125106_p1799132411359"></a>reachtop<sup id="zh-cn_topic_0000001127125106_sup126311239153512"><a name="zh-cn_topic_0000001127125106_sup126311239153512"></a><a name="zh-cn_topic_0000001127125106_sup126311239153512"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="21.89%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001127125106_p93757171511"><a name="zh-cn_topic_0000001127125106_p93757171511"></a><a name="zh-cn_topic_0000001127125106_p93757171511"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="61.92999999999999%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001127125106_p1841194517415"><a name="zh-cn_topic_0000001127125106_p1841194517415"></a><a name="zh-cn_topic_0000001127125106_p1841194517415"></a>当页面滑动到最上部的点时触发的事件回调，当flex-direction: column时才会触发。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125106_row2849452153619"><td class="cellrowborder" valign="top" width="16.18%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001127125106_p11850135219366"><a name="zh-cn_topic_0000001127125106_p11850135219366"></a><a name="zh-cn_topic_0000001127125106_p11850135219366"></a>reachbottom<sup id="zh-cn_topic_0000001127125106_sup66531160375"><a name="zh-cn_topic_0000001127125106_sup66531160375"></a><a name="zh-cn_topic_0000001127125106_sup66531160375"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="21.89%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001127125106_p798910191353"><a name="zh-cn_topic_0000001127125106_p798910191353"></a><a name="zh-cn_topic_0000001127125106_p798910191353"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="61.92999999999999%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001127125106_p1885010522361"><a name="zh-cn_topic_0000001127125106_p1885010522361"></a><a name="zh-cn_topic_0000001127125106_p1885010522361"></a>当页面滑动到最下部的点时触发的事件回调，当flex-direction: column时才会触发。</p>
</td>
</tr>
</tbody>
</table>

## 方法<a name="zh-cn_topic_0000001127125106_section2279124532420"></a>

除支持[通用方法](js-components-common-methods.md#ZH-CN_TOPIC_0000001209252157)外，还支持如下方法：

<a name="zh-cn_topic_0000001127125106_table20753173210251"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001127125106_row575363214257"><th class="cellrowborder" valign="top" width="17.07%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001127125106_p157531032112517"><a name="zh-cn_topic_0000001127125106_p157531032112517"></a><a name="zh-cn_topic_0000001127125106_p157531032112517"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="11.84%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001127125106_p77531632132518"><a name="zh-cn_topic_0000001127125106_p77531632132518"></a><a name="zh-cn_topic_0000001127125106_p77531632132518"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="13.66%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001127125106_p817515404414"><a name="zh-cn_topic_0000001127125106_p817515404414"></a><a name="zh-cn_topic_0000001127125106_p817515404414"></a>返回值</p>
</th>
<th class="cellrowborder" valign="top" width="57.43000000000001%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001127125106_p147531232132512"><a name="zh-cn_topic_0000001127125106_p147531232132512"></a><a name="zh-cn_topic_0000001127125106_p147531232132512"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001127125106_row15753113210251"><td class="cellrowborder" valign="top" width="17.07%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001127125106_p2314135812511"><a name="zh-cn_topic_0000001127125106_p2314135812511"></a><a name="zh-cn_topic_0000001127125106_p2314135812511"></a>getScrollOffset<sup id="zh-cn_topic_0000001127125106_sup663342216185"><a name="zh-cn_topic_0000001127125106_sup663342216185"></a><a name="zh-cn_topic_0000001127125106_sup663342216185"></a><span>6+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="11.84%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001127125106_p7314115819256"><a name="zh-cn_topic_0000001127125106_p7314115819256"></a><a name="zh-cn_topic_0000001127125106_p7314115819256"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="13.66%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001127125106_p2017514401045"><a name="zh-cn_topic_0000001127125106_p2017514401045"></a><a name="zh-cn_topic_0000001127125106_p2017514401045"></a><a href="#zh-cn_topic_0000001127125106_table154011838131719">ScrollOffset</a></p>
</td>
<td class="cellrowborder" valign="top" width="57.43000000000001%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001127125106_p0314958162512"><a name="zh-cn_topic_0000001127125106_p0314958162512"></a><a name="zh-cn_topic_0000001127125106_p0314958162512"></a>获取元素内容的滚动偏移。</p>
<div class="note" id="zh-cn_topic_0000001127125106_note18321919610"><a name="zh-cn_topic_0000001127125106_note18321919610"></a><a name="zh-cn_topic_0000001127125106_note18321919610"></a><span class="notetitle"> 说明： </span><div class="notebody"><a name="zh-cn_topic_0000001127125106_ul873964691316"></a><a name="zh-cn_topic_0000001127125106_ul873964691316"></a><ul id="zh-cn_topic_0000001127125106_ul873964691316"><li>需要设置overflow样式为scroll。</li></ul>
</div></div>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125106_row393410526251"><td class="cellrowborder" valign="top" width="17.07%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001127125106_p6171185561413"><a name="zh-cn_topic_0000001127125106_p6171185561413"></a><a name="zh-cn_topic_0000001127125106_p6171185561413"></a>scrollBy<sup id="zh-cn_topic_0000001127125106_sup188191223181818"><a name="zh-cn_topic_0000001127125106_sup188191223181818"></a><a name="zh-cn_topic_0000001127125106_sup188191223181818"></a><span>6+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="11.84%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001127125106_p1231455814253"><a name="zh-cn_topic_0000001127125106_p1231455814253"></a><a name="zh-cn_topic_0000001127125106_p1231455814253"></a><a href="#zh-cn_topic_0000001127125106_table1139175871819">ScrollParam</a></p>
</td>
<td class="cellrowborder" valign="top" width="13.66%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001127125106_p121756404410"><a name="zh-cn_topic_0000001127125106_p121756404410"></a><a name="zh-cn_topic_0000001127125106_p121756404410"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="57.43000000000001%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001127125106_p10314105842512"><a name="zh-cn_topic_0000001127125106_p10314105842512"></a><a name="zh-cn_topic_0000001127125106_p10314105842512"></a>指定元素内容的滚动偏移。</p>
<div class="note" id="zh-cn_topic_0000001127125106_note3227027181713"><a name="zh-cn_topic_0000001127125106_note3227027181713"></a><a name="zh-cn_topic_0000001127125106_note3227027181713"></a><span class="notetitle"> 说明： </span><div class="notebody"><a name="zh-cn_topic_0000001127125106_ul11227027181717"></a><a name="zh-cn_topic_0000001127125106_ul11227027181717"></a><ul id="zh-cn_topic_0000001127125106_ul11227027181717"><li>需要设置overflow样式为scroll。</li></ul>
</div></div>
</td>
</tr>
</tbody>
</table>

**表 1**  ScrollOffset<sup>6+</sup>

<a name="zh-cn_topic_0000001127125106_table154011838131719"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001127125106_row154011938191717"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="zh-cn_topic_0000001127125106_p0401153814174"><a name="zh-cn_topic_0000001127125106_p0401153814174"></a><a name="zh-cn_topic_0000001127125106_p0401153814174"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="zh-cn_topic_0000001127125106_p19401038111719"><a name="zh-cn_topic_0000001127125106_p19401038111719"></a><a name="zh-cn_topic_0000001127125106_p19401038111719"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="zh-cn_topic_0000001127125106_p104011438181716"><a name="zh-cn_topic_0000001127125106_p104011438181716"></a><a name="zh-cn_topic_0000001127125106_p104011438181716"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001127125106_row6401133811715"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001127125106_p0401153816171"><a name="zh-cn_topic_0000001127125106_p0401153816171"></a><a name="zh-cn_topic_0000001127125106_p0401153816171"></a>x</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001127125106_p17401183819172"><a name="zh-cn_topic_0000001127125106_p17401183819172"></a><a name="zh-cn_topic_0000001127125106_p17401183819172"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001127125106_p1840123811176"><a name="zh-cn_topic_0000001127125106_p1840123811176"></a><a name="zh-cn_topic_0000001127125106_p1840123811176"></a>在x轴方向的偏移，单位为px。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125106_row540103815174"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001127125106_p1240133811713"><a name="zh-cn_topic_0000001127125106_p1240133811713"></a><a name="zh-cn_topic_0000001127125106_p1240133811713"></a>y</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001127125106_p4402153816174"><a name="zh-cn_topic_0000001127125106_p4402153816174"></a><a name="zh-cn_topic_0000001127125106_p4402153816174"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001127125106_p94021838121713"><a name="zh-cn_topic_0000001127125106_p94021838121713"></a><a name="zh-cn_topic_0000001127125106_p94021838121713"></a>在y轴方向的偏移，单位为px。</p>
</td>
</tr>
</tbody>
</table>

**表 2**  ScrollParam<sup>6+</sup>

<a name="zh-cn_topic_0000001127125106_table1139175871819"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001127125106_row161391758201815"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="zh-cn_topic_0000001127125106_p161396585187"><a name="zh-cn_topic_0000001127125106_p161396585187"></a><a name="zh-cn_topic_0000001127125106_p161396585187"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="zh-cn_topic_0000001127125106_p613975815186"><a name="zh-cn_topic_0000001127125106_p613975815186"></a><a name="zh-cn_topic_0000001127125106_p613975815186"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="zh-cn_topic_0000001127125106_p18140145861817"><a name="zh-cn_topic_0000001127125106_p18140145861817"></a><a name="zh-cn_topic_0000001127125106_p18140145861817"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001127125106_row41401258181817"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001127125106_p1140858101811"><a name="zh-cn_topic_0000001127125106_p1140858101811"></a><a name="zh-cn_topic_0000001127125106_p1140858101811"></a>dx</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001127125106_p1014085831819"><a name="zh-cn_topic_0000001127125106_p1014085831819"></a><a name="zh-cn_topic_0000001127125106_p1014085831819"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001127125106_p8140458111815"><a name="zh-cn_topic_0000001127125106_p8140458111815"></a><a name="zh-cn_topic_0000001127125106_p8140458111815"></a>水平方向滑动的偏移量，单位px。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125106_row101401584185"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001127125106_p1314055819184"><a name="zh-cn_topic_0000001127125106_p1314055819184"></a><a name="zh-cn_topic_0000001127125106_p1314055819184"></a>dy</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001127125106_p614035881816"><a name="zh-cn_topic_0000001127125106_p614035881816"></a><a name="zh-cn_topic_0000001127125106_p614035881816"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001127125106_p214075831810"><a name="zh-cn_topic_0000001127125106_p214075831810"></a><a name="zh-cn_topic_0000001127125106_p214075831810"></a>垂直方向滑动的偏移量，单位px。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125106_row1414025811820"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001127125106_p814014580180"><a name="zh-cn_topic_0000001127125106_p814014580180"></a><a name="zh-cn_topic_0000001127125106_p814014580180"></a>smooth</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001127125106_p17140155818186"><a name="zh-cn_topic_0000001127125106_p17140155818186"></a><a name="zh-cn_topic_0000001127125106_p17140155818186"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001127125106_p21401584187"><a name="zh-cn_topic_0000001127125106_p21401584187"></a><a name="zh-cn_topic_0000001127125106_p21401584187"></a>是否平滑处理。</p>
</td>
</tr>
</tbody>
</table>

## 示例<a name="zh-cn_topic_0000001127125106_section1241545010391"></a>

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

    ![](figures/zh-cn_image_0000001173164931.png)

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

    ![](figures/zh-cn_image_0000001127125266.png)


