# list<a name="ZH-CN_TOPIC_0000001127284836"></a>

列表包含一系列相同宽度的列表项。适合连续、多行呈现同类数据，例如图片和文本。

## 权限列表<a name="section11257113618419"></a>

无

## 子组件<a name="section9288143101012"></a>

仅支持<[list-item-group](js-components-container-list-item-group.md)\>和<[list-item](js-components-container-list-item.md)\>。

## 属性<a name="section2907183951110"></a>

除支持[通用属性](js-components-common-attributes.md)外，还支持如下属性：

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="14.67%" id="mcps1.1.6.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="10.91%" id="mcps1.1.6.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="9.34%" id="mcps1.1.6.1.4"><p>必填</p>
</th>
<th class="cellrowborder" valign="top" width="41.959999999999994%" id="mcps1.1.6.1.5"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>scrollpage</p>
</td>
<td class="cellrowborder" valign="top" width="14.67%" headers="mcps1.1.6.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.91%" headers="mcps1.1.6.1.3 "><p>false</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="41.959999999999994%" headers="mcps1.1.6.1.5 "><p>设置为true时，将 list 顶部页面中非 list 部分随 list 一起滑出可视区域，当list方向为row时，不支持此属性。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>cachedcount</p>
</td>
<td class="cellrowborder" valign="top" width="14.67%" headers="mcps1.1.6.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.91%" headers="mcps1.1.6.1.3 "><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="41.959999999999994%" headers="mcps1.1.6.1.5 "><p>长列表延迟加载时list-item最少缓存数量。</p>
<p>可视区域外缓存的list-item数量少于该值时，会触发requestitem事件。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>scrollbar</p>
</td>
<td class="cellrowborder" valign="top" width="14.67%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.91%" headers="mcps1.1.6.1.3 "><p>off</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="41.959999999999994%" headers="mcps1.1.6.1.5 "><p>侧边滑动栏的显示模式（当前只支持纵向）：</p>
<ul><li>off：不显示。</li><li>auto：按需显示(触摸时显示，2s后消失)。</li><li>on：常驻显示。</li></ul>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>scrolleffect</p>
</td>
<td class="cellrowborder" valign="top" width="14.67%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.91%" headers="mcps1.1.6.1.3 "><p>spring</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="41.959999999999994%" headers="mcps1.1.6.1.5 "><p>滑动效果，目前支持如下滑动效果：</p>
<ul><li>spring：弹性物理动效，滑动到边缘后可以根据初始速度或通过触摸事件继续滑动一段距离，松手后回弹。</li><li>fade：渐隐物理动效，滑动到边缘后展示一个波浪形的渐隐，根据速度和滑动距离的变化渐隐也会发送一定的变化。</li><li>no：滑动到边缘后无效果。</li></ul>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>indexer</p>
</td>
<td class="cellrowborder" valign="top" width="14.67%" headers="mcps1.1.6.1.2 "><p>boolean | Array&lt;string&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.91%" headers="mcps1.1.6.1.3 "><p>false</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="41.959999999999994%" headers="mcps1.1.6.1.5 "><p>是否展示侧边栏快速字母索引栏。设置为true或者自定义索引时，索引栏会显示在列表右边界处。示例：</p>
<p>"indexer" : "true"表示使用默认字母索引表。</p>
<p>"indexer" : "false"表示无索引。</p>
<p>"indexer" : ['#',‘1’,'2',‘3’,'4',‘5’,'6',‘7’,'8']表示自定义索引表。自定义时"#"必须要存在。</p>
<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><ul><li>indexer属性生效需要flex-direction属性配合设置为column，且columns属性设置为1。</li><li>点击索引条进行列表项索引需要list-item子组件配合设置相应的<a href="js-components-container-list-item.md#section2907183951110">section属性</a>。</li></ul>
</div></div>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>indexercircle<sup><span>5+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="14.67%" headers="mcps1.1.6.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.91%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="41.959999999999994%" headers="mcps1.1.6.1.5 "><p>是否为环形索引。</p>
<p>穿戴设备默认为true，其他为false。indexer为false时不生效。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>indexermulti<sup><span>5+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="14.67%" headers="mcps1.1.6.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.91%" headers="mcps1.1.6.1.3 "><p>false</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="41.959999999999994%" headers="mcps1.1.6.1.5 "><p>是否开启索引条多语言功能。</p>
<p>indexer为false时不生效。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>indexerbubble<sup><span>5+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="14.67%" headers="mcps1.1.6.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.91%" headers="mcps1.1.6.1.3 "><p>true</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="41.959999999999994%" headers="mcps1.1.6.1.5 "><p>是否开启索引切换的气泡提示。</p>
<p>indexer为false时不生效。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>divider<sup><span>5+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="14.67%" headers="mcps1.1.6.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.91%" headers="mcps1.1.6.1.3 "><p>false</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="41.959999999999994%" headers="mcps1.1.6.1.5 "><p>item是否自带分隔线。</p>
<p>其样式参考<a href="../../nottoctopics/zh-cn_topic_0000001131154746.md#section1071433432218">样式列表</a>的divider-color、divider-height、divider-length、divider-origin。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>shapemode</p>
</td>
<td class="cellrowborder" valign="top" width="14.67%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.91%" headers="mcps1.1.6.1.3 "><p>default</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="41.959999999999994%" headers="mcps1.1.6.1.5 "><p>侧边滑动栏的形状类型。</p>
<ul><li>default：不指定，跟随主题；</li><li>rect：矩形；</li><li>round：圆形。</li></ul>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>updateeffect</p>
</td>
<td class="cellrowborder" valign="top" width="14.67%" headers="mcps1.1.6.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.91%" headers="mcps1.1.6.1.3 "><p>false</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="41.959999999999994%" headers="mcps1.1.6.1.5 "><p>用于设置当list内部的item发生删除或新增时是否支持动效。</p>
<ul><li>false：新增删除item时无过渡动效。</li><li>true：新增删除item时播放过程动效。</li></ul>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>chainanimation<sup>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="14.67%" headers="mcps1.1.6.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.91%" headers="mcps1.1.6.1.3 "><p>false</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="41.959999999999994%" headers="mcps1.1.6.1.5 "><p>用于设置当前list是否启用链式联动动效，开启后列表滑动以及顶部和底部拖拽时会有链式联动的效果。链式联动效果：list内的list-item间隔一定距离，在基本的滑动交互行为下，主动对象驱动从动对象进行联动，驱动效果遵循弹簧物理动效。</p>
<ul><li>false：不启用链式联动</li><li>true：启用链式联动<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><ul><li>不支持动态修改。</li><li>如同时配置了indexer，链式动效不生效。</li><li>如配置了链式动效，list-item的sticky不生效。</li></ul>
</div></div>
</li></ul>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>initialindex</p>
</td>
<td class="cellrowborder" valign="top" width="14.67%" headers="mcps1.1.6.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.91%" headers="mcps1.1.6.1.3 "><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="41.959999999999994%" headers="mcps1.1.6.1.5 "><p>用于设置当前List初次加载时视口起始位置显示的item，默认为0，即显示第一个item，如设置的序号超过了最后一个item的序号，则设置不生效，当同时设置了initialoffset属性时，当前属性不生效。当indexer为true或者scrollpage为true时，不生效。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>initialoffset</p>
</td>
<td class="cellrowborder" valign="top" width="14.67%" headers="mcps1.1.6.1.2 "><p>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.91%" headers="mcps1.1.6.1.3 "><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="41.959999999999994%" headers="mcps1.1.6.1.5 "><p>用于设置当前List初次加载时视口的起始偏移量，偏移量无法超过当前List可滑动的范围，如果超过会被截断为可滑动范围的极限值。当indexer为true或者scrollpage为true时，不生效。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>selected<sup>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="14.67%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.91%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="41.959999999999994%" headers="mcps1.1.6.1.5 "><p>指定当前列表中被选中激活的项，可选值为list-item的section属性值。</p>
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
<tbody><tr><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p>divider-color<sup><span>5+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p>transparent</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p>item分隔线颜色，仅当list的divider属性为true时生效。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p>divider-height<sup><span>5+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p>1</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p>item分隔线高度，仅当list的divider属性为true时生效。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p>divider-length<sup><span>5+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p>主轴宽度</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p>item分隔线长度，不设置时最大长度为主轴宽度，具体长度取决于divider-origin，仅当list的divider属性为true时生效。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p>divider-origin<sup><span>5+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p>item分隔线相对于item主轴起点位置的偏移量，仅当list的divider属性为true时生效。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p>flex-direction</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p>string</p>
<p></p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p>column</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p>设置flex容器主轴的方向，指定flex项如何放置在flex容器中，可选值为：</p>
<ul><li>column：主轴为纵向。</li><li>row：主轴为横向。</li></ul>
<p>其他组件默认值为row，在list组件中默认值为column。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p>columns</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p>1</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p>list交叉轴方向的显示列数，默认为1列。</p>
<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>设置多列时，在list交叉轴上进行均分，每一列大小相同。</p>
</div></div>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p>align-items</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p>stretch</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p>list每一列交叉轴上的对齐格式，可选值为：</p>
<ul><li>stretch：弹性元素被在交叉轴方向被拉伸到与容器相同的高度或宽度。</li><li>flex-start：元素向交叉轴起点对齐。</li><li>flex-end：元素向交叉轴终点对齐。</li><li>center：元素在交叉轴居中。<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>align-items样式作用在每一列的子元素上，列与列之间采用均分方式布局。</p>
</div></div>
</li></ul>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p>item-extent</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p>&lt;length&gt; | &lt;percentage&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p>设置内部item为固定大小，设置为百分比格式时，指相对于list的视口主轴方向长度的百分比。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p>fade-color</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p><span>&lt;</span><span>color</span><span>&gt;</span></p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p>grey</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p>设置渐隐物理动效的颜色。当滑动效果设置为渐隐物理动效时生效。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p>scrollbar-color<sup>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p>设置滚动条的颜色。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p>scrollbar-width<sup>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p>设置滚动条的宽度。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p>scrollbar-offset<sup>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p>设置滚动条距离List默认位置的偏移量，只支持正数，默认位置在List右边缘，可以通过这个偏移量调整滚动条的水平位置，如果滚动条绘制在list外部，而list父组件有裁剪，会导致滚动条被裁剪。</p>
</td>
</tr>
</tbody>
</table>

## 事件<a name="section471854810515"></a>

除支持[通用事件](js-components-common-events.md)外，还支持如下事件：

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="24.852485248524854%" id="mcps1.1.4.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="29.552955295529554%" id="mcps1.1.4.1.2"><p>参数</p>
</th>
<th class="cellrowborder" valign="top" width="45.5945594559456%" id="mcps1.1.4.1.3"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p>indexerchange<sup><span>5+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p>{ local: booleanValue }</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p>多语言索引条切换事件，仅当indexer属性为true，indexermulti为true时生效。booleanValue可能值为true或者false：</p>
<ul><li>true: 当前展示本地索引。</li><li>false: 当前展示字母索引。</li></ul>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p>scroll</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p>{ scrollX: scrollXValue, scrollY: scrollYValue, scrollState: stateValue }</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p>列表滑动的偏移量和状态回调。</p>
<p>stateValue: 0表示列表滑动已经停止。</p>
<p>stateValue: 1表示列表正在用户触摸状态下滑动。</p>
<p>stateValue: 2表示列表正在用户松手状态下滑动。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p>scrollbottom</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p>当前列表已滑动到底部位置。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p>scrolltop</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p>当前列表已滑动到顶部位置。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p>scrollend</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p>列表滑动已经结束。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p>scrolltouchup</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p>手指已经抬起且列表仍在惯性滑动。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p>requestitem</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p>请求创建新的list-item。</p>
<p>长列表延迟加载时，可视区域外缓存的list-item数量少于cachedcount时，会触发该事件。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p>rotate<sup>7+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p>{ rotateValue: number }</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p>返回表冠旋转角度增量值，仅智能穿戴支持。</p>
</td>
</tr>
</tbody>
</table>

## 方法<a name="section47669296127"></a>

支持[通用方法](js-components-common-methods.md)外，还支持如下方法：

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="14.09%" id="mcps1.1.4.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="34.910000000000004%" id="mcps1.1.4.1.2"><p>参数</p>
</th>
<th class="cellrowborder" valign="top" width="51%" id="mcps1.1.4.1.3"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="14.09%" headers="mcps1.1.4.1.1 "><p>scrollTo</p>
</td>
<td class="cellrowborder" valign="top" width="34.910000000000004%" headers="mcps1.1.4.1.2 "><p>{ index: number(指定位置) }</p>
</td>
<td class="cellrowborder" valign="top" width="51%" headers="mcps1.1.4.1.3 "><p>list滑动到指定index的item位置。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="14.09%" headers="mcps1.1.4.1.1 "><p>scrollBy</p>
</td>
<td class="cellrowborder" valign="top" width="34.910000000000004%" headers="mcps1.1.4.1.2 "><p><a href="#t54327f53ea104788bc430b9047ecb47b">ScrollParam</a></p>
</td>
<td class="cellrowborder" valign="top" width="51%" headers="mcps1.1.4.1.3 "><p>触发list滑动一段距离。</p>
<p>智慧屏特有方法。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="14.09%" headers="mcps1.1.4.1.1 "><p>scrollTop</p>
</td>
<td class="cellrowborder" valign="top" width="34.910000000000004%" headers="mcps1.1.4.1.2 "><p>{ smooth: boolean }</p>
</td>
<td class="cellrowborder" valign="top" width="51%" headers="mcps1.1.4.1.3 "><p>smooth缺省为false，表示直接滚动到顶部。</p>
<p>smooth为true，表示平滑滚动到顶部。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="14.09%" headers="mcps1.1.4.1.1 "><p>scrollBottom</p>
</td>
<td class="cellrowborder" valign="top" width="34.910000000000004%" headers="mcps1.1.4.1.2 "><p>{ smooth: boolean }</p>
</td>
<td class="cellrowborder" valign="top" width="51%" headers="mcps1.1.4.1.3 "><p>smooth缺省为false，表示直接滚动到底部。</p>
<p>smooth为true，表示平滑滚动到底部。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="14.09%" headers="mcps1.1.4.1.1 "><p>scrollPage</p>
</td>
<td class="cellrowborder" valign="top" width="34.910000000000004%" headers="mcps1.1.4.1.2 "><p>{ reverse: boolean, smooth: boolean }</p>
</td>
<td class="cellrowborder" valign="top" width="51%" headers="mcps1.1.4.1.3 "><p>reverse缺省值为false，表示下一页，无完整页则滚动到底部。</p>
<p>reverse为true，表示上一页，无完整页则滚动到顶部。</p>
<p>smooth缺省值为false，表示直接滚动一页。</p>
<p>smooth为true，表示平滑滚动一页。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="14.09%" headers="mcps1.1.4.1.1 "><p>scrollArrow</p>
</td>
<td class="cellrowborder" valign="top" width="34.910000000000004%" headers="mcps1.1.4.1.2 "><p>{ reverse: boolean, smooth: boolean }</p>
</td>
<td class="cellrowborder" valign="top" width="51%" headers="mcps1.1.4.1.3 "><p>reverse缺省值为false，表示向底部方向滑动一段距离，无足够距离则滚动到底部。</p>
<p>reverse为true，表示向顶部方向滑动一段距离，无足够距离则滚动到顶部。</p>
<p>smooth缺省值为false，表示直接滚动。</p>
<p>smooth为true，表示平滑滚动。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="14.09%" headers="mcps1.1.4.1.1 "><p>collapseGroup</p>
</td>
<td class="cellrowborder" valign="top" width="34.910000000000004%" headers="mcps1.1.4.1.2 "><p>{ groupid: string }</p>
</td>
<td class="cellrowborder" valign="top" width="51%" headers="mcps1.1.4.1.3 "><p>收拢指定的group。</p>
<p>groupid：需要收拢的group的id。</p>
<p>当groupid未指定时收拢所有的group。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="14.09%" headers="mcps1.1.4.1.1 "><p>expandGroup</p>
</td>
<td class="cellrowborder" valign="top" width="34.910000000000004%" headers="mcps1.1.4.1.2 "><p>{ groupid: string }</p>
</td>
<td class="cellrowborder" valign="top" width="51%" headers="mcps1.1.4.1.3 "><p>展开指定的group。</p>
<p>groupid：需要展开的group的id。</p>
<p>当groupid未指定时展开所有的group。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="14.09%" headers="mcps1.1.4.1.1 "><p>currentOffset</p>
</td>
<td class="cellrowborder" valign="top" width="34.910000000000004%" headers="mcps1.1.4.1.2 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="51%" headers="mcps1.1.4.1.3 "><p>返回当前滑动的偏移量。返回值类型是Object，返回值说明请见<a href="#table1145513617576">表2</a>。</p>
</td>
</tr>
</tbody>
</table>

**表 1**  ScrollParam

<a name="t54327f53ea104788bc430b9047ecb47b"></a>
<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="12.000000000000002%" id="mcps1.2.6.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="22.000000000000004%" id="mcps1.2.6.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="24.000000000000004%" id="mcps1.2.6.1.3"><p>是否必选</p>
</th>
<th class="cellrowborder" valign="top" width="21.000000000000004%" id="mcps1.2.6.1.4"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="21.000000000000004%" id="mcps1.2.6.1.5"><p>备注</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="12.000000000000002%" headers="mcps1.2.6.1.1 "><p>dx</p>
</td>
<td class="cellrowborder" valign="top" width="22.000000000000004%" headers="mcps1.2.6.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.2.6.1.3 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="21.000000000000004%" headers="mcps1.2.6.1.4 "><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="21.000000000000004%" headers="mcps1.2.6.1.5 "><p>水平方向滑动的偏移量，单位为px。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="12.000000000000002%" headers="mcps1.2.6.1.1 "><p>dy</p>
</td>
<td class="cellrowborder" valign="top" width="22.000000000000004%" headers="mcps1.2.6.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.2.6.1.3 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="21.000000000000004%" headers="mcps1.2.6.1.4 "><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="21.000000000000004%" headers="mcps1.2.6.1.5 "><p>垂直方向滑动的偏移量，单位为px。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="12.000000000000002%" headers="mcps1.2.6.1.1 "><p>smooth</p>
</td>
<td class="cellrowborder" valign="top" width="22.000000000000004%" headers="mcps1.2.6.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.2.6.1.3 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="21.000000000000004%" headers="mcps1.2.6.1.4 "><p>true</p>
</td>
<td class="cellrowborder" valign="top" width="21.000000000000004%" headers="mcps1.2.6.1.5 "><p>列表位置跳转时是否有滑动动画。</p>
</td>
</tr>
</tbody>
</table>

**表 2**  currentOffset返回对象属性说明

<a name="table1145513617576"></a>
<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="21.82%" id="mcps1.2.4.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="40%" id="mcps1.2.4.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="38.18%" id="mcps1.2.4.1.3"><p>备注</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="21.82%" headers="mcps1.2.4.1.1 "><p>x</p>
</td>
<td class="cellrowborder" valign="top" width="40%" headers="mcps1.2.4.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="38.18%" headers="mcps1.2.4.1.3 "><p>当前x轴滑动偏移量，单位为px。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="21.82%" headers="mcps1.2.4.1.1 "><p>y</p>
</td>
<td class="cellrowborder" valign="top" width="40%" headers="mcps1.2.4.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="38.18%" headers="mcps1.2.4.1.3 "><p>当前y轴滑动偏移量，单位为px。</p>
</td>
</tr>
</tbody>
</table>
## 示例

```
!-- index.hml -->
<div class="container">  
  <list class="todo-wrapper">    
    <list-item for="{{todolist}}" class="todo-item">      
      <div style="flex-direction: column;align-items: center;justify-content: center;">         
      <text class="todo-title">{{$item.title}}</text>        
      <text class="todo-title">{{$item.date}}</text>      
    </div>    
  </list-item>  
</list></div>
```

```
// index.js
export default {
  data: {    
    todolist: [{      
      title: '刷题',      
      date: '2021-12-31 10:00:00',    
      }, {      
      title: '看电影',      
      date: '2021-12-31 20:00:00',    
    }],  
  },
}
```

```
/* index.css */
.container {  
  display: flex;  
  justify-content: center;  
  align-items: center;  
  width: 100%;  
  height: 100%;
}
.todo-wrapper {  
  width: 100%;  
  height: 300px;
}
.todo-item {  
  width: 100%;  
  height: 120px;  
  justify-content:center;
}
.todo-title {  
  width: 100%;  
  height: 80px;  
  text-align: center;
}
```

![](figures/list.png)

